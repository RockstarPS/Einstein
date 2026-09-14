/****************************************************************************
** Copyright (C) 2004-2009 Mazatech S.r.l. All rights reserved.
**
** This file is part of AmanithVG software, an OpenVG implementation.
** This file is strictly confidential under the signed Mazatech Software
** Non-disclosure agreement and it's provided according to the signed
** Mazatech Software licensing agreement.
**
** Khronos and OpenVG are trademarks of The Khronos Group Inc.
** OpenGL is a registered trademark and OpenGL ES is a trademark of
** Silicon Graphics, Inc.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** For any information, please contact info@mazatech.com
**
****************************************************************************/

/*
   This file is a modified version of the sample implementation of openvg.h, version 1.1
   The original copyright and permission notice, RELATED TO THIS FILE ONLY, are reported below:
*/

/* $Revision: 6810 $ on $Date:: 2008-10-29 07:31:37 -0700 #$ */

/*------------------------------------------------------------------------
 * 
 * VG extensions Reference Implementation
 * -------------------------------------
 *
 * Copyright (c) 2008 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and /or associated documentation files
 * (the "Materials "), to deal in the Materials without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Materials,
 * and to permit persons to whom the Materials are furnished to do so,
 * subject to the following conditions: 
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Materials. 
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE MATERIALS OR
 * THE USE OR OTHER DEALINGS IN THE MATERIALS.
 *
 *//**
 * \file
 * \brief	VG extensions
 *//*-------------------------------------------------------------------*/



#ifndef _VGEXT_H
#define _VGEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <VG/openvg.h>
#include <VG/vgu.h>

#ifndef VG_API_ENTRYP
#   define VG_API_ENTRYP VG_API_ENTRY*
#endif

#ifndef VGU_API_ENTRYP
#   define VGU_API_ENTRYP VGU_API_ENTRY*
#endif

/*-------------------------------------------------------------------------------
 * KHR extensions
 *------------------------------------------------------------------------------*/

typedef enum  {

#ifndef VG_KHR_iterative_average_blur
  VG_MAX_AVERAGE_BLUR_DIMENSION_KHR        = 0x116B,
  VG_AVERAGE_BLUR_DIMENSION_RESOLUTION_KHR = 0x116C,
  VG_MAX_AVERAGE_BLUR_ITERATIONS_KHR       = 0x116D,
#endif

  VG_PARAM_TYPE_KHR_FORCE_SIZE             = VG_MAX_ENUM
} VGParamTypeKHR;

#ifndef VG_KHR_EGL_image
#define VG_KHR_EGL_image 1
/* VGEGLImageKHR is an opaque handle to an EGLImage */
typedef void* VGeglImageKHR; 

#ifdef VG_VGEXT_PROTOTYPES
VG_API_CALL VGImage VG_API_ENTRY vgCreateEGLImageTargetKHR(VGeglImageKHR image);
#endif
typedef VGImage (VG_API_ENTRYP PFNVGCREATEEGLIMAGETARGETKHRPROC) (VGeglImageKHR image);

#endif


#ifndef VG_KHR_iterative_average_blur
#define VG_KHR_iterative_average_blur 1

#ifdef VG_VGEXT_PROTOTYPES
VG_API_CALL void vgIterativeAverageBlurKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGTilingMode tilingMode);
#endif 
typedef void (VG_API_ENTRYP PFNVGITERATIVEAVERAGEBLURKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGTilingMode tilingMode);

#endif


#ifndef VG_KHR_advanced_blending
#define VG_KHR_advanced_blending 1

