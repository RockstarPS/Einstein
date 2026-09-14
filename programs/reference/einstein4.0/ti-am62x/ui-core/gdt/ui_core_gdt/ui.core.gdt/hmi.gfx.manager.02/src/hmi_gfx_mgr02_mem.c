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
 ** Name:           hmi_gfx_mgr02_mem.c
 **
 ** Description:    Manages the GRAM by allocating back buffer to the next
 **                 display element list. DUring the first run the GRAM is
 **                 allocated from the start of GRAM memory. When a display
 **                 refresh requiring new element or update of existing element
 **                 are required, the buffer will be allocated from the end of
 **                 GRAM memory. Now the block allocated at the end of GRAM will
 **                 be back buffer where the hmi_gfx_mgr02 performs the building
 **                 operations. Now once the building is complete the back buffer
 **                 is tagged as the front buffer. Now the next request for build
 **                 or refresh will make the GRAM allocation to happen from the
 **                 start of GRAM memory. This cycle will be continued.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_MEM_C
#define HMI_GFX_MGR02_PRIV_C

#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_KEPLER
/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "dma.handler.h"
#include "graphics.h"
#include "hmi_gfx_mgr02_dcu.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_mem.h"
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
#if !defined(NUNIT_TESTING)
  #include <windows.h>
  #include <stdio.h>
  #include "hmi_gfx_dcu_sim_w32.h"
#endif
#endif
#if  defined(GFX_MGR02_SHUTDOWN_TEST)
#include "hmi_gfx_mgr02_test.h"
#endif


#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#if !defined(GFX_MGR02_SHUTDOWN_TEST)
#define  GFX_MGR_TEST_SHUTDOWN(count)
#endif

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static void hmi_gfx_mgr02_dma_complete_cb(dma_handler_app_resp_struct * p_app_resp_S);

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
static GFX_MGR02_GRAM_CHUNK l_next_gram_alloc_table[GFX_MGR02_NUM_DCU_LAYERS];
static UINT32               l_next_gram_alloc_size;
static GFX_MGR02_GRAM_CHUNK l_cur_gram_alloc_table[GFX_MGR02_NUM_DCU_LAYERS];
static UINT32               l_cur_gram_alloc_size;
static UINT32               l_act_gram_alloc_size;
static UINT8                l_cur_front_buffer_loc;
static UINT8                l_next_gram_alloc_layers; 
static UINT8                l_cur_gram_alloc_layers; 


