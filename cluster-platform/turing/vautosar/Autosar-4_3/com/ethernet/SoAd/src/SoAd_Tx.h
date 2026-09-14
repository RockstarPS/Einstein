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
*   @file SoAd_Tx.h
*   @ingroup SoAd
*   @brief This file provides the declaration of the SoAd transmit API and data type. 
********************************************************************************************************************/
#ifndef SOAD_TX_H
#define SOAD_TX_H
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
*   @brief This Api is used to intialize the tx for the SoCon idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_TxSoConInit(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to intialize the tx properties
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxInit(void);
/*!******************************************************************************************************************
*   @brief This Api is used to intialize the Udp aliver timer
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UdpAliveTimerInit(void);
/*!******************************************************************************************************************
*   @brief This Api is used to intialize the Udp Npdu tx timer 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxUdpNPduTimerInit(void);
/*!******************************************************************************************************************
*   @brief This Api is used to update the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UpdateUdpAliveTimeout(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to start the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_StartUdpAliveTimeout(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the alive timer expiry for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UdpAliveTimeoutHandler(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to reset the the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SoConResetUdpAliveTimeout(SoAd_SoConIdType  SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to terminate the pending tx for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxTerminateTransmit(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to get the unconfirmed transmit data of the socket idx 
*   @param[in] SocketIdx the socket idx
*   @return the unconfirmed data length
********************************************************************************************************************/
FUNC(uint32, SOAD_CODE) SoAd_TxTcpGetUnconfirmedDataLength(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to process the transmit and confirmation handling in the main function
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxMainFunction(void);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SOAD_TX_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
