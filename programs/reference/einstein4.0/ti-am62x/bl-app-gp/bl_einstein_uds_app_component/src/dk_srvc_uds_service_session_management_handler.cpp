//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
#include "dk_srvc_uds_service_session_management_handler.h"
// #include "udsmgr_doip_VipIf.h"
#include "udsmgr_doip_security.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
#define UDSCFG_LOG_ENABLED

#ifdef UDSCFG_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);
#endif

void CUdsServiceSessionManagementHandler::serviceInitialize(void)
{
    /// -# Configure session control service properties.
    mSessionManagementServiceConfig.mIsFunctionalRequestSupported = true;
    mSessionManagementServiceConfig.mResponsePendingSupported = true;
    mSessionManagementServiceConfig.mLengthCheckConditionType=ELengthCheckConditionType_t::ELengthCheckCondition_Equal;
    mSessionManagementServiceConfig.mServiceRequestLength = 2U;
    mSessionManagementServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mSessionManagementServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mSessionManagementServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
    {sessionManagementRequestHandler(clientAddress,pRequestData,requestLength);};
    mSessionManagementServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
    {sessionManagementPostresponseHandler(clientAddress);} ;
    mSessionManagementServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
    {sessionManagementResetHandler(clientAddress);} ;
    mEcuResetFlag = 0U;
#ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        mDiagnosticSessionControlServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
    );
#endif
    /// -# Add Session control service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
        mDiagnosticSessionControlServiceId,
        &mSessionManagementServiceConfig
    );
}

void CUdsServiceSessionManagementHandler::sessionManagementRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength)
{
    CUdsServiceHandlerIf::ESessionType_t requestedSession; // requested session
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // Response code
    CUdsServiceManagerIf::EResponseType_t responseType; //Response type
    std::vector<uint8_t> sessionResponseData(mUdsSessionManagementResponseLength); // buffer to update response.
    uint8_t index;  // configuration table index
    uint8_t requestedSessionSubfunction;    // requested sub function
    SUdsSessionConfig_t const *pCurrentSessionConfig;   // reference to requested sub function configuration.

    /// -# Set responseCode as SubFunctionNotSupported, Assuming sub function not supported.
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;
    requestedSession = ESessionType_t::ESessionType_Last;

#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," session control service request received in session ");
#endif
    /// -# Check for valid request length,If the request is invalid the update response as IncorrectMessageLength.
    if ((requestLength > 0U) && (pRequestData!= nullptr))
    {
        /// -# Get session value from requested data.
        requestedSessionSubfunction = pRequestData[0];
        /// -# Iterate over the configuration table to check whether the requested session is supported.
        for(index=0U; index<CUdsServiceHandlerIf::ESessionType_t::ESessionType_Last; index++)
        {
#ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext,"requestedSessionSubfunction:", requestedSessionSubfunction);
#endif
            if (mUdsSessionConfig[index].mSessionSubFunctionValue ==  requestedSessionSubfunction)
            {
                requestedSession = static_cast<CUdsServiceHandlerIf::ESessionType_t>(index);
                /// -# If session supported check for valid transition conditions.
                responseCode = sessionTransitionValid(requestedSession);
                responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Positive;
                break;
            }
            else  if ((requestedSessionSubfunction & 0x7FU) == mUdsSessionConfig[index].mSessionSubFunctionValue)
            {
                requestedSession = static_cast<CUdsServiceHandlerIf::ESessionType_t>(index);
                /// -# If session supported check for valid transition conditions.
                responseCode = sessionTransitionValid(requestedSession);

                responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Suppress;
                break;
            }
        }
    }
    else
    {
#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Incorrect Message Length Or Invalid Format");
#endif
        // If valid request length not supported , send NRC 0x13
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
    }

    if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        /// -# If requested session supported and session transition valid, Update the positive response data.
        /// and set current session to the requested session.
#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Session transition valid . Session changed to   ",requestedSession);
#endif

        mServiceManagerInstance.setCurrentSession(requestedSession);

        pCurrentSessionConfig = &mUdsSessionConfig[requestedSession];
        sessionResponseData[0]=(requestedSessionSubfunction);

        /// -# Update the P2Max and P2StarMax values for current session.
        sessionResponseData[1] = static_cast<uint8_t >(
                                     ((((pCurrentSessionConfig->mTimingConfig).mP2TimeMaxCountInMs)>> 8U) & 0xffU)
                                 );

        sessionResponseData[2] = static_cast<uint8_t >(
                                     (((pCurrentSessionConfig->mTimingConfig).mP2TimeMaxCountInMs) & 0xffU)
                                 );

        sessionResponseData[3] = static_cast<uint8_t >(
                                     (((((pCurrentSessionConfig->mTimingConfig).mP2StarTimeMaxCountInMs)/10U)>>8U)&0xffU)
                                 );

        sessionResponseData[4] = static_cast<uint8_t >(
                                     ((((pCurrentSessionConfig->mTimingConfig).mP2StarTimeMaxCountInMs)/10U) & 0xffU)
                                 );

#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Diagnostic session response update. serviceResponseUpdate");
#endif
        mServiceManagerInstance.serviceResponseUpdate(
            clientAddress,
            responseType,
            sessionResponseData
        );
    }
    else
    {
        /// -# If the requested session is not supported , update Negative response.
#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ",static_cast<uint32_t>(responseCode));
#endif
        mServiceManagerInstance.sendNegativeResponse(clientAddress,
                static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode)
                                                    );
    }
}


