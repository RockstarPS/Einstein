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
 ** Name:           hmi_gfx_mgr02_imxrt.c
 **
 ** Description:    Building Graphics element using IMXRT PXP driver API
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#define HMI_GFX_MGR02_IMXRT_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
**                          INCLUDE FILES
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

#if defined(GFX_MGR02_IMXRT)
#include "hmi_gfx_mgr02_imxrt.h"
#include "hmi_gfx_mgr02_context.h"
#ifdef GFX02_DEBUG_INFO
#include "fsl_debug_console.h"
#endif
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_amber_iris.h"
#include "hmi_gfx_mgr02_imxrt_lcdif.h"

#include "hmi_gfx_mgr02_imxrt_lcdif.h"
#include "panel_definition_imxrt.h"

#ifdef  __cplusplus
extern "C" { tk, 7''
#endif

/*============================================================================
**                              MACRO DEFINITIONS
**==========================================================================*/

#define IMXRT_DISP_LAYERS 8
#define GFX_MGR02_NUM_IMXRT_LAYERS 8

#define GFX_MGR02_IMXRT_WIN_DIRTY           ((UINT8)0x00)		/*If the window attributes changed*/
#define GFX_MGR02_IMXRT_WIN_UPDATED         ((UINT8)0x01)		/*If the window atrributes are updated and not committed to display.*/
#define GFX_MGR02_IMXRT_WIN_COMMITED        ((UINT8)0x02)		/*After commiting the window for display.*/

#define GFX_MGR02_ELEMENT_VISIBLE           ((UINT32)2)
#define GFX_MGR02_ELEMENT_INVISIBLE         ((UINT32)1)
#define GFX_MGR02_ELEMENT_INVALID           ((UINT32)0)

/*============================================================================
**                              TYPE DEFINITIONS
**==========================================================================*/

typedef enum
{
    GFX_MGR02_DRIVER_FREE = 0,
    GFX_MGR02_DRIVER_BUSY_IRIS_ENGINE  = 1,
    GFX_MGR02_DRIVER_BUSY_WINDOW_COMMIT= 2
}GFX_MGR02_DRIVER_BUSY_STATUS_T;

/*
** Datatype used to specify window creation parameters.
*/

typedef struct {
    GFX_MGR02_WINDOW_DATA_T window_data[GFX_MGR02_NUM_IMXRT_LAYERS]; /*Windows associated with Display*/
    UINT32 bg_colour; /*Display BG Colour*/
    UINT8 num_of_visible_elements; /*Number of active elements in the Display. */
    UINT8 num_of_planes_used; /*Number of planes used. This is needed to restrict planes per Disp controller.*/
} GFX_MGR02_DISPLAY_DATA_T;

/*============================================================================
**                          FUNCTION DECLARATIONS
**==========================================================================*/

static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,		UINT32 p_layer_index);
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers_cp_child(	GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP, UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id,UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index);
#if (GFX_MGR02_NUM_OF_SWDGS > 0)
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area);
#endif
#if (GFX_MGR02_NUM_OF_FILLS > 0)
static void hmi_gfx_mgr02_get_tile_fill_layer_area(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area);
#endif
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(	GFX_MGR02_ELEMENT_AREA const *p_area, UINT32 p_num_elements,GFX_MGR02_WINDOW_DATA_T *p_window_SP);
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
static UINT8 hmi_gfx_mgr02_is_image_transparent(UINT8 fl_format_U8);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0)
static UINT8 hmi_gfx_mgr02_is_widget_transparent(UINT8 fl_format_U8);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
static void hmi_gfx_mgr02_set_blendmode(GFX_MGR02_WINDOW_DATA_T const *p_wind,	UINT32 p_layer_index, lcdifv2_pixel_format_t pix_format);
#endif

/*============================================================================
**                          MEMORY ALLOCATION
**==========================================================================*/

const UINT8 lc_imxrt_num_planes_u8a[GFX_MGR02_NUM_LAYERS] = { GFX_MGR02_NUM_DISP0_PLANES};

#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
static GFX_MGR02_IMAGE_DEF_T l_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif

static volatile UINT8 l_gfx_mgr_shutdown_status;
static GFX_MGR02_ANIM_DATA_T *l_layer_anim_data_SP;
static UINT8 l_cur_num_of_elements[GFX_MGR02_NUM_LAYERS];
static UINT8 l_cur_free_layer;

#ifdef GFX02_DEBUG_INFO
static UINT32                  l_tot_num_of_elements;
static UINT32                  l_debug_vram_usage;
#endif

static GFX_MGR02_DISPLAY_DATA_T l_disp_comp[GFX_MGR02_NUM_LAYERS];
static UINT8 l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) 0;
static UINT32 l_content_ready_ondisplay = (UINT32) 0;


#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_is_emergency_shutdown_req_active
** Visibility:       Global
** Description:      Returns the shutdown mode type.
** Invocation:       By
** Inputs/Outputs:   l_gfx_mgr_shutdown_status
** Critical Section: None.
** Created:          05-Sep-2014
** Updated:          05-Sep-2014
**==========================================================================*/
UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
  return (l_gfx_mgr_shutdown_status);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_initialize
 ** Visibility:       Global
 ** Description:      This function for rendering the window
 **
 ** Invocation:
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
s_gx_flocal hmi_gfx_mgr02_imxrt_initialize(void)
{

    UINT8 fl_index_u8=(UINT8)0u;
    UINT8 fl_disp_index_u8=(UINT8)0u;
    GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP;
    UINT8   fl_no_planes_u8=(UINT8)6;
    
    hmi_gfx_mgr02_imxrt_lcdif_display_initialize();
    
    #ifdef GFX_MGR02_USE_EXT_MEMORY_MANAGER
    (void)hmi_gfx_mgr02_imxrt_mem_mgmt_init();
    #endif
    
#if GFX_MGR02_NUM_LAYERS>1 
    for (fl_disp_index_u8 = (UINT8)0; fl_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_disp_index_u8++)
#else  
    fl_disp_index_u8 = (UINT8)0;
#endif     
    {
       l_content_ready_ondisplay =(UINT32)0;
       l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_NORMAL;
       l_layer_anim_data_SP      = hmi_gfx_mgr02_layout_get_anim_data();
    
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
   (void)memcpy((void *)&l_runtime_wdg_image_layer_def_S[0],
          (const void *)&lc_runtime_wdg_image_layer_def_S[0],
          sizeof(l_runtime_wdg_image_layer_def_S));
#endif

       fl_win_data_SP = &l_disp_comp[fl_disp_index_u8].window_data[0];
       while(fl_index_u8<(UINT8)GFX_MGR02_NUM_IMXRT_LAYERS)
       {
           fl_win_data_SP->next_elem_sp = NULL;
           fl_win_data_SP->curr_elem_sp = NULL;
           fl_win_data_SP->root_elem_sp = NULL;
           fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
           fl_win_data_SP->win_colour = 0UL;
           fl_win_data_SP->win = 0u;
           fl_index_u8++;
           if (fl_index_u8 < (UINT8)(GFX_MGR02_NUM_IMXRT_LAYERS))
           {
                fl_win_data_SP++;
           }

        }
        fl_win_data_SP = &l_disp_comp[fl_disp_index_u8].window_data[0];
        for(fl_index_u8=(UINT8)0;fl_index_u8< lc_imxrt_num_planes_u8a[fl_disp_index_u8];fl_index_u8++)
        {
            fl_win_data_SP->win_prop.topLeftX = (UINT32)0;
            fl_win_data_SP->win_prop.topLeftY = (UINT32)0;
            fl_win_data_SP->win_prop.width    = DEMO_PANEL_WIDTH;
            fl_win_data_SP->win_prop.height   = DEMO_PANEL_HEIGHT;
            fl_win_data_SP->layerId  = (fl_no_planes_u8-0x01u);
            fl_win_data_SP++;
            fl_no_planes_u8--;
        }
    }
    return((s_gx_flocal)TRUE);
}




