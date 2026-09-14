#ifndef __SCHED_H_INCLUDED
#define	__SCHED_H_INCLUDED

/* Scheduling algorithms.  */
#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2

struct sched_param {
  int sched_priority;
};
#endif