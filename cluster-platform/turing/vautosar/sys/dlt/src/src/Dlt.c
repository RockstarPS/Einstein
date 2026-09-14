/******************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/******************************************************************************
 *  File Name         :  Dlt.c                                                *
 *  Module Short Name :  Dlt                                                  *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace module                                 *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLT_C
#define DLT_C

/******************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dlt.h"
#include "Det.h"
#include "Dcm.h"
#include "Rte_Dlt.h"

/******************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define DLT_RX_BUFF_SIZE        0xFFU
#define DLT_RX_PDU_ID           0x07u
#define DLT_TX_PDU_ID           0x08u

/******************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/******************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
static tDlt_LocalConfigDataType Dlt_LocalConfigData;
static uint8 LogMessageCount = MAX_MSG_COUNT_RESET; // initialize the counter to zero
static uint8 Dlt_TxBuffer[DLT_RX_BUFF_SIZE] = {0U};
static uint8 Dlt_RxBuffer[DLT_RX_BUFF_SIZE] = {0U};
static uint8 DltInternalBuffPos;     // need to assign to 0 in startofreception
static uint8 TpSduLengthDltInternal; //  will get this input from startofreception (TpSduLength) need to store in local
static uint8 Dlt_HeaderBuffer[DLT_MAX_HEADER_BUFF_SIZE] = {0U};
static uint8 DltHeaderActLength = 0U;
static LogChannelBufferType logChannelBufferInternal[DLT_NUM_LOGCHANNELREF];
static LogChannelBufferType logChannelBufferTX[DLT_NUM_LOGCHANNELREF];
static DltLogMsgInfo DltLogMsg = {0U};
static DltSwcContext_Type DltSwcContextInternal[DLT_MAX_NUM_SWCCONTEXT] = {0U};
static DltLogChannelAssignment_Type DltLogChannelAssignmentInternal[DLT_MAX_NUM_LOGCHANNELASSIGNMENT] = {0U};
static uint8 Dlt_InternalBuffer[DLT_INTERNAL_BUFFER_SIZE] = {0U};
//----------------------------------------------------------------------------------------------------------------------
/// Local function prototypes
//----------------------------------------------------------------------------------------------------------------------
#if (DLT_GENERAL_VERSIONINFOAPI == STD_ON)
void Dlt_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

static Dlt_ReturnType Dlt_FilterMessage(const Dlt_MessageLogInfoType *logInfo);
static Dlt_ReturnType Dlt_SelectTargetLogChannels(const Dlt_MessageLogInfoType *logInfo);
static Dlt_ReturnType Dlt_CheckMessageLength(uint16 logDataLength);
static Dlt_ReturnType Dlt_ApplyLogLevelThreshold(Dlt_MessageLogLevelType logLevel);
static Dlt_ReturnType Dlt_CopyMessageToBuffers(uint32 sessionId, uint32 timeStamp, const Dlt_MessageLogInfoType *logInfo, const uint8 *logData, uint16 logDataLength);
static void Dlt_CreateDltLogHeader(uint32 sessionId, uint32 timeStamp, const Dlt_MessageLogInfoType *logInfo, uint16 logDataLength);
static void Dlt_CreateDltTraceHeader(uint32 sessionId, uint32 timeStamp, const Dlt_MessageTraceInfoType *traceInfo, uint16 logDataLength);
static void Dlt_TxFunction(void);
static uint32 Dlt_GenerateTimestamp(void);
static void Dlt_MessageCounter(void);

/*============================================================================
**
** Function Name    :   Dlt_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Returns the version information
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType * VersionInfo - Pointer to a Version Info type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
#if (DLT_GENERAL_VERSIONINFOAPI == STD_ON)
void Dlt_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
    if (NULL != VersionInfo)
    {
        VersionInfo->vendorID = (uint16)DLT_VENDOR_ID;
        VersionInfo->moduleID = (uint16)DLT_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)DLT_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DLT_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DLT_SW_PATCH_VERSION;
    }
}
#endif

/*============================================================================
**
** Function Name    :   Dlt_InitMemory
**
** Visibility       :   Public
**
** Description      :   The InitMemory function is called to initialise the
**                      state machine to enabbe logging before init is called.
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void Dlt_InitMemory(void)
{
    /*Initialising Register Context array value to zero*/
    MemLib_MemCpy(DltSwcContextInternal, DltSwcContext, sizeof(DltSwcContext));
    MemLib_MemCpy(DltLogChannelAssignmentInternal, DltLogChannelAssignment, sizeof(DltLogChannelAssignment));
    Dlt_LocalConfigData.regContextIDCount = DLT_NUM_SWCCONTEXT;
}

/*============================================================================
**
** Function Name    :   Dlt_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void Dlt_Init(const Dlt_ConfigType *config)
{
    /* Memory Initialisation */
    Dlt_InitMemory();

    /* Loading the Values in local structure SessionId and InIt status*/
    Dlt_LocalConfigData.sessionID = DltConfig.sessionID;
    Dlt_LocalConfigData.initStatus = DltConfig.initStatus;
    Dlt_LocalConfigData.filterEnabled = DltConfig.filterEnabled;
    Dlt_LocalConfigData.regContextIDCount = DLT_NUM_SWCCONTEXT;

    /* DltExt Initialisation */
    #if (DLT_USE_VAUTOSAR_DLTEXT == STD_ON)
    DLTEXT_INIT_CALLOUT();
    #endif
}

/*============================================================================
**
** Function Name    :   Dlt_MainFunction
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void Dlt_MainFunction(void)
{
    /*DltExt Main function Call*/
    #if (DLT_USE_VAUTOSAR_DLTEXT == STD_ON)
    DLTEXT_MAIN_CALLOUT();
    #endif

    Dlt_TxFunction();

    /* TestCode function used to test using stubs*/
    #if (DLT_TESTCODE_EN == STD_ON)
    DLT_TESTCODE_CALLOUT();
    #endif
}

