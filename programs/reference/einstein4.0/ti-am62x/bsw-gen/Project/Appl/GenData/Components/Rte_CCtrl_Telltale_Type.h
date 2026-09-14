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
 *          File:  Rte_CCtrl_Telltale_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CCtrl_Telltale>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCTRL_TELLTALE_TYPE_H
# define _RTE_CCTRL_TELLTALE_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BulbStatusNotActive
#   define BulbStatusNotActive (0U)
#  endif

#  ifndef BulbStatusActive
#   define BulbStatusActive (45020U)
#  endif

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

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
#  endif

#  ifndef TFTExitBlankOut
#   define TFTExitBlankOut (0U)
#  endif

#  ifndef TFTInBlankOut
#   define TFTInBlankOut (1U)
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

#  ifndef TT_ABS_INDEX
#   define TT_ABS_INDEX (0U)
#  endif

#  ifndef TT_AIRBAG_INDEX
#   define TT_AIRBAG_INDEX (1U)
#  endif

#  ifndef TT_BRAKE_RED_INDEX
#   define TT_BRAKE_RED_INDEX (2U)
#  endif

#  ifndef TT_BRAKE_HOLD_INDEX
#   define TT_BRAKE_HOLD_INDEX (3U)
#  endif

#  ifndef TT_BRAKE_YELLOW_INDEX
#   define TT_BRAKE_YELLOW_INDEX (4U)
#  endif

#  ifndef TT_PARKING_BRAKE_INDEX
#   define TT_PARKING_BRAKE_INDEX (5U)
#  endif

#  ifndef TT_TRACTION_CTRL_INDEX
#   define TT_TRACTION_CTRL_INDEX (6U)
#  endif

#  ifndef TT_VCS_OFF_INDEX
#   define TT_VCS_OFF_INDEX (7U)
#  endif

#  ifndef TT_ABS_INDEX_US
#   define TT_ABS_INDEX_US (8U)
#  endif

#  ifndef TT_BRAKE_RED_INDEX_US
#   define TT_BRAKE_RED_INDEX_US (9U)
#  endif

#  ifndef TT_PARKING_BRAKE_INDEX_US
#   define TT_PARKING_BRAKE_INDEX_US (10U)
#  endif

#  ifndef TT_SAF_RES4_INDEX
#   define TT_SAF_RES4_INDEX (11U)
#  endif

#  ifndef TT_SAF_RES5_INDEX
#   define TT_SAF_RES5_INDEX (12U)
#  endif

#  ifndef TT_SAF_RES6_INDEX
#   define TT_SAF_RES6_INDEX (13U)
#  endif

#  ifndef TT_SAF_RES7_INDEX
#   define TT_SAF_RES7_INDEX (14U)
#  endif

#  ifndef TT_SAF_RES8_INDEX
#   define TT_SAF_RES8_INDEX (15U)
#  endif

#  ifndef TT_ADAS_INDEX
#   define TT_ADAS_INDEX (16U)
#  endif

#  ifndef TT_AUTO_HIGH_BEAM_INDEX
#   define TT_AUTO_HIGH_BEAM_INDEX (17U)
#  endif

#  ifndef TT_BRAKE_HOLD_STANDBY_INDEX
#   define TT_BRAKE_HOLD_STANDBY_INDEX (18U)
#  endif

#  ifndef TT_FUEL_INDEX
#   define TT_FUEL_INDEX (19U)
#  endif

#  ifndef TT_FFOG_INDEX
#   define TT_FFOG_INDEX (20U)
#  endif

#  ifndef TT_HEAD_INDEX
#   define TT_HEAD_INDEX (21U)
#  endif

#  ifndef TT_HIGH_BEAM_INDEX
#   define TT_HIGH_BEAM_INDEX (22U)
#  endif

#  ifndef TT_PCS_OFF_INDEX
#   define TT_PCS_OFF_INDEX (23U)
#  endif

#  ifndef TT_READY_INDEX
#   define TT_READY_INDEX (24U)
#  endif

