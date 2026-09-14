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
 *  \file     Mcu.c
 *
 *  \brief    This file contains MCU MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Mcu.h"
#include "Mcu_Priv.h"
#include "SchM_Mcu.h"
#include "stdint.h"
#include "string.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /*  (MCU_DEV_ERROR_DETECT == STD_ON) */

#include "Dem.h"
#include "Os.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((MCU_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (MCU_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (MCU_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Mcu: AUTOSAR Version Numbers of Mcu are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((MCU_SW_MAJOR_VERSION != (10U)) || \
    (MCU_SW_MINOR_VERSION != (0U)) ||  \
    (MCU_SW_PATCH_VERSION != (0U)))
    #error "Mcu: Software Version Numbers are inconsistent!!"
#endif

#ifndef MCU_E_CLOCK_FAILURE
#define MCU_E_CLOCK_FAILURE DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                         Function Declarations                              */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

const struct Mcu_ConfigType_s McuModuleConfiguration_0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (STD_ON == MCU_GET_VERSION_INFO_API)
FUNC(void, MCU_CODE) Mcu_GetVersionInfo(Std_VersionInfoType * versioninfo)
{

}
#endif

void Mcu_SetMode(Mcu_ModeType McuMode)
{

}

FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_PBCFG) CfgPtr)
{

}

#if (STD_ON == MCU_INIT_CLOCK_API)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    return E_OK;
}
#endif

#if(STD_OFF == MCU_NO_PLL)
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(void)
{
    return E_OK;
}
#endif

#if (STD_ON == MCU_INIT_RAM_API)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    return E_OK;
}
#endif

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void)
{
    return (Mcu_PllStatusType) MCU_PLL_STATUS_UNDEFINED;
}

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void)
{
    return 0U;
}

FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void)
{
    return MCU_RESET_UNDEFINED;
}

#if (STD_ON == MCU_PERFORM_RESET_API)
FUNC(void, MCU_CODE) Mcu_PerformReset(void)
{

}
#endif

#if (STD_ON == MCU_GET_RAM_STATE_API)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(void)
{
    return E_OK;
}
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 *  End of File: Mcu.c
 ******************************************************************************/