typedef enum {
  VG_BLEND_OVERLAY_KHR        = 0x2010,
  VG_BLEND_HARDLIGHT_KHR      = 0x2011,
  VG_BLEND_SOFTLIGHT_SVG_KHR  = 0x2012,
  VG_BLEND_SOFTLIGHT_KHR      = 0x2013,
  VG_BLEND_COLORDODGE_KHR     = 0x2014,
  VG_BLEND_COLORBURN_KHR      = 0x2015,
  VG_BLEND_DIFFERENCE_KHR     = 0x2016,
  VG_BLEND_SUBTRACT_KHR       = 0x2017,
  VG_BLEND_INVERT_KHR         = 0x2018,
  VG_BLEND_EXCLUSION_KHR      = 0x2019,
  VG_BLEND_LINEARDODGE_KHR    = 0x201a,
  VG_BLEND_LINEARBURN_KHR     = 0x201b,
  VG_BLEND_VIVIDLIGHT_KHR     = 0x201c,
  VG_BLEND_LINEARLIGHT_KHR    = 0x201d,
  VG_BLEND_PINLIGHT_KHR       = 0x201e,
  VG_BLEND_HARDMIX_KHR        = 0x201f,
  VG_BLEND_CLEAR_KHR          = 0x2020,
  VG_BLEND_DST_KHR            = 0x2021,
  VG_BLEND_SRC_OUT_KHR        = 0x2022,
  VG_BLEND_DST_OUT_KHR        = 0x2023,
  VG_BLEND_SRC_ATOP_KHR       = 0x2024,
  VG_BLEND_DST_ATOP_KHR       = 0x2025,
  VG_BLEND_XOR_KHR            = 0x2026,

  VG_BLEND_MODE_KHR_FORCE_SIZE= VG_MAX_ENUM
} VGBlendModeKHR;
#endif

#ifndef VG_KHR_parametric_filter
#define VG_KHR_parametric_filter 1 

typedef enum {
  VG_PF_OBJECT_VISIBLE_FLAG_KHR = (1 << 0),
  VG_PF_KNOCKOUT_FLAG_KHR       = (1 << 1),
  VG_PF_OUTER_FLAG_KHR          = (1 << 2),
  VG_PF_INNER_FLAG_KHR          = (1 << 3),

  VG_PF_TYPE_KHR_FORCE_SIZE     = VG_MAX_ENUM
} VGPfTypeKHR;

typedef enum {
  VGU_IMAGE_IN_USE_ERROR           = 0xF010,

  VGU_ERROR_CODE_KHR_FORCE_SIZE    = VG_MAX_ENUM
} VGUErrorCodeKHR;

#ifdef VG_VGEXT_PROTOTYPES
VG_API_CALL void VG_API_ENTRY vgParametricFilterKHR(VGImage dst,VGImage src,VGImage blur,VGfloat strength,VGfloat offsetX,VGfloat offsetY,VGbitfield filterFlags,VGPaint highlightPaint,VGPaint shadowPaint);
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguDropShadowKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint shadowColorRGBA);
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguGlowKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint glowColorRGBA) ;
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguBevelKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint highlightColorRGBA,VGuint shadowColorRGBA);
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguGradientGlowKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint stopsCount,const VGfloat* glowColorRampStops);
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguGradientBevelKHR(VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint stopsCount,const VGfloat* bevelColorRampStops);
#endif
typedef void (VG_API_ENTRYP PFNVGPARAMETRICFILTERKHRPROC) (VGImage dst,VGImage src,VGImage blur,VGfloat strength,VGfloat offsetX,VGfloat offsetY,VGbitfield filterFlags,VGPaint highlightPaint,VGPaint shadowPaint);
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUDROPSHADOWKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint shadowColorRGBA);
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUGLOWKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint glowColorRGBA);
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUBEVELKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint highlightColorRGBA,VGuint shadowColorRGBA);
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUGRADIENTGLOWKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint stopsCount,const VGfloat* glowColorRampStops);
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUGRADIENTBEVELKHRPROC) (VGImage dst,VGImage src,VGfloat dimX,VGfloat dimY,VGuint iterative,VGfloat strength,VGfloat distance,VGfloat angle,VGbitfield filterFlags,VGbitfield allowedQuality,VGuint stopsCount,const VGfloat* bevelColorRampStops);

#endif


/*-------------------------------------------------------------------------------
 * NDS extensions
 *------------------------------------------------------------------------------*/

#ifndef VG_NDS_paint_generation
#define VG_NDS_paint_generation 1

