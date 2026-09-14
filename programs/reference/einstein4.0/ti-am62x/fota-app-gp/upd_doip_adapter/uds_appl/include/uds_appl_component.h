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
#ifndef UDS_APPL_COMPONENT_H
#define UDS_APPL_COMPONENT_H

/// Start of user code : User code for file c_uds_service_manager.h

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_uds_appl_component.h"
#include "dk_runtime_parserif.h"
#include "dk_srvc_uds_service_manager.h"
#include "dk_srvc_uds_service_session_management_handler.h" 
#include "dk_srvc_uds_service_download_handler.h"
#include "dk_srvc_uds_service_tester_present_handler.h"
#include "dk_srvc_uds_service_data_identifier_handler.h"
#include "dk_srvc_uds_service_security_access_handler.h"
#include "dk_srvc_uds_service_routine_control_handler.h"
#include "dk_srvc_uds_service_dtc_handler.h"
#include "dk_srvc_uds_service_ecu_reset_handler.h"
/// End of user code
namespace dk
{
namespace app
{
namespace udsblservices
{
	
using namespace dk::runtime;

class UdsApplComponent : public dk::runtime::core::Component
{
public:
    explicit UdsApplComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)
    {
    }

    ~UdsApplComponent()
    {
    }

    bool onInit();
    bool onExit();
    bool onStart();
    bool onStop();
    void worker(void);

    void onReceiveUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation & msg);

    void onReceiveUdsTimeout(UdsTimeout & msg);

    void onReceiveUdsServiceReqIndication(UdsServiceReqIndication & msg);

    void onReceiveUdsInstallerDidResponse(UdsInstallerDidResponse & msg);

    void onReceiveUdsNvmResponse(UdsNvmResponse & msg);

    void onReceiveInstallerFlashStatusNotification(InstallerFlashStatusNotification & msg);

    void onReceiveInstallerUdsVerifyResp(InstallerUdsVerifyResp & msg);

    void onReceiveBlGipDiagResponse(BlDiagResponse & msg);

	void onReceiveBlVipDiagRequest(BlDiagRequest & msg);

private:
/// Start of user code : User code for file uds_appl_component.h
  ///   
    /// @brief It is the path location of INI file. This path will be searched first for INI file.
    ///
    //const std::string mUdsBlServicesIniFilePath1 = "/tmp/uds_services.ini";
    const std::string mUdsBlServicesIniFilePath1 = "/etc/uds_services.ini";
    
    ///   
    /// @brief It is the path location of INI file. This path will be searched for INI file if the file not found in
    ///        mUdsBlServicesIniFilePath1.
    ///
    const std::string mUdsBlServicesIniFilePath2 = "/etc/uds_services.ini";
    
    ///
    /// @brief This defines the default period(in ms) of Uds Service Manager Main function task.This value is 
    ///  configurable via INI file.
    ///
    const uint32_t mUdsServiceManagerMainFunctionPeriodInMs = 10U;
    
    ///
    /// @brief Instance of CUdsServiceManager 
    ///
    CUdsServiceManager  mUdsServiceManagerInstance;
    
    ///
    /// @brief Instance of DiagnosticSessionControl service  handler  
    ///
    CUdsServiceSessionManagementHandler  mUdsServiceSessionManagementHandlerInstance = \
                                CUdsServiceSessionManagementHandler(mUdsServiceManagerInstance);
                
    ///
    ///@brief Instance of Request downloads service handler.
    ///
    CUdsServiceDownloadHandler mUdsServiceDownloadHandlerInstance = \
                                CUdsServiceDownloadHandler(mUdsServiceManagerInstance);
    
    ///
    ///@brief Instance of tester present service handler.
    ///
    CUdsServiceTesterPresentHandler mUdsServiceTesterPresentHandlerInstance = \
                                CUdsServiceTesterPresentHandler(mUdsServiceManagerInstance);
    
    ///
    ///@brief Instance of data identifier service handler.
    ///
    CUdsServiceDataIdentifierHandler mUdsServiceDataIdentifierHandlerInstance = \
                            CUdsServiceDataIdentifierHandler(mUdsServiceManagerInstance);

    ///
    ///@brief Instance of dtc service handler.
    ///
    CUdsServiceDtcHandler mUdsServiceDtcHandlerInstance = \
    		CUdsServiceDtcHandler(mUdsServiceManagerInstance);

    ///
    ///@brief Instance of data identifier service handler.
    ///
    CUdsServiceSecurityAccessHandler mUdsServiceSecurityAccessHandlerInstance = \
    						CUdsServiceSecurityAccessHandler(mUdsServiceManagerInstance);

    ///
    ///@brief Instance of Routine Control service handler.
    ///
    CUdsServiceRoutineControlHandler mUdsServiceRoutineControlHandlerInstance = \
    		CUdsServiceRoutineControlHandler(mUdsServiceManagerInstance);

    ///
	///@brief Instance of ECU Reset service handler.
	///
    CUdsServiceEcuResetHandler mUdsServiceEcuResetHandlerInstance = \
    		CUdsServiceEcuResetHandler(mUdsServiceManagerInstance);

    ///
    ///@brief It is the Reference to the ParserIf. This is used to read INI files to update Uds Service configurations.
    ///
    dk::runtime::core::ParserIf mUdsServiceManagerParser;
    
    ///
    /// @brief This method is used to read the configuration from the INI .
    /// 
    void iniHandler(void);
    
    ///
    /// @brief This method is used to invoke the CUdsServiceManager periodic task.This method is registered in onInit 
    ///        method with the configurable time from INI file and this method is called periodically with the 
    ///        configured time.
    ///
    void periodicTask(void);
	
	
	void onReceiveVIPResponseHandler(const uint8_t responseCode, uint16_t msgID, uint8_t *pMsg);
/// End of user code
};

}
}
}


#endif //UDS_APPL_COMPONENT_H

