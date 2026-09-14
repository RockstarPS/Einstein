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
** Name:           gfx_scn_widget_image_test_presentation.c
**
** Description:    This modules implements sample presentation
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_WIDGET_IMAGE_TEST_PRESENTATION_C

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
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
GFX_MGR02_ILOC_DATA l_tt1_pos, l_tt2_pos, l_tt3_pos, l_tt4_pos, l_tt5_pos, l_tt6_pos;
UINT8 test_cmd = 0;
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
void widget_image_test_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    {
         hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_IMAGE_TEST, 1);
         hmi_gfx_mgr02_if_select_dwidget(GFX_WIDGET_IMG_TEST, 0);
         hmi_gfx_mgr02_if_set_text(GFX_CMD_EXECUTION,L"Image Widget");
         hmi_gfx_mgr02_if_set_text(GFX_EXE_ELEM_PROPERTY, L"Animation ");
         l_tt1_pos.x = l_tt2_pos.x = l_tt3_pos.x = l_tt4_pos.x = l_tt5_pos.x = l_tt6_pos.x = 183;
         l_tt1_pos.y = 28;
         l_tt2_pos.y = 64;
         l_tt3_pos.y = 100;
         l_tt4_pos.y = 136;
         l_tt5_pos.y = 172;
         l_tt6_pos.y = 208;
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT1_ANIM, l_tt1_pos.y); /* 346, 28 */
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT2_ANIM, l_tt2_pos.y); /* 346, 64  */
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT3_ANIM, l_tt3_pos.y); /* 346, 100 */
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT4_ANIM, l_tt4_pos.y); /* 346, 136 */
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT5_ANIM, l_tt5_pos.y); /* 346, 172 */
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT6_ANIM, l_tt6_pos.y); /* 346, 208 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT1_0_ANIM, l_tt1_pos.x); /* 346, 28 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT2_0_ANIM, l_tt2_pos.x); /* 346, 64  */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT3_0_ANIM, l_tt3_pos.x); /* 346, 100 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT4_0_ANIM, l_tt4_pos.x); /* 346, 136 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT5_0_ANIM, l_tt5_pos.x); /* 346, 172 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT6_1_ANIM, l_tt6_pos.x); /* 346, 208 */
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_IMAGE_TEST, 1);
        if(test_cmd == 0)
        {
        if(l_tt1_pos.y < 208){l_tt1_pos.y++;}
        if(l_tt2_pos.y < 172){l_tt2_pos.y++;}
        if(l_tt3_pos.y < 136){l_tt3_pos.y++;}
        
        if(l_tt4_pos.y > 100){l_tt4_pos.y--;}
        if(l_tt5_pos.y > 64){l_tt5_pos.y--;}
        if(l_tt6_pos.y > 28){l_tt6_pos.y--;}else{test_cmd = 1;}
         hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT1_ANIM, l_tt1_pos.y); /* 346, 28 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT2_ANIM, l_tt2_pos.y); /* 346, 64  */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT3_ANIM, l_tt3_pos.y); /* 346, 100 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT4_ANIM, l_tt4_pos.y); /* 346, 136 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT5_ANIM, l_tt5_pos.y); /* 346, 172 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT6_ANIM, l_tt6_pos.y); /* 346, 208 */
       }
        else if(test_cmd == 1)
        {
           l_tt6_pos.y--;
           l_tt1_pos.y++;
           if(l_tt6_pos.y > -50)
           {
              test_cmd = 2;
              l_tt1_pos.x = l_tt2_pos.x = l_tt3_pos.x = l_tt4_pos.x = l_tt5_pos.x = l_tt6_pos.x = 346;
              l_tt1_pos.y = 28;
              l_tt2_pos.y = 64;
              l_tt3_pos.y = 100;
              l_tt4_pos.y = 136;
              l_tt5_pos.y = 172;
              l_tt6_pos.y = 208;
           }
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT1_ANIM, l_tt1_pos.y); /* 346, 28 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT2_ANIM, l_tt2_pos.y); /* 346, 64  */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT3_ANIM, l_tt3_pos.y); /* 346, 100 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT4_ANIM, l_tt4_pos.y); /* 346, 136 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT5_ANIM, l_tt5_pos.y); /* 346, 172 */
        hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_8BPP_TT6_ANIM, l_tt6_pos.y); /* 346, 208 */
        }
        else if(test_cmd == 2)
        {
              l_tt1_pos.y = l_tt2_pos.y = l_tt3_pos.y = l_tt4_pos.y = l_tt5_pos.y = l_tt6_pos.y = 13;
              l_tt1_pos.x = 19;
              l_tt2_pos.x = 53;
              l_tt3_pos.x = 87;
              l_tt4_pos.x = 121;
              l_tt5_pos.x = 155;
              l_tt6_pos.x = 189;
              hmi_gfx_mgr02_if_select_dwidget(GFX_WIDGET_IMG_TEST, 1);
              test_cmd = 3;
 		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT1_0_ANIM, l_tt1_pos.x); /* 346, 28 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT2_0_ANIM, l_tt2_pos.x); /* 346, 64  */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT3_0_ANIM, l_tt3_pos.x); /* 346, 100 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT4_0_ANIM, l_tt4_pos.x); /* 346, 136 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT5_0_ANIM, l_tt5_pos.x); /* 346, 172 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT6_1_ANIM, l_tt6_pos.x); /* 346, 208 */
        }
        else if(test_cmd == 3)
        {
            if(l_tt1_pos.x < 189){l_tt1_pos.x++;}
            if(l_tt2_pos.x < 155){l_tt2_pos.x++;}
            if(l_tt3_pos.x < 121){l_tt3_pos.x++;}
            if(l_tt4_pos.x > 87){l_tt4_pos.x--;}
            if(l_tt5_pos.x > 53){l_tt5_pos.x--;}
            if(l_tt6_pos.x > 19){l_tt6_pos.x--;if(l_tt6_pos.x <= 19){test_cmd =4;}}
  		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT1_0_ANIM, l_tt1_pos.x); /* 346, 28 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT2_0_ANIM, l_tt2_pos.x); /* 346, 64  */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT3_0_ANIM, l_tt3_pos.x); /* 346, 100 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT4_0_ANIM, l_tt4_pos.x); /* 346, 136 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT5_0_ANIM, l_tt5_pos.x); /* 346, 172 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT6_1_ANIM, l_tt6_pos.x); /* 346, 208 */
       }
        else if(test_cmd == 4)
        {
            l_tt1_pos.x++;
            l_tt6_pos.x--; 
            if(l_tt6_pos.x == 0)
            {
               test_cmd =0;
               l_tt1_pos.x = l_tt2_pos.x = l_tt3_pos.x = l_tt4_pos.x = l_tt5_pos.x = l_tt6_pos.x = 346;
               l_tt1_pos.y = 28;
               l_tt2_pos.y = 64;
               l_tt3_pos.y = 100;
               l_tt4_pos.y = 136;
               l_tt5_pos.y = 172;
               l_tt6_pos.y = 208;
               hmi_gfx_mgr02_if_select_dwidget(GFX_WIDGET_IMG_TEST, 0);
            }
   		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT1_0_ANIM, l_tt1_pos.x); /* 346, 28 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT2_0_ANIM, l_tt2_pos.x); /* 346, 64  */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT3_0_ANIM, l_tt3_pos.x); /* 346, 100 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT4_0_ANIM, l_tt4_pos.x); /* 346, 136 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT5_0_ANIM, l_tt5_pos.x); /* 346, 172 */
		 hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_8BPP_TT6_1_ANIM, l_tt6_pos.x); /* 346, 208 */
      }
   }
    else if(p_presen_hndl_status_SP->presentation_status  == LSH_DEACTIVATED_STATUS)
    {
        hmi_gfx_mgr02_if_set_screen(GFX_SCN_WIDGET_IMAGE_TEST, 0);
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

