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
/// @file dk_srvc_uds_core.h
/// @ingroup UDSCore
///
/// @brief  CUdsCore Class. CUdsCore implements the server part of ISO 14299-2 Unified diagnostic services(UDS)-Part 2:
///         Session layer services.
/// CUdsCore implements server part of the ISO 14299-2 Unified diagnostic services (UDS)—Part 2: Session layer services.
/// The CUdsCore implements the session state handling,application layer timing handling ,Request and Response handling.
/// It provides infrastructure for
///         * Handling of application layer timing parameters.
///         * Modifying the application layer timing parameters.
///         * Forwards diagnostic request from the TP layer to the Diagnostic services.
///         * Forwards diagnostic response from Diagnostic services to TP.
///         * Error Handling.
///         * Handling of Diagnostic request connection(Only one request is processed at a time).
///         * Handling of RCRRP NRC 78 response transmission.
///
/// Application timing parameters for UDS server:
/// -# P2Server :Performance requirement for the server to start with the response message after the reception of a
///   request message.
/// -# P2*Server :Performance requirement for the server to start with the response message after the transmission of a
///     negative response message with negative response code 0x78.
/// -# P4Server : This is the time between the reception of a request and the start of the
///     transmission of the final response at the server side.
/// -# S3Server : Time for the server to keep a diagnostic session other than the defaultSession active while not
///     receiving any diagnostic request message.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_SRVC_UDS_CORE_H
#define DK_SRVC_UDS_CORE_H
#include <cstdint>
#include "dk_srvc_uds_core_if.h"
#include "dk_runtime_uds_core_component.h"
namespace dk
{
namespace srvc
{
namespace udscore
{

class CUdsCore : public CUdsCoreIf
{
public:
    ///
    /// @brief Type of service responses.
    ///
    typedef enum
    {
        EResponse_Rcrrp=0U,  ///< NRC 78 RCRRP response type.
        EResponse_BusyNRC,  ///< NRC 21 Busy repeat request negative response type.In Uds Services this type should not
        /// used. As this type is to handle multiple tester connection.
        EResponse_Negative, ///< Negative response.
        EResponse_Suppress, ///< Suppressed response . No response to be sent.
        EResponse_Positive, ///< Positive response.
        EResponse_Last      ///< Guard
    } EResponseType_t;

    ///
    /// @brief  Timer ID for UDS timers. This is used as the reference ID to the UDS timer and used to configure with
    ///         CUdsTimer Class.
    ///
    typedef enum
    {
        EUdsTimeoutType_SessionTimeout=0U, ///< Indicates session time-out.
        EUdsTimeoutType_ServiceTimeout,    ///< Indicates service time-out.
        EUdsTimeoutType_Last,    ///< Guard.
    } EUdsTimeoutType_t;

    ///
    /// @brief Uds configuration structure . It contains the timing configuration of UDS layer.
    ///
    typedef struct
    {
        uint32_t mP2TimeCountInMs;              ///< P2 server time in milliseconds. Inter message Request to
        /// response time gap time out value.
        uint32_t mP2StarTimeCountInMs;          ///< P2star server time count in milliseconds . It defines the time
        /// between two consecutive RCRRP responses.
        uint32_t mP4TimeCountInMs;              ///< P4 server time in milliseconds. It defines the maximum time to
        /// transmit a final response i.e. Positive or negative response
        /// (not RCRRP).  If also defines the maximum duration of RCRRP 0x78
        /// response transmission.
        uint32_t mS3TimecountInMs;              ///< Session time-out in milliseconds. It defines the time to keep a
        /// diagnostic session other than default session, active.
        uint32_t mUdsMainFunctionPeriodInMs;    ///< It defines the periodic task call time of Uds in milliseconds.
        bool  mUdsBusyResponseForMultiRequestSupport; ///< It defines whether the busy response NRC 0x21 for multi
        ///< request is supported or not.
        uint16_t mDtoolAddress;
        uint16_t mRdiagAddress;
        uint16_t mFtoolAddress;
    } SUdsCoreConfig_t;

    ///
    /// @brief Constructor of CUdsCore Class
    /// @param  udsCoreConfig Uds configuration structure . It contains the timing configuration of UDS layer.
    ///
    CUdsCore(const SUdsCoreConfig_t udsCoreConfig):mUdsCoreConfig(udsCoreConfig)
    {

    }

    ///
    /// @brief Destructor of CUdsCore Class .
    ///
    ~CUdsCore()
    {

    }

    ///
    /// @brief CUdsCore Component Init.
    /// This function shall be invoked to initialize CUdsCore Component & its associated instances.
    /// This method handles the timer configuration for the Uds timings
    ///
    void onInit(void);

    ///
    /// @brief CUdsCore Component finalization routine.
    /// This function shall be invoked to finalize CUdsCore Component & its associated instances.
    ///
    void onExit(void);

    ///
    /// @brief CUdsCore periodic task
    /// This method shall be scheduled periodically with the configured value.
    /// This method handles the following functionality
    /// -# Uds Request Handling
    /// -# Uds Response Transmission Handling
    /// -# Uds Response Conformation Handling
    ///
    void diagnosticMainFunction(void);

