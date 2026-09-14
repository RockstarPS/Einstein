/*
*
* Copyright (c) 2023 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     DioApp.c
 *
 *  \brief    This file contains the DIO test example
 */
#ifndef DIO_APP_C
#define DIO_APP_C
/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
/* Include Files */
#include "stdio.h"
#include "app_utils.h"
#ifdef SIMULATION_BUILD
#include <hw_include/soc1.h>
#else
#include <hw_include/soc.h>
#endif
#include <hw_include/lld_gpio.h>
#include <hw_include/arch/lld_arch.h>
#include "DioApp.h"
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"

/**
 *\brief   This function is set a unloack MMR register required for Pin Mux
 *
 */
extern void DioApp_unlockMmrRegisters(uint32 lockKey0, uint32 lockKey1)
{
    uint32 regVal = 0U;
    (void)lockKey0;
    (void)lockKey1;

    /* write Partition 1 Lock Key 0 Register */
    LLD_REG32_WR(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + 0x5008U, 0x68EF3490);

    AppUtils_Printf((uint32)APP_UTILS_PRINT_MSG_NORMAL,
                    "\n");

    /* write Partition 1 Lock Key 1 Register */
    LLD_REG32_WR(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + 0x500CU, 0xD172BC5AU);

    AppUtils_Printf((uint32)APP_UTILS_PRINT_MSG_NORMAL,
                    "\n");

    /* Check for unlock */
    regVal = LLD_REG32_RD(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + 0x5008U);
    while ((regVal & 0x1U) != 0x1U)
    {
        regVal = LLD_REG32_RD(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + 0x5008U);
    }
	
	/*Main GPIO- PADCFG_CTRL0_CFG0 Register*/
	/* write Partition 1 Lock Key 0 Register */
	LLD_REG32_WR(CSL_PADCFG_CTRL0_CFG0_BASE + 0x5008U, 0x68EF3490);
    AppUtils_Printf((uint32)APP_UTILS_PRINT_MSG_NORMAL,
                    "\n");

    /* write Partition 1 Lock Key 1 Register */
	LLD_REG32_WR(CSL_PADCFG_CTRL0_CFG0_BASE + 0x500CU, 0xD172BC5AU);
    AppUtils_Printf((uint32)APP_UTILS_PRINT_MSG_NORMAL,
                    "\n");

    /* Check for unlock */
	regVal = LLD_REG32_RD(CSL_PADCFG_CTRL0_CFG0_BASE + 0x5008U); 
    while ((regVal & 0x1U) != 0x1U)
    {
		regVal = LLD_REG32_RD(CSL_PADCFG_CTRL0_CFG0_BASE + 0x5008U);
    }

    return;
}

/**
 *\brief   This function is enable Pin Muxing: Wakeup domain
 *
 */

extern void DioApp_McuDomainPinMux(uint32 offset, uint32 muxmode)
{
    uint32 regVal = 0U;

    regVal = LLD_REG32_RD(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + offset);
    regVal &= 0U;
    regVal |= muxmode;
    LLD_REG32_WR(CSL_MCU_PADCFG_CTRL0_CFG0_BASE + offset, regVal);

    return;
}
extern void DioApp_MainDomainPinMux(uint32 offset, uint32 muxmode)
{
    uint32 regVal = 0U;

    regVal = LLD_REG32_RD(CSL_PADCFG_CTRL0_CFG0_BASE + offset);
    regVal &= 0U;
    regVal |= muxmode;
    LLD_REG32_WR(CSL_PADCFG_CTRL0_CFG0_BASE + offset, regVal);

    return;
}

#endif 
