///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @file UclDL_Imple.h
/// @ingroup UclDL
/// @brief UCL Data Layer Implementation for Asynchronous ACK mechanism.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLDL_IMPL_H
#define UCLDL_IMPL_H

#include "UclDL_Types.h"
#include "UclDLCbk_Types.h"
#include "UclALPhyCbk_Types.h"

#define UCLDL_IMPL_ACK_MSG_SIZE 10u
#define UCLDL_IMPL_HB_MSG_SIZE 10u
#define UCLDL_IMPL_SEC_KEY_SIZE 16u
#define UCLDL_IMPL_SEC_MSG_SIZE 30u

#define UCLDL_IMPL_SEC_KVV_REQ_MSG_SIZE 16u
#define UCLDL_IMPL_SEC_KVV_RES_MSG_SIZE 20u

#define UCLDL_IMPL_MAX_LOCAL_TIMERS 4u

typedef struct SUclDLInst_t SUclDLInst;

///
/// @brief Callback function type for local timers
///
typedef void ( *TUclDLLocalTimerCbk ) ( SUclDLInst *pInst );

///
/// @brief State definitions for UclDL_Impl
///
typedef enum EUclDLState_t
{
    eUclDLState_Shutdown,     ///< UclDL is shutdown
    eUclDLState_Initializing, ///< UclDL is initializing
    eUclDLState_Active,       ///< UclDL is Active for both reception and transmission
    eUclDLState_RxOnly,       ///< UclDL is Receive only
    eUclDLState_Recovery,     ///< UclDL is in Recovery mode
    eUclDLState_Last          ///< Guard
} EUclDLState;

///
/// @brief Authentication State definitions for UclDL_Impl
///
typedef enum EUclDLAuthState_t
{
    eUclDLAuthState_UnAuthenticated, ///< UclDL is not authenticated. Secure messages cannot be sent/received.
    eUclDLAuthState_KeyNegotiation,  ///< UclDL is waiting for key negotiation
    eUclDLAuthState_RS2,             ///< UclDL is waiting for Random Seed 2
    eUclDLAuthState_KVVReq,          ///< UclDL is waiting for KVV Request
    eUclDLAuthState_KVVResp,         ///< UclDL is waiting for KVV Response
    eUclDLAuthState_Authenticated,   ///< UclDL is authenticated. Secure messages can be sent/received.
    eUclDLAuthState_Last             ///< Guard
} EUclDLAuthState;

///
/// @brief Structure for the ACK queue
///
/// The ACK queue maintains the message ids waiting for ACK and tracks the ACK timeout
///
typedef struct SUclDLAckQueueType_t
{
    uint16 msgId;     ///< Msg ID waitng for ACK
    uint16 isFree;    ///< Specifies if the slot is free
    uint64 timestamp; ///< Timestamp when the frame is transmitted
} SUclDLAckQueueType;

///
/// @brief Configuration data for UclDL_Impl.
///
/// The SUclDLCfg structure defines the constant configuration data for UclDL_Impl class.
///
typedef struct SUclDLCfg_t
{
    uint8 nodeId;                       ///< Node ID
    uint8 receiveProcessingMode;        ///< Process receive frames in callback or in a task
    uint16 timerTaskPeriodicityMs;      ///< Periodicity of UclDL processing task
    uint16 heartBeatTimerPeriodicityMs; ///< Periodicity of UclDL Heart beat timer
    uint16 linkDownTimerPeriodicityMs;  ///< Periodicity of UclDL Link down timer
    uint16 maxAckTimeoutMs;             ///< Maximum timeout to receive ACK in ms
    uint8 maxTxAckQueueSize;            ///< Default size of the queue shall be "10" . Maximum queue size should not exceed 50
    SUclDLAckQueueType *pAckQueue;      ///< ACK Queue
    uint16 phyRetryTimeIntervalMs;      ///< Time Interval to reinitialize phy in case of link down in ms
    uint16 maxTxMsgLength;              ///< Maximum transmit message length
    uint8 maxPhyRecoveryAttempts;       ///< Maximum Phy recovery attempts
    uint16 maxRxMsgLength;              ///< Maximum receive message length
    uint16 txWorkBufferSize;            ///< Size of the Transmit work buffer
    uint16 rxWorkBufferSize;            ///< Size of the Receive work buffer
    uint8 *pTxWorkBuffer;               ///< Work Buffer for Transmit Messages
    uint8 *pRxWorkBuffer;               ///< Work Buffer for Receive Messages
    uint8 enableSecurity;               ///< Enable Secure UCL messages
    uint8 enableTSC;                    ///< Enable TSC Counter for UCL messages
    uint16 tscToleranceMs;              ///< TSC tolerance beyond which the messages will be rejected
    uint16 keyNegotiationDelayMs;       ///< Timer delay before staring key negotiation
    uint16 securityStateTimeoutMs;      ///< State timeout delay during key negotiation
    uint16 encBufferSize;               ///< Size of the Encryption buffer
    uint16 decBufferSize;               ///< Size of the Decryption buffer
    uint8 *pEncBuffer;                  ///< Encryption buffer
    uint8 *pDecBuffer;                  ///< Decryption buffer
    uint8 *pCryMsgScratchBuffer;        ///< Scratch buffer to form the Crypto messages
    uint8 *pTransmitIVBuffer;           ///< Buffer for Transmit Initialization Vector
    uint8 *pReceiveIVBuffer;            ///< Buffer for Receive Initialization Vector
    uint8 *pRS1Buffer;                  ///< Buffer for Random Seed 1
    uint8 *pRS2Buffer;                  ///< Buffer for Random Seed 2
    uint8 *pSKBuffer;                   ///< Buffer for Session Key
    uint8 *pKVVReqBuffer;               ///< Buffer for KVV Request
    uint8 *pKVVRespBuffer;              ///< Buffer for KVV Response
} SUclDLCfg;

