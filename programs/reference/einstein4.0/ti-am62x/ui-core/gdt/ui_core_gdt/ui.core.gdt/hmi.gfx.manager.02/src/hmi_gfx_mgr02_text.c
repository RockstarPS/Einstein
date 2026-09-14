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
** Name:           hmi_gfx_mgr02_text.c
**
** Description:    Main graphics manager 02 text print module
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_MGR02_TEXT_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_font.h"
#include "hmi_gfx_mgr02_text.h"
#if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))
#include <freetype/ftsynth.h>
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
#include "hmi_gfx_mgr02_cache.h"
#endif

#if defined(GFX_MGR02_KEPLER)
#include "dma.handler.h"
#include "DCU.h"
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)
#error "Invalid configuration. GFX_MGR02_HORIZONTAL_SCROLL_ENABLED macro not applicable for rotated display."
#endif
#include "graphics.h"
#include "hmi_gfx_mgr02_dcu.h"
#include "hmi_gfx_mgr02_mem.h"
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#include "ExtFontEngine_wrapper.h"
#endif
#endif
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
#include "fs_itype.h"
#endif
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
#define GFX_MGR02_FONT_IDLE   (55u)
#define GFX_MGR02_FONT_LOAD   (1u)
#define GFX_MGR02_FONT_PRINT  (2u)
#define GFX_MGR02_FONT_ENDING (3u)



/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
#if defined(GFX_MGR02_KEPLER)
static UINT32 hmi_gfx_mgr02_font_fsl_edma_sm(UINT8 p_eDMAChannel, UINT32 p_dma_cb);
static void   hmi_gfx_mgr02_font_fsl_edma_cb(dma_handler_app_resp_struct * p_app_resp_S);
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
static void   hmi_gfx_mgr02_font_dual_transfer_edma_cb(void);
#endif
#endif
static GFX_MGR02_FONT_CHAR_CONFIG const * hmi_gfx_mgr02_get_fcc_ptr(HMI_CHAR p_char,
  GFX_MGR02_FONT_LUT const * p_font_lut_SP,
  UINT32 p_table_size,
  UINT32 p_vg_font);
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
static UINT32 hmi_gfx_mgr02_ft2_get_text_width(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                               UINT32                p_font_id,
                                             #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)  
                                               UINT32                p_clip_mode,
                                             #endif  
                                               UINT32                p_alignment
                                             #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                               ,HMI_CHAR            * p_string
                                             #endif
                                             #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                               ,GFX_MGR02_SHAPE_INFO  *p_shaper_info
                                             #endif
                                              ); 
#endif                                        

#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
static UINT32 hmi_gfx_mgr02_mt_get_text_width(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                              UINT32            p_font_id,
                                              UINT32            p_clip_mode,
                                              UINT32            p_alignment
                                            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                              ,HMI_CHAR        * p_string
                                            #endif
                                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                               ,GFX_MGR02_SHAPE_INFO  *p_shaper_info
                                            #endif
                                              );
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
static UINT32 hmi_convert_utf32cp_to_utf16cp(HMI_CHAR* p_out, UINT32 const* p_src, UINT32 p_length);
#endif
#endif

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**===========================================================================*/

#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
#if GFX_MGR02_MAX_TEXT_LENGTH <= GFX_MGR02_APPEND_CHAR_CNT
#error "GFX_MGR02_MAX_TEXT_LENGTH should be > GFX_MGR02_APPEND_CHAR_CNT"
#endif
#endif

#if defined(GFX_MGR02_KEPLER)
static hmi_gfx_mgr02_font_callback_type hmi_gfx_mgr02_font_callback;
static HMI_CHAR           const * l_edma_string;
static GFX_MGR02_FONT_LUT const * l_font_lut_SP;
static GFX_MGR02_FONT     const * l_font_SP;
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
static UINT32                     l_font_id;
#endif
static UINT32                     l_dest_address;
static UINT32                     l_dest_width;
static SINT32                     l_text_y_offset;
static UINT8             volatile l_fsl_text_task_state;
static UINT8                      l_string_length;
static UINT8                      l_devider;
static UINT8                      l_text_height;
static UINT32                     l_cur_x_offset;
#if (((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED))))
static UINT16                     l_max_available_width;
static UINT16                     l_displayed_width;
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
static SINT32                     l_text_horizontal_offset;
static Graphics_Object_t          l_text_source_go;
static Graphics_Object_t          l_text_target_go;
#endif
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
static volatile UINT8             l_text_char_printed;
#endif
#endif

#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
static GFX_MGR02_FNT_GRP_DYN_PROP l_gfx_mgr02_font_grp_prop_S[GFX_MGR02_NUM_OF_FONT_GROUPS];
#endif
#if (defined(GFX_MGR02_KEPLER) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE))) 
extern UINT8 const lc_gfx_mono_append_txt_font_width[];
#endif
#if (defined(GFX_MGR02_KEPLER) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)))
extern UINT8 const lc_gfx_digi_append_txt_font_width[];
#endif

#if GFX_MGR02_NUM_OF_DTEXTS > 0 
 #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
      #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
        extern GFX_MGR02_SHAPE_ML_DATA l_shape_ml_dtext_buffer[GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS];
      #endif
 #endif
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_init
** Visibility:       global
** Description:      Initialises the Font library control variables
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          05-Feb-2013 by ASHEKHAR
** Updated:          05-Feb-2013 by ASHEKHAR
**==========================================================================*/
void hmi_gfx_mgr02_font_init(void)
{
#if defined(GFX_MGR02_KEPLER)
  hmi_gfx_mgr02_font_callback  = GFX_MGR02_NULL_PTR;
  l_edma_string                = GFX_MGR02_NULL_PTR;
  l_font_lut_SP                = GFX_MGR02_NULL_PTR;
  l_font_SP                    = GFX_MGR02_NULL_PTR;
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
  l_font_id                    = 0xFFFFFFFFUL;
#endif
  l_dest_address               = 0;
  l_dest_width                 = 0;
  l_text_y_offset              = 0;
  l_fsl_text_task_state        = GFX_MGR02_FONT_IDLE;
  l_string_length              = 0;
  l_devider                    = 0;
  l_text_height                = 0;
#endif
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
  (void)memset((void *)&l_gfx_mgr02_font_grp_prop_S[0], 0, sizeof(l_gfx_mgr02_font_grp_prop_S));
#endif

}

#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_select_gfont
** Visibility:       global
** Description:      Sets a selected font index and the right2left flag for a
**                   passed font group ID
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_select_gfont(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left)
{
  UINT32                 fl_ret_sts = FALSE;
#if GFX_MGR02_NUM_OF_FONTS > 0
  GFX_MGR02_FONT       const * fl_font;
  UINT32                       fl_gfont_id;
  GFX_MGR02_FNT_GRP_DYN_PROP * fl_gfont_prop;
  if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    fl_font = &lc_gfx_font_table[p_font_id];
    if(fl_font->is_group != 0U)
    {
      fl_gfont_id = fl_font->p.group_sel_index;
      if(fl_gfont_id < (UINT32)GFX_MGR02_NUM_OF_FONT_GROUPS)
      {
        fl_gfont_prop = &l_gfx_mgr02_font_grp_prop_S[fl_gfont_id];
        if(fl_gfont_prop->group_selection != (GFX_UINT)p_selection_index)
        {
          fl_gfont_prop->group_selection = (GFX_UINT)p_selection_index;
          fl_ret_sts = TRUE;
        }
        if(fl_gfont_prop->right2left != (GFX_UINT)p_right2left)
        {
          fl_gfont_prop->right2left      = (GFX_UINT)p_right2left;
          fl_ret_sts = TRUE;
        }
      }
    }
  }
#endif
  return(fl_ret_sts);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_gfont_prop
** Visibility:       global
** Description:      Returns the dynamic property related to the passed
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
GFX_MGR02_FNT_GRP_DYN_PROP * hmi_gfx_mgr02_get_gfont_prop(UINT32 p_font_id)
{
  GFX_MGR02_FNT_GRP_DYN_PROP * fl_gfont_prop = GFX_MGR02_NULL_PTR;
#if GFX_MGR02_NUM_OF_FONTS > 0
  GFX_MGR02_FONT const * fl_font;
  UINT32                 fl_gfont_id;
  if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    fl_font = &lc_gfx_font_table[p_font_id];
    if(fl_font->is_group != 0U)
    {
      fl_gfont_id = fl_font->p.group_sel_index;
      if(fl_gfont_id < (UINT32)GFX_MGR02_NUM_OF_FONT_GROUPS)
      {
        fl_gfont_prop = &l_gfx_mgr02_font_grp_prop_S[fl_gfont_id];
      }
    }
  }
#endif
  return(fl_gfont_prop);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_gfont_alignment
** Visibility:       global (but for local used by gfx02)
** Description:      Returns the modified alignment value for a group font.
**                   Group font supports a right2left which if set by apps
**                   will change all right align to left and left align to
**                   right. So gfx02 uses this function to get the modified
**                   alignment based on this rule.
** Invocation:       Invoked by gfx02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          12-Jun-2013 by EMANOJ1
** Updated:          12-Jun-2013 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_get_gfont_alignment(UINT32 p_font_id, UINT32 p_alignment)
{
  UINT32 fl_alignment = p_alignment;
#if GFX_MGR02_NUM_OF_FONTS > 0
  GFX_MGR02_FONT const * fl_font;
  UINT32                 fl_gfont_id;
  if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    fl_font = &lc_gfx_font_table[p_font_id];
    if(fl_font->is_group != 0U)
    {
      fl_gfont_id = fl_font->p.group_sel_index;
      if(fl_gfont_id < (UINT32)GFX_MGR02_NUM_OF_FONT_GROUPS)
      {
        if(l_gfx_mgr02_font_grp_prop_S[fl_gfont_id].right2left != 0U)
        {
          /*
          ** If right to left flag is set then change all the left alignment
          ** to right alignment AND right alignment to left.
          */
          if(fl_alignment == GFX_MGR02_TP_ALIGN_LEFT)
          {
            fl_alignment = GFX_MGR02_TP_ALIGN_RIGHT;
          }
          else if(fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
          {
            fl_alignment = GFX_MGR02_TP_ALIGN_LEFT;
          }
          else
          {
              /*For Fixing MISRA warning.*/
          }
        }
      }
    }
  }
#endif
  return(fl_alignment);
}
#endif


/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_font_id
** Visibility:       global
** Description:
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          05-Feb-2013 by EMANOJ1
** Updated:          05-Feb-2013 by EMANOJ1
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
UINT32 hmi_gfx_mgr02_get_font_id(UINT32 p_font_id)
{
  UINT32 fl_font_id;
  fl_font_id = p_font_id;
#if GFX_MGR02_NUM_OF_FONTS > 0
  if(fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
    GFX_MGR02_FONT const * fl_font = &lc_gfx_font_table[fl_font_id];
    if((fl_font->is_group != 0U) && (fl_font->p.group_sel_index < (UINT8)GFX_MGR02_NUM_OF_FONT_GROUPS))
    {
      fl_font_id = l_gfx_mgr02_font_grp_prop_S[fl_font->p.group_sel_index].group_selection;
      if(fl_font_id < fl_font->size_table)
      {
        fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_font->f.grp_ptr[fl_font_id]);
      }
    }
#endif
  }
  else
#endif
  {
    fl_font_id = (UINT32)GFX_MGR02_NUM_OF_FONTS;
  }
  return(fl_font_id);
}


#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
/*============================================================================
** Function Name:    hmi_gfx_mgr02_is_autohint_enabled
** Visibility:       global
** Description:
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   p_font_id, autohint enabled or not.
** Critical Section: None.
** Created:          24-Mar-2016 by SSIGAMAN
** Updated:          
**==========================================================================*/
BOOLEAN hmi_gfx_mgr02_is_autohint_enabled(UINT32 p_font_id)
{
  BOOLEAN fl_ret_bool =FALSE;	
#if GFX_MGR02_NUM_OF_FONTS > 0
  if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    GFX_MGR02_FONT const * fl_font = &lc_gfx_font_table[p_font_id];
    if(fl_font->is_autohint != ((UINT8)0))
    {
      fl_ret_bool=TRUE;
    }
  }
#endif
  return(fl_ret_bool);
}

#endif
/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_init
** Visibility:       global
** Description:      Initialises the Font library control variables
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          05-Feb-2013 by EMANOJ1
** Updated:          05-Feb-2013 by EMANOJ1
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
GFX_MGR02_FONT const * hmi_gfx_mgr02_get_font_pointer(UINT32 p_font_id)
{ 
    GFX_MGR02_FONT const * fl_font = GFX_MGR02_NULL_PTR;
#if GFX_MGR02_NUM_OF_FONTS > 0
    UINT32 fl_font_id = p_font_id;

    if(fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
        fl_font = &lc_gfx_font_table[fl_font_id];
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
        if((fl_font->is_group != 0U) && (fl_font->p.group_sel_index < (UINT8)GFX_MGR02_NUM_OF_FONT_GROUPS))
        {
            fl_font_id = l_gfx_mgr02_font_grp_prop_S[fl_font->p.group_sel_index].group_selection;
            if(fl_font_id < fl_font->size_table)
            {
                fl_font = hmi_gfx_mgr02_get_font_pointer((UINT32)fl_font->f.grp_ptr[fl_font_id]);
            }
            else
            {
                fl_font = GFX_MGR02_NULL_PTR;
            }
        }
#endif
    }
    else
    {
        fl_font = GFX_MGR02_NULL_PTR;
    }
#else
    {
        GFX_MGR02_UNUSED_VAR(p_font_id);
    }
#endif
    return(fl_font);
}
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_grp_default_font_ptr
** Visibility:       global
** Description:      Gives the default font id from font group
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          03-Aug-2015 by SBOLLAM
** Updated:          03-Aug-2015 by SBOLLAM
**==========================================================================*/
GFX_MGR02_FONT const * hmi_gfx_mgr02_get_grp_default_font_ptr(UINT32 p_font_id)
{
  GFX_MGR02_FONT const * fl_font;
#if GFX_MGR02_NUM_OF_FONTS > 0
  if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    fl_font = &lc_gfx_font_table[p_font_id];
    if(fl_font->is_group != 0U)
    {
      if(fl_font->default_index < fl_font->size_table)
      {
        fl_font = hmi_gfx_mgr02_get_font_pointer((UINT32)fl_font->f.grp_ptr[fl_font->default_index]);
      }
      else
      {
        fl_font = GFX_MGR02_NULL_PTR;
      }
    }
    else
    {
      fl_font = GFX_MGR02_NULL_PTR;
    }
  }
  else
#endif
  {
    fl_font = GFX_MGR02_NULL_PTR;
  }
  return(fl_font);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_fcc
