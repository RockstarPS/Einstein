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
 ** Name:           hmi_gfx_mgr02_imxrt_mem_mgmt.c
 **
 ** Description:    This file has to be maintained by application. Application can 
 **					return the memory allocated based on memory available in
 **					hardware like OCRAM/SDRAM
 **============================================================================
 **
 **==========================================================================*/
/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#include "panel_definition_imxrt.h"
#include "hmi_gfx_mgr02_imxrt_mem_mgmt.h"
#if defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
#ifdef GFX02_DEBUG_INFO
  #ifdef WIN32
    #include <stdio.h>
  #endif
#include <stdlib.h>
#endif
#include <string.h>
#include "fsl_common.h"

#define FRAME_BUFFER_ALIGN 32
AT_NONCACHEABLE_SECTION_ALIGN(static uint32_t l_imxrt_pxp_fb_info_s[2][DEMO_BUFFER_HEIGHT][DEMO_BUFFER_WIDTH], FRAME_BUFFER_ALIGN);

#define IMXRT_PXP_DYNAMIC_ALLOC
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_imxrt_mem_mgmt_init(void)
{

    


}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_malloc()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : void * on sucess and NULL if can't able to allocate requested memory.
Critical Section     : None
Parameters           : IrisMemInfo
******************************************************************************/
void* hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(PixEngMemInfo * p_meminfo)
{
  void * fl_ret_ptr = NULL; 
  #ifdef IMXRT_PXP_DYNAMIC_ALLOC
  fl_ret_ptr = SDK_Malloc(p_meminfo->Size, p_meminfo->Alignment);
  #else
  if(p_meminfo->MemCateg == IMXRT_FRONT_RENDER_BUFFER)
  {
	fl_ret_ptr =  &l_imxrt_pxp_fb_info_s[0];
  }
  else
  {
    fl_ret_ptr =  &l_imxrt_pxp_fb_info_s[1];
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
void hmi_gfx_mgr02_imxrt_mem_mgmt_free(void* pAddr)
{
	SDK_Free(pAddr);
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
 ** CMS Rev 1.0     21-May-2021    CSAKTHIV
 ** 
 ** Initial version for IMXRT 
 **
 **==========================================================================*/

/* end of file =============================================================*/

