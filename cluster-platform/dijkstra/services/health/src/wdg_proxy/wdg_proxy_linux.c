
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
//
//     systemctl --version
//     systemd 250 (250.5+)
//     +PAM -AUDIT -SELINUX -APPARMOR +IMA -SMACK +SECCOMP -GCRYPT -GNUTLS -OPENSSL +ACL +BLKID -CURL -ELFUTILS -FIDO2 -IDN2 -IDN -IPTC +KMOD -LIBCRYPTSETUP +LIBFDISK -PCRE2 -PWQUALITY -P11KIT -QRENCODE -BZIP2 -LZ4 -XZ -ZLIB +ZSTD -BPF_FRAMEWORK +XKBCOMMON +UTMP +SYSVINIT default-hierarchy=hybrid
//
//     D-Bus interface of systemd --> https://www.freedesktop.org/software/systemd/man/latest/org.freedesktop.systemd1.html
//
//     dbus-daemon --version
//     D-Bus Message Bus Daemon 1.14.8
//     Copyright (C) 2002, 2003 Red Hat, Inc., CodeFactory AB, and others
//     This is free software; see the source for copying conditions.
//     There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
//---------------------------------------------------------------------------------------------------------------------

#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <systemd/sd-bus.h>
#include <sys/timerfd.h>
#include <poll.h>

#include "dk_logger.h"
#include "wdg_proxy.h"
#include "wdg_proxy_comm_if.h"
#include "wdg_proxy_cfg.h"

#define WP_TASK_PERIODICITY_MS     (100)
#define WP_MS_TO_NS                (1000000)
#define WP_PROCESS_UNKNOWN         (255U)

#define WP_PROCESS_UNKNOWN_ST  (0U)
#define WP_PROCESS_HEALTHY_ST  (1U)
#define WP_PROCESS_STARTED_ST  (2U)
#define WP_PROCESS_STOPPED_ST  (3U)
#define WP_PROCESS_ERROR_ST    (4U)
#define WP_PROCESS_INACTIVE_ST (5U)

#define WP_FD_INDEX_SD_BUS               (0U)
#define WP_FD_INDEX_EVENT_TIMER          (1U)
#define WP_MAX_EVENTS                    (2U)

#define WP_SD_PROCESS_CURR_STATE_ACTIVE          (0)
#define WP_SD_PROCESS_CURR_STATE_INACTIVE        (1)
#define WP_SD_PROCESS_CURR_STATE_FAILED          (2)
#define WP_SD_PROCESS_CURR_STATE_ACTIVATING      (3)
#define WP_SD_PROCESS_CURR_STATE_DEACTIVATING    (4)

#ifndef WP_UNKNOWN_ST_TMO_MS
#define WP_UNKNOWN_ST_TMO_MS   WP_TASK_PERIODICITY_MS
#endif

#define _cleanup_(f) __attribute__((cleanup(f)))
#define DESTINATION                     "org.freedesktop.systemd1"
#define PATH                            "/org/freedesktop/systemd1"
#define INTERFACE_PROPERITIES           "org.freedesktop.DBus.Properties"
#define INTERFACE_MANAGER               "org.freedesktop.systemd1.Manager"
#define INTERFACE_UNIT                  "org.freedesktop.systemd1.Unit"
#define INTERFACE_SERVICE               "org.freedesktop.systemd1.Service"
#define MEMBER_GET_UNIT                 "GetUnit"
#define MEMBER_GET                      "Get"
#define MEMBER_PROPERTIES_CHANGED       "PropertiesChanged"
#define MEMBER_ACTIVE_STATE             "ActiveState"
#define MEMBER_RESTART_USEC             "RestartUSec"
#define MEMBER_NRestarts                "NRestarts"

#define SERVICE_STATE_ACTIVE      "active"
#define SERVICE_STATE_ACTIVATING  "activating"
#define SERVICE_STATE_INACTIVE    "inactive"
#define SERVICE_STATE_DEACTIVE    "deactivating"
#define SERVICE_STATE_FAILED      "failed"

#define STRING_MAX_SIZE    (20U)
#define MATCH_RULE_SIZE    (_POSIX_PATH_MAX * 2)
#define INFINITE_TIMEOUT   (-1)



