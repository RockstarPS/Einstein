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
#include "dk_srvc_uds_service_ecu_reset_handler.h"


//#include "udsmgr_doip_VipIf.h"
#include <cstdlib>

namespace dk
{
namespace app
{
namespace udsblservices
{

LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

void CUdsServiceEcuResetHandler::serviceInitialize(void)
{
    /// -# Configure Tester present service properties.
    mEcuResetServiceConfig.mIsFunctionalRequestSupported = false;
    mEcuResetServiceConfig.mLengthCheckConditionType = \
            ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mEcuResetServiceConfig.mServiceRequestLength = 2u;
    mEcuResetServiceConfig.mSupportedSessionMask = \
            (ESessionMask_t::ESessionMask_AllSession);
    mEcuResetServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mEcuResetServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)\
    {ecuResetRequestHandler(clientAddress, pRequestData,requestLength);};
    mEcuResetServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress) {
        ecuResetPostresponseHandler(clientAddress);
    } ;
    mEcuResetServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) {
        ecuResetResetHandler(clientAddress);
    } ;

    LOGD(
        &gUdsBlServicesLogContext,
        mEcuResetServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
    );
    /// -# Add Tester present service configuration to Uds Service Manager.
    mpServiceManagerInstance.addServiceHandler(
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
        mEcuResetServiceId,
        &mEcuResetServiceConfig
    );
}

void CUdsServiceEcuResetHandler::ecuResetResetHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext,"ecuResetResetHandler Invoked ");
}

void CUdsServiceEcuResetHandler::ecuResetPostresponseHandler(const uint16_t clientAddress)
{
    // Initiate Shut down process
    //std::string shutdownCmd = "shutdown -q";
    //system(shutdownCmd.c_str());
    // LOGD(&gUdsBlServicesLogContext,"ecuResetPostresponseHandler Invoked ");
    // if(mEcuResetFlag == 1)
    // {
    //     BlDiagRequest lBlDiagReq;

    //     lBlDiagReq.serviceId = ESidType_EcuReset;
    //     lBlDiagReq.didId = 0xffff; ///< not applicable
    //     lBlDiagReq.contrlOpLen = 0U;
    //     lBlDiagReq.dataLen = 0U;
    //     usleep(20000);
    //     DK_RTE_Send_BlGipDiagRequest(lBlDiagReq);
    // }

}

void CUdsServiceEcuResetHandler::ecuResetRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData,uint16_t requestLength)
{
    std::vector<uint8_t> subfunction(1u); // buffer to update response.
    //uint8_t subfunction;    // requested sub function
    CUdsServiceManagerIf::EResponseType_t responseType; //  response type.
    CUdsServiceHandlerIf::EResponseCode_t responseCode; //  response code.

    /// -# Set responseCode as NoError, Assuming sub function supported.
    mEcuResetFlag = 0;
    GipDiagRequest lDiagRequest;
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
    LOGD(&gUdsBlServicesLogContext," ECU Reset service request received ");
    mClientAddress = clientAddress;
    if (requestLength != mUdsEcuResetRequestLength)
    {
        /// -# If requested length not supported , update response as NRC InvalidFormat.
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
    }
    else
    {
        /// -# Get Sub function from the requested data.
        subfunction[0] = pRequestData[0];
        if(subfunction[0] == mUdsEcuResetSubFunction)
        {
            /// -# If the requested sub function supported , then update responseType as Positive.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        }
        else
        {
            /// -# If the sub function not supported , update response as NRC SubFunctionNotSupported.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;
        }
    }

    if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        ///-# If request not accepted then send negative response.
        LOGD(  &gUdsBlServicesLogContext, "Request not accepted because of NRC Code ",   responseCode  );
        mpServiceManagerInstance.sendNegativeResponse(clientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
    }
    else
    {
        mEcuResetFlag = 1;
        lDiagRequest.serviceId = 0x11;
        lDiagRequest.didId = 0xFFFF; //DID is not applicable for ecu reset service
        lDiagRequest.controlOp[0] = subfunction[0];
        lDiagRequest.dataLen =0x00;
        DK_RTE_Send_GipDiagRequest(lDiagRequest);
        ///-# If request not accepted then send positive response.
        LOGD(&gUdsBlServicesLogContext,"ECU reset positive response updated for sub function ",subfunction[0]);

        //send a reset request to VIP through UCL
        ///Doip_SendECUResetReq();
    }
}

void CUdsServiceEcuResetHandler::ecuResetResponseHandler(GipDiagResponse & msg)
{
    LOGI(&gUdsBlServicesLogContext,"DkMsgBlGipDiagResponse message received " );
    std::vector<uint8_t> subfunction(1u);
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;

    if(static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        if(msg.sid == ESidType_EcuReset )
        {
            subfunction[0] = msg.controlOp[0];
            mpServiceManagerInstance.serviceResponseUpdate(mClientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, subfunction);
        }
    }
    else
    {
        responseCode = static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) ;
    }

    if(responseCode !=  CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        mpServiceManagerInstance.sendNegativeResponse(mClientAddress,responseCode);
    }
}

} // udsblservices
} // app
} // dk
