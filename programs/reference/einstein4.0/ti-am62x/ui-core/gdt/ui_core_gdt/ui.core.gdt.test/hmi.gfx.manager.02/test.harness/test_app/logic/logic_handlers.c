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
#if defined(GFX_MGR02_GDG03_TEST_FIXTURE)
#include "gfx_scn_1bpp_bmp_logic.c"
#include "gfx_scn_2bpp_bmp_logic.c"
#include "gfx_scn_4bpp_alpha_map_logic.c"
#include "gfx_scn_4bpp_bmp_logic.c"
#include "gfx_scn_8bpp_alpha_map_logic.c"
#include "gfx_scn_8bpp_bmp_logic.c"
#include "gfx_scn_8bpp_smiley_logic.c"
#include "gfx_scn_8bpp_smiley_tile_on_400_272_logic.c"
#include "gfx_scn_24bpp_bmp_logic.c"
#include "gfx_scn_32bpp_bmp_logic.c"
#include "gfx_scn_argb1555_bmp_logic.c"
#include "gfx_scn_argb4444_bmp_logic.c"
#include "gfx_scn_honda_anim_logic.c"
#include "gfx_scn_odo_test_logic.c"
#include "gfx_scn_openvg_test_logic.c"
#include "gfx_scn_rgb565_bmp_chroma_logic.c"
#include "gfx_scn_rgb565_bmp_logic.c"
#include "gfx_scn_splash_anim_logic.c"
#include "gfx_scn_text_diff_bpp_logic.c"
#include "gfx_scn_wdgt_4bpp_bmp_logic.c"
#include "gfx_scn_wdgt_race_lights_logic.c"
#include "gfx_scn_widget_4bpp_bmps_logic.c"
#include "gfx_scn_widget_image_test_logic.c"
#include "gfx_scn_widget_text_logic.c"
#else

#if defined(GFX_MGR02_NON_ANIM_SIMAGE_TEST)  || defined(GFX_MGR02_ANIM_SIMAGE_TEST)
#include "gfx_scn_simage_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_DIMAGE_TEST) || defined(GFX_MGR02_ANIM_DIMAGE_TEST)
#include "gfx_scn_dimage_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_SWIDGET_TEST) || defined(GFX_MGR02_ANIM_SWIDGET_TEST)
#include "gfx_scn_swidget_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_DWIDGET_TEST) || defined(GFX_MGR02_ANIM_DWIDGET_TEST)
#include "gfx_scn_dwidget_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_STEXT_TEST)  || defined(GFX_MGR02_ANIM_STEXT_TEST)
#include "gfx_scn_stext_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_DTEXT_TEST) || defined(GFX_MGR02_ANIM_DTEXT_TEST)
#include "gfx_scn_dtext_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_TILE_TEST)  || defined(GFX_MGR02_ANIM_TILE_TEST)
#include "gfx_scn_tile_logic.c"
#endif

#if defined(GFX_MGR02_NON_ANIM_FILL_TEST)  || defined(GFX_MGR02_ANIM_FILL_TEST)
#include "gfx_scn_fill_logic.c"
#endif

#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
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
** CMS Rev 01       20-Feb-2013  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

