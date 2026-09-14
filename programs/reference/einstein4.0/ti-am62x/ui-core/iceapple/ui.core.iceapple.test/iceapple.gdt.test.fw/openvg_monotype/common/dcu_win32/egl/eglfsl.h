/*-*- c -*-*******************************************************************
 *
 *  Freescale Semiconductor, Inc.
 *  (c) Copyright 2010, Freescale Semiconductor, Inc.
 *  ALL RIGHTS RESERVED.
 *
 ****************************************************************************/
/** \addtogroup eglfsl
 *  Freescale EGL extension allowing the direct access to the memory of a
 *  Pbuffer. Pbuffer contents then can be displayed by the DCUs directly
 *  without any further copying or reformatting. The presence of the
 *  extension is signalled  statically by the presence of the define
 *  EGL_FSL_get_pbuffer_dim, and dynamically by
 *  eglQueryString(dpy,EGL_EXTENSIONS).
 *
 *  @{
 ****************************************************************************/
/** \file      eglfsl.h
 *  \author    Norbert Stoeffler
 *  \date      2010-02-26
 *
 *  \internal
 *   language  C
 ****************************************************************************/

#ifndef EGLFSL_H
#define EGLFSL_H

#include "EGL\egl.h"

/*****************************************************************************
 *  types
 ****************************************************************************/

/** struct describing physical buffer dimensions. integer types must match
    the machine types and therefore are _not_ EGLint etc.
 */
typedef struct {
  int		Width,Height;	/**< dimensions in pixels */
  char		*pByte;		/**< pointer to upper left corner */
  int		Stride;		/**< stride (distance between 2 rows) in
				   bytes */
  unsigned int	Add;		/**< physical address of *pByte */

  int		AllocSize;	/**< real size (including all paddings) of the
				   buffer in bytes */
  int		PixelFormat;	/**< TODO: maybe VGImageFormat */
} EGLPbufferDimFSL;


/*****************************************************************************
 *  exported functions
 ****************************************************************************/

EGLAPI EGLBoolean eglGetPbufferDimFSL(EGLPbufferDimFSL *pbd,
				      EGLDisplay dpy, EGLSurface surf);


#endif /* EGLFSL_H */
