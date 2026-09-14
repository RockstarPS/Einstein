/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDisplayCdd.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CDisplayCdd
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CDisplayCdd>
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

#include "Rte_CDisplayCdd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDisplayCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CDisplayCdd_TestDefines(void);


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
 * EDeviceStatus: Enumeration of integer in interval [0...5] with enumerators
 *   eDeviceNotReady (0U)
 *   eDeviceInitialized (1U)
 *   eDeviceReady (2U)
 *   eDeviceBusy (3U)
 *   eDeviceFault (4U)
 *   eDeviceMaxState (5U)
 * EDisplayCddStatus: Enumeration of integer in interval [0...4] with enumerators
 *   eDisplayNotReady (0U)
 *   eDisplayReady (1U)
 *   eDisplayBusy (2U)
 *   eDisplayFaultHandle (3U)
 *   eDisplayMaxStatus (4U)
 * EDisplayPower: Enumeration of integer in interval [0...2] with enumerators
 *   EDisplayPower_Off (0U)
 *   EDisplayPower_On (1U)
 *   EDisplayPower_Last (2U)
 * EDisplayPowerState: Enumeration of integer in interval [0...5] with enumerators
 *   eDisplayIdle (0U)
 *   eDisplayPowerON (1U)
 *   eDisplayNormal (2U)
 *   eDisplayPowerOFF (3U)
 *   eDisplayFault_Handle (4U)
 *   eDisplayMaxPowerState (5U)
 * EDisplayStatus: Enumeration of integer in interval [0...4] with enumerators
 *   EDisplayState_Off (0U)
 *   EDisplayState_On (1U)
 *   EDisplayState_Error (2U)
 *   EDisplayState_Disconnected (3U)
 *   EDisplayState_Last (4U)
 * EDisplayType: Enumeration of integer in interval [0...1] with enumerators
 *   e_Display10Inch (0U)
 *   e_DisplayMaxDevice (1U)
 * EGammaCorrectionStatus: Enumeration of integer in interval [0...3] with enumerators
 *   eDisplayCdd_GammaCorrection_None (0U)
 *   eDisplayCdd_GammaCorrection_OnGoing (1U)
 *   eDisplayCdd_GammaCorrection_Success (2U)
 *   eDisplayCdd_GammaCorrection_Failure (3U)
 * IoHwAb_DOutGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 *   eIO_DOutGroupIdCount (0)
 * IoHwAb_DOutSignalIdType: Enumeration of integer in interval [0...60] with enumerators
 *   eIO_DOUT_DO_5VSW2_3V3_EN (0U)
 *   eIO_DOUT_PARK_BRAKE_TT_OUT (1U)
 *   eIO_DOUT_DO_SYC1 (2U)
 *   eIO_DOUT_SEAT_BELT_TT_MCUOUT (3U)
 *   eIO_DOUT_TURN_LEFT_TT_MCUOUT (4U)
 *   eIO_DOUT_DO_LCD_BL_PWR_EN (5U)
 *   eIO_DOUT_DO_3V3_DISP_SW_EN (6U)
 *   eIO_DOUT_AMP_SHTD (7U)
 *   eIO_DOUT_FUEL_RHEO_SUP_EN (8U)
 *   eIO_DOUT_DO_LCD_STBYB (9U)
 *   eIO_DOUT_SBATT2_EN (10U)
 *   eIO_DOUT_BRAKE_TT_MCUOUT (11U)
 *   eIO_DOUT_AIRBAG_TT_MCUOUT (12U)
 *   eIO_DOUT_TURN_RIGHT_TT_MCUOUT (13U)
 *   eIO_DOUT_DO_SMPS_5V_SW_EN (14U)
 *   eIO_DOUT_PCS_OFF_TT_MCUOUT (15U)
 *   eIO_DOUT_ABS_TT_MCUOUT (16U)
 *   eIO_DOUT_SLIP_TT_MCUOUT (17U)
 *   eIO_DOUT_VCS_OFF_TT_MCUOUT (18U)
 *   eIO_DOUT_ECB_EPB_TT_MCUOUT (19U)
 *   eIO_DOUT_Flasher_FL_RL_OUT (20U)
 *   eIO_DOUT_Flasher_DEN1 (21U)
 *   eIO_DOUT_Flasher_DSEL1 (22U)
 *   eIO_DOUT_Flasher_FR_RR_OUT (23U)
 *   eIO_DOUT_DO_LCD_RST (24U)
 *   eIO_DOUT_DO_SMPS_1V2_EN (25U)
 *   eIO_DO_MAX (26U)
 *   eIO_DOUT_DO_DISP_RESET (27U)
 *   eIO_DOUT_DO_DISP_STBY (28U)
 *   eIO_DOUT_DO_TFT_BL_EN (29U)
 *   eIO_DOUT_DO_PWM_DIMMING (30U)
 *   eIO_DOUT_DO_RTC_INTN (31U)
 *   eIO_DOUT_DO_SOC_PWR_LATCH (32U)
 *   eIO_DOUT_DO_1V2_EN (33U)
 *   eIO_DOUT_DO_EN_5V (34U)
 *   eIO_DOUT_DO_ENET_EN (35U)
 *   eIO_DOUT_DO_LIN_NSLP (36U)
 *   eIO_DOUT_DO_MCU_RESETSTAZ (37U)
 *   eIO_DOUT_DO_3V3_DISP (38U)
 *   eIO_DOUT_DO_MD_TOUCH_RST (39U)
 *   eIO_DOUT_DO_VPP_EN (40U)
 *   eIO_DOUT_DO_MD_GNSS_BOOT_EN (41U)
 *   eIO_DOUT_DO_MD_GNSS_RESETP (42U)
 *   eIO_DOUT_DO_MD_GNSS_PWR_EN (43U)
 *   eIO_DOUT_DO_BLU_OPAMP_PWR_EN (44U)
 *   eIO_DOUT_DO_BLU_DWALED_EN (45U)
 *   eIO_DOUT_DO_TCON_BYPASS_MODE (46U)
 *   eIO_DOUT_DO_TCON_BYPASS_SEL0 (47U)
 *   eIO_DOUT_DO_TCON_BYPASS_SEL1 (48U)
 *   eIO_DOUT_DO_SOC_FPDLINK3_PDB (49U)
 *   eIO_DOUT_DO_SOC_FPDLINK3_INTB (50U)
 *   eIO_DOUT_DO_SOC_FPDLINK3_BISTEN (51U)
 *   eIO_DOUT_DO_ENET_RSTB (52U)
 *   eIO_DOUT_DO_EN_BUCK_FALD (53U)
 *   eIO_DOUT_DO_MCU_AMUX_S1 (54U)
 *   eIO_DOUT_DO_MCU_AMUX_S0 (55U)
 *   eIO_DOUT_DO_TCON_SPI0_CS0 (56U)
 *   eIO_DOUT_DO_SPI_CAN_CS (57U)
 *   eIO_DOUT_DESER_SPI1_DO (58U)
 *   eIO_DOUT_DO_SOC_TCON_GRBN (59U)
 *   eIO_DOUT_DO_TFT_CSB (60U)
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
 *
 * Record Types:
 * =============
 * SDisplayCurrentState: Record with elements
 *   displayId of type UInt32
 *   state of type EDisplayStatus
 * SDisplaySetPower: Record with elements
 *   displayId of type UInt32
 *   state of type EDisplayPower
 *
 *********************************************************************************************************************/