/****************************************************************************
 Function Name        : hmi_gfx_mgr02_build_screen
 Description          : Builds the screens that are active.
 Invocation           : Invoked by manager
 Parameters           : p_layer_ID_U8
 Return Value         : None
 Critical Section     : None
 External Interfaces  : None
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 ******************************************************************************/
void hmi_gfx_mgr02_imxrt_build_screen(UINT32 p_layer_ID_U32) {
    if (p_layer_ID_U32 < (UINT32) GFX_MGR02_NUM_LAYERS) {
        hmi_gfx_mgr02_manage_layers(p_layer_ID_U32);
        hmi_gfx_mgr02_render_display(p_layer_ID_U32);
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers
 ** Visibility:       static
 ** Description:      This function copies all elements in currently active
 **                   screens to next_elem_sp
 **                   Each element in list is then validated to see if they
 **                   fully or partly visible.
 **                   Partly or fully visible elements index
 **                   Total number of visible layers are restricted to the
 **                   number of DCU layers.
 **                   Refer to 02_design\layer_allocation.doc
 ** Invocation:       Invoked by hmi_gfx_mgr02_build_screen() to determine the
 **                   visible elements to be built.
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index) 
{
    UINT32 fl_max_priority;
    GFX_MGR02_SCREEN_ID_T const *fl_cur_screen;
    UINT32 fl_cur_screen_id;

    if (p_layer_index < (UINT32) GFX_MGR02_NUM_LAYERS) 
    {
        fl_max_priority = lc_layer_def_S[p_layer_index].nb_priority;
        fl_cur_screen = lc_layer_def_S[p_layer_index].prio_stack;
        l_disp_comp[p_layer_index].num_of_visible_elements = (UINT8) 0;
        l_disp_comp[p_layer_index].num_of_planes_used = (UINT8) 0;
        l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) 0;
#if GFX_MGR02_NUM_LAYERS >1
       if (p_layer_index > 0)
       {
         l_cur_free_layer = (IMXRT_DISP_LAYERS - lc_imxrt_num_planes_u8a[0]);
       }
       else
       #endif
        {
            l_cur_free_layer = IMXRT_DISP_LAYERS;
        }

        while (fl_max_priority > 0UL) 
        {
            fl_max_priority--;
            if (fl_max_priority < (UINT32)GFX_MGR02_NUM_PRIORITY)
            {
            fl_cur_screen_id = fl_cur_screen[fl_max_priority];
            if (fl_cur_screen_id < (UINT32) GFX_MGR02_NUM_OF_SCREENS) 
            {
                hmi_gfx_mgr02_manage_layers_cp_childrens(fl_cur_screen_id,p_layer_index);
            }
        }
        }
#if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0
       hmi_gfx_mgr02_manage_widget_memory();
#endif
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_childrens
 ** Visibility:       static
 ** Description:      This function copies the visible elements of passed screen
 **                   to render list
 ** Invocation:       Invoked by
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id,UINT32 p_layer_index)
{
    GFX_MGR02_ELEM_LIST_T const *fl_elem_list_SP;
    UINT32 fl_num_of_elem;
    GFX_MGR02_ANIM_DATA_T const *fl_anim_prop_SP =	hmi_gfx_mgr02_layout_get_anim_data();

    if ((p_screen_id < (UINT32)GFX_MGR02_NUM_OF_SCREENS) && (p_layer_index < GFX_MGR02_NUM_LAYERS))
    {
        GFX_MGR02_SCREEN_DEF_T const *fl_screen_def_SP = &lc_screen_def_S[p_screen_id];	
    (void) hmi_gfx_mgr02_context_begin_update(p_layer_index,&lc_layer_def_S[p_layer_index], FALSE);
    hmi_gfx_mgr02_context_reset_state();
    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_anim_prop_SP->layer_alpha[p_layer_index]);
    hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const*) &fl_anim_prop_SP->layer_loc[p_layer_index]);

#if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
    if (fl_screen_def_SP->anim_index < (UINT8) (GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)) 
    {
        hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_anim_prop_SP->group_alpha[fl_screen_def_SP->anim_index]);
        hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const*) &fl_anim_prop_SP->group_loc[fl_screen_def_SP->anim_index]);
    }
#endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */

    fl_num_of_elem = fl_screen_def_SP->num_child_elements;
    if (fl_num_of_elem > (UINT32) 0) 
    {
        fl_elem_list_SP = &fl_screen_def_SP->child[fl_num_of_elem - 0x01u];
        while (fl_num_of_elem > (UINT32) 0) 
        {
            fl_num_of_elem--;
            l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) 0;
            
            hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP,p_layer_index);
            if (fl_num_of_elem != (UINT32) 0) 
            {
                fl_elem_list_SP = &fl_elem_list_SP[-1];
            }
        }
    }
}
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_child
 ** Visibility:       static
 ** Description:      This function copy the passed child element after verifying
 **                   that it is visible
 ** Invocation:       Invoked by
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static void hmi_gfx_mgr02_manage_layers_cp_child(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP, UINT32 p_layer_index) 
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    GFX_MGR02_ELEM_LIST_T const *fl_elem_list_SP = p_elem_list_SP;
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0)||(GFX_MGR02_NUM_OF_SWDGS > 0)
    UINT16 fl_base_id = fl_elem_list_SP->base_id;
#endif
    UINT8 fl_cur_layer_index;
    GFX_MGR02_CONTEXT_STATE_T fl_cur_context_S;
    GFX_MGR02_ELEMENT_AREA fl_elem_area = { 0, 0, 0, 0, GFX_MGR02_OPEQUE, 255 };
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    GFX_MGR02_ANIM_DATA_T const *fl_anim_prop_SP = 	hmi_gfx_mgr02_layout_get_anim_data();
#endif
    GFX_MGR02_CONTEXT_T const *fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
    UINT32 fl_element_valid = FALSE;

    hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

    if (p_layer_index < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        switch (fl_obj_type) 
        {
#if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0)
            case GFX_MGR02_TYPE_DWIDGET:
            case GFX_MGR02_TYPE_DIMAGE:
            {
            #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
                if((fl_obj_id < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS) && (GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_list_SP->obj_id)))
                {
                   hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_anim_prop_SP->group_loc[fl_obj_id]);
                   hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_anim_prop_SP->group_alpha[fl_obj_id]);
                }
            #endif
                if(l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8)0)
                {
                 l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)fl_elem_list_SP->base_id, fl_elem_list_SP->obj_id);
                }
                if(fl_obj_type == GFX_MGR02_TYPE_DWIDGET)
                {
                #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
                    fl_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_swidget(fl_elem_list_SP);
                #endif
                }
                else
                {
                #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
                    fl_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_simage(fl_elem_list_SP);
                #endif
                }
                if(fl_elem_list_SP != GFX_MGR02_NULL_PTR)
                {
                    hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP, p_layer_index);
                }
                fl_element_valid = FALSE;
            }
            break;
    #endif /* #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0) */
#if GFX_MGR02_NUM_OF_SWDGS > 0
            case GFX_MGR02_TYPE_SWIDGET: 
            {
                if (fl_base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS) 
                {
                    GFX_MGR02_IMAGE_DEF_T const *fl_image_desc_SP;
                    GFX_MGR02_WIDGET_DEF_T const *fl_widget_desc_SP = &lc_swidget_layer_def_S[fl_base_id];
                    fl_vaof_index = hmi_gfx_mgr02_get_widget_layer_area(fl_elem_list_SP,	&fl_elem_area);
                    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                    GFX_MGR02_VISIBLE_AREA fl_clipped_area;
                    #endif
                    fl_elem_area.alpha = fl_context_SP->state.alpha;
                    fl_elem_area.sx = fl_context_SP->state.loc.x;
                    fl_elem_area.sy = fl_context_SP->state.loc.y;
                    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                    fl_clipped_area.sx = fl_elem_area.sx;
                    fl_clipped_area.sy = fl_elem_area.sy;
                    fl_clipped_area.ex = (fl_elem_area.ex+fl_elem_area.sx);
                    fl_clipped_area.ey = (fl_elem_area.ey+fl_elem_area.sy);

                    if(hmi_gfx_mgr02_context_validate_clip(&fl_clipped_area, &fl_context_SP->state.clip) != FALSE)
                    {
                        fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                    }
                    else
                    #endif
                    {
                         hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index);
                         #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0
                         if((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT) || (fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_VGLITE))
                         {
                            hmi_gfx_mgr02_context_widget_set_active(fl_widget_desc_SP->client_id);
                         }
                         #endif
                         
                         #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
                         if(fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE)
                         {
                            if (fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
                            {
                                fl_image_desc_SP = &lc_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
                                if(hmi_gfx_mgr02_is_widget_transparent(fl_image_desc_SP->format) == TRUE)
                                {
                                     fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                                }
                                else
                                {
                                     fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                                }
                            }
                         }
                         else
                         #endif
                         {
                             #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
                             if (fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
                             {
                                 fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
                                 if(hmi_gfx_mgr02_is_widget_transparent(fl_image_desc_SP->format) == TRUE)
                                 {
                                     fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                                 }
                                 else
                                 {
                                     fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                                 }
                             }
                             #endif
                         }
                    }
                    if ((fl_elem_area.ex > (SINT16) 0)	&& (fl_elem_area.ey > (SINT16) 0))
                    {
                        fl_element_valid = TRUE;
                    }
                    if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 0)
                    {			
                        l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_list_SP, TRUE);
                    }
                }
            }
            break;
#endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
            case GFX_MGR02_TYPE_SIMAGE: 
            {
                if (fl_base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
                {
                    GFX_MGR02_IMAGE_DEF_T const *fl_image_desc_SP =	&lc_image_layer_def_S[fl_base_id];
                    fl_vaof_index = hmi_gfx_mgr02_get_image_layer_area(fl_elem_list_SP,&fl_elem_area);
                    fl_elem_area.alpha = fl_context_SP->state.alpha;
                    fl_elem_area.sx = fl_context_SP->state.loc.x;
                    fl_elem_area.sy = fl_context_SP->state.loc.y;
                    hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index,TRUE, p_layer_index);

                    if (hmi_gfx_mgr02_is_image_transparent(fl_image_desc_SP->format) == TRUE) 
                    {
                        fl_elem_area.is_transparent = (UINT8) GFX_MGR02_TRANSPARENT;
                    } 
                    else 
                    {
                        fl_elem_area.is_transparent = (UINT8) GFX_MGR02_OPEQUE;
                    }
                    if ((fl_elem_area.ex > (SINT16) 0) && (fl_elem_area.ey > (SINT16) 0))
                    {
                        fl_element_valid = TRUE;
                    }
                    if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 0)
                    {
                        l_gfx_mgr02_imxrt_element_dirty_u8 =(UINT8) hmi_gfx_mgr02_layout_is_element_changed((UINT32) fl_elem_list_SP->base_id,fl_elem_list_SP->obj_id);
                    }
                }
            }
            break;
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
            case GFX_MGR02_TYPE_STEXT:
            case GFX_MGR02_TYPE_DTEXT: 
            {
                fl_elem_area.alpha = fl_context_SP->state.alpha;
                fl_elem_area.sx = fl_context_SP->state.loc.x;
                fl_elem_area.sy = fl_context_SP->state.loc.y;
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area,	GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
                /* for text always considered as transparent */
                fl_elem_area.is_transparent = (UINT8) GFX_MGR02_TRANSPARENT;
                fl_element_valid = TRUE;
                if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 0) 
                {
                    l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) hmi_gfx_mgr02_layout_is_element_changed((UINT32) fl_elem_list_SP->base_id,fl_elem_list_SP->obj_id);
                }
            }
            break;
#endif
#if (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TILES > 0)
            case GFX_MGR02_TYPE_TILE:
            case GFX_MGR02_TYPE_FILL: 
            {
                hmi_gfx_mgr02_get_tile_fill_layer_area(fl_elem_list_SP, &fl_elem_area);
                fl_elem_area.alpha = fl_context_SP->state.alpha;
                fl_elem_area.sx = fl_context_SP->state.loc.x;
                fl_elem_area.sy = fl_context_SP->state.loc.y;
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area,
                GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
                /* always considered as transparent */
                fl_elem_area.is_transparent = (UINT8) GFX_MGR02_TRANSPARENT;
                fl_element_valid = TRUE;
                if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 0)
                {
                    l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) hmi_gfx_mgr02_layout_is_element_changed((UINT32) fl_elem_list_SP->base_id,fl_elem_list_SP->obj_id);
                }
            }
            break;
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
            case GFX_MGR02_TYPE_USER_LAYER: 
            {
                if (fl_elem_list_SP->base_id < (UINT32)GFX_MGR02_NUM_USER_LAYERS)
                {
        /* Get the element area of the user_image element */
                    GFX_MGR02_IMAGE_DEF_T *fl_image_def_SP = &l_layer_anim_data_SP->user_image_layer[fl_elem_list_SP->base_id];
                    (void) hmi_gfx_mgr02_load_user_layer_def_info(fl_elem_list_SP->base_id, fl_image_def_SP);
                    if ((fl_image_def_SP->pixel_data != GFX_MGR02_NULL_PTR)
                    && (fl_image_def_SP->height != (UINT16) 0)
                    && (fl_image_def_SP->width != (UINT16) 0)) 
                    {
                        (void) hmi_gfx_mgr02_get_image_layer_area(fl_elem_list_SP, &fl_elem_area);
                        fl_elem_area.alpha = fl_context_SP->state.alpha;
                        fl_elem_area.sx = fl_context_SP->state.loc.x;
                        fl_elem_area.sy = fl_context_SP->state.loc.y;
                        hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
                        
                        if (hmi_gfx_mgr02_is_image_transparent(fl_image_def_SP->format) == TRUE) 
                        {
                          fl_elem_area.is_transparent = (UINT8) GFX_MGR02_TRANSPARENT;
                        } 
                        else 
                        {
                          fl_elem_area.is_transparent = (UINT8) GFX_MGR02_OPEQUE;
                        }
                        
                        fl_element_valid = TRUE;
                    }
                    
                    if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 0) 
                    {
                        l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) hmi_gfx_mgr02_layout_is_element_changed((UINT32) fl_elem_list_SP->base_id,fl_elem_list_SP->obj_id);
                    }
                }
            }
            break;
