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

#include <stdint.h>
#include <sys/mman.h>

#include <ti/csl/soc.h>
#include "osa_reg_io.h"
#include "osa_define.h"
#include "osa_delay.h"


void osa_reg32_write(uint32 val, uint_addr addr)
{
    *(volatile uint32 *)addr = val;
}

uint32 osa_reg32_read(uint_addr addr)
{
    return *(volatile uint32 *)addr;
}

int32 osa_reg32_poll_iseq(uint_addr addr, uint32 req_val, uint32 mask, uint32 cnt)
{
    uint32 count, val;
    int32 res = 0;

    /* Add high-frequency poll loops. */
    cnt += 10;

    /*
     * High-frequency loop (designed for shorter hardware latency such as
     * reset).
     */
    for (count = 0; count < cnt; count++) {
        /* Read from the device */
        val = osa_reg32_read(addr);
        val = (val & mask);

        if (val == req_val) {
            res = 0;
            break;
        }

        /*
         * Sleep to wait for hardware.
         * Period is selected to allow for high-frequency polling
         * (5us, e.g. reset) over the first 10 iterations, then
         * reverting to a lower-frequency (100us, e.g. DMA) for the
         * remainder.
         */
        if (count < 10)
            osa_usleep_range(5, 5);
        else
            osa_usleep_range(100, 100);
    }

    if (res || (count >= cnt)) {
        OSA_PR_INFO("Poll failed!\n");
        res = -1;
    }

    return res;
}

void *osa_get_decoder_base_reg_addr(void)
{
    void *reg_addr = NULL;

    reg_addr = (void *)mmap_device_io(0x100000, CSL_DECODER0_MTX_CORE_BASE);
    if (reg_addr == (void *)MAP_DEVICE_FAILED)
        return NULL;

    return reg_addr;
}

void *osa_get_encoder_base_reg_addr(void)
{
    void *reg_addr = NULL;

    reg_addr = (void *)mmap_device_io(ENCODER0_REG_SIZE, CSL_ENCODER0_REG_TOPAZHP_MULTICORE_BASE);
    if (reg_addr == (void *)MAP_DEVICE_FAILED)
        return NULL;

    return reg_addr;
}
