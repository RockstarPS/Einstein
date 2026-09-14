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
** Name:           gfx_scn_honda_anim_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_HONDA_ANIM_PRESENTATION_C

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
void scn_main_sts_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 1);
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 1);
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
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 0);
    }
    else
    {
    }
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
void scn_trip_b_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_B, 1);
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 1);
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_1, L"Trip");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_2, L"Avg.Fuel");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_3, L"Avg.Speed");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_4, L"Time");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_1_VAL, L"348.5");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_2_VAL, L"34.4");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_3_VAL, L"90");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_4_HR_VAL, L"06");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_4_MN_VAL, L"35");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_IFE_SCALE_0, L"0");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_IFE_SCALE_40, L"40");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_IFE_SCALE_80, L"80");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_1_UNIT,L"miles");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_2_UNIT,L"mpg");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_3_UNIT,L"mph");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_4_HR_UNIT,L"h");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_B_LINE_4_MN_UNIT,L"min");
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_B, 1);
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
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_B, 0);
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 0);
    }
    else
    {
    }
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
void scn_trip_a_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_A, 1);
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 1);
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_1, L"Trip");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_2, L"Avg.Fuel");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_3, L"Avg.Speed");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_4, L"Time");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_1_VAL,L"248.6");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_2_VAL,L"34.4");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_3_VAL,L"50");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_4_HR_VAL,L"03");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_4_MN_VAL,L"08");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_1_UNIT,L"miles");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_2_UNIT,L"mpg");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_3_UNIT,L"mph");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_4_HR_UNIT,L"h");
         hmi_gfx_mgr02_if_set_text(GFX_TXT_TRIP_A_LINE_4_MN_UNIT,L"min");
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_A, 1);
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
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_TRIP_A, 0);
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_MAIN_STATUS, 0);
    }
    else
    {
    }
}

void scn_fill_presentation_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_FILL_NON_ANIM, 1);
         l_anim_present = 0;
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_FILL_NON_ANIM, 1);
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
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_FILL_NON_ANIM, 0);
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

