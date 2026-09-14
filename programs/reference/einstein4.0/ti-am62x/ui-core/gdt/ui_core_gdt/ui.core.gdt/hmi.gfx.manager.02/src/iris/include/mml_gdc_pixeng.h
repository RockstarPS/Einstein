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
 * \file        mml_gdc_pixeng.h
 * \brief       Pixel Engine API
 *
 */

#ifndef MML_GDC_PIXENG_H
#define MML_GDC_PIXENG_H

/*lint -save -e621 */

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/**
* @defgroup pixeng_api Pixel Engine API
* The pixel engine API provides all functions for blit operations using the
* Pixel engine hardware.
* @{
**/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

#ifndef IRIS_API
#define IRIS_API extern
#endif

/*!
 * PixEngine error codes
 **/
#define  MML_ERR_GDC_PE_OUT_OF_SPACE              MM_ERRCODE(0xC00C0401U) /*!< The system runs out of memory to perform this operation */
#define  MML_ERR_GDC_PE_INVALID_CONTEXT           MM_ERRCODE(0xC00C0402U) /*!< Context object invalid */
#define  MML_ERR_GDC_PE_INVALID_TARGET            MM_ERRCODE(0xC00C0403U) /*!< Invalid target  */
#define  MML_ERR_GDC_PE_INVALID_SURFACE_OBJECT    MM_ERRCODE(0xC00C0404U) /*!< Surface object invalid */
#define  MML_ERR_GDC_PE_INVALID_ADDRESS           MM_ERRCODE(0xC00C0405U) /*!< Wrong address (For instance not aligned) */
#define  MML_ERR_GDC_PE_INVALID_MATRIX            MM_ERRCODE(0xC00C0406U) /*!< A matrix operation cannot be performed */
#define  MML_ERR_GDC_PE_INVALID_DIMENSION         MM_ERRCODE(0xC00C0407U) /*!< Surface dimension is out of range */
#define  MML_ERR_GDC_PE_INVALID_STRIDE            MM_ERRCODE(0xC00C0408U) /*!< Invalid value for Stride */
#define  MML_ERR_GDC_PE_INVALID_BITS_PER_PIXEL    MM_ERRCODE(0xC00C0409U) /*!< Invalid value for BitsPerPixel */
#define  MML_ERR_GDC_PE_INVALID_COMPRESSION       MM_ERRCODE(0xC00C0410U) /*!< Compression type not supported */
#define  MML_ERR_GDC_PE_INVALID_RLD_REQUEST       MM_ERRCODE(0xC00C0411U) /*!< Required fetch unit does not support RLD */
#define  MML_ERR_GDC_PE_INVALID_ROP_MODE          MM_ERRCODE(0xC00C0412U) /*!< Not all surfaces are defined for the specified ROP mode */
#define  MML_ERR_GDC_PE_INVALID_SURFACE_PARAM     MM_ERRCODE(0xC00C0413U) /*!< The requested surface features are not supported  */
#define  MML_ERR_GDC_PE_INVALID_NO_ACTIVE_AREA    MM_ERRCODE(0xC00C0414U) /*!< A blit operation was started but no active area source defined */
#define  MML_ERR_GDC_PE_INVALID_ATTRIBUTE         MM_ERRCODE(0xC00C0415U) /*!< Invalid attribute (target) was specified for an argument. */
#define  MML_ERR_GDC_PE_INVALID_PARAMETER         MM_ERRCODE(0xC00C0416U) /*!< Invalid parameter was specified for an argument. */
#define  MML_ERR_GDC_PE_INVALID_OPERATION         MM_ERRCODE(0xC00C0417U) /*!< The requested operation failed */
#define  MML_ERR_GDC_PE_INVALID_MASK_PARAM        MM_ERRCODE(0xC00C0418U) /*!< Required parameter is not supported for mask */
#define  MML_ERR_GDC_PE_INVALID_SCALING           MM_ERRCODE(0xC00C0419U) /*!< The scale factor exceeds the hardware capabilities */
#define  MML_ERR_GDC_PE_INVALID_STORE_COMRESSION  MM_ERRCODE(0xC00C0420U) /*!< Unsupported store compression type */
#define  MML_ERR_GDC_PE_INVALID_STORE_CLUT        MM_ERRCODE(0xC00C0421U) /*!< Store color lookup table not supported */
#define  MML_ERR_GDC_PE_MIPMAP_GENERATION         MM_ERRCODE(0xC00C0422U) /*!< An error occured while generating mipmaps */
#define  MML_ERR_GDC_PE_INVALID_FLOAT             MM_ERRCODE(0xC00C0423U) /*!< A float value exceeds the range supported by hardware */


/*! Bind target for surfaces */
#define MML_GDC_PE_STORE          0x00000001UL /*!<  = blit write destination */
#define MML_GDC_PE_SRC            0x00000002UL /*!<  = blit source surface */
#define MML_GDC_PE_DST            0x00000004UL /*!<  = Background for blend operations */
#define MML_GDC_PE_MASK           0x00000008UL /*!<  = Mask surface */
#define MML_GDC_PE_SRC2           0x00000010UL /*!<  = second source surface */

