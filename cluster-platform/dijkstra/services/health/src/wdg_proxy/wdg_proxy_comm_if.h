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

#ifndef WDGPROXY_COMMIF_H
#define WDGPROXY_COMMIF_H

#include "wdg_proxy_types.h"

extern int32_t WdgProxyCommIf_Init ( void );
extern int32_t WdgProxyCommIf_Shutdown ( void );
extern int32_t WdgProxyCommIf_SendHeartbeat ( void );
extern int32_t WdgProxyCommIf_SendFatalError ( uint32_t idx );
extern int32_t WdgProxyCommIF_SendHealthEvent (uint8_t idx, uint8_t record_type, uint8_t restart_type, uint8_t restart_cnt);
extern int32_t WdgProxyCommIf_PackageDLTLogs ( void );

#endif /* WDGPROXY_COMMIF_H */
