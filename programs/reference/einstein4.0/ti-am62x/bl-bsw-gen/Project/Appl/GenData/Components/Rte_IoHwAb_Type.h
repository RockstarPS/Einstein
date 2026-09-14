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
 *          File:  Rte_IoHwAb_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB_TYPE_H
# define _RTE_IOHWAB_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eIO_ADC_ADC_FUEL_5V_MON
#   define eIO_ADC_ADC_FUEL_5V_MON (16U)
#  endif

#  ifndef eIO_ADC_ADC_FUEL_MAIN
#   define eIO_ADC_ADC_FUEL_MAIN (17U)
#  endif

#  ifndef eIO_ADC_IGN_AD
#   define eIO_ADC_IGN_AD (2U)
#  endif

#  ifndef eIO_ADC_FUEL_SEND_SUB_MICRO_AD
#   define eIO_ADC_FUEL_SEND_SUB_MICRO_AD (3U)
#  endif

#  ifndef eIO_ADC_AI_BATTERY
#   define eIO_ADC_AI_BATTERY (4U)
#  endif

#  ifndef eIO_ADC_AI_LCD_NTC
#   define eIO_ADC_AI_LCD_NTC (5U)
#  endif

#  ifndef eIO_ADC_AI_TEMP_RTC
#   define eIO_ADC_AI_TEMP_RTC (6U)
#  endif

#  ifndef eIO_ADC_Flasher_Diag_sense_1
#   define eIO_ADC_Flasher_Diag_sense_1 (7U)
#  endif

#  ifndef eIO_ADC_STR_SW2_ADIN
#   define eIO_ADC_STR_SW2_ADIN (8U)
#  endif

#  ifndef eIO_ADC_STR_SW1_ADIN
#   define eIO_ADC_STR_SW1_ADIN (9U)
#  endif

#  ifndef eIO_ADC_RHEO_SW_IN_ADIN
#   define eIO_ADC_RHEO_SW_IN_ADIN (10U)
#  endif

#  ifndef eIO_ADC_ADC_RHEO_5V_MON_ADIN
#   define eIO_ADC_ADC_RHEO_5V_MON_ADIN (11U)
#  endif

#  ifndef eIO_ADC_Flasher_Diag_sense_2
#   define eIO_ADC_Flasher_Diag_sense_2 (12U)
#  endif

#  ifndef eIO_ADC_AdcChannel_Vdb
#   define eIO_ADC_AdcChannel_Vdb (13U)
#  endif

#  ifndef eIO_ADC_AdcChannel_Vtemp
#   define eIO_ADC_AdcChannel_Vtemp (14U)
#  endif

#  ifndef eIO_ADC_MAX
#   define eIO_ADC_MAX (15U)
#  endif

#  ifndef eIO_ADC_AI_SAMPLE_1
#   define eIO_ADC_AI_SAMPLE_1 (0U)
#  endif

#  ifndef eIO_ADC_AI_SAMPLE_2
#   define eIO_ADC_AI_SAMPLE_2 (1U)
#  endif

#  ifndef eIO_DInGroupIdCount
#   define eIO_DInGroupIdCount (0)
#  endif

#  ifndef eIO_DIN_DI_AL_HAZARD
#   define eIO_DIN_DI_AL_HAZARD (0U)
#  endif

#  ifndef eIO_DIN_DI_AH_IGNITION
#   define eIO_DIN_DI_AH_IGNITION (1U)
#  endif

#  ifndef eIO_DIN_DI_SMPS_3V3_PG
#   define eIO_DIN_DI_SMPS_3V3_PG (2U)
#  endif

#  ifndef eIO_DIN_STOP_LAMP_MCU
#   define eIO_DIN_STOP_LAMP_MCU (3U)
#  endif

#  ifndef eIO_DIN_DI_AL_BRAKE_LEVEL
#   define eIO_DIN_DI_AL_BRAKE_LEVEL (4U)
#  endif

#  ifndef eIO_DIN_DI_AL_OIL_W
#   define eIO_DIN_DI_AL_OIL_W (5U)
#  endif

#  ifndef eIO_DIN_DI_AL_DRV_SEAT_BUCKLE
#   define eIO_DIN_DI_AL_DRV_SEAT_BUCKLE (6U)
#  endif

#  ifndef eIO_DIN_DI_AL_WASHER_LEVEL_SW
#   define eIO_DIN_DI_AL_WASHER_LEVEL_SW (7U)
#  endif

#  ifndef eIO_DIN_ODO_TripKnobInput
#   define eIO_DIN_ODO_TripKnobInput (8U)
#  endif

#  ifndef eIO_DIN_DI_AL_VACUUM
#   define eIO_DIN_DI_AL_VACUUM (9U)
#  endif

#  ifndef eIO_DIN_DI_LCD_BL_PWR_FAULT
#   define eIO_DIN_DI_LCD_BL_PWR_FAULT (10U)
#  endif

