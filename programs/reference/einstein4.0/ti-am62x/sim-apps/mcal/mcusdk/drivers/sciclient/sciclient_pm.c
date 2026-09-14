/*
 * Copyright (c) 2018-2024, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 *  \file sciclient_pm.c
 *
 *  \brief File containing the SCICLIENT API interfaces to the Power management
 *         SYSFW services.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <string.h>
#include <drivers/hw_include/csl_types.h>
#include <drivers/sciclient.h>
#include <kernel/dpl/SystemP.h>

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

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Sciclient_pmSetModuleState(uint32_t moduleId,
                                   uint32_t state,
                                   uint32_t reqFlag,
                                   uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmGetModuleState(uint32_t  moduleId,
                                   uint32_t *moduleState,
                                   uint32_t *resetState,
                                   uint32_t *contextLossState,
                                   uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmSetModuleRst(uint32_t moduleId,
                                 uint32_t resetBit,
                                 uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmSetModuleRst_flags(uint32_t moduleId,
                                 uint32_t resetBit,
                                 uint32_t reqFlag,
                                 uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmModuleClkRequest(uint32_t moduleId,
                                     uint32_t clockId,
                                     uint32_t state,
                                     uint32_t additionalFlag,
                                     uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmModuleGetClkStatus(uint32_t  moduleId,
                                       uint32_t  clockId,
                                       uint32_t *state,
                                       uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmSetModuleClkParent(uint32_t moduleId,
                                       uint32_t clockId,
                                       uint32_t parent,
                                       uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmGetModuleClkParent(uint32_t  moduleId,
                                       uint32_t  clockId,
                                       uint32_t *parent,
                                       uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmGetModuleClkNumParent(uint32_t  moduleId,
                                          uint32_t  clockId,
                                          uint32_t *numParent,
                                          uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmSetModuleClkFreq(uint32_t moduleId,
                                     uint32_t clockId,
                                     uint64_t freqHz,
                                     uint32_t additionalFlag,
                                     uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmQueryModuleClkFreq(uint32_t moduleId,
                                       uint32_t clockId,
                                       uint64_t reqFreqHz,
                                       uint64_t *respFreqHz,
                                       uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmGetModuleClkFreq(uint32_t  moduleId,
                                     uint32_t  clockId,
                                     uint64_t *freqHz,
                                     uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_pmDeviceReset(uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

