#include <windows.h>
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include "hmi_logic_state_handler.h"
#include <wchar.h>
#include <math.h>
#include "tmwtypes.h"
#include "hmi_bidi_algo.h"

#ifdef GFX_MGR02_P552_L2

UINT8 hmi_etm_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_diag_ev_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_popup_core_layer0_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_welcome_odo_only_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_minor_gauges_ev_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_root_menu_tab_cb(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_menu_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_trailer_button_deviation_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
UINT8 hmi_chklst_button_deviation_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  return(0);
}
void hmi_popup_core_layer0_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}
void hmi_minor_gauges_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}
void hmi_menu_set_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}
void hmi_neutral_tow_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_splash_mexico_present_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_splash_present_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_blank_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_etm_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_diag_prsnt_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_popup_core_layer0_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_welcome_odoonly_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_minor_gauges_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_root_tab_menu_present_cb(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_gear_pos_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_rtt_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_odo_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}
void hmi_sst_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
}

typedef enum
{
    HMI_STEERING_ELOCKER_HIDE     = -1,
    HMI_STEERING_ELOCKER_SHOW     = 0,
} HMI_OFF_ROAD_ELOCKER_T;


typedef enum
{
    HMI_STEERING_GREY_ARROW_HIDE  = -1,
    HMI_STEERING_GREY_ARROW_SHOW  = 0,
} HMI_OFF_ROAD_GREY_ARROWS_T;

typedef enum
{
    HMI_POWER_FRONT_NUM_OF_LINES  = 48,
    HMI_POWER_BACK_NUM_OF_LINES   = 74
}HMI_POWER_NUM_OF_LINES_T;
typedef enum
{
    HMI_POWER_FRONT_Y_POS_START_LINE  = 0,
	HMI_POWER_BACK_Y_POS_STAT_LINE    = 0
}HMI_POWER_FRONT_Y_POS_LINE_T;
extern int l_power_distrib_scr_active;
int hmi_anim_get_animation_type(void);
int HmiHostRearPercentFill(void);
int HmiHostFrontPercentFill(void);
void hmi_power_distribution_present_update(void)
{
    GFX_MGR02_VCLIP_DATA fl_frnt_tire_offset;
    GFX_MGR02_VCLIP_DATA fl_rear_tire_offset;
    /* ASHEKHAR Work around to keep wheel moving... Need to fix completely.
       No Need to have Alpha set.
    */
    if(l_power_distrib_scr_active != 0x00)
    {
        fl_frnt_tire_offset.num_lines   = (((HmiHostFrontPercentFill() * HMI_POWER_FRONT_NUM_OF_LINES) / 100));
        fl_rear_tire_offset.num_lines   = ((HmiHostRearPercentFill()   * HMI_POWER_BACK_NUM_OF_LINES)  / 100);

        if(fl_frnt_tire_offset.num_lines == 0)
        {
           fl_frnt_tire_offset.num_lines = 1;
           (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_FRONT_ANIM, 0x05);
        }
        else
        {
           (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_FRONT_ANIM, 0xFF);
        }


        if(fl_rear_tire_offset.num_lines == 0)
        {
           fl_rear_tire_offset.num_lines  = 1;
           (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_REAR_ANIM, 0x05);
        }
        else
        {
           (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_REAR_ANIM, 0xFF);
        }

        fl_frnt_tire_offset.start_line = HMI_POWER_FRONT_NUM_OF_LINES - fl_frnt_tire_offset.num_lines;
        fl_rear_tire_offset.start_line = 0;
    }
    else
    {
	   if(hmi_anim_get_animation_type() == __GFX_NUM_ANIMATIONS)
	   {
          l_power_distrib_scr_active       = 0x01;
          fl_frnt_tire_offset.num_lines    = 0;
          fl_rear_tire_offset.num_lines    = 0;
          fl_frnt_tire_offset.start_line   = HMI_POWER_FRONT_NUM_OF_LINES;
          fl_rear_tire_offset.start_line   = HMI_POWER_BACK_Y_POS_STAT_LINE;
	   }
	   else
	   {
          fl_frnt_tire_offset.num_lines    = (((HmiHostFrontPercentFill() * HMI_POWER_FRONT_NUM_OF_LINES) / 100));;
          fl_rear_tire_offset.num_lines    = ((HmiHostRearPercentFill()   * HMI_POWER_BACK_NUM_OF_LINES)  / 100);;
          fl_frnt_tire_offset.start_line   = HMI_POWER_FRONT_NUM_OF_LINES - fl_frnt_tire_offset.num_lines;
          fl_rear_tire_offset.start_line   = HMI_POWER_BACK_Y_POS_STAT_LINE;
	   }

       (void)hmi_gfx_mgr02_if_set_obj_default_properties(GFX_IMG_POWER_DISTRIBUTION_GRAD_ANIM);
       (void)hmi_gfx_mgr02_if_set_obj_default_properties(GFX_WDG_PD_FRONT_ANIM);
       (void)hmi_gfx_mgr02_if_set_obj_default_properties(GFX_WDG_PD_REAR_ANIM);
       (void)hmi_gfx_mgr02_if_set_obj_default_properties(GFX_IMG_PD_TRUCK_ANIM);
       (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_FRONT_ANIM, 0x05);
       (void)hmi_gfx_mgr02_if_set_obj_alpha(GFX_WDG_PD_REAR_ANIM, 0x05);
    }

	//fl_frnt_tire_offset.num_lines    = 0;
    //fl_rear_tire_offset.num_lines    = 0;
    //fl_frnt_tire_offset.start_line   = 48;
    //fl_rear_tire_offset.start_line   = 48;

    (void)hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_FRONT_ANIM, &fl_frnt_tire_offset);
    (void)hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_REAR_ANIM, &fl_rear_tire_offset);
}

