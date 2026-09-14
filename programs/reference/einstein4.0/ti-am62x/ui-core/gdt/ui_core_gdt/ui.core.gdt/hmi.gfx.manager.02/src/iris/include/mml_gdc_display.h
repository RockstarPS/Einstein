/********************************************************************/
/*          (c) 2011 Fujitsu Semiconductor Europe GmbH              */
/*                                                                  */
/* ALL RIGHTS RESERVED. No part of this publication may be copied   */
/* and provided to any third party in any form or by any means      */
/* without the written permission of Fujitsu, unless expressly      */
/* agreed to in written form by Fujitsu.                            */
/* All trademarks used in this document are the property of their   */
/* respective owners.                                               */
/*                                                                  */
/* For further provisions please refer to the respective License    */
/* Agreement.                                                       */
/* (V1.3)                                                           */
/********************************************************************/

/**
 * \author      Fujitsu Semiconductor Europe GmbH - GCC Neuried
 * \date        2011
 * \file        mml_gdc_display.h
 * \brief       Display Controller API
 *
 */

#ifndef MML_GDC_DISPLAY_H
#define MML_GDC_DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 Includes
*******************************************************************************/

/**
 * @defgroup display_api Display API
 *  The Display API exposes all the hardware features of the display
 *  controller. This includes:\n
 *  - configuring video modes\n
 *  - using windows/layers for rendering \n
 *  - dithering\n
 *  - gamma correction\n
 *  - blending and transparency of windows/layers\n
 *
 *
 * @{
 */

/*******************************************************************************
 Definitions
*******************************************************************************/

/**
 * Error values returned from this API.
 */
#define MML_ERR_GDC_DISP_DEVICE_NOT_FOUND       MM_ERRCODE(0xC00C0101)  /*!< The display adapter requested was not found                          */
#define MML_ERR_GDC_DISP_DISPLAY_ALREADY_OPEN   MM_ERRCODE(0xC00C0102)  /*!< The display being opened was already open.                           */
#define MML_ERR_GDC_DISP_INVALID_ARG            MM_ERRCODE(0xC00C0103)  /*!< An invalid argument was passed                                       */
#define MML_ERR_GDC_DISP_UNSUPPORTED_MODE       MM_ERRCODE(0xC00C0104)  /*!< A display mode was requested that is not supported on the hardware   */
#define MML_ERR_GDC_DISP_DEVICE_INIT_FAILED     MM_ERRCODE(0xC00C0105)  /*!< Hardware device(s) failed initialization                             */
#define MML_ERR_GDC_DISP_DEVICE_CLOSE_FAILED    MM_ERRCODE(0xC00C0106)  /*!< Hardware device(s) failed to close                                   */
#define MML_ERR_GDC_DISP_OUT_OF_SYSTEM_MEMORY   MM_ERRCODE(0xC00C0107)  /*!< The system is out of memory.                                         */
#define MML_ERR_GDC_DISP_LAYER_ALREADY_USED     MM_ERRCODE(0xC00C0108)  /*!< The requested layer is already being used                            */
#define MML_ERR_GDC_DISP_WRONG_PIXEL_FORMAT     MM_ERRCODE(0xC00C0109)  /*!< The pixel format is not supported by the display controller          */
#define MML_ERR_GDC_DISP_WRONG_STRIDE           MM_ERRCODE(0xC00C010A)  /*!< The stride of the pixel buffer must be a multiple of 64              */
#define MML_ERR_GDC_DISP_WRONG_WINDOW           MM_ERRCODE(0xC00C010B)  /*!< The given window object is not valid                                 */
#define MML_ERR_GDC_DISP_WRONG_INDEX_WINDOW     MM_ERRCODE(0xC00C010C)  /*!< The layer does not support an indexed color format                   */
#define MML_ERR_GDC_DISP_FAILED                 MM_ERRCODE(0xC00C010D)  /*!< The operation failed for an unknown reason                           */
#define MML_ERR_GDC_DISP_WRONG_YC_WINDOW        MM_ERRCODE(0xC00C010E)  /*!< The layer does not support a YC format                               */
#define MML_ERR_GDC_DISP_INVALID_ATTRIBUTE      MM_ERRCODE(0xC00C010F)  /*!< Invalid attribute (target) was specified for an argument. */
#define MML_ERR_GDC_DISP_INVALID_PARAMETER      MM_ERRCODE(0xC00C0110)  /*!< Invalid parameter was specified for an argument. */
#define MML_ERR_GDC_DISP_INVALID_HW             MM_ERRCODE(0xC00C0111)  /*!< The requestet operation si not supported for this hardware */
#define MML_ERR_GDC_DISP_INVALID_LAYER          MM_ERRCODE(0xC00C0112)  /*!< The given layer id is invalid                                        */
#define MML_ERR_GDC_DISP_INVALID_ROP_MODE       MM_ERRCODE(0xC00C0113)  /*!< The ROP mode is not suported for the display path                    */
#define MML_ERR_GDC_DISP_INVALID_DISPLAY        MM_ERRCODE(0xC00C0114)  /*!< The display was not correct initialized */
#define MML_ERR_GDC_DISP_INVALID_SURFACE        MM_ERRCODE(0xC00C0115)  /*!< Surface object invalid */
#define MML_ERR_GDC_DISP_INVALID_MATRIX         MM_ERRCODE(0xC00C0116)  /*!< The given matrices cannot applied to hardware */

