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

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "hmi_msgTest.h"
#include "localSemaphores.h"
#include "hmi_msgDefinition.h"


/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/
				 
static UINT32 messageIndex;

static LOCAL_SEMAPHORES(MessageFlags, MSG_NUM_MESSAGES);
static BOOLEAN tst_Retrigger;

static struct
{
    UINT16 Actual;
    UINT16 Expected;
    UINT16 CategoryMask;
    UINT8 Notification;
    UINT8 test_SeqTimer;
    UINT16 msgEvent;
    UINT32 CategoryQuery;
    eMessageIdentity ShowMessage;
} tstData;


void test_Mark(UINT32 Value);
void test_Notification(UINT8 msgSource);

#if defined   ENABLE_PRIVATE_TIMERS

  static TIMER  seq_DisplayTimer;
  static TIMER  seq_HoldTimer;
  static TIMER  seq_CycleTimer;
  static TIMER  seq_DispIndTimer;
  #endif



#ifndef ENABLE_PRIVATE_TIMERS
#define SEQ_DISPLAY_TIMER_ID    50
#define SEQ_HOLD_TIMER_ID       100
#define SEQ_CYCLE_TIMER_ID      150
#define SEQ_DISP_INDICATION_TIMER_ID  200
#define SEQ_1SEC_TIMER_ID      250
#define HMI_MSG_1SEC_TIME      600
#endif

  
 
  #define seq_DisplayTimer (SEQ_DISPLAY_TIMER_ID)
  #define seq_HoldTimer    (SEQ_HOLD_TIMER_ID)
  #define seq_CycleTimer   (SEQ_CYCLE_TIMER_ID)
  #define seq_DispIndTimer      (SEQ_DISP_INDICATION_TIMER_ID)
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
  #define seq_1secTimer  (SEQ_1SEC_TIMER_ID)
#endif


  unsigned char Start,Clear,Check;

UINT16 test_GetWarningState ( UINT16 *msgData, UINT16 Qualifier )
//U08SIF_STANDARD_INTERFACE(test_GetWarningState)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message detection for the tst suite.
**
**  Parameters:     *Data:      Pointer to where the current message state will
**                              be stored.
**                  *Qualifier: Pointer to the message qualifying data.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 14/Apr/2010
**==========================================================================*/
{
    BOOLEAN thisState = (BOOLEAN)GET_SEMAPHORE(MessageFlags, messageIndex);
    UINT16 testCondition;

		Qualifier = Qualifier;
    if (FALSE == thisState)
    {
        testCondition = MSG_CONDITION_OFF;
    }
    else
    {
        if (FALSE == tst_Retrigger)
        {
            testCondition = MSG_CONDITION_ACTIVE;
        }
        else
        {
            testCondition = MSG_CONDITION_FORCED;
        }
    }

    if (SIF_ISVALID_DATA())
    {
        SIF_SET_DATA(testCondition);
    }
    return 0;
}

UINT16 test_EventCallback(UINT16 *msgData, UINT16 Qualifier)
//U08SIF_STANDARD_INTERFACE(test_EventCallback)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Callback on message event.
**
**  Parameters:     *Data:      Pointer to the message event state.
**                  *Qualifier: (Pointer to) the message event notification states.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 14/Apr/2010
**==========================================================================*/
{
    Qualifier = Qualifier;
	  if (SIF_ISVALID_DATA())
    {
        tstData.msgEvent |= SIF_GET_DATA();
    }
    return 0;
}


void test_Mark(UINT32 Value)
{
    messageIndex = Value;
}

void test_Notification(UINT8 msgSource)
{
    SETBIT(tstData.Notification, msgSource);
}



	  


/*--------------------------------------------------------------------------*/
/* TIMER SIMULATION.                                                        */
/*--------------------------------------------------------------------------*/

void test_StartTimer(UINT32 timeout, TIMER  timer)
{
if(timeout!=0)
{
switch(timer)
{
case SEQ_DISPLAY_TIMER_ID :
Start=2;
break;

case SEQ_HOLD_TIMER_ID :
Start=4;
break;

case SEQ_CYCLE_TIMER_ID  :
Start=6;
break;

case SEQ_DISP_INDICATION_TIMER_ID:
Start=8;
break;

case SEQ_1SEC_TIMER_ID:
Start=10;
break;

default:
Start=111;
break;
}
}
else
{
Start=0;

}
}



void test_ClearTimer(TIMER timer)
{
switch(timer)
{
case SEQ_DISPLAY_TIMER_ID :
Clear=1;
break;

case SEQ_HOLD_TIMER_ID :
Clear=3;
break;

case SEQ_CYCLE_TIMER_ID  :
Clear=5;
break;

case SEQ_DISP_INDICATION_TIMER_ID:
Clear=7;
break;

case SEQ_1SEC_TIMER_ID:
Clear=9;

break;

default:
Clear=0;
break;

}
}

UINT8 test_CheckTimer(TIMER timer)
{

	UINT8 retValue = (UINT8)timer;

	if(TIMER_RUNNING==timer)
	{
	Check=100;
	}
	else
	{
	Check=7;
	}
return retValue;

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
