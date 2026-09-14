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
** Name:           gfx_scn_text_diff_bpp_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_TEXT_DIFF_BPP_PRESENTATION_C

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
void text_diff_bpp_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_TEXT_DIFF_BPP, 1);
         hmi_gfx_mgr02_if_set_text(GFX_BPP2_LJ_HOR_PINK_RED_TEXT, L"lj h red");
         hmi_gfx_mgr02_if_set_text(GFX_BPP2_CJ_HOR_WHITE_GREEN_TEXT, L"cj h green");
         hmi_gfx_mgr02_if_set_text(GFX_BPP2_RJ_HOR_BLUE_YELLOW_TEXT, L"rj h yellow");
         hmi_gfx_mgr02_if_set_text(GFX_BPP1_LJ_HOR_PINK_RED_TEXT, L"lj h red");
         hmi_gfx_mgr02_if_set_text(GFX_BPP1_CJ_HOR_WHITE_GREEN_TEXT, L"cj h green");
         hmi_gfx_mgr02_if_set_text(GFX_BPP1_RJ_HOR_BLUE_YELLOW_TEXT,L"rj h yellow");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_LJ_HOR_PINK_RED_TEXT, L"lj h red");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_CJ_HOR_WHITE_GREEN_TEXT, L"cj h green");
         hmi_gfx_mgr02_if_set_text(GFX_BPP8_RJ_HOR_BLUE_YELLOW_TEXT, L"rj h yellow");
         hmi_gfx_mgr02_if_set_text(GFX_BPP4_LJ_HOR_PINK_RED_TEXT, L"lj h red");
         hmi_gfx_mgr02_if_set_text(GFX_BPP4_CJ_HOR_WHITE_GREEN_TEXT, L"cj h green");
         hmi_gfx_mgr02_if_set_text(GFX_BPP4_RJ_HOR_BLUE_YELLOW_TEXT, L"rj h yellow");
         hmi_gfx_mgr02_if_set_text(GFX_CMD_EXECUTION, L"Command 1");
         hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Element 1");
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_TEXT_DIFF_BPP, 1);
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
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_TEXT_DIFF_BPP, 0);
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
** CMS Rev 01       11-JUNE-2012  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

