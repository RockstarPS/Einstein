#if !defined( OS_TYPES_H )
#define OS_TYPES_H

/* ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//      This is an unpublished work of authorship, which contains trade
//      secrets, created in 2002.  Visteon Corporation owns all rights
//      to this work and intends to maintain it in confidence to preserve
//      its trade secret status.  Visteon Corporation reserves the right,
//      under the copyright laws of the United States or those of any other
//      country that may have jurisdiction, to protect this work as an
//      unpublished work, in the event of an inadvertent or deliberate
//      unauthorized publication.  Visteon Corporation also reserves its
//      rights under all copyright laws to protect this work as a published
//      work, when appropriate.  Those having access to this work may not
//      copy it, use it, modify it, or disclose the information contained
//      in it without the written authorization of Visteon Corporation.
//
// ======================================================================== */

/* ===========================================================================
//
// File:            os_types.h
//
// Description:     OS Types
//
// ======================================================================== */

/* ===========================================================================
//
//  Include Files
//
// ======================================================================== */


#include <stdio.h>
#include <types.h>
#include <stdint.h>

/* ===========================================================================
//
//  Begin C in a C++ environment
//
// ======================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

//#define OSAL_DEBUG

/* ===========================================================================
//
//  32 bit unsigned
//
// ======================================================================== */

#ifndef _UNSIGNED_32
   #define _UNSIGNED_32
   typedef uint32_t     unsigned32;
#endif


/* ===========================================================================
//
//  32 bit signed
//
// ======================================================================== */

#ifndef _SIGNED_32
   #define _SIGNED_32
   typedef int32_t    signed32;
#endif


/* ===========================================================================
//
//  16 bit unsigned
//
// ======================================================================== */

#ifndef _UNSIGNED_16
   #define _UNSIGNED_16
   typedef uint16_t     unsigned16;
#endif


/* ===========================================================================
//
//  16 bit signed
//
// ======================================================================== */

#ifndef _SIGNED_16
   #define _SIGNED_16
   typedef int16_t      signed16;
#endif


/* ===========================================================================
//
//  8 bit unsigned
//
// ======================================================================== */

#ifndef _UNSIGNED_8
   #define _UNSIGNED_8
   typedef uint8_t      unsigned8;
#endif


/* ===========================================================================
//
//  8 bit signed
//
// ======================================================================== */

#ifndef _SIGNED_8
   #define _SIGNED_8
   typedef int8_t      signed8;
#endif


/* ===========================================================================
//
//  64 bit unsigned
//
// ======================================================================== */

#ifndef _UNSIGNED_64
   #define _UNSIGNED_64
   typedef uint64_t    unsigned64;
#endif


/* ===========================================================================
//
//  64 bit signed
//
// ======================================================================== */

#ifndef _SIGNED_64
   #define _SIGNED_64
   typedef int64_t    signed64;
#endif


/* ===========================================================================
//
//  BOOLEAN types
//
// ======================================================================== */

#ifndef _BOOLEAN
   #define _BOOLEAN
   typedef short bool;
#endif

#ifndef true
   #define true     (1)
#endif

#ifndef  false
   #define false    (0)
#endif


/* ===========================================================================
//
//  os_status_type enum
//
// ======================================================================== */

typedef enum
{
    OS_FAIL,
    OS_SUCCESS
}
os_status_type;


/* ===========================================================================
//
//  ipcSyncFunctionPointerType for synchronous message suppor (use rarely)
//
// ======================================================================== */

typedef void (*ipcSyncFunctionPointerType)( unsigned32 * msg, unsigned32 * rMsg );


/* ===========================================================================
//
//  os_max_usage_struct_type for clients to specify how many OS resources
//  they require.
//
// ======================================================================== */

typedef struct
{
    unsigned32  os_timers;
    unsigned32  os_semaphores;
    unsigned32  os_mutexes;
}
os_max_usage_struct_type;


/* ===========================================================================
//
//  This type specifies the priority for the given task
//  (0 being lowest, 255 highest)
//
// ======================================================================== */

typedef unsigned8   os_priority_type;


/* ===========================================================================
//
//  This type specifies the type for the generic task signalling event
//
// ======================================================================== */

typedef unsigned32  os_event_type;


/* ===========================================================================
//
//  os_file_type
//
// ======================================================================== */

typedef FILE  os_file_type;


/* ===========================================================================
//
//  Micro Endianess defines
//
// ======================================================================== */

#define OS_MICRO_ENDIAN_BIG             (0)
#define OS_MICRO_ENDIAN_LITTLE          (1)


/* ===========================================================================
//
//  End C in a C++ environment
//
// ======================================================================== */
#ifdef __cplusplus
}
#endif

#endif /*  OS_TYPES_H */
