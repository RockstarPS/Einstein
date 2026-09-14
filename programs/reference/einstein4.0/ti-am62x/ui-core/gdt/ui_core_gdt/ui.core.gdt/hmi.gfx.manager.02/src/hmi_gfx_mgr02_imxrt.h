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
** Name:           hmi_gfx_mgr02_imxrt.h
**
** Description:    Building Graphics element using IMXRT PXP driver API
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#ifndef HMI_GFX_MGR02_IMXRT_H
#define HMI_GFX_MGR02_IMXRT_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_imxrt_lcdif.h"

#if defined (GFX_MGR02_IMXRT)

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#ifdef HMI_GFX_MGR02_IMXRT_C
#define GFX_IMXRT_EXTERN
#else
#define GFX_IMXRT_EXTERN extern
#endif

typedef struct GFX_IMXRT_WINDOW_PROPERTIES{
	UINT32 topLeftX; /*!< Top left X coordinate of the window on the display.     */
	UINT32 topLeftY; /*!< Top left Y coordinate of the window on the display.     */
	UINT32 width; /*!< Width to create the window with.                        */
	UINT32 height; /*!< Height to create the window with. */
} GFX_IMXRT_WINDOW_PROPERTIES;


/* Defines the data required for managing a single window */
typedef struct GFX_MGR02_WINDOW_DATA_T{
	GFX_IMXRT_WINDOW_PROPERTIES win_prop;
	GFX_MGR02_VISIBLE_AREA clip;
	void *render_buffer;
	UINT32 win_colour;
	UINT8 win;
	GFX_MGR02_ELEM_LIST_T const * prevLayer;
	UINT8 layerId;
	SINT32 posx;
	SINT32 posy;
	GFX_UINT win_sts :2;
	UINT8 alpha;
	GFX_UINT see_through :1;
	UINT32 startX;
	UINT32 startY;	
    GFX_MGR02_ELEM_LIST_T  const * root_elem_sp;
    GFX_MGR02_ELEM_LIST_T  const * next_elem_sp;
    GFX_MGR02_ELEM_LIST_T  const * curr_elem_sp;
} GFX_MGR02_WINDOW_DATA_T;


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

GFX_IMXRT_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_initialize(void);
GFX_IMXRT_EXTERN void hmi_gfx_mgr02_imxrt_build_widget(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP, UINT32 p_layer_index);


#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
GFX_IMXRT_EXTERN void hmi_gfx_mgr02_imxrt_build_image(GFX_MGR02_WINDOW_DATA_T *p_win_data_SP,UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const *p_elem_list_SP,UINT32 p_layer_index);
#endif

GFX_IMXRT_EXTERN UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);

GFX_IMXRT_EXTERN s_gx_flocal hmi_gfx_mgr02_imxrt_get_bound(GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
GFX_IMXRT_EXTERN void hmi_gfx_mgr02_imxrt_build_screen(UINT32 p_layer_ID_U32);

#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
GFX_IMXRT_EXTERN GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_imxrt_get_runtime_widget_ptr(UINT16 p_img_id);
#endif
GFX_IMXRT_EXTERN UINT32 hmi_gfx_mgr02_imxrt_get_disp_content_status(void);
GFX_IMXRT_EXTERN void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8,UINT32 p_bg_color_u32);
#undef GFX_IMXRT_EXTERN
#endif
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

** CMS Rev 1.0      27-Jun-2021    CSAKTHIV
** Initial version.
**==========================================================================*/
/* end of file =============================================================*/