    ///
    /// @brief This method handles the transmission request from UDS Services.
    /// This method handles the transmission of diagnostic response . It checks for the type of responses.
    /// If the type of responses are EResponse_Positive or EResponse_Negative response then the response data is copied
    /// and the transmission is triggered in diagnosticMainFunction. If the response type is EResponse_Rcrrp or
    /// EResponse_BusyNRC the transmission is triggered immediately.If the response type is EResponse_Suppress then no
    /// transmission request is triggered and the serviceProcessingDone is invoked.
    ///
    /// @param[in] responseType type of reponse.
    /// @param[in] clientAddress  client address.
    /// @param[in] responseDataLength length of response data.
    /// @param[in] pResponseData  pointer to the response buffer.
    ///
    /// @note EResponse_BusyNRC response type should only be invoked by CUdsCore on processing diagnostic
    /// request. If Uds Service needs to send NRC 0x21 , use EResponse_Negative response type.
    ///
    void updateResponse
    (
        const EResponseType_t responseType,
        const uint16_t clientAddress,
        const uint16_t responseDataLength,
        const uint8_t * const pResponseData
    );

    ///
    /// @brief This method used to restart the Session timer.
    /// This method used to restart the Session timer.This method should be invoked from TP layer on receiving the
    /// tester present request with a functional address. This provides an parallel processing for functionally
    /// addressed tester present service.
    ///
    ///
    virtual void reStartSessionTimer(void);

    ///
    /// @brief This method updates the P2 timer and P2Star timer value.
    /// This method updates the P2 and P2Star time count of CUdsCore .This function should be invoked by session control
    /// service handler to update the timing as per the session configuration.
    ///
    /// @param[in]  p2TimeCountInMs      Maximum P2 time count
    /// @param[in]  p2StarTimeCountInMs  Maximum P2Star time count
    /// @param[in]  p4TimeCountInMs      Maximum P4 time count
    ///
    void setTimingParameters
    (
        const uint32_t p2TimeCountInMs,
        const uint32_t p2StarTimeCountInMs,
        const uint32_t p4TimeCountInMs
    );

    ///
    /// @brief CUdsCore diagnostic request handling.
    /// This method shall be invoked when a successful diagnostic request is received from TP layer.
    /// It validates the request acceptance conditions . If a request is already processed , then the new request is
    /// rejected and a NRC 0x21 is sent to the tester. If no new request is processed then it checks for requested
    /// length with the server supported buffer size.If requested length greater than available buffer size ,then NRC
    /// 0x10 is sent.IF all the cases passes it will copy the requested data to the CUdsCore buffer.
    ///
    /// @param[in] pDataBuffer pointer to data buffer.
    /// @param[in] dataLength length of data buffer.
    /// @param[in] requestType type of request given
    /// @param[in] clientAddress requested client address
    ///
    /// @return boolean true If the request is accepted.
    ///              false If the request is not accepted.
    ///
    virtual bool requestIndication(const uint8_t * const pDataBuffer,const uint16_t dataLength,
                                   const CUdsCoreIf::ERequestType_t requestType,const uint16_t clientAddress);

    ///
    /// @brief This method handles the transmit confirmation from TP.
    /// This method is to invoked by TP layer to confirm the transmission of diagnostic response or the failure to
    /// transmit the diagnostic response.
    ///
    /// @param[in]  transmitStatus status of message transmission .
    ///         -true -  successful transmission
    ///         -false - Failure transmission.
    /// @param[in]  clientAddress requested client address
    ///
    virtual void transmitConfirmation(const bool transmitStatus,const uint16_t clientAddress);

    ///
    /// @brief This method used to set the TP instance for the UDS
    /// This method used to set the TP instance for the UDS. The TP class should inherit from CUdsTpIf Interface.
    ///
    /// @param pUdsTpIf pointer reference to TP instance
    ///
    virtual void setUdsTpIf(CUdsTpIf * const pUdsTpIf);

private:

    ///
    /// @brief  Timer data type for each connection . This is used for each connection response p2 handling timer
    /// handling.
    ///
    typedef struct
    {
        uint32_t mP2Timer; ///< Timer used for handling response time-out  P2Server and P2*Server.
        uint32_t mP4Timer; ///< Timer used for handling maximum response time-out  P4Server.
    } SServiceTimerConfig_t;

    ///
    /// @brief  It defines the state of the diagnostic connection request processing.
    ///
    typedef enum
    {
        EDiagnosticProcesingState_Idle=0U,   ///< Initial state .
        EDiagnosticProcesingState_RxProcessing, ///< Processing the received new diagnostic request.
        EDiagnosticProcesingState_WaitForResponse, ///< wait for the response from the uds service handler.
        EDiagnosticProcesingState_TransmitResponse, ///< Updated response should be transmitted in this state.
        EDiagnosticProcesingState_ResponseConfirmation, ///< Handling of response transmit confirmation.
        EDiagnosticProcesingState_last  ///< Guard
    } EDiagnosticProcesingState_t;

