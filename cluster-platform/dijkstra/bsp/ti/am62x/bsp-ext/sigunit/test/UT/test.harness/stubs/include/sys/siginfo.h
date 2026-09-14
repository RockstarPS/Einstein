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
#define __SIGINFO_H_DECLARED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif
#include <sys/qnxtypes.h>
#include <sys/types.h>

#define SIGEV_PULSE_32			4	/* notify, coid, priority, code, value */
#define SIGEV_64BIT				0x80
#define SIGEV_PULSE_64 			(SIGEV_64BIT|SIGEV_PULSE_32)

#define SIGEV_PULSE 		(SIGEV_PULSE_64)
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



# define SIGEV_PULSE_INIT(__e, __f, __p, __c, __v)	\
	((__e)->sigev_notify = SIGEV_PULSE,				\
	 (__e)->sigev_coid = (__f),						\
	 (__e)->sigev_priority = (__p),					\
	 (__e)->sigev_value.sival_ptr = (void *)(_Uintptrt)(__v),	\
	 (__e)->sigev_code = (__c))

# define SIGEV_PULSE_INT_INIT(__e, __f, __p, __c, __v)	\
	((__e)->sigev_notify = SIGEV_PULSE | SIGEV_FLAG_SIVAL_INT,	\
	 (__e)->sigev_coid = (__f),						\
	 (__e)->sigev_priority = (__p),					\
	 (__e)->sigev_value.sival_int = (int)(__v),		\
	 (__e)->sigev_code = (__c))

# define SIGEV_PULSE_PTR_INIT(__e, __f, __p, __c, __v)	\
	((__e)->sigev_notify = SIGEV_PULSE,				\
	 (__e)->sigev_coid = (__f),						\
	 (__e)->sigev_priority = (__p),					\
	 (__e)->sigev_value.sival_ptr = (void *)(_Uintptrt)(__v),			\
	 (__e)->sigev_code = (__c))


# define SIGEV_TYPE_MASK		0x000000ff
# define SIGEV_FLAG_OVERDRIVE	0x00000200
# define SIGEV_FLAG_UPDATEABLE	0x00000400
# define SIGEV_FLAG_SIVAL_INT	0x00000800
# define SIGEV_FLAG_NOQUEUE		0x00001000 //do not queue the pulse if no server to handle it.
# define SIGEV_FLAG_HANDLE		0x00002000
# define SIGEV_FLAG_CODE_UPDATEABLE	0x00004000

#define SIGEV_INVALID_HANDLE	0xffffffffU


typedef struct  {
	int				si_signo;
	int				si_code;		/* if SI_NOINFO, only si_signo is valid */
	int				si_errno;
	union {
		int				__pad[7];
		struct {
			pid_t			__pid;
			union {
				struct {
					uid_t			__uid;
					union sigval	__value;
				}				__kill;		/* si_code <= 0 SI_FROMUSER */
			}				__pdata;
		}				__proc;
		struct {
			int				__fltno;
			void			*__fltip;
			void			*__addr;
			int				__bdslot;
		}				__fault;				/* si_signo=SIGSEGV,ILL,FPE,TRAP,BUS */
	}				__data;
}				siginfo_t;
/* <STAN_MACRO1, STAN_MACRO5> */
#define si_pid		__data.__proc.__pid
#define si_value	__data.__proc.__pdata.__kill.__value
#define si_uid		__data.__proc.__pdata.__kill.__uid
#define si_fltno	__data.__fault.__fltno
#define si_trapno	si_fltno
#define si_addr		__data.__fault.__addr
#define si_fltip	__data.__fault.__fltip
#define si_bdslot	__data.__fault.__bdslot
/* </STAN_MACRO1, STAN_MACRO5> */
#endif

