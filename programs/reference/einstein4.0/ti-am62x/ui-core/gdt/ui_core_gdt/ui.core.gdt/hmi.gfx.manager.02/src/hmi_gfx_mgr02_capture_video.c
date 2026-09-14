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
 ** Name:           hmi_gfx_mgr02_capture_video.c
 **
 ** Description:    This module contains the Video driver initialization/shutdown
 **                 
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_CAPTURE_VIDEO_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED)
	#if defined(GFX_MGR02_TRAVEO2)
		#include "cygfx_capture.h"
        #include "ut_compat.h"
	#else
		#include "mml_gdc_capture.h"
	#endif
#if defined(GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2)
#include "cy_mipicsi2.h"
#include "cy_device_headers.h"
#include "cy_project.h"
#endif
#include "hmi_gfx_mgr02_amber_mem_mgmt.h"
#include "hmi_gfx_mgr02_capture_video.h"
#include "hmi_gfx_mgr02_capture_video.dat"

#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
#include "ut_capringbuffer.h"
#endif

#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
#include "ut_compatibility.h"
#endif

typedef enum
{
    GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS  = 0,
    GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE,
    GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS,
    GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE,
    GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE,
    GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
} GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS;
#if ((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
static UINT8                   l_gfx_mgr02_video_mode_status = FALSE;
#endif
static MML_GDC_CAP_CTX         l_capCtx = GFX_MGR02_NULL_PTR;
static MML_GDC_SYNC_CONTAINER  l_sync_c;
static MML_GDC_SYNC            l_capSync = &l_sync_c;
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS l_cap_init_status = GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE;


#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
static MML_GDC_SURFACE         l_capSurf[GFX_MGR02_CAPTURE_BUFFERS_COUNT];
#define  GFX_MGR02_MAX_CAPTURE_BUFFERS_COUNT    3
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_capture_to_surf_memory_allocation(GFX_MGR02_VIDEO_DEF_T const* p_video_def);
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS  hmi_gfx_mgr02_capture_to_surf_start_capture(void);
#endif   

#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
static void        *ringBufferVirt = 0;
/* Ring buffer size saved to avoid recalculations 
   In future if window scaling feature is implemented then ring buffer size need 
   to be calculated everytime during window_init */
   static MM_U32      l_ringBufferSize = 0;
   static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_capture_to_win_memory_allocation(MML_GDC_DISP_MODE_LINE* p_modeline_param, GFX_MGR02_VIDEO_DEF_T p_video_def);
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
/* Initial compression percent is 100 i.e no compression */
#define GFX_MGR02_INITIAL_COMPRESSION_PERCENT      100
/* Maximum compression percentage is 50%. Compressing more than 50% of the buffer will be complete lossy one. */
#define GFX_MGR02_MAX_COMPRESSION_PERCENT          50
/* Compression percent increased from no compression in steps of 5 */
#define GFX_MGR02_COMPRESSION_REDUCTION_PERCENT    5
  #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
  static MM_ERROR hmi_gfx_mgr02_compress_RGB_capture_buffer(MML_GDC_SURFACE surf, MM_U32 w, MM_U32 h, MML_GDC_SURF_FORMAT eFormat, MM_U32* ReqSizeInBytes);
  #endif
