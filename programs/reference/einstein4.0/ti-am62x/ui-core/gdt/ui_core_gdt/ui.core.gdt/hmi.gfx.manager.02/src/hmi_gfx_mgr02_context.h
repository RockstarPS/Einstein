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
** Name:           hmi_gfx_mgr02_context.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_CONTEXT_H
#define HMI_GFX_MGR02_CONTEXT_H

#ifdef HMI_GFX_MGR02_CONTEXT_C
  #define GFX_CONTEXT_EXTERN
#else
  #define GFX_CONTEXT_EXTERN extern
#endif

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_font.h"
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)))
 #include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
   #include FT_OUTLINE_H
   #include FT_MODULE_H 
   #include FT_SYSTEM_H
 #endif
 #if defined(GFX_MGR02_VGLITE)
   #include FT_OUTLINE_H
   #include FT_BBOX_H
   #if defined (GFX_MGR02_USE_FREETYPE2_OS2_TABLE)
        #include FT_TRUETYPE_TABLES_H
   #endif
 #endif
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
    #include "fs_itype.h"
  #endif
#endif

#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
        #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| \
             (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || \
             (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
            #if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
                /* include the Shaper (wtle and harfbuzz) engine header file  */
                #include "hmi_gfx_mgr02_shape_engine.h"
            #endif
            #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
                #ifndef GFX_MGR02_SHAPE_ENGINE
                    #include "tsunienc.h"
                #endif
            #endif
        #endif
    #endif
    #include "hmi_gfx_mgr02_amber_mem_mgmt.h"
    #if defined(GFX_MGR02_USER_DEFINED_MM)
        #include "hmi_gfx_mgr02_mem_config.h"
    #endif
#else
  /* Currently tested only for Kepler-2 platform, later it can be open for OVG platform as well */
    #if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
        #error "GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE/HARFBUZZ is valid only for Amber/AmberIris"
    #endif
#endif

#if defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
    #include "hmi_gfx_mgr02_imxrt_mem_mgmt.h"
    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
        #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
            #if defined(GFX_MGR02_USER_DEFINED_MM)
                #include "hmi_gfx_mgr02_mem_config.h"
            #endif
        #endif
    #endif
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)))
 #ifndef GFX_MGR02_DPI
  #define GFX_MGR02_DPI (72)
 #endif
#endif

typedef enum
{
  GFX_MGR02_DONE,
  GFX_MGR02_PARTIALLY_DONE,
  GFX_MGR02_NOT_DONE
}GFX_MGR02_CTX_INIT_STATUS;

/*
** Bitmask for invisible flag
*/
#define GFX_MGR02_CONTEXT_ALPHA_FLAG (0x01)
#define GFX_MGR02_CONTEXT_CLIP_FLAG  (0x02U)
#define GFX_MGR02_CONTEXT_INVALID   0x00U
#define GFX_MGR02_CONTEXT_INTIALIZED  0x01U

#define GFX_MGR02_CLR_CONTEXT_ALPHA_FLAG (0xFEU)
#define GFX_MGR02_CLR_CONTEXT_CLIP_FLAG  (0xFDU)
typedef struct
{
   GFX_MGR02_ILOC_DATA             loc;
   GFX_MGR02_ALPHA                 alpha;
   UINT8                           invisible;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
   GFX_FLOAT                       matrix[9];
#endif
   GFX_MGR02_VISIBLE_AREA          clip;
}GFX_MGR02_CONTEXT_STATE_T;

#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
typedef struct
{
FT_Face    ft2_face;
UINT8      ft2_font_size;
} GFX_MGR02_FT2_FACE_PROP_T;
#endif


