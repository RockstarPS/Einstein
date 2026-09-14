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
#include"dk_srvc_uds_service_manager.h"
#include "uds_appl_persist_manager.h"
#include "Reflashhandle.hpp"
#include <string>
#include <algorithm>

namespace dk
{
namespace app
{
namespace udsblservices
{

#ifdef UDSCFG_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);
#endif
void CUdsServiceManager::onInit(void)
{
    #ifdef UDSCFG_LOG_ENABLED
    LOGI(&gUdsBlServicesLogContext," CUdsServiceManager onInit Invoked");
    #endif
    /// -# Set mCurrentDiagnosticMode to Boot loader Mode.
    mCurrentDiagnosticMode = EDiagnosticMode_FotaMode;
    mCurrentServiceTableId = EServiceTableId_Uds;
    ///< Load GIP verification status
}

void CUdsServiceManager::periodicTask(void)
{
    static uint8_t fblReasonInitializationFlag = false;
    fblReason local_reasonForStartingFbl;

    ///-#  Handling of service Manager state #serviceManagerStateProcessing.
    serviceManagerStateProcessing();

    if (mCurrentDiagnosticMode == EDiagnosticMode_DiagMode)
    {
        if (mDiagnosticModeTimer > 0U)
        {
            --mDiagnosticModeTimer;
            if(mDiagnosticModeTimer == 0U)
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Diagnostic mode expired ");
                #endif
                updateDiagnosticMode(EDiagnosticMode_FotaMode);
            }
        }
    }

    // If it was requested programming session in app doip, start with doip session
    ObjVipInstaller.get_reasonForStartingFbl(local_reasonForStartingFbl);
    if( fblReason_notInitialized != local_reasonForStartingFbl && false == fblReasonInitializationFlag )
    {
        fblReasonInitializationFlag = true;
        if( fblReason_doipProgSession == local_reasonForStartingFbl )
        {
            setCurrentSession(CUdsServiceHandlerIf::ESessionType_t::ESessionType_FotaSession);
            printf("RSA: Starting with fota session\n");
        }
        else
        {
            printf("RSA: Starting with default session\n");
        }
    }
}

void CUdsServiceManager::serviceResponseUpdate
(
    const uint16_t clientAddress,
    const CUdsServiceManagerIf::EResponseType_t responseType,
    const std::vector<uint8_t> &responseData
)
{
   UdsServiceResponseTransmitRequest DkMsgUdsServiceResponseTransmitRequest;//DK message for Negative response.
    mIsSuppressReqForSession=0;
    mCacheClientAddr=0;
    #ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext, " new response received for  ", clientAddress, " responseData size ", responseData.size(), " response type ", static_cast<uint32_t>(responseType));
    #endif
    if (isRequestInProgress(clientAddress) != false)
    {
        SDiagnosticDataBufferControl_t &pDiagnosticDataBufferControl = mDiagnosticDataBufferControl[clientAddress];
        if (pDiagnosticDataBufferControl.mDiagServiceManagerState == EDiagServiceManagerState_WaitingForResponse)
        {
            /// -# If the diag service manager state is in waiting for response state , Check for response type
            if ((responseType == CUdsServiceManagerIf::EResponseType_t::EResponse_Positive) || \
                (responseType == CUdsServiceManagerIf::EResponseType_t::EResponse_Suppress))
            {
                /// \verbatim
                /// -# If response type is Positive response , then do the following
                ///     Update the first byte of response with positive response bit set in the current service ID.
                ///     Copy the data to the response buffer and increment the response data length by 1.
                /// \endverbatim
                pDiagnosticDataBufferControl.mData.clear();
                pDiagnosticDataBufferControl.mData.push_back((pDiagnosticDataBufferControl.mServiceId | 0x40U));
                if (responseData.size()>0U)
                {
                    pDiagnosticDataBufferControl.mData.insert(pDiagnosticDataBufferControl.mData.begin()+1, responseData.begin(),responseData.end());
                }

                DkMsgUdsServiceResponseTransmitRequest.responseType = static_cast<uint8_t>(responseType);
                DkMsgUdsServiceResponseTransmitRequest.clientAddress = clientAddress;
                DkMsgUdsServiceResponseTransmitRequest.serviceId = pDiagnosticDataBufferControl.mServiceId ;
                DkMsgUdsServiceResponseTransmitRequest.dataLen = static_cast<uint16_t>(pDiagnosticDataBufferControl.mData.size());
                (void)memset(static_cast<uint8_t *>(&DkMsgUdsServiceResponseTransmitRequest.data[0]),0,
                            static_cast<uint32_t>(DkMsgUdsServiceResponseTransmitRequest.dataLen));
                (void)std::copy((pDiagnosticDataBufferControl.mData).begin(),
                          (pDiagnosticDataBufferControl.mData).end(),
                          &(DkMsgUdsServiceResponseTransmitRequest.data[0]));
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Positive response send for the client address",clientAddress,
                    " pDiagnosticDataBufferControl.mServiceId  ",pDiagnosticDataBufferControl.mServiceId );
                #endif
                DK_RTE_Send_UdsServiceResponseTransmitRequest(DkMsgUdsServiceResponseTransmitRequest);
                if (responseType == CUdsServiceManagerIf::EResponseType_t::EResponse_Suppress)
                {
                    ///Entering loop only for Suppress response
                    mIsSuppressReqForSession=1;
                    mCacheClientAddr=clientAddress;
                }
            }
            else
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," negative response send for the client address",clientAddress,
                    " pDiagnosticDataBufferControl.mServiceId  ",pDiagnosticDataBufferControl.mServiceId );
                #endif
                /// -# If the response type is negative response , then update the negative response .
                sendNegativeResponse(clientAddress, static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseData[0]));
            }
        }
        else
        {
            /// if diag service manager state is other than waiting for response state, then don't transmit.
            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext, " request processing Invalid state ", pDiagnosticDataBufferControl.mDiagServiceManagerState);
            #endif
        }
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," No request exist for client address", clientAddress);
        #endif
    }
}

