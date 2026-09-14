/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_TmExt_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <TmExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TMEXT_TYPE_H
# define _RTE_TMEXT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eWarningMask_Timerhandle
#   define eWarningMask_Timerhandle (0U)
#  endif

#  ifndef eOWC_Timerhandle
#   define eOWC_Timerhandle (1U)
#  endif

#  ifndef eNWD_Timerhandle
#   define eNWD_Timerhandle (2U)
#  endif

#  ifndef eWarningBulbCheckMask_Timerhandle
#   define eWarningBulbCheckMask_Timerhandle (3U)
#  endif

#  ifndef eInitWarning_TimerHandle
#   define eInitWarning_TimerHandle (4U)
#  endif

#  ifndef eInitChimeTimerHandle
#   define eInitChimeTimerHandle (5U)
#  endif

#  ifndef eProgrammingTimerHandle
#   define eProgrammingTimerHandle (6U)
#  endif

#  ifndef eStubCounter_TimerHanlde
#   define eStubCounter_TimerHanlde (7U)
#  endif

#  ifndef eModeMgrDisplayPowerDownUp
#   define eModeMgrDisplayPowerDownUp (8U)
#  endif

#  ifndef eModeMgrDisplayFaultAction
#   define eModeMgrDisplayFaultAction (9U)
#  endif

#  ifndef eModeMgrDomanResetAction
#   define eModeMgrDomanResetAction (10U)
#  endif

#  ifndef eModeMgrPowerFaultAction
#   define eModeMgrPowerFaultAction (11U)
#  endif

#  ifndef eEtm4SecTimer
#   define eEtm4SecTimer (12U)
#  endif

#  ifndef eEtm1200msecTimer
#   define eEtm1200msecTimer (13U)
#  endif

#  ifndef eEtm3SecTimer
#   define eEtm3SecTimer (14U)
#  endif

#  ifndef eCallbackTimerOdoMdl
#   define eCallbackTimerOdoMdl (15U)
#  endif

#  ifndef eThrottleTimerOdoMdl
#   define eThrottleTimerOdoMdl (16U)
#  endif

#  ifndef eChangeupCallbackTimerodoMdl
#   define eChangeupCallbackTimerodoMdl (17U)
#  endif

#  ifndef eTimerVehicleState
#   define eTimerVehicleState (18U)
#  endif

#  ifndef eTimerVariantConfig
#   define eTimerVariantConfig (19U)
#  endif

#  ifndef WARNING_DISPLAY_TIMER_ID
#   define WARNING_DISPLAY_TIMER_ID (20U)
#  endif

#  ifndef WARNING_HOLD_TIMER_ID
#   define WARNING_HOLD_TIMER_ID (21U)
#  endif

#  ifndef WARNING_CYCLE_TIMER_ID
#   define WARNING_CYCLE_TIMER_ID (22U)
#  endif

#  ifndef WARNING_DISPLAYHOLD_TIMER_ID
#   define WARNING_DISPLAYHOLD_TIMER_ID (23U)
#  endif

#  ifndef WARNING_ACK_TIMER_ID
#   define WARNING_ACK_TIMER_ID (24U)
#  endif

#  ifndef eTimerHandle_Sleep
#   define eTimerHandle_Sleep (25U)
#  endif

#  ifndef eInStartCount_TimerHandle
#   define eInStartCount_TimerHandle (26U)
#  endif

#  ifndef eVehicleModeCount_TimerHandle
#   define eVehicleModeCount_TimerHandle (27U)
#  endif

#  ifndef e10secTimer
#   define e10secTimer (28U)
#  endif

#  ifndef e3secTimer
#   define e3secTimer (29U)
#  endif

#  ifndef e30secTimer
#   define e30secTimer (30U)
#  endif

#  ifndef e2_6secTimer
#   define e2_6secTimer (31U)
#  endif

#  ifndef eDcmApp5secTimer
#   define eDcmApp5secTimer (32U)
#  endif

#  ifndef eDcmApp1secTimer
#   define eDcmApp1secTimer (33U)
#  endif

#  ifndef eLidopen_OFFTimer
#   define eLidopen_OFFTimer (34U)
#  endif

#  ifndef eLidopen_ONTimer
#   define eLidopen_ONTimer (35U)
#  endif

#  ifndef POPUP_DISPLAY_TIMER_ID
#   define POPUP_DISPLAY_TIMER_ID (36U)
#  endif

#  ifndef POPUP_GRP_TAB_TIMER_ID
#   define POPUP_GRP_TAB_TIMER_ID (37U)
#  endif

#  ifndef eDrvRec5_6Timer
#   define eDrvRec5_6Timer (38U)
#  endif

#  ifndef eDrvRec3_6Timer
#   define eDrvRec3_6Timer (39U)
#  endif

