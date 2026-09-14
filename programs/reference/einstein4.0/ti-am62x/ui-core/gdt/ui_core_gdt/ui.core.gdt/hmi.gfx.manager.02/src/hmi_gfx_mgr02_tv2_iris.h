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
**============================================================================*/
/**
 * \file    hmi_gfx_mgr02_tv2_iris.h
 */
 
#ifndef HMI_GFX_MGR02_TV2_IRIS_H
#define HMI_GFX_MGR02_TV2_IRIS_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef HMI_GFX_MGR02_TV2_IRIS_C
	#define GFX_TV2_IRIS_EXTERN
#else
	#define GFX_TV2_IRIS_EXTERN extern
#endif

#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
#endif


#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*Iris Driver Not Supports the 2BPP, 4BPP and ARGB6666 . So this is temp implementation for now.*/
#ifndef CYGFX_SM_FORMAT_RGB4
#define CYGFX_SM_FORMAT_RGB4 (CYGFX_U08)28
#endif
#ifndef CYGFX_SM_FORMAT_RGB2
#define CYGFX_SM_FORMAT_RGB2 (CYGFX_U08)29
#endif
#ifndef CYGFX_SM_FORMAT_A6R6G6B6
#define CYGFX_SM_FORMAT_A6R6G6B6 ((MM_U08)30)
#endif
/**
    Initializes the library internal variables.

    \param None

    \retval  ::TRUE                             Success
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_init(void);
/**
    Prepares the environment for merge widget element rendering.

    \param [in] p_cntx_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
/**
    Passing the command to blit engine for rendering the image element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_image(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *p_elem_def_SP);

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
/**
    Passing the command to blit engine for rendering the video frame.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_video(GFX_MGR02_CONTEXT_T  const *p_cntx_SP, GFX_MGR02_VIDEO_DEF_T  const *p_elem_def_SP);
#endif
/**
    Passing the command to blit engine for rendering the fill element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP
	\param [in] p_dim

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_fill(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
/**
    Passing the command to blit engine for rendering the tile element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP
	\param [in] p_dim

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_tile(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TILE_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
#endif

/**
    Passing the command to blit engine for rendering the text element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP
	\param [in] p_string
	\param [in] p_text_actual_width

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
/**
    Passing the command to blit engine for rendering the text element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP
	\param [in] p_string
	\param [in] p_text_actual_width
	\param [in]	p_is_multi_line_text
	\param [in]	p_ml_str_index
	
    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, 
                                                                 HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width, u_gx_flocal p_is_multi_line_text
															  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
		                                                         ,UINT16 p_ml_str_index
                                                              #endif
                                                                );
#else
/**
    Passing the command to blit engine for rendering the text element.

    \param [in] p_cntx_SP
	\param [in] p_elem_def_SP
	\param [in] p_string
	\param [in] p_text_actual_width

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width);
#endif
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
/**
	Creates mask image surface.

    \param [in] p_cntx_SP
	\param [in] p_image_desc_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN void hmi_gfx_mgr02_amber_create_mask_image_surf( GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *p_image_desc_SP);
/**
	Sets the mask mode.

    \param [in] p_cntx_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN void hmi_gfx_mgr02_amber_set_mask_mode(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
/**
	Binds the mask surface to the blit engine context.

    \param [in] p_cntx_SP
	\param [in] p_image_desc_SP

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN void hmi_gfx_mgr02_amber_bind_mask_surf(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , MML_GDC_SURFACE p_mask_surf);
#endif
#if (GFX_MGR02_NUM_OF_SVGS > 0)
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_svg(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_OVG_OBJECT_T  const *p_elem_def_SP);
#endif

#if (GFX_MGR02_NUM_USER_LAYERS > 0)
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_build_uimage(GFX_MGR02_CONTEXT_T const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);    
#endif
/**
	This function to be called after all the blit commands of the widget are sent
	to the command queue. This function will add the synchronization object into the queue
	and it wait for the synchronization object to be signaled. If signaled means that the blit operations are completed.


    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_finish(void);
/**
	Clears the stored surface with passed color.

    \param [in] p_cntx_SP
	\param [in] p_clear_color

    \retval  ::TRUE                             On Success
	\retval  ::FALSE							On Failure
**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_tv2_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);

#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
/**
	Prepares for Warping a Widget element.

    \param [in] p_build
	\param [in] p_elem_list
	
    \retval  ::TRUE                             On Success

**/
GFX_TV2_IRIS_EXTERN s_gx_flocal hmi_gfx_mgr02_amber_start_warping(GFX_MGR02_CONTEXT_GB_T* p_build, GFX_MGR02_ELEM_LIST_T const * p_elem_list);
/**
	Prepares for Warping a Widget element.

    \param [in] p_build
	\param [in] p_elem_list
	
    \retval  ::TRUE                             On Success

**/
GFX_TV2_IRIS_EXTERN void hmi_gfx_mgr02_amber_finish_warping(GFX_MGR02_CONTEXT_GB_T * p_build, GFX_MGR02_ELEM_LIST_T const * p_elem_list);
#endif /* GFX_MGR02_WIDGET_WARPING_ENABLED */
#endif
#if(GFX_MGR02_NUM_MASK_WIDGETS > 0)
	
/**
	Interface to bind mask surface with pixel context after performing translation..

    \param [in] p_cntx_SP
	\param [in] p_x
	\param [in] p_y
	
    \retval  ::TRUE                             On Success

**/
GFX_TV2_IRIS_EXTERN void hmi_gfx_mgr02_amber_set_mask_attributes(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , SINT32 p_x, SINT32 p_y);
#endif
#undef GFX_TV2_IRIS_EXTERN
#ifdef __cplusplus
} /* extern "C" */
#endif
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
 ** CMS Rev 1.0      Jan-2021    SSIGAMAN
 ** Initial version.
 **==========================================================================*/
/* end of file =============================================================*/