void CUdsServiceManager::addServiceHandler
(
    const CUdsServiceManagerIf::EServiceTableId_t serviceTableId,
    const uint8_t serviceId,
    const CUdsServiceHandlerIf::SServiceConfig_t * const pServiceConfig
)
{
    CUdsServiceHandlerIf::SServiceConfig_t * pTempServiceConfig; //reference to service configuration in service map.

    /// -# If the requested diagnostic mode supported , the update the service in the requested mode.
    if (serviceTableId < CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Last)
    {
        if ((mServiceHandlerConfiguration[serviceTableId].find(serviceId)) !=
            (mServiceHandlerConfiguration[serviceTableId].end()))
        {
            #ifdef UDSCFG_LOG_ENABLED
            // If the configuration already exists , then the request is discarded.
            LOGW(&gUdsBlServicesLogContext,"Requested service ID ",serviceId,"already exists.");
            #endif
        }
        else
        {
            #ifdef UDSCFG_LOG_ENABLED
            LOGI(
                &gUdsBlServicesLogContext,
                " New service added in Service Manager . Service Details ",
                " serviceTableId ",
                serviceTableId,
                " serviceId ",
                serviceId
                );
            #endif
            /// -# Update the Service handler configuration table.
            pTempServiceConfig = &mServiceHandlerConfiguration[serviceTableId][serviceId];
            pTempServiceConfig->mIsFunctionalRequestSupported= pServiceConfig->mIsFunctionalRequestSupported;
            pTempServiceConfig->mResponsePendingSupported= pServiceConfig->mResponsePendingSupported;
            pTempServiceConfig->mLengthCheckConditionType= pServiceConfig->mLengthCheckConditionType;
            pTempServiceConfig->mServiceRequestLength= pServiceConfig->mServiceRequestLength;
            pTempServiceConfig->mSupportedSessionMask= pServiceConfig->mSupportedSessionMask;
            pTempServiceConfig->mSupportedSecurityMask= pServiceConfig->mSupportedSecurityMask;
            pTempServiceConfig->mRequsestHandlerCbkFn= pServiceConfig->mRequsestHandlerCbkFn;
            pTempServiceConfig->mPostResponseHandlerCbkFn= pServiceConfig->mPostResponseHandlerCbkFn;
            pTempServiceConfig->mResetServiceHandlerCbkFn= pServiceConfig->mResetServiceHandlerCbkFn;

            #ifdef UDSCFG_LOG_ENABLED
            LOGD(
            &gUdsBlServicesLogContext,
            "mIsFunctionalRequestSupported = ",
            pServiceConfig->mIsFunctionalRequestSupported ,
            " mLengthCheckConditionType = ",
            pServiceConfig->mLengthCheckConditionType,
            " mServiceRequestLength = ",
            pServiceConfig->mServiceRequestLength,
            " mSupportedSessionMask = ",
            pServiceConfig->mSupportedSessionMask ,
            " mSupportedSecurityMask = ",
            pServiceConfig->mSupportedSecurityMask
            );
            #endif
        }

    }
}

