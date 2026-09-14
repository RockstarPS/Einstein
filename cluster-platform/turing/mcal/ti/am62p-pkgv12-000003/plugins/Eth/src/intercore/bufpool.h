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
 * \file     bufpool.h
 *
 * \brief    Implements a simple buffer pool
 */

#ifndef BUFPOOL_H_
#define BUFPOOL_H_

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
/*                                Macros                                      */
/* ========================================================================== */

/*! Total memory used by all shared buffer pools combined */
#define BUFPOOL_MEM_LEN     (BUFPOOL_MAX_POOLS * sizeof(BufPool_Pool))

/*! Maximum Ethernet Payload Size. */
#define ETH_MAX_PAYLOAD     (1514)
/*! Size of the VLAN tag in bytes */
#define VLAN_TAG_SIZE       (4U)

/*! Total size of the Ethernet frame in bytes */
#define ETH_FRAME_SIZE      (ETH_MAX_PAYLOAD + VLAN_TAG_SIZE)

/*! MCU2_0 buffer pool for MCU2_0->MCU2_1 interface */
#define BUFPOOL_MCU2_0_R5_0_1   (0)
/*! MCU2_1 buffer pool */
#define BUFPOOL_MCU2_1          (1)
/*! A72 buffer pool */
#define BUFPOOL_A72             (2)
/*! MCU2_0 buffer pool for MCU2_0->A72 interface */
#define BUFPOOL_MCU2_0_A72      (3)
/*! MCU2_0 buffer pool for MCU2_0->MCU3_0 interface */
#define BUFPOOL_MCU2_0_R5_1_0   (4)
/*! MCU3_0 buffer pool */
#define BUFPOOL_MCU3_0          (5)
/*! MCU2_1 buffer pool for MCU2_1->MCU3_0 interface */
#define BUFPOOL_MCU2_1_R5_1_0   (6)
/*! MCU2_0 buffer pool for MCU2_1->A72 interface */
#define BUFPOOL_MCU2_1_A72      (7)
/*! Total number of buffer pools */
#define BUFPOOL_MAX_POOLS       (8)

/*! Maximum no. of buffers in each buffer pool */
#define BUFPOOL_BUF_MAX     (1280U)

/*! Buffer pool API return code: Success */
#define BUFPOOL_OK          (0)       
/*! Buffer pool API return code: Failure */
#define BUFPOOL_ERROR       (-1)      

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*!
 * \brief Fixed size data buffer 
 */
typedef struct BufPool_Buf_s
{
    /*! Data buffer */
    uint8 payload[ETH_FRAME_SIZE];

    /*! Valid payload length */
    uint16 payloadLen;

    /*! Reference count: 0 means the buffer is free */
    sint16 refCount;
    
    /*! Is buffer in use (1) or free (0) */
    sint16 isUsed;

    /*! Pool ID to which this buffer belongs */
    uint32 poolId;

    /*! Padding to keep the buffer size 128 byte aligned */
    uint8 pad[8];

} BufPool_Buf;

/*!
 * \brief Fixed size buffer pool
 */
typedef struct BufPool_Pool_s
{
    /*! Pool ID */
    uint32 poolId;

    /*! Pointer to the last freed buffer */ 
    sint32 lastFreed;

    /*! Pointer to the last allocated buffer */
    sint32 lastAlloc;

    /*! Magic number used to check pool initialization */
    uint32 magic;

    /*! Maximum no of buffers in the pool (fixed) */
    uint32 maxSize;

    /*! Number of successful buffer get operations on this buffer pool  */
    uint32 numBufGet;

    /*! Number of successful buffer free operations on this buffer pool  */
    uint32 numBufFree;

    /*! Number of times a buffer get from this buffer pool failed */
    uint32 numBufGetErr;

    /*! Contiguous array of BufPool_Buf objects */
    BufPool_Buf buf_array[BUFPOOL_BUF_MAX];

} BufPool_Pool;

/*!
 * \brief BufPool handle
 *
 * BufPool handle provided to the user
 */
typedef struct BufPool_Pool_s* BufPool_Handle;

/*! Size of buffer object */
#define BUF_OBJ_SIZE_IN_BYTES (sizeof(BufPool_Buf))

/* ========================================================================== */
/*                         External Variable Declarations                     */
/* ========================================================================== */

/* ========================================================================== */
/*                     API/Public Function Declarations                       */
/* ========================================================================== */

/*!
 * \brief Initializes a buffer pool
 *
 * This function creates a buffer pool in the memory region pointed
 * to by the BufPool_Handle
 *
 * \param hBufPool  Pointer to pre-allocated memory for this buffer pool
 * \param poolId    Buffer Pool ID
 * \param maxSize   Total no. of buffers in this buffer pool
 *
 * \retval BUFPOOL_OK
 */
sint32 BufPool_init(BufPool_Handle hBufPool,
                     uint32 poolId,
                     uint32 maxSize);

/*!
 * \brief Returns a pointer to a free buffer
 *
 * This function alloctes a free buffer from the given buffer pool
 * and returns a pointer to it.
 *
 * \param hBufPool  Handle to the buffer pool from which to allocate a buffer
 *
 * \retval Pointer to a BufPool_Buf object if the get operation was successfull
 * \retval NULL in case of failure
 */
BufPool_Buf* BufPool_getBuf(BufPool_Handle hBufPool);

/*!
 * \brief Decrements the ref count of a buffer object
 *
 * This function decrements the ref count of an allocated buffer object.
 * If the ref count reaches zero, the buffer is released to the buffer pool.
 *
 * \param hBuf  Handle to a buffer object
 *
 * \retval BUFPOOL_OK
 */

sint32 BufPool_freeBuf(BufPool_Buf* hBuf);

#ifdef __cplusplus
}
#endif

#endif

#endif /* BUFPOOL_H_ */
