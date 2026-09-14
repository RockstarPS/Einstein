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
 *        Config:  Turing.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.18.0
 *                 RTE Core Version 1.18.0
 *       License:  Unlimited license CBD1700714 for Visteon Corporation
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

#  ifndef eIOAdcId_MAI_BRAKE_FLUID_LEVEL
#   define eIOAdcId_MAI_BRAKE_FLUID_LEVEL (0U)
#  endif

#  ifndef eIOAdcId_MAI_VATT_MONITOR
#   define eIOAdcId_MAI_VATT_MONITOR (1U)
#  endif

#  ifndef eIOAdcId_MAI_IGN_MONITOR
#   define eIOAdcId_MAI_IGN_MONITOR (2U)
#  endif

#  ifndef eIOAdcId_MAI_MONITOR_5V
#   define eIOAdcId_MAI_MONITOR_5V (3U)
#  endif

#  ifndef eIOAdcId_MAI_TFT_TEMP
#   define eIOAdcId_MAI_TFT_TEMP (4U)
#  endif

#  ifndef eIOAdcId_MAI_SPKR_BTL_P
#   define eIOAdcId_MAI_SPKR_BTL_P (5U)
#  endif

#  ifndef eIOAdcId_MAI_DAY_NIGHT
#   define eIOAdcId_MAI_DAY_NIGHT (6U)
#  endif

#  ifndef eIOAdcId_MAI_DIMMING_STATUS
#   define eIOAdcId_MAI_DIMMING_STATUS (7U)
#  endif

#  ifndef eIOAdcId_MAI_EXT_TEMP
#   define eIOAdcId_MAI_EXT_TEMP (8U)
#  endif

#  ifndef eIOAdcId_MAI_FUEL_LEVEL
#   define eIOAdcId_MAI_FUEL_LEVEL (9U)
#  endif

#  ifndef eIOAdcId_MAI_GPU_TEMP
#   define eIOAdcId_MAI_GPU_TEMP (10U)
#  endif

#  ifndef eIOAdcId_MAI_OIL_LEVEL_SENSOR
#   define eIOAdcId_MAI_OIL_LEVEL_SENSOR (11U)
#  endif

#  ifndef eIOAdcId_MAI_STRG_WHELL_SW1
#   define eIOAdcId_MAI_STRG_WHELL_SW1 (12U)
#  endif

#  ifndef eIOAdcId_MAI_STRG_WHELL_SW2
#   define eIOAdcId_MAI_STRG_WHELL_SW2 (13U)
#  endif

#  ifndef eIOAdcId_MAI_VEHICLE_SPEED_MONITOR
#   define eIOAdcId_MAI_VEHICLE_SPEED_MONITOR (14U)
#  endif

#  ifndef eIOAdcId_Count
#   define eIOAdcId_Count (15U)
#  endif

#  ifndef eIOPinInId_MDI_PARKING_BRAKE
#   define eIOPinInId_MDI_PARKING_BRAKE (0U)
#  endif

#  ifndef eIOPinInId_MDI_TRIP_RESET
#   define eIOPinInId_MDI_TRIP_RESET (1U)
#  endif

#  ifndef eIOPinInId_MinWasher
#   define eIOPinInId_MinWasher (2U)
#  endif

#  ifndef eIOPinInId_Dimming1
#   define eIOPinInId_Dimming1 (3U)
#  endif

#  ifndef eIOPinInId_Monitoring
#   define eIOPinInId_Monitoring (4U)
#  endif

#  ifndef eIOPinInId_Dimming2
#   define eIOPinInId_Dimming2 (5U)
#  endif

#  ifndef eIOPinInId_Count
#   define eIOPinInId_Count (6U)
#  endif

#  ifndef eIOPinOutId_MDO_TT01
#   define eIOPinOutId_MDO_TT01 (0U)
#  endif

#  ifndef eIOPinOutId_MDO_TT02
#   define eIOPinOutId_MDO_TT02 (1U)
#  endif

#  ifndef eIOPinOutId_MDO_TT03
#   define eIOPinOutId_MDO_TT03 (2U)
#  endif

