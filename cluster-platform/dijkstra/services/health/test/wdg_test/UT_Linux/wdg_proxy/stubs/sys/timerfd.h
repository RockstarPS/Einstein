
#ifndef _SYS_TIMERFD_H
#define _SYS_TIMERFD_H

#define __SI_MAX_SIZE   128
#if __WORDSIZE == 64
# define __SI_PAD_SIZE   ((__SI_MAX_SIZE / sizeof (int)) - 4)
#else
# define __SI_PAD_SIZE   ((__SI_MAX_SIZE / sizeof (int)) - 3)
#endif

#define __SIGEV_MAX_SIZE   64
#if __WORDSIZE == 64
# define __SIGEV_PAD_SIZE   ((__SIGEV_MAX_SIZE / sizeof (int)) - 4)
#else
# define __SIGEV_PAD_SIZE   ((__SIGEV_MAX_SIZE / sizeof (int)) - 3)
#endif

# define CLOCK_MONOTONIC            2

union sigval
{
  int sival_int;
  void *sival_ptr;
};

/* #include <bits/types/__sigval_t.h> */
typedef union sigval __sigval_t;

typedef struct
{
    int si_signo;    /* Signal number.  */
    int si_code;
    int si_errno;

#if __WORDSIZE == 64
    int __pad0;      /* Explicit padding.  */
#endif

    union
    {
      int _pad[__SI_PAD_SIZE];
    } _sifields;
} siginfo_t;
 
 /* Structure to transport application-defined values with signals.  */
typedef struct sigevent
{
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
    {
        int _pad[__SIGEV_PAD_SIZE];
    }_sigev_un;
} sigevent_t;

/* #include bits/sigaction.h */
#define _SIGSET_NWORDS (1024 / (8 * sizeof (unsigned long int)))
typedef struct
{
  unsigned long int __val[_SIGSET_NWORDS];
} __sigset_t;

/* Type of a signal handler.  */
typedef void (*__sighandler_t) (int);

/* Bits in `sa_flags'.  */
#define	SA_NOCLDSTOP  1   /* Don't send SIGCHLD when children stop.  */
#define SA_NOCLDWAIT  2   /* Don't create zombie on child death.  */
#define SA_SIGINFO    4   /* Invoke signal-catching function with

/* `sigev_notify' values.  */
enum
{
  SIGEV_SIGNAL = 0,      /* Notify via signal.  */
# define SIGEV_SIGNAL    SIGEV_SIGNAL
  SIGEV_NONE,           /* Other notification: meaningless.  */
# define SIGEV_NONE	SIGEV_NONE
  SIGEV_THREAD,         /* Deliver via thread creation.  */
# define SIGEV_THREAD   SIGEV_THREAD

  SIGEV_THREAD_ID = 4   /* Send signal to specific thread.
                        This is a Linux extension.  */
#define SIGEV_THREAD_ID SIGEV_THREAD_ID
};

/* Structure describing the action to be taken when a signal arrives.  */
struct sigaction
{
    /* Signal handler.  */
    union
    {
        /* Used if SA_SIGINFO is not set.  */
        __sighandler_t sa_handler;
        /* Used if SA_SIGINFO is set.  */
        void (*sa_sigaction) (int, siginfo_t *, void *);
    }__sigaction_handler;
    # define sa_handler __sigaction_handler.sa_handler
    # define sa_sigaction __sigaction_handler.sa_sigaction

    /* Additional set of signals to be blocked.  */
    __sigset_t sa_mask;

    /* Special flags.  */
    int sa_flags;

    /* Restore handler.  */
    void (*sa_restorer) (void);
};

/* #include <time.h>*/
typedef int timer_t;

typedef int clockid_t;

struct timespec {
        long tv_sec;
        long tv_nsec;
};

/* POSIX.1b structure for timer start values and intervals.  */
struct itimerspec
{
    struct timespec it_interval;
    struct timespec it_value;
};

/* Create new per-process timer using CLOCK_ID.  */
int timer_create (clockid_t __clock_id,
                  struct sigevent *__restrict __evp,
                  timer_t *__restrict __timerid);

/* Delete timer TIMERID.  */
int timer_delete (timer_t __timerid);

/* Set timer TIMERID to VALUE, returning old value in OVALUE.  */
int timer_settime (timer_t __timerid, int __flags,
       const struct itimerspec *__restrict __value,
       struct itimerspec *__restrict __ovalue);

/* #include sys/timerfd.h */
/* Return file descriptor for new interval timer source.  */
int timerfd_create (int __clock_id, int __flags);

/* Set next expiration time of interval timer source UFD to UTMR.  If
   FLAGS has the TFD_TIMER_ABSTIME flag set the timeout value is
   absolute.  Optionally return the old expiration time in OTMR.  */
int timerfd_settime (int __ufd, int __flags,
                const struct itimerspec *__utmr,
                struct itimerspec *__otmr);

/* #include signal.h */
/* Return number of available real-time signal with highest priority.  */
int __libc_current_sigrtmin (void);
/* Return number of available real-time signal with lowest priority.  */
int __libc_current_sigrtmax (void);

#define SIGRTMIN        (__libc_current_sigrtmin ())
#define SIGRTMAX        (__libc_current_sigrtmax ())

/* #include signal.h */
/* Clear all signals from SET.  */
int sigemptyset (sigset_t *__set) ;

/* Get and/or set the action for signal SIG.  */
int sigaction (int __sig, const struct sigaction *__restrict __act,
               struct sigaction *__restrict __oact );
#endif