/*============================================================================
**
** Function Name    :   Dlt_SendTraceMessage
**
** Visibility       :   Public
**
** Description      :   The service represents the interface to be used by basic
**                      software modules or by software components to trace parameters.
**
** Invocation       :
**
** Inputs           :   Dlt_SessionIDType session_id - session id
**                      const Dlt_MessageTraceInfoType* traceInfo - Information for filtering the message
**                      const uint8* traceData - Parameters to be traced
**                      uint16 traceDataLength - Length fo trace data
**
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_MSG_TOO_LARGE - The message is too large
**                      DLT_E_NO_BUFFER - Not enough buffer available
**                      DLT_E_UNKNOWN_SESSION_ID: The provided session id is unknown
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SendTraceMessage(Dlt_SessionIDType sessionId, const Dlt_MessageTraceInfoType *traceInfo, uint8 *traceData, uint16 traceDataLength)
{
    Std_ReturnType DltStdRetval = E_OK;
    uint32 timeStamp = 0U;

    // This function is not implemented as per autosar specs
    Dlt_CreateDltTraceHeader(sessionId, timeStamp, traceInfo, traceDataLength);
    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_RegisterContext
**
** Visibility       :   Public
**
** Description      :   The Register context funtion is called by the SWC to
**                      register its context to log messages
**
** Invocation       :
**
** Inputs           :   Dlt_SessionIDType session_id     - session id
**                      Dlt_ApplicationIDType app_id     - application id
**                      Dlt_ContextIDType context_id     - context id
**                      const uint8* app_description     - description string for app id
**                      uint8 len_app_description        - length of the app description string
**                      const uint8* context_description - description string for context id
**                      uint8 len_context_description    - length of the context description string
**
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_CONTEXT_ALREADY_REG - if context is already registered
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_RegisterContext(Dlt_SessionIDType logmsg_session_id, Dlt_ApplicationIDType logmsg_app_id, Dlt_ContextIDType logmsg_context_id, uint8 *logmsg_app_description, uint8 logmsg_len_app_description, uint8 *logmsg_context_description, uint8 logmsg_len_context_description)
{
    Dlt_ReturnType RegisterStatus = DLT_E_ERROR;
    uint8 idx = 0U;
    Dlt_Internal_ApplicationIDType logmsg_app_InternalId = 0U;
    Dlt_Internal_ContextIDType logmsg_context_InternalId = 0U;

    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;

    logmsg_context_InternalId = DLT_UINT32_CONVERT_TUPLE(logmsg_context_id);
    logmsg_app_InternalId = DLT_UINT32_CONVERT_TUPLE(logmsg_app_id);


    if ((logmsg_app_description == NULL) || (logmsg_len_app_description == 1U) || (logmsg_context_description == NULL) || (logmsg_len_context_description == 1U))
    {
        /*do nothing misra_c_2012_rule_2_7_violation:	These parameters are not used in the function*/
    }

    /*Dlt initialisation check */
    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        /*Session id check with configured value */
        if (logmsg_session_id == Dlt_LocalConfigData.sessionID)
        {
            /* if reg_app_id_cnt = 0, its initialised now and no AppId is registered yet*/
            if (Dlt_LocalConfigData.regContextIDCount == 0U)
            {
                MemLib_MemCpy(DltSwcContextInternal[(Dlt_LocalConfigData.regContextIDCount)].DltSwcApplicationId, logmsg_app_id, sizeof(Dlt_ApplicationIDType));
                MemLib_MemCpy(DltSwcContextInternal[(Dlt_LocalConfigData.regContextIDCount)].DltSwcContextId, logmsg_context_id, sizeof(Dlt_ContextIDType));
                Dlt_LocalConfigData.regContextIDCount++;
                RegisterStatus = DLT_E_OK;
            }
            else
            {
                /*for loop checking for appid array */
                for (idx = 0; idx < Dlt_LocalConfigData.regContextIDCount; idx++)
                {
                    swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
                    swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

                    /*checking for appid in the array */
                    if (logmsg_app_InternalId == swcApplicationId && logmsg_context_InternalId == swcContextId)
                    {
                        RegisterStatus = DLT_E_CONTEXT_ALREADY_REG;
                        break;
                    }
                }
                /*check if appid NOT already registered */
                if (RegisterStatus != DLT_E_CONTEXT_ALREADY_REG)
                {
                    if (Dlt_LocalConfigData.regContextIDCount < DLT_MAX_NUM_SWCCONTEXT)
                    {
                        /*register the new app id */
                        MemLib_MemCpy(DltSwcContextInternal[(Dlt_LocalConfigData.regContextIDCount)].DltSwcApplicationId, logmsg_app_id, sizeof(Dlt_ApplicationIDType));
                        MemLib_MemCpy(DltSwcContextInternal[(Dlt_LocalConfigData.regContextIDCount)].DltSwcContextId, logmsg_context_id, sizeof(Dlt_ContextIDType));

                        #if (DLT_SWC_SUPPORTLOGLEVELCHANGENOTIFICATION == STD_ON) // [SWS_Dlt_00768]
                        // Dlt_GetLogInfo(UNREGISTER_CONTEXT, logmsg_session_id, logmsg_app_InternalId, logmsg_context_InternalId);
                        #endif

                        /*Increament the AppId Count */
                        Dlt_LocalConfigData.regContextIDCount++;
                        RegisterStatus = DLT_E_OK;
                    }
                }
            }
        }
        else
        {
            RegisterStatus = DLT_E_UNKNOWN_SESSION_ID;
        }
    }
    else
    {
        RegisterStatus = DLT_E_ERROR;
    }

    return ((Std_ReturnType)RegisterStatus);
}

/*============================================================================
**
** Function Name    :   Dlt_UnregisterContext
**
** Visibility       :   Public
**
** Description      :   The service has to be called when a software module is
**                      going to be stopped.
**
** Invocation       :
**
** Inputs           :   Dlt_SessionIDType session_id     - session id
**                      Dlt_ApplicationIDType app_id     - application id
**                      Dlt_ContextIDType context_id     - context id
**
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_CONTEXT_NOT_YET_REG - context has not registered before
**                      DLT_E_UNKNOWN_SESSION_ID - session id is unknown
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_UnregisterContext(Dlt_SessionIDType message_session_id, Dlt_ApplicationIDType message_app_id, Dlt_ContextIDType message_context_id)
{
    Dlt_ReturnType UnRegisterStatus = DLT_E_ERROR;
    uint8 idx = 0;
    uint8 jdx = 0;

    Dlt_Internal_ContextIDType logmsg_context_InternalId = 0U;
    Dlt_Internal_ApplicationIDType logmsg_app_InternalId = 0U;

    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;

    logmsg_context_InternalId = DLT_UINT32_CONVERT_TUPLE(message_context_id);
    logmsg_app_InternalId = DLT_UINT32_CONVERT_TUPLE(message_app_id);

    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        /* Session id check */
        if (message_session_id == Dlt_LocalConfigData.sessionID)
        {
            UnRegisterStatus = DLT_E_CONTEXT_NOT_YET_REG;
            /* loop for checking app id in the registered array  */
            for (idx = 0; idx < Dlt_LocalConfigData.regContextIDCount; idx++)
            {
                swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
                swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

                /* app id check in the array */
                if ((Dlt_LocalConfigData.regContextIDCount <= DLT_MAX_NUM_SWCCONTEXT) && (logmsg_app_InternalId == swcApplicationId) && (logmsg_context_InternalId == swcContextId))
                {
                    /* Shifting the data in the array */
                    for (jdx = idx; jdx <= Dlt_LocalConfigData.regContextIDCount; jdx++)
                    {
                        if ((DLT_MAX_NUM_SWCCONTEXT - 1U) > jdx)
                        {
                            MemLib_MemCpy(DltSwcContextInternal[jdx].DltSwcApplicationId, DltSwcContextInternal[jdx + 1U].DltSwcApplicationId, sizeof(Dlt_ApplicationIDType));
                            MemLib_MemCpy(DltSwcContextInternal[jdx].DltSwcContextId, DltSwcContextInternal[jdx + 1U].DltSwcContextId, sizeof(Dlt_ContextIDType));
                        }
                        else
                        {
                            break;
                        }
                    }

                    #if (DLT_SWC_SUPPORTLOGLEVELCHANGENOTIFICATION == STD_ON) // [SWS_Dlt_00768]
                    // Dlt_GetLogInfo(UNREGISTER_CONTEXT, logmsg_session_id, logmsg_app_InternalId, logmsg_context_InternalId);
                    #endif

                    /*Incrementing AppId count*/
                    /*misra_c_2012_rule_14_2_violation:	The expression "Dlt_LocalConfigData.regContextIDCount" used in the for loop clauses is modified in the loop body - To be deviated*/
                    Dlt_LocalConfigData.regContextIDCount--;
                    UnRegisterStatus = DLT_E_OK;
                    break;
                }
            }
        }
        else
        {
            UnRegisterStatus = DLT_E_UNKNOWN_SESSION_ID;
        }
    }
    else
    {
        UnRegisterStatus = DLT_E_ERROR;
    }

    return ((Std_ReturnType)UnRegisterStatus);
}

/*============================================================================
**
** Function Name    :   Dlt_DemTriggerOnEventData
**
** Visibility       :   Public
**
** Description      :   Triggers on changes of the event related data in the
**                      event memory.
**
** Invocation       :
**
** Inputs           :   Dem_EventIdType EventId - event id
**
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_DemTriggerOnEventData(Dem_EventIdType EventId)
{
    return DLT_E_OK;
}

/*============================================================================
**
** Function Name    :   Dlt_DetForwardErrorTrace
**
** Visibility       :   Public
**
** Description      :   Service to forward error reports from Det to Dlt.
**
** Invocation       :
**
** Inputs           :   uint16 moduleId - module id
**                      uint8 instanceId - instance id
**                      uint8 apiId - api id
**                      uint8 errorId - error id
**
** Outputs          :  none
**
** Critical Section :
**
**==========================================================================*/
void Dlt_DetForwardErrorTrace(uint16 moduleId, uint8 instanceId, uint8 apiId, uint8 errorId)
{
}

