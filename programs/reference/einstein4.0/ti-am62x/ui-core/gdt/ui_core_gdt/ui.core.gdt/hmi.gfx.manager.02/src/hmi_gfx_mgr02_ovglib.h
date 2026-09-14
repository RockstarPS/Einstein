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
** Name:           hmi_gfx_mgr02_ovglib.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_OVGLIB_H
#define HMI_GFX_MGR02_OVGLIB_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_OPEN_VG)
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

s_gx_flocal hmi_gfx_mgr02_ovglib_build_image(GFX_MGR02_CONTEXT_T  const * , GFX_MGR02_IMAGE_DEF_T  const *);
#if defined(GFX_MGR02_USE_FILESYSTEM)
s_gx_flocal hmi_gfx_mgr02_ovglib_build_uimage(GFX_MGR02_CONTEXT_T  const * , GFX_MGR02_IMAGE_DEF_T  const *);
#endif
s_gx_flocal hmi_gfx_mgr02_ovglib_build_bitmap_reflection(VGImage ,GFX_MGR02_CONTEXT_T const *, GFX_MGR02_IMAGE_DEF_T const *);
s_gx_flocal hmi_gfx_mgr02_ovglib_build_fill(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_FILL_DEF_T   const *, GFX_MGR02_IDIM_DATA const *);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
s_gx_flocal hmi_gfx_mgr02_ovglib_build_tile(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TILE_DEF_T   const *, GFX_MGR02_IDIM_DATA const *);
#endif
#if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
s_gx_flocal hmi_gfx_mgr02_ovglib_build_text(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TEXT_DEF_T   const *, HMI_CHAR const *, u_gx_flocal, u_gx_flocal);
#else
s_gx_flocal hmi_gfx_mgr02_ovglib_build_text(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TEXT_DEF_T   const *, HMI_CHAR const *, u_gx_flocal);
#endif
s_gx_flocal hmi_gfx_mgr02_ovglib_build_svg(GFX_MGR02_CONTEXT_T    const * , GFX_MGR02_OVG_OBJECT_T const *);
s_gx_flocal hmi_gfx_mgr02_ovglib_finish(void);
s_gx_flocal hmi_gfx_mgr02_ovglib_init(void);
s_gx_flocal hmi_gfx_mgr02_ovglib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
s_gx_flocal hmi_gfx_mgr02_ovglib_get_bound(UINT32                p_obj_type,
                                           GFX_MGR02_CONTEXT_T const * p_cntx_SP, /*QA C warning fix */
                                           GFX_FLOAT               * p_bounds);
void hmi_gfx_mgr02_ovglib_set_mask_mode(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
s_gx_flocal hmi_gfx_mgr02_ovglib_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
void hmi_gfx_mgr02_ovglib_fb_updated(void);
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
s_gx_flocal hmi_gfx_mgr02_ovglib_pre_copy_fb(GFX_MGR02_CONTEXT_T  const * p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const * p_elem_def_SP);
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
void hmi_gfx_mgr02_ovglib_cache_init(void);
void hmi_gfx_mgr02_ovglib_cache_distroy(void);
#endif
#if defined (GFX_MGR02_VG_IMG_CACHE_ENABLED)
void hmi_gfx_mgr02_ovglib_remove_from_cache(void const * p_obj_def_S);
#endif
UINT32 hmi_gfx_mgr02_ovglib_cache_get_object(void const * pc_bitmap_def_S, GFX_MGR02_VG_OBJ_TYPES bitmap_def_type, UINT32 p_raw_data, UINT32  p_attributes);
#ifdef GFX_DRIVER_SUPPORT_VECTOR_FONT
void hmi_gfx_mgr02_ovglib_font_init(void);
#endif
#ifndef GFX_MGR02_PRECREATE_FONTS
#define GFX_MGR02_PRECREATE_FONTS          (FONTS_NONE)
#endif

#endif /* #if defined(GFX_MGR02_OPEN_VG) */

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
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
** CMS Rev #        Date            By
** CMS Rev X.X      dd-mmm-yyyy     CDSID
**
**============================================================================
** CMS Rev 1.8    23-Nov-2017    ARAJASE2
** 994906: P552 L1, L2 - OpenVG rendering texts are not displayed (Core Migration).
** Usage of GFX_MGR02_VG_CACHE_ENABLED macro is replaced with new macros
** GFX_MGR02_VG_IMG_CACHE_ENABLED and GFX_MGR02_VG_TXT_CACHE_ENABLED
**
** CMS Rev 1.7     07/02/2016    SBOLLAM
** RTC ID: 750237: Updated error logging capability and added
**                 OVG software recovery capability
**
** CMS Rev 1.6     31-Jan-2017    VGAJJI        RTC 787468
** B515 - Changes
**
** CMS Rev 1.5     28-Oct-2015    ADEVI         RTC 412568
** Multi line text Implementation - Initial Version.
**
** CMS Rev 1.4      22-Aug-2015    APERUMAL
** RTC 405974 - QA C warnings fix for Honda Thaa
**
** CMS Rev 1.3      14-Dec-2014    RBHARAT2
** RTC 250101 - VG cache implementation modified to have individual cache buffers
**
** CMS Rev 1.2      26-Aug-2013     EMANOJ1
** Updated to support dynamic buffer allocation for OpenVg wdgets with 
** clip=false setting in kepler DCU targets.
**
** CMS Rev 1.1      15-May-2013     EMANOJ1
** Added hmi_gfx_mgr02_ovglib_get_bound() interface to calculate the 
** transformed bounds of an element
**
** CMS Rev 1.0      08-Aug-2012     EMANOJ1
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
#endif