/*! = 0 */
#define  MML_GDC_PE_ROP_BLACKNESS                         ((MM_U08)0x00)
/*! = 1 */
#define  MML_GDC_PE_ROP_WHITENESS                         ((MM_U08)0xFF)
/*! = SRC */
#define  MML_GDC_PE_ROP_SRCCOPY                           ((MM_U08)0xAA)
/*! = ~SRC */
#define  MML_GDC_PE_ROP_NOTSRCCOPY                        ((MM_U08)0x55)
/*! = MASK */
#define  MML_GDC_PE_ROP_MASKCOPY                          ((MM_U08)0xCC)
/*! = ~MASK */
#define  MML_GDC_PE_ROP_NOTMASK                           ((MM_U08)0x33)
/*! = MASK ^ SRC */
#define  MML_GDC_PE_ROP_MASKINVERT                        ((MM_U08)0x66)
/*! = MASK & SRC */
#define  MML_GDC_PE_ROP_MSKAND                            ((MM_U08)0x88)
/*! = SRC & ~MASK */
#define  MML_GDC_PE_ROP_MASKERASE                         ((MM_U08)0x22)
/*! = ~ (MASK | SRC) */
#define  MML_GDC_PE_ROP_NOTMASKERASE                      ((MM_U08)0x11)
/*! =  SRC | MASK */
#define  MML_GDC_PE_ROP_MERGEMASK                         ((MM_U08)0xEE)
/*! =  SRC | ~MASK */
#define  MML_GDC_PE_ROP_MERGEMASKNOT                      ((MM_U08)0xBB)
/* with DST */
/*! = DST */
#define  MML_GDC_PE_ROP_DSTCOPY                           ((MM_U08)0xF0)
/*! = ~DST */
#define  MML_GDC_PE_ROP_NOTDSTCOPY                        ((MM_U08)0x0F)
/*! = DST | MASK | SRC */
#define  MML_GDC_PE_ROP_DSTPAINT                          ((MM_U08)0xFE)
/*! = MASK ? SRC : DST */
#define  MML_GDC_PE_ROP_MASKSEL                           ((MM_U08)0xB8)
/*! = DST & MASK & SRC */
#define  MML_GDC_PE_ROP_DSTAND                            ((MM_U08)0x80)

/*!  Nearest filter enable. */
#define MML_GDC_PE_FILTER_NEAREST                       0UL
/*!  Bilinear filter enable. */
#define MML_GDC_PE_FILTER_BILINEAR                      1UL

/*! No gamma convertion. */
#define MML_GDC_PE_GAMMA_NEUTRAL                         0UL
/*! Enable the gamma correction stage to remove gamma.
    This stage is located after the color conversion stage and before the
    bi-linear filter stage. */
#define MML_GDC_PE_GAMMA_REMOVE                         1UL
/*! Enable the gamma correction stage to apply gamma.
    This stage is located after the bi-linear filter stage and before the
    multiply stage. */
#define MML_GDC_PE_GAMMA_ADD                            2UL
/*! Enable the gamma correction stage for bi-linear filtering. */
#define MML_GDC_PE_GAMMA_CORRECTED                      3UL

/*! The coordinate system for geometry operation starts in the upper
    left corner equal to buffer content and display coordinate orientation. */
#define MML_GDC_PE_ATTR_ZERO_UP_LEFT                    0UL
/*! The coordinate system for geometry operation starts in the lover
    left corner. */
#define MML_GDC_PE_ATTR_ZERO_DOWN_LEFT                  1UL

/*! Color multiplication using alpha value */
#define MML_GDC_PE_COLORMULTI_ALPHA                     0UL
/*! Color multiplication using constant color */
#define MML_GDC_PE_COLORMULTI_CONSTANT                  1UL

/*! Tile mode of PAD */
#define MML_GDC_PE_TILE_PAD                             0UL
/*! Constant color filling */
#define MML_GDC_PE_TILE_FILL_CONSTANT                   1UL
/*! Zero filling */
#define MML_GDC_PE_TILE_FILL_ZERO                       2UL


/*! Filling skip area using constant color */
#define MML_GDC_PE_SKIP_COLOR_CONSTANT                  0UL
/*! Filling skip area using zero value */
#define MML_GDC_PE_SKIP_COLOR_ZERO                      1UL

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*! Context attributes used by #mmlGdcPeAttribute. */
typedef enum {
    /*!  Set the color dither mode. The related parameter can be
    - MM_TRUE    Enable color dithering.
    - MM_FALSE   Disable color dithering.(default) */
    MML_GDC_PE_CTX_ATTR_DITHER_COLOR,
    /*!  Set the alpha dither mode. The related parameter can be
    - MM_TRUE    Enable alpha dithering.
    - MM_FALSE   Disable alpha dithering.(default) */
    MML_GDC_PE_CTX_ATTR_DITHER_ALPHA,
    /*!  Set the CLUT dither mode. The related parameter can be
    - MM_TRUE    Enable dithering.
    - MM_FALSE   Disable dithering.(default) */
    MML_GDC_PE_CTX_ATTR_DITHER_CLUT,
    /*!  Set the filter mode. The related parameter can be
    - ::MML_GDC_PE_FILTER_NEAREST or
    - ::MML_GDC_PE_FILTER_BILINEAR (default)
    */
    MML_GDC_PE_CTX_ATTR_FILTER,
    /*!  Define the coordinate zero point for geometry operations.
         The related parameter can be
    - ::MML_GDC_PE_ATTR_ZERO_UP_LEFT
    - ::MML_GDC_PE_ATTR_ZERO_DOWN_LEFT (default)
    */
    MML_GDC_PE_ATTR_ZERO_POINT
} MML_GDC_PE_CTX_ATTR;