#endif
#ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
static const cy_stc_sysint_irq_t l_irq_cfg = 
{
    .sysIntSrc  = videoss_0_interrupt_mipicsi_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true
};
static void hmi_gfx_mgr02_capture_video_mipi_cs2_init(void);
static void hmi_gfx_mgr02_capture_video_mipi_cs2_deinit(void);
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_open_capture_unit(void);
#ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
static UINT8 l_mipi_init_done = 0;
#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
static UINT8 l_mipi_mem_init_done = 0;
#endif
void hmi_gfx_mgr02_mipicsi2_interrupt_handler(void);
static void hmi_gfx_mgr02_mipicsi2_set_interrupt(void);
#endif
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
/*============================================================================
** Function Name:       hmi_gfx_mgr02_capture_video_init(void)
** Visibility:          Graphics Manager.
** Description:         Interface to initialise the video capture module
** Invocation:          By hmi_gfx_mgr02_layout_initialize
** Inputs/Outputs:      void 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void hmi_gfx_mgr02_capture_video_init(void)
{
    #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
    UINT8 fl_buf_index;
    for(fl_buf_index = 0; fl_buf_index < GFX_MGR02_CAPTURE_BUFFERS_COUNT; fl_buf_index++)
    {
    l_capSurf[fl_buf_index] = GFX_MGR02_NULL_PTR;
    }
    #endif

  #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
    ringBufferVirt = 0;
  #endif
#if ((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
    l_gfx_mgr02_video_mode_status = FALSE; 
#endif
    l_capCtx = GFX_MGR02_NULL_PTR;
}

#ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
static void hmi_gfx_mgr02_capture_video_mipi_cs2_init(void)
{
    hmi_gfx_mgr02_mipicsi2_set_interrupt();
    (void)Cy_Mipicsi2_Init(VIDEOSS0_MIPICSI0, &stcCfg);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsActiveChange, true);
    Cy_Mipicsi2_SetInterruptMask(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange, true);
}
static void hmi_gfx_mgr02_capture_video_mipi_cs2_deinit(void)
{
    Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0,Mipicsi2IrqErrorCrc);
    Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0,Mipicsi2IrqErrorEccSingle);
    Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0,Mipicsi2IrqErrorEccDouble);
    Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0,Mipicsi2IrqStatusUlpsActiveChange);
    Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0,Mipicsi2IrqStatusUlpsMarkActiveChange);
    Cy_Mipicsi2_DeInit(VIDEOSS0_MIPICSI0);
}

void hmi_gfx_mgr02_mipicsi2_interrupt_handler(void)
{
    uint32_t maskedIntrStatus;
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorCrc);
    }
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccSingle);
    }
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqErrorEccDouble);
    }
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsActiveChange);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsActiveChange);
    }
    maskedIntrStatus = Cy_Mipicsi2_GetInterruptStatus(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange);
    if(maskedIntrStatus != 0)
    {
        Cy_Mipicsi2_ClearInterrupt(VIDEOSS0_MIPICSI0, Mipicsi2IrqStatusUlpsMarkActiveChange);
    }
}
static void hmi_gfx_mgr02_mipicsi2_set_interrupt(void)
{
  MM_ERROR ret = MML_OK;
  /* Initialize MipiCsi interrupts */
  if (l_irq_cfg.sysIntSrc < disconnected_IRQn)
  {
    IRIS_API_CHECK(ret, Cy_SysInt_InitIRQ(&l_irq_cfg)); // GFX_2D
  }
  /* Set Handlers */
  Cy_SysInt_SetSystemIrqVector(l_irq_cfg.sysIntSrc, hmi_gfx_mgr02_mipicsi2_interrupt_handler);
  /* Set Prio/Enable IRQ */
  NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
  NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
  NVIC_EnableIRQ(CPUIntIdx3_IRQn);
}
#endif
/*============================================================================
** Function Name:       hmi_gfx_mgr02_get_capture_init_status(void)
** Visibility:          Graphics Manager.
** Description:         Interface to get the init status of the video capture module
** Invocation:          By application
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INIT_STATUS 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_get_capture_init_status(void)
{
    GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status;
    if((l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE) || (l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE))
    {
        fl_init_status = GFX_MGR02_CAPTURE_INIT_FAILURE;
    }
    else if(l_cap_init_status  == GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE)
    {
        fl_init_status = GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS;
    }
    else
    {
        fl_init_status = GFX_MGR02_CAPTURE_INIT_SUCCESS;
    }
    return  fl_init_status;
}

  
#if ((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
/*============================================================================
** Function Name:       hmi_gfx_mgr02_capture_video_set_status(void)
** Visibility:          Graphics Manager.
** Description:         Interface to set the ON/OFF status of the video capture module
** Invocation:          By hmi_gfx_mgr02_build_screen, hmi_gfx_mgr02_generic_build_screen
** Inputs/Outputs:      TRUE/FALSE 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void hmi_gfx_mgr02_capture_video_set_status(UINT8 p_status)
{
    l_gfx_mgr02_video_mode_status = p_status;
}

/*============================================================================
** Function Name:       hmi_gfx_mgr02_capture_video_get_status(void)
** Visibility:          Graphics Manager.
** Description:         Interface to get the ON/OFF status of the video capture module
** Invocation:          By hmi_gfx_mgr02_build_screen, hmi_gfx_mgr02_generic_build_screen
** Inputs/Outputs:      TRUE/FALSE 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
UINT8 hmi_gfx_mgr02_capture_video_get_status(void)
{
    return l_gfx_mgr02_video_mode_status;	   
}
#endif

/*============================================================================
** Function Name:       hmi_gfx_mgr02_open_capture_unit(void)
** Visibility:          Internal
** Description:         Interface to open the capture unit
** Invocation:          Internal
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_open_capture_unit(void)
{
    MM_ERROR ret = MML_OK;
    GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS fl_status = GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE;
    #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
    if(!l_mipi_init_done)
    {
      l_mipi_init_done = 1;
    #endif
#if defined(GFX_MGR02_TRAVEO2)
    IRIS_API_CHECK(ret, CyGfx_CapOpen(CYGFX_CAP_UNIT_0, &l_capProperties, &l_capCtx));
#else
    IRIS_API_CHECK(ret, mmlGdcCapOpen(MML_GDC_CAP_UNIT_0, &l_capProperties, &l_capCtx));
#endif
    if(MML_OK == ret)
    {
      #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
      hmi_gfx_mgr02_capture_video_mipi_cs2_init();
      #endif
	#if defined(GFX_MGR02_TRAVEO2)
	  if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_ITU8_YUV422)
	#else
      if(l_capProperties.format == MML_GDC_CAP_VIDEO_FORMAT_YUV422)
	#endif
      {
        IRIS_API_CHECK(ret, mmlGdcCapSetAttribute(l_capCtx, MML_GDC_CAP_ATTR_YUVCONVERSIONMODE, MM_GDC_CAP_YUVCONVERSIONMODE_ITU709));      
      }

	#if defined(GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2)
	    if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_PARALLEL_RGB)
      {
        IRIS_API_CHECK(ret, CyGfx_CapSetAttribute(l_capCtx, CYGFX_CAP_ATTR_COLORBITS, 0x08080800U));
        IRIS_API_CHECK(ret, CyGfx_CapSetAttribute(l_capCtx,CYGFX_CAP_ATTR_COLORSHIFT, 0x10080000U));
      }
      else if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_PARALLEL_YUV422)
      {
        IRIS_API_CHECK(ret, CyGfx_CapSetAttribute(l_capCtx, MML_GDC_CAP_ATTR_YUVCONVERSIONMODE, CYGFX_CAP_YUVCONVERSIONMODE_ITU601)); 
        IRIS_API_CHECK(ret, CyGfx_CapSetAttribute(l_capCtx, CYGFX_CAP_ATTR_COLORBITS, 0x08080808U));
        IRIS_API_CHECK(ret, CyGfx_CapSetAttribute(l_capCtx,CYGFX_CAP_ATTR_COLORSHIFT, 0x08000000U)); 
      }
      else
      {
        /*do nothing*/
      }
	#endif
      fl_status = GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS; 
    }
    #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
    }
    else
    {
      fl_status = GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS;
    }
    #endif
    return fl_status;
}

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED)
/*============================================================================
** Function Name:       hmi_gfx_mgr02_get_capture_context(void)
** Visibility:          Graphics Manager.
** Description:         Interface to get the capture context
** Invocation:          By hmi_gfx_mgr02_initialize
** Inputs/Outputs:      Capture Context pointer 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
MML_GDC_CAP_CTX* hmi_gfx_mgr02_get_capture_context(void)
{
    return &l_capCtx;
}
#endif 

 
#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
/*============================================================================
** Function Name:       hmi_gfx_mgr02_capture_to_window_init()
** Visibility:          Graphics Manager.
** Description:         Interface to initialize the capture to window mode. This
**                      interface will be invoked during every build of the video
**                      element till GFX_MGR02_CAPTURE_INIT_SUCCESS state is reached.
** Invocation:          By hmi_gfx_mgr02_build_video in hmi_gfx_mgr02_amber.c
** Inputs/Outputs:      Mode line parameters, video def, status
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_window_init(MML_GDC_DISP_MODE_LINE* p_modeline_param, GFX_MGR02_VIDEO_DEF_T p_video_def)
{
    GFX_MGR02_CAPTURE_INIT_STATUS   fl_init_status;
    if(l_capCtx == NULL)
    {
        l_cap_init_status = hmi_gfx_mgr02_open_capture_unit();
        if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS)
        {
            l_cap_init_status =  hmi_gfx_mgr02_capture_to_win_memory_allocation(p_modeline_param, p_video_def);
        }
    }
    /* Try for memory allocation during every build of the video element */
    else 
    {
      if((l_cap_init_status  == GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE) || (l_cap_init_status  == GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE))
      {
          l_cap_init_status = hmi_gfx_mgr02_capture_to_win_memory_allocation(p_modeline_param, p_video_def);
      }
    }
    fl_init_status = hmi_gfx_mgr02_get_capture_init_status();
    return fl_init_status;
}

