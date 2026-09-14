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
 *          File:  Rte_Dlt_Type.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Dlt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DLT_TYPE_H
# define _RTE_DLT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DLT_ASSIGN_ADD
#   define DLT_ASSIGN_ADD (1U)
#  endif

#  ifndef DLT_ASSIGN_REMOVE
#   define DLT_ASSIGN_REMOVE (2U)
#  endif

#  ifndef DLT_LOG_OFF
#   define DLT_LOG_OFF (0U)
#  endif

#  ifndef DLT_LOG_FATAL
#   define DLT_LOG_FATAL (1U)
#  endif

#  ifndef DLT_LOG_ERROR
#   define DLT_LOG_ERROR (2U)
#  endif

#  ifndef DLT_LOG_WARN
#   define DLT_LOG_WARN (3U)
#  endif

#  ifndef DLT_LOG_INFO
#   define DLT_LOG_INFO (4U)
#  endif

#  ifndef DLT_LOG_DEBUG
#   define DLT_LOG_DEBUG (5U)
#  endif

#  ifndef DLT_LOG_VERBOSE
#   define DLT_LOG_VERBOSE (6U)
#  endif

#  ifndef DLT_TRACE_VARIABLE
#   define DLT_TRACE_VARIABLE (1U)
#  endif

#  ifndef DLT_TRACE_FUNCTION_IN
#   define DLT_TRACE_FUNCTION_IN (2U)
#  endif

#  ifndef DLT_TRACE_FUNCTION_OUT
#   define DLT_TRACE_FUNCTION_OUT (3U)
#  endif

#  ifndef DLT_TRACE_STATE
#   define DLT_TRACE_STATE (4U)
#  endif

#  ifndef DLT_TRACE_VFB
#   define DLT_TRACE_VFB (5U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DLT_TYPE_H */
