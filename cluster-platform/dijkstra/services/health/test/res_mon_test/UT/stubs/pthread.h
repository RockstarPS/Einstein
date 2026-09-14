#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED

#define PTHREAD_CREATE_DETACHED     (1)
#define EOK              0  /* No error */ 

typedef int pthread_t;
typedef int pthread_attr_t;

int pthread_attr_init( pthread_attr_t *attr );
int pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate );
int pthread_cancel (pthread_t thread);
int pthread_create( pthread_t* thread, const pthread_attr_t* attr,void* (*start_routine)(void* ), void* arg );

#endif
