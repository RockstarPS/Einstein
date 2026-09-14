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
 * \file        mml_gdc_surfman.h
 * \brief       Surface interface
 *
 */

#ifndef MML_GDC_SURFMAN_H
#define MML_GDC_SURFMAN_H

/*lint -save -e621 */

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/


/**
 * @defgroup surface_api Surface API
 *  The Surface API provides all functions to manage memory blocks with image
 *  content. A "surface" is a description of such a memory block, including
 *  dimension of the image, pixel format and physical address in memory.\n
 *  Most modules of the graphics library can work on surfaces, like Capture,
 *  Display, PixEngine, OpenGL (as texture). The Surface API allows to:\n
 *  - Pass surfaces created by the application to PixEngine for further
 *    processing\n
 *  - Pass surfaces created by the application to Display for displaying on
 *    the screen\n
 *  - etc.\n
 * @{
 */

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/


#ifndef MML_GDC_SURF_API
#define MML_GDC_SURF_API extern
#endif

/*!
 * Surface manager error codes
 **/
#define  MML_ERR_GDC_SURF_OUT_OF_SPACE              MM_ERRCODE(0xC00C0201U) /*!< The system runs out of memory to perform this operation */
#define  MML_ERR_GDC_SURF_OUT_OF_VRAM               MM_ERRCODE(0xC00C0202U) /*!< The video memory runs out of memory to perform this operation */
#define  MML_ERR_GDC_SURF_INVALID_SURFACE           MM_ERRCODE(0xC00C0203U) /*!< Surface object invalid */
#define  MML_ERR_GDC_SURF_INVALID_FORMAT            MM_ERRCODE(0xC00C0204U) /*!< The given format is not supported */
#define  MML_ERR_GDC_SURF_INVALID_FOR_BUFFER_OWNED  MM_ERRCODE(0xC00C0205U) /*!< The operation is not allowed for buffer owned surface objects */
#define  MML_ERR_GDC_SURF_INVALID_ATTRIBUTE         MM_ERRCODE(0xC00C0206U) /*!< The given attribute is not supported  */
#define  MML_ERR_GDC_SURF_ERROR_ADDRESS_TRANSLATION MM_ERRCODE(0xC00C0207U) /*!< Address translation faild. */
#define  MML_ERR_GDC_SURF_INVALID_EGL_CONTEXT       MM_ERRCODE(0xC00C0208U) /*!< The EGL context is invalid. */
#define  MML_ERR_GDC_SURF_INVALID_BUFFER            MM_ERRCODE(0xC00C0209U) /*!< The OpenGl buffer is invalid. */
#define  MML_ERR_GDC_SURF_INVALID_PARAMETER         MM_ERRCODE(0xC00C0210U) /*!< The parameter is wrong. */
#define  MML_ERR_GDC_SURF_INVALID_ADDRESS_ALIGNMENT MM_ERRCODE(0xC00C0211U) /*!< The base address alignment is not suitable for this operation. */

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*! GDC Surface object
*
*/
typedef struct _MML_GDC_SURFACE_CONTAINER
{
    MM_U32 reserved[15];
} MML_GDC_SURFACE_CONTAINER, *MML_GDC_SURFACE;

/*! Color format of surface buffer. R, G, B, A and X stands for red, gree, blue, alpha and unused.
    The field description(s) is followed by the bit width. For instance R5G6B5 used 5 red, 6 green and 5
    blue bits but no alpha. RGB8 stands for a gray of indexed format. Note: Additional formats
    are supported by the PixEng hardware. They can be defined with the attrib function.
    */
typedef enum {
    /*! R8G8B8A8  */
    MML_GDC_SURF_FORMAT_R8G8B8A8               = 0x00,

    /*! A8B8G8R8 */
    MML_GDC_SURF_FORMAT_A8B8G8R8,

    /*! R8G8B8X8 */
    MML_GDC_SURF_FORMAT_R8G8B8X8,

    /*! X8B8G8R8 */
    MML_GDC_SURF_FORMAT_X8B8G8R8,

    /*! R8G8B8 */
    MML_GDC_SURF_FORMAT_R8G8B8,

    /*! B8G8R8 */
    MML_GDC_SURF_FORMAT_B8G8R8,

    /*! R4G4B4A4 */
    MML_GDC_SURF_FORMAT_R4G4B4A4,

    /*! R5G5B5A1 */
    MML_GDC_SURF_FORMAT_R5G5B5A1,

    /*! R5G6B5 */
    MML_GDC_SURF_FORMAT_R5G6B5,

    /*! RGB8A8 (gray or indexed)*/
    MML_GDC_SURF_FORMAT_RGB8A8,

    /*! RGB8 (gray or indexed) */
    MML_GDC_SURF_FORMAT_RGB8,

    /*! A8 */
    MML_GDC_SURF_FORMAT_A8,

    /*! A1 */
    MML_GDC_SURF_FORMAT_A1,

    /*! RGB1 */
    MML_GDC_SURF_FORMAT_RGB1,

    /*! A8R8G8B8 */
    MML_GDC_SURF_FORMAT_A8R8G8B8,

    /*! B8G8R8A8 */
    MML_GDC_SURF_FORMAT_B8G8R8A8,

    /*! A1R5G5B5 */
    MML_GDC_SURF_FORMAT_A1R5G5B5,

    /*! A1B5G5R5 */
    MML_GDC_SURF_FORMAT_A1B5G5R5,

    /*! B5G5R5A1 */
    MML_GDC_SURF_FORMAT_B5G5R5A1

} MML_GDC_SURF_FORMAT;

