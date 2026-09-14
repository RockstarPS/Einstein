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
*   @file XcpOnCan.c
*   @ingroup XcpOnCan
*   @brief This file implements the AUTOSAR XcpOnCan module.The XcpOnCan module is responsible for providing the 
*          XcpOnCan transport layer interface for the Xcp module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "XcpOnCan.h"
#include "XcpOnCan_Lcfg.h"
#include "XcpOnCan_MemMap.h"
#include "Xcp.h"
#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "CanIf.h"
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((XCPONCAN_SW_MAJOR_VERSION != XCPONCAN_CFG_SW_MAJOR_VERSION) || \
    (XCPONCAN_SW_MINOR_VERSION != XCPONCAN_CFG_SW_MINOR_VERSION) || \
    (XCPONCAN_SW_PATCH_VERSION != XCPONCAN_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((XCPONCAN_AR_RELEASE_MAJOR_VERSION != XCPONCAN_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (XCPONCAN_AR_RELEASE_MINOR_VERSION != XCPONCAN_CFG_AR_RELEASE_MINOR_VERSION) || \
    (XCPONCAN_AR_RELEASE_REVISION_VERSION != XCPONCAN_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
#define XcpOnCan_DetReportError(ApiId,ErrId) \
    (void)Det_ReportError(XCPONCAN_MODULE_ID,XCPONCAN_INSTANCE_ID,(ApiId),(ErrId))
#endif
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static XcpOnCan_InitStateType XcpOnCan_InitState = XcpOnCan_InitStateUnInitialized;
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define XCPONCAN_START_SEC_CODE
#include "MemMap.h"

#define XCPONCAN_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define XCPONCAN_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*   @brief      Initializes the XcpOnCan module
*   @param[in]  ConfigPtr  Points to the implementation specific structure
*   @ServiceID  0x01
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_Init( P2CONST(XcpOnCan_ConfigType, AUTOMATIC, XCPONCAN_APPL_CONST) ConfigPtr )
{
    uint8 ChIdx;
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
#endif
    {
        /* Intialize channel states and buffer */
        for(ChIdx=0U; ChIdx< XCPONCAN_NUM_OF_CHANNELS; ChIdx++)
        {
            XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfoState = XCPONCAN_TX_STATE_IDLE;
            XcpOnCan_ChannelCtrlStatus[ChIdx].PduSetState = XcpOnCan_PduSetStateOffline;
            XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfo.SduDataPtr = NULL_PTR;
            XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfo.SduLength = 0U;
            XcpOnCan_ChannelCtrlStatus[ChIdx].Timer = 0U;
            Xcp_UtilMemSet(&XcpOnCan_ChannelCtrlStatus[ChIdx].TxBuffer[0],0U,XCPONCAN_TX_BUFFER_SIZE);
        }
        XcpOnCan_InitState = XcpOnCan_InitStateInitialized;
    }
    XCPONCAN_DUMMY_STATEMENT(ConfigPtr);
}
/********************************************************************************************************************
*   @brief      This service is used to indicate the reception of Pdu from XcpOnCan module 
*   @param[in]  RxPduId  Receive pdu id
*   @param[in]  PduInfoPtr  pointer to the received pdu info 
*   @ServiceID  0x02
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) Xcp_CanIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, XCPONCAN_APPL_DATA) PduInfoPtr
)
{
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
        {
            ErrorId = XCPONCAN_E_NULL_POINTER;
        }
        else if (XCPONCAN_NUM_OF_RX_PDUID <= RxPduId)
        {
            ErrorId = XCPONCAN_E_INV_PARAM_IDX;
        }
        else
        {
            if (XCP_CMD_CONNECT == PduInfoPtr->SduDataPtr[0])
            {
                /* if received cmd is connect ,then set Active TL to CAN*/
                Xcp_SetActiveTl(RxPduId,XCPONCAN_MAX_CTO,XCPONCAN_MAX_DTO,XCP_TRANSPORT_LAYER_CAN);
            }
            /* if current TL is Can then notify to Xcp */
            if (XCP_TRANSPORT_LAYER_CAN == Xcp_GetActiveTl(RxPduId))
            {
                Xcp_TlRxIndication(RxPduId,&PduInfoPtr->SduDataPtr[0]);
            }
        }
    }

#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_CANIFRXINDICATION_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service is used to indicate the confirmation of tramit Pdu from XcpOnCan module 
*   @param[in]  TxPduId  Transmit pdu id
*   @ServiceID  0x03
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) Xcp_CanIfTxConfirmation(PduIdType TxPduId,Std_ReturnType Result)
{
    uint8 ChIdx;
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else
        {
            /* Check for matching confirmation Tx pdu id */
            for (ChIdx = 0U; ChIdx < XCPONCAN_NUM_OF_CHANNELS ; ChIdx++)
            {
                /* If valid Tx pduid found, then notify the Xcp*/
                if (XcpOnCan_ChannelConfig[ChIdx].TxConfPduId == TxPduId)
                {
                    XcpOnCan_ChannelCtrlStatus[ChIdx].Timer = 0U;
                    Xcp_TlTxConfirmation(ChIdx);
                    break;
                }
            }
        }
    }
    XCPONCAN_DUMMY_STATEMENT(Result);
#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_CANIFTXCONFIRMATION_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service is used to transmit the xcp pdu data to the XcpOnCan
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  len  length of the data to be transmitted
*   @param[in]  msg  pointer to the transmit message buffer
*   @ServiceID  0x05
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_Send
( 
    uint8 Xcp_Channel,
    uint8 len, 
    P2CONST(uint8, AUTOMATIC, XCPONCAN_APPL_DATA) msg 
)
{
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    PduInfoType TxPduInfo;
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else if (msg == NULL_PTR)
        {
            ErrorId = XCPONCAN_E_NULL_POINTER;
        }
        else if (XCPONCAN_NUM_OF_CHANNELS <= Xcp_Channel)
        {
             ErrorId = XCPONCAN_E_INV_PARAM_IDX;
        }
        else
        {
            Xcp_UtilMemCopy(&XcpOnCan_ChannelCtrlStatus[Xcp_Channel].TxBuffer[0],msg,len);
            TxPduInfo.SduDataPtr = &XcpOnCan_ChannelCtrlStatus[Xcp_Channel].TxBuffer[0];
            #if (XCPONCAN_VARIABLE_DLC == STD_ON)
            TxPduInfo.SduLength = len;
            #else
            TxPduInfo.SduLength = XCPONCAN_PDU_SIZE;
            #endif

            if (XcpOnCan_ChannelCtrlStatus[Xcp_Channel].PduSetState == XcpOnCan_PduSetStateOffline)
            {
                if (E_NOT_OK == CanIf_Transmit(XcpOnCan_ChannelConfig[Xcp_Channel].CanIfTxPduId,&TxPduInfo))
                {
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfoState = XCPONCAN_TX_STATE_PENDING;
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduDataPtr = TxPduInfo.SduDataPtr;
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduLength = TxPduInfo.SduLength;
                }
                else
                {
                    /* for E_BUSY(if buffered in CanIf ) and E_OK */
                    /* Clear pending transmit request */
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfoState = XCPONCAN_TX_STATE_IDLE;
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduDataPtr = NULL_PTR;
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduLength = 0U;
                    /* set confirmation timer */
                    XcpOnCan_ChannelCtrlStatus[Xcp_Channel].Timer = XCPONCAN_TX_CONFIRMATION_TIMEOUT;
                }
            }
            else
            {
                XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfoState = XCPONCAN_TX_STATE_PENDING;
                XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduDataPtr = TxPduInfo.SduDataPtr;
                XcpOnCan_ChannelCtrlStatus[Xcp_Channel].QueuedPduInfo.SduLength = TxPduInfo.SduLength;
            }
        }
    }
  
#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_SEND_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service is used to flush the pending transmission of xcp pdu data to the XcpOnCan.
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  XcpFlushTypeSel flush type : XCP_FLUSH_CTO, XCP_FLUSH_DTO, XCP_FLUSH_ALL
*   @ServiceID  0x06
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_SendFlush( uint8 Xcp_Channel, uint8 XcpFlushTypeSel )
{
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else
        {
            XCPONCAN_DUMMY_STATEMENT(Xcp_Channel);
            XCPONCAN_DUMMY_STATEMENT(XcpFlushTypeSel);
        }
    }

#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_SENDFLUSH_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service is used to handle the custom transport service layer commands
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  pCmd pointer to the command
*   @return returns the command error code
*   @ServiceID  0x07
********************************************************************************************************************/
FUNC(uint8, XCPONCAN_CODE) XcpOnCan_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, XCPONCAN_APPL_DATA) pCmd )
{
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else
        {
            XCPONCAN_DUMMY_STATEMENT(Xcp_Channel);
            XCPONCAN_DUMMY_STATEMENT(pCmd);
        }
    }

