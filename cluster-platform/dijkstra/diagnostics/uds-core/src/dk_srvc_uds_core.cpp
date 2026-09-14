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
#include"dk_srvc_uds_core.h"
#include <string>
#include "dk_srvc_uds_tp_doip.h"

namespace dk
{
namespace srvc
{
namespace udscore
{
// public method implementation

#ifdef UDSCORE_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsCoreLogContext);
#endif

void CUdsCore::onInit(void)
{
#ifdef UDSCORE_LOG_ENABLED
    LOGV(&gUdsCoreLogContext,"CUdsCore onInit method invoked.");
#endif
    mDiagnosticConnection.clear();
    ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
    {
        std::lock_guard<std::mutex> guard ( mS3TimeoutMutex);
        mSessionTimer = 0U;
    }
}

void CUdsCore::onExit(void)
{
#ifdef UDSCORE_LOG_ENABLED
    LOGV(&gUdsCoreLogContext,"CUdsCore onExit method invoked.");
#endif
}

void CUdsCore::diagnosticMainFunction(void)
{
    UdsServiceReqIndication  DkMsgUdsServiceRequestIndication;
    ConnectionStatusMap_t::iterator mapIt;
#ifdef UDSCORE_LOG_ENABLED
    // LOGV(&gUdsCoreLogContext,"Periodic task for UdsCore invoked");	/* dkasiman commented */
#endif

    /// Session timer handling
    sessionTimerProcessing();
    /// diagnostic request state handling
    for(mapIt = mDiagnosticConnection.begin(); mapIt != mDiagnosticConnection.end(); ++mapIt)
    {
        SServiceTimerConfig_t * serviceTimer = &(mapIt->second).mServiceTimerConfig;
        switch(mapIt->second.mCurrentRequestState)
        {
        case EDiagnosticProcesingState_t::EDiagnosticProcesingState_RxProcessing:
            /// New request dispatch handling.
            mapIt->second.mCurrentRequestState = EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse;

            DkMsgUdsServiceRequestIndication.requestType = (mapIt->second).mCurrentRequestType;
            (void)memset(static_cast<uint8_t *>(&DkMsgUdsServiceRequestIndication.data[0]),0,
                         (mapIt->second).mDataBuffer.size());

            (void)std::copy((mapIt->second).mDataBuffer.begin(),(mapIt->second).mDataBuffer.end(),
                            &(DkMsgUdsServiceRequestIndication.data[0]));

            DkMsgUdsServiceRequestIndication.dataLen = static_cast<uint16_t>((mapIt->second).mDataBuffer.size());
            DkMsgUdsServiceRequestIndication.serviceId = (mapIt->second).mDataBuffer[0];
            DkMsgUdsServiceRequestIndication.clientAddress = mapIt->first;
            // send request indication message.
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,"DkMsgUdsServiceRequestIndication message notification . clientAddress = ",
                 DkMsgUdsServiceRequestIndication.clientAddress,
                 "dataLen = ",
                 DkMsgUdsServiceRequestIndication.dataLen,
                 "serviceId = ",
                 DkMsgUdsServiceRequestIndication.serviceId);
#endif
#ifdef DUAL_INSTANCE_POC
            if(DkMsgUdsServiceRequestIndication.clientAddress == mUdsCoreConfig.mFtoolAddress)// FTOOL_ADDR)
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext, "Sending request indication  for ftool");
#endif
                DK_RTE_Send_UdsServiceReqIndication(DkMsgUdsServiceRequestIndication);

            }
            else if((DkMsgUdsServiceRequestIndication.clientAddress == mUdsCoreConfig.mDtoolAddress) || (DkMsgUdsServiceRequestIndication.clientAddress == mUdsCoreConfig.mRdiagAddress))//DTOOL_ADDR)
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext, "Sending request indication for dtool");
#endif
                DK_RTE_Send_UdsServiceReqIndication_DTool(DkMsgUdsServiceRequestIndication);

            }
            else
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext, "Sending request for unknown tool address",DkMsgUdsServiceRequestIndication.clientAddress);
#endif
            }
#else
            DK_RTE_Send_UdsServiceReqIndication(DkMsgUdsServiceRequestIndication);
