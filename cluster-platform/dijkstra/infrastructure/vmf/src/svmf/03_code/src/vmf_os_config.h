/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               vmf_os_config.h
  Description:          os specific header file for vmf
  Project Scope:        leopard-e

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar
  Target Hardware:      leopard-e

  *****************************************************************************/

#ifndef NW_OS_CONFIG_H
#define NW_OS_CONFIG_H

#include "os_if.h"
#include <mqx_osal_if.h>
#include <mqx_inc.h>
#include <msg_prv.h>
#include <mutex.h>
#include <stdlib.h>
#include <charq.h>
#include <util_types_if.h>
#define ERROR_CHANNEL   stdout
#define VMF_MQX                     /* use mqx threading */

#define VMF_CORE VS_MICRO_CORE_A5

#ifndef PROC_NUMBER_FROM_QID
/* Extract the processor number from a queue id */
#define MSG16_PROC_SHIFT                (8)
#define PROC_SHIFT                      MSG16_PROC_SHIFT
#define PROC_NUMBER_FROM_QID(qid) ((qid) >> PROC_SHIFT)
#endif


#define     delay(ms_time)          _time_delay(ms_time)
#define     nw_sleep_ms(ms_time)    _time_delay(ms_time)

#define     nw_os_cfg_get_ms_time() nw_vmf_ipc_get_ms_time()
#define     nw_os_malloc(len)       malloc(len)

#define     getmypid()      (vmf_pid_t)_task_get_id()
#define     NW_MEMCOPY(sink,source,length) memcpy(sink,source,length)

typedef unsigned long       DWORD;
typedef unsigned short      WORD;

#ifndef true
typedef BOOL    bool;
#define true    TRUE
#define false   FALSE
#endif


#define assert(arg)


#endif


