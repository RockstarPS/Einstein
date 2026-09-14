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
#include "dk_srvc_uds_service_tester_present_handler.h"

namespace dk
{
namespace app
{
namespace udsblservices
{

#ifdef UDSCFG_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);
#endif

void CUdsServiceTesterPresentHandler::serviceInitialize(void)
{
    /// -# Configure Tester present service properties.
    mTesterPresentServiceConfig.mIsFunctionalRequestSupported = true;
    mTesterPresentServiceConfig.mResponsePendingSupported = true;
    mTesterPresentServiceConfig.mLengthCheckConditionType = ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mTesterPresentServiceConfig.mServiceRequestLength = 2U;
    mTesterPresentServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mTesterPresentServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mTesterPresentServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
                                                        {testerPresentRequestHandler(clientAddress,pRequestData,requestLength);};
    mTesterPresentServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
                                                        {testerPresentPostresponseHandler(clientAddress);} ;
    mTesterPresentServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
                                                        {testerPresentResetHandler(clientAddress);} ;
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(
        &gUdsBlServicesLogContext,
        mTesterPresentServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    #endif
    /// -# Add Tester present service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
                                                CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mTesterPresentServiceId,
                                                &mTesterPresentServiceConfig
                                               );
}

void CUdsServiceTesterPresentHandler::testerPresentResetHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"testerPresentResetHandler Invoked ",clientAddress);
    #endif
}

void CUdsServiceTesterPresentHandler::testerPresentPostresponseHandler(const uint16_t clientAddress)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"testerPresentPostresponseHandler Invoked ",clientAddress);
    #endif
}

void CUdsServiceTesterPresentHandler::testerPresentRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)
{
    std::vector<uint8_t> subfunction(1U);    // requested sub function
    CUdsServiceManagerIf::EResponseType_t responseType; //  response type.
    CUdsServiceHandlerIf::EResponseCode_t responseCode; //  response code.

    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext," Tester present service request received in");
    #endif

    if (requestLength != mUdsTesterPresentRequestLength)
    {
        /// -# If requested length not supported , update response as NRC InvalidFormat.
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
    }
    else
    {
        /// -# Get Sub function from the requested data.
        subfunction[0] = pRequestData[0];
        if(subfunction[0] == mUdsTesterPresentSubFunction)
        {
            /// -# If the requested sub function supported , then update responseType as Positive.
            responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Positive;
            /// -# Set responseCode as NoError, sub function supported.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        }
        else
        {
            /// @todo Move the suppressed response handling to service Manager.
            if ((subfunction[0] & 0x7FU) == mUdsTesterPresentSubFunction)
            {
                /// -# If the requested sub function has Suppressed response bit set , then update responseType as
                /// EResponse_Suppress.
                responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Suppress;
                /// -# Set responseCode as NoError, sub function supported.
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext,"Suppressed response Bit set ",subfunction[0]);
                #endif
            }
            else
            {
                /// -# If the sub function not supported , update response as NRC SubFunctionNotSupported.
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;
            }
        }
    }

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(
            &gUdsBlServicesLogContext,
            "Request not accepted because of NRC Code ",
            responseCode
            );
        #endif
        mServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);
    }
    else
    {
        ///-# If request not accepted then send positive response.
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Tester present positive response updated for sub function ",subfunction[0]);
        #endif
        mServiceManagerInstance.serviceResponseUpdate(clientAddress, responseType, subfunction);
    }
}

} // udsblservices
} // app
} // dk
