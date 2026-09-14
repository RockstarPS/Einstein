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
#include<ctime>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "dk_runtime_nissan_bl_uds_appl_component.h"
#include "dk_srvc_uds_service_security_access_handler.h"
#include "nissan_bl_uds_appl_persist_manager.h"
#include "dk_bspal_trng.h"
#include <unix.h>
#include <spawn.h>
#include<unistd.h>



using namespace std;

namespace dk
{
namespace app
{
namespace udsblservices
{

LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);

bool CUdsServiceSecurityAccessHandler::mKeyUnlocked = false ;



void CUdsServiceSecurityAccessHandler::serviceInitialize(void)
{


    Scounter_t keyCounter;

    if (CUdsPersistManager::loadGipIntegrityChkStatus_counter(keyCounter ) == 0)
    {
        keyCounter.delayCounter = 0;
        keyCounter.attemptCounter1 = 0;
        keyCounter.attemptCounter2 = 0;

        (void)CUdsPersistManager::saveGipIntegrityChkStatus_counter(keyCounter);
        CUdsServiceSecurityAccessHandler:: UDSStopDelayTimer();
    }
    else if (keyCounter.delayCounter !=0 && keyCounter.delayCounter < CUdsServiceSecurityAccessHandler:: mDelayCounterInSec || keyCounter.attemptCounter1 > 9)
    {
        mMaxRetriesReached = 1;
        CUdsServiceSecurityAccessHandler:: UDSStartDelayTimer();
    }

    ///-# Initialize Internal sates of CUdsServiceSecurityAccessHandler.
    CUdsServiceSecurityAccessHandler::mKeyUnlocked = false ;
    mRequestedSecurityLevel =CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Default;
    mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;
    /// -# Configure security Access service properties.
    mSecurityAccessServiceConfig.mIsFunctionalRequestSupported = false;
    mSecurityAccessServiceConfig.mLengthCheckConditionType = ELengthCheckConditionType_t::ELengthCheckCondition_GreaterOrEqual;
    mSecurityAccessServiceConfig.mServiceRequestLength = 2u;
    mSecurityAccessServiceConfig.mSupportedSessionMask = ESessionMask_t::ESessionMask_FotaSession;
    mSecurityAccessServiceConfig.mSupportedSecurityMask = ESecurityMask_t::ESecurityMask_AllLevel;
    mSecurityAccessServiceConfig.mRequsestHandlerCbkFn =
        [=](const uint16_t clientAddress,const uint8_t *const pRequestData,uint16_t requestLength)
    {
        securityAccessRequestHandler(clientAddress, pRequestData,requestLength);
    };
    mSecurityAccessServiceConfig.mPostResponseHandlerCbkFn =
    [=](const uint16_t clientAddress) {
        securityAccessPostresponseHandler(clientAddress);
    };
    mSecurityAccessServiceConfig.mResetServiceHandlerCbkFn =
    [=](const uint16_t clientAddress) {
        resetSecurityAccess(clientAddress);
    };
    mpServiceManagerInstance.addServiceHandler(CUdsServiceManagerIf::EServiceTableId_t::EServiceTableId_Uds,mSecurityAccessServiceId,  												&mSecurityAccessServiceConfig);
    mVipResponsePending =false;
    mSeedRequestFlag = false;
    mDummySeedFlag = false;
    CUdsServiceSecurityAccessHandler::mKeyUnlocked = false;
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
void CUdsServiceSecurityAccessHandler::securityAccessRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData,
        uint16_t requestLength)
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status
    CUdsServiceHandlerIf::ESecurityLevel_t requsetedSecurityLevel; // requested security level
    //CUdsServiceHandlerIf::ESessionType_t currentSession;    // current session
    //CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel; // current security level

