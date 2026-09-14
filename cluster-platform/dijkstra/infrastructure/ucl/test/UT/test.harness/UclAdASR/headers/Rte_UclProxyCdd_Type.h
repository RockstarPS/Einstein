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
 *          File:  Rte_UclProxyCdd_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <UclProxyCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_UCLPROXYCDD_TYPE_H
# define _RTE_UCLPROXYCDD_TYPE_H

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

#  ifndef EDidType_Read
#   define EDidType_Read (0U)
#  endif

#  ifndef EDidType_Write
#   define EDidType_Write (1U)
#  endif

#  ifndef EDidType_Last
#   define EDidType_Last (2U)
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

#  ifndef EIOCtrlOptType_returnControlToECU
#   define EIOCtrlOptType_returnControlToECU (0U)
#  endif

#  ifndef EIOCtrlOptType_resetToDefault
#   define EIOCtrlOptType_resetToDefault (1U)
#  endif

#  ifndef EIOCtrlOptType_freezeCurrentState
#   define EIOCtrlOptType_freezeCurrentState (2U)
#  endif

#  ifndef EIOCtrlOptType_shortTermAdjustment
#   define EIOCtrlOptType_shortTermAdjustment (3U)
#  endif

#  ifndef EIOCtrlOptType_Last
#   define EIOCtrlOptType_Last (4U)
#  endif

#  ifndef EIgnitionStatus_Off
#   define EIgnitionStatus_Off (0U)
#  endif

#  ifndef EIgnitionStatus_Acc
#   define EIgnitionStatus_Acc (1U)
#  endif

#  ifndef EIgnitionStatus_Start
#   define EIgnitionStatus_Start (2U)
#  endif

#  ifndef EIgnitionStatus_Run
#   define EIgnitionStatus_Run (3U)
#  endif

#  ifndef EIgnitionStatus_Last
#   define EIgnitionStatus_Last (4U)
#  endif

#  ifndef ERoutineType_Start
#   define ERoutineType_Start (0U)
#  endif

#  ifndef ERoutineType_Stop
#   define ERoutineType_Stop (1U)
#  endif

#  ifndef ERoutineType_QueryResults
#   define ERoutineType_QueryResults (2U)
#  endif

#  ifndef ERoutineType_Last
#   define ERoutineType_Last (3U)
#  endif

#  ifndef ESidType_ReadDid
#   define ESidType_ReadDid (34U)
#  endif

#  ifndef ESidType_WriteDid
#   define ESidType_WriteDid (46U)
#  endif

#  ifndef ESidType_RoutineId
#   define ESidType_RoutineId (49U)
#  endif

#  ifndef ESidType_IoCtrl
#   define ESidType_IoCtrl (47U)
#  endif

#  ifndef ESidType_EcuReset
#   define ESidType_EcuReset (17U)
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
#   define ESystemState_Shutdown (7U)
#  endif

#  ifndef ESystemState_Last
#   define ESystemState_Last (8U)
#  endif

#  ifndef ESystemState_Meet
#   define ESystemState_Meet (6U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_UCLPROXYCDD_TYPE_H */
