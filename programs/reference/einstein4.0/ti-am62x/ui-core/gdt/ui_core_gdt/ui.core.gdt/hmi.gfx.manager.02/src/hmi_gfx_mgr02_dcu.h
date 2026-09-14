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
** Name:           hmi_gfx_mgr02_dcu.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_DCU_H
#define HMI_GFX_MGR02_DCU_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0)
  #define __GFX_MGR02_RLE_ENABLED
#endif

#ifdef GFX_MGR02_KEPLER
typedef struct
{
   GFX_MGR02_ELEM_LIST_T  const * next_elem_list_sa[GFX_MGR02_NUM_DCU_LAYERS];
   GFX_MGR02_ELEM_LIST_T  const * cur_elem_list_sa[GFX_MGR02_NUM_DCU_LAYERS];
   GFX_MGR02_VISIBLE_AREA         elem_area_sa[GFX_MGR02_NUM_DCU_LAYERS];
   UINT8                          cur_layer_index;
   UINT8                          start_layer_index;
   UINT8                          visible_num_of_elements;
   UINT8                          hp_num_elements;
   UINT8                          lp_num_elements;
   volatile UINT8                 cur_build_layer;
#ifdef GFX02_DEBUG_INFO
   UINT32                         l_tot_num_of_elements;
#endif
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
   GFX_MGR02_IMAGE_DEF_T  const * rt_wdg_img_layer_def_SP;
#endif
}GFX_MGR02_CONTROL_DATA_T;

typedef struct
{
   UINT32 address;
   UINT32 size  :24;
   UINT32 status:8;
}GFX_MGR02_GRAM_CHUNK;

typedef struct
{
   GFX_MGR02_ALPHA     alpha;
   GFX_MGR02_ILOC_DATA coord;
}GFX_MGR02_GROUP_PROPERTY;

#define GFX_MGR02_DATA_MODE_DIRECT    (0)
#define GFX_MGR02_DATA_MODE_RELATIVE  (1)

#define GFX_MGR02_PMODE_IDLE                 (0x00u)
/*
** Possible graphics modes hold by l_gfx_mgr_vsync_process_mode
** This is used by the hmi_gfx_mgr02_vblank_isr (DCU ISR)
*/
#define GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU   (0x08u) /* Virtual layer to DCU layer copy request */
#define GFX_MGR02_PMODE_START_BUILD          (0x04u) /* Build operation needs to be started     */
#define GFX_MGR02_PMODE_CPY_WBUF2GRAM        (0x02u) /* Build operation needs to be started     */

/*
** Possible graphics modes hold by l_gfx_mgr_edma_process_mode
** This is used by the hmi_gfx_mgr02_gram_print_done_isr (eDMA ISR)
*/
#define GFX_MGR02_PMODE_BUILD_TEXT           (0x01u) /* indicates text layer building is triggered */
#define GFX_MGR02_PMODE_BUILD_WIDGET         (0x04u) /* indicates a widget element building is triggered */
#define GFX_MGR02_PMODE_BUILD_WIDGET_SUB_CPY (0x02u) /* indicates a sub copy for a widget element is triggered */
#define GFX_MGR02_PMODE_INIT_GRAM            (0x03u) /* indicates GRAM initialization during pre-render phase triggered */
#define GFX_MGR02_PMODE_SWAP_GRAM            (0x05u) /* indicates a GRAM front to back buffer copy is triggered */
#define GFX_MGR02_PMODE_UPDATE_GRAM          (0x06u) /* indicates GRAM initialization during render phase triggered */
#define GFX_MGR02_PMODE_BUILD_IMAGE          (0x07u) /* indicates text layer building is triggered */

/*
** GFX_MGR02_MAX_CLUT_INDEX - Maximum CLUT index value supported by the DCU3
** DCU3_CLUT_MEM_SIZE       - Maximum CLUT memory available in bytes
** DCU3_CLUT_NUM_ENTRIES    - Number of CLUT entries possible in the available CLUT memory
**                            (color entry takes 4bytes)
*/
#define GFX_MGR02_MAX_CLUT_INDEX  ((UINT32)0x00000800)
#define DCU3_CLUT_MEM_SIZE        (8*1024)
#define DCU3_CLUT_NUM_ENTRIES     (DCU3_CLUT_MEM_SIZE/sizeof(UINT32))