#  ifndef eIO_DIN_DI_AL_FUEL_LID_EFI_ECU
#   define eIO_DIN_DI_AL_FUEL_LID_EFI_ECU (11U)
#  endif

#  ifndef eIO_DIN_DI_TT_SHIFT_ERR
#   define eIO_DIN_DI_TT_SHIFT_ERR (12U)
#  endif

#  ifndef eIO_DIN_MAX
#   define eIO_DIN_MAX (13U)
#  endif

#  ifndef eIO_DIN_DI_PMIC_INTN
#   define eIO_DIN_DI_PMIC_INTN (14U)
#  endif

#  ifndef eIO_DIN_DI_MCU_PORZ
#   define eIO_DIN_DI_MCU_PORZ (15U)
#  endif

#  ifndef eIO_DOutGroupIdCount
#   define eIO_DOutGroupIdCount (0)
#  endif

#  ifndef eIO_DOUT_DO_5VSW2_3V3_EN
#   define eIO_DOUT_DO_5VSW2_3V3_EN (0U)
#  endif

#  ifndef eIO_DOUT_PARK_BRAKE_TT_OUT
#   define eIO_DOUT_PARK_BRAKE_TT_OUT (1U)
#  endif

#  ifndef eIO_DOUT_DO_SYC1
#   define eIO_DOUT_DO_SYC1 (2U)
#  endif

#  ifndef eIO_DOUT_SEAT_BELT_TT_MCUOUT
#   define eIO_DOUT_SEAT_BELT_TT_MCUOUT (3U)
#  endif

#  ifndef eIO_DOUT_TURN_LEFT_TT_MCUOUT
#   define eIO_DOUT_TURN_LEFT_TT_MCUOUT (4U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_BL_PWR_EN
#   define eIO_DOUT_DO_LCD_BL_PWR_EN (5U)
#  endif

#  ifndef eIO_DOUT_DO_3V3_DISP_SW_EN
#   define eIO_DOUT_DO_3V3_DISP_SW_EN (6U)
#  endif

#  ifndef eIO_DOUT_AMP_SHTD
#   define eIO_DOUT_AMP_SHTD (7U)
#  endif

#  ifndef eIO_DOUT_FUEL_RHEO_SUP_EN
#   define eIO_DOUT_FUEL_RHEO_SUP_EN (8U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_STBYB
#   define eIO_DOUT_DO_LCD_STBYB (9U)
#  endif

#  ifndef eIO_DOUT_SBATT2_EN
#   define eIO_DOUT_SBATT2_EN (10U)
#  endif

#  ifndef eIO_DOUT_BRAKE_TT_MCUOUT
#   define eIO_DOUT_BRAKE_TT_MCUOUT (11U)
#  endif

#  ifndef eIO_DOUT_AIRBAG_TT_MCUOUT
#   define eIO_DOUT_AIRBAG_TT_MCUOUT (12U)
#  endif

#  ifndef eIO_DOUT_TURN_RIGHT_TT_MCUOUT
#   define eIO_DOUT_TURN_RIGHT_TT_MCUOUT (13U)
#  endif

#  ifndef eIO_DOUT_DO_SMPS_5V_SW_EN
#   define eIO_DOUT_DO_SMPS_5V_SW_EN (14U)
#  endif

#  ifndef eIO_DOUT_PCS_OFF_TT_MCUOUT
#   define eIO_DOUT_PCS_OFF_TT_MCUOUT (15U)
#  endif

#  ifndef eIO_DOUT_ABS_TT_MCUOUT
#   define eIO_DOUT_ABS_TT_MCUOUT (16U)
#  endif

#  ifndef eIO_DOUT_SLIP_TT_MCUOUT
#   define eIO_DOUT_SLIP_TT_MCUOUT (17U)
#  endif

#  ifndef eIO_DOUT_VCS_OFF_TT_MCUOUT
#   define eIO_DOUT_VCS_OFF_TT_MCUOUT (18U)
#  endif

#  ifndef eIO_DOUT_ECB_EPB_TT_MCUOUT
#   define eIO_DOUT_ECB_EPB_TT_MCUOUT (19U)
#  endif

#  ifndef eIO_DOUT_Flasher_FL_RL_OUT
#   define eIO_DOUT_Flasher_FL_RL_OUT (20U)
#  endif

#  ifndef eIO_DOUT_Flasher_DEN1
#   define eIO_DOUT_Flasher_DEN1 (21U)
#  endif

#  ifndef eIO_DOUT_Flasher_DSEL1
#   define eIO_DOUT_Flasher_DSEL1 (22U)
#  endif

#  ifndef eIO_DOUT_Flasher_FR_RR_OUT
#   define eIO_DOUT_Flasher_FR_RR_OUT (23U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_RST
#   define eIO_DOUT_DO_LCD_RST (24U)
#  endif

