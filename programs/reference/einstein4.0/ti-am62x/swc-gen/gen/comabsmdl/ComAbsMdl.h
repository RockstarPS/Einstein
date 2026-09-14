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
*    @file ComAbsMdl.h
*    @ingroup ComAbsMdl
*    @brief This file contains the API provided by the ComAbsMdl.
*    Auto generated code in VTAMILAR at 2024-11-20 16:37:10.938021
********************************************************************************************************************/
#ifndef COMABSMDL_H_
#define COMABSMDL_H_

#include "Rte_CComAbsMdl.h"
#include "ComAbsMdl_TxCfg.h"
#include "ComAbsMdl_RxCfg.h"
# include "Rte_DataHandleType.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_CComAbsMdl_stubs.h"

#ifndef COMABSMDL_DUMMY_STATEMENT
#define COMABSMDL_DUMMY_STATEMENT(param)                  ((void)(param))
#endif

/********************************************************************************************************************
*   @brief   This method is used to set the signal confirmation status
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void ComAbsMdl_TxCan_SetCanSignalTxConfirmation(tTxSignalId SignalId);
/********************************************************************************************************************
*   @brief   This method is used to intialize the rx can variable
********************************************************************************************************************/
void ComAbsMdl_RxCanVarInit(void);
/********************************************************************************************************************
*   @brief   This method is used to tx can variable
********************************************************************************************************************/
void ComAbsMdl_TxCanVarInit(void);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void ComAbsMdl_ReloadMissingTimer(tRxSignalId SignalId);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
*   @param[in] pSignalValue	 pointer to signal value
*   @param[in] pSignalLength pointer to signal length
*   @return Std_ReturnType		pSignalLength
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_RxCanSetSignalValueU8Arr(tRxSignalId SignalId, const uint8 * pSignalValue,const uint32 *pSignalLength);
extern Std_ReturnType CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId,uint8 * pSignalValue,tRxSignalStatus *pSignalStatus);

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

#  ifndef eTxSigConfirmStatus_Cleared
#   define eTxSigConfirmStatus_Cleared (0U)
#  endif

#  ifndef eTxSigConfirmStatus_Set
#   define eTxSigConfirmStatus_Set (1U)
#  endif

#  ifndef eTxSigConfirmStatus_NotSupported
#   define eTxSigConfirmStatus_NotSupported (2U)
#  endif

#endif /* COMABSMDL_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/



