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
/// @file dk_srvc_uds_service_manager.h
/// @ingroup UdsBlServices
///
/// @brief  CUdsServiceManager Class.It implements the common interface which are accessed by
///         the Uds Service Handlers. It handles the service request, response transmission and invoking
///         post processing tasks.
/// It provides the infrastructure for
///  -# Checking the validity of an incoming diagnostic request (Verification of Diagnostic Session/Security
///     Access levels/Application permission) and keeps track of the progress of a service request execution.
///  -# Assembling Positive and Negative responses.
///  -# Initiate transmission of responses to UdsCore.
///  -# Handling of suppressed response.
///  -# Handling multi diagnostic mode support.
///  -# Dispatching the received request to the respective service handlers.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_SERVICE_MANAGER_H
#define DK_SRVC_UDS_SERVICE_MANAGER_H
#include <cstdint>
#include <map>
#include "dk_srvc_uds_service_manager_if.h"
#include "dk_runtime_bl_einstein_uds_app_component.h"


namespace dk
{
namespace app
{
namespace udsblservices
{

class CUdsServiceManager : public CUdsServiceManagerIf
{
public:
    ///
    /// @brief This defines the type of address modes.
    ///
    typedef enum
    {
        EAddressMode_FotaClient=0U,    ///< address of FOTA client.
        EAddressMode_DiagClient,  ///< address of Diagnostic client.
        EAddressMode_Last           ///< Guard
    } EAddressMode_t;

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
    );

    ///
    /// @brief This method is used to map the service Id with its instances for each mode.
    ///         This method should be used by each service to register with service Manager.
    ///
    /// @param[in] serviceTableId It defines the service table index value to which the service handler is registered .
    /// @param[in] serviceId It is a 1 byte unique value used to represent UDS service.
    /// @param[in] pServiceConfig pointer to service configuration.
    ///
    virtual void addServiceHandler
    (
        const CUdsServiceManagerIf::EServiceTableId_t serviceTableId,
        const uint8_t serviceId,
        const CUdsServiceHandlerIf::SServiceConfig_t * const pServiceConfig
    );

    ///
    /// @brief This method is used to get the current security level
    ///
    /// @return ESecurityLevel_t Current security level.
    ///
    virtual CUdsServiceHandlerIf::ESecurityLevel_t getCurrentSecurityLevel(void);

    ///
    /// @brief This method is used to get the current session level
    ///
    /// @return ESessionType_t Current session level.
    ///
    virtual CUdsServiceHandlerIf::ESessionType_t   getCurrentSession(void);

    ///
    /// @brief This method is used to set the current session level
    ///
    /// @param[in] session Current session level.
    ///
    virtual void setCurrentSession(const CUdsServiceHandlerIf::ESessionType_t session);

    ///
    /// @brief This method is used to set the current security level
    ///
    /// @param[in] securityLevel security level to be set.
    ///
    virtual void setCurrentSecurityLevel(const CUdsServiceHandlerIf::ESecurityLevel_t securityLevel);

    ///
    /// @brief This method is used to send Negative response
    ///
    /// @param[in] nrc Negative response code to be sent
    ///
    virtual void sendNegativeResponse(const uint16_t clientAddress,const CUdsServiceHandlerIf::EResponseCode_t nrc);

    ///
    /// @brief This method handles the session time-out.
    ///
    virtual void sessionTimeout(void);

    ///
    /// @brief This method is used to handle the service time-out.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    virtual void serviceTimeout(const uint16_t clientAddress);

    ///
    /// @brief This method is the initialization routine for CUdsServiceManager
    ///
    void onInit(void);

    ///
    /// @brief This method is the CUdsServiceManager periodic task.
    /// It shall be scheduled periodically with the configured value.
    /// It is responsible for Uds Service Manager state handling.
    ///
    void periodicTask(void);

    ///
    /// @brief This method should be invoked on the when the transmit confirmation status is received from Uds core .
    ///         layer
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] responseType It defines the response type of the transmit request.
    ///
    void serviceTransmitConfirmation(const uint16_t clientAddress, const CUdsServiceManagerIf::EResponseType_t responseType);

