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
** Name:           hmi_gfx_mgr02_imxrt_pxp.h
**
** Description:    Building Graphics element using IMXRT PXP driver API
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#ifndef HMI_GFX_MGR02_IMXRT_PXP_H
#define HMI_GFX_MGR02_IMXRT_PXP_H


#ifdef HMI_GFX_MGR02_IMXRT_PXP_C
#define GFX_IMXRT_PXP_EXTERN
#else
#define GFX_IMXRT_PXP_EXTERN extern
#endif

#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
#endif

#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_IMXRT_PXP)
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_init(void);
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_image(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *p_elem_def_SP);

GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP ,
                                                                    GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP,
                                                                    HMI_CHAR const *p_string,
                                                                    u_gx_flocal p_text_actual_width
#if (defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                                                    ,u_gx_flocal p_is_multi_line_text
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                    ,UINT16 p_ml_str_index
#endif
#endif
                                                                    );


GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_fill(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
#ifdef USE_IMXRT_PXP_QUEUE
GFX_IMXRT_PXP_EXTERN void hmi_gfx_mgr02_imxrt_pxp_wait2complete_blit(void);
#endif
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_finish(void);
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
#endif
GFX_IMXRT_PXP_EXTERN pxp_output_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(u_gx_flocal p_pix_format);
GFX_IMXRT_PXP_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_mem_copy(UINT32  *p_src_ptr , UINT32  *p_dest_ptr, UINT32 p_size);
GFX_IMXRT_PXP_EXTERN UINT32 hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(pxp_output_pixel_format_t p_format);
#undef GFX_IMXRT_PXP_EXTERN
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

** CMS Rev 1.0      27-Jun-2021    CSAKTHIV
** Initial version.
**==========================================================================*/
/* end of file =============================================================*/

