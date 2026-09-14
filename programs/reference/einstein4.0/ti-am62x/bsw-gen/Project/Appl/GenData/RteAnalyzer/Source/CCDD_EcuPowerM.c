/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CCDD_EcuPowerM.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CCDD_EcuPowerM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CCDD_EcuPowerM>
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

#include "Rte_CCDD_EcuPowerM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CCDD_EcuPowerM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CCDD_EcuPowerM_TestDefines(void);


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
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt16: Integer in interval [0...65535]
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
 * IoHwAb_AdcSignalIdType: Enumeration of integer in interval [0...17] with enumerators
 *   eIO_ADC_ADC_FUEL_5V_MON (16U)
 *   eIO_ADC_ADC_FUEL_MAIN (17U)
 *   eIO_ADC_IGN_AD (2U)
 *   eIO_ADC_FUEL_SEND_SUB_MICRO_AD (3U)
 *   eIO_ADC_AI_BATTERY (4U)
 *   eIO_ADC_AI_LCD_NTC (5U)
 *   eIO_ADC_AI_TEMP_RTC (6U)
 *   eIO_ADC_Flasher_Diag_sense_1 (7U)
 *   eIO_ADC_STR_SW2_ADIN (8U)
 *   eIO_ADC_STR_SW1_ADIN (9U)
 *   eIO_ADC_RHEO_SW_IN_ADIN (10U)
 *   eIO_ADC_ADC_RHEO_5V_MON_ADIN (11U)
 *   eIO_ADC_Flasher_Diag_sense_2 (12U)
 *   eIO_ADC_AdcChannel_Vdb (13U)
 *   eIO_ADC_AdcChannel_Vtemp (14U)
 *   eIO_ADC_MAX (15U)
 *   eIO_ADC_AI_SAMPLE_1 (0U)
 *   eIO_ADC_AI_SAMPLE_2 (1U)
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
 * IoHwAb_PwmSignalIdType: Enumeration of integer in interval [0...9] with enumerators
 *   eIO_PWM_MCU_BUZZER_AMPLCTRL (0U)
 *   eIO_PWM_HIGH_BEAM_TT_MCUOUT (1U)
 *   eIO_PWM_FUEL_TEMP_GAUG_TEXT_PWM_OUT (2U)
 *   eIO_PWM_PWM_OUT_ILL2 (3U)
 *   eIO_PWM_PWM_OUT_ILL1 (4U)
 *   eIO_PWM_BG_Dimming_PWM (5U)
 *   eIO_PWM_PWM_GREEN_TT_DIMMING (6U)
 *   eIO_PWM_CXPI_CLK (7U)
 *   eIO_PWM_PWM_LCD_BL_DIMMING (8U)
 *   eIO_PWM_MAX (9U)
 *
 *********************************************************************************************************************/


#define CCDD_EcuPowerM_START_SEC_CODE
#include "CCDD_EcuPowerM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCDD_EcuPowerM_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CCDD_EcuPowerM_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CCDD_EcuPowerM_CODE) CCDD_EcuPowerM_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCDD_EcuPowerM_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt16 Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rpIoHwAb_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(0, 0U, &Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(0U, &Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(0, &Call_rpIoHwAb_Din_GetInputGroup_SyncInput, &Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(0U, &Call_rpIoHwAb_Din_GetProcessedInput_InputSignal, &Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(0U, &Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(0U, 0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(0U, &Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  CCDD_EcuPowerM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCDD_EcuPowerM_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CCDD_EcuPowerM_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CCDD_EcuPowerM_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CCDD_EcuPowerM_CODE) CCDD_EcuPowerM_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCDD_EcuPowerM_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcuPowerM_GetDeviceStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EcuPowerM_GetDeviceStatus> of PortPrototype <ppCS_RequestPower>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuPowerM_GetDeviceStatus(UInt8 device, UInt8 *status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_EcuPowerM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuPowerM_GetDeviceStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CCDD_EcuPowerM_CODE) EcuPowerM_GetDeviceStatus(UInt8 device, P2VAR(UInt8, AUTOMATIC, RTE_CCDD_ECUPOWERM_APPL_VAR) status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuPowerM_GetDeviceStatus (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt16 Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rpIoHwAb_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(0, 0U, &Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(0U, &Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(0, &Call_rpIoHwAb_Din_GetInputGroup_SyncInput, &Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(0U, &Call_rpIoHwAb_Din_GetProcessedInput_InputSignal, &Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(0U, &Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(0U, 0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(0U, &Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
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
 * Runnable Entity Name: EcuPowerM_RequestPower
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EcuPowerM_RequestPower> of PortPrototype <ppCS_RequestPower>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_SetDout_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_PWM_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType EcuPowerM_RequestPower(UInt8 device, UInt8 request)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_EcuPowerM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuPowerM_RequestPower_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CCDD_EcuPowerM_CODE) EcuPowerM_RequestPower(UInt8 device, UInt8 request) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuPowerM_RequestPower (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt16 Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rpIoHwAb_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(0, 0U, &Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(0U, &Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(0, &Call_rpIoHwAb_Din_GetInputGroup_SyncInput, &Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(0U, &Call_rpIoHwAb_Din_GetProcessedInput_InputSignal, &Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(0U, &Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus);
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

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(0U, 0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(0U, &Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus);
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
    case RTE_E_TI_IOHWAB_PWM_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CCDD_EcuPowerM_STOP_SEC_CODE
#include "CCDD_EcuPowerM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CCDD_EcuPowerM_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_1 = eIO_ADC_ADC_FUEL_5V_MON;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_2 = eIO_ADC_ADC_FUEL_MAIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_3 = eIO_ADC_IGN_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_4 = eIO_ADC_FUEL_SEND_SUB_MICRO_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_5 = eIO_ADC_AI_BATTERY;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_6 = eIO_ADC_AI_LCD_NTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_7 = eIO_ADC_AI_TEMP_RTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_8 = eIO_ADC_Flasher_Diag_sense_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_9 = eIO_ADC_STR_SW2_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_10 = eIO_ADC_STR_SW1_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_11 = eIO_ADC_RHEO_SW_IN_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_12 = eIO_ADC_ADC_RHEO_5V_MON_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_13 = eIO_ADC_Flasher_Diag_sense_2;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_14 = eIO_ADC_AdcChannel_Vdb;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_15 = eIO_ADC_AdcChannel_Vtemp;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_16 = eIO_ADC_MAX;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_17 = eIO_ADC_AI_SAMPLE_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_18 = eIO_ADC_AI_SAMPLE_2;

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

  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_1 = eIO_PWM_MCU_BUZZER_AMPLCTRL;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_2 = eIO_PWM_HIGH_BEAM_TT_MCUOUT;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_3 = eIO_PWM_FUEL_TEMP_GAUG_TEXT_PWM_OUT;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_4 = eIO_PWM_PWM_OUT_ILL2;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_5 = eIO_PWM_PWM_OUT_ILL1;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_6 = eIO_PWM_BG_Dimming_PWM;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_7 = eIO_PWM_PWM_GREEN_TT_DIMMING;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_8 = eIO_PWM_CXPI_CLK;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_9 = eIO_PWM_PWM_LCD_BL_DIMMING;
  IoHwAb_PwmSignalIdType Test_IoHwAb_PwmSignalIdType_V_10 = eIO_PWM_MAX;
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
