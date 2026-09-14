/*
 *  Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file  timer.c
 *
 *  \brief Timer APIs.
 *
 *   This file contains the device abstraction layer APIs for Timer.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include <hw_include/lld.h>
#include <hw_include/lldr_timer.h>
#include <hw_include/lld_types.h>
#include <Pwm/epwm_hw/V0_1/timer.h>
#include <hw_include/hw_types.h>

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

/**
 * \brief   This function will check for write POSTED status
 *
 * \param   reg          Register whose status has to be checked
 *
 *    'reg' can take the following values \n
 *    TIMER_WRITE_POST_TCLR - Timer Control register \n
 *    TIMER_WRITE_POST_TCRR - Timer Counter register \n
 *    TIMER_WRITE_POST_TLDR - Timer Load register \n
 *    TIMER_WRITE_POST_TTGR - Timer Trigger register \n
 *    TIMER_WRITE_POST_TMAR - Timer Match register \n
 *
 * \param   baseAddr       Base Address of the Timer Module Register.
 *
 * \return  None.
 *
 **/
static inline sint32 TimerWaitForWrite(uint32 reg, uint32 baseAddr);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */
sint32 Pwm_TIMEREnable(uint32 baseAddr)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);
        if (retVal == LLD_PASS)
        {
            /* Start the timer */
            HW_WR_FIELD32(
                baseAddr + TIMER_TCLR,
                TIMER_TCLR_ST,
                TIMER_TCLR_ST_ST_VALUE_1);
        }
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERDisable(uint32 baseAddr)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);
        if (retVal == LLD_PASS)
        {
            /* Stop the timer */
            HW_WR_FIELD32(
                baseAddr + TIMER_TCLR,
                TIMER_TCLR_ST,
                TIMER_TCLR_ST_ST_VALUE_0);
        }
    }
    return(retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERModeConfigure(uint32 baseAddr, uint32 timerMode)
{
    uint32 regVal;
    sint32  retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        if ( (timerMode == TIMER_ONESHOT_CMP_ENABLE)    ||
             (timerMode == (uint32) (TIMER_ONESHOT_NOCMP_ENABLE))  ||
             (timerMode == TIMER_AUTORLD_CMP_ENABLE)    ||
             (timerMode == TIMER_AUTORLD_NOCMP_ENABLE) )
        {
            /* Wait for previous write to complete */
            retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

            if (retVal == LLD_PASS)
            {
                /* Clear the AR and CE field of TCLR */
                HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                              TIMER_TCLR_AR,
                              TIMER_TCLR_AR_AR_VALUE_0);

                HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                              TIMER_TCLR_CE,
                              TIMER_TCLR_CE_CE_VALUE_0);

                /* Wait for previous write to complete */
                retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

                if (retVal == LLD_PASS)
                {
                    /* Set the timer mode in TCLR register */
                    regVal = HW_RD_REG32(baseAddr + TIMER_TCLR);

                    regVal |= (timerMode & (TIMER_TCLR_AR_MASK | TIMER_TCLR_CE_MASK));

                    HW_WR_REG32(baseAddr + TIMER_TCLR, regVal);
                }
            }
        }
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERPreScalerClkDisable(uint32 baseAddr)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

        if (retVal == LLD_PASS)
        {
            /* Disable Pre-scaler clock */
            HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                          TIMER_TCLR_PRE,
                          TIMER_TCLR_PRE_PRE_VALUE_0);
        }
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERCounterSet(uint32 baseAddr, uint32 counter)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TCRR, baseAddr);

        if (retVal == LLD_PASS)
        {
            /* Set the counter value */
            HW_WR_REG32(baseAddr + TIMER_TCRR, counter);
        }
    }
    return (retVal);
}

/* This is kept for backwards compatibility
 * is replaced by new TIMERCounterGet2 API */
uint32 Pwm_TIMERCounterGet(uint32 baseAddr)
{
    /* Wait for previous write to complete */
    (void)TimerWaitForWrite(TIMER_WRITE_POST_TCRR, baseAddr);

    /* Read the counter value from TCRR */
    return (HW_RD_REG32(baseAddr + TIMER_TCRR));
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERReloadSet(uint32 baseAddr, uint32 reload)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TLDR, baseAddr);

        if (retVal == LLD_PASS)
        {
            /* Load the register with the re-load value */
            HW_WR_REG32(baseAddr + TIMER_TLDR, reload);
        }
    }
    return (retVal);
}


