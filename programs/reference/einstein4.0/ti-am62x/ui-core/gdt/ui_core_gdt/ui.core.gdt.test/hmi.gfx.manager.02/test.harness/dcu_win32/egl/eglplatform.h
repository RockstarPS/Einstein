/* -*- mode: c; tab-width: 8; -*- */
/* vi: set sw=4 ts=8: */
/* Platform-specific types and definitions for egl.h
 * Last modified 2008/10/22
 *
 * If you make additions or modifications to eglplatform.h specific to
 * your implementation or runtime environment, please send them to
 * Khronos (preferably by filing a bug in the member or public Bugzillas
 * and attaching a copy) for possible inclusion in future versions.
 */

/*
** Copyright (c) 2007-2008 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

#ifndef __eglplatform_h_
#define __eglplatform_h_

// AMD commented out this include so WinCE would build
//#include <sys/types.h>

/* Macros used in EGL function prototype declarations.
 *
 * EGLAPI return-type EGLAPIENTRY eglFunction(arguments);
 * typedef return-type (EXPAPIENTRYP PFNEGLFUNCTIONPROC) (arguments);
 *
 * On Windows, EGLAPIENTRY can be defined like APIENTRY.
 * On most other platforms, it should be empty.
 */

//#ifndef EGLAPI
#     define EGLAPI
//#endif

#define EGLAPIENTRY

#define EGLAPIENTRYP EGLAPIENTRY *

/* The types NativeDisplayType, NativeWindowType, and NativePixmapType
 * are aliases of window-system-dependent types, such as X Display * or
 * Windows Device Context. They must be defined in platform-specific
 * code below. The EGL-prefixed versions of Native*Type are the same
 * types, renamed in EGL 1.3 so all types in the API start with "EGL".
 */


typedef void *NativeDisplayType;
typedef void *NativePixmapType;
typedef void *NativeWindowType;


/* EGL 1.2 types, renamed for consistency in EGL 1.3 */
typedef NativeDisplayType EGLNativeDisplayType;
typedef NativePixmapType EGLNativePixmapType;
typedef NativeWindowType EGLNativeWindowType;

/* platform specific Out-of-band handle values */

/* Define EGLint. This must be an integral type large enough to contain
 * all legal attribute names and values passed into and out of EGL,
 * whether their type is boolean, bitmask, enumerant (symbolic
 * constant), integer, handle, or other.
 * While in general a 32-bit integer will suffice, if handles are
 * represented as pointers, then EGLint should be defined as a 64-bit
 * integer type.
 */
typedef int EGLint;

#endif
