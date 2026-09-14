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
*   @file SoAd.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd module is to create an interface between an AUTOSAR communication service 
*   module using PDUs (e.g. PDU Router) and a socket based TCP/IP stack. It will map I-PDU IDs to socket connections 
*   and vice versa.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Internal.h"
#include "SoAd_Lcfg.h"
#include "SoAd_PBcfg.h"
#include "SchM_SoAd.h"
#include "SoAd_Tx.h"
#include "SoAd_Rx.h"
#include "SoAd_Socket.h"
#include "SoAd_TcpIpIf.h"
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((SOAD_SW_MAJOR_VERSION != SOAD_CFG_SW_MAJOR_VERSION) || \
    (SOAD_SW_MINOR_VERSION != SOAD_CFG_SW_MINOR_VERSION) || \
    (SOAD_SW_PATCH_VERSION != SOAD_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((SOAD_AR_RELEASE_MAJOR_VERSION != SOAD_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (SOAD_AR_RELEASE_MINOR_VERSION != SOAD_CFG_AR_RELEASE_MINOR_VERSION) || \
    (SOAD_AR_RELEASE_REVISION_VERSION != SOAD_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* @brief Defines the maximum number of open closed request for a socket */
#define SOAD_OPEN_CLOSE_REQ_LIMIT 255u
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
* @brief The api is used to intialize the local address  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_LocalAddrInit(void);
/*!******************************************************************************************************************
* @brief The api is used to intialize the socket connection  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConInit(void);
/*!******************************************************************************************************************
* @brief The api is used to  initialize the routing groups.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RoutingGroupInit(void);
/*!******************************************************************************************************************
* @brief The api is used to reset the remote address of the  the socket connection 
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConResetRemoteAddr(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to handle the procesing of the socket connection in main function call
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConMainFunction(void);
/*!******************************************************************************************************************
* @brief The api is used to open the socket connection
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConOpen(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to open the udp socket connection 
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConUdpOpen(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to check for socket state and open socket for reception
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConCheckAndOpenSocketForReception(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to open tcp socket connection
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConTcpOpen(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to process the close request for the socket connection
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConClose(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to handle the socket conncetion close.
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConCloseHandler(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to reset the socket connection close mode and its properties
* @param[in] SoConIdx the socket connection id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConResetCloseMode(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to process whether the connection can be accepted for the socket connection
* @param[in] SoConIdx the socket connection id
* @param[in] RemoteAddrPtr pointer to the remote address of the tcp accept request
* @param[out] pSoConIdx pointer to the matched socket connection id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConTcpGetSoConIdxForAcceptance
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr,
  P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) pSoConIdx
);
/*!******************************************************************************************************************
* @brief The api is used to process the TCP connect request for the accepted socket connection.
* @param[in] SoConIdx the socket connection id
* @param[in] SocketIdConnected the tcpip socket id of the connected socket
* @param[in] RemoteAddrPtr pointer to the remote address of the tcp connect rrequest
* @return status of the request E_OK: request accepted E_NOT_OK: request not accpeted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConTcpConnectAcceptedSoConIdx
(
    SoAd_SoConIdType SoConIdx,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
);
/*!******************************************************************************************************************
* @brief The api is used to for checking the precondition for accepting the remote address
* @param[in] SoConIdx the socket connection id
* @return status of the request E_OK: remote addr state check valid  set E_NOT_OK: remote addr state check not valid
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConCheckStateForSetRemoteAddr(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The api is used to update the remote address for this socket connection 
* @param[in] SoConIdx the socket connection id
* @param[in] RemoteAddrPtr pointer to the remote address to be set
* @return Status of the request E_OK: Remote address set E_NOT_OK: Remote address not set
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConSetRemoteAddr
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
);
/*!******************************************************************************************************************
* @brief The api is used to check if the remote addr is same as the local ip address
* @param[in] SoConIdx the socket connection id
* @param[in] RemoteAddrPtr pointer to the remote address 
* @return Status of the addr comparision E_OK:Local and Rem addr are same E_NOT_OK: Local and Rem addr are different
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConIsSoConIpAddrSameAsRemAddr
(
    SoAd_SoConIdType SoConIdx, 
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
);
/*!******************************************************************************************************************
* @brief The api is used to notify the Ip addr assignment state to the Socket connection id users
* @param[in] SoConIdx the socket connection id
* @param[in] state Ip addr assignment state
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConNotifyLocalIpAddrAssignmentChg
(
    SoAd_SoConIdType SoConIdx,
    SoAd_IpAddrStateType State
);
/*!******************************************************************************************************************
* @brief The api is used to open socket connection for reception from the remote address
* @param[in] SoConIdx the socket connection id
* @param[in] SoConIdx the remote addr to receive from
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConOpenOnReception
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr
);
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
*   @brief      Initializes the Socket Adaptor.
*   @param[in]  SoAdConfigPtr Pointer to the configuration data of the SoAd module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_Init(P2CONST(SoAd_ConfigType, AUTOMATIC, SOAD_CONST) SoAdConfigPtr)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (SoAdConfigPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else if (FALSE == SoAd_CheckConfigPtr(SoAdConfigPtr))
    {
        ErrorId = SOAD_E_INIT_FAILED;
    }
    else
    {
        /* Set Pb config data */
        SoAd_SetConfigDataPtr(SoAdConfigPtr);
        /* Initialize the Bsd socket */
        SoAd_TcpIpBsdInit();
        /* Initialize SoCon */
        SoAd_SoConInit();
        /* Initialize sockets */
        SoAd_SocketInit();
        /* Initialize local address states */
        SoAd_LocalAddrInit();
        /* Initialize the routing groups */
        SoAd_RoutingGroupInit();
        /* Initialize Udp Timeout */
        SoAd_UdpAliveTimerInit();
        SoAd_TxUdpNPduTimerInit();
        /* set SoAd to Init */
        SoAd_InitStatus = SOAD_INITIALIZED;
    }
#ifdef DLOG
    Dlog_Print(" SoAd_Init status %d \n",SoAd_InitStatus);
#endif
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_INIT_API , ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,SOAD_APPL_VAR) versioninfo )
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (NULL_PTR == versioninfo)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        /* Get version info */
        versioninfo->vendorID = SOAD_VENDOR_ID;
        versioninfo->moduleID = SOAD_MODULE_ID;
        versioninfo->sw_major_version = SOAD_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = SOAD_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = SOAD_SW_PATCH_VERSION;
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETVERSIONINFO_API , ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetSoConId
(
    PduIdType TxPduId, 
    P2VAR(SoAd_SoConIdType,AUTOMATIC,SOAD_APPL_VAR) SoConIdPtr 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SOAD_NUM_OF_TX_PDU <= TxPduId) 
    {
        ErrorId = SOAD_E_INV_PDUID;
    }
    else if (SoConIdPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        /* TxPduId and PduRouteIdx are same, get the id of the PduRouteDestIdx */
        PduRouteDestIdx  = SoAd_PduRouteCfgGetPduRouteDestStartIdx(TxPduId);
        if (PduRouteDestIdx < SOAD_NUM_OF_PDU_ROUTE_DEST)
        {
            *SoConIdPtr = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
            RetVal = E_OK;
        }
    }
        
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETSOCONID_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service opens the socket connection specified by SoConId.
*   @param[in]  SoConId  socket connection index specifying the socket connection which shall be opened.
*   @return     Std_ReturnType Result of operation E_OK The request was successful
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x08
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_OpenSoCon( SoAd_SoConIdType SoConId )
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConId) == TRUE)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        SoAd_EnterCriticalSection();
        if (SoAd_SoConCtrlGetOpenCloseReqCount(SoConId) < SOAD_OPEN_CLOSE_REQ_LIMIT)
        {
            /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
            SoAd_SoConCtrlIncOpenCloseReqCount(SoConId);
            SoAd_SoConCtrlSetSoConEventStateChange(SoConId,TRUE);
            RetVal = E_OK;
        }
        SoAd_ExitCriticalSection();
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_OPENSOCON_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_CloseSoCon(SoAd_SoConIdType SoConId, boolean Abort)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConId) == TRUE)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {   
        SoAd_EnterCriticalSection();
        /* Decrement OpenClose request */
        if (SoAd_SoConCtrlIsOpenCloseReqPending(SoConId) == TRUE)
        {
            SoAd_SoConCtrlDecOpenCloseReqCount(SoConId);
        }
        /* set close req if not pending OpenClose req or Abort is True */
        if ((SoAd_SoConCtrlIsOpenCloseReqPending(SoConId) == FALSE) || (Abort == TRUE))
        {
            if (SoAd_SoConCtrlGetSoConMode(SoConId) != SOAD_SOCON_OFFLINE)
            {
                if (Abort == TRUE)
                {
                    SoAd_SoConCtrlSetAbort(SoConId,TRUE);
                    SoAd_SoConCtrlSetOpenCloseReqCount(SoConId,0u);
                }
                /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
                SoAd_SoConCtrlSetCloseReqType(SoConId,SOAD_CLOSE_REQ_OFFLINE);
                SoAd_SoConCtrlSetSoConEventStateChange(SoConId,TRUE);
            }
        }
        RetVal = E_OK;
        SoAd_ExitCriticalSection();  
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_CLOSESOCON_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Returns current state of the socket connection specified by SoConId.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the state shall be returned.
*   @param[out] ModePtr Pointer to memory where the socket connection state shall be stored
*   @ServiceID  0x22
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_GetSoConMode
( 
    SoAd_SoConIdType SoConId,
    P2VAR(SoAd_SoConModeType,AUTOMATIC,SOAD_APPL_VAR) ModePtr 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if ( NULL_PTR == ModePtr)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        *ModePtr = SoAd_SoConCtrlGetSoConMode(SoConId);  
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETSOCONMODE_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_RequestIpAddrAssignment
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) DefaultRouterPtr 
)
{   
    SoAd_SocketIdxType SocketIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            /* Request Ip address assignment */ 
            RetVal = SoAd_TcpIpIfRequestIpAddrAssignment(LocalAddrIdx, Type,LocalIpAddrPtr, Netmask, DefaultRouterPtr);
            /* Update local port of local static IP address if request was successful. */
            if (RetVal == E_OK)
            {
                if (Type == SOAD_IPADDR_ASSIGNMENT_STATIC)
                {
                    if (SoAd_SocketGetLocalPort(SocketIdx) == SOAD_PORT_ANY)
                    {
                        SoAd_SocketSetLocalPort(SocketIdx,SoAd_UtilpAddrGetPort(LocalIpAddrPtr));
                    }
                }
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_REQUESTIPADDRASSIGNMENT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
} 
/********************************************************************************************************************
*   @brief      By this API service the local IP address assignment used for the socket connection specified by 
*               SoConId is released.
*   @param[in]  SoConId socket connection index specifying the socket connection for which the IP address shall be 
*               released
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0B
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReleaseIpAddrAssignment(SoAd_SoConIdType SoConId)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for dev error */  
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            /* Request TcpIp to release the Ip address assigned */
            RetVal = SoAd_TcpIpIfReleaseIpAddrAssignment(LocalAddrIdx);
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_RELEASEIPADDRASSIGNMENT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetLocalAddr
( 
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) DefaultRouterPtr 
)
{   
    SoAd_SocketIdxType SocketIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if((LocalAddrPtr == NULL_PTR) || (NetmaskPtr == NULL_PTR) || (DefaultRouterPtr == NULL_PTR))
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            /* Get TcpIp IP address. */
            if (SoAd_TcpIpIfGetIpAddr(LocalAddrIdx,LocalAddrPtr,NetmaskPtr,DefaultRouterPtr) == E_NOT_OK)
            {
                SoAd_UtilpAddrSetIpv4Addr(LocalAddrPtr,SOAD_IPADDR_ANY);
            }
            /* update port */
            SoAd_UtilpAddrSetPort(LocalAddrPtr,SoAd_SocketGetLocalPort(SocketIdx));
            RetVal = E_OK;
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETLOCALADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
} 
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetPhysAddr
( 
    SoAd_SoConIdType SoConId, 
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) PhysAddrPtr 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    SoAd_SocketIdxType SocketIdx;
    /* check for dev error */  
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if(PhysAddrPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            RetVal = SoAd_TcpIpIfGetPhysAddr(LocalAddrIdx,SocketIdx,PhysAddrPtr);
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETPHYSADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) IpAddrPtr
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for dev error */   
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if(IpAddrPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {   
        /* Check if remote address is set and contains at least wildcards. */
        if (SoAd_SoConCtrlGetRemoteAddrState(SoConId) <= SOAD_SOCON_IP_ANY_PORT_ANY)
        {
            /* update Remote Ip address and Port */
            SoAd_UtilpAddrSetIpv4Addr(IpAddrPtr,SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConId));
            SoAd_UtilpAddrSetPort(IpAddrPtr,SoAd_SoConCtrlGetRemoteAddrPort(SoConId));
            RetVal = E_OK;
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETREMOTEADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Enables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id. 
*               Routing of PDUs can be either forwarding of PDUs from the upper layer to a TCP or UDP socket of the 
*               TCP/IP stack specified by a PduRoute or the other way around specified by a SocketRoute
*   @param[in]  id routing group identifier specifying the routing group to be enabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableRouting( SoAd_RoutingGroupIdType id )
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfRoutingGroup() <= id)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        /* Update the status for PduRouteDest's routing group */
        for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
            RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
        {
            SoAd_RoutingGroupPduRouteDestCtrlSetEnabled(RgPduRouteDestIdx,TRUE);
        }
        /* Update the status for PduRouteDest's routing group */
        for(RgSocketRouteDestIdx = SoAd_RoutingGroupCfgGetRgSocketRouteDestStartIdx(id);
            RgSocketRouteDestIdx <= SoAd_RoutingGroupCfgGetRgSocketRouteDestEndIdx(id);RgSocketRouteDestIdx++)
        {
            SoAd_RoutingGroupSocketRouteDestCtrlSetEnabled(RgSocketRouteDestIdx,TRUE);
        }
        RetVal = E_OK;
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_ENABLEROUTING_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableSpecificRouting(SoAd_RoutingGroupIdType id,SoAd_SoConIdType SoConId)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((SoAd_CfgGetNumOfRoutingGroup() <= id) || (SoAd_CfgGetNumOfSoCon() <= SoConId))
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
       /* Update the status for PduRouteDest's routing group */
        for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
            RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
        {
            if (SoAd_RGPduRouteDestCfgGetSoConIdx(RgPduRouteDestIdx) == SoConId)
            {
                SoAd_RoutingGroupPduRouteDestCtrlSetEnabled(RgPduRouteDestIdx,TRUE);
                RetVal=E_OK;
            }
        }
        /* Update the status for PduRouteDest's routing group */
        for(RgSocketRouteDestIdx = SoAd_RoutingGroupCfgGetRgSocketRouteDestStartIdx(id);
            RgSocketRouteDestIdx <= SoAd_RoutingGroupCfgGetRgSocketRouteDestEndIdx(id);RgSocketRouteDestIdx++)
        {
            if (SoAd_RGSocketRouteDestCfgGetSoConIdx(RgSocketRouteDestIdx) == SoConId)
            {
                SoAd_RoutingGroupSocketRouteDestCtrlSetEnabled(RgSocketRouteDestIdx,TRUE);
                RetVal=E_OK;
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_ENABLESPECIFICROUTING_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Disables routing of a group of PDUs in the SoAd related to the RoutingGroup specified by parameter id.
*               Routing of PDUs can be either forwarding of PDUs from the upper layer to a TCP or UDP socket of the 
*               TCP/IP stack specified by a PduRoute or the other way around specified by a SocketRoute.
*   @param[in]  id routing group identifier specifying the routing group to be disabled
*   @return     Std_ReturnType E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableRouting( SoAd_RoutingGroupIdType id )
{
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfRoutingGroup() <= id)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        /* Update the status for PduRouteDest's routing group */
        for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
            RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
        {
            SoAd_RoutingGroupPduRouteDestCtrlSetEnabled(RgPduRouteDestIdx,FALSE);
        }
        /* Update the status for PduRouteDest's routing group */
        for(RgSocketRouteDestIdx = SoAd_RoutingGroupCfgGetRgSocketRouteDestStartIdx(id);
            RgSocketRouteDestIdx <= SoAd_RoutingGroupCfgGetRgSocketRouteDestEndIdx(id);RgSocketRouteDestIdx++)
        {
            SoAd_RoutingGroupSocketRouteDestCtrlSetEnabled(RgSocketRouteDestIdx,FALSE);
        }
        RetVal=E_OK;
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_DISABLEROUTING_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableSpecificRouting(SoAd_RoutingGroupIdType id,SoAd_SoConIdType SoConId)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((SOAD_NUM_OF_ROUTING_GROUP <= id) || (SoAd_CfgGetNumOfSoCon() <= SoConId))
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        /* Update the status for PduRouteDest's routing group */
        for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
            RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
        {
            if (SoAd_RGPduRouteDestCfgGetSoConIdx(RgPduRouteDestIdx) == SoConId)
            {
                SoAd_RoutingGroupPduRouteDestCtrlSetEnabled(RgPduRouteDestIdx,FALSE);
                RetVal=E_OK;
            }
        }
        /* Update the status for PduRouteDest's routing group */
        for(RgSocketRouteDestIdx = SoAd_RoutingGroupCfgGetRgSocketRouteDestStartIdx(id);
            RgSocketRouteDestIdx <= SoAd_RoutingGroupCfgGetRgSocketRouteDestEndIdx(id);RgSocketRouteDestIdx++)
        {
            if (SoAd_RGSocketRouteDestCfgGetSoConIdx(RgSocketRouteDestIdx) == SoConId)
            {
                SoAd_RoutingGroupSocketRouteDestCtrlSetEnabled(RgSocketRouteDestIdx,FALSE);
                RetVal=E_OK;
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_DISABLESPECIFICROUTING_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal; 
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetRemoteAddr
( 
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    boolean SoConModeChange = FALSE;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (NULL_PTR == RemoteAddrPtr)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
     else if (SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConId) == TRUE)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        /* if socket connection states allow to set remote address.i,e no Tx/Rx pendinf, then update Rem addr */
        if (SoAd_SoConCheckStateForSetRemoteAddr(SoConId) == E_OK)
        {
            /* set remote address if valid. */
            if (SoAd_SoConSetRemoteAddr(SoConId, RemoteAddrPtr) == E_OK) 
            {
                SoAd_EnterCriticalSection();
                /* if socket connection is online and shall be set to reconnect since remote address has wildcards. */
                if ((SoAd_SoConCtrlGetSoConMode(SoConId) == SOAD_SOCON_ONLINE) &&
                    ((SoAd_SoConCtrlGetRemoteAddrState(SoConId) & SOAD_SOCON_MASK_ANY) != 0u))
                {
                    SoAd_SoConCtrlSetSoConMode(SoConId,SOAD_SOCON_RECONNECT); 
                    SoConModeChange = TRUE;
                }
                SoAd_ExitCriticalSection();
                /* Notify about changed socket conenction mode */
                if ( SoConModeChange == TRUE )
                {
                    SoAd_SoConNotifySoConModeChg(SoConId, SOAD_SOCON_RECONNECT);
                }
                else if (SoAd_SoConCtrlGetRemoteAddrState(SoConId) == SOAD_SOCON_IP_SET_PORT_SET)
                {
                    /* if remote address is set , set flag to handle socket connection in main function. */
                    SoAd_SoConCtrlSetSoConEventStateChange(SoConId,TRUE);
                }
                else
                {
                    /* Do Nothing */
                }
                RetVal = E_OK;
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_SETREMOTEADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
} 
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetUniqueRemoteAddr
( 
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2VAR(SoAd_SoConIdType,AUTOMATIC,SOAD_APPL_VAR) AssignedSoConIdPtr
)
{
    SoAd_SoConIdType BestMatchSoConIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if ((NULL_PTR == RemoteAddrPtr) || (NULL_PTR == AssignedSoConIdPtr))
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            SoAd_EnterCriticalSection();
            /* Process if the requested RemoteAddr doesn't have wildcards */
            if ((SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr) != SOAD_IPADDR_ANY) && 
                (SoAd_UtilpAddrGetPort(RemoteAddrPtr) != SOAD_PORT_ANY))
            {
                /* Find the SoConId with the address match */
                if (TRUE == SoAd_SoConGetSoConIdxByBestMatchAlgo(SoConGrpIdx,RemoteAddrPtr,&BestMatchSoConIdx))
                {
                    /* If requested address already set then, reset the connection parameters */
                    if (SoAd_SoConCtrlGetRemoteAddrState(BestMatchSoConIdx) == SOAD_SOCON_IP_SET_PORT_SET)
                    {
                        if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
                        {
                            /* Remove alive supervision timeout  */
                            SoAd_SoConResetUdpAliveTimeout(BestMatchSoConIdx);
                        }
                        RetVal = E_OK;
                    }
                    else
                    {
                        if (SoAd_SoConSetRemoteAddr(BestMatchSoConIdx, RemoteAddrPtr) == E_OK)
                        {
                            /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
                            SoAd_SoConCtrlSetSoConEventStateChange(BestMatchSoConIdx,TRUE);
                            RetVal = E_OK;
                        }
                    }
                    
                    if (RetVal == E_OK)
                    {
                        /* Update the valid the SoConId */ 
                        *AssignedSoConIdPtr = BestMatchSoConIdx;
                    }
                }
                SoAd_ExitCriticalSection();
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_SETUNIQUEREMOTEADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      By this API service the remote address (IP address and port) of the specified socket connection 
*               shall be released, i.e. set back to the configured remote address setting.
*   @param[in]  SoConId Index of the socket connection for which the remote address shall be released.
*   @ServiceID  0x23
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SoConIds. Non reentrant for the same SoConId.
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_ReleaseRemoteAddr( SoAd_SoConIdType SoConId )
{
    SoAd_SockAddrType RemoteAddr;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_RemAddrIpV4IdxType RemAddrIpV4Idx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        /* Check if the current Remote address is same as configured value then relase is not required */
        if ((SoAd_SoConCtrlGetRemoteAddrState(SoConId) & SOAD_SOCON_MASK_NOT) == 0u)
        {
            RemAddrIpV4Idx = SoAd_SoConCfgGetRemAddrIpV4Idx(SoConId);
            if (RemAddrIpV4Idx < SoAd_CfgGetNumOfRemAddrIpV4())
            {
                /* get Remote addr from configuration */
                SoAd_UtilAddrSetIpv4Addr(RemoteAddr,SoAd_SocketCfgGetRemAddrIpv4(RemAddrIpV4Idx));
                SoAd_UtilAddrSetPort(RemoteAddr,SoAd_SocketCfgGetRemAddrIpv4Port(RemAddrIpV4Idx));
                /* check if remote address is already set */
                if ((SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConId) != SoAd_UtilAddrGetIpv4Addr(RemoteAddr)) &&
                   (SoAd_SoConCtrlGetRemoteAddrPort(SoConId) != SoAd_UtilAddrGetPort(RemoteAddr)) && 
                   (SoAd_SoConCtrlGetRemoteAddrState(SoConId) != SoAd_SoConCfgGetRemAddrState(SoConId)))
                {
                    /* If requested address already set then, reset the connection parameters */
                    if (SoAd_SoConCtrlGetRemoteAddrState(SoConId) == SOAD_SOCON_IP_SET_PORT_SET)
                    {
                        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
                        /* Remove alive supervision timeout from timeout list if configured and running. */
                        if(SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
                        {
                            SoAd_SoConResetUdpAliveTimeout(SoConId);
                        }
                    }
                    /* Set the Remote addr from configuration to the SoConId */
                    if (SoAd_SoConSetRemoteAddr(SoConId, &RemoteAddr) == E_OK)
                    {
                        /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
                        SoAd_SoConCtrlSetSoConEventStateChange(SoConId,TRUE);
                    }
                }
            }
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_RELEASEREMOTEADDR_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    SoAd_SoConIdType SoConIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SOAD_NUM_OF_TX_PDU <= id)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        /* TxPduId and PduRouteIdx are same, get the id of the PduRouteDestIdx */
        PduRouteDestIdx  = SoAd_PduRouteCfgGetPduRouteDestStartIdx(id);
        if (PduRouteDestIdx < SoAd_CfgGetNumOfPduRouteDest())
        {
            SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
            /* Get the Socket Id for this SoConIdx */
            if (SoConIdx < SoAd_CfgGetNumOfSoCon())
            {
                RetVal = SoAd_SocketTcpIpChangeParameter(SoAd_SoConCfgGetSocketIdx(SoConIdx),parameter,value);
            }
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_TPCHANGEPARAMETER_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReadDhcpHostNameOption
( 
    SoAd_SoConIdType SoConId,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) length,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) data
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if ((NULL_PTR == length) || (NULL_PTR == data))
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            if (LocalAddrIdx < SoAd_CfgGetNumOfLocalIpAddr()) 
            {
                RetVal = SoAd_TcpIpIfDhcpReadOption(LocalAddrIdx, length,data);
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_READDHCPHOSTNAMEOPTION_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_WriteDhcpHostNameOption
( 
    SoAd_SoConIdType SoConId,
    uint8 length,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) data
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfSoCon() <= SoConId)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (NULL_PTR == data)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConId);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            if (LocalAddrIdx < SoAd_CfgGetNumOfLocalIpAddr())
            {
                RetVal = SoAd_TcpIpIfDhcpWriteOption(LocalAddrIdx,length,data);
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_WRITEDHCPHOSTNAMEOPTION_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetAndResetMeasurementData
( 
    SoAd_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,SOAD_APPL_VAR) MeasurementDataPtr 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (NULL_PTR == MeasurementDataPtr)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        RetVal = SoAd_TcpIpIfGetAndResetMeasurementData(MeasurementIdx,MeasurementResetNeeded,MeasurementDataPtr);
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_GETANDRESETMEASUREMENTDATA_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      The TCP/IP stack calls this primitive after the reception of data on a socket. The socket identifier 
*               along with configuration information determines which module is to be called.
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @param[in]  RemoteAddrPtr Pointer to memory containing IP address and port of the remote host which sent the data
*   @param[in]  BufPtr Pointer to the received data.
*   @param[in]  Length Data length of the received TCP segment or UDP datagram.=
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxIndication
( 
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) BufPtr,
    uint16 Length 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SocketIdxType LocalSocketIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((RemoteAddrPtr == NULL_PTR) || (BufPtr == NULL_PTR))
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else if (SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx) == E_NOT_OK)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (Length == 0u)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        SoAd_RxIndicationProcessing(LocalSocketIdx,RemoteAddrPtr,BufPtr,Length);
    }
  
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_RXINDICATION_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service gets called if the stack put a socket into the listen mode before (as server) and a peer
*               connected to it (as client). In detail: The TCP/IP stack calls this function after a socket was set
*               into the listen state with TcpIp_TcpListen() and a TCP connection is requested by the peer.
*   @param[in]  SocketId Socket identifier of the related local socket resource which has been used at TcpIp_Bind()
*   @param[in]  SocketIdConnected Socket identifier of the local socket resource used for the established connection
*   @param[in]  RemoteAddrPtr IP address and port of the remote host.
*   @return     Std_ReturnType Result of operation E_OK upper layer accepts the established connection 
*               E_NOT_OK upper layer refuses the established connection, TcpIp stack shall close the connection.
*   @ServiceID  0x15
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted
( 
    TcpIp_SocketIdType SocketId,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr 
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConIdType SoConIdxAccepted;
    uint8 ErrorId = SOAD_E_NO_ERROR;  
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketIdxType LocalSocketIdx;
    /* check for dev error */    
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if((SOAD_SOCKET_ID_INVALID == SocketIdConnected) ||
            (E_NOT_OK == SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx)))
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else if (NULL_PTR == RemoteAddrPtr)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        #ifdef DLOG
        Dlog_Print(" SoAd_TcpAccepted SocketId %d SocketIdConnected %d\n",SocketId,SocketIdConnected);
        #endif
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(LocalSocketIdx);
        SoConIdx =SoAd_SocketCfgGetSoConStartIdx(LocalSocketIdx);
        if ((SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == FALSE) &&
            (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE))
        {
            if (SoAd_SocketCtrlGetSocketState(LocalSocketIdx) == SOAD_SOCK_STATE_LISTEN)
            {
                /* Check for suitable socket connection */
                if (SoAd_SoConTcpGetSoConIdxForAcceptance(SoConIdx, RemoteAddrPtr, &SoConIdxAccepted) == E_OK)
                {
                    /* if socket connection found , try to accepts connection. */
                    RetVal = SoAd_SoConTcpConnectAcceptedSoConIdx(SoConIdxAccepted, SocketIdConnected, RemoteAddrPtr);
                }
            }
        }
        else
        {
            ErrorId = SOAD_E_INV_SOCKETID;
        }
    }
    
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_TCPACCEPTED_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service gets called if the stack initiated a TCP connection before (as client) and the peer
*               (the server) acknowledged the connection set up. In detail: The TCP/IP stack calls this function 
*               after a socket was requested to connect with TcpIp_TcpConnect() and a TCP connection is confirmed 
*               by the peer. The parameter value of SocketId equals the SocketId value of the preceeding 
*               TcpIp_TcpConnect() call
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @ServiceID  0x16
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpConnected( TcpIp_SocketIdType SocketId )
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SocketIdxType LocalSocketIdx;
    /* check for dev error */    
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx) == E_NOT_OK)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        #ifdef DLOG
        Dlog_Print(" SoAd_TcpConnected SocketId %d \n",SocketId);
        #endif
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(LocalSocketIdx);
        SoConIdx =SoAd_SocketCfgGetSoConStartIdx(LocalSocketIdx);
        if ((SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == TRUE) &&
            (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE))
        {
            /* if socket state is in connect and if any open req or auto setup then update the state to established */
            if(SoAd_SocketCtrlGetSocketState(LocalSocketIdx) == SOAD_SOCK_STATE_CONNECT )
            {
                if((SoAd_SoConCtrlIsOpenCloseReqPending(SoConIdx))  ||
                   (SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConIdx) == TRUE))
                {
                    if (SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_ONLINE)
                    {
                        /* update the status */
                        SoAd_SocketCtrlSetSocketState(LocalSocketIdx,SOAD_SOCK_STATE_ESTABLISHED);
                        SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_ONLINE);
                        /* Notify user about state change. */
                        SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
                        /* Try to start TP reception is required. */
                        (void)SoAd_RxTpStartOfReception(SoConIdx);
                    }
                }
            }
        }
        else
        {
            ErrorId = SOAD_E_INV_SOCKETID;
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_TCPCONNECTED_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
} 
/********************************************************************************************************************
*   @brief      This service gets called if the stack encounters a condition described by the values in Event
*   @param[in]  SocketId Socket identifier of the related local socket resource
*   @param[in]  Event This parameter contains a description of the event just encountered
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpEvent( TcpIp_SocketIdType SocketId, TcpIp_EventType Event )
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SocketIdxType LocalSocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx) == E_NOT_OK)
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(LocalSocketIdx);
        if (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
        {
            /* Handle Tcp Events */
            if ((Event == SOAD_TCP_RESET) || (Event == SOAD_TCP_CLOSED))
            {
                SoAd_SocketTcpEventClose(LocalSocketIdx);
            }
            else if (Event == SOAD_TCP_FIN_RECEIVED)
            {
                SoAd_SocketTcpEventFinReceived(LocalSocketIdx);
            }
            else
            {
                /* Invalid eventes for Tcp */
                ErrorId = SOAD_E_INV_ARG;
            }
        }
        else
        {
            /* Handle Udp Events */
            if (Event == SOAD_UDP_CLOSED)
            {
                SoAd_SocketUdpEventClose(LocalSocketIdx);
            }
            else
            {
                /* Invalid eventes for Udp */
                ErrorId = SOAD_E_INV_ARG;
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_TCPIPEVENT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service gets called by the TCP/IP stack if an IP address assignment changes (i.e. new address 
*               assigned or assigned address becomes invalid).
*   @param[in]  IpAddrId IP address Identifier, representing an IP address specified in the TcpIp module configuraiton
*               (e.g. static IPv4 address on EthIf controller 0).
*   @param[in]  State state of IP address assignment
*   @ServiceID  0x18
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg(TcpIp_LocalAddrIdType IpAddrId,TcpIp_IpAddrStateType State)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((SoAd_CfgGetNumOfLocalIpAddr() <= IpAddrId) || 
             ((SOAD_IPADDR_STATE_ASSIGNED != State) && (SOAD_IPADDR_STATE_ONHOLD != State) && 
              (SOAD_IPADDR_STATE_UNASSIGNED != State)))
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else 
    {
        /* update the Ipaddr state */
        SoAd_CtrlSetIpAddrState(IpAddrId,State);
        for (SoConIdx = 0u; SoConIdx < SoAd_CfgGetNumOfSoCon(); SoConIdx++)
        {
            SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
            if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
            {
                /* Check if the SoConGrp IpAddr state is changed */
                if (IpAddrId == SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx))
                {
                    /* Notify user about IP address state change on socket connection. */
                    SoAd_SoConNotifyLocalIpAddrAssignmentChg(SoConIdx, State);
                    /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
                    SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
                }
                /* update the close mode to prevent that socket connection is opened automatically on IP reassign */
                if (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_SOCKET_RECONNECT)
                {
                    SoAd_SoConSetCloseReq(SoConIdx,SOAD_CLOSE_REQ_SOCKET);
                }
            }
        }
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_LOCALIPADDRASSIGNMENTCHG_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      Schedules the Socket Adaptor. (Entry point for scheduling)
*   @ServiceID  0x19
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_MainFunction( void )
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else
    {
        SoAd_TcpIpBsdMainFunctionRx();
        SoAd_RxMainFunction();
        SoAd_TcpIpBsdMainFunctionState();       
        SoAd_SoConMainFunction();
        SoAd_TxMainFunction();
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
        SoAd_DetReportError(SOAD_MAINFUNCTION_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief This Api is used to notify Socket connection mode changes to the users.
*   @param[in] SoConIdx the socket connection idx
*   @param[in] Mode the socket connection mode 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SoConNotifySoConModeChg(SoAd_SoConIdType SoConIdx,SoAd_SoConModeType Mode)
{ 
    SoAd_UpSoConModeChgFuncType pUpSoConModeChgFunc;
    SoAd_UpSoConModeChgFuncIdxType SoConModeChgCbkIndIdx;

    /* Call all socket connection related socket connection mode change notifications. */
    for ( SoConModeChgCbkIndIdx = SoAd_SoConCfgGetSoConModeChgCbkIndStartIdx(SoConIdx);
          SoConModeChgCbkIndIdx <= SoAd_SoConCfgGetSoConModeChgCbkIndEndIdx(SoConIdx);SoConModeChgCbkIndIdx++ )
    {
        pUpSoConModeChgFunc = SoAd_CfgGetUpSoConModeChgFunc(SoConModeChgCbkIndIdx);
        if ( pUpSoConModeChgFunc != NULL_PTR )
        {
            pUpSoConModeChgFunc(SoConIdx, Mode);
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to check the states and open socket connection for reception 
*   @param[in] SoConIdx the socket connection idx
*   @param[in] RemoteAddrPtr the receive remote addr
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConCheckStatesAndOpenSoConOnReception
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for valid states for reception */
    if (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx) == TRUE)
    {
        if (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE)
        {
            if(SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_ONLINE)
            {
                RetVal = E_OK;
            }
            else
            {
                /* if not online , try to open SoCon */
                RetVal = SoAd_SoConOpenOnReception(SoConIdx, RemoteAddrPtr);
            }
            
            if (RetVal == E_OK)
            {
                /* update alive timeout */
                SoAd_UpdateUdpAliveTimeout(SoConIdx);
                /* Update received remote address */
                SoAd_SoConCtrlSetRcvdRemoteAddrDomain(SoConIdx,SOAD_AF_INET);
                SoAd_SoConCtrlSetRcvdRemoteAddrPort(SoConIdx,SoAd_UtilpAddrGetPort(RemoteAddrPtr));
                SoAd_SoConCtrlSetRcvdRemoteAddrIpv4Addr(SoConIdx,SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr));
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to request reconnect for the socket connection
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SoConRequestReconnect(SoAd_SoConIdType SoConIdx)
{
    if ((SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConIdx) == TRUE) &&
        (SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) <= SOAD_SOCON_IP_ANY_PORT_ANY) &&
        ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) & SOAD_SOCON_MASK_ANY)!= 0u))
    {
        SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_RECONNECT);
        /* Set socket connection to reconnect in next main function. */
        SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to request close for the socket connection
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SoConSetCloseReq(SoAd_SoConIdType SoConIdx,SoAd_SoConCloseReqType CloseReq)
{
    SoAd_EnterCriticalSection();
    /*! update only if requested close req greater than current close req */
    if (CloseReq > SoAd_SoConCtrlGetCloseReqType(SoConIdx))
    {
        SoAd_SoConCtrlSetCloseReqType(SoConIdx,CloseReq);
    }
    /* Set the SoCon state event to hadle the reqeuest for this SoConId in the main function */
    SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
    SoAd_ExitCriticalSection();
}
/********************************************************************************************************************
*   @brief This Api is used to get the socket connection Idx by the best match algorithm
*   @param[in] SoConGrpIdx the socket connection group idx
*   @param[in] SockAddrPtr the received socket address 
*   @param[in,out] SoConIdxPtr the pointer to update the best match socket connection idx
*   @return status of the request TRUE: Socket connection id found FALSE: Socket connection id not found 
********************************************************************************************************************/
FUNC(boolean, SOAD_CODE) SoAd_SoConGetSoConIdxByBestMatchAlgo
(
    SoAd_SoConGrpIdxType SoConGrpIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_CONST) SockAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
)
{
    boolean MatchFound = FALSE;
    SoAd_SoConIdType SoConIdxOfGrp;
    SoAd_BestMatchPriorityType NewBestMatchPriority=SOAD_BEST_MATCH_NONE;
    SoAd_BestMatchPriorityType BestMatchPriority=SOAD_BEST_MATCH_NONE;
    /* check for best match SoConIdx */
    if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
    {
        /*! Find the SoConId with the address match */
        for(SoConIdxOfGrp = SoAd_SoConGrpCfgGetSoConStartIdx(SoConGrpIdx);
           (SoConIdxOfGrp <= SoAd_SoConGrpCfgGetSoConEndIdx(SoConGrpIdx));SoConIdxOfGrp++)
        {
            if (((SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE) && 
                 (SoAd_SoConCtrlGetSoConMode(SoConIdxOfGrp) == SOAD_SOCON_RECONNECT)) ||
                (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == FALSE))
            {
                if ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdxOfGrp) & SOAD_SOCON_MASK_NOT) == 0u)
                {
                    if ((SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConIdxOfGrp) == SoAd_UtilpAddrGetIpv4Addr(SockAddrPtr)) &&
                        (SoAd_SoConCtrlGetRemoteAddrPort(SoConIdxOfGrp) == SoAd_UtilpAddrGetPort(SockAddrPtr)))
                    {
                        /* Check for both Ip and port match */
                        NewBestMatchPriority = SOAD_BEST_MATCH_IP_MATCH_PORT_MATCH;
                    }
                    else if ((SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConIdxOfGrp) == SoAd_UtilpAddrGetIpv4Addr(SockAddrPtr)) &&
                            (SoAd_SoConCtrlGetRemoteAddrPort(SoConIdxOfGrp) == SOAD_PORT_ANY))
                    {
                        /* Check for Ip match and any port */
                        NewBestMatchPriority = SOAD_BEST_MATCH_IP_MATCH_PORT_ANY;
                    }
                    else if ((SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConIdxOfGrp) == SOAD_IPADDR_ANY) &&
                            (SoAd_SoConCtrlGetRemoteAddrPort(SoConIdxOfGrp) == SoAd_UtilpAddrGetPort(SockAddrPtr)))
                    {
                        /* Check for both port match and any Ip */
                        NewBestMatchPriority = SOAD_BEST_MATCH_IP_ANY_PORT_MATCH;
                    }
                    else if ((SoAd_SoConCtrlGetRemoteAddrIpv4Addr(SoConIdxOfGrp) == SOAD_IPADDR_ANY) &&
                            (SoAd_SoConCtrlGetRemoteAddrPort(SoConIdxOfGrp) == SOAD_PORT_ANY))
                    {
                        /* Check for any port match */
                        NewBestMatchPriority = SOAD_BEST_MATCH_IP_ANY_PORT_ANY;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                    /* If new priority found , update priority */
                    if (NewBestMatchPriority > BestMatchPriority)
                    {
                        BestMatchPriority = NewBestMatchPriority;
                        *SoConIdxPtr = SoConIdxOfGrp;
                        MatchFound = TRUE;
                        /* If both Ip and Port matches (high priority then exit ) */
                        if ( BestMatchPriority == SOAD_BEST_MATCH_IP_MATCH_PORT_MATCH )
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return MatchFound;
}
/********************************************************************************************************************
*   @brief     This service used to copy data from source buffer to destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] SrcPtr pointer to source buffer data
*   @param[in] Length byte size to be copied
********************************************************************************************************************/
FUNC(void,SOAD_CODE) SoAd_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) SrcPtr , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief The api is used to intialize the local address  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_LocalAddrInit(void)
{
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* Initialize the local address */
    for (LocalAddrIdx=0U;LocalAddrIdx<SoAd_CfgGetNumOfLocalIpAddr();LocalAddrIdx++)
    {
        SoAd_CtrlSetIpAddrState(LocalAddrIdx,SOAD_IPADDR_STATE_UNASSIGNED);
    }
}
/********************************************************************************************************************
* @brief The api is used to intialize the socket connection  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConInit(void)
{
    SoAd_SoConIdType SoConIdx;
    /* Initialize the socket connections */
    for (SoConIdx=0U;SoConIdx<SoAd_CfgGetNumOfSoCon();SoConIdx++)
    {
        SoAd_SoConCtrlSetAbort(SoConIdx,FALSE);
        SoAd_SoConCtrlSetOpenCloseReqCount(SoConIdx,0u);
        SoAd_SoConCtrlSetCloseReqType(SoConIdx,SOAD_CLOSE_REQ_NONE);
        SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_OFFLINE);
        SoAd_SoConResetRemoteAddr(SoConIdx);
        /* Initialize the Tx ctrl elements for this socket */
        SoAd_TxSoConInit(SoConIdx);
        SoAd_RxInitSoCon(SoConIdx);
        /* Initialize the SoCon state */
        SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,FALSE);
    }
}
/********************************************************************************************************************
* @brief The api is used to  initialize the routing groups.
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RoutingGroupInit(void)
{
    boolean EnabledAtInit = FALSE;
    SoAd_RoutingGroupIdxType RoutingGroupIdx;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    /* Initialize all routing groups */
    for (RoutingGroupIdx = 0u;RoutingGroupIdx < SoAd_CfgGetNumOfRoutingGroup();RoutingGroupIdx++)
    {
        /* Get the Routing Enable from config */
        if (SoAd_RoutingGroupCfgGetEnabledAtInit(RoutingGroupIdx)== TRUE)
        {
            EnabledAtInit = TRUE;
        }
        /* Update the status for PduRouteDest's routing group */
        for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(RoutingGroupIdx);
            RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(RoutingGroupIdx);RgPduRouteDestIdx++)
        {
            SoAd_RoutingGroupPduRouteDestCtrlSetEnabled(RgPduRouteDestIdx,EnabledAtInit);
            SoAd_RoutingGroupPduRouteDestCtrlSetTriggerRequest(RgPduRouteDestIdx,FALSE);
        }
        
        /* Update the status for PduRouteDest's routing group */
        for(RgSocketRouteDestIdx = SoAd_RoutingGroupCfgGetRgSocketRouteDestStartIdx(RoutingGroupIdx);
            RgSocketRouteDestIdx <= SoAd_RoutingGroupCfgGetRgSocketRouteDestEndIdx(RoutingGroupIdx);
            RgSocketRouteDestIdx++)
        {
            SoAd_RoutingGroupSocketRouteDestCtrlSetEnabled(RgSocketRouteDestIdx,EnabledAtInit);
            SoAd_RoutingGroupSocketRouteDestCtrlSetTriggerRequest(RgSocketRouteDestIdx,FALSE);
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to reset the remote address of the  the socket connection 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConResetRemoteAddr(SoAd_SoConIdType SoConIdx)
{
    SoAd_RemAddrIpV4IdxType RemAddrIpV4Idx;
    /* reset the remote address */
    if (SoConIdx < SoAd_CfgGetNumOfSoCon())
    {
        RemAddrIpV4Idx = SoAd_SoConCfgGetRemAddrIpV4Idx(SoConIdx);
        if (RemAddrIpV4Idx < SoAd_CfgGetNumOfRemAddrIpV4())
        {
            /* Reset Remote address from configuration */ 
            SoAd_SoConCtrlSetRemoteAddrDomain(SoConIdx,SOAD_AF_INET);
            SoAd_SoConCtrlSetRemoteAddrPort(SoConIdx,SoAd_SocketCfgGetRemAddrIpv4Port(RemAddrIpV4Idx));
            SoAd_SoConCtrlSetRemoteAddrIpv4Addr(SoConIdx,SoAd_SocketCfgGetRemAddrIpv4(RemAddrIpV4Idx));
            /* Reset remote address state */
            SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,SoAd_SoConCfgGetRemAddrState(SoConIdx));
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to handle the procesing of the socket connection in main function call
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConMainFunction(void)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* process SoCon state for all SoConId */
    for (SoConIdx = 0u;SoConIdx<SoAd_CfgGetNumOfSoCon();SoConIdx++)
    {
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
        if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            /* Handle udp alive timeout */
            if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
            {
                SoAd_UdpAliveTimeoutHandler(SoConIdx);
            }
            LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
            /* Check if SoCon Event open/close request state is set */
            if (SoAd_SoConCtrlGetSoConEventStateChange(SoConIdx) != FALSE)
            {
                SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,FALSE);
                /* if no socket connection close is requested then try to open socket connection */
                if (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE )
                {
                    /* if socket connection has automatic setup enabled or is in reconnect state or 
                    is requested to be opened. */
                    if ((SoAd_SoConCfgIsSoConGrpAutoConnectionSetupEnabled(SoConIdx) == TRUE) || 
                        (SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_RECONNECT) ||
                        (SoAd_SoConCtrlIsOpenCloseReqPending(SoConIdx) == TRUE))
                    {
                        /* if socket connection is not online yet and IP address is assigned then try to 
                            open the connection */
                        if ((SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_ONLINE) &&
                            (SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED))
                        {
                            SoAd_SoConOpen(SoConIdx);
                        }
                    }
                    else
                    {
                        /*Check if socket shall be opened to enable socket connection open on reception otherwise.
                        if no user request and no auto setup , then the socket can be connected when message
                        acceptance filter is enabled */
                        SoAd_SoConCheckAndOpenSocketForReception(SoConIdx);
                    }
                }
                else
                {
                    /* Close socket connection. */
                    SoAd_SoConClose(SoConIdx);
                }
            }
        }
    } 
}
/********************************************************************************************************************
* @brief The api is used to open the socket connection
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConOpen(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketIdxType SocketIdx;
    /* process Tcp SoCon Open */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        if (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == TRUE)
        {
            /* process socket connection open sequence for TCP client. */
            if((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) == SOAD_SOCON_IP_SET_PORT_SET) &&
               (SoAd_SocketTcpOpenClient(SocketIdx,SoAd_SoConCtrlGetpRemoteAddr(SoConIdx)) == E_OK))
            {
                SoAd_SoConTcpOpen(SoConIdx);
            }
            else
            {
                /* If no socket is assigned set event to handle socket connection state in main function again. */
                SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
            }
        }
        else
        {
            /* process socket connection open sequence for TCP server. listen socket */
            if (SoAd_SocketTcpOpenServer(SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx)) == E_OK)
            {
                SoAd_SoConTcpOpen(SoConIdx);
            }
            else
            {
                /* If no socket is assigned set event to handle socket connection state in main function again. */
                SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
            }
        }
    }
    else
    {
        /* process UDP SoCon Open */
        if (SoAd_SocketUdpOpen(SocketIdx) == E_OK )
        {
            SoAd_SoConUdpOpen(SoConIdx);
        }
        else
        {
            /* If no socket is assigned set event to handle socket connection state in main function again. */
            SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to open the udp socket connection 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConUdpOpen(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* process udp socket connection open */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);    
    /* if remote address is set or UDP listen only is configured then update the mode and notify to UL */
    if ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) == SOAD_SOCON_IP_SET_PORT_SET) || 
        (SoAd_SocketUdpCfgGetListenOnly(SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx)) != FALSE))
    {
        SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_ONLINE);
        /* if remote address is set, Trigger address resolution */
        if (SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) == SOAD_SOCON_IP_SET_PORT_SET )
        {
            /* Trigger address reolution if any Pdu route is configured */
            if (SoAd_SoConCfgIsPduRouteSupported(SoConIdx) == TRUE)
            {
                LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
                SoAd_TcpIpIfTriggerAddressResolution(LocalAddrIdx,SoAd_SoConCtrlGetRemoteAddr(SoConIdx)); 
            }
        }
        /* Notify user about socket connection state change. */
        SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));

        /* Start TP sessions by calling StartOfReception if required. */
        (void)SoAd_RxTpStartOfReception(SoConIdx);
    }
    else
    {
        /* Set to Reconnect and notify to the user */
        if (SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_RECONNECT )
        {
            SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_RECONNECT);
            SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to check for socket state and open socket for reception
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConCheckAndOpenSocketForReception(SoAd_SoConIdType SoConIdx)
{
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* check for socket state and process socket open for reception */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
    {
        LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
        /* Try Open socket for reception if IP is assigned, socket is not yet opened and protocol type is UDP. */
        if ((SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED) &&
            (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED) &&
            (SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx) != SOAD_NUM_OF_UDP_SOCKET))
        {
            if ((SoAd_SoConGrpCfgIsMsgAcceptFilterSupported(SoConGrpIdx) == TRUE) &&
                (SoAd_SocketUdpCfgGetListenOnly(SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx)) == FALSE))
            {
                /* check for configured remote address with wildcards. */
                if ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) <= SOAD_SOCON_IP_ANY_PORT_ANY) &&
                    ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) & SOAD_SOCON_MASK_ANY) != 0u))
                {
                    if(SoAd_SocketUdpOpen(SocketIdx) == E_NOT_OK)
                    {
                        /* If no socket is assigned set event to handle socket connection state in main 
                        function again. */
                        SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
                    }
                }
            }
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to open tcp socket connection
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConTcpOpen(SoAd_SoConIdType SoConIdx)
{
    /* Set socket connection to reconnect and notify to user  */
    if (SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_RECONNECT)
    {
        SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_RECONNECT); 
        SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
    }
}
/********************************************************************************************************************
* @brief The api is used to process the close request for the socket connection
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConClose(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConModeType  NewSoConState;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* process SoCon close */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    boolean Abort = SoAd_SoConCtrlGetAbort(SoConIdx);
    /* Get expected socket connection state after closing. */
    switch (SoAd_SoConCtrlGetCloseReqType(SoConIdx))
    {
        case SOAD_CLOSE_REQ_OFFLINE_RESET:
        case SOAD_CLOSE_REQ_OFFLINE:
        case SOAD_CLOSE_REQ_SOCKET:
        {
            NewSoConState = SOAD_SOCON_OFFLINE;
            break;
        }
        default: /* SOAD_CLOSE_REQ_RECONNECT || SOAD_CLOSE_REQ_SOCKET_RECONNECT */
        {
            NewSoConState = SOAD_SOCON_RECONNECT;
            break;
        }
    }
    /* Check if expected socket connection state after closing is different to the current state. */
    if (SoAd_SoConCtrlGetSoConMode(SoConIdx) != NewSoConState )
    {
        /* Set new socket connection state. */
        SoAd_SoConCtrlSetSoConMode(SoConIdx,NewSoConState);
        /* Close socket connection. */
        SoAd_SoConCloseHandler(SoConIdx);
        /* Notify user about socket connection state change. */
        SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
    }
    /* Close related sockets. */
    if (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        /* Close Tcp Socket */
        SoAd_SocketTcpClose(SoAd_SoConCfgGetSocketIdx(SoConIdx), Abort);
        /* Close Tcp listen socket. */
        SoAd_SocketTcpCloseListen(SoAd_SoConCfgGetSocketIdx(SoConIdx), Abort);
    }
    else
    {
        /* Close Udp Socket */
        SoAd_SocketUdpClose(SoAd_SoConCfgGetSocketIdx(SoConIdx), Abort);
    }
    /* Reset socket connection close mode. */
    SoAd_SoConResetCloseMode(SoConIdx);
    /* Set event to handle socket connection state in main function. */
    SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
}
/********************************************************************************************************************
* @brief The api is used to handle the socket conncetion close.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConCloseHandler(SoAd_SoConIdType SoConIdx)
{
    boolean NormalClose =TRUE;
    /* process SoCon close */
    switch (SoAd_SoConCtrlGetCloseReqType(SoConIdx))
    {
        case SOAD_CLOSE_REQ_OFFLINE:
            /* socket connection shall be closed by normal close request .
               Reset structs, remote address and  terminate active TP sessions. */
            SoAd_SoConResetRemoteAddr(SoConIdx);
            break;
        case SOAD_CLOSE_REQ_OFFLINE_RESET:
            /* socket connection shall be closed by special request (shutdown, API call failed, config issue) 
               Reset structs, remote address, open/close sequence and terminate active TP sessions negatively. */
            SoAd_SoConResetRemoteAddr(SoConIdx);
            SoAd_SoConCtrlSetOpenCloseReqCount(SoConIdx,0u);
            NormalClose = FALSE;
            break;
        case SOAD_CLOSE_REQ_SOCKET_RECONNECT:
            /* socket connection shall be closed by socket close and TcpInitiate is true (if TCP is enabled).
                Reset structs and terminate active TP sessions negatively. */
            NormalClose = FALSE;
            break;
        default: /* SOAD_CLOSE_REQ_SOCKET || SOAD_CLOSE_REQ_RECONNECT */
            /* socket connection shall be closed if if socket is closed or requested to be reconnected 
               otherwise. Reset structs, remote address and terminate active TP sessions negatively. */
            SoAd_SoConResetRemoteAddr(SoConIdx);
            NormalClose = FALSE;
            break;
    }
    SoAd_SoConCtrlSetAbort(SoConIdx,FALSE);
    /* Terminate active transmissions. */
    if (SoAd_SoConCfgIsPduRouteSupported(SoConIdx)  == TRUE)
    {
        SoAd_TxTerminateTransmit(SoConIdx);
    }
    /* Terminate active receptions. */
    if (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx) == TRUE)
    {
        SoAd_RxTerminateReceive(SoConIdx,NormalClose);
    }
    /* Reset alive timer */
    SoAd_SoConResetUdpAliveTimeout(SoConIdx);
}
/********************************************************************************************************************
* @brief The api is used to reset the socket connection close mode and its properties
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConResetCloseMode(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConModeType NewSoConMode;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* process SoCon Reset close mode */
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SoAd_EnterCriticalSection();
    switch (SoAd_SoConCtrlGetCloseReqType(SoConIdx))
    {
        case SOAD_CLOSE_REQ_OFFLINE_RESET:
        case SOAD_CLOSE_REQ_OFFLINE:
        case SOAD_CLOSE_REQ_SOCKET:
        {
            NewSoConMode = SOAD_SOCON_OFFLINE;
            break;
        }
        default: /* SOAD_CLOSE_REQ_RECONNECT || SOAD_CLOSE_REQ_SOCKET_RECONNECT */
        {
            NewSoConMode = SOAD_SOCON_RECONNECT;
            break;
        }
    }
    /* Reset close mode if socket connection is in expected mode and socket is closed in case of TCP. */
    if ((SoAd_SoConCtrlGetSoConMode(SoConIdx) == NewSoConMode) && 
        ((SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE) ||
        (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED)))
    {
        SoAd_SoConCtrlSetCloseReqType(SoConIdx,SOAD_CLOSE_REQ_NONE);
    }
    SoAd_ExitCriticalSection();
}
/********************************************************************************************************************
* @brief The api is used to process whether the connection can be accepted for the socket connection
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConTcpGetSoConIdxForAcceptance
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr,
  P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) pSoConIdx
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConIdType  BestMatchSoConIdx;
    /* check for tcp acceptance */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsMsgAcceptFilterSupported(SoConGrpIdx) == TRUE)
    {
        SoAd_EnterCriticalSection();
        if (TRUE == SoAd_SoConGetSoConIdxByBestMatchAlgo(SoConGrpIdx,RemoteAddrPtr,&BestMatchSoConIdx))
        {
            *pSoConIdx = BestMatchSoConIdx;
            RetVal = E_OK;
        }
        SoAd_ExitCriticalSection();
    }
    else
    {
        if (SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_RECONNECT)
        {
            *pSoConIdx = SoConIdx;
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The api is used to process the TCP connect request for the accepted socket connection.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConTcpConnectAcceptedSoConIdx
(
    SoAd_SoConIdType SoConIdx,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
)
{   
    SoAd_SocketIdxType SocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* process tcp acceptance */
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED)
    {   
        RetVal = E_OK;
        /* Update Remote address and state */
        SoAd_SoConCtrlSetRemoteAddrIpv4Addr(SoConIdx,SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr));
        SoAd_SoConCtrlSetRemoteAddrPort(SoConIdx,SoAd_UtilpAddrGetPort(RemoteAddrPtr));
        SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,SOAD_SOCON_IP_SET_PORT_SET);
        /* update socket and SoCon state */
        SoAd_SocketTcpSetAcceptedSocketId(SocketIdx,SocketIdConnected);
        SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_ONLINE);
        /* Notify user about mode change */
        SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
        /* if socket connection has a SocketRoute. */
        if (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx)  == TRUE)
        {
            /* Try to start TP reception is required. */
            if ( SoAd_RxTpStartOfReception(SoConIdx) == E_NOT_OK )
            {
                RetVal = E_NOT_OK;
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The api is used to for checking the precondition for accepting the remote address
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConCheckStateForSetRemoteAddr(SoAd_SoConIdType SoConIdx)
{
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    /* check state for remote addr update */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
    {
        if ((SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_OFFLINE) && 
            (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE))
        {
            /*! Return E_NOT_OK it TCP and mode is not offline */
            RetVal = E_NOT_OK;
        }
    }
    /* if TP transmission is active, return E_NOT_OK */
    if (SoAd_SoConCfgIsPduRouteSupported(SoConIdx) == TRUE)
    {
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
        if (SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx) != SOAD_NUM_OF_PDU_ROUTE_DEST)
        {
            RetVal = E_NOT_OK;
        }
    }
    /* if TP reception is active, return E_NOT_OK */
    if (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx) == TRUE) 
    {
        RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
        if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) != SOAD_NUM_OF_SOCKET_ROUTE)
        {
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The api is used to update the remote address for this socket connection 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConSetRemoteAddr
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Compare remote address to local IP addresses to prevent setting local IP address as remote. */
    if (SoAd_SoConIsSoConIpAddrSameAsRemAddr(SoConIdx, RemoteAddrPtr) == E_NOT_OK)
    {
        SoAd_EnterCriticalSection();
        /*! update Remote Ip address and Port */
        SoAd_SoConCtrlSetRemoteAddrIpv4Addr(SoConIdx,SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr));
        SoAd_SoConCtrlSetRemoteAddrPort(SoConIdx,SoAd_UtilpAddrGetPort(RemoteAddrPtr));
        /* Update Ip address state */
        if (SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr) == SOAD_IPADDR_ANY)
        {
            SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,(SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        else
        {
            SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,(SOAD_SOCON_IP_SET_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        /* Update port address state */
        if (SoAd_UtilpAddrGetPort(RemoteAddrPtr) == SOAD_PORT_ANY)
        {
            SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,(SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_PORT));
        }
        else
        {
            SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,(SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_PORT));
        }
        SoAd_ExitCriticalSection();
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The api is used to check if the remote addr is same as the local ip address
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConIsSoConIpAddrSameAsRemAddr
(
    SoAd_SoConIdType SoConIdx, 
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
)
{
    uint8 Netmask;
    SoAd_SoConGrpIdxType  SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    TcpIp_SockAddrType LocalIpAddr;
    TcpIp_SockAddrType DefaultRouter;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check if remote addr is same as local ip addr */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
    {
        LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
         /* Get local IP address from TcpIp. */
        if (E_OK == SoAd_TcpIpIfGetIpAddr(LocalAddrIdx,&LocalIpAddr,&Netmask,&DefaultRouter))
        {
            if (SoAd_UtilAddrGetIpv4Addr(LocalIpAddr) == SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr))
            {
                RetVal = E_OK;
            }
        }
    }
    return RetVal;
} 
/********************************************************************************************************************
* @brief The api is used to notify the Ip addr assignment state to the Socket connection id users
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SoConNotifyLocalIpAddrAssignmentChg
(
    SoAd_SoConIdType SoConIdx,
    SoAd_IpAddrStateType State
)
{
    SoAd_LocalIpAddrAssignChgFuncType pLocalIpAddrAssignChgFunc;
    SoAd_LocalIpAddrAssignChgFuncIdxType LocalIpAddrAssignmentChgFuncIdx;
    /* Notify to all configured LocalIpAddrAssignmentChgInd for this SoCon Id */
    for(LocalIpAddrAssignmentChgFuncIdx = SoAd_SoConCfgGetLocalIpAddrAssignmentChgIndStartIdx(SoConIdx);
        LocalIpAddrAssignmentChgFuncIdx <= SoAd_SoConCfgGetLocalIpAddrAssignmentChgIndEndIdx(SoConIdx);
        LocalIpAddrAssignmentChgFuncIdx++)
    {
        pLocalIpAddrAssignChgFunc = SoAd_CfgGetLocalIpAddrAssignChgFunc(LocalIpAddrAssignmentChgFuncIdx);
        if (NULL_PTR != pLocalIpAddrAssignChgFunc)
        {
            pLocalIpAddrAssignChgFunc(SoConIdx,State);
        }
    }
}
/********************************************************************************************************************
* @brief The api is used to open socket connection for reception from the remote address
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConOpenOnReception
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* open socket connection for reception */
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if ((SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE) &&
         (SoAd_SoConGrpCfgIsMsgAcceptFilterSupported(SoConGrpIdx) == TRUE))
    {
        if (SoAd_SocketUdpCfgGetListenOnly(SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx)) == FALSE)
        {
            if (((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) & SOAD_SOCON_MASK_ANY) > 0U) &&
                ((SoAd_SoConCtrlGetRemoteAddrState(SoConIdx) & SOAD_SOCON_MASK_NOT) == 0U))
            {
                SoAd_EnterCriticalSection();
                /* Set Remote address and its state*/ 
                SoAd_SoConCtrlSetRemoteAddrDomain(SoConIdx,SOAD_AF_INET);
                SoAd_SoConCtrlSetRemoteAddrPort(SoConIdx,SoAd_UtilpAddrGetPort(RemoteAddrPtr));
                SoAd_SoConCtrlSetRemoteAddrIpv4Addr(SoConIdx,SoAd_UtilpAddrGetIpv4Addr(RemoteAddrPtr));
                SoAd_SoConCtrlSetRemoteAddrState(SoConIdx,SOAD_SOCON_IP_SET_PORT_SET);
                SoAd_ExitCriticalSection();
                /* Update SoCon status */
                SoAd_SoConCtrlSetSoConMode(SoConIdx,SOAD_SOCON_ONLINE);
                /* Notify user about state change. */
                SoAd_SoConNotifySoConModeChg(SoConIdx,SoAd_SoConCtrlGetSoConMode(SoConIdx));
                /* Start alive supervision timeout. */
                SoAd_StartUdpAliveTimeout(SoConIdx);
                /* Start TP reception if required and succeeds. */
                RetVal = SoAd_RxTpStartOfReception(SoConIdx);
            }
        }
    }
    return RetVal;
}

#define SOAD_STOP_SEC_CODE
#include "MemMap.h" 
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    26-Oct-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

