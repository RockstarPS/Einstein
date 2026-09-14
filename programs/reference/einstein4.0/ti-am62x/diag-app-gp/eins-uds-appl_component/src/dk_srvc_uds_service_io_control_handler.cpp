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

#include "dk_srvc_uds_service_io_control_handler.h"
// #include "doip_IO.h"
// #include "doip_dtc.h"
#include "udsmgr_doip_error.h"
// #include "udsmgr_doip_VipIf.h"
// #include "nissan_bl_uds_appl_persist_manager.h"


namespace dk
{
namespace app
{
namespace udsblservices
{
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

void CUdsServiceIOControlHandler::serviceInitialize(void)
{
    /// -# Configure IO control service properties #mIOControlServiceConfig.
    mIOControlServiceConfig.mIsFunctionalRequestSupported = false;
    mIOControlServiceConfig.mResponsePendingSupported = true ;
    mIOControlServiceConfig.mLengthCheckConditionType = \
            ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mIOControlServiceConfig.mServiceRequestLength = 4u;
    mIOControlServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession | ESessionMask_t::ESessionMask_DefaultSession;
    mIOControlServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mIOControlServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)\
    {IOControlRequestHandler(clientAddress, pRequestData,requestLength);};
    mIOControlServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress) {
        IOControlPostresponseHandler(clientAddress);
    } ;
    mIOControlServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) {
        IOControlResetHandler(clientAddress);
    } ;

    LOGD(
        &gUdsBlServicesLogContext,
        mInputOutputControlByIdentifierServiceId,
        " service register requested for mode ",
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
    );
    /// -# Add IO control service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler(
        CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
        mInputOutputControlByIdentifierServiceId,
        &mIOControlServiceConfig
    );


}

void CUdsServiceIOControlHandler::IOControlPostresponseHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext," IOControlPostresponseHandler Invoked ");
}

void CUdsServiceIOControlHandler::IOControlResetHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext," IOControlResetHandler Invoked ");
    // -# Initialize mIsIOResponsePending to false.
    // mCurrentIOStatus.mIsIOResponsePending = false;
}

void CUdsServiceIOControlHandler::IOControlRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)
{
    //uint8_t lDtcRequest = false;

    CUdsServiceHandlerIf::ESessionType_t currentSession; // current session
    CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel; // current security level
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_Last; // response status
    uint8_t index;  // configuration table index
    uint16_t did;   // requested DID value
    //EIOControlParameter_t IoCtlParameter ;
    uint8_t DidIndex = 0;

    /// -# Get Current session and security level.
    currentSession = mServiceManagerInstance.getCurrentSession();
    currentSecurityLevel = mServiceManagerInstance.getCurrentSecurityLevel();
    mClientAddress = clientAddress;

    LOGD(&gUdsBlServicesLogContext,
         " IOControlRequestHandler request received in session ", currentSession,
         " and in security level ", currentSecurityLevel, "ClientAddress :",clientAddress);


    if((requestLength >= 3U) && (pRequestData!= nullptr))
    {
        /// -# Get requested DID.
        did = ((static_cast<uint16_t>((static_cast<uint16_t>(pRequestData[0])) << 8U)) & 0xFF00U) | \
              ((static_cast<uint16_t>(pRequestData[1])) & 0x00FFU);

        /// @todo Implement optimized search algorithm for finding valid DID.

        /// -# Iterate over the configuration table to check whether the requested DID is supported.
        for(index=0U; index< sizeof(mDidIdConfig)/sizeof(mDidIdConfig[0]); index++)
        {
            if (mDidIdConfig[index].mDidId ==  did)
            {
                /// -# If supported update responseCode as NoError
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                DidIndex = index ;
                /// -# set the reference to the current sub function configuration
                // pDidConfiguration_t = &mWriteDidConfigurationTable[index];
                break;
            }

        }

        if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
        {
            responseCode = processIORequest(DidIndex,did,&pRequestData[2],(requestLength - 2));
        }
        else
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange ;
        }
    }
    else
    {
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
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
        mServiceManagerInstance.sendNegativeResponse(mClientAddress,responseCode);
    }


}

