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
#include "doip_routine.h"
#include "doip_dtc.h"
#include "uds_mgr_doip_error.h"
#include "uds_appl_persist_manager.h"
#include "Reflashhandle.hpp"

namespace dk
{
namespace app
{
namespace udsblservices
{
LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

void CUdsServiceRoutineControlHandler::serviceInitialize(void)
{
    /// -# Configure Routine control service properties #mRoutineControlServiceConfig.
    mRoutineControlServiceConfig.mIsFunctionalRequestSupported = false;
    mRoutineControlServiceConfig.mResponsePendingSupported = true;
    mRoutineControlServiceConfig.mLengthCheckConditionType = \
                                                    ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mRoutineControlServiceConfig.mServiceRequestLength = 4u;
    mRoutineControlServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mRoutineControlServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mRoutineControlServiceConfig.mRequsestHandlerCbkFn = [=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)\
                                                     {routineControlRequestHandler(clientAddress, pRequestData,requestLength);};
    mRoutineControlServiceConfig.mPostResponseHandlerCbkFn = [=](const uint16_t clientAddress) {routineControlPostresponseHandler(clientAddress);} ;
    mRoutineControlServiceConfig.mResetServiceHandlerCbkFn = [=](const uint16_t clientAddress) {routineControlResetHandler(clientAddress);} ;

    LOGD(
        &gUdsBlServicesLogContext,
        mDiagnosticSessionControlServiceId,
        " service register requested for mode ",
		CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds
        );
    /// -# Add Routine control service configuration to Uds Service Manager.
    mpServiceManagerInstance.addServiceHandler(
    											CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,
                                                mRoutineControlServiceId,
                                                &mRoutineControlServiceConfig
                                               );

}

void CUdsServiceRoutineControlHandler::routineControlPostresponseHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext," routineControlPostresponseHandler Invoked ");
}

void CUdsServiceRoutineControlHandler::routineControlResetHandler(const uint16_t clientAddress)
{
    LOGD(&gUdsBlServicesLogContext," routineControlResetHandler Invoked ");
}

void CUdsServiceRoutineControlHandler::routineControlRequestHandler(const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)
{

	CUdsServiceHandlerIf::ESessionType_t currentSession; // current session
	CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel; // current security level
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
	uint16_t did;
	//uint16_t routineInfoLength; // routine Information length
	//uint8_t *routineInfobuffer; // routine Information buffer.
	//std::vector<uint8_t> responseBuffer(7U);

	currentSession = mpServiceManagerInstance.getCurrentSession();
	currentSecurityLevel = mpServiceManagerInstance.getCurrentSecurityLevel();

	LOGD(&gUdsBlServicesLogContext,
			" routineControlRequestHandler request received in session ", currentSession,
			" and in security level ", currentSecurityLevel);



	if( pRequestData != nullptr )
	{
		did = ((static_cast<uint16_t>((static_cast<uint16_t>(pRequestData[1])) << 8U)) & 0xFF00U) |
			((static_cast<uint16_t>(pRequestData[2])) & 0x00FFU);

		// Block with security access only read/write eeprom services
		switch(did)
		{
		case 0xF0FB:
		case 0xF0FA:
			if( mpServiceManagerInstance.isPermmitedBySecurityLevel(ESecurityMask_t::ESecurityMask_levelL2) )
				responseCode = EResponseCode_t::EResponseCode_NoError;
			else
				responseCode = EResponseCode_t::EResponseCode_SecurityAccessDenied;
			break;
		default:
			responseCode = EResponseCode_t::EResponseCode_NoError;
			break;
		}

		if(EResponseCode_t::EResponseCode_NoError == responseCode)
		{
			mClientAddress = clientAddress;

			/// routines by diag tunnel
			diagTunnelNotification routineReqNotification(routinediagTunnelCallback,this);

			if( ObjVipInstaller.DiagTunnelGetStatus() == eDiagTunnel_Idle )
			{
				ObjVipInstaller.DiagTunnelSend(
					CUdsServiceHandlerIf::mRoutineControlServiceId,
					pRequestData,
					requestLength,
					routineReqNotification
				);
				responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
			}
			else
			{
				printf("DT: trying to use Diag tunnel when is not available\n");
				responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestOutOfRange;
			}
		}
	}
	else // length check
	{
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
	}

	mpServiceManagerInstance.sendNegativeResponse(clientAddress, responseCode);

}


void CUdsServiceRoutineControlHandler::routinediagTunnelCallback(void* instancePointer, uint8_t result)
{
	uint16_t mysize = 0;
	uint8_t* mybuff = NULL;

	CUdsServiceRoutineControlHandler* self = reinterpret_cast<CUdsServiceRoutineControlHandler*>(instancePointer);
	//LOGD(&gUdsBlServicesLogContext,"DT: callback called w/instance: ", instancePointer);

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
			printf("DT: (Routine)negative response returned by vip\n");
		}
	}
	else
	{
		printf("DT: expected diag tunnel buffer to be received. State not expected\n");
		self->mpServiceManagerInstance.sendNegativeResponse(self->mClientAddress,
		   CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ConditionsNotCorrect
		);
	}
}

} // udsservices
} // app
} // dk
