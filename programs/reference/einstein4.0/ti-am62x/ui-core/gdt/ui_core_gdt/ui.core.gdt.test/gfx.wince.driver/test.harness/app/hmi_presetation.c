#include "system.h"
#include "hmi_gfx_driver.h"
#include "hmi_gfx_interface.h"
#include <wchar.h>
#define HMI_GRAPHICS_APP_C
#include "mireo_viaGPS_API.h"

int cur_screen = GFX_SCR_HOME;
void GfxPresentationInit(void)
{
}

/*****************************************************************************
 *
 *   Function Name:         GfxHmiNaviWindowsHandler
 *
 *   Description:           handler controls hmi and navi windows based on commands from Logic
 *
 *   Parameters:            None
 *
 *   Global Variables Used: None
 *
 *   Return value:          None
 *
 ******************************************************************************/
void GfxHmiNaviWindowsHandler(UINT layerStatus)
{
  HWND l_hWnd = FindWindow(L"HMI", L"hmi");
  HWND hWnd = FindWindow(mireo_app_class, mireo_wnd_title);

  if(layerStatus)
  {
    if(hWnd)
    {
      SendMessage(hWnd, WM_MIREO_ACTIVATE, MA_FOREGROUND, 0);
      SetForegroundWindow(hWnd);
    }
    else
    {
      SHELLEXECUTEINFO shExeInfo = {0};
      shExeInfo.cbSize = sizeof(SHELLEXECUTEINFO);
      shExeInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
      shExeInfo.hwnd = NULL;
      shExeInfo.lpVerb = NULL;
      shExeInfo.lpFile = TEXT("\\MMCMemory\\MapmyIndia\\BlackEdition.exe");
      shExeInfo.lpParameters = TEXT("");
      shExeInfo.lpDirectory = NULL;
      shExeInfo.nShow = SW_SHOWNORMAL;
      shExeInfo.hInstApp = NULL;
      //ShellExecuteEx(&shExeInfo);
      ShowWindow(l_hWnd, SW_HIDE);
	  //hmi_gfx_ddraw_distroy();
    }
  }
  else
  {
    if(l_hWnd)
    {
      SendMessage(hWnd, WM_MIREO_ACTIVATE, MA_BACKGROUND, 0);
      SetForegroundWindow(l_hWnd);
    }
  }
}

void GfxTouchEventHandler(UINT32 p_btn_id, UINT32 p_button_state, UINT32 p_btn_ev)
{
   switch(p_btn_id)
   {
	  case GFX_WDG_TNR_BAND:
	  {
		 printf("GFX_WDG_TNR_BAND\n");
		 GfxHmiNaviWindowsHandler(1);
	  }
	  break;
	  case GFX_WDG_HOME_BTN_3:
	  {
		  cur_screen = GFX_SCR_TUNER;
	  }
	  break;
	  case GFX_WDG_HOME_BTN:
	  {
		  cur_screen = GFX_SCR_HOME;
	  }
	  break;
	  default:
	  {
         printf("Touch %d,%d,%d\n",p_btn_id,p_button_state,p_btn_ev);
	  }
	  break;
   }
}

void GfxNaviMessagesHandler(UINT message)
{
}

void GfxPresentationTask(void)
{
#if 0
   static unsigned char anim_step = 0;
   static unsigned char welcome   = 40;

   if(hold_action_count != 0)
   {
	  hold_action_count--;
	  if(hold_action_count == 0)
	  {
		 switch(hold_action)
		 {
			case HOLD_ACTION_PSAVE :PresetSave(hold_action_val);
			                        hold_action=HOLD_ACTION_DONE;
			                        break;
			case HOLD_ACTION_SEEKUP:SearchStationFWD(1);
			                        hold_action=HOLD_ACTION_DONE;
			                        break;
			case HOLD_ACTION_SEEKDN:SearchStationBWD(1);
			                        hold_action=HOLD_ACTION_DONE;
			                        break;
		 }
	  }
   }
   if(auto_search)
   {
	  SearchStationFWD(0);
   }
   hmi_gfx_if_send_data_cmd(cur_screen, 1);
#endif
   switch(cur_screen)
   {
       case GFX_SCR_TUNER:
	   {
		   hmi_gfx_if_send_data_cmd(GFX_SCR_TUNER, 1);
		   hmi_gfx_if_send_data_cmd(GFX_SCR_HOME, 0);
	   }
	   break;
       case GFX_SCR_HOME:
	   {
		   hmi_gfx_if_send_data_cmd(GFX_SCR_TUNER, 0);
		   hmi_gfx_if_send_data_cmd(GFX_SCR_HOME, 1);
	   }
	   break;
   }

   hmi_gfx_if_update_cmd();
}