void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	  hmi_power_distribution_present_update();
   }
}


UINT32 fuel_hist_grow_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 fuel_hist_reset_bar_5_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 fuel_hist_reset_bar_4_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 fuel_hist_reset_bar_3_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 fuel_hist_reset_bar_2_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 fuel_hist_reset_bar_1_intphdl(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_menu_content_to_list_step_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_menu_list_to_content_step_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_page_content_to_content_up_previous_fadeout_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_page_content_to_content_up_next_fadein_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_page_content_to_content_down_previous_fadeout_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_page_content_to_content_down_next_fadein_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_warn_zone2_content_fadeout_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_warn_zone2_content_fadein_step1_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}
UINT32 hmi_warn_zone2_content_fadein_step2_animcb(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}

void hmi_reset_anim_callback(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_welcome_splash_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
UINT32 hmi_p552_set_welcome_animation(UINT32 p_cur_step)
{
   return(p_cur_step);
}
void hmi_welcome_close_splash_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_tab_transition_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_tab_transition_left_to_right_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_tab_transition_right_to_left_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_list_to_content_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_list_to_content_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_to_list_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_to_list_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_list_to_list_closeing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_list_to_list_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_move_up_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_move_up_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_move_down_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_content_move_down_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_focus_move_templateAB_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_focus_move_up_templateCD_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_menu_focus_move_down_templateCD_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_zone2_content_fadeout_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_zone2_content_fadein_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_warn_generic_fadein_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_warn_generic_fadeout_animcb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_welcome_odoonly_fadeout_complete(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
void hmi_connection_checklist_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}
#if 0
void hmi_reset_anim_callback(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_tab_transition_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_tab_transition_left_to_right_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_tab_transition_right_to_left_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_content_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_content_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_to_list_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_to_list_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_list_closeing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_list_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_move_up_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_move_up_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_move_down_closing_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_move_down_opening_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_focus_move_up_templateCD_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_focus_move_down_templateCD_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_zone2_content_fadeout_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
#endif

UINT32 hmi_reset_anim_reset_action_cb(UINT32 p_cur_step){return 0;}
UINT32 warn_zone2_content_fadeout_set_sequence(UINT32 p_cur_step){return 0;}
UINT32 reset_progress_bar_step_anim_cb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_warn_zone2_fadeout_animcb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_warn_zone2_list_fadein_animcb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_warn_zone2_fadein_animcb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_anim_gauge_view_gaugefill_fadeoutcb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_gauge_view_into_minorgaugefadeout_cb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}
UINT32 hmi_gauge_view_selection_part2_animcb(UINT32 p_cur_step, UINT32 p_max_step){return 0;}


void hmi_reset_cancel_anim_callback(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_compass_anim_update_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_row_welcome_screen_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_mexico_welcome_screen_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
UINT32 hmi_warn_generic_set_sequnce(UINT32 p_cur_step){return 0;}
void hmi_street_sign_fadein_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
UINT32 hmi_nav_streat_text_fadein_animselect(UINT32 p_cur_step){return 0;}
void hmi_nav_speed_sign_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
UINT32 is_nav_europe_configured(UINT32 p_cur_step){return 0;}
UINT32 nav_speed_sign_goto_end(UINT32 p_cur_step){return 0;}
void hmi_nav_destination_reached_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_nav_waypoint_flag_animon_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_nav_waypoint_flag_animoff_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_nav_turn_by_turn_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
UINT32 hmi_nav_turn_by_turn_set_index(UINT32 p_cur_step){return 0;}
UINT32 hmi_nav_turn_by_turn_end_sequence(UINT32 p_cur_step){return 0;}
void hmi_rpa_warn_fadein_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_warn_instrument_dimm_fadein_animcb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_warn_tpms_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
UINT32 hmi_warn_tpms_set_sequence(UINT32 p_cur_step){return 0;}
void hmi_warn_tpms_fadeout_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_list_animation_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_content_to_content_up_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_content_to_content_down_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_list_to_content_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_menu_content_to_list_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_warn_zone2_content_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
void hmi_warn_generic_content_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames){}
#endif