#ifndef _MMAP_H
#define _MMAP_H

#define PROT_READ	0x1		/* page can be read */
#define PROT_WRITE	0x2		/* page can be written */
#define PROT_EXEC	0x4		/* page can be executed */
#define PROT_SEM	0x8		/* page may be used for atomic ops */
#define PROT_NONE	0x0		/* page can not be accessed */
#define PROT_GROWSDOWN	0x01000000	/* mprotect flag: extend change to start of growsdown vma */
#define PROT_GROWSUP	0x02000000	/* mprotect flag: extend change to end of growsup vma */

#define MAP_SHARED	0x01		/* Share changes */
#define MAP_PRIVATE	0x02		/* Changes are private */
#define MAP_SHARED_VALIDATE 0x03	/* share + validate extension flags */

#define MAP_FAILED	((void *) -1)

extern int munmap (void *__addr, size_t __len);
extern int shm_unlink (const char *__name);
extern int shm_open (const char *__name, int __oflag, mode_t __mode);

extern void *mmap(void *addr, size_t length, int prot, int flags,
       int fd, off_t offset);

#endif