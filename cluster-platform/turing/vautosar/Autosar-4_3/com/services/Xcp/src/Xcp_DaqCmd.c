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
*   @file Xcp_DaqCmd.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of DAQ commands of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_CalibCmd.h"
#include "Xcp_DaqCmd.h"
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
/*! @brief Defines the max odt entry size for the channel */
#define XCP_MAX_ODT_ENTRY_SIZE(Ch)                  (Xcp_ChannelCtrlStatus[(Ch)].MaxDto - 1u)


/*! @brief Defines the start stop daq mode as stop */
#define XCP_DAQ_START_STOP_DAQ_LIST_MODE_STOP       0x00U
/*! @brief Defines the start stop daq mode as start */
#define XCP_DAQ_START_STOP_DAQ_LIST_MODE_START      0x01U
/*! @brief Defines the start stop daq mode as select */
#define XCP_DAQ_START_STOP_DAQ_LIST_MODE_SELECT     0x02U

/*! @brief Defines the start stop sync daq mode as stop all */
#define XCP_DAQ_START_STOP_SYNCH_STOP_ALL           0x00U
/*! @brief Defines the start stop sync daq mode as start */
#define XCP_DAQ_START_STOP_SYNCH_START_SELECTED     0x01U
/*! @brief Defines the start stop sync daq mode as stop selected */
#define XCP_DAQ_START_STOP_SYNCH_STOP_SELECTED      0x02U

/*! @brief Defines the overload flags as No overload indication */
#define XCP_DAQ_NO_OVERLOAD_INDICATION                  ((uint8)(0x00U << 6U))
/*! @brief Defines the overload flags as overload indication in MSB of PID */
#define XCP_DAQ_OVERLOAD_INDICATION_IN_MSB_OF_PID       ((uint8)(0x01U << 6U))
/*! @brief Defines the overload flags as overload indication by Event Packet */
#define XCP_DAQ_OVERLOAD_INDICATION_BY_EVENT_PACKET     ((uint8)(0x02U << 6U))
/*! @brief Defines the overload flags as not allowed */
#define XCP_DAQ_OVERLOAD_INDICATION_NOT_ALLOWED         ((uint8)(0x03U << 6U))

#if (XCP_DAQ_CONFIG_TYPE == DAQ_STATIC)
/*! @brief Defines the bit mask for DAQ property config type */
#define XCP_DAQ_PROPERTY_CONFIG_TYPE    0X00U
#else
#define XCP_DAQ_PROPERTY_CONFIG_TYPE    0X01U
#endif

/*! @brief Defines the bit mask for DAQ property presaclar */
#define XCP_DAQ_PROPERTY_PRESCALER      0X02U
/*! @brief Defines the bit mask for DAQ property resume */
# if( XCP_DAQ_RESUME == STD_ON )
#define XCP_DAQ_PROPERTY_RESUME         0X04U
#else
#define XCP_DAQ_PROPERTY_RESUME         0X00U
#endif
/*! @brief Defines the bit mask for DAQ property STIM */
#define XCP_DAQ_PROPERTY_STIM           0X08U
/*! @brief Defines the bit mask for DAQ property Timestamp */
# if( XCP_DAQ_TIMESTAMP_SIZE > 0u )
#define XCP_DAQ_PROPERTY_TIMESTAMP      0X10U
#else
#define XCP_DAQ_PROPERTY_TIMESTAMP      0X00U
#endif
/*! @brief Defines the bit mask for DAQ property PID OFF */
#define XCP_DAQ_PROPERTY_PID_OFF        0X20U
/*! @brief Defines the XCP DAQ properties */
#define XCP_DAQ_PROPERTY    (uint8)(XCP_DAQ_PROPERTY_CONFIG_TYPE | XCP_DAQ_PROPERTY_TIMESTAMP | \
                    XCP_DAQ_PROPERTY_PRESCALER | XCP_DAQ_PROPERTY_RESUME | XCP_DAQ_OVERLOAD_INDICATION_IN_MSB_OF_PID)

/*! @brief Defines the bit mask for the id field type as absolute ODT number */
#define XCP_DAQ_HDR_PID                         (0u)
/*! @brief Defines the bit mask for the id field type as relative ODT number , absolute DAQ list number byte */
#define XCP_DAQ_HDR_ODT_DAQB                    (1u<<6)
/*! @brief Defines the bit mask for the id field type as relative ODT number , absolute DAQ list number word */
#define XCP_DAQ_HDR_ODT_DAQW                    (2u<<6)
/*! @brief Defines the bit mask for the id field type as relative ODT number , absolute DAQ list number word ,aligned */
#define XCP_DAQ_HDR_ODT_FIL_DAQW                (3u<<6)