#endif
            default: 
            {
                fl_element_valid = FALSE;
            }
            break;
        }

        fl_cur_layer_index = l_disp_comp[p_layer_index].num_of_visible_elements;
        if ((fl_context_SP->state.invisible == (UINT8) 0)
                && (fl_element_valid == TRUE) && (fl_cur_layer_index < (UINT8)GFX_MGR02_NUM_IMXRT_LAYERS)) 
        {
            /*
             ** This element is with in displayable area and is not transparent.
             ** This element can be added to the render list and validated for
             ** visibility.
             */
            GFX_MGR02_WINDOW_DATA_T *fl_win_data_SP =	&l_disp_comp[p_layer_index].window_data[fl_cur_layer_index];
            {
                if (hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_elem_area,
                l_disp_comp[p_layer_index].num_of_visible_elements,
                &l_disp_comp[p_layer_index].window_data[0]) == GFX_MGR02_ELEMENT_VISIBLE) 
                {
                    /*
                     ** The below element win_prop area includes vaoa index i.e. opaque area to be considered
                     ** fl_elem_area_SP-> is the actual position of the element
                     */
                    if (fl_win_data_SP->win_prop.topLeftX != (UINT32) fl_elem_area.sx) 
                    {
                        fl_win_data_SP->win_prop.topLeftX = (UINT32) fl_elem_area.sx;
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->win_prop.topLeftY != (UINT32) fl_elem_area.sy) 
                    {
                        fl_win_data_SP->win_prop.topLeftY = (UINT32) fl_elem_area.sy;
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->win_prop.width != ((UINT32) fl_elem_area.ex - (UINT32) fl_elem_area.sx)) 
                    {
                        fl_win_data_SP->win_prop.width = ((UINT32) fl_elem_area.ex - (UINT32) fl_elem_area.sx);
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->win_prop.height != ((UINT32) fl_elem_area.ey - (UINT32) fl_elem_area.sy)) 
                    {
                        fl_win_data_SP->win_prop.height = ((UINT32) fl_elem_area.ey - (UINT32) fl_elem_area.sy);
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->alpha != fl_elem_area.alpha) 
                    {
                        fl_win_data_SP->alpha = fl_elem_area.alpha;
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->clip.sx != fl_context_SP->state.clip.sx) 
                    {
                        fl_win_data_SP->clip.sx = fl_context_SP->state.clip.sx;
                    }
                    
                    if (fl_win_data_SP->clip.sy != fl_context_SP->state.clip.sy) 
                    {
                        fl_win_data_SP->clip.sy = fl_context_SP->state.clip.sy;
                    }
                    
                    if (fl_win_data_SP->clip.ex != fl_context_SP->state.clip.ex) 
                    {
                        fl_win_data_SP->clip.ex = fl_context_SP->state.clip.ex;
                    }
                    
                    if (fl_win_data_SP->clip.ey != fl_context_SP->state.clip.ey) 
                    {
                        fl_win_data_SP->clip.ey = fl_context_SP->state.clip.ey;
                    }
                    
                    if (fl_win_data_SP->curr_elem_sp  != fl_elem_list_SP)
                    {
                       fl_win_data_SP->curr_elem_sp      = fl_elem_list_SP;
                       fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    }
                    
                    if (fl_win_data_SP->next_elem_sp  != fl_elem_list_SP)
                    {
                       fl_win_data_SP->next_elem_sp      = fl_elem_list_SP;
                    }
                    
                    if (l_gfx_mgr02_imxrt_element_dirty_u8 == (UINT8) 1) 
                    {
                        fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                        l_gfx_mgr02_imxrt_element_dirty_u8 = (UINT8) 0;
                    }

                    if((l_cur_free_layer <= 6u)&&
                        (l_disp_comp[p_layer_index].num_of_planes_used <= lc_imxrt_num_planes_u8a[p_layer_index]))
                    {
                        l_disp_comp[p_layer_index].num_of_planes_used++;
                    }
                    fl_win_data_SP->posx = (SINT32) (fl_context_SP->state.loc.x);
                    fl_win_data_SP->posy = (SINT32) (fl_context_SP->state.loc.y);

                    if (fl_elem_area.is_transparent == (UINT8) GFX_MGR02_OPEQUE) 
                    {
                        fl_win_data_SP->see_through = 0;
                    }
                    else 
                    {
                        fl_win_data_SP->see_through = 1;
                    }
                        
                    l_cur_free_layer--;
                    fl_win_data_SP->layerId = l_cur_free_layer;

                    if (l_disp_comp[p_layer_index].num_of_visible_elements < (UINT8) GFX_MGR02_NUM_IMXRT_LAYERS)
                    {
                        l_disp_comp[p_layer_index].num_of_visible_elements++;		
                    }
                }
            }
        }
        hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_display
 ** Visibility:       static
 ** Description:      This function copies the visible elements of passed screen
 **                   to render list
 ** Invocation:       Invoked by
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index) 
{
    UINT8 fl_next_element = 0u;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    UINT8 fl_cur_window_U8;
    UINT8 fl_disp_commit_needed_u8 = (UINT8) FALSE;
    GFX_MGR02_WINDOW_DATA_T *fl_win_data_SP;
    UINT8 fl_win_order_changed_u8 = (UINT8)FALSE;

    if (p_layer_index < GFX_MGR02_NUM_LAYERS)
    {
        if ((l_disp_comp[p_layer_index].num_of_visible_elements > (UINT8) 0 ) && (fl_shutdown_state != GFX_MGR02_SHUTDOWN_EMERGENCY))
        {
            /*
            Check whether the Window order got changed. If changed then render all the windows content freshly.
            */
            fl_next_element         = l_disp_comp[p_layer_index].num_of_visible_elements;
            if ((fl_next_element <= (UINT8)(GFX_MGR02_NUM_IMXRT_LAYERS)) && (fl_next_element > 0))
            {
                fl_win_data_SP          = &l_disp_comp[p_layer_index].window_data[fl_next_element - (UINT8)1];
                while(fl_next_element > (UINT8)0) 
                {
                    if(fl_win_data_SP->prevLayer != fl_win_data_SP->next_elem_sp)
                    {
                        fl_win_order_changed_u8 = (UINT8)TRUE;
                        break;
                    }
                    fl_next_element--;
                    fl_win_data_SP--;
                }
            }

            fl_next_element = l_disp_comp[p_layer_index].num_of_visible_elements;
            if(fl_win_order_changed_u8 != (UINT8)FALSE) 
            {
                while((fl_next_element > (UINT8)0) && (fl_next_element <= (UINT8)(GFX_MGR02_NUM_IMXRT_LAYERS)))
                {
                    fl_win_data_SP          = &l_disp_comp[p_layer_index].window_data[fl_next_element - (UINT8)1];
                    fl_win_data_SP->win     = 0;
                    fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    fl_next_element--;
                }
            }

            fl_next_element = l_disp_comp[p_layer_index].num_of_visible_elements;
            while((fl_next_element > (UINT8)0) && (fl_next_element <= (UINT8)(GFX_MGR02_NUM_IMXRT_LAYERS)))
            {
                fl_win_data_SP =  &l_disp_comp[p_layer_index].window_data[fl_next_element-(UINT8)1];
                hmi_gfx_mgr02_render_window(fl_win_data_SP,fl_win_data_SP->layerId);
                fl_win_data_SP->prevLayer = fl_win_data_SP->next_elem_sp;
                fl_next_element--;
            }
            
            /*
            ** Check Whether the Display Commit Needed or not?
            ** Commit the Display for the changes.
            */
            for (fl_cur_window_U8 = (UINT8) 0;	fl_cur_window_U8< l_disp_comp[p_layer_index].num_of_visible_elements;fl_cur_window_U8++)
            {
                if (l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts == GFX_MGR02_IMXRT_WIN_UPDATED)
                {
                    hmi_gfx_mgr02_imxrt_lcdif_TriggerShadowLoad(l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].layerId);
                    l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts = GFX_MGR02_IMXRT_WIN_COMMITED;
                }
            }
        
            fl_next_element = l_disp_comp[p_layer_index].num_of_visible_elements;
            if (fl_next_element < (UINT8)GFX_MGR02_NUM_IMXRT_LAYERS)
            {
                fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
                while(fl_next_element < (UINT8)GFX_MGR02_NUM_IMXRT_LAYERS)
                {
                    fl_win_data_SP->win         = 0;
                    fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                    if(fl_win_data_SP->layerId < (UINT8)GFX_MGR02_NUM_IMXRT_LAYERS)
                    {
                        hmi_gfx_mgr02_imxrt_lcdif_disable_layer(fl_win_data_SP->layerId);
                        fl_win_data_SP->layerId = (UINT8)GFX_MGR02_NUM_IMXRT_LAYERS;
                    }
                    fl_next_element++;
                    fl_win_data_SP++;
                }
            }
        
            l_content_ready_ondisplay = (UINT32) 2;
            l_cur_num_of_elements[p_layer_index] = l_disp_comp[p_layer_index].num_of_visible_elements;
        } 
        else 
        {
            /*Destroy the active windows if the number visible element is Zero.*/
            fl_next_element = (UINT8) 0;
            fl_win_data_SP = &l_disp_comp[p_layer_index].window_data[fl_next_element];		
            
            while (fl_next_element < (UINT8) l_cur_num_of_elements[p_layer_index]) 
            {
                fl_win_data_SP->win_prop.topLeftX = (UINT32) 0;
                fl_win_data_SP->win_prop.topLeftY = (UINT32) 0;
                fl_win_data_SP->win_prop.width = 0;
                fl_win_data_SP->win_prop.height = 0;
                fl_win_data_SP->posx = 0;
                fl_win_data_SP->posy = 0;
                fl_win_data_SP->alpha = 0;
                fl_win_data_SP->win_colour = 0;
                fl_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_DIRTY;
                fl_disp_commit_needed_u8 = (UINT8) TRUE;
                hmi_gfx_mgr02_imxrt_lcdif_disable_layer(fl_win_data_SP->layerId);
                fl_next_element++;
                fl_win_data_SP++;
            }
            if (fl_disp_commit_needed_u8 == (UINT8) TRUE) 
            {
                l_cur_num_of_elements[p_layer_index] = (UINT8) 0;
                l_content_ready_ondisplay = (UINT32) 1;
            }
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_window
 ** Visibility:       static
 ** Description:
 **
 ** Invocation:       Invoked by
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,
                                        UINT32 p_layer_index) 
{
    UINT32 fl_obj_type;
    UINT32 fl_obj_id;
    GFX_MGR02_ELEM_LIST_T const *fl_elem_list_SP = p_win_data_SP->next_elem_sp;
    UINT32 ret = FALSE;

    if ((fl_elem_list_SP != NULL)&& (p_win_data_SP->win_sts == GFX_MGR02_IMXRT_WIN_DIRTY)) 
    {

        fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
        fl_obj_id = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);

        p_win_data_SP->win_prop.topLeftX = (UINT32) p_win_data_SP->posx;
        p_win_data_SP->win_prop.topLeftY = (UINT32) p_win_data_SP->posy;

        switch (fl_obj_type) {
#if (GFX_MGR02_NUM_OF_SWDGS > 0)
        case GFX_MGR02_TYPE_SWIDGET: {
            hmi_gfx_mgr02_imxrt_build_widget(p_win_data_SP, fl_elem_list_SP,
                    p_layer_index);
        }
            break;
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
        case GFX_MGR02_TYPE_USER_LAYER: {
            hmi_gfx_mgr02_imxrt_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,
                    p_layer_index);
        }
            break;
#endif
#if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
        case GFX_MGR02_TYPE_SIMAGE: {
            hmi_gfx_mgr02_imxrt_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,
                    p_layer_index);
        }
            break;
#endif

        default: {
            /* Adding comment to fix MISRA c-2012 Rule 16.4 */
        }
            break;
        }
    }
    GFX_MGR02_UNUSED_VAR(ret);
}

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_imxrt_build_image
 ** Visibility:       static
 ** Description:      Builds/Updates image element
 ** Invocation:       By hmi_gfx_mgr02_render_window
 ** Inputs/Outputs:   GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
void hmi_gfx_mgr02_imxrt_build_image(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,
                                     UINT32 p_obj_id, 
                                     GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,
                                     UINT32 p_layer_index) 
{
    GFX_MGR02_IMAGE_DEF_T const *fl_image_desc_SP = GFX_MGR02_NULL_PTR;
    UINT32 fl_obj_type;
    void *fl_buff_ptr = GFX_MGR02_NULL_PTR;

    if (p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);

#if GFX_MGR02_NUM_USER_LAYERS > 0
        if ((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS))
        {
            fl_image_desc_SP =	&l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
        } 
        else
#endif
        {
#if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
            if (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {				
            fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
            }
#endif
        }

        if (fl_image_desc_SP != GFX_MGR02_NULL_PTR)
        {
            lcdifv2_pixel_format_t fl_pix_format;
            lcdifv2_buffer_config_t fbConfig;
            UINT32 fl_bpp = (UINT32) 0;
            
            hmi_gfx_mgr02_context_reset_state();
            if (fl_obj_type != GFX_MGR02_TYPE_3D_MDL) 
            {
                fl_buff_ptr = (void*) fl_image_desc_SP->pixel_data;
#if GFX_MGR02_NUM_OF_CLUTS > 0
                if(fl_image_desc_SP->clut < (UINT16)GFX_MGR02_NUM_OF_CLUTS)
                {
                    GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_image_desc_SP->clut];
                    void * fl_clut_p =(void *) fl_elem_clut_SP->CLUT;
                    (void)LCDIFV2_SetLut(DEMO_LCDIF, (UINT8)p_layer_index, (uint32_t *)fl_clut_p, fl_elem_clut_SP->CLUTsize, TRUE);
                }
#endif
            }
        
            fl_pix_format = hmi_gfx_mgr02_imxrt_lcdif_map_image_pix_format(fl_image_desc_SP->format);
            fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
            fbConfig.pixelFormat = fl_pix_format;
            fbConfig.strideBytes = ((UINT16)(p_win_data_SP->win_prop.width * fl_bpp)) >> 3U;
            LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, (UINT8)p_layer_index,&fbConfig);
            hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_layer_index,fl_pix_format);
            LCDIFV2_SetLayerSize(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->win_prop.width, (UINT16)p_win_data_SP->win_prop.height);
            LCDIFV2_SetLayerOffset(DEMO_LCDIF, (UINT8)p_layer_index,  (UINT16)p_win_data_SP->posx, (UINT16)p_win_data_SP->posy);
            hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_index,fl_buff_ptr);
            p_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_UPDATED;
            p_win_data_SP->win = 1;
        }
    }
    GFX_MGR02_UNUSED_VAR(p_obj_id);
}
#endif

