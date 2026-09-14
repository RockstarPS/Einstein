/*
 * Copyright  2017-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "system.h"
#ifndef WIN32
   typedef UINT8  GFX_IMG_DATA_T ;
   typedef UINT16 GFX_IMG_DATA16_T ;
   typedef UINT32 GFX_IMG_DATA32_T ;
#else
   typedef UINT8  GFX_IMG_DATA_T;
   typedef UINT16 GFX_IMG_DATA16_T;
   typedef UINT32 GFX_IMG_DATA32_T;
#endif
#define GFX_IMG_DATA_PREFIX

#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_pxp.h"
#include "display_support.h"
#include "New_images_3_0_ovg2.h"
//#include "New_images_3_0_ovg.dat"
#include "img_rpm.h"
#include "img_speed.h"
#include "img_circle.h"
#include "New_images_1.h"
#include "New_images_2.h"
#include "New_images_3.h"
#include "New_images_3_0.h"
#include "New_images_3_0_ovg2.h"
#include "New_images_7.h"

#include "fsl_soc_src.h"
#include "hmi_gfx_mgr02_imxrt_lcdif.h"
#define GDT_PXP_DEMO
//#define ELCDIF_RGB_DEMO
#if defined GDT_PXP_DEMO
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_types.h"
static uint32_t l_dc_busy_cnt = 0;
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_PXP PXP

/* Use RGB565 or XRGB8888 */
#define USE_RGB565 0
#define APP_IMG_WIDTH  DEMO_BUFFER_WIDTH
#define APP_IMG_HEIGHT DEMO_BUFFER_HEIGHT

#define APP_PS_WIDTH  (APP_IMG_WIDTH / 2U)
#define APP_PS_HEIGHT (APP_IMG_HEIGHT / 2U)
#define APP_AS_WIDTH  (APP_IMG_WIDTH / 2U)
#define APP_AS_HEIGHT (APP_IMG_HEIGHT / 2U)

#define APP_PS_ULC_X ((APP_IMG_WIDTH / 2) - (APP_PS_SIZE / 2))
#define APP_PS_ULC_Y ((APP_IMG_HEIGHT / 2) - (APP_PS_SIZE / 2))
#define APP_PS_LRC_X ((APP_IMG_WIDTH / 2) + (APP_PS_SIZE / 2) - 1U)
#define APP_PS_LRC_Y ((APP_IMG_HEIGHT / 2) + (APP_PS_SIZE / 2) - 1U)

#if USE_RGB565

typedef uint16_t pixel_t;
#define APP_BPP            2U /* Use 16-bit RGB565 format. */
#define APP_RED            0xF100U
#define APP_BLUE           0x001FU
#define APP_PXP_PS_FORMAT  kPXP_PsPixelFormatRGB565
#define APP_PXP_AS_FORMAT  kPXP_AsPixelFormatRGB565
#define APP_PXP_OUT_FORMAT kPXP_OutputPixelFormatRGB565
#define APP_DC_FORMAT      kVIDEO_PixelFormatRGB565

#else

typedef uint32_t pixel_t;
#define APP_BPP            4U /* Use 32-bit XRGB888 format. */
#define APP_RED            0x00FF0000U
#define APP_BLUE           0x000000FFU
#define APP_PXP_PS_FORMAT  kPXP_PsPixelFormatRGB888
#define APP_PXP_AS_FORMAT  kPXP_AsPixelFormatRGB888
#define APP_PXP_OUT_FORMAT kPXP_OutputPixelFormatRGB888
#define APP_DC_FORMAT      kVIDEO_PixelFormatXRGB8888

