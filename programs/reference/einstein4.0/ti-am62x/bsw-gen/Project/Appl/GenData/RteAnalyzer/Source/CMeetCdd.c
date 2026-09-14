/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CMeetCdd.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CMeetCdd
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CMeetCdd>
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

#include "Rte_CMeetCdd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CMeetCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CMeetCdd_TestDefines(void);


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
 * Rte_DT_Arr_u16_7_0: Integer in interval [0...65535]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_10_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_17_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_3_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_46_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_61_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_9_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
 * Rte_DT_data_u8_256_0: Integer in interval [0...255]
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
 * EDcmExtAction: Enumeration of integer in interval [0...8] with enumerators
 *   eDcmExtAction_Read (0U)
 *   eDcmExtAction_Write (1U)
 *   eDcmExtAction_IOCtrl (2U)
 *   eDcmExtAction_RetCtrlEcu (3U)
 *   eDcmExtAction_RoutineStart (4U)
 *   eDcmExtAction_RoutineStop (5U)
 *   eDcmExtAction__RoutineResult (6U)
 *   eDcmExtAction_CheckConditions (7U)
 *   eDcmExtAction_Reset (8U)
 * EDidType: Enumeration of integer in interval [0...2] with enumerators
 *   EDidType_Read (0U)
 *   EDidType_Write (1U)
 *   EDidType_Last (2U)
 * EIOCtrlOptType: Enumeration of integer in interval [0...4] with enumerators
 *   EIOCtrlOptType_returnControlToECU (0U)
 *   EIOCtrlOptType_resetToDefault (1U)
 *   EIOCtrlOptType_freezeCurrentState (2U)
 *   EIOCtrlOptType_shortTermAdjustment (3U)
 *   EIOCtrlOptType_Last (4U)
 * EMeetModeStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eManufModeActive (0U)
 *   eManufModeInActive (1U)
 * ERoutineType: Enumeration of integer in interval [0...3] with enumerators
 *   ERoutineType_Start (0U)
 *   ERoutineType_Stop (1U)
 *   ERoutineType_QueryResults (2U)
 *   ERoutineType_Last (3U)
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
 * teDIDOperation: Enumeration of integer in interval [0...7] with enumerators
 *   eRead (0U)
 *   eWrite (1U)
 *   eSTA (2U)
 *   eRCTECU (3U)
 *   eCheckConditions (4U)
 *   eRST2DEFAULT (5U)
 *   eFCS (6U)
 *   eLengthCheck (7U)
 * teDiagOpStatus: Enumeration of integer in interval [0...64] with enumerators
 *   DIAG_INITIAL (0U)
 *   DIAG_PENDING (1U)
 *   DIAG_CANCEL (2U)
 *   DIAG_FORCE_RCRRP_OK (3U)
 *   DIAG_FORCE_RCRRP_NOT_OK (64U)
 * teRoutineOperation: Enumeration of integer in interval [0...2] with enumerators
 *   eRoutineStart (0U)
 *   eRoutineStop (1U)
 *   eRoutineResult (2U)
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_10: Array with 10 element(s) of type Rte_DT_Arr_u8_10_0
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_17: Array with 17 element(s) of type Rte_DT_Arr_u8_17_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * Arr_u8_3: Array with 3 element(s) of type Rte_DT_Arr_u8_3_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_46: Array with 46 element(s) of type Rte_DT_Arr_u8_46_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_61: Array with 61 element(s) of type Rte_DT_Arr_u8_61_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Arr_u8_9: Array with 9 element(s) of type Rte_DT_Arr_u8_9_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 * data_u8_256: Array with 256 element(s) of type Rte_DT_data_u8_256_0
 *
 * Record Types:
 * =============
 * SDiagDIDRequest: Record with elements
 *   did of type UInt16
 *   didType of type EDidType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagIOCtrlRequest: Record with elements
 *   did of type UInt16
 *   optionCtrl of type EIOCtrlOptType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagResponse: Record with elements
 *   responseCode of type UInt8
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagRoutineRequest: Record with elements
 *   routineId of type UInt16
 *   routineType of type ERoutineType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 *
 *********************************************************************************************************************/