#if (GFX_MGR02_NUM_OF_SWDGS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_imxrt_build_widget
 ** Visibility:       static
 ** Description:      Builds the widget element for the first time. Initializes
 **                   RAM and then copies all active elements.
 ** Invocation:       By hmi_gfx_mgr02_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
void hmi_gfx_mgr02_imxrt_build_widget(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,
                                      GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP, 
                                      UINT32 p_layer_index) 
{
    GFX_MGR02_WIDGET_DEF_T const *fl_widget_desc_SP;
    GFX_MGR02_IMAGE_DEF_T const *fl_image_desc_SP = GFX_MGR02_NULL_PTR;
    GFX_MGR02_CONTEXT_GB_T fl_build_elem_S = {0};

    UINT32 fl_clear_buffer = FALSE;
    UINT32 fl_clear_color = 0UL;
    UINT32 fl_element_change_status;
    lcdifv2_pixel_format_t fl_pix_format;
    UINT32 fl_obj_id;
    UINT8 fl_bpp = (UINT8)0;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    GFX_MGR02_VISIBLE_AREA fl_elem_clip_S;
    SINT32 fl_start_offset;
    UINT32 fl_buff_offset = 0UL;
#endif

    if (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
    {
        fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];

    #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS>0
        if(fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE)
        {
            if (fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
            {
                fl_image_desc_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
                fl_build_elem_S.area.width = fl_image_desc_SP->width;
                fl_build_elem_S.area.height = fl_image_desc_SP->height;
            }
        }
        else
    #endif
        {
        #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0 
            if (fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {
                fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
                fl_build_elem_S.area.width = fl_image_desc_SP->width;
                fl_build_elem_S.area.height = fl_image_desc_SP->height;
            }
        #endif
        }

        fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        fl_build_elem_S.fb_format = fl_widget_desc_SP->fb_format;
        fl_pix_format = hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format((UINT8)fl_build_elem_S.fb_format);  //test

        if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id)) 
        {
        #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            if (fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
            {
                if (fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE) 
                {
                    GFX_MGR02_WIDGET_DYN_PROPERTY const *fl_wdgt_anim_prop_SP =	&l_layer_anim_data_SP->widget_prop[fl_obj_id];
                    fl_build_elem_S.area.x = fl_wdgt_anim_prop_SP->coord.x;
                    fl_build_elem_S.area.y = fl_wdgt_anim_prop_SP->coord.y;
                    fl_clear_buffer = TRUE;
                    fl_clear_color = fl_widget_desc_SP->bg_fill_color;
                    p_win_data_SP->win_colour = fl_wdgt_anim_prop_SP->fg_color;
                }
                else 
                {
                    fl_build_elem_S.area.x = lc_widget_anim_property_S[fl_obj_id].coord.x;
                    fl_build_elem_S.area.y = lc_widget_anim_property_S[fl_obj_id].coord.y;
                    p_win_data_SP->win_colour =	lc_widget_anim_property_S[fl_obj_id].fg_color;
                }
            }
        #endif
        } 
        else 
        {
        #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
            if (fl_obj_id < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
            {
                fl_build_elem_S.area.x = lc_swdg_const_property_S[fl_obj_id].coord.x;
                fl_build_elem_S.area.y = lc_swdg_const_property_S[fl_obj_id].coord.y;
                p_win_data_SP->win_colour = lc_swdg_const_property_S[fl_obj_id].fg_color;
            }
        #endif
        }
        
        if (fl_image_desc_SP != GFX_MGR02_NULL_PTR)
        {
        #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            fl_elem_clip_S.sx = (SINT16) p_win_data_SP->win_prop.topLeftX;
            fl_elem_clip_S.sy = (SINT16) p_win_data_SP->win_prop.topLeftY;
            fl_elem_clip_S.ex = (SINT16) fl_build_elem_S.area.width;
            fl_elem_clip_S.ey = (SINT16) fl_build_elem_S.area.height;
            fl_elem_clip_S.ex += fl_elem_clip_S.sx;
            fl_elem_clip_S.ey += fl_elem_clip_S.sy;
            if (hmi_gfx_mgr02_context_validate_clip(&p_win_data_SP->clip,&fl_elem_clip_S) == FALSE) 
            {
                fl_start_offset = (p_win_data_SP->clip.sx - (SINT32) p_win_data_SP->win_prop.topLeftX);
                if ((fl_start_offset >= 0)&& (fl_start_offset < (SINT32) fl_image_desc_SP->width))
                {
                    fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
                    fl_buff_offset = ((fl_bpp * (UINT32) fl_start_offset) >> 3U);
                    fl_start_offset = (p_win_data_SP->clip.sy - (SINT32) p_win_data_SP->win_prop.topLeftY);
                    if ((fl_start_offset >= 0)&& (fl_start_offset < (SINT32) fl_image_desc_SP->height))
                    {
                        fl_buff_offset += ((UINT32) fl_start_offset	* ((fl_bpp * (UINT32)fl_image_desc_SP->width) >> 3U));
                        p_win_data_SP->win_prop.topLeftX =	(UINT32) p_win_data_SP->clip.sx;
                        p_win_data_SP->win_prop.topLeftY =	(UINT32) p_win_data_SP->clip.sy;
                        p_win_data_SP->win_prop.width = (UINT32) p_win_data_SP->clip.ex;
                        p_win_data_SP->win_prop.width -= (UINT32) p_win_data_SP->clip.sx;
                        p_win_data_SP->win_prop.height = (UINT32) p_win_data_SP->clip.ey;
                        p_win_data_SP->win_prop.height -= (UINT32) p_win_data_SP->clip.sy;
                    }
                }
            }
        #endif
            
        #if GFX_MGR02_NUM_OF_CLUTS > 0
            if(fl_image_desc_SP->clut < (UINT16)GFX_MGR02_NUM_OF_CLUTS)
            {
                GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_image_desc_SP->clut];
                void * fl_clut_p =(void *) fl_elem_clut_SP->CLUT;
                (void)LCDIFV2_SetLut(DEMO_LCDIF, (UINT8)p_layer_index, (uint32_t *)fl_clut_p, fl_elem_clut_SP->CLUTsize, TRUE);
            }
        #endif
            
            if ((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT) || (fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_VGLITE))
            {
                /*
                ** no need to build again if the content is active / nothing changed
                */
                fl_element_change_status =	hmi_gfx_mgr02_layout_is_element_childrens_changed(p_elem_list_SP, TRUE);
                if ((fl_element_change_status != FALSE)	|| (p_win_data_SP->win_sts == GFX_MGR02_IMXRT_WIN_DIRTY)) 
                {
                    UINT32 fl_updated;
                    fl_build_elem_S.client_id = (UINT32) fl_widget_desc_SP->client_id;
                    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                    fl_build_elem_S.fb_group_id   = fl_widget_desc_SP->fb_group_id;
                    #endif
                    #if defined(GFX_MGR02_VGLITE)
                    if (fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_VGLITE)
                    {
                        fl_build_elem_S.fb_target = GFX_MGR02_TARGET_VGLITE;
                    }
                    else
                    #endif    
                    {
                        fl_build_elem_S.fb_target = GFX_MGR02_TARGET_IMXRT_PXP;
                    }
                    fl_build_elem_S.clr_buffer = fl_clear_buffer;
                    fl_build_elem_S.clr_color = fl_clear_color;
                    fl_build_elem_S.render_buffer = NULL;
                    /* dirty area check true for mask widget and normal widget */
                    fl_build_elem_S.dirty_area = TRUE;
                    fl_updated = hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, p_elem_list_SP);
                    if ((fl_updated != FALSE)|| (p_win_data_SP->render_buffer != fl_build_elem_S.render_buffer)) 
                    {
                        lcdifv2_buffer_config_t fbConfig;
                    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                        if ((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)
                                || (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height)) 
                        {
                            fl_buff_offset += (UINT32) fl_build_elem_S.render_buffer;
                            fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
                            fbConfig.pixelFormat = fl_pix_format;
                            fbConfig.strideBytes = ((UINT16)(p_win_data_SP->win_prop.width * fl_bpp)) >> 3U;
                            LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, (UINT8)p_layer_index,&fbConfig);
                            hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_layer_index,fl_pix_format);
                            LCDIFV2_SetLayerSize(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->win_prop.width, (UINT16)p_win_data_SP->win_prop.height);
                            LCDIFV2_SetLayerOffset(DEMO_LCDIF, (UINT8)p_layer_index,  (UINT16)p_win_data_SP->posx, (UINT16)p_win_data_SP->posy);
                            hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_index,(void *)fl_buff_offset);
                        }
                        else
                    #endif
                        {
                            fl_pix_format = hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format((UINT8)fl_build_elem_S.fb_format);  //test
                            fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
                            fbConfig.pixelFormat = fl_pix_format;
                            fbConfig.strideBytes = ((UINT16)(p_win_data_SP->win_prop.width * fl_bpp)) >> 3U;
                            LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, (UINT8)p_layer_index,&fbConfig);
                            hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_layer_index,fl_pix_format);
                            LCDIFV2_SetLayerSize(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->win_prop.width, (UINT16)p_win_data_SP->win_prop.height);
                            LCDIFV2_SetLayerOffset(DEMO_LCDIF, (UINT8)p_layer_index,  (UINT16)p_win_data_SP->posx, (UINT16)p_win_data_SP->posy);
                            hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_index,fl_build_elem_S.render_buffer);
                        }
                        p_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_UPDATED;
                        p_win_data_SP->win = 1;
                    }
                    else 
                    {
                        GFX_MGR02_UNUSED_VAR(fl_pix_format);
                    }
                } 
                else if ((UINT8) hmi_gfx_mgr02_layout_is_element_changed((UINT32) p_elem_list_SP->base_id,p_elem_list_SP->obj_id) != FALSE) 
                {
                
                    lcdifv2_buffer_config_t fbConfig;
                #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                    if ((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)
                        || (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height)) 
                    {
                        fl_buff_offset += (UINT32) p_win_data_SP->render_buffer;
                        fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
                        fbConfig.pixelFormat = fl_pix_format;
                        fbConfig.strideBytes = ((UINT16)(p_win_data_SP->win_prop.width * fl_bpp)) >> 3U;
                        LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, (UINT8)p_layer_index,&fbConfig);
                        hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_layer_index,fl_pix_format);
                        LCDIFV2_SetLayerSize(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->win_prop.width, (UINT16)p_win_data_SP->win_prop.height);
                        LCDIFV2_SetLayerOffset(DEMO_LCDIF, (UINT8)p_layer_index,  (UINT16)p_win_data_SP->posx, (UINT16)p_win_data_SP->posy);
                        hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_index,(void *)fl_buff_offset);
                    } 
                    else
                #endif
                    {
                        fl_pix_format = hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format((UINT8)fl_build_elem_S.fb_format);
                        fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
                        fbConfig.pixelFormat = fl_pix_format;
                        fbConfig.strideBytes = ((UINT16)(p_win_data_SP->win_prop.width * fl_bpp)) >> 3U;
                        LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, (UINT8)p_layer_index,&fbConfig);
                        hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_layer_index,fl_pix_format);
                        LCDIFV2_SetLayerSize(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->win_prop.width, (UINT16)p_win_data_SP->win_prop.height);
                        LCDIFV2_SetLayerOffset(DEMO_LCDIF, (UINT8)p_layer_index, (UINT16)p_win_data_SP->posx, (UINT16)p_win_data_SP->posy);
                        hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_index,fl_build_elem_S.render_buffer);
                    }
                    p_win_data_SP->win_sts = GFX_MGR02_IMXRT_WIN_UPDATED;
                    p_win_data_SP->win = 1;
                } 
                else 
                {
                    /* Adding comment to fix MISRA c-2012 Rule 15.7 */
                }
            }
        }
    }
}
#endif /* GFX_MGR02_NUM_OF_SWDGS > 0 */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_imxrt_get_disp_content_status
 ** Visibility:       Global
 ** Description:      Interface to get display content status .
 **
 ** Invocation:       By hmi_gfx_mgr02_layout.c
 ** Inputs/Outputs:   l_content_ready_ondisplay
 **                   0 -> default.
 **                   1 -> Display active with background colour set.
 **                   2 -> Display active with active layer alongwith
 **                        background colour set.
 ** Critical Section: None.
 **==========================================================================*/

