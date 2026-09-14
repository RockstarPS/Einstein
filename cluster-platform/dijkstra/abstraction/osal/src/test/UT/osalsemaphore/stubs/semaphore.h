#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

#define ETIMEDOUT               9938

#if __WORDSIZE == 64
# define __SIZEOF_SEM_T	32
#else
# define __SIZEOF_SEM_T	16
#endif

typedef union
{
  char __size[__SIZEOF_SEM_T];
  long int __align;
} sem_t;

int sem_init (sem_t *__sem, int __pshared, unsigned int __value);
int sem_wait (sem_t *__sem);
int sem_destroy (sem_t *__sem);
int sem_timedwait (sem_t *__restrict __sem,
	   const struct timespec *__restrict __abstime);
int sem_trywait (sem_t *__sem);
int sem_post (sem_t *__sem);
int sem_getvalue (sem_t *__restrict __sem, int *__restrict __sval);

#endif