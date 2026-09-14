/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 - 2020 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#include "vg_lite_platform.h"
#include "vg_lite_kernel.h"
#include "vg_lite_hal.h"
#include "vg_lite_os.h"

#if !_BAREMETAL
#else
#include "xil_cache.h"
#endif

#if _BAREMETAL
/* The followings should be configured by FPGA. */
static    uint32_t    registerMemBase    = 0x43c80000;
#else
static    uint32_t    registerMemBase    = 0x40240000;
#endif

#define HEAP_NODE_USED  0xABBAF00DU

static volatile void* contiguousMem = NULL;
static uint32_t gpuMemBase = 0;

/* Default heap size is 16MB. */
static uint32_t heap_size = MAX_CONTIGUOUS_SIZE;

void vg_lite_init_mem(uint32_t register_mem_base,
          uint32_t gpu_mem_base,
          volatile void * contiguous_mem_base,
          uint32_t contiguous_mem_size)
{
    registerMemBase = register_mem_base;
    gpuMemBase      = gpu_mem_base;
    contiguousMem   = contiguous_mem_base;
    heap_size       = contiguous_mem_size;
}

/* Implementation of list. ****************************************/
typedef struct list_head {
    struct list_head *next;
    struct list_head *prev;
}list_head_t;

#define INIT_LIST_HEAD(entry) \
        (entry)->next = (entry);\
        (entry)->prev = (entry);

/* Add the list item in front of "head". */
static inline void add_list(list_head_t *to_add, list_head_t *head)
{
    /* Link the new item. */
    to_add->next = head;
    to_add->prev = head->prev;

  /* Modify the neighbor. */
    head->prev = to_add;
    if (to_add->prev != NULL) {
        to_add->prev->next = to_add;
    }
}

/* Remove an entry out of the list. */
static inline void delete_list(list_head_t *entry)
{
    if (entry->prev != NULL) {
        entry->prev->next = entry->next;
    }
    if (entry->next != NULL) {
        entry->next->prev = entry->prev;
    }
}

/* End of list implementation. ***********/
static inline void memset_(void *mem, unsigned char value, unsigned int size)
{
    unsigned int i;
    for (i = 0u; i < size; i++) {
        ((unsigned char*)mem)[i] = value;
    }
}

typedef struct heap_node {
    list_head_t list; /* TODO: Linux specific, needs to rewrite. */
    uint32_t offset;
    unsigned long size;
    uint32_t status;
}heap_node_t;

struct memory_heap {
    uint32_t free;
    list_head_t list;
};

struct mapped_memory {
    void * logical;
    uint32_t physical;
    int page_count;
    struct page ** pages;
};

struct vg_lite_device {
    /* void * gpu; */
    uint32_t gpu;    /* Always use physical for register access in RTOS. */
    /* struct page * pages; */
    volatile void * contiguous;
    unsigned int order;
    unsigned int heap_size;
    void * virtual;
    uint32_t physical;
    uint32_t size;
    struct memory_heap heap;
    int irq_enabled;
    void * device;
    int registered;
    int major;
    struct class * class;
    int created;
};

struct client_data {
    struct vg_lite_device * device;
    struct vm_area_struct * vm;
    void * contiguous_mapped;
};

static struct vg_lite_device *device;

void vg_lite_hal_delay(uint32_t milliseconds)
{
    vg_lite_os_sleep(milliseconds);
}

void vg_lite_hal_barrier(void)
{
     /*Memory barrier. */
#if _BAREMETAL
     Xil_DCacheFlush();
#else
    __asm("DSB");
#endif
}

static int vg_lite_init(void);
vg_lite_error_t vg_lite_hal_initialize(void)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    /* TODO: Turn on the power. */
    (void)vg_lite_init();
    /* TODO: Turn on the clock. */
    error = (vg_lite_error_t)vg_lite_os_initialize();

    return error;
}

void vg_lite_hal_deinitialize(void)
{
    /* TODO: Remove clock. */
    vg_lite_os_deinitialize();
    /* TODO: Remove power. */
}