CUdsServiceHandlerIf::ESecurityLevel_t CUdsServiceManager::getCurrentSecurityLevel(void)
{
    /// -# return current security level.
    return mCurrentSecurityLevel;
}

bool CUdsServiceManager::isPermmitedBySecurityLevel(CUdsServiceHandlerIf::ESecurityMask_t permittedSecurity)
{
    bool result;
    uint32_t shift_sess = static_cast<uint32_t>(1U) << static_cast<uint32_t>(this->mCurrentSecurityLevel);
    if( ( shift_sess & static_cast<uint32_t>(permittedSecurity) ) != 0U )
    {
        result = true;
    }
    else
    {
        printf("UDS: Diag not allowed by security: sess(%x&%x)permitted==0\n",permittedSecurity,shift_sess);
        result = false;
    }
    return result;
}

CUdsServiceHandlerIf::ESessionType_t CUdsServiceManager::getCurrentSession(void)
{
    ///-# return current session.
    return mCurrentSession;
}

void CUdsServiceManager::setCurrentSession(const CUdsServiceHandlerIf::ESessionType_t session)
{
    CUdsServiceHandlerIf::ResetServiceHandlerCbkFn_t resetServiceHandlerCbkFn;
    CUdsServiceHandlerIf::PostResponseHandlerCbkFn_t postResponseCbkFunc;

    /// -# Check if the request session is supported.
    if (session < CUdsServiceHandlerIf::ESessionType_t::ESessionType_Last)
    {

        /// -# Reset security level to default security level.
        setCurrentSecurityLevel(CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Default);
        /// -# Reset security level in 0x27 service handlers.
        if ((mServiceHandlerConfiguration[mCurrentServiceTableId].find(0x27U)) !=
            (mServiceHandlerConfiguration[mCurrentServiceTableId].end()))
        {
            resetServiceHandlerCbkFn = \
                    mServiceHandlerConfiguration[mCurrentServiceTableId][0x27U].mResetServiceHandlerCbkFn;
            if (resetServiceHandlerCbkFn != nullptr)
            {
                resetServiceHandlerCbkFn(0U);
            }
        }
        /// -# Reset Request Download service handlers.
       if ((mServiceHandlerConfiguration[mCurrentServiceTableId].find(0x34U)) !=
           (mServiceHandlerConfiguration[mCurrentServiceTableId].end()))
       {
           resetServiceHandlerCbkFn = \
                   mServiceHandlerConfiguration[mCurrentServiceTableId][0x34U].mResetServiceHandlerCbkFn;
           if (resetServiceHandlerCbkFn != nullptr)
           {
               resetServiceHandlerCbkFn(0U);
           }
       }

        /// @todo Notify session change to other components.

        ///-# Update current sesssion to requested session.
        mCurrentSession = session;
        printf("\n mCurrentSession : %d \n", mCurrentSession);


        postResponseCbkFunc = mServiceHandlerConfiguration[mCurrentServiceTableId][0x10U].mPostResponseHandlerCbkFn;

        if (postResponseCbkFunc != nullptr)
        {
            postResponseCbkFunc(0U);
        }

        #ifdef UDSCFG_LOG_ENABLED
        LOGI(&gUdsBlServicesLogContext,"Session level updated to new session ",static_cast<uint32_t>(mCurrentSession));
        #endif
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Invalid Session request",static_cast<uint32_t>(session));
        #endif
    }
}

void CUdsServiceManager::setCurrentSecurityLevel(const CUdsServiceHandlerIf::ESecurityLevel_t securityLevel)
{
    /// -# Check if the request security level is supported.
    if (securityLevel < CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Last)
    {
        /// -# If supported update the securityLevel to requested level.
        mCurrentSecurityLevel = securityLevel;
        // #ifdef UDSCFG_LOG_ENABLED
        /// @todo Notify security Level changes.
        LOGI(&gUdsBlServicesLogContext,"Security level updated to new security level ",mCurrentSecurityLevel);
        // #endif
    }
    else
    {
        // #ifdef UDSCFG_LOG_ENABLED
        LOGI(&gUdsBlServicesLogContext,"Invalid security Level request",static_cast<uint32_t>(securityLevel));
        // #endif
    }
}