#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void APP_InitInputBuffer(void);
static void APP_InitLcdif(void);
static void APP_InitPxp(void);
static void APP_Blend(void);
static void APP_BufferSwitchOffCallback(void *param, void *switchOffBuffer);
uint32_t hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count(void);
void enableCpuCycleCounter1(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

AT_NONCACHEABLE_SECTION_ALIGN(static pixel_t s_BufferLcd[2][APP_IMG_HEIGHT][APP_IMG_WIDTH], FRAME_BUFFER_ALIGN);
AT_NONCACHEABLE_SECTION_ALIGN(static pixel_t s_psBufferPxp[APP_PS_HEIGHT][APP_PS_WIDTH], FRAME_BUFFER_ALIGN);
AT_NONCACHEABLE_SECTION_ALIGN(static pixel_t s_asBufferPxp[APP_AS_HEIGHT][APP_AS_WIDTH], FRAME_BUFFER_ALIGN);



/* PXP Output buffer config. */
static pxp_output_buffer_config_t outputBufferConfig;

static uint8_t curLcdBufferIdx = 0;

extern GFX_IMG_DATA32_T lc_new_images_3_0_ovg_data2[2500];
//extern GFX_IMG_DATA32_T lc_new_images_3_0_ovg_data[130560];
UINT16 temp_array[2500];
UINT16 temp_array1[2500];
UINT16 temp_array2[2500];
UINT16 temp_array3[2500];
UINT16 temp_array4[2500];
UINT16 temp_array5[2500];
UINT16 temp_array6[2500];
UINT16 temp_array7[2500];
static void * my_watch;
static void * my_watch1;
static void * my_watch2;
static void * my_watch3;
static void * my_watch4;
static void * my_watch5;
static void * my_watch6;
static void * my_watch7;

/*
 * When new frame buffer sent to display, it might not be shown immediately.
 * Application could use callback to get new frame shown notification, at the
 * same time, when this flag is set, application could write to the older
 * frame buffer.
 */
static volatile bool s_newFrameShown = false;
static dc_fb_info_t fbInfo;

/*******************************************************************************
 * Code
 ******************************************************************************/
static void BOARD_ResetDisplayMix(void)
{
    /*
     * Reset the displaymix, otherwise during debugging, the
     * debugger may not reset the display, then the behavior
     * is not right.
     */
    SRC_AssertSliceSoftwareReset(SRC, kSRC_DisplaySlice);
    while (kSRC_SliceResetInProcess == SRC_GetSliceResetState(SRC, kSRC_DisplaySlice))
    {
    }
}
uint32_t hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count(void)
{
#if 1
    return DWT->CYCCNT;
#endif
}

uint32_t hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(uint32_t fl_end_time, uint32_t fl_start_time)
{
#if 1
	uint32_t fl_count = fl_end_time - fl_start_time;
	uint32_t fl_msec = COUNT_TO_MSEC(fl_count, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
	return fl_msec;
#endif
}
static uint32_t l_delay_U32 = 1 * 1000 * 1;
static uint32_t l_select_screen = 1;
static uint32_t l_time_compare = 5000;
static uint32_t l_select_wdg1 = 0;
static uint32_t l_select_wdg2 = 0;
static uint32_t l_select_wdg3 = 0;
static uint32_t l_select_wdg4 = 0;
static uint32_t l_select_wdg5 = 0;
static uint32_t l_select_wdg6 = 0;

int main(void)
{
	uint32_t fl_before_cnt;
	uint32_t fl_after_cnt;
	uint32_t fl_fps;
	uint32_t fl_fps_in_msec;
     BOARD_ConfigMPU();
    BOARD_BootClockRUN();
    BOARD_ResetDisplayMix();
    BOARD_InitLpuartPins();
    BOARD_InitMipiPanelPins();
    BOARD_InitDebugConsole();

   // temp_array =  lc_new_images_3_0_ovg_data2;
  //  memcpy(temp_array,lc_new_images_3_0_ovg_data2,5000);
  //  memcpy(temp_array,lc_new_images_3_0_ovg_data,522240);
    memcpy(temp_array,lc_img_rpm_data2,5000);
    my_watch = &temp_array;
    memcpy(temp_array1,lc_img_speed_data2,5000);
    my_watch1 = &temp_array1;
    memcpy(temp_array2,lc_img_circle_data2,5000);
    my_watch2 = &temp_array2;
    memcpy(temp_array3,lc_new_images_3_data2,5000);
    my_watch3 = &temp_array3;
    memcpy(temp_array4,lc_new_images_3_0_data2,5000);
    my_watch4 = &temp_array4;
    memcpy(temp_array5,lc_new_images_7_data2,5000);
    my_watch5 = &temp_array5;
    memcpy(temp_array6,lc_new_images_1_data2,5000);
    my_watch6 = &temp_array6;
    memcpy(temp_array7,lc_new_images_2_data2,5000);
    my_watch7 = &temp_array7;

    PRINTF("\r\nPXP Blend example start...\r\n");
#if defined  ELCDIF_RGB_DEMO
    APP_InitInputBuffer();
    APP_InitPxp();
    APP_InitLcdif();
    APP_Blend();
#endif
#if defined  GDT_PXP_DEMO
    //APP_InitLcdif();
    BOARD_PrepareDisplayController();
    hmi_lsh_initialize(0);
    hmi_gfx_mgr02_layout_initialize();

    if(l_select_screen == 0)
    {
    LSH_ADD_STATE(GFX_SCR_TV2_SAMLE1,255);
    //LSH_ADD_STATE(GFX_SCR_IMXRT_FPS_FILL_IMG,255);
    }
    else if(l_select_screen == 1)
    {
    //LSH_ADD_STATE(GFX_SCR_TV2_SAMLE1,255);
   // LSH_ADD_STATE(GFX_SCR_TV2_SAMLE1,255);
    LSH_ADD_STATE(GFX_SCR_IMXRT_FPS_FILL_IMG,255);
    }
    else
    {
    LSH_ADD_STATE(GFX_SCR_IMXRT_WO_WIDGET,255);
    //LSH_ADD_STATE(GFX_SCR_IMXRT_FPS_FILL_IMG,255);
    }
    //hmi_lsh_task();
    //hmi_gfx_mgr02_layout_build_screen();
    enableCpuCycleCounter1();
#endif	
    while (1)
    {
	#if defined  GDT_PXP_DEMO
        hmi_lsh_task();
        fl_before_cnt = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
#if 0

        while(1)
        {
        	fl_after_cnt = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
        	if(fl_after_cnt >= 2097151)
        	{
        		PRINTF("\r\n its 2 minutest \r\n");

        	}
        	fl_fps_in_msec =  hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_after_cnt,fl_before_cnt);
        	if(fl_fps_in_msec >= l_time_compare)
        	{
        		PRINTF("\r\n its 2 minutest \r\n");
        	}


        }
#endif
        //PRINTF("\r\nbf cnt %d...\r\n",fl_before_cnt );
        hmi_gfx_mgr02_layout_build_screen();

    /*    if(l_select_wdg1 == 1)
        {
               	LSH_REM_STATE(GFX_SCR_TV2_SAMLE1,255);
        }
        else  if(l_select_wdg1 == 2)
        {
               	LSH_ADD_STATE(GFX_SCR_TV2_SAMLE1,255);
        } */


        fl_after_cnt = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
        //PRINTF("\r\naf cnt %d...\r\n",fl_before_cnt );
        fl_fps_in_msec =  hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_after_cnt,fl_before_cnt);
     //   PRINTF("\r\n fps in msec %d...\r\n",fl_fps_in_msec);


        /* Show the active frame buffer for a while. */
        //SDK_DelayAtLeastUs(l_delay_U32, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
     /*   while(!hmi_gfx_mgr02_imxrt_lcdif_is_render_done())
        {
        	l_dc_busy_cnt++;
        }*/
	#endif		
		
    }
}

