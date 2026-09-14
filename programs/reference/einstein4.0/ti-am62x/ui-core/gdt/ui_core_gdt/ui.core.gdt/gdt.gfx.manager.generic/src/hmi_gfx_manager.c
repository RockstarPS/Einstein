/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

/*****************************************************************************
File Name        :  hmi_gfx_manager.c
Module Short Name:  GFX_MGR
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Graphics Manager for the GDT. This provides interfaces
                    for application to activate/deactivate screens, set/get dynamic
                    data
Organization     :  Driver Information Software Section,
                    Visteon Corporation
List the compiler name with the ersion number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :  ANSI C
Target Processor :  ANY
******************************************************************************/
#define HMI_GFX_MANAGER_C

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#include "hmi_gfx_manager.h"
#include "hmi_gfx_driver.h"
#include "hmi_gfx_mgr_font.h"
#include <math.h>
#include "string.h"

#ifdef GFX_MGR_NEED_INTERFACE_LAYER
 #include "hmi_gfx_interface.h"
#endif

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

#define GFX_SCREEN_CHANGED_BIT   (0x01)
#define GFX_BEGIN_UPDATE_BIT     (0x02)
/*
** Configurations used in the .cfg file
*/
#define GFX_BLOCK                (0x00)
#define GFX_PAINT_CHANGED        (0x01)
#define GFX_REPAINT              (0x02)
#define GFX_NONE                 (0x03)

#define GFX_TOUCH_PATH_END       (GFX_NB_ELEMENTS)

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*
** Bit operation macros to Check,Set and Clear the group font change flags
*/
#define GFX_MGR01_IS_CHANGED(flag_array, obj_id) ((((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) & (UINT8)(1<<(((UINT16)(obj_id))&0x07u))) != 0)
#define GFX_MGR01_SET_FLAG(flag_array, obj_id)   ((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]   |= (UINT8)(1<<(((UINT16)(obj_id))&0x07u)))
#define GFX_MGR01_CLR_FLAG(flag_array, obj_id)   (((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) &= (UINT8)~(UINT8)(1u<<(((UINT16)(obj_id))&0x07)))


/* Below macros were generated from 1BPP tool for OPEN VG support. In the latest
version of the GDT(rel-124BPPGDT-01.00.00), these macros are not generated as 
it does not support OPEN VG platform . So for backward compatibility, we are
defining with the default values */

#ifndef NB_DYN_XY_OVG
  #define NB_DYN_XY_OVG            0
#endif

#ifndef NB_SXY_OVG
  #define NB_SXY_OVG               0
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#if NB_DYN_ELEMENTS > 0
  /*
  ** Flag to indicate whether a dynamic object has changed..
  */
  static UINT8 l_dyn_element_changed_U8[NB_DYN_ELEMENTS];
  #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
    static GFX_SIZE_X_T l_dyn_screen_pos_x_S32[NB_PRIORITY];
    static GFX_SIZE_Y_T l_dyn_screen_pos_y_S32[NB_PRIORITY];
  #endif
  
#if NB_DYN_FILL_SCREENS > 0
  static COORDINATE_DEF_T l_fill_screen_dyn_property_S[NB_DYN_FILL_SCREENS];
  static FILL_SCREEN_DEF_T l_fill_screen_def_dyn_S[NB_DYN_FILL_SCREENS];
#endif
#if NB_DYN_XY_BITMAPS > 0
  static COORDINATE_DEF_T l_dyn_xy_bitmap_coord_S[NB_DYN_XY_BITMAPS];
#endif
#if NB_DYNXY_DIMAGES > 0
  static COORDINATE_DEF_T l_d_image_dyn_property_S[NB_DYNXY_DIMAGES];
#endif
#if NB_DYNXY_TEXTS > 0
  static GFX_TEXT_PROPERTY l_dyn_text_dyn_property_S[NB_DYNXY_TEXTS];
#endif
#if NB_DYNAMIC_CLIP_WIDGETS > 0
  static WIDGET_PROPERTY_T l_widget_dynamic_clip_list_SA[NB_DYNAMIC_CLIP_WIDGETS];
#endif
#if defined(NB_DYNXY_WIDGETS) && (NB_DYNXY_WIDGETS > 0)
  static WIDGET_DYNXY_PROPERTY_T l_dynxy_widget_list_SA[NB_DYNXY_WIDGETS];
#endif

#endif

#if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
static UINT8 l_font_elem_changed_flag_U8A[(GFX_MGR01_NUM_OF_FONTS+7)/8];
#endif

/*
** RAM to hold the screen ID for each of the screen priority.
*/
static UINT8 l_gfx_driver_notify_flag_U8;

#if NB_LAYERS > 1
  UINT8 gl_active_layer_id_U8;
#else
  #define gl_active_layer_id_U8 (0)
#endif
#if ((NB_PRIORITY > 1) || (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE  == GFX_PAINT_CHANGED))
  static UINT8 l_highest_active_priority_U8[NB_LAYERS];
#endif

#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    #define NO_OF_CLIP_AREAS 50
    RECTANGLE_DEF_T l_clip_area_list_S[NO_OF_CLIP_AREAS];
UINT8           l_clip_count_U8;
UINT8           l_temp_clip_count_U8;
UINT16          l_cur_bld_scr_pri_U16;
#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */

#if GFX_TOUCH_SCREEN_ENABLED > 0
  static WIDGET_TOUCH_INFO_DEF_T const * l_last_touch_area_SP;
  static UINT32                  l_tread_index_U32;
  static UINT32                  l_twrite_index_U32;
  static UINT32                  l_tcount_U32;
  static GFX_TOUCH_QDATA         l_touch_event_queue_S[GFX_TOUCH_EVENT_Q_SIZE];
 #if defined(WIN32) || defined(WINCE)
  static CRITICAL_SECTION        l_tcritical_section;
 #endif
#endif

/*****************************************************************************
*                       Locally used Constant Declarations                   *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
******************************************************************************/

#include "hmi_gfx_mgr_data.rom"

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/

#if (NB_STATIC_CLIP_AREA > 0) || (NB_DYNAMIC_CLIP_WIDGETS > 0) || ((GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) && (GFX_DRIVER_NEED_BMP_CLIPPING == YES))
 static RECTANGLE_DEF_T GfxManagerGetModifiedClipArea(RECTANGLE_DEF_T const p_clip_area);
#endif
#if NB_WIDGETS > 0
  static UINT8 GfxManagerCheckWidgetsChanged(WIDGET_DEF_T const * p_widget_ptr); 
 #ifdef GFX_ALIGNED_WIDGETS_ENABLED
  static void GfxManagerBuildAlignedWidget(WIDGET_DEF_T const * p_widget_ptr);
  static void GfxManagerBuildAlignedElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP,
                                            RECTANGLE_DEF_T      * p_size_SP,
                                            UINT8                  p_space_U8);
  void GfxManagerGetElementSizeInfo(GFX_ELEMENT_PROPERTY const * p_element_table_AP, RECTANGLE_DEF_T * p_size_SP);
  #if NB_ALL_BITMAPS > 0
    static void GfxManagerGetStaticXyBitmapInfo(GFX_ELEMENT_PROPERTY const * p_element_table_AP, GFX_ELEMENT_ID_T p_dyn_table_index, RECTANGLE_DEF_T * p_size_SP);
    static void GfxManagerBuildAlignedStaticXyBitmap(GFX_ELEMENT_PROPERTY const * p_element_table_AP, RECTANGLE_DEF_T * p_size_SP, UINT8 p_space_U8);
  #endif
 #endif
 #if (NB_DYN_WIDGETS > 0)
   static UINT8 GfxManagerGetSelectedWidgetId(GFX_ELEMENT_ID_T * p_dynamic_widget_id_P);
 #endif
#endif


#if GFX_PIX_FORMAT != GFX_SEG
  static UINT8 GfxManagerCheckElementChanged(WIDGET_DEF_T const * p_widget_ptr);
#endif

#if NB_WIDGETS > 0 || GFX_PIX_FORMAT != GFX_SEG
  static void GfxManagerBuildWidget(WIDGET_DEF_T const * p_widget_ptr);
  static void GfxManagerBuildElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP);
#endif

#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
static void GfxManagerUpdateClipData(COORDINATE_DEF_T const * coord,GFX_SIZE_W_T width,GFX_SIZE_H_T height);
static BOOLEAN GfxManagerUpdateClipList(RECTANGLE_DEF_T fl_clip_data);

static BOOLEAN GfxManagerBuildNormalScreen(SCREEN_ID_T fl_screen_id,UINT16 fl_count_U16,SCREEN_TABLE_T const * fl_screen_def_SP);
static BOOLEAN GfxManagerBuildClippedScreenUtility(SCREEN_ID_T fl_screen_id,UINT16 fl_count_U16,SCREEN_TABLE_T const * fl_screen_def_SP);
static BOOLEAN GfxManagerIsDynElementChanged(WIDGET_DEF_T const * p_widget_ptr);
static BOOLEAN GfxManagerBuildClippedScreen(WIDGET_DEF_T const * p_widget_ptr);
static void GfxManagerBuildClippedElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP);

#if NB_ALL_BITMAPS > 0
static void GfxManagerBuildClippedStaticXyBitmap(GFX_ELEMENT_PROPERTY const * p_elem_property_P, COORDINATE_DEF_T * p_coord_P);
#endif /* NB_ALL_BITMAPS > 0 */

static UINT8 GfxManagerCheckClipArea(RECTANGLE_DEF_T fl_image_area,UINT8 start_index);
static void GfxManagerReSetClipArea(void);
#if 0
static BOOLEAN GfxManagerCheckClipAreaOverlaps(RECTANGLE_DEF_T fl_clip_data);
#else
static UINT8 GfxManagerCheckClipAreaOverlaps(RECTANGLE_DEF_T fl_clip_data,UINT8 start_index);
#endif
static BOOLEAN GfxManagerUpdateClip(RECTANGLE_DEF_T fl_clip_data);

#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */

#if GFX_TOUCH_SCREEN_ENABLED > 0
  static void   GfxManagerTouchEventHandler(UINT16 x, UINT16 y, UINT8 touch_event);
  static UINT32 GfxManagerPopTouchEvent(GFX_TOUCH_QDATA * p_touch_data_SP);
#endif

static void GfxManagerScreenEventHandler(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data, UINT8 p_priority);
#ifdef GFX_MANAGER_AVOID_MULTIPLE_SCR_ADDN
static UINT8 GfxManagerGetCurScreenPriority(GFX_ELEMENT_ID_T p_element);
#endif


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

void GfxManager_set_screen_changed_status(void)
{
  (void)memset(&l_dyn_element_changed_U8[0], 0x01,NB_DYN_ELEMENTS );
}


/****************************************************************************
Function Name        : GfxManagerInitialize
Description          : This function initializes the graphics manager data.
                       So this function needs to be invoked during initialization
                       Application shall use the other API's only after
                       manager initialization is done.
Invocation           : Called when ever there is a need to initialize/re-initialize
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxManagerInitialize(void)
{
#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
  UINT8 fl_loop_count_U8;
#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
#if NB_PRIORITY > 1
   UINT16 fl_count_U16;
#endif
#if NB_LAYERS > 1
   UINT8  fl_lid_U8;
   gl_active_layer_id_U8 = NB_LAYERS;
   for(fl_lid_U8 = 0; fl_lid_U8 < NB_LAYERS; fl_lid_U8++)
#else
   UINT8 fl_lid_U8 = 0;
#endif
   {
   #if ((NB_PRIORITY > 1) || (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED))
     l_highest_active_priority_U8[fl_lid_U8] = NB_PRIORITY;
   #endif
   #if NB_PRIORITY > 1 
      for (fl_count_U16 = 0; fl_count_U16 < lc_layer_table_S[fl_lid_U8].nb_priority; fl_count_U16++)
   #endif
      {
      #if NB_PRIORITY > 1
         lc_layer_table_S[fl_lid_U8].psid_tptr[fl_count_U16] = NB_SCREENS;
      #else
         lc_layer_table_S[fl_lid_U8].psid_tptr[0] = NB_SCREENS;
      #endif
      }
   }
#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
  for(fl_loop_count_U8=0; fl_loop_count_U8 < NO_OF_CLIP_AREAS; fl_loop_count_U8++)
  {
    l_clip_area_list_S[fl_loop_count_U8].x = 0;
    l_clip_area_list_S[fl_loop_count_U8].y = 0;
    l_clip_area_list_S[fl_loop_count_U8].w = lc_layer_table_S[0].width;
    l_clip_area_list_S[fl_loop_count_U8].h = lc_layer_table_S[0].height;
  }
  l_clip_count_U8 = 0;
#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
  l_gfx_driver_notify_flag_U8 = 0;
#if GFX_TOUCH_SCREEN_ENABLED > 0
   l_last_touch_area_SP = 0;
   l_tread_index_U32    = 0;
   l_twrite_index_U32   = 0;
   l_tcount_U32         = 0;
 #if defined(WIN32) || defined(WINCE)
   InitializeCriticalSection(&l_tcritical_section);
 #endif
#endif
#ifdef GFX_MGR_NEED_INTERFACE_LAYER
   hmi_gfx_if_initialize(0);
#endif

#if NB_DYN_ELEMENTS > 0
  #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
    (void)memset(&l_dyn_screen_pos_x_S32[0], 0,NB_PRIORITY );
    (void)memset(&l_dyn_screen_pos_y_S32[0], 0,NB_PRIORITY );
  #endif

#if NB_DYN_FILL_SCREENS > 0
   (void)memcpy(&l_fill_screen_dyn_property_S, &lc_fill_screen_dyn_property_S, sizeof(l_fill_screen_dyn_property_S));
   (void)memcpy(&l_fill_screen_def_dyn_S, &lc_fill_screen_def_dyn_S, sizeof(l_fill_screen_def_dyn_S));	 
#endif
#if NB_DYN_XY_BITMAPS > 0
   (void)memcpy(&l_dyn_xy_bitmap_coord_S, &lc_dyn_xy_bitmap_coord_S, sizeof(l_dyn_xy_bitmap_coord_S));
#endif
#if NB_DYNXY_DIMAGES > 0
   (void)memcpy(&l_d_image_dyn_property_S, &lc_d_image_dyn_property_S, sizeof(l_d_image_dyn_property_S));
#endif
#if NB_DYNXY_TEXTS > 0
   (void)memcpy(&l_dyn_text_dyn_property_S, &lc_dyn_text_dyn_property_S, sizeof(l_dyn_text_dyn_property_S));
#endif
#if NB_DYNAMIC_CLIP_WIDGETS > 0
   (void)memcpy(&l_widget_dynamic_clip_list_SA, &lc_widget_dynamic_clip_list_SA, sizeof(l_widget_dynamic_clip_list_SA));
#endif
#endif
   GfxDriverInitialize();
}

/****************************************************************************
Function Name        : GfxManagerExit
Description          :
Invocation           :
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxManagerExit(void)
{
#if defined(WIN32) || defined(WINCE)
 #if GFX_TOUCH_SCREEN_ENABLED > 0
   DeleteCriticalSection(&l_tcritical_section);
 #endif
#endif
#ifdef GFX_MGR_NEED_INTERFACE_LAYER
   hmi_gfx_if_exit();
#endif
}

#if NB_DYN_ELEMENTS > 0
#ifdef GFX_OPEN_VG
/****************************************************************************
Function Name        : GfxManagerRotate
Description          : This functions sets transformation matrix to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerRotate(GFX_ELEMENT_ID_T p_element, VGfloat p_rotate)
{
   if((p_element >= MAX_INDEX_DYN_NFILL_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         VGfloat * fl_matrix = &l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].matrix[0];
         {
            fl_matrix[0] = cosf(p_rotate);
            fl_matrix[1] = sinf(p_rotate);
            fl_matrix[3] = -fl_matrix[1];
            fl_matrix[4] = fl_matrix[0];
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   }
}


/****************************************************************************
Function Name        : GfxManagerSetAlpha
Description          : This functions sets alpha value to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetAlpha(GFX_ELEMENT_ID_T p_element, VGfloat p_alpha)
{
   if((p_element >= MAX_INDEX_DYN_NFILL_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha != p_alpha)
         {
            l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha = p_alpha;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   }
}

/****************************************************************************
Function Name        : GfxManagerSetAlpha
Description          : This functions sets alpha value to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetReflection(GFX_ELEMENT_ID_T p_element, VGfloat p_distance, VGfloat p_height)
{
   if((p_element >= MAX_INDEX_DYN_NFILL_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].reflection_height != p_height)
         {
            l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].reflection_height = p_height;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
         if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].reflection_dist2surf != p_distance)
         {
            l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].reflection_dist2surf = p_distance;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   }
}


/****************************************************************************
Function Name        : GfxManagerRotate
Description          : This functions sets transformation matrix to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerScale(GFX_ELEMENT_ID_T p_element, VGfloat p_scale_x, VGfloat p_scale_y)
{
   if((p_element >= MAX_INDEX_DYN_NFILL_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         VGfloat * fl_matrix = &l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].matrix[0];
         {
            fl_matrix[0] = p_scale_x;
            fl_matrix[1] = 0;
            fl_matrix[3] = 0;
            fl_matrix[4] = p_scale_y;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   }
}

/****************************************************************************
Function Name        : GfxManagerRotate
Description          : This functions sets transformation matrix to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetMatrix(GFX_ELEMENT_ID_T p_element, VGfloat * matrix)
{
   if((p_element >= MAX_INDEX_DYN_WIDGETS_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < NB_DYN_XY_BITMAPS)
      {
         VGfloat * fl_matrix = &l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].matrix[0];
         {
            fl_matrix[0] = matrix[0];
            fl_matrix[1] = matrix[1];
            fl_matrix[2] = matrix[2];
            fl_matrix[3] = matrix[3];
            fl_matrix[4] = matrix[4];
            fl_matrix[5] = matrix[5];
            fl_matrix[6] = matrix[6];
            fl_matrix[7] = matrix[7];
            fl_matrix[8] = matrix[8];
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
   #if NB_DYN_XY_ALPHAMAP > 0
      if(fl_dyn_table_index < (NB_DYN_XY_BITMAPS+NB_DYN_XY_ALPHAMAP))
      {
         VGfloat * fl_matrix = &lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index-NB_DYN_XY_BITMAPS].matrix[0];
         {
            fl_matrix[0] = matrix[0];
            fl_matrix[1] = matrix[1];
            fl_matrix[2] = matrix[2];
            fl_matrix[3] = matrix[3];
            fl_matrix[4] = matrix[4];
            fl_matrix[5] = matrix[5];
            fl_matrix[6] = matrix[6];
            fl_matrix[7] = matrix[7];
            fl_matrix[8] = matrix[8];
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
   #if NB_DYN_XY_OVG > 0
      if(fl_dyn_table_index < (NB_DYN_XY_BITMAPS+NB_DYN_XY_ALPHAMAP+NB_DYN_XY_OVG))
      {
         VGfloat * fl_matrix = &lc_dyn_xy_ovg_coord_S[fl_dyn_table_index-(NB_DYN_XY_BITMAPS+NB_DYN_XY_ALPHAMAP)].matrix[0];
         {
            fl_matrix[0] = matrix[0];
            fl_matrix[1] = matrix[1];
            fl_matrix[2] = matrix[2];
            fl_matrix[3] = matrix[3];
            fl_matrix[4] = matrix[4];
            fl_matrix[5] = matrix[5];
            fl_matrix[6] = matrix[6];
            fl_matrix[7] = matrix[7];
            fl_matrix[8] = matrix[8];
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      if(p_element < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            VGfloat * fl_matrix = &l_widget_dynamic_clip_list_SA[p_element].matrix[0];
            fl_matrix[0] = matrix[0];
            fl_matrix[1] = matrix[1];
            fl_matrix[2] = matrix[2];
            fl_matrix[3] = matrix[3];
            fl_matrix[4] = matrix[4];
            fl_matrix[5] = matrix[5];
            fl_matrix[6] = matrix[6];
            fl_matrix[7] = matrix[7];
            fl_matrix[8] = matrix[8];
            l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
      {
      }
   }
}

/****************************************************************************
Function Name        : GfxManagerRotate
Description          : This functions sets transformation matrix to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerReSetMatrix(GFX_ELEMENT_ID_T p_element)
{
   if((p_element >= MAX_INDEX_DYN_WIDGETS_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         VGfloat * fl_matrix = &l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].matrix[0];
         {
            fl_matrix[0] = 1;
            fl_matrix[1] = 0;
            fl_matrix[2] = 0;
            fl_matrix[3] = 0;
            fl_matrix[4] = 1;
            fl_matrix[5] = 0;
            fl_matrix[6] = 0;
            fl_matrix[7] = 0;
            fl_matrix[8] = 1;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      if(p_element < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            VGfloat * fl_matrix = &l_widget_dynamic_clip_list_SA[p_element].matrix[0];
            fl_matrix[0] = 1;
            fl_matrix[1] = 0;
            fl_matrix[2] = 0;
            fl_matrix[3] = 0;
            fl_matrix[4] = 1;
            fl_matrix[5] = 0;
            fl_matrix[6] = 0;
            fl_matrix[7] = 0;
            fl_matrix[8] = 1;
            l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
      else
   #endif
      {
      }
   }
}

/****************************************************************************
Function Name        : GfxManagerRotate
Description          : This functions sets transformation matrix to the
                       specified element. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerTranslate(GFX_ELEMENT_ID_T p_element, VGfloat p_tx, VGfloat p_ty)
{
   if((p_element >= MAX_INDEX_DYN_NFILL_INDEX) && (p_element < MAX_INDEX_DYN_X_BITMAP_INDEX))
   {
      /*
      ** Dynamic XY bitmap index
      */
      GFX_ELEMENT_ID_T fl_dyn_table_index = (p_element-MAX_INDEX_DYN_NFILL_INDEX);
   #if NB_DYN_XY_BITMAPS > 0
      if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
      {
         VGfloat * fl_matrix = &l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].matrix[0];
         {
            fl_matrix[0] = 1;
            fl_matrix[1] = 0;
            fl_matrix[3] = 0;
            fl_matrix[4] = 1;
            fl_matrix[6] = p_tx;
            fl_matrix[7] = p_ty;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   }
}
#endif /*#ifdef GFX_OPEN_VG*/

/****************************************************************************
Function Name        : GfxManagerSetDynScreenPriority
Description          : This functions sets the priority of the screen dynamically.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element(Screen ID) and event data to be set
                       in p_data(Activate/Deactivate), priority(New priority of screen)
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetDynScreenPriority(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data, UINT8 p_priority)
{
  if(p_element < MAX_DYNAMIC_ELEMENT_INDEX)
  {
    if(p_element < MAX_INDEX_SCREEN_INDEX)
    {
      #if NB_LAYERS > 1
      SCREEN_TABLE_T const * fl_screen_def_SP         = &lc_screen_table_S[p_element];
      LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[fl_screen_def_SP->layerid];
      #else
      LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[0];
      #endif
      if(p_priority < fl_active_layer_table_SP->nb_priority)
      {
          GfxManagerScreenEventHandler(p_element, p_data, p_priority);
      }
    }
  }
}


#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
/****************************************************************************
Function Name        : GfxManagerSetScreenDynPosition
Description          : This functions sets the x and y position of the screen with
                       the passed values.  The screen priority is found and the x and
                       y values are changed for that priority.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element(Screen ID) and x position
                       in p_pos_x, y position in p_pos_y
Return Value         : None.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetScreenDynPosition(GFX_ELEMENT_ID_T p_element, GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y)
{
  UINT8 fl_priority_U8;

  if(p_element < MAX_DYNAMIC_ELEMENT_INDEX)
  {
    if(p_element < MAX_INDEX_SCREEN_INDEX)
    {
      #if (NB_LAYERS > 1) && (NB_PRIORITY > 1)
        SCREEN_TABLE_T const * fl_screen_def_SP         = &lc_screen_table_S[p_element];
        LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[fl_screen_def_SP->layerid];
      #else
        LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[0];
      #endif
      #if NB_PRIORITY > 1
      for(fl_priority_U8=0; fl_priority_U8 < NB_PRIORITY; fl_priority_U8++)
      #endif
      {
        #if NB_PRIORITY > 1
          if(p_element == fl_active_layer_table_SP->psid_tptr[fl_priority_U8])
          {
            break;
          }
        #else
          fl_priority_U8 = 0;
        #endif
       }
       if(fl_priority_U8 < NB_PRIORITY)
       {
         l_dyn_screen_pos_x_S32[fl_priority_U8] = p_pos_x;
         l_dyn_screen_pos_y_S32[fl_priority_U8] = p_pos_y;
         l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
       }
    }
  }
}
#endif


#ifdef GFX_MANAGER_AVOID_MULTIPLE_SCR_ADDN
/****************************************************************************
Function Name        : GfxManagerGetCurScreenPriority
Description          : This functions searches the layer pointer table and gets
                       the current priority of the element. If element is not found
                       then nb_priority is returned.
Invocation           : Invoked by GfxManagerScreenEventHandler
Parameters           : element identifier in p_element
Return Value         : Priority.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
static UINT8 GfxManagerGetCurScreenPriority(GFX_ELEMENT_ID_T p_element)
{
    UINT8 fl_cur_priority_U8;

    #if NB_LAYERS > 1
      SCREEN_TABLE_T const * fl_screen_def_SP         = &lc_screen_table_S[p_element];
      LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[fl_screen_def_SP->layerid];
    #else
      LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[0];
    #endif

    #if NB_PRIORITY > 1
    for(fl_cur_priority_U8=0; fl_cur_priority_U8 < fl_active_layer_table_SP->nb_priority; fl_cur_priority_U8++)
    #else
    fl_cur_priority_U8 = 0;
    #endif
    {
      if(fl_active_layer_table_SP->psid_tptr[fl_cur_priority_U8] == p_element)
      {
          break;
      }
      #if NB_PRIORITY < 1
      else
      {
          fl_cur_priority_U8 = fl_active_layer_table_SP->nb_priority;
      }
      #endif
    }
    return fl_cur_priority_U8;
}
#endif

/****************************************************************************
Function Name        : GfxManagerScreenEventHandler
Description          : This functions handles the activate or remove events for a screen.
Invocation           : Invoked by GfxManagerSendEvent or GfxManagerSetDynScrenPriority
Parameters           : element identifier in p_element and event data to be set
                       in p_data and priority
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
static void GfxManagerScreenEventHandler(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data, UINT8 p_priority)
{
#if NB_PRIORITY > 1
   UINT8 fl_priority;
#endif
      #if NB_LAYERS > 1
         SCREEN_TABLE_T const * fl_screen_def_SP         = &lc_screen_table_S[p_element];
         LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[fl_screen_def_SP->layerid];
      #else
         LAYER_TABLE_T  const * fl_active_layer_table_SP = &lc_layer_table_S[0];
      #endif


         if(p_data == GFX_REMOVE_SCREEN_EV)
         {
            if(fl_active_layer_table_SP->psid_tptr[p_priority] == p_element)
            {
               l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               fl_active_layer_table_SP->psid_tptr[p_priority] = NB_SCREENS;
            #if NB_PRIORITY > 1
             #if NB_LAYERS > 1
               fl_priority = l_highest_active_priority_U8[fl_screen_def_SP->layerid];
               l_highest_active_priority_U8[fl_screen_def_SP->layerid] = NB_PRIORITY;
             #else
               fl_priority = l_highest_active_priority_U8[0];
               l_highest_active_priority_U8[0] = NB_PRIORITY;
             #endif
               if(fl_priority < NB_PRIORITY)
               {
                  /*
                  ** A screen is removed, so refresh all the active priority screens and
                  ** also find the next high priority screen active.
                  */
                  fl_priority++; /* to make sure we run through all the priorities */
                  while(fl_priority != 0)
                  {
                     fl_priority--;
                     p_element = fl_active_layer_table_SP->psid_tptr[fl_priority];
                     if(p_element != NB_SCREENS)
                     {
                     #if NB_LAYERS > 1
                        if(l_highest_active_priority_U8[fl_screen_def_SP->layerid] == NB_PRIORITY)
                        {
                           /* Assign the next highest priority */
                           l_highest_active_priority_U8[fl_screen_def_SP->layerid] = fl_priority;
                        }
                     #else
                        if(l_highest_active_priority_U8[0] == NB_PRIORITY)
                        {
                           l_highest_active_priority_U8[0] = fl_priority;
                        }
                     #endif
                        l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
                     }
                  }
               }
            #endif /* #if NB_PRIORITY > 1 */
            }
            #ifdef GFX_MANAGER_AVOID_MULTIPLE_SCR_ADDN
            else
            {
              UINT8 fl_cur_priority;
              fl_cur_priority = GfxManagerGetCurScreenPriority(p_element);
              if(fl_cur_priority < fl_active_layer_table_SP->nb_priority)
              {
              GfxManagerScreenEventHandler(p_element, GFX_REMOVE_SCREEN_EV, fl_cur_priority);
              }
            }
            #endif
         }
         else if(fl_active_layer_table_SP->psid_tptr[p_priority] != p_element)
         {
          #ifdef GFX_MANAGER_AVOID_MULTIPLE_SCR_ADDN
            UINT8 fl_cur_priority;
            fl_cur_priority = GfxManagerGetCurScreenPriority(p_element);
            if(fl_cur_priority < fl_active_layer_table_SP->nb_priority)
            {
              GfxManagerScreenEventHandler(p_element, GFX_REMOVE_SCREEN_EV, fl_cur_priority);
            }
          #endif
            /*
            ** New Screen for this priority
            */

            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
            fl_active_layer_table_SP->psid_tptr[p_priority] = p_element;
         #if NB_PRIORITY > 1
            fl_priority = NB_PRIORITY;
           #if NB_LAYERS > 1
            if(l_highest_active_priority_U8[fl_screen_def_SP->layerid] == NB_PRIORITY)
            {
               /*
               ** This is the first screen to get activated.
               */
               l_highest_active_priority_U8[fl_screen_def_SP->layerid] = p_priority;
            }
            else if(p_priority > l_highest_active_priority_U8[fl_screen_def_SP->layerid])
            {
               /*
               ** This screen has high priority than already active screens.
               */
               l_highest_active_priority_U8[fl_screen_def_SP->layerid] = p_priority;
            }
            else
            {
               /*
               ** This screen has same or lower piority than existing screens.
               ** So a refresh would be needed for all the active screens
               */
               fl_priority = l_highest_active_priority_U8[fl_screen_def_SP->layerid];
            }
           #else
            if(l_highest_active_priority_U8[0] == NB_PRIORITY)
            {
               /*
               ** This is the first screen to get activated.
               */
               l_highest_active_priority_U8[0] = p_priority;
            }
            else if(p_priority > l_highest_active_priority_U8[0])
            {
               /*
               ** This screen has high priority than already active screens.
               */
               l_highest_active_priority_U8[0] = p_priority;
            }
            else
            {
               /*
               ** This screen has same or lower piority than existing screens.
               ** So a refresh would be needed for all the active screens
               */
               fl_priority = l_highest_active_priority_U8[0];
            }
           #endif
            if(fl_priority < NB_PRIORITY)
            {
               fl_priority++;
               while(fl_priority != 0)
               {
                  fl_priority--;
                  p_element = fl_active_layer_table_SP->psid_tptr[fl_priority];
                  if(p_element != NB_SCREENS)
                  {
                     l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
                  }
               }
            }
         #endif /* #if NB_PRIORITY > 1 */
         }

         else
         {
            /*
            ** Ignore as there is no change in screen
            */
         }
}

