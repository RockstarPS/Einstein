/*
 *  Copyright (c) Texas Instruments Incorporated 2020-22
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
 *  \file udma_resmgr.c
 *
 *  \brief File containing the UDMA resource manager APIs.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "tiudma_mgr.h"
#include "udma_resmgr.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static int g_UdmaFd = -1;
static int ref_cnt = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static int32_t Udma_resmgr_open(void)
{
    int32_t retVal = UDMA_SOK;

    if (0==ref_cnt)
    {
        g_UdmaFd = open(TIUDMA_DEVICE_NAME, O_SYNC | O_RDWR);
        if (g_UdmaFd < 0)
        {
            retVal = UDMA_EFAIL;
        }
    }

    ref_cnt++;

    return retVal;
}

static int32_t Udma_resmgr_close(void)
{
    int32_t  retVal = UDMA_SOK;

    ref_cnt--;

    if (ref_cnt == 0)
    {
        close(g_UdmaFd);
        g_UdmaFd = -1;
    }

    return (retVal);
}

uint32_t Udma_resmgr_rmAllocBlkCopyCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.blkcopy.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_BLKCOPYCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.blkcopy.chNum;

            Udma_rmAllocBlkCopyCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeBlkCopyCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.blkcopy.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_BLKCOPYCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeBlkCopyCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocBlkCopyHcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.blkcopyhc.preferredChNum = preferredChNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_BLKCOPYHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.blkcopyhc.chNum;

            Udma_rmAllocBlkCopyHcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeBlkCopyHcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.blkcopyhc.chNum = chNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_BLKCOPYHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeBlkCopyHcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocBlkCopyUhcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.blkcopyuhc.preferredChNum = preferredChNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_BLKCOPYUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.blkcopyuhc.chNum;

            Udma_rmAllocBlkCopyUhcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeBlkCopyUhcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.blkcopyuhc.chNum = chNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_BLKCOPYUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeBlkCopyUhcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocTxCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.tx.preferredChNum = preferredChNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_TXCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.tx.chNum;

            Udma_rmAllocTxCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeTxCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.tx.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_TXCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeTxCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocRxCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.rx.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_RXCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.rx.chNum;

            Udma_rmAllocRxCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeRxCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.rx.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_RXCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeRxCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocTxHcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.txhc.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_TXHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.txhc.chNum;

            Udma_rmAllocTxHcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeTxHcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.txhc.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_TXHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeTxHcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocRxHcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.rxhc.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_RXHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.rxhc.chNum;

            Udma_rmAllocRxHcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeRxHcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.rxhc.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_RXHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeRxHcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocTxUhcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.txuhc.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_TXUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.txuhc.chNum;

            Udma_rmAllocTxUhcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeTxUhcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.txuhc.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_TXUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeTxUhcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocRxUhcCh(uint32_t preferredChNum, Udma_DrvHandle drvHandle)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.rxuhc.preferredChNum = preferredChNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_RXUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.rxuhc.chNum;

            Udma_rmAllocRxUhcCh(chNum, drvHandle);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeRxUhcCh(uint32_t chNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.rxuhc.chNum = chNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_RXUHCCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeRxUhcCh(chNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

#if (UDMA_NUM_UTC_INSTANCE > 0)
uint32_t Udma_resmgr_rmAllocExtCh(uint32_t preferredChNum,
                           Udma_DrvHandle drvHandle,
                           const Udma_UtcInstInfo *utcInfo)
{
    uint32_t chNum = UDMA_DMA_CH_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.ext.preferredChNum = preferredChNum;
        cargs.args.ext.utcInfo = utcInfo;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_EXTCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            chNum = cargs.args.ext.chNum;

            Udma_rmAllocExtCh(chNum, drvHandle, utcInfo);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return chNum;
}

void Udma_resmgr_rmFreeExtCh(uint32_t chNum,
                      Udma_DrvHandle drvHandle,
                      const Udma_UtcInstInfo *utcInfo)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.ext.chNum = chNum;
        cargs.args.ext.utcInfo = utcInfo;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_EXTCH, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeExtCh(chNum, drvHandle, utcInfo);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}
#endif

static uint16_t Udma_resmgr_rmAllocPrefProxy(uint16_t preferredProxyNum, Udma_DrvHandle drvHandle)
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

uint16_t Udma_resmgr_rmAllocProxy(uint16_t preferredProxyNum, Udma_DrvHandle drvHandle)
{
    uint16_t proxyNum = UDMA_PROXY_INVALID;
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (retVal == UDMA_SOK)
    {
        cargs.args.proxy.preferredProxyNum = preferredProxyNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_PROXY, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            proxyNum = Udma_resmgr_rmAllocPrefProxy(cargs.args.proxy.proxyNum, drvHandle);

            Udma_assert(drvHandle, proxyNum == cargs.args.proxy.proxyNum);
        }
    }

    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return proxyNum;
}

void Udma_resmgr_rmFreeProxy(uint16_t proxyNum, Udma_DrvHandle drvHandle)
{
    int32_t retVal = UDMA_EFAIL;
    TIUDMA_CmdArgs cargs;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.proxy.proxyNum = proxyNum;
        cargs.instId = drvHandle->initPrms.instId;
        
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_PROXY, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeProxy(proxyNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

static int32_t Udma_resmgr_rmAllocPrefFreeRing(uint16_t preferredRingNum, Udma_DrvHandle drvHandle)
{
    int32_t  retVal = UDMA_EFAIL;
    uint32_t            i, offset, bitPos, bitMask;
    Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;
#if defined (SOC_AM62X) || defined (SOC_AM62A) || defined (SOC_AM62PX)
    uint32_t            freeRingOffset = rmInitPrms->startFreeRing +
                                 drvHandle->bcdmaRegs.txChanCnt +
                                 drvHandle->bcdmaRegs.txExtUtcChanCnt +
                                 drvHandle->bcdmaRegs.rxChanCnt;
#else
    uint32_t            freeRingOffset = rmInitPrms->startFreeRing +
                                 drvHandle->udmapRegs.txChanCnt +
                                 drvHandle->udmapRegs.txExtUtcChanCnt +
                                 drvHandle->udmapRegs.rxChanCnt;
#endif

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

    /* Alloc only the preferred ring - ignore FQ rings */
    if(preferredRingNum >= freeRingOffset)
    {

        i = preferredRingNum - freeRingOffset;
        offset = i >> 5U;
        Udma_assert(drvHandle, offset < UDMA_RM_FREE_RING_ARR_SIZE);
        bitPos = i - (offset << 5U);
        bitMask = (uint32_t) 1U << bitPos;
        if((drvHandle->freeRingFlag[offset] & bitMask) == bitMask)
        {
            drvHandle->freeRingFlag[offset] &= ~bitMask;
            retVal = UDMA_SOK;
        }
    }

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);

    return retVal;
}