static int split_node(heap_node_t * node, unsigned long size)
{
    /* TODO: the original is linux specific list based, needs rewrite.
    */
    int ret;
    heap_node_t * split;

    /*
     * If the newly allocated object fits exactly the size of the free
     * node, there is no need to split.
     */
    if ((node->size - size) == 0u)
    {
        ret = 0;
    }
    else
    {
        /* Allocate a new node. */
        split = (heap_node_t *)vg_lite_os_malloc(sizeof(heap_node_t));
        if (split == NULL)
        {
            ret = -1;
        }
        else
        {
            /* Fill in the data of this node of the remaning size. */
            split->offset = node->offset + size;
            split->size = node->size - size;
            split->status = 0;

            /* Add the new node behind the current node. */
            add_list(&split->list, &node->list);

            /* Adjust the size of the current node. */
            node->size = size;
            ret = 0;
        }
    }
    
    return ret;
}

vg_lite_error_t vg_lite_hal_allocate_contiguous(unsigned long size, void ** logical, uint32_t * physical,void ** node)
{
    unsigned long aligned_size;
    heap_node_t * pos;
    vg_lite_error_t ret = VG_LITE_OUT_OF_MEMORY;

    /* Align the size to 64 bytes. */
    aligned_size = (size + 63u) & (~(63u));

    /* Check if there is enough free memory available. */
    if (aligned_size <= device->heap.free)
    {
        /* Walk the heap backwards. */
        for (pos = (heap_node_t*)device->heap.list.prev;
                     &pos->list != &device->heap.list;
                     pos = (heap_node_t*) pos->list.prev) 
        {
            /* Check if the current node is free and is big enough. */
            if ((pos->status == 0u) && (pos->size >= aligned_size)) 
            {
                /* See if we the current node is big enough to split. */
                if (0 != split_node(pos, aligned_size))
                {
                    ret = VG_LITE_OUT_OF_RESOURCES;
                    break;
                }
                else
                {
                    /* Mark the current node as used. */
                    pos->status = HEAP_NODE_USED;

                    /*  Return the logical/physical address. */
                    /* *logical = (uint8_t *) private_data->contiguous_mapped + pos->offset; */
                    *logical = (uint8_t *)device->virtual + pos->offset;
                    *physical = gpuMemBase + (uint32_t)(*logical);/* device->physical + pos->offset; */
                    device->heap.free -= aligned_size;

                    *node = pos;
                    ret = VG_LITE_SUCCESS;
                    break;
                }
            }           
        }
    }
    return ret;
}

void vg_lite_hal_free_contiguous(void * memory_handle)
{
    /* TODO: no list available in RTOS. */
    heap_node_t * pos, * node;

    /* Get pointer to node. */
    node = memory_handle;

    if (node->status == HEAP_NODE_USED) 
    {
        /* Mark node as free. */
        node->status = 0u;

        /* Add node size to free count. */
        device->heap.free += node->size;

        /* Check if next node is free. */
        pos = node;
        pos = (heap_node_t *)pos->list.next;
        if (&pos->list != &device->heap.list) 
        {
            if (pos->status == 0u) 
            {
                /* Merge the nodes. */
                node->size += pos->size;
                if(node->offset > pos->offset)
                {
                    node->offset = pos->offset;
                }
                /* Delete the next node from the list. */
                delete_list(&pos->list);
                vg_lite_os_free(pos);
            }
        }

        /* Check if the previous node is free. */
        pos = node;
        pos = (heap_node_t *)pos->list.prev;
        if (&pos->list != &device->heap.list) 
        {
            if (pos->status == 0u) 
            {
                /* Merge the nodes. */
                pos->size += node->size;
                if(pos->offset > node->offset)
                {
                    pos->offset = node->offset;
                }
                /* Delete the current node from the list. */
                delete_list(&node->list);
                vg_lite_os_free(node);
            }
        }
        
        /* when release command buffer node and ts buffer node to exit,release the linked list*/
        if(device->heap.list.next == device->heap.list.prev) {
            delete_list(&pos->list);
            vg_lite_os_free(pos);
        }
    }
}

void vg_lite_hal_free_os_heap(void)
{
    struct heap_node    *pos, *n;

    /* Check for valid device. */
    if (device != NULL) {
        /* Process each node. */
        for (pos = (heap_node_t *)device->heap.list.next,
             n = (heap_node_t *)pos->list.next;
             &pos->list != &device->heap.list;
             pos = n, n = (heap_node_t *)n->list.next) {
                /* Remove it from the linked list. */
                delete_list(&pos->list);
                /* Free up the memory. */
                vg_lite_os_free(pos);
        }
    }
}