UINT32 hmi_gfx_mgr02_imxrt_get_disp_content_status(void) {
    return (l_content_ready_ondisplay);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_set_disp_bgcolor
 ** Visibility:       Global
 ** Description:      This function is used to set the BG colour of the Display.
 **
 ** Invocation:       By Application
 ** Inputs/Outputs:   Tndex of the Display , BG colour
 ** Critical Section: None.
 ** Created:          08-Dec-2015 by SSIGAMAN
 ** Updated:          08-Dec-2015 by SSIGAMAN
 **==========================================================================*/

void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8,UINT32 p_bg_color_u32) 
{
    if (p_disp_index_u8 < (UINT8) GFX_MGR02_NUM_LAYERS)
    {
        l_disp_comp[p_disp_index_u8].bg_colour = p_bg_color_u32;
    }
}

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_image_transparent
 ** Visibility:       static
 ** Description:
 ** Invocation:
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static UINT8 hmi_gfx_mgr02_is_image_transparent(UINT8 fl_format_U8) 
{
    UINT8 fl_image_transparent_U8;

    switch (fl_format_U8) 
    {
        case kPXP_AsPixelFormatARGB8888:
        case kPXP_AsPixelFormatARGB1555:
        case kPXP_AsPixelFormatARGB4444: 
        {
            fl_image_transparent_U8 = (UINT8)TRUE;
        }
            break;
        default: 
        {
            fl_image_transparent_U8 = (UINT8)FALSE;
        }
            break;
    }
    return fl_image_transparent_U8;
}
#endif

