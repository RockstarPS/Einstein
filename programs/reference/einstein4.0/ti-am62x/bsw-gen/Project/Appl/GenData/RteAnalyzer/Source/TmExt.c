/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TmExt.c
 *        Config:  BMW.dpa
 *     SW-C Type:  TmExt
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <TmExt>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_TmExt.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_TmExt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void TmExt_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean
 * UInt32: Integer in interval [0...4294967295]
 *
 * Enumeration Types:
 * ==================
 * HTimer: Enumeration of integer in interval [0...80] with enumerators
 *   eWarningMask_Timerhandle (0U)
 *   eOWC_Timerhandle (1U)
 *   eNWD_Timerhandle (2U)
 *   eWarningBulbCheckMask_Timerhandle (3U)
 *   eInitWarning_TimerHandle (4U)
 *   eInitChimeTimerHandle (5U)
 *   eProgrammingTimerHandle (6U)
 *   eStubCounter_TimerHanlde (7U)
 *   eModeMgrDisplayPowerDownUp (8U)
 *   eModeMgrDisplayFaultAction (9U)
 *   eModeMgrDomanResetAction (10U)
 *   eModeMgrPowerFaultAction (11U)
 *   eEtm4SecTimer (12U)
 *   eEtm1200msecTimer (13U)
 *   eEtm3SecTimer (14U)
 *   eCallbackTimerOdoMdl (15U)
 *   eThrottleTimerOdoMdl (16U)
 *   eChangeupCallbackTimerodoMdl (17U)
 *   eTimerVehicleState (18U)
 *   eTimerVariantConfig (19U)
 *   WARNING_DISPLAY_TIMER_ID (20U)
 *   WARNING_HOLD_TIMER_ID (21U)
 *   WARNING_CYCLE_TIMER_ID (22U)
 *   WARNING_DISPLAYHOLD_TIMER_ID (23U)
 *   WARNING_ACK_TIMER_ID (24U)
 *   eTimerHandle_Sleep (25U)
 *   eInStartCount_TimerHandle (26U)
 *   eVehicleModeCount_TimerHandle (27U)
 *   e10secTimer (28U)
 *   e3secTimer (29U)
 *   e30secTimer (30U)
 *   e2_6secTimer (31U)
 *   eDcmApp5secTimer (32U)
 *   eDcmApp1secTimer (33U)
 *   eLidopen_OFFTimer (34U)
 *   eLidopen_ONTimer (35U)
 *   POPUP_DISPLAY_TIMER_ID (36U)
 *   POPUP_GRP_TAB_TIMER_ID (37U)
 *   eDrvRec5_6Timer (38U)
 *   eDrvRec3_6Timer (39U)
 *   eIDS_1SecTimer (40U)
 *   eIDS3_1SecTimer (41U)
 *   eIDS_3SecTimer (42U)
 *   ePerDispSet100msTimer (43U)
 *   eDrvRec1_2secTimer (44U)
 *   eDrvRec0_8secTimer (45U)
 *   eHMI_Initial_Blank_timer_ID (46U)
 *   eHMI_Fade_in_delay_timer_ID (47U)
 *   eKM6secTimer (48U)
 *   eKM5_8secTimer (49U)
 *   eKM0_6secTimer (50U)
 *   eKM0_2secTimer (51U)
 *   eIgnCANMode_3SecTimer (52U)
 *   eDem2_6secTimer (53U)
 *   eDem5secTimer (54U)
 *   e2FRheo5secTimer (55U)
 *   e2FSTSW5secTimer (56U)
 *   eLSTM3_Timer (57U)
 *   eLSTM4_Timer (58U)
 *   eDem_AFS_5sec_Timer (59U)
 *   WARNING_MSGTIMEOUT_1SEC_TIMER_ID (60U)
 *   eDCMApp_30Sec_Timer (61U)
 *   WRN_ACK_REDISPLAY_TIMER_ID (62U)
 *   eMenuScrollStart1sTimer (63U)
 *   eType4_6secTimer (64U)
 *   eDcmApp_0_35secTimer (65U)
 *   eDcmApp_0_35_1secTimer (66U)
 *   eRemoteCarFindCtrlStateTimer (67U)
 *   eBrake_Red_100msecTimer (68U)
 *   eStreeingSw_ReleaseTimer (69U)
 *   POPUP_SETTING_TIMER_ID (70U)
 *   eMenu100msTimer (71U)
 *   eBuzzerMiddleEast_6secs (72U)
 *   eBuzzerMiddleEast_6secs_2 (73U)
 *   eMaxNumof16BitTimers (74U)
 *   eSleepMaxTimer (75U)
 *   eRentACarTimer (76U)
 *   eDoorWarn_Timer (77U)
 *   eTimerHandleGdtCdd (78U)
 *   eSample32BitTimer (79U)
 *   eTimerMax (80U)
 *
 *********************************************************************************************************************/