#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_TLSSERVICE_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
    return(XCP_ERR_CMD_UNKNOWN);
}
/********************************************************************************************************************
*   @brief      This service is process the pending transmission and tx confirmation timeout
*   @ServiceID  0x08
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_MainFunction( void )
{
    uint8 ChIdx;
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
    boolean NotifyConfTimeout = FALSE;
    
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else
        {
            /* retransmit the pending request */
            for (ChIdx=0;ChIdx<XCPONCAN_NUM_OF_CHANNELS;ChIdx++)
            {
                if ((XcpOnCan_ChannelCtrlStatus[ChIdx].PduSetState == XcpOnCan_PduSetStateOnline) && 
                    (XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfoState == XCPONCAN_TX_STATE_PENDING))
                {
                    if (E_OK == CanIf_Transmit(XcpOnCan_ChannelConfig[ChIdx].CanIfTxPduId,
                                                &XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfo))
                    {
                        /* for E_BUSY(if buffered in CanIf ) and E_OK */
                        /* Clear pending transmit request */
                        XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfoState = XCPONCAN_TX_STATE_IDLE;
                        XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfo.SduDataPtr = NULL_PTR;
                        XcpOnCan_ChannelCtrlStatus[ChIdx].QueuedPduInfo.SduLength = 0U;
                        /* set confirmation timer */
                        XcpOnCan_ChannelCtrlStatus[ChIdx].Timer = XCPONCAN_TX_CONFIRMATION_TIMEOUT;
                    }
                }

                XcpOnCan_EnterCriticalSection();
                if (XcpOnCan_ChannelCtrlStatus[ChIdx].Timer > 0U)
                {
                    XcpOnCan_ChannelCtrlStatus[ChIdx].Timer--;
                    if (XcpOnCan_ChannelCtrlStatus[ChIdx].Timer == 0U)
                    {
                        NotifyConfTimeout = TRUE;
                    }
                }
                XcpOnCan_ExitCriticalSection();
                if (NotifyConfTimeout == TRUE)
                {
                    /* Timeout happened, release PDU */
                    (void)Xcp_TlTxConfirmation(ChIdx);
                }
            }
        }
    }

