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
*   @file Xcp_PgmCmd.h
*   @ingroup Xcp
*   @brief This file provides the declaration of the Xcp program command API. 
********************************************************************************************************************/
#ifndef XCP_PGMCMD_H
#define XCP_PGMCMD_H
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
*   @brief      This service is used to process the program command program start 0xD2 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramStart
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program clear 0xD1 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramClear
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program 0xD0 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgram
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program reset 0xCF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramReset
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command processor info 0xCE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorGetPgmProcessorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command get sector info 0xCD request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorGetSectorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program prepare 0xCC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramPrepare
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program next 0xCA request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramNext
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to process the program command program max 0xC9 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramMax
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* XCP_PGMCMD_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
