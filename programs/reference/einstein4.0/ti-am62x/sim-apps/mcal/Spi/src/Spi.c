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
 *  \file     Spi.c
 *
 *  \brief    This file contains SPI MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "string.h"
#include "Spi_Cfg.h"
#include "Spi.h"
#include "Spi_Dbg.h"
#include "Spi_Priv.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (SPI_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (SPI_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Spi: AUTOSAR Version Numbers of Spi are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((SPI_SW_MAJOR_VERSION != (9U)) || \
    (SPI_SW_MINOR_VERSION != (0U)) ||  \
    (SPI_SW_PATCH_VERSION != (1U)))
    #error "Spi: Software Version Numbers are inconsistent!!"
#endif

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

const struct Spi_ConfigType_s SpiDriver;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) CfgPtr)
{

}

FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    return (Std_ReturnType)E_OK;
}

FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    return SPI_IDLE;
}

FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(Spi_JobType Job)
{
    return SPI_JOB_OK;
}

FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    return SPI_SEQ_OK;
}

#if (STD_ON == SPI_VERSION_INFO_API)
FUNC(void, SPI_CODE) Spi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo)
{

}
#endif

#if (STD_ON == SPI_HW_STATUS_API)
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    return SPI_IDLE;
}
#endif

#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(Spi_ChannelType Channel, P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{
    return (Std_ReturnType)E_OK;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(Spi_ChannelType Channel, P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer)
{
    return (Std_ReturnType)E_OK;
}
#endif

#if ((SPI_CHANNELBUFFERS == SPI_EB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(Spi_ChannelType Channel, P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr, P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr, Spi_NumberOfDataType Length)
{
    return (Std_ReturnType)E_OK;
}
#endif

#if ((SPI_SCALEABILITY == SPI_LEVEL_1) || (SPI_SCALEABILITY == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    return (Std_ReturnType)E_OK;
}
#endif

#if (STD_ON == SPI_CANCEL_API)
FUNC(void, SPI_CODE) Spi_Cancel(Spi_SequenceType Sequence)
{

}
#endif

#if ((SPI_SCALEABILITY == SPI_LEVEL_0) || (SPI_SCALEABILITY == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    return (Std_ReturnType)E_OK;
}
#endif

#if (SPI_SCALEABILITY == SPI_LEVEL_2)
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    return (Std_ReturnType)E_OK;
}
#endif

FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void)
{
}

#if (STD_ON == SPI_REGISTER_READBACK_API)
FUNC(Std_ReturnType, SPI_CODE) Spi_RegisterReadback(Spi_HWUnitType HWUnit, P2VAR(Spi_RegisterReadbackType, AUTOMATIC, SPI_APPL_DATA) RegRbPtr)
{
    return (Std_ReturnType)E_OK;
}
#endif

#if (STD_ON == SPI_SAFETY_API)
FUNC(Std_ReturnType, SPI_CODE) Spi_dataOverflowUnderflowIntrEnable(Spi_HWUnitType HWUnit, uint32 intFlags)
{
    return (Std_ReturnType)E_OK;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_dataOverflowUnderflowIntrDisable(Spi_HWUnitType HWUnit, uint32 intFlags)
{
    return (Std_ReturnType)E_OK;
}

FUNC(Mcspi_IrqStatusType, SPI_CODE) Spi_dataOverflowUnderflowIntrGetStatus(Spi_HWUnitType HWUnit, uint32 intFlags)
{
    return SPI_NO_EVENT;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_dataOverflowUnderflowIntrStatusClear(Spi_HWUnitType HWUnit, uint32 intFlags)
{
    return (Std_ReturnType)E_OK;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
