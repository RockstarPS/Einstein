//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Thu Dec 28 15:23:37 IST 2023
// User: SSUBRA21
// System: GIP
// Configuration: Platform
// Project: EU_BMW_MIC
// Message Catalogue version : 1.0.0
//
//---------------------------------------------------------------------------------------------------------------------
#include "eins_uds_appl_component.h"
#include "dk_logger.h"
#include <unistd.h>

/// Start of user code : Header user code for file eins_uds_appl_component.cpp

/// End of user code

namespace dk
{
namespace app
{
namespace udsblservices
{


LOG_DECLARE_CONTEXT(gUdsBlServicesLogContext);

bool EinsUdsApplComponent::onInit()
{
    bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file eins_uds_appl_component.cpp

/// End of user code

    printf("EinsUdsApplComponentInit \r\n");
    LOG_REGISTER_CONTEXT(gUdsBlServicesLogContext, "UDS Service Handler",  "UDS Service Handler", DLT_LOG_VERBOSE);
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onInit Invoked" );
    mUdsServiceSessionManagementHandlerInstance.serviceInitialize();
    mUdsServiceIOControlHandlerInstance.serviceInitialize();
    mUdsServiceDataIdentifierHandlerInstance.serviceInitialize();
    mUdsServiceRoutineIdentifierHandlerInstance.serviceInitialize();
    mUdsServiceEcuResetHandlerInstance.serviceInitialize();
	mUdsServiceDownloadHandlerInstance.serviceInitialize();
    iniHandler();

    return ret;
}

bool EinsUdsApplComponent::onExit()
{
    bool ret = Component::onExit();

    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onExit Invoked" );
/// Start of user code : User code for function onExit in file eins_uds_appl_component.cpp

/// End of user code

    return ret;
}

bool EinsUdsApplComponent::onStart()
{
    bool ret = Component::onStart();
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onStart \n Invoked" );
/// Start of user code : User code for function onStart in file eins_uds_appl_component.cpp

/// End of user code

    return ret;
}

bool EinsUdsApplComponent::onStop()
{
    bool ret = Component::onStop();
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onStop Invoked" );
/// Start of user code : User code for function onStop in file eins_uds_appl_component.cpp

/// End of user code

    return ret;
}

void EinsUdsApplComponent::worker()
{
/// Start of user code : User code for function worker in file eins_uds_appl_component.cpp

/// End of user code
}

void EinsUdsApplComponent::onReceiveUdsServiceReqIndication(UdsServiceReqIndication const  & msg)
{
/// Start of user code : User code for function onReceiveUdsServiceReqIndication in file eins_uds_appl_component.cpp
    LOGI(&gUdsBlServicesLogContext,"DkMsgUdsServiceReqIndicatio message received " );
    mUdsServiceManagerInstance.serviceRequestHandler(msg.clientAddress,msg.requestType,msg.dataLen,&msg.data[0]);
/// End of user code
}

void EinsUdsApplComponent::onReceiveUdsTimeout(UdsTimeout const  & msg)
{
/// Start of user code : User code for function onReceiveUdsTimeout in file nissan_bl_uds_appl_component.cpp
    // LOGD(&gUdsBlServicesLogContext,"DkMsgUdsTimeout message received " );
    ///Check for session timeout
    if (msg.timeoutType == EUdsTimeout_Session)
    {
        mUdsServiceManagerInstance.sessionTimeout();
    }
    ///Check for service timeout
    else if (msg.timeoutType == EUdsTimeout_Service)
    {
        mUdsServiceManagerInstance.serviceTimeout(msg.clientAddress);
        // LOGE(&gUdsBlServicesLogContext, "Flash read Error",l_bytes_S32);
        // LOGE(&gUdsBlServicesLogContext, "Error vale ", strerror( errvalue ));
    }
    else
    {
        // invalid type
    }
/// End of user code
}

void EinsUdsApplComponent::onReceiveUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation const  & msg)
{
/// Start of user code : User code for function onReceiveUdsServiceResponseTransmitConfirmation in file bmw_uds_appl_component.cpp
    LOGI(&gUdsBlServicesLogContext,"DkMsgUdsServiceResponseTransmitConfirmation message received " );
    mUdsServiceManagerInstance.serviceTransmitConfirmation(msg.clientAddress,
            static_cast<CUdsServiceManagerIf::EResponseType_t>(msg.responseType)
                                                          );
/// End of user code

/// End of user code
}


void EinsUdsApplComponent::onReceiveGipDiagResponse(GipDiagResponse const  & msg)
{
    GipDiagResponse msg1 ;
    msg1 = msg ;
/// Start of user code : User code for function onReceiveBlGipDiagResponse in file bmw_uds_appl_component.cpp
    LOGI(&gUdsBlServicesLogContext,"DkMsgBlGipDiagResponse message received " );
    // mUdsServiceDataIdentifierHandlerInstance.readDidResponseUpdateFrmVIP(msg1);
    if(msg1.sid == ESidType_IoCtrl)
    {
        mUdsServiceIOControlHandlerInstance.IOControlResponse(msg1);
    }

    else if(msg1.sid == ESidType_ReadDid || msg1.sid == ESidType_WriteDid)
    {
        mUdsServiceDataIdentifierHandlerInstance.RWControlResponse(msg1);
    }

    else if(msg1.sid == ESidType_RoutineId)
    {
        mUdsServiceRoutineIdentifierHandlerInstance.RoutineControlResponse(msg1);
    }

    else if(msg1.sid == 10)
    {
        mUdsServiceManagerInstance.RoutineControlResponse(msg1);
    }
    else if(msg1.sid == ESidType_EcuReset)
    {
        mUdsServiceEcuResetHandlerInstance.ecuResetResponseHandler(msg1);

    }
/// End of user code
}




void EinsUdsApplComponent::periodicTask(void)
{
    /*LOGV(&gUdsBlServicesLogContext,"CUdsBlServiceManagerComp::periodicTask " );*/
    mUdsServiceManagerInstance.periodicTask();
}

void EinsUdsApplComponent::onReceiveDoIPDownloadResponse(DoIPDownloadResponse const  & msg)
{
	switch(msg.serviceId)
	{
		case 0x34:
		case 0x36:
		case 0x37:
		{
			mUdsServiceDownloadHandlerInstance.DownloadServiceResponseHandler(msg);
			// Send to Download Manager;
			break;
		}
		case 0xFE00:
		case 0xFE01:
		case 0xFE02:
		case 0xFE03:
		case 0xFF00:
		case 0xFF01:
		{
			mUdsServiceRoutineIdentifierHandlerInstance.DownloadServiceResponseHandler(msg);
			// Send to Routine Manager;
			break;
		}
		default:
		{
			break;
		}
	}
}

void EinsUdsApplComponent::iniHandler(void)
{
    bool parserStatus;
    bool pathListStatus;
    std::string temporaryFilePath;
    uint32_t udsServicePeriodicityValue = 0;
    std::vector<std::string> udsPathList;
    std::vector<uint16_t> diagModeAddress;
    std::vector<uint16_t> fotaModeAddress;
    std::stringstream ss;
    uint32_t noOfAddress;
    uint16_t address;

    parserStatus = false ;
    /// -# Check for uds core ini file in UDS_CORE_INI_FILE_PATH1 path, if not Check for uds core ini file
    /// in UDS_CORE_INI_FILE_PATH2 path.If file not found in both path default configuration is used.
    if(mUdsServiceManagerParser.loadConfiguration(mUdsBlServicesIniFilePath1))
    {
        parserStatus = true;
        LOGV(
            &gUdsBlServicesLogContext, "UdsCoreComponent:: udsCoreIniHandler ini file found in ",
            mUdsBlServicesIniFilePath1
        );
    }
    else if(mUdsServiceManagerParser.loadConfiguration(mUdsBlServicesIniFilePath2))
    {
        parserStatus = true;
        LOGV(
            &gUdsBlServicesLogContext, "UdsCoreComponent:: udsCoreIniHandler ini file found in ",
            mUdsBlServicesIniFilePath2
        );
    }
    else
    {
        parserStatus = false ;
    }

    if(parserStatus == true)
    {
        /// -# Loading UdsCore configuration from ini file , if the ini file found.
        pathListStatus = mUdsServiceManagerParser.getAllValuesForKey(
                             "udsDownloadServices",
                             "downloadTemporaryFilePath",
                             udsPathList
                         );
        if(pathListStatus != false)
        {
            if (udsPathList.size() > 0U)
            {
                temporaryFilePath = udsPathList[0];
            }
            else
            {
                //temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
            }
        }
        else
        {
            // temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
        }


        udsServicePeriodicityValue = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value(
                                         "udsBlServices",
                                         "udsServiceManagerMainFunctionPeriodInMs",
                                         static_cast<int32_t>(mUdsServiceManagerMainFunctionPeriodInMs)
                                     ));

        /// -# update the list of address of diagnostic mode
        noOfAddress = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value("udsDiagModeAddress","numberOfDiagModeAddress",0));
        for(uint32_t index = 0U; index<noOfAddress; ++index)
        {
            ss.str(std::string());
            ss<<index;
            address = static_cast<uint16_t>(mUdsServiceManagerParser.getInt32Value("udsDiagModeAddress",
                                            "diagModeAddress_"+ss.str(),
                                            0xFFFF
                                                                                  ));
            diagModeAddress.push_back(address);
        }

