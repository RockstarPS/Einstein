/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file DoIP_Lcfg.h
*    @ingroup DoIPConfiguration
*    @brief This is DoIP link time configuration header file. It contains definitions of link time
*    configuration parameters for the DoIP module.
*    @defgroup DoIPConfiguration
*    @brief This contains the link time configurations for the DoIP module.
********************************************************************************************************************/
#ifndef DOIP_LCFG_H
#define DOIP_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP_Cfg.h"
#include "SoAd.h"
/********************************************************************************************************************
* #! DoIP types                                                                                                     *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef DOIP_LOCAL 
#define DOIP_LOCAL  static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#ifndef DOIP_LOCAL_INLINE
#define DOIP_LOCAL_INLINE  LOCAL_INLINE
#endif

/*! DoIP configuration types */
typedef uint8 DoIP_ConIdxType;
typedef uint8 DoIP_LocalIpAddrIdxType;
typedef uint8 DoIP_TcpTxBufferIdxType;
typedef uint8 DoIP_TcpTxQueueIdxType;
typedef uint8 DoIP_TesterIdxType;
typedef uint16 DoIP_TesterAddrType;
typedef uint8 DoIP_RoutingActivationIdxType;
typedef uint8 DoIP_ChannelIdxType;
typedef uint8 DoIP_TesterToRoutingActivationMapIdxType;
/*! API type. */
typedef uint8 DoIP_ApiType;
# define DOIP_API_TYPE_TP                               0x00u
# define DOIP_API_TYPE_IF                               0x01u

typedef struct
{
    uint8 HeaderVersion:8u;
    uint8 HeaderInvVersion:8u;
    uint16 HeaderType:16u;
    uint32 HeaderLength:32u;
}DoIP_GenericHeaderType;

typedef struct
{
    DoIP_LocalIpAddrIdxType LocalIpAddrIdx;
    PduIdType RxCancelPduId;
    PduIdType TxPduId;
}DoIP_ConnectionConfigType;

typedef uint8 DoIP_DiagNackBufferIdxType;

typedef struct
{
    boolean                         IsRoutingActivationRequired;
    DoIP_TesterAddrType             TesterAddr;
    PduLengthType                   NumOfDiagAckNackRespBytes;
    DoIP_RoutingActivationIdxType   RoutingActivationIdx; 
    DoIP_DiagNackBufferIdxType      DiagNackBufferStartIdx;
    DoIP_DiagNackBufferIdxType      DiagNackBufferEndIdx;
    DoIP_TesterToRoutingActivationMapIdxType    TesterToRoutingActivationMapStartIdx;
    DoIP_TesterToRoutingActivationMapIdxType    TesterToRoutingActivationMapEndIdx;
}DoIP_TesterConfigType;

typedef uint16 DoIP_EcuAddrType;

typedef uint8 DoIP_TxIfBufferIdxType;

typedef struct
{
    boolean             IsDefaultChannel;
    DoIP_ApiType        ApiType;        
    DoIP_TesterIdxType  TesterIdx;
    DoIP_EcuAddrType    EcuAddr;
    PduLengthType       TpMaxLength;
    PduIdType           RxPduId;
    PduIdType           TxConfId;
    DoIP_TxIfBufferIdxType  TxIfBufferStartIdx;
    DoIP_TxIfBufferIdxType  TxIfBufferSize;
}DoIP_ChannelConfigType; 

typedef P2FUNC(Std_ReturnType, DOIP_CODE, DoIP_AuthCallbackFnType)
(
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) Authentified,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) AuthenticationReqData,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) AuthenticationResData
);
  

/*! Confirmation function pointer. */
typedef P2FUNC(Std_ReturnType, DOIP_CODE, DoIP_ConfCallbackFnType)
(
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) Confirmed,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ConfirmationReqData,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ConfirmationResData
);


typedef struct
{
    uint8 RoutingActivationNumber;
    uint8 AuthResLength;
    uint8 AuthReqLength;
    uint8 ConfReqLength;
    uint8 ConfResLength;
    DoIP_ChannelIdxType  ChannelStartIdx;
    DoIP_ChannelIdxType  ChannelEndIdx;
    DoIP_AuthCallbackFnType pAuthCallbackFn;
    DoIP_ConfCallbackFnType pConfCallbackFn;
}DoIP_RoutingActivationConfigType;

typedef uint8 DoIP_TxTcpQueueElementIdxType;
typedef uint8 DoIP_HeaderBufferIdxType;

typedef struct
{
    DoIP_HeaderBufferIdxType        RxHeaderBufferStartIdx;
    DoIP_HeaderBufferIdxType        TxHeaderBufferStartIdx;
    DoIP_TxTcpQueueElementIdxType   TcpTxQueueElementStartIdx;
    DoIP_TxTcpQueueElementIdxType   TcpTxQueueElementEndIdx;
    DoIP_TxTcpQueueElementIdxType   TcpTxQueueElementSize;
}DoIP_TcpConConfigType;

/*! IP address assignment type. */
typedef uint8 DoIP_IpAddrAssignmentType;
# define DOIP_IPADDR_ASSIGN_TYPE_NONE                   0u
# define DOIP_IPADDR_ASSIGN_TYPE_STATIC                 1u
# define DOIP_IPADDR_ASSIGN_TYPE_LINKLOCAL_DOIP         2u
# define DOIP_IPADDR_ASSIGN_TYPE_DHCP                   3u
# define DOIP_IPADDR_ASSIGN_TYPE_LINKLOCAL              4u

typedef uint8 DoIP_IpAddrAssignmentIdxType;
typedef uint8 DoIP_LocalAddrIdxType;
typedef uint8 DoIP_ConMapIdxType;

typedef struct
{
    /*! @brief if UDP alive timeout is enabled */
    boolean IsUpdAliveTimeoutEnabled;
    DoIP_IpAddrAssignmentIdxType    IpAddrAssignmentStartIdx;
    DoIP_IpAddrAssignmentIdxType    IpAddrAssignmentEndIdx;
    DoIP_ConMapIdxType              ConMapStartIdx;    
    DoIP_ConMapIdxType              ConMapEndIdx;    
}DoIP_LocalAddrConfigType;

typedef struct
{
    boolean IsIpAssignementEnabled;
    DoIP_IpAddrAssignmentType IpAddrAssignmentType;
}DoIP_IpAddrAssignmentConfigType;

typedef struct
{
    DoIP_ChannelIdxType ChannelIdx;
}DoIP_RxPduConfigType;

typedef struct
{
    DoIP_TesterIdxType TesterIdx;
}DoIP_DefaultAddrConfigType;

