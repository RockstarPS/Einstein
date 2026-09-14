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
 * osa time handling functions implementation for QNX
 */

#include <stdio.h>
#include <sys/times.h>

#include "../../inc/osa_time.h"
#include "../../inc/osa_mem.h"
#include "../../inc/osa_define.h"

/* The finest resolution we need is ms */
uint64 osa_get_number_of_ticks(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
}

/* We're using ms as jiffies */
uint64 osa_msecs_to_jiffies(uint32 m)
{
    return m;
}

/* We're using ms as jiffies */
uint64 osa_jiffies_to_msecs(uint64 j)
{
    return j;
}

void osa_getnstimeofday(struct osa_timespec *ts_args)
{
    struct timespec *ts;

    if(NULL == ts_args)
    {
        printf("Failed to allocate memory in 'osa_getnstimeofday' function \n");
    }
    else
    {
        ts = (struct timespec *)(&ts_args->ts);
        timespec_get(ts, TIME_UTC);
    }
}

void osa_timespec_sub(struct osa_timespec *end_time, struct osa_timespec *start_time, struct osa_timespec *dif_time)
{
    struct timespec *ts = (struct timespec *)(&dif_time->ts);

    ts->tv_sec = end_time->ts.tv_sec - start_time->ts.tv_sec;
    ts->tv_nsec = end_time->ts.tv_nsec - start_time->ts.tv_nsec;
}

/**
 * osa_timespec_to_ns - Convert timespec to nanoseconds
 * @ts_args:     pointer to the variable to be converted
 *
 * Returns the given time in nanosecond
 */
int64 osa_timespec_to_ns(struct osa_timespec *ts_args)
{
    struct timespec *ts = (struct timespec *)(&ts_args->ts);
    return timespec2nsec(ts);
}

