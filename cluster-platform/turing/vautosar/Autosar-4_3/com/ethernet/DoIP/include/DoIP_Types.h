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
*    @file DoIP_Types.h
*    @ingroup DoIP
*    @brief This file provides the types for the DoIP module.
********************************************************************************************************************/
#ifndef DOIP_TYPES_H
#define DOIP_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/*! @brief Pending return type */ 
#define DOIP_E_PENDING  0x10u

#ifndef RTE_DOIP_TYPE_H /*! values to be defined in Rte_DoIP_Type.h */
/*! @brief DoIP Power Mode "not ready" */
#define DOIP_NOT_READY      0x00u
/*! @brief DoIP Power Mode "ready" */
#define DOIP_READY          0x01
/*! @brief DoIP Power Mode "not supported" */
#define DOIP_NOT_SUPPORTED  0x02

/*! @brief Used for handling of the PowerMode in DoIP entity status requests */
typedef uint8 DoIP_PowerStateType;

/*! @brief Defines the type for Activation line  as Active */
#define DOIP_ACTIVATION_LINE_ACTIVE         0U
/*! @brief Defines the type for Activation line as Inactive */
#define DOIP_ACTIVATION_LINE_INACTIVE       1u
/*! @brief Defines the type for Activation line */
typedef uint8 DoIP_ActivationLineType;
#endif

/*! @brief Defines the type for the DoIP Init status */
typedef enum
{
    /*! @brief Defines the status as UnInitialized */
    DoIP_StateUnInitialized=0u,
    /*! @brief Defines the status as Initialized */
    DoIP_StateInitialized
}DoIP_InitStateType;

typedef uint8 DoIP_FurtherActionByteType;

#define DOIP_VIN_LENGTH                     17u
#define DOIP_GID_LENGTH                     6u
#define DOIP_EID_LENGTH                     6u
#define DOIP_PHYS_ADDR_LENGTH               6u
#define DOIP_ADDR_LENGTH                    2u
#define DOIP_GENERIC_HEADER_LENGTH          8u
#define DOIP_GEN_HDR_TYPE_IDX               2u
#define DOIP_GEN_HDR_NACK_CODE_LENGTH       1u
#define DOIP_ROUT_ACTIV_REQ_MIN_LENGTH      7u
#define DOIP_ROUT_ACTIV_REQ_MAX_LENGTH      11u
#define DOIP_ROUT_ACTIV_REQ_TYPE_LENGTH     1u
#define DOIP_ROUT_ACTIV_REQ_RSVD_LENGTH     4u
#define DOIP_ROUT_ACTIV_REQ_OEM_LENGTH      4u
#define DOIP_ROUT_ACTIV_ACK_MIN_LENGTH      9u
#define DOIP_ROUT_ACTIV_ACK_MAX_LENGTH      13u
#define DOIP_ROUT_ACTIV_ACK_OEM_LENGTH      4u
#define DOIP_DIAG_HDR_LENGTH                4u
#define DOIP_DIAG_MSG_REQ_MIN_LENGTH        4u
#define DOIP_DIAG_MSG_ACK_LENGTH            5u
/* Hostname option size minimum: "DoIP-" */
#define DOIP_HOST_NAME_MIN_SIZE             5u  
/* Hostname option size with VIN prefix only: "DoIP-VIN" */
#define DOIP_HOST_NAME_VIN_PREFIX_SIZE      8u  
 /* Hostname option size with VIN: "DoIP-VIN<VinValue>" */
#define DOIP_HOST_NAME_VIN_SIZE             25u
#define DOIP_LOGICAL_ADDRESS_LENGTH         2u

/*! Number of vehicle identification responses. */
# define DOIP_IDENT_RES_NUM                     1u

/* DoIP header types */
# define DOIP_HEADER_TYPE_GEN_NACK                    0x0000u
# define DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ           0x0001u
# define DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_EID       0x0002u
# define DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_VIN       0x0003u
# define DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT        0x0004u
# define DOIP_HEADER_TYPE_ROUT_ACTIV_REQ              0x0005u
# define DOIP_HEADER_TYPE_ROUT_ACTIV_RES              0x0006u
# define DOIP_HEADER_TYPE_ALIVE_CHECK_REQ             0x0007u
# define DOIP_HEADER_TYPE_ALIVE_CHECK_RES             0x0008u
# define DOIP_HEADER_TYPE_ENTITY_STATE_REQ            0x4001u
# define DOIP_HEADER_TYPE_ENTITY_STATE_RES            0x4002u
# define DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_REQ    0x4003u
# define DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES    0x4004u
# define DOIP_HEADER_TYPE_DIAG_REQ                    0x8001u
# define DOIP_HEADER_TYPE_DIAG_ACK                    0x8002u
# define DOIP_HEADER_TYPE_DIAG_NACK                   0x8003u
# define DOIP_HEADER_TYPE_OEM_SPECIFIC                0xEEEEu
# define DOIP_HEADER_TYPE_INVALID                     0xEFFFu

/* DoIP protocol versions */
# define DOIP_PROTOCOL_VERSION_2012                (uint8)0x02u
# define DOIP_PROTOCOL_INV_VERSION_2012            (uint8)0xFD  
# define DOIP_PROTOCOL_VERSION_DEFAULT             (uint8)0xFFu
# define DOIP_PROTOCOL_INV_VERSION_DEFAULT         (uint8)(~(DOIP_PROTOCOL_VERSION_DEFAULT))

