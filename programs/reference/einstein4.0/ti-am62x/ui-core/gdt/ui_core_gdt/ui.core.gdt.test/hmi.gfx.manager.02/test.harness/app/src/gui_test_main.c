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
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include "user_nanim_argb8888.dat"
#include "user_anim_rgb565.dat"
#include "hmi_logic_state_handler.h"
#include <wchar.h>
#include <math.h>
#include "tmwtypes.h"
#include "hmi_bidi_algo.h"

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

void scr_ovg_presentation(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   static unsigned int counter = 0, time=0, fl_pos_x=76;
   
   counter++;

   if(counter >= (1000/32))
   {
	  time++;
	  counter=0;
   }

   if((counter % 15)==0)
   {
	  fl_pos_x++;
	  if(fl_pos_x >= 376)fl_pos_x=76;
   }
#if 0
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_OVG, 0);
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_USER_LAYER, 0);
   }
   else
   {
	 char pbuff[30];
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_OVG, 1);
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_USER_LAYER, 1);
	 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_TUNE_ARROW_ANIM, fl_pos_x);
	 sprintf(pbuff, "%d:%d", time/60, time%60);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_OVG, pbuff);
   }
#endif
}

#ifdef GFX_MGR02_MY2014_FORD_TVM_MFD
void hmi_gfx_mgr02_driver_dcu_isr(void)
{
   void * fbp1 = hmi_gfx_mgr02_context_swap_layer(0);

   if(fbp1!= 0)
   {
      DCU.LAYER[0].CTRLDESCL1.B.WIDTH   = 480;
      DCU.LAYER[0].CTRLDESCL1.B.HEIGHT	= 272;
      DCU.LAYER[0].CTRLDESCL4.B.BPP	    = GFX_MGR02_16BPP_RGB565;//GFX_MGR02_32BPP
      DCU.LAYER[0].CTRLDESCL3.R		    = fbp1;
      DCU.LAYER[0].CTRLDESCL4.B.TILE_EN = 0;
      DCU.LAYER[0].CTRLDESCL4.B.AB		= 0;
      DCU.LAYER[0].CTRLDESCL4.B.BB		= 0;
      DCU.LAYER[0].CTRLDESCL4.B.EN      = 1;
   }
}
#endif
int a1posx=131, a1posy=203, a2posx=-23, a2posy=48, a3posx=336, a3posy=101;

UINT32 hmi_gfx_anim_engine_user_defined_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_max_step);
}
UINT32 hello_handler(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_max_step);
}

UINT32 my_handler(UINT32 p_cur_step, UINT32 p_max_step)
{
   return(p_cur_step);
}

void my_present_scr(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
}

void scr_test_handler(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
//   hmi_gfx_mgr02_if_set_text(GFX_TEXT_MCOLOR1, L"White");
//   hmi_gfx_mgr02_if_set_text(GFX_TEXT_MCOLOR2, "Blue");
}

int l_power_distrib_scr_active = 1;
int l_p552_pow_ffill = 100;
int l_p552_pow_rfill = 100;
int l_p552_pow_anim  = 0;//__GFX_NUM_ANIMATIONS;