/* Portable: read register value. */
uint32_t vg_lite_hal_peek(uint32_t address)
{
    /* Read data from the GPU register. */
    return (uint32_t) (*(volatile uint32_t *) (device->gpu + address));
}

/* Portable: write register. */
void vg_lite_hal_poke(uint32_t address, uint32_t data)
{
    /* Write data to the GPU register. */
    uint32_t *LocalAddr = (uint32_t *)(device->gpu + address);
    *LocalAddr = data;
}

vg_lite_error_t vg_lite_hal_query_mem(vg_lite_kernel_mem_t *mem)
{
    vg_lite_error_t ret;
    
    if(device != NULL)
    {
        mem->bytes  = device->heap.free;
        ret = VG_LITE_SUCCESS;
    }
    else
    {
        mem->bytes = 0;
        ret = VG_LITE_NO_CONTEXT;
    }
    
    return ret;
}

void vg_lite_IRQHandler(void)
{
    vg_lite_os_IRQHandler();
}

int32_t vg_lite_hal_wait_interrupt(uint32_t timeout, uint32_t mask, uint32_t * value)
{
    return (int32_t)vg_lite_os_wait_interrupt(timeout,mask,value);
}

void * vg_lite_hal_map(unsigned long size, void * logical, uint32_t physical, uint32_t * gpu)
{

    (void) size;
    (void) logical;
    (void) physical;
    (void) gpu;
    return (void *)0;
}

void vg_lite_hal_unmap(void * memory_handle)
{

    (void) memory_handle;
}

vg_lite_error_t vg_lite_hal_submit(uint32_t physical, uint32_t offset, uint32_t size, vg_lite_os_async_event_t *event)
{
    return (vg_lite_error_t)vg_lite_os_submit(physical,offset,size,event);
}

vg_lite_error_t vg_lite_hal_wait(uint32_t timeout, vg_lite_os_async_event_t *event)
{
    return (vg_lite_error_t)vg_lite_os_wait(timeout,event);
}

static void vg_lite_exit(void)
{
    heap_node_t * pos;
    heap_node_t * n;

    /* Check for valid device. */
    if (device != NULL) {
        /* TODO: unmap register mem should be unnecessary. */
        device->gpu = 0;

        /* Process each node. */
        for (pos = (heap_node_t *)device->heap.list.next, n = (heap_node_t *)pos->list.next;
             &pos->list != &device->heap.list;
             pos = n, n = (heap_node_t *)n->list.next) {
            /* Remove it from the linked list. */
            delete_list(&pos->list);

            /* Free up the memory. */
            vg_lite_os_free(pos);
        }

        /* Free up the device structure. */
        vg_lite_os_free(device);
    }
}

static int vg_lite_init(void)
{
    int ret;
    heap_node_t * node;
    static struct vg_lite_device Device;

    /* Initialize memory and objects ***************************************/
    /* Create device structure. */
    device = &Device;

    /* Zero out the enture structure. */
    memset_(device, 0, sizeof(struct vg_lite_device));

    /* Setup register memory. **********************************************/
    device->gpu = registerMemBase;

    /* Initialize contiguous memory. ***************************************/
    /* Allocate the contiguous memory. */
    device->heap_size = heap_size;
    device->contiguous = (volatile void *)contiguousMem;
    memset_((void *)device->contiguous, 0, heap_size);
    /* Make 64byte aligned. */
    while ((((uint32_t)device->contiguous) & 63u) != 0u)
    {
        device->contiguous = ((unsigned char*) device->contiguous) + 4;
        device->heap_size -= 4u;
    }

    /* Check if we allocated any contiguous memory or not. */
    if (device->contiguous == NULL) 
    {
        vg_lite_exit();
        ret = -1;
    }
    else
    {

        device->virtual = (void *)device->contiguous;
        device->physical = gpuMemBase + (uint32_t)device->virtual;
        device->size = device->heap_size;

        /* Create the heap. */
        INIT_LIST_HEAD(&device->heap.list);
        device->heap.free = device->size;

        node = (heap_node_t *)vg_lite_os_malloc(sizeof(heap_node_t));
        if (node == NULL) 
        {
            vg_lite_exit();
            ret = -1;
        }
        else 
        {
            node->offset = 0;
            node->size = device->size;
            node->status = 0;
            add_list(&node->list, &device->heap.list);
            /* Success. */
            ret = 0;
        }
    }
    return ret;
}