/* DoIP generic nack codes */
# define DOIP_GEN_NACK_FORMAT                      0x00u
# define DOIP_GEN_NACK_TYPE                        0x01u
# define DOIP_GEN_NACK_MAX_LEN                     0x02u
# define DOIP_GEN_NACK_OUT_OF_MEM                  0x03u
# define DOIP_GEN_NACK_INV_LEN                     0x04u
# define DOIP_GEN_NACK_OK                          0xFFu
# define DOIP_GEN_NACK_LEN_BYTE                    0x01u

/* DoIP routing activation nack codes */
# define DOIP_ROUT_ACTIV_RES_CODE_UNKNOWN_TESTER   0x00u
# define DOIP_ROUT_ACTIV_RES_CODE_SOCKETS_IN_USE   0x01u
# define DOIP_ROUT_ACTIV_RES_CODE_DIFFERENT_TESTER 0x02u
# define DOIP_ROUT_ACTIV_RES_CODE_ALREADY_ACTIV    0x03u
# define DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT  0x04u
# define DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED 0x05u
# define DOIP_ROUT_ACTIV_RES_CODE_INV_ACTIV_TYPE   0x06u
# define DOIP_ROUT_ACTIV_RES_CODE_SUCCESS          0x10u
# define DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REQUIRED 0x11u

/* DoIP diagnostic request nack codes */
# define DOIP_DIAG_MSG_RES_CODE_ACK                0x00u
# define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_SRC_ADDR   0x01u /* described in ISO/CD 13400 - not used */
# define DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR   0x02u
# define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_TGT_ADDR   0x03u
# define DOIP_DIAG_MSG_RES_CODE_MSG_TOO_LARGE      0x04u
# define DOIP_DIAG_MSG_RES_CODE_OUT_OF_MEMORY      0x05u
# define DOIP_DIAG_MSG_RES_CODE_TGT_UNREACHABLE    0x06u
# define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_NETWORK    0x07u
# define DOIP_DIAG_MSG_RES_CODE_NETWORK_TRANSPROT  0x08u

/* DoIP diagnostic power mode ack codes */
# define DOIP_DIAG_POWER_MODE_RES_CODE_NOT_READY   0x00u
# define DOIP_DIAG_POWER_MODE_RES_CODE_READY       0x01u

/* DHCP-Options DoIP-Tester */
# define DOIP_DHCP_OPT_TABLE_SIZE                  0x04u
# define DOIP_DHCP_OPT_SUB_LEN                     0x05u /* enterNum + subOptionLen */
# define DOIP_DHCP_OPT_CODE                        0x01u
# define DOIP_DHCP_OPT_LEN                         0x05u
# define DOIP_DHCP_OPT_IPV4_ADDR_SIZE              0x04u
# define DOIP_DHCP_OPT_IPV6_ADDR_SIZE              0x10u
# define DOIP_DHCP_OPT_125_MIN_LEN                 0x0Bu /* enterNum + subOptionLen + hdr + addrSize */
# define DOIP_DHCP_OPT_17_MIN_LEN                  0x17u /* enterNum + subOptionLen + hdr + addrSize */
# define DOIP_DHCP_OPT_ENTERPRISE_NUM              0x00000C7Bu

/* Announcement reset types */
# define DOIP_ANNOUNCE_SET                         0x00u
# define DOIP_ANNOUNCE_RESET                       0x01u

/*! OEM payload type flags type. */
typedef uint8 DoIP_OemPayloadTypeFlagType;
# define DOIP_OEM_PAYLOAD_TYPE_PROT_UDP            (uint8)0x00u
# define DOIP_OEM_PAYLOAD_TYPE_PROT_TCP            (uint8)0x01u
# define DOIP_OEM_PAYLOAD_TYPE_ROUT_NOT_ACTIV      (uint8)0x00u
# define DOIP_OEM_PAYLOAD_TYPE_ROUT_ACTIV          (uint8)0x02u

/*! Unused parameter. */
# define DOIP_UNUSED_PARAM                      0u

/*! Routing activation state type. */
typedef uint8 DoIP_RoutingActivationStateType;
# define DOIP_ROUTING_ACTIVATION_STATE_NONE                     0u
# define DOIP_ROUTING_ACTIVATION_STATE_AUTH_PENDING             1u
# define DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING             2u
# define DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED                3u

#define DOIP_ADDR_ANY                         ((uint16)0xFFFFu)

/*! IP address request state type. */
typedef uint8 DoIP_IpAddrReqStateType;
# define DOIP_IP_ADDR_REQ_STATE_NONE                    0x00u
# define DOIP_IP_ADDR_REQ_STATE_REQUESTED               0x01u

/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef DOIP_CODE
#define DOIP_CODE
#endif 

#ifndef DOIP_CONST
#define DOIP_CONST
#endif  

#ifndef DOIP_APPL_DATA
#define DOIP_APPL_DATA
#endif

#ifndef DOIP_APPL_CONST
#define DOIP_APPL_CODE
#endif

#ifndef DOIP_CALLOUT_CODE
#define DOIP_CALLOUT_CODE
#endif

#ifndef DOIP_VAR
#define DOIP_VAR
#endif

#ifndef DOIP_VAR_INIT
#define DOIP_VAR_INIT
#endif

#ifndef DOIP_VAR_NOINIT
#define DOIP_VAR_NOINIT
#endif

#ifndef DOIP_VAR_POWER_ON_INIT
#define DOIP_VAR_POWER_ON_INIT
#endif

#ifndef DOIP_VAR_FAST
#define DOIP_VAR_FAST
#endif

#ifndef DOIP_VAR_SLOW
#define DOIP_VAR_SLOW
#endif


#endif /* DOIP_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

