/*
*
* Copyright (C) 2024 Texas Instruments Incorporated
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
 *  \file   Fls_OSPI.c
 *
 *  \brief  OSPI  specific driver APIs implementation.
 *
 *   This file contains the driver APIs for OSPI controller.
 */


 /* ========================================================================== */
 /*                             Include Files                                  */
 /* ========================================================================== */
#include "Std_Types.h"
#include "stdint.h"
#include <hw_include/arch/lld_arch.h>
#include "Fls_Ospi.h"
#include "Fls_Brd_Nor.h"
#include "Fls_Cfg.h"
#include <SchM_Fls.h>
#include "Os.h"



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/*
 *  ======== OSPI_hwi ========
 *  Hwi interrupt handler to service the OSPI peripheral
 *
 *  The handler is a generic handler for a OSPI object.
 */
void OSPI_hwi(SPI_Handle handle)
{
    
}

/*
 *  ======== OSPI_close ========
 */
void Fls_OSPI_close(SPI_Handle handle)
{
    
}

/*
 *  ======== OSPI_init ========
 */

void Fls_OSPI_init(SPI_Handle handle)
{

}

/*
 *  ======== OSPI_open ========
 */
SPI_Handle Fls_OSPI_open(SPI_Handle handle, const SPI_Params *params)
{
    SPI_Handle               retHandle = handle;
    return(retHandle);
}

 /* FLS_CoverageGap_09:Dynamic coverage for OSPI_transfer() cannot be acieved,
  * as the variable xferRet expects a value from OSPI_primeTransfer which is a static function.
  */
boolean OSPI_transfer(SPI_Handle handle, SPI_Transaction *transaction_xfer)
{
    boolean                ret = FALSE; /* return value */
    return (ret);
}

Std_ReturnType OSPI_control(SPI_Handle handle, uint32 cmd, const void *arg)
{
    Std_ReturnType      retVal = E_NOT_OK;
    return retVal;
}

/*
 *  ======== SPI_Params_init ========
 */
void SPI_Params_init(SPI_Params *params)
{
    
}

/*******************************************************************************
 * Fls_RegisterReadback
 ******************************************************************************/
/*! \brief      This is the function for checking the configuration registers.
 *              This APi can be called by higher layers to check if configuration
 *              is correct.
 *
 *  \param[in] SPI_Handle handle - Handle for the SPI object that will used in OSPI Driver
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-7300,MCAL-7375,MCAL-7371,MCAL-7423
 */
#if (STD_ON == OSPI_REGISTER_READBACK_API)

Std_ReturnType Ospi_RegisterReadback(
    P2VAR(CSL_ospi_flash_cfgRegs, AUTOMATIC, FLS_APPL_DATA) RegRbPtr)
{
    //uint32 baseAddr;
    Std_ReturnType retVal =  E_OK;
    return (retVal);
}
#endif /*#if (STD_ON == OSPI_REGISTER_READBACK_API) */

#if (STD_ON == OSPI_SAFETY_API)
/*
 * Design: MCAL-7401,MCAL-7388
 */
FUNC(Std_ReturnType, FLS_CODE)
    Fls_dataOverflowUnderflowIntrEnable(uint32 intrFlag)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;
    return (retVal);
}
/*
 * Design: MCAL-7401,MCAL-7388
 */
FUNC(Std_ReturnType, FLS_CODE)
    Fls_dataOverflowUnderflowIntrDisable(uint32 intrFlag)
{
    /* Disable  the interrupts */
    Std_ReturnType retVal = (Std_ReturnType) E_OK;
    return (retVal);
}


FUNC(Ospi_IrqStatusType, FLS_CODE)
    Fls_dataOverflowUnderflowIntrGetStatus(uint32 intFlags)
{
    Ospi_IrqStatusType  ospiIrqstatus    =  OSPI_NO_EVENT;
    return (ospiIrqstatus);
}

FUNC(Std_ReturnType, FLS_CODE)
    Fls_dataOverflowUnderflowIntrStatusClear(uint32 intrFlag)
{
  Std_ReturnType retVal = (Std_ReturnType) E_OK;
  return (retVal);

}
#endif//#if (STD_ON == OSPI_SAFETY_API)

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
