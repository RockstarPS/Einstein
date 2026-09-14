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
 *          File:  Rte_GdtCtrl.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <GdtCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GDTCTRL_H
# define _RTE_GDTCTRL_H

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

# include "Rte_GdtCtrl_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_OdoMdl_tiSR_OdoOutMiles_Miles; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpSR_rEng_TIEngMdl_Out_Tacho (0U)
#  define Rte_InitValue_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed (FALSE)
#  define Rte_InitValue_rpSR_rSpd_TISpdMdl_Out_Speed (0U)
#  define Rte_InitValue_tiSR_OdoOutMiles_Miles (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GdtCtrl_tiSR_TrcOut_deTrcOut(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpSR_pBtnState_B3_TIBtnMdl_State_State Rte_Read_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State
#  define Rte_Read_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State(data) (*(data) = Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_pBtnState_B4_TIBtnMdl_State_State Rte_Read_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State
#  define Rte_Read_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State(data) (*(data) = Rte_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_pBtnState_B5_TIBtnMdl_State_State Rte_Read_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State
#  define Rte_Read_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State(data) (*(data) = Rte_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_pBtnState_B6_TIBtnMdl_State_State Rte_Read_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State
#  define Rte_Read_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State(data) (*(data) = Rte_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_pBtnState_B7_TIBtnMdl_State_State Rte_Read_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State
#  define Rte_Read_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State(data) (*(data) = Rte_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_rEng_TIEngMdl_Out_Tacho Rte_Read_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho
#  define Rte_Read_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho(data) (*(data) = Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed Rte_Read_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed
#  define Rte_Read_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSR_rSpd_TISpdMdl_Out_Speed Rte_Read_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed
#  define Rte_Read_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_OdoOutMiles_Miles Rte_Read_GdtCtrl_tiSR_OdoOutMiles_Miles
#  define Rte_Read_GdtCtrl_tiSR_OdoOutMiles_Miles(data) (*(data) = Rte_OdoMdl_tiSR_OdoOutMiles_Miles, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TrcOut_deTrcOut Rte_Read_GdtCtrl_tiSR_TrcOut_deTrcOut


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TRIPMDL_APPL_CODE) CTripMdl_ResetTrip(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_itCS_TripMdl_ResetTrip() (CTripMdl_ResetTrip(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_WRNCTRL_APPL_CODE) CWrnCtrl_Acknowledge(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge(arg1) (CWrnCtrl_Acknowledge(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_WRNCTRL_APPL_CODE) WrnCtrl_GetCount(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Count); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rList_TIWrnCtrl_Lists_GetCount WrnCtrl_GetCount
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_WRNCTRL_APPL_CODE) WrnCtrl_GetFirst(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rList_TIWrnCtrl_Lists_GetFirst WrnCtrl_GetFirst
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_WRNCTRL_APPL_CODE) WrnCtrl_GetNext(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rList_TIWrnCtrl_Lists_GetNext WrnCtrl_GetNext
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_WRNCTRL_APPL_CODE) WrnCtrl_Release(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rList_TIWrnCtrl_Lists_Release() (WrnCtrl_Release(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) CTmExt_Impl_DisableNotification(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rPulse_TITmExt_Pulse_DisableNotification(arg1, arg2) (CTmExt_Impl_DisableNotification(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) CTmExt_Impl_EnableNotification(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Sync); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rPulse_TITmExt_Pulse_EnableNotification(arg1, arg2, arg3) (CTmExt_Impl_EnableNotification(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_HMICTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_HMICTRL_APPL_CODE) CHmiCtrl_Gdt_Ready(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_HMICTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSub_TIHmiCtrl_SubReply_Ready(arg1) (CHmiCtrl_Gdt_Ready(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_WRNCTRL_APPL_CODE) WrnCtrl_Replays_Gdt_Ready(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_TIWrnCtrl_SyncReply_Ready(arg1, arg2) (WrnCtrl_Replays_Gdt_Ready(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_WRNCTRL_APPL_CODE) WrnCtrl_Replays_Gdt_Replay(TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WRNCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_rSync_TIWrnCtrl_SyncReply_Replay WrnCtrl_Replays_Gdt_Replay


# endif /* !defined(RTE_CORE) */


# define GdtCtrl_START_SEC_CODE
# include "GdtCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CGdtCtrl_Impl_MainFunction CGdtCtrl_Impl_MainFunction
#  define RTE_RUNNABLE_CGdtCtrl_Impl_Notification CGdtCtrl_Impl_Notification
#  define RTE_RUNNABLE_CGdtCtrl_Impl_OnCommand CGdtCtrl_Impl_OnCommand
#  define RTE_RUNNABLE_CGdtCtrl_Impl_PrepareSub CGdtCtrl_Impl_PrepareSub
#  define RTE_RUNNABLE_CGdtCtrl_Impl_Start CGdtCtrl_Impl_Start
#  define RTE_RUNNABLE_GdtCtrlRef_SpeedDataRx GdtCtrlRef_SpeedDataRx
#  define RTE_RUNNABLE_GdtCtrlRef_TachoDataRx GdtCtrlRef_TachoDataRx
#  define RTE_RUNNABLE_GdtCtrl_Cancel GdtCtrl_Cancel
#  define RTE_RUNNABLE_GdtCtrl_DiagAction GdtCtrl_DiagAction
#  define RTE_RUNNABLE_GdtCtrl_Latch GdtCtrl_Latch
#  define RTE_RUNNABLE_GdtCtrl_ListChange GdtCtrl_ListChange
#  define RTE_RUNNABLE_GdtCtrl_Prepare GdtCtrl_Prepare
#  define RTE_RUNNABLE_GdtCtrl_Stop GdtCtrl_Stop
# endif

FUNC(void, GdtCtrl_CODE) CGdtCtrl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtCtrl_CODE) CGdtCtrl_Impl_Notification(P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, GdtCtrl_CODE) CGdtCtrl_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, GdtCtrl_CODE) CGdtCtrl_Impl_PrepareSub(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, GdtCtrl_CODE) CGdtCtrl_Impl_Start(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, GdtCtrl_CODE) GdtCtrlRef_SpeedDataRx(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtCtrl_CODE) GdtCtrlRef_TachoDataRx(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtCtrl_CODE) GdtCtrl_Cancel(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, GdtCtrl_CODE) GdtCtrl_DiagAction(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, GdtCtrl_CODE) GdtCtrl_Latch(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, GdtCtrl_CODE) GdtCtrl_ListChange(TWrnListMask ListMask); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, GdtCtrl_CODE) GdtCtrl_Prepare(EWrnReason Reason, TWrnId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, GdtCtrl_CODE) GdtCtrl_Stop(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define GdtCtrl_STOP_SEC_CODE
# include "GdtCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_Diag_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIHmiCtrl_SubCmd_E_NOT_OK (1U)

#  define RTE_E_tiCS_TISystem_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_Lists_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_SyncCmd_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIWrnCtrl_SyncReply_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GDTCTRL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
