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
*   @file SoAd_TcpIpIf.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd_TcpIpIf is to provide the interface for the tcpip abstraction. 
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Lcfg.h"
#include "SchM_SoAd.h"
#include "SoAd_Socket.h"
#include "SoAd_TcpIpIf.h"
#if (SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
#include "TcpIp.h"
#endif
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/*! @brief Defines the DHCP IPV4 Host name option byte value */
#define SOAD_DHCP_OPT_V4_HOSTNAME   81u
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

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
* @brief The Api is used to request the Ip address assignment of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfRequestIpAddrAssignment
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) DefaultRouterPtr
)
{
    Std_ReturnType RetVal;
    /* Autosar API */
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_RequestIpAddrAssignment(LocalAddrIdx, Type,LocalIpAddrPtr, Netmask, DefaultRouterPtr);
#elif (SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    RetVal = SoAd_TcpIpBsdRequestIpAddrAssignment(LocalAddrIdx, Type,LocalIpAddrPtr, Netmask, DefaultRouterPtr);
#else
    RetVal = E_NOT_OK;
#endif     
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to release the ip addr assigned  of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfReleaseIpAddrAssignment(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    Std_ReturnType RetVal;
    /* Autosar API */
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_ReleaseIpAddrAssignment(LocalAddrIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    RetVal = SoAd_TcpIpBsdReleaseIpAddrAssignment(LocalAddrIdx); 
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the current ip address assigned to the local addr id of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetIpAddr
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) DefaultRouterPtr 
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    /* Autosar API */
    RetVal = TcpIp_GetIpAddr(LocalAddrIdx,LocalAddrPtr,NetmaskPtr,DefaultRouterPtr);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    SoAd_TcpIpBsdGetIpAddr(LocalAddrIdx,LocalAddrPtr,NetmaskPtr,DefaultRouterPtr);    
    RetVal = E_OK;
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;

}
/********************************************************************************************************************
* @brief The Api is used to get the physicall addr(MAC) of the local addr id of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetPhysAddr
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_SocketIdxType   SocketIdx,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) PhysAddrPtr
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    /* Autosar API */
    RetVal = TcpIp_GetPhysAddr(LocalAddrIdx,PhysAddrPtr);
    SOAD_DUMMY_STATEMENT(SocketIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    RetVal = SoAd_TcpIpBsdGetPhysAddr(LocalAddrIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),PhysAddrPtr);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to read the DHCP host name of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfDhcpReadOption
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) length,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) data
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    /* Autosar API */
    RetVal = TcpIp_DhcpReadOption(LocalAddrIdx, SOAD_DHCP_OPT_V4_HOSTNAME,length,data);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    RetVal = SoAd_TcpIpBsdReadDhcpHostNameOption(LocalAddrIdx,length,data);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to write the DHCP host name of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfDhcpWriteOption
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    uint8 length,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) data
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    /* Autosar API */
    RetVal = TcpIp_DhcpWriteOption(LocalAddrIdx, SOAD_DHCP_OPT_V4_HOSTNAME,length,data);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
    RetVal = SoAd_TcpIpBsdWriteDhcpHostNameOption(LocalAddrIdx,length,data);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get and reset the measurement data
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetAndResetMeasurementData
( 
    SoAd_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,SOAD_APPL_VAR) MeasurementDataPtr 
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    /* Autosar API */
    RetVal = TcpIp_GetAndResetMeasurementData(MeasurementIdx, MeasurementResetNeeded,MeasurementDataPtr);
