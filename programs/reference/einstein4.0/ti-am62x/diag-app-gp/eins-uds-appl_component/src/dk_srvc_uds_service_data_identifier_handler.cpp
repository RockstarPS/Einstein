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
#include "dk_runtime_eins_uds_appl_component.h"
#include "dk_srvc_uds_service_data_identifier_handler.h"

namespace dk
{
namespace app
{
namespace udsblservices
{

#ifndef UDSCFG_LOG_ENABLED
#define UDSCFG_LOG_ENABLED
#endif

///<#ifdef UDSCFG_LOG_ENABLED
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);
///< #endif
void CUdsServiceDataIdentifierHandler::serviceInitialize(void)
{
    /// -# Configure Read data Identifier service properties.
    mReadDataIdentifierServiceConfig.mIsFunctionalRequestSupported = true;
    mReadDataIdentifierServiceConfig.mResponsePendingSupported = true;
    mReadDataIdentifierServiceConfig.mLengthCheckConditionType = \
            ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mReadDataIdentifierServiceConfig.mServiceRequestLength = 3U;
    mReadDataIdentifierServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mReadDataIdentifierServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mReadDataIdentifierServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
    {readDataIdentifierRequestHandler(clientAddress,pRequestData,requestLength);};
    mReadDataIdentifierServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
    {readDataIdentifierPostresponseHandler(clientAddress);} ;
    mReadDataIdentifierServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
    {readDataIdentifierResetHandler(clientAddress);} ;
    LOGD( &gUdsBlServicesLogContext,  mReadDataByIdentifierServiceId, " service register requested for mode ",
          CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds);
    /// -# Add Read data Identifier service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler( CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
            mReadDataByIdentifierServiceId, &mReadDataIdentifierServiceConfig   );

    /// -# Configure Read data Identifier service properties.
    mWriteDataIdentifierServiceConfig.mIsFunctionalRequestSupported = true;
    mWriteDataIdentifierServiceConfig.mResponsePendingSupported = true;
    mWriteDataIdentifierServiceConfig.mLengthCheckConditionType = \
            ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mWriteDataIdentifierServiceConfig.mServiceRequestLength = 3U;
    mWriteDataIdentifierServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mWriteDataIdentifierServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mWriteDataIdentifierServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
    {writeDataIdentifierRequestHandler(clientAddress,pRequestData,requestLength);};
    mWriteDataIdentifierServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
    {writeDataIdentifierPostresponseHandler(clientAddress);} ;
    mWriteDataIdentifierServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
    {writeDataIdentifierResetHandler(clientAddress);} ;

    LOGD(  &gUdsBlServicesLogContext, mReadDataByIdentifierServiceId, " service register requested for mode ",
           CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds  );
    /// -# Add Read data Identifier service configuration to Uds Service Manager.

    mServiceManagerInstance.addServiceHandler(  CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
            mWriteDataByIdentifierServiceId, &mWriteDataIdentifierServiceConfig  );

}

void CUdsServiceDataIdentifierHandler::readDataIdentifierRequestHandler( const uint16_t clientAddress,  const uint8_t *const pRequestData,
        const uint16_t requestLength )
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode = EResponseCode_RequestOutOfRange ; // response status.
    uint16_t did = 0xFFFFu;   // requested DID value
    GipDiagRequest lDiagRequest;
    uint8_t index;

    if((requestLength >= 2U) && (pRequestData!= nullptr))
    {
        ///<  Get requested DID.
        did = ((static_cast<uint16_t>((static_cast<uint16_t>(pRequestData[0])) << 8U)) & 0xFF00U) | \
              ((static_cast<uint16_t>(pRequestData[1])) & 0x00FFU);

        ///< Iterate over the configuration table to check whether the requested DID is supported.
        for(index=0U; index<sizeof(mDidConfigurationTable)/sizeof(mDidConfigurationTable[0]); index++)
        {
            if (mDidConfigurationTable[index].mDidId ==  did)
            {
                ///<  If supported update responseCode as NoError
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                break;
            }
        }

        if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
        {
            lDiagRequest.serviceId = 0x22;
            lDiagRequest.didId = did;
            lDiagRequest.controlOpLen = 0x0; ///< no control option for Read identifiers.
            lDiagRequest.dataLen =requestLength -2;

            if((requestLength -2) > 0 )
            {
                (void)memcpy(lDiagRequest.data,&pRequestData[2],(requestLength -2));
            }


            DK_RTE_Send_GipDiagRequest(lDiagRequest);
            mClientAddress = clientAddress;
        }
    }
    else
    {
        ///< If request not accepted then send negative response.
        LOGD(   &gUdsBlServicesLogContext, "Request not accepted because of NRC Code ", responseCode );
        mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
    }

}

