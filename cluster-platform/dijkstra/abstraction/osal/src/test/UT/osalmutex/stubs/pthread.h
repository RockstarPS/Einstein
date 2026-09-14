#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED


#define CLOCK_REALTIME			0
#define ETIMEDOUT               9938

typedef struct pthread_attr_t_ * pthread_attr_t;
typedef struct pthread_mutex_t_ * pthread_mutex_t;
typedef struct pthread_mutexattr_t_ * pthread_mutexattr_t;

enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
  PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};

enum
{
  PTHREAD_PROCESS_PRIVATE,
#define PTHREAD_PROCESS_PRIVATE PTHREAD_PROCESS_PRIVATE
  PTHREAD_PROCESS_SHARED
#define PTHREAD_PROCESS_SHARED  PTHREAD_PROCESS_SHARED
};

int pthread_mutex_init (pthread_mutex_t *__mutex,
			       const pthread_mutexattr_t *__mutexattr);
int pthread_mutex_destroy (pthread_mutex_t *__mutex);
int pthread_mutex_trylock (pthread_mutex_t *__mutex);
int pthread_mutex_lock (pthread_mutex_t *__mutex);
int pthread_mutex_unlock (pthread_mutex_t *__mutex);
int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
				    const struct timespec *__restrict
				    __abstime);

int pthread_mutexattr_init (pthread_mutexattr_t *__attr);
int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
					 int __pshared);
int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind);
int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr);

#endif