typedef struct
{
    uint32_t ExecMainPID;
    char Result[STRING_MAX_SIZE];
    char ActiveState[STRING_MAX_SIZE];
    char PrevActiveState[STRING_MAX_SIZE];
} ServiceProperity_t;

typedef struct
{
    char matchRule[MATCH_RULE_SIZE];
    char objPath[_POSIX_PATH_MAX];
} ServiceCfg_t;

typedef struct
{
    char processName[_POSIX_PATH_MAX];
    char serviceName[_POSIX_PATH_MAX];
    bool isWdgEnabled;
} ProcessMonitorListCfg_t;

typedef struct
{
    ServiceCfg_t serviceCfg;
    ServiceProperity_t serviceProperity;
    uint8_t state;
    uint8_t restartCount;
    uint8_t event;
    bool isWdgEnabled;
    bool health_event_sent;
    int32_t delay_timer;
    uint32_t stateTimer;
} ProcessMonitorData_t;

static int32_t WdgProxy_ReportFatalError ( const uint8_t idx );
static int32_t WdgProxy_StartEventTimer ( void );
static int32_t WdgProxy_StopEventTimer ( void );
static void  WdgProxy_RunEventTimer ( void );
static int8_t WdgProxy_SetupSdBusMatchRule ( const uint8_t idx );
static int8_t WdgProxy_GetCurrentState(const uint8_t index);
static int8_t WdgProxy_QuerySdBusProperity(const char* objPath, const char* interface,
        const char* member_to_query, uint64_t* result, char* str_result);
static uint8_t WdgProxy_ProcessSdBusMsg( sd_bus_message *msg );
static void WdgProxy_ProcessSDBUSEvent ( const uint8_t index );
static void WdgProxy_CheckProcessCurrState( const uint8_t idx );

static int32_t msg_timer_cnt;
static bool fatal_error;
static int32_t timer_fd;
static int32_t sd_bus_fd;

static struct pollfd fds[WP_MAX_EVENTS];

static sd_bus* bus = NULL;

static const ProcessMonitorListCfg_t ProcessMonitorList[PROCESS_MONITOR_LIST_SIZE] =
{
    PROCESS_MONITOR_LIST
};

static ProcessMonitorData_t ProcessMonitorData[PROCESS_MONITOR_LIST_SIZE];

LOG_IMPORT_CONTEXT( gWPLogContext );

int8_t WdgProxy_onInit ( void )
{
    int8_t ret = WP_OK;

    /*Connect to the session bus*/
    int32_t ret_sd = sd_bus_open_system(&bus);

    if ( 0 > ret_sd )
    {
        LOGE ( &gWPLogContext, "Failed to connect to the system bus: %s\n", strerror(-ret) );
        ret = WP_FAIL;
    }

    return ret;
}

int8_t WdgProxy_onStart ( void )
{
    int8_t ret = WP_OK;

    for(uint8_t process_idx = 0U; process_idx < PROCESS_MONITOR_LIST_SIZE; process_idx++)
    {
        ProcessMonitorData[process_idx].restartCount = 0U;
        ProcessMonitorData[process_idx].state = WP_PROCESS_UNKNOWN_ST;
        ProcessMonitorData[process_idx].event = WP_RESTART_EVENT_TYPE_UNKNOWN;
        ProcessMonitorData[process_idx].health_event_sent = FALSE;
        ProcessMonitorData[process_idx].delay_timer = WP_TASK_PERIODICITY_MS;
        ProcessMonitorData[process_idx].stateTimer = WP_UNKNOWN_ST_TMO_MS;
        strcpy(ProcessMonitorData[process_idx].serviceProperity.PrevActiveState, SERVICE_STATE_INACTIVE);

        if(WP_FAIL == WdgProxy_SetupSdBusMatchRule(process_idx))
        {
            LOGE ( &gWPLogContext, "Failed to setup match rule for the process : %d ", process_idx );
            ProcessMonitorData[process_idx].state = WP_PROCESS_ERROR_ST;
        }
    }


    /*Get file descriptor for the SD BUS*/
    sd_bus_fd = sd_bus_get_fd(bus);

    if(sd_bus_fd < 0)
    {
        LOGE ( &gWPLogContext, "Failed to get system bus file descriptor: %s ", strerror(-sd_bus_fd) );
        ret = WP_FAIL;
    }

    if( WP_OK == ret)
    {
        /*Start Event timer*/
        ret = WdgProxy_StartEventTimer();
    }

    if ( WP_OK == ret )
    {
        fds[WP_FD_INDEX_SD_BUS].fd = sd_bus_fd;
        fds[WP_FD_INDEX_SD_BUS].events = POLLIN;

        fds[WP_FD_INDEX_EVENT_TIMER].fd = timer_fd;
        fds[WP_FD_INDEX_EVENT_TIMER].events = POLLIN;

        fatal_error = FALSE;
        msg_timer_cnt = WDG_VMF_MSG_PERIODICITY;

        /* Initialize IPC Communication Channel */
        ret = WdgProxyCommIf_Init();
    }

    return ret;
}