typedef struct
{
   UINT8                 layer_id;
   UINT8                 fb_format;   /* frame buffer pix format   */
   UINT8                 fb_target;   /* target library to be used */
   GFX_UINT              alignment:2; /* text alignment            */
   GFX_UINT              draw_mode:2; /* text draw mode            */
   GFX_UINT              clip_mode:3; /* text clip mode            */
   UINT8                 font_id;     /* text font id              */
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
   UINT8                 shaping_required;/* Text shaping is needed/not             */
#endif
#endif
   UINT16                scroll_offset;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
   GFX_MGR02_FONT_SIZE_T font_size;
#endif
   UINT16                clut;        /* clut to be used           */
   GFX_MGR02_ISIZE_W_T   fb_w;        /* frame buffer width        */
   GFX_MGR02_ISIZE_H_T   fb_h;        /* frame buffer height       */
   void                * fb_P;        /* Pointer to frame buffer   */
   GFX_MGR02_COLOR       fg_color;    /* foreground color          */
   GFX_MGR02_COLOR       bg_color;    /* background color          */
   GFX_MGR02_ISIZE_W_T   text_width;  /* text box width  */
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
   GFX_MGR02_FLOC_DATA   pivot;                 /* pivot point xy  */
#endif
#if (defined(GFX_MGR02_AMBER_IRIS)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)) && !defined(GFX_MGR02_IMXRT)
   #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
   MML_GDC_SYNC          pe_sync;
   #endif
   MML_GDC_PE_CONTEXT    pe_ctx;
   MML_GDC_SURFACE       pe_tsurf;
#endif
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0) 
   #if defined(GFX_MGR02_AMBER_IRIS)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
   MML_GDC_SURFACE       pe_msurf;  /* mask surface */
   #endif
   UINT8                 mask_mode;
#endif
#if defined(GFX_MGR02_FUJITSU)
   MML_GDC_PE_CONTEXT    pe_ctx;
   MML_GDC_SURFACE       pe_tsurf;
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
 #if((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
  FT_Library ft2_library;
  GFX_MGR02_FT2_FACE_PROP_T    ft2_faceprop[GFX_MGR02_NUM_OF_FONTS];
 #endif
 #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
  FS_STATE mt_fs_state;
  FILECHAR mt_font_name[GFX_MGR02_NUM_OF_FONTS][MAX_FONT_NAME_LEN];
 #endif
#endif

#if defined(GFX_MGR02_TRAVEO2)
  UINT32  priority;    /*There is no priority difference between the OTF tasks. Priority is applicable for the memory tasks*/
  UINT16  wdg_height;  /*store surface height for of OTF mode widget*/
  UINT8   render_mode; /*LBO or IBO*/

#endif
#if defined(GFX_MGR02_OPEN_GL)	&&  defined(GFX_MGR02_DYNAMIC_BOUNDS_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
   HMI_CHAR       * gl_string_ptr;
#endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
   UINT8            max_shrink;
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
   UINT32 pre_render_index;
#endif
}GFX_MGR02_CONTEXT_RENDER_PROP_T;

typedef struct
{
   GFX_MGR02_CONTEXT_STATE_T       state;
   GFX_MGR02_CONTEXT_RENDER_PROP_T rprop;
}GFX_MGR02_CONTEXT_T;

typedef struct
{
   UINT32                client_id;
   #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
   UINT8                 fb_group_id;
   #endif
   GFX_MGR02_IAREA_DATA  area;
   UINT32                fb_format;
   UINT32                fb_target;
   UINT32                clr_buffer;
   UINT32                clr_color;
   void                * render_buffer;
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)	|| defined(GFX_MGR02_AMBER_IRIS) )&& !defined(GFX_MGR02_IMXRT)
   #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
   MML_GDC_SYNC          pe_sync;
   #endif
   MML_GDC_PE_CONTEXT    pe_ctx;
   MML_GDC_SURFACE       pe_tsurf;
   #if GFX_MGR02_NUM_MASK_WIDGETS>0
   MML_GDC_SURFACE       pe_msurf;
   UINT8                 mask_mode;
   #endif
   #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
   UINT8                 use_extram; 
   #endif
#endif
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)	|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT))
   UINT32                dirty_area;
#endif
#if defined(GFX_MGR02_TRAVEO2)  
   UINT32 priority;
   UINT16 wdg_height;
   UINT8 render_mode;
