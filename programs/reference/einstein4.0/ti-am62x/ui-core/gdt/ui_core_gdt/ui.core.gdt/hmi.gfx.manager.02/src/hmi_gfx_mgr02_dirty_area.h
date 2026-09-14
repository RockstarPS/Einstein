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
** Name:           hmi_gfx_mgr02_dirty_area.h
**
** Description:    dirty area redraw related interfaces
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_DIRTY_AREA_H
#define HMI_GFX_MGR02_DIRTY_AREA_H

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

typedef struct
{
   UINT32 spos;
   UINT32 epos;
}GFX_MGR02_DAR_AREA; 

typedef struct
{
   GFX_MGR02_ELEM_LIST_T const * elem_SP;
   UINT8                         opeque;
   UINT8                         dirty_area;
}GFX_MGR02_DAR_OBJECT;

typedef struct
{
   GFX_MGR02_ELEM_LIST_T const * elem_SP;
   GFX_MGR02_VISIBLE_AREA        area;
   GFX_UINT                        opeque:1;  /* TODO : check and optimize for memory later */
   GFX_UINT                        visible:1;
}GFX_MGR02_DAR_OBJ_INFO;

typedef struct
{
   GFX_MGR02_DAR_OBJ_INFO * obj_info;
   UINT16                 * obj_count;
   UINT32                   max_objects;
}GFX_MGR02_DAR_OBJ_CONFIG;

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW

void   hmi_gfx_mgr02_dar_init(void);
void   hmi_gfx_mgr02_dar_start(UINT8 p_layer_id);
UINT32 hmi_gfx_mgr02_dar_add(GFX_MGR02_DAR_OBJECT * p_dar_obj_SP, GFX_FLOAT * p_bound);
UINT32 hmi_gfx_mgr02_dar_process(void);
GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_dar_get_drect(UINT32 p_index);
UINT32 hmi_gfx_mgr02_dar_get_num_drects(void);
GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_dar_get_object_area(GFX_MGR02_ELEM_LIST_T const * p_elem_SP);

#endif /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */

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
**
** CMS Rev 1.2      26-Aug-2013    EMANOJ1
** Updated based on changes required in generic.c to support dynamic buffer
** allocation for DCU openVG widgets.
**
** CMS Rev 1.1      20-Jun-2013    EMANOJ1
** Updated to add element opeque, visible status bit to support element visibility
** check by DAR to speed up rendering by removal of invisible elements from 
** rendering.
**
** CMS Rev 1.0      15-May-2013     EMANOJ1
** Creation.
**
**==========================================================================*/
/* end of file =============================================================*/
#endif
