
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/procfs.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <ha/ham.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>

#include "dk_logger.h"
#include "wdg_proxy.h"
#include "wdg_proxy_comm_if.h"
#include "wdg_proxy_cfg.h"

#define PCODE_HB_MISS_LOW      (_PULSE_CODE_MINAVAIL + 1)
#define PCODE_HB_MISS_HIGH     (_PULSE_CODE_MINAVAIL + 2)
#define PCODE_DEATH            (_PULSE_CODE_MINAVAIL + 3)
#define PCODE_TIMER            (_PULSE_CODE_MINAVAIL + 4)

#define PCODE_VALUE_OFFSET     (100)

#ifdef WDG_PROXY_HEALTH_EVENT
#define WP_FATAL_ERR_DELAY_MS  (100)
#endif

#define WP_TASK_PERIODICITY_MS (200)
#define WP_MS_TO_NS            (1000000)

#define WP_SLM_START           (0U)
#define WP_SLM_STOP            (1U)

#define WP_PROCESS_UNKNOWN_ST  (0U)
#define WP_PROCESS_HEALTHY_ST  (1U)
#define WP_PROCESS_STARTED_ST  (2U)
#define WP_PROCESS_STOPPED_ST  (3U)
#define WP_PROCESS_ERROR_ST    (4U)

#ifndef WP_UNKNOWN_ST_TMO_MS
#define WP_UNKNOWN_ST_TMO_MS   (1000U)
#endif

#define WP_MAX_SLM_RESP_LEN    (8192U)

#define WP_FATAL_CODE_LOW_MEMORY       (250)
#define WP_FATAL_CODE_HIGH_CPULOAD     (251)

#if defined(HEALTH_FT)
#define SLM_PATH "/tmp/slm"
#else
#define SLM_PATH "/dev/slm"
#endif

#define PROC_PATH "/proc"

static int32_t WdgProxy_StartEventTimer ( void );
static int32_t WdgProxy_StopEventTimer ( void );
static void    WdgProxy_RunEventTimer ( void );
static int32_t WdgProxy_SetupHAM ( uint8_t idx );
static ham_entity_t *WdgProxy_Attach ( uint8_t idx );
static int32_t WdgProxy_RequestSLM ( const char *pProcessName, uint8_t slm_action );
static int32_t WdgProxy_ReportFatalError ( uint8_t idx );
static void    WdgProxy_ProcessEvent ( int8_t event, int32_t data );
static void WdgProxy_MonitorMemory ( void );
static void WdgProxy_MonitorCPU ( void );
static int32_t WdgProxy_createDelayTimer(void);
static int32_t WdgProxy_startDelayTimer(long int time_ns);
static int32_t WdgProxy_deleteDelayTimer(void);
static void WdgProxy_ReportFatalError_hdlr(int32_t signum);
static int32_t WdgProxy_CheckProcessExitedInSLM(const char *pProcessName );
static int32_t WdgProxy_IsNumeric(const char *str);
static const char* WdgProxy_ExtractFilename(const char* path);

static int32_t chid;
static int32_t coid;
static timer_t timer_id;
static int32_t msg_timer_cnt;
static bool fatal_error;
static timer_t delay_timerID;

typedef struct
{
    char name[_POSIX_PATH_MAX];
    bool isHbEnabled;
    uint8_t hbLowMissAction;
    uint8_t hbHighMissAction;
    uint8_t deathAction;
    uint8_t maxRestartCount;
} ProcessMonitorListCfg_t;

typedef struct
{
    uint8_t  state;
    uint8_t  restartCount;
    uint32_t stateTimer;
    uint8_t event;
    uint8_t health_event_sent;
} ProcessMonitorData_t;

typedef struct
{
    uint64_t ts;
    uint64_t sutime;
} CpuLoadSnapshot_t;

#ifdef UNIT_TEST

static ProcessMonitorListCfg_t ProcessMonitorList[PROCESS_MONITOR_LIST_SIZE] =
{
    PROCESS_MONITOR_LIST
};

#else

static const ProcessMonitorListCfg_t ProcessMonitorList[PROCESS_MONITOR_LIST_SIZE] =
{
    PROCESS_MONITOR_LIST
};

#endif

static CpuLoadSnapshot_t CpuLoadSnapshotPrev[WP_MAX_CPUS] = { 0 };
static ProcessMonitorData_t ProcessMonitorData[PROCESS_MONITOR_LIST_SIZE] = { 0 };

/* coverity[MISRA C-2012 Directive 8.5 violation] : FALSE */
LOG_IMPORT_CONTEXT( gWPLogContext );

int8_t WdgProxy_onInit ( void )
{
    int8_t retval = WP_FAIL;

    if ( access ( "/proc/ham", F_OK ) == 0 )
    {
        ( void ) ham_connect ( 0 );

        retval = WP_OK;
    }
    else
    {
        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
        LOGE ( &gWPLogContext, "/proc/ham unavailable" );
    }

    return retval;
}

