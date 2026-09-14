/*
 *  Copyright (C) 2023-25 Texas Instruments Incorporated
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include <sdl/include/sdl_types.h>
#include <sdl/sdl_ecc.h>
#include "sdl_r5_utils.h"
#include <sdl/ecc/sdl_ecc_utils.h>
#include <sdl/ecc/sdl_ecc_priv.h>
#include <sdl/ecc/sdl_ecc_core.h>
#include <sdl/ecc/soc/sdl_soc_ecc.h>
#include "sdl_vim.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Local defines */
#define SDL_ECC_R5_CFLR_ATCM_DATA_ERROR_MASK (0x1000001u)
#define SDL_ECC_R5_CFLR_BTCM_DATA_ERROR_MASK (0x2000001u)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*********************************************************************
 *
 * /brief   Configure ECC for given ram Id for the CPU
 *
 * /param  ramId: Ram Id of memory section
 *
 * /return  SDL_PASS : Success; SDL_EFAIL for failures
 */
int32_t SDL_ECC_configECCRam(uint32_t ramId)
{
    int32_t retVal= SDL_PASS;

    return retVal;

}

/*********************************************************************
 *
 * /brief   Poll ecc event
 *
 * \param  eccMemType: Memory type
 * \param  memSubType: Memory subtype
 * \param  errorType:  Error type to poll
 *
 * \return SDL_ECC_EVENT_FOUND or if no events found
 */
uint32_t SDL_ECC_pollErrorEvent(SDL_ECC_MemType eccMemType,
                               SDL_ECC_MemSubType memSubType,
                               SDL_ECC_InjectErrorType errorType)
{
    uint32_t retValue = 0u;

    return retValue;
}
