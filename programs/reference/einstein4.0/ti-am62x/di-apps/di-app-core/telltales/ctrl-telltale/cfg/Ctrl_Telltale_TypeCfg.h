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
#include "Rte_CCtrl_Telltale_Type.h"
#include "Ctrl_Telltale_Cfg.h"

typedef struct TellTaleMdl_TTConfig_t 
{
	boolean Is_TTProveOut_Enabled;
    uint16 ProveOut_ONtime;
	uint16 ProveOut_OFFtime;
	uint16 ProveOut_StartPhase;
	uint8  Operational_states;
	uint8  LVSD_state;
	uint8  HVSD_state;
}TellTaleMdl_TTConfig;

static const TellTaleMdl_TTConfig tt_ctrl_ttconfig[TT_TOTAL_NUM_OF_TELLTALES] =
    {
        cPRODUCT_SPECIFIC_TELLTALE_CONFIG
    };