#  ifndef TT_RFOG_INDEX
#   define TT_RFOG_INDEX (25U)
#  endif

#  ifndef TT_SEAT_BELT_INDEX
#   define TT_SEAT_BELT_INDEX (26U)
#  endif

#  ifndef TT_TAIL_LIGHT_INDEX
#   define TT_TAIL_LIGHT_INDEX (27U)
#  endif

#  ifndef TT_TURN_HAZARD_RIGHT_INDEX
#   define TT_TURN_HAZARD_RIGHT_INDEX (28U)
#  endif

#  ifndef TT_TURN_HAZARD_LEFT_INDEX
#   define TT_TURN_HAZARD_LEFT_INDEX (29U)
#  endif

#  ifndef TT_EWT_INDEX
#   define TT_EWT_INDEX (30U)
#  endif

#  ifndef TT_AAHB_LO_GREEN
#   define TT_AAHB_LO_GREEN (31U)
#  endif

#  ifndef TT_AAHB_SHADED_GREEN
#   define TT_AAHB_SHADED_GREEN (32U)
#  endif

#  ifndef TT_AAHB_HI_GREEN
#   define TT_AAHB_HI_GREEN (33U)
#  endif

#  ifndef TT_AAHB_HI_WHITE
#   define TT_AAHB_HI_WHITE (34U)
#  endif

#  ifndef TT_ITS_INFRA
#   define TT_ITS_INFRA (35U)
#  endif

#  ifndef TT_ITS_VEHICLE
#   define TT_ITS_VEHICLE (36U)
#  endif

#  ifndef TT_ITS_COMBINATION
#   define TT_ITS_COMBINATION (37U)
#  endif

#  ifndef TT_SSS_GREEN
#   define TT_SSS_GREEN (38U)
#  endif

#  ifndef TT_SSS_AMBER
#   define TT_SSS_AMBER (39U)
#  endif

#  ifndef TT_LCA_LEFT_WHITE
#   define TT_LCA_LEFT_WHITE (40U)
#  endif

#  ifndef TT_LCA_LEFT_GRAY
#   define TT_LCA_LEFT_GRAY (41U)
#  endif

#  ifndef TT_LCA_LEFT_GREEN
#   define TT_LCA_LEFT_GREEN (42U)
#  endif

#  ifndef TT_LCA_RIGHT_WHITE
#   define TT_LCA_RIGHT_WHITE (43U)
#  endif

#  ifndef TT_LCA_RIGHT_GRAY
#   define TT_LCA_RIGHT_GRAY (44U)
#  endif

#  ifndef TT_LCA_RIGHT_GREEN
#   define TT_LCA_RIGHT_GREEN (45U)
#  endif

#  ifndef TT_LTA_GREEN
#   define TT_LTA_GREEN (46U)
#  endif

#  ifndef TT_LTA_WHITE
#   define TT_LTA_WHITE (47U)
#  endif

#  ifndef TT_LTA_AMBER
#   define TT_LTA_AMBER (48U)
#  endif

#  ifndef TT_CCT_GREEN
#   define TT_CCT_GREEN (49U)
#  endif

#  ifndef TT_CCT_WHITE
#   define TT_CCT_WHITE (50U)
#  endif

#  ifndef TT_CCT_AMBER
#   define TT_CCT_AMBER (51U)
#  endif

#  ifndef TT_RCCT_GREEN
#   define TT_RCCT_GREEN (52U)
#  endif

#  ifndef TT_RCCT_WHITE
#   define TT_RCCT_WHITE (53U)
#  endif

#  ifndef TT_RCCT_AMBER
#   define TT_RCCT_AMBER (54U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV4
#   define TT_ACCDT_WHITE_LV4 (55U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV3
#   define TT_ACCDT_WHITE_LV3 (56U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV2
#   define TT_ACCDT_WHITE_LV2 (57U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV1
#   define TT_ACCDT_WHITE_LV1 (58U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV4
#   define TT_ACCDT_GREEN_LV4 (59U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV3
#   define TT_ACCDT_GREEN_LV3 (60U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV2
#   define TT_ACCDT_GREEN_LV2 (61U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV1
#   define TT_ACCDT_GREEN_LV1 (62U)
#  endif