static void APP_InitLcdif(void)
{
    status_t status;

    BOARD_PrepareDisplayController();

    status = g_dc.ops->init(&g_dc);
    if (kStatus_Success != status)
    {
        PRINTF("Display initialization failed\r\n");
        assert(0);
    }

    g_dc.ops->getLayerDefaultConfig(&g_dc, 0, &fbInfo);
    fbInfo.pixelFormat = APP_DC_FORMAT;
    fbInfo.width       = APP_IMG_WIDTH;
    fbInfo.height      = APP_IMG_HEIGHT;
    fbInfo.startX      = DEMO_BUFFER_START_X;
    fbInfo.startY      = DEMO_BUFFER_START_Y;
    fbInfo.strideBytes = APP_IMG_WIDTH * APP_BPP;
    g_dc.ops->setLayerConfig(&g_dc, 0, &fbInfo);

  //  g_dc.ops->setCallback(&g_dc, 0, APP_BufferSwitchOffCallback, NULL);

    s_newFrameShown = false;
    g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)s_BufferLcd[curLcdBufferIdx]);

    /* For the DBI interface display, application must wait for the first
     * frame buffer sent to the panel.
     */
    if ((g_dc.ops->getProperty(&g_dc) & kDC_FB_ReserveFrameBuffer) == 0)
    {
        while (s_newFrameShown == false)
        {
        }
    }

    s_newFrameShown = true;

    g_dc.ops->enableLayer(&g_dc, 0);
}
void enableCpuCycleCounter1(void)
{
    /* Make sure the DWT trace fucntion is enabled. */
    if (CoreDebug_DEMCR_TRCENA_Msk != (CoreDebug_DEMCR_TRCENA_Msk & CoreDebug->DEMCR))
    {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    }

    /* CYCCNT not supported on this device. */
    assert(DWT_CTRL_NOCYCCNT_Msk != (DWT->CTRL & DWT_CTRL_NOCYCCNT_Msk));

    /* Read CYCCNT directly if CYCCENT has already been enabled, otherwise enable CYCCENT first. */
    if (DWT_CTRL_CYCCNTENA_Msk != (DWT_CTRL_CYCCNTENA_Msk & DWT->CTRL))
    {
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}
static void APP_InitPxp(void)
{
    PXP_Init(APP_PXP);

    /* PS configure. */
    const pxp_ps_buffer_config_t psBufferConfig = {
        .pixelFormat = APP_PXP_PS_FORMAT,
        .swapByte    = false,
        .bufferAddr  = (uint32_t)s_psBufferPxp,
        .bufferAddrU = 0U,
        .bufferAddrV = 0U,
        .pitchBytes  = APP_PS_WIDTH * APP_BPP,
    };

    PXP_SetProcessSurfaceBackGroundColor(APP_PXP, 0U);

    PXP_SetProcessSurfaceBufferConfig(APP_PXP, &psBufferConfig);

    /* AS config. */
    const pxp_as_buffer_config_t asBufferConfig = {
        .pixelFormat = APP_PXP_AS_FORMAT,
        .bufferAddr  = (uint32_t)s_asBufferPxp,
        .pitchBytes  = APP_AS_WIDTH * APP_BPP,
    };

    const pxp_as_blend_config_t asBlendConfig = {.alpha       = 0U,    /* Don't care. */
                                                 .invertAlpha = false, /* Don't care. */
                                                 .alphaMode   = kPXP_AlphaRop,
                                                 .ropMode     = kPXP_RopMergeAs};

    PXP_SetAlphaSurfaceBufferConfig(APP_PXP, &asBufferConfig);
    PXP_SetAlphaSurfaceBlendConfig(APP_PXP, &asBlendConfig);

    /* Output config. */
    outputBufferConfig.pixelFormat    = APP_PXP_OUT_FORMAT;
    outputBufferConfig.interlacedMode = kPXP_OutputProgressive;
    outputBufferConfig.buffer0Addr    = (uint32_t)s_BufferLcd[0];
    outputBufferConfig.buffer1Addr    = 0U;
    outputBufferConfig.pitchBytes     = APP_IMG_WIDTH * APP_BPP;
    outputBufferConfig.width          = APP_IMG_WIDTH;
    outputBufferConfig.height         = APP_IMG_HEIGHT;

    PXP_SetOutputBufferConfig(APP_PXP, &outputBufferConfig);

    /* Disable CSC1, it is enabled by default. */
    PXP_EnableCsc1(APP_PXP, false);
}

static void APP_Blend(void)
{
    uint8_t curLcdBufferIdx = 1U;
    int8_t psIncX           = 1;
    int8_t psIncY           = 1;
    int8_t asIncX           = -1;
    int8_t asIncY           = -1;
    uint16_t psUlcX         = 0U;
    uint16_t psUlcY         = 0U;
    uint16_t asUlcX         = APP_IMG_WIDTH - APP_AS_WIDTH;
    uint16_t asUlcY         = APP_IMG_HEIGHT - APP_AS_HEIGHT;
    uint16_t psLrcX, psLrcY, asLrcX, asLrcY;

    psLrcX = psUlcX + APP_PS_WIDTH - 1U;
    psLrcY = psUlcY + APP_PS_HEIGHT - 1U;
    asLrcX = asUlcX + APP_AS_WIDTH - 1U;
    asLrcY = asUlcY + APP_AS_HEIGHT - 1U;

    for (;;)
    {
        /* Prepare next buffer for LCD. */
        PXP_SetProcessSurfacePosition(APP_PXP, psUlcX, psUlcY, psLrcX, psLrcY);
        PXP_SetAlphaSurfacePosition(APP_PXP, asUlcX, asUlcY, asLrcX, asLrcY);

        /*
         * Wait for the new set frame buffer active, so that the older frame
         * buffer is inactive, then PXP could output to the older frame buffer.
         */
        while (s_newFrameShown == false)
        {
        }

        /* Switch to the other LCD buffer. */
        curLcdBufferIdx ^= 1U;

        outputBufferConfig.buffer0Addr = (uint32_t)s_BufferLcd[curLcdBufferIdx];
        PXP_SetOutputBufferConfig(APP_PXP, &outputBufferConfig);

        /* Start PXP. */
        PXP_Start(APP_PXP);

        /* Wait for process complete. */
        while (!(kPXP_CompleteFlag & PXP_GetStatusFlags(APP_PXP)))
        {
        }

        PXP_ClearStatusFlags(APP_PXP, kPXP_CompleteFlag);

        s_newFrameShown = false;
        g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)s_BufferLcd[curLcdBufferIdx]);

        psLrcX += psIncX;
        psLrcY += psIncY;
        asLrcX += asIncX;
        asLrcY += asIncY;
        psUlcX += psIncX;
        psUlcY += psIncY;
        asUlcX += asIncX;
        asUlcY += asIncY;

        if (0 == asUlcX)
        {
            asIncX = 1;
        }
        else if (APP_IMG_WIDTH - 1 == asLrcX)
        {
            asIncX = -1;
        }

        if (0 == asUlcY)
        {
            asIncY = 1;
        }
        else if (APP_IMG_HEIGHT - 1 == asLrcY)
        {
            asIncY = -1;
        }

        if (0 == psUlcX)
        {
            psIncX = 1;
        }
        else if (APP_IMG_WIDTH - 1 == psLrcX)
        {
            psIncX = -1;
        }

        if (0 == psUlcY)
        {
            psIncY = 1;
        }
        else if (APP_IMG_HEIGHT - 1 == psLrcY)
        {
            psIncY = -1;
        }
    }
}

