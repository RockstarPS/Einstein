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
*    @file SoAd_Cfg.h
*    @ingroup SoAd" Configuration
*    @brief This is SoAd Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the SoAd module.
*    Auto generated code in PCHINNAT at 2024-01-20 21:51:54.517727
********************************************************************************************************************/
#ifndef SOAD_CFG_H
#define SOAD_CFG_H
#include "Std_Types.h"
#ifdef DLOG
#include "Dlog.h"    
#endif

/********************************************************************************************************************
*  #! SoAd Precompile Configuration                                                                  *
********************************************************************************************************************/
#define SOAD_DEV_ERROR_DETECT  STD_ON
#define SOAD_GET_AND_RESET_MEASUREMENT_DATA_API  STD_OFF
#define SOAD_IPV6_ADDRESS_ENABLED  STD_OFF
#define SOAD_MAIN_FUNCTION_PERIOD  10U
#define SOAD_ROUTING_GROUP_MAX  1U
#define SOAD_SO_CON_MAX                             4u
#define SOAD_VERSION_INFO_API                       STD_OFF

/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the SOAD configuration software Major version */
#define SOAD_CFG_SW_MAJOR_VERSION                   1U
/*! @brief Defines the SOAD configuration software Minor version */
#define SOAD_CFG_SW_MINOR_VERSION                   0U
/*! @brief Defines the SOAD configuration software Patch version */
#define SOAD_CFG_SW_PATCH_VERSION                   0U
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by SOAD configuration  */
#define SOAD_CFG_AR_RELEASE_MAJOR_VERSION           4U
/*! @brief Defines the AUTOSAR Release Minor version supported by SOAD configuration  */
#define SOAD_CFG_AR_RELEASE_MINOR_VERSION           3U
/*! @brief Defines the AUTOSAR Release patch version supported by SOAD configuration  */
#define SOAD_CFG_AR_RELEASE_REVISION_VERSION        1U 

/********************************************************************************************************************
*  #! SoAd module configuration                                                                      *
********************************************************************************************************************/

/*! @brief Defines the dummy macro */
#ifndef SOAD_DUMMY_STATEMENT
#define SOAD_DUMMY_STATEMENT(v) (void)v
#endif

#define SOAD_MAX_PDU_LENGTH                                         4096
#define SOAD_SOCON_ID_INVALID                                       SOAD_NUM_OF_SOCON
#define SOAD_TCPIP_API_AUTOSAR                                      0U
#define SOAD_TCPIP_API_LINUX                                        1U
#define SOAD_TCPIP_API                                              SOAD_TCPIP_API_AUTOSAR

/* -1 for bsd linux / max val for autosar */
#if (SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
#include "TcpIp_Cfg.h" // include for autosar
#define SOAD_SOCKET_ID_INVALID                                      7u
#else
#define SOAD_SOCKET_ID_INVALID                                      -1
#endif
/* SoAd Pdu route id */
#define SOAD_PDU_UdpServerPduRouteIf    0U
#define SOAD_PDU_UdpServerPduRouteTp    1U
#define SOAD_PDU_UdpClientPduRouteIf    2U
#define SOAD_PDU_UdpClientPduRouteTp    3U
#define SOAD_PDU_TcpServerPduRouteIf    4U
#define SOAD_PDU_TcpServerPduRouteTp    5U
#define SOAD_PDU_TcpClientPduRouteIf    6U
#define SOAD_PDU_TcpClientPduRouteTp    7U
#define SOAD_PDU_UdpDoIPServerPduRouteTp 8U
#define SOAD_PDU_UdpDoIPServerPduRouteIf 9U
#define SOAD_PDU_TcpDoIPServerPduRouteTp 10U

/* SoAd Socket route id */
#define SOAD_PDU_UdpServerSocketRouteIf    0U
#define SOAD_PDU_UdpServerSocketRouteTp    1U
#define SOAD_PDU_UdpClientSocketRouteIf    2U
#define SOAD_PDU_UdpClientSocketRouteTp    3U
#define SOAD_PDU_TcpServerSocketRouteIf    4U
#define SOAD_PDU_TcpServerSocketRouteTp    5U
#define SOAD_PDU_TcpClientSocketRouteIf    6U
#define SOAD_PDU_TcpClientSocketRouteTp    7U
#define SOAD_PDU_UdpDoIPServerSocketRouteTp 8U
#define SOAD_PDU_TcpDoIPServerSocketRouteTp 9U
	

/* SoAd routing group id */
#define SOAD_RG_UdpServerRoutingGroup   0U
#define SOAD_RG_UdpClientRoutingGroup   1U
#define SOAD_RG_TcpServerRoutingGroup   2U
#define SOAD_RG_TcpClientRoutingGroup   3U
#define SOAD_RG_DoIPRoutingGroup   3U
/* SoAd SoCon Id*/
#define SOAD_SOCON_UdpServerSocketConnection 0U
#define SOAD_SOCON_UdpClientSocketConnection 1U
#define SOAD_SOCON_TcpServerSocketConnection 2U
#define SOAD_SOCON_TcpClientSocketConnection 3U
#define SOAD_SOCON_UdpDoIPServerSocketConnection 4U
#define SOAD_SOCON_UdpDoIPAnnounceServerSocketConnection 5U
#define SOAD_SOCON_TcpDoIPServerSocketConnection 6U

/********************************************************************************************************************
* #! SoAd types                                                                                      *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/

/*! @brief SoCon identifier type for unique identification of a SoAd socket connection. The size of this type depends 
*   on the maximum number of socket connections which is specified by configuration parameter SoAdSoConMax. */
typedef uint8 SoAd_SoConIdType;
/*! @brief RoutingGroup identifier type for unique identification of a SoAd routing group. The size of this type
*   depends on the maximum number of routing groups which is specified by configuration parameter 
*   SoAdRoutingGroupMax. */
typedef uint8 SoAd_RoutingGroupIdType;


#endif /* SOAD_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