int hmi_anim_get_animation_type(void)
{
   return(l_p552_pow_anim);
}
int HmiHostRearPercentFill(void)
{
   return(l_p552_pow_rfill);
}
int HmiHostFrontPercentFill(void)
{
   return(l_p552_pow_ffill);
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
   MSG  msg;
   void * fbp1;
   void * fbp2;
   UINT32  fl_prev_count = GetTickCount();
   UINT32  fl_cur_count;
   UINT32  fl_exec_count = 0, l_popup=0;
   GFX_MGR02_VCLIP_DATA l_clip;

   l_clip.start_line = 0;//216;
   l_clip.num_lines  = 158;
   
   l_welcome_done = 0;
   fl_exec_count  = 1;

   SetTimer(NULL, 0, 32, GTTimerProc);
   hmi_gfx_mgr02_if_KSColdInit();
   hmi_lsh_initialize(1);
   hmi_gfx_mgr02_if_start();

#ifdef GFX_MGR02_NEWPROJECT
   DCU.DISP_SIZE.B.DELTA_X = 800 / 16;
   DCU.DISP_SIZE.B.DELTA_Y = 480;
   //hmi_gfx_mgr02_driver_startup();
   hmi_gfx_mgr02_if_enable_dcu();
   hmi_gfx02_dcu_sim_init(1);
#else
   DCU.DISP_SIZE.B.DELTA_X = 800 / 16;
   DCU.DISP_SIZE.B.DELTA_Y = 480;
   hmi_gfx02_dcu_sim_init(1);
   DCU.DCU_MODE.B.DCU_MODE = 1;
#endif
   
#ifdef GFX_MGR02_NEWPROJECT
   //LSH_ADD_STATE(GFX_SCR_CLIP_WIDGETS, GFX_ANIM_WELCOME);
   LSH_ADD_STATE(GFX_SCR_VG_FONT_TEST, 255);//GFX_VG_FNT_ANIM);
   //LSH_ADD_STATE(GFX_SCR_FONT_TEST, 255);
   //LSH_ADD_STATE(GFX_SCR_CLIP_WIDGETS, 255);
   //LSH_ADD_STATE(GFX_SCR_DCU_STARTUP, GFX_ANIM_WELCOME);
   //hmi_gfx_anim_play_rwd(GFX_SCR_EOL_RED, 1);
   //LSH_ADD_STATE(GFX_SCR_EOL_RED, 255);
   //LSH_ADD_STATE(GFX_SCR_DRIVE_COMPUTER, GFX_LEFT_LEVEL_MOVE);
   //LSH_ADD_STATE(GFX_SCR_MAL_ANIM, GFX_SCR_MAL);
   //LSH_ADD_STATE(GFX_SCR_POPUP, GFX_COMPASS_ROATATION);
   //LSH_ADD_STATE(GFX_SCR_DCU_POPUP, GFX_MAP_ANIM);
   //LSH_ADD_STATE(GFX_SCR_TACHOMETER, GFX_NISSAN_W02_ANIM);
   //LSH_ADD_STATE(GFX_SCR_MULTI_COLOR, 255);
{
   GFX_MGR02_IAREA_DATA fl_area;
   hmi_gfx_mgr02_layout_get_obj_area(GFX_WDG_NISSAN_CLIP2_ANIM, &fl_area);
   fl_area.width = 384;
   hmi_gfx_mgr02_layout_set_obj_area(GFX_WDG_NISSAN_CLIP2_ANIM, &fl_area);
}
   //LSH_ADD_STATE(GFX_SCR_NISSAN_TEST, GFX_NISSAN_ANIM);
#elif defined(GFX_MGR02_P552_L2)
   LSH_ADD_STATE(GFX_SCR_POWER_DISTRIBUTION, 255);
   LSH_ADD_STATE(GFX_SCR_MAIN_MENU, 255);
   LSH_ADD_STATE(GFX_SCR_SST, 255);
   LSH_ADD_STATE(GFX_SCR_GEAR_POS, 255);
   LSH_ADD_STATE(GFX_SCR_ODO, 255);
   LSH_ADD_STATE(GFX_SCR_RTT, 255);
#elif defined(GFX_MGR02_DCU_SIMPLE_1)
   LSH_ADD_STATE(GFX_DCU_T_TEST, 255);
#else
   LSH_ADD_STATE(GFX_SCR_AMFM_BASE, 255);
#endif
   
   while(l_preset_num < 7)	  
      while(1)
	  {
	     if(kbhit())
		 {
		    switch(getch())
			{
            #ifdef GFX_MGR02_MY2014_FORD_TVM_MFD
			case '1':l_preset_num=1;break;
			case '2':l_preset_num=2;break;
			case '3':l_preset_num=3;break;
			case '4':l_preset_num=4;break;
			case '5':l_preset_num=5;break;
			case '6':l_preset_num=6;break;
			case '+':if(l_popup == 0)
			         {
			            l_scroll_bar++;
			         }
					 else
					 {
						l_posx++;
						if(l_posx > 395)l_posx=395;
					 }
					 l_scale += 0.01;
			         break;
			case '-':if(l_popup == 0)
			         {
			            l_scroll_bar--;
			         }
					 else
					 {
						l_posx--;
						if(l_posx < 85)l_posx=85;
					 }
					 l_scale -= 0.01;
			         break;
			case 'h':l_header_layout++;break;
			case 't':l_time++;break;
			case 'a':l_scroll_bar++;l_preset_num++;l_header_layout++;l_time++;break;
			case 'p':if(l_popup == 0){LSH_ADD_STATE(GFX_SCR_D4_TAB,255);l_popup=1;}
			         else    		 {LSH_REM_STATE(GFX_SCR_D4_TAB,255);l_popup=0;}
					 break;
			#else
			case 'q':a1posx++;break;
			case 'a':a1posx--;break;
			case 'w':a1posy++;break;
			case 's':a1posy--;break;
			case 'e':a2posx++;break;
			case 'd':a2posx--;break;
			case 'r':a2posy++;break;
			case 'f':a2posy--;break;
			case 't':a3posx++;break;
			case 'g':a3posx--;break;
			case 'y':a3posy++;break;
			case 'h':a3posy--;break;
			case '-':
			{
			   l_clip.num_lines--;
			   l_p552_pow_ffill--;if(l_p552_pow_ffill<0)l_p552_pow_ffill=0;
			   l_p552_pow_rfill--;if(l_p552_pow_rfill<0)l_p552_pow_rfill=0;
			   //hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_FRONT_ANIM, &l_clip);
			   break;
			}
			case '+':
			{
			   l_p552_pow_ffill++;if(l_p552_pow_ffill>100)l_p552_pow_ffill=100;
			   l_p552_pow_rfill++;if(l_p552_pow_rfill>100)l_p552_pow_rfill=100;
			   l_clip.num_lines++;
			   //hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_FRONT_ANIM, &l_clip);
			   break;
			}
			case '*':
			{
			   l_clip.start_line--;
			   //hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_FRONT_ANIM, &l_clip);
			   break;
			}
			case '9':
			{
			   l_clip.start_line++;
			   l_power_distrib_scr_active++;l_power_distrib_scr_active &= 1;
			   //hmi_gfx_mgr02_if_set_obj_vclip(GFX_WDG_PD_FRONT_ANIM, &l_clip);
			   break;
			}
            #endif
			case  27:l_preset_num = 10;break;
			}
		 }
	     if(l_welcome_done)
		 {
	        fl_exec_count++;
		 }
	     fl_cur_count = GetTickCount();
	     if((fl_cur_count-fl_prev_count) >= 33)
		 {
			 fl_prev_count += 33;
             hmi_gfx_mgr02_if_KSTimedTask();
			 break;
		 }
		 if((fl_exec_count % (8000/33)) == 0)
		 {
            //hmi_gfx_anim_play_rwd(GFX_SCR_DCU_STARTUP, GFX_ANIM_WELCOME);
			//LSH_ADD_STATE(GFX_SCR_DCU_POPUP, 0xFFFF);
		 }
         if(GetMessage(&msg, NULL, 0, 0))
         {
           TranslateMessage(&msg);
           DispatchMessage(&msg);
         }
	  }

   return(0);
}

