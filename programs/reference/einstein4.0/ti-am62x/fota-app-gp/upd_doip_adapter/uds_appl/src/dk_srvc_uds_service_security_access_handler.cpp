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
#include <cstdlib>
#include <ctime>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <unix.h>
#include <spawn.h>
#include <unistd.h>
//#include <openssl/rand.h>

#include "mbedtls/sha256.h"
#include "mbedtls/rsa.h"
//#include "mbedtls/pk.h"

#include "dk_runtime_uds_appl_component.h"
#include "dk_srvc_uds_service_security_access_handler.h"
#include "uds_appl_persist_manager.h"
#include "dk_bspal_trng.h"
#include "Reflashhandle.hpp"

using namespace std;

namespace dk
{
namespace app
{
namespace udsblservices
{

//static const char public_key_file[] = "/etc/2701_public_key.pem";

LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

bool CUdsServiceSecurityAccessHandler::mKeyUnlocked = false;

/**********************************************************************************************************/
/*********************** DIAG HARDENING IMPLEMENTATION START  *********************************************/
/**********************************************************************************************************/

#define DIAGHARDENING_VIRGIN_FLAG_READ_DID 0xF062
#define DIAGHARDENING_SERIAL_NUMB_READ_DID 0xF18C

#define DOIP_SEC_SECRETCOUNTER_SIZE		32

static uint8_t virgin_flag = 0xFF;

static uint8_t DoIPSecIncrementalCounter[32] = {0x00};
static uint8_t CounterValue[32];
static uint8_t DoIpSeedGenFlag = 0u;

static uint8_t FailCount[1];
static uint8_t DelayCount[1];
static uint8_t EcuSerialNum[20];

static uint16_t SecurityCouter = 0;
/* tlobao comment: Flag used to make the request synchronous. To be improved later */
#define VF_SYNC_STATUS_ONGOING 0u 
#define VF_SYNC_STATUS_FINISHED 1u

void CUdsServiceSecurityAccessHandler::diagHardeningOnStart(void)
{	

}

void CUdsServiceSecurityAccessHandler::diagHardeningInitializeVirginFlag(void)
{
	const uint8_t requestVirginFlag[2] = {0xF0 , 0x62};
	const uint16_t lengthReadDidRequest = 2;

	diagTunnelNotification diagHardeningNotification(diagHardeningdiagTunnelCallback,this);

	if( ObjVipInstaller.DiagTunnelGetStatus() != eDiagTunnel_Idle )
	{
		printf("DT: trying to use Diag tunnel when is not available\n");
		return;
	}


	ObjVipInstaller.DiagTunnelSend(
		CUdsServiceHandlerIf::mReadDataByIdentifierServiceId,
		requestVirginFlag,
		lengthReadDidRequest,
		diagHardeningNotification
	);

}

void CUdsServiceSecurityAccessHandler::diagHardeningdiagTunnelCallback(void* instancePointer, uint8_t result)
{
	uint16_t mysize = 0;
	uint8_t* mybuff = NULL;
	uint16_t did;

	CUdsServiceSecurityAccessHandler* self = reinterpret_cast<CUdsServiceSecurityAccessHandler*>(instancePointer);

	if( ObjVipInstaller.DiagTunnelGetBuffer(&mybuff,&mysize) != eDiagTunnel_Rcvd )
	{
		printf("DT: expected diag tunnel buffer to be received. State not expected. Diag harnening init NOT_OK\n");
		return;
	}
	if( diagTunnelNotification::EDiagTunnelResult_t::EDiagTunnelResult_Positive != result )
	{
		printf("DT: negative response returned by vip. Diag harnening init NOT_OK. Buffer Has %d %d %d %d\n",mysize, mybuff[0], mybuff[1], mybuff[2]);
		return;
	}

	did = ((static_cast<uint16_t>((static_cast<uint16_t>(mybuff[0])) << 8U)) & 0xFF00U) | \
		((static_cast<uint16_t>(mybuff[1])) & 0x00FFU);

	switch(did)
	{
		case DIAGHARDENING_VIRGIN_FLAG_READ_DID:

			virgin_flag = mybuff[2];

			//memcpy(&DoIPSecIncrementalCounter[0], &mybuff[3], 32);

			printf("DT: Diag hardening updated virgin_flag %d\n",virgin_flag);
			
			(void)self->processSeedRequest(self->mClientAddress, self->mRequestedSecurityLevel, self->msecuritySubFunction);

			break;
	}

}

/**********************************************************************************************************/
/*********************** DIAG HARDENING IMPLEMENTATION END  ***********************************************/
/**********************************************************************************************************/



void CUdsServiceSecurityAccessHandler::serviceInitialize(void)
{
	///-# Initialize Internal sates of CUdsServiceSecurityAccessHandler.
	
	mKeyUnlocked = false;
	mRequestedSecurityLevel = CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Default;
	mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;
	/// -# Configure security Access service properties.
	mSecurityAccessServiceConfig.mIsFunctionalRequestSupported = false;
	mSecurityAccessServiceConfig.mLengthCheckConditionType = ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
	mSecurityAccessServiceConfig.mServiceRequestLength = 2u;
	mSecurityAccessServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
	mSecurityAccessServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
	mSecurityAccessServiceConfig.mRequsestHandlerCbkFn =
			[=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)
			{	securityAccessRequestHandler(clientAddress, pRequestData,requestLength);};
	mSecurityAccessServiceConfig.mPostResponseHandlerCbkFn =
			[=](const uint16_t clientAddress)
			{	securityAccessPostresponseHandler(clientAddress);};
	mSecurityAccessServiceConfig.mResetServiceHandlerCbkFn =
			[=](const uint16_t clientAddress)
			{	resetSecurityAccess(clientAddress);};
	mpServiceManagerInstance.addServiceHandler(CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,mSecurityAccessServiceId, &mSecurityAccessServiceConfig);
	mVipResponsePending = false;
	mSeedRequestFlag = false;

	ObjVipInstaller.get_FailCount(FailCount);
	ObjVipInstaller.get_DelayCount(DelayCount);
}

///
/// @brief This method handles the post response functionality of tester present service.This method is
///         configured as post response handler callback  function for tester present service.
///
void CUdsServiceSecurityAccessHandler::securityAccessPostresponseHandler(const uint16_t clientAddress)
{
	LOGD(&gUdsBlServicesLogContext, " Post Response Handler Invoked ");
    /* Send Extended timing configuration for Write digest service: called next to this*/
    //updateCustomSessionTimerConfig(0x01);
}

///
/// @brief This method handles the SecurityAccess (0x27) service request . The method should be set as
///        request handler callback  function for SecurityAccess (0x27) service.This method updates positive
///        or negative response based on the request.
///
/// @param[in] pRequestData  pointer to request data length
/// @param[in] requestLength  size of the requested data.
///
void CUdsServiceSecurityAccessHandler::securityAccessRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData, uint16_t requestLength)
{
	CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported; // response status
	CUdsServiceHandlerIf::ESecurityLevel_t requsetedSecurityLevel = CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_L2; // requested security level
	CUdsServiceHandlerIf::ESessionType_t currentSession = mpServiceManagerInstance.getCurrentSession();
	CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel = mpServiceManagerInstance.getCurrentSecurityLevel();

	#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext, " security Access request received in session ", currentSession, " and in security level ", currentSecurityLevel);
	#endif

	/// -# Check for valid length , if the requested length is invalid then update response status as InvalidFormat.
	if ((requestLength > 0u) && (pRequestData))
	{
		/// -# Get security sub-function from the requested data.
		mRequestedSubFcn = pRequestData[0];

		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext," Get security sub-function from the requested data ", mRequestedSubFcn);
		#endif

		switch (mRequestedSubFcn)
		{
			case ESecurityAccessSubFunction_ReqSeed:
				if (1 != requestLength)
				{
					responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
				}
				else
				{
	
					// wait for the request to finish
					{
						printf("UDS: Init diagHardening VirginFlag\n");
						mSeedRequestFlag = true;

						if (FailCount[0] > mMaxRetries)
						{
							(void)printf("\n Fail count reached NRC 0x37");
							responseCode = EResponseCode_RequiredTimeDelayNotExpired;
							LOGD(&gUdsBlServicesLogContext,"Maximum attempt reached NRC Code ", responseCode);
							mpServiceManagerInstance.sendNegativeResponse(clientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
						}
						else
						{
							diagHardeningInitializeVirginFlag();
						}

						printf("UDS: VirginFlag is up to date\n");
					}
					mClientAddress = clientAddress;
					mRequestedSecurityLevel = requsetedSecurityLevel;
					msecuritySubFunction = mRequestedSubFcn;

					// need some time...
					responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
				}
				break;

			case ESecurityAccessSubFunction_SendKey:
				if( (mKeyLength + 1u ) != requestLength)
				{
					#ifdef UDSCFG_LOG_ENABLED
					LOGD(&gUdsBlServicesLogContext," request length ", requestLength);
					#endif
					responseCode = EResponseCode_IncorrectMessageLengthOrInvalidFormat;
				}
				else if(mSeedRequestFlag == false)
				{
					responseCode = EResponseCode_RequestSequenceError;

				}
				else
				{
					///< -# If the send Key sub function request is valid, process the request and update response.
					responseCode = processKeyRequest(clientAddress, &pRequestData[1], (requestLength - 1), (mRequestedSubFcn - 1));
					mSeedRequestFlag = false;
				}
				break;
		}
	}
	else // Invalid request length
	{
		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
	}

	if (responseCode != CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError)
	{
		/// -# If the request is not accepted , update mSecurityAccessState to WaitForSeed and send negative response.
		mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;
		LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", responseCode);
		mpServiceManagerInstance.sendNegativeResponse(clientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
	}
}

void CUdsServiceSecurityAccessHandler::resetSecurityAccess(const uint16_t clientAddress)
{
	mRequestedSecurityLevel = CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Default;
	mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;
	LOGI(&gUdsBlServicesLogContext," resetSecurityAccess Invoked . mRequestedSecurityLevel= ", mRequestedSecurityLevel, mSecurityAccessState,"Security level updated to ", mRequestedSecurityLevel);
	/// -# Update security level to default level.
	mpServiceManagerInstance.setCurrentSecurityLevel(mRequestedSecurityLevel);
    mVipResponsePending = false;
	mKeyUnlocked = false;
	mSeedRequestFlag = false;
}

///
/// @brief Read DID Response from VIP
/// @param[in] msg  pointer to  BlDiagResponse
///

void CUdsServiceSecurityAccessHandler::readDidResponseUpdateFrmVIP(BlDiagResponse & msg)
{
    if (mVipResponsePending == true)
    {
    	mVipResponsePending = false;

		switch(msg.didId)
		{
			case 0xF18C: ///< Check for ECU serial number
				prepareFormalSeedResponse(msg);
				break;

			case 0xF062: ///< check for virgin flag
				processSeedGen(msg);
				break;

			default:
				LOGE(&gUdsBlServicesLogContext, "Invalid DID Response received!");
				break;
		}
    }
    else
    {
		printf("**************** Ignoring invalid DID Response! ****************\n");
		LOGD(&gUdsBlServicesLogContext,"Ignore Invalid DID Response");
    }
}

///
/// @brief This method is used to generate seed
/// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
///
void CUdsServiceSecurityAccessHandler::processSeedGen(BlDiagResponse & msg)
{
	uint8_t lseed[256];
	int32_t ret = -1;
	std::vector<uint8_t> dataBuffer;
	CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status

   ///< check for virgin flag
	if((msg.responseLen == 2 ) && (msg.response[0] == 0u))
	{
		///< Dummy seed key processing
		ret = genDummySeed(lseed[0] , mSeedLength);

		if(ret == 0 )
		{
			///< Copy the encrypted Seed and send it to UDS stack
			std::copy(&lseed[0], &lseed[256], std::back_inserter(dataBuffer));
			mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;

			#ifdef UDSCFG_LOG_ENABLED
			LOGD(&gUdsBlServicesLogContext,"Read DID positive response updated for ",msg.didId);
			#endif

			mpServiceManagerInstance.serviceResponseUpdate(mClientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, dataBuffer);
		}
		else
		{
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_FailurePreventsExecutionOfRequestedAction;
			LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", responseCode);
			mpServiceManagerInstance.sendNegativeResponse(mClientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
		}
	}
	else if ((msg.responseLen == 2 ) && (msg.response[0] == 1u))
	{
		///< Formal Seed key processing
		ret = genFormalSeed();

		if(ret == 0 )
		{
			LOGI(&gUdsBlServicesLogContext, "Proces Seed : Response $F18C is pending ");
			mVipResponsePending = true;
		}
		else
		{
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_FailurePreventsExecutionOfRequestedAction;
			LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", responseCode);
			mpServiceManagerInstance.sendNegativeResponse(mClientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
		}
	}
	else
	{
		///<Node Code Required
	}
}

static inline unsigned long long rdtsc(void)
{
	unsigned long long ts;
#if defined(__i386__)
	asm volatile ("rdtsc" : "=A" (ts));	//asm volatile ("lfence; rdtsc" : "=A" (ts)); asm volatile ("rdtscp" : "=A" (ts) : : "ecx");
#elif defined(__x86_64__) || defined(__amd64__)
	unsigned long long low, high;
	asm volatile ("rdtsc" : "=a" (low), "=d" (high));
	ts = (high << 32) | low;
#elif defined(__aarch64__)
	asm volatile("mrs %0, cntvct_el0" : "=r" (ts));
#else
	// "sys/time.h" should be included...
	struct timeval tv;
	gettimeofday(&tv, 0);
	ts = (unsigned long long)tv.tv_sec*1000000+tv.tv_usec;
#endif
	return ts;
}

static inline unsigned long long hash64F(unsigned long long x)
{
	x ^= x >> 32;
	x *= 0xD6E8FEB86659FD93ULL;
	x ^= x >> 32;
	x *= 0xD6E8FEB86659FD93ULL;
	x ^= x >> 32;
	return x;
}

static inline unsigned long long hash64R(unsigned long long x)
{
	x ^= x >> 32;
	x *= 0xCFEE444D8B59A89BULL;
	x ^= x >> 32;
	x *= 0xCFEE444D8B59A89BULL;
	x ^= x >> 32;
	return x;
}

static int timer_based_rand(void *dummy, unsigned char *data, size_t size)
{
	(void)dummy;	// This is the context needed for some mbedtls functions!

	while (size > 0)
	{
		static unsigned long long buff[2];
		static unsigned int bytes_in_buff;
		const unsigned char *ptr = (unsigned char *) buff;

		if (size > bytes_in_buff)
		{
			if (bytes_in_buff > 0)
			{
				memcpy(data, &ptr[sizeof(buff) - bytes_in_buff], bytes_in_buff);
				data += bytes_in_buff;
				size -= bytes_in_buff;
			}
			buff[0] = hash64F(buff[0] + rdtsc());
			buff[1] = hash64R(buff[1] + rdtsc());
			bytes_in_buff = sizeof(buff);
		}
		else
		{
			memcpy(data, &ptr[sizeof(buff) - bytes_in_buff], size);
			bytes_in_buff -= size;
			size = 0;
		}
	}

	return 0;
}

static const unsigned char N[] =
{
#ifndef PRODUCTION_MODE
	0xCB, 0xEF, 0x67, 0x84, 0x43, 0xAF, 0xEF, 0x6C, 0x4B, 0xCD, 0x65, 0x63, 0x18, 0xFA, 0xB0, 0x6D,
	0x23, 0x0F, 0x63, 0xB7, 0xFE, 0xC9, 0x24, 0xDA, 0x47, 0xC4, 0x3D, 0x37, 0xDD, 0xE2, 0xFB, 0xE6,
	0xBF, 0x1B, 0xD0, 0xEA, 0x28, 0xE7, 0xB2, 0xEC, 0x4D, 0x44, 0x5C, 0xE5, 0xB4, 0x4A, 0x95, 0xF9,
	0xFC, 0x30, 0x6D, 0x6F, 0xB2, 0x0D, 0x52, 0xAA, 0xB4, 0x9D, 0xB3, 0x66, 0x32, 0x20, 0x87, 0xE4,
	0x60, 0xAF, 0x44, 0xBA, 0x26, 0x05, 0xB1, 0x9D, 0xEC, 0xA5, 0x5E, 0xCC, 0x4E, 0xE1, 0xBA, 0x33,
	0xE3, 0x75, 0xC3, 0x84, 0x24, 0xE5, 0x34, 0x0E, 0x4F, 0xE7, 0x16, 0x01, 0x25, 0x9B, 0x9E, 0x73,
	0x21, 0x80, 0xDB, 0x44, 0x49, 0x0D, 0xE3, 0xBF, 0xA0, 0x9A, 0xDF, 0x8E, 0x1E, 0x70, 0x83, 0x4F,
	0xE5, 0x4E, 0x43, 0xD6, 0x61, 0xF9, 0x34, 0xA7, 0xFE, 0x2E, 0xAC, 0xFF, 0x83, 0x26, 0x2F, 0x4B,
	0xC2, 0xB1, 0x50, 0xC9, 0x8B, 0x8E, 0x62, 0x78, 0x97, 0xF2, 0xA9, 0xA7, 0x22, 0x74, 0xA1, 0xB8,
	0x23, 0xBA, 0x06, 0xE8, 0x6D, 0x9F, 0x04, 0x58, 0x21, 0x68, 0x68, 0x2C, 0x1E, 0x8B, 0xF4, 0x5A,
	0xA5, 0x08, 0xED, 0x6A, 0x5B, 0x66, 0xA8, 0x30, 0xED, 0xEB, 0xE5, 0x2A, 0xF3, 0x15, 0x9C, 0x1B,
	0x40, 0xA4, 0xE2, 0x0D, 0x60, 0x45, 0x0A, 0x1F, 0x8D, 0x06, 0xA8, 0x21, 0xD7, 0xD7, 0x6D, 0x5D,
	0x4B, 0x90, 0xF2, 0xA7, 0x21, 0x3D, 0xF2, 0xB5, 0xD8, 0x2C, 0x18, 0x4F, 0xB1, 0x30, 0x57, 0x39,
	0x34, 0x4B, 0xE6, 0xCA, 0x7B, 0x98, 0x98, 0x36, 0x99, 0xF0, 0x1D, 0x10, 0x4A, 0x6A, 0xDE, 0x12,
	0x2B, 0xA6, 0x08, 0xAC, 0xB1, 0xE3, 0x1A, 0xED, 0xCB, 0x1C, 0xFC, 0x51, 0x44, 0xD6, 0x53, 0x45,
	0x0D, 0xEF, 0xB1, 0xB7, 0xF3, 0xF4, 0x1F, 0x16, 0x31, 0x03, 0x56, 0x4A, 0x64, 0x0D, 0x0C, 0x5F
#else
	0xBB, 0x93, 0x3C, 0x23, 0x62, 0xEC, 0x0E,
	0x93, 0xD9, 0xB7, 0xA1, 0x6C, 0x19, 0xDB, 0x99, 0x6F, 0x20, 0xD4, 0x4D, 0xC1, 0x54, 0x66, 0x1C,
	0xDC, 0x5C, 0x17, 0xFF, 0x1C, 0x8C, 0x72, 0x2B, 0x4D, 0xC2, 0x32, 0x73, 0x6F, 0xEB, 0xED, 0xE6,
	0x07, 0x11, 0xE0, 0x44, 0x15, 0x62, 0x1A, 0x2F, 0x3B, 0xBD, 0xC9, 0x03, 0xF1, 0x71, 0x49, 0xE6,
	0x5F, 0x95, 0xAF, 0x4C, 0xA0, 0x79, 0xFE, 0x30, 0xAD, 0x8B, 0xDC, 0xB8, 0x28, 0x35, 0xDC, 0x52,
	0xE9, 0x26, 0xA1, 0xB1, 0xE4, 0x5B, 0xB1, 0x63, 0x71, 0xF9, 0x54, 0xE8, 0x5E, 0x95, 0x59, 0xAC,
	0x89, 0xEB, 0xE0, 0x79, 0x43, 0xB9, 0x4B, 0x90, 0x2E, 0x2D, 0xF1, 0xFD, 0x91, 0x5E, 0x0C, 0x0C,
	0x42, 0xE3, 0x5B, 0x5F, 0xDA, 0x78, 0x9E, 0xE6, 0x4A, 0xC2, 0xC8, 0x65, 0x25, 0xBF, 0x04, 0x9F,
	0x47, 0x49, 0x7C, 0xF7, 0x14, 0x52, 0x1B, 0xE7, 0x4D, 0x2A, 0x87, 0x8B, 0xDD, 0x7E, 0xF3, 0x4C,
	0xAE, 0xCE, 0xFC, 0x1F, 0x1E, 0x8B, 0x84, 0xAC, 0x2B, 0x32, 0xF6, 0x85, 0xF4, 0x33, 0x12, 0x5B,
	0xA4, 0x7E, 0x22, 0x62, 0x79, 0xFD, 0x91, 0x06, 0x3C, 0x8C, 0xA1, 0x93, 0xA8, 0x3C, 0x5C, 0xD8,
	0xC2, 0x9B, 0xBB, 0xC6, 0x0A, 0xB1, 0x88, 0x09, 0x4A, 0xE8, 0x9D, 0xA6, 0x94, 0x8D, 0x68, 0xCC,
	0xA6, 0x17, 0x23, 0xFF, 0xF3, 0x9D, 0x4F, 0xB4, 0x24, 0x44, 0xD1, 0x2E, 0xE3, 0x54, 0x5A, 0xE0,
	0xEC, 0xA4, 0x62, 0xF8, 0x35, 0xD0, 0xAF, 0x60, 0x5A, 0x57, 0xF7, 0x37, 0xFD, 0x31, 0xC8, 0x77,
	0x56, 0xF1, 0xB0, 0x6F, 0x3D, 0xDE, 0xBA, 0xF2, 0x3F, 0x1C, 0xF1, 0x14, 0x48, 0xCA, 0x37, 0x1B,
	0x41, 0xB6, 0xEB, 0x2F, 0xAD, 0x9F, 0xB5, 0x21, 0x55, 0x6F, 0xFC, 0x08, 0xD8, 0x58, 0x6D, 0x59,
	0x4F, 0xF9, 0xA2, 0x1C, 0xE4, 0x58, 0x07, 0x07, 0x4D
#endif
};
static const unsigned char E[] =
{
	0x01, 0x00, 0x01
};

///
/// @brief This method handles the request seed sub function for the SecurityAccess (0x27) service of each security level.
///
/// @param[in] newSecurityLevel requested new security level
/// @param[in] securitySubFunction sub function value of the requested new security level
///

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceSecurityAccessHandler::processSeedRequest(const uint16_t clientAddress, CUdsServiceHandlerIf::ESecurityLevel_t newSecurityLevel, uint8_t securitySubFunction)
{

	if (virgin_flag != 0)
	{
		if(DoIpSeedGenFlag == 0u)
		{
			DoIpSeedGenFlag = 1u;

			DoIpSec_GenerateSecretSeed(mRandomSeed);
		}
		
		mbedtls_rsa_context ctx;
		mbedtls_rsa_init(&ctx, MBEDTLS_RSA_PKCS_V21, MBEDTLS_MD_SHA256);

		if (mbedtls_rsa_import_raw(&ctx, N, sizeof(N), 0, 0, 0, 0, 0, 0, E, sizeof(E)) == 0)
		{
			if (mbedtls_rsa_complete(&ctx) == 0)
			{
				int err = mbedtls_rsa_rsaes_oaep_encrypt(&ctx, timer_based_rand, 0, MBEDTLS_RSA_PUBLIC, 0, 0, sizeof(mRandomSeed), mRandomSeed, mEncryptedSeed);
				if (err == 0)
				{
					printf("RSA encryption: %02X %02X ... %02X %02X.\n", mEncryptedSeed[0], mEncryptedSeed[1], mEncryptedSeed[254], mEncryptedSeed[255]);
				}
				else
				{
					printf( "RSA encryption failed: %04X\n", -err);
				}
			}
			else
			{
				printf("Error completing RSA key!\n");
			}
		}
		else
		{
			printf("Error importing raw RSA key!\n");
		}

		mbedtls_rsa_free(&ctx);
	}
	else
	{
		for (unsigned int i = 0; i < sizeof(mEncryptedSeed); ++i) mEncryptedSeed[i] = 0xFF;
	}

	std::vector<uint8_t> dataBuffer;

	dataBuffer.push_back(securitySubFunction);
	for (unsigned int i = 0; i < 256; ++i) dataBuffer.push_back(mEncryptedSeed[i]);
	mClientAddress = clientAddress;
	mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;
	mRequestedSecurityLevel = newSecurityLevel;
	msecuritySubFunction = securitySubFunction;
	mVipResponsePending = false;

	mpServiceManagerInstance.serviceResponseUpdate(clientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, dataBuffer);

	return CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;

}

uint8_t CUdsServiceSecurityAccessHandler::DoIpSec_GenerateSecretSeed(uint8_t *MsgBuff)
{
    uint8_t RetVal = 1u;

	ObjVipInstaller.get_ecuSerialNumber(EcuSerialNum);

    if (MsgBuff != NULL)
    {
        uint8_t RandomNumber[32];
        uint32_t Index = 0;

		memcpy(RandomNumber, DoIPSecIncrementalCounter, 32);

        memcpy(&MsgBuff[Index], RandomNumber, 32);
        Index += 32;
        RetVal = DoIpSec_ReadSecretCounter(RandomNumber, 32);
        if (RetVal == 0u)
        {
            memcpy(&MsgBuff[Index], RandomNumber, 32);
            Index += 32;
            RetVal = DoIpSec_WriteSecretCounter(RandomNumber, 32);
            if (RetVal == 0u)
            {
                MsgBuff[Index] = 0x01u;
                Index++;
                MsgBuff[Index] = 0x02u;
                Index++;
				memcpy(&MsgBuff[Index], EcuSerialNum, 10);
                Index += 10u;
				/* Copy default value (0x20) */
				for(uint8_t i = 0; i < 10u; i++)
				{
					MsgBuff[Index+i] = 0x20u;
				}
            }
        }
    }

    return RetVal;
}

void CUdsServiceSecurityAccessHandler::DoIpSec_ScrambleRandom(uint32_t *pScramble)
{
    uint8_t RandomNumber[32];

	memcpy(RandomNumber, DoIPSecIncrementalCounter, 32);

	/*take LSB 4 bytes*/
	(*pScramble)  = (uint32_t)RandomNumber[28];

	(*pScramble) <<= 24;

	(*pScramble) += (uint32_t)RandomNumber[29];

	(*pScramble) <<= 16;

	(*pScramble) += (uint32_t)RandomNumber[30];

	(*pScramble) <<= 8;

	(*pScramble) += (uint32_t)RandomNumber[31];

    /*max 50 iterations*/
    (*pScramble) %= (uint8_t)50;

    (*pScramble)++;

}

uint8_t CUdsServiceSecurityAccessHandler::DoIpSec_ReadSecretCounter(uint8_t *MsgBuff, uint16_t BuffSize)
{
    uint8_t RetVal = 1u;
    uint8_t Index;

    if( ( MsgBuff != NULL ) && ( BuffSize == DOIP_SEC_SECRETCOUNTER_SIZE ) )
    {
		memcpy(CounterValue, DoIPSecIncrementalCounter, 32);

        for(Index = 0; Index < 32; Index++)
        {
            MsgBuff[Index] = CounterValue[Index];
        }

        RetVal = DoIpSec_IsMaxValueNotReached(&MsgBuff[0], BuffSize);
    }

    return RetVal;
}

uint8_t CUdsServiceSecurityAccessHandler::DoIpSec_IsMaxValueNotReached(const uint8_t *MsgBuff, uint16_t CounterSize)
{
    uint8_t RetVal = 1u;
    uint16_t Index;

    for ( Index = 0; Index < CounterSize; Index++ )
    {
        if ( MsgBuff[Index] != 0xFF )
        {
            RetVal = 0u;
            break;
        }
    }

    return RetVal;
}

uint8_t CUdsServiceSecurityAccessHandler::DoIpSec_WriteSecretCounter(const uint8_t *MsgBuff, uint16_t BuffSize)
{
    uint8_t RetVal = 1u;
    int16_t Index;
    uint8_t Overflow = 1;

    if ( ( MsgBuff != NULL ) && ( BuffSize == DOIP_SEC_SECRETCOUNTER_SIZE ) )
    {
        RetVal = DoIpSec_IsMaxValueNotReached(&MsgBuff[0], BuffSize);

		if ( RetVal == 0u )
        {
            for(Index = 0; Index < 32; Index++)
            {
                CounterValue[Index] = MsgBuff[Index];
            }

            for ( Index = BuffSize-1; Index >= 0; Index-- )
            {
                if ( Overflow > 0 )
                {
                    if ( CounterValue[Index] < 0xFF )
                    {
                        CounterValue[Index] = CounterValue[Index]+1;
                        Overflow = 0;
                    }
                    else
                    {
                        CounterValue[Index] = 0x00;
                        Overflow = 1;
                    }
                }
            }

            RetVal = 0u;

			memcpy(DoIPSecIncrementalCounter, CounterValue, 32);

        }	
    }

    return RetVal;
}


bool CUdsServiceSecurityAccessHandler:: UDSStopDelayTimer(void)
{
    int32_t ret;

    if(-1 != timer_delete ( timer1000ms_ID ))
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}
void UDSTimerPerodicEvent(const int32_t signum)
{
	BlDiagRequest lBlDiagReq;
	lBlDiagReq.serviceId = 0x2EU;
	lBlDiagReq.didId = 0x2222U;
	lBlDiagReq.contrlOpLen = 0U;
	lBlDiagReq.dataLen = 1U;

	if (SecurityCouter < 61U){
			SecurityCouter++;
		}
	if (SecurityCouter >= 60U)
	{
		SecurityCouter = 0;

		if(DelayCount[0] != 0)
		{
			DelayCount[0] -= 1U;

			(void)printf("\n Delay Count : %d", DelayCount[0]);

			lBlDiagReq.data[0] = DelayCount[0];
			DK_RTE_Send_BlGipDiagRequest(lBlDiagReq);

			if(DelayCount[0] == 0)
			{
				FailCount[0] = 0;

				(void)printf("\n Fail Count : %d", FailCount[0]);
			}
		}
	}
}


bool CUdsServiceSecurityAccessHandler:: UDSStartDelayTimer(void)
{
    struct sigevent event;
    struct itimerspec itime;
    bool ret = false;

    if (SIG_ERR != signal(SIGUSR1, UDSTimerPerodicEvent))
    {
        ret = true;
    }
    if(true == ret)
    {
        SIGEV_SIGNAL_INIT (&event, SIGUSR1);
        if(-1 != timer_create (CLOCK_REALTIME, &event, &timer1000ms_ID))
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    if(true == ret)
    {
        itime.it_value.tv_sec = 1U;
        itime.it_value.tv_nsec = 0;
        itime.it_interval.tv_sec = 1U;
        itime.it_interval.tv_nsec = 0;

        if(-1 != timer_settime(timer1000ms_ID, 0, &itime, NULL))
        {
            ret = true;
        }
        else
        {
            ret = false;

        }
    }

    return ret;

}





///
/// @brief This method handles the verify key sub function for the SecurityAccess (0x27) service of each security level.
///
/// @param[in] pKeyDataBuffer pointer to received key data buffer
/// @param[in] keyDataLength  size of the received key data
/// @param[in] securitySubFunction sub function value of the requested  security level
///

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceSecurityAccessHandler::processKeyRequest(const uint16_t clientAddress, const uint8_t * const pKeyDataBuffer, uint16_t keyDataLength, uint8_t securitySubFunction)
{
	//uint8_t responseBuffer;
	std::vector<uint8_t> responseBuffer(1u); // buffer to update response.
	int keyVerificationStatus = -1;
	CUdsServiceHandlerIf::EResponseCode_t responseCode;

	DoIpSeedGenFlag = 0u;

	BlDiagRequest lBlDiagReq;
	lBlDiagReq.serviceId = 0x2EU;
	lBlDiagReq.didId = 0x1111U;
	lBlDiagReq.contrlOpLen = 0U;
	lBlDiagReq.dataLen = 1U;

	#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext, " Verify the received key for the security level  ",securitySubFunction);
	#endif

	if (virgin_flag != 0)
	{
		
		mbedtls_rsa_context ctx;
		mbedtls_rsa_init(&ctx, MBEDTLS_RSA_PKCS_V21, MBEDTLS_MD_SHA256);

		//mbedtls_rsa_set_padding(&ctx, MBEDTLS_RSA_PKCS_V21, MBEDTLS_MD_SHA256);
		if (mbedtls_rsa_import_raw(&ctx, N, sizeof(N), 0, 0, 0, 0, 0, 0, E, sizeof(E)) == 0)
		{
			if (mbedtls_rsa_complete(&ctx) == 0)
			{
				unsigned char hash[32];
				mbedtls_sha256_ret(mRandomSeed, sizeof(mRandomSeed), hash, 0);
				keyVerificationStatus = mbedtls_rsa_rsassa_pss_verify(&ctx, timer_based_rand, 0, 0, MBEDTLS_MD_SHA256, sizeof(hash), hash, pKeyDataBuffer);
			}
			else
			{
				printf("Error completing RSA key!\n");
			}
		}
		else
		{
			printf("Error importing raw RSA key!\n");
		}

		mbedtls_rsa_free(&ctx);
		
	}
	else
	{
		unsigned int i;

		for (i = 0; i < 256; ++i)
		{
			if (pKeyDataBuffer[i] != 0xFF)
			{
				break;
			}
		}

		if (i == 256)
		{
			keyVerificationStatus = 0;
		}
	}


	printf("RSA: signature verification returned %d.\n", keyVerificationStatus);

	if ((keyVerificationStatus == 0) && (mMaxRetriesReached == 0 ))
	{
		/// -# If Key verification success , then update sub function in response buffer.
		responseBuffer[0] = securitySubFunction +1;
		/// -# Update to New security level.
		mpServiceManagerInstance.setCurrentSecurityLevel(mRequestedSecurityLevel);
		/// -# Update security to wait for ESecurityAccessState_WaitForSeed to accept to new request.
		mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;

		LOGI(&gUdsBlServicesLogContext, " Security changed to level ", mRequestedSecurityLevel);

		mKeyUnlocked = true;

		/// Update positive response
		mpServiceManagerInstance.serviceResponseUpdate(clientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, responseBuffer);

		responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;

		FailCount[0] = 0;
		DelayCount[0] = 0;

		lBlDiagReq.data[0] = FailCount[0];
		DK_RTE_Send_BlGipDiagRequest(lBlDiagReq);

		(void)printf("\n Fail Count : %d", FailCount[0]);
		(void)printf("\n Delay Count : %d", DelayCount[0]);
	}
	else
	{
		FailCount[0] += 1U;
		/// -# If key verification failed Update response status as InvalidKey
		LOGD(&gUdsBlServicesLogContext, " Invalid key detected ", FailCount[0]);


		lBlDiagReq.data[0] = FailCount[0];
		DK_RTE_Send_BlGipDiagRequest(lBlDiagReq);
		
		LOGE(&gUdsBlServicesLogContext, "Send FailCount request to VIP!");

		(void)printf("\n Fail Count : %d", FailCount[0]);

        if (FailCount[0] > mMaxRetries)
        {            
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ExceedNumberOfAttempts;
			
			DelayCount[0] = 16U;
			
			(void)CUdsServiceSecurityAccessHandler:: UDSStartDelayTimer();
        }
		else
		{
			responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_InvalidKey;
			(void)CUdsServiceSecurityAccessHandler::UDSStopDelayTimer();
		}
		
	}

	/// -# Return response status
	return responseCode;
}

int32_t CUdsServiceSecurityAccessHandler::verifyKey( const uint8_t * const pKeyDataBuffer, uint16_t keyDataLength, uint8_t securitySubFunction)
{
	int32_t ret;
	FILE *fp;
	int32_t count;

	LOGI(&gUdsBlServicesLogContext, "Key length is :  ", keyDataLength);

	if( (fp = fopen("/tmp/encryptedKey.txt", "wb")) != NULL)
	{
		count = fwrite(pKeyDataBuffer, keyDataLength, 1, fp);
		if(1 == count)
		{
			LOGI(&gUdsBlServicesLogContext, "fwrite successful for /tmp/encryptedKey.txt");
			ret = 0;
		}
		else
		{
			LOGE(&gUdsBlServicesLogContext, "fwrite failed for /tmp/encryptedKey.txt!");
		}
		fclose(fp);
	}
	else
	{
		LOGE(&gUdsBlServicesLogContext, "fopen error for /tmp/keyDataLength.txt!");
	}

	ret = mCryptoRSA.verifySign("/tmp/rawSeed.txt", "/tmp/encryptedKey.txt", "sha256", "/etc/2701_public_key.pem", RSA_PADDING_PSS, 32);

	return ret;
}

/// @brief This method is used update dummy seed
/// @param[out] pSeed :  update the seed value
/// @param[in] length : size of the seed(bytes)
///
int32_t CUdsServiceSecurityAccessHandler::genFormalSeed( )
{
	dk::lib::meet::SJsonDataType lRDlyjsonData; ///< Json data
	int lSubFuncChk = 0;
	int8_t ret = -1;
	std::unique_ptr< dk::lib::meet::CjsonRWAccessor> mJsonRWHandlr;

	///< # Update sub-function in response buffer
	//responseBuffer[0] = securitySubFunction;
	///< Request seed
	///< #1 - PUN ( Random number)  0 - 32 bytes [0 -> 31]
	///< #2 - Counter ( Incremental counter) 32 - 64 bytes [32 -> 63 ]
	///< #3 - Security level   -- 1 byte [64]
	///< #4 - Session ID -- 1 byte  [65]
	///< #5 - ECU Serial number (DID : $F18C) -- 20 bytes [66 -- 85]
	///< ECU serial number is copied in response buffer
	///< request
   ///< clear seed response  buffer

	///< Read Random Number
	int32_t fd = TRNG_Open();

	if (fd == -1)
	{
		LOGE(&gUdsBlServicesLogContext, "Failed to open Ring oscillator for random num generation!");
	}
	else
	{
		int32_t rc = TRNG_Read(fd, mSeedRandomNumber , mRandomNumLen);
		if (rc == -1)
		{
			LOGE(&gUdsBlServicesLogContext, "Unable to read random Number!");
		}
		else
		{
			ret = 0;
			LOGV(&gUdsBlServicesLogContext, "Random number generated successfully!");
		}
	}

	///< Read Increment Counter
	if(ret == 0)
	{
		ret = -1;
		if ( mJsonRWPath.c_str() != nullptr )
		{
			mJsonRWHandlr.reset(new dk::lib::meet::CjsonRWAccessor(mJsonRWPath.c_str()));

			if (mJsonRWHandlr->jsonIsValid() == -1) ///< Check If filePath/file valid
			{
				///< if path is not valid, copy it from system path
				ifstream source(mJsonRWDefaultPath, ios::binary);
				ofstream dest(mJsonRWPath, ios::binary);
				istreambuf_iterator<char> begin_source(source);
				istreambuf_iterator<char> end_source;
				ostreambuf_iterator<char> begin_dest(dest);
				copy(begin_source, end_source, begin_dest);
				source.close();
				dest.close();

				mJsonRWHandlr.reset(new dk::lib::meet::CjsonRWAccessor(mJsonRWPath.c_str()));
				if (mJsonRWHandlr->jsonIsValid() == -1)
				{
					LOGE(&gUdsBlServicesLogContext, "No valid RW json file!");
				}
				else
				{
					ret = 0;
					LOGI(&gUdsBlServicesLogContext, "Json file Read from the path: ", mJsonRWPath);
				}
			}
			else
			{
				ret = 0;
			}
		}
	}

	///< save Increment Counter
	if(ret == 0)
	{
		ret = -1;

		///< Read the Seed KeyIncrement counter from the json file

		lSubFuncChk = mJsonRWHandlr->jsonGetValue("seedkeyCounter", lRDlyjsonData);
		if ( lSubFuncChk == 0 )
		{

			LOGV(&gUdsBlServicesLogContext, " Read the seed key counter  : ", "Size of the counter ",  +lRDlyjsonData.llData.size());

			uint8 index = 0;

			if (lRDlyjsonData.llData.size() == mSeedIncrementCntrLen)
			{

				for (auto it = lRDlyjsonData.llData.begin(); it < lRDlyjsonData.llData.end(); it++, index++)
				{
					mSeedIncrementCntr[index] = static_cast<uint8_t>(*it);
				}

				lSubFuncChk = update256bitInrementCounter(&mSeedIncrementCntr[0] ,mSeedIncrementCntrLen);
				if (lSubFuncChk == 0)
				{
					dk::lib::meet::SJsonDataType lRWjsonData; ///< Json data
					lRWjsonData.lenumType = dk::lib::meet::EJsonType_longInt;
					for (index = 0; index < mSeedIncrementCntrLen; index++)
					{
						lRWjsonData.llData.push_back(mSeedIncrementCntr[index]);
					}

					lSubFuncChk = mJsonRWHandlr->jsonSetValue ("seedkeyCounter", lRWjsonData);

					if (lSubFuncChk == 0)
					{
						ret = 0;
						LOGV(&gUdsBlServicesLogContext, "Increment counter saved to the json file ");

						///<Update the JSON file
						ret = mJsonRWHandlr->jsonSyncToStorage();

					}
					else
					{
						LOGE(&gUdsBlServicesLogContext, "Unable to save increment counter!");
					}
				}
				else
				{
					LOGE(&gUdsBlServicesLogContext, "Unable to compute increment counter!");
				}
			}
		}
	}

	if(ret == 0)
	{
		///< Request ECU serial number $F18C
		BlDiagRequest lDiagReqMsg;
		lDiagReqMsg.didId = 0xF18CU;
		lDiagReqMsg.contrlOpLen = 0x1U;
		lDiagReqMsg.controlOp[0] =0x1U;
		lDiagReqMsg.dataLen = 0x0U;
		DK_RTE_Send_BlGipDiagRequest(lDiagReqMsg);
		LOGE(&gUdsBlServicesLogContext, "Send $F18C request to VIP!");
	}

	// Always close fd after use, whether TRNG_Read succeeded or failed
	int32_t const close_rc = TRNG_Close(fd);
	if (close_rc == -1)
	{
		LOGE(&gUdsBlServicesLogContext, "Failed to close TRNG file descriptor!");
	}

	return ret;
}

///
/// @brief This method is to compute seed and sent the value in intended format
/// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
///
void CUdsServiceSecurityAccessHandler::prepareFormalSeedResponse(BlDiagResponse &msg)
{
    uint8_t lRandomSeed[86];
	CUdsServiceHandlerIf::ESessionType_t currentSession = mpServiceManagerInstance.getCurrentSession();	// Read current session
	CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel = mpServiceManagerInstance.getCurrentSecurityLevel();	// Read current security level
	int32_t ret = -1;
    std::vector<uint8_t> dataBuffer;
	//FILE *fp;

	dataBuffer.push_back(mRequestedSubFcn);

	LOGI(&gUdsBlServicesLogContext,"Package creation for seed-key pair");

	std::copy(mSeedRandomNumber, mSeedRandomNumber + mRandomNumLen , lRandomSeed);
	std::copy(mSeedIncrementCntr, mSeedIncrementCntr + mSeedIncrementCntrLen , &lRandomSeed[32]);

	lRandomSeed[64] = currentSecurityLevel;
	lRandomSeed[65] = currentSession;

	std::copy(msg.response, msg.response+20, &lRandomSeed[66]);

	// VMN:
	printf("**************** Random seed:");
	for (unsigned int i = 0; i < sizeof(lRandomSeed); ++i)
	{
		printf("%c%02X", i % 16 == 0 ? '\n' : ' ', lRandomSeed[i]);
	}
	printf("****************\n");

	int32_t x = mCryptoRSA.rsaEncrypt(lRandomSeed, sizeof(lRandomSeed), mEncryptedSeed, "/etc/2701_public_key.pem");
	if (x > 0)
	{
		ret = 0;

		printf("**************** Encrypted Random seed:");
		for (int i = 0; i < x; ++i)
		{
			printf("%c%02X", i % 16 == 0 ? '\n' : ' ', mEncryptedSeed[i]);
		}
		printf("****************\n");
	}
	else
	{
		printf("Encryption return: %d\n", x);
	}

/*
	///< Encryption -> RSA 1056 bit
    ///< write the generated seed in a file  and store in temp path
    ///< create a empty file for  storing the encrypted data
	fp = fopen("/tmp/RawSeed.txt", "wb");
	if (fp != NULL)
	{
		int32_t count = fwrite(static_cast<const void*>(&lRandomSeed[0]), mSeedKeyResponseLength, 1, fp);
		if(1 == count)
		{
			LOGI(&gUdsBlServicesLogContext, "fwrite successful for /tmp/RawSeed.txt");
			ret = 0;
			// VMN:
			printf("**************** Random seed written in '/tmp/RawSeed.txt'.\n");
		}
		else
		{
			LOGE(&gUdsBlServicesLogContext, "fwrite failed for /tmp/RawSeed.txt!");
		}

		fclose(fp);
	}
	else
	{
		LOGE(&gUdsBlServicesLogContext, "fopen error for /tmp/RawSeed.txt!");
	}

	if (ret == 0)
	{
		ret = -1;
		///< create a file
		int32_t lEncryptRSAChk = mCryptoRSA.rsaEncrypt("/tmp/RawSeed.txt", "/tmp/EncryptedRawSeed.txt", "/etc/2701_public_key.pem", RSA_PADDING_OAEP);

		if (lEncryptRSAChk == 0)
		{
			// VMN:
			printf("**************** Random seed encrypted in '/tmp/EncryptedRawSeed.txt'.\n");

			fp = fopen("/tmp/EncryptedRawSeed.txt", "rb");
			if (fp != NULL)
			{
				size_t lCnt = fread(mEncryptedSeed, sizeof(mEncryptedSeed) , 1, fp);
		    	LOGI(&gUdsBlServicesLogContext, "read Encrypted Seed length (in bytes ): ", +lCnt);

				if (lCnt != 0)
				{
					ret = 0;
					// VMN:
					printf("**************** Encrypted Random seed:\n");
					for (unsigned int i = 0; i < sizeof(mEncryptedSeed); ++i)
					{
						printf("%c%02X", i % 16 == 0 ? '\n' : ' ', mEncryptedSeed[i]);
					}
					printf("****************\n");
				}
				else
				{
					ret = -1;
					LOGE(&gUdsBlServicesLogContext, "read Encrypted Seed Failed!", lCnt);
				}

				fclose(fp);
			}
			else
			{
				LOGE(&gUdsBlServicesLogContext, "Unable to open encrypted raw seed!");
			}
		}
	}
	*/

	if (ret == 0)
	{
		std::copy(mEncryptedSeed, &mEncryptedSeed[256], std::back_inserter(dataBuffer));	// Copy the encrypted Seed and send it to UDS stack
		mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;

		#ifdef UDSCFG_LOG_ENABLED
		LOGD(&gUdsBlServicesLogContext,"Read DID positive response updated for ", msg.didId);
		#endif
		// If positive response received, then Update DID response data in response buffer.
		mpServiceManagerInstance.serviceResponseUpdate(mClientAddress, CUdsServiceManagerIf::EResponseType_t::EResponse_Positive, dataBuffer);
	}
	else
	{
    	CUdsServiceHandlerIf::EResponseCode_t responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_FailurePreventsExecutionOfRequestedAction;
		LOGD(&gUdsBlServicesLogContext, "Request not accepted because of NRC Code", responseCode);
		mpServiceManagerInstance.sendNegativeResponse(mClientAddress, responseCode);
	}
}

///
/// @brief This method is used to increment 256 bit seed key increment counter .
/// @param[in/out] pMsgBuff : Buffer to increment the counter
/// @param[in] pMsgBuff : Size of the buffer (in bytes).
/// @param[out] "-1" failed "0" success
///
int CUdsServiceSecurityAccessHandler::update256bitInrementCounter(uint8_t *pMsgBuff, uint16_t lBufSize)
{
  int  ret =  -1 ;
  int16_t index;
  uint8_t Overflow = 1;

  if((NULL != pMsgBuff) && (lBufSize == mSeedIncrementCntrLen))
  {
	ret = isMaxValueNotReached( pMsgBuff, lBufSize);
	if(ret == 0)
	{
	  LOGE(&gUdsBlServicesLogContext, "overflow!");

	  for(index = lBufSize-1; index >= 0; index--)
	  {
		if(Overflow > 0)
		{
		  if(pMsgBuff[index] < 0xFF)
		  {
			pMsgBuff[index] = pMsgBuff[index]+1;
			Overflow = 0;
		  }
		  else
		  {
			pMsgBuff[index] = 0x00;
			Overflow = 1;
		  }
		}
	  }
	  ret = 0;
	}
  }

	LOGE(&gUdsBlServicesLogContext,"After the overflow logic!");
	return ret;
}

///
/// @brief This method is used to inspect if max value reached.
/// @param[in/out] pMsgBuff : Buffer to increment the counter
/// @param[in] pMsgBuff : Size of the buffer (in bytes).
/// @param[out] "-1" failed "0" success
///
int CUdsServiceSecurityAccessHandler::isMaxValueNotReached(uint8_t *pMsgBuff, uint16_t lBufSize)
{
  int  ret =  -1 ;
  uint8_t index;

  for(index = 0; index < lBufSize; index++)
  {
    if(pMsgBuff[index] != 0xFF)
    {
      ret = 0x0;
      break;
    }
  }
  return ret;
}


///
/// @brief This method is to update/Compute Session Timer.
/// @param[in] eSrvctypeID : Service Type.
///
void CUdsServiceSecurityAccessHandler::updateCustomSessionTimerConfig(uint8_t eSrvctypeID )
{
	UdsServiceSetTimings dkMsgUdsServiceSetTimings;
	/// -# Update the P2 timing parameters.
	dkMsgUdsServiceSetTimings.p2TimeMs = mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2TimeMaxCountInMs;
	dkMsgUdsServiceSetTimings.p2StarTimeMs =mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMinCountInMs;
	dkMsgUdsServiceSetTimings.p4TimeMs =mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMaxCountInMs;
	#ifdef UDSCFG_LOG_ENABLED
	LOGD(
		&gUdsBlServicesLogContext,
		"Update UDS Timing parameters message sent for SrvcType ",
		static_cast<uint32_t>(eSrvctypeID),
		" mP2TimeMinCountInMs: ", mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2TimeMinCountInMs,
		" mP2TimeMaxCountInMs: ", mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2TimeMaxCountInMs,
		" mP2StarTimeMinCountInMs: ", mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMinCountInMs,
		" mP2StarTimeMaxCountInMs: ", mServiceSessionTimerConfig[eSrvctypeID].mTimingConfig.mP2StarTimeMaxCountInMs
		);
	#endif
	/// -# Send message to update the timing parameters for current session.
	DK_RTE_Send_UdsServiceSetTimings(dkMsgUdsServiceSetTimings);
}

/// @brief This method is used update dummy seed
/// @param[out] pSeed :  update the seed value
/// @param[in] length : size of the seed(bytes)
///
int32_t  CUdsServiceSecurityAccessHandler::genDummySeed(uint8_t &pSeed, uint16_t length)
{
	int32_t Ret = -1;

	if(length == mSeedLength)
	{
		std::memset(&pSeed, 0xFF, length);
		Ret = 0;
	}

	return  Ret;
}

int8_t CUdsServiceSecurityAccessHandler::verifySecurityAccess(void)
{
	int8_t ret = -1 ;

	if(CUdsServiceSecurityAccessHandler::mKeyUnlocked == true)
	{
		ret = 0;
	}

	return ret;

}

} // udsblservices
} // app
} // dk
