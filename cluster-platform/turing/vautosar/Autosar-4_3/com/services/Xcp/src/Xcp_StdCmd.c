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
*   @file Xcp_StdCmd.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of standard commands of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_StdCmd.h"
#include "Xcp_Internal.h"
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*  #! Feature validation check                                                                                      *
********************************************************************************************************************/
/********************************************************************************************************************
*  #! PRIVATE MACRO DEFINITIONS                                                                                     *
********************************************************************************************************************/
/*! @brief Defines the resource support value for Calibration */
#if (XCP_CALIBRATION_PAGE_ENABLED == STD_ON)
    #define XCP_CRM_RESOURCE_SUPPORTED_CAL_PAG  (uint8)XCP_RM_CAL_PAG
#else
    #define XCP_CRM_RESOURCE_SUPPORTED_CAL_PAG  0x0U
#endif

/*! @brief Defines the resource support value for DAQ */
#if (XCP_DAQ_ENABLED == STD_ON)
    #define XCP_CRM_RESOURCE_SUPPORTED_DAQ  (uint8)XCP_RM_DAQ
#else
    #define XCP_CRM_RESOURCE_SUPPORTED_DAQ  0x0U
#endif

/*! @brief Defines the resource support value for STIM */
#if (XCP_STIM_ENABLED == STD_ON)
    #define XCP_CRM_RESOURCE_SUPPORTED_STIM (uint8)XCP_RM_STIM
#else
    #define XCP_CRM_RESOURCE_SUPPORTED_STIM 0x0U
#endif
/*! @brief Defines the resource support value for program */
#if (XCP_PROGRAM_ENABLED == STD_ON)
    #define XCP_CRM_RESOURCE_SUPPORTED_PGM (uint8)XCP_RM_PGM
#else
    #define XCP_CRM_RESOURCE_SUPPORTED_PGM 0x0U
#endif
/*! @brief Defines the resource support value for Xcp */
#define XCP_CRM_RESOURCE_SUPPORTED_VALUE (XCP_CRM_RESOURCE_SUPPORTED_CAL_PAG | XCP_CRM_RESOURCE_SUPPORTED_DAQ | \
                                        XCP_CRM_RESOURCE_SUPPORTED_STIM    | XCP_CRM_RESOURCE_SUPPORTED_PGM )

/*! @brief Defines the comm mode info support */
#if ( XCP_COMM_MODE_INFO == STD_ON )
#define XCP_CRM_CONNECT_COMM_BASIC_CMB_OPTIONAL (uint8)XCP_CMB_OPTIONAL
#else 
#define XCP_CRM_CONNECT_COMM_BASIC_CMB_OPTIONAL 0x0U
#endif
/*! @brief Defines the block upload support */
#if ( XCP_BLOCK_UPLOAD == STD_ON )
#define XCP_CRM_CONNECT_COMM_BASIC_CMB_SLAVE_BLOCK_MODE (uint8)XCP_CMB_SLAVE_BLOCK_MODE
#else 
#define XCP_CRM_CONNECT_COMM_BASIC_CMB_SLAVE_BLOCK_MODE 0x0U
#endif
/*! @brief Defines the comm mode basic value */
#define XCP_CRM_CONNECT_COMM_BASIC_VALUE ( XCP_CRM_CONNECT_COMM_BASIC_CMB_OPTIONAL | \
                                        XCP_CRM_CONNECT_COMM_BASIC_CMB_SLAVE_BLOCK_MODE )
/*! @brief Defines the Xcp protocol layer verion number supported */
#define XCP_PROTOCOL_LAYER_VERSION                  0x0101U
/*! @brief Defines the Xcp protocol layer verion number High byte */
#define XCP_PROTOCOL_LAYER_VERSION_HIGH_BYTE        0x01U
/*! @brief Defines the Xcp protocol layer verion number Low byte */
#define XCP_PROTOCOL_LAYER_VERSION_LOW_BYTE         0x01U
/*! @brief Defines the Xcp protocol transport layer verion number supported */
#define XCP_TRANSPORT_LAYER_VERSION                 0x0101U
/*! @brief Defines the Xcp protocol transport layer verion number High byte */
#define XCP_TRANSPORT_LAYER_VERSION_HIGH_BYTE       0x01U
/*! @brief Defines the Xcp protocol transport layer verion number Low byte */
#define XCP_TRANSPORT_LAYER_VERSION_LOW_BYTE        0x01U