        noOfAddress = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value("udsFotaModeAddress","numberOfFotaModeAddress",0));
        for(uint32_t index = 0U; index<noOfAddress; ++index)
        {
            ss.str(std::string());
            ss<<index;
            address = static_cast<uint16_t>(mUdsServiceManagerParser.getInt32Value("udsFotaModeAddress",
                                            "fotaModeAddress_"+ss.str(),
                                            0xFFFF
                                                                                  ));
            fotaModeAddress.push_back(address);
        }

    }
    else
    {
        /// -# If Uds Core ini file not found load default configuration.
        LOGE(&gUdsBlServicesLogContext, "UdsCoreComponent::udsCoreIniHandler Failed to load uds core ini file ");
        //temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
        //udsServicePeriodicityValue = mUdsServiceManagerMainFunctionPeriodInMs;
    }

    LOGD(&gUdsBlServicesLogContext,"temporaryFilePath = ",temporaryFilePath);
    /// -# Register periodic task of  CUdsBlServiceManagerComp with configurable time.
    (void)registerTask([=]() {
        periodicTask();
    }, udsServicePeriodicityValue);

    LOGD(
        &gUdsBlServicesLogContext,
        "Register periodic task of  CUdsBlServiceManagerComp with  udsServicePeriodicityValue = ",
        temporaryFilePath
    );

    /// -# Set temporary download file path
    // mUdsServiceDownloadHandlerInstance.setDownloadFileTemporaryPath(temporaryFilePath);
    mUdsServiceManagerInstance.setDiagnosticModeAddress(fotaModeAddress,
            CUdsServiceManager::EAddressMode_t::EAddressMode_FotaClient);
    mUdsServiceManagerInstance.setDiagnosticModeAddress(diagModeAddress,
            CUdsServiceManager::EAddressMode_t::EAddressMode_DiagClient);
}

}
}
}

/// Start of user code : Footer user code for file eins_uds_appl_component.cpp

/// End of user code

