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
*   @file Xcp_PgmCmd.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of program commands of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_PgmCmd.h"
#include "Xcp_Internal.h"
/********************************************************************************************************************
*  #! Feature validation check                                                                                      *
********************************************************************************************************************/
/********************************************************************************************************************
*  #! PRIVATE MACRO DEFINITIONS                                                                                     *
********************************************************************************************************************/

/*! @brief Defines the program mode bit mask for absolute mode */
#define XCP_PGM_ABSOLUTE_MODE_BIT               0x01U
/*! @brief Defines the program mode bit mask for functional mode */
#define XCP_PGM_FUNCTIONAL_MODE_BIT             0x02U
/*! @brief Defines the program mode bit mask for compression support */
#define XCP_PGM_COMPRESSION_SUPPORTED_BIT       0x04U
/*! @brief Defines the program mode bit mask for compression required */
#define XCP_PGM_COMPRESSION_REQUIRED_BIT        0x08U
/*! @brief Defines the program mode bit mask for encryption support */
#define XCP_PGM_ENCRYPTION_SUPPORTED_BIT        0x10U
/*! @brief Defines the program mode bit mask for encryption required */
#define XCP_PGM_ENCRYPTION_REQUIRED_BIT         0x20U
/*! @brief Defines the program mode bit mask for non sequence support */
#define XCP_PGM_NON_SEQ_PGM_SUPPORTED_BIT       0x40U
/*! @brief Defines the program mode bit mask for non sequence required */
#define XCP_PGM_NON_SEQ_PGM_REQUIRED_BIT        0x80U

/*! @brief Defines the maximum program size supported for this channel */
#define XCP_CRO_PROGRAM_MAX_SIZE(Ch)        ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 2u))
/*! @brief Defines the maximum block size suppoerted for this channel */
#define XCP_GET_MAX_BS_PGM(Ch)              ((uint8)((254u / XCP_CRO_PROGRAM_MAX_SIZE((Ch))) + (uint8)1u))
/*! @brief Defines the maximum program size suppoerted for program max cmd request for this channel */
#define XCP_CRO_PROGRAM_MAX_MAX_SIZE(Ch)    ((uint8)(Xcp_ChannelCtrlStatus[(Ch)].MaxCto - 1u))

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
*   @brief      This service is used to process the program command program start 0xD2 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramStart
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_CMD_OK;
    /* Add protection check */
    /* update response buffer */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U; /* reserved byte */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U; /* Initialize the COMM_MODE */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = Xcp_ChannelCtrlStatus[XcpChannel].MaxCto; 
