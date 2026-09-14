#ifndef	_TIME_H_
#define	_TIME_H_

#define CLOCK_MONOTONIC            2

typedef int clockid_t;

struct timespec {
	long	tv_sec;		/* seconds */
	long	tv_nsec;	/* and nanoseconds */
};

extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp);

#endif