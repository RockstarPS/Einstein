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

#ifndef __NEUTRINO_H_INCLUDED
#define __NEUTRINO_H_INCLUDED


//#include <sched.h>
struct sched_param {
  int sched_priority;
};

//#include <signal.h>
#define SIGUSR1     16  /* user defined signal 1 */

#include <stdint.h>
#include <sys/types.h>
//#include <sys/siginfo.h>
//#include <time.h>

#define SIGEV_SIGNAL_32			1	/* notify, signo, value */

#define SIGEV_64BIT				0x80

#define SIGEV_SIGNAL_64 		(SIGEV_64BIT|SIGEV_SIGNAL_32)

#define SIGEV_SIGNAL 		(SIGEV_SIGNAL_64)

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
		int				__sigev_memop;
	}				__sigev_un2;
};
#define sigev_signo			__sigev_un1.__sigev_signo
#define sigev_coid				__sigev_un1.__sigev_coid
#define sigev_code					__sigev_un2.__st.__sigev_code
#define sigev_priority				__sigev_un2.__st.__sigev_priority

# define SIGEV_SIGNAL_INIT(__e, __s)			\
	((__e)->sigev_notify = SIGEV_SIGNAL,		\
	 (__e)->sigev_signo = (__s))

#define SIGEV_PULSE_32			4	/* notify, coid, priority, code, value */
#define SIGEV_64BIT				0x80
#define SIGEV_PULSE_64 			(SIGEV_64BIT|SIGEV_PULSE_32)

#define SIGEV_PULSE 		(SIGEV_PULSE_64)
typedef int   timer_t;
struct timespec;

struct timespec {
        long tv_sec;
        long tv_nsec;
};

struct itimerspec {
    struct timespec it_value,
                    it_interval;
    } ;
#define clockid_t   int 
    struct sigevent; /* for C++ */
extern int timer_create(clockid_t __clock_id, struct sigevent *__evp, timer_t *__timerid);
extern int timer_delete(timer_t __timerid);
extern int timer_settime(timer_t __timerid, int __flags, const struct itimerspec *__value, struct itimerspec *__ovalue);

/*
typedef  unsigned int timer_t;
struct itimerspec {
    struct timespec it_value,
                    it_interval;
    } ;
 */
# define CLOCK_MONOTONIC            2
#define _NTO_TCTL_IO					14
struct _pulse {
	uint16_t					type;
	uint16_t					subtype;
	int8_t						code;
	uint8_t					zero[3];
	union sigval				value;
	int32_t						scoid;
};

struct _msg_info64 {						/* _msg_info	_server_info */
	uint32_t					nd;			/*  client      server */
	uint32_t					srcnd;		/*  server      n/a */
	pid_t						pid;		/*	client		server */
	int32_t						tid;		/*	thread		n/a */
	int32_t						chid;		/*	server		server */
	int32_t						scoid;		/*	server		server */
	int32_t						coid;		/*	client		client */
	int16_t						priority;	/*	thread		n/a */
	int16_t						flags;		/*	n/a			client */
	int64_t					msglen;		/*	msg			n/a */
	int64_t					srcmsglen;	/*	thread		n/a */
	int64_t					dstmsglen;	/*	thread		n/a */
	uint32_t					type_id;	/*  client		server channel */
	uint32_t					reserved;
};

#define _msg_info	_msg_info64

#define _NTO_SIDE_CHANNEL		0x40000000
#define _PULSE_CODE_MINAVAIL	0	/* QNX managers will never use this range */
#define _PULSE_CODE_MAXAVAIL	127

extern int MsgReceivePulse(int __chid, void *__pulse, uint64_t __bytes, struct _msg_info *__info);
extern int ConnectAttach(uint32_t __nd, pid_t __pid, int __chid, unsigned __index, int __flags);
extern int ChannelCreate(unsigned __flags);
extern int ChannelDestroy(int __chid);
extern int ConnectDetach(int __coid);
extern int SchedGet(pid_t __pid, int __tid, struct sched_param *__param);
extern int ThreadCtl(int __cmd, void *__data);
extern int ChannelCreate(unsigned __flags);
//extern int TimerCreate(clockid_t __id, const struct sigevent *__notify);
//extern int TimerSettime(timer_t __id, int __flags, const struct _itimer *__itime, struct _itimer *__oitime);


#endif
