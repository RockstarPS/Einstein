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
#ifndef BMW_UDS_APPL_COMPONENT_H
#define BMW_UDS_APPL_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_eins_uds_appl_component.h"
#include "dk_srvc_uds_service_data_identifier_handler.h"
#include "dk_srvc_uds_service_session_management_handler.h"
#include "dk_srvc_uds_service_io_control_handler.h"
#include "dk_srvc_uds_service_routine_control_handler.h"
#include "dk_srvc_uds_service_download_handler.h"
#include "dk_srvc_uds_service_manager.h"
#include "dk_runtime_parserif.h"
#include "dk_srvc_uds_service_ecu_reset_handler.h"



namespace dk
{
namespace app
{
namespace udsblservices
{


using namespace dk::runtime;


class EinsUdsApplComponent : public dk::runtime::core::Component
{
public:
    explicit EinsUdsApplComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~EinsUdsApplComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveUdsServiceReqIndication(UdsServiceReqIndication const & msg);

    void onReceiveUdsTimeout(UdsTimeout const & msg);

    void onReceiveUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation const & msg);

    void onReceiveGipDiagResponse(GipDiagResponse const & msg);
	
	void onReceiveDoIPDownloadResponse(DoIPDownloadResponse const  & msg);

private:


    ///< Start of user code : User code for file bmw_uds_appl_component.h

    CUdsServiceManager  mUdsServiceManagerInstance;

    CUdsServiceSessionManagementHandler  mUdsServiceSessionManagementHandlerInstance = \
            CUdsServiceSessionManagementHandler(mUdsServiceManagerInstance);

    CUdsServiceIOControlHandler  mUdsServiceIOControlHandlerInstance  = \
            CUdsServiceIOControlHandler(mUdsServiceManagerInstance);

    CUdsServiceDataIdentifierHandler  mUdsServiceDataIdentifierHandlerInstance  = \
            CUdsServiceDataIdentifierHandler (mUdsServiceManagerInstance);

    CUdsServiceRoutineControlHandler  mUdsServiceRoutineIdentifierHandlerInstance  = \
            CUdsServiceRoutineControlHandler (mUdsServiceManagerInstance);
    CUdsServiceEcuResetHandler  mUdsServiceEcuResetHandlerInstance  = \
            CUdsServiceEcuResetHandler (mUdsServiceManagerInstance);
	CUdsServiceDownloadHandler  mUdsServiceDownloadHandlerInstance = \
			CUdsServiceDownloadHandler (mUdsServiceManagerInstance);
    ///< End of user code

    dk::runtime::core::ParserIf mUdsServiceManagerParser;

    const std::string mUdsBlServicesIniFilePath1 = "/system/etc/uds_services.ini";

    ///
    /// @brief It is the path location of INI file. This path will be searched for INI file if the file not found in
    ///        mUdsBlServicesIniFilePath1.
    ///
    const std::string mUdsBlServicesIniFilePath2 = "/etc/uds_services.ini";

    const uint32_t mUdsServiceManagerMainFunctionPeriodInMs = 10U;


    void iniHandler();

    void periodicTask(void);

};

} // udsblservices
} // app
} // dk

#endif //BMW_UDS_APPL_COMPONENT_H