/*! DoIP Control status types */
typedef uint8 DoIP_TcpConIdxType;
typedef uint32 DoIP_TcpConInactiveTimerType;
typedef uint8 DoIP_TcpRxBufferIdxType;
typedef uint8 DoIP_TargetAddrType;


typedef struct
{
    SoAd_IpAddrStateType    IpAddrState;
    SoAd_SoConIdType        SoConIdx;
    SoAd_SoConModeType      SoConMode;
    boolean                 SoConCloseReq;
}DoIP_ConCtrlStatusType;

typedef struct
{
    /*! @brief IP address request state */
    DoIP_IpAddrReqStateType IpAddrReqState;
}DoIP_IpAddrAssignmentCtrlType;


typedef struct
{
    /*! @brief Defines whether the Rx message to be skipped of this Tcp connection */
    boolean RxSkipMsg;    
    /*! @brief Defines the Rx channel is active of this Tcp connection */
    boolean RxChannelActive;
    /*! @brief Defines whether the Rx Tp session is active of this Tcp connection */
    boolean RxTpSessionActive;
    /*! @brief Defines whether the Rx Tp cancel is active of this Tcp connection */
    boolean RxTpCancelReq;
    /*! @brief Defines the previous Rx message buffer size of this Tcp connection */
    DoIP_TcpRxBufferIdxType RxLastBufferSize;
    /*! @brief Defines the number of Rx bytes copied of this Tcp connection */
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    /*! @brief Defines the last Rx target address of this Tcp connection */
    DoIP_TesterAddrType RxLastTargetAddr;
    /*! @brief Defines the last Rx channel Idx of this Tcp connection */
    DoIP_ChannelIdxType RxLastChannelIdx;
}DoIP_TcpConRxCtrlStatusType;

typedef struct
{
    /*! @brief Defines the Channel Idx */  
    DoIP_ChannelIdxType ChannelIdx;
    /*! @brief Defines the header buffer length */
    PduLengthType       HeaderBufferLength;
    /*! @brief Defines the PduInfo data */
    PduInfoType         TxTcpPduInfo;
}DoIP_TxTcpQueueElementType;

typedef struct
{
    /*! @brief Defines whether Tx Tp cancel is requested of this Tcp connection */
    boolean                 TxTpCancelReq;
    /*! @brief Defines whether Tx Tp session is active of this Tcp connection */
    boolean                 TxTpSessionActive;
    /*! @brief Defines whether the socket close is requested of this Tcp connection */
    boolean                 TxTpCloseSocketReq;
    /*! @brief Defines the previous Tx message buffer size of this Tcp connection */
    DoIP_TcpTxBufferIdxType TxLastBufferSize;
    /*! @brief Defines the number of Tx bytes copied of this Tcp connection */
    DoIP_TcpTxBufferIdxType TxBytesCopied;
    /*! @brief Defines the Tx Tcp Queue Idx of this Tcp connection */
    DoIP_TxTcpQueueElementIdxType  TcpTxQueueElementIdx;
    /*! @brief Defines the Tx Tcp Queue Level of this Tcp connection */
    DoIP_TcpTxQueueIdxType  TxTcpCtrlQueueLevel;
    /*! @brief Defines the Tx Tp header type  of this Tcp connection */
    uint16                  TxTpHeaderType;
    /*! @brief Defines the Tx Tp 1st parmeter of header type of this Tcp connection */
    uint16                  TxTpFirstParam;
    /*! @brief Defines the Tx Tp 2nd parmeter of header type of this Tcp connection */
    uint16                  TxTpSecondParam;
    /*! @brief Defines the Tx Tp 3rd parmeter of header type of this Tcp connection */
    uint16                  TxTpThirdParam;
}DoIP_TcpConTxCtrlStatusType;

typedef struct
{
    /*! @brief Defines the tester address of this Tcp connection */
    DoIP_TesterAddrType             TesterAddr;
    /*! @brief Defines the tester Index of this Tcp connection */
    DoIP_TesterIdxType              TesterIdx;
    /*! @brief Defines the routing activation Idx of this Tcp connection */
    DoIP_RoutingActivationIdxType   RoutingActivationIdx;
    /*! @brief Defines the routing activation state of this Tcp connection */
    DoIP_RoutingActivationStateType RoutingActivationState;
    /*! @brief Defines the local address of this Tcp connection */
    SoAd_SockAddrType               LocalIpAddress;
    /*! @brief Defines the remote address of this Tcp connection */
    SoAd_SockAddrType               RemoteIpAddress;
    /*! @brief Defines the inactivity timeout of this Tcp connection */
    DoIP_TcpConInactiveTimerType    InactiveTimeCount;
    /*! @brief Defines the Tx control status of this Tcp connection */
    DoIP_TcpConTxCtrlStatusType     TcpConTxCtrlStatus;
    /*! @brief Defines the Tx control status of this Tcp connection */
    DoIP_TcpConRxCtrlStatusType     TcpConRxCtrlStatus;
}DoIP_TcpConCtrlStatusType;

typedef uint16 DoIP_UdpConTxRetryCountType;
typedef uint8 DoIP_UdpConIdxType;
typedef uint8 DoIP_UdpTxCtrlIdxType;

typedef struct
{
    /*! @brief Defines the Connection Idx of this Udp Connection */
    DoIP_ConIdxType             ConIdx;
    /*! @brief Defines the Tx retry count of this Udp Connection */
    DoIP_UdpConTxRetryCountType  TxRetryCount;
    /*! @brief Defines the Tx Tp header type  of this Udp connection */
    uint16                      TxHeaderType;
    /*! @brief Defines the Tx Tp 1st parmeter of header type of this Udp connection */
    uint16                      TxFirstParam;
    /*! @brief Defines the Tx Tp 2nd parmeter of header type of this Udp connection */
    uint16                      TxSecondParam;
    /*! @brief Defines the remote address of this Udp connection */
    SoAd_SockAddrType           RemoteIpAddress;
} DoIP_UdpConCtrlStatusType; 

typedef struct 
{
    /*! @brief Defines the Connection Idx of this Udp Connection */
    DoIP_ConIdxType             ConIdx;
    /*! @brief Defines the Tx retry count of this Udp Connection */
    DoIP_UdpConTxRetryCountType  TxRetryCount;
    /*! @brief Defines the Tx Tp header type  of this Udp connection */
    uint16                      TxHeaderType;
    /*! @brief Defines the Tx Tp 1st parmeter of header type of this Udp connection */
    uint16                      TxFirstParam;
    /*! @brief Defines the Tx Tp 2nd parmeter of header type of this Udp connection */
    uint16                      TxSecondParam;
    /*! @brief Defines the remote address of this Udp connection */
    SoAd_SockAddrType           RemoteIpAddress;
}DoIP_UdpTxCtrlStatusType;