/*============================================================================
** Function Name:       hmi_gfx_mgr02_capture_to_win_memory_allocation()
** Visibility:          Internal
** Description:         Interface to allocate memory for the capture to window mode
** Invocation:          By hmi_gfx_mgr02_capture_to_window_init
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INIT_STATUS
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_capture_to_win_memory_allocation(MML_GDC_DISP_MODE_LINE* p_modeline_param, GFX_MGR02_VIDEO_DEF_T p_video_def) 
{
    GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS fl_memory_allocation_status = GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE;

    IrisMemInfo fl_memory_s;
    MM_ERROR    ret = MML_OK;
    MM_BOOL     fl_YUV = MM_FALSE;
    #ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
    MM_U32 fl_compressed_buffer_size;
    MM_U32 fl_compression_percentage = GFX_MGR02_INITIAL_COMPRESSION_PERCENT;
    #endif
    #if defined(GFX_MGR02_TRAVEO2)
    if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_PARALLEL_YUV422)
    #else
    if(l_capProperties.format == MML_GDC_CAP_VIDEO_FORMAT_YUV422)
    #endif
    {
       fl_YUV =  MM_TRUE;
    } 
    /* Assign a memory block as ring buffer */
    if(l_ringBufferSize == 0)
    {
      #if defined(GFX_MGR02_TRAVEO2)
      l_ringBufferSize = CalculateRingbufferSize(
                        l_capProperties.Hact,
                        l_capProperties.Vact,
                        l_capProperties.Htot,
                        l_capProperties.Vtot,
                        (MM_U32)(l_capProperties.pixelClock * 1000000.0f),
                        p_modeline_param->horDisplayPeriod,
                        p_modeline_param->vertDisplayPeriod,
                        p_modeline_param->horTotal,
                        p_modeline_param->vertTotal,
                        (MM_U32)(p_modeline_param->pixelClock * 1000000.0f),
                        p_video_def.dim.width,      
                        p_video_def.dim.height,    
                        0,                              
                        p_video_def.dim.width,     
                        p_video_def.dim.height,   
                        0,                              
                        fl_YUV);
      #else
      l_ringBufferSize = CalculateRingbufferSize(
                        l_capProperties.active_width,
                        l_capProperties.active_height,
                        l_capProperties.total_width,
                        l_capProperties.total_height,
                        (MM_U32)(l_capProperties.pix_clk * 1000000.0f),
                        p_modeline_param->horDisplayPeriod,
                        p_modeline_param->vertDisplayPeriod,
                        p_modeline_param->horTotal,
                        p_modeline_param->vertTotal,
                        (MM_U32)(p_modeline_param->pixelClock * 1000000.0f),
                        p_video_def.dim.width,      
                        p_video_def.dim.height,    
                        0,                              
                        p_video_def.dim.width,     
                        p_video_def.dim.height,   
                        0,                              
                        fl_YUV);
      #endif
    } 
    fl_memory_s.Size = l_ringBufferSize;
    fl_memory_s.MemCateg = IRIS_VIDEO_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFF; 
    fl_memory_s.Alignment = (UINT32)32; 
    #ifdef GFX_MGR02_CAPTURE_BUFFER_IN_HRAM
    fl_memory_s.ExtMemory = (UINT8)1; 
    #else
    fl_memory_s.ExtMemory = (UINT8)0;
    #endif
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    ringBufferVirt = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);

    #ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
    while (ringBufferVirt == 0)
    {
        fl_compression_percentage = fl_compression_percentage - GFX_MGR02_COMPRESSION_REDUCTION_PERCENT;
        if(fl_compression_percentage < GFX_MGR02_MAX_COMPRESSION_PERCENT)
        {
          /* Compression less than 50% will be complete lossy one hence not done */
          break;
        }
        else
        {
          /* If there is not enough memory for an uncompressed ring buffer, reduce the size.
             The driver will automatically choose the appropriate compression factor */
          fl_compressed_buffer_size = (fl_memory_s.Size * fl_compression_percentage)/GFX_MGR02_INITIAL_COMPRESSION_PERCENT;
          fl_memory_s.Size = fl_compressed_buffer_size;
          ringBufferVirt = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        }
    }
    #endif
    IRIS_API_CHECK(ret, mmlGdcCapAssignCapToWinBuffer(l_capCtx, (MM_ADDR)ringBufferVirt, fl_memory_s.Size));  
    if(MML_OK == ret)
    {
        fl_memory_allocation_status = GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS; 
    }
  return fl_memory_allocation_status;

}

