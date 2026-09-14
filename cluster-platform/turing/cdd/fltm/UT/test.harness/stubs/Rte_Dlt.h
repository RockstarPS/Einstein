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
 *   ECU-Project:  IC
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


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_ECUMEXT_APPL_CODE) EcuMExt_GetResetReason(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_EcumExt_GetResetReason_GetResetReason EcuMExt_GetResetReason


# endif /* !defined(RTE_CORE) */


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
#  define RTE_RUNNABLE_Dlt_SetTraceStatus Dlt_SetTraceStatus
#  define RTE_RUNNABLE_Dlt_StoreConfiguration Dlt_StoreConfiguration
#  define RTE_RUNNABLE_Dlt_UnregisterContext Dlt_UnregisterContext
# endif

FUNC(void, Dlt_CODE) Dlt_DetForwardErrorTrace(UInt16 moduleId, UInt8 instanceId, UInt8 apiId, UInt8 errorId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultLogLevel(P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) defaultLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultTraceStatus(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultTraceStatus(P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelNames(P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) numberOfLogChannels, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelNames); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelNames(P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) numberOfLogChannels, P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelNames); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelThreshold(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelThreshold, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelThreshold(P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelThreshold, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogInfo(UInt8 options, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) status, P2VAR(Dlt_LogInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) logInfo); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogInfo(UInt8 options, P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) status, P2VAR(Dlt_LogInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) logInfo); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetTraceStatus(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetTraceStatus(P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Dlt_CODE) Dlt_InjectCall_SESSION(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, UInt32 serviceId, UInt32 dataLength, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, Dlt_CODE) Dlt_InjectCall_SESSION(P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, UInt32 serviceId, UInt32 dataLength, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Dlt_CODE) Dlt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_RegisterContext(Dlt_SessionIDType sessionId, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) appDescription, UInt8 lenAppDescription, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) contextDescription, UInt8 lenContextDescription); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_RegisterContext(Dlt_SessionIDType sessionId, P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) appDescription, UInt8 lenAppDescription, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) contextDescription, UInt8 lenContextDescription); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Dlt_CODE) Dlt_ResetToFactoryDefault(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendLogMessage(Dlt_SessionIDType sessionId, P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) logInfo, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) logData, UInt16 logDataLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendTraceMessage(Dlt_SessionIDType sessionId, P2CONST(Dlt_MessageTraceInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) traceInfo, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) traceData, UInt16 traceDataLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultTraceStatus(Boolean newTraceStatus, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultTraceStatus(Boolean newTraceStatus, P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelAssignment(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_AssignmentOperation addRemoveOp); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelAssignment(P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_AssignmentOperation addRemoveOp); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelThreshold(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_MessageLogLevelType newThreshold, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelThreshold(P2VAR(Dlt_LogChannelNameType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_MessageLogLevelType newThreshold, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogLevel(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Dlt_MessageLogLevelType newLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogLevel(P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Dlt_MessageLogLevelType newLogLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetTraceStatus(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetTraceStatus(P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Boolean newTraceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Dlt_CODE) Dlt_StoreConfiguration(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlt_CODE) Dlt_UnregisterContext(Dlt_SessionIDType sessionId, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlt_CODE) Dlt_UnregisterContext(Dlt_SessionIDType sessionId, P2VAR(Dlt_ApplicationIDType, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Dlt_ContextIDType, AUTOMATIC, RTE_DLT_APPL_VAR) contextId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

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

#  define RTE_E_If_CS_Dlt_SetTraceStatus_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_StoreConfiguration_E_NOT_OK (1U)

#  define RTE_E_If_CS_Dlt_UnregisterContext_E_NOT_OK (1U)

#  define RTE_E_TI_EcuMExt_GetResetReason_E_NOT_OK (1U)
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
