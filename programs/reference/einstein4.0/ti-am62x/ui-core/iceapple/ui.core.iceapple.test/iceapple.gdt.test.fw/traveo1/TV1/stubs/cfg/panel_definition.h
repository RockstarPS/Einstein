/************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)           */
/*                                                                      */
/* The following software deliverable is intended for and must only be  */
/* used for reference and in an evaluation laboratory environment.      */
/* It is provided on an as-is basis without charge and is subject to    */
/* alterations.                                                         */
/* It is the user's obligation to fully test the software in its        */
/* environment and to ensure proper functionality, qualification and    */
/* compliance with component specifications.                            */
/*                                                                      */
/* In the event the software deliverable includes the use of open       */
/* source components, the provisions of the governing open source       */
/* license agreement shall apply with respect to such software          */
/* deliverable.                                                         */
/* FSEU does not warrant that the deliverables do not infringe any      */
/* third party intellectual property right (IPR). In the event that     */
/* the deliverables infringe a third party IPR it is the sole           */
/* responsibility of the customer to obtain necessary licenses to       */
/* continue the usage of the deliverable.                               */
/*                                                                      */
/* To the maximum extent permitted by applicable law FSEU disclaims all */
/* warranties, whether express or implied, in particular, but not       */
/* limited to, warranties of merchantability and fitness for a          */
/* particular purpose for which the deliverable is not designated.      */
/*                                                                      */
/* To the maximum extent permitted by applicable law, FSEU's liability  */
/* is restricted to intentional misconduct and gross negligence.        */
/* FSEU is not liable for consequential damages.                        */
/*                                                                      */
/* (V1.5)                                                               */
/************************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     1.0
 * \date        2011
 * \file        panel_definition.h
 *              Calypso Starter Kit Display Setup Settings.
 *
 *
 * \attention  THIS SAMPLE CODE IS PROVIDED AS IS.
 *             FUJITSU SEMICONDUCTOR ACCEPTS NO RESPONSIBILITY OR LIABILITY
 *             FOR ANY ERRORS OR OMMISSIONS.
 */

#ifndef __PANEL_DEFINITION_H__
#define __PANEL_DEFINITION_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static const MML_GDC_DISP_TCON_PROPERTIES stTConConfig[] =
{
    { 0x00000534, 0x00000091 }, /* GFXTCON_DIR_PIN0_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000538, 0x00000091 }, /* GFXTCON_DIR_PIN1_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x0000053C, 0x00000091 }, /* GFXTCON_DIR_PIN2_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000540, 0x00000091 }, /* GFXTCON_DIR_PIN3_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000544, 0x00000091 }, /* GFXTCON_DIR_PIN4_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000548, 0x00000091 }, /* GFXTCON_DIR_PIN5_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x0000054C, 0x00000091 }, /* GFXTCON_DIR_PIN6_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000550, 0x00000091 }, /* GFXTCON_DIR_PIN7_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000554, 0x00000091 }, /* GFXTCON_DIR_PIN8_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000558, 0x00000091 }, /* GFXTCON_DIR_PIN9_CTRL  - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x0000055C, 0x00000091 }, /* GFXTCON_DIR_PIN10_CTRL - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000560, 0x00000091 }, /* GFXTCON_DIR_PIN11_CTRL - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x00000564, 0x00000091 }, /* GFXTCON_DIR_PIN12_CTRL - set Boost = 1 (4 mA), Mode = 1 (TTL) and InOut = 1 (output) */
    { 0x0000052C, 0x00000009 }  /* GFXTCON_DIR_RBM_CTRL   - set BitsPerCol = 1 (8), IfcType = 0 (TTL), ByPass = 1 (bypass mode) */
};
#if defined(GFX_MGR02_FUJITSU)
static const MML_GDC_DISP_CLOCK_PARAMS stDispClockParams =
{
    10,           /*!< Set frequency divider to 11 (2nd divider has factor 2) (clock: 200/(2+1)/2 = 33.3 MHz). */
    2,            /*!< No phase shift.                                         */
    0             /*!< No clock inversion.                                     */
};
/**
 * The 'virtual' display parameters.
 **/
const MML_GDC_IRS_DISP_PROPERTIES l_mml_gdc_dispParams = {
    /* DISP parameters (display controller). */
    543,        /*!< Horizontal Total Pixels (0..4095).               */
    501,        /*!< Horizontal Synchronize pulse Position (0..4095). */
    21,          /*!< Horizontal Synchronize pulse Width (0..255).     */
    480,        /*!< Horizontal Display Period (0..4095).             */
    278,        /*!< Vertical Total Raster (0..4095).                 */
    273,        /*!< Vertical Synchronize pulse Position (0..4095).   */
    1,          /*!< Vertical Synchronize pulse Width (0..63).        */
    272,        /*!< Vertical Display Period (0..4095).               */

    &stDispClockParams,  /*!< Clock parameters.                       */
    /* Connected panel parameters. */
    MML_GDC_DISP_INTERFACE_TTL,      /*!< Panel interface type.    */
    MML_GDC_DISP_BITS_PER_COLOR_8,   /*!< Panel bits per color.    */
    /* TCON (timing controller) parameters. */
    stTConConfig,                 /*!< TCON register address, value pairs. */
    1UL,                          /*!< Bypass TCON. */
    sizeof(stTConConfig)/sizeof(MML_GDC_DISP_TCON_PROPERTIES) /*!< TCON struct nr. of elements */
};
#endif
#if defined(GFX_MGR02_AMBER)

