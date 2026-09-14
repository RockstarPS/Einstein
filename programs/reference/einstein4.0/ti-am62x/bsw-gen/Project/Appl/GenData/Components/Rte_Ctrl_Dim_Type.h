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
 *          File:  Rte_Ctrl_Dim_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Ctrl_Dim>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRL_DIM_TYPE_H
# define _RTE_CTRL_DIM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CLUSTER_INACTIVE
#   define CLUSTER_INACTIVE (0U)
#  endif

#  ifndef CLUSTER_ACTIVE
#   define CLUSTER_ACTIVE (1U)
#  endif

#  ifndef TFTDisplayOFF
#   define TFTDisplayOFF (0U)
#  endif

#  ifndef TFTDisplayON
#   define TFTDisplayON (1U)
#  endif

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
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

#  ifndef eIO_DIN_DI_SBATT2_ERR
#   define eIO_DIN_DI_SBATT2_ERR (16U)
#  endif

#  ifndef eIO_DIN_DI_FALD_PG
#   define eIO_DIN_DI_FALD_PG (17U)
#  endif

#  ifndef eIO_DIN_DI_MD_TOUCH_INTN
#   define eIO_DIN_DI_MD_TOUCH_INTN (18U)
#  endif

#  ifndef eIO_DIN_DI_BL_FAULT
#   define eIO_DIN_DI_BL_FAULT (19U)
#  endif

#  ifndef eIO_DIN_DI_SOC_FPDLINK3_LOCK
#   define eIO_DIN_DI_SOC_FPDLINK3_LOCK (20U)
#  endif

#  ifndef eIO_DIN_DI_SOC_FPDLINK3_PASS
#   define eIO_DIN_DI_SOC_FPDLINK3_PASS (21U)
#  endif

#  ifndef eIO_DIN_DI_ENET_MII_INT
#   define eIO_DIN_DI_ENET_MII_INT (22U)
#  endif

#  ifndef eIO_DIN_DI_IGN_MON
#   define eIO_DIN_DI_IGN_MON (23U)
#  endif

#  ifndef eIO_DIN_DI_CABLE_DETECT
#   define eIO_DIN_DI_CABLE_DETECT (24U)
#  endif

#  ifndef eIO_DIN_DI_TCON_IND_OUT
#   define eIO_DIN_DI_TCON_IND_OUT (25U)
#  endif

#  ifndef eIO_DIN_DI_SPI_CAN_TCON_SDI
#   define eIO_DIN_DI_SPI_CAN_TCON_SDI (26U)
#  endif

#  ifndef eIO_DIN_DI_MCU_FALD_CONN_CHK
#   define eIO_DIN_DI_MCU_FALD_CONN_CHK (27U)
#  endif

#  ifndef eIO_DIN_DI_LDO_1V2_FAULTN
#   define eIO_DIN_DI_LDO_1V2_FAULTN (28U)
#  endif

#  ifndef eIO_DIN_DI_TFT_ER_DET
#   define eIO_DIN_DI_TFT_ER_DET (29U)
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

#  ifndef NETWORK_SLEEP
#   define NETWORK_SLEEP (0U)
#  endif

#  ifndef NETWORK_NORMAL
#   define NETWORK_NORMAL (1U)
#  endif

#  ifndef NETWORK_STANDALONE
#   define NETWORK_STANDALONE (2U)
#  endif

#  ifndef eSWCApp_SmartKey_Bzr
#   define eSWCApp_SmartKey_Bzr (0U)
#  endif

#  ifndef eSWCApp_Warn_MFLID
#   define eSWCApp_Warn_MFLID (1U)
#  endif

#  ifndef eSWCApp_Head_TT
#   define eSWCApp_Head_TT (2U)
#  endif

#  ifndef eSWCApp_Tail_TT
#   define eSWCApp_Tail_TT (3U)
#  endif

#  ifndef eSWCApp_Fuel
#   define eSWCApp_Fuel (4U)
#  endif

#  ifndef eSWCApp_Illum
#   define eSWCApp_Illum (5U)
#  endif

#  ifndef eSWCApp_Buzzer
#   define eSWCApp_Buzzer (6U)
#  endif

#  ifndef eSWCApp_NVM
#   define eSWCApp_NVM (7U)
#  endif

#  ifndef eTFTDisplayOnExceptTurn
#   define eTFTDisplayOnExceptTurn (8U)
#  endif

#  ifndef eTurnL_Status
#   define eTurnL_Status (9U)
#  endif

#  ifndef eTurnR_Status
#   define eTurnR_Status (10U)
#  endif

#  ifndef eSWCApp_End
#   define eSWCApp_End (11U)
#  endif

#  ifndef eSleep_Inactive
#   define eSleep_Inactive (0U)
#  endif

#  ifndef eISleep_Active
#   define eISleep_Active (1U)
#  endif

#  ifndef eDayNightModeIn
#   define eDayNightModeIn (0U)
#  endif

#  ifndef eIllumination_levelIn
#   define eIllumination_levelIn (1U)
#  endif

#  ifndef eAmbient_Light_levelIn
#   define eAmbient_Light_levelIn (2U)
#  endif

#  ifndef ePowerModeIn
#   define ePowerModeIn (3U)
#  endif

#  ifndef eTransportModeIn
#   define eTransportModeIn (4U)
#  endif

#  ifndef eGearModeIn
#   define eGearModeIn (5U)
#  endif

#  ifndef eGearRecommendationIn
#   define eGearRecommendationIn (6U)
#  endif

#  ifndef eGearIn
#   define eGearIn (7U)
#  endif

#  ifndef eWarningIn
#   define eWarningIn (8U)
#  endif

#  ifndef eGearStatusIn
#   define eGearStatusIn (9U)
#  endif

#  ifndef eEngineSpeedIn
#   define eEngineSpeedIn (10U)
#  endif

#  ifndef eTurn_Indicator_ControlIn
#   define eTurn_Indicator_ControlIn (11U)
#  endif

#  ifndef eEndOfRxSignal
#   define eEndOfRxSignal (12U)
#  endif

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRL_DIM_TYPE_H */
