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
 *  \file sciclient_procboot.c
 *
 *  \brief File containing the SCICLIENT API interfaces to the Processor boot
 *         SYSFW services.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <string.h>
#include <kernel/dpl/SystemP.h>
#include <drivers/hw_include/csl_types.h>
#include <drivers/sciclient.h>

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

int32_t Sciclient_procBootRequestProcessor(uint8_t processorId,
                                           uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}


int32_t Sciclient_procBootReleaseProcessor(uint8_t  processorId,
                                           uint32_t reqFlag,
                                           uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootHandoverProcessor(uint8_t  processorId,
                                            uint8_t  hostId,
                                            uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootSetProcessorCfg (
            const struct tisci_msg_proc_set_config_req * configReq,
            uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootSetSequenceCtrl(uint8_t  processorId,
                                          uint32_t control_flags_1_set,
                                          uint32_t control_flags_1_clear,
                                          uint32_t reqFlag,
                                          uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootAuthAndStart(
            const struct tisci_msg_proc_auth_boot_req * authBootCfg,
            uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootGetProcessorState(
            uint8_t processorId,
            struct tisci_msg_proc_get_status_resp * procStatus,
            uint32_t  timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

int32_t Sciclient_procBootWaitProcessorState(uint8_t  processorId,
                                        uint8_t  num_match_iterations,
                                        uint8_t  delay_per_iteration_us,
                                        uint32_t status_flags_1_set_all_wait,
                                        uint32_t status_flags_1_set_any_wait,
                                        uint32_t status_flags_1_clr_all_wait,
                                        uint32_t status_flags_1_clr_any_wait,
                                        uint32_t reqFlag,
                                        uint32_t timeout)
{
    int32_t retVal = SystemP_SUCCESS;
    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

