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
** Name:           hmi_gfx_mgr02_cache.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_CACHE_H
#define HMI_GFX_MGR02_CACHE_H

#ifdef GUI_GFX_MANAGER_CACHE_C
  #define GFX_CACHE_EXTERN
#else
  #define GFX_CACHE_EXTERN extern
#endif

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
#include <ftcache.h>
#include <freetype/ftsizes.h>
#endif

#if defined(GFX_MGR02_OPEN_VG)	|| defined(GFX_MGR02_OPEN_GL) || ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)) && defined(GFX_STRING_CACHE_ENABLED))
#if defined(GFX_MGR02_OPEN_VG)
#include "VG/openvg.h"
#include "VG/vgu.h"
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
typedef union
{
   void const* id;
   struct
   {
      UINT32 dyn_data:1;
      UINT32 obj_id  :15;
      UINT32 obj_code:16;
   }b;
}GFX_MGR02_OGLIB_DYN_TEX_ID;



typedef struct
{
   void * data;					   /* pixel or buffer data pointer address*/
   void const* id;                 /* union of font id and character for searching */
#if defined(GFX_MGR02_OPEN_GL)
   UINT32 texw;
   UINT32 texh;
#endif
#if defined(GFX_MGR02_OPEN_GL) 
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
   GLuint po;
#endif
#endif
#if defined(GFX_MGR02_OPEN_VG)
   VGImage   imageid;			   /* generated from opengl api */
#endif
#if defined(GFX_MGR02_OPEN_GL)
   GLuint texId;				   /* generated from openvg api */
#endif
   UINT32 live;
#if defined(GFX_MGR02_OPEN_GL)
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
   SINT32 bitmap_left;
   SINT32 bitmap_top;
   UINT32 width;
   UINT32 height;
   SINT32 xadvance;
#endif
#endif
#if defined(GFX_MGR02_OPEN_VG)
   VGfloat   origin[2];
   VGfloat   escapement[2];
#endif
   UINT32  font_id;
}GFX_MGR02_TEXTURE;
#endif

#ifdef GFX_STRING_CACHE_ENABLED
typedef struct GFX_STRING_CACHE_INFO_T{
  struct GFX_STRING_CACHE_INFO_T *Prev;
  
  #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
  GFX_MGR02_COLOR  drawColor;                   /* Draw Color of txt - only checking for iMXRT_PXP platform can be extended to other platforms in future if required */
  #endif
  
  UINT32 FontId;                               /*Id of Font*/
  UINT8  FontSize;                             /*Height of the Font*/
  UINT8  StringLen;                            /*Length of the String*/
  UINT16 bmpWidth;                             /*String print width in terms of pixels*/
  UINT8  *Buf;                                 /*Start Address of the String Image*/
  HMI_CHAR String[GFX_MGR02_MAX_TEXT_LENGTH + 1];
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
  HMI_CHAR InString[GFX_MGR02_MAX_TEXT_LENGTH + 1];
  GFX_MGR02_ISIZE_W_T TextBoxWidth;
  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  UINT8  MaxShrink;                             /*Maximum shrink percentage*/
  #endif   
  UINT8 ClipMode:3;
  UINT8 Alignment:2;  
  #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
  BOOLEAN isScrolled:1; 
  #endif
#endif
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
    GFX_MGR02_TXT_SPECIAL_EFFECTS  special_effects;
 #endif
  struct GFX_STRING_CACHE_INFO_T *Next;
  
}GFX_STRING_CACHE_INFO;
#endif
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
#define GFX_MGR02_MAX_CACHE_LIVE 254
#endif
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_IMG_CACHE_ENABLED))
#define GFX_MGR02_MAX_IMAGE_CACHE_LIVE 5
#endif

#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))||((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)) && defined(GFX_STRING_CACHE_ENABLED))
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
GFX_CACHE_EXTERN void hmi_gfx_mgr02_cache_init(void);
GFX_CACHE_EXTERN void hmi_gfx_mgr02_cache_shutdown(void);
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
GFX_CACHE_EXTERN GFX_MGR02_TEXTURE * hmi_gfx_mgr02_get_char_cache_ptr(void const* p_img_id);
GFX_CACHE_EXTERN void hmi_gfx_mgr02_cache_update_live_count(void);
#endif
#ifdef GFX_STRING_CACHE_ENABLED
  #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
    GFX_CACHE_EXTERN void * hmi_gfx_mgr02_get_string_cache_ptr(HMI_CHAR const * p_string_p, GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FONT const * p_font_SP, UINT32 p_font_id, GFX_MGR02_TXT_SPECIAL_EFFECTS  *p_special_effects
                                                                #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
                                                                ,GFX_MGR02_COLOR p_draw_color
                                                                #endif
                                                               );
  #else
    GFX_CACHE_EXTERN void * hmi_gfx_mgr02_get_string_cache_ptr(HMI_CHAR const * p_string_p, GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FONT const * p_font_SP,UINT32 p_font_id
                                                                #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
                                                                ,GFX_MGR02_COLOR p_draw_color
                                                                #endif
                                                               );
    
  #endif
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    GFX_CACHE_EXTERN UINT8 hmi_gfx_mgr02_get_string_cache_info(GFX_STRING_CACHE_INFO* p_cache_info_out);
#endif
#endif
    GFX_CACHE_EXTERN void hmi_gfx_mgr02_add_string_in_cache_queue(GFX_STRING_CACHE_INFO *element);
#endif
#endif /*#if defined(GFX_MGR02_OPEN_GL)|| (defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))*/

#endif /* #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)*/
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
GFX_CACHE_EXTERN FT_Error hmi_gfx_mgr02_ft2_cache_init(FT_Library  p_library);
GFX_CACHE_EXTERN FT_Error hmi_gfx_mgr02_ft2_cache_face_init(UINT8 p_font_id);
GFX_CACHE_EXTERN FTC_ImageCache hmi_gfx_mgr02_get_ft2_imgcache_handler(void);
GFX_CACHE_EXTERN FTC_Manager hmi_gfx_mgr02_get_ft2_cachemgr_handler(void);
#endif

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
** CMS Rev 1.2     17-Jul-2017    ARAJASE2
** 911991: CI for opengl simulation
** Compilation error resolved in opengl
**
** CMS Rev 1.1     07-Feb-2017    VGAJJI
** 796121: gfx_mgr02: Code protection check was missed for bmp fonts
**
** CMS Rev 1.0      12-Nov-2016     CSAKTHIV
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
#endif