CUdsServiceHandlerIf::EResponseCode_t CUdsServiceSessionManagementHandler::sessionTransitionValid
(
    const CUdsServiceHandlerIf::ESessionType_t requestedSession
)
{
    CUdsServiceHandlerIf::EResponseCode_t responseStatus; // response status
    CUdsServiceHandlerIf::ESessionType_t currentSession; // current session
    CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel;    // current security level
    SUdsSessionConfig_t const *pCurrentSessionConfig;   // reference to requested sub function configuration.

    /// -# Get Current session and security level.
    currentSession       = mServiceManagerInstance.getCurrentSession();
    currentSecurityLevel = mServiceManagerInstance.getCurrentSecurityLevel();
#ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        "Session transition requested in current session ",
        currentSession,
        " and current security level ",
        currentSecurityLevel,
        " requestedSession ",
        requestedSession
    );
#endif
    /// -# Get configuration of the requested session.
    pCurrentSessionConfig = &mUdsSessionConfig[requestedSession];
    /// -# If the session transition is not supported in current session , then update response status
    /// as SubFunctionNotSupportedInActive_Session.
    if (((static_cast<uint32_t>(static_cast<uint32_t>(1U) << static_cast<uint32_t>(currentSession))) &  \
            (pCurrentSessionConfig->mSupportedSessionMask)) == 0U)
    {
        responseStatus = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupportedInActive_Session;
    }
    else if (((static_cast<uint32_t>(static_cast<uint32_t>(1U) << static_cast<uint32_t>(currentSecurityLevel))) & \
              (pCurrentSessionConfig->mSupportedSecurityMask)) == 0U)
    {
        /// -# If the requested session transition is not supported in current security level ,then update response
        /// status as SecurityAccessDenied.
        responseStatus = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
    }
    else
    {
        /// @todo Any pre conditions or system mode should be checked here.
        /* Check if Default Session, Clear the Security Access */
        if(requestedSession == CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)/* Default Session */
        {
            /* Clear Security access*/
            // (void)FblSec_ClearSecurityAccess();
            if(currentSession ==  CUdsServiceHandlerIf::ESessionType_t::ESessionType_FotaSession)
            {
                mEcuResetFlag = 0x1U;
                LOGW(&gUdsBlServicesLogContext,"Transistion to default session: Enable ECU Reset flag ");

            }
        }
        /// -# If session transition is valid then update response status as NoError.
        responseStatus = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
    }

    /// -# return response status
    return responseStatus;
}


void CUdsServiceSessionManagementHandler::sessionManagementPostresponseHandler(const uint16_t clientAddress)
{
    UdsServiceSetTimings dkMsgUdsServiceSetTimings; // Dk message for transmitting service timings
    CUdsServiceHandlerIf::ESessionType_t currentSession; // current session.

    /// -# Get current session.
    currentSession = mServiceManagerInstance.getCurrentSession();
#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"sessionManagementPostresponseHandler Invoked currentSession: ", static_cast<uint32_t>(currentSession));
#endif
    //  UdsCurrentSession DkMsgUdsCurrentSession;
    //  DkMsgUdsCurrentSession.currentSession = currentSession;
    //  DK_RTE_Send_UdsCurrentSession(DkMsgUdsCurrentSession);
    if (currentSession < CUdsServiceHandlerIf::ESessionType_t::ESessionType_Last)
    {
        /// -# Update the P2 timing parameters.
        dkMsgUdsServiceSetTimings.p2TimeMs = mUdsSessionConfig[currentSession].mTimingConfig.mP2TimeMaxCountInMs;
        dkMsgUdsServiceSetTimings.p2StarTimeMs =mUdsSessionConfig[currentSession].mTimingConfig.mP2StarTimeMinCountInMs;
        dkMsgUdsServiceSetTimings.p4TimeMs =mUdsSessionConfig[currentSession].mTimingConfig.mP2StarTimeMaxCountInMs;
        if(currentSession == 0x01)/* Progrmmg Sess*/
        {
            dkMsgUdsServiceSetTimings.p4TimeMs = 900000; /* 15 min => Installer requisite */
        }

#ifdef UDSCFG_LOG_ENABLED
        LOGD(
            &gUdsBlServicesLogContext,
            "Update UDS Timing parameters message sent for clientAddress ",
            clientAddress,
            " p2TimeMs ",
            mUdsSessionConfig[currentSession].mTimingConfig.mP2TimeMaxCountInMs,
            " p2StarTimeMs ",
            mUdsSessionConfig[currentSession].mTimingConfig.mP2StarTimeMinCountInMs,
            " p4TimeMs ", dkMsgUdsServiceSetTimings.p4TimeMs
        );
#endif
        /// -# Send message to update the timing parameters for current session.
        DK_RTE_Send_UdsServiceSetTimings(dkMsgUdsServiceSetTimings);
    }

	LOGW(&gUdsBlServicesLogContext,"ECU Reset Invoked ");

}


void CUdsServiceSessionManagementHandler::sessionManagementResetHandler(const uint16_t clientAddress)
{
#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Reset Handler Invoked ",clientAddress);
#endif
}

} // udsblservices
} // app
} // dk
