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
 * IMG DEC Memory Manager header file
 */

#ifndef _IMG_DEC_MEM_MGR_H
#define _IMG_DEC_MEM_MGR_H

#include "osal/inc/osa_list.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_mutex.h"

/* buffer ids (per memory context) */
#define MEM_MAN_MIN_BUFFER 1
#define MEM_MAN_MAX_BUFFER 16384

enum mem_attr {
	MEM_ATTR_CACHED        = 0x00000001,
	MEM_ATTR_UNCACHED      = 0x00000002,
	MEM_ATTR_WRITECOMBINE  = 0x00000004,
	MEM_ATTR_SECURE        = 0x00000010,
	MEM_ATTR_FORCE32BITS = 0x7FFFFFFFU
};

enum mmu_callback_type {
	MMU_CALLBACK_MAP = 1,
	MMU_CALLBACK_UNMAP,
	MMU_CALLBACK_FORCE32BITS = 0x7FFFFFFFU
};

enum heap_type {
	MEM_HEAP_TYPE_UNIFIED = 1,
	MEM_HEAP_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

union heap_options {
	struct {
		int64 gfp_type; /* pool and flags for buffer allocations */
	} unified;
};

/*
 * struct heap_config - contains heap configuration structure
 * @type: enumeration of heap_type
 * @options: pool and flags for buffer allocations, eg OSA_GFP_KERNEL
 * @to_dev_addr: function pointer for retrieving device addr
 */
struct heap_config {
	enum heap_type type;
	union heap_options options;
	uint64 (*to_dev_addr)(union heap_options *opts, uint64 addr);
};

/*
 * struct mmu_heap - typedef for mmu_heap
 * @virt_addr_start: start of the device virtual address
 * @alloc_atom: atom allocation in bytes
 * @size: total size of the heap in bytes
 */
struct mmu_heap {
	uintptr_t virt_addr_start;
	size_t alloc_atom;
	size_t size;
};

/*
 * struct mem_ctx - the memory context
 * @buffers: idr list of buffers
 * @mmu_ctxs: contains linked lists of struct mmu_ctx
 * @mem_man_entry: the entry list for dev_mem_main:mem_ctxs linked list
 */
struct mem_ctx {
	void *buffers;
	struct clist_head mmu_ctxs;
	struct clist_head mem_man_entry;
};

/*
 * struct mmu_ctx_mapping - the mmu context mapping information
 * @mmu_ctx: pointer to the mmu_ctx to which this mmu mapping information
 *	     belongs
 * @buffer: pointer to the buffer which this mmu_ctx_mapping is for
 * @map: pointer to the mmu_map which this mmu_ctx_mapping belongs
 * @virt_addr: Virtual address
 * @mmu_ctx_entry: the entry list for mmu_ctx:mapping linked list.
 * @buffer_entry: the entry list for buffer:mappings linked list.
 */
struct mmu_ctx_mapping {
	struct mmu_ctx *mmu_ctx;
	struct buffer *buffer;
	struct mmu_map *map;
	uint32 virt_addr;
	struct clist_head mmu_ctx_entry;
	struct clist_head buffer_entry;
};

/*
 * struct mmu_ctx - the mmu context information - one per stream
 * @device: pointer to the device
 * @mmu_config_addr_width: the address width for the mmu config
 * @mem_ctx: pointer to mem_ctx where this mmu_ctx belongs to
 * @heap: pointer to struct heap to where this mem_ctx belongs to
 * @mmu_dir: pointer to the mmu_directory this mmu_ctx belongs to
 * @mappings: contains linked list of struct mmu_ctx_mapping
 * @mem_ctx_entry: the entry list for mem_ctx:mmu_ctxs
 * @callback_fn: pointer to function callback
 * @callback_data: pointer to the callback data
 */
struct mmu_ctx {
	void *device;
	uint32 mmu_config_addr_width;
	struct mem_ctx *mem_ctx;
	struct heap *heap;
	struct mmu_directory *mmu_dir;
	struct clist_head mappings;
	struct clist_head mem_ctx_entry;
	void (*callback_fn)(enum mmu_callback_type type, int32 buff_id,
			    void *data);
	void *callback_data;
};

/*
 * struct buffer - the mmu context information - one per stream
 * @id: buffer identification
 * @request_size: request size for the allocation
 * @actual_size: size aligned with the OSA_PAGE_SIZE allocation
 * @device: pointer to the device
 * @mem_ctx: pointer to struct mem_ctx to where this buffer belongs to
 * @heap: pointer to struct heap to where this buffer belongs to
 * @mappings: contains linked lists of struct mmu_ctx_mapping
 * @kptr: pointer to virtual mapping for the buffer object into kernel address
 *	  space
 * @priv: pointer to priv data used for scaterlist table info
 */
struct buffer {
	int32 id; /* Generated in <mem_ctx:buffers> */
	size_t request_size;
	size_t actual_size;
	void *device;
	struct mem_ctx *mem_ctx;
	struct heap *heap;
	struct clist_head mappings; /* contains <struct mmu_ctx_mapping> */
	void *kptr;
	void *priv;
};

struct heap_ops {
	int32 (*alloc)(void *device, struct heap *heap,
		     size_t size, enum mem_attr attr,
		     struct buffer *buffer);
	void (*free)(struct heap *heap, struct buffer *buffer);
	int32 (*map_km)(struct heap *heap, struct buffer *buffer);
	int32 (*get_sg_table)(struct heap *heap, struct buffer *buffer,
			    void **sg_table);
	void (*sync_cpu_to_dev)(struct heap *heap, struct buffer *buffer);
	void (*sync_dev_to_cpu)(struct heap *heap, struct buffer *buffer);
	void (*destroy)(struct heap *heap);
};

struct heap {
	int32 id; /* Generated in <mem_man:heaps> */
	enum heap_type type;
	struct heap_ops *ops;
	union heap_options options;
	uint64 (*to_dev_addr)(union heap_options *opts, uint64 addr);
	void *priv;
};

int32 img_mem_init(void *dev);
void img_mem_exit(void);

int32 img_mem_create_ctx(struct mem_ctx **new_ctx);
void img_mem_destroy_ctx(struct mem_ctx *ctx);

int32 img_mem_import(void *device, struct mem_ctx *ctx,
		   size_t size, enum mem_attr attr, int32 *buf_id);

int32 img_mem_alloc(void *device, struct mem_ctx *ctx, int32 heap_id,
		  size_t size, enum mem_attr attributes, int32 *buf_id);
void img_mem_free(struct mem_ctx *ctx, int32 buff_id);

void img_mem_free_bufid(struct mem_ctx *ctx, int32 buf_id);

int32 img_mem_map_km(struct mem_ctx *ctx, int32 buf_id);
void *img_mem_get_kptr(struct mem_ctx *ctx, int32 buff_id);

int32 img_mem_sync_cpu_to_device(struct mem_ctx *ctx, int32 buf_id);
int32 img_mem_sync_device_to_cpu(struct mem_ctx *ctx, int32 buf_id);

int32 img_mmu_ctx_create(void *device, uint32 mmu_config_addr_width,
		       struct mem_ctx *mem_ctx, int32 heap_id,
		       void (*callback_fn)(enum mmu_callback_type type,
					   int32 buff_id, void *data),
		       void *callback_data, struct mmu_ctx **mmu_ctx);
void img_mmu_ctx_destroy(struct mmu_ctx *ctx);

int32 img_mmu_map(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		int32 buff_id, uint32 virt_addr, uint32 map_flags);
int32 img_mmu_map_sg(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		   int32 buff_id, void *sgt, uint32 virt_addr,
		   uint32 map_flags);
int32 img_mmu_unmap(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		  int32 buff_id);

int32 img_mmu_get_ptd(const struct mmu_ctx *ctx, uint32 *ptd);

int32 img_mmu_get_pagetable_entry(const struct mmu_ctx *ctx, uintptr_t dev_virt_addr);

int32 img_mem_add_heap(const struct heap_config *heap_cfg, int32 *heap_id);
void img_mem_del_heap(int32 heap_id);

/* Heap operation related function */
int32 img_mem_unified_init(const struct heap_config *config,
			 struct heap *heap);

#endif /* _IMG_DEC_MEM_MGR */
