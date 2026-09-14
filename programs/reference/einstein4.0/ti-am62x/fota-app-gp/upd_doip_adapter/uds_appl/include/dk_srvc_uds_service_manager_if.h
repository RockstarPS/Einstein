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
/// @file dk_srvc_uds_service_manager_if.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceManagerIf Class. It is an interface class.It defines the common interface which are accessed by 
///         the Uds Service Handlers.The CUdsServiceManager class implements these methods.
/// It provides API for 
///  -# Uds Service handler to update response data to transmit to UdsCore.
///  -# Uds Service handlers to get current session and current security Level.
///  -# Uds service handlers to initializes its configuration to CUdsServiceManager.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_MANAGER_IF_H
#define DK_SRVC_UDS_SERVICE_MANAGER_IF_H
#include <cstdint>
#include "dk_srvc_uds_service_handler_if.h"
#include "dk_logger.h"

namespace dk
{
namespace app
{
namespace udsblservices
{
    
class CUdsServiceManagerIf
{
public:
    ///
    /// @brief It defines the type of responses to be sent to Uds Core.This type values should match with response type
    ///        defined in UdsCore class.
    ///
    typedef enum
    {
        EResponse_Rcrrp=0U,  ///< NRC 78 RCRRP response type.
        EResponse_BusyNRC,  ///< NRC 21 Busy repeat request negative response type.In Uds Services this type should not
                            /// used. As this type is to handle multiple tester.
        EResponse_Negative, ///< Negative response.
        EResponse_Suppress, ///< Suppressed response . No response to be sent.
        EResponse_Positive, ///< Positive response. 
        EResponse_Last      ///< Guard.
    }EResponseType_t;
        
    ///
    /// @brief It defines the type of supported service list for different protocol. This value is used as key for the 
    /// service list map for different protocols such as OBD ,enhanced diagnostics.
    ///
    typedef enum
    {
        EServiceTableId_Uds=0U, ///< UDS service table list  
        EServiceTableId_Last    ///< Guards
    }EServiceTableId_t;
    
    ///
    /// @brief This method should be invoked when a diagnostic service handler needs to update the reponse to the core.
    ///        
    /// @param[in]  clientAddress requested client address.
    /// @param[in]  responseType type of responses to be sent to Uds Core.
    /// @param[in]  responseData reference of response data to be transmitted.
    ///
    virtual void serviceResponseUpdate
    (
        const uint16_t clientAddress,
        const CUdsServiceManagerIf::EResponseType_t responseType,
        const std::vector<uint8_t> &responseData
    )=0;
    
    ///
    /// @brief This method is used to map the service Id with its instances for each service table.
    ///         This method should be used by each service to register with service Manager.
    ///
    /// @param[in] serviceTableId It defines the service table index value to which the service handler to be registered.
    /// @param[in] serviceId It is a 1 byte unique value used to represent UDS service.
    /// @param[in] pServiceConfig pointer to service configuration.
    ///    
    virtual void addServiceHandler
    (
        const CUdsServiceManagerIf::EServiceTableId_t serviceTableId, 
        const uint8_t serviceId,
        const CUdsServiceHandlerIf::SServiceConfig_t  * const pServiceConfig
    )=0;
                                            
    ///
    /// @brief This method is used to get the current security level
    ///
    /// @return ESecurityLevel_t Current security level.
    ///
    virtual CUdsServiceHandlerIf::ESecurityLevel_t getCurrentSecurityLevel(void)=0;
    
    ///
    /// @brief This method is used to set the current security level
    ///
    /// @param[in] securityLevel security level to be set.
    ///
    virtual void setCurrentSecurityLevel(const CUdsServiceHandlerIf::ESecurityLevel_t securityLevel)=0;
    
    ///
    /// @brief notify current session
    ///
    /// @param[in] session session changes 
    ///
    virtual void setCurrentSession(const CUdsServiceHandlerIf::ESessionType_t session)=0;
    
    
    ///
    /// @brief This method is used to get the current session level
    ///
    /// @return ESessionType_t Current session level.
    ///
    virtual CUdsServiceHandlerIf::ESessionType_t   getCurrentSession(void)=0;
    
    ///
    /// @brief This method is used to send Negative response
    ///
    /// @param[in] nrc Negative response code to be sent
    /// 
    virtual void sendNegativeResponse(const uint16_t clientAddress,const CUdsServiceHandlerIf::EResponseCode_t nrc)=0;
    
    ///
    /// @brief This method handles the session time-out.
    ///
    virtual void sessionTimeout(void)=0;
    
    /// 
    /// @brief This method is used to handle the service time-out.
    ///
    /// @param[in]  clientAddress requested client address.
    /// 
    virtual void serviceTimeout(const uint16_t clientAddress)=0;

    ///
    /// @brief This method is used to check if security level is ok
    ///
    /// @arg ESecurityMask_t permitted security level to be checked
    ///
    /// @return boolean. True if ECU is unlocked (security is ok)
    ///
    virtual bool isPermmitedBySecurityLevel(CUdsServiceHandlerIf::ESecurityMask_t permittedSecurity)=0;



};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_MANAGER_IF_H