/*============================================================================
**
** Function Name    :   Dlt_SetLogLevel
**
** Visibility       :   Public
**
** Description      :   This service is used to change the LogLevel for the
**                      given tuple of ApplicationID/ContextID.
**
** Invocation       :
**
** Inputs           :   Dlt_ApplicationIDType appId - app id
**                      Dlt_ContextIDType contextId - context id
**                      Dlt_MessageLogLevelType newLogLevel - set new level
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetLogLevel(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, Dlt_MessageLogLevelType newLogLevel)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(appId);
    uint32 contxtId = DLT_UINT32_CONVERT_TUPLE(contextId);
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;
    
    for (idx = 0U; idx < DLT_MAX_NUM_SWCCONTEXT; idx++)
    {
        swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
        swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

        if ((swcApplicationId == applicationId) && (swcContextId == contxtId))
        {
            DltSwcContextInternal[idx].DltLogLevelThreshold = newLogLevel;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_SetTraceStatus
**
** Visibility       :   Public
**
** Description      :   The service Dlt_SetTraceStatus sets the trace status
**                      for a specific tuple of ApplicationID and ContextID.
**
** Invocation       :
**
** Inputs           :   Dlt_ApplicationIDType appId - app id
**                      Dlt_ContextIDType contextId - context id
**                      boolean newTraceStatus - New Trace Status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetTraceStatus(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, boolean newTraceStatus)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(appId);
    uint32 contxtId = DLT_UINT32_CONVERT_TUPLE(contextId);
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;

    for (idx = 0U; idx < DLT_MAX_NUM_SWCCONTEXT; idx++)
    {
        swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
        swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

        if ((swcApplicationId == applicationId) && (swcContextId == contxtId))
        {
            DltSwcContextInternal[idx].DltTraceStatus = newTraceStatus;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetLogInfo
**
** Visibility       :   Public
**
** Description      :   Called to request information about registered
**                      ApplicationIds, their ContextIds and the corresponding log level.
**
** Invocation       :
**
** Inputs           :   uint8 options - filter the response
**                      Dlt_ApplicationIDType appId - app id
**                      Dlt_ContextIDType contextId - context id
**
** Outputs          :  uint8* status - status
**                     Dlt_LogInfoType* logInfo - Information about application ids
**                     DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetLogInfo(uint8 options, Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, uint8 *status, Dlt_LogInfoType *logInfo)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetDefaultLogLevel
**
** Visibility       :   Public
**
** Description      :   Returns the Default Log Level currently used by the Dlt module.
**                      The returned Log Level might differ from the one which is stored non volatile.
**
** Invocation       :
**
** Inputs           :   none
**
** Outputs          :  Dlt_MessageLogLevelType* defaultLogLevel - Default log level
**                     DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetDefaultLogLevel(Dlt_MessageLogLevelType *defaultLogLevel)
{
    Std_ReturnType DltStdRetval = E_OK;

    *defaultLogLevel = DltLogLevelSetting.DltDefaultLogLevel;

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_StoreConfiguration
**
** Visibility       :   Public
**
** Description      :   Copies the current Dlt configuration to NvRAM by
**                      calling NvM_WriteBlock().
**
** Invocation       :
**
** Inputs           :   none
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**                     DLT_E_NOT_SUPPORTED: Service is not supported
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_StoreConfiguration(void)
{
    Std_ReturnType DltStdRetval = E_OK;
    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_ResetToFactoryDefault
**
** Visibility       :   Public
**
** Description      :   The service Dlt_ResetToFactoryDefault sets the LogLevel
**                      and TraceStatus back to the persistently stored default
**                      values. If the feature NvMRAM support is enabled, all
**                      stored Dlt values in the NvM are deleted.
**
** Invocation       :
**
** Inputs           :   none
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_ResetToFactoryDefault(void)
{
    Std_ReturnType DltStdRetval = E_OK;

    MemLib_MemSet(DltSwcContextInternal, 0x0U, sizeof(DltSwcContextInternal));
    MemLib_MemSet(DltLogChannelAssignmentInternal, 0x0U, sizeof(DltSwcContextInternal));

    MemLib_MemCpy(DltSwcContextInternal, DltSwcContext, sizeof(DltSwcContext));
    MemLib_MemCpy(DltLogChannelAssignmentInternal, DltLogChannelAssignment, sizeof(DltLogChannelAssignment));

    Dlt_LocalConfigData.regContextIDCount = DLT_NUM_SWCCONTEXT;

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_SetMessageFiltering
**
** Visibility       :   Public
**
** Description      :   Switches on/off the message filtering functionality of
**                      the Dlt module.
**
** Invocation       :
**
** Inputs           :   boolean MessageFiltering - sets the message filtering
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetMessageFiltering(boolean MessageFilteringStatus)
{
    Std_ReturnType ReturnValue = DLT_E_OK;

    /* Status check */
    if (MessageFilteringStatus != FALSE)
    {
        /* Enabling the Filtering Functionality */
        Dlt_LocalConfigData.filterEnabled = MSG_FILTER_ENABLE;
    }
    else
    {
        /* Disabling the Filtering Functionality */
        Dlt_LocalConfigData.filterEnabled = MSG_FILTER_DISABLE;
    }

    return ReturnValue;
}

