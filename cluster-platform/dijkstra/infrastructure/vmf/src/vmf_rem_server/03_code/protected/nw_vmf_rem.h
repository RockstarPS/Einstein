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
*  MODULE NAME  :  nw_vmf_rem.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __REM_VMF_H
#define __REM_VMF_H

#ifdef WIN32
#pragma once
#pragma warning(disable : 4996)
#define WIN32_LEAN_AND_MEAN     // Selten verwendete Teile der Windows-Header nicht einbinden.
#include <stdio.h>
#include <tchar.h>
#endif

#ifndef VMF_REM_SERVER_UNIT_TEST
    #ifdef WIN32
    #include <winsock2.h>
    #endif
#endif

#ifndef OS_TYPES_H
#include <os_types.h>
#endif
#include "nw_os_config.h"

#include "nw_vmf_types.h"
#if ((defined WIN32) && (!defined VMF_REM_SERVER_UNIT_TEST))
#ifndef __WINDOWS__
#include "nw_vmf_rem_client.h"
#endif
#else
#include "nw_vmf_client.h"
#endif
#include "nw_vmf_rem_cfg.h"
#include "nw_vmf_rem_types.h"
#include "nw_vmf_rem_debug.h"
#include "nw_vmf_rem_server_connector.h"
#include "nw_vmf_rem_server_rpc.h"
#include "nw_vmf_rem_util.h"

#endif