int8_t WdgProxy_onStart ( void )
{
    uint8_t idx;
    int32_t ret_value = WP_FAIL;

    chid = ChannelCreate ( 0 );

    if ( 0 <= chid )
    {
        coid = ConnectAttach ( 0, 0, chid, _NTO_SIDE_CHANNEL, 0 );

        if ( 0 <= coid )
        {
            for ( idx = 0U; ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE ); idx++ )
            {
                ProcessMonitorData[idx].restartCount = 0U;
                ProcessMonitorData[idx].state = WP_PROCESS_UNKNOWN_ST;
                ProcessMonitorData[idx].stateTimer = WP_UNKNOWN_ST_TMO_MS;
                ProcessMonitorData[idx].health_event_sent = FALSE;
            }

            ret_value = WdgProxy_StartEventTimer();
        }
        else
        {
            ( void ) ChannelDestroy ( chid );

            if ( __get_errno_ptr() != NULL )
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE ( &gWPLogContext, "ConnectAttach Failed : %s", strerror ( errno ) );
            }
        }
    }
    else
    {
        if ( __get_errno_ptr() != NULL )
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "ChannelCreate Failed : %s", strerror ( errno ) );
        }

    }


    /* Initialize IPC Communication Channel */
    if ( WP_OK == ret_value )
    {
        fatal_error = FALSE;
        msg_timer_cnt = WDG_VMF_MSG_PERIODICITY;

        ( void ) WdgProxyCommIf_Init();
    }

    /*Create delay timer*/
    if( WP_OK == ret_value )
    {
        ret_value = WdgProxy_createDelayTimer();
    }

    return (int8_t)ret_value;
}

int8_t WdgProxy_onStop ( void )
{
    int8_t ret_onStop = WP_OK;
    int8_t idx =0;
    ( void ) WdgProxyCommIf_Shutdown();
    ( void ) WdgProxy_StopEventTimer();
    ( void ) WdgProxy_deleteDelayTimer();

    for ( idx = 0U; ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE ); idx++ )
    {
        const ProcessMonitorListCfg_t *pCfg = &ProcessMonitorList[idx];

        if ( 0 != ( ham_detach_name ( ND_LOCAL_NODE, pCfg->name, 0 )))
        {
            LOGE( &gWPLogContext, "ham_detach_name Failed for %s:", pCfg->name);
        }
    }
    ( void ) ConnectDetach ( coid );
    ( void ) ChannelDestroy ( chid );

    return ret_onStop;
}

int8_t WdgProxy_onShutdown ( void )
{
    int8_t ret_onShutdown = WP_OK;

    ( void ) ham_disconnect ( 0 );

    return ret_onShutdown;
}

void    WdgProxy_worker ( void )
{
    int32_t rcvid;
    struct _pulse pulse = {};
    int32_t data;

    rcvid = MsgReceivePulse ( chid, &pulse, sizeof ( pulse ), NULL );

    if ( rcvid < 0 )
    {
        if ( __get_errno_ptr() != NULL )
        {
            if ( errno != EINTR )
            {
                //TODO: Handle properly
            }
        }
    }
    else
    {
        if ( PCODE_TIMER == pulse.code )
        {
            data = 0;
        }
        else
        {
            data = ( int32_t ) ( pulse.value.sival_int - ( int32_t ) PCODE_VALUE_OFFSET );
        }
        /* coverity[MISRA C-2012 Directive 2.2 violation] : FALSE */
        WdgProxy_MonitorMemory ( );
        WdgProxy_MonitorCPU ( );
        WdgProxy_ProcessEvent ( pulse.code, data );
    }
}

static void  WdgProxy_RunEventTimer ( void )
{
    uint8_t idx;
    int32_t ret_RunEventTimer = WP_FAIL;
    const ProcessMonitorListCfg_t *pCfg;
    ProcessMonitorData_t *pData;

    for ( idx = 0U; ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE ); idx++ )
    {
        pCfg = &ProcessMonitorList[idx];
        pData = &ProcessMonitorData[idx];

        if ( ( WP_PROCESS_UNKNOWN_ST == pData->state ) || ( WP_PROCESS_STARTED_ST == pData->state ) )
        {
            ret_RunEventTimer = WdgProxy_SetupHAM ( idx );

            if ( ret_RunEventTimer == WP_OK )
            {
                pData->state = WP_PROCESS_HEALTHY_ST;
                pData->stateTimer = 0U;
            }
            else
            {
                if ( pData->stateTimer > 0U )
                {
                    pData->stateTimer -= (uint32_t)WP_TASK_PERIODICITY_MS;
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGI ( &gWPLogContext, "WdgProxy_SetupHAM failed %d, retrying...", idx );
                }
                else
                {
                    ret_RunEventTimer = WdgProxy_ReportFatalError ( idx );
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGE ( &gWPLogContext, "WdgProxy_SetupHAM failed %d", idx );
                }
            }
        }
        else if ( WP_PROCESS_STOPPED_ST == pData->state )
        {
            /*Check process is properly exited */
            if(WP_OK == WdgProxy_CheckProcessExitedInSLM(pCfg->name))
            {
                if ( ProcessMonitorData[idx].restartCount < pCfg->maxRestartCount )
                {
                    ret_RunEventTimer = WdgProxy_RequestSLM ( pCfg->name, WP_SLM_START );

                    if ( ret_RunEventTimer == WP_OK )
                    {
                        pData->state = WP_PROCESS_STARTED_ST;
                        pData->stateTimer = WP_UNKNOWN_ST_TMO_MS;
                        ProcessMonitorData[idx].restartCount++;
#ifdef WDG_PROXY_HEALTH_EVENT
                        (void)WdgProxyCommIF_SendHealthEvent(idx, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
                        pData->event = WP_RESTART_EVENT_TYPE_UNKNOWN;
#endif
                        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                        LOGI ( &gWPLogContext, "%s: Restart Counter %d / %d", pCfg->name, ProcessMonitorData[idx].restartCount, pCfg->maxRestartCount );
                    }
                    else
                    {
                        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                        LOGE ( &gWPLogContext, "WdgProxy_RestartProcess %d", idx );
                    }
                }
                else
                {
                    ret_RunEventTimer = WdgProxy_ReportFatalError ( idx );
                }
            }
            else
            {
                if ( pData->stateTimer > 0U )
                {
                    pData->stateTimer -= (uint32_t)WP_TASK_PERIODICITY_MS;
                    /* Retry again */
                    //(void) WdgProxy_RequestSLM ( pCfg->name, WP_SLM_STOP);
                }
                else
                {
                    ret_RunEventTimer = WdgProxy_ReportFatalError ( idx );
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGE ( &gWPLogContext, "Process stop failed %d", idx );
                }
            }
        }
        else if ( WP_PROCESS_HEALTHY_ST == pData->state )
        {
            /* Process Healthy. Do Nothing */
        }
        else if ( WP_PROCESS_ERROR_ST == pData->state )
        {
            ret_RunEventTimer = WdgProxy_ReportFatalError ( idx );
        }
        else
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "Unknown State %d for %s", pData->state, pCfg->name );
        }
    }

    /* Process HB VMF Message */
    msg_timer_cnt -= ( int32_t ) WP_TASK_PERIODICITY_MS;

    if ( msg_timer_cnt <= 0 )
    {
        if ( FALSE == fatal_error )
        {
            /* Send healthy heartbeat */
            ( void ) WdgProxyCommIf_SendHeartbeat();
        }
        else
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "Fatal error: Skipping heartbeat to VIP" );
        }

        /* Reload timer */
        msg_timer_cnt = WDG_VMF_MSG_PERIODICITY;
    }
}