int8_t WdgProxy_onStop ( void )
{
    int8_t ret = WP_FAIL;

    ret = WdgProxyCommIf_Shutdown();
    ( void ) WdgProxy_StopEventTimer();

    return ret;
}

int8_t WdgProxy_onShutdown ( void )
{
    /*Flush the all unread queued messages*/
    (void)sd_bus_flush(bus);

    /*Disconnects the bus connection*/
    sd_bus_close(bus);

    /*Unreference the bus object*/
    (void)sd_bus_unref(bus);

    return WP_OK;
}

void  WdgProxy_worker ( void )
{
    int ret;

    ret = poll(fds, WP_MAX_EVENTS, -1);
    if (ret < 0)
    {
        LOGE(&gWPLogContext, "poll failed: %s", strerror(errno));
    }

    /* sd-bus events */
    if (fds[WP_FD_INDEX_SD_BUS].revents & POLLIN)
    {
        sd_bus_message *msg = NULL;

        /* Drain ALL pending sd-bus messages */
        while ((ret = sd_bus_process(bus, &msg)) > 0)
        {
            if (msg)
            {
                uint8_t idx = WdgProxy_ProcessSdBusMsg(msg);
                WdgProxy_ProcessSDBUSEvent(idx);
                sd_bus_message_unref(msg);
                msg = NULL;
            }
        }

        if (ret < 0)
        {
            LOGE(&gWPLogContext, "sd_bus_process failed: %s", strerror(-ret));
        }
    }

    /* periodic timerfd */
    if (fds[WP_FD_INDEX_EVENT_TIMER].revents & POLLIN)
    {
        uint64_t expirations;
        ssize_t res = read(timer_fd, &expirations, sizeof(expirations));
        (void) res;
        WdgProxy_RunEventTimer();
    }

}

static void  WdgProxy_RunEventTimer ( void )
{
    uint8_t idx;
    const ProcessMonitorListCfg_t *pCfg;
    ProcessMonitorData_t *pData;

    for ( idx = 0U; ( idx < PROCESS_MONITOR_LIST_SIZE ); idx++ )
    {
        pCfg = &ProcessMonitorList[idx];
        pData = &ProcessMonitorData[idx];

        if ( WP_PROCESS_UNKNOWN_ST == pData->state )
        {
            WdgProxy_CheckProcessCurrState( idx );
        }
        else if( WP_PROCESS_STOPPED_ST == pData->state )
        {
            WdgProxy_CheckProcessCurrState( idx );
        }
        else if( WP_PROCESS_STARTED_ST == pData->state)
        {
            pData->state = WP_PROCESS_HEALTHY_ST;
        }
        else if ( WP_PROCESS_HEALTHY_ST == pData->state )
        {
            /* Do nothing */
        }
        else if ( WP_PROCESS_ERROR_ST == pData->state )
        {
            (void) WdgProxy_ReportFatalError ( idx );
        }
        else if(WP_PROCESS_INACTIVE_ST == pData->state)
        {
            WdgProxy_CheckProcessCurrState( idx);
        }
        else
        {
            LOGE ( &gWPLogContext, "Unknown State %d for %s", pData->state, pCfg->processName );
        }
    }

    /* Process HB VMF Message */
    msg_timer_cnt -= ( int32_t ) WP_TASK_PERIODICITY_MS;

    if ( 0 >= msg_timer_cnt )
    {
        if ( FALSE == fatal_error )
        {
            /* Send healthy heartbeat */
            ( void ) WdgProxyCommIf_SendHeartbeat();
        }
        else
        {
            LOGE ( &gWPLogContext, "Fatal error: Skipping heartbeat to VIP" );
        }

        /* Reload timer */
        msg_timer_cnt = WDG_VMF_MSG_PERIODICITY;
    }
}

