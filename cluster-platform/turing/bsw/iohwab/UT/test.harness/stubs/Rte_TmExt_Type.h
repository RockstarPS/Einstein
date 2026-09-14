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
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
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

#  ifndef eBsw_Can_Emmision_Timer
#   define eBsw_Can_Emmision_Timer (0U)
#  endif

#  ifndef eBsw_Can_FrameTimeout
#   define eBsw_Can_FrameTimeout (1U)
#  endif

#  ifndef eBsw_DiagFuelDTC_Timer
#   define eBsw_DiagFuelDTC_Timer (2U)
#  endif

#  ifndef eBsw_DiagHoldApplMode_Timer
#   define eBsw_DiagHoldApplMode_Timer (3U)
#  endif

#  ifndef eBsw_Wus_Judgement_Timer
#   define eBsw_Wus_Judgement_Timer (4U)
#  endif

#  ifndef eBsw_Wus_S1S4Timer
#   define eBsw_Wus_S1S4Timer (5U)
#  endif

#  ifndef eNvmExtSf_Timer
#   define eNvmExtSf_Timer (6U)
#  endif

#  ifndef eTLTAirbag_Timer
#   define eTLTAirbag_Timer (7U)
#  endif

#  ifndef eTLTHandsOff_Timer
#   define eTLTHandsOff_Timer (8U)
#  endif

#  ifndef eTLTPark_Timer
#   define eTLTPark_Timer (9U)
#  endif

#  ifndef eTLTService_Timer
#   define eTLTService_Timer (10U)
#  endif

#  ifndef eTLTStop_Timer
#   define eTLTStop_Timer (11U)
#  endif

#  ifndef eView_Illumination_DimOutDisable_Timer
#   define eView_Illumination_DimOutDisable_Timer (12U)
#  endif

#  ifndef eView_Illumination_OverC_DeadTimer
#   define eView_Illumination_OverC_DeadTimer (13U)
#  endif

#  ifndef eView_Illumination_OverC_ProtectTimer
#   define eView_Illumination_OverC_ProtectTimer (14U)
#  endif

#  ifndef eView_Illumination_OverCurrent_Timer
#   define eView_Illumination_OverCurrent_Timer (15U)
#  endif

#  ifndef eView_Illumination_UnderVoltageRecovery
#   define eView_Illumination_UnderVoltageRecovery (16U)
#  endif

#  ifndef eVirtualDiagReq_Timer
#   define eVirtualDiagReq_Timer (17U)
#  endif

#  ifndef eModeMgrChimePowerDownUp
#   define eModeMgrChimePowerDownUp (18U)
#  endif

#  ifndef eModeMgrDisplayPowerDownUp
#   define eModeMgrDisplayPowerDownUp (19U)
#  endif

#  ifndef eView_Illumination_InitialDimOut_Timer
#   define eView_Illumination_InitialDimOut_Timer (20U)
#  endif

#  ifndef eIohwabExt_Pwm0_Timer
#   define eIohwabExt_Pwm0_Timer (21U)
#  endif

#  ifndef eIohwabExt_Pwm1_Timer
#   define eIohwabExt_Pwm1_Timer (22U)
#  endif

#  ifndef eIohwabExt_Pwm2_Timer
#   define eIohwabExt_Pwm2_Timer (23U)
#  endif

#  ifndef eMaxNumof16BitTimers
#   define eMaxNumof16BitTimers (24U)
#  endif

#  ifndef eSample32BitTimer
#   define eSample32BitTimer (25U)
#  endif

#  ifndef eTelltaleRequestControlTimer
#   define eTelltaleRequestControlTimer (26U)
#  endif

#  ifndef eMemCheckSf_Timer
#   define eMemCheckSf_Timer (27U)
#  endif

#  ifndef eTimerSWCModelActivation
#   define eTimerSWCModelActivation (28U)
#  endif

#  ifndef eTFT_DeratingTimer
#   define eTFT_DeratingTimer (29U)
#  endif

#  ifndef eTimerMax
#   define eTimerMax (30U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TMEXT_TYPE_H */