static void WdgProxy_ProcessEvent ( int8_t event, int32_t data )
{
    int32_t ret_ProcessEvent = WP_FAIL;
    ProcessMonitorData_t *pData;
    const ProcessMonitorListCfg_t *pCfg;

    if ( data < (int32_t)PROCESS_MONITOR_LIST_SIZE )
    {
        pData = &ProcessMonitorData[data];
        pCfg = &ProcessMonitorList[data];

        switch ( event )
        {
        case PCODE_HB_MISS_LOW:
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "Heart beat Miss Low for %d", data );

            pData->event = WP_RESTART_EVENT_TYPE_LOW_HB_MISS;

            switch ( pCfg->hbLowMissAction )
            {
            case WP_ACTION_RESTART:
            {
                ret_ProcessEvent = WdgProxy_RequestSLM ( pCfg->name, WP_SLM_STOP );

                if ( ret_ProcessEvent == WP_OK )
                {
                    pData->state = WP_PROCESS_STOPPED_ST;
                }
                else
                {
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGE ( &gWPLogContext, "WdgProxy_RequestSLM %d", data );
                    ( void ) WdgProxy_ReportFatalError ( (uint8_t)data );
                }

            }
            break;

            case WP_ACTION_FATAL:
                ( void ) WdgProxy_ReportFatalError ( (uint8_t)data );
                break;

            default:
            {
                /*Do nothing*/
            }
            break;
            }

            break;

        case PCODE_HB_MISS_HIGH:
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "Heart beat Miss High for %d", data );

            pData->event = WP_RESTART_EVENT_TYPE_HIGH_HB_MISS;

            switch ( pCfg->hbHighMissAction )
            {
            case WP_ACTION_RESTART:
            {
                ret_ProcessEvent = WdgProxy_RequestSLM ( pCfg->name, WP_SLM_STOP );

                if ( ret_ProcessEvent == WP_OK )
                {
                    pData->state = WP_PROCESS_STOPPED_ST;
                }
                else
                {
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGE ( &gWPLogContext, "WdgProxy_RequestSLM %d", data );
                    ( void ) WdgProxy_ReportFatalError ( (uint8_t)data );
                }

            }
            break;

            case WP_ACTION_FATAL:
                ( void ) WdgProxy_ReportFatalError ( (uint8_t)data );
                break;

            default:
            {
                /*Do nothing*/
            }
            break;
            }

            break;

        case PCODE_DEATH:
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "Process death for %d", data );

            pData->event = WP_RESTART_EVENT_TYPE_DEATH;

            (void) WdgProxyCommIf_PackageDLTLogs();

            switch ( pCfg->deathAction )
            {
            case WP_ACTION_RESTART:
                pData->state = WP_PROCESS_STOPPED_ST;
                break;

            case WP_ACTION_FATAL:
                ( void ) WdgProxy_ReportFatalError ( (uint8_t)data );
                break;

            default:
            {
                /*Do nothing*/
            }
            break;
            }

            break;

        case PCODE_TIMER:
            WdgProxy_RunEventTimer();
            break;

        default:
        {
            /*Do nothing*/
        }
        break;
        }
    }
}