static void APP_InitInputBuffer(void)
{
    uint32_t i, j;

    /* The PS buffer is BLUE rectangle, the AS buffer is RED rectangle. */

    for (i = 0; i < APP_PS_HEIGHT; i++)
    {
        for (j = 0; j < APP_PS_WIDTH; j++)
        {
            s_psBufferPxp[i][j] = APP_BLUE;
        }
    }

    for (i = 0; i < APP_PS_HEIGHT; i++)
    {
        for (j = 0; j < APP_PS_WIDTH; j++)
        {
            s_asBufferPxp[i][j] = APP_RED;
        }
    }

    memset(s_BufferLcd, 0x0U, sizeof(s_BufferLcd));
}
static uint32_t l_incr_y_by = 3;
static void APP_BufferSwitchOffCallback(void *param, void *switchOffBuffer)
{
    s_newFrameShown = true;
}
#if defined GDT_PXP_DEMO
static UINT32 l_alpha = 0;
static UINT32 l_x = 0;
static UINT32 l_y = 0;
static UINT32 l_clip_ex = 10;
static UINT32 l_clip_ey = 10;
static UINT32 l_check_vertical_anim = 1;
void hmi_scr_tv2_samle1_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	GFX_MGR02_HCLIP_DATA fl_v_clip;
	GFX_MGR02_HCLIP_DATA fl_h_clip;
	if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	{
		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,1);
	}
	else if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
	{

		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,0);
	}
	else
	{
#if 1

		fl_h_clip.start_column = 0;
		fl_h_clip.num_columns = l_clip_ex;
		l_clip_ex++;
		if(l_clip_ex == 479)
			l_clip_ex = 10;

		fl_v_clip.start_column = 0;
		fl_v_clip.num_columns = l_clip_ey;
		l_clip_ey++;
		if(l_clip_ey == 271)
			l_clip_ey = 10;

		//hmi_gfx_mgr02_layout_set_text(GFX_NEW_TEXTS_2_ANIM, L"Hi");
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_NEW_FILL_SCREENS_1_ANIM, l_alpha);
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_CIRCLE_ANIM, 125);
		//
		if(l_check_vertical_anim == 1)
		{
			//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_CIRCLE_ANIM, l_y);
		}
		else
		{
			//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_CIRCLE_ANIM, l_x);

		}
