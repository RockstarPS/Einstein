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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.1
// Date: Thu May 28 21:15:28 IST 2020
// User: SRODIN
// System: GPU
//
//---------------------------------------------------------------------------------------------------------------------
#include "uds_core_component.h"

/// Start of user code : Header user code for file c_uds_core_comp.cpp
#include <iostream>
#include <chrono>
#include "uds_core_component.h"
#include "dk_srvc_uds_tp_doip.h"
#include "dk_srvc_uds_core.h"

//#ifdef UDSCORE_LOG_ENABLED
//LOG_DECLARE_CONTEXT(gUdsCoreLogContext);
//#endif
/// End of user code

namespace dk
{
namespace srvc
{
namespace udscore
{
#ifdef UDSCORE_LOG_ENABLED
LOG_DECLARE_CONTEXT(gUdsCoreLogContext);
#endif
bool UdsCoreComponent::onInit()
{
    bool ret = true;

    Component::onInit();

/// Start of user code : User code for function onInit in file c_uds_core_comp.cpp
    // (void)dk::runtime::core::Component::onInit();
#ifdef UDSCORE_LOG_ENABLED
    LOG_REGISTER_CONTEXT(gUdsCoreLogContext, "UDS",  "UDS Core component", DLT_LOG_INFO);

    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onInit Invoked" );
    /// -# Update UDS configuration from INI file.
    LOGI(&gUdsCoreLogContext,"CUdsCoreComp::onInit Invoked 2" );
#endif
    udsCoreIniHandler();
#ifdef UDSCORE_LOG_ENABLED
    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onInit Invoked 3" );
#endif
    if (mpUdsCoreInst!= nullptr)
    {
        /// -# Invoke UdsCore onInit.
        mpUdsCoreInst->onInit();
    }
#ifdef UDSCORE_LOG_ENABLED
    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onInit Invoked 2" );
#endif
/// End of user code

    return ret;
}

bool UdsCoreComponent::onExit()
{
    bool ret = true;

    Component::onExit();

/// Start of user code : User code for function onExit in file c_uds_core_comp.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onExit Invoked" );
#endif
    /// -# delete allocated memory for CUdsCore and UdsTp object
    if (mpUdsCoreInst!= nullptr)
    {
        mpUdsCoreInst->onExit();
    }
    if(mpUdsTpIfInst != nullptr)
    {
        delete mpUdsTpIfInst;
    }

    if(mpUdsCoreInst != nullptr)
    {
        delete mpUdsCoreInst;
    }
    (void)dk::runtime::core::Component::onExit();
/// End of user code

    return ret;
}

bool UdsCoreComponent::onStart()
{
    bool ret = true;



/// Start of user code : User code for function onStart in file c_uds_core_comp.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onStart Invoked" );
#endif
    Component::onStart();
//   (void)dk::runtime::core::Component::onStart();
/// End of user code

    return ret;
}

bool UdsCoreComponent::onStop()
{
    bool ret = true;

//	Component::onStop();

/// Start of user code : User code for function onStop in file c_uds_core_comp.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGI(&gUdsCoreLogContext,  "CUdsCoreComp::onStop Invoked" );
#endif
    // (void)dk::runtime::core::Component::onStop();
    //return true;
    Component::onStop();
/// End of user code

    return ret;
}

void UdsCoreComponent::worker()
{
/// Start of user code : User code for function worker in file c_uds_core_comp.cpp

/// End of user code
}

void UdsCoreComponent::onReceiveDoipDiagDataIndication(DoipDiagDataIndication & msg)
{
/// Start of user code : User code for function onReceiveDoipDiagDataIndication in file uds_core_component.cpp
    /// On reception of Data from Diagnostic message from DoIP
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"DkMsgDoipDiagDataIndication DK message received msg.targetAddressType ",static_cast<uint32_t >(msg.targetAddressType));
#endif
    if (mpUdsTpIfInst != nullptr)
    {
        /// notify the request to Tp Interface
        mpUdsTpIfInst->requestDataIndication(
            msg.sourceAddress,
            msg.targetAddress,
            msg.targetAddressType,
            static_cast<uint8_t *>(&msg.data[0]),
            msg.dataLen,
            msg.result
        );
    }
/// End of user code
}

void UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest & msg)
{
/// Start of user code : User code for function onReceiveDkMsgUdsServiceResponseTransmitRequest in file c_uds_core_comp.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"DkMsgUdsServiceResponseTransmitRequest DK message received ");
#endif
    /// notify the reception of diagnostic service response to UDS Core layer.
    if (mpUdsCoreInst != nullptr)
    {
        mpUdsCoreInst->updateResponse(static_cast<CUdsCore::EResponseType_t>(msg.responseType),
                                      msg.clientAddress,
                                      msg.dataLen,
                                      &(msg.data[0])
                                     );
    }

}

void UdsCoreComponent::onReceiveDoipDiagDataConfirmation(DoipDiagDataConfirmation & msg)
{
/// Start of user code : User code for function onReceiveDkMsgDoipDiagDataConfirmation in file c_uds_core_comp.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"DkMsgDoipDiagDataConfirmation DK message received ");
#endif
    /// On reception of Data confirmation request from DoIP
    if (mpUdsTpIfInst != nullptr)
    {
        /// notify the confirmation to Tp Interface
        mpUdsTpIfInst->trasmitDataConfirmation(msg.sourceAddress,msg.targetAddress,msg.targetAddressType,msg.result);
    }
/// End of user cod

}

void UdsCoreComponent::onReceiveUdsServiceSetTimings(UdsServiceSetTimings & msg)
{
/// Start of user code : User code for function onReceiveDoipDiagDataConfirmation in file uds_core_component.cpp
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"DkMsgUdsServiceSetTimings DK message received ");
#endif
    /// notify the reception of timing service update to UDS Core layer.
    if (mpUdsCoreInst != nullptr)
    {
        mpUdsCoreInst->setTimingParameters(msg.p2TimeMs,msg.p2StarTimeMs,msg.p4TimeMs);
    }
/// End of user code

}

