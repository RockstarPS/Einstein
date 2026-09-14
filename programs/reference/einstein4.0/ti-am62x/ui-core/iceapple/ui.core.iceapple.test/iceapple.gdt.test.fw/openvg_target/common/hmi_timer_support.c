/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
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
 ** Name:          hmi_timer_support.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_TIMER_SUPPORT_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/

#include "hmi_timer_support.h"
#include "hmi_msgSequencer.cfg"
#include "hmi_menu_core_01_logic.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
WPARAM WindowsTimer[HMI_NO_OF_TIMERS];
UINT16 popupTimerEvent[HMI_NO_OF_TIMERS];
WPARAM msgcore_timer_id;
int    msgcore_timer_ev;
WPARAM msgcore_cycletimer_id;
int    msgcore_cycletimer_ev;
WPARAM msgcore_newwarntimer_id;
int    msgcore_newwarntimer_ev;
WPARAM msgcore_longCycletimer_id;
int    msgcore_longCycletimer_ev;
WPARAM msgcore_holdtimer_id;
int    msgcore_holdtimer_ev;


WPARAM msgcore_timer_id_0;
int    msgcore_timer_ev_0;
WPARAM msgcore_cycletimer_id_0;
int    msgcore_cycletimer_ev_0;
WPARAM msgcore_newwarntimer_id_0;
int    msgcore_newwarntimer_ev_0;
WPARAM msgcore_holdtimer_id_0;
int    msgcore_holdtimer_ev_0;
WPARAM msgcore_ackreptimer_id_0;
int    msgcore_ackreptimer_ev_0;


/* Menu Timers*/
WPARAM WindowsMenuTimer[HMI_NO_OF_MENU_TIMERS];
WPARAM menu_timer_id;

