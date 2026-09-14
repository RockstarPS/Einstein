/*=============================================================================
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
 ** Name:           hmi_gfx_mgr02_dirty_area.c
 **
 ** Description:    Implements the dirty region redraw support functions to 
 **                 maintain active elements area and to derive dirty area
 **                 based on new list of area.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_PRIV_C

/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_dirty_area.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#if !defined(GFX_MGR02_SOFTWARE) && !defined(GFX_MGR02_MONOTFT) && !defined(GFX_MGR02_OPEN_VG) && !defined(GFX_MGR02_OPEN_GL) && !defined(GFX_MGR02_FUJITSU)&&!defined(GFX_MGR02_AMBER)&&!defined(GFX_MGR02_AMBER_IRIS)&&!defined(GFX_MGR02_TRAVEO2)&&!defined(GFX_MGR02_IMXRT)&&!defined(GFX_MGR02_IMXRT_PXP)
 #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
  #error "GFX_MGR02_DIRTY_REGION_REDRAW is valid only for OpenVG/Software"
 #endif
#endif

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
 #define GFX_MGR02_DAR_DIRTY_FLAG_ARRAY_SIZE     ((GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX+31)/32)
 #define GFX_MGR02_DAR_IS_TRANSPARENT_ARRAY_SIZE ((GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX+15)/16)

 #define GFX_MGR02_DAR_ADD_AREA(dst, src)   \
            ((dst))->spos = ((src))->spos;  \
            ((dst))->epos = ((src))->epos;  \
            l_dirty_rect_count++

 #define GFX_MGR02_DAR_CPY_OBJ_POS(dst, src) \
      ((dst))->spos = ((src))->spos;         \
      ((dst))->epos = ((src))->epos

 #define GFX_MGR02_DAR_GET_SPOS(src)  (((GFX_MGR02_DAR_AREA *)(src))->spos)
 #define GFX_MGR02_DAR_GET_EPOS(src)  (((GFX_MGR02_DAR_AREA *)(src))->epos)
#endif

#ifndef GFX_MGR02_DAR_RECT_PROXIMITY
 #define GFX_MGR02_DAR_RECT_PROXIMITY (0U)
#endif
#ifndef GFX_MGR02_DAR_MAX_RECTANGLES
 #define GFX_MGR02_DAR_MAX_RECTANGLES (0U)
#endif

typedef union
{
    GFX_MGR02_DAR_AREA * dar_area;
    GFX_MGR02_VISIBLE_AREA * visible_area;
} GFX_MGR02_AREA;
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
static UINT32 hmi_gfx_mgr02_dar_is_visible(GFX_MGR02_VISIBLE_AREA const * p_area,
                                    UINT32                   p_remaining_dar_count,
                                    GFX_MGR02_DAR_OBJ_INFO * p_dar_obj_info_SP);
static void hmi_gfx_mgr02_dar_delete_invalid_dirty_rect(void);
static void hmi_gfx_mgr02_dar_optimize_dirty_rect_list(void);

#endif
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
 #if GFX_MGR02_DIRTY_REGION_NUM_VALID_OBJ_CONFIG == 0
  #error "GFX_MGR02_DIRTY_REGION_REDRAW but there is no valid configuration generated\n"
 #endif
 extern GFX_MGR02_DAR_OBJ_CONFIG const lc_dirty_area_obj_config_S[GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];
#endif

/*
** This is a common work buffer shared by all layers.
*/
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
 /*
 ** l_dar_build_skip_count - indicates the number of elements that needs to be skipped
 ** from processing and rendering. This is added for the usecase where we have a base screen
 ** active and we are activating a popup. Now in this case the popup elements are
 ** added on top of the base screen elements which are already active. In this case
 ** we need not build the base screen elements again and only popup elements needs to be
 ** built. Init value for this -1 indicating an invalid or unset configuration
 ** l_dar_cur_rectangle - Indicates the current DAR region rectangle being rendered by
 ** generic.c
 ** l_dar_cur_layer     - indicates current display layer processed by DAR
 ** l_dirty_rect_count  - indicates the total number of non-overlapping dirty regions
 ** l_dar_nxt_obj_count - Indicates the total number of elements which is added to the 
 **                       DAR list after dar_start was invoked. 
 */
 static UINT16          l_dar_nxt_obj_count;
 static volatile UINT16 l_dirty_rect_count;
 static SINT16          l_dar_build_skip_count;
 static UINT16          l_dar_cur_rectangle;
 static UINT8           l_dar_cur_layer;
 /*
 ** Allow the DAR tables to be placed in a memory segment, because thes ecould be 
 ** very large size and aften requiring to keep in large capacity graphics RAM
 ** l_dar_nxt_obj_info_S - holds the information related to the element which was 
 **                        added
 ** l_dirty_rectangle_list_S - holds the total number of dirty rectangles.
 **                            initially it holds individual dirty elements rectangle
 **                            but later this will be optimized to a set of non 
 **                            overlapping rectangles.
 */
 #if defined(__CWCC__)
    #pragma push
    #pragma section RW "GFX02_DAR_RW_DATA" "GFX02_DAR_RW_DATA"
    #define GFX02_DAR_RW_DATA_PREFIX __declspec(section "GFX02_DAR_RW_DATA")
 #elif defined(__RENESAS__)
    #pragma section GFX02_DAR_RW_DATA
 #elif defined(__ghs__)
    #pragma ghs section bss="GFX02_DAR_RW_DATA"
 #elif defined(__GNUC__)
    #define GFX02_DAR_RW_DATA_PREFIX __attribute__((section("GFX02_DAR_RW_DATA")))  
 #endif
 #ifndef GFX02_DAR_RW_DATA_PREFIX
    #define GFX02_DAR_RW_DATA_PREFIX
 #endif

#if defined(__IAR_SYSTEMS_ICC__)
 #pragma location = ".GFX02_DAR_RW_DATA"