/*! @brief Defines the Xcp master block mode bit mask */
#define XCP_COMM_MODE_MASTER_BLOCK_MODE_BIT         0x01U
/*! @brief Defines the Xcp interleaved  mode bit mask */
#define XCP_COMM_MODE_INTERLEAVED_MODE_BIT          0x02U

/*! @brief Defines the Identifier Type (GET_ID) for ASCII  */
#define XCP_ID_TYPE_ASCII                           0x00u
/*! @brief Defines the Identifier Type (GET_ID) for ASAM name */
#define XCP_ID_TYPE_ASAM_NAME                       0x01u
/*! @brief Defines the Identifier Type (GET_ID) for ASAM path */
#define XCP_ID_TYPE_ASAM_PATH                       0x02u
/*! @brief Defines the Identifier Type (GET_ID) for ASAM URL */
#define XCP_ID_TYPE_ASAM_URL                        0x03u
/*! @brief Defines the Identifier Type (GET_ID) for ASAM upload */
#define XCP_ID_TYPE_ASAM_UPLOAD                     0x04u

/*! @brief Defines the mode transfer mode bit mask */
#define XCP_ID_MODETRANSFER_MODE_BIT                0x01U          
/*! @brief Defines the compressed encrypted  bit mask */
#define XCP_ID_COMPRESSED_ENCRYPTED_BIT             0x02U          

/*! @brief Defines the DAQ requested mode store calibration*/
#define XCP_SET_REQ_MODE_STORE_CAL_REQ_BIT             0x01U
/*! @brief Defines the DAQ requested mode DAQ no resume */
#define XCP_SET_REQ_MODE_STORE_DAQ_REQ_NO_RESUME_BIT   0x02U
/*! @brief Defines the DAQ requested mode DAQ resume */
#define XCP_SET_REQ_MODE_STORE_DAQ_REQ_RESUME_BIT      0x04U
/*! @brief Defines the DAQ requested mode DAQ clear */
#define XCP_SET_REQ_MODE_CLEAR_DAQ_REQ_BIT             0x08U

/*! @brief Defines the resource bit mask for calibration resource */
#define XCP_RESOURCE_CAL_PAG_BIT                    0x01u
/*! @brief Defines the resource bit mask for DAQ resource */
#define XCP_RESOURCE_DAQ_BIT                        0x04u
/*! @brief Defines the resource bit mask for STIM resource */
#define XCP_RESOURCE_STIM_BIT                       0x08u
/*! @brief Defines the resource bit mask for PGM resource */
#define XCP_RESOURCE_PGM_BIT                        0x10u
/*! @brief Defines the resource bit mask for all supported resource */
#define XCP_RESOURCE_ALL_RESOURCES_BIT              0x1Du

/*! @brief Defines the seed command value for mode 0 */
#define XCP_STD_CMD_GET_SEED_MODE_0                 0x0U
/*! @brief Defines the seed command value for mode 1 */
#define XCP_STD_CMD_GET_SEED_MODE_1                 0x01U

/*! @brief Defines the unlock key max size for the channel */
#define XCP_CRO_UNLOCK_MAX_KEY_SIZE(Ch)             ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 2u))

/********************************************************************************************************************
*  #! PRIVATE TYPE DECLARATION                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  #! PRIVATE FUNCTION PROTOTYPES                                                                                   *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#define XCP_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                     *
********************************************************************************************************************/

