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
/*!******************************************************************************************************************
*   @file SoAd.h
*   @ingroup SoAd
*   @brief This file provides the declaration of the SoAd API. This header file should be included by other
*   modules that use the SoAd API.
*   @defgroup SoAd
*   @brief The main purpose of the SoAd module is to create an interface between an AUTOSAR communication service 
*   module using PDUs (e.g. PDU Router) and a socket based TCP/IP stack. It will map I-PDU IDs to socket connections 
*   and vice versa.
********************************************************************************************************************/
#ifndef SOAD_H
#define SOAD_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_Cfg.h"
#include "SoAd_Types.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the SoAd SW major version */
#define SOAD_SW_MAJOR_VERSION                   1u
/*! @brief Defines the SoAd SW minor version */
#define SOAD_SW_MINOR_VERSION                   0u
/*! @brief Defines the SoAd SW patch version */
#define SOAD_SW_PATCH_VERSION                   0u
/* Autosar Release */
/*! @brief Defines the SoAd AUTOSAR major version */
#define SOAD_AR_RELEASE_MAJOR_VERSION           4u
/*! @brief Defines the SoAd AUTOSAR minor version */
#define SOAD_AR_RELEASE_MINOR_VERSION           3u
/*! @brief Defines the SoAd AUTOSAR patch version */
#define SOAD_AR_RELEASE_REVISION_VERSION        1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of SoAd module. */
#define SOAD_VENDOR_ID                          0x0033u
/*! @brief Defines the Module Id of SoAd module.*/
#define SOAD_MODULE_ID                          056u
/*! @brief Defines the version Id of SoAd module.*/
#define SOAD_INSTANCE_ID                        0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for SoAd_GetVersionInfo function */
#define SOAD_GETVERSIONINFO_API                 0x02u
/*! @brief Defines the service Id for SoAd_Init function */
#define SOAD_INIT_API                           0x01u
/*! @brief Defines the service Id for SoAd_IfTransmit function */
#define SOAD_IFTRANSMIT_API                     0x49u
/*! @brief Defines the service Id for SoAd_IfRoutingGroupTransmit function */
#define SOAD_IFROUTINGGROUPTRANSMIT_API         0x1Du
/*! @brief Defines the service Id for SoAd_IfSpecificRoutingGroupTransmit function */
#define SOAD_IFSPECIFICROUTINGGROUPTRANSMIT_API 0x1fu
/*! @brief Defines the service Id for SoAd_TpTransmit function */
#define SOAD_TPTRANSMIT_API                     0x49u
/*! @brief Defines the service Id for SoAd_TpCancelTransmit function */
#define SOAD_TPCANCELTRANSMIT_API               0x4Au
/*! @brief Defines the service Id for SoAd_TpCancelReceive function */
#define SOAD_TPCANCELRECEIVE_API                0x4Cu
/*! @brief Defines the service Id for SoAd_GetSoConId function */
#define SOAD_GETSOCONID_API                     0x07u
/*! @brief Defines the service Id for SoAd_OpenSoCon function */
#define SOAD_OPENSOCON_API                      0x08u
/*! @brief Defines the service Id for SoAd_CloseSoCon function */
#define SOAD_CLOSESOCON_API                     0x09u
/*! @brief Defines the service Id for SoAd_GetSoConMode function */
#define SOAD_GETSOCONMODE_API                   0x22u
/*! @brief Defines the service Id for SoAd_RequestIpAddrAssignment function */
#define SOAD_REQUESTIPADDRASSIGNMENT_API        0x0Au
/*! @brief Defines the service Id for SoAd_ReleaseIpAddrAssignment function */
#define SOAD_RELEASEIPADDRASSIGNMENT_API        0x0Bu
/*! @brief Defines the service Id for SoAd_GetLocalAddr function */
#define SOAD_GETLOCALADDR_API                   0x0Cu
/*! @brief Defines the service Id for SoAd_GetPhysAddr function */
#define SOAD_GETPHYSADDR_API                    0x0Du
/*! @brief Defines the service Id for SoAd_GetRemoteAddr function */
#define SOAD_GETREMOTEADDR_API                  0x1Cu
/*! @brief Defines the service Id for SoAd_EnableRouting function */
#define SOAD_ENABLEROUTING_API                  0x0Eu
/*! @brief Defines the service Id for SoAd_EnableSpecificRouting function */
#define SOAD_ENABLESPECIFICROUTING_API          0x20u
/*! @brief Defines the service Id for SoAd_DisableRouting function */
#define SOAD_DISABLEROUTING_API                 0x0Fu
/*! @brief Defines the service Id for SoAd_DisableSpecificRouting function */
#define SOAD_DISABLESPECIFICROUTING_API         0x21u
/*! @brief Defines the service Id for SoAd_SetRemoteAddr function */
#define SOAD_SETREMOTEADDR_API                  0x10u
/*! @brief Defines the service Id for SoAd_SetUniqueRemoteAddr function */
#define SOAD_SETUNIQUEREMOTEADDR_API            0x1Eu
/*! @brief Defines the service Id for SoAd_ReleaseRemoteAddr function */
#define SOAD_RELEASEREMOTEADDR_API              0x23u
/*! @brief Defines the service Id for SoAd_TpChangeParameter function */
#define SOAD_TPCHANGEPARAMETER_API              0x4bu
/*! @brief Defines the service Id for SoAd_ReadDhcpHostNameOption function */
#define SOAD_READDHCPHOSTNAMEOPTION_API         0x1Au
/*! @brief Defines the service Id for SoAd_WriteDhcpHostNameOption function */
#define SOAD_WRITEDHCPHOSTNAMEOPTION_API        0x1Bu
/*! @brief Defines the service Id for SoAd_GetAndResetMeasurementData function */
#define SOAD_GETANDRESETMEASUREMENTDATA_API     0x45u
/*! @brief Defines the service Id for SoAd_RxIndication function */
#define SOAD_RXINDICATION_API                   0x12u
/*! @brief Defines the service Id for SoAd_CopyTxData function */
#define SOAD_COPYTXDATA_API                     0x13u
/*! @brief Defines the service Id for SoAd_TxConfirmation function */
#define SOAD_TXCONFIRMATION_API                 0x14u
/*! @brief Defines the service Id for SoAd_TcpAccepted function */
#define SOAD_TCPACCEPTED_API                    0x15u
/*! @brief Defines the service Id for SoAd_TcpConnected function */
#define SOAD_TCPCONNECTED_API                   0x16u
/*! @brief Defines the service Id for SoAd_TcpIpEvent function */
#define SOAD_TCPIPEVENT_API                     0x17u
/*! @brief Defines the service Id for SoAd_LocalIpAddrAssignmentChg function */
#define SOAD_LOCALIPADDRASSIGNMENTCHG_API       0x18u
/*! @brief Defines the service Id for SoAd_MainFunction function */
#define SOAD_MAINFUNCTION_API                   0x19u
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called before initializing the module */
#define SOAD_E_UNINIT		 		            0x01u
/*! @brief API service called with NULL pointer */
#define SOAD_E_PARAM_POINTER		            0x02u
/*! @brief API service called with Invalid argument */
#define SOAD_E_INV_ARG		                    0x03u
/*! @brief API service called with Invalid PDU ID */
#define SOAD_E_INV_PDUID		                0x06u
/*! @brief API service called with Invalid socket address */
#define SOAD_E_INV_SOCKETID		                0x07u
/*! @brief API service called with Invaid configuration set selection */
#define SOAD_E_INIT_FAILED		                0x08u
/*! @brief API service called with Invalid meta data */
#define SOAD_E_INV_METADATA		                0x09u
/*! @brief API No error ID */
#define SOAD_E_NO_ERROR                         0xFFu
#include "SoAd_PBcfg.h"
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      Initializes the Socket Adaptor.
*   @param[in]  SoAdConfigPtr Pointer to the configuration data of the SoAd module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_Init( P2CONST(SoAd_ConfigType,AUTOMATIC,SOAD_APPL_CONST) SoAdConfigPtr );
/*!******************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,SOAD_APPL_VAR) versioninfo );
/*!******************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  PduInfoPtr  Length of and pointer to the PDU data and pointer to MetaData
*   @return     Std_ReturnType E_OK: Transmit request has been accepted.
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfTransmit
( 
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,SOAD_APPL_CONST) PduInfoPtr 
);
/*!******************************************************************************************************************
*   @brief      Triggers the transmission of all If-TxPDUs identified by the parameter id after requesting the data
*               from the related upper layer.
*   @param[in]  id  routing group identifier indirectly specifying PDUs to be transmitted
*   @return     Std_ReturnType Result of operation E_OK The request was successful 
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x1D
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfRoutingGroupTransmit( SoAd_RoutingGroupIdType id );
/*!******************************************************************************************************************
*   @brief      Triggers the transmission of all If-TxPDUs identified by the parameter id on the socket connection 
*               specified by SoConId after requesting the data from the related upper layer.
*   @param[in]  id  routing group identifier indirectly specifying PDUs to be transmitted
*   @param[in]  SoConId  socket connection index specifying the socket connection on which the PDUs shall be 
*               transmitted
*   @return     Std_ReturnType Result of operation E_OK The request was successful 
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x1F
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfSpecificRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType id,
    SoAd_SoConIdType SoConId 
);
/*!******************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  PduInfoPtr  Length of and pointer to the PDU data and pointer to MetaData
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpTransmit
( 
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,SOAD_APPL_CONST) PduInfoPtr 
);
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
*   @param[in]  TxPduId  Identification of the PDU to be cancelled.
*   @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module. 
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelTransmit( PduIdType TxPduId );
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing reception of a PDU in a lower layer transport protocol module.
*   @param[in]  RxPduId  Identification of the PDU to be cancelled.
*   @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module. 
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelReceive( PduIdType RxPduId );
/*!******************************************************************************************************************
*   @brief      Returns socket connection index related to the specified TxPduId.
*   @param[in]  TxPduId  Transmit PduId specifying the SoAd socket connection for which the socket connection index
*               shall be returned.
*   @param[out] SoConIdPtr  Pointer to memory receiving the socket connection index asked for.
*   @return     Std_ReturnType Result of operation E_OK The request was successful
*               E_NOT_OK The request was not successful
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetSoConId
(
    PduIdType TxPduId, 
    P2VAR(SoAd_SoConIdType,AUTOMATIC,SOAD_APPL_VAR) SoConIdPtr 
);
/*!******************************************************************************************************************
*   @brief      This service opens the socket connection specified by SoConId.
*   @param[in]  SoConId  socket connection index specifying the socket connection which shall be opened.
*   @return     Std_ReturnType Result of operation E_OK The request was successful
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x08
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_OpenSoCon( SoAd_SoConIdType SoConId );
/*!******************************************************************************************************************
*   @brief      This service closes the socket connection specified by SoConId.
*   @param[in]  SoConId  socket connection index specifying the socket connection which shall be closed
*   @param[in]  abort  TRUE: socket connection will immediately be terminated. 
*               FALSE: socket connection will be terminated if no other upper layer is using this socket connection.
*   @return     Std_ReturnType Result of operation E_OK The request was successful
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x09
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_CloseSoCon( SoAd_SoConIdType SoConId, boolean abort );
/*!******************************************************************************************************************
*   @brief      Returns current state of the socket connection specified by SoConId.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the state shall be returned.
*   @param[out] ModePtr Pointer to memory where the socket connection state shall be stored
*   @ServiceID  0x22
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_GetSoConMode
( 
    SoAd_SoConIdType SoConId,
    P2VAR(SoAd_SoConModeType,AUTOMATIC,SOAD_APPL_VAR) ModePtr 
);
/*!******************************************************************************************************************
*   @brief      By this API service the local IP address assignment which shall be used for the socket connection 
*               specified by SoConId is initiated.
*   @param[in]  SoConId Socket connection index specifying the socket connection for which the IP address shall be set
*   @param[in]  Type Type of IP address assignment which shall be initiated.
*   @param[in]  LocalIpAddrPtr Pointer to structure containing the IP address which shall be assigned to the EthIf 
*               controller indirectly specified via SoConId.
*   @param[in]  Netmask Network mask of IPv4 address or address prefix of IPv6 address in CIDR Notation.
*   @param[in]  DefaultRouterPtr Pointer to structure containing the IP address of the default router (gateway)
*               which shall be assigned
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0A
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_RequestIpAddrAssignment
( 
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) DefaultRouterPtr 
);
/*!******************************************************************************************************************
*   @brief      By this API service the local IP address assignment used for the socket connection specified by 
*               SoConId is released.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the IP address shall be 
*               released
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0B
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReleaseIpAddrAssignment( SoAd_SoConIdType SoConId );
/*!******************************************************************************************************************
*   @brief      Retrieves the local address (IP address and port) actually used for the SoAd socket connection 
*               specified by SoConId, the netmask and default router
*   @param[in]  SoConId socket connection index representing the SoAd socket connection for which the actual local
*               IP address shall be obtained.
*   @param[in,out]  LocalAddrPtr Pointer to a struct where the local address (IP address and port) is stored.The struct
*               member domain shall be set by the caller of the API to the desired TcpIp_DomainType and it shall be 
*               ensured by the caller that the struct is large enough to store an address of the selected type
*               (INET or INET6).
*   @param[out] NetmaskPtr Pointer to memory where Network mask of IPv4 address or address prefix of IPv6 address in 
*               CIDR Notation is stored 
*   @param[in,out] DefaultRouterPtr Pointer to struct where the IP address of the default router (gateway) is stored
*               (struct member "port" is not used and of arbitrary value). The struct must be of the same type and size
*               as LocalAddrPtr
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetLocalAddr
( 
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) DefaultRouterPtr 
);
/*!******************************************************************************************************************
*   @brief      Retrieves the physical source address of the EthIf controller used by the SoAd socket connection 
*               specified by SoConId.
*   @param[in]  SoConId socket connection index representing the SoAd socket connection for which the physical source
*               address of the related EthIf controller shall be obtained.
*   @param[out] PhysAddrPtr Pointer to the memory where the physical source address (MAC address) in network byte
*               order is stored
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0D
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetPhysAddr
( 
    SoAd_SoConIdType SoConId, 
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) PhysAddrPtr 
);
/*!******************************************************************************************************************
*   @brief      Retrieves the remote address (IP address and port) actually used for the SoAd socket connection 
*               specified by SoConId
*   @param[in]  SoConId socket connection index representing the SoAd socket connection for which the actually 
*               specified remote address shall be obtained.
*   @param[out] IpAddrPtr Pointer to a struct where the retrieved remote address (IP address and port) is stored
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x1C
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) IpAddrPtr
);
/*!******************************************************************************************************************
*   @brief      Enables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id. 
*               Routing of PDUs can be either forwarding of PDUs from the upper layer to a TCP or UDP socket of the 
*               TCP/IP stack specified by a PduRoute or the other way around specified by a SocketRoute
*   @param[in]  id routing group identifier specifying the routing group to be enabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableRouting( SoAd_RoutingGroupIdType id );
/*!******************************************************************************************************************
*   @brief      Enables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id 
*               only on the socket connection identified by SoConId.
*   @param[in]  id routing group identifier specifying the routing group to be enabled
*   @param[in]  SoConId socket connection index specifying the socket connection on which the routing group shall be 
*               enabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x20
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableSpecificRouting(SoAd_RoutingGroupIdType id,SoAd_SoConIdType SoConId);
/*!******************************************************************************************************************
*   @brief      Disables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id.
*               Routing of PDUs can be either forwarding of PDUs from the upper layer to a TCP or UDP socket of the 
*               TCP/IP stack specified by a PduRoute or the other way around specified by a SocketRoute.
*   @param[in]  id routing group identifier specifying the routing group to be disabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableRouting( SoAd_RoutingGroupIdType id );
/*!******************************************************************************************************************
*   @brief      Disables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id
*               only on the socket connection identified by SoConId.
*   @param[in]  id routing group identifier specifying the routing group to be disabled
*   @param[in]  SoConId socket connection index specifying the socket connection on which the routing group shall 
*               be disabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x21
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableSpecificRouting(SoAd_RoutingGroupIdType id,SoAd_SoConIdType SoConId);
/*!******************************************************************************************************************
*   @brief      By this API service the remote address (IP address and port) of the specified socket connection shall
*               be set.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the remote address shall be
*               set
*   @param[in]  RemoteAddrPtr Struct containint the IP address and port to be set.
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetRemoteAddr
( 
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr 
);
/*!******************************************************************************************************************
*   @brief      This API service shall either return the socket connection index of the SoAdSocketConnectionGroup 
*               where the specified remote address (IP address and port) is set or assign the remote address to an 
*               unused socket connection from the same SoAdSocketConnectionGroup.
*   @param[in]  SoConId Index of any socket connection that is part of the SoAdSocketConnectionGroup.
*   @param[in]  RemoteAddrPtr Pointer to the structure containing the requested remote IP address and port.
*   @param[out] AssignedSoConIdPtr Pointer to the SoAd_SoConIdType where the index of the socket connection configured
*               with the remote address (RemoteAddrPtr) shall be stored.
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x1e
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetUniqueRemoteAddr
( 
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2VAR(SoAd_SoConIdType,AUTOMATIC,SOAD_APPL_VAR) AssignedSoConIdPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the remote address (IP address and port) of the specified socket connection 
*               shall be released, i.e. set back to the configured remote address setting.
*   @param[in]  SoConId Index of the socket connection for which the remote address shall be released.
*   @ServiceID  0x23
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_ReleaseRemoteAddr( SoAd_SoConIdType SoConId );
/*!******************************************************************************************************************
*   @brief      Request to change a specific transport protocol parameter (e.g. block size).
*   @param[in]  id Identification of the PDU which the parameter change shall affect.
*   @param[in]  parameter ID of the parameter that shall be changed.
*   @param[in]  value The new value of the parameter.
*   @return     Std_ReturnType E_OK: The parameter was changed successfully. 
*               E_NOT_OK: The parameter change was rejected.
*   @ServiceID  0x4b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);
/*!******************************************************************************************************************
*   @brief      By this API service an upper layer of the SoAd can read the currently configured hostname, 
*               i.e. FQDN option in the DHCP submodule of the TCP/IP stack
*   @param[in]  SoConId socket connection index specifying the socket connection for which the hostname shall be read
*   @param[in,out] length As input parameter, contains the length of the provided data buffer. 
*               Will be overwritten with the length of the actual data.
*   @param[out] data Pointer to provided memory buffer the hostname, i.e. the Fully Qualified Domain Name (FQDN)
*               according to IETF RFC 4702/IETF RFC 4704 will be copied to.
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x1A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReadDhcpHostNameOption
( 
    SoAd_SoConIdType SoConId,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) length,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) data
);
/*!******************************************************************************************************************
*   @brief      By this API service an upper layer of the SoAd can set the hostname, i.e. FQDN option in the DHCP 
*               submodule of the TCP/IP stack.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the hostname shall be 
*               changed
*   @param[in]  length Length of hostname to be set.
*   @param[in]  data Pointer to memory containing the hostname, i.e. the Fully Qualified Domain Name (FQDN) 
*               according to IETF RFC 4702/IETF RFC 4704.
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x1B
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_WriteDhcpHostNameOption
( 
    SoAd_SoConIdType SoConId,
    uint8 length,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) data
);
/*!******************************************************************************************************************
*   @brief      Allows to read and reset detailed measurement data for diagnostic purposes. Get all MeasurementIdx's 
*               at once is not supported. SOAD_MEAS_ALL shall only be used to reset all MeasurementIdx's at once. 
*               A NULL_PTR shall be provided for MeasurementDataPtr in this case.
*   @param[in]  MeasurementIdx Data index of measurement data
*   @param[in]  MeasurementResetNeeded Flag to trigger a reset of the measurement data
*   @param[out] MeasurementDataPtr Reference to data buffer, where to copy measurement data
*   @return     Std_ReturnType E_OK: successful E_NOT_OK: failed
*   @ServiceID  0x45
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetAndResetMeasurementData
( 
    SoAd_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,SOAD_APPL_VAR) MeasurementDataPtr 
);
/*!******************************************************************************************************************
*   @brief      Schedules the Socket Adaptor. (Entry point for scheduling)
*   @ServiceID  0x19
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_MainFunction( void );

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SOAD_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

