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
 *          File:  Rte_GdtCdd_Type.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application types header file for SW-C <GdtCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GDTCDD_TYPE_H
# define _RTE_GDTCDD_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GDTCDD_TYPE_H */
