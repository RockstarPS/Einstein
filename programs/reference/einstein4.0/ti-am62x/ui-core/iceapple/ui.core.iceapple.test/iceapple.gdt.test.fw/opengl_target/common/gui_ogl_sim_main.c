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
 ** Name:           gui_test_main.c
 **
 ** Description:    
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define gui_test_main_c

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "conio.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_logic_state_handler.h"
#include <wchar.h>
#include <math.h>
#include "tmwtypes.h"
#include "hmi_bidi_algo.h"
#include "sched.h"
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
VOID CALLBACK GTTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
int l_welcome_done = 0;
int l_gt_request   = 0;
int l_preset_num = 1,l_scroll_bar=0, l_header_layout=0, l_time=0, l_posx=85;
float l_scale = 1.0;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

void hmi_gfx_mgr02_driver_dcu_isr(void)
{
}

/*============================================================================
** Function Name:    
** Visibility:       
** Description:      
** Invocation:       
** Inputs/Outputs:   
** Critical Section: 
** Created:          09-Aug-2012 by EMANOJ1
** Updated:          09-Aug-2012 by EMANOJ1
**==========================================================================*/
int main(int argc, char * argv[])
{
   MSG    msg;
   UINT32 fl_prev_count = GetTickCount();
   UINT32 fl_cur_count;
   static int l_test_scr=0;

   SetTimer(NULL, 0, 32, GTTimerProc);
   hmi_gfx_mgr02_if_KSColdInit();
   hmi_lsh_initialize(1);
   hmi_gfx_mgr02_if_start();
#if GFX_NUM_ANIMATIONS > 0
   hmi_gfx_anim_engine_init();
#endif

   //Add first screen as default
   LSH_ADD_STATE(l_test_scr, 255);
   printf("screen %d added\n",l_test_scr);

   while(1)
   {
      if(_kbhit())
      {
        switch(_getch())
        {
        case  27:return(0);
        case 'a':
          LSH_REM_STATE(l_test_scr++, 255);
          if(l_test_scr >= GFX_MGR02_NUM_OF_SCREENS)
            l_test_scr = 0;
          LSH_ADD_STATE(l_test_scr, 255);
          printf("screen %d added\n",l_test_scr);

          break;
        }
      }
      fl_cur_count = GetTickCount();
      if((fl_cur_count-fl_prev_count) >= 33)
      {
          fl_prev_count += 33;
#if GFX_NUM_ANIMATIONS > 0
          hmi_gfx_anim_engine();
          hmi_gfx_mgr02_if_KSTimedTask();
          hmi_gfx_anim_engine_tick();
#endif
      }
      if(GetMessage(&msg, NULL, 0, 0))
      {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
   }
}

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event)
{
   UINT32 p_touch_event = GFX_MGR02_GET_MOUSE_EV(p_event->event);
   UINT32 p_touch_event_gone_ouside_bounds = GFX_MGR02_IS_MOUSE_OUTSIDE_BOUND(p_event->event);
   if(p_touch_event == GFX_MGR02_MOUSE_UP_EV)
   {
   #ifdef EAGLE_OPENGL
      if(p_obj_id == GFX_DTWDG_SOURCE_CLOSE)
      {
      	  LSH_REM_STATE(GFX_SCR_SOURCE, GFX_SOURCE_OFF_ANIM);
      }
      else if(p_obj_id == GFX_DTWDG_SOURCE)
      {
      	  hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_WDG_SOURCE_ANIM, 800);
      	  LSH_ADD_STATE(GFX_SCR_SOURCE, GFX_SOURCE_ON_ANIM);
      }
      else
      {
      }
   #endif
   }
   printf("Touch Event %d on Element %d X=%d, Y=%d, Valid=%d\n", p_touch_event, p_obj_id, p_event->x, p_event->y, p_touch_event_gone_ouside_bounds);
}
#endif

UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T * p_event_hndl_status_SP)
{
    return(0);
}

void KernelTriggerGraphicsTask(void)
{
   l_gt_request = 1;
}

VOID CALLBACK GTTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
   if(l_gt_request != 0)
   {
      l_gt_request = 0;
      Graphics_Task();
      Graphics_Task_Done();
   }
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
 ** CMS Rev 1.0      09-Aug-2012    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
