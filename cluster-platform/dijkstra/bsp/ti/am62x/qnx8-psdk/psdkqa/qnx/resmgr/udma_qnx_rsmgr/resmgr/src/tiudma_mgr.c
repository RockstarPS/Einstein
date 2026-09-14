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

/*
 * Define THREAD_POOL_PARAM_T such that we can avoid a compiler
 * warning when we use the dispatch*() functions below
 */
#define THREAD_POOL_PARAM_T dispatch_context_t

#include "tiudma_mgr.h"
#include "tiudma_mgr_private.h"
#include "proto.h"
#include <ti/drv/sciclient/sciclient.h>
#include "ti/drv/udma/include/udma_ch.h"
#include "ti/drv/udma/src/udma_priv.h"

static int          verbose = 0;

static int udma_io_devctl(resmgr_context_t *ctp, io_devctl_t *msg, RESMGR_OCB_T *ocb);
struct Udma_DrvObj      gUdmaDrvObj[UDMA_INST_ID_MAX + 1];

IOFUNC_OCB_T *
ocb_calloc (resmgr_context_t * ctp, IOFUNC_ATTR_T * device)
{
    ti_udma_ocb_t *ocb = NULL;

    /* Allocate the OCB */
    ocb = (ti_udma_ocb_t *) calloc (1, sizeof (ti_udma_ocb_t));
    if (ocb == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    pthread_mutex_init(&ocb->lock, NULL);
    /* Initialize OCB */

    return (IOFUNC_OCB_T *)(ocb);
}

void
ocb_free (IOFUNC_OCB_T * ocb)
{
    ti_udma_ocb_t *udma_ocb = (ti_udma_ocb_t *)ocb;

    if (udma_ocb)
    {
        pthread_mutex_destroy(&udma_ocb->lock);
        free (udma_ocb);
    }
}

int main(int argc, char *argv[])
{
    struct stat             sbuf;
    int                     id;
    int                     option;
    resmgr_connect_funcs_t  connect_funcs;
    resmgr_io_funcs_t       io_funcs;
    dispatch_t             *dpp;
    resmgr_attr_t           rattr;
    dispatch_context_t     *ctp;
    iofunc_attr_t           ioattr;
    iofunc_mount_t          mattr;
    iofunc_funcs_t          ocb_funcs;
    thread_pool_attr_t      tattr;
    thread_pool_t          *tpool;

    /* Only allow one instance */
    if (-1 != stat(TIUDMA_DEVICE_NAME, &sbuf))
    {
        perror("UDMA resmgr already running...");
        return (-1);
    }

    /* Get IO priveleges */
    if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
        perror("ThreadCtl(_NTO_TCTL_IO");
        return 1;
    }

    Resmgr_Udma_setup();

    /* Initialize the dispatch interface */
    dpp = dispatch_create();
    if (!dpp) {
        udma_slogerr("%s: Failed to create dispatch interface", argv[0]);
        return (errno);
    }

    /* Initialize the resource manager attributes */
    memset(&rattr, 0, sizeof(rattr));
    rattr.nparts_max = 10;
    rattr.msg_max_size = 2048;

    memset (&tattr, 0x00, sizeof(thread_pool_attr_t));
    tattr.handle = dpp;
    tattr.context_alloc = dispatch_context_alloc;
    tattr.context_free = dispatch_context_free;
    tattr.block_func = dispatch_block;
    tattr.unblock_func = dispatch_unblock;
    tattr.handler_func = dispatch_handler;
    tattr.lo_water = 2;
    tattr.hi_water = 8;
    tattr.increment = 1;
    tattr.maximum = 50;

    memset (&mattr, 0, sizeof(iofunc_mount_t));
    mattr.flags = 0;
    mattr.conf = IOFUNC_PC_CHOWN_RESTRICTED | IOFUNC_PC_NO_TRUNC | IOFUNC_PC_SYNC_IO;
    mattr.dev = 0;
    mattr.funcs = &ocb_funcs;
    memset(&ocb_funcs, 0, sizeof(iofunc_funcs_t));
    ocb_funcs.nfuncs = _IOFUNC_NFUNCS;
    ocb_funcs.ocb_calloc = ocb_calloc;
    ocb_funcs.ocb_free = ocb_free;

    /* Initialize the connect functions */
    memset(&io_funcs, 0, sizeof(resmgr_io_funcs_t));
    iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs,
                     _RESMGR_IO_NFUNCS, &io_funcs);
    io_funcs.devctl = udma_io_devctl;

    iofunc_attr_init(&ioattr, S_IFCHR | 0644, NULL, NULL);
    ioattr.mount = &mattr;

    /* Attach the device name */
    id = resmgr_attach(dpp,
                       &rattr,
                       TIUDMA_DEVICE_NAME,
                       _FTYPE_ANY,
                       0,
                       &connect_funcs,
                       &io_funcs,
                       &ioattr);
    if (id == -1) {
        udma_slogerr("%s: Failed to attach pathname", argv[0]);
        return (errno);
    }

    if ((tpool = thread_pool_create(&tattr, 0)) == NULL)
    {
        udma_slogerr("thread pool create failed\n");
        return (errno);
    }

    /* Allocate a context structure */
    ctp = dispatch_context_alloc(dpp);

    while ( (option = getopt(argc, argv, "v")) != -1) {
        switch (option) {

            case 'v':
                verbose++;
                break;
            default:
                fprintf(stderr,"Unsupported option '-%c'\n",option);
                goto fail0;
        }
    }

    /* Run in the background */
    if (procmgr_daemon(EXIT_SUCCESS,
                       PROCMGR_DAEMON_NOCLOSE | PROCMGR_DAEMON_NODEVNULL ) == -1)
    {
        udma_slogerr("%s: procmgr_daemon", argv[0]);
        goto fail0;
    }

    thread_pool_start(tpool);

    while (1) {
        if ((ctp = dispatch_block(ctp)) == NULL) {
            udma_slogerr("%s: Block error", argv[0]);
            goto fail0;
        }
        dispatch_handler(ctp);
    }

