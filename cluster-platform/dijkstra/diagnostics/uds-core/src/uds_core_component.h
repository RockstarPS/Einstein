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
#ifndef UDS_CORE_COMPONENT_H
#define UDS_CORE_COMPONENT_H

/// Start of user code : Header user code for file c_uds_core_comp.h
#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_parserif.h"
#include "dk_srvc_uds_tp_if.h"
#include "dk_srvc_uds_core.h"
#include "dk_runtime_uds_core_component.h"
/// End of user code

namespace dk
{
namespace srvc
{
namespace udscore
{

using namespace dk::runtime;

class UdsCoreComponent : public dk::runtime::core::Component
{
public:
    explicit UdsCoreComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)
    {
    }

    ~UdsCoreComponent()
    {
    }

    ///
    /// @brief This method implements the Uds core component Initialization Routine.
    ///
    bool onInit();

    ///
    /// @brief This method implements the Uds core component finalization Routine.
    ///
    bool onExit();

    ///
    /// @brief This method implements the Uds core component start Routine.
    ///
    bool onStart();

    ///
    /// @brief This method implements the Uds core component stop Routine.
    ///
    bool onStop();

    ///
    /// @brief This method implements the Uds core component worker Routine.
    ///
    void worker(void);
    ///
    /// @brief This method is invoked by Dk core on reception of DK_MSG_DOIP_DIAG_DATA_IND message.
    ///
    /// @param[in] data DK_MSG_DOIP_DIAG_DATA_IND message type
    ///
    void onReceiveDoipDiagDataIndication(DoipDiagDataIndication & msg);

    void onReceiveUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest & msg);

    void onReceiveDoipDiagDataConfirmation(DoipDiagDataConfirmation & msg);

    ///
    /// @brief This method is invoked by Dk core on reception of DK_MSG_UDS_CORE_SERVICE_SET_TIMINGS message.
    ///
    /// @param[in] data DK_MSG_UDS_CORE_SERVICE_SET_TIMINGS message type
    ///
    void onReceiveUdsServiceSetTimings(UdsServiceSetTimings & msg);

    ///
    /// @brief This method is invoked by Dk core on reception of DK_MSG_UDS_CORE_SERVICE_RES_TRANSMIT_REQ message.
    ///
    /// @param[in] data DK_MSG_UDS_CORE_SERVICE_RES_TRANSMIT_REQ message type
    ///
    void onReceiveDkMsgUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest & msg);

private:
/// Start of user code : User code for file c_uds_core_comp.h
    ///
    /// @brief It is the path location of INI file. This path will be searched first for INI file.
    ///
    //const std::string mUdsCoreIniFilePath1 = "/tmp/uds_core.ini";
#ifndef DIAG_BOOT_PATH
    const std::string mUdsCoreIniFilePath1 = "/system/etc/uds_core.ini";
#else
    const std::string mUdsCoreIniFilePath1 = "/etc/uds_core.ini";
#endif

    ///
    /// @brief It is the path location of INI file. This path will be searched for INI file if the file not found in
    ///        mUdsCoreIniFilePath1.
    ///
    const std::string mUdsCoreIniFilePath2 = "/etc/uds_core.ini";

    ///
    /// @brief P2 server time in milliseconds.It is the default value used when there is invalid INI File.
    ///
    const uint32_t mUdsP2TimeCountInMs= 50U;

    ///
    /// @brief P2star server time in milliseconds.It is the default value used when there is invalid INI File.
    ///
    const uint32_t mUdsP2StarTimeCountInMs = 5000U;

    ///
    /// @brief P4 server time in milliseconds.It is the default value used when there is invalid INI File.
    ///
    const uint32_t mUdsP4TimeCountInMs = 300000U;

    ///
    /// @brief S3 server time in milliseconds.It is the default value used when there is invalid INI File.
    ///
    const uint32_t mUdsS3TimeCountInMs = 5000U;

    ///
    /// @brief periodic task call time of Uds in milliseconds.It is the default value used when there is invalid
    /// INI File.
    ///
    const uint32_t mUdsCoreMainFunctionPeriodInMs=10U;

    ///
    /// @brief Server source address default value. This value is used when the INI configuration is Invalid.
    ///
    const uint16_t mUdsDiagnosticAddress = 0xE000U;

    ///
    ///
    /// @brief This feature enables the busy repeat request 0x21 response in multi tester connected scenario.
    /// Eg: When diagnostic application process a request from tester tool1 and a new request is triggered by
    /// another(or same tool)  tester tool2 a busy repeat request 0x21 response is sent to tool2 and then a reponse
    /// would be sent to diagnostic tool.
    ///
    /// Value :
    ///       -# true - feature disabled
    ///       -# false - feature enabled.
    ///
    const bool mBusyResponseForMultiRequestSupport = false;

    ///
    /// @brief It is the Reference to the CUdsCore.CUdsCore is created in onInit method and this holds the reference
    ///        to it. The CUdsCore instance would be deleted in onInit method.
    ///
    CUdsCore   *mpUdsCoreInst = nullptr;

    ///
    /// @brief It is the Reference to the UdsDoIp.UdsDoIp is created in onInit method and this holds the reference
    ///        to it. The CUdsCore instance would be deleted in onInit method.
    ///
    CUdsTpIf     *mpUdsTpIfInst = nullptr;

    ///
    ///@brief It is the Reference to the ParserIf. This is used to read INI files to update Uds Core configurations.
    ///
    dk::runtime::core::ParserIf mUdsCoreParser;

    ///
    /// @brief This method is used to read the configuration from the INI .
    ///
    void udsCoreIniHandler(void);

    ///
    /// @brief This method is used to invoke the CUdsCore periodic task.This method is registered in onInit method with
    ///        the configurable time from INI file.
    ///
    void udsPeriodicTask(void);

/// End of user code
};

} // udscore
} // srvc
} // dk

#endif //C_UDS_CORE_COMP_H

