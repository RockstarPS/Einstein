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
 * osa firware request functions implementation for QNX
 */

#include "../../inc/osa_firmware.h"
#include "osa_firmware_data.h"
#include <osa_mem.h>

struct firmware {
    size_t size;
    uint8 *data;
};

void osa_init_completion(void **firmware_loading_complete_args)
{
    uint8 size = 1;
    /* Dummy implementation for QNX */
    *firmware_loading_complete_args = osa_malloc(size, 0);
}

int32 osa_request_firmware_nowait(void *module, const osa_char *name,
        void *device, void *context, void *fp)
{
    struct firmware fw;
    void (*cont)(const struct firmware *fw, void *context);

    fw.size = sizeof(firmware_data);
    fw.data = firmware_data;

    cont = (void (*)(const struct firmware *, void *))fp;
    cont(&fw, context);

    return 0;
}

void osa_complete_all(void *x)
{
    /* Dummy implementation for QNX */
}

void osa_wait_for_completion(void *x)
{
    /* Dummy implementation for QNX */
}

void osa_release_firmware(void *fw)
{
    /* Dummy implementation for QNX */
}

size_t osa_get_fw_size(void *fw_args)
{
    struct firmware *fw = (struct firmware *)fw_args;
    return fw->size;
}

const uint8 *osa_get_fw_data(void *fw_args)
{
    struct firmware *fw = (struct firmware *)fw_args;
    return fw->data;
}
