/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           gfx_default_handler.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_DEFAULT_HANDLER_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_cfg.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define START_ANIM_COMMAND                            (LSH_GET_COMMAND(ButtonID_OK,    ButtonState_Pressed))
#define STOP_ANIM_COMMAND                             (LSH_GET_COMMAND(ButtonID_RIGHT, ButtonState_Pressed))
#define RESET_ANIM_COMMAND                            (LSH_GET_COMMAND(ButtonID_DOWN,  ButtonState_Pressed))

#define GFX_SCN_SPLASH_ACTIVATE                       (LSH_GET_COMMAND(ButtonID_A,     ButtonState_Pressed))
#define GFX_SCN_TEXT_DIFF_BPP_ACTIVATE                (LSH_GET_COMMAND(ButtonID_S,     ButtonState_Pressed))
#define GFX_SCN_WIDGET_TEXT_ACTIVATE                  (LSH_GET_COMMAND(ButtonID_D,     ButtonState_Pressed))
#define GFX_SCN_WIDGET_IMAGE_TEST_ACTIVATE            (LSH_GET_COMMAND(ButtonID_F,     ButtonState_Pressed))
#define GFX_SCN_ODO_TEST_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_G,     ButtonState_Pressed))
#define GFX_SCN_WDGT_4BPP_BMP_ACTIVATE                (LSH_GET_COMMAND(ButtonID_H,     ButtonState_Pressed))
#define GFX_SCN_WDGT_RACE_LIGHTS_ACTIVATE             (LSH_GET_COMMAND(ButtonID_J,     ButtonState_Pressed))
#define GFX_SCN_32BPP_BMP_ACTIVATE                    (LSH_GET_COMMAND(ButtonID_K,     ButtonState_Pressed))
#define GFX_SCN_24BPP_BMP_ACTIVATE                    (LSH_GET_COMMAND(ButtonID_L,     ButtonState_Pressed))
#define GFX_SCN_RGB565_BMP_ACTIVATE                   (LSH_GET_COMMAND(ButtonID_Q,     ButtonState_Pressed))
#define GFX_SCN_8BPP_BMP_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_W,     ButtonState_Pressed))
#define GFX_SCN_ARGB1555_BMP_ACTIVATE                 (LSH_GET_COMMAND(ButtonID_E,     ButtonState_Pressed))
#define GFX_SCN_ARGB4444_BMP_ACTIVATE                 (LSH_GET_COMMAND(ButtonID_R,     ButtonState_Pressed))
#define GFX_SCN_4BPP_BMP_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_T,     ButtonState_Pressed))
#define GFX_SCN_2BPP_BMP_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_Y,     ButtonState_Pressed))
#define GFX_SCN_1BPP_BMP_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_U,     ButtonState_Pressed))
#define GFX_SCN_RGB565_BMP_CHROMA_ACTIVATE            (LSH_GET_COMMAND(ButtonID_I,     ButtonState_Pressed))
#define GFX_SCN_8BPP_SMILEY_ACTIVATE                  (LSH_GET_COMMAND(ButtonID_O,     ButtonState_Pressed))
#define GFX_SCN_8BPP_SMILEY_TILE_ON_400_272_ACTIVATE  (LSH_GET_COMMAND(ButtonID_P,     ButtonState_Pressed))
#define GFX_SCN_8BPP_ALPHA_MAP_ACTIVATE               (LSH_GET_COMMAND(ButtonID_Z,     ButtonState_Pressed))
#define GFX_SCN_4BPP_ALPHA_MAP_ACTIVATE               (LSH_GET_COMMAND(ButtonID_X,     ButtonState_Pressed))
#define GFX_SCN_WIDGET_4BPP_BMPS_ACTIVATE             (LSH_GET_COMMAND(ButtonID_C,     ButtonState_Pressed))
#define GFX_SCN_OPENVG_TEST_ACTIVATE                  (LSH_GET_COMMAND(ButtonID_V,     ButtonState_Pressed))
#define GFX_ALL_SCREENS_TEST_ACTIVATE                 (LSH_GET_COMMAND(ButtonID_B,     ButtonState_Pressed))
#define GFX_SCN_EOL_TEST_ACTIVATE                     (LSH_GET_COMMAND(ButtonID_1,     ButtonState_Pressed))
#define GFX_SCN_VISIBLE_LAYER1_ACTIVATE               (LSH_GET_COMMAND(ButtonID_2,     ButtonState_Pressed))
#define GFX_SCN_VISIBLE_LAYER2_ACTIVATE               (LSH_GET_COMMAND(ButtonID_3,     ButtonState_Pressed))
#define GFX_SCN_VISIBLE_LAYER_ACTIVATE                (LSH_GET_COMMAND(ButtonID_4,     ButtonState_Pressed))
#define GFX_SCN_TRIP_A_ACTIVATE                       (LSH_GET_COMMAND(ButtonID_5,     ButtonState_Pressed))
#define GFX_SCN_TRIP_B_ACTIVATE                       (LSH_GET_COMMAND(ButtonID_6,     ButtonState_Pressed))
#define GFX_SCN_MAIN_STATUS_ACTIVATE                  (LSH_GET_COMMAND(ButtonID_7,     ButtonState_Pressed))

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
static GFX_MGR02_SCR_ELEM_ID l_current_screen = GFX_SCN_FILL_NON_ANIM;
static GFX_MGR02_SCR_ELEM_ID l_next_screen    = GFX_SCN_FILL_NON_ANIM;
static UINT8 l_all_screen_test = 0;
/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
void hmi_logic_trans_into_run(void)
{
   printf("hmi_lsh_add_state(GFX_NEW_SCREENS_1)\n");
   l_current_screen = GFX_SCN_FILL_NON_ANIM;
   l_next_screen    = GFX_SCN_FILL_NON_ANIM;
   hmi_lsh_add_state(GFX_SCN_FILL_NON_ANIM);
}