#ifdef CMODEL
IRIS_API MM_S32 IrisSwKick(void);
#define IRIS_KICK() IrisSwKick()
#else
#define IRIS_KICK()
#endif


/*******************************************************************************
 Macro Definitions
*******************************************************************************/

/*******************************************************************************
 Data Types
*******************************************************************************/

/**
 * Window-system-dependent types
 */
typedef struct __MML_GDC_DISPLAY*           MML_GDC_DISPLAY;
typedef struct __MML_GDC_DISP_WINDOW*       MML_GDC_DISP_WINDOW;

/* TCON setup element */
typedef struct MML_GDC_DISP_TCON_PROPERTIES {
   MM_U32 address;              /*!< Address of the TCON register */
   MM_U32 value;                /*!< Value of the TCON register */
} MML_GDC_DISP_TCON_PROPERTIES;


/* Dither output alignment */
typedef enum
{
    MML_GDC_DISP_DITHER_ALIGNMENT_RIGHT = 0x0UL,     /*!< Dither output data byte aligned right */
    MML_GDC_DISP_DITHER_ALIGNMENT_LEFT               /*!< Dither output data byte aligned left  */
} MML_GDC_DISP_DITHER_ALIGNMENT;

/* Dither output format */
typedef enum
{
    MML_GDC_DISP_DITHER_FORMAT_888 = 0x0UL,      /*!< Dither output format 888 */
    MML_GDC_DISP_DITHER_FORMAT_777,              /*!< Dither output format 777 */
    MML_GDC_DISP_DITHER_FORMAT_666,              /*!< Dither output format 666 */
    MML_GDC_DISP_DITHER_FORMAT_565               /*!< Dither output format 565 */
} MML_GDC_DISP_DITHER_FORMAT;

/**
 * Dither mode.
 */
typedef enum {
    MML_GDC_DISP_TEMPDITH = 0x0UL,              /*!< Temporal dithering  */
    MML_GDC_DISP_SPATDITH                       /*!< Spatial dithering  */
} MML_GDC_DISP_DITHER_MODE;


/* Panel interface */
typedef enum
{
    MML_GDC_DISP_INTERFACE_TTL,          /*!< TTL panel  */
    MML_GDC_DISP_INTERFACE_RSDS          /*!< RSDS panel */
} MML_GDC_DISP_INTERFACE;

/* Panel bits per color */
typedef enum
{
    MML_GDC_DISP_BITS_PER_COLOR_6,      /*!< six bit per color   */
    MML_GDC_DISP_BITS_PER_COLOR_8       /*!< eight bit per color */
} MML_GDC_DISP_BITS_PER_COLOR;

/* Display Controller Clock Settings */
typedef struct
{
    MM_U16          CLK_DIV;          /*!< Clock Divider (1 = divide by 2 ... 255 = divide by 256) when using the internal PLL; set to 0 when using external clock.\n
                                           The resulting pixel clock is: pix_clk = MCU_FREQ_CLK_GFX_PLL_HZ / (CLK_DIV + 1) / 2,
                                           where MCU_FREQ_CLK_GFX_PLL_HZ is the GFXPLL frequency defined in mcu.h */
    MM_U16          CLK_SHIFT;        /*!< Clock Phase Shift (0...255 clocks) when using the internal PLL; it must be smaller than CLK_DIR; set to 0 when using external clock */
    MM_U32          CLK_INV;          /*!< Set to 1 to invert clock, otherwise to 0; clock inversion only possible with external clock in TCON bypass mode */
}MML_GDC_DISP_CLOCK_PARAMS;

