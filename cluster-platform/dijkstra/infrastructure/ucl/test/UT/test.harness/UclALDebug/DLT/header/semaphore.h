
#include <time.h>

#if __WORDSIZE == 64
# define __SIZEOF_SEM_T	32
#else
# define __SIZEOF_SEM_T	16
#endif


/* Value returned if `sem_open' failed.  */
#define SEM_FAILED      ((sem_t *) 0)
#ifndef EOK
#define EOK 0
#endif

typedef union
{
  char __size[__SIZEOF_SEM_T];
  long int __align;
} sem_t;

int sem_timedwait (sem_t *__restrict __sem, const struct timespec *__restrict __abstime);