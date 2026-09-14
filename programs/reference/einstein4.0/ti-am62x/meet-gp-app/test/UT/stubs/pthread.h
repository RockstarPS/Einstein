

#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED

#include "stub_unistd.h"
typedef struct pthread_attr_t_ * pthread_attr_t;
typedef unsigned long int pthread_t;


int pthread_join (pthread_t __th, void **__thread_return);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
  void *(*start_routine) (void *), void *arg);


#  define pthread_cleanup_push(routine, arg) \
  do {                                                                              \
    __pthread_cleanup_class __clframe (routine, arg)

#  define pthread_cleanup_pop(execute) \
    __clframe.__setdoit (execute);                                              \
  } while (0)

#endif
