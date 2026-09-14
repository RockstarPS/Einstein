#ifndef	_TIME_H_
#define	_TIME_H_

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif

#define SIGEV_THREAD			7	/* notify, notify_function, notify_attributes *///siginfo.h
#define CLOCK_MONOTONIC            2 // time.h

# ifndef __int32 //_mingw.g
#  define __int32 long
# endif

#ifndef _TIME32_T_DEFINED//MinGW/include/sys/types
typedef __int32 __time32_t;
#define _TIME32_T_DEFINED
#endif

typedef	__time32_t time_t; //MinGW/include/sys/types

#if defined(__TIMER_T)  //time.h
typedef __TIMER_T   timer_t;
#undef __TIMER_T
#endif

#if defined(__CLOCKID_T)
typedef __CLOCKID_T clockid_t;
#undef __CLOCKID_T
#endif

//struct sigevent; /* for C++ */
#if 1
struct timespec {
	long	tv_sec;		/* seconds */
	long	tv_nsec;	/* and nanoseconds */
};
#endif
#if 1
struct itimerspec {
    struct timespec it_value, it_interval;
	//struct timespec it_value;// it_interval;
    };
#endif

#if 0

/*
 * Used to define time specifications.
 */
#undef __TIMESPEC_DEF //target_nto.h
#define __TIMESPEC_DEF(__name, __pref) \
	struct __name {						\
	    time_t	__pref##_sec;	\
	    long			__pref##_nsec;	\
    }

#undef	__TIMESPEC
#define __TIMESPEC	__TIMESPEC_DEF(timespec, tv)
#undef	__TIMESPEC_INTERNAL
#define	__TIMESPEC_INTERNAL	__TIMESPEC_DEF(__timespec, __tv)


#undef __SCHED_PARAM_DEF
#if defined(__EXT_QNX) || defined(__EXT_POSIX1_200112)
#define __SCHED_PARAM_DEF(__name, __ts, __pref) \
	struct __name { \
		_INT32	__pref##_priority; \
		_INT32	__pref##_curpriority; \
		union {	\
			_INT32	__reserved[8]; \
			struct {	\
				_INT32	__ss_low_priority;	\
				_INT32	__ss_max_repl;	\
				struct __ts	__ss_repl_period;	\
				struct __ts	__ss_init_budget;	\
			}			__ss;	\
		}			__ss_un;	\
	}
	#define __sched_ss_low_priority	__ss_un.__ss.__ss_low_priority
	#define __sched_ss_max_repl		__ss_un.__ss.__ss_max_repl
	#define __sched_ss_repl_period	__ss_un.__ss.__ss_repl_period
	#define __sched_ss_init_budget	__ss_un.__ss.__ss_init_budget
#else
#define __SCHED_PARAM_DEF(__name, __ts, __pref) \
	struct __name { \
		_INT32	__pref##_priority; \
		_INT32	__pref##_curpriority; \
		_INT32	__spare[8]; \
	}
#endif

#undef	__SCHED_PARAM_INTERNAL
#define	__SCHED_PARAM_INTERNAL	__SCHED_PARAM_DEF(__sched_param, __timespec,__sched)
#undef	__SCHED_PARAM_T
#define	__SCHED_PARAM_T	__SCHED_PARAM_DEF(sched_param, timespec, sched)

/*
 * Used to define thread creation attributes.
 */
#undef __PTHREAD_ATTR_T
#define __PTHREAD_ATTR_T \
	struct _thread_attr { \
		int							__flags; \
		_Sizet						__stacksize; \
		void						*__stackaddr; \
		void						(*__exitfunc)(void *__status); \
		int							__policy; \
		struct __sched_param		__param; \
		unsigned					__guardsize; \
		unsigned					__prealloc; \
		int							__spare[2]; \
	}

#if defined(__PTHREAD_ATTR_T) //siginfo.h
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

#endif

union sigval {//siginfo.h
    int         sival_int;
    void       *sival_ptr;
};

struct sigevent {//siginfo.h
    int                             sigev_notify;
    union {
            int                     __sigev_signo;
            int                     __sigev_coid;
            int                     __sigev_id;
            void                    (*__sigev_notify_function)(union sigval);
            volatile unsigned       *__sigev_addr;
    } __sigev_un1;

# define sigev_signo                __sigev_un1.__sigev_signo
# define sigev_coid                 __sigev_un1.__sigev_coid
# define sigev_id                   __sigev_un1.__sigev_id
# define sigev_notify_function      __sigev_un1.__sigev_notify_function
# define sigev_addr                 __sigev_un1.__sigev_addr

    union sigval                    sigev_value;

    union {
            struct {
                    short           __sigev_code;
                    short           __sigev_priority;
            } __st;
            pthread_attr_t          *__sigev_notify_attributes;
            int                     __sigev_memop;
        } __sigev_un2;

# define sigev_notify_attributes    __sigev_un2.__sigev_notify_attributes
# define sigev_code                 __sigev_un2.__st.__sigev_code
# define sigev_priority             __sigev_un2.__st.__sigev_priority
# define sigev_memop                __sigev_un2.__sigev_memop
};  
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp);
extern int timer_create(clockid_t __clock_id, struct sigevent *__evp, timer_t *__timerid);
extern int timer_delete(timer_t __timerid);
extern int timer_settime(timer_t __timerid, int __flags, const struct itimerspec *__value, struct itimerspec *__ovalue);
#endif