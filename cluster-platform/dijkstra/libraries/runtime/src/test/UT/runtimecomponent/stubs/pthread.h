#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED

typedef unsigned long int pthread_t;
int pthread_setname_np (pthread_t __target_thread, const char *__name);

#endif