static void WdgProxy_CheckProcessCurrState( const uint8_t idx )
{
    ProcessMonitorData_t *pData;
    const ProcessMonitorListCfg_t *pCfg;

    if( PROCESS_MONITOR_LIST_SIZE > idx )
    {
        pCfg = &ProcessMonitorList[idx];
        pData = &ProcessMonitorData[idx];

        int32_t ret = WdgProxy_GetCurrentState(idx);


        if(WP_SD_PROCESS_CURR_STATE_ACTIVE == ret)
        {
            if ( WP_PROCESS_UNKNOWN_ST == pData->state )
            {
                pData->state = WP_PROCESS_STARTED_ST;
            }
            else if(( WP_PROCESS_STOPPED_ST == pData->state ) || ( WP_PROCESS_INACTIVE_ST == pData->state ))
            {
                uint64_t Nrestart = 0;
                pData->state = WP_PROCESS_STARTED_ST;
                pData->stateTimer = WP_UNKNOWN_ST_TMO_MS;
                (void) WdgProxy_QuerySdBusProperity( pData->serviceCfg.objPath, INTERFACE_SERVICE,
                                                     MEMBER_NRestarts, &Nrestart, NULL );
                /*Process is restarted*/
                pData->restartCount = (uint8_t)Nrestart;
                LOGI ( &gWPLogContext, "Process Restarted- %s. Restart count: %d", pCfg->processName, pData->restartCount );
#ifdef WDG_PROXY_HEALTH_EVENT
                (void)WdgProxyCommIF_SendHealthEvent(idx, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
#endif
            }
            else
            {
                /*Do nothing*/
            }
        }
        else if((WP_SD_PROCESS_CURR_STATE_INACTIVE == ret) || (WP_SD_PROCESS_CURR_STATE_FAILED == ret))
        {

            if( (WP_PROCESS_STOPPED_ST == pData->state ) || (WP_PROCESS_UNKNOWN_ST == pData->state))
            {
                if(pData->stateTimer > 0U)
                {
                    pData->stateTimer -= (uint32_t)WP_TASK_PERIODICITY_MS;
                }
                else
                {
                    /*Report Fatal error*/
                    LOGE ( &gWPLogContext, "Service : %s is failed. Result: %s", pCfg->serviceName, pData->serviceProperity.Result );
                    (void)WdgProxy_ReportFatalError(idx);
                }
            }
        }
        else
        {
            if ( (WP_SD_PROCESS_CURR_STATE_ACTIVATING == ret) || (WP_SD_PROCESS_CURR_STATE_DEACTIVATING == ret) )
            {
                LOGI ( &gWPLogContext, "Service : %s current status is %d.", pCfg->serviceName, ret );
            }
            else
            {
                (void) WdgProxy_ReportFatalError ( idx );
                LOGE ( &gWPLogContext, "Failed to get current status : %s", pCfg->serviceName );
            }
        }
    }
}

static void WdgProxy_ProcessSDBUSEvent ( const uint8_t index )
{
    ProcessMonitorData_t *pData;
    const ProcessMonitorListCfg_t *pCfg;

    if( PROCESS_MONITOR_LIST_SIZE > index )
    {
        pData = &ProcessMonitorData[index];
        pCfg = &ProcessMonitorList[index];

        //LOGI ( &gWPLogContext, "Previuous state: %s, current state: %s, Result: %s, Substate: %s, PID: %d",
        //               pData->serviceProperity.PrevActiveState, pData->serviceProperity.ActiveState, pData->serviceProperity.Result, pData->serviceProperity.SubState, pData->serviceProperity.ExecMainPID);

        if(WP_PROCESS_HEALTHY_ST == pData->state)
        {
            if((strcmp(pData->serviceProperity.PrevActiveState, SERVICE_STATE_ACTIVE) == 0)
                    && (strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_FAILED) == 0))
            {
                pData->state = WP_PROCESS_STOPPED_ST;

                /*Process crashed or exited with non zero exit code or terminated by signal*/
                pData->event = WP_RESTART_EVENT_TYPE_DEATH;

#ifdef WDG_PROXY_HEALTH_EVENT
                (void)WdgProxyCommIF_SendHealthEvent(index, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
#endif
                LOGE ( &gWPLogContext, "Process Failure detected: %s, PID: %d, Result: %s, ActiveState: %s", pCfg->processName,
                       pData->serviceProperity.ExecMainPID, pData->serviceProperity.Result, pData->serviceProperity.ActiveState );
            }
            else if((strcmp(pData->serviceProperity.PrevActiveState, SERVICE_STATE_ACTIVE) == 0)
                    && (strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_INACTIVE) == 0))
            {
                pData->state = WP_PROCESS_STOPPED_ST;

                /*Cause of the dead - clean exit code 0 or
                one of the clean signals SIGHUP, SIGINT, SIGTERM, or SIGPIPE */
                pData->event = WP_RESTART_EVENT_TYPE_DEATH;

#ifdef WDG_PROXY_HEALTH_EVENT
                (void)WdgProxyCommIF_SendHealthEvent(index, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
#endif
                LOGE ( &gWPLogContext, "Process dead detected: %s, PID: %d, Result: %s, ActiveState: %s", pCfg->processName,
                       pData->serviceProperity.ExecMainPID, pData->serviceProperity.Result, pData->serviceProperity.ActiveState );
            }
            else if((strcmp(pData->serviceProperity.PrevActiveState, SERVICE_STATE_DEACTIVE) == 0)
                    && (strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_INACTIVE) == 0))
            {
                pData->state = WP_PROCESS_INACTIVE_ST;

                /*System service is deactivated */
                pData->event = WP_RESTART_EVENT_TYPE_INACTIVE;
#ifdef WDG_PROXY_HEALTH_EVENT
                (void)WdgProxyCommIF_SendHealthEvent(index, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
#endif

                LOGE ( &gWPLogContext, "Service deactivated: %s, PID: %d, Result: %s, ActiveState: %s", pCfg->serviceName,
                       pData->serviceProperity.ExecMainPID, pData->serviceProperity.Result, pData->serviceProperity.ActiveState );
            }
            else if((strcmp(pData->serviceProperity.PrevActiveState, SERVICE_STATE_DEACTIVE) == 0)
                    && (strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_FAILED) == 0))
            {
                pData->state = WP_PROCESS_STOPPED_ST;
                /*Process is deactivated for watchdog failure*/
                pData->event = WP_RESTART_EVENT_TYPE_WDG_FAILURE;

#ifdef WDG_PROXY_HEALTH_EVENT
                (void)WdgProxyCommIF_SendHealthEvent(index, WP_RECORD_TYPE_NO_FATAL_ERROR, pData->event, pData->restartCount);
#endif

                LOGE ( &gWPLogContext, "Process Watchdog failure detected: %s, PID: %d, Result: %s, ActiveState: %s", pCfg->processName,
                       pData->serviceProperity.ExecMainPID, pData->serviceProperity.Result, pData->serviceProperity.ActiveState );
            }
            else
            {
                /*Do nothing*/
            }

            (void) strcpy(pData->serviceProperity.PrevActiveState, pData->serviceProperity.ActiveState);
        }
    }
}