#define TmExt_START_SEC_CODE
#include "TmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_MainFunction
 *********************************************************************************************************************/

  TmExt_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_Timer_GetElapsedTime
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Timer_GetElapsedTime> of PortPrototype <pp_CS_TmExt_Timer_GetElapsedTime>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TmExt_Timer_GetElapsedTime(HTimer hTimer, UInt32 *ElapsedTime)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_GetElapsedTime_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_Timer_GetElapsedTime(HTimer hTimer, P2VAR(UInt32, AUTOMATIC, RTE_TMEXT_APPL_VAR) ElapsedTime) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_GetElapsedTime
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_Timer_IsElapsed
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Timer_IsElapsed> of PortPrototype <pp_CS_TmExt_Timer_IsElapsed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TmExt_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_IsElapsed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsElapsed) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_IsElapsed
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_Timer_IsStarted
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Timer_IsStarted> of PortPrototype <pp_CS_TmExt_Timer_IsStarted>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TmExt_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_IsStarted_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_Timer_IsStarted(HTimer hTimer, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsStarted) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_IsStarted
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_Timer_Start
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Timer_Start> of PortPrototype <pp_CS_TmExt_Timer_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TmExt_Timer_Start(HTimer hTimer)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_Timer_Start(HTimer hTimer) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_Start
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmExt_Timer_Stop
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Timer_Stop> of PortPrototype <pp_CS_TmExt_Timer_Stop>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TmExt_Timer_Stop(HTimer hTimer)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TmExt_CODE) TmExt_Timer_Stop(HTimer hTimer) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_Timer_Stop
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TmExt_STOP_SEC_CODE
#include "TmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void TmExt_TestDefines(void)
{
  /* Enumeration Data Types */

  HTimer Test_HTimer_V_1 = eWarningMask_Timerhandle;
  HTimer Test_HTimer_V_2 = eOWC_Timerhandle;
  HTimer Test_HTimer_V_3 = eNWD_Timerhandle;
  HTimer Test_HTimer_V_4 = eWarningBulbCheckMask_Timerhandle;
  HTimer Test_HTimer_V_5 = eInitWarning_TimerHandle;
  HTimer Test_HTimer_V_6 = eInitChimeTimerHandle;
  HTimer Test_HTimer_V_7 = eProgrammingTimerHandle;
  HTimer Test_HTimer_V_8 = eStubCounter_TimerHanlde;
  HTimer Test_HTimer_V_9 = eModeMgrDisplayPowerDownUp;
  HTimer Test_HTimer_V_10 = eModeMgrDisplayFaultAction;
  HTimer Test_HTimer_V_11 = eModeMgrDomanResetAction;
  HTimer Test_HTimer_V_12 = eModeMgrPowerFaultAction;
  HTimer Test_HTimer_V_13 = eEtm4SecTimer;
  HTimer Test_HTimer_V_14 = eEtm1200msecTimer;
  HTimer Test_HTimer_V_15 = eEtm3SecTimer;
  HTimer Test_HTimer_V_16 = eCallbackTimerOdoMdl;
  HTimer Test_HTimer_V_17 = eThrottleTimerOdoMdl;
  HTimer Test_HTimer_V_18 = eChangeupCallbackTimerodoMdl;
  HTimer Test_HTimer_V_19 = eTimerVehicleState;
  HTimer Test_HTimer_V_20 = eTimerVariantConfig;
  HTimer Test_HTimer_V_21 = WARNING_DISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_22 = WARNING_HOLD_TIMER_ID;
  HTimer Test_HTimer_V_23 = WARNING_CYCLE_TIMER_ID;
  HTimer Test_HTimer_V_24 = WARNING_DISPLAYHOLD_TIMER_ID;
  HTimer Test_HTimer_V_25 = WARNING_ACK_TIMER_ID;
  HTimer Test_HTimer_V_26 = eTimerHandle_Sleep;
  HTimer Test_HTimer_V_27 = eInStartCount_TimerHandle;
  HTimer Test_HTimer_V_28 = eVehicleModeCount_TimerHandle;
  HTimer Test_HTimer_V_29 = e10secTimer;
  HTimer Test_HTimer_V_30 = e3secTimer;
  HTimer Test_HTimer_V_31 = e30secTimer;
  HTimer Test_HTimer_V_32 = e2_6secTimer;
  HTimer Test_HTimer_V_33 = eDcmApp5secTimer;
  HTimer Test_HTimer_V_34 = eDcmApp1secTimer;
  HTimer Test_HTimer_V_35 = eLidopen_OFFTimer;
  HTimer Test_HTimer_V_36 = eLidopen_ONTimer;
  HTimer Test_HTimer_V_37 = POPUP_DISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_38 = POPUP_GRP_TAB_TIMER_ID;
  HTimer Test_HTimer_V_39 = eDrvRec5_6Timer;
  HTimer Test_HTimer_V_40 = eDrvRec3_6Timer;
  HTimer Test_HTimer_V_41 = eIDS_1SecTimer;
  HTimer Test_HTimer_V_42 = eIDS3_1SecTimer;
  HTimer Test_HTimer_V_43 = eIDS_3SecTimer;
  HTimer Test_HTimer_V_44 = ePerDispSet100msTimer;
  HTimer Test_HTimer_V_45 = eDrvRec1_2secTimer;
  HTimer Test_HTimer_V_46 = eDrvRec0_8secTimer;
  HTimer Test_HTimer_V_47 = eHMI_Initial_Blank_timer_ID;
  HTimer Test_HTimer_V_48 = eHMI_Fade_in_delay_timer_ID;
  HTimer Test_HTimer_V_49 = eKM6secTimer;
  HTimer Test_HTimer_V_50 = eKM5_8secTimer;
  HTimer Test_HTimer_V_51 = eKM0_6secTimer;
  HTimer Test_HTimer_V_52 = eKM0_2secTimer;
  HTimer Test_HTimer_V_53 = eIgnCANMode_3SecTimer;
  HTimer Test_HTimer_V_54 = eDem2_6secTimer;
  HTimer Test_HTimer_V_55 = eDem5secTimer;
  HTimer Test_HTimer_V_56 = e2FRheo5secTimer;
  HTimer Test_HTimer_V_57 = e2FSTSW5secTimer;
  HTimer Test_HTimer_V_58 = eLSTM3_Timer;
  HTimer Test_HTimer_V_59 = eLSTM4_Timer;
  HTimer Test_HTimer_V_60 = eDem_AFS_5sec_Timer;
  HTimer Test_HTimer_V_61 = WARNING_MSGTIMEOUT_1SEC_TIMER_ID;
  HTimer Test_HTimer_V_62 = eDCMApp_30Sec_Timer;
  HTimer Test_HTimer_V_63 = WRN_ACK_REDISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_64 = eMenuScrollStart1sTimer;
  HTimer Test_HTimer_V_65 = eType4_6secTimer;
  HTimer Test_HTimer_V_66 = eDcmApp_0_35secTimer;
  HTimer Test_HTimer_V_67 = eDcmApp_0_35_1secTimer;
  HTimer Test_HTimer_V_68 = eRemoteCarFindCtrlStateTimer;
  HTimer Test_HTimer_V_69 = eBrake_Red_100msecTimer;
  HTimer Test_HTimer_V_70 = eStreeingSw_ReleaseTimer;
  HTimer Test_HTimer_V_71 = POPUP_SETTING_TIMER_ID;
  HTimer Test_HTimer_V_72 = eMenu100msTimer;
  HTimer Test_HTimer_V_73 = eBuzzerMiddleEast_6secs;
  HTimer Test_HTimer_V_74 = eBuzzerMiddleEast_6secs_2;
  HTimer Test_HTimer_V_75 = eMaxNumof16BitTimers;
  HTimer Test_HTimer_V_76 = eSleepMaxTimer;
  HTimer Test_HTimer_V_77 = eRentACarTimer;
  HTimer Test_HTimer_V_78 = eDoorWarn_Timer;
  HTimer Test_HTimer_V_79 = eTimerHandleGdtCdd;
  HTimer Test_HTimer_V_80 = eSample32BitTimer;
  HTimer Test_HTimer_V_81 = eTimerMax;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
