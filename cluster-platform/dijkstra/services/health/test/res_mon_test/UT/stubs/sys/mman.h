#ifndef __MMAN_H_INCLUDED
#define __MMAN_H_INCLUDED

#include <stdint.h>

#define MAP_FAILED      ((void *)-1)

# define MAP_STACK       0x00001000     /*!< Memory used for stack  */
# define PG_HWMAPPED     0x00400000     /*!< Pages are present and mapped */
#define PROT_EXEC       0x00000400     /*!< Pages can be executed  */
#define PROT_READ       0x00000100     /*!< Pages can be read      */
#define PROT_WRITE      0x00000200     /*!< Pages can be written   */

extern uintptr_t mmap_device_io(size_t __len, uint64_t __io);
extern int munmap_device_io(uintptr_t __io, size_t __len);

#endif


