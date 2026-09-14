//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Tue Jul 20 14:55:07 IST 2021
// User: RKRISHN8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "uds_appl_component.h"

/// Start of user code : Header user code for file uds_appl_component.cpp
namespace dk
{
namespace app
{
namespace udsblservices
{

LOG_DECLARE_CONTEXT(gUdsBlServicesLogContext);

/// End of user code

bool UdsApplComponent::onInit()
{
    bool ret = true;

    Component::onInit();

/// Start of user code : User code for function onInit in file uds_appl_component.cpp
    /// -# Register the logger instance with the logger type.
    LOG_REGISTER_CONTEXT(gUdsBlServicesLogContext, "UDS Service Handler",  "UDS Service Handler", DLT_LOG_INFO);
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onInit Invoked" );

    
    /// -# Invoke service handler serviceInitialize method so that each service can register its configuration 
    /// to this instance.
    mUdsServiceSessionManagementHandlerInstance.serviceInitialize();
    mUdsServiceDownloadHandlerInstance.serviceInitialize();
    mUdsServiceTesterPresentHandlerInstance.serviceInitialize();
    mUdsServiceDataIdentifierHandlerInstance.serviceInitialize(); 
    mUdsServiceSecurityAccessHandlerInstance.serviceInitialize();
    mUdsServiceRoutineControlHandlerInstance.serviceInitialize();
    mUdsServiceDtcHandlerInstance.serviceInitialize();
    mUdsServiceEcuResetHandlerInstance.serviceInitialize();

    /// -# Process INI configuration for Uds Services.
    iniHandler();
/// End of user code

    return ret;
}

bool UdsApplComponent::onExit()
{
    bool ret = true;
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onExit Invoked" );

    Component::onExit();

/// Start of user code : User code for function onExit in file uds_appl_component.cpp

/// End of user code

    return ret;
}

bool UdsApplComponent::onStart()
{
    bool ret = true;
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onStart \n Invoked" );

    Component::onStart();

/// Start of user code : User code for function onStart in file uds_appl_component.cpp
    mUdsServiceSecurityAccessHandlerInstance.diagHardeningOnStart();
/// End of user code

    return ret;
}

bool UdsApplComponent::onStop()
{
    bool ret = true;
    LOGI(&gUdsBlServicesLogContext,  "UdsCoreComponent onStop Invoked" );

    Component::onStop();

/// Start of user code : User code for function onStop in file uds_appl_component.cpp

/// End of user code

    return ret;
}

void UdsApplComponent::worker()
{
/// Start of user code : User code for function worker in file uds_appl_component.cpp

/// End of user code
}

void UdsApplComponent::onReceiveUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation & msg)
{
/// Start of user code : User code for function onReceiveUdsServiceResponseTransmitConfirmation in file uds_appl_component.cpp
 
    LOGD(&gUdsBlServicesLogContext,"DkMsgUdsServiceResponseTransmitConfirmation message received " );
    /// Invoke service Manager confirmation method serviceTransmitConfirmation to do post processing tasks.
    mUdsServiceManagerInstance.serviceTransmitConfirmation(msg.clientAddress,
                                                   static_cast<CUdsServiceManagerIf::EResponseType_t>(msg.responseType)
                                                    );
}
/// End of user code



void UdsApplComponent::onReceiveUdsServiceReqIndication(UdsServiceReqIndication & msg)
{
/// Start of user code : User code for function onReceiveUdsServiceReqIndication in file uds_appl_component.cpp
    LOGD(&gUdsBlServicesLogContext,"DkMsgUdsServiceReqIndication message received " );
    /// -# Invoke service Manager request handler method serviceRequestHandler to validate the received request
    mUdsServiceManagerInstance.serviceRequestHandler(msg.clientAddress,msg.requestType,msg.dataLen,&msg.data[0]);

/// End of user code
}

void UdsApplComponent::onReceiveUdsInstallerDidResponse(UdsInstallerDidResponse & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerDidResponse in file uds_appl_component.cpp

    LOGD(&gUdsBlServicesLogContext,"DkMsgUdsInstallerDidResponse_t message received " );
/// End of user code
}

void UdsApplComponent::onReceiveUdsTimeout(UdsTimeout & msg)
{
/// Start of user code : User code for function onReceiveUdsTimeout in file uds_appl_component.cpp
    LOGD(&gUdsBlServicesLogContext,"DkMsgUdsTimeout message received " );
    ///Check for session timeout
    if (msg.timeoutType == EUdsTimeout_Session)
    {
        mUdsServiceManagerInstance.sessionTimeout();
    }
    ///Check for service timeout
    else if (msg.timeoutType == EUdsTimeout_Service)
    {
        mUdsServiceManagerInstance.serviceTimeout(msg.clientAddress);
    }
    else
    {
        // invalid type
    }
/// End of user code
}


void UdsApplComponent::onReceiveUdsNvmResponse(UdsNvmResponse & msg)
{
/// Start of user code : User code for function onReceiveUdsNvmResponse in file uds_appl_component.cpp
    LOGD(&gUdsBlServicesLogContext,"DkMsgUdsNvmResponse_t message received " );

/// End of user code
}

void UdsApplComponent::periodicTask(void)
{
    /*LOGV(&gUdsBlServicesLogContext,"CUdsBlServiceManagerComp::periodicTask " );*/
    mUdsServiceManagerInstance.periodicTask();
}

void UdsApplComponent::iniHandler(void)
{
    bool parserStatus;
    bool pathListStatus;
    std::string temporaryFilePath;
    uint32_t udsServicePeriodicityValue;
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
                temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
            }
        }
        else
        {
           temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
        }
        
            
        udsServicePeriodicityValue = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value(
                                                            "udsBlServices",
                                                            "udsServiceManagerMainFunctionPeriodInMs",
                                                         static_cast<int32_t>(mUdsServiceManagerMainFunctionPeriodInMs)
                                                            ));
                                                            
        /// -# update the list of address of diagnostic mode
        noOfAddress = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value("udsDiagModeAddress","numberOfDiagModeAddress",0));
        if (noOfAddress < 10000U) 
        {
            for(uint32_t index1 = 0U;index1<noOfAddress;++index1)
            {
                ss.str(std::string());
                ss<<index1; 
                address = static_cast<uint16_t>(mUdsServiceManagerParser.getInt32Value("udsDiagModeAddress",
                                                                            "diagModeAddress_"+ss.str(),
                                                                            0xFFFF
                                                                            ));
                diagModeAddress.push_back(address);   
            }
        }
        
        noOfAddress = static_cast<uint32_t>(mUdsServiceManagerParser.getInt32Value("udsFotaModeAddress","numberOfFotaModeAddress",0));
        if (noOfAddress < 10000U) 
        {
            for(uint32_t index2 = 0U;index2<noOfAddress;++index2)
            {
                ss.str(std::string());
                ss<<index2; 
                address = static_cast<uint16_t>(mUdsServiceManagerParser.getInt32Value("udsFotaModeAddress",
                                                                            "fotaModeAddress_"+ss.str(),
                                                                            0xFFFF
                                                                            ));
                fotaModeAddress.push_back(address);
            }
        }
                                                            
    }    
    else
    {
        /// -# If Uds Core ini file not found load default configuration.
        LOGE(&gUdsBlServicesLogContext, "UdsCoreComponent::udsCoreIniHandler Failed to load uds core ini file "); 
        temporaryFilePath = mUdsServiceDownloadHandlerInstance.mDefaultDownloadTemporaryFilePath;
        udsServicePeriodicityValue = mUdsServiceManagerMainFunctionPeriodInMs;
    }
    
    LOGD(&gUdsBlServicesLogContext,"temporaryFilePath = ",temporaryFilePath);
    /// -# Register periodic task of  CUdsBlServiceManagerComp with configurable time.
    (void)registerTask([=]() { periodicTask(); }, udsServicePeriodicityValue);
    
    LOGD(
        &gUdsBlServicesLogContext,
        "Register periodic task of  CUdsBlServiceManagerComp with  udsServicePeriodicityValue = ",
        temporaryFilePath
        );
    
    /// -# Set temporary download file path
    mUdsServiceDownloadHandlerInstance.setDownloadFileTemporaryPath(temporaryFilePath);
    mUdsServiceManagerInstance.setDiagnosticModeAddress(fotaModeAddress,
                                CUdsServiceManager::EAddressMode_t::EAddressMode_FotaClient);
    mUdsServiceManagerInstance.setDiagnosticModeAddress(diagModeAddress,
                                CUdsServiceManager::EAddressMode_t::EAddressMode_DiagClient);
}

