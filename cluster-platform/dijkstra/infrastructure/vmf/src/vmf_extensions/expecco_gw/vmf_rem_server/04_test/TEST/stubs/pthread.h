
#ifndef _PTHREAD_H_
#define _PTHREAD_H_

#include "os_types.h"

#define PTHREAD_RESULT_OK           (EOK)
#define PTHREAD_RESULT_ERROR        (-1)

#define PTHREAD_MUTEX_INITIALIZER   (0)
#define PTHREAD_CREATE_DETACHED     (1)
#define PTHREAD_STACK_LAZY          (2)
#define PTHREAD_MUTEX_NORMAL        (3)
#define CLOCK_REALTIME              (4)

typedef int pthread_mutex_t;
typedef int pthread_t;
typedef int pthread_attr_t;
typedef int pthread_mutexattr_t;

void set_pthread_result (unsigned16 tmp_pthread_result);
signed16 pthread_mutex_lock( pthread_mutex_t* mutex );
signed16 pthread_mutex_unlock( pthread_mutex_t* mutex );
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
#endif

