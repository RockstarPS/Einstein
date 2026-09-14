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
*   @file SoAd_Socket.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd_Socket is to implement the socket functionality api and data type. 
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Lcfg.h"
#include "SchM_SoAd.h"
#include "SoAd_Socket.h"
#include "SoAd_TcpIpIf.h"
#include "SoAd_Internal.h"
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define SoAd_SocketGetNumOfOpenSocket()         (SoAd_NumOfOpenSockets)
#define SoAd_SocketIncNumOfOpenSocket()         (SoAd_NumOfOpenSockets++)
#define SoAd_SocketDecNumOfOpenSocket()         (SoAd_NumOfOpenSockets--)
#define SoAd_SocketIsAnySocketOpened()          (SoAd_NumOfOpenSockets > 0u)
#define SoAd_SocketSetNumOfOpenSocket(val)      (SoAd_NumOfOpenSockets=(val))
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @breif Defines the number of open TcpIp sockets. */
SOAD_LOCAL VAR(uint16, SOAD_VAR_NOINIT) SoAd_NumOfOpenSockets=0U;
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
* @brief The Api is used to change the parameter value of the Udp socket 
* @param[in] SocketIdx socket idx
* @param[in] TcpIpSocketId tcpip socket idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SocketUdpChangeParameter
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId
);
/*!******************************************************************************************************************
* @brief The Api is used to reset the local port of the socket
* @param[in] SocketIdx the socket idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SocketResetLocalPort(SoAd_SocketIdxType SocketIdx);
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
* @brief The Api is used to initialize the socket properties
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketInit(void)
{
    SoAd_SocketIdxType SocketIdx; 
    /* Initialize the Socket status */
    for(SocketIdx=0U;SocketIdx<SoAd_CfgGetNumOfSocket();SocketIdx++)
    {
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SOAD_SOCON_ID_INVALID);
        SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_CLOSED);
        SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,SOAD_SOCKET_ID_INVALID);
        SoAd_SocketCtrlSetSkipBytes(SocketIdx,0u);
        
    }
    /* Reset Local Port - Should be done after the state is initialized */
    for(SocketIdx=0U;SocketIdx<SoAd_CfgGetNumOfSocket();SocketIdx++)
    {
        /* Reset local Port */
        SoAd_SocketResetLocalPort(SocketIdx);
    }
    /* Initialize the Number of open TcpIp Sockets */
    SoAd_SocketSetNumOfOpenSocket(0U);
}
/********************************************************************************************************************
* @brief The Api is used to set the local port of the socket
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketSetLocalPort(SoAd_SocketIdxType SocketIdx,SoAd_PortType Port)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    if(SocketIdx < SoAd_CfgGetNumOfSocket()) 
    {
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
        if(SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            /* If Tcp connection and TcpInitiate is False , set the port to SoConGrp socket */ 
            if((SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE) && 
               (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == FALSE) && 
               (SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx) < SoAd_CfgGetNumOfSocket()))
            {
                SoAd_SocketCtrlSetLocalPort(SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx),Port);
            }
            else
            {
                SoAd_SocketCtrlSetLocalPort(SocketIdx,Port);
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to get the local port of the socket
********************************************************************************************************************/
FUNC(SoAd_PortType, SOAD_CODE) SoAd_SocketGetLocalPort(SoAd_SocketIdxType SocketIdx)
{    
    SoAd_PortType Port = SOAD_PORT_ANY;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    
    if(SocketIdx < SoAd_CfgGetNumOfSocket()) 
    {
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
        if(SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
        {
            /* If Tcp connection and TcpInitiate is False , set the port to SoConGrp socket */ 
            if((SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE) && 
               (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == FALSE) && 
               (SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx) < SoAd_CfgGetNumOfSocket()))
            {
                Port = SoAd_SocketCtrlGetLocalPort(SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx));
            }
            else
            {
                Port = SoAd_SocketCtrlGetLocalPort(SocketIdx);
            }
        }
    }
    return Port;
}
/********************************************************************************************************************
* @brief The Api is used to open the Udp socket
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketUdpOpen(SoAd_SocketIdxType SocketIdx)
{
    SoAd_PortType LocalPort;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    TcpIp_SocketIdType TcpIpSocketId = SOAD_SOCKET_ID_INVALID;

    if ((SocketIdx < SOAD_NUM_OF_SOCKET) &&
        (SoAd_SocketCfgGetSoConGrpIdx(SocketIdx) < SoAd_CfgGetNumOfSoConGrp()))
    {
        LocalPort = SoAd_SocketGetLocalPort(SocketIdx);
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
        
        /* if no socket is assigned, the get and assign socket from TcpIp for this SoConIdx */
        if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED )
        {
            if (SoAd_TcpIpIfGetSocket(SocketIdx,SOAD_AF_INET, SOAD_IPPROTO_UDP, 
                        SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&TcpIpSocketId) == E_OK)
            {
                SoAd_SocketUdpChangeParameter(SocketIdx,TcpIpSocketId);
                SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,TcpIpSocketId);
                /* Bind socket. */
                if (SoAd_TcpIpIfBind(SocketIdx,TcpIpSocketId,
                    SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&LocalPort) == E_OK)
                {
                    /* Update local port. */
                    SoAd_SocketSetLocalPort(SocketIdx,LocalPort);
                    SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_ESTABLISHED);
                    SoAd_SocketIncNumOfOpenSocket();
                    RetVal = E_OK;
                }
            
                if ( RetVal == E_NOT_OK )
                {
                    /* Close socket if any error occurred. */
                    (void)SoAd_TcpIpIfClose(SocketIdx, TcpIpSocketId,FALSE);
                }
            }
        }
        else
        {
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to open the Tcp server socket
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpOpenServer(SoAd_SocketIdxType ListenSockIdx)
{
    uint16 MaxChannel;
    SoAd_PortType LocalPort;
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    TcpIp_SocketIdType TcpIpSocketId = SOAD_SOCKET_ID_INVALID;
    
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(ListenSockIdx);
    if (SoConGrpIdx< SoAd_CfgGetNumOfSoConGrp())
    {
        LocalPort = SoAd_SocketGetLocalPort(ListenSockIdx);
        /* Open listen socket is not already assigned */
        if (SoAd_SocketCtrlGetSocketState(ListenSockIdx) == SOAD_SOCK_STATE_CLOSED)
        {
            /*  Get TcpIp socket. */
            if (SoAd_TcpIpIfGetSocket(ListenSockIdx,SOAD_AF_INET, SOAD_IPPROTO_TCP,
                            SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&TcpIpSocketId) == E_OK)
            {
                /* Change TcpIp parameter on socket. */
                SoAd_SocketTcpChangeParameter(ListenSockIdx,TcpIpSocketId);
                /* Bind TcpIp socket . */
                if (SoAd_TcpIpIfBind(ListenSockIdx,TcpIpSocketId,
                            SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&LocalPort) == E_OK)
                {
                    /* Update local port. */
                    SoAd_SocketSetLocalPort(ListenSockIdx,LocalPort);
                    /* Start listen on the socket */
                    MaxChannel = SoAd_SoConGrpCfgGetSoConEndIdx(SoConGrpIdx)-
                                    SoAd_SoConGrpCfgGetSoConStartIdx(SoConGrpIdx)+1U;
                    if (SoAd_TcpIpIfTcpListen(ListenSockIdx,TcpIpSocketId,MaxChannel) == E_OK)
                    {
                        SoAd_SocketCtrlSetTcpIpSocketId(ListenSockIdx,TcpIpSocketId);
                        SoAd_SocketCtrlSetSocketState(ListenSockIdx,SOAD_SOCK_STATE_LISTEN);
                        SoAd_SocketIncNumOfOpenSocket();
                        RetVal = E_OK;
                    }
                }

                if ( RetVal == E_NOT_OK )
                {
                     /* Close socket if any error occurred. */
                    (void)SoAd_TcpIpIfClose(ListenSockIdx,TcpIpSocketId, FALSE);
                }
            }
        }
        else
        {
            RetVal = E_OK; /* TcpIp Socket already assigned */
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to open the Tcp client socket
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpOpenClient
(
    SoAd_SocketIdxType SocketIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) pRemoteAddr
)
{
    SoAd_PortType LocalPort;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    TcpIp_SocketIdType TcpIpSocketId = SOAD_SOCKET_ID_INVALID;
    
    if ((SocketIdx < SOAD_NUM_OF_SOCKET) &&
        (SoAd_SocketCfgGetSoConGrpIdx(SocketIdx) < SoAd_CfgGetNumOfSoConGrp()))
    {
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
        LocalPort = SoAd_SocketGetLocalPort(SocketIdx);
        /* if no socket is assigned and remote address is set, Try to get and connect socket. */
        if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED)
        {
            if (SoAd_TcpIpIfGetSocket(SocketIdx,SOAD_AF_INET, SOAD_IPPROTO_TCP, 
                            SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&TcpIpSocketId) == E_OK)
            {
                /* Change TcpIp parameter on socket. */
                SoAd_SocketTcpChangeParameter(SocketIdx,TcpIpSocketId);
                /* Bind TcpIp socket . */
                if (SoAd_TcpIpIfBind(SocketIdx,TcpIpSocketId,
                            SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx),&LocalPort) == E_OK )  
                {
                    /* Update local port. */
                    SoAd_SocketSetLocalPort(SocketIdx,LocalPort);
                    SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,TcpIpSocketId);
                    /* Connect TcpIp Socket */  
                    if (SoAd_TcpIpIfTcpConnect(SocketIdx,TcpIpSocketId, pRemoteAddr) == E_OK)
                    {
                        SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_CONNECT);
                        SoAd_SocketIncNumOfOpenSocket();
                        RetVal = E_OK;
                    }
                }

                if ( RetVal == E_NOT_OK )
                {
                     /* Close socket if any error occurred. */
                    (void)SoAd_TcpIpIfClose(SocketIdx,TcpIpSocketId,FALSE);
                }
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle the Udp close event
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketUdpEventClose(SoAd_SocketIdxType SocketIdx)
{
    SoAd_SoConIdType SoConIdx;
    
    SoAd_EnterCriticalSection();
    /* Decrement number of open sockets. */
    if (SoAd_SocketGetNumOfOpenSocket() > 0U)
    {
        SoAd_SocketDecNumOfOpenSocket();
    }
    /* Update socket status */
    SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_CLOSED);
    SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,SOAD_SOCKET_ID_INVALID);
    SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
    /* Reset local port to the configured value. */
    SoAd_SocketResetLocalPort(SocketIdx);
    /* Close all related socket connections. */
    for(SoConIdx = SoAd_SocketCfgGetSoConStartIdx(SocketIdx);
        SoConIdx <= SoAd_SocketCfgGetSoConEndIdx(SocketIdx);SoConIdx++)
    {
        SoAd_SoConSetCloseReq(SoConIdx,SOAD_CLOSE_REQ_SOCKET);
    }
    SoAd_ExitCriticalSection();
} 
/********************************************************************************************************************
* @brief The Api is used to handle the tcp close event
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpEventClose(SoAd_SocketIdxType SocketIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;

    SoAd_EnterCriticalSection();
    /* Update socket status */
    /* Decrement number of open sockets. */
    if (SoAd_SocketGetNumOfOpenSocket() > 0U)
    {
        SoAd_SocketDecNumOfOpenSocket();
    }
    /* Update socket status */
    SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_CLOSED);
    SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,SOAD_SOCKET_ID_INVALID);
    SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
    SoAd_SocketCtrlSetSkipBytes(SocketIdx,0u);
    /* Reset port */
    SoAd_SocketResetLocalPort(SocketIdx);
    /* Update socket state for no listen socket */
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    if (SocketIdx != SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx))
    {
        if (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == TRUE)
        {
            SoAd_SoConSetCloseReq(SoAd_SocketCfgGetSoConStartIdx(SocketIdx),SOAD_CLOSE_REQ_SOCKET_RECONNECT);
        }
        else
        {
            SoAd_SoConSetCloseReq(SoAd_SocketCfgGetSoConStartIdx(SocketIdx),SOAD_CLOSE_REQ_SOCKET);
        }
    }
    SoAd_ExitCriticalSection();
}
/********************************************************************************************************************
* @brief The Api is used to handle the tcp FIN event
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpEventFinReceived(SoAd_SocketIdxType SocketIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;

    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    if (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == TRUE)
    {
        /* Set close mode to indicate that socket is closing and shall be reconnected in case of client socket. */
        SoAd_SoConSetCloseReq(SoAd_SocketCfgGetSoConStartIdx(SocketIdx),SOAD_CLOSE_REQ_SOCKET_RECONNECT);
    }
    else
    {
        /*  Set close mode to indicate that socket is closing otherwise. */
        SoAd_SoConSetCloseReq(SoAd_SocketCfgGetSoConStartIdx(SocketIdx),SOAD_CLOSE_REQ_SOCKET);
    }
    /* Close TcpIp socket. */
    (void)SoAd_TcpIpIfClose(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),FALSE);
}
/********************************************************************************************************************
* @brief The Api is used to get the socket idx from the tcpip socket idx
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketGetSocketIdxByTcpIpSocketId
(
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(SoAd_SocketIdxType, AUTOMATIC, SOAD_APPL_DATA) pSocketIdx
)
{
    SoAd_SocketIdxType SocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;

    for(SocketIdx = 0u;SocketIdx<SoAd_CfgGetNumOfSocket();SocketIdx++)
    {
        /* Return socket index if requested TcpIpSocketId found and stop iteration. */
        if (SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx) == TcpIpSocketId)
        {
            *pSocketIdx = SocketIdx;
            RetVal = E_OK;
            break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle the tcp close request
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpClose(SoAd_SocketIdxType SocketIdx,boolean Abort)
{
    if((SoAd_SocketCtrlGetSocketState(SocketIdx) != SOAD_SOCK_STATE_CLOSED) && 
      (SoAd_SocketCtrlGetSocketState(SocketIdx) != SOAD_SOCK_STATE_CLOSING))
    {
        /* Close the Socket */
        SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_CLOSING);
        (void)SoAd_TcpIpIfClose(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),Abort);
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the tcp close request for listen socket
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpCloseListen(SoAd_SocketIdxType SocketIdx, boolean Abort)
{
    SoAd_SoConIdType SoConIdOfGrp;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketIdxType ListenSocketIdx;
    boolean ListenSocketRequired = FALSE;
    
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    /* if socket is a server socket, close the listen socket only if the other socon's socket in grp are closed. */
    if (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == FALSE)
    {
        ListenSocketIdx = SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx);
        /* check if listen socket is not already closed */
        if ((SoAd_SocketCtrlGetSocketState(ListenSocketIdx) != SOAD_SOCK_STATE_CLOSED) &&
            (SoAd_SocketCtrlGetSocketState(ListenSocketIdx) != SOAD_SOCK_STATE_CLOSING))
        {
            for(SoConIdOfGrp = SoAd_SoConGrpCfgGetSoConStartIdx(SoConGrpIdx);
                SoConIdOfGrp <= SoAd_SoConGrpCfgGetSoConEndIdx(SoConGrpIdx);SoConIdOfGrp++)
            {
                /* If any SoConIdOfGrp is not online, then ListenSockIdx is required */
                if (SoAd_SoConCtrlGetSoConMode(SoConIdOfGrp) != SOAD_SOCON_OFFLINE )
                {
                    ListenSocketRequired = TRUE;
                    break;
                }
            }
            /* close TcpIp socket */
            if (ListenSocketRequired == FALSE)
            {
                SoAd_SocketCtrlSetSocketState(ListenSocketIdx,SOAD_SOCK_STATE_CLOSING);
                (void)SoAd_TcpIpIfClose(ListenSocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(ListenSocketIdx),Abort);
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the tcp close request
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketUdpClose(SoAd_SocketIdxType SocketIdx, boolean Abort)
{
    boolean IsSocketRequired = FALSE;
    SoAd_SoConIdType SoConIdxOfSocket;
    /* if socket state not closed, then check the mode of all SoCon for this socket and if all are offline then
       close the TcpIp socket */
    if(SoAd_SocketCtrlGetSocketState(SocketIdx) != SOAD_SOCK_STATE_CLOSED )
    {
        for(SoConIdxOfSocket=SoAd_SocketCfgGetSoConStartIdx(SocketIdx);
            SoConIdxOfSocket<=SoAd_SocketCfgGetSoConEndIdx(SocketIdx);SoConIdxOfSocket++)
        {
            if (SoAd_SoConCtrlGetSoConMode(SoConIdxOfSocket) != SOAD_SOCON_OFFLINE)
            {
                IsSocketRequired = TRUE;
                break;
            }
        }
        /* close TcpIp socket */
        if (IsSocketRequired == FALSE)
        {
            (void)SoAd_TcpIpIfClose(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),Abort);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the change parameter request for the socket idx
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpIpChangeParameter
(
    SoAd_SocketIdxType SocketIdx,
    TPParameterType Parameter,
    uint16 Value
)
{
    return SoAd_TcpIpIfChangeParameter(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),Parameter,(uint8 *)&Value);
}
/********************************************************************************************************************
* @brief The Api is used to indicate the accepted tcpip socket id for the listen socket idx 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpSetAcceptedSocketId
(
    SoAd_SocketIdxType SocketIdx,
    SoAd_SocketIdxType SocketIdConnected
)
{
    if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CLOSED)
    { 
        SoAd_SocketCtrlSetTcpIpSocketId(SocketIdx,SocketIdConnected);
        SoAd_SocketCtrlSetSocketState(SocketIdx,SOAD_SOCK_STATE_ESTABLISHED);
        SoAd_SocketIncNumOfOpenSocket();
    }
}
/********************************************************************************************************************
* @brief The Api is used to indicate the processed tcp data for the socket
********************************************************************************************************************/
FUNC(void,SOAD_CODE) SoAd_SocketTcpReceived(SoAd_SocketIdxType SocketIdx,PduLengthType Length)
{
    SoAd_TcpIpIfTcpReceived(SocketIdx, Length);
}
/********************************************************************************************************************
* @brief The Api is used to check and udpate skip data for the socket
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpCheckAndUpdateSkipData
(
    SoAd_SocketIdxType SocketIdx,
    uint16 Length,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) SkippedLengthPtr
)
{
    Std_ReturnType RetVal = E_OK;
    
    /* check if skip bytes are present */
    if (SoAd_SocketCtrlGetSkipBytes(SocketIdx) > 0U)
    {
        if (SoAd_SocketCtrlGetSkipBytes(SocketIdx) > Length)
        {
            /* if skip bytes are greater than requested length , then update the skip bytes */
            SoAd_SocketCtrlSetSkipBytes(SocketIdx,SoAd_SocketCtrlGetSkipBytes(SocketIdx)-Length);
            /* notify TcpIp about reception of socket data is confirmed */
            SoAd_TcpIpIfTcpReceived(SocketIdx,Length);
            RetVal = E_NOT_OK;
        }
        else
        {
            /* update the bytes to be skipped and reset the skip bytes */
            *SkippedLengthPtr = SoAd_SocketCtrlGetSkipBytes(SocketIdx);
            SoAd_SocketCtrlSetSkipBytes(SocketIdx,0u);
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to check and udpate skip data for the socket
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpUpdateSkipData
(
    SoAd_SocketIdxType SocketIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    
    /* process skip data */
    if (SoAd_SocketCtrlGetSkipBytes(SocketIdx) > 0u)
    {
        if (SoAd_SocketCtrlGetSkipBytes(SocketIdx) < (TotalLen - *ReleaseBufLenPtr))
        {
            /* Update Release buffer length  */
            *ReleaseBufLenPtr += SoAd_SocketCtrlGetSkipBytes(SocketIdx);
            SoAd_SocketCtrlSetSkipBytes(SocketIdx,0U);
            RetVal=E_OK;
        }
        else
        {
            SoAd_SocketCtrlSetSkipBytes(SocketIdx,(TotalLen - *ReleaseBufLenPtr));
            *ReleaseBufLenPtr = TotalLen; 
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to transmit the data on the Udp socket
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_SocketUdpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    SoAd_SockAddrType *pRemoteAddr,
    uint16 TotalLength
)
{
    return SoAd_TcpIpIfUdpTransmit(SocketIdx,pRemoteAddr,TotalLength);
}
/********************************************************************************************************************
* @brief The Api is used to transmit the data on the Tcp socket
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_SocketTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    uint32 AvailableLength, 
    boolean ForceRetrieve
)
{
    return SoAd_TcpIpIfTcpTransmit(SocketIdx,AvailableLength,ForceRetrieve);
}
/********************************************************************************************************************
* @brief The Api is used to change the parameter value of the socket 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpChangeParameter
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId
)
{
    uint8 TcpNoDelay = 1U;
    uint32 TcpRxBufferMin = 0U;
    boolean TcpKeepAlive=FALSE;
    uint16 KeepAliveProbesMax=0U;
    uint32 TcpKeepAliveTime=0U;
    uint32 TcpKeepAliveInterval=0U;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketTcpIdxType SocketTcpIdx;
    uint8 FramePriority = SOAD_DEFAULT_FRAME_PRIORITY;
    
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    FramePriority = SoAd_SoConGrpCfgGetFramePriority(SoConGrpIdx);

    /* Update TCPIP_PARAMID_FRAMEPRIO */
    if (FramePriority != SOAD_DEFAULT_FRAME_PRIORITY)
    {
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx, TcpIpSocketId,TCPIP_PARAMID_FRAMEPRIO, &FramePriority); 
    }
    
    if (SoAd_SoConGrpCfgGetSocketTcpIdx(SoConGrpIdx) < SOAD_NUM_OF_TCP_SOCKET)
    {
        SocketTcpIdx = SoAd_SoConGrpCfgGetSocketTcpIdx(SoConGrpIdx);
        /* Update TCPIP_PARAMID_TCP_RXWND_MAX */
        TcpRxBufferMin = SoAd_SocketTcpCfgGetTcpRxBufferMin(SocketTcpIdx);
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx, TcpIpSocketId,TCPIP_PARAMID_TCP_RXWND_MAX,(uint8*)&TcpRxBufferMin); 
        /* Update TCPIP_PARAMID_TCP_NAGLE */
        if (FALSE != SoAd_SocketTcpCfgGetTcpNoDelay(SocketTcpIdx))
        {
            TcpNoDelay = 0U;
        }
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId, TCPIP_PARAMID_TCP_NAGLE, &TcpNoDelay); 
        /* Update TCPIP_PARAMID_TCP_KEEPALIVE */
        TcpKeepAlive = SoAd_SocketTcpCfgGetTcpKeepAlive(SocketTcpIdx);
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId, TCPIP_PARAMID_TCP_KEEPALIVE,(uint8 *)&TcpKeepAlive); 
        if (FALSE != TcpKeepAlive)
        {
            /* Update TCPIP_PARAMID_TCP_KEEPALIVE ,TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX 
                ,TCPIP_PARAMID_TCP_KEEPALIVE_TIME */
            TcpKeepAliveInterval = SoAd_SocketTcpCfgGetTcpKeepAliveInterval(SocketTcpIdx);
            KeepAliveProbesMax = SoAd_SocketTcpCfgGetKeepAliveProbesMax(SocketTcpIdx);
            TcpKeepAliveTime = SoAd_SocketTcpCfgGetTcpKeepAliveTime(SocketTcpIdx);
            (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL, 
                                        (uint8 *)&TcpKeepAliveInterval); 
            (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX, 
                                        (uint8 *)&KeepAliveProbesMax); 
            (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,TCPIP_PARAMID_TCP_KEEPALIVE_TIME, 
                                        (uint8 *)&TcpKeepAliveTime); 
            
        }
        /* pending parameters : TCPIP_PARAMID_TTL, TCPIP_PARAMID_TCP_OPTIONFILTER, TCPIP_PARAMID_PATHMTU_ENABLE
                                TCPIP_PARAMID_FLOWLABEL, TCPIP_PARAMID_DSCP */
    }
    (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,SOAD_PARAMID_STACK_SPECIFIC, NULL_PTR);
    (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,SOAD_PARAMID_STACK_SPECIFIC_TCP, NULL_PTR);
}

/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief The Api is used to change the parameter value of the Udp socket 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_SocketUdpChangeParameter
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId
)
{
    uint8 FramePriority;
    uint8 CheckSumEnabled;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);

    FramePriority = SoAd_SoConGrpCfgGetFramePriority(SoConGrpIdx);
    if(FramePriority != SOAD_DEFAULT_FRAME_PRIORITY)
    {
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx, TcpIpSocketId,TCPIP_PARAMID_FRAMEPRIO, &FramePriority); 
    }
    
    if(SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx) < SoAd_CfgGetNumOfSocketUdp())
    {
        CheckSumEnabled = SoAd_SocketUdpCfgGetChecksumEnabled(SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx));
        (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,TCPIP_PARAMID_UDP_CHECKSUM, &CheckSumEnabled);
    }   
    // should be called to make socket in non blocking mode, only for non asr
    (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,SOAD_PARAMID_STACK_SPECIFIC, NULL_PTR);
    (void)SoAd_TcpIpIfChangeParameter(SocketIdx,TcpIpSocketId,SOAD_PARAMID_STACK_SPECIFIC_UDP, NULL_PTR);
}
/********************************************************************************************************************
* @brief The Api is used to reset the local port of the socket
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketResetLocalPort(SoAd_SocketIdxType SocketIdx)
{
    boolean ResetLocalPort=TRUE;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketIdxType SoConGrpSocketIdx,SoConSocketIdx;
    SoAd_SoConIdType SoConIdxOfGrp;
    
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    if (SoConGrpIdx < SoAd_CfgGetNumOfSoConGrp())
    {
        if ((SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE) && 
            (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == FALSE))
        {
            SoConGrpSocketIdx = SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx);
            /* check for listen socket */
            if (SoAd_SocketCtrlGetSocketState(SoConGrpSocketIdx) == SOAD_SOCK_STATE_CLOSED)
            {
                for(SoConIdxOfGrp = SoAd_SocketCfgGetSoConStartIdx(SoConGrpSocketIdx);
                    SoConIdxOfGrp < SoAd_SocketCfgGetSoConEndIdx(SoConGrpSocketIdx);SoConIdxOfGrp++)
                {
                    SoConSocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdxOfGrp);
                    if (SoAd_SocketCtrlGetSocketState(SoConSocketIdx) != SOAD_SOCK_STATE_CLOSED)
                    {
                        ResetLocalPort = FALSE;
                        break;
                    }
                }
            }
            else
            {
                ResetLocalPort = FALSE;
            }
            /* If all the socket of listen socon grp closed, then reset the port of listen socket */
            if (ResetLocalPort == TRUE)
            {
                SoAd_SocketCtrlSetLocalPort(SoConGrpSocketIdx,SoAd_SoConGrpCfgGetLocalPort(SoConGrpIdx));
            }
        }
        else
        {
            /* reset the port of socket */
            SoAd_SocketCtrlSetLocalPort(SocketIdx,SoAd_SoConGrpCfgGetLocalPort(SoConGrpIdx));
        }
    }
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