#endif
            break;

        case EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse:
            /// Service Timer handling
            if (serviceTimer->mP4Timer > 0U)
            {
                ///< get the current time stamp
                uint32_t lCurrentTimeStampMs = nowTimeMs();
                if(lCurrentTimeStampMs > (serviceTimer->mP4Timer) )
                {
#ifdef UDSCORE_LOG_ENABLED
                    LOGD(&gUdsCoreLogContext,"mP4Timer time-out occurred.");
#endif

                    ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
                    {
                        std::lock_guard<std::mutex> guard ( mP2P4P2StarTimeoutMutex );
                        serviceTimer->mP2Timer = 0U;
                        serviceTimer->mP4Timer = 0U;
                    }


                    serviceTimeout(mapIt->first);
                }
            }

            if (serviceTimer->mP2Timer > 0U)
            {
                uint32_t lCurrentTimeStampMs = nowTimeMs();

                if(lCurrentTimeStampMs > (serviceTimer->mP2Timer) )
                {
                    /// If RCRRP is supported , then update the time-out.
                    if ((mapIt->second).mPendingResponseSupport == true)
                    {
#ifdef UDSCORE_LOG_ENABLED
                        LOGD(&gUdsCoreLogContext,"mP2Timer time-out occurred with Pending Response Supported serviceTimer->mP4Timer",serviceTimer->mP4Timer);
#endif
                        sendResponsePending(mapIt->first); // send NRC 0x78
                        ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
                        {
                            std::lock_guard<std::mutex> guard ( mP2P4P2StarTimeoutMutex );
                            serviceTimer->mP2Timer = mUdsCoreConfig.mP2StarTimeCountInMs + (nowTimeMs());
                        }
                    }

                    else
                    {
#ifdef UDSCORE_LOG_ENABLED
                        LOGD(&gUdsCoreLogContext,"mP2Timer time-out occurred with Pending Response not Supported.");
#endif
                        ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
                        {
                            std::lock_guard<std::mutex> guard ( mP2P4P2StarTimeoutMutex );
                            serviceTimer->mP4Timer = 0U;
                            serviceTimer->mP2Timer = 0U;
                        }
                        serviceTimeout(mapIt->first);
                    }
                }
            }
            break;

        case EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse:
            if (mapIt->second.mCurrentResponseType == EResponse_Positive)
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,
                     "EDiagnosticProcesingState_TransmitResponse , Positive response transmission invoked",
                     "clientAddress = ",mapIt->first);
#endif
                if (mpTpInstance!= nullptr)
                {
                    (void)mpTpInstance->transmitDataRequest(&(mapIt->second).mDataBuffer[0],
                                                            static_cast<uint16_t>((mapIt->second).mDataBuffer.size()),mapIt->first);
                }
            }
            else
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,
                     "EDiagnosticProcesingState_TransmitResponse , Negative response transmission invoked",
                     "clientAddress = ",mapIt->first);
#endif
                if (mpTpInstance!= nullptr)
                {
                    (void)mpTpInstance->transmitDataRequest(&(mapIt->second).mNegativeResponseBuffer[0],3U,
                                                            mapIt->first);
                }
            }
            mapIt->second.mCurrentRequestState = EDiagnosticProcesingState_t::EDiagnosticProcesingState_ResponseConfirmation;
            break;

        case EDiagnosticProcesingState_t::EDiagnosticProcesingState_ResponseConfirmation:
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,"EDiagnosticProcesingState_ResponseConfirmation state ");
#endif
            break;

        default:
#ifdef UDSCORE_LOG_ENABLED
            LOGV(&gUdsCoreLogContext,"EDiagnosticProcesingState_t default state ");
#endif
            break;
        }
    }
}