void CUdsServiceManager::sessionTimeout(void)
{
    CUdsServiceHandlerIf::ResetServiceHandlerCbkFn_t resetServiceHandlerCbkFn;
    uint8_t serviceId;

    /// Set current session to default session only if the session is not in default session.
    if (mCurrentSession != CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession)
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGI(&gUdsBlServicesLogContext,"Session Time-out occurred  ");
        #endif
        /// Reset all services other than session and security.
        for(ServiceHandlerConfiguration_t::iterator tempService = mServiceHandlerConfiguration[mCurrentServiceTableId].begin();
            tempService != mServiceHandlerConfiguration[mCurrentServiceTableId].end();
            tempService++)
        {
            serviceId = tempService->first;
            if (( serviceId != 0x27U) && (serviceId != 0x10U))
            {
                resetServiceHandlerCbkFn = \
                                mServiceHandlerConfiguration[mCurrentServiceTableId][serviceId].mResetServiceHandlerCbkFn;
                if (resetServiceHandlerCbkFn!=nullptr)
                {
                    resetServiceHandlerCbkFn(0U);
                }
            }

        }
        /// Session and security resets done separately here.
        setCurrentSession(CUdsServiceHandlerIf::ESessionType_t::ESessionType_DefaultSession);
    }
}

void CUdsServiceManager::serviceTimeout(const uint16_t clientAddress)
{
    CUdsServiceHandlerIf::ResetServiceHandlerCbkFn_t resetServiceHandlerCbkFn;
    uint8_t serviceId;
    /// If the service Id supported , call the reset handler method of the requested
    /// service.
    if (isRequestInProgress(clientAddress) != false)
    {
        serviceId = mDiagnosticDataBufferControl[clientAddress].mServiceId;

        if ((mServiceHandlerConfiguration[mCurrentServiceTableId].find(serviceId)) !=
            (mServiceHandlerConfiguration[mCurrentServiceTableId].end()))
        {
            resetServiceHandlerCbkFn = \
                mServiceHandlerConfiguration[mCurrentServiceTableId][serviceId].mResetServiceHandlerCbkFn;

            if (resetServiceHandlerCbkFn != nullptr)
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGI(&gUdsBlServicesLogContext,"Service Time-out occurred ",serviceId);
                #endif
                resetServiceHandlerCbkFn(clientAddress);
            }
        }
    }
}

void CUdsServiceManager::sendNegativeResponse(const uint16_t clientAddress,const CUdsServiceHandlerIf::EResponseCode_t nrc)
{
    // DK message structure used for updating Negative response.
    UdsServiceResponseTransmitRequest DkMsgUdsServiceResponseTransmitRequest;

    ///-# Update DK message for sending response message
    if (isRequestInProgress(clientAddress) != false)
    {
        SDiagnosticDataBufferControl_t &pDiagnosticDataBufferControl = mDiagnosticDataBufferControl[clientAddress];
        if(nrc == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending)
        {
            DkMsgUdsServiceResponseTransmitRequest.responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Rcrrp;
        }
        else
        {
            DkMsgUdsServiceResponseTransmitRequest.responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Negative;
            pDiagnosticDataBufferControl.mDiagServiceManagerState = EDiagServiceManagerState_WaitingForRequest;
        }
        DkMsgUdsServiceResponseTransmitRequest.dataLen  = 0x3U;
        DkMsgUdsServiceResponseTransmitRequest.data[0]  = 0x7fU;
        DkMsgUdsServiceResponseTransmitRequest.data[1]  = pDiagnosticDataBufferControl.mServiceId;
        DkMsgUdsServiceResponseTransmitRequest.data[2]  = nrc;
        DkMsgUdsServiceResponseTransmitRequest.clientAddress  = clientAddress;
        DkMsgUdsServiceResponseTransmitRequest.serviceId = pDiagnosticDataBufferControl.mServiceId ;

        ///-# set diagManager state to EDiagServiceManagerState_WaitingForRequest to process new request or
        /// transmit confirmation.
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Negative response send for client address ",clientAddress,
            " negative response code ",nrc);
        #endif
        // Send response message to UDS core
        DK_RTE_Send_UdsServiceResponseTransmitRequest(DkMsgUdsServiceResponseTransmitRequest);
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Negative response not send as the request doesn't exists for client address ",
            clientAddress);
        #endif
    }
}

