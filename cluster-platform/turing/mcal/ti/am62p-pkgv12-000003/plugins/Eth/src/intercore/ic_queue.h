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
 * \file     ic_queue.h
 *
 * \brief    Implementation of a circular queue.
 */

#ifndef IC_QUEUE_H_
#define IC_QUEUE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include "Eth_Cfg.h"
#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros                                           */
/* ========================================================================== */

/*! ICQ API return code: Success */
#define ICQ_RETURN_SUCCESS      (0)
/*! ICQ API return code: Failure */
#define ICQ_RETURN_FAILURE      (-1)
/*! ICQ API return code: Queue Full */
#define ICQ_ERR_QFULL           (-2)
/*! ICQ API return code: Queue Empty */
#define ICQ_ERR_QEMPTY          (-3)

/*! Maximum no. of IcQ_Node objects in a queue */
#define ICQ_MAX_QUEUE_SIZE      (2048)

/*! MCU2_0 to MCU2_1 TX queue */
#define ICQ_MCU2_0_TO_MCU2_1    (0U)
/*! MCU2_1 to MCU2_0 TX queue */
#define ICQ_MCU2_1_TO_MCU2_0    (1U)
/*! MCU2_0 to A72 TX queue */
#define ICQ_MCU2_0_TO_A72       (2U)
/*! A72 to MCU2_0 TX queue */
#define ICQ_A72_TO_MCU2_0       (3U)
/*! MCU2_0 to MCU3_0 TX queue */
#define ICQ_MCU2_0_TO_MCU3_0    (4U)
/*! MCU3_0 to MCU2_0 TX queue */
#define ICQ_MCU3_0_TO_MCU2_0    (5U)
/*! MCU2_1 to MCU3_0 TX queue */
#define ICQ_MCU2_1_TO_MCU3_0    (6U)
/*! MCU3_0 to MCU2_1 TX queue */
#define ICQ_MCU3_0_TO_MCU2_1    (7U)
/*! MCU2_1 to A72 TX queue */
#define ICQ_MCU2_1_TO_A72       (8U)
/*! A72 to MCU2_1 TX queue */
#define ICQ_A72_TO_MCU2_1       (9U)
/*! Total number of queues */
#define ICQ_MAX_NUM_QUEUES      (10U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*!
 * \brief Node structure for a fixed size circular queue
 */
typedef struct IcQ_Node_s
{
    /*! Data buffer pointer */
    void *pDataBuffer;

    /*! Data buffer length */
    uint32 dataBufferLen;

    /*! Packet ID */
    uint32 packetId;

    /*! Reserved */
    uint32 reserved;

} IcQ_Node;

/*!
 * \brief Fixed size circular queue structure.
 */
typedef struct IcQ_s
{
    /*! Queue ID */
    uint32 queueId;

    /*! Pointer to the head descriptor */
    uint32 head;

    /*! Pointer to the tail descriptor */
    uint32 tail;

    /*! Magic number used to check queue initialization */
    uint32 magic;

    /*! Maximum no of nodes in the queue (fixed) */
    uint32 maxSize;

    /*! Contiguous array of queue nodes */
    IcQ_Node nodeArray[ICQ_MAX_QUEUE_SIZE];
}IcQ;

/*!
 * \brief Inter-core queue handle
 *
 * Inter-core queue handle provided to the user
 */
typedef struct IcQ_s* IcQ_Handle;

/*! Size of queue node (descriptor) */    
#define ICQ_NODE_SIZE_IN_BYTES (sizeof(IcQ_Node))

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
                      uint32 maxSize);

/*!
 * \brief Enqueues an \ref IcQ_Node object on the given queue
 *
 * @param[in] hIcQueue      Handle to IcQ object
 * @param[in] pNode         Handle to IcQ_Node object
 *
 * @return None
 */
sint32 IcQueue_enq(IcQ_Handle hIcQueue,
                    IcQ_Node *pNode);

/*!
 * \brief Dequeues a node from the given queue
 * 
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return The next \ref IcQ_Node object on the queue
 * @return NULL if the queue is empty
 */
IcQ_Node* IcQueue_deq(IcQ_Handle hIcQueue);

/*!
 * \brief Returns BTRUE if the given queue is empty
 *
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return True if a queue is empty.
 */
boolean IcQueue_isQEmpty(IcQ_Handle hIcQueue);

/*!
 * \brief Returns BTRUE if the given queue is full
 *
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return True if a queue is full.
 */
boolean IcQueue_isQFull(IcQ_Handle hIcQueue);

#ifdef __cplusplus
}
#endif
#endif
#endif /* IC_QUEUE_H_ */