bool CUdsCore::requestIndication
(
    const uint8_t *const pDataBuffer,
    const uint16_t dataLength,
    const CUdsCoreIf::ERequestType_t requestType,
    const uint16_t clientAddress
)
{
    uint8_t negativeRespose[3];     // Buffer to pack the Negative response.
    EResponseType_t responseType;   // response type for invalid case .
    responseType = EResponse_Negative;
    uint8_t responseCode = mNoError;           // request acceptance failure code.
    bool requestStatus = false;             // request acceptance status.

    if((pDataBuffer!= nullptr) && ((dataLength>0U) && (dataLength < mUdsDiagBufferSizeSupported)))
    {
        stopSessionTimer();
        /// Check whether the connection is available for client address
        if (mDiagnosticConnection.find(clientAddress) == mDiagnosticConnection.end())  //gbl variable to check.
        {
            /// if connection already not created, then create the new connection
            mDiagnosticConnection[clientAddress].mCurrentRequestState = EDiagnosticProcesingState_RxProcessing;
            mDiagnosticConnection[clientAddress].mCurrentRequestType = requestType;
            mDiagnosticConnection[clientAddress].mCurrentServiceId = pDataBuffer[0];
            mDiagnosticConnection[clientAddress].mPendingResponseSupport = false;
            mDiagnosticConnection[clientAddress].mResponsePendingTransmitStatus = false;
            mDiagnosticConnection[clientAddress].mCurrentResponseType = CUdsCore::EResponseType_t::EResponse_Last;
            ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
            {
                std::lock_guard<std::mutex> guard ( mP2P4P2StarTimeoutMutex );
                mDiagnosticConnection[clientAddress].mServiceTimerConfig.mP2Timer = mUdsCoreConfig.mP2TimeCountInMs + (nowTimeMs());
                mDiagnosticConnection[clientAddress].mServiceTimerConfig.mP4Timer = mUdsCoreConfig.mP4TimeCountInMs + (nowTimeMs());
            }

            mDiagnosticConnection[clientAddress].mDataBuffer.clear();
            mDiagnosticConnection[clientAddress].mDataBuffer.insert( mDiagnosticConnection[clientAddress].mDataBuffer.begin(),pDataBuffer,&pDataBuffer[dataLength]);

            // vector allocation fail check
            if (static_cast<uint16_t>(mDiagnosticConnection[clientAddress].mDataBuffer.size()) != dataLength)
            {
                /// -# If requested length greater than available buffer size ,then update the responseCode as 0x10
                /// General reject negative response code. The diagnostic request shall be rejected.
                responseCode = mGeneralRejectNegativeResponseCode;
                responseType = EResponse_Negative;
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,
                     "Diagnostic message request received but vector data allocation fails . Client Address ",
                     clientAddress);
#endif
            }
            else
            {
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,
                     "Valid Diagnostic message request received .Client Address ",
                     clientAddress);
#endif
                requestStatus = true;
            }
        }
        else
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,
                 "Diagnostic message request received but Client connection already exists . Client Address ",
                 clientAddress," Busy repeat request sent ");
#endif
            responseCode = mBusyRepeatRequestNegativeResponseCode;
            responseType = EResponse_BusyNRC;
        }
    }
    else
    {
        responseCode = mGeneralRejectNegativeResponseCode;
        responseType = EResponse_Negative;
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             "Diagnostic message request received with nullBuffer data or datalength as ",dataLength);
#endif
    }

    if ((responseCode != mNoError) && (pDataBuffer!= nullptr))
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(
            &gUdsCoreLogContext,
            "Diagnostic message request not accepted .Hence NRC is sent",
            responseCode
        );
#endif
        /// -# If the request is not accepted , then pack the negative response response and trigger the diagnostic
        /// response transmission.Also update the requestStatus as false.
        negativeRespose[0] = 0x7fU;
        negativeRespose[1] = pDataBuffer[0];
        negativeRespose[2] = responseCode;
        updateResponse(responseType,clientAddress,static_cast<uint16_t>(3U),&negativeRespose[0]);
        requestStatus = false;
    }

    /// -# Return the request status.
    return requestStatus;
}

void CUdsCore::updateResponse
(
    const EResponseType_t responseType,
    const uint16_t clientAddress,
    const uint16_t responseDataLength,
    const uint8_t * const pResponseData
)
{
    CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
        if(pConnetionStatus->mCurrentRequestState == EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse)
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,
                 "Diagnostic response update received Client Address ",clientAddress," response type ",
                 responseType," mCurrentRequestState ",pConnetionStatus->mCurrentRequestState);
#endif
            switch(responseType)
            {
            case EResponse_Positive:
                pConnetionStatus->mDataBuffer.clear();
                pConnetionStatus->mDataBuffer.insert(pConnetionStatus->mDataBuffer.end(),
                                                     pResponseData,&pResponseData[responseDataLength]);
                pConnetionStatus->mCurrentRequestState = \
                        EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse;
                pConnetionStatus->mCurrentResponseType = responseType;
                break;

            case EResponse_Negative:
            case EResponse_BusyNRC:
                /// @TODO: Add a exception NRC list for functional request.
                (void)memcpy(pConnetionStatus->mNegativeResponseBuffer,pResponseData,3U);
                pConnetionStatus->mCurrentRequestState = \
                        EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse;
                pConnetionStatus->mCurrentResponseType = responseType;
                break;

            case EResponse_Rcrrp:
                /// Update only when the response is not updated.
                if (pConnetionStatus->mCurrentResponseType == CUdsCore::EResponseType_t::EResponse_Last)
                {
                    pConnetionStatus->mPendingResponseSupport = true;
                }
                break;

            default: // case EResponse_Suppress:
                // Trigger post processing response.
                serviceProcessingDone(clientAddress);
                break;
            }
        }
        else
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,
                 "Diagnostic response update received Client Address ",clientAddress," with response type ",responseType,
                 " with mCurrentRequestState as ",pConnetionStatus->mCurrentRequestState);