/*! Surface attributes used by #mmlGdcPeSurfAttribute. */
typedef enum {
    /*!  Enable/disable of color multiplication. The related parameter can be
    - MM_TRUE    Enable color multiplication
    - MM_FALSE   Disable color multiplication.(Default) */
    MML_GDC_PE_SURF_ATTR_COLORMULTI,

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
    MML_GDC_PE_SURF_ATTR_COLORMULTI_MODE,

    /*!  Enable/disable of alpha multiplication. The related parameter can be
    - MM_TRUE    Enable alpha multiplication
    - MM_FALSE   Disable alpha multiplication. (Default) */
    MML_GDC_PE_SURF_ATTR_ALPHAMULTI,

    /*!  Mode of tiling mode for pixels in out of source buffer. The related parameter can be
    - ::MML_GDC_PE_TILE_PAD,
    - ::MML_GDC_PE_TILE_FILL_CONSTANT or
    - ::MML_GDC_PE_TILE_FILL_ZERO (Default)
    */
    MML_GDC_PE_SURF_ATTR_TILE_MODE,

    /*!  Mode of skip mode for pixels inside of skip area. The related parameter can be
    - ::MML_GDC_PE_SKIP_COLOR_CONSTANT (Default)
    - ::MML_GDC_PE_SKIP_COLOR_ZERO
    */
    MML_GDC_PE_SURF_ATTR_SKIP_MODE
} MML_GDC_PE_SURF_ATTR;


/*! Blit Blend function definition used by #mmlGdcPeBlendFunc. */
typedef enum {
    MML_GDC_PE_BF_GL_ZERO                     = 0x0UL,
    MML_GDC_PE_BF_GL_ONE                      = 0x1UL,
    MML_GDC_PE_BF_GL_SRC_COLOR                = 0x300UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_SRC_COLOR      = 0x301UL,
    MML_GDC_PE_BF_GL_SRC_ALPHA                = 0x302UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA      = 0x303UL,
    MML_GDC_PE_BF_GL_DST_ALPHA                = 0x304UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_DST_ALPHA      = 0x305UL,
    MML_GDC_PE_BF_GL_DST_COLOR                = 0x306UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_DST_COLOR      = 0x307UL,
    MML_GDC_PE_BF_GL_SRC_ALPHA_SATURATE       = 0x308UL,
    MML_GDC_PE_BF_GL_CONSTANT_COLOR           = 0x8001UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_CONSTANT_COLOR = 0x8002UL,
    MML_GDC_PE_BF_GL_CONSTANT_ALPHA           = 0x8003UL,
    MML_GDC_PE_BF_GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004UL
} MML_GDC_PE_BF;

/*! Blit Blend mode definition used by #mmlGdcPeBlendMode. */
typedef enum {
    MML_GDC_PE_BM_GL_FUNC_ADD                 = 0x8006UL,
    MML_GDC_PE_BM_GL_MIN                      = 0x8007UL,
    MML_GDC_PE_BM_GL_MAX                      = 0x8008UL,
    MML_GDC_PE_BM_GL_FUNC_SUBTRACT            = 0x800AUL,
    MML_GDC_PE_BM_GL_FUNC_REVERSE_SUBTRACT    = 0x800BUL,
    MML_GDC_PE_BM_VG_BLEND_SRC                = 0x2000UL,
    MML_GDC_PE_BM_VG_BLEND_SRC_OVER           = 0x2001UL,
    MML_GDC_PE_BM_VG_BLEND_DST_OVER           = 0x2002UL,
    MML_GDC_PE_BM_VG_BLEND_SRC_IN             = 0x2003UL,
    MML_GDC_PE_BM_VG_BLEND_DST_IN             = 0x2004UL,
    MML_GDC_PE_BM_VG_BLEND_MULTIPLY           = 0x2005UL,
    MML_GDC_PE_BM_VG_BLEND_SCREEN             = 0x2006UL,
    MML_GDC_PE_BM_VG_BLEND_DARKEN             = 0x2007UL,
    MML_GDC_PE_BM_VG_BLEND_LIGHTEN            = 0x2008UL,
    MML_GDC_PE_BM_VG_BLEND_ADDITIVE           = 0x2009UL
} MML_GDC_PE_BM;

/*! Blend function for second blit blend step or layer blend */
typedef enum {
    MML_GDC_IRS_LAYER_BF_ZERO = 0x0UL,
    MML_GDC_IRS_LAYER_BF_ONE,
    MML_GDC_IRS_LAYER_BF_DST_ALPHA,
    MML_GDC_IRS_LAYER_BF_ONE_MINUS_DST_ALPHA,
    MML_GDC_IRS_LAYER_BF_SRC_ALPHA,
    MML_GDC_IRS_LAYER_BF_ONE_MINUS_SRC_ALPHA,
    MML_GDC_IRS_LAYER_BF_CONST_ALPHA,
    MML_GDC_IRS_LAYER_BF_ONE_MINUS_CONST_ALPHA
} MML_GDC_IRS_LAYER_BF;


 typedef struct _MML_GDC_PE_CONTEXT_CONTAINER
 {
     MM_U32 reserved[102];
}MML_GDC_PE_CONTEXT_CONTAINER, *MML_GDC_PE_CONTEXT;