#if (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0) || (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_widget_transparent
 ** Visibility:       static
 ** Description:
 ** Invocation:
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static UINT8 hmi_gfx_mgr02_is_widget_transparent(UINT8 fl_format_U8) 
{
    UINT8 fl_image_transparent_U8;
    switch (fl_format_U8) 
    {
    
        case GFX_MGR02_PIX_FORMAT_ARGB8888:
        case GFX_MGR02_PIX_FORMAT_ARGB1555:
        case GFX_MGR02_PIX_FORMAT_ARGB4444:
        case GFX_MGR02_PIX_FORMAT_8BPP:
        case GFX_MGR02_PIX_FORMAT_4BPP:
        case GFX_MGR02_PIX_FORMAT_2BPP:
        {
            fl_image_transparent_U8 = (UINT8)TRUE;
        }
            break;
        default: 
        {
            fl_image_transparent_U8 = (UINT8)FALSE;
        }
            break;
    }
    return fl_image_transparent_U8;
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_is_child_visible
 ** Visibility:       static
 ** Description:      Determines whether a passed layer is visible or not.
 **                   A passed area is checked against each element above it to
 **                   determine if it is hidden or not. Incase the passed area
 **                   is partially hidden, the exposed area will be again examined
 **                   recursively to see the overall hidden or visible status.
 **                   For example for a reactangle area X, and if there are 5 elements
 **                   above it (elem 1 to 5). Now if elem 1 covers only a small area c
 **                   as shown below
 **                   -----------------
 **                   +               +
 **                   + a             +
 **                   +-------+++++++++
 **                   +\\\c\\\+   b   +
 **                   -----------------
 **                   this function will recursively check for the exposed sub area
 **                   'a' (Visible top portion) and 'b' (Visible Right portion) seperately
 **                   against elem 2 to 5 to see if they are getting
 **                   hidden or not.  So after the recursive loop finally determines that
 **                   a passed area is fully hidden it returns FALSE else it returns TRUE.
 **                   02_design\hmi_gfx_mgr02_design.xls implements a xls macro to proveout
 **                   this logic.
 ** Invocation:       By hmi_gfx_mgr02_manage_layers().
 ** Inputs/Outputs:   p_area          - Pointer to area of the element
 **                   p_elem_list_SAP - Pointer to the element list above.
 **                   p_num_elements  - number of elements in p_elem_list_SAP.
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(	GFX_MGR02_ELEMENT_AREA const *p_area,
                                                            UINT32 p_num_elements,
                                                            GFX_MGR02_WINDOW_DATA_T *p_window_SP) 
{
    UINT32 fl_layer_visible = GFX_MGR02_ELEMENT_INVALID;
    GFX_MGR02_ELEMENT_AREA fl_area = { 0, 0, 0, 0, GFX_MGR02_OPEQUE, 255 };
    GFX_MGR02_ELEMENT_AREA fl_area2 = { 0, 0, 0, 0, GFX_MGR02_OPEQUE, 255 };
    SINT16 fl_temp;
    UINT32 fl_num_elements = p_num_elements;
    GFX_MGR02_WINDOW_DATA_T *fl_window_SP = p_window_SP;
    while ((fl_layer_visible == GFX_MGR02_ELEMENT_INVALID)&& (fl_num_elements > (UINT32) 0))
    {
        fl_area.sx = (SINT16) fl_window_SP->win_prop.topLeftX;
        fl_area.sy = (SINT16) fl_window_SP->win_prop.topLeftY;
        fl_area.ex = (SINT16) fl_window_SP->win_prop.width;
        fl_area.ey = (SINT16) fl_window_SP->win_prop.height;
        fl_area.alpha = (UINT8) fl_window_SP->alpha;

        if (fl_area.alpha == (UINT8) 0)
        {
            /*
             ** The alpha will never be a value of zero. i.e. if zero then this
             ** element will never add to the windows itself. It is only for safety
             ** purpose
             ** nkrishn9 confirm the statement from emanoj
             */
            fl_area.is_transparent = (UINT8) GFX_MGR02_TRANSPARENT;
        } 
        else if ((fl_window_SP->see_through != (UINT8) 0)|| (fl_area.alpha < (UINT8) 255)) 
        {
            fl_area.is_transparent = (UINT8) GFX_MGR02_SEETHROUGH;
        }
        else 
        {
            fl_area.is_transparent = (UINT8) GFX_MGR02_OPEQUE;
        }

        fl_num_elements--;
        fl_window_SP++;
        while (fl_num_elements > (UINT32) 0)
            {
            fl_num_elements--;
            fl_window_SP++;
            if (fl_area.is_transparent == (UINT8) GFX_MGR02_OPEQUE) {
                if ((fl_area.sx <= p_area->sx) && (fl_area.sy <= p_area->sy)
                        && (fl_area.ex >= p_area->ex)
                        && (fl_area.ey >= p_area->ey)) {
                    /*
                     ** p_area is completely hidden in fl_area
                     */
                    fl_layer_visible = GFX_MGR02_ELEMENT_INVISIBLE;
                } else if (((fl_area.sx >= p_area->sx)
                        && (fl_area.sx <= p_area->ex))
                        || ((fl_area.ex >= p_area->sx)
                                && (fl_area.ex <= p_area->ex))
                        || ((fl_area.sx < p_area->sx)
                                && (fl_area.ex > p_area->ex))) {
                    if (((fl_area.sy >= p_area->sy)
                            && (fl_area.sy <= p_area->ey))
                            || ((fl_area.ey >= p_area->sy)
                                    && (fl_area.ey <= p_area->ey))
                            || ((fl_area.sy < p_area->sy)
                                    && (fl_area.ey > p_area->ey))) {
                        /*
                         ** Layer is overlapping.
                         */
                        fl_area2.sx = p_area->sx;
                        fl_area2.sy = p_area->sy;
                        fl_area2.ex = p_area->ex;
                        fl_area2.ey = p_area->ey;
                        fl_area2.is_transparent = p_area->is_transparent;

                        if (fl_area.sy > p_area->sy) {
                            /*
                             ** Visible top portion of the p_area rectangle
                             */
                            fl_area2.ey = (fl_area.sy - (SINT16) 1);
                            fl_layer_visible =
                                    hmi_gfx_mgr02_manage_layers_is_child_visible(
                                            (GFX_MGR02_ELEMENT_AREA const*) &fl_area2,
                                            fl_num_elements, fl_window_SP);
                            fl_area2.sy = fl_area.sy;
                            fl_area2.ey = p_area->ey;
                        }
                        if ((fl_area.ey < p_area->ey)
                                && (fl_layer_visible
                                        != GFX_MGR02_ELEMENT_VISIBLE)) {
                            /*
                             ** Visible bottom portion of the p_area rectangle
                             */
                            fl_temp = fl_area2.sy;
                            fl_area2.sy = (fl_area.ey + (SINT16) 1);
                            fl_layer_visible =
                                    hmi_gfx_mgr02_manage_layers_is_child_visible(
                                            (GFX_MGR02_ELEMENT_AREA const*) &fl_area2,
                                            fl_num_elements, fl_window_SP);
                            fl_area2.sy = fl_temp;
                            fl_area2.ey = fl_area.ey;
                        }
                        if ((fl_area.sx > p_area->sx)
                                && (fl_layer_visible
                                        != GFX_MGR02_ELEMENT_VISIBLE)) {
                            /*
                             ** Visible Left portion of the p_area rectangle
                             */
                            fl_area2.ex = (fl_area.sx - (SINT16) 1);
                            fl_layer_visible =
                                    hmi_gfx_mgr02_manage_layers_is_child_visible(
                                            (GFX_MGR02_ELEMENT_AREA const*) &fl_area2,
                                            fl_num_elements, fl_window_SP);
                            fl_area2.ex = p_area->ex;

                        }
                        if ((fl_area.ex < p_area->ex)
                                && (fl_layer_visible
                                        != GFX_MGR02_ELEMENT_VISIBLE)) {
                            /*
                             ** Visible Right portion of the p_area rectangle
                             */
                            fl_area2.sx = (fl_area.ex + (SINT16) 1);
                            fl_layer_visible =
                                    hmi_gfx_mgr02_manage_layers_is_child_visible(
                                            (GFX_MGR02_ELEMENT_AREA const*) &fl_area2,
                                            fl_num_elements, fl_window_SP);
                        }
                    }
                    /*
                     ** ELSE - Layer is not overlapping with fl_area so need to proceed to
                     **        next element in p_elem_list_SAP to see if that is overlapping.
                     */
                } else {
                    /* QAC fix... */
                }
                /*
                 ** ELSE - Layer is not overlapping with fl_area so need to proceed to
                 **        next element in p_elem_list_SAP to see if that is overlapping.
                 */

            }
        }
    }
    if (fl_layer_visible == GFX_MGR02_ELEMENT_INVALID) {
        fl_layer_visible = GFX_MGR02_ELEMENT_VISIBLE;
    }
    return (fl_layer_visible);
}

#if (GFX_MGR02_NUM_OF_FILLS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_tile_fill_layer_area
 ** Visibility:       static
 ** Description:      fetches the Tile, Fill elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_get_tile_fill_layer_area(	GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area)
{
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

    if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
        if (fl_obj_type == GFX_MGR02_TYPE_FILL) 
        {
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
            {
                hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const*) &l_layer_anim_data_SP->fill_prop[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_layer_anim_data_SP->fill_prop[fl_obj_id].alpha);
                p_elem_area->ex = (SINT16) l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.width;
                p_elem_area->ey = (SINT16) l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.height;
            p_elem_area->is_transparent = (UINT8) GFX_MGR02_OPEQUE;
            }
#endif
        }
    }
    else 
    {
        if (fl_obj_type == GFX_MGR02_TYPE_FILL) 
        {
#if GFX_MGR02_NUM_FILL_INSTANCES > 0
            if((fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_INSTANCES) && (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS))
            {
            hmi_gfx_mgr02_context_set_loc(&lc_fill_const_property_S[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) lc_fill_const_property_S[fl_obj_id].alpha);
            p_elem_area->ex = (SINT16) lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.width;
            p_elem_area->ey = (SINT16) lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.height;
            p_elem_area->is_transparent = (UINT8) GFX_MGR02_OPEQUE;
            }
#endif
        }
    }
}
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_image_layer_area
 ** Visibility:       static
 ** Description:      fetches the Image elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area) 
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
#if((GFX_MGR02_NUM_USER_LAYERS > 0 )|| (GFX_MGR02_NUM_3D_MDL_LAYERS > 0))
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
#endif
    UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    GFX_MGR02_IMAGE_DEF_T const *fl_image_layer_def_SP;

#if GFX_MGR02_NUM_USER_LAYERS > 0
    if (fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) 
    {
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
        {
            fl_image_layer_def_SP =	&l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
            if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id)) 
            {
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
                if(fl_obj_id < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
                {
                    GFX_MGR02_IMAGE_DYN_PROPERTY * fl_img_dyn_prop_SP = &l_layer_anim_data_SP->user_prop[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_img_dyn_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_dyn_prop_SP->alpha);
                }
       #endif
            } 
            else 
            {
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
                if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
                {
                    GFX_MGR02_IMAGE_PROPERTY const *fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_img_prop_SP->alpha);
                }
#endif
            }
            p_elem_area->ey = (SINT16) fl_image_layer_def_SP->height;
            p_elem_area->ex = (SINT16) fl_image_layer_def_SP->width;
        }
    }
    else
#endif
    {
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
        {
            fl_image_layer_def_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
            if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
                if(fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
                {
                    GFX_MGR02_IMAGE_DYN_PROPERTY const *fl_img_dyn_prop_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc(&fl_img_dyn_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_img_dyn_prop_SP->alpha);
                }
#endif
            } 
            else
            {
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
                if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
                {
                    GFX_MGR02_IMAGE_PROPERTY const *fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_img_prop_SP->alpha);
                }        
#endif
            }
            if (fl_image_layer_def_SP->vaoa_index != (UINT8) 0) 
            {
                fl_vaof_index = (UINT8) fl_image_layer_def_SP->vaoa_index;
            }
            p_elem_area->ey = (SINT16) fl_image_layer_def_SP->height;
            p_elem_area->ex = (SINT16) fl_image_layer_def_SP->width;
        }