#endif
        }
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             "Diagnostic response update received for terminated connection Client Address ",clientAddress,
             " with response type ",responseType);
#endif
    }

}

void CUdsCore::transmitConfirmation(const bool transmitStatus,const uint16_t clientAddress)
{
    CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
        /// Check if the last transmission is the response pending transmission.
        if (pConnetionStatus->mResponsePendingTransmitStatus != true)
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,
                 "Diagnostic response transmit confirmation received for clientAddress ",clientAddress,
                 " with transmitStatus ",transmitStatus);
#endif
            if (transmitStatus == true)
            {
                pConnetionStatus->mCurrentRequestState = EDiagnosticProcesingState_Idle;
                /// notify the confirmation status to services to handle the post processing.
                notifyTransmitConfirmation(clientAddress);
            }
            serviceProcessingDone(clientAddress);
        }
        else
        {
            pConnetionStatus->mResponsePendingTransmitStatus = false;
        }
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             "Diagnostic response transmit confirmation received for terminated connection Client Address ",clientAddress,
             " with transmitStatus ",transmitStatus);
#endif
    }
}

void CUdsCore::reStartSessionTimer(void)
{
    startSessionTimer();
}

void CUdsCore::setTimingParameters
(
    const uint32_t p2TimeCountInMs,
    const uint32_t p2StarTimeCountInMs,
    const uint32_t p4TimeCountInMs
)
{
    /// -# Update the P2 and P2 star timeCount.
    mUdsCoreConfig.mP2TimeCountInMs     = p2TimeCountInMs;
    mUdsCoreConfig.mP2StarTimeCountInMs = p2StarTimeCountInMs;
    mUdsCoreConfig.mP4TimeCountInMs = p4TimeCountInMs;
#ifdef UDSCORE_LOG_ENABLED
    LOGD(
        &gUdsCoreLogContext,
        "Uds P2 Timing parameters updated",
        "mP2TimeCountInMs = ",
        mUdsCoreConfig.mP2TimeCountInMs,
        "mP2StarTimeCountInMs = ",
        mUdsCoreConfig.mP2StarTimeCountInMs,
        "mP4TimeCountInMs = ",
        mUdsCoreConfig.mP4TimeCountInMs
    );
#endif
}

void CUdsCore::setUdsTpIf(CUdsTpIf * const pUdsTpIf)
{
    /// -# set Tp instance to CUdsCore instance.
    mpTpInstance = pUdsTpIf;
#ifdef UDSCORE_LOG_ENABLED
    LOGV( &gUdsCoreLogContext, "UdsTpIf Instance is updated for UdsCore");
#endif
}

// Private method implementation

void CUdsCore::notifyTransmitConfirmation(const uint16_t clientAddress)
{
    UdsServiceResponseTransmitConfirmation DkMsgUdsServiceResponseTransmitConfirmation;
    const CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             "DkMsgUdsServiceResponseTransmitConfirmation message transmission for  clientAddress ",clientAddress);
#endif
        DkMsgUdsServiceResponseTransmitConfirmation.responseType = pConnetionStatus->mCurrentRequestType;
        DkMsgUdsServiceResponseTransmitConfirmation.serviceId = pConnetionStatus->mCurrentServiceId;
        DkMsgUdsServiceResponseTransmitConfirmation.clientAddress = clientAddress;