    ///
    /// @brief  It defines the status of each diagnostic connection.
    ///
    typedef struct
    {
        uint8_t mCurrentServiceId;  ///< requested service Id of the connection .
        bool mPendingResponseSupport;    ///< pending response supported for current request.
        EDiagnosticProcesingState_t mCurrentRequestState; ///< request processing state of the connection.
        CUdsCoreIf::ERequestType_t mCurrentRequestType; ///< request type of the connection.
        EResponseType_t mCurrentResponseType; ///< response type of the connection.
        bool mResponsePendingTransmitStatus; ///< response pending transmission status of the connection.
        std::vector<uint8_t> mDataBuffer; ///< request/response data buffer for the connection
        uint8_t mNegativeResponseBuffer[3]; ///< negative response buffer of the connection.
        SServiceTimerConfig_t mServiceTimerConfig; ///< P2 response timer status.
    } SConnectionStatus_t;

    ///
    /// @brief  This is the map dataType for connections.It has clientAddress as "key" and its status as the "value".
    ///
    typedef std::map<uint16_t,SConnectionStatus_t> ConnectionStatusMap_t;

    ///
    /// @brief  It contains the current connection status.
    ///
    ConnectionStatusMap_t mDiagnosticConnection;

    std::mutex mP2P4P2StarTimeoutMutex;
    std::mutex mS3TimeoutMutex;
    ///
    /// @brief It is the timer used for handling S3 time-out.
    ///
    uint32_t mSessionTimer=0U;

    ///
    /// @brief This Negative response code indicates that the requested action has been rejected by the server.
    ///
    const uint8_t mGeneralRejectNegativeResponseCode = 0x10U;

    ///
    /// @brief This NRC indicates that the server is temporarily too busy to perform the requested operation.
    ///
    const uint8_t mBusyRepeatRequestNegativeResponseCode = 0x21U;

    ///
    /// @brief This NRC indicates that the request message was received correctly, and that all parameters in the
    /// request message were valid, but the action to be performed is not yet completed and the server is not yet
    /// ready to receive another request.
    ///
    const uint8_t mRcrrp_Negative_Response_Code = 0x78U;

    ///
    /// @brief It indicates the successful processing of diagnostic request in UDS layer.
    ///
    const uint8_t mNoError = 0x00U;

    ///
    /// @brief It indicates the supported size for processing the diagnostic request.
    ///
    const uint16_t mUdsDiagBufferSizeSupported = 64512U + 512U;

    ///
    /// @brief It contains the CUdsCore configuration.Value needs to be passed when creating Objects of CUdsCore Class.
    ///
    SUdsCoreConfig_t mUdsCoreConfig;

    ///
    /// @brief It contains the reference to the supported TP layer Instance.
    ///
    CUdsTpIf * mpTpInstance=nullptr;

    ///
    /// @brief This method is used to return the connection status of the requested client address.
    ///
    /// @param[in]  clientAddress requested client address
    ///
    /// @return SConnectionStatus_t returns the pointer reference of the connection status if the connection exists for
    /// the requested clientAddress else "nullptr" is returned.
    ///
    CUdsCore::SConnectionStatus_t* getConnectionStatus(const uint16_t clientAddress);

    ///
    /// @brief This method is send the confirmation DK message to the UDS service manager.
    ///
    /// @param[in]  clientAddress requested client address
    ///
    void notifyTransmitConfirmation(const uint16_t clientAddress);

    ///
    /// @brief This method handles the implementation after a successful processing of a request.
    /// This method shall be invoked from response transmit confirmation or when the response type is suppress response.
    /// On successful response transmission , the P2 / P4 /P2Star Timer should be stopped and the S3 timer should be
    /// started.
    ///
    /// @param[in]  clientAddress requested client address
    ///
    void serviceProcessingDone(const uint16_t clientAddress);


    ///
    /// @brief This method provides an interface for start session timer. The S3 timer value is updated from the
    /// mUdsCoreConfig.mS3TimecountInMs .
    ///
    void startSessionTimer(void);

    ///
    /// @brief This method provides an interface for stop session timer.
    ///
    void stopSessionTimer(void);

    ///
    /// @brief This method handles the S3 Timer and notifies the session time-out to UDS service handler.
    ///
    void sessionTimerProcessing(void);

    ///
    /// @brief This method handles updates the negative response for response pending 0x78 and trigger transmission of
    ///  response pending for the requested client Address. Response is send if the connection is valid for the
    ///  requested client Address .
    ///
    /// @param[in]  clientAddress requested client address
    ///
    void sendResponsePending(const uint16_t clientAddress);

    ///
    /// @brief This method handles the service time-out.
    /// On service time-out , the P2 timer is stopped and the final negative response NRC 21 busy repeat request is
    /// transmitted. Service time-out is notified to Uds Service handler.
    ///
    /// @param[in]  clientAddress requested client address
    ///
    void serviceTimeout(const uint16_t clientAddress);
    uint32_t nowTimeMs(void);
};

} // udscore
} // srvc
} // dk

#endif //DK_SRVC_UDS_CORE_H
