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
 *  \file     Wdg.c
 *
 *  \brief    This file contains implementation of the Internal Watchdog MCAL
 *            driver
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"
#include "stdint.h"
#include "Wdg.h"
#include "SchM_Wdg.h"
#include <hw_include/lldr_rti.h>
#if (STD_ON == WDG_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Dem.h"
#include "Wdg_Priv.h"
/* There are static inline functions in hw_types.h file. Map them as well */
#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"
#include <hw_include/hw_types.h>
#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((WDG_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
    (WDG_AR_RELEASE_MINOR_VERSION != (0x03U)) ||  \
    (WDG_AR_RELEASE_REVISION_VERSION != (0x01U)))
  #error "WDG: AUTOSAR Version Numbers of WDG are different"
#endif

/* Software Version Check */
#if ((WDG_SW_MAJOR_VERSION != (9U)) || (WDG_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Wdg.c and Wdg.h are inconsistent!"
#endif

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"
/** \brief WDG driver status */
/*
 * Design: MCAL-5622
 */

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

#if (STD_ON == WDG_GET_VERSION_INFO_API)
/*
 * Design: MCAL-5575
 */
FUNC(void, WDG_CODE)
    Wdg_GetVersionInfo(Std_VersionInfoType * versioninfo)
{

}
#endif  /* STD_ON == WDG_GET_VERSION_INFO_API */

/*
 * Design: MCAL-5542,MCAL-5621,MCAL-5586,MCAL-5550,MCAL-5618,MCAL-5579,MCAL-5572,MCAL-5544,MCAL-5558,MCAL-5563,MCAL-5548,MCAL-5625
 */
FUNC(void, WDG_CODE) Wdg_Init(
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) CfgPtr)
{

}

/*
 * Design: MCAL-5592,MCAL-5593,MCAL-5590,MCAL-5571,MCAL-5555
 */
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(
    uint16 timeout)
{

}

/*
 * Design: MCAL-5603,MCAL-5623,MCAL-5604,MCAL-5543,MCAL-5594,MCAL-5569,MCAL-5612,MCAL-5551,MCAL-5614,MCAL-5598
 */
FUNC(void, WDG_CODE) Wdg_Trigger(void)
{
    
}

/* Dummy Function, just to return E_OK if called from WDG IF layer */
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(
    WdgIf_ModeType Mode)
{
    return (E_OK);
}

/*
 * Design: MCAL-5553,MCAL-5619
 */
#if (STD_ON == WDG_REGISTER_READBACK_API)
FUNC(Std_ReturnType, WDG_CODE) Wdg_RegisterReadback
            (P2VAR(Wdg_RegisterReadbackType, AUTOMATIC,
                         WDG_APPL_DATA) regRbPtr)
{
    Std_ReturnType retVal = (Std_ReturnType) E_NOT_OK;
    return (retVal);
}
#endif /*STD_ON == WDG_REGISTER_READBACK_API*/

#if (STD_ON == WDG_DEV_ERROR_DETECT)
void Wdg_reportDetError(uint8 apiId, uint8 errorId)
{
    
}
#endif  /* #if (STD_ON == WDG_DEV_ERROR_DETECT) */

void Wdg_reportDemError(Dem_EventIdType     eventId,
                           Dem_EventStatusType eventStatus)
{

}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"