#ifdef DUAL_INSTANCE_POC
        if( DkMsgUdsServiceResponseTransmitConfirmation.clientAddress == mUdsCoreConfig.mFtoolAddress) //FTOOL_ADDR)
        {

#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext, "Response transmission confirm for ftool");
#endif
            DK_RTE_Send_UdsServiceResponseTransmitConfirmation(DkMsgUdsServiceResponseTransmitConfirmation); ///< modified
        }
        else if (( DkMsgUdsServiceResponseTransmitConfirmation.clientAddress == mUdsCoreConfig.mDtoolAddress) || ( DkMsgUdsServiceResponseTransmitConfirmation.clientAddress == mUdsCoreConfig.mRdiagAddress))//DTOOL_ADDR)
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext, "Response transmission confirm for dtool");
#endif
            DK_RTE_Send_UdsServiceResponseTransmitConfirmation_DTool(DkMsgUdsServiceResponseTransmitConfirmation); ///<modified
        }
        else
        {
            LOGD(&gUdsCoreLogContext, "Response transmission confirm for unknow tool address",DkMsgUdsServiceResponseTransmitConfirmation.clientAddress);
        }
#else
        DK_RTE_Send_UdsServiceResponseTransmitConfirmation(DkMsgUdsServiceResponseTransmitConfirmation); ///<modified
#endif


    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             "DkMsgUdsServiceResponseTransmitConfirmation message transmission for terminated clientAddress ",
             clientAddress);
#endif
    }
}

void CUdsCore::serviceProcessingDone(const uint16_t clientAddress)
{
    /// -# Stopping P2 / P4 /P2Star Timer
    CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
        {
            ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
            std::lock_guard<std::mutex> guard ( mP2P4P2StarTimeoutMutex );
            pConnetionStatus->mServiceTimerConfig.mP2Timer = 0x0U;
            pConnetionStatus->mServiceTimerConfig.mP4Timer = 0x0U;
        }
        (void)mDiagnosticConnection.erase(clientAddress);
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"Connection terminated for clientAddress ",clientAddress);
#endif
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"serviceProcessingDone for terminated clientAddress ",clientAddress);
#endif
    }
    /// -# start S3 Timer after the request processing.
    startSessionTimer();
}

void CUdsCore::startSessionTimer(void)
{
    ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
    {
        std::lock_guard<std::mutex> guard ( mS3TimeoutMutex);
        mSessionTimer = mUdsCoreConfig.mS3TimecountInMs+ (nowTimeMs());
    }
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"session timer started with ",mSessionTimer);
#endif
}

void CUdsCore::stopSessionTimer(void)
{
    ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
    {
        std::lock_guard<std::mutex> guard ( mS3TimeoutMutex);
        mSessionTimer = 0U;
    }
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"session timer stopped mSessionTimer ",mSessionTimer);
#endif
}

void CUdsCore::sessionTimerProcessing(void)
{
    UdsTimeout DkMsgUdsTimeout; // DK runtime message structure for time-out notification
    if (mDiagnosticConnection.size() == 0U) /// assuming no ongoing services request processing
    {
        if(mSessionTimer>0U)
        {
            uint32_t lCurrentTimeStampMs = nowTimeMs();

            if (lCurrentTimeStampMs > mSessionTimer )
            {
                ///< Note : Critical Braces ensure mutex is destroyed after setting the  timer
                {
                    std::lock_guard<std::mutex> guard ( mS3TimeoutMutex);
                    mSessionTimer = 0U;
                }
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,"S3 time-out occurred . Session time-out message sent to UdsServices ");
#endif
                DkMsgUdsTimeout.clientAddress = 0xffffU;
                DkMsgUdsTimeout.timeoutType = static_cast<uint8_t>(EUdsTimeoutType_t::EUdsTimeoutType_SessionTimeout);
#ifdef DUAL_INSTANCE_POC
                if (mDiagnosticConnection.find(mUdsCoreConfig.mFtoolAddress) != mDiagnosticConnection.end())
                {
#ifdef UDSCORE_LOG_ENABLED
                    LOGD(&gUdsCoreLogContext,"Sending uds sesssion time out for ftool");
#endif
                    DK_RTE_Send_UdsTimeout(DkMsgUdsTimeout);
                }

                if((mDiagnosticConnection.find(mUdsCoreConfig.mDtoolAddress) != mDiagnosticConnection.end()) || (mDiagnosticConnection.find(mUdsCoreConfig.mRdiagAddress) != mDiagnosticConnection.end()))
                {
#ifdef UDSCORE_LOG_ENABLED
                    LOGD(&gUdsCoreLogContext,"Sending uds sesssion time out for dtool");
#endif
                    DK_RTE_Send_UdsTimeout_DTool(DkMsgUdsTimeout);


                }
#else
                DK_RTE_Send_UdsTimeout(DkMsgUdsTimeout);
#endif

                //	DkMsgUdsTimeout.clientAddress = 0xffffU;

            }
        }
    }
}

