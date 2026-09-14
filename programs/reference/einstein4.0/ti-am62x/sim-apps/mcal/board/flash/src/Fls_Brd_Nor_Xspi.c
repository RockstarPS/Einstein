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
 *  \file     Fls_Brd_Nor_Xspi.c
 *
 *  \brief    This file contains FLS MCAL driver internal functions for Board Nor XSPI - STUBBED VERSION
 *
 */


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Fls_Brd_Nor.h"
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

Std_ReturnType Nor_xspiCmdWrite(SPI_Handle handle, uint8 *cmdBuf,
                                        uint32 cmdLen, uint32 dataLen)
{
    /* Stub implementation */
    (void)handle;
    (void)cmdBuf;
    (void)cmdLen;
    (void)dataLen;
    return E_OK;
}

Std_ReturnType Nor_xspiCmdRead(SPI_Handle handle, uint8 *cmdBuf,
                            uint32 cmdLen, uint8 *rxBuf, uint32 rxLen)
{
    /* Stub implementation */
    (void)handle;
    (void)cmdBuf;
    (void)cmdLen;
    (void)rxBuf;
    (void)rxLen;
    return E_OK;
}

Std_ReturnType Nor_xspiRegRead(SPI_Handle handle,
                                  uint32   regAddr,
                                  uint8    *data)
{
    /* Stub implementation */
    (void)handle;
    (void)regAddr;
    (void)data;
    return E_OK;
}

Std_ReturnType Nor_xspiRegWrite(SPI_Handle handle,
                                   uint32   regAddr,
                                   uint8    data)
{
    /* Stub implementation */
    (void)handle;
    (void)regAddr;
    (void)data;
    return E_OK;
}

Std_ReturnType Nor_xspiHybridSectCfg(SPI_Handle handle,
                                        uint8    enable,
                                        uint32   cfgFlag)
{
    /* Stub implementation */
    (void)handle;
    (void)enable;
    (void)cfgFlag;
    return E_OK;
}

Std_ReturnType Nor_xspiReadId(SPI_Handle handle)
{
    /* Stub implementation */
    (void)handle;
    return E_OK;
}

Std_ReturnType Nor_xspiEnableDDR(SPI_Handle handle)
{
    /* Stub implementation */
    (void)handle;
    return E_OK;
}

Std_ReturnType Nor_xspiEnableSDR(SPI_Handle handle)
{
    /* Stub implementation */
    (void)handle;
    return E_OK;
}

/*
 * Design : MCAL-15384
 * Fls_norAsyncErase Function calls this
 * removed polling in Nor_xspiWaitReady
 */
Fls_InternalStateType Nor_xspiAsyncWaitReady(SPI_Handle handle, uint32 timeOut)
{
    /* Stub implementation */
    (void)handle;
    (void)timeOut;
    return FLS_INTERNAL_JOB_DONE;
}

Std_ReturnType Nor_xspiWaitReady(SPI_Handle handle, uint32 timeOut)
{
    /* Stub implementation */
    (void)handle;
    (void)timeOut;
    return E_OK;
}

Std_ReturnType Nor_xspiSetDummyCycle(SPI_Handle handle, uint32 dummyCycle)
{
    /* Stub implementation */
    (void)handle;
    (void)dummyCycle;
    return E_OK;
}

Std_ReturnType Nor_xspiResetMemory(SPI_Handle handle)
{
    /* Stub implementation */
    (void)handle;
    return E_OK;
}

Std_ReturnType Nor_xspiSetOpcode(SPI_Handle handle)
{
    /* Stub implementation */
    (void)handle;
    return E_OK;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