static int32_t WdgProxy_ReportFatalError (const uint8_t idx )
{
    int32_t ret = WP_FAIL;

    if ( PROCESS_MONITOR_LIST_SIZE > idx )
    {
        const ProcessMonitorListCfg_t *pCfg =  &ProcessMonitorList[idx];
        ProcessMonitorData_t *pData = &ProcessMonitorData[idx];

        LOGE ( &gWPLogContext, "WP FATAL ERROR FOR %s", pCfg->processName );

        pData->state = WP_PROCESS_ERROR_ST;
        fatal_error = TRUE;

#ifdef WDG_PROXY_HEALTH_EVENT
        pData->delay_timer -= (int32_t)WP_TASK_PERIODICITY_MS;
        /*Send health event record only one time for failed process*/
        if( FALSE == pData->health_event_sent )
        {
            ret = WdgProxyCommIF_SendHealthEvent(idx, WP_RECORD_TYPE_FATAL_ERROR, pData->event, pData->restartCount);
            pData->health_event_sent = TRUE;
        }
        else
        {
            /*Wait till the expiry of delay timer, to avoid fatal message being sent before expiry of delay timer*/
            if( 0 >= pData->delay_timer )
            {
                ret = WdgProxyCommIf_SendFatalError ( ( uint32_t ) idx );
            }
        }
#else
        ret = WdgProxyCommIf_SendFatalError ( ( uint32_t ) idx );
#endif
    }

    return ret;
}