void CUdsServiceManager::updateDiagnosticMode(const CUdsServiceManager::EDiagnosticMode_t mode)
{
    if (mode < CUdsServiceManager::EDiagnosticMode_t::EDiagnosticMode_Last)
    {
        mCurrentDiagnosticMode = mode;
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," current diag mode updated =  ",static_cast<uint32_t>(mCurrentDiagnosticMode));
        #endif
        // DK send message
        UdsCurrentMode DKMsgUdsCurrentMode;
        DKMsgUdsCurrentMode.currentMode = static_cast<uint8_t>(mCurrentDiagnosticMode);
        DK_RTE_Send_UdsCurrentMode(DKMsgUdsCurrentMode);
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Invalid diag mode request =  ",static_cast<uint32_t>(mode));
        #endif
    }
}


bool CUdsServiceManager::isRequestInProgress(const uint16_t clientAddress)
{
    bool status = false;
    if (mDiagnosticDataBufferControl.find(clientAddress) != mDiagnosticDataBufferControl.end())
    {
        status = true;
    }
    return status;
}

bool CUdsServiceManager::oemRequestConditionCheck(const uint16_t clientAddress,const uint8_t serviceId)
{
    bool requestStatus = false;
    EAddressMode_t addressType;
    uint8_t noOfRequestInProgress;

    if((std::find(mDiagModeAddress.begin(),mDiagModeAddress.end(),clientAddress)) != mDiagModeAddress.end())
    {
        addressType = EAddressMode_DiagClient;
        mDiagnosticModeTimer = mDiagnosticModeTimeCountInMs;
    }
    else if((std::find(mFotaModeAddress.begin(),mFotaModeAddress.end(),clientAddress)) != mFotaModeAddress.end())
    {
        addressType = EAddressMode_FotaClient;
    }
    else
    {
        addressType = EAddressMode_Last;
    }

    noOfRequestInProgress = static_cast<uint8_t>(mDiagnosticDataBufferControl.size());
    if (addressType != EAddressMode_Last)
    {
        if ((serviceId == 0x22U) || \
            (serviceId == 0x19U))
        {
                requestStatus = true;
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Request service is ",serviceId," oemRequestConditionCheck ",static_cast<uint32_t>(requestStatus));
                #endif
        }
        else
        {
            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext,"noOfRequestInProgress ",static_cast<uint32_t>(noOfRequestInProgress));
            #endif
            // If any other service is already in progress then send NRC $21.
            if (noOfRequestInProgress != 0U)
            {
                requestStatus = false;
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," mDiagServiceManagerState is not in \
                        EDiagServiceManagerState_WaitingForRequest . NRC 0x21 send");
                #endif
            }
            else
            {
                requestStatus = true;
            }

            if ((mCurrentDiagnosticMode == EDiagnosticMode_FotaMode) && \
                (addressType == EAddressMode_DiagClient))
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Diag mode change requested to EDiagnosticMode_DiagMode ");
                #endif
                updateDiagnosticMode(EDiagnosticMode_DiagMode);
            }
        }
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Invalid diag address type =  ",static_cast<uint32_t>(addressType));
        #endif
    }

    return requestStatus;
}