/*============================================================================
** Function Name:       hmi_gfx_mgr02_set_capture_signal_loss()
** Visibility:          Graphics Manager.
** Description:         Interface to set the signal loss status of the video capture module
** Invocation:          hmi_gfx_mgr02_build_video
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INIT_STATUS 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void  hmi_gfx_mgr02_set_capture_signal_loss(GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status)
{
    if(fl_init_status == GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS)
    {
      /* During window commit, cap commit will happen. Hence window commit failure indicates cap commit failure */
      l_cap_init_status =  GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE;
    }
}
#endif

/*============================================================================
** Function Name:       hmi_gfx_mgr02_get_capture_sync(void)
** Visibility:          Graphics Manager.
** Description:         Interface to get the capture sync object
** Invocation:          hmi_gfx_mgr02_build_video
** Inputs/Outputs:      Capture sync object 
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
MML_GDC_SYNC* hmi_gfx_mgr02_get_capture_sync(void)
{
    return &l_capSync;
}

#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_capture_to_surface_init(void)
** Visibility:          Graphics Manager.
** Description:         Interface to initialize the capture to surface mode. This
**                      interface will be invoked during every build of the video
**                      element till GFX_MGR02_CAPTURE_INIT_SUCCESS state is reached.
** Invocation:          hmi_gfx_mgr02_amber_build_video
** Inputs/Outputs:      p_video_def , GFX_MGR02_CAPTURE_INIT_STATUS
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_surface_init(GFX_MGR02_VIDEO_DEF_T const* p_video_def)
{
    GFX_MGR02_CAPTURE_INIT_STATUS   fl_init_status;
    if(l_capCtx == NULL)
    { 
        l_cap_init_status = hmi_gfx_mgr02_open_capture_unit();
        if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS)
        {
          l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_memory_allocation(p_video_def);
          if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS)
          {
              l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_start_capture();
          }
        }
    }
    else if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE)
    {
        l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_memory_allocation(p_video_def);
        if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS)
        {
            l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_start_capture();
        } 
    }
    else if(l_cap_init_status == GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE)
    {
        l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_start_capture();  
    }
    else
    {
      l_cap_init_status = hmi_gfx_mgr02_capture_to_surf_memory_allocation(p_video_def);
    }
    fl_init_status = hmi_gfx_mgr02_get_capture_init_status();
    return fl_init_status;
}

/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_to_surf_memory_allocation(void)
** Visibility:          Internal.
** Description:         Interface to allocate memory for the capture to surface mode
** Invocation:          By hmi_gfx_mgr02_capture_to_surface_init
** Inputs/Outputs:      GFX_MGR02_VIDEO_DEF_T const* p_video_def, GFX_MGR02_CAPTURE_INIT_STATUS
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS hmi_gfx_mgr02_capture_to_surf_memory_allocation(GFX_MGR02_VIDEO_DEF_T const* p_video_def)
{
  MM_ERROR ret = MML_OK;
  GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS fl_memory_allocation_status = GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS;
  MML_GDC_SURF_FORMAT fl_surf_format;
  IrisMemInfo fl_memory_s;
  UINT8 fl_buf_index;
  #ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
  MM_U32 fl_actual_buffer_size;
  MM_U32 fl_compression_percentage = GFX_MGR02_INITIAL_COMPRESSION_PERCENT;
  #endif
  void* fl_surface_memory;
  #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
  if(l_mipi_mem_init_done == 0)
  {
  #endif
    #if defined(GFX_MGR02_TRAVEO2)
    if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_ITU8_YUV422)
    #else
    if(l_capProperties.format == MML_GDC_CAP_VIDEO_FORMAT_YUV422)
    #endif
    {
      fl_surf_format =  MML_GDC_SURF_FORMAT_YVYU422;
    }
    #if defined(GFX_MGR02_TRAVEO2)
    if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_PARALLEL_RGB)
    {
      fl_surf_format = MML_GDC_SURF_FORMAT_R8G8B8; 
    }
    else if(l_capProperties.format == CYGFX_CAP_VIDEO_FORMAT_PARALLEL_YUV422)
    {
      fl_surf_format = CYGFX_SM_FORMAT_VYUY422;
    }
    #endif
    fl_memory_s.Size = 0;
    fl_memory_s.MemCateg = IRIS_VIDEO_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFu; 
    fl_memory_s.Alignment = (UINT32)32; 
    #ifdef GFX_MGR02_CAPTURE_BUFFER_IN_HRAM
    fl_memory_s.ExtMemory = (UINT8)1; 
    #else
    fl_memory_s.ExtMemory = (UINT8)0;
    #endif
    /* Initialize capture buffers */
    #if defined(GFX_MGR02_TRAVEO2)
    IRIS_API_CHECK(ret, utSmGenSurfaceObjects(GFX_MGR02_CAPTURE_BUFFERS_COUNT, l_capSurf));
    #else
    IRIS_API_CHECK(ret, mmlGdcSmGenSurfaceObjects(GFX_MGR02_CAPTURE_BUFFERS_COUNT, l_capSurf));
    #endif
    for (fl_buf_index = 0; fl_buf_index<GFX_MGR02_CAPTURE_BUFFERS_COUNT; fl_buf_index++)
    {
      void* fl_surface_memory;
      IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(l_capSurf[fl_buf_index], p_video_def->dim.width, p_video_def->dim.height, fl_surf_format, GFX_MGR02_NULL_PTR, 0));
      IRIS_API_CHECK(ret, mmlGdcSmGetAttribute(l_capSurf[fl_buf_index], MML_GDC_SURF_ATTR_SIZEINBYTES, (MM_U32*)&fl_memory_s.Size));
      #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
      fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
      #endif
      fl_surface_memory = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
      #ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
      /* Compression currently allowed in GDT only if video format is of RGB888
      The surface buffer format will also be MML_GDC_SURF_FORMAT_R8G8B8 */
      fl_actual_buffer_size = fl_memory_s.Size; 
      while (fl_surface_memory == 0)
      {
        fl_compression_percentage = fl_compression_percentage - GFX_MGR02_COMPRESSION_REDUCTION_PERCENT;
        if(fl_compression_percentage < GFX_MGR02_MAX_COMPRESSION_PERCENT)
        {
          /* Compression less than 50% will be complete lossy one hence not done */
          break;
        }
        else
        {
          fl_memory_s.Size = (fl_actual_buffer_size * fl_compression_percentage)/GFX_MGR02_INITIAL_COMPRESSION_PERCENT;
          ret = hmi_gfx_mgr02_compress_RGB_capture_buffer(l_capSurf[fl_buf_index], p_video_def->dim.width, p_video_def->dim.height, fl_surf_format, (MM_U32*)&fl_memory_s.Size);
          if(ret == MML_OK)
          {
            fl_surface_memory = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
          }
        }
      }
      #else
      fl_surface_memory = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
      #endif
      if(fl_surface_memory != (void*)0)
      {
        IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(l_capSurf[fl_buf_index], MML_GDC_SURF_ATTR_BASE_ADDRESS, (MM_U32)fl_surface_memory));  	
        IRIS_API_CHECK(ret, mmlGdcCapAssignSurfaceArray(l_capCtx, l_capSurf, GFX_MGR02_CAPTURE_BUFFERS_COUNT));
        fl_memory_allocation_status = GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS;
      }
    }
  #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
    l_mipi_mem_init_done = 1;
  }
  #endif
  return fl_memory_allocation_status; 
}

