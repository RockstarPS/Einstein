/*
 * Copyright (c) 2020-2024, Texas Instruments Incorporated
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
 *  \file sciclient_rm_irq.c
 *
 *  \brief File containing the interrupt routing logic front-end for interrupt
 *         resource management SYSFW services.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <string.h>
#include <kernel/dpl/SystemP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <drivers/hw_include/csl_types.h>
#include <drivers/sciclient.h>
#include <drivers/sciclient/sciclient_rm_priv.h>

#include <drivers/hw_include/cslr_soc.h>
#include <drivers/hw_include/cslr_intaggr.h>
#include <drivers/hw_include/cslr_intr_router.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * Maximum depth of the path stack.
 */
#define SCICLIENT_PS_MAX_DEPTH (SCICLIENT_IRQ_MAX_ROUTE_DEPTH)

#define SCICLIENT_INP_TO_OUTP(rinp, rbase, lbase) (lbase + (rinp - rbase))
#define SCICLIENT_OUTP_TO_INP(loutp, lbase, rbase) (rbase + (loutp - lbase))

/*
 * IR Register Macros
 */
#define SCICLIENT_IR_INT_CONTROL_REG_OFFSET        0x00000004U
#define SCICLIENT_IR_INT_CONTROL_REG_STEP          0x00000004U

/*
 * IA Register Macros
 */
#define SCICLIENT_IA_ENTRY_INTMAP_LO(e)        ((e) * 0x8u)

#define SCICLIENT_IA_VINT_MAX_BITS             64u

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Sciclient_rmProgramInterruptRoute (const struct tisci_msg_rm_irq_set_req *req,
                                           const struct tisci_msg_rm_irq_set_resp *resp,
                                           uint32_t timeout __attribute__((unused)))
{
    int32_t r = SystemP_SUCCESS;
    return r;
}

int32_t Sciclient_rmClearInterruptRoute (const struct tisci_msg_rm_irq_release_req *req,
                                         const struct tisci_msg_rm_irq_release_resp *resp,
                                         uint32_t timeout __attribute__((unused)))
{
    int32_t r = SystemP_SUCCESS;
    return r;
}

int32_t Sciclient_rmTranslateIntOutput(uint16_t  src_dev_id,
                                      uint16_t  src_output,
                                      uint16_t  dst_dev_id,
                                      uint16_t  *dst_input)
{
    int32_t r = SystemP_SUCCESS;
    return r;
}

int32_t Sciclient_rmTranslateIrqInput(uint16_t  dst_dev_id,
                                      uint16_t  dst_input,
                                      uint16_t  src_dev_id,
                                      uint16_t  *src_output)
{
    int32_t r = SystemP_SUCCESS;
    return r;
}
