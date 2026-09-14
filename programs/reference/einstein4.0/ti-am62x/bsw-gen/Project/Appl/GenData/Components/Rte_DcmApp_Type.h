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
 *          File:  Rte_DcmApp_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <DcmApp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCMAPP_TYPE_H
# define _RTE_DCMAPP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
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

#  ifndef eRead
#   define eRead (0U)
#  endif

#  ifndef eWrite
#   define eWrite (1U)
#  endif

#  ifndef eSTA
#   define eSTA (2U)
#  endif

#  ifndef eRCTECU
#   define eRCTECU (3U)
#  endif

#  ifndef eCheckConditions
#   define eCheckConditions (4U)
#  endif

#  ifndef eRST2DEFAULT
#   define eRST2DEFAULT (5U)
#  endif

#  ifndef eFCS
#   define eFCS (6U)
#  endif

#  ifndef eLengthCheck
#   define eLengthCheck (7U)
#  endif

#  ifndef DIAG_INITIAL
#   define DIAG_INITIAL (0U)
#  endif

#  ifndef DIAG_PENDING
#   define DIAG_PENDING (1U)
#  endif

#  ifndef DIAG_CANCEL
#   define DIAG_CANCEL (2U)
#  endif

#  ifndef DIAG_FORCE_RCRRP_OK
#   define DIAG_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef DIAG_FORCE_RCRRP_NOT_OK
#   define DIAG_FORCE_RCRRP_NOT_OK (64U)
#  endif

#  ifndef eRoutineStart
#   define eRoutineStart (0U)
#  endif

#  ifndef eRoutineStop
#   define eRoutineStop (1U)
#  endif

#  ifndef eRoutineResult
#   define eRoutineResult (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCMAPP_TYPE_H */