typedef enum { 
  VG_PAINT_COLOR_RAMP_LINEAR_NDS            = 0x1A10,
  VG_COLOR_MATRIX_NDS                       = 0x1A11,
  VG_PAINT_COLOR_TRANSFORM_LINEAR_NDS       = 0x1A12,

  VG_PAINT_PARAM_TYPE_NDS_FORCE_SIZE        = VG_MAX_ENUM
} VGPaintParamTypeNds;

typedef enum {
  VG_DRAW_IMAGE_COLOR_MATRIX_NDS            = 0x1F10,

  VG_IMAGE_MODE_NDS_FORCE_SIZE              = VG_MAX_ENUM
} VGImageModeNds;
#endif 


#ifndef VG_NDS_projective_geometry
#define VG_NDS_projective_geometry 1

typedef enum {
  VG_CLIP_MODE_NDS                          = 0x1180,
  VG_CLIP_LINES_NDS                         = 0x1181,
  VG_MAX_CLIP_LINES_NDS                     = 0x1182,

  VG_PARAM_TYPE_NDS_FORCE_SIZE        = VG_MAX_ENUM
} VGParamTypeNds;

typedef enum {
  VG_CLIPMODE_NONE_NDS                      = 0x3000,
  VG_CLIPMODE_CLIP_CLOSED_NDS               = 0x3001,
  VG_CLIPMODE_CLIP_OPEN_NDS                 = 0x3002,
  VG_CLIPMODE_CULL_NDS                      = 0x3003,

  VG_CLIPMODE_NDS_FORCE_SIZE = VG_MAX_ENUM
} VGClipModeNds;

typedef enum {
  VG_RQUAD_TO_NDS              = ( 13 << 1 ),
  VG_RCUBIC_TO_NDS             = ( 14 << 1 ),
  
  VG_PATH_SEGMENT_NDS_FORCE_SIZE = VG_MAX_ENUM
} VGPathSegmentNds;

typedef enum {
  VG_RQUAD_TO_ABS_NDS            = (VG_RQUAD_TO_NDS  | VG_ABSOLUTE),
  VG_RQUAD_TO_REL_NDS            = (VG_RQUAD_TO_NDS  | VG_RELATIVE),
  VG_RCUBIC_TO_ABS_NDS           = (VG_RCUBIC_TO_NDS | VG_ABSOLUTE),
  VG_RCUBIC_TO_REL_NDS           = (VG_RCUBIC_TO_NDS | VG_RELATIVE),

  VG_PATH_COMMAND_NDS_FORCE_SIZE = VG_MAX_ENUM
} VGPathCommandNds;

#ifdef VG_VGEXT_PROTOTYPES
VG_API_CALL void VG_API_ENTRY vgProjectiveMatrixNDS(VGboolean enable) ;
VGU_API_CALL VGUErrorCode VGU_API_ENTRY vguTransformClipLineNDS(const VGfloat Ain,const VGfloat Bin,const VGfloat Cin,const VGfloat* matrix,const VGboolean inverse,VGfloat* Aout,VGfloat* Bout,VGfloat* Cout);
#endif 
typedef void (VG_API_ENTRYP PFNVGPROJECTIVEMATRIXNDSPROC) (VGboolean enable) ;
typedef VGUErrorCode (VGU_API_ENTRYP PFNVGUTRANSFORMCLIPLINENDSPROC) (const VGfloat Ain,const VGfloat Bin,const VGfloat Cin,const VGfloat* matrix,const VGboolean inverse,VGfloat* Aout,VGfloat* Bout,VGfloat* Cout);

#endif

/*-------------------------------------------------------------------------------
 * AmanithVG extensions
 *------------------------------------------------------------------------------*/

#if !defined(AM_EXCLUDE_EXTENSIONS)

#if !defined(VG_MZT_separable_cap_style)
#define VG_MZT_separable_cap_style 1

typedef enum {
    VG_STROKE_START_CAP_STYLE_MZT               = 0x1192,
    VG_STROKE_END_CAP_STYLE_MZT                 = 0x1193,

    VG_PARAM_TYPE0_MZT_FORCE_SIZE               = VG_MAX_ENUM
} VGParamType0Mzt;
#endif

#if !defined(VG_MZT_separable_blend_modes)
#define VG_MZT_separable_blend_modes 1