#if defined(WIN32) || defined(MATLAB_MEX_FILE)
   UINT8 gallo_memory[GFX_MGR02_GRAM_SIZE];
   #define GFX_MGR02_GRAM_BASE  ((UINT32)&gallo_memory[0])
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_initialize
 ** Visibility:       global
 ** Description:      Initializes all internal variable data to its default
 ** Invocation:       By gfx mgr 02 core
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-Apr-2012 by EMANOJ1
 ** Created:          05-Apr-2012 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_mem_initialize(void)
{
    l_next_gram_alloc_size   = 0;
    l_cur_gram_alloc_size    = 0;
    l_cur_front_buffer_loc   = 0;
    l_next_gram_alloc_layers = 0;
    l_cur_gram_alloc_layers  = 0; 
    l_act_gram_alloc_size    = 0;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_front_buffer
 ** Visibility:       global
 ** Description:      Returns the specified front buffer
 ** Invocation:       By gfx mgr 02 core
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-Apr-2012 by EMANOJ1
 ** Created:          05-Apr-2012 by EMANOJ1
 **==========================================================================*/
GFX_MGR02_GRAM_CHUNK * hmi_gfx_mgr02_get_front_buffer(UINT32 p_layer_id)
{
   GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP;
   if(p_layer_id < l_cur_gram_alloc_layers)
   {
      fl_gram_chunk_SP = &l_cur_gram_alloc_table[p_layer_id];
   }
   else
   {
      fl_gram_chunk_SP = GFX_MGR02_NULL_PTR;
   }
   return(fl_gram_chunk_SP);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_back_buffer
 ** Visibility:       global
 ** Description:      Returns the specified back buffer
 ** Invocation:       By gfx mgr 02 core
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-Apr-2012 by EMANOJ1
 ** Created:          05-Apr-2012 by EMANOJ1
 **==========================================================================*/
GFX_MGR02_GRAM_CHUNK * hmi_gfx_mgr02_get_back_buffer(UINT32 p_layer_id)
{
   GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP;
   if(p_layer_id < l_next_gram_alloc_layers)
   {
      fl_gram_chunk_SP = &l_next_gram_alloc_table[p_layer_id];
   }
   else
   {
      fl_gram_chunk_SP = GFX_MGR02_NULL_PTR;
   }
   return(fl_gram_chunk_SP);
}

#if defined(GFX_MGR02_DCU_ENABLE_HCLIP)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_workbuffer
 ** Visibility:       global
 ** Description:      Returns the pointer to a work buffer if the requsted 
 **                   size is available. First a dedicated buffer is checked for
 **                   availability. If not available then will look at the 
 **                   regular GRAM for space and returns a valid pointer if
 **                   requested space is free.
 ** Invocation:       By gfx mgr 02 core
 ** Inputs/Outputs:   None
 ** Critical Section: Could be called from either GraphicsTask or from eDMA 
 **                   complete callback ISR.
 ** Created:          23-May-2013 by EMANOJ1
 ** Created:          29-May-2013 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_get_workbuffer(UINT32 p_size_bytes)
{
   UINT32 fl_base_address;

#if GFX_MGR02_DEDICATED_WORK_BUFFER_SIZE > 0
   if(p_size_bytes <= GFX_MGR02_DEDICATED_WORK_BUFFER_SIZE)
   {
      fl_base_address = (GFX_MGR02_DEDICATED_WORK_BUFFER_BASE);
   }
   else
   {
      fl_base_address = (UINT32)(GFX_MGR02_NULL_PTR);
   }
#else
   /* Compiler warning fix for Honda THAA */
   UINT32 fl_available_size;

   fl_base_address   = (UINT32)(GFX_MGR02_NULL_PTR);
   fl_available_size = (l_next_gram_alloc_size + l_act_gram_alloc_size);
   if(fl_available_size >= GFX_MGR02_GRAM_SIZE)
   {
      fl_available_size = 0;
   }
   else
   {
      fl_available_size = (GFX_MGR02_GRAM_SIZE-fl_available_size);
      if(fl_available_size >= p_size_bytes)
      {
      #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
         if(l_cur_front_buffer_loc != 0)
         {
            fl_base_address = (GFX_MGR02_GRAM_BASE+l_next_gram_alloc_size);
         }
         else
         {
            fl_base_address  = ((GFX_MGR02_GRAM_BASE+GFX_MGR02_GRAM_SIZE)-l_next_gram_alloc_size);
            fl_base_address -= fl_available_size;
         }
      #else
         if(l_cur_front_buffer_loc != 0)
         {
            fl_base_address = (GFX_MGR02_GRAM_BASE+l_next_gram_alloc_size);
         }
         else
         {
            fl_base_address  = ((GFX_MGR02_GRAM_BASE+(GFX_MGR02_GRAM_SIZE/2))+l_next_gram_alloc_size);
         }
      #endif
      }
   }
#endif
   return(fl_base_address);
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_start_alloc
 ** Visibility:       local
 ** Description:      Initialization for starting the memory allocation
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          18-Jun-2013 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_mem_start_alloc(UINT32 p_num_layers)
{
   l_next_gram_alloc_layers = (UINT8)p_num_layers;
   l_next_gram_alloc_size   = 0;
   /*
   ** Decide on the allocation start point, if previous allocation
   ** was from start of GRAM (GFX_MGR02_GRAM_BASE) then make the
   ** next allocation to start from end of GRAM (GFX_MGR02_GRAM_BASE+GFX_MGR02_GRAM_SIZE)
   */
   if(l_cur_front_buffer_loc == 0)
   {
      l_cur_front_buffer_loc = 1;
   }
   else
   {
      l_cur_front_buffer_loc = 0;
   }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_cancel_alloc
 ** Visibility:       local
 ** Description:      Cancels the allocations done so far reset the 
 **                   l_cur_front_buffer_loc.
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          13-Feb-2015 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_mem_cancel_alloc(void)
{
   /*
   ** Decide on the allocation start point, if previous allocation
   ** was from start of GRAM (GFX_MGR02_GRAM_BASE) then make the
   ** next allocation to start from end of GRAM (GFX_MGR02_GRAM_BASE+GFX_MGR02_GRAM_SIZE)
   */
   if(l_cur_front_buffer_loc == 0)
   {
      l_cur_front_buffer_loc = 1;
   }
   else
   {
      l_cur_front_buffer_loc = 0;
   }
   l_next_gram_alloc_size = l_act_gram_alloc_size;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_done
 ** Visibility:       local
 ** Description:      Indicates end of current build cycle to mem module
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          07-Jan-2015 by EMANOJ1
 ** Updated:          07-Jan-2015 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_mem_done(void)
{
   l_act_gram_alloc_size = l_next_gram_alloc_size;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_end_alloc
 ** Visibility:       local
 ** Description:      Indicates end of successful gram allocations
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          18-Jun-2013 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_mem_end_alloc(void)
{
#ifdef GFX02_DEBUG_INFO
    gfx_debug("\r\nINFO   - TOTAL GRAM USAGE fb=%d bb=%d tot = %d\r\n\r\n", l_cur_gram_alloc_size,
    l_next_gram_alloc_size,
    l_cur_gram_alloc_size+l_next_gram_alloc_size);
#endif
#ifdef GFX02_DEBUG_WARN
   if((l_next_gram_alloc_size + l_cur_gram_alloc_size) > GFX_MGR02_GRAM_SIZE)
   {
      gfx_debug("WARNING - There is not enough memory to double buffer fb=%d bb=%d tot = %d\r\n", l_cur_gram_alloc_size, l_next_gram_alloc_size, l_cur_gram_alloc_size+l_next_gram_alloc_size);
   }
#endif
}

#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_alloc
 ** Visibility:       local
 ** Description:      Allocates the gram and ties it to the passed layer id.
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          18-Jun-2013 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_mem_getbase(void)
{
   UINT32                 fl_start_address;
   if(l_cur_front_buffer_loc != 0)
   {
      fl_start_address = GFX_MGR02_GRAM_BASE;
   }
   else
   {
      fl_start_address = (GFX_MGR02_GRAM_BASE+(GFX_MGR02_GRAM_SIZE/2));
   }
   return(fl_start_address);
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_mem_alloc
 ** Visibility:       local
 ** Description:      Allocates the gram and ties it to the passed layer id.
 ** Invocation:       hmi_gfx_mgr02_manage_layers
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          18-Jun-2013 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_mem_alloc(UINT32 p_layer, UINT32 p_size_bytes)
{
   GFX_MGR02_GRAM_CHUNK * fl_next_alloc_gram = &l_next_gram_alloc_table[p_layer];
   UINT32                 fl_start_address;

#if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
   /*
   ** Decide on the allocation start point, if previous allocation
   ** was from start of GRAM (GFX_MGR02_GRAM_BASE) then make the
   ** next allocation to start from end of GRAM (GFX_MGR02_GRAM_BASE+GFX_MGR02_GRAM_SIZE)
   */
   if(l_cur_front_buffer_loc != 0)
   {
      fl_start_address = GFX_MGR02_GRAM_BASE;
   }
   else
   {
      fl_start_address = (GFX_MGR02_GRAM_BASE+GFX_MGR02_GRAM_SIZE);
   }
#else
   if(l_cur_front_buffer_loc != 0)
   {
      fl_start_address = GFX_MGR02_GRAM_BASE;
   }
   else
   {
      fl_start_address = (GFX_MGR02_GRAM_BASE+(GFX_MGR02_GRAM_SIZE/2));
   }
#endif

#if ((GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN) || defined(GFX_MGR02_USE_OPTIMAL_EDMA_SIZE))
   if((p_size_bytes & (GFX_MGR02_DCU_EDMA_TXFR_32BYTES-1)) != 0)
   {
      /*
      ** Align the number of bytes to a 32byte boundary
      ** incase it is not aligned
      */
      p_size_bytes &= (UINT32)~(GFX_MGR02_DCU_EDMA_TXFR_32BYTES-1);
      p_size_bytes += GFX_MGR02_DCU_EDMA_TXFR_32BYTES;
   }
#else
   if((p_size_bytes & (GFX_MGR02_DCU_EDMA_TXFR_8BYTES-1)) != 0)
   {
      /*
      ** Align the number of bytes to a 8byte/64bit boundary
      ** incase it is not aligned
      */
      p_size_bytes &= (UINT32)~(GFX_MGR02_DCU_EDMA_TXFR_8BYTES-1);
      p_size_bytes += GFX_MGR02_DCU_EDMA_TXFR_8BYTES;
   }
#endif
   
   fl_next_alloc_gram->size    = 0;
   fl_next_alloc_gram->address = 0;
   fl_next_alloc_gram->status  = GFX_MGR02_GRAM_CHUNK_STS_NONE;

#if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
   if((l_next_gram_alloc_size + p_size_bytes) < GFX_MGR02_GRAM_SIZE)
#else
   if((l_next_gram_alloc_size + p_size_bytes) < (GFX_MGR02_GRAM_SIZE/2))
#endif
   {
      if(p_size_bytes != 0)
      {
      #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
         if(l_cur_front_buffer_loc != 0)
         {
            fl_next_alloc_gram->address  = fl_start_address;
            fl_next_alloc_gram->address += l_next_gram_alloc_size;
            l_next_gram_alloc_size      += p_size_bytes;
         }
         else
         {
            l_next_gram_alloc_size      += p_size_bytes;
            fl_next_alloc_gram->address  = fl_start_address;
            fl_next_alloc_gram->address -= l_next_gram_alloc_size;
         }
      #else
         fl_next_alloc_gram->address  = fl_start_address;
         fl_next_alloc_gram->address += l_next_gram_alloc_size;
         l_next_gram_alloc_size      += p_size_bytes;
      #endif
      #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
         if(l_cur_gram_alloc_size > 0)
         {
            if((l_next_gram_alloc_size + l_cur_gram_alloc_size) > GFX_MGR02_GRAM_SIZE)
            {
               /*
               ** GRAM allocation is overlapping with existing usage
               ** so we cannot perform a clear GRAM operation from here.
               ** we will keep this pending and do it from the vblank period
               */
               fl_next_alloc_gram->status = GFX_MGR02_GRAM_CHUNK_STS_OVERLAP;
            }
         }
      #endif
         if((fl_next_alloc_gram->status == GFX_MGR02_GRAM_CHUNK_STS_NONE)/* && (p_size_bytes != 0)*/) /* QA C warning fix for Honda Thaa */
         {
            fl_next_alloc_gram->status = GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED;
         }
         fl_next_alloc_gram->size = p_size_bytes;
      }
   }
   else
   {
      /*
      ** Memory overflow error.
      */
      l_next_gram_alloc_size += p_size_bytes;
   #ifdef GFX02_DEBUG_ERROR
      gfx_debug("ERROR   - There is not enough memory to build elements. Total size exceeded GFX_MGR02_GRAM_SIZE\n");
   #endif
   }
   return(fl_next_alloc_gram->status);
}

/*============================================================================
**
** Function Name:       hmi_gfx_mgr02_get_size_for_bpp
**
** Visibility:          Local to hmi_gfx_manager
**
** Description:         When allocating graphics RAM, an 8BPP per pixel
**                      image needs 1 byte (i.e. 8 bits) to store one pixel.
**                      A 4BPP images can store two pixels in one byte, and
**                      so on.  This function is used to calculate the
**                      actual size of graphics RAM that needs to be allocated
**                      based on the number of pixels (i.e. the "size") and
**                      the BPP.
**
** Invocation:          Invoked by any function that is going to allocate
**                      graphics RAM prior to doing so.
**
** Inputs/Outputs:      The "bpp" parameter is the BPP and encoding type
**                      of the object that will be placed in graphics RAM.
**
**                      The "size" parameter is the number of pixels (i.e. the
**                      "size") needed.
**
** Critical Section:    None
** Created:             18/01/12 by ASHEKHAR
** Updated:             18/01/12 by ASHEKHAR
**==========================================================================*/
UINT32 hmi_gfx_mgr02_get_size_for_bpp(UINT32 bpp, UINT32 size, UINT32 alignment)
{
   UINT32 adjusted_size = size;

   switch(bpp)
   { 
      case GFX_MGR02_1BPP:
      {
         adjusted_size >>= 3;
         break;
      }
      case GFX_MGR02_2BPP:
      {
         adjusted_size >>= 2;
         break;
      }
      case GFX_MGR02_4BPP:
      case GFX_MGR02_4BPP_TRANSPARENCY:
      case GFX_MGR02_4BPP_LUMINANCE:
      {
         adjusted_size >>= 1;
         break;
      }
      case GFX_MGR02_16BPP_RGB565:
      case GFX_MGR02_16BPP_ARGB1555:
      case GFX_MGR02_16BPP_ARGB4444:
      case GFX_MGR02_16BPP_APAL8:
      {
         adjusted_size <<= 1;
         break;
      }
      case GFX_MGR02_24BPP:
      {
         adjusted_size  *= 3;
         break;
      }
      case GFX_MGR02_32BPP:
      {
         adjusted_size <<= 2;
         break;
      }
      case GFX_MGR02_8BPP:
      case GFX_MGR02_8BPP_TRANSPARENCY:
      case GFX_MGR02_8BPP_LUMINANCE:
      default:
      {
    	  /*For MISRA warning fix.*/
      }
      break;
   }
   /*
   ** Adjust the size to multiples of 64bit for effective DMA transfer
   */
   if(alignment != FALSE)
   {
      if((adjusted_size % 8u) != 0u)
      {
         adjusted_size = (adjusted_size + 8u) - (adjusted_size % 8u);
      }
   }
   return(adjusted_size);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_memcpy_64bit (reference from freescale library)
 ** Visibility:       static
 ** Description:      This function performs a 64bit aligned memcopy using DMA.
 ** Invocation:       Invoked when ever needed. After invokation the caller
 **                   needs to perform DMA_Start(GFX_MGR02_DMA_CHANNEL) to
 **                   initiate the transfer.
 ** Inputs/Outputs:   in  - source, destination and num of bytes to copy.
 **                   out - DMA_ERROR_OK if request was successful
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_memcpy_64bit(UINT32 p_source_addr,
                                  UINT32 p_dest_addr,
                                  UINT32 p_size_bytes)
{
    dma_handler_type fl_dma_parameters;
    UINT32           fl_error;

    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_MEM_1)
    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32         = p_source_addr;
    fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32    = p_dest_addr;
    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16          = (DMA_SR_ALWAYS_ENB_0+GFX_MGR02_DMA_CHANNEL);
    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E      = DMA_MUX_ALWAYS_ENB_REQUEST;
#ifdef GFX_MGR02_USE_OPTIMAL_EDMA_SIZE
    if((p_size_bytes & (GFX_MGR02_DCU_EDMA_TXFR_32BYTES-1)) == 0)
    {
       fl_dma_parameters.dma_drv_channel_parameters.source_size_E           = SIZE_32BYTE;
       fl_dma_parameters.dma_drv_channel_parameters.destination_size_E      = SIZE_32BYTE;
       fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16       = GFX_MGR02_DCU_EDMA_TXFR_32BYTES;
       fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16  = GFX_MGR02_DCU_EDMA_TXFR_32BYTES;
    }
    else
#endif
    {
       fl_dma_parameters.dma_drv_channel_parameters.source_size_E           = SIZE_4BYTE;
       fl_dma_parameters.dma_drv_channel_parameters.destination_size_E      = SIZE_4BYTE;
       fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16       = 4;
       fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16  = 4;
    }
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32       = p_size_bytes;      
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32      = 0;     
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8   = 0; 
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8  = 0;
    fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16       = 1;
    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32 = 0;
    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32   = 0;  
    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8          = (UINT8)GFX_MGR02_EDMA_BWC_BG_RENDERING;        
    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8      = 1;
    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8   = 1;
    fl_dma_parameters.dma_channel_num                                       = (dma_channel_num_type)GFX_MGR02_DMA_CHANNEL;
    fl_dma_parameters.dma_callback                                          = hmi_gfx_mgr02_dma_complete_cb;
    fl_error = DMA_Handler_InitiateRequest(&fl_dma_parameters);
    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_MEM_3)
    return(fl_error);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_front_buffer_index
 ** Visibility:       static
 ** Description:      This function checks if the passed element p_elem_list_SP
 **                   is already active in front buffer. If active then returns
 **                   its index in l_cur_gram_alloc_table or else returns
 **                   GFX_MGR02_NUM_DCU_LAYERS
 ** Invocation:       Invoked by hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   in  - 1. next (back buffer) element to be looked up in current
 **                            (front) buffer.
 **                         2. Index of next element in the l_next_gram_alloc_table[]
 **                   out - GFX_MGR02_NUM_DCU_LAYERS if the element was not found in
 **                         l_cur_gram_alloc_table[] / front buffer, meaning the
 **                         element is not active currently OR a valid index indicating
 **                         element in the current buffer.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_get_front_buffer_index(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_cur_elem_index)
{
    UINT32 fl_front_buffer_index = GFX_MGR02_NUM_DCU_LAYERS;
    UINT32 i;
    GFX_MGR02_CONTROL_DATA_T *  fl_ctrl_data_SP = hmi_gfx_mgr02_get_control_data_ptr();

    for(i=0; (i < l_cur_gram_alloc_layers) && (fl_front_buffer_index == GFX_MGR02_NUM_DCU_LAYERS); i++)
    {
        /*
        ** Element is already built.
        */
        if(p_elem_list_SP == fl_ctrl_data_SP->cur_elem_list_sa[i])
        {
            if((l_cur_gram_alloc_table[i].address != 0) &&
                (l_next_gram_alloc_table[p_cur_elem_index].size == l_cur_gram_alloc_table[i].size) &&
                (l_cur_gram_alloc_table[i].status == GFX_MGR02_GRAM_CHUNK_STS_ACTIVE))
            {
                fl_front_buffer_index = i;
            }
        }
    }
    
    return(fl_front_buffer_index);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_copy_front_to_back_buffer
 ** Visibility:       static
 ** Description:      This function copies the front buffer content in to the
 **                   backbuffer
 ** Invocation:       Invoked by hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_copy_front_to_back_buffer(UINT32 p_front_buffer_index, UINT32 p_back_buffer_index)
{
    UINT32 fl_dest_addr    = l_next_gram_alloc_table[p_back_buffer_index].address;
    UINT32 fl_base_address = l_cur_gram_alloc_table[p_front_buffer_index].address;
    UINT32 i;
    UINT32 fl_process_mode;
    UINT32 fl_ret_sts        = FALSE;
    UINT32 fl_base_chunk_sts = l_cur_gram_alloc_table[p_front_buffer_index].status;
    UINT32 fl_dest_chunk_sts = l_next_gram_alloc_table[p_back_buffer_index].status;
    SINT32 fl_elem_size      = l_next_gram_alloc_table[p_back_buffer_index].size;
    /*
    ** no update required, so copy from the cur base to new base
    ** Copy possible only if the dest buffer doesn't overlap with other buffers 
    ** or if the buffer is allocated
    */
    if((fl_dest_addr      != 0) && 
       (fl_dest_chunk_sts != GFX_MGR02_GRAM_CHUNK_STS_OVERLAP) &&
       (fl_base_chunk_sts == GFX_MGR02_GRAM_CHUNK_STS_ACTIVE))
    {
        if(fl_elem_size > 0)
        {
           if((fl_elem_size & (GFX_MGR02_BYTES_IN_64BIT-1uL)) != 0)
           {
              /*
              ** Element size is not in multiple of 64bits error
              ** This condition should never happen, so this code is
              ** added as per defensive coding practice.
              */
              fl_elem_size &= (UINT32)(~(GFX_MGR02_BYTES_IN_64BIT-1uL));
           #ifdef GFX02_DEBUG_ERROR
              gfx_debug("ERROR   - GRAM Size not aligned to 64bits error\n");
           #endif
           }

           fl_process_mode = hmi_gfx_mgr02_get_process_mode();

           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_MEM_4)
           while((hmi_gfx_mgr02_is_emergency_shutdown_req_active() != GFX_MGR02_SHUTDOWN_EMERGENCY) && 
                 (fl_elem_size > 0x00) && (fl_process_mode != GFX_MGR02_PMODE_IDLE))
           {
               /*
               ** Perform CPU copy if DMA is busy
               ** Perform GFX_MGR02_CPU_COPY_MAX_WORDS units a time with CPU
               ** and check for DMA availability. If DMA is available then
               ** break the loop and use DMA to perform remaining bytes.
               */
               for( i=0;
                    (i < GFX_MGR02_CPU_COPY_MAX_WORDS) && (fl_elem_size > 0x00); i++)
               {
                   GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_MEM_5)
                   *((UINT32 *)fl_dest_addr) = *((UINT32 *)fl_base_address);
                   fl_base_address += 4;
                   fl_dest_addr    += 4;
                   fl_elem_size    -= 4;
               }
               fl_process_mode = hmi_gfx_mgr02_get_process_mode();
           }
           if((hmi_gfx_mgr02_is_emergency_shutdown_req_active() != GFX_MGR02_SHUTDOWN_EMERGENCY) && (fl_elem_size != 0x00))
           {
               hmi_gfx_mgr02_set_process_mode(GFX_MGR02_PMODE_SWAP_GRAM);
               if(hmi_gfx_mgr02_memcpy_64bit(fl_base_address,
                                             fl_dest_addr,
                                             fl_elem_size) == DMA_NO_ERROR)
               {
                  GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_MEM_6)
                  l_next_gram_alloc_table[p_back_buffer_index].status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
               }
               else
               {
                  /* DMA transfer request failed */
                  hmi_gfx_mgr02_set_process_mode(GFX_MGR02_PMODE_IDLE);
               }
           }
           else
           {
               l_next_gram_alloc_table[p_back_buffer_index].status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
           }
        }
        fl_ret_sts = TRUE;
    }
    return(fl_ret_sts);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_swap_backbuff_to_frontbuff
 ** Visibility:       static
 ** Description:      This function makes the next buffer as current at the
 **                   end of pre-render loop.
 ** Invocation:       Invoked by hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_swap_backbuff_to_frontbuff(void)
{
    UINT32 i;
    for(i=0; i < l_next_gram_alloc_layers; i++)
    {
        /*
        ** Pre render operations are completed, so make the next gram address
        ** the current so that the render loop can start building in to the
        ** new gram locations.
        */
        l_cur_gram_alloc_table[i].address = l_next_gram_alloc_table[i].address;
        l_cur_gram_alloc_table[i].size    = l_next_gram_alloc_table[i].size;
        l_cur_gram_alloc_table[i].status  = l_next_gram_alloc_table[i].status;
    }
    l_cur_gram_alloc_size   = l_next_gram_alloc_size;
    l_cur_gram_alloc_layers = l_next_gram_alloc_layers;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_dma_complete_cb
 ** Visibility:       local
 ** Description:      Used to restart the pre-render loop after DMA transfer is completed.
 ** Invocation:       hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          27-Feb-2012 by ASHEKHAR
 ** Updated:          27-Feb-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_dma_complete_cb(dma_handler_app_resp_struct * p_app_resp_S)
{
   GFX_MGR02_UNUSED_PTR(p_app_resp_S);
   hmi_gfx_mgr02_set_process_mode(GFX_MGR02_PMODE_IDLE);
}

#endif /* GFX_MGR02_KEPLER */
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
 ** CMS Rev 1.16     22-Aug-2015    APERUMAL
 ** RTC#405974
 ** QAC warnings fix for Honda Thaa
 **
 ** CMS Rev 1.15     13-Feb-2015    EMANOJ1
 ** Rtc#265549 : handled a case where the memory allocation got cancelled due to
 ** no changes in next update. In this case l_next_gram_alloc_size is loaded
 ** with current allocation size so that l_act_gram_alloc_size is not getting
 ** overwritten with wrong value (hmi_gfx_mgr02_mem_cancel_alloc).
 ** 
 ** CMS Rev 1.14     07-Jan-2015    EMANOJ1
 ** Rtc#265549 : Workbuffer allocation was calculation more free memory because
 ** the current memory usage in l_cur_gram_alloc_size was overwritten with
 ** l_next_gram_alloc_size. Ideally this copy could have been done after the
 ** next buffer is swapped at TFT level. But this was done much before and the 
 ** free memory calculation went wrong. Since changing of the swapp to its correct
 ** place will have a lot of impact to current software path.. decided to introduce 
 ** another variable to fix this issue quickly without much impact to existing 
 ** software.
 **
 ** CMS Rev 1.13     30-Sep-2014    EMANOJ1
 ** hmi_gfx_mgr02_mem_alloc updated align the size to 32bytes when 
 ** GFX_MGR02_USE_OPTIMAL_EDMA_SIZE option is enabled to fix a eDMA error due
 ** to non-aligned memory while performing hmi_gfx_mgr02_memcpy_64bit
 **
 ** CMS Rev 1.12     07-Jan-2014    EMANOJ1
 ** hmi_gfx_mgr02_mem_alloc modified to consider only half the memory incase of
 ** GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN
 **
 ** CMS Rev 1.11     17-Dec-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_get_size_for_bpp to fix issue in size calculation
 ** hmi_gfx_mgr02_memcpy_64bit() updated to have an option to perform 32byte
 ** DMA transfers.
 **
 ** CMS Rev 1.10     27-Aug-2013    EMANOJ1
 ** Updated to support the infrastructure DMA manager core package instead of the
 ** freescale DMA.c
 **
 ** CMS Rev 1.9      19-Jun-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_copy_front_to_back_buffer to make sure the copy happens
 ** only if the source buffer is active (built).
 **
 ** CMS Rev 1.8      18-Jun-2013    EMANOJ1
 ** Reworked pre-render, memory allocation operations to makesure we don't 
 ** rebuild GRAM contents if the change is in the parent which can be applied
 ** directly to DCU layers example if the position of the parent objects
 ** changes, it need not be rebuilt again we could just program the DCU layers 
 ** to make the operations faster.
 **
 ** CMS Rev 1.7      06-Jun-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_manage_virtual_layer_gram to utilize the text width
 ** calculated during the manage layer phase rather than doing the calculations
 ** again.
 **
 ** CMS Rev 1.6      29-May-2013    EMANOJ1
 ** Fixed unit testing issues in hmi_gfx_mgr02_get_workbuffer
 **
 ** CMS Rev 1.5      23-May-2013    EMANOJ1
 ** Added hmi_gfx_mgr02_get_workbuffer() function to support horizontal clipping
 ** of images inside widget.
 ** 
 ** CMS Rev 1.4      22-Mar-2013    VMUTHUSU
 ** Change NULL_PTR to GFX_MGR02_NULL_PTR
 **
 ** CMS Rev 1.3      10-Dec-12      ASHEKHAR
 ** Updated based on the discussion for emergency shutdown strategy.
 **
 ** CMS Rev 1.2      10-Jul-12      EMANOJ1
 ** Updated based on the BPP_and_encoding type definitions changes in 
 ** hmi_gfx_mgr02_types.h
 **
 ** CMS Rev 1.1      27-Jan-2012    ASHEKHAR
 **
 ** CMS Rev 1.0      05-May-2011    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
