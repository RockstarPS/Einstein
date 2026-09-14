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
 ** Name:           hmi_gfx_mgr02_driver.c
 **
 ** Description:    This module contains the DCU initialization routines to
 **                 setup the TFT timing parameters, QSPI and DMA
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_DRIVER_C
#define HMI_GFX_MGR02_PRIV_C
/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_KEPLER
#include "hmi_gfx_mgr02_dcu.h"
#include "hmi_gfx_mgr02_driver.h"
#include "hmi_gfx_mgr02_reg.h"
#include "dma.handler.h"
#include "graphics.h"
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
#if !defined(NUNIT_TESTING)
  #include "hmi_gfx_dcu_sim_w32.h"
#endif
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#if defined(GFX_MGR02_FARADAY)
 #ifndef GFX_MGR02_DCU_BLEND_ITER
  #define GFX_MGR02_DCU_BLEND_ITER (6)
 #endif
#elif defined(CWR_MPC5645S) || defined( CWR_MPC5645S_LITE )
 #define DCU_CLOCK_DISABLE()  (CGM.AC0_DC.B.DE0 = 0)
 #define DCU_CLOCK_ENABLE()   (CGM.AC0_DC.B.DE0 = 1)
#else
 #define DCU_CLOCK_DISABLE()
 #define DCU_CLOCK_ENABLE()
#endif

#ifndef GFX_MGR02_DCU_BLEND_ITER
 #define GFX_MGR02_DCU_BLEND_ITER (4)
#endif

#if defined(GFX_MGR02_FARADAY)
 #if (GFX_MGR02_DCU_BLEND_ITER < 2) || (GFX_MGR02_DCU_BLEND_ITER > 6)
  #error "Unsupported GFX_MGR02_DCU_BLEND_ITER\n"
 #endif
#else
 #if (GFX_MGR02_DCU_BLEND_ITER < 2) || (GFX_MGR02_DCU_BLEND_ITER > 4)
  #error "Unsupported GFX_MGR02_DCU_BLEND_ITER\n"
 #endif
