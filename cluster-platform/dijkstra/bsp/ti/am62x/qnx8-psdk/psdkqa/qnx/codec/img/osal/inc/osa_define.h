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
 * osa definitions header
 */

#ifndef OSA_DEFINE_H_
#define OSA_DEFINE_H_

#if defined(OSAL_LINUX)

#include <linux/dma-mapping.h>
#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include <media/v4l2-mem2mem.h>

#if defined (DEBUG_DECODER_DRIVER) || defined (DEBUG_ENCODER_DRIVER)
#define OSA_PR_INFO             pr_info
#define OSA_PR_DEBUG            pr_debug
#define OSA_DEV_INFO            dev_info
#define OSA_DEV_DBG             dev_dbg
#else
#define OSA_PR_INFO(msg...)
#define OSA_PR_DEBUG(msg...)
#define OSA_DEV_INFO(osa_dev, msg...)
#define OSA_DEV_DBG(osa_dev, msg...)
#endif
#define OSA_DEV_WARN            dev_warn
#define OSA_PR_WARN             pr_warn
#define OSA_DEV_ERR             dev_err
#define OSA_PR_ERR              pr_err
#define OSA_WARN_ON             WARN_ON
#define OSA_PAGE_SIZE           PAGE_SIZE
#define OSA_GFP_KERNEL          GFP_KERNEL
#define OSA_THIS_MODULE         THIS_MODULE
#define OSA_DMA_TO_DEVICE       DMA_TO_DEVICE
#define OSA_DMA_FROM_DEVICE     DMA_FROM_DEVICE
#define OSA_DMA_BIDIRECTIONAL   DMA_BIDIRECTIONAL
#define OSA_DUMP_STACK          dump_stack()

#define MAX_PLANES              3


#elif defined(OSAL_SYSBIOS)

#include "osa_types.h"
#include <ti/osal/TaskP.h>

#define ALIGN(val, alignv)  (((val) + ((typeof(val))(alignv) - 1)) & ~((typeof(val))((alignv)) - 1))
#define BIT(nr)             (1UL << (nr))
#define min(a, b)           (((a) < (b)) ? (a) : (b))
#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))
#define likely(x)           __builtin_expect((x),1)
#define unlikely(x)         __builtin_expect((x),0)

/* PAZE_SIZE value will change according to architecture */
#define PAGE_SIZE               4096
#define GFP_KERNEL              0
#define THIS_MODULE             (void *)0
#define DMA_TO_DEVICE           0
#define DMA_BIDIRECTIONAL       0
#define DMA_FROM_DEVICE         0

#define NSEC_PER_SEC            (1000000000U)
#define MAX_PLANES              3

#define __iomem
#define HW_SYNC_BARRIER()

/**
 * \brief Align 64b value to 'align' bytes
 */
static inline uint64_t ALIGN64(uint64_t val, uint32_t align)
{
    return (uint64_t)( (uint64_t)(val+align-1) / align) * align;
}

/**
 * \brief Align 32b value to 'align' bytes
 */
static inline uint32_t ALIGN32(uint32_t val, uint32_t align)
{
    return (uint32_t)( (uint32_t)(val+align-1) / align) * align;
}

static inline uint32_t HW_RD_REG32_RAW(uint32_t addr)
{
    uint32_t regVal = *(volatile uint32_t *) ((uintptr_t) addr);
    /* Donot call any functions after this. If required implement as macros */
    HW_SYNC_BARRIER();
    return (regVal);
}

static inline void HW_WR_REG32_RAW(uint32_t addr, uint32_t value)
{
    *(volatile uint32_t *) ((uintptr_t) addr) = value;
    /* Donot call any functions after this. If required implement as macros */
    HW_SYNC_BARRIER();
    return;
}

#define ioread32(addr) (HW_RD_REG32_RAW((uint32_t) (addr)))

#define iowrite32(value, addr)    \
    (HW_WR_REG32_RAW((uint32_t) (addr), (uint32_t) (value)))

static inline int64 div_s64_rem(int64 dividend, int32 divisor, int32 *remainder)
{
    *remainder = dividend % divisor;
    return dividend / divisor;
}

static inline int64 div_s64(int64 dividend, int32 divisor)
{
    int32 remainder;
    return div_s64_rem(dividend, divisor, &remainder);
}

extern volatile int32 g_AssertFailLoop;

void VideoCodec_printf(const char *format, ...);

#ifdef DEBUG_DECODER_DRIVER
#define OSA_DEV_DBG(DEV, ...)       VideoCodec_printf(__VA_ARGS__)
#define OSA_DEV_INFO(DEV, ...)      VideoCodec_printf(__VA_ARGS__)
#define OSA_PR_DEBUG                VideoCodec_printf
#define OSA_PR_INFO                 VideoCodec_printf
#else
#define OSA_PR_INFO(msg...)
#define OSA_PR_DEBUG(msg...)
#define OSA_DEV_INFO(osa_dev, msg...)
#define OSA_DEV_DBG(osa_dev, msg...)
#endif
#define OSA_WARN_ON                 UTILS_assert
#define OSA_PR_ERR                  VideoCodec_printf
#define OSA_PR_WARN                 VideoCodec_printf
#define OSA_DEV_ERR(DEV, ...)       VideoCodec_printf(__VA_ARGS__)
#define OSA_DEV_WARN(DEV, ...)      VideoCodec_printf(__VA_ARGS__)

