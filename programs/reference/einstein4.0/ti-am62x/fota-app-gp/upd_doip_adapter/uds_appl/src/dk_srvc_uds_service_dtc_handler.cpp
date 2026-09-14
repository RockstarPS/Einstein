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
#include "dk_srvc_uds_service_dtc_handler.h"
#include "dk_srvc_uds_service_dtc_err.h"
#include <cstdlib>
#include "doip_dtc.h"
#include "uds_appl_persist_manager.h"
#include "Reflashhandle.hpp"

namespace dk
{
namespace app
{
namespace udsblservices
{

LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

void CUdsServiceDtcHandler::serviceInitialize(void)
{
    /// -# Configure Tester present service properties.
    mDtcReadServiceConfig.mIsFunctionalRequestSupported = false;
    mDtcReadServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mDtcReadServiceConfig.mServiceRequestLength = 2u;
    mDtcReadServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_AllSession;
    mDtcReadServiceConfig.mSupportedSecurityMask = ESecurityMask_AllLevel;
    mDtcReadServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)\
                                                     {dtcReadRequestHandler(clientAddress, pRequestData,requestLength);};
    mDtcReadServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress) {dtcReadPostresponseHandler(clientAddress);} ;
    mDtcReadServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) {dtcReadResetHandler(clientAddress);} ;
    
    LOGD(
        &gUdsBlServicesLogContext,
        mEcuResetServiceId,
        " service register requested for mode ",
		CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
        
    /// -# Add Tester present service configuration to Uds Service Manager. 
    mpServiceManagerInstance.addServiceHandler(
    											CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
												mReadDtcInformationServiceId,
                                                &mDtcReadServiceConfig
                                               );


}

void CUdsServiceDtcHandler::dtcReadResetHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext,"dtcReadResetHandler Invoked ");
}

void CUdsServiceDtcHandler::dtcReadPostresponseHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext,"dtcReadPostresponseHandler Invoked ");
}


void CUdsServiceDtcHandler::readDtcdiagTunnelCallback(void* instancePointer, uint8_t result)
{
	uint16_t mysize = 0;
	uint8_t* mybuff = NULL;

	CUdsServiceDtcHandler* self = reinterpret_cast<CUdsServiceDtcHandler*>(instancePointer);
	printf("DT: dtc callback called\n");

	if( ObjVipInstaller.DiagTunnelGetBuffer(&mybuff,&mysize) == eDiagTunnel_Rcvd )
	{
		if( diagTunnelNotification::EDiagTunnelResult_t::EDiagTunnelResult_Positive == result )
		{
			std::vector<uint8_t> dataBuffer;
			dataBuffer.insert(dataBuffer.end(), &mybuff[0], &mybuff[mysize]);
			self->mpServiceManagerInstance.serviceResponseUpdate(self->mClientAddress,
				CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
				dataBuffer
			);
		}
		else
		{	
			// return the error processed by vip
			self->mpServiceManagerInstance.sendNegativeResponse(self->mClientAddress,
				static_cast<CUdsServiceHandlerIf::EResponseCode_t>(mybuff[2])
			);
			printf("DT: DTC negative response returned by vip\n");
		}
	}
	else
	{
		printf("DT: DTC expected diag tunnel buffer to be received. State not expected\n");
		self->mpServiceManagerInstance.sendNegativeResponse(self->mClientAddress,
		   CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect
		);
	}
}

void CUdsServiceDtcHandler::dtcReadRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData,uint16_t requestLength)
{
	std::vector<uint8_t> subfunction(1u); // buffer to update response.
	std::vector<uint8_t> responseBuffer(14u); // buffer to update response.

    CUdsServiceHandlerIf::EResponseCode_t responseCode; //  response code.
    /// -# Set responseCode as NoError, Assuming sub function supported.
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
    LOGD(&gUdsBlServicesLogContext," DTC Read service request received requestLength:", requestLength);

	/// -# Get Sub function from the requested data.
	subfunction[0] = pRequestData[0];
	LOGD(&gUdsBlServicesLogContext," DTC Read service request Sub Function:", static_cast<uint32_t>(subfunction[0]));
    
	mClientAddress = clientAddress;

	/// read dids by diag tunnel
	diagTunnelNotification readdtcNotification(readDtcdiagTunnelCallback,this);

	if( ObjVipInstaller.DiagTunnelGetStatus() == eDiagTunnel_Idle )
	{
		ObjVipInstaller.DiagTunnelSend(
			CUdsServiceHandlerIf::mReadDtcInformationServiceId,
			pRequestData,
			requestLength,
			readdtcNotification
		);
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
	}
	else
	{
		printf("DT: trying to use Diag tunnel when is not available\n");
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
	}

	mpServiceManagerInstance.sendNegativeResponse(
		clientAddress,
		static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode)
	);
}

} // udsblservices
} // app
} // dk
