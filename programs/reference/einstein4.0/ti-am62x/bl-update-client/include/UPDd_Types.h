/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
# ifndef UPDd_Types_H
# define UPDd_Types_H

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define UPDd_INJECTION_TESTING // Only for unit testing
#define UTEST // Only for unit test, do not use this on target

//#define UPDd_POINTER_TEST_DISABLED           // Disable the checks on pointers
#define UPDd_MAX_PACKAGE_NAME_SIZE 64        // Max size for package name
#define UPDd_LZMA_MEMORY_POOL_SIZE (1024) // Memory pool for LZMA decoding, encoder need to be configured with the same size
#define UPDd_LOAD_BUFFER_SIZE (256)       // Maximum IO chunk
#define UPDd_REQ_FIFO_SIZE 8 				 // Number of IO chunk on the IO decoupling queue
#define UPDd_HASH_BUFFER_SIZE (32)           // Internal buffer for storing the Hash
#define UPDd_REQ_FIFO_HIGH_LOAD 50 			 // Percentage, when REQ_FIFO goes about this threshold,
		                                     // the load is considerer high and the responses are delayed to reduce the transmission speed
#define UPDd_COMPOSE_BUFFER_SIZE (1)        // If Delta Composition with A-Only is required, it shall be as big as the partition (can be 1 if not required)

#define UPDd_SPARSE_BLOCK_SIZE (1024)

#define UPDd_MAX_SLOT 2 // Can be 1 or 2, 2 when A & B is supported
#define E_PENDING 2u

#define UPDd_MAX_ERASE_CYCLE 2 // Maximum number of erase cycles per power cycle
#define UPDd_MAX_HASHING_CYCLE 5 // Maximum number of consecutive invalid hashing
#define UPDd_AUTO_SYNCH 1 // Automaticaly synch the inactive bank after commit

// Constants for FLS
#define UPDd_FLS_PAGE_BUFFERING STD_ON     // when activated, UPD only write multiple of the page size
#define UPDd_FLS_SECTOR_WRITEPAGE_SIZE 512 // UPD only write multiple of the page size
#define UPDd_FLS_SECTOR_BASEADDRESS (0x0)  // Address of the first FLS Sector
#define UPDd_FLS_SECTOR_SIZE (32*1024)     // Sector Size, in case of resume, UPD only erase the last sector

#define UPDd_HW_PARTITION_SWICTH STD_OFF  // when activated, HW support the bank addresses switch. BankB is always inactive.

#define UPDd_UPDATE_ONCE_ACTIVE_CHAIN_VERIFIED // Authorize the update only if once chain verified ok

#define UPDd_TASK_PERIOD_MS 1000       // Period of UPDTask in ms
#define UPDd_HOLD_TIMEOUT_MS 60000    // Time in ms before starting synchronization & inspection after init

#define UPDd_MAX_IO_ERROR_WARNING 5   // maximun number of warning for IOAdapter errors


//=====================================================================================================================
// TYPES
//=====================================================================================================================
typedef struct sUPDdManifest
{
    uint8  GoldenSha256[32];
} tUPDdManifest;

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#define UPDd_MAX_HASHABLE_SIZE_PER_CALL         32

#endif /*UPDd_Types_H*/
