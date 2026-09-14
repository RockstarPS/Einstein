
/*
 *  qnxtypes.h    Non-portable low-level IO definitions
 *

 */

#ifndef QNXTYPES_H_
#define QNXTYPES_H_
#include <stdint.h>
typedef  int32_t uid_t;
typedef  int32_t gid_t;
typedef int32_t		pid_t;
typedef uint64_t		ino_t;
typedef uint32_t		dev_t;
typedef int clockid_t;
typedef uint32_t mode_t;

#define __ITIMER \
		{	\
			uint64_t					nsec;	\
			uint64_t					interval_nsec;	\
		}

struct _itimer __ITIMER;

#endif

