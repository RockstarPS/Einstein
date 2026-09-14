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

#ifndef RTW_HEADER_Ctrl_Telltale_h
#define RTW_HEADER_Ctrl_Telltale_h
#include "rtwtypes.h"
#include "Rte_CCtrl_Telltale.h"


/* Includes for objects with custom storage classes. */
#include "Ctrl_Telltale_data.h"
#include "Rte_Type.h"
#include "string.h"

/* MACRO DECLARATIONS */

#define cTT_CONFIGURED_OFF             255U
#define cTT_TURN_INPUT                  16U
#define cTTMDL_MAX_PROVEOUT_TIME       110u 
#define DIAG_ENABLE                      8U
#define eBULBTEST_NORMAL                 1U
#define eBULBTEST_DIAG_TT_TURN_ON      170U
#define eBULBTEST_DIAG_TT_TURN_OFF      85U
#define TT_RUN                          32U
#define TT_OFF                          64U

/* STATIC FUNCTIONS DECLARATIONS */

static void InputProcess(void);
static void Process_Ctrl_Telltale(void);
static void OutputProcess(void);
static uint8 CtrlTtGetStateByte(uint8 IgnSts, uint8 tt_state_byte);

/* FUNCTIONS DECLARATIONS */

void CTtView_TtViewUpdateStatus(uint8 index, uint8 tt_status);
void CtrlTt_CtrlTtUpdateStatus(uint8 index, uint8 tt_status);
void CtrlTt_CtrlTtGetStatus(uint8 index, uint8 *tt_status);
void CtrlTtStatus_Output_Array(uint8 index, uint8 TT_Phase);


#endif