static int32_t WdgProxy_SetupHAM ( uint8_t idx )
{
    int8_t ret_SetupHAM = WP_FAIL;
    ham_entity_t *ehdl;
    ham_condition_t *chdl;
    ham_action_t *ahdl;
    pid_t pid;

    if ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE )
    {
        const ProcessMonitorListCfg_t *pCfg = &ProcessMonitorList[idx];

        pid = getpid();

        if ( TRUE == pCfg->isHbEnabled )
        {
            ehdl = ham_entity_handle ( ND_LOCAL_NODE, pCfg->name, 0 );
        }
        else
        {
            ehdl = WdgProxy_Attach ( idx );
        }

        if ( NULL != ehdl )
        {
            if ( TRUE == pCfg->isHbEnabled )
            {
                /* Setup Heart beat miss high condition */
                chdl = ham_condition ( ehdl, CONDHBEATMISSEDHIGH, "hb-miss-high",
                                       ( (uint16_t)HCONDNOWAIT | (uint16_t)HCONDINDEPENDENT | (uint16_t)HREARMAFTERRESTART ) );

                if ( NULL != chdl )
                {
                    ahdl = ham_action_notify_pulse ( chdl, "pulse", ND_LOCAL_NODE, pid,
                                                     chid, PCODE_HB_MISS_HIGH, ( PCODE_VALUE_OFFSET + (int32_t)idx ), HREARMAFTERRESTART );

                    if ( NULL != ahdl )
                    {
                        ( void ) ham_action_handle_free ( ahdl );
                    }
                    else
                    {
                        if ( __get_errno_ptr() != NULL )
                        {
                            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                            LOGE ( &gWPLogContext, "ham_action_notify_pulse Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                        }
                    }

                    ( void ) ham_condition_handle_free ( chdl );
                }
                else
                {
                    if ( __get_errno_ptr() != NULL )
                    {
                        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                        LOGE ( &gWPLogContext, "ham_condition Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                    }
                }

                /* Setup Heart beat miss low condition */
                chdl = ham_condition ( ehdl, CONDHBEATMISSEDLOW, "hb-miss-low",
                                       ( (uint16_t)HCONDNOWAIT | (uint16_t)HCONDINDEPENDENT | (uint16_t)HREARMAFTERRESTART ) );

                if ( NULL != chdl )
                {
                    ahdl = ham_action_notify_pulse ( chdl, "pulse", ND_LOCAL_NODE, pid,
                                                     chid, PCODE_HB_MISS_LOW, ( PCODE_VALUE_OFFSET + (int32_t)idx ), HREARMAFTERRESTART );

                    if ( NULL != ahdl )
                    {
                        ( void ) ham_action_handle_free ( ahdl );
                    }
                    else
                    {
                        if ( __get_errno_ptr() != NULL )
                        {
                            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                            LOGE ( &gWPLogContext, "ham_action_notify_pulse Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                        }
                    }

                    ( void ) ham_condition_handle_free ( chdl );
                }
                else
                {
                    if ( __get_errno_ptr() != NULL )
                    {
                        if ( EEXIST != errno )
                        {
                            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                            LOGE ( &gWPLogContext, "ham_condition Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                        }
                        else
                        {
                            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                            LOGI ( &gWPLogContext, "ham_condition Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                        }
                    }
                }
            }

            /* Setup Process death condition */
            chdl = ham_condition ( ehdl, CONDDEATH, "death",
                                   ( (uint16_t)HCONDNOWAIT | (uint16_t)HCONDINDEPENDENT | (uint16_t)HREARMAFTERRESTART ) );

            if ( NULL != chdl )
            {
                ahdl = ham_action_notify_pulse ( chdl, "pulse", ND_LOCAL_NODE, pid,
                                                 chid, PCODE_DEATH, ( PCODE_VALUE_OFFSET + ( int32_t ) idx ), HREARMAFTERRESTART );

                if ( NULL != ahdl )
                {
                    ( void ) ham_action_handle_free ( ahdl );
                }
                else
                {
                    if ( __get_errno_ptr() != NULL )
                    {
                        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                        LOGE ( &gWPLogContext, "ham_action_notify_pulse Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                    }
                }

                ( void ) ham_condition_handle_free ( chdl );
            }
            else
            {
                if ( __get_errno_ptr() != NULL )
                {
                    /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                    LOGE ( &gWPLogContext, "ham_condition Failed for %s :  %s", pCfg->name, strerror ( errno ) );
                }
            }

            ret_SetupHAM = WP_OK;
        }
        else
        {
            if ( __get_errno_ptr() != NULL )
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE ( &gWPLogContext, "ham_entity_handle Failed for %s :  %s", pCfg->name, strerror ( errno ) );
            }
        }
    }
    return ret_SetupHAM;
}

static int32_t WdgProxy_IsNumeric(const char *str)
{
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}

static const char* WdgProxy_ExtractFilename(const char* path)
{
    const char* last_slash = strrchr(path, '/');
    if (last_slash)
    {
        return last_slash + 1;  // return everything after the last '/'
    }
    else
    {
        return path;  // no slash found, whole path is the filename
    }
}

static int32_t WdgProxy_GetPID_Of( const char *name )
{
    int32_t procNum = -1;
    DIR *proc_dir;
    struct dirent *entry;
    char path[4096];
    struct stat st;
    FILE *fp;
    char process_path[4096];
    const char *process_name;

    proc_dir = opendir(PROC_PATH);

    if (proc_dir != NULL)
    {
        do
        {
            entry = readdir(proc_dir);
            if(entry != NULL)
            {
                snprintf(path, sizeof(path), "%s/%s", PROC_PATH, entry->d_name);
                if ((stat(path, &st) == 0) && (S_ISDIR(st.st_mode) != 0) && (WdgProxy_IsNumeric(entry->d_name) != 0))
                {
                    snprintf(path, sizeof(path), "%s/%s/cmdline", PROC_PATH, entry->d_name);
                    fp = fopen(path, "r");
                    if (fp != NULL)
                    {
                        if (fgets(process_path, sizeof(process_path), fp))
                        {
                            process_path[strcspn(process_path, "\n")] = '\0'; // Strip newline
                            process_name = WdgProxy_ExtractFilename(process_path);

                            LOGD ( &gWPLogContext, "Comparing %s and %s", name, process_name);
                            if((name != NULL) && (process_name != NULL))
                            {
                                if(0U == strcmp(name, process_name))
                                {
                                    procNum = atoi(entry->d_name);
                                    LOGD ( &gWPLogContext, "Found match %s, PID : %d", name, procNum);
                                }
                            }
                        }
                        fclose(fp);
                    }
                }
            }
        }
        while (entry != NULL);
        closedir(proc_dir);
    }
    else
    {
        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
        LOGE ( &gWPLogContext, "Unable to open %s", PROC_PATH);
    }

    /* coverity[MISRA C-2012 Directive 15.5 violation] : FALSE */
    return procNum;
}

static ham_entity_t *WdgProxy_Attach ( uint8_t idx )
{

    ham_entity_t *ehdl = NULL;
    int32_t procNum = -1;

    if ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE)
    {
        const ProcessMonitorListCfg_t *pCfg = &ProcessMonitorList[idx];

        procNum = WdgProxy_GetPID_Of ( pCfg->name );
        if ( procNum < 0 )
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "Process is not running. Starting %s", pCfg->name);
            /* Following request is a blocking function. It can blocks for a while
             * if the process depend from some other slow process. */
            if ( WP_FAIL == WdgProxy_RequestSLM ( pCfg->name, WP_SLM_START ) )
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE ( &gWPLogContext, "Couldn't start %s", pCfg->name);

                /* coverity[MISRA C-2012 Directive 15.5 violation] : FALSE */
                return NULL;
            }
            procNum = WdgProxy_GetPID_Of ( pCfg->name );
        }
        if ( -1 != procNum )
        {
            /* Attempt to attach using handle */
            ehdl = ham_entity_handle ( ND_LOCAL_NODE, pCfg->name, 0 );

            if ( NULL == ehdl )
            {
                if ( __get_errno_ptr() != NULL )
                {
                    LOGI ( &gWPLogContext,"ham_entity_handle Failed for %s : errno=%d: %s",
                           pCfg->name, errno, strerror ( errno ) );
                }

                /* Process is running attach to it using pid */
                ehdl = ham_attach ( pCfg->name, ND_LOCAL_NODE, procNum, NULL, 0 );
                if (NULL == ehdl)
                {
                    if ( __get_errno_ptr() != NULL )
                    {
                        LOGE ( &gWPLogContext,"ham_attach Failed for %s PID=%d: errno=%d: %s",
                               pCfg->name, procNum, errno, strerror ( errno ) );
                    }
                }
                else
                {
                    LOGI ( &gWPLogContext, "ham_attach Success for %s PID=%d.",
                           pCfg->name, procNum );
                }
            }
        }
        else
        {
            LOGE ( &gWPLogContext, "Process %s is not running. Can't attach to it!", pCfg->name);

            ehdl = NULL;
        }
    }

    /* coverity[MISRA C-2012 Directive 15.5 violation] : FALSE */
    return ehdl;
}

static int32_t WdgProxy_RequestSLM ( const char *pProcessName, uint8_t slm_action )
{
    int32_t ret_RequestSLM = WP_FAIL;
    int32_t slm_fd;
    char cmd[_POSIX_PATH_MAX];
    char res[WP_MAX_SLM_RESP_LEN];
    ssize_t wb;

    slm_fd = open ( SLM_PATH, O_RDWR );

    if ( slm_fd >= 0 )
    {
        ( void ) memset ( cmd, 0, _POSIX_PATH_MAX );
        ( void ) memset ( res, 0, WP_MAX_SLM_RESP_LEN );

        switch ( slm_action )
        {
        case WP_SLM_START:
            /* coverity[MISRA C-2012 Directive 21.6 violation] : FALSE */
            (void)snprintf ( cmd, _POSIX_PATH_MAX, "start %s", pProcessName );
            break;

        case WP_SLM_STOP:
            /* coverity[MISRA C-2012 Directive 21.6 violation] : FALSE */
            (void)snprintf ( cmd, _POSIX_PATH_MAX, "stop %s", pProcessName );
            break;

        default:
        {
            /*Do nothing*/
        }
        break;

        }

        /* Execute the Command */
        do
        {
            if ( __get_errno_ptr() != NULL )
            {
                errno = EOK;
            }
            wb = write ( slm_fd, cmd, strnlen ( cmd, _POSIX_PATH_MAX ) );
        }
        while ( -1 == wb && (int)EBUSY == errno );
        if ( -1 == wb )
        {
            if ( ( ENOENT == errno ) && ( WP_SLM_STOP == slm_action ) )
            {
                /* It isn't an error. */
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGI (&gWPLogContext, "The process %s is already dead", pProcessName );
            }
            else
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE (&gWPLogContext, "Write to /dev/slm failed" );

                if ( __get_errno_ptr() != NULL )
                {
                    LOGE (&gWPLogContext, "For ps:%s write to slm failed with: %s", pProcessName, strerror ( errno ) );
                }

                ( void ) close ( slm_fd );
                /* coverity[MISRA C-2012 Directive 15.5 violation] : FALSE */
                return ret_RequestSLM;
            }
        }

        ( void ) close ( slm_fd );

        if ( (WP_SLM_START == slm_action) )
        {
            if ( -1 != WdgProxy_GetPID_Of ( pProcessName ) )
            {
                ret_RequestSLM = WP_OK;
            }
            else
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE (&gWPLogContext, "Process %s haven't started", pProcessName);
            }
        }
        else if ( (WP_SLM_STOP == slm_action) )
        {
            ret_RequestSLM = WP_OK;
        }
        else
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE (&gWPLogContext, "Unknown action for %s", pProcessName);
        }
    }
    else
    {
        LOGE (&gWPLogContext, "unavailable when trying to restart" );
        if ( __get_errno_ptr() != NULL )
        {
            LOGE (&gWPLogContext, "slm unavailable when trying to restart %s :  %s", pProcessName, strerror ( errno ) );
        }
    }

    /* coverity[MISRA C-2012 Directive 15.5 violation] : FALSE */
    return ret_RequestSLM;
}

static int32_t WdgProxy_ReportFatalError ( uint8_t idx )
{

    int32_t ret_ReportFatalError = WP_OK;

    if ( idx < (uint8_t)PROCESS_MONITOR_LIST_SIZE )
    {
        const ProcessMonitorListCfg_t *pCfg =  &ProcessMonitorList[idx];
        ProcessMonitorData_t *pData = &ProcessMonitorData[idx];

        LOGE ( &gWPLogContext, "WP FATAL ERROR FOR %s", pCfg->name );

        pData->state = WP_PROCESS_ERROR_ST;
        fatal_error = TRUE;

#ifdef WDG_PROXY_HEALTH_EVENT
        if(pData->health_event_sent == FALSE)
        {
            ret_ReportFatalError = WdgProxyCommIF_SendHealthEvent(idx, WP_RECORD_TYPE_FATAL_ERROR, pData->event, pData->restartCount);
            pData->health_event_sent = TRUE;
            if(WP_OK == ret_ReportFatalError)
            {
                ret_ReportFatalError = WdgProxy_startDelayTimer(WP_FATAL_ERR_DELAY_MS * WP_MS_TO_NS);
            }
        }
        else
        {
            ret_ReportFatalError = WdgProxyCommIf_SendFatalError ( ( uint32_t ) idx );
        }
#else
        ret_ReportFatalError = WdgProxyCommIf_SendFatalError ( ( uint32_t ) idx );
#endif
    }
    else
    {
        ret_ReportFatalError = WP_FAIL;
    }
    return ret_ReportFatalError;
}

static int32_t WdgProxy_StartEventTimer ( void )
{
    int32_t ret_StartEventTimer = WP_FAIL;
    int32_t prio;
    struct sigevent         event = {0};
    struct sched_param      scheduling_params = {0};
    struct itimerspec       itime;

    if ( -1 != SchedGet ( 0, 0, &scheduling_params ) )
    {
        prio = scheduling_params.sched_priority;
    }
    else
    {
        prio = 10;
    }
    /* coverity[MISRA C-2012 Directive 10.1 violation] : FALSE */
    event.sigev_notify = SIGEV_PULSE;
    event.sigev_coid = coid;
    event.sigev_priority = (int16_t)prio;
    event.sigev_code = PCODE_TIMER;

    if ( -1 != timer_create ( CLOCK_MONOTONIC, &event, &timer_id ) )
    {
        ret_StartEventTimer = WP_OK;
    }
    else
    {
        ret_StartEventTimer = WP_FAIL;

        if ( __get_errno_ptr() != NULL )
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "timer_create failed: %s", strerror ( errno ) );

        }
    }

    if ( WP_OK == ret_StartEventTimer )
    {
        itime.it_value.tv_sec = 0;
        itime.it_value.tv_nsec = ( WP_TASK_PERIODICITY_MS * WP_MS_TO_NS );
        itime.it_interval.tv_sec = 0;
        itime.it_interval.tv_nsec = ( WP_TASK_PERIODICITY_MS * WP_MS_TO_NS );

        if ( -1 != timer_settime ( timer_id, 0, &itime, NULL ) )
        {
            ret_StartEventTimer = WP_OK;
        }
        else
        {
            ret_StartEventTimer = WP_FAIL;

            if ( __get_errno_ptr() != NULL )
            {
                LOGE ( &gWPLogContext, "timer_create failed: %s", strerror ( errno ) );
            }
        }
    }

    return ret_StartEventTimer;
}

static int32_t WdgProxy_StopEventTimer ( void )
{
    int32_t ret_StopEventTimer;

    if ( -1 != timer_delete ( timer_id ) )
    {
        ret_StopEventTimer = WP_OK;
    }
    else
    {
        ret_StopEventTimer = WP_FAIL;

        if ( __get_errno_ptr() != NULL )
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "timer_delete failed: %s", strerror ( errno ) );
        }
    }

    return ret_StopEventTimer;
}