typedef struct
{
    PduLengthType TxLength;
}DoIP_ChannelCtrlStatusType;

typedef struct
{
    DoIP_TcpConIdxType TcpConIdx;
    PduLengthType NegativeAckOffset;
}DoIP_TesterCtrlStatusType;


typedef uint32 DoIP_AliveCheckCountType;
typedef uint32 DoIP_OemDataType;

typedef struct
{
    boolean                         OemReqResUsed;
    DoIP_OemDataType                OemRequest;
    DoIP_OemDataType                OemResponse;
    DoIP_AliveCheckCountType        AliveCheckCount;
    DoIP_TcpConIdxType              TcpConIdx;
    DoIP_TesterAddrType             TesterAddr;
    DoIP_TesterIdxType              TesterIdx;
    DoIP_RoutingActivationIdxType   RoutingActivationIdx;
    uint32                          AliveCheckElemNum;
}DoIP_RoutingActivationCtrlStatusType;

typedef struct
{
    boolean         TcpBufferReqTx;
    DoIP_ConIdxType TcpBufferConIdx;
    PduLengthType   TcpBufferLength;
    PduLengthType   UdpBufferLength;
}DoIP_OemPayloadCtrlStatusType;

/*! @brief Defines the Type for Callback function to check if the PowerMode of the DoIP entity is ready or not. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserGetPowerModeCallbackFnType)
(
    P2VAR(DoIP_PowerStateType,AUTOMATIC,DOIP_APPL_VAR) PowerStateReady
); 
/*! @brief Defines the Type for Callback function to get the confirmation for the Routing Activation. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserRoutingActivationConfirmationFnType)
(
    P2VAR(boolean,AUTOMATIC,DOIP_APPL_VAR) Confirmed,
    P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) ConfirmationReqData,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_VAR) ConfirmationResData
);

/*! @brief Defines the Type for Callback function to get the confirmation for the Routing Activation. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserRoutingActivationAuthenticationFnType)
(
    P2VAR(boolean,AUTOMATIC,DOIP_APPL_VAR) Authentified,
    P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) AuthenticationReqData,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_VAR) AuthenticationResData
);

/*! @brief  Defines the Type for Function that is used in the case that DoIPVinGIDMaster is set to true and a container
    DoIPTriggerGidSyncCallback is configured to trigger the synchronization process of the GroupIdentifier. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserTriggerGidSyncCallbackFnType)(void);

/*! @brief Defines the Type for Function that is used in the case that DoIPVinGIDMaster is set to false and 
    DoIPGetGidCallback is configured to get on a vehicle identification the GID. If the return value is not E_OK 
    the DoIP shall use the default GID. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserGetGidCallbackFnType)
(
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_VAR) GroupId
);

/*! @brief Defines the Type for Function that is used to get VIN .Dcm_GetVin should be called as per AUTOSAR. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserGetVinCallbackFnType)
(
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_VAR) Vin
);

/*! @brief Defines the Type for Callback function to get the OEM specific Further Action Byte for the DoIP vehicle  
    identification response/vehicle announcement. */
typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserGetFurtherActionByteCallbackFnType)
(
    P2VAR(DoIP_FurtherActionByteType,AUTOMATIC,DOIP_APPL_VAR) FurtherActionByte
);

typedef P2FUNC(Std_ReturnType,DOIP_APPL_CODE,DoIP_UserGetPayloadCallbackFnType)
(
    uint16 RxHeaderType,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) RxPduInfo,
    uint8 PayloadType,
    P2VAR(uint16,AUTOMATIC,DOIP_APPL_VAR) TxHeaderType,
    P2VAR(PduInfoType,AUTOMATIC,DOIP_APPL_VAR) TxPduInfo
    
); 
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
extern DoIP_ConCtrlStatusType DoIP_ConCtrlStatus[DOIP_NUM_OF_CONNECTION];
extern DoIP_TxTcpQueueElementType DoIP_TxTcpQueue[DOIP_TCP_TX_QUEUE_SIZE];
extern DoIP_TcpConCtrlStatusType DoIP_TcpConCtrlStatus[DOIP_NUM_OF_TCP_CONNECTION];
extern DoIP_UdpConCtrlStatusType DoIP_UdpConCtrlStatus[DOIP_NUM_OF_UDP_CONNECTION];
extern DoIP_UdpTxCtrlStatusType DoIP_UdpTxCtrlStatus[DOIP_UDP_NUM_OF_TX_CTRL];
extern DoIP_ChannelCtrlStatusType DoIP_ChannelCtrlStatus[DOIP_NUM_OF_CHANNEL];
extern DoIP_TesterCtrlStatusType DoIP_TesterCtrlStatus[DOIP_NUM_OF_TESTER];
extern DoIP_IpAddrAssignmentCtrlType DoIP_IpAddrAssignmentCtrl[DOIP_NUM_OF_IP_ADDRESS_ASSIGNEMENT];
extern DoIP_RoutingActivationCtrlStatusType DoIP_RoutingActivationCtrlStatus;
extern DoIP_OemPayloadCtrlStatusType DoIP_OemPayloadCtrlStatus;
extern uint8 DoIP_OemPayloadUdpBuffer[DOIP_OEM_PAYLOAD_UDP_BUFFER_SIZE];
#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0u)
extern uint8 DoIP_OemPayloadTcpBuffer[DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE]; 
#endif
extern boolean DoIP_ActivationLineInactiveReq;
extern boolean DoIP_PduSizeRoutingStatus;
extern boolean DoIP_GroupIdInSyncStatus;
extern DoIP_ActivationLineType DoIP_ActivationLineState;
extern DoIP_LocalIpAddrIdxType DoIP_LocalIpAddrAssignedCount;  
extern uint8 DoIP_RxHeaderBuffer[DOIP_RX_HEADER_BUFFER_SIZE];
extern uint8 DoIP_TxHeaderBuffer[DOIP_TX_HEADER_BUFFER_SIZE];
extern uint8 DoIP_TxIfBuffer[DOIP_TX_IF_BUFFER_SIZE];
extern uint8 DoIP_DiagNAckBuffer[DOIP_DIAG_NACK_BUFFER_SIZE];
/********************************************************************************************************************
* #! DoIP const config  data                                                                                     *
********************************************************************************************************************/
/*! @brief DoIP configuration */
extern const DoIP_ConfigType DoIP_Config;
extern const DoIP_ConnectionConfigType DoIP_ConnectionConfig[DOIP_NUM_OF_CONNECTION];
/*! @brief Configured EID (Entity ID of) for vehicle identification/vehicle announcement. Only necessary if 
    DoIPUseMacAddressForIdentification is set to FALSE. */
