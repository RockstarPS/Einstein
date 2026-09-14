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
//-------------------------------------------------------------------------------------------------------------------------
///
/// @file infra_comm_doip_handler.h
/// @ingroup DOIP
///
/// @brief  CDoIPHandler Class. CDoIPHandler DOIP Handler provides the interface to initialize the DOIP stack and Handles the
///         Timeout scenarios (Initial Inactivity Timer, General Inactivity timer and Alive Check response timer).It Process
///         the received DoIP messages(Routing Activation, Diagnostic messages, and Alive Check responses).It supports UDSOnIP
///         DOIP, and SOAD header format.
///         The instance of DOIPHandler can be created by DoIP Component.///
//-------------------------------------------------------------------------------------------------------------------------
#ifndef INFRA_COMM_DOIP_HANDLER_H
#define INFRA_COMM_DOIP_HANDLER_H

#define DOIP_PROTOCOL_VERSION                 2U
#define DOIP_PROTOCOL_INVERSE_VERSION         253U
#define DOIP_PROTOCOL_DEFAULT_VERSION         255U
#define DOIP_PROTOCOL_INVERSE_DEFAULT_VERSION 0U

#include<vector>
#include <map>
#include <string.h>
#include <unistd.h>
#include "infra_comm_doip_soad.h"
#include "infra_comm_doip_cfg.h"
#include "infra_comm_doip_soadCbkIf.h"
#include "dk_runtime_doip_component.h"
#include "infra_comm_doip_timer.h"

#define SOAD_HANDLER_SOCK_INDEX(vlanNo, maxSockPerVlan,sockID)   ((vlanNo * maxSockPerVlan) + sockID)
#define HANDLER_SOAD_VLAN_INDEX(sockID,maxSockPerVlan)         (sockID / maxSockPerVlan )
#define HANDLER_SOAD_SOCK_INDEX(sockID,maxSockPerVlan)         (sockID % maxSockPerVlan )

#ifdef DOIP_IPV6
//Added since it is not supported by DK RTE generation
//After proper API added to DoIP messages and generation support struct can/should be removed
typedef struct
{
    uint16 portNum;
    std::string IPv6Address;
    //std::string MulticastIPv6Address; //Not removed for possible feature actions
} SDoIPSetNetworkInformationIPv6;
#endif

class CDoIPHandler : public CSoAdCallbackIf
{

public:

    CDoIPHandler()
    {
        // mPortNum   = 0;
        //  mIpAddress = "" ;
        mdoIpNoOfSocketsSupported = 0U;
        mdoIpNoOfConcurrentSrcAddrSupported = 0U; ///< number of concurrent source address supported
        mdoIpsourceAddressCount = 0U;        ///< number of source address
        setVehicleInfo ( &initialVehicleInfo );
    }
    ~CDoIPHandler()
    {
    }

    uint8_t init ( void );

    void stop ( void );

    ///
    /// @brief This method should be invoked by SOAD on receive data over TCP/IP or UDP stack
    /// @param[in] sockNr ID of data received connection. If Data come from different client,
    ///                  the sockNr should be difefrent.
    /// @param[in] rxBuffer Buffer to store the received data.
    ///
    void messageReceived ( bool isUdp, uint8_t vlanNo,uint8_t sockNr, const std::vector<uint8_t> *rxBuffer, const void *clientAddr );

    void tcpConnectionEstablished ( uint8_t socketId,uint8_t vlanNo );
    ///
    /// @brief  Transmit the UDS message to the UDS core to process the uds request
    /// @param[in] sourceAddress address of the tester.
    /// @param[in] targetAddress Address of the target.
    /// @param[in] TAType                Target Address Type (Physical or Functional)
    /// @param[in] pMessageData  UDS message data
    /// @param[in] messageLength    Length of the UDS message
    ///
    void dataTrasferRequest ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t TAType, const uint8_t *pMessageData,  uint32_t messageLength );
    ///
    /// @brief This method configures the DOIP configuration parameters, like Address,timers....
    /// @param[in] DoIPConfig Doip Configuration parameters.
    ///
    void setDoIPDefaultConfig ( SDoIPConfig_t *DoIPConfig );
    ///
    void setDoIPParams ( DoipSetParams doipParams );
