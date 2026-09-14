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
 * osa memory management defintions
 */

#ifndef OSA_MEM_H_
#define OSA_MEM_H_

#include "osa_types.h"

#define osa_container_of(ptr, type, member)     (type *)((int8 *)ptr - ((size_t)&(((type *)0)->member)))
#define OSA_ALIGN(x, a, type)                   (((x) + ((type)(a) - 1)) & ~((type)(a) - 1))

#ifdef DEBUG_OSA_MEM
struct memory_release {
    uint8 flag;
    void *ptr;
    uint8 func[200];
    uint32 line;
    uint32 size;
};
void osa_print_mem_leak(void);
#endif

/**
 * osa_calloc - allocate memory for an array. The memory is set to zero.
 * @n: number of elements.
 * @size: element size.
 * @flags: the type of memory to allocate (see osa_malloc).
 */
#ifdef DEBUG_OSA_MEM
#define osa_calloc(a,b,c) osa_calloc_debug(a,b,c,__func__,__LINE__)
void *osa_calloc_debug(uint64 n, uint64 size, int64 flags, const uint8 *func, uint32 line);
#else
void *osa_calloc(uint64 n, uint64 size, int64 flags);
#endif

/**
 * osa_malloc - allocate memory
 * @size: how many bytes of memory are required.
 * @flags: the type of memory to allocate.
 *
 * osa_malloc is the normal method of allocating memory
 * for objects smaller than page size in the kernel.
 *
 * The @flags argument may be one of:
 *
 * %OSA_GFP_USER - Allocate memory on behalf of user.  May sleep.
 *
 * %OSA_GFP_KERNEL - Allocate normal kernel ram.  May sleep.
 *
 * %OSA_GFP_ATOMIC - Allocation will not sleep.  May use emergency pools.
 *   For example, use this inside interrupt handlers.
 *
 * %OSA_GFP_HIGHUSER - Allocate pages from high memory.
 *
 * %OSA_GFP_NOIO - Do not do any I/O at all while trying to get memory.
 *
 * %OSA_GFP_NOFS - Do not make any fs calls while trying to get memory.
 *
 * %OSA_GFP_NOWAIT - Allocation will not sleep.
 *
 * %OSA_GFP_DMA - Allocation suitable for DMA.
 *   Should only be used for osa_malloc() caches.
 */
#ifdef DEBUG_OSA_MEM
#define osa_malloc(a,b) osa_malloc_debug(a,b,__func__,__LINE__)
void *osa_malloc_debug(uint64 size, int64 flags, const uint8 *func, uint32 line);
#else
void *osa_malloc(uint64 size, int64 flags);
#endif

/**
 * osa_realloc - reallocate memory. The contents will remain unchanged.
 * @p: object to reallocate memory for.
 * @new_size: how many bytes of memory are required.
 * @flags: the type of memory to allocate.
 *
 * The contents of the object pointed to are preserved up to the
 * lesser of the new and old sizes.  If @p is %NULL, osa_realloc()
 * behaves exactly like osa_malloc().  If @new_size is 0 and @p is not a
 * %NULL pointer, the object pointed to is freed.
 */
void *osa_realloc(const void *p, uint64 new_size, int64 flags);

/**
 * osa_free - free previously allocated memory
 * @objp: pointer returned by osa_malloc.
 *
 * If @objp is NULL, no operation is performed.
 *
 * Don't free memory not originally allocated by osa_malloc()
 * or you will run into trouble.
 */
#ifdef DEBUG_OSA_MEM
#define osa_free(a) osa_free_debug(a, __func__, __LINE__)
void osa_free_debug(const void *objp, const uint8 *func, uint32 line);
#else
void osa_free(const void *objp);
#endif

/**
 * osa_zalloc - allocate memory. The memory is set to zero.
 * @size: how many bytes of memory are required.
 * @flags: the type of memory to allocate (see osa_malloc).
 */
#ifdef DEBUG_OSA_MEM
#define osa_zalloc(a,b) osa_zalloc_debug(a,b,__func__,__LINE__)
void *osa_zalloc_debug(uint64 size, int64 flags, const uint8 *func, uint32 line);
#else
void *osa_zalloc(uint64 size, int64 flags);
#endif

/**
 * osa_malloc_array - allocate memory for an array.
 * @n: number of elements.
 * @size: element size.
 * @flags: the type of memory to allocate (see osa_malloc).
 */
#ifdef DEBUG_OSA_MEM
#define osa_malloc_array(a,b,c) osa_malloc_array_debug(a,b,c,__func__,__LINE__)
void *osa_malloc_array_debug(size_t n, size_t size, int64 flags, const uint8 *func, uint32 line);
#else
void *osa_malloc_array(size_t n, size_t size, int64 flags);
#endif

/**
 * osa_strdup -  allocate space and copy an existing string.
 * @s: The string to duplicate 
 * @flags: the type of memory to allocate (see osa_malloc).
 */
#ifdef DEBUG_OSA_MEM
#define osa_strdup(a,b) osa_strdup_debug(a,b,__func__,__LINE__)
int8 *osa_strdup_debug(const int8 *s, int64 flags, const uint8 *func, uint32 line);
#else
int8 *osa_strdup(const int8 *s, int64 flags);
#endif

/**
 * osa_memdup - duplicate region of memory
 *
 * @src: memory region to duplicate
 * @len: memory region length
 * @gfp: mask to use
 */
#ifdef DEBUG_OSA_MEM
#define osa_memdup(a,b,c) osa_memdup_debug(a,b,c,__func__,__LINE__)
void *osa_memdup_debug(const void *src, size_t len, int64 flags, const uint8 *func, uint32 line);
#else
void *osa_memdup(const void *src, size_t len, int64 flags);
#endif

/**
 *  osa_vmap  -  map an array of pages into virtually contiguous space
 *  @pages:     array of page pointers
 *  @count:     number of pages to map
 *  @flags:     vm_area->flags
 *  @prot:      page protection for the mapping
 *
 *  Maps @count pages from @pages into contiguous kernel virtual
 *  space.
 */
void *osa_vmap(void **pages, uint32 count);

/**
 *  osa_vunmap  -  release virtual mapping obtained by osa_vmap()
 *  @addr:      memory base address
 *
 *  Free the virtually contiguous memory area starting at @addr,
 *  which was created from the page array passed to osa_vmap().
 *
 *  Must not be called in interrupt context.
 */
void osa_vunmap(const void *addr);

#endif /* OSA_MEM_H_ */