#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_MAINFUNCTION_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service is used to set the PDU mode to control the transmission of PDU
*   @param[in]  Network network id 
*   @param[in]  PduMode Tx pdu mode type XcpOnCan_PduSetStateOffline : No Transmission
*   XcpOnCan_PduSetStateOnline : Transmission allowed
*   @ServiceID  0x09
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_SetPduMode( NetworkHandleType Network, XcpOnCan_PduSetStateType PduMode )
{
    uint8 ErrorId = XCPONCAN_E_NO_ERROR;
     
    #if ( CANXCP_ENABLE_CONTROL == STD_ON )
    if (XcpOnCan_ControlState == XcpOnCan_ControlStateEnable)
    #endif
    {
        if (XcpOnCan_InitStateUnInitialized == XcpOnCan_InitState)
        {
            ErrorId = XCPONCAN_E_NOT_INITIALIZED;
        }
        else if (XCPONCAN_NUM_OF_CHANNELS <= Network)
        {
             ErrorId = XCPONCAN_E_INV_PARAM_IDX;
        }
        else
        {
            XcpOnCan_ChannelCtrlStatus[Network].PduSetState = PduMode;
        }
    }

#if (XCPONCAN_DEV_ERROR_DETECT == STD_ON)
    if (XCPONCAN_E_NO_ERROR != ErrorId)
    {
        XcpOnCan_DetReportError(XCPONCAN_SETPDUMODE_API, ErrorId);
    }
#else
    XCPONCAN_DUMMY_STATEMENT(ErrorId);
#endif
}

#define XCPONCAN_STOP_SEC_CODE
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
*  @date    02-Apr-2024
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/