void UdsApplComponent::onReceiveVIPResponseHandler(const uint8_t responseCode, uint16_t msgID, uint8_t *pMsg)
{
    LOGD(&gUdsBlServicesLogContext,"Response message received from VIP", msgID);
}


void UdsApplComponent::onReceiveInstallerFlashStatusNotification(InstallerFlashStatusNotification & msg)
{
    LOGD(&gUdsBlServicesLogContext,"DkMsgInstallerUdsVerifyResp_t Install notification ",+msg.status );

       mUdsServiceDownloadHandlerInstance.installerFlashStatus(msg.status);

}

void UdsApplComponent::onReceiveInstallerUdsVerifyResp(InstallerUdsVerifyResp & msg)
{
    LOGD(&gUdsBlServicesLogContext,"DkMsgInstallerUdsVerifyResp_t Resp message received ",+msg.verifyStatus );
}


void UdsApplComponent::onReceiveBlGipDiagResponse(BlDiagResponse & msg)
{
    /// Start of user code : User code for function onReceiveBlGipDiagResponse in file uds_appl_component.cpp
    LOGD(&gUdsBlServicesLogContext,"Response message received from VIP", "Service Id" ,+msg.sid, "Data Unit Id", +msg.didId,"size",+msg.responseLen);
    /// Notify corresponding Response handler service
    /// End of user code
}

void UdsApplComponent::onReceiveBlVipDiagRequest(BlDiagRequest & msg)
{
    /// Start of user code : User code for function onReceiveBlVipDiagRequest in file uds_appl_component.cpp
    LOGD(&gUdsBlServicesLogContext,"Request message received from VIP", "Service Id" ,+msg.serviceId, "Data Unit Id", +msg.didId);

    /// End of user code
}

}
}
}
/// End of user code