    ///-# Get current session and security level.
    //currentSession = mpServiceManagerInstance.getCurrentSession();
    requsetedSecurityLevel = mpServiceManagerInstance.getCurrentSecurityLevel();
    //requsetedSecurityLevel = currentSecurityLevel;


#ifdef UDSCFG_LOG_ENABLED
    /*LOGD(&gUdsBlServicesLogContext,
    		" security Access request received in session ", currentSession,
    		" and in security level ", currentSecurityLevel);*/
#endif

    ///< -# Set responseCode as SubFunctionNotSupported, assuming sub function not supported.
    responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_SubFunctionNotSupported;

    /// -# Check for valid length , if the requested length is invalid then update response status as InvalidFormat.
    if ((requestLength > 0u) && (pRequestData))
    {
        /// -# Get security sub-function from the requested data.
        mRequestedSubFcn = pRequestData[0];


#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext," Get security sub-function from the requested data ", mRequestedSubFcn);
#endif


        Scounter_t keyCounter;

        CUdsPersistManager::loadGipIntegrityChkStatus_counter(keyCounter );


        if (keyCounter.delayCounter == 0)
            mMaxRetriesReached = 0;


        switch (mRequestedSubFcn)
        {
        case ESecurityAccessSubFunction_ReqSeed:

            if (1 != requestLength)
            {
                responseCode =CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_IncorrectMessageLengthOrInvalidFormat;
            }
            else
            {
                /// -# If requestSeed sub-function request is valid , process the request and update response .

                mSeedRequestFlag = true;
                if (mMaxRetriesReached != true)
                {
                    responseCode = processSeedRequest(clientAddress,requsetedSecurityLevel, mRequestedSubFcn);
                }
                else
                {
                    responseCode = EResponseCode_RequiredTimeDelayNotExpired;
                    LOGD(&gUdsBlServicesLogContext,"Maximum attempt reached NRC Code ", responseCode);
                    mpServiceManagerInstance.sendNegativeResponse(clientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
                }
            }
            break;

        case ESecurityAccessSubFunction_SendKey:

            if((mKeyLength + 1u ) != requestLength)
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
                ///< -# If the send Key sub function request is valid , process the request and update response.
                responseCode = processKeyRequest(clientAddress,&pRequestData[1], (requestLength - 1u),(mRequestedSubFcn - 1u));
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
    mRequestedSecurityLevel =CUdsServiceHandlerIf::ESecurityLevel_t::ESecurityLevel_Default;
    mSecurityAccessState =ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;
    LOGD(&gUdsBlServicesLogContext," resetSecurityAccess Invoked . mRequestedSecurityLevel= ",
         mRequestedSecurityLevel, mSecurityAccessState,"Security level updated to ", mRequestedSecurityLevel);
    /// -# Update security level to default level.
    mpServiceManagerInstance.setCurrentSecurityLevel(mRequestedSecurityLevel);
    mVipResponsePending =false;
    mKeyUnlocked = false;
    mSeedRequestFlag = false;
    mDummySeedFlag = false;
}



///
/// @brief Read DID Response from VIP
/// @param[in] msg  pointer to  BlDiagResponse
///

void CUdsServiceSecurityAccessHandler::readDidResponseUpdateFrmVIP(BlDiagResponse & msg )
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
            LOGE(&gUdsBlServicesLogContext,"Invalid DID Response received");
            break;
        }
    }
    else
    {
        LOGD(&gUdsBlServicesLogContext,"Ignore Invalid DID Response");
    }
}


///
/// @brief This method is used to generate seed
/// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
///
void CUdsServiceSecurityAccessHandler::processSeedGen(BlDiagResponse & msg )
{
    uint8_t lseed[256];
    int32_t ret = -1;
    std::vector<uint8_t> dataBuffer;
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status

    ///< check for virgin flag
    if((msg.responseLen == 1 ) && (msg.response[0] == 0u))
    {
        ///< Dummy seed key processing
        ret = genDummySeed( lseed[0], mSeedLength);

        if(ret == 0 )
        {
            ///< Copy the encrypted Seed and send it to UDS stack
            dataBuffer.push_back( mRequestedSubFcn);
            std::copy(&lseed[0], &lseed[256], std::back_inserter(dataBuffer));
            mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;
            mDummySeedFlag = true ;

#ifdef UDSCFG_LOG_ENABLED
            LOGD(&gUdsBlServicesLogContext,"Read DID positive response updated for ",msg.didId);
#endif

            mpServiceManagerInstance.serviceResponseUpdate(mClientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,dataBuffer );
        }
        else
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_FailurePreventsExecutionOfRequestedAction;
            LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", responseCode);
            mpServiceManagerInstance.sendNegativeResponse(mClientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
        }
    }
    else if ((msg.responseLen == 1 ) && (msg.response[0] != 0u))
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

///
/// @brief This method handles the request seed sub function for the SecurityAccess (0x27) service of each security
///         level.
///
/// @param[in] newSecurityLevel requested new security level
/// @param[in] securitySubFunction sub function value of the requested new security level
///

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceSecurityAccessHandler::processSeedRequest(const uint16_t clientAddress,
        CUdsServiceHandlerIf::ESecurityLevel_t newSecurityLevel,
        uint8_t securitySubFunction)
{
    CUdsServiceHandlerIf::EResponseCode_t responseCode;  // response status
    BlDiagRequest lDiagReqMsg;
    uint8 ldummySeed[256]= {0x0u};
    std::vector<uint8_t> dataBuffer;

    if(CUdsServiceSecurityAccessHandler::mKeyUnlocked  == false )
    {
        ///< check for virgin flag
        lDiagReqMsg.serviceId =0x2E;
        lDiagReqMsg.didId =0xf062;
        lDiagReqMsg.contrlOpLen = 0x1U;
        lDiagReqMsg.controlOp[0] =0x1U;
        lDiagReqMsg.dataLen = 0x0U;
        DK_RTE_Send_BlGipDiagRequest(lDiagReqMsg);
        mClientAddress = clientAddress;
        mRequestedSecuritylevel = newSecurityLevel;
        msecuritySubFunction = securitySubFunction;
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_RequestCorrectlyReceivedResponsePending;
        mVipResponsePending = true;
        LOGI(&gUdsBlServicesLogContext, "Virgin Flag requested from VIP : Response is pending ");
    }
    else
    {
        ///< Copy the encrypted Seed and send it to UDS stack
        dataBuffer.push_back( mRequestedSubFcn);
        std::copy(&ldummySeed[0], &ldummySeed[256], std::back_inserter(dataBuffer));
        //mRequestedSecurityLevel = newSecurityLevel;
        mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;
        mDummySeedFlag = true ;

#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Read DID positive response updated for ",lDiagReqMsg.didId);
#endif
        ///< -# If positive response received , then Update DID response data in response buffer.
        mpServiceManagerInstance.serviceResponseUpdate(mClientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,dataBuffer );
    }


    return responseCode;
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

    Scounter_t keyCounter;
    LOGD(&gUdsBlServicesLogContext, "Inside timer handler ");
    if (CUdsPersistManager::loadGipIntegrityChkStatus_counter(keyCounter ) == 0)
    {
        LOGD(&gUdsBlServicesLogContext, "Unable to fetch persistant data ");
    }

    if (keyCounter.delayCounter != 0)
    {
        keyCounter.delayCounter--;

        LOGD(&gUdsBlServicesLogContext, "timer Count value ", keyCounter.delayCounter);
    }
    else
    {
        keyCounter.attemptCounter1 = 0;
        keyCounter.attemptCounter2 = 0;
        keyCounter.delayCounter = 0;
    }
    (void)CUdsPersistManager::saveGipIntegrityChkStatus_counter(keyCounter);

    LOGD(&gUdsBlServicesLogContext, "timer Count value ", keyCounter.delayCounter);

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
/// @brief This method handles the verify key sub function for the SecurityAccess (0x27) service of each security
///         level.
///
/// @param[in] pKeyDataBuffer pointer to received key data buffer
/// @param[in] keyDataLength  size of the received key data
/// @param[in] securitySubFunction sub function value of the requested  security level
///

CUdsServiceHandlerIf::EResponseCode_t CUdsServiceSecurityAccessHandler::processKeyRequest(const uint16_t clientAddress, const uint8_t * const pKeyDataBuffer,
        uint16_t keyDataLength, uint8_t securitySubFunction)
{
    //uint8_t responseBuffer;
    std::vector<uint8_t> responseBuffer(1u); // buffer to update response.
    uint8_t keyVerificationStatus;
    CUdsServiceHandlerIf::EResponseCode_t responseCode;

#ifdef UDSCFG_LOG_ENABLED
    LOGD(&gUdsBlServicesLogContext, " Verify the received key for the security level  ",securitySubFunction);
#endif
    if( mDummySeedFlag == true)
    {
        keyVerificationStatus = 0x00u;
        mDummySeedFlag = false;
    }
    else
    {
        /// -# Verify the received key for the security level and update response status.
        keyVerificationStatus = verifyKey(pKeyDataBuffer, keyDataLength, securitySubFunction);
    }

    Scounter_t keyCounter;
    if (CUdsPersistManager::loadGipIntegrityChkStatus_counter(keyCounter ) == 0)
    {
        keyCounter.delayCounter = 0;
        keyCounter.attemptCounter1 = 0;
        keyCounter.attemptCounter2 = 0;

        (void)CUdsPersistManager::saveGipIntegrityChkStatus_counter(keyCounter);
    }

    LOGD(&gUdsBlServicesLogContext, "Init Count value ", keyCounter.attemptCounter1);



    if ((keyVerificationStatus == 0x00u) && (mMaxRetriesReached == 0 )) {
        /// -# Update to New security level.
        mpServiceManagerInstance.setCurrentSecurityLevel((CUdsServiceHandlerIf::ESecurityLevel_t)securitySubFunction);
        /// -# If Key verification success , then update sub function in response buffer.
        responseBuffer[0] = securitySubFunction +1;
        /// -# Update security to wait for ESecurityAccessState_WaitForSeed to accept to new request.
        mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForSeed;

        LOGD(&gUdsBlServicesLogContext, " Security changed to level ", securitySubFunction);


        mKeyUnlocked = true;

        /// Update positive response
        mpServiceManagerInstance.serviceResponseUpdate(clientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,
                responseBuffer);

        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_NoError;
        keyCounter.attemptCounter1 = 0;


    }
    else
    {
        keyCounter.attemptCounter1++;

        /// -# If key verification failed Update response status as InvalidKey
        LOGD(&gUdsBlServicesLogContext, " Invalid key detected ", keyCounter.attemptCounter1);

        if (keyCounter.attemptCounter1 < mMaxRetries)
        {
            mMaxRetriesReached = 0;
            mtriggerDelayCounter = 1;
            CUdsServiceSecurityAccessHandler::UDSStopDelayTimer();
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_InvalidKey;
        }
        else if (keyCounter.attemptCounter1 >= mMaxRetries)
        {
            responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_ExceedNumberOfAttempts;
            mMaxRetriesReached = 1;
            if(mtriggerDelayCounter)
            {
                mtriggerDelayCounter = 0;
                if(keyCounter.delayCounter == 0)
                {
                    keyCounter.delayCounter = CUdsServiceSecurityAccessHandler::mDelayCounterInSec;
                    CUdsServiceSecurityAccessHandler:: UDSStartDelayTimer();
                }

            }


            LOGD(&gUdsBlServicesLogContext, " maxretry ", mtriggerDelayCounter, "keyCounter.delayCounter", keyCounter.delayCounter);
        }

    }

    (void)CUdsPersistManager::saveGipIntegrityChkStatus_counter(keyCounter);

    /// -# Return response status
    return responseCode;
}

int32_t CUdsServiceSecurityAccessHandler::verifyKey( const uint8_t * const pKeyDataBuffer, uint16_t keyDataLength, uint8_t securitySubFunction)
{
    int32_t ret;
    FILE *fp;
    int32_t count;

    LOGI(&gUdsBlServicesLogContext,"Key length is :  ", keyDataLength);

    if( (fp = fopen("/tmp/encryptedKey.txt", "wb")) != NULL)
    {
        count = fwrite(pKeyDataBuffer, keyDataLength, 1, fp);
        if(1 == count)
        {
            LOGI(&gUdsBlServicesLogContext,"fwrite successful for ", "/tmp/encryptedKey.txt");
            ret = 0;
        }
        else
        {
            LOGE(&gUdsBlServicesLogContext,"fwrite failed for ", "/tmp/encryptedKey.txt");
        }
        fclose(fp);
    }
    else
    {
        LOGE(&gUdsBlServicesLogContext,"fopen error for ", "/tmp/keyDataLength.txt");
    }

    ret  = mCryptoRSA.verifySign("/tmp/rawSeed.txt", "/tmp/encryptedKey.txt", "sha256", "/etc/2701_public_key.pem", RSA_PADDING_PSS, 32);

    return  ret;
}

/// @brief This method is used update dummy seed
/// @param[out] pSeed :  update the seed value
/// @param[in] length : size of the seed(bytes)
///
int32_t  CUdsServiceSecurityAccessHandler::genFormalSeed( )
{
    dk::lib::meet::SJsonDataType lRDlyjsonData; ///< Json data
    int lSubFuncChk;
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
        LOGE(&gUdsBlServicesLogContext, " Failed to open Ring oscillator for random num generation   ");
    }
    else
    {
        int32_t rc = TRNG_Read(fd, mSeedRandomNumber, mRandomNumLen);
        if (rc == -1)
        {
            LOGE(&gUdsBlServicesLogContext, "Unable to read random Number   ");
        }
        else
        {
            ret = 0;
            LOGV(&gUdsBlServicesLogContext, "Random number generated successfully");
        }
    }

    ///< Read Increment Counter
    if(ret == 0)
    {
        ret = -1;
        if ( mJsonRWPath.c_str() != nullptr )
        {
            mJsonRWHandlr.reset ( new dk::lib::meet::CjsonRWAccessor (  mJsonRWPath.c_str() ) );

            if ( mJsonRWHandlr->jsonIsValid() == -1 ) ///< Check If filePath/file valid
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

                mJsonRWHandlr.reset ( new dk::lib::meet::CjsonRWAccessor ( mJsonRWPath.c_str()  ) );
                if ( mJsonRWHandlr->jsonIsValid() == -1 )
                {
                    LOGE ( &gUdsBlServicesLogContext, "No valid RW json file" );
                }
                else
                {
                    ret = 0;
                    LOGI ( &gUdsBlServicesLogContext, " Json file Read from the path : ", mJsonRWPath );
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

        lSubFuncChk = mJsonRWHandlr->jsonGetValue ("seedkeyCounter", lRDlyjsonData);
        if ( lSubFuncChk == 0 )
        {

            LOGV ( &gUdsBlServicesLogContext, " Read the seed key counter  : ", "Size of the counter ",  +lRDlyjsonData.llData.size());

            uint8 index = 0;

            if (  lRDlyjsonData.llData.size() == mSeedIncrementCntrLen  )
            {

                for ( auto it = lRDlyjsonData.llData.begin() ; it < lRDlyjsonData.llData.end(); it++, index++ )
                {
                    mSeedIncrementCntr[index] = static_cast<uint8_t> ( *it );
                }

                lSubFuncChk = update256bitInrementCounter( &mSeedIncrementCntr[0],mSeedIncrementCntrLen);
                if(lSubFuncChk == 0)
                {
                    dk::lib::meet::SJsonDataType lRWjsonData; ///< Json data
                    lRWjsonData.lenumType = dk::lib::meet::EJsonType_longInt;
                    for ( index = 0; index < mSeedIncrementCntrLen ; index++  )
                    {
                        lRWjsonData.llData.push_back( mSeedIncrementCntr[index]);
                    }


                    lSubFuncChk = mJsonRWHandlr->jsonSetValue ( "seedkeyCounter", lRWjsonData );

                    if(lSubFuncChk == 0 )
                    {
                        ret = 0;
                        LOGV(&gUdsBlServicesLogContext, "Increment counter saved to the json file  ");

                        ///<Update the JSON file
                        ret = mJsonRWHandlr->jsonSyncToStorage();

                    }
                    else
                    {
                        LOGE(&gUdsBlServicesLogContext, "Unable to save increment counter  ");
                    }
                }
                else
                {
                    LOGE(&gUdsBlServicesLogContext, "Unable to compute increment counter  ");
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
        LOGE(&gUdsBlServicesLogContext, "Send $F18C request to VIP  ");

    }

    return ret;
}

///
/// @brief This method is to compute seed and sent the value in intended format
/// @param[in] msg :  Msg from VIP (UCL). On reception of  "0xF18C" serial number from VIP , seed is computed
///
void CUdsServiceSecurityAccessHandler::prepareFormalSeedResponse(BlDiagResponse & msg )
{
    std::vector<uint8_t> dataBuffer;
    uint8_t lRandomSeed[86];
    //CUdsServiceHandlerIf::ESessionType_t currentSession;    // current session
    //CUdsServiceHandlerIf::ESecurityLevel_t currentSecurityLevel; // current security level
    uint8_t lEncryptedSeed[256]= {0x0 };
    int32_t ret = -1 ;
    dk::lib::meet::SJsonDataType lRDlyjsonData; ///< Json data
    int32_t lEncryptRSAChk = -1;
    CUdsServiceHandlerIf::EResponseCode_t responseCode; // response status.
    FILE *fp;
    int32_t count = 0;

    ///< Read current session
    //currentSession = mpServiceManagerInstance.getCurrentSession();
    ///< Read current security level
    //currentSecurityLevel = mpServiceManagerInstance.getCurrentSecurityLevel();
    ///< Security level
    dataBuffer.push_back( mRequestedSubFcn);
    ///< random number

    LOGI(&gUdsBlServicesLogContext,"Package creation for seed-key pair");

    //std::copy(std::begin(mSeedRandomNumber), std::end(mSeedRandomNumber), std::begin(lRandomSeed));
    std::copy(mSeedRandomNumber, mSeedRandomNumber + mRandomNumLen, lRandomSeed);
    std::copy(mSeedIncrementCntr, mSeedIncrementCntr + mSeedIncrementCntrLen, &lRandomSeed[32] );

    //std::copy(std::begin(mSeedIncrementCntr), std::end(mSeedIncrementCntr ) , &lRandomSeed[32] );
    lRandomSeed[64] = 0x1;
    lRandomSeed[65] = 0x2; ///< reprogramming session

    std::copy((msg.response), (msg.response + 20 ), &lRandomSeed[ 66]);
    ///< Encryption -> RSA 1056 bit
    ///< write the generated seed in a file  and store in temp path
    ///<  create a empty file for  storing the encrypted data
    if( (fp = fopen("/tmp/rawSeed.txt", "wb")) != NULL)
    {
        count = fwrite(static_cast<const void*>(&lRandomSeed[0]), mSeedKeyResponseLength, 1, fp);
        if(1 == count)
        {
            LOGI(&gUdsBlServicesLogContext,"fwrite successful for ", "/tmp/rawSeed.txt");
            ret = 0;
        }
        else
        {
            LOGE(&gUdsBlServicesLogContext,"fwrite failed for ", "/tmp/rawSeed.txt");
        }
        fclose(fp);
    }
    else
    {
        LOGE(&gUdsBlServicesLogContext,"fopen error for ", "/tmp/rawSeed.txt");
    }

    if(ret == 0)
    {
        ret = -1;
        ///< create a file
        lEncryptRSAChk = mCryptoRSA.rsaEncrypt("/tmp/rawSeed.txt", "/tmp/encryptedRawseed.txt","/etc/2701_public_key.pem",RSA_PADDING_OAEP);

        if( lEncryptRSAChk == 0)
        {
            if((fp = fopen("/tmp/encryptedRawseed.txt", "rb")) != NULL)
            {
                size_t lCnt;

                lCnt = fread( &lEncryptedSeed[0], 256, 1, fp);
                LOGI(&gUdsBlServicesLogContext,"read Encrypted Seed length (in bytes )  : ", +lCnt);
                if( lCnt != 0 )
                {
                    ret = 0;
                }
                else
                {
                    ret = -1;
                    LOGE(&gUdsBlServicesLogContext,"read Encrypted Seed Failed : ", count);
                }

                fclose(fp);
            }
            else
            {
                LOGE(&gUdsBlServicesLogContext,"Unable to open encrypted raw seed  : " );
            }
        }
    }

    if(ret == 0 )
    {
        ///< Copy the encrypted Seed and send it to UDS stack
        std::copy(&lEncryptedSeed[0], &lEncryptedSeed[256], std::back_inserter(dataBuffer));
        //mRequestedSecurityLevel = newSecurityLevel;
        mSecurityAccessState = ESecurityAccessState_t::ESecurityAccessState_WaitForKey;

#ifdef UDSCFG_LOG_ENABLED
        LOGD(&gUdsBlServicesLogContext,"Read DID positive response updated for ",msg.didId);
#endif
        ///< -# If positive response received , then Update DID response data in response buffer.
        mpServiceManagerInstance.serviceResponseUpdate(mClientAddress,CUdsServiceManagerIf::EResponseType_t::EResponse_Positive,dataBuffer );
    }
    else
    {
        responseCode = CUdsServiceHandlerIf::EResponseCode_t::EResponseCode_FailurePreventsExecutionOfRequestedAction;
        LOGD(&gUdsBlServicesLogContext,"Request not accepted because of NRC Code ", responseCode);
        mpServiceManagerInstance.sendNegativeResponse(mClientAddress,static_cast<CUdsServiceHandlerIf::EResponseCode_t>(responseCode));
    }
}
///
/// @brief This method is used to increment 256 bit seed key increment counter .
/// @param[in/out] pMsgBuff : Buffer to increment the counter
/// @param[in] pMsgBuff : Size of the buffer (in bytes).
/// @param[out] "-1" failed "0" success
///
int CUdsServiceSecurityAccessHandler::update256bitInrementCounter(uint8_t *pMsgBuff, uint16_t lBufSize )
{
    int  ret =  -1 ;
    int16_t index;
    uint8_t Overflow = 1;

    if((NULL != pMsgBuff) && (lBufSize == mSeedIncrementCntrLen))
    {
        ret = isMaxValueNotReached( pMsgBuff, lBufSize);
        if(ret == 0)
        {
            LOGE(&gUdsBlServicesLogContext,"overflow ");

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

    LOGE(&gUdsBlServicesLogContext,"After the overflow logic ");
    return ret;
}

///
/// @brief This method is used to inspect if max value reached  .
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
int32_t  CUdsServiceSecurityAccessHandler::genDummySeed( uint8_t &pSeed,  uint16_t length)
{
    int32_t Ret = -1;

    if(length == mSeedLength  )
    {
        std::memset(&pSeed,0xff,length);
        Ret = 0;
    }

    return  Ret;
}


int8_t CUdsServiceSecurityAccessHandler::verifySecurityAccess(void)
{
    int8_t ret = -1 ;

    if(CUdsServiceSecurityAccessHandler::mKeyUnlocked == true )
    {
        ret = 0;
    }

    return ret;

}


} // udsblservices
} // app
} // dk
