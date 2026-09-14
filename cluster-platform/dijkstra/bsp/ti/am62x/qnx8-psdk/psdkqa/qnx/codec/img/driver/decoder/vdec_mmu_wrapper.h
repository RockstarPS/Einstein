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
 * VDEC MMU Functions
 */

#include "osal/inc/osa_define.h"
#include "img_errors.h"
#include "img_mem.h"
#include "lst.h"
#include "mmu_defs.h"
#include "vid_buf.h"

#ifndef _VXD_MMU_H_
#define _VXD_MMU_H_

/* Page size of the device MMU */
#define DEV_MMU_PAGE_SIZE (0x1000)
/* Page alignment of the device MMU */
#define DEV_MMU_PAGE_ALIGNMENT  (0x1000)

#define HOST_MMU_PAGE_SIZE OSA_PAGE_SIZE

/*
 * @Function	mmu_stream_get_ptd_handle
 * @Description
 * This function is used to obtain the stream PTD (Page Table Directory)handle
 * @Input	mmu_str_handle : MMU stream handle.
 * @Output	str_ptd : Pointer to stream PTD handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_get_ptd_handle(void *mmu_str_handle,
			      void **str_ptd);

/*
 * @Function	mmu_device_create
 * @Description
 * This function is used to create and initialise the MMU device context.
 * @Input	mmu_type : MMU type.
 * @Input	ptd_alignment : Alignment of Page Table directory.
 * @Output	mmudev_hndl : A pointer used to return the
 *		MMU device handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_device_create(enum mmu_etype mmu_type,
		      uint32 ptd_alignment,
		      void **mmudev_hndl);

/*
 * @Function	mmu_device_destroy
 * @Description
 * This function is used to create and initialise the MMU device context.
 * NOTE: Destroy device automatically destroys any streams and frees and
 * memory allocated using MMU_StreamMalloc().
 * @Input	mmudev_hndl : The MMU device handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_device_destroy(void *mmudev_hndl);

/*
 * @Function	mmu_stream_create
 * @Description
 * This function is used to create and initialise the MMU stream context.
 * @Input	mmudev_hndl : The MMU device handle.
 * @Input	km_str_id : Stream Id used in communication with KM driver.
 * @Output	mmustr_hndl : A pointer used to return the MMU stream handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_create(void *mmudev_hndl,
		      uint32 km_str_id,
		      void *vxd_dec_ctx,
		      void **mmustr_hndl);

/*
 * @Function	mmu_stream_destroy
 * @Description
 * This function is used to create and initialise the MMU stream context.
 * NOTE: Destroy automatically frees and memory allocated using
 *	mmu_stream_malloc().
 * @Input	mmustr_hndl : The MMU stream handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_destroy(void *mmustr_hndl);

/*
 * @Function	mmu_stream_alloc
 * @Description
 * This function is used to allocate stream memory.
 * @Input	mmustr_hndl : The MMU stream handle.
 * @Input	heap_id : The MMU heap Id.
 * @Input	mem_heap_id : Memory heap id
 * @Input	mem_attrib : Memory attributes
 * @Input	size : The size, in bytes, to be allocated.
 * @Input	alignment : The required byte alignment
 *		(1, 2, 4, 8, 16 etc).
 * @Output	ddbuf_info : A pointer to a #vidio_ddbufinfo structure
 *		used to return the buffer info.
 * @Return	IMG_SUCCESS or an error code.
 */
int32  mmu_stream_alloc(void *mmustr_hndl,
		      enum mmu_eheap_id heap_id,
		      uint32 mem_heap_id,
		      enum sys_emem_attrib mem_attrib,
		      uint32 size,
		      uint32 alignment,
		      struct vidio_ddbufinfo *ddbuf_info);

/*
 * @Function	mmu_stream_map_ext
 * @Description
 * This function is used to malloc device memory (virtual memory), but mapping
 * this to memory that has already been allocated (externally).
 * NOTE: Memory can be freed using MMU_Free().  However, this does not
 *	free the memory provided by the caller via pvCpuLinearAddr.
 * @Input	mmustr_hndl    : The MMU stream handle.
 * @Input	heap_id : The heap Id.
 * @Input	buff_id : The buffer Id.
 * @Input	size : The size, in bytes, to be allocated.
 * @Input	alignment : The required byte alignment (1, 2, 4, 8, 16 etc).
 * @Input	mem_attrib : Memory attributes
 * @Input	cpu_linear_addr : CPU linear address of the memory
 *		to be allocated for the device.
 * @Output	ddbuf_info : A pointer to a #vidio_ddbufinfo structure
 *		used to return the buffer info.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_map_ext(void *mmustr_hndl,
		       enum mmu_eheap_id heap_id,
		       uint32 buff_id,
		       uint32 size,
		       uint32 alignment,
		       enum sys_emem_attrib mem_attrib,
		       void *cpu_linear_addr,
		       struct vidio_ddbufinfo *ddbuf_info);

int32 mmu_stream_map_ext_sg(void *mmustr_hndl,
			  enum mmu_eheap_id heap_id,
			  void *sgt,
			  uint32 size,
			  uint32 alignment,
			  enum sys_emem_attrib mem_attrib,
			  void *cpu_linear_addr,
			  struct vidio_ddbufinfo *ddbuf_info,
			  uint32 *buff_id);

/*
 * @Function	mmu_free_mem
 * @Description
 * This function is used to free device memory.
 * @Input	ps_dd_buf_info : A pointer to a #vidio_ddbufinfo structure.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_free_mem(void *mmustr_hndl,
		 struct vidio_ddbufinfo *ddbuf_info
);

/*
 * @Function	mmu_free_mem
 * @Description
 * This function is used to free device memory.
 * @Input	ps_dd_buf_info : A pointer to a #vidio_ddbufinfo structure.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_free_mem_sg(void *mmustr_hndl,
		    struct vidio_ddbufinfo *ddbuf_info);

int32 mmu_get_heap(uint32 image_stride, enum mmu_eheap_id *heap_id);

#endif /* _VXD_MMU_H_ */
