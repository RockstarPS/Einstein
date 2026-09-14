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

#ifndef OSA_TASK_H_
#define OSA_TASK_H_

#include "osa_types.h"

enum task_priority {
    OSA_INTERRUPT_TASK_PRIORITY,
    OSA_VXD_WORKER_TASK_PRIORITY,
    OSA_STREAM_WORKER_TASK_PRIORITY
};

typedef struct task_params_s
{
    uint8 *name;                    /*!< Name of the task instance.                  */
    enum task_priority priority;    /*!< The priority of the task                    */
    uint32 stacksize;               /*!< The stack size of the task                  */
    void *arg0;                     /*!< arg0                                        */
    void *arg1;                     /*!< arg1                                        */
    void *stack;                    /*!< pointer to stack memory, if NULL OS will allocate internally */
} task_params;

/*!
 *  @brief  Function to create a task.
 *
 *  @param  taskfxn  Function pointer of the task.
 *
 *  @param  params  Pointer to the instance configuration parameters.
 *
 *  @return A handler on success or a NULL on an error
 */
void *osa_task_create(void *taskfxn, task_params *params);

/*!
 *  @brief  Function to delete a task.
 *
 *  @param  handle  A handle returned from osa_task_create
 *
 *  @return Status of the functions
 *    - 0: Deleted the task instance
 *    - -ve value: Failed to delete the task instance
 */
int32 osa_task_delete(void *handle);

/*!
 *  @brief  Function for Task sleep in units ms-second
 *
 *  @param timeout  sleep ticks.
 */
void osa_task_sleep(uint32 timeout);

#endif /* OSA_TASK_H_ */
