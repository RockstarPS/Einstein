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
// @File Name:       ComAbsCtrl.c
// @Description: 	 This component controls the ComAbs component with respect to
// @				 Application SRD Network / Multiplex - Generic SRD 0.3
//---------------------------------------------------------------------------------------------------------------------
#include "ComAbsCtrl_cfg.h"

// Determining the NW sleep or Wake up conditions.

boolean ComAbsCtrl_NWSleep_Wakeup_Determination(boolean ComAbsCtrl_IgnStatus, boolean ICAN_NwAwake_Status)
{
    uint8 fl_HSCAN_network_temp_BOOL   = FALSE;

	if((ePwrMode_Off == ComAbsCtrl_IgnStatus) && \
	(ICAN_NwAwake_Status != TRUE ))
	{ 
		fl_HSCAN_network_temp_BOOL = TRUE; //Enable this when the requirement is clear
	}

    return fl_HSCAN_network_temp_BOOL;
}

