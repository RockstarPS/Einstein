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
 *          File:  Rte_FastGaugeAdapter_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <FastGaugeAdapter>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_FASTGAUGEADAPTER_TYPE_H
# define _RTE_FASTGAUGEADAPTER_TYPE_H

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

#  ifndef EGaugeUnit_Mph
#   define EGaugeUnit_Mph (0U)
#  endif

#  ifndef EGaugeUnit_Kmph
#   define EGaugeUnit_Kmph (1U)
#  endif

#  ifndef EGaugeUnit_Centigrade
#   define EGaugeUnit_Centigrade (2U)
#  endif

#  ifndef EGaugeUnit_Farenheit
#   define EGaugeUnit_Farenheit (3U)
#  endif

#  ifndef EGaugeUnit_Psi
#   define EGaugeUnit_Psi (4U)
#  endif

#  ifndef EGaugeUnit_Pa
#   define EGaugeUnit_Pa (5U)
#  endif

#  ifndef EGaugeUnit_Bar
#   define EGaugeUnit_Bar (6U)
#  endif

#  ifndef EGaugeUnit_Kmpl
#   define EGaugeUnit_Kmpl (7U)
#  endif

#  ifndef EGaugeUnit_Mpg
#   define EGaugeUnit_Mpg (8U)
#  endif

#  ifndef EGaugeUnit_Ltr
#   define EGaugeUnit_Ltr (9U)
#  endif

#  ifndef EGaugeUnit_Gal
#   define EGaugeUnit_Gal (10U)
#  endif

#  ifndef EGaugeUnit_Km
#   define EGaugeUnit_Km (11U)
#  endif

#  ifndef EGaugeUnit_Mile
#   define EGaugeUnit_Mile (12U)
#  endif

#  ifndef EGaugeUnit_Last
#   define EGaugeUnit_Last (13U)
#  endif

#  ifndef eHMI_NOT_READY
#   define eHMI_NOT_READY (0U)
#  endif

#  ifndef eHMI_READY
#   define eHMI_READY (1U)
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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_FASTGAUGEADAPTER_TYPE_H */