void CUdsServiceManager::serviceRequestHandler
(
    const uint16_t clientAddress,
    const uint8_t requestType,
    const uint16_t requestDatalength,
    const uint8_t *const pRequestDataBuffer
)
{
    // if already a request is processed and then a request for same client received sent NRC $21
    // fota mode -> Diag mode : when receives request from diag tool ID except services $19 and $22.
    // Diag mode -> fota mode : when there is no communication with more than 5s.
    // NRC $21 should be sent in diag mode , when there is request from FOTA GW
    // +ve response should be sent in fota mode , request $22 and $19 service should be processed and response should
    // send.

    // DK message structure used for updating Negative response.
    UdsServiceResponseTransmitRequest DkMsgUdsServiceResponseTransmitRequest;

    if (isRequestInProgress(clientAddress) != true)
    {
        if (oemRequestConditionCheck(clientAddress,pRequestDataBuffer[0]) != false)
        {
            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext," New request accepted clientAddress ", clientAddress,
                " service ID ", static_cast<uint32_t>(pRequestDataBuffer[0]));
            #endif
            SDiagnosticDataBufferControl_t &pDiagnosticDataBufferControl = mDiagnosticDataBufferControl[clientAddress];
            pDiagnosticDataBufferControl.mAddressType = requestType;
            pDiagnosticDataBufferControl.mServiceId = pRequestDataBuffer[0];
            pDiagnosticDataBufferControl.mResponseType = EResponse_Last;
            pDiagnosticDataBufferControl.mDiagServiceManagerState = EDiagServiceManagerState_ProcessingReceivedRequest;
            pDiagnosticDataBufferControl.mData.insert(pDiagnosticDataBufferControl.mData.begin(),
                                pRequestDataBuffer,pRequestDataBuffer+requestDatalength);
        }
        else
        {
            #ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext," oemRequestConditionCheck failed  clientAddress . NRC 21 transmission \
                triggered ", clientAddress);
            #endif
            DkMsgUdsServiceResponseTransmitRequest.responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_BusyNRC;
            DkMsgUdsServiceResponseTransmitRequest.clientAddress = clientAddress;
            DkMsgUdsServiceResponseTransmitRequest.serviceId = pRequestDataBuffer[0];
            DkMsgUdsServiceResponseTransmitRequest.dataLen = 0x3U;
            DkMsgUdsServiceResponseTransmitRequest.data[0] = 0x7fU;
            DkMsgUdsServiceResponseTransmitRequest.data[1] = pRequestDataBuffer[0];
            DkMsgUdsServiceResponseTransmitRequest.data[2] = \
                                    CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_BusyRepeatRequest;
            /// -# Send DK message for negative response to UdsCore
            DK_RTE_Send_UdsServiceResponseTransmitRequest(DkMsgUdsServiceResponseTransmitRequest);
        }
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Request not accepted Client address already in progress . clientAddress ",
                clientAddress);
        #endif
    }
}

void CUdsServiceManager::serviceTransmitConfirmation
(
const uint16_t clientAddress,
const CUdsServiceManagerIf::EResponseType_t responseType
)
{
    CUdsServiceHandlerIf::PostResponseHandlerCbkFn_t postResponseHandlerCbkFn;
    uint8_t serviceId;
    if (isRequestInProgress(clientAddress) != false)
    {
        serviceId = mDiagnosticDataBufferControl[clientAddress].mServiceId;
        /// -# check if the service is supported in current diagnostic mode and invoke the service's post handler function.
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Message Confirmation is received for response type ", static_cast<uint32_t>(responseType) );
        #endif
        if ( mServiceHandlerConfiguration[mCurrentServiceTableId].find(serviceId) != \
                mServiceHandlerConfiguration[mCurrentServiceTableId].end())
        {
            postResponseHandlerCbkFn = \
                mServiceHandlerConfiguration[mCurrentServiceTableId][serviceId].mPostResponseHandlerCbkFn;
            if (postResponseHandlerCbkFn != nullptr)
            {
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext,"Post Handler function Invoked");
                #endif
                postResponseHandlerCbkFn(clientAddress);
            }
        }
        /// erase the element
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," request connection removed clientAddress ",clientAddress);
        #endif
        (void)mDiagnosticDataBufferControl.erase(clientAddress);
    }
    else
    {
        #ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Request not accepted Client address already in progress . clientAddress ",
                clientAddress);
        #endif
    }
}



