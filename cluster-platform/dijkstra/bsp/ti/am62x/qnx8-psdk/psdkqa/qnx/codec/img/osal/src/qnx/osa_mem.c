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
 * osa memory handling functions implementation for QNX
 */

#include <stdlib.h>
#include <string.h>

#include "../../inc/osa_mem.h"
#include "../../inc/osa_define.h"

#ifdef DEBUG_OSA_MEM
DEFINE_MUTEX(lock);
#define MAX_NUM_RESOURCES 5000
static struct memory_release resource[MAX_NUM_RESOURCES] = {0};
static uint32 count = 0;

void osa_save_mem(void *ptr, uint32 size, const uint8 *func, uint32 line)
{
    uint32 i = 0;

    mutex_lock(&lock);
    for (i = 0; i < MAX_NUM_RESOURCES; i++) {
        if (0 == resource[i].flag) {
            resource[i].flag = 1;
            strcpy(resource[i].func, func);
            resource[i].line = line;
            resource[i].ptr = ptr;
            resource[i].size = size;
            count++;
            mutex_unlock(&lock);
            return;
        }
    }
    mutex_unlock(&lock);
    OSA_PR_ERR("##### NO MEMORY #######\n");
}

void osa_remove_mem(void *ptr, const uint8 *func, uint32 line)
{
    uint32 i = 0;

    mutex_lock(&lock);
    for (i = 0; i < MAX_NUM_RESOURCES; i++) {
        if (1 == resource[i].flag) {
            if (ptr == resource[i].ptr) {
                resource[i].flag = 0;
                count--;
                mutex_unlock(&lock);
                return;
            }
        }
    }
    mutex_unlock(&lock);
    OSA_PR_ERR("##### INVALID ADDRESS ####### [0x%llx] function_name = %s line_no = %d\n",
               (uint64)ptr, func, line);
}

void osa_print_mem_leak()
{
    uint32 i = 0;

    OSA_PR_ERR("##### printing %d outstanding allocations #####\n", count);
    for (i = 0; i < MAX_NUM_RESOURCES; i++) {
        if (1 == resource[i].flag) {
            OSA_PR_ERR("function_name = %s, line_no = %d, ptr = 0x%llx, size = %d\n",
                       resource[i].func, resource[i].line, (uint64)resource[i].ptr,
                       resource[i].size);
        }
    }
}
#endif

#ifdef DEBUG_OSA_MEM
void *osa_calloc_debug(uint64 n, uint64 size, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_calloc(uint64 n, uint64 size, int64 flags)
#endif
{
    void *data = NULL;
    data = calloc(n, size);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, size * n, func, line);
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
void *osa_malloc_debug(uint64 size, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_malloc(uint64 size, int64 flags)
#endif
{
    void *data = NULL;
    data = malloc(size);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, size, func, line);
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
void *osa_realloc(const void *p, uint64 new_size, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_realloc(const void *p, uint64 new_size, int64 flags)
{
#endif
    void *data = NULL;
    data = realloc((void *)p, new_size);
#ifdef DEBUG_OSA_MEM
    if(data) {
        osa_remove_mem(p, func, line);
        osa_save_mem(data, new_size, func, line);
    }
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
void osa_free_debug(const void *objp, const uint8 *func, uint32 line)
#else
void osa_free(const void *objp)
#endif
{
#ifdef DEBUG_OSA_MEM
    osa_remove_mem((void *)objp, func, line);
#endif
    return free((void *)objp);
}

#ifdef DEBUG_OSA_MEM
void *osa_zalloc_debug(uint64 size, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_zalloc(uint64 size, int64 flags)
#endif
{
    void *data = NULL;
    data = malloc(size);
    if(data != NULL)
        memset(data, 0x0, size);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, size, func, line);
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
void *osa_malloc_array_debug(size_t n, size_t size, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_malloc_array(size_t n, size_t size, int64 flags)
#endif
{
    void *data = NULL;
    data = calloc(n, size);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, n * size, func, line);
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
int8 *osa_strdup_debug(const int8 *s, int64 flags, const uint8 *func, uint32 line)
#else
int8 *osa_strdup(const int8 *s, int64 flags)
#endif
{
    void *data = NULL;
    data = strdup((char *)s);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, strlen(s), func, line);
#endif
    return data;
}

#ifdef DEBUG_OSA_MEM
void *osa_memdup_debug(const void *src, size_t len, int64 flags, const uint8 *func, uint32 line)
#else
void *osa_memdup(const void *src, size_t len, int64 flags)
#endif
{
    void *data = NULL;
    data = malloc(len);
    if(data != NULL)
        memcpy(data, src, len);
#ifdef DEBUG_OSA_MEM
    osa_save_mem(data, len, func, line);
#endif
    return data;
}

void *osa_vmap(void **pages, uint32 count)
{
    struct page *page = (struct page *)*pages;

    return (page->sgt->sgl->dma_address);
}

void osa_vunmap(const void *addr)
{
}
