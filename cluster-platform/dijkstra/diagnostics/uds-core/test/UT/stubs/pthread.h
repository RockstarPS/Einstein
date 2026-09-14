#if !defined( PTHREAD_H )
#define PTHREAD_H

#define PTHREAD_CANCEL_ASYNCHRONOUS			0x20
extern int pthread_setcanceltype(int __type, int *__oldtype);

/*
 * Mutex types.
 */
enum
{
  /* Compatibility with LinuxThreads */
  PTHREAD_MUTEX_FAST_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_TIMED_NP = PTHREAD_MUTEX_FAST_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP = PTHREAD_MUTEX_FAST_NP,
  /* For compatibility with POSIX */
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_FAST_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
};

typedef struct {
    void * p;                   /* Pointer to actual object */
    unsigned int x;             /* Extra information - reuse count etc */
} ptw32_handle_t;

typedef ptw32_handle_t pthread_t;
typedef struct pthread_attr_t_ * pthread_attr_t;

typedef struct pthread_mutex_t_ * pthread_mutex_t;
typedef struct pthread_mutexattr_t_ * pthread_mutexattr_t;

int pthread_cancel (pthread_t thread);

int pthread_create (pthread_t * tid, const pthread_attr_t * attr, void *(*start) (void *), void *arg);

int pthread_mutexattr_settype (pthread_mutexattr_t * attr, int kind);

int pthread_mutex_init (pthread_mutex_t * mutex, const pthread_mutexattr_t * attr);

int pthread_mutexattr_init (pthread_mutexattr_t * attr);

int pthread_mutex_destroy (pthread_mutex_t * mutex);

int pthread_mutex_lock (pthread_mutex_t * mutex);

int pthread_mutex_timedlock(pthread_mutex_t * mutex, const struct timespec *abstime);

int pthread_mutex_trylock (pthread_mutex_t * mutex);

int pthread_mutex_unlock (pthread_mutex_t * mutex);
#endif