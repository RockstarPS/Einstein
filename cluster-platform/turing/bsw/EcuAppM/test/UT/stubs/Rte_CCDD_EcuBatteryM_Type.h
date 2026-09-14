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
 *          File:  Rte_CCDD_EcuBatteryM_Type.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CCDD_EcuBatteryM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCDD_ECUBATTERYM_TYPE_H
# define _RTE_CCDD_ECUBATTERYM_TYPE_H

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

#  ifndef eIO_ADC_MON_VBATT
#   define eIO_ADC_MON_VBATT (0U)
#  endif

#  ifndef eIO_ADC_MON_3V3_SW
#   define eIO_ADC_MON_3V3_SW (1U)
#  endif

#  ifndef eIO_ADC_MON_5V0_SW
#   define eIO_ADC_MON_5V0_SW (2U)
#  endif

#  ifndef eIO_ADC_MON_TEST_CONN_TFT
#   define eIO_ADC_MON_TEST_CONN_TFT (3U)
#  endif

#  ifndef eIO_ADC_MON_PWR_FUELSEND
#   define eIO_ADC_MON_PWR_FUELSEND (4U)
#  endif

#  ifndef eIO_ADC_MON_TFT_NTC1
#   define eIO_ADC_MON_TFT_NTC1 (5U)
#  endif

#  ifndef eIO_ADC_MON_VING1
#   define eIO_ADC_MON_VING1 (6U)
#  endif

#  ifndef eIO_ADC_MON_TRIP_SW1_IN
#   define eIO_ADC_MON_TRIP_SW1_IN (7U)
#  endif

#  ifndef eIO_ADC_MON_TRIP_SW2_IN
#   define eIO_ADC_MON_TRIP_SW2_IN (8U)
#  endif

#  ifndef eIO_ADC_MON_5V0_SW_2
#   define eIO_ADC_MON_5V0_SW_2 (9U)
#  endif

#  ifndef eIO_ADC_MON_FUEL_SENDER_IN
#   define eIO_ADC_MON_FUEL_SENDER_IN (10U)
#  endif

#  ifndef eIO_ADC_AIRBAG_DIAG_IN
#   define eIO_ADC_AIRBAG_DIAG_IN (11U)
#  endif

#  ifndef eIO_ADC_MON_AIRBAG_IN
#   define eIO_ADC_MON_AIRBAG_IN (12U)
#  endif

#  ifndef eIO_ADC_MAX
#   define eIO_ADC_MAX (13U)
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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCDD_ECUBATTERYM_TYPE_H */