extern uint8 const DoIP_CfgEid[DOIP_EID_LENGTH];
/*! @brief Configured GID (Group ID of) for vehicle identification/vehicle announcement. */
extern uint8 const DoIP_CfgGid[DOIP_GID_LENGTH];
extern const DoIP_TesterConfigType DoIP_TesterConfig[DOIP_NUM_OF_TESTER];
extern const DoIP_RoutingActivationConfigType DoIP_RoutingActivationConfig[DOIP_NUM_OF_ROUTING_ACTIVATION];
extern const DoIP_ChannelConfigType DoIP_ChannelConfig[DOIP_NUM_OF_CHANNEL];
extern const DoIP_TcpConConfigType DoIP_TcpConConfig[DOIP_NUM_OF_TCP_CONNECTION];
extern const DoIP_LocalAddrConfigType DoIP_LocalAddrConfig[DOIP_NUM_OF_LOCAL_ADDR];
extern const DoIP_IpAddrAssignmentConfigType DoIP_IpAddrAssignmentConfig[DOIP_NUM_OF_IP_ADDRESS_ASSIGNEMENT];
extern const DoIP_RxPduConfigType DoIP_RxPduConfig[DOIP_NUM_OF_RX_PDU];
extern const DoIP_RoutingActivationIdxType DoIP_TesterToRoutingActivationIdxMap[DoIP_NUM_OF_TESTER_TO_ROUTING_ACTIVATION];
extern const DoIP_UserGetFurtherActionByteCallbackFnType DoIP_UserGetFurtherActionByteCallbackFn;
extern const DoIP_UserGetPayloadCallbackFnType DoIP_UserGetPayloadCallbackFn;
extern const DoIP_UserGetGidCallbackFnType DoIP_UserGetGidCallbackFn;
extern const DoIP_UserGetVinCallbackFnType DoIP_UserGetVinCallbackFn;
extern const DoIP_UserTriggerGidSyncCallbackFnType DoIP_UserTriggerGidSyncCallbackFn;
extern const DoIP_UserGetPowerModeCallbackFnType DoIP_UserGetPowerModeCallbackFn;
extern const DoIP_DefaultAddrConfigType DoIP_DefaultAddrConfig;
extern const DoIP_ConIdxType DoIP_LocalAddrToConMap[DOIP_LOCAL_ADDR_TO_CON_MAP_SIZE];

/* Get macros for DoIP configuration */

#define DoIP_CfgGetUserFurtherActionByteCallbackFn(param)   (DoIP_UserGetFurtherActionByteCallbackFn((param)))
#define DoIP_CfgGetUserGetGidCallbackFn(param)              (DoIP_UserGetGidCallbackFn((param)))
#define DoIP_CfgGetUserGetVinCallbackFn(param)              (DoIP_UserGetVinCallbackFn((param)))
#define DoIP_CfgUserTriggerGidSyncCallbackFn()              (DoIP_UserTriggerGidSyncCallbackFn())
#define DoIP_CfgUserGetPowerModeCallbackFn(param)           (DoIP_UserGetPowerModeCallbackFn(param))

#define DoIP_TesterCfgGetIsRoutingActivationRequired(Idx)   (DoIP_TesterConfig[(Idx)].IsRoutingActivationRequired)
#define DoIP_TesterCfgGetTesterAddr(Idx)                      (DoIP_TesterConfig[(Idx)].TesterAddr)
#define DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(Idx)     (DoIP_TesterConfig[(Idx)].NumOfDiagAckNackRespBytes)
#define DoIP_TesterCfgGetRoutingActivationIdx(Idx)          (DoIP_TesterConfig[(Idx)].RoutingActivationIdx)
#define DoIP_TesterCfgGetDiagNackBufferStartIdx(Idx)          (DoIP_TesterConfig[(Idx)].DiagNackBufferStartIdx)
#define DoIP_TesterCfgGetDiagNackBufferEndIdx(Idx)          (DoIP_TesterConfig[(Idx)].DiagNackBufferEndIdx)
#define DoIP_TesterCfgGetTesterToRoutingActivationMapStartIdx(Idx)  (DoIP_TesterConfig[(Idx)].TesterToRoutingActivationMapStartIdx)
#define DoIP_TesterCfgGetTesterToRoutingActivationMapEndIdx(Idx)    (DoIP_TesterConfig[(Idx)].TesterToRoutingActivationMapEndIdx)


#define DoIP_RoutingActivationCfgGetActivationNumber(Idx)   (DoIP_RoutingActivationConfig[(Idx)].RoutingActivationNumber)
#define DoIP_RoutingActivationCfgGetAuthResLength(Idx)      (DoIP_RoutingActivationConfig[(Idx)].AuthResLength)
#define DoIP_RoutingActivationCfgGetAuthReqLength(Idx)      (DoIP_RoutingActivationConfig[(Idx)].AuthReqLength)
#define DoIP_RoutingActivationCfgGetConfReqLength(Idx)      (DoIP_RoutingActivationConfig[(Idx)].ConfReqLength)
#define DoIP_RoutingActivationCfgGetConfResLength(Idx)      (DoIP_RoutingActivationConfig[(Idx)].ConfResLength)
#define DoIP_RoutingActivationCfgGetChannelStartIdx(Idx)    (DoIP_RoutingActivationConfig[(Idx)].ChannelStartIdx)
#define DoIP_RoutingActivationCfgGetChannelEndIdx(Idx)    (DoIP_RoutingActivationConfig[(Idx)].ChannelEndIdx)
#define DoIP_RoutingActivationCfgGetpAuthCallbackFn(Idx)    (DoIP_RoutingActivationConfig[(Idx)].pAuthCallbackFn)
#define DoIP_RoutingActivationCfgGetpConfCallbackFn(Idx)    (DoIP_RoutingActivationConfig[(Idx)].pConfCallbackFn)

#define DoIP_CfgGetNumOfConnection()        (DOIP_NUM_OF_CONNECTION)
#define DoIP_CfgGetNumOfUdpConnection()     (DOIP_NUM_OF_UDP_CONNECTION)
#define DoIP_CfgGetNumOfUdpTxCtrl()     (DOIP_UDP_NUM_OF_TX_CTRL)
#define DoIP_CfgGetNumOfTcpConnection()     (DOIP_NUM_OF_TCP_CONNECTION)
#define DoIP_CfgGetNumOfTcpUdpConnection()  (DOIP_NUM_OF_TCP_UDP_CONNECTION)
#define DoIP_CfgGetNumOfTcpTxQueue()        (DOIP_NUM_OF_TCP_TX_QUEUE)
#define DoIP_CfgGetTcpTxQueueSize()         (DOIP_TCP_TX_QUEUE_SIZE)
#define DoIP_CfgGetNumOfTester()            (DOIP_NUM_OF_TESTER)
#define DoIP_CfgGetNumOfRoutingActivation() (DOIP_NUM_OF_ROUTING_ACTIVATION)
#define DoIP_CfgGetNumOfChannel()           (DOIP_NUM_OF_CHANNEL)
#define DoIP_CfgGetNumOfLocalAddr()         (DOIP_NUM_OF_LOCAL_ADDR)