    ///
    /// @brief This method should be invoked when a diagnostic request is received from the UdsCore layer.
    /// This method is responsible for Uds Service Manager state handling.
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] requestType address type of the requested client address.
    /// @param[in] requestDatalength size of requested data length
    /// @param[in] pRequestDataBuffer pointer to the requested buffer.
    ///
    void serviceRequestHandler
    (
        const uint16_t clientAddress,
        const uint8_t requestType,
        const uint16_t requestDatalength,
        const uint8_t * const pRequestDataBuffer
    );

    ///
    /// @brief This method is used to update the list of supported address for different modes.
    ///
    /// @param[in] addressList list of supported address.
    /// @param[in] mode mode supported by the address list.
    ///
    void setDiagnosticModeAddress(const std::vector<uint16_t> &addressList,const CUdsServiceManager::EAddressMode_t mode);

private:
    ///
    /// @brief It defines the type of diagnostic mode. PZ1A has two modes FOTA mode and Diagnostic mode.
    ///
    typedef enum
    {
        EDiagnosticMode_FotaMode=0U,   ///< FOTA mode.
        EDiagnosticMode_DiagMode,     ///< Diag mode.
        EDiagnosticMode_Last          ///< Guard.
    } EDiagnosticMode_t;

    ///
    /// @brief This defines the state of Uds Service Manager.
    ///
    typedef enum
    {
        EDiagServiceManagerState_WaitingForRequest=0U, ///< This defines the waiting for request state.
        EDiagServiceManagerState_ProcessingReceivedRequest,///< This defines the processing received request state.
        EDiagServiceManagerState_WaitingForResponse,///< This defines the waiting for response state
        EDiagServiceManagerState_Last ///< Guard
    } EDiagServiceManagerState_t;

    ///
    /// @brief This holds the current status of the received diagnostic request.
    ///
    typedef struct
    {
        uint8_t mAddressType;    ///< requested address type.
        uint8_t mServiceId;      ///< requested service ID.
        uint8_t mResponseType;   ///< response type for the current request.
        uint16_t mClientAddress; ///< requested client address.
        EDiagServiceManagerState_t mDiagServiceManagerState; ///< request processing state.
        std::vector<uint8_t> mData;
    } SDiagnosticDataBufferControl_t;

    ///
    /// @brief It is the dataType for the service manager buffer . It has client address as "key" and the status of
    /// the received type.
    ///
    typedef std::map<uint16_t,SDiagnosticDataBufferControl_t> DiagnosticDataBufferControl_t;

    ///
    /// @brief This is the map type definition for service Handler . This is used to map the service Id and service
    ///        handler instance reference.
    //
    typedef std::map<uint8_t,CUdsServiceHandlerIf::SServiceConfig_t> ServiceHandlerConfiguration_t;

    ///
    /// @brief This contains the current list of diagnostic request received.
    ///
    DiagnosticDataBufferControl_t mDiagnosticDataBufferControl;

    ///
    /// @brief This contains the list of supported diagnostic mode address.
    ///
    std::vector<uint16_t> mDiagModeAddress;

    ///
    /// @brief This contains the list of supported fota mode address.
    ///
    std::vector<uint16_t> mFotaModeAddress;

    ///
    /// @brief This defines the time-out value for staying in the diagnostic mode.
    ///
    const uint32_t   mDiagnosticModeTimeCountInMs = 5000U;

    ///
    /// @brief Timer for handling the diagnostic mode.
    ///
    uint32_t   mDiagnosticModeTimer;

    ///
    /// @brief This holds the service configuration of each mode . This is updated whenever the service handler
    ///        registers with service manager.
    ///
    ServiceHandlerConfiguration_t mServiceHandlerConfiguration[EServiceTableId_Last];

    ///
    /// @brief This defines the current session of Diagnostic.
    ///
    CUdsServiceHandlerIf::ESessionType_t mCurrentSession;

    ///
    /// @brief This defines the current security level of Diagnostic.
    ///
    CUdsServiceHandlerIf::ESecurityLevel_t   mCurrentSecurityLevel;

