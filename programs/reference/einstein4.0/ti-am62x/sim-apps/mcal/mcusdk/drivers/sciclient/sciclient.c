/*
 * Copyright (c) 2017-2024, Texas Instruments Incorporated
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
 *  \file sciclient.c
 *
 *  \brief File containing the SCICLIENT driver APIs.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <drivers/sciclient/sciclient_priv.h>
#include <kernel/dpl/HwiP.h>
#include <kernel/dpl/SystemP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <stdbool.h>
#include <string.h> /*For memcpy*/
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*Header size in words*/
#define SCICLIENT_HEADER_SIZE_IN_WORDS (sizeof (struct tisci_header) \
                                        / sizeof (uint32_t))

/** Indicate that this message is marked secure */
#define TISCI_MSG_FLAG_MASK    (TISCI_BIT(0) | TISCI_BIT(1))

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Sciclient_init(uint32_t coreId)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_deinit(void)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_abiCheck(void)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_getVersionCheck(uint32_t doLog)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_triggerSecHandover(void)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_service(const Sciclient_ReqPrm_t *pReqPrm,
                          Sciclient_RespPrm_t      *pRespPrm)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_loadFirmware(const uint32_t *pSciclient_firmware)
{
    return SystemP_SUCCESS;
}

int32_t Sciclient_waitForBootNotification(void)
{
    return SystemP_SUCCESS;
}

uint32_t Sciclient_getCurrentContext(uint16_t messageType)
{
    return 0;
}

uint32_t Sciclient_getSelfDevIdCore(void)
{
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */