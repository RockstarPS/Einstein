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
 *  \file     Gpt.c
 *
 *  \brief    This file contains GPT MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Gpt.h"
#include "SchM_Gpt.h"
#include "stdint.h"

#if (STD_ON == GPT_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#include <hw_include/hw_types.h>
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#include <hw_include/lldr_timer.h>

#include "Gpt_Priv.h"
#include "Gpt_Irq.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#if ((GPT_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (GPT_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (GPT_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Gpt: AUTOSAR Version Numbers of Gpt are different!!"
#endif

#if ((GPT_SW_MAJOR_VERSION != (9U)) || \
    (GPT_SW_MINOR_VERSION != (0U)) ||  \
    (GPT_SW_PATCH_VERSION != (1U)))
    #error "Gpt: Software Version Numbers are inconsistent!!"
#endif

typedef Gpt_ChannelHwObjType * Gpt_ChannelHwObjPtrType;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

const struct Gpt_ConfigType_s GptChannelConfigSet;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (STD_ON == GPT_VERSION_INFO_API)
FUNC(void, GPT_CODE) Gpt_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr)
{

}
#endif

FUNC(void, GPT_CODE)
    Gpt_Init( P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_CONST) CfgPtr)
{
    
}

#if (STD_ON == GPT_DEINIT_API)
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    
}
#endif

#if (STD_ON == GPT_TIME_ELAPSED_API)
FUNC(Gpt_ValueType, GPT_CODE)
    Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    return 0U;
}
#endif

#if (STD_ON == GPT_TIME_REMAINING_API)
FUNC(Gpt_ValueType, GPT_CODE)
    Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    return 0U;
}
#endif

FUNC(void, GPT_CODE)
                Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{

}

FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{

}

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
FUNC(void, GPT_CODE)
    Gpt_EnableNotification(Gpt_ChannelType Channel)
{

}
#endif

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
FUNC(void, GPT_CODE)
    Gpt_DisableNotification(Gpt_ChannelType Channel)
{

}
#endif

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{

}
#endif

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE)
    Gpt_DisableWakeup(Gpt_ChannelType Channel)
{

}
#endif

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE)
    Gpt_EnableWakeup(Gpt_ChannelType Channel)
{

}
#endif

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE)
    Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{

}
#endif

#if (GPT_PREDEF_TIMER_DISABLED == GPT_PREDEF_TIMER_TYPE)
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue (
     Gpt_PredefTimerType PredefTimer,uint32* TimeValuePtr)
{
    return E_OK;
}
#endif

Gpt_ChannelHwObjType *Gpt_getHwUnitObj(Gpt_ChannelType gptChannel,
                                       uint32         *chIdx)
{
    return NULL;
}

#if (STD_ON == GPT_REGISTER_READBACK_API)
FUNC(Std_ReturnType, GPT_CODE) Gpt_RegisterReadback(
    Gpt_ChannelType GptChannel,
    P2VAR(Gpt_RegisterReadbackType, AUTOMATIC, GPT_APPL_DATA) RegRbPtr)
{
    return E_OK;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_ISR_CODE
#include "Gpt_MemMap.h"

void Gpt_notifyIsr(uint32 chIdx)
{

}

void Gpt_wakeupIsr(uint32 chIdx)
{

}

#define GPT_STOP_SEC_ISR_CODE
#include "Gpt_MemMap.h"
