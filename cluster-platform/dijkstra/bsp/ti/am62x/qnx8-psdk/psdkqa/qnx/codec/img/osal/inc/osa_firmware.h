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
 * osa firmware related definitions
 */

#ifndef OSA_FIRMWARE_H_
#define OSA_FIRMWARE_H_

#include "osa_types.h"

/* Fetch firmware from the file system */
void osa_init_completion(void **firmware_loading_complete_args);

/**
 * osa_request_firmware_nowait() - asynchronous version of request_firmware
 * @module: module requesting the firmware
 * @name: name of firmware file
 * @device: device for which firmware is being loaded
 * @context: will be passed over to @cont, and
 *  @fw may be %NULL if firmware request fails.
 * @cont: function will be called asynchronously when the firmware
 *  request is over.
 *
 *  Caller must hold the reference count of @device
 **/
int32 osa_request_firmware_nowait(void *module, const osa_char *name,
        void *device, void *context, void *fp);

/**
 * osa_complete_all: - signals all threads waiting on this completion
 * @x:  holds the state of this particular completion
 *
 * This will wake up all threads waiting on this particular completion event.
 *
 * If this function wakes up a task, it executes a full memory barrier before
 * accessing the task state.
 *
 * Since osa_complete_all() sets the completion of @x permanently to done
 * to allow multiple waiters to finish.
 */
void osa_complete_all(void *x);

/**
 * osa_wait_for_completion: - waits for completion of a task
 * @x:  holds the state of this particular completion
 *
 * This waits to be signaled for completion of a specific task. It is NOT
 * interruptible and there is no timeout.
 */
void osa_wait_for_completion(void *x);

/**
 * osa_release_firmware() - release the resource associated with a firmware image
 * @fw: firmware resource to release
 **/
void osa_release_firmware(void *fw);

/* Return size of firmware data */
size_t osa_get_fw_size(void *fw_args);

/* Return the firmware data pointer */
const uint8 *osa_get_fw_data(void *fw_args);

#endif /* OSA_FIRMWARE_H_ */