#  ifndef TT_SL_GREEN
#   define TT_SL_GREEN (63U)
#  endif

#  ifndef TT_SL_WHITE
#   define TT_SL_WHITE (64U)
#  endif

#  ifndef TT_SL_AMBER
#   define TT_SL_AMBER (65U)
#  endif

#  ifndef TT_AUTO_LSD_AMBER
#   define TT_AUTO_LSD_AMBER (66U)
#  endif

#  ifndef TT_DRIVEMODE_SPORT
#   define TT_DRIVEMODE_SPORT (67U)
#  endif

#  ifndef TT_DRIVEMODE_ECO
#   define TT_DRIVEMODE_ECO (68U)
#  endif

#  ifndef TT_DRIVEMODE_CUSTOM
#   define TT_DRIVEMODE_CUSTOM (69U)
#  endif

#  ifndef TT_DRIVEMODE_RANGE
#   define TT_DRIVEMODE_RANGE (70U)
#  endif

#  ifndef TT_DRIVEMODE_REARCOMFORT
#   define TT_DRIVEMODE_REARCOMFORT (71U)
#  endif

#  ifndef TT_DRIVEMODE_SNOW
#   define TT_DRIVEMODE_SNOW (72U)
#  endif

#  ifndef TT_DRIVEMODE_TRACK
#   define TT_DRIVEMODE_TRACK (73U)
#  endif

#  ifndef TT_LDA_RED
#   define TT_LDA_RED (74U)
#  endif

#  ifndef TT_LDA_AMBER
#   define TT_LDA_AMBER (75U)
#  endif

#  ifndef TT_LDA_WHITE
#   define TT_LDA_WHITE (76U)
#  endif

#  ifndef TT_LDA_OFF_AMBER
#   define TT_LDA_OFF_AMBER (77U)
#  endif

#  ifndef TT_LDA_OFF_WHITE
#   define TT_LDA_OFF_WHITE (78U)
#  endif

#  ifndef TT_ECOLAMP
#   define TT_ECOLAMP (79U)
#  endif

#  ifndef TT_PS_GREEN
#   define TT_PS_GREEN (80U)
#  endif

#  ifndef TT_PKBOPER_TXT
#   define TT_PKBOPER_TXT (81U)
#  endif

#  ifndef TT_PKBOPER_IMG
#   define TT_PKBOPER_IMG (82U)
#  endif

#  ifndef TT_TPMS_INDEX
#   define TT_TPMS_INDEX (83U)
#  endif

#  ifndef TT_EBPWIND_RED_US
#   define TT_EBPWIND_RED_US (84U)
#  endif

#  ifndef TT_EBPWIND_RED
#   define TT_EBPWIND_RED (85U)
#  endif

#  ifndef TT_FMSR_AMBER
#   define TT_FMSR_AMBER (86U)
#  endif

#  ifndef TT_FMFR_AMBER
#   define TT_FMFR_AMBER (87U)
#  endif

#  ifndef TT_MULWL_GREEN
#   define TT_MULWL_GREEN (88U)
#  endif

#  ifndef TT_HCS_ACCESS_GREEN
#   define TT_HCS_ACCESS_GREEN (89U)
#  endif

#  ifndef TT_HCS_LIFT_GREEN
#   define TT_HCS_LIFT_GREEN (90U)
#  endif

#  ifndef TT_HCS_LIFT_AMBER
#   define TT_HCS_LIFT_AMBER (91U)
#  endif

#  ifndef TT_TOTAL_NUM_OF_TELLTALES
#   define TT_TOTAL_NUM_OF_TELLTALES (92U)
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

#endif /* _RTE_CCTRL_TELLTALE_TYPE_H */
