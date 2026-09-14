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
 * \file vHsmTimer.h
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

#include "Std_Types.h"
#include "string.h"

typedef void (*vHsmTimer_cbk_t)(void);

typedef struct
{
    sint32           TimeMS;
    vHsmTimer_cbk_t  pTimerCbkfn;
    volatile boolean TimerElaplsed;
    uint32 TimerReload;
}vHsmTimer_Obj_st;

typedef struct 
{
    uint8            TimerId;
    boolean          TimerRel;
    vHsmTimer_Obj_st TimerObj;
}vHsmTimer_handle_st;


void vHsmTimer_Init(void);
Std_ReturnType vHsmTimer_Start(vHsmTimer_handle_st * p_TimerHandle_st);
Std_ReturnType vHsmTimer_Stop(uint8 p_TimerId);
sint32 vHsmTimer_Remaining(uint8 p_TimerId);
uint64 vHsmTimer_TickCount(void);
void ClockP_timerTickIsr(uint32 a __attribute__((unused)));
uint32 vHsmTimerSystick_getCount(void);
uint32 vHsmTimerSystick_getReloadCount(void);
uint32 vHsmTimerSystick_isOverflowed(void);
void vHsmTimerSystick_stop(void);
void OsClock_Callback(void);


/*EOF*/
