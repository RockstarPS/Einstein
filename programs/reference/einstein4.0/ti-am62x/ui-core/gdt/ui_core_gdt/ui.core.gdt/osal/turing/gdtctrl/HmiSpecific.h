//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
#ifndef HMISPECIFIC_H
#define HMISPECIFIC_H

#ifdef GDTCTRL_LANGUAGECORE_ENABLED
#include "hmi_language_interface.h"
#endif

#include "hmi_logic_state_handler.h"

#ifdef GDTCTRL_POPUPCORE_ENABLED
#include "hmi_popup_core_if.h"
#endif

#ifdef GDTCTRL_MENUCORE_ENABLED
#include "hmi_menu_core_01_logic.h"
#endif


void                HmiSpecific_Init(void);
Std_ReturnType      HmiSpecific_Activate(void);
void                HmiSpecific_Active(void);
Std_ReturnType      HmiSpecific_Deactivate(void);

#if (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS))
Std_ReturnType      HmiSpecific_Prepare(EWrnReason Reason, TWrnId Id);
void                HmiSpecific_Cancel(EWrnReason Reason, TWrnId Id);
void                HmiSpecific_Latch(EWrnReason Reason, TWrnId Id);
void                HmiSpecific_ListChange(TWrnListMask ListMask);

Std_ReturnType      HmiSpecific_PrepareSub ( EHmiSubId Id );
void                HmiSpecific_Start ( EHmiSubId Id );
void                HmiSpecific_Stop ( EHmiSubId Id );

Std_ReturnType      HmiSpecific_DiagAction(EDcmExtAction Action, uint8* Data, uint8* Lenght, uint32 Id);
void                HmiSpecific_Notification ( const SPulseNotification *Notification );
#endif

#endif // HMISPECIFIC_H
