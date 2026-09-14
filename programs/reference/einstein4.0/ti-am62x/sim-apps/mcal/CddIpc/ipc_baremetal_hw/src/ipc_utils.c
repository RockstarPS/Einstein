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
 *  \file ipc_utils.c
 *
 *  \brief Implementation of ipc utility functions such as queues,
 *          buffer manager, etc...
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <CddIpc/ipc_baremetal_hw/ipc.h>
#include "ipc_utils.h"
#include "ipc_priv.h"

#include <CddIpc/ipc_baremetal_hw/soc/ipc_soc.h>
#include <CddIpc/ipc_baremetal_hw/include/ipc_types.h>

#if defined (IPC_CFG_PRINT_ENABLE)
/* This is needed for vsnprintf */
#include <stdio.h>
#include <stdarg.h>
#endif

/* ========================================================================== */
/*                            Local Types/Defines                             */
/* ========================================================================== */

/* ========================================================================== */
/*                               Globals                                      */
/* ========================================================================== */

#define CDD_IPC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

/**< Function disable all interrupts */

/* ========================================================================== */
/*                              API's                                         */
/* ========================================================================== */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

int32_t IpcUtils_Init(Ipc_OsalPrms *pOsalInit)
{
    int32_t rtnVal = IPC_EINVALID_PARAMS;
    return (rtnVal);
}

/* Queue Related */
void* IpcUtils_QgetHead(IpcUtils_QHandle *handle)
{
    IpcUtils_QElem *elem = NULL;
    return (elem);
}

uint8 IpcUtils_QisEmpty(IpcUtils_QHandle *handle)
{
    uint8 rtnVal = 0U;
    return (rtnVal);
}

void IpcUtils_Qput(IpcUtils_QHandle *handle, IpcUtils_QElem *elem)
{
    
}

void IpcUtils_Qenqueue(IpcUtils_QHandle *handle, IpcUtils_QElem *elem)
{
    
}

void* IpcUtils_Qnext(IpcUtils_QElem *qelem)
{
    void *rtnVal = NULL;
    return rtnVal;
}

void IpcUtils_Qremove(IpcUtils_QElem *qelem)
{
    
}

void IpcUtils_Qdelete(IpcUtils_QHandle *handle)
{

}

int32_t IpcUtils_Qcreate(IpcUtils_QHandle *handle)
{
    int32_t rtnVal = IPC_EINVALID_PARAMS;
    return (rtnVal);
}

int32_t IpcUtils_HeapCreate(IpcUtils_HeapHandle *pHndl,
                            IpcUtils_HeapParams *param)
{
    int32_t rtnVal = IPC_EINVALID_PARAMS;
    return rtnVal;
}

void IpcUtils_HeapDelete(IpcUtils_HeapHandle *pHndl)
{
    
}

void *IpcUtils_HeapAlloc(IpcUtils_HeapHandle *pHndl, uint32 size,
                            uint32 align)
{
    return NULL;   
}

void IpcUtils_HeapFree(IpcUtils_HeapHandle *pHndl, void* block, uint32 size)
{
    
}

void SystemP_printf(const sint8 *format, ...)
{

}

uint32 IpcUtils_strnlen(const unsigned char *string, uint32 stringlen)
{
    uint32 len = 0U;
    return (len);
}

void string_copy_n(sint8 *dest, const sint8 *src, uint32 n)
{
    
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

/* ========================================================================== */
/*                          Local Functions                                   */
/* ========================================================================== */