#ifdef DOIP_IPV6
    ///
    /// @brief This method configures the network IPv6 address
    /// @param[in] networkConfig Network Configuration parameters.
    ///
    void setNetWorkConfigIPv6 ( SDoIPSetNetworkInformationIPv6 networkConfig );
#endif
    ///
    /// @brief This method configures the network IP address
    /// @param[in] networkConfig Network Configuration parameters.
    ///
    void setNetWorkConfig ( SDoIPSetNetworkInformation networkConfig );

    /// set the number of VLANS doip entity supports
    void setVlanCount(uint8_t count);
    ///
    /// @brief This method configures vehicle information like, VIN, EID, GID..
    /// @param[in] vehicleInfo  Vehcile information parameters.
    ///
    void setVehicleInfo ( SVehicleInfo_t *vehicleInfo );
    ///
    /// @brief This method set the vehicle sync status. Whether the VIN configured or not
    /// @param[in] SyncState  Sync status.
    ///
    void setVehicleInfoSyncState ( uint8_t SyncState );
    ///
    /// @brief This method excuted in a periodicity. Periodic tasks are handles in this method
    /// @param[in] None
    ///
    void periodicTask ( void );
    ///
    /// @brief This menthod handles the doip timer instance
    /// @param[in] None
    ///
    void doipTimerBaseTick ( void );
    ///
    /// @brief This menthod handles the diagnosticPower mode response from Target
    /// @param[in] powerMode power mode of the target
    ///
    void diagnosticPowerModeResponse ( uint8_t vlanNo,uint8_t powerMode,const void *clientAddr );

    void doipSocketClose ( uint8_t socketId );