#endif
}GFX_MGR02_CONTEXT_GB_T;
#if defined(GFX_MGR02_FARADAY)
extern UINT8   gpu_init(void);
extern UINT8   gpu_fini(void);
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

UINT32 hmi_gfx_mgr02_context_initialize(void);
void hmi_gfx_mgr02_context_shutdown(void);
GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_get_ptr(void);
void hmi_gfx_mgr02_context_reset_state(void);

void hmi_gfx_mgr02_context_state_set(GFX_MGR02_CONTEXT_STATE_T const * p_context);
void hmi_gfx_mgr02_context_state_get(GFX_MGR02_CONTEXT_STATE_T * p_context);
void hmi_gfx_mgr02_context_set_alpha(u_gx_flocal p_alpha);
void hmi_gfx_mgr02_context_set_loc(GFX_MGR02_ILOC_DATA const * p_xy_SP);

#if (GFX_MGR02_NUM_MASK_WIDGETS > 0) && (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
void hmi_gfx_mgr02_context_set_masksurf(MML_GDC_SURFACE const p_pe_msurf);
void hmi_gfx_mgr02_context_render_get(GFX_MGR02_CONTEXT_RENDER_PROP_T * p_context);
void hmi_gfx_mgr02_context_render_set(GFX_MGR02_CONTEXT_RENDER_PROP_T const * p_context);
#endif
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0) 
void hmi_gfx_mgr02_context_set_maskmode(UINT8 p_mask_mode);
#endif
#if (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) 
void hmi_gfx_mgr02_context_set_text_width(GFX_MGR02_ISIZE_W_T p_text_width);
#endif
void hmi_gfx_mgr02_context_set_textprop(u_gx_flocal p_font_id,
                                        u_gx_flocal p_alignment,
                                        u_gx_flocal p_draw_mode,
                                        u_gx_flocal p_clip_mode,
                                        u_gx_flocal p_scroll_offset,
                                        u_gx_flocal p_width
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE || GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE )&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE))
                                       ,UINT8 p_font_pt_size
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                                        , UINT8 p_shapping_required
#endif
#endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
                                       ,UINT8 p_max_shrink
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                                       ,UINT32 p_pre_render_index
#endif
                                       );

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
UINT8 hmi_gfx_mgr02_context_get_ft2_font_size(UINT32 p_font_id);
void hmi_gfx_mgr02_context_set_ft2_font_size(UINT32 p_font_id, UINT8 p_fnt_pt_size);
UINT32 hmi_gfx_mgr02_context_get_ft2_face_index(UINT32 p_font_id);
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)) && !defined (GFX_MGR02_KEPLER)
FS_STATE* hmi_gfx_mgr02_get_mt_client_handler(void);
#endif

void hmi_gfx_mgr02_context_set_fg_color(GFX_MGR02_COLOR p_fg_color);
void hmi_gfx_mgr02_context_set_bg_color(GFX_MGR02_COLOR p_bg_color);
void hmi_gfx_mgr02_context_set_clut(u_gx_flocal p_clut);

void hmi_gfx_mgr02_context_set_clip(GFX_MGR02_IAREA_DATA const * p_clip_SP);
UINT32 hmi_gfx_mgr02_context_combine_clip(GFX_MGR02_VISIBLE_AREA     * p_cur_clip_SP, 
                                          GFX_MGR02_IAREA_DATA const * p_new_clip_SP);
UINT32 hmi_gfx_mgr02_context_validate_clip(GFX_MGR02_VISIBLE_AREA       * p_cur_clip_SP, 
                                           GFX_MGR02_VISIBLE_AREA const * p_new_clip_SP);