#endif

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static void hmi_gfx_mgr02_driver_InitDCU(void);
#ifdef GFX_MGR02_USE_SHARP_LQ042
static void hmi_gfx_mgr02_driver_SetupLQ042(void);
#endif

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
#ifdef NUNIT_TESTING
extern UINT8 gfx_comp_array_boundary_error;
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_InitDCU(void)
**
** Visibility:          Static function.
**
** Description:         Initializes the DCU registers to a known state
**                      (defined below).
**
** Invocation:          Invoked by "hmi_gfx_mgr02_driver_startup()" during a common
**                      init.
**
** Inputs/Outputs:      DCU registers written.
**
** Critical Section:    None
**
** Created:             29/02/12 by ASHEKHAR
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
static void hmi_gfx_mgr02_driver_InitDCU(void)
{
  /*
  ** Initialize the DCU to a known set of conditions.  The conditions are:
  **
  ** 1)  DCU reset disabled (DCU_SW_RESET = 0)
  ** 2)  Two plane blend (BLEND_ITER = 2)
  ** 3)  PDI sync lock 0 frames (PDI_SYNC_LOCK = 0)
  ** 4)  PDI interpolate chroma same (PDI_INTERPOL_EN = 0)
  ** 5)  Disable pixel clock (RASTER_EN = 0)
  ** 6)  PDI disabled (PDI_EN = 0)
  ** 7)  PDI byte ordering LSB, MSB (PDI_BYTE_REV = 0)
  ** 8)  PDI ignore data enable signal (PDI_DE_MODE = 0)
  ** 9)  PDI narrow mode disabled (PDI_NARROW_MODE = 0)
  ** 10) PDI mode = 8 bit monochrome (PDI_MODE = 0)
  ** 11) PDI slave mode disabled (PDI_SLAVE_Mode = 0)
  ** 12) CRC calculated over whole area (TAG_EN = 0)
  ** 13) Signature calculator is disabled (SIG_EN = 0)
  ** 14) PDI sync from external source (PDI_SYNC = 0)
  ** 15) Gamma correction disabled (EN_GAMMA = 0)
  ** 16) DCU off (DCU_MODE = 0)
  */
  DCU.DCU_MODE.R = 0x00200000uL	;

  /*
  ** The CST-05 code package enables and selects the FMPLL0 clock for the
  ** pixel clock, so no need to do it here.
  */

  /*
  ** Set the default background color.
  */
  DCU.BGND.R = GFX_MGR02_DEFAULT_BACKGROUND_COLOR;

  /*
  ** All interrupts disabled except the vertical blank interrupt
  ** and DMA transfter finish.
  */
  DCU.INT_STATUS.R                  = 0xFFFFFFFFuL;
  DCU.INT_MASK.B.M_VS_BLANK         = 0;
  DCU.INT_MASK.B.M_DMA_TRANS_FINISH = 0;
}

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_SetupLQ042(void)
**
** Visibility:          Static function.
**
** Description:         Initializes the I/O for communication with a Sharp
**                      LQ042 display.
**
** Invocation:          Invoked by "hmi_gfx_mgr02_driver_startup()" during a common
**                      init.
**
** Inputs/Outputs:      None.
**
** Critical Section:    None
**
** Created:             29/02/12 by EMANOJ1
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
#ifdef GFX_MGR02_USE_SHARP_LQ042
static void hmi_gfx_mgr02_driver_SetupLQ042(void)
{
  /*
  ** Note the conditional compile that has been added to support the PC
  ** simulation.
  */
  #if !defined(WIN32) && !defined(MATLAB_MEX_FILE)
  UINT32 i;

  /*
  ** Config port A RED data lints as outputs and give control to the DCU.
  ** All lines should have the slew rate control (SRC) enabled to get maximum
  ** drive strength.
  */
  for(i = (UINT32)PA2; i <= (UINT32)PA7; i++)
  {
    SIU.PCR[i].R = 0x0604;
  }

  /*
  ** Config port A GREEN data lints as outputs and give control to the DCU.
  ** All lines should have the slew rate control (SRC) enabled to get maximum
  ** drive strength.
  */
  for(i = (UINT32)PA10; i <= (UINT32)PA15; i++)
  {
    SIU.PCR[i].R = 0x0604;
  }

  /*
  ** Config port G BLUE data lints as outputs and give control to the DCU.
  ** All lines should have the slew rate control (SRC) enabled to get maximum
  ** drive strength.
  */
  for(i = (UINT32)PG2; i <= (UINT32)PG7; i++)
  {
    SIU.PCR[i].R = 0x0604;
  }

  /*
  ** Configure the other signals similar to the RGB outputs.
  */
  SIU.PCR[PG8].R = 0x0604;  /* Vsynch */
  SIU.PCR[PG9].R = 0x0604;  /* Hsynch */
  SIU.PCR[PG10].R = 0x0604; /* DE     */
  SIU.PCR[PG11].R = 0x0604; /* Pclk   */
  #endif

  /*
  ** Configure the display size registers.
  */
  DCU.DISP_SIZE.B.DELTA_X = (480/16);
  DCU.DISP_SIZE.B.DELTA_Y = 272;

  /*
  ** Set up the timing registers per the Sharp specification.  In particular,
  ** note that the horizontal and vertical back porches differ from the spec
  ** because Sharp includes the horizontal and vertical pulse widths in the
  ** back porches but the DCU does not.
  **
  ** Display timing calculations:
  **
  ** Total clock cycles per frame =
  **  = (PWH + BPH + 480 + FPH) * (PWV + BPV + 272 + FPV)
  **  = [(5 + 112 + 480 + 2) * (2 + 29 + 272 + 2)
  **  = 599 * 305
  **  = 182695
  **
  ** At a pixel clock of 64MHz/6:
  **  = 182695 pixels * (1 pixel / 64/7)
  **  = (182695 * 7) / 64
  **  = 19982.265625
  **  = 19.982265625ms per frame
  **  = 50.04 FPS
  **
  ** Length of vertical blank period:
  **   Per Freescale, the physical blanking time experienced by the panel is
  **   PWV + BPV + FPV but the blanking time available for software activities
  **   is slightly shorter due to the fact that the DCU must arbitrate, fetch,
  **   decode and blend data to be ready for the first pixel after the
  **   physical blanking time.  The arbitration process starts one horizontal
  **   line before the end of the physical blanking period and this time is
  **   indicated by the PROG_END flag. So the blanking time is as follows:
  **
  **   Software blanking time = PWV + FPV + (BPV - 1)
  **    = 2 + 2 + 28 horizontal line cycles
  **    = 32 horizontal line cycles * 599 pixels per horizontal line
  **    = 19168 pixels
  **    = (19168 pixels * 7) / 64
  **    = 2.0965ms
  */
  DCU.HSYN_PARA.B.BP_H = SHARP_LQ042_BACK_PORCH_HORIZONTAL;  /* Horizontal back porch, in units of pixel clock cycles */
  DCU.HSYN_PARA.B.PW_H = SHARP_LQ042_PULSE_WIDTH_HORIZONTAL; /* Horizontal sync pulse width, in units of pixel clock cycles */
  DCU.HSYN_PARA.B.FP_H = SHARP_LQ042_FRONT_PORCH_HORIZONTAL; /* Horizontal front porch, in units of pixel clock cycles */

  DCU.VSYN_PARA.B.BP_V = SHARP_LQ042_BACK_PORCH_VERTICAL;  /* Vertical back porch, in units of horizontal line cycles */
  DCU.VSYN_PARA.B.PW_V = SHARP_LQ042_PULSE_WIDTH_VERTICAL; /* Vertical sync pulse width, in units of horizontal line cycles */
  DCU.VSYN_PARA.B.FP_V = SHARP_LQ042_FRONT_PORCH_VERTICAL; /* Vertical front porch, in units of horizontal line cycles */

  DCU.DIV_RATIO.R = SHARP_LQ042_DIV_RATIO; /* Clock divider = 64MHz/7 = 9.14MHz pixel clock */

  DCU.SYN_POL.R = 0x00000003; /* Synchro neg */
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_driver_startup
 ** Visibility:       global
 ** Description:      Initializes the DCU, QSPI and freescale library
 ** Invocation:       By presentation layer when ever it wants to restart.
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-May-2011 by ASHEKHAR
 ** Updated:          09-Oct-2012 by ASHEKHAR
 **==========================================================================*/
void hmi_gfx_mgr02_driver_startup(void)
{
  UINT32 i;

#ifdef HMI_GFX_MGR02_GAMMA_CORRECTION
    static UINT8 fl_gamma_correction_red_table[GFX_MGR02_NUM_OF_GAMMA_VALUES] = GFX_MGR02_GAMMA_RED_CORRECTION_TABLE;
    static UINT8 fl_gamma_correction_green_table[GFX_MGR02_NUM_OF_GAMMA_VALUES] = GFX_MGR02_GAMMA_GREEN_CORRECTION_TABLE;
    static UINT8 fl_gamma_correction_blue_table[GFX_MGR02_NUM_OF_GAMMA_VALUES] = GFX_MGR02_GAMMA_BLUE_CORRECTION_TABLE;
    UINT32 * fl_gamma_red_ram_U32AP   = (UINT32 *)(void *)&DCU.GAMMARED[0];
    UINT32 * fl_gamma_green_ram_U32AP = (UINT32 *)(void *)&DCU.GAMMAGREEN[0];
    UINT32 * fl_gamma_blue_ram_U32AP  = (UINT32 *)(void *)&DCU.GAMMABLUE[0];
    UINT8 * fl_gamma_red_calib_U8AP   = fl_gamma_correction_red_table;
    UINT8 * fl_gamma_green_calib_U8AP = fl_gamma_correction_green_table;
    UINT8 * fl_gamma_blue_calib_U8AP  = fl_gamma_correction_blue_table;
    UINT32 fl_gamma_index_U32;
    for (fl_gamma_index_U32 = 0; fl_gamma_index_U32 < GFX_MGR02_NUM_OF_GAMMA_VALUES; fl_gamma_index_U32++)
    {
       *fl_gamma_red_ram_U32AP   = (UINT32)*fl_gamma_red_calib_U8AP;
       *fl_gamma_green_ram_U32AP = (UINT32)*fl_gamma_green_calib_U8AP;
       *fl_gamma_blue_ram_U32AP  = (UINT32)*fl_gamma_blue_calib_U8AP;
       fl_gamma_red_ram_U32AP    = &fl_gamma_red_ram_U32AP[1];
       fl_gamma_green_ram_U32AP  = &fl_gamma_green_ram_U32AP[1];
       fl_gamma_blue_ram_U32AP   = &fl_gamma_blue_ram_U32AP[1];
       fl_gamma_red_calib_U8AP    = &fl_gamma_red_calib_U8AP[1];
       fl_gamma_green_calib_U8AP = &fl_gamma_green_calib_U8AP[1];
       fl_gamma_blue_calib_U8AP  = &fl_gamma_blue_calib_U8AP[1];
    }
#endif

  /*
  ** On the Rainbow device, it is necessary to bypass the TCON otherwise
  ** the display will be blank.
  */
#if !defined(WIN32) && !defined(MATLAB_MEX_FILE)
 #if defined(GFX_MGR02_FARADAY)
  DCU_CLOCK_DIV();
  DCU_CLOCK_SEL();  
  TCON.CTRL1.B.TCON_BYPASS = 1;
 #elif defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  TCON.CTRL1.B.TCON_BYPASS = 1;
 #else
 #endif
  /*
  ** As soon as we configure the function mode of TFT clock pin, the clock
  ** will start outputing from the pin. In order to prevent it until we enable
  ** the data transmission, here we are disabling the clock to the DCU itself.
  ** This will be enabled after all DCU configuration is done and after the
  ** DCU_MODE is made 1
  */
  DCU_CLOCK_DISABLE();
#endif

  /*
  ** Initialize the DCU.
  */
  hmi_gfx_mgr02_driver_InitDCU();

  /*
  ** Set up the timing for the Sharp LQ042 TFT if configured.  If not, execute
  ** a user defined function to setup the display timing.
  */
#ifdef GFX_MGR02_USE_SHARP_LQ042
  hmi_gfx_mgr02_driver_SetupLQ042();
#else
  GFX_MGR02_PROD_SPEC_DISPLAY_SETUP();
#endif

   /*
   ** Init the Freescale library code.
   */
#if defined(GFX_MGR02_INIT_DMA)
   DMA_Handler_Init();
#endif
   Graphics_Init();
   /*
  ** Init all the layer control descriptors to a known state.
  */
  for (i = 0; i < (UINT32)GFX_MGR02_NUM_DCU_LAYERS; i++)
  {
     hmi_gfx_mgr02_driver_init_layer(i);
  }
  DCU.DCU_MODE.B.BLEND_ITER = GFX_MGR02_DCU_BLEND_ITER;
}

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_shutdown(void)
**
** Visibility:          global function.
**
** Description:         DeActivates the DMA transfer if it is active when system
**                      requires shutdown, this ensures that callback doesn't get
**                      trigger even after DMA Tx completed.
**
** Invocation:          Invoked by "hmi_gfx_mgr02_driver_startup()" during a common
**                      init.
**
** Inputs/Outputs:      DCU registers written.
**
** Critical Section:    None
**
** Created:             29/02/12 by ASHEKHAR
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_driver_shutdown(void)
{
   hmi_gfx_mgr02_driver_disable_dcu();
#if defined(GFX_MGR02_INIT_DMA)
   DMA_Handler_DeInit();
#endif
}

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_dcu_isr(void)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02_driver.h" header file.
** Description:         This is used to trigger the DCU configuration when VS_BLANK interrupt
**                      is triggered.
**
** Invocation:          Invoked by the DCU ISR
**
** Inputs/Outputs:      None.
**
** Critical Section:    None
**
** Created:             27/02/2012 by ASHEKHAR
**
** Updated:             27/02/2012 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_driver_dcu_isr(void)
{
  if(DCU.INT_STATUS.B.DMA_TRANS_FINISH != (UINT8)0)
  {
     /*
     ** Clear the interrupt flag.
     */
     hmi_gfx_mgr02_vblank_isr(GFX_MGR02_DCU_TXFR_FINISH);
     DCU.INT_STATUS.R = 0x00004000;
  }
  if (DCU.INT_STATUS.B.VS_BLANK != (UINT8)0)
  {
     /*
     ** Clear the interrupt flag.
     */
     hmi_gfx_mgr02_vblank_isr(GFX_MGR02_DCU_VSYNC_START);
     DCU.INT_STATUS.R = 0x00000008;
  }
}

/*============================================================================
**
** Function Name:       void gdg02_EnableDCU(void)
**                      void gdg02_EnableDCULite(void)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02_driver.h" header file.
**
** Description:         This function turns on the DCU.  When this happens,
**                      objects that have been placed into the various
**                      layers and/or the cursor memory will be blended
**                      and the display updated accordingly.
**
** Invocation:          Called by the application code whenever the DCU should
**                      be enabled.  Typically, this occurs once after a
**                      transition of the ignition switch into RUN and
**                      layers have been enabled with various graphical
**                      objects to be displayed.
**
** Inputs/Outputs:      None
**
** Critical Section:    None
**
** Created:             29/02/12 by EMANOJ1
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_driver_enable_dcu(void)
{
  DCU.DCU_MODE.B.RASTER_EN = 1;
  DCU.DCU_MODE.B.DCU_MODE  = 1;

  DCU.INT_STATUS.R                  = 0xFFFFFFFFuL;
  DCU.INT_MASK.B.M_VS_BLANK         = 0;
  DCU.INT_MASK.B.M_DMA_TRANS_FINISH = 0;

#ifdef HMI_GFX_MGR02_GAMMA_CORRECTION
  DCU.DCU_MODE.B.EN_GAMMA = 1;
#endif
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
 #if !defined(NUNIT_TESTING)
  hmi_gfx02_dcu_sim_init(1);
 #endif
#else
  /*
  ** Enable the clock to the DCU so that the TFT signals can begin.
  */
  DCU_CLOCK_ENABLE();
#endif
}

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_disable_dcu(void)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02_driver.h" header file.
**
** Description:         This function turns off the DCU.  When this happens,
**                      the display will no longer be updated by the DCU.
**
** Invocation:          Called by the application code whenever the DCU should
**                      be disabled.  Typically, this occurs once after a
**                      transition of the ignition switch into OFF and
**                      the display is no longer required.
**
** Inputs/Outputs:      None.
**
** Critical Section:    None
**
** Created:             29/02/12 by EMANOJ1
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_driver_disable_dcu(void)
{
  DCU.DCU_MODE.B.RASTER_EN  = 0;
  DCU.DCU_MODE.B.DCU_MODE   = 0;

  DCU.INT_MASK.B.M_VS_BLANK         = 1;
  DCU.INT_MASK.B.M_DMA_TRANS_FINISH = 1;
  DCU.INT_STATUS.R                  = 0xFFFFFFFFuL;

#ifdef HMI_GFX_MGR02_GAMMA_CORRECTION
  DCU.DCU_MODE.B.EN_GAMMA = 0;
#endif
}

