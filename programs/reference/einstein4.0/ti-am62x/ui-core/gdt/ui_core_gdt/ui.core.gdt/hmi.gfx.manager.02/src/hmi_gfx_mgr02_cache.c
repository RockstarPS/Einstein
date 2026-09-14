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
 ** Name:           hmi_gfx_mgr02_cache.c
 **
 ** Description:    File for handling cache for images, char and text for different 
 **                 platforms in  graphics manager 02.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define GUI_GFX_MANAGER_CACHE_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED)) ||((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)) && defined(GFX_STRING_CACHE_ENABLED)) || ((defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED))
#include "hmi_gfx_mgr02_generic.h"
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
#include "hmi_gfx_mgr02_ogllib.h"
#endif
#include "hmi_gfx_mgr02_cache.h"

#include "stdlib.h"
#include "string.h"
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/


/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
GFX_MGR02_TEXTURE l_gees11_char_texture[GFX_MGR02_MAX_CHAR_TEXTURES];
#endif
#ifdef GFX_STRING_CACHE_ENABLED
static GFX_STRING_CACHE_INFO *head;
static GFX_STRING_CACHE_INFO *tail;
static UINT32 cur_cache_size = (UINT32)0;
/*To add one entry in Queue.*/
static void hmi_gfx_mgr02_cache_enqueue(const GFX_STRING_CACHE_INFO *Node);
/*To remove a rear entry from the Queue.*/
static void hmi_gfx_mgr02_cache_dequeue(void);
/*To bring the entry which is in the Queue to front.*/
static UINT8 * hmi_gfx_mgr02_cache_update_queue(const GFX_STRING_CACHE_INFO *Node, UINT8 p_use_inString);
static void hmi_gfx_mgr02_shutdown_string_cache(void);
static UINT32 hmi_gfx_mgr02_cache_node_exist(const GFX_STRING_CACHE_INFO *p_dst_Node, const GFX_STRING_CACHE_INFO *p_src_Node, UINT8 p_use_inString);
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
static FT_Error hmi_gfx_mgr02_ft2face_Requester(FTC_FaceID  p_face_id, FT_Library  p_library, FT_Pointer  p_req_data, FT_Face*    p_face);	
static FTC_Manager     l_ftc_manager     = NULL;
static FTC_ImageCache  l_ftc_image_cache = NULL;
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
/****************************************************************************
Function Name        : hmi_gfx_mgr02_cache_init
Description          : Returns the texture from the cache if present else
                       returns NULL
Invocation           : Invoked internally
Parameters           : Pointer to the image data
Return Value         : GFX_MGR02_TEXTURE pointer ot NULL
Critical Section     : None
External Interfaces  : None
******************************************************************************/
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))||((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)) && defined(GFX_STRING_CACHE_ENABLED))
void hmi_gfx_mgr02_cache_init(void)
{
   #if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
   (void)memset(l_gees11_char_texture, 0, (sizeof(GFX_MGR02_TEXTURE)*GFX_MGR02_MAX_CHAR_TEXTURES));
   #endif
   #ifdef GFX_STRING_CACHE_ENABLED
    /*
    1. Do memory initializations.
    */
    head= NULL;
    tail= NULL;
    cur_cache_size =(UINT32)0;
   #endif
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_cache_shutdown
Description          : Returns the texture from the cache if present else
                       returns NULL
Invocation           : Invoked internally
Parameters           : Pointer to the image data
Return Value         : GFX_MGR02_TEXTURE pointer ot NULL
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_cache_shutdown(void)
{
#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
  UINT32 i;

  for (i = 0; i < GFX_MGR02_MAX_CHAR_TEXTURES; i++)
  {
#if defined(GFX_MGR02_OPEN_GL)
    if (l_gees11_char_texture[i].texId != 0)
    {
      glDeleteTextures(1, &l_gees11_char_texture[i].texId);
      l_gees11_char_texture[i].texId = 0;
    }
#endif
#if defined(GFX_MGR02_OPEN_VG)
    if (l_gees11_char_texture[i].imageid != 0)
    {
#ifndef FSL_CONST_IMAGES
      vgDestroyImage(l_gees11_char_texture[i].imageid);
#else
      vgDestroyConstImageFSL(l_gees11_char_texture[i].imageid);
#endif
      l_gees11_char_texture[i].imageid = 0;
    }
#endif
    l_gees11_char_texture[i].data = 0;

  }
#endif
#ifdef GFX_STRING_CACHE_ENABLED
  hmi_gfx_mgr02_shutdown_string_cache();
#endif
}
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ft2face_Requester
Description          : Call back function while using free type cache.
Invocation           : Call back function invoked by Free type
Return Value         : FT_Error
Critical Section     : None
Parameters           : p_face_id, p_library, p_req_data, p_face
******************************************************************************/	
static FT_Error hmi_gfx_mgr02_ft2face_Requester(FTC_FaceID  p_face_id, FT_Library  p_library, FT_Pointer  p_req_data, FT_Face*    p_face)
{
  FT_Error fl_error;
  GFX_MGR02_FONT const * fl_font;
  GFX_MGR02_CONTEXT_T const * p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
  fl_font = p_face_id;		
  fl_error = FT_New_Memory_Face( p_cntx_SP->rprop.ft2_library, 
                                fl_font->f.ffile_name, 
                                (FT_Long)fl_font->extfontsize,  
                                0, 
                                p_face);
  GFX_MGR02_UNUSED_PTR(p_library);
  GFX_MGR02_UNUSED_PTR(p_req_data);  
  return fl_error;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ft2_cache_init
Description          : Initialisation of cache manager and image cache handler
Invocation           : Invoked by context_ext_font_engine_initialize
Return Value         : FT_Error
Critical Section     : None
Parameters           : p_library
******************************************************************************/
FT_Error  hmi_gfx_mgr02_ft2_cache_init(FT_Library  p_library)
{
  FT_Error        fl_error;
  fl_error = FTC_Manager_New(p_library, GFX_MGR02_AMBER_FT2_CACHE_MAX_FACES, GFX_MGR02_AMBER_FT2_CACHE_MAX_SIZES, GFX_MGR02_AMBER_FT2_CACHE_MAX_BYTES, hmi_gfx_mgr02_ft2face_Requester, NULL, &l_ftc_manager);
  if(fl_error == FALSE)
  {
    fl_error = FTC_ImageCache_New(l_ftc_manager, &l_ftc_image_cache);
  }
  return fl_error;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ft2_cache_face_init
Description          : Face and Size lookup while using freetype cache.
Invocation           : Invoked by context_ext_font_engine_initialize
Return Value         : FT_Error
Critical Section     : None
Parameters           : p_font_id
******************************************************************************/
FT_Error hmi_gfx_mgr02_ft2_cache_face_init(UINT8 p_font_id)
{
    FTC_ScalerRec   fl_scaler;
    FT_Size         fl_asize = NULL;
    GFX_FLOAT       ptsize;
    FT_Error        fl_error = 0;
      
    if (p_font_id < (UINT8)GFX_MGR02_NUM_OF_FONTS)
    {      
        GFX_MGR02_CONTEXT_T * p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
        UINT32 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(p_font_id);
        fl_scaler.face_id = (FTC_FaceID)(&lc_gfx_font_table[fl_ft2_face_index]);
        fl_scaler.width = 0;
        ptsize = ((GFX_FLOAT)lc_gfx_font_table[p_font_id].height_pts * 64.0f);
        fl_scaler.height = (FT_UInt)ptsize;
        fl_scaler.pixel = 0;
        fl_scaler.x_res = GFX_MGR02_DPI;
        fl_scaler.y_res = GFX_MGR02_DPI;

        fl_error = FTC_Manager_LookupFace( l_ftc_manager,(FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index], &p_cntx_SP->rprop.ft2_faceprop[p_font_id].ft2_face);
        if(fl_error == FALSE)
        {
            fl_error = FTC_Manager_LookupSize( l_ftc_manager,&fl_scaler, &fl_asize);
        }
        if((fl_error == FALSE) && (fl_asize != NULL))
        {
            fl_error = FT_Activate_Size(fl_asize);
        }
    }
    return fl_error;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_ft2_cachemgr_handler
Description          : The free type cache manager handler is passed.
Invocation           : Invoked by hmi_gfx_mgr02_set_font_size
Return Value         : FTC_Manager
Critical Section     : None
Parameters           : None
******************************************************************************/
FTC_Manager hmi_gfx_mgr02_get_ft2_cachemgr_handler(void)
{
  return l_ftc_manager;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_ft2_imgcache_handler
Description          : The free type image cache handler is passed.
Invocation           : Invoked by hmi_gfx_mgr02_get_ft_char_width,
                       hmi_gfx_mgr02_amber_FtTextOut.
Return Value         : FTC_ImageCache
Critical Section     : None
Parameters           : None
******************************************************************************/
FTC_ImageCache hmi_gfx_mgr02_get_ft2_imgcache_handler(void)
{
  return l_ftc_image_cache;
}
#endif


#if defined(GFX_MGR02_OPEN_GL)||(defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_char_cache_ptr
Description          : Returns the texture from the cache if present else
                       returns NULL
Invocation           : Invoked internally
Parameters           : Pointer to the image data
Return Value         : GFX_MGR02_TEXTURE pointer ot NULL
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GFX_MGR02_TEXTURE * hmi_gfx_mgr02_get_char_cache_ptr(void const* p_img_id)
{
   UINT32              fl_tex_index;
   BOOLEAN             fl_texture_found = FALSE;
   UINT32              fl_cur_live_count   = GFX_MGR02_MAX_CACHE_LIVE;
   UINT32              fl_least_used_index = GFX_MGR02_MAX_CHAR_TEXTURES;


   for(fl_tex_index=0; fl_tex_index < GFX_MGR02_MAX_CHAR_TEXTURES; fl_tex_index++)
   {
      if(l_gees11_char_texture[fl_tex_index].id == p_img_id)
      {

         fl_texture_found = TRUE;
    #if defined(GFX_MGR02_OPEN_GL)
         glActiveTexture(GL_TEXTURE0);
      #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         glEnable(GL_TEXTURE_2D);
      #endif
         glBindTexture(GL_TEXTURE_2D, l_gees11_char_texture[fl_tex_index].texId);
    #endif
         /* keep the image id same so that new texture will not be created. china team keep p_img_id in ram */
         l_gees11_char_texture[fl_tex_index].id   = p_img_id;
         l_gees11_char_texture[fl_tex_index].live = (GFX_MGR02_MAX_CACHE_LIVE+1);
         fl_least_used_index = fl_tex_index;
         break;
      }
      else if(l_gees11_char_texture[fl_tex_index].live < fl_cur_live_count)
      {
         fl_cur_live_count   = l_gees11_char_texture[fl_tex_index].live;
         fl_least_used_index = fl_tex_index;
         /* imgid or texid can be zero anytime(yet to confirm). so using data */
         if(l_gees11_char_texture[fl_least_used_index].data == 0)
         {
            fl_texture_found = TRUE;
            break;
         }
      }
      else
      {
      }
   }
   if(fl_texture_found == FALSE)
   {
      if(fl_least_used_index == GFX_MGR02_MAX_CHAR_TEXTURES)
      {
         fl_least_used_index = 0;
      }
      /* cleared so that texture will be deleted eventhough img id is same */
      l_gees11_char_texture[fl_least_used_index].id = 0;
    #if defined(GFX_MGR02_OPEN_VG)
      #ifndef FSL_CONST_IMAGES
         vgDestroyImage(l_gees11_char_texture[fl_least_used_index].imageid);
      #else
         vgDestroyConstImageFSL(l_gees11_char_texture[fl_least_used_index].imageid);
      #endif
      l_gees11_char_texture[fl_least_used_index].imageid = 0;
      l_gees11_char_texture[fl_least_used_index].live = 0;
      l_gees11_char_texture[fl_least_used_index].data = 0;
    #endif

   }

   return(&l_gees11_char_texture[fl_least_used_index]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_cache_update_live_count
Description          : Reduces the live count of the images in vg image cache
Invocation           : Invoked internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_cache_update_live_count(void)
{
   UINT32 i;
   for(i=0; i < GFX_MGR02_MAX_CHAR_TEXTURES; i++)
   {
      if(l_gees11_char_texture[i].live > 0)
      {
         l_gees11_char_texture[i].live--;
      }
   }
}
#endif
#ifdef GFX_STRING_CACHE_ENABLED
static UINT32 hmi_gfx_mgr02_cache_node_exist(const GFX_STRING_CACHE_INFO *p_dst_Node, const GFX_STRING_CACHE_INFO *p_src_Node, UINT8 p_use_inString)
{
    UINT32 fl_ret_status = (UINT32)FALSE;

    if (p_use_inString == (UINT8)(TRUE))
    {
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
      if ((p_dst_Node->FontId == p_src_Node->FontId) &&
          (p_dst_Node->FontSize == p_src_Node->FontSize) &&
          (p_dst_Node->ClipMode == p_src_Node->ClipMode) &&
          (p_dst_Node->TextBoxWidth == p_src_Node->TextBoxWidth) &&
          (p_dst_Node->Alignment == p_src_Node->Alignment) &&
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          (p_dst_Node->isScrolled == p_src_Node->isScrolled) &&
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          (p_dst_Node->MaxShrink == p_src_Node->MaxShrink) &&
#endif
          (p_src_Node->StringLen == (UINT8)((UINT8)(GFX_MGR02_MAX_TEXT_LENGTH) + 1U)) &&
          (HMI_STRCMP(p_dst_Node->InString, p_src_Node->InString) == 0))
      {
#if ((defined(GFX_MGR02_TXT_EFFECTS_ENABLED)) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        /*TODO: for now freetype supports bold effect alone so other checks are to be added as we add other features*/

        if (p_dst_Node->special_effects.effect_type == p_src_Node->special_effects.effect_type)
        {
          fl_ret_status = (UINT32)TRUE;
        }
#else
        fl_ret_status = (UINT32)TRUE;
#endif
      }

#endif
#endif
    }
    else
    {
      if ((p_dst_Node->FontId == p_src_Node->FontId) &&
          (p_dst_Node->FontSize == p_src_Node->FontSize) &&
          (p_dst_Node->StringLen == p_src_Node->StringLen) &&
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2))
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
          (p_dst_Node->ClipMode == p_src_Node->ClipMode) &&
          (p_dst_Node->TextBoxWidth == p_src_Node->TextBoxWidth) &&
          (p_dst_Node->Alignment == p_src_Node->Alignment) &&
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          (p_dst_Node->isScrolled == p_src_Node->isScrolled) &&
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          (p_dst_Node->MaxShrink == p_src_Node->MaxShrink) &&
#endif
#endif
#endif
#if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
          (p_dst_Node->drawColor == p_src_Node->drawColor) &&
#endif
          (HMI_STRCMP(p_dst_Node->String, p_src_Node->String) == 0))
        {
            #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
            if (p_dst_Node->special_effects.effect_type == p_src_Node->special_effects.effect_type)
            {
                #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
                if (p_src_Node->special_effects.effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
                {
                    if (p_dst_Node->special_effects.bold_percentage == p_src_Node->special_effects.bold_percentage)
                    {
                        fl_ret_status = (UINT32)TRUE;
                    }
                }
                else if ((p_src_Node->special_effects.effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT) || (p_src_Node->special_effects.effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT))
                {
                    if ((p_dst_Node->special_effects.otl_width != p_src_Node->special_effects.otl_width) &&
                        (p_dst_Node->special_effects.otl_opacity != p_src_Node->special_effects.otl_opacity))
                    {
                        fl_ret_status = (UINT32)FALSE;
                    }
                }
                else if (p_src_Node->special_effects.effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT)
                {
                    if ((p_dst_Node->special_effects.shadow_bg_col != p_src_Node->special_effects.shadow_bg_col) &&
                        (p_dst_Node->special_effects.shadow_x != p_src_Node->special_effects.shadow_x) &&
                        (p_dst_Node->special_effects.shadow_y != p_src_Node->special_effects.shadow_y))
                    {
                        fl_ret_status = (UINT32)FALSE;
                    } 
                }
                else
                #endif
                {
                    /* Even special effects properties also matches, that means this node is already exist */
                    fl_ret_status = (UINT32)TRUE;
                }
            }
            else
            #endif
            {
                /* Special effects properties are not matched */
                fl_ret_status = (UINT32)FALSE;
            }
        }
    }
    return fl_ret_status;
}

static void hmi_gfx_mgr02_cache_enqueue(const GFX_STRING_CACHE_INFO *Node)
{
    /* MISRA C-2012 Directive 4.12 disallows dynamic memory allocation, MISRA C-2012 Rule 21.3 disallows use of function malloc - Deviation Approved
     * the use of dynamic memory allocation (malloc) has been carefully considered here. 
     */
    struct GFX_STRING_CACHE_INFO_T *temp = (GFX_STRING_CACHE_INFO *)malloc(sizeof(GFX_STRING_CACHE_INFO));
    if(temp!=NULL)
    {
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        UINT8 fl_InStrLen = (UINT8)HMI_STRLEN(Node->InString);
        if (fl_InStrLen > (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
        {
          fl_InStrLen = (UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
        }
        
        (void)HMI_STRNCPY(temp->InString, Node->InString, (UINT32)(fl_InStrLen));
        temp->InString[fl_InStrLen] = (HMI_CHAR)'\0';
        temp->ClipMode              = Node->ClipMode;
        temp->TextBoxWidth          = Node->TextBoxWidth;
        temp->Alignment             = Node->Alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        temp->isScrolled             = Node->isScrolled; 
#endif         
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        temp->MaxShrink             = Node->MaxShrink;
#endif
#endif
#endif
        temp->bmpWidth    = Node->bmpWidth;
        temp->Buf         = Node->Buf;
        temp->FontId      = Node->FontId;
        temp->FontSize    = Node->FontSize;
        
        
        #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
        temp->drawColor   = Node->drawColor;
        #endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
        temp->special_effects.effect_type = Node->special_effects.effect_type;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
        if (Node->special_effects.effect_type != GFX_MGR02_TXT_INVALID_EFFECT)
        {
          temp->special_effects.bold_percentage = Node->special_effects.bold_percentage;
          temp->special_effects.otl_width = Node->special_effects.otl_width;
          temp->special_effects.otl_opacity = Node->special_effects.otl_opacity;
          temp->special_effects.shadow_bg_col = Node->special_effects.shadow_bg_col;
          temp->special_effects.shadow_x = Node->special_effects.shadow_x;
          temp->special_effects.shadow_y = Node->special_effects.shadow_y;
        }
#endif
#endif
        if(Node->StringLen < (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
        {
            temp->StringLen   = Node->StringLen;
        }
        else
        {
            temp->StringLen =(UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
        }
        
        if(temp->StringLen <= (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
        {
            (void)HMI_STRNCPY(temp->String,Node->String,(UINT32)temp->StringLen);
        }
        
        temp->String[temp->StringLen]=(HMI_CHAR)'\0';
    
        if(head==NULL)
        {
            head=temp;
            head->Prev = NULL;
            head->Next = NULL;
            tail=head;
            cur_cache_size++;
        }
        else
        {
            /*add the new element in the front of the queue*/
            temp->Prev = NULL;
            temp->Next = head;
            head->Prev = temp;
            head= temp;
            cur_cache_size++;
        }
    }

}
/*We are going to remove the tail element */
static void hmi_gfx_mgr02_cache_dequeue(void)
{
      struct GFX_STRING_CACHE_INFO_T *temp;
      temp = tail;
      if(tail->Prev == NULL)
      {
           head = NULL;
           tail = NULL;
      }
      else
      {
        tail = tail->Prev;
        tail->Next = NULL;
      }
      /* MISRA C-2012 Rule 21.3 disallows use of function free - Deviation Approved           
       * the use of dynamic memory allocation (free) has been carefully considered here. 
       */
      free(temp);
      cur_cache_size--;
}

/*To bring the entry which is in the Queue to front.*/
static UINT8 * hmi_gfx_mgr02_cache_update_queue(const GFX_STRING_CACHE_INFO *Node, UINT8 p_use_inString)
{
    UINT8 * retP=NULL;
    if(hmi_gfx_mgr02_cache_node_exist(head,Node, p_use_inString) != (UINT32)FALSE)
    {
        /*If the passed element matches the head of the Queue means, Do Nothing.
        */
        retP=head->Buf;
    }
    else if(hmi_gfx_mgr02_cache_node_exist(tail,Node, p_use_inString) != (UINT32)FALSE)
    {
        /*If the passed element matches the tail of the Queue
        Remove the element from the tail and add it in head.
        */
        tail->Next = head;
        head->Prev = tail;

        tail = tail->Prev;
        tail->Next =NULL;
        head = head->Prev;
        head->Prev = NULL;

        retP=head->Buf;
    }
    else
    {
        /*If the passed element matches the middle of the Queue means
        Shuffle the Queue in such a way that the cache hit content is in head of the queue.
        */
        if(cur_cache_size>(UINT32)2)
        {
            UINT32 counter= cur_cache_size-(UINT32)2;
            struct GFX_STRING_CACHE_INFO_T *cur;
            cur = head->Next;
            for(;counter>(UINT32)0;counter--)
            {
                if(hmi_gfx_mgr02_cache_node_exist(cur,Node, p_use_inString) != (UINT32)FALSE)
                {
                    cur->Prev->Next=cur->Next;
                    cur->Next->Prev=cur->Prev;

                    cur->Prev = NULL;
                    cur->Next = head;
                    head->Prev= cur;
                    head =cur;

                    retP=head->Buf;
                    break;
                }
                else
                {
                    cur=cur->Next;
                }
            }
        }
    }
    return retP;
}

#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
void * hmi_gfx_mgr02_get_string_cache_ptr(HMI_CHAR const * p_string_p, GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FONT const * p_font_SP, UINT32 p_font_id, GFX_MGR02_TXT_SPECIAL_EFFECTS  *p_special_effects
                                            #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
                                            ,GFX_MGR02_COLOR p_draw_color
                                            #endif
                                            )
#else
void * hmi_gfx_mgr02_get_string_cache_ptr(HMI_CHAR const * p_string_p, GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FONT const * p_font_SP,UINT32 p_font_id
                                            #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
                                            ,GFX_MGR02_COLOR p_draw_color
                                            #endif
                                            )
#endif
{
    void *ret=NULL;
    /*
    1. Search the Cache Queue for the requested String.
    2. If String is found, then return head->Buf. otherwise return NULL.
    */
    if((cur_cache_size>(UINT32)0) && (cur_cache_size <= (UINT32)GFX_MAX_NUM_STRINGS_TO_CACHE))
    {
        /*There are some entries in the Queue.*/
        GFX_STRING_CACHE_INFO temp;
        (void)memset(temp.String, (SINT32)'\0', sizeof(temp.String));
        (void)HMI_STRNCPY(temp.String,p_string_p,(UINT32)GFX_MGR02_MAX_TEXT_LENGTH);
        temp.StringLen = (UINT8)HMI_STRLEN(temp.String);
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        (void)memset(temp.InString, (SINT32)'\0', sizeof(temp.InString));
        temp.TextBoxWidth            = p_cntx_SP->rprop.text_width;
        temp.ClipMode                = (UINT8)p_cntx_SP->rprop.clip_mode;
        temp.Alignment               = (UINT8)p_cntx_SP->rprop.alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        temp.isScrolled              = (p_cntx_SP->rprop.scroll_offset > 0U) ? TRUE:FALSE; 
#endif 
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        temp.MaxShrink               = p_cntx_SP->rprop.max_shrink;
#endif
#endif
#endif
        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_VGLITE))
        if(p_font_SP->is_ffile !=0)
        {
            temp.FontSize  = p_cntx_SP->rprop.font_size.height;
        }
        else
        #endif
        {
            temp.FontSize  = p_font_SP->p.height;
        }
       #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
        if(p_special_effects != NULL)
        {
          temp.special_effects.effect_type = p_special_effects->effect_type;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          if(p_special_effects->effect_type != GFX_MGR02_TXT_INVALID_EFFECT)
          {
            temp.special_effects.bold_percentage = p_special_effects->bold_percentage;
            temp.special_effects.otl_width = p_special_effects->otl_width;
            temp.special_effects.otl_opacity = p_special_effects->otl_opacity;
            temp.special_effects.shadow_bg_col = p_special_effects->shadow_bg_col;
            temp.special_effects.shadow_x = p_special_effects->shadow_x;
            temp.special_effects.shadow_y = p_special_effects->shadow_y;
          }
#endif
        }
        else
        {
          temp.special_effects.effect_type = GFX_MGR02_TXT_INVALID_EFFECT;
        }
       #endif
        temp.FontId      = p_font_id;
        #if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
        temp.drawColor   = p_draw_color;
        #endif
        ret= hmi_gfx_mgr02_cache_update_queue(&temp, (UINT8)(FALSE));
    }

    return ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_string_cache_info()
Description          : API to get GFX_STRING_CACHE_INFO* for the given input string
Invocation           : Invoked by build_text.
Return Value         : true if given string is available otherwise false
Parameters           : GFX_STRING_CACHE_INFO --> Pointer to update the string cache info
******************************************************************************/
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
UINT8 hmi_gfx_mgr02_get_string_cache_info(GFX_STRING_CACHE_INFO* p_cache_info_out)
{
  UINT8 retValue = (UINT8)FALSE;
  /*
    1. Search the Cache Queue for the requested String.
    2. If String is found, then return head->Buf. otherwise return NULL.
  */
  if ((cur_cache_size > (UINT32)0) && (cur_cache_size <= (UINT32)GFX_MAX_NUM_STRINGS_TO_CACHE))
  {
    void *ret=NULL;

    /*There are some entries in the Queue.*/
    GFX_STRING_CACHE_INFO temp;
    UINT8 fl_inStrLength = (UINT8)HMI_STRLEN(p_cache_info_out->InString);
    (void)memset(temp.InString, (SINT32)'\0', sizeof(temp.InString));	
    (void)memset(temp.String, (SINT32)'\0', sizeof(temp.String));
    temp.StringLen = (UINT8)((UINT8)(GFX_MGR02_MAX_TEXT_LENGTH) + 1U);//Setting invalid length
    (void)HMI_STRNCPY(temp.InString, p_cache_info_out->InString, (UINT32)(fl_inStrLength));
    temp.FontId    = p_cache_info_out->FontId;
    temp.FontSize  = p_cache_info_out->FontSize;
    temp.ClipMode  = p_cache_info_out->ClipMode;
    temp.TextBoxWidth = p_cache_info_out->TextBoxWidth;
    temp.Alignment    = p_cache_info_out->Alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    temp.isScrolled   = p_cache_info_out->isScrolled; 
#endif 
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    temp.MaxShrink = p_cache_info_out->MaxShrink;
#endif
#if ((defined(GFX_MGR02_TXT_EFFECTS_ENABLED)) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
      temp.special_effects.effect_type = p_cache_info_out->special_effects.effect_type;
#endif
    ret = hmi_gfx_mgr02_cache_update_queue(&temp, (UINT8)(TRUE));
    if(ret != NULL)
    {
      p_cache_info_out->bmpWidth  = head->bmpWidth;
      p_cache_info_out->Buf       = head->Buf;
      p_cache_info_out->FontId    = head->FontId;
      p_cache_info_out->FontSize  = head->FontSize;
      p_cache_info_out->ClipMode  = head->ClipMode;
      p_cache_info_out->TextBoxWidth = head->TextBoxWidth;
      p_cache_info_out->Alignment = head->Alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      p_cache_info_out->isScrolled = head->isScrolled; 
#endif 
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
      p_cache_info_out->MaxShrink = head->MaxShrink;
#endif
#if ((defined(GFX_MGR02_TXT_EFFECTS_ENABLED)) &&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        p_cache_info_out->special_effects.effect_type = head->special_effects.effect_type;
#endif
      if (head->StringLen < (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
      {
        p_cache_info_out->StringLen = head->StringLen;
      }
      else
      {
        p_cache_info_out->StringLen = (UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
      }

      if (p_cache_info_out->StringLen <= (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
      {
        (void)HMI_STRNCPY(p_cache_info_out->String, head->String, (UINT32)p_cache_info_out->StringLen);
      }

      p_cache_info_out->String[p_cache_info_out->StringLen] = (HMI_CHAR)'\0';
      retValue = (UINT8)TRUE;
    }
  }
  return retValue;
}
#endif
#endif
void hmi_gfx_mgr02_add_string_in_cache_queue(GFX_STRING_CACHE_INFO *element)
{
    /*Search is not required here to find the existing content as 
    it is done in hmi_gfx_mgr02_get_string_cache_ptr() and
    if the string is not there only we will going to add the string in cache.*/
    if(cur_cache_size<(UINT32)GFX_MAX_NUM_STRINGS_TO_CACHE)
    {
        hmi_gfx_mgr02_cache_enqueue(element);
    }
    else if(cur_cache_size == (UINT32)GFX_MAX_NUM_STRINGS_TO_CACHE)
    {
#if (defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP))
       hmi_gfx_mgr02_imxrt_mem_mgmt_free(tail->Buf);
#elif (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2))
       hmi_gfx_mgr02_amber_mem_mgmt_free(tail->Buf);
#endif
        tail->Buf=NULL;
        hmi_gfx_mgr02_cache_dequeue();
        hmi_gfx_mgr02_cache_enqueue(element);
    }
    else
    {
      /*For fixing the MISRA warnings.*/
    }
}

static void hmi_gfx_mgr02_shutdown_string_cache(void)
{
    GFX_STRING_CACHE_INFO *temp=NULL;
    while(head!=NULL)
    {
      if(head->Buf!=NULL)
      {
#if (defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP))
        hmi_gfx_mgr02_imxrt_mem_mgmt_free(head->Buf);
#elif (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_TRAVEO2))
        hmi_gfx_mgr02_amber_mem_mgmt_free(head->Buf);
#endif
        head->Buf=NULL;
      }
      temp=head->Next;
      /* MISRA C-2012 Rule 21.3 disallows use of function free - Deviation Approved
       * the use of dynamic memory allocation (free) has been carefully considered here. 
       */
      free(head);
      head=temp;
    }
    head=NULL;
    tail=NULL;
    cur_cache_size=(UINT32)0;
}

#endif
#endif /* #if defined(GFX_MGR02_OPEN_GL)|| (defined(GFX_MGR02_OPEN_VG) && defined (GFX_MGR02_VG_TXT_CACHE_ENABLED)) */


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
 **
 ** CMS Rev 1.0      10-Dec-2016    CSAKTHIV
 ** Creation.
 **
 ** CMS Rev 1.1      23-Nov-2017    ARAJASE2
 ** RTC : 994906: P552 L1, L2 - OpenVG rendering texts are not displayed (Core Migration).
 ** Usage of GFX_MGR02_VG_CACHE_ENABLED macro is replaced with new macros
 ** GFX_MGR02_VG_IMG_CACHE_ENABLED and GFX_MGR02_VG_TXT_CACHE_ENABLED
 **
 ** CMS Rev 1.2      14-Mar-2018     ADEVI
 ** 1054545: Freetype cache implementation.
**
 **==========================================================================*/


/* end of file =============================================================*/
