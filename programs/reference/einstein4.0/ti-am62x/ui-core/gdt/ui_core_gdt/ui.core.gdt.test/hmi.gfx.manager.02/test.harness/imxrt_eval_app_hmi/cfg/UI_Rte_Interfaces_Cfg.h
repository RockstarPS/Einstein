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

//#include "TmExt_Cfg.h"
//#include "TmExt_Timer.h"

/* NOTE: The below macros should be configured with RTE API's. It should not be removed. */

//#define UI_RTE_TIMER_START(timer_id)                          Rte_Call_CP_CS_Gdt_TI_If_TmExt_Timer_Start_Timer_Start(timer_id)
//#define UI_RTE_TIMER_STOP(timer_id)                           Rte_Call_CP_CS_Gdt_TI_If_TmExt_Timer_Stop_Timer_Stop(timer_id)
//#define UI_RTE_TIMER_GET_ELAPSED_TIME(timer_id, ptr_value)    Rte_Call_CP_CS_Gdt_TI_If_TmExt_Timer_GetElapsedTime_Timer_GetElapsedTime(timer_id, ptr_value)
//#define UI_RTE_TIMER_IS_STARTED(timer_id, ptr_status)         Rte_Call_CP_CS_Gdt_TI_If_TmExt_Timer_IsStarted_Timer_IsStarted(timer_id, ptr_status)
//#define UI_RTE_TIMER_IS_ELAPSED(timer_id, count, ptr_status)  Rte_Call_CP_CS_Gdt_TI_If_TmExt_Timer_IsElapsed_Timer_IsElapsed(timer_id, count, ptr_status)
#define UI_RTE_GDT_CDD_RENDER_DONE()                          (void)Rte_Result_GdtCdd_TIGdtCtrl_CS_CP_RenderDone(); \
                                                              (void)Rte_Call_GdtCdd_TIGdtCtrl_CS_CP_RenderDone()

#define UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL()
#define UI_RTE_GDTCDD_WATCHDOG_ENABLE_CALL()
#define UI_RTE_GDTCDD_WATCHDOG_DISABLE_CALL()
#define UI_LCDBUS_IF_INIT()                                 GdtCDD_LcdBusIFDrv_Init()
#define UI_LCDBUS_IF_FB_TRANS()	                            GdtCDD_LCDBusIFDrv_FB_Trans()

#define Gfx_Ev_RdrDeinit          Rte_Ev_Gfx_RdrDeinit	
#define Gfx_Ev_RdrDeinitDone      Rte_Ev_Gfx_RdrDeinitDone
#define Gfx_Ev_RdrInit            Rte_Ev_Gfx_RdrInit
#define Gfx_Ev_RdrInitDone        Rte_Ev_Gfx_RdrInitDone
#define Gfx_Ev_RdrStart           Rte_Ev_Gfx_RdrStart
#define Gfx_Ev_VSync              Rte_Ev_Gfx_VSync
#endif // RTE_INTERFACES_CFG_H
