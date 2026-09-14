/*
 *  Copyright (C) 2023 Texas Instruments Incorporated
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
 *  \file dss_evtMgr.c
 *
 *  \brief File containing the DSS event manager implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <drivers/dss.h>
#include <drivers/fvid2.h>
#include <kernel/dpl/SemaphoreP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/dss/v0/common/dss_evtMgr.h>

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

/* ========================================================================== */
/*                  Internal/Private Function Declarations                   */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Dss_evtMgrInit(const Dss_EvtMgrInitParams *initParams)
{
    return FVID2_SOK;
}

int32_t Dss_evtMgrDeInit(void)
{
    return FVID2_SOK;
}

void *Dss_evtMgrRegister(uint32_t instId,
                         uint32_t eventGroup,
                         const uint32_t *event,
                         uint32_t numEvents,
                         Dss_evtMgrCbFxn callback,
                         void *arg)
{
    return NULL;
}

int32_t Dss_evtMgrUnRegister(void *handle)
{
    return FVID2_SOK;
}

int32_t Dss_evtMgrEnable(void *handle)
{
    return FVID2_SOK;
}

int32_t Dss_evtMgrDisable(void *handle)
{
    return FVID2_SOK;
}

void Dss_evtMgrMasterIsr(uint8_t arg)
{
    
}