/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*   @brief      This service is used to process the standard command connect 0xFF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorConnect
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{

    /* lock all resources with initial value. */
    #if ( XCP_SEED_KEY == STD_ON )
    Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus = Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionInitStatus;
    #endif

    Xcp_ChannelCtrlStatus[XcpChannel].ConnectionState = XCP_CONNECTION_STATE_TYPE_CONNECTED;
    Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_CONNECTED;   
    /* set resource */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = XCP_CRM_RESOURCE_SUPPORTED_VALUE;
    /* set com mode */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = XCP_CRM_CONNECT_COMM_BASIC_VALUE;
    /* set max cto */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = Xcp_ChannelCtrlStatus[XcpChannel].MaxCto;
    /* set max dto */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)Xcp_ChannelCtrlStatus[XcpChannel].MaxDto;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Xcp_ChannelCtrlStatus[XcpChannel].MaxDto>>8U) ;
    /* set xcp protocol version */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = XCP_PROTOCOL_LAYER_VERSION_HIGH_BYTE;
    /* set xcp transport protocol version */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = XCP_TRANSPORT_LAYER_VERSION_HIGH_BYTE;
    /* update reponse length */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;

    #if( XCP_DAQ == STD_ON )
    /* Calculate Send Queue Entry size based on MaxDto parameter. */
    Xcp_CalcSendQueueEntrySizeAndLimit(XcpChannel);
    #endif

    /* notify to application layer */
    Xcp_ApplConnectionStateNotification(XcpChannel,XCP_CON_STATE_CONNECTED);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command Disconnect 0xFE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorDisconnect
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    Xcp_Disconnect(XcpChannel);
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command Get status 0xFD request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorGetStatus
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* set Current session status - byte 1*/
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U] = Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus;
    /* set Current resource protection status - byte 2 */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2U] = Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus;
    /* reserved byte 3*/
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3U] = 0U;
    /* set the Session configuration id - byte 4 */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4U] = (uint8)(Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId);
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5U] = (uint8)(Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId >> 8U);
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 5U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command Synch 0xFC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorSynch
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_CMD_SYNCH);
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard get comm mode 0xFB request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorGetCommModeInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* Byte 1	Reserved */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U] = 0x00U;
    /* Byte 3 Reserved */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3U] = 0x00U;
    #if( XCP_BLOCK_DOWNLOAD == STD_ON )
    /* Byte 2	COMM_MODE_OPTIONAL */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2U] = XCP_COMM_MODE_MASTER_BLOCK_MODE_BIT;
    /* Byte 4	MAX_BS */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4U] = XCP_MAX_DOWNLOAD_BLOCK_SIZE;
    /* Byte 5	MIN_ST */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5U] = XCP_MAX_ST;
    #else
    /* Byte 2	COMM_MODE_OPTIONAL */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3U] = 0x00U;
    /* Byte 4	MAX_BS */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4U] = 0x00U;
    /* Byte 5	MIN_ST */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5U] = 0x00U;
    #endif 
    /* interleav mode not supported */
    /* Byte 6	QUEUE_SIZE */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6U] = 0U;
    /* Byte 7 XCP Driver Version Number */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7U] = XCP_SW_MAJOR_VERSION;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard get Id 0xFA request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorGetId
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    #if( XCP_GET_ID_GENERIC == STD_ON )
    uint32 GetIdLength=0U;
    P2VAR(uint8,AUTOMATIC,XCP_VAR_NOINIT) pDataBuffer;
    #endif
    /* 1    BYTE   Mode - supported only mode transfer with upload 0*/
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U] = 0U;
    /* 2,3 Word - reserved */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2U] = 0U;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3U] = 0U;
    /* Initialize MTA length. Mode 0 ,the length is 0 */
    Xcp_UtilMemSet(&Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4],0x00U,4U);

    #if (XCP_STATION_ID_LENGTH > 0U)
    if (CmdPtr[1U] == XCP_ID_TYPE_ASAM_NAME)
    {
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4]= (uint8)(XCP_STATION_ID_LENGTH);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5]= (uint8)(XCP_STATION_ID_LENGTH>>8U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6]= (uint8)(XCP_STATION_ID_LENGTH>>16U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7]= (uint8)(XCP_STATION_ID_LENGTH>>24U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
        /* set the Memory Transfer Address (MTA) address , so the master can upload the data */
        Xcp_SetMta(XcpChannel,0x00U,(Xcp_AddressPtrType)&Xc_StationId[0]);
        
    }
    else
    #endif
    {
        #if( XCP_GET_ID_GENERIC == STD_ON )
        GetIdLength = Xcp_ApplGetIdData(&pDataBuffer,CmdPtr[1U]);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4]= (uint8)GetIdLength;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5]= (uint8)(GetIdLength>>8U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6]= (uint8)(GetIdLength>>16U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7]= (uint8)(GetIdLength>>24U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
        if (GetIdLength >0U)
        {
            Xcp_SetMta(XcpChannel,0x00U,(Xcp_AddressPtrType)pDataBuffer);
        }
        #endif
    }
}
#if( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) )
/********************************************************************************************************************
*   @brief      This service is used to process the standard command set request  0xF9 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorSetRequest
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    boolean ValidRequest = FALSE;
#if (XCP_PAGE_FREEZE == STD_ON)
    /* STORE_CAL_REQ sets a request to save calibration data into non-volatile memory */
    if ((CmdPtr[1] & XCP_SET_REQ_MODE_STORE_CAL_REQ_BIT) != 0U)
    {
        ValidRequest = TRUE;
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_STORE_CAL_REQ;
    }
