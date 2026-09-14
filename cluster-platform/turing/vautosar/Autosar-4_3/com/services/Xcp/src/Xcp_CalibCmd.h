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
*   @file Xcp_CalibCmd.h
*   @ingroup Xcp
*   @brief This file provides the declaration of the Xcp calibration command API. 
********************************************************************************************************************/
#ifndef XCP_CALIBCMD_H
#define XCP_CALIBCMD_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                          *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service is used to process the Calibration command download 0xF0 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the Calibration command download next 0xEF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownloadNext
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the Calibration command download max 0xEE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownloadMax
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the Calibration command short download 0xED request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorShortDownload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the Calibration command modify bits 0xEC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorModifyBits
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the request to start all selected DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdStartAllSelectedDaq(Xcp_ChannelType XcpChannel);
#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* XCP_CALIBCMD_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