/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_driver_init_layer(UINT32 layer)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02_driver.h" header file.
**
** Description:         This function initializes a layer of the DCU to
**                      a known set of conditions.  The conditions are:
**
**                      1) Layer disabled (EN = 0)
**                      2) Tile mode disabled (TILE_EN = 0)
**                      3) Tile mode data from MCU memory (DATA_SEL = 0) (Spectrum only)
**                      4) Safety mode disabled (SAFETY_EN = 0)
**                      5) Transparency = 100% (TRANS = 0xFF), not transparent
**                      6) Bits-per-pixel = 1 (BPP = 0)
**                      7) Lookup table offset = 0 (LUOFFS = 0)
**                      8) Chroma keying off (BB = 0)
**                      9) Alpha blending off (AB = 0)
**
**                      In addition, the chroma key min and max registers
**                      are set to 0x00000000.  This is important because
**                      the special transparency mode (BB = 1, AB = 2)
**                      will use the min/max values to remove pixels.  To
**                      eliminate this from accidentally happening, we
**                      set the registers to a combination that is not
**                      expected to be used.
**
** Invocation:          Called by the application code whenever it wishes
**                      to initialize a layer for further writing.  It is not
**                      absolutely necessary to use this function since
**                      functions exist to write all of the aforementioned
**                      values.  However, it is highly recommended that
**                      this be used to get the layer to a known state
**                      before attempting further writes to it.
**
** Inputs/Outputs:      The "layer" input parameter selects the layer
**                      to be initialized, and can range from 0 to 15.
**
** Critical Section:    None
**
** Created:             29/02/12 by EMANOJ1
**
** Updated:             16/03/12 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_driver_init_layer(UINT32 layer)
{
    if(layer < (UINT32)GFX_MGR02_NUM_DCU_LAYERS)
    {
#if !defined(WIN32) && !defined(MATLAB_MEX_FILE)
        DCU.LAYER[layer].CTRLDESCL4.R = 0x0FF00000uL;
#else
        DCU.LAYER[layer].CTRLDESCL4.R = 0x00000FF0uL;
#endif
        DCU.LAYER[layer].CTRLDESCL5.R = 0x00000000;
        DCU.LAYER[layer].CTRLDESCL6.R = 0x00000000;
    }
    else
    {
#ifdef NUNIT_TESTING
        gfx_comp_array_boundary_error = 1;
#endif
    }
}

