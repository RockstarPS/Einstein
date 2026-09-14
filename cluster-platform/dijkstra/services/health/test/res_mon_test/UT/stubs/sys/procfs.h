#ifndef PROCFS_H
#define PROCFS_H

#include <sys/syspage.h>

typedef struct 
{
    int tid;
    int sutime
} procfs_status;

typedef struct
{
    uint32_t num_threads;
    uint32_t num_timers;
    uint32_t num_fdcons;
    uint32_t num_chancons;
    uint64_t start_time;
    uint64_t stime;
    uint64_t utime;
    
} procfs_info;

typedef struct
{
    uint32_t flags;
    uint64_t size; 
    
} procfs_mapinfo;

typedef struct
{
    uint64_t vector;
} procfs_irq;

#define DCMD_PROC_TIDSTATUS 0
#define DCMD_PROC_INFO 1
#define DCMD_PROC_PAGEDATA 2
#define DCMD_PROC_IRQS 3

#endif