/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERCompareSet(uint32 baseAddr, uint32 compareVal)
{
    sint32 retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        /* Wait for previous write to complete */
        retVal = TimerWaitForWrite(TIMER_WRITE_POST_TMAR, baseAddr);

        if (retVal == LLD_PASS)
        {
            /* Write the compare value to TMAR */
            HW_WR_REG32(baseAddr + TIMER_TMAR, compareVal);
        }
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERIntStatusClear(uint32 baseAddr, uint32 intFlags)
{
    sint32 retVal = LLD_EBADARGS;
    uint32 flags = intFlags & (TIMER_IRQSTATUS_TCAR_IT_FLAG_MASK |
                                 TIMER_IRQSTATUS_OVF_IT_FLAG_MASK |
                                 TIMER_IRQSTATUS_MAT_IT_FLAG_MASK);

    if ( (baseAddr != (uint32)(0u)) &&
         (flags    != (uint32)(0u)))
    {
        /* Clear the interrupt status from IRQSTATUS register */
        HW_WR_REG32(baseAddr + TIMER_IRQSTATUS, flags);
        retVal = LLD_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERIntEnable(uint32 baseAddr, uint32 intFlags)
{
    sint32 retVal = LLD_EBADARGS;
    uint32 flags = intFlags & (TIMER_INT_TCAR_EN_FLAG |
                                 TIMER_INT_OVF_EN_FLAG |
                                 TIMER_INT_MAT_EN_FLAG);

    if ( (baseAddr != (uint32)(0u)) &&
         (flags    != (uint32)(0u)))
    {
        /* Enable the Timer interrupts represented by intFlags */
        HW_WR_REG32(baseAddr + TIMER_IRQENABLE_SET, flags);
        retVal = LLD_PASS;
    }
    return(retVal);
}
/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERIntDisable(uint32 baseAddr, uint32 intFlags)
{
    sint32 retVal = LLD_EBADARGS;
    uint32 flags = intFlags & (TIMER_INT_TCAR_EN_FLAG |
                                 TIMER_INT_OVF_EN_FLAG |
                                 TIMER_INT_MAT_EN_FLAG);

    if ( (baseAddr != (uint32)(0u)) &&
         (flags    != (uint32)(0u)))
    {
        /* Disable the Timer interrupts represented by intFlags */
        HW_WR_REG32(baseAddr + TIMER_IRQENABLE_CLR, flags);
        retVal = LLD_PASS;
    }
    return (retVal);
}

/* This is kept for backwards compatibility
 * is replaced by new Pwm_TIMERIntEnableGet2 API */

uint32 Pwm_TIMERIntEnableGet(uint32 baseAddr)
{
    /* Return the status of register IRQENABLE_SET */
    return (HW_RD_REG32(baseAddr + TIMER_IRQENABLE_SET));
}


/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */
sint32 Pwm_TIMERResetConfigure(uint32 baseAddr, uint32 rstOption)
{
    sint32     retVal = LLD_EBADARGS;

    if (baseAddr != (uint32)(0u))
    {
        if ( (rstOption == TIMER_SFT_RESET_ENABLE) ||
             (rstOption == TIMER_SFT_RESET_DISABLE) )
        {
            /* Write the option sent by user to SFT field of TSICR */
            HW_WR_FIELD32(baseAddr + TIMER_TSICR,
                          TIMER_TSICR_SFT,
                          rstOption >> TIMER_TSICR_SFT_SHIFT);
            retVal = LLD_PASS;
        }
    }
    return(retVal);
}


/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMERPostedModeConfig(uint32 baseAddr, uint32 postMode)
{
    sint32     retVal = LLD_EBADARGS;

    if ((baseAddr != (uint32)(0u)))
    {
        if ( (postMode == TIMER_POSTED) ||
             (postMode == TIMER_NONPOSTED) )
        {
        /* Write to the POSTED field of TSICR */
        HW_WR_FIELD32(baseAddr + TIMER_TSICR,
                      TIMER_TSICR_POSTED,
                      postMode >> TIMER_TSICR_POSTED_SHIFT);
        retVal = LLD_PASS;
        }
    }
    return (retVal);
}



/* This is kept for backwards compatibility
 * is replaced by new Pwm_TIMERWritePostedStatusGet2 API */

uint32 Pwm_TIMERWritePostedStatusGet(uint32 baseAddr)
{
    /* Return the status of TWPS register */
    return (HW_RD_REG32(baseAddr + TIMER_TWPS));
}


/**
 * Requirement: REQ_TAG(PDK-6041)
 * Design: did_csl_dmtimer
 */

sint32 Pwm_TIMEREmuModeConfigure(uint32 baseAddr, uint32 emuModeOption)
{
    sint32     retVal = LLD_EBADARGS;

    if ((baseAddr != (uint32)(0u)))
    {
        /* Write to the EMUFREE field of TIOCP_CFG */
        HW_WR_FIELD32(baseAddr + TIMER_TIOCP_CFG,
                      TIMER_TIOCP_CFG_EMUFREE,
                      emuModeOption);
        retVal = LLD_PASS;
    }
    return (retVal);
}

/* ========================================================================== */
/*                      Internal Function Definitions                         */
/* ========================================================================== */
static inline sint32 TimerWaitForWrite(uint32 reg, uint32 baseAddr)
{
    sint32          retVal = LLD_PASS;
    volatile uint32 exit_count = (uint32) 0U;
    uint32 step_size           = (uint32) 1U;

    if (0U != HW_RD_FIELD32(baseAddr + TIMER_TSICR, TIMER_TSICR_POSTED))
    {
        while ((uint32) 0U != (reg & Pwm_TIMERWritePostedStatusGet(baseAddr)))
        {
             exit_count += step_size;
            /* Do nothing - Busy wait,
             * quit the loop if posted transations are not complete
             * by one full cycle of counting
             * This check and break prevents getting stuck in the loop
             */
             if (exit_count == 0U)
             {
                retVal = LLD_ETIMEOUT;
                break;
             }
        }
    }
    return (retVal);
}
/********************************* End of file ******************************/