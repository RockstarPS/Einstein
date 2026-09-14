/*
 *   Copyright (C) 2022-24 Texas Instruments Incorporated
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
 *
 */

/**
 *  \file     sdl_dcc.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of DCC.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "sdlr_dcc2.h"
#include "sdl_dcc.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* Internal functions */

static int32_t SDL_DCC_checkMode(SDL_DCC_Mode mode)
{
    int32_t sdlResult = SDL_PASS;



    return sdlResult;
}

static int32_t SDL_DCC_checkClkSrc0(SDL_DCC_ClkSrc0 clkSrc0)
{
    int32_t sdlResult = SDL_PASS;


    return sdlResult;
}

static int32_t SDL_DCC_checkClkSrc1(SDL_DCC_ClkSrc1 clkSrc1)
{
    int32_t sdlResult = SDL_PASS;

    return sdlResult;
}

/*******************************************************************************
 *   API for configuring the DCC module
 ******************************************************************************/

/**
 *  Design: PROC_SDL-2071
 */

int32_t SDL_DCC_configure(SDL_DCC_Inst instance, const SDL_DCC_Config *pConfig)
{
    int32_t sdlResult = SDL_EFAIL;

    return sdlResult;
}


/********************************************************************************************************
*   API for verify the configuration of DCC module
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2074
 */
int32_t SDL_DCC_verifyConfig(SDL_DCC_Inst instance, const SDL_DCC_Config *pConfig)
{

    int32_t  sdlResult = SDL_EFAIL;


    return sdlResult;
}


/********************************************************************************************************
*   API for Enabling the DCC module
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2072
 */
int32_t SDL_DCC_enable(SDL_DCC_Inst instance)
{
    int32_t sdlResult = SDL_EFAIL;


    return sdlResult;
}


/********************************************************************************************************
*   API for Disabling the DCC module
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2073
 */
int32_t SDL_DCC_disable(SDL_DCC_Inst instance)
{

    int32_t sdlResult = SDL_EFAIL ;


    return sdlResult;
}


/********************************************************************************************************
*   API for getting the status of specified DCC instance
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2075
 */
int32_t SDL_DCC_getStatus(SDL_DCC_Inst instance, SDL_DCC_Status *pStatus)
{

    int32_t sdlResult = SDL_EFAIL ;

    return sdlResult;
}



/********************************************************************************************************
*   API for Enabling the Error and Done Interrupts
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2140
 */
int32_t SDL_DCC_enableIntr(SDL_DCC_Inst instance, SDL_DCC_IntrType intr)
{
    int32_t sdlResult = SDL_EFAIL;

    return sdlResult;

}


/********************************************************************************************************
*   API for disabling the Interrupt
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2076
 */
int32_t SDL_DCC_disableIntr(SDL_DCC_Inst instance, SDL_DCC_IntrType intr)
{
    int32_t sdlResult = SDL_EFAIL;

    return sdlResult;
}

/********************************************************************************************************
*   API for clearing the Interrupt
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-??
 */
int32_t SDL_DCC_clearIntr(SDL_DCC_Inst instance, SDL_DCC_IntrType intr)
{
    int32_t sdlResult = SDL_EFAIL;

    return sdlResult;
}


/********************************************************************************************************
*   API for reading the static registers values
*********************************************************************************************************/

/**
 *  Design: PROC_SDL-2077
 */
int32_t SDL_DCC_getStaticRegs(SDL_DCC_Inst instance, SDL_DCC_StaticRegs *pStaticRegs)
{

    int32_t  sdlResult = SDL_EFAIL;


    return sdlResult;

}