#endif
 
 static GFX02_DAR_RW_DATA_PREFIX GFX_MGR02_DAR_OBJ_INFO l_dar_nxt_obj_info_S[GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX];
#if defined(__IAR_SYSTEMS_ICC__)
 #pragma location = ".GFX02_DAR_RW_DATA"
#endif
 static GFX02_DAR_RW_DATA_PREFIX GFX_MGR02_VISIBLE_AREA l_dirty_rectangle_list_S[GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX*2];

 #if defined(__CWCC__)
   #pragma pop
 #elif (defined(__RENESAS__))
   #pragma section
 #elif defined(__ghs__)
   #pragma ghs section bss=default
 #endif
#endif /* GFX_MGR02_DIRTY_REGION_REDRAW */

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_init
Description          : Init function
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_dar_init(void)
{
   UINT32 i;
   for(i=0; i<(GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_AMBER_MERGE_WIDGETS); i++)
   {
      if(lc_dirty_area_obj_config_S[i].obj_count != GFX_MGR02_NULL_PTR)
      {
         *lc_dirty_area_obj_config_S[i].obj_count = 0;
      }
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_start
Description          : Initializes the DAR to start the dirty area calculation
                       process for a passed layer
Invocation           : by generic.c
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_dar_start(UINT8 p_layer_id)
{
   l_dar_nxt_obj_count     = 0U;
   l_dirty_rect_count      = 0U;
   l_dar_cur_layer         = p_layer_id;
   l_dar_build_skip_count = -1;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_add
Description          : Adds an element to the DAR next list.
Invocation           : by generic.c
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_dar_add(GFX_MGR02_DAR_OBJECT * p_dar_obj_SP, GFX_FLOAT * p_bound)
{
   UINT32 fl_ret =(UINT32)FALSE;
   if(l_dar_nxt_obj_count <(UINT16) GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX)
   {
      GFX_MGR02_CONTEXT_T   const       * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
      GFX_MGR02_DAR_OBJ_INFO            * fl_dar_nxt_obj_info_SP;
      UINT32                              fl_cur_rect_list_count;
      GFX_MGR02_DAR_OBJ_INFO            * fl_dar_cur_obj_info_SP;
      UINT32                              fl_elem_exists = FALSE;
      GFX_MGR02_AREA                      fl_dar_va_1;
      GFX_MGR02_AREA                      fl_dar_va_2;      
      GFX_MGR02_VISIBLE_AREA              fl_area; 
      GFX_FLOAT                           fl_area_ex_temp;
      GFX_FLOAT                           fl_area_ey_temp;
      if(fl_context_SP->state.alpha < 255U)
      {
         p_dar_obj_SP->opeque = 0U;
      }

      fl_area.sx = (SINT16)p_bound[0];
      fl_area.sy = (SINT16)p_bound[1];
      fl_area_ex_temp = p_bound[0]+p_bound[2]+(GFX_FLOAT)0.5;
      fl_area.ex = (SINT16)(fl_area_ex_temp);
      fl_area_ey_temp = p_bound[1]+p_bound[3]+(GFX_FLOAT)0.5;
      fl_area.ey = (SINT16)(fl_area_ey_temp);

#if defined(GFX_MGR02_CLIPPED_WIDGETS) || \
    defined(GFX_MGR02_KEPLER)          || \
    defined(GFX_MGR02_AMBER)           || \
    defined(GFX_MGR02_AMBER_IRIS)      || \
    defined(GFX_MGR02_TRAVEO2)         || \
    defined(GFX_MGR02_IMXRT)           || \
    defined(GFX_MGR02_IMXRT_PXP)       || \
    defined(GFX_MGR02_SOFTWARE)        || \
    (GFX_MGR02_TOUCH_SCREEN_ENABLED > 0)
      if(fl_area.sx < fl_context_SP->state.clip.sx)
      {
         fl_area.sx = fl_context_SP->state.clip.sx;
      }
      if(fl_area.sy < fl_context_SP->state.clip.sy)
      {
         fl_area.sy = fl_context_SP->state.clip.sy;
      }
      if(fl_area.ex > fl_context_SP->state.clip.ex)
      {
         fl_area.ex = fl_context_SP->state.clip.ex;
      }
      if(fl_area.ey > fl_context_SP->state.clip.ey)
      {
         fl_area.ey = fl_context_SP->state.clip.ey;
      }
#endif
      
      if(l_dar_cur_layer < (GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_AMBER_MERGE_WIDGETS))
      {
          if(p_dar_obj_SP->dirty_area != FALSE)
          {
             /* element is dirty, add to list if we have got space */
             if(l_dirty_rect_count < ((sizeof(l_dirty_rectangle_list_S)) / (sizeof(GFX_MGR02_VISIBLE_AREA))))
             {
                 fl_dar_va_1.visible_area = &l_dirty_rectangle_list_S[l_dirty_rect_count];
                 fl_dar_va_2.visible_area = &fl_area;
                 GFX_MGR02_DAR_ADD_AREA(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
                /*
                ** Do a search for this element inside the currently active element
                ** list. If the element is present inside that list then
                ** it means, the element may have been moved/transformed. So we have to
                ** make current area also as dirty and add it to the list
                */
                fl_cur_rect_list_count = *lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_count;
                fl_dar_cur_obj_info_SP = &lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[0];
                while(fl_cur_rect_list_count > 0U)
                {
                   fl_cur_rect_list_count--;
                   if(fl_dar_cur_obj_info_SP->elem_SP == p_dar_obj_SP->elem_SP)
                   {
                      if(l_dirty_rect_count < (sizeof(l_dirty_rectangle_list_S)/sizeof(GFX_MGR02_VISIBLE_AREA)))
                      {
                         /*
                         ** If this dirty element was present in the current active
                         ** element list array then add its area also in to dirty area list
                         ** delete the element from the current list since have added it already
                         */
                         fl_dar_va_1.visible_area = &l_dirty_rectangle_list_S[l_dirty_rect_count];
                         fl_dar_va_2.visible_area = &fl_dar_cur_obj_info_SP->area;
                         GFX_MGR02_DAR_ADD_AREA(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
                         fl_dar_cur_obj_info_SP->elem_SP = GFX_MGR02_NULL_PTR;
                         fl_cur_rect_list_count          = 0;
                         fl_elem_exists                  = TRUE;
                      }
                   }
                   fl_dar_cur_obj_info_SP++;
                }
                if(fl_elem_exists != FALSE)
                {
                   /* 
                   ** an existing element became dirty, which means start 
                   ** rendering from element 0 itself
                   */
                   l_dar_build_skip_count = 0;
                }
                else if(l_dar_build_skip_count < 0)
                {
                   /*
                   ** This element is a new element, so if skip count is unset
                   ** set the elements added so far to be skipped.
                   */
                   l_dar_build_skip_count = (SINT16)l_dar_nxt_obj_count;
                }
                else
                {
                    /*To Fix MISRA warning.*/
                }
             #ifdef GFX02_DEBUG_DAR
                gfx_debug("Dirty-Object = %d,%d,%d,%d Added\n", fl_area.sx, fl_area.sy, fl_area.ex,fl_area.ey);
             #endif
             }
          #ifdef GFX02_DEBUG_DAR
             else
             {
                gfx_debug("Dirty-Object = %d,%d,%d,%d No space left to Add\n", fl_area.sx, fl_area.sy, fl_area.ex, fl_area.ey);
             }
          #endif
          }
          else
          {
             /* 
             ** element not dirty 
             */
             fl_cur_rect_list_count = *lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_count;
             fl_dar_cur_obj_info_SP = &lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[0];
             while(fl_cur_rect_list_count > 0U)
             {
                fl_cur_rect_list_count--;
                if(fl_dar_cur_obj_info_SP->elem_SP == p_dar_obj_SP->elem_SP)
                {
                   /*
                   ** This element exists in the current list also and not ditry
                   ** so delete it as it need not be processed any further.
                   */
                   fl_dar_cur_obj_info_SP->elem_SP = GFX_MGR02_NULL_PTR;
                   fl_cur_rect_list_count          = 0;
                   fl_elem_exists                  = TRUE;
                }
                fl_dar_cur_obj_info_SP++;
             }
             if(fl_elem_exists != FALSE)
             {
                if(l_dar_build_skip_count > 0)
                {
                   /*
                   ** If any existing element which is not dirty found
                   ** reset the skip count back to zero since the new elements
                   ** would have been added inbetween and therefore better to perform
                   ** full build.
                   */
                   l_dar_build_skip_count = 0;
                }
             }
          }
          /*
          ** Copy the element in to next element list array
          */
          fl_dar_nxt_obj_info_SP = &l_dar_nxt_obj_info_S[l_dar_nxt_obj_count];
          fl_dar_va_1.visible_area = &fl_dar_nxt_obj_info_SP->area;
          fl_dar_va_2.visible_area = &fl_area;               
          GFX_MGR02_DAR_CPY_OBJ_POS(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
          fl_dar_nxt_obj_info_SP->elem_SP = p_dar_obj_SP->elem_SP;
          fl_dar_nxt_obj_info_SP->opeque  = p_dar_obj_SP->opeque;
          fl_dar_nxt_obj_info_SP->visible = TRUE;
          l_dar_nxt_obj_count++;
          fl_ret =(UINT32)TRUE;
      }
   }
   return(fl_ret);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_delete_invalid_dirty_rect
Description          : Arranges the dirty rect list by deleting the invalid
                       rectangles.
Invocation           : Internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_dar_delete_invalid_dirty_rect(void)
{
   GFX_MGR02_VISIBLE_AREA * fl_cur_rect_SP = &l_dirty_rectangle_list_S[0];
   GFX_MGR02_VISIBLE_AREA * fl_nxt_rect_SP = &l_dirty_rectangle_list_S[0];
   UINT32                   fl_rect_index  = 0;
   UINT32                   fl_dirty_rect_count = 0;

   while(fl_rect_index < l_dirty_rect_count)
   {
      fl_rect_index++;
      if((fl_nxt_rect_SP->sx >= fl_nxt_rect_SP->ex) || (fl_nxt_rect_SP->sy >= fl_nxt_rect_SP->ey))
      {
         fl_nxt_rect_SP++;
      }
      else
      {
         if(fl_cur_rect_SP != fl_nxt_rect_SP)
         {
            ((GFX_MGR02_DAR_AREA *)fl_cur_rect_SP)->spos = ((GFX_MGR02_DAR_AREA *)fl_nxt_rect_SP)->spos;
            ((GFX_MGR02_DAR_AREA *)fl_cur_rect_SP)->epos = ((GFX_MGR02_DAR_AREA *)fl_nxt_rect_SP)->epos;
         }
         fl_cur_rect_SP++;
         fl_nxt_rect_SP++;
         fl_dirty_rect_count++;
      }
   }
   l_dirty_rect_count = (UINT16)fl_dirty_rect_count;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_optimize_dirty_rect_list
Description          : Runs until all the rectangles in the list are non
                       overlapping. If there are overlapped rectangles in
                       list, they will be combined to form a single rectangle
                       which covers both. This runs until all overlapping 
                       rectangles are combined and are not overlapping.
Invocation           : Invoked by hmi_gfx_mgr02_dar_process()
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_dar_optimize_dirty_rect_list(void)
{
   GFX_MGR02_VISIBLE_AREA * fl_cur_rect_SP = &l_dirty_rectangle_list_S[0];
   GFX_MGR02_VISIBLE_AREA * fl_nxt_rect_SP;
   UINT32 fl_num_rect = 0;
   UINT32 fl_remaining_rects;
   UINT32 fl_rect_combined;
   UINT32 fl_rect_combined_count = 0; /* just to make sure we don't get stuck here */

   SINT32 fl_cur_sx;
   SINT32 fl_cur_sy;
   SINT32 fl_cur_ex;
   SINT32 fl_cur_ey;
#if (GFX_MGR02_DAR_RECT_PROXIMITY > 0) || (GFX_MGR02_DAR_MAX_RECTANGLES > 0)
   GFX_MGR02_CONTEXT_T  const  * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
   SINT32 fl_max_x = (SINT32)fl_context_SP->rprop.fb_w;
   SINT32 fl_max_y = (SINT32)fl_context_SP->rprop.fb_h;
#endif

   while(fl_rect_combined_count < l_dirty_rect_count)
   {
      if (fl_num_rect < l_dirty_rect_count)
      {
         fl_num_rect++;
         fl_rect_combined = FALSE;
         /*
         ** Run the loop only if rectangle is valid
         */

         fl_cur_sx = fl_cur_rect_SP->sx;
         fl_cur_sy = fl_cur_rect_SP->sy;
         fl_cur_ex = fl_cur_rect_SP->ex;
         fl_cur_ey = fl_cur_rect_SP->ey;
      #if GFX_MGR02_DAR_RECT_PROXIMITY > 0
         /*
         ** Increase the size of cur rectangle by a factor, so that closer
         ** by rectangles gets combined even if they don't really overlap
         ** This is to help reduce the number of dirty rectangles when the
         ** render loop runs.
         */
         fl_cur_sx -= GFX_MGR02_DAR_RECT_PROXIMITY;
         fl_cur_sy -= GFX_MGR02_DAR_RECT_PROXIMITY;
         fl_cur_ex += GFX_MGR02_DAR_RECT_PROXIMITY;
         fl_cur_ey += GFX_MGR02_DAR_RECT_PROXIMITY;
         /* clamp the bounds to available TFT area */
         if(fl_cur_sx < 0)
         {
            fl_cur_sx = 0;
         }
         if(fl_cur_sy < 0)
         {
            fl_cur_sy = 0;
         }
         if(fl_cur_ex > fl_max_x)
         {
            fl_cur_ex = fl_max_x;
         }
         if(fl_cur_ey > fl_max_y)
         {
            fl_cur_ey = fl_max_y;
         }
      #endif
         if((fl_cur_rect_SP->sx < fl_cur_rect_SP->ex) && 
            (fl_cur_rect_SP->sy < fl_cur_rect_SP->ey))
         {
            /*
            ** Check the fl_cur_rect_SP against rest of the rectangles following it in
            ** the list. e.g if we have 5 elements in list and if the fl_cur_rect_SP points
            ** to element 2 in the list, the comparisons for overlap will be performed with
            ** element 3-5. i.e. fl_nxt_rect_SP will be loaded with elem area of 3 to 5
            ** and will be compared against element 2 area for overlap.
            ** Once an overlap is detected, the fl_cur_rect_SP area will be combined with
            ** the fl_nxt_rect_SP and the fl_cur_rect_SP will be made invalid. And the loop
            ** will be restarted from the begenining of the list.
            */
            fl_remaining_rects = fl_num_rect;
            fl_nxt_rect_SP     = fl_cur_rect_SP;
            while((fl_remaining_rects < l_dirty_rect_count) && (fl_rect_combined == FALSE))
            {
               fl_remaining_rects++;
               fl_nxt_rect_SP++;

               if((fl_nxt_rect_SP->sx < fl_nxt_rect_SP->ex) && (fl_nxt_rect_SP->sy < fl_nxt_rect_SP->ey))
               {
                  if((fl_cur_rect_SP->sx <= fl_nxt_rect_SP->sx) && 
                     (fl_cur_rect_SP->sy <= fl_nxt_rect_SP->sy) &&
                     (fl_cur_rect_SP->ex >= fl_nxt_rect_SP->ex) && 
                     (fl_cur_rect_SP->ey >= fl_nxt_rect_SP->ey))
                  {
                     /*
                     ** fl_nxt_rect_SP is completely hidden in fl_cur_rect_SP
                     ** so deleting fl_nxt_rect_SP
                     */
                     ((GFX_MGR02_DAR_AREA *)fl_nxt_rect_SP)->spos = 0;
                     ((GFX_MGR02_DAR_AREA *)fl_nxt_rect_SP)->epos = 0;
                  }
                  else if( ((fl_cur_sx >= fl_nxt_rect_SP->sx) && (fl_cur_sx <= fl_nxt_rect_SP->ex)) ||
                           ((fl_cur_ex >= fl_nxt_rect_SP->sx) && (fl_cur_ex <= fl_nxt_rect_SP->ex)) ||
                           ((fl_cur_sx <  fl_nxt_rect_SP->sx) && (fl_cur_ex >  fl_nxt_rect_SP->ex)) )
                  {
                        if( ((fl_cur_sy >= fl_nxt_rect_SP->sy) && (fl_cur_sy <= fl_nxt_rect_SP->ey)) ||
                           ((fl_cur_ey >= fl_nxt_rect_SP->sy) && (fl_cur_ey <= fl_nxt_rect_SP->ey)) ||
                           ((fl_cur_sy <  fl_nxt_rect_SP->sy) && (fl_cur_ey >  fl_nxt_rect_SP->ey)) )
                        {
                           /*
                           ** Layer is overlapping.
                           */
                           if(fl_cur_rect_SP->sx < fl_nxt_rect_SP->sx)
                           {
                              fl_nxt_rect_SP->sx = fl_cur_rect_SP->sx;
                              fl_rect_combined   = TRUE;
                           }
                           if(fl_cur_rect_SP->sy < fl_nxt_rect_SP->sy)
                           {
                              fl_nxt_rect_SP->sy = fl_cur_rect_SP->sy;
                              fl_rect_combined   = TRUE;
                           }
                           if(fl_cur_rect_SP->ex > fl_nxt_rect_SP->ex)
                           {
                              fl_nxt_rect_SP->ex = fl_cur_rect_SP->ex;
                              fl_rect_combined   = TRUE;
                           }
                           if(fl_cur_rect_SP->ey > fl_nxt_rect_SP->ey)
                           {
                              fl_nxt_rect_SP->ey = fl_cur_rect_SP->ey;
                              fl_rect_combined   = TRUE;
                           }
                           /*
                           ** Current rectangle got combined with next rectangle, so
                           ** removing current rectangle.
                           */
                           ((GFX_MGR02_DAR_AREA *)fl_cur_rect_SP)->spos = 0;
                           ((GFX_MGR02_DAR_AREA *)fl_cur_rect_SP)->epos = 0;
                           /*
                           ** If the cur rectangle is within the next rectangle, then
                           ** the cur rectangle is already accounted for by the next.
                           ** Since no new rectangle is formed by comining cur with next, 
                           ** there is no need to run this loop and we need not restart
                           ** from the begening. So just break the loop to proceed to next
                           ** rectangle.
                           */
                           if(fl_rect_combined == FALSE)
                           {
                              fl_remaining_rects = l_dirty_rect_count;
                           }
                        }
                  }
                  else
                  {
                     /*To Fix MISRA warning.*/
                  }
               }
            }
         }
         if(fl_rect_combined != FALSE)
         {
            /*
            ** Since we have just combined a rectangle to a bigger one
            ** chances are that it might overlap with other rectangles
            ** we covered already. So we are restarting from begining of the
            ** list again to cover that possibility
            */
            fl_cur_rect_SP = &l_dirty_rectangle_list_S[0];
            fl_num_rect    = 0;
            fl_rect_combined_count++;
         #ifdef GFX02_DEBUG_DAR
            gfx_debug("Rect Combined = %d,%d,%d,%d\n", fl_nxt_rect_SP->sx, fl_nxt_rect_SP->sy, fl_nxt_rect_SP->ex, fl_nxt_rect_SP->ey);
         #endif
         }
         else
         {
            fl_cur_rect_SP++;
         }
      }
      else
      {
         break;
      }
   }
   hmi_gfx_mgr02_dar_delete_invalid_dirty_rect();
#if GFX_MGR02_DAR_MAX_RECTANGLES > 0
   if(l_dirty_rect_count > (UINT16)GFX_MGR02_DAR_MAX_RECTANGLES)
   {
      /*
      ** If the number of dirty rectangles is more than the configured
      ** threshold, opt for a full layer area build.
      */
      l_dirty_rect_count = 1U;
      l_dirty_rectangle_list_S[0].sx = 0;
      l_dirty_rectangle_list_S[0].sy = 0;
      l_dirty_rectangle_list_S[0].ex = (SINT16)fl_max_x;
      l_dirty_rectangle_list_S[0].ey = (SINT16)fl_max_y;
   }
#endif
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_is_visible
Description          : Analyzes the passed elements for its partial or full 
                       visibility. 
Invocation           : by DAR processing
Parameters           : None.
Return Value         : Returns FALSE if the element is fully hidden behind 
                       other elements on top it. Returns TRUE if its partially
                       or fully visible
Critical Section     : None
External Interfaces  : None
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static UINT32 hmi_gfx_mgr02_dar_is_visible(GFX_MGR02_VISIBLE_AREA const * p_area,
                                    UINT32                   p_remaining_dar_count,
                                    GFX_MGR02_DAR_OBJ_INFO * p_dar_obj_info_SP)
{
   UINT32                  fl_visible = TRUE;
   UINT32                  fl_overlap_visible;
   GFX_MGR02_VISIBLE_AREA  fl_area;
   GFX_MGR02_VISIBLE_AREA  fl_area2;
   SINT16                  fl_temp;
   UINT32                  fl_remaining_dar_count = p_remaining_dar_count;
   GFX_MGR02_DAR_OBJ_INFO * fl_dar_obj_info_SP = p_dar_obj_info_SP;
   while((fl_remaining_dar_count > 0U) && (fl_visible != FALSE))
   {
      fl_remaining_dar_count--;
      fl_area.sx = fl_dar_obj_info_SP->area.sx;
      fl_area.sy = fl_dar_obj_info_SP->area.sy; 
      fl_area.ex = fl_dar_obj_info_SP->area.ex; 
      fl_area.ey = fl_dar_obj_info_SP->area.ey; 
      if((fl_dar_obj_info_SP->opeque != 0U) && (fl_dar_obj_info_SP->visible != 0U))
      {
         fl_dar_obj_info_SP++;
         if((fl_area.sx <= p_area->sx) && (fl_area.sy <= p_area->sy) &&
            (fl_area.ex >= p_area->ex) && (fl_area.ey >= p_area->ey))
         {
            /*
            ** p_area is completely hidden in fl_area
            */
            fl_visible = FALSE;
         }
         else if(((fl_area.sx >= p_area->sx) && (fl_area.sx <= p_area->ex)) ||
                 ((fl_area.ex >= p_area->sx) && (fl_area.ex <= p_area->ex)) ||
                 ((fl_area.sx <  p_area->sx) && (fl_area.ex >  p_area->ex)) )
         {
            if(((fl_area.sy >= p_area->sy) && (fl_area.sy <= p_area->ey)) ||
               ((fl_area.ey >= p_area->sy) && (fl_area.ey <= p_area->ey)) ||
               ((fl_area.sy <  p_area->sy) && (fl_area.ey >  p_area->ey)) )
            {
               if(fl_remaining_dar_count > 0U)
               {
                  /*
                  ** Layer is overlapping.
                  */
                  fl_area2.sx        = p_area->sx;
                  fl_area2.sy        = p_area->sy;
                  fl_area2.ex        = p_area->ex;
                  fl_area2.ey        = p_area->ey;
                  fl_overlap_visible = FALSE;
                  if(fl_area.sy > p_area->sy)
                  {
                     /*
                     ** Visible top portion of the p_area rectangle
                     */
                     fl_area2.ey        = (SINT16)(fl_area.sy - 1);
                     fl_overlap_visible = hmi_gfx_mgr02_dar_is_visible(&fl_area2, fl_remaining_dar_count, fl_dar_obj_info_SP);
                     fl_area2.sy        = fl_area.sy;
                     fl_area2.ey        = p_area->ey;
                  }
                  if((fl_area.ey < p_area->ey) && (fl_overlap_visible == FALSE))
                  {
                     /*
                     ** Visible bottom portion of the p_area rectangle
                     */
                     fl_temp            = fl_area2.sy;
                     fl_area2.sy        = (SINT16)(fl_area.ey + 1);
                     fl_overlap_visible = hmi_gfx_mgr02_dar_is_visible(&fl_area2, fl_remaining_dar_count, fl_dar_obj_info_SP);
                     fl_area2.sy        = fl_temp;
                     fl_area2.ey        = fl_area.ey;
                  }
                  if((fl_area.sx > p_area->sx) && (fl_overlap_visible == FALSE))
                  {
                     /*
                     ** Visible Left portion of the p_area rectangle
                     */
                     fl_area2.ex        = (SINT16)(fl_area.sx - 1);
                     fl_overlap_visible = hmi_gfx_mgr02_dar_is_visible(&fl_area2, fl_remaining_dar_count, fl_dar_obj_info_SP);
                     fl_area2.ex        = p_area->ex;

                  }
                  if((fl_area.ex < p_area->ex) && (fl_overlap_visible == FALSE))
                  {
                     /*
                     ** Visible Right portion of the p_area rectangle
                     */
                     fl_area2.sx        = (SINT16)(fl_area.ex+1);
                     fl_overlap_visible = hmi_gfx_mgr02_dar_is_visible(&fl_area2, fl_remaining_dar_count, fl_dar_obj_info_SP);
                  }
               }
               else
               {
                  fl_overlap_visible = TRUE;
               }
               fl_visible            = fl_overlap_visible;
               fl_remaining_dar_count = 0U;
            }
         }
         else
         {
            /* fl_area doesnot overlaps with p_area */
         }
      }
      else
      {
         fl_dar_obj_info_SP++;
      }
   }
   return(fl_visible);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_process
Description          : Does initial level of filtering by removing all 
                       invisible/hidden elements. Prepares a dirty rectangle
                       list and then optimizes the list by combining all 
                       overlapping rectangles in to a single entry.
                       Updated the current DAR element list with new list
Invocation           : by generic.c
Parameters           : None.
Return Value         : Number of dirty regions
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_dar_process(void)
{
   UINT32                   fl_nxt_rect_list_count;
   UINT32                   fl_cur_rect_list_count;
   GFX_MGR02_DAR_OBJ_INFO * fl_dar_nxt_obj_info_SP;
   GFX_MGR02_DAR_OBJ_INFO * fl_dar_cur_obj_info_SP;
   GFX_MGR02_AREA           fl_dar_va_1;
   GFX_MGR02_AREA           fl_dar_va_2;
   
#ifndef GFX_MGR02_DAR_SKIP_VISIBILE_CHK
   GFX_MGR02_VISIBLE_AREA const * fl_visible_area_SP;
#endif
   /*
   ** The hmi_gfx_mgr02_dar_process starts after all dirty objects are added
   ** to l_dar_nxt_obj_info_S[] by hmi_gfx_mgr02_dar_add
   ** The fl_dar_cur_obj_info_SP will contain the previous dirty element list
   ** when the hmi_gfx_mgr02_dar_add performs new additions. And hmi_gfx_mgr02_dar_add
   ** routine will remove items from fl_dar_cur_obj_info_SP if they exists in
   ** l_dar_nxt_obj_info_S[] as well as in fl_dar_cur_obj_info_SP[]
   ** So when hmi_gfx_mgr02_dar_process starts the next list contains
   ** new dirty elements, and cur list contains old items which are non longer present
   ** new element list (which means in active element list which need to be removed).
   ** This means the element which are left out in fl_dar_cur_obj_info_SP need also to
   ** added to dirty region list
   */
   if (l_dar_cur_layer < (GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_AMBER_MERGE_WIDGETS))
   {
       fl_cur_rect_list_count = *lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_count;
       *lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_count = l_dar_nxt_obj_count;
       fl_dar_cur_obj_info_SP = &lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[0];
       fl_dar_nxt_obj_info_SP = &l_dar_nxt_obj_info_S[0];
       fl_nxt_rect_list_count = l_dar_nxt_obj_count;
       while(fl_cur_rect_list_count > 0U)
       {
          /* 
          ** This loop verifies for left out elements inside cur list and add them
          ** to dirty region list and copies next element list to current list 
          */
          fl_cur_rect_list_count--;
          
          if(fl_dar_cur_obj_info_SP->elem_SP != GFX_MGR02_NULL_PTR)
          {
             /*
             ** This element is in current list but not there in new list
             ** that means it got deactivated and its area needs to be marked as
             ** dirty and added to dirty area list
             */
             l_dar_build_skip_count = 0;
             if(l_dirty_rect_count < ((sizeof(l_dirty_rectangle_list_S)) / (sizeof(GFX_MGR02_VISIBLE_AREA))))
             {
                 fl_dar_va_1.visible_area = &l_dirty_rectangle_list_S[l_dirty_rect_count];
                 fl_dar_va_2.visible_area = &fl_dar_cur_obj_info_SP->area;
                 GFX_MGR02_DAR_ADD_AREA(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
             }
          }
          if(fl_nxt_rect_list_count > 0U)
          {
             /*
             ** Copy next element to current list
             */
             fl_dar_va_1.visible_area = &fl_dar_cur_obj_info_SP->area;
             fl_dar_va_2.visible_area = &fl_dar_nxt_obj_info_SP->area;               
             GFX_MGR02_DAR_CPY_OBJ_POS(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
             fl_dar_cur_obj_info_SP->elem_SP = fl_dar_nxt_obj_info_SP->elem_SP;
             fl_dar_cur_obj_info_SP->visible = fl_dar_nxt_obj_info_SP->visible;
             fl_dar_cur_obj_info_SP->opeque  = fl_dar_nxt_obj_info_SP->opeque;
             fl_dar_nxt_obj_info_SP++;
             fl_nxt_rect_list_count--;
          }
          fl_dar_cur_obj_info_SP++;
       }
       while(fl_nxt_rect_list_count > 0U)
       {
          /* 
          ** This loop copies remaining next list to cur list
          */
          fl_dar_va_1.visible_area = &fl_dar_cur_obj_info_SP->area;
          fl_dar_va_2.visible_area = &fl_dar_nxt_obj_info_SP->area;               
          GFX_MGR02_DAR_CPY_OBJ_POS(fl_dar_va_1.dar_area, fl_dar_va_2.dar_area);
          fl_dar_cur_obj_info_SP->elem_SP = fl_dar_nxt_obj_info_SP->elem_SP;
          fl_dar_cur_obj_info_SP->visible = fl_dar_nxt_obj_info_SP->visible;
          fl_dar_cur_obj_info_SP->opeque  = fl_dar_nxt_obj_info_SP->opeque;
          fl_dar_nxt_obj_info_SP++;
          fl_dar_cur_obj_info_SP++;
          fl_nxt_rect_list_count--;
       }
       /*
       ** Mark elements which are getting hidden behind higher priority elements
       ** by analyzing their visibility.
       */
       if(l_dar_build_skip_count < 0)
       {
          l_dar_build_skip_count = 0;
       }
       if(l_dar_nxt_obj_count > 0U)
       {
          /* 
          ** topmost object is visible by default 
          */
          fl_dar_nxt_obj_info_SP  = &lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[l_dar_nxt_obj_count-1U];
          fl_dar_nxt_obj_info_SP->visible = 1U;
          fl_nxt_rect_list_count          = 1U;
          fl_dar_nxt_obj_info_SP--;

          fl_cur_rect_list_count = l_dar_nxt_obj_count;
          if(l_dar_build_skip_count > 0)
          {
             fl_cur_rect_list_count -= (UINT32)l_dar_build_skip_count;
          }

          while(fl_nxt_rect_list_count < fl_cur_rect_list_count)
          {
             #ifndef GFX_MGR02_DAR_SKIP_VISIBILE_CHK
             fl_visible_area_SP = &fl_dar_nxt_obj_info_SP->area;
             if(hmi_gfx_mgr02_dar_is_visible(fl_visible_area_SP,fl_nxt_rect_list_count,&fl_dar_nxt_obj_info_SP[1]) == FALSE)
             {
                /* this element is not visible */
                fl_dar_nxt_obj_info_SP->visible = 0U;
             }
             else
             #endif
             {
                /* this element is visible */
                fl_dar_nxt_obj_info_SP->visible = 1U;
             }
             fl_nxt_rect_list_count++;
             fl_dar_nxt_obj_info_SP--;
          }
          while(l_dar_build_skip_count > 0)
          {
             l_dar_build_skip_count--;
             fl_dar_nxt_obj_info_SP->visible = 0U;
             fl_dar_nxt_obj_info_SP--;
          }
       }
       /*
       ** Optimize the dirty region list to a non overlaping list of
       ** rectangles.
       */
       hmi_gfx_mgr02_dar_optimize_dirty_rect_list();
       l_dar_nxt_obj_count = 0U;
       l_dar_cur_rectangle = 0U;
   }
   return (UINT32)l_dirty_rect_count;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_get_drect
Description          : Returns the dirty rectangle info for the passed index
Invocation           : generic.c
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_dar_get_drect(UINT32 p_index)
{
   GFX_MGR02_VISIBLE_AREA * fl_rect = GFX_MGR02_NULL_PTR;

   if(p_index < l_dirty_rect_count)
   {
      fl_rect             = &l_dirty_rectangle_list_S[p_index];
      l_dar_cur_rectangle = (UINT16)p_index;
   #ifdef GFX02_DEBUG_DAR
      gfx_debug("Drect = %d,%d,%d,%d\n", fl_rect->sx, fl_rect->sy, fl_rect->ex, fl_rect->ey);
   #endif
      if((fl_rect->sx >= fl_rect->ex) || (fl_rect->sy >= fl_rect->ey))
      {
         fl_rect = GFX_MGR02_NULL_PTR;
      }
      /*
      ** hmi_gfx_mgr02_dar_get_drect is called by the hmi_gfx_mgr02_generic_build_screen()
      ** function to set the clip rectangle and initiate the build. So the generic
      ** build routine will call this function the number of dirty rectangles 
      ** present inside l_dirty_rectangle_list_S[]
      ** Since each call to this will be a begining of a new build cycle, we are 
      ** clearing l_dar_nxt_obj_count = 0 to point to the first element in
      ** lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[] to return
      ** the correct area for element by hmi_gfx_mgr02_dar_get_object_area()
      ** l_dar_nxt_obj_countis reused for a different purpose by the 
      ** hmi_gfx_mgr02_dar_get_object_area() under the assumption that the other
      ** process routines no longer require while we are in building phase.
      ** The other routine uses uses this during the initial dirty area finding
      ** phase.
      */ 
      l_dar_nxt_obj_count = 0U;
   }

   return(fl_rect);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_get_object_area
Description          : Returns area correspondiing to the passed element
                       by searching the DAR cur element list. Area is returned
                       as NULL if the elements area falls outside the currently
                       selected dirty region by l_dar_cur_rectangle OR if the 
                       element could not be located inside DAR cur list
Invocation           : by generic.c
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_dar_get_object_area(GFX_MGR02_ELEM_LIST_T const * p_elem_SP)
{
   GFX_MGR02_DAR_OBJ_INFO * fl_dar_cur_obj_info_SP;
   GFX_MGR02_VISIBLE_AREA * fl_area = GFX_MGR02_NULL_PTR;
   UINT32 fl_obj_count;
   UINT32 fl_visible;
   SINT32 fl_search_count = (SINT32)l_dar_nxt_obj_count;
   
   if (l_dar_cur_layer < (GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_AMBER_MERGE_WIDGETS))
   {
       fl_obj_count           = *lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_count;

       if(fl_search_count < (SINT32)fl_obj_count)
       {
          fl_dar_cur_obj_info_SP = &lc_dirty_area_obj_config_S[l_dar_cur_layer].obj_info[fl_search_count];
          while((fl_search_count < (SINT32)fl_obj_count) && (fl_area == GFX_MGR02_NULL_PTR))
          {
             fl_search_count++;
             if(fl_dar_cur_obj_info_SP->elem_SP == p_elem_SP)
             {
                fl_visible = fl_dar_cur_obj_info_SP->visible;
                if(fl_visible != 0U)
                {
                   /*
                   ** Contain the element area within the DAR current rectangle
                   */
                   if (l_dar_cur_rectangle < (UINT16)(GFX_MGR02_DAR_OBJ_LIST_SIZE_MAX*2))
                   {
                       GFX_MGR02_VISIBLE_AREA fl_clipped_area;
                       fl_clipped_area.sx = l_dirty_rectangle_list_S[l_dar_cur_rectangle].sx;
                       fl_clipped_area.sy = l_dirty_rectangle_list_S[l_dar_cur_rectangle].sy;
                       fl_clipped_area.ex = l_dirty_rectangle_list_S[l_dar_cur_rectangle].ex;
                       fl_clipped_area.ey = l_dirty_rectangle_list_S[l_dar_cur_rectangle].ey;
                       if(hmi_gfx_mgr02_context_validate_clip(&fl_clipped_area, &fl_dar_cur_obj_info_SP->area) == FALSE)
                       {
                          /*
                          ** Check if the element is fully or partially visible
                          */
                        #ifndef GFX_MGR02_DAR_SKIP_VISIBILE_CHK
                          fl_visible = hmi_gfx_mgr02_dar_is_visible(&fl_clipped_area,
                                                                    (fl_obj_count-(UINT32)fl_search_count),
                                                                    &fl_dar_cur_obj_info_SP[1]);
                        #else
                          fl_visible = TRUE;
                        #endif
                       }
                       else
                       {
                          /*
                          ** Current element falls outside the DAR
                          */
                          fl_visible = 0U;
                       }
                   }
                }
                l_dar_nxt_obj_count = (UINT16)fl_search_count;
                if(fl_visible == 0U)
                {
                   /* element not visible, break the loop */
                   fl_search_count = (SINT32)fl_obj_count;
                }
                else
                {
                   /* 
                   ** found area for the passed element and is visible as well
                   */
                   fl_area = &fl_dar_cur_obj_info_SP->area;
                }
             }
             else
             {
                fl_dar_cur_obj_info_SP++;
             }
          }
       }
   }
   return(fl_area);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_dar_get_num_drects
Description          : Returns the number of dirty regions
Invocation           : by generic.c
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_dar_get_num_drects(void)
{
   return (UINT32)l_dirty_rect_count;
}

#endif /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */

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
 ** CMS Rev 1.8     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.8     3-Nov-2015    SSIGAMAN
 ** RTC 456457:
 ** Updated the Module to adapt the Dirty Area Feature for Amber platform.
 **
 ** CMS Rev 1.7     25-Jul-2014    EMANOJ1
 ** hmi_gfx_mgr02_dar_optimize_dirty_rect_list() updated to fix an issue where
 ** a larger dirty rectangle was formed due to an error in logic.
 ** The logic removes a rectangle by making sx=sy=ex=ey=0, now this was considered
 ** as a valid rectangle by the logic when the cur rectangle is fully contained within 
 ** the next rectangle. And a resultant rectangle with sx=0, sy= 0, ex=next.ex, ey=next.ey
 ** is formed. Now logic is updated to skip this so that dirty rectangle list is
 ** correctly formed.
 **
 ** CMS Rev 1.6     25-Nov-2013    CMUTHUSA
 ** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
 **
 ** CMS Rev 1.5      15-Oct-2013    EMANOJ1
 ** Crash issue due to loop control variable (fl_search_count) left unchanged
 ** in function hmi_gfx_mgr02_dar_get_object_area fixed.
 **
 ** CMS Rev 1.4      26-Aug-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_dar_add to accept the bound as a parameter. This
 ** was updated becuase the bound calculation is now done as float to support
 ** the dynamic buffer allocation for OpenVG widgets in Kepler DCU platforms.
 ** So the conversion to int and boundary check for the bound is also moved
 ** to here.
 **
 ** CMS Rev 1.3      24-Jun-2013    EMANOJ1
 ** Added GFX_MGR02_DAR_RECT_PROXIMITY config option to allow combining nearby 
 ** rectangles based on a configured proximity pixels value, even though they
 ** don't really overlap each other. This is an attempt to reduce the number
 ** of dirty rectangles.
 ** GFX_MGR02_DAR_MAX_RECTANGLES config option support to select a full 
 ** layer update if the number of rectangle crosess this threshold.
 ** 
 ** CMS Rev 1.2      21-Jun-2013    EMANOJ1
 ** Updated to handle a case where we add a new high priority screen to an 
 ** existing active screens, and in this case we only need to draw the newly
 ** added high priority screen alone. Because the reset of the contents are
 ** already available in frame buffer.
 **
 ** CMS Rev 1.1      20-Jun-2013    EMANOJ1
 ** Updated to add element visibility check also in to DAR process to speed up
 ** rendering by removal of invisible elements from rendering.
 **
 ** CMS Rev 1.0      09-May-2013    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
