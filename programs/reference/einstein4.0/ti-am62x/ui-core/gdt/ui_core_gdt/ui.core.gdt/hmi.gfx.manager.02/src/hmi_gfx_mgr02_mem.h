/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_mem.h
**
** Description:    Interface header for the graphics manager for the
**                 Kepler Spectrum/RainbowLite Platform.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_MEM_H
#define HMI_GFX_MGR02_MEM_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
#ifdef GFX_MGR02_KEPLER
/*
** Possible states for status element in GFX_MGR02_GRAM_CHUNK structure
** GFX_MGR02_GRAM_CHUNK_STS_NONE      - Means that the GRAM chunk is not allocated
** GFX_MGR02_GRAM_CHUNK_STS_ACTIVE    - Means the GRAM chunk is fully built and ready to assign to DCU
** GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED - Means the GRAM chunk is allocated a memory but not initialized or built
** GFX_MGR02_GRAM_CHUNK_STS_INITED    - Means the GRAM chunk is initialized to a default color value.
** GFX_MGR02_GRAM_CHUNK_STS_OVERLAP   - Means the GRAM chunk is overlapping with an already active chunk.
**                                      This happens because when a new updates need to built, the gfx02
**                                      allocates GRAM chunks for layers in back buffer. But when the back
**                                      buffer size requirement exceeds the available free memory then
**                                      the GRAM chunks gets allocated in to the front buffer itself.
**                                      These buffers are set as OVERLAP buffers. GFX02 doesnot perform
**                                      any inittialization or prerender operation on OVERLAP buffers
**                                      because they becomes visible since part of whole of them would be
**                                      lively displayed. OVERLAP buffer is initialized and built in vblank
**                                      only to avoid any undesired visual effects.
** GFX_MGR02_GRAM_CHUNK_STS_COPY      - Means that the backbuffer doesn't needs to be rebuilt, instead it
**                                      copy the content from its current front buffer as there is no
**                                      change as such.
** GFX_MGR02_GRAM_CHUNK_STS_BUILT     - indicates that the content is built but some post processing 
**                                      is required to make it ACTIVE. This is currently used only for
**                                      multi color widgets in DCU. 
*/
#define GFX_MGR02_GRAM_CHUNK_STS_NONE      (0)
#define GFX_MGR02_GRAM_CHUNK_STS_ACTIVE    (1)
#define GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED (2)
#define GFX_MGR02_GRAM_CHUNK_STS_INITED    (3)
#define GFX_MGR02_GRAM_CHUNK_STS_OVERLAP   (4)
#define GFX_MGR02_GRAM_CHUNK_STS_COPY      (5)
#define GFX_MGR02_GRAM_CHUNK_STS_BUILT     (6)
#define GFX_MGR02_GRAM_CHUNK_STS_WAIT_SYNC (7)

#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
  #define GFX_MGR02_OFSCRN2GRAM_OFFSET  (GFX_MGR02_GRAM_DCU_BASE-hmi_gfx_mgr02_mem_getbase())
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

UINT32 hmi_gfx_mgr02_get_size_for_bpp(UINT32 bpp, UINT32 size, UINT32 alignment);
UINT32 hmi_gfx_mgr02_memcpy_64bit(UINT32 p_source_addr,
                                  UINT32 p_dest_addr,
                                  UINT32 p_size_bytes);
UINT32 hmi_gfx_mgr02_get_front_buffer_index(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_cur_elem_index);
UINT32 hmi_gfx_mgr02_copy_front_to_back_buffer(UINT32 p_front_buffer_index, UINT32 p_back_buffer_index);
void   hmi_gfx_mgr02_swap_backbuff_to_frontbuff(void);
#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
UINT32 hmi_gfx_mgr02_mem_getbase(void);
#endif

GFX_MGR02_GRAM_CHUNK * hmi_gfx_mgr02_get_front_buffer(UINT32 p_layer_id);
GFX_MGR02_GRAM_CHUNK * hmi_gfx_mgr02_get_back_buffer(UINT32 p_layer_id);

void hmi_gfx_mgr02_mem_initialize(void);
void hmi_gfx_mgr02_mem_start_alloc(UINT32 p_num_layers);
UINT32 hmi_gfx_mgr02_mem_alloc(UINT32 p_layer, UINT32 p_size_bytes);
void hmi_gfx_mgr02_mem_end_alloc(void);
void hmi_gfx_mgr02_mem_cancel_alloc(void);
void hmi_gfx_mgr02_mem_done(void);

#if defined(GFX_MGR02_DCU_ENABLE_HCLIP)
UINT32 hmi_gfx_mgr02_get_workbuffer(UINT32 p_size_bytes);
#endif

#endif /* #ifdef GFX_MGR02_KEPLER */
#ifdef  __cplusplus
}
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
**
** CMS Rev 1.2      22-Aug-2015    APERUMAL
** RTC#405974
** QA C warning fix for Honda Thaa
**
** CMS Rev 1.1      19-Sep-2013    EMANOJ1
** Updated to support multi color text
**
** Updated          16-Mar-2012  ASHEKHAR
**
** CMS Rev 1.0      05-May-11    EMANOJ1
** Creation.
**==========================================================================*/

/* end of file =============================================================*/
#endif
