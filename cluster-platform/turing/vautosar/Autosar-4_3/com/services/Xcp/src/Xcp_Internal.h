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
*   @file Xcp_Internal.h
*   @ingroup Xcp
*   @brief This file provides the declaration of the Xcp internal APIs. 
********************************************************************************************************************/
#ifndef XCP_INTERNAL_H
#define XCP_INTERNAL_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp_Lcfg.h"

/********************************************************************************************************************
*  PUBLIC MACRO & TYPE DEFINITIONS                                                                                  *
********************************************************************************************************************/
/*! @brief  Defines the resource mask for the calibration pag */
#define XCP_RM_CAL_PAG                          0x01u
/*! @brief  Defines the resource mask for the DAQ */
#define XCP_RM_DAQ                              0x04u
/*! @brief  Defines the resource mask for the STIM */
#define XCP_RM_STIM                             0x08u
/*! @brief  Defines the resource mask for the PGM */
#define XCP_RM_PGM                              0x10u
/*! @brief  Defines the all resource mask*/
#define XCP_RM_ALL_RESOURCES                    0x1Du
/*! @brief Defines Connection states of the Xcp channel as Disconnected */
#define XCP_CON_STATE_DISCONNECTED              0x00u
/*! @brief Defines Connection states of the Xcp channel as Resume */
#define XCP_CON_STATE_RESUME                    0x01u
/*! @brief Defines Connection states of the Xcp channel as Connected */
#define XCP_CON_STATE_CONNECTED                 0x02u

/* DAQ_LIST_MODE (GET_DAQ_LIST_MODE, SET_DAQ_LIST_MODE) */
/*! @brief Defines the bit mask of daq list mode for the  start/sop selection */
#define XCP_DAQ_LIST_SELECTED                   0x01u 
/*! @brief Defines the bit mask of daq list mode  for the Data Stimulation Mode */
#define XCP_DAQ_LIST_DIRECTION                  0x02u
/*! @brief Defines the bit mask of daq list mode  for the Timestamps active */
#define XCP_DAQ_LIST_TIMESTAMP                  0x10u
/*! @brief Defines the bit mask of daq list mode  for the No PID */
#define XCP_DAQ_LIST_NO_PID                     0x20u 
/*! @brief Defines the bit mask of daq list mode  for the DAQ list is running */
#define XCP_DAQ_LIST_RUNNING                    0x40u 
/*! @brief Defines the bit mask of daq list mode  for the Resume Mode */
#define XCP_DAQ_LIST_RESUME                     0x80u 
/*! @brief Defines the bit mask of daq list mode  for the reserved type */
#define XCP_DAQ_LIST_RESERVED                   0x08u

/*! @brief Defines the type for the xcp timestamp */
#if ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_OFF )
typedef uint8 Xcp_TimestampType; 
#elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_BYTE )
typedef uint8 Xcp_TimestampType; 
#elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_WORD )
typedef uint16 Xcp_TimestampType; 
#elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_DWORD )
typedef uint32 Xcp_TimestampType; 
#else
#error "Invalid valid timestamp size. Valid sizes are 0, 1, 2 and 4 Bytes"
#endif


#if( XCP_STIM == STD_ON )
/*! @brief Defines the STIM action value check ODT buffer */
#define XCP_STIM_CHECK_ODT_BUFFER           0x01u
/*! @brief Defines the STIM action value reset ODT buffer */
#define XCP_STIM_RESET_ODT_BUFFER           0x02u

/*! @brief Defines the STIM data available status */
#define XCP_NO_STIM_DATA_AVAILABLE          0x00u
/*! @brief Defines the STIM data not available status */
#define XCP_STIM_DATA_AVAILABLE             0x01u

/*! @brief Defines the STIM Single shot mode type */
#define XCP_STIM_SINGLE_SHOT_MODE           (0x00u)
/*! @brief Defines the STIM continuous mode type */
#define XCP_STIM_CONTINUOUS_MODE            (0x01u)
# endif
/*! @brief Defines the overload indication as None */
#define XCP_DAQ_OVERLOAD_INDICATION_NONE      (0u<<6)
/*! @brief Defines the overload indication as PID */
#define XCP_DAQ_OVERLOAD_INDICATION_PID       (1u<<6)
/*! @brief Defines the overload indication as Event */
#define XCP_DAQ_OVERLOAD_INDICATION_EVENT     (2u<<6)
/*! @brief Defines the overload indication as MSB */
#define XCP_DAQ_OVERLOAD_MSB                  0x80u

