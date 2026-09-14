/*******************************************************************************
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2016. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.

 ** file    hmi_gfx_mgr02_mem_mgmt.c
 ** brief   This memory management module is responsible for managing heap memory using a 
            first-fit algorithm. In this algorithm, the system searches for the first available memory block 
            that can accommodate the requested size. If such a block is found, it is divided 
            into two parts: one part is allocated for the requested data, and the remaining 
            part is marked as a free block. To ensure proper alignment of memory, the module 
            adds the requested size and alignment requirements and then searches for an 
            appropriate block. The portion of memory before the alignment is split, creating a
            new free block, which is then added to the list of available free blocks. Whenever
            a block of memory is freed, it is added to the beginning of the linked list of free
            blocks. This list allows for efficient management of available memory. Additionally,
            the system periodically checks for opportunities to merge adjacent free blocks to 
            optimize memory usage. 
            Embedded-headers allocator: all GFX_MGR02_BLOCK_INFO_T headers reside
            INSIDE the managed heap region. No malloc()/free() from the CRT heap
            are used in this module. Free/allocated blocks are linked by pointers
            to headers stored in-heap.
*******************************************************************************/

#define HMI_GFX_MGR02_MEM_MGMT_C

/*******************************************************************************
 Includes
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hmi_gfx_mgr02.cfg"
#include "hmi_gfx_mgr02_mem_mgmt.h"

/*******************************************************************************
 Macro Definitions
*******************************************************************************/

#ifdef GFX_MGR02_MEM_MGMT_CHECK
#define GFX_MEM_MAGIC                         0xAFFEAFFEUL
#define GFX_MEM_MAGIC_SIZE                    (4UL)
#endif

/* Number of heap areas managed in this module */
#define GFX_MGR02_MAX_HEAPS                        (1U)

/*******************************************************************************
 Data Types
*******************************************************************************/

/* block of memory in the heap */
typedef struct GFX_MGR02_BLOCK_INFO
{
    struct GFX_MGR02_BLOCK_INFO *nextBlock;     
    struct GFX_MGR02_BLOCK_INFO *prevBlock;                                   
    struct GFX_MGR02_BLOCK_INFO *nextFreeBlock; 
    struct GFX_MGR02_BLOCK_INFO *prevFreeBlock;
    UINT32 size;                   /* total size of the block (header (24 bytes) + payload) */
    UINT32 isUsed;                 /* indicates whether the block is allocated or free */
} GFX_MGR02_BLOCK_INFO_T;

/* heap area information */
typedef struct 
{
    struct GFX_MGR02_BLOCK_INFO *startBlock; /* start of complete block list */
    struct GFX_MGR02_BLOCK_INFO *freeBlockRover; /* start of free block list */
    UINT32 size;                  /* Total size of complete heap area */ 
    UINT32 totalAllocatedMem;     /* Total allocated memory */
    UINT32 totalFreeMem;          /* Total free memory */
    UINT32 totalBlockInfoMem;     /* Total reserved memory for header (block info) */
    UINT32 totalUntrackedMem;     /* Total untracked memory */
    UINT32 numFreeBlocks;         /* Number of free blocks available */
    UINT32 numAllocatedBlocks;    /* Number of allocated blocks available */
    UINT32 baseAddress;           /* Base address of heap area */
} GFX_MGR02_HEAP_INFO_T;

/*******************************************************************************
                      Global Variables
*******************************************************************************/

#ifdef GFX_MGR02_MEM_MGMT_CHECK
/* Below variable indicate whether the next word following a memory area allocated 
 * by hmi_gfx_mgr02_mem_mgmt_heap_alloc has been overwritten */
static BOOLEAN l_memory_overwritten = FALSE;
#endif /* GFX_MGR02_MEM_MGMT_CHECK */

static GFX_MGR02_HEAP_INFO_T l_heap_info_S[GFX_MGR02_MAX_HEAPS];
static UINT8 l_num_heap_created = 0U;

/*******************************************************************************
                       Function Prototypes
*******************************************************************************/

static GFX_MGR02_BLOCK_INFO_T* hmi_gfx_mgr02_get_block(void *p_addr, GFX_MGR02_HEAP_INFO_T* p_heap);
static void hmi_gfx_mgr02_insert_to_free_list(GFX_MGR02_BLOCK_INFO_T* p_block, GFX_MGR02_HEAP_INFO_T* p_heap);
static void hmi_gfx_mgr02_remove_from_free_list(GFX_MGR02_BLOCK_INFO_T* p_block, GFX_MGR02_HEAP_INFO_T* p_heap);