typedef struct
{
    /* Display controller parameters. */
    MM_U16          HTP;        /*!< Horizontal Total Pixels (0..4095).               */
    MM_U16          HSP;        /*!< Horizontal Synchronize pulse Position (0..4095). */
    MM_U16          HSW;        /*!< Horizontal Synchronize pulse Width (0..255).     */
    MM_U16          HDP;        /*!< Horizontal Display Period (0..4095).             */
    MM_U16          VTR;        /*!< Vertical Total Raster (0..4095).                 */
    MM_U16          VSP;        /*!< Vertical Synchronize pulse Position (0..4095).   */
    MM_U16          VSW;        /*!< Vertical Synchronize pulse Width (0..63).        */
    MM_U16          VDP;        /*!< Vertical Display Period (0..4095).               */

    /* Pixel clock settings. */
    const MML_GDC_DISP_CLOCK_PARAMS*  psDispClockParams;  /*!< Pointer to Clock Setings Structure   */

    /* Connected panel parameters. */
    MML_GDC_DISP_INTERFACE           panelInterfaceType; /*!< Panel interface type.                */
    MML_GDC_DISP_BITS_PER_COLOR         panelBitPerColor;   /*!< Panel bits per color.                */

    /* TCON parameters (timing controller). */
    const MML_GDC_DISP_TCON_PROPERTIES* psTConSetup;        /*!< Pointer to TCON register settings    */
    const MM_U32                bTConBypass;        /*!< Operate TCON in bypass mode          */
    const MM_U32                nTConElems;         /*!< Number of TCON register setting pairs*/
} MML_GDC_IRS_DISP_PROPERTIES;



/**
 * Enumeration of layers available for each display controller.
 */
typedef enum {
    MML_GDC_DISP_LAYER_0 = 0,   /*!< Layer 0    */
    MML_GDC_DISP_LAYER_1,       /*!< Layer 1    */
    MML_GDC_DISP_LAYER_2,       /*!< Layer 2    */
    MML_GDC_DISP_LAYER_3,       /*!< Layer 3    */
    MML_GDC_DISP_MASK_ALL,      /*!< Mask for blended layers */
    MML_GDC_DISP_MASK_LAYER_1,  /*!< Mask for Layer 1 */
    MML_GDC_DISP_MASK_LAYER_2,  /*!< Mask for Layer 2 */
    MML_GDC_DISP_MASK_LAYER_3   /*!< Mask for Layer 3 */
} MML_GDC_DISP_LAYER;

/**
 * Datatype used to specify window creation parameters.
 */
typedef struct {
    MM_U32                      topLeftX;       /*!< Top left X coordinate of the window on the display.     */
    MM_U32                      topLeftY;       /*!< Top left Y coordinate of the window on the display.     */
    MM_U32                      width;          /*!< Width to create the window with.                        */
    MM_U32                      height;         /*!< Height to create the window with.                       */
    MM_U32                      layerId;        /*!< Layer to use for the window (see ::MML_GDC_DISP_LAYER). */
} MML_GDC_DISP_WINDOW_PROPERTIES;


/*! Blend function */
typedef enum {
    MML_GDC_IRS_DISP_BF_ZERO = 0x0UL,
    MML_GDC_IRS_DISP_BF_ONE,
    MML_GDC_IRS_DISP_BF_DST_ALPHA,
    MML_GDC_IRS_DISP_BF_ONE_MINUS_DST_ALPHA,
    MML_GDC_IRS_DISP_BF_SRC_ALPHA,
    MML_GDC_IRS_DISP_BF_ONE_MINUS_SRC_ALPHA,
    MML_GDC_IRS_DISP_BF_CONST_ALPHA,
    MML_GDC_IRS_DISP_BF_ONE_MINUS_CONST_ALPHA
} MML_GDC_IRS_DISP_BLEND_FUNC;


/*! Enumeration of the different configuration attributes used by
    ::mmlGdcDispSetAttribute  */
