/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  intEvtDefs.h                                               *
*  AUTHOR NAME  :  Joerg Merkle (jmerkle)                                     *
*******************************************************************************
*  MODULE DATE  :   2011                                                      *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  Message group and event definitions for the Visteon message framework      *
*******************************************************************************/

#ifndef _INTEVTDEFS_H
#define _INTEVTDEFS_H



/******************************************************************************/
/*                                                                            */
/* MESSAGE GROUPS                                                             */
/*                                                                            */
/******************************************************************************/
#define BROADCAST                       250


/* Message Groups for VMF Tracer -- DO NOT MOVE!!! */
#define VMF_TRACE_IN                    120
#define VMF_TRACE_OUT                   121
#define VMF_TRACE_CTRL                  122
#define VMF_TRACE_SYSINFO_CTRL          123
#define VMF_TRACE_SYSINFO_DATA          124
#define VMF_TRACE_IPC_DATA              125
#define VMF_SQL                         126
#define VMF_DYN_0                       127



/******************************************************************************/
/*                                                                            */
/* MESSAGE ID'S                                                               */
/*                                                                            */
/******************************************************************************/

/**************** \defgroup BROADCAST ********************/
#define BrdSysStartUp                    0
#define BrdSysRunning                    1
#define BrdSysShutDownRequest            2
#define BrdSysShutDown                   3
#define BrdSysSaveLog                    4
#define BrdSysAbnVolt                    5



/**************** \defgroup VMF_TRACE_CTRL ************ >>> DO NOT MODIFY <<< ***/
#define VMF_TRACE_CTRL_REG_CLIENT       0       /* register a trace client       */
#define VMF_TRACE_CTRL_REG_VIEWER       1       /* register windows viewer       */
#define VMF_TRACE_CTRL_FILTER_SET       2       /* set a single filter           */
#define VMF_TRACE_CTRL_FILTER_REQ       3       /* request all filters           */
#define VMF_TRACE_CTRL_FILTER_RESP      4       /* response with all filters     */
#define VMF_TRACE_CTRL_PERSISTENT       5       /* store current filters         */
#define VMF_TRACE_CTRL_STARTUP_Q_SET    6       /* en/disable startup queueing   */
#define VMF_TRACE_CTRL_STARTUP_Q_REQ    7       /* requeste startup queueing     */
#define VMF_TRACE_CTRL_STARTUP_Q_RESP   8       /* response startup queueing     */
#define VMF_TRACE_CTRL_UNREG_VIEWER     9       /* unregister windows viewer     */
#define VMF_TRACE_CTRL_CONNECTION_NAMES 10      /* transfer of connection name   */
#define VMF_CTRL_START_TIMER            11      /* start a vmf timer             */
#define VMF_CTRL_VMF_INFO_REQUEST       12      /* vmf info request              */
#define VMF_CTRL_VMF_INFO_RESPONSE      13      /* vmf info response             */
#define VMF_CTRL_VMF_VERSION_STRING     14      /* VMF version string            */
#define VMF_CTRL_VMF_ENABLE_SPY_QUEUE   15      /* enable Queue for SPY          */
#define VMF_CTRL_VMF_DISABLE_SPY_QUEUE  16      /* disable Queue for SPY         */
#define VMF_TRACE_CTRL_REQ_CONN_NAMES   17      /* request all connection names  */
#define VMF_CTRL_REQUEST_CONNECTION_NAMES VMF_TRACE_CTRL_REQ_CONN_NAMES
#define VMF_TRACE_DOWNLOAD_REQUEST      18      /* download request tool->target */
#define VMF_TRACE_DOWNLOAD_RESPONSE     19      /* response from target to downlod request target->tool */
#define VMF_TRACE_DOWNLOAD_TRANSFER     20      /* download transfer tool->target*/
#define VMF_TRACE_DOWNLOAD_TRANSFER_REQ_RESP 21     /* download transfer response    */
#define VMF_TRACE_DOWNLOAD_DONE         22      /* download is done              */
#define VMF_TRACE_CTRL_TIME_SYNC        23      /* vmf-time server sync message  */
#define VMF_TRACE_CTRL_TIME_INTERNAL    24      /* vmf-time server internal timer message */
#define VMF_TRACE_CTRL_TIME_REQ         25      /* request current time from time-server */
#define VMF_TRACE_SATURN_FLASH_DONE     26      /* flash of Saturn is done */
#define VMF_TRACE_CTRL_REG_GW_GROUPS    27      /* regsiter gateway message groups */

#define VMF_TRACE_READ_MEM_REQ          30      /* read memory request  */
#define VMF_TRACE_READ_MEM_RESP         31      /* read memory response */
#define VMF_TRACE_WRITE_MEM_REQ         32      /* write memory request */
#define VMF_TRACE_WRITE_MEM_RESP        33      /* write memory response */

#define VMF_CTRL_MONITOR_REQUEST        40      /* request from CtrlMonitor tool */
#define VMF_CTRL_MONITOR_RESPONSE       41      /* response to CtrlMonitor tool */

#define VMF_CTRL_SEQ_DIAGRAM_ENABLE     45      /* enable/disable sending of "metadata" to spy for sequence diagrams */
#define VMF_CTRL_SEQ_DIAGRAM_DATA       46      /* "metadata" for sequence diagrams */

#define VMF_CTRL_BAUDRATE_REQUEST       50      /* request the highest baudrate         */
#define VMF_CTRL_BAUDRATE_RESPONSE      51      /* response with the highest baudrate   */
#define VMF_CTRL_BAUDRATE_SET           52      /* set a baudrate                       */

#define VMF_CTRL_CONNECTION_CHECK       250     /* used to test remote connection*/


/**************** \defgroup VMF_TRACE_SYSINFO_CTRL ***************/
#define VMF_SYSINFO_START                        (0)
#define VMF_SYSINFO_CTRL_PROFILER_START          (VMF_SYSINFO_START +0)     /* CTRL: start profiler thread */
#define VMF_SYSINFO_CTRL_PROFILER_STOP           (VMF_SYSINFO_START +1)     /* CTRL: stop profiler thread  */
#define VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ (VMF_SYSINFO_START +2)     /* CTRL: start transferring load for given pid */
#define VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ  (VMF_SYSINFO_START +3)     /* CTRL: stop transferring load for given pid */
#define VMF_SYSINFO_DATA_PROFILER_LOAD_RESP      (VMF_SYSINFO_START +4)     /* DATA: transfer load */
#define VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ   (VMF_SYSINFO_START +5)     /* CTRL: request a name for a given pid*/
#define VMF_SYSINFO_DATA_PROFILER_PID_NAME_RESP  (VMF_SYSINFO_START +6)     /* DATA: response with a name for a given pid  */
#define VMF_IPC_STATUS_CTRL_START_STOP           (VMF_SYSINFO_START +7)     /* CTRL: enable/disable ipc status */
#define VMF_IPC_STATUS_DATA_POOLS                (VMF_SYSINFO_START +8)     /* DATA: transfer of shm ipc pool status */
#define VMF_IPC_STATUS_DATA_QUEUES               (VMF_SYSINFO_START +9)     /* DATA: transfer of shm ipc queue status */
#define VMF_IPC_STATUS_DATA_QUEUE_NAME           (VMF_SYSINFO_START +10)    /* DATA: transfer of shm ipc queue name */

#endif /*_INTEVTDEFS_H*/