/*! Color format of color lookup table */
typedef enum {
    /*! R10G10B10 */
    MML_GDC_SURF_CLF_R10G10B10   = 0x00,
    /*! R8G8B8A8 */
    MML_GDC_SURF_CLF_R8G8B8A8,
    /*! R8G8B8 */
    MML_GDC_SURF_CLF_R8G8B8,
    /*! B8G8R8 */
    MML_GDC_SURF_CLF_B8G8R8
} MML_GDC_SURF_CLF;

/*! Mode definition for color lookup table */
typedef enum {
    /*! 0x0 : Module in neutral mode, input data is bypassed to the output */
    MML_GDC_SURF_CLM_NEUTRAL                     = 0x0UL,
    /*! 0x1 : Color lookup mode (red, green and blue values will be replaced by related look up entry, alpha is bypassed */
    MML_GDC_SURF_CLM_LUT                         = 0x1UL,
    /*! 0x2 : Module in color index table mode (LUT holds a r,g,b color value, indexed with the red input color, alpha is bypassed) */
    MML_GDC_SURF_CLM_INDEX_RGB                   = 0x2UL,
    /*! 0x3 : Module in RGBA color index table mode (LUT holds a r,g,b,a value, indexed with the red input color) */
    MML_GDC_SURF_CLM_INDEX_RGBA                  = 0x3UL
} MML_GDC_SURF_CLM;

/*! Compression Format */
typedef enum {
    /*! The buffer is not compressed */
    MML_GDC_SURF_COMP_NON                     = 0x0UL,
    /*! Run length encoded: big endian coded, repetition count (0...127) + 1 */
    MML_GDC_SURF_COMP_RLC                     = 0x1UL,
    /*! Packed YUV format: 2 pixels coded as 32 bit YUYV, where U and V used for both pixels and Y is separate.
      Note: The MML_SM_ATTR_COLORBITS and MML_SM_ATTR_CLUTCOLORSHIFT will be ignored and
      MML_SM_ATTR_BITPERPIXEL is 16 in this case. Not supported with Iris PixEng*/
    MML_GDC_SURF_COMP_YUYV                    = 0x2UL,
    /*! Run length encoded format 2: little endian coded, repetition count (1...127)
    @note This setting has not effect for Calypso and Titan devices.
    */
    MML_GDC_SURF_COMP_RLC2                    = 0x25UL
} MML_GDC_SURF_COMP;

/*! Surface attribute */
typedef enum {
    /*! Virtual Base Address */
    MML_GDC_SURF_ATTR_BASE_ADDRESS                  = 0x0,
    /*! Physical Base Address (identical to base address for this driver) */
    MML_GDC_SURF_ATTR_PHYS_ADDRESS,
    /*! Width in pixels */
    MML_GDC_SURF_ATTR_WIDTH,
    /*! Height in pixels */
    MML_GDC_SURF_ATTR_HEIGHT,
    /*! Size of a line in bytes. If unStride = 0 the default
    unStride = ((unWidth * unBitPerPixel + 7) >> 3) will be used */
    MML_GDC_SURF_ATTR_STRIDE,
    /*! Size of one pixel in bits (1, 2, 4, 8, 16, 24, 32)*/
    MML_GDC_SURF_ATTR_BITPERPIXEL,
    /*! Color component size in bits (0xRRGGBBAA) */
    MML_GDC_SURF_ATTR_COLORBITS,
    /*! Color component shift (0xRRGGBBAA) */
    MML_GDC_SURF_ATTR_COLORSHIFT,
    /*! Compression Format (must be one of #MML_GDC_SURF_COMP, default #MML_GDC_SURF_COMP_NON) */
    MML_GDC_SURF_ATTR_COMPRESSION_FORMAT,
    /*! Buffer size (= unHeight * unStride for uncompressed sources otherwise the size of the comressed stream)*/
    MML_GDC_SURF_ATTR_SIZEINBYTES,
    /*! Color look up table mode (must be one of #MML_GDC_SURF_CLM, default #MML_GDC_SURF_CLM_NEUTRAL) */
    MML_GDC_SURF_ATTR_CLUTMODE,
    /*! Number of color look up table  entries (0..255) */
    MML_GDC_SURF_ATTR_CLUTCOUNT,
    /*! Size of one entry in bits (1, 2, 4, 8, 16, 24, 32) */
    MML_GDC_SURF_ATTR_CLUTBITPERPIXEL,
    /*! Color component size of one entry in bits (0xRRGGBBAA) */
    MML_GDC_SURF_ATTR_CLUTCOLORBITS,
    /*! Color component shift of one entry in bits (0xRRGGBBAA) */
    MML_GDC_SURF_ATTR_CLUTCOLORSHIFT,
    /*! Virtual address of CLUT data */
    MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS,
    /*! Physical address of CLUT data (identical to base address for this driver)*/
    MML_GDC_SURF_ATTR_CLUTBUFFER_PHYS_ADDRESS,
    /*! User defined */
    MML_GDC_SURF_ATTR_USERDEFINED
} MML_GDC_SURF_ATTR;