typedef enum {
    VG_STROKE_BLEND_MODE_MZT                    = 0x1190,
    VG_FILL_BLEND_MODE_MZT                      = 0x1191,

    VG_PARAM_TYPE1_MZT_FORCE_SIZE               = VG_MAX_ENUM
} VGParamType1Mzt;
#endif

#if !defined(VG_MZT_color_ramp_interpolation)
#define VG_MZT_color_ramp_interpolation 1

typedef enum {
    VG_PAINT_COLOR_RAMP_INTERPOLATION_TYPE_MZT  = 0x1A91,

    VG_PAINT_PARAM_TYPE0_MZT_FORCE_SIZE         = VG_MAX_ENUM
} VGPaintParamType0Mzt;

typedef enum {
    VG_COLOR_RAMP_INTERPOLATION_LINEAR_MZT      = 0x1C90,
    VG_COLOR_RAMP_INTERPOLATION_SMOOTH_MZT      = 0x1C91,

    VG_COLOR_RAMP_INTERPOLATION_TYPE_MZT_FORCE_SIZE = VG_MAX_ENUM
} VGColorRampInterpolationTypeMzt;
#endif

#if !defined(VG_MZT_paint_opacity) && (defined(AM_GLE) || defined(AM_GLS))
#define VG_MZT_paint_opacity 1
typedef enum {
    VG_PAINT_OPACITY_MZT                        = 0x1A92,

    VG_PAINT_PARAM_TYPE1_MZT_FORCE_SIZE         = VG_MAX_ENUM
} VGPaintParamType1Mzt;
#endif

#if !defined(VG_MZT_conical_gradient)
#define VG_MZT_conical_gradient 1

typedef enum {
    VG_PAINT_CONICAL_GRADIENT_MZT               = 0x1A90,

    VG_PAINT_PARAM_TYPE2_MZT_FORCE_SIZE         = VG_MAX_ENUM
} VGPaintParamType2Mzt;

typedef enum {
    VG_PAINT_TYPE_CONICAL_GRADIENT_MZT          = 0x1B90,

    VG_PAINT_TYPE_MZT_FORCE_SIZE                = VG_MAX_ENUM
} VGPaintTypeMzt;
#endif

#if !defined(VG_MZT_advanced_blend_modes)
#define VG_MZT_advanced_blend_modes 1

typedef enum {
    VG_BLEND_CLEAR_MZT                          = 0x2090,
    VG_BLEND_DST_MZT                            = 0x2091,
    VG_BLEND_SRC_OUT_MZT                        = 0x2092,
    VG_BLEND_DST_OUT_MZT                        = 0x2093,
    VG_BLEND_SRC_ATOP_MZT                       = 0x2094,
    VG_BLEND_DST_ATOP_MZT                       = 0x2095,
    VG_BLEND_XOR_MZT                            = 0x2096,
    VG_BLEND_OVERLAY_MZT                        = 0x2097,
    VG_BLEND_COLOR_DODGE_MZT                    = 0x2098,
    VG_BLEND_COLOR_BURN_MZT                     = 0x2099,
    VG_BLEND_HARD_LIGHT_MZT                     = 0x209A,
    VG_BLEND_SOFT_LIGHT_MZT                     = 0x209B,
    VG_BLEND_DIFFERENCE_MZT                     = 0x209C,
    VG_BLEND_EXCLUSION_MZT                      = 0x209D,

    VG_BLEND_MODE_MZT_FORCE_SIZE                = VG_MAX_ENUM
} VGBlendModeMzt;
#endif

#if defined(VG_MZT_statistics)
typedef enum {
    VG_STAT_FLATTENING_POINTS_COUNT_MZT         = (1 << 0),
    VG_STAT_FLATTENING_TIME_MS_MZT              = (1 << 1),
    VG_STAT_TRIANGULATION_TRIANGLES_COUNT_MZT   = (1 << 2),
    VG_STAT_TRIANGULATION_TIME_MS_MZT           = (1 << 3),
    VG_STAT_STROKER_POINTS_COUNT_MZT            = (1 << 4),
    VG_STAT_STROKER_TIME_MS_MZT                 = (1 << 5),
    VG_STAT_GL_DRAWELEMENTS_COUNT_MZT           = (1 << 6),
    VG_STAT_GL_DRAWARRAYS_COUNT_MZT             = (1 << 7),
    VG_STATISTIC_ALL_MZT                        = ((1 << 8) - 1),
} VGStatisticInfoMzt;