/*******************************************************************************
                       Function Definitions
*******************************************************************************/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_create_heap
Description          : Creates a memory heap and attach it to passed handle
Parameters           : hdlmem      Handle to the newly created heap
                       size        Size of the heap memory
                       baseAddress Physical start address of the heap memory
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_create_heap(GFX_MGR02_MEM_MGMT_HEAP_HANDLE *p_hdlmem, UINT32 p_size, UINT32 p_baseAddress)
{
    GFX_ERROR fl_ret;

    if (l_num_heap_created < GFX_MGR02_MAX_HEAPS)
    {        
        UINT32 fl_header_size = sizeof(GFX_MGR02_BLOCK_INFO_T);
        GFX_MGR02_HEAP_INFO_T* fl_heap = &l_heap_info_S[l_num_heap_created];
        
        if ((p_hdlmem == NULL) || (p_size <= fl_header_size))
        {
            #ifdef GFX02_DEBUG_INFO
            printf("create_heap: ERROR: invalid parameter(s)\r\n");
            #endif
            fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
        }
        else
        {
            fl_heap->size = p_size;
            fl_heap->numFreeBlocks = 1U;
            fl_heap->numAllocatedBlocks = 0U;
            fl_heap->baseAddress = p_baseAddress;
            fl_heap->startBlock = (GFX_MGR02_BLOCK_INFO_T*)p_baseAddress;
            
            if (fl_heap->startBlock == NULL)
            {
                fl_ret = GFX_MM_ERR_INVALID_MEMORY;
            }
            else
            {
                /* Start block will points to the start of the heap
                 * Initially, Start block is updated as whole heap region */
                fl_heap->startBlock->nextBlock      = NULL;
                fl_heap->startBlock->prevBlock      = NULL;
                fl_heap->startBlock->size           = p_size;
                fl_heap->startBlock->isUsed         = 0U;
                fl_heap->startBlock->nextFreeBlock  = NULL;
                fl_heap->startBlock->prevFreeBlock  = NULL;
                fl_heap->freeBlockRover             = fl_heap->startBlock;
                fl_heap->totalBlockInfoMem          = fl_header_size;
                fl_heap->totalAllocatedMem          = 0U;
                fl_heap->totalFreeMem               = p_size - fl_header_size;
                fl_heap->totalUntrackedMem          = 0U;
                *p_hdlmem                           = (GFX_MGR02_MEM_MGMT_HEAP_HANDLE)fl_heap;
                l_num_heap_created++;
                fl_ret = GFX_OK;
            }
        }
    }
    else
    {
        fl_ret = GFX_MM_ERR_MAX_HEAP_CREATED;
    }
    
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_destroy_heap
Description          : Destroys a heap object associated with passed handle
Parameters           : hdlmem  Handle to heap
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_destroy_heap(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem)
{
    /* Destroy Heap is dummy call, No action required here */
    
    GFX_ERROR fl_ret = GFX_OK;
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;

    if (fl_heap == NULL)
    {
        #ifdef GFX02_DEBUG_INFO
        printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_destroy_heap: ERROR: p_hdlmem == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    }
    else
    {
        if (l_num_heap_created > 0U)
        {
            l_num_heap_created--;
        }
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_heap_alloc
Description          : Allocates a block of memory from the specified heap.
Parameters           : hdlmem     Heap to perform the allocation from
                       size       Number of bytes to allocate
                       alignment  Alignment to use for the allocation
                       addr       Pointer to the newly allocated memory
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_alloc(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem, UINT32 p_size, UINT32 p_alignment, UINT32 *p_addr)
{
    GFX_ERROR fl_ret = GFX_MM_ERR_NO_MEMORY;
    GFX_MGR02_BLOCK_INFO_T *fl_block;
    GFX_MGR02_BLOCK_INFO_T fl_temp_block;
    GFX_MGR02_BLOCK_INFO_T *fl_newBlock = NULL;
    GFX_MGR02_BLOCK_INFO_T *fl_newRemBlock = NULL;
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;
    UINT32 fl_alignRemainder, fl_total_alloc_size, fl_total_align_size, fl_total_align_alloc_size;
    UINT32 fl_alignment     = p_alignment;
    UINT32 fl_alloc_size    = p_size;
    UINT32 fl_header_size   = sizeof(GFX_MGR02_BLOCK_INFO_T);
    UINT8 fl_mergedFlag     = 0U;
    
    if ((fl_heap == NULL) || (fl_alloc_size == 0UL) || (p_addr == NULL))
    {
        #ifdef GFX02_DEBUG_INFO
        printf("hmi_gfx_mgr02_mem_mgmt_heap_alloc: ERROR: hdlmem == NULL or size == 0 or addr == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    }
    else
    {
        *p_addr = 0U;
        
        /* Normalize alignment to make sure the allocated memory is always aligned to 4 bytes boundary */
        if (fl_alignment == 0U) /* alignment is 0 */
        {
            fl_alignment = 4U;
        } 
        else if (0U != (fl_alignment & 1U)) /* alignment is odd */
        {
            fl_alignment *= 4U;
        } 
        else if (0U != (fl_alignment & 2U)) /* alignment is even but not divisible by 4 */
        {
            fl_alignment *= 2U;
        } 
        else
        {
            /* alignment is divisible by 4, remain unchanged */
        }
        
        /* Search for first available memory block in the linked list of available
         * free blocks that can accommodate the requested size.  */ 
        fl_block = fl_heap->freeBlockRover;

        #ifdef GFX_MGR02_MEM_MGMT_CHECK
        fl_alloc_size += GFX_MEM_MAGIC_SIZE;
        #endif
        
        while (NULL != fl_block)
        {
            /* Check alignment remainder of the usuable memory address after the header within the block */
            fl_alignRemainder = ((((UINT32)fl_block + fl_header_size) + (fl_alignment-1U)) & \
                    ~(fl_alignment-1U)) - ((UINT32)fl_block + fl_header_size);
            
            /* If alignment remainder is zero, then the current free block is divided into two blocks
             * one part is allocated for the requested size plus header size, and the remaining part
             * is marked as a free block with a new header. But if alignment remainder is not zero,
             * then current free block is divided into three blocks. The portion of memory before the
             * alignment is splitted from the allocated block, creating a new free block, which is 
             * then added to the linked list of available free blocks. */            
            if (fl_alignRemainder == 0U)
            {
                fl_total_alloc_size = fl_alloc_size + fl_header_size;
                if (fl_block->size >= fl_total_alloc_size)
                {
                    /* New free block needs to be created if current block is larger than the
                    allocated block and its should have enough memory left to hold one more header */
                    
                    if ((fl_total_alloc_size + fl_header_size) < (fl_block->size))
                    {
                        /* Current free block splitted into new free block & allocated block. */
                        fl_newBlock = (GFX_MGR02_BLOCK_INFO_T*)((UINT32)fl_block + fl_total_alloc_size);
                        fl_newBlock->nextBlock = fl_block->nextBlock;
                        fl_newBlock->prevBlock = fl_block;
                        fl_newBlock->size = fl_block->size - fl_total_alloc_size;
                        fl_newBlock->isUsed = 0u;
                        fl_newBlock->nextFreeBlock = fl_block->nextFreeBlock;
                        fl_newBlock->prevFreeBlock = fl_block->prevFreeBlock;
                        
                        fl_block->nextBlock = fl_newBlock;

                        if (NULL != fl_newBlock->nextBlock)
                        {
                            fl_newBlock->nextBlock->prevBlock = fl_newBlock;
                        }

                        if (NULL != fl_block->prevFreeBlock)
                        {
                            fl_block->prevFreeBlock->nextFreeBlock = fl_newBlock;
                        }

                        if (NULL != fl_block->nextFreeBlock)
                        {
                            fl_block->nextFreeBlock->prevFreeBlock = fl_newBlock;
                        }
                        
                        if (fl_heap->freeBlockRover == fl_block)
                        {
                            fl_heap->freeBlockRover = fl_newBlock;
                        }
                        
                        fl_heap->totalBlockInfoMem += fl_header_size;
                        fl_heap->numFreeBlocks++;
                    } 
                    else
                    {
                        if (NULL != fl_block->prevFreeBlock)
                        {
                            fl_block->prevFreeBlock->nextFreeBlock = fl_block->nextFreeBlock;
                        }
                        
                        if (NULL != fl_block->nextFreeBlock)
                        {
                            fl_block->nextFreeBlock->prevFreeBlock = fl_block->prevFreeBlock;
                        }
                        
                        if (fl_heap->freeBlockRover == fl_block)
                        {
                            fl_heap->freeBlockRover = fl_block->nextFreeBlock;
                        }
                        
                        fl_heap->totalUntrackedMem += (fl_block->size - fl_total_alloc_size);
                    }
                    
                    fl_block->size = fl_total_alloc_size;
                    fl_block->isUsed = 1U;
                    fl_heap->totalAllocatedMem += fl_alloc_size;
                    if (fl_heap->totalFreeMem >= fl_total_alloc_size)
                    {
                        fl_heap->totalFreeMem = fl_heap->totalFreeMem - fl_total_alloc_size;
                    }
                    fl_heap->numAllocatedBlocks++;
                    if (fl_heap->numFreeBlocks > 0U)
                    {
                        fl_heap->numFreeBlocks--;
                    }
                    
                    *p_addr = (UINT32)fl_block + fl_header_size;

                    #ifdef GFX_MGR02_MEM_MGMT_CHECK
                    void* fl_VirtAdd = NULL;
                    const UINT32 fl_val = GFX_MEM_MAGIC;
                    UINT32 fl_addCheck = ((*p_addr) + fl_alloc_size) - GFX_MEM_MAGIC_SIZE;
                    fl_VirtAdd = (void*)(fl_addCheck);
                    (void)memcpy(fl_VirtAdd, (const void*)&fl_val, GFX_MEM_MAGIC_SIZE);
                    #endif
                    fl_ret = GFX_OK;
                    break;
                }
            }
            else
            {
                
                fl_alignRemainder += ((((UINT32)fl_block + (fl_header_size * 2U) + fl_alignRemainder) + \
                    (fl_alignment-1U)) & ~(fl_alignment-1U)) - ((UINT32)fl_block + (fl_header_size * 2U) + fl_alignRemainder);
                
                fl_total_alloc_size = fl_alloc_size + fl_header_size;
                fl_total_align_size = fl_alignRemainder + fl_header_size;
                fl_total_align_alloc_size = fl_total_alloc_size + fl_total_align_size;
                
                if (fl_block->size >= fl_total_align_alloc_size)
                {
                    /* New free block needs to be created if current block is
                    larger than the allocated block + align block and
                    its should have enough memory left to hold one more header for the new block */
                    if ((fl_total_align_alloc_size + fl_header_size) < fl_block->size)
                    {
                        fl_newBlock = (GFX_MGR02_BLOCK_INFO_T*)((UINT32)fl_block + fl_total_align_alloc_size);
                        fl_newBlock->nextBlock = fl_block->nextBlock;
                        fl_newBlock->prevBlock = fl_block;
                        fl_newBlock->size = fl_block->size - fl_total_align_alloc_size;
                        fl_newBlock->isUsed = 0U;
                        fl_newBlock->nextFreeBlock = fl_block->nextFreeBlock;
                        fl_newBlock->prevFreeBlock = fl_block->prevFreeBlock;
                        
                        fl_block->nextBlock = fl_newBlock;
                        fl_block->size = fl_total_align_alloc_size;

                        if (NULL != fl_newBlock->nextBlock)
                        {
                            fl_newBlock->nextBlock->prevBlock = fl_newBlock;
                        }

                        if (NULL != fl_block->prevFreeBlock)
                        {
                            fl_block->prevFreeBlock->nextFreeBlock = fl_newBlock;
                        }

                        if (NULL != fl_block->nextFreeBlock)
                        {
                            fl_block->nextFreeBlock->prevFreeBlock = fl_newBlock;
                        }
                        
                        if (fl_heap->freeBlockRover == fl_block )
                        {
                            fl_heap->freeBlockRover = fl_newBlock;
                        }
                        
                        fl_heap->totalBlockInfoMem += fl_header_size;
                        fl_heap->numFreeBlocks++;
                    } 
                    else
                    {
                        if (NULL != fl_block->prevFreeBlock)
                        {
                            fl_block->prevFreeBlock->nextFreeBlock = fl_block->nextFreeBlock;
                        }
                        
                        if (NULL != fl_block->nextFreeBlock)
                        {
                            fl_block->nextFreeBlock->prevFreeBlock = fl_block->prevFreeBlock;
                        }
                        
                        if (fl_heap->freeBlockRover == fl_block)
                        {
                            fl_heap->freeBlockRover = fl_block->nextFreeBlock;
                        }
                        
                        fl_heap->totalUntrackedMem += (fl_block->size - fl_total_align_alloc_size);
                    }
                    
                    /* Creating a temporary copy of alignRemainder + alloc block */
                    (void)memcpy((void *)&fl_temp_block, (const void *)fl_block, (size_t)fl_header_size);
                    
                    /* Create new align remainder block splitted from the current (alignRemainder + alloc) block */
                    fl_newRemBlock                  = (GFX_MGR02_BLOCK_INFO_T*)fl_block;
                    fl_newRemBlock->prevBlock       = fl_temp_block.prevBlock;
                    fl_newRemBlock->nextBlock       = (GFX_MGR02_BLOCK_INFO_T*)((UINT32)fl_block + fl_total_align_size);
                    fl_newRemBlock->size            = fl_total_align_size;
                    fl_newRemBlock->isUsed          = 0U;
                    fl_newRemBlock->nextFreeBlock   = NULL;
                    fl_newRemBlock->prevFreeBlock   = NULL;
                    
                    fl_heap->numFreeBlocks++;
                    fl_heap->totalBlockInfoMem   += fl_header_size;
                    
                    if(NULL != fl_newRemBlock->prevBlock)
                    {
                        /* If the previous block of new align remainder block is also free,
                         *  then both blocks are merged together to create one free block */
                        if (fl_newRemBlock->prevBlock->isUsed == 0U)
                        {
                            fl_newRemBlock->prevBlock->nextBlock = fl_newRemBlock->nextBlock;
                            fl_newRemBlock->nextBlock->prevBlock = fl_newRemBlock->prevBlock;
                            fl_newRemBlock->prevBlock->size += fl_newRemBlock->size;
                            
                            fl_heap->totalBlockInfoMem -= fl_header_size;
                            fl_heap->totalFreeMem += fl_header_size;
                            fl_heap->numFreeBlocks--;
                            
                            fl_mergedFlag = 1U;
                        }
                    }
                    
                    if (fl_mergedFlag == 0U)
                    {
                        hmi_gfx_mgr02_insert_to_free_list(fl_newRemBlock, fl_heap);
                        fl_newRemBlock->nextBlock->prevBlock = fl_newRemBlock;
                        if(NULL != fl_newRemBlock->prevBlock)
                        {
                            fl_newRemBlock->prevBlock->nextBlock = fl_newRemBlock;
                        }
                        if (fl_heap->startBlock == fl_block)
                        {
                            fl_heap->startBlock = fl_newRemBlock;
                        }
                    }
                    
                    fl_block = (GFX_MGR02_BLOCK_INFO_T*)((UINT32)fl_block + fl_total_align_size);
                    fl_block->size = fl_total_alloc_size;
                    fl_block->nextBlock = fl_temp_block.nextBlock;
                    fl_block->isUsed = 1U;
                    if (fl_block->nextBlock != NULL)
                    {
                        fl_block->nextBlock->prevBlock = fl_block;
                    }
                    
                    fl_heap->totalAllocatedMem   += fl_alloc_size;
                    if (fl_heap->totalFreeMem >= (fl_alloc_size + (fl_header_size * 2U)))
                    {
                        fl_heap->totalFreeMem -= (fl_alloc_size + (fl_header_size * 2U));
                    }
                    
                    fl_heap->numAllocatedBlocks++;
                    if (fl_heap->numFreeBlocks > 0U)
                    {
                        fl_heap->numFreeBlocks--;
                    }
                            
                    *p_addr = (UINT32)fl_block + fl_header_size;

                    #ifdef GFX_MGR02_MEM_MGMT_CHECK
                    void* fl_VirtAdd = NULL;
                    const UINT32 fl_val = GFX_MEM_MAGIC;
                    UINT32 fl_addCheck = ((*p_addr) + fl_alloc_size) - GFX_MEM_MAGIC_SIZE;
                    fl_VirtAdd = (void*)(fl_addCheck);
                    (void)memcpy(fl_VirtAdd, (const void*)&fl_val, GFX_MEM_MAGIC_SIZE);
                    #endif
                    fl_ret = GFX_OK;
                    break;
                }
            }
            
            fl_block = (GFX_MGR02_BLOCK_INFO_T*) fl_block->nextFreeBlock;
        }
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_heap_free
Description          : Frees a block of memory previously allocated by hmi_gfx_mgr02_mem_mgmt_heap_alloc
Parameters           : hdlmem  Heap to release the memory to
                       addr    Pointer to the memory to free
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_free(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem, void* p_addr)
{
    GFX_ERROR fl_ret = GFX_OK;
    GFX_MGR02_BLOCK_INFO_T *fl_block;
    GFX_MGR02_BLOCK_INFO_T *fl_tempPtr;
    BOOLEAN fl_merged = FALSE; 
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;
    UINT32 fl_header_size = sizeof(GFX_MGR02_BLOCK_INFO_T);
    #ifdef GFX_MGR02_MEM_MGMT_CHECK
    UINT32 fl_orgSize = 0UL;
    #endif

    if (fl_heap == NULL)
    {
        #ifdef GFX02_DEBUG_INFO
        printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_free: ERROR: hdlmem == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    }
    else if ((p_addr == NULL) || ((UINT32)p_addr < fl_heap->baseAddress) || \
        ((UINT32)p_addr > (fl_heap->baseAddress + fl_heap->size)))
    {
        #ifdef GFX02_DEBUG_INFO
        printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_free() - invalid/unmanaged address 0x%08x\n", (UINT32)p_addr);
        #endif
        fl_ret = GFX_MM_ERR_INVALID_MEMORY;
    }
    else
    {
        fl_block = hmi_gfx_mgr02_get_block(p_addr, fl_heap);
        
        if (fl_block == NULL)
        {
            #ifdef GFX02_DEBUG_INFO
            printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_free() - failed to find block with address 0x%08x\n", (UINT32)p_addr);
            #endif
            fl_ret = GFX_MM_ERR_INVALID_MEMORY;
        }
        else
        {
            /* Check if the block is already free */
            if (fl_block->isUsed == 0U)
            {
                #ifdef GFX02_DEBUG_INFO
                printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_free() - attempt to free already free block at 0x%08x\n", (UINT32)p_addr);
                #endif
                fl_ret = GFX_MM_ERR_INVALID_MEMORY;
            }
            else
            {
                fl_block->isUsed = 0U;
                
                if (fl_heap->totalAllocatedMem >= (fl_block->size - fl_header_size))
                {
                    fl_heap->totalAllocatedMem -= (fl_block->size - fl_header_size);
                }
                
                fl_heap->totalFreeMem += (fl_block->size - fl_header_size);
                #ifdef GFX_MGR02_MEM_MGMT_CHECK
                if (fl_block->size >= fl_header_size)
                {
                    fl_orgSize = (fl_block->size - fl_header_size);
                }
                #endif
                
                /* If the next block of newly freed block is also free,
                 * then both blocks are merged together to create one free block */
                if (NULL != fl_block->nextBlock)
                {
                    fl_tempPtr = fl_block->nextBlock;
                    if (fl_tempPtr->isUsed == 0U)
                    {
                        fl_block->size += fl_tempPtr->size;

                        if (fl_tempPtr->prevFreeBlock != NULL)
                        {
                            fl_tempPtr->prevFreeBlock->nextFreeBlock = fl_block;
                        }

                        if (fl_tempPtr->nextFreeBlock != NULL)
                        {
                            fl_tempPtr->nextFreeBlock->prevFreeBlock = fl_block;
                        }

                        fl_block->nextFreeBlock = fl_tempPtr->nextFreeBlock;
                        fl_block->prevFreeBlock = fl_tempPtr->prevFreeBlock;

                        if (fl_heap->freeBlockRover == fl_tempPtr)
                        {
                            fl_heap->freeBlockRover = fl_block;
                        }
                        
                        fl_block->nextBlock = fl_tempPtr->nextBlock;
                        if (NULL != fl_tempPtr->nextBlock )
                        {
                            fl_tempPtr->nextBlock->prevBlock = fl_block;
                        }
                        
                        if (fl_heap->numAllocatedBlocks > 0U)
                        {
                            fl_heap->numAllocatedBlocks--;
                        }
                        if (fl_heap->totalBlockInfoMem >= fl_header_size)
                        {
                            fl_heap->totalBlockInfoMem -= fl_header_size;
                        }
                        fl_heap->totalFreeMem += fl_header_size;
                        fl_merged = TRUE;
                    }
                }
                
                /* If the previous block of newly freed block is also free,
                 * then both blocks are merged together to create one free block */
                if (NULL != fl_block->prevBlock )
                {
                    fl_tempPtr = fl_block->prevBlock;

                    if ( fl_tempPtr->isUsed == 0U )
                    {
                        fl_tempPtr->size += fl_block->size;
                        if (fl_heap->numAllocatedBlocks > 0U)
                        {
                            fl_heap->numAllocatedBlocks--;
                        }
                        if (fl_heap->totalBlockInfoMem >= fl_header_size)
                        {
                            fl_heap->totalBlockInfoMem -= fl_header_size;
                        }
                        fl_heap->totalFreeMem += fl_header_size;
                        
                        fl_tempPtr->nextBlock = fl_block->nextBlock;
                        if (NULL != fl_block->nextBlock )
                        {
                            fl_block->nextBlock->prevBlock = fl_tempPtr;
                        }

                        if (fl_merged == TRUE)
                        {
                            if (fl_heap->numFreeBlocks > 0U)
                            {
                                fl_heap->numFreeBlocks--;
                            }
                            fl_heap->numAllocatedBlocks++;
                            
                            hmi_gfx_mgr02_remove_from_free_list(fl_block, fl_heap);
                        }
                        fl_merged = TRUE;
                    }
                }

                if (FALSE == fl_merged)
                {
                    hmi_gfx_mgr02_insert_to_free_list(fl_block, fl_heap);
                    
                    if (fl_heap->numAllocatedBlocks > 0U)
                    {
                        fl_heap->numAllocatedBlocks--;
                    }
                    fl_heap->numFreeBlocks++;
                }
                
                #ifdef GFX_MGR02_MEM_MGMT_CHECK
                void* fl_VirtAdd = NULL;
                UINT32 fl_val;
                UINT32 fl_addCheck = (((UINT32)p_addr) + fl_orgSize) - GFX_MEM_MAGIC_SIZE;
                fl_VirtAdd = (void*)(fl_addCheck);
                (void)memcpy((void *)&fl_val, (const void *)fl_VirtAdd, GFX_MEM_MAGIC_SIZE);
                if (fl_val != GFX_MEM_MAGIC)
                {
                    #ifdef GFX02_DEBUG_INFO
                    printf("[ERROR] Memory beyond allocated RAM was overwritten: Allocated block at %p (size %d bytes)\n", p_addr, fl_orgSize - 4);
                    #endif
                    l_memory_overwritten = TRUE;
                    fl_ret = GFX_MM_ERR_CHECK_FAILED;
                }
                #endif
            }
        }
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_heap_realloc
Description          : Reallocates a block of memory previously allocated by hmi_gfx_mgr02_mem_mgmt_heap_alloc
Parameters           : hdlmem     Heap to perform the reallocation from
                       size       Number of bytes to reallocate
                       alignment  Alignment to use for the reallocation
                       oldaddr    Pointer to the old allocated memory that needs to be reallocated
                       newaddr    Pointer to the newly reallocated memory
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_realloc(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem,
                                              UINT32 p_size, UINT32 p_alignment, 
                                              UINT32 *p_newaddr, UINT32 *p_oldaddr)
{
    /*
    1) Allocate the New memory as per newly requested size
    2) Copy the old memory content to newly allocated memory.
    3) Free the old memory.
    4) Return the new memory
    */
    
    UINT32 fl_utRet = 0UL;
    GFX_ERROR fl_ret;
    GFX_MGR02_BLOCK_INFO_T *fl_block;
    GFX_MGR02_HEAP_INFO_T *fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;
    UINT32 fl_header_size = sizeof(GFX_MGR02_BLOCK_INFO_T);
    
    fl_block = hmi_gfx_mgr02_get_block(p_oldaddr, fl_heap);
    
    if (fl_block == NULL)
    {
        /* Passed memory address is not found in the allocated block linked list */ 
        *p_newaddr = 0UL;
        #ifdef GFX02_DEBUG_INFO
        printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_realloc - failed to find block with address 0x%08x\n", (UINT32)p_oldaddr);
        #endif
        fl_ret = GFX_MM_ERR_INVALID_MEMORY;
    }
    else if (fl_block->isUsed == 0U)
    {
        *p_newaddr = 0UL;
        #ifdef GFX02_DEBUG_INFO
        printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_realloc - already free block with address 0x%08x\n", (UINT32)p_oldaddr);
        #endif
        fl_ret = GFX_MM_ERR_INVALID_MEMORY;
    }
    else
    {
        /* Checked if the requested size is same the original block size */
        #ifdef GFX_MGR02_MEM_MGMT_CHECK
        if ((p_size + fl_header_size + GFX_MEM_MAGIC_SIZE) == fl_block->size)
        #else
        if ((p_size + fl_header_size) == fl_block->size)    
        #endif    
        {
            *p_newaddr = (UINT32)p_oldaddr;
            #ifdef GFX02_DEBUG_INFO
            printf("[WARN] hmi_gfx_mgr02_mem_mgmt_heap_realloc - same size reallocation requested with address 0x%08x\n", (UINT32)p_oldaddr);
            #endif
            fl_ret = GFX_OK;
        }
        else
        {
            *p_newaddr = 0UL;
            fl_ret = hmi_gfx_mgr02_mem_mgmt_heap_alloc(p_hdlmem, p_size, p_alignment, &fl_utRet);
            if(fl_ret == GFX_OK)
            {
                if(fl_utRet != (UINT32)0)
                {
                    #ifdef GFX_MGR02_MEM_MGMT_CHECK
                    if ((p_size + fl_header_size + GFX_MEM_MAGIC_SIZE) > fl_block->size)
                    #else
                    if ((p_size + fl_header_size) > fl_block->size)    
                    #endif    
                    {
                        #ifdef GFX_MGR02_MEM_MGMT_CHECK
                        (void)memcpy((void *)fl_utRet, (const void*)p_oldaddr, (size_t)(fl_block->size - (fl_header_size + GFX_MEM_MAGIC_SIZE)));
                        #else
                        (void)memcpy((void *)fl_utRet, (const void*)p_oldaddr, (size_t)(fl_block->size - (fl_header_size)));    
                        #endif    
                    }
                    else
                    {
                        (void)memcpy((void *)fl_utRet, (const void*)p_oldaddr, (size_t)p_size);
                    }
                }
                
                fl_ret = hmi_gfx_mgr02_mem_mgmt_heap_free(p_hdlmem, p_oldaddr);
                if (fl_ret != GFX_OK)
                {
                    #ifdef GFX02_DEBUG_INFO
                    printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_heap_free: failed to free memory at %p!\n", p_oldaddr);
                    #endif
                }
            
                *p_newaddr = fl_utRet;
            }
        }
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_get_size
Description          : Gets the size of the heap memory
Parameters           : hdlmem  Heap to get the information for
                       size    Pointer to the variable to receive the information
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_size(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem, UINT32 *p_size)
{
    GFX_ERROR fl_ret;
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;

    if ((fl_heap == NULL) || (p_size == NULL))
    {
        #ifdef GFX02_DEBUG_INFO
        printf("hmi_gfx_mgr02_mem_mgmt_get_size: ERROR: hdlmem == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    }
    else
    {
        *p_size = fl_heap->size;
        fl_ret = GFX_OK;
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_get_free
Description          : Gets the total amount of free memory on the heap
Parameters           : hdlmem  Heap to get the information for
                       size    Pointer to the variable to receive the information
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_free(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem, UINT32 *p_size)
{
    GFX_ERROR fl_ret;
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;

    if ((fl_heap == NULL) || (p_size == NULL))
    {
        #ifdef GFX02_DEBUG_INFO
        printf("hmi_gfx_mgr02_mem_mgmt_get_free: ERROR: hdlmem == NULL or size == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    } 
    else
    {
        *p_size = fl_heap->totalFreeMem;
        fl_ret = GFX_OK;
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_mem_mgmt_get_largest
Description          : Gets the size of the largest free contiguous memory block on the heap
Parameters           : hdlmem   Heap to get the information for
                       size    Pointer to variable to receive the information
Return Value         : Error code
******************************************************************************/

GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_largest(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem, UINT32 *p_size)
{
    GFX_MGR02_HEAP_INFO_T* fl_heap = (GFX_MGR02_HEAP_INFO_T*)p_hdlmem;
    UINT32 fl_header_size = sizeof(GFX_MGR02_BLOCK_INFO_T);
    GFX_MGR02_BLOCK_INFO_T *fl_block;
    GFX_ERROR fl_ret;
    
    if ((fl_heap == NULL) || (p_size == NULL))
    {
        #ifdef GFX02_DEBUG_INFO
        printf("hmi_gfx_mgr02_mem_mgmt_get_largest: ERROR: hdlmem == NULL or size == NULL\r\n");
        #endif
        fl_ret = GFX_MM_ERR_INVALID_PARAMETER;
    }
    else
    {
        *p_size = 0U;
        fl_block = fl_heap->freeBlockRover;

        while (NULL != fl_block)
        {
            if (fl_block->size > (*p_size + fl_header_size))
            {
                *p_size = (fl_block->size - fl_header_size);
            }
            fl_block = fl_block->nextFreeBlock;
        }
        fl_ret = GFX_OK;
    }
    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_insert_to_free_list
Description          : Add the specified block to the specified heap's free block list.
Parameters           : block Block to add to the free list.
                       heap Heap to add block to.
Return Value         : None
******************************************************************************/

static void hmi_gfx_mgr02_insert_to_free_list(GFX_MGR02_BLOCK_INFO_T* p_block, GFX_MGR02_HEAP_INFO_T* p_heap)
{
    if(NULL != p_heap->freeBlockRover )
    {
        p_heap->freeBlockRover->prevFreeBlock = p_block;
        p_block->nextFreeBlock = p_heap->freeBlockRover;
    }
    p_block->prevFreeBlock = NULL;
    p_heap->freeBlockRover = p_block;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_remove_from_free_list
Description          : Remove the specified block from the specified heap's free block list.
Parameters           : block Block to remove from the free list.
                       heap Heap to remove block from.
Return Value         : None
******************************************************************************/

static void hmi_gfx_mgr02_remove_from_free_list(GFX_MGR02_BLOCK_INFO_T* p_block, GFX_MGR02_HEAP_INFO_T* p_heap)
{
    if( p_heap->freeBlockRover == p_block )
    {
        if (NULL != p_block->nextFreeBlock)
        {
            p_block->nextFreeBlock->prevFreeBlock = NULL;
        }
        p_heap->freeBlockRover = p_block->nextFreeBlock;
    }
    else
    {
        if (NULL != p_block->nextFreeBlock)
        {
            p_block->nextFreeBlock->prevFreeBlock = p_block->prevFreeBlock;
        }
        if (NULL != p_block->prevFreeBlock)
        {
            p_block->prevFreeBlock->nextFreeBlock = p_block->nextFreeBlock;
        }
    }
    p_block->nextFreeBlock = NULL;
    p_block->prevFreeBlock = NULL;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_block
Description          : Locates a GFX_MGR02_BLOCK_INFO_T structure associated with
                       the specified address in the specified heap.
Parameters           : addr Address which the block is associated with
                       heap Heap which contains the block
Return Value         : Pointer to the GFX_MGR02_BLOCK_INFO_T structure object, or NULL.
******************************************************************************/

static GFX_MGR02_BLOCK_INFO_T* hmi_gfx_mgr02_get_block(void *p_addr, GFX_MGR02_HEAP_INFO_T* p_heap)
{
    GFX_MGR02_BLOCK_INFO_T *fl_block = p_heap->startBlock;
    BOOLEAN fl_blockFound = FALSE;
    UINT32 fl_header_size = sizeof(GFX_MGR02_BLOCK_INFO_T);
    
    /* Traverse through the block linked list, and find the required block */
    while (NULL != fl_block)
    {
        if (((UINT32)fl_block + fl_header_size) == (UINT32)p_addr)
        {
            fl_blockFound = TRUE;
            break;
        }
        fl_block = fl_block->nextBlock;
    }
    
    if (fl_blockFound == FALSE)
    {
        fl_block = NULL;
    }

    return fl_block;
}