///
/// @brief Private instance data for UclDL_Impl. \n
/// @ingroup UclDL
///
/// The SUclDLInst structure defines the private instance data for UclDL_Impl class.
///
struct SUclDLInst_t
{
    uint8 numIUclALPhy; ///< Number of connected UclALPhy instances
    uint8 *pIUclALPhy;  ///< Instance ID of the connected UclALPhy instances
    uint8 instId;       ///<instance ID of the UclDL
    uint8 numIUclDLCbk; ///< Number of connected UclDLCbk instances
    uint8 *pIUclDLCbk;  ///< Instance ID of the connected UclDLCbk instances

    uint8 numIUclALCrypto; ///< Number of connected UclALCrypto instances
    uint8 *pIUclALCrypto;  ///< Instance ID of the connected UclALCrypto instances

    const SUclDLCfg *pCfg; ///< Configuration for the UclDL_Impl instance

    EUclDLState state;                                               ///< State of the UclDL_Impl instance
    EUclDLAuthState authState;                                       ///< Authentication State of the UclDL_Impl instance
    SUclDLStats stats;                                               ///< Statistics of the UclDL_Impl instance
    EUclDLLinkStatus linkStatus;                                     ///< Status of the UclDL Link
    uint32 ackQueueProtectMutexId;                                   ///< Status of the UclDL Link
    uint8 txCobsOverheadBytes;                                       ///< COBS Overhead for transmit for this Instance
    uint8 rxCobsOverheadBytes;                                       ///< COBS Overhead for receive for this Instance
    uint8 ackMsgScratchBuffer[UCLDL_IMPL_ACK_MSG_SIZE];              ///< Scratch buffer to form the ACK message
    uint8 hbMsgScratchBuffer[UCLDL_IMPL_HB_MSG_SIZE];                ///< Scratch buffer to form the Heartbeat message
    uint32 timerTaskId;                                              ///< Id for the TimerTask
    uint32 txBytesBps;                                               ///< Scratch pad variables for Bps calculations
    uint32 rxBytesBps;                                               ///< Scratch pad variables for Bps calculations
    uint32 localTimers[UCLDL_IMPL_MAX_LOCAL_TIMERS];                 ///< Array of local timers
    uint32 sendMutexId;                                              ///< Id for the Mutex to protect Send function
    TUclDLLocalTimerCbk localTimersCbk[UCLDL_IMPL_MAX_LOCAL_TIMERS]; ///< Array of local timers callbacks
    uint8 numPhyRecoveryAttempts;                                    ///< Number of times Phy recovery has been attempted
    uint16 tscCounter;                                               ///< Time Synchronized Counter Value
    uint16 phyReInitCounter;                                         ///< Re-Initialize Phy Counter Value
};

///
/// @brief This method implements the Initialize API for the IUclDL Interface
///        It initializes the DL Stack and its dependent modules (e.g. Phy, Crypto)
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Initialization Success
/// @return UCL_E_NOK   Initialization Failed
///
Ucl_ReturnType UclDL_Impl_IUclDL_Initialize ( SUclDLInst *pInst, uint8 InstId );

///
/// @brief This method implements the Shutdown API for the IUclDL Interface
///        It shuts down the DL Stack and its dependent modules (e.g. Phy, Crypto)
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Shutdown Success
/// @return UCL_E_NOK   Shutdown Failed
///
Ucl_ReturnType UclDL_Impl_IUclDL_Shutdown ( SUclDLInst *pInst, uint8 InstId );

///
/// @brief This method implements the Send API for the IUclDL Interface
///        It sends the encoded UCL messages to the Phy Abstraction
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
/// @param pMsg     Pointer to the UclDL Message for transmission
///
/// @return UCL_E_OK    Message accepted for transmission
/// @return UCL_E_NOK   Message Rejected
/// @return UCL_E_INVALID_ARGS Invalid Arguments
/// @return UCL_E_INVALID_STATE Invalid State to Send a message
///
Ucl_ReturnType UclDL_Impl_IUclDL_Send ( SUclDLInst *pInst, uint8 InstId, SUclDLMsg *pMsg );

///
/// @brief This method implements the Get Statistics API for the IUclDL Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
/// @param pDLStats   Pointer to the UclDL statistics
///
/// @return UCL_E_OK    Request to update DL statistics
/// @return UCL_E_NOK   Request Rejected
Ucl_ReturnType UclDL_Impl_IUclDL_GetStats ( SUclDLInst *pInst, uint8 InstId, SUclDLStats *pDLStats );

/// @brief This method implements the FatalError Callback API for the IUclALPhyCbk Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee i.e UclALPhy Instance
/// @param Status   Status of the error
///
void UclDL_Impl_IUclALPhyCbk_FatalError ( SUclDLInst *pInst, uint8 InstId, uint8 status );

///
/// @brief This method implements the ReceiveDataAvailable Callback API for the IUclALPhyCbk Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee i.e UclALPhy Instance
///
void UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable ( SUclDLInst *pInst, uint8 InstId );

///
/// @brief This method implements the PeerReadyStatusChanged Callback API for the IUclALPhyCbk Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee i.e UclALPhy Instance
/// @param Status   Peer Ready Status
///
void UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged ( SUclDLInst *pInst, uint8 InstId, EUclALPhyPeerReadyStatus status );

#endif //UCLDL_IMPL_H
