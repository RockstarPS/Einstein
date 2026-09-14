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
#include <WinBase.h>
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include <wchar.h>
#include <math.h>
#include "tmwtypes.h"
#include "hmi_bidi_algo.h"
#include "hmi_gfx_mgr02_image_data.h"

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
int l_gt_request = 0;
int option = 0;
int choice = 0;

GFX_MGR02_ILOC_DATA pos;
GFX_MGR02_TILE_DATA tile;
GFX_MGR02_IDIM_DATA dim;
GFX_MGR02_IAREA_DATA area;
GFX_MGR02_VCLIP_DATA clip;
float matrix[9];
/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

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
    MSG     msg;
		UINT8 scroll_offset = 0;
    UINT32  fl_prev_count = GetTickCount();
    UINT32  fl_cur_count;
    UINT32  fl_exec_count = 0, l_popup=0;

    fl_exec_count  = 1;

    SetTimer(NULL, 0, 32, GTTimerProc);

   
    hmi_gfx_mgr02_if_KSWakeUp();
    hmi_gfx_mgr02_if_start();

    DCU.DISP_SIZE.B.DELTA_X = 320/16;
    DCU.DISP_SIZE.B.DELTA_Y = 320;
    hmi_gfx_mgr02_if_enable_dcu();
    hmi_gfx02_dcu_sim_init(1);
 
	while(1)
	{
		if(kbhit())
		{
			char c = getch();
			switch(c)
			{
				case 27: 
					return;
				case 'a':
					/* Testing Static Image -All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGENONANIM1, 1);						 
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'b':
					/* Testing Static Image with Anim -All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGENONANIM2, 1);						 
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'c':
					/* Testing Static Image with Anim -All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIM1, 1);						 
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'd':
					/*  Testing Static Image with Anim -Offset All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIM1, 1);	
                    #ifdef GFX_MGR02_SET_ANIM_OFFSET_POSITION
					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_1BPP_NANIM_0_ANIM, 5);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_1BPP_NANIM_0_ANIM, 5);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_2BPP_NANIM_0_ANIM, 15);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_2BPP_NANIM_0_ANIM, 6);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_4BPP_NANIM_0_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_4BPP_NANIM_0_ANIM, 22);

					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_NANNIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_NANNIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_APAL_NANIM_0_ANIM, 11);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_APAL_NANIM_0_ANIM, 17);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_RGB5_NANIM_0_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_RGB5_NANIM_0_ANIM, 1);

					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_RGB8_NANIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_RGB8_NANIM_0_ANIM, 7);

					#endif
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'e':
					/* Testing Static Image with Anim -All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIM2, 1);						 
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'f':
					/*  Testing Static Image with Anim -Offse All properties */
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIM2, 1);	
                    #ifdef GFX_MGR02_SET_ANIM_OFFSET_POSITION
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_ARG15_NANIM_0_ANIM, 11);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_ARG15_NANIM_0_ANIM, 17);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_ARG8_NANIM_0_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_ARG8_NANIM_0_ANIM, 19);

					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_ARG8PRE_NANIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_ARG8PRE_NANIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_ALPHA_NANIM_0_ANIM, 11);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_ALPHA_NANIM_0_ANIM, 17);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_4BPP_ALPHA_NANIM_0_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_4BPP_ALPHA_NANIM_0_ANIM, 19);

					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_1BPP_ALPHANANIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_1BPP_ALPHANANIM_0_ANIM, 7);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_LUM_NANIM_0_ANIM, 11);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_LUM_NANIM_0_ANIM, 17);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_4BPP_LUM_NANIM_0_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_4BPP_LUM_NANIM_0_ANIM, 19);

					#endif
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
			   case 'g':
					/* Testing Static Image with animation TRUE using API */
				    hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIMRGB, 1);
					#ifndef GFX_MGR02_SET_ANIM_OFFSET_POSITION
					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_1_ANIM_ANIM, 63);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_1_ANIM_ANIM, 5);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_2_ALPHA_ANIM_ANIM, 65);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_2_ALPHA_ANIM_ANIM, 115);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 12);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 71);
                    #endif
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'h':
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIMRGB, 1);	
					/* Testing with offset position enabled */
					/* Perform this after executing the above test case */
					#ifdef GFX_MGR02_SET_ANIM_OFFSET_POSITION
					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_1_ANIM_ANIM, 53);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_1_ANIM_ANIM, 5);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_2_ALPHA_ANIM_ANIM, 15);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_2_ALPHA_ANIM_ANIM, 60);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 22);

					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_1_ANIM_ANIM, 30);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_1_ANIM_ANIM, 5);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_2_ALPHA_ANIM_ANIM, 15);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_2_ALPHA_ANIM_ANIM, 60);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 49);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 22);
					#endif
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'i':
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGEANIMRGB, 1);	
					/* Testing with offset position enabled */
					/* Perform this after executing the above test case */
					#ifdef GFX_MGR02_SET_ANIM_OFFSET_POSITION
					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_1_ANIM_ANIM, 200);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_1_ANIM_ANIM, 150);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_2_ALPHA_ANIM_ANIM, 187);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_2_ALPHA_ANIM_ANIM, 170);
				    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 200);
				    hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM, 100);
					#endif
					hmi_gfx_mgr02_if_set_obj_default_properties(GFX_SIMG_1_ANIM_ANIM);
					hmi_gfx_mgr02_if_set_obj_default_properties(GFX_SIMG_2_ALPHA_ANIM_ANIM);
					hmi_gfx_mgr02_if_set_obj_default_properties(GFX_SIMG_3_CLIP_OPEQ_ANIM_ANIM);
					 hmi_gfx_mgr02_if_set_obj_dim_h(GFX_FILL_NORMAL_1_ANIM, 40);
					 hmi_gfx_mgr02_if_set_obj_dim_w(GFX_FILL_NORMAL_1_ANIM, 60);
					 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_FILL_NORMAL_1_ANIM, 90);
					 hmi_gfx_mgr02_if_set_obj_pos_y(GFX_FILL_NORMAL_1_ANIM, 100);
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
			case 'j':
				   /* Testing Static Widget */
				   hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_SWDG, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 1);
				   hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SWDG_SIMAGE_ANIM, 20);
				   hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SWDG_SIMAGE_ANIM, 20);
					 hmi_gfx_mgr02_layout_get_obj_area(GFX_SWDG_SIMAGE_ANIM, &area);
				   area.x = 20;
				   area.y = 20;
				   area.height = 190;
				   area.width = 180;
				   hmi_gfx_mgr02_if_set_obj_area(GFX_SWDG_SIMAGE_ANIM, &area);
					 hmi_gfx_mgr02_if_set_obj_pos_y(GFX_DWDG_SWDG, 20);
					 clip.num_lines = 100;
				   clip.start_line = 50;
				   //hmi_gfx_mgr02_if_set_obj_vclip(GFX_SWDG_SIMAGE_ANIM,&clip);

					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
					break;
				case 'k':
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 0);
					hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 1);
				  //hmi_gfx_mgr02_if_set_obj_default_properties(GFX_SWDG_SIMAGE_ANIM, 1);
					hmi_gfx_mgr02_if_set_obj_pos_x(GFX_DWDG_SWDG_ANIM, 20);
				  hmi_gfx_mgr02_if_set_obj_pos_y(GFX_DWDG_SWDG_ANIM, 20);
						
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
				case 'l':
				   /* Testing Static Widget */
				   hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_SWDG, 1);
				   hmi_gfx_mgr02_if_select_dimage(GFX_IMG_DYN1, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 1);
				  hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_DYN1_ANIM, 100);
				  hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_DYN1_ANIM, 100);
					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
					break;
				case 'm':
				/* Testing Static Widget */
				   hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_SWDG, 1);
				   hmi_gfx_mgr02_if_select_dimage(GFX_IMG_DYN1, 1);
				   hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_DYN_2_ANIM, 30);
				   hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_DYN_2_ANIM, 30);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSWIDGET, 1);

					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;	
				case 'n':
				/* Testing Fill anim */
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGENONANIM1, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSIMAGENONANIM1, 1);
				   hmi_gfx_mgr02_layout_get_obj_area(GFX_FILL_NORMAL_ANIM, &area);
				   area.x = 50;
				   area.y = 50;
				   area.height = 100;
				   area.width = 100;
				   hmi_gfx_mgr02_if_set_obj_area(GFX_FILL_NORMAL_ANIM, &area);
					 hmi_gfx_mgr02_if_set_obj_dim_h(GFX_FILL_NORMAL_ANIM, 60);
					 hmi_gfx_mgr02_if_set_obj_dim_w(GFX_FILL_NORMAL_ANIM, 50);
					 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_FILL_NORMAL_ANIM, 100);
					 hmi_gfx_mgr02_if_set_obj_pos_y(GFX_FILL_NORMAL_ANIM, 100);

					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					    #if GFX_NUM_ANIMATIONS > 0
						hmi_gfx_anim_engine_tick();
						#endif
					}
				break;
        case 'q':
					/* Test static text */
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSTATICTEXT, 0);
				   hmi_gfx_mgr02_if_set_screen(GFX_SCR_TESTSTATICTEXT, 1);
					 #ifdef GFX_MGR02_SET_ANIM_OFFSET_POSITION
					 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_STEXT_NORMAL_ANIM, 30);
				   hmi_gfx_mgr02_if_set_obj_pos_y(GFX_STEXT_NORMAL_ANIM, -30);
           #else
					 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_STEXT_NORMAL_ANIM, 30);
				   hmi_gfx_mgr02_if_set_obj_pos_y(GFX_STEXT_NORMAL_ANIM, 60);
           #endif
   					fl_cur_count = GetTickCount();
					if((fl_cur_count-fl_prev_count) >= 33)
					{
						fl_prev_count += 33;
						hmi_gfx_mgr02_if_KSTimedTask();
					}
					break;
			}
		}
		else
		{
              MSG  msg;
              if(GetMessage(&msg, NULL, 0, 0))
              {
                  TranslateMessage(&msg);
                  DispatchMessage(&msg);
              }
		}
	}
   return(0);
}

#if GFX_MGR02_NUM_USER_LAYERS > 0
void hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{
	
	p_image_def->width = 50;
	p_image_def->height = 50;
	p_image_def->pixel_data = lc_img_gear_pos_d_data;
	p_image_def->format = GFX_MGR02_16BPP_RGB565;

		
}
#endif

void hmi_gfx_mgr02_render_user_layer(UINT32 p_base_id)
{
	
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

void hmi_presentation_task(void)
{
}

void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id)
{
   //hmi_gfx_anim_play_fwd(20, GFX_OFFSET_MOVEMENT);
}
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event)
{
}
#endif

/*============================================================================
 **
 **============================================================================
 ** C M S    R E V I S I O N    N O T E S
 **============================================================================
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.2
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
