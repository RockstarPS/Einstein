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
** Name:           hmi_gfx_mgr02_shape_engine.h
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_SHAPE_ENGINE_H
#define HMI_GFX_MGR02_SHAPE_ENGINE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || \
      (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||   \
      (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
	#if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
	  #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)	&& (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
	    /* MonoType(iType) font engine */
	    #include "fs_itype.h"
        /* include the WorldType Shaper API core header file                        */
        #include "tsshaperapi.h"
	  #endif
	  #if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
	       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
	    #include "hb.h"
      #include "hb-ft.h"
      
      #include "ubidi.h"
      #include "ustring.h"

	  #endif


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
/*******************************************************************************
 Macro Definitions
*******************************************************************************/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
#if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
	       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
typedef struct
{
   hb_glyph_info_t          *glyph_info;
   hb_glyph_position_t      *gpos_info;
   UINT32                    glyph_count;
   hb_buffer_content_type_t  content_type;
}GFX_MGR02_HB_SHAPE_WORD_INFO;

typedef struct
{
  SINT16                    x_offset[GFX_MGR02_MAX_TEXT_LENGTH];
  SINT16                    y_offset[GFX_MGR02_MAX_TEXT_LENGTH];
  SINT16                    x_advance[GFX_MGR02_MAX_TEXT_LENGTH];
  UINT32                    code_point[GFX_MGR02_MAX_TEXT_LENGTH];
  hb_buffer_content_type_t  content_type[GFX_MGR02_MAX_TEXT_LENGTH];  
  UINT32                    glyph_count; 
  HMI_CHAR                  unicode[GFX_MGR02_MAX_TEXT_LENGTH];
}GFX_MGR02_HB_SHAPE_INFO;
#endif
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
UINT32 hmi_gfx_mgr02_shape_engine_initialize(void);
void hmi_gfx_mgr02_shape_engine_shutdown(void);
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
 TsShaperText * hmi_gfx_mgr02_shape_engine_get_gpos(UINT32 p_font_id, 
   UINT32 const* p_string,
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
   HMI_CHAR const* p_string_u16,
   BOOLEAN p_use_u16_ptr,
#endif
   UINT32 p_str_len,
   FS_STATE * p_client_state);
#elif (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
#if 0
 SINT8 hmi_gfx_mgr02_shape_engine_shapedtext(UINT32 p_font_id, HMI_CHAR * p_string);
#endif 
 BOOLEAN hmi_gfx_mgr02_init_ubidi(HMI_CHAR const * p_string, UINT32 p_strlen, UINT8 p_lang_dir_RTL);
 UINT8 hmi_gfx_mgr02_get_ubidi_segment_count(void);
 UINT8 hmi_gfx_mgr02_get_ubidi_last_segment_RTL_status(void);
 HMI_CHAR * hmi_gfx_mgr02_get_ubidi_next_segment(void);
 void hmi_gfx_mgr02_close_ubidi(void);
 GFX_MGR02_HB_SHAPE_INFO * hmi_gfx_mgr02_process_ubidi(HMI_CHAR const * p_string, UINT32 p_strlen, UINT8 p_lang_dir_RTL, UINT32 p_font_id, HMI_CHAR *p_shaped_str
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
   , UINT32 p_pre_render_index
#endif
 );
#endif

#ifdef  __cplusplus
}
#endif

    #endif	/* #if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ) */
  #endif  /* #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) */
#endif	/* #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE	*/

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
** CMS Rev 1.1      19-Dec-2017     sbollam
** Added Harfbuzz shape engine support.
** Ref Task : 978896
** WTLE Shape engine support for MMC 978896
** CMS Rev 1.0      20-Nov-2017     sbollam
** Creation.
** WTLE Shape engine support for MMC 978896
**==========================================================================*/


/* end of file =============================================================*/
#endif