/*============================================================================
**
** Function Name    :   Dlt_SetDefaultLogLevel
**
** Visibility       :   Public
**
** Description      :   Called to modify the pass through range for Log Messages
**                      for all not explicit set ContextIds.
**
** Invocation       :
**
** Inputs           :   Dlt_MessageLogLevelType newLogLevel - new filter value
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel)
{
    Std_ReturnType DltStdRetval = E_OK;
    DltLogLevelSetting.DltDefaultLogLevel = newLogLevel;
    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_SetDefaultTraceStatus
**
** Visibility       :   Public
**
** Description      :   Called to enable or disable trace messages for all not
**                      explicitly set ContextIds.
**
** Invocation       :
**
** Inputs           :   boolean newTraceStatus - set trace message
**                      Dlt_LogChannelNameType logChannelName - Name of logchannel
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetDefaultTraceStatus(boolean newTraceStatus, Dlt_LogChannelNameType logChannelName)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 logChannel = DLT_UINT32_CONVERT_TUPLE(logChannelName);
    uint32 swclogChannel = 0U;

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);

        if (swclogChannel == logChannel)
        {
            DltLogChannelRef[idx].DltLogTraceStatusFlag = newTraceStatus;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetDefaultTraceStatus
**
** Visibility       :   Public
**
** Description      :   Called to enable or disable trace messages for all not
**                      explicitly set ContextIds.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**
** Outputs          :  boolean* traceStatus - current trace status
**                     DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetDefaultTraceStatus(Dlt_LogChannelNameType logChannelName, boolean *traceStatus)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 logChannel = DLT_UINT32_CONVERT_TUPLE(logChannelName);
    uint32 swclogChannel = 0U;

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);

        if (swclogChannel == logChannel)
        {
            *traceStatus = DltLogChannelRef[idx].DltLogTraceStatusFlag;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetLogChannelNames
**
** Visibility       :   Public
**
** Description      :   Returns all configured LogChannel names.
**
** Invocation       :
**
** Inputs           :   none
**
** Outputs          :  uint8* numberOfLogChannels - number of channels
**                     Dlt_LogChannelNameType* logChannelNames - Name of logChannelBufferInternal
**                     DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetLogChannelNames(uint8 *numberOfLogChannels, Dlt_LogChannelNameType logChannelNames)
{
    Std_ReturnType DltStdRetval = E_OK;
    uint8 idx = 0U;
    uint32 logChannelId[DLT_NUM_LOGCHANNELREF] = {0U};

    *numberOfLogChannels = DLT_NUM_LOGCHANNELREF;

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        logChannelId[idx] = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);
    }

    MemLib_MemCpy(logChannelNames, logChannelId, sizeof(logChannelId));

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetTraceStatus
**
** Visibility       :   Public
**
** Description      :   Returns the current Trace Status for a given tuple
**                      ApplicationId/ContextId.
**
** Invocation       :
**
** Inputs           :   Dlt_ApplicationIDType appId - appid
**                      Dlt_ContextIDType contextId - contextid
**
** Outputs          :  boolean* traceStatus - current trace status
**                     DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetTraceStatus(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, boolean *traceStatus)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(appId);
    uint32 contxtId = DLT_UINT32_CONVERT_TUPLE(contextId);
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;

    for (idx = 0U; idx < DLT_MAX_NUM_SWCCONTEXT; idx++)
    {
        swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
        swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

        if ((swcApplicationId == applicationId) && (swcContextId == contxtId))
        {
            *traceStatus = DltSwcContextInternal[idx].DltTraceStatus;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_SetLogChannelAssignment
**
** Visibility       :   Public
**
** Description      :   Adds/removes the addressed tuple ApplicationId/ContextId
**                      to/from the addressed LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_ApplicationIDType appId - appid
**                      Dlt_ContextIDType contextId - contextid
**                      Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_AssignmentOperation addRemoveOp - Add or remove log channel
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetLogChannelAssignment(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, Dlt_LogChannelNameType logChannelName, Dlt_AssignmentOperation addRemoveOp)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint8 jdx = 0U;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(appId);
    uint32 contxtId = DLT_UINT32_CONVERT_TUPLE(contextId);
    uint32 logChannel = DLT_UINT32_CONVERT_TUPLE(logChannelName);
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;
    uint32 swclogChannel = 0U;
    uint8 matchFound = 0U;
    DltSwcContext_Type *SwcContext = 0U;
    DltLogChannel_Type *LogChannelRef = 0U;

    for (idx = 0U; idx < DLT_MAX_NUM_SWCCONTEXT; idx++)
    {
        swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
        swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

        if ((swcApplicationId == applicationId) && (swcContextId == contxtId))
        {
            SwcContext = &DltSwcContextInternal[idx];
            matchFound |= 1U;
            break;
        }
    }

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);

        if(logChannel == swclogChannel)
        {
            LogChannelRef = &DltLogChannelRef[idx];
            matchFound |= 2U;
            break;
        }
    }

    if (addRemoveOp == DLT_ASSIGN_ADD && matchFound == 3U)
    {
        for (idx = 0U; idx < DLT_MAX_NUM_LOGCHANNELASSIGNMENT; idx++)
        {
            if (&DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef == NULL_PTR)
            {
                DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef = SwcContext;
                DltLogChannelAssignmentInternal[idx].DltLogChannelRef = LogChannelRef;
                DltStdRetval = E_OK;
                break;
            }
            else if ((SwcContext == DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef) &&
                     (LogChannelRef == DltLogChannelAssignmentInternal[idx].DltLogChannelRef))
            {
                swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelAssignmentInternal[idx].DltLogChannelRef->DltLogChannelId);
                
                if (logChannel == swclogChannel)
                {
                    DltStdRetval = E_OK;
                    break;
                }
            }
            else
            {
                // Do nothing
            }
        }
    }
    else if (addRemoveOp == DLT_ASSIGN_REMOVE && matchFound == 3U)
    {
        for (idx = 0U; idx < DLT_MAX_NUM_LOGCHANNELASSIGNMENT; idx++)
        {
            if (&DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef == NULL_PTR)
            {
                DltStdRetval = E_OK;
                break;
            }
            else if ((SwcContext == DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef) &&
                     (LogChannelRef == DltLogChannelAssignmentInternal[idx].DltLogChannelRef) &&
                     (logChannel == DLT_UINT32_CONVERT_TUPLE(DltLogChannelAssignmentInternal[idx].DltLogChannelRef->DltLogChannelId)))
            {
                for (jdx = idx; jdx < (DLT_MAX_NUM_LOGCHANNELASSIGNMENT - 1u); jdx++)
                {
                    DltLogChannelAssignmentInternal[jdx] = DltLogChannelAssignmentInternal[jdx + 1U];
                }
                DltStdRetval = E_OK;
                break;
            }
            else
            {
                // Do nothing
            }
        }
    }
    else
    {
        // Do Nothing
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_SetLogChannelThreshold
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetLogChannelThreshold(Dlt_LogChannelNameType logChannelName, Dlt_MessageLogLevelType newThreshold, boolean newTraceStatus)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 logChannel = DLT_UINT32_CONVERT_TUPLE(logChannelName);
    uint32 swclogChannel = 0U;

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);

        if (swclogChannel == logChannel)
        {
            DltLogChannelRef[idx].DltLogChannelThreshold = newThreshold;
            DltLogChannelRef[idx].DltLogTraceStatusFlag = newTraceStatus;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_GetLogChannelThreshold
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_GetLogChannelThreshold(Dlt_LogChannelNameType logChannelName, Dlt_MessageLogLevelType *logChannelThreshold, boolean *traceStatus)
{
    Std_ReturnType DltStdRetval = E_NOT_OK;
    uint8 idx = 0U;
    uint32 logChannel = DLT_UINT32_CONVERT_TUPLE(logChannelName);
    uint32 swclogChannel = 0U;

    for (idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        swclogChannel = DLT_UINT32_CONVERT_TUPLE(DltLogChannelRef[idx].DltLogChannelId);

        if (swclogChannel == logChannel)
        {
            *logChannelThreshold = DltLogChannelRef[idx].DltLogChannelThreshold;
            *traceStatus = DltLogChannelRef[idx].DltLogTraceStatusFlag;
            DltStdRetval = E_OK;
            break;
        }
    }

    return DltStdRetval;
}

/*============================================================================
**
** Function Name    :   Dlt_InjectCall_<SESSION>
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_InjectCall_SESSION(Dlt_ApplicationIDType appId, Dlt_ContextIDType contextId, uint32 serviceId, uint32 dataLength, uint8 *data)
{
}

/*============================================================================
**
** Function Name    :   Dlt_RxIndication
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr)
{
    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        // Dlt_ReturnType RetVal = DLT_E_NOT_OK;
        if (RxPduId != DLT_RX_PDU_ID)
        {
        }
        else
        {
            DltInternalBuffPos = 0U;
            TpSduLengthDltInternal = 0U;
        }
    }
}

/*============================================================================
**
** Function Name    :   Dlt_TriggerTransmit
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr)
{
    return DLT_E_OK;
}

/*============================================================================
**
** Function Name    :   Dlt_TxConfirmation
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        if (TxPduId != DLT_TX_PDU_ID)
        {
            // Pdu Id Invalid
        }
        else
        {
        }
    }
}

/*============================================================================
**
** Function Name    :   Dlt_TpTxConfirmation
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TpTxConfirmation(PduIdType PduId, Std_ReturnType result)
{
    for (uint8 idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        LogChannelBufferType *channelTX = &logChannelBufferTX[idx];

        if (PduId == channelTX->TxPduId)
        {
            if (result == DLT_E_OK)
            {
                // clear TX buffer
                channelTX->count = 0U;
                channelTX->TxStatus = eDlt_Transmit_Idle;
                channelTX->TransmitCounter = 0U;
            }
            else
            {
                // Do nothing
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   Dlt_CopyTxData
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_CopyTxData(PduIdType id, const PduInfoType *info, const RetryInfoType *retry, PduLengthType *availableDataPtr)
{
    PduLengthType memIter = 0U;
    BufReq_ReturnType fl_RetVal = BUFREQ_E_NOT_OK;

    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        fl_RetVal = BUFREQ_E_BUSY;

        if (info->SduLength == 0U)
        {
            if (DLT_RX_BUFF_SIZE < DltInternalBuffPos)
            {
                /* do nothing */
            }
            else
            {
                *availableDataPtr = (DLT_RX_BUFF_SIZE - DltInternalBuffPos); /* CERT C 17225671 */
            }
        }

        if (DltInternalBuffPos < DLT_RX_BUFF_SIZE)
        {
            if (info->SduLength <= (DLT_RX_BUFF_SIZE - DltInternalBuffPos))
            {
                for (memIter = 0U; memIter < info->SduLength; memIter++)
                {
                    info->SduDataPtr[memIter] = Dlt_TxBuffer[DltInternalBuffPos + memIter];
                }
                DltInternalBuffPos += memIter;
                *availableDataPtr = DLT_RX_BUFF_SIZE - DltInternalBuffPos;
                fl_RetVal = BUFREQ_OK;
            }
        }
        else
        {
        }
    }
    return fl_RetVal;
}