/*****************************************************************************/
/*** GLOBAL VARIABLES ********************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/

/**
*   [SWDD3300] Reset all parameters of the context object.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   @param[in,out] pectx The context object
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeResetContext(MML_GDC_PE_CONTEXT pectx);


/**
*   [SWDD3310] mmlGdcPeBindSurface binds a surface to a context.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   If drvctx is equal to NULL, mmlGdcPeBindSurface is terminated without any operation.
*   @note All binded surfaces must no be deleted as long as the context is used.
*   Parameter changes in the surface object after binding are used for further
*   blit operations with the context.
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] target Binding target. It is a single or OR combined value of:
*       - ::MML_GDC_PE_SRC
*       - ::MML_GDC_PE_DST
*       - ::MML_GDC_PE_STORE
*       - ::MML_GDC_PE_SRC2 (not for Titan)
*       - ::MML_GDC_PE_MASK
*   @param[in] surface Surface object
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBindSurface(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_SURFACE surface);


/**
*   [SWDD3314] Set attributes for PixEngine operations.\n
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*   If pectx is equal to NULL, mmlGdcPeAttribute is terminated without any operation.
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] pname State name for setting. Can be one of ::MML_GDC_PE_CTX_ATTR
*   @param[in] param Parameter for argument target (See ::MML_GDC_PE_CTX_ATTR description)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeAttribute (MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_CTX_ATTR pname, MM_U32 param);

/**
*   [SWDD3050] Set rectangle area in which any operation of PixEngine is skipped.
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*
*   User can select to fill the area by constant color or zero. See also #mmlGdcPeSurfColor.
*
*   The area is defined by lower left coordinate, width and height.
*   The lower left coordinate is inside of skipping area.
*   The upper right coordinate (x+w, y+h) is outside of skipping area.
*   Parameters must be x < x+w and y < y+h.
*   If x or y is 4096 or heigher, function returns MML_ERR_GDC_PE_INVALID_PARAMETER.
*
*   If w and h are equal to 0, skipping is disabled.
*   If pectx is equal to NULL, mmlGdcPeSkip is terminated without any operation.
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] target Setting target. It is a single or OR combined value of:\n
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_MASK\n
*   @param[in] x horizontal start pixel of the skip frame (0 - 4095)
*   @param[in] y vertical start pixel of the skip frame (0 - 4095) (Count direction depends on ::MML_GDC_PE_ATTR_ZERO_POINT)
*   @param[in] w Width of skip frame (0 - 4096)
*   @param[in] h Height of skip frame (0 - 4096)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSkip(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_U32 x, MM_U32 y, MM_U32 w, MM_U32 h);

/**
*   [SWDD3320] Set the constant color value.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   This color has the following usage:\n
*       - Fill color used in mmlGdcPeFill.
*       - Constant color used in blend mode
*           (For detail information, refer to #mmlGdcPeBlendMode)
*   If pectx is equal to NULL, mmlGdcPeColor is terminated without any operation.
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] red Red component of color (0 - 255, default 0)
*   @param[in] green Green component of color (0 - 255, default 0)
*   @param[in] blue Blue component of color (0 - 255, default 0)
*   @param[in] alpha Alpha component of color (0 - 255, default 0)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeColor(MML_GDC_PE_CONTEXT pectx, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha);


/**
*   [SWDD3314] Set attributes for each surface indicated target.
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*
*   If pectx is equal to NULL, mmlGdcPeSurfAttribute is terminated without any operation.
*   @note
*   - If pixel becomes subject to both tiling and skipping, MML_GDC_PE_SURF_ATTR_SKIP_MODE setting takes precedence.
*   - The MASK surface does not support color multiplication. The function reports an error if a related parameter
*     is set.
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] target Setting target
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_MASK\n
*       ::MML_GDC_PE_SRC2\n
*   @param[in] pname State name for setting. Can be one of ::MML_GDC_PE_SURF_ATTR.
*   @param[in] param Parameter for target. See ::MML_GDC_PE_SURF_ATTR description.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSurfAttribute(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_PE_SURF_ATTR pname, MM_U32 param);

/**
*   [SWDD3080] Set the constant color value for the surface defined by target.
*   \cond Related to SWAD100 \endcond
*
*   Indicated color is used for following usage. (See also #mmlGdcPeSurfAttribute.)
*   - Constant color in skipped area.
*   - Constant color in color multiplication.
*   - Constant color in tiling.
*   - Constant color used for the generation of a color component in format conversion
*       e.g. Format conversion from RGB565 to RGBA8888 when 0x1234_5678 is used as constant color
*           0xFFFF (RGB565) -> 0xFFFF_FF78 (RGBA8888)
*
*   If pectx is equal to NULL, mmlGdcPeSurfColor is terminated without any operation.
*   @note Setting different constant color to skipping and color multiplication is not supported.
*   If MML_GDC_PE_SURF_ATTR_SKIP and MML_GDC_PE_SURF_ATTR_COLMULTI are enabled,
*   same value is used as constant color indicated by mmlGdcPeSurfColor.
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] target Setting target
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_MASK\n
*       ::MML_GDC_PE_SRC2\n
*   @param[in] red Red component of color (0 - 255, default 255)
*   @param[in] green Green component of color (0 - 255, default 255)
*   @param[in] blue Blue component of color (0 - 255, default 255)
*   @param[in] alpha Alpha component of color (0 - 255, default 255)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSurfColor(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha);

/**
*   [SWDD3322] Set the blending parameter.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   When one of the following functions is used, a color value set by #mmlGdcPeColor is used as constant color.
*   - ::MML_GDC_PE_BF_GL_CONSTANT_COLOR
*   - ::MML_GDC_PE_BF_GL_ONE_MINUS_CONSTANT_COLOR
*   - ::MML_GDC_PE_BF_GL_CONSTANT_ALPHA
*   - ::MML_GDC_PE_BF_GL_ONE_MINUS_CONSTANT_ALPHA
*
*   If pectx is equal to NULL, mmlGdcPeBlendFunc is terminated without any operation.
*   @note When OpenVG blend mode (See #mmlGdcPeBlendMode) is used, setting for this function is ignored in drawing image.
*   @param[in,out] pectx Pointer of context area of driver (!=NULL)
*   @param[in] func_red_src Blend function of source red (default: MML_GDC_PE_BF_GL_SRC_ALPHA)
*   @param[in] func_red_dst Blend function of destination red (default: MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA)
*   @param[in] func_green_src Blend function of source green (default: MML_GDC_PE_BF_GL_SRC_ALPHA)
*   @param[in] func_green_dst Blend function of destination green (default: MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA)
*   @param[in] func_blue_src Blend function of source blue (default: MML_GDC_PE_BF_GL_SRC_ALPHA)
*   @param[in] func_blue_dst Blend function of destination blue (default: MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA)
*   @param[in] func_alpha_src Blend function of source alpha (default: MML_GDC_PE_BF_GL_SRC_ALPHA)
*   @param[in] func_alpha_dst Blend function of destination alpha (default: MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBlendFunc(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BF func_red_src, MML_GDC_PE_BF func_red_dst,
        MML_GDC_PE_BF func_green_src, MML_GDC_PE_BF func_green_dst, MML_GDC_PE_BF func_blue_src, MML_GDC_PE_BF func_blue_dst,
        MML_GDC_PE_BF func_alpha_src, MML_GDC_PE_BF func_alpha_dst);

/**
*   [SWDD3326] Set the blending parameter.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   If pectx is equal to NULL, mmlGdcPeBlendMode is terminated without any operation.
*   @note The output of a blend oeration is always alpha pre-multiplied.
*   For the detail blend function, refer to chapter 13.2 in OpenVG specification Version 1.1 (March 27, 2007).
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] mode_red Blend mode of red (default: MML_GDC_PE_BM_GL_FUNC_ADD)
*   @param[in] mode_green Blend mode of green (default: MML_GDC_PE_BM_GL_FUNC_ADD)
*   @param[in] mode_blue Blend mode of blue (default: MML_GDC_PE_BM_GL_FUNC_ADD)
*   @param[in] mode_alpha Blend mode of alpha (default: MML_GDC_PE_BM_GL_FUNC_ADD)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBlendMode(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BM mode_red, MML_GDC_PE_BM mode_green, MML_GDC_PE_BM mode_blue, MML_GDC_PE_BM mode_alpha);

/**
*   [SWDD3343] Set the color blend function the second blend unit.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   @note Calypso and Titan devices cannot use transparent color and alpha blend
*     in the second blend unit so blending is switched off if
*     #mmlGdcPeBlend2SetTransparency is called.
*     On the other hand a previously enabled transparent color will be switched off
*     by calling #mmlGdcPeBlend2Func for this blend step.
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] func_color_src Blend function for source color (default: MML_GDC_IRS_LAYER_BF_SRC_ALPHA)
*   @param[in] func_color_dst Blend function for destination color (default: MML_GDC_IRS_LAYER_BF_ONE_MINUS_SRC_ALPHA)
*   @param[in] func_alpha_src Blend function for source alpha (default: MML_GDC_IRS_LAYER_BF_SRC_ALPHA)
*   @param[in] func_alpha_dst Blend function for destination alpha (default: MML_GDC_IRS_LAYER_BF_ONE_MINUS_SRC_ALPHA)
*   @param[in] alpha Alpha value for modes using consant alpha
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBlend2Func(MML_GDC_PE_CONTEXT pectx,
        MML_GDC_IRS_LAYER_BF func_color_src, MML_GDC_IRS_LAYER_BF func_color_dst,
        MML_GDC_IRS_LAYER_BF func_alpha_src, MML_GDC_IRS_LAYER_BF func_alpha_dst,
        MM_U08 alpha);

/**
*  [SWDD3346] Set transparency for the second blend unit. The color components r, g, b are
*  \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*  always 8 bit values also for 16 bpp and indexed color modes.
*  For instance call mmlGdcPeBlend2SetTransparency(MM_TRUE, 255, 255, 255) to
*  disable the 0xffff color entry in a 16 bpp buffer.
*  @note Calypso and Titan devices cannot use transparent color and alpha blend
*     in the second blend unit so blending is switched off if
*     #mmlGdcPeBlend2SetTransparency is called.
*     On the other hand a previously enabled transparent color will be switched off
*     by calling #mmlGdcPeBlend2Func for this blend step.
*  @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*  @param enable Enable transparency
*  @param red red component of transparent color
*  @param green green component of transparent color
*  @param blue blue component of transparent color
*
*  @return MML_OK on success. Otherwise the related error code defined above.
**/
IRIS_API MM_S32 mmlGdcPeBlend2SetTransparency( MML_GDC_PE_CONTEXT pectx,
                                  MM_BOOL enable,
                                  MM_U08 red,
                                  MM_U08 green,
                                  MM_U08 blue );

