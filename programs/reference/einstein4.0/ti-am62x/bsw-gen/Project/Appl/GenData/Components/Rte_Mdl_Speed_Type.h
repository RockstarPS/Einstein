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
 *          File:  Rte_Mdl_Speed_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Mdl_Speed>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_SPEED_TYPE_H
# define _RTE_MDL_SPEED_TYPE_H

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

#  ifndef eFUNC_CANADA
#   define eFUNC_CANADA (0U)
#  endif

#  ifndef eFUNC_NORTH_AMERICA
#   define eFUNC_NORTH_AMERICA (1U)
#  endif

#  ifndef eFUNC_MEXICO
#   define eFUNC_MEXICO (2U)
#  endif

#  ifndef eFUNC_GENERAL_EXPORT
#   define eFUNC_GENERAL_EXPORT (3U)
#  endif

#  ifndef eFUNC_UK
#   define eFUNC_UK (4U)
#  endif

#  ifndef eFUNC_EUROPE
#   define eFUNC_EUROPE (5U)
#  endif

#  ifndef eFUNC_SOUTH_AFRICA
#   define eFUNC_SOUTH_AFRICA (6U)
#  endif

#  ifndef eFUNC_MIDDLE_EAST_ASIA
#   define eFUNC_MIDDLE_EAST_ASIA (7U)
#  endif

#  ifndef eFUNC_JAPAN
#   define eFUNC_JAPAN (8U)
#  endif

#  ifndef eFUNC_INDIA
#   define eFUNC_INDIA (9U)
#  endif

#  ifndef eFUNC_KOREA
#   define eFUNC_KOREA (10U)
#  endif

#  ifndef eFUNC_TAIWAN
#   define eFUNC_TAIWAN (11U)
#  endif

#  ifndef eFUNC_CHINA
#   define eFUNC_CHINA (12U)
#  endif

#  ifndef eFUNC_HONG_KONG
#   define eFUNC_HONG_KONG (13U)
#  endif

#  ifndef eFUNC_AUSTRALIA
#   define eFUNC_AUSTRALIA (14U)
#  endif

#  ifndef eSPEEDO
#   define eSPEEDO (1U)
#  endif

#  ifndef eTACHO
#   define eTACHO (2U)
#  endif

#  ifndef eHVSYS_INDICATOR
#   define eHVSYS_INDICATOR (4U)
#  endif

#  ifndef eSPEAKER
#   define eSPEAKER (8U)
#  endif

#  ifndef eTELLTALE
#   define eTELLTALE (16U)
#  endif

#  ifndef eBUTTONEVENT
#   define eBUTTONEVENT (32U)
#  endif

#  ifndef eMIDDISPALY
#   define eMIDDISPALY (64U)
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

#  ifndef eVehicleSpeedABSIn
#   define eVehicleSpeedABSIn (0U)
#  endif

#  ifndef eAirbagIn
#   define eAirbagIn (1U)
#  endif

#  ifndef eAlive_101In
#   define eAlive_101In (2U)
#  endif

#  ifndef eCRC_101In
#   define eCRC_101In (3U)
#  endif

#  ifndef eEndOfSafeRxSignal
#   define eEndOfSafeRxSignal (4U)
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
#   define eSIGNAL_INVALID (3U)
#  endif

#  ifndef eSIGNAL_INVALID_CRC
#   define eSIGNAL_INVALID_CRC (4U)
#  endif

#  ifndef eSIGNAL_INVALID_ALIVE_COUNTER
#   define eSIGNAL_INVALID_ALIVE_COUNTER (5U)
#  endif

#  ifndef eSIGNAL_REPEATED
#   define eSIGNAL_REPEATED (6U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_SPEED_TYPE_H */
