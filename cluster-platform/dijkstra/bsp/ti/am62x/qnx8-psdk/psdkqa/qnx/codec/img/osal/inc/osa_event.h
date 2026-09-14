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
 * osa event definitions
 *
 * Copyright (c) Imagination Technologies Ltd.
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef OSA_EVENT_H_
#define OSA_EVENT_H_

#include "osa_types.h"

/**
 * osa_create_event_obj - allocate and init the event
 *
 * @event: Pointer to event object
 *
 * Allocate and initialize the event object.
 * Returns error if fails to allocate.
 */
int32 osa_create_event_obj(void ** event);


/**
 * osa_destroy_event_obj - destroy and free the event
 * @event: event object to destroy
 *
 * This function frees the event object.
 */
void osa_destroy_event_obj(void * event);


/**
 * osa_signal_event_obj - signals the event object
 * @event: event object
 *
 * Signals the event object specified.
 */
void osa_signal_event_obj(void *event);


/**
 * osa_wait_event_obj - wait on the event object
 * @event: event object
 * @uninterruptible: flag to indicate if wait should be interruptible
 * @timeout: timeout to wait for event
 *
 * Waits for the event. If uninterruptible is set to false, then the
 * call is interruptible.
 * Returns IMG_SUCCESS when event is signalled.
 * Returns IMG_ERROR_INTERRUPTED if it is interrupted.
 */
int32 osa_wait_event_obj(void *event, osa_bool uninterruptible, uint32 timeout);

#endif /* OSA_EVENT_H_ */