static int32_t WdgProxy_CheckProcessExitedInSLM(const char *pProcessName )
{
    int32_t ret = WP_OK;
    int32_t slm_fd;
    char cmd[_POSIX_PATH_MAX];
    char res[WP_MAX_SLM_RESP_LEN];
    ssize_t wb;
    char *token;

    slm_fd = open ( SLM_PATH, O_RDWR );

    if ( slm_fd >= 0 )
    {
        /* Run command to get active components */
        ( void ) memset ( cmd, 0, _POSIX_PATH_MAX );
        ( void ) memset ( res, 0, WP_MAX_SLM_RESP_LEN );

        ( void ) snprintf ( cmd, _POSIX_PATH_MAX, "active" );
        do
        {
            if ( __get_errno_ptr() != NULL )
            {
                errno = EOK;
            }
            wb = write ( slm_fd, cmd, strnlen ( cmd, _POSIX_PATH_MAX ) );
        }
        while ( -1 == wb && (int)EBUSY == errno );
        if ( -1 == wb )
        {
            LOGE (&gWPLogContext, "Write to /dev/slm failed" );

            if ( __get_errno_ptr() != NULL )
            {
                LOGE (&gWPLogContext, "For ps:%s write to slm failed with: %s", pProcessName, strerror ( errno ) );
            }

            ret = WP_FAIL;
        }

        if(ret == WP_OK)
        {
            uint64_t totalReadBytes = 0U;
            uint64_t readBytes;
            /*Read bytes*/
            do
            {
                readBytes = (uint64_t)read ( slm_fd, &res[totalReadBytes], ( WP_MAX_SLM_RESP_LEN - totalReadBytes -1U) );
                totalReadBytes += readBytes;
            }
            while ( ( readBytes > 0U ) && ( totalReadBytes < (WP_MAX_SLM_RESP_LEN - 1U) ));

            /* Verify the process in the read bytes*/
            if ( ( totalReadBytes > 0U ) && ( totalReadBytes <= ( WP_MAX_SLM_RESP_LEN - 1U ) ) )
            {
                /*explicitly add the null terminator at the end of the data in the res string*/
                res[totalReadBytes] = '\0';

                char *buf = res;
                while ((token = strsep(&buf, " \t\n")) != NULL)
                {
                    if (*token == '\0')
                    {
                        continue;  // skip empty
                    }
                    if (strcmp(token, pProcessName) == 0)
                    {
                        LOGE (&gWPLogContext, "Process is still active in slm %s", pProcessName);
                        ret = WP_FAIL;
                        break;

                    }
                }
            }
        }

        ( void ) close ( slm_fd );
    }

    return ret;
}