typedef enum {
    /*!  Window attribute: Enable/disable of color multiplication. The related parameter can be
    - MM_TRUE    Enable color multiplication
    - MM_FALSE   Disable color multiplication.(Default) */
    MML_GDC_DISP_ATTR_COLORMULTI,
    /*!  Mode of color multiplication. The related parameter can be
    - MML_GDC_PE_COLORMULTI_ALPHA    Alpha value (Default)
    - MML_GDC_PE_COLORMULTI_CONSTANT    Constant color indicated by mmlGdcPeSurfColor.
    The related formula is \verbatim
    if (AlphaMultiply == TRUE)
        Aout = Ain * Aconst;
    else
        Aout = Ain;
    if (ColorMultiplyEnable == TRUE)
    {
        if (ColorMultiplyMode == MML_GDC_PE_COLORMULTI_ALPHA)
            Cout = Cin * Aout;
        else // ColorMultiplySelect == MML_ERR_GDC_SURF_INVALID_EGL_CONTEXT)
            Cout = Cin * Cconst;
    }
    else
        Cout = Cin;
    \endverbatim
    */
    MML_GDC_DISP_ATTR_COLORMULTI_MODE,
    /*!  Window attribute: Enable/disable of alpha multiplication. The related parameter can be
    - MM_TRUE    Enable alpha multiplication
    - MM_FALSE   Disable alpha multiplication. (Default) */
    MML_GDC_DISP_ATTR_ALPHAMULTI,
    /*!  Mode of tiling mode for pixels in out of source buffer. The related parameter can be
    - ::MML_GDC_PE_TILE_PAD,
    - ::MML_GDC_PE_TILE_FILL_CONSTANT or
    - ::MML_GDC_PE_TILE_FILL_ZERO (Default)
    */
    MML_GDC_DISP_ATTR_TILE_MODE,
    /*!  Window attribute: Mode of skip mode for pixels inside of skip area. The related parameter can be
    - ::MML_GDC_PE_SKIP_COLOR_CONSTANT (Default)
    - ::MML_GDC_PE_SKIP_COLOR_ZERO
    */
    MML_GDC_DISP_ATTR_SKIP_MODE,
    /*! Display attribute:
      *  MM_TRUE (default): ::mmlGdcDispCommit is synchronized with VSYNC (limited by panel frame reate)
      *  MM_FALSE: ::mmlGdcDispCommit is not (always) synchronized with VSYNC
      * A typical doubled buffered application will render a new image in the
      * background buffer and apply this buffer later on to a window.
      * The default handling of the driver ensures that each buffer will be
      * visible at least one frame before the next buffer becomes visible.
      * To analyze the performance reserve it is possible to switch off the
      * VSYNC wait with the known limitation that frames may be skipped or render
      * artefacts are visible.
      * \note This feature should be used for debugging purposes and performance tests only.
      * The driver cannot garantee a correct function under all circumstances in this mode.
      */
    MML_GDC_DISP_ATTR_ENABLE_VSYNC

} MML_GDC_DISP_ATTR;

/*******************************************************************************
 Global Variables
*******************************************************************************/

/* N/A */

/*******************************************************************************
 Function Prototypes
*******************************************************************************/

/**
 * [SWDD4020] Used to open a display.
 *  \cond Related to SWAD000, SWAD401 \endcond
 *
 *  @param[in] mode The display mode to setup.
 *  @param[in,out] display On success will contain a valid ::MML_GDC_DISPLAY.
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 *
 */
IRIS_API MM_S32 mmlGdcIrsDispOpenDisplay( MML_GDC_IRS_DISP_PROPERTIES *mode,
                              MML_GDC_DISPLAY* display );


/**
 * [SWDD4021] Used to close a display.
 *  \cond Related to SWAD000, SWAD401 \endcond
 *
 *  @param[in,out] display An ::MML_GDC_DISPLAY returned from a previos call to ::mmlGdcIrsDispOpenDisplay.
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 *
 */
IRIS_API MM_S32 mmlGdcDispCloseDisplay( MML_GDC_DISPLAY display );