/// Start of user code : User code for c_uds_core.cpp

void UdsCoreComponent::udsPeriodicTask(void)
{
    ///-# Invoking CUdsCore Periodic task
    if (mpUdsCoreInst!= nullptr)
    {
#ifdef UDSCORE_LOG_ENABLED
        //  LOGV(&gUdsCoreLogContext,  "udsPeriodicTask Invoked" );	/* dkasiman commented */
#endif
        mpUdsCoreInst->diagnosticMainFunction();
    }
}

void UdsCoreComponent::udsCoreIniHandler(void)
{
    bool parserStatus;
    CUdsCore::SUdsCoreConfig_t udsCoreConfig = {0};
    CUdsTpDoip::SUdsTpDoipConfig_t udsTpDoipConfig = {0};
    uint32_t noOfAddress = 0U;
    uint16_t address = 0U;
    std::stringstream ss;

    ///-# Check for uds core ini file in mUdsCoreIniFilePath1 path, if not Check for uds core ini file
    ///in mUdsCoreIniFilePath2 path.If file not found in both path default configuration is used.

    if(mUdsCoreParser.loadConfiguration(mUdsCoreIniFilePath1))
    {
        parserStatus = true;
#ifdef UDSCORE_LOG_ENABLED
        LOGV(
            &gUdsCoreLogContext, "CUdsCoreComp:: udsCoreIniHandler ini file found in ",
            mUdsCoreIniFilePath1
        );
#endif
    }
    else if(mUdsCoreParser.loadConfiguration(mUdsCoreIniFilePath2))
    {
        parserStatus = true;
#ifdef UDSCORE_LOG_ENABLED
        LOGV(
            &gUdsCoreLogContext, "CUdsCoreComp:: udsCoreIniHandler ini file found in ",
            mUdsCoreIniFilePath2
        );
#endif
    }
    else
    {
        parserStatus = false ;
    }

    if(parserStatus == true)
    {
        ///-# Loading CUdsCore configuration from ini file
        udsCoreConfig.mP2TimeCountInMs = static_cast<uint32_t>(mUdsCoreParser.getInt32Value(
                                             "udsCore",
                                             "udsP2TimeCountInMs",
                                             static_cast<int32_t>(mUdsP2TimeCountInMs)
                                         ));

        udsCoreConfig.mP2StarTimeCountInMs = static_cast<uint32_t>(mUdsCoreParser.getInt32Value(
                "udsCore",
                "udsP2StarTimeCountInMs",
                static_cast<int32_t>(mUdsP2StarTimeCountInMs)
                                             ));

        udsCoreConfig.mP4TimeCountInMs = static_cast<uint32_t>(mUdsCoreParser.getInt32Value(
                                             "udsCore",
                                             "udsP4TimeCountInMs",
                                             static_cast<int32_t>(mUdsP4TimeCountInMs)
                                         ));

        udsCoreConfig.mS3TimecountInMs = static_cast<uint32_t>(mUdsCoreParser.getInt32Value(
                                             "udsCore",
                                             "udsS3TimeCountInMs",
                                             static_cast<int32_t>(mUdsS3TimeCountInMs)
                                         ));

        udsCoreConfig.mUdsMainFunctionPeriodInMs= static_cast<uint32_t>(mUdsCoreParser.getInt32Value(
                    "udsCore",
                    "udsCoreMainFunctionPeriodInMs",
                    static_cast<int32_t>(mUdsCoreMainFunctionPeriodInMs)
                ));

        udsCoreConfig.mUdsBusyResponseForMultiRequestSupport = mUdsCoreParser.getBoolValue(
                    "udsCore",
                    "mUdsBusyResponseForMultiRequestSupport",
                    mBusyResponseForMultiRequestSupport
                );

        ///-# Loading CUdsTpDoip configuration from ini file
        udsTpDoipConfig.mUdsTpSourceAddress = static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                "udsTpDoip",
                "ecuSourceAddress",
                static_cast<int32_t>(mUdsDiagnosticAddress)
                                              ));

        noOfAddress = static_cast<uint32_t>(mUdsCoreParser.getInt32Value("udsTpDoip","noOfPhysicalAddressSupported",0));
        for(uint32_t index = 0U; index<noOfAddress; ++index)
        {
            ss.str(std::string());
            ss<<index;
            address = static_cast<uint16_t>(mUdsCoreParser.getInt32Value("udsTpDoip",
                                            "physicalAddress_"+ss.str(),
                                            0xFFFF
                                                                        ));
            udsTpDoipConfig.mUdsTpReceiveAddressConfig.push_back({address,
                    CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest});
        }

        noOfAddress =  static_cast<uint32_t>(mUdsCoreParser.getInt32Value("udsTpDoip","noOfFunctionalAddressSupported",0));
        for(uint32_t index = 0U; index<noOfAddress; ++index)
        {
            ss.str(std::string());
            ss<<index;
            address = static_cast<uint16_t>(mUdsCoreParser.getInt32Value("udsTpDoip",
                                            "functionalAddress_"+ss.str(),
                                            0xFFFF
                                                                        ));

            udsTpDoipConfig.mUdsTpReceiveAddressConfig.push_back({address,
                    CUdsCoreIf::ERequestType_t::ERequestType_FunctionalRequest});
        }