/****************************************************************************
Function Name        : GfxManagerSendEvent
Description          : This functions sets event data to the specified element
                       identifier. If the event data is different than the
                       current event data maintained by manager, then a changed
                       flag is also set to cause a screen refresh.
Invocation           : Invoked by application when ever required.
Parameters           : element identifier in p_element and event data to be set
                       in p_data
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSendEvent(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data)
{
#if NB_DYN_ELEMENTS > NB_SCREENS
   GFX_ELEMENT_ID_T fl_dyn_table_index;
#endif

   if(p_element < MAX_DYNAMIC_ELEMENT_INDEX)
   {
      if(p_element < MAX_INDEX_SCREEN_INDEX)
      {
         if(p_data == GFX_REFRESH_SCREEN_EV)
         {
            /* issue a rebuild of the screen */
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
        else
        {
          UINT8 fl_screen_priority;
          SCREEN_TABLE_T const * fl_screen_def_SP  = &lc_screen_table_S[p_element];
          fl_screen_priority = fl_screen_def_SP->priority;
          GfxManagerScreenEventHandler(p_element, p_data, fl_screen_priority);
        }
        }
   #if NB_DYN_BITMAPS > 0
      else if(p_element < MAX_INDEX_DYN_BITMAPS_INDEX)
      {
         fl_dyn_table_index = GET_DYN_BITMAPS_INDEX(p_element);

         if(l_cur_dyn_bitmap_S[fl_dyn_table_index] != p_data)
         {
            l_cur_dyn_bitmap_S[fl_dyn_table_index]  = (DYN_BITMAP_DATA_T)p_data;
            l_dyn_element_changed_U8[p_element]    |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   #if NB_DYN_TEXTS > 0
      else if(p_element < MAX_INDEX_DYN_TEXTS_INDEX)
      {
         fl_dyn_table_index = GET_DYN_TEXTS_INDEX(p_element);

         if(p_data == 0)
         {
            /* Clean the Dynamic Text */
            if(*lc_dyn_text_def_S[fl_dyn_table_index].data_ptr != 0U)
            {
               *lc_dyn_text_def_S[fl_dyn_table_index].data_ptr = 0U;
               l_dyn_element_changed_U8[p_element]            |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
         else
         {
            /* Issue a refresh of the text */
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   #if NB_DYN_WIDGETS > 0
      else if(p_element < MAX_INDEX_DYN_WIDGETS_INDEX)
      {
         fl_dyn_table_index = GET_DYN_WIDGETS_INDEX(p_element);

         if(l_dyn_widget_S[fl_dyn_table_index] != p_data)
         {
            l_dyn_widget_S[fl_dyn_table_index]  = (DYN_WIDGET_DATA_T)p_data;
            l_dyn_element_changed_U8[p_element]|= GFX_SCREEN_CHANGED_FLAG;
         }
      }
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      else if(p_element < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
      {
      }
   #endif
   #if NB_DYN_FILL_SCREENS > 0
      else if(p_element < MAX_INDEX_DYN_NFILL_INDEX)
      {
         l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
      }
   #endif
   #if NB_ALL_DYN_XY_BITMAPS > 0
      else if(p_element < MAX_INDEX_DYN_XY_BITMAP_INDEX)
      {
         fl_dyn_table_index = GET_DYN_XY_BITMAPS_INDEX(p_element);
         if(fl_dyn_table_index < NB_ALL_DYN_XY_BITMAPS)
         {
         #if NB_DYN_XY_BITMAPS > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
            {
               if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_ALPHAMAP > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
            #endif
               if(lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_OVG > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_OVGMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
            #endif
               if(lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_COLORTRANSBITMAP > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
            #endif
               if(lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_ALPHABITMAP > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
            #endif
               if(lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHAMAP > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
            #endif
               if(lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHABITMAP > 0
            if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX > 0
               fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
            #endif
               if(lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].x != (GFX_SIZE_X_T)(p_data))
               {
                  lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].x = (GFX_SIZE_X_T)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            }
            else
         #endif
            {
            }
         }
         else
         {
			fl_dyn_table_index = GET_DYN_Y_BITMAPS_INDEX(p_element);
			p_element          -= NB_ALL_DYN_XY_BITMAPS;
			if(fl_dyn_table_index < NB_ALL_DYN_XY_BITMAPS)
			{
				 #if NB_DYN_XY_BITMAPS > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
					{
					   if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_ALPHAMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
					#endif
					   if(lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_OVG > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_OVGMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_COLORTRANSBITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_ALPHABITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
					#endif
					   if(lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_UNIALPHAMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
					#endif
					   if(lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_UNIALPHABITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].y != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].y = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
					{
					}
				}
				else
				{
               if(p_data <= GFX_PIX_FORMAT_ALPHA)
               {

				fl_dyn_table_index -= NB_ALL_DYN_XY_BITMAPS;
				p_element          -= NB_ALL_DYN_XY_BITMAPS;				
				 #if NB_DYN_XY_BITMAPS > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
					{
					   if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_ALPHAMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
					#endif
					   if(lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_alphamap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_OVG > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_OVGMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_ovg_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_COLORTRANSBITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_colortransbitmap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_ALPHABITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
					#endif
					   if(lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_alphabitmap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_UNIALPHAMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
					#endif
					   if(lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_unialphamap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
				 #if NB_DYN_XY_UNIALPHABITMAP > 0
					if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX)
					{
					#if MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX > 0
					   fl_dyn_table_index -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
					#endif
					   if(lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].alpha != (GFX_SIZE_Y_T)(p_data))
					   {
						  lc_dyn_xy_unialphabitmap_coord_S[fl_dyn_table_index].alpha = (GFX_SIZE_Y_T)(p_data);
						  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
					   }
					}
					else
				 #endif
					{
					}
				}
         }
         }
      }
   #endif
   #if NB_DYNXY_DIMAGES > 0
      else if(p_element < MAX_INDEX_DYN_X_DBITMAP_INDEX)
      {
         p_element -= MAX_INDEX_DYN_XY_BITMAP_INDEX;
         if(p_element < NB_DYNXY_DIMAGES)
         {
            if((GFX_SIZE_X_T)(p_data) != l_d_image_dyn_property_S[p_element].x)
            {
               l_d_image_dyn_property_S[p_element].x  = (GFX_SIZE_X_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_Y_DBITMAP_INDEX)
      {
         p_element -= MAX_INDEX_DYN_X_DBITMAP_INDEX;
         if(p_element < NB_DYNXY_DIMAGES)
         {
            if((GFX_SIZE_Y_T)(p_data) != l_d_image_dyn_property_S[p_element].y)
            {
               l_d_image_dyn_property_S[p_element].y  = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_ALPHA_DBITMAP_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_DBITMAP_INDEX;
         if(p_element < NB_DYNXY_DIMAGES)
         {
            if(((GFX_COLOR_T)(p_data) != l_d_image_dyn_property_S[p_element].alpha) &&
			    (p_data <= GFX_PIX_FORMAT_ALPHA))
            {
               l_d_image_dyn_property_S[p_element].alpha  = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }      
   #endif
   #if NB_DYNXY_TEXTS > 0
      else if(p_element < MAX_INDEX_DYN_X_DTEXT_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_DBITMAP_INDEX;
         if(p_element < NB_DYNXY_TEXTS)
         {
            if((GFX_SIZE_X_T)(p_data) != l_dyn_text_dyn_property_S[p_element].coord.x)
            {
               l_dyn_text_dyn_property_S[p_element].coord.x = (GFX_SIZE_X_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_Y_DTEXT_INDEX)
      {
         p_element -= MAX_INDEX_DYN_X_DTEXT_INDEX;
         if(p_element < NB_DYNXY_TEXTS)
         {
            if((GFX_SIZE_Y_T)(p_data) != l_dyn_text_dyn_property_S[p_element].coord.y)
            {
               l_dyn_text_dyn_property_S[p_element].coord.y = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_ALPHA_DTEXT_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_DTEXT_INDEX;
         if(p_element < NB_DYNXY_TEXTS)
         {
            if(((GFX_SIZE_Y_T)(p_data) != l_dyn_text_dyn_property_S[p_element].coord.alpha)&&
            (p_data <= GFX_PIX_FORMAT_ALPHA))
            {
               l_dyn_text_dyn_property_S[p_element].coord.alpha = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }      
      else if(p_element < MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX)
      {
         p_element -= MAX_INDEX_DYN_ALPHA_DTEXT_INDEX;
         if(p_element < NB_DYNXY_TEXTS)
         {
            if((GFX_COLOR_T)(p_data) != l_dyn_text_dyn_property_S[p_element].draw_color)
            {
               l_dyn_text_dyn_property_S[p_element].draw_color = (GFX_COLOR_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
    #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      else if(p_element < MAX_INDEX_DYN_NBLINES_DTEXT_INDEX)
      {
         p_element -= MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX;
         if(p_element < NB_DYNXY_TEXTS)
         {
            if(p_data != l_dyn_text_dyn_property_S[p_element].nb_lines)
            {
               l_dyn_text_dyn_property_S[p_element].nb_lines = (UINT8)p_data;
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
    #endif
   #endif
   #if NB_DYN_FILL_SCREENS > 0
      else if(p_element < MAX_INDEX_DYN_X_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_NBLINES_DTEXT_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
            if((GFX_SIZE_X_T)(p_data) != l_fill_screen_dyn_property_S[p_element].x)
            {
               l_fill_screen_dyn_property_S[p_element].x = (GFX_SIZE_X_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_Y_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_X_NFILL_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
            if((GFX_SIZE_Y_T)(p_data) != l_fill_screen_dyn_property_S[p_element].y)
            {
               l_fill_screen_dyn_property_S[p_element].y = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_W_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_NFILL_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
            if((GFX_SIZE_W_T)(p_data) != l_fill_screen_def_dyn_S[p_element].width)
            {
               l_fill_screen_def_dyn_S[p_element].width = (GFX_SIZE_W_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_H_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_W_NFILL_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
            if((GFX_SIZE_H_T)(p_data) != l_fill_screen_def_dyn_S[p_element].height)
            {
               l_fill_screen_def_dyn_S[p_element].height = (GFX_SIZE_H_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_ALPHA_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_H_NFILL_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
            if(((GFX_SIZE_Y_T)(p_data) != l_fill_screen_dyn_property_S[p_element].alpha) &&
            (p_data <= GFX_PIX_FORMAT_ALPHA))
            {
               l_fill_screen_dyn_property_S[p_element].alpha = (UINT8)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }      
      else if(p_element < MAX_INDEX_DYN_COLOR_NFILL_INDEX)
      {
         p_element -= MAX_INDEX_DYN_ALPHA_NFILL_INDEX;
         if(p_element < NB_DYN_FILL_SCREENS)
         {
			#ifdef GFX_MGR_USE_INT_RGB
            if((GFX_COLOR_T)(p_data) != l_fill_screen_def_dyn_S[p_element].color)
            {
               l_fill_screen_def_dyn_S[p_element].color = (GFX_COLOR_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         #else
            float a = ((float)((UINT8)p_data >> 24))/255.0f;
            float r = ((float)((UINT8)p_data >> 16))/255.0f;
            float g = ((float)((UINT8)p_data >> 8))/255.0f;
            float b = ((float)((UINT8)p_data))/255.0f;
            if(a != l_fill_screen_def_dyn_S[p_element].color[3])
            {
               l_fill_screen_def_dyn_S[p_element].color[3] = a;
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
            if(r != l_fill_screen_def_dyn_S[p_element].color[0])
            {
               l_fill_screen_def_dyn_S[p_element].color[0] = r;
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
            if(g != l_fill_screen_def_dyn_S[p_element].color[1])
            {
               l_fill_screen_def_dyn_S[p_element].color[1] = g;
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
            if(b != l_fill_screen_def_dyn_S[p_element].color[2])
            {
               l_fill_screen_def_dyn_S[p_element].color[2] = b;
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         #endif
         }
      }
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      else if(p_element < MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_COLOR_NFILL_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_X_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].clip.x)
            {
               l_widget_dynamic_clip_list_SA[p_element].clip.x = (GFX_SIZE_X_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_Y_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].clip.y)
            {
               l_widget_dynamic_clip_list_SA[p_element].clip.y = (GFX_SIZE_Y_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_W_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].clip.w)
            {
               l_widget_dynamic_clip_list_SA[p_element].clip.w = (GFX_SIZE_W_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_H_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].clip.h)
            {
               l_widget_dynamic_clip_list_SA[p_element].clip.h = (GFX_SIZE_H_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_X_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_X_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].dyn_prop.x)
            {
               l_widget_dynamic_clip_list_SA[p_element].dyn_prop.x = (GFX_SIZE_H_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }
         }
      }
      else if(p_element < MAX_INDEX_DYN_Y_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_X_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if((GFX_SIZE_Y_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].dyn_prop.y)
            {
               l_widget_dynamic_clip_list_SA[p_element].dyn_prop.y = (GFX_SIZE_H_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }         
         }
      } 
      else if(p_element < MAX_INDEX_DYN_ALPHA_WIDGETS_INDEX)
      {
         p_element -= MAX_INDEX_DYN_Y_WIDGETS_INDEX;
         if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            if(((GFX_COLOR_T)(p_data) != l_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha) &&
            (p_data <= GFX_PIX_FORMAT_ALPHA))	
            {
               l_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha = (GFX_SIZE_H_T)(p_data);
               l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
            }         
         }
      }              
   #endif
   #if NB_DYN_ELEMENTS > NB_SCREENS
      else
      {
         /*do nothing*/
      }
   #endif
   }
 #if (GFX_SCROLABLE_TEXT_SUPPORT != 0) && (NB_DYN_TEXTS > 0)
   else
   {
      /*
      ** Handle the scroll offset event for dynamic text.
      */
      if(p_element < MAX_INDEX_SCROLL_INDEX)
      {
         p_element -= MAX_INDEX_STEXTS_INDEX;
         if(p_element < NB_DYN_TEXTS)
         {
            DYN_TEXT_DEF_T const * fl_text_SP = &lc_dyn_text_def_S[p_element];
            GFX_CHAR             * fl_data_P;
            if((fl_text_SP->properties & GFX_TEXT_PROPERTY_SCROLABLE) != 0)
            {
               fl_data_P = &fl_text_SP->data_ptr[fl_text_SP->length+1];
            #if GFX_UNICODE_ENABLED
               if(*fl_data_P != p_data)
               {
                  *fl_data_P = p_data;
                  l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
               }
            #else
               p_element += MAX_INDEX_DYN_BITMAPS_INDEX;
               if(*fl_data_P != (GFX_CHAR)(p_data>>8))
               {
                  *fl_data_P = (GFX_CHAR)(p_data>>8);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
               fl_data_P++;
               if(*fl_data_P != (GFX_CHAR)(p_data))
               {
                  *fl_data_P = (GFX_CHAR)(p_data);
                  l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               }
            #endif
            }
         }
      }
   }
 #endif
}
#endif

#if NB_DYN_TEXTS > 0
/****************************************************************************
Function Name        : GfxManagerSendText
Description          : This function copies the passed string in to the
                       string buffer of the passed dynamic text element.
                       A data changed flag is set if the passed text is
                       different than what is set currently in the elements
                       string buffer.
Invocation           : When ever needed.
Parameters           : Dynamic text element identifier in p_element and new
                       string in p_str.
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSendText(GFX_ELEMENT_ID_T p_element, GFX_CHAR const * p_str)
{
   GFX_ELEMENT_ID_T   fl_dyn_table_index;
   GFX_CHAR         * fl_str_ptr;
   GFX_TEXT_LENGTH_T  fl_dest_length;
   UINT8              fl_str_changed_U8;
   GFX_CHAR const    * fl_str;

   if((p_element >= MAX_INDEX_DYN_BITMAPS_INDEX) && (p_element < MAX_INDEX_DYN_TEXTS_INDEX))
   {
      fl_dyn_table_index = GET_DYN_TEXTS_INDEX(p_element);
      fl_str_ptr         = lc_dyn_text_def_S[fl_dyn_table_index].data_ptr;
      fl_dest_length     = lc_dyn_text_def_S[fl_dyn_table_index].length;
      fl_str_changed_U8  = 0;
      fl_str             = p_str;
      while((fl_dest_length != 0U) && (*fl_str != 0U))
      {
         if(*fl_str != *fl_str_ptr)
         {
            *fl_str_ptr = *fl_str;
            fl_str_changed_U8 = 1U;
         }
         fl_str_ptr++;
         fl_str++;
         fl_dest_length--;
      }
      if(*fl_str_ptr != 0U)
      {
         *fl_str_ptr = 0;
         fl_str_changed_U8 = 1U;
      }
      if(fl_str_changed_U8 != FALSE)
      {
         l_dyn_element_changed_U8[p_element]|= GFX_SCREEN_CHANGED_FLAG;
      }
   }
}
#endif /*#if NB_DYN_TEXTS > 0*/

#if (GFX_PIX_FORMAT == GFX_1BPP_SEG)||(GFX_PIX_FORMAT == GFX_SEG)
#if NB_DYN_BITMAPS > 0

#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
/****************************************************************************
Function Name        : GfxManagerSetTextColor
Description          : This function sets the text color for the segments
                       icon is nothing but a dynamic image either
                       available or not available.
Invocation           : When ever needed.
Return Value         : None.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetTextColor(GFX_ELEMENT_ID_T p_element, GFX_SEG_COLOR p_color_value)
{
   GFX_ELEMENT_ID_T fl_dyn_table_index;
   DYN_TEXT_DEF_T const *fl_text_SP;
   GFX_SEG_COLOR *fl_seg_color;

   if ((p_element >= MAX_INDEX_DYN_BITMAPS_INDEX) && (p_element < MAX_INDEX_DYN_TEXTS_INDEX))
   {    
	
      fl_dyn_table_index = GET_DYN_TEXTS_INDEX(p_element);
      fl_text_SP = &lc_dyn_text_def_S[fl_dyn_table_index];
      fl_seg_color = fl_text_SP->seg_color;
         if (*fl_seg_color != p_color_value)
         {
            *fl_seg_color = p_color_value;
         }      
	
   }
}
#endif

/****************************************************************************
Function Name        : GfxManagerSetIcon
Description          : This function sets the icon state to on or off.
                       icon is nothing but a dynamic image either
                       available or not available.
Invocation           : When ever needed.
Parameters           : Dynamic text element identifier in p_element and new
                       icon state in state_b.
Return Value         : None.
Critical Section     : Shall not be invoked while GfxManagerBuildSegmentScreen in progress.
External Interfaces  : None.
******************************************************************************/
void GfxManagerSetIcon(GFX_ELEMENT_ID_T p_element,
#if defined(GFX_MGR01_MULTI_COLOR_SUPPORT)
                       GFX_SEG_COLOR color_value
#else
                       BOOLEAN state_b
#endif
)
{
   GFX_ELEMENT_ID_T   fl_element_id_E;
   UINT8              layer_no;

   if((p_element >= MAX_INDEX_SCREEN_INDEX) && 
      (p_element < MAX_INDEX_DYN_BITMAPS_INDEX))
   {
	   
      UINT8 fl_byte_U8;
#ifndef GFX_MGR01_MULTI_COLOR_SUPPORT
      UINT8 fl_bit_U8;
#endif

      fl_element_id_E = GET_DYN_BITMAPS_INDEX(p_element);

#ifndef GFX_MGR01_MULTI_COLOR_SUPPORT
      fl_byte_U8 = (UINT8)((fl_element_id_E & 0xFFF8U) >> 3u);
      fl_bit_U8 = (UINT8)(1 << (fl_element_id_E & 0x07U));
#else
      fl_byte_U8 = (UINT8)(fl_element_id_E >> 1u); 
#endif

      for(layer_no = 0U; layer_no < NB_LAYERS;layer_no++)
      {
         if (lc_layer_table_S[layer_no].layer_type == GFX_SEG)
         {
#if defined(GFX_MGR01_MULTI_COLOR_SUPPORT)
            UINT8 fl_current_byte = lc_layer_table_S[layer_no].icon_mask[fl_byte_U8];
            UINT8 fl_segment_id = (UINT8)(fl_element_id_E & 1u);
            UINT8 fl_new_byte = GfxDriverSegmentUpdateColor(fl_current_byte, color_value, (fl_segment_id));
           
            if (fl_new_byte != fl_current_byte)
            {
               lc_layer_table_S[layer_no].icon_mask[fl_byte_U8] = fl_new_byte;
               l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
            }
#else
            UINT8 fl_current_bit_U8 = lc_layer_table_S[layer_no].icon_mask[fl_byte_U8] & fl_bit_U8;
            UINT8 fl_prev_bit_U8 = state_b << (fl_element_id_E & 0x07U);

            if (fl_prev_bit_U8 != fl_current_bit_U8)
            {
               l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
               /*Clear the Icon*/
               if (state_b == 0U)
               {
                  lc_layer_table_S[layer_no].icon_mask[fl_byte_U8] &= ~fl_bit_U8;
               }
               else /*Set the Icon*/
               {
                  lc_layer_table_S[layer_no].icon_mask[fl_byte_U8] |= fl_bit_U8;
               }
            }
#endif
         }
      }       
   }
}
#endif
#endif /*#if GFX_PIX_FORMAT == GFX_1BPP_SEG || GFX_PIX_FORMAT == GFX_SEG*/

#if NB_DYN_ELEMENTS > NB_SCREENS
/****************************************************************************
Function Name        : GfxManagerGetEvent
Description          : This function returns the passed elements last set
                       event data. The event data is written to passed p_data
Invocation           : Invoked by application when ever required.
Parameters           : Element ID in p_element and Pointer to GFX_ELEMENT_DATA_T
                       where this function can write the event data.
Return Value         : TRUE if success, FALSE otherwise.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
UINT8 GfxManagerGetEvent(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T * p_data)
{
   UINT8 fl_read_status_U8 = FALSE;
   GFX_ELEMENT_ID_T fl_element = p_element;
   if(fl_element < MAX_DYNAMIC_ELEMENT_INDEX)
   {
      if(fl_element < MAX_INDEX_SCREEN_INDEX)
      {
      }
   #if NB_DYN_BITMAPS > 0
      else if(fl_element < MAX_INDEX_DYN_BITMAPS_INDEX)
      {
         fl_element         = GET_DYN_BITMAPS_INDEX(fl_element);
         *p_data           = l_cur_dyn_bitmap_S[fl_element];
         fl_read_status_U8 = TRUE;
      }
   #endif
   #if NB_DYN_TEXTS > 0
      else if(fl_element < MAX_INDEX_DYN_TEXTS_INDEX)
      {
      }
   #endif
   #if NB_DYN_WIDGETS > 0
      else if(fl_element < MAX_INDEX_DYN_WIDGETS_INDEX)
      {
         fl_element = GET_DYN_WIDGETS_INDEX(fl_element);
         *p_data   = l_dyn_widget_S[fl_element];
         fl_read_status_U8 = TRUE;
      }
   #endif
   #if NB_DYN_FILL_SCREENS > 0 || NB_DYNAMIC_CLIP_WIDGETS > 0
      else if(fl_element < MAX_INDEX_DYN_NFILL_INDEX)
      {
      }
   #endif
   #if NB_ALL_DYN_XY_BITMAPS > 0
      else if(fl_element < MAX_INDEX_DYN_XY_BITMAP_INDEX)
      {
         fl_element = GET_DYN_XY_BITMAPS_INDEX(fl_element);
         if(fl_element < NB_ALL_DYN_XY_BITMAPS)
         {
         #if NB_DYN_XY_BITMAPS > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
            {
               *p_data           = l_dyn_xy_bitmap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_ALPHAMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
            #endif
               *p_data           = lc_dyn_xy_alphamap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_COLORTRANSBITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_colortransbitmap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_ALPHABITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
            #endif
               *p_data           = lc_dyn_xy_alphabitmap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHAMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_unialphamap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHABITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_unialphabitmap_coord_S[fl_element].x;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
            {
               /*do nothing*/
            }
         }
         else
         {
            fl_element -= NB_ALL_DYN_XY_BITMAPS;
         #if NB_DYN_XY_BITMAPS > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
            {
               *p_data           = l_dyn_xy_bitmap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_ALPHAMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
            #endif
               *p_data           = lc_dyn_xy_alphamap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_COLORTRANSBITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_colortransbitmap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_ALPHABITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
            #endif
               *p_data           = lc_dyn_xy_alphabitmap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHAMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_unialphamap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
         #if NB_DYN_XY_UNIALPHABITMAP > 0
            if(fl_element < MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX)
            {
            #if MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX > 0
               fl_element -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
            #endif
               *p_data           = lc_dyn_xy_unialphabitmap_coord_S[fl_element].y;
               fl_read_status_U8 = TRUE;
            }
            else
         #endif
            {
            }
         }
      }
   #endif
   #if NB_DYNXY_DIMAGES > 0
      else if(fl_element < MAX_INDEX_DYN_X_DBITMAP_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_XY_BITMAP_INDEX;
         if(fl_element < NB_DYNXY_DIMAGES)
         {
            *p_data           = l_d_image_dyn_property_S[fl_element].x;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_Y_DBITMAP_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_X_DBITMAP_INDEX;
         if(fl_element < NB_DYNXY_DIMAGES)
         {
            *p_data           = l_d_image_dyn_property_S[fl_element].y;
            fl_read_status_U8 = TRUE;
         }
      }
   #endif
   #if NB_DYNXY_TEXTS > 0
      else if(fl_element < MAX_INDEX_DYN_X_DTEXT_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_Y_DBITMAP_INDEX;
         if(fl_element < NB_DYNXY_TEXTS)
         {
            *p_data           = l_dyn_text_dyn_property_S[fl_element].coord.x;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_Y_DTEXT_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_X_DTEXT_INDEX;
         if(fl_element < NB_DYNXY_TEXTS)
         {
            *p_data           = l_dyn_text_dyn_property_S[fl_element].coord.y;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_Y_DTEXT_INDEX;
         if(fl_element < NB_DYNXY_TEXTS)
         {
            *p_data           = l_dyn_text_dyn_property_S[fl_element].draw_color;
            fl_read_status_U8 = TRUE;
         }
      }
    #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      else if(fl_element < MAX_INDEX_DYN_NBLINES_DTEXT_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX;
         if(fl_element < NB_DYNXY_TEXTS)
         {
            *p_data           = l_dyn_text_dyn_property_S[fl_element].nb_lines;
            fl_read_status_U8 = TRUE;
         }
      }
    #endif
   #endif
   #if NB_DYN_FILL_SCREENS > 0
      else if(fl_element < MAX_INDEX_DYN_X_NFILL_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_NBLINES_DTEXT_INDEX;
         if(fl_element < NB_DYN_FILL_SCREENS)
         {
            *p_data           = l_fill_screen_dyn_property_S[fl_element].x;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_Y_NFILL_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_X_NFILL_INDEX;
         if(fl_element < NB_DYN_FILL_SCREENS)
         {
            *p_data           = l_fill_screen_dyn_property_S[fl_element].y;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_W_NFILL_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_Y_NFILL_INDEX;
         if(fl_element < NB_DYN_FILL_SCREENS)
         {
            *p_data           = l_fill_screen_def_dyn_S[fl_element].width;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_H_NFILL_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_W_NFILL_INDEX;
         if(fl_element < NB_DYN_FILL_SCREENS)
         {
            *p_data           = l_fill_screen_def_dyn_S[fl_element].height;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_COLOR_NFILL_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_H_NFILL_INDEX;
         if(fl_element < NB_DYN_FILL_SCREENS)
         {
         #ifdef GFX_MGR_USE_INT_RGB
            *p_data           = l_fill_screen_def_dyn_S[fl_element].color;
            fl_read_status_U8 = TRUE;
         #else
            fl_read_status_U8 = FALSE;
         #endif
         }
      }
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      else if(fl_element < MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_COLOR_NFILL_INDEX;
         if(fl_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            *p_data = l_widget_dynamic_clip_list_SA[fl_element].clip.x;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX;
         if(fl_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            *p_data = l_widget_dynamic_clip_list_SA[fl_element].clip.y;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX;
         if(fl_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            *p_data = l_widget_dynamic_clip_list_SA[fl_element].clip.w;
            fl_read_status_U8 = TRUE;
         }
      }
      else if(fl_element < MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX)
      {
         fl_element -= MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX;
         if(fl_element < NB_DYNAMIC_CLIP_WIDGETS)
         {
            *p_data = l_widget_dynamic_clip_list_SA[fl_element].clip.h;
            fl_read_status_U8 = TRUE;
         }
      }
   #endif
   #if NB_DYN_ELEMENTS > NB_SCREENS
      else
      {
         /*do nothing*/
      }
   #endif
   }
 #if (GFX_SCROLABLE_TEXT_SUPPORT != 0) && (NB_DYN_TEXTS > 0)
   else
   {
      /*
      ** Handle the scroll offset event for dynamic text.
      */
      if(fl_element > MAX_INDEX_STEXTS_INDEX)
      {
         fl_element -= MAX_INDEX_STEXTS_INDEX;
         if(fl_element < NB_DYN_TEXTS)
         {
            DYN_TEXT_DEF_T const * fl_text_SP = &lc_dyn_text_def_S[fl_element];
            GFX_CHAR             * fl_data_P;
            if((fl_text_SP->properties & GFX_TEXT_PROPERTY_SCROLABLE) != 0)
            {
               fl_data_P  = &fl_text_SP->data_ptr[fl_text_SP->length+1];
            #if GFX_UNICODE_ENABLED
               *p_data    = *fl_data_P;
            #else
               *p_data = *fl_data_P;
               fl_data_P++;
               (*p_data)<<=8;
               *p_data  += *fl_data_P;
            #endif
               fl_read_status_U8 = TRUE;
            }
         }
      }
   }
 #endif
   return(fl_read_status_U8);
}
#endif

#if NB_DYN_TEXTS > 0
/****************************************************************************
Function Name        : GfxManagerGetText
Description          : This function returns the pointer to string for the
                       requested dynamic text element.
Invocation           : When ever required.
Parameters           : Element ID of the dynamic text whose current string
                       needs to be returned.
Return Value         : Pointer to String.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
GFX_CHAR const * GfxManagerGetText(GFX_ELEMENT_ID_T p_element)
{
   GFX_CHAR const * fl_str = NULL;
   if((p_element >= MAX_INDEX_DYN_BITMAPS_INDEX) && (p_element < MAX_INDEX_DYN_TEXTS_INDEX))
   {
      GFX_ELEMENT_ID_T fl_element = GET_DYN_TEXTS_INDEX(p_element);
      fl_str    = (void *)lc_dyn_text_def_S[fl_element].data_ptr;
   }
   return(fl_str);
}

/****************************************************************************
Function Name        : GfxManagerGetTextFitWidth
Description          : This function shall provide the total number of characters
                       that can be displayed with in the available display width
Invocation           : Invoked by application when ever required.
Parameters           : Element ID in p_element and Pointer to string data.
Return Value         : GFX_TEXT_WIDTH_INFO_DEF_T.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
void GfxManagerGetTextFitWidth(GFX_ELEMENT_ID_T p_element, GFX_TEXT_WIDTH_INFO_DEF_T * p_txt_info_S)
{
   GFX_ELEMENT_ID_T           fl_element_id_E;
   p_txt_info_S->tot_available_width = 0;
   p_txt_info_S->disp_str_ptr[0] = '\0';
   p_txt_info_S->disp_width = 0;
   p_txt_info_S->disp_len = 0;
   p_txt_info_S->text_clip_flag = 0;
   if((p_element >= MAX_INDEX_DYN_BITMAPS_INDEX) && (p_element < MAX_INDEX_DYN_TEXTS_INDEX))
   {
       fl_element_id_E = GET_DYN_TEXTS_INDEX(p_element);
       if(p_txt_info_S->input_str_ptr != NULL)  /* check for valid original string */
       {
          p_txt_info_S->tot_available_width = lc_dyn_text_def_S[fl_element_id_E].width;
          GfxDriverGetTextFitWidth(p_txt_info_S, &lc_dyn_text_def_S[fl_element_id_E]);
       }
       else
       {
          p_txt_info_S->input_str_ptr = NULL;
       }
   }
}
#endif /*#if NB_DYN_TEXTS > 0*/


#if(GFX_PIX_FORMAT == GFX_1BPP_SEG)||(GFX_PIX_FORMAT == GFX_SEG)
/****************************************************************************
Function Name        : GfxManagerBuildSegmentScreen
Description          : Performs the screen building for the segmented layer 
                       and updates the frame buffer
Invocation           : Invoked by application when ever the screen needs to be
                       refreshed.
Parameters           : void
Return Value         : void.
Critical Section     : Shall not call other API's (e.g. from interrupt level) while
                       GfxManagerBuildSegmentScreen is ongoing.
External Interfaces  : None.
******************************************************************************/
#if NB_LAYERS > 1
UINT8 GfxManagerBuildSegmentScreen(void)
#else
void GfxManagerBuildSegmentScreen(void)
#endif
{
       
#if NB_PRIORITY > 1
   UINT8                 fl_cur_priority_U8;
   UINT8                 fl_highest_active_priority_U8;
#endif
#if NB_LAYERS > 1
   UINT8                 fl_active_layers_U8 = 0;
#endif
      
   LAYER_TABLE_T const * fl_active_layer_table_SP = &lc_layer_table_S[gl_active_layer_id_U8];

   #if NB_PRIORITY > 1   
   #if NB_LAYERS > 1
      fl_highest_active_priority_U8 = l_highest_active_priority_U8[gl_active_layer_id_U8];
   #else
      fl_highest_active_priority_U8 = l_highest_active_priority_U8[0];
   #endif
   #endif
   
   #if NB_PRIORITY > 1
      for(fl_cur_priority_U8=0; fl_cur_priority_U8 <= fl_highest_active_priority_U8; fl_cur_priority_U8++)
   #endif
      {
      #if NB_PRIORITY > 1
         SCREEN_ID_T fl_screen_id = fl_active_layer_table_SP->psid_tptr[fl_cur_priority_U8];
      #else
         SCREEN_ID_T fl_screen_id = fl_active_layer_table_SP->psid_tptr[0];
      #endif
         SCREEN_TABLE_T const * fl_screen_def_SP = &lc_screen_table_S[fl_screen_id];

         UINT16 fl_nb_elements_U16  = fl_screen_def_SP->widget.list.nb_elements;
         GFX_ELEMENT_PROPERTY const * fl_element_table_A = fl_screen_def_SP->widget.list.element_table;
         
         GFX_ELEMENT_ID_T fl_element_id_E;

         if(fl_screen_id < NB_SCREENS)
         {
           while(fl_nb_elements_U16 > 0)
           {
             /* l_gfx_driver_notify_flag_U8 = (GFX_SCREEN_CHANGED_BIT|GFX_BEGIN_UPDATE_BIT); */
             fl_element_id_E = fl_element_table_A->id;
             if(fl_element_id_E < NB_DYN_ELEMENTS)
             {
               if((l_dyn_element_changed_U8[fl_element_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
               {
                 l_dyn_element_changed_U8[fl_element_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
                 #if NB_DYN_BITMAPS > 0
                 if (fl_element_id_E < MAX_INDEX_DYN_BITMAPS_INDEX)
                 {
                   COORDINATE_DEF_T *pos;	
                   pos = (COORDINATE_DEF_T *)fl_element_table_A->prop;			
                    fl_element_id_E = GET_DYN_BITMAPS_INDEX(fl_element_id_E);	
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT	
                   GFX_SEG_COLOR fl_color_value;
                    UINT8 fl_byte_U8 = (UINT8)(fl_element_id_E >> 1u); 
                    UINT8 fl_icon_byte = fl_active_layer_table_SP->icon_mask[fl_byte_U8];
                   if ((fl_element_id_E % 2u) == 0u)
                   {
                     fl_color_value = (GFX_SEG_COLOR)(fl_icon_byte & 0x0F);
                   }
                   else
                   {
                     fl_color_value = (GFX_SEG_COLOR)((fl_icon_byte >> 4u) & 0x0F);
                   }
                   GfxDriverSegmentBuildIcon(pos->x, pos->y, fl_color_value);
#else
                   GfxDriverSegmentBuildIcon(pos->x,
                     pos->y,
                     (fl_active_layer_table_SP->icon_mask[fl_element_id_E / 8U] & (1 << (fl_element_id_E & 0x07U))));
#endif
                 }
#endif

#if NB_DYN_TEXTS > 0
#if NB_DYN_BITMAPS > 0
                 else if(fl_element_id_E < MAX_INDEX_DYN_TEXTS_INDEX)
#else
                 if(fl_element_id_E < MAX_INDEX_DYN_TEXTS_INDEX)
#endif
                 {
                   fl_element_id_E = GET_DYN_TEXTS_INDEX(fl_element_id_E);
                   (void)GfxDriverSegmentBuildText(&lc_dyn_text_def_S[fl_element_id_E]);
                 }
                 else
                 {
                  /*do nothing*/
                 }
#endif
                 l_gfx_driver_notify_flag_U8 = GFX_SCREEN_CHANGED_BIT|GFX_BEGIN_UPDATE_BIT;
               }
             }
             fl_element_table_A++;
             fl_nb_elements_U16--;
           }
#if NB_LAYERS > 1
            if((l_gfx_driver_notify_flag_U8 & GFX_BEGIN_UPDATE_BIT) != 0)
            {
                fl_active_layers_U8 |= (1<<gl_active_layer_id_U8);
            }
#endif
         }    
      }
#if NB_LAYERS > 1
	  return fl_active_layers_U8;
#endif
}
#endif
/****************************************************************************
Function Name        : void GfxManagerBuildScreen(){}
Description          : Performs the screen building and updates the frame buffer
                       if there are any changes to be made.
Invocation           : Invoked by application when ever the screen needs to be
                       refreshed.
Parameters           : Optional post copy flag in p_post_copy_flag_U8. This flag
                       is bit encoded. Bit0 for layer0, Bit1 for layer 1 etc.
                       If the flag is set for a layer, after the frame buffer is
                       built the manager instructs the driver to copy the content
                       to the new back buffer. The current frame buffer needs to
                       be copied since the manager builds only the changed area.
                       This flag can be set to 0 if some animation sequence is
                       being executed and each frame is going to be rebuilt fully
                       and there is no need to keep a copy for rework. By this way
                       animation speed can be improved by avoiding the pre-copy.
Return Value         : Returns TRUE if the screen was updated. FALSE otherwise.
Critical Section     : Shall not call other API's (e.g. from interrupt level) while
                       GfxManagerBuildScreen is ongoing.
External Interfaces  : None.
******************************************************************************/
#if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
UINT8 GfxManagerBuildScreen(UINT8 p_post_copy_flag_U8)
#else
UINT8 GfxManagerBuildScreen(void)
#endif
{
#if NB_PRIORITY > 1
   UINT8                 fl_cur_priority_U8;
   UINT8                 fl_highest_active_priority_U8;
 #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_REPAINT)
   UINT8                 fl_repaint_U8;
 #endif
#endif
#if NB_LAYERS > 1
   UINT8                 fl_active_layers_U8 = 0;
#endif
#if NB_LAYERS > 1 || (GFX_PIX_FORMAT != GFX_SEG)
   LAYER_TABLE_T const * fl_active_layer_table_SP = &lc_layer_table_S[0];
#endif

   l_gfx_driver_notify_flag_U8 = 0;

#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
  l_cur_bld_scr_pri_U16 = NB_PRIORITY;
#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
#if NB_LAYERS > 1
   for(gl_active_layer_id_U8 = 0; gl_active_layer_id_U8 < NB_LAYERS; gl_active_layer_id_U8++, fl_active_layer_table_SP++)
#endif
   {
      /*
      ** Check to see whether the driver is not busy and there are priority scrrens
      ** active..
      */
   #if NB_PRIORITY > 1
      fl_highest_active_priority_U8 = NB_PRIORITY;
    #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_REPAINT)
      fl_repaint_U8                 = FALSE;
    #endif
   #endif
   #if NB_LAYERS > 1
      if(GfxDriverCheckBusyStatus(gl_active_layer_id_U8) == FALSE)
   #else
      if(GfxDriverCheckBusyStatus() == FALSE)
   #endif
   #if NB_PRIORITY > 1
      {
         #if NB_LAYERS > 1
            fl_highest_active_priority_U8 = l_highest_active_priority_U8[gl_active_layer_id_U8];
         #else
            fl_highest_active_priority_U8 = l_highest_active_priority_U8[0];
         #endif
      }
      if(fl_highest_active_priority_U8 < NB_PRIORITY)
   #endif
      {
      #if (GFX_PIX_FORMAT != GFX_SEG)
      #if (GFX_PIX_FORMAT == GFX_1BPP_SEG)
         if(fl_active_layer_table_SP->layer_type != GFX_SEG)
      #endif
         {
         #if NB_PRIORITY > 1
            for(fl_cur_priority_U8=0; fl_cur_priority_U8 <= fl_highest_active_priority_U8; fl_cur_priority_U8++)
         #endif
            {
            #if NB_PRIORITY > 1
               SCREEN_ID_T fl_screen_id = fl_active_layer_table_SP->psid_tptr[fl_cur_priority_U8];
            #else
               SCREEN_ID_T fl_screen_id = fl_active_layer_table_SP->psid_tptr[0];
            #endif
               SCREEN_TABLE_T const * fl_screen_def_SP = &lc_screen_table_S[fl_screen_id];
               #if NB_PRIORITY > 1
               #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
                 GfxDriverSetElementOffset(l_dyn_screen_pos_x_S32[fl_cur_priority_U8],l_dyn_screen_pos_y_S32[fl_cur_priority_U8]);
               #endif
               #elif (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
                 GfxDriverSetElementOffset(l_dyn_screen_pos_x_S32[0],l_dyn_screen_pos_y_S32[0]);
               #endif

               #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
               l_cur_bld_scr_pri_U16 = fl_cur_priority_U8;
               if(l_clip_count_U8 == 0)
               {
                  GfxManagerBuildNormalScreen(fl_screen_id,fl_cur_priority_U8,fl_screen_def_SP);

                #if NB_LAYERS > 1
                fl_active_layers_U8 |= (1<<gl_active_layer_id_U8);
                #endif /* NB_LAYERS > 1 */
               }
               else
               {
                   GfxManagerBuildClippedScreenUtility(fl_screen_id,fl_cur_priority_U8,fl_screen_def_SP);
               }
               #else
               if(fl_screen_id < NB_SCREENS)
               {
               #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_REPAINT) && (NB_PRIORITY > 1)
                  if(fl_repaint_U8 != FALSE)
                  {
                     /*
                     ** If a low priority screen has changes, then repaint all the
                     ** further priority screens by setting its changed flag.
                     */
                     l_dyn_element_changed_U8[fl_screen_id] |= GFX_SCREEN_CHANGED_FLAG;
                  }
               #endif
                  if((l_dyn_element_changed_U8[fl_screen_id] & GFX_SCREEN_CHANGED_FLAG) != 0)
                  {
                     /*
                     ** if the screen itself is changed rebuild entire screen.
                     */
                     GfxManagerBuildWidget(&fl_screen_def_SP->widget);
                     l_dyn_element_changed_U8[fl_screen_id] &= (UINT8)(~GFX_SCREEN_CHANGED_FLAG);
                  }
                  #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_BLOCK) && (NB_PRIORITY > 1)
                  else if(fl_cur_priority_U8 >= l_highest_active_priority_U8[gl_active_layer_id_U8])
                  #else
                  else
                 #endif
                  {
                     /*
                     ** No change in screen, so look for any of its dynamic elements are
                     ** changed.
                     */
                  #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_REPAINT) && (NB_PRIORITY > 1)
                     if(GfxManagerCheckElementChanged(&fl_screen_def_SP->widget) != FALSE)
                     {
                        fl_repaint_U8 = TRUE;
                     }
                  #else
                     (void)GfxManagerCheckElementChanged(&fl_screen_def_SP->widget);
                  #endif
                  }
                 #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_BLOCK) && (NB_PRIORITY > 1)
                  else
                  {
                  }
                #endif
               #if NB_LAYERS > 1
                  if((l_gfx_driver_notify_flag_U8 & GFX_BEGIN_UPDATE_BIT) != 0)
                  {
                     fl_active_layers_U8 |= (1<<gl_active_layer_id_U8);
                  }
               #endif
               }
           }
         #endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
         }
         #if(GFX_PIX_FORMAT == GFX_1BPP_SEG)  
         else
         {
			 #if NB_LAYERS > 1
			 fl_active_layers_U8 |= GfxManagerBuildSegmentScreen();
			 #else
			 GfxManagerBuildSegmentScreen();
             #endif
         }
		 #endif
         #else
		    #if NB_LAYERS > 1
            fl_active_layers_U8 = GfxManagerBuildSegmentScreen();
			#else
			GfxManagerBuildSegmentScreen();
			#endif
         #endif
      #if NB_LAYERS > 1
            l_gfx_driver_notify_flag_U8 &= GFX_SCREEN_CHANGED_BIT;
      #endif
      }
   }

   if(l_gfx_driver_notify_flag_U8 != 0)
   {
   #if NB_LAYERS > 1
     #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
      GfxDriverEndUpdate(fl_active_layers_U8, p_post_copy_flag_U8);
     #else
      GfxDriverEndUpdate(fl_active_layers_U8);
     #endif
   #else
     #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
      GfxDriverEndUpdate(p_post_copy_flag_U8);
   #else
      GfxDriverEndUpdate();
     #endif
   #endif
   }

   return(l_gfx_driver_notify_flag_U8);
}

#if (NB_DYN_WIDGETS > 0)  && (NB_WIDGETS > 0)
/****************************************************************************
Function Name        : GfxManagerGetSelectedWidgetId
Description          : This function returns the selected widget index for a
                       passed dynamic widget. If the selected widget index
                       is pointing to another dynamic widget, then fuction
                       makes recursive calls until a static widget is found.
                       This is to support nested dynamic widgets
Invocation           : Invoked internally by manager.
Parameters           : Dynamic widget index
Return Value         : Absolute identifier for the selected static widget.
                       If a static widget is not found then returns GFX_NB_ELEMENTS.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 GfxManagerGetSelectedWidgetId(GFX_ELEMENT_ID_T * p_dynamic_widget_id_P)
{
   UINT8 fl_changed_U8 = FALSE;

#if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
   GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_widget_elem_list_S[*p_dynamic_widget_id_P];

   *p_dynamic_widget_id_P = l_dyn_widget_S[*p_dynamic_widget_id_P];
   if(*p_dynamic_widget_id_P < fl_elem_list_SP->nb_elements)
   {
      *p_dynamic_widget_id_P = fl_elem_list_SP->element_table[*p_dynamic_widget_id_P].id;
   }
   else
   {
      *p_dynamic_widget_id_P = GFX_NB_ELEMENTS;
   }
#else
   *p_dynamic_widget_id_P = l_dyn_widget_S[*p_dynamic_widget_id_P];
#endif
   if((*p_dynamic_widget_id_P >= MAX_INDEX_DYN_TEXTS_INDEX) && \
      (*p_dynamic_widget_id_P < MAX_INDEX_DYN_WIDGETS_INDEX)   )
   {
      /*
      ** This dynamic widget is pointing to another dynamic widget
      */
   #if (GFX_NEED_NESTED_DYNAMIC_WIDGET_SUPPORT > 0)
      if((l_dyn_element_changed_U8[*p_dynamic_widget_id_P] & GFX_SCREEN_CHANGED_FLAG) != 0)
      {
         l_dyn_element_changed_U8[*p_dynamic_widget_id_P] &= ~GFX_SCREEN_CHANGED_FLAG;
         fl_changed_U8 = TRUE;
      }
      *p_dynamic_widget_id_P = GET_DYN_WIDGETS_INDEX(*p_dynamic_widget_id_P);
      fl_changed_U8         |= GfxManagerGetSelectedWidgetId(p_dynamic_widget_id_P);
   #else
      *p_dynamic_widget_id_P = GFX_NB_ELEMENTS;
   #endif
   }
   return(fl_changed_U8);
}
#endif


#if GFX_PIX_FORMAT != GFX_SEG 
/****************************************************************************
Function Name        : GfxManagerCheckElementChanged
Description          : This function looks for changed elements and build the
                       the elements which has a change.
Invocation           : Invoked internally by manager.
Parameters           : Pointer to widget which needs to be checked for changes
Return Value         : TRUE if there are changes, FALSE otherwise.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 GfxManagerCheckElementChanged(WIDGET_DEF_T const * p_widget_ptr)
{
   UINT16 fl_nb_elements_U16    = p_widget_ptr->list.nb_elements;
   UINT8 fl_screen_changed_U8 = FALSE;
   GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;
   GFX_ELEMENT_ID_T             fl_elem_id_E;

   while((fl_nb_elements_U16 > 0) && (fl_screen_changed_U8 == FALSE))
   {
      fl_elem_id_E = fl_element_table_A->id;
      #if NB_STATIC_TEXTS > 0
      #if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
        if((fl_elem_id_E < MAX_INDEX_STEXTS_INDEX) &&
        (fl_elem_id_E >= MAX_INDEX_WIDGETS_INDEX))
        {
          DYN_TEXT_DEF_T  fl_text_def;
          UINT8 fl_font_id;
          fl_elem_id_E = GET_STEXTS_INDEX(fl_elem_id_E);
          fl_text_def = lc_static_text_def_S[fl_elem_id_E];
          fl_font_id = fl_text_def.font_id;
          if(GFX_MGR01_IS_CHANGED(l_font_elem_changed_flag_U8A,fl_font_id))
          {
            GfxManagerBuildWidget(p_widget_ptr);
            GFX_MGR01_CLR_FLAG(l_font_elem_changed_flag_U8A,fl_font_id);
            fl_screen_changed_U8 = TRUE;
          }
        }
      #endif
      #endif  
      #if NB_DYN_ELEMENTS > NB_SCREENS
      if(fl_elem_id_E < NB_DYN_ELEMENTS)
      {
          #if NB_DYN_TEXTS > 0
          #if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
            if((fl_elem_id_E < MAX_INDEX_DYN_TEXTS_INDEX) &&
            (fl_elem_id_E >= MAX_INDEX_DYN_BITMAPS_INDEX))
            {
              DYN_TEXT_DEF_T  fl_text_def;
              UINT8 fl_font_id;
              fl_elem_id_E = GET_DYN_TEXTS_INDEX(fl_elem_id_E);
              fl_text_def = lc_dyn_text_def_S[fl_elem_id_E];
              fl_font_id = fl_text_def.font_id;
              if(GFX_MGR01_IS_CHANGED(l_font_elem_changed_flag_U8A,fl_font_id))
              {
                GfxManagerBuildWidget(p_widget_ptr);
                GFX_MGR01_CLR_FLAG(l_font_elem_changed_flag_U8A,fl_font_id);
                l_dyn_element_changed_U8[fl_elem_id_E] &= (UINT8)(~GFX_SCREEN_CHANGED_FLAG);
                fl_screen_changed_U8 = TRUE;
              }
            }
          #endif
          #endif
         if((l_dyn_element_changed_U8[fl_elem_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
         {
         #if /*(NB_DYN_WIDGETS > 0) && */(NB_WIDGETS > 0)
            if((fl_elem_id_E <  MAX_INDEX_DYN_TEXTS_INDEX)  || \
               (fl_elem_id_E >= MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)   )
            {
               /*
               ** Any dynamic element other than a dynamic widgets has changed then,
               ** rebuild the parent widget and exit.
               */
               GfxManagerBuildWidget(p_widget_ptr);
               l_dyn_element_changed_U8[fl_elem_id_E] &= (UINT8)(~GFX_SCREEN_CHANGED_FLAG);
               fl_screen_changed_U8 = TRUE;
            }
            else
         #endif
         #if (NB_DYN_WIDGETS > 0)
            if((fl_elem_id_E >= MAX_INDEX_DYN_TEXTS_INDEX) && \
               (fl_elem_id_E < MAX_INDEX_DYN_WIDGETS_INDEX)   )
            {
               fl_elem_id_E = GET_DYN_WIDGETS_INDEX(fl_elem_id_E);
               (void)GfxManagerGetSelectedWidgetId(&fl_elem_id_E);
               if(fl_elem_id_E >= GFX_NB_ELEMENTS)
               {
                 GfxManagerBuildWidget(p_widget_ptr);
                 l_dyn_element_changed_U8[fl_elem_id_E] &= (UINT8)(~GFX_SCREEN_CHANGED_FLAG);
                 fl_screen_changed_U8 = TRUE;
               }
            }
            else
         #endif
            {
            }
         }
       #if NB_DYN_BITMAPS > 0 /*&& NB_ALL_DYN_XY_BITMAPS > 0*/
         else
         {
            /*
            ** Check to see whether a dynamic XY image inside a dynamic image has
            ** change in its co-ordinates. Then again we need to rebuild the parent widget.
            ** E.g for the below case assume the Elem3 dynamic imag index has not changed
            ** and its remaining at 0 itself. Now we need to look at whether the selected
            ** index 0 (Elem4) is a dynamic xy. If yes see if it has any change in xy location.
            ** p_widget_ptr ---
            **                 '---- Elem1
            **                 '---- Elem2
            **                 '---- Elem3(dynamic image)
            **                          '---- (.) Elem4(dynamic xy image) currently selected
            **                          '----     Elem5(dynamic xy image)
            */
            if((fl_elem_id_E >= MAX_INDEX_SCREEN_INDEX) && (fl_elem_id_E < MAX_INDEX_DYN_BITMAPS_INDEX))
            {
               fl_elem_id_E = GET_DYN_BITMAPS_INDEX(fl_elem_id_E);
               if(fl_elem_id_E < NB_DYN_BITMAPS)
               {
               #if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
                  GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_image_elem_list_S[fl_elem_id_E];
                  fl_elem_id_E = l_cur_dyn_bitmap_S[fl_elem_id_E];
                  if(fl_elem_id_E < fl_elem_list_SP->nb_elements)
                  {
                     /*p_element_table_AP = &fl_elem_list_SP->element_table[fl_elem_id_E];*/
                     if(fl_elem_list_SP->element_table[fl_elem_id_E].id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
                     {
                        if((l_dyn_element_changed_U8[fl_elem_list_SP->element_table[fl_elem_id_E].id] & GFX_SCREEN_CHANGED_FLAG) != 0)
                        {
                           GfxManagerBuildWidget(p_widget_ptr);
                           l_dyn_element_changed_U8[fl_elem_list_SP->element_table[fl_elem_id_E].id] &= ~GFX_SCREEN_CHANGED_FLAG;
                           fl_screen_changed_U8 = TRUE;
                        }
                     }
                  }
               #else
                  GFX_ELEMENT_PROPERTY fl_elem_property_S;
                  fl_elem_property_S.id = l_cur_dyn_bitmap_S[fl_elem_id_E];
                  if(fl_elem_property_S.id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
                  {
                     if((l_dyn_element_changed_U8[fl_elem_property_S.id] & GFX_SCREEN_CHANGED_FLAG) != 0)
                     {
                        GfxManagerBuildWidget(p_widget_ptr);
                        l_dyn_element_changed_U8[fl_elem_property_S.id] &= ~GFX_SCREEN_CHANGED_FLAG;
                        fl_screen_changed_U8 = TRUE;
                     }
                  }
               #endif
               }
            }
         }
      #endif
      }
      #endif   /* #if NB_DYN_ELEMENTS > NB_SCREENS */
      fl_nb_elements_U16--;
      fl_element_table_A++;
   }
#if NB_WIDGETS > 0
   if(fl_screen_changed_U8 == FALSE)
   {
      /*
      ** No change in dynamic elements at parent level, so look inside child-widgets
      ** for any changes.
      */
      if(GfxManagerCheckWidgetsChanged(p_widget_ptr) != FALSE)
      {
         fl_screen_changed_U8 = TRUE;
      }
   }
#endif
   return(fl_screen_changed_U8);
}

#if NB_WIDGETS > 0
/****************************************************************************
Function Name        : GfxManagerCheckWidgetsChanged
Description          : This function looks a widget (static and dynamic) for
                       changes and builds the widgets which has changes.
Invocation           : Invoked internally by manager.
Parameters           : Pointer to widget which needs to be checked for changes
Return Value         : TRUE if there are changes, FALSE otherwise.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 GfxManagerCheckWidgetsChanged(WIDGET_DEF_T const * p_widget_ptr)
{
   UINT16 fl_nb_elements_U16  = p_widget_ptr->list.nb_elements;
   UINT8 fl_ret_status_U8   = 0;
   GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;
   GFX_ELEMENT_ID_T       fl_elem_id_E;

   while(fl_nb_elements_U16 > 0)
   {
      fl_elem_id_E = fl_element_table_A->id;

      if((fl_elem_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_elem_id_E < MAX_INDEX_WIDGETS_INDEX))
      {
         fl_ret_status_U8 |= GfxManagerCheckElementChanged(&lc_widget_table_S[GET_WIDGETS_INDEX(fl_elem_id_E)]);
      }
   #if (NB_DYN_WIDGETS > 0)
      else if((fl_elem_id_E >= MAX_INDEX_DYN_TEXTS_INDEX) && \
              (fl_elem_id_E < MAX_INDEX_DYN_WIDGETS_INDEX)   )
      {
         if((l_dyn_element_changed_U8[fl_elem_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
         {
            l_dyn_element_changed_U8[fl_elem_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
            fl_ret_status_U8 = TRUE;
         }
         fl_elem_id_E      = GET_DYN_WIDGETS_INDEX(fl_elem_id_E);
         fl_ret_status_U8 |= GfxManagerGetSelectedWidgetId(&fl_elem_id_E);
         if((fl_elem_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_elem_id_E < MAX_INDEX_WIDGETS_INDEX))
         {
            fl_elem_id_E = GET_WIDGETS_INDEX(fl_elem_id_E);
            if(fl_ret_status_U8 != FALSE)
            {
               /*
               ** If its a valid widget then we need to rebuild it as there
               ** are changes detected.
               */
               GfxManagerBuildWidget(&lc_widget_table_S[fl_elem_id_E]);
            }
            else
            {
               /*
               ** Dynamic widget has not changed, so look inside the currently
               ** selected widget for any changes. If any changes, then we can build it.
               */
               fl_ret_status_U8 |= GfxManagerCheckElementChanged(&lc_widget_table_S[fl_elem_id_E]);
            }
         }
      #if NB_DYNAMIC_CLIP_WIDGETS > 0
         else if((fl_elem_id_E >= MAX_INDEX_DYN_WIDGETS_INDEX) && (fl_elem_id_E < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX))
         {
            if((l_dyn_element_changed_U8[fl_elem_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
            {
               l_dyn_element_changed_U8[fl_elem_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
               fl_ret_status_U8 = TRUE;
            }
            fl_elem_id_E = GET_DYN_CLIP_WIDGETS_INDEX(fl_elem_id_E);
            if(fl_ret_status_U8 != FALSE)
            {
               /*
               ** If its a valid widget then we need to rebuild it as there
               ** are changes detected.
               */
               GfxManagerBuildWidget(&lc_dyn_clip_widget_table_S[fl_elem_id_E]);
            }
            else
            {
               /*
               ** Dynamic widget has not changed, so look inside the currently
               ** selected widget for any changes. If any changes, then we can build it.
               */
               fl_ret_status_U8 |= GfxManagerCheckElementChanged(&lc_dyn_clip_widget_table_S[fl_elem_id_E]);
            }
         }
      #endif
         else
         {
         }
      }
    #if NB_DYNAMIC_CLIP_WIDGETS > 0
      else if((fl_elem_id_E >= MAX_INDEX_DYN_WIDGETS_INDEX) && (fl_elem_id_E < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX))
      {
         if((l_dyn_element_changed_U8[fl_elem_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
         {
            l_dyn_element_changed_U8[fl_elem_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
            fl_ret_status_U8 = TRUE;
         }
         fl_elem_id_E = GET_DYN_CLIP_WIDGETS_INDEX(fl_elem_id_E);
         if(fl_ret_status_U8 != FALSE)
         {
            /*
            ** If its a valid widget then we need to rebuild it as there
            ** are changes detected.
            */
            GfxManagerBuildWidget(&lc_dyn_clip_widget_table_S[fl_elem_id_E]);
         }
         else
         {
            /*
            ** Dynamic widget has not changed, so look inside the currently
            ** selected widget for any changes. If any changes, then we can build it.
            */
            fl_ret_status_U8 |= GfxManagerCheckElementChanged(&lc_dyn_clip_widget_table_S[fl_elem_id_E]);
         }
      }
    #endif
      else
      {
      }
   #endif
      fl_nb_elements_U16--;
      fl_element_table_A++;
   }

   return(fl_ret_status_U8);
}
#endif  /*#if NB_WIDGETS > 0*/
#endif  /* #if GFX_PIX_FORMAT != GFX_SEG  */

#if NB_ALL_BITMAPS > 0
/****************************************************************************
Function Name        : GfxManagerBuildStaticXyBitmap
Description          : This function performs a blind building operation of
                       passed Static XY Bitmap without looking for any change
                       in element
Invocation           : Internally by the manager
Parameters           : Element property in p_elem_property_P and coordinate
                       value in p_coord_P.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildStaticXyBitmap(GFX_ELEMENT_PROPERTY const * p_elem_property_P, COORDINATE_DEF_T const * p_coord_P)
{
    GFX_ELEMENT_ID_T fl_elem_id_E = GET_BITMAPS_INDEX(p_elem_property_P->id);

 #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    if(p_coord_P == NULL)
    {
      p_coord_P = (COORDINATE_DEF_T const *) p_elem_property_P->prop;
    }
 #endif
 #if NB_SXY_BITMAPS > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_NORMAL_INDEX)
    {
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_bitmap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_bitmap_def_S[fl_elem_id_E].w,
      lc_sxy_bitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildBitmapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_bitmap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_bitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_ALPHAMAP > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_NORMAL_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_alphamap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_alphamap_def_S[fl_elem_id_E].w,
      lc_sxy_alphamap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildAlphaMapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_alphamap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_alphamap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_OVG > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_OVGMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;
       GfxDriverBuildOvgObject(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_ovgmap_def_S[fl_elem_id_E],
         #endif
           &lc_sxy_ovgmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_COLORTRANSBITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_colortransbitmap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_colortransbitmap_def_S[fl_elem_id_E].w,
      lc_sxy_colortransbitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildColorTransBitMapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_colortransbitmap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_colortransbitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_ALPHABITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_alphabitmap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_alphabitmap_def_S[fl_elem_id_E].w,
      lc_sxy_alphabitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildAlphaBitMapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_alphabitmap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_alphabitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_UNIALPHAMAP > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_unialphamap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_unialphamap_def_S[fl_elem_id_E].w,
      lc_sxy_unialphamap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildUniAlphaMapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_unialphamap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_unialphamap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_SXY_UNIALPHABITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_UNIALPHABITMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      (COORDINATE_DEF_T const *)p_coord_P,
             #else
             &lc_sxy_unialphabitmap_coord_S[fl_elem_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_sxy_unialphabitmap_def_S[fl_elem_id_E].w,
      lc_sxy_unialphabitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildUniAlphaBitMapImage(
         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
           (COORDINATE_DEF_T const *)p_coord_P,
         #else
           &lc_sxy_unialphabitmap_coord_S[fl_elem_id_E],
         #endif
           &lc_sxy_unialphabitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
    {
       /*
       ** Unsupported draw mode
       */
    }
}
#endif

#if NB_ALL_DYN_XY_BITMAPS > 0
/****************************************************************************
Function Name        : GfxManagerBuildDynamicXyBitmap
Description          : This function performs a blind building operation of
                       passed Dynamic XY Bitmap without looking for any change
                        in element
Invocation           : Internally by the manager
Parameters           : Element property in p_elem_property_P.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildDynamicXyBitmap(GFX_ELEMENT_PROPERTY const * p_elem_property_P
										   #if NB_DYN_BITMAPS > 0
										     , COORDINATE_DEF_T * p_coord_P
                                           #endif
											 )
{
    GFX_ELEMENT_ID_T fl_elem_id_E = GET_DYN_XY_BITMAPS_INDEX(p_elem_property_P->id);

 #if NB_DYN_XY_BITMAPS > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
    {
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &l_dyn_xy_bitmap_coord_S[fl_elem_id_E],
      lc_dyn_xy_bitmap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_bitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
	   #if NB_DYN_BITMAPS > 0
	     if(p_coord_P != NULL)
		 {
		   COORDINATE_DEF_T fl_coord_P;
		   fl_coord_P.x = (p_coord_P->x+l_dyn_xy_bitmap_coord_S[fl_elem_id_E].x);
           fl_coord_P.y = (p_coord_P->y+l_dyn_xy_bitmap_coord_S[fl_elem_id_E].y);
           GfxDriverBuildBitmapImage(&fl_coord_P, &lc_dyn_xy_bitmap_def_S[fl_elem_id_E]);
		 }
		 else
		 {
		   GfxDriverBuildBitmapImage(&l_dyn_xy_bitmap_coord_S[fl_elem_id_E], &lc_dyn_xy_bitmap_def_S[fl_elem_id_E]);
		 }
       #else
         GfxDriverBuildBitmapImage(&l_dyn_xy_bitmap_coord_S[fl_elem_id_E], &lc_dyn_xy_bitmap_def_S[fl_elem_id_E]);
       #endif
    }
    else
 #endif
 #if NB_DYN_XY_ALPHAMAP > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_alphamap_coord_S[fl_elem_id_E],
      lc_dyn_xy_alphamap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_alphamap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildAlphaMapImage(&lc_dyn_xy_alphamap_coord_S[fl_elem_id_E], &lc_dyn_xy_alphamap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_DYN_XY_OVG > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_OVGMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_ovg_coord_S[fl_elem_id_E],
      lc_dyn_xy_ovgmap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_ovgmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildOvgObject(&lc_dyn_xy_ovg_coord_S[fl_elem_id_E], &lc_dyn_xy_ovgmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_DYN_XY_COLORTRANSBITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_colortransbitmap_coord_S[fl_elem_id_E],
      lc_dyn_xy_colortransbitmap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_colortransbitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildColorTransBitMapImage(&lc_dyn_xy_colortransbitmap_coord_S[fl_elem_id_E], &lc_dyn_xy_colortransbitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_DYN_XY_ALPHABITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_alphabitmap_coord_S[fl_elem_id_E],
      lc_dyn_xy_alphabitmap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_alphabitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildAlphaBitMapImage(&lc_dyn_xy_alphabitmap_coord_S[fl_elem_id_E], &lc_dyn_xy_alphabitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_DYN_XY_UNIALPHAMAP > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_unialphamap_coord_S[fl_elem_id_E],
      lc_dyn_xy_unialphamap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_unialphamap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildUniAlphaMapImage(&lc_dyn_xy_unialphamap_coord_S[fl_elem_id_E], &lc_dyn_xy_unialphamap_def_S[fl_elem_id_E]);
    }
    else
 #endif
 #if NB_DYN_XY_UNIALPHABITMAP > 0
    if(fl_elem_id_E < MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       fl_elem_id_E -= MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX;
       #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
    GfxManagerUpdateClipData(
      &lc_dyn_xy_unialphabitmap_coord_S[fl_elem_id_E],
      lc_dyn_xy_unialphabitmap_def_S[fl_elem_id_E].w,
      lc_dyn_xy_unialphabitmap_def_S[fl_elem_id_E].h);
       #endif   /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
       GfxDriverBuildUniAlphaBitMapImage(&lc_dyn_xy_unialphabitmap_coord_S[fl_elem_id_E], &lc_dyn_xy_unialphabitmap_def_S[fl_elem_id_E]);
    }
    else
 #endif
    {
       /*
       ** Unsupported draw mode
       */
    }
}
#endif

 #if (NB_STATIC_CLIP_AREA > 0) || (NB_DYNAMIC_CLIP_WIDGETS > 0) || ((GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) && (GFX_DRIVER_NEED_BMP_CLIPPING == YES))
/****************************************************************************
Function Name        : GfxManagerGetModifiedClipArea
Description          : This function calculates the modified clip area according
                       to the change in the element offset.
Invocation           : Internally by the manager
Parameters           : The actual clip area.
Return Value         : Modified clip area
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static RECTANGLE_DEF_T GfxManagerGetModifiedClipArea(RECTANGLE_DEF_T const p_clip_area)
{
  RECTANGLE_DEF_T  fl_widget_clip_area;
  GFX_SIZE_X_T  fl_widget_off_area_x;
  GFX_SIZE_Y_T  fl_widget_off_area_y;
  UINT8  fl_widget_off_area_alpha;
  GFX_SIZE_W_T fl_tot_width;
  GFX_SIZE_H_T fl_tot_height;

  fl_widget_clip_area = p_clip_area;
  GfxDriverAddElementOffset(&fl_widget_clip_area.x, &fl_widget_clip_area.y);
  GfxDriverGetWidgetOffset(&fl_widget_off_area_x, &fl_widget_off_area_y, &fl_widget_off_area_alpha);

  fl_widget_clip_area.x+= fl_widget_off_area_x;
  fl_widget_clip_area.y+= fl_widget_off_area_y;

  fl_tot_width = fl_widget_clip_area.x + fl_widget_clip_area.w;
  if(fl_tot_width > GFX_MAX_W_LENGTH)
  {
    fl_widget_clip_area.w = fl_widget_clip_area.w - (fl_tot_width - GFX_MAX_W_LENGTH);
  }
  fl_tot_height = fl_widget_clip_area.y + fl_widget_clip_area.h;
  if(fl_tot_height > GFX_MAX_H_LENGTH)
  {
    fl_widget_clip_area.h = fl_widget_clip_area.h - (fl_tot_height - GFX_MAX_H_LENGTH);
  }

  return fl_widget_clip_area;
}
#endif

#if NB_WIDGETS > 0 || GFX_PIX_FORMAT != GFX_SEG
/****************************************************************************
Function Name        : GfxManagerBuildWidget
Description          : This function performs a blind building operation of
                       passed widget without looking for any change in element
Invocation           : Internally by the manager
Parameters           : Pointer the widget which needs to be built.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildWidget(WIDGET_DEF_T const * p_widget_ptr)
{
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   RECTANGLE_DEF_T   fl_clip_area_S;
#endif
#ifdef GFX_OPEN_VG
   VGfloat           fl_matrix[9];
#endif

   UINT16 fl_nb_elements_U16  = p_widget_ptr->list.nb_elements;
   GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES) 
   GFX_SIZE_X_T fl_pos_x;
   GFX_SIZE_Y_T fl_pos_y;
   UINT8 fl_alpha ;
   GfxDriverGetWidgetOffset(&fl_pos_x,&fl_pos_y,&fl_alpha);
#endif



   if((l_gfx_driver_notify_flag_U8 & GFX_BEGIN_UPDATE_BIT) == 0)
   {
   #if GFX_MANAGER_NEED_BEGIN_UPDATE_NOTIFICATION > 0
    #if NB_LAYERS > 1
      GfxDriverBeginUpdate(gl_active_layer_id_U8);
    #else
      GfxDriverBeginUpdate();
    #endif
   #endif
      l_gfx_driver_notify_flag_U8 = (GFX_SCREEN_CHANGED_BIT|GFX_BEGIN_UPDATE_BIT);
   }
#ifdef GFX_OPEN_VG
   GfxDriverGetMatrix(fl_matrix);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   GfxDriverGetClipArea(&fl_clip_area_S);
 #if NB_STATIC_CLIP_AREA > 0
   if((p_widget_ptr->property & GFX_WIDGET_CLIP_MASK) == GFX_WIDGET_CLIP_STATIC)
   {
      #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
      RECTANGLE_DEF_T  fl_widget_clip_area;
      fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_widget_static_clip_list_SA[p_widget_ptr->clip_index].clip);
      GfxDriverSetClipArea(&fl_widget_clip_area);
      #else
      GfxDriverSetClipArea(&l_widget_static_clip_list_SA[p_widget_ptr->clip_index].clip);
      #endif
   #ifdef GFX_OPEN_VG
      GfxDriverMultMatrix(&l_widget_static_clip_list_SA[p_widget_ptr->clip_index].matrix[0]);
   #endif
   }
   else
 #endif
 #if NB_DYNAMIC_CLIP_WIDGETS > 0
   if((p_widget_ptr->property & GFX_WIDGET_CLIP_MASK) == GFX_WIDGET_CLIP_DYNAMIC)
   {
      #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES) 
      RECTANGLE_DEF_T  fl_widget_clip_area;
      GfxDriverAddWidgetOffset(l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].dyn_prop.x,
                               l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].dyn_prop.y ,
                               l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].dyn_prop.alpha);

      fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].clip);
      GfxDriverSetClipArea(&fl_widget_clip_area);
      #else
      GfxDriverSetClipArea(&l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].clip);
      #endif
   #ifdef GFX_OPEN_VG
      GfxDriverMultMatrix(&l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].matrix[0]);
   #endif
   }
   else
 #endif
   {
   }
#endif
#ifdef GFX_ALIGNED_WIDGETS_ENABLED
   if(((p_widget_ptr->property & GFX_WIDGET_ALIGN_MASK) != GFX_WIDGET_ALIGN_NONE) &&
      (fl_nb_elements_U16 > 1))
   {
      GfxManagerBuildAlignedWidget(p_widget_ptr);
   }
   else
#endif
   {
      while(fl_nb_elements_U16 > 0)
      {
         GfxManagerBuildElement(fl_element_table_A);
         fl_element_table_A++;
         fl_nb_elements_U16--;
      }
   }
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  GfxDriverSetClipArea(&fl_clip_area_S);
#endif
#ifdef GFX_OPEN_VG
   GfxDriverSetMatrix(fl_matrix);
#endif

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)  
   GfxDriverSetWidgetOffset(fl_pos_x,fl_pos_y,fl_alpha);
#endif
}

/****************************************************************************
Function Name        : GfxManagerBuildElement
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
static void GfxManagerBuildElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP)
{
   GFX_ELEMENT_ID_T fl_element_id_E = p_element_table_AP->id;

   if(fl_element_id_E >= MAX_INDEX_SCREEN_INDEX)
   {
      if(fl_element_id_E < NB_DYN_ELEMENTS)
      {
         l_dyn_element_changed_U8[fl_element_id_E] &= (UINT8)(~GFX_SCREEN_CHANGED_FLAG);
      }
   #if (NB_ALL_BITMAPS+NB_ALL_DYN_XY_BITMAPS) > 0
     #if NB_DYN_BITMAPS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_BITMAPS_INDEX)
      {
         fl_element_id_E = GET_DYN_BITMAPS_INDEX(fl_element_id_E);
         if(fl_element_id_E < NB_DYN_BITMAPS)
         {
         #if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
            GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_image_elem_list_S[fl_element_id_E];
            COORDINATE_DEF_T       * fl_coord_P      = NULL;
          #if NB_DYNXY_DIMAGES > 0
            if(fl_element_id_E < NB_DYNXY_DIMAGES)
            {
               fl_coord_P = &l_d_image_dyn_property_S[fl_element_id_E];
            }
          #endif
            fl_element_id_E = (GFX_ELEMENT_ID_T)l_cur_dyn_bitmap_S[fl_element_id_E];
            if(fl_element_id_E < fl_elem_list_SP->nb_elements)
            {
               p_element_table_AP = &fl_elem_list_SP->element_table[fl_element_id_E];
            #if NB_ALL_DYN_XY_BITMAPS > 0
               if(p_element_table_AP->id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
               {
			      GfxManagerBuildDynamicXyBitmap(p_element_table_AP,fl_coord_P);
               }
               else
            #endif
                {
                  #if NB_ALL_BITMAPS > 0
                  GfxManagerBuildStaticXyBitmap(p_element_table_AP, fl_coord_P);
                  #endif
               }
            }
         #else
            GFX_ELEMENT_PROPERTY fl_elem_property_S;
            fl_elem_property_S.id = l_cur_dyn_bitmap_S[fl_element_id_E];
          #if NB_ALL_DYN_XY_BITMAPS > 0
            if(fl_elem_property_S.id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
            {
               GfxManagerBuildDynamicXyBitmap((void *)&fl_elem_property_S
				                                 #if NB_DYN_BITMAPS > 0
				                                   ,NULL
                                                 #endif
												   );
            }
            else
          #endif
            {
               GfxManagerBuildStaticXyBitmap((void *)&fl_elem_property_S, 0);
            }
         #endif
         }
      }
      else
     #endif
   #endif
   #if NB_DYN_TEXTS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_TEXTS_INDEX)
      {
         fl_element_id_E = GET_DYN_TEXTS_INDEX(fl_element_id_E);

      #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
       #if NB_DYNXY_TEXTS > 0
         if(fl_element_id_E < NB_DYNXY_TEXTS)
         {
            (void)GfxDriverBuildText(
                     &l_dyn_text_dyn_property_S[fl_element_id_E],
                     &lc_dyn_text_def_S[fl_element_id_E]);
         }
         else
       #endif
         {
            GfxDriverBuildText(
                     p_element_table_AP->prop,
                     &lc_dyn_text_def_S[fl_element_id_E]);
         }
      #else
       #if NB_DYNXY_TEXTS > 0
         if(fl_element_id_E < NB_DYNXY_TEXTS)
         {
            (void)GfxDriverBuildText(
                     &l_dyn_text_dyn_property_S[fl_element_id_E],
                     &lc_dyn_text_def_S[fl_element_id_E]);
         }
         else
       #endif
         {
            GfxDriverBuildText(
                     &lc_dyn_text_prop_def_S[fl_element_id_E-NB_DYNXY_TEXTS],
                     &lc_dyn_text_def_S[fl_element_id_E]);
         }
      #endif
      }
      else
   #endif
   #if NB_DYN_WIDGETS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_WIDGETS_INDEX)
      {
      #if NB_WIDGETS > 0
         fl_element_id_E = GET_DYN_WIDGETS_INDEX(fl_element_id_E);
         (void)GfxManagerGetSelectedWidgetId(&fl_element_id_E);
         if((fl_element_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_element_id_E < MAX_INDEX_WIDGETS_INDEX))
         {
            /*
            ** Build if its a valid widget.
            */
            fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
            GfxManagerBuildWidget(&lc_widget_table_S[fl_element_id_E]);
         }
       #if NB_DYNAMIC_CLIP_WIDGETS > 0
         else if(fl_element_id_E < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
         {
            fl_element_id_E = GET_DYN_CLIP_WIDGETS_INDEX(fl_element_id_E);
            GfxManagerBuildWidget(&lc_dyn_clip_widget_table_S[fl_element_id_E]);
         }
       #endif
      #endif
      }
      else
   #endif
   #if NB_DYNAMIC_CLIP_WIDGETS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
      {
         fl_element_id_E = GET_DYN_CLIP_WIDGETS_INDEX(fl_element_id_E);
         GfxManagerBuildWidget(&lc_dyn_clip_widget_table_S[fl_element_id_E]);
      }
      else
   #endif
   #if NB_DYN_FILL_SCREENS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_NFILL_INDEX)
      {
         fl_element_id_E = GET_DYN_NFILL_INDEX(fl_element_id_E);
         GfxDriverBuildFillScreen(
             &l_fill_screen_dyn_property_S[fl_element_id_E],
             &l_fill_screen_def_dyn_S[fl_element_id_E]);
      }
      else
   #endif
   #if NB_ALL_DYN_XY_BITMAPS > 0
      if(fl_element_id_E < MAX_INDEX_DYN_XY_BITMAP_INDEX)
      {
         GfxManagerBuildDynamicXyBitmap(p_element_table_AP
				                                 #if NB_DYN_BITMAPS > 0
				                                   ,NULL
                                                 #endif
												   );
      }
      else
   #endif
   #if NB_FILL_SCREENS > 0
      if(fl_element_id_E < MAX_INDEX_FILL_SCREENS_INDEX)
      {
         fl_element_id_E = GET_FILL_SCREENS_INDEX(fl_element_id_E);
         #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
      GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        (COORDINATE_DEF_T const *)p_element_table_AP->prop,
             #else
             &lc_fill_screen_def_coord_S[fl_element_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_fill_screen_def_S[fl_element_id_E].width,
        lc_fill_screen_def_S[fl_element_id_E].height);
         #endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
         GfxDriverBuildFillScreen(
           #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
             (COORDINATE_DEF_T const *)p_element_table_AP->prop,
           #else
             &lc_fill_screen_def_coord_S[fl_element_id_E],
           #endif
             &lc_fill_screen_def_S[fl_element_id_E]);
      }
      else
   #endif
   #if NB_VERT_PATTERN_FILL > 0
      if(fl_element_id_E < MAX_INDEX_VERT_PATTERN_FILL_INDEX)
      {
         fl_element_id_E = GET_VERT_PATTERN_FILL_INDEX(fl_element_id_E);
         #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
      GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        (COORDINATE_DEF_T const *)p_element_table_AP->prop,
             #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_pattern_fill_def_S[fl_element_id_E].width,
        lc_pattern_fill_def_S[fl_element_id_E].height);
         #endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
         GfxDriverBuildVerticalPatternFill(
           #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
             (COORDINATE_DEF_T const *)p_element_table_AP->prop,
           #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
           #endif
             &lc_pattern_fill_def_S[fl_element_id_E]);
      }
      else
   #endif
   #if NB_HORZ_PATTERN_FILL > 0
      if(fl_element_id_E < MAX_INDEX_HORZ_PATTERN_FILL_INDEX)
      {
         fl_element_id_E = GET_HORZ_PATTERN_FILL_INDEX(fl_element_id_E);
          #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
      GfxManagerUpdateClipData(
             #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        (COORDINATE_DEF_T const *)p_element_table_AP->prop,
             #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
             #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
             lc_pattern_fill_def_S[fl_element_id_E].width,
        lc_pattern_fill_def_S[fl_element_id_E].height);
         #endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */
         GfxDriverBuildHorizontalPatternFill(
           #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
             (COORDINATE_DEF_T const *)p_element_table_AP->prop,
           #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
           #endif
             &lc_pattern_fill_def_S[fl_element_id_E]);
      }
      else
   #endif
   #if NB_ALL_BITMAPS > 0
      if(fl_element_id_E < MAX_INDEX_BITMAPS_INDEX)
      {
         GfxManagerBuildStaticXyBitmap(p_element_table_AP, NULL);
      }
      else
   #endif
   #if NB_WIDGETS > 0
      if(fl_element_id_E < MAX_INDEX_WIDGETS_INDEX)
      {
      #ifdef GFX_ALIGNED_WIDGETS_ENABLED
         WIDGET_DEF_T const * fl_widget_ptr;
         fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
         fl_widget_ptr      = &lc_widget_table_S[fl_element_id_E];

         if(((fl_widget_ptr->property & GFX_WIDGET_ALIGN_MASK) == GFX_WIDGET_ALIGN_NONE) ||
            (fl_widget_ptr->list.nb_elements <= 1) )
         {
            GfxManagerBuildWidget(fl_widget_ptr);
         }
         else
         {
            GfxManagerBuildAlignedWidget(fl_widget_ptr);
         }
      #else
         fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
         GfxManagerBuildWidget(&lc_widget_table_S[fl_element_id_E]);
      #endif
      }
      else
   #endif
   #if NB_STATIC_TEXTS > 0
      if(fl_element_id_E < MAX_INDEX_STEXTS_INDEX)
      {
         fl_element_id_E = GET_STEXTS_INDEX(fl_element_id_E);
         (void)GfxDriverBuildText(
            #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
              p_element_table_AP->prop,
            #else
              &lc_static_text_prop_def_S[fl_element_id_E],
            #endif
              &lc_static_text_def_S[fl_element_id_E]);
      }
      else
   #endif
      {
      }
   }
}

#endif

#if (NB_WIDGETS > 0)
#ifdef GFX_ALIGNED_WIDGETS_ENABLED
/****************************************************************************
Function Name        : GfxManagerBuildAlignedWidget
Description          : The child elements in the passed widgets are built
                       with the specified alignment. First element size
                       information will be used for finding the area to which
                       alignment needs to be done. Rest of the element sizes
                       are added together and then limited to the total area
                       of the first element. This function then performs a
                       aligned build of elements by dynamically calculating
                       XY location for each elements at run time.
Invocation           : internally by the manager.
Parameters           : Pointer to aligned widget.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildAlignedWidget(WIDGET_DEF_T const * p_widget_ptr)
{
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   RECTANGLE_DEF_T fl_clip_area_S;
#endif
   UINT16              fl_nb_elements_U16  = p_widget_ptr->list.nb_elements;
   UINT16              fl_count_U16;
   RECTANGLE_DEF_T    fl_base_size_S;
   RECTANGLE_DEF_T    fl_size_S;
   GFX_SIZE_W_T       fl_total_width = 0;
   GFX_SIZE_W_T       fl_available_width = 0;
   GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;

   GfxManagerGetElementSizeInfo(fl_element_table_A, &fl_base_size_S);

#ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
   fl_base_size_S.x   = ((COORDINATE_DEF_T const *)fl_element_table_A->prop)->x;
   fl_base_size_S.y   = ((COORDINATE_DEF_T const *)fl_element_table_A->prop)->y;
#endif
   fl_available_width = fl_base_size_S.w;
   fl_element_table_A++;
   fl_nb_elements_U16--;
   fl_count_U16 = fl_nb_elements_U16;

   while(fl_count_U16 > 0)
   {
      fl_size_S.w = fl_available_width;
      GfxManagerGetElementSizeInfo(fl_element_table_A, &fl_size_S);
   #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      if(fl_element_table_A->prop != 0)
      {
         fl_size_S.x = ((COORDINATE_DEF_T const *)fl_element_table_A->prop)->x;
         fl_size_S.y = ((COORDINATE_DEF_T const *)fl_element_table_A->prop)->y;
      }
      else
      {
         fl_size_S.x = fl_base_size_S.x;
         fl_size_S.y = fl_base_size_S.y;
      }
   #endif
      if(fl_size_S.w != 0)
      {
         fl_total_width += fl_size_S.w;
         if(fl_total_width > fl_base_size_S.w)
         {
            fl_total_width    -= fl_size_S.w;
            fl_nb_elements_U16 -= fl_count_U16;
            fl_count_U16        = 0;
         }
         else
         {
            fl_element_table_A++;
            fl_count_U16--;
            if(fl_count_U16 != 0)
            {
               fl_size_S.w    += p_widget_ptr->inter_element_space;
               fl_total_width += p_widget_ptr->inter_element_space;
               if(fl_available_width > fl_size_S.w)
               {
                  fl_available_width -= fl_size_S.w;
               }
               else
               {
                  fl_nb_elements_U16 -= fl_count_U16;
                  fl_count_U16        = 0;
               }
            }
         }
      }
      else
      {
         fl_element_table_A++;
         fl_count_U16--;
      }
   }

   if((fl_base_size_S.w > 0) && (fl_total_width <= fl_base_size_S.w))
   {
   #ifdef GFX_OPEN_VG
      VGfloat fl_matrix[9];
      GfxDriverGetMatrix(fl_matrix);
   #endif
      if((p_widget_ptr->property & GFX_WIDGET_ALIGN_MASK) > GFX_WIDGET_ALIGN_LEFT)
      {
         fl_base_size_S.x += (fl_base_size_S.w >> 1);
         fl_base_size_S.w  = fl_total_width;
         if((p_widget_ptr->property & GFX_WIDGET_ALIGN_MASK) == GFX_WIDGET_ALIGN_CENTER)
         {
            fl_total_width >>= 1;
         }
         else
         {
            fl_total_width--;
         }
         if(fl_base_size_S.x > fl_total_width)
         {
            fl_base_size_S.x -= fl_total_width;
         }
         else
         {
            fl_base_size_S.x = 0;
         }
      }
      else
      {
         fl_base_size_S.w = fl_total_width;
      }
   #ifdef GFX_CLIPPED_WIDGETS_ENABLED
      GfxDriverGetClipArea(&fl_clip_area_S);
    #if NB_STATIC_CLIP_AREA > 0
      if((p_widget_ptr->property & GFX_WIDGET_CLIP_MASK) == GFX_WIDGET_CLIP_STATIC)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_widget_static_clip_list_SA[p_widget_ptr->clip_index].clip);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_widget_static_clip_list_SA[p_widget_ptr->clip_index].clip);
        #endif        
      #ifdef GFX_OPEN_VG
         GfxDriverMultMatrix(&l_widget_static_clip_list_SA[p_widget_ptr->clip_index].matrix);
      #endif
      }
      else
    #endif
    #if NB_DYNAMIC_CLIP_WIDGETS > 0
      if((p_widget_ptr->property & GFX_WIDGET_CLIP_MASK) == GFX_WIDGET_CLIP_DYNAMIC)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].clip);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].clip);
        #endif       
      #ifdef GFX_OPEN_VG
         GfxDriverMultMatrix(&l_widget_dynamic_clip_list_SA[p_widget_ptr->clip_index].matrix);
      #endif
      }
      else
    #endif
      {
      }
   #endif
      GfxManagerBuildElement(p_widget_ptr->list.element_table);
      fl_element_table_A = &p_widget_ptr->list.element_table[1];
      while(fl_nb_elements_U16 > 0)
      {
         GfxManagerBuildAlignedElement(fl_element_table_A++, &fl_base_size_S, p_widget_ptr->inter_element_space);
         fl_nb_elements_U16--;
      }
   #ifdef GFX_CLIPPED_WIDGETS_ENABLED
      GfxDriverSetClipArea(&fl_clip_area_S);
   #endif
   #ifdef GFX_OPEN_VG
      GfxDriverSetMatrix(fl_matrix);
   #endif
   }
}

/****************************************************************************
Function Name        : GfxManagerGetElementSizeInfo
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxManagerGetElementSizeInfo(GFX_ELEMENT_PROPERTY const * p_element_table_AP, RECTANGLE_DEF_T * p_size_SP)
{
   GFX_ELEMENT_ID_T fl_dyn_table_index = p_element_table_AP->id;
#if (NB_ALL_BITMAPS+NB_ALL_DYN_XY_BITMAPS) > 0
  #if NB_DYN_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_BITMAPS_INDEX)
   {
      fl_dyn_table_index = GET_DYN_BITMAPS_INDEX(fl_dyn_table_index);
      if(fl_dyn_table_index < NB_DYN_BITMAPS)
      {
      #if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
         GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_image_elem_list_S[fl_dyn_table_index];
         fl_dyn_table_index = l_cur_dyn_bitmap_S[fl_dyn_table_index];
         p_size_SP->w = 0;
         p_size_SP->h = 0;
         if(fl_dyn_table_index < fl_elem_list_SP->nb_elements)
         {
            p_element_table_AP = &fl_elem_list_SP->element_table[fl_dyn_table_index];
         #if NB_ALL_DYN_XY_BITMAPS > 0
            if(p_element_table_AP->id >= MAX_INDEX_DYN_XY_BITMAP_INDEX)
         #endif
            {
               GfxManagerGetStaticXyBitmapInfo(p_element_table_AP, p_element_table_AP->id, p_size_SP);
               if(p_element_table_AP->prop != 0)
               {
                  p_size_SP->x = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->x;
                  p_size_SP->y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
               }
            }
         }
      #else
         fl_dyn_table_index = l_cur_dyn_bitmap_S[fl_dyn_table_index];
       #if NB_ALL_DYN_XY_BITMAPS > 0
         if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BITMAP_INDEX)
         {
            /*
            ** Dynamic XY bitmap is not supported in an aligned widget.
            */
            p_size_SP->w = 0;
            p_size_SP->h = 0;
         }
         else
       #endif
         {
            GfxManagerGetStaticXyBitmapInfo(p_element_table_AP, fl_dyn_table_index, p_size_SP);
         }
      #endif
      }
   }
   else
  #endif
#endif
#if NB_DYN_TEXTS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_TEXTS_INDEX)
   {
      GFX_TEXT_INFO fl_text_info_S;
    UINT8         fl_clip_flag_U8;
    UINT8         temp  = 0;

      fl_dyn_table_index                 = GET_DYN_TEXTS_INDEX(fl_dyn_table_index);
      fl_text_info_S.dyn_text_def_SP     = &lc_dyn_text_def_S[fl_dyn_table_index];
      fl_text_info_S.print_str_P         = fl_text_info_S.dyn_text_def_SP->data_ptr;
      fl_text_info_S.append_string_width = 0;
      if(p_size_SP->w > fl_text_info_S.dyn_text_def_SP->width)
      {
         fl_text_info_S.max_available_width = fl_text_info_S.dyn_text_def_SP->width;
      }
      else
      {
         fl_text_info_S.max_available_width = p_size_SP->w;
      }
    fl_clip_flag_U8 = GfxDriverGetTextWidth(&fl_text_info_S, &temp);
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
      p_size_SP->x = lc_dyn_text_prop_def_S[fl_dyn_table_index].coord.x;
      p_size_SP->y = lc_dyn_text_prop_def_S[fl_dyn_table_index].coord.y;
   #endif
      p_size_SP->w = fl_text_info_S.print_width;
      p_size_SP->h = 0;
   }
   else
#endif
#if ((NB_DYN_WIDGETS > 0) || (NB_DYNAMIC_CLIP_WIDGETS > 0))
   if(fl_dyn_table_index < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
   {
      /*
      ** Widget expansion is not supported at the moment inside a aligned group
      */
      p_size_SP->w = 0;
      p_size_SP->h = 0;
   }
   else
#endif
#if NB_ALL_DYN_XY_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BITMAP_INDEX)
   {
      /*
      ** Dynamic XY bitmap is not supported in an aligned widget.
      */
      p_size_SP->w = 0;
      p_size_SP->h = 0;
   }
   else
#endif
#if NB_FILL_SCREENS > 0
   if(fl_dyn_table_index < MAX_INDEX_FILL_SCREENS_INDEX)
   {
      fl_dyn_table_index = GET_FILL_SCREENS_INDEX(fl_dyn_table_index);
      p_size_SP->w = lc_fill_screen_def_S[fl_dyn_table_index].width;
      p_size_SP->h = lc_fill_screen_def_S[fl_dyn_table_index].height;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
      p_size_SP->x = lc_fill_screen_def_coord_S[fl_dyn_table_index].x;
      p_size_SP->y = lc_fill_screen_def_coord_S[fl_dyn_table_index].y;
   #endif
   }
   else
#endif
#if NB_VERT_PATTERN_FILL > 0
   if(fl_dyn_table_index < MAX_INDEX_VERT_PATTERN_FILL_INDEX)
   {
      fl_dyn_table_index = GET_VERT_PATTERN_FILL_INDEX(fl_dyn_table_index);
      p_size_SP->w = lc_pattern_fill_def_S[fl_dyn_table_index].width;
      p_size_SP->h = lc_pattern_fill_def_S[fl_dyn_table_index].height;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
      p_size_SP->x = lc_pattern_fill_coord_S[fl_dyn_table_index].x;
      p_size_SP->y = lc_pattern_fill_coord_S[fl_dyn_table_index].y;
   #endif
   }
   else
#endif
#if NB_HORZ_PATTERN_FILL > 0
   if(fl_dyn_table_index < MAX_INDEX_HORZ_PATTERN_FILL_INDEX)
   {
      fl_dyn_table_index = GET_HORZ_PATTERN_FILL_INDEX(fl_dyn_table_index);
      p_size_SP->w = lc_pattern_fill_def_S[fl_dyn_table_index].width;
      p_size_SP->h = lc_pattern_fill_def_S[fl_dyn_table_index].height;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
      p_size_SP->x = lc_pattern_fill_coord_S[fl_dyn_table_index].x;
      p_size_SP->y = lc_pattern_fill_coord_S[fl_dyn_table_index].y;
   #endif
   }
   else
#endif
#if NB_ALL_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_BITMAPS_INDEX)
   {
      GfxManagerGetStaticXyBitmapInfo(p_element_table_AP, fl_dyn_table_index, p_size_SP);
   }
   else
#endif
#if NB_WIDGETS > 0
   if(fl_dyn_table_index < MAX_INDEX_WIDGETS_INDEX)
   {
      /*
      ** widget expansion inside an aligned widget is not supported yet.
      */
      p_size_SP->w = 0;
      p_size_SP->h = 0;
   }
   else
#endif
#if NB_STATIC_TEXTS > 0
   if(fl_dyn_table_index < MAX_INDEX_STEXTS_INDEX)
   {
      GFX_TEXT_INFO fl_text_info_S;
    UINT8         fl_clip_flag_U8;
    UINT8         temp = 0;

      fl_dyn_table_index                 = GET_STEXTS_INDEX(fl_dyn_table_index);
      fl_text_info_S.dyn_text_def_SP     = &lc_static_text_def_S[fl_dyn_table_index];
      fl_text_info_S.print_str_P         = fl_text_info_S.dyn_text_def_SP->data_ptr;
      fl_text_info_S.append_string_width = 0;
      if(p_size_SP->w > fl_text_info_S.dyn_text_def_SP->width)
      {
         fl_text_info_S.max_available_width = fl_text_info_S.dyn_text_def_SP->width;
      }
      else
      {
         fl_text_info_S.max_available_width = p_size_SP->w;
      }
    fl_clip_flag_U8 = GfxDriverGetTextWidth(&fl_text_info_S, &temp);
      p_size_SP->w    = fl_text_info_S.print_width;
      p_size_SP->h    = 0;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
      p_size_SP->x    = lc_static_text_prop_def_S[fl_dyn_table_index].coord.x;
      p_size_SP->y    = lc_static_text_prop_def_S[fl_dyn_table_index].coord.y;
   #endif
   }
   else
#endif
   {
   }
}

/****************************************************************************
Function Name        : GfxManagerBuildAlignedElement
Description          : This function draws the passed element and then updates
                       the available width and next X location for further
                       drawing
Invocation           : internally by the manager.
Parameters           : Element ID, size info and inter element space
Return Value         : Updates p_size_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildAlignedElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP,
                                          RECTANGLE_DEF_T      * p_size_SP,
                                          UINT8                  p_space_U8)
{
   GFX_ELEMENT_ID_T fl_dyn_table_index = p_element_table_AP->id;

#if NB_DYN_ELEMENTS > 0
   if(fl_dyn_table_index < NB_DYN_ELEMENTS)
   {
      /*
      ** Clear the refresh flags corresponding to dynamic element to prevent
      ** continous rebuild.
      */
      l_dyn_element_changed_U8[fl_dyn_table_index] &= ~GFX_SCREEN_CHANGED_FLAG;
   }
#endif
#if (NB_ALL_BITMAPS+NB_ALL_DYN_XY_BITMAPS) > 0
  #if NB_DYN_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_BITMAPS_INDEX)
   {
      fl_dyn_table_index = GET_DYN_BITMAPS_INDEX(fl_dyn_table_index);
      if(fl_dyn_table_index < NB_DYN_BITMAPS)
      {
      #if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
         GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_image_elem_list_S[fl_dyn_table_index];
         fl_dyn_table_index = l_cur_dyn_bitmap_S[fl_dyn_table_index];
         if(fl_dyn_table_index < fl_elem_list_SP->nb_elements)
         {
            p_element_table_AP = &fl_elem_list_SP->element_table[fl_dyn_table_index];
         #if NB_ALL_DYN_XY_BITMAPS > 0
            if(p_element_table_AP->id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
            {
               /*
               ** Dynamic XY bitmap is not supported in an aligned widget.
               */
            }
            else
         #endif
            {
               GfxManagerBuildAlignedStaticXyBitmap(p_element_table_AP, p_size_SP, p_space_U8);
            }
         }
      #else
         GFX_ELEMENT_PROPERTY fl_elem_property_S;
         fl_elem_property_S.id = l_cur_dyn_bitmap_S[fl_dyn_table_index];
       #if NB_ALL_DYN_XY_BITMAPS > 0
         if(fl_elem_property_S.id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
         {
         }
         else
       #endif
         {
            GfxManagerBuildAlignedStaticXyBitmap((void *)&fl_elem_property_S, p_size_SP, p_space_U8);
         }
      #endif
      }
   }
   else
  #endif
#endif
#if NB_DYN_TEXTS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_TEXTS_INDEX)
   {
      DYN_TEXT_DEF_T    fl_dyn_text_def_S;
      GFX_TEXT_PROPERTY fl_text_property_S;
      GFX_SIZE_X_T      fl_end_x;
      GFX_SIZE_W_T      fl_width;

      fl_dyn_table_index = GET_DYN_TEXTS_INDEX(fl_dyn_table_index);
      memcpy(&fl_dyn_text_def_S, &lc_dyn_text_def_S[fl_dyn_table_index], sizeof(DYN_TEXT_DEF_T));
      if(fl_dyn_text_def_S.width > p_size_SP->w)
      {
         fl_dyn_text_def_S.width = p_size_SP->w;
      }
      fl_text_property_S.coord.x = p_size_SP->x;

    #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_text_property_S.coord.y    = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->coord.y;
      fl_text_property_S.draw_color = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->draw_color;
     #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      fl_text_property_S.nb_lines   = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->nb_lines;
     #endif
    #else
      fl_text_property_S.coord.y    = lc_dyn_text_prop_def_S[fl_dyn_table_index].coord.y;
      fl_text_property_S.draw_color = lc_dyn_text_prop_def_S[fl_dyn_table_index].draw_color;
     #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      fl_text_property_S.nb_lines   = lc_dyn_text_prop_def_S[fl_dyn_table_index].nb_lines;
     #endif
    #endif

      fl_end_x = GfxDriverBuildText(&fl_text_property_S, &fl_dyn_text_def_S);

      fl_end_x    += p_space_U8;
      fl_width     = (fl_end_x - p_size_SP->x); /* calculate the width of the text */
      p_size_SP->x = fl_end_x;
      if(p_size_SP->w > fl_width)
      {
         p_size_SP->w -= fl_width;
      }
      else
      {
         p_size_SP->w = 0;
      }
   }
   else
#endif
#if ((NB_DYN_WIDGETS > 0) || (NB_DYNAMIC_CLIP_WIDGETS > 0))
   if(fl_dyn_table_index < MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
   {
      /*
      ** Widget expansion is not supported at the moment inside a aligned group
      */
   }
   else
#endif
#if NB_DYN_FILL_SCREENS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_NFILL_INDEX)
   {
      /*
      ** Dynamic XY fillscreens is not supported in an aligned widget.
      */
   }
   else
#endif
#if NB_ALL_DYN_XY_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BITMAP_INDEX)
   {
      /*
      ** Dynamic XY bitmap is not supported in an aligned widget.
      */
   }
   else
#endif
#if NB_FILL_SCREENS > 0
   if(fl_dyn_table_index < MAX_INDEX_FILL_SCREENS_INDEX)
   {
      GFX_SIZE_W_T      fl_width;
      COORDINATE_DEF_T  fl_coordinate_S;

      fl_dyn_table_index = GET_FILL_SCREENS_INDEX(fl_dyn_table_index);
      fl_coordinate_S.x  = p_size_SP->x;
   #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_coordinate_S.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
   #else
      fl_coordinate_S.y = lc_fill_screen_def_coord_S[fl_dyn_table_index].y;
   #endif
      GfxDriverBuildFillScreen(((COORDINATE_DEF_T const *)&fl_coordinate_S),
                               &lc_fill_screen_def_S[fl_dyn_table_index]);
      fl_width      = lc_fill_screen_def_S[fl_dyn_table_index].width;
      fl_width     += p_space_U8;
      p_size_SP->x += fl_width;
      if(p_size_SP->w > fl_width)
      {
         p_size_SP->w -= fl_width;
      }
      else
      {
         p_size_SP->w = 0;
      }
   }
   else
#endif
#if NB_VERT_PATTERN_FILL > 0
   if(fl_dyn_table_index < MAX_INDEX_VERT_PATTERN_FILL_INDEX)
   {
      GFX_SIZE_W_T     fl_width;
      COORDINATE_DEF_T  fl_coordinate_S;
      fl_dyn_table_index = GET_VERT_PATTERN_FILL_INDEX(fl_dyn_table_index);
      fl_coordinate_S.x  = p_size_SP->x;
   #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_coordinate_S.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
   #else
      fl_coordinate_S.y = lc_pattern_fill_coord_S[fl_dyn_table_index].y
   #endif
      GfxDriverBuildVerticalPatternFill(((COORDINATE_DEF_T const *)&fl_coordinate_S),
                                         &lc_pattern_fill_def_S[fl_dyn_table_index]);
      fl_width      = lc_pattern_fill_def_S[fl_dyn_table_index].width;
      fl_width     += p_space_U8;
      p_size_SP->x += fl_width;
      if(p_size_SP->w > fl_width)
      {
         p_size_SP->w -= fl_width;
      }
      else
      {
         p_size_SP->w = 0;
      }
   }
   else
#endif
#if NB_HORZ_PATTERN_FILL > 0
   if(fl_dyn_table_index < MAX_INDEX_HORZ_PATTERN_FILL_INDEX)
   {
      GFX_SIZE_W_T fl_width;
      COORDINATE_DEF_T  fl_coordinate_S;
      fl_dyn_table_index = GET_HORZ_PATTERN_FILL_INDEX(fl_dyn_table_index);
      fl_coordinate_S.x = p_size_SP->x;
   #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_coordinate_S.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
   #else
      fl_coordinate_S.y = lc_pattern_fill_coord_S[fl_dyn_table_index].y;
   #endif
      GfxDriverBuildHorizontalPatternFill(((COORDINATE_DEF_T const *)&fl_coordinate_S),
                                           &lc_pattern_fill_def_S[fl_dyn_table_index]);
      fl_width      = lc_pattern_fill_def_S[fl_dyn_table_index].width;
      fl_width     += p_space_U8;
      p_size_SP->x += fl_width;
      if(p_size_SP->w > fl_width)
      {
         p_size_SP->w -= fl_width;
      }
      else
      {
         p_size_SP->w = 0;
      }
   }
   else
#endif
#if NB_ALL_BITMAPS > 0
   if(fl_dyn_table_index < MAX_INDEX_BITMAPS_INDEX)
   {
      GfxManagerBuildAlignedStaticXyBitmap(p_element_table_AP, p_size_SP, p_space_U8);
   }
   else
#endif
#if NB_WIDGETS > 0
   if(fl_dyn_table_index < MAX_INDEX_WIDGETS_INDEX)
   {
      /*
      ** widget expansion inside an aligned widget is not supported yet.
      */
   }
   else
#endif
#if NB_STATIC_TEXTS > 0
   if(fl_dyn_table_index < MAX_INDEX_STEXTS_INDEX)
   {
      DYN_TEXT_DEF_T    fl_dyn_text_def_S;
      GFX_TEXT_PROPERTY fl_text_property_S;
      GFX_SIZE_X_T      fl_end_x;
      GFX_SIZE_W_T      fl_width;

      fl_dyn_table_index = GET_STEXTS_INDEX(fl_dyn_table_index);
      memcpy(&fl_dyn_text_def_S, &lc_static_text_def_S[fl_dyn_table_index], sizeof(DYN_TEXT_DEF_T));
      if(fl_dyn_text_def_S.width > p_size_SP->w)
      {
         fl_dyn_text_def_S.width = p_size_SP->w;
      }
      fl_text_property_S.coord.x = p_size_SP->x;

   #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_text_property_S.coord.y    = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->coord.y;
      fl_text_property_S.draw_color = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->draw_color;
     #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      fl_text_property_S.nb_lines   = ((GFX_TEXT_PROPERTY const *)p_element_table_AP->prop)->nb_lines;
     #endif
   #else
      fl_text_property_S.coord.y    = lc_static_text_prop_def_S[fl_dyn_table_index].coord.y;
      fl_text_property_S.draw_color = lc_static_text_prop_def_S[fl_dyn_table_index].draw_color;
     #if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
      fl_text_property_S.nb_lines   = lc_static_text_prop_def_S[fl_dyn_table_index].nb_lines;
     #endif
   #endif

      fl_end_x     = GfxDriverBuildText(&fl_text_property_S, &fl_dyn_text_def_S);
      fl_end_x    += p_space_U8;
      fl_width     = (fl_end_x - p_size_SP->x); /* calculate the width of the text */
      p_size_SP->x = fl_end_x;
      if(p_size_SP->w > fl_width)
      {
         p_size_SP->w -= fl_width;
      }
      else
      {
         p_size_SP->w = 0;
      }
   }
   else
#endif
   {
   }
}

#if NB_ALL_BITMAPS > 0
/****************************************************************************
Function Name        : GfxManagerGetStaticXyBitmapInfo
Description          : This function returns the X,Y, Width and Height info
                       for the passed static xy image.
Invocation           : internally by the manager.
Parameters           : element ID, size info.
Return Value         : Updates X,Y, Width and Height info in to p_size_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerGetStaticXyBitmapInfo(GFX_ELEMENT_PROPERTY const * p_element_table_AP, GFX_ELEMENT_ID_T p_dyn_table_index, RECTANGLE_DEF_T * p_size_SP)
{
    p_dyn_table_index = GET_BITMAPS_INDEX(p_dyn_table_index);
 #if NB_SXY_BITMAPS > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_NORMAL_INDEX)
    {
       p_size_SP->w = lc_sxy_bitmap_def_S[p_dyn_table_index].w;
       p_size_SP->h = lc_sxy_bitmap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_bitmap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_bitmap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_ALPHAMAP > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_NORMAL_INDEX;
       p_size_SP->w       = lc_sxy_alphamap_def_S[p_dyn_table_index].w;
       p_size_SP->h       = lc_sxy_alphamap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_alphamap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_alphamap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_OVG > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_OVGMAP_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;

       if(((COORDINATE_DEF_T const *)p_element_table_AP->prop)->p_ovg != 0)
       {
          p_size_SP->w = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->p_ovg->bounds[2];
          p_size_SP->h = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->p_ovg->bounds[3];
       }
       else
       {
          p_size_SP->w = lc_sxy_ovgmap_def_S[p_dyn_table_index].ovg_data->bounds[2];
          p_size_SP->h = lc_sxy_ovgmap_def_S[p_dyn_table_index].ovg_data->bounds[3];
       }
       if(lc_sxy_ovgmap_def_S[p_dyn_table_index].cw != 0 &&  lc_sxy_ovgmap_def_S[p_dyn_table_index].ch != 0)
       {
          if(p_size_SP->w > lc_sxy_ovgmap_def_S[p_dyn_table_index].cw)
          {
             p_size_SP->w = lc_sxy_ovgmap_def_S[p_dyn_table_index].cw;
          }
          if(p_size_SP->h > lc_sxy_ovgmap_def_S[p_dyn_table_index].ch)
          {
             p_size_SP->h = lc_sxy_ovgmap_def_S[p_dyn_table_index].ch;
          }
       }
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_ovgmap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_ovgmap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_COLORTRANSBITMAP > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;
       p_size_SP->w       = lc_sxy_colortransbitmap_def_S[p_dyn_table_index].w;
       p_size_SP->h       = lc_sxy_colortransbitmap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_colortransbitmap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_colortransbitmap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_ALPHABITMAP > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX;
       p_size_SP->w       = lc_sxy_alphabitmap_def_S[p_dyn_table_index].w;
       p_size_SP->h       = lc_sxy_alphabitmap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_alphabitmap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_alphabitmap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_UNIALPHAMAP > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX;
       p_size_SP->w       = lc_sxy_unialphamap_def_S[p_dyn_table_index].w;
       p_size_SP->h       = lc_sxy_unialphamap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_unialphamap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_unialphamap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
 #if NB_SXY_UNIALPHABITMAP > 0
    if(p_dyn_table_index < MAX_INDEX_BMP_DRAW_UNIALPHABITMAP_INDEX)
    {
       p_dyn_table_index -= MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX;
       p_size_SP->w       = lc_sxy_unialphabitmap_def_S[p_dyn_table_index].w;
       p_size_SP->h       = lc_sxy_unialphabitmap_def_S[p_dyn_table_index].h;
   #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       p_size_SP->x = lc_sxy_unialphabitmap_coord_S[p_dyn_table_index].x;
       p_size_SP->y = lc_sxy_unialphabitmap_coord_S[p_dyn_table_index].y;
   #endif
    }
    else
 #endif
    {
       /*
       ** Unsupported draw mode
       */
       p_size_SP->w = 0;
       p_size_SP->h = 0;
    }
}

/****************************************************************************
Function Name        : GfxManagerBuildAlignedStaticXyBitmap
Description          : This function draws static xy bitmaps for an aligned widget
                       build.
Invocation           : Internally by manager.
Parameters           : element property, available area size, inter element space
Return Value         : Updates p_size_SP with available width information after
                       deducting the drawn image width + inter element space.
                       Updates the next x location as well.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildAlignedStaticXyBitmap(GFX_ELEMENT_PROPERTY const * p_element_table_AP, RECTANGLE_DEF_T * p_size_SP, UINT8 p_space_U8)
{
    GFX_ELEMENT_ID_T fl_element_id_E = GET_BITMAPS_INDEX(p_element_table_AP->id);
    GFX_SIZE_W_T     fl_width;
    COORDINATE_DEF_T fl_coordinate_S;

 #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    memcpy(&fl_coordinate_S,p_element_table_AP->prop, sizeof(COORDINATE_DEF_T));
    fl_coordinate_S.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
 #endif
    fl_coordinate_S.x = p_size_SP->x;

 #if NB_SXY_BITMAPS > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_NORMAL_INDEX)
    {
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_bitmap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildBitmapImage(&fl_coordinate_S, &lc_sxy_bitmap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_bitmap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_ALPHAMAP > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX)
    {
       fl_element_id_E -= MAX_INDEX_BMP_DRAW_NORMAL_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_alphamap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildAlphaMapImage(&fl_coordinate_S, &lc_sxy_alphamap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_alphamap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_OVG > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_OVGMAP_INDEX)
    {
       fl_element_id_E -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_ovgmap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildOvgObject(&fl_coordinate_S, &lc_sxy_ovgmap_def_S[fl_element_id_E]);
       if(((COORDINATE_DEF_T const *)p_element_table_AP->prop)->p_ovg != 0)
       {
          fl_width = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->p_ovg->bounds[2];
       }
       else
       {
          fl_width = lc_sxy_ovgmap_def_S[fl_element_id_E].ovg_data->bounds[2];
       }
       if(lc_sxy_ovgmap_def_S[fl_element_id_E].cw != 0 &&  lc_sxy_ovgmap_def_S[fl_element_id_E].ch != 0)
       {
          if(fl_width > lc_sxy_ovgmap_def_S[fl_element_id_E].cw)
          {
             fl_width = lc_sxy_ovgmap_def_S[fl_element_id_E].cw;
          }
       }
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_COLORTRANSBITMAP > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX)
    {
       fl_element_id_E -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_colortransbitmap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildColorTransBitMapImage(&fl_coordinate_S, &lc_sxy_colortransbitmap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_colortransbitmap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_ALPHABITMAP > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX)
    {
       fl_element_id_E  -= MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_alphabitmap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildAlphaBitMapImage(&fl_coordinate_S, &lc_sxy_alphabitmap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_alphabitmap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_UNIALPHAMAP > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX)
    {
       fl_element_id_E  -= MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_unialphamap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildUniAlphaMapImage(&fl_coordinate_S, &lc_sxy_unialphamap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_unialphamap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
 #if NB_SXY_UNIALPHABITMAP > 0
    if(fl_element_id_E < MAX_INDEX_BMP_DRAW_UNIALPHABITMAP_INDEX)
    {
       fl_element_id_E  -= MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX;
    #ifndef GFX_INDEPENDANT_PROPERTY_ENABLED
       fl_coordinate_S.y = lc_sxy_unialphabitmap_coord_S[fl_element_id_E].y;
    #endif
       GfxDriverBuildUniAlphaBitMapImage(&fl_coordinate_S, &lc_sxy_unialphabitmap_def_S[fl_element_id_E]);
       fl_width      = lc_sxy_unialphabitmap_def_S[fl_element_id_E].w;
       fl_width     += p_space_U8;
       p_size_SP->x += fl_width;
       if(p_size_SP->w > fl_width)
       {
          p_size_SP->w -= fl_width;
       }
       else
       {
          p_size_SP->w = 0;
       }
    }
    else
 #endif
    {
       /*
       ** Unsupported draw mode
       */
    }
}
#endif /*#if NB_ALL_BITMAPS > 0*/
#endif /*#ifdef GFX_ALIGNED_WIDGETS_ENABLED*/
#endif /*#if (NB_WIDGETS > 0)*/

#if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
/****************************************************************************
Function Name        : GfxManagerUpdateClipData
Description          : This function shall provide clip data to update the
                       clip list by calling GfxManagerUpdateClipList.
Invocation           : Internally by manager.
Parameters           : x, y coordinates, height and width
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerUpdateClipData(COORDINATE_DEF_T const * coord,GFX_SIZE_W_T width,GFX_SIZE_H_T height)
{
  RECTANGLE_DEF_T fl_clip_data;
#if NB_LAYERS > 1
  if((l_cur_bld_scr_pri_U16 < l_highest_active_priority_U8[gl_active_layer_id_U8]))
#else
    if((l_cur_bld_scr_pri_U16 < l_highest_active_priority_U8[0]))
#endif /* NB_LAYERS > 1 */
      {
      /* update the clip data only if we are building the low priority screens */
      fl_clip_data.x = coord->x;
      fl_clip_data.y = coord->y;
      fl_clip_data.w = width;
      fl_clip_data.h = height;
      GfxManagerUpdateClipList(fl_clip_data);
    }
}/* End of GfxManagerUpdateClipData() */
/****************************************************************************
Function Name        : GfxManagerUpdateClipList
Description          : This function checks for the clip data is present in
                        the list already and if not present update to the clip.
Invocation           : Internally by manager.
Parameters           : clip data information
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerUpdateClipList(RECTANGLE_DEF_T fl_clip_data)
{
  BOOLEAN ret = TRUE;
  UINT8 i = 0;
  UINT8 j = l_clip_count_U8;
  RECTANGLE_DEF_T clip_data;
  for(i=0; ((i < j) && (ret == TRUE)); i++)
  {
    /* browse through the list_clip_area to see whether this data already exists
    if so don't add it and return FALSE */
    if( (fl_clip_data.x == l_clip_area_list_S[i].x) &&
      (fl_clip_data.y == l_clip_area_list_S[i].y) &&
      (fl_clip_data.w == l_clip_area_list_S[i].w) &&
      (fl_clip_data.h == l_clip_area_list_S[i].h)
      )
    {
      /* we have this already in the list don't update it */
      ret = FALSE;
    }
  }
  if(ret == TRUE)
  {
    if(l_clip_count_U8==0)
    {
      /* nothing in the clip list yet this is the first item to be added
      so add it */
      GfxManagerUpdateClip(fl_clip_data);
    }
    else
    {
      l_temp_clip_count_U8 = GfxManagerCheckClipAreaOverlaps(fl_clip_data,0);
      if(l_temp_clip_count_U8 != NO_OF_CLIP_AREAS)
      {
        while(l_temp_clip_count_U8 != l_clip_count_U8)
        {
          clip_data.x = l_clip_area_list_S[l_temp_clip_count_U8].x;
          clip_data.y = l_clip_area_list_S[l_temp_clip_count_U8].y;
          clip_data.w = l_clip_area_list_S[l_temp_clip_count_U8].w;
          clip_data.h = l_clip_area_list_S[l_temp_clip_count_U8].h;
          GfxManagerCheckClipAreaOverlaps(clip_data,l_temp_clip_count_U8+1);
          l_temp_clip_count_U8++;
        }
      }
    }
  }
  return ret;
}/* End of GfxManagerUpdateClipList() */
/****************************************************************************
Function Name        : GfxManagerBuildNormalScreen
Description          : This function prepares the screen for display.
Invocation           : Internally by manager.
Parameters           : Screen ID and Screen table
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerBuildNormalScreen(SCREEN_ID_T screen_id,UINT16 count_U16,SCREEN_TABLE_T const *screen_def_SP)
{
  if(screen_id < NB_SCREENS)
  {
    if((l_dyn_element_changed_U8[screen_id] & GFX_SCREEN_CHANGED_FLAG) != 0)
    {
      /*
      ** if the screen itself is changed rebuild entire screen.
      */
      GfxManagerBuildWidget(&screen_def_SP->widget);
      l_dyn_element_changed_U8[screen_id] &= ~GFX_SCREEN_CHANGED_FLAG;
    }
        #if NB_DYN_ELEMENTS > NB_SCREENS
    else
    {
      /*
      ** No change in screen, so look for any of its dynamic elements are
      ** changed.
      */
      GfxManagerCheckElementChanged(&screen_def_SP->widget);
    }
        #endif /*#if NB_DYN_ELEMENTS > NB_SCREENS*/
  }
}/* End of GfxManagerBuildNormalScreen() */
/****************************************************************************
Function Name        : GfxManagerBuildClippedScreenUtility
Description          : This function prepares the clipped screen for display.
Invocation           : Internally by manager.
Parameters           : Screen ID and Screen table
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerBuildClippedScreenUtility(SCREEN_ID_T  screen_id,UINT16 count_U16,SCREEN_TABLE_T const *screen_def_SP)
{
  if(screen_id < NB_SCREENS)
  {
    if((l_dyn_element_changed_U8[screen_id] & GFX_SCREEN_CHANGED_FLAG) != 0)
    {
      /*
      ** if the screen itself is changed rebuild entire screen.
      */
      GfxManagerBuildWidget(&screen_def_SP->widget);
      l_dyn_element_changed_U8[screen_id] &= ~GFX_SCREEN_CHANGED_FLAG;
    }
        #if NB_DYN_ELEMENTS > NB_SCREENS
    else
    {
      GfxManagerBuildClippedScreen(&screen_def_SP->widget);
    }
        #endif /*#if NB_DYN_ELEMENTS > NB_SCREENS*/

        #if (NB_LAYERS > 1)
    if(count_U16 == l_highest_active_priority_U8[gl_active_layer_id_U8])
        #else
      if(count_U16 == l_highest_active_priority_U8[0])
        #endif /* (NB_LAYERS > 1) */
        {
        GfxManagerReSetClipArea();
        GfxDriverReSetClipArea();
      }
  }
}/* GfxManagerBuildClippedScreenUtility() */
/****************************************************************************
Function Name        : GfxManagerIsDynElementChanged
Description          : This function checks for any dynamic element change in
                       the screen.
Invocation           : Internally by manager.
Parameters           : widget pointer
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerIsDynElementChanged(WIDGET_DEF_T const * p_widget_ptr)
{
  BOOLEAN bLoop = TRUE;
  BOOLEAN bRetVal = FALSE;
  UINT16 fl_nb_elements_U16  = p_widget_ptr->list.nb_elements;
  GFX_ELEMENT_ID_T fl_element_id_E;
  GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;

#if (NB_DYN_WIDGETS > 0) && (NB_WIDGETS > 0)
  BOOLEAN bDynWidget = FALSE;
#endif

  while((bLoop == TRUE) && (fl_nb_elements_U16 > 0))
  {
    fl_element_id_E = fl_element_table_A->id;
    if(fl_element_id_E >= MAX_INDEX_SCREEN_INDEX)
    {
      if(fl_element_id_E < NB_DYN_ELEMENTS)
      {
                #if (NB_DYN_WIDGETS > 0) && (NB_WIDGETS > 0)
        if((fl_element_id_E >= MAX_INDEX_DYN_TEXTS_INDEX) && \
          (fl_element_id_E < MAX_INDEX_DYN_WIDGETS_INDEX)   )
        {
          /* It is a dynamic widget hence bDynWidget to TRUE */
          bDynWidget = TRUE;
        }
                #endif

        if((bDynWidget == FALSE) &&
          ((l_dyn_element_changed_U8[fl_element_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0))
        {
          bRetVal = TRUE;
          /* break out of while loop since we found a change in dynamic element */
          bLoop = FALSE;
        }
      }
    }
    fl_nb_elements_U16--;
    fl_element_table_A++;
  }
  return bRetVal;
}/* End of GfxManagerIsDynElementChanged() */
/****************************************************************************
Function Name        : GfxManagerBuildClippedScreen
Description          : This function builds the clipped screen
Invocation           : Internally by manager.
Parameters           : widget pointer
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerBuildClippedScreen(WIDGET_DEF_T const * p_widget_ptr)
{
  UINT16 fl_nb_elements_U16  = p_widget_ptr->list.nb_elements;
  GFX_ELEMENT_PROPERTY const * fl_element_table_A = p_widget_ptr->list.element_table;
  GFX_ELEMENT_ID_T       fl_elem_id_E;

  if(GfxManagerIsDynElementChanged(p_widget_ptr) != FALSE)
  {
    GfxDriverReSetClipArea();
    GfxManagerBuildWidget(p_widget_ptr);
  }
  else
  {
    while(fl_nb_elements_U16 > 0)
    {
      fl_elem_id_E = fl_element_table_A->id;

      if((fl_elem_id_E >= MAX_INDEX_BITMAPS_INDEX) && \
        (fl_elem_id_E < MAX_INDEX_WIDGETS_INDEX)   )
      {
        /* element is a widget so again call this function with selected widgetid */
        fl_elem_id_E = GET_WIDGETS_INDEX(fl_elem_id_E);
        GfxManagerBuildClippedScreen(&lc_widget_table_S[fl_elem_id_E]);
      }
            #if (NB_DYN_WIDGETS > 0)
      else if((fl_elem_id_E >= MAX_INDEX_DYN_TEXTS_INDEX) && \
        (fl_elem_id_E < MAX_INDEX_DYN_WIDGETS_INDEX))
      {
        /* it is a dynamic widget */
        if((l_dyn_element_changed_U8[fl_elem_id_E] & GFX_SCREEN_CHANGED_FLAG) != 0)
        {
          /* dynamic widget is changed so build without clipping */
          l_dyn_element_changed_U8[fl_elem_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
          fl_elem_id_E      = GET_DYN_WIDGETS_INDEX(fl_elem_id_E);
          (void)GfxManagerGetSelectedWidgetId(&fl_elem_id_E);
          if((fl_elem_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_elem_id_E < MAX_INDEX_WIDGETS_INDEX))
          {
            fl_elem_id_E = GET_WIDGETS_INDEX(fl_elem_id_E);
            GfxDriverReSetClipArea();
            GfxManagerBuildWidget(&lc_widget_table_S[fl_elem_id_E]);
          }
        }
        else
        {
          /* it is a dynamic widget but it is not changed so again call this function
          with selected widget */
          fl_elem_id_E      = GET_DYN_WIDGETS_INDEX(fl_elem_id_E);
         (void)GfxManagerGetSelectedWidgetId(&fl_elem_id_E);
          if((fl_elem_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_elem_id_E < MAX_INDEX_WIDGETS_INDEX))
          {
            fl_elem_id_E = GET_WIDGETS_INDEX(fl_elem_id_E);
            GfxManagerBuildClippedScreen(&lc_widget_table_S[fl_elem_id_E]);
          }
        }
      }
            #endif /* (NB_DYN_WIDGETS > 0) */
      else
      {
        GfxManagerBuildClippedElement(fl_element_table_A);
      }

      fl_nb_elements_U16--;
      fl_element_table_A++;
    }
  }
}/* End of GfxManagerBuildClippedScreen() */

/****************************************************************************
Function Name        : GfxManagerBuildClippedElement
Description          : This function calls the different elements in the
                       screen and builds them
Invocation           : Internally by manager
Parameters           : element table pointer
Return Value         : Void
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildClippedElement(GFX_ELEMENT_PROPERTY const * p_element_table_AP)
{
  RECTANGLE_DEF_T fl_image_area;
  UINT8 l_clip_region_U8 = 0;
  UINT8 l_start_index_U8 = 0;
  UINT8 l_test_clip_count_U8 = 0;

  GFX_ELEMENT_ID_T fl_element_id_E = p_element_table_AP->id;

  if(fl_element_id_E >= MAX_INDEX_SCREEN_INDEX)
  {
    if(fl_element_id_E < NB_DYN_ELEMENTS)
    {
      l_dyn_element_changed_U8[fl_element_id_E] &= ~GFX_SCREEN_CHANGED_FLAG;
    }
   #if (NB_ALL_BITMAPS+NB_ALL_DYN_XY_BITMAPS) > 0
     #if NB_DYN_BITMAPS > 0
    if(fl_element_id_E < MAX_INDEX_DYN_BITMAPS_INDEX)
    {
      fl_element_id_E = GET_DYN_BITMAPS_INDEX(fl_element_id_E);
      if(fl_element_id_E < NB_DYN_BITMAPS)
      {
         #if defined(GFX_DYNAMIC_INDEXING_TABLE_SUPPORT) || defined(GFX_INDEPENDANT_PROPERTY_ENABLED)
        GFX_ELEMENT_LIST const * fl_elem_list_SP = &lc_dynamic_image_elem_list_S[fl_element_id_E];
        COORDINATE_DEF_T       * fl_coord_P      = 0;
          #if NB_DYNXY_DIMAGES > 0
        if(fl_element_id_E < NB_DYNXY_DIMAGES)
        {
          fl_coord_P = &l_d_image_dyn_property_S[fl_element_id_E];
        }
          #endif
        fl_element_id_E = l_cur_dyn_bitmap_S[fl_element_id_E];
        if(fl_element_id_E < fl_elem_list_SP->nb_elements)
        {
          p_element_table_AP = &fl_elem_list_SP->element_table[fl_element_id_E];
            #if NB_ALL_DYN_XY_BITMAPS > 0
          if(p_element_table_AP->id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
          {
            GfxManagerBuildDynamicXyBitmap(p_element_table_AP
				                                 #if NB_DYN_BITMAPS > 0
				                                   ,NULL
                                                 #endif
												   );
          }
          else
            #endif
            {
            GfxManagerBuildClippedStaticXyBitmap(p_element_table_AP, fl_coord_P);
          }
        }
         #else
        GFX_ELEMENT_PROPERTY fl_elem_property_S;
        fl_elem_property_S.id = l_cur_dyn_bitmap_S[fl_element_id_E];
          #if NB_ALL_DYN_XY_BITMAPS > 0
        if(fl_elem_property_S.id < MAX_INDEX_DYN_XY_BITMAP_INDEX)
        {
          GfxManagerBuildDynamicXyBitmap((void *)&fl_elem_property_S
				                                 #if NB_DYN_BITMAPS > 0
				                                   ,NULL
                                                 #endif
												   );
        }
        else
          #endif
          {
          GfxManagerBuildClippedStaticXyBitmap((void *)&fl_elem_property_S, 0);
        }
         #endif
      }
    }
    else
     #endif
   #endif
   #if NB_DYN_TEXTS > 0
    if(fl_element_id_E < MAX_INDEX_DYN_TEXTS_INDEX)
    {
      UINT8       fl_font_id;
      GFX_FONT    const * fl_font;
      fl_element_id_E = GET_DYN_TEXTS_INDEX(fl_element_id_E);

      #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        fl_image_area.x = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->x;
        fl_image_area.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
      #else
        fl_image_area.x = lc_dyn_text_prop_def_S[fl_element_id_E].x;
        fl_image_area.y = lc_dyn_text_prop_def_S[fl_element_id_E].y;
      #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
      fl_image_area.w = lc_dyn_text_def_S[fl_element_id_E].width;
      fl_font_id = lc_dyn_text_def_S[fl_element_id_E].font_id;
      fl_font = &lc_gfx_font_table[fl_font_id];
      #if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
        if(fl_font->is_group != 0)
        {
        fl_font_id = GfxDriverGetGrpSelFontId(fl_font_id);
        fl_font = &lc_gfx_font_table[fl_font_id];
        }
      #endif
      fl_image_area.h = fl_font.p.height;
      for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
      {
        l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);

        if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
        {
            #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
            RECTANGLE_DEF_T  fl_widget_clip_area;
            fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
            GfxDriverSetClipArea(&fl_widget_clip_area);
            #else
            GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
            #endif         

            #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (void)GfxDriverBuildText(
            p_element_table_AP->prop,
            &lc_dyn_text_def_S[fl_element_id_E]);
            #else
              #if NB_DYNXY_TEXTS > 0
          if(fl_element_id_E < NB_DYNXY_TEXTS)
          {
            (void)GfxDriverBuildText(
              &l_dyn_text_dyn_property_S[fl_element_id_E],
              &lc_dyn_text_def_S[fl_element_id_E]);
          }
          else
              #endif
            {
            (void)GfxDriverBuildText(
              &lc_dyn_text_prop_def_S[fl_element_id_E-NB_DYNXY_TEXTS],
              &lc_dyn_text_def_S[fl_element_id_E]);
          }
            #endif

          l_start_index_U8 = l_clip_region_U8+1;
        }
      }
    }
    else
   #endif
   #if NB_DYN_WIDGETS > 0
    if(fl_element_id_E < MAX_INDEX_DYN_WIDGETS_INDEX)
    {
      #if NB_WIDGETS > 0
      fl_element_id_E = GET_DYN_WIDGETS_INDEX(fl_element_id_E);
      (void)GfxManagerGetSelectedWidgetId(&fl_element_id_E);
      if((fl_element_id_E >= MAX_INDEX_BITMAPS_INDEX) && (fl_element_id_E < MAX_INDEX_WIDGETS_INDEX))
      {
        /*
        ** Build if its a valid widget.
        */
        fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
        GfxManagerBuildWidget(&lc_widget_table_S[fl_element_id_E]);
      }
      #endif
    }
    else
   #endif
   #if NB_DYN_FILL_SCREENS > 0
    if(fl_element_id_E < MAX_INDEX_DYN_NFILL_INDEX)
    {
      fl_element_id_E = GET_DYN_NFILL_INDEX(fl_element_id_E);
      GfxDriverBuildFillScreen(
        &l_fill_screen_dyn_property_S[fl_element_id_E],
        &l_fill_screen_def_dyn_S[fl_element_id_E]);
    }
    else
   #endif
   #if NB_ALL_DYN_XY_BITMAPS > 0
    if(fl_element_id_E < MAX_INDEX_DYN_XY_BITMAP_INDEX)
    {
      GfxManagerBuildDynamicXyBitmap(p_element_table_AP
				                                 #if NB_DYN_BITMAPS > 0
				                                   ,NULL
                                                 #endif
												   );
    }
    else
   #endif
   #if NB_FILL_SCREENS > 0
    if(fl_element_id_E < MAX_INDEX_FILL_SCREENS_INDEX)
    {
      fl_element_id_E = GET_FILL_SCREENS_INDEX(fl_element_id_E);

         #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
      fl_image_area.x = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->x;
      fl_image_area.y = ((COORDINATE_DEF_T const *)p_element_table_AP->prop)->y;
         #else
      fl_image_area.x = lc_fill_screen_def_coord_S[fl_element_id_E].x;
      fl_image_area.y = lc_fill_screen_def_coord_S[fl_element_id_E].y;
         #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

      fl_image_area.w = lc_fill_screen_def_S[fl_element_id_E].width;
      fl_image_area.h = lc_fill_screen_def_S[fl_element_id_E].height;

      for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
      {
        l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
        if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
        {
          #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
          RECTANGLE_DEF_T  fl_widget_clip_area;
          fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
          GfxDriverSetClipArea(&fl_widget_clip_area);
          #else
          GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
          #endif
          GfxDriverBuildFillScreen(
                  #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
            (COORDINATE_DEF_T const *)p_element_table_AP->prop,
                  #else
                  &lc_fill_screen_def_coord_S[fl_element_id_E],
                  #endif
            &lc_fill_screen_def_S[fl_element_id_E]);

          l_start_index_U8 = l_clip_region_U8+1;
        }
      }
    }
    else
   #endif
   #if NB_VERT_PATTERN_FILL > 0
    if(fl_element_id_E < MAX_INDEX_VERT_PATTERN_FILL_INDEX)
    {
      fl_element_id_E = GET_VERT_PATTERN_FILL_INDEX(fl_element_id_E);
      GfxDriverBuildVerticalPatternFill(
           #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        (COORDINATE_DEF_T const *)p_element_table_AP->prop,
           #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
           #endif
        &lc_pattern_fill_def_S[fl_element_id_E]);
    }
    else
   #endif
   #if NB_HORZ_PATTERN_FILL > 0
    if(fl_element_id_E < MAX_INDEX_HORZ_PATTERN_FILL_INDEX)
    {
      fl_element_id_E = GET_HORZ_PATTERN_FILL_INDEX(fl_element_id_E);
      GfxDriverBuildHorizontalPatternFill(
           #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
        (COORDINATE_DEF_T const *)p_element_table_AP->prop,
           #else
             &lc_pattern_fill_coord_S[fl_element_id_E],
           #endif
        &lc_pattern_fill_def_S[fl_element_id_E]);
    }
    else
   #endif
   #if NB_ALL_BITMAPS > 0
    if(fl_element_id_E < MAX_INDEX_BITMAPS_INDEX)
    {
      GfxManagerBuildClippedStaticXyBitmap(p_element_table_AP, 0);
    }
    else
   #endif
   #if NB_WIDGETS > 0
    if(fl_element_id_E < MAX_INDEX_WIDGETS_INDEX)
    {
      #ifdef GFX_ALIGNED_WIDGETS_ENABLED
      WIDGET_DEF_T const * fl_widget_ptr;
      fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
      fl_widget_ptr      = &lc_widget_table_S[fl_element_id_E];
      if(((fl_widget_ptr->property & GFX_WIDGET_CLIP_MASK) == GFX_WIDGET_ALIGN_NONE) ||
        (fl_widget_ptr->list.nb_elements <= 1 ))
      {
        GfxManagerBuildWidget(fl_widget_ptr);
      }
      else
      {
        GfxManagerBuildAlignedWidget(fl_widget_ptr);
      }
      #else
      fl_element_id_E = GET_WIDGETS_INDEX(fl_element_id_E);
      GfxManagerBuildWidget(&lc_widget_table_S[fl_element_id_E]);
      #endif
    }
    else
   #endif
   #if NB_STATIC_TEXTS > 0
    if(fl_element_id_E < MAX_INDEX_STEXTS_INDEX)
    {
      fl_element_id_E = GET_STEXTS_INDEX(fl_element_id_E);
      (void)GfxDriverBuildText(
            #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
              p_element_table_AP->prop,
            #else
              &lc_static_text_prop_def_S[fl_element_id_E],
            #endif
        &lc_static_text_def_S[fl_element_id_E]);
    }
    else
   #endif
      {
    }
  }
}/* End of GfxManagerBuildClippedElement() */

#if NB_ALL_BITMAPS > 0
/****************************************************************************
Function Name        : GfxManagerBuildClippedStaticXyBitmap
Description          : This function performs a blind building operation of
                       passed Static XY Bitmap without looking for any change
                       in element
Invocation           : Internally by the manager
Parameters           : Element property in p_elem_property_P and coordinate
                       value in p_coord_P.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerBuildClippedStaticXyBitmap(GFX_ELEMENT_PROPERTY const * p_elem_property_P, COORDINATE_DEF_T * p_coord_P)
{
  RECTANGLE_DEF_T fl_image_area;
  UINT8 l_clip_region_U8 = 0;
  UINT8 l_start_index_U8 = 0;
  UINT8 l_test_clip_count_U8 = 0;

  GFX_ELEMENT_ID_T fl_elem_id_E = GET_BITMAPS_INDEX(p_elem_property_P->id);

 #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
  if(p_coord_P == 0)
  {
    p_coord_P = (void *)p_elem_property_P->prop;
  }
 #endif
 #if NB_SXY_BITMAPS > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_NORMAL_INDEX)
  {
       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_bitmap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_bitmap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_bitmap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_bitmap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildBitmapImage(
                 #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                 #else
                 &lc_sxy_bitmap_coord_S[fl_elem_id_E],
                 #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
          &lc_sxy_bitmap_def_S[fl_elem_id_E]);

        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
 #if NB_SXY_ALPHAMAP > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX)
  {
    fl_elem_id_E -= MAX_INDEX_BMP_DRAW_NORMAL_INDEX;

       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_alphamap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_alphamap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_alphamap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_alphamap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildAlphaMapImage(
                 #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                 #else
                 &lc_sxy_alphamap_coord_S[fl_elem_id_E],
                 #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */
          &lc_sxy_alphamap_def_S[fl_elem_id_E]);

        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
 #if NB_SXY_COLORTRANSBITMAP > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX)
  {
    fl_elem_id_E -= MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX;

       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_colortransbitmap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_colortransbitmap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_colortransbitmap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_colortransbitmap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildColorTransBitMapImage(
                #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                #else
                &lc_sxy_colortransbitmap_coord_S[fl_elem_id_E],
                #endif
          &lc_sxy_colortransbitmap_def_S[fl_elem_id_E]);

        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
 #if NB_SXY_ALPHABITMAP > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX)
  {
    fl_elem_id_E -= MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX;

       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_alphabitmap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_alphabitmap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_alphabitmap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_alphabitmap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildAlphaBitMapImage(
                #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                #else
                &lc_sxy_alphabitmap_coord_S[fl_elem_id_E],
                #endif
          &lc_sxy_alphabitmap_def_S[fl_elem_id_E]);

        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
 #if NB_SXY_UNIALPHAMAP > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX)
  {
    fl_elem_id_E -= MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX;

       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_alphabitmap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_alphabitmap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_alphabitmap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_alphabitmap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildUniAlphaMapImage(
                #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                #else
                &lc_sxy_unialphamap_coord_S[fl_elem_id_E],
                #endif
          &lc_sxy_unialphamap_def_S[fl_elem_id_E]);

        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
 #if NB_SXY_UNIALPHABITMAP > 0
  if(fl_elem_id_E < MAX_INDEX_BMP_DRAW_UNIALPHABITMAP_INDEX)
  {
    fl_elem_id_E -= MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX;

       #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
    fl_image_area.x = ((COORDINATE_DEF_T const *)p_coord_P)->x;
    fl_image_area.y = ((COORDINATE_DEF_T const *)p_coord_P)->y;
       #else
    fl_image_area.x = lc_sxy_unialphabitmap_coord_S[fl_elem_id_E].x;
    fl_image_area.y = lc_sxy_unialphabitmap_coord_S[fl_elem_id_E].y;
       #endif /* GFX_INDEPENDANT_PROPERTY_ENABLED */

    fl_image_area.w = lc_sxy_unialphabitmap_def_S[fl_elem_id_E].w;
    fl_image_area.h = lc_sxy_unialphabitmap_def_S[fl_elem_id_E].h;

    for(l_test_clip_count_U8=0; (l_test_clip_count_U8 < l_clip_count_U8 && l_clip_region_U8 < NO_OF_CLIP_AREAS); l_test_clip_count_U8++)
    {
      l_clip_region_U8 = GfxManagerCheckClipArea(fl_image_area,l_start_index_U8);
      if(l_clip_region_U8 < NO_OF_CLIP_AREAS)
      {
        #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)     
        RECTANGLE_DEF_T  fl_widget_clip_area;
        fl_widget_clip_area = GfxManagerGetModifiedClipArea(l_clip_area_list_S[l_clip_region_U8]);
        GfxDriverSetClipArea(&fl_widget_clip_area);
        #else
        GfxDriverSetClipArea(&l_clip_area_list_S[l_clip_region_U8]);
        #endif
        GfxDriverBuildUniAlphaBitMapImage(
                #ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
          (COORDINATE_DEF_T const *)p_coord_P,
                #else
                &lc_sxy_unialphabitmap_coord_S[fl_elem_id_E],
                #endif
          &lc_sxy_unialphabitmap_def_S[fl_elem_id_E]);
        l_start_index_U8 = l_clip_region_U8+1;
      }
    }
  }
  else
 #endif
    {
    /*
    ** Unsupported draw mode
    */
  }
}/* Emd pf GfxManagerBuildClippedStaticXyBitmap() */
#endif /* NB_ALL_BITMAPS > 0 */
/****************************************************************************
Function Name        : GfxManagerCheckClipArea
Description          : This function shall check for the recived image area
                       with clip area list
Invocation           : Internally by the manager
Parameters           : RECTANGLE_DEF_T as fl_image_area and start index.
Return Value         : number of clip areas.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 GfxManagerCheckClipArea(RECTANGLE_DEF_T fl_image_area,UINT8 start_index)
{
  UINT8 i;
  UINT8 ret;
  BOOLEAN loop = TRUE;

  GFX_SIZE_X_T fl_img_x;
  GFX_SIZE_X_T fl_img_xw;
  GFX_SIZE_Y_T fl_img_y;
  GFX_SIZE_Y_T fl_img_yh;

  GFX_SIZE_X_T cl_img_x;
  GFX_SIZE_X_T cl_img_xw;
  GFX_SIZE_Y_T cl_img_y;
  GFX_SIZE_Y_T cl_img_yh;

  fl_img_y  = fl_image_area.y;
  fl_img_yh = fl_image_area.y + fl_image_area.h;
  fl_img_x  = fl_image_area.x;
  fl_img_xw = fl_image_area.x + fl_image_area.w;

  ret = NO_OF_CLIP_AREAS;

  if(start_index < NO_OF_CLIP_AREAS)
  {
    for(i=start_index; (i < l_clip_count_U8 && loop == TRUE); i++)
    {
      if(((l_clip_area_list_S[i].w == 480) && (l_clip_area_list_S[i].h == 272)) ||
        ((fl_image_area.x == l_clip_area_list_S[i].x) && (fl_image_area.y == l_clip_area_list_S[i].y) &&
        (fl_image_area.w == l_clip_area_list_S[i].w) && (fl_image_area.h == l_clip_area_list_S[i].h))
        )
      {
        /* clipping width and height are equal to screen size so no clipping */
        /* otherwise the image area is exactly equal to the clip list ignore */
      }
      else
      {
        cl_img_y  = l_clip_area_list_S[i].y;
        cl_img_yh = l_clip_area_list_S[i].y + l_clip_area_list_S[i].h;

        cl_img_x  = l_clip_area_list_S[i].x;
        cl_img_xw = l_clip_area_list_S[i].x + l_clip_area_list_S[i].w;

        if(((cl_img_y <= fl_img_y)  && (fl_img_y <= cl_img_yh))  ||
          ((cl_img_y <= fl_img_yh) && (fl_img_yh <= cl_img_yh)) ||
          ((fl_img_y <= cl_img_y)  && (cl_img_y <= fl_img_yh))  ||
          ((fl_img_y <= cl_img_yh) && (cl_img_yh <= fl_img_yh))
          )
        {
          if(((cl_img_x <= fl_img_x)  && (fl_img_x <= cl_img_xw)) ||
            ((cl_img_x <= fl_img_xw) && (fl_img_xw <= cl_img_xw))||
            ((fl_img_x <= cl_img_x)  && (cl_img_x <= fl_img_xw)) ||
            ((fl_img_x <= cl_img_xw) && (cl_img_xw <= fl_img_xw))
            )
          {
            ret = i;
            loop = FALSE;
          }
        }
      }
    }
  }
  return ret;
}/* End of GfxManagerCheckClipArea() */
/****************************************************************************
Function Name        : GfxManagerReSetClipArea
Description          : This function resets the clip area list.
Invocation           : Internally by the manager
Parameters           : None.
Return Value         : None.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerReSetClipArea(void)
{
  UINT8 i;
  for(i=0; i< NO_OF_CLIP_AREAS; i++)
  {
    l_clip_area_list_S[i].x = 0;
    l_clip_area_list_S[i].y = 0;
    l_clip_area_list_S[i].w = lc_layer_table_S[0].width;
    l_clip_area_list_S[i].h = lc_layer_table_S[0].height;
  }
  l_clip_count_U8 = 0;
}/* End of GfxManagerReSetClipArea() */

#if 0
/****************************************************************************
Function Name        : GfxManagerCheckClipAreaOverlaps
Description          : This function checks clip area overlap for the recived
                       clip data and shall update the clip information by
                       calling GfxManagerUpdateClip().
Invocation           : Internally by the manager
Parameters           : RECTANGLE_DEF_T as fl_clip_data.
Return Value         : clip area overlpa.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 GfxManagerCheckClipAreaOverlaps(RECTANGLE_DEF_T fl_clip_data)
{
  RECTANGLE_DEF_T c1,c2,c3;
  UINT8 i = 0;
  BOOLEAN bOverLap = FALSE;
  BOOLEAN bOnceUpdated = FALSE;
  UINT8 fl_temp_clip_count_U8 = l_clip_count_U8;
  GFX_SIZE_X_T x1,x2,x1w1,x2w2;
  GFX_SIZE_Y_T y1,y2,y1h1,y2h2;
  GFX_SIZE_W_T w1,w2;
  GFX_SIZE_H_T h1,h2;
  x1 = fl_clip_data.x;
  y1 = fl_clip_data.y;
  w1 = fl_clip_data.w;
  h1 = fl_clip_data.h;
  x1w1 = x1 + w1;
  y1h1 = y1 + h1;
  //if(fl_temp_clip_count_U8 == 0)
  {
    /* no clip data has been updated yet this is the first
    so update it without any checking */
  }
  //else
  {
    for(i=0;i<fl_temp_clip_count_U8;i++)
    {
      x2 = l_clip_area_list_S[i].x;
      y2 = l_clip_area_list_S[i].y;
      w2 = l_clip_area_list_S[i].w;
      h2 = l_clip_area_list_S[i].h;
      x2w2 = x2 + w2;
      y2h2 = y2 + h2;

      if(((y1 <= y2)  && (y2 <= y1h1))  ||
        ((y1 <= y2h2) && (y2h2 <= y1h1)) ||
        ((y2 <= y1)  && (y1 <= y2h2))  ||
        ((y2 <= y1h1) && (y1h1 <= y2h2))
        )
      {
        if(((x1 <= x2)  && (x2 <= x1w1)) ||
          ((x1 <= x2w2) && (x2w2 <= x1w1))||
          ((x2 <= x1)  && (x1 <= x2w2)) ||
          ((x2 <= x1w1) && (x1w1 <= x2w2))
          )
        {
          bOverLap = TRUE;
          bOnceUpdated = TRUE;
        }
      }

      if(bOverLap == TRUE)
      {
        if(x2>=x1 && x2w2>=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;

          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1;
          c2.y = y1;
          c2.w = w2+(x2-x1);
          c2.h = h2-c1.h;
          /* update the other two clipping regions to the end of the existing clip_count */
          GfxManagerUpdateClip(c2);

          c3.x = x1;
          c3.y = y2+h2;
          c3.w = w1;
          c3.h = h1+y1-c3.y;
          GfxManagerUpdateClip(c3);
        }
        else if(x2>=x1 && x2w2>=x1w1 && y2<=y1 && y2h2>=y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          /* update the second clipping list to the end of the list */
          c2.x = x1;
          c2.y = y1;
          c2.w = x2-x1;
          c2.h = h1;
          GfxManagerUpdateClip(c2);
        }
        else if(x2>=x1 && x2w2>=x1w1 && y2>=y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1+w1;
          c2.y = y2;
          c2.w = x2+w2-c2.x;
          c2.h = h2;
          GfxManagerUpdateClip(c2);
        }
        else if(x2>=x1 && x2w2>=x1w1 && y2>=y1 && y2h2>=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = y2-y1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1;
          c2.y = y2;
          c2.w = w2+(x2-x1);
          c2.h = h2-c1.h;
          GfxManagerUpdateClip(c2);

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = h2+y2-c3.y;
          GfxManagerUpdateClip(c3);
        }
        else if(x2>=x1 && x2w2<=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1;
          c2.y = y1;
          c2.w = w1;
          c2.h = h1;
          GfxManagerUpdateClip(c2);
        }
        else if(x2>=x1 && x2w2<=x1w1 && y2<=y1 && y2h2>=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1;
          c2.y = y1;
          c2.w = w1;
          c2.h = h1;
          GfxManagerUpdateClip(c2);

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = h2+y2-c3.y;
          GfxManagerUpdateClip(c3);
        }
        else if(x2>=x1 && x2w2<=x1w1 && y2>=y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;
        }
        else if(x2>=x1 && x2w2<=x1w1 && y2>=y1 && y2h2>=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x2;
          c2.y = y1+h1;
          c2.w = w2;
          c2.h = h2+y2-c2.y;
          GfxManagerUpdateClip(c2);
        }
        else if(x2<=x1 && x2w2>=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          c2.x = x1;
          c2.y = y2+h2;
          c2.w = w1;
          c2.h = h1+y1-c2.y;
          GfxManagerUpdateClip(c2);
        }
        else if(x2<=x1 && x2w2>=x1w1 && y2<=y1 && y2h2>=y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;
        }
        else if(x2<=x1 && x2w2>=x1w1 && y2>=y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x1;
          c2.y = y2;
          c2.w = x1-x2;
          c2.h = h2;
          GfxManagerUpdateClip(c2);

          c3.x = x1+w1;
          c3.y = y2;
          c3.w = x2+w2-c3.x;
          c3.h = h2;
          GfxManagerUpdateClip(c3);
        }
        else if(x2<=x1 && x2w2>=x1w1 && y2>=y1 && y2h2>=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          GfxManagerUpdateClip(c1);

          c2.x = x2;
          c2.y = y2;
          c2.w = w2;
          c2.h = h2;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c2.x;
          l_clip_area_list_S[i].y = c2.y;
          l_clip_area_list_S[i].w = c2.w;
          l_clip_area_list_S[i].h = c2.h;
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x2;
          c2.y = y1;
          c2.w = x1-x2+w1;
          c2.h = y2+h2-y1;
          GfxManagerUpdateClip(c2);

          c3.x = x1;
          c3.y = y2+h2;
          c3.w = w1;
          c3.h = y1+h1-c3.y;
          GfxManagerUpdateClip(c3);
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2<=y1 && y2h2>=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          c2.x = x2+w2;
          c2.y = y1;
          c2.w = x1+w1-c2.x;
          c2.h = h1;
          GfxManagerUpdateClip(c2);
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2>=y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x2;
          c2.y = y2;
          c2.w = x1-x2;
          c2.h = h2;
          GfxManagerUpdateClip(c2);
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2>=y1 && y2h2>=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = y2-y1;
          /* clipping region identified update the first area to the identified clip count */
          l_clip_area_list_S[i].x = c1.x;
          l_clip_area_list_S[i].y = c1.y;
          l_clip_area_list_S[i].w = c1.w;
          l_clip_area_list_S[i].h = c1.h;

          c2.x = x2;
          c2.y = y2;
          c2.w = w2;
          c2.h = h1-c1.h;
          GfxManagerUpdateClip(c2);

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = y2+h2-c3.h;
          GfxManagerUpdateClip(c3);
        }
        else
        {
          /* doesn't overlap so just add it to the end of list */
        }
        bOverLap = FALSE;
      }
      else
      {
      }
    }
    if(bOnceUpdated == FALSE)
    {
      GfxManagerUpdateClip(fl_clip_data);
    }
  }
}/* End of GfxManagerCheckClipAreaOverlaps() */
#else
/****************************************************************************
Function Name        : GfxManagerCheckClipAreaOverlaps
Description          : This function checks clip area overlap for the recived
                       clip data and shall update the clip information by
                       calling GfxManagerUpdateClip().
Invocation           : Internally by the manager
Parameters           : RECTANGLE_DEF_T as fl_clip_data and start index.
Return Value         : clip area overlpa.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT8 GfxManagerCheckClipAreaOverlaps(RECTANGLE_DEF_T fl_clip_data,UINT8 start_index)
{
  UINT8 fl_start_index = start_index;
  UINT8 index = 0;
  UINT8 ret = NO_OF_CLIP_AREAS;
  RECTANGLE_DEF_T c1,c2,c3;
  UINT8 i = 0;
  BOOLEAN bOverLap = FALSE;
  BOOLEAN bOnceUpdated = FALSE;
  UINT8 fl_temp_clip_count_U8 = l_clip_count_U8;
  GFX_SIZE_X_T x1,x2,x1w1,x2w2;
  GFX_SIZE_Y_T y1,y2,y1h1,y2h2;
  GFX_SIZE_W_T w1,w2;
  GFX_SIZE_H_T h1,h2;
  x1 = fl_clip_data.x;
  y1 = fl_clip_data.y;
  w1 = fl_clip_data.w;
  h1 = fl_clip_data.h;
  x1w1 = x1 + w1;
  y1h1 = y1 + h1;
  //if(fl_temp_clip_count_U8 == 0)
  {
    /* no clip data has been updated yet this is the first
    so update it without any checking */
  }
  //else
  {
    i = start_index;
    if(i != 0)
    {
      bOnceUpdated = TRUE;
    }
    for(i=start_index; bOverLap == FALSE && i<fl_temp_clip_count_U8; i++)
    {
      x2 = l_clip_area_list_S[i].x;
      y2 = l_clip_area_list_S[i].y;
      w2 = l_clip_area_list_S[i].w;
      h2 = l_clip_area_list_S[i].h;
      x2w2 = x2 + w2;
      y2h2 = y2 + h2;

      if(((y1 <= y2)  && (y2 < y1h1))  ||
        ((y1 < y2h2) && (y2h2 < y1h1)) ||
        ((y2 <= y1)  && (y1 < y2h2))  ||
        ((y2 < y1h1) && (y1h1 < y2h2))
        )
      {
        if(((x1 <= x2)  && (x2 < x1w1)) ||
          ((x1 < x2w2) && (x2w2 < x1w1))||
          ((x2 <= x1)  && (x1 < x2w2)) ||
          ((x2 < x1w1) && (x1w1 < x2w2))
          )
        {
          bOverLap = TRUE;
          bOnceUpdated = TRUE;
          ret = i;
        }
      }

      if(bOverLap == TRUE)
      {
        if(x2>x1 && x2w2>x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;

          c2.x = x1;
          c2.y = y1;
          c2.w = w2+(x2-x1);
          c2.h = h2-c1.h;
          /* update the other two clipping regions to the end of the existing clip_count */

          c3.x = x1;
          c3.y = y2+h2;
          c3.w = w1;
          c3.h = h1+y1-c3.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;
            GfxManagerUpdateClip(c2);
            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else if(x2>x1 && x2w2>x1w1 && y2<=y1 && y2h2>y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          /* update the second clipping list to the end of the list */
          c2.x = x1;
          c2.y = y1;
          c2.w = x2-x1;
          c2.h = h1;
          if(start_index == 0)
          {
            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2>x1 && x2w2>x1w1 && y2>y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;

          c2.x = x1+w1;
          c2.y = y2;
          c2.w = x2+w2-c2.x;
          c2.h = h2;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }

        }
        else if(x2>x1 && x2w2>x1w1 && y2>y1 && y2h2>y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = y2-y1;

          c2.x = x1;
          c2.y = y2;
          c2.w = w2+(x2-x1);
          c2.h = h1-c1.h;

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = h2+y2-c3.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);

            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else if(x2>x1 && x2w2<=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;

          c2.x = x1;
          c2.y = y1;
          c2.w = w1;
          c2.h = h1;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2>x1 && x2w2<=x1w1 && y2<=y1 && y2h2>y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;

          c2.x = x1;
          c2.y = y1;
          c2.w = w1;
          c2.h = h1;

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = h2+y2-c3.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);

            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else if(x2>x1 && x2w2<=x1w1 && y2>y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;
          }
        }
        else if(x2>x1 && x2w2<=x1w1 && y2>y1 && y2h2>y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;

          c2.x = x2;
          c2.y = y1+h1;
          c2.w = w2;
          c2.h = h2+y2-c2.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2<=x1 && x2w2>x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          c2.x = x1;
          c2.y = y2+h2;
          c2.w = w1;
          c2.h = h1+y1-c2.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2<=x1 && x2w2>x1w1 && y2<=y1 && y2h2>y1h1)
        {
          /* The clipping region is same as that of the existing item so no need to update
          in this case */
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;
          }
        }
        else if(x2<=x1 && x2w2>x1w1 && y2>y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;

          c2.x = x2;
          c2.y = y2;
          c2.w = x1-x2;
          c2.h = h2;

          c3.x = x1+w1;
          c3.y = y2;
          c3.w = x2+w2-c3.x;
          c3.h = h2;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);

            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else if(x2<=x1 && x2w2>x1w1 && y2>y1 && y2h2>y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = y2-y1;

          c2.x = x2;
          c2.y = y2;
          c2.w = w2;
          c2.h = h2;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c1);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c2.x;
            l_clip_area_list_S[start_index-1].y = c2.y;
            l_clip_area_list_S[start_index-1].w = c2.w;
            l_clip_area_list_S[start_index-1].h = c2.h;

            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;
          }
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2<=y1 && y2h2<=y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = y1-y2;

          c2.x = x2;
          c2.y = y1;
          c2.w = x1-x2+w1;
          c2.h = y2+h2-y1;

          c3.x = x1;
          c3.y = y2+h2;
          c3.w = w1;
          c3.h = y1+h1-c3.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);

            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2<=y1 && y2h2>y1h1)
        {
          c1.x = x2;
          c1.y = y2;
          c1.w = w2;
          c1.h = h2;

          c2.x = x2+w2;
          c2.y = y1;
          c2.w = x1+w1-c2.x;
          c2.h = h1;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2>y1 && y2h2<=y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = h1;

          c2.x = x2;
          c2.y = y2;
          c2.w = x1-x2;
          c2.h = h2;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;
          }
        }
        else if(x2<=x1 && x2w2<=x1w1 && y2>y1 && y2h2>y1h1)
        {
          c1.x = x1;
          c1.y = y1;
          c1.w = w1;
          c1.h = y2-y1;

          c2.x = x2;
          c2.y = y2;
          c2.w = x1+w1-x2;
          c2.h = h1-c1.h;

          c3.x = x2;
          c3.y = y1+h1;
          c3.w = w2;
          c3.h = y2+h2-c3.y;
          if(start_index == 0)
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[i].x = c1.x;
            l_clip_area_list_S[i].y = c1.y;
            l_clip_area_list_S[i].w = c1.w;
            l_clip_area_list_S[i].h = c1.h;

            GfxManagerUpdateClip(c2);

            GfxManagerUpdateClip(c3);
          }
          else
          {
            /* clipping region identified update the first area to the identified clip count */
            l_clip_area_list_S[start_index-1].x = c1.x;
            l_clip_area_list_S[start_index-1].y = c1.y;
            l_clip_area_list_S[start_index-1].w = c1.w;
            l_clip_area_list_S[start_index-1].h = c1.h;

            l_clip_area_list_S[i].x = c2.x;
            l_clip_area_list_S[i].y = c2.y;
            l_clip_area_list_S[i].w = c2.w;
            l_clip_area_list_S[i].h = c2.h;

            GfxManagerUpdateClip(c3);
          }
        }
        else
        {
          /* doesn't overlap so just add it to the end of list */
        }
      }
      else
      {
      }
    }
    if(bOnceUpdated == FALSE)
    {
      GfxManagerUpdateClip(fl_clip_data);
      ret = NO_OF_CLIP_AREAS;
    }
    else
    {
    }
  }
  return ret;
}/* End of GfxManagerCheckClipAreaOverlaps() */
#endif

/****************************************************************************
Function Name        : GfxManagerUpdateClip
Description          : This function updates the clip data to the clip list.
Invocation           : Internally by manager.
Parameters           : clip data information
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static BOOLEAN GfxManagerUpdateClip(RECTANGLE_DEF_T fl_clip_data)
{
  if(fl_clip_data.w == 0 || fl_clip_data.h == 0)
  {
    /* if width or height is zero it is a line and not a rectangle region
    so ignore this data don't add */
  }
  else
  {
    l_clip_area_list_S[l_clip_count_U8].x = fl_clip_data.x;
    l_clip_area_list_S[l_clip_count_U8].y = fl_clip_data.y;
    l_clip_area_list_S[l_clip_count_U8].w = fl_clip_data.w;
    l_clip_area_list_S[l_clip_count_U8].h = fl_clip_data.h;
    l_clip_count_U8++;
    if(l_clip_count_U8 >= NO_OF_CLIP_AREAS)
    {
      l_clip_count_U8 = 0;
    }
  }
}/* End of GfxManagerUpdateClip() */
#endif /* (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED) */

#if GFX_TOUCH_SCREEN_ENABLED > 0
/****************************************************************************
Function Name        : GfxManagerProcessTouchEvents
Description          : This function pops button events from the queue and
                       hands it over to the GfxManagerTouchEventHandler to
                       despatch it to application.
Invocation           : By application.
Parameters           : None.
Return Value         :
Critical Section     : This function needs to be called from the same context
                       as the sending of events/data to the graphics manager.
                       Ideally needs to call at the end of the Graphics_Task()
                       This cuntion sets the internal event data so by calling
                       it at the end will make sure that it reads and sets the
                       correct data.
External Interfaces  : None
******************************************************************************/
void GfxManagerProcessTouchEvents(void)
{
   GFX_TOUCH_QDATA fl_touch_event_SP;

   while(GfxManagerPopTouchEvent(&fl_touch_event_SP) != 0)
   {
      GfxManagerTouchEventHandler(fl_touch_event_SP.x, fl_touch_event_SP.y, fl_touch_event_SP.event);
   }
}

/****************************************************************************
Function Name        : GfxManagerPushTouchEvent
Description          : This function pushes button events to the queue.
Invocation           : By application.
Parameters           : Pointer to GFX_TOUCH_QDATA.
Return Value         : None.
Critical Section     : None.
External Interfaces  : None
******************************************************************************/
void GfxManagerPushTouchEvent(GFX_TOUCH_QDATA * p_touch_data_SP)
{
   GFX_TOUCH_QDATA * fl_touch_data_SP;
   UINT32            fl_tcount_U32 = l_tcount_U32;
   UINT32            fl_twrite_U32 = l_twrite_index_U32;
   if(fl_tcount_U32 < GFX_TOUCH_EVENT_Q_SIZE)
   {
      fl_touch_data_SP        = &l_touch_event_queue_S[fl_twrite_U32];
      fl_touch_data_SP->x     = p_touch_data_SP->x;
      fl_touch_data_SP->y     = p_touch_data_SP->y;
      fl_touch_data_SP->event = p_touch_data_SP->event;
      fl_tcount_U32++;
      fl_twrite_U32++;
      if(fl_twrite_U32 >= GFX_TOUCH_EVENT_Q_SIZE)
      {
         fl_twrite_U32 = 0;
      }
   #if defined(WIN32) || defined(WINCE)
      EnterCriticalSection(&l_tcritical_section);
   #endif
      l_twrite_index_U32 = fl_twrite_U32;
      l_tcount_U32       = fl_tcount_U32;
   #if defined(WIN32) || defined(WINCE)
      LeaveCriticalSection(&l_tcritical_section);
   #endif
   }
#ifdef DEBUG
   else
   {
      printf("GfxManagerPushTouchEvent Q FULL Error\n");
   }
#endif
}

/****************************************************************************
Function Name        : GfxManagerPopTouchEvent
Description          : This function pops button events from the queue.
Invocation           : By GfxManagerProcessTouchEvents.
Parameters           : Pointer to GFX_TOUCH_QDATA where the touch event will be
                       written.
Return Value         : Returns zero if there are no events in queue
                       If the p_touch_data_SP is updated with an event returns
                       non zero.
Critical Section     : None.
External Interfaces  : None
******************************************************************************/
static UINT32 GfxManagerPopTouchEvent(GFX_TOUCH_QDATA * p_touch_data_SP)
{
   GFX_TOUCH_QDATA * fl_touch_data_SP;
   UINT32            fl_tcount_U32 = l_tcount_U32;
   UINT32            fl_tread_U32  = l_tread_index_U32;
   UINT32            fl_sts_U32;
   if(fl_tcount_U32 > 0)
   {
      fl_touch_data_SP       = &l_touch_event_queue_S[fl_tread_U32];
      p_touch_data_SP->x     = fl_touch_data_SP->x;
      p_touch_data_SP->y     = fl_touch_data_SP->y;
      p_touch_data_SP->event = fl_touch_data_SP->event;
      fl_tcount_U32--;
      fl_tread_U32++;
      if(fl_tread_U32 >= GFX_TOUCH_EVENT_Q_SIZE)
      {
         fl_tread_U32 = 0;
      }
   #if defined(WIN32) || defined(WINCE)
      EnterCriticalSection(&l_tcritical_section);
   #endif
      l_tread_index_U32 = fl_tread_U32;
      l_tcount_U32      = fl_tcount_U32;
   #if defined(WIN32) || defined(WINCE)
      LeaveCriticalSection(&l_tcritical_section);
   #endif
      fl_sts_U32        = 1;
   }
   else
   {
      fl_sts_U32 = 0;
   }
   return(fl_sts_U32);
}

/****************************************************************************
Function Name        : GfxManagerTouchEventHandler
Description          : Searches through all touch area in the active screens
                       to find a match for the passed event. Once a match is
                       found, notifies the application for action.
Invocation           : Internally by manager.
Parameters           : x,y coordinate of the touch and the touch event
                       Touch event can be GFX_MOUSE_MOVE_EV, GFX_MOUSE_DOWN_EV
                       or GFX_MOUSE_UP_EV
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void GfxManagerTouchEventHandler(UINT16 x, UINT16 y, UINT8 touch_event)
{
   UINT8                  fl_no_layers = NB_LAYERS;
   LAYER_TABLE_T  const * fl_active_layer_table_SP;
   UINT8                  fl_prio_U8;
   UINT8                  l_last_touch_area_valid = FALSE;

   if(l_last_touch_area_SP != 0)
   {
      if((x < l_last_touch_area_SP->area.x) ||
         (y < l_last_touch_area_SP->area.y) ||
         (x > (l_last_touch_area_SP->area.x + l_last_touch_area_SP->area.w)) ||
         (y > (l_last_touch_area_SP->area.y + l_last_touch_area_SP->area.h)))
      {
         /*
         ** Post inactive as we have left the last active touch button area.
         */
         GFX_ELEMENT_ID_T  touch_widget  = GET_DYN_WIDGETS_INDEX(l_last_touch_area_SP->widget_id);
         DYN_WIDGET_DATA_T fl_prev_sel_t = l_dyn_widget_S[touch_widget];
         if(fl_prev_sel_t == 1)
         {
            /* Deselect the button, if it is in selected state */
            GfxManagerSendEvent(l_last_touch_area_SP->widget_id, 0);
            fl_prev_sel_t = 0;
         }
         GFX_TOUCH_SCREEN_EVENT_DISPATCH(l_last_touch_area_SP->widget_id, fl_prev_sel_t, GFX_MOUSE_CANCEL_EV);
         l_last_touch_area_SP = 0;
      }
   }

   fl_prio_U8 = NB_PRIORITY;

   while((fl_no_layers > 0) && (fl_prio_U8 >= NB_PRIORITY))
   {
      fl_no_layers--;
      fl_active_layer_table_SP = &lc_layer_table_S[fl_no_layers];
   #if  NB_PRIORITY > 1
      fl_prio_U8 = l_highest_active_priority_U8[fl_no_layers];
   #else
      fl_prio_U8 = 0;
   #endif
   }

   if(fl_prio_U8 < NB_PRIORITY)
   {
      SCREEN_ID_T fl_screen_id = fl_active_layer_table_SP->psid_tptr[fl_prio_U8];

      if(fl_screen_id < MAX_INDEX_SCREEN_INDEX)
      {
         UINT32 fl_nb_touch = lc_screen_table_S[fl_screen_id].no_touch_points;
         UINT32 fl_cur_touch;
         UINT32 fl_obj_selected;
         UINT32 fl_wdg_id;
         UINT32 fl_path_count;
         WIDGET_ACTIVE_PATH_DEF_T const * fl_path_info_SP;
         WIDGET_TOUCH_INFO_DEF_T  const * fl_touch_info_SP = lc_screen_table_S[fl_screen_id].touch_points_table;

         for(fl_cur_touch=0; fl_cur_touch< fl_nb_touch; fl_cur_touch++,fl_touch_info_SP++)
         {
            fl_path_info_SP = fl_touch_info_SP->selection_path;
            fl_obj_selected = TRUE;

            if(fl_path_info_SP != 0)
            {
               fl_path_count = fl_touch_info_SP->num_path;

               while(fl_path_count > 0)
               {
                  fl_path_count--;
                  fl_wdg_id = fl_path_info_SP->widget_id;
                  if(fl_wdg_id != GFX_TOUCH_PATH_END)
                  {
                     fl_wdg_id = GET_DYN_WIDGETS_INDEX(fl_wdg_id);
                     if(fl_wdg_id < NB_DYN_WIDGETS)
                     {
                        fl_wdg_id = l_dyn_widget_S[fl_wdg_id];
                        if(fl_wdg_id != fl_path_info_SP->widget_index)
                        {
                           /*
                           ** This path segment is not active
                           ** But don't break the loop as there may be
                           ** another segment which could be active, so just continue.
                           */
                           fl_obj_selected = FALSE;
                        }
                     }
                     else
                     {
                        /*
                        ** This is an invalid condition, which is not expected.
                        */
                        fl_path_count   = 0;
                        fl_obj_selected = FALSE;
                     }
                  }
                  else
                  {
                     /*
                     ** End of path segment
                     ** 1. If the fl_obj_selected is true that means this segment is
                     **    currently selected and therefore we can break the loop immediately
                     ** 2. If fl_obj_selected is false then this segment pathj is not
                     **    currently active there fore if any further segments are present
                     **    we can continue with that to see if that is active.
                     */
                     if(fl_obj_selected != FALSE)
                     {
                        fl_path_count = 0;
                     }
                     else if(fl_path_count > 0)
                     {
                        /*
                        ** continue the search
                        */
                        fl_obj_selected = TRUE;
                     }
                     else
                     {
                     }
                  }
                  fl_path_info_SP++;
               }
            }

            if(fl_obj_selected != FALSE)
            {
               if((x >= fl_touch_info_SP->area.x)&&(x <= (fl_touch_info_SP->area.x + fl_touch_info_SP->area.w))&&
                  (y >= fl_touch_info_SP->area.y)&&(y <= (fl_touch_info_SP->area.y + fl_touch_info_SP->area.h)))
               {
                  /* Touch area match found */
                  GFX_ELEMENT_ID_T  touch_widget;
                  DYN_WIDGET_DATA_T fl_prev_sel_t;
                  GFX_ELEMENT_LIST const * fl_elem_list_SP;
                  UINT32            no_of_touch_disp;

                  touch_widget            = GET_DYN_WIDGETS_INDEX(fl_touch_info_SP->widget_id);
                  fl_elem_list_SP         = &lc_dynamic_widget_elem_list_S[touch_widget];
                  no_of_touch_disp        = fl_elem_list_SP->nb_elements;
                  fl_prev_sel_t           = l_dyn_widget_S[touch_widget];
                  l_last_touch_area_valid = TRUE;

                  switch(touch_event)
                  {
                     /*touched*/
                     case GFX_MOUSE_DOWN_EV:
                     {
                        if(no_of_touch_disp > 1)
                        {
                           /*
                           ** auto selection only of there are 2 or more elements
                           ** otherwise leave it to the app to decide.
                           */
                           if(fl_prev_sel_t == 0)
                           {
                              GfxManagerSendEvent(fl_touch_info_SP->widget_id, 1);
                              fl_prev_sel_t  = 1;
                           }
                           else if(fl_prev_sel_t == 1)
                           {
                              GfxManagerSendEvent(fl_touch_info_SP->widget_id, 0);
                              fl_prev_sel_t  = 0;
                           }
                           else
                           {
                           }
                        }
                        GFX_TOUCH_SCREEN_EVENT_DISPATCH(fl_touch_info_SP->widget_id, fl_prev_sel_t, GFX_MOUSE_DOWN_EV);
                        l_last_touch_area_SP = fl_touch_info_SP;
                     }
                     break;
                     /* released */
                     case GFX_MOUSE_UP_EV:
                     {
                        if(l_last_touch_area_SP == fl_touch_info_SP)
                        {
                           if(no_of_touch_disp > 1)
                           {
                              if(fl_prev_sel_t == 0)
                              {
                                 GfxManagerSendEvent(fl_touch_info_SP->widget_id, 1);
                                 fl_prev_sel_t   = 1;
                              }
                              else if(fl_prev_sel_t == 1)
                              {
                                 GfxManagerSendEvent(fl_touch_info_SP->widget_id, 0);
                                 fl_prev_sel_t   = 0;
                              }
                              else
                              {
                              }
                           }
                           GFX_TOUCH_SCREEN_EVENT_DISPATCH(fl_touch_info_SP->widget_id, fl_prev_sel_t, GFX_MOUSE_UP_EV);
                        }
                        l_last_touch_area_SP = 0;
                     }
                     break;
                     default:
                     {
                     }
                     break;
                  }
                  fl_cur_touch = fl_nb_touch;
               }
            }
         }
      }
   }
   if(l_last_touch_area_valid == FALSE)
   {
      /*
      ** Clear the history if it detected to be invalid.
      */
      l_last_touch_area_SP = 0;
   }
}
#endif

