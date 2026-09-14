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
 * osa data type definitions
 */

#ifndef OSA_TYPES_H_
#define OSA_TYPES_H_

/* This structure definition used for circular linked list implementation */
struct clist_head {
    struct clist_head *next, *prev;
};

enum {
    osa_false   = 0,
    osa_true    = 1,
    OSA_STATE_FORCE32BITS = 0x7FFFFFFFU
};

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

enum {
    HWA_DECODER   = 0,
    HWA_ENCODER    = 1,
    HWA_FORCE32BITS = 0x7FFFFFFFU
};

#define MAX_PLANES  3

#if defined(OSAL_LINUX)
/* ---------- Intel/AMD x64 processor family -------------------------*/
    typedef signed char                           int8;
    typedef short int                             int16;
    typedef int                                   int32;
    typedef long long int                         int64;
    typedef unsigned char                         uint8;
    typedef unsigned short int                    uint16;
    typedef unsigned int                          uint32;
    typedef unsigned long long int                uint64;
    typedef unsigned long long int                uint_addr;

    typedef unsigned char                         osa_char;

    typedef long                                  slong;
    typedef unsigned long                         ulong;

    typedef unsigned long int                     uintptr_t;
    typedef long unsigned int                     size_t;

    typedef unsigned char                         osa_bool;

    typedef struct v4l2_fh                        file_hndl;
    typedef struct v4l2_m2m_buffer                m2m_buffer;
    typedef struct v4l2_m2m_dev                   m2m_dev;
    typedef struct v4l2_device                    ti_device;

/* ---------- Intel/AMD x64 processor family -------------------------*/
#elif defined(OSAL_SYSBIOS)
/* ---------- For J7 R5F ARM32 Processor family ----------------------*/
    #include <stdio.h>
    #include <stdint.h>
    #include <string.h>

    typedef   signed char   int8;
    typedef          char   uint8;
    typedef          short  int16;
    typedef unsigned short  uint16;
    typedef          int    int32;
    typedef unsigned int    uint32;
    typedef          long long int64;
    typedef unsigned long long uint64;
    typedef unsigned int       uint_addr;

    typedef long slong;
    typedef char osa_char;

    typedef unsigned char osa_bool;

    #ifndef true
    #define true 1
    #endif

    #ifndef false
    #define false 0
    #endif

    #if !defined(A72)
        typedef unsigned long ulong;

    struct timespec{
        uint64 tv_sec;
        uint64 tv_nsec;
    };
    #endif

    struct scatterlist{
        unsigned long   page_link;
        unsigned int    offset;
        unsigned int    length;
        void            *dma_address;
        uint32          is_alloc_inside;
    };

    struct sg_table{
        struct scatterlist *sgl;       /* the list */
        unsigned int       nents;      /* number of mapped entries */
        unsigned int       orig_nents; /* original size of list */
    };

    struct page {
        struct sg_table   *sgt;
    };

    struct work_struct{
        void (* worker_func)(void *work);
        void *work;
        uint8 work_complete;
        void *timer_handle;
        uint32 timer_status;
        void *queue_handle;
        void *workq_sem_handle;
        void *lock;
    };

    struct device{
        void *phy_addr;
    };

    struct v4l2_device{
        struct device   *dev;
    };

    typedef void*               file_hndl;
    typedef void*               m2m_dev;
    typedef struct mm_buffer*   m2m_buffer;
    typedef struct v4l2_device  ti_device;

/* ---------- For J7 R5F ARM32 Processor family ----------------------*/
#elif defined(OSAL_QNX)

    #include <stdarg.h>
    #include <stdint.h>
    #include <stdlib.h>

    typedef int8_t                                int8;
    typedef int16_t                               int16;
    typedef int32_t                               int32;
    typedef int64_t                               int64;
    typedef uint8_t                               uint8;
    typedef uint16_t                              uint16;
    typedef uint32_t                              uint32;
    typedef uint64_t                              uint64;
    typedef uintptr_t                             uint_addr;

    typedef char                                  osa_char;

    typedef long                                  slong;
    typedef unsigned long                         ulong;

    typedef unsigned char                         osa_bool;

    struct scatterlist{
        unsigned long   page_link;
        unsigned int    offset;
        unsigned int    length;
        void            *dma_address;
        uint32          is_alloc_inside;
        uint32          end;
    };

    struct sg_table{
        struct scatterlist *sgl;       /* the list */
        unsigned int       nents;      /* number of mapped entries */
        unsigned int       orig_nents; /* original size of list */
    };

    struct page {
        struct sg_table   *sgt;
    };

    struct work_struct{
        void (* worker_func)(void *work);
        void *work;
        uint8 work_complete;
        void *timer_handle;
        uint32 timer_status;
        void *queue_handle;
        void *workq_sem_handle;
        void *lock;
    };

    struct device{
        void *phy_addr;
    };

    struct v4l2_device{
        struct device   *dev;
    };

    typedef void*                   file_hndl;
    typedef void*                   m2m_dev;
    typedef struct mm_buffer*       m2m_buffer;
    typedef struct v4l2_device      ti_device;

#else
    #error "Define macro for othe paltform"
#endif

#endif /* OSA_TYPES_H_ */