/**
*   [SWDD3330] Set the raster operation (ROP) for each color channel and the alpha channel.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   If pectx is equal to NULL, mmlGdcPeRopOperation is terminated without any operation.
*   @note
*   - The involved source surfaces depend on the ROP mode.
*     The driver will report an error if a requested surface
*     is not defined and #mmlGdcPeBlt is called.
*     If one of the ROP modes uses the DST surface the blend
*     unit in the blit path will be switched off and the result
*     will be written directly in the store surface.
*   - The required ROP mode can be calculated by the following table:
*     \verbatim
        surface  DST MASK SRC  output (STORE)
                  0   0   0       0
                  0   0   1       1
                  0   1   0       0
                  0   1   1       1
                  1   0   0       1
                  1   0   1       0
                  1   1   0       1
                  1   1   1       1
              Operation index    0x5A
      \endverbatim
*     Some useful ROP modes are predefined in the define
*     section of this file, see MML_GDC_PE_ROP_...
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] op_red ROP3 operation code for red component(default: ::MML_GDC_PE_ROP_SRCCOPY)
*   @param[in] op_green ROP3 operation code for green component(default: ::MML_GDC_PE_ROP_SRCCOPY)
*   @param[in] op_blue ROP3 operation code for blue component(default: ::MML_GDC_PE_ROP_SRCCOPY)
*   @param[in] op_alpha ROP3 operation code for alpha component(default: ::MML_GDC_PE_ROP_SRCCOPY)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeRopOperation(MML_GDC_PE_CONTEXT pectx, MM_U08 op_red, MM_U08 op_green,
                                        MM_U08 op_blue, MM_U08 op_alpha);

/**
*   [SWDD3060] mmlGdcPeSetMatrix is setting function of transformation matrix for scaling, rotation, translation and flipping.
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*
*   The formular for the transformation based on this matrix is:
*   \verbatim
        xout = fMatrix[0] * x + fMatrix[2] * y + fMatrix[4]
        yout = fMatrix[1] * x + fMatrix[3] * y + fMatrix[5]
    \endverbatim
*   If fMatrix = NULL, following data is set in transformation matrix:
*   \verbatim
        / fMatrix[0] fMatrix[2] fMatrix[4] \      / 1 0 0 \
        |                                  |  =   |       |
        \ fMatrix[1] fMatrix[3] fMatrix[5] /      \ 0 1 0 /
    \endverbatim
*
*   If pectx is equal to NULL mmlGdcPeSetMatrix is terminated without any operation.
*
*   @param[in,out] pectx Pointer for context area of Basic Graphics Library (!=NULL)
*   @param[in] target Setting target. It is a single or OR combined value of:\n
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_MASK\n
*       ::MML_GDC_PE_SRC2\n
*   @param fMatrix [in] Transformation matrix for scaling , rotation, translate, and flip.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSetMatrix(MML_GDC_PE_CONTEXT pectx, MM_U32 target, const MM_FLOAT *fMatrix);

/**
* [SWDD3062] mmlGdcPeSetMatrixFix is equvalent to #mmlGdcPeSetMatrix except the matrix is defined in fix point 16.16 format.
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307, SWAD600 \endcond
*   @param[in,out] pectx Pointer for context area of Basic Graphics Library (!=NULL)
*   @param[in] target Setting target. It is a single or OR combined value of:\n
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_MASK\n
*       ::MML_GDC_PE_SRC2\n
*   @param pMatrix [in] Transformation matrix for scaling , rotation, translate, and flip.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSetMatrixFix(MML_GDC_PE_CONTEXT pectx, MM_U32 target, const MM_S32 *pMatrix);

/**
*   [SWDD3390] mmlGdcPeColorMatrix is setting function for color matrix.
*   Related to: SWAD000, SWAD100, SWAD300, SWAD301, SWAD211
*   If pectx is equal to NULL, mmlGdcPeColorMatrix is terminated without any operation.
*   Color matrix is defined following formula.
*   \verbatim
        red_out   = fMatrixPrt[0] * red + fMatrixPrt[3] * green + fMatrixPrt[6] * blue + fMatrixPrt[9]  * 255
        green_out = fMatrixPrt[1] * red + fMatrixPrt[4] * green + fMatrixPrt[7] * blue + fMatrixPrt[10] * 255
        blue_out  = fMatrixPrt[2] * red + fMatrixPrt[5] * green + fMatrixPrt[8] * blue + fMatrixPrt[11] * 255
    \endverbatim
*   If matrix = 0, following data is settled in transformation matrix:
*   \verbatim
        / fMatrix[0] fMatrix[3] fMatrix[6] fMatrix[ 9] \    / 1 0 0 0 \
        | fMatrix[1] fMatrix[4] fMatrix[7] fMatrix[10] | =  | 0 1 0 0 |
        \ fMatrix[2] fMatrix[5] fMatrix[8] fMatrix[11] /    \ 0 0 1 0 /
     \endverbatim
*
*   Alpha value is bypassed without modification.
*   @param[in,out] pectx Pointer for context area of Basic Graphics Library (!=NULL)
*   @param[in] fMatrix Address of color matrix (See [Description])
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeColorMatrix(MML_GDC_PE_CONTEXT pectx, const MM_FLOAT *fMatrix);

/**
* [SWDD3391] mmlGdcPeColorMatrixFix is equvalent to #mmlGdcPeColorMatrix except the matrix is defined in fix point 16.16 format.
* Related to: SWAD000, SWAD100, SWAD006, SWAD300, SWAD301, SWAD211
*   @param[in,out] pectx Pointer for context area of Basic Graphics Library (!=NULL)
*   @param[in] pMatrix Address of color matrix (See [Description])
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeColorMatrixFix (MML_GDC_PE_CONTEXT pectx, const MM_S32 *pMatrix);


/**
*   [SWDD3350] mmlGdcPeGetDrawBox is a function to get the last draw box.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   Each Blt function calculates a store surface draw rectangle basing
*   on the #mmlGdcPeSelectArea settings and the related surface properties
*   (active area, matrix). The context stores this draw box and
*   or's each new #mmlGdcPeBlt draw box until it is cleaned with the
*   reset parameter of this function. The application can use the draw
*   box to restore a background in this area.
*   If reset is larger than 0, this function deletes the old drawbox and
*   calculates a new one with the next calling of #mmlGdcPeBlt.
*   The function returns an error if no blit operation since the last reset was called
*   and the reset parameter is 0.
*
*   @param[in,out] pectx Pointer for context area of Basic Graphics Library (!=NULL)
*   @param[in,out] x Pointer to get horizontal start point.
*   @param[in,out] y Pointer to get vertical start point (Zero point depends on ::MML_GDC_PE_ATTR_ZERO_POINT)
*   @param[in,out] w Pointer to get width
*   @param[in,out] h Pointer to get height
*   @param[in] reset Reset flag (see above)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeGetDrawBox(MML_GDC_PE_CONTEXT pectx, MM_U32 *x, MM_U32 *y, MM_U32 *w, MM_U32 *h, MM_U32 reset);

/**
*   [SWDD3040] mmlGdcPeActiveArea defines the processing area in the surface indicated by target.
*   \cond Related to SWAD000, SWAD100, SWAD305, SWAD307 \endcond
*
*   See also #mmlGdcPeSelectArea.
*   The area is defined by lower left coordinate, width and height.
*   The lower left coordinate is inside of processing area.
*   The upper right coordinate (x+w, y+h) is outside of processing area.
*   Parameters must be x < x+w and y < y+h.
*   If x or y is equal to 4096, function returns MML_ERR_GDC_PE_INVALID_PARAMETER.
*   If w and h are equal to 0, active area is disabled.
*   If x and y are negative, the color value is defined by #mmlGdcPeSurfAttribute
*   and ::MML_GDC_PE_SURF_ATTR_TILE_MODE.
*   If pectx is equal to NULL, mmlGdcPeActiveArea is terminated without any operation.
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param target [in] Setting target. It is a single or OR combined value of:\n
*       ::MML_GDC_PE_SRC\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_STORE\n
*       ::MML_GDC_PE_MASK\n
*   @param[in] x Left start coordinate of the active area (-4095 - 4096)
*   @param[in] y Lower (or upper see ::MML_GDC_PE_ATTR_ZERO_POINT) start coordinate of the active area (-4095 - 4096)
*   @param[in] w Width of active area (0 - 4096)
*   @param[in] h Height of active area (0 - 4096)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeActiveArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_S32 x, MM_S32 y, MM_U32 w, MM_U32 h);

/**
*   [SWDD3312] mmlGdcPeSelectArea defines which surfaces are used to calculate the processing area.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD301 \endcond
*
*   A default #mmlGdcPeBlt function processes rectangle in store surface
*   defined by the active area (see #mmlGdcPeActiveArea) of the src surface
*   and the given matrix transformation defined by #mmlGdcPeSetMatrix.
*   #mmlGdcPeSelectArea changed it to active area of any other bounded
*   surfaces or a combination of surfaces. Combination can be defined like this:
*       mmlGdcPeSelectArea(pectx, MML_GDC_PE_SRC|GDC_PE_DST);
*   If more than one surface defines to target, the bounding box of all active areas
*   will be used.
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] target [in] Selecting target. It is a single or OR combined value of:\n
*       ::MML_GDC_PE_SRC (default)\n
*       ::MML_GDC_PE_DST\n
*       ::MML_GDC_PE_STORE\n
*       ::MML_GDC_PE_MASK\n
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSelectArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target);

/**
*   [SWDD3400] This API fills the specified region of store surface with the constant color.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD302, SWAD303, SWAD304 \endcond
*
*   When w or h is equal to 0, this API returns MM_TRUE but no work is done.
*
*   @param[in] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] x Left start coordinate of the store surface (0 - 4095)
*   @param[in] y Lower (or upper see ::MML_GDC_PE_ATTR_ZERO_POINT) start coordinate of the store surface (0 - 4095)
*   @param[in] w Width of rectangle region in pixel count (0 - 4096)
*   @param[in] h Height of rectangle region in line count (0 - 4096)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeFill (MML_GDC_PE_CONTEXT pectx, MM_U32 x, MM_U32 y, MM_U32 w, MM_U32 h);


/**
*   [SWDD3410] This API copies data from source region to destination region.
*   \cond Related to SWAD000, SWAD100, SWAD006, SWAD300, SWAD302, SWAD303, SWAD304, SWAD306, SWAD309 \endcond
*
*   When an attribute (ROP, filter,... ) is specified, the effect is reflected to the result of data copy.
*   @note
*   - The offsetx and offsety position parameters will be added to the current
*     geometric matrix of the src and mask surface. That means they are
*     not really required because the matrix changes can handle the same.
*     However the most common use case is to blend a (modified) source bitmap
*     to a defined x, y position and it is much simpler to commit this position
*     as parameter. The geometrical relation between pixels of the target buffer
*     and pixels of the source buffer are defined in the following
*     way:
*       - Mstore is the matrix of the store surface
*       - Moffs represent a matrix using the fX, fY offsets given from this function
*       - and Ms (Xs, Ys) represent the surface matrix (pixel) of the related source: SRC or MASK
*   \verbatim
        / Xstore \                  / Xs \
        |        |  = Moffs * Ms *  |    |
        \ Ystore /                  \ Ys /
    \endverbatim
*   The path for the DST calculation is a little bit different:
*   \verbatim
        / Xstore \            / Xdst \
        |        |  = Mdst *  |      |
        \ Ystore /            \ Ydst /
    \endverbatim
*   - A typical #mmlGdcPeBlt operation processes a store rectangle
*   defined by the active area of the SRC surface and the
*   given matrix transformation. An application can change
*   this behavior by using #mmlGdcPeSelectArea.
*   - A SRC and STORE surface must be defined in minimum to proceed a mmlGdcPeBlt
*   (simple copy) opertation. If a DST surface is defined too a blend operation
*   will be performed. With a MASK surface and a related ROP operation it
*   mutates to a ROP operation. See #mmlGdcPeRopOperation for more details.
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] offsetx horizontal offset (-4096 - 4095)
*   @param[in] offsety vertical offset (-4096 - 4095) (Count direction depends on ::MML_GDC_PE_ATTR_ZERO_POINT)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBlt(MML_GDC_PE_CONTEXT pectx, MM_FLOAT offsetx, MM_FLOAT offsety);

/**
*   [SWDD3411] mmlGdcPeBltFix is equvalent to #mmlGdcPeBlt except the matrix is defined in fix point 16.16 format.
*   \cond Related to SWAD000, SWAD100, SWAD006, SWAD300, SWAD302, SWAD303, SWAD304, SWAD306, SWAD309 \endcond
*
*   @param[in,out] pectx Pointer to context area of Basic Graphics Library (!=NULL)
*   @param[in] offsetx horizontal offset (-4096 - 4095)
*   @param[in] offsety vertical offset (-4096 - 4095) (Count direction depends on ::MML_GDC_PE_ATTR_ZERO_POINT)
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeBltFix(MML_GDC_PE_CONTEXT pectx, MM_S32 offsetx, MM_S32 offsety);

/** @} end defgroup */