MML_GDC_DISP_MODE_LINE l_disp_timing0 ={
    34.0f,                           /**< Pixel clock in units of MHz */
    800,                             /**< Horizontal Display Period - Illuminated area */
    852,                             /**< Number of the dot when the sync pulse starts */
    862,                             /**< Number of the dot when the sync pulse ends */
    1056,                            /**< Total horizontal */
    480,                             /**< Vertical display period - Illuminated area */
    490,                             /**< Vertical sync pulse start position */
    495,                             /**< Vertical sync end position */
    525,                             /**< Total vertical lines */
    1024,                            /**< Minimal total horizontal lines, is ignored when direct capture is not enabled. */
    1088,                            /**< Maximal total horizontal lines, is ignored when direct capture is not enabled. */
    520,                             /**< Minimal total vertical lines, is ignored when direct capture is not enabled. */
    530,                             /**< Maximal total vertical lines, is ignored when direct capture is not enabled. */
    3,                               /**< Number of display clock delay, default no additional delay, value is in [0, 16] */

    MML_GDC_DISP_DCK_INVERT_OFF,     /**< Enable inversion of display clock, default set as not inverted */
    NULL,                            /**< Handle returned from ::mmlGdcCapOpen. Valid handle enables the direct capture (
                                          capture-to-display) mode, no buffer, display is synced to video, the video 
                                          timing and resolution must be same as the display. Default value is NULL. */
    MML_GDC_DISP_DE_HIGH,            /**<  Bit field combination of polarity control possibilities: \n    ::MML_GDC_DISP_HSYNC_LOW / ::MML_GDC_DISP_HSYNC_HIGH
                                                                                               \n    ::MML_GDC_DISP_VSYNC_LOW / ::MML_GDC_DISP_VSYNC_HIGH
                                                                                               \n    ::MML_GDC_DISP_DE_LOW / ::MML_GDC_DISP_DE_HIGH
                                                                                               \n    ::MML_GDC_DISP_RGB_LOW / ::MML_GDC_DISP_RGB_HIGH. 
                                      \nDefault value ::MML_GDC_DISP_HSYNC_LOW|::MML_GDC_DISP_VSYNC_LOW|::MML_GDC_DISP_DE_HIGH|::MML_GDC_DISP_RGB_LOW. */
};


MML_GDC_DISP_MODE_LINE l_disp_timing1 ={
    7.4f,                           /**< Pixel clock in units of MHz */
    450,                            /**< Horizontal Display Period - Illuminated area */
    485,                            /**< Number of the dot when the sync pulse starts */
    505,                            /**< Number of the dot when the sync pulse ends */
    520,                            /**< Total horizontal */
    167,                            /**< Vertical display period - Illuminated area */
    170,                            /**< Vertical sync pulse start position */
    172,                            /**< Vertical sync end position */
    174,                            /**< Total vertical lines */
    450,                            /**< Minimal total horizontal lines, is ignored when direct capture is not enabled. */
    520,                            /**< Maximal total horizontal lines, is ignored when direct capture is not enabled. */
    167,                            /**< Minimal total vertical lines, is ignored when direct capture is not enabled. */
    174,                            /**< Maximal total vertical lines, is ignored when direct capture is not enabled. */
    0,                              /**< Number of display clock delay, default no additional delay, value is in [0, 16] */
    MML_GDC_DISP_DCK_INVERT_OFF,    /**< Enable inversion of display clock, default set as not inverted */
    NULL,                           /**< Handle returned from ::mmlGdcCapOpen. Valid handle enables the direct capture (
                                          capture-to-display) mode, no buffer, display is synced to video, the video
                                          timing and resolution must be same as the display. Default value is NULL. */
    MML_GDC_DISP_DE_HIGH | MML_GDC_DISP_HSYNC_LOW | MML_GDC_DISP_VSYNC_LOW,
                                    /**<  Bit field combination of polarity control possibilities:
                                     * \n    ::MML_GDC_DISP_HSYNC_LOW / ::MML_GDC_DISP_HSYNC_HIGH
                                       \n    ::MML_GDC_DISP_VSYNC_LOW / ::MML_GDC_DISP_VSYNC_HIGH
                                       \n    ::MML_GDC_DISP_DE_LOW / ::MML_GDC_DISP_DE_HIGH
                                       \n    ::MML_GDC_DISP_RGB_LOW / ::MML_GDC_DISP_RGB_HIGH.
                                      \nDefault value ::MML_GDC_DISP_HSYNC_LOW|::MML_GDC_DISP_VSYNC_LOW|
                                                      ::MML_GDC_DISP_DE_HIGH|::MML_GDC_DISP_RGB_LOW. */
};