#ifdef HMI_GFX_MGR02_ENABLE_DCU_TEST
/*============================================================================
**
** Function Name:       UINT32 hmi_gfx_mgr02_EnableDCUTest(void)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02.h" header file.
**
** Description:         This function turns on a special DCU test mode which
**                      displays 8 vertical colorbars of equal width across
**                      the TFT being controlled.  It is a quick and simple
**                      way to see if the display is hooked up properly to
**                      the DCU and to see if the DCU timing registers
**                      have been properly configured for the display in
**                      question.
**
**                      From left to right, the colorbars default to black,
**                      dark blue, light blue, green, yellow, red, purple
**                      and white.  These default values can be changed by
**                      using the "hmi_gfx_mgr02_SetColorBarRGB()" function.
**
**                      NOTE:  This function is conditionally compiled and
**                      only exists if HMI_GFX_MGR02_ENABLE_DCU_TEST is enabled.
**
** Invocation:          Called by the application code whenever the DCU test
**                      mode should be enabled.
**
** Inputs/Outputs:      None.
**
** Critical Section:    None
**
** Created:             06/27/2012 by ASHEKHAR
**
** Updated:             06/27/2012 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_EnableDCUTest(void)
{
     DCU.DCU_MODE.B.RASTER_EN = 1;
     DCU.DCU_MODE.B.DCU_MODE  = 3;
}

 /*============================================================================
**
** Function Name:       UINT32 hmi_gfx_mgr02_SetColorBarRGB(UINT32 color_bar_num, UINT32 rgb_value)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02.h" header file.
**
** Description:         This function allows changing of the default
**                      RGB values for the colorbars that can be enabled
**                      via the "hmi_gfx_mgr02_EnableDCUTest()" function.
**
**                      From left to right, the colorbars default to black,
**                      dark blue, light blue, green, yellow, red, purple
**                      and white.  These default values can be changed by
**                      using the "hmi_gfx_mgr02_SetColorBarRGB()" function.
**
**                      NOTE:  This function is conditionally compiled and
**                      only exists if HMI_GFX_MGR02_ENABLE_DCU_TEST is enabled.
**
** Invocation:          Called by the application code whenever it wishes
**                      to change the color of one of the colorbars.
**
** Inputs/Outputs:      The "color_bar_num" input parameter selects the
**                      colorbar to be updated, where 0 is the leftmost and
**                      7 is the rightmost.
**
**                      The "rgb_value" input parameter selects the
**                      RGB value.  The MS 8-bits are ignored, the next
**                      8-bits are the R value, then the G value, then
**                      the B value.
**
**                      This function returns FALSE if a value greater than 7 is selected.
**                      Otherwise, it returns TRUE.
**
** Critical Section:    None
**
** Created:             06/27/2012 by ASHEKHAR
**
** Updated:             06/27/2012 by ASHEKHAR
**
**==========================================================================*/
UINT32 hmi_gfx_mgr02_SetColorBarRGB(UINT32 color_bar_num, UINT32 rgb_value)
{
  UINT32 retval = FALSE;

  /*
  ** Verify proper selection of the color bar number before proceeding.
  */
  if (color_bar_num <= (UINT32)7)
  {
    DCU.COLBAR[color_bar_num].R = rgb_value;
    retval = TRUE;
  }
  return(retval);
}
#endif

#endif /* #ifdef GFX_MGR02_KEPLER */
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
 **  Rev 1.6         15-Jul-2015    EMANOJ1
 **  RTC #349460 :- DCU.INT_STATUS.R is written FFFFFFFF to clear all pending 
 **  status during init.
 **
 **  Rev 1.5         27-Aug-2013    EMANOJ1
 **  Updated to support the infrastructure DMA manager core package instead of the
 **  freescale DMA.c
 **
 **  Rev 1.4         21-Nov-2012    ASHEKHAR
 **  CGM.AC0_DC.R moved to conditional compilation as this is not avialable in
 **  Spectrum micro, reported by P552 team.
 **
 **  Rev 1.3         09-Oct-2012    ASHEKHAR
 **  Moved gamma correction values setting from manager to driver.
 **
 **  Rev 1.2         04-Sep-2012    ASHEKHAR
 **  Updated to added gamma correction feature.
 **
 **  Rev 1.1         27-Jan-2012    ASHEKHAR
 **
 ** CMS Rev 1.0      05-May-2011    EMANOJ1
 ** Creation.
 **==========================================================================*/

/* end of file =============================================================*/