/**
 * @defgroup sync_api Synchronization API
 * @{
 */

/**
*    [SWDD2250] This API is used to wait drawing completion for synchronization.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD303 \endcond
*
*   For Calypso and Titan devices it is recommended to use different synchronisation calls because
*   the CPU is blocked until all graphical operations are finished.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeFinish(void);

/**
*   [SWDD2260] Force execution of PixEng commands in finite time. This call has no effect for
*   Calypso and Titan devices.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD303 \endcond
*
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeFlush(void);

/**
*   [SWDD2240] Inserts a sync object into the 2D command stream (similar to the OpenGL glFencSync() call).
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD303 \endcond
*
*   @param[in,out] sync Sync object created by mmlGdcSyncCreate(). After successful completion
*                        of mmlGdcPeSync(), it holds the parameter of the inserted sync.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeSync(MML_GDC_SYNC sync);

/**
*   [SWDD2270] Inserts a sync wait into the 2D command stream (similar to the OpenGL glWaitSync() call).
*   PixEngine operations performed after this call are only executed after sync gets
*   signaled.
*   This mmlGdcPeWaitSync has no function for Calypso and Titan devices.
*   \cond Related to SWAD000, SWAD100, SWAD300, SWAD303 \endcond
*
*   @param[in] sync Sync to wait for.
*   @return MML_OK on success. Otherwise the related error code.
**/
IRIS_API MM_S32 mmlGdcPeWaitSync(MML_GDC_SYNC sync);

/** @} end defgroup */

#ifdef __cplusplus
}
#endif

/*lint -restore */

#endif /* MML_GDC_PIXENG_H */
