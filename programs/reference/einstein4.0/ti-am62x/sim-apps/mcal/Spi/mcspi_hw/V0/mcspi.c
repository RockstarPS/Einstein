/*
 *  Copyright (C) 2024 Texas Instruments Incorporated - www.ti.com
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
 * \file       mcspi.c
 *
 * \brief      This file contains the function definitions for the device
 *             abstraction layer for MCSPI.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/**
 * \brief This is to disable HW_SYNC_BARRIER for J7 due to performance
 *        requirement
 */
#define MEM_BARRIER_DISABLE

/*LDRA_ANALYSIS*/
#include "Std_Types.h"
#include <hw_include/lld_mcspi.h>

/*LDRA_NOANALYSIS*/
#include <stdint.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define MCSPI_CLKD_MASK       (0xF)

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void McSPIIntEnable(uint32 baseAddr, uint32 intFlags)
{
    
}

void McSPIIntDisable(uint32 baseAddr, uint32 intFlags)
{

}

uint32 McSPIIntStatusGet(uint32 baseAddr)
{
    /* Return the interrupt status present in the MCSPI_IRQSTATUS register. */
    return 0;
}

void McSPIIntStatusClear(uint32 baseAddr, uint32 intFlags)
{
    
}

/***************************** END OF FILE ************************************/
