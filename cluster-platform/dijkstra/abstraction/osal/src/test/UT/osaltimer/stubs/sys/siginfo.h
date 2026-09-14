/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable license fees to QNX
 * Software Systems before you may reproduce, modify or distribute this software,
 * or any work that includes all or part of this software.   Free development
 * licenses are available for evaluation and non-commercial purposes.  For more
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *
 * This file may contain contributions from others.  Please review this entire
 * file for other proprietary rights or license notices, as well as the QNX
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 * $
 */


#ifndef __SIGINFO_H_INCLUDED
#define __SIGINFO_H_INCLUDED

typedef struct pthread_attr_t_ * pthread_attr_t;

#if defined(__CLOCK_T)
typedef __CLOCK_T	clock_t;
#undef __CLOCK_T
#endif

#if defined(__TIME_T)
typedef __TIME_T	time_t;
#undef __TIME_T
#endif

#if defined(__PID_T)
typedef __PID_T		pid_t;
#undef __PID_T
#endif

#if defined(__UID_T)
typedef __UID_T		uid_t;
#undef __UID_T
#endif

#if defined(__PTHREAD_ATTR_T)
#if defined(__TIMESPEC_INTERNAL)
__TIMESPEC_INTERNAL;
#undef __TIMESPEC_INTERNAL
#endif
#if defined(__SCHED_PARAM_INTERNAL)
__SCHED_PARAM_INTERNAL;
#undef __SCHED_PARAM_INTERNAL
#endif
typedef __PTHREAD_ATTR_T	pthread_attr_t;
#undef __PTHREAD_ATTR_T
#endif

#define SIGEV_NONE_32			0	/* notify */
#define SIGEV_SIGNAL_32			1	/* notify, signo, value */
#define SIGEV_SIGNAL_CODE_32	2	/* notify, signo, value, code */
#define SIGEV_SIGNAL_THREAD_32	3	/* notify, signo, value, code */
#define SIGEV_PULSE_32			4	/* notify, coid, priority, code, value */
#define SIGEV_UNBLOCK_32		5	/* notify */
#define SIGEV_INTR_32			6	/* notify */
#define SIGEV_THREAD_32			7	/* notify, notify_function, notify_attributes */
#define SIGEV_MEMORY_32			8	/* notify, address, value, op */

#define SIGEV_64BIT				0x80

#define SIGEV_NONE_64 			(SIGEV_64BIT|SIGEV_NONE_32)
#define SIGEV_SIGNAL_64 		(SIGEV_64BIT|SIGEV_SIGNAL_32)
#define SIGEV_SIGNAL_CODE_64 	(SIGEV_64BIT|SIGEV_SIGNAL_CODE_32)
#define SIGEV_SIGNAL_THREAD_64 	(SIGEV_64BIT|SIGEV_SIGNAL_THREAD_32)
#define SIGEV_PULSE_64 			(SIGEV_64BIT|SIGEV_PULSE_32)
#define SIGEV_UNBLOCK_64 		(SIGEV_64BIT|SIGEV_UNBLOCK_32)
#define SIGEV_INTR_64 			(SIGEV_64BIT|SIGEV_INTR_32)
#define SIGEV_THREAD_64 		(SIGEV_64BIT|SIGEV_THREAD_32)
#define SIGEV_MEMORY_64 		(SIGEV_64BIT|SIGEV_MEMORY_32)


	#define SIGEV_SIGNAL 		(SIGEV_SIGNAL_64)
	#define SIGEV_SIGNAL_CODE 	(SIGEV_SIGNAL_CODE_64)
	#define SIGEV_SIGNAL_THREAD (SIGEV_SIGNAL_THREAD_64)
	#define SIGEV_PULSE 		(SIGEV_PULSE_64)
	#define SIGEV_UNBLOCK 		(SIGEV_UNBLOCK_64)
	#define SIGEV_INTR 			(SIGEV_INTR_64)
	#define SIGEV_THREAD 		(SIGEV_THREAD_64)
	#define SIGEV_MEMORY 		(SIGEV_MEMORY_64)




union sigval {
    int         sival_int;
    void       *sival_ptr;
};



struct sigevent {
	int				sigev_notify;
	union {
		int				__sigev_signo;
		int				__sigev_coid;
		int				__sigev_id;
		void			(*__sigev_notify_function)(union sigval);
		volatile unsigned	*__sigev_addr;
		unsigned		__sigev_handle;
	}				__sigev_un1;
	union sigval	sigev_value;
	union {
		struct {
			short			__sigev_code;
			short			__sigev_priority;
		} __st;
		pthread_attr_t	*__sigev_notify_attributes;
		int				__sigev_memop;
	}				__sigev_un2;
};
/* <STAN_MACRO1, STAN_MACRO5> */
# define sigev_signo			__sigev_un1.__sigev_signo
# define sigev_coid				__sigev_un1.__sigev_coid
# define sigev_id				__sigev_un1.__sigev_id
# define sigev_notify_function	__sigev_un1.__sigev_notify_function
# define sigev_addr				__sigev_un1.__sigev_addr
# define sigev_handle			__sigev_un1.__sigev_handle

# define sigev_notify_attributes	__sigev_un2.__sigev_notify_attributes
# define sigev_code					__sigev_un2.__st.__sigev_code
# define sigev_priority				__sigev_un2.__st.__sigev_priority
# define sigev_memop				__sigev_un2.__sigev_memop
/* </STAN_MACRO1, STAN_MACRO5> */
#endif
