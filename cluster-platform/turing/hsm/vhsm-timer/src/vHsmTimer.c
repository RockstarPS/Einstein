/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmTimer.c
 *
 * \brief
 * Visteon HSM Timer Implementation for ARM M Cores using Systick
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

#include "vHsmTimer.h"
#include "trace.h"
#include "hwip.h"
#include "osal_halt.h"

#define MAX_TIMERS   (4u)
#define INVALID_TIMER (-1)
#define M4FCLOCKFREQUENCY (400000000u)
#define MICROSECONDPERTICK (1000u)
#define SYSTICK_INT (15u)

/* SysTick timer implementation for clock tick */
#define SYST_BASE   (0xE000E010u)
#define SYST_CSR    (volatile uint32_t *)((SYST_BASE) + 0x00u)
#define SYST_RVR    (volatile uint32_t *)((SYST_BASE) + 0x04u)
#define SYST_CVR    (volatile uint32_t *)((SYST_BASE) + 0x08u)



typedef struct 
{
    uint32           inputClkHz;
    uint32           periodInUsec;
    uint32           periodInNsec;
    uint32           oneshotMode;
    uint32           enableOverflowInt;
}vHsmTimer_Params_st;

static uint64 vHsmTimer_UsTicks;
static vHsmTimer_Obj_st vHsmTimer_Handle_stA[MAX_TIMERS] = {0};

static void vHsmTimerSystick_setup(vHsmTimer_Params_st *params);
static void vHsmTimerSystick_start(void);

FUNC(void,TIMER_CODE) vHsmTimer_Init(void)
{
    uint8 i = 0;
    uint32 err = 0;
    vHsmTimer_Params_st fl_TimerParams_st = {0};
    struct hwip_params hwi_params_Timer;
    for(i=0;i<MAX_TIMERS;i++)
    {
        vHsmTimer_Handle_stA[i].TimeMS = INVALID_TIMER;
    }
    fl_TimerParams_st.inputClkHz = M4FCLOCKFREQUENCY;
    fl_TimerParams_st.enableOverflowInt = 1u;
    fl_TimerParams_st.oneshotMode = 0u;
    fl_TimerParams_st.periodInNsec = 0u;
    fl_TimerParams_st.periodInUsec = MICROSECONDPERTICK;
    hwi_params_Timer.priority = 3u;
    vHsmTimerSystick_setup(&fl_TimerParams_st);
    mask_interrupts();
    err = hwip_create(0,SYSTICK_INT,ClockP_timerTickIsr,&hwi_params_Timer);
    if (err != 0) {
        TRACE_info(" Systick Int req fails \n");
        osal_system_halt(err);
    }
    err = hwip_enable_interrupt(SYSTICK_INT, NULL);
    if (err != 0) {
        TRACE_info(" Systick Int  req fails \n");
        osal_system_halt(err);
    }
    unmask_interrupts();
    /* start the tick timer */
    vHsmTimerSystick_start();
    TRACE_info("\r\n Timer Init Done \n");
}

FUNC(Std_ReturnType,TIMER_CODE) vHsmTimer_Start(vHsmTimer_handle_st * p_TimerHandle_st)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 vHsmTimerId_U8 = 0u;
    if((NULL != p_TimerHandle_st) && (MAX_TIMERS > p_TimerHandle_st->TimerId) && (p_TimerHandle_st->TimerObj.TimeMS > 0))
    {
        vHsmTimerId_U8 = p_TimerHandle_st->TimerId;
        if(vHsmTimer_Handle_stA[vHsmTimerId_U8].TimeMS == INVALID_TIMER)
        {
            vHsmTimer_Handle_stA[vHsmTimerId_U8].TimeMS = p_TimerHandle_st->TimerObj.TimeMS;
            vHsmTimer_Handle_stA[vHsmTimerId_U8].TimerElaplsed = FALSE;
            vHsmTimer_Handle_stA[vHsmTimerId_U8].pTimerCbkfn = p_TimerHandle_st->TimerObj.pTimerCbkfn;
            if(p_TimerHandle_st->TimerRel == TRUE)
            {
                vHsmTimer_Handle_stA[vHsmTimerId_U8].TimerReload = p_TimerHandle_st->TimerObj.TimeMS;;
            }
            else
            {
                vHsmTimer_Handle_stA[vHsmTimerId_U8].TimerReload = 0u;
            }
            l_RetVal_E = E_OK;
        }
    }
    return l_RetVal_E;
}

FUNC(Std_ReturnType,TIMER_CODE) vHsmTimer_Stop(uint8 p_TimerId)
{
    Std_ReturnType l_RetVal_E = E_OK;
    vHsmTimer_Handle_stA[p_TimerId].TimeMS = INVALID_TIMER;
    vHsmTimer_Handle_stA[p_TimerId].pTimerCbkfn = NULL;
    vHsmTimer_Handle_stA[p_TimerId].TimerElaplsed = FALSE;
    vHsmTimer_Handle_stA[p_TimerId].TimerReload = 0u;
    return l_RetVal_E;
}

