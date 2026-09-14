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
 *          File:  Rte_Mdl_SafetyAdapter_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Mdl_SafetyAdapter>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_SAFETYADAPTER_TYPE_H
# define _RTE_MDL_SAFETYADAPTER_TYPE_H

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

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
#  endif

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

#  ifndef NETWORK_SLEEP
#   define NETWORK_SLEEP (0U)
#  endif

#  ifndef NETWORK_NORMAL
#   define NETWORK_NORMAL (1U)
#  endif

#  ifndef NETWORK_STANDALONE
#   define NETWORK_STANDALONE (2U)
#  endif

#  ifndef eSCSBZRIn
#   define eSCSBZRIn (0U)
#  endif

#  ifndef eSCSACCELIn
#   define eSCSACCELIn (1U)
#  endif

#  ifndef ePBKLABIn
#   define ePBKLABIn (2U)
#  endif

#  ifndef eDBKLABIn
#   define eDBKLABIn (3U)
#  endif

#  ifndef eABIn
#   define eABIn (4U)
#  endif

#  ifndef eB_PKBLPIn
#   define eB_PKBLPIn (5U)
#  endif

#  ifndef eB_EPBWLIn
#   define eB_EPBWLIn (6U)
#  endif

#  ifndef eB_EPBMIDIn
#   define eB_EPBMIDIn (7U)
#  endif

#  ifndef eB_CPKBIn
#   define eB_CPKBIn (8U)
#  endif

#  ifndef eVSCOFFIn
#   define eVSCOFFIn (9U)
#  endif

#  ifndef eVSCEXISTIn
#   define eVSCEXISTIn (10U)
#  endif

#  ifndef eTRCOFFIn
#   define eTRCOFFIn (11U)
#  endif

#  ifndef eSLP_WLIn
#   define eSLP_WLIn (12U)
#  endif

#  ifndef eMCBWIn
#   define eMCBWIn (13U)
#  endif

#  ifndef eECBEXISTIn
#   define eECBEXISTIn (14U)
#  endif

#  ifndef eEBW_MIDIn
#   define eEBW_MIDIn (15U)
#  endif

#  ifndef eBRK_MIDIn
#   define eBRK_MIDIn (16U)
#  endif

#  ifndef eBHEXISTIn
#   define eBHEXISTIn (17U)
#  endif

#  ifndef eB_EBWIn
#   define eB_EBWIn (18U)
#  endif

#  ifndef eB_DAINDPIn
#   define eB_DAINDPIn (19U)
#  endif

#  ifndef eB_DAINDCIn
#   define eB_DAINDCIn (20U)
#  endif

#  ifndef eB_DACINDIn
#   define eB_DACINDIn (21U)
#  endif

#  ifndef eB_BUZZERIn
#   define eB_BUZZERIn (22U)
#  endif

#  ifndef eB_BRLVIn
#   define eB_BRLVIn (23U)
#  endif

#  ifndef eB_BRKWIn
#   define eB_BRKWIn (24U)
#  endif

#  ifndef eB_ALSDIn
#   define eB_ALSDIn (25U)
#  endif

#  ifndef eB_ABSIn
#   define eB_ABSIn (26U)
#  endif

#  ifndef eABS_MIDIn
#   define eABS_MIDIn (27U)
#  endif

#  ifndef ePWIINFOIn
#   define ePWIINFOIn (28U)
#  endif

#  ifndef eTRCCONRRIn
#   define eTRCCONRRIn (29U)
#  endif

#  ifndef eTRCCONRLIn
#   define eTRCCONRLIn (30U)
#  endif

#  ifndef eTRCCONFRIn
#   define eTRCCONFRIn (31U)
#  endif

#  ifndef eTRCCONFLIn
#   define eTRCCONFLIn (32U)
#  endif

#  ifndef eB_EBW2In
#   define eB_EBW2In (33U)
#  endif

#  ifndef eB_BUZZE2In
#   define eB_BUZZE2In (34U)
#  endif

#  ifndef eB_BRLV2In
#   define eB_BRLV2In (35U)
#  endif

#  ifndef eB_BRKW2In
#   define eB_BRKW2In (36U)
#  endif

#  ifndef eEndOfRxSafeSignal
#   define eEndOfRxSafeSignal (37U)
#  endif

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_SAFETYADAPTER_TYPE_H */
