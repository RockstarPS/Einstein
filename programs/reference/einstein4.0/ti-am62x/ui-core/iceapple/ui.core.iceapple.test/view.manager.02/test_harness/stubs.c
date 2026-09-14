
#include "stdio.h"
//#include "hmi_gfx_anim_engine_cfg.h"
#include "hmi_logic_state_handler.h"


UINT8 l_absorb_type00;
UINT8 l_absorb_type01;
UINT8 l_absorb_type02;
UINT8 l_absorb_type10;
UINT8 l_absorb_type11;
UINT8 l_absorb_type12;
UINT8 l_absorb_type20;
UINT8 l_absorb_type21;
UINT8 l_absorb_type22;

char * buttonid_str[] =
{
   "ButtonID_POWER",
   "ButtonID_0",
   "ButtonID_1",
   "ButtonID_2",
   "ButtonID_3",
   "ButtonID_4",
   "ButtonID_SOFT_KEY_1",
   "ButtonID_SOFT_KEY_2",
   "ButtonID_SOFT_KEY_3",
   "ButtonID_SOFT_KEY_4",
   "ButtonID_HOUR",
   "ButtonID_MINUTE",
   "ButtonID_VOLUME_KNOB",
   "ButtonID_MMRC_VOLUME_DOWN",
   "ButtonID_MMRC_PTT",
   "ButtonID_HOUR_MIN",
   "ButtonID_INVALID"
};

char * buttonst_str[] =
{
   "RELEASED",
   "PRESSED",
   "REPEAT1",
   "REPEAT2",
   "REPEAT3",
   "REPEAT4",
   "INVALID"
};

char * lsh_state_str[] =
{
   "GFX_SCR_00",
   "GFX_SCR_01",
   "GFX_SCR_02",
   "GFX_SCR_10",
   "GFX_SCR_11",
   "GFX_SCR_12",
   "GFX_SCR_20",
   "GFX_SCR_21",
   "GFX_SCR_22",
   "INVALID_STATE"
};

char * getState(LSH_STATE_ID_T p_state_id_U8)
{
   if(p_state_id_U8<=8)
   {
      return lsh_state_str[p_state_id_U8];
   }
   else
   {
      return lsh_state_str[9];
   }
}

void printf_focus(UINT8 focus)
{
   printf("  FOCUS_STATUS\n");
   if(focus == 0 || focus == 255)
   {
	  printf("   LSH_INVALID_STATUS\n");
   }
   else
   {
   if(focus & LSH_LOST_FOCUS_STATUS)
   {
	  printf("   LSH_LOST_FOCUS_STATUS\n");
   }
   if(focus & LSH_GOT_FOCUS_STATUS)
   {
	  printf("   LSH_GOT_FOCUS_STATUS\n");
   }
   if((focus & LSH_REFRESH_STATUS) == LSH_ACTIVATED_STATUS)
   {
	  printf("   LSH_ACTIVATED_STATUS\n");
   }
   if((focus & LSH_REFRESH_STATUS)== LSH_DEACTIVATED_STATUS)
   {
	  printf("   LSH_DEACTIVATED_STATUS\n");
   }
   if((focus & LSH_REFRESH_STATUS) == LSH_REFRESH_STATUS)
   {
	  printf("   LSH_REFRESH_STATUS\n");
   }
   if(focus & LSH_ANIM_COMPLETE_STATUS)
   {
	  printf("   LSH_ANIM_COMPLETE_STATUS\n");
   }
   if(focus & LSH_ANIM_STARTED_STATUS)
   {
	  printf("   LSH_ANIM_STARTED_STATUS\n");
   }
   }
}


void print_button(UINT16 p_button_command_U16)
{
   UINT16 p_button_id     = LSH_GET_ID(p_button_command_U16);
   UINT16 p_button_state  = LSH_GET_STATUS(p_button_command_U16);
   if(p_button_id > 16)
   {
	  p_button_id = 16;
   }
   if(p_button_state > 6)
   {
	  p_button_state = 6;
   }
   printf("  BTN ID = [%s]\n  BTN STS = [%s]\n", buttonid_str[p_button_id], buttonst_str[p_button_state]);
}

UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nhmi_lsh_default_button_event_handler\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(LSH_STATUS_ABSORBED);
}

UINT8 scr_00_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_00_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type00);
}
UINT8 scr_01_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_01_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type01);
}
UINT8 scr_02_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_02_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   printf("hmi_lsh_add_state(GFX_SCR_12, ANIM_MAX_ID)\nhmi_lsh_remap_button_events(ButtonID_POWER, GFX_SCR_12)\n");
   LSH_ADD_STATE(GFX_SCR_12, ANIM_MAX_ID);
   hmi_lsh_remap_button_events(ButtonID_POWER, GFX_SCR_12);
   return(l_absorb_type02);
}
UINT8 scr_10_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_10_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type10);
}
UINT8 scr_11_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_11_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type11);
}
UINT8 scr_12_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_12_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type12);
}
UINT8 scr_20_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_20_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type20);
}
UINT8 scr_21_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_21_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type21);
}
UINT8 scr_22_ev(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_22_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
   return(l_absorb_type22);
}

void printf_focus_status(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("  logic state = %s\n", getState(state->logic_state_id));
   printf("  focus id = %d\n",state->focus_id);
   printf("  client id = %d\n", state->client_id);
   printf_focus(state->focus_status);
}

void printf_unfreeze_event_status(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf("\nscr_unfreeze_ev\n  state = %s\n", getState(state->logic_state_id));
   print_button(state->button_command);
}

void scr_00_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_00_focus\n");
   printf_focus_status(state);
}
void scr_01_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_01_focus\n");
   printf_focus_status(state);
}
void scr_02_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_02_focus\n");
   printf_focus_status(state);
}
void scr_10_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_10_focus\n");
   printf_focus_status(state);
}
void scr_11_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_11_focus\n");
   printf_focus_status(state);
   if(state->focus_status & LSH_LOST_FOCUS_STATUS)
   {
      printf("hmi_lsh_remove_state(S11, ANIM_MAX_ID)\n");
	  LSH_REM_STATE(GFX_SCR_11, ANIM_MAX_ID);
   }
}
void scr_12_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_12_focus\n");
   printf_focus_status(state);
}
void scr_20_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_20_focus\n");
   printf_focus_status(state);
}
void scr_21_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_21_focus\n");
   printf_focus_status(state);
}
void scr_22_focus(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_22_focus\n");
   printf_focus_status(state);
}

void scr_presentation_print_presentation(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("  logic state = %s\n", getState(state->logic_state_id));
   printf_focus(state->presentation_status);
}

void scr_00_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_00_pres\n");
   scr_presentation_print_presentation(state);
}

void scr_01_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_01_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_02_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_02_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_10_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_10_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_11_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_11_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_12_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_12_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_20_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_20_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_21_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_21_pres\n");
   scr_presentation_print_presentation(state);
}
void scr_22_pres(LSH_PRESN_HANDLER_STATUS_T * state)
{
   printf("scr_22_pres\n");
   scr_presentation_print_presentation(state);
}
void gui_common_focus_handler_for_all_screen(LSH_FOCUS_HANDLER_STATUS_T * state)
{
   printf("scr_all_scr\n");
   printf_focus_status(state);
}
void gui_common_unfreeze_event_handler(LSH_EVENT_HANDLER_STATUS_T * state)
{
   printf_unfreeze_event_status(state);
}
#ifdef MATLAB_MEX_FILE
void initialize_hmi_view_manager_02(void * p_dpm_stack_P)
{
}
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
UINT32 hmi_lsh_start_animation(UINT32 p_priority, UINT32 p_state_id, UINT32 p_anim_id)
{
   if(p_state_id > 2)
   return(0);
   else
   return(1);
}

void hmi_lsh_stop_animation(UINT32 p_priority, UINT32 p_state_id, UINT32 p_anim_id)
{
}

#endif
#endif


