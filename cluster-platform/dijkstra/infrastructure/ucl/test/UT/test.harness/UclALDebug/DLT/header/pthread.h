
#ifndef _PTHREAD_H
#define _PTHREAD_H	1

#include <sys/types.h>
#include <sched.h>

#  define __SIZEOF_PTHREAD_MUTEX_T 40
#  define __SIZEOF_PTHREAD_ATTR_T 56

/* Detach state.  */
enum
{
  PTHREAD_CREATE_JOINABLE,
#define PTHREAD_CREATE_JOINABLE	PTHREAD_CREATE_JOINABLE
  PTHREAD_CREATE_DETACHED
#define PTHREAD_CREATE_DETACHED	PTHREAD_CREATE_DETACHED
};

/* Mutex types.  */
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
#if defined __USE_UNIX98 || defined __USE_XOPEN2K8
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
#endif
#ifdef __USE_GNU
  /* For compatibility.  */
  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
#endif
};

#ifdef __x86_64__
# define __PTHREAD_MUTEX_INITIALIZER(__kind) \
  0, 0, 0, 0, __kind, 0, 0, { 0, 0 }
#else
# define __PTHREAD_MUTEX_INITIALIZER(__kind) \
  0, 0, 0, __kind, 0, { { 0, 0 } }
#endif

#define PTHREAD_MUTEX_INITIALIZER \
 { {  __PTHREAD_MUTEX_INITIALIZER (PTHREAD_MUTEX_TIMED_NP) } }

/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;

struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
#ifdef __x86_64__
  unsigned int __nusers;
#endif
  /* KIND must stay at this position in the structure to maintain
     binary compatibility with static initializers.  */
  int __kind;
#ifdef __x86_64__
  short __spins;
  short __elision;
  __pthread_list_t __list;
# define __PTHREAD_MUTEX_HAVE_PREV      1
#else
  unsigned int __nusers;
  __extension__ union
  {
    struct
    {
      short __espins;
      short __eelision;
# define __spins __elision_data.__espins
# define __elision __elision_data.__eelision
    } __elision_data;
    //__pthread_slist_t __list;
  };
# define __PTHREAD_MUTEX_HAVE_PREV      0
#endif
};

typedef union
{
  struct __pthread_mutex_s __data;
  char __size[__SIZEOF_PTHREAD_MUTEX_T];
  long int __align;
} pthread_mutex_t;

union pthread_attr_t
{
  char __size[__SIZEOF_PTHREAD_ATTR_T];
  long int __align;
};
#ifndef __have_pthread_attr_t
typedef union pthread_attr_t pthread_attr_t;
# define __have_pthread_attr_t 1
#endif

typedef int pthread_mutexattr_t;

void set_pthread_result (unsigned int tmp_pthread_result);
int pthread_mutex_lock( pthread_mutex_t* mutex );
int pthread_mutex_unlock( pthread_mutex_t* mutex );
int pthread_attr_init( pthread_attr_t *attr );
int pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate );
int pthread_create( pthread_t* thread, const pthread_attr_t* attr,void* (*start_routine)(void* ), void* arg );
int pthread_attr_destroy( pthread_attr_t * attr);
int pthread_attr_setstacklazy(pthread_attr_t * a, int lazystack );
int pthread_mutexattr_init(const pthread_mutexattr_t* attr );
int pthread_mutexattr_settype(pthread_mutexattr_t * attr,int type );
int pthread_mutexattr_destroy(pthread_mutexattr_t* attr );
int pthread_mutex_init(pthread_mutex_t* mutex,const pthread_mutexattr_t* attr );
int pthread_attr_setstacksize( pthread_attr_t * attr, size_t stacksize );

int pthread_attr_getschedparam (const pthread_attr_t *__attr, struct sched_param *__param);
int pthread_attr_setschedparam (pthread_attr_t *__attr, const struct sched_param *__param);
int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy);
int pthread_getschedparam (pthread_t __target_thread, int *__restrict __policy, struct sched_param *__restrict __param);
pthread_t pthread_self (void);
int pthread_setschedparam (pthread_t __target_thread, int __policy,  const struct sched_param *__param);
#endif  /* pthread.h */