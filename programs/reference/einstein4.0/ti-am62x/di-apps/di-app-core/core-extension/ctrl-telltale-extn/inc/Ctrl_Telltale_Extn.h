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
#ifndef CTRL_TELLTALE_EXTN_H
#define CTRL_TELLTALE_EXTN_H

#include "Rte_Type.h"
#include "Rte_CCtrl_Telltale_Type.h"


/* Function Declarations */ 

void CtrlTt_InitProveout(uint8 CtrlTtIgnSts);
uint8 CtrlTtCheckProveout(uint8 index, uint8 l_turn_on_off, uint8 tt_state_byte);
uint8 CtrlTtCheckBatteryStatus(uint8 index, uint8 l_turn_on_off, uint8 battery_status); 
uint8 CtrlTtVoltageLviHvi(void);

#endif