#endif 
#if (XCP_PAGE_FREEZE == STD_ON)
    /* The STORE_DAQ_REQ_NO_RESUME does not set the slave into RESUME mode. */
    if ((CmdPtr[1] & XCP_SET_REQ_MODE_STORE_DAQ_REQ_NO_RESUME_BIT) != 0U)
    {
        ValidRequest = TRUE;
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_STORE_DAQ_REQ_NO_RESUME;
        Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId = (uint16)CmdPtr[1];
        Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId |= (((uint16)CmdPtr[2])<<8U);
    }

    /* The STORE_DAQ_REQ_RESUME sets a request to save all selected DAQ lists to memory,
        but at the same time implicitly sets the slave into RESUME mode. */
    if ((CmdPtr[1] & XCP_SET_REQ_MODE_STORE_DAQ_REQ_RESUME_BIT) != 0U)
    {
        ValidRequest = TRUE;
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_STORE_DAQ_REQ_NO_RESUME;
         Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId = (uint16)CmdPtr[1];
        Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId |= (((uint16)CmdPtr[2])<<8U);
    }

    if ((CmdPtr[1] & XCP_SET_REQ_MODE_CLEAR_DAQ_REQ_BIT) != 0U)
    {
        ValidRequest = TRUE;
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_STORE_DAQ_REQ_NO_RESUME;
    }