void CUdsServiceDataIdentifierHandler::readDataIdentifierPostresponseHandler(const uint16_t clientAddress)
{
#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"readDataIdentifierPostresponseHandler Invoked ",clientAddress);
#endif
}

void CUdsServiceDataIdentifierHandler::readDataIdentifierResetHandler(const uint16_t clientAddress)
{

#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"readDataIdentifierResetHandler Invoked ",clientAddress);
#endif
}


void CUdsServiceDataIdentifierHandler::RWControlResponse(GipDiagResponse & msg)
{
    LOGI(&gUdsBlServicesLogContext,"DkMsgBlGipDiagResponse message received " );
    uint8_t index,DidIndex ;
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;

    if(static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        if(msg.sid == ESidType_ReadDid )
        {
            for(index=0U; index< sizeof(mDidConfigurationTable)/sizeof(mDidConfigurationTable[0]); index++)
            {
                if (mDidConfigurationTable[index].mDidId ==  msg.didId)
                {
                    ///< If supported update responseCode as NoError
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                    DidIndex = index ;
                    break;
                }
            }
            if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
            {
                processRWResponse(DidIndex,msg.didId,msg.response,msg.responseLen) ;
            }
        }
        else if(msg.sid == ESidType_WriteDid)
        {
            for(index=0U; index< sizeof(mWriteDidConfigurationTable)/sizeof(mWriteDidConfigurationTable[0]); index++)
            {
                if (mWriteDidConfigurationTable[index].mDidId ==  msg.didId)
                {
                    ///< If supported update responseCode as NoError
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                    DidIndex = index ;
                    break;
                }
            }
            if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
            {
                processRWResponse(DidIndex,msg.didId,msg.response,msg.responseLen) ;
            }
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


void CUdsServiceDataIdentifierHandler::processRWResponse( uint8_t index,uint16_t DidId, const uint8_t * const pRWInfobuffer,
        uint16_t RWInfoLength )

{
    std::vector<uint8_t> dataBuffer(static_cast<uint32_t>(RWInfoLength + 2));

    ///< DidId
    dataBuffer[0] = static_cast<uint8_t>((DidId >>8U) & 0x00ffU);
    dataBuffer[1] = static_cast<uint8_t>(DidId & 0x00ffU);

    LOGD(&gUdsBlServicesLogContext,"RWControlResponse - ID  ",DidId, "length ", RWInfoLength);

    ///< Control Parameter
    if(RWInfoLength > 0 )
    {
        (void)memcpy(&dataBuffer[2],&pRWInfobuffer[0],RWInfoLength);
    }

    mServiceManagerInstance.serviceResponseUpdate(mClientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,dataBuffer) ;

}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierRequestHandler( const uint16_t clientAddress, const uint8_t *const pRequestData,
        const uint16_t requestLength )
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode = EResponseCode_RequestOutOfRange ; // response status.
    uint16_t did = 0xFFFFu;   // requested DID value
    GipDiagRequest lDiagRequest;
    uint8_t index;

    if((requestLength >= 2U) && (pRequestData!= nullptr))
    {
        ///<  Get requested DID.
        did = ((static_cast<uint16_t>((static_cast<uint16_t>(pRequestData[0])) << 8U)) & 0xFF00U) | \
              ((static_cast<uint16_t>(pRequestData[1])) & 0x00FFU);
        ///< Iterate over the configuration table to check whether the requested DID is supported.
        for(index=0U; index<sizeof(mWriteDidConfigurationTable)/sizeof(mWriteDidConfigurationTable[0]); index++)
        {
            if (mWriteDidConfigurationTable[index].mDidId ==  did)
            {
                LOGD(   &gUdsBlServicesLogContext, "Requested DID ", did );
                ///<  If supported update responseCode as NoError
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                break;
            }
        }

        if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
        {
            lDiagRequest.serviceId = 0x2E;
            lDiagRequest.didId = did;
            lDiagRequest.controlOpLen = 0x0; ///< no control option for Read identifiers.
            lDiagRequest.dataLen =requestLength -2;

            if((requestLength -2) > 0 )
            {
                (void)memcpy(lDiagRequest.data,&pRequestData[2],(requestLength -2));
            }

            DK_RTE_Send_GipDiagRequest(lDiagRequest);
            mClientAddress = clientAddress;
        }
    }
    else
    {
        ///< If request not accepted then send negative response.
        LOGD(   &gUdsBlServicesLogContext, "Request not accepted because of NRC Code ", responseCode );
        mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);
    }
}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierPostresponseHandler(const uint16_t clientAddress)
{
#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"writeDataIdentifierPostresponseHandler Invoked  ",clientAddress);
#endif
}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierResetHandler(const uint16_t clientAddress)
{

#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext,"readDataIdentifierResetHandler Invoked ",clientAddress);
#endif
}


} // udsblservices
} // app
} // dk
