/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_amber_iris.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#ifndef HMI_GFX_MGR02_AMBER_IRIS_H
#define HMI_GFX_MGR02_AMBER_IRIS_H


#ifdef HMI_GFX_MGR02_AMBER_IRIS_C
	#define GFX_AMBER_IRIS_EXTERN
#else
	#define GFX_AMBER_IRIS_EXTERN extern
#endif

#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
#endif


#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)) && !defined(GFX_MGR02_IMXRT)

	typedef enum
	{
	  GFX_MGR02_DRIVER_FREE =0,
	  GFX_MGR02_DRIVER_BUSY_IRIS_ENGINE  =1,
	  GFX_MGR02_DRIVER_BUSY_WINDOW_COMMIT=2
	}GFX_MGR02_DRIVER_BUSY_STATUS_T;

	/*Iris Driver Not Supports the 2BPP, 4BPP and ARGB6666 . So this is temp implementation for now.*/
	#if defined(GFX_MGR02_TRAVEO2)
		#ifndef CYGFX_SM_FORMAT_RGB4
			#define CYGFX_SM_FORMAT_RGB4 (CYGFX_U08)28
		#endif
		#ifndef CYGFX_SM_FORMAT_RGB2
			#define CYGFX_SM_FORMAT_RGB2 (CYGFX_U08)29
		#endif
		#ifndef CYGFX_SM_FORMAT_A6R6G6B6
			#define CYGFX_SM_FORMAT_A6R6G6B6 ((CYGFX_U08)30)
		#endif
		#ifndef MML_GDC_SURF_FORMAT_RGB4
	        #define MML_GDC_SURF_FORMAT_RGB4 CYGFX_SM_FORMAT_RGB4
	    #endif
		#ifndef MML_GDC_SURF_FORMAT_RGB2
			#define MML_GDC_SURF_FORMAT_RGB2 CYGFX_SM_FORMAT_RGB2
		#endif
		#ifndef MML_GDC_SURF_FORMAT_A6R6G6B6
			#define MML_GDC_SURF_FORMAT_A6R6G6B6 CYGFX_SM_FORMAT_A6R6G6B6
		#endif
	#else
		#ifndef MML_GDC_SURF_FORMAT_RGB4
			#define MML_GDC_SURF_FORMAT_RGB4 (MM_U08)27
		#endif
		#ifndef MML_GDC_SURF_FORMAT_RGB2
			#define MML_GDC_SURF_FORMAT_RGB2 (MM_U08)28
		#endif
		#ifndef MML_GDC_SURF_FORMAT_A6R6G6B6
			#define MML_GDC_SURF_FORMAT_A6R6G6B6 ((MM_U08)29)
		#endif
	#endif
	
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)&&defined(GFX_MGR02_AMBER))|| defined(GFX_MGR02_AMBER_IRIS)
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_init(void);
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
	#if defined(GFX_MGR02_AMBER)
	GFX_AMBER_IRIS_EXTERN UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
	#endif
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_image(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *p_elem_def_SP);

	#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_video(GFX_MGR02_CONTEXT_T  const *p_cntx_SP, GFX_MGR02_VIDEO_DEF_T  const *p_elem_def_SP);
	#endif

	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_fill(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_tile(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TILE_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
	#endif

	#if (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, 
																	 HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width, u_gx_flocal p_is_multi_line_text
																  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
																	 ,UINT16 p_ml_str_index
																  #endif
																	);
	#else
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width);
	#endif
	#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
	GFX_AMBER_IRIS_EXTERN void hmi_gfx_mgr02_amber_create_mask_image_surf( GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *fl_image_desc_SP);
	GFX_AMBER_IRIS_EXTERN void hmi_gfx_mgr02_amber_set_mask_mode(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
	GFX_AMBER_IRIS_EXTERN void hmi_gfx_mgr02_amber_bind_mask_surf(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , MML_GDC_SURFACE p_mask_surf);
	#endif
	#if (GFX_MGR02_NUM_OF_SVGS > 0)
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_build_svg(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_OVG_OBJECT_T  const *p_elem_def_SP);
	#endif

	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_finish(void);
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
	GFX_AMBER_IRIS_EXTERN UINT32 hmi_gfx_mgr02_amber_get_size_for_bpp(MML_GDC_SURF_FORMAT bpp);

	#if defined(GFX_MGR02_AMBER_CMODEL)
	GFX_AMBER_IRIS_EXTERN void * hmi_gfx_mgr02_amber_get_virtual_addr(void *buffer, UINT32 bufferSize);
	#endif
	#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_start_warping(GFX_MGR02_CONTEXT_GB_T* p_build, GFX_MGR02_ELEM_LIST_T const * p_elem_list);
	GFX_AMBER_IRIS_EXTERN void hmi_gfx_mgr02_amber_finish_warping(GFX_MGR02_CONTEXT_GB_T * p_build, GFX_MGR02_ELEM_LIST_T const * p_elem_list);
	#endif /* GFX_MGR02_WIDGET_WARPING_ENABLED */


	#if(GFX_MGR02_NUM_MASK_WIDGETS > 0)
	GFX_AMBER_IRIS_EXTERN void hmi_gfx_mgr02_amber_set_mask_attributes(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , SINT32 p_x, SINT32 p_y);
	#endif

#endif
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)
	GFX_AMBER_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
	GFX_AMBER_IRIS_EXTERN MML_GDC_SURF_FORMAT hmi_gfx_mgr02_amber_get_wdg_pix_format(u_gx_flocal p_pix_format);
	#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)
	GFX_AMBER_IRIS_EXTERN UINT32 hmi_gfx_mgr02_get_bpp(UINT32 p_format);
	#endif
#endif
#endif
#undef GFX_AMBER_IRIS_EXTERN
#endif
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
 ** CMS Rev 1.7      31-Aug-2018     ADEVI
 ** 1149379: Capture Video Driver for KeplerII

 ** CMS Rev 1.6      14-Mar-2018     ADEVI
 ** 1054545: Freetype cache implementation.
**
 ** CMS Rev 1.5      1-Sep-2017    SSIGAMAN
 ** 912798: Different FrameBuffer configuration support in GDT required
 ** ARGB6666 and YUV422 widget rendering formats added.
 **
 ** CMS Rev 1.4     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.3     12-Apr-2017    ADEVI
 ** 829051: Amber:Multi line feature integration
 **
 ** CMS Rev 1.2     24-Mar-2016    SSIGAMAN
 ** 554958: Amber:Support for freetype text cache 
 ** Cache Support added for freetype in order to improve the rendering performance.
 **
 ** CMS Rev 1.1      18-Aug-2015    VTODOROV
 ** RTC 371946: Warping functionality.
 **
 ** CMS Rev 1.0      30-Aug-2014    SSIGAMAN
 ** Initial version.
 **==========================================================================*/
/* end of file =============================================================*/

