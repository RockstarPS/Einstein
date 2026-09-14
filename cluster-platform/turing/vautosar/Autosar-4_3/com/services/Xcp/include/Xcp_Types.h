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
*    @file Xcp_Types.h
*    @ingroup Xcp
*    @brief This file provides the types for the Xcp module.
********************************************************************************************************************/
#ifndef XCP_TYPES_H
#define XCP_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"

/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef XCP_CODE
#define XCP_CODE
#endif 

#ifndef XCP_CONST
#define XCP_CONST
#endif  

#ifndef XCP_APPL_DATA
#define XCP_APPL_DATA
#endif

#ifndef XCP_APPL_CODE
#define XCP_APPL_CODE
#endif 

#ifndef XCP_APPL_VAR
#define XCP_APPL_VAR
#endif 

#ifndef XCP_APPL_CONST
#define XCP_APPL_CONST
#endif

#ifndef XCP_CALLOUT_CODE
#define XCP_CALLOUT_CODE
#endif

#ifndef XCP_VAR
#define XCP_VAR
#endif

#ifndef XCP_VAR_INIT
#define XCP_VAR_INIT
#endif

#ifndef XCP_VAR_NOINIT
#define XCP_VAR_NOINIT
#endif

#ifndef XCP_VAR_POWER_ON_INIT
#define XCP_VAR_POWER_ON_INIT
#endif

#ifndef XCP_VAR_FAST
#define XCP_VAR_FAST
#endif

#ifndef XCP_VAR_SLOW
#define XCP_VAR_SLOW
#endif

/*! @brief Defines the Command Request Object command byte position */
#define XCP_CRO_CMD_BYTE                            0u
/*! @brief Defines the Command Response Message command byte position */
#define XCP_CRM_CMD_BYTE                            0u
/*! @brief Defines the Command Response Message error byte position */
#define XCP_CRM_ERR_BYTE                            1u
/*! @brief Defines the Command Response Message error length byte position */
#define XCP_CRM_ERR_LEN_BYTE                        2u

/* #! Below are the standard command - mandatory */
#define XCP_CMD_CONNECT                             0xFFu
#define XCP_CMD_DISCONNECT                          0xFEu
#define XCP_CMD_GET_STATUS                          0xFDu
#define XCP_CMD_SYNC                                0xFCu
/* #! Below are the standard command - optional */
#define XCP_CMD_GET_COMM_MODE_INFO                  0xFBu
#define XCP_CMD_GET_ID                              0xFAu
#define XCP_CMD_SET_REQUEST                         0xF9u
#define XCP_CMD_GET_SEED                            0xF8u
#define XCP_CMD_UNLOCK                              0xF7u
#define XCP_CMD_SET_MTA                             0xF6u
#define XCP_CMD_UPLOAD                              0xF5u
#define XCP_CMD_SHORT_UPLOAD                        0xF4u
#define XCP_CMD_BUILD_CHECKSUM                      0xF3u
#define XCP_CMD_TRANSPORT_LAYER_CMD                 0xF2u
#define XCP_CMD_USER_CMD                            0xF1u
/* #! Below are the Calibration command - mandatory */
#define XCP_CMD_DOWNLOAD                            0xF0u
/* #! Below are the Calibration command - optional */
#define XCP_CMD_DOWNLOAD_NEXT                       0xEFu
#define XCP_CMD_DOWNLOAD_MAX                        0xEEu
#define XCP_CMD_SHORT_DOWNLOAD                      0xEDu
#define XCP_CMD_MODIFY_BITS                         0xECu
/* #! Below are the PAG command - mandatory */
#define XCP_CMD_SET_CAL_PAGE                        0xEBu
#define XCP_CMD_GET_CAL_PAGE                        0xEAu
/* #! Below are the PAG command - optional */
#define XCP_CMD_GET_PAG_PROCESSOR_INFO              0xE9u
#define XCP_CMD_GET_SEGMENT_INFO                    0xE8u
#define XCP_CMD_GET_PAGE_INFO                       0xE7u
#define XCP_CMD_SET_SEGMENT_MODE                    0xE6u
#define XCP_CMD_GET_SEGMENT_MODE                    0xE5u
#define XCP_CMD_COPY_CAL_PAGE                       0xE4u
/* #! Below are the DAQ command - mandatory */
#define XCP_CMD_CLEAR_DAQ_LIST                      0xE3u
#define XCP_CMD_SET_DAQ_PTR                         0xE2u
#define XCP_CMD_WRITE_DAQ                           0xE1u
#define XCP_CMD_SET_DAQ_LIST_MODE                   0xE0u
#define XCP_CMD_START_STOP_DAQ_LIST                 0xDEu
#define XCP_CMD_START_STOP_SYNCH                    0xDDu
/* #! Below are the DAQ command - Optional */
#define XCP_CMD_GET_DAQ_LIST_MODE                   0xDFu
#define XCP_CMD_GET_DAQ_CLOCK                       0xDCu
#define XCP_CMD_READ_DAQ                            0xDBu
#define XCP_CMD_GET_DAQ_PROCESSOR_INFO              0xDAu
#define XCP_CMD_GET_DAQ_RESOLUTION_INFO             0xD9u
#define XCP_CMD_GET_DAQ_LIST_INFO                   0xD8u
#define XCP_CMD_GET_DAQ_EVENT_INFO                  0xD7u
/* #! Below are the DAQ command  mandatory : Dynamic configuration */
#define XCP_CMD_FREE_DAQ                            0xD6u
#define XCP_CMD_ALLOC_DAQ                           0xD5u
#define XCP_CMD_ALLOC_ODT                           0xD4u
#define XCP_CMD_ALLOC_ODT_ENTRY                     0xD3u
/* #! Below are the Pgm commands, mandatory */
#define XCP_CMD_PROGRAM_START                       0xD2u
#define XCP_CMD_PROGRAM_CLEAR                       0xD1u
#define XCP_CMD_PROGRAM                             0xD0u
#define XCP_CMD_PROGRAM_RESET                       0xCFu
/* #! Below are the Pgm commands, optional */
#define XCP_CMD_GET_PGM_PROCESSOR_INFO              0xCEu
#define XCP_CMD_GET_SECTOR_INFO                     0xCDu
#define XCP_CMD_PROGRAM_PREPARE                     0xCCu
#define XCP_CMD_PROGRAM_FORMAT                      0xCBu
#define XCP_CMD_PROGRAM_NEXT                        0xCAu
#define XCP_CMD_PROGRAM_MAX                         0xC9u
#define XCP_CMD_PROGRAM_VERIFY                      0xC8u
/* #! Below are the DAQ command - Optional */
#define XCP_CMD_WRITE_DAQ_MULTIPLE                  0xC7u
#define XCP_CMD_DTO_CTR_PROPERTIES                  0xC5u
/*! @brief Defines the start id range of Xcp commands */
#define XCP_CMD_START                               0xC0u

