#ifndef __NEUTRINO_H_INCLUDED
#define __NEUTRINO_H_INCLUDED

#include <limits.h>
#include <time.h>
#include <pthread.h>

#define _NTO_TCTL_IO    14

extern int ThreadCtl(int __cmd, void *__data);
extern int ClockTime_r(clockid_t __id, const uint64_t *_new, uint64_t *__old);
extern int devctl( int filedes,
                   int dcmd,
                   void * dev_data_ptr,
                   size_t n_bytes,
                   int * dev_info_ptr ); 

#endif
