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
/// @file dk_srvc_uds_service_tester_present_handler.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceSessionManagementHandler Class. It implements the the tester present handler service 0x3E.
///
/// This service is used to indicate to a server that a client is still connected to the vehicle and that certain 
/// diagnostic services and/or communication that have been previously activated are to remain active.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_TESTER_PRESENT_HANDLER_H
#define DK_SRVC_UDS_SERVICE_TESTER_PRESENT_HANDLER_H
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_srvc_uds_service_manager_if.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
    
class CUdsServiceTesterPresentHandler : public CUdsServiceHandlerIf
{
public:
    /// 
    /// @brief Constructor of CUdsServiceTesterPresentHandler.
    ///
    /// param[in]  reference of serviceManager instance
    ///
    explicit CUdsServiceTesterPresentHandler
    (
        CUdsServiceManagerIf &serviceManagerInstance
    ):mServiceManagerInstance(serviceManagerInstance)
    {
        
    }
    
    /// 
    /// @brief Destructor of CUdsServiceTesterPresentHandler.
    ///
    ~CUdsServiceTesterPresentHandler()
    {
        
    }
    
	///
    /// @brief This method is the tester present Handler service handler initialization routine.This method should be 
    ///        invoked by UDS service Manager on Init . 
    ///
    virtual void serviceInitialize(void);
        
private:
    
    ///
    /// @brief It defines the tester present request data length.
    ///
    const uint8_t mUdsTesterPresentRequestLength = 0x1U;
    
    ///
    /// @brief It defines the sub function value supported by tester present service.
    ///
    const uint8_t mUdsTesterPresentSubFunction = 0x00U;
    
    ///
    /// @brief It defines the tester present service configurations.
    ///
    SServiceConfig_t mTesterPresentServiceConfig;
    
    ///
    /// @brief It defines the service configurations.
    /// 
    CUdsServiceManagerIf  &mServiceManagerInstance;
    
    ///
    /// @brief This method handles the tester present request . The method should be set as request handler callback 
    ///        function for tester present service.This method updates positive or negative response based on the
    ///        request . 
    /// @param[in] clientAddress requested client address.
    /// @param[in] pRequestData  pointer to request data length
    /// @param[in] requestLength size of the requested data.
    ///
    void testerPresentRequestHandler(const uint16_t clientAddress,const uint8_t * const pRequestData,const uint16_t requestLength);
    
    ///
    /// @brief This method handles the post response functionality of tester present service.This method is 
    ///         configured as post response handler callback  function for tester present service.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void testerPresentPostresponseHandler(const uint16_t clientAddress);
    
    ///
    /// @brief This method handles the reset handler of tester present service.This method will set internal status to
    ///        initial value.This method is configured as reset handler callback function for tester present service.
    ///
    /// @param[in] clientAddress requested client address.
    /// 
    void testerPresentResetHandler(const uint16_t clientAddress);
    
};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_TESTER_PRESENT_HANDLER_H