/*!  @brief Defines the value for the reponse packet */
#define XCP_PID_RES                                 0xFFu 
/*!  @brief Defines the value for the error reponse packet */
#define XCP_PID_ERR                                 0xFEu 
/*!  @brief Defines the value for the event reponse packet */
#define XCP_PID_EV                                  0xFDu 
/*!  @brief Defines the value for the service request reponse packet */
#define XCP_PID_SERV                                0xFCu

/*!  @brief Defines the Xcp send status bit mask - Command response message request  */
#define XCP_CRM_REQUEST                             (0x01u)
/*!  @brief Defines the Xcp send status bit mask  - Data transfer object(DAQ) request  */
#define XCP_DTO_REQUEST                             (0x02u)
/*!  @brief Defines the Xcp send status bit mask  - event request  */
#define XCP_EVT_REQUEST                             (0x04u)
/*!  @brief Defines the Xcp send status bit mask  - Command response message pending  */
#define XCP_CRM_PENDING                             (0x10u)
/*!  @brief Defines the Xcp send status bit mask  - Data transfer object(DAQ) pending  */
#define XCP_DTO_PENDING                             (0x20u)
/*!  @brief Defines the Xcp send status bit mask  - event pending  */
#define XCP_EVT_PENDING                             (0x40u)
/*!  @brief Defines the Xcp send status bit mask  - tx pending  */
#define XCP_SEND_PENDING                            (XCP_DTO_PENDING|XCP_CRM_PENDING|XCP_EVT_PENDING)

/* #! Defines the session status bit mask - store calibration request   */
#define XCP_SESSION_STORE_CAL_REQ                    (0x0001u)
/* #! Defines the session status bit mask - store Daq no resume  */
#define XCP_SESSION_STORE_DAQ_REQ_NO_RESUME          (0x0002u)
/* #! Defines the session status bit mask - store Daq req resume  */
#define XCP_SESSION_STORE_DAQ_REQ_RESUME             (0x0004u)
/* #! Defines the session status bit mask - store Daq req  */
#define XCP_SESSION_CLEAR_DAQ_REQ                    (0x0008u)
/* #! Defines the session status bit mask - session error   */
#define XCP_SESSION_ERROR                            (0x0010u) 
/* #! Defines the session status bit mask - session connected  */
#define XCP_SESSION_CONNECTED                        (0x0020u) 
/* #! Defines the session status bit mask - session daq  */
#define XCP_SESSION_DAQ                              (0x0040u)
/* #! Defines the session status bit mask - session resume  */
#define XCP_SESSION_RESUME                           (0x0080u)
/* #! Defines the session status bit mask - session polling  */
#define XCP_SESSION_POLLING                          (0x0100u) 
/* #! Defines the session status bit mask - daq req no resume  */
#define XCP_SESSION_STORE_DAQ_REQ_NO_RESUME_INTERNAL (0x0200u) 
/* #! Defines the session status bit mask - block upload */
#define XCP_SESSION_BLOCK_UPLOAD                     (0x0400u) 