#define DoIP_TcpConCfgGetRxHeaderBufferStartIdx(Idx)    (DoIP_TcpConConfig[(Idx)].RxHeaderBufferStartIdx)
#define DoIP_TcpConCfgGetTxHeaderBufferStartIdx(Idx)    (DoIP_TcpConConfig[(Idx)].TxHeaderBufferStartIdx)
#define DoIP_TcpConCfgGetTcpTxQueueElementStartIdx(Idx) (DoIP_TcpConConfig[(Idx)].TcpTxQueueElementStartIdx)
#define DoIP_TcpConCfgGetTcpTxQueueElementEndIdx(Idx)   (DoIP_TcpConConfig[(Idx)].TcpTxQueueElementEndIdx)
#define DoIP_TcpConCfgGetTcpTxQueueElementSize(Idx)     (DoIP_TcpConConfig[(Idx)].TcpTxQueueElementSize)

#define DoIP_ChannelCfgGetIsDefaultChannel(Idx) (DoIP_ChannelConfig[(Idx)].IsDefaultChannel)
#define DoIP_ChannelCfgGetApiType(Idx)      (DoIP_ChannelConfig[(Idx)].ApiType)
#define DoIP_ChannelCfgGetTesterIdx(Idx)    (DoIP_ChannelConfig[(Idx)].TesterIdx)
#define DoIP_ChannelCfgGetEcuAddr(Idx)      (DoIP_ChannelConfig[(Idx)].EcuAddr)
#define DoIP_ChannelCfgGetTpMaxLength(Idx)  (DoIP_ChannelConfig[(Idx)].TpMaxLength)
#define DoIP_ChannelCfgGetRxPduId(Idx)      (DoIP_ChannelConfig[(Idx)].RxPduId)
#define DoIP_ChannelCfgGetTxConfId(Idx)     (DoIP_ChannelConfig[(Idx)].TxConfId)
#define DoIP_ChannelCfgGetTxIfBufferStartIdx(Idx)     (DoIP_ChannelConfig[(Idx)].TxIfBufferStartIdx)
#define DoIP_ChannelCfgGetTxIfBufferSize(Idx)     (DoIP_ChannelConfig[(Idx)].TxIfBufferSize)

#define DoIP_IpAddrAssignmentCfgGetIsIpAssignementEnabled(Idx)  (DoIP_IpAddrAssignmentConfig[(Idx)].IsIpAssignementEnabled)
#define DoIP_IpAddrAssignmentCfgGetIpAddrAssignmentType(Idx)    (DoIP_IpAddrAssignmentConfig[(Idx)].IpAddrAssignmentType)
#define DoIp_CfgGetNumOfIpAddrAssignment()  (DOIP_NUM_OF_IP_ADDRESS_ASSIGNEMENT)

#define DoIP_LocalAddCfgGetIsUpdAliveTimeoutEnabled(Idx)    (DoIP_LocalAddrConfig[(Idx)].IsUpdAliveTimeoutEnabled)
#define DoIP_LocalAddCfgGetIpAddrAssignmentStartIdx(Idx)    (DoIP_LocalAddrConfig[(Idx)].IpAddrAssignmentStartIdx)
#define DoIP_LocalAddCfgGetIpAddrAssignmentEndIdx(Idx)      (DoIP_LocalAddrConfig[(Idx)].IpAddrAssignmentEndIdx)
#define DoIP_LocalAddCfgGetConMapStartIdx(Idx)              (DoIP_LocalAddrConfig[(Idx)].ConMapStartIdx)
#define DoIP_LocalAddCfgGetConMapEndIdx(Idx)                (DoIP_LocalAddrConfig[(Idx)].ConMapEndIdx)

#define DoIP_RxPduCfgGetChannelIdx(Idx) (DoIP_RxPduConfig[(Idx)].ChannelIdx)

#define DoIP_DefaultTesterCfgGetTesterIdx() (DoIP_DefaultAddrConfig.TesterIdx)

#define DoIP_CfgGetDoIP_TesterToRoutingActivationIdxMap(Idx) (DoIP_TesterToRoutingActivationIdxMap[Idx])

#define DoIP_TxPduIdCfgGetChannelIdx(Idx)   ((DoIP_ChannelIdxType)(Idx))

/* Get, Set macros for DoIP ctrl status */
#define DoIP_ConCtrlGetIpAddrState(Idx)             (DoIP_ConCtrlStatus[(Idx)].IpAddrState)
#define DoIP_ConCtrlGetSoConIdx(Idx)                (DoIP_ConCtrlStatus[(Idx)].SoConIdx)
#define DoIP_ConCtrlGetSoConMode(Idx)               (DoIP_ConCtrlStatus[(Idx)].SoConMode)
#define DoIP_ConCtrlGetSoConCloseReq(Idx)           (DoIP_ConCtrlStatus[(Idx)].SoConCloseReq)

#define DoIP_ConCtrlSetIpAddrState(Idx,Val)         (DoIP_ConCtrlStatus[(Idx)].IpAddrState=(Val))
#define DoIP_ConCtrlSetSoConIdx(Idx,Val)            (DoIP_ConCtrlStatus[(Idx)].SoConIdx=(Val))
#define DoIP_ConCtrlSetSoConMode(Idx,Val)           (DoIP_ConCtrlStatus[(Idx)].SoConMode=(Val))
#define DoIP_ConCtrlSetSoConCloseReq(Idx,Val)       (DoIP_ConCtrlStatus[(Idx)].SoConCloseReq=(Val))

#define DoIP_TcpConCtrlGetRxSkipMsg(Idx)            (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxSkipMsg)
#define DoIP_TcpConCtrlGetRxChannelActive(Idx)      (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxChannelActive)
#define DoIP_TcpConCtrlGetRxTpSessionActive(Idx)    (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxTpSessionActive)
#define DoIP_TcpConCtrlGetRxTpCancelReq(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxTpCancelReq)
#define DoIP_TcpConCtrlGetRxLastBufferSize(Idx)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastBufferSize)
#define DoIP_TcpConCtrlGetRxMsgOffset(Idx)          (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxMsgOffset)
#define DoIP_TcpConCtrlGetRxLastTargetAddr(Idx)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastTargetAddr)
#define DoIP_TcpConCtrlGetRxLastChannelIdx(Idx)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastChannelIdx)