#define CMeetCdd_START_SEC_CODE
#include "CMeetCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_DID_DiagAction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DID_DiagAction> of PortPrototype <pp_CS_DID_DiagAction>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, UInt8 *Data, UInt8 *pNrc, teDIDOperation eOperation)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_DID_DiagAction_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_DID_DiagAction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teDIDOperation eOperation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_DID_DiagAction (returns application error)
 *********************************************************************************************************************/

  CMeetCdd_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_Impl_MainFunction
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
 *   Std_ReturnType Rte_Receive_rSR_DiagResponse_DiagResponseData(SDiagResponse *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Audio_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Communication_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Power_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Warning_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Audio_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Communication_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Display_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Power_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Warning_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Warning_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagDIDRequest_DiagDIDRequestData(const SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Send_pSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(const SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Send_pSR_DiagRoutineRequest_DiagRoutineRequestData(const SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Write_pp_SR_SleepReq_SleepReqData(Boolean data)
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
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
 *     Argument BsConst_Audio_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte)
 *     Argument BsConst_BsConst_Illumination_ReservedByte: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)
 *     Argument BsConst_BsConst_Illumination_ReservedByte_SafeCopy1: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)
 *     Argument BsConst_BsConst_Illumination_ReservedByte_SafeCopy2: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
 *     Argument BsConst_Communication_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
 *     Argument BsConst_EngOffTimer_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
 *     Argument BsConst_FuelGauge_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
 *     Argument BsConst_OilGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
 *     Argument BsConst_PowerGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
 *     Argument BsConst_Power_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
 *     Argument BsConst_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
 *     Argument BsConst_ServiceReminder_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
 *     Argument BsConst_SpeedoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
 *     Argument BsConst_TachoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
 *     Argument BsConst_TempGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv)
 *     Argument BsConst_Temperature_Sensor_Conv: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy1)
 *     Argument BsConst_Temperature_Sensor_Conv_SafeCopy1: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy2)
 *     Argument BsConst_Temperature_Sensor_Conv_SafeCopy2: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
 *     Argument BsConst_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
 *     Argument BsConst_Warning_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
 *     Argument BsCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
 *     Argument BsDiag_Dtc_Element: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
 *     Argument BsDiag_ErrorRecord_Element: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
 *     Argument BsReten_Audio_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
 *     Argument BsReten_Communication_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
 *     Argument BsReten_Display_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
 *     Argument BsReten_Gauges_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
 *     Argument BsReten_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
 *     Argument BsReten_Odometer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
 *     Argument BsReten_Personalization_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
 *     Argument BsReten_Power_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
 *     Argument BsReten_RealTimeClock_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
 *     Argument BsReten_Tripcomputer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
 *     Argument BsReten_Warning_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
 *     Argument BsRt_CusDlt_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
 *     Argument BsRt_FuelGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
 *     Argument BsRt_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
 *     Argument BsRt_Odometer_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
 *     Argument BsRt_OilGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
 *     Argument BsRt_Personalization_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
 *     Argument BsRt_PowerGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
 *     Argument BsRt_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
 *     Argument BsRt_SpeedoGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
 *     Argument BsRt_TachoGauge_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
 *     Argument BsRt_TempGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
 *     Argument BsRt_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
 *     Argument BsRt_Warning_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyManufacturingDate)
 *     Argument BsShare_AssemblyManufacturingDate: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyPlantNumber)
 *     Argument BsShare_AssemblyPlantNumber: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_61_0 *BsShare_EcuPartNumber_Element)
 *     Argument BsShare_EcuPartNumber_Element: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(UInt16 BsShare_HWModification)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(const Rte_DT_Arr_u8_9_0 *BsShare_PCBSerialNumber)
 *     Argument BsShare_PCBSerialNumber: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(const Rte_DT_Arr_u8_10_0 *BsShare_ProductSerialNumber)
 *     Argument BsShare_ProductSerialNumber: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_SMTManufacturingDate)
 *     Argument BsShare_SMTManufacturingDate: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_SMTPlantNumber)
 *     Argument BsShare_SMTPlantNumber: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
 *     Argument BsShare_SwUpdFotaFinPrint_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
 *     Argument BsShare_SwUpdFotaMode_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
 *     Argument BsShare_SwUpdFotaStatus_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
 *     Argument BsShare_SwUpdFotadecrypt_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
 *     Argument BsShare_SwUpdReflash_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
 *     Argument BsShare_VehicleConfig_Element: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_46_0 *BsShare_VisMeet_Element)
 *     Argument BsShare_VisMeet_Element: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPCBPartNumber)
 *     Argument BsShare_VisteonPCBPartNumber: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPartNumber)
 *     Argument BsShare_VisteonPartNumber: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
 *     Argument RefCys_Certicificate1_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
 *     Argument RefCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CMeetCdd_CODE) CMeetCdd_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagResponse Receive_rSR_DiagResponse_DiagResponseData;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Audio_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Communication_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Power_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsConst_Warning_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Audio_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Communication_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Display_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Gauges_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Illumination_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Odometer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Personalization_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Power_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsReten_Warning_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_Illumination_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_Odometer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_Personalization_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsRt_Warning_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber;
  UInt8 Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element;
  UInt8 Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element;

  SDiagDIDRequest Send_pSR_DiagDIDRequest_DiagDIDRequestData = {
  0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SDiagIOCtrlRequest Send_pSR_DiagIOCtrlRequest_DiagIOCtrlRequestData = {
  0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SDiagRoutineRequest Send_pSR_DiagRoutineRequest_DiagRoutineRequestData = {
  0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

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
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr = 0U;
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr = 0U;
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr = 0U;
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_2048 Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_1024 Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_61 Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr = 0U;
  Arr_u8_9 Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_10 Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_256 Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr = 0U;
  Arr_u8_46 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element_BsConst_Audio_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_BsConst_BsConst_Illumination_ReservedByte = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element_BsConst_Communication_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element_BsConst_EngOffTimer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element_BsConst_FuelGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_BsConst_Lookup_Curve_HotSpot_Coef_X = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_BsConst_Lookup_Curve_HotSpot_Coef_Y = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element_BsConst_OilGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_BsConst_PCB_Temperature_Sensor_Conv = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 = {
  0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element_BsConst_PowerGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element_BsConst_Power_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element_BsConst_RealTimeClock_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element_BsConst_ServiceReminder_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element_BsConst_SpeedoGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element_BsConst_TachoGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element_BsConst_TempGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_BsConst_Temperature_Sensor_Conv = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1_BsConst_Temperature_Sensor_Conv_SafeCopy1 = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2_BsConst_Temperature_Sensor_Conv_SafeCopy2 = {
  0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element_BsConst_TripComputer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element_BsConst_Warning_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element_BsCys_Certicificate_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_2048 Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element_BsDiag_Dtc_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_1024 Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element_BsDiag_ErrorRecord_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element_BsReten_Audio_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element_BsReten_Communication_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element_BsReten_Display_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element_BsReten_Gauges_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element_BsReten_Illumination_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element_BsReten_Odometer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element_BsReten_Personalization_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element_BsReten_Power_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element_BsReten_RealTimeClock_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element_BsReten_Tripcomputer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element_BsReten_Warning_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element_BsRt_CusDlt_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element_BsRt_FuelGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element_BsRt_Illumination_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element_BsRt_Odometer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element_BsRt_OilGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element_BsRt_Personalization_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element_BsRt_PowerGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element_BsRt_RealTimeClock_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element_BsRt_SpeedoGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element_BsRt_TachoGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element_BsRt_TempGauge_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element_BsRt_TripComputer_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element_BsRt_Warning_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate_BsShare_AssemblyManufacturingDate = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber_BsShare_AssemblyPlantNumber = {
  0U, 0U, 0U
};
  Arr_u8_61 Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element_BsShare_EcuPartNumber_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_9 Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber_BsShare_PCBSerialNumber = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_10 Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber_BsShare_ProductSerialNumber = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate_BsShare_SMTManufacturingDate = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber_BsShare_SMTPlantNumber = {
  0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element_BsShare_SwUpdFotaFinPrint_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element_BsShare_SwUpdFotaMode_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element_BsShare_SwUpdFotaStatus_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element_BsShare_SwUpdFotadecrypt_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element_BsShare_SwUpdReflash_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_256 Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element_BsShare_VehicleConfig_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_46 Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element_BsShare_VisMeet_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber_BsShare_VisteonPCBPartNumber = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber_BsShare_VisteonPartNumber = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element_RefCys_Certicificate1_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element_RefCys_Certicificate_Element = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CMeetCdd_Rte_Receive_rSR_DiagResponse_DiagResponseData(&Receive_rSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Audio_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_Audio_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte(&Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Communication_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_Communication_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable(&Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level(&Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv(&Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty(&Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Power_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_Power_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2(&Read_rp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsConst_Warning_Element(&Read_rp_SR_JobStatus_JobStatus_BsConst_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(&Read_rp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(&Read_rp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(&Read_rp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Audio_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Audio_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Communication_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Communication_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Display_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Display_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Gauges_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Illumination_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Odometer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Personalization_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Power_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Power_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsReten_Warning_Element(&Read_rp_SR_JobStatus_JobStatus_BsReten_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_Illumination_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_Odometer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_Personalization_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsRt_Warning_Element(&Read_rp_SR_JobStatus_JobStatus_BsRt_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(&Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification(&Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(&Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(&Read_rp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(&Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(&Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(&Read_rp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Send_pSR_DiagDIDRequest_DiagDIDRequestData(&Send_pSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Send_pSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Send_pSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Send_pSR_DiagRoutineRequest_DiagRoutineRequestData(&Send_pSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Write_pp_SR_SleepReq_SleepReqData(Rte_InitValue_pp_SR_SleepReq_SleepReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(0, 0U, &Call_rpIoHwAb_DOut_SetOutputGroup_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_DOut_SetOutputPin(0U, FALSE, &Call_rpIoHwAb_DOut_SetOutputPin_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(0U, &Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_Din_GetInputGroup(0, &Call_rpIoHwAb_Din_GetInputGroup_SyncInput, &Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_Din_GetProcessedInput(0U, &Call_rpIoHwAb_Din_GetProcessedInput_InputSignal, &Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(0U, &Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDuty_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(0U, 0U, 0U, &Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(0U, &Call_rpIoHwAb_PWM_PwmSetIdeal_ErrorStatus);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(&Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(&Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr);
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
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element_BsConst_Audio_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte(Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_BsConst_BsConst_Illumination_ReservedByte);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element_BsConst_Communication_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element_BsConst_EngOffTimer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element_BsConst_FuelGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_BsConst_Lookup_Curve_HotSpot_Coef_X);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_BsConst_Lookup_Curve_HotSpot_Coef_Y);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element_BsConst_OilGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv(Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_BsConst_PCB_Temperature_Sensor_Conv);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element_BsConst_PowerGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element_BsConst_Power_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element_BsConst_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element_BsConst_ServiceReminder_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element_BsConst_SpeedoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element_BsConst_TachoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element_BsConst_TempGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv(Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_BsConst_Temperature_Sensor_Conv);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1_BsConst_Temperature_Sensor_Conv_SafeCopy1);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2_BsConst_Temperature_Sensor_Conv_SafeCopy2);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element_BsConst_TripComputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element_BsConst_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element_BsCys_Certicificate_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element_BsDiag_Dtc_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element_BsDiag_ErrorRecord_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element_BsReten_Audio_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element_BsReten_Communication_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element_BsReten_Display_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element_BsReten_Gauges_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element_BsReten_Illumination_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element_BsReten_Odometer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element_BsReten_Personalization_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element_BsReten_Power_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element_BsReten_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element_BsReten_Tripcomputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element_BsReten_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element_BsRt_CusDlt_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element_BsRt_FuelGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element_BsRt_Illumination_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element_BsRt_Odometer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element_BsRt_OilGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element_BsRt_Personalization_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element_BsRt_PowerGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element_BsRt_RealTimeClock_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element_BsRt_SpeedoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element_BsRt_TachoGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element_BsRt_TempGauge_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element_BsRt_TripComputer_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element_BsRt_Warning_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate_BsShare_AssemblyManufacturingDate);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber_BsShare_AssemblyPlantNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element_BsShare_EcuPartNumber_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber_BsShare_PCBSerialNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber_BsShare_ProductSerialNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate_BsShare_SMTManufacturingDate);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber_BsShare_SMTPlantNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element_BsShare_SwUpdFotaFinPrint_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element_BsShare_SwUpdFotaMode_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element_BsShare_SwUpdFotaStatus_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element_BsShare_SwUpdFotadecrypt_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element_BsShare_SwUpdReflash_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element_BsShare_VehicleConfig_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(0U);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element_BsShare_VisMeet_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber_BsShare_VisteonPCBPartNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber_BsShare_VisteonPartNumber);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element_RefCys_Certicificate1_Element);
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

  fct_status = TSC_CMeetCdd_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element_RefCys_Certicificate_Element);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_MeetCdd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CMeetCdd_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_Meet_Mgrdiagcdd_Action
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Meet_Mgrdiagcdd_Action> of PortPrototype <pp_CS_Meet_Mgrdiagcdd_Action>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_Meet_Mgrdiagcdd_Action(EDcmExtAction *Action, UInt8 *Data, UInt8 *Length, UInt32 *DID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Meet_Mgrdiagcdd_Action_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Meet_Mgrdiagcdd_Action_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Meet_Mgrdiagcdd_Action(P2VAR(EDcmExtAction, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Action, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Length, P2VAR(UInt32, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) DID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Meet_Mgrdiagcdd_Action (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_RID_DiagAction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RID_DiagAction> of PortPrototype <pp_CS_RID_DiagAction>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, UInt8 *Out_RoutineInfo, UInt8 *Data, UInt16 *DataLength, UInt8 *pNrc, teRoutineOperation eOperation)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RID_DiagAction_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_RID_DiagAction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt16, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teRoutineOperation eOperation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_RID_DiagAction (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_Read_ManufModeStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read_ManufModeStatus> of PortPrototype <pp_CS_Read_ManufModeStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_Read_ManufModeStatus(EMeetModeStatus *currentstate)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Read_ManufModeStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Read_ManufModeStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Read_ManufModeStatus(P2VAR(EMeetModeStatus, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) currentstate) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Read_ManufModeStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMeetCdd_Write_Mfg_Flag
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Write_Mfg_Flag> of PortPrototype <pp_CS_Write_Mfg_Flag>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMeetCdd_Write_Mfg_Flag(UInt16 *pdata)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_Write_Mfg_Flag_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Write_Mfg_Flag_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Write_Mfg_Flag(P2VAR(UInt16, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pdata) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMeetCdd_Write_Mfg_Flag (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CMeetCdd_STOP_SEC_CODE
#include "CMeetCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CMeetCdd_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  EDcmExtAction Test_EDcmExtAction_V_1 = eDcmExtAction_Read;
  EDcmExtAction Test_EDcmExtAction_V_2 = eDcmExtAction_Write;
  EDcmExtAction Test_EDcmExtAction_V_3 = eDcmExtAction_IOCtrl;
  EDcmExtAction Test_EDcmExtAction_V_4 = eDcmExtAction_RetCtrlEcu;
  EDcmExtAction Test_EDcmExtAction_V_5 = eDcmExtAction_RoutineStart;
  EDcmExtAction Test_EDcmExtAction_V_6 = eDcmExtAction_RoutineStop;
  EDcmExtAction Test_EDcmExtAction_V_7 = eDcmExtAction__RoutineResult;
  EDcmExtAction Test_EDcmExtAction_V_8 = eDcmExtAction_CheckConditions;
  EDcmExtAction Test_EDcmExtAction_V_9 = eDcmExtAction_Reset;

  EDidType Test_EDidType_V_1 = EDidType_Read;
  EDidType Test_EDidType_V_2 = EDidType_Write;
  EDidType Test_EDidType_V_3 = EDidType_Last;

  EIOCtrlOptType Test_EIOCtrlOptType_V_1 = EIOCtrlOptType_returnControlToECU;
  EIOCtrlOptType Test_EIOCtrlOptType_V_2 = EIOCtrlOptType_resetToDefault;
  EIOCtrlOptType Test_EIOCtrlOptType_V_3 = EIOCtrlOptType_freezeCurrentState;
  EIOCtrlOptType Test_EIOCtrlOptType_V_4 = EIOCtrlOptType_shortTermAdjustment;
  EIOCtrlOptType Test_EIOCtrlOptType_V_5 = EIOCtrlOptType_Last;

  EMeetModeStatus Test_EMeetModeStatus_V_1 = eManufModeActive;
  EMeetModeStatus Test_EMeetModeStatus_V_2 = eManufModeInActive;

  ERoutineType Test_ERoutineType_V_1 = ERoutineType_Start;
  ERoutineType Test_ERoutineType_V_2 = ERoutineType_Stop;
  ERoutineType Test_ERoutineType_V_3 = ERoutineType_QueryResults;
  ERoutineType Test_ERoutineType_V_4 = ERoutineType_Last;

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

  teDIDOperation Test_teDIDOperation_V_1 = eRead;
  teDIDOperation Test_teDIDOperation_V_2 = eWrite;
  teDIDOperation Test_teDIDOperation_V_3 = eSTA;
  teDIDOperation Test_teDIDOperation_V_4 = eRCTECU;
  teDIDOperation Test_teDIDOperation_V_5 = eCheckConditions;
  teDIDOperation Test_teDIDOperation_V_6 = eRST2DEFAULT;
  teDIDOperation Test_teDIDOperation_V_7 = eFCS;
  teDIDOperation Test_teDIDOperation_V_8 = eLengthCheck;

  teDiagOpStatus Test_teDiagOpStatus_V_1 = DIAG_INITIAL;
  teDiagOpStatus Test_teDiagOpStatus_V_2 = DIAG_PENDING;
  teDiagOpStatus Test_teDiagOpStatus_V_3 = DIAG_CANCEL;
  teDiagOpStatus Test_teDiagOpStatus_V_4 = DIAG_FORCE_RCRRP_OK;
  teDiagOpStatus Test_teDiagOpStatus_V_5 = DIAG_FORCE_RCRRP_NOT_OK;

  teRoutineOperation Test_teRoutineOperation_V_1 = eRoutineStart;
  teRoutineOperation Test_teRoutineOperation_V_2 = eRoutineStop;
  teRoutineOperation Test_teRoutineOperation_V_3 = eRoutineResult;
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