#ifdef DUAL_INSTANCE_POC

        udsTpDoipConfig.mDtoolAddress = static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                            "udsTpDoip",
                                            "dtoolAddress",
                                            static_cast<int32_t>(mUdsDiagnosticAddress)
                                        ));
        udsTpDoipConfig.mRdiagAddress =  static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                             "udsTpDoip",
                                             "rdiagAddress",
                                             static_cast<int32_t>(mUdsDiagnosticAddress)
                                         ));

        udsTpDoipConfig.mFtoolAddress = static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                            "udsTpDoip",
                                            "ftoolAddress",
                                            static_cast<int32_t>(mUdsDiagnosticAddress)
                                        ));

        udsCoreConfig.mDtoolAddress =   static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                            "udsTpDoip",
                                            "dtoolAddress",
                                            static_cast<int32_t>(mUdsDiagnosticAddress)
                                        ));
        udsCoreConfig.mRdiagAddress = static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                          "udsTpDoip",
                                          "rdiagAddress",
                                          static_cast<int32_t>(mUdsDiagnosticAddress)
                                      ));
        udsCoreConfig.mFtoolAddress = static_cast<uint16_t>(mUdsCoreParser.getInt32Value(
                                          "udsTpDoip",
                                          "ftoolAddress",
                                          static_cast<int32_t>(mUdsDiagnosticAddress)
                                      ));

