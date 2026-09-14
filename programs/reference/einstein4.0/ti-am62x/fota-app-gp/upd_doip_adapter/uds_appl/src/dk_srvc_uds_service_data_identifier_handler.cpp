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
#include "dk_runtime_uds_appl_component.h"
#include "dk_srvc_uds_service_data_identifier_handler.h"
#include "uds_appl_persist_manager.h"

#include <iostream>

//#include "UclSys.h"
//#include "UclDLCbk_Types.h"
#include "doip_ucl_hdlr.h"
#include "doip_dtc.h"
#include "Reflashhandle.hpp"

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
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		mReadDataByIdentifierServiceId,
		" service register requested for mode ",
		CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
		);
	#endif
	/// -# Add Read data Identifier service configuration to Uds Service Manager.
	mServiceManagerInstance.addServiceHandler(
												CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
												mReadDataByIdentifierServiceId,
												&mReadDataIdentifierServiceConfig
											   );

	/// -# Configure Read data Identifier service properties.
	mWriteDataIdentifierServiceConfig.mIsFunctionalRequestSupported = true;
	mWriteDataIdentifierServiceConfig.mResponsePendingSupported = true;
	mWriteDataIdentifierServiceConfig.mLengthCheckConditionType = \
													ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
	mWriteDataIdentifierServiceConfig.mServiceRequestLength = 3U;
	mWriteDataIdentifierServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
	mWriteDataIdentifierServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_levelL2;
	mWriteDataIdentifierServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,const uint16_t requestLength)\
														{writeDataIdentifierRequestHandler(clientAddress,pRequestData,requestLength);};
	mWriteDataIdentifierServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress)\
														{writeDataIdentifierPostresponseHandler(clientAddress);} ;
	mWriteDataIdentifierServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) \
														{writeDataIdentifierResetHandler(clientAddress);} ;

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		mReadDataByIdentifierServiceId,
		" service register requested for mode ",
		CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
		);
	#endif
	/// -# Add Read data Identifier service configuration to Uds Service Manager.
	mServiceManagerInstance.addServiceHandler(
												CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
												mWriteDataByIdentifierServiceId,
												&mWriteDataIdentifierServiceConfig
											   );


   /// -# Initialize status DID status variables
   currentRequestedDid = 0x000U;
}

void CUdsServiceDataIdentifierHandler::readDataIdentifierRequestHandler
(
const uint16_t clientAddress,
const uint8_t *const pRequestData,
const uint16_t requestLength
)
{
	CUdsServiceHandlerIf::ESessionType_t currentSession;	// current session type.
	CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel;	// current security level.
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.

	/// -# Get Current session and security level.
	currentSession	   = mServiceManagerInstance.getCurrentSession();
	currentSecurityLevel = mServiceManagerInstance.getCurrentSecurityLevel();

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		" readDataIdentifier request received in session ",
		currentSession ,
		" and in security level ",
		currentSecurityLevel
		);
	#endif
	/// -# Set responseCode as RequestOutOfRange, Assuming DID not supported.
	responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
	/// -# If the request length is invalid ,then update response as IncorrectMessageLength.
	if( pRequestData != nullptr )
	{
		diagTunnelNotification readDidNotification(dataIdentifierdiagTunnelCallback,this);

		if( ObjVipInstaller.DiagTunnelGetStatus() == eDiagTunnel_Idle )
		{
			mClientAddress = clientAddress;
			ObjVipInstaller.DiagTunnelSend(
				CUdsServiceHandlerIf::mReadDataByIdentifierServiceId,
				pRequestData,
				requestLength,
				readDidNotification
			);
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
		}
		else
		{
			printf("DT: trying to use Diag tunnel when is not available\n");
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
		}
	}
	else // length check
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
	currentRequestedDid = 0x000U;
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext,"readDataIdentifierResetHandler Invoked ",clientAddress);
	#endif
}


void CUdsServiceDataIdentifierHandler::dataIdentifierdiagTunnelCallback(void* instancePointer, uint8_t result)
{
	uint16_t mysize = 0;
	uint8_t* mybuff = NULL;

	CUdsServiceDataIdentifierHandler* self = reinterpret_cast<CUdsServiceDataIdentifierHandler*>(instancePointer);
	//LOGD(&gUdsBlServicesLogContext,"DT: callback called w/instance: ", instancePointer);

	if( ObjVipInstaller.DiagTunnelGetBuffer(&mybuff,&mysize) == eDiagTunnel_Rcvd )
	{
		if( diagTunnelNotification::EDiagTunnelResult_t::EDiagTunnelResult_Positive == result )
		{
			std::vector<uint8_t> dataBuffer;
			dataBuffer.insert(dataBuffer.end(), &mybuff[0], &mybuff[mysize]);
			self->mServiceManagerInstance.serviceResponseUpdate(self->mClientAddress,
				CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
				dataBuffer
			);
		}
		else
		{	
			// return the error processed by vip
			self->mServiceManagerInstance.sendNegativeResponse(self->mClientAddress,
				static_cast<CUdsServiceHandlerIf::EResponseCode_t>(mybuff[2])
			);
			printf("DT: negative response returned by vip\n");
		}
	}
	else
	{
		printf("DT: expected diag tunnel buffer to be received. State not expected\n");
		self->mServiceManagerInstance.sendNegativeResponse(self->mClientAddress,
		   CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect
		);
	}
}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierRequestHandler
(
const uint16_t clientAddress,
const uint8_t *const pRequestData,
const uint16_t requestLength
)
{
	CUdsServiceHandlerIf::ESessionType_t currentSession;	// current session type.
	CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel;	// current security level.
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.
	/// -# Get Current session and security level.
	currentSession	   = mServiceManagerInstance.getCurrentSession();
	currentSecurityLevel = mServiceManagerInstance.getCurrentSecurityLevel();

	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		" WriteDataIdentifier request received in session ",
		currentSession ,
		" and in security level ",
		currentSecurityLevel  ,
		" requestLength ",
		requestLength
		);
	#endif

	/// -# If the request length is invalid ,then update response as IncorrectMessageLength.
	if((requestLength >= 2U) && (pRequestData!= nullptr))
	{
		diagTunnelNotification writeDidNotification(dataIdentifierdiagTunnelCallback,this);

		if( ObjVipInstaller.DiagTunnelGetStatus() == eDiagTunnel_Idle )
		{
			mClientAddress = clientAddress;
			ObjVipInstaller.DiagTunnelSend(
				CUdsServiceHandlerIf::mWriteDataByIdentifierServiceId,
				pRequestData,
				requestLength,
				writeDidNotification
			);
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
		}
		else
		{
			printf("DT: trying to use Diag tunnel when is not available\n");
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
		}
	}
	else // length check
	{
		printf("UDS Write: Invalid format\n");
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
	}

	mServiceManagerInstance.sendNegativeResponse(clientAddress,responseCode);

}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierPostresponseHandler(const uint16_t clientAddress)
{
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext,"writeDataIdentifierPostresponseHandler Invoked  ",clientAddress);
	#endif
}

void CUdsServiceDataIdentifierHandler::writeDataIdentifierResetHandler(const uint16_t clientAddress)
{
	currentRequestedDid = 0x0000U;
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(&gUdsBlServicesLogContext,"writeDataIdentifierPostresponseHandler Invoked ",clientAddress);
	#endif
}



} // udsblservices
} // app
} // dk