/*
** Define the numberof words in 64bit  (1word = 4bytes = 32bits)
** Define the numberof bytes in a word (1word = 4bytes = 32bits)
*/
#define GFX_MGR02_WORDS_IN_64BIT (2ul)
#define GFX_MGR02_BYTES_IN_WORD  (4ul)
#define GFX_MGR02_BYTES_IN_64BIT (GFX_MGR02_BYTES_IN_WORD*GFX_MGR02_WORDS_IN_64BIT)

/*
** Maximum number of WORDS copied in a single loop using CPU, after this
** count the loop will break and check for DMA availability.
*/
#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
 #define GFX_MGR02_CPU_COPY_MAX_WORDS ((GFX_MGR02_DCU_EDMA_TXFR_32BYTES * 3)/GFX_MGR02_BYTES_IN_WORD)
#else
 #define GFX_MGR02_CPU_COPY_MAX_WORDS (GFX_MGR02_WORDS_IN_64BIT * 10)
#endif

/*
** hmi_gfx_mgr02_vblank_isr p_type definitions
** GFX_MGR02_DCU_VSYNC_START - indicates start of vsync where the 
**                             register programming can be started
** GFX_MGR02_DCU_TXFR_END    - indicates end of DCU DMA transfers
**                             for the current frame. This is used
**                             to begin the next content build 
*/
#define GFX_MGR02_DCU_VSYNC_START (0)
#define GFX_MGR02_DCU_TXFR_FINISH (1)


/*
** Possible configuration options for GFX_MGR02_GRAM_OVERAP_HANDLING
** See hmi_gfx_mgr02.$cfg for details on each one
*/
#define GFX_MGR02_BUILD_DCU_NORMAL (0x00)
#define GFX_MGR02_BUILD_DCU_VBLANK (0x01)
#define GFX_MGR02_BUILD_DCU_OFSCRN (0x02)

#define GFX_MGR02_DCU_EDMA_TXFR_32BYTES (32)
#define GFX_MGR02_DCU_EDMA_TXFR_16BYTES (16)
#define GFX_MGR02_DCU_EDMA_TXFR_8BYTES  (8)
#define GFX_MGR02_DCU_EDMA_TXFR_4BYTES  (4)
#define GFX_MGR02_DCU_EDMA_TXFR_2BYTES  (2)
#define GFX_MGR02_DCU_EDMA_TXFR_1BYTE   (1)

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
void hmi_gfx_mgr02_initialize(void);
void hmi_gfx_mgr02_vblank_isr(UINT32 p_type);
void hmi_gfx_mgr02_gram_print_done_isr(void);
#if defined(__GFX_MGR02_RLE_ENABLED)
void hmi_gfx_mgr02_rle_isr(void);
#endif
void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U8);
UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
void hmi_gfx_mgr02_emergency_shutdown(void);
#ifdef HMI_GFX_MGR02_ENABLE_DCU_TEST
void hmi_gfx_mgr02_init_for_EOL_mode(UINT32 p_enable_test_pattern);
#endif
void hmi_gfx_mgr02_set_process_mode(UINT8 p_process_mode);
UINT8 hmi_gfx_mgr02_get_process_mode(void);
GFX_MGR02_CONTROL_DATA_T    * hmi_gfx_mgr02_get_control_data_ptr(void);
extern UINT8          const lc_dcu_image_width_byte_U8A[GFX_MGR02_16BPP_APAL8+1];
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
** CMS Rev 1.1     04/08/17    ADEVI
** 924879 : Monotype Font Integration in Kepler I.
**
** CMS Rev 1.0      08-Aug-12    EMANOJ1
** Creation.
**
**==========================================================================*/

/* end of file =============================================================*/
#endif