/**
 * [SWDD4025] Setup next frame generation mode
 * \cond Related to SWAD000, SWAD401 \endcond
 *
 * Sets display controller next frame generation mode. If both parameters are 0 (default)
 * the next frame generation will start after receiving the last pixel of
 * the previous frame. If xPos and yPos are set then the generation of the next
 * frame is started when the current position in the current frame corresponds to
 * xPos, yPos.
 * @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 * @param[in] xPos horizontal position in the current frame at witch generation of next frame starts
 * @param[in] yPos vertical position in the current frame at witch generation of next frame starts
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispFrameTriggerPos(MML_GDC_DISPLAY display, MM_U32 xPos, MM_U32 yPos);

/**
 * [SWDD4030] Configure Dithering Parameters
 * \cond Related to SWAD000, SWAD401 \endcond
 *
 * Configures dithering parameters
 *  @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 *  @param[in] bEnable Enable dithering of the output with MM_TRUE
 *  @param[in] eMode Dither output mode
 *  @param[in] eAlign Dither output data byte alignment
 *  @param[in] eFormat Dither output format
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispDitherCtrl( MML_GDC_DISPLAY display,
                             MM_BOOL bEnable,
                             MML_GDC_DISP_DITHER_MODE eMode,
                             MML_GDC_DISP_DITHER_ALIGNMENT eAlign,
                             MML_GDC_DISP_DITHER_FORMAT eFormat );

/**
 * [SWDD4045] Assign a color lookup table to the display path.
 * \cond Related to SWAD000, SWAD403, SWAD210 \endcond
 *
 *  \note New look up table entries will be visible immediately.
 *        However mode changes (on/off) will be applied with the next ::mmlGdcDispCommit
 *        call.
 *  @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 *  @param[in] bufferAddress The address of the color buffer. The driver expects 256
 *   32 bit entries (R10G10B10) describing the 10 bit red, green and blue LUT entries.
 *   If the bufferAddress = 0 the CLUT processing will be switched off.
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispClut(MML_GDC_DISPLAY display, void *bufferAddress);

/**
 * [SWDD4047] Set the color matrix coefficients for the display path\n
 * \cond Related to: SWAD000, SWAD403\n \endcond
 *  @note The color matrix can be used either in the display path or in the
 *        blit path. An error occures if it will be used in both blocks
 *        simultaneously.
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 *  @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 *  @param[in] fMatrix The new matrix values as a float[12] array or
 *       NULL to switch the color matrix off.
 *  @note The formula to calculate the new colors is \verbatim
         red_out   = fMatrix[0] * red + fMatrix[3] * green + fMatrix[6] * blue + fMatrix[9]  * 255
         green_out = fMatrix[1] * red + fMatrix[4] * green + fMatrix[7] * blue + fMatrix[10] * 255
         blue_out  = fMatrix[2] * red + fMatrix[5] * green + fMatrix[8] * blue + fMatrix[11] * 255
         \endverbatim
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispColorMatrix (MML_GDC_DISPLAY display, const MM_FLOAT *fMatrix);

/**
 * [SWDD4048] mmlGdcDispColorMatrixFix is equvalent to ::mmlGdcDispColorMatrix except the matrix is
 * defined in fix point 16.16 format.
 * \cond Related to: SWAD000, SWAD403 \endcond
 *  @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 *  @param[in] pMatrix The new matrix values or NULL to switch the color matrix off.
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispColorMatrixFix (MML_GDC_DISPLAY display, const MM_S32 *pMatrix);

/**
* [SWDD4050] mmlGdcDispCommit updates windows and display related changes.
 * \cond Related to: SWAD410 \endcond
 * @param[in,out] display An ::MML_GDC_DISPLAY identifying the display.
 * @return MML_OK on success. Otherwise the related error code defined above.
 **/
IRIS_API MM_S32 mmlGdcDispCommit (MML_GDC_DISPLAY display);

/**
 * [SWDD4100] Used to create a window.
 *  \cond Related to SWAD000, SWAD402 \endcond
 *
 *  @param[in] display An ::MML_GDC_DISPLAY identifying the display to create the window on.
 *  @param[in] properties A pointer to a ::MML_GDC_DISP_WINDOW_PROPERTIES structure which specifies
 *                    the properties of the window to create.
 *  @param[in,out] pWin On success will contain a ::MML_GDC_DISP_WINDOW
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 *
 */
IRIS_API MM_S32 mmlGdcDispCreateWindow( MML_GDC_DISPLAY display,
                                           MML_GDC_DISP_WINDOW_PROPERTIES *properties,
                                           MML_GDC_DISP_WINDOW *pWin);