    ///
    /// @brief This defines the current Diagnostic mode.
    ///
    CUdsServiceManager::EDiagnosticMode_t   mCurrentDiagnosticMode;

    ///
    /// @brief This defines the current service table index.
    ///
    CUdsServiceManagerIf::EServiceTableId_t   mCurrentServiceTableId;
    ///
    /// @brief This defines Suppress flag.
    ///
    uint8_t mIsSuppressReqForSession =0;
    ///
    /// @brief This defines the temp variable for client address.
    ///
    uint16_t mCacheClientAddr =0;

    ///
    /// @brief This method handles the Uds Service Manager state
    ///
    /// The Uds Service Manager has the following states,
    ///     1.EDiagServiceManagerState_WaitingForRequest (waiting for Request)
    ///     2.EDiagServiceManagerState_ProcessingReceivedRequest (processing received request)
    ///     3.EDiagServiceManagerState_WaitingForResponse (waiting for response)
    /// State transition:
    ///  Initial------------------>EDiagServiceManagerState_WaitingForRequest ----------------
    ///                                  ^                               ^                   |
    ///                                  |                               |                   |
    ///                                  |                               |                   v
    ///    EDiagServiceManagerState_WaitingForResponse <------------EDiagServiceManagerState_ProcessingReceivedRequest
    ///
    /// -# EDiagServiceManagerState_WaitingForRequest:
    ///         This is the initial state. In this state Uds Service Manager would accept new service request,process
    ///         transmit confirmation and invoke the post processing tasks.
    ///         Entry:
    ///              1. During CUdsServiceManager Initialization.
    ///              2. When session or service time-out occurs in any state.
    ///         Exit:
    ///             1.When a new service request is received,state changed to
    ///                 EDiagServiceManagerState_ProcessingReceivedRequest
    /// -# EDiagServiceManagerState_ProcessingReceivedRequest
    ///         This state is transitioned from the EDiagServiceManagerState_WaitingForRequest when a new request is
    ///         received .In this state the received request would be processed and if valid request present the it
    ///         would be notified to service layer.
    ///         Entry:
    ///             1.When a new service request is received,state changed to
    ///                 EDiagServiceManagerState_ProcessingReceivedRequest
    ///         Exit:
    ///             1. If a valid request is present , then state changed to
    ///                 EDiagServiceManagerState_WaitingForResponse to wait for service handler reponse.
    ///             2.If service or session time-out occurs then,state changed to
    ///                 EDiagServiceManagerState_WaitingForRequest
    /// -# EDiagServiceManagerState_WaitingForResponse:
    ///         In this state the CUdsServiceManager would wait for the response from Uds Service handlers and if a
    ///         valid response transmit request is provided , it would be transmitted to the UDS core.
    ///         Entry:
    ///             1.When a valid request is processed in EDiagServiceManagerState_ProcessingReceivedRequest state
    ///                 changed to EDiagServiceManagerState_WaitingForResponse
    ///         Exit:
    ///             1. If a valid response transmit request is provided by service handler , then the state changes to
    ///                 EDiagServiceManagerState_WaitingForRequest.
    ///             2. If service or session time-out occurs then,state changed to
    ///                 EDiagServiceManagerState_WaitingForRequest
    ///
    void serviceManagerStateProcessing(void);

    ///
    /// @brief This method is used to update the current diagnostic mode.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    void updateDiagnosticMode(const CUdsServiceManager::EDiagnosticMode_t mode);

    ///
    /// @brief This method validates if a request is already in progress for the requested client address.
    ///
    /// @param[in] clientAddress requested client address.
    ///
    bool isRequestInProgress(const uint16_t clientAddress);

    ///
    /// @brief This method validates the OEM specific condition to accept the requested service.
    ///
    /// @param[in] clientAddress requested client address.
    /// @param[in] serviceId requested service identifier.
    ///
    bool oemRequestConditionCheck(const uint16_t clientAddress,const uint8_t serviceId);


};

} // udsblservices
} // app
} // dk

#endif  //DK_SRVC_UDS_SERVICE_MANAGER_H




