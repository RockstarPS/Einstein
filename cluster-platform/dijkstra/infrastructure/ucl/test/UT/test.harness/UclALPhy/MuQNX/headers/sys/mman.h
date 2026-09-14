#ifndef __MMAN_H_INCLUDED
#define __MMAN_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif


#if defined(__OFF64_T)
typedef __OFF64_T	off64_t;
#undef __OFF64_T
#endif

/* Page protection flags which may be or-ed together         */
#define PROT_READ       0x00000100     /*!< Pages can be read      */
#define PROT_WRITE      0x00000200     /*!< Pages can be written   */

#if defined(__EXT_QNX)
# define PROT_NOCACHE   0x00000800     /*!< Pages are not cached   */
#endif

#define MAP_FAILED      ((void *)-1)

#if defined(__EXT_QNX)
# define NOFD                (-1)
#endif

#if defined(__EXT_QNX)
extern void *mmap_device_memory(void *__addr, size_t __len, int __prot, int __flags, _Uint64t __physical);
extern int munmap(void *__addr, size_t __len);
extern int munmap_device_memory(void *__addr, size_t __len);
#endif


#define __ALIASOFF(__n)

#if defined(__EXT_QNX)		/* 1003.1j D5, used only for getting physical addresses */
//# ifdef __EXT_LF64SRC
extern int mem_offset64(__const void *__addr, int __fd, size_t __len, off64_t *__off, size_t *__contig_len) __ALIASOFF("mem_offset");
//#  if defined(__EXT_LF64ALIAS) && !defined(__ALIAS_ATTRIBUTE)
//#   error ALIAS not configured for compiler: mmap
//#  endif
//# endif
#endif

#endif //__MMAN_H_INCLUDED