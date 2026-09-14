/*
 * $QNXLicenseC:
 * Copyright 2007, QNX Software Systems. All Rights Reserved.
 * 
 * You must obtain a written license from and pay applicable license fees to QNX 
 * Software Systems before you may reproduce, modify or distribute this software, 
 * or any work that includes all or part of this software.   Free development 
 * licenses are available for evaluation and non-commercial purposes.  For more 
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *  
 * This file may contain contributions from others.  Please review this entire 
 * file for other proprietary rights or license notices, as well as the QNX 
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/ 
 * for other information.
 * $
 */



/*
 *  sys/types.h Defined system types
 *

 */
#ifndef __TYPES_H_INCLUDED
#define __TYPES_H_INCLUDED
#define __TYPES_H_DECLARED

#include <sys/qnxtypes.h>
uint32_t min(uint32_t a, uint32_t b);

typedef uint8_t                 _Uint8t;
typedef uint16_t                _Uint16t;
typedef uint64_t                _Uint64t;
typedef uint32_t                _Uint32t;
typedef int32_t                 _Int32t;
typedef int64_t                 _Int64t;

typedef _Uint64t				_Sizet;
typedef _Int64t					_Ssizet;
typedef _Uint64t				_Paddr64t;
typedef _Uint32t				_Paddr32t;


typedef _Uint64t				_Uintptr64t;
typedef _Uint32t				_Uintptr32t;
typedef _Int64t					_Intptr64t;
typedef _Int32t					_Intptr32t; 

struct _clockadjust { _Uint32t tick_count; _Int32t tick_nsec_inc; };
struct _clockadjust __CLOCKADJUST;

#endif