UINT32 hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{
   switch(p_base_id)
   {
#ifdef GFX_MGR02_NEWPROJECT
      case 0:
	  {
		 static void * fb_ptr = 0;
		 void * cur_fb = hmi_gfx_mgr02_context_swap_layer(1);
		 if(cur_fb != 0)
		 {
			fb_ptr = cur_fb;
		 }
		 p_image_def->format	  = GFX_MGR02_32BPP;
		 p_image_def->width		  = 480;
		 p_image_def->height	  = 272;
		 p_image_def->pixel_data  = fb_ptr;
	  }
	  break;
#elif defined(GFX_MGR02_P552_L2)

#elif !defined(GFX_MGR02_DCU_SIMPLE_1)
	  case GFX_IMG_UTYPE_ANIM_BASEID:
	  {
		 p_image_def->format	  = VG_sARGB_8888;
		 p_image_def->width		  = 60;
		 p_image_def->height	  = 30;
		 p_image_def->pixel_data  = (void *)&lc_user_nanim_argb8888_data[0];
	  }
	  break;
	  case GFX_IMG_UTYPE_NANIM_BASEID:
	  {
		 p_image_def->format	  = VG_sRGB_565;
		 p_image_def->width		  = 80;
		 p_image_def->height	  = 40;
		 p_image_def->pixel_data  = (void *)&lc_user_anim_rgb565_data[0];
	  }
	  break;
#endif
	  default:
	  {
		 p_image_def->width		  = 0;
		 p_image_def->height	  = 0;
		 p_image_def->pixel_data  = 0;
	  }
	  break;
   }
   return TRUE;
}

