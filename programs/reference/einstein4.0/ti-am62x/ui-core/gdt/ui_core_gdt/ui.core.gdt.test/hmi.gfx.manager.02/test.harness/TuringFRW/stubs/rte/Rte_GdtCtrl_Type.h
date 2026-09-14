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
 *          File:  Rte_GdtCtrl_Type.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application types header file for SW-C <GdtCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GDTCTRL_TYPE_H
# define _RTE_GDTCTRL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eEBtnState_NotPressed
#   define eEBtnState_NotPressed (0U)
#  endif

#  ifndef eEBtnState_Pressed
#   define eEBtnState_Pressed (1U)
#  endif

#  ifndef eEBtnState_ShortPress
#   define eEBtnState_ShortPress (2U)
#  endif

#  ifndef eEBtnState_LongPress1
#   define eEBtnState_LongPress1 (3U)
#  endif

#  ifndef eEBtnState_LongPress2
#   define eEBtnState_LongPress2 (4U)
#  endif

#  ifndef eEBtnState_LongPress3
#   define eEBtnState_LongPress3 (5U)
#  endif

#  ifndef eEBtnState_LongPress4
#   define eEBtnState_LongPress4 (6U)
#  endif

#  ifndef eEBtnState_LongPress5
#   define eEBtnState_LongPress5 (7U)
#  endif

#  ifndef eEBtnState_ThumbwheelRolling
#   define eEBtnState_ThumbwheelRolling (8U)
#  endif

#  ifndef eEBtnState_Count
#   define eEBtnState_Count (9U)
#  endif

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#  endif

#  ifndef eCmpCmd_DeActivate
#   define eCmpCmd_DeActivate (3U)
#  endif

#  ifndef eCmpCmd_Reset
#   define eCmpCmd_Reset (4U)
#  endif

#  ifndef eCmpCmd_ReStart
#   define eCmpCmd_ReStart (5U)
#  endif

#  ifndef eCmpCmd_ExternalCount
#   define eCmpCmd_ExternalCount (6U)
#  endif

#  ifndef eCmpCmd_DiagStart
#   define eCmpCmd_DiagStart (7U)
#  endif

#  ifndef eCmpCmd_DiagStop
#   define eCmpCmd_DiagStop (8U)
#  endif

#  ifndef eCmpCmd_Count
#   define eCmpCmd_Count (9U)
#  endif

#  ifndef eDcmExt_Write
#   define eDcmExt_Write (0U)
#  endif

#  ifndef eDcmExt_Read
#   define eDcmExt_Read (1U)
#  endif

#  ifndef eDcmExt_IOCtrl
#   define eDcmExt_IOCtrl (2U)
#  endif

#  ifndef eDcmExt_RoutineCtrl
#   define eDcmExt_RoutineCtrl (3U)
#  endif

#  ifndef eHmiSubId_Welcome
#   define eHmiSubId_Welcome (0U)
#  endif

#  ifndef eHmiSubId_ETM100
#   define eHmiSubId_ETM100 (1U)
#  endif

#  ifndef eHmiSubId_ETM110
#   define eHmiSubId_ETM110 (2U)
#  endif

#  ifndef eHmiSubId_ETM120
#   define eHmiSubId_ETM120 (3U)
#  endif

#  ifndef eHmiSubId_ETM130
#   define eHmiSubId_ETM130 (4U)
#  endif

#  ifndef eHmiSubId_ETM230
#   define eHmiSubId_ETM230 (5U)
#  endif

#  ifndef eHmiSubId_ETM233
#   define eHmiSubId_ETM233 (6U)
#  endif

#  ifndef eHmiSubId_Count
#   define eHmiSubId_Count (7U)
#  endif

#  ifndef ePulsePhase_Off
#   define ePulsePhase_Off (0U)
#  endif

#  ifndef ePulsePhase_On
#   define ePulsePhase_On (1U)
#  endif

#  ifndef ePulsePhase_Any
#   define ePulsePhase_Any (2U)
#  endif

#  ifndef eWrnReason_TopActive
#   define eWrnReason_TopActive (0U)
#  endif

#  ifndef eWrnReason_Replay
#   define eWrnReason_Replay (1U)
#  endif

#  ifndef eWrnReason_Count
#   define eWrnReason_Count (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GDTCTRL_TYPE_H */
