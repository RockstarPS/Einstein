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
** Name:           hmi_gfx_mgr02_capture_video.h
**
** Description:    Sample Interface header for the video driver
**                 
**                 
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_CAPTURE_VIDEO_H
#define HMI_GFX_MGR02_CAPTURE_VIDEO_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
	
#include "hmi_gfx_mgr02_capture_video_cfg.h"

typedef enum
{
    GFX_MGR02_CAPTURE_INIT_FAILURE  = 0,
    GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS,
    GFX_MGR02_CAPTURE_INIT_SUCCESS
} GFX_MGR02_CAPTURE_INIT_STATUS;

#ifdef HMI_GFX_MGR02_CAPTURE_VIDEO_C
	#define GFX_CAPTURE_VIDEO_EXTERN
#else
	#define GFX_CAPTURE_VIDEO_EXTERN extern
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
#if(GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
GFX_CAPTURE_VIDEO_EXTERN GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_surface_init(GFX_MGR02_VIDEO_DEF_T const *p_video_def);
GFX_CAPTURE_VIDEO_EXTERN void hmi_gfx_mgr02_capture_get_surface(MML_GDC_SURFACE* fl_video_surface);
void hmi_gfx_mgr02_capture_to_surface_commit(void);
#endif

#if(GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
GFX_CAPTURE_VIDEO_EXTERN GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_window_init(MML_GDC_DISP_MODE_LINE* p_modeline_param, GFX_MGR02_VIDEO_DEF_T p_video_def);
GFX_CAPTURE_VIDEO_EXTERN void  hmi_gfx_mgr02_set_capture_signal_loss(GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status);
#endif

#if(GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
GFX_CAPTURE_VIDEO_EXTERN GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_display_init(void);
#endif

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED)
GFX_CAPTURE_VIDEO_EXTERN MML_GDC_CAP_CTX* hmi_gfx_mgr02_get_capture_context(void);
#endif

GFX_CAPTURE_VIDEO_EXTERN GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_get_capture_init_status(void); 
GFX_CAPTURE_VIDEO_EXTERN void hmi_gfx_mgr02_capture_video_shutdown(void); 
GFX_CAPTURE_VIDEO_EXTERN void hmi_gfx_mgr02_capture_video_init(void);
GFX_CAPTURE_VIDEO_EXTERN MML_GDC_SYNC* hmi_gfx_mgr02_get_capture_sync(void);	

#if((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
GFX_CAPTURE_VIDEO_EXTERN UINT8 hmi_gfx_mgr02_capture_video_get_status(void);
GFX_CAPTURE_VIDEO_EXTERN void hmi_gfx_mgr02_capture_video_set_status(UINT8 p_status);
#endif 

#ifdef  __cplusplus
}
#endif
/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
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
**
** CMS Rev 1.1      16-Aug-2018    adevi
** Interface udpation.
**
** CMS Rev 1.0      16-Aug-2018    adevi
** Creation.
**==========================================================================*/

/* end of file =============================================================*/
#endif