/*============================================================================
**
** Function Name    :   Dlt_StartOfReception
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_StartOfReception(PduIdType DltRxPduid, const PduInfoType *info, PduLengthType TpSduLength, PduLengthType *bufferSizePtr)
{
    BufReq_ReturnType fl_RetVal;
    fl_RetVal = BUFREQ_E_NOT_OK;
    uint8 PduReqIdMatch;

    PduReqIdMatch = DLT_E_NOT_OK;

    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        if (DLT_RX_PDU_ID == DltRxPduid)
        {
            PduReqIdMatch = DLT_E_OK;
            // break;
        }

        if (PduReqIdMatch != DLT_E_NOT_OK)
        {
            if (TpSduLength <= DLT_RX_BUFF_SIZE)
            {
                DltInternalBuffPos = 0x0U;                            // BufferPosition
                TpSduLengthDltInternal = (Dcm_MsgLenType)TpSduLength; // TpSduLength
                *bufferSizePtr = (PduLengthType)DLT_RX_BUFF_SIZE;
                fl_RetVal = BUFREQ_OK;
            }
            else
            {
                fl_RetVal = BUFREQ_E_OVFL;
            }
        }
        else
        {
            /*Do nothing*/
        }
    }

    return fl_RetVal;
}

/*============================================================================
**
** Function Name    :   Dlt_TpRxIndication
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TpRxIndication(PduIdType id, Std_ReturnType result)
{
    //To suppress compiler warning - Remove when Dlt_RxBuffer is used.
    UNUSED(Dlt_RxBuffer); 
}

/*============================================================================
**
** Function Name    :   Dlt_CopyRxData
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_CopyRxData(PduIdType DltRxPduid, const PduInfoType *info, PduLengthType *bufferSizePtr)
{
    BufReq_ReturnType fl_RetVal = BUFREQ_E_NOT_OK;
    PduLengthType MemIter = 0U;

    if (Dlt_LocalConfigData.initStatus == DLT_INIT)
    {
        if (info->SduLength != 0U)
        {
            if (DltInternalBuffPos < TpSduLengthDltInternal)
            {
                for (MemIter = 0U; MemIter < info->SduLength; MemIter++)
                {
                    Dlt_RxBuffer[DltInternalBuffPos + MemIter] = info->SduDataPtr[MemIter];
                }
                DltInternalBuffPos += MemIter;
                *bufferSizePtr = (PduLengthType)(TpSduLengthDltInternal - DltInternalBuffPos);
                fl_RetVal = BUFREQ_OK;
            }
        }
        else
        { /* Just inform available buffer size*/
            if ((PduLengthType)TpSduLengthDltInternal < DltInternalBuffPos)
            {
                fl_RetVal = BUFREQ_E_NOT_OK;
            }
            else
            {
                *bufferSizePtr = (PduLengthType)TpSduLengthDltInternal - DltInternalBuffPos; /*CERT C 17223802*/
                fl_RetVal = BUFREQ_OK;
            }
        }
    }
    else
    {
        /*Do nothing*/
    }

    return fl_RetVal;
}

/*============================================================================
**
** Function Name    :  Dlt_GenerateTimestamp
** Visibility       :  Public
** Description      :
** Invocation       :
** Inputs           :
** Outputs          :
** Critical Section :
**==========================================================================*/
static uint32 Dlt_GenerateTimestamp(void)
{
    uint32 timeStamp = 0x0U;

    #if (DLT_GENERAL_GPTCHANNELREF_CONFIG == STD_ON && DLT_GENERAL_STBMTIMEBASEREF_CONFIG == STD_OFF)
    // GPT based timestamp
    timeStamp = DLT_GPT_GETTIMEELAPSED(DLT_GENERAL_GPTCHANNELREF);
    #elif (DLT_GENERAL_GPTCHANNELREF_CONFIG == STD_OFF && DLT_GENERAL_STBMTIMEBASEREF_CONFIG == STD_ON)
    // STBM based timestamp
    DLT_STBM_GETCURRENTTIME(DLT_GENERAL_STBMTIMEBASEREF, &timeStamp);
    #else
    // Get program specific timestamp from DltExt
    timeStamp = DLTEXT_GENERATETIMESTAMP();
    #endif

    return timeStamp;
}