#  ifndef eIOPinOutId_MDO_TT04
#   define eIOPinOutId_MDO_TT04 (3U)
#  endif

#  ifndef eIOPinOutId_MDO_TT05
#   define eIOPinOutId_MDO_TT05 (4U)
#  endif

#  ifndef eIOPinOutId_MDO_TT06
#   define eIOPinOutId_MDO_TT06 (5U)
#  endif

#  ifndef eIOPinOutId_MDO_TT07
#   define eIOPinOutId_MDO_TT07 (6U)
#  endif

#  ifndef eIOPinOutId_MDO_TT08
#   define eIOPinOutId_MDO_TT08 (7U)
#  endif

#  ifndef eIOPinOutId_MDO_TT09
#   define eIOPinOutId_MDO_TT09 (8U)
#  endif

#  ifndef eIOPinOutId_MDO_TT10
#   define eIOPinOutId_MDO_TT10 (9U)
#  endif

#  ifndef eIOPinOutId_MDO_TT11
#   define eIOPinOutId_MDO_TT11 (10U)
#  endif

#  ifndef eIOPinOutId_MDO_TT12
#   define eIOPinOutId_MDO_TT12 (11U)
#  endif

#  ifndef eIOPinOutId_MDO_TT04_1
#   define eIOPinOutId_MDO_TT04_1 (12U)
#  endif

#  ifndef eIOPinOutId_DAY_NIGHT
#   define eIOPinOutId_DAY_NIGHT (13U)
#  endif

#  ifndef eIOPinOutId_CS_DIMMING_OUT
#   define eIOPinOutId_CS_DIMMING_OUT (14U)
#  endif

#  ifndef eIOPinOutId_SPKR_EN
#   define eIOPinOutId_SPKR_EN (15U)
#  endif

#  ifndef eIOPinOutId_MDO_MUTE
#   define eIOPinOutId_MDO_MUTE (16U)
#  endif

#  ifndef eIOPinOutId_MDO_OIL_EN
#   define eIOPinOutId_MDO_OIL_EN (17U)
#  endif

#  ifndef eIOPinOutId_MDO_VBATT_MONITORING_EN
#   define eIOPinOutId_MDO_VBATT_MONITORING_EN (18U)
#  endif

#  ifndef eIOPinOutId_Count
#   define eIOPinOutId_Count (19U)
#  endif

#  ifndef IOHWAB_E_NO_ERROR
#   define IOHWAB_E_NO_ERROR (2U)
#  endif

#  ifndef IOHWAB_E_ERROR
#   define IOHWAB_E_ERROR (3U)
#  endif

#  ifndef IOHWAB_E_ADC_ERROR
#   define IOHWAB_E_ADC_ERROR (4U)
#  endif

#  ifndef IOHWAB_E_DOUT_ID_INVALID
#   define IOHWAB_E_DOUT_ID_INVALID (5U)
#  endif

#  ifndef IOHWAB_E_DIN_ID_INVALID
#   define IOHWAB_E_DIN_ID_INVALID (6U)
#  endif

#  ifndef IOHWAB_E_ADC_ID_INVALID
#   define IOHWAB_E_ADC_ID_INVALID (7U)
#  endif

#  ifndef IOHWAB_E_PULSEINPUT_ID_INVALID
#   define IOHWAB_E_PULSEINPUT_ID_INVALID (8U)
#  endif

#  ifndef eIOPulseInIdSafe_SpeedIn
#   define eIOPulseInIdSafe_SpeedIn (0U)
#  endif

#  ifndef eIOPulseInIdSafe_Count
#   define eIOPulseInIdSafe_Count (1U)
#  endif

#  ifndef eIODutyOutId_VEHICLE_SPEED
#   define eIODutyOutId_VEHICLE_SPEED (0U)
#  endif

#  ifndef eIODutyOutId_BklDrvDimming
#   define eIODutyOutId_BklDrvDimming (1U)
#  endif

#  ifndef eIODutyOutId_Count
#   define eIODutyOutId_Count (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_IOHWAB_TYPE_H */
