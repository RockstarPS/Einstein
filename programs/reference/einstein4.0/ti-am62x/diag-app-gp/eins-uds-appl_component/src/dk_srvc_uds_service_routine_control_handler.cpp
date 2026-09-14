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

#include "dk_srvc_uds_service_routine_control_handler.h"
#include "dk_logger.h"

#define SIZE_OF_SIGNATURE						(0x180)
#define OTA_ACTIVATE_ROUTINE_ID					(0xFE00)
#define OTA_ROLLBACK_ROUTINE_ID					(0xFE01)
#define OTA_ACTIVATION_COMPLETE_ROUTINE_ID		(0xFE02)
#define OTA_SYNC_ROUTINE_ID						(0xFE03)
#define OTA_ERASE_ROUTINE_ID					(0xFF00)
#define OTA_VALIDATE_ROUTINE_ID					(0xFF01)


namespace dk
{
namespace app
{
namespace udsblservices
{

LOG_IMPORT_CONTEXT ( gUdsBlServicesLogContext );

void CUdsServiceRoutineControlHandler::serviceInitialize ( void )
{
    /// -# Configure Routine control service properties #mRoutineControlServiceConfig.
    mRoutineControlServiceConfig.mIsFunctionalRequestSupported = true;
	mRoutineControlServiceConfig.mResponsePendingSupported = true;
    mRoutineControlServiceConfig.mLengthCheckConditionType = \
            ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mRoutineControlServiceConfig.mServiceRequestLength = 4u;
    mRoutineControlServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mRoutineControlServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mRoutineControlServiceConfig.mRequsestHandlerCbkFn = [ = ] ( const uint16_t clientAddress, uint8_t const * pRequestData, const uint16_t requestLength ) \
    {routineControlRequestHandler ( clientAddress, pRequestData, requestLength );};
    mRoutineControlServiceConfig.mPostResponseHandlerCbkFn = [ = ] ( const uint16_t clientAddress )
    {
        routineControlPostresponseHandler ( clientAddress );
    } ;
    mRoutineControlServiceConfig.mResetServiceHandlerCbkFn = [ = ] ( const uint16_t clientAddress )
    {
        routineControlResetHandler ( clientAddress );
    } ;


    LOGD ( &gUdsBlServicesLogContext,  mDiagnosticSessionControlServiceId, " service register requested for mode ",
           CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds);
    /// -# Add Routine control service configuration to Uds Service Manager.
    mServiceManagerInstance.addServiceHandler ( CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
            mRoutineControlServiceId, &mRoutineControlServiceConfig );


}

void CUdsServiceRoutineControlHandler::routineControlPostresponseHandler ( const uint16_t clientAddress )
{

    LOGD ( &gUdsBlServicesLogContext, " routineControlPostresponseHandler Invoked " );
}

void CUdsServiceRoutineControlHandler::routineControlResetHandler ( const uint16_t clientAddress )
{

    LOGD ( &gUdsBlServicesLogContext, " routineControlResetHandler Invoked " );
    /// -# Initialize mIsRoutineResponsePending to false.
}

void CUdsServiceRoutineControlHandler::routineControlRequestHandler ( const uint16_t clientAddress, uint8_t const *pRequestData, const uint16_t requestLength )
{
    uint8_t index;  // index of the configuration table
    uint8_t requestedSubFunction;   // requested sub function
    uint16_t routineId; // requested routine ID
    CUdsServiceHandlerIf::ESessionType_t currentSession; // current session
    CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel; // current security level
    SRoutineIdConfig_t const *pRoutineControlServiceConfig; // reference to routine configuration
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_Last;; // response status
    std::vector<uint8_t> subfunction;    // requested sub function
	bool DownloadRequestStatus = false;
	DoIPDownloadRequest RoutineControlDownloadService;

    /// -# Get Current session and security level.
    currentSession       = mServiceManagerInstance.getCurrentSession();
    currentSecurityLevel = mServiceManagerInstance.getCurrentSecurityLevel();

    mClientAddress = clientAddress;

    LOGD ( &gUdsBlServicesLogContext,  " :routineControl request received in session ",currentSession,
           " and in security level ", currentSecurityLevel );

    /// -# Set response status as RequestOutOfRange, Assuming RID not supported.
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;

    /// -# If the request length is invalid ,then update response status as IncorrectMessageLength.
    if ( ( requestLength > 2u ) && ( pRequestData ) )
    {
        /// -# Get requested sub function from the requested data buffer.
        requestedSubFunction = pRequestData[0];
        /// -# Get routine ID from the requested data buffer.
        routineId = ( ( ( static_cast<uint16_t> ( pRequestData[1] ) ) << 8u ) & 0xFF00u ) | \
                    ( ( static_cast<uint16_t> ( pRequestData[2] ) ) & 0x00FFu );


        if ( requestedSubFunction >= ERoutinSunFunction_Last )
        {
            /// -# If the requested sub function not supported ,update response status SubFunctionNotSupported.
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;
        }
        else
        {
            /// @todo Implement optimized search algorithm for finding valid DID.
            /// -# Iterate over the configuration table to check whether the requested routine ID is supported.
            for ( index = 0u; index < sizeof(mRoutineIdConfig)/sizeof(mRoutineIdConfig[0]); index++ )
            {
                if ( mRoutineIdConfig[index].mRoutineId ==  routineId )
                {
                    /// -# If RID supported update responseCode as NoError
                    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                    pRoutineControlServiceConfig = &mRoutineIdConfig[index];
                    break;
                }
            }
        }

        if ( responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError )
        {
            if ( ( ( 1u << currentSession ) & ( pRoutineControlServiceConfig->mSupportedSessionMask ) ) == 0u )
            {
                /// -# If the requested RID not supported in current session,then update response status as
                /// RequestOutOfRange
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;

                LOGD ( &gUdsBlServicesLogContext, "Request not supported in current session " );

            }
            else if ( ( ( 1u << currentSecurityLevel ) & ( pRoutineControlServiceConfig->mSupportedSecurityMask ) ) == 0u )
            {
                /// -# If the requested RID not supported in current security level,then update response status as
                /// SecurityAccessDenied
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SecurityAccessDenied;
            }
            else if ( ( ( 1u << (requestedSubFunction - 1u) ) & ( pRoutineControlServiceConfig->mSupportedSubFunctionMask ) ) == 0u )
            {
                /// -# If the requested RID does not supported requested sub function,then update response status as
                /// SubFunctionNotSupported
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;
            }
            else
            {
                /// -# set the reference to the current RID configuration.
				switch(routineId)
				{
					case OTA_ACTIVATE_ROUTINE_ID:
					case OTA_ROLLBACK_ROUTINE_ID:
					case OTA_ACTIVATION_COMPLETE_ROUTINE_ID:
					case OTA_SYNC_ROUTINE_ID:
					{
						DownloadRequestStatus = true;
						break;
					}
					case OTA_ERASE_ROUTINE_ID:
					{
						arrayTo32BitValue(&pRequestData[3], &RoutineControlDownloadService.blkaddress);
						arrayTo32BitValue(&pRequestData[7], &RoutineControlDownloadService.blklength);

						DownloadRequestStatus = true;
						break;
					}
					case OTA_VALIDATE_ROUTINE_ID:
					{
						arrayTo32BitValue(&pRequestData[3], &RoutineControlDownloadService.blkaddress);
						arrayTo32BitValue(&pRequestData[7], &RoutineControlDownloadService.blklength);

						memcpy(RoutineControlDownloadService.data, &pRequestData[11], SIZE_OF_SIGNATURE);

						RoutineControlDownloadService.dataLen = SIZE_OF_SIGNATURE;

						DownloadRequestStatus = true;
						break;
					}
					default:
					{
						break;
					}
				}

				if(DownloadRequestStatus == true)
				{
					DownloadRequestStatus = false;

					RoutineControlDownloadService.serviceId		= routineId;
					//Send the Request to UpdAdapter for download services handling.

					DK_RTE_Send_DoIPDownloadRequest(RoutineControlDownloadService);
				}
				else	// Send the Request to application
				{
					GipDiagRequest DiagRequest ;
					DiagRequest.serviceId = ESidType_RoutineId ;
					DiagRequest.didId = routineId ;
					DiagRequest.controlOpLen = 1  ;
					DiagRequest.controlOp[0] = requestedSubFunction ;
					DiagRequest.dataLen =requestLength -3;

					if((requestLength -3) > 0 )
					{
						(void)memcpy(DiagRequest.data, &pRequestData[3], (requestLength -3));
					}

					DK_RTE_Send_GipDiagRequest(DiagRequest);
					LOGD(&gUdsBlServicesLogContext,"DiagRequest - Idx ",routineId, "sub type :",requestedSubFunction );
				}
            }
        }
    }
    else // Invalid format
    {

        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
    }

    if ( responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError )
    {
        ///-# If request not accepted then send negative response.

        LOGD ( &gUdsBlServicesLogContext, "Request not accepted because of NRC Code ", responseCode );
        mServiceManagerInstance.sendNegativeResponse ( clientAddress, responseCode );
    }

}


void CUdsServiceRoutineControlHandler::RoutineControlResponse(GipDiagResponse & msg)
{
    //CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status

    LOGI(&gUdsBlServicesLogContext,"DkMsgBlGipDiagResponse message received " );
    uint8_t index,DidIndex ;
    CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;

    if(static_cast<CUdsServiceHandlerIf::EResponseCode_t>(msg.responseCode) == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {

        for(index=0U; index<sizeof(mRoutineIdConfig)/sizeof(mRoutineIdConfig[0]); index++)
        {
            if (mRoutineIdConfig[index].mRoutineId ==  msg.didId)
            {
                responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
                DidIndex = index ;
                break;

            }
        }

        if(responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
        {
            responseCode = RoutineControlProcessResponse(DidIndex,msg.didId,msg.controlOp,msg.controlOpLen,msg.response,msg.responseLen) ;
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


CUdsServiceHandlerIf::EResponseCode_t CUdsServiceRoutineControlHandler::RoutineControlProcessResponse
(
    uint8_t index,
    uint16_t DidId,
    const uint8_t * const pIOCntrlbuffer,
    uint16_t IOCntrlLength,
    const uint8_t * const pIOInfobuffer,
    uint16_t IOInfoLength
)

{
    std::vector<uint8_t> dataBuffer(static_cast<uint32_t>(IOInfoLength + IOCntrlLength + 2));
    CUdsServiceManagerIf::EResponseType_t responseType ;
    responseType = CUdsServiceManagerIf::EResponseType_t::EResponse_Positive ;
    ERoutineSubFunction_t Parameter ;
    uint16_t CtlStateLen = IOInfoLength; // Received data length

    CUdsServiceHandlerIf::EResponseCode_t responseCode  = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;
    // Total Length Check

    Parameter = static_cast<ERoutineSubFunction_t>(pIOCntrlbuffer[0]) ;

    LOGD(&gUdsBlServicesLogContext,"Processing IO Repsonse - IOIdx ",Parameter, "Length : ",IOInfoLength );
    ///  -# If the requested IO is supported invoke corresponding method and get the status, else update response
    ///  as RequestOutOfRange
    switch(Parameter)
    {

    case ERoutineSubFunction_Start:
    case ERoutineSubFunction_Stop:
    case ERoutineSubFunction_Requestresult:

        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;

        break;

    default:
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect;
        break;

    }

    if (responseCode == CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
    {
        // DidId
        dataBuffer[0] = static_cast<uint8_t> (Parameter) ;
        dataBuffer[1] = static_cast<uint8_t>((DidId >>8U) & 0x00ffU);
        dataBuffer[2] = static_cast<uint8_t>(DidId & 0x00ffU);


        // Control Parameter
        if(CtlStateLen > 0 )
        {
            (void)memcpy(&dataBuffer[3],&pIOInfobuffer[0],CtlStateLen);
        }

        LOGD(&gUdsBlServicesLogContext,"IOControlResponse - ID  ",DidId, "Parameter ",Parameter, "Length ", CtlStateLen);
        mServiceManagerInstance.serviceResponseUpdate(mClientAddress,responseType,dataBuffer) ;
    }

    return responseCode ;
}

void CUdsServiceRoutineControlHandler::DownloadServiceResponseHandler(DoIPDownloadResponse const  & msg)
{
	std::vector<uint8_t> responseBuffer;
	CUdsServiceHandlerIf::EResponseCode_t responseCode  = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_GeneralProgrammingFailure;

	if(msg.result == 0x00)
	{
		responseBuffer.resize(3);

		responseBuffer[0] = static_cast<uint8_t>(ERoutineSubFunction_Start) ;
        responseBuffer[1] = static_cast<uint8_t>((msg.serviceId >>8U) & 0x00ffU);
        responseBuffer[2] = static_cast<uint8_t>(msg.serviceId & 0x00ffU);

		mServiceManagerInstance.serviceResponseUpdate(mClientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, responseBuffer);
	}
	else
	{
		mServiceManagerInstance.sendNegativeResponse(mClientAddress, responseCode);
	}
}

void CUdsServiceRoutineControlHandler::arrayTo32BitValue(uint8_t *const arr, uint32_t *value)
{
    // Ensure the array has at least 4 bytes
    if (arr != nullptr)
	{
        // Combine bytes into a 32-bit value (little-endian)
		*value = 0;
		*value |= (static_cast<uint32_t>(arr[3])) << 24;
		*value |= (static_cast<uint32_t>(arr[2])) << 16;
		*value |= (static_cast<uint32_t>(arr[1])) << 8;
		*value |= (static_cast<uint32_t>(arr[0])) << 0;
    }
}


}
}
}



