/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2016. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_amber_mem_mgmt.c
 **
 ** Description:
 **
 **
 **============================================================================
 **
 **==========================================================================*/
 /*============================================================================
  ** I N C L U D E   F I L E S
  **==========================================================================*/
#include "hmi_gfx_mgr02_amber_mem_mgmt.h"
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
#ifdef GFX02_DEBUG_INFO
#ifdef WIN32
#include <stdio.h>
#endif
#include <stdlib.h>
#endif
#include <string.h>
#include "mml_gdc_driver_api.h"
#include "ut_memman.h"
#include "ut_compatibility.h"
#if defined(GFX_MGR02_TRAVEO2)
#include "ut_compat.h"
#endif
#if defined(GFX_MGR02_USER_DEFINED_MM)
#include "hmi_gfx_mgr02_mem_config.h"
#endif
#include "hmi_gfx_mgr02_mem_mgmt.inc"
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
extern char __ghsbegin_gfx02_workbuff_start[];
extern char __ghsend_gfx02_workbuff_end[];
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)

  /*============================================================================
   ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
   **==========================================================================*/
  static MM_U32 hmi_gfx_mgr02_get_extram_size(void);

  /*============================================================================
   ** M E M O R Y   A L L O C A T I O N
   **==========================================================================*/
  static MML_MMAN_HEAP_HANDLE g_heapHandle_HRAM = (MML_MMAN_HEAP_HANDLE)NULL;

  /*============================================================================
   ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
   **==========================================================================*/


   /****************************************************************************
   Function Name        : hmi_gfx_mgr02_get_extram_size()
   Description          : Initializes internal data for first tme use
   Invocation           : When ever generic context needs to be initialized
   Return Value         : None
   Critical Section     : None
   Parameters           : None
   ******************************************************************************/
  static MM_U32 hmi_gfx_mgr02_get_extram_size(void)
  {
    return ((MM_U32)__ghsend_gfx02_workbuff_end - (MM_U32)__ghsbegin_gfx02_workbuff_start);
  }