FUNC(sint32,TIMER_CODE) vHsmTimer_Remaining(uint8 p_TimerId)
{
    if(p_TimerId < MAX_TIMERS)
    {
        return vHsmTimer_Handle_stA[p_TimerId].TimeMS;
    }
    else
    {
        return INVALID_TIMER;
    }
}

FUNC(uint64,TIMER_CODE) vHsmTimer_TickCount(void)
{
    return vHsmTimer_UsTicks;
}



/* Systick Configuration for M core*/

FUNC(void,TIMER_CODE) ClockP_timerTickIsr(uint32 a __attribute__((unused)))
{
    uint8 i = 0;
    /* Hsm Main scheduler callback --  High priority */
    OsClock_Callback();
    /* For Timers */
    vHsmTimer_UsTicks++;
    for(i =0;i<MAX_TIMERS;i++)
    {
        if(vHsmTimer_Handle_stA[i].TimeMS != INVALID_TIMER)
        {
            vHsmTimer_Handle_stA[i].TimeMS--;
            if(vHsmTimer_Handle_stA[i].TimeMS == 0)
            {
                vHsmTimer_Handle_stA[i].pTimerCbkfn();
                if(vHsmTimer_Handle_stA->TimerReload > 0)
                {
                    vHsmTimer_Handle_stA[i].TimeMS = vHsmTimer_Handle_stA[i].TimerReload;
                }
                else
                {
                    vHsmTimer_Handle_stA[i].TimeMS = INVALID_TIMER;
                }
            }
            else
            {
                /* Do Nothing*/
            }
        }
        else
        {
            /* Do nothing*/
        }
    }
}

static FUNC(void,TIMER_CODE) vHsmTimerSystick_setup(vHsmTimer_Params_st *params)
{
    volatile uint32 *addr;
    uint32 ctrlVal;
    uint32 countVal , reloadVal;
    uint64 timeInNsec, timerCycles;
    /* stop timer and clear pending interrupts */
    vHsmTimerSystick_stop();
    timeInNsec = (uint64_t)params->periodInNsec;
    if(timeInNsec == 0U)
    {
        timeInNsec = params->periodInUsec*1000U;
    }
    timerCycles =  ( (uint64)params->inputClkHz * timeInNsec ) / 1000000000U;
    /* calculate count and reload value register value */
    countVal = (uint32)timerCycles;
    /* keep reload value as 0, later if is auto-reload is enabled, it will be set a value > 0 */
    reloadVal = 0;
    /* calculate control register value, keep timer disabled */
    ctrlVal = 0;
    /* select clock source as CPU clock */
    ctrlVal |= (1u << 2u);
    /* enable/disable interrupts */
    if((boolean)params->enableOverflowInt == true)
    {
        /* enable interrupt */
        ctrlVal |= (1u << 1u);
    }
    if(params->oneshotMode==(uint32)0U)
    {
        /* autoreload timer */
        reloadVal = countVal;
    }
    /* set timer control value */
    addr = SYST_CSR;
    *addr = ctrlVal;
    /* set reload value */
    addr = SYST_RVR;
    *addr = reloadVal;
    /* set count value */
    addr = SYST_CVR;
    *addr = countVal;
}

/* base address not used since, address is fixed for SysTick in M4F */
static FUNC(void,TIMER_CODE) vHsmTimerSystick_start(void)
{
    volatile uint32 *addr = SYST_CSR;
    /* start timer */
    *addr |= (0x1U << 0);
}

/* base address not used since, address is fixed for SysTick in M4F */
FUNC(void,TIMER_CODE) vHsmTimerSystick_stop(void)
{
    volatile uint32 *addr = SYST_CSR;
    /* stop timer */
    *addr &= ~(0x1U << 0);
}

/* base address not used since, address is fixed for SysTick in M4F */
FUNC(uint32,TIMER_CODE) vHsmTimerSystick_getCount(void)
{
    /* return 0xFFFFFFFF - value, since ClockP assumes in this format to calculate current time */
    return (0xFFFFFFFFu - CSL_REG32_RD(SYST_CVR));

}

/* base address not used since, address is fixed for SysTick in M4F */
FUNC(uint32,TIMER_CODE) vHsmTimerSystick_getReloadCount(void)
{
    /* return 0xFFFFFFFF - value, since ClockP assumes in this format to calculate current time */
    return (0xFFFFFFFFu - CSL_REG32_RD(SYST_RVR));
}

/* base address not used since, address is fixed for SysTick in M4F */
FUNC(uint32,TIMER_CODE) vHsmTimerSystick_isOverflowed(void)
{
    volatile uint32 *addr = SYST_CSR;
    return ((*addr >> 16) & 0x1U);
}



/*EOF*/