static void WdgProxy_MonitorCPU(void)
{
#if defined(WDG_FATAL_MAX_CPULOAD_PERCENT) && defined(WDG_WARN_MAX_CPULOAD_PERCENT)

    int32_t        as_fd;
    procfs_status  status = {0};
    uint64_t       now;
    uint64_t       now_diff;
    uint64_t       sutime_diff;
    uint16_t        num_cpus = _syspage_ptr->num_cpu;
    double         cpu_load_percent;
    double         total_cpu_load_percent = 0.0f;

    /* Throttle INFO logs to once per second */
    static uint64_t last_info_log_ts = 0;

    as_fd = open("/proc/1/as", O_RDONLY);
    if (as_fd < 0)
    {
        LOGE ( &gWPLogContext, "Open /proc/1/as Failed");
        return;
    }

    for(uint16_t i = 0; i < num_cpus; i++)
    {
        status.tid = (int32_t)(i + 1U);

        if(ClockTime_r ( CLOCK_MONOTONIC, NULL, &now ) == EOK )
        {
            /* Read CPU Idle thread times */
            if(devctl(as_fd, DCMD_PROC_TIDSTATUS, &status, sizeof (status), NULL) == EOK)
            {
                //LOGI ( "CPU-%d: %lu, %lu\n", i, now, status.sutime );
                if(CpuLoadSnapshotPrev[i].ts != 0ULL)
                {
                    now_diff   = (now >= CpuLoadSnapshotPrev[i].ts) ? (now - CpuLoadSnapshotPrev[i].ts) : 0ULL;
                    sutime_diff = (status.sutime >= CpuLoadSnapshotPrev[i].sutime) ? (status.sutime - CpuLoadSnapshotPrev[i].sutime) : 0ULL;
                    if(now_diff > 0ULL)
                    {
                        cpu_load_percent = (1.0 - ((double)sutime_diff / (double)now_diff)) * 100.0;
                        total_cpu_load_percent = total_cpu_load_percent + cpu_load_percent;
                    }
                   
                }

                CpuLoadSnapshotPrev[i].ts = now;
                CpuLoadSnapshotPrev[i].sutime = status.sutime;
            }
            else
            {
                LOGE (&gWPLogContext, "DCMD_PROC_TIDSTATUS - Failed ");
            }
        }
        else
        {
            LOGE (&gWPLogContext, "ClockTime_r Failed");
        }
    }
    
    total_cpu_load_percent = total_cpu_load_percent / (double)num_cpus;
    
    if( total_cpu_load_percent >= WDG_FATAL_MAX_CPULOAD_PERCENT )
    {
        LOGE ( &gWPLogContext, "CPU LOAD FATAL : %f percent", total_cpu_load_percent );
#ifdef WDG_FATAL_MAX_CPULOAD_NOTIFY
        fatal_error = TRUE;
        ( void ) WdgProxyCommIf_SendFatalError ( WP_FATAL_CODE_HIGH_CPULOAD );
#endif
    }
    else if( total_cpu_load_percent >= WDG_WARN_MAX_CPULOAD_PERCENT )
    {
        LOGW ( &gWPLogContext, "CPU LOAD WARN : %f percent", total_cpu_load_percent );
    }
    else
    {
        uint64_t curr_ts;
        
		/* Log Printed 1s once in the console */
       
        if (ClockTime_r(CLOCK_MONOTONIC, NULL, &curr_ts) == EOK)
        {
           if ((curr_ts - last_info_log_ts) >= 1000000000ULL)
           {
              LOGI(&gWPLogContext,  "CPU LOAD INFO : %.2f %%", total_cpu_load_percent);

              last_info_log_ts = curr_ts;
           }
        }
    }

   (void)close(as_fd);
#endif
}