#define DoIP_TcpConCtrlSetRxSkipMsg(Idx,Val)            (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxSkipMsg=(Val))
#define DoIP_TcpConCtrlSetRxChannelActive(Idx,Val)      (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxChannelActive=(Val))
#define DoIP_TcpConCtrlSetRxTpSessionActive(Idx,Val)    (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxTpSessionActive=(Val))
#define DoIP_TcpConCtrlSetRxTpCancelReq(Idx,Val)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxTpCancelReq=(Val))
#define DoIP_TcpConCtrlSetRxLastBufferSize(Idx,Val)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastBufferSize=(Val))
#define DoIP_TcpConCtrlSetRxMsgOffset(Idx,Val)          (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxMsgOffset=(Val))
#define DoIP_TcpConCtrlSetRxLastTargetAddr(Idx,Val)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastTargetAddr=(Val))
#define DoIP_TcpConCtrlSetRxLastChannelIdx(Idx,Val)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConRxCtrlStatus.RxLastChannelIdx=(Val))

#define DoIP_TxTcpQueueElementCtrlGetChannelIdx(Idx)                (DoIP_TxTcpQueue[(Idx)].ChannelIdx)
#define DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfoLength(Idx)        (DoIP_TxTcpQueue[(Idx)].TxTcpPduInfo.SduLength)
#define DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfoSduDataPtr(Idx)    (DoIP_TxTcpQueue[(Idx)].TxTcpPduInfo.SduDataPtr)
#define DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(Idx)    (DoIP_TxTcpQueue[(Idx)].TxTcpPduInfo)
#define DoIP_TxTcpQueueElementCtrlGetHeaderBufferLength(Idx)        (DoIP_TxTcpQueue[(Idx)].HeaderBufferLength)

#define DoIP_TxTcpQueueElementCtrlSetChannelIdx(Idx,Val)            (DoIP_TxTcpQueue[(Idx)].ChannelIdx=(Val))
#define DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(Idx,Val)        (DoIP_TxTcpQueue[(Idx)].TxTcpPduInfo.SduLength=(Val))
#define DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(Idx,Val)    (DoIP_TxTcpQueue[(Idx)].TxTcpPduInfo.SduDataPtr=(Val))
#define DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(Idx,Val)    (DoIP_TxTcpQueue[(Idx)].HeaderBufferLength=(Val))


#define DoIP_TcpConCtrlGetTxTpCancelReq(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpCancelReq)
#define DoIP_TcpConCtrlGetTxTpSessionActive(Idx)    (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpSessionActive)
#define DoIP_TcpConCtrlGetTxTpCloseSocketReq(Idx)   (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpCloseSocketReq)
#define DoIP_TcpConCtrlGetTxLastBufferSize(Idx)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxLastBufferSize)
#define DoIP_TcpConCtrlGetTxBytesCopied(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxBytesCopied)
#define DoIP_TcpConCtrlGetTxTcpQueueElementIdx(Idx) (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TcpTxQueueElementIdx)
#define DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(Idx)  (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTcpCtrlQueueLevel)
#define DoIP_TcpConCtrlGetTxTpHeaderType(Idx)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpHeaderType)
#define DoIP_TcpConCtrlGetTxTpFirstParam(Idx)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpFirstParam)
#define DoIP_TcpConCtrlGetTxTpSecondParam(Idx)      (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpSecondParam)
#define DoIP_TcpConCtrlGetTxTpThirdParam(Idx)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpThirdParam)

#define DoIP_TcpConCtrlIncTxTcpCtrlQueueLevel(Idx)  (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTcpCtrlQueueLevel++)
#define DoIP_TcpConCtrlDecTxTcpCtrlQueueLevel(Idx)  (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTcpCtrlQueueLevel--)
#define DoIP_TcpConCtrlIncTxTcpQueueElementIdx(Idx) (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TcpTxQueueElementIdx++)
#define DoIP_TcpConCtrlDecTxTcpQueueElementIdx(Idx) (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TcpTxQueueElementIdx--)

#define DoIP_TcpConCtrlSetTxTpCancelReq(Idx,Val)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpCancelReq=(Val))
#define DoIP_TcpConCtrlSetTxTpSessionActive(Idx,Val)    (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpSessionActive=(Val))
#define DoIP_TcpConCtrlSetTxTpCloseSocketReq(Idx,Val)   (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpCloseSocketReq=(Val))
#define DoIP_TcpConCtrlSetTxLastBufferSize(Idx,Val)     (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxLastBufferSize=(Val))
#define DoIP_TcpConCtrlSetTxBytesCopied(Idx,Val)        (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxBytesCopied=(Val))
#define DoIP_TcpConCtrlSetTxTcpQueueElementIdx(Idx,Val) (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TcpTxQueueElementIdx=(Val))
#define DoIP_TcpConCtrlSetTxTcpCtrlQueueLevel(Idx,Val)  (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTcpCtrlQueueLevel=(Val))
#define DoIP_TcpConCtrlSetTxTpHeaderType(Idx,Val)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpHeaderType=(Val))
#define DoIP_TcpConCtrlSetTxTpFirstParam(Idx,Val)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpFirstParam=(Val))
#define DoIP_TcpConCtrlSetTxTpSecondParam(Idx,Val)      (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpSecondParam=(Val))
#define DoIP_TcpConCtrlSetTxTpThirdParam(Idx,Val)       (DoIP_TcpConCtrlStatus[(Idx)].TcpConTxCtrlStatus.TxTpThirdParam=(Val))

#define DoIP_TcpConCtrlGetTesterAddr(Idx)               (DoIP_TcpConCtrlStatus[(Idx)].TesterAddr)
#define DoIP_TcpConCtrlGetTesterIdx(Idx)                (DoIP_TcpConCtrlStatus[(Idx)].TesterIdx)
#define DoIP_TcpConCtrlGetRoutingActivationIdx(Idx)     (DoIP_TcpConCtrlStatus[(Idx)].RoutingActivationIdx)
#define DoIP_TcpConCtrlGetRoutingActivationState(Idx)   (DoIP_TcpConCtrlStatus[(Idx)].RoutingActivationState)
#define DoIP_TcpConCtrlGetLocalIpAddress(Idx)           (DoIP_TcpConCtrlStatus[(Idx)].LocalIpAddress)
#define DoIP_TcpConCtrlGetRemoteIpAddress(Idx)          (DoIP_TcpConCtrlStatus[(Idx)].RemoteIpAddress)
#define DoIP_TcpConCtrlGetInactiveTimeCount(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].InactiveTimeCount)

