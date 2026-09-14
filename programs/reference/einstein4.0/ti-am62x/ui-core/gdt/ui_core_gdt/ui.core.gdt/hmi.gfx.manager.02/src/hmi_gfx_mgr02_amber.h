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
** Name:           hmi_gfx_mgr02_amber.h
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_AMBER_H
#define HMI_GFX_MGR02_AMBER_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_AMBER)


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef GUI_GFX_MANAGER_AMBER_C
	#define EXTERN
#else
	#define EXTERN extern
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*******************************************************************************
 Macro Definitions
*******************************************************************************/
#define GFX_MGR02_NUM_OF_PLANES             0x05
#ifndef MML_GDC_SURF_FORMAT_A6R6G6B6
#define MML_GDC_SURF_FORMAT_A6R6G6B6 ((MM_U08)29)
#endif
#define GFX_MGR02_USE_VRAM_HRAM        ((UINT8)2)

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
extern const UINT32 lc_amber_plane_features_u32a[GFX_MGR02_NUM_LAYERS][GFX_MGR02_NUM_OF_PLANES];
extern const UINT8 lc_amber_num_planes_u8a[GFX_MGR02_NUM_LAYERS];
extern const UINT32 lc_amber_disp_bg_colour_u32a[GFX_MGR02_NUM_LAYERS];
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
	extern GFX_MGR02_IMAGE_DEF_T const lc_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif
EXTERN void hmi_gfx_mgr02_initialize(void);
EXTERN void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U32);
EXTERN UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
EXTERN void hmi_gfx_mgr02_emergency_shutdown(void);
EXTERN void hmi_gfx_mgr02_amber_shutdown(void);
EXTERN UINT8 hmi_gfx_mgr02_amber_driver_busy(void);
EXTERN void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32);
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
EXTERN GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_amber_get_runtime_widget_ptr(UINT16 p_img_id);
#endif
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
EXTERN UINT32 hmi_gfx_mgr02_get_amber_driver_cur_status(void);
#endif
EXTERN UINT32 hmi_gfx_mgr02_amber_get_disp_content_status(void);
/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif
#undef EXTERN
#endif /* #if defined(GFX_MGR02_AMBER) */

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
** CMS Rev #        Date            By
** CMS Rev X.X      dd-mmm-yyyy     CDSID
**
**============================================================================
** CMS Rev 1.7      08-Nov-2017    KKUBENDI
** 968274: Added macro GFX_MGR02_USE_VRAM_HRAM
**
** CMS Rev 1.6      6-Sep-2017    ADEVI
** 948804: Amber driver run time recovery implementation.
**
** CMS Rev 1.5      1-Sep-2017    SSIGAMAN
** 912798: Different FrameBuffer configuration support in GDT required
** ARGB6666 and YUV422 widget rendering formats added.
**
** CMS Rev 1.4     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.3     29/06/17    SSRINI19
** 880883 : GM-CHUD QAC MISRA additional warning fixes
** 
** CMS Rev 1.2     20-Dec-2015    SSIGAMAN
** RTC :486359
** Added API for checking the Driver Status whether Busy or Free.
**
** CMS Rev 1.1		10-Feb-2015		SSIGAMAN
** Added the void hmi_gfx_mgr02_normal_shutdown(void) API.
**
** CMS Rev 1.0      11-Aug-2014     nkrishn9
** Creation.
** First version archived in RTC
**==========================================================================*/


/* end of file =============================================================*/
#endif