void hmi_gfx_mgr02_render_user_layer(UINT32 p_base_id)
{
   switch(p_base_id)
   {

	  case 0:
	  {
	  }
	  break;
	  case 1:
	  {
	  }
	  break;
   }
}

#ifdef GFX_MGR02_NEWPROJECT
void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event)
{
   UINT32 p_touch_event = GFX_MGR02_GET_MOUSE_EV(p_event->event);
   UINT32 p_touch_event_gone_ouside_bounds = GFX_MGR02_IS_MOUSE_OUTSIDE_BOUND(p_event->event);
   printf("Touch Event %d on Element %d X=%d, Y=%d, Valid=%d\n", p_touch_event, p_obj_id, p_event->x, p_event->y, p_touch_event_gone_ouside_bounds);
   LSH_REM_STATE(GFX_SCR_DCU_POPUP, ANIM_MAX_ID);
}
#endif

void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id)
{
#ifdef GFX_MGR02_NEWPROJECT
   printf("Animation %d Completed\n", p_anim_id);
   if(p_anim_id == GFX_ANIM_WELCOME)
   {
	  l_welcome_done = 1;
   }
#endif
}

void hmi_anim_1_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
   printf("Anim callback CurFrame=%d, TotFrames=%d\n", p_cur_frame, p_total_frames);
}

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

void hmi_scr_dcu_startup_presentation(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
}