private:

    std::vector <CSoAdTcp> tcp;
    std::vector <CSoAdUdp> udp;
    CDoIPTimer mdoipTimer;
    uint8_t doipHeaderLength = 8U;       ///< DOIP header length
    uint32_t doipStackSize = 64512U + 512U;     ///< Stack size to hold received data over ethernet
    uint32_t doipDiagResLenght = 5;     ///< DOIP Diagnostic message resnposne length
    std::map<std::pair<int32_t, uint8_t>, uint32_t> mTimerId;
    /// @breif  Socket state
    enum ESocketStateType_t
    {
        SocketStateType_ConnectionInvalid = 0U,       ///< Connection Invalid
        SocketStateType_ConnectionEstablished = 1U,   ///< Connection Established
        SocketStateType_ConnectionRegistered = 2U,    ///< Connection Registered
        SocketStateType_Last,
    };

    std::vector<uint16_t> sa;               ///< source Address
    std::vector<int16_t> sockNr;            ///< socket number
    std::vector<ESocketStateType_t> DoIPSocketState;    ///< DOIP Socket state vector
    std::vector<bool> awaitingAliveCheckResponse;       ///< Waiting for Alive check response

    /// @breif Protocol type
    enum ESocketProtocolType_t
    {
        SocketProtocolType_TCP,             ///< TCP Protocol
        SocketProtocolType_UDP,                 ///< UDP is not supported with the Current DoIP stack
        SocketProtocolType_Last
    };

    /// @brief  Routing Activation acknowledgment code
    enum ERoutingActivationACK_t
    {
        ERoutingActivationACK_DeniedUnknownSA                           = 0x00U,    ///< Source Address not matched with configured
        ERoutingActivationACK_DeniedAllSocketsActive          = 0x01U,  ///< All the connection are Active
        ERoutingActivationACK_DeniedSocketRegistered                  = 0x02U,  ///< Requested Routing Activation socket registered and Active
        ERoutingActivationACK_DeniedSocketAlreadyRegistered   = 0x03U,  ///< Requested Routing Activation SourceAddress registered already
        ERoutingActivationACK_DeniedMissingAuth                     = 0x04U,    ///< Authentication Missing
        ERoutingActivationACK_DeniedConfirmRejected           = 0x05U,  ///< Confirmation Rejected
        ERoutingActivationACK_DeniedUnsupportedRAType         = 0x06U,  ///< Routing Activation type not supported
        ERoutingActivationACK_DoneSuccessfully                = 0x10U,  ///< Routing Activation Done successfully
        ERoutingActivationACK_DoneConfirmPending              = 0x11U,  ///< Routing Activation Done successfully but Confirmation pending
        ERoutingActivationACK_Last,
    };

    /// @brief  Negative acknowledgment code for DOIP Header
    enum EDoIPPatternErr_t
    {
        EDoIPPatternErr_IncorrectPatternFormat            = 0x00U,        ///<  Incorrect Protocol and Protocol Inverse Version
        EDoIPPatternErr_UnknownPayloadType                  = 0x01U,      ///<  Message Type Not supported
        EDoIPPatternErr_DiagMessageTooLarge               = 0x02U,        ///<  Diagnostic message is too Large
        EDoIPPatternErr_OutOfMemory                     = 0x03U,      ///<  The Length received id Exceeds DOIP Entity memory
        EDoIPPatternErr_InvalidPayloadLength            = 0x04U,      ///< Invalid payload length
        /* 0x05 to 0xFF is reserved by ISO 13400-2 */
        EDoIPPatternErr_ReservedSectionStart            = 0x05U,      ///< RESERVED FOR ISO 13400
        EDoIPPatternErr_ReservedSectionEnd              = 0xFFU,      ///< RESERVED FOR ISO 13400
        EDoIPPatternErr_Last,
    };

    /// @brief  Routing Activation Request Type
    enum ERoutingActivationType_t
    {
        ERoutingActivationType_Default                   = 0x00U, ///<  Default Routing Activation Type
        ERoutingActivationType_WWH_OBD                   = 0x01U, ///<  Default Routing Activation request with type WWH-OBD
        ERoutingActivationType_CentralSecurity           = 0xE0U, ///<  Reserved for OEM specific
        ERoutingActivationType_Last
    };

    ///  @brief  Diagnostic message negative acknowledgment code
    enum EDiagMsgResponse_t
    {
        EDiagMsgResponse_MsgOk                                             = 0x00U,   ///< Diagnostic Message OK
        EDiagMsgResponse_ReservedSection1End           = 0x01U,   ///< RESERVED FOR ISO 13400
        EDiagMsgResponse_InvalidSourceAddr             = 0x02U,   ///< Source Address not registered for Diagnostic message
        EDiagMsgResponse_UnknowntargetAddr             = 0x03U,   ///< Target Address not match with the configured
        EDiagMsgResponse_InvalidPayloadLength          = 0x04U,   ///< invalid Payload length
        EDiagMsgResponse_OutOfMemory                   = 0x05U,   ///<  The Length received id Exceeds DOIP Entity memory
        EDiagMsgResponse_TargetUnreachable             = 0x06U,   ///<  Target is unreachable
        EDiagMsgResponse_UnknownNetwork                = 0x07U,   ///< Unknown Network
        EDiagMsgResponse_TransportProtocolError        = 0x08U,   ///< Transport Protocol error
        EDiagMsgResponse_ReservedSection2Start         = 0x09U,   ///< RESERVED FOR ISO 13400
        EDiagMsgResponse_ReservedSection2End           = 0xFFU,   ///< RESERVED FOR ISO 13400
        EDiagMsgResponse_Last
    };

    /// @brief Routing Activation requested socket assignment
    enum ESocketAssignment_t
    {
        ESocketAssignment_Failed = 0U,  ///< Requested socket not assigned for Routing activation
        ESocketAssignment_Successful, ///< Requested socket successfully assigned for Routing activation
        ESocketAssignment_Pending,      ///< Requested socket assignment pending for Routing activation
        ESocketAssignment_Last
    };

    /// @breif DOIP Timers
    enum ETimer_t
    {
        ETimers_AliveCheckResponse = 0,             ///< Alive check response timer
        ETimers_Generalactivity,                            ///< General activity timer
        ETimers_InitialInActivity,                      ///< Initial In Activity timer
        ETimers_AnnounceWait,                                   ///< Vehicle Announce wait timer
        ETimers_AnnounceInterval,                           ///< Vehicle Announce Interval timer
        ETimers_Last
    };

    ERoutingActivationACK_t routingActivationResponseCode = ERoutingActivationACK_DeniedUnknownSA;

    uint16_t pendingRoutingActivationSa = 0xffU;
    int16_t pendingRoutingActivationSocket = -1;
    int16_t pendingRoutingActivationSocketIndex = -1;

    /// @breif DoIP Payload Types
    enum EPayloadType_t
    {
        EPayloadType_GenericHeaderNegativeAck           = 0x0000U,  ///< DOIP Header Negative acknowledgment message type
        EPayloadType_VehicleIdRequestMessage            = 0x0001U,  ///< DOIP Vehicle Identifier Request message type
        EPayloadType_VehicleIdRequestEid                        = 0x0002U,  ///< DOIP Vehicle Identifier Request with EID message type
        EPayloadType_VehicleIdRequestVin                        = 0x0003U,  ///< DOIP Vehicle Identifier Request with VIN message type
        EPayloadType_VehicleAnnouncementOrResponse      = 0x0004U,  ///< DOIP Vehicle Announcement Response message type
        EPayloadType_RoutingActivaionRequest            = 0x0005U,  ///< DOIP Routing Activation Request message type
        EPayloadType_RoutingActivationResponse          = 0x0006U,  ///< DOIP Routing Activation Response message type
        EPayloadType_AliveCheckRequest                  = 0x0007U,  ///< DOIP Alive Check Request message type
        EPayloadType_AliveCheckResponse                 = 0x0008U,  ///< DOIP Alive Check Response message type
        /* 0x0009 to 0x4000 is reserved by ISO 13400-2 */
        EPayloadType_ReservedSection1Start              = 0x0009U,  ///< RESERVED FOR ISO 13400
        EPayloadType_ReservedSection1End                = 0x4000U,  ///< RESERVED FOR ISO 13400
        EPayloadType_EntityStatusRequest                = 0x4001U,  ///< DOIP Entity Status Request message type
        EPayloadType_EntityStatusResponse               = 0x4002U,  ///< DOIP Entity Status Response message type
        EPayloadType_DiagPowerModeInfoRequest           = 0x4003U,  ///< DOIP Power mode information Request message type
        EPayloadType_DiagPowerModeInfoResponse          = 0x4004U,  ///< DOIP Power mode information Response message type
        /* 0x4005 to 0x8000 is reserved by ISO 13400-2 */
        EPayloadType_ReservedSection2Start              = 0x4005U,  ///< RESERVED FOR ISO 13400
        EPayloadType_ReservedSection2End                = 0x8000U,  ///< RESERVED FOR ISO 13400
        EPayloadType_DiagnosticMessage                  = 0x8001U,  ///< DOIP Diagnostic message type
        EPayloadType_DiagnosticMessagePositiveAck       = 0x8002U,  ///< DOIP  Diagnostic Positive acknowledgment message type
        EPayloadType_DiagnosticMessageNegativeAck       = 0x8003U,  ///< DOIP Diagnostic Negative acknowledgment message type
        /* 0x8004 to 0xEFFF is reserved by ISO 13400-2 */
        EPayloadType_ReservedSection3Start              = 0x8004U,  ///< RESERVED FOR ISO 13400
        EPayloadType_ReservedSection3End                = 0xEFFFU,  ///< RESERVED FOR ISO 13400
        /* 0xF000 to 0xFFFF is reserved by ISO 13400-2 for Manufcaturing Purpose */
        EPayloadType_ReservedManufacturePurposeStart    = 0xF000U,  ///< RESERVED FOR MANUFACTURER PURPOSE
        EPayloadType_ReservedManufacturePurposeEnd      = 0xFFFFU,  ///< RESERVED FOR MANUFACTURER PURPOSE
        EPayloadType_Last
    };

    /// @breif DoIP Payload Length
    enum EPayloadLen_t
    {
        EPayLoadLen_VehicleIdRequestMessage         = 0,
        EPayLoadLen_VehicleIdRequestEid             = 6,
        EPayLoadLen_VehicleIdRequestVin             = 17,
        EPayLoadLen_EntityStatus                    = 0,
        EPayLoadLen_RoutingActivationMin            = 7,
        EPayLoadLen_DiagnosticReq                   = 2,
        EPayLoadLen_AliveCheckResponse              = 2,
        EPayLoadLen_DiagPowerModeInfoRequest        = 0,
        EPayLoadLen_DiagnosticMessageMin            = 5,
        EpayLoadLen_AnnouncementResponseMin         = 32

    };
    enum EDoIPNodeType_t
    {
        EDoIPNodeType_Gateway = 0,              ///< Alive check response timer
        EDoIPNodeType_Node,                             ///< General activity timer
        EDoIPNodeType_Last
    };

    enum EDoIPPowerModeType_t
    {
        EDoIPPowerModeType_NotReady = 0,        ///< Power Mode not ready
        EDoIPPowerModeType_Ready,                       ///< Power Mode ready
        EDoIPPowerModeType_NotSupported         ///< Power Mode is not supported
    };

    uint8_t         mdoIpNoOfSocketsSupported = 0U; ///< number of sockets supported
    uint8_t         mdoIpNoOfConcurrentSrcAddrSupported = 0U; ///< number of concurrent source address supported
    uint8_t         mdoIpsourceAddressCount = 0U;        ///< number of source address
    uint32_t        mdoIpAliveCheckresponseTimeMs = 0U;  ///< Alive Check Resposne timer
    uint32_t        mdoIpGenericInactiveTimeMs = 0U;     ///< Gneral InActivity Timer
    uint32_t        mdoIpInitialInactiveTimeMs = 0U;     ///< Initial InActivity Timer
    uint8_t         mdoIpActivationNumber = 0U;          ///< DoIP Routing Activation Number
    bool            mdoIpRoutingActivationRequired = false; ///< DoIP Routing activation request required for DOIP Protocol
    bool            mdoIpAliveCheckRequired = false;        ///< DoIP Alive Check Response required for DOIP Protocol to check the tester availability
    bool            mdoIpAuthenticationRequired = false;    ///< DoIP Authentication required for Routing activation
    bool            mdoIpConfirmationRequired = false;      ///< DoIP Confirmation required for Routing activation
    std::vector<uint16_t> mdoIpSourceAddress;       ///< Source Address of the Tester ECU
    uint16_t        mdoIpTargetAddressePhysical = 0U;    ///< Target Address of the ECU (Logical Physical Address)
    std::vector<uint16_t> mdoIpTargetAddressesFunctional;   ///< Target Addresses of the ECU (Logical Functional Addresses)
    uint8_t         mdoIpTargetAddressCount = 0U;        ///< Target Address Count including logical physical and Functional addresses
    std::vector <uint16_t> mPortNum    ;                   ///< Port Number for Socket
    uint8_t         mdiagOverIPProtocol = 0U;            ///< Protocol which has been configured in INI
    uint8_t         mVlanCount  = 0U;                ///< Number of Vlans Supoorted
    std::map<uint8_t, uint32_t> m_timers;           ///< timers (GeneralActivity Timer, InitialInActivity Timer, AliveCheckResponse  Timer)
    std::vector <std::string> mIpAddress;                         ///< IP Address of the target
    unsigned long maxPayloadLength = 0xFFFFFFFFUL ; ///< maximum payload length

    std::vector<uint8_t> mVin;
    std::vector<uint8_t> mEid;
    std::vector<uint8_t> mGid;
    std::mutex mSetDoipParams;
    bool vehicleAnnouncementDone = false;
    uint32_t mdoIpVehicleAnnounceIntervalTimeMs = 0U;
    uint32_t mdoIpVehicleAnnounceWaitTimeMs = 0U;
    std::vector<uint8_t> announceCount;
    std::vector <uint8_t> flag;
    uint8_t vehicleInfoSyncState = 0x10;    // Vehicle sync Not happeed yet
    uint8_t actionRequired = 0x10; // Routing Activation required
    SVehicleInfo_t initialVehicleInfo = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    const int32_t mGlobalSocketIndex = -1;
    const int32_t mUDPProxySocketBase = 0xffff;
    std::mutex mProtectTimerMap;
    ///
    /// @brief  get the payload Length from the received buffer.
    ///         Decode the payload Length from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return payload length
    ///
    uint32_t getPayloadLength ( const std::vector<uint8_t> *buffer );
    ///
    /// @brief  get source address from the received buffer.
    ///         Decode the Source address from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return  Source Address of the Tester
    ///
    uint16_t getSourceAddress ( const std::vector<uint8_t> *buffer );
    ///
    /// @brief  get Traget address from the received buffer.
    ///         Decode the Traget address from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return   Target Address of the ECU
    ///
    uint16_t getTargetAddress ( const std::vector<uint8_t> *buffer );
    ///
    /// @brief  get protocol version of the DOIP from the received buffer.
    ///         Decode the protocol version from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return   Protocol version of the DOIP
    ///
    uint8_t getProtocolVersion ( const std::vector<uint8_t> *buffer );
    ///
    /// @brief  get protocol inverse version of the DOIP from the received buffer.
    ///         Decode the protocol inverse version from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return   Protocol inverse version of the DOIP
    ///
    uint8_t  getProtocolInverVersion ( const std::vector<uint8_t> *buffer );
    ///
    /// @brief  get payload type from the received buffer.
    ///         Decode the n from the received buffer
    ///
    /// @param[in]  buffer   Received data buffer
    /// @return     return   Protocol inverse version of the DOIP
    ///
    uint16_t getPayloadType ( const std::vector<uint8_t> *buffer );
    /// @brief  Check for the Registered Source AddressThis method Check the  received Source Address
    ///         and Registered source addresses.
    ///
    /// @param[in]  sourceAddress Source address from the request
    /// @return     True    - The source Address received is valid
    ///             False   - The source Address received is not valid
    bool sourceAddressKnown ( uint16_t sourceAddress );
    /// @brief  This method check whether the Authentication is required for the requested RoutingActivation request.
    ///
    /// @param[in]  activationType Activation type of the requested routing activation.
    /// @return     True    - Authentication is required for the requested RoutingActivation request
    ///             False   - Authentication is not required for the requested RoutingActivation request
    ///
    bool authenticationRequired ( uint8_t activationType );
    ///
    /// @brief  Check for Authentication.If authentication required for routing activation. There should
    ///         Call back function needs to provide to to check authenticatication. There is no support
    ///         in this version
    ///
    /// @param[in]  activationType Activation type of the requested routing activation.
    /// @return     True    - Authentication is successfull
    ///             False   - Authentication not successfull
    ///
    bool doIpauthenticated ( uint8_t activationType );
    ///
    /// @brief  This method check whether the confirmation is required for the requested RoutingActivation request.
    ///
    /// @param[in]  activationType Activation type of the requested routing activation.
    /// @return     True    - confirmation is required for the requested RoutingActivation request
    ///             False   - confirmation is not required for the requested RoutingActivation request
    ///
    bool confirmationRequired ( uint8_t activationType );
    ///
    /// @brief  Check for Confimration.If Confirmation required for routing activation. There should
    ///         Call back function needs to provide to to confirm. There is no support
    ///         in this version
    ///
    /// @param[in]  activationType Activation type of the requested routing activation.
    /// @return     True    - Confirmation is successfull
    ///             False   - Confirmation is not successfull
    ///
    bool confirmed ( uint8_t activationType );
    ///
    /// @brief      Prepare the Routing Activation response .
    /// @details    After processing the routing activation request, this method will be called
    ///             to prepare the buffer;
    /// @param[in]  buffer  buffer to store the Routing Activation response
    /// @param[in]  ResponseCode Response code for routing activation
    /// @param[in]  routingActivationResponseCode response code of the Routing Activation Request
    /// @return     returns number of bytes sent to tester
    ///
    int32_t prepareRoutingActivationResponse ( uint16_t sourceAddress,  ERoutingActivationACK_t ResponseCode, uint8_t Socket_Id );
    ///
    /// @brief    Send Alive Check Request for  all the Source Address .
    /// @details  Send Alive Check Request for  all the Source Address, when the socket is not available
    ///              for routing activation..
    /// @param[in]  None
    ///
    void startAllSaAliveCheck ( void );
    ///
    /// @brief  Send Alive check request. Prepare and send the alive check request
    ///
    /// @param[in]  socketId socket Index.
    ///
    void prepareAndSendAliveCheckReq ( uint8_t Socket_Id );
    ///
    /// @brief  Register the socket for the DOIP communication. This method will be called  while the socket is available for the
    ///         further communication. And the State of the socket will be set as registered
    /// @param[in]  slotIndex Index of the Connection table array.
    /// @param[in]  sockNr    Socket Handle.
    /// @param[in]  sourceAddress Source address .
    ///
    void registerSocket ( uint8_t slotIndex,  uint8_t sockNr, uint16_t sourceAddress );
    /// @brief  Send the negative acknowledgment for the Diagnostic request.
    ///         This method, prepare the negative acknowledgment for the Diagnostic message request
    ///         and send it to the tester.
    /// @param[in]  sockNr    Socket Handle.
    /// @param[in]  sourceAddress  Source Address.
    /// @param[in]  targetAddress   Target address.
    /// @param[in]  nackCode  negative acknowledgment code
    ///
    void createAndSendDiagnosticNack ( uint8_t  sockNr, uint16_t sourceAddress, uint16_t targetAddress, uint8_t nackCode );
    /// @brief  Send the positive acknowledgment for the Diagnostic request.
    ///         This method, prepare the positive acknowledgment for the Diagnostic message request
    ///         and send it to the tester.
    /// @param[in]  sockNr    Socket Handle.
    /// @param[in]  sourceAddress  Source Address.
    /// @param[in]  targetAddress   Target address.
    void createAndSendDiagnosticAck ( uint8_t sockNr, uint16_t sourceAddress, uint16_t targetAddress );

    /// @brief     verift the received Target addres valid or not
    /// @param[in]    targetAddress -  Targetaddres of the ECU whcih is from Tester over DOIP message
    ///
    bool targetAddressSupported ( uint16_t targetAddress );
    /// @brief  Handle the timers. This method handles the GenralActivity, AlivecheckResponseTimer,InitialInActivity timers
    /// @aram[in]   connectionIndex Socket connection index
    ///
    void handleTimeout ( uint8_t connectionIndex );
    /// @brief  Assign a socket for the routing activation request.This method will call Confirmation
    ///         function which is provided for the tester, if it is required for the requested Routing Activation;
    /// @param[in]  sockNr SocketHandle
    /// @param[in]  activationType Activation type of the requested routing activation
    /// @param[in]  sourceAddress Source address of the Tester

    uint8_t assignSocket ( uint8_t socketId, uint16_t sourceAddress );
    /// @brief  Check for Routing Activation Type.This method, verifies the configured Activation
    ///         type and received activation type from tester.
    /// @param[in]  activationType    Activation type of the Routing Activation Request.

    bool routingTypeSupported ( ERoutingActivationType_t activationType );
    /// @breif  Handle the routing activation request from the tester.This method will be called, when the routing activation request
    ///         is coming from tester;
    /// @param[in]  sockNr SocketHandle
    /// @param[in]  PayloadLength Length of the received payload
    /// @param[in]  rxBuffer Received message will stored in the buffer
    void routingActivationReq ( uint8_t socketId, const std::vector<uint8_t> *rxBuffer );
    /// @breif  Handle the the Alive check Response from the tester.when the tester sends the response
    ///         for the Alive check request,the requested routing activation will be discarded and sends the negative response.
    /// @param[in]  sockNr SocketHandle
    /// @param[in]  PayloadLength Length of the received payload
    /// @param[in]  rxBuffer Received message will stored in the buffer

    void aliveCheckResp ( uint8_t sockNr, const std::vector<uint8_t> *rxBuffer ) ;
    /// @breif  Send the negative acknowledgment.This method, prepare the negative acknowledgment
    ///         and send it to the tester.
    /// @param[in]  sockNr    Socket Handle.
    /// @param[in]  nackCode  negative acknowledgement code

    void createAndSendNack ( bool isUdpReq, uint8_t sockNr, uint8_t nackCode,const void *clientAddr  );

    /// @breif  Send Alive Check Request for the Single Source Address .Send Alive Check Request for the single source address
    ///     to check for whether the socket is available for routing activation.
    /// @param[in]  sourceAddress Source address

    void startSingleSaAliveCheck ( uint16_t sourceAddress );
    /// @breif  Handle the Diagnostic message from tester.This method check the Diagnostic message request, If it contains any data,
    ///     it will be forwarded to the UDS manager. And send the acknowledgment to the tester.
    /// @param[in]  sockNr SocketHandle
    /// @param[in]  PayloadLength Length of the received payload
    /// @param[in]  rxBuffer Received message will stored in the buffer

    void diagnosticMessage ( uint8_t sockNr, const std::vector<uint8_t> *rxBuffer );
    /// @breif  Message Indication, this method used to send Diagnostic message from tester to UDS for processing the message.
    /// @param[in]  sourceAddress  Source Address.
    /// @param[in]  targetAddress   Target address.
    /// @param[in]  taType          Physical or FUnctional Logical address.
    /// @param[in]  buffer          buffer of data to be transmitted to UDS.
    /// @param[in]  messageLength   length of UDS message.
    /// @param[in]  DoIP_Result     DOIP OK or NOT.
    void messageIndication ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t taType, uint8_t *buffer,  uint32_t messageLength,  uint8_t DoIP_Result  );
    /// @breif  Message Confirmation for the Sending message to the Tester from UDS.This method will confirm the Transmission of UDS response to the Tester.
    /// @param[in]  sourceAddress  Source Address.
    /// @param[in]  targetAddress   Target address.
    /// @param[in]  TAType          Physical or FUnctional Logical address.
    /// @param[in]  DoIP_Result     DOIP OK or NOT.
    void messsageConfirmation ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t TAType,  uint8_t DoIP_Result );
    /// @brief  Restarts the timer. this method used to restart the timer
    /// @param[in]  timerId   ID of the timer
    /// @param[in]  timoeCount   timer value
    void restartTimer ( int32_t timerId, uint32_t timoeCount );
    /// @brief  Data recived from tester which contain the SOAD header format
    /// @param[in]  sockNr     Id of teh socket
    /// @param[in]  rxBuffer   data buffer
    void dataReceivedForSoAd ( uint8_t SocketId, const std::vector<uint8_t> *rxBuffer );
    /// @brief  Data recived from tester which contain the DOIP/UdSOnIP header format
    /// @param[in]  sockNr     Id of teh socket
    /// @param[in]  rxBuffer   data buffer
    void dataReceivedForDoipOrUdsOnIP ( bool isUdp,uint8_t vlanNo, uint8_t SocketId, const std::vector<uint8_t> *rxBuffer, const void *clientAddr );
    /// @brief  This method used to get the Target address type. The Target address can be logical physical address
    ///         or logical functional address
    /// @param[in]  targetAddress     TargetAddress
    uint8_t findTargetType ( uint16_t targetAddress );
    /// @breif  Handle the Diagnostic message from tester.This method check the Diagnostic message request, If it contains any data,
    ///     it will be forwarded to the UDS manager. And send the acknowledgment to the tester.
    /// @param[in]  sockNr SocketHandle
    /// @param[in]  PayloadLength Length of the received payload
    /// @param[in]  rxBuffer Received message will stored in the buffer
    void vehicleIdentificationRequest ( uint8_t vlanNo,const std::vector<uint8_t> *rxBuffer, const void *clientAddress );
    /// @breif  Send vehicle announcement message to the network. By broadcasting the VIN, EID and GID
    /// @param[in]  None
    void sendVehicleAnnouncement ( uint8_t vlanNo,const void *clientAddress );

    /// @breif  Send the DOIP Entity status response
    /// @param[in]  None
    void doipEntityStatusResponse(uint8_t vlanNo,const void *clientAddr);

    int32_t getTimerId ( int32_t socketIndex, ETimer_t eTimer  );

    int32_t saveTimerId ( int32_t socketIndex, ETimer_t eTimer, int32_t timerId  );

    void AliveCheckTimeout ( uint8_t connectionIndex );

    void InitialInactivityTimeout ( uint8_t connectionIndex );

    void GeneralInactivityTimeout ( uint8_t connectionIndex );

    void tcpSocketClose( uint8_t socketId,uint8_t vlanNo);

#ifdef DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION 
    void notifyUdsAppOnRoutingActivation(uint16_t sourceAddress );
    /// @brief The DOIP stack informs the application that it has successfully executed a routingactivation request.
    /// @param[in]  sourceAddress  Source Address.

#endif //DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION 



};


#endif // end of INFRA_COMM_DOIP_HANDLER_H

