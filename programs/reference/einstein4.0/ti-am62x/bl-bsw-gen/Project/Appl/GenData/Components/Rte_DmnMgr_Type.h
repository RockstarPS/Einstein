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
 *          File:  Rte_DmnMgr_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <DmnMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DMNMGR_TYPE_H
# define _RTE_DMNMGR_TYPE_H

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

#  ifndef EDmnChangeReqStatus_NoReq
#   define EDmnChangeReqStatus_NoReq (0U)
#  endif

#  ifndef EDmnChangeReqStatus_WaitAwakeTime
#   define EDmnChangeReqStatus_WaitAwakeTime (1U)
#  endif

#  ifndef EDmnChangeReqStatus_WaitShutdonwTime
#   define EDmnChangeReqStatus_WaitShutdonwTime (2U)
#  endif

#  ifndef EDmnChangeReqStatus_PrevReqPending
#   define EDmnChangeReqStatus_PrevReqPending (3U)
#  endif

#  ifndef EDmnChangeReqStatus_ReqSucceed
#   define EDmnChangeReqStatus_ReqSucceed (4U)
#  endif

#  ifndef EDmnChangeReqStatus_ReqFail
#   define EDmnChangeReqStatus_ReqFail (5U)
#  endif

#  ifndef EDmnChangeReqStatus_ReqTimedOut
#   define EDmnChangeReqStatus_ReqTimedOut (6U)
#  endif

#  ifndef EDmnChangeReqStatus_DmnNotReady
#   define EDmnChangeReqStatus_DmnNotReady (7U)
#  endif

#  ifndef EDmnHealth_Active
#   define EDmnHealth_Active (0U)
#  endif

#  ifndef EDmnHealth_UCL_Fatal_Error
#   define EDmnHealth_UCL_Fatal_Error (1U)
#  endif

#  ifndef EDmnHealth_HB_Miss
#   define EDmnHealth_HB_Miss (2U)
#  endif

#  ifndef EDmnHealth_Fatal_Error
#   define EDmnHealth_Fatal_Error (3U)
#  endif

#  ifndef EDmnHealth_Rcvd_Inv_SeqCnt
#   define EDmnHealth_Rcvd_Inv_SeqCnt (4U)
#  endif

#  ifndef EDmnHealth_First_HB_Rcv_Time_Expired
#   define EDmnHealth_First_HB_Rcv_Time_Expired (5U)
#  endif

#  ifndef EDmnHealth_First_LinkUp_Time_Expired
#   define EDmnHealth_First_LinkUp_Time_Expired (6U)
#  endif

#  ifndef EDmnHealth_Shutdown_Time_Expired
#   define EDmnHealth_Shutdown_Time_Expired (7U)
#  endif

#  ifndef EDmnHealth_Last
#   define EDmnHealth_Last (8U)
#  endif

#  ifndef DMN_NOT_READY
#   define DMN_NOT_READY (0U)
#  endif

#  ifndef DMN_READY
#   define DMN_READY (1U)
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

#  ifndef ESystemState_Last
#   define ESystemState_Last (7U)
#  endif

#  ifndef EUclLinkState_Not_Rcvd
#   define EUclLinkState_Not_Rcvd (0U)
#  endif

#  ifndef EUclLinkState_Down
#   define EUclLinkState_Down (1U)
#  endif

#  ifndef EUclLinkState_Up
#   define EUclLinkState_Up (2U)
#  endif

#  ifndef EUclLinkState_Last
#   define EUclLinkState_Last (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DMNMGR_TYPE_H */