/**
 * [SWDD4101] Used to destroy a window.
 *  \cond Related to SWAD000, SWAD402 \endcond
 *
 *  @param[in,out] pWin An ::MML_GDC_DISP_WINDOW returned from a previous call to
 *              ::mmlGdcDispCreateWindow.
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 *
 */
IRIS_API MM_S32 mmlGdcDispDestroyWindow( MML_GDC_DISP_WINDOW pWin );

/**
 * [SWDD4102] Show the surface content on a previously opened window.
 * \cond Related to SWAD000, SWAD100, SWAD402 \endcond
 *
 * @note The execution of this call will be queued together with PixEng
 *   blit operations. That means previously sent blits will be executed first.
 *   Therefore it is typically not required to synchronise the blit execution with
 *   diplay updates.
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 *  @param[in,out] win An ::MML_GDC_DISP_WINDOW returned from a previous call to
 *              ::mmlGdcDispCreateWindow.
 *  @param[in] surf The ::MML_GDC_SURFACE object to show. The layer will be switched off
 *    if surf is zero.
 * @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcDispSetSurface(MML_GDC_DISP_WINDOW win, MML_GDC_SURFACE surf);

/**
 * [SWDD4103] Set the position of a layer on the screen.
 * \cond Related to SWAD000, SWAD402 \endcond
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 *
 * @param[in,out] win Window handle
 * @param[in] left horizontal offset of window on the screen
 * @param[in] top vertical offset of window on the screen
 * @param[in] width vertical offset of window on the screen
 * @param[in] height vertical offset of window on the screen
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 */
IRIS_API MM_S32 mmlGdcDispSetPosition( MML_GDC_DISP_WINDOW win,
                              MM_S32 left,
                              MM_S32 top,
                              MM_U32 width,
                              MM_U32 height );

/**
 * [SWDD4110] Sets the blend mode for a layer
 * \cond Related to SWAD000, SWAD402 \endcond
 *
 * @note Calypso and Titan devices cannot use transparent color and alpha blend
 *      for the same layer so blending is switched off if ::mmlGdcDispSetTransparency is called.
 *      On the other hand a previously enabled transparent color will be switched off
 *      by calling ::mmlGdcIrsDispSetBlendFunc for this layer.
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 * @param[in,out] win An ::MML_GDC_DISP_WINDOW returned from a previous call to
 *             ::mmlGdcDispCreateWindow with the layer type MML_GDC_DISP_LAYER_1, MML_GDC_DISP_LAYER_2
 *             or MML_GDC_DISP_LAYER_3.
 * @param[in] func_color_src The source color blend function as defined in ::MML_GDC_IRS_DISP_BLEND_FUNC.
 *      The default value is MML_GDC_IRS_DISP_BF_ONE
 * @param[in] func_color_dst The destination color blend function as defined in ::MML_GDC_IRS_DISP_BLEND_FUNC.
 *      The default value is MML_GDC_IRS_DISP_BF_ONE_MINUS_SRC_ALPHA
 * @param[in] func_alpha_src The source color blend function as defined in ::MML_GDC_IRS_DISP_BLEND_FUNC.
 *      The default value is MML_GDC_IRS_DISP_BF_ONE
 * @param[in] func_alpha_dst The destination color blend function as defined in ::MML_GDC_IRS_DISP_BLEND_FUNC.
 *      The default value is MML_GDC_IRS_DISP_BF_ONE_MINUS_SRC_ALPHA
 * @param[in] alpha The alpha value (used for MML_GDC_IRS_DISP_BF_CONST_ALPHA or MML_GDC_IRS_DISP_BF_ONE_MINUS_CONST_ALPHA)
 * @return MML_OK on success. Otherwise the related error code defined above.
 */
IRIS_API MM_S32 mmlGdcIrsDispSetBlendFunc (MML_GDC_DISP_WINDOW win,
                                           MML_GDC_IRS_DISP_BLEND_FUNC func_color_src,
                                           MML_GDC_IRS_DISP_BLEND_FUNC func_color_dst,
                                           MML_GDC_IRS_DISP_BLEND_FUNC func_alpha_src,
                                           MML_GDC_IRS_DISP_BLEND_FUNC func_alpha_dst,
                                           MM_U08 alpha);

