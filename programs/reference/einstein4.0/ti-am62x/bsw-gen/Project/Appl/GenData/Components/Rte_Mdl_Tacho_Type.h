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
 *          File:  Rte_Mdl_Tacho_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Mdl_Tacho>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_TACHO_TYPE_H
# define _RTE_MDL_TACHO_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CLUSTER_INACTIVE
#   define CLUSTER_INACTIVE (0U)
#  endif

#  ifndef CLUSTER_ACTIVE
#   define CLUSTER_ACTIVE (1U)
#  endif

#  ifndef eFUNC_CANADA
#   define eFUNC_CANADA (0U)
#  endif

#  ifndef eFUNC_NORTH_AMERICA
#   define eFUNC_NORTH_AMERICA (1U)
#  endif

#  ifndef eFUNC_MEXICO
#   define eFUNC_MEXICO (2U)
#  endif

#  ifndef eFUNC_GENERAL_EXPORT
#   define eFUNC_GENERAL_EXPORT (3U)
#  endif

#  ifndef eFUNC_UK
#   define eFUNC_UK (4U)
#  endif

#  ifndef eFUNC_EUROPE
#   define eFUNC_EUROPE (5U)
#  endif

#  ifndef eFUNC_SOUTH_AFRICA
#   define eFUNC_SOUTH_AFRICA (6U)
#  endif

#  ifndef eFUNC_MIDDLE_EAST_ASIA
#   define eFUNC_MIDDLE_EAST_ASIA (7U)
#  endif

#  ifndef eFUNC_JAPAN
#   define eFUNC_JAPAN (8U)
#  endif

#  ifndef eFUNC_INDIA
#   define eFUNC_INDIA (9U)
#  endif

#  ifndef eFUNC_KOREA
#   define eFUNC_KOREA (10U)
#  endif

#  ifndef eFUNC_TAIWAN
#   define eFUNC_TAIWAN (11U)
#  endif

#  ifndef eFUNC_CHINA
#   define eFUNC_CHINA (12U)
#  endif

#  ifndef eFUNC_HONG_KONG
#   define eFUNC_HONG_KONG (13U)
#  endif

#  ifndef eFUNC_AUSTRALIA
#   define eFUNC_AUSTRALIA (14U)
#  endif

#  ifndef eSPEEDO
#   define eSPEEDO (1U)
#  endif

#  ifndef eTACHO
#   define eTACHO (2U)
#  endif

#  ifndef eHVSYS_INDICATOR
#   define eHVSYS_INDICATOR (4U)
#  endif

#  ifndef eSPEAKER
#   define eSPEAKER (8U)
#  endif

#  ifndef eTELLTALE
#   define eTELLTALE (16U)
#  endif

#  ifndef eBUTTONEVENT
#   define eBUTTONEVENT (32U)
#  endif

#  ifndef eMIDDISPALY
#   define eMIDDISPALY (64U)
#  endif

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
#  endif

#  ifndef eDayNightModeIn
#   define eDayNightModeIn (0U)
#  endif

#  ifndef eIllumination_levelIn
#   define eIllumination_levelIn (1U)
#  endif

#  ifndef eAmbient_Light_levelIn
#   define eAmbient_Light_levelIn (2U)
#  endif

#  ifndef ePowerModeIn
#   define ePowerModeIn (3U)
#  endif

#  ifndef eTransportModeIn
#   define eTransportModeIn (4U)
#  endif

#  ifndef eGearModeIn
#   define eGearModeIn (5U)
#  endif

#  ifndef eGearRecommendationIn
#   define eGearRecommendationIn (6U)
#  endif

#  ifndef eGearIn
#   define eGearIn (7U)
#  endif

#  ifndef eWarningIn
#   define eWarningIn (8U)
#  endif

#  ifndef eGearStatusIn
#   define eGearStatusIn (9U)
#  endif

#  ifndef eEngineSpeedIn
#   define eEngineSpeedIn (10U)
#  endif

#  ifndef eTurn_Indicator_ControlIn
#   define eTurn_Indicator_ControlIn (11U)
#  endif

#  ifndef eEndOfRxSignal
#   define eEndOfRxSignal (12U)
#  endif

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_TACHO_TYPE_H */