//		hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_NEW_FILL_SCREENS_3_ANIM, l_x);
		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_NEW_FILL_SCREENS_3_ANIM, l_y);
//		hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_SPEED_ANIM,l_alpha);
		//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_SPEED_ANIM, l_x);
		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_SPEED_ANIM, l_y);
		//hmi_gfx_mgr02_layout_set_obj_hclip(GFX_NEW_WIDGETS_3_ANIM, &fl_h_clip );
		//hmi_gfx_mgr02_layout_set_obj_vclip(GFX_NEW_WIDGETS_3_ANIM, &fl_v_clip );
	//	hmi_gfx_mgr02_layout_set_text(GFX_NEW_TEXTS_2_ANIM, L"Hi How are you");
		l_alpha++;
		if(l_alpha == 255)
		{
			l_alpha = 0;
		}
		l_x++;
		if(l_x == 479)
		{
			l_x = 0;
		}
		l_y = l_y + l_incr_y_by;
		if(l_y > 270)
		{
			l_y = 0;
		}
#endif
	}
}

UINT32 c = 1;
void hmi_scr_imxrt_wo_widget_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	GFX_MGR02_HCLIP_DATA fl_v_clip;
	GFX_MGR02_HCLIP_DATA fl_h_clip;
	if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	{
		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,1);
	}
	else if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
	{

		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,0);
	}
	else
	{
#if 1

		fl_h_clip.start_column = 0;
		fl_h_clip.num_columns = l_clip_ex;
		l_clip_ex++;
		if(l_clip_ex == 479)
			l_clip_ex = 10;

		fl_v_clip.start_column = 0;
		fl_v_clip.num_columns = l_clip_ey;
		l_clip_ey++;
		if(l_clip_ey == 271)
			l_clip_ey = 10;

		hmi_gfx_mgr02_layout_set_text(GFX_NEW_TEXTS_2_ANIM, L"Hi");
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_NEW_FILL_SCREENS_1_ANIM, l_alpha);
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_CIRCLE_ANIM, 125);
		//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_CIRCLE_ANIM, l_x);
