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

#ifndef OSA_SEMAPHORE_H_
#define OSA_SEMAPHORE_H_

#include "osa_types.h"

/*!
 *  @brief    Mode of the semaphore
 */
enum osa_semaphore_mode {
    osa_semaphore_mode_counting = 0x0,
    osa_semaphore_mode_binary   = 0x1,
    osa_semaphore_mode_FORCE32BITS = 0x7FFFFFFFU
};

enum osa_semaphore_wait {
    osa_semaphore_no_wait,
    osa_semaphore_wait_forever = -1,
    osa_semaphore_wait_FORCE32BITS = 0x7FFFFFFFU
};

/*!
 *  @brief  Function to create a semaphore.
 *
 *  @param  mode   This should be binary semaphore or counting semaphore
 *  @param  count  Initial count of the semaphore. For binary semaphores,
 *                 only values of 0 or 1 are valid.
 *
 *  @return A Semaphore Handle on success or a NULL on an error
 */
void *osa_semaphore_create(enum osa_semaphore_mode mode, uint32 count);

/*!
 *  @brief  Function to delete a semaphore.
 *
 *  @param  handle returned from ::osa_semaphore_create
 *
 *  @return Status of the functions
 *    -0 on success.
 *    -ve value on failure.
 */
int32 osa_semaphore_delete(void *handle);

/*!
 *  @brief  Function to pend (wait) on a semaphore.
 *
 *  @param  handle returned from ::osa_semaphore_create
 *
 *  @param  timeout Timeout (in milliseconds) to wait for the semaphore to
 *                  be posted (signalled).
 *
 *  @return Status of the functions
 *    -0 on success.
 *    -ve value on failure.
 */
int32 osa_semaphore_pend(void *handle, uint32 timeout);

/*!
 *  @brief  Function to post (signal) a semaphore.
 *
 *  @param  handle returned from ::osa_semaphore_create
 *
 *  @return Status of the functions
 *    -0 on success.
 *    -ve value on failure.
 */
int32 osa_semaphore_post(void *handle);

#endif /* OSA_SEMAPHORE_H_ */