fail0:
    return (-errno);
}

static int udma_io_devctl(resmgr_context_t *ctp, io_devctl_t *msg, RESMGR_OCB_T *ocb)
{
    int     status, nbytes;
    int     err = EOK;
    ti_udma_ocb_t * udma_ocb = (ti_udma_ocb_t *)ocb;
    TIUDMA_CmdArgs *cargs = (TIUDMA_CmdArgs *)(_DEVCTL_DATA (msg->i));
    TIUDMA_CmdArgs *output = (TIUDMA_CmdArgs *)(_DEVCTL_DATA (msg->o));
    Udma_DrvHandle  drvHandle = &gUdmaDrvObj[cargs->instId];

    if ((status = iofunc_devctl_default(ctp, msg, ocb)) != _RESMGR_DEFAULT)
    {
        return status;
    }

    pthread_mutex_lock(&udma_ocb->lock);
    status = nbytes = 0;
    switch(msg->i.dcmd)
    {
        case DCMD_TIUDMA_ALLOC_BLKCOPYCH:
        {
            output->args.blkcopy.chNum =
                Udma_rmAllocBlkCopyCh(cargs->args.blkcopy.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> blkcopy.preferredChNum=%d, blkcopy.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.blkcopy.preferredChNum, output->args.blkcopy.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_BLKCOPYCH:
        {
            Udma_rmFreeBlkCopyCh(cargs->args.blkcopy.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_BLKCOPYHCCH:
        {
            output->args.blkcopyhc.chNum =
                Udma_rmAllocBlkCopyHcCh(cargs->args.blkcopyhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> blkcopyhc.preferredChNum=%d, blkcopyhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.blkcopyhc.preferredChNum, output->args.blkcopyhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_BLKCOPYHCCH:
        {
            Udma_rmFreeBlkCopyHcCh(cargs->args.blkcopyhc.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_BLKCOPYUHCCH:
        {
            output->args.blkcopyuhc.chNum =
                Udma_rmAllocBlkCopyUhcCh(cargs->args.blkcopyuhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> blkcopyuhc.preferredChNum=%d, blkcopyuhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.blkcopyuhc.preferredChNum, output->args.blkcopyuhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_BLKCOPYUHCCH:
        {
            Udma_rmFreeBlkCopyUhcCh(cargs->args.blkcopyuhc.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_TXCH:
        {
            output->args.tx.chNum =
                Udma_rmAllocTxCh(cargs->args.tx.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> tx.preferredChNum=%d, tx.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.tx.preferredChNum, output->args.tx.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_TXCH:
        {
            Udma_rmFreeTxCh(cargs->args.tx.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_RXCH:
        {
            output->args.rx.chNum =
                Udma_rmAllocRxCh(cargs->args.rx.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> rx.preferredChNum=%d, rx.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.rx.preferredChNum, output->args.rx.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_RXCH:
        {
            Udma_rmFreeRxCh(cargs->args.rx.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_TXHCCH:
        {
            output->args.txhc.chNum =
                Udma_rmAllocTxHcCh(cargs->args.txhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> txhc.preferredChNum=%d, txhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.txhc.preferredChNum, output->args.txhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_TXHCCH:
        {
            Udma_rmFreeTxHcCh(cargs->args.txhc.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_RXHCCH:
        {
            output->args.rxhc.chNum =
                Udma_rmAllocRxHcCh(cargs->args.rxhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> rxhc.preferredChNum=%d, rxhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.rxhc.preferredChNum, output->args.rxhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_RXHCCH:
        {
            Udma_rmFreeRxHcCh(cargs->args.rxhc.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_TXUHCCH:
        {
            output->args.txuhc.chNum =
                Udma_rmAllocTxUhcCh(cargs->args.txuhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> txuhc.preferredChNum=%d, txuhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.txuhc.preferredChNum, output->args.txuhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_TXUHCCH:
        {
            Udma_rmFreeTxUhcCh(cargs->args.txuhc.chNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_RXUHCCH:
        {
            output->args.rxuhc.chNum =
                Udma_rmAllocRxUhcCh(cargs->args.rxuhc.preferredChNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> rxuhc.preferredChNum=%d, rxuhc.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.rxuhc.preferredChNum, output->args.rxuhc.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_RXUHCCH:
        {
            Udma_rmFreeRxUhcCh(cargs->args.rxuhc.chNum, drvHandle);
            break;
        }
#if (UDMA_NUM_UTC_INSTANCE > 0)
        case DCMD_TIUDMA_ALLOC_EXTCH:
        {
            output->args.ext.chNum =
                Udma_rmAllocExtCh(cargs->args.ext.preferredChNum, drvHandle, cargs->args.ext.utcInfo);
            udma_sloginfo("%s:%d UDMA---> ext.preferredChNum=%d, ext.ChNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.ext.preferredChNum, output->args.ext.chNum);
            break;
        }
        case DCMD_TIUDMA_FREE_EXTCH:
        {
            Udma_rmFreeExtCh(cargs->args.ext.chNum, drvHandle, cargs->args.ext.utcInfo);
            break;
        }
#endif
        case DCMD_TIUDMA_ALLOC_PROXY:
        {
            output->args.proxy.proxyNum =
                Resmgr_Udma_rmAllocProxy(cargs->args.proxy.preferredProxyNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> proxy.preferredProxyNum=%d, proxy.proxyNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.proxy.preferredProxyNum, output->args.proxy.proxyNum);
            break;
        }
        case DCMD_TIUDMA_FREE_PROXY:
        {
            Udma_rmFreeProxy(cargs->args.proxy.proxyNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_FREERING:
        {
            output->args.freering.ringNum =
                Udma_rmAllocFreeRing(drvHandle);
            udma_sloginfo("%s:%d UDMA---> freering.ringNum=%d\n", __FUNCTION__, __LINE__,
                output->args.freering.ringNum);
            break;
        }
        case DCMD_TIUDMA_FREE_FREERING:
        {
            Udma_rmFreeFreeRing(cargs->args.freering.ringNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_RINGMON:
        {
            output->args.ringmon.ringNum =
                Udma_rmAllocRingMon(drvHandle);
            udma_sloginfo("%s:%d UDMA---> ringmon.ringNum=%d\n", __FUNCTION__, __LINE__,
                output->args.ringmon.ringNum);
            break;
        }
        case DCMD_TIUDMA_FREE_RINGMON:
        {
            Udma_rmFreeRingMon(cargs->args.ringmon.ringNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_VINTR:
        {
            output->args.vintr.vintrNum =
                Udma_rmAllocVintr(drvHandle);
            udma_sloginfo("%s:%d UDMA---> vintr.vintrNum=%d\n", __FUNCTION__, __LINE__,
                output->args.vintr.vintrNum);
            break;
        }
        case DCMD_TIUDMA_FREE_VINTR:
        {
            Udma_rmFreeVintr(cargs->args.vintr.vintrNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_IRINTR:
        {
            output->args.irintr.irIntrNum =
                Udma_rmAllocIrIntr(cargs->args.irintr.preferredIrIntrNum, drvHandle);
            udma_sloginfo("%s:%d UDMA---> rintr.preferredIrIntrNum=%d irintr.irIntrNum=%d\n", __FUNCTION__, __LINE__,
                cargs->args.irintr.preferredIrIntrNum, output->args.irintr.irIntrNum);
            break;
        }
        case DCMD_TIUDMA_FREE_IRINTR:
        {
            Udma_rmFreeIrIntr(cargs->args.irintr.irIntrNum, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_EVENT:
        {
            output->args.event.globalEvent =
                Udma_rmAllocEvent(drvHandle);
            udma_sloginfo("%s:%d UDMA---> event.globalEvent=%d\n", __FUNCTION__, __LINE__,
                output->args.event.globalEvent);
            break;
        }
        case DCMD_TIUDMA_FREE_EVENT:
        {
            Udma_rmFreeEvent(cargs->args.event.globalEvent, drvHandle);
            break;
        }
        case DCMD_TIUDMA_ALLOC_VINTRBIT:
        {
            output->args.vintrbit.vintrBitNum =
                Udma_rmAllocVintrBit(drvHandle->globalEventHandle);
            udma_sloginfo("%s:%d UDMA---> vintrbit.vintrBitNum=%d\n", __FUNCTION__, __LINE__,
                output->args.vintrbit.vintrBitNum);
            break;
        }
        case DCMD_TIUDMA_FREE_VINTRBIT:
        {
            Udma_rmFreeVintrBit(cargs->args.vintrbit.vintrBitNum, drvHandle, drvHandle->globalEventHandle);
            break;
        }
#if 0 // TODO: Add these in later
        case DCMD_TIUDMA_ALLOC_FLOW:
        {
            output->args.flow.vintrBitNum =
                Udma_rmAllocVintrBit(drvHandle->globalEventHandle);
            break;
        }
        case DCMD_TIUDMA_FREE_FLOW:
        {
            Udma_rmFreeVintrBit(cargs->args.flow.vintrBitNum, drvHandle, drvHandle->globalEventHandle);
            break;
        }
#endif
        default:
        {
            err = EINVAL;
        }
    }

    if (err != EOK)
    {
        udma_slogerr("%s: ERROR nbytes/%d err/%d EOK/%d\n",__func__,nbytes,err,EOK);
        pthread_mutex_unlock(&udma_ocb->lock);
        return (err);
    }

    msg->o.ret_val = 0;
    pthread_mutex_unlock(&udma_ocb->lock);

    return (_RESMGR_PTR(ctp, &msg->o, sizeof(msg->o) + sizeof(TIUDMA_CmdArgs)));
}

