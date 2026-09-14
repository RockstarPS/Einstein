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
** Name:           hmi_gfx_mgr02_generic.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_GENERIC_H
#define HMI_GFX_MGR02_GENERIC_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_font.h"
#include "hmi_gfx_mgr02_context.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
#define GFX_MGR02_GENERIC_BUILD          (0U)
#define GFX_MGR02_ALIGNED_WIDGET_INIT    (1U)
#define GFX_MGR02_ALIGNED_WIDGET_BUILD   (2U)

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/

void   hmi_gfx_mgr02_generic_initialize(void);
void hmi_gfx_mgr02_generic_shutdown(void);
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
u_gx_flocal hmi_gfx_mgr02_generic_build_screen(u_gx_flocal p_layer_ID_U8, u_gx_flocal p_layout_dirty_U8);
#else
u_gx_flocal hmi_gfx_mgr02_generic_build_screen(u_gx_flocal p_layer_ID_U8);
#endif
#if (defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)) && (GFX_MGR02_NUM_OF_SWDGS > 0)
UINT32 hmi_gfx_mgr02_generic_build_dcu_gen_widget(GFX_MGR02_CONTEXT_GB_T      * p_build,
                                                  GFX_MGR02_ELEM_LIST_T const * p_elem_list);
#endif
#if GFX_MGR02_NUM_MASK_WIDGETS>0
void hmi_gfx_mgr02_generic_build_mask_element(GFX_MGR02_CONTEXT_T      * fl_context_sp,
                                                  GFX_MGR02_ELEM_LIST_T const * p_elem_SP,
												  u_gx_flocal p_aligned_widget,
                                                  u_gx_flocal p_obj_dirty_U8);
#endif
#if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_TRAVEO2)
u_gx_flocal  hmi_gfx_mgr02_generic_get_element_bound(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP, 
                                                     u_gx_flocal                    p_target_U8,
                                                     GFX_FLOAT * p_bound);
#endif
void hmi_gfx_mgr02_generic_add_bound(GFX_FLOAT * p_bound);

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
GFX_MGR02_MULTI_LINE_INFO hmi_gfx_mgr02_run_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const             * p_string,
                                        GFX_MGR02_MULTI_LINE_DATA              *p_multi_line_array,
                                        GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   *p_dep_param,
                                        BOOLEAN p_is_RTL_lang);
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
GFX_MGR02_MULTI_LINE_INFO hmi_gfx_mgr02_run_RTL_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const             * p_string,
                                        GFX_MGR02_MULTI_LINE_DATA              *p_multi_line_array,
                                        GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   *p_dep_param,
                                        BOOLEAN p_is_RTL_lang);
#endif
#endif

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
** CMS Rev 1.12     30-Nov-2017    ARAJASE2
** 1005357: Graphics Manager update for Hebrew Text rendering
** Enabled existing arabic related code for GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED macro also.
** Renamed the following functions since it supports both arabic and Hebrew(RTL - Right to Left)
** hmi_gfx_mgr02_arabic_multiline_algorithm --> hmi_gfx_mgr02_RTL_multiline_algorithm
** hmi_gfx_mgr02_run_arabic_multiline_algorithm --> hmi_gfx_mgr02_run_RTL_multiline_algorithm
**
** CMS Rev 1.11     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.10     12-Apr-2017    ADEVI
** 829051: Amber:Multi line feature integration
**
** CMS Rev 1.9      28-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.8     27-JULY-2016    SANAND2
** 641381: Arabic multi line changes.
**
** CMS Rev 1.7     22-July-2016    ADEVI
** 623405: Arabic multi line algorithm changes.
**
** CMS Rev 1.6     22-July-2016    ADEVI
** 610788: Multi - line data saved and new line requirement changes.
**
** CMS Rev 1.5     30-Aug-2014    SSIGAMAN
** Spansion Iris engine Amber-I changes for Kepler2. Window surface added as 
** element for the structure GFX_MGR02_GEN_BUILD_ELEMENT_T.
**
** CMS Rev 1.4      19-Mar-2014     EMANOJ1
** Compiler switch adjusted per latest implementation to fix a compiler warning
** related to missing prototype for hmi_gfx_mgr02_generic_get_element_bound()
** 
** CMS Rev 1.3      26-Aug-2013     EMANOJ1
** Updated to support dynamic buffer allocation for DCU openVg widgets with
** clip=false property setting.
**
** CMS Rev 1.2      28-Dec-2012     YSREEMAN
** Creation. Changes were made for integrating and to resolve compilation errors
**
** CMS Rev 1.0      10-OCT-2012     YSREEMAN
** Creation.
** This file is added to declare all the Global Function Prototypes required 
** for hmi_gfx_mgr02_software.c file 
**==========================================================================*/
/* end of file =============================================================*/
#endif
