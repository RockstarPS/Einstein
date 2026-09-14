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
 * \file     bufpool.c
 *
 * \brief    Implements a simple buffer pool
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Eth_Cfg.h"
#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
#include <string.h>
#include "bufpool.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/*! \brief Magic vlaue used to check if a bufpool has been initialized. */
#define BUFPOOL_INIT_DONE               (0xABCDABCDU)

/*! \brief Assert wrapper */
#define BufPool_assert(cond, ...)        


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

/* ========================================================================== */
/*                          Private Functions                                 */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          API/Public Functions                              */
/* ========================================================================== */

/*!
 * \brief Initializes a buffer pool
 *
 */
sint32 BufPool_init(BufPool_Handle hBufPool,
                     uint32 poolId,
                     uint32 maxSize)
{
    sint32 bufIdx  = 0;
    sint32 retVal = BUFPOOL_OK;

    BufPool_assert(hBufPool && (maxSize<=BUFPOOL_BUF_MAX));

    hBufPool->poolId    = poolId;
    hBufPool->lastAlloc = 0;
    hBufPool->numBufGet = 0;
    hBufPool->numBufFree   = 0;
    hBufPool->numBufGetErr = 0;
    hBufPool->maxSize   = maxSize;
    hBufPool->magic     = BUFPOOL_INIT_DONE;

    /* Clear all the buffers */
    (void)memset(hBufPool->buf_array, 0x00, maxSize * sizeof(BufPool_Buf));

    for (bufIdx = 0; bufIdx < maxSize; bufIdx++)
    {
        hBufPool->buf_array[bufIdx].poolId = poolId;
    }

    return retVal;
}

/*!
 * \brief Returns a pointer to a free buffer
 *
 */
BufPool_Buf* BufPool_getBuf(BufPool_Handle hBufPool)
{
    sint32 idx = 0;
    BufPool_Buf* hBuf = NULL_PTR;

    BufPool_assert(hBufPool->magic == BUFPOOL_INIT_DONE);

    /* Start search at the last allocated node */

    /* Search from last alloc to end of pool */
    for (idx = hBufPool->lastAlloc; idx < hBufPool->maxSize; idx++)
    {
        if (0 == hBufPool->buf_array[idx].isUsed)
        {
            /* Mark the buffer used and store it's index */
            hBufPool->buf_array[idx].isUsed = 1;
            hBufPool->buf_array[idx].refCount = 1;
            hBufPool->lastAlloc = idx;
            hBufPool->numBufGet++;
            hBuf = &(hBufPool->buf_array[idx]);
            break;
        }
    }

    if (idx == hBufPool->maxSize)
    {
        /* Search from 0 to last alloc */
        for (idx = 0; idx < hBufPool->lastAlloc; idx++)
        {
            if (0 == hBufPool->buf_array[idx].isUsed)
            {
                /* Mark the buffer used and store it's index */
                hBufPool->buf_array[idx].isUsed = 1;
                hBufPool->buf_array[idx].refCount = 1;
                hBufPool->lastAlloc = idx;
                hBufPool->numBufGet++;
                hBuf = &(hBufPool->buf_array[idx]);
                break;
            }
        }

        /* Search failed */
        hBufPool->numBufGetErr++;
    }

    return hBuf;
}

/*!
 * \brief Decrements the ref count of a buffer object
 *
 * If the refCount reaches zero, free the pool buffer
 *
 */
sint32 BufPool_freeBuf(BufPool_Buf* hBuf)
{
    sint32 retVal = BUFPOOL_OK;

    BufPool_assert(hBuf && (hBuf->refCount >=0));

    if (hBuf->refCount > 0)
    {
        --(hBuf->refCount);

        if (0 == hBuf->refCount)
        {
            /* Mark the buffer free */
            hBuf->isUsed = 0;
        }
    }

    return retVal;
}
#endif