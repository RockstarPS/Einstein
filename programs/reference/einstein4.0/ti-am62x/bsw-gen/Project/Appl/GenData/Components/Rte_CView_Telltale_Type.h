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
 *          File:  Rte_CView_Telltale_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CView_Telltale>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CVIEW_TELLTALE_TYPE_H
# define _RTE_CVIEW_TELLTALE_TYPE_H

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

#  ifndef eHMI_NOT_READY
#   define eHMI_NOT_READY (0U)
#  endif

#  ifndef eHMI_READY
#   define eHMI_READY (1U)
#  endif

#  ifndef NOT_IN_SYNCH
#   define NOT_IN_SYNCH (0U)
#  endif

#  ifndef FLASH_180DEG_PHASE_SYNCH
#   define FLASH_180DEG_PHASE_SYNCH (1U)
#  endif

#  ifndef FLASH_360DEG_PHASE_SYNCH
#   define FLASH_360DEG_PHASE_SYNCH (2U)
#  endif

#  ifndef FLASH_OFF_PERIOD_MASK
#   define FLASH_OFF_PERIOD_MASK (4U)
#  endif

#  ifndef TT_TURN_OFF
#   define TT_TURN_OFF (0U)
#  endif

#  ifndef TT_TURN_ON
#   define TT_TURN_ON (1U)
#  endif

#  ifndef TT_FLASH_QUARTER_HZ
#   define TT_FLASH_QUARTER_HZ (2U)
#  endif

#  ifndef TT_FLASH_HALF_HZ
#   define TT_FLASH_HALF_HZ (3U)
#  endif

#  ifndef TT_FLASH_CSNR_HALF_HZ
#   define TT_FLASH_CSNR_HALF_HZ (4U)
#  endif

#  ifndef TT_FLASH_0_83_HZ
#   define TT_FLASH_0_83_HZ (5U)
#  endif

#  ifndef TT_FLASH_1HZ
#   define TT_FLASH_1HZ (6U)
#  endif

#  ifndef TT_FLASH_1_33_HZ
#   define TT_FLASH_1_33_HZ (7U)
#  endif

#  ifndef TT_FLASH_1_66_HZ
#   define TT_FLASH_1_66_HZ (8U)
#  endif

#  ifndef TT_FLASH_2HZ
#   define TT_FLASH_2HZ (9U)
#  endif

#  ifndef TT_FLASH_2_5_HZ
#   define TT_FLASH_2_5_HZ (10U)
#  endif

#  ifndef TT_FLASH_2_66_HZ
#   define TT_FLASH_2_66_HZ (11U)
#  endif

#  ifndef TT_FLASH_TRNHZ_Normal
#   define TT_FLASH_TRNHZ_Normal (12U)
#  endif

#  ifndef TT_FLASH_TRNHZ_Fast
#   define TT_FLASH_TRNHZ_Fast (13U)
#  endif

#  ifndef TT_FLASH_TRNHZ_FHL
#   define TT_FLASH_TRNHZ_FHL (14U)
#  endif

#  ifndef TT_FLASH_3HZ
#   define TT_FLASH_3HZ (15U)
#  endif

#  ifndef TT_FLASH_4HZ
#   define TT_FLASH_4HZ (16U)
#  endif

#  ifndef TT_FLASH_5HZ
#   define TT_FLASH_5HZ (17U)
#  endif

#  ifndef TT_FLASH_SYNC_QUARTER_HZ
#   define TT_FLASH_SYNC_QUARTER_HZ (18U)
#  endif

#  ifndef TT_FLASH_SYNC_HALF_HZ
#   define TT_FLASH_SYNC_HALF_HZ (19U)
#  endif

#  ifndef TT_FLASH_SYNC_CSNR_HALF_HZ
#   define TT_FLASH_SYNC_CSNR_HALF_HZ (20U)
#  endif

#  ifndef TT_FLASH_SYNC_0_83_HZ
#   define TT_FLASH_SYNC_0_83_HZ (21U)
#  endif

#  ifndef TT_FLASH_SYNC_1HZ
#   define TT_FLASH_SYNC_1HZ (22U)
#  endif

#  ifndef TT_FLASH_SYNC_1_33_HZ
#   define TT_FLASH_SYNC_1_33_HZ (23U)
#  endif

#  ifndef TT_FLASH_SYNC_1_66_HZ
#   define TT_FLASH_SYNC_1_66_HZ (24U)
#  endif

#  ifndef TT_FLASH_SYNC_2HZ
#   define TT_FLASH_SYNC_2HZ (25U)
#  endif

#  ifndef TT_FLASH_SYNC_2_5_HZ
#   define TT_FLASH_SYNC_2_5_HZ (26U)
#  endif

#  ifndef TT_FLASH_SYNC_2_66_HZ
#   define TT_FLASH_SYNC_2_66_HZ (27U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_Normal
#   define TT_FLASH_TRNHZ_SYNC_Normal (28U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_Fast
#   define TT_FLASH_TRNHZ_SYNC_Fast (29U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_FHL
#   define TT_FLASH_TRNHZ_SYNC_FHL (30U)
#  endif

#  ifndef TT_FLASH_SYNC_4HZ
#   define TT_FLASH_SYNC_4HZ (31U)
#  endif

#  ifndef TT_FLASH_SYNC_5HZ
#   define TT_FLASH_SYNC_5HZ (32U)
#  endif

#  ifndef TT_CONFIGURED_OFF
#   define TT_CONFIGURED_OFF (255U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CVIEW_TELLTALE_TYPE_H */
