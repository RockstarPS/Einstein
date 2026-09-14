//---------------------------------------------------------------------------------------------------------------------
// VISTEON CORPORATION CONFIDENTIAL
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
// File Name:       ComAbsCtrlNwControllerApp.h
//---------------------------------------------------------------------------------------------------------------------
#ifndef COMABSCTRLNWCONTROLLERAPP_H
#define COMABSCTRLNWCONTROLLERAPP_H

#include "Rte_CComAbsCtrl.h"

//=====================================================================================================================
//  OUTPUT
//=====================================================================================================================
extern void ComAbsCtrl_NwControllerApp_Sleep_Wakeup_Process(tPwrModeState ComAbsNW_IGNstatus);
extern void ComAbsCtrl_NwControllerApp_Init(void);
extern void ComAbsCtrl_NwControllerApp_Wakeup_Init(void);
extern void ComAbsCtrl_NwControllerApp_ProcessAliveTimer(void); 
extern void ComAbsCtrl_SetNetworkComMode(tNetworkComMode Mode);
extern boolean ComAbsCtrl_NWSleep_Wakeup_Determination(boolean ComAbsCtrl_IgnStatus, boolean ICAN_NwAwake_Status);
static void ComAbsCtrl_NwControllerApp_Network_KeyOff_Status(tPwrModeState ComAbsNW_IGN);
#define GET_CANNM_CURRENTMODE(ComMode) \
    Rte_Call_rpCSComMExt_CAN_GetCurrentComMode(0U, (ComMode))

#endif // COMABSCTRLNWCONTROLLERAPP_H