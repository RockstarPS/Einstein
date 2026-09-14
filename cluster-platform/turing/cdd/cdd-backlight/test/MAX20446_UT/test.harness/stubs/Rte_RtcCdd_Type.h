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
 *          File:  Rte_RtcCdd_Type.h
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
 *
 *   Description:  Application types header file for SW-C <RtcCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_RTCCDD_TYPE_H
# define _RTE_RTCCDD_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#  endif

#  ifndef eCmpCmd_DeActivate
#   define eCmpCmd_DeActivate (3U)
#  endif

#  ifndef eIO_ADC_MAI_OIL_LEVEL_SENSOR
#   define eIO_ADC_MAI_OIL_LEVEL_SENSOR (0U)
#  endif

#  ifndef eIO_ADC_MAI_FUEL_LEVEL
#   define eIO_ADC_MAI_FUEL_LEVEL (1U)
#  endif

#  ifndef eIO_ADC_MAI_BRAKE_FLUID_LEVEL
#   define eIO_ADC_MAI_BRAKE_FLUID_LEVEL (2U)
#  endif

#  ifndef eIO_ADC_MAI_P_10V_MONITOR
#   define eIO_ADC_MAI_P_10V_MONITOR (3U)
#  endif

#  ifndef eIO_ADC_MAI_DIMMING2_INPUT
#   define eIO_ADC_MAI_DIMMING2_INPUT (4U)
#  endif

#  ifndef eIO_ADC_MAI_EXTERNAL_TEMP
#   define eIO_ADC_MAI_EXTERNAL_TEMP (5U)
#  endif

#  ifndef eIO_ADC_MAI_SBR_LIGHT
#   define eIO_ADC_MAI_SBR_LIGHT (6U)
#  endif

#  ifndef eIO_ADC_MAI_STRG_WHEEL_SW1
#   define eIO_ADC_MAI_STRG_WHEEL_SW1 (7U)
#  endif

#  ifndef eIO_ADC_MAI_IGNSENSE_MCU_IN
#   define eIO_ADC_MAI_IGNSENSE_MCU_IN (8U)
#  endif

#  ifndef eIO_ADC_TT_SERVICE_MAI
#   define eIO_ADC_TT_SERVICE_MAI (9U)
#  endif

#  ifndef eIO_ADC_TT_AIRBAG_MAI
#   define eIO_ADC_TT_AIRBAG_MAI (10U)
#  endif

#  ifndef eIO_ADC_MAI_VEHICLE_SPEED_OUTPUT
#   define eIO_ADC_MAI_VEHICLE_SPEED_OUTPUT (11U)
#  endif

#  ifndef eIO_ADC_MAI_DIMMING_OUT_STATUS
#   define eIO_ADC_MAI_DIMMING_OUT_STATUS (12U)
#  endif

#  ifndef eIO_ADC_MAI_TEMP_BCKL
#   define eIO_ADC_MAI_TEMP_BCKL (13U)
#  endif

#  ifndef eIO_ADC_MAI_SVBAT_MONITORING
#   define eIO_ADC_MAI_SVBAT_MONITORING (14U)
#  endif

#  ifndef eIO_ADC_MAI_VbPWM_SUPERV
#   define eIO_ADC_MAI_VbPWM_SUPERV (15U)
#  endif

#  ifndef eIO_ADC_TT_LCA_TAKE_OVER_MAI
#   define eIO_ADC_TT_LCA_TAKE_OVER_MAI (16U)
#  endif

#  ifndef eIO_ADC_TT_PARKING_BRAKE_MAI
#   define eIO_ADC_TT_PARKING_BRAKE_MAI (17U)
#  endif

#  ifndef eIO_ADC_TT_TURN_LEFT_MAI
#   define eIO_ADC_TT_TURN_LEFT_MAI (18U)
#  endif

#  ifndef eIO_ADC_TT_TURN_RIGHT_MAI
#   define eIO_ADC_TT_TURN_RIGHT_MAI (19U)
#  endif

#  ifndef eIO_ADC_MAI_STRG_WHEEL_SW2
#   define eIO_ADC_MAI_STRG_WHEEL_SW2 (20U)
#  endif

#  ifndef eIO_ADC_TT_STOP_MAI
#   define eIO_ADC_TT_STOP_MAI (21U)
#  endif

#  ifndef eIO_ADC_MAI_SPARE_1
#   define eIO_ADC_MAI_SPARE_1 (22U)
#  endif

#  ifndef eIO_ADC_MAI_SPARE_2
#   define eIO_ADC_MAI_SPARE_2 (23U)
#  endif

#  ifndef eIO_ADC_MAI_SPARE_3
#   define eIO_ADC_MAI_SPARE_3 (24U)
#  endif

#  ifndef eIO_ADC_MAI_SPARE_4
#   define eIO_ADC_MAI_SPARE_4 (25U)
#  endif

#  ifndef eIO_ADC_MAI_SPARE_5
#   define eIO_ADC_MAI_SPARE_5 (26U)
#  endif

#  ifndef eIO_ADC_MAI_DAY_NIGHT
#   define eIO_ADC_MAI_DAY_NIGHT (27U)
#  endif

#  ifndef eIO_ADC_MAI_ALT_WARNING
#   define eIO_ADC_MAI_ALT_WARNING (28U)
#  endif

#  ifndef eIO_ADC_MAI_BATT_SUPERV
#   define eIO_ADC_MAI_BATT_SUPERV (29U)
#  endif

#  ifndef eIO_ADC_MAI_TEMP_SENSOR
#   define eIO_ADC_MAI_TEMP_SENSOR (30U)
#  endif

#  ifndef eIO_ADC_VBATT_MON
#   define eIO_ADC_VBATT_MON (31U)
#  endif

#  ifndef eIO_ADC_SBATT2_MON
#   define eIO_ADC_SBATT2_MON (32U)
#  endif

#  ifndef eIO_ADCIdCount
#   define eIO_ADCIdCount (33U)
#  endif

#  ifndef eIO_ADC_MAI_DIMMING2_INPUT_RAW
#   define eIO_ADC_MAI_DIMMING2_INPUT_RAW (34U)
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
#   define IOHWAB_E_ADC_ERROR (0U)
#  endif

#  ifndef IOHWAB_E_ADC_ID_INVALID
#   define IOHWAB_E_ADC_ID_INVALID (1U)
#  endif

#  ifndef IOHWAB_E_ERROR
#   define IOHWAB_E_ERROR (2U)
#  endif

#  ifndef IOHWAB_E_DOUT_ID_INVALID
#   define IOHWAB_E_DOUT_ID_INVALID (3U)
#  endif

#  ifndef IOHWAB_E_NO_ERROR
#   define IOHWAB_E_NO_ERROR (4U)
#  endif

#  ifndef IOHWAB_E_DIN_ID_INVALID
#   define IOHWAB_E_DIN_ID_INVALID (5U)
#  endif

#  ifndef eResetReason_BatteryConnect
#   define eResetReason_BatteryConnect (0U)
#  endif

#  ifndef eResetReason_ModuleWakeup
#   define eResetReason_ModuleWakeup (1U)
#  endif

#  ifndef eResetReason_EarlyWakeup
#   define eResetReason_EarlyWakeup (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_RTCCDD_TYPE_H */
