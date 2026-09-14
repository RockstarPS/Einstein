/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CComAbsCtrl.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CComAbsCtrl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CComAbsCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CComAbsCtrl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CComAbsCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CComAbsCtrl_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * IoHwAb_DInGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 *   eIO_DInGroupIdCount (0)
 * IoHwAb_DInSignalIdType: Enumeration of integer in interval [0...29] with enumerators
 *   eIO_DIN_DI_AL_HAZARD (0U)
 *   eIO_DIN_DI_AH_IGNITION (1U)
 *   eIO_DIN_DI_SMPS_3V3_PG (2U)
 *   eIO_DIN_STOP_LAMP_MCU (3U)
 *   eIO_DIN_DI_AL_BRAKE_LEVEL (4U)
 *   eIO_DIN_DI_AL_OIL_W (5U)
 *   eIO_DIN_DI_AL_DRV_SEAT_BUCKLE (6U)
 *   eIO_DIN_DI_AL_WASHER_LEVEL_SW (7U)
 *   eIO_DIN_ODO_TripKnobInput (8U)
 *   eIO_DIN_DI_AL_VACUUM (9U)
 *   eIO_DIN_DI_LCD_BL_PWR_FAULT (10U)
 *   eIO_DIN_DI_AL_FUEL_LID_EFI_ECU (11U)
 *   eIO_DIN_DI_TT_SHIFT_ERR (12U)
 *   eIO_DIN_MAX (13U)
 *   eIO_DIN_DI_PMIC_INTN (14U)
 *   eIO_DIN_DI_MCU_PORZ (15U)
 *   eIO_DIN_DI_SBATT2_ERR (16U)
 *   eIO_DIN_DI_FALD_PG (17U)
 *   eIO_DIN_DI_MD_TOUCH_INTN (18U)
 *   eIO_DIN_DI_BL_FAULT (19U)
 *   eIO_DIN_DI_SOC_FPDLINK3_LOCK (20U)
 *   eIO_DIN_DI_SOC_FPDLINK3_PASS (21U)
 *   eIO_DIN_DI_ENET_MII_INT (22U)
 *   eIO_DIN_DI_IGN_MON (23U)
 *   eIO_DIN_DI_CABLE_DETECT (24U)
 *   eIO_DIN_DI_TCON_IND_OUT (25U)
 *   eIO_DIN_DI_SPI_CAN_TCON_SDI (26U)
 *   eIO_DIN_DI_MCU_FALD_CONN_CHK (27U)
 *   eIO_DIN_DI_LDO_1V2_FAULTN (28U)
 *   eIO_DIN_DI_TFT_ER_DET (29U)
 * IoHwAb_ErrorType: Enumeration of integer in interval [2...13] with enumerators
 *   E_NO_ERROR (2U)
 *   E_ERROR (3U)
 *   E_ADC_ERROR (4U)
 *   E_DOUT_ID_INVALID (5U)
 *   E_DIN_ID_INVALID (6U)
 *   E_ADC_ID_INVALID (7U)
 *   IOHWAB_E_ADC_ERROR (8U)
 *   IOHWAB_E_ADC_ID_INVALID (9U)
 *   IOHWAB_E_ERROR (10U)
 *   IOHWAB_E_DOUT_ID_INVALID (11U)
 *   IOHWAB_E_NO_ERROR (12U)
 *   IOHWAB_E_DIN_ID_INVALID (13U)
 * tRxSignalId: Enumeration of integer in interval [0...12] with enumerators
 *   eDayNightModeIn (0U)
 *   eIllumination_levelIn (1U)
 *   eAmbient_Light_levelIn (2U)
 *   ePowerModeIn (3U)
 *   eTransportModeIn (4U)
 *   eGearModeIn (5U)
 *   eGearRecommendationIn (6U)
 *   eGearIn (7U)
 *   eWarningIn (8U)
 *   eGearStatusIn (9U)
 *   eEngineSpeedIn (10U)
 *   eTurn_Indicator_ControlIn (11U)
 *   eEndOfRxSignal (12U)
 * tRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tRxSignalStatus: Enumeration of integer in interval [0...4] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (4U)
 * tSafeRxSignalId: Enumeration of integer in interval [0...4] with enumerators
 *   eVehicleSpeedABSIn (0U)
 *   eAirbagIn (1U)
 *   eAlive_101In (2U)
 *   eCRC_101In (3U)
 *   eEndOfSafeRxSignal (4U)
 * tSafeRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tSafeRxSignalStatus: Enumeration of integer in interval [0...6] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (3U)
 *   eSIGNAL_INVALID_CRC (4U)
 *   eSIGNAL_INVALID_ALIVE_COUNTER (5U)
 *   eSIGNAL_REPEATED (6U)
 * tSafeTxSignalId: Enumeration of integer in interval [0...3] with enumerators
 *   eBattery_VoltageOut (0U)
 *   eAlive_200Out (1U)
 *   eCRC_200Out (2U)
 *   eEndofSafeTxSignals (3U)
 * tTxSigConfirmStatus: Enumeration of integer in interval [0...2] with enumerators
 *   eTxSigConfirmStatus_Cleared (0U)
 *   eTxSigConfirmStatus_Set (1U)
 *   eTxSigConfirmStatus_NotSupported (2U)
 * tTxSignalId: Enumeration of integer in interval [0...49] with enumerators
 *   eSecureTxByte0Out (0U)
 *   eSecureTxByte1Out (1U)
 *   eSecureTxByte2Out (2U)
 *   eSecureTxByte3Out (3U)
 *   eMAC_TxOut (4U)
 *   eFV_TxOut (5U)
 *   eOdometerOut (6U)
 *   eVehicleSpeedICOut (7U)
 *   eIllumination_PWMOut (8U)
 *   eDebug1_Byte0Out (9U)
 *   eDebug1_Byte1Out (10U)
 *   eDebug1_Byte2Out (11U)
 *   eDebug1_Byte3Out (12U)
 *   eDebug1_Byte4Out (13U)
 *   eDebug1_Byte5Out (14U)
 *   eDebug1_Byte6Out (15U)
 *   eDebug1_Byte7Out (16U)
 *   eDebug2_Byte0Out (17U)
 *   eDebug2_Byte1Out (18U)
 *   eDebug2_Byte2Out (19U)
 *   eDebug2_Byte3Out (20U)
 *   eDebug2_Byte4Out (21U)
 *   eDebug2_Byte5Out (22U)
 *   eDebug2_Byte6Out (23U)
 *   eDebug2_Byte7Out (24U)
 *   eDebug3_Byte0Out (25U)
 *   eDebug3_Byte1Out (26U)
 *   eDebug3_Byte2Out (27U)
 *   eDebug3_Byte3Out (28U)
 *   eDebug3_Byte4Out (29U)
 *   eDebug3_Byte5Out (30U)
 *   eDebug3_Byte6Out (31U)
 *   eDebug3_Byte7Out (32U)
 *   eDebug4_Byte0Out (33U)
 *   eDebug4_Byte1Out (34U)
 *   eDebug4_Byte2Out (35U)
 *   eDebug4_Byte3Out (36U)
 *   eDebug4_Byte4Out (37U)
 *   eDebug4_Byte5Out (38U)
 *   eDebug4_Byte6Out (39U)
 *   eDebug4_Byte7Out (40U)
 *   eDebug5_Byte0Out (41U)
 *   eDebug5_Byte1Out (42U)
 *   eDebug5_Byte2Out (43U)
 *   eDebug5_Byte3Out (44U)
 *   eDebug5_Byte4Out (45U)
 *   eDebug5_Byte5Out (46U)
 *   eDebug5_Byte6Out (47U)
 *   eDebug5_Byte7Out (48U)
 *   eEndOfTxSignal (49U)
 *
 *********************************************************************************************************************/


