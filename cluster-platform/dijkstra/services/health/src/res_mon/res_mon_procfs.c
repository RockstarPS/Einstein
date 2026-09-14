/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <sys/slog2.h>
#include <sys/stat.h>
#include <sys/procfs.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include "debug.h"

#define PROC_PATH_MAX    (128U)
#define PROC_CMD_MAX     (1024U)
#define MAX_CPUS         (32U)
#define MAX_SEGMENTS     (16384U)
#define MAX_PROCESS      (1024U)
#define MAX_IRQS         (1024U)

static char as_name[PROC_PATH_MAX];
static char cmd_name[PROC_PATH_MAX];
static char cmdline[PROC_CMD_MAX];
static char irq_str[MAX_SEGMENTS];
static procfs_mapinfo membufs [MAX_SEGMENTS];
static procfs_irq irqs [MAX_IRQS] = { 0 };

static void ResMonProcFs_CpuInfo ( )
{
    char           as_name[PROC_PATH_MAX];
    int32_t        as_fd;
    procfs_status  status = {0};
    int32_t        num_cpus = _syspage_ptr->num_cpu;
    int32_t        i;
    int32_t        ret;
    uint64_t       now = 0;

    ret = snprintf ( as_name, PROC_PATH_MAX, "/proc/1/as" );
    if ( 0 > ret )
    {
        LOGI ( "%s", "snprintf failed" );
    }
    /* Log number of CPUs */
    LOGI ( "CPU: %d",  num_cpus );

    if ( ( as_fd = open ( as_name, O_RDONLY ) ) != -1 )
    {
        for( i = 0; i < num_cpus; i++ )
        {
            /* Each CPU has a Idle thread starting from TID 1 */
            status.tid = i + 1;
            if( ClockTime_r ( CLOCK_MONOTONIC, NULL, &now ) != EOK )
            {
                LOGE ( "%s", "ClockTime_r Failed" );
            }
            /* Log CPU Idle thread times */
            if ( devctl ( as_fd, DCMD_PROC_TIDSTATUS, &status, sizeof ( status ), NULL ) == EOK )
            {
                LOGI ( "CPU-%d: %lu, %lu", i, now, status.sutime );
            }
        }
        close( as_fd );
    }
}

static void ResMonProcFs_MemInfo( )
{
    struct asinfo_entry *entries = SYSPAGE_ENTRY ( asinfo );
    size_t count = SYSPAGE_ENTRY_SIZE( asinfo ) / sizeof( struct asinfo_entry );
    char *strings = SYSPAGE_ENTRY(strings)->data;
    uint64_t total = 0;
    size_t i;
    struct stat stat_info;

    /* Calculate total memory */
    for ( i = 0; i < count; i++ )
    {
        struct asinfo_entry *entry = &entries[i];
        if ( strncmp( strings + entry->name, "ram", 3U ) == 0 )
        {
            total += entry->end - entry->start + 1;
        }
    }
    /* Find used memory and Log */
    if ( stat ( "/proc", &stat_info ) != -1 )
    {
        LOGI ( "MEM: %lu, %lu", total, stat_info.st_size );
    }
}

