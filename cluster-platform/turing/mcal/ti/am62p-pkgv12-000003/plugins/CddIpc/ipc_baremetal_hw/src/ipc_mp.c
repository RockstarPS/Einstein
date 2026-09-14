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
 *  \file ipc_mp.c
 *
 *  \brief File containing the IPC driver utilities for MultiProc handling.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include <CddIpc/ipc_baremetal_hw/ipc.h>
#include <CddIpc/ipc_baremetal_hw/include/ipc_mp.h>
#include <CddIpc/ipc_baremetal_hw/include/ipc_types.h>
#include "ipc_priv.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

typedef struct Ipc_MpConfig_s
{
    uint32	selfProcId;
    /**< own processor id */

    uint8        name[IPC_MAX_PROC_NAMELEN];
    /**< Name of self processor */

    uint32    numProcessors;
    /**< Number of Processors */

    Ipc_ProcInfo procInfo[IPC_MAX_PROCS];
    /**< Array of processors Info */
}Ipc_MpConfig;

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

static Ipc_MpConfig   g_ipcMpConfig;

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

sint32 Ipc_mpSetConfig(uint32 selfId, uint32 numProc, uint32 procArry[IPC_MAX_PROCS])
{
    sint32        retVal = IPC_SOK;
    Ipc_MpConfig  *pMpCfg = &g_ipcMpConfig;
    uint32       i = 0;
    uint32       id;

    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage as this branch handles invalid configuration
     * parameters (when `selfId >= IPC_MAX_PROCS` or `numProc > IPC_MAX_PROCS`). In all
     * supported board configurations and in unit/integration tests the processor IDs and
     * counts are supplied from static platform configuration and always satisfy
     * `0 <= id < IPC_MAX_PROCS`. Exercising this defensive path requires intentionally
     * malformed or corrupted inputs, which are out of scope for normal functional tests.
     *
     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review..
     */
    if( (selfId >= IPC_MAX_PROCS) || (numProc > IPC_MAX_PROCS) )
    {

      retVal = IPC_EINVALID_PARAMS;
     
    }
    /* TI_COVERAGE_GAP_STOP */
    else
    {
        pMpCfg->selfProcId    = selfId;
        pMpCfg->numProcessors = numProc;
        const sint8 *ptr = Ipc_getCoreName(selfId);
      if (ptr != NULL)
      {
        string_copy_n((sint8 *)pMpCfg->name, ptr, IPC_MAX_PROC_NAMELEN-1);
      }
      /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the else need not to  be covered as it is added just to avoid MISRA violation .

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
      else
     {
       /* Added to avoid MISRA violation */
     }
        pMpCfg->name[IPC_MAX_PROC_NAMELEN-1] = '\0';
        for(i = 0; i < numProc; i++)
        {
            id = procArry[i];
            pMpCfg->procInfo[i].procId = id;
            if(id < IPC_MAX_PROCS)
            {
              ptr = Ipc_getCoreName(id);
              if (ptr != NULL)
              {
                string_copy_n((sint8 *)pMpCfg->procInfo[i].name, ptr, IPC_MAX_PROC_NAMELEN-1);
                pMpCfg->procInfo[i].name[IPC_MAX_PROC_NAMELEN-1] = '\0';
              }
              else
              /**
               * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the ptr variable is assigned a variable before the NULL condition check.

               * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
               */
              {
                /* Added to avoid MISRA violation */
              }
         /* TI_COVERAGE_GAP_STOP */
       }
        }
    }

    return retVal;
}

uint16 Ipc_mpGetNumProcessors(void)
{
    return g_ipcMpConfig.numProcessors;
}

uint32 Ipc_mpGetSelfId(void)
{
    return g_ipcMpConfig.selfProcId;
}

uint32 Ipc_mpGetRemoteProcId(uint32 coreIndex)
{
    uint32       remoteId = 0xFFU;
    Ipc_MpConfig  *pMpCfg = &g_ipcMpConfig;

    if(coreIndex < g_ipcMpConfig.numProcessors)

    { 
      remoteId = pMpCfg->procInfo[coreIndex].procId;
    }
    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the below The selfProcId variable is assigned a variable before the NULL condition check, so Else case can’t be covered
    * Since it is hardware dependent.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    else
    {
      /* Do Nothing */
    }
    /* TI_COVERAGE_GAP_STOP */

    return remoteId;
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"
