/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_CCDD_EcuBatteryM_Type.h
 *           Config:  Audi_Etron_TV2.dpa
 *      ECU-Project:  Audi_Etron_TV2
 *
 *        Generator:  MICROSAR RTE Generator Version 4.39.00
 *                    RTE Core Version 4.39.00
 *          License:  CBD2500735
 *
 *      Description:  Application types header file for SW-C <CCDD_EcuBatteryM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CCDD_ECUBATTERYM_TYPE_H
# define RTE_CCDD_ECUBATTERYM_TYPE_H

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
#  ifndef eIOAdcId_AI_FPK_BKL_NTC
#   define eIOAdcId_AI_FPK_BKL_NTC (0U)
#  endif

#  ifndef eIOAdcId_AI_FPK_BATT_DIAG
#   define eIOAdcId_AI_FPK_BATT_DIAG (1U)
#  endif

#  ifndef eIOAdcId_AI_3V3_FPK_DISPLAY_PG
#   define eIOAdcId_AI_3V3_FPK_DISPLAY_PG (2U)
#  endif

#  ifndef eIOAdcId_AI_SMPS_5V_PG
#   define eIOAdcId_AI_SMPS_5V_PG (3U)
#  endif

#  ifndef eIOAdcId_AI_3V3_SW_FPK_PG
#   define eIOAdcId_AI_3V3_SW_FPK_PG (4U)
#  endif

#  ifndef eIOAdcId_AI_FPK_32kHz_TEMP
#   define eIOAdcId_AI_FPK_32kHz_TEMP (5U)
#  endif

#  ifndef eIO_ADC_MAX
#   define eIO_ADC_MAX (6U)
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

#endif /* RTE_CCDD_ECUBATTERYM_TYPE_H */
