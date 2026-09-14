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
** Name:           gfx_scn_wdgt_race_lights_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_WDGT_RACE_LIGHTS_PRESENTATION_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_logic_state_handler.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

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
void wdgt_race_lights_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_text(GFX_CMD_EXECUTION, L"Splash Screen Presentation");
         hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"");
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_GREEN_BIG_ANIM, 0x00000000);
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_GREEN_SMALL_ANIM, 0x00000000);  /* 0x0000FF00*/
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_RED_SMALL_ANIM, 0x00000000); /* 0x00FF0000 */
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_YELLOW_SMALL_0_ANIM, 0x00000000);
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_YELLOW_SMALL_1_ANIM, 0x00000000);
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_YELLOW_SMALL_2_ANIM, 0x00000000);
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_YELLOW_DOUBLE2_ANIM, 0x00000000);/*0x00FFFF7F*/
         hmi_gfx_mgr02_if_set_obj_fg_color(GFX_IMG_RACE_YELLOW_DOUBLE1_ANIM, 0x00000000);
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_WDGT_RACE_LIGHTS, 1);
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WDGT_RACE_LIGHTS, 1);
        if(l_anim_present == 5)
        {
           l_screen_presenation_complete = 1;
        }
        else
        {
            l_anim_present++;
        }
    }
    else if(p_presen_hndl_status_SP->presentation_status  == LSH_DEACTIVATED_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WDGT_RACE_LIGHTS, 0);
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

