#include "ui_presentation.h"

//#include "port.h"
//m#include"main.h"


unsigned int l_current_scrren_U32=0;
//men_port_gpio_level_t ledstatus;

void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id)
{

}
void hmi_compass_anim_update_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event)
{

printf("hmi_gfx_mgr02_app_touch_event_handler(obj:%d, event:%d)\n", p_obj_id, p_event);


}
#endif

void hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{

}


void hmi_scr_p42m_compass_present_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
#if 0
    switch(p_presen_hndl_status_SP->presentation_status)
    {
	case LSH_ACTIVATED_STATUS:
	  (void) hmi_gfx_mgr02_if_set_screen(GFX_SCR_P42M_COMPASS, 1);
	  hmi_gfx_anim_play_fwd(GFX_SCR_P42M_COMPASS,GFX_NEW_ANIMATIONS_1);
	break;
        case LSH_REFRESH_STATUS:
	break;
	case LSH_DEACTIVATED_STATUS:
	 (void) hmi_gfx_mgr02_if_set_screen(GFX_SCR_P42M_COMPASS, 0);
	  break;
	default:
	  break;
    }
#endif
}
UINT8 hmi_scr_p42m_compass_ev_hndlr(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    switch(p_event_hndl_status_SP->button_command)
    {
    default : 
        return(LSH_STATUS_NONE);
    }

}
void hmi_scr_p42m_compass_focus_hndlr(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}

UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T * p_btn_command_id)
{
   return 0;
}

UINT32 needle_goto_callback(UINT32 p_cur_step)
{
    return(0);
}

void eco_pedal_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

UINT32 eco_pedal_goto_cb(UINT32 p_cur_step)
{
    return(0);
}


void hmi_ecopedal_present_hdnlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    GFX_MGR02_IAREA_DATA fl_area;
	fl_area.x=150;
	fl_area.y=60;
	fl_area.width=150;
	fl_area.height=300;
	//hmi_gfx_mgr02_layout_set_obj_area(GFX_WDG_HF_ANIM, &fl_area);
    switch(p_presen_hndl_status_SP->presentation_status)
    {
	case LSH_ACTIVATED_STATUS:
	  (void) hmi_gfx_mgr02_if_set_screen((int)p_presen_hndl_status_SP->logic_state_id, 1);
	  //hmi_gfx_anim_play_fwd(GFX_TEST_SCREEN,GFX_MAL_TEST);
	  hmi_gfx_anim_play_fwd((int)p_presen_hndl_status_SP->logic_state_id,GFX_ECO_PEDAL_ANIM);
	break;
        case LSH_REFRESH_STATUS:
	break;
	case LSH_DEACTIVATED_STATUS:
	 (void) hmi_gfx_mgr02_if_set_screen((int)p_presen_hndl_status_SP->logic_state_id, 0);
	  break;
	default:
	  break;
    }

}
UINT8 hmi_ecopedal_ev_hdnlr(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    switch(p_event_hndl_status_SP->button_command)
    {
    default : 
        return(LSH_STATUS_NONE);
    }

}
void hmi_ecopedal_focus_hdnlr(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}