#endif
    }
    else
    {
        ///-# If Uds Core ini file not found load default configuration.
#ifdef UDSCORE_LOG_ENABLED
        LOGE(&gUdsCoreLogContext, "CUdsCoreComp:: udsCoreIniHandler Failed to load uds core ini file ");
#endif
        udsCoreConfig.mP2TimeCountInMs = mUdsP2TimeCountInMs;
        udsCoreConfig.mP2StarTimeCountInMs = mUdsP2StarTimeCountInMs;
        udsCoreConfig.mP4TimeCountInMs = mUdsP4TimeCountInMs;
        udsCoreConfig.mS3TimecountInMs = mUdsS3TimeCountInMs;
        udsCoreConfig.mUdsMainFunctionPeriodInMs = mUdsCoreMainFunctionPeriodInMs;
        udsCoreConfig.mUdsBusyResponseForMultiRequestSupport = mBusyResponseForMultiRequestSupport;

        udsTpDoipConfig.mUdsTpSourceAddress = mUdsDiagnosticAddress;
        udsTpDoipConfig.mUdsTpReceiveAddressConfig.clear();
    }
#ifdef UDSCORE_LOG_ENABLED
    LOGI(
        &gUdsCoreLogContext,
        "udsCoreConfig values ",
        "udsCoreConfig.mP2TimeCountInMs = ",
        udsCoreConfig.mP2TimeCountInMs,
        "udsCoreConfig.mP2StarTimeCountInMs = ",
        udsCoreConfig.mP2StarTimeCountInMs,
        "udsCoreConfig.mP4TimeCountInMs = ",
        udsCoreConfig.mP4TimeCountInMs,
        "udsCoreConfig.mS3TimecountInMs = ",
        udsCoreConfig.mS3TimecountInMs,
        "udsCoreConfig.mUdsMainFunctionPeriodInMs = ",
        udsCoreConfig.mUdsMainFunctionPeriodInMs,
        "udsCoreConfig.mUdsBusyResponseForMultiRequestSupport = ",
        mBusyResponseForMultiRequestSupport
    );
#endif

    ///-# Create Uds Core Instance
    mpUdsCoreInst = new(std::nothrow)CUdsCore(udsCoreConfig);
    if (mpUdsCoreInst != nullptr)
    {
#ifdef UDSCORE_LOG_ENABLED
        ///-# If Uds Core ini file not found load default configuration.
        LOGE(&gUdsCoreLogContext, "CUdsCoreComp:: CUdsCore Instance Creation Success");
#endif
    }

#ifdef UDSCORE_LOG_ENABLED
    LOGI(
        &gUdsCoreLogContext,
        "udsTpDoipConfig values",
        "udsTpDoipConfig.mUdsTpSourceAddress = ",
        udsTpDoipConfig.mUdsTpSourceAddress
    );
#endif

    ///-# Create Doip Instance
    ///-# Create Uds Core Instance
    mpUdsTpIfInst = new(std::nothrow)CUdsTpDoip(udsTpDoipConfig);
    if (mpUdsTpIfInst != nullptr)
    {
#ifdef UDSCORE_LOG_ENABLED
        ///-# If Uds Core ini file not found load default configuration.
        LOGE(&gUdsCoreLogContext, "CUdsCoreComp:: CUdsTpDoip Instance Creation Success");
#endif
    }
    /// Check for valid instance of CUdsTpIf and CUdsCore
    if ((mpUdsTpIfInst != nullptr) && (mpUdsCoreInst!= nullptr))
    {
        /// -# set Tp Instance to Uds Core
        mpUdsCoreInst->setUdsTpIf(mpUdsTpIfInst);

        /// -# set Uds Instance to Uds Core
        mpUdsTpIfInst->setUdsCoreIf(static_cast<CUdsCoreIf*>(mpUdsCoreInst));
    }

    /// - # Register the task of Uds Core and Uds Timer
    (void)registerTask([=]() {
        udsPeriodicTask();
    }, udsCoreConfig.mUdsMainFunctionPeriodInMs);
#ifdef UDSCORE_LOG_ENABLED
    LOGD(&gUdsCoreLogContext,"udsPeriodicTask task is registered with time ",udsCoreConfig.mUdsMainFunctionPeriodInMs);
#endif
}
/// End of user code

} // udscore
} // srvc
} // dk

/// Start of user code : Footer user code for file c_uds_core_comp.cpp

/// End of user code