#define DoIP_TcpConCtrlIncInactiveTimeCount(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].InactiveTimeCount++)
#define DoIP_TcpConCtrlDecInactiveTimeCount(Idx)        (DoIP_TcpConCtrlStatus[(Idx)].InactiveTimeCount--)

#define DoIP_TcpConCtrlSetTesterAddr(Idx,Val)               (DoIP_TcpConCtrlStatus[(Idx)].TesterAddr=(Val))
#define DoIP_TcpConCtrlSetTesterIdx(Idx,Val)                (DoIP_TcpConCtrlStatus[(Idx)].TesterIdx=(Val))
#define DoIP_TcpConCtrlSetRoutingActivationIdx(Idx,Val)     (DoIP_TcpConCtrlStatus[(Idx)].RoutingActivationIdx=(Val))
#define DoIP_TcpConCtrlSetRoutingActivationState(Idx,Val)   (DoIP_TcpConCtrlStatus[(Idx)].RoutingActivationState=(Val))
#define DoIP_TcpConCtrlSetLocalIpAddress(Idx,Val)           (DoIP_TcpConCtrlStatus[(Idx)].LocalIpAddress=(Val))
#define DoIP_TcpConCtrlSetRemoteIpAddress(Idx,Val)          (DoIP_TcpConCtrlStatus[(Idx)].RemoteIpAddress=(Val))
#define DoIP_TcpConCtrlSetInactiveTimeCount(Idx,Val)        (DoIP_TcpConCtrlStatus[(Idx)].InactiveTimeCount=(Val))

#define DoIP_UdpConCtrlGetConIdx(Idx)           (DoIP_UdpConCtrlStatus[(Idx)].ConIdx)
#define DoIP_UdpConCtrlGetTxRetryCount(Idx)     (DoIP_UdpConCtrlStatus[(Idx)].TxRetryCount)
#define DoIP_UdpConCtrlGetTxHeaderType(Idx)     (DoIP_UdpConCtrlStatus[(Idx)].TxHeaderType)
#define DoIP_UdpConCtrlGetTxFirstParam(Idx)     (DoIP_UdpConCtrlStatus[(Idx)].TxFirstParam)
#define DoIP_UdpConCtrlGetTxSecondParam(Idx)    (DoIP_UdpConCtrlStatus[(Idx)].TxSecondParam)
#define DoIP_UdpConCtrlGetRemoteIpAddress(Idx)  (DoIP_UdpConCtrlStatus[(Idx)].RemoteIpAddress)

#define DoIP_UdpConCtrlSetConIdx(Idx,Val)           (DoIP_UdpConCtrlStatus[(Idx)].ConIdx=(Val))
#define DoIP_UdpConCtrlSetTxRetryCount(Idx,Val)     (DoIP_UdpConCtrlStatus[(Idx)].TxRetryCount=(Val))
#define DoIP_UdpConCtrlSetTxHeaderType(Idx,Val)     (DoIP_UdpConCtrlStatus[(Idx)].TxHeaderType=(Val))
#define DoIP_UdpConCtrlSetTxFirstParam(Idx,Val)     (DoIP_UdpConCtrlStatus[(Idx)].TxFirstParam=(Val))
#define DoIP_UdpConCtrlSetTxSecondParam(Idx,Val)    (DoIP_UdpConCtrlStatus[(Idx)].TxSecondParam=(Val))
#define DoIP_UdpConCtrlSetRemoteIpAddress(Idx,Val)  (DoIP_UdpConCtrlStatus[(Idx)].RemoteIpAddress=(Val))

#define DoIP_UdpTxCtrlGetConIdx(Idx)           (DoIP_UdpTxCtrlStatus[(Idx)].ConIdx)
#define DoIP_UdpTxCtrlGetTxRetryCount(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxRetryCount)
#define DoIP_UdpTxCtrlGetTxHeaderType(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxHeaderType)
#define DoIP_UdpTxCtrlGetTxFirstParam(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxFirstParam)
#define DoIP_UdpTxCtrlGetTxSecondParam(Idx)    (DoIP_UdpTxCtrlStatus[(Idx)].TxSecondParam)
#define DoIP_UdpTxCtrlGetRemoteIpAddress(Idx)  (DoIP_UdpTxCtrlStatus[(Idx)].RemoteIpAddress)

#define DoIP_UdpTxCtrlIncTxFirstParam(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxFirstParam++)
#define DoIP_UdpTxCtrlDecTxFirstParam(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxFirstParam--)

#define DoIP_UdpTxCtrlIncTxSecondParam(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxSecondParam++)
#define DoIP_UdpTxCtrlDecTxSecondParam(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxSecondParam--)

#define DoIP_UdpTxCtrlIncTxRetryCount(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxRetryCount++)
#define DoIP_UdpTxCtrlDecTxRetryCount(Idx)     (DoIP_UdpTxCtrlStatus[(Idx)].TxRetryCount--)

#define DoIP_UdpTxCtrlSetConIdx(Idx,Val)           (DoIP_UdpTxCtrlStatus[(Idx)].ConIdx=(Val))
#define DoIP_UdpTxCtrlSetTxRetryCount(Idx,Val)     (DoIP_UdpTxCtrlStatus[(Idx)].TxRetryCount=(Val))
#define DoIP_UdpTxCtrlSetTxHeaderType(Idx,Val)     (DoIP_UdpTxCtrlStatus[(Idx)].TxHeaderType=(Val))
#define DoIP_UdpTxCtrlSetTxFirstParam(Idx,Val)     (DoIP_UdpTxCtrlStatus[(Idx)].TxFirstParam=(Val))
#define DoIP_UdpTxCtrlSetTxSecondParam(Idx,Val)    (DoIP_UdpTxCtrlStatus[(Idx)].TxSecondParam=(Val))
#define DoIP_UdpTxCtrlSetRemoteIpAddress(Idx,Val)  (DoIP_UdpTxCtrlStatus[(Idx)].RemoteIpAddress=(Val))

#define DoIP_ChannelCtrlCfgGetTxLength(Idx)     (DoIP_ChannelCtrlStatus[(Idx)].TxLength)
#define DoIP_ChannelCtrlCfgSetTxLength(Idx,Val) (DoIP_ChannelCtrlStatus[(Idx)].TxLength=(Val))

#define DoIP_TesterCtrlGetTcpConIdx(Idx)            (DoIP_TesterCtrlStatus[(Idx)].TcpConIdx)
#define DoIP_TesterCtrlGetNegativeAckOffset(Idx)    (DoIP_TesterCtrlStatus[(Idx)].NegativeAckOffset)

