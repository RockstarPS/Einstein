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
/*! \file wdg_proxy.h
 *    \defgroup Dijkstra Health Management
 *   \brief Watchdog Proxy Application
 *
 *   Watchdog Proxy application takes the the first level corrective action on the errant process and notifies VIP if
 *  the error condition persists.
*/

#ifndef WDGPROXY_H
#define WDGPROXY_H

#include "wdg_proxy_types.h"

int8_t WdgProxy_onInit ( void );
int8_t WdgProxy_onStart ( void );
int8_t WdgProxy_onStop ( void );
int8_t WdgProxy_onShutdown ( void );
void    WdgProxy_worker ( void );

#endif /* WDGPROXY_H */