#  ifndef eIDS_1SecTimer
#   define eIDS_1SecTimer (40U)
#  endif

#  ifndef eIDS3_1SecTimer
#   define eIDS3_1SecTimer (41U)
#  endif

#  ifndef eIDS_3SecTimer
#   define eIDS_3SecTimer (42U)
#  endif

#  ifndef ePerDispSet100msTimer
#   define ePerDispSet100msTimer (43U)
#  endif

#  ifndef eDrvRec1_2secTimer
#   define eDrvRec1_2secTimer (44U)
#  endif

#  ifndef eDrvRec0_8secTimer
#   define eDrvRec0_8secTimer (45U)
#  endif

#  ifndef eHMI_Initial_Blank_timer_ID
#   define eHMI_Initial_Blank_timer_ID (46U)
#  endif

#  ifndef eHMI_Fade_in_delay_timer_ID
#   define eHMI_Fade_in_delay_timer_ID (47U)
#  endif

#  ifndef eKM6secTimer
#   define eKM6secTimer (48U)
#  endif

#  ifndef eKM5_8secTimer
#   define eKM5_8secTimer (49U)
#  endif

#  ifndef eKM0_6secTimer
#   define eKM0_6secTimer (50U)
#  endif

#  ifndef eKM0_2secTimer
#   define eKM0_2secTimer (51U)
#  endif

#  ifndef eIgnCANMode_3SecTimer
#   define eIgnCANMode_3SecTimer (52U)
#  endif

#  ifndef eDem2_6secTimer
#   define eDem2_6secTimer (53U)
#  endif

#  ifndef eDem5secTimer
#   define eDem5secTimer (54U)
#  endif

#  ifndef e2FRheo5secTimer
#   define e2FRheo5secTimer (55U)
#  endif

#  ifndef e2FSTSW5secTimer
#   define e2FSTSW5secTimer (56U)
#  endif

#  ifndef eLSTM3_Timer
#   define eLSTM3_Timer (57U)
#  endif

#  ifndef eLSTM4_Timer
#   define eLSTM4_Timer (58U)
#  endif

#  ifndef eDem_AFS_5sec_Timer
#   define eDem_AFS_5sec_Timer (59U)
#  endif

#  ifndef WARNING_MSGTIMEOUT_1SEC_TIMER_ID
#   define WARNING_MSGTIMEOUT_1SEC_TIMER_ID (60U)
#  endif

#  ifndef eDCMApp_30Sec_Timer
#   define eDCMApp_30Sec_Timer (61U)
#  endif

#  ifndef WRN_ACK_REDISPLAY_TIMER_ID
#   define WRN_ACK_REDISPLAY_TIMER_ID (62U)
#  endif

#  ifndef eMenuScrollStart1sTimer
#   define eMenuScrollStart1sTimer (63U)
#  endif

#  ifndef eType4_6secTimer
#   define eType4_6secTimer (64U)
#  endif

#  ifndef eDcmApp_0_35secTimer
#   define eDcmApp_0_35secTimer (65U)
#  endif

#  ifndef eDcmApp_0_35_1secTimer
#   define eDcmApp_0_35_1secTimer (66U)
#  endif

#  ifndef eRemoteCarFindCtrlStateTimer
#   define eRemoteCarFindCtrlStateTimer (67U)
#  endif

#  ifndef eBrake_Red_100msecTimer
#   define eBrake_Red_100msecTimer (68U)
#  endif

#  ifndef eStreeingSw_ReleaseTimer
#   define eStreeingSw_ReleaseTimer (69U)
#  endif

#  ifndef POPUP_SETTING_TIMER_ID
#   define POPUP_SETTING_TIMER_ID (70U)
#  endif

#  ifndef eMenu100msTimer
#   define eMenu100msTimer (71U)
#  endif

#  ifndef eBuzzerMiddleEast_6secs
#   define eBuzzerMiddleEast_6secs (72U)
#  endif

#  ifndef eBuzzerMiddleEast_6secs_2
#   define eBuzzerMiddleEast_6secs_2 (73U)
#  endif

#  ifndef eMaxNumof16BitTimers
#   define eMaxNumof16BitTimers (74U)
#  endif

#  ifndef eSleepMaxTimer
#   define eSleepMaxTimer (75U)
#  endif

#  ifndef eRentACarTimer
#   define eRentACarTimer (76U)
#  endif

#  ifndef eDoorWarn_Timer
#   define eDoorWarn_Timer (77U)
#  endif

#  ifndef eTimerHandleGdtCdd
#   define eTimerHandleGdtCdd (78U)
#  endif

#  ifndef eSample32BitTimer
#   define eSample32BitTimer (79U)
#  endif

#  ifndef eTimerMax
#   define eTimerMax (80U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TMEXT_TYPE_H */