/*! @brief Define the Offset for CTO .2 is due to initial length of dto */
# define XCP_CONNECT_DTO_OFFSET               2u
/*! @brief Defines the  max length for the send event */
#define XCP_SENDEVENT_MAX_LENGTH(Ch)          ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 2u)) 

/*! @brief Defines the current event bit mask as No operation, i,e Inactive (DAQ not running, Event not configured) */
#define XCP_EVENT_NOP                         0x00u 
/*! @brief Defines the current event bit mask as DAQ active */
#define XCP_EVENT_DAQ                         0x01u 
/*! @brief Defines the current event bit mask as DAQ queue overload */
#define XCP_EVENT_DAQ_OVERLOAD                0x02u 
/*! @brief Defines the current event bit mask as timeout supervision violation */
#define XCP_EVENT_DAQ_TIMEOUT                 0x04u 
/*! @brief Defines the current event bit mask as stim active */
#define XCP_EVENT_STIM                        0x08u 
/*! @brief Defines the current event bit mask as stim data not available */
#define XCP_EVENT_STIM_OVERRUN                0x10u

/*! @brief Defines the DAQ flag bit mask for selected */
#define XCP_DAQ_FLAG_SELECTED                       0x01u
/*! @brief Defines the DAQ flag bit mask for direction */
#define XCP_DAQ_FLAG_DIRECTION                      0x02u
/*! @brief Defines the DAQ flag bit mask for timestamp */
#define XCP_DAQ_FLAG_TIMESTAMP                      0x10u 
/*! @brief Defines the DAQ flag bit mask for selected PID*/
#define XCP_DAQ_FLAG_NO_PID                         0x20u 
/*! @brief Defines the DAQ flag bit mask for DAQ running */
#define XCP_DAQ_FLAG_RUNNING                        0x40u
/*! @brief Defines the DAQ flag bit mask for resume mode */
#define XCP_DAQ_FLAG_RESUME                         0x80u

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      This API is used to update the response buffer with the negative response
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  ErrorCommand the error command value 
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_SetNegativeResponse(Xcp_ChannelType XcpChannel,uint8 ErrorCommand);
/*!******************************************************************************************************************
*   @brief      This service is used to update the MTA for the xcp channel
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  AddressExtension  address extension value 
*   @param[in]  Address  MTA address value
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_SetMta(Xcp_ChannelType XcpChannel,uint8 AddressExtension, Xcp_AddressPtrType Address );
/*!******************************************************************************************************************
*   @brief      This service is used to read the value from the MTA
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  Size  size of the data to be read
*   @param[out]  Data  pointer to update the data 
*   @return status of the request XCP_CMD_OK for successful read else error code  
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_ReadMta
(
    Xcp_ChannelType XcpChannel,
    uint8 DataSize,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Data 
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the write request of the MTA.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  Size  length of the data
*   @param[in]  pDataBuffer  pointer to the Data buffer
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_WriteMta
( 
    Xcp_ChannelType XcpChannel,
    uint8 Size,
    CONSTP2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) pDataBuffer
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the request to stop all DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdStopAllDaq(Xcp_ChannelType XcpChannel);
/*!******************************************************************************************************************
*   @brief      This service is used to intialize the DAQ queue.
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdQueueInit(Xcp_ChannelType XcpChannel);
/*!******************************************************************************************************************
*   @brief      This service is used to whether access of the requested reource is protected or not.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  Resource resource value for which the protection status to be checked.
*   @return status of the access protection protection 
*   XCP_CMD_OK: resourced unlocked XCP_ERR_ACCESS_LOCKED: resource locked.
********************************************************************************************************************/
FUNC(uint8,XCP_CODE) Xcp_ResourceProtectionCheck(Xcp_ChannelType XcpChannel,uint8 Resource);
/*!******************************************************************************************************************
*   @brief  This API is used to calculate the send queue entry size and limit value for the xcp channel 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_CalcSendQueueEntrySizeAndLimit( Xcp_ChannelType XcpChannel );
#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* XCP_INTERNAL_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
