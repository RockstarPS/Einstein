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
 *  \file  Gpt_Gptimer.c
 *
 *  \brief This file contains GPT MCAL driver functions for the General purpose
 *         timers.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <Gpt_Cfg.h>
#include "Gpt.h"
#include "Gpt_Priv.h"

#include "stdint.h"

/* There are static inline functions in hw_types.h file. Map them as well */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#include <hw_include/hw_types.h>
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#include "Dem.h"
#include "Os.h"

/* CSL from PDK */
#include <hw_include/soc1.h>
#include <hw_include/lldr_timer.h>


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*
 * Values that can be passed to TIMERModeConfigure as timerMode.
 */
/* Value used to enable the timer in one-shot and compare mode */
#define GPTIMER_ONESHOT_CMP_ENABLE          (TIMER_TCLR_CE_MASK)

/* Value used to enable the timer only in one-shot mode */
#define GPTIMER_ONESHOT_NOCMP_ENABLE        (0x0000000U)

/* Value used to enable the timer in auto-reload and compare mode */
#define GPTIMER_AUTORLD_CMP_ENABLE          (TIMER_TCLR_AR_MASK | \
                                             TIMER_TCLR_CE_MASK)

/* Value used to enable the timer only in auto-reload mode */
#define GPTIMER_AUTORLD_NOCMP_ENABLE        (TIMER_TCLR_AR_MASK)

/******************************************************************************/
/*
 * Values that can be passed to GPTIMERGPOConfigure as gpoCfg.
 */
/* Value used to drive 0 on PORGPOCFG pin */
#define GPTIMER_GPO_CFG_0         (TIMER_TCLR_GPO_CFG_GPO_CFG_0)

/* Value used to drive 1 on PORGPOCFG pin */
#define GPTIMER_GPO_CFG_1         (TIMER_TCLR_GPO_CFG_GPO_CFG_1 << \
                                   TIMER_TCLR_GPO_CFG_SHIFT)

/******************************************************************************/
/*
 * Values that can be passed to GPTIMERIntStatusClear/GPTIMERIntRawStatusSet/
 * as intFlags. Also these values can be used while checking the status got from
 * GPTIMERIntRawStatusGet/GPTIMERIntStatusGet.
 * Any combination is also followed.
 * Example- (GPTIMER_INT_TCAR_IT_FLAG | GPTIMER_INT_OVF_IT_FLAG)
 */
/* Value used for capture event of Timer */
#define GPTIMER_INT_TCAR_IT_FLAG             ( \
        TIMER_IRQSTATUS_RAW_TCAR_IT_FLAG_MASK)

/* Value used for overflow event of Timer */
#define GPTIMER_INT_OVF_IT_FLAG              ( \
        TIMER_IRQSTATUS_RAW_OVF_IT_FLAG_MASK)

/* Value used for Match event of Timer */
#define GPTIMER_INT_MAT_IT_FLAG              ( \
        TIMER_IRQSTATUS_RAW_MAT_IT_FLAG_MASK)

/******************************************************************************/
/*
 * Values that can be passed to GPTIMERResetConfigure as rstOption.
 */
/* Value used to enable software reset for Timer */
#define GPTIMER_SFT_RESET_ENABLE             (TIMER_TSICR_SFT_MASK)

/* Value used to disable software reset for Timer */
#define GPTIMER_SFT_RESET_DISABLE            (TIMER_TSICR_SFT_SFT_0)

/******************************************************************************/
/*
 * Values that can be used while checking the status received from
 * GPTIMERIsResetDone.
 */
/* Value used to check whether reset is done */
#define GPTIMER_IS_RESET_DONE                ( \
        TIMER_TIOCP_CFG_SOFTRESET_SOFTRESET_VALUE_0)

/* Value used to check whether reset is ongoing */
#define GPTIMER_IS_RESET_ONGOING             ( \
        TIMER_TIOCP_CFG_SOFTRESET_SOFTRESET_VALUE_1)

/******************************************************************************/
/*
 * Values that can be passed to TIMERPostedModeConfig as postMode.
 */
/* Value used to enable the posted mode of operation */
#define GPTIMER_POSTED                       (TIMER_TSICR_POSTED_MASK)

/* Value used to disable the posted mode of operation */
/* Non-posted mode is where CPU is stalled untill write completion response
 * to indicate success or failure of the transaction */
#define GPTIMER_NONPOSTED                    (TIMER_TSICR_POSTED_POSTED_VALUE_0)

/******************************************************************************/

/******************************************************************************/
/*
 * Values that can be passed to GPTIMERIdleModeConfigure as idleModeOption.
 */
/* Value used to set Timer in Force-idle mode*/
#define GPTIMER_FORCE_IDLE            (TIMER_TIOCP_CFG_IDLEMODE_IDLE_MODE_0X0)

/* Value used to set Timer in No-idle mode*/
#define GPTIMER_NO_IDLE               (TIMER_TIOCP_CFG_IDLEMODE_IDLE_MODE_0X1)

/* Value used to set Timer in Smart-idle mode*/
#define GPTIMER_SMART_IDLE            (TIMER_TIOCP_CFG_IDLEMODE_IDLE_MODE_0X2)

