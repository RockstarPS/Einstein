/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
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
** Name:           gfx_scn_splash_anim_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_DIMAGE_PRESENTATION_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_anim_engine_cfg.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
UINT8 l_dimage_count = 0;
UINT8 cmd_step = 0;
UINT8 l_wait_count = 0;
UINT16 l_posx = 0, l_posy = 0;
GFX_MGR02_ILOC_DATA l_wdgt1_pos, l_wdgt2_pos, l_wdgt3_pos, l_wdgt_dyn_pos;
GFX_MGR02_ILOC_DATA l_widgt1_offset, l_widgt2_offset, l_widgt3_offset, l_wdgt_dyn_offset_pos;
extern UINT8 l_screen_presenation_complete;
#if !defined(WIN32)
static UINT8 l_anim_present = 0;
#endif
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
void scn_dimage_presnt_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    UINT32 fl_animation_command;
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         l_widgt1_offset.x = l_widgt2_offset.x = l_widgt3_offset.x = 0;
         l_widgt1_offset.y = l_widgt2_offset.y = l_widgt3_offset.y = 0;
         l_wdgt_dyn_offset_pos.x =0; l_wdgt_dyn_offset_pos.y=0;
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_SPLASH_ANIM, 1);
         hmi_gfx_mgr02_if_set_text(GFX_CMD_EXECUTION, L"Splash Screen Presentation");
         hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Element");
         #if defined(GFX_MGR02_ANIM_DIMAGE_TEST)
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SCN_SPLASH_ANIM_ANIM, 0);
         hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SCN_SPLASH_ANIM_ANIM, 0);
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SPLASH_SCREEN_CONTAINER_ANIM, 0);
         hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SPLASH_SCREEN_CONTAINER_ANIM, 0);
         hmi_gfx_mgr02_if_set_obj_default_properties(GFX_TEST_DYN_ANIM_WDGT_ANIM);
         hmi_gfx_mgr02_if_get_obj_pos(GFX_TEST_DYN_ANIM_WDGT_ANIM, &l_wdgt_dyn_pos);
         hmi_gfx_mgr02_if_select_dimage(GFX_SPLASH_SCREEN_CONTAINER, 0);
         hmi_gfx_mgr02_if_set_obj_default_properties(GFX_TEST_WIDGET_ANIM);
         hmi_gfx_mgr02_if_set_obj_default_properties(GFX_WDGT_TEST_L1_ANIM);
         hmi_gfx_mgr02_if_set_obj_default_properties(GFX_NEW_WIDGETS_23_ANIM);
         hmi_gfx_mgr02_if_get_obj_pos(GFX_TEST_WIDGET_ANIM, &l_wdgt1_pos);
         hmi_gfx_mgr02_if_get_obj_pos(GFX_WDGT_TEST_L1_ANIM, &l_wdgt2_pos);
         hmi_gfx_mgr02_if_get_obj_pos(GFX_NEW_WIDGETS_23_ANIM, &l_wdgt3_pos);
         l_widgt2_offset.x = -l_wdgt2_pos.x;
         l_widgt2_offset.y = -l_wdgt2_pos.y;
         l_widgt3_offset.x = -l_wdgt3_pos.x;
         l_widgt3_offset.y = -l_wdgt3_pos.y;
         l_wait_count = 0;
         l_dimage_count = 0;
         fl_animation_command = GFX_ANIM_PLAY;
         fl_animation_command |= ((UINT32)GFX_SCREEN_DIMAGE_ANIMATION << 16);
         hmi_gfx_anim_play(0, fl_animation_command);
         #endif
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_SPLASH_ANIM, 1);
         #if defined(GFX_MGR02_ANIM_DIMAGE_TEST)
        if(cmd_step == 1)
            {
        l_widgt1_offset.x++;
        l_widgt2_offset.x++;
        l_widgt3_offset.x++;
        //l_wdgt_dyn_offset_pos.x++;
        hmi_gfx_mgr02_if_set_obj_pos_x(GFX_TEST_WIDGET_ANIM, l_wdgt1_pos.x + l_widgt1_offset.x);
        hmi_gfx_mgr02_if_set_obj_pos_x(GFX_TEST_DYN_ANIM_WDGT_ANIM, l_wdgt1_pos.x + l_wdgt_dyn_offset_pos.x);
        //hmi_gfx_mgr02_if_set_obj_pos_y(GFX_WDGT_TEST_L1_ANIM, 0);
        hmi_gfx_mgr02_if_set_obj_pos_x(GFX_WDGT_TEST_L1_ANIM, l_wdgt2_pos.x + l_widgt2_offset.x);
        //hmi_gfx_mgr02_if_set_obj_pos_y(GFX_NEW_WIDGETS_23_ANIM, 0);
        hmi_gfx_mgr02_if_set_obj_pos_x(GFX_NEW_WIDGETS_23_ANIM, l_wdgt3_pos.x + l_widgt3_offset.x);
        if(l_dimage_count <= 21)
        {
            l_dimage_count++;
            hmi_gfx_mgr02_if_select_dimage(GFX_SPLASH_SCREEN_CONTAINER, l_dimage_count);
            //hmi_gfx_mgr02_if_set_obj_pos_y(GFX_TEST_WIDGET_ANIM, 0);
        }
        else if(l_dimage_count == 22)
        {
           hmi_gfx_mgr02_if_select_dimage(GFX_SPLASH_SCREEN_CONTAINER, 10);
           hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SPLASH_SCREEN_CONTAINER_ANIM, l_posy);
           hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"DImage X-Axis");
           l_dimage_count++;
        }
        else if(l_dimage_count == 23)
        {
            if(l_posx < 481)
            {
               l_posx+=10;
            }
            else
            {
               l_posx = 0;
               l_posy = 0;
               l_dimage_count = 24;
               hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"DImage Y-Axis");
            }
            hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SPLASH_SCREEN_CONTAINER_ANIM, l_posx);
        }
        else if(l_dimage_count == 24)
        {
           if(l_posy >= 273)
           {
              l_posy = 0;
              l_posx = 0;
              l_dimage_count = 25;
              hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Screen X-Axis");
           }
           else
           {
              l_posy+=5;
           }
           hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SPLASH_SCREEN_CONTAINER_ANIM, l_posy);
        }
        else if(l_dimage_count == 25)
        {
            if(l_posx < 481)
            {
               l_posx+=10;
            }
            else
            {
               l_posx = 0;
               l_posy = 0;
               l_dimage_count = 26;
               hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"DImage Y-Axis");
            }
            hmi_gfx_mgr02_if_set_obj_pos_x(GFX_SCN_SPLASH_ANIM_ANIM, l_posx);
        }
        else if(l_dimage_count == 26)
        {
           if(l_posy >= 273)
           {
              l_posy = 0;
              l_posx = 0;
              l_dimage_count = 27;
              hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Anim Complete");
           }
           else
           {
              l_posy+=5;
           }
           hmi_gfx_mgr02_if_set_obj_pos_y(GFX_SCN_SPLASH_ANIM_ANIM, l_posy);
        }
        else
        {
           l_screen_presenation_complete = 1;
        }
        }
        #endif
    }
    else if(p_presen_hndl_status_SP->presentation_status  == LSH_DEACTIVATED_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_SPLASH_ANIM, 0);
    }
    else
    {
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
** CMS Rev 01       20-Feb-2013  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