static int32_t WdgProxy_StartEventTimer ( void )
{
    int32_t ret = WP_OK;
    struct itimerspec  itime = {0};

    timer_fd = timerfd_create ( CLOCK_MONOTONIC, 0);
    if ( 0 >  timer_fd)
    {
        ret = WP_FAIL;
        LOGE ( &gWPLogContext, "timer fd create failed: %s", strerror ( errno ) );
    }

    if ( WP_OK == ret )
    {
        itime.it_value.tv_sec = 0;
        itime.it_value.tv_nsec = ( WP_TASK_PERIODICITY_MS * WP_MS_TO_NS );
        itime.it_interval.tv_sec = 0;
        itime.it_interval.tv_nsec = ( WP_TASK_PERIODICITY_MS * WP_MS_TO_NS );

        if ( 0 > timerfd_settime ( timer_fd, 0, &itime, NULL ) )
        {
            ret = WP_FAIL;
            LOGE ( &gWPLogContext, "timer fd settime failed: %s", strerror ( errno ) );
        }
    }

    return ret;
}

static int32_t WdgProxy_StopEventTimer ( void )
{
    int32_t ret = WP_OK;

    if ( 0 > close ( timer_fd ) )
    {
        ret = WP_FAIL;
        LOGE ( &gWPLogContext, "closing timer fd failed: %s", strerror ( errno ) );
    }

    return ret;
}

static int8_t WdgProxy_SetupSdBusMatchRule ( const uint8_t idx )
{
    int8_t ret = WP_OK;
    int32_t retSD;

    _cleanup_(sd_bus_error_free) sd_bus_error error = SD_BUS_ERROR_NULL;
    _cleanup_(sd_bus_message_unrefp) sd_bus_message *msg = NULL;

    const ProcessMonitorListCfg_t *pCfg = &ProcessMonitorList[idx];
    ProcessMonitorData_t *pData = &ProcessMonitorData[idx];

    /*Get unit file object path for the each process*/
    retSD = sd_bus_call_method(bus, DESTINATION, PATH, INTERFACE_MANAGER, MEMBER_GET_UNIT, &error,
                               &msg, "s", pCfg->serviceName);

    if ( 0 > retSD )
    {
        LOGE ( &gWPLogContext, "Failed to get unit file path: %s", strerror(-ret) );
        ret = WP_FAIL;
    }
    else
    {
        const char* s;
        retSD = sd_bus_message_read(msg, "o", &s);

        if ( 0 > retSD )
        {
            LOGE ( &gWPLogContext, "Failed to read unit file path: %s", strerror(-ret) );
            ret = WP_FAIL;
        }
        else
        {
            (void)strncpy(pData->serviceCfg.objPath, s,  (sizeof(pData->serviceCfg.objPath)-1));
            LOGI ( &gWPLogContext, "Service name: %s, object path: %s ", pCfg->serviceName, pData->serviceCfg.objPath );

            /*Create match rule for each process*/
            (void)snprintf(pData->serviceCfg.matchRule, sizeof(pData->serviceCfg.matchRule),
                           "type='signal',interface='%s',member='%s',path='%s'",
                           INTERFACE_PROPERITIES, MEMBER_PROPERTIES_CHANGED, pData->serviceCfg.objPath);

            /*Add match rule*/
            retSD = sd_bus_add_match(bus, NULL, pData->serviceCfg.matchRule, NULL, NULL);

            if ( 0 > retSD )
            {
                LOGE ( &gWPLogContext, "Failed to add match rule: %s", strerror(-ret) );
                LOGI ( &gWPLogContext,  "Match rule %s ", pData->serviceCfg.matchRule);
                ret = WP_FAIL;
            }

        }
    }

    return ret;
}