/* Value used to set Timer in Smart-idle wake-up-capable mode*/
#define GPTIMER_SMART_IDLE_WAKEUP     (TIMER_TIOCP_CFG_IDLEMODE_IDLE_MODE_0X3)

/******************************************************************************/
/*
 * Values that can be passed to GPTIMEREmuModeConfigure as emuModeOption.
 */
/* Value used to freeze Timer in emulation mode*/
#define GPTIMER_FROZEN            (TIMER_TIOCP_CFG_EMUFREE_TIMER_FROZEN)

/* Value used to free run Timer in emulation mode  */
#define GPTIMER_FREE              (TIMER_TIOCP_CFG_EMUFREE_TIMER_FREE)

/**
 * \brief  GP Timer interrupt flags.
 */
#define GPTIMER_INT_TCAR_EN_FLAG    (TIMER_IRQENABLE_SET_TCAR_EN_FLAG_MASK)
/**< Timer capture event interrupt mask */
#define GPTIMER_INT_OVF_EN_FLAG     (TIMER_IRQENABLE_SET_OVF_EN_FLAG_MASK)
/**< Timer overflow event interrupt mask */
#define GPTIMER_INT_MAT_EN_FLAG     (TIMER_IRQENABLE_SET_MAT_EN_FLAG_MASK)
/**< Timer Match event interrupt mask */
#define GPTIMER_INT_ALL_EN_FLAG     (TIMER_IRQENABLE_SET_TCAR_EN_FLAG_MASK | \
                                     TIMER_IRQENABLE_SET_OVF_EN_FLAG_MASK |  \
                                     TIMER_IRQENABLE_SET_MAT_EN_FLAG_MASK)
/**< Macro to control all the above interrupt status */

/**
 * \brief  GP Timer wakeup flags.
 */
#define GPTIMER_WAKE_TCAR_FLAG      (TIMER_IRQWAKEEN_TCAR_WUP_ENA_MASK)
/**< Timer capture event wakeup mask */
#define GPTIMER_WAKE_OVF_FLAG       (TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK)
/**< Timer overflow event wakeup mask */
#define GPTIMER_WAKE_MAT_FLAG       (TIMER_IRQWAKEEN_MAT_WUP_ENA_MASK)
/**< Timer Match event wakeup mask */
#define GPTIMER_WAKE_ALL_EN_FLAG    (TIMER_IRQWAKEEN_TCAR_WUP_ENA_MASK | \
                                     TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK |  \
                                     TIMER_IRQWAKEEN_MAT_WUP_ENA_MASK)
/**< Macro to control all the above wakeup status */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                  Internal Function Definitions                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define GPT_START_SEC_CODE

#include "Gpt_MemMap.h"

/**
 * \brief   This API will enable/disable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/
void
    Gpt_gptimerStart(const Gpt_ChannelHwObjType *pHwUnitObj, uint32  countValue,
                     uint32 enableInt)
{
}

/**
 * \brief   This API will enable/disable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/
void Gpt_gptimerStop(
                                        const Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   This API will enable/disable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/
void  Gpt_gptimerEnableNotify(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   This API will enable/disable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/
void Gpt_gptimerDisableNotify(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
}


/**
 * \brief   This API will enable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/

 /*
  * Design : MCAL-6307
  */
void Gpt_gptimerEnableWakeup(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   This API will enable GPTIMER wake up events.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 **/

/*
 * Design : MCAL-6293
 */
void Gpt_gptimerDisableWakeup(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   This API will initialize the timer.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 * \param   pHwUnitObj     Pointer to Timer HW object to store initialized
 *                          value.
 *
 * \return  None.
 **/
void Gpt_gptimerInit(uint32   gptChannel,
                      Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   This API will deinitialize the timer.
 *
 * \param   pHwUnitObj     Pointer to Timer HW object.
 *
 * \return  None.
 **/
void Gpt_gptimerDeInit(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
}

/**
 * \brief   Get/Read the counter value from the counter register.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  This API returns the count value present in the Timer Counter
 *          register.
 *
 * \note:   Value can be read from the counter register when the counter is
 *          stopped or when it is running.
 **/
uint32 Gpt_gptimerCounterGet(uint32 baseAddr)
{
    return 0U;
}

/**
 * \brief   Get the match register contents.
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  This API returns the match register contents.
 *
 **/
uint32 Gpt_gptimerReloadGet(uint32 baseAddr)
{
    return 0U;
}

#if (STD_ON == GPT_DEV_ERROR_DETECT)
void Gpt_reportDetError(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, apiId, errorId);
    return;
}

#endif  /* #if (STD_ON == GPT_DEV_ERROR_DETECT) */

void Gpt_reportRuntimeError(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, apiId, errorId);
    return;
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_ISR_CODE
#include "Gpt_MemMap.h"

void Gpt_gptimerIntrClear(Gpt_ChannelType gptChannel)
{
}

void Gpt_gptimerIntDisableCh(Gpt_ChannelType gptChannel)
{
}

#define GPT_STOP_SEC_ISR_CODE
#include "Gpt_MemMap.h"
/* eof */