/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_to_surface_commit(void)
** Visibility:          Internal.
** Description:         Interface to start the next frame capture
** Invocation:          By hmi_gfx_mgr02_capture_to_surface_init
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INIT_STATUS
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
static GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS  hmi_gfx_mgr02_capture_to_surf_start_capture(void)
{
    MM_ERROR ret = MML_OK;
    GFX_MGR02_CAPTURE_INTERNAL_INIT_STATUS fl_start_capture_status = GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE;
    IRIS_API_CHECK(ret, mmlGdcCapCommit(l_capCtx));
    if(MML_OK == ret)
    {
        #if GFX_MGR02_CAPTURE_BUFFERS_COUNT <=2
        IRIS_API_CHECK(ret, mmlGdcCapSync(l_capCtx, l_capSync));
        #else
        IRIS_API_CHECK(ret, mmlGdcCapSyncVSync(l_capCtx, l_capSync, 2u));
        #endif
        fl_start_capture_status =	GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS;
    }
    return fl_start_capture_status; 
}

/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_get_surface(void)
** Visibility:          Graphics Manager.
** Description:         Interface to get the last captured surface
** Invocation:          By hmi_gfx_mgr02_amber_build_video
** Inputs/Outputs:      Video capture surface place holder
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void hmi_gfx_mgr02_capture_get_surface(MML_GDC_SURFACE* fl_video_surface)
{
  MM_ERROR ret = MML_OK;
  if(FALSE != l_gfx_mgr02_video_mode_status)
  {
      /* Retrieve the last captured frame... */
      IRIS_API_CHECK(ret, mmlGdcCapGetSurface(l_capCtx, *fl_video_surface));
  }
} 

