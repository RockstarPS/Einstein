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
*    @file TcpIp_Lcfg.h
*    @ingroup TcpIpConfiguration
*    @brief This is TcpIp link time configuration header file. It contains definitions of link time
*    configuration parameters for the TcpIp module.
*    @defgroup TcpIpConfiguration
*    @brief This contains the link time configurations for the TcpIp module.
********************************************************************************************************************/
#ifndef TCPIP_LCFG_H
#define TCPIP_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* #! TcpIp const config  data                                                                                       *
********************************************************************************************************************/
/*! @brief specifies the assignment policy for the IP address. */
extern const TcpIp_AddrAssignmentConfigType TcpIp_AddrAssignmentConfig[TCPIP_NUM_OF_LOCALADDR];
/*! @brief specifies a static IP address including directly related parameters. */
extern const TcpIp_StaticIpAddressConfigType TcpIp_StaticIpAddressConfig[TCPIP_NUM_OF_LOCALADDR];
/*! @brief Specifies the local IP (Internet Protocol) addresses used for IP communication. */
extern const TcpIp_LocalAddrConfigType TcpIp_LocalAddrConfig[TCPIP_NUM_OF_LOCALADDR];
/*! @brief specifies an upper layer of TcpIp that uses the socket API.  */
extern const TcpIp_SocketOwnerConfigType TcpIp_SocketOwnerConfig[TCPIP_NUM_OF_SOCKETS];
/*! @brief Defines the connfiguration of the TcpIp ctrl */
extern const TcpIp_CtrlConfigType TcpIp_CtrlConfig; 
/*! @brief defines Configuration data structure of the TcpIp module.  */
extern const TcpIp_TcpIpConfigType TcpIp_TcpIpConfig;

#endif /* TCPIP_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