uint16_t Udma_resmgr_rmAllocFreeRing(Udma_DrvHandle drvHandle)
{
    uint16_t            ringNum = UDMA_RING_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_FREERING, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            ringNum = cargs.args.freering.ringNum;

            retVal = Udma_resmgr_rmAllocPrefFreeRing(ringNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return ringNum;
}

void Udma_resmgr_rmFreeFreeRing(uint16_t ringNum, Udma_DrvHandle drvHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.freering.ringNum = ringNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_FREERING, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeFreeRing(ringNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

static int32_t Udma_resmgr_rmAllocPrefRingMon(uint16_t preferredRingNum, Udma_DrvHandle drvHandle)
{
    int32_t  retVal = UDMA_EFAIL;
    uint32_t            i, offset, bitPos, bitMask;
    Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;
    uint32_t            ringMonOffset = rmInitPrms->startRingMon;

    if(preferredRingNum >= ringMonOffset)
    {
        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
        drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

        i = preferredRingNum - ringMonOffset;
        offset = i >> 5U;
        Udma_assert(drvHandle, offset < UDMA_RM_RING_MON_ARR_SIZE);
        bitPos = i - (offset << 5U);
        bitMask = (uint32_t) 1U << bitPos;
        Udma_assert(drvHandle, (drvHandle->ringMonFlag[offset] & bitMask) == 0U);
        drvHandle->ringMonFlag[offset] &= ~bitMask;

        retVal = UDMA_SOK;

        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
        drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);
    }

    return retVal;
}

uint16_t Udma_resmgr_rmAllocRingMon(Udma_DrvHandle drvHandle)
{
    uint16_t            ringNum = UDMA_RING_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_RINGMON, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            ringNum = cargs.args.ringmon.ringNum;

            retVal = Udma_resmgr_rmAllocPrefRingMon(ringNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return ringNum;
}

void Udma_resmgr_rmFreeRingMon(uint16_t ringNum, Udma_DrvHandle drvHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.ringmon.ringNum = ringNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_RINGMON, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeRingMon(ringNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

static void Udma_resmgr_rmAllocPrefVintr(uint32_t preferredIntrNum, Udma_DrvHandle drvHandle)
{
    uint32_t            i, offset, bitPos, bitMask;
    Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

    Udma_assert(drvHandle,
        preferredIntrNum < (rmInitPrms->startVintr + rmInitPrms->numVintr));
    Udma_assert(drvHandle, preferredIntrNum >= rmInitPrms->startVintr);

    i = preferredIntrNum - rmInitPrms->startVintr;
    offset = i >> 5U;
    Udma_assert(drvHandle, offset < UDMA_RM_VINTR_ARR_SIZE);
    bitPos = i - (offset << 5U);
    bitMask = (uint32_t) 1U << bitPos;
    Udma_assert(drvHandle, (drvHandle->vintrFlag[offset] & bitMask) == 0U);
    drvHandle->vintrFlag[offset] &= ~bitMask;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);

    return;
}

uint32_t Udma_resmgr_rmAllocVintr(Udma_DrvHandle drvHandle)
{
    uint32_t            vintrNum = UDMA_EVENT_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_VINTR, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            vintrNum = cargs.args.vintr.vintrNum;

            Udma_resmgr_rmAllocPrefVintr(vintrNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return vintrNum;
}

void Udma_resmgr_rmFreeVintr(uint32_t vintrNum, Udma_DrvHandle drvHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.vintr.vintrNum = vintrNum;
        cargs.instId = drvHandle->initPrms.instId;
        
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_VINTR, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeVintr(vintrNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

uint32_t Udma_resmgr_rmAllocIrIntr(uint32_t preferredIrIntrNum, Udma_DrvHandle drvHandle)
{
    uint32_t            irIntrNum = UDMA_INTR_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.irintr.preferredIrIntrNum = preferredIrIntrNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_IRINTR, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            irIntrNum = cargs.args.irintr.irIntrNum;

            Udma_rmAllocIrIntr(irIntrNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return irIntrNum;
}

void Udma_resmgr_rmFreeIrIntr(uint32_t irIntrNum, Udma_DrvHandle drvHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.args.irintr.irIntrNum = irIntrNum;
        cargs.instId = drvHandle->initPrms.instId;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_IRINTR, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeIrIntr(irIntrNum, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

static void Udma_resmgr_rmAllocPrefEvent(uint32_t preferredGlobalEvent, Udma_DrvHandle drvHandle)
{
    uint32_t            i, offset, bitPos, bitMask;
    Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

    Udma_assert(drvHandle,
        preferredGlobalEvent < (rmInitPrms->startGlobalEvent + rmInitPrms->numGlobalEvent));
    Udma_assert(drvHandle, preferredGlobalEvent >= rmInitPrms->startGlobalEvent);

    i = preferredGlobalEvent - rmInitPrms->startGlobalEvent;
    offset = i >> 5U;
    Udma_assert(drvHandle, offset < UDMA_RM_GLOBAL_EVENT_ARR_SIZE);
    bitPos = i - (offset << 5U);
    bitMask = (uint32_t) 1U << bitPos;
    Udma_assert(drvHandle, (drvHandle->globalEventFlag[offset] & bitMask) == 0U);
    drvHandle->globalEventFlag[offset] &= ~bitMask;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);

    return;
}

uint32_t Udma_resmgr_rmAllocEvent(Udma_DrvHandle drvHandle)
{
    uint32_t globalEvent = UDMA_EVENT_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_EVENT, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            globalEvent = cargs.args.event.globalEvent;

            Udma_resmgr_rmAllocPrefEvent(globalEvent, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return globalEvent;
}

void Udma_resmgr_rmFreeEvent(uint32_t globalEvent, Udma_DrvHandle drvHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.event.globalEvent = globalEvent;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_EVENT, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeEvent(globalEvent, drvHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}

static void Udma_resmgr_rmAllocPrefVintrBit(uint32_t preferredVintrBitNum,
                         Udma_DrvHandle drvHandle,
                         Udma_EventHandle eventHandle)
{
    uint64_t                bitMask;
    Udma_EventHandle        masterEventHandle;
    const Udma_EventPrms   *eventPrms;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

    masterEventHandle = eventHandle;
    eventPrms = &eventHandle->eventPrms;
    if(NULL_PTR != eventPrms->masterEventHandle)
    {
        /* Shared event. Get the master handle */
        masterEventHandle = eventPrms->masterEventHandle;
    }

    Udma_assert(drvHandle, preferredVintrBitNum < UDMA_MAX_EVENTS_PER_VINTR);
    bitMask = ((uint64_t) 1U << preferredVintrBitNum);
    Udma_assert(drvHandle,
        (masterEventHandle->vintrBitAllocFlag & bitMask) == bitMask);
    masterEventHandle->vintrBitAllocFlag |= bitMask;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);

    return;
}

uint32_t Udma_resmgr_rmAllocVintrBit(Udma_DrvHandle drvHandle, Udma_EventHandle eventHandle)
{
    uint32_t vintrBitNum = UDMA_EVENT_INVALID;
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_ALLOC_VINTRBIT, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            vintrBitNum = cargs.args.vintrbit.vintrBitNum;

            Udma_resmgr_rmAllocPrefVintrBit(vintrBitNum, drvHandle, eventHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return vintrBitNum;
}

void Udma_resmgr_rmFreeVintrBit(uint32_t vintrBitNum,
                         Udma_DrvHandle drvHandle,
                         Udma_EventHandle eventHandle)
{
    TIUDMA_CmdArgs cargs;
    int32_t  retVal = UDMA_SOK;

    retVal = Udma_resmgr_open();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_open failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    if (g_UdmaFd > 0)
    {
        cargs.instId = drvHandle->initPrms.instId;
        cargs.args.vintrbit.vintrBitNum = vintrBitNum;

        retVal = devctl(g_UdmaFd, DCMD_TIUDMA_FREE_VINTRBIT, &cargs,
                        sizeof(TIUDMA_CmdArgs), NULL);

        Udma_assert(drvHandle, retVal==UDMA_SOK);

        if (UDMA_SOK == retVal)
        {
            Udma_rmFreeVintrBit(vintrBitNum, drvHandle, eventHandle);
        }
    }
    retVal = Udma_resmgr_close();
    if (UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle, "[Error] Udma_resmgr_close failed!!!\n");
        Udma_assert(drvHandle, retVal==UDMA_SOK);
    }

    return;
}
