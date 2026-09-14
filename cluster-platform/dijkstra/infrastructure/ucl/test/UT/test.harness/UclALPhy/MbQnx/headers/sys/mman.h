/*
 * $QNXLicenseC:
 * Copyright 2007, 2014 QNX Software Systems. All Rights Reserved.
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

/** @file
 *
 *    POSIX memory management.
 *
 */

//#ifndef __MMAN_H_INCLUDED
//#define __MMAN_H_INCLUDED

#include <stdint.h>

typedef unsigned long long _Uint64t;
/* Page protection flags which may be or-ed together         */
#define PROT_NONE       0x00000000
#define PROT_READ       0x00000100     /*!< Pages can be read      */
#define PROT_WRITE      0x00000200     /*!< Pages can be written   */
#define PROT_EXEC       0x00000400     /*!< Pages can be executed  */
# define PROT_NOCACHE   0x00000800  /*!< Pages are not cached   */

/* Sharing types: Must choose either SHARED, PRIVATE or ANON */
#define MAP_SHARED       0x00000001     /*!< Share changes          */
#define MAP_PRIVATE      0x00000002     /*!< Changes are private  */
#define MAP_FAILED      ((void *)-1)

void *mmap(void *__addr, size_t __len, int __prot, int __flags, int __fd, off_t __off);

int munmap(void *__addr, size_t __len);
void *mmap_device_memory(void *__addr, size_t __len, int __prot, int __flags, _Uint64t __physical);
int munmap_device_memory(void *__addr, size_t __len);

extern int getpagesize(void);
//#endif
