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
#ifndef RTE_INTERFACES_CFG_H
#define RTE_INTERFACES_CFG_H

//#include "TmExt_Timer.h"

/* NOTE: The below macros should be configured with RTE API's. It should not be removed. */

#define UI_RTE_TIMER_START(timer_id)                          TmExt_Timer_Start(timer_id)//Rte_Call_rpCS_TmExt_Timer_Start(timer_id)
#define UI_RTE_TIMER_STOP(timer_id)                           TmExt_Timer_Stop(timer_id)//Rte_Call_rpCS_TmExt_Timer_Stop(timer_id)
#define UI_RTE_TIMER_GET_ELAPSED_TIME(timer_id, ptr_value)    TmExt_Timer_GetElapsedTime(timer_id)//Rte_Call_rpCS_TmExt_Timer_GetElapsedTime(timer_id, ptr_value)
#define UI_RTE_TIMER_IS_STARTED(timer_id, ptr_status)         TmExt_Timer_IsStarted(timer_id)//Rte_Call_rpCS_TmExt_Timer_IsStarted(timer_id, ptr_status)
#define UI_RTE_TIMER_IS_ELAPSED(timer_id, count, ptr_status)  TmExt_Timer_IsElapsed(timer_id)//Rte_Call_rpCS_TmExt_Timer_IsElapsed(timer_id, count, ptr_status)


#define UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL()
#define UI_RTE_GDTCDD_WATCHDOG_ENABLE_CALL()
#define UI_RTE_GDTCDD_WATCHDOG_DISABLE_CALL()


#endif /* RTE_INTERFACES_CFG_H */