#define OSA_PAGE_SIZE               PAGE_SIZE
#define OSA_GFP_KERNEL              GFP_KERNEL
#define OSA_THIS_MODULE             THIS_MODULE
#define OSA_DMA_TO_DEVICE           DMA_TO_DEVICE
#define OSA_DMA_FROM_DEVICE         DMA_FROM_DEVICE
#define OSA_DMA_BIDIRECTIONAL       DMA_BIDIRECTIONAL
#define OSA_DUMP_STACK              dump_stack()

#define UTILS_assert(y)                                     \
    (UTILS_assertLocal((osa_bool) (y), (const int8 *) # y, \
                       (const int8 *) __FILE__, (int32) __LINE__))

static inline void UTILS_assertLocal(osa_bool   condition,
                                     const int8  *str,
                                     const int8  *fileName,
                                     int32  lineNum)
{
    if (condition != FALSE) {
        OSA_PR_ERR(" Assertion @ Line: %d in %s: %s : failed !!!\n",
                lineNum, fileName, str);
        OSA_PR_ERR(" Assertion @ Line: %d in %s: %s : failed !!!\n",
                lineNum, fileName, str);
        while(g_AssertFailLoop)
        {
            TaskP_sleepInMsecs(1U);
        }
    }
    return;
}

static inline void dump_stack()
{
    /* This is dummy implementation, later we have change */
    UTILS_assert(TRUE);
}

#elif defined(OSAL_QNX)

#include <assert.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <string.h>
#include <hw/inout.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#undef ALIGN
#define ALIGN(val, alignv)  (((val) + ((typeof(val))(alignv) - 1)) & ~((typeof(val))((alignv)) - 1))

#define UTILS_assert(y)                                     \
    (UTILS_assertLocal((bool) (y), (const int8_t *) # y, \
                       (const int8_t *) __FILE__, (int32_t) __LINE__))

static inline void UTILS_assertLocal(bool condition,
                                     const int8_t *str,
                                     const int8_t *fileName,
                                     int32_t lineNum)
{
        if (condition != false)
                slogf(_SLOG_SETCODE(_SLOGC_PRIVATE_START, 65), _SLOG_ERROR,
                      " Assertion @ Line: %d in %s: %s : failed !!!\n",
                      lineNum, fileName, str);
        return;
}

static inline void dump_stack()
{
    return;
}

#define BIT(nr)             (1UL << (nr))
#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))
#define likely(x)           __builtin_expect((x),1)
#define unlikely(x)         __builtin_expect((x),0)

#define GFP_KERNEL              0

#define ioread32(addr)     in32((uint64_t)(addr))
#define iowrite32(val, addr) out32((uint64_t)(addr), val)

static inline int64_t div_s64_rem(int64_t dividend, int32_t divisor, int32_t *remainder)
{
        *remainder = dividend % divisor;
        return dividend / divisor;
}

static inline int64_t div_s64(int64_t dividend, int32_t divisor)
{
        int32_t remainder;
        return div_s64_rem(dividend, divisor, &remainder);
}

void osa_qnx_logger(int level, const char *fmt, ...);
void osa_qnx_dev_logger(int level, const void *dev, const char *fmt, ...);

#define OSA_DEV_DBG(DEV, ...)           osa_qnx_logger(_SLOG_DEBUG1, __VA_ARGS__)
#define OSA_DEV_INFO(DEV, ...)          osa_qnx_logger(_SLOG_INFO, __VA_ARGS__)
#define OSA_PR_DEBUG(...)               osa_qnx_logger(_SLOG_DEBUG1, __VA_ARGS__)
#define OSA_PR_INFO(...)                osa_qnx_logger(_SLOG_INFO, __VA_ARGS__)

#if defined NDEBUG
#define OSA_WARN_ON                     UTILS_assert
#else
#define OSA_WARN_ON(y)                  assert((int)(y) == 0)
#endif
#define OSA_PR_ERR(...)                 osa_qnx_logger(_SLOG_ERROR, __VA_ARGS__)
#define OSA_PR_WARN(...)                osa_qnx_logger(_SLOG_WARNING, __VA_ARGS__)
#define OSA_DEV_ERR(DEV, ...)           osa_qnx_dev_logger(_SLOG_ERROR, DEV, __VA_ARGS__)
#define OSA_DEV_WARN(DEV, ...)          osa_qnx_dev_logger(_SLOG_WARNING, DEV, __VA_ARGS__)

#define OSA_PAGE_SIZE          getpagesize()
#define OSA_GFP_KERNEL         GFP_KERNEL
#define OSA_THIS_MODULE        (void *)0
#define OSA_DMA_TO_DEVICE      0
#define DMA_FROM_DEVICE    0
#define OSA_DMA_FROM_DEVICE    0
#define OSA_DMA_BIDIRECTIONAL  0
#define OSA_DUMP_STACK         dump_stack()

#define NSEC_PER_SEC            (1000000000U)
#define MAX_PLANES              3

#define __iomem

#else

#error "Define macro for other paltform"

#endif

#endif /* OSA_DEFINE_H_ */