static int8_t WdgProxy_GetCurrentState( const uint8_t index )
{
    int8_t ret = WP_FAIL;

    const ProcessMonitorListCfg_t *pCfg = &ProcessMonitorList[index];
    ProcessMonitorData_t *pData = &ProcessMonitorData[index];

    /*Get Value of ActiveState*/
    ret = WdgProxy_QuerySdBusProperity(pData->serviceCfg.objPath, INTERFACE_UNIT,
                                       MEMBER_ACTIVE_STATE, NULL, pData->serviceProperity.ActiveState);

    if (strcmp(pData->serviceProperity.PrevActiveState, pData->serviceProperity.ActiveState) != 0)
    {
        LOGI(&gWPLogContext, "Service name: %s, Current ActiveState: %s", pCfg->serviceName,
             pData->serviceProperity.ActiveState);

        strcpy(pData->serviceProperity.PrevActiveState, pData->serviceProperity.ActiveState);
    }

    if(WP_OK == ret)
    {
        if(strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_ACTIVE) == 0)
        {
            ret = WP_SD_PROCESS_CURR_STATE_ACTIVE;
        }
        else if(strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_FAILED) == 0)
        {
            ret = WP_SD_PROCESS_CURR_STATE_FAILED;
        }
        else if(strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_INACTIVE) == 0)
        {
            ret = WP_SD_PROCESS_CURR_STATE_INACTIVE;
        }
        else if(strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_DEACTIVE) == 0)
        {
            ret = WP_SD_PROCESS_CURR_STATE_DEACTIVATING;
        }
        else if(strcmp(pData->serviceProperity.ActiveState, SERVICE_STATE_ACTIVATING) == 0)
        {
            ret = WP_SD_PROCESS_CURR_STATE_ACTIVATING;
        }
        else
        {
            ret = WP_FAIL;
        }
    }

    return ret;
}

static uint8_t WdgProxy_ProcessSdBusMsg(sd_bus_message *msg)
{
    uint8_t process_index = WP_PROCESS_UNKNOWN;

    const char* path = sd_bus_message_get_path(msg);

    if(NULL != path)
    {
        for(uint8_t idx = 0; idx < PROCESS_MONITOR_LIST_SIZE; idx++)
        {
            if(0 == strcmp(path, ProcessMonitorData[idx].serviceCfg.objPath))
            {
                process_index = idx;
                break;
            }
        }

        if(WP_PROCESS_UNKNOWN != process_index)
        {
            int32_t ret;

            /*Skip a first single element of string type without read*/
            (void) sd_bus_message_skip(msg, "s");

            /*Enter into the message container to read further properities*/
            ret = sd_bus_message_enter_container(msg, 'a', "{sv}");
            if( 0 > ret )
            {
                LOGE ( &gWPLogContext, "Failed to enter container to read SD BUS message: %s", strerror(-ret));
            }
            else
            {
                /*Iterate through the dictionary elements*/
                while ((ret = sd_bus_message_enter_container(msg, 'e', "sv")) > 0)
                {
                    const char *key;

                    /*Read the key element of dictionary*/
                    ret = sd_bus_message_read(msg, "s", &key);
                    if ( 0 > ret )
                    {
                        LOGE ( &gWPLogContext, "Error reading dictionary key of SD BUS message: %s", strerror(-ret));
                        break;
                    }

                    /*Enter into the message container to read each variant*/
                    ret = sd_bus_message_enter_container(msg, 'v', NULL);
                    if ( 0 > ret )
                    {
                        LOGE ( &gWPLogContext, "Error entering variant container of SD BUS message: %s", strerror(-ret));
                        break;
                    }

                    if(strcmp(key, "ExecMainPID") == 0)
                    {
                        uint32_t variant_value;
                        ret = sd_bus_message_read_basic(msg, 'u', &variant_value);
                        if ( 0 < ret )
                            ProcessMonitorData[process_index].serviceProperity.ExecMainPID = variant_value;
                    }
                    else if(strcmp(key, "Result") == 0)
                    {
                        const char *variant_string;
                        ret = sd_bus_message_read_basic(msg, 's', &variant_string);
                        if ( 0 < ret )
                            (void)strncpy(ProcessMonitorData[process_index].serviceProperity.Result,
                                          variant_string, (STRING_MAX_SIZE - 1));
                    }
                    else if(strcmp(key, "ActiveState") == 0)
                    {
                        const char *variant_string;
                        ret = sd_bus_message_read_basic(msg, 's', &variant_string);
                        if ( 0 < ret )
                            (void)strncpy(ProcessMonitorData[process_index].serviceProperity.ActiveState,
                                          variant_string, (STRING_MAX_SIZE - 1));
                    }
                    else
                    {
                        /*Skip the other element of any type*/
                        ret = sd_bus_message_skip(msg, NULL);
                        if ( 0 > ret )
                        {
                            LOGE ( &gWPLogContext, "Failed skipping SD BUS message read: %s", strerror(-ret));
                            break;
                        }
                    }

                    (void)sd_bus_message_exit_container(msg);
                    (void)sd_bus_message_exit_container(msg);
                }

                if ( 0 > ret )
                    LOGE ( &gWPLogContext, "Error iterating through a{sv} dictionary to read SD BUS message: %s", strerror(-ret));
            }

            /*Exit container once read all messages*/
            (void)sd_bus_message_exit_container(msg);
        }
    }
    else
    {
        LOGE ( &gWPLogContext, "object path NULL");
    }

    return process_index;
}


static int8_t WdgProxy_QuerySdBusProperity(const char* objPath, const char* interface,
        const char* member_to_query, uint64_t* result, char* str_result)
{
    int8_t ret = WP_FAIL;
    int32_t retSD;

    _cleanup_(sd_bus_error_free) sd_bus_error error = SD_BUS_ERROR_NULL;
    _cleanup_(sd_bus_message_unrefp) sd_bus_message *msg = NULL;

    /* Query the properties of the service unit */
    retSD = sd_bus_call_method(bus, DESTINATION,
                               objPath, INTERFACE_PROPERITIES,
                               MEMBER_GET,
                               &error,
                               &msg,
                               "ss",
                               interface,
                               member_to_query );
    if ( 0 > retSD )
    {
        LOGE ( &gWPLogContext, "Failed to get service status: %s", error.message);
        sd_bus_error_free(&error);
    }
    else
    {
        /* Read the entire message */
        retSD = sd_bus_message_enter_container(msg, 'v', NULL);
        if ( 0 > retSD )
        {
            LOGE ( &gWPLogContext, "Error entering variant container to read SD BUS message: %s", strerror(-ret));
        }
        else
        {
            /* Depending on the type of variant value, read and handle it accordingly */
            char variant_type;
            retSD = sd_bus_message_peek_type(msg, &variant_type, NULL);

            if ( 0 > retSD )
            {
                LOGE ( &gWPLogContext, "Error peeking variant type to read SD BUS message: %s", strerror(-ret));
            }
            else if( 's' == variant_type )
            {
                const char *output_string;
                retSD = sd_bus_message_read_basic(msg, variant_type, &output_string);
                if( 0 > retSD )
                {
                    LOGE ( &gWPLogContext, "Error reading SD Bus message: %s", strerror(-ret));
                }
                else
                {
                    if(NULL != str_result)
                    {
                        (void) strcpy(str_result, output_string);
                        ret = WP_OK;
                    }
                }
            }
            else
            {
                uint64_t output_value = 0;
                retSD = sd_bus_message_read_basic(msg, variant_type, &output_value);
                if( 0 > retSD )
                {
                    LOGE ( &gWPLogContext, "Error reading SD Bus message: %s", strerror(-ret));
                }
                else
                {
                    if(NULL != result)
                    {
                        *result = output_value;
                        ret = WP_OK;
                    }
                }
            }
        }
    }

    (void) sd_bus_message_exit_container(msg);

    return ret;
}
