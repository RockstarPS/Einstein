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
*   @file Xcp_PagCmd.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of PAGE SWITCHING COMMANDS (PAG) commands of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_PagCmd.h"
#include "Xcp_Internal.h"
/********************************************************************************************************************
*  #! Feature validation check                                                                                      *
********************************************************************************************************************/
/********************************************************************************************************************
*  #! PRIVATE MACRO DEFINITIONS                                                                                     *
********************************************************************************************************************/

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
*   @brief      This service is used to process the PAG command set cal page 0xEB request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorSetCalPage
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode;
    ErrorCode = Xcp_ApplSetCalPage(XcpChannel,CmdPtr[1],CmdPtr[2],CmdPtr[3]);
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
*   @brief      This service is used to process the PAG command get cal page 0xEA request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorGetCalPage
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode=XCP_CMD_OK;
    /* check for valid mode */
    if ((CmdPtr[1] == 0x01U) || (CmdPtr[1] == 0x02U))
    {
        /* update reserved byte */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
        /* udpate cal page */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = Xcp_ApplGetCalPage(XcpChannel,CmdPtr[1],CmdPtr[2]);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 3U;
    }
    else
    {
        ErrorCode = XCP_ERR_PAGE_MODE_NOT_VALID;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command get page processor info 0xE9 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorGetPageProcessorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* update page processor info */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = XCP_MAX_SEGMENT;
    # if( XCP_PAGE_FREEZE == STD_ON )
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0x01U;
    #else
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0x00U;
    #endif
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 2U;
    XCP_DUMMY_STATEMENT(XcpChannel);
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command get segment info 0xE8 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorGetSegmentInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint32 Address=0U;
    uint32 Length=0U;
    uint8 ErrorCode=XCP_CMD_OK;
    Xcp_PageStandardInfoType PageStandardInfo = {0};
    Xcp_PageAddressMappinInfoType PageAddressMappinInfo = {0};
    /* check for valid segment */
    if ((XCP_MAX_SEGMENT <= CmdPtr[2]) || (3U <= CmdPtr[1]))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else if (((CmdPtr[1] == 0U) && (2U <= CmdPtr[3])) ||
            ((CmdPtr[1] == 2U) && (3U <= CmdPtr[3])))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        if (CmdPtr[1] == 0U) /* get basic address info */
        {
            /* update reserved bytes */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
            /* Get Segment Basic Info */
            Xcp_ApplGetSegmentBasicInfo(XcpChannel,CmdPtr[2],CmdPtr[3],&Address,&Length);
            if (CmdPtr[3] == 0U) /* 0 = address */
            {
                /* update address */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)Address;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Address >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(Address >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(Address >> 24U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 8u;
            }
            else /* CmdPtr[3] 1 = length */
            {
                /* update length */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)Length;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Length >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(Length >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(Length >> 24U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 8u;
            }

        }
        else if (CmdPtr[1] == 1U) /* get standard info */
        {
            Xcp_ApplGetSegmentStandardInfo(XcpChannel,CmdPtr[2],&PageStandardInfo);
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = PageStandardInfo.MaxPages;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = PageStandardInfo.AddressExtension;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = PageStandardInfo.NumOfAddrRangeMapping;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = PageStandardInfo.CompressionMethod;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = PageStandardInfo.EncryptionMethod;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 5U;
        }
        else /* get address mapping info */
        {
            /* update reserved bytes */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
            /* Get Segment Basic Info */
            Xcp_ApplGetSegmentAddressMappingInfo(XcpChannel,CmdPtr[2],CmdPtr[3],CmdPtr[4],&PageAddressMappinInfo);
            if (CmdPtr[3] == 0U) /* 0 = source address */
            {
                /* update source address */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)PageAddressMappinInfo.SourceAddress;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(PageAddressMappinInfo.SourceAddress >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(PageAddressMappinInfo.SourceAddress >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(PageAddressMappinInfo.SourceAddress >> 24U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 8u;
            }
            else if (CmdPtr[3] == 1U) /* 1 = destination address */
            {
                /* update destination address */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)PageAddressMappinInfo.DestinationAddress;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(PageAddressMappinInfo.DestinationAddress >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(PageAddressMappinInfo.DestinationAddress >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(PageAddressMappinInfo.DestinationAddress >> 24U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 8u;
            }
            else 
            {
                /* CmdPtr[3]  2 = length address */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)PageAddressMappinInfo.Length;
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(PageAddressMappinInfo.Length >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(PageAddressMappinInfo.Length >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(PageAddressMappinInfo.Length >> 24U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 8u;
            }
        }
    }

    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command get page info 0xE7 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorGetPageInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 PageProperty=0U;
    uint8 PageInitSegment=0U;
    uint8 ErrorCode=XCP_CMD_OK;

    if ((XCP_MAX_SEGMENT <= CmdPtr[2]) || (XCP_MAX_PAGE <= CmdPtr[3]))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* update page property and Init segment */
        Xcp_ApplGetPageInfo(XcpChannel,CmdPtr[2],CmdPtr[3],&PageProperty,&PageInitSegment);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = PageProperty;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = PageInitSegment;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 2U;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command set segment info 0xE6 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorSetSegmentMode
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode=XCP_CMD_OK;
    if ((XCP_MAX_SEGMENT <= CmdPtr[1]) || (0U != (CmdPtr[2] & 0xFE)))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* set segment mode */
        Xcp_ApplSetSegmentMode(XcpChannel,CmdPtr[1],CmdPtr[2]);
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
            Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command get segmnet mode 0xE5 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorGetSegmentMode
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode=XCP_CMD_OK;
    if ((XCP_MAX_SEGMENT <= CmdPtr[2]))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* Get segment mode and update response */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U; /* reserved byte */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = Xcp_ApplGetSegmentMode(XcpChannel,CmdPtr[2]);
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 2U;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the PAG command 0xe4 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PagCmdProcessorCopyCalPage
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode=XCP_CMD_OK;
    if ((XCP_MAX_SEGMENT <= CmdPtr[1])||(XCP_MAX_SEGMENT <= CmdPtr[3]) ||
        (XCP_MAX_PAGE <= CmdPtr[2])||(XCP_MAX_PAGE <= CmdPtr[4]))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* request cal page copy */
        ErrorCode = Xcp_ApplCopyCalPage(XcpChannel,CmdPtr[1],CmdPtr[2],CmdPtr[3],CmdPtr[4]);
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
