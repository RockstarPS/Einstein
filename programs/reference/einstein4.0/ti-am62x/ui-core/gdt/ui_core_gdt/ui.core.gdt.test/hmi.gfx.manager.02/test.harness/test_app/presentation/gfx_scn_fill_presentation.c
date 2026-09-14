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
** Name:           gfx_scn_widget_text_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_WIDGET_TEXT_PRESENTATION_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
GFX_MGR02_ILOC_DATA l_wdgt_text_animation, l_text_animation;
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

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
void widget_text_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_TEXT, 1);
         hmi_gfx_mgr02_if_set_text(GFX_CMD_EXECUTION, L"Widget Text");
         hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Element");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_LJ_HOR_PINK_RED_TEXT_0, L"Widget text");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_LJ_HOR_PINK_RED_TEXT_0_0, L"Widget text");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_CJ_HOR_WHITE_GREEN_TEXT_1, L"Widget text");

         hmi_gfx_mgr02_if_set_text(GFX_BPP8_LJ_HOR_PINK_RED_TEXT_0_ANIM, L"Widget text");
         l_wdgt_text_animation.x = l_text_animation.x =0;
         l_wdgt_text_animation.y = l_text_animation.y =0;
         hmi_gfx_mgr02_if_set_obj_pos(GFX_BPP8_LJ_HOR_PINK_RED_TEXT_0_ANIM, &l_text_animation);
         hmi_gfx_mgr02_if_set_obj_pos_x(GFX_BPP8_CJ_HOR_WHITE_GREEN_TEXT_1_ANIM,l_wdgt_text_animation.x);
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
    static UINT8 cmd_step =0;
     switch(cmd_step)
         {
         case 0:
             l_text_animation.y--;
             if(l_wdgt_text_animation.y <= -75)
                 {cmd_step = 1;}
             l_wdgt_text_animation.y--;
             if(l_wdgt_text_animation.y == -65){cmd_step = 2;}
             break;
         case 1:
             l_text_animation.y++;
             if(l_wdgt_text_animation.y >= 65)
                 {cmd_step = 0;}l_wdgt_text_animation.y++;
             if(l_wdgt_text_animation.y == 1){cmd_step = 2;}
             break;
         case 2:
             if(l_wdgt_text_animation.y < 0){
                 cmd_step = 0;
                 }
             else
                 {
                 cmd_step = 1;
                 }
                 if(l_anim_present == 2)
                 {
                    l_screen_presenation_complete = 1;
                 }
             l_anim_present++;
             break;
         case 3:
             
             break;
         }
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_TEXT, 1);
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_BPP8_CJ_HOR_WHITE_GREEN_TEXT_1_ANIM,l_wdgt_text_animation.y);
                hmi_gfx_mgr02_if_set_obj_pos_y(GFX_BPP8_CJ_HOR_WHITE_GREEN_TEXT_1_ANIM,l_text_animation.y);
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_BPP8_LJ_HOR_PINK_RED_TEXT_0_ANIM, l_text_animation.y);

    }
    else if(p_presen_hndl_status_SP->presentation_status  == LSH_DEACTIVATED_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_TEXT, 0);
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
** CMS Rev 01       20-FEB-2013  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