static const MML_GDC_DISP_TCON_PROPERTIES tconConfig0[] = {
        {0x0418, 0x15141312},       // MapBit3_0   ( B5, B4, B3, B2)
        {0x041C, 0x0B0A1716},       // MapBit7_4   ( G3, G2, B7, B6)
        {0x0420, 0x0F0E0D0C},       // MapBit11_8  ( G7, G6, G5, G4)
        {0x0424, 0x05040302},       // MapBit15_12 ( R5, R4, R3, R2)
        {0x0428, 0x1F1F0706},       // MapBit19_16 (  0,  0, R7, R6)
        {0x042C, 0x1F1F1F1F},       // MapBit23_20 (  0,  0,  0,  0)
};

static const MML_GDC_DISP_TCON_PROPERTIES tconConfig1[] = {
        {0x0418, 0x1F1F1F1F},       // MapBit3_0   (  0,  0,  0,  0)
        {0x041C, 0x16171F1F},       // MapBit7_4   ( B6, B7,  0,  0)
        {0x0420, 0x12131415},       // MapBit11_8  ( B2, B3, B4, B5)
        {0x0424, 0x0C0D0E0F},       // MapBit15_12 ( G4, G5, G6, G7)
        {0x0428, 0x06070A0B},       // MapBit19_16 ( R6, R7, G2, G3)
        {0x042C, 0x02030405},       // MapBit23_20 ( R2, R3, R4, R5)
};

const MML_GDC_DISP_PROPERTIES l_mml_gdc_dispParams[1] =
{
    MML_GDC_DISP_CONTROLLER_0,                  /**< Which display controller to use */
    MML_GDC_DISP_SINGLE_SCREEN,                 /**< Only single screen mode is currently supported: must be set to MML_GDC_DISP_SINGLE_SCREEN. */
    MML_GDC_DISP_SYNC_MODE_NONE,                /**< Determines the operating mode of the display for Side-by-Side synchronization. */
    800,                                        /**< Horizontal resolution (640, 800, 1024, etc.).     */
    480,                                        /**< Vertical resolution (480, 600, 768, etc.).        */
    60,                                         /**< Refresh rate in Hz (60, 75, 85, etc.).            */
    1,                                          /**< Set to a non-zero value to have the driver use the modeLine settings specified by modeLine.  */
    &l_disp_timing0,                            /**< Custom display timing information.  */
    (MML_GDC_DISP_TCON_PROPERTIES*)tconConfig0, /**< Pointer to TCON register/value structure array. Must be NULL if no TCON is used. */
    sizeof(tconConfig0) / sizeof(MML_GDC_DISP_TCON_PROPERTIES) /**< Number of TCON registers to be programmed. Must be zero if no TCON is used.*/
};
#endif
#if defined(GFX_MGR02_TRAVEO2)

static CYGFX_DISP_TCON_PROPERTIES_S tconConfig[] =
{
        { 0x0408, 0x00000108}, /* CTRL (ENLVDS | BYPASS) */
        { 0x0410, 0x03040508}, /* MapBit3_0   ( R3, R4, R5, G0)     */
        { 0x0414, 0x11000102}, /* MapBit7_4   ( B1, R0, R1, R2)     */
        { 0x0418, 0x0B0C0D10}, /* MapBit11_8  ( G3, G4, G5, B0)     */
        { 0x041c, 0x191A090A}, /* MapBit15_12 ( VSYNC, EN, G1, G2)  */
        { 0x0420, 0x13141518}, /* MapBit19_16 ( B3, B4, B5, HSYNC)  */
        { 0x0424, 0x16171B12}, /* MapBit23_20 ( B6, B7, RES, B2)    */
        { 0x0428, 0x06070E0F}, /* MapBit27_24 ( R6, R7, G6, G7)     */
};

const CYGFX_DISP_PROPERTIES_S l_mml_gdc_dispParams[1] = {
      CYGFX_DISP_CONTROLLER_0,
      CYGFX_DISP_MODE_SINGLE_SCREEN,
      CYGFX_DISP_SYNC_MODE_NONE,
      {
        29.2f,                             /* pixelClock */
        800,                                /* Hact */
        480,                                /* Vact */
        928,                                /* Htot */
        525,                                /* Vtot */
        88,                                /* Hsbp */
        32,                                 /* Vsbp */
        48,                                 /* Hsync */
        3,                                  /* Vsync */
        893,                                /* HtotMin */
        517,                                /* VtotMin */
        1003,                               /* HtotMax */
        579,                                /* VtotMax */
        CYGFX_DISP_DCK_INVERT_OFF,          /* DCKInvertEnable */
        CYGFX_GEN_POLARITY_HIGH,            /* polEn */
        CYGFX_GEN_POLARITY_LOW,             /* polHs */
        CYGFX_GEN_POLARITY_LOW,             /* polVs */
        CYGFX_DISP_RGB_LOW                  /* pixInv */
      },
      tconConfig,
      sizeof(tconConfig) / sizeof(CYGFX_DISP_TCON_PROPERTIES_S)
};
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PANEL_DEFINITION_H__ */
