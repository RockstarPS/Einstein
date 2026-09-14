/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * osa error definitions
 */
#ifndef OSA_ERR_H_
#define OSA_ERR_H_

#include "osa_types.h"

#define OSA_EPERM        1  /* Operation not permitted */
#define OSA_ENOENT       2  /* No such file or directory */
#define OSA_ESRCH        3  /* No such process */
#define OSA_EINTR        4  /* Interrupted system call */
#define OSA_EIO          5  /* I/O error */
#define OSA_ENXIO        6  /* No such device or address */
#define OSA_E2BIG        7  /* Argument list too long */
#define OSA_ENOEXEC      8  /* Exec format error */
#define OSA_EBADF        9  /* Bad file number */
#define OSA_ECHILD      10  /* No child processes */
#define OSA_EAGAIN      11  /* Try again */
#define OSA_ENOMEM      12  /* Out of memory */
#define OSA_EACCES      13  /* Permission denied */
#define OSA_EFAULT      14  /* Bad address */
#define OSA_ENOTBLK     15  /* Block device required */
#define OSA_EBUSY       16  /* Device or resource busy */
#define OSA_EEXIST      17  /* File exists */
#define OSA_EXDEV       18  /* Cross-device link */
#define OSA_ENODEV      19  /* No such device */
#define OSA_ENOTDIR     20  /* Not a directory */
#define OSA_EISDIR      21  /* Is a directory */
#define OSA_EINVAL      22  /* Invalid argument */
#define OSA_ENFILE      23  /* File table overflow */
#define OSA_EMFILE      24  /* Too many open files */
#define OSA_ENOTTY      25  /* Not a typewriter */
#define OSA_ETXTBSY     26  /* Text file busy */
#define OSA_EFBIG       27  /* File too large */
#define OSA_ENOSPC      28  /* No space left on device */
#define OSA_ESPIPE      29  /* Illegal seek */
#define OSA_EROFS       30  /* Read-only file system */
#define OSA_EMLINK      31  /* Too many links */
#define OSA_EPIPE       32  /* Broken pipe */
#define OSA_EDOM        33  /* Math argument out of domain of func */
#define OSA_ERANGE      34  /* Math result not representable */

#define OSA_MAX_ERRNO   4095

#define OSA_IS_ERR_VALUE(x) ((ulong)(void *)(x) >= (ulong)-OSA_MAX_ERRNO)

static inline void *OSA_ERR_PTR(slong error)
{
    return (void *) error;
}

static inline long OSA_PTR_ERR(const void *ptr)
{
    return (slong) ptr;
}

static inline osa_bool OSA_IS_ERR(const void *ptr)
{
    return OSA_IS_ERR_VALUE((ulong)ptr);
}
#endif /* OSA_ERR_H_ */