void CUdsServiceManager::serviceManagerStateProcessing(void)
{
    CUdsServiceHandlerIf::SServiceConfig_t * pTempServiceConfig;
    CUdsServiceHandlerIf::EResponseCode_t responseCode;
    CUdsServiceHandlerIf::ESecurityLevel_t currSecurityLevel;
    CUdsServiceHandlerIf::ESessionType_t   currSession;
    DiagnosticDataBufferControl_t::iterator iter;
    uint8_t currentServiceId;
    uint16_t clientAddress;
    uint16_t currentServiceRequestLength;

    for (iter=mDiagnosticDataBufferControl.begin();iter != mDiagnosticDataBufferControl.end();++iter)
    {
        /// -# Set responseCode as NoError, assuming service pre-check passes.
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        SDiagnosticDataBufferControl_t &pDiagnosticDataBufferControl = iter->second;
        clientAddress = iter->first;
        currentServiceId= pDiagnosticDataBufferControl.mServiceId;
        currentServiceRequestLength = static_cast<uint16_t>(pDiagnosticDataBufferControl.mData.size());
        /// -# if service manager state is EDiagServiceManagerState_ProcessingReceivedRequest, then process the
        ///  received request.
        if (pDiagnosticDataBufferControl.mDiagServiceManagerState == EDiagServiceManagerState_ProcessingReceivedRequest)
        {
            /// -# Iterate over the service configuration to check if the requested service supported in the current
            /// diagnostic mode. If the service is not supported in the current diagnostic mode, then send service
            /// not supported ServiceNotSupported Negative response.
            if ( mServiceHandlerConfiguration[mCurrentServiceTableId].find(currentServiceId) != \
                mServiceHandlerConfiguration[mCurrentServiceTableId].end())
            {
                /// -# Get current session and security level.
                currSecurityLevel = getCurrentSecurityLevel();
                currSession       = getCurrentSession();
                /// -# Get the configuration of the requested service.
                pTempServiceConfig = &mServiceHandlerConfiguration[mCurrentServiceTableId][currentServiceId];
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(&gUdsBlServicesLogContext," Configuration of the requested service ",
                        " currentServiceId", static_cast<uint32_t>(currentServiceId),
                        " mServiceRequestLength", static_cast<uint32_t>(pTempServiceConfig->mServiceRequestLength),
                        " currentServiceRequestLength", static_cast<uint32_t>(currentServiceRequestLength),
                        " currSecurityLevel", static_cast<uint32_t>(currSecurityLevel),
                        " currSession", static_cast<uint32_t>(currSession),
                        " Supported Sess Mask: ", static_cast<uint32_t>(pTempServiceConfig->mSupportedSessionMask),
                        " mIsFunctionalRequestSupported: ", static_cast<uint32_t>(pTempServiceConfig->mIsFunctionalRequestSupported)
                        );
                #endif
                /// -# If the requested service not supported in current session , update response as
                /// ServiceNotSupportedInActiveSession
                if ( ((pDiagnosticDataBufferControl.mAddressType == 0x01U ) && \
                     (pTempServiceConfig->mIsFunctionalRequestSupported)) || \
                     (pDiagnosticDataBufferControl.mAddressType == 0x00U))
                {
                    if ((static_cast<uint32_t>(static_cast<uint32_t>(1U) << static_cast<uint32_t>(currSession)) & \
                        (pTempServiceConfig->mSupportedSessionMask)) == 0U)
                    {
                        #ifdef UDSCFG_LOG_ENABLED
                        LOGD(&gUdsBlServicesLogContext," Service not supported in Active Session ",
                                currSession,
                                " Sess Mask",
                                static_cast<uint32_t>(pTempServiceConfig->mSupportedSessionMask));
                        #endif
                        responseCode = \
                        CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ServiceNotSupportedInActiveSession;
                    }
                    else if ( false == isPermmitedBySecurityLevel(pTempServiceConfig->mSupportedSecurityMask) )
                    {
                        /// -# If the requested service not supported in current security level , update response as
                        /// SecurityAccessDenied
                        #ifdef UDSCFG_LOG_ENABLED
                        LOGD(&gUdsBlServicesLogContext," SecurityAccessDenied Current Sec Level ",
                                currSecurityLevel,
                                " Supported Sec Mask: ",
                                static_cast<uint32_t>(pTempServiceConfig->mSupportedSecurityMask));
                        #endif
                        responseCode = \
                        CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
                    }
                    else
                    {
                        /// -# If the requested service length not matches with the configured length then update
                        /// response as InvalidFormat
                        if (pTempServiceConfig->mLengthCheckConditionType == \
                            CUdsServiceHandlerIf::ELengthCheckConditionType_t::ELengthCheckCondition_Equal)
                        {
                            if (pTempServiceConfig->mServiceRequestLength != currentServiceRequestLength)
                            {
                                responseCode = CUdsServiceHandlerIf::EResponseCode_t::\
                                                EResponseCode_IncorrectMessageLengthOrInvalidFormat;
                            }
                        }
                        else
                        {
                            if (pTempServiceConfig->mServiceRequestLength > currentServiceRequestLength)
                            {
                                responseCode = CUdsServiceHandlerIf::EResponseCode_t::\
                                                EResponseCode_IncorrectMessageLengthOrInvalidFormat;
                            }
                        }
                    }
                }
                else
                {
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ServiceNotSupported;
                }
            }
            else
            {
                /// If the service is not supported in the current diagnostic mode, then send service not supported
                /// 0x11u Negative response.
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ServiceNotSupported;
            }


            if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
            {
                ///  Update the CUdsServiceManager state to EDiagServiceManagerState_WaitingForResponse
                pDiagnosticDataBufferControl.mDiagServiceManagerState = EDiagServiceManagerState_WaitingForResponse;
               /*
                #ifdef UDSCFG_LOG_ENABLED
                LOGD(
                    &gUdsBlServicesLogContext,
                    " mDiagServiceManagerState set to EDiagServiceManagerState_WaitingForResponse",
                    "Response Pending Supported ",
                    pTempServiceConfig->mResponsePendingSupported
                    );
                #endif
                */
                if(pTempServiceConfig->mResponsePendingSupported == true)
                {
                    #ifdef UDSCFG_LOG_ENABLED
                    LOGD(&gUdsBlServicesLogContext, " pTempServiceConfig->mResponsePendingSupported is true ");
                    #endif
                    //send pending response
                    sendNegativeResponse(clientAddress, \
                          CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending);
                }

                /// If the service request is valid , Notify invoke the corresponding service handler.
                if (pTempServiceConfig->mRequsestHandlerCbkFn != nullptr)
                {
                    #ifdef UDSCFG_LOG_ENABLED
                    LOGD(&gUdsBlServicesLogContext, " mRequsestHandlerCbkFn Invoked  currentServiceId ", static_cast<uint32_t>(currentServiceId));
                    #endif
                    pTempServiceConfig->mRequsestHandlerCbkFn(clientAddress,
                                                              &pDiagnosticDataBufferControl.mData[1],
                            static_cast<uint16_t>(static_cast<uint32_t>(pDiagnosticDataBufferControl.mData.size())-1U));
                }

            }
            else
            {
                #ifdef UDSCFG_LOG_ENABLED
                ///-# If request not accepted then send negative response.
                LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", static_cast<uint32_t>(responseCode));
                #endif
                sendNegativeResponse(clientAddress,responseCode);
            }
        }
        else if(pDiagnosticDataBufferControl.mDiagServiceManagerState == EDiagServiceManagerState_WaitingForResponse)
        {
            // The response updated by service handler are handled by serviceResponseUpdate function.
        }
        else
        {
            // Process post handling tasks when confirmation is received for a serviceId.
        }
    }
    if(mIsSuppressReqForSession)
    {
        
    	CUdsServiceHandlerIf::PostResponseHandlerCbkFn_t postResponseHandlerCbkFn;

    	if (isRequestInProgress(mCacheClientAddr) != false)
    	{

    		if ((mServiceHandlerConfiguration[mCurrentServiceTableId].find(0x27U)) !=
    				(mServiceHandlerConfiguration[mCurrentServiceTableId].end()))
    		{
    			postResponseHandlerCbkFn = \
    					mServiceHandlerConfiguration[mCurrentServiceTableId][0x27U].mPostResponseHandlerCbkFn;;
    			if (postResponseHandlerCbkFn != nullptr)
    			{
    				postResponseHandlerCbkFn(mCacheClientAddr);
    			}
    			(void)mDiagnosticDataBufferControl.erase(mCacheClientAddr);
    		}
    	}
    	mIsSuppressReqForSession=0;
    	mCacheClientAddr=0;
    }
}