Description          : Gets the FCC for the requested char. If it tunes out 
to be NULL (non-existing) then trys to get FCC for 
the default char.
Invocation           : Invoke with Char to be looked and Font table pointer
Parameters           : p_char        - Char to be searched
p_font_lut_SP - Pointer to font table
Return Value         : Char info structure pointer or NULL pointer
Critical Section     : None
External Interfaces  : Font data tables.
******************************************************************************/
GFX_MGR02_FONT_CHAR_CONFIG const * hmi_gfx_mgr02_get_fcc(HMI_CHAR p_char,
  GFX_MGR02_FONT_LUT const * p_font_lut_SP,
  UINT32 p_table_size,
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
  UINT32 p_font_id,
#endif
  UINT32 p_vg_font)
{
  GFX_MGR02_FONT_CHAR_CONFIG const * fl_fcc;
  fl_fcc = hmi_gfx_mgr02_get_fcc_ptr(p_char, p_font_lut_SP, p_table_size, p_vg_font);
#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
  if(fl_fcc == GFX_MGR02_NULL_PTR)
  {
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
    GFX_MGR02_FONT             const * fl_font_SP;
    GFX_MGR02_FONT_LUT         const * fl_font_lut_SP;
    UINT32                fl_vg_font;
    fl_font_SP = hmi_gfx_mgr02_get_grp_default_font_ptr(p_font_id);
    if(fl_font_SP != GFX_MGR02_NULL_PTR)
    {
      if(fl_font_SP->is_vfont != 0U)
      {
#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
        fl_font_lut_SP = fl_font_SP->f.ovg_ptr->lut_ptr;
#else
        fl_font_lut_SP = GFX_MGR02_NULL_PTR;
#endif
        fl_vg_font = TRUE;
      }
      else
      {
        fl_font_lut_SP = fl_font_SP->f.lut_ptr;
        fl_vg_font     = FALSE;
      }
      if(fl_font_lut_SP != GFX_MGR02_NULL_PTR)
      {
        fl_fcc = hmi_gfx_mgr02_get_fcc_ptr(p_char, fl_font_lut_SP, fl_font_SP->size_table, fl_vg_font);
        if(fl_fcc == GFX_MGR02_NULL_PTR)
        {
          fl_fcc = hmi_gfx_mgr02_get_fcc_ptr((HMI_CHAR)GFX_MGR02_DEFAULT_CHAR, p_font_lut_SP, p_table_size, p_vg_font);
          if(fl_fcc == GFX_MGR02_NULL_PTR)
          {
            fl_fcc = hmi_gfx_mgr02_get_fcc_ptr((HMI_CHAR)GFX_MGR02_DEFAULT_CHAR, fl_font_lut_SP, fl_font_SP->size_table, fl_vg_font);
          }
        }
      }
    }
    else
    {
      fl_fcc = hmi_gfx_mgr02_get_fcc_ptr((HMI_CHAR)GFX_MGR02_DEFAULT_CHAR, p_font_lut_SP, p_table_size, p_vg_font);
    }
#else
    fl_fcc = hmi_gfx_mgr02_get_fcc_ptr((HMI_CHAR)GFX_MGR02_DEFAULT_CHAR, p_font_lut_SP, p_table_size, p_vg_font);
#endif
  }
#endif
  return fl_fcc;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_fcc_ptr
Description          : Searches for the passed character in the font table
and returns the pointer to the char info structure.
If the char is missing then returns NULL pointer.
Invocation           : Invoke with Char to be looked and Font table pointer
Parameters           : p_char        - Char to be searched
p_font_lut_SP - Pointer to font table
Return Value         : Char info structure pointer or NULL pointer
Critical Section     : None
External Interfaces  : Font data tables.
******************************************************************************/
static GFX_MGR02_FONT_CHAR_CONFIG const * hmi_gfx_mgr02_get_fcc_ptr(HMI_CHAR p_char,
  GFX_MGR02_FONT_LUT const * p_font_lut_SP,
  UINT32 p_table_size,
  UINT32 p_vg_font)
{
  GFX_MGR02_FONT_LUT         const * fl_font_lut_SP = p_font_lut_SP;
  union
  {
    GFX_MGR02_FONT_CHAR_CONFIG const * all;
    GFX_MGR02_FONT_CHAR_CONFIG const * rf;
#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
    GFX_MGR02_OVG_GLYPH_DEF_T  const * vf;
#endif
  }fcc;

  fcc.all = GFX_MGR02_NULL_PTR;

#if (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_HYBRID) || (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_LINEAR)
#if (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_HYBRID)
  if(p_table_size <= 8U)
#endif
  {
    GFX_MGR02_FONT_LUT   const * fl_font_lut_end_SP;
    HMI_CHAR                     fl_base_char_code;
    UINT32                       fl_linear_temp_cnt = (UINT32)0;

    while(fl_linear_temp_cnt < p_table_size)
    {
      if(p_char == fl_font_lut_SP->ch_code)
      {
        fcc.all            = fl_font_lut_SP->fcc_ptr;
        fl_linear_temp_cnt = p_table_size;
      }
      else if(p_char > fl_font_lut_SP->ch_code)
      {
        if((fl_font_lut_SP->attributes & GFX_MGR02_FONT_SEARCH_MODE_TLUP) == GFX_MGR02_FONT_SEARCH_MODE_TLUP)
        {
          fl_base_char_code = fl_font_lut_SP->ch_code;
          fl_font_lut_end_SP = &fl_font_lut_SP[1];

          if(p_char <= fl_font_lut_end_SP->ch_code)
          {
            if(p_char != fl_font_lut_end_SP->ch_code)
            {
#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
              if(p_vg_font != FALSE)
              {
                fcc.all = fl_font_lut_SP->fcc_ptr;
                fcc.vf  = &fcc.vf[p_char - fl_base_char_code];
              }
              else
#endif
              {
                fcc.rf  = &fl_font_lut_SP->fcc_ptr[p_char - fl_base_char_code];
              }
            }
            else
            {
              fcc.all = fl_font_lut_end_SP->fcc_ptr;
            }
            /* Terminate the loop... */
            fl_linear_temp_cnt = p_table_size;
          }
          else
          {
            fcc.all = GFX_MGR02_NULL_PTR;
          }
          fl_font_lut_SP = &fl_font_lut_SP[1];
          fl_linear_temp_cnt++;
        }
      }
      else
      {
        fl_linear_temp_cnt = p_table_size;
      }
      fl_font_lut_SP++;
      fl_linear_temp_cnt++;
    }
  }
#endif
#if (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_HYBRID) || (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_BINARY)
#if (GFX_MGR02_CHAR_SEARCH_MODE == GFX_MGR02_LUP_HYBRID)
  else
#endif
  {
    UINT32 fl_high_U16 = p_table_size;
    UINT32 fl_low_U16  = (UINT32)0;
    UINT32 fl_mid_U16;

    fl_high_U16--;
    if((p_char >= fl_font_lut_SP[0].ch_code)&&(p_char <= fl_font_lut_SP[fl_high_U16].ch_code)) /*RTC #334189*/
    {
      while(fl_high_U16 > fl_low_U16)
      {
        fl_mid_U16 = (fl_high_U16 - fl_low_U16)>>1;
        if(fl_mid_U16 != (UINT32)0)
        {
          fl_mid_U16 += fl_low_U16;
          if(fl_font_lut_SP[fl_mid_U16].ch_code < p_char)
          {
            fl_low_U16 = fl_mid_U16;
          }
          else
          {
            fl_high_U16 = fl_mid_U16;
          }
        }
        else
        {
          if((fl_font_lut_SP[fl_low_U16].attributes & GFX_MGR02_FONT_SEARCH_MODE_TLUP) == GFX_MGR02_FONT_SEARCH_MODE_TLUP)
          {
            if(p_char >= fl_font_lut_SP[fl_low_U16].ch_code)
            {
              fcc.all = fl_font_lut_SP[fl_low_U16].fcc_ptr;
#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
              if(p_vg_font != FALSE)
              {
                fcc.vf = &fcc.vf[p_char - fl_font_lut_SP[fl_low_U16].ch_code];
              }
              else
#endif
              {
                fcc.rf = &fcc.rf[p_char - fl_font_lut_SP[fl_low_U16].ch_code];
              }
            }
          }
          else
          {
            if(p_char == fl_font_lut_SP[fl_high_U16].ch_code)
            {
              fcc.all = fl_font_lut_SP[fl_high_U16].fcc_ptr;
            }
            else if(p_char == fl_font_lut_SP[fl_low_U16].ch_code)
            {
              fcc.all = fl_font_lut_SP[fl_low_U16].fcc_ptr;
            }
            else
            {
                /*For Fixing MISRA warning.*/
            }
          }
          fl_high_U16 = (UINT32)0; /* Terminate the loop. */
        }
      }
    }
  }
#endif
  GFX_MGR02_UNUSED_VAR(p_vg_font);
  return(fcc.rf);
}

#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && defined (GFX_MGR02_SHAPE_ENGINE_ENABLED)
SINT16 hmi_gfx_mgr02_embold_glyph_advance(FT_GlyphSlot p_slot, SINT16 p_x_advance)
{
  /*algorithm taken from ftsynth.c->FT_GlyphSlot_AdjustWeight*/
  SINT16 fl_glyph_advance_x = p_x_advance;
  if ((p_slot != GFX_MGR02_NULL_PTR) && (p_slot->face != GFX_MGR02_NULL_PTR))
  {
    FT_Size size = p_slot->face->size;
    if (size != GFX_MGR02_NULL_PTR)
    {
      FT_Pos xstr = (FT_Pos)(size->metrics.x_ppem * GFX_MGR02_DEFAULT_BOLD_WEIGHT) / 1024;
      if (p_slot->format == FT_GLYPH_FORMAT_BITMAP)
      {
        xstr &= ~63;
        if (xstr == 0)
        {
          xstr = 1 << 6;
        }
      }
      if(p_x_advance != 0)
      {
        fl_glyph_advance_x = (SINT16)(p_x_advance + (xstr >> 6));
      }
    }
  }
  return fl_glyph_advance_x;
}
#endif
/*============================================================================
**==========================================================================*/
UINT32 hmi_gfx_mgr02_get_ft_char_width(FT_Face p_face, HMI_CHAR p_char, BOOLEAN p_autohint_bool
                                              #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                              , UINT8 p_font_size
                                              , UINT32 p_font_id 
                                              #endif
                                              #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                              ,GFX_MGR02_TXT_SPECIAL_EFFECTS const* p_txt_special_prop_SP
                                              #endif
                                              #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                              ,UINT8 p_complex_script
                                              ,hb_buffer_content_type_t p_content_type
                                              ,SINT16 p_x_advance
                                              #endif
                                              )
{
    UINT32  fl_char_width = 0U;
    FT_Face fl_face = p_face;
    if((p_char != '\0')
       #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
       && (p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
       #endif
      )
    {
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
      FTC_Manager fl_ftc_manager = hmi_gfx_mgr02_get_ft2_cachemgr_handler();
      UINT32 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(p_font_id);
      FT_Error ft_error = FTC_Manager_LookupFace(fl_ftc_manager, (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index], &fl_face);
      if (ft_error == FT_Err_Ok)
      {
        FT_Size fl_asize = GFX_MGR02_NULL_PTR;
        FTC_ScalerRec fl_scaler;
        fl_scaler.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
        fl_scaler.width = 0U;
        fl_scaler.height = (FT_UInt)(p_font_size * 64.0F);
        fl_scaler.pixel = 0;
        fl_scaler.x_res = GFX_MGR02_DPI;
        fl_scaler.y_res = GFX_MGR02_DPI;
        ft_error = FTC_Manager_LookupSize(fl_ftc_manager, &fl_scaler, &fl_asize);
        if ((ft_error == FT_Err_Ok) && (fl_asize != GFX_MGR02_NULL_PTR))
        {
          ft_error = FT_Activate_Size(fl_asize);
          fl_face = fl_asize->face;
          if (ft_error != FT_Err_Ok)
          {
#ifdef GFX02_DEBUG_INFO
            gfx_debug("Error in FT_Activate_Size \n");
#endif
          }
        }
        else
        {
#ifdef GFX02_DEBUG_INFO
          gfx_debug("Error in FTC_Manager_LookupSize \n");
#endif
        }
      }
      else
      {
#ifdef GFX02_DEBUG_INFO
        gfx_debug("Error in FTC_Manager_LookupFace \n");
#endif
      }
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      BOOLEAN fl_bitmap_done = FALSE;
      if (p_txt_special_prop_SP != GFX_MGR02_NULL_PTR)
      {
        if (p_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
        {
          UINT32 fl_flags = FT_LOAD_RENDER;
          if (p_autohint_bool != ((BOOLEAN)0))
          {
            fl_flags |= FT_LOAD_FORCE_AUTOHINT;
          }
          (void)FT_Load_Char(fl_face, p_char, fl_flags);
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if ((p_complex_script == (UINT8)TRUE) && (p_content_type == HB_BUFFER_CONTENT_TYPE_GLYPHS))
          {
            fl_char_width = hmi_gfx_mgr02_embold_glyph_advance(fl_face->glyph, p_x_advance);
          }
          else
#endif
          {
            (void)FT_GlyphSlot_AdjustWeight(fl_face->glyph, GFX_MGR02_DEFAULT_BOLD_WEIGHT, GFX_MGR02_DEFAULT_BOLD_WEIGHT);
            fl_char_width = fl_face->glyph->advance.x;
          }
          fl_bitmap_done = TRUE;
        }
      }
      if (fl_bitmap_done == FALSE)
#endif
      {
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        if ((p_complex_script == (UINT8)TRUE) && (p_content_type == HB_BUFFER_CONTENT_TYPE_GLYPHS))
        {
          fl_char_width = p_x_advance;
        }
        else
#endif
        {
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
          FT_Glyph fl_glyph = NULL;
          FTC_ImageTypeRec fl_type;
          FTC_ImageCache fl_ftc_image_cache;
          FT_Error fl_error = FT_Err_Ok;
          FT_UInt fl_cur_glyph_index = FT_Get_Char_Index(fl_face, p_char);
#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
          if (fl_cur_glyph_index == (FT_UInt)0)
          {
            fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)GFX_MGR02_DEFAULT_CHAR);
          }
#endif
          fl_ftc_image_cache = hmi_gfx_mgr02_get_ft2_imgcache_handler();

          fl_type.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
          fl_type.width = p_font_size;
          fl_type.height = p_font_size;
          fl_type.flags = FT_LOAD_RENDER;

          if (p_autohint_bool != ((BOOLEAN)0))
          {
            fl_type.flags |= FT_LOAD_FORCE_AUTOHINT;
          }
          if ((p_font_size != 0U) && (fl_type.face_id != NULL))
          {
            fl_error = FTC_ImageCache_Lookup(fl_ftc_image_cache, &fl_type, fl_cur_glyph_index, &fl_glyph, NULL);
          }
          else
          {
            fl_error = TRUE;
          }
          if ((FALSE == fl_error) && (fl_glyph != NULL))
          {
            fl_char_width = (fl_glyph->advance.x / 1024);
          }
          else
#endif
          {
            UINT32 fl_flags = FT_LOAD_RENDER;
            if (p_autohint_bool != ((BOOLEAN)0))
            {
              fl_flags |= FT_LOAD_FORCE_AUTOHINT;
            }
            (void)FT_Load_Char(fl_face, p_char, fl_flags);
            fl_char_width = fl_face->glyph->advance.x;
          }
        }
      }
    }
    /* In FreeType, widths and other dimensional values are represented in a 26.6 fixed-point format.
       This means 26 bits are used for the integer part and 6 bits for the fractional part.
       By shifting the integer width value 6 bits to the left, we convert it into the 26.6 fixed-point format */
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    if ((p_complex_script != (UINT8)TRUE) || (p_content_type != HB_BUFFER_CONTENT_TYPE_GLYPHS))
#endif
    {
       fl_char_width = (UINT32)(fl_char_width / 64U);/* Equivalent to right shift 6 times. */
    }

    return fl_char_width;
}
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
/*============================================================================
** Function Name:    hmi_gfx_mgr02_realign_shaper_output
** Visibility:       local
** Description:      Function used to shift p_shaper data for right side clipping
** Invocation:       Invoked by hmi_gfx_mgr02_ft2_get_text_width
** Inputs/Outputs:   p_shaper_ptr to be modified on the basis of p_dest_offset,p_src_offset and p_str_len.
** Critical Section: None.
** Created:          05-Feb-2013 by EMANOJ1
** Updated:          05-Feb-2013 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_mgr02_realign_shaper_output(GFX_MGR02_HB_SHAPE_INFO *p_shaper_ptr, SINT32 p_dest_offset, SINT32 p_src_offset,UINT32 p_str_len)
{
  (void)memmove(p_shaper_ptr->unicode + p_dest_offset,
                p_shaper_ptr->unicode + p_src_offset,
                p_str_len * sizeof(HMI_CHAR));
  (void)memmove(p_shaper_ptr->content_type + p_dest_offset,
                p_shaper_ptr->content_type + p_src_offset,
                p_str_len * sizeof(hb_buffer_content_type_t));

  (void)memmove(p_shaper_ptr->code_point + p_dest_offset,
                p_shaper_ptr->code_point + p_src_offset,
                p_str_len * sizeof(UINT32));

  (void)memmove(p_shaper_ptr->x_offset + p_dest_offset,
                p_shaper_ptr->x_offset + p_src_offset,
                p_str_len * sizeof(SINT16));

  (void)memmove(p_shaper_ptr->y_offset + p_dest_offset,
                p_shaper_ptr->y_offset + p_src_offset,
                p_str_len * sizeof(SINT16));

  (void)memmove(p_shaper_ptr->x_advance + p_dest_offset,
                p_shaper_ptr->x_advance + p_src_offset,
                p_str_len * sizeof(SINT16));
}
#endif
/*============================================================================
** Function Name:    hmi_gfx_mgr02_ft2_get_text_width
** Visibility:       global
** Description:
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          05-Feb-2013 by EMANOJ1
** Updated:          05-Feb-2013 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_ft2_get_text_width(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                               UINT32                p_font_id,
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                               UINT32                p_clip_mode,
#endif  
                                               UINT32                p_alignment
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                               ,HMI_CHAR            * p_string
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                               ,GFX_MGR02_SHAPE_INFO  *p_shaper_info
#endif
                                              )
{
  FT_Face          face = NULL;
  UINT32           fl_font_id          = hmi_gfx_mgr02_get_font_id(p_font_id);
  UINT32           fl_clip_flag_U8     = FALSE;
  UINT32           fl_tot_nb_char_U32   = (UINT32)0;  /* total number of character in the original string */
  SINT32           fl_tot_str_size     = 0;  /* Total size of string in pixel */
  HMI_CHAR const * fl_str_start_loc_SP = p_clip_text_info_SP->print_str_P;
  HMI_CHAR const * fl_str_end_loc_SP;
  SINT32           fl_calc_width;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  UINT32           fl_append_str_index_U8;
  UINT32           fl_append_str_length_U8 = 0;
  SINT32           fl_append_length    = 0;

#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
      GFX_MGR02_TEXT_DEF_T const *fl_element_def_SP = p_clip_text_info_SP->dyn_text_def_SP;
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
  GFX_MGR02_TXT_SPECIAL_EFFECTS *fl_txt_special_prop_SP = GFX_MGR02_NULL_PTR;
#endif
  UINT32           fl_str_len;
  HMI_CHAR const * fl_loop_check_SP;
  BOOLEAN fl_autohint_bool= hmi_gfx_mgr02_is_autohint_enabled(p_font_id);
  GFX_MGR02_CONTEXT_T const * p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();

  if(fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    face = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
  }
  if(face != NULL)
  {
    fl_str_len = HMI_STRLEN(fl_str_start_loc_SP);
    if(fl_str_len > 0U)
    {
#if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX) || defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
      UINT8 fl_allow_calc;
#endif
      SINT32  fl_temp_str_size;
      UINT32 fl_current_index = 0U;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
      UINT16 fl_append_char = 0U;
#endif
      BOOLEAN fl_scroll_enabled = FALSE;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      if (p_cntx_SP->rprop.scroll_offset > 0U)
      {
        fl_scroll_enabled = TRUE;
      }
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
       UINT8 fl_complex_script = (UINT8)FALSE;
       SINT16 fl_current_advance_x = 0;
       HMI_CHAR *fl_shape_str = GFX_MGR02_NULL_PTR;
       GFX_MGR02_HB_SHAPE_INFO * fl_shaper_ptr = GFX_MGR02_NULL_PTR;
       UINT8 fl_txt_dir_RTL = 0U;
/* Invoke shape engine if there any complex scripts */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
        if (hmi_gfx_mgr02_get_arabic_char_count(p_clip_text_info_SP->print_str_P, (UINT16)fl_str_len) != 0U)
        {
          fl_complex_script = (UINT8)TRUE;
          fl_txt_dir_RTL = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
        if (hmi_gfx_mgr02_get_hebrew_char_count(p_clip_text_info_SP->print_str_P, (UINT16)fl_str_len) != 0U)
        {
          fl_complex_script = (UINT8)TRUE;
          fl_txt_dir_RTL = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
        if ((hmi_gfx_mgr02_get_thai_char_count(fl_str_start_loc_SP, (UINT16)fl_str_len) != 0U))
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        if (hmi_gfx_mgr02_get_devanagari_char_count(fl_str_start_loc_SP, (UINT16)fl_str_len) != 0U)
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED)
        if ((hmi_gfx_mgr02_get_regional_char_count(fl_str_start_loc_SP, (UINT16)fl_str_len) != 0U))
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
        if (fl_complex_script != (UINT8)TRUE)
        {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          GFX_MGR02_UNUSED_VAR(fl_append_char);
#endif
          GFX_MGR02_UNUSED_PTR(fl_shape_str);
        }

      if(fl_complex_script == (UINT8)TRUE)
      {
        UINT16 fl_shape_str_size = fl_str_len * 2U; //This should have enough space to expand the input string. So allocating 2X the size of input string
        fl_shape_str   = (HMI_CHAR *)malloc((sizeof(HMI_CHAR)) * (fl_shape_str_size));
        if(fl_shape_str != GFX_MGR02_NULL_PTR)
        {
          fl_shaper_ptr = hmi_gfx_mgr02_process_ubidi(fl_str_start_loc_SP
                                      , fl_str_len
                                      ,fl_txt_dir_RTL
                                      ,fl_font_id
                                      ,fl_shape_str
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                                      , p_clip_text_info_SP->pre_render_index
#endif
                                      );
          if(fl_shaper_ptr != GFX_MGR02_NULL_PTR)
          {
            if (p_shaper_info != GFX_MGR02_NULL_PTR)
            {
              p_shaper_info->shaper_out_ptr = fl_shaper_ptr;
            }
            fl_str_start_loc_SP = (HMI_CHAR const *)fl_shape_str;
            fl_str_len = (UINT32)fl_shaper_ptr->glyph_count;
          }
        }
      }
#endif
      if(((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT))
      {
        fl_str_end_loc_SP = &fl_str_start_loc_SP[fl_str_len-1U];
        fl_current_index = fl_str_len-1U;
        fl_loop_check_SP = &fl_str_start_loc_SP[0];
      }
      else
      {
        fl_str_end_loc_SP = fl_str_start_loc_SP;
        fl_loop_check_SP = &fl_str_start_loc_SP[fl_str_len-1U];
        fl_current_index = 0;
      }
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      if (((UINT32)p_clip_text_info_SP->dyn_text_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
      {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((p_clip_text_info_SP->dyn_text_def_SP->anim_id));
        UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_clip_text_info_SP->dyn_text_def_SP->anim_id));

        if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
          GFX_MGR02_ANIM_DATA_T *fl_anim_data = hmi_gfx_mgr02_layout_get_anim_data();
          GFX_MGR02_TEXT_DYN_PROPERTY const *fl_text_anim_prop_S = &fl_anim_data->text_prop[fl_prop_index_u32];
          fl_txt_special_prop_SP = (GFX_MGR02_TXT_SPECIAL_EFFECTS *)&fl_text_anim_prop_S->txt_special_effects;
        }
      }
#endif
      while(fl_tot_nb_char_U32 < (UINT32)p_clip_text_info_SP->num_chars_to_process)
      {
#if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX) || defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
        switch(fl_str_end_loc_SP[0])
        {
#if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX)
             case GFX_MGR02_TEXT_COLOR_CODE_PREFIX:
               {
                 UINT32 fl_tcc_count = 0;
#if GFX_MGR02_UNICODE != 0
                 while(fl_tcc_count < ((UINT32)3))
                 {
                   fl_tot_nb_char_U32++;
                   fl_tcc_count++;
                   if(fl_str_end_loc_SP == fl_loop_check_SP)
                   {
                     break;
                   }
                   else
                   {
                     if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                     {
                       fl_str_end_loc_SP--;
                       fl_current_index--;
                     }
                     else
                     {
                       fl_str_end_loc_SP++;
                       fl_current_index++;
                     }
                   }
                 }
#else
                 while(fl_tcc_count < ((UINT32)4))
                 {
                   fl_tot_nb_char_U32++;
                   fl_tcc_count++;
                   if(fl_str_end_loc_SP == fl_loop_check_SP)
                   {
                     break;
                   }
                   else
                   {
                     if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                     {
                       fl_str_end_loc_SP--;
                       fl_current_index--;
                     }
                     else
                     {
                       fl_str_end_loc_SP++;
                       fl_current_index++;
                     }
                   }
                 }
#endif
               }
               break;
#endif
#if defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
             case GFX_MGR02_TEXT_SPACE_CODE_PREFIX:
               {
                 fl_tot_nb_char_U32++;
                 if(fl_str_end_loc_SP != fl_loop_check_SP)
                 {
                   if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                   {
                     fl_str_end_loc_SP--;
                     fl_current_index--;
                   }
                   else
                   {
                     fl_str_end_loc_SP++;
                     fl_current_index++;
                   }

                   fl_tot_str_size += ((UINT32)(fl_str_end_loc_SP[0]) << 6);
                   fl_tot_nb_char_U32++;
                   /* Added this check to optimize the width calculation algorithm.
                   ** suppose if string = ABCDEFGHIJKL, and string got truncated
                   ** at "D" character itself, so need not to process remaining
                   ** characters (EFGHIJKL)
                   */ 
                   fl_temp_str_size = fl_tot_str_size; 
                   if (fl_scroll_enabled == FALSE)
                   {
                     fl_clip_flag_U8 = TRUE;
                     break;
                   }
                   if((fl_temp_str_size > p_clip_text_info_SP->max_available_width) || (fl_str_end_loc_SP == fl_loop_check_SP))
                   {
                     break;
                   }
                   else
                   {
                     if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                     {
                       fl_str_end_loc_SP--;
                       fl_current_index--;
                     }
                     else
                     {
                       fl_str_end_loc_SP++;
                       fl_current_index++;
                     }
                   }
                 }
               }
               break;
#endif
             default:
             {
                 /*For MISRA Fix.*/
             }
               break;
        }
        fl_allow_calc = FALSE;
        if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          if(fl_str_end_loc_SP >= fl_loop_check_SP)
          {
            fl_allow_calc = TRUE;
          }
        }
        else
        {
          if(fl_str_end_loc_SP <= fl_loop_check_SP)
          {
            fl_allow_calc = TRUE;
          }
        }
        if (fl_allow_calc != FALSE)
#endif
        {
          #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          hb_buffer_content_type_t fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
          if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
          {
            fl_content_type = fl_shaper_ptr->content_type[fl_current_index];
            fl_current_advance_x = fl_shaper_ptr->x_advance[fl_current_index];
          }
          #endif
          fl_tot_str_size += hmi_gfx_mgr02_get_ft_char_width(face, fl_str_end_loc_SP[0], fl_autohint_bool
                                                              #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                                              , p_clip_text_info_SP->font_pt_size, fl_font_id
                                                              #endif
                                                              #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                                              ,fl_txt_special_prop_SP
                                                              #endif
                                                              #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                              ,fl_complex_script
                                                              ,fl_content_type
                                                              ,fl_current_advance_x
                                                              #endif
                                                              );
          fl_tot_nb_char_U32++;
          /* Added this check to optimize the width calculation algorithm.
          ** suppose if string = ABCDEFGHIJKL, and string got truncated
          ** at "D" character itself, so need not to process remaining
          ** characters (EFGHIJKL)
          */ 
          fl_temp_str_size = fl_tot_str_size; 
          if((fl_temp_str_size > p_clip_text_info_SP->max_available_width) && (fl_scroll_enabled == FALSE))
          {
            fl_clip_flag_U8 = TRUE;
            break;
          }
          else if (fl_str_end_loc_SP == fl_loop_check_SP)
          {
            break;
          }
          else
          {
            if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
            {
              fl_str_end_loc_SP--;
              fl_current_index--;
            }
            else
            {
              fl_str_end_loc_SP++;
              fl_current_index++;
            }
          }
        }
      }
      if (fl_tot_str_size > 0)
      {
        if (fl_tot_str_size > (SINT32)p_clip_text_info_SP->max_available_width)
        {
          if (fl_scroll_enabled == FALSE)
          {
            fl_clip_flag_U8 = TRUE;
          }
        }
#if (defined(GFX_MGR02_COMPLEX_SCRIPT_PADDING) && defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
        if(fl_clip_flag_U8 == FALSE)
        {
          UINT32 fl_buf_padding = 0;
          if ((fl_complex_script == (UINT8)TRUE) && (fl_txt_dir_RTL != TRUE))
          {
            HMI_CHAR padding_char = (HMI_CHAR)0x0020;
            fl_buf_padding = hmi_gfx_mgr02_get_ft_char_width(face, padding_char, fl_autohint_bool
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                                             ,
                                                             p_clip_text_info_SP->font_pt_size, fl_font_id
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                                             ,
                                                             fl_txt_special_prop_SP
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                             ,
                                                             fl_complex_script, HB_BUFFER_CONTENT_TYPE_UNICODE, 0
#endif
            );
          }
          if (((fl_tot_str_size + fl_buf_padding) > (SINT32)p_clip_text_info_SP->max_available_width) && (fl_scroll_enabled != TRUE))
          {
            fl_tot_str_size = (SINT32)p_clip_text_info_SP->max_available_width;
          }
          else
          {
            fl_tot_str_size += (SINT32)fl_buf_padding;
          }
        }
#endif
        fl_calc_width = (GFX_MGR02_ISIZE_X_T)p_clip_text_info_SP->max_available_width;
        if (fl_clip_flag_U8 != FALSE)
        {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          if((p_clip_text_info_SP->append_str != FALSE) &&
            (((p_clip_mode & GFX_MGR02_TP_CLIP_APPEND) == GFX_MGR02_TP_CLIP_APPEND) || 
            ((p_clip_mode & GFX_MGR02_TP_CLIP_SHRINK_FIT) == GFX_MGR02_TP_CLIP_SHRINK_FIT)))
          {
            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            hb_buffer_content_type_t fl_content_type = HB_BUFFER_CONTENT_TYPE_UNICODE;
            fl_current_advance_x = 0;
            #endif
            fl_append_char = GFX_MGR02_APPEND_CHAR;

            fl_append_length = hmi_gfx_mgr02_get_ft_char_width(face, fl_append_char, fl_autohint_bool
                                                                  #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                                                  , p_clip_text_info_SP->font_pt_size, fl_font_id
                                                                  #endif
                                                                  #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                                                  ,fl_txt_special_prop_SP
                                                                  #endif
                                                                  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                  ,fl_complex_script
                                                                  ,fl_content_type
                                                                  ,fl_current_advance_x
                                                                  #endif
                                                                  );              
            fl_append_length = (GFX_MGR02_APPEND_CHAR_CNT * fl_append_length);
            if(fl_append_length < (SINT32)p_clip_text_info_SP->max_available_width)
            {
              fl_calc_width          -= fl_append_length;
              fl_append_str_length_U8 = GFX_MGR02_APPEND_CHAR_CNT;
            }
            else
            {
              /* 
              ** append string cannot be fitted in available width 
              ** so we don't show it..
              */
              fl_append_length        = 0;
              fl_append_str_length_U8 = 0;
            }
          }
#endif
          if((p_alignment & GFX_MGR02_TP_ALIGN_MASK) == GFX_MGR02_TP_ALIGN_RIGHT)
          {
            /* 
            ** Start removing characters only from where
            ** we have stopped (since exceeded no' of pixels
            ** configured). It will optimize the calculation.
            */
            fl_str_start_loc_SP = fl_str_end_loc_SP;
            while(((UINT32) 0) != fl_tot_nb_char_U32)
            {
              UINT32 fl_char_width;
              #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              hb_buffer_content_type_t fl_content_type = HB_BUFFER_CONTENT_TYPE_UNICODE;
              if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
              {
                fl_content_type = fl_shaper_ptr->content_type[fl_current_index];
                fl_current_advance_x = fl_shaper_ptr->x_advance[fl_current_index];
              }
              #endif
              fl_char_width = hmi_gfx_mgr02_get_ft_char_width(face, *fl_str_start_loc_SP, fl_autohint_bool
                                #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                , p_clip_text_info_SP->font_pt_size, fl_font_id
                                #endif
                                #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                ,fl_txt_special_prop_SP
                                #endif
                                #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                ,fl_complex_script
                                ,fl_content_type
                                ,fl_current_advance_x
                                #endif	
                                );              
              /* In order to prevent the removal of last letter in normal clipping mode so the Character
              exceeding the textbox width is hardcut*/
              if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                  || (fl_element_def_SP->max_num_of_lines != 1U)
#endif
              )
              {
                fl_tot_nb_char_U32--;
                fl_tot_str_size -= (SINT32)fl_char_width;
                fl_str_start_loc_SP++;
                fl_current_index++;
              }
              if ((fl_tot_str_size <= fl_calc_width) || (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                if(p_string != GFX_MGR02_NULL_PTR)
                {
                    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                    UINT32 fl_glyph_shift = fl_str_len - fl_tot_nb_char_U32;
                    #endif
                    if(fl_append_length > 0)
                    {
                        if(fl_tot_nb_char_U32 > (UINT32)(GFX_MGR02_MAX_TEXT_LENGTH-GFX_MGR02_APPEND_CHAR_CNT))
                        {
                          /*
                          ** We are now OK to fit the width of the string but
                          ** if the p_string cannot accomodate the string characters yet
                          ** we have to remove more characters..
                          */
                          continue;
                        }
                        else
                        { 
                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                            if ((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                            {
                                hmi_gfx_mgr02_realign_shaper_output(fl_shaper_ptr, GFX_MGR02_APPEND_CHAR_CNT, fl_glyph_shift, fl_str_len);
                            }
                            #endif
                            for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < (UINT32)GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                            {
                                #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                if((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                                {
                                    fl_shaper_ptr->unicode[fl_append_str_index_U8] = fl_append_char;
                                    fl_shaper_ptr->content_type[fl_append_str_index_U8] = HB_BUFFER_CONTENT_TYPE_UNICODE;
                                    /* Updating GPOS delta values with zero's since for append string ... delta values will be 0 */
                                    fl_shaper_ptr->x_offset[fl_append_str_index_U8] = 0;
                                    fl_shaper_ptr->y_offset[fl_append_str_index_U8] = 0;
                                    fl_shaper_ptr->x_advance[fl_append_str_index_U8] = (fl_append_length/GFX_MGR02_APPEND_CHAR_CNT);
                                }
                                #endif
                                p_string[fl_append_str_index_U8] = fl_append_char;
                            }

                            #ifdef GFX_MGR02_UNICODE
                            (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], GFX_MGR02_MAX_TEXT_LENGTH, L"%ls", fl_str_start_loc_SP); /* ls implies the passed input string is wide char string */
                            #else
                            (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], GFX_MGR02_MAX_TEXT_LENGTH, "%s", fl_str_start_loc_SP); /* %s implies the passed string is a single byte string */
                            #endif

                            fl_tot_str_size += fl_append_length;
                            fl_tot_nb_char_U32 += fl_append_str_length_U8;
                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                            if ((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                            {
                                fl_shaper_ptr->glyph_count = fl_tot_nb_char_U32;
                            }
                            #endif
                        }
                    }
                    else
                    {
                        if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                        {
                          fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                        }
                        (void)HMI_STRNCPY(p_string, fl_str_start_loc_SP, fl_tot_nb_char_U32);
                        
                        #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                        if ((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                        {
                          hmi_gfx_mgr02_realign_shaper_output(fl_shaper_ptr, 0U, fl_glyph_shift, fl_str_len);
                        }
                        #endif
                        p_string[fl_tot_nb_char_U32] = 0;
                    }
                }
#else
                p_clip_text_info_SP->print_str_P = fl_str_start_loc_SP;
#endif
                break;
              }
            }
          }
          else
          {
            while( ((UINT32)0) != fl_tot_nb_char_U32)
            {
              UINT32 fl_char_width;
              #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              hb_buffer_content_type_t fl_content_type = HB_BUFFER_CONTENT_TYPE_UNICODE;
              if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
              {
                fl_content_type = fl_shaper_ptr->content_type[fl_current_index];
                fl_current_advance_x = fl_shaper_ptr->x_advance[fl_current_index];
              }
              #endif
              fl_char_width = hmi_gfx_mgr02_get_ft_char_width(face, *fl_str_end_loc_SP, fl_autohint_bool
                                  #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                  , p_clip_text_info_SP->font_pt_size, fl_font_id
                                  #endif
                                  #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                  ,fl_txt_special_prop_SP
                                  #endif
                                  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                  ,fl_complex_script
                                  ,fl_content_type
                                  ,fl_current_advance_x
                                  #endif
                                  );                              
              if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                  || (fl_element_def_SP->max_num_of_lines != 1U)
#endif
              )
              {
                fl_tot_str_size -= (SINT32)fl_char_width;
                fl_tot_nb_char_U32--;
                fl_str_end_loc_SP--;
                fl_current_index--;
              }
              if((fl_tot_str_size <= fl_calc_width) || (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                if(p_string != GFX_MGR02_NULL_PTR)
                {
                  if(fl_append_length > 0)
                  {
                    if(fl_tot_nb_char_U32 > (UINT32)(GFX_MGR02_MAX_TEXT_LENGTH-GFX_MGR02_APPEND_CHAR_CNT))
                    {
                      /*
                      ** We are now OK to fit the width of the string but
                      ** ff the p_string cannot accomodate the string characters yet
                      ** we have to remove more characters..
                      */
                      continue;
                    }
                    else
                    {
                      (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
                      fl_append_str_index_U8 = fl_tot_nb_char_U32;
                      fl_tot_nb_char_U32     += fl_append_str_length_U8;
                      fl_tot_str_size       += fl_append_length;
                      for(;
                        fl_append_str_index_U8 < fl_tot_nb_char_U32; 
                        fl_append_str_index_U8++)
                      {
                      #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                        if((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                        {
                          fl_shaper_ptr->unicode[fl_append_str_index_U8] = fl_append_char;
                          fl_shaper_ptr->content_type[fl_append_str_index_U8] = HB_BUFFER_CONTENT_TYPE_UNICODE;
                          /* Updating GPOS delta values with zero's since for append string ... delta values will be 0 */
                          fl_shaper_ptr->x_offset[fl_append_str_index_U8] = 0;
                          fl_shaper_ptr->y_offset[fl_append_str_index_U8] = 0;
                          fl_shaper_ptr->x_advance[fl_append_str_index_U8] = (fl_append_length/GFX_MGR02_APPEND_CHAR_CNT);
                          fl_shaper_ptr->glyph_count = fl_append_str_index_U8 + 1U; //Mark the last appended char position as size of processed text
                        }
                      #endif
                        p_string[fl_append_str_index_U8] = fl_append_char;
                      }
                      p_string[fl_append_str_index_U8] = (HMI_CHAR)'\0';
                    }
                  }
                  else
                  {
                    if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                    {
                      fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                    }
                    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                    if(fl_shaper_ptr != GFX_MGR02_NULL_PTR)
                    {
                      fl_shaper_ptr->glyph_count = fl_tot_nb_char_U32;
                    }
                    #endif
                    (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
                    p_string[fl_tot_nb_char_U32] = 0;
                  }
                }
#endif
                break;
              }

            }
          }
        }
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        else if(p_string != GFX_MGR02_NULL_PTR)
        {
          if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
          {
            fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
          }
          (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
          p_string[fl_tot_nb_char_U32] = 0;
        }
        else
        {
          /*MISRA.IF.NO_ELSE fix*/
        }
#endif
      }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      if((fl_complex_script == (UINT8)TRUE)&& (fl_shape_str != GFX_MGR02_NULL_PTR))
      {
        free(fl_shape_str);
        fl_shape_str = GFX_MGR02_NULL_PTR;
      }
     #endif
    }
  }
  p_clip_text_info_SP->print_width     = (UINT16)fl_tot_str_size;
  p_clip_text_info_SP->print_length_U8 = (UINT8)fl_tot_nb_char_U32;
  /* The above explicit typecast from UINT32 to UINT8 is done intentionally since print length
  is assumed that it wont exceed 255. No new warnings because of this change */
  return(fl_clip_flag_U8);
}
#endif /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)       */
#endif  /* #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE */

#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
/// <summary>
/// Internal API to convert a 32bit unicode to UTF16
/// </summary>
/// <param name="p_unicode">unicode value</param>
/// <param name="p_out">where to push the UTF16 codes</param>
/// <returns>Returns the actual number of characters used from HMI_CHAR*</returns>
static UINT32 hmi_convert_utf32cp_to_utf16cp(HMI_CHAR* p_out, UINT32 const * p_src, UINT32 p_length)
{
  UINT32 fl_dst_index = 0;
  for (UINT32 index = 0; index < p_length; index++)
  {
    UINT32 p_unicode = p_src[index];
    if ((p_unicode >= 0xD800U) && (p_unicode <= 0xDFFFU))
    {
      p_out[fl_dst_index] = (HMI_CHAR)(0xFFFD);
      fl_dst_index++;
    }
    else if (p_unicode <= 0xFFFFU)
    {
      p_out[fl_dst_index] = (HMI_CHAR)(p_unicode);
      fl_dst_index++;
    }
    else if (p_unicode <= 0x10FFFFU)
    {
      /* logic from https://unicode.org/faq/utf_bom.html*/
      UINT16 X                =   (UINT16)(p_unicode);
      UINT32 U                =    (p_unicode >> 16U) & (UINT32)((1U << 5U) - 1U); 
      UINT16 W                =   (UINT16)((U)-1U);
      UINT16 fl_ucode16L      =   0xD800U;
      UINT16 fl_ucode16H      =   0xDC00U;
      fl_ucode16L            |=   (UINT16)(W << 6U);
      fl_ucode16L            |=   (UINT16)(X >> 10U);
      p_out[fl_dst_index] = (HMI_CHAR)(fl_ucode16L);
      fl_dst_index++;
      X                       =   (UINT16)(p_unicode);
      fl_ucode16H            |=   (UINT16)(X & (UINT16)((UINT16)(1U << 10U) - 1U));
      p_out[fl_dst_index] = (HMI_CHAR)(fl_ucode16H);
      fl_dst_index++;
    }
    else
    {
      p_out[fl_dst_index] = (HMI_CHAR)(0xFFFD);
      fl_dst_index++;
    }
  }
  return(fl_dst_index);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_mt_get_text_width
Description          : Returns the total pixel width of the passed text string using monotype interface.
Invocation           :
Parameters           : p_p_clip_text_info_SP->disp_string_P - Pointer to String
p_string - pointer to a buffer where the print string will 
will be copied. The buffer has to have a 
size of (GFX_MGR02_MAX_TEXT_LENGTH+1)
Return Value         : FALSE - String not clipped, TRUE - String is clipped.
Critical Section     : None
External Interfaces  :
******************************************************************************/

static UINT32 hmi_gfx_mgr02_mt_get_text_width(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                              UINT32            p_font_id,
                                              UINT32            p_clip_mode,
                                              UINT32            p_alignment
                                           #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                              ,HMI_CHAR        * p_string
                                           #endif
                                           #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                              ,GFX_MGR02_SHAPE_INFO  *p_shaper_info
                                           #endif
                                             )
{

  GFX_MGR02_FONT             const * fl_font_SP;
  UINT32                fl_clip_flag_U8      =  FALSE;
  UINT32                fl_tot_nb_char_U32   =  (UINT32)0;  /* total number of character in the original string */
  SINT32                fl_tot_str_size      =  0;  /* Total size of string in pixel */
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  SINT32                fl_append_length     =  0;
#endif
  SINT32                fl_calc_width;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
  UINT32                fl_u32_unicode[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1U];
#else
  UINT32                fl_u32_unicode[GFX_MGR02_MAX_TEXT_LENGTH + 1U];
#endif
  UINT32         const* fl_str_start_loc_SP;
  UINT32         const* fl_str_end_loc_SP;
  UINT32         const* fl_loop_check_SP;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  UINT32                fl_append_str_index_U8;
  UINT32                fl_append_str_length_U8 = 0;
#endif
  FS_SHORT i_dx = 0;
  FS_SHORT i_dy = 0;
  FS_FIXED dx = 0.0f;
  FS_FIXED dy = 0.0f;
  FS_LONG  err = 0;
  UINT32                fl_str_len;
  FS_STATE            * fl_client_state;
  SINT32                fl_available_width;
 #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
  SINT32                fl_shadow_width=0;
  UINT8                 fl_effect_type = GFX_MGR02_TXT_INVALID_EFFECT;
 #endif
      GFX_MGR02_CONTEXT_T const *p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
  UINT32            fl_font_id = hmi_gfx_mgr02_get_font_id(p_font_id);
  fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);

  /*Convert to UINT32 array*/
  {
    HMI_CHAR      const* fl_instr  =    p_clip_text_info_SP->print_str_P;
    UINT32 fl_instr_len            =    HMI_STRLEN(fl_instr);
    UINT32 fl_index                =    0U;
    SINT32 fl_char_count = (SINT32)fl_instr_len;
    SINT32 codeUnitsConsumed = 1;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    if (fl_instr_len < (UINT32)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
#else
    if (fl_instr_len < (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
#endif
    {
      while (fl_char_count > 0)
      {
        fl_u32_unicode[fl_index++] = TsUniEnc_decodeUTF16(fl_instr, fl_char_count, &codeUnitsConsumed);
        if (codeUnitsConsumed > 0)
        {
          fl_char_count -= codeUnitsConsumed;
          fl_instr += (codeUnitsConsumed);
        }
      }
    }
    /* fl_u32_unicode size -> [GFX_MGR02_MAX_TEXT_LENGTH + 1]*/
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    if (fl_index <= (UINT32)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
#else
    if (fl_index <= (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
#endif
    {
      fl_u32_unicode[fl_index] = 0U;
    }
    fl_str_len = fl_index;
    fl_str_start_loc_SP = &fl_u32_unicode[0];
  }
  if ((fl_font_SP != GFX_MGR02_NULL_PTR)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    && (fl_str_start_loc_SP != GFX_MGR02_NULL_PTR)
#endif
    )
  {
    UINT8 fl_font_char_space = fl_font_SP->char_space;
    if(fl_str_len > 0U)
    {
#if !(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT) && (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)))
      GFX_FLOAT font_height_pts_temp;
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      GFX_MGR02_TEXT_DYN_PROPERTY const *fl_text_anim_prop_S = GFX_MGR02_NULL_PTR;
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      BOOLEAN fl_scroll_enabled = hmi_gfx_mgr02_layout_get_text_scroll_status((GFX_MGR02_ANIM_ELEM_ID)p_clip_text_info_SP->dyn_text_def_SP->anim_id);
#else
      BOOLEAN fl_scroll_enabled = FALSE;
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      UINT8 fl_complex_script = (UINT8)FALSE;
      UINT32 fl_index = 0U;
      UINT16 fl_append_char_glyph_id = 0U;
      UINT32 *fl_shape_str = GFX_MGR02_NULL_PTR;
      TsShaperText *fl_shaper_ptr = GFX_MGR02_NULL_PTR;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
      GFX_MGR02_TEXT_DEF_T const *fl_element_def_SP = p_clip_text_info_SP->dyn_text_def_SP;
      GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
      UINT16 fl_cur_glph_index;
      UINT16 fl_src_str_idx = p_clip_text_info_SP->str_offset_idx;

      if ((fl_element_def_SP->wrap_mode != (UINT8)GFX_MGR02_WRAP_WORD) &&
          (fl_element_def_SP->max_num_of_lines == 1U))
#endif
      {
        /* Invoke shape engine if there any complex scripts */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
        if(hmi_gfx_mgr02_get_arabic_char_count(p_clip_text_info_SP->print_str_P,(UINT16)fl_str_len) != 0U)
        {
         fl_complex_script = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
        if(hmi_gfx_mgr02_get_hebrew_char_count(p_clip_text_info_SP->print_str_P,(UINT16)fl_str_len) != 0U)
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
        if(hmi_gfx_mgr02_get_thai_char_count(p_clip_text_info_SP->print_str_P,(UINT16)fl_str_len) != 0U)
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
#if defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED)
        if ((hmi_gfx_mgr02_get_regional_char_count(fl_str_start_loc_SP, (UINT16)fl_str_len) != 0U))
        {
          fl_complex_script = (UINT8)TRUE;
        }
#endif
        if(fl_complex_script != (UINT8)TRUE)
        {
          GFX_MGR02_UNUSED_VAR(fl_index); 
          GFX_MGR02_UNUSED_VAR(fl_append_char_glyph_id); 
          GFX_MGR02_UNUSED_PTR(fl_shape_str); 
        }
     }
    #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
     else
     {
       GFX_MGR02_UNUSED_VAR(fl_index); 
       GFX_MGR02_UNUSED_VAR(fl_append_char_glyph_id); 
       GFX_MGR02_UNUSED_PTR(fl_shape_str); 
     }
    #endif
  #endif

      fl_client_state = hmi_gfx_mgr02_get_mt_client_handler();
      (void)FS_set_font(fl_client_state, (FILECHAR *)p_cntx_SP->rprop.mt_font_name[fl_font_id]);
      

      #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
         /* By default no special effects */
         (void)FS_set_flags(fl_client_state, FLAGS_NO_EFFECT);
         if(((UINT32)p_clip_text_info_SP->dyn_text_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
         {
           UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE((p_clip_text_info_SP->dyn_text_def_SP->anim_id));
           UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_clip_text_info_SP->dyn_text_def_SP->anim_id));

           if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
              (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
           {
              GFX_MGR02_ANIM_DATA_T *fl_anim_data =  hmi_gfx_mgr02_layout_get_anim_data();
              fl_text_anim_prop_S                 =  &fl_anim_data->text_prop[fl_prop_index_u32];
           }
           
         }
      /****************** TEXT SPECIAL EFFECTS PROPERTIES UPDATE *********************/
     
      if(fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
      {
          fl_effect_type = fl_text_anim_prop_S->txt_special_effects.effect_type;
          if(fl_effect_type == GFX_MGR02_TXT_SOFTEND_EFFECT)
          {
           /* Softened effect (Softened appearance of graymap) */
           (void)FS_set_flags(fl_client_state, FLAGS_SOFTENED_ON);
          }
          else if(fl_effect_type == GFX_MGR02_TXT_OTL_UNFILL_EFFECT)
          {
            /* No outline filled */
            (void)FS_set_flags(fl_client_state, FLAGS_OUTLINED_UNFILLED);
          }
          else if(fl_effect_type == GFX_MGR02_TXT_EMBOSSED_EFFECT)
          {
            /* Normal text with Embossed (Edge effect with a raised appearance)*/
            (void)FS_set_flags(fl_client_state, FLAGS_EMBOSSED);
          }
          else if(fl_effect_type == GFX_MGR02_TXT_ENGRAVED_EFFECT)
          {
            /* Normal text with Engraved effect (Edge effect with a depressed appearance)*/
            (void)FS_set_flags(fl_client_state, FLAGS_ENGRAVED);
          }
          else if(fl_effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT)
          {
            /* Glow effect with no outline filled */
            (void)FS_set_flags(fl_client_state, FLAGS_OUTLINED_UNFILLED);
            FS_set_outline_width(fl_client_state, 2);
            FS_set_outline_opacity(fl_client_state, (FS_FIXED)(2.0*65536));
          }
          else if(fl_effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT)
          {
            /* Normal text with glow effect */
            (void)FS_set_flags(fl_client_state, FLAGS_OUTLINED_SOFT);  
            FS_set_outline_width(fl_client_state, (fl_text_anim_prop_S->txt_special_effects.otl_width));
            FS_set_outline_opacity(fl_client_state, (FS_FIXED)((fl_text_anim_prop_S->txt_special_effects.otl_opacity)*65536));
          }
          else if(fl_effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
          {
            /* Normal text with Bold effect*/
            (void)FS_set_flags(fl_client_state, FLAGS_REGULARBOLD_ON);
            FS_set_bold_pct(fl_client_state, (FS_FIXED)((fl_text_anim_prop_S->txt_special_effects.bold_percentage)*65536));
          }
          else if(fl_effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT)
          {
            /* Remove shadow width from the available width so that shadow effect can embedd within it */
            (void)FS_set_flags(fl_client_state, FLAGS_NO_EFFECT);
            fl_shadow_width = fl_text_anim_prop_S->txt_special_effects.shadow_x;
            fl_shadow_width =  ((fl_shadow_width) < 0 ? 0 - (fl_shadow_width) : (fl_shadow_width));
          }
          else
          {
            /* Drop shadow effect can be achieve by setting no flags and drawring bg and fg separately */
            /* No special effects */
            /* For normal text */
            (void)FS_set_flags(fl_client_state, FLAGS_NO_EFFECT);
          }

         /************ END OF TEXT SPECIAL EFFECTS PROPERTIES UPDATE *********************/
      }
     #endif /* #define GFX_MGR02_TXT_EFFECTS_ENABLED  */

      /* Set the scale, we are assuming that xppem == yppem and no rotation   */
      /* or skewing. Note: ppem<<16 converts the specified ppem value into a  */
      /* 16.16 fixed point value.                                             */
      #if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
      (void)FS_set_scale(fl_client_state, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size*65536), 0, 0, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size*65536));
      #else
      font_height_pts_temp = fl_font_SP->height_pts*65536.0f;   
      (void)FS_set_scale(fl_client_state, (FS_LONG)(font_height_pts_temp), 0, 0, (FS_LONG)(font_height_pts_temp));
      #endif
      /* set the cmap...                                                  */
      /* ...first try Windows Unicode with surrogates...                  */
      err = FS_set_cmap(fl_client_state, 3, 10);
      if (err != SUCCESS)
      {
        /* ...then try normal Windows Unicode                           */
        err = FS_set_cmap(fl_client_state, 3, 1);
        if (err != SUCCESS)
        {
          (void)FS_set_cmap(fl_client_state, 1, 0);
        }
      }


      p_clip_text_info_SP->print_length_U8 = 0;
      p_clip_text_info_SP->print_width     = 0;

    #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      fl_available_width = (SINT32)(p_clip_text_info_SP->max_available_width - fl_shadow_width);
    #else
      fl_available_width = (SINT32)(p_clip_text_info_SP->max_available_width);
    #endif
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
   #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    if((fl_element_def_SP->wrap_mode != (UINT8)GFX_MGR02_WRAP_WORD) && 
       (fl_element_def_SP->max_num_of_lines == 1U))
   #endif
    {
      if(fl_complex_script == (UINT8)TRUE)
      {
        /* set the flag so that get_glyph functions will turn ON cmap      */
        (void)FS_set_flags(fl_client_state, FLAGS_CMAP_OFF);
        fl_shaper_ptr = (TsShaperText *)hmi_gfx_mgr02_shape_engine_get_gpos(fl_font_id, fl_str_start_loc_SP, 
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
          NULL, FALSE,
#endif
          fl_str_len, fl_client_state);

        if(fl_shaper_ptr != GFX_MGR02_NULL_PTR)
        {
          if(p_shaper_info != GFX_MGR02_NULL_PTR)
          {
            p_shaper_info->shaper_out_ptr = fl_shaper_ptr;
          }
          fl_str_len = (UINT32)fl_shaper_ptr->textInfoArrayLen;//TODO: arajase2 ---> check this
          
          /* Deviation - MISRA C-2012 Directive 4.12 disallows dynamic memory allocation, MISRA C-2012 Rule 21.3 disallows use of function malloc  
           * the use of dynamic memory allocation (malloc) has been carefully considered here. 
           */
          fl_shape_str    =   (UINT32*)malloc((sizeof(UINT32)) * (fl_str_len + 1U));
          if(fl_shape_str != GFX_MGR02_NULL_PTR)
          {
            while(fl_index < fl_str_len)
            {
              fl_shape_str[fl_index] = fl_shaper_ptr->textInfoArray[fl_index].glyphID;
              fl_index++;
            }
            fl_shape_str[fl_index] = 0U;
            fl_str_start_loc_SP  =  (UINT32 const *)fl_shape_str;
          }
        }
      }
    }
   #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    else
    {
      if(p_clip_text_info_SP->is_complex == (UINT8)TRUE)
      {
        fl_ML_data_ptr = &l_shape_ml_dtext_buffer[fl_element_def_SP->ml_string_index];
        /* set the flag so that get_glyph functions will turn ON cmap      */
        (void)FS_set_flags(fl_client_state, FLAGS_CMAP_OFF);
      }
    }
   #endif
  #endif
      if(((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT))
      {
        fl_str_end_loc_SP = &fl_str_start_loc_SP[fl_str_len-1U];
        fl_loop_check_SP = &fl_str_start_loc_SP[0];
       #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
        if(fl_src_str_idx == fl_str_len)
        {
          fl_src_str_idx = fl_src_str_idx - 1u;
        }
        else
        {
          fl_src_str_idx = (UINT16)((fl_src_str_idx + fl_str_len) - 1u);
        }
       #endif
      }
      else
      {
        fl_str_end_loc_SP = fl_str_start_loc_SP;
        fl_loop_check_SP = &fl_str_start_loc_SP[fl_str_len-1U];
      }
#ifdef GFX_MGRO2_AMBER_MONO_DE_RENDER
      FS_OUTLINE *fl_outln;
#endif

      while (fl_tot_nb_char_U32 < (UINT32)p_clip_text_info_SP->num_chars_to_process)
      {
        BOOLEAN fl_break_out_of_loop = FALSE;
#ifndef GFX_MGRO2_AMBER_MONO_DE_RENDER
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        if ((fl_element_def_SP->wrap_mode != (UINT8)GFX_MGR02_WRAP_WORD) &&
          (fl_element_def_SP->max_num_of_lines == 1U))
#endif
        {
          (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
        }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        else
        {
          if(p_clip_text_info_SP->is_complex == (UINT8)TRUE)
          {
            /* Switch OFF CMAP table when the current character is
            ** (a) Unicode or (b) not matches with original string data
            ** (b) case can be occur only when there is still is data is pending to
            ** show on to display then we are appending ...
            */ 
            if((fl_ML_data_ptr != GFX_MGR02_NULL_PTR) && ((fl_ML_data_ptr->is_character[fl_src_str_idx] == 1U) ||
               (fl_ML_data_ptr->input_string[fl_src_str_idx] != fl_str_end_loc_SP[0])))
            {
                fl_cur_glph_index = FS_map_char(fl_client_state,fl_str_end_loc_SP[0]);
                (void)FS_get_advance(fl_client_state,fl_cur_glph_index,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
            else
            {
              (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
          }
          else
          {
            (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
          }
        }
      #endif
#else
        (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
#endif
        fl_tot_str_size += i_dx;
#else
        fl_outln          =  FS_get_outline(fl_client_state,fl_str_end_loc_SP[0]);
        fl_tot_str_size  +=  fl_outln->i_dx;
#endif
        fl_tot_nb_char_U32++;

        /* Added this check to optimize the width calculation algorithm.
        ** suppose if string = ABCDEFGHIJKL, and string got truncated
        ** at "D" character itself, so need not to process remaining
        ** characters (EFGHIJKL).
        *  When scroll is enabled this clip optimization is not applicable and 
        ** the full text need to be processed
        */
        if ((fl_tot_str_size > fl_available_width) && (fl_scroll_enabled == FALSE))
        {   
            fl_clip_flag_U8 = TRUE;
            fl_break_out_of_loop = TRUE;
        }
        else if(fl_str_end_loc_SP == fl_loop_check_SP)
        { 
          fl_break_out_of_loop = TRUE;
        }
        else
        {
          if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
          {
          
          #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
           fl_src_str_idx--;
          #endif
            fl_str_end_loc_SP--;
          }
          else
          {
          #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
            fl_src_str_idx++;
          #endif
            fl_str_end_loc_SP++;
          }
        }
        if(fl_break_out_of_loop == TRUE)
        {
            break;
        }
        fl_tot_str_size += (SINT32)fl_font_char_space;
      }

      fl_calc_width = (GFX_MGR02_ISIZE_X_T)fl_available_width;

      if(fl_clip_flag_U8 != FALSE)
      {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        if((p_clip_text_info_SP->append_str != FALSE) &&
          (((p_clip_mode & GFX_MGR02_TP_CLIP_APPEND) == GFX_MGR02_TP_CLIP_APPEND) || 
           ((p_clip_mode & GFX_MGR02_TP_CLIP_SHRINK_FIT) == GFX_MGR02_TP_CLIP_SHRINK_FIT)))
        {
        #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
          {
            fl_append_char_glyph_id = FS_map_char(fl_client_state,GFX_MGR02_APPEND_CHAR);
            (void)FS_get_advance(fl_client_state,fl_append_char_glyph_id,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
          }
          else
          {
           #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
            if((fl_element_def_SP->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) && 
               (fl_element_def_SP->max_num_of_lines > 1U) && 
               (p_clip_text_info_SP->is_complex == (UINT8)TRUE))
            {
              fl_append_char_glyph_id = FS_map_char(fl_client_state,GFX_MGR02_APPEND_CHAR);
              (void)FS_get_advance(fl_client_state,fl_append_char_glyph_id,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
            else
            {
              (void)FS_get_advance(fl_client_state,GFX_MGR02_APPEND_CHAR,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
           #else
            (void)FS_get_advance(fl_client_state,GFX_MGR02_APPEND_CHAR,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
           #endif
          }
        #else
          (void)FS_get_advance(fl_client_state,GFX_MGR02_APPEND_CHAR,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
        #endif
          fl_append_length = ((SINT32)GFX_MGR02_APPEND_CHAR_CNT * i_dx);
          fl_append_length += (((SINT32)GFX_MGR02_APPEND_CHAR_CNT)* (fl_font_char_space));


          if((fl_append_length > 0) && (fl_append_length < fl_available_width))
          {
            fl_calc_width          -= fl_append_length;
            fl_append_str_length_U8 = GFX_MGR02_APPEND_CHAR_CNT;
          }
          else
          {
            /* 
            ** append string cannot be fitted in available width 
            ** so we don't show it..
            */
            fl_append_length        = 0;
            fl_append_str_length_U8 = 0;
          }
        }
#endif
      }
      /* Clip text */
      if(fl_clip_flag_U8 != FALSE)
      {
          if((p_alignment & GFX_MGR02_TP_ALIGN_MASK) == GFX_MGR02_TP_ALIGN_RIGHT)
          {
          /* 
          ** Start removing characters only from where
          ** we have stopped (since exceeded no' of pixels
          ** configured). It will optimize the calculation.
          */
          fl_str_start_loc_SP = fl_str_end_loc_SP;
          while( ((UINT32)0) != fl_tot_nb_char_U32)
          {
          #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
            if((fl_element_def_SP->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) && 
               (fl_element_def_SP->max_num_of_lines > 1U) && 
               (p_clip_text_info_SP->is_complex == (UINT8)TRUE))
            {
              if(fl_ML_data_ptr->is_character[fl_src_str_idx] == 1U)
              {
                fl_cur_glph_index = FS_map_char(fl_client_state,fl_str_start_loc_SP[0]);
                (void)FS_get_advance(fl_client_state,fl_cur_glph_index,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
              }
              else
              {
                (void)FS_get_advance(fl_client_state,fl_str_start_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
              }
            }
            else
            {
              (void)FS_get_advance(fl_client_state,fl_str_start_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
            fl_src_str_idx++;
          #else
            (void)FS_get_advance(fl_client_state,fl_str_start_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
          #endif
          /* In order to prevent the removal of last letter in normal clipping mode so the Character
          exceeding the textbox width is hardcut*/
            if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL) 
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
            || (fl_element_def_SP->max_num_of_lines != 1U)
#endif
            )
            {
              fl_tot_str_size -= (SINT32)(i_dx + fl_font_char_space);
              fl_tot_nb_char_U32--;
              fl_str_start_loc_SP++;
            }
            /* here the normal clip mode is an exception because the total string size is forcefully made higher than the text box size*/
            {

              if ((fl_tot_str_size <= fl_calc_width)|| (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                if(p_string != GFX_MGR02_NULL_PTR)
                {
                  if(fl_append_length > 0)
                  {
                    if(fl_tot_nb_char_U32 > ((UINT32)GFX_MGR02_MAX_TEXT_LENGTH-(UINT32)GFX_MGR02_APPEND_CHAR_CNT))
                    {
                      /*
                      ** We are now OK to fit the width of the string but
                      ** if the p_string cannot accomodate the string characters yet
                      ** we have to remove more characters..
                      */
                      continue;
                    }
                    else
                    {
                      for(fl_append_str_index_U8 = 0u; fl_append_str_index_U8 < (UINT32)GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                      {
                       #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                        if((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                        {
                          p_string[fl_append_str_index_U8] = fl_append_char_glyph_id;
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].glyphID = fl_append_char_glyph_id;
                          /* Updating GPOS delta values with zero's since for append string ... delta values will be 0 */
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].advance.x = 0;
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].advance.y = 0;
                        }
                        else
                        {
                          p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                        }
                       #else
                        p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                       #endif
                      }
                      (void)hmi_convert_utf32cp_to_utf16cp(&p_string[fl_append_str_length_U8], fl_str_start_loc_SP, fl_tot_nb_char_U32);

                      fl_tot_str_size   += fl_append_length;
                      fl_tot_nb_char_U32 += fl_append_str_length_U8;
                    }
                  }
                  else
                  {
                    UINT32 fl_converted_length;
                    if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                    {
                      fl_tot_nb_char_U32   =  GFX_MGR02_MAX_TEXT_LENGTH;
                    }
                    fl_converted_length = hmi_convert_utf32cp_to_utf16cp(p_string, fl_str_start_loc_SP, fl_tot_nb_char_U32);
                    p_string[fl_converted_length]  =  0;
                  }
                  p_clip_text_info_SP->print_str_P =  p_string;
                }
                else
                {
                  fl_tot_str_size     +=  fl_append_length;
                  fl_tot_nb_char_U32  +=  fl_append_str_length_U8;
                }
#endif
                break;
              }
            }
          }

        }
        else
        {
          while( ((UINT32)0) != fl_tot_nb_char_U32)
          {
          #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
            if((fl_element_def_SP->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) && 
               (fl_element_def_SP->max_num_of_lines > 1U) && 
               (p_clip_text_info_SP->is_complex == (UINT8)TRUE))
            {
              if(fl_ML_data_ptr->is_character[fl_src_str_idx] == 1U)
              {
                fl_cur_glph_index = FS_map_char(fl_client_state,fl_str_end_loc_SP[0]);
                (void)FS_get_advance(fl_client_state,fl_cur_glph_index,FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
              }
              else
              {
                (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
              }
            }
            else
            {
              (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
            }
            fl_src_str_idx--;
          #else
            (void)FS_get_advance(fl_client_state,fl_str_end_loc_SP[0],FS_MAP_GRAYMAP8,&i_dx,&i_dy,&dx,&dy);
          #endif
          /* In order to prevent the removal of last letter in normal clipping mode so the Character
          exceeding the textbox width is hardcut*/
            if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL) 
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
            || (fl_element_def_SP->max_num_of_lines != 1U)
#endif
            )
            {
              fl_tot_str_size -= (SINT32)(i_dx + fl_font_char_space);
              fl_tot_nb_char_U32--;
              fl_str_end_loc_SP--;
            }
            /* here the normal clip mode is an exception because the total string size is forcefully made higher than the text box size*/
            {
              if((fl_tot_str_size <= fl_calc_width) || (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                if(p_string != GFX_MGR02_NULL_PTR)
                {
                  if(fl_append_length > 0)
                  {
                    if(fl_tot_nb_char_U32 > ((UINT32)GFX_MGR02_MAX_TEXT_LENGTH-(UINT32)GFX_MGR02_APPEND_CHAR_CNT))
                    {
                      /*
                      ** We are now OK to fit the width of the string but
                      ** ff the p_string cannot accomodate the string characters yet
                      ** we have to remove more characters..
                      */
                      continue;
                    }
                    else
                    {
                      UINT32 fl_converted_length = hmi_convert_utf32cp_to_utf16cp(p_string, fl_str_start_loc_SP, fl_tot_nb_char_U32);
                      fl_append_str_index_U8  = fl_converted_length;
                      fl_tot_nb_char_U32     += fl_append_str_length_U8;
                      fl_tot_str_size        += fl_append_length;
                      for(;
                        fl_append_str_index_U8 < (fl_converted_length + fl_append_str_length_U8);
                        fl_append_str_index_U8++)
                      {
                       #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                        if((fl_complex_script == (UINT8)TRUE) && (fl_shaper_ptr != GFX_MGR02_NULL_PTR))
                        {
                          p_string[fl_append_str_index_U8] = fl_append_char_glyph_id;
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].glyphID = fl_append_char_glyph_id;
                          /* Updating GPOS delta values with zero's since for append string ... delta values will be 0 */
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].advance.x = 0;
                          fl_shaper_ptr->textInfoArray[fl_append_str_index_U8].advance.y = 0;
                        }
                        else
                        {
                          p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                        }
                       #else
                        p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                       #endif
                      }
                      p_string[fl_append_str_index_U8] = (HMI_CHAR)'\0';
                    }
                  }
                  else
                  {
                    UINT32 fl_converted_length = fl_tot_nb_char_U32;
                    if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                    {
                      fl_tot_nb_char_U32  = GFX_MGR02_MAX_TEXT_LENGTH;
                    }
                    fl_converted_length = hmi_convert_utf32cp_to_utf16cp(p_string, fl_str_start_loc_SP, fl_tot_nb_char_U32);
                    p_string[fl_converted_length] = 0;
                  }
                  p_clip_text_info_SP->print_str_P = p_string;
                }
                else
                {
                  fl_tot_str_size   += fl_append_length;
                  fl_tot_nb_char_U32 += fl_append_str_length_U8;
                }
#endif
                break;
              }
            }
          }
        }
      }
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
      else if(p_string != GFX_MGR02_NULL_PTR)
      {
        UINT32 fl_converted_length;
        if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
        {
          fl_tot_nb_char_U32  = GFX_MGR02_MAX_TEXT_LENGTH;
        }
        fl_converted_length = hmi_convert_utf32cp_to_utf16cp(p_string, fl_str_start_loc_SP, fl_tot_nb_char_U32);
        p_string[fl_converted_length] = 0;
        p_clip_text_info_SP->print_str_P = p_string;
      }
      else
      {
      }
#endif /* #if defined(GFX_MGR02_CLIP_TEXT_ENABLE) */
   #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    #if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
     #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
      if((fl_element_def_SP->wrap_mode != (UINT8)GFX_MGR02_WRAP_WORD) && 
              (fl_element_def_SP->max_num_of_lines == 1U))
     #endif
      {
          if(fl_complex_script == (UINT8)TRUE)
          {
           /* set the flag so that get_glyph functions will turn ON cmap      */
            (void)FS_set_flags(fl_client_state, FLAGS_CMAP_ON);
            if(fl_shape_str != GFX_MGR02_NULL_PTR)
            {
              /* Deviation - MISRA C-2012 Rule 21.3 disallows use of function free()            
               * the use of dynamic memory allocation API(free) has been carefully considered here. 
              */
              free(fl_shape_str);
            }
          }
      }
     #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
      else
      {
         if(p_clip_text_info_SP->is_complex == (UINT8)TRUE)
        {
          /* set the flag so that get_glyph functions will turn ON cmap      */
          (void)FS_set_flags(fl_client_state, FLAGS_CMAP_ON);
        }
      }
     #endif
    #endif
   #endif
    }
    if(fl_tot_str_size < 0)
    {
      fl_tot_str_size = 0;
    }
 #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
    else
    {
      if((fl_effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT) && (fl_tot_str_size > 0))
      {
        /* Add the shadow width back to the calculated width, since 
        ** even shadow text should accommodate within it
        */ 
        fl_tot_str_size += fl_shadow_width;
      }
    }
  #endif
    p_clip_text_info_SP->print_width     = (UINT16)fl_tot_str_size;
    p_clip_text_info_SP->print_length_U8 = (UINT8)fl_tot_nb_char_U32;
  }   
  return(fl_clip_flag_U8);
}
#endif /*#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE*/
#endif /* #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)*/

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_set_font_size
Description          : Sets font size for TTF
Parameters           : UINT32 p_font_id     - Font ID to update the size
UINT8 p_fnt_pt_size  - Font height in terms of pixels
Invocation           :
Critical Section     : None
External Interfaces  :
******************************************************************************/
void hmi_gfx_mgr02_set_font_size(UINT32 p_font_id, UINT8 p_fnt_pt_size)
{
  if (p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
  {
    UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id(p_font_id);

    GFX_MGR02_FONT const *fl_font_SP = NULL;
    if (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
      fl_font_SP = &lc_gfx_font_table[fl_font_id];
      if ((fl_font_SP != NULL) && (fl_font_SP->is_ffile != (UINT8)0))
      {
        UINT8 fl_cur_font_size;
        fl_cur_font_size = hmi_gfx_mgr02_context_get_ft2_font_size(fl_font_id);
#ifdef GFX_DISABLE_FONT_FACE_OPTIMIZATION
        if (fl_cur_font_size != p_fnt_pt_size)
#endif
        {

          GFX_FLOAT ptsize = ((GFX_FLOAT)p_fnt_pt_size * (GFX_FLOAT)64);
          if (ptsize > (GFX_FLOAT)0)
          {
            FT_Error fl_error;
            GFX_MGR02_CONTEXT_T *fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
            FT_Face face = fl_context_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
            UINT32 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(fl_font_id);
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
            FTC_Manager fl_ftc_manager;
            fl_ftc_manager = hmi_gfx_mgr02_get_ft2_cachemgr_handler();
            fl_error = FTC_Manager_LookupFace(fl_ftc_manager, (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index], &face);
            if (fl_error == 0)
            {
              FTC_ScalerRec fl_scaler;
              FT_Size fl_asize = NULL;
              fl_scaler.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
              fl_scaler.width = 0;
              fl_scaler.height = (FT_UInt)ptsize;
              fl_scaler.pixel = 0;
              fl_scaler.x_res = GFX_MGR02_DPI;
              fl_scaler.y_res = GFX_MGR02_DPI;
              fl_error = FTC_Manager_LookupSize(fl_ftc_manager, &fl_scaler, &fl_asize);
              if ((fl_error == FALSE) && (fl_asize != NULL))
              {
                fl_error = FT_Activate_Size(fl_asize);
              }
            }
#else
            fl_error = FT_Set_Char_Size(
                face,               /* handle to face object           */
                0,                  /* char_width in 1/64th of points  */
                (FT_F26Dot6)ptsize, /* char_height in 1/64th of points */
                GFX_MGR02_DPI,      /* horizontal device resolution    */
                GFX_MGR02_DPI);     /* vertical device resolution      */

#endif
            if (fl_error == FALSE)
            {
              if ((fl_font_id == fl_ft2_face_index) && (fl_cur_font_size != p_fnt_pt_size))
              {
                hmi_gfx_mgr02_context_set_ft2_font_size(fl_font_id, p_fnt_pt_size);
              }
            }
          }
        }
      }
    }
  }
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_text_width
Description          : Returns the total pixel width of the passed text string.
Invocation           :
Parameters           : p_p_clip_text_info_SP->disp_string_P - Pointer to String
p_string - pointer to a buffer where the print string will 
will be copied. The buffer has to have a 
size of (GFX_MGR02_MAX_TEXT_LENGTH+1)
Return Value         : FALSE - String not clipped, TRUE - String is clipped.
Critical Section     : None
External Interfaces  :
******************************************************************************/
UINT32 hmi_gfx_mgr02_get_text_width(GFX_MGR02_TEXT_INFO* p_clip_text_info_SP,
  UINT32            p_font_id,
  UINT32            p_clip_mode,
  UINT32            p_alignment
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  , HMI_CHAR* p_string
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  , GFX_MGR02_SHAPE_INFO* p_shaper_info
#endif
)
{
    GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_base_SP;
    GFX_MGR02_FONT_LUT         const * fl_font_lut_SP = GFX_MGR02_NULL_PTR;
    GFX_MGR02_FONT             const * fl_font_SP;
    UINT32                fl_clip_flag_U8     = (UINT32)FALSE;
    UINT32                fl_tot_nb_char_U32  = (UINT32)0;  /* total number of character in the original string */
    SINT32                fl_tot_str_size     = (SINT32)0;  /* Total size of string in pixel */
    #if (((GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)) || (defined(GFX_MGR02_CLIP_TEXT_ENABLE)))
    SINT32                fl_append_length    = (SINT32)0;
    #endif
    HMI_CHAR      const * fl_str_start_loc_SP = p_clip_text_info_SP->print_str_P;
    HMI_CHAR      const * fl_str_end_loc_SP;
    SINT32                fl_calc_width;
    #if defined(GFX_MGR02_KEPLER)
    SINT32 fl_startx_offset;
    SINT32 fl_write_width = 0;
    UINT32 fl_font_bpp    = GFX_MGR02_FONT_ENCODING_8BPP;
    #endif
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
    SINT32                fl_tot_xadv = 0;
    UINT32                fl_vg_font;
    #endif
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    UINT32                fl_append_str_index_U8;
    UINT32                fl_append_str_length_U8 = 0;
    #endif
    #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
    UINT16 fl_scale_string_size = 0;
    #endif
    #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
    GFX_CLIP_INFO          fl_clip_info;
    #endif
    UINT32                fl_str_len;
    HMI_CHAR const *      fl_loop_check_SP;
    
    #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
    hmi_gfx_mgr02_set_font_size(p_font_id, p_clip_text_info_SP->font_pt_size);
    #endif   
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(p_font_id);

    p_clip_text_info_SP->print_length_U8 = (UINT8)0;
    p_clip_text_info_SP->print_width     = (UINT16)0;

    if((fl_font_SP != GFX_MGR02_NULL_PTR) && (fl_str_start_loc_SP != GFX_MGR02_NULL_PTR))
    {      
        #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
        if(p_clip_text_info_SP->get_dynamic_clipinfo == (UINT8)TRUE)
        {
          /* Get the clip info from application. */
          fl_clip_info = GFX_MGR_GET_CLIP_INFO(p_clip_text_info_SP->print_str_P);		
          if(fl_clip_info == LEFT_CLIP)
          {
            p_alignment = GFX_MGR02_TP_ALIGN_RIGHT;
          }
          else if(fl_clip_info == RIGHT_CLIP)
          {
            p_alignment = GFX_MGR02_TP_ALIGN_LEFT;
          }
          else
          {
              /*For Fixing MISRA warning.*/
          }
        }
        #endif
  
        if(fl_font_SP->is_vfont != (UINT8) 0)
        {
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
          fl_font_lut_SP = fl_font_SP->f.ovg_ptr->lut_ptr;
          fl_vg_font = TRUE;
    #else
          fl_font_lut_SP = GFX_MGR02_NULL_PTR;
    #endif
        }
    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
        else if(fl_font_SP->is_ffile !=(UINT8) 0)
        {
          fl_clip_flag_U8 = hmi_gfx_mgr02_ft2_get_text_width(p_clip_text_info_SP,
            p_font_id,
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)        
            p_clip_mode,
    #endif
            p_alignment
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            ,p_string
    #endif
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
           ,p_shaper_info
    #endif
            );
        }
    #endif
    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
        else if(fl_font_SP->is_ffile != 0U)
        {
          fl_clip_flag_U8 = hmi_gfx_mgr02_mt_get_text_width(p_clip_text_info_SP,
            p_font_id,
            p_clip_mode,
            p_alignment
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            ,p_string
    #endif
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
           ,p_shaper_info
    #endif
            );
        }
    #endif
        else
        {
          fl_font_lut_SP = fl_font_SP->f.lut_ptr;
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
          fl_vg_font     = FALSE;
    #endif
    #if defined(GFX_MGR02_KEPLER)
          fl_font_bpp    = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);
    #endif
        }

    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
        if(fl_font_SP->is_ffile == 0u)
        {
    #endif
          if((*fl_str_start_loc_SP != ((HMI_CHAR)0)) && (fl_font_lut_SP != GFX_MGR02_NULL_PTR))
          {
            fl_str_len = HMI_STRLEN(fl_str_start_loc_SP);
            if(((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT) && (fl_str_len > 0U))
            {
              fl_str_end_loc_SP = &fl_str_start_loc_SP[fl_str_len-1U];
              fl_loop_check_SP = &fl_str_start_loc_SP[0];
            }
            else
            {
              fl_str_end_loc_SP = fl_str_start_loc_SP;
              fl_loop_check_SP = &fl_str_start_loc_SP[fl_str_len-1U];
            }

    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
            if(fl_vg_font != FALSE)
            {
              GFX_MGR02_OVG_GLYPH_DEF_T const * fl_vg_glyph_SP;

              while(fl_tot_nb_char_U32 < (UINT32)p_clip_text_info_SP->num_chars_to_process)
              {
                fl_vg_glyph_SP = (GFX_MGR02_OVG_GLYPH_DEF_T const *)hmi_gfx_mgr02_get_fcc(*fl_str_end_loc_SP, fl_font_lut_SP, fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                  p_font_id,
    #endif
                  TRUE);
                if(fl_vg_glyph_SP != 0)
                {
                  fl_tot_str_size += fl_vg_glyph_SP->x_advance;
                }
                fl_tot_nb_char_U32++;
                /* Added this check to optimize the width calculation algorithm.
                ** suppose if string = ABCDEFGHIJKL, and string got truncated
                ** at "D" character itself, so need not to process remaining
                ** characters (EFGHIJKL)
                */ 
                if((fl_tot_str_size > p_clip_text_info_SP->max_available_width) || (fl_str_end_loc_SP == fl_loop_check_SP))
                {
                  break;
                }
                else
                {
                  if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                  {
                    fl_str_end_loc_SP--;
                  }
                  else
                  {
                    fl_str_end_loc_SP++;
                  }
                }
              }
              if(fl_tot_str_size != 0)
              {
                fl_tot_xadv      = fl_tot_str_size;
                fl_tot_str_size  = (fl_tot_str_size * fl_font_SP->f.ovg_ptr->ptsize);
                fl_tot_str_size /= fl_font_SP->f.ovg_ptr->bmsize;
              }
            }
            else
    #endif
    #if (defined(GFX_MGR02_KEPLER) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE)  || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)  || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)))
            {
              SINT32 width;
              fl_tot_nb_char_U32=HMI_STRLEN ((HMI_CHAR*) fl_str_start_loc_SP);
              if(fl_tot_nb_char_U32>GFX_MGR02_MAX_TEXT_LENGTH)fl_tot_nb_char_U32=GFX_MGR02_MAX_TEXT_LENGTH;
              {
                SINT16 fl_text_width = 0;
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE) && defined(GFX_MGR02_KEPLER)	
                UINT8 fl_current_font_engine = ui_app_get_cur_font_engine();
    #endif

    #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
                if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
    #endif
                {
                  fl_text_width = digi_get_text_width(lc_gfx_digi_append_txt_font_width[p_font_id],(DT16_ushort*)fl_str_start_loc_SP,fl_tot_nb_char_U32,(DT32_int*)&width);
                }
    #endif
    #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
                else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
    #endif
                {
                  fl_text_width = monotype_get_text_width(lc_gfx_mono_append_txt_font_width[p_font_id],(MT16_ushort*)fl_str_start_loc_SP,fl_tot_nb_char_U32,(MT32_int*)&width);	
                }
    #endif
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE) && defined(GFX_MGR02_KEPLER)	
                else
                {
                }
    #endif

                if(fl_text_width<0)
                {
                  /*Before initialize Digitype */
                  fl_tot_str_size=0;
                  fl_tot_nb_char_U32=0;
                }
                else
                {
                  fl_tot_str_size=width;
                }
                if(fl_tot_str_size > p_clip_text_info_SP->max_available_width)
                {
                  fl_clip_flag_U8  = TRUE;
                  fl_tot_str_size=p_clip_text_info_SP->max_available_width;
                }
              }
            }
            p_clip_text_info_SP->print_width     = (UINT16)fl_tot_str_size;
            p_clip_text_info_SP->print_length_U8 = (UINT8)fl_tot_nb_char_U32;
            GFX_MGR02_UNUSED_VAR(p_clip_mode);
            return(fl_clip_flag_U8);
    #else /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) */
            {
              while(fl_tot_nb_char_U32 < (UINT32)p_clip_text_info_SP->num_chars_to_process)
              {
                fl_font_base_SP = hmi_gfx_mgr02_get_fcc(*fl_str_end_loc_SP, fl_font_lut_SP, (UINT32)fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                  (UINT32)p_font_id,
    #endif
                  (UINT32)FALSE);
                if(fl_font_base_SP != GFX_MGR02_NULL_PTR)
                {
                  SINT32 fl_owidth = (SINT32)fl_font_base_SP->owidth;
    #if defined(GFX_MGR02_KEPLER)
                  fl_write_width   = fl_tot_str_size;
    #endif
                  fl_tot_str_size += fl_owidth;
    #if defined(GFX_MGR02_KEPLER)
    #if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
    #if defined(GFX_MGR02_CPU_ARABIC_JOINING_PATCH)
                  if(fl_font_base_SP->x_soffset == -1)
                  {
                    if((CheckArabicCharRange(*fl_str_end_loc_SP) == TRUE) && \
                      (fl_tot_nb_char_U32 != ((UINT32)0)) && \
                      (fl_font_bpp == GFX_MGR02_FONT_ENCODING_4BPP))
                    {
                      /* 
                      when address is odd, then make it even to see joining effect clearly in Arabic
                      since moving 1 extra pixel and blending with the previous 2 pixels,
                      decrement "fl_tot_str_size" by 1 pixel.
                      */
                      fl_tot_str_size--;
                    }
                  }
    #endif
    #endif
                  if(p_clip_text_info_SP->target == GFX_MGR02_TARGET_DCU)
                  {
    #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                    if(fl_font_bpp == GFX_MGR02_FONT_ENCODING_4BPP)
                    {
                      if(((fl_tot_str_size & 0x01) != 0)&& (fl_str_end_loc_SP[1] != 0))
                      {
                        fl_tot_str_size++;
                      }
                    }
    #endif
                    /*
                    ** The width may sometimes be > owidth, in that case there is a 
                    ** possibility that we may be allocating less width than what is 
                    ** necessary. So below operations are for maintaining to what
                    ** extend we might write in to the text buffer. If the write 
                    ** extend is > fl_tot_str_size, we have to make fl_tot_str_size
                    ** large enough to accomodate the extend of the buffer write.
                    */
                    fl_startx_offset = fl_font_base_SP->x_soffset;
                    if(fl_startx_offset < 0)
                    {
                      if((fl_write_width+fl_startx_offset) < 0)
                      {
                        fl_write_width   = -fl_startx_offset;
                        fl_startx_offset = 0;
                      }
                    }
    #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                    if(fl_font_bpp == GFX_MGR02_FONT_ENCODING_4BPP)
                    {
                      if((fl_startx_offset & 1) != 0)
                      {
                        fl_startx_offset++;
                      }
                    }
    #endif
                    if(fl_font_base_SP->width != 0)
                    {
                      fl_write_width += fl_startx_offset;
                      fl_write_width += fl_font_base_SP->width;
    #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                      if((fl_font_bpp == GFX_MGR02_FONT_ENCODING_4BPP) && ((fl_write_width & 1) != 0))
                      {
                        fl_write_width++;
                      }
    #endif
                    }
                  }
    #endif
                }
                fl_tot_nb_char_U32++;
                /* Added this check to optimize the width calculation algorithm.
                ** suppose if string = ABCDEFGHIJKL, and string got truncated
                ** at "D" character itself, so need not to process remaining
                ** characters (EFGHIJKL)
                */ 
                if((fl_tot_str_size > (SINT32)(p_clip_text_info_SP->max_available_width)) || (fl_str_end_loc_SP == fl_loop_check_SP))
                { 
                  break;
                }
                else
                {
                  if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                  {
                    fl_str_end_loc_SP--;
                  }
                  else
                  {
                    fl_str_end_loc_SP++;
                  }
                }
                if(fl_font_base_SP != GFX_MGR02_NULL_PTR)
                {
                  fl_tot_str_size += (SINT32)fl_font_SP->char_space; //for invalid character characterspacing not required
                }
              }
    #if defined(GFX_MGR02_KEPLER)
              if(p_clip_text_info_SP->target == GFX_MGR02_TARGET_DCU)
              {
                if(fl_tot_str_size < fl_write_width)
                {
                  fl_tot_str_size = fl_write_width;
                }
              }
    #endif
            }

            if((fl_tot_str_size >(SINT32) p_clip_text_info_SP->max_available_width) && (p_clip_mode != (UINT32)GFX_MGR02_TP_NO_CLIP))
            {
              fl_clip_flag_U8  = (UINT32)TRUE;
            }
    #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
            if(((UINT32)FALSE != fl_clip_flag_U8)&&(p_clip_text_info_SP->scroll == GFX_MGR02_TP_SCROLL_DISABLE))
            {
              fl_scale_string_size = (UINT16)(((fl_tot_str_size * PERC_SCALING) / (UINT16)100) + (UINT16)1); /* apply the max. scaling */
              if(fl_scale_string_size < p_clip_text_info_SP->max_available_width)
              {
                p_clip_text_info_SP->print_width     = (UINT16)fl_tot_str_size;
                p_clip_text_info_SP->print_length_U8 = (UINT8)fl_tot_nb_char_U32;
                return(fl_clip_flag_U8);
              }
            }
    #endif

            fl_calc_width = (SINT32)p_clip_text_info_SP->max_available_width;

            if(fl_clip_flag_U8 != (UINT32)FALSE)
            {
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
              if((p_clip_text_info_SP->append_str != (UINT32)FALSE) &&
                (((p_clip_mode & GFX_MGR02_TP_CLIP_APPEND) == GFX_MGR02_TP_CLIP_APPEND) || 
                 ((p_clip_mode & GFX_MGR02_TP_CLIP_SHRINK_FIT) == GFX_MGR02_TP_CLIP_SHRINK_FIT)))
              {
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
                if(fl_vg_font != FALSE)
                {
                  GFX_MGR02_OVG_GLYPH_DEF_T const * fl_vg_glyph_SP;
                  fl_vg_glyph_SP = (GFX_MGR02_OVG_GLYPH_DEF_T const *)hmi_gfx_mgr02_get_fcc(GFX_MGR02_APPEND_CHAR, fl_font_lut_SP, fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                    p_font_id,
    #endif
                    TRUE);

                  if(fl_vg_glyph_SP != 0)
                  {
                    fl_append_length  = fl_vg_glyph_SP->x_advance;
                    if(fl_append_length > 0)
                    {
                      fl_append_length *= GFX_MGR02_APPEND_CHAR_CNT;
                      fl_append_length *= fl_font_SP->f.ovg_ptr->ptsize;
                      fl_append_length /= fl_font_SP->f.ovg_ptr->bmsize;
                    }
                  }
                }
                else
    #endif
                {
                  fl_font_base_SP  = hmi_gfx_mgr02_get_fcc(GFX_MGR02_APPEND_CHAR, fl_font_lut_SP, (UINT32)fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                    p_font_id,
    #endif
                    FALSE);
                  if(fl_font_base_SP != GFX_MGR02_NULL_PTR)
                  {
                    fl_append_length = (GFX_MGR02_APPEND_CHAR_CNT * (SINT32)fl_font_base_SP->owidth);
                    fl_append_length += (GFX_MGR02_APPEND_CHAR_CNT * (SINT32)fl_font_SP->char_space);
                    if(fl_append_length > 0)
                    {
    #if defined(GFX_MGR02_KEPLER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                      if(p_clip_text_info_SP->target == GFX_MGR02_TARGET_DCU)
                      {
                        if((fl_font_base_SP->owidth & 0x01) != 0)
                        {
                          fl_append_length += GFX_MGR02_APPEND_CHAR_CNT;
                        }
                      }
    #endif
                    }
                  }

                }
                if((fl_append_length > 0) && (fl_append_length < (SINT32)p_clip_text_info_SP->max_available_width))
                {
                  fl_calc_width          -= fl_append_length;
                  fl_append_str_length_U8 = (UINT32)GFX_MGR02_APPEND_CHAR_CNT;
                }
                else
                {
                  /* 
                  ** append string cannot be fitted in available width 
                  ** so we don't show it..
                  */
                  fl_append_length        = 0;
                  fl_append_str_length_U8 = 0;
                }
              }
    #endif
            }

    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
            if(fl_vg_font != FALSE)
            {
              fl_calc_width *= fl_font_SP->f.ovg_ptr->bmsize;
              fl_calc_width /= fl_font_SP->f.ovg_ptr->ptsize;
            }
    #endif

            /* Clip text */
            if(fl_clip_flag_U8 != (UINT32)FALSE)
            {
                if((p_alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                    /* 
                    ** Start removing characters only from where
                    ** we have stopped (since exceeded no' of pixels
                    ** configured). It will optimize the calculation.
                    */
                    fl_str_start_loc_SP = fl_str_end_loc_SP;
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
                if(fl_vg_font != (UINT32)FALSE)
                {
                  while( ((UINT32)0) != fl_tot_nb_char_U32)
                  {
                    fl_font_base_SP = hmi_gfx_mgr02_get_fcc(*fl_str_start_loc_SP, fl_font_lut_SP, fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                      p_font_id,
    #endif
                      TRUE);
                    fl_str_start_loc_SP++;
                    fl_tot_nb_char_U32--;
                    if(fl_font_base_SP != 0)
                    {
                      fl_tot_xadv -= ((GFX_MGR02_OVG_GLYPH_DEF_T *)(void *)fl_font_base_SP)->x_advance;
                      if(fl_tot_xadv <= fl_calc_width)
                      {
                        fl_append_length *= fl_font_SP->f.ovg_ptr->bmsize;
                        fl_append_length /= fl_font_SP->f.ovg_ptr->ptsize;
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                        if(p_string != GFX_MGR02_NULL_PTR)
                        {
                          if(fl_append_length > 0)
                          {
                            if(fl_tot_nb_char_U32 > (UINT32)(GFX_MGR02_MAX_TEXT_LENGTH-GFX_MGR02_APPEND_CHAR_CNT))
                            {
                              /*
                              ** We are now OK to fit the width of the string but
                              ** if the p_string cannot accomodate the string characters yet
                              ** we have to remove more characters..
                              */
                              continue;
                            }
                            else
                            {
                              for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                              {
                                p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                              }

                              #ifdef GFX_MGR02_UNICODE
                                     (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], GFX_MGR02_MAX_TEXT_LENGTH, L"%ls", fl_str_start_loc_SP);   /* ls implies the passed input string is wide char string */                      
                              #else
                                     (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], GFX_MGR02_MAX_TEXT_LENGTH, "%s", fl_str_start_loc_SP);  /* %s implies the passed string is a single byte string */                       
                              #endif
                              
                              fl_tot_xadv       += fl_append_length;
                              fl_tot_nb_char_U32 += fl_append_str_length_U8;
                            }
                          }
                          else
                          {
                            if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                            {
                              fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                            }
                            (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
                            p_string[fl_tot_nb_char_U32] = 0;
                          }
                          p_clip_text_info_SP->print_str_P = p_string;
                        }
                        else
                        {
                          fl_tot_xadv       += fl_append_length;
                          fl_tot_nb_char_U32 += fl_append_str_length_U8;
                        }
    #endif
                        break;
                      }
                    }
                  }
                  if(fl_tot_xadv > 0)
                  {
                    fl_tot_str_size  = (fl_tot_xadv * fl_font_SP->f.ovg_ptr->ptsize);
                    fl_tot_str_size /= fl_font_SP->f.ovg_ptr->bmsize;
                  }
                  else
                  {
                    fl_tot_str_size = 0;
                  }
                }
                else
    #endif
                    {
                        while( ((UINT32)0) != fl_tot_nb_char_U32)
                        {
                            fl_font_base_SP = hmi_gfx_mgr02_get_fcc(*fl_str_start_loc_SP, fl_font_lut_SP, (UINT32)fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                            (UINT32)p_font_id,
    #endif
                            (UINT32)FALSE);
                            if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL) 
    #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                                || (p_clip_text_info_SP->dyn_text_def_SP->max_num_of_lines != 1U)
    #endif
                            )
                            {
                                fl_str_start_loc_SP++;
                                fl_tot_nb_char_U32--;
                            }
                            if(fl_font_base_SP != GFX_MGR02_NULL_PTR)
                            {
                                SINT32 fl_font_owidth = (SINT32)(fl_font_base_SP->owidth + fl_font_SP->char_space);
                                
                                if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                                    || (p_clip_text_info_SP->dyn_text_def_SP->max_num_of_lines != 1U)
#endif
                                    )
                                {
                                    fl_tot_str_size -= fl_font_owidth;
                                }
    #if defined(GFX_MGR02_KEPLER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                                if((p_clip_text_info_SP->target == GFX_MGR02_TARGET_DCU) && ((fl_font_base_SP->owidth & 0x01) != 0) )
                                {
                                    fl_tot_str_size--;
                                }
    #endif
                                if((fl_tot_str_size <= fl_calc_width) || (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
                                {
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                    if(p_string != GFX_MGR02_NULL_PTR)
                                    {
                                        if(fl_append_length > 0)
                                        {
                                            if(fl_tot_nb_char_U32 > ((UINT32)GFX_MGR02_MAX_TEXT_LENGTH-(UINT32)GFX_MGR02_APPEND_CHAR_CNT))
                                            {
                                              /*
                                              ** We are now OK to fit the width of the string but
                                              ** if the p_string cannot accomodate the string characters yet
                                              ** we have to remove more characters..
                                              */
                                              continue;
                                            }
                                            else
                                            {
                                                for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < (UINT8)GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                                                {
                                                    p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                                                }
                                                
                                                if(fl_append_str_length_U8<(UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                                                {
                                                    /* Deviation - MISRA C-2012 Rule 21.6 disallows use of standard library function swprintf */
                                                    #ifdef GFX_MGR02_UNICODE
                                                            (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], ((UINT8)GFX_MGR02_MAX_TEXT_LENGTH - (UINT8)GFX_MGR02_APPEND_CHAR_CNT), L"%ls", (const HMI_CHAR *)fl_str_start_loc_SP); /* ls implies the passed input string is wide char string */                         
                                                    #else
                                                            (void)HMI_SNPRINTF(&p_string[fl_append_str_length_U8], ((UINT8)GFX_MGR02_MAX_TEXT_LENGTH - (UINT8)GFX_MGR02_APPEND_CHAR_CNT), "%s", (const HMI_CHAR *)fl_str_start_loc_SP);   /* %s implies the passed string is a single byte string */                      
                                                    #endif
                                                }
                              
                                                fl_tot_str_size   += fl_append_length;
                                                fl_tot_nb_char_U32 += fl_append_str_length_U8;
                                            }
                                        }
                                        else
                                        {
                                            if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                                            {
                                              fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                                            }
                                            (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,(size_t)fl_tot_nb_char_U32);
                                            p_string[fl_tot_nb_char_U32] = 0;
                                        }
                                        p_clip_text_info_SP->print_str_P = p_string;
                                    }
                                    else
                                    {
                                        fl_tot_str_size   += fl_append_length;
                                        fl_tot_nb_char_U32 += fl_append_str_length_U8;
                                    }
    #else
                                    {
                                        if(fl_tot_nb_char_U32 >(UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                                        {
                                            fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                                        }
                            
                                        p_clip_text_info_SP->print_str_P = fl_str_start_loc_SP;
                              
                                    }
    #endif
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
    #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && defined(GFX_MGR02_OPEN_VG)
                    if(fl_vg_font != FALSE)
                    {
                        while( ((UINT32)0) != fl_tot_nb_char_U32)
                        {
                            fl_font_base_SP = hmi_gfx_mgr02_get_fcc(*fl_str_end_loc_SP, fl_font_lut_SP, fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                            p_font_id,
    #endif
                            TRUE);
                            fl_tot_nb_char_U32--;
                            fl_str_end_loc_SP--;
                            if(fl_font_base_SP != 0)
                            {
                                fl_tot_xadv -= ((GFX_MGR02_OVG_GLYPH_DEF_T *)(void *)fl_font_base_SP)->x_advance;
                                if(fl_tot_xadv <= fl_calc_width)
                                {
                                    fl_append_length *= fl_font_SP->f.ovg_ptr->bmsize;
                                    fl_append_length /= fl_font_SP->f.ovg_ptr->ptsize;
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                    if(p_string != GFX_MGR02_NULL_PTR)
                                    {
                                        if(fl_append_length > 0)
                                        {
                                            if(fl_tot_nb_char_U32 > (UINT32)(GFX_MGR02_MAX_TEXT_LENGTH-GFX_MGR02_APPEND_CHAR_CNT))
                                            {
                                              /*
                                              ** We are now OK to fit the width of the string but
                                              ** ff the p_string cannot accomodate the string characters yet
                                              ** we have to remove more characters..
                                              */
                                              continue;
                                            }
                                            else
                                            {
                                              (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
                                              fl_append_str_index_U8 = fl_tot_nb_char_U32;
                                              fl_tot_nb_char_U32     += fl_append_str_length_U8;
                                              fl_tot_xadv           += fl_append_length;
                                              for(;
                                                fl_append_str_index_U8 < fl_tot_nb_char_U32; 
                                                fl_append_str_index_U8++)
                                              {
                                                p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                                              }
                                                p_string[fl_append_str_index_U8] = '\0';
                                            }
                                        }
                                        else
                                        {
                                            if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                                            {
                                              fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                                            }
                                            (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,fl_tot_nb_char_U32);
                                            p_string[fl_tot_nb_char_U32] = 0;
                                        }
                                        p_clip_text_info_SP->print_str_P = p_string;
                                    }
                                    else
                                    {
                                        fl_tot_xadv       += fl_append_length;
                                        fl_tot_nb_char_U32 += fl_append_str_length_U8;
                                    }
    #endif
                                    break;
                                }
                            }
                        }
                        if(fl_tot_xadv > 0)
                        {
                            fl_tot_str_size  = (fl_tot_xadv * fl_font_SP->f.ovg_ptr->ptsize);
                            fl_tot_str_size /= fl_font_SP->f.ovg_ptr->bmsize;
                        }
                        else
                        {
                            fl_tot_str_size = 0;
                        }
                    }
                    else
    #endif
                    {
                        while( ((UINT32)0) != fl_tot_nb_char_U32)
                        {
                            fl_font_base_SP = hmi_gfx_mgr02_get_fcc(*fl_str_end_loc_SP, fl_font_lut_SP, (UINT32)fl_font_SP->size_table, 
    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                            (UINT32)p_font_id,
    #endif
                            (UINT32)FALSE);
                            if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL)
    #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                            || (p_clip_text_info_SP->dyn_text_def_SP->max_num_of_lines != 1U)
    #endif
                            )
                            {
                                fl_tot_nb_char_U32--;
                                fl_str_end_loc_SP--;
                            }
                            if(fl_font_base_SP != GFX_MGR02_NULL_PTR)
                            {
                                SINT32 fl_font_SP_owidth = (SINT32)(fl_font_base_SP->owidth + fl_font_SP->char_space);
                                if ((p_clip_mode != GFX_MGR02_TP_CLIP_NORMAL)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
                                    || (p_clip_text_info_SP->dyn_text_def_SP->max_num_of_lines != 1U)
#endif
                                    )
                                {
                                    fl_tot_str_size -= fl_font_SP_owidth;
                                }
    #if defined(GFX_MGR02_KEPLER)  && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
                                if((p_clip_text_info_SP->target == GFX_MGR02_TARGET_DCU) && ((fl_font_base_SP->owidth & 0x01) != 0) )
                                {
                                    fl_tot_str_size--;
                                }
    #endif
                                if((fl_tot_str_size <= fl_calc_width) || (p_clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
                                {
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                    if(p_string != GFX_MGR02_NULL_PTR)
                                    {
                                      if(fl_append_length > 0)
                                      {
                                        if(fl_tot_nb_char_U32 > ((UINT32)GFX_MGR02_MAX_TEXT_LENGTH-(UINT32)GFX_MGR02_APPEND_CHAR_CNT))
                                        {
                                          /*
                                          ** We are now OK to fit the width of the string but
                                          ** ff the p_string cannot accomodate the string characters yet
                                          ** we have to remove more characters..
                                          */
                                          continue;
                                        }
                                        else
                                        {
                                          (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,(size_t)fl_tot_nb_char_U32);
                                          fl_append_str_index_U8 = fl_tot_nb_char_U32;
                                          fl_tot_nb_char_U32     += fl_append_str_length_U8;
                                          fl_tot_str_size       += fl_append_length;
                                          for(;
                                            fl_append_str_index_U8 < fl_tot_nb_char_U32; 
                                            fl_append_str_index_U8++)
                                          {
                                            p_string[fl_append_str_index_U8] = GFX_MGR02_APPEND_CHAR;
                                          }
                                          p_string[fl_append_str_index_U8] = (HMI_CHAR)'\0';
                                        }
                                      }
                                      else
                                      {
                                        if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                                        {
                                          fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                                        }
                                        (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,(size_t)fl_tot_nb_char_U32);
                                        p_string[fl_tot_nb_char_U32] = 0;
                                      }
                                      p_clip_text_info_SP->print_str_P = p_string;
                                    }
                                    else
                                    {
                                        fl_tot_str_size   += (SINT32)fl_append_length;
                                        fl_tot_nb_char_U32 += fl_append_str_length_U8;
                                    }
    #endif
                                    break;
                                }
                            }
                        }
                    }
                }
            }
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            else if(p_string != GFX_MGR02_NULL_PTR)
            {
                if(fl_tot_nb_char_U32 > (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
                {
                    fl_tot_nb_char_U32 = GFX_MGR02_MAX_TEXT_LENGTH;
                }
                (void)HMI_STRNCPY(p_string,fl_str_start_loc_SP,(size_t)fl_tot_nb_char_U32);
                p_string[fl_tot_nb_char_U32] = 0;
                p_clip_text_info_SP->print_str_P = p_string;
            }
            else
            {
              /*MISRA.IF.NO_ELSE fix*/
            }
    #endif /* #if defined(GFX_MGR02_CLIP_TEXT_ENABLE) */
    #endif  /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE)       */
          }
          
          if(fl_tot_str_size < 0)
          {
            fl_tot_str_size = 0;
          }
          
          p_clip_text_info_SP->print_width     = (UINT16)fl_tot_str_size;
          p_clip_text_info_SP->print_length_U8 = (UINT8)fl_tot_nb_char_U32;
    #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
        }
    #endif
    }  

#if defined(GFX_MGR02_OPEN_VG)   
    GFX_MGR02_UNUSED_VAR(p_clip_mode);
#endif   
    return(fl_clip_flag_U8);
}
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_arabic_char_count
** Visibility:       Static
** Description:      This interface return number of thai character inside the
**                   string
**                   
** Invocation:       Invoked by layout

**                   
** Inputs			  Array of Unicodes for the Display
** Outputs:          Count on the no.of the unicodes within the range
** Critical Section: None.
** Created:          1-June-2016 by CSAKTHIV
** Updated:          
**==========================================================================*/

UINT16 hmi_gfx_mgr02_get_arabic_char_count(HMI_CHAR const *In_Str, UINT16 p_count)
{
  UINT16 fl_range =0U;
  UINT16 fl_data ;

  for(fl_data = 0U; fl_data < p_count;fl_data++)
  {

    if(((In_Str[fl_data] >= ARABIC_SET1_LOW) && (In_Str[fl_data] <= ARABIC_SET1_HIGH)) ||
      ((In_Str[fl_data] >= ARABIC_PRESENTATION_FORMS_A_START) && (In_Str[fl_data] <= ARABIC_PRESENTATION_FORMS_A_END)) || 
      ((In_Str[fl_data] >= ARABIC_PRESENTATION_FORMS_B_START) && (In_Str[fl_data] <= ARABIC_PRESENTATION_FORMS_B_END))  ||
      ((In_Str[fl_data] >= LRE_UNICODE) && (In_Str[fl_data] <= RLO_UNICODE)) ||
      (In_Str[fl_data] == LRM_UNICODE) || (In_Str[fl_data] == RLM_UNICODE))
    {
      fl_range += ((UINT16)1);
      break;
    }
  }
  return fl_range;
}
#endif

#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_hebrew_char_count
** Visibility:       Static
** Description:      This interface return number of hebrew character inside the
**                   string
**                   
** Invocation:       Invoked by layout
** Inputs            Array of Unicodes for the Display
** Outputs:          Count the no.of the unicodes within the hebrew char range
** Critical Section: None.
** Created:          30-Nov-2017 by ARAJASE2
** Updated:          
**==========================================================================*/

UINT16 hmi_gfx_mgr02_get_hebrew_char_count(HMI_CHAR const *In_Str, UINT16 p_count)
{
  UINT16 fl_range = 0U;
  UINT16 fl_data ;
  for(fl_data = 0U; fl_data < p_count;fl_data++)
  {
    if(((In_Str[fl_data] >= HEBREW_START) && (In_Str[fl_data] <= HEBREW_END)) ||
      ((In_Str[fl_data] >= LRE_UNICODE) && (In_Str[fl_data] <= RLO_UNICODE)) ||
      ((In_Str[fl_data] == LRM_UNICODE) || (In_Str[fl_data] == RLM_UNICODE)))
    {
      fl_range += ((UINT16)1);
      break;
    }
  }
  return fl_range;
}
#endif

#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_thai_char_count
** Visibility:       Static
** Description:      This interface return number of thai character inside the
**                   string.
**                   
** Invocation:       Invoked by layout
**                   
** Inputs			  Array of Unicodes for the Display
** Outputs:          Count on the no.of the unicodes within the range
** Critical Section: None.
** Created:          1/06/2016	by CSAKTHIV
** Updated:          
**==========================================================================*/

UINT16 hmi_gfx_mgr02_get_thai_char_count(HMI_CHAR const *In_Str, UINT16 p_count)
{
  UINT16 fl_range =0U;
  UINT16 fl_data ;
  for(fl_data = 0; fl_data < p_count;fl_data++)
  {

    if(((In_Str[fl_data] >= THAI_CONSONANT_START) && (In_Str[fl_data] <= THAI_CONSONANT_END)) || 
      ((In_Str[fl_data] >= THAI_SET1_START) && (In_Str[fl_data] <= THAI_SET1_END))  ||
      ((In_Str[fl_data] >= THAI_SET2_START) && (In_Str[fl_data] <= THAI_SET2_END))||
      (In_Str[fl_data] == THAI_SIGN_SYMBL) || (In_Str[fl_data] == THAI_CURRENCY_SYMBL))
    {
      fl_range += 1U;
      break;
    }
  }
  return fl_range;
}
#endif


#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_devanagari_char_count
** Visibility:       Static
** Description:      This interface return number of Hindi character inside the
**                   string.
**                   
** Invocation:       Invoked by layout
**                   
** Inputs            Array of Unicodes for the Display
** Outputs:          Count on the no.of the unicodes within the range
** Critical Section: None.
** Created:          09/30/2019 by ARAJASE2
** Updated:
**==========================================================================*/

UINT16 hmi_gfx_mgr02_get_devanagari_char_count(HMI_CHAR const *In_Str, UINT16 p_count)
{
  UINT16 fl_range = 0U;
  UINT16 fl_data ;
  for(fl_data = 0U; fl_data < p_count;fl_data++)
  {
    if((In_Str[fl_data] >= DEVANAGARI_START) && (In_Str[fl_data] <= DEVANAGARI_END))
    {
      fl_range += 1U;
      break;
    }
  }
  return fl_range;
}
#endif
#if defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_regional_char_count
** Visibility:       Static
** Description:      This interface returns whether regional character
**                   present in the string
**                   
** Invocation:       Invoked by layout
**                   
** Inputs            Array of Unicodes for the Display
** Outputs:          Count on the no.of the unicodes within the range
** Critical Section: None.
** Created:          09/30/2019 by ARAJASE2
** Updated:
**==========================================================================*/
UINT16 hmi_gfx_mgr02_get_regional_char_count(HMI_CHAR const *In_Str, UINT16 p_count)
{
  UINT16 fl_range = 0U;
  UINT16 fl_data;
  for (fl_data = 0U; fl_data < p_count; fl_data++)
  {
    if (((In_Str[fl_data] >= TAMIL_START) && (In_Str[fl_data] <= TAMIL_END)) ||
      ((In_Str[fl_data] >= BENGALI_START) && (In_Str[fl_data] <= BENGALI_END)) ||
      ((In_Str[fl_data] >= MARATHI_START) && (In_Str[fl_data] <= MARATHI_END)) ||
      ((In_Str[fl_data] >= GUJARATI_START) && (In_Str[fl_data] <= GUJARATI_END)) ||
      ((In_Str[fl_data] >= KANNADA_START) && (In_Str[fl_data] <= KANNADA_END)) ||
      ((In_Str[fl_data] >= MALAYALAM_START) && (In_Str[fl_data] <= MALAYALAM_END)) ||
      ((In_Str[fl_data] >= TELUGU_START) && (In_Str[fl_data] <= TELUGU_END)) ||
      ((In_Str[fl_data] >= PUNJABI_START) && (In_Str[fl_data] <= PUNJABI_END)) ||
      ((In_Str[fl_data] >= ODIA_START) && (In_Str[fl_data] <= ODIA_END)))
    {
      fl_range += 1U;
      break;
    }
  }
  return fl_range;
}
#endif
#if defined(GFX_MGR02_KEPLER)
/*
** Workaround for a data corruption observed by the use of isel instruction
** Refer ui.core.gdt.doc\hmi.gfx.manager.02\release\SR# 1-1248551151.msg
*/
#ifndef WIN32
#pragma push
#pragma gen_isel off     
#endif
/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_fsl_edma_cb
** Visibility:       global
** Description:      DMA callback handler for the text printing.
** Invocation:       Invoked by DMA Callback ISR
**                   function
** Inputs/Outputs:   DMA Channel.
** Critical Section: None.
** Created:          11-Jul-2013 by EMANOJ1
** Updated:          11-Jul-2013 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_mgr02_font_fsl_edma_cb(dma_handler_app_resp_struct * p_app_resp_S)
{
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
  /* During text clipping only the first character should be clipped with */
  /* l_text_y_offset.  For the other characters its not applicatble.      */
  l_text_y_offset = 0;
#endif
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
  l_text_char_printed = (UINT8)TRUE;
#else
  (void)hmi_gfx_mgr02_font_fsl_edma_sm(GFX_MGR02_DMA_CHANNEL, TRUE);
#endif
  GFX_MGR02_UNUSED_PTR(p_app_resp_S);
}

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_dual_transfer_edma_cb
** Visibility:       global
** Description:      DMA callback handler for the text printing. When horizontal 
**                   scroll is enabled double edma transfer is required. 
** Invocation:       Invoked by Graphics_TransformationCallback
**                   function
** Inputs/Outputs:   DMA Channel.
** Critical Section: None.
** Created:          16-Jan-2015 by ADEVI
** Updated:          16-Jan-2015 by ADEVI
**==========================================================================*/
static void hmi_gfx_mgr02_font_dual_transfer_edma_cb(void)
{
  /* Same callback is configured for Graphics_Subcopy and Graphics_Paste */
  /* callStatus used to distinguish the caller function                  */
  static BOOLEAN callStatus = CALLBCK_FRM_GRAPHICS_SUBCOPY;
  /* l_text_horizontal_offset is applicable only for the first character that is getting */
  /* rendered.  So when call back is invoked after rendering the first character the     */
  /* l_text_horizontal_offset is reset to 0.                                             */
  l_text_horizontal_offset = 0;

  switch(callStatus)
  {
  case CALLBCK_FRM_GRAPHICS_SUBCOPY:
    (void)Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
      &l_text_source_go,
      &l_text_target_go,
      (UINT16)0,
      (UINT16)0,
      &hmi_gfx_mgr02_font_dual_transfer_edma_cb);
    callStatus = CALLBCK_FRM_GRAPHICS_PASTE;
    break;
  case CALLBCK_FRM_GRAPHICS_PASTE:
    callStatus = CALLBCK_FRM_GRAPHICS_SUBCOPY;
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
    l_text_char_printed = TRUE;
#else
    /* Invoked to render the remaining characters */
    (void)hmi_gfx_mgr02_font_fsl_edma_sm(GFX_MGR02_DMA_CHANNEL, TRUE);
#endif
    break;
  default:
    callStatus = CALLBCK_FRM_GRAPHICS_SUBCOPY;
    break;
  }
}
#endif


/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_fsl_edma_sm
** Visibility:       global
** Description:      Performs the Font print using DMA one character at a time.
** Invocation:       Invoked by hmi_gfx_mgr02_font_kepler_dma_print, DMA Callback
**                   function
** Inputs/Outputs:   DMA Channel. p_dma_cb - indicates whether the invokation
**                   is by a print routine to begin operation (FALSE) or from a
**                   DMA call back ISR which is then is to initate the next letter
**                   in the string (TRUE)
** Critical Section: None.
** Created:          05-Feb-2013 by ASHEKHAR
** Updated:          11-Jul-2013 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_font_fsl_edma_sm(UINT8 p_eDMAChannel, UINT32 p_dma_cb)
{
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
  SINT16            f1_scroll_end_offset = 0;
  UINT16            fl_copy_width = 0;
  UINT16            fl_temp_width = 0;
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
  Graphics_Object_t  fl_source;
  Graphics_Object_t  fl_target;
#endif
  dma_handler_type   fl_dma_parameters;
  UINT32             fl_error = (UINT32)(~DMA_NO_ERROR);
  HMI_CHAR           currentChar;
  SINT32             fl_char_y_offset;
  SINT32             fl_char_height;
  SINT32             fl_tot_height;
  SINT32             fl_dest_y_offset;
  SINT32             fl_dest_x_offset;
  SINT32             fl_start_x_offset;
  UINT32             fl_orig_width;
  GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;

  l_fsl_text_task_state = GFX_MGR02_FONT_LOAD;

  while((l_fsl_text_task_state == GFX_MGR02_FONT_LOAD) && (l_string_length > 0))
  {
    do
    {
#if (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1)
      currentChar    = l_edma_string[l_string_length - 1];
#else
      currentChar    = l_edma_string[0];
      l_edma_string  = &l_edma_string[1];
#endif
      l_string_length--;
      fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(currentChar, l_font_lut_SP, l_font_SP->size_table, 
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
        l_font_id,
#endif
        l_font_SP->is_vfont);

#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      /* Odd values of l_text_y_offset cannot be scrolled for 4BPP font rendering */ 
      if(((l_text_y_offset & 0x01) && (l_devider == 2)) != 0)
      {
        /* If the l_text_y_offset is odd, make it even */
        l_text_y_offset--;
      }
#endif

      /* When scroll is enabled then based on the scroll offset(l_text_y_offset) the characters need */
      /* to be removed from the beginning.                                                           */
      while(fl_font_fcc_SP != GFX_MGR02_NULL_PTR) 
      {
        fl_temp_width =  fl_font_fcc_SP->owidth;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        /* Odd values of fl_copy_width cannot be scrolled for 4BPP font rendering */ 
        if(((fl_temp_width & 0x01) && (l_devider == 2)) != 0)
        {
          /* If the width is odd, make it even */
          fl_temp_width++;
        }
#endif

        if(l_text_y_offset >= fl_temp_width)
        {
          if(l_string_length > 0)
          {
            l_text_y_offset = l_text_y_offset - fl_temp_width;
#if (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1)
            currentChar    = l_edma_string[l_string_length - 1];
#else
            currentChar    = l_edma_string[0];
            l_edma_string  = &l_edma_string[1];
#endif
            l_string_length--;
            fl_font_fcc_SP  = hmi_gfx_mgr02_get_fcc(currentChar, l_font_lut_SP, l_font_SP->size_table, 
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
              l_font_id,
#endif
              l_font_SP->is_vfont);
          }
          else
          {
            /* when there are no more characters to be displayed and if the scroll offset  */
            /* is still greater than the last character's width then set the scroll offset */
            /* as 0 and the font pointer to NULL so that text will not be displayed.       */
            l_text_y_offset = 0;
            fl_font_fcc_SP = GFX_MGR02_NULL_PTR;
          }
        }
        else
        {
          break;
        }
      }

      if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR) 
      {
        /* when the width of the characters to be displayed during scroll exceed the */
        /* text box width then the f1_scroll_end_offset is calculated and no more    */
        /* characters will be displayed by setting the l_string_length to 0          */
        fl_copy_width = (UINT16)(fl_font_fcc_SP->owidth - l_text_y_offset);
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        /* Odd values of fl_copy_width cannot be scrolled for 4BPP font rendering */ 
        if(((fl_copy_width & 0x01) && (l_devider == 2)) != 0)
        {
          /* If the width is odd, make it even */
          fl_copy_width++;
        }
#endif
        l_displayed_width += (UINT16)(fl_copy_width);
        if(l_displayed_width >= l_max_available_width)
        {
          l_string_length      = 0;
          f1_scroll_end_offset = l_displayed_width - l_max_available_width;
        }
      }
#endif
    }
    while((fl_font_fcc_SP == GFX_MGR02_NULL_PTR) && (l_string_length > 0));

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    /* The l_text_y_offset found after applying the scroll offset from the start of the text       */
    /* is the l_text_horizontal_offset to be applied when GFX_MGR02_HORIZONTAL_SCROLL_ENABLED is 1 */
    l_text_horizontal_offset = l_text_y_offset;
    l_text_y_offset          = 0;
#endif

    if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
    {
      if(fl_font_fcc_SP->fdata == GFX_MGR02_NULL_PTR)
      {
        UINT8 fl_width = fl_font_fcc_SP->owidth;

        if(((fl_width & 0x01) != 0) && (l_devider == 2))
        {
          fl_width++; 
        }
        /* we can just skip this character as there is no data */
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
        l_dest_address += (l_dest_width * (fl_font_fcc_SP->owidth - l_text_y_offset));
        l_text_y_offset = 0;
#elif(defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED))
        l_dest_address          += ((fl_width - l_text_horizontal_offset)/l_devider);
        l_text_horizontal_offset = 0;
#else
        l_dest_address += (fl_width/l_devider);
#endif
      }
      else
      {
        #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
          fl_dest_y_offset = (fl_font_fcc_SP->x_soffset-l_text_y_offset);
        #else
          fl_dest_y_offset = (fl_font_fcc_SP->y_soffset-l_text_y_offset);
        #endif
        fl_char_height   = fl_font_fcc_SP->height;

        if(fl_dest_y_offset < 0)
        {
       #if GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0
          fl_char_height  += fl_dest_y_offset;
       #else
            fl_char_height  += fl_font_fcc_SP->y_soffset;
       #endif
          /* When rotation is enabled then fl_char_height will remain the same */
          /* during text clipping, only the character width will be modified   */
          fl_tot_height    = fl_char_height;
          fl_char_y_offset = -fl_dest_y_offset;
        }
        else
        {
        #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
          fl_tot_height    = (fl_font_fcc_SP->y_soffset+fl_char_height);
        #else
          fl_tot_height    = (fl_dest_y_offset+fl_char_height);
        #endif
          fl_char_y_offset = 0;
        }

        if(fl_tot_height > 0)
        {
          if(fl_tot_height > l_text_height)
          {
            fl_tot_height  -= l_text_height;
            fl_char_height -= fl_tot_height;
          }
        }

        if(fl_char_height <= 0)
        {
          /* we can just skip this character as there is no data */
          if(l_devider == 2)
          {
            fl_orig_width = fl_font_fcc_SP->owidth;
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
            l_dest_address += (l_dest_width * fl_orig_width);
#else
            if((fl_orig_width & 0x01) != 0)
            {
              /* If the width is odd, make it even */
              fl_orig_width++;
            }
            l_dest_address += (fl_orig_width >> 1);
#endif
            l_cur_x_offset += fl_orig_width;
          }
          else
          {
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
            l_dest_address += (fl_font_fcc_SP->owidth * l_dest_width);
#else
            l_dest_address += fl_font_fcc_SP->owidth;
#endif
            l_cur_x_offset += fl_font_fcc_SP->owidth;
          }
        }
        else
        {
          /* we need to print */
          fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32    = l_dest_address;
          fl_dma_parameters.dma_drv_channel_parameters.source_number_U16          = (DMA_SR_ALWAYS_ENB_0+GFX_MGR02_DMA_CHANNEL);
          fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E      = DMA_MUX_ALWAYS_ENB_REQUEST;
          fl_dma_parameters.dma_drv_channel_parameters.source_size_E              = SIZE_1BYTE;
          fl_dma_parameters.dma_drv_channel_parameters.destination_size_E         = SIZE_1BYTE;
          fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16          = 1;
          fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16     = 1;
          fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8   = 0;
          fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8  = 1;
          fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32 = 0;
          fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32   = 0;
          fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8          = GFX_MGR02_EDMA_BWC_NORMAL_RENDERING;
          fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8      = 1;
          fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8   = 1;
          fl_dma_parameters.dma_channel_num                                       = (dma_channel_num_type)GFX_MGR02_DMA_CHANNEL;
          fl_dma_parameters.dma_callback                                          = hmi_gfx_mgr02_font_fsl_edma_cb;
          fl_start_x_offset = fl_font_fcc_SP->x_soffset;
          fl_orig_width     = fl_font_fcc_SP->owidth;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          fl_orig_width = fl_orig_width - l_text_horizontal_offset;
#endif

          if(l_devider == 2)
          {
#if GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0
            if((fl_start_x_offset & 0x01) != 0)
            {
              /* If the xoffset is odd, make it even */
              fl_start_x_offset++;
            }
            if((fl_orig_width & 0x01) != 0)
            {
              /* If the width is odd, make it even */
              fl_orig_width++;
            }
#endif               
            fl_dest_x_offset  = fl_start_x_offset;
            fl_dest_x_offset += l_cur_x_offset;
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32 = ((fl_font_fcc_SP->height+1) >> 1);
#else
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32 = ((fl_font_fcc_SP->width+1) >> 1);
#endif
            /*
            ** fl_font_fcc_SP->x_soffset can have nagative values, make sure
            ** we take negative values only if we donot overflow the lower address
            ** boundary due to the resulting subtraction
            */
            if(fl_dest_x_offset >= 0)
            {
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)) 
              fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 += (fl_start_x_offset * l_dest_width);
#else
              fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 += (fl_start_x_offset / 2);
#endif
            }
            else
            {
              if(fl_start_x_offset < 0)
              {
                fl_start_x_offset = -fl_start_x_offset;
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)) 
                l_dest_address += (fl_start_x_offset * l_dest_width);
#else
                l_dest_address   += (fl_start_x_offset >> 1);
#endif
              }
            }
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
            /* When text clipping is enabled then l_text_y_offset need to be subtracted from */
            /* original width.  Because that would be the actual data visible                */
            l_dest_address   += ((fl_orig_width - l_text_y_offset) * l_dest_width);
#else
            l_dest_address += (fl_orig_width >> 1);
#endif
          }
          else
          {
            fl_dest_x_offset          = fl_start_x_offset;
            fl_dest_x_offset         += l_cur_x_offset;
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32 = fl_font_fcc_SP->width;
            if(fl_dest_x_offset >= 0)
            {
              fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 += fl_font_fcc_SP->x_soffset;
              l_dest_address                += fl_orig_width;
            }
            else
            {
              l_dest_address += (-fl_font_fcc_SP->x_soffset);
              l_dest_address += fl_orig_width;
            }
          }

          l_cur_x_offset += fl_orig_width;

  #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
          {
            SINT32 fl_offset_height  = l_text_height - (fl_font_fcc_SP->y_soffset+fl_font_fcc_SP->height); 
  
            if(fl_offset_height & 0x1)
            {
              fl_offset_height++;
            }
            fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 += (fl_offset_height >> 1);
          }
  #else
          if(fl_dest_y_offset > 0)
          {
            fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 += (fl_dest_y_offset*l_dest_width);
          }
  #endif

          fl_dma_parameters.dma_drv_channel_parameters.source_address_U32 = (UINT32)(fl_font_fcc_SP->fdata);
          if(fl_char_y_offset > 0)
          {
            fl_dma_parameters.dma_drv_channel_parameters.source_address_U32 += (fl_char_y_offset * fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32);
          }

          fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32 = (l_dest_width - fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32);
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1))
          /* When text clipping is enabled then l_text_y_offset need to be subtracted from */
          /* original width.  Because that would be the actual data visible                */
          fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16  = (UINT16)(fl_font_fcc_SP->width - (l_text_y_offset + f1_scroll_end_offset));
#else
          fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16  = (UINT16)fl_char_height;
#endif

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          if((l_text_horizontal_offset > 0) || (f1_scroll_end_offset > 0))
            /*  Double eDMA transfer to be done */
          {            
            fl_source.address = (UINT32)(fl_font_fcc_SP->fdata);
            /* To convert GFX_MGR02_FONT_ENCODING_4BPP to GRAPHICS_4BPP */
            /* and GFX_MGR02_FONT_ENCODING_8BPP to GRAPHICS_8BPP        */
            fl_source.BPP     = (GFX_MGR02_GET_BPP(l_font_lut_SP->attributes)) >> 2;
            fl_source.height  = fl_font_fcc_SP->height;
            fl_source.width   = fl_font_fcc_SP->owidth;
            /* Odd values of fl_source.width cannot be scrolled for 4BPP font rendering */ 
            if(((fl_source.width & 0x01) && (l_devider == 2)) != 0)
            {
              /* If the width is odd, make it even */
              fl_source.width++;
            }
            fl_source.x       = 0;
            fl_source.y       = 0;

            fl_copy_width     = fl_copy_width - f1_scroll_end_offset;
            fl_target.height  = fl_source.height;
            fl_target.width   = fl_copy_width;
            fl_target.x       = 0;
            fl_target.y       = 0;
            fl_target.BPP     = fl_source.BPP;
            fl_target.address = hmi_gfx_mgr02_get_size_for_bpp(fl_target.BPP, (fl_target.width*fl_target.height), FALSE);
            fl_target.address = hmi_gfx_mgr02_get_workbuffer(fl_target.address);

            /* Second edma transfer from buffer to actual destination           */
            /* Load the current buffer data as the source of next edma transfer */

            l_text_source_go.address = fl_target.address;
            l_text_source_go.BPP     = fl_target.BPP;
            l_text_source_go.height  = fl_target.height;
            l_text_source_go.width   = fl_target.width;
            l_text_source_go.x       = fl_target.x;
            l_text_source_go.y       = fl_target.y;

            l_text_target_go.address = fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32;
            l_text_target_go.BPP     = fl_target.BPP;
            l_text_target_go.height  = (UINT16)fl_char_height;
            /* l_dest_width is divided by divider in fsl_print function so its remultiplied by the divider */ 
            l_text_target_go.width   = (UINT16)(l_dest_width * l_devider);
            l_text_target_go.x       = fl_target.x;
            l_text_target_go.y       = fl_target.y; 


            /* First edma transfer from source to buffer  */
            l_fsl_text_task_state = GFX_MGR02_FONT_PRINT;
            /* l_text_horizontal_offset denotes the number of pixels that are to be left from the   */
            /* start of the character. f1_scroll_end_offset denotes the number of pixels to be left */
            /* at the end of the character. Eg - l_text_horizontal_offset = 2 => start coying from  */
            /* third pixel. f1_scroll_end_offset = 2 => leave the last two pixels of the character. */
            fl_error = Graphics_SubCopy(GFX_MGR02_DMA_CHANNEL,
              &fl_source,
              &fl_target,
              (UINT16)l_text_horizontal_offset,
              (UINT16)0,
              (UINT16)(fl_source.width - f1_scroll_end_offset),
              (UINT16)fl_char_height,
              &hmi_gfx_mgr02_font_dual_transfer_edma_cb);
            if(fl_error != GRAPHICS_ERROR_OK)
            {
              l_fsl_text_task_state = GFX_MGR02_FONT_IDLE;
            }
            else
            {
            }
          }
          else
#endif
          {
            if((fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32 != 0) &&
              (fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16 != 0))
            {
              l_fsl_text_task_state = GFX_MGR02_FONT_PRINT;


              //if(l_gfx_mgr02_data_S.)
            /*  if(l_gfx_mgr02_data_S->
              l_cur_gram_alloc_table*/
              fl_error = DMA_Handler_InitiateRequest(&fl_dma_parameters);
              if(fl_error != DMA_NO_ERROR)
              {
                l_fsl_text_task_state = GFX_MGR02_FONT_IDLE;
              }
            }
          }
        }
      }
    }
  }
#if !defined(GFX_MGR02_DMA_CPU_RENDER)
  if(l_fsl_text_task_state != GFX_MGR02_FONT_PRINT)
  {
    l_fsl_text_task_state = GFX_MGR02_FONT_IDLE;
    if(hmi_gfx_mgr02_font_callback != GFX_MGR02_NULL_PTR)
    {
      hmi_gfx_mgr02_font_callback_type fl_callback = hmi_gfx_mgr02_font_callback;
      hmi_gfx_mgr02_font_callback = GFX_MGR02_NULL_PTR;
      if(p_dma_cb != FALSE)
      {
        /*
        ** Invoke the call back only if  called from a DMA callback ISR
        ** i.e. if the DMA is not triggered at all from the call
        ** hmi_gfx_mgr02_font_fsl_edma_print(), then we need not issue a
        ** callback to application at all, instead this can be a return
        ** status to application.
        */
        fl_callback();
      }
    }
  }
#else
  GFX_MGR02_UNUSED_VAR(p_dma_cb);
#endif
  GFX_MGR02_UNUSED_VAR(p_eDMAChannel);
  return(fl_error);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_fsl_edma_print
** Visibility:       global
** Description:      Performs the Font Print using DMA transfer.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   String, String Width, Font, Font Encoding, Font Engine Type.
** Critical Section: Width of the String.
** Created:          24-May-2013 by EMANOJ1
** Updated:          24-May-2013 by EMANOJ1
**==========================================================================*/
GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_font_fsl_edma_print(GFX_MGR02_TEXT_INFO  const        * p_text_context,
  hmi_gfx_mgr02_font_callback_type  p_callback,
  UINT32                            p_dest_address,
  UINT32                            p_dest_width,
  UINT32                            p_text_y_sclip,
  UINT32                            p_text_height_cap)
{
  GFX_MGR02_FONT_CODE_T   fl_font_print_error;
  GFX_MGR02_FONT  const * fl_font_SP;
  UINT8                   fl_text_BPP;
  GFX_MGR02_CONTEXT_T   * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
  HMI_CHAR           currentChar;
#endif

  fl_font_SP          = hmi_gfx_mgr02_get_font_pointer(fl_context_SP->rprop.font_id);
  fl_font_print_error = GFX_MGR02_FONT_ERROR_FAIL;

  if((fl_font_SP                      != GFX_MGR02_NULL_PTR) &&
    (p_text_context->print_str_P     != GFX_MGR02_NULL_PTR) &&
    (p_text_context->print_length_U8 != 0))
  {
    fl_text_BPP = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);

    if((fl_text_BPP == GFX_MGR02_FONT_ENCODING_4BPP) || (fl_text_BPP == GFX_MGR02_FONT_ENCODING_8BPP))
    {
      /* with eDMA only 4bpp and 8bpp fonts are supported */
      if(l_fsl_text_task_state == GFX_MGR02_FONT_IDLE)
      {
        if(p_text_height_cap == 0)
        {
          p_text_height_cap = fl_font_SP->p.height;
        }
        l_font_SP                       = fl_font_SP;
        l_font_lut_SP                   = l_font_SP->f.lut_ptr;
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
        l_font_id                       = fl_context_SP->rprop.font_id;
#endif
        l_edma_string                   = p_text_context->print_str_P;
        l_string_length                 = p_text_context->print_length_U8;
        hmi_gfx_mgr02_font_callback     = p_callback;
        l_dest_address                  = p_dest_address;

#if (((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED))))
        l_max_available_width           = p_text_context->max_available_width;
        l_displayed_width               = 0;
#endif

        if(fl_text_BPP == GFX_MGR02_FONT_ENCODING_4BPP)
        {
          l_devider = 2;
        }
        else
        {
          l_devider = 1;
        }

#if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
        if(p_text_context->db_format == GFX_MGR02_16BPP_ARGB4444)
        {
          /* for multi color widgets the destination buffer is 16bit ARGB4444 */
          l_dest_width    = (p_dest_width << 1);
          l_dest_address += ((p_text_context->coord.x << 1) + (p_text_context->coord.y * l_dest_width));
        }
        else
#endif
          if(fl_text_BPP == GFX_MGR02_FONT_ENCODING_4BPP)
          {
            l_dest_width    = (p_dest_width>>1);
            l_dest_address += ((p_text_context->coord.x>>1) + (p_text_context->coord.y * l_dest_width));
          }
          else
          {
            l_dest_width    = p_dest_width;
            l_dest_address += ((p_text_context->coord.x) + (p_text_context->coord.y * l_dest_width));
          }
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED))) 
          l_displayed_width = p_text_context->print_sindex_U8;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          /* Odd values of l_displayed_width cannot be scrolled for 4BPP font rendering */ 
          if(((l_displayed_width & 0x01) && (l_devider == 2)) != 0)
          {
            /* If the l_displayed_width is odd, make it even */
            l_displayed_width--;
          }
#endif
#endif

          l_text_y_offset       = (SINT32)p_text_y_sclip;
          l_text_height         = (UINT8)p_text_height_cap;
          l_cur_x_offset        = 0;
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
          l_text_char_printed = FALSE;
          while(l_string_length > 0)
          {
            GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
            currentChar    = l_edma_string[0];
            l_edma_string  = &l_edma_string[1];
            l_string_length--;
            fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(currentChar, l_font_lut_SP, l_font_SP->size_table, 
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
              l_font_id,
#endif
              l_font_SP->is_vfont);
            if((fl_font_fcc_SP->x_soffset < 0) && ((SINT16)(l_cur_x_offset+fl_font_fcc_SP->x_soffset) > 0))
            {
              hmi_gfx_mgr02_font_char_cpu_print(fl_font_fcc_SP
#if defined(GFX_MGR02_CPU_ARABIC_JOINING_PATCH)
                ,currentChar
#endif
                );
              fl_font_print_error = GFX_MGR02_FONT_WRITE_ACTIVE;
            }
            else
            {
              UINT32 fl_dma_init_status;
              l_edma_string  = &l_edma_string[-1];
              l_string_length++;
              fl_dma_init_status = hmi_gfx_mgr02_font_fsl_edma_sm(GFX_MGR02_DMA_CHANNEL, FALSE); 
              if(fl_dma_init_status == DMA_NO_ERROR)
              {
                fl_font_print_error = GFX_MGR02_FONT_WRITE_ACTIVE;
                while(l_text_char_printed == FALSE)
#if defined(WIN32)
                {
                  MSG  msg;                           
                  if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
                  {                                
                    TranslateMessage(&msg);       
                    DispatchMessage(&msg);        
                  }
                }
#else
                  ;
#endif
                l_text_char_printed = FALSE;
              }
              else
              {
                l_fsl_text_task_state = GFX_MGR02_FONT_IDLE;
              }
            }
          }
          if(fl_font_print_error != GFX_MGR02_FONT_ERROR_FAIL)
          {
            l_fsl_text_task_state = GFX_MGR02_FONT_IDLE;
            if(hmi_gfx_mgr02_font_callback != GFX_MGR02_NULL_PTR)
            {
              hmi_gfx_mgr02_font_callback_type fl_callback = hmi_gfx_mgr02_font_callback;
              hmi_gfx_mgr02_font_callback = GFX_MGR02_NULL_PTR;
              {
                fl_callback();
              }
            }
          }
#else /* end - defined((GFX_MGR02_DMA_CPU_RENDER == 1) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)) */ 
          if(hmi_gfx_mgr02_font_fsl_edma_sm(GFX_MGR02_DMA_CHANNEL, FALSE) == DMA_NO_ERROR)
          {
            /*
            ** Return a success status only if DMA is started.
            */
            fl_font_print_error = GFX_MGR02_FONT_WRITE_ACTIVE;
          }
#endif
      }
    }
  }
  return (fl_font_print_error);
}
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_font_char_cpu_print
** Visibility:       global
** Description:      Performs the Font Print using CPU.
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   String length, Font fcc ptr.
** Critical Section: None.
** Created:          4-Nov-2015 by SBOLLAM
**==========================================================================*/
void hmi_gfx_mgr02_font_char_cpu_print(GFX_MGR02_FONT_CHAR_CONFIG const *p_font_fcc_SP
#if defined(GFX_MGR02_CPU_ARABIC_JOINING_PATCH)
  , HMI_CHAR p_char
#endif
  )
{
  SINT32             fl_char_y_offset;
  SINT32             fl_char_height;
  SINT32             fl_tot_height;
  SINT32             fl_dest_y_offset;
  SINT32             fl_start_x_offset;
  UINT32             fl_orig_width;
  UINT8            * fl_dest_address = (UINT8*)l_dest_address;
  UINT8            * fl_src_address  = (UINT8*)(p_font_fcc_SP->fdata);
  SINT32             fl_sy;
  SINT32             fl_sx;
  SINT8              fl_neg_pix_cnt;
  UINT8              fl_prev_src_byte_hnibble;
  UINT8              fl_src_byte;
  UINT8              fl_src_lnibble;
  UINT8              fl_dest_byte;
  UINT32             fl_is_arabic = FALSE;

  l_fsl_text_task_state = GFX_MGR02_FONT_LOAD;
  fl_dest_y_offset = (p_font_fcc_SP->y_soffset-l_text_y_offset);
  fl_char_height   = p_font_fcc_SP->height;

  if(fl_dest_y_offset < 0)
  {
    fl_char_height  += fl_dest_y_offset;
    fl_tot_height    = fl_char_height;
    fl_char_y_offset = -fl_dest_y_offset;
  }
  else
  {
    fl_tot_height    = (fl_dest_y_offset+fl_char_height);
    fl_char_y_offset = 0;
  }
  if(fl_char_height <= 0)
  {
    /* we can just skip this character as there is no data */
    if(l_devider == 2)
    {
      fl_orig_width = p_font_fcc_SP->owidth;
      if((fl_orig_width & 0x01) != 0)
      {
        /* If the width is odd, make it even */
        fl_orig_width++;
      }
      l_dest_address += (fl_orig_width >> 1);
      l_cur_x_offset += fl_orig_width;
    }
    else
    {
      l_dest_address += p_font_fcc_SP->owidth;
      l_cur_x_offset += p_font_fcc_SP->owidth;
    }
    p_font_fcc_SP  = GFX_MGR02_NULL_PTR;
  }
  else
  {
    UINT16 fl_minor_loop_cnt;
    UINT16   fl_copy_width = 0;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    UINT16  fl_raw_width;
#endif

    if(fl_tot_height > 0)
    {
      if(fl_tot_height > l_text_height)
      {
        fl_tot_height  -= l_text_height;
        fl_char_height -= fl_tot_height;
      }
    }
    fl_start_x_offset = p_font_fcc_SP->x_soffset;
    fl_orig_width     = p_font_fcc_SP->owidth;
    fl_copy_width = p_font_fcc_SP->width;
    if(l_devider == 2)
    {
      if((p_font_fcc_SP->x_soffset & 0x01) != 0)
      {
        /* If the x start offset is odd, make it even */
        fl_start_x_offset--;
#if defined(GFX_MGR02_CPU_ARABIC_JOINING_PATCH)
        fl_is_arabic = CheckArabicCharRange(p_char);
        if(fl_is_arabic == TRUE)
        {
          /* 
          when address is odd, then make it even to see joining effect clearly in Arabic
          since moving 1 extra pixel and blending with the previous 2 pixels,
          decrement "fl_orig_width" by 1 pixel.
          */
          fl_orig_width--;
        }
#endif
      }
      if((fl_orig_width & 0x01) != 0)
      {
        /* If the width is odd, make it even */
        fl_orig_width++;
      }
      if((fl_copy_width & 0x01) != 0)
      {
        fl_copy_width++;
      }
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      l_displayed_width += (UINT16)(fl_orig_width);
      if(l_displayed_width >= l_max_available_width)
      {
        fl_copy_width -= (l_displayed_width - l_max_available_width);
        l_string_length = 0;
      } 
      if((fl_copy_width & 0x01) != 0)
      {
        /* If the width is odd, make it even */
        fl_copy_width++;
      }
      fl_raw_width = ((p_font_fcc_SP->width+1)>>1);
#endif             
      l_dest_address += (fl_orig_width >> 1);
      fl_minor_loop_cnt = (fl_copy_width >> 1);
    }
    else
    {
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      fl_copy_width = p_font_fcc_SP->width;
      l_displayed_width += (UINT16)(fl_orig_width);
      if(l_displayed_width >= l_max_available_width)
      {
        fl_copy_width -= (l_displayed_width - l_max_available_width);
        l_string_length = 0;
      } 
      fl_raw_width = p_font_fcc_SP->width;
#endif
      l_dest_address += fl_orig_width;
      fl_minor_loop_cnt = (UINT16)fl_copy_width;
    }
    l_cur_x_offset += fl_orig_width;
    if(fl_dest_y_offset > 0)
    {
      fl_dest_address = (UINT8*)&fl_dest_address[(fl_dest_y_offset*l_dest_width)];
    }
    fl_dest_address = (UINT8*)&fl_dest_address[(fl_start_x_offset/l_devider)];
    if(fl_char_y_offset > 0)
    {
      fl_src_address = (UINT8*)&fl_src_address[fl_char_y_offset * fl_minor_loop_cnt];
    }
    if((fl_is_arabic == FALSE)  && ((p_font_fcc_SP->x_soffset & 0x01) != 0))
    {
      fl_neg_pix_cnt = p_font_fcc_SP->x_soffset;
    }
    else
    {
      fl_neg_pix_cnt = fl_start_x_offset;
    }
    fl_prev_src_byte_hnibble = 0;
    for(fl_sy=fl_char_y_offset; fl_sy<fl_char_height; fl_sy++)
    {
      for(fl_sx=0; fl_sx<fl_minor_loop_cnt; fl_sx++)
      {
        fl_src_byte = *fl_src_address;
        fl_src_address +=1 ;
        /* This process requires only when address is odd and 4bpp AA */
        if((l_devider == 2) && (fl_is_arabic == FALSE) && ((p_font_fcc_SP->x_soffset & 0x01) != 0))
        {
          /*
          Blending logic: suppose prev char last byte is 0x0D
          this means, in a row of pixels "D' is the first pixel
          and "0" is the next pixel, but the byte will be 0x0D.
          Hence blend should be look like below:

          prev-char	next-char
          byte		  bytes
          ---------	 ---------
          B   | |   D   
          0x05  | | 0xAB, 0xCD  
          | |         
          ---------	 ---------
          once blend with prev-char last byte is completed,
          then the byte 0xAB is becomes as --> 0x0A
          now blend with next byte lower nibble as
          0xDA
          */
          fl_src_lnibble = fl_src_byte & 0xF;
          fl_src_lnibble = ((fl_src_lnibble << 4) & (0xF0)) | fl_prev_src_byte_hnibble;  
          fl_prev_src_byte_hnibble = (fl_src_byte >> 4) & 0xF;
          fl_src_byte = fl_src_lnibble;
        }
        if(fl_neg_pix_cnt < 0)
        {
          fl_dest_byte = *fl_dest_address;
          if((fl_dest_byte == 0) && (fl_src_byte != 0) && \
            (l_devider == 2) && (fl_is_arabic == FALSE) && ((p_font_fcc_SP->x_soffset & 0x01) != 0))
          {
            fl_src_byte |= (fl_src_byte >> 4); 
          }
          fl_dest_byte = fl_dest_byte | fl_src_byte;
          *fl_dest_address  = fl_dest_byte;
          fl_dest_address += 1;
          if(((fl_is_arabic == FALSE) && ((p_font_fcc_SP->x_soffset & 0x01) != 0)) || (l_devider == 1)) 
          {
            fl_neg_pix_cnt++;
          }
          else
          {
            fl_neg_pix_cnt +=2;
          }
        }
        else
        {
          *fl_dest_address = fl_src_byte;
          fl_dest_address += 1;

        }
      }
      /* This process requires only when address is odd and 4bpp AA */
      if((l_devider == 2) && (fl_is_arabic == FALSE) && ((p_font_fcc_SP->x_soffset & 0x01) != 0)) 
      {
        /* Here we may miss last byte higher nibble to print on GRAM, hence print this as well
        ** because o_width actually a odd width for -ve x-soffset characters
        */
        fl_prev_src_byte_hnibble &= 0xF;
        fl_src_byte = fl_prev_src_byte_hnibble;
        *fl_dest_address = fl_src_byte;
      }
      fl_prev_src_byte_hnibble = 0;
      if((fl_is_arabic == FALSE) && ((p_font_fcc_SP->x_soffset & 0x01) != 0))
      {
        fl_neg_pix_cnt = p_font_fcc_SP->x_soffset;
      }
      else
      {
        fl_neg_pix_cnt = fl_start_x_offset;
      }
      fl_dest_address = (fl_dest_address + (l_dest_width - fl_minor_loop_cnt));
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      /* fl_minor_loop_cnt can be less than the width only when scroll support is enabled */
      if(fl_minor_loop_cnt < fl_raw_width)
      {
        fl_src_address += (fl_raw_width - fl_minor_loop_cnt); 
      }
#endif
    }
  }
}
#endif
/* end - defined((GFX_MGR02_DMA_CPU_RENDER == 1) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)) */
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
UINT32 CheckArabicCharRange(HMI_CHAR p_char)
{
  UINT32 fl_ret_status;
  if((p_char  >=  1536  && p_char <=  1791)   || \
    (p_char  >=  64336 && p_char <=  65023)  || \
    (p_char  >=  65136 && p_char <=  65279))
  {
    fl_ret_status = TRUE;
  }
  else
  {
    fl_ret_status = FALSE;
  }
  return fl_ret_status;
}
#endif
#ifndef WIN32
#pragma pop
#endif
#endif /* #if defined(GFX_MGR02_KEPLER) */

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_mark_anch_points
** Visibility:       global
** Description:      Gives the anchor points of a given mark(unicode)
**                   which are used for GPOS calculations
** Invocation:       Invoked by hmi_gfx_mgr02_get_gpos_delta_pixels
** Inputs/Outputs:   unicode and font id, mark gpsos table ptr.
** Critical Section: None.
** Created:          15-Sep-2016 by SBOLLAM
**==========================================================================*/
GFX_MGR02_GPOS_MARK_TABLE const* hmi_gfx_mgr02_get_mark_anch_points(HMI_CHAR p_char,
  GFX_MGR02_GPOS_MARK_TABLE const *p_gpos_mark_ptr, HMI_CHAR  p_mark_table_size)
{
  GFX_MGR02_GPOS_MARK_TABLE const * fl_return = GFX_MGR02_NULL_PTR;
  if(p_mark_table_size > 0U)
  {
    HMI_CHAR              fl_mark_table_size = p_mark_table_size;
    GFX_MGR02_GPOS_MARK_TABLE const *fl_gpos_mark_ptr = p_gpos_mark_ptr;
    HMI_CHAR fl_first = 0; 
    HMI_CHAR fl_last  = fl_mark_table_size-1U;
    HMI_CHAR fl_middle= (fl_first+fl_last)/2U;

    while ((fl_first <= fl_last) && (fl_middle < p_mark_table_size))
    {
      if (fl_gpos_mark_ptr[fl_middle].unicode < p_char)
      {
        fl_first = fl_middle + 1U;
      }
      else if (fl_gpos_mark_ptr[fl_middle].unicode == p_char) 
      {
        fl_return = &fl_gpos_mark_ptr[fl_middle];
        break;
      }
      else
      {
        fl_last = fl_middle - 1U;
      }
      fl_middle = (fl_first + fl_last)/2U;
    }
  }
  /*if (fl_first > fl_last)
  printf("Not found! %d Unicode is not present in the Table.\n", p_char);*/
  return fl_return;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_base_anch_points
** Visibility:       global
** Description:      Gives the anchor points of a given base(unicode)
**                   which are used for GPOS calculations
** Invocation:       Invoked by ovg lib
** Inputs/Outputs:   unicode and font id, base gpsos table ptr.
** Critical Section: None.
** Created:          15-Sep-2016 by SBOLLAM
**==========================================================================*/
GFX_MGR02_GPOS_BASE_TABLE const* hmi_gfx_mgr02_get_base_anch_points(HMI_CHAR p_char,
  GFX_MGR02_GPOS_BASE_TABLE const *p_gpos_base_ptr, HMI_CHAR p_base_table_size)
{

  GFX_MGR02_GPOS_BASE_TABLE const * fl_return = GFX_MGR02_NULL_PTR;
  if(p_base_table_size > 0U)
  {
    HMI_CHAR              fl_base_table_size = p_base_table_size;
    GFX_MGR02_GPOS_BASE_TABLE const *fl_gpos_base_ptr = p_gpos_base_ptr;
    HMI_CHAR fl_first = 0; 
    HMI_CHAR fl_last  = fl_base_table_size-1U;
    HMI_CHAR fl_middle= (fl_first+fl_last)/2U;

    while ((fl_first <= fl_last) && (fl_middle < p_base_table_size))
    {
      if (fl_gpos_base_ptr[fl_middle].unicode < p_char)
      {
        fl_first = fl_middle + 1U;
      }
      else if (fl_gpos_base_ptr[fl_middle].unicode == p_char) 
      {
        fl_return = &fl_gpos_base_ptr[fl_middle];
        break;
      }
      else
      {
        fl_last = fl_middle - 1U;
      }
      fl_middle = (fl_first + fl_last)/2U;
    }
  }
  /*if (fl_first > fl_last)
  printf("Not found! %d Unicode is not present in the Table.\n", p_char);*/ 
  return fl_return;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_base_anch_points
** Visibility:       global
** Description:      Gives the anchor points of a given ligature(unicode)
**                   which are used for GPOS calculations
** Invocation:       Invoked by hmi_gfx_mgr02_get_gpos_delta_pixels
** Inputs/Outputs:   unicode and font id, base gpsos table ptr.
** Critical Section: None.
** Created:          24-Jul-2017 by SBOLLAM
**==========================================================================*/
GFX_MGR02_GPOS_LIGATURE_TABLE const* hmi_gfx_mgr02_get_ligature_anch_points(HMI_CHAR p_char,
  GFX_MGR02_GPOS_LIGATURE_TABLE const *p_gpos_lig_ptr, HMI_CHAR p_lig_table_size)
{
  GFX_MGR02_GPOS_LIGATURE_TABLE const * fl_return = GFX_MGR02_NULL_PTR;
  if(p_lig_table_size > 0U)
  {
    HMI_CHAR              fl_lig_table_size = p_lig_table_size;
    GFX_MGR02_GPOS_LIGATURE_TABLE const *fl_gpos_lig_ptr = p_gpos_lig_ptr;

    HMI_CHAR fl_first = 0; 
    HMI_CHAR fl_last  = fl_lig_table_size-1U;
    HMI_CHAR fl_middle= (fl_first+fl_last)/2U;
    while ((fl_first <= fl_last) && (fl_middle < p_lig_table_size))
    {
      if (fl_gpos_lig_ptr[fl_middle].unicode < p_char)
      {
        fl_first = fl_middle + 1U;
      }
      else if (fl_gpos_lig_ptr[fl_middle].unicode == p_char) 
      {
        fl_return = &fl_gpos_lig_ptr[fl_middle];
        break;
      }
      else
      {
        fl_last = fl_middle - 1U;
      }
      fl_middle = (fl_first + fl_last)/2U;
    }
  }
  /*if (fl_first > fl_last)
  printf("Not found! %d Unicode is not present in the Table.\n", p_char);*/ 
  return fl_return;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_gpos_delta_pixels
Description          : Calculates the delta position of the zero width
character w.r.t Base,Ligature and Mark
Invocation           : Internally
Parameters           : p_delta_pixels - Resultant delta values.
p_string_ptr - Input string
p_font_id - font used for text build
Return Value         : p_delta_pixels - output
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT8 hmi_gfx_mgr02_get_gpos_delta_pixels(GFX_MGR02_GPOS_DELTA * p_delta_pixels, 
                                            HMI_CHAR const* p_string_ptr,
                                            SINT32 p_str_index,
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
                                            UINT32 p_font_id,
#else
                                            GFX_MGR02_FONT const * p_font_SP,
#endif
                                            GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
                                            GFX_MGR02_LANG_READ_DIR p_lang_read_dir)
{
  GFX_MGR02_GPOS_TABLE          const *fl_gpos_table_ptr  = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_MARK_TABLE     const *fl_mark_MtoB_ptr   = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_BASE_TABLE     const *fl_base_gpos_ptr   = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_MARK_TABLE     const *fl_mark_MtoL_ptr   = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_LIGATURE_TABLE const *fl_lig_gpos_ptr    = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_MARK_TABLE     const *fl_mark1_MtoM_ptr  = GFX_MGR02_NULL_PTR;
  GFX_MGR02_GPOS_BASE_TABLE     const *fl_mark2_MtoM_ptr  = GFX_MGR02_NULL_PTR;
  GFX_FLOAT fl_height_pixels    = 1.0f;
  GFX_FLOAT fl_mark_pixels_x    = 0.0f;
  GFX_FLOAT fl_mark_pixels_y    = 0.0f;
  GFX_FLOAT fl_base_pixels_x    = 0.0f;
  GFX_FLOAT fl_base_pixels_y    = 0.0f;
  HMI_CHAR fl_index             = 0U;
  UINT8 fl_tbl_found            = GFX_MGR02_GPOS_INVALID_TBL;
  HMI_CHAR base_char;
  HMI_CHAR mark1_char;
  //#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
 #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
  HMI_CHAR mark2_char;
  HMI_CHAR const *fl_string_ptr = p_string_ptr;
  #endif
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
  FONT_METRICS fm;
  UINT32 fl_font_id = p_font_id;
  GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
  fl_gpos_table_ptr = lc_gfx_font_table[fl_font_id].gpos_table_ptr;
  FS_font_metrics((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, &fm);
  /* Converting FUnits to pixels */
  fl_height_pixels           =  (fl_font_SP->height_pts/fm.unitsPerEm);
#else
  fl_gpos_table_ptr          = p_font_SP->gpos_table_ptr;
  fl_height_pixels           = ((GFX_FLOAT)(p_font_SP->height_pts)/(GFX_FLOAT)p_font_SP->unitsPerEm);
#endif
  if((p_string_ptr[0] != (HMI_CHAR)('\0')) && (p_string_ptr[1] != (HMI_CHAR)('\0')))
  {
    if(p_lang_read_dir == GFX_MGR02_LANG_READ_DIR_RTL)
    {
      base_char = p_string_ptr[1];
      mark1_char = p_string_ptr[0];
    }
    else
    {
      base_char = p_string_ptr[0];
      mark1_char = p_string_ptr[1];
    }
    if(fl_gpos_table_ptr != GFX_MGR02_NULL_PTR)
    {
      /* handle Mark to Base table */
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
      mark2_char = base_char;      
      if((fl_gpos_table_ptr->mark_to_base_tbl_size > 0U) && (p_lang_read_dir != GFX_MGR02_LANG_READ_DIR_RTL))
      {
        /*The Base char need not to be a previous char. So search for the Base char in reverse order*/
        while(p_str_index >= 0)
        {
         #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if((GFX_MGR02_IS_THAI_JOIN_CHAR(*fl_string_ptr) != 1U) && (GFX_MGR02_DEVA_ZW_CHAR(*fl_string_ptr) != 1U))
         #elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if(GFX_MGR02_IS_THAI_JOIN_CHAR(*fl_string_ptr) != 1U)
         #else
          if(GFX_MGR02_DEVA_ZW_CHAR(*fl_string_ptr) != 1U)
         #endif
          {
            base_char = *fl_string_ptr;
            break;
          }
          p_str_index--;
          fl_string_ptr--;
        }
      }
#endif
      for(fl_index = 0U; fl_index < fl_gpos_table_ptr->mark_to_base_tbl_size; fl_index++)
      {
        GFX_MGR02_GPOS_M2B_TABLE const *fl_m2b_ptr = &fl_gpos_table_ptr->mark_to_base_tbl_ptr[fl_index];
        fl_mark_MtoB_ptr = hmi_gfx_mgr02_get_mark_anch_points(mark1_char,
          fl_m2b_ptr->gpos_MtoB_mark_ptr, fl_m2b_ptr->mark_MtoB_table_size);
        fl_base_gpos_ptr = hmi_gfx_mgr02_get_base_anch_points(base_char,
          fl_m2b_ptr->gpos_MtoB_base_ptr, fl_m2b_ptr->base_MtoB_table_size);
        if((fl_mark_MtoB_ptr != GFX_MGR02_NULL_PTR) && (fl_base_gpos_ptr != GFX_MGR02_NULL_PTR))
        {
          fl_tbl_found = GFX_MGR02_GPOS_M2B_TBL;
          break;
        }
      }
//#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)     
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
      //Restore back the base_char to process with Mark2Mark tables
      base_char = mark2_char;
#endif      
      /* handle Mark to Ligature table */
      for(fl_index = 0U; fl_index < fl_gpos_table_ptr->mark_to_ligature_tbl_size; fl_index++)
      {
        GFX_MGR02_GPOS_M2L_TABLE const *fl_m2l_ptr = &fl_gpos_table_ptr->mark_to_ligature_tbl_ptr[fl_index];
        fl_mark_MtoL_ptr = hmi_gfx_mgr02_get_mark_anch_points(mark1_char,
          fl_m2l_ptr->gpos_MtoL_mark_ptr, fl_m2l_ptr->mark_MtoL_table_size);
        fl_lig_gpos_ptr = hmi_gfx_mgr02_get_ligature_anch_points(base_char,
          fl_m2l_ptr->gpos_MtoL_ligature_ptr, fl_m2l_ptr->ligature_table_size);
        if((fl_mark_MtoL_ptr != GFX_MGR02_NULL_PTR) && (fl_lig_gpos_ptr != GFX_MGR02_NULL_PTR))
        {
          fl_tbl_found = GFX_MGR02_GPOS_M2L_TBL;
          break;
        }
      }
      /* handle Mark to Mark table*/
      for(fl_index = 0U; fl_index < fl_gpos_table_ptr->mark_to_mark_tbl_size; fl_index++)
      {
        GFX_MGR02_GPOS_M2M_TABLE const *fl_m2m_ptr = &fl_gpos_table_ptr->mark_to_mark_tbl_ptr[fl_index];
        fl_mark1_MtoM_ptr = hmi_gfx_mgr02_get_mark_anch_points(mark1_char,
          fl_m2m_ptr->gpos_MtoM_mark1_ptr, fl_m2m_ptr->gpos_MtoM_mark1_size);
        fl_mark2_MtoM_ptr = hmi_gfx_mgr02_get_base_anch_points(base_char,
          fl_m2m_ptr->gpos_MtoM_mark2_ptr, fl_m2m_ptr->gpos_MtoM_mark2_size);
        if((fl_mark1_MtoM_ptr != GFX_MGR02_NULL_PTR) && (fl_mark2_MtoM_ptr != GFX_MGR02_NULL_PTR))
        {
          fl_tbl_found = GFX_MGR02_GPOS_M2M_TBL;
          break;
        }
      }
      if((fl_mark_MtoB_ptr != GFX_MGR02_NULL_PTR) && (fl_base_gpos_ptr != GFX_MGR02_NULL_PTR) && 
         (fl_mark2_MtoM_ptr == GFX_MGR02_NULL_PTR))
      {
        /* Apply GPOS MarkBase */
        if(fl_mark_MtoB_ptr->class_select < fl_base_gpos_ptr->count )
        {			
          fl_base_pixels_x   = (GFX_FLOAT)(((fl_height_pixels) * ((GFX_FLOAT)fl_base_gpos_ptr->class_anch[fl_mark_MtoB_ptr->class_select].anch_x)));
          fl_base_pixels_y   = (GFX_FLOAT)(((fl_height_pixels) * ((GFX_FLOAT)fl_base_gpos_ptr->class_anch[fl_mark_MtoB_ptr->class_select].anch_y)));
        }
        else
        {
          fl_base_pixels_x = (GFX_FLOAT)0;
          fl_base_pixels_y = (GFX_FLOAT)0;
        }
        fl_mark_pixels_x   = (GFX_FLOAT)(((fl_height_pixels) * ((GFX_FLOAT)fl_mark_MtoB_ptr->class_anch.anch_x)));
        fl_mark_pixels_y   = (GFX_FLOAT)(((fl_height_pixels) * ((GFX_FLOAT)fl_mark_MtoB_ptr->class_anch.anch_y)));

        p_delta_pixels->gpos_delta_pixels_x   = (GFX_FLOAT)((fl_base_pixels_x - fl_mark_pixels_x));
        p_delta_pixels->gpos_delta_pixels_y   = (GFX_FLOAT)((fl_base_pixels_y - fl_mark_pixels_y));
      }
      else if((fl_mark_MtoL_ptr != GFX_MGR02_NULL_PTR) && (fl_lig_gpos_ptr != GFX_MGR02_NULL_PTR))
      {
        GFX_MGR02_GPOS_COMPONENT const*fl_lig_comp_ptr; 
        UINT8 fl_components_size;
        UINT8 fl_comp_index;
        GFX_MGR02_GPOS_LIG_COMP_TABLE const*fl_lig_anch_pts_ptr;
        GFX_MGR02_CLASS_ANCH_POINTS const*fl_final_anch_points = GFX_MGR02_NULL_PTR;

        fl_lig_comp_ptr = fl_lig_gpos_ptr->components;
        fl_components_size = fl_lig_gpos_ptr->components_size;
        for(fl_comp_index=(fl_components_size); fl_comp_index>0U; fl_comp_index--)
        {
          /* 
          ** Always try get matching anchor points from last component in the ligature table.
          ** If matching anchor points are not available in last then try get it from 2nd las
          ** and so on ... until 1st component (0th index)
          */
          fl_lig_anch_pts_ptr = &fl_lig_comp_ptr->anch_ptr[fl_comp_index-1U];
          if(fl_mark_MtoL_ptr->class_select == (UINT8)GFX_MGR02_CLASS0)
          {
            if((fl_lig_anch_pts_ptr->class0_anch.anch_x !=0) &&
              (fl_lig_anch_pts_ptr->class0_anch.anch_y !=0))
            {
              fl_final_anch_points = &fl_lig_anch_pts_ptr->class0_anch;
              break;
            }
          }
          else
          {
            if((fl_lig_anch_pts_ptr->class1_anch.anch_x !=0) &&
              (fl_lig_anch_pts_ptr->class1_anch.anch_y !=0))
            {
              fl_final_anch_points = &fl_lig_anch_pts_ptr->class1_anch;
              break;
            }
          }
        }
        if(fl_final_anch_points != GFX_MGR02_NULL_PTR)
        {
          GFX_FLOAT fl_lig_pixels_x=(GFX_FLOAT)0;
          GFX_FLOAT fl_lig_pixels_y=(GFX_FLOAT)0;

          fl_lig_pixels_x   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_final_anch_points->anch_x)));
          fl_lig_pixels_y   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_final_anch_points->anch_y)));

          fl_mark_pixels_x   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark_MtoL_ptr->class_anch.anch_x)));
          fl_mark_pixels_y   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark_MtoL_ptr->class_anch.anch_y)));

          p_delta_pixels->gpos_delta_pixels_x   = (GFX_FLOAT)((fl_lig_pixels_x - fl_mark_pixels_x));
          p_delta_pixels->gpos_delta_pixels_y   = (GFX_FLOAT)((fl_lig_pixels_y - fl_mark_pixels_y));
        }
      }
      else if((fl_mark1_MtoM_ptr != GFX_MGR02_NULL_PTR) && (fl_mark2_MtoM_ptr != GFX_MGR02_NULL_PTR))  //Mark2Mark
      {
        
        if(fl_mark1_MtoM_ptr->class_select < fl_mark2_MtoM_ptr->count )
        {
            fl_base_pixels_x   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark2_MtoM_ptr->class_anch[fl_mark1_MtoM_ptr->class_select].anch_x)));
            fl_base_pixels_y   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark2_MtoM_ptr->class_anch[fl_mark1_MtoM_ptr->class_select].anch_y)));
        }
        else
        {
            fl_base_pixels_x = (GFX_FLOAT)0;
            fl_base_pixels_y = (GFX_FLOAT)0;
        }
        
        fl_mark_pixels_x   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark1_MtoM_ptr->class_anch.anch_x)));
        fl_mark_pixels_y   = (GFX_FLOAT)((fl_height_pixels * ((GFX_FLOAT)fl_mark1_MtoM_ptr->class_anch.anch_y)));

        p_delta_pixels->gpos_delta_pixels_x   = (GFX_FLOAT)((fl_base_pixels_x - fl_mark_pixels_x));
        p_delta_pixels->gpos_delta_pixels_y   = (GFX_FLOAT)((fl_base_pixels_y - fl_mark_pixels_y));
      }
      else
      {
        /*For MISRA warning Fix.*/
      }
    } 
  }
  return fl_tbl_found;
}
#endif  /* #if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED) */

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_get_string_reverse()
** Visibility:       Global
** Description:      Reverse the input string.
** Invocation:       Internally
** Inputs/Outputs:   Returns the reversed string output.
**                   p_rev_str ==> Input and output string
**                   p_count  ==> string length
** Critical Section: None
** Created:          6-Apr-2018 by SBOLLAM
**===========================================================================*/
void hmi_gfx_mgr02_get_string_reverse(HMI_CHAR * p_rev_str, UINT16 p_count)
{ 
  UINT16 fl_count = p_count;
  if(fl_count > 0U)
  {
    HMI_CHAR fl_temp_char;
    UINT16 fl_input=0U;

    fl_count = fl_count-(UINT16)1;
    while (fl_input < fl_count) 
    {
      fl_temp_char = p_rev_str[fl_input];
      p_rev_str[fl_input] = p_rev_str[fl_count];
      p_rev_str[fl_count] = fl_temp_char;
      fl_input++;
      fl_count--;
    }
  }
}

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
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
** CMS Rev 1.84      04-Apr-2018     ADEVI
** 1079104: Monotype client handler implementation.
**
** CMS Rev 1.83      14-Mar-2018     ADEVI
** 1054545: Freetype cache implementation.
**
** CMS Rev 1.82     19-Jan-2018     ARAJASE2
** 1035451: GPOS X Position update for Thai Language
** hmi_gfx_mgr02_get_gpos_delta_pixels function prototype changed to return the status of
** GPOS table availability for the given characters
**
** CMS Rev 1.81     10/01/18    ADEVI
** 1004848 : Clip information fectched from application and Append string located based on app input.
**
** CMS Rev 1.80     20-Dec-2017    ARAJASE2
** 1021315: Multiple GPOS table support in graphic manager
**
** CMS Rev 1.79     19-Dec-2017    KKUBENDI
** 1010997: GPOS table support for Amber platform in Graphics Manager 02
** Moved function hmi_gfx_mgr02_get_gpos_delta_pixels from hmi_gfx_mgr02_ovglib.c

** CMS Rev 1.78     30-Nov-2017    ARAJASE2
** 1005357: Graphics Manager update for Hebrew Text rendering
** Added new function hmi_gfx_mgr02_get_hebrew_char_count to check the hebrew character range
**
** CMS Rev 1.77     02/11/17    ADEVI
** 986811 : Range of Bidi procesed arabic characters included in get_arabic_char_count function.
**
** CMS Rev 1.76     23/10/17    ADEVI
** 953502 : Text clipping issue in wchar lib of GHS resolved.
**
** CMS Rev 1.75     19-Oct-2017    SBOLLAM
** 976302: Optimized "get_text_width" function to improve
** the text process and rendering speed when input string
** is large
** CMS Rev 1.74     18-Sep-2017    ARAJASE2
** 921462: Dynamic Font update issue in Amber platform with External font
** Unwanted code removed from hmi_gfx_mgr02_set_font_size function
**
** CMS Rev 1.73     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.72     04/08/17    ADEVI
** 924879 : Monotype Font Integration in Kepler I.
**
** CMS Rev 1.71    24-Jul-2017    SBOLLAM
** RTC ID: 917605: Implemented GPOS- MarkToLigature table
**
** CMS Rev 1.70    29-Jun-2017    SSRINI19
** 880883 : GM-CHUD QAC MISRA additional warning fixes 
**
** CMS Rev 1.69     30-May-2016    APERUMAL
** RTC 876766:
** B515 : Multiline string length beyond 255 is causing reset
** Changed fl_tot_nb_char_U8 from UINT8 to UINT32 in hmi_gfx_mgr02_ft2_get_text_width,
** hmi_gfx_mgr02_mt_get_text_width, hmi_gfx_mgr02_get_text_width
**
** CMS Rev 1.68     06-Jan-2017    SSIGAMAN
** 774561: Removed the conditional compilation macro GFX_MGR02_NUM_OF_DTEXTS
** for hmi_gfx_mgr02_get_font_id().
**
** CMS Rev 1.67      31-Jan-2017    VGAJJI
** 793418: B515 - Coverity Warnings Fix
**
** CMS Rev 1.66     30-JAN-2016    ADEVI
** RTC 790127:
** Hyundai DE Issue - Non - linear scrolling issue fixed.
**
** CMS Rev 1.65     21-DEC-2016    ADEVI
** RTC 770468:
** B515 Issue - Append characters were not displayed is fixed.
**
** CMS Rev 1.64     22-NOV-2016    ADEVI
** RTC 739046:
** Honda T6ZA Arabic half character cut issue 
**
** CMS Rev 1.63     02-NOV-2016    APERUMAL
** RTC 735553:
** Porsche Misra warning fixes 
**
** CMS Rev 1.62     28-Oct-2016    ADEVI
** RTC 715689:
** Resolved Scroll issue in Hyundai.
**
** CMS Rev 1.61     15-Sep-2016    SBOLLAM
** 695578: GPOS handling through mono type font engine.
** Description: Added two new functions
**              <hmi_gfx_mgr02_get_mark_anch_points>
**              <hmi_gfx_mgr02_get_base_anch_points>
**
** CMS Rev 1.60    27-JULY-2016    SANAND2
** 641381: Arabic multi line implementation.

** CMS Rev 1.59     6-Jun-2016    ADEVI
** RTC 612917:
** Issue in arabic text rendering. Increased gaps seen.
**
** CMS Rev 1.58     2-Jun-2016    SBOLLAM
** RTC 611259:
** Text box start offset(alignment) is not proper.
**
** CMS Rev 1.57     02-June-2016    CSAKTHIV
** RTC 566848:
** Thai support using GSUB table
**
** CMS Rev 1.56     12-May-2016    SBOLLAM
** RTC 594426:
** Observed Extra Pixels for some characters in Arabic.
**
** CMS Rev 1.56     12-May-2016    ADEVI
** RTC 594099:
** l_displayed_width rounding off done for display without rotation only.
**
** CMS Rev 1.55     06-May-2016    SBOLLAM
** 578284: Honda T6ZA: Arabic character gap issue exists in few strings 
** Added CheckArabicCharRange() API.
**
** CMS Rev 1.54     4-May-2016    SSIGAMAN
** RTC 564827: 
** FT_LOAD_DEFAULT is added with FT_LOAD_FORCE_AUTOHINT when auto hint is TRUE.
**
** CMS Rev 1.53     28-Apr-2016    ADEVI
** 578262: Add dynamic change of size of the used TTF fonts
** Added hmi_gfx_mgr02_set_font_size() API.
**
** CMS Rev 1.52     11-Apr-2016    ADEVI
** RTC 5570947:
** Right aligned text scroll for Hyundai AE SVC.
**
** CMS Rev 1.51      08-Apr-2016    APERUMAL
** 568204: Compiler warning fix for Hyundai DE
** 
** CMS Rev 1.50      07-Apr-2016    SBOLLAM
** 564648: Arabic join issue observed in HondaTG7
** 
** CMS Rev 1.49      29-Mar-2016    SVIKRAM
** 521269: Compiler warnings fix
**
** CMS Rev 1.48     24-Mar-2016    SSIGAMAN
** 554985: Amber:AutoHint status update changes
** Added hmi_gfx_mgr02_is_autohint_enabled() API and the hinting is 
** selected based on it in freetype width calc funtion.
**
** CMS Rev 1.47     29-Feb-2015   SSIGAMAN
** RTC533884: condition compilation statement is wrong
** Conditional compilation statement in the hmi_gfx_mgr02_get_text_width() API
** for freetype text Corrected.
**
** CMS Rev 1.46     05-Feb-2015    APERUMAL
** RTC 512949:
** Compiler warnings fix for B515
**
** CMS Rev 1.45     28-Dec-2015   CSAKTHIV
** Ref RTC# 490199
** Monotype Integration
** 
** CMS Rev 1.44     21-Dec-2015   ADEVI
** Ref RTC# 485981
** Dots issue when long length text with characters of odd width are getting
** rendered in anti-clockwise rotated display.  The calculation for odd width 
** characters was happening unwantedly for rotated display.
** 
** CMS Rev 1.43     12-Nov-2015   SBOLLAM
** Ref RTC# 464097
** Fixed reset issue, found after enabling "DMA N CPU" 
** render option in GDT
**
** CMS Rev 1.42     4-Nov-2015    SBOLLAM
** Ref RTC# 412557.
** For rendering negativ x-soffset characters,
** introduced new function which will render through
** CPU <hmi_gfx_mgr02_font_char_cpu_print>
**
** CMS Rev 1.41     15-Sep-2015   SSIGAMAN
** Ref RTC# 370662.
** hmi_gfx_mgr02_get_font_id() modified as it always return "0" as font id.
**
** CMS Rev 1.40     7-Sep-2015    SBOLLAM
** Ref RTC# 404998.
** Fixed an issue, when freetype is used as ext font engine,
** and the text is right aligned, then updated print string
** is not considered in <hmi_gfx_mgr02_ft2_get_text_width> 
**
** CMS Rev 1.39     3-Aug-2015    SBOLLAM
** Ref RTC# 390099.
** Default font feature implementation for font groups.
**
** CMS Rev 1.38     23-Jul-2015   ARAJASE2
** 380645: W207 Compiler warnings
** Compiler warning fix for W207
**
** CMS Rev 1.37     03-Jul-2015    EMANOJ1
** Ref RTC#371850 
** Fixed text alignment issue in rotated display configuration due to width
** calculation error.
** 
** CMS Rev 1.36     26-Jun-2015    EMANOJ1
** Ref RTC#357859 
** Updated hmi_gfx_mgr02_get_text_width to fix a text buffer overwrite issue.
** This was due to the fact that GFX_MGR02_FONT_CHAR_CONFIG width was some times
** > owidth. owidth was used for calculating total string width & since width
** was > for some characters, it was resulting lesser string width than was 
** actually needed. So in the DCU target this will cause the buffer being overrun
**
** CMS Rev 1.35     25-Jun-2015    EMANOJ1
** Ref RTC#366174 
** Changes done in 1.34 are reverted as it has introduced side effects of uneven
** character spacing between characters. Instead the 1.34 handling will be done 
** via GDT code generation
**
** CMS Rev 1.34     15-Mar-2015    CSAKTHIV
** Ref RTC# 
** Arabic language change. If x_offset is negative, then it should be added to 
** 0 width only for DCU. As in DCU frame buffer will be overwritten instead of 
** blending.
**
** CMS Rev 1.33     19-Jan-2015    ADEVI
** Ref RTC# 270611, 259720.
** Horizontal scroll implementation done for DCU(4/8BPP) with rotation disabled.
**
** CMS Rev 1.32     24-Dec-2014    ADEVI
** Ref RTC# 261166.
** Memory corrution was happening when scroll enabled in DCU with anti-clockwise
** rotation enabled.  The l_text_y_offset was not considered and reinitialised.
** for space character.
**
** CMS Rev 1.31     18-Nov-2014    ADEVI
** Ref RTC# 204201,240749.
** Check added to restrict when the characters to be displayed cross the actual 
** text box width, when anti clockwise rotated text with scroll is enabled.
**
** CMS Rev 1.30     13-Nov-2014    ADEVI
** Ref RTC# 239784.
** #if GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1 check always used along with.
** GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1 since for text only anti-
** clockwise rotation support is provided now.
**
** CMS Rev 1.29     11-Nov-2014    ADEVI
** Ref RTC# 204201.
** Updated hmi_gfx_mgr02_font_fsl_edma_sm to support text scrolling during normal
** and anti clockwise rotation conditions.
**
** CMS Rev 1.28     13-Oct-2014    EMANOJ1
** Fixed a variable handling issue in hmi_gfx_mgr02_ft2_get_text_width 
** identified during review. SMIS ID : 79920
**
** CMS Rev 1.27     10-Oct-2014    EMANOJ1
** RTC #205473 : Added support for inserting blank pixels in text string
**
** CMS Rev 1.26     15-Jul-2014    EMANOJ1
** In Rev 1.25 changes, update to parameter passed to FT_Load_Char were missed
** in few other places. Those were now corrected to match with all other places
** to fix the reopen of text width calculation issue.
**
** CMS Rev 1.25     19-Jun-2014    EMANOJ1
** CTC reported that hmi_gfx_mgr02_layout_get_text_width is reporting width
** lesser than what is actually displayed.
** Updated hmi_gfx_mgr02_ft2_get_text_width fix the parameter passed to
** FT_Load_Char to match that of the one passed in hmi_gfx_mgr02_ogllib_build_text
** so that the width calculation is matching. 
**
** CMS Rev 1.24     25-Feb-2014    EMANOJ1
** Text width calculation for freetype library updated to consider text color
** code prefix command and color data when multi colored text for opengl is
** enabled.
**
** CMS Rev 1.23     18-Feb-2014    EMANOJ1
** >isel instruction usage is disabled per ui.core.gdt.doc\hmi.gfx.manager.02\release\SR# 1-1248551151.msg
**
** CMS Rev 1.22     17-Jan-2014    EMANOJ1
** Updated hmi_gfx_mgr02_get_text_width updated to donot add an extra pixel for 
** odd width, if the current character is the last character of the string. Done
** to fix width calculation error.
**
** CMS Rev 1.21     18-Dec-2013    EMANOJ1
** GFX_MGR02_DEFAULT_CHAR handling added to replace missing characters with a 
** default character.
**
** CMS Rev 1.20     17-Dec-2013    EMANOJ1
** Integrated digity
**
** CMS Rev 1.19     09-Dec-2013    EMANOJ1
** Fixed issue in width difference when a null pointer is passed in p_string
** compared to a valid pointer for a append text condition. When a null pointer
** is passed, the append width was not added to overall width which caused this
** issue. So hmi_gfx_mgr02_get_text_width updated to fix the issue
**
** CMS Rev 1.18     15-Nov-2013    EMANOJ1/SBOLLAM
** Removed the extra transparent pixels at left/right side of text during width
** calculation as the same calculation was not performed during rendering and 
** was causing a clipping effect.
** Text width calculation updated so that append text works with vg font as well
**
** CMS Rev 1.17     11-Nov-2013    EMANOJ1/SBOLLAM
** hmi_gfx_mgr02_get_text_width updated to correctly apply the end transp
** pixels for left/center aligned text
** Left/Center aligned string copy to p_string updated to fix an issue of 
** skipping one character.
**
** CMS Rev 1.17     09-Nov-2013    SBOLLAM
** hmi_gfx_mgr02_get_text_width updated to impement append text functionality
**
** CMS Rev 1.15     19-Sep-2013    EMANOJ1
** hmi_gfx_mgr02_font_fsl_edma_sm updated to handle the odd number handling
** in case if(fl_char_height <= 0) to fix alignment issue when a text is animated
** vertically (y axis) from clipping to no clipping.
** Also fixed making fl_font_fcc_SP = NULL and accessing owidth in the same case
** as well.
**
** CMS Rev 1.14     19-Sep-2013    EMANOJ1
** rev 1.12 change was integrated at the wrong location. Which is corrected.
**
** CMS Rev 1.13     19-Sep-2013    EMANOJ1
** Updated to hmi_gfx_mgr02_font_fsl_edma_print to support multi color text
** The updation is done to calculate the start address for text copy incase
** of a multi-color widget. Multi color widgets destination buffer is 16bpp
** so the calculation has to handle this.
**
** CMS Rev 1.12     11-Sep-2013    EMANOJ1
** Updated hmi_gfx_mgr02_get_text_width() to fix a right aligned numeric text
** shaking issue noted in P42M.
**
** CMS Rev 1.11     30-Aug-2013    EMANOJ1
** l_fsl_text_task_state is updated before DMA request to makesure that if the
** DMA complete callback happens prioror to return of the DMA request, we
** will not corrupt the task state causing a stuck issue.
**
** CMS Rev 1.10     27-Aug-2013    EMANOJ1
** Updated to support the infrastructure DMA manager core package instead of the
** freescale DMA.c
**
** CMS Rev 1.9      11-Jul-2013    EMANOJ1
** Updated not to perform a callback initiation to caller, if the text printing
** could not be started. If the printing could not be started only the return status
** provided to application. If the text printing is started, then the call back
** will be provided after all chars are printed as usual.
**
** CMS Rev 1.8      12-Jun-2013    EMANOJ1
** Added hmi_gfx_mgr02_get_gfont_alignment function to return the modified
** text alignment value which can be coomonly used by all platforms.
** Fixed an issue in binary lookup (hmi_gfx_mgr02_get_fcc) where it failed
** to locate arabic character ranges in a test application.
**
** CMS Rev 1.6      10-Jun-2013    EMANOJ1
** Added interface to set/get font group properties
**
** CMS Rev 1.5      07-Jun-2013    EMANOJ1
** Implemented vector fonts based text rendering.
**
** CMS Rev 1.4      06-Jun-2013    EMANOJ1
** Handled a case where x_soffset was having a negative value and resulted in
** frame buffer pointer going outside the boundary and causing a corruption.
**
** CMS Rev 1.3      24-May-2013    EMANOJ1
** Rewrite the eDMA font printing routines optimize and commonize existing
** routines with swr and ovg.
**
** CMS Rev 1.2      22-Mar-2013    VMUTHUSU
** Change NULL_PTR to GFX_MGR02_NULL_PTR
**
** CMS Rev 1.1      15-Mar-2012    ASHEKHAR
** Resolved issue with respect to default matrix. OpenVG origin is at bottom
**
** CMS Rev 1.0      09-Aug-2012    ASHEKHAR
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
