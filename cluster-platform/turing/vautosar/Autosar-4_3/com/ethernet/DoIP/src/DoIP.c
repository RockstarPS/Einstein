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
*   @file DoIP.c
*   @ingroup DoIP
*   @brief This file implements the AUTOSAR DoIP module.The DoIP module implements the ISO 13400 Diagnostic over 
*   IP (DoIP).
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP.h"
#include "DoIP_Lcfg.h"
#include "SchM_DoIP.h"
#include "DoIP_MemMap.h"
#include "DoIP.h"
#include "DoIP_Internal.h"
#include "PduR_DoIP.h"
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((DOIP_SW_MAJOR_VERSION != DOIP_CFG_SW_MAJOR_VERSION) || \
    (DOIP_SW_MINOR_VERSION != DOIP_CFG_SW_MINOR_VERSION) || \
    (DOIP_SW_PATCH_VERSION != DOIP_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((DOIP_AR_RELEASE_MAJOR_VERSION != DOIP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (DOIP_AR_RELEASE_MINOR_VERSION != DOIP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (DOIP_AR_RELEASE_REVISION_VERSION != DOIP_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static DoIP_InitStateType DoIP_InitState = DoIP_StateUnInitialized;
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
* @brief This api is used to intialize the connection status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConnectionInit(void);
/*!******************************************************************************************************************
* @brief This api is used to intialize the channel status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ChannelsInit(void);
/*!******************************************************************************************************************
* @brief This api is used to intialize the tester status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TesterInit(void);
/*!******************************************************************************************************************
* @brief This api is used to intialize the local address status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_LocalAddrInit(void);
/*!******************************************************************************************************************
* @brief This api is used to intialize the routing activation status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RoutingActivationInit(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the GID synchronization 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_GidSyncHandler(void);
/*! # SoCon */
/*!******************************************************************************************************************
* @brief This api is used to get the DoIP Connection idx by the socket connection idx
* @param[in] SoConId the socket connection idx
* @param[out] pConIdx the pointer to the DoIP connection idx
* @return status of the request E_OK: valid DoIP Connection id found E_NOT_OK: No DoIP Connection id found
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_GetConIdxBySoConId
( 
    SoAd_SoConIdType SoConId,
    P2VAR(DoIP_ConIdxType, AUTOMATIC, DOIP_APPL_VAR) pConIdx
);
/*!******************************************************************************************************************
* @brief This api is used to process the Socket conncetion mode change 
* @param[in] SoConId the socket connection idx
* @param[in] Mode the socket conncetion mode
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_SoConModeChgOnlineHandler
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode,
    DoIP_ConIdxType ConIdx
);
/*!******************************************************************************************************************
* @brief  This api used to process the tcp socket connection mode changes
* @param[in] TcpConIdx the DoIP tcp connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TcpSoConModeChgOfflineHandler(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to handle the socket connection mode offline
* @param[in] Mode the socket connection mode
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_SoConModeChgOfflineHandler(SoAd_SoConModeType Mode,DoIP_ConIdxType ConIdx);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp socket connection mode offline
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpSoConModeChgOfflineHandler(DoIP_ConIdxType ConIdx);
/*!******************************************************************************************************************
* @brief  This api used to check whether the all the Socket connections are assigned to the SoAd connection
* @return status of the assignment E_OK: all connection are assigned E_NOT_OK: all connection are not assigned
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_IsSoConIdxAssignedForAllCon(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the Socket conncetion states 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_HandleSoConStateHandler(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the active line state inactive
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConHandleActLineStateInactive(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the close request for the socket connection 
* @return request status E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_ConSoConCloseAll(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the release all Ip address assignment
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConRelAllIpAddrAssign(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the release Ip address assignment of the local addr idx
* @param[in] LocalAddrIdx the local address idx 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConRelIpAddrAssign(DoIP_LocalAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief  This api used to handle the local Ip address change for the connection Idx 
* @param[in] ConIdx the DoIP connection Idx
* @param[in] State the Ip address state type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChgHandler
(
    DoIP_ConIdxType Condx,
    SoAd_IpAddrStateType State
);
/*!******************************************************************************************************************
* @brief  This api used to process the activation line active request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ActivationLineStateActiveHandler(void);
/*!******************************************************************************************************************
* @brief  This api used to process the Local Ip address assignement 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_IpAddrAssignmentHandler(void);
/*!******************************************************************************************************************
* @brief  This api used to set the DHCP host name for the local address id
* @param[in] LocalIpAddrIdx the local Ip address idx
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_SetDhcpHostname(DoIP_LocalIpAddrIdxType LocalIpAddrIdx);
/*!******************************************************************************************************************
* @brief  This api used to request the ip address assignment for the local ip address idx 
* @param[in] LocalIpAddrIdx the local Ip address idx
* @param[in] IpAddrAssignmentIdx the local Ip assignment idx
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RequestIpAddrAssignment
(   
    DoIP_LocalIpAddrIdxType  LocalIpAddrIdx,
    DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx
);
#define DOIP_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
* @brief This service initializes all global variables of the DoIP module. After return of this service the 
* DoIP module is operational.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_Init(P2CONST(DoIP_ConfigType,AUTOMATIC,DOIP_APPL_CONST) DoIPConfigPtr)
{
    /* Initialize DoIP Connection */
    DoIP_ConnectionInit();
    /* Initialize DoIP Channel */
    DoIP_ChannelsInit();
    /* Initialize DoIP Tester */
    DoIP_TesterInit();
    /* Initialize DoIP Local Addr */
    DoIP_LocalAddrInit();
    /* Initialize DoIP routing activation init */
    DoIP_RoutingActivationInit();
    /* Initialize Oem payload ctrl status */   
    DoIP_OemPayloadCtrlSetTcpBufferReqTx(FALSE);
    DoIP_OemPayloadCtrlSetTcpBufferLength(0U);
    DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
    DoIP_OemPayloadCtrlSetUdpBufferLength(0U);
    /* Initialize Activation line status */
    DoIP_CtrlSetActivationLineInactiveReq(FALSE);
    DoIP_CtrlSetActivationLineState(DoIP_CfgGetDefaultActivationLineState());
    DoIP_CtrlSetPduSizeRoutingStatus(FALSE);
    DoIP_CtrlSetGroupIdInSyncStatus(FALSE);
    /* set the state to initialized */
    DoIP_InitState = DoIP_StateInitialized;
    DOIP_DUMMY_STATEMENT(DoIPConfigPtr);
}
#if (DOIP_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
* @brief Returns the version information of this module.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,DOIP_APPL_DATA) versioninfo)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    /* check for Dev error */
    if (NULL_PTR == versioninfo)
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else
    {
        /* Get version info */
        versioninfo->vendorID = DOIP_VENDOR_ID;
        versioninfo->moduleID = DOIP_MODULE_ID;
        versioninfo->sw_major_version = DOIP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DOIP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DOIP_SW_PATCH_VERSION;
    }

#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_GETVERSIONINFO_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
/********************************************************************************************************************
* @brief Requests transmission of a PDU.
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr 
)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ChannelIdxType ChannelIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    /* check for Dev error */
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if (NULL_PTR == PduInfoPtr)
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else if (0U == PduInfoPtr->SduLength)
    {
        ErrorId = DOIP_E_INVALID_PARAMETER;
    }
    else
    {
        ChannelIdx = DoIP_TxPduIdCfgGetChannelIdx(TxPduId);
        if (DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_TP)
        {
            /* Check for any pending tx */
            if (DoIP_ChannelCtrlCfgGetTxLength(ChannelIdx) == 0U)
            {
                TesterIdx = DoIP_ChannelCfgGetTesterIdx(ChannelIdx);
                TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterIdx);
                if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
                {
                    /* Trigger transmit */
                    DoIP_ChannelCtrlCfgSetTxLength(ChannelIdx,PduInfoPtr->SduLength);
                    RetVal = DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_REQ,ChannelIdx,
                                                (uint16)PduInfoPtr->SduLength,0U,NULL_PTR, FALSE);  
                }
                if (RetVal == E_NOT_OK)
                {
                    /* reset length */
                    DoIP_ChannelCtrlCfgSetTxLength(ChannelIdx,0U);
                }
            }
        }
        else
        {
            ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_TPTRANSMIT_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit(PduIdType TxPduId)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ChannelIdxType ChannelIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    /* check for Dev error */
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        ChannelIdx = DoIP_TxPduIdCfgGetChannelIdx(TxPduId);
        if (DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_TP)
        {
            TesterIdx = DoIP_ChannelCfgGetTesterIdx(ChannelIdx);
            TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterIdx);
            if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
            {
                /* Check for pending tp tx */
                if ((DoIP_TcpConCtrlGetTxTpSessionActive(TcpConIdx) == TRUE) && 
                    (DoIP_ChannelCtrlCfgGetTxLength(ChannelIdx) == 0U))
                {
                    /* trigger tp cancel transmit */
                    if (SoAd_TpCancelTransmit(DoIP_ConCfgGetTxPduId(TcpConIdx)) == E_OK)
                    {
                        DoIP_TcpConCtrlSetTxTpCancelReq(TcpConIdx,TRUE);
                        RetVal = E_OK;
                    }
                }
            }
        }    
        else
        {
            ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_TPCANCELTRANSMIT_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief Requests cancellation of an ongoing reception of a PDU in a lower layer transport protocol module.
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive(PduIdType RxPduId)
{
    DoIP_TesterIdxType TesterIdx;
    DoIP_ChannelIdxType ChannelIdx;
    DoIP_TcpConIdxType TcpConIdx;
    uint8 ErrorId = DOIP_E_NO_ERROR;
    /* check for Dev error */
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_RX_PDU <= RxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        ChannelIdx = DoIP_RxPduCfgGetChannelIdx(RxPduId);
        if (DOIP_API_TYPE_TP == DoIP_ChannelCfgGetApiType(ChannelIdx))
        {
            TesterIdx = DoIP_ChannelCfgGetTesterIdx(ChannelIdx);
            TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterIdx);
            if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
            {
                /* check if channe is active */
                if (DoIP_TcpConCtrlGetRxChannelActive(TcpConIdx) == TRUE)
                {
                    /* Request SoAd to cancel the Rx */
                    if (SoAd_TpCancelReceive(DoIP_ConCfgGetRxCancelPduId(TcpConIdx)) == E_OK)
                    {
                        DoIP_TcpConCtrlSetRxTpCancelReq(TcpConIdx,TRUE);
                    }
                }
            }
        }
        else
        {
            ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_TPCANCELRECEIVE_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
   return E_OK; 
}
/********************************************************************************************************************
* @brief Requests transmission of a PDU.
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfTransmit
(
    PduIdType TxPduId, 
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr
)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ChannelIdxType ChannelIdx;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for Dev error */
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if ((NULL_PTR == PduInfoPtr) && (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else
    {
        ChannelIdx = DoIP_TxPduIdCfgGetChannelIdx(TxPduId);
        if ((DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_IF) &&
            (DoIP_ChannelCfgGetTxIfBufferSize(ChannelIdx) > PduInfoPtr->SduLength))
        {
            /* Check for any pending tx */
            if (DoIP_ChannelCtrlCfgGetTxLength(ChannelIdx) == 0U)
            {
                TesterIdx = DoIP_ChannelCfgGetTesterIdx(ChannelIdx);
                TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterIdx);
                if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
                {
                    /* Trigger transmit */
                    DoIP_ChannelCtrlCfgSetTxLength(ChannelIdx,PduInfoPtr->SduLength);
                    RetVal = DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_REQ,ChannelIdx,
                                                (uint16)PduInfoPtr->SduLength,0U,PduInfoPtr->SduDataPtr, FALSE);  
                }
            }
        }
        else
        {
            ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_IFTRANSMIT_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
   return RetVal; 
}
/********************************************************************************************************************
* @brief Requests cancellation of an ongoing transmission of a PDU in a lower layer
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit(PduIdType TxPduId)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ChannelIdxType ChannelIdx;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* check for Dev error */
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        ChannelIdx = DoIP_TxPduIdCfgGetChannelIdx(TxPduId);
        if (DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_IF)
        {
            TesterIdx = DoIP_ChannelCfgGetTesterIdx(ChannelIdx);
            TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterIdx);
            if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
            {
                /* check if any tx ongoing  */
                if((DoIP_TcpConCtrlGetTxTpSessionActive(TcpConIdx) == TRUE) &&
                    (DoIP_ChannelCtrlCfgGetTxLength(ChannelIdx) == 0U))
                {
                    /* Request SoAd to Cancel the transmit */
                    if(SoAd_TpCancelTransmit(DoIP_ConCfgGetTxPduId(TcpConIdx)) == E_OK )
                    {
                        DoIP_TcpConCtrlSetTxTpCancelReq(TcpConIdx,TRUE);
                        RetVal = E_OK;
                    }
                }
            }
        }
        else
        {
            ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_IFCANCELTRANSMIT_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief This function is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
* function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this
* case the function restarts to copy the data beginning at the offset from the current position indicated
* by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated by availableDataPtr.
********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2CONST(RetryInfoType,AUTOMATIC,DOIP_APPL_CONST) retry,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) availableDataPtr
)
{
    DoIP_ConIdxType ConIdx;
    uint8 ErrorId = DOIP_E_NO_ERROR;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    /* check for Dev error */
    ConIdx = (DoIP_ConIdxType)id;
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfTcpConnection() <= ConIdx)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if ((NULL_PTR == info) || (NULL_PTR == availableDataPtr) || 
            ((info->SduDataPtr == NULL_PTR) && (info->SduLength != 0U)))
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else if (NULL_PTR != retry)
    {
        ErrorId = DOIP_E_INVALID_PARAMETER;
    }
    else
    {
        if (DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_ONLINE)
        {
            RetVal = DoIP_TxTcpQueueCopy(ConIdx, info, availableDataPtr);
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADTPCOPYTXDATA_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief This function is called after the I-PDU has been transmitted on its network, the result indicates 
* whether the transmission was successful or not.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_TcpConIdxType TcpConIdx;
    TcpConIdx = id;
    /* check for Dev error */    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfTcpConnection() <= TcpConIdx)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        /* Remove element from queue */
        DoIP_TxTcpQueueRemoveElement(TcpConIdx,result);
        if (DoIP_TcpConCtrlGetTxTpCancelReq(TcpConIdx) == TRUE)
        {
            DoIP_TcpConCtrlSetTxTpCancelReq(TcpConIdx,FALSE);
        }
        
        if ((DoIP_ConCtrlGetSoConCloseReq(TcpConIdx) == TRUE) &&
            (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) == 0u))
        {
            /* request to close if no connection is pending */
             DoIP_SoConClose(TcpConIdx); 
        }
        else
        {
            if (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) > 0u )
            {
                /* Transmit pending element (if enabled). */
                DoIP_TxTcpQueueTransmitElement(TcpConIdx);
            }
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADTPTXCONFIRMATION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief This function is called at the start of receiving an N-SDU. The N-SDU might be fragmented into multiple
* N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF). The service shall 
* provide the currently available maximum buffer size when invoked with TpSduLength equal to 0.
********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr 
)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfTcpConnection() <= id)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if (NULL_PTR == bufferSizePtr)
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else if (0U != TpSduLength )
    {
        ErrorId = DOIP_E_INVALID_PARAMETER;
    }
    else
    {
        /* Check for connection reception state */
        if ((DoIP_ConCtrlGetSoConMode((DoIP_ConIdxType)id) == SOAD_SOCON_ONLINE) && 
            (DoIP_TcpConCtrlGetRxTpSessionActive((DoIP_TcpConIdxType)id) == FALSE))
        {
            /* Set Rx Tp session active */
            DoIP_TcpConCtrlSetRxTpSessionActive((DoIP_TcpConIdxType)id,TRUE);
            RetVal = BUFREQ_OK;
        }
        DOIP_DUMMY_STATEMENT(info);
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADTPSTARTOFRECEPTION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
* Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer 
* is written to the position indicated by bufferSizePtr.
********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr
)
{
    DoIP_TesterIdxType TesterIdx;
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfTcpConnection() <= id)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if ((NULL_PTR == bufferSizePtr) || (NULL_PTR == info))
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else
    {
        RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset((DoIP_TcpConIdxType)id);
        TesterIdx = DoIP_TcpConCtrlGetTesterIdx((DoIP_TcpConIdxType)id);

        if ((DoIP_ConCtrlGetSoConMode((DoIP_ConIdxType)id) == SOAD_SOCON_ONLINE) && 
            (DoIP_TcpConCtrlGetRxTpSessionActive((DoIP_TcpConIdxType)id) == TRUE))
        {
            if (DoIP_ConCtrlGetSoConCloseReq((DoIP_ConIdxType)id) == TRUE) /* Check for socket close connection */
            {
                *bufferSizePtr = 0U;
                DoIP_TcpConCtrlSetRxLastBufferSize((DoIP_TcpConIdxType)id,0U);
                RetVal = BUFREQ_OK;
            }
            else if (DoIP_TcpConCtrlGetRxTpCancelReq((DoIP_TcpConIdxType)id) == TRUE) /* Rx Tp cancel request is set */
            {
                RetVal = BUFREQ_E_NOT_OK;
            }
            else if ((TesterIdx != DoIP_CfgGetNumOfTester()) && (RxMsgOffset == 0U) &&
                     (DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx) > 0U))
            { 
                /* diagnostic message acknowledge is pending - do not accept new data until acknowledge is sent */
                *bufferSizePtr = 0U;
                DoIP_TcpConCtrlSetRxLastBufferSize((DoIP_TcpConIdxType)id,0U);
                RetVal = BUFREQ_OK;
            }
            else if ((info->SduLength == 0U) && (RxMsgOffset < DOIP_GENERIC_HEADER_LENGTH))
            {
                /* provide buffer for generic header */
                *bufferSizePtr = (PduLengthType)(DOIP_GENERIC_HEADER_LENGTH - RxMsgOffset);
                DoIP_TcpConCtrlSetRxLastBufferSize((DoIP_TcpConIdxType)id,*bufferSizePtr);
                RetVal = BUFREQ_OK;
            }
            else if ((info->SduLength != 0U) && (info->SduDataPtr == NULL_PTR) )
            {
                /* SoAd has Rx data */
                ErrorId = DOIP_E_INVALID_PARAMETER; 
                RetVal = BUFREQ_E_NOT_OK;
            }
            /* SoAd has Rx data AND check length */
            else if ((info->SduLength != 0U) && 
                    (info->SduLength > DoIP_TcpConCtrlGetRxLastBufferSize((DoIP_TcpConIdxType)id)))
            { 
                /* unexpected length */
                RetVal = BUFREQ_E_NOT_OK;
            }
            else
            {
                /* Process copy request.*/
                DoIP_RxTcpHandleCopyRxDataCopy((DoIP_TcpConIdxType)id, info, bufferSizePtr, &ErrorId);
                RetVal = BUFREQ_OK;
            }
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADTPCOPYRXDATA_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief Called after an I-PDU has been received via the TP API, the result indicates whether the transmission 
* was successful or not.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdTpRxIndication(PduIdType id, Std_ReturnType result)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfTcpConnection() <= id)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        /* Reset Tp session */
        DoIP_TcpConCtrlSetRxTpSessionActive((DoIP_TcpConIdxType)id,FALSE);
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADTPRXINDICATION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
    DOIP_DUMMY_STATEMENT(result);
}
/********************************************************************************************************************
* @brief Indication of a received PDU from a lower layer communication interface module.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr
)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DoIP_CfgGetNumOfConnection() <= RxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = DOIP_E_PARAM_POINTER;
    }
    else
    {
        /* Check for connection reception state */
        if ((DoIP_ConCtrlGetIpAddrState((DoIP_ConIdxType)RxPduId) == SOAD_IPADDR_STATE_ASSIGNED) &&
            (DoIP_ConCtrlGetSoConMode((DoIP_ConIdxType)RxPduId) == SOAD_SOCON_ONLINE) && 
            (DoIP_ConCtrlGetSoConCloseReq((DoIP_ConIdxType)RxPduId) == FALSE))
        {
            DoIP_RxUdpHandleRxIndication((DoIP_ConIdxType)RxPduId, PduInfoPtr);
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADIFRXINDICATION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
* transmit a PDU.
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdIfTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if (DOIP_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = DOIP_E_INVALID_PDU_SDU_ID;
    }
    else
    {
        /* TODO : If the SoAd calls the DoIP module via the Interface DoIP_SoAdIfTxConfirmation, the DoIP module shall 
            release the buffer which is related to the received TxPduId. */
        DOIP_DUMMY_STATEMENT(TxPduId);
        DOIP_DUMMY_STATEMENT(result);
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOADIFTXCONFIRMATION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief Notification about a DoIP socket connection state change, e.g. socket connection gets online
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoConModeChg(SoAd_SoConIdType SoConId, SoAd_SoConModeType Mode)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ConIdxType ConIdx;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if ( (Mode != SOAD_SOCON_ONLINE) &&
            (Mode != SOAD_SOCON_RECONNECT) &&
            (Mode != SOAD_SOCON_OFFLINE) )
    {
        ErrorId = DOIP_E_INVALID_PARAMETER;
    }
    else
    {
        if (DoIP_GetConIdxBySoConId(SoConId,&ConIdx) == E_OK)
        {
            if (Mode == SOAD_SOCON_ONLINE )
            {
                /* handle Online mode change */
                DoIP_SoConModeChgOnlineHandler(SoConId,Mode,ConIdx);
            }
            else
            {
                /* handle Offline mode change */
                DoIP_SoConModeChgOfflineHandler(Mode,ConIdx);
            } 
        }
        else
        {
            //ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_SOCONMODECHG_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief This function gets called by the DoIP if an IP address assignment related to a socket connection 
* changes (i.e. new address assigned or assigned address becomes invalid).
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChg(SoAd_SoConIdType SoConId, TcpIp_IpAddrStateType State)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    DoIP_ConIdxType ConIdx;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else if ((State != SOAD_IPADDR_STATE_ASSIGNED) && 
            (State != SOAD_IPADDR_STATE_ONHOLD) && (State != SOAD_IPADDR_STATE_UNASSIGNED))
    {
        ErrorId = DOIP_E_INVALID_PARAMETER;
    }
    else
    {
        if (DoIP_GetConIdxBySoConId(SoConId,&ConIdx) == E_OK)
        {
            DoIP_LocalIpAddrAssignmentChgHandler(ConIdx,State);
        }
        else
        {
            //ErrorId = DOIP_E_INVALID_PARAMETER;
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_LOCALIPADDRASSIGNMENTCHG_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief This function is used to notify the DoIP on a switch of the DoIPActivationLine to active
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_ActivationLineSwitchActive(void)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else
    {
        /* set activation req and line active */
        DoIP_CtrlSetActivationLineState(DOIP_ACTIVATION_LINE_ACTIVE);
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_ACTIVATIONLINESWITCHACTIVE_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief This function is used to notify the DoIP on a switch of the DoIPActivationLine to inactive
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_ActivationLineSwitchInactive(void)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else
    {
        /* set activation req and line inactive */
        DoIP_CtrlSetActivationLineInactiveReq(TRUE);
        DoIP_CtrlSetActivationLineState(DOIP_ACTIVATION_LINE_INACTIVE);
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_ACTIVATIONLINESWITCHINACTIVE_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief Schedules the Diagnostic over IP module. (Entry point for scheduling)
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_MainFunction(void)
{
    uint8 ErrorId = DOIP_E_NO_ERROR;
    
    if (DoIP_StateUnInitialized == DoIP_InitState)
    {
        ErrorId = DOIP_E_UNINIT;
    }
    else
    {
        /* Handle active line request */
        if ((DoIP_CtrlGetActivationLineState() == DOIP_ACTIVATION_LINE_ACTIVE) && 
            (DoIP_CtrlGetActivationLineInactiveReq() == FALSE))
        {
            if (DoIP_IsSoConIdxAssignedForAllCon() == E_OK)
            {
                DoIP_ActivationLineStateActiveHandler();
            }
        }
        else
        {
            DoIP_ConHandleActLineStateInactive();
        }
    }
    
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
    if (DOIP_E_NO_ERROR != ErrorId)
    {
        DoIP_DetReportError(DOIP_MAINFUNCTION_API , ErrorId);
    }
#else
    DOIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief This api is used to request closing of the socket connection
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoConClose(DoIP_ConIdxType ConIdx)
{
    /* Request to close SoCon */
    (void)SoAd_CloseSoCon(DoIP_ConCtrlGetSoConIdx(ConIdx), TRUE);
    /* Set state from reconnect to offline since it might be set to reconnect to avoid multiple open requests. */
    if(DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_RECONNECT)
    {
        DoIP_ConCtrlSetSoConMode(ConIdx, SOAD_SOCON_OFFLINE); 
    }
}
FUNC(uint8, DOIP_CODE) DoIP_UtilGetU8(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset)
{
    return pBuffer[Offset];
}

FUNC(uint16, DOIP_CODE) DoIP_UtilGetU16(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset)
{
    return (uint16)(((uint16)(pBuffer[Offset + 0u]) << 8u) | pBuffer[Offset + 1u]);
}

FUNC(uint32, DOIP_CODE) DoIP_UtilGetU32(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset)
{
    return (uint32)(((uint32)(pBuffer[Offset + 0u]) << 24u) | ((uint32)(pBuffer[Offset + 1u]) << 16u) | 
                  ((uint32)(pBuffer[Offset + 2u]) << 8u) | pBuffer[Offset + 3u]);

}

FUNC(void, DOIP_CODE) DOIP_UtilExtractGenericHeader
(
    P2VAR(DoIP_GenericHeaderType,AUTOMATIC,DOIP_APPL_DATA) pGenericHeader,
    P2CONST(uint8,AUTOMATIC,DOIP_APPL_DATA) pBuffer
)
{
    pGenericHeader->HeaderVersion = DoIP_UtilGetU8(pBuffer,0);
    pGenericHeader->HeaderInvVersion = DoIP_UtilGetU8(pBuffer,1);
    pGenericHeader->HeaderType = DoIP_UtilGetU16(pBuffer,2);
    pGenericHeader->HeaderLength = DoIP_UtilGetU32(pBuffer,4);
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief This api is used to intialize the connection status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConnectionInit(void)
{
    DoIP_ConIdxType ConIdx;
    DoIP_TcpConIdxType TcpConIdx;
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx;    
    /* Initialize the SoCon status */
    for(ConIdx = 0U; ConIdx < DoIP_CfgGetNumOfConnection();ConIdx++ )
    {
        DoIP_ConCtrlSetIpAddrState(ConIdx,SOAD_IPADDR_STATE_UNASSIGNED);
        DoIP_ConCtrlSetSoConIdx(ConIdx,SOAD_SOCON_ID_INVALID);
        DoIP_ConCtrlSetSoConMode(ConIdx,SOAD_SOCON_OFFLINE);
        DoIP_ConCtrlSetSoConCloseReq(ConIdx,FALSE);
    }
    /* Initialize the Tcp connection */
    for (TcpConIdx = 0U; TcpConIdx < DoIP_CfgGetNumOfTcpConnection();TcpConIdx++)
    {
        /* Initialize the Tcp Connection ctrl status */
        DoIP_TcpConCtrlSetTesterAddr(TcpConIdx,DOIP_ADDR_ANY);
        DoIP_TcpConCtrlSetTesterIdx(TcpConIdx,DoIP_CfgGetNumOfTester());
        DoIP_TcpConCtrlSetRoutingActivationIdx(TcpConIdx,DoIP_CfgGetNumOfRoutingActivation());
        DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE);
        DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
        /* Initialize the Tcp connection Tx Ctrl status */
        DoIP_TcpConCtrlSetTxTpCancelReq(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetTxTpCloseSocketReq(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,0U);
        DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,0U);
        DoIP_TcpConCtrlSetTxTcpQueueElementIdx(TcpConIdx,DoIP_TcpConCfgGetTcpTxQueueElementStartIdx(TcpConIdx));
        DoIP_TcpConCtrlSetTxTcpCtrlQueueLevel(TcpConIdx,0U);
        DoIP_TcpConCtrlSetTxTpHeaderType(TcpConIdx,DOIP_HEADER_TYPE_INVALID);
        DoIP_TcpConCtrlSetTxTpFirstParam(TcpConIdx,0U);
        DoIP_TcpConCtrlSetTxTpSecondParam(TcpConIdx,0U);
        DoIP_TcpConCtrlSetTxTpThirdParam(TcpConIdx,0U);
        /* Initialize the Tcp connection Tx queue */
        DoIP_TxTcpQueueElementIdxType TcpTxQueueElementIdx;
        for(TcpTxQueueElementIdx = DoIP_TcpConCfgGetTcpTxQueueElementStartIdx (TcpConIdx);
            TcpTxQueueElementIdx <= DoIP_TcpConCfgGetTcpTxQueueElementEndIdx(TcpConIdx); TcpTxQueueElementIdx++)
        {
            DoIP_TxTcpQueueElementCtrlSetChannelIdx(TcpTxQueueElementIdx,DoIP_CfgGetNumOfChannel());
            DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TcpTxQueueElementIdx,0U);
            DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TcpTxQueueElementIdx,0U);
            DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TcpTxQueueElementIdx,NULL_PTR);
        }
        /* Initialize the Tcp connection Rx Ctrl status */
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,FALSE);        
        DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetRxTpSessionActive(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetRxTpCancelReq(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U); 
        DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);      
        DoIP_TcpConCtrlSetRxLastTargetAddr(TcpConIdx,DOIP_ADDR_ANY); 
        DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,DoIP_CfgGetNumOfChannel()); 
    }
    /* Initialize all UDP tx status */
    for(UdpTxCtrlIdx = 0u;UdpTxCtrlIdx<DoIP_CfgGetNumOfUdpTxCtrl();UdpTxCtrlIdx++)
    {
        DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx,DoIP_CfgGetNumOfConnection());
        DoIP_UdpTxCtrlSetTxRetryCount(UdpTxCtrlIdx,0U);
        DoIP_UdpTxCtrlSetTxHeaderType(UdpTxCtrlIdx,DOIP_HEADER_TYPE_INVALID);
        DoIP_UdpTxCtrlSetTxFirstParam(UdpTxCtrlIdx,0U);
        DoIP_UdpTxCtrlSetTxSecondParam(UdpTxCtrlIdx,0U);
    }    
}
/********************************************************************************************************************
* @brief This api is used to intialize the channel status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ChannelsInit(void)
{
    DoIP_ChannelIdxType ChannelIdx;
    for(ChannelIdx=0U;ChannelIdx < DoIP_CfgGetNumOfChannel();ChannelIdx++)
    {
        DoIP_ChannelCtrlCfgSetTxLength(ChannelIdx,0U);
    }
}
/********************************************************************************************************************
* @brief This api is used to intialize the tester status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TesterInit(void)
{
    DoIP_TesterIdxType TesterIdx;
    
    for(TesterIdx=0U;TesterIdx < DoIP_CfgGetNumOfTester();TesterIdx++)
    {
        DoIP_TesterCtrlSetTcpConIdx(TesterIdx,DoIP_CfgGetNumOfTcpConnection());
        DoIP_TesterCtrlSetNegativeAckOffset(TesterIdx,0U);
    }
}
/********************************************************************************************************************
* @brief This api is used to intialize the local address status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_LocalAddrInit(void)
{
    DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx;
    
    for(IpAddrAssignmentIdx=0U;IpAddrAssignmentIdx < DoIp_CfgGetNumOfIpAddrAssignment();IpAddrAssignmentIdx++)
    {
        DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(IpAddrAssignmentIdx,DOIP_IP_ADDR_REQ_STATE_NONE);
    }
    DoIP_LocalIpAddrAssignedCount = 0U;
}
/********************************************************************************************************************
* @brief This api is used to intialize the routing activation status
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RoutingActivationInit(void)
{
    DoIP_RoutingActivationCtrlSetOemReqResUsed(FALSE);
    DoIP_RoutingActivationCtrlSetOemRequest(0U);
    DoIP_RoutingActivationCtrlSetOemResponse(0U);
    DoIP_RoutingActivationCtrlSetAliveCheckCount(0U);
    DoIP_RoutingActivationCtrlSetTcpConIdx(DoIP_CfgGetNumOfTcpConnection());
    DoIP_RoutingActivationCtrlSetTesterAddr(DOIP_ADDR_ANY);
    DoIP_RoutingActivationCtrlSetTesterIdx(DoIP_CfgGetNumOfTester());
    DoIP_RoutingActivationCtrlSetRoutingActivationIdx(DoIP_CfgGetNumOfRoutingActivation());
    DoIP_RoutingActivationCtrlSetAliveCheckElemNum(0U);
    /* alive check list Init */
}
/********************************************************************************************************************
* @brief  This api used to handle the GID synchronization 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_GidSyncHandler(void)
{
    if (DoIP_GroupIdInSyncStatus != TRUE)
    {
        /* Invoke Gid sync if ip address is assigned */
        if (DoIP_LocalIpAddrAssignedCount > 0U)
        {
            if(DoIP_CfgUserTriggerGidSyncCallbackFn() == E_OK) 
            {
                DoIP_GroupIdInSyncStatus = FALSE;
            }
        }
    }
}
/*! # SoCon */
/********************************************************************************************************************
* @brief This api is used to get the DoIP Connection idx by the socket connection idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_GetConIdxBySoConId
( 
    SoAd_SoConIdType SoConId,
    P2VAR(DoIP_ConIdxType, AUTOMATIC, DOIP_APPL_VAR) pConIdx
)
{
  Std_ReturnType RetVal = E_NOT_OK;
  DoIP_ConIdxType ConIdx;

    /* Get matching Connection idx if the SoConId found  */
    for (ConIdx = 0U; ConIdx < DoIP_CfgGetNumOfConnection();ConIdx++)
    {
        if (SoConId == DoIP_ConCtrlGetSoConIdx(ConIdx))
        {
            *pConIdx = ConIdx;
            RetVal = E_OK;
            break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to process the Socket conncetion mode change 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_SoConModeChgOnlineHandler
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode,
    DoIP_ConIdxType ConIdx
)
{
    if (DoIP_ConCtrlGetIpAddrState(ConIdx) == SOAD_IPADDR_STATE_ASSIGNED)
    {
        /* If Ip address is assigned , update SoCon status */
        DoIP_ConCtrlSetSoConMode(ConIdx,Mode);
        DoIP_ConCtrlSetSoConCloseReq(ConIdx,FALSE);
        /* If connection idx is Udp then trigger vehicle announcement if needed */
        if(ConIdx >= DoIP_CfgGetNumOfUdpConnection())
        {
            (void)DoIP_TxUdpTransmit(ConIdx,DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT,
                                      DOIP_VEHICLE_ANNOUNCEMENT_COUNT,FALSE);
        }
    }
    DOIP_DUMMY_STATEMENT(SoConId);
}
/********************************************************************************************************************
* @brief  This api used to handle the socket connection mode offline
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_SoConModeChgOfflineHandler(SoAd_SoConModeType Mode,DoIP_ConIdxType ConIdx)
{
    /* update SoCon states */
    DoIP_ConCtrlSetSoConMode(ConIdx,Mode);
    DoIP_ConCtrlSetSoConCloseReq(ConIdx,FALSE);
    
    if (ConIdx < DoIP_CfgGetNumOfTcpConnection())
    {
        /* Handle TCP socket connection mode change to offline or reconnect. */
        DoIP_TcpSoConModeChgOfflineHandler(ConIdx);
    }
    else
    {
        /* Handle UDP socket connection mode change to offline or reconnect. */
        DoIP_UdpSoConModeChgOfflineHandler(ConIdx);
    }
}
/********************************************************************************************************************
* @brief  This api used to process the tcp socket connection mode changes
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TcpSoConModeChgOfflineHandler(DoIP_TcpConIdxType TcpConIdx)
{
    DoIP_TesterIdxType TesterIdx;
    
    TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);   
    if(TesterIdx < DoIP_CfgGetNumOfTester())
    {
        DoIP_TesterCtrlSetTcpConIdx(TcpConIdx,DoIP_CfgGetNumOfTcpConnection());
        /* Todo : DOIP_NACK_APPEND_REQ */
        DoIP_TesterCtrlSetNegativeAckOffset(TcpConIdx,0U);
    }
    /* Initialize the Tcp Connection ctrl status */
    DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
    DoIP_TcpConCtrlSetTesterAddr(TcpConIdx,DOIP_ADDR_ANY);
    DoIP_TcpConCtrlSetTesterIdx(TcpConIdx,DoIP_CfgGetNumOfTester());
    DoIP_TcpConCtrlSetRoutingActivationIdx(TcpConIdx,DoIP_CfgGetNumOfRoutingActivation());
    DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE);
    /* Initialize the Tcp connection Tx Ctrl status */
    DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,0U);
    DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,FALSE);
    DoIP_TcpConCtrlSetTxTpHeaderType(TcpConIdx,DOIP_HEADER_TYPE_INVALID);
    DoIP_TcpConCtrlSetTxTpCancelReq(TcpConIdx,FALSE);
    /* Initialize the Tcp connection Rx Ctrl status */
    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);      
    DoIP_TcpConCtrlSetRxTpSessionActive(TcpConIdx,FALSE);
    DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,FALSE);        
    DoIP_TcpConCtrlSetRxTpCancelReq(TcpConIdx,FALSE);
    /* Notify to cancel ongoing reception */
    if(DoIP_TcpConCtrlGetRxChannelActive(TcpConIdx) == TRUE)
    {
        PduR_DoIPTpRxIndication(DoIP_ChannelCfgGetRxPduId(DoIP_TcpConCtrlGetRxLastChannelIdx(TcpConIdx)),E_NOT_OK);
        DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,DoIP_CfgGetNumOfChannel()); 
        DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,FALSE);
    }
    
    /* Remove Tcp connection from Tx queue */
    while (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) > 0U)
    {
        DoIP_TxTcpQueueRemoveElement(TcpConIdx, E_NOT_OK);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp socket connection mode offline
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpSoConModeChgOfflineHandler(DoIP_ConIdxType ConIdx)
{
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx;
    /* clear pending tx */
    for(UdpTxCtrlIdx = 0u;UdpTxCtrlIdx < DoIP_CfgGetNumOfUdpTxCtrl();UdpTxCtrlIdx++)
    {
        if (DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx) == ConIdx)
        {
            #if (DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON)
            if (DoIP_UdpTxCtrlGetTxHeaderType(UdpTxCtrlIdx) == DOIP_HEADER_TYPE_OEM_SPECIFIC)
            {
                DoIP_OemPayloadCtrlSetUdpBufferLength(0U);
            }
            #endif
            DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx,DoIP_CfgGetNumOfConnection());
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to check whether the all the Socket connections are assigned to the SoAd connection
* @return status of the assignment E_OK: all connection are assigned E_NOT_OK: all connection are not assigned
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_IsSoConIdxAssignedForAllCon(void)
{
    DoIP_ConIdxType  ConIdx;
    Std_ReturnType   RetVal = E_OK;
    SoAd_SoConIdType SoConId = 0U;
    
    if (DoIP_ConCtrlGetSoConIdx(0U) == SOAD_SOCON_ID_INVALID)
    {
        for(ConIdx=0U; ConIdx<DoIP_CfgGetNumOfConnection(); ConIdx++)
        {
            if (DoIP_ConCtrlGetSoConIdx(ConIdx) == SOAD_SOCON_ID_INVALID)
            {
                if (SoAd_GetSoConId(DoIP_ConCfgGetTxPduId(ConIdx),&SoConId) == E_OK)
                {
                    DoIP_ConCtrlSetSoConIdx(ConIdx,SoConId);
                }
                else
                {
                    RetVal = E_NOT_OK;
                }
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the Socket conncetion states 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_HandleSoConStateHandler(void)
{
    DoIP_ConIdxType ConIdx;
    
    for (ConIdx = 0U; ConIdx < DoIP_CfgGetNumOfConnection(); ConIdx++)
    {
        /* Request SoCon open */
        if ((DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_OFFLINE) &&
            (DoIP_ConCtrlGetIpAddrState(ConIdx) == SOAD_IPADDR_STATE_ASSIGNED))
        {
            DoIP_ConCtrlSetSoConMode(ConIdx,SOAD_SOCON_RECONNECT);
            (void)SoAd_OpenSoCon(DoIP_ConCtrlGetSoConIdx(ConIdx));
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the active line state inactive
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConHandleActLineStateInactive(void)
{
    if (DoIP_ConSoConCloseAll() == E_OK)
    {
        DoIP_ConRelAllIpAddrAssign();
        DoIP_CtrlSetActivationLineInactiveReq(FALSE);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the close request for the socket connection 
* @return request status E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_ConSoConCloseAll(void)
{
    Std_ReturnType RetVal = E_OK;
    DoIP_ConIdxType ConIdx;

    for (ConIdx =0U;ConIdx <= DoIP_CfgGetNumOfConnection();ConIdx++)
    {
        if (DoIP_ConCtrlGetSoConMode(ConIdx) != SOAD_SOCON_OFFLINE)
        {
            if (DoIP_ConCtrlGetSoConCloseReq(ConIdx) != TRUE)
            {
                /* Request close */
                DoIP_ConCtrlSetSoConCloseReq(ConIdx,TRUE);
                DoIP_SoConClose(ConIdx);
            }
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the release all Ip address assignment
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConRelAllIpAddrAssign(void)
{
    DoIP_LocalAddrIdxType LocalAddrIdx;
    DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx;

    for(LocalAddrIdx =0U;LocalAddrIdx < DoIP_CfgGetNumOfLocalAddr();LocalAddrIdx++)
    {
        for(IpAddrAssignmentIdx = DoIP_LocalAddCfgGetIpAddrAssignmentStartIdx(LocalAddrIdx);
            IpAddrAssignmentIdx <= DoIP_LocalAddCfgGetIpAddrAssignmentEndIdx(LocalAddrIdx);IpAddrAssignmentIdx++)
        {
            if (DoIP_IpAddrAssignmentCfgGetIsIpAssignementEnabled(IpAddrAssignmentIdx) == TRUE)
            {
                DoIP_ConRelIpAddrAssign(LocalAddrIdx);
            }
            DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(IpAddrAssignmentIdx,DOIP_IP_ADDR_REQ_STATE_NONE);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the release Ip address assignment of the local addr idx
* @param[in] LocalAddrIdx the local address idx 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ConRelIpAddrAssign(DoIP_LocalAddrIdxType LocalAddrIdx)
{
    DoIP_ConIdxType ConIdx;
    /* Request to release ip addr */
    ConIdx = DoIP_LocalAddrToConMap[DoIP_LocalAddCfgGetConMapStartIdx(LocalAddrIdx)];
    (void)SoAd_ReleaseIpAddrAssignment(DoIP_ConCtrlGetSoConIdx(ConIdx));
}
/********************************************************************************************************************
* @brief  This api used to handle the local Ip address change for the connection Idx 
* @param[in] ConIdx the DoIP connection Idx
* @param[in] State the Ip address state type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChgHandler
(
    DoIP_ConIdxType ConIdx,
    SoAd_IpAddrStateType State
)
{
    DoIP_LocalIpAddrIdxType LocalIpAddrIdx;

    LocalIpAddrIdx = DoIP_ConCfgGetLocalIpAddrIdx(ConIdx);
    DoIP_ConCtrlSetIpAddrState(ConIdx,State);
    
    if (State == SOAD_IPADDR_STATE_UNASSIGNED)
    {
        DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx;
        /* set the assignement state as SOAD_IPADDR_STATE_UNASSIGNED */
        for(IpAddrAssignmentIdx = DoIP_LocalAddCfgGetIpAddrAssignmentStartIdx(LocalIpAddrIdx);
            IpAddrAssignmentIdx <= DoIP_LocalAddCfgGetIpAddrAssignmentEndIdx(LocalIpAddrIdx);IpAddrAssignmentIdx++)
        {
            DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(IpAddrAssignmentIdx,DOIP_IP_ADDR_REQ_STATE_NONE);
        }
        /* Request to close socket connection. */
        DoIP_SoConClose(ConIdx); 
        #if 0
        #if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
        /* Reset GID sync state if all IP addresses are unassigned (if GID sync is configured). */
        if (DoIP_LocalIpAddrAssignedCount > 0U )
        {
            DoIP_LocalIpAddrAssignedCount--;
            if ( DoIP_LocalIpAddrAssignedCount == 0U)
            {
                DoIP_GidInSync = FALSE;
            }
        }
        #endif
        #endif
    }
    else if (State == SOAD_IPADDR_STATE_ASSIGNED)
    {
        if (DoIP_CtrlGetActivationLineState() == DOIP_ACTIVATION_LINE_ACTIVE)
        {
            /* Request to open socket */
            if (DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_OFFLINE)
            {
                DoIP_ConCtrlSetSoConMode(ConIdx,SOAD_SOCON_RECONNECT);
                (void)SoAd_OpenSoCon(DoIP_ConCtrlGetSoConIdx(ConIdx));
            }
        }
        #if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
        DoIP_LocalIpAddrAssignedCount++;
        #endif
    }
    else
    {
        /* Do Nothing */
    }
}
/********************************************************************************************************************
* @brief  This api used to process the activation line active request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_ActivationLineStateActiveHandler(void)
{
    /* Handle IpAddress assigment */
    DoIP_IpAddrAssignmentHandler();
    /* Handle SoCon states */
    DoIP_HandleSoConStateHandler();
    /* Handle Gid sync */
    DoIP_GidSyncHandler();  
    /* Routing activation authentifications and confirmations Handler*/
    DoIP_RxTcpRoutHandleRetryRoutingActivationAuthAndConf();
    /* Handle pending UDP tx. */
    DoIP_TxUdpCtrlHandler();
    /* Tcp Queue transmit handler  */
    DoIP_TxTcpQueueHandleTransmit();
    /* Handle Alive check timing */
    DoIP_RxTcpRoutHandleAliveCheckTimeouts();
    DoIP_RxTcpRoutHandleInactivityTimeouts();
}
/********************************************************************************************************************
* @brief  This api used to process the Local Ip address assignement 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_IpAddrAssignmentHandler(void)
{
    DoIP_LocalIpAddrIdxType LocalIpAddrIdx;
    DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx;
    
    for (LocalIpAddrIdx = 0U; LocalIpAddrIdx < DoIP_CfgGetNumOfLocalAddr(); LocalIpAddrIdx++)
    {
        /* Check for all IpAddr Assignment for this local address */ 
        for(IpAddrAssignmentIdx = DoIP_LocalAddCfgGetIpAddrAssignmentStartIdx(LocalIpAddrIdx);
            IpAddrAssignmentIdx <= DoIP_LocalAddCfgGetIpAddrAssignmentEndIdx(LocalIpAddrIdx);IpAddrAssignmentIdx++)
        {
            /* if Ip address not yet assigned */
            if (DoIP_IpAddrAssignmentCtrlGetIpAddrReqState(IpAddrAssignmentIdx) == DOIP_IP_ADDR_REQ_STATE_NONE)
            {
                DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(IpAddrAssignmentIdx,DOIP_IP_ADDR_REQ_STATE_REQUESTED);
                if (DoIP_IpAddrAssignmentCfgGetIpAddrAssignmentType(IpAddrAssignmentIdx) == DOIP_IPADDR_ASSIGN_TYPE_DHCP)
                {
                    /* if assignment type is Dhcp , set Dhcp host name */
                    (void)DoIP_SetDhcpHostname(LocalIpAddrIdx);
                }
                
                if (DoIP_IpAddrAssignmentCfgGetIsIpAssignementEnabled(IpAddrAssignmentIdx) == TRUE)
                {
                    /* Request IP address assignment. */
                    if (E_NOT_OK == DoIP_RequestIpAddrAssignment(LocalIpAddrIdx,IpAddrAssignmentIdx))
                    {
                        DoIP_IpAddrAssignmentCtrlSetIpAddrReqState(IpAddrAssignmentIdx,DOIP_IP_ADDR_REQ_STATE_NONE);
                    }
                }
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to set the DHCP host name for the local address id
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_SetDhcpHostname(DoIP_LocalIpAddrIdxType LocalIpAddrIdx)
{
    Std_ReturnType RetVal;
    DoIP_ConIdxType ConIdx;
    uint8 HostNameSize;
    #if (DOIP_DHCP_OPTION_VIN_USE == STD_ON)
    uint8 HostName[DOIP_HOST_NAME_VIN_SIZE] = { 'D', 'o', 'I', 'P', '-', 'V', 'I', 'N' };
    uint8 HostNameIdx;
    #else
    uint8 HostName[DOIP_HOST_NAME_MIN_SIZE] = { 'D', 'o', 'I', 'P', '-' };
    #endif
    
    /* Todo : check the connection */
    ConIdx = LocalIpAddrIdx;
    #if (DOIP_DHCP_OPTION_VIN_USE == STD_ON)
    if(DoIP_CfgGetUserGetVinCallbackFn(&HostName[DOIP_HOST_NAME_VIN_PREFIX_SIZE]) != E_OK)
    {
        /* upadte invalid pattern if VIN not provided */
        for(HostNameIdx=DOIP_HOST_NAME_VIN_PREFIX_SIZE; HostNameIdx < DOIP_HOST_NAME_VIN_SIZE;HostNameIdx++)
        {
            HostName[HostNameIdx] = DOIP_VIN_INVALIDITY_PATTERN;
        }
    }
    HostNameSize = DOIP_HOST_NAME_VIN_SIZE;
    #else
    HostNameSize = DOIP_HOST_NAME_MIN_SIZE;
    #endif
    /*Request to set the Host name */
    RetVal = SoAd_WriteDhcpHostNameOption(DoIP_ConCtrlGetSoConIdx(ConIdx),HostNameSize,HostName);
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to request the ip address assignment for the local ip address idx 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RequestIpAddrAssignment
(   
    DoIP_LocalIpAddrIdxType  LocalIpAddrIdx,
    DoIP_IpAddrAssignmentIdxType IpAddrAssignmentIdx
)
{
    Std_ReturnType RetVal = E_OK;
    SoAd_SockAddrType LocalIpAddr;
    SoAd_SockAddrType DefaultRouter;
    DoIP_ConIdxType ConIdx;
    
    /* Todo : check the connection */
    ConIdx = LocalIpAddrIdx;
    switch (DoIP_IpAddrAssignmentCfgGetIpAddrAssignmentType(IpAddrAssignmentIdx))
    {
        case DOIP_IPADDR_ASSIGN_TYPE_STATIC:
            /* set address */
            LocalIpAddr.Domain = SOAD_AF_INET; 
            DefaultRouter.Domain = SOAD_AF_INET; 
            RetVal = SoAd_RequestIpAddrAssignment(DoIP_ConCtrlGetSoConIdx(ConIdx),SOAD_IPADDR_ASSIGNMENT_STATIC,
                                                  &LocalIpAddr,0U,&DefaultRouter);
            break;
        case DOIP_IPADDR_ASSIGN_TYPE_LINKLOCAL_DOIP:
            RetVal = SoAd_RequestIpAddrAssignment(DoIP_ConCtrlGetSoConIdx(ConIdx),
                                                SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP,NULL_PTR,0U,NULL_PTR);
            break;
        case DOIP_IPADDR_ASSIGN_TYPE_LINKLOCAL:
            RetVal = SoAd_RequestIpAddrAssignment(DoIP_ConCtrlGetSoConIdx(ConIdx),
                                                SOAD_IPADDR_ASSIGNMENT_LINKLOCAL,NULL_PTR,0U,NULL_PTR);
            break;
        case DOIP_IPADDR_ASSIGN_TYPE_DHCP:
            RetVal = SoAd_RequestIpAddrAssignment(DoIP_ConCtrlGetSoConIdx(ConIdx),
                                                SOAD_IPADDR_ASSIGNMENT_DHCP,NULL_PTR,0U,NULL_PTR);
            break;
        default:
            break;
    }
    return RetVal;
}
/* #! util mem copy */
/********************************************************************************************************************
* @brief     This Api used to copy data from source buffer to destination buffer
********************************************************************************************************************/
FUNC(void,DOIP_CODE) DoIP_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DestPtr, 
    CONSTP2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) SrcPtr, 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}
/********************************************************************************************************************
* @brief  This Api used to set requested data to the destination buffer
********************************************************************************************************************/
FUNC(void,DOIP_CODE) DoIP_UtilMemSet
(   
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DestPtr , 
    uint8 Value , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* Set [pSrc] to Value. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value;
    }
}

#define DOIP_STOP_SEC_CODE
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
*  @date    29-Dec-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

