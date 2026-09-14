/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           hmi_msgTest.c
**
** Description:
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define hmi_msgTest_C
#pragma optimization_level 0
/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "system.h"
#include "hmi_SIF.h"
#include "hmi_msgSequencer.cfg"
#include "hmi_msgTest.h"
#include "localSemaphores.h"
#include "hmi_msgDefinition.h"
#include "hmi_msgSequencer.h"
#include "hmi_msgStore.h"
#include "swtmr.h"
#include "hmi_msgTask.h"
#include "hmi_msgTypes.h"
/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/
#define HMI_TIMER_CLEAR                 (TIMER_CLEAR)
#define HMI_TIMER_EXPIRED               (TIMER_EXPIRED)
#define HMI_TIMER_RUNNING               (TIMER_RUNNING)
#define HMI_TIMER_NOT_RUNNING           (TIMER_CLEAR)



static UINT16 StubTimeElapsed;
static UINT16 StubTimeOut[SEQ_TOTAL_NO_OF_TIMERS];
static MSG_VIEWINFO_T fl_msg_data;	
static MSG_VIEWINFO_T fl_prev_msg_data;
static MSG_VIEWINFO_T fl_next_msg_data;
static MSG_VIEWINFO_T fl_first_msg_data;
/*--------------------------------------------------------------------------*/
/* TIMER SIMULATION.                                                        */
/*--------------------------------------------------------------------------*/
UINT8 hmi_stub_timer_check(UINT16 timer_id)
{
	BOOLEAN fl_timer_elapsed_BOOL = FALSE;
    UINT8 fl_return_U8 = HMI_TIMER_CLEAR;

    if(timer_id < SEQ_TOTAL_NO_OF_TIMERS)
    {        
        if((StubTimeOut[timer_id] != 0) && (StubTimeElapsed >= StubTimeOut[timer_id]))
        {
            fl_timer_elapsed_BOOL = TRUE;
        }
        
        if(FALSE != fl_timer_elapsed_BOOL)
        {
            fl_return_U8 = HMI_TIMER_EXPIRED;
        }
        else
        {
            if(StubTimeOut[timer_id] != 0)
            {
                fl_return_U8 = HMI_TIMER_RUNNING;
            }
            else
            {
                fl_return_U8 = HMI_TIMER_NOT_RUNNING;
            }
        }
    }
    return(fl_return_U8);
}

void hmi_stub_timer_start(UINT32 timeout, UINT16 timer_id)
{
	if(timer_id < SEQ_TOTAL_NO_OF_TIMERS)
    {
        StubTimeOut[timer_id] = timeout;        
    }
}

void hmi_stub_timer_stop(UINT16 timer_id)
{
    if(timer_id < SEQ_TOTAL_NO_OF_TIMERS)
    {
        StubTimeOut[timer_id] = 0;
    }
}

void hmi_stub_msg_get_current()
{	
	msg_StoreGetCurrent(&fl_msg_data,0);
	msg_StoreSelectPrevious(&fl_prev_msg_data,1);
	msg_StoreSelectNext(&fl_next_msg_data,0);
	msg_StoreSelectFirst(&fl_first_msg_data,0);
}

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 09/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/* end of file =============================================================*/