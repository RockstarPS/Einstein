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
*    @file ComAbsMdlSafe.h
*    @ingroup ComAbsMdlSafe
*    @brief This file contains the API provided by the ComAbsMdlSafe.
*    Auto generated code in ABASAVAR at 2025-11-14 16:05:41.216111
********************************************************************************************************************/
#ifndef COMABSMDLSAFE_H_
#define COMABSMDLSAFE_H_

#include "ComAbsMdlSafe_TxCfg.h"
#include "ComAbsMdlSafe_RxCfg.h"
#include "Rte_DataHandleType.h"
#include "ComAbsCtrl_cfg.h"

#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
#ifndef ComAbsMdlSafe_DUMMY_STATEMENT
#define ComAbsMdlSafe_DUMMY_STATEMENT(param) ((void)(param))
#endif

/********************************************************************************************************************
*   @brief   This method is used to set the signal confirmation status
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void ComAbsMdlSafeTxCan_SetCanSignalTxConfirmation(tSafeTxSignalId SignalId);
/********************************************************************************************************************
*   @brief   This method is used to intialize the rx can variable
********************************************************************************************************************/
void ComAbsMdlSafeRxCanVarInit(void);
/********************************************************************************************************************
*   @brief   This method is used to tx can variable
********************************************************************************************************************/
//void ComAbsMdlSafeTxCanVarInit(void);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void ComAbsMdlSafeReloadMissingTimer(tRxSafeSignalId SignalId);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
*   @param[in] pSignalValue	 pointer to signal value
*   @param[in] pSignalLength pointer to signal length
*   @return Std_ReturnType		pSignalLength
********************************************************************************************************************/
Std_ReturnType ComAbsMdlSafeRxCanSetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength);
uint8 ComAbsMdlSafe_RxCanSignalNRStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalMissingStatus[COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanJustRcvdStatus[COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignal_currentStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END

#include "MemMap.h"
#endif /* COMABSMDLSAFE_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/