/**
 * [SWDD4140] Set transparency for a layer.
 * \cond Related to SWAD000, SWAD402 \endcond
 *
 * The color components r, g, b are always 8 bit values also for 16 bpp and
 * indexed color modes.
 * For instance call mmlGdcDispSetTransparency(MM_TRUE, 255, 255, 255) to
 * disable the 0xffff color entry in a 16 bpp buffer.
 * @note Calypso and Titan devices cannot use transparent color and alpha blend
 *      for the same layer so blending is switched off if ::mmlGdcDispSetTransparency is called.
 *      On the other hand a previously enabled transparent color will be switched off
 *      by calling ::mmlGdcIrsDispSetBlendFunc for this layer.
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 * @param[in,out] win An ::MML_GDC_DISP_WINDOW returned from a previous call to
 *             ::mmlGdcDispCreateWindow.
 * @param[in] enable Enable transparency
 * @param[in] red red component of transparent color
 * @param[in] green green component of transparent color
 * @param[in] blue blue component of transparent color
 *
 * @return MML_OK on success. Otherwise the related error code defined above.
 */
IRIS_API MM_S32 mmlGdcDispSetTransparency( MML_GDC_DISP_WINDOW win,
                                  MM_BOOL enable,
                                  MM_U08 red,
                                  MM_U08 green,
                                  MM_U08 blue );


/**
 * [SWDD4160] Sets the attribute pname to param.
 * \cond Related to SWAD000, SWAD402, SWAD411 \endcond
 * Display and win specify for which display controller and window
 * the attribute should be set. Depending on the attribute, display or win doesn't need to be valid.
 *
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 * @param[in,out] display          An ::MML_GDC_DISPLAY returned from a previous call to ::mmlGdcIrsDispOpenDisplay.
 * @param[in,out] win              Window for which to set the attribute
 * @param[in] pname            Parameter name
 * @param[in] param            Value to set for parameter pname
 *
 */
IRIS_API MM_S32 mmlGdcDispSetAttribute( MML_GDC_DISPLAY display, MML_GDC_DISP_WINDOW win, MML_GDC_DISP_ATTR pname, MM_U32 param );