//		hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_NEW_FILL_SCREENS_3_ANIM, l_x);
		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_NEW_FILL_SCREENS_3_ANIM, l_y);
//		hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_SPEED_ANIM,l_alpha);

		if(l_check_vertical_anim == 1)
		{
			hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_SPEED_ANIM, l_y);
		}
		else
		{
			hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_SPEED_ANIM, l_x);

		}
		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_SPEED_ANIM, l_y);
		//hmi_gfx_mgr02_layout_set_obj_hclip(GFX_NEW_WIDGETS_3_ANIM, &fl_h_clip );
		//hmi_gfx_mgr02_layout_set_obj_vclip(GFX_NEW_WIDGETS_3_ANIM, &fl_v_clip );

		l_alpha++;
		if(l_alpha == 255)
		{
			l_alpha = 0;
		}
		l_x++;
		if(l_x == 479)
		{
			l_x = 0;
		}
		l_y = l_y + 10;
		if(l_y > 270)
		{
			l_y = 0;
		}
#endif
	}
}

void hmi_scr_imxrt_fps_fill_img_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	GFX_MGR02_HCLIP_DATA fl_v_clip;
	GFX_MGR02_HCLIP_DATA fl_h_clip;
	if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	{
		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,1);
	}
	else if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
	{

		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id,0);
	}
	else
	{
#if 1

	/*	fl_h_clip.start_column = 0;
		fl_h_clip.num_columns = l_clip_ex;
		l_clip_ex++;
		if(l_clip_ex == 479)
			l_clip_ex = 10;

		fl_v_clip.start_column = 0;
		fl_v_clip.num_columns = l_clip_ey;
		l_clip_ey++;
		if(l_clip_ey == 271)
			l_clip_ey = 10; */

		//hmi_gfx_mgr02_layout_set_text(GFX_NEW_TEXTS_2_ANIM, L"Hi How are you");
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_NEW_FILL_SCREENS_1_ANIM, l_alpha);
		//hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_CIRCLE_ANIM, 125);
		//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_CIRCLE_ANIM, l_x);
