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
//---------------------------------------------------------------------------------------------------------------------
///
/// @file dk_srvc_uds_service_ecu_reset_handler.h
/// @ingroup UdsServices
///
/// @brief  CUdsServiceEcuResetHandler Class. It implements the the ECU reset handler service 0x11.
///
/// This service requests the server to effectively perform a server reset based on the content of the resetType
/// parameter value embedded in the ECUReset request message. The ECUReset positive response message (if
/// required) shall be sent before the reset is executed in the server(s). After a successful server reset the server
/// shall activate the defaultSession.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_ECU_RESET_HANDLER_H
#define DK_SRVC_UDS_SERVICE_ECU_RESET_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"
///#include "dk_runtime_c_uds_bl_service_manager_comp.h"
#include "dk_runtime_uds_appl_component.h"

namespace dk
{
namespace app
{
namespace udsblservices
{

class CUdsServiceEcuResetHandler : public CUdsServiceHandlerIf
{
public:    
	///
    /// @brief This method is the ECU reset service handler initialization routine.This method should be 
    ///        invoked by UDS service Manager on Init . 
    ///
    void serviceInitialize(void);
    
    ///
    /// @brief This method is used to set the UDS service Manager instance reference for the ECU reset  
    ///        service handler.
    ///
    /// @param[in] pUdsServiceManagerIf pointer to the UDS service manager Instance.
    ///
    explicit CUdsServiceEcuResetHandler
       (
           CUdsServiceManagerIf &serviceManagerInstance
       ):mpServiceManagerInstance(serviceManagerInstance)
       {

       }
    ~CUdsServiceEcuResetHandler()
       {

       }
    //void setServiceManagerIf(CUdsServiceManagerIf * pUdsServiceManagerIf);
    
private:
    ///
    /// @brief It defines the ECU reset flag .
    ///
    uint8_t mEcuResetFlag = 0;
    
    ///
    /// @brief It defines the ECU reset request data length.
    ///
    const uint8_t mUdsEcuResetRequestLength = 0x1u;
    
    ///
    /// @brief It defines the sub function value supported by ECU reset service.
    ///
    const uint8_t mUdsEcuResetSubFunction = 0x01;
    
    ///
    /// @brief It defines the ECU reset service configurations.
    ///
    SServiceConfig_t mEcuResetServiceConfig;
    
    ///
    /// @brief It defines the service configurations.
    /// 
    //CUdsServiceManagerIf * mpServiceManagerInstance;
    CUdsServiceManagerIf &mpServiceManagerInstance;
    
    ///
    /// @brief This method handles the ECU reset request . The method should be set as request handler callback 
    ///        function for ECU reset service.This method updates positive or negative response based on the
    ///        request . 
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength  size of the requested data.
    ///
    void ecuResetRequestHandler(const uint16_t clientAddress, const uint8_t * const pRequestData,uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of ECU reset service.This method is 
    ///         configured as post response handler callback  function for ECU reset service.
    ///
    void ecuResetPostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of ECU reset service.This method will set internal status to
    ///        initial value.This method is configured as reset handler callback function for ECU reset service.
    ///
    void ecuResetResetHandler(const uint16_t clientAddress);
    
};

} // udsblservices
} // app
} // dk
#endif  //DK_SRVC_UDS_SERVICE_ECU_RESET_HANDLER_H
