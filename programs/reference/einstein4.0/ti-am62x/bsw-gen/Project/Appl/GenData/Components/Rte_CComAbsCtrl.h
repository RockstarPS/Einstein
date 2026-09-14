/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CComAbsCtrl.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CComAbsCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSCTRL_H
# define _RTE_CCOMABSCTRL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CComAbsCtrl_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_ActivateSilentCommunication ComMExt_CAN_ActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_CommControlActivateRx ComMExt_CAN_CommControlActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_CommControlActivateTx ComMExt_CAN_CommControlActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_CommControlDeActivateRx ComMExt_CAN_CommControlDeActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_CommControlDeActivateTx ComMExt_CAN_CommControlDeActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlSetDone(Boolean PduInitRequest); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_CommControlSetDone(arg1) (ComMExt_CAN_CommControlSetDone(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_DeActivateSilentCommunication ComMExt_CAN_DeActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_GetCurrentComMode ComMExt_CAN_GetCurrentComMode
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_ReleaseCommunication ComMExt_CAN_ReleaseCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_CAN_RequestCommunication ComMExt_CAN_RequestCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_GetBusOffStatus(UInt8 Channel, P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) BusOffStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_GetBusOffStatus ComMExt_GetBusOffStatus
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_Get_MCAN_ERR_PIN_Status(P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) fl_pin_status_BOOL); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status ComMExt_Get_MCAN_ERR_PIN_Status
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSComMExt_Init() (ComMExt_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSTxCanMdl_TxCan_ClearCanSignalTxConfirmation(arg1) (CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, P2VAR(tTxSigConfirmStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation(arg1, arg2) (CComAbsMdl_TxCan_GetCanSignalTxConfirmation(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer CComAbsMdl_TxCan_SetSignalFromRetentionBuffer
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue CComAbsMdl_TxCan_SetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData, UInt32 SignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr CComAbsMdl_TxCan_SetSignalValueU8Arr
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalClearJustRcvdStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalInvalidProcessingControl(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalMissingProcessingControl(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalNRProcessingControl(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_TxCanMdlSafe_TxCan_ClearCanSignalTxConfirmation(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalFromRetentionBuffer(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_IoHwAb_Din_GetAsyncRawInput IoHwAb_GetAsyncRawInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_IoHwAb_Din_GetInputGroup IoHwAb_GetInputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) InputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput IoHwAb_GetProcessedInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_IoHwAb_Din_GetSyncRawInput IoHwAb_GetSyncRawInput


# endif /* !defined(RTE_CORE) */


# define CComAbsCtrl_START_SEC_CODE
# include "CComAbsCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CComAbsCtrl_CmpMain CComAbsCtrl_CmpMain
#  define RTE_RUNNABLE_CComAbsCtrl_Impl_MainFunction CComAbsCtrl_Impl_MainFunction
#  define RTE_RUNNABLE_CComAbsCtrl_Impl_OnCommand CComAbsCtrl_Impl_OnCommand
# endif

FUNC(void, CComAbsCtrl_CODE) CComAbsCtrl_CmpMain(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CComAbsCtrl_CODE) CComAbsCtrl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CComAbsCtrl_CODE) CComAbsCtrl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CComAbsCtrl_STOP_SEC_CODE
# include "CComAbsCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_ComMExt_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsTx_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSCTRL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