#define DoIP_TesterCtrlSetTcpConIdx(Idx,Val)            (DoIP_TesterCtrlStatus[(Idx)].TcpConIdx=(Val))
#define DoIP_TesterCtrlSetNegativeAckOffset(Idx,Val)    (DoIP_TesterCtrlStatus[(Idx)].NegativeAckOffset=(Val))


#define DoIP_RoutingActivationCtrlGetOemReqResUsed()         (DoIP_RoutingActivationCtrlStatus.OemReqResUsed)
#define DoIP_RoutingActivationCtrlGetOemRequest()            (DoIP_RoutingActivationCtrlStatus.OemRequest)
#define DoIP_RoutingActivationCtrlGetOemResponse()           (DoIP_RoutingActivationCtrlStatus.OemResponse)
#define DoIP_RoutingActivationCtrlGetAliveCheckCount()       (DoIP_RoutingActivationCtrlStatus.AliveCheckCount)
#define DoIP_RoutingActivationCtrlGetTcpConIdx()             (DoIP_RoutingActivationCtrlStatus.TcpConIdx)
#define DoIP_RoutingActivationCtrlGetTesterAddr()            (DoIP_RoutingActivationCtrlStatus.TesterAddr)
#define DoIP_RoutingActivationCtrlGetTesterIdx()             (DoIP_RoutingActivationCtrlStatus.TesterIdx)
#define DoIP_RoutingActivationCtrlGetRoutingActivationIdx()  (DoIP_RoutingActivationCtrlStatus.RoutingActivationIdx)
#define DoIP_RoutingActivationCtrlGetAliveCheckElemNum()     (DoIP_RoutingActivationCtrlStatus.AliveCheckElemNum)

#define DoIP_RoutingActivationCtrlIncAliveCheckCount()       (DoIP_RoutingActivationCtrlStatus.AliveCheckCount++)
#define DoIP_RoutingActivationCtrlDecAliveCheckCount()       (DoIP_RoutingActivationCtrlStatus.AliveCheckCount--)

#define DoIP_RoutingActivationCtrlSetOemReqResUsed(Val)         (DoIP_RoutingActivationCtrlStatus.OemReqResUsed=(Val))
#define DoIP_RoutingActivationCtrlSetOemRequest(Val)            (DoIP_RoutingActivationCtrlStatus.OemRequest=(Val))
#define DoIP_RoutingActivationCtrlSetOemResponse(Val)           (DoIP_RoutingActivationCtrlStatus.OemResponse=(Val))
#define DoIP_RoutingActivationCtrlSetAliveCheckCount(Val)       (DoIP_RoutingActivationCtrlStatus.AliveCheckCount=(Val))
#define DoIP_RoutingActivationCtrlSetTcpConIdx(Val)             (DoIP_RoutingActivationCtrlStatus.TcpConIdx=(Val))
#define DoIP_RoutingActivationCtrlSetTesterAddr(Val)            (DoIP_RoutingActivationCtrlStatus.TesterAddr=(Val))
#define DoIP_RoutingActivationCtrlSetTesterIdx(Val)             (DoIP_RoutingActivationCtrlStatus.TesterIdx=(Val))
#define DoIP_RoutingActivationCtrlSetRoutingActivationIdx(Val)  (DoIP_RoutingActivationCtrlStatus.RoutingActivationIdx=(Val))
#define DoIP_RoutingActivationCtrlSetAliveCheckElemNum(Val)     (DoIP_RoutingActivationCtrlStatus.AliveCheckElemNum=(Val))

#define DoIP_OemPayloadCtrlGetTcpBufferReqTx()   (DoIP_OemPayloadCtrlStatus.TcpBufferReqTx)
#define DoIP_OemPayloadCtrlGetTcpBufferConIdx()  (DoIP_OemPayloadCtrlStatus.TcpBufferConIdx)
#define DoIP_OemPayloadCtrlGetTcpBufferLength()  (DoIP_OemPayloadCtrlStatus.TcpBufferLength)
#define DoIP_OemPayloadCtrlGetUdpBufferLength()  (DoIP_OemPayloadCtrlStatus.UdpBufferLength)

#define DoIP_OemPayloadCtrlSetTcpBufferReqTx(Val)   (DoIP_OemPayloadCtrlStatus.TcpBufferReqTx=(Val))
#define DoIP_OemPayloadCtrlSetTcpBufferConIdx(Val)  (DoIP_OemPayloadCtrlStatus.TcpBufferConIdx=(Val))
#define DoIP_OemPayloadCtrlSetTcpBufferLength(Val)  (DoIP_OemPayloadCtrlStatus.TcpBufferLength=(Val))
#define DoIP_OemPayloadCtrlSetUdpBufferLength(Val)  (DoIP_OemPayloadCtrlStatus.UdpBufferLength=(Val))

#define DoIP_CtrlGetActivationLineInactiveReq()     (DoIP_ActivationLineInactiveReq)
#define DoIP_CtrlSetActivationLineInactiveReq(Val)  (DoIP_ActivationLineInactiveReq=(Val))

#define DoIP_CtrlGetActivationLineState()           (DoIP_ActivationLineState)
#define DoIP_CtrlSetActivationLineState(Val)        (DoIP_ActivationLineState=(Val))

#define DoIP_CtrlGetActivationLineState()           (DoIP_ActivationLineState)
#define DoIP_CtrlSetActivationLineState(Val)        (DoIP_ActivationLineState=(Val))

#define DoIP_CtrlGetPduSizeRoutingStatus()          (DoIP_PduSizeRoutingStatus)
#define DoIP_CtrlSetPduSizeRoutingStatus(Val)       (DoIP_PduSizeRoutingStatus=(Val))

#define DoIP_CtrlGetGroupIdInSyncStatus()           (DoIP_GroupIdInSyncStatus)
#define DoIP_CtrlSetGroupIdInSyncStatus(Val)        (DoIP_GroupIdInSyncStatus=(Val))

#define DoIP_CfgGetDefaultActivationLineState()     DOIP_ACTIVATION_LINE_INACTIVE

#define DoIP_ConCfgGetLocalIpAddrIdx(Idx)   (DoIP_ConnectionConfig[(Idx)].LocalIpAddrIdx)
#define DoIP_ConCfgGetRxCancelPduId(Idx)    (DoIP_ConnectionConfig[(Idx)].RxCancelPduId)
#define DoIP_ConCfgGetTxPduId(Idx)          (DoIP_ConnectionConfig[(Idx)].TxPduId)

#define DoIP_IpAddrAssignmentCtrlGetIpAddrReqState(Idx) (DoIP_IpAddrAssignmentCtrl[(Idx)].IpAddrReqState)
#define DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(Idx,Val) (DoIP_IpAddrAssignmentCtrl[(Idx)].IpAddrReqState=(Val))

#endif /* DOIP_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