#endif
    if (ValidRequest == FALSE)
    {
        Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_OUT_OF_RANGE);
    }
}
#endif
/********************************************************************************************************************
*   @brief      This service is used to process the standard command Get seed 0xF8 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorGetSeed
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 SeedLength = 0U;
    uint8 ErrorCode = XCP_CMD_OK;
    if (CmdPtr[0] != XCP_STD_CMD_GET_SEED_MODE_0)
    {
        /* mode 1 not supported */
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else if (((CmdPtr[1] & XCP_RESOURCE_ALL_RESOURCES_BIT) == 0U) && (CmdPtr[1] > 0U))
    {
        /* invalid resources */
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* check if resource is unprotected */
        if ((Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus & CmdPtr[1]) != 0U)
        {
            SeedLength = Xcp_ApplGetSeed(CmdPtr[0],
                                        &Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1]);
            if (SeedLength > Xcp_ChannelCtrlStatus[XcpChannel].MaxCto - 2U)
            {
                /* Seed length exceeds one cto */
                ErrorCode = XCP_ERR_OUT_OF_RANGE;
            }
            else
            {
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = SeedLength;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen +=  (uint16)(SeedLength+1U);
            }
        }
        else
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen +=  1U;
        }
    }

    if (ErrorCode != XCP_CMD_OK)
    {
        /* set negative response */
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command unlock 0xF7 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorUnlock
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Resource = 0U;
    uint8 ErrorCode = XCP_CMD_OK;
    
    /* check for valid key length. */
    if (CmdPtr[1] > XCP_CRO_UNLOCK_MAX_KEY_SIZE(XcpChannel))
    {
        ErrorCode = XCP_ERR_SEQUENCE;
    }
    else
    {
        Resource = Xcp_ApplUnlock(&CmdPtr[2],CmdPtr[1]);
        if (Resource == 0x0u)
        {
            Xcp_Disconnect(XcpChannel);
            ErrorCode = XCP_ERR_ACCESS_LOCKED;
        }
        else
        {
            /* unlock protection status for the reource */
            Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus &= (uint8)~Resource;
            /* set response data */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 1U;
        }
    }
    if (ErrorCode != XCP_CMD_OK)
    {
        /* set negative response */
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command set MTA 0xF6 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorSetMta
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    Xcp_SetMta(XcpChannel,CmdPtr[3],(Xcp_AddressPtrType)&CmdPtr[4]);
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command upload 0xF5 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorUpload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 BlockSize;
    uint8 ErrorCode = XCP_CMD_OK;
   
     BlockSize = CmdPtr[1];
    
    # if( XCP_BLOCK_UPLOAD == STD_OFF )
    if (( BlockSize == 0U) ||  (BlockSize > Xcp_ChannelConfig[XcpChannel].UploadSizeMax))
    # else
    if ( BlockSize == 0U) 
    #endif
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        #if( XCP_BLOCK_UPLOAD == STD_ON )
        if (BlockSize > Xcp_ChannelConfig[XcpChannel].UploadSizeMax)
        {
            /* update pending block size */
            Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = BlockSize - Xcp_ChannelConfig[XcpChannel].UploadSizeMax;
            BlockSize =  Xcp_ChannelConfig[XcpChannel].UploadSizeMax;
            /* copy data */
            ErrorCode =  Xcp_ReadMta(XcpChannel,BlockSize,&Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U]);
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += (uint16)(BlockSize + 1U);
            if ((ErrorCode == XCP_CMD_OK) || (ErrorCode == XCP_CMD_PENDING))
            {
                Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_BLOCK_UPLOAD;
            }
        }
        else
        #endif
        {
            ErrorCode =  Xcp_ReadMta(XcpChannel,BlockSize,&Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U]);
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += (uint16)(BlockSize+1U);
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        if( ErrorCode == XCP_CMD_PENDING )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending = TRUE;
        }
        else
        {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command short upload 0xF4 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorShortUpload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_CMD_OK; 

    /* check for size */
    if ((CmdPtr[1] == 0U ) || (CmdPtr[1] >Xcp_ChannelConfig[XcpChannel].UploadSizeMax ))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* set mta */
        Xcp_SetMta(XcpChannel,CmdPtr[3],(Xcp_AddressPtrType)CmdPtr[4]);
        ErrorCode =  Xcp_ReadMta(XcpChannel,CmdPtr[1],&Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U]);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += (uint16)(CmdPtr[1]+1U);
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        if( ErrorCode == XCP_CMD_PENDING )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending = TRUE;
        }
        else
        {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command build checksum  0xF3 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorBuildChecksum
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint32 Checksum=0U;
    uint8 ChecksumType=0U;
    uint32 BlockSize = 0U;
    uint8 ErrorCode = XCP_CMD_OK; 
    /* get block size */
    BlockSize = (((uint32)CmdPtr[4]) | (((uint32)CmdPtr[5]) << 8U) | 
                 (((uint32)CmdPtr[6]) << 16U) |  (((uint32)CmdPtr[7]) << 24U));
    
    if ((BlockSize > XCP_CHECKSUM_MAX_BLOCK_SIZE) 
    #if (XCP_READ_PROTECTION == STD_ON)
        || (XCP_ERR_ACCESS_DENIED == Xcp_ApplGetReadAccess(XcpChannel,Xcp_ChannelCtrlStatus[XcpChannel].MTA,BlockSize))
    #endif
    )
    {
        Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_OUT_OF_RANGE);
        /* set reserved data */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
        /* set max block size */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] =(uint8)XCP_CHECKSUM_MAX_BLOCK_SIZE;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] =(uint8)(XCP_CHECKSUM_MAX_BLOCK_SIZE>>8U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] =(uint8)(XCP_CHECKSUM_MAX_BLOCK_SIZE>>16U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] =(uint8)(XCP_CHECKSUM_MAX_BLOCK_SIZE>>24U);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
        
    }
    else
    {
        ErrorCode = Xcp_ApplCalculateChecksum((uint8 *)Xcp_ChannelCtrlStatus[XcpChannel].MTA ,
                                            BlockSize,&Checksum,&ChecksumType);
        if (ErrorCode == XCP_CMD_OK)
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = ChecksumType;
            /* reserved */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
            /* update checksum */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] =(uint8)Checksum;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] =(uint8)(Checksum>>8U);
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] =(uint8)(Checksum>>16U);
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] =(uint8)(Checksum>>24U);
            /* Move MTA to next value. */
            Xcp_ChannelCtrlStatus[XcpChannel].MTA += BlockSize;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
        }
    }

    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        if( ErrorCode == XCP_CMD_PENDING )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending = TRUE;
        }
        else
        {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command transport layer 0xF2 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorTlCmd
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_ERR_OUT_OF_RANGE;
    Xcp_TlServiceFunctPtrType pTlServiceFunct;

    if (Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl < XCP_NUM_OF_TL_SUPPORTED) 
    {
        pTlServiceFunct = Xcp_TlConfig[Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl].TlServiceFunctPtr;
        if ( pTlServiceFunct != NULL_PTR)
        {
            ErrorCode = pTlServiceFunct(XcpChannel,CmdPtr);
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        if( ErrorCode == XCP_CMD_PENDING )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending = TRUE;
        }
        else
        {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the standard command User command 0xF1 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_StdCmdProcessorUserCmd
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode;
    ErrorCode = Xcp_ApplUserCmdProcessor(XcpChannel,CmdPtr);
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        if( ErrorCode == XCP_CMD_PENDING )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending = TRUE;
        }
        else
        {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to update the MTA for the xcp channel
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  AddressExtension  address extension value 
*   @param[in]  Address  MTA address value
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_SetMta(Xcp_ChannelType XcpChannel,uint8 AddressExtension, Xcp_AddressPtrType Address )
{
    Xcp_ChannelCtrlStatus[XcpChannel].MTAExtension = AddressExtension;
    Xcp_ChannelCtrlStatus[XcpChannel].MTA = Xcp_ApplGetAddrPointer(XcpChannel,AddressExtension,Address);
}
/********************************************************************************************************************
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
)
{
    uint8 RetVal;
    #if (XCP_READ_PROTECTION == STD_ON)
    if (XCP_ERR_ACCESS_DENIED == Xcp_ApplGetReadAccess(XcpChannel,Xcp_ChannelCtrlStatus[XcpChannel].MTA,DataSize))
    {
        RetVal = XCP_ERR_ACCESS_DENIED;
    }
    else
    #endif
    {
        /* Read data */
        RetVal = Xcp_ApplMeasurementRead( Data, Xcp_ChannelCtrlStatus[XcpChannel].MTA, DataSize );
        /* Update the MTA value to point nex address with AG  */
        Xcp_ChannelCtrlStatus[XcpChannel].MTA +=  DataSize;
    }
    return RetVal;
}
#define XCP_STOP_SEC_CODE
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
*  @date    30-Apr-2024
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/
