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
** Name:           hmi_gfx_mgr02_tv2.h
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_TV2_H
#define HMI_GFX_MGR02_TV2_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_TRAVEO2)


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef GUI_GFX_MANAGER_TV2_C
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
#ifndef CYGFX_SM_FORMAT_A6R6G6B6
#define CYGFX_SM_FORMAT_A6R6G6B6 ((MM_U08)30)
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
/**
    Initialization function of the TV2 target.

    \param [in] void

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_initialize(void);
/**
    Buid screen function of the TV2 target.

    \param [in] p_layer_ID_U32

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U32);
/**
    Emergency shutdown request function.

    \param [in] void

    \retval  ::void
**/
EXTERN UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
/**
    Emergency shutdown function.

    \param [in] void

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_emergency_shutdown(void);
/**
    Normal shutdown function of the TV2 target.

    \param [in] void

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_amber_shutdown(void);
/**
    Function to check the driver busy status.

    \param [in] void

    \retval  ::1    On Busy
    \retval  ::0    On Free
**/
EXTERN UINT8 hmi_gfx_mgr02_amber_driver_busy(void);
/**
    Function to set a background colour of display.

    \param [in] p_disp_index_u8
    \param [in] p_bg_color_u32

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32);
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
/**
    function to get the runtime widget.

    \param [in] widget id

    \retval  ::GFX_MGR02_IMAGE_DEF_T    Widget information.
**/
EXTERN GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_amber_get_runtime_widget_ptr(UINT16 p_img_id);
#endif
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
/**
    Function to check the driver's current status.

    \param [in] void

    \retval  ::1    On Busy
    \retval  ::0    On Free
**/
EXTERN UINT32 hmi_gfx_mgr02_get_amber_driver_cur_status(void);
#endif
/**
    Function to get a current status of a display.

    \param [in] void

    \retval  ::0    Default. Display not opened yet.                   
    \retval  ::1    Display active with background colour set.
    \retval  ::2    Display active with active layer alongwith background colour set
**/
EXTERN UINT32 hmi_gfx_mgr02_amber_get_disp_content_status(void);
/**
    Set Surface for the OTF window.

    \param [in] p_build

    \retval  ::void
**/
#ifdef LBO_OTF_FEATURE_CC
EXTERN void hmi_gfx_mgr02_set_otf_wnd_surf(const GFX_MGR02_CONTEXT_GB_T * p_build);
/**
    Check the passed surface is related OTF window or not.

    \param [in] p_surf

    \retval  ::1                                if the surfacee is related to OTF window                             
	\retval  ::0    							if the surface is related to NON-OTF related.
**/
EXTERN UINT8 hmi_gfx_mgr02_is_otf_win_surface(const CYGFX_SURFACE_OBJECT_S *p_surf);
#endif
/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
void hmi_gfx_mgr02_tv2_set_display_property(CYGFX_DISP_ATTR p_attr_name, CYGFX_U32 p_val);
#endif
#ifdef  __cplusplus
}
#endif
#undef EXTERN
#endif /* #if defined(GFX_MGR02_TRAVEO2) */

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
** CMS Rev 1.0      26-April-2021    SSIGAMAN
** Taken the copy of amber.c and modified for the traveo2.
**
**==========================================================================*/


/* end of file =============================================================*/
#endif
