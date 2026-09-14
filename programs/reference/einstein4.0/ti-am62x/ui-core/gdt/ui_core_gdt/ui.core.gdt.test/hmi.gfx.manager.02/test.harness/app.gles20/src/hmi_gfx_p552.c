#include <windows.h>
#include "hmi_gfx_mgr02_layout.h"
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
void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
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


#endif