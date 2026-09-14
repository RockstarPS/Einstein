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
*   @file SoAd_Internal.h
*   @ingroup SoAd
*   @brief This file provides the declaration of the SoAd internal API and data type. 
********************************************************************************************************************/
#ifndef SOAD_INTERNAL_H
#define SOAD_INTERNAL_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_Cfg.h"
#include "SoAd_Lcfg.h"
#include "SoAd_Types.h"
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
#ifndef SOAD_LOCAL 
#define SOAD_LOCAL  static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#ifndef SOAD_LOCAL_INLINE
#define SOAD_LOCAL_INLINE  LOCAL_INLINE
#endif

/*! @brief Defines the Det Report error API */
#define SoAd_DetReportError(ApiId,ErrId) (void)Det_ReportError(SOAD_MODULE_ID,SOAD_INSTANCE_ID,(ApiId),(ErrId))
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief This Api is used to request reconnect for the socket connection
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_SoConRequestReconnect(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to request close for the socket connection
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_SoConSetCloseReq(SoAd_SoConIdType SoConIdx,SoAd_SoConCloseReqType CloseReq);
/*!******************************************************************************************************************
*   @brief     This service used to copy data from source buffer to destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] SrcPtr pointer to source buffer data
*   @param[in] Length byte size to be copied
********************************************************************************************************************/
extern FUNC(void,SOAD_CODE) SoAd_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) SrcPtr , 
    PduLengthType Length
);
/*!******************************************************************************************************************
*   @brief This Api is used to get the socket connection Idx by the best match algorithm
*   @param[in] SoConGrpIdx the socket connection group idx
*   @param[in] SockAddrPtr the received socket address 
*   @param[in,out] SoConIdxPtr the pointer to update the best match socket connection idx
*   @return status of the request TRUE: Socket connection id found FALSE: Socket connection id not found 
********************************************************************************************************************/
extern FUNC(boolean, SOAD_CODE) SoAd_SoConGetSoConIdxByBestMatchAlgo
(
    SoAd_SoConGrpIdxType SoConGrpIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_CONST) SockAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to notify Socket connection mode changes to the users.
*   @param[in] SoConIdx the socket connection idx
*   @param[in] Mode the socket connection mode 
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_SoConNotifySoConModeChg(SoAd_SoConIdType SoConIdx,SoAd_SoConModeType Mode);
/*!******************************************************************************************************************
*   @brief This Api is used to check the states and open socket connection for reception 
*   @param[in] SoConIdx the socket connection idx
*   @param[in] RemoteAddrPtr the receive remote addr
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_SoConCheckStatesAndOpenSoConOnReception
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr
);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SOAD_INTERNAL_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