/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/

/**
* [SWDD1010] Reset a surface object with default values.
*   \cond Related to SWAD100 \endcond
*  @param[in,out] surf The surface to reset.
*  @return MML_OK on success, otherwise the related error code
**/
MM_S32 mmlGdcSmResetSurfaceObject(MML_GDC_SURFACE surf);


/**
*  [SWDD1020] Assign a memory address representing an image to a surface object.
*  \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*
*  The buffer is owned by the calling function. It just describes
*  how the image buffer must be used by a function.
*  The application must ensure that the memory is availble as long
*  as the surface is still be used.
*  @param[in,out] surf The surface name
*  @param[in] ulWidth The with in pixel of the image.
*  @param[in] ulHeight The height in pixel of the image.
*  @param[in] eFormat The format of the image.
*       The format defines the fields BitPerPixel, ColorBits, ColorShift
*  @param[in] pBufferAddress The memory address of the image. The buffer
*       starts with the upper left pixel.
*  @param[in] ulRleWords Number of 32-bit words that are required to decode the run
*       length encoded source buffer. Zero indicates an uncompressed buffer.
*  @return MML_OK on success, otherwise the related error code
**/
IRIS_API MM_S32 mmlGdcSmAssignBuffer(MML_GDC_SURFACE surf, MM_U32 ulWidth, MM_U32 ulHeight, MML_GDC_SURF_FORMAT eFormat, void *pBufferAddress, MM_U32 ulRleWords);

/**
*  [SWDD1030] Assign a color lookup table to a surface.
*  \cond Related to SWAD000, SWAD100, SWAD210 \endcond
*
*  It points to a VRAM memory address owned by the application.
*  The application must ensure that the memory is available as long
*  as the surface is still in use and that the memory block is large
*  enough with respect to the width, height and format parameters of
*  the surface.
*  @param[in,out] surf The surface object getting this new property.
*  @param[in] eMode Defines the operation mode for the CLUT
*  @param[in] ulCount Number of table entries to be written
*  @param[in] eFormat Format of the table entries
*  @param[in] pBufferAddress The address of the color buffer.
*  @return MML_OK on success, otherwise the related error code
**/
IRIS_API MM_S32 mmlGdcSmAssignClut(MML_GDC_SURFACE surf, MML_GDC_SURF_CLM eMode, MM_U32 ulCount, MML_GDC_SURF_CLF eFormat, void *pBufferAddress);

/**
* [SWDD1040] Set surface attributes
*  \cond Related to SWAD100 \endcond
*
*  The application must ensure that the parameters like stride, height, size
*  and format of the surface are always consistent and match the size of the
*  memory block allocated for the surface.
*  @param[in,out] surf The surface
*  @param[in] eName Name of the attribute see #MML_GDC_SURF_ATTR
*  @param[in] ulValue The new value
*  @return MML_OK on success, otherwise the related error code
**/
IRIS_API MM_S32 mmlGdcSmSetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 ulValue);

/**
* [SWDD1050] Get surface attributes
*  \cond Related to SWAD000, SWAD100, SWAD113 \endcond
*
*  @param[in] surf The surface
*  @param[in] eName Name of the attribute see #MML_GDC_SURF_ATTR
*  @param[in,out] pulValue pPointer to a variable to the the new parameter
*  @return MML_OK on success, otherwise the related error code
**/
IRIS_API MM_S32 mmlGdcSmGetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 *pulValue);

/** @} end defgroup */

#ifdef __cplusplus
}
#endif

/*lint -restore */

#endif /* MML_GDC_SURFMAN_H */
