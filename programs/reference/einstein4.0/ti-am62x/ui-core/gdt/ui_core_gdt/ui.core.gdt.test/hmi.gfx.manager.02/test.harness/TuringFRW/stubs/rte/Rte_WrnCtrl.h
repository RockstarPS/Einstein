/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_WrnCtrl.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <WrnCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_WRNCTRL_H
# define _RTE_WRNCTRL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_WrnCtrl_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"

#  ifndef RTE_COM_VERSION
#   define RTE_COM_VERSION 40U
#  endif


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EKeyPos, RTE_VAR_INIT) Rte_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_tiSR_TIModMdl_KeyPos_KeyPos (0U)
#  define Rte_InitValue_tiSR_TISpdMdl_Out_IsOverSpeed (FALSE)
#  define Rte_InitValue_tiSR_TISpdMdl_Out_Speed (0U)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_BrkLamp (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_MyKey_Active (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_Slow_For_HDC (FALSE)
#  define Rte_InitValue_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_tiSR_TIModMdl_KeyPos_KeyPos Rte_Read_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos
#  define Rte_Read_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos(data) (*(data) = Rte_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TISpdMdl_Out_IsOverSpeed Rte_Read_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed
#  define Rte_Read_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_BrkLamp Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_BrkLamp_B_Rq_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_Disable_Neutral_Tow_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_DrStatDrv_B_Actl_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_DrStatPsngr_B_Actl_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_Enable_Neutral_Tow_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_MyKey_Active Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_MyKey_Active_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_Slow_For_HDC Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_Slow_For_HDC_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat
#  define Rte_Read_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_Tire_Press_System_Stat_610999c4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_GDTCTRL_APPL_CODE) GdtCtrl_Cancel(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel(arg1, arg2) (GdtCtrl_Cancel(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_GDTCTRL_APPL_CODE) GdtCtrl_Latch(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch(arg1, arg2) (GdtCtrl_Latch(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_GDTCTRL_APPL_CODE) GdtCtrl_ListChange(TWrnListMask ListMask); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange(arg1) (GdtCtrl_ListChange(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_GDTCTRL_APPL_CODE) GdtCtrl_Prepare(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_GDTCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare GdtCtrl_Prepare
#  define RTE_START_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SNDVIEW_APPL_CODE) SndView_Cancel(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel(arg1, arg2) (SndView_Cancel(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SNDVIEW_APPL_CODE) SndView_Latch(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch(arg1, arg2) (SndView_Latch(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SNDVIEW_APPL_CODE) SndView_ListChange(TWrnListMask ListMask); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange(arg1) (SndView_ListChange(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_SNDVIEW_APPL_CODE) SndView_Prepare(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SNDVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare SndView_Prepare
#  define RTE_START_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TTVIEW_APPL_CODE) TtView_Cancel(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel(arg1, arg2) (TtView_Cancel(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TTVIEW_APPL_CODE) TtView_Latch(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch(arg1, arg2) (TtView_Latch(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TTVIEW_APPL_CODE) TtView_ListChange(TWrnListMask ListMask); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange(arg1) (TtView_ListChange(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_TTVIEW_APPL_CODE) TtView_Prepare(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TTVIEW_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare TtView_Prepare


# endif /* !defined(RTE_CORE) */


# define WrnCtrl_START_SEC_CODE
# include "WrnCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CWrnCtrl_Acknowledge CWrnCtrl_Acknowledge
#  define RTE_RUNNABLE_CWrnCtrl_Impl_MainFunction CWrnCtrl_Impl_MainFunction
#  define RTE_RUNNABLE_CWrnCtrl_Impl_OnCommand CWrnCtrl_Impl_OnCommand
#  define RTE_RUNNABLE_WrnCtrl_GetCount WrnCtrl_GetCount
#  define RTE_RUNNABLE_WrnCtrl_GetFirst WrnCtrl_GetFirst
#  define RTE_RUNNABLE_WrnCtrl_GetNext WrnCtrl_GetNext
#  define RTE_RUNNABLE_WrnCtrl_Release WrnCtrl_Release
#  define RTE_RUNNABLE_WrnCtrl_Replays_Gdt_Ready WrnCtrl_Replays_Gdt_Ready
#  define RTE_RUNNABLE_WrnCtrl_Replays_Gdt_Replay WrnCtrl_Replays_Gdt_Replay
#  define RTE_RUNNABLE_WrnCtrl_Replays_Snd_Ready WrnCtrl_Replays_Snd_Ready
#  define RTE_RUNNABLE_WrnCtrl_Replays_Snd_Replay WrnCtrl_Replays_Snd_Replay
#  define RTE_RUNNABLE_WrnCtrl_Replays_Tt_Ready WrnCtrl_Replays_Tt_Ready
#  define RTE_RUNNABLE_WrnCtrl_Replays_Tt_Replay WrnCtrl_Replays_Tt_Replay
# endif

FUNC(void, WrnCtrl_CODE) CWrnCtrl_Acknowledge(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WrnCtrl_CODE) CWrnCtrl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, WrnCtrl_CODE) CWrnCtrl_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_GetCount(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Count); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_GetFirst(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_GetNext(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WrnCtrl_CODE) WrnCtrl_Release(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WrnCtrl_CODE) WrnCtrl_Replays_Gdt_Ready(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_Replays_Gdt_Replay(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WrnCtrl_CODE) WrnCtrl_Replays_Snd_Ready(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_Replays_Snd_Replay(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WrnCtrl_CODE) WrnCtrl_Replays_Tt_Ready(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, WrnCtrl_CODE) WrnCtrl_Replays_Tt_Replay(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define WrnCtrl_STOP_SEC_CODE
# include "WrnCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_tiCS_TISystem_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_Lists_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_SyncCmd_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_SyncReply_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_WRNCTRL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
