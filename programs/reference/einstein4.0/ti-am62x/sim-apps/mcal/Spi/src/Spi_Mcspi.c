/*
*
* Copyright (c) 2024 Texas Instruments Incorporated
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
 *  \file     Spi_Mcspi.c
 *
 *  \brief    This file contains SPI MCAL driver functions for the McSPI
 *            peripheral
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "stdint.h"
#include "Spi_Cfg.h"
#include "Spi.h"
#include "Spi_Priv.h"
#include "Dem.h"
#include "Os.h"

/* There are static inline functions in hw_types.h file. Map them as well */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
#include <hw_include/lldr.h>
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#include <hw_include/lldr_mcspi.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

void Spi_mcspiInit(const Spi_HwUnitObjType *hwUnitObj)
{
}

void Spi_mcspiDeInit(const Spi_HwUnitObjType *hwUnitObj)
{
}

void Spi_mcspiConfigJob(const Spi_HwUnitObjType *hwUnitObj, Spi_JobObjType *jobObj)
{
}

void Spi_mcspiConfigCh(const Spi_HwUnitObjType *hwUnitObj, const Spi_JobObjType *jobObj, Spi_ChannelObjType *chObj)
{
}

void Spi_mcspiStart(const Spi_HwUnitObjType *hwUnitObj, const Spi_JobObjType *jobObj, uint32 isIntrMode)
{
}

void Spi_mcspiReStart(const Spi_HwUnitObjType *hwUnitObj, const Spi_JobObjType *jobObj)
{
}

Spi_JobResultType Spi_mcspiContinueTxRx(const Spi_HwUnitObjType *hwUnitObj, const Spi_JobObjType *jobObj, Spi_ChannelObjType *chObj)
{
    return SPI_JOB_OK;
}

Spi_JobResultType Spi_mcspiXferJob(const Spi_HwUnitObjType *hwUnitObj, Spi_JobObjType *jobObj)
{
    return SPI_JOB_OK;
}

void Spi_mcspiStop(const Spi_HwUnitObjType *hwUnitObj, const Spi_JobObjType *jobObj)
{
}

void Spi_mcspiClearAllIrqStatus(uint32 baseAddr)
{
}

void Spi_mcspiDisableAllIntr(uint32 baseAddr)
{
}

#if (STD_ON == SPI_REGISTER_READBACK_API)
void Spi_mcspiRegReadback(const Spi_HwUnitObjType *hwUnitObj, Spi_RegisterReadbackType *RegRbPtr)
{
    if (RegRbPtr != NULL_PTR)
    {
        RegRbPtr->mcspiHlRev = 0U;
        RegRbPtr->mcspiHlHwInfo = 0U;
        RegRbPtr->mcspiHlSysConfig = 0U;
        RegRbPtr->mcspiRev = 0U;
        RegRbPtr->mcspiSysStatus = 0U;
        RegRbPtr->mcspiSyst = 0U;
        RegRbPtr->mcspiModulctrl = 0U;
        RegRbPtr->mcspiSysConfig = 0U;
        RegRbPtr->mcspiCh0config = 0U;
        RegRbPtr->mcspiCh1config = 0U;
        RegRbPtr->mcspiCh2config = 0U;
        RegRbPtr->mcspiCh3config = 0U;
        RegRbPtr->mcspiIrqenable = 0U;
    }
}
#endif  /* #if (STD_ON == SPI_REGISTER_READBACK_API) */

uint32 Spi_mcspiGetCsIntrMask(uint32 csNum, Spi_TxRxMode txRxMode)
{
    return 0U;
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