#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
void hmi_gfx_mgr02_context_set_clip_va(GFX_MGR02_VISIBLE_AREA const * p_clip_SP);
UINT8 hmi_gfx_mgr02_context_is_widget_builded_first(const GFX_MGR02_CONTEXT_GB_T * p_cgb);
#endif
SINT32 hmi_gfx_mgr02_context_copy_fb(UINT32 p_client_layer_id, GFX_MGR02_CONTEXT_T const * p_cntx_SP);
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
void hmi_gfx_mgr02_context_set_matrix(GFX_FLOAT const * p_matrix);
void hmi_gfx_mgr02_context_set_pivot(GFX_MGR02_FLOC_DATA const * p_pivot);
void hmi_gfx_mgr02_context_mul_matrix(GFX_FLOAT * p_dest_matrix, GFX_FLOAT const * p_src_matrix);
#endif

GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_begin_update(u_gx_flocal p_layer_id, GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP, u_gx_flocal p_lock);
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)
void * hmi_gfx_mgr02_context_swap_layer(u_gx_flocal p_layer_id);
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) ||defined(GFX_MGR02_FUJITSU)
void hmi_gfx_mgr02_context_pre_copy_fb(u_gx_flocal p_layer_id);
void hmi_gfx_mgr02_context_back_fb_supdate(u_gx_flocal p_layer_id, u_gx_flocal p_update);
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS) ||defined (GFX_MGR02_TRAVEO2) ||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
void hmi_gfx_mgr02_context_end_update(u_gx_flocal p_layer_id, UINT32 p_updated);
#endif

#if defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT)||defined(GFX_MGR02_FUJITSU)
void * hmi_gfx_mgr02_context_alloc_fb(u_gx_flocal p_pix_format, 
                                      u_gx_flocal p_fb_width, 
                                      u_gx_flocal p_fb_height);
#endif

#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0) ||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
void hmi_gfx_mgr02_context_widget_prepare(void);
void hmi_gfx_mgr02_context_widget_set_active(UINT32 p_client_id);
void hmi_gfx_mgr02_context_widget_end_update(UINT32 p_client_id, 
                                             UINT32 p_updated
#if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)											 
											 ,UINT8 p_use_extram
#endif											 
											 );
void * hmi_gfx_mgr02_context_swap_widget(u_gx_flocal p_client_id);
void hmi_gfx_mgr02_context_widget_done(void);
#endif

#if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_AMBER) || defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)|| defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_widget_begin_update(GFX_MGR02_CONTEXT_GB_T * p_cgb);
#endif

#if ((defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_TRAVEO2)) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))))
void hmi_gfx_mgr02_context_free_amber_pathbuffers(void);
#endif
#if defined (GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined (GFX_MGR02_IMXRT)
void hmi_gfx_mgr02_context_reset_widget_buff_id(void);
#if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)
MML_GDC_PE_CONTEXT hmi_gfx_mgr02_context_get_pixeng_ctx(UINT32 client_id);
void * hmi_gfx_mgr02_context_get_fb(GFX_UINT client_id, GFX_UINT buffer_id);
#endif
#endif
#if ((defined (GFX_MGR02_IMXRT) || defined (GFX_MGR02_AMBER)|| defined (GFX_MGR02_TRAVEO2)) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0))
void * hmi_gfx_mgr02_context_get_front_fb(GFX_UINT client_id);
GFX_CONTEXT_EXTERN void hmi_gfx_mgr02_manage_widget_memory(void);
#endif
#if defined (GFX_MGR02_SOFTWARE)
void* hmi_gfx_mgr02_context_get_front_fb(u_gx_flocal p_layer_id);
#endif
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && (((GFX_MGR02_NUM_OF_SVGS > 0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)) && defined(GFX_MGR02_VGLITE)))
GFX_CONTEXT_EXTERN void * hmi_gfx_mgr02_context_get_path_cmd_buf(void);
#endif

#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE))
GFX_CONTEXT_EXTERN void * hmi_gfx_mgr02_context_get_sw_decompr_buffer(void);
#endif