void scr_popup_pres(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      float fl_matrix_1[9];
      float fl_cur_angle = 1.0;

      fl_cur_angle *= 3.141592654f;
      fl_cur_angle /=180.0f;

      fl_matrix_1[0] = cosf(fl_cur_angle);
      fl_matrix_1[1] = sinf(fl_cur_angle);
      fl_matrix_1[2] = 0;
      fl_matrix_1[3] = -fl_matrix_1[1];
      fl_matrix_1[4] = fl_matrix_1[0];
      fl_matrix_1[5] = 0;
      fl_matrix_1[6] = 0;
      fl_matrix_1[7] = 0;
      fl_matrix_1[8] = 1;

	  hmi_gfx_mgr02_if_mul_obj_transformation(GFX_IMG_COMPASS_ANIM, fl_matrix_1);
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

void dcu_t_test_present(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_DCU_SIMPLE_1
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(GFX_DCU_T_TEST, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(GFX_DCU_T_TEST, 1);
   }
#endif
}

void hmi_scr_gfont_pres(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
   /* GFX_TXT_FONT_TEST5*/
	   static UINT16 const lcarabic1[] = {0x639, 0x648, 0x62F, 0x629, 0x20, 0x644, 0x625, 0x639, 0x62F, 0x627, 0x62F, 0x20, 0x627, 0x644, 0x645, 0x635, 0x646, 0x639, 0x00};
   /* GFX_TXT_FONT_TEST6*/
	   static UINT16 const lcarabic2[] = {0x625, 0x632, 0x627, 0x644, 0x629, 0x20, 0x627, 0x644, 0x635, 0x642, 0x64A, 0x639, 0x20, 0x62E, 0x644, 0x641, 0x64A, 0x00};
	   UINT16 larabic[50];

	  if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	  {
		 a1posx = a1posy = 0;
	  }
	  else
	  {
         hmi_gfx_mgr02_layout_select_gfont_index(GFX_MGR02_FONT_ID_NEW_FONTS_3, a1posx, a1posy);
	  }
	  memcpy(larabic,lcarabic1, sizeof(lcarabic1));
      bidi_process(larabic , (sizeof(lcarabic1)/2)-1);
	  hmi_gfx_mgr02_if_set_text(GFX_TXT_FONT_TEST4,  larabic);
	  hmi_gfx_mgr02_if_set_text(GFX_TXT_FONT_TEST6,  larabic);
	  memcpy(larabic,lcarabic2, sizeof(lcarabic2));
      bidi_process(larabic , (sizeof(lcarabic2)/2)-1);
	  hmi_gfx_mgr02_if_set_text(GFX_TXT_FONT_TEST3,  larabic);
	  hmi_gfx_mgr02_if_set_text(GFX_TXT_FONT_TEST5,  larabic);
	  hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

void hmi_scr_vgfont_pres(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

void dyn_area_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
#ifdef GFX_MGR02_NEWPROJECT
   extern GFX_ANIM_AREA_T l_new_area_1_ddata_S;
   if(p_cur_frame == 0)
   {
	  l_new_area_1_ddata_S.end.x = 50;
	  l_new_area_1_ddata_S.end.y = 50;
	  l_new_area_1_ddata_S.end.w = -100;
	  l_new_area_1_ddata_S.end.h = 0;
   }
#endif
}


void dyn_mal_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
#ifdef GFX_MGR02_NEWPROJECT
   extern GFX_ANIM_MAL_T l_dyn_mal_ddata_S;
   if(p_cur_frame == 0)
   {
	  l_dyn_mal_ddata_S.end.x = 100;
	  l_dyn_mal_ddata_S.end.y = 0;
   }
#endif
}

void ddata_anim_pres(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}
void hmi_scr_clip_widgets_pres(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   GFX_MGR02_ILOC_DATA pos;

   hmi_gfx_mgr02_if_set_text(GFX_TXT_ROOT_CLIP,  L"RCLIP");
   hmi_gfx_mgr02_if_set_text(GFX_TXT_ROOT_CLIPA, L"RCLIP_A");
   hmi_gfx_mgr02_if_set_text(GFX_TXT_ROOT_CLIP_0, L"Amid");
   hmi_gfx_mgr02_if_set_text(GFX_TXT_SVG_FONT, L"Hello Svg");
   
   hmi_gfx_mgr02_layout_get_obj_pos(GFX_WDG_CHILD_CLIP2_ANIM, &pos);
   if(pos.x != a3posx)
   {
   	  pos.x = a3posx;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_WDG_CHILD_CLIP2_ANIM, &pos);
      printf("GFX_WDG_ROOT_OVG_ANIM POS = %d,%d\n", pos.x, pos.y);
   }
   if(pos.y != a3posy)
   {
   	  pos.y = a3posy;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_WDG_CHILD_CLIP2_ANIM, &pos);
      printf("GFX_WDG_ROOT_OVG_ANIM POS = %d,%d\n", pos.x, pos.y);
   }

   hmi_gfx_mgr02_layout_get_obj_pos(GFX_WDG_CHILD_OVG_ANIM, &pos);
   if(pos.x != a1posx)
   {
   	  pos.x = a1posx;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_WDG_CHILD_OVG_ANIM, &pos);
      printf("GFX_WDG_CHILD_OVG_ANIM POS = %d,%d\n", pos.x, pos.y);
   }
   if(pos.y != a1posy)
   {
   	  pos.y = a1posy;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_WDG_CHILD_OVG_ANIM, &pos);
      printf("GFX_WDG_CHILD_OVG_ANIM POS = %d,%d\n", pos.x, pos.y);
   }
   hmi_gfx_mgr02_layout_get_obj_pos(GFX_IMG_CHILD_CLIP_0_ANIM, &pos);
   if(pos.x != a2posx)
   {
   	  pos.x = a2posx;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_IMG_CHILD_CLIP_0_ANIM, &pos);
      printf("GFX_IMG_CHILD_CLIP_0_ANIM POS = %d,%d\n", pos.x, pos.y);
   }
   if(pos.y != a2posy)
   {
   	  pos.y = a2posy;
      hmi_gfx_mgr02_if_set_obj_pos(GFX_IMG_CHILD_CLIP_0_ANIM, &pos);
      printf("GFX_IMG_CHILD_CLIP_0_ANIM POS = %d,%d\n", pos.x, pos.y);
   }

   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

void hmi_scr_dcu_base_presentation(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      printf("hmi_scr_dcu_base_presentation - LSH_DEACTIVATED_STATUS\n");
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      printf("hmi_scr_dcu_base_presentation - %d\n", p_presen_hndl_status_SP->presentation_status);
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

UINT32 check_cond(UINT32 p_cur_step)
{
	static int count = 0;
	printf("check_cond step = %d\n", p_cur_step);
	if(count > 10)
	{
		return 255;
	}
	else
	{
		count++;
		return 0;
	}
}

void hmi_scr_dcu_popup_presentation(LSH_PRESN_HANDLER_STATUS_T * p_presen_hndl_status_SP)
{
#ifdef GFX_MGR02_NEWPROJECT
   if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      printf("hmi_scr_dcu_popup_presentation - LSH_DEACTIVATED_STATUS\n");
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
      printf("hmi_scr_dcu_popup_presentation - %d\n", p_presen_hndl_status_SP->presentation_status);
      hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
   }
#endif
}

