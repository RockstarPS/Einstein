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
 *          File:  Rte_Test_Comp_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Test_Comp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TEST_COMP_TYPE_H
# define _RTE_TEST_COMP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef EDisplayState_Off
#   define EDisplayState_Off (0U)
#  endif

#  ifndef EDisplayState_On
#   define EDisplayState_On (1U)
#  endif

#  ifndef EDisplayState_Error
#   define EDisplayState_Error (2U)
#  endif

#  ifndef EDisplayState_Disconnected
#   define EDisplayState_Disconnected (3U)
#  endif

#  ifndef EDisplayState_Last
#   define EDisplayState_Last (4U)
#  endif

#  ifndef EDomainId_VP
#   define EDomainId_VP (0U)
#  endif

#  ifndef EDomainId_Cluster
#   define EDomainId_Cluster (1U)
#  endif

#  ifndef EDomainId_IVI
#   define EDomainId_IVI (2U)
#  endif

#  ifndef EDomainId_Last
#   define EDomainId_Last (3U)
#  endif

#  ifndef ESystemState_Off
#   define ESystemState_Off (0U)
#  endif

#  ifndef ESystemState_Startup
#   define ESystemState_Startup (1U)
#  endif

#  ifndef ESystemState_Up
#   define ESystemState_Up (2U)
#  endif

#  ifndef ESystemState_FullRun
#   define ESystemState_FullRun (3U)
#  endif

#  ifndef ESystemState_PrepareShutdown
#   define ESystemState_PrepareShutdown (4U)
#  endif

#  ifndef ESystemState_Minimal
#   define ESystemState_Minimal (5U)
#  endif

#  ifndef ESystemState_Shutdown
#   define ESystemState_Shutdown (6U)
#  endif

#  ifndef ESystemState_Meet
#   define ESystemState_Meet (7U)
#  endif

#  ifndef ESystemState_Last
#   define ESystemState_Last (8U)
#  endif

#  ifndef EnetReqType_Reset
#   define EnetReqType_Reset (1U)
#  endif

#  ifndef EnetReqType_linkStatus
#   define EnetReqType_linkStatus (2U)
#  endif

#  ifndef EnetReqType_SqiVal
#   define EnetReqType_SqiVal (3U)
#  endif

#  ifndef EnetReqType_WorstSqiVal
#   define EnetReqType_WorstSqiVal (4U)
#  endif

#  ifndef EnetReqType_BestSqiVal
#   define EnetReqType_BestSqiVal (5U)
#  endif

#  ifndef EnetReqType_FaultStatus
#   define EnetReqType_FaultStatus (6U)
#  endif

#  ifndef EnetReqType_CableStatus
#   define EnetReqType_CableStatus (7U)
#  endif

#  ifndef EnetReqType_masterSlaveStatus
#   define EnetReqType_masterSlaveStatus (8U)
#  endif

#  ifndef EnetReqType_Last
#   define EnetReqType_Last (9U)
#  endif

#  ifndef EnetReqMode_Read
#   define EnetReqMode_Read (0U)
#  endif

#  ifndef EnetReqMode_Write
#   define EnetReqMode_Write (1U)
#  endif

#  ifndef EnetReqMode_Last
#   define EnetReqMode_Last (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TEST_COMP_TYPE_H */