#  ifndef eIO_DOUT_DO_SMPS_1V2_EN
#   define eIO_DOUT_DO_SMPS_1V2_EN (25U)
#  endif

#  ifndef eIO_DO_MAX
#   define eIO_DO_MAX (26U)
#  endif

#  ifndef eIO_DOUT_DO_DISP_RESET
#   define eIO_DOUT_DO_DISP_RESET (27U)
#  endif

#  ifndef eIO_DOUT_DO_DISP_STBY
#   define eIO_DOUT_DO_DISP_STBY (28U)
#  endif

#  ifndef eIO_DOUT_DO_TFT_BL_EN
#   define eIO_DOUT_DO_TFT_BL_EN (29U)
#  endif

#  ifndef eIO_DOUT_DO_PWM_DIMMING
#   define eIO_DOUT_DO_PWM_DIMMING (30U)
#  endif

#  ifndef eIO_DOUT_DO_RTC_INTN
#   define eIO_DOUT_DO_RTC_INTN (31U)
#  endif

#  ifndef eIO_DOUT_DO_SOC_PWR_LATCH
#   define eIO_DOUT_DO_SOC_PWR_LATCH (32U)
#  endif

#  ifndef eIO_DOUT_DO_1V2_EN
#   define eIO_DOUT_DO_1V2_EN (33U)
#  endif

#  ifndef eIO_DOUT_DO_EN_5V
#   define eIO_DOUT_DO_EN_5V (34U)
#  endif

#  ifndef eIO_DOUT_DO_ENET_EN
#   define eIO_DOUT_DO_ENET_EN (35U)
#  endif

#  ifndef eIO_DOUT_DO_LIN_NSLP
#   define eIO_DOUT_DO_LIN_NSLP (36U)
#  endif

#  ifndef E_NO_ERROR
#   define E_NO_ERROR (2U)
#  endif

#  ifndef E_ERROR
#   define E_ERROR (3U)
#  endif

#  ifndef E_ADC_ERROR
#   define E_ADC_ERROR (4U)
#  endif

#  ifndef E_DOUT_ID_INVALID
#   define E_DOUT_ID_INVALID (5U)
#  endif

#  ifndef E_DIN_ID_INVALID
#   define E_DIN_ID_INVALID (6U)
#  endif

#  ifndef E_ADC_ID_INVALID
#   define E_ADC_ID_INVALID (7U)
#  endif

#  ifndef IOHWAB_E_ADC_ERROR
#   define IOHWAB_E_ADC_ERROR (8U)
#  endif

#  ifndef IOHWAB_E_ADC_ID_INVALID
#   define IOHWAB_E_ADC_ID_INVALID (9U)
#  endif

#  ifndef IOHWAB_E_ERROR
#   define IOHWAB_E_ERROR (10U)
#  endif

#  ifndef IOHWAB_E_DOUT_ID_INVALID
#   define IOHWAB_E_DOUT_ID_INVALID (11U)
#  endif

#  ifndef IOHWAB_E_NO_ERROR
#   define IOHWAB_E_NO_ERROR (12U)
#  endif

#  ifndef IOHWAB_E_DIN_ID_INVALID
#   define IOHWAB_E_DIN_ID_INVALID (13U)
#  endif

#  ifndef eIO_PWM_MCU_BUZZER_AMPLCTRL
#   define eIO_PWM_MCU_BUZZER_AMPLCTRL (0U)
#  endif

#  ifndef eIO_PWM_HIGH_BEAM_TT_MCUOUT
#   define eIO_PWM_HIGH_BEAM_TT_MCUOUT (1U)
#  endif

#  ifndef eIO_PWM_FUEL_TEMP_GAUG_TEXT_PWM_OUT
#   define eIO_PWM_FUEL_TEMP_GAUG_TEXT_PWM_OUT (2U)
#  endif

#  ifndef eIO_PWM_PWM_OUT_ILL2
#   define eIO_PWM_PWM_OUT_ILL2 (3U)
#  endif

#  ifndef eIO_PWM_PWM_OUT_ILL1
#   define eIO_PWM_PWM_OUT_ILL1 (4U)
#  endif

#  ifndef eIO_PWM_BG_Dimming_PWM
#   define eIO_PWM_BG_Dimming_PWM (5U)
#  endif

#  ifndef eIO_PWM_PWM_GREEN_TT_DIMMING
#   define eIO_PWM_PWM_GREEN_TT_DIMMING (6U)
#  endif

#  ifndef eIO_PWM_CXPI_CLK
#   define eIO_PWM_CXPI_CLK (7U)
#  endif

#  ifndef eIO_PWM_PWM_LCD_BL_DIMMING
#   define eIO_PWM_PWM_LCD_BL_DIMMING (8U)
#  endif

#  ifndef eIO_PWM_MAX
#   define eIO_PWM_MAX (9U)
#  endif

#  ifndef eIOPulseInputIdCount
#   define eIOPulseInputIdCount (0)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_IOHWAB_TYPE_H */
