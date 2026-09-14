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
 * This component is used to track decoder resources,
 * and share them across other components.
 */

#ifndef __RMAN_API_H__
#define __RMAN_API_H__

#include "osal/inc/osa_types.h"
#include "img_errors.h"
#include "lst.h"

#define	RMAN_ALL_TYPES		(0xFFFFFFFF)
#define	RMAN_TYPE_P1		(0xFFFFFFFE)
#define	RMAN_TYPE_P2		(0xFFFFFFFE)
#define	RMAN_TYPE_P3		(0xFFFFFFFE)
#define RMAN_STICKY		(0xFFFFFFFD)

int32 rman_initialise(void);

void rman_deinitialise(void);

int32 rman_create_bucket(void **res_handle);

void rman_destroy_bucket(void *res_handle);

void *rman_get_global_bucket(void);

typedef void (*rman_fn_free) (void *param);

int32 rman_register_resource(void *res_handle, uint32 type_id, rman_fn_free fn_free,
			   void *param, void **res_handle_ptr,
			   uint32 *res_id);

typedef int32 (*rman_fn_alloc) (void *alloc_info, void **param);

int32 rman_get_named_resource(uint8 *res_name, rman_fn_alloc fn_alloc,
			    void *alloc_info, void *res_bucket_handle,
			    uint32 type_id, rman_fn_free fn_free,
			    void **param, void **res_handle, uint32 *res_id);

uint32 rman_get_resource_id(void *res_handle);

int32 rman_get_resource(uint32 res_id, uint32 type_id, void **param,
		      void **res_handle);

void rman_free_resource(void *res_handle);

void rman_lock_resource(void *res_handle);

void rman_unlock_resource(void *res_hanle);

void rman_free_resources(void *res_bucket_handle, uint32 type_id);

#endif
