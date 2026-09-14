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
 *  \file dss_dctrlApi.c
 *
 *  \brief File containing the DSS Controller driver implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <kernel/dpl/SemaphoreP.h>
#include <drivers/dss.h>
#include <drivers/dss/v0/common/dss_evtMgr.h>
#include <drivers/dss/v0/dctrl/dss_dctrlDrv.h>
#include <drivers/dss/v0/dctrl/dss_dctrlPriv.h>
#include <drivers/dss/v0/dctrl/dss_dctrlIntr.h>
#include <drivers/dss/v0/soc/dss_soc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  Below ifdef __cplusplus is added so that C++ build passes without
 *  typecasting. This is because the prototype is build as C type
 *  whereas this file is build as CPP file. Hence we get C++ build error.
 *  Also if typecasting is used, then we get MisraC error Rule 11.1.
 */
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                  Internal/Private Function Declarations                    */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Dss_dctrlDrvInit(const Dss_DctrlDrvInitParams *drvInitParams)
{
    int32_t retVal = FVID2_SOK;
    return (retVal);
}

int32_t Dss_dctrlDrvDeInit(void)
{
    int32_t retVal = FVID2_SOK;
    return (retVal);
}

DssDctrlDrvClientHandle Dss_dctrlDrvRegisterClient(
                                    uint32_t nodeId,
                                    const Dss_DctrlDrvClientInfo *clientInfo)
{
    DssDctrlDrvClientHandle clientHandle = NULL;
    return clientHandle;
}

int32_t Dss_dctrlDrvUnRegisterClient(DssDctrlDrvClientHandle handle)
{
    int32_t retVal = FVID2_SOK;
    return retVal;
}

int32_t Dss_dctrlDrvStartClient(DssDctrlDrvClientHandle handle,
                                uint32_t dummyStart)
{
    int32_t retVal = FVID2_SOK;
    return retVal;
}

int32_t Dss_dctrlDrvStopClient(DssDctrlDrvClientHandle handle,
                               uint32_t syncStop)
{
    int32_t retVal = FVID2_SOK;
    return retVal;
}

int32_t Dss_dctrlDrvGetVpParams(DssDctrlDrvClientHandle handle,
                                Dss_DctrlVpParams *vpParams)
{
    int32_t retVal = FVID2_SOK;
    return retVal;
}

int32_t Dss_dctrlDrvSetGoBit(DssDctrlDrvClientHandle handle)
{
    int32_t retVal = FVID2_SOK;
    return (retVal);
}

uint32_t Dss_dctrlDrvIsSafeToPush(DssDctrlDrvClientHandle handle)
{
    uint32_t retVal = FALSE;
    return retVal;
}

Dss_DctrlDrvPipeInfo *Dss_dctrlDrvGetPipeInfo(DssDctrlDrvClientHandle handle)
{
    return NULL;
}

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */
