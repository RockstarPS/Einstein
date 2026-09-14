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
** Name:           gfx_scn_visible_layer_presentation.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define GFX_SCN_VISIBLE_LAYER_PRESENTATION_C
#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_cfg.h"
static UINT8 l_anim_present = 0;
#if defined(GFX_MGR02_GDG03_TEST_FIXTURE)
#include "gfx_scn_1bpp_bmp_presentation.c"
#include "gfx_scn_2bpp_bmp_presentation.c"
#include "gfx_scn_4bpp_alpha_map_presentation.c"
#include "gfx_scn_4bpp_bmp_presentation.c"
#include "gfx_scn_8bpp_alpha_map_presentation.c"
#include "gfx_scn_8bpp_bmp_presentation.c"
#include "gfx_scn_8bpp_smiley_presentation.c"
#include "gfx_scn_8bpp_smiley_tile_on_400_272_presentation.c"
#include "gfx_scn_24bpp_bmp_presentation.c"
#include "gfx_scn_32bpp_bmp_presentation.c"
#include "gfx_scn_argb1555_bmp_presentation.c"
#include "gfx_scn_argb4444_bmp_presentation.c"
#include "gfx_scn_honda_anim_presentation.c"
#include "gfx_scn_odo_test_presentation.c"
#include "gfx_scn_openvg_test_presentation.c"
#include "gfx_scn_rgb565_bmp_chroma_presentation.c"
#include "gfx_scn_rgb565_bmp_presentation.c"
#include "gfx_scn_splash_anim_presentation.c"
#include "gfx_scn_text_diff_bpp_presentation.c"
#include "gfx_scn_wdgt_4bpp_bmp_presentation.c"
#include "gfx_scn_wdgt_race_lights_presentation.c"
#include "gfx_scn_widget_4bpp_bmps_presentation.c"
#include "gfx_scn_widget_image_test_presentation.c"
#include "gfx_scn_widget_text_presentation.c"
#include "gfx_scn_etm_presentation.c"
#include "scn_visible_layer_presentation.c"
#include "gfx_scn_layer_visible2_presentation.c"
#include "gfx_scn_layer_visible1_presentation.c"
#else
#if defined(GFX_MGR02_SIMAGE_TEST)  || defined(GFX_MGR02_ANIM_SIMAGE_TEST)
#include "gfx_scn_simage_presentation.c"
#endif

#if defined(GFX_MGR02_DIMAGE_TEST) || defined(GFX_MGR02_ANIM_DIMAGE_TEST)
#include "gfx_scn_dimage_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_SWIDGET_TEST) || defined(GFX_MGR02_ANIM_SWIDGET_TEST)
#include "gfx_scn_swidget_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_DWIDGET_TEST) || defined(GFX_MGR02_ANIM_DWIDGET_TEST)
#include "gfx_scn_dwidget_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_STEXT_TEST)  || defined(GFX_MGR02_ANIM_STEXT_TEST)
#include "gfx_scn_stext_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_DTEXT_TEST) || defined(GFX_MGR02_ANIM_DTEXT_TEST)
#include "gfx_scn_dtext_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_TILE_TEST)  || defined(GFX_MGR02_ANIM_TILE_TEST)
#include "gfx_scn_tile_presentation.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_FILL_TEST)  || defined(GFX_MGR02_ANIM_FILL_TEST)
#include "gfx_scn_fill_presentation.c"
#endif

#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

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

