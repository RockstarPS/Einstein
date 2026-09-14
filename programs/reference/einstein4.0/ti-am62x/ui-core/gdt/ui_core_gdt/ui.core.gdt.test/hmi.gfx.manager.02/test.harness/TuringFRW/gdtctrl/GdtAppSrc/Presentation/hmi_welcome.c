#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h" 
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_cfg.h"

#if 0
UINT8 hmi_welcome_ev_hndlr(const LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	return (LSH_STATUS_ABSORBED);
}

void hmi_welcome_present_hndlr(const LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	if ((p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS) || 
	    (p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS))
	{		
		hmi_gfx_mgr02_layout_set_text(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else /* LSH_DEACTIVATED_STATUS */
	{ 
		hmi_gfx_mgr02_layout_set_text(p_presen_hndl_status_SP->logic_state_id, 0);
	}
}

void hmi_welcome_focus_hndlr(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
   if(p_focus_hndl_status_SP->focus_status == LSH_ANIM_COMPLETE_STATUS)
   {
       LSH_REM_STATE(GFX_SRC_WELCOME,  ANIM_MAX_ID);
   }
   else if(p_focus_hndl_status_SP->focus_status == LSH_LOST_FOCUS_STATUS)
   {
  	   LSH_ADD_STATE(GFX_SCR_HEADER_FOOTER, ANIM_MAX_ID);
   }
   else
   {
   }
}
#endif
