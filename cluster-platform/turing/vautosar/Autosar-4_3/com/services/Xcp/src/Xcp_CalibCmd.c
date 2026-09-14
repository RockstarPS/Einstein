
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
*   @file Xcp_CalibCmd.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of calibration commands of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_CalibCmd.h"
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
/*! @brief Defines the macro to get the next download max size */
#define XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(Ch)     ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 2u))
/*! @brief Defines the macro to get the download max cmd max size */
#define XCP_CRO_DOWNLOAD_MAX_MAX_SIZE(Ch)      ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 1u))
/*! @brief Defines the macro to get the short download max size */
#define XCP_CRM_SHORT_DOWNLOAD_MAX_SIZE(Ch)    ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 8u))
/*! @brief Defines the max left shift from modify bits command */
#define XCP_UPPER_LIMIT_LEFT_SHIFT             (31u)

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
*   @brief      This service is used to process the Calibration command download 0xF0 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Size;
    uint8 ErrorCode = XCP_CMD_OK;
    
    Size = CmdPtr[1];
    
    # if( XCP_BLOCK_DOWNLOAD == STD_OFF )
    if ((Size == 0U) || (Size > Xcp_ChannelConfig[XcpChannel].DownloadSizeMax))
    #else
    if (Size == 0U) 
    #endif
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    #if (XCP_SEED_KEY == STD_ON)
    else if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_CAL_PAG) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    #endif
    else
    {   
        # if( XCP_BLOCK_DOWNLOAD == STD_ON )
        if (Size > Xcp_ChannelConfig[XcpChannel].DownloadSizeMax)
        {
            /* handle block mode */
            Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = Size - Xcp_ChannelConfig[XcpChannel].DownloadSizeMax;
            Size =  Xcp_ChannelConfig[XcpChannel].DownloadSizeMax;
            ErrorCode = Xcp_WriteMta(XcpChannel,Size,&CmdPtr[2]);
            /* Donot send response for block mode request */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 0U;
        }
        else
        #endif
        {
            ErrorCode = Xcp_WriteMta(XcpChannel,Size,&CmdPtr[2]);
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
*   @brief      This service is used to process the Calibration command download next 0xEF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownloadNext
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Size;
    uint8 ErrorCode = XCP_CMD_OK;
    
    Size = CmdPtr[1];

    if (Size > (XCP_MAX_DOWNLOAD_BYTES - XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XcpChannel)))
    {
        /* if requested size is greater than supported size then return XCP_ERR_OUT_OF_RANGE */
        Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = 0U;
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else if (Size != Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize)
    {
        /* if requested size is not equal to next block size , return XCP_ERR_SEQUENCE */
        Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_SEQUENCE);
        /* update the next block size supported */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2U] = Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 1U;
    }
    else
    {
        if (Size <= XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XcpChannel))
        {
            /* write the last bytes of the block download */
            Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = 0U;
            ErrorCode = Xcp_WriteMta(XcpChannel,Size,&CmdPtr[2U]);
        }
        else
        {
            /* more pending bytes to receive, so copy the current recieved data and do not sent response  */
            Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = Size - XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XcpChannel);
            Size = XCP_CRO_DOWNLOAD_NEXT_MAX_SIZE(XcpChannel);
            ErrorCode = Xcp_WriteMta(XcpChannel,Size,&CmdPtr[2]);
            /* Donot send response for block mode request */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 0U;
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
*   @brief      This service is used to process the Calibration command download max 0xEE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorDownloadMax
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode;
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_CAL_PAG) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    {
        ErrorCode = Xcp_WriteMta(XcpChannel, (XCP_CRO_DOWNLOAD_MAX_MAX_SIZE(XcpChannel)),&CmdPtr[1U]);
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
*   @brief      This service is used to process the Calibration command short download 0xED request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorShortDownload
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    Xcp_AddressPtrType Address;
    uint8 ErrorCode = XCP_ERR_CMD_UNKNOWN;

    Address = (((Xcp_AddressPtrType )CmdPtr[4]) |
                (((Xcp_AddressPtrType )CmdPtr[5]) << 8u) | 
                (((Xcp_AddressPtrType )CmdPtr[6]) << 16u) |
                (((Xcp_AddressPtrType )CmdPtr[7]) << 24u));

    if ((CmdPtr[1] == 0U) || 
        (CmdPtr[1] > XCP_CRM_SHORT_DOWNLOAD_MAX_SIZE(XcpChannel)))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    #if (XCP_SEED_KEY == STD_ON)
    else if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_CAL_PAG) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    #endif
    else
    {
        Xcp_SetMta(XcpChannel,CmdPtr[3],Address);
        ErrorCode = Xcp_WriteMta(XcpChannel,CmdPtr[1],&CmdPtr[8U]);
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
*   @brief      This service is used to process the Calibration command modify bits 0xEC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_CalibCmdProcessorModifyBits
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint32 Data=0U;
    uint8 ShiftValue;
    uint16  MaskAndValue;
    uint16  MaskXorValue;
    Xcp_AddressPtrType MtaVal;
    uint8 ErrorCode = XCP_ERR_CMD_UNKNOWN;

    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_CAL_PAG) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    {
        ShiftValue = CmdPtr[1];
        if (ShiftValue <= XCP_UPPER_LIMIT_LEFT_SHIFT)
        {
            /* get xor and xand value */
            MaskAndValue = (((uint16)CmdPtr[2]) | (((uint16)CmdPtr[3]) << 8U));
            MaskXorValue = (((uint16)CmdPtr[4]) | (((uint16)CmdPtr[5]) << 8U));
            /* get and update MTA location */
            MtaVal = Xcp_ChannelCtrlStatus[XcpChannel].MTA;
            ErrorCode = Xcp_ReadMta(XcpChannel,4U,(uint8 *)&Data);
            Xcp_ChannelCtrlStatus[XcpChannel].MTA=MtaVal;
            /* perform masking and update the data */
            if (ErrorCode == XCP_CMD_OK)
            {
                Data = (uint32)((Data & (~((uint32)(((uint16)~MaskAndValue) << ShiftValue)))) ^
                                ((uint32)(MaskXorValue << ShiftValue)));
                ErrorCode = Xcp_WriteMta(XcpChannel,4U,(uint8 *)&Data);
                Xcp_ChannelCtrlStatus[XcpChannel].MTA=MtaVal;
            }
            else
            {
                /* update access denied */
                if (ErrorCode == XCP_CMD_PENDING)
                {
                    ErrorCode = XCP_ERR_ACCESS_DENIED;
                }
            }
        } 
        else
        {
            ErrorCode = XCP_ERR_OUT_OF_RANGE;
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
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
)
{
    uint8 RetVal;
    RetVal = Xcp_ApplCalibrationWrite(Xcp_ChannelCtrlStatus[XcpChannel].MTA, pDataBuffer, Size );
    Xcp_ChannelCtrlStatus[XcpChannel].MTA += Size;
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