#endif
    }
    p_elem_area->is_transparent = (UINT8) GFX_MGR02_OPEQUE;
    return (fl_vaof_index);
}
#endif /* (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) */

#if GFX_MGR02_NUM_OF_SWDGS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_widget_layer_area
 ** Visibility:       static
 ** Description:      fetches the Widget elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T, Visible Area Offset
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,GFX_MGR02_ELEMENT_AREA *p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT16 fl_base_id = p_elem_list_SP->base_id;

    if (fl_base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
    {
        GFX_MGR02_WIDGET_DEF_T const *fl_widget_layer_def_SP =	&lc_swidget_layer_def_S[fl_base_id];

        if(((fl_widget_layer_def_SP->rr_engine == GFX_MGR02_RT_DEFAULT) || (fl_widget_layer_def_SP->rr_engine == GFX_MGR02_RT_VGLITE)) &&
           (fl_widget_layer_def_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE) &&(fl_widget_layer_def_SP->merge!=(UINT8)0))
        {
        #if (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0)
            GFX_FLOAT  fl_bound[4];
            /*
            ** if clip not set, then the
            ** widget area needs to be calculated dynamically based on 
            ** current transformed bounds of the widget layer
            ** For this to work the element has to be animation enabled, so that
            ** its XY location can be modified.
            ** After the bound is calculated, it needs to be loaded to l_runtime_wdg_image_layer_def_S
            ** which is placed in RAM.
            */
            if (fl_widget_layer_def_SP->image_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
            {
                GFX_MGR02_IMAGE_DEF_T   *fl_image_layer_def_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_layer_def_SP->image_id];
                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
                {
                #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
                    UINT32 fl_aligned_width;
                    UINT32 fl_aligned_height;
                    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
                    {
                        GFX_MGR02_WIDGET_DYN_PROPERTY * fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
                        
                        if (fl_widget_layer_def_SP->rr_engine == GFX_MGR02_RT_VGLITE)
                        {
                            (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_list_SP, (u_gx_flocal)GFX_MGR02_TARGET_VGLITE, fl_bound);
                        }
                        else
                        {
                            (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_list_SP, (u_gx_flocal)GFX_MGR02_TARGET_IMXRT_PXP, fl_bound);
                        }

                        fl_widg_dyn_prop_SP->coord.x    = (SINT16)fl_bound[0];
                        fl_widg_dyn_prop_SP->coord.y    = (SINT16)fl_bound[1];
                        fl_bound[0] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.x; /* get any remaining fractional part */
                        fl_bound[1] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.y;

                        fl_aligned_width  = (UINT32)(fl_bound[2] + fl_bound[0] + 0.5f);
                        fl_aligned_height = (UINT32)(fl_bound[3] + fl_bound[1] + 0.5f);

                        fl_image_layer_def_SP->width  = (GFX_MGR02_ISIZE_W_T)(fl_aligned_width);
                        fl_image_layer_def_SP->height = (GFX_MGR02_ISIZE_H_T)(fl_aligned_height);
                    }
                #endif
                }
                else
                {
                    fl_image_layer_def_SP->width  = (UINT16)0;
                    fl_image_layer_def_SP->height = (UINT16)0;
                }
                p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
                p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
                if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
                {
                    fl_vaof_index = (UINT8)fl_image_layer_def_SP->vaoa_index;
                }
            }
        #else
            /*
            ** Not a valid configuration & never expected to run.
            ** Make the layer invisible
            */
            p_elem_area->ey  = -1;
            p_elem_area->ex  = -1;
        #endif
        }
        else
        {
    #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
               if( fl_widget_layer_def_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
               {
                   GFX_MGR02_IMAGE_DEF_T const *fl_image_layer_def_SP = &lc_image_layer_def_S[fl_widget_layer_def_SP->image_id];
                   p_elem_area->ey = (SINT16) fl_image_layer_def_SP->height;
                   p_elem_area->ex = (SINT16) fl_image_layer_def_SP->width;
                   if (fl_image_layer_def_SP->vaoa_index != (UINT8) 0)
                   {
                       fl_vaof_index = (UINT8) fl_image_layer_def_SP->vaoa_index;
                   }
               }
    #endif
        }

        if (fl_widget_layer_def_SP->merge != (UINT8) 0) 
        {
            p_elem_area->is_transparent = (UINT8) GFX_MGR02_OPEQUE;
        }

        if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
            {
                GFX_MGR02_WIDGET_DYN_PROPERTY const *fl_widg_dyn_prop_SP =	&l_layer_anim_data_SP->widget_prop[fl_obj_id];
                
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) fl_widg_dyn_prop_SP->alpha);
            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                if (fl_widget_layer_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE) 
                {
                    GFX_MGR02_WIDGET_PROPERTY const *fl_elem_prop_SP;
                    GFX_MGR02_ILOC_DATA fl_coord;
                    /*
                     ** When hmi_gfx_mgr02_context_set_clip is invoked, the clip
                     ** start X & Y is added with the current XY location in context
                     ** So we need to make sure we just have the offset of XY movement
                     ** alone in context prior to hmi_gfx_mgr02_context_set_clip call
                     ** After this call we can set the raw co-ordinate values
                     */
                    fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id];
                    fl_coord.x = (SINT16) (-fl_elem_prop_SP->coord.x);
                    fl_coord.y = (SINT16) (-fl_elem_prop_SP->coord.y);
                    hmi_gfx_mgr02_context_set_loc(&fl_coord);
                    hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_clip(&fl_widg_dyn_prop_SP->clip);
                    if (fl_widget_layer_def_SP->merge != (UINT8) 0) 
                    {
                        fl_coord.x = -fl_coord.x;
                        fl_coord.y = -fl_coord.y;
                        hmi_gfx_mgr02_context_set_loc(&fl_coord);
                    }
                }
                else
            #endif
                {
                    hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
                }
            }
        #endif
        } 
        else 
        {
        #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
            if (fl_obj_id < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
            {
                if (fl_widget_layer_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE) 
                {
                    if(fl_widget_layer_def_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
                    {                     
                      GFX_MGR02_IAREA_DATA fl_clip_area_SP;
                      fl_clip_area_SP.x =  lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].sx;
                      fl_clip_area_SP.y =  lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].sy;
                      fl_clip_area_SP.width  =  (UINT16) lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].ex;
                      fl_clip_area_SP.height =(UINT16) lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].ey;
                      hmi_gfx_mgr02_context_set_clip(&fl_clip_area_SP);
                    }
                }
            
                hmi_gfx_mgr02_context_set_loc(&lc_swdg_const_property_S[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal) lc_swdg_const_property_S[fl_obj_id].alpha);
            }
    #endif
        }
    }
    return (fl_vaof_index);
}
#endif  /* GFX_MGR02_NUM_OF_SWDGS */

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_set_blendmode
 ** Visibility:       static
 ** Description:
 ** Invocation:
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static void hmi_gfx_mgr02_set_blendmode( GFX_MGR02_WINDOW_DATA_T const *p_wind,UINT32 p_layer_index, lcdifv2_pixel_format_t pix_format)
{
    lcdifv2_blend_config_t config = {0};
    config.globalAlpha =  p_wind->alpha;
    config.alphaMode = kLCDIFV2_AlphaEmbedded;

    LCDIFV2_SetLayerBlendConfig(DEMO_LCDIF, (UINT8)p_layer_index, &config);
    GFX_MGR02_UNUSED_VAR(pix_format);
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_bound
Description          : Calculates the transformed bounds of an elements passed
boundary
Invocation           : 
Parameters           : Object, Context and boundary
Return Value         : Boundary
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_get_bound(GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds)
{
  p_bounds[0] = (GFX_FLOAT)p_cntx_SP->state.loc.x;
  p_bounds[1] = (GFX_FLOAT)p_cntx_SP->state.loc.y;
  /* return True by default since no error condition has been identified */
  return((s_gx_flocal)TRUE);
}

#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_imxrt_get_runtime_widget_ptr
 ** Visibility:       Global
 ** Description:      Interface to get pointer of l_runtime_wdg_image_layer_def_S .
 **
 ** Invocation:       By hmi_gfx_mgr02_context.c
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          28-Jul-2017 by CSAKTHIV
 ** Updated:
 **==========================================================================*/

GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_imxrt_get_runtime_widget_ptr(UINT16 p_img_id)
{
    GFX_MGR02_IMAGE_DEF_T *fl_image_def_SP = GFX_MGR02_NULL_PTR;
    if (p_img_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
    {
        fl_image_def_SP = &l_runtime_wdg_image_layer_def_S[p_img_id];
}
    return fl_image_def_SP;
}
#endif

#ifdef  __cplusplus
}
#endif
#endif /* #if defined(GFX_MGR02_IMXRT) */