# if( XCP_BLOCK_UPLOAD == STD_ON )
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] |= XCP_CMB_SLAVE_BLOCK_MODE; /* update the COMM_MODE */
# endif
# if( XCP_BLOCK_DOWNLOAD == STD_ON )
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] |= XCP_CMO_MASTER_BLOCK_MODE; /* update the COMM_MODE */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] =  XCP_GET_MAX_BS_PGM(XcpChannel);
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] =  XCP_GET_MIN_ST_PGM(XcpChannel);
# else
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] =  0U;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] =  0U;
# endif
    /* Interleaved mode not supported */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] =  0U; 
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 6U;
    /* notify appl about request */
    ErrorCode = Xcp_ApplProgramStart();
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
*   @brief      This service is used to process the program command program clear 0xD1 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramClear
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint32 Size;
    uint8 ErrorCode = XCP_CMD_OK;

    Size = (((uint32 )CmdPtr[4]) |
            (((uint32)CmdPtr[5]) << 8u) | 
            (((uint32)CmdPtr[6]) << 16u) |
            (((uint32)CmdPtr[7]) << 24u));
    
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_PGM) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    # if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
    if (Xcp_ApplProgramWriteAccessCheck(Xcp_ChannelCtrlStatus[XcpChannel].MTA,Size) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    if (CmdPtr[1] == 0U) 
    {
        /* the absolute access mode only supported */
        ErrorCode = Xcp_ApplProgramClear((uint8 *)&Xcp_ChannelCtrlStatus[XcpChannel].MTA,Size);
    }
    else
    {
        ErrorCode = XCP_ERR_CMD_SYNTAX;
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
*   @brief      This service is used to process the program command program 0xD0 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgram
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Size;
    uint8 ErrorCode = XCP_CMD_OK;

    Size = CmdPtr[1];

    #if( XCP_BLOCK_DOWNLOAD == STD_ON )
    if (Size > XCP_CRO_PROGRAM_MAX_SIZE(XcpChannel))
    {
        Size =  XCP_CRO_PROGRAM_MAX_SIZE(XcpChannel);
    }
    Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize = CmdPtr[1] - Size;
    #else
    if (Size > XCP_CRO_PROGRAM_MAX_SIZE(XcpChannel))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    #endif
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_PGM) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    # if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
    if (Xcp_ApplProgramWriteAccessCheck(Xcp_ChannelCtrlStatus[XcpChannel].MTA,Size) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    {
        /* program request */
        ErrorCode = Xcp_ApplProgram((uint8 *)&CmdPtr[2],(uint8 *)Xcp_ChannelCtrlStatus[XcpChannel].MTA,Size);
        Xcp_ChannelCtrlStatus[XcpChannel].MTA+=Size;
    }

# if( XCP_BLOCK_DOWNLOAD == STD_ON )
    if( Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize > 0u )
    {
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 0u;
    }
# endif
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
*   @brief      This service is used to process the program command program reset 0xCF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramReset
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* Disconnect xcp connection */
    Xcp_Disconnect(XcpChannel);
    /* Notify appl to reset */
    Xcp_ApplReset(XcpChannel);
    /* Dont send response */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 0U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the program command processor info 0xCE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorGetPgmProcessorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* only abosule mode supported. Compression, Encryption and Non seq pgm not supported */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = XCP_PGM_ABSOLUTE_MODE_BIT;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = XCP_MAX_NUMBER_OF_SECTOR ;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 2U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the program command get sector info 0xCD request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorGetSectorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_CMD_OK;
    uint8 Sector;
    uint8 Mode;
    /* get sector and mode */
    Sector = CmdPtr[2];
    Mode = CmdPtr[1];
    if(XCP_MAX_PGM_SECTOR <= Sector)
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        if (Mode == 2U) /* get name length of this SECTOR */
        {
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = Xcp_PgmSectorNameLength[Sector];
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen +=1U;
            /* update the mta */
            Xcp_SetMta(XcpChannel,0x00U,Xcp_PgmSectorAddress[Sector]);            
        }
        else  
        {
            /* update response */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0x00U; /* clear seq num */
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0x00U; /* Program Sequence Number*/
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0x00U; /* Programming method */
            if (Mode == 0U)
            {
                /* update address */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorStartAddress);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorStartAddress >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorStartAddress >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorStartAddress >> 24U);
            }
            else
            {
                /* update length */
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorLength);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorLength >> 8U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorLength >> 16U);
                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(Xcp_PgmSectorConfig[Sector].SectorLength >> 24U);
            }
            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the program command program prepare 0xCC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramPrepare
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint16 Size;
    uint8 ErrorCode;

    Size = ((uint16)CmdPtr[2] | (((uint16)CmdPtr[3]) << 8U));

    ErrorCode = Xcp_ApplProgramPrepare(XcpChannel,(uint8 *)Xcp_ChannelCtrlStatus[XcpChannel].MTA,Size);

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
*   @brief      This service is used to process the program command program next 0xCA request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramNext
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* process program request if received size is the excepted next block size else send XCP_ERR_SEQUENCE */
    if (Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize == CmdPtr[1])
    {
        Xcp_PgmCmdProcessorProgram(XcpChannel,CmdPtr);
    }
    else
    {
        /* send XCP_ERR_SEQUENCE  */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[0] = XCP_PID_ERR;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = XCP_ERR_SEQUENCE;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 3U;
    }
}
/*******************************************************************************************************************
*   @brief      This service is used to process the program command program max 0xC9 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_PgmCmdProcessorProgramMax
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_CMD_OK;
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_PGM) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    # if( XCP_PROGRAMMING_WRITE_PROTECTION == STD_ON )
    if (Xcp_ApplProgramWriteAccessCheck(Xcp_ChannelCtrlStatus[XcpChannel].MTA, 
        XCP_CRO_PROGRAM_MAX_MAX_SIZE(XcpChannel)) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    {
        ErrorCode = Xcp_ApplProgram((uint8 *)&CmdPtr[1],(uint8 *)Xcp_ChannelCtrlStatus[XcpChannel].MTA,
                                XCP_CRO_PROGRAM_MAX_MAX_SIZE(XcpChannel));
        Xcp_ChannelCtrlStatus[XcpChannel].MTA +=  XCP_CRO_PROGRAM_MAX_MAX_SIZE(XcpChannel);
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