#if (defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_USE_TIDSS))
GFX_CONTEXT_EXTERN void * hmi_gfx_mgr02_context_get_fb_addr(UINT32 p_frame_index);
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
** CMS Rev 1.22     19-Sep-2017    KKUBENDI
** 939889: Mazda J59: Kepler2- Graphics building in HRAM and transfer to VRAM to display
**
** CMS Rev 1.21     18-Sep-2017     ARAJASE2
** 921462: Dynamic Font update issue in Amber platform with External font
** hmi_gfx_mgr02_context_set_textprop function is changed to accept font_size parameter
** font_size array is replaced with single object in GFX_MGR02_CONTEXT_RENDER_PROP_T structure
**
** CMS Rev 1.20     1-Sep-2017    CSAKTHIV
** 944993: Dirty Area Enabling lead to deallocation of memory
**
** CMS Rev 1.19     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.18     23-Aug-2017    ADEVI
** 929657: Dynamic Text Width Change
** 
** CMS Rev 1.17     06-JUL-2017    ADEVI
** RTC ID: 871825:  Changes to support MONOTFT Platform
**
** CMS Rev 1.16     07/02/2016    SBOLLAM
** RTC ID: 750237: Updated error logging capability and added
**                 OVG software recovery capability
**
** CMS Rev 1.15      15-Dec-2016    VGAJJI
** 756979: B515 Compiler warnings Fix
**
** CMS Rev 1.14      16-DEC-2016    EMANOJ1
** Faraday Future - Touch object auto selection does not work (RTC : 767349)
** Updates due to function prototype change
**
** CMS Rev 1.13     15-Dec-2016    SSIGAMAN
** 766753: BAIC:Provide option to allocate memory for frame buffer in HRAM
** Included hmi_gfx_mgr02_amber_mem_mgmt.h file.
** 
** CMS Rev 1.12     18-July-2016    SSIGAMAN
** RTC 639228: 
** PR Comments Fix. The alpha and path buffer variables are used within the 
** GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0 conditional check.
**
** CMS Rev 1.11     5-May-2016    SSIGAMAN
** RTC 628373: Freetype text rendering: 1st character is missing in the 
**             1st rendering string of the context if morethan 1 pixel engine context used.
** Changes are done in such a manner that the pixel engine context to have their own path buffers.
** 
** CMS Rev 1.10     5-May-2016    SSIGAMAN
** RTC 587998: Prototype missing compiler issue 
** The prototype for the API hmi_gfx_mgr02_context_set_text_width() added.
** 
** CMS Rev 1.9     4-May-2016    SSIGAMAN
** RTC 571865: 
** The structure member da_redraw in GFX_MGR02_CONTEXT_GB_T is removed
** as per PR comments.
**
** CMS Rev 1.8     28-Apr-2016    ADEVI
** 543906:
** To support dynamic change of the text box size
** 
** CMS Rev 1.7     17-Mar-2016    SSIGAMAN
** 549069:
** New API added to support Dirty Area Redraw in Amber.
**
** CMS Rev 1.6     3-Nov-2015    SSIGAMAN
** RTC 456457:
** Dirty Area Redraw is applicable for merge widgets with CLIP=TRUE. 
** So, one flag named da_redraw was added in GFX_MGR02_CONTEXT_GB_T.
**
** CMS Rev 1.5     3-Nov-2015    SSIGAMAN
** RTC 456457:
** Added prototype for hmi_gfx_mgr02_context_copy_fb().
**
** CMS Rev 1.4     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.3     17-Mar-2014    EMANOJ1
** RTC : Defect 133048
** Removed macros to calculate point size from pixelsize as they were not correct
** 
** CMS Rev 1.2      15-May-2012    EMANOJ1
** hmi_gfx_mgr02_context_validate_clip renamed as hmi_gfx_mgr02_context_combine_clip
** because it was doing a combing and validation operation .
** Added hmi_gfx_mgr02_context_set_clip_va to accept clip area as 
** GFX_MGR02_VISIBLE_AREA type.
** Added a paremeter to hmi_gfx_mgr02_context_end_updateto specify whether any
** update is made to the framebuffer to decide whether to swap the buffer or not
**
** CMS Rev 1.1      15-Mar-2012    ASHEKHAR
** Resolved issue with respect to default matrix. OpenVG origin is at bottom
**
** CMS Rev 1.0      08-Aug-12    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
