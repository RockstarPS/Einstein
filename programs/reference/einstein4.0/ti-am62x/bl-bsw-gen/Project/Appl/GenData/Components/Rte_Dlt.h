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
 *          File:  Rte_Dlt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Dlt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DLT_H
# define _RTE_DLT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Dlt_Type.h"
# include "Rte_DataHandleType.h"


# define Dlt_START_SEC_CODE
# include "Dlt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dlt_DetForwardErrorTrace Dlt_DetForwardErrorTrace
#  define RTE_RUNNABLE_Dlt_GetDefaultLogLevel Dlt_GetDefaultLogLevel
#  define RTE_RUNNABLE_Dlt_GetDefaultTraceStatus Dlt_GetDefaultTraceStatus
#  define RTE_RUNNABLE_Dlt_GetLogChannelNames Dlt_GetLogChannelNames
#  define RTE_RUNNABLE_Dlt_GetLogChannelThreshold Dlt_GetLogChannelThreshold
#  define RTE_RUNNABLE_Dlt_GetLogInfo Dlt_GetLogInfo
#  define RTE_RUNNABLE_Dlt_GetTraceStatus Dlt_GetTraceStatus
#  define RTE_RUNNABLE_Dlt_InjectCall_SESSION Dlt_InjectCall_SESSION
#  define RTE_RUNNABLE_Dlt_MainFunction Dlt_MainFunction
#  define RTE_RUNNABLE_Dlt_RegisterContext Dlt_RegisterContext
#  define RTE_RUNNABLE_Dlt_ResetToFactoryDefault Dlt_ResetToFactoryDefault
#  define RTE_RUNNABLE_Dlt_SendLogMessage Dlt_SendLogMessage
#  define RTE_RUNNABLE_Dlt_SendTraceMessage Dlt_SendTraceMessage
#  define RTE_RUNNABLE_Dlt_SetDefaultLogLevel Dlt_SetDefaultLogLevel
#  define RTE_RUNNABLE_Dlt_SetDefaultTraceStatus Dlt_SetDefaultTraceStatus
#  define RTE_RUNNABLE_Dlt_SetLogChannelAssignment Dlt_SetLogChannelAssignment
#  define RTE_RUNNABLE_Dlt_SetLogChannelThreshold Dlt_SetLogChannelThreshold
#  define RTE_RUNNABLE_Dlt_SetLogLevel Dlt_SetLogLevel
#  define RTE_RUNNABLE_Dlt_SetMessageFiltering Dlt_SetMessageFiltering
#  define RTE_RUNNABLE_Dlt_SetTraceStatus Dlt_SetTraceStatus
#  define RTE_RUNNABLE_Dlt_StoreConfiguration Dlt_StoreConfiguration
#  define RTE_RUNNABLE_Dlt_UnregisterContext Dlt_UnregisterContext
# endif

FUNC(void, Dlt_CODE) Dlt_DetForwardErrorTrace(UInt16 moduleId, UInt8 instanceId, UInt8 apiId, UInt8 errorId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultLogLevel(P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) defaultLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultTraceStatus(Dlt_LogChannelNameType logChannelName, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelNames(P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) numberOfLogChannels, P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelNames); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelThreshold(Dlt_LogChannelNameType logChannelName, P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelThreshold, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogInfo(UInt8 options, Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) status, P2VAR(Dlt_LogInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) logInfo); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetTraceStatus(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Dlt_CODE) Dlt_InjectCall_SESSION(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, UInt32 serviceId, UInt32 dataLength, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Dlt_CODE) Dlt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_RegisterContext(Dlt_SessionIDType logmsg_session_id, Dlt_ApplicationIDType logmsg_app_id, Dlt_ContextIDType logmsg_context_id, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) logmsg_app_description, UInt8 logmsg_len_app_description, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) logmsg_context_description, UInt8 logmsg_len_context_description); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_ResetToFactoryDefault(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendLogMessage(Dlt_SessionIDType msg_session_id, P2VAR(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) msg_log_info, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) msg_logData, UInt16 msg_datalength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendTraceMessage(Dlt_SessionIDType sessionId, P2VAR(Dlt_MessageTraceInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) traceInfo, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) traceData, UInt16 traceDataLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultTraceStatus(Boolean newTraceStatus, Dlt_LogChannelNameType logChannelName); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelAssignment(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, Dlt_LogChannelNameType logChannelName, Dlt_AssignmentOperation addRemoveOp); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelThreshold(Dlt_LogChannelNameType logChannelName, Dlt_MessageLogLevelType newThreshold, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogLevel(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, Dlt_MessageLogLevelType newLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetMessageFiltering(Boolean MessageFilteringStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetTraceStatus(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_StoreConfiguration(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_UnregisterContext(Dlt_SessionIDType message_session_id, Dlt_ApplicationIDType message_app_id, Dlt_ContextIDType message_context_id); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Dlt_STOP_SEC_CODE
# include "Dlt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_If_CS_Dlt_GetDefaultLogLevel_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_GetDefaultTraceStatus_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_GetLogChannelNames_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_GetLogChannelThreshold_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_GetLogInfo_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_GetTraceStatus_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_RegisterContext_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_ResetToFactoryDefault_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SendLogMessage_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SendTraceMessage_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetDefaultLogLevel_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetDefaultTraceStatus_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetLogChannelAssignment_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetLogChannelThreshold_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetLogLevel_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetMessageFiltering_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_SetTraceStatus_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_StoreConfiguration_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_UnregisterContext_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DLT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