/****************************************************************************
Function Name        : timer_support_wint_proc
Description          : Notifies Windows timer expiry
Invocation           : invoked by windows main function
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
VOID CALLBACK hmi_timer_support_proc(_In_  HWND hwnd, _In_  UINT uMsg, _In_  UINT_PTR idEvent, _In_  DWORD dwTime){
  UINT8 i;
  for(i = 0; i < HMI_NO_OF_TIMERS; i++)
  {
    if(idEvent == WindowsTimer[i])
    {
 	  WindowsTimer[i] = 0;
      hmi_popup_core_timeout_callback(i,popupTimerEvent[i]);
      hmi_popup_core_activate_popup(L1_INFO_POPUP_ID, ANIM_MAX_ID);
      KillTimer(NULL,idEvent);
    }
  }
  for(i = 0; i < HMI_NO_OF_MENU_TIMERS; i++)
  {
    if(idEvent == WindowsMenuTimer[i])
    {
      WindowsMenuTimer[i] = 0;
      hmi_menu_logic_open_timer_timeout(i, ANIM_MAX_ID);
      KillTimer(NULL,idEvent);
    }
  }
  if(idEvent == msgcore_timer_id) 
  {
    msgcore_timer_ev = TIMER_EXPIRED;
    msgcore_timer_id = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_cycletimer_id) 
  {
    msgcore_cycletimer_ev = TIMER_EXPIRED;
    msgcore_cycletimer_id = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_newwarntimer_id) 
  {
    msgcore_newwarntimer_ev = TIMER_EXPIRED;
    msgcore_newwarntimer_id = 0;
    KillTimer(NULL,idEvent);
  }
    if(idEvent == msgcore_longCycletimer_id) 
  {
    msgcore_longCycletimer_ev = TIMER_EXPIRED;
    msgcore_longCycletimer_id = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_holdtimer_id) 
  {
    msgcore_holdtimer_ev = TIMER_EXPIRED;
    msgcore_holdtimer_id = 0;
    KillTimer(NULL,idEvent);
  }
  
  
  if(idEvent == msgcore_timer_id_0) 
  {
    msgcore_timer_ev_0 = TIMER_EXPIRED;
    msgcore_timer_id_0 = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_cycletimer_id_0) 
  {
    msgcore_cycletimer_ev_0 = TIMER_EXPIRED;
    msgcore_cycletimer_id_0 = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_newwarntimer_id_0) 
  {
    msgcore_newwarntimer_ev_0 = TIMER_EXPIRED;
    msgcore_newwarntimer_id_0 = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_holdtimer_id_0) 
  {
    msgcore_holdtimer_ev_0 = TIMER_EXPIRED;
    msgcore_holdtimer_id_0 = 0;
    KillTimer(NULL,idEvent);
  }
  if(idEvent == msgcore_ackreptimer_id_0) 
  {
    msgcore_ackreptimer_ev_0 = TIMER_EXPIRED;
    msgcore_ackreptimer_id_0 = 0;
    KillTimer(NULL,idEvent);
  }
}

/****************************************************************************
Function Name        : hmi_popup_core_support_timer_start
Description          : Start timer interface
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_popup_core_support_timer_start(TIMER_ID_TYPE timer_id, UINT32 timeout_count, UINT16 p_evt_U16)
{
   if(WindowsTimer[timer_id] == 0){
      WindowsTimer[timer_id]    = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, (TIMERPROC)hmi_timer_support_proc);
      popupTimerEvent[timer_id] = p_evt_U16;
   }
}

/****************************************************************************
Function Name        : hmi_popup_core_support_timer_stop
Description          : Stop timer interface
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_popup_core_support_timer_stop(TIMER_ID_TYPE timer_id)
{
	KillTimer(NULL,WindowsTimer[timer_id]);
	WindowsTimer[timer_id] = 0;
}

/****************************************************************************
Function Name        : hmi_popup_core_support_timer_check
Description          : Check timer interface
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_popup_core_support_timer_check(TIMER_ID_TYPE timer_id)
{
	if(WindowsTimer[timer_id] != 0)
	{
		return HMI_TIMER_RUNNING;
	}
	else
	{
		return HMI_TIMER_NOT_RUNNING;
	}
}

/****************************************************************************
Function Name        : hmi_msg_core_support_timer_start
Description          : Start timer interface
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_msg_core_support_timer_start(UINT32 timeout_count, TIMER_ID_TYPE timer_id)
{
    if((timer_id == SEQ_DISPLAY_TIMER_ID_1) && (msgcore_timer_id == 0))
    {
	  msgcore_timer_ev = TIMER_RUNNING;
	  msgcore_timer_id = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == SEQ_CYCLE_TIMER_ID_1) && (msgcore_cycletimer_id == 0))
    {
	  msgcore_cycletimer_ev = TIMER_RUNNING;
	  msgcore_cycletimer_id = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == SEQ_DISP_INDICATION_TIMER_ID_1) && (msgcore_newwarntimer_id == 0))
    {
	  msgcore_newwarntimer_ev = TIMER_RUNNING;
	  msgcore_newwarntimer_id = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == SEQ_LONG_CYCLE_TIMER_ID_1) && (msgcore_longCycletimer_id == 0))
    {
	  msgcore_longCycletimer_ev = TIMER_RUNNING;
	  msgcore_longCycletimer_id = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }   
    if((timer_id == SEQ_HOLD_TIMER_ID_1) && (msgcore_holdtimer_id == 0))
    {
	  msgcore_holdtimer_ev = TIMER_RUNNING;
	  msgcore_holdtimer_id = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    } 
    if((timer_id == SEQ_DISPLAY_TIMER_ID_0) && (msgcore_timer_id_0 == 0))
    {
	  msgcore_timer_ev_0 = TIMER_RUNNING;
	  msgcore_timer_id_0 = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    } 
    if((timer_id == SEQ_CYCLE_TIMER_ID_0) && (msgcore_cycletimer_id_0 == 0))
    {
	  msgcore_cycletimer_ev_0 = TIMER_RUNNING;
	  msgcore_cycletimer_id_0 = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == SEQ_DISP_INDICATION_TIMER_ID_0) && (msgcore_newwarntimer_id_0 == 0))
    {
	  msgcore_newwarntimer_ev_0 = TIMER_RUNNING;
	  msgcore_newwarntimer_id_0 = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == SEQ_HOLD_TIMER_ID_0) && (msgcore_holdtimer_id_0 == 0))
    {
	  msgcore_holdtimer_ev_0 = TIMER_RUNNING;
	  msgcore_holdtimer_id_0 = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }
    if((timer_id == STOR_ACK_WRNG_REP_TIMER_ID_0) && (msgcore_ackreptimer_id_0 == 0))
    {
	  msgcore_ackreptimer_ev_0 = TIMER_RUNNING;
	  msgcore_ackreptimer_id_0 = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
    }  
}

/****************************************************************************
Function Name        : hmi_msg_core_support_timer_stop
Description          : Stop timer interface
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_msg_core_support_timer_stop(TIMER_ID_TYPE timer_id)
{
   if(timer_id == SEQ_DISPLAY_TIMER_ID_1)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_timer_id = 0;
	  msgcore_timer_ev = TIMER_CLEAR;
   }
   if(timer_id == SEQ_CYCLE_TIMER_ID_1)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_cycletimer_id = 0;
	  msgcore_cycletimer_ev = TIMER_CLEAR;
   }
   if(timer_id == SEQ_DISP_INDICATION_TIMER_ID_1)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_newwarntimer_id = 0;
	  msgcore_newwarntimer_ev = TIMER_CLEAR;
   }
   if(timer_id == SEQ_LONG_CYCLE_TIMER_ID_0)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_longCycletimer_id = 0;
	  msgcore_longCycletimer_ev = TIMER_CLEAR;
   }
   if(timer_id == SEQ_HOLD_TIMER_ID_1)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_holdtimer_id = 0;
	  msgcore_holdtimer_ev = TIMER_CLEAR;
   }	

   if(timer_id == SEQ_DISPLAY_TIMER_ID_0)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_timer_id_0 = 0;
	  msgcore_timer_ev_0 = TIMER_CLEAR;
   }
   if(timer_id == SEQ_CYCLE_TIMER_ID_0)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_cycletimer_id_0 = 0;
	  msgcore_cycletimer_ev_0 = TIMER_CLEAR;
   }
   if(timer_id == SEQ_DISP_INDICATION_TIMER_ID_0)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_newwarntimer_id_0 = 0;
	  msgcore_newwarntimer_ev_0 = TIMER_CLEAR;
   }
   if(timer_id == SEQ_HOLD_TIMER_ID_0)
   {
	  KillTimer(NULL, timer_id);
	  msgcore_holdtimer_id_0 = 0;
	  msgcore_holdtimer_ev_0 = TIMER_CLEAR;
   }
    if(timer_id == STOR_ACK_WRNG_REP_TIMER_ID_0)
    {
	  KillTimer(NULL, timer_id);
	  msgcore_ackreptimer_id_0 = 0;
	  msgcore_ackreptimer_ev_0 = TIMER_CLEAR;
    }  
}

/****************************************************************************
Function Name        : hmi_msg_core_support_timer_check
Description          : Check timer interface
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_msg_core_support_timer_check(TIMER_ID_TYPE timer_id)
{
	if(timer_id == SEQ_DISPLAY_TIMER_ID_1)
	{
		if(msgcore_timer_ev == TIMER_EXPIRED)
		{
			msgcore_timer_ev = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_timer_ev != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_CYCLE_TIMER_ID_1)
	{
		if(msgcore_cycletimer_ev == TIMER_EXPIRED)
		{
			msgcore_cycletimer_ev = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_cycletimer_ev != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_DISP_INDICATION_TIMER_ID_1)
	{
		if(msgcore_newwarntimer_ev == TIMER_EXPIRED)
		{
			msgcore_newwarntimer_ev = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_newwarntimer_ev != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_LONG_CYCLE_TIMER_ID_0)
	{
		if(msgcore_longCycletimer_ev == TIMER_EXPIRED)
		{
			msgcore_longCycletimer_ev = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_longCycletimer_ev != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_HOLD_TIMER_ID_1)
	{
		if(msgcore_holdtimer_ev == TIMER_EXPIRED)
		{
			msgcore_holdtimer_ev = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_holdtimer_ev != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}

   	if(timer_id == SEQ_DISPLAY_TIMER_ID_0)
	{
		if(msgcore_timer_ev_0 == TIMER_EXPIRED)
		{
			msgcore_timer_ev_0 = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_timer_ev_0 != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_CYCLE_TIMER_ID_0)
	{
		if(msgcore_cycletimer_ev_0 == TIMER_EXPIRED)
		{
			msgcore_cycletimer_ev_0 = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_cycletimer_ev_0 != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_DISP_INDICATION_TIMER_ID_0)
	{
		if(msgcore_newwarntimer_ev_0 == TIMER_EXPIRED)
		{
			msgcore_newwarntimer_ev_0 = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_newwarntimer_ev_0 != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
	if(timer_id == SEQ_HOLD_TIMER_ID_0)
	{
		if(msgcore_holdtimer_ev_0 == TIMER_EXPIRED)
		{
			msgcore_holdtimer_ev_0 = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_holdtimer_ev_0 != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}
    if(timer_id == STOR_ACK_WRNG_REP_TIMER_ID_0)
	{
		if(msgcore_ackreptimer_ev_0 == TIMER_EXPIRED)
		{
			msgcore_ackreptimer_ev_0 = TIMER_CLEAR;
			return TIMER_EXPIRED;
		}
		else if(msgcore_ackreptimer_ev_0 != 0)
		{
			return TIMER_RUNNING;
		}
		else
		{
		}
	}

	return TIMER_CLEAR;
}

/****************************************************************************
Function Name        : hmi_menu_core_start_timer
Description          : Start timer interface
Invocation           : invoked by menu core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_menu_core_start_timer(UINT8 menu_id, MENU_TIMER_ID_TYPE timer_id, UINT32 timeout_count)
{
	if(WindowsMenuTimer[timer_id] == 0){
	   WindowsMenuTimer[timer_id] = SetTimer(NULL, (UINT_PTR)NULL , timeout_count *1000, hmi_timer_support_proc);
	}
}

/****************************************************************************
Function Name        : hmi_menu_core_stop_timer
Description          : Stop timer interface
Invocation           : invoked by menu core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_menu_core_stop_timer(UINT menu_id, MENU_TIMER_ID_TYPE timer_id)
{
	KillTimer(NULL,WindowsMenuTimer[timer_id]);
	WindowsMenuTimer[timer_id] = 0;
}

/*============================================================================
 **
 **============================================================================
 ** C M S    R E V I S I O N    N O T E S
 **============================================================================
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.
 ** 2.  Why the change was made and the intended result.
 **
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 **
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif