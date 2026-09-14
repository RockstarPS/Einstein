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
*  MODULE NAME  :  vmf.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_H
#define __VMF_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( PTHREAD_H )
#include <pthread.h>
#endif

#ifndef OS_TYPES_H
#include <os_types.h>
#endif


#include <intEvtDefs.h>
#include "nw_config.h"
#include "nw_vmf_types.h"
#include "nw_vmf_client.h"
#include "nw_vmf_client_uties.h"
#ifdef VMF_TRACE
#include "nw_vmf_trace.h"
#endif
#include "nw_vmf_timer.h"

#ifdef __cplusplus
}
#endif


#endif