static void ResMonProcFs_ProcessInfo( int32_t pid )
{
    int32_t        as_fd;
    int32_t        cmd_fd;
    procfs_info    info = { 0 };
    int32_t        i;
    uint64_t       now = 0;
    int32_t        nmembuf = 0;
    int32_t        stack_sz = 0;
    int32_t        text_sz = 0;
    int32_t        data_sz = 0;
    int32_t        nirqs = 0;
    uint32_t       offset;
    int32_t        ret = 0;
    int64_t        size = 0;

    /* Initialize Buffers */
    memset( as_name, 0, sizeof ( as_name ) );
    memset( cmd_name, 0, sizeof ( cmd_name ) );
    memset( cmdline, 0, sizeof ( cmdline ) );

    /* Prepare path names */
    ret = snprintf( as_name, PROC_PATH_MAX, "/proc/%d/as", pid );
    if ( 0 > ret )
    {
        LOGE ( "%s", "snprintf failed" );
    }

    ret = snprintf( cmd_name, PROC_PATH_MAX, "/proc/%d/cmdline", pid );
    if ( 0 > ret )
    {
        LOGE ( "%s", "snprintf failed" );
    }

    /* Read command like to get the process name */
    if ( ( cmd_fd = open ( cmd_name, O_RDONLY ) ) != -1 )
    {
        if ( ( size = read ( cmd_fd, cmdline, sizeof ( cmdline ) ) ) <= 0 )
        {
            LOGE ( "Cannot read %s", cmd_name );
        }
        (void) size;
        close( cmd_fd );
    }
    else
    {
        LOGE ( "Cannot open %s", cmd_name );
    }

    /* Get process metrics */
    if ( ( as_fd = open ( as_name, O_RDONLY ) ) != -1 )
    {
        if ( ClockTime_r ( CLOCK_MONOTONIC, NULL, &now ) != EOK )
        {
            LOGE ( "%s", "ClockTime_r Failed" );
        }
        if ( devctl ( as_fd, DCMD_PROC_INFO, &info, sizeof ( info ), NULL ) != EOK )
        {
            LOGE ( "%s", "DCMD_PROC_INFO failed" );
        }
        if ( devctl ( as_fd, DCMD_PROC_PAGEDATA, membufs, sizeof ( membufs ), &nmembuf ) != EOK )
        {
            LOGE ( "%s", "DCMD_PROC_PAGEDATA failed" );
        }
        if ( devctl ( as_fd, DCMD_PROC_IRQS, irqs, sizeof (irqs), &nirqs) != EOK )
        {
            LOGE ( "%s", "DCMD_PROC_IRQS failed" );
        }
        close( as_fd );
    }
    else
    {
        LOGE ( "Cannot open %s", as_name );
    }

    /* Get memory metrics */
    if ( MAX_SEGMENTS > nmembuf )
    {
        for ( i = 0; i < nmembuf; i++ )
        {
            if ( ( membufs[i].flags & MAP_STACK ) == MAP_STACK )
            {
                if ( ( membufs[i].flags & PG_HWMAPPED ) == PG_HWMAPPED )
                {
                    stack_sz += membufs[i].size;
                }
                else
                {
                    // Unallocated stack
                }
            }
            else if ( ( membufs[i].flags & PROT_EXEC ) == PROT_EXEC )
            {
                text_sz += membufs[i].size;
            }
            else if ( ( membufs[i].flags & (PROT_READ | PROT_WRITE ) ) == ( PROT_READ | PROT_WRITE ) )
            {
                data_sz += membufs[i].size;
            }
            else if ( ( membufs[i].flags & PROT_READ) == PROT_READ )
            {
                text_sz += membufs[i].size;
            }
            else
            {
                data_sz += membufs[i].size;
            }
        }
    }
    else
    {
    	LOGE ( "nmembuf exceeds allocated size %d", nmembuf );
    }

    /* Get IRQ Info */
    if ( MAX_IRQS > nirqs )
    {
        memset(irq_str, 0, MAX_SEGMENTS);
        offset = 0;
        ret = snprintf( irq_str, MAX_SEGMENTS, "%d", nirqs);
        if ( 0 > ret )
        {
            LOGE ( "%s", "snprintf failed" );
        }
        for( i = 0; i < nirqs; i++ )
        {
            offset = strnlen(irq_str, MAX_SEGMENTS);
        	ret = snprintf( &irq_str[offset], (size_t) ( MAX_SEGMENTS - offset ), ", %u", irqs[i].vector);
            if ( 0 > ret )
            {
                LOGE ( "%s", "snprintf failed" );
            }
        }
    }
    else
    {
    	LOGE ( "nirqs exceeds allocated size %d", nirqs );
    }

    /* Log per process data */
	LOGI ( "PID-%d: %s: %d, %d, %d, %d, %d: %lu, %lu, %lu, %lu: %d, %d, %d: %s", pid, cmdline,
			info.num_threads, info.num_timers, info.num_fdcons, info.num_chancons, nirqs,
			now, info.start_time, info.stime, info.utime,
			stack_sz, text_sz, data_sz,
			irq_str);
}

void ResMonProcfs_Log( void )
{
    struct dirent   *dirent;
    DIR             *dir;
    int32_t          pid;
    int64_t          value;

    /* Log CPU Info */
    ResMonProcFs_CpuInfo ( );
    /* Log Memory Info */
    ResMonProcFs_MemInfo ( );
    /* Open proc fs */
    dir = opendir ( "/proc" );
    if( dir != NULL )
    {
        /* Iterate over the processes */
        while ( ( dirent = readdir ( dir ) ) )
        {
            if ( isdigit ( *dirent -> d_name ) )
            {
                /* Get PID */
                value = (int32_t) strtol ( dirent -> d_name, NULL, 10 );
                if ( INT_MIN < value && INT_MAX > value )
                {
                    pid = value;

                    /* Log per-process info */
                    ResMonProcFs_ProcessInfo( pid );
                }
            }
        }
        closedir ( dir );
    }
    else
    {
        LOGE ( "%s", "couldn't open /proc" );
    }
}
