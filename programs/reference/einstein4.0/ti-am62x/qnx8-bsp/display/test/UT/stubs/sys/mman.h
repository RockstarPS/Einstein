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

#ifndef __MMAN_H_INCLUDED
#define __MMAN_H_INCLUDED

#include <sys/platform.h>

/* Sharing types: Must choose either SHARED, PRIVATE or ANON */
#define MAP_SHARED       0x00000001     /*!< Share changes          */
#define MAP_PRIVATE      0x00000002     /*!< Changes are private    */
# define MAP_FILE        0x00000000
#define MAP_TYPE        0x0000000f     /*!< Mask for share type    */
#define MAP_NORESERVE   0x00004000
#define MAP_RENAME      0x00008000

/* Flags to mmap (or-ed in to MAP_SHARED or MAP_PRIVATE)     */
#define MAP_FIXED        0x00000010     /*!< User assigns address   */
# define MAP_ELF         0x00000020     /*!< Patch ELF relocations  */
# define MAP_NOSYNCFILE  0x00000040     /*!< Memory not synced to file */
# define MAP_LAZY        0x00000080     /*!< Allow lazy mapping     */
# define MAP_STACK       0x00001000     /*!< Memory used for stack  */
# define MAP_BELOW       0x00002000     /*!< Allocate below hint    */
# define MAP_NOINIT      0x00004000     /*!< Don't have to initialize the memory */
# define MAP_PHYS        0x00010000     /*!< Map physical memory    */



/* flags for mlockall() */
#define MCL_CURRENT     0x000000001
#define MCL_FUTURE      0x000000002

#define MAP_FAILED      ((void *)-1)


# define NOFD                (-1)
# define MAP_DEVICE_FAILED   ((_Uintptrt)MAP_FAILED)




# define UNMAP_INIT_REQUIRED	0x00000001
# define UNMAP_INIT_OPTIONAL	0x00000002

extern uintptr_t mmap_device_io(size_t __len, uint64_t __io);
extern int munmap_device_io(uintptr_t __io, size_t __len);


#endif