/**
 *   [SWDD4161] Set the constant color value of surface indicated by surface.
 *   \cond Related to SWAD000, SWAD402 \endcond
 *
 *   Indicated color is used for following usage. (See also ::mmlGdcPeSurfAttribute.)
 *   - Constant color in skipped area.
 *   - Constant color in color multiplication.
 *   - Constant color in tiling.
 *   - Constant color used for the generation of a color component in format conversion
 *       e.g. Format conversion from RGB565 to RGBA8888 when 0x1234_5678 is used as constant color
 *           0xFFFF (RGB565) -> 0xFFFF_FF78 (RGBA8888)
 *
 *   @note Setting different constant color to skipping and color multiplication is not supported.
 *   If MML_GDC_PE_SURF_ATTR_SKIP and MML_GDC_PE_SURF_ATTR_COLMULTI are enabled,
 *   same value is used as constant color indicated by mmlGdcPeSurfColor.
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
 *   @param[in,out] win Window for which to set the attribute
 *   @param[in] red Red component of color (0 - 255, default 0)
 *   @param[in] green Green component of color (0 - 255, default 0)
 *   @param[in] blue Blue component of color (0 - 255, default 0)
 *   @param[in] alpha Alpha component of color (0 - 255, default 255)
 *   @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcDispSetColor(MML_GDC_DISP_WINDOW win, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha);

/**
*   [SWDD4162] mmlGdcDispSetMatrix is setting function of transformation matrix for scaling,
*   translation and flipping for a surface assigned to the window.
*   \cond Related to SWAD000, SWAD402 \endcond
*
*   @note:
*   - This function must not be used for a window with a run length compressed surface.
*   - Matrixes with rotaions different from 90° or a mutiple of them are not supported.
*   - Only all windows or the window created for layer ::MML_GDC_DISP_LAYER_3
*   can be upscaled.
*   It requires that the display path can use the scaler see ::mmlGdcConfigSetAttribute with
*   attribute ::MML_GDC_CONFIG_ATTR_ASSIGN_SCALER.
*   Downscaling is not supported.
*   - Only the ::MML_GDC_DISP_LAYER_3 window can be used for subpixel surface translation.
*   It requires that the display path can use the scaler see ::mmlGdcConfigSetAttribute with
*   attribute ::MML_GDC_CONFIG_ATTR_ASSIGN_SCALER.
*
*   The formular for the transformation based on this matrix is:
*   \verbatim
        xout = fMatrix[0] * x + fMatrix[2] * y + fMatrix[4]
        yout = fMatrix[1] * x + fMatrix[3] * y + fMatrix[5]
    \endverbatim
*   If matrix = 0, following data is settled in transformation matrix:
*   \verbatim
        / fMatrix[0] fMatrix[2] fMatrix[4] \      / 1 0 0 \
        |                                  |  =   |       |
        \ fMatrix[1] fMatrix[3] fMatrix[5] /      \ 0 1 0 /
    \endverbatim
*
*   If pectx is equal to NULL, or matrix is equal to NULL, mmlGdcPeSetMatrix is terminated without any operation.
*  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
*
*   @param[in,out] win Window handle
*   @param[in] fMatrix Transformation matrix for scaling , rotation, translate, and flip.
*   @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcDispSetMatrix(MML_GDC_DISP_WINDOW win, const MM_FLOAT *fMatrix);

/**
    [SWDD4163] mmlGdcDispSetMatrixFix is equvalent to ::mmlGdcDispSetMatrix except the matrix is defined in fix point 16.16 format.
    \cond Related to SWAD000, SWAD402 \endcond

    @param[in,out] win Window handle
    @param[in] pMatrix Transformation matrix for scaling , rotation, translate, and flip.
    @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcDispSetMatrixFix(MML_GDC_DISP_WINDOW win, const MM_S32 *pMatrix);

/**
*  [SWDD4150] Set the ROP mode
*  \cond Related to SWAD000, SWAD402 \endcond
*
*  Define the ROP mode for a layer.
*  @note A window created with MML_GDC_DISP_MASK_... is required to use a ROP mode.
*       The rop modes define the way how the color and alpha data are combined.
*       A typical mode is using ::MML_GDC_PE_ROP_SRCCOPY for color channels and
*       ::MML_GDC_PE_ROP_MASKCOPY for alpha. In this case the mask layer will
*       be used as external alpha layer. The function  reports an error is a
*       ROP3 mode is selected.
*  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
*   @param[in,out] win Window handle. It must be a mask window (create with a
*       MML_GDC_DISP_MASK_... parameter).
*   @param[in] ucRedMode ROP mode for the red channel.
*       (default is ROP_BLACKNESS)
*   @param[in] ucGreenMode ROP mode for the green channel.
*       (default is ROP_BLACKNESS)
*   @param[in] ucBlueMode ROP mode for the blue channel.
*       (default is ROP_BLACKNESS)
*   @param[in] ucAlphaMode ROP mode for the alpha channel.
*       (default is ROP_BLACKNESS)
*  @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcDispRopMode(MML_GDC_DISP_WINDOW win, MM_U08 ucRedMode, MM_U08 ucGreenMode, MM_U08 ucBlueMode, MM_U08 ucAlphaMode);


/**
*   [SWDD4052] Set rectangle area for skipping in the surface indicated by surface.
*   \cond Related to SWAD000, SWAD402 \endcond
*
*   User can select filling the area by constant color or zero. See also ::mmlGdcDispSetColor.
*
*   The area is defined by lower left coordinate, width and height.
*   The lower left coordinate is inside of skipping area.
*   The upper right coordinate (x+w, y+h) is outside of skipping area.
*
*   If w and h are equal to 0, skipping is disabled.
*
 *  \note The requested changes will be applied with the next ::mmlGdcDispCommit call.
*   @param[in,out] win Window handle. It must be a mask window (create with a
*       MML_GDC_DISP_MASK_... parameter).
*   @param[in] left x coordinate at lower left in skip frame (0 - 4096)
*   @param[in] top y coordinate at lower left in skip frame (0 - 4096)
*   @param[in] width Width of skip frame (0 - 4096)
*   @param[in] height Height of skip frame (0 - 4096)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcIrsDispReadSkip(MML_GDC_DISP_WINDOW win,
                              MM_U32 left,
                              MM_U32 top,
                              MM_U32 width,
                              MM_U32 height );

/** @} end defgroup */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