/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_to_surface_commit(void)
** Visibility:          Graphics Manager.
** Description:         Interface to start the next frame capture
** Invocation:          By hmi_gfx_mgr02_amber_build_video
** Inputs/Outputs:      None
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void  hmi_gfx_mgr02_capture_to_surface_commit(void)
{
  if(FALSE != l_gfx_mgr02_video_mode_status)
  {
        MM_ERROR ret = MML_OK;
        #if (GFX_MGR02_CAPTURE_BUFFERS_COUNT < GFX_MGR02_MAX_CAPTURE_BUFFERS_COUNT)
        /* Trigger another single frame capture.
        The next frame will be stored in the "back buffer" */
        IRIS_API_CHECK(ret, mmlGdcCapCommit(l_capCtx));
        if(ret != MML_OK)
        {
            l_cap_init_status = GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE;
        }
        #endif
        IRIS_API_CHECK(ret, mmlGdcCapSync(l_capCtx, l_capSync)); 
  }
}

#ifdef GFX_MGR02_CAPTURE_VIDEO_COMPRESSION_ENABLED
/*============================================================================
** Function Name:       hmi_gfx_mgr02_compress_RGB_capture_buffer()
** Visibility:          Internal.
** Description:         Interface to compress the capture buffer size
** Invocation:          By hmi_gfx_mgr02_capture_to_surf_memory_allocation
** Inputs/Outputs:      surf, w,h ,format, size
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
static MM_ERROR hmi_gfx_mgr02_compress_RGB_capture_buffer(MML_GDC_SURFACE surf, MM_U32 w, MM_U32 h, MML_GDC_SURF_FORMAT eFormat, MM_U32* ReqSizeInBytes)
{
    MM_ERROR ret = MML_OK;
    MM_U32 size;
    MM_U08 ro, go, bo;
    MM_U08 rc, gc, bc;
    MM_U08 r = 8, g = 8, b = 8;
    MM_U32 i;

    IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(surf, w, h, eFormat, 0, 0));
    IRIS_API_CHECK(ret, mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_COLORBITS, &size));
    ro = (MM_U08)((size>>24) & 0xff);
    go = (MM_U08)((size>>16) & 0xff);
    bo = (MM_U08)((size>> 8) & 0xff);
    IRIS_API_CHECK(ret, mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_SIZEINBYTES, &size));
    for (i = 0; (i < (32 - 4)) && (size > *ReqSizeInBytes); i++)
    {
        switch(i % 4)
        {
        case 1: r--;
            break;
        case 2: b--;
            break;
        case 3: g--;
            break;
        default:
        {
        	/*For MISRA warning Fix.*/
        }
            break;
        }
        rc = MIN(r, ro);
        gc = MIN(g, go);
        bc = MIN(b, bo);
        /* Green channel gets the most bits */
        IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(l_capSurf[i], MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, MML_GDC_SURF_COMP_RLAD_UNIFORM));
        IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_RLAD_MAXCOLORBITS,
            (((MM_U32)rc)<<24) | (((MM_U32)gc)<<16) | (((MM_U32)bc)<<8)));
        IRIS_API_CHECK(ret, mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_SIZEINBYTES, &size));
    }
    if ((size > *ReqSizeInBytes) || (size == 0))
    {
        ret = MML_ERR;
    }
    else
    {
        *ReqSizeInBytes = size;
    } 
    return ret;
}
#endif
#endif


