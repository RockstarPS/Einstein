
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
*    @file Xcp_Lcfg.c
*    @ingroup XcpConfiguration
*    @brief This is Xcp Link time configuration source file. It contains definitions of Link time configuration
*    parameters for the Xcp module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp_Lcfg.h"

#ifdef XCPONETH_SUPPORTED
#include "XcpOnEth.h"
#endif

/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
/* @brief Defines the control state of Xcp.This is used to enable/disable the functionality of Xcp */
VAR(Xcp_ControlStateType,XCP_VAR_INIT) Xcp_ControlState = XCP_CONTROL_STATE_ENABLE;
/* @brief Defines the ctrl status for the xcp channel */
VAR(Xcp_ChannelCtrlStatusType,XCP_VAR_NOINIT) Xcp_ChannelCtrlStatus[XCP_NUM_OF_CHANNELS];
/* @brief Defines the STIM mode supported for the XCP */
VAR(Xcp_StimModeType,XCP_VAR_NOINIT) Xcp_StimMode;
/* @brief Defines the transmission mode for the Xcp channels */
VAR(Xcp_TransmissionModeType,XCP_VAR_NOINIT) Xcp_TransmissionMode[XCP_NUM_OF_CHANNELS];
/* @brief Defines the Xcp event control status */
VAR(Xcp_EventCtrlStatusType,XCP_VAR_NOINIT) Xcp_EventCtrlStatus[XCP_MAX_EVENT];
/* @brief Defines the Xcp STIM buffer */
VAR(Xcp_DtoBufferType,XCP_VAR_NOINIT) Xcp_StimBuffer[XCP_NUM_OF_CHANNELS][XCP_MAX_ODT_STIM];
/* @brief Defines the Xcp DAQ queue type */
VAR(Xcp_DaqQueueType,XCP_VAR_NOINIT)  Xcp_DaqSendQueue[XCP_NUM_OF_CHANNELS];
/* @brief Defines the Xcp DAQ queue reference */
VAR(uint8,XCP_VAR_NOINIT) Xcp_DaqSendQueueRef[XCP_DAQ_SEND_QUEUE_SIZE];
/********************************************************************************************************************
* #! DoIP const config  data                                                                                       *
********************************************************************************************************************/
/*  @brief Defines the Xcp channel configuration 
    UnlockKeySizeMax    : Defines the unlock key size max
    UploadSizeMax       : Defines the upload size max   
    DownloadSizeMax     : Defines the download size max
    NetworkChannelId    : Defines the network channel idx
*/
CONST(Xcp_ChannelConfigType,XCP_CONST) Xcp_ChannelConfig[XCP_NUM_OF_CHANNELS]=
{
    { 10U, 10U, 100U, 0U }
};
/* @brief Defines the transport layer configuration for the each TL 
    TlServiceFunctPtr   : Defines the transport layer service function 
    TlSendFunctPtr      : Defines the transport layer send function
    TlSendFlushFunctPtrType : Defines the transport layer send flush function
*/
CONST(Xcp_TlConfigType,XCP_CONST) Xcp_TlConfig[XCP_NUM_OF_TL_SUPPORTED] =
{
    #ifdef XCPONETH_SUPPORTED
    {   &XcpOnEth_TLService , &XcpOnEth_Send , &XcpOnEth_SendFlush }
    #else
    {NULL_PTR, NULL_PTR, NULL_PTR}
    #endif
};

/* @brief Defines the program sector configuration for each sector .
    SectorStartAddress  : Defines the program sector start address
    SectorEndAddress    : Defines the program sector end address
    SectorLength        : Defines the program sector length    
*/
CONST(Xcp_PgmSectorConfigType,XCP_CONST) Xcp_PgmSectorConfig[XCP_MAX_PGM_SECTOR]=
{
    {0x00000000U, 0x00001FFFFU, 0x1FFFFU}
};

/* @brief Defines the program sector address for each sector. */
CONST(uint32,XCP_CONST) Xcp_PgmSectorAddress[XCP_MAX_PGM_SECTOR]=
{
    0x00000000
};

/* @brief Defines the length of program sector address for each sector.  */
CONST(uint8,XCP_CONST) Xcp_PgmSectorNameLength[XCP_MAX_PGM_SECTOR]=
{
    8U
};

/* @brief Defines the a2l file name */
CONST(char, XCP_CONST) Xc_StationId[] = "E40_1_1";

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