void CUdsServiceIOControlHandler::IOControlResponse(GipDiagResponse & msg)
{
    //CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status

    LOGI(&gUdsBlServicesLogContext,"DkMsgBlGipDiagResponse message received " );
    uint8_t index,DidIndex ;
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;

    if(static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {

        for(index=0U; index<sizeof(mDidIdConfig)/sizeof(mDidIdConfig[0]); index++)
        {
            if (mDidIdConfig[index].mDidId ==  msg.didId)
            {
                /// -# If supported update responseCode as NoError
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                DidIndex = index ;
                /// -# set the reference to the current sub function configuration
                // pDidConfiguration_t = &mWriteDidConfigurationTable[index];
                break;

            }
        }

        if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
        {
            responseCode = processIOResponse(DidIndex,msg.didId,msg.controlOp,msg.controlOpLen,msg.response,msg.responseLen) ;
        }

    }
    else
    {
        responseCode = static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) ;
    }

    if(responseCode !=  CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        mServiceManagerInstance.sendNegativeResponse(mClientAddress,responseCode);
    }


}

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceIOControlHandler::processIORequest
(
    uint8_t index,
    uint16_t DidId,
    const uint8_t * const pIOInfobuffer,
    uint16_t IOInfoLength
)
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode;
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
    EIOControlParameter_t Parameter ;
    uint16_t CtlStateLen = 0 ;

    // Total Length Check

    Parameter = static_cast<EIOControlParameter_t>(pIOInfobuffer[0]) ;
    IOInfoLength-- ;

    LOGD(&gUdsBlServicesLogContext,"Processing IO - IOIdx ",Parameter, "Length : ",IOInfoLength );
    /// -# If the requested IO is supported invoke corresponding method and get the status, else update response
    /// as RequestOutOfRange
    switch(Parameter)
    {

    case IOControlParameter_returnControlToECU:
    case IOControlParameter_resetToDefault:
    case IOControlParameter_freezeCurrentState:
        if(IOInfoLength == 0)
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
            CtlStateLen = IOInfoLength ;
        }
        else
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
        }

        break;

    case IOControlParameter_shortTermAdjustment:
        if(IOInfoLength == mDidIdConfig[index].mRequestStateLength)
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
            CtlStateLen = IOInfoLength ;
        }
        else
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
        }
        break;

    case IOControlParameter_Last:
    default:
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
        break;

    }

    /// -# return response code .
    if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError )
    {
        // Send the Request to application

        GipDiagRequest DiagRequest ;
        DiagRequest.serviceId = ESidType_IoCtrl ;
        DiagRequest.didId = DidId ;
        DiagRequest.controlOpLen = 1 ;
        DiagRequest.controlOp[0] = static_cast<uint8_t>(Parameter) ;
        if(CtlStateLen > 0 )
        {
            (void)memcpy(&DiagRequest.data[0], &pIOInfobuffer[1],CtlStateLen);
        }
        DiagRequest.dataLen = CtlStateLen ;

        DK_RTE_Send_GipDiagRequest(DiagRequest);

        LOGD(&gUdsBlServicesLogContext,"DiagRequest - Idx ",DidId, "Parame:",Parameter, "Length : ", CtlStateLen );

    }

    return responseCode;
}


CUdsServiceHandlerIf::EResponseCode_t CUdsServiceIOControlHandler::processIOResponse
(
    uint8_t index,
    uint16_t DidId,
    const uint8_t * const pIOCntrlOp,
    uint16_t IOCntrlOpLenth,
    const uint8_t * const pIOInfobuffer,
    uint16_t IOInfoLength
)

{
    std::vector<uint8_t> dataBuffer(static_cast<uint32_t>(IOInfoLength + IOCntrlOpLenth + 2));
    CUdsServiceManagerIf::EResponseType_t responseType ;
    responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Positive ;
    EIOControlParameter_t Parameter ;
    uint16_t CtlStateLen = 0 ;
    CUdsServiceHandlerIf::EResponseCode_t responseCode  = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;
    // Total Length Check

    Parameter = static_cast<EIOControlParameter_t>(pIOCntrlOp[0]) ;

    LOGD(&gUdsBlServicesLogContext,"Processing IO Repsonse - IOIdx ",Parameter, "Length : ",IOInfoLength );
    ///  -# If the requested IO is supported invoke corresponding method and get the status, else update response
    ///  as RequestOutOfRange
    switch(Parameter)
    {

    case IOControlParameter_returnControlToECU:
    case IOControlParameter_shortTermAdjustment:
    case IOControlParameter_resetToDefault:
    case IOControlParameter_freezeCurrentState:

        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        CtlStateLen = IOInfoLength ;

        break;
    case IOControlParameter_Last:
    default:
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;
        break;

    }

    if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        // DidId
        dataBuffer[0] = static_cast<uint8_t>((DidId >>8U) & 0x00ffU);
        dataBuffer[1] = static_cast<uint8_t>(DidId & 0x00ffU);
        dataBuffer[2] = static_cast<uint8_t> (Parameter) ;

        // Control Parameter
        if(CtlStateLen > 0 )
        {
            (void)memcpy(&dataBuffer[3],&pIOInfobuffer[0],CtlStateLen);
        }

        LOGD(&gUdsBlServicesLogContext,"IOControlResponse - ID  ",DidId, "Parameter ",
             Parameter, "Lenght ", CtlStateLen);
        mServiceManagerInstance.serviceResponseUpdate(mClientAddress,responseType,dataBuffer) ;
    }

    return responseCode ;
}


} // udsservices
} // app
} // dk