#if NB_DYN_ELEMENTS > 0
/****************************************************************************
Function Name        : GfxManagerSetDefaultProperties
Description          : Sets the default properties for the element passed.
                       Default properties are taken from tool generated file.
Invocation           : By application.
Parameters           : Element Id
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxManagerSetDefaultProperties(GFX_ELEMENT_ID_T p_element)
{
  #if (NB_DYN_ELEMENTS > NB_SCREENS) && (NB_DYN_XY_BITMAPS > 0)
  GFX_ELEMENT_ID_T fl_dyn_table_index;
  #endif	
  if(p_element < MAX_DYNAMIC_ELEMENT_INDEX)
  {
    if(p_element < MAX_INDEX_SCREEN_INDEX)
    {
    }
    #if NB_DYN_XY_BITMAPS > 0
    else if(p_element < MAX_INDEX_DYN_XY_BITMAP_INDEX)
    {
      fl_dyn_table_index = GET_DYN_XY_BITMAPS_INDEX(p_element);
      if(fl_dyn_table_index < NB_ALL_DYN_XY_BITMAPS)
      {
        if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
        {
          if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x != lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x)
          {
            l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x = lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].x;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
          }
        }
      }
      else
      {
        fl_dyn_table_index -= NB_ALL_DYN_XY_BITMAPS;
        p_element          -= NB_ALL_DYN_XY_BITMAPS;
        if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
        {
          if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y != lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y)
          {
            l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y = lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].y;
            l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
          }
        }
		else
		{
			if(fl_dyn_table_index < MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX)
            {
                if(l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha != lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha)
                {
                    l_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha = lc_dyn_xy_bitmap_coord_S[fl_dyn_table_index].alpha;
                    l_dyn_element_changed_U8[p_element] |= GFX_SCREEN_CHANGED_FLAG;
                }
            }
		}
      }
    }
    #endif 
    #if NB_DYNXY_DIMAGES > 0
    else if(p_element < MAX_INDEX_DYN_X_DBITMAP_INDEX)
    {
      p_element -= MAX_INDEX_DYN_XY_BITMAP_INDEX;
      if(p_element < NB_DYNXY_DIMAGES)
      {
        if(l_d_image_dyn_property_S[p_element].x != lc_d_image_dyn_property_S[p_element].x)
        {
          l_d_image_dyn_property_S[p_element].x  = lc_d_image_dyn_property_S[p_element].x;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_Y_DBITMAP_INDEX)
    {
      p_element -= MAX_INDEX_DYN_X_DBITMAP_INDEX;
      if(p_element < NB_DYNXY_DIMAGES)
      {
        if(l_d_image_dyn_property_S[p_element].y != lc_d_image_dyn_property_S[p_element].y)
        {
          l_d_image_dyn_property_S[p_element].y  = lc_d_image_dyn_property_S[p_element].y;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
	else if(p_element < MAX_INDEX_DYN_ALPHA_DBITMAP_INDEX)
	{
      p_element -= MAX_INDEX_DYN_Y_DBITMAP_INDEX;
      if(p_element < NB_DYNXY_DIMAGES)
      {
        if(l_d_image_dyn_property_S[p_element].alpha != lc_d_image_dyn_property_S[p_element].alpha)
        {
          l_d_image_dyn_property_S[p_element].alpha  = lc_d_image_dyn_property_S[p_element].alpha;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_SCREEN_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }		
	}
    #endif
    #if NB_DYNXY_TEXTS > 0
    else if(p_element < MAX_INDEX_DYN_X_DTEXT_INDEX)
    {
      p_element -= MAX_INDEX_DYN_Y_DBITMAP_INDEX;
      if(p_element < NB_DYNXY_TEXTS)
      {
        if(l_dyn_text_dyn_property_S[p_element].coord.x != lc_dyn_text_dyn_property_S[p_element].coord.x)
        {
          l_dyn_text_dyn_property_S[p_element].coord.x = lc_dyn_text_dyn_property_S[p_element].coord.x;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_Y_DTEXT_INDEX)
    {
      p_element -= MAX_INDEX_DYN_X_DTEXT_INDEX;
      if(p_element < NB_DYNXY_TEXTS)
      {
        if(l_dyn_text_dyn_property_S[p_element].coord.y != lc_dyn_text_dyn_property_S[p_element].coord.y)
        {
          l_dyn_text_dyn_property_S[p_element].coord.y = lc_dyn_text_dyn_property_S[p_element].coord.y;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
	else if(p_element < MAX_INDEX_DYN_ALPHA_DTEXT_INDEX)
	{
      p_element -= MAX_INDEX_DYN_Y_DTEXT_INDEX;
      if(p_element < NB_DYNXY_TEXTS)
      {
        if(l_dyn_text_dyn_property_S[p_element].coord.alpha != lc_dyn_text_dyn_property_S[p_element].coord.alpha)
        {
          l_dyn_text_dyn_property_S[p_element].coord.alpha = lc_dyn_text_dyn_property_S[p_element].coord.alpha;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }		
	}
    else if(p_element < MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX)
    {
      p_element -= MAX_INDEX_DYN_ALPHA_DTEXT_INDEX;
      if(p_element < NB_DYNXY_TEXTS)
      {
        if(l_dyn_text_dyn_property_S[p_element].draw_color != lc_dyn_text_dyn_property_S[p_element].draw_color)
        {
          l_dyn_text_dyn_property_S[p_element].draw_color = lc_dyn_text_dyn_property_S[p_element].draw_color;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_BITMAPS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    #endif /* #if NB_DYNXY_TEXTS > 0 */
    #if NB_DYN_FILL_SCREENS > 0
    else if(p_element < MAX_INDEX_DYN_X_NFILL_INDEX)
    {
      p_element -= MAX_INDEX_DYN_NBLINES_DTEXT_INDEX;
      if(p_element < NB_DYN_FILL_SCREENS)
      {
        if(l_fill_screen_dyn_property_S[p_element].x != lc_fill_screen_dyn_property_S[p_element].x)
        {
          l_fill_screen_dyn_property_S[p_element].x = lc_fill_screen_dyn_property_S[p_element].x;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_Y_NFILL_INDEX)
    {
      p_element -= MAX_INDEX_DYN_X_NFILL_INDEX;
      if(p_element < NB_DYN_FILL_SCREENS)
      {
        if(l_fill_screen_dyn_property_S[p_element].y != lc_fill_screen_dyn_property_S[p_element].y)
        {
          l_fill_screen_dyn_property_S[p_element].y = lc_fill_screen_dyn_property_S[p_element].y;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_W_NFILL_INDEX)
    {
      p_element -= MAX_INDEX_DYN_Y_NFILL_INDEX;
      if(p_element < NB_DYN_FILL_SCREENS)
      {
        if(l_fill_screen_def_dyn_S[p_element].width != lc_fill_screen_def_dyn_S[p_element].width)
        {
          l_fill_screen_def_dyn_S[p_element].width = lc_fill_screen_def_dyn_S[p_element].width;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_H_NFILL_INDEX)
    {
      p_element -= MAX_INDEX_DYN_W_NFILL_INDEX;
      if(p_element < NB_DYN_FILL_SCREENS)
      {
        if(l_fill_screen_def_dyn_S[p_element].height != lc_fill_screen_def_dyn_S[p_element].height)
        {
          l_fill_screen_def_dyn_S[p_element].height = lc_fill_screen_def_dyn_S[p_element].height;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
	else if(p_element < MAX_INDEX_DYN_ALPHA_NFILL_INDEX)
	{
      p_element -= MAX_INDEX_DYN_H_NFILL_INDEX;
      if(p_element < NB_DYN_FILL_SCREENS)
      {
        if(l_fill_screen_dyn_property_S[p_element].alpha != lc_fill_screen_dyn_property_S[p_element].alpha)
        {
          l_fill_screen_dyn_property_S[p_element].alpha = lc_fill_screen_dyn_property_S[p_element].alpha;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_CLIP_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }		
	}
    #endif
    #if NB_DYNAMIC_CLIP_WIDGETS > 0
    else if(p_element < MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_COLOR_NFILL_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
        if(l_widget_dynamic_clip_list_SA[p_element].clip.x != lc_widget_dynamic_clip_list_SA[p_element].clip.x)
        {
          l_widget_dynamic_clip_list_SA[p_element].clip.x = lc_widget_dynamic_clip_list_SA[p_element].clip.x;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
        if(l_widget_dynamic_clip_list_SA[p_element].clip.y != lc_widget_dynamic_clip_list_SA[p_element].clip.y)
        {
          l_widget_dynamic_clip_list_SA[p_element].clip.y = lc_widget_dynamic_clip_list_SA[p_element].clip.y;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
        if(l_widget_dynamic_clip_list_SA[p_element].clip.w != lc_widget_dynamic_clip_list_SA[p_element].clip.w)
        {
           l_widget_dynamic_clip_list_SA[p_element].clip.w = lc_widget_dynamic_clip_list_SA[p_element].clip.w;
           l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
    else if(p_element < MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
        if(l_widget_dynamic_clip_list_SA[p_element].clip.h != lc_widget_dynamic_clip_list_SA[p_element].clip.h)
        {
          l_widget_dynamic_clip_list_SA[p_element].clip.h = lc_widget_dynamic_clip_list_SA[p_element].clip.h;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;
        }
      }
    }
   else if(p_element < MAX_INDEX_DYN_X_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
		if(l_widget_dynamic_clip_list_SA[p_element].dyn_prop.x != lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.x)
		{
          l_widget_dynamic_clip_list_SA[p_element].dyn_prop.x = lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.x;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;			
		}
		
      }
    }
   else if(p_element < MAX_INDEX_DYN_Y_WIDGETS_INDEX)
    {
      p_element -= MAX_INDEX_DYN_X_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
		if(l_widget_dynamic_clip_list_SA[p_element].dyn_prop.y != lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.y)
		{
          l_widget_dynamic_clip_list_SA[p_element].dyn_prop.y = lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.y;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;			
		}
      }
    }
	else if(p_element < MAX_INDEX_DYN_ALPHA_WIDGETS_INDEX)	
	{
      p_element -= MAX_INDEX_DYN_Y_WIDGETS_INDEX;
      if(p_element < NB_DYNAMIC_CLIP_WIDGETS)
      {
		if(l_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha != lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha)
		{
          l_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha = lc_widget_dynamic_clip_list_SA[p_element].dyn_prop.alpha;
          l_dyn_element_changed_U8[p_element+MAX_INDEX_DYN_WIDGETS_INDEX] |= GFX_SCREEN_CHANGED_FLAG;			
		}
      }		
	}
    #endif
    else
    {
    }
  }
}
#endif



/*============================================================================
** Function Name:    GfxManagerSelectGroupFontIndex
** Visibility:       global
** Description:      Sets a selected font index for the passed font group ID
** Invocation:       Invoked by application
** Inputs/Outputs:   Returns TRUE if the selection operation is valid.
** Critical Section: None.
** Created:          18-Jan-2016 by ADEVI
** Updated:          18-Jan-2016 by ADEVI
**==========================================================================*/
UINT8 GfxManagerSelectGroupFontIndex(GFX_ELEMENT_ID_T p_font_id, GFX_ELEMENT_DATA_T p_selection_index)
{
  UINT8                 fl_ret_sts = FALSE;
  #if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
    if(p_font_id < GFX_MGR01_NUM_OF_FONTS)
    {
      if(GfxDriverSetGroupFontIndex(p_font_id, p_selection_index))
      {
        GFX_MGR01_SET_FLAG(l_font_elem_changed_flag_U8A,p_font_id);
        fl_ret_sts = TRUE;
      }
    }
  #else
   (void)p_font_id;
   (void)p_selection_index;
  #endif
  return(fl_ret_sts);
}


/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              :  20-Sep-2024
By                :  aperumal
Traceability      :  HYUND32598-12826
Change Description:  Multicolor support for segmented displays 
Date              :  14-APR-2017
By                :  kkubendi
Traceability      :  791443
Change Description:  GFX01/HyundaiQxC: Update Graphics Manager 01 to support XY,Alpha animation, 
					 Alpha and Image blending.

Date              :  06-JUN-2016
By                :  adevi
Traceability      :  612910
Change Description:  S101 Issue in text building fixed.

Date              :  09-MAY-2016
By                :  adevi
Traceability      :  589518
Change Description:  S101 compiler warning fixes.

Date              :  19-JAN-2015
By                :  adevi
Traceability      :  491345
Change Description:  Font grouping and dynamic font id change.

Date              :  28-DEC-2015
By                :  adevi
Traceability      :  489987
Change Description:  Dynamic screen position change interface introduced.

Date              :  14-OCT-2015
By                :  aperumal
Traceability      :  430157
Change Description:  Compiler warning fix in GfxManagerSetDynScreenPriority

Date              :  12-OCT-2015
By                :  adevi
Traceability      :  430157
Change Description:  GfxManagerSetDefaultProperties interface introduced.

Date              :  21-AUG-2015
By                :  arajase2
Traceability      :  399702: l_highest_active_priority_U8 is used without NB_PRIORITY > 1 check
Change Description:  Addressed review comment for Compiler warning fix in Honda K35

Date              :23/9/2015
By                :csakthiv
Traceability      :RTC 429132
Change Description:Modified dynamic screen priority interface. Screen changed flag will
                   be set eventhough there is no change in screen priority. This was done
				   just to satify the application requirment as in gfx_10 design, sendevent
				   with refresh is called continously.

Date              :17/7/2015
By                :adevi
Traceability      :RTC 368488
Change Description:New interface added to set dynamic screen priority.

Date              :  07-APR-2015
By                :  arajase2
Traceability      :  302203: Compiler warning fix for Honda K35
Change Description:  Compiler warning fix for Honda K35

Date              :  25-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  GfxManagerGetTextFit function is removed as the implementation
was commented inside the function. Usage of this function can be replaced with
GfxManagerGetTextFitWidth  function

Date              :  06-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  QAC 8.1.2 Warnings resolved.

Date              :  12-Dec-2014
By                :  adevi
Traceability      :
Change Description:  1. MAX_INDEX_SCROLL_INDEX macro introduced.

Date              :  24-Jul-2014
By                :  adevi
Traceability      :  
Change Description:  1. GfxManagerBuildSegmentScreen prototype modified based on
                        NB_LAYERS value.
                     2. QAC fixes.

Date              :  30-May-2014
By                :  kcsarava
Traceability      :  Updated for PR ID: 76698;
Change Description:  Have the fix for raised PR defects

Date              :  26.05.2014
By                :  kcsarava
Traceability      :  Added support to get the total number of characters that
                     can be displayed with in the available display width.
Change Description:  added function GfxManagerGetTextFitWidth() to get the total
                     number of characters that can be displayed with in the
                     available display width for the respective element and given
                     input text.
Date              :  23.08.2013
By                :  pteki
Traceability      :  frambebuffer update for segmented data change only when
                     there is any change.
Change Description:  GfxManagerSetIcon() updates the GFX_SCREEN_CHANGED_FLAG
                     when there is a change in the segmented icon bit.
                     GfxManagerBuildSegmentScreen()build the screen when the
                     element get changed by verifying the GFX_SCREEN_CHANGED_FLAG
                     for the particular element id.
Date              :  04.09.2012
By                :  tvijayas
Traceability      :  added support for segmenetd display and combination of
                     segmented and dotmatrix display.
Change Description:  added function GfxManagerBuildSegmentScreen() to build
                     segmented display screen.it will consist of only dynamic
                     image as icon and text.
                     GfxManagerSetIcon() is used to set the icons for
                     segmented display.
Date              :  01.08.2011
By                :  emanoj1
Traceability      :  Volvo Demo issue - a change in dynamic widget index
                     didn't initiated the rebuild.
Change Description:  GfxManagerCheckDynElementChanged() updated
Traceability      :  Volvo Demo issue - GfxDriverEndUpdate() passed the
                     unchanged layer bit which caused an unnecessary layer swap.
Change Description:  GfxManagerBuildScreen() updated to pass only changed layers

Date              :  02.06.2011
By                :  emanoj1
Traceability      :  MM L3 issue - If one button was in a dynamic widget which
                     is not selected and therefore not on display, but still
                     the GfxManagerTouchEventHandler was posting the events
                     if the mouse is clicked on the display area.
Change Description:  The path handling was corrected to check whether a widget
                     is selcted before checking whether its area falls under the
                     mouse click.

Date              :  22.03.2011
By                :  emanoj1
Traceability      :  MM L3 requuirements
Change Description: Integrated Vijay's Touch screen implementation.
                    Modified to introduce a queue machanism for touch events
                    as the events needs to be processed by a different process

Date              :  28.12.2010
By                :  ksriniv2
Traceability      :
Change Description: 1.File updated for multi level update.
                      GfxManagerBuildElement()
                      GfxManagerBuildDynamicXyBitmap()
                      GfxManagerBuildStaticXyBitmap()
                      The above functions are changed to check for clipping
                      and update the clip data before they are built
                    2.Peer review comments updated.

Date              :  16.4.2010
By                :  gyuvamat
Traceability      :
Change Description: Fixed QAC warnings

Date              :  28-Dec-09
By                :  emanoj1
Traceability      :  1.4
Change Description:  1. Updated GfxManagerCheckDynElementChanged to remove checking
                     and building dynamic widgets. Because if after the dynamic
                     widgets, if there are any elements changed then we will
                     rebuild the parent widget itself. This will cause the dynamic
                     widget to build twice. To fix this dynamic widget change
                     detection and building is moved to GfxManagerCheckWidgetsChanged
                     2. GfxManagerCheckDynElementChanged was doing a
                     GfxManagerCheckWidgetsChanged even though the parent widget
                     has been rebuilt. To fix added a if(fl_screen_changed_U8 == FALSE)
                     check before GfxManagerCheckDynElementChanged() call.
                     3. Added support for nested dynamic widgets. New function
                     GfxManagerGetSelectedWidgetId() will take care of this as well
                     as change number 1.
                     4. Fixed non update of high priority screen if a lower priority
                     screen gets inserted (vmuthusu change).
                     5. Added code to clear element changed flag in the
                     GfxManagerBuildAlignedElement() to prevent repeated element build
                     even without any changes (vmuthusu change).
                     6. Fixed l_highest_active_priority variable not getting updated
                     correctly when screens are removed (vmuthusu change).
                     7. Fixed an issue of redrawing low priority screen if a highest
                     priority screen is requested (vmuthusu change).
                     8. MULTI_LINE_TEXT_NEEDED is replaced with autogenerated
                     GFX_MULTI_LINE_TEXT_ENABLED.
                     9. GfxManagerBuildScreen() updated to run the priority loop from
                     0 to the maximum active priority tarher than running from 0 to
                     NB_PRIORITY.
                     10.Updated GfxManagerBuildScreen() to handle
                     GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE configurations.
                     Have a look at 03_code\cfg\hmi_gfx_mgr_app.$cfg for more info
                     on this.

Date              :  03-Aug-09
By                :  emanoj1
Traceability      :  1.3
Change Description:  Modified to support user control of post copy by driver
                     to increase rendering rate while doing screen animations.
                     Introduced hmi_gfx_manager.cfg. Added NB_PRIORITY check
                     to disable priority loops when there is only one
                     priority.

Date              :  17-Jun-09
By                :  emanoj1
Traceability      :  1.2
Change Description:  Added support for multiple display layers and some
                     optimizations. Interface naming changed to match the file
                     name rather than use of GfxCore.

Date              :  12-Jun-09
By                :  tvijayas
Traceability      :  1.1
Change Description:  Initial version done by emanoj1 used for Reneses development
                     modified for reusability and archived.

Date              :  05-Jun-09
By                :  emanoj1
Traceability      :  1.0
Change Description:  Initial version
-----------------------------------------------------------------------------*/