#if defined(VG_VGEXT_PROTOTYPES)
/*
In the statistics build, this resets statistics counters.
Errors: VG_ILLEGAL_ARGUMENT_ERROR: if statistics is not a valid bitwise OR of values from the VGStatisticInfo enumeration.
*/
VG_API_CALL void VG_API_ENTRY vgResetStatisticsMZT(const VGbitfield statistics) VG_API_EXIT;
/*
In the statistics build, this returns statistics gathered since the last vgResetStatisticsAM.
Errors: VG_ILLEGAL_ARGUMENT_ERROR: if statistic is not one of the values from VGStatisticInfo enumeration.
*/
VG_API_CALL VGint VG_API_ENTRY vgGetStatisticiMZT(const VGStatisticInfoMzt statistic) VG_API_EXIT;
#endif
typedef void (VG_API_ENTRYP PFNVGRESETSTATISTICSMZTPROC) (const VGbitfield statistics);
typedef VGint (VG_API_ENTRYP PFNVGGETSTATISTICIMZTPROC) (const VGStatisticInfoMzt statistic);
#endif

#endif // AM_EXCLUDE_EXTENSIONS

/* Initialize the AmanithVG driver; it internally allocates a 32bit drawing surface with specified
dimensions (in pixels). It must be also specified linear (VG_TRUE) or non-linear (VG_FALSE) color space.
For best performance use non-linear color space. */
VG_API_CALL VGboolean VG_API_ENTRY vgInitContextAM(const VGint surfaceWidth,
                                                   const VGint surfaceHeight,
                                                   const VGboolean surfaceLinearColorSpace) VG_API_EXIT;
#define vgInitContextMZT vgInitContextAM

/* Destroy the AmanithVG driver, it frees all allocated memory and created entities (images, paths, paints). */
VG_API_CALL void VG_API_ENTRY vgDestroyContextAM(void) VG_API_EXIT;
#define vgDestroyContextMZT vgDestroyContextAM

/* Update the dimensions of the drawing surface, since the last call of vgInitContextAM or vgResizeSurfaceAM */
VG_API_CALL void VG_API_ENTRY vgResizeSurfaceAM(const VGint surfaceWidth,
                                                const VGint surfaceHeight) VG_API_EXIT;
#define vgResizeSurfaceMZT vgResizeSurfaceAM

/* Get the drawing surface width, in pixels */
VG_API_CALL VGint VG_API_ENTRY vgGetSurfaceWidthAM(void) VG_API_EXIT;
#define vgGetSurfaceWidthMZT vgGetSurfaceWidthAM

/* Get the drawing surface height, in pixels */
VG_API_CALL VGint VG_API_ENTRY vgGetSurfaceHeightAM(void) VG_API_EXIT;
#define vgGetSurfaceHeightMZT vgGetSurfaceHeightAM

/* Get the drawing surface format */
VG_API_CALL VGImageFormat VG_API_ENTRY vgGetSurfaceFormatAM(void) VG_API_EXIT;
#define vgGetSurfaceFormatMZT vgGetSurfaceFormatAM

/* Get the direct access to the drawing surface pixels (AmanithVG SRE). It must be used only to blit the surface on the screen,
according to the platform graphic subsystem. */
VG_API_CALL VGubyte * VG_API_ENTRY vgGetSurfacePixelsAM(void) VG_API_EXIT;
#define vgGetSurfacePixelsMZT vgGetSurfacePixelsAM

/* Reset depth and stencil buffers to a valid state for the next frame (AmanithVG GLE). */
VG_API_CALL void VG_API_ENTRY vgPostSwapBuffersAM(void) VG_API_EXIT;
#define vgPostSwapBuffersMZT vgPostSwapBuffersAM

#ifdef __cplusplus 
} /* extern "C" */
#endif

#endif /* _VGEXT_H */