#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_to_display_init(void)
** Visibility:          Graphics Manager.
** Description:         Interface to initialise the capture to display mode.
** Invocation:          By hmi_gfx_mgr02_initialize
** Inputs/Outputs:      GFX_MGR02_CAPTURE_INIT_STATUS
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_capture_to_display_init(void)
{
    GFX_MGR02_CAPTURE_INIT_STATUS   fl_init_status;
  if(l_capCtx == NULL)
  {
    l_cap_init_status = hmi_gfx_mgr02_open_capture_unit();
  }
  fl_init_status = hmi_gfx_mgr02_get_capture_init_status();
  return fl_init_status;
}
#endif


/*============================================================================
** Function Name:       void hmi_gfx_mgr02_capture_video_shutdown(void)
** Visibility:          Graphics Manager.
** Description:         Interface to shut down the capture module
** Invocation:          By hmi_gfx_mgr02_build_screen, hmi_gfx_mgr02_generic_build_screen
** Inputs/Outputs:      None
** Critical Section:    None
** Created:             ADEVI
** Updated:             ADEVI
**==========================================================================*/
void hmi_gfx_mgr02_capture_video_shutdown(void)
{
  if(NULL != l_capCtx)
  {
    #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
    UINT8 fl_buf_index;
    #endif
    
    MM_ERROR ret = MML_OK;
    IRIS_API_CHECK(ret, mmlGdcCapAssignSurfaceArray(l_capCtx, GFX_MGR02_NULL_PTR, 0));
    IRIS_API_CHECK(ret, mmlGdcCapCommit(l_capCtx));

    #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE) 
    hmi_gfx_mgr02_amber_mem_mgmt_free(ringBufferVirt);
    ringBufferVirt = 0;
    #endif

    #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
    for (fl_buf_index = 0; fl_buf_index<GFX_MGR02_CAPTURE_BUFFERS_COUNT; fl_buf_index++)
    {
      void* fl_surface_memory = GFX_MGR02_NULL_PTR;
      IRIS_API_CHECK(ret,mmlGdcSmGetAttribute(l_capSurf[fl_buf_index], MML_GDC_SURF_ATTR_BASE_ADDRESS, (MM_U32*)&fl_surface_memory));
      hmi_gfx_mgr02_amber_mem_mgmt_free(fl_surface_memory);
    }
	  #if defined(GFX_MGR02_TRAVEO2)
	    IRIS_API_CHECK(ret,utSmDeleteSurfaceObjects(GFX_MGR02_CAPTURE_BUFFERS_COUNT, l_capSurf));
	  #else
      IRIS_API_CHECK(ret,mmlGdcSmDeleteSurfaceObjects(GFX_MGR02_CAPTURE_BUFFERS_COUNT, l_capSurf));
	  #endif
    #endif

    /* Close Capture unit 0 */
    #if defined(GFX_MGR02_TRAVEO2)
    IRIS_API_CHECK(ret,CyGfx_CapClose(l_capCtx));
    #else
    IRIS_API_CHECK(ret,mmlGdcCapClose(l_capCtx));
    #endif
    l_capCtx = GFX_MGR02_NULL_PTR;
    l_cap_init_status = GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE;

    #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
    l_mipi_init_done = 0;
    #if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
    l_mipi_mem_init_done=0;
    #endif
    #endif
  } 
}


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
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 **
 ** CMS Rev 1.1      16-Aug-2018    adevi
 ** Interface udpation.
 **
 ** CMS Rev 1.0      16-Aug-2018    adevi
 ** Creation.
 **==========================================================================*/

/* end of file =============================================================*/


#endif // #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED)