UINT32 goto_check_function(UINT32 p_cur_step)
{
	return 255;
}

#ifdef GFX_MGR02_MY2014_FORD_TVM_MFD

UINT8 hmi_menu_app_submenu_buttonevent_deviation_process(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){return 0;}
UINT8 hmi_menu_app_buttonevent_deviation_process(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){return 0;}
UINT8 hmi_menu_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){return 0;}
UINT8 hmi_popup_core_layer1_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){return 0;}
UINT8 hmi_popup_core_layer0_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){return 0;}
void hmi_menu_set_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP){}
void hmi_popup_core_layer1_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP){}
void hmi_popup_core_layer0_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP){}
void scr_header_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){}
void scr_footer_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){}
void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){}
void hmi_popup_core_layer1_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){}
void hmi_popup_core_layer0_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){}


void hmi_popup_core_layer11_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer11_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer11_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer23_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer23_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer23_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer16_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer16_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer16_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer8_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer8_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer8_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer3_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
   if(p_presn_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_D4_TAB, 0);
   }
   else
   {
	 HMI_CHAR pbuff[30];												  
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_D4_TAB, 1);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M05_TAB, 1);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M05_C1,L"Manual");
     hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_G156_ANIM, l_posx);
	 switch(l_posx)
	 {
		case 85:hmi_gfx_mgr02_if_set_text(GFX_TXT_D4_H2,L"SURYAN");break;
		case 95:hmi_gfx_mgr02_if_set_text(GFX_TXT_D4_H2,L"BIG FM");break;
		case 105:hmi_gfx_mgr02_if_set_text(GFX_TXT_D4_H2,L"HIT FM");break;
		default:hmi_gfx_mgr02_if_set_text(GFX_TXT_D4_H2,L" ");break;
	 }
     swprintf(pbuff, sizeof(pbuff)/2, L"%d Mhz", l_posx);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_D4_C1,pbuff);
   }
}
void hmi_popup_core_layer3_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer3_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer6_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer6_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer6_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer10_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer10_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer10_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void hmi_popup_core_layer21_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
void hmi_popup_core_layer21_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 hmi_popup_core_layer21_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
void gui_basescreen_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
   if(p_presn_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_AMFM_BASE, 0);
   }
   else
   {
	 HMI_CHAR pbuff[30];
#if 0
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_ROOT_LIST, 1);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_B0_C1, L"Line 1");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_B0_C2, L"Line 1");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_B0_C3, L"Line 1");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_B0_C4, L"Line 1");
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_G1, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_G2, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_G3, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_G4, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_A1, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_A2, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_A3, 0);
	 hmi_gfx_mgr02_if_select_dimage(GFX_IMG_B0_A4, 0);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_WDG_ROOT_WINDOW, 0);
#else
	 hmi_gfx_mgr02_if_set_screen(GFX_SCR_AMFM_BASE, 1);
	 //hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_TUNE_ARROW_ANIM, fl_pos_x);
     swprintf(pbuff, sizeof(pbuff)/2, L"SURYAN%d", l_posx);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_A2B_C1, pbuff);
     swprintf(pbuff, sizeof(pbuff)/2, L"Preset %d", l_preset_num);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_A2B_C2, pbuff);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_A2B_C3, L"AF");
	 if(l_scroll_bar < 0)l_scroll_bar=55;
	 else if(l_scroll_bar > 55)l_scroll_bar=0;
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M03B_A2B_SCROLLBAR, l_scroll_bar);
	 if(l_header_layout > 3)l_header_layout=0;
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M08K_HEADER, l_header_layout);
     swprintf(pbuff, sizeof(pbuff)/2, L"%d:%02d", l_time/60, l_time%60);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M08_H1, pbuff);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M04_SOFTKEY_1, 0);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M04_SOFTKEY_2, 0);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M04_SOFTKEY_3, 0);
	 hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_M04_SOFTKEY_4, 0);
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M04A_S1_C1, L"--");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M04A_S2_C1, L"Manuel");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M04A_S3_C1, L"--");
	 hmi_gfx_mgr02_if_set_text(GFX_TXT_M04A_S4_C1, L"--");
#endif
   }
}
void gui_basescreen_focus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
}
UINT8 gui_basescreen_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  return 0;
}
#endif /* GFX_MGR02_MY2014_FORD_TVM_MFD */

void ui_menu_bar_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
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
