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
 ** Name:           hmi_gfx_mgr02_perflog.c
 **
 ** Description:    Implements the performance matrics collection routines.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_PERFLOG_C

/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_perflog.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef GFX_MGR02_ENABLE_LOG

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

GFX_TCOUNT_TYPE l_gfxlog_scnt[GFX_LOG_MAX_NUM];
GFX_TCOUNT_TYPE l_gfxlog[GFX_LOG_MAX_NUM];
GFX_TCOUNT_TYPE l_gfxlogmax[GFX_LOG_MAX_NUM];
GFX_TCOUNT_TYPE l_gfxlogmin[GFX_LOG_MAX_NUM];
GFX_DOUBLE l_fps;
GFX_DOUBLE l_processing_us;
GFX_DOUBLE l_rendering_us;
GFX_DOUBLE l_dirty_area_processing_us;
GFX_DOUBLE l_swap_buffer_us;
#ifdef GFX_MGR02_KEPLER
GFX_DOUBLE l_dcu_overall_us;
GFX_DOUBLE l_dcu_processing_us;
GFX_DOUBLE l_dcu_rendering_us;
GFX_DOUBLE l_dcu_openvg_us;
GFX_DOUBLE l_dcu_edma_us;
GFX_DOUBLE l_dcu_multicolor_us;
GFX_DOUBLE l_dcu_isr_us;
GFX_DOUBLE l_dcu_offscrn_cpy_us;
GFX_DOUBLE l_dcu_edma_isr_us;
#endif

#define GFX_MGR02_FPS_HIS_NB (0x0F)
UINT32 l_fps_his_index;
UINT32 l_fps_his_count;
GFX_DOUBLE l_fps_his[GFX_MGR02_FPS_HIS_NB+1];
GFX_DOUBLE l_avg_fps;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxloginit(void)
{
   UINT32 i;
   for(i=0;i<GFX_LOG_MAX_NUM;i++)
   {
	  l_gfxlogmax[i] = 0;
	  l_gfxlogmin[i] = (GFX_TCOUNT_TYPE)(-1);
   }
   l_fps_his_index = 0;
   l_fps_his_count = 0;
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxlogstart(UINT32 id)
{
   if(id < GFX_LOG_MAX_NUM)
   {
      l_gfxlog[id]       = 0;
      l_gfxlog_scnt[id]  = GFX_TCOUNT;
   }
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxlogend(UINT32 id)
{
   if(id < GFX_LOG_MAX_NUM)
   {
      l_gfxlog_scnt[id] = (GFX_TCOUNT-l_gfxlog_scnt[id]);
      l_gfxlog[id]     += l_gfxlog_scnt[id];
      if(l_gfxlog[id] > l_gfxlogmax[id])
      {
         l_gfxlogmax[id] = l_gfxlog[id];
      }
      if(l_gfxlog[id] < l_gfxlogmin[id])
      {
         l_gfxlogmin[id] = l_gfxlog[id];
      }
   }
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxlogstop(UINT32 id)
{
   if(id < GFX_LOG_MAX_NUM)
   {
      gfxlogend(id);
   }
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxlogcontinue(UINT32 id)
{
   l_gfxlog_scnt[id] = GFX_TCOUNT;
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void gfxlogupdate(void)
{
   UINT32 i;

   l_fps                       = ((GFX_DOUBLE)GFX_TCOUNT_HZ)/((GFX_DOUBLE)(l_gfxlog[GFX_LOG_OVERALL]));
   l_processing_us             = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_PROCESSING]            * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_rendering_us              = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_RENDERING]             * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dirty_area_processing_us  = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DIRTY_AREA_PROCESSING] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_swap_buffer_us            = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_SWAP_BUFFER]           * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
#ifdef GFX_MGR02_KEPLER
   l_dcu_overall_us     = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_OVERALL]    * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_processing_us  = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_PROCESSING] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_rendering_us   = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_RENDERING]  * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_openvg_us      = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_OPENVG]     * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_edma_us        = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_EDMA]       * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_multicolor_us  = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_MULTICOLOR] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_isr_us         = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_ISR] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_offscrn_cpy_us = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_OFFSCRN_CPY] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
   l_dcu_edma_isr_us    = ((GFX_DOUBLE)l_gfxlog[GFX_LOG_DCU_EDMA_ISR] * 1000000.0)/(GFX_DOUBLE)GFX_TCOUNT_HZ;
#endif

   l_fps_his[l_fps_his_index] = l_fps;
   l_fps_his_index++;
   l_fps_his_index &= GFX_MGR02_FPS_HIS_NB;
   if(l_fps_his_count <= GFX_MGR02_FPS_HIS_NB)
   {
      l_fps_his_count++;
   }
   for(i=0; i < l_fps_his_count; i++)
   {
      l_avg_fps += l_fps_his[i];
   }
   l_avg_fps /= (GFX_DOUBLE)i;
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
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 **
 ** CMS Rev 1.1      17-Dec-2013    EMANOJ1
 ** More metrics added for DCU
 **
 ** CMS Rev 1.0      09-May-2013    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