#define CComAbsCtrl_START_SEC_CODE
#include "CComAbsCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsCtrl_CmpMain
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_CmpMain_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsCtrl_CODE) CComAbsCtrl_CmpMain(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_CmpMain
 *********************************************************************************************************************/

  CComAbsCtrl_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsCtrl_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_ActivateSilentCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_CommControlActivateRx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_CommControlActivateTx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_CommControlDeActivateRx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_CommControlDeActivateTx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_CommControlSetDone(Boolean PduInitRequest)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_ReleaseCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_CAN_RequestCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSComMExt_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSTxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_TxCanMdlSafe_TxCan_ClearCanSignalTxConfirmation(tSafeTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation(tSafeTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalFromRetentionBuffer(tSafeTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue(tSafeTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr(tSafeTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_IoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_IoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_IoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsCtrl_CODE) CComAbsCtrl_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt8 Call_rpCSComMExt_CAN_GetCurrentComMode_ComMode = 0U;
  Boolean Call_rpCSComMExt_GetBusOffStatus_BusOffStatus = FALSE;
  Boolean Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL = FALSE;
  UInt8 Call_rpCSRxCanMdl_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rpCSRxCanMdl_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rpCSRxCanMdl_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  tTxSigConfirmStatus Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rpCSTxCanMdl_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  UInt8 Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tSafeRxSignalJustRcvdStatus Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  tTxSigConfirmStatus Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  Boolean Call_rp_CS_IoHwAb_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rp_CS_IoHwAb_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rp_CS_IoHwAb_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rp_CS_IoHwAb_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rp_CS_IoHwAb_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rp_CS_IoHwAb_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rp_CS_IoHwAb_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rp_CS_IoHwAb_Din_GetSyncRawInput_ErrorStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_ActivateSilentCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlActivateRx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlActivateTx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlDeActivateRx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlDeActivateTx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlSetDone(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_DeActivateSilentCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_GetCurrentComMode(0U, &Call_rpCSComMExt_CAN_GetCurrentComMode_ComMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_ReleaseCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_RequestCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_GetBusOffStatus(0U, &Call_rpCSComMExt_GetBusOffStatus_BusOffStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status(&Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_Init();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(0U, &Call_rpCSRxCanMdl_RxCan_GetSignalValue_pSignalValue, &Call_rpCSRxCanMdl_RxCan_GetSignalValue_pSignalStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr(0U, &Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(0U, &Call_rpCSRxCanMdl_RxCan_SetSignalInitValue_pSignalValue);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr(0U, &Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalClearJustRcvdStatus(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus(0U, &Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation(0U, &Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(0U, &Call_rpCSTxCanMdl_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr(0U, &Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue(0U, &Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue_pSignalValue, &Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue_pSignalStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr(0U, &Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue(0U, &Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue_pSignalValue);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr(0U, &Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalClearJustRcvdStatus(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus(0U, &Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalInvalidProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalMissingProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalNRProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation(0U, &Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue(0U, &Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr(0U, &Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetAsyncRawInput(0U, &Call_rp_CS_IoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rp_CS_IoHwAb_Din_GetAsyncRawInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetInputGroup(0, &Call_rp_CS_IoHwAb_Din_GetInputGroup_SyncInput, &Call_rp_CS_IoHwAb_Din_GetInputGroup_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput(0U, &Call_rp_CS_IoHwAb_Din_GetProcessedInput_InputSignal, &Call_rp_CS_IoHwAb_Din_GetProcessedInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetSyncRawInput(0U, &Call_rp_CS_IoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rp_CS_IoHwAb_Din_GetSyncRawInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsCtrl_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CComAbsCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsCtrl_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsCtrl_CODE) CComAbsCtrl_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsCtrl_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CComAbsCtrl_STOP_SEC_CODE
#include "CComAbsCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CComAbsCtrl_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  IoHwAb_DInGroupIdType Test_IoHwAb_DInGroupIdType_V_1 = eIO_DInGroupIdCount;

  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_1 = eIO_DIN_DI_AL_HAZARD;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_2 = eIO_DIN_DI_AH_IGNITION;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_3 = eIO_DIN_DI_SMPS_3V3_PG;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_4 = eIO_DIN_STOP_LAMP_MCU;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_5 = eIO_DIN_DI_AL_BRAKE_LEVEL;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_6 = eIO_DIN_DI_AL_OIL_W;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_7 = eIO_DIN_DI_AL_DRV_SEAT_BUCKLE;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_8 = eIO_DIN_DI_AL_WASHER_LEVEL_SW;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_9 = eIO_DIN_ODO_TripKnobInput;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_10 = eIO_DIN_DI_AL_VACUUM;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_11 = eIO_DIN_DI_LCD_BL_PWR_FAULT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_12 = eIO_DIN_DI_AL_FUEL_LID_EFI_ECU;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_13 = eIO_DIN_DI_TT_SHIFT_ERR;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_14 = eIO_DIN_MAX;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_15 = eIO_DIN_DI_PMIC_INTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_16 = eIO_DIN_DI_MCU_PORZ;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_17 = eIO_DIN_DI_SBATT2_ERR;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_18 = eIO_DIN_DI_FALD_PG;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_19 = eIO_DIN_DI_MD_TOUCH_INTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_20 = eIO_DIN_DI_BL_FAULT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_21 = eIO_DIN_DI_SOC_FPDLINK3_LOCK;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_22 = eIO_DIN_DI_SOC_FPDLINK3_PASS;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_23 = eIO_DIN_DI_ENET_MII_INT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_24 = eIO_DIN_DI_IGN_MON;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_25 = eIO_DIN_DI_CABLE_DETECT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_26 = eIO_DIN_DI_TCON_IND_OUT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_27 = eIO_DIN_DI_SPI_CAN_TCON_SDI;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_28 = eIO_DIN_DI_MCU_FALD_CONN_CHK;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_29 = eIO_DIN_DI_LDO_1V2_FAULTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_30 = eIO_DIN_DI_TFT_ER_DET;

  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_1 = E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_2 = E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_3 = E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_4 = E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_5 = E_DIN_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_6 = E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_7 = IOHWAB_E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_8 = IOHWAB_E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_9 = IOHWAB_E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_10 = IOHWAB_E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_11 = IOHWAB_E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_12 = IOHWAB_E_DIN_ID_INVALID;

  tRxSignalId Test_tRxSignalId_V_1 = eDayNightModeIn;
  tRxSignalId Test_tRxSignalId_V_2 = eIllumination_levelIn;
  tRxSignalId Test_tRxSignalId_V_3 = eAmbient_Light_levelIn;
  tRxSignalId Test_tRxSignalId_V_4 = ePowerModeIn;
  tRxSignalId Test_tRxSignalId_V_5 = eTransportModeIn;
  tRxSignalId Test_tRxSignalId_V_6 = eGearModeIn;
  tRxSignalId Test_tRxSignalId_V_7 = eGearRecommendationIn;
  tRxSignalId Test_tRxSignalId_V_8 = eGearIn;
  tRxSignalId Test_tRxSignalId_V_9 = eWarningIn;
  tRxSignalId Test_tRxSignalId_V_10 = eGearStatusIn;
  tRxSignalId Test_tRxSignalId_V_11 = eEngineSpeedIn;
  tRxSignalId Test_tRxSignalId_V_12 = eTurn_Indicator_ControlIn;
  tRxSignalId Test_tRxSignalId_V_13 = eEndOfRxSignal;

  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tRxSignalStatus Test_tRxSignalStatus_V_1 = eSIGNAL_OK;
  tRxSignalStatus Test_tRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tRxSignalStatus Test_tRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tRxSignalStatus Test_tRxSignalStatus_V_4 = eSIGNAL_INVALID;

  tSafeRxSignalId Test_tSafeRxSignalId_V_1 = eVehicleSpeedABSIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_2 = eAirbagIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_3 = eAlive_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_4 = eCRC_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_5 = eEndOfSafeRxSignal;

  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_1 = eSIGNAL_OK;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_4 = eSIGNAL_INVALID;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_5 = eSIGNAL_INVALID_CRC;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_6 = eSIGNAL_INVALID_ALIVE_COUNTER;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_7 = eSIGNAL_REPEATED;

  tSafeTxSignalId Test_tSafeTxSignalId_V_1 = eBattery_VoltageOut;
  tSafeTxSignalId Test_tSafeTxSignalId_V_2 = eAlive_200Out;
  tSafeTxSignalId Test_tSafeTxSignalId_V_3 = eCRC_200Out;
  tSafeTxSignalId Test_tSafeTxSignalId_V_4 = eEndofSafeTxSignals;

  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_1 = eTxSigConfirmStatus_Cleared;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_2 = eTxSigConfirmStatus_Set;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_3 = eTxSigConfirmStatus_NotSupported;

  tTxSignalId Test_tTxSignalId_V_1 = eSecureTxByte0Out;
  tTxSignalId Test_tTxSignalId_V_2 = eSecureTxByte1Out;
  tTxSignalId Test_tTxSignalId_V_3 = eSecureTxByte2Out;
  tTxSignalId Test_tTxSignalId_V_4 = eSecureTxByte3Out;
  tTxSignalId Test_tTxSignalId_V_5 = eMAC_TxOut;
  tTxSignalId Test_tTxSignalId_V_6 = eFV_TxOut;
  tTxSignalId Test_tTxSignalId_V_7 = eOdometerOut;
  tTxSignalId Test_tTxSignalId_V_8 = eVehicleSpeedICOut;
  tTxSignalId Test_tTxSignalId_V_9 = eIllumination_PWMOut;
  tTxSignalId Test_tTxSignalId_V_10 = eDebug1_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_11 = eDebug1_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_12 = eDebug1_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_13 = eDebug1_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_14 = eDebug1_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_15 = eDebug1_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_16 = eDebug1_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_17 = eDebug1_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_18 = eDebug2_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_19 = eDebug2_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_20 = eDebug2_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_21 = eDebug2_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_22 = eDebug2_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_23 = eDebug2_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_24 = eDebug2_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_25 = eDebug2_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_26 = eDebug3_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_27 = eDebug3_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_28 = eDebug3_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_29 = eDebug3_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_30 = eDebug3_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_31 = eDebug3_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_32 = eDebug3_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_33 = eDebug3_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_34 = eDebug4_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_35 = eDebug4_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_36 = eDebug4_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_37 = eDebug4_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_38 = eDebug4_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_39 = eDebug4_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_40 = eDebug4_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_41 = eDebug4_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_42 = eDebug5_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_43 = eDebug5_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_44 = eDebug5_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_45 = eDebug5_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_46 = eDebug5_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_47 = eDebug5_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_48 = eDebug5_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_49 = eDebug5_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_50 = eEndOfTxSignal;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