//		hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_NEW_FILL_SCREENS_3_ANIM, l_x);
		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_NEW_FILL_SCREENS_3_ANIM, l_y);
//		hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_SPEED_ANIM,l_alpha);

	/*	if(l_check_vertical_anim == 1)
		{
			hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_NEW_IMAGES_3_ANIM, l_y);
			//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_SPEED_ANIM, l_y);
		}
		else
		{
			hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_NEW_IMAGES_3_ANIM, l_x);
			//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_SPEED_ANIM, l_x);

		} */

		//hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_IMG_SPEED_ANIM, l_y);
		//hmi_gfx_mgr02_layout_set_obj_hclip(GFX_NEW_WIDGETS_3_ANIM, &fl_h_clip );
		//hmi_gfx_mgr02_layout_set_obj_vclip(GFX_NEW_WIDGETS_3_ANIM, &fl_v_clip );
		//hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_IMG_SPEED_ANIM, l_x);

	//	hmi_gfx_mgr02_layout_select_dwidget(GFX_DYN_WDG1,l_select_wdg1);
	//	hmi_gfx_mgr02_layout_select_dwidget(GFX_DYN_WDG4,l_select_wdg1);
	//	hmi_gfx_mgr02_layout_select_dwidget(GFX_DYN_WDG6,l_select_wdg1);
//		hmi_gfx_mgr02_layout_select_dimage(GFX_DYN_IMG1,l_select_wdg1);
	//	hmi_gfx_mgr02_layout_select_dimage(GFX_DYN_IMG2,l_select_wdg1);
	//	hmi_gfx_mgr02_layout_select_dimage(GFX_DYN_IMG3,l_select_wdg1);





	//	l_alpha++;
	/*	if(l_alpha == 255)
		{
			l_alpha = 0;
		}
		l_x++;
		if(l_x == 479)
		{
			l_x = 0;
		}
		l_y++;
		if(l_y == 271)
		{
			l_y = 0;
		}  */
#endif
	}
}
#endif