/*! @brief Defines the timestamp size for DAQ */
#define XCP_DAQ_RES_TIMESTAMP_SIZE                  (0x07u)
/*! @brief Defines the timestamp bit mask value */
#  if( XCP_DAQ_TIMESTAMP_FIXED == STD_ON )
#define XCP_DAQ_RES_TIMESTAMP_FIXED                 (0x08u)
#else
#define XCP_DAQ_RES_TIMESTAMP_FIXED                 (0x00U)
#endif

/*! @brief Defines the macro for getting the multiple daq write bit offset  */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_BITOFFSET(i)     (2u + (8u*(i))) 
/*! @brief Defines the macro for getting the multiple daq write size  */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_SIZE(i)          (3u + (8u*(i))) 
/*! @brief Defines the macro for getting the multiple daq write extension */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_EXT(i)           (8u + (8u*(i))) 
/*! @brief Defines the macro for getting the multiple daq write address  */
#define XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(i)          (4u + (2u*((i)*4u)))

/********************************************************************************************************************
*  #! PRIVATE TYPE DECLARATION                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  #! PRIVATE FUNCTION PROTOTYPES                                                                                   *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service is used to process the allocation of stim memory.
*   @param[in]  XcpChannel  Channel Id type
*   @return returns the error code for the request.
********************************************************************************************************************/
XCP_LOCAL FUNC(uint8, XCP_CODE) Xcp_DaqAllocStimMemory( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief      This service is used to process the request to stop all selected DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStopAllSelectedDaq(Xcp_ChannelType XcpChannel);
/*!******************************************************************************************************************
*   @brief      This service is used to process the request to start DAQ .
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  DaqNumber  DAQ number to be started
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStartDaq(Xcp_ChannelType XcpChannel, uint16 DaqNumber);
/*!******************************************************************************************************************
*   @brief      This service is used to process the request to stop DAQ .
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  DaqNumber  DAQ number to be stoppped
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStopDaq(Xcp_ChannelType XcpChannel, uint16 DaqNumber);
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
*   @brief      This service is used to process the DAQ command set DAQ ptr 0xE2 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorSetDaqPtr
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 OdtNum;
    uint16 DaqNum=0U;
    uint8 OdtEntryNum;
    uint8 ErrorCode = XCP_CMD_OK; 
    /* Get daq values */
    DaqNum = (uint16)CmdPtr[2];
    DaqNum |= ((uint16)CmdPtr[2])<<8U;
    OdtNum = CmdPtr[4];
    OdtEntryNum = CmdPtr[5];

    if ((DaqNum >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists) ||
        (OdtNum >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts) ||
        (OdtEntryNum >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries) ||
        (DaqNum >= XCP_MAX_DAQ ))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        OdtNum = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqNum] + OdtNum ;
        if (OdtNum < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))
        {
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx = 
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[OdtNum] + OdtEntryNum;
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
*   @brief      This service is used to process the DAQ command write DAQ 0xE1 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorWriteDaq
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 BitOffset;
    uint8 DaqElemSize;
    uint8 DaqElemAddrExt;
    uint8 ErrorCode = XCP_CMD_OK;
    Xcp_AddressPtrType DaqElemAddr;
    Xcp_AddressPtrType DaqElemAddrWitExt;
    Xcp_OdtEntryIdxType ActiveOdtEntryIdx;
    /* get daq data */
    BitOffset = CmdPtr[1];
    DaqElemSize = CmdPtr[2];
    DaqElemAddrExt = CmdPtr[3];
    DaqElemAddr = (((uint32)CmdPtr[4]) | (((uint32)CmdPtr[5]) << 8U) | 
                 (((uint32)CmdPtr[6]) << 16U) |  (((uint32)CmdPtr[7]) << 24U));
    /* get transformed address */
    DaqElemAddrWitExt  = Xcp_ApplGetAddrPointer(XcpChannel,DaqElemAddrExt,DaqElemAddr); 
    
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries == 0U))
    {
        ErrorCode = XCP_ERR_DAQ_CONFIG;
    }
    #if (XCP_SEED_KEY == STD_ON)
    else if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_DAQ) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    #endif
    #if (XCP_READ_PROTECTION == STD_ON)
    else if (XCP_ERR_ACCESS_DENIED == Xcp_ApplGetReadAccess(XcpChannel,DaqElemAddrWitExt,DaqElemSize))
    {
        ErrorCode = XCP_ERR_ACCESS_DENIED;
    }
    #endif
    else if ((BitOffset != 0xFFu ) ||
             (DaqElemSize == 0U) || 
             (DaqElemSize > XCP_MAX_ODT_ENTRY_SIZE(XcpChannel)))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx >= XCP_MAX_ODT_ENTRIES)
    {
        ErrorCode = XCP_ERR_DAQ_CONFIG;
    }
    else
    {
        ActiveOdtEntryIdx = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntries[ActiveOdtEntryIdx] = DaqElemAddrWitExt;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[ActiveOdtEntryIdx] = DaqElemSize;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx = (ActiveOdtEntryIdx+ 1U);
           
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command set daq list mode 0xE0 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorSetDaqListMode
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Mode;
    uint8 PreScalar;
    uint16 DaqNumber;
    uint16 EventNumber;
    uint8 ErrorCode = XCP_CMD_OK;
    /* get daq values */
    DaqNumber = ((uint16)CmdPtr[2] | (((uint16)CmdPtr[3]) << 8U));
    EventNumber = ((uint16)CmdPtr[4] | (((uint16)CmdPtr[5]) << 8U)); 
    PreScalar = CmdPtr[6];
    Mode = CmdPtr[7];

    if ((DaqNumber >= XCP_MAX_DAQ) ||
        (EventNumber >= XCP_MAX_EVENT) || 
        (CmdPtr[7] > 0U ))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    #if( XCP_DAQ_TIMESTAMP_SIZE == 0 )
    else if ((Mode & XCP_DAQ_LIST_TIMESTAMP) > 0U)
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    #endif
    #if( XCP_DAQ_TIMESTAMP_FIXED == STD_ON )
    else if ((Mode & XCP_DAQ_LIST_TIMESTAMP) == 0U)
    {
        ErrorCode = XCP_ERR_CMD_SYNTAX;
    }
    #endif
    #if( XCP_STIM == STD_OFF )
    else if((Mode & XCP_DAQ_LIST_DIRECTION) > 0u ) 
    {
        ErrorCode = XCP_ERR_MODE_NOT_VALID;
    }
    #endif
    else
    {
        if (PreScalar == 0U)
        {
            PreScalar = 1U;
        }
        /* update daq status */
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqNumber] = Mode;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqToEventChannelMap[DaqNumber] = EventNumber;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListPrescalarInitialValue[DaqNumber] = PreScalar;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListPrescalarCounter[DaqNumber] = PreScalar;
        /* allocate stim buffers */
        #if (XCP_STIM == STD_ON)
        ErrorCode = Xcp_DaqAllocStimMemory(XcpChannel);
        #endif
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
         Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command get daq list mode 0xDF request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorGetDaqListMode
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint16 DaqNumber;
    uint8 ErrorCode = XCP_CMD_OK;
    DaqNumber = ((uint16)CmdPtr[2] | (((uint16)CmdPtr[3]) << 8U));
    /* Check for valid range */
    if (DaqNumber >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists)
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* update mode */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqNumber];
        /* reserved */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
        /* update event channel mapping */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqToEventChannelMap[DaqNumber];
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqToEventChannelMap[DaqNumber] >> 8U);
        /* update prescalar */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListPrescalarInitialValue[DaqNumber];
        /* update priority */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = 0U;
        /* update length */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command start stop daq list 0xDE request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorStartStopDaqList
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Mode;
    uint16 DaqNumber;
    uint8 ErrorCode = XCP_CMD_OK;
    
    DaqNumber = ((uint16)CmdPtr[2] | (((uint16)CmdPtr[3]) << 8U));
    Mode = CmdPtr[1];
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_DAQ) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    if ((DaqNumber >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists) ||
        (Mode > XCP_DAQ_START_STOP_DAQ_LIST_MODE_SELECT))
    {
        /* Check for valid range */
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        if ((Mode == XCP_DAQ_START_STOP_DAQ_LIST_MODE_START) || (Mode == XCP_DAQ_START_STOP_DAQ_LIST_MODE_SELECT))
        {
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqNumber] |= XCP_DAQ_FLAG_SELECTED;
            if (Mode == XCP_DAQ_START_STOP_DAQ_LIST_MODE_START)
            {
                Xcp_DaqCmdStartDaq(XcpChannel,DaqNumber);
            }
        }
        else
        {
            Xcp_DaqCmdStopDaq(XcpChannel,DaqNumber);
        }
        /* upadate response */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqNumber];
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 1U;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command start stop synch 0xDD request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorStartStopSynch
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 Mode;
    uint8 ErrorCode = XCP_CMD_OK;
    /* update mode */
    Mode = CmdPtr[1];
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries == 0U))
    {
        ErrorCode = XCP_ERR_DAQ_CONFIG;
    }
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_DAQ) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    #endif
    else if (Mode > XCP_DAQ_START_STOP_SYNCH_STOP_SELECTED)
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        if (Mode == XCP_DAQ_START_STOP_SYNCH_START_SELECTED)
        {
            Xcp_DaqCmdStartAllSelectedDaq(XcpChannel);
        }
        else if (Mode == XCP_DAQ_START_STOP_SYNCH_STOP_SELECTED)
        {
            Xcp_DaqCmdStopAllSelectedDaq(XcpChannel);
        }
        else
        {
            Xcp_DaqCmdStopAllDaq(XcpChannel);
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command get daq clock 0xDC request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorGetDaqClock
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint32 TimeStamp=0U;
    /* Get timestamp value */
    TimeStamp = Xcp_ApplGetTimeStamp();
    /* update response buffer */
    /*Reserved bytes */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 0U;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = 0U;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 0U;
    /* timestamp value */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)TimeStamp;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(TimeStamp >> 8U);
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)(TimeStamp >> 16U);
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(TimeStamp >> 24U);
    /* update response length */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command get daq processor info 0xDA request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorGetDaqProcessorInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* update response buffer */
    /* DAQ_PROPERTIES */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = XCP_DAQ_PROPERTY;
    /* MAX_DAQ */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = (uint8)Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = (uint8)(Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists >> 8U);
    /* MAX_EVENT_CHANNEL */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = (uint8)XCP_MAX_EVENT;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(XCP_MAX_EVENT >> 8U);
    /* MIN_DAQ */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = 0U; 
    /* DAQ_KEY_BYTE */
    #if (XCP_DAQ_HDR_LEN == 1u)
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = XCP_DAQ_HDR_PID;
    #else
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = XCP_DAQ_HDR_ODT_DAQB;
    #endif
    /* update response length */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command get DAQ resolution info 0xD9 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorGetDaqResolutionInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    /* update reponse */
    /* GRANULARITY_ODT_ENTRY_SIZE_DAQ */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = 1U;
    /* MAX_ODT_ENTRY_SIZE_DAQ */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = XCP_MAX_ODT_ENTRY_SIZE(XcpChannel);
    /* GRANULARITY_ODT_ENTRY_SIZE_STIM    */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = 1U;
    /* MAX_ODT_ENTRY_SIZE_STIM    */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = XCP_MAX_ODT_ENTRY_SIZE(XcpChannel);
    #if ( XCP_DAQ_TIMESTAMP_SIZE > 0u )
    /* TIMESTAMP_MODE    */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = XCP_DAQ_TIMESTAMP_UNIT | sizeof(Xcp_TimestampType) | XCP_DAQ_RES_TIMESTAMP_FIXED;
    /* TIMESTAMP_TICKS    */
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = (uint8)XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = (uint8)(XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT >> 8U);
    #else
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = 0U; 
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = 0U;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[7] = 0U;
    #endif
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 7U;
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command get DAQ event info 0xD7 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorGetDaqEventInfo
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint16 EventNumber=0U;
    uint8 ErrorCode = XCP_CMD_OK;

    EventNumber = (uint16)CmdPtr[0];
    EventNumber |= ((uint16)CmdPtr[0]) >> 8U;
    if (EventNumber >= XCP_MAX_EVENT)
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* update response */
        /* DAQ_EVENT_PROPERTIES */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1] = Xcp_EventCtrlStatus[EventNumber].EventDirection;
        /* MAX_DAQ_LIST */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[2] = Xcp_EventCtrlStatus[EventNumber].EventNumOfDaq;
        /* EVENT_CHANNEL_NAME_LENGTH */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[3] = Xcp_EventCtrlStatus[EventNumber].EventNameLength;
        /* EVENT_CHANNEL_TIME_CYCLE */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[4] = Xcp_EventCtrlStatus[EventNumber].EventTimeCycle;
        /* EVENT_CHANNEL_TIME_UNIT */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[5] = (uint8)(Xcp_EventCtrlStatus[EventNumber].EventTimeUnit >> 4U);
        /* EVENT_CHANNEL_PRIORITY */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[6] = 0U;
        /* update length */
        Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 6U;
        /* udpate MTA */
        Xcp_ChannelCtrlStatus[XcpChannel].MTA =  Xcp_EventCtrlStatus[EventNumber].EventName;
        Xcp_ChannelCtrlStatus[XcpChannel].MTAExtension =  0x00U;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command free DAQ 0xD6 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorFreeDaq
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 ErrorCode = XCP_CMD_OK;
    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_DAQ) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    {
        /* notify appliation to close activities releated to Daq  */
        Xcp_ApplFreeDaq(XcpChannel);
        /* Reset the Daq */
        Xcp_UtilMemSet((uint8 *)&Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus,
                        0x00U,sizeof(Xcp_DaqListStatusType));
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command alloc daq 0xD5 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorAllocDaq
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint16 DaqCount;
    uint8 ErrorCode = XCP_CMD_OK;
    DaqCount = (((uint16)CmdPtr[2]) | (((uint16)CmdPtr[3]) << 8U));
    /* check for sequence error */
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts != 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries != 0U))
    {
        ErrorCode = XCP_ERR_SEQUENCE;
    }
    else if (DaqCount > XCP_MAX_DAQ)
    {
        ErrorCode = XCP_ERR_MEMORY_OVERFLOW;
    }
    else
    {
        /* update the daq count */
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists = DaqCount;
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command alloc ODT 0xD4 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorAllocOdt
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{   
    uint8 OdtCount;
    uint16 DaqNumber;
    uint8 ErrorCode = XCP_CMD_OK;

    /* get daq info */
    DaqNumber = (((uint16)CmdPtr[2]) | (((uint16)CmdPtr[3]) << 8U)); 
    OdtCount = CmdPtr[4];
    /* check for sequence error */
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries != 0U))
    {
        ErrorCode = XCP_ERR_SEQUENCE;
    }
    else if ((DaqNumber >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists) ||
            (DaqNumber >= XCP_MAX_DAQ))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* update odt values */
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqNumber] = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtsOfDaq[DaqNumber] = OdtCount;
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts += OdtCount;
        /* check for overflow */
        if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts > (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))
        {
            ErrorCode = XCP_ERR_MEMORY_OVERFLOW;
            Xcp_UtilMemSet((uint8 *)&Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus,0x00U,sizeof(Xcp_DaqListStatusType));
        }
    }
    /* check and udpate error reponse */
    if (ErrorCode != XCP_CMD_OK)
    {
        Xcp_SetNegativeResponse(XcpChannel,ErrorCode);
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the DAQ command alloc ODT entry 0xD3 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorAllocOdtEntry
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 OdtNumber;
    uint16 DaqNumber;
    uint8 OdtEntriesCount;
    Xcp_OdtIdxType OdtIdx;
    uint8 ErrorCode = XCP_CMD_OK; 

    /* get daq info */
    DaqNumber = (((uint16)CmdPtr[2]) | (((uint16)CmdPtr[3]) << 8U)); 
    OdtNumber = CmdPtr[4];
    OdtEntriesCount = CmdPtr[5];
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts == 0U))
    {
        ErrorCode = XCP_ERR_SEQUENCE;
    }
    else if ((DaqNumber >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists) ||
            (DaqNumber >= XCP_MAX_DAQ))
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else if (OdtNumber >= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtsOfDaq[DaqNumber])
    {
        ErrorCode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        OdtIdx =  Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqNumber]+OdtNumber;
        if (OdtIdx < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))
        {
            /* update odt entries count */
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[OdtIdx] = 
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries;
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[OdtIdx] = OdtEntriesCount;
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries += OdtEntriesCount; 
            /* check for overflow */
            if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries > XCP_MAX_ODT_ENTRIES)
            {
                ErrorCode = XCP_ERR_OUT_OF_RANGE;    
                Xcp_UtilMemSet((uint8 *)&Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus,0x00U,sizeof(Xcp_DaqListStatusType));
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
*   @brief      This service is used to process the DAQ command write DAQ multiple 0xC7 request.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  CmdPtr  pointer to the command buffer
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdProcessorWriteDaqMultiple
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    uint8 DaqIdx;
    uint8 BitOffset;
    uint8 DaqElemSize;
    uint8 DaqElemAddrExt;
    uint8 ErrorCode = XCP_CMD_OK;
    Xcp_AddressPtrType DaqElemAddr;
    Xcp_AddressPtrType DaqElemAddrWitExt;
    Xcp_OdtEntryIdxType ActiveOdtEntryIdx;

    #if (XCP_SEED_KEY == STD_ON)
    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RM_DAQ) != XCP_CMD_OK)
    {
        ErrorCode = XCP_ERR_ACCESS_LOCKED;
    }
    else
    #endif
    if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts == 0U) ||
        (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntries == 0U))
    {
        ErrorCode = XCP_ERR_DAQ_CONFIG;
    }
    else
    {
        /* iterate for all the daq count requested */
        for(DaqIdx = 0U; ((DaqIdx < CmdPtr[1]) && (ErrorCode == XCP_CMD_OK));DaqIdx++)
        {
            /* get info from request */
            DaqElemAddr = (uint32)CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(DaqIdx)];
            DaqElemAddr |= ((uint32)CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(DaqIdx)+1U]) << 8U;
            DaqElemAddr |= ((uint32)CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(DaqIdx)+2U]) << 16U;
            DaqElemAddr |= ((uint32)CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_ADDR(DaqIdx)+3U]) << 24U;
            DaqElemAddrExt = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_EXT(DaqIdx)];
            DaqElemSize = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_SIZE(DaqIdx)];
            BitOffset = CmdPtr[XCP_CRO_WRITE_DAQ_MULTIPLE_BITOFFSET(DaqIdx)];
            /* get address with extension */
            DaqElemAddrWitExt = Xcp_ApplGetAddrPointer(XcpChannel,DaqElemAddrExt,DaqElemAddr);
            /* check for valid input */
            if ((DaqElemSize == 0U) || 
                (DaqElemSize >= XCP_MAX_ODT_ENTRY_SIZE(XcpChannel)) ||
                (BitOffset != 0xFFU))
            {
                ErrorCode = XCP_ERR_OUT_OF_RANGE;
            }
            else if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx >= XCP_MAX_ODT_ENTRIES)
            {
                ErrorCode = XCP_ERR_DAQ_CONFIG;
            }
            #if (XCP_READ_PROTECTION == STD_ON)
            else if (XCP_ERR_ACCESS_DENIED == Xcp_ApplGetReadAccess(XcpChannel,DaqElemAddrWitExt,DaqElemSize))
            {
                ErrorCode = XCP_ERR_ACCESS_DENIED;
            }
            #endif
            else 
            {
                /* update odt entries */
                ActiveOdtEntryIdx = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx;
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntries[ActiveOdtEntryIdx] = DaqElemAddrWitExt;
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[ActiveOdtEntryIdx] = DaqElemSize;
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.ActiveOdtEntryIdx = (ActiveOdtEntryIdx + 1U);
                  
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
*   @brief      This service is used to process the request to stop all DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdStopAllDaq(Xcp_ChannelType XcpChannel)
{
    uint16 DaqList;
    /* deactivate the daq list and reset the state */
    for(DaqList = 0U;DaqList < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;DaqList++)
    {
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] &=
                        (uint8)(XCP_DAQ_FLAG_DIRECTION | XCP_DAQ_FLAG_TIMESTAMP | XCP_DAQ_FLAG_NO_PID);
    }
    /* clear the session for this channel */
    Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_DAQ) & 0xFFFFu);
    Xcp_DaqCmdQueueInit(XcpChannel);  
}
/********************************************************************************************************************
*   @brief      This service is used to intialize the DAQ queue.
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdQueueInit(Xcp_ChannelType XcpChannel)
{
    Xcp_DaqSendQueue[XcpChannel].ReadIdx = 0U;
    Xcp_DaqSendQueue[XcpChannel].ReadIdx = 0U;
    Xcp_DaqSendQueue[XcpChannel].OverloadFlag = FALSE;
}
/********************************************************************************************************************
*   @brief      This service is used to process the request to start all selected DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_DaqCmdStartAllSelectedDaq(Xcp_ChannelType XcpChannel)
{
    uint16 DaqList;
    /* start all Daq list previously selected */
    for(DaqList = 0U;DaqList < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;DaqList++)
    {
        if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] & (uint8)XCP_DAQ_FLAG_SELECTED) != 0U)
        {
            Xcp_DaqCmdStartDaq(XcpChannel,DaqList);
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] &= (uint8)((~XCP_DAQ_FLAG_SELECTED) & 0xFFu);
        }
    }
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service is used to process the allocation of stim memory.
*   @param[in]  XcpChannel  Channel Id type
*   @return returns the error code for the request.
********************************************************************************************************************/
XCP_LOCAL FUNC(uint8, XCP_CODE) Xcp_DaqAllocStimMemory( Xcp_ChannelType XcpChannel )
{
    uint16 DaqList;
    Xcp_OdtIdxType Odt;
    uint8 ErrorCode = XCP_CMD_OK;
    Xcp_OdtIdxType StimBufferCnt=0U;
    /* Iterate for all Daq list */
    for (DaqList = 0;
        ((DaqList < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists) && (ErrorCode == XCP_CMD_OK));
        DaqList++)
    {
        /* Iterate for all otds */
        for (Odt = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqList];
            ((Odt < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqList] +
                    Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtsOfDaq[DaqList]) && 
                    (ErrorCode == XCP_CMD_OK) && (Odt < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM)));
            Odt++)
        {
            /* Check if STIM is enabled in the mode */
            if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] & XCP_DAQ_FLAG_DIRECTION) > 0U)
            {
                if (StimBufferCnt >= (uint8)XCP_MAX_ODT_STIM)
                {
                    ErrorCode = XCP_ERR_MEMORY_OVERFLOW;
                }
                else
                {
                    /* update buffer */
                    Xcp_StimBuffer[XcpChannel][StimBufferCnt].Buffer[0] = 0xFF;
                    Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.pStimBuffer[Odt] = &Xcp_StimBuffer[XcpChannel][StimBufferCnt];
                    StimBufferCnt++;
                }   
            }
            else
            {
                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.pStimBuffer[Odt] = NULL_PTR;
            }
        }
    }
    return ErrorCode;
} 
/********************************************************************************************************************
*   @brief      This service is used to process the request to stop all selected DAQ .
*   @param[in]  XcpChannel  Channel Id type
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStopAllSelectedDaq(Xcp_ChannelType XcpChannel)
{
    uint16 DaqList;
    /* stop all Daq list previously selected */
    for(DaqList = 0U;DaqList < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;DaqList++)
    {
        if ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] & (uint8)XCP_DAQ_FLAG_SELECTED) != 0U)
        {
            Xcp_DaqCmdStopDaq(XcpChannel,DaqList);
            Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqList] &= (uint8)((~XCP_DAQ_FLAG_SELECTED) & 0xFFu);
        }
    }
}
/********************************************************************************************************************
*   @brief      This service is used to process the request to start DAQ .
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  DaqNumber  DAQ number to be started
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStartDaq(Xcp_ChannelType XcpChannel, uint16 DaqNumber)
{
    /* Activate Daq and set session to daq */
    Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqNumber] |= (uint8)XCP_DAQ_FLAG_RUNNING;
    Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListPrescalarCounter[DaqNumber] = 1u;
    Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_DAQ;
}
/********************************************************************************************************************
*   @brief      This service is used to process the request to stop DAQ .
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  DaqNumber  DAQ number to be stoppped
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_DaqCmdStopDaq(Xcp_ChannelType XcpChannel, uint16 DaqNumber)
{
    uint8 Mode=0U;
    uint16 DaqListIdx;

    /* deactivate the daq list and reset the state */
    Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqNumber] &=  (uint8)(XCP_DAQ_FLAG_DIRECTION | XCP_DAQ_FLAG_TIMESTAMP | XCP_DAQ_FLAG_NO_PID);
    /* check if daq session is available for any daqlist in the channel */
    for(DaqListIdx = 0U;DaqListIdx < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;DaqListIdx++)
    {
        Mode |= Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqListIdx];
    }
    /* if no daq list is running, the clear the session for this channel */
    if ((Mode & XCP_DAQ_FLAG_RUNNING) == 0U)
    {
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_DAQ) & 0xFFFFu);
        Xcp_DaqCmdQueueInit(XcpChannel);
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
