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
 * osa time related functions definitions
 */

#ifndef OSA_TIME_H_
#define OSA_TIME_H_

#include "osa_types.h"

#define osa_time_before(a, b)                   ((int64)((a) - (b)) < 0)
#define osa_time_is_before_eq_jiffies(a, b)     ((int64)((a) - (b)) >= 0)
#define osa_time_is_after_jiffies(a, b)         ((int64)((a) - (b)) < 0)

#if defined(OSAL_LINUX)
#include <linux/time.h>

struct osa_timespec {
    struct timespec ts;
};
#elif defined(OSAL_SYSBIOS)
struct osa_timespec {
    uint64 ts;
};
#elif defined(OSAL_QNX)
#include <time.h>
struct osa_timespec {
    struct timespec ts;
};
#endif

/* This function will return reminder and quotient */
static inline uint32 osa_do_div(uint64 *n, uint32 base)
{
    uint32 remainder = *n % base;
    *n = *n / base;
    return remainder;
}

/* Jiffies is a global variable declared in <linux/jiffies.h>
 * as: extern unsigned long volatile jiffies; Its only usage is to store the
 * number of ticks occurred since system start-up. On kernel boot-up,
 * jiffies is initialized to a special initial value, and it is incremented
 * by one for each timer interrupt
 */

uint64 osa_get_number_of_ticks(void);

/**
 * osa_msecs_to_jiffies: - convert milliseconds to jiffies
 * @m:  time in milliseconds
 *
 * conversion is done as follows:
 *
 * - negative values mean 'infinite timeout' (MAX_JIFFY_OFFSET)
 *
 * - 'too large' values [that would result in larger than
 *   MAX_JIFFY_OFFSET values] mean 'infinite timeout' too.
 *
 * - all other values are converted to jiffies by either multiplying
 *   the input value by a factor or dividing it with a factor and
 *   handling any 32-bit overflows.
 */
uint64 osa_msecs_to_jiffies(uint32 m);

/*
 * Convert jiffies to milliseconds and back.
 */
uint64 osa_jiffies_to_msecs(uint64 j);

/* This function allocate memory and return current time */
void osa_getnstimeofday(struct osa_timespec *ts_args);

/* This function allocate memory return the time difference */
void osa_timespec_sub(struct osa_timespec *end_time, struct osa_timespec *start_time, struct osa_timespec *dif_time);

/**
 * osa_timespec_to_ns - Convert given time to nanoseconds
 * @ts_args: pointer to the variable, to be converted
 *
 * Returns the given time in nanosecond
 */
int64 osa_timespec_to_ns(struct osa_timespec *ts_args);

#endif /* OSA_TIME_H_ */