#endif  
  /****************************************************************************
  Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_init()
  Description          : Initializes internal data for first tme use
  Invocation           : When ever generic context needs to be initialized
  Return Value         : None
  Critical Section     : None
  Parameters           : None
  ******************************************************************************/
  MM_ERROR hmi_gfx_mgr02_amber_mem_mgmt_init(void)
  {
    MM_ERROR fl_ret;
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
    MM_U32 fl_dynamic_HRAM_Size_U32 = hmi_gfx_mgr02_get_extram_size();
    MM_U32 fl_dynamic_HRAM_baseAddress_U32 = (MM_U32)__ghsbegin_gfx02_workbuff_start;
#endif  

    fl_ret = utMmanReset();    /*VRAM Initialization.*/
#if defined(GFX_MGR02_USER_DEFINED_MM)
    if (fl_ret == MML_OK)
    {
      fl_ret = utMmanInit(); /*Partition in VRAM for Freetype2 ext font engine*/
    }
#endif
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
    if ((fl_dynamic_HRAM_Size_U32 > (MM_U32)0) && (fl_ret == MML_OK))
    {
      if (g_heapHandle_HRAM != NULL)
      {
        (void)utMmanDestroyHeap(g_heapHandle_HRAM);
        g_heapHandle_HRAM = (MML_MMAN_HEAP_HANDLE)NULL;
      }
      fl_ret = utMmanCreateHeap(&g_heapHandle_HRAM, fl_dynamic_HRAM_Size_U32, fl_dynamic_HRAM_baseAddress_U32);
      if (fl_ret != MML_OK)
      {
#ifdef GFX02_DEBUG_INFO
        (void)printf("utMmanReset: utMmanCreateHeap failed to create HRAM heap(0x%08x)\n", fl_ret);
#endif
      }
    }
#endif  
    return fl_ret;
  }

  /****************************************************************************
  Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_malloc()
  Description          : Initializes internal data for first tme use
  Invocation           : When ever generic context needs to be initialized
  Return Value         : void * on sucess and NULL if can't able to allocate requested memory.
  Critical Section     : None
  Parameters           : IrisMemInfo
  ******************************************************************************/
  void* hmi_gfx_mgr02_amber_mem_mgmt_malloc(const IrisMemInfo* p_meminfo)
  {
    MM_ADDR* fl_ret_ptr = (MM_ADDR*)0;
    if ((p_meminfo->MemCateg == IRIS_WIDGET_FRONT_RENDER_BUFFER) ||
      (p_meminfo->MemCateg == IRIS_WIDGET_BACK_RENDER_BUFFER))
    {
      if (p_meminfo->WidgetClientId < GFX_NUM_OF_FB_GROUPS)
      {
        void* fl_current_fb = hmi_gfx_mgr02_layout_get_front_fb(p_meminfo->WidgetClientId);
        if (fl_current_fb != NULL)
        {
          if (fl_current_fb == lc_fb_groups_SA[p_meminfo->WidgetClientId].fb[0])
          {
            fl_ret_ptr = lc_fb_groups_SA[p_meminfo->WidgetClientId].fb[1];
          }
          else if (fl_current_fb == lc_fb_groups_SA[p_meminfo->WidgetClientId].fb[1])
          {
            fl_ret_ptr = lc_fb_groups_SA[p_meminfo->WidgetClientId].fb[0];
          }
        }
        else
        {
          fl_ret_ptr = lc_fb_groups_SA[p_meminfo->WidgetClientId].fb[0];
        }
        return fl_ret_ptr;
      }
    }

    if (p_meminfo->ExtMemory == (UINT8)0)
    {
      fl_ret_ptr = mmlGdcVideoAlloc(p_meminfo->Size, p_meminfo->Alignment, NULL);
    }
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
    else
    {
      MM_ADDR ulRet = (MM_ADDR)0;
      if (MML_OK != utMmanHeapAlloc(g_heapHandle_HRAM, p_meminfo->Size, p_meminfo->Alignment, &ulRet))
      {
#ifdef GFX02_DEBUG_INFO
        (void)printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_malloc: failed to allocate %d bytes\n", p_meminfo->Size);
#endif
        ulRet = (MM_ADDR)0;
      }
      fl_ret_ptr = (MM_ADDR*)ulRet;
    }
#endif
    return fl_ret_ptr;
  }


  /****************************************************************************
  Function Name        : void hmi_gfx_mgr02_amber_mem_mgmt_free()
  Description          : Initializes internal data for first tme use
  Invocation           : When ever generic context needs to be initialized
  Return Value         : None
  Critical Section     : None
  Parameters           : None
  ******************************************************************************/
  void hmi_gfx_mgr02_amber_mem_mgmt_free(void* pAddr)
  {
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)    
    MM_U32 fl_start_addr = (MM_U32)__ghsbegin_gfx02_workbuff_start;
    MM_U32 fl_end_addr = (MM_U32)__ghsend_gfx02_workbuff_end;
    if (((MM_U32)((MM_ADDR*)pAddr) >= fl_start_addr) && ((MM_U32)((MM_ADDR*)pAddr) <= fl_end_addr))
    {
      MM_ERROR ret;
      ret = utMmanHeapFree(g_heapHandle_HRAM, pAddr);
      if (ret != MML_OK)
      {
#ifdef GFX02_DEBUG_INFO
        (void)printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_free: failed to free memory at %p!\n", pAddr);
#endif 
      }
    }
    else
#endif  
    {
      mmlGdcVideoFree(pAddr);
    }
  }

#ifdef  __cplusplus
}
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
 ** CMS Rev 1.2     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.1      16-Aug-2017    SSIGAMAN
 ** 908966: Static allocation of VRAM required.
 ** Modified the files inorder to support user to allocate the required memories
 ** widget rendering and memory required for Draw engine and widget warping.
 **
 ** CMS Rev 1.0      23-Nov-2016    SBOLLAM/APERUMAL
 ** This file is added to provide interfaces to allocate memory in VRAM / HRAM
 **==========================================================================*/

 /* end of file =============================================================*/