void CUdsCore::serviceTimeout(const uint16_t clientAddress)
{
    UdsTimeout DkMsgUdsTimeout; // DK runtime message structure for time-out notification
    CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
        /// updated negative response buffer.
        pConnetionStatus->mNegativeResponseBuffer[0] = 0x7fU;
        pConnetionStatus->mNegativeResponseBuffer[1] = pConnetionStatus->mCurrentServiceId;
        pConnetionStatus->mNegativeResponseBuffer[2] = 0x21U;

        /// notify upper layer
        DkMsgUdsTimeout.timeoutType = static_cast<uint8_t>(EUdsTimeoutType_t::EUdsTimeoutType_ServiceTimeout);
        DkMsgUdsTimeout.clientAddress = pConnetionStatus->mCurrentServiceId;
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"DkMsgUdsTimeout message sent for clientAddress ",clientAddress);
#endif
#ifdef DUAL_INSTANCE_POC
        if(clientAddress == mUdsCoreConfig.mFtoolAddress)//FTOOL_ADDR)
        {
            // printf("service timeout for ftool\n");
            DK_RTE_Send_UdsTimeout(DkMsgUdsTimeout);
        }
        else if ((clientAddress == mUdsCoreConfig.mDtoolAddress) || (clientAddress == mUdsCoreConfig.mRdiagAddress))//DTOOL_ADDR)
        {
            DK_RTE_Send_UdsTimeout_DTool(DkMsgUdsTimeout);
        }
        else
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext,"Unknown client address");
#endif
        }
#else

        DK_RTE_Send_UdsTimeout(DkMsgUdsTimeout);
#endif

#ifdef UDSCORE_LOG_ENABLED
        /// trigger response pending transmission.
        LOGD(&gUdsCoreLogContext,"P2 time-out occurred . NRC 0x78 response sending initiated for clientAddress ",
             clientAddress);
#endif
        updateResponse(EResponse_Negative,clientAddress,static_cast<uint16_t>(3U),
                       &pConnetionStatus->mNegativeResponseBuffer[0]);
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"serviceTimeout invoked for terminated connection.",clientAddress);
#endif
    }

}

void CUdsCore::sendResponsePending(const uint16_t clientAddress)
{
    CUdsCore::SConnectionStatus_t* const pConnetionStatus = getConnectionStatus(clientAddress);

    if(pConnetionStatus != nullptr)
    {
        pConnetionStatus->mNegativeResponseBuffer[0] = 0x7fU;
        pConnetionStatus->mNegativeResponseBuffer[1] = pConnetionStatus->mCurrentServiceId;
        pConnetionStatus->mNegativeResponseBuffer[2] = 0x78U;
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"P2 time-out occurred . NRC 0x78 response sending initiated for clientAddress ",
             clientAddress);
#endif
        pConnetionStatus->mResponsePendingTransmitStatus = true;
        /// trigger the transmission of response pending 0x78 NRC.
        if (mpTpInstance!= nullptr)
        {
            (void)mpTpInstance->transmitDataRequest(&pConnetionStatus->mNegativeResponseBuffer[0],3U,clientAddress);
        }
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,"sendResponsePending invoked for terminated connection. ",clientAddress);
#endif
    }
}

CUdsCore::SConnectionStatus_t* CUdsCore::getConnectionStatus(const uint16_t clientAddress)
{
    CUdsCore::SConnectionStatus_t* pConnetionStatus;
    if (mDiagnosticConnection.find(clientAddress) != mDiagnosticConnection.end())
    {
        pConnetionStatus = &mDiagnosticConnection[clientAddress];
#ifdef UDSCORE_LOG_ENABLED
        LOGV(&gUdsCoreLogContext,"Connection exists for clientAddress",clientAddress);
#endif
    }
    else
    {
        pConnetionStatus = nullptr;
#ifdef UDSCORE_LOG_ENABLED
        LOGV(&gUdsCoreLogContext,"Connection does not exits for clientAddress",clientAddress);
#endif
    }
    return pConnetionStatus;
}

uint32_t CUdsCore::nowTimeMs()
{
    return static_cast<uint32_t> ( std::chrono::steady_clock::now().time_since_epoch() / std::chrono::milliseconds ( 1U ) );
}

} // udscore
} // srvc
} // dk