static void WdgProxy_MonitorMemory ( void )
{
#if defined(WDG_FATAL_LOW_MEMORY_PERCENT) && defined(WDG_WARN_LOW_MEMORY_PERCENT)
    struct asinfo_entry *entries = SYSPAGE_ENTRY ( asinfo );
    size_t count = SYSPAGE_ENTRY_SIZE( asinfo ) / sizeof( struct asinfo_entry );
    char *strings = SYSPAGE_ENTRY(strings)->data;
    uint64_t total = 0;
    size_t i;
    struct stat stat_info;
    double percent = 0;
    static uint64_t last_info_log_time = 0;

    /* Calculate total memory */
    for ( i = 0; i < count; i++ )
    {
        struct asinfo_entry *entry = &entries[i];
        if ( strncmp( strings + entry->name, "ram", 3U ) == 0 )
        {
           total += (uint64_t)(entry->end - entry->start + 1U);
        }
    }
    /* Find used memory and calculate percentage */
    if ( stat ( "/proc", &stat_info ) != -1 )
    {
        if(total!=0ULL)
        {
            percent = ((double)stat_info.st_size * 100.0) / (double)total;
            if( percent <= WDG_FATAL_LOW_MEMORY_PERCENT )
            {
                LOGE ( &gWPLogContext, "MEM UTIL FATAL :  %.2f percent free", percent );
#ifdef WDG_FATAL_LOW_MEMORY_NOTIFY
                fatal_error = TRUE;
                ( void ) WdgProxyCommIf_SendFatalError ( WP_FATAL_CODE_LOW_MEMORY  );
#endif
            }
            else if( percent <= WDG_WARN_LOW_MEMORY_PERCENT)
            {
                LOGW ( &gWPLogContext, "MEM UTIL LOW :  %.2f percent free", percent );
            }
            else
            {
                uint64_t curr_time;
        
                /* Log Printed  1s once in the console */
       
                if (ClockTime_r(CLOCK_MONOTONIC, NULL, &curr_time) == EOK)
                {
                    if ((curr_time - last_info_log_time) >= 1000000000ULL)
                    {       
                         LOGI ( &gWPLogContext, "MEM UTIL NORMAL :  %.2f percent free", percent );
                         last_info_log_time = curr_time;
                    }
                }
            }
        }
        else
        {
            LOGE( &gWPLogContext,"TOTAL MEM IS DIVIDED BY ZERO");
        }
    }
#endif
}