void CUdsServiceManager::setDiagnosticModeAddress
(
const std::vector<uint16_t> &addressList,
const CUdsServiceManager::EAddressMode_t mode
)
{
    switch(mode)
    {
        case CUdsServiceManager::EAddressMode_t::EAddressMode_FotaClient:
            mFotaModeAddress.assign(addressList.begin(),addressList.end());
            break;

        case CUdsServiceManager::EAddressMode_t::EAddressMode_DiagClient:
            mDiagModeAddress.assign(addressList.begin(),addressList.end());
            break;

        default:
            break;
    }
}



void CUdsServiceManager::onReceiveDKMsgInstallerUdsVerifyResp(InstallerUdsVerifyResp & msg)
{
/// Start of user code : User code for function onReceiveDKMsgInstallerUdsVerifyResp in file c_uds_service_manager_component.cpp

/// End of user code
}

void CUdsServiceManager::onReceiveDkMsgInstallerUdsDigestReadResp(InstallerUdsDigestReadResp & msg)
{
/// Start of user code : User code for function onReceiveDkMsgInstallerUdsDigestReadResp in file c_uds_service_manager_component.cpp

/// End of user code
}

void CUdsServiceManager::onReceiveDkMsgInstallerUdsDigestWriteResp(InstallerUdsDigestWriteResp & msg)
{
/// Start of user code : User code for function onReceiveDkMsgInstallerUdsDigestWriteResp in file c_uds_service_manager_component.cpp

/// End of user code
}



} // udsblservices
} // app
} // dk
