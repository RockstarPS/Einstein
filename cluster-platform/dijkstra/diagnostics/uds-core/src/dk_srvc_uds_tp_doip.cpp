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
#include "dk_srvc_uds_tp_doip.h"

namespace dk
{
namespace srvc
{
namespace udscore
{

#ifdef UDSCORE_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsCoreLogContext);
#endif

void CUdsTpDoip::requestDataIndication
(
    const uint16_t doIpSA,
    const uint16_t doIpTA,
    const uint8_t doIpTAType,
    const uint8_t * const pMessageData,
    const uint16_t length,
    const uint8_t doIpResult
)
{
    bool validRequest = false; // Request status
    const CUdsCoreIf::ERequestType_t receievedRequestType = static_cast<CUdsCoreIf::ERequestType_t>(doIpTAType); // received request type.
#ifdef UDSCORE_LOG_ENABLED
    LOGD(
        &gUdsCoreLogContext,
        "Message received from DoIP",
        "doIpSA= ",
        doIpSA,
        "doIpTA= ",
        doIpTA,
        "doIpTAType = ",
        static_cast<uint32_t>(doIpTAType),
        "length = ",
        length,
        "doIpResult = ",
        doIpResult
    );
#endif
    /// -# Check if the requested Target address type is supported.
    if((receievedRequestType <  CUdsCoreIf::ERequestType_t::ERequestType_Last) && (length >0U))
    {
        /// -# if the Target address type is supported ,check for address Type.
        if(receievedRequestType ==  CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest)
        {
            /// -# If the requested address type is Physical request, set the validRequest flag .
            validRequest = true;
        }
        else
        {
            /// -# If the requested address type is a functional request, Check if the received data request is a
            /// tester present service with suppressed bit set.
            if ((pMessageData[0]==0x3EU)&&(pMessageData[1] == 0x80U) &&(length ==2U))
            {
                /// -# If the received data request is a tester present service with suppressed bit set , then
                ///  restart session timer.
#ifdef UDSCORE_LOG_ENABLED
                LOGD(&gUdsCoreLogContext,"Tester present message with Functional address and suppressed bit set");
#endif
                if (mpUdsCoreTpIf!=nullptr)
                {
                    mpUdsCoreTpIf->reStartSessionTimer();
                }
            }
            else
            {
                /// -# If the received data is not a tester present request ,set the validRequest flag to process
                /// the request.
                validRequest = true;
            }
        }
        /// -# If validRequest flag is set , it indicates a valid diagnostic message is received.
        if (validRequest != false)
        {
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext," Message received from DoIP - Notified to diagnostic layer");
#endif
            /// -# Notify the Diagnostic layer to indicate the reception of new request.
            if (mpUdsCoreTpIf!=nullptr)
            {
                (void)mpUdsCoreTpIf->requestIndication(pMessageData,length,receievedRequestType,doIpSA);
            }
        }
    }
    else
    {
#ifdef UDSCORE_LOG_ENABLED
        LOGD(&gUdsCoreLogContext,
             " Message received from DoIP - Invalid request type ",static_cast<uint32_t>(doIpTAType));
#endif
    }
}

uint8_t CUdsTpDoip::transmitDataRequest(const uint8_t * const pMessageData,const uint16_t length,const uint16_t clientAddress)
{
    uint8_t mTramsmitStatus; // Transmit request status
    std::vector<SUdsTpReceiveAddressConfig_t>::iterator tpAddressIterator;
    DoipDiagDataTransferRequest DkMsgDoipDataTransferRequest = {0}; // DK message structure for transmit request.
    CUdsCoreIf::ERequestType_t currentTargetAddressType = CUdsCoreIf::ERequestType_t::ERequestType_Last;

#ifdef UDSCORE_LOG_ENABLED
    LOGD(
        &gUdsCoreLogContext,
        "New response transmission request received .Transmit request details",
        "clientAddress = ",
        clientAddress,
        "length = ",
        length
    );
#endif

    /// find if the requested address is valid
    for(tpAddressIterator = mUdsTpDoipConfig.mUdsTpReceiveAddressConfig.begin();
            tpAddressIterator!=mUdsTpDoipConfig.mUdsTpReceiveAddressConfig.end();
            ++tpAddressIterator)
    {
        if (tpAddressIterator->mAddress == clientAddress)
        {
            currentTargetAddressType = tpAddressIterator->mAddressType;
#ifdef UDSCORE_LOG_ENABLED
            LOGD(&gUdsCoreLogContext," Valid address found ",clientAddress);
#endif
            break;
        }
    }

    /// Check for valid target address ,target address type and valid data request.
    if ((currentTargetAddressType < CUdsCoreIf::ERequestType_t::ERequestType_Last) && \
            (pMessageData != nullptr) && (length > 0U))
    {

#ifdef UDSCORE_LOG_ENABLED
    LOGD(
        &gUdsCoreLogContext,
        "clientAddress = ",
        clientAddress,
        "length = ",
        length,
        "pMessageData[0]",
        static_cast<uint32_t>(pMessageData[0]),
        "pMessageData[1]",
        static_cast<uint32_t>(pMessageData[1]),
        "pMessageData[2]",
        static_cast<uint32_t>(pMessageData[2])
    );
#endif
        ///  If the validity check Ok,then do the following,
        /// -# Set Diagnostic server source address .
        DkMsgDoipDataTransferRequest.sourceAddress = mUdsTpDoipConfig.mUdsTpSourceAddress;
        /// -# Set Diagnostic client source address.
        DkMsgDoipDataTransferRequest.targetAddress = clientAddress;
        /// -# Set Diagnostic Target address type.
        DkMsgDoipDataTransferRequest.targetAddressType = static_cast<uint8_t>(currentTargetAddressType);
        /// -# Copy the transmit data.
        (void)memcpy(&DkMsgDoipDataTransferRequest.data[0],pMessageData,static_cast<uint32_t>(length));
        /// -# set the transmit data length.
        DkMsgDoipDataTransferRequest.dataLen = length;

        DK_RTE_Send_DoipDiagDataTransferRequest(DkMsgDoipDataTransferRequest);

        /// Set transmit request status to true.
        mTramsmitStatus = true;
    }
    else
    {
        /// If the validity check not OK, Set transmit request status to false.
        mTramsmitStatus = false;
    }

#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext," mTramsmitStatus =",static_cast<uint32_t>(mTramsmitStatus));
#endif

    /// Return transmit status.
    return mTramsmitStatus;
}

void CUdsTpDoip::trasmitDataConfirmation(const uint16_t doIpSA,const uint16_t doIpTA,const uint8_t doIpTAType,const uint8_t doIpResult)
{
    ///  Notify the transmit status to the Diagnostic layer.
    bool status;
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext," Confirmation received doIpResult =",doIpResult);
#endif
    status = (doIpResult == 0U) ? true:false;
    if (mpUdsCoreTpIf!=nullptr)
    {
        mpUdsCoreTpIf->transmitConfirmation(status,doIpTA);
    }
}

void CUdsTpDoip::setUdsCoreIf(CUdsCoreIf * const pUdsCoreIf)
{
#ifdef UDSCORE_LOG_ENABLED
    LOGV(&gUdsCoreLogContext,"UdsCore instance set for UdsTpDoip");
#endif
    ///  Set the CUdsCore Interface instance to CUdsTpDoip instance.
    mpUdsCoreTpIf = pUdsCoreIf;
}

} // udscore
} // srvc
} // dk