static void WdgProxy_ReportFatalError_hdlr(int32_t signum)
{
    const ProcessMonitorData_t *pData = NULL;
    uint32_t idx;

    /*Touch unused variable*/
    (void)signum;

    for ( idx = 0U; ( idx < (uint32_t)PROCESS_MONITOR_LIST_SIZE ); idx++ )
    {
        pData = &ProcessMonitorData[idx];

        if ( WP_PROCESS_ERROR_ST == pData->state )
        {
            /*Send Fatal Error*/
            (void)WdgProxyCommIf_SendFatalError ( idx );
            break;
        }

    }

    /*Disable timer temporarily*/
    (void)WdgProxy_startDelayTimer(0);
}

static int32_t WdgProxy_createDelayTimer(void)
{
    struct sigevent event = {0};
    int32_t ret_createDelayTimer = WP_FAIL;
    /* coverity[MISRA C-2012 Directive 22.8 violation] : FALSE */
    if (SIG_ERR != signal((int)SIGUSR1, &WdgProxy_ReportFatalError_hdlr))
    {
        ret_createDelayTimer = WP_OK;
    }

    if(WP_OK == ret_createDelayTimer)
    {
        /* coverity[MISRA C-2012 Directive 10.1 violation] : FALSE */
        SIGEV_SIGNAL_INIT (&event, SIGUSR1);
        if(-1 != timer_create (CLOCK_MONOTONIC, &event, &delay_timerID))
        {
            ret_createDelayTimer = WP_OK;
        }
        else
        {
            ret_createDelayTimer = WP_FAIL;

            if ( __get_errno_ptr() != NULL )
            {
                /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
                LOGE ( &gWPLogContext, "100ms delay timer create failed: %s", strerror ( errno ) );
            }
        }
    }

    return ret_createDelayTimer;
}
/* coverity[MISRA C-2012 Directive 4.6 violation] : FALSE */
static int32_t WdgProxy_startDelayTimer(long int time_ns)
{
    int32_t ret_startDelayTimer = WP_FAIL;
    struct itimerspec itime;

    itime.it_value.tv_sec = 0;
    itime.it_value.tv_nsec = time_ns;
    itime.it_interval.tv_sec = 0;
    itime.it_interval.tv_nsec = 0;

    if(-1 != timer_settime(delay_timerID, 0, &itime, NULL))
    {
        ret_startDelayTimer = WP_OK;
    }
    else
    {
        if ( __get_errno_ptr() != NULL )
        {
            LOGE ( &gWPLogContext, "100ms delay timer set failed: %s", strerror ( errno ) );
        }
    }

    return ret_startDelayTimer;
}

static int32_t WdgProxy_deleteDelayTimer(void)
{
    int32_t ret_deleteDelayTimer;

    if(-1 != timer_delete ( delay_timerID ))
    {
        ret_deleteDelayTimer = WP_OK;
    }
    else
    {
        ret_deleteDelayTimer = WP_FAIL;

        if ( __get_errno_ptr() != NULL )
        {
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "100ms delay timer delete failed: %s", strerror ( errno ) );
        }
    }

    return ret_deleteDelayTimer;
}