/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
void hmi_logic_trans_outof_run(void)
{
   printf("hmi_lsh_remove_state(GFX_NEW_SCREENS_1)\n");
   hmi_lsh_remove_state(GFX_SCN_FILL_NON_ANIM);
}

/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
void hmi_update_current_screen(GFX_MGR02_SCR_ELEM_ID p_current_screen)
{
   l_current_screen = p_current_screen;
}
UINT8 l_screen_presenation_complete = 1;
static UINT16 pre_button_cmd = 0;
/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
   UINT8 fl_all_screen_test_abort = 0;
   #if !defined(WIN32)
   if(l_screen_presenation_complete == 1)
   {
        if(l_next_screen == GFX_SCN_FILL_NON_ANIM)
        {
           l_next_screen = GFX_SCN_TEXT_DIFF_BPP;
        }
        else
        {
           l_next_screen++;
        }
        hmi_lsh_remove_state(l_current_screen);
        hmi_lsh_add_state(l_next_screen);
        l_current_screen = l_next_screen;
        l_screen_presenation_complete = 0;
   }
   #else
   printf("hmi_lsh_default_button_event_handler()\n");
   switch(p_event_hndl_status_SP->button_command)
   {
     case GFX_SCN_SPLASH_ACTIVATE:
       l_next_screen = GFX_SCN_SPLASH_ANIM;
       break;
     case GFX_SCN_TEXT_DIFF_BPP_ACTIVATE:
       l_next_screen = GFX_SCN_TEXT_DIFF_BPP;
       break;
     case GFX_SCN_WIDGET_TEXT_ACTIVATE:
       l_next_screen = GFX_SCN_WIDGET_TEXT;
       break;
     case GFX_SCN_WIDGET_IMAGE_TEST_ACTIVATE:
       l_next_screen = GFX_SCN_WIDGET_IMAGE_TEST;
       break;
     case GFX_SCN_ODO_TEST_ACTIVATE:
       l_next_screen = GFX_SCN_ODO_TEST;
       break;
     case GFX_SCN_WDGT_4BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_WDGT_4BPP_BMP;
       break;
     case GFX_SCN_WDGT_RACE_LIGHTS_ACTIVATE:
       l_next_screen = GFX_SCN_WDGT_RACE_LIGHTS;
       break;
     case GFX_SCN_32BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_32BPP_BMP;
       break;
     case GFX_SCN_24BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_24BPP_BMP;
       break;
     case GFX_SCN_RGB565_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_RGB565_BMP;
       break;
     case GFX_SCN_8BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_8BPP_BMP;
       break;
     case GFX_SCN_ARGB1555_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_ARGB1555_BMP;
       break;
     case GFX_SCN_ARGB4444_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_ARGB4444_BMP;
       break;
     case GFX_SCN_4BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_4BPP_BMP;
       break;
     case GFX_SCN_2BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_2BPP_BMP;
       break;
     case GFX_SCN_1BPP_BMP_ACTIVATE:
       l_next_screen = GFX_SCN_1BPP_BMP;
       break;
     case GFX_SCN_RGB565_BMP_CHROMA_ACTIVATE:
       l_next_screen = GFX_SCN_RGB565_BMP_CHROMA;
       break;
     case GFX_SCN_8BPP_SMILEY_ACTIVATE:
       l_next_screen = GFX_SCN_8BPP_SMILEY;
       break;
     case GFX_SCN_8BPP_SMILEY_TILE_ON_400_272_ACTIVATE:
       l_next_screen = GFX_SCN_8BPP_SMILEY_TILE_ON_400_272;
       break;
     case GFX_SCN_8BPP_ALPHA_MAP_ACTIVATE:
       l_next_screen = GFX_SCN_8BPP_ALPHA_MAP;
       break;
     case GFX_SCN_4BPP_ALPHA_MAP_ACTIVATE:
       l_next_screen = GFX_SCN_4BPP_ALPHA_MAP;
       break;
     case GFX_SCN_WIDGET_4BPP_BMPS_ACTIVATE:
       l_next_screen = GFX_SCN_WIDGET_4BPP_BMPS;
       break;
     case GFX_SCN_OPENVG_TEST_ACTIVATE:
//       l_next_screen = GFX_SCN_OPENVG_TEST;
       break;
     case GFX_SCN_EOL_TEST_ACTIVATE:
     l_next_screen = GFX_SCN_ENGINEERING_TEST_MODE;     
     break;
     case GFX_SCN_VISIBLE_LAYER1_ACTIVATE:
       l_next_screen = GFX_LAYER_VISIBILITY1;
     break;
     case GFX_SCN_VISIBLE_LAYER2_ACTIVATE:
       l_next_screen = GFX_LAYER_VISIBILITY2;
     break;
     case GFX_SCN_VISIBLE_LAYER_ACTIVATE:
       l_next_screen = GFX_NEW_SCREENS_1;
     break;
     case GFX_SCN_TRIP_A_ACTIVATE:
      l_next_screen = GFX_SCN_TRIP_A;
      break;
     case GFX_SCN_TRIP_B_ACTIVATE:l_next_screen = GFX_SCN_TRIP_B;break;
     case GFX_SCN_MAIN_STATUS_ACTIVATE:l_next_screen = GFX_SCN_MAIN_STATUS;break;
     case GFX_ALL_SCREENS_TEST_ACTIVATE:
       l_next_screen = GFX_SCN_SPLASH_ANIM;
       fl_all_screen_test_abort = 0;
       break;
       default:
       fl_all_screen_test_abort = 0;
       break;
   }
   if(fl_all_screen_test_abort == 2)
   {
      l_all_screen_test = 1;
   }
   else if(fl_all_screen_test_abort == 1)
   {
     l_all_screen_test = 0;
   } else {}
   if(l_next_screen != l_current_screen)
   {
      UINT32 fl_animation_command;
      hmi_lsh_remove_state(l_current_screen);
      hmi_lsh_add_state(l_next_screen);
      l_current_screen = l_next_screen;
   }
   #endif
   return(LSH_STATUS_ABSORBED);
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
** CMS Rev 01       20-Feb-2013  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