/*! @brief Defines the bit mask for DAQ Timestamp not supported */
#define XCP_DAQ_TIMESTAMP_OFF                       0x00u
/*! @brief Defines the bit mask for DAQ Timestamp size as byte  */
#define XCP_DAQ_TIMESTAMP_BYTE                      0x01u
/*! @brief Defines the bit mask for DAQ Timestamp size as word  */
#define XCP_DAQ_TIMESTAMP_WORD                      0x02u
/*! @brief Defines the bit mask for DAQ Timestamp size as dword  */
#define XCP_DAQ_TIMESTAMP_DWORD                     0x04u


/*! @brief Defines the bit mask for the timstamp unit support for 1ns */
#define XCP_DAQ_TIMESTAMP_UNIT_1NS                  (0u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 10ns */
#define XCP_DAQ_TIMESTAMP_UNIT_10NS                 (1u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 100ns */
#define XCP_DAQ_TIMESTAMP_UNIT_100NS                (2u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 1us */
#define XCP_DAQ_TIMESTAMP_UNIT_1US                  (3u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 10us */
#define XCP_DAQ_TIMESTAMP_UNIT_10US                 (4u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 100us */
#define XCP_DAQ_TIMESTAMP_UNIT_100US                (5u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 1ms */
#define XCP_DAQ_TIMESTAMP_UNIT_1MS                  (6u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 10ms */
#define XCP_DAQ_TIMESTAMP_UNIT_10MS                 (7u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 100ms */
#define XCP_DAQ_TIMESTAMP_UNIT_100MS                (8u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 1ms */
#define XCP_DAQ_TIMESTAMP_UNIT_1S                   (9u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 1ps */
#define XCP_DAQ_TIMESTAMP_UNIT_1PS                  (10u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 10ps */
#define XCP_DAQ_TIMESTAMP_UNIT_10PS                 (11u<<4)
/*! @brief Defines the bit mask for the timstamp unit support for 100ps */
#define XCP_DAQ_TIMESTAMP_UNIT_100PS                (12u<<4)

/*! @brief Defines the bit mask for DAQ Timestamp not supported */
#define XCP_DAQ_TIMESTAMP_OFF                       0x00u
/*! @brief Defines the bit mask for DAQ Timestamp size as byte  */
#define XCP_DAQ_TIMESTAMP_BYTE                      0x01u
/*! @brief Defines the bit mask for DAQ Timestamp size as word  */
#define XCP_DAQ_TIMESTAMP_WORD                      0x02u
/*! @brief Defines the bit mask for DAQ Timestamp size as dword  */
#define XCP_DAQ_TIMESTAMP_DWORD                     0x04u

/*! @brief Defines the configuartion type as static */
#define DAQ_STATIC                                  0x0U
/*! @brief Defines the configuartion type as dynamic */
#define DAQ_DYNAMIC                                 0x0U

/*! @brief Defines the DAQ configuration type */
typedef uint8 Xcp_DaqConfigType;

/*! @brief Defines the DAQ xcp identification size type */
typedef enum
{
    /*! @brief Defines the DAQ xcp identification type as absolute*/
    ABSOLUTE=0U,
    /*! @brief Defines the DAQ xcp identification type as relative byte */
    RELATIVE_BYTE,
    /*! @brief Defines the DAQ xcp identification type as relative word */
    RELATIVE_WORD,
    /*! @brief Defines the DAQ xcp identification type as relative word aligned */
    RELATIVE_WORD_ALIGNED
}Xcp_IdentificationFieldType;


/*! @brief Defines the transmission mode type as OFF */
#define XCP_TX_OFF  0U
/*! @brief Defines the transmission mode type as ON */
#define XCP_TX_ON   1U
/*! @brief Defines the xcp transmission mode type */
typedef uint8 Xcp_TransmissionModeType;
/* Flush Types */
/*! @brief Defines the Xcp flush type as flush CTO only */
#define XCP_FLUSH_CTO   0u
/*! @brief Defines the Xcp flush type as flush DTO only */
#define XCP_FLUSH_DTO   1u
/*! @brief Defines the Xcp flush type as flush all */
#define XCP_FLUSH_ALL   2u

#endif /* XCP_TYPES_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
