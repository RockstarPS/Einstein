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
 *  \ingroup DRV_IPC_MODULE
 *  \defgroup DRV_IPC_VIRTIO_MODULE IPC Driver VirtIO configuration
 *            This is documentation for VirtIO configurations used by IPC
 *
 *  @{
 */

/**
 *  \file ipc_virtio.h
 *
 *  \brief VirtIO Interface for application.
 */

#ifndef IPC_VIRTIO_H_
#define IPC_VIRTIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <CddIpc/ipc_baremetal_hw/soc/ipc_soc.h>
#include <CddIpc/ipc_baremetal_hw/include/ipc_types.h>
/**
 *  \brief Parameter structure for creating VirtIO table for each core
 *  combinations.
 */
typedef struct Ipc_VirtIoParams_s
{
    void      *vqObjBaseAddr;
    /**< Base address for storing VQ Object */

    uint32  vqBufSize;
    /**< Size of the Buffer for storing VQ objects */

    void      *vringBaseAddr;
    /**<  Base address for Shared VRing for all cores */

    uint32  vringBufSize;
    /**< Buffer Size. Recommemded Size is 0x40000 * NumOfCores */

    uint32  timeoutCnt;
    /**< timeoutCnt. Set 0xFFFFFFFF for wait forever */
} Ipc_VirtIoParams;




/**
 * \brief Returns local memory for Virtio objects for one core-pair
 */
uint32 Ipc_getVqObjMemoryRequiredPerCore(void);

/**
 *  \brief      Initailize the Virtio module
 * 
 *  \return      #IPC_SOK or #IPC_EFAIL
 */
sint32 Ipc_initVirtIO(Ipc_VirtIoParams *vqParam);


/**
 *  \brief     Loads the resource table. If the remote
 *             core A72, and has valid radource table
 *             then, it will wait for Linux to be ready
 *             use address from resource table.
 *
 *  \param rsctable [IN] Pointer of resource table
 *
 *  \return      #IPC_SOK or #IPC_EFAIL
 */
#if !defined (SOC_AM275X)
sint32 Ipc_loadResourceTable(void *rsctable);
#endif

/**
 *  \brief     Gets the address of the trace buffer.
 *
 *  \return    Address of the trace buffer.
 */
void * Ipc_getResourceTraceBufPtr(void);
/**
 *  \brief Ipc_allocVirtio
 */
void* Ipc_allocVirtio(void);

void Virtio_isr(uint32* msg, uint32 priv);

/**
 * \brief Resets the local VRing queue handles for the remote core.
 *
 * \param remoteId  [IN] Id of remote processor
 *
 * \return  None
 *
 */
#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) || defined(SOC_J742S2) || defined(SOC_J784S4) || defined(SOC_J7200)
void Ipc_resetCoreVirtIO(uint32 remoteId);
#endif

/**
 * \brief  Checks if remote is ready
 *
 * \param procId [IN] Id of remote core
 *
 * \return  1 if remote proc is is not A72 or resource table is null
 *            or linux vdev status is 0x7
 *          0 if linux vdev status is not 0x7
 *
 */
uint8 Ipc_isRemoteReady(uint16 procId);
/**
 * \brief Check if a remote Virtio has been created
 *
 * \param remoteId  [IN] Id of remote processor
 *
 * \return  1 if virtio exists for the given remote proc
 *          0 if virtio does not exist for the given remote proc
 */
uint8 Ipc_isRemoteVirtioCreated(uint32 remoteId);

/**
 * \brief Creates Virtio late when Linux is ready
 *
 * \param procId  [IN] Id of remote processor
 *
 * \return #IPC_SOK or #IPC_EFAIL
 */
sint32 Ipc_physToVirt(uint32 pa, uint32 *va);

/**
 * \brief Get physical address from given virual address
 *
 * \param   pa physical address
 *          va virtual address
 *
 * \return #IPC_SOK or #IPC_EFAIL
 *
 **/
sint8 Ipc_virtToPhys(uint32 va, uint32 *pa);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef IPC_VIRTIO_H_ */

/* @} */
