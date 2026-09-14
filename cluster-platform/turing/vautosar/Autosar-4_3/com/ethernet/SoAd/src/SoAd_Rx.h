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
*   @file SoAd_Rx.h
*   @ingroup SoAd
*   @brief This file provides the declaration of the SoAd Receive API and data type. 
********************************************************************************************************************/
#ifndef SOAD_RX_H
#define SOAD_RX_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief This Api is used to initialize the rx properties of the SoCon
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxInitSoCon(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to indicate the start of Tp recepetion for the socket connection idx
*   @param[in] SoConIdx the socket connection idx
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpStartOfReception(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to terminate the pending reception
*   @param[in] SoConIdx the socket connection idx
*   @param[in] NormalClose TRUE: termination called by close request FALSE:termination called by other
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxTerminateReceive(SoAd_SoConIdType SoConIdx,boolean NormalClose);
/*!******************************************************************************************************************
*   @brief This Api is used to process the received data from the socket via SoAd_RxIndication
*   @param[in] SocketIdx the tcpip socket idx
*   @param[in] RemoteAddrPtr received data's remote addr 
*   @param[in] BufPtr pointer to the received data buffer
*   @param[in] Length the received data length
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxIndicationProcessing
( 
    SoAd_SocketIdxType SocketIdx,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) BufPtr,
    uint16 Length 
);
/*!******************************************************************************************************************
*   @brief This Api is used to process the reception in the main function
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxMainFunction(void);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SOAD_RX_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

