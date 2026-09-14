#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED

typedef struct pthread_attr_t_ * pthread_attr_t;
typedef struct pthread_mutex_t_ * pthread_mutex_t;
typedef unsigned long int pthread_t;

enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};

enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};

enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};

enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
       void *(*start_routine) (void *), void *arg);
int pthread_cancel (pthread_t __th);
int pthread_join (pthread_t __th, void **__thread_return);
void pthread_exit (void *__retval);
int pthread_setname_np (pthread_t __target_thread, const char *__name);
pthread_t pthread_self (void);
int pthread_setcancelstate (int __state, int *__oldstate);
int pthread_setcanceltype (int __type, int *__oldtype);

int sched_yield(void);
	   
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_setscope(pthread_attr_t *attr, int scope);
int pthread_attr_setdetachstate (pthread_attr_t *__attr,
                                        int __detachstate);
int pthread_attr_destroy (pthread_attr_t *__attr);

class __pthread_cleanup_class
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
 public:
  __pthread_cleanup_class (void (*__fct) (void *), void *__arg)
    : __cancel_routine (__fct), __cancel_arg (__arg), __do_it (1) { }
  ~__pthread_cleanup_class () { if (__do_it) __cancel_routine (__cancel_arg); }
  void __setdoit (int __newval) { __do_it = __newval; }
  void __defer () { pthread_setcanceltype (PTHREAD_CANCEL_DEFERRED,
                                           &__cancel_type); }
  void __restore () const { pthread_setcanceltype (__cancel_type, 0); }
};

#  define pthread_cleanup_push(routine, arg) \
  do {                                                                              \
    __pthread_cleanup_class __clframe (routine, arg)

#  define pthread_cleanup_pop(execute) \
    __clframe.__setdoit (execute);                                              \
  } while (0)

#endif