#define CDisplayCdd_START_SEC_CODE
#include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_GetGammaCorrectionStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetGammaCorrectionStatus> of PortPrototype <ppCS_DisplayCdd_GammaSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CDisplayCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_GetGammaCorrectionStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDisplayCdd_CODE) CDisplayCdd_GetGammaCorrectionStatus(P2VAR(EGammaCorrectionStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaCrStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_GetGammaCorrectionStatus
 *********************************************************************************************************************/

  CDisplayCdd_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_GetStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetStatus> of PortPrototype <pp_CS_DisplayCdd_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(const SDisplaySetPower *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Status_GetStatus(EDisplayType DeviceName, EDeviceStatus *DeviceStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Status_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDisplayCdd_GetStatus(EDisplayType DeviceId, EDisplayCddStatus *DeviceStatus, EDisplayPowerState *DisplayPowerState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Display_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_GetStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_GetStatus(EDisplayType DeviceId, P2VAR(EDisplayCddStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DeviceStatus, P2VAR(EDisplayPowerState, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DisplayPowerState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_GetStatus (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDisplayCurrentState Read_rpSRDisplayCurrentState_DisplayCurrentStateData;

  SDisplaySetPower Write_ppSRDisplaySetPower_DisplaySetPowerData;

  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus = 0U;
  EDeviceStatus Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDisplayCdd_Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(&Read_rpSRDisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_ppSRDisplaySetPower_DisplaySetPowerData, 0, sizeof(Write_ppSRDisplaySetPower_DisplaySetPowerData));
  fct_status = TSC_CDisplayCdd_Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(&Write_ppSRDisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(0, 0U, &Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(0U, 0U);
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
    case RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Status_GetStatus(0U, &Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus);
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
    case RTE_E_TI_Backlight_Status_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_I2cSeqEndCallback
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <I2cSeqEndCallback> of PortPrototype <ppCS_DisplayCdd_Cbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CDisplayCdd_I2cSeqEndCallback(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_I2cSeqEndCallback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDisplayCdd_CODE) CDisplayCdd_I2cSeqEndCallback(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_I2cSeqEndCallback
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_Impl_MainFunction
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
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(const SDisplaySetPower *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Status_GetStatus(EDisplayType DeviceName, EDeviceStatus *DeviceStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDisplayCdd_CODE) CDisplayCdd_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDisplayCurrentState Read_rpSRDisplayCurrentState_DisplayCurrentStateData;

  SDisplaySetPower Write_ppSRDisplaySetPower_DisplaySetPowerData;

  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus = 0U;
  EDeviceStatus Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDisplayCdd_Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(&Read_rpSRDisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_ppSRDisplaySetPower_DisplaySetPowerData, 0, sizeof(Write_ppSRDisplaySetPower_DisplaySetPowerData));
  fct_status = TSC_CDisplayCdd_Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(&Write_ppSRDisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(0, 0U, &Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(0U, 0U);
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
    case RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Status_GetStatus(0U, &Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus);
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
    case RTE_E_TI_Backlight_Status_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CDisplayCdd>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(const SDisplaySetPower *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Status_GetStatus(EDisplayType DeviceName, EDeviceStatus *DeviceStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Status_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CDisplayCdd_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDisplayCurrentState Read_rpSRDisplayCurrentState_DisplayCurrentStateData;

  SDisplaySetPower Write_ppSRDisplaySetPower_DisplaySetPowerData;

  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus = 0U;
  EDeviceStatus Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDisplayCdd_Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(&Read_rpSRDisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_ppSRDisplaySetPower_DisplaySetPowerData, 0, sizeof(Write_ppSRDisplaySetPower_DisplaySetPowerData));
  fct_status = TSC_CDisplayCdd_Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(&Write_ppSRDisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(0, 0U, &Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(0U, 0U);
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
    case RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Status_GetStatus(0U, &Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus);
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
    case RTE_E_TI_Backlight_Status_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_SetGammaCorrection
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetGammaCorrection> of PortPrototype <ppCS_DisplayCdd_GammaSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDisplayCdd_SetGammaCorrection(UInt8 *GmaSetPtr, UInt8 datalength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Display_GammaCorrection_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_SetGammaCorrection_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetGammaCorrection(P2VAR(UInt8, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaSetPtr, UInt8 datalength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_SetGammaCorrection (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDisplayCdd_SetState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetState> of PortPrototype <pp_CS_DisplayCdd_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(const SDisplaySetPower *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_SetDout_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_Status_GetStatus(EDisplayType DeviceName, EDeviceStatus *DeviceStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Status_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Display_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_SetState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDisplayCdd_SetState (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDisplayCurrentState Read_rpSRDisplayCurrentState_DisplayCurrentStateData;

  SDisplaySetPower Write_ppSRDisplaySetPower_DisplaySetPowerData;

  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus = 0U;
  EDeviceStatus Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDisplayCdd_Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(&Read_rpSRDisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_ppSRDisplaySetPower_DisplaySetPowerData, 0, sizeof(Write_ppSRDisplaySetPower_DisplaySetPowerData));
  fct_status = TSC_CDisplayCdd_Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(&Write_ppSRDisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(0, 0U, &Call_rpIoHwAb_SetDout_SetOutputGroup_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_SetDout_SetOutputPin_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_SetDout_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(0U, 0U);
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
    case RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Status_GetStatus(0U, &Call_rp_CS_Backlight_Status_GetStatus_DeviceStatus);
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
    case RTE_E_TI_Backlight_Status_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDisplayCdd_STOP_SEC_CODE
#include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CDisplayCdd_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  EDeviceStatus Test_EDeviceStatus_V_1 = eDeviceNotReady;
  EDeviceStatus Test_EDeviceStatus_V_2 = eDeviceInitialized;
  EDeviceStatus Test_EDeviceStatus_V_3 = eDeviceReady;
  EDeviceStatus Test_EDeviceStatus_V_4 = eDeviceBusy;
  EDeviceStatus Test_EDeviceStatus_V_5 = eDeviceFault;
  EDeviceStatus Test_EDeviceStatus_V_6 = eDeviceMaxState;

  EDisplayCddStatus Test_EDisplayCddStatus_V_1 = eDisplayNotReady;
  EDisplayCddStatus Test_EDisplayCddStatus_V_2 = eDisplayReady;
  EDisplayCddStatus Test_EDisplayCddStatus_V_3 = eDisplayBusy;
  EDisplayCddStatus Test_EDisplayCddStatus_V_4 = eDisplayFaultHandle;
  EDisplayCddStatus Test_EDisplayCddStatus_V_5 = eDisplayMaxStatus;

  EDisplayPower Test_EDisplayPower_V_1 = EDisplayPower_Off;
  EDisplayPower Test_EDisplayPower_V_2 = EDisplayPower_On;
  EDisplayPower Test_EDisplayPower_V_3 = EDisplayPower_Last;

  EDisplayPowerState Test_EDisplayPowerState_V_1 = eDisplayIdle;
  EDisplayPowerState Test_EDisplayPowerState_V_2 = eDisplayPowerON;
  EDisplayPowerState Test_EDisplayPowerState_V_3 = eDisplayNormal;
  EDisplayPowerState Test_EDisplayPowerState_V_4 = eDisplayPowerOFF;
  EDisplayPowerState Test_EDisplayPowerState_V_5 = eDisplayFault_Handle;
  EDisplayPowerState Test_EDisplayPowerState_V_6 = eDisplayMaxPowerState;

  EDisplayStatus Test_EDisplayStatus_V_1 = EDisplayState_Off;
  EDisplayStatus Test_EDisplayStatus_V_2 = EDisplayState_On;
  EDisplayStatus Test_EDisplayStatus_V_3 = EDisplayState_Error;
  EDisplayStatus Test_EDisplayStatus_V_4 = EDisplayState_Disconnected;
  EDisplayStatus Test_EDisplayStatus_V_5 = EDisplayState_Last;

  EDisplayType Test_EDisplayType_V_1 = e_Display10Inch;
  EDisplayType Test_EDisplayType_V_2 = e_DisplayMaxDevice;

  EGammaCorrectionStatus Test_EGammaCorrectionStatus_V_1 = eDisplayCdd_GammaCorrection_None;
  EGammaCorrectionStatus Test_EGammaCorrectionStatus_V_2 = eDisplayCdd_GammaCorrection_OnGoing;
  EGammaCorrectionStatus Test_EGammaCorrectionStatus_V_3 = eDisplayCdd_GammaCorrection_Success;
  EGammaCorrectionStatus Test_EGammaCorrectionStatus_V_4 = eDisplayCdd_GammaCorrection_Failure;

  IoHwAb_DOutGroupIdType Test_IoHwAb_DOutGroupIdType_V_1 = eIO_DOutGroupIdCount;

  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_1 = eIO_DOUT_DO_5VSW2_3V3_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_2 = eIO_DOUT_PARK_BRAKE_TT_OUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_3 = eIO_DOUT_DO_SYC1;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_4 = eIO_DOUT_SEAT_BELT_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_5 = eIO_DOUT_TURN_LEFT_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_6 = eIO_DOUT_DO_LCD_BL_PWR_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_7 = eIO_DOUT_DO_3V3_DISP_SW_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_8 = eIO_DOUT_AMP_SHTD;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_9 = eIO_DOUT_FUEL_RHEO_SUP_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_10 = eIO_DOUT_DO_LCD_STBYB;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_11 = eIO_DOUT_SBATT2_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_12 = eIO_DOUT_BRAKE_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_13 = eIO_DOUT_AIRBAG_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_14 = eIO_DOUT_TURN_RIGHT_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_15 = eIO_DOUT_DO_SMPS_5V_SW_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_16 = eIO_DOUT_PCS_OFF_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_17 = eIO_DOUT_ABS_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_18 = eIO_DOUT_SLIP_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_19 = eIO_DOUT_VCS_OFF_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_20 = eIO_DOUT_ECB_EPB_TT_MCUOUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_21 = eIO_DOUT_Flasher_FL_RL_OUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_22 = eIO_DOUT_Flasher_DEN1;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_23 = eIO_DOUT_Flasher_DSEL1;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_24 = eIO_DOUT_Flasher_FR_RR_OUT;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_25 = eIO_DOUT_DO_LCD_RST;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_26 = eIO_DOUT_DO_SMPS_1V2_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_27 = eIO_DO_MAX;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_28 = eIO_DOUT_DO_DISP_RESET;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_29 = eIO_DOUT_DO_DISP_STBY;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_30 = eIO_DOUT_DO_TFT_BL_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_31 = eIO_DOUT_DO_PWM_DIMMING;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_32 = eIO_DOUT_DO_RTC_INTN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_33 = eIO_DOUT_DO_SOC_PWR_LATCH;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_34 = eIO_DOUT_DO_1V2_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_35 = eIO_DOUT_DO_EN_5V;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_36 = eIO_DOUT_DO_ENET_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_37 = eIO_DOUT_DO_LIN_NSLP;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_38 = eIO_DOUT_DO_MCU_RESETSTAZ;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_39 = eIO_DOUT_DO_3V3_DISP;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_40 = eIO_DOUT_DO_MD_TOUCH_RST;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_41 = eIO_DOUT_DO_VPP_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_42 = eIO_DOUT_DO_MD_GNSS_BOOT_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_43 = eIO_DOUT_DO_MD_GNSS_RESETP;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_44 = eIO_DOUT_DO_MD_GNSS_PWR_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_45 = eIO_DOUT_DO_BLU_OPAMP_PWR_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_46 = eIO_DOUT_DO_BLU_DWALED_EN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_47 = eIO_DOUT_DO_TCON_BYPASS_MODE;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_48 = eIO_DOUT_DO_TCON_BYPASS_SEL0;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_49 = eIO_DOUT_DO_TCON_BYPASS_SEL1;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_50 = eIO_DOUT_DO_SOC_FPDLINK3_PDB;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_51 = eIO_DOUT_DO_SOC_FPDLINK3_INTB;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_52 = eIO_DOUT_DO_SOC_FPDLINK3_BISTEN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_53 = eIO_DOUT_DO_ENET_RSTB;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_54 = eIO_DOUT_DO_EN_BUCK_FALD;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_55 = eIO_DOUT_DO_MCU_AMUX_S1;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_56 = eIO_DOUT_DO_MCU_AMUX_S0;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_57 = eIO_DOUT_DO_TCON_SPI0_CS0;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_58 = eIO_DOUT_DO_SPI_CAN_CS;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_59 = eIO_DOUT_DESER_SPI1_DO;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_60 = eIO_DOUT_DO_SOC_TCON_GRBN;
  IoHwAb_DOutSignalIdType Test_IoHwAb_DOutSignalIdType_V_61 = eIO_DOUT_DO_TFT_CSB;

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