#else 
    SOAD_DUMMY_STATEMENT(MeasurementIdx);
    SOAD_DUMMY_STATEMENT(MeasurementResetNeeded);
    SOAD_DUMMY_STATEMENT(MeasurementDataPtr);
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to trigger the address resolution to check for remote address
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpIfTriggerAddressResolution
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_SockAddrType RemoteAddr
)
{
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    uint8 CtrlIdx = 0u;
    uint8 PhysAddr[6u] = { 0u, 0u, 0u, 0u, 0u, 0u };
    if ( TcpIp_GetCtrlIdx(LocalAddrIdx, &CtrlIdx) == E_OK)
    {
        (void)TcpIp_GetRemotePhysAddr(CtrlIdx,&RemoteAddr, &PhysAddr[0], TRUE);
    }
#else
    SOAD_DUMMY_STATEMENT(LocalAddrIdx);
    SOAD_DUMMY_STATEMENT(RemoteAddr);
#endif

}
/********************************************************************************************************************
* @brief The Api request to transmit UDP data the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_TcpIpIfUdpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    SoAd_SockAddrType *pRemoteAddr,
    uint16 TotalLength
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_UdpTransmit(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),NULL_PTR,pRemoteAddr,TotalLength);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdUdpTransmit(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),pRemoteAddr,TotalLength);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api request to transmit Tcp data of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_TcpIpIfTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    uint32 AvailableLength, 
    boolean ForceRetrieve
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_TcpTransmit(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),NULL_PTR,AvailableLength,ForceRetrieve);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdTcpTransmit(SocketIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),
                                        AvailableLength,ForceRetrieve);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to change the socket parameter of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfChangeParameter 
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    SoAd_TcpIpParameterType ParameterId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ParameterValue
)
{
    Std_ReturnType RetVal;
    #if (SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX) 
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    #endif
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_ChangeParameter(TcpIpSocketId, ParameterId,ParameterValue); 
    SOAD_DUMMY_STATEMENT(SocketIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdChangeParameter(SocketIdx,TcpIpSocketId,ParameterId,ParameterValue);  
    SoConGrpIdx =  SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    if((RetVal == E_OK) &&
       (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE))
    {
        LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
        if (SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST )
        {
            RetVal |= SoAd_TcpIpBsdChangeParameter(SocketIdx,SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketIdx),
                                                    ParameterId,ParameterValue);  
            RetVal |= SoAd_TcpIpBsdChangeParameter(SocketIdx,SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketIdx),
                                                    ParameterId,ParameterValue);  
        }
        else
        {
            /* join multicast group */
            RetVal = SoAd_TcpIpBsdJoinMultiCastGroupV4(SocketIdx, TcpIpSocketId);
        }
    }
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle the Tcp connect of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfTcpConnect
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_TcpConnect(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx), RemAddrPtr); 
    SOAD_DUMMY_STATEMENT(TcpIpSocketId);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdTcpConnect(SocketIdx,TcpIpSocketId,RemAddrPtr);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle tcp listen of the the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfTcpListen
(
    SoAd_SocketIdxType ListenSocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    uint16 MaxChannels
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_TcpListen(TcpIpSocketId, MaxChannels); 
    SOAD_DUMMY_STATEMENT(ListenSocketIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdTcpListen(ListenSocketIdx,TcpIpSocketId,MaxChannels);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to bind the socket of the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfBind
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_Bind(TcpIpSocketIdx,LocalAddrIdx,PortPtr); 
    SOAD_DUMMY_STATEMENT(SocketIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdBind(SocketIdx,TcpIpSocketIdx,PortPtr);
    SOAD_DUMMY_STATEMENT(LocalAddrIdx);
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the socket of the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetSocket
(
    SoAd_SocketIdxType SocketId,
    SoAd_DomainType Domain,
    SoAd_ProtocolType Protocol,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, SOAD_APPL_DATA) SocketIdPtr
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_SoAdGetSocket(Domain,Protocol,SocketIdPtr); 
    SOAD_DUMMY_STATEMENT(SocketId);
    SOAD_DUMMY_STATEMENT(LocalAddrIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    RetVal = SoAd_TcpIpBsdGetSocket(SocketId,Domain,Protocol,LocalAddrIdx,SocketIdPtr); 
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used close the socket of the TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfClose
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    boolean Abort
)
{
    Std_ReturnType RetVal;
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    RetVal = TcpIp_Close(TcpIpSocketIdx,Abort); 
    SOAD_DUMMY_STATEMENT(SocketIdx);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)  
    SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketIdx,Abort); 
    RetVal = E_OK;
#else
    RetVal = E_NOT_OK;
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used idicate that the SoAd has received and processed the message
* @param[in] SocketIdx the SoAd socket id on which the message received
* @param[in] Length the length of the processsed received message
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpIfTcpReceived(SoAd_SocketIdxType SocketIdx,PduLengthType Length)
{
#if(SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
    (void)TcpIp_TcpReceived(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx), Length);
#elif(SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)   
    SoAd_TcpIpBsdTcpReceived(SocketIdx,Length);
#else   
    RetVal = E_NOT_OK;
#endif
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/


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

