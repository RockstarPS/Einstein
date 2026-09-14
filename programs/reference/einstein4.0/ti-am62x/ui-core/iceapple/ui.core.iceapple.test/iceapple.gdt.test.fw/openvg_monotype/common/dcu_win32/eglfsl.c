/*-*- c -*-*******************************************************************
 *
 *  Freescale Semiconductor, Inc.
 *  (c) Copyright 2010, Freescale Semiconductor, Inc.
 *  ALL RIGHTS RESERVED.
 *
 ****************************************************************************/
/** \addtogroup eglfsl
 *  @{
 ****************************************************************************/
/** \file      eglfsl.c
 *  \author    Norbert Stoeffler
 *  \date      2010-02-26
 *
 *  \internal
 *   language  C
 ****************************************************************************/
#include	"EGL/eglfsl.h"
#include	"VG/openvg.h"

/*****************************************************************************
 *  local function prototypes
 ****************************************************************************/

/*****************************************************************************
 *  exported functions
 ****************************************************************************/

/****************************************************************************/

/** return a struct describing the physical buffer dimensions of a given
 *  Pbuffer
 *
 *  \param pbd	pointer to where to store the result
 *  \param dpy	the display
 *  \param surf	the surface id of the Pbuffer
 *  \return	EGL_FALSE on error, EGL_TRUE on success
 */
EGLBoolean eglGetPbufferDimFSL(EGLPbufferDimFSL * pbd,
			                   EGLDisplay         dpy,
			                   EGLSurface         surf)
{
  pbd->Add         =  (unsigned int)((EGLSURFACE *)surf)->pbuff;
  pbd->Width       =  ((EGLSURFACE *)surf)->width;
  pbd->Height      =  ((EGLSURFACE *)surf)->height;
  pbd->PixelFormat =  ((EGLSURFACE *)surf)->pix_format;
  return EGL_TRUE;
}