/*============================================================================
**
** Function Name    :   Dlt_SendLogMessage
** Visibility       :   Public
** Description      :   The Send Log message is called to send the log message
**                      to the external client.
** Invocation       :
** Inputs           :   Dlt_SessionIDType session_id    - session id
**                      Dlt_MessageLogInfoType log_info - contains the log level of the log message
**                      const uint8* log_data           - the log message
**                      uint8 log_data_length           - length of the log message
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_MSG_TOO_LARGE - if the message is too large
**                      DLT_E_IF_NOT_AVAILABLE - if the interface is not available
**                      DLT_E_UNKNOWN_SESSION_ID - If the provided session ID is unknown
**                      DLT_E_NOT_IN_VERBOSE_MODE - If the message cannot be sent in verbose mode
** Critical Section :
**==========================================================================*/
Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, uint8 *logData, uint16 logDataLength)
{  
    Dlt_ReturnType result = DLT_E_OK; 
    Dlt_MessageLogLevelType logLevel = logInfo->logLevel;

    // Validate input parameters
    if (logInfo == NULL || logData == NULL || logDataLength == 0U)
    {
        DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, DLT_E_ERROR);
        result = DLT_E_OK;
    }
    else
    {
        // Step 1: Generate timeStamp
        #if(DLT_HEADERUSETIMESTAMP == STD_ON)
        uint32 timeStamp = 0U;
        timeStamp = Dlt_GenerateTimestamp();
        #endif

        // Step 2: Filter message
        result = Dlt_FilterMessage(logInfo);

        if (result != DLT_E_OK)
        {
            DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, result);
            result = DLT_E_OK;
        }
        else
        {
            {
                // Step 3: Select target logChannelBufferInternal
                result = Dlt_SelectTargetLogChannels(logInfo);
                if (result != DLT_E_OK)
                {
                    DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, result);
                    result = DLT_E_OK;
                }
                else
                {
                    // Step 4: Check message length
                    result = Dlt_CheckMessageLength(logDataLength);
                    if (result == DLT_E_MSG_TOO_LARGE)
                    {
                        DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, DLT_E_MSG_TOO_LARGE);
                    }
                    else
                    {
                        // Step 5: Apply LogChannel threshold
                        result = Dlt_ApplyLogLevelThreshold(logLevel);
                        if (result != DLT_E_OK)
                        {
                            DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, result);
                            result = DLT_E_OK;
                        }
                        else
                        {
                            // Step 6: Copy Dlt message to LogChannel specific buffer
                            result = Dlt_CopyMessageToBuffers(sessionId, timeStamp, logInfo, logData, logDataLength);
                            if (result != DLT_E_OK)
                            {
                                DLT_DET_REPORTERROR(DLT_MODULE_ID, DLT_INSTANCE_ID_DET, DLT_API_ID_SENDLOGMESSAGE, result);
                                result = DLT_E_OK;
                            }
                            else
                            {
                                //Do nothing
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

/*============================================================================
** Function Name    :    Dlt_FilterMessage
** Visibility       :    Public
** Description      :    Called from Dlt_SendLogMessage to Filter the Messages
** Invocation       :
** Inputs           :   applicationId - app id
**                      session_id - Session id
**                      FaultCategory - Fault Category 
** Outputs          :   DLT_E_NOT_OK - if error occured
**                      DLT_E_OK - if Success
**                      DLT_E_UNKNOWN_SESSION_ID -  session id is unknown
** Critical Section :
**==========================================================================*/
Dlt_ReturnType Dlt_FilterMessage(const Dlt_MessageLogInfoType *logInfo)
{
    Dlt_ReturnType DltRetval = DLT_E_NOT_OK;
    uint8 idx = 0U;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(logInfo->appId);
    uint32 contextId = DLT_UINT32_CONVERT_TUPLE(logInfo->contextId);
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;
    Dlt_MessageLogLevelType logLevel = logInfo->logLevel;
    boolean matchFound = FALSE;
    boolean logLevelFilter = FALSE;

    if (Dlt_LocalConfigData.filterEnabled == MSG_FILTER_ENABLE)
    {
        for (idx = 0U; idx < DLT_MAX_NUM_SWCCONTEXT; idx++)
        {
            swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcApplicationId);
            swcContextId = DLT_UINT32_CONVERT_TUPLE(DltSwcContextInternal[idx].DltSwcContextId);

            if (swcApplicationId == applicationId)
            {
                if( (swcContextId == contextId) || (swcContextId == 0U))
                {
                    matchFound = TRUE;

                    if (logLevel <= DltSwcContextInternal[idx].DltLogLevelThreshold)
                    {
                        // The message is not further processed
                        logLevelFilter = TRUE;
                    }
                    break;
                }

                
            }
        }
    }
    else
    {
        matchFound = TRUE;
    }

    if ((matchFound == TRUE) && (logLevelFilter == FALSE))
    {
        DltRetval = DLT_E_OK;

        if ((logInfo->options & DLT_ISMSGVERBOSEMODE_BIT) != DLT_USEVERBOSEMODE)
        {
            DltRetval = DLT_E_NOT_IN_VERBOSE_MODE;
        }
    }

    return DltRetval;
}

/*============================================================================
** Function Name    :   Dlt_SelectTargetLogChannels
** Visibility       :   Static
** Description      :   Called from Dlt_SendLogMessage to select the target log channels
** Invocation       :
** Inputs           :   logInfo
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
static Dlt_ReturnType Dlt_SelectTargetLogChannels(const Dlt_MessageLogInfoType *logInfo)
{
    uint8 idx = 0U;
    boolean matchFound = FALSE;
    uint32 applicationId = DLT_UINT32_CONVERT_TUPLE(logInfo->appId);
    uint32 contextId = DLT_UINT32_CONVERT_TUPLE(logInfo->contextId);
    DltSwcContext_Type *DltLogChannelAssignmentPtr = NULL_PTR;
    DltLogChannel_Type *DltLogChannelPtr[DLT_NUM_LOGCHANNELREF] = {NULL_PTR};
    uint32 swcApplicationId = 0U;
    uint32 swcContextId = 0U;
    uint8 channelCount = 0U;

    for (idx = 0U; idx < DLT_MAX_NUM_LOGCHANNELASSIGNMENT; idx++)
    {
        if (DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef != NULL_PTR)
        {
            swcApplicationId = DLT_UINT32_CONVERT_TUPLE(DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef->DltSwcApplicationId);
            swcContextId = DLT_UINT32_CONVERT_TUPLE(DltLogChannelAssignmentInternal[idx].DltLogChannelAssignmentSwcContextRef->DltSwcContextId);

            if (swcApplicationId == applicationId)
            {
                if ((swcContextId == contextId) || (swcContextId == 0U))
                {
                    DltLogChannelPtr[channelCount++] = DltLogChannelAssignmentInternal[idx].DltLogChannelRef;
                    matchFound = TRUE;
                }
            }
        }
    }

    if (matchFound == FALSE)
    {
        DltLogChannelPtr[channelCount++] = &DltDefaultLogChannelRef;
    }

    DltLogMsg.applicationId = applicationId;
    DltLogMsg.contextId = contextId;
    DltLogMsg.LogChannelAssignmentPtr = DltLogChannelAssignmentPtr;

    for(idx = 0U; idx < channelCount; idx++)
    {
        DltLogMsg.LogChannelPtr[idx] = DltLogChannelPtr[idx];
    }
    
    DltLogMsg.channelCount = channelCount;

    return DLT_E_OK;
}

/*============================================================================
** Function Name    :   Dlt_CheckMessageLength
** Visibility       :   Static
** Description      :   Called from Dlt_SendLogMessage to check message length
** Invocation       :
** Inputs           :   length
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
static Dlt_ReturnType Dlt_CheckMessageLength(uint16 length)
{
    Dlt_ReturnType ret = DLT_E_OK;
    uint8 adjustChannelCount = 0U;
    DltLogMsg.MessageLength = length;
    boolean atleastOneChannelPass = FALSE;

    for (uint8 idy = 0U; idy < DltLogMsg.channelCount; idy++)
    {
        for (uint8 idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
        {
            if (DltLogMsg.LogChannelPtr[idy] == &DltLogChannelRef[idx])
            {
                if (length > DltLogMsg.LogChannelPtr[idy]->DltLogChannelMaxMessageLength)
                {
                    ret = DLT_E_MSG_TOO_LARGE;
                }
                else
                {
                    DltLogMsg.LogChannelPtr[adjustChannelCount++] = DltLogMsg.LogChannelPtr[idy];
                    atleastOneChannelPass = TRUE;
                }
            }
            else
            {
             
            }
        }
    }  

    if (atleastOneChannelPass == TRUE)
    {
        ret = DLT_E_OK;
    }
    else
    {
        if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength)
        {
            ret = DLT_E_MSG_TOO_LARGE;
        }
        else
        {
            DltLogMsg.LogChannelPtr[adjustChannelCount++] = &DltDefaultLogChannelRef;
            ret = DLT_E_OK;
        }
    }

    DltLogMsg.channelCount = adjustChannelCount;

    return ret;
}

/*============================================================================
** Function Name    :   Dlt_ApplyLogLevelThreshold
** Visibility       :   Static
** Description      :   Called from Dlt_SendLogMessage to apply log level threshold
** Invocation       :
** Inputs           :   logLevel
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
static Dlt_ReturnType Dlt_ApplyLogLevelThreshold(Dlt_MessageLogLevelType logLevel)
{
    Dlt_ReturnType ret = DLT_E_OK;
    uint8 adjustChannelCount = 0U;
    boolean atleastOneChannelPass = FALSE;

    for (uint8 idx = 0U; idx < DltLogMsg.channelCount; idx++)
    {
        if (logLevel < DltLogMsg.LogChannelPtr[idx]->DltLogChannelThreshold)
        {
            // The message is not further processed
            ret = DLT_E_NOT_OK;
        }
        else
        {
            DltLogMsg.LogChannelPtr[adjustChannelCount++] = DltLogMsg.LogChannelPtr[idx];
            atleastOneChannelPass = TRUE;
        }
    }

    DltLogMsg.channelCount = adjustChannelCount;

    if (atleastOneChannelPass == TRUE)
    {
        ret = DLT_E_OK;
    }

    return ret;
}

/*============================================================================
** Function Name    :   Dlt_CopyMessageToBuffers
** Visibility       :   Static
** Description      :   Called from Dlt_SendLogMessage to copy message buffer
** Invocation       :
** Inputs           :   sessionId, timeStamp, logInfo, logData, logDataLength
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
static Dlt_ReturnType Dlt_CopyMessageToBuffers(uint32 sessionId, uint32 timeStamp, const Dlt_MessageLogInfoType *logInfo, const uint8 *logData, uint16 logDataLength)
{
    Dlt_ReturnType ret = DLT_E_NOT_OK;
    uint16 messagaLengthAct = 0U;
    

    (void)Dlt_MessageCounter();

    // Step 7: Create header
    Dlt_CreateDltLogHeader(sessionId, timeStamp, logInfo, logDataLength);

    messagaLengthAct = DltHeaderActLength + logDataLength;

    MemLib_MemCpy(Dlt_InternalBuffer, Dlt_HeaderBuffer, DltHeaderActLength);
    MemLib_MemCpy(Dlt_InternalBuffer + DltHeaderActLength, logData, logDataLength);

    for (uint8 idx = 0; idx < DltLogMsg.channelCount; idx++)
    {
        LogChannelBufferType *channel = &logChannelBufferInternal[idx];

        #if(DLT_USE_VAUTOSAR_DLTEXT == STD_ON)
        uint32 locLogChannelId = 0U;
        locLogChannelId = DLT_UINT32_CONVERT_TUPLE(DltLogMsg.LogChannelPtr[idx]->DltLogChannelId);

        if (locLogChannelId == DLTEXT_CHANNEL_ID)
        {
            (void)DLTEXT_FILTERMESSAGE_CALLOUT(Dlt_InternalBuffer, Dlt_InternalBuffer + DltHeaderActLength, DltHeaderActLength, logDataLength, logInfo->logLevel);
            ret = DLT_E_OK;
        }
        else
        #endif
        {
            // Check if the message length exceeds the maximum allowed for the channel
            if (messagaLengthAct < DltLogMsg.LogChannelPtr[idx]->DltLogChannelMaxMessageLength)
            {
                // Check if there is enough space in the buffer
                if (DLT_INTERNAL_BUFFER_SIZE - channel->count <= messagaLengthAct)
                {
                    if (channel->overflowFlag == FALSE)
                    {
                        // Set overflow flag and discard the message
                        channel->overflowFlag = TRUE;
                    }
                    ret = DLT_E_NO_BUFFER;
                }
                else
                {
                    for (uint8 idy = 0; idy < messagaLengthAct; idy++)
                    {
                        channel->buffer[channel->head] = Dlt_InternalBuffer[idy];
                        channel->head = (channel->head + 1u) % DLT_INTERNAL_BUFFER_SIZE;
                    }
                    channel->count = channel->count + messagaLengthAct;
                    channel->TxPduId = DltLogMsg.LogChannelPtr[idx]->DltTxPdu->DltITxPduHandleId;
                    channel->MaxNumOfRetries = DltLogMsg.LogChannelPtr[0]->DltLogChannelMaxNumOfRetries;

                    ret = DLT_E_OK;
                }
            }
        }
    }

    return ret;
}

/*============================================================================
** Function Name    :   Dlt_CreateDltLogHeader
** Visibility       :   Static
** Description      :   Called from Dlt_SendLogMessage to create DLT log headerByte
** Invocation       :
** Inputs           :   sessionId, timeStamp, logInfo, logData, logDataLength
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
void Dlt_CreateDltLogHeader(uint32 sessionId, uint32 timeStamp, const Dlt_MessageLogInfoType *logInfo, uint16 logDataLength)
{
    uint16 DltLogTotalLength = 0U;
    uint8 byteIdx = 4U;

    // Set the UEH bit (SWS_Dlt_00678)
    if (DLT_USEEXTHEADERINNONVERBMODE)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_UEH);
    }

    // Set the MSBF bit (SWS_Dlt_00679 & SWS_Dlt_00680)
    if (DLT_ISBIGENDIAN)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_MSBF);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_MSBF); // Clear MSBF bit for Little Endian
    }

    // Set the WEID bit (SWS_Dlt_00681)
    if (DLT_HEADERUSEECUID)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WEID);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WEID); // Clear WEID bit if ECU ID not used
    }

    // Set the WSID bit (SWS_Dlt_00682)
    if (DLT_HEADERUSESESSIONID)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WSID);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WSID); // Clear WSID bit if Session ID not used
    }

    // Set the WTMS bit (SWS_Dlt_00683)
    if (DLT_HEADERUSETIMESTAMP)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WTMS);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WTMS); // Clear WTMS bit if timeStamp not used
    }

    // Set the VERS bits - Bit 5-7 (SWS_Dlt_00684) 
    Dlt_HeaderBuffer[0U] |= ((DLT_PROTOCOL_VERSION << 5u) & DLT_PROTOCOL_VERSION_MASK);

    // Set the MCNT field (SWS_Dlt_00685)
    Dlt_HeaderBuffer[1U] = (uint8)(LogMessageCount & 0xFFU);

    // Set the optional ECU field (SWS_Dlt_00686, SWS_Dlt_00687)
    #if (DLT_HEADERUSEECUID == STD_ON)
    Dlt_HeaderBuffer[byteIdx++] = (uint8)(DLT_ECUID_VALUE & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 24U) & 0xFFU);
    #endif

    // Set the optional SEID field (SWS_Dlt_00688)
    #if (DLT_HEADERUSESESSIONID == STD_ON)
    Dlt_HeaderBuffer[byteIdx++] = (uint8)(sessionId & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 24U) & 0xFFU);
    #endif

    // Set the optional TMSP field (SWS_Dlt_00689)
    #if (DLT_HEADERUSETIMESTAMP == STD_ON)
    // Dlt_HeaderBuffer[byteIdx++] = (uint8)(timeStamp & 0xFFU);
    // Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 8U) & 0xFFU);
    // Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 16U) & 0xFFU);
    // Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 24U) & 0xFFU);

    Dlt_HeaderBuffer[byteIdx++] = (uint16)((timeStamp >> 24U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint16)((timeStamp >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint16)((timeStamp >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint16)(timeStamp & 0xFFU);
    #endif

    if ((DLT_USEEXTHEADERINNONVERBMODE == STD_ON) || (DLT_USEVERBOSEMODE == STD_ON) || ((logInfo->options & DLT_ISMSGVERBOSEMODE_BIT) == DLT_USEVERBOSEMODE))
    {
        // Message info - MSIN byte update
        // Set the VERB bit (SWS_Dlt_00691)
        if (DLT_USEVERBOSEMODE)
        {
            Dlt_HeaderBuffer[byteIdx] |= (1U << DLT_EXTENDED_HEADER_BIT_VERB);
        }

         // Clear the MSTP bits - Bit 1-3: MSTP
        Dlt_HeaderBuffer[byteIdx] |= ((uint8)(logInfo->options & DLT_MSTP_FIELD_CLEAR_MASK));
        Dlt_HeaderBuffer[byteIdx] |= (uint8)((logInfo->logLevel << 4u) & DLT_MTIN_FIELD_MASK);

        byteIdx++;

        // Update Number of Arguments field - NOAR
        if(DLT_USEVERBOSEMODE)
        {
            Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->argCount & 0xFFU);
        }
        else
        {
            Dlt_HeaderBuffer[byteIdx++] = 0U;
        }
        
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->appId[0U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->appId[1U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->appId[2U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->appId[3U] & 0xFFU);

        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->contextId[0U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->contextId[1U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->contextId[2U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(logInfo->contextId[3U] & 0xFFU);

    }

    DltHeaderActLength = byteIdx;
    DltLogTotalLength = DltHeaderActLength + logDataLength;

    // Set the message length (SWS_Dlt_00690)
    Dlt_HeaderBuffer[2U] = (uint8)((DltLogTotalLength >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[3U] = (uint8)(DltLogTotalLength & 0xFFU);
}

/*============================================================================
** Function Name    :   Dlt_CreateDltTraceHeader
** Visibility       :   Static
** Description      :   Called from Dlt_SendTraceMessage to create DLT trace headerByte
** Invocation       :
** Inputs           :   sessionId, timeStamp, logInfo, logData, logDataLength
** Outputs          :   Dlt_ReturnType
** Critical Section :
**==========================================================================*/
void Dlt_CreateDltTraceHeader(uint32 sessionId, uint32 timeStamp, const Dlt_MessageTraceInfoType *traceInfo, uint16 logDataLength)
{
    uint16 DltLogTotalLength = 0U;
    uint8 byteIdx = 4U;

    // Set the UEH bit (SWS_Dlt_00678)
    if (DLT_USEEXTHEADERINNONVERBMODE)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_UEH);
    }

    // Set the MSBF bit (SWS_Dlt_00679 & SWS_Dlt_00680)
    if (DLT_ISBIGENDIAN)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_MSBF);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_MSBF); // Clear MSBF bit for Little Endian
    }

    // Set the WEID bit (SWS_Dlt_00681)
    if (DLT_HEADERUSEECUID)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WEID);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WEID); // Clear WEID bit if ECU ID not used
    }

    // Set the WSID bit (SWS_Dlt_00682)
    if (DLT_HEADERUSESESSIONID)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WSID);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WSID); // Clear WSID bit if Session ID not used
    }

    // Set the WTMS bit (SWS_Dlt_00683)
    if (DLT_HEADERUSETIMESTAMP)
    {
        Dlt_HeaderBuffer[0U] |= (1U << DLT_HEADER_BIT_WTMS);
    }
    else
    {
        Dlt_HeaderBuffer[0U] &= ~(1U << DLT_HEADER_BIT_WTMS); // Clear WTMS bit if timeStamp not used
    }

    // Set the VERS bits - Bit 5-7 (SWS_Dlt_00684) 
    Dlt_HeaderBuffer[0U] |= (DLT_PROTOCOL_VERSION & DLT_PROTOCOL_VERSION_MASK);

    // Set the MCNT field (SWS_Dlt_00685)
    Dlt_HeaderBuffer[1U] = (uint8)(LogMessageCount & 0xFFU);

    // Set the optional ECU field (SWS_Dlt_00686, SWS_Dlt_00687)
    #if (DLT_HEADERUSEECUID == STD_ON)
    Dlt_HeaderBuffer[byteIdx++] = (uint8)(DLT_ECUID_VALUE & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((DLT_ECUID_VALUE >> 24U) & 0xFFU);
    #endif

    // Set the optional SEID field (SWS_Dlt_00688)
    #if (DLT_HEADERUSESESSIONID == STD_ON)
    Dlt_HeaderBuffer[byteIdx++] = (uint8)(sessionId & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((sessionId >> 24U) & 0xFFU);
    #endif

    // Set the optional TMSP field (SWS_Dlt_00689)
    #if (DLT_HEADERUSETIMESTAMP == STD_ON)
    Dlt_HeaderBuffer[byteIdx++] = (uint8)(timeStamp & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 8U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 16U) & 0xFFU);
    Dlt_HeaderBuffer[byteIdx++] = (uint8)((timeStamp >> 24U) & 0xFFU);
    #endif

    if ((DLT_USEEXTHEADERINNONVERBMODE == STD_ON) || (DLT_USEVERBOSEMODE == STD_ON) || ((traceInfo->options & DLT_ISMSGVERBOSEMODE_BIT) == DLT_USEVERBOSEMODE))
    {
        // Message info - MSIN byte update
        // Set the VERB bit (SWS_Dlt_00691)
        if (DLT_USEVERBOSEMODE)
        {
            Dlt_HeaderBuffer[byteIdx] |= (1U << DLT_EXTENDED_HEADER_BIT_VERB);
        }

        // Set the MSTP bits - Bit 1-3: MSTP
        Dlt_HeaderBuffer[byteIdx] |= (uint8)(traceInfo->options | DLT_MSTP_FIELD_SET_MASK);
        Dlt_HeaderBuffer[byteIdx] |= (uint8)((traceInfo->traceInfo << 4u) & DLT_MTIN_FIELD_MASK);

        // Update Number of Arguments field - NOAR
        // Updating NOAR as 0 because there is no arg field in traceInfo structure
        Dlt_HeaderBuffer[byteIdx++] = 0U;

        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->appId[0U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->appId[1U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->appId[2U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->appId[3U] & 0xFFU);

        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->context[0U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->context[1U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->context[2U] & 0xFFU);
        Dlt_HeaderBuffer[byteIdx++] = (uint8)(traceInfo->context[3U] & 0xFFU);
    }

    DltHeaderActLength = byteIdx;

    // Set the message length (SWS_Dlt_00690)
    Dlt_HeaderBuffer[2U] = (uint8)(DltLogTotalLength & 0xFFU);
    Dlt_HeaderBuffer[3U] = (uint8)((DltLogTotalLength >> 8U) & 0xFFU);
}

/*============================================================================
**
** Function Name    :   Dlt_MessageCounter
** Visibility       :   Public
** Description      :
** Invocation       :
** Inputs           :
** Outputs          :
** Critical Section :
**==========================================================================*/
static void Dlt_MessageCounter(void)
{
    if (LogMessageCount == MAX_MSG_COUNT_VALUE)
    {
        LogMessageCount = MAX_MSG_COUNT_RESET;
    }
    else
    {
        (LogMessageCount++); /* Message counter increment*/
    }
}

/*============================================================================
** Function Name    :   Dlt_TxFunction
** Visibility       :   Static
** Description      :   To transfer data to PDUR
** Invocation       :
** Inputs           :   void
** Outputs          :   void
** Critical Section :
**==========================================================================*/
void Dlt_TxFunction(void)
{
    PduIdType TxPduId;
    PduInfoType PduInfoPtr = {0U};

    for (uint8 idx = 0U; idx < DLT_NUM_LOGCHANNELREF; idx++)
    {
        LogChannelBufferType *channel = &logChannelBufferInternal[idx];
        LogChannelBufferType *channelTX = &logChannelBufferTX[idx];

        if ((channel->count != 0U) && (channelTX->TxStatus == eDlt_Transmit_Idle))
        {
            // Copy data to Tx buffer
            MemLib_MemCpy(channelTX, channel, sizeof(LogChannelBufferType));

            channelTX->TxStatus = eDlt_Transmit_InProgress;

            // clear internal buffer
            channel->count = 0U;

            TxPduId = channelTX->TxPduId;
            PduInfoPtr.SduLength = channelTX->count;
            MemLib_MemCpy(PduInfoPtr.SduDataPtr, channelTX->buffer, PduInfoPtr.SduLength);

            channelTX->TransmitCounter++;

            if (channelTX->TransmitCounter > channelTX->MaxNumOfRetries)
            {
                // Msg is discarted, no further transmit attempts
                // clear TX buffer
                channelTX->count = 0U;
                channelTX->TxStatus = eDlt_Transmit_Idle;
            }
            else
            {
                (void)DLT_PDUR_TRANSMIT(TxPduId, PduInfoPtr);
            }
            
        }
    }
}

#endif

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 20-Sep-2023
CDSID              : bmalgeka
Traceability       :
Change Description : Initial Framework version of Dlt
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
