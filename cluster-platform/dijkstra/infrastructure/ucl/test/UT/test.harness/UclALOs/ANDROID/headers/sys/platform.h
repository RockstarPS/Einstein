#ifndef __PLATFORM_H_INCLUDED
#define __PLATFORM_H_INCLUDED

//#ifndef __TARGET_NTO_H_INCLUDED
#include <sys/target_nto.h>
//#endif

#define _INT32		int//platform.h

typedef int _sigset_t;
typedef _sigset_t sigset_t;

typedef unsigned	_Sizet;//compiler_gnu.h
#endif