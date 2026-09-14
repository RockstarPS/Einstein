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
 *          File:  Rte_CWarnMsg_Core_Observer_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CWarnMsg_Core_Observer>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CWARNMSG_CORE_OBSERVER_TYPE_H
# define _RTE_CWARNMSG_CORE_OBSERVER_TYPE_H

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

#  ifndef EButtonId_None
#   define EButtonId_None (0U)
#  endif

#  ifndef EButtonId_Ok
#   define EButtonId_Ok (1U)
#  endif

#  ifndef EButtonId_Up
#   define EButtonId_Up (2U)
#  endif

#  ifndef EButtonId_Down
#   define EButtonId_Down (3U)
#  endif

#  ifndef EButtonId_Back
#   define EButtonId_Back (4U)
#  endif

#  ifndef EButtonId_Menu
#   define EButtonId_Menu (5U)
#  endif

#  ifndef EButtonId_Phone
#   define EButtonId_Phone (6U)
#  endif

#  ifndef EButtonId_Hud
#   define EButtonId_Hud (7U)
#  endif

#  ifndef EButtonId_Last
#   define EButtonId_Last (8U)
#  endif

#  ifndef EButtonSts_Off
#   define EButtonSts_Off (0U)
#  endif

#  ifndef EButtonSts_On
#   define EButtonSts_On (1U)
#  endif

#  ifndef EButtonSts_Short
#   define EButtonSts_Short (2U)
#  endif

#  ifndef EButtonSts_Long
#   define EButtonSts_Long (3U)
#  endif

#  ifndef EButtonSts_Repeat
#   define EButtonSts_Repeat (4U)
#  endif

#  ifndef EButtonSts_Last
#   define EButtonSts_Last (5U)
#  endif

#  ifndef NO_CHIME_ID
#   define NO_CHIME_ID (0U)
#  endif

#  ifndef MAX_CHIME_ID
#   define MAX_CHIME_ID (1U)
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

#  ifndef eSCREENMODE_OFF
#   define eSCREENMODE_OFF (0U)
#  endif

#  ifndef eSCREENMODE_BLANK
#   define eSCREENMODE_BLANK (1U)
#  endif

#  ifndef eSCREENMODE_NORMAL
#   define eSCREENMODE_NORMAL (2U)
#  endif

#  ifndef eSCREENMODE_DISPLAY_ADJ
#   define eSCREENMODE_DISPLAY_ADJ (3U)
#  endif

#  ifndef eSCREENMODE_WELCOME
#   define eSCREENMODE_WELCOME (4U)
#  endif

#  ifndef eSCREENMODE_IGNOFF_CHR
#   define eSCREENMODE_IGNOFF_CHR (5U)
#  endif

#  ifndef eSCREENMODE_OPENING
#   define eSCREENMODE_OPENING (6U)
#  endif

#  ifndef eSCREENMODE_ENDING
#   define eSCREENMODE_ENDING (7U)
#  endif

#  ifndef eSCREENMODE_ENDING_IGNOFF_CHR
#   define eSCREENMODE_ENDING_IGNOFF_CHR (8U)
#  endif

#  ifndef eSCREENMODE_RESERVED
#   define eSCREENMODE_RESERVED (9U)
#  endif

#  ifndef HUD_WK_LO
#   define HUD_WK_LO (0U)
#  endif

#  ifndef HUD_WK_HI
#   define HUD_WK_HI (1U)
#  endif

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
#  endif

#  ifndef NO_TARGET
#   define NO_TARGET (0U)
#  endif

#  ifndef TG_LEFT
#   define TG_LEFT (1U)
#  endif

#  ifndef TG_UP
#   define TG_UP (2U)
#  endif

#  ifndef TG_DOWN
#   define TG_DOWN (3U)
#  endif

#  ifndef TG_RIGHT
#   define TG_RIGHT (4U)
#  endif

#  ifndef TG_ENTER
#   define TG_ENTER (5U)
#  endif

#  ifndef TG_BACK
#   define TG_BACK (6U)
#  endif

#  ifndef TG_MAX
#   define TG_MAX (7U)
#  endif

#  ifndef WRNG_NOTIFIED_NONE
#   define WRNG_NOTIFIED_NONE (0U)
#  endif

#  ifndef WRNG_NOTIFIED_ACKNOWLEDGED
#   define WRNG_NOTIFIED_ACKNOWLEDGED (1U)
#  endif

#  ifndef WRNG_NOTIFIED_TIMEOUT
#   define WRNG_NOTIFIED_TIMEOUT (2U)
#  endif

#  ifndef WRNG_NOTIFIED_HIDDEN
#   define WRNG_NOTIFIED_HIDDEN (4U)
#  endif

#  ifndef WRNG_NOTIFIED_SHOW
#   define WRNG_NOTIFIED_SHOW (8U)
#  endif

#  ifndef WRNG_NOTIFIED_ACTIVE
#   define WRNG_NOTIFIED_ACTIVE (16U)
#  endif

#  ifndef WRNG_NOTIFIED_INACTIVE
#   define WRNG_NOTIFIED_INACTIVE (32U)
#  endif

#  ifndef UI_WARNING_EVENT_NONE
#   define UI_WARNING_EVENT_NONE (0U)
#  endif

#  ifndef UI_WARNING_EVENT_RETRIGGER
#   define UI_WARNING_EVENT_RETRIGGER (1U)
#  endif

#  ifndef UI_WARNING_EVENT_FORCED
#   define UI_WARNING_EVENT_FORCED (2U)
#  endif

#  ifndef WRN_NORM_BRLV_02
#   define WRN_NORM_BRLV_02 (0U)
#  endif

#  ifndef WRN_NORM_ECB_02
#   define WRN_NORM_ECB_02 (1U)
#  endif

#  ifndef WRN_NORM_BRK_02
#   define WRN_NORM_BRK_02 (2U)
#  endif

#  ifndef WRN_NORM_BRKHLD_10
#   define WRN_NORM_BRKHLD_10 (3U)
#  endif

#  ifndef WRN_NORM_BRKHLD_12
#   define WRN_NORM_BRKHLD_12 (4U)
#  endif

#  ifndef WRN_NORM_BRKHLD_16
#   define WRN_NORM_BRKHLD_16 (5U)
#  endif

#  ifndef WRN_NORM_ABS_02
#   define WRN_NORM_ABS_02 (6U)
#  endif

#  ifndef WRN_NORM_AUTHIG_02
#   define WRN_NORM_AUTHIG_02 (7U)
#  endif

#  ifndef WRN_NORM_ADAHIG_02
#   define WRN_NORM_ADAHIG_02 (8U)
#  endif

#  ifndef WRN_NORM_BRKHLD_02
#   define WRN_NORM_BRKHLD_02 (9U)
#  endif

#  ifndef WRN_NORM_BRKHLD_03
#   define WRN_NORM_BRKHLD_03 (10U)
#  endif

#  ifndef WRN_NORM_BRKHLD_05
#   define WRN_NORM_BRKHLD_05 (11U)
#  endif

#  ifndef WRN_NORM_BRKHLD_06
#   define WRN_NORM_BRKHLD_06 (12U)
#  endif

#  ifndef WRN_NORM_BRKHLD_07
#   define WRN_NORM_BRKHLD_07 (13U)
#  endif

#  ifndef WRN_NORM_BRKHLD_08
#   define WRN_NORM_BRKHLD_08 (14U)
#  endif

#  ifndef WRN_NORM_BRKHLD_11
#   define WRN_NORM_BRKHLD_11 (15U)
#  endif

#  ifndef WRN_NORM_BRKHLD_13
#   define WRN_NORM_BRKHLD_13 (16U)
#  endif

#  ifndef WRN_NORM_BRKHLD_14
#   define WRN_NORM_BRKHLD_14 (17U)
#  endif

#  ifndef WRN_NORM_BRKHLD_15
#   define WRN_NORM_BRKHLD_15 (18U)
#  endif

#  ifndef WRN_NORM_BRKHLD_17
#   define WRN_NORM_BRKHLD_17 (19U)
#  endif

#  ifndef WRN_NORM_AIRBAG_03
#   define WRN_NORM_AIRBAG_03 (20U)
#  endif

#  ifndef WRN_NORM_AUTHIG_04
#   define WRN_NORM_AUTHIG_04 (21U)
#  endif

#  ifndef WRN_NORM_ADAHIG_04
#   define WRN_NORM_ADAHIG_04 (22U)
#  endif

#  ifndef WRN_NORM_ADASTT_05
#   define WRN_NORM_ADASTT_05 (23U)
#  endif

#  ifndef WRN_NORM_ADASTT_07
#   define WRN_NORM_ADASTT_07 (24U)
#  endif

#  ifndef WRN_NORM_ADASTT_09
#   define WRN_NORM_ADASTT_09 (25U)
#  endif

#  ifndef WRN_NORM_ADASTT_10
#   define WRN_NORM_ADASTT_10 (26U)
#  endif

#  ifndef WRN_NORM_ADASTT_11
#   define WRN_NORM_ADASTT_11 (27U)
#  endif

#  ifndef WRN_NORM_TFUEL_01
#   define WRN_NORM_TFUEL_01 (28U)
#  endif

#  ifndef WRN_NORM_PSC1_02
#   define WRN_NORM_PSC1_02 (29U)
#  endif

#  ifndef WRN_NORM_PSC1_04
#   define WRN_NORM_PSC1_04 (30U)
#  endif

#  ifndef WRN_NORM_PSC1_05
#   define WRN_NORM_PSC1_05 (31U)
#  endif

#  ifndef WRN_NORM_PSC1_06
#   define WRN_NORM_PSC1_06 (32U)
#  endif

#  ifndef WRN_NORM_PSC1_07
#   define WRN_NORM_PSC1_07 (33U)
#  endif

#  ifndef WRN_NORM_PSC1_08
#   define WRN_NORM_PSC1_08 (34U)
#  endif

#  ifndef WRN_NORM_PSC1_09
#   define WRN_NORM_PSC1_09 (35U)
#  endif

#  ifndef WRN_NORM_PSC1_10
#   define WRN_NORM_PSC1_10 (36U)
#  endif

#  ifndef WRN_NORM_PSC1_12
#   define WRN_NORM_PSC1_12 (37U)
#  endif

#  ifndef WRN_NORM_PSC1_13
#   define WRN_NORM_PSC1_13 (38U)
#  endif

#  ifndef WRN_NORM_EPB_03
#   define WRN_NORM_EPB_03 (39U)
#  endif

#  ifndef WRN_NORM_EPB_04
#   define WRN_NORM_EPB_04 (40U)
#  endif

#  ifndef WRN_NORM_EPB_05
#   define WRN_NORM_EPB_05 (41U)
#  endif

#  ifndef WRN_NORM_EPB_08
#   define WRN_NORM_EPB_08 (42U)
#  endif

#  ifndef WRN_NORM_EPB_10
#   define WRN_NORM_EPB_10 (43U)
#  endif

#  ifndef WRN_NORM_EPB_11
#   define WRN_NORM_EPB_11 (44U)
#  endif

#  ifndef WRN_NORM_EPB_12
#   define WRN_NORM_EPB_12 (45U)
#  endif

#  ifndef WRN_NORM_EPB_13
#   define WRN_NORM_EPB_13 (46U)
#  endif

#  ifndef WRN_NORM_EPB_14
#   define WRN_NORM_EPB_14 (47U)
#  endif

#  ifndef WRN_NORM_EPB_15
#   define WRN_NORM_EPB_15 (48U)
#  endif

#  ifndef WRN_NORM_EPB_16
#   define WRN_NORM_EPB_16 (49U)
#  endif

#  ifndef WRN_NORM_EPB_17
#   define WRN_NORM_EPB_17 (50U)
#  endif

#  ifndef WRN_NORM_EPB_18
#   define WRN_NORM_EPB_18 (51U)
#  endif

#  ifndef WRN_NORM_TRCOFF_02
#   define WRN_NORM_TRCOFF_02 (52U)
#  endif

#  ifndef WRN_NORM_WASLEV_02
#   define WRN_NORM_WASLEV_02 (53U)
#  endif

#  ifndef WRN_NORM_BVOOPE_02
#   define WRN_NORM_BVOOPE_02 (54U)
#  endif

#  ifndef WRN_NORM_THESEN_02
#   define WRN_NORM_THESEN_02 (55U)
#  endif

#  ifndef WRN_NORM_THESEN_03
#   define WRN_NORM_THESEN_03 (56U)
#  endif

#  ifndef WRN_CUSTMIZE_DIGKEY_04
#   define WRN_CUSTMIZE_DIGKEY_04 (57U)
#  endif

#  ifndef WRN_CUSTMIZE_DIGKEY_05
#   define WRN_CUSTMIZE_DIGKEY_05 (58U)
#  endif

#  ifndef WRN_CUSTMIZE_DIGKEY_06
#   define WRN_CUSTMIZE_DIGKEY_06 (59U)
#  endif

#  ifndef WRN_CUSTMIZE_DIGKEY_07
#   define WRN_CUSTMIZE_DIGKEY_07 (60U)
#  endif

#  ifndef WRN_NORM_MLGT_01
#   define WRN_NORM_MLGT_01 (61U)
#  endif

#  ifndef WRN_NORM_TPWSR_01
#   define WRN_NORM_TPWSR_01 (62U)
#  endif

#  ifndef WRN_NORM_TPWSR_02
#   define WRN_NORM_TPWSR_02 (63U)
#  endif

#  ifndef WRN_NORM_TPWSR_03
#   define WRN_NORM_TPWSR_03 (64U)
#  endif

#  ifndef WRN_NORM_SMASTA_02
#   define WRN_NORM_SMASTA_02 (65U)
#  endif

#  ifndef WRN_NORM_SMASTA_03
#   define WRN_NORM_SMASTA_03 (66U)
#  endif

#  ifndef WRN_NORM_SMASTA_04
#   define WRN_NORM_SMASTA_04 (67U)
#  endif

#  ifndef WRN_NORM_SMASTA_05
#   define WRN_NORM_SMASTA_05 (68U)
#  endif

#  ifndef WRN_NORM_SMASTA_06
#   define WRN_NORM_SMASTA_06 (69U)
#  endif

#  ifndef WRN_NORM_SMASTA_07
#   define WRN_NORM_SMASTA_07 (70U)
#  endif

#  ifndef WRN_NORM_SMASTA_08
#   define WRN_NORM_SMASTA_08 (71U)
#  endif

#  ifndef WRN_NORM_SMASTA_09
#   define WRN_NORM_SMASTA_09 (72U)
#  endif

#  ifndef WRN_NORM_SMASTA_10
#   define WRN_NORM_SMASTA_10 (73U)
#  endif

#  ifndef WRN_NORM_SMASTA_11
#   define WRN_NORM_SMASTA_11 (74U)
#  endif

#  ifndef WRN_NORM_SMASTA_12
#   define WRN_NORM_SMASTA_12 (75U)
#  endif

#  ifndef WRN_NORM_SMASTA_13
#   define WRN_NORM_SMASTA_13 (76U)
#  endif

#  ifndef WRN_NORM_SMASTA_17
#   define WRN_NORM_SMASTA_17 (77U)
#  endif

#  ifndef WRN_NORM_SMASTA_18
#   define WRN_NORM_SMASTA_18 (78U)
#  endif

#  ifndef WRN_NORM_SMASTA_19
#   define WRN_NORM_SMASTA_19 (79U)
#  endif

#  ifndef WRN_NORM_SMASTA_20
#   define WRN_NORM_SMASTA_20 (80U)
#  endif

#  ifndef WRN_NORM_SMASTA_21
#   define WRN_NORM_SMASTA_21 (81U)
#  endif

#  ifndef WRN_NORM_SMASTA_23
#   define WRN_NORM_SMASTA_23 (82U)
#  endif

#  ifndef WRN_NORM_SMASTA_24
#   define WRN_NORM_SMASTA_24 (83U)
#  endif

#  ifndef WRN_NORM_SMASTA_25
#   define WRN_NORM_SMASTA_25 (84U)
#  endif

#  ifndef WRN_NORM_SMASTA_26
#   define WRN_NORM_SMASTA_26 (85U)
#  endif

#  ifndef WRN_NORM_SMASTA_28
#   define WRN_NORM_SMASTA_28 (86U)
#  endif

#  ifndef WRN_NORM_SMASTA_29
#   define WRN_NORM_SMASTA_29 (87U)
#  endif

#  ifndef WRN_NORM_SMASTA_30
#   define WRN_NORM_SMASTA_30 (88U)
#  endif

#  ifndef WRN_NORM_SMASTA_31
#   define WRN_NORM_SMASTA_31 (89U)
#  endif

#  ifndef WRN_NORM_SMASTA_32
#   define WRN_NORM_SMASTA_32 (90U)
#  endif

#  ifndef WRN_NORM_SMASTA_33
#   define WRN_NORM_SMASTA_33 (91U)
#  endif

#  ifndef WRN_NORM_SMASTA_34
#   define WRN_NORM_SMASTA_34 (92U)
#  endif

#  ifndef WRN_NORM_SMASTA_36
#   define WRN_NORM_SMASTA_36 (93U)
#  endif

#  ifndef WRN_NORM_SMASTA_37
#   define WRN_NORM_SMASTA_37 (94U)
#  endif

#  ifndef WRN_NORM_SMASTA_38
#   define WRN_NORM_SMASTA_38 (95U)
#  endif

#  ifndef WRN_NORM_SMASTA_39
#   define WRN_NORM_SMASTA_39 (96U)
#  endif

#  ifndef WRN_NORM_SMASTA_40
#   define WRN_NORM_SMASTA_40 (97U)
#  endif

#  ifndef WRN_NORM_SMASTA_41
#   define WRN_NORM_SMASTA_41 (98U)
#  endif

#  ifndef WRN_NORM_LEDHEA_01
#   define WRN_NORM_LEDHEA_01 (99U)
#  endif

#  ifndef WRN_NORM_HEALEV_02
#   define WRN_NORM_HEALEV_02 (100U)
#  endif

#  ifndef WRN_NORM_HEALEV_03
#   define WRN_NORM_HEALEV_03 (101U)
#  endif

#  ifndef WRN_NORM_GRISHU_02
#   define WRN_NORM_GRISHU_02 (102U)
#  endif

#  ifndef WRN_NORM_AVAS_02
#   define WRN_NORM_AVAS_02 (103U)
#  endif

#  ifndef WRN_NORM_ALOA_03
#   define WRN_NORM_ALOA_03 (104U)
#  endif

#  ifndef WRN_NORM_PCS2_03
#   define WRN_NORM_PCS2_03 (105U)
#  endif

#  ifndef WRN_NORM_PCS2_11
#   define WRN_NORM_PCS2_11 (106U)
#  endif

#  ifndef WRN_NORM_TRWIP_01
#   define WRN_NORM_TRWIP_01 (107U)
#  endif

#  ifndef WRN_NORM_RSEREM_02
#   define WRN_NORM_RSEREM_02 (108U)
#  endif

#  ifndef WRN_NORM_RSEREM_03
#   define WRN_NORM_RSEREM_03 (109U)
#  endif

#  ifndef WRN_NORM_RSEREM_04
#   define WRN_NORM_RSEREM_04 (110U)
#  endif

#  ifndef WRN_NORM_RSEREM_05
#   define WRN_NORM_RSEREM_05 (111U)
#  endif

#  ifndef WRN_NORM_4WDSYS_03
#   define WRN_NORM_4WDSYS_03 (112U)
#  endif

#  ifndef WRN_NORM_4WDSYS_04
#   define WRN_NORM_4WDSYS_04 (113U)
#  endif

#  ifndef WRN_NORM_4WDSYS_06
#   define WRN_NORM_4WDSYS_06 (114U)
#  endif

#  ifndef WRN_NORM_CVTOIL_02
#   define WRN_NORM_CVTOIL_02 (115U)
#  endif

#  ifndef WRN_NORM_CVTOIL_03
#   define WRN_NORM_CVTOIL_03 (116U)
#  endif

#  ifndef WRN_NORM_ATMAL_02
#   define WRN_NORM_ATMAL_02 (117U)
#  endif

#  ifndef WRN_NORM_SFTPOS_02
#   define WRN_NORM_SFTPOS_02 (118U)
#  endif

#  ifndef WRN_NORM_SFTPOS_03
#   define WRN_NORM_SFTPOS_03 (119U)
#  endif

#  ifndef WRN_NORM_SFTPOS_04
#   define WRN_NORM_SFTPOS_04 (120U)
#  endif

#  ifndef WRN_NORM_MCBW_02
#   define WRN_NORM_MCBW_02 (121U)
#  endif

#  ifndef WRN_NORM_TPWS_01
#   define WRN_NORM_TPWS_01 (122U)
#  endif

#  ifndef WRN_NORM_TPWS_02
#   define WRN_NORM_TPWS_02 (123U)
#  endif

#  ifndef WRN_NORM_OILMIL_02
#   define WRN_NORM_OILMIL_02 (124U)
#  endif

#  ifndef WRN_NORM_OILMIL_03
#   define WRN_NORM_OILMIL_03 (125U)
#  endif

#  ifndef WRN_NORM_OILMIL_04
#   define WRN_NORM_OILMIL_04 (126U)
#  endif

#  ifndef WRN_NORM_OILMIL_05
#   define WRN_NORM_OILMIL_05 (127U)
#  endif

#  ifndef WRN_NORM_BRLV0_02
#   define WRN_NORM_BRLV0_02 (128U)
#  endif

#  ifndef WRN_NORM_OILPRE_01
#   define WRN_NORM_OILPRE_01 (129U)
#  endif

#  ifndef WRN_NORM_BRK0_02
#   define WRN_NORM_BRK0_02 (130U)
#  endif

#  ifndef WRN_NORM_BRK0_03
#   define WRN_NORM_BRK0_03 (131U)
#  endif

#  ifndef WRN_NORM_EPS_02
#   define WRN_NORM_EPS_02 (132U)
#  endif

#  ifndef WRN_NORM_EPS_03
#   define WRN_NORM_EPS_03 (133U)
#  endif

#  ifndef WRN_NORM_EPS_04
#   define WRN_NORM_EPS_04 (134U)
#  endif

#  ifndef WRN_NORM_EPS_05
#   define WRN_NORM_EPS_05 (135U)
#  endif

#  ifndef WRN_NORM_EPS_06
#   define WRN_NORM_EPS_06 (136U)
#  endif

#  ifndef WRN_NORM_EPS_07
#   define WRN_NORM_EPS_07 (137U)
#  endif

#  ifndef WRN_NORM_EPS_09
#   define WRN_NORM_EPS_09 (138U)
#  endif

#  ifndef WRN_NORM_EPS_10
#   define WRN_NORM_EPS_10 (139U)
#  endif

#  ifndef WRN_NORM_EPS_11
#   define WRN_NORM_EPS_11 (140U)
#  endif

#  ifndef WRN_NORM_FUECAP_02
#   define WRN_NORM_FUECAP_02 (141U)
#  endif

#  ifndef WRN_NORM_CHEENG_02
#   define WRN_NORM_CHEENG_02 (142U)
#  endif

#  ifndef WRN_NORM_CHEENG_03
#   define WRN_NORM_CHEENG_03 (143U)
#  endif

#  ifndef WRN_NORM_CHEENG_04
#   define WRN_NORM_CHEENG_04 (144U)
#  endif

#  ifndef WRN_NORM_CHEENG_07
#   define WRN_NORM_CHEENG_07 (145U)
#  endif

#  ifndef WRN_NORM_ROLAWA_01
#   define WRN_NORM_ROLAWA_01 (146U)
#  endif

#  ifndef WRN_NORM_ROLAWA_02
#   define WRN_NORM_ROLAWA_02 (147U)
#  endif

#  ifndef WRN_NORM_ROLAWA_03
#   define WRN_NORM_ROLAWA_03 (148U)
#  endif

#  ifndef WRN_NORM_GPF_05
#   define WRN_NORM_GPF_05 (149U)
#  endif

#  ifndef WRN_NORM_GPF_06
#   define WRN_NORM_GPF_06 (150U)
#  endif

#  ifndef WRN_NORM_GPF_07
#   define WRN_NORM_GPF_07 (151U)
#  endif

#  ifndef WRN_NORM_GPF_08
#   define WRN_NORM_GPF_08 (152U)
#  endif

#  ifndef WRN_NORM_GPF_09
#   define WRN_NORM_GPF_09 (153U)
#  endif

#  ifndef WRN_NORM_GPF_10
#   define WRN_NORM_GPF_10 (154U)
#  endif

#  ifndef WRN_NORM_GPF_11
#   define WRN_NORM_GPF_11 (155U)
#  endif

#  ifndef WRN_NORM_OILLEV_02
#   define WRN_NORM_OILLEV_02 (156U)
#  endif

#  ifndef WRN_NORM_COOTEM_03
#   define WRN_NORM_COOTEM_03 (157U)
#  endif

#  ifndef WRN_NORM_ONACCN_03
#   define WRN_NORM_ONACCN_03 (158U)
#  endif

#  ifndef WRN_NORM_BATLOW_02
#   define WRN_NORM_BATLOW_02 (159U)
#  endif

#  ifndef WRN_NORM_CHAMAL_02
#   define WRN_NORM_CHAMAL_02 (160U)
#  endif

#  ifndef WRN_NORM_CHAMAL_03
#   define WRN_NORM_CHAMAL_03 (161U)
#  endif

#  ifndef WRN_NORM_POWMAN_02
#   define WRN_NORM_POWMAN_02 (162U)
#  endif

#  ifndef WRN_NORM_SOCLOW_02
#   define WRN_NORM_SOCLOW_02 (163U)
#  endif

#  ifndef WRN_NORM_SOCLOW_03
#   define WRN_NORM_SOCLOW_03 (164U)
#  endif

#  ifndef WRN_NORM_BATINS_02
#   define WRN_NORM_BATINS_02 (165U)
#  endif

#  ifndef WRN_NORM_BATINS_03
#   define WRN_NORM_BATINS_03 (166U)
#  endif

#  ifndef WRN_NORM_BATINS_04
#   define WRN_NORM_BATINS_04 (167U)
#  endif

#  ifndef WRN_NORM_BATINS_05
#   define WRN_NORM_BATINS_05 (168U)
#  endif

#  ifndef WRN_NORM_ONACCP_02
#   define WRN_NORM_ONACCP_02 (169U)
#  endif

#  ifndef WRN_NORM_ALMN_02
#   define WRN_NORM_ALMN_02 (170U)
#  endif

#  ifndef WRN_NORM_HEAECU_02
#   define WRN_NORM_HEAECU_02 (171U)
#  endif

#  ifndef WRN_NORM_BOS_02
#   define WRN_NORM_BOS_02 (172U)
#  endif

#  ifndef WRN_NORM_BOS_03
#   define WRN_NORM_BOS_03 (173U)
#  endif

#  ifndef WRN_NORM_EVMOD_02
#   define WRN_NORM_EVMOD_02 (174U)
#  endif

#  ifndef WRN_NORM_EVMOD_03
#   define WRN_NORM_EVMOD_03 (175U)
#  endif

#  ifndef WRN_NORM_EVMOD_04
#   define WRN_NORM_EVMOD_04 (176U)
#  endif

#  ifndef WRN_NORM_EVMOD_05
#   define WRN_NORM_EVMOD_05 (177U)
#  endif

#  ifndef WRN_NORM_EVMOD_06
#   define WRN_NORM_EVMOD_06 (178U)
#  endif

#  ifndef WRN_NORM_EVMOD_07
#   define WRN_NORM_EVMOD_07 (179U)
#  endif

#  ifndef WRN_NORM_EVMOD_08
#   define WRN_NORM_EVMOD_08 (180U)
#  endif

#  ifndef WRN_NORM_EVMOD_09
#   define WRN_NORM_EVMOD_09 (181U)
#  endif

#  ifndef WRN_NORM_EVMOD_10
#   define WRN_NORM_EVMOD_10 (182U)
#  endif

#  ifndef WRN_NORM_DSC_02
#   define WRN_NORM_DSC_02 (183U)
#  endif

#  ifndef WRN_NORM_DSC_03
#   define WRN_NORM_DSC_03 (184U)
#  endif

#  ifndef WRN_NORM_DSC_04
#   define WRN_NORM_DSC_04 (185U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_01
#   define WRN_NORM_ROLAWA1_01 (186U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_02
#   define WRN_NORM_ROLAWA1_02 (187U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_03
#   define WRN_NORM_ROLAWA1_03 (188U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_04
#   define WRN_NORM_ROLAWA1_04 (189U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_05
#   define WRN_NORM_ROLAWA1_05 (190U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_06
#   define WRN_NORM_ROLAWA1_06 (191U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_07
#   define WRN_NORM_ROLAWA1_07 (192U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_08
#   define WRN_NORM_ROLAWA1_08 (193U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_09
#   define WRN_NORM_ROLAWA1_09 (194U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_10
#   define WRN_NORM_ROLAWA1_10 (195U)
#  endif

#  ifndef WRN_NORM_ROLAWA1_11
#   define WRN_NORM_ROLAWA1_11 (196U)
#  endif

#  ifndef WRN_NORM_MAICER_09
#   define WRN_NORM_MAICER_09 (197U)
#  endif

#  ifndef WRN_NORM_MAICER_10
#   define WRN_NORM_MAICER_10 (198U)
#  endif

#  ifndef WRN_NORM_MAICER_11
#   define WRN_NORM_MAICER_11 (199U)
#  endif

#  ifndef WRN_NORM_MAICER_12
#   define WRN_NORM_MAICER_12 (200U)
#  endif

#  ifndef WRN_NORM_PKSB_09
#   define WRN_NORM_PKSB_09 (201U)
#  endif

#  ifndef WRN_NORM_PKSB_10
#   define WRN_NORM_PKSB_10 (202U)
#  endif

#  ifndef WRN_NORM_PKSB_11
#   define WRN_NORM_PKSB_11 (203U)
#  endif

#  ifndef WRN_NORM_PKSB_13
#   define WRN_NORM_PKSB_13 (204U)
#  endif

#  ifndef WRN_NORM_PKSB_14
#   define WRN_NORM_PKSB_14 (205U)
#  endif

#  ifndef WRN_NORM_ISA_02
#   define WRN_NORM_ISA_02 (206U)
#  endif

#  ifndef WRN_NORM_ISA_04
#   define WRN_NORM_ISA_04 (207U)
#  endif

#  ifndef WRN_NORM_TCBM_01
#   define WRN_NORM_TCBM_01 (208U)
#  endif

#  ifndef WRN_NORM_TCBM_02
#   define WRN_NORM_TCBM_02 (209U)
#  endif

#  ifndef WRN_NORM_ADAFRO_02
#   define WRN_NORM_ADAFRO_02 (210U)
#  endif

#  ifndef WRN_NORM_PDA_03
#   define WRN_NORM_PDA_03 (211U)
#  endif

#  ifndef WRN_NORM_RTAN_03
#   define WRN_NORM_RTAN_03 (212U)
#  endif

#  ifndef WRN_NORM_SEA_02
#   define WRN_NORM_SEA_02 (213U)
#  endif

#  ifndef WRN_NORM_T120_01
#   define WRN_NORM_T120_01 (214U)
#  endif

#  ifndef WRN_POWER_EIGCON_02
#   define WRN_POWER_EIGCON_02 (215U)
#  endif

#  ifndef WRN_POWER_EIGCON_04
#   define WRN_POWER_EIGCON_04 (216U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_02
#   define WRN_PROSRV_PROSRV_02 (217U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_03
#   define WRN_PROSRV_PROSRV_03 (218U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_04
#   define WRN_PROSRV_PROSRV_04 (219U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_05
#   define WRN_PROSRV_PROSRV_05 (220U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_08
#   define WRN_PROSRV_PROSRV_08 (221U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_09
#   define WRN_PROSRV_PROSRV_09 (222U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_10
#   define WRN_PROSRV_PROSRV_10 (223U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_11
#   define WRN_PROSRV_PROSRV_11 (224U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_12
#   define WRN_PROSRV_PROSRV_12 (225U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_13
#   define WRN_PROSRV_PROSRV_13 (226U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_22
#   define WRN_PROSRV_PROSRV_22 (227U)
#  endif

#  ifndef WRN_PROSRV_PROSRV_23
#   define WRN_PROSRV_PROSRV_23 (228U)
#  endif

#  ifndef WRN_NORM_BATCOO_02
#   define WRN_NORM_BATCOO_02 (229U)
#  endif

#  ifndef WRN_NORM_BATCOO_03
#   define WRN_NORM_BATCOO_03 (230U)
#  endif

#  ifndef WRN_NORM_LDA_02
#   define WRN_NORM_LDA_02 (231U)
#  endif

#  ifndef WRN_NORM_LDA_03
#   define WRN_NORM_LDA_03 (232U)
#  endif

#  ifndef WRN_NORM_LDA_06
#   define WRN_NORM_LDA_06 (233U)
#  endif

#  ifndef WRN_NORM_LDA_07
#   define WRN_NORM_LDA_07 (234U)
#  endif

#  ifndef WRN_NORM_LTA_02
#   define WRN_NORM_LTA_02 (235U)
#  endif

#  ifndef WRN_NORM_LTA_03
#   define WRN_NORM_LTA_03 (236U)
#  endif

#  ifndef WRN_NORM_LTA_07
#   define WRN_NORM_LTA_07 (237U)
#  endif

#  ifndef WRN_NORM_LCA_02
#   define WRN_NORM_LCA_02 (238U)
#  endif

#  ifndef WRN_NORM_LCA_03
#   define WRN_NORM_LCA_03 (239U)
#  endif

#  ifndef WRN_NORM_LCA_04
#   define WRN_NORM_LCA_04 (240U)
#  endif

#  ifndef WRN_NORM_LCA_05
#   define WRN_NORM_LCA_05 (241U)
#  endif

#  ifndef WRN_NORM_LCA_15
#   define WRN_NORM_LCA_15 (242U)
#  endif

#  ifndef WRN_NORM_LCA_16
#   define WRN_NORM_LCA_16 (243U)
#  endif

#  ifndef WRN_NORM_LCA_17
#   define WRN_NORM_LCA_17 (244U)
#  endif

#  ifndef WRN_NORM_LCA_20
#   define WRN_NORM_LCA_20 (245U)
#  endif

#  ifndef WRN_NORM_RSA_01
#   define WRN_NORM_RSA_01 (246U)
#  endif

#  ifndef WRN_NORM_RSA_04
#   define WRN_NORM_RSA_04 (247U)
#  endif

#  ifndef WRN_NORM_RSA_05
#   define WRN_NORM_RSA_05 (248U)
#  endif

#  ifndef WRN_NORM_CHADYN_01
#   define WRN_NORM_CHADYN_01 (249U)
#  endif

#  ifndef WRN_NORM_CHADYN_02
#   define WRN_NORM_CHADYN_02 (250U)
#  endif

#  ifndef WRN_NORM_TOWWAR_02
#   define WRN_NORM_TOWWAR_02 (251U)
#  endif

#  ifndef WRN_NORM_TOWWAR_03
#   define WRN_NORM_TOWWAR_03 (252U)
#  endif

#  ifndef WRN_NORM_TOWWAR_05
#   define WRN_NORM_TOWWAR_05 (253U)
#  endif

#  ifndef WRN_NORM_DMC_02
#   define WRN_NORM_DMC_02 (254U)
#  endif

#  ifndef WRN_NORM_DMC_03
#   define WRN_NORM_DMC_03 (255U)
#  endif

#  ifndef WRN_NORM_DMC_05
#   define WRN_NORM_DMC_05 (256U)
#  endif

#  ifndef WRN_NORM_DMC_06
#   define WRN_NORM_DMC_06 (257U)
#  endif

#  ifndef WRN_NORM_DMC_12
#   define WRN_NORM_DMC_12 (258U)
#  endif

#  ifndef WRN_NORM_DMC_13
#   define WRN_NORM_DMC_13 (259U)
#  endif

#  ifndef WRN_NORM_DMC_14
#   define WRN_NORM_DMC_14 (260U)
#  endif

#  ifndef WRN_NORM_DMC_15
#   define WRN_NORM_DMC_15 (261U)
#  endif

#  ifndef WRN_NORM_DMC_17
#   define WRN_NORM_DMC_17 (262U)
#  endif

#  ifndef WRN_NORM_DMC_18
#   define WRN_NORM_DMC_18 (263U)
#  endif

#  ifndef WRN_NORM_ICYRA_01
#   define WRN_NORM_ICYRA_01 (264U)
#  endif

#  ifndef WRN_NORM_SEA_NCYC_02
#   define WRN_NORM_SEA_NCYC_02 (265U)
#  endif

#  ifndef WRN_NORM_DRIPOW_02
#   define WRN_NORM_DRIPOW_02 (266U)
#  endif

#  ifndef WRN_NORM_DRIPOW_03
#   define WRN_NORM_DRIPOW_03 (267U)
#  endif

#  ifndef WRN_NORM_DRIPOW_04
#   define WRN_NORM_DRIPOW_04 (268U)
#  endif

#  ifndef WRN_NORM_CCS_02
#   define WRN_NORM_CCS_02 (269U)
#  endif

#  ifndef WRN_NORM_CCS_03
#   define WRN_NORM_CCS_03 (270U)
#  endif

#  ifndef WRN_NORM_ACC_02
#   define WRN_NORM_ACC_02 (271U)
#  endif

#  ifndef WRN_NORM_ACC_03
#   define WRN_NORM_ACC_03 (272U)
#  endif

#  ifndef WRN_NORM_ACC_04
#   define WRN_NORM_ACC_04 (273U)
#  endif

#  ifndef WRN_NORM_ACC_05
#   define WRN_NORM_ACC_05 (274U)
#  endif

#  ifndef WRN_NORM_ACC_06
#   define WRN_NORM_ACC_06 (275U)
#  endif

#  ifndef WRN_NORM_ACC_07
#   define WRN_NORM_ACC_07 (276U)
#  endif

#  ifndef WRN_NORM_ACC_08
#   define WRN_NORM_ACC_08 (277U)
#  endif

#  ifndef WRN_NORM_ACC_09
#   define WRN_NORM_ACC_09 (278U)
#  endif

#  ifndef WRN_NORM_ACC_10
#   define WRN_NORM_ACC_10 (279U)
#  endif

#  ifndef WRN_NORM_ACC_11
#   define WRN_NORM_ACC_11 (280U)
#  endif

#  ifndef WRN_NORM_ACC_12
#   define WRN_NORM_ACC_12 (281U)
#  endif

#  ifndef WRN_NORM_ACC_18
#   define WRN_NORM_ACC_18 (282U)
#  endif

#  ifndef WRN_NORM_ACC_19
#   define WRN_NORM_ACC_19 (283U)
#  endif

#  ifndef WRN_NORM_ACC_21
#   define WRN_NORM_ACC_21 (284U)
#  endif

#  ifndef WRN_NORM_DESA_02
#   define WRN_NORM_DESA_02 (285U)
#  endif

#  ifndef WRN_NORM_DESA_03
#   define WRN_NORM_DESA_03 (286U)
#  endif

#  ifndef WRN_NORM_DESA_04
#   define WRN_NORM_DESA_04 (287U)
#  endif

#  ifndef WRN_NORM_DESA_05
#   define WRN_NORM_DESA_05 (288U)
#  endif

#  ifndef WRN_NORM_DESA_06
#   define WRN_NORM_DESA_06 (289U)
#  endif

#  ifndef WRN_NORM_DESA_07
#   define WRN_NORM_DESA_07 (290U)
#  endif

#  ifndef WRN_NORM_DESA_08
#   define WRN_NORM_DESA_08 (291U)
#  endif

#  ifndef WRN_NORM_PEXI_02
#   define WRN_NORM_PEXI_02 (292U)
#  endif

#  ifndef WRN_NORM_RESADJ_09
#   define WRN_NORM_RESADJ_09 (293U)
#  endif

#  ifndef WRN_NORM_RESADJ_10
#   define WRN_NORM_RESADJ_10 (294U)
#  endif

#  ifndef WRN_NORM_RESADJ_11
#   define WRN_NORM_RESADJ_11 (295U)
#  endif

#  ifndef WRN_NORM_RESADJ_12
#   define WRN_NORM_RESADJ_12 (296U)
#  endif

#  ifndef WRN_NORM_RESADJ_13
#   define WRN_NORM_RESADJ_13 (297U)
#  endif

#  ifndef WRN_NORM_RESADJ_14
#   define WRN_NORM_RESADJ_14 (298U)
#  endif

#  ifndef WRN_NORM_RESADJ_15
#   define WRN_NORM_RESADJ_15 (299U)
#  endif

#  ifndef WRN_NORM_TSMODE_02
#   define WRN_NORM_TSMODE_02 (300U)
#  endif

#  ifndef WRN_NORM_UNIOVE_02
#   define WRN_NORM_UNIOVE_02 (301U)
#  endif

#  ifndef WRN_NORM_UNIOVE_04
#   define WRN_NORM_UNIOVE_04 (302U)
#  endif

#  ifndef WARN_ADAS_SDG_01
#   define WARN_ADAS_SDG_01 (303U)
#  endif

#  ifndef WRN_ADAS_PDA_01
#   define WRN_ADAS_PDA_01 (304U)
#  endif

#  ifndef WRN_ADAS_PDA_02
#   define WRN_ADAS_PDA_02 (305U)
#  endif

#  ifndef WRN_NORM_TDOOR_01
#   define WRN_NORM_TDOOR_01 (306U)
#  endif

#  ifndef WRN_NORM_TDOOR_02
#   define WRN_NORM_TDOOR_02 (307U)
#  endif

#  ifndef WRN_NORM_TDOOR_03
#   define WRN_NORM_TDOOR_03 (308U)
#  endif

#  ifndef WRN_NORM_ACCHOL_02
#   define WRN_NORM_ACCHOL_02 (309U)
#  endif

#  ifndef WRN_NORM_ACCHOL_03
#   define WRN_NORM_ACCHOL_03 (310U)
#  endif

#  ifndef WRN_NORM_ACCHOL_05
#   define WRN_NORM_ACCHOL_05 (311U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_09
#   define WRN_NORM_MAICER_09_RESADJ_09 (312U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_10
#   define WRN_NORM_MAICER_09_RESADJ_10 (313U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_11
#   define WRN_NORM_MAICER_09_RESADJ_11 (314U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_12
#   define WRN_NORM_MAICER_09_RESADJ_12 (315U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_13
#   define WRN_NORM_MAICER_09_RESADJ_13 (316U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_14
#   define WRN_NORM_MAICER_09_RESADJ_14 (317U)
#  endif

#  ifndef WRN_NORM_MAICER_09_RESADJ_15
#   define WRN_NORM_MAICER_09_RESADJ_15 (318U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_09
#   define WRN_NORM_MAICER_11_RESADJ_09 (319U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_10
#   define WRN_NORM_MAICER_11_RESADJ_10 (320U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_11
#   define WRN_NORM_MAICER_11_RESADJ_11 (321U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_12
#   define WRN_NORM_MAICER_11_RESADJ_12 (322U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_13
#   define WRN_NORM_MAICER_11_RESADJ_13 (323U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_14
#   define WRN_NORM_MAICER_11_RESADJ_14 (324U)
#  endif

#  ifndef WRN_NORM_MAICER_11_RESADJ_15
#   define WRN_NORM_MAICER_11_RESADJ_15 (325U)
#  endif

#  ifndef WRN_NORM_CVRS_04
#   define WRN_NORM_CVRS_04 (326U)
#  endif

#  ifndef WRN_NORM_CVRS_05
#   define WRN_NORM_CVRS_05 (327U)
#  endif

#  ifndef WRN_NORM_SMASTA_42
#   define WRN_NORM_SMASTA_42 (328U)
#  endif

#  ifndef WRN_NORM_SMASTA_43
#   define WRN_NORM_SMASTA_43 (329U)
#  endif

#  ifndef WRN_NORM_SMASTA_44
#   define WRN_NORM_SMASTA_44 (330U)
#  endif

#  ifndef WRN_NORM_SMASTA_45
#   define WRN_NORM_SMASTA_45 (331U)
#  endif

#  ifndef WRN_NORM_SMASTA_46
#   define WRN_NORM_SMASTA_46 (332U)
#  endif

#  ifndef WRN_NORM_SMASTA_47
#   define WRN_NORM_SMASTA_47 (333U)
#  endif

#  ifndef WRN_NORM_SMASTA_48
#   define WRN_NORM_SMASTA_48 (334U)
#  endif

#  ifndef WRN_MFLID_MFLID_01
#   define WRN_MFLID_MFLID_01 (335U)
#  endif

#  ifndef WRN_NORM_MFLID_02
#   define WRN_NORM_MFLID_02 (336U)
#  endif

#  ifndef WRN_NORM_MFLID_03
#   define WRN_NORM_MFLID_03 (337U)
#  endif

#  ifndef WRN_NORM_TMNT_15
#   define WRN_NORM_TMNT_15 (338U)
#  endif

#  ifndef WRN_NORM_TMNT_16
#   define WRN_NORM_TMNT_16 (339U)
#  endif

#  ifndef WRN_ADAS_LCA1
#   define WRN_ADAS_LCA1 (340U)
#  endif

#  ifndef WRN_ADAS_LCA2
#   define WRN_ADAS_LCA2 (341U)
#  endif

#  ifndef WRN_DOOR_UNLMOD_02
#   define WRN_DOOR_UNLMOD_02 (342U)
#  endif

#  ifndef WARN_ADAS_PDA1
#   define WARN_ADAS_PDA1 (343U)
#  endif

#  ifndef WRN_ADAS_URSM_01
#   define WRN_ADAS_URSM_01 (344U)
#  endif

#  ifndef WRN_ADAS_URSM_02
#   define WRN_ADAS_URSM_02 (345U)
#  endif

#  ifndef WRN_ADAS_URSM_03
#   define WRN_ADAS_URSM_03 (346U)
#  endif

#  ifndef WRN_ADAS_URSM_04
#   define WRN_ADAS_URSM_04 (347U)
#  endif

#  ifndef WRN_ADAS_URSM_05
#   define WRN_ADAS_URSM_05 (348U)
#  endif

#  ifndef WRN_ADAS_URSM_06
#   define WRN_ADAS_URSM_06 (349U)
#  endif

#  ifndef WRN_ADAS_URSM_07
#   define WRN_ADAS_URSM_07 (350U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND1
#   define WRN_NORM_SYSMAL_HVIND1 (351U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND2
#   define WRN_NORM_SYSMAL_HVIND2 (352U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND3
#   define WRN_NORM_SYSMAL_HVIND3 (353U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND4
#   define WRN_NORM_SYSMAL_HVIND4 (354U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND5
#   define WRN_NORM_SYSMAL_HVIND5 (355U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND6
#   define WRN_NORM_SYSMAL_HVIND6 (356U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND7
#   define WRN_NORM_SYSMAL_HVIND7 (357U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND8
#   define WRN_NORM_SYSMAL_HVIND8 (358U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND9
#   define WRN_NORM_SYSMAL_HVIND9 (359U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND10
#   define WRN_NORM_SYSMAL_HVIND10 (360U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND11
#   define WRN_NORM_SYSMAL_HVIND11 (361U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND12
#   define WRN_NORM_SYSMAL_HVIND12 (362U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND13
#   define WRN_NORM_SYSMAL_HVIND13 (363U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND14
#   define WRN_NORM_SYSMAL_HVIND14 (364U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND15
#   define WRN_NORM_SYSMAL_HVIND15 (365U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND16
#   define WRN_NORM_SYSMAL_HVIND16 (366U)
#  endif

#  ifndef WRN_NORM_SYSMAL_HVIND17
#   define WRN_NORM_SYSMAL_HVIND17 (367U)
#  endif

#  ifndef WRN_NORM_FHL_04
#   define WRN_NORM_FHL_04 (368U)
#  endif

#  ifndef WRN_NORM_SMASTA_52
#   define WRN_NORM_SMASTA_52 (369U)
#  endif

#  ifndef WRN_NORM_SMASTA_53
#   define WRN_NORM_SMASTA_53 (370U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_02
#   define WRN_NORM_GPF_MEV01_02 (371U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_03
#   define WRN_NORM_GPF_MEV01_03 (372U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_04
#   define WRN_NORM_GPF_MEV01_04 (373U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_05
#   define WRN_NORM_GPF_MEV01_05 (374U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_06
#   define WRN_NORM_GPF_MEV01_06 (375U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_07
#   define WRN_NORM_GPF_MEV01_07 (376U)
#  endif

#  ifndef WRN_NORM_GPF_MEV01_08
#   define WRN_NORM_GPF_MEV01_08 (377U)
#  endif

#  ifndef WRN_NORM_VCOPE_02
#   define WRN_NORM_VCOPE_02 (378U)
#  endif

#  ifndef WRN_NORM_VCOPE_03
#   define WRN_NORM_VCOPE_03 (379U)
#  endif

#  ifndef WRN_ADAS_LCA_01
#   define WRN_ADAS_LCA_01 (380U)
#  endif

#  ifndef WRN_ADAS_LCA_03
#   define WRN_ADAS_LCA_03 (381U)
#  endif

#  ifndef WRN_ADAS_LCA_04
#   define WRN_ADAS_LCA_04 (382U)
#  endif

#  ifndef WRN_NORM_FCMDI_01
#   define WRN_NORM_FCMDI_01 (383U)
#  endif

#  ifndef WRN_NORM_FCMDI_02
#   define WRN_NORM_FCMDI_02 (384U)
#  endif

#  ifndef WRN_NORM_FCMDI_03
#   define WRN_NORM_FCMDI_03 (385U)
#  endif

#  ifndef WRN_NORM_FCMDI_04
#   define WRN_NORM_FCMDI_04 (386U)
#  endif

#  ifndef WRN_NORM_FCMDI_05
#   define WRN_NORM_FCMDI_05 (387U)
#  endif

#  ifndef WRN_NORM_FCMDI_06
#   define WRN_NORM_FCMDI_06 (388U)
#  endif

#  ifndef WRN_NORM_FCMDI_07
#   define WRN_NORM_FCMDI_07 (389U)
#  endif

#  ifndef WRN_NORM_TSMODE_VM01_02
#   define WRN_NORM_TSMODE_VM01_02 (390U)
#  endif

#  ifndef WRN_ADAS_ACC_01
#   define WRN_ADAS_ACC_01 (391U)
#  endif

#  ifndef WRN_ADAS_ACC_02
#   define WRN_ADAS_ACC_02 (392U)
#  endif

#  ifndef WRN_ADAS_ACC_03
#   define WRN_ADAS_ACC_03 (393U)
#  endif

#  ifndef WRN_ADAS_ACC_04
#   define WRN_ADAS_ACC_04 (394U)
#  endif

#  ifndef WRN_ADAS_ACC_05
#   define WRN_ADAS_ACC_05 (395U)
#  endif

#  ifndef WRN_ADAS_ACC_22
#   define WRN_ADAS_ACC_22 (396U)
#  endif

#  ifndef WRN_ADAS_ACC_23
#   define WRN_ADAS_ACC_23 (397U)
#  endif

#  ifndef WRN_ADAS_ACC_24
#   define WRN_ADAS_ACC_24 (398U)
#  endif

#  ifndef WRN_ADAS_ACC_25
#   define WRN_ADAS_ACC_25 (399U)
#  endif

#  ifndef WRN_ADAS_ACC_26
#   define WRN_ADAS_ACC_26 (400U)
#  endif

#  ifndef WRN_ADAS_ACC_27
#   define WRN_ADAS_ACC_27 (401U)
#  endif

#  ifndef WRN_ADAS_ACC_28
#   define WRN_ADAS_ACC_28 (402U)
#  endif

#  ifndef WRN_ADAS_ACC_29
#   define WRN_ADAS_ACC_29 (403U)
#  endif

#  ifndef WRN_ADAS_ACC_30
#   define WRN_ADAS_ACC_30 (404U)
#  endif

#  ifndef WRN_ADAS_ACC_31
#   define WRN_ADAS_ACC_31 (405U)
#  endif

#  ifndef WRN_ADAS_ACC_32
#   define WRN_ADAS_ACC_32 (406U)
#  endif

#  ifndef WRN_ADAS_ACC_33
#   define WRN_ADAS_ACC_33 (407U)
#  endif

#  ifndef WRN_ADAS_ACC_34
#   define WRN_ADAS_ACC_34 (408U)
#  endif

#  ifndef WRN_ADAS_ACC_35
#   define WRN_ADAS_ACC_35 (409U)
#  endif

#  ifndef WRN_ADAS_ACC_36
#   define WRN_ADAS_ACC_36 (410U)
#  endif

#  ifndef WRN_ADAS_ACC_37
#   define WRN_ADAS_ACC_37 (411U)
#  endif

#  ifndef WRN_ADAS_ACC_38
#   define WRN_ADAS_ACC_38 (412U)
#  endif

#  ifndef WRN_ADAS_ACC_39
#   define WRN_ADAS_ACC_39 (413U)
#  endif

#  ifndef WRN_ADAS_ACC_40
#   define WRN_ADAS_ACC_40 (414U)
#  endif

#  ifndef WRN_ADAS_ACC_41
#   define WRN_ADAS_ACC_41 (415U)
#  endif

#  ifndef WRN_ADAS_ACC_42
#   define WRN_ADAS_ACC_42 (416U)
#  endif

#  ifndef WRN_ADAS_ACC_43
#   define WRN_ADAS_ACC_43 (417U)
#  endif

#  ifndef WRN_ADAS_ACC_44
#   define WRN_ADAS_ACC_44 (418U)
#  endif

#  ifndef WRN_ADAS_ACC_45
#   define WRN_ADAS_ACC_45 (419U)
#  endif

#  ifndef WRN_ADAS_ACC_46
#   define WRN_ADAS_ACC_46 (420U)
#  endif

#  ifndef WRN_ADAS_ACC_47
#   define WRN_ADAS_ACC_47 (421U)
#  endif

#  ifndef WRN_ADAS_ACC_48
#   define WRN_ADAS_ACC_48 (422U)
#  endif

#  ifndef WRN_ADAS_ACC_49
#   define WRN_ADAS_ACC_49 (423U)
#  endif

#  ifndef WRN_ADAS_ACC_50
#   define WRN_ADAS_ACC_50 (424U)
#  endif

#  ifndef WRN_ADAS_ACC_51
#   define WRN_ADAS_ACC_51 (425U)
#  endif

#  ifndef WRN_ADAS_ACC_52
#   define WRN_ADAS_ACC_52 (426U)
#  endif

#  ifndef WRN_ADAS_ACC_53
#   define WRN_ADAS_ACC_53 (427U)
#  endif

#  ifndef WRN_ADAS_ACC_54
#   define WRN_ADAS_ACC_54 (428U)
#  endif

#  ifndef WRN_ADAS_ACC_55
#   define WRN_ADAS_ACC_55 (429U)
#  endif

#  ifndef WRN_ADAS_ACC_56
#   define WRN_ADAS_ACC_56 (430U)
#  endif

#  ifndef WRN_ADAS_ACC_57
#   define WRN_ADAS_ACC_57 (431U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_02
#   define WRN_NORM_ACC_VM01_GSY07_02 (432U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_03
#   define WRN_NORM_ACC_VM01_GSY07_03 (433U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_04
#   define WRN_NORM_ACC_VM01_GSY07_04 (434U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_05
#   define WRN_NORM_ACC_VM01_GSY07_05 (435U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_06
#   define WRN_NORM_ACC_VM01_GSY07_06 (436U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_07
#   define WRN_NORM_ACC_VM01_GSY07_07 (437U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_08
#   define WRN_NORM_ACC_VM01_GSY07_08 (438U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GSY07_09
#   define WRN_NORM_ACC_VM01_GSY07_09 (439U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE02_02
#   define WRN_NORM_ACC_VM01_EFE02_02 (440U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE02_03
#   define WRN_NORM_ACC_VM01_EFE02_03 (441U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE02_04
#   define WRN_NORM_ACC_VM01_EFE02_04 (442U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE02_05
#   define WRN_NORM_ACC_VM01_EFE02_05 (443U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE01_02
#   define WRN_NORM_ACC_VM01_EFE01_02 (444U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE01_03
#   define WRN_NORM_ACC_VM01_EFE01_03 (445U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE01_04
#   define WRN_NORM_ACC_VM01_EFE01_04 (446U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_EFE01_05
#   define WRN_NORM_ACC_VM01_EFE01_05 (447U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_02
#   define WRN_NORM_ACC_VM01_GME12_02 (448U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_03
#   define WRN_NORM_ACC_VM01_GME12_03 (449U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_04
#   define WRN_NORM_ACC_VM01_GME12_04 (450U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_05
#   define WRN_NORM_ACC_VM01_GME12_05 (451U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_06
#   define WRN_NORM_ACC_VM01_GME12_06 (452U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_07
#   define WRN_NORM_ACC_VM01_GME12_07 (453U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_08
#   define WRN_NORM_ACC_VM01_GME12_08 (454U)
#  endif

#  ifndef WRN_NORM_ACC_VM01_GME12_09
#   define WRN_NORM_ACC_VM01_GME12_09 (455U)
#  endif

#  ifndef WRN_NORM_FCTA_01
#   define WRN_NORM_FCTA_01 (456U)
#  endif

#  ifndef WARN_NORM_GRISHU_02
#   define WARN_NORM_GRISHU_02 (457U)
#  endif

#  ifndef WRN_NORM_CHEENG_06
#   define WRN_NORM_CHEENG_06 (458U)
#  endif

#  ifndef WRN_NORM_SFTPOSL_02
#   define WRN_NORM_SFTPOSL_02 (459U)
#  endif

#  ifndef WRN_NORM_SFTPOSL_03
#   define WRN_NORM_SFTPOSL_03 (460U)
#  endif

#  ifndef WRN_NORM_SFTPOSL_04
#   define WRN_NORM_SFTPOSL_04 (461U)
#  endif

#  ifndef WRN_NORM_TPMS_02
#   define WRN_NORM_TPMS_02 (462U)
#  endif

#  ifndef WRN_NORM_TPMS_03
#   define WRN_NORM_TPMS_03 (463U)
#  endif

#  ifndef WRN_NORM_STOSTA_02
#   define WRN_NORM_STOSTA_02 (464U)
#  endif

#  ifndef WRN_NORM_RSRDI_02
#   define WRN_NORM_RSRDI_02 (465U)
#  endif

#  ifndef WRN_NORM_PSSDI_02
#   define WRN_NORM_PSSDI_02 (466U)
#  endif

#  ifndef WRN_NORM_UNOVE_02
#   define WRN_NORM_UNOVE_02 (467U)
#  endif

#  ifndef WRN_NORM_UNOVE_04
#   define WRN_NORM_UNOVE_04 (468U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_02
#   define WRN_CUSTMIZE_PERSET_02 (469U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_03
#   define WRN_CUSTMIZE_PERSET_03 (470U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_04
#   define WRN_CUSTMIZE_PERSET_04 (471U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_06
#   define WRN_CUSTMIZE_PERSET_06 (472U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_07
#   define WRN_CUSTMIZE_PERSET_07 (473U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_08
#   define WRN_CUSTMIZE_PERSET_08 (474U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_09
#   define WRN_CUSTMIZE_PERSET_09 (475U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_10
#   define WRN_CUSTMIZE_PERSET_10 (476U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_11
#   define WRN_CUSTMIZE_PERSET_11 (477U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_12
#   define WRN_CUSTMIZE_PERSET_12 (478U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_13
#   define WRN_CUSTMIZE_PERSET_13 (479U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_14
#   define WRN_CUSTMIZE_PERSET_14 (480U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_15
#   define WRN_CUSTMIZE_PERSET_15 (481U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_16
#   define WRN_CUSTMIZE_PERSET_16 (482U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_17
#   define WRN_CUSTMIZE_PERSET_17 (483U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_18
#   define WRN_CUSTMIZE_PERSET_18 (484U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_19
#   define WRN_CUSTMIZE_PERSET_19 (485U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_20
#   define WRN_CUSTMIZE_PERSET_20 (486U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_21
#   define WRN_CUSTMIZE_PERSET_21 (487U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_22
#   define WRN_CUSTMIZE_PERSET_22 (488U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_23
#   define WRN_CUSTMIZE_PERSET_23 (489U)
#  endif

#  ifndef WRN_CUSTMIZE_PERSET_24
#   define WRN_CUSTMIZE_PERSET_24 (490U)
#  endif

#  ifndef WRN_NORM_SEA_VM01_02
#   define WRN_NORM_SEA_VM01_02 (491U)
#  endif

#  ifndef WRN_NORM_SEA_VM02_02
#   define WRN_NORM_SEA_VM02_02 (492U)
#  endif

#  ifndef WRN_NORM_PSSDI_03
#   define WRN_NORM_PSSDI_03 (493U)
#  endif

#  ifndef WRN_NORM_PSSDI_04
#   define WRN_NORM_PSSDI_04 (494U)
#  endif

#  ifndef WRN_NORM_PSSDI_05
#   define WRN_NORM_PSSDI_05 (495U)
#  endif

#  ifndef WRN_NORM_PSSDI_06
#   define WRN_NORM_PSSDI_06 (496U)
#  endif

#  ifndef WRN_NORM_CLESON_02
#   define WRN_NORM_CLESON_02 (497U)
#  endif

#  ifndef WRN_CUTMIZE_DIGKEY_01
#   define WRN_CUTMIZE_DIGKEY_01 (498U)
#  endif

#  ifndef WRN_NORM_RSRDI_03
#   define WRN_NORM_RSRDI_03 (499U)
#  endif

#  ifndef WRN_ADAS_LCA_02
#   define WRN_ADAS_LCA_02 (500U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ02
#   define WRN_NORM_TPMS_VM02_REQ02 (501U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ03
#   define WRN_NORM_TPMS_VM02_REQ03 (502U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ04
#   define WRN_NORM_TPMS_VM02_REQ04 (503U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ05
#   define WRN_NORM_TPMS_VM02_REQ05 (504U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ06
#   define WRN_NORM_TPMS_VM02_REQ06 (505U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ07
#   define WRN_NORM_TPMS_VM02_REQ07 (506U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ08
#   define WRN_NORM_TPMS_VM02_REQ08 (507U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ09
#   define WRN_NORM_TPMS_VM02_REQ09 (508U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ10
#   define WRN_NORM_TPMS_VM02_REQ10 (509U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_REQ11
#   define WRN_NORM_TPMS_VM02_REQ11 (510U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_GWM08_REQ02
#   define WRN_NORM_TPMS_VM02_GWM08_REQ02 (511U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_GWM08_REQ01
#   define WRN_NORM_TPMS_VM02_GWM08_REQ01 (512U)
#  endif

#  ifndef WRN_NORM_PSSDI_07
#   define WRN_NORM_PSSDI_07 (513U)
#  endif

#  ifndef WRN_NORM_EXWUOC_04
#   define WRN_NORM_EXWUOC_04 (514U)
#  endif

#  ifndef WRN_NORM_EXWUOC_06
#   define WRN_NORM_EXWUOC_06 (515U)
#  endif

#  ifndef WRN_NORM_EXWUOC_10
#   define WRN_NORM_EXWUOC_10 (516U)
#  endif

#  ifndef WRN_NORM_EXWUOC_16
#   define WRN_NORM_EXWUOC_16 (517U)
#  endif

#  ifndef WRN_NORM_EXWUOC_17
#   define WRN_NORM_EXWUOC_17 (518U)
#  endif

#  ifndef WRN_NORM_EXWUOC_18
#   define WRN_NORM_EXWUOC_18 (519U)
#  endif

#  ifndef WRN_NORM_PBD_02
#   define WRN_NORM_PBD_02 (520U)
#  endif

#  ifndef WRN_NORM_FCTA_02
#   define WRN_NORM_FCTA_02 (521U)
#  endif

#  ifndef WRN_NORM_TMN_02
#   define WRN_NORM_TMN_02 (522U)
#  endif

#  ifndef WRN_NORM_TMN_03
#   define WRN_NORM_TMN_03 (523U)
#  endif

#  ifndef WRN_NORM_PEDPRO_03
#   define WRN_NORM_PEDPRO_03 (524U)
#  endif

#  ifndef WRN_NORM_PEDPRO_04
#   define WRN_NORM_PEDPRO_04 (525U)
#  endif

#  ifndef WRN_NORM_LEAUNF_02
#   define WRN_NORM_LEAUNF_02 (526U)
#  endif

#  ifndef WRN_NORM_LEAUNF_04
#   define WRN_NORM_LEAUNF_04 (527U)
#  endif

#  ifndef WRN_NORM_HCS_02
#   define WRN_NORM_HCS_02 (528U)
#  endif

#  ifndef WRN_NORM_HCS_03
#   define WRN_NORM_HCS_03 (529U)
#  endif

#  ifndef WRN_NORM_HCS_04
#   define WRN_NORM_HCS_04 (530U)
#  endif

#  ifndef WRN_NORM_HCS_05
#   define WRN_NORM_HCS_05 (531U)
#  endif

#  ifndef WRN_NORM_HCS_06
#   define WRN_NORM_HCS_06 (532U)
#  endif

#  ifndef WRN_NORM_HCS_07
#   define WRN_NORM_HCS_07 (533U)
#  endif

#  ifndef WRN_NORM_HCS_08
#   define WRN_NORM_HCS_08 (534U)
#  endif

#  ifndef WRN_NORM_HCS_09
#   define WRN_NORM_HCS_09 (535U)
#  endif

#  ifndef WRN_NORM_HCS_10
#   define WRN_NORM_HCS_10 (536U)
#  endif

#  ifndef WRN_NORM_HCS_11
#   define WRN_NORM_HCS_11 (537U)
#  endif

#  ifndef WRN_NORM_SCB_02
#   define WRN_NORM_SCB_02 (538U)
#  endif

#  ifndef WRN_NORM_ITS_02
#   define WRN_NORM_ITS_02 (539U)
#  endif

#  ifndef WRN_NORM_ITS_06
#   define WRN_NORM_ITS_06 (540U)
#  endif

#  ifndef WRN_NORM_ITS_MEV01_02
#   define WRN_NORM_ITS_MEV01_02 (541U)
#  endif

#  ifndef WRN_NORM_ITS_MEV01_04
#   define WRN_NORM_ITS_MEV01_04 (542U)
#  endif

#  ifndef WRN_NORM_ITS_MEV01_05
#   define WRN_NORM_ITS_MEV01_05 (543U)
#  endif

#  ifndef WRN_NORM_ITS_MEV01_06
#   define WRN_NORM_ITS_MEV01_06 (544U)
#  endif

#  ifndef WRN_NORM_MAPACC_02
#   define WRN_NORM_MAPACC_02 (545U)
#  endif

#  ifndef WRN_NORM_OAA_03
#   define WRN_NORM_OAA_03 (546U)
#  endif

#  ifndef WRN_NORM_OAA_04
#   define WRN_NORM_OAA_04 (547U)
#  endif

#  ifndef WRN_NORM_LCA_21
#   define WRN_NORM_LCA_21 (548U)
#  endif

#  ifndef WRN_NORM_LCA_26
#   define WRN_NORM_LCA_26 (549U)
#  endif

#  ifndef WRN_NORM_LCA_27
#   define WRN_NORM_LCA_27 (550U)
#  endif

#  ifndef WRN_NORM_LCA_28
#   define WRN_NORM_LCA_28 (551U)
#  endif

#  ifndef WRN_NORM_LCA_29
#   define WRN_NORM_LCA_29 (552U)
#  endif

#  ifndef WRN_NORM_LCA_30
#   define WRN_NORM_LCA_30 (553U)
#  endif

#  ifndef WRN_NORM_LCA_31
#   define WRN_NORM_LCA_31 (554U)
#  endif

#  ifndef WRN_NORM_NLOCK_02
#   define WRN_NORM_NLOCK_02 (555U)
#  endif

#  ifndef WRN_NORM_ATFWRN_02
#   define WRN_NORM_ATFWRN_02 (556U)
#  endif

#  ifndef WRN_NORM_LTA_04
#   define WRN_NORM_LTA_04 (557U)
#  endif

#  ifndef WRN_NORM_LTA_05
#   define WRN_NORM_LTA_05 (558U)
#  endif

#  ifndef WRN_NORM_LTA_06
#   define WRN_NORM_LTA_06 (559U)
#  endif

#  ifndef WRN_NORM_LTA_08
#   define WRN_NORM_LTA_08 (560U)
#  endif

#  ifndef WRN_NORM_LTA_09
#   define WRN_NORM_LTA_09 (561U)
#  endif

#  ifndef WRN_NORM_LTA_10
#   define WRN_NORM_LTA_10 (562U)
#  endif

#  ifndef WRN_NORM_LTA_11
#   define WRN_NORM_LTA_11 (563U)
#  endif

#  ifndef WRN_NORM_LTA_12
#   define WRN_NORM_LTA_12 (564U)
#  endif

#  ifndef WRN_NORM_PCL_02
#   define WRN_NORM_PCL_02 (565U)
#  endif

#  ifndef WRN_ADAS_LCA_05
#   define WRN_ADAS_LCA_05 (566U)
#  endif

#  ifndef WRN_ADAS_LCA_06
#   define WRN_ADAS_LCA_06 (567U)
#  endif

#  ifndef WRN_ADAS_LCA_07
#   define WRN_ADAS_LCA_07 (568U)
#  endif

#  ifndef WRN_ADAS_LCA_08
#   define WRN_ADAS_LCA_08 (569U)
#  endif

#  ifndef WRN_ADAS_LCA_09
#   define WRN_ADAS_LCA_09 (570U)
#  endif

#  ifndef WRN_ADAS_LCA_10
#   define WRN_ADAS_LCA_10 (571U)
#  endif

#  ifndef WRN_ADAS_LCA_11
#   define WRN_ADAS_LCA_11 (572U)
#  endif

#  ifndef WRN_ADAS_LCA_12
#   define WRN_ADAS_LCA_12 (573U)
#  endif

#  ifndef WRN_NORM_LDA_04
#   define WRN_NORM_LDA_04 (574U)
#  endif

#  ifndef WRN_NORM_LDA_05
#   define WRN_NORM_LDA_05 (575U)
#  endif

#  ifndef WRN_ADAS_OAA_01
#   define WRN_ADAS_OAA_01 (576U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_GWM08_REQ06
#   define WRN_NORM_TPMS_VM02_GWM08_REQ06 (577U)
#  endif

#  ifndef WRN_NORM_TPMS_VM02_GWM08_REQ07
#   define WRN_NORM_TPMS_VM02_GWM08_REQ07 (578U)
#  endif

#  ifndef WRN_ADAS_ACC_G7
#   define WRN_ADAS_ACC_G7 (579U)
#  endif

#  ifndef WRN_ADAS_ACC_G11_01
#   define WRN_ADAS_ACC_G11_01 (580U)
#  endif

#  ifndef WRN_ADAS_ACC_G11_02
#   define WRN_ADAS_ACC_G11_02 (581U)
#  endif

#  ifndef WRN_ADAS_ACC_G11_03
#   define WRN_ADAS_ACC_G11_03 (582U)
#  endif

#  ifndef WRN_ADAS_ACC_G20
#   define WRN_ADAS_ACC_G20 (583U)
#  endif

#  ifndef WRN_ADAS_ACC_G22
#   define WRN_ADAS_ACC_G22 (584U)
#  endif

#  ifndef WRN_ADAS_ACC_G23
#   define WRN_ADAS_ACC_G23 (585U)
#  endif

#  ifndef HUD_WRN_NORM_PCS1_05
#   define HUD_WRN_NORM_PCS1_05 (586U)
#  endif

#  ifndef HUD_WRN_NORM_PCS1_06
#   define HUD_WRN_NORM_PCS1_06 (587U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G20
#   define HUD_WRN_ADAS_ACC_G20 (588U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G7
#   define HUD_WRN_ADAS_ACC_G7 (589U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G23
#   define HUD_WRN_ADAS_ACC_G23 (590U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G22
#   define HUD_WRN_ADAS_ACC_G22 (591U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_02
#   define HUD_WRN_ADAS_LCA_02 (592U)
#  endif

#  ifndef HUD_WRN_NORM_DA_02
#   define HUD_WRN_NORM_DA_02 (593U)
#  endif

#  ifndef HUD_WRN_NORM_SCB_02
#   define HUD_WRN_NORM_SCB_02 (594U)
#  endif

#  ifndef HUD_WRN_NORM_ITS_MEV01_04
#   define HUD_WRN_NORM_ITS_MEV01_04 (595U)
#  endif

#  ifndef HUD_WRN_NORM_ITS_MEV01_02
#   define HUD_WRN_NORM_ITS_MEV01_02 (596U)
#  endif

#  ifndef HUD_WRN_NORM_ITS_02
#   define HUD_WRN_NORM_ITS_02 (597U)
#  endif

#  ifndef HUD_WRN_NORM_BOS_02
#   define HUD_WRN_NORM_BOS_02 (598U)
#  endif

#  ifndef HUD_WRN_NORM_DSC_02
#   define HUD_WRN_NORM_DSC_02 (599U)
#  endif

#  ifndef HUD_WRN_NORM_PMAR_03
#   define HUD_WRN_NORM_PMAR_03 (600U)
#  endif

#  ifndef HUD_WRN_ADAS_OAA_01
#   define HUD_WRN_ADAS_OAA_01 (601U)
#  endif

#  ifndef HUD_WRN_NORM_ACC_19
#   define HUD_WRN_NORM_ACC_19 (602U)
#  endif

#  ifndef HUD_WRN_NORM_LCA_29
#   define HUD_WRN_NORM_LCA_29 (603U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_05
#   define HUD_WRN_ADAS_LCA_05 (604U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_06
#   define HUD_WRN_ADAS_LCA_06 (605U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_07
#   define HUD_WRN_ADAS_LCA_07 (606U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_08
#   define HUD_WRN_ADAS_LCA_08 (607U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_09
#   define HUD_WRN_ADAS_LCA_09 (608U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_10
#   define HUD_WRN_ADAS_LCA_10 (609U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_11
#   define HUD_WRN_ADAS_LCA_11 (610U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_12
#   define HUD_WRN_ADAS_LCA_12 (611U)
#  endif

#  ifndef HUD_WRN_NORM_RTAN_02
#   define HUD_WRN_NORM_RTAN_02 (612U)
#  endif

#  ifndef HUD_WRN_NORM_LDA_02
#   define HUD_WRN_NORM_LDA_02 (613U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_03
#   define HUD_WRN_ADAS_LCA_03 (614U)
#  endif

#  ifndef HUD_WRN_ADAS_LCA_04
#   define HUD_WRN_ADAS_LCA_04 (615U)
#  endif

#  ifndef HUD_WRN_NORM_ACC_21
#   define HUD_WRN_NORM_ACC_21 (616U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G11_01
#   define HUD_WRN_ADAS_ACC_G11_01 (617U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G11_02
#   define HUD_WRN_ADAS_ACC_G11_02 (618U)
#  endif

#  ifndef HUD_WRN_ADAS_ACC_G11_03
#   define HUD_WRN_ADAS_ACC_G11_03 (619U)
#  endif

#  ifndef HUD_WRN_NORM_DSC_04
#   define HUD_WRN_NORM_DSC_04 (620U)
#  endif

#  ifndef WRN_NORM_GROUP1
#   define WRN_NORM_GROUP1 (621U)
#  endif

#  ifndef WRN_NORM_GROUP2
#   define WRN_NORM_GROUP2 (622U)
#  endif

#  ifndef WRN_NORM_GROUP3
#   define WRN_NORM_GROUP3 (623U)
#  endif

#  ifndef WRN_NORM_GROUP4
#   define WRN_NORM_GROUP4 (624U)
#  endif

#  ifndef WRN_NORM_GROUP5
#   define WRN_NORM_GROUP5 (625U)
#  endif

#  ifndef WRN_NORM_GROUP6
#   define WRN_NORM_GROUP6 (626U)
#  endif

#  ifndef WRN_NORM_GROUP7
#   define WRN_NORM_GROUP7 (627U)
#  endif

#  ifndef WRN_NORM_GROUP8
#   define WRN_NORM_GROUP8 (628U)
#  endif

#  ifndef WRN_NORM_GROUP9
#   define WRN_NORM_GROUP9 (629U)
#  endif

#  ifndef TotalNumOfWarnings
#   define TotalNumOfWarnings (630U)
#  endif

#  ifndef UI_WARNING_STATUS_OFF
#   define UI_WARNING_STATUS_OFF (0U)
#  endif

#  ifndef UI_WARNING_STATUS_ON
#   define UI_WARNING_STATUS_ON (1U)
#  endif

#  ifndef UI_WARNING_STATUS_UNKNOWN
#   define UI_WARNING_STATUS_UNKNOWN (2U)
#  endif

#  ifndef eTxSigConfirmStatus_Cleared
#   define eTxSigConfirmStatus_Cleared (0U)
#  endif

#  ifndef eTxSigConfirmStatus_Set
#   define eTxSigConfirmStatus_Set (1U)
#  endif

#  ifndef eTxSigConfirmStatus_NotSupported
#   define eTxSigConfirmStatus_NotSupported (2U)
#  endif

#  ifndef eSecureTxByte0Out
#   define eSecureTxByte0Out (0U)
#  endif

#  ifndef eSecureTxByte1Out
#   define eSecureTxByte1Out (1U)
#  endif

#  ifndef eSecureTxByte2Out
#   define eSecureTxByte2Out (2U)
#  endif

#  ifndef eSecureTxByte3Out
#   define eSecureTxByte3Out (3U)
#  endif

#  ifndef eMAC_TxOut
#   define eMAC_TxOut (4U)
#  endif

#  ifndef eFV_TxOut
#   define eFV_TxOut (5U)
#  endif

#  ifndef eOdometerOut
#   define eOdometerOut (6U)
#  endif

#  ifndef eVehicleSpeedICOut
#   define eVehicleSpeedICOut (7U)
#  endif

#  ifndef eIllumination_PWMOut
#   define eIllumination_PWMOut (8U)
#  endif

#  ifndef eDebug1_Byte0Out
#   define eDebug1_Byte0Out (9U)
#  endif

#  ifndef eDebug1_Byte1Out
#   define eDebug1_Byte1Out (10U)
#  endif

#  ifndef eDebug1_Byte2Out
#   define eDebug1_Byte2Out (11U)
#  endif

#  ifndef eDebug1_Byte3Out
#   define eDebug1_Byte3Out (12U)
#  endif

#  ifndef eDebug1_Byte4Out
#   define eDebug1_Byte4Out (13U)
#  endif

#  ifndef eDebug1_Byte5Out
#   define eDebug1_Byte5Out (14U)
#  endif

#  ifndef eDebug1_Byte6Out
#   define eDebug1_Byte6Out (15U)
#  endif

#  ifndef eDebug1_Byte7Out
#   define eDebug1_Byte7Out (16U)
#  endif

#  ifndef eDebug2_Byte0Out
#   define eDebug2_Byte0Out (17U)
#  endif

#  ifndef eDebug2_Byte1Out
#   define eDebug2_Byte1Out (18U)
#  endif

#  ifndef eDebug2_Byte2Out
#   define eDebug2_Byte2Out (19U)
#  endif

#  ifndef eDebug2_Byte3Out
#   define eDebug2_Byte3Out (20U)
#  endif

#  ifndef eDebug2_Byte4Out
#   define eDebug2_Byte4Out (21U)
#  endif

#  ifndef eDebug2_Byte5Out
#   define eDebug2_Byte5Out (22U)
#  endif

#  ifndef eDebug2_Byte6Out
#   define eDebug2_Byte6Out (23U)
#  endif

#  ifndef eDebug2_Byte7Out
#   define eDebug2_Byte7Out (24U)
#  endif

#  ifndef eDebug3_Byte0Out
#   define eDebug3_Byte0Out (25U)
#  endif

#  ifndef eDebug3_Byte1Out
#   define eDebug3_Byte1Out (26U)
#  endif

#  ifndef eDebug3_Byte2Out
#   define eDebug3_Byte2Out (27U)
#  endif

#  ifndef eDebug3_Byte3Out
#   define eDebug3_Byte3Out (28U)
#  endif

#  ifndef eDebug3_Byte4Out
#   define eDebug3_Byte4Out (29U)
#  endif

#  ifndef eDebug3_Byte5Out
#   define eDebug3_Byte5Out (30U)
#  endif

#  ifndef eDebug3_Byte6Out
#   define eDebug3_Byte6Out (31U)
#  endif

#  ifndef eDebug3_Byte7Out
#   define eDebug3_Byte7Out (32U)
#  endif

#  ifndef eDebug4_Byte0Out
#   define eDebug4_Byte0Out (33U)
#  endif

#  ifndef eDebug4_Byte1Out
#   define eDebug4_Byte1Out (34U)
#  endif

#  ifndef eDebug4_Byte2Out
#   define eDebug4_Byte2Out (35U)
#  endif

#  ifndef eDebug4_Byte3Out
#   define eDebug4_Byte3Out (36U)
#  endif

#  ifndef eDebug4_Byte4Out
#   define eDebug4_Byte4Out (37U)
#  endif

#  ifndef eDebug4_Byte5Out
#   define eDebug4_Byte5Out (38U)
#  endif

#  ifndef eDebug4_Byte6Out
#   define eDebug4_Byte6Out (39U)
#  endif

#  ifndef eDebug4_Byte7Out
#   define eDebug4_Byte7Out (40U)
#  endif

#  ifndef eDebug5_Byte0Out
#   define eDebug5_Byte0Out (41U)
#  endif

#  ifndef eDebug5_Byte1Out
#   define eDebug5_Byte1Out (42U)
#  endif

#  ifndef eDebug5_Byte2Out
#   define eDebug5_Byte2Out (43U)
#  endif

#  ifndef eDebug5_Byte3Out
#   define eDebug5_Byte3Out (44U)
#  endif

#  ifndef eDebug5_Byte4Out
#   define eDebug5_Byte4Out (45U)
#  endif

#  ifndef eDebug5_Byte5Out
#   define eDebug5_Byte5Out (46U)
#  endif

#  ifndef eDebug5_Byte6Out
#   define eDebug5_Byte6Out (47U)
#  endif

#  ifndef eDebug5_Byte7Out
#   define eDebug5_Byte7Out (48U)
#  endif

#  ifndef eEndOfTxSignal
#   define eEndOfTxSignal (49U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CWARNMSG_CORE_OBSERVER_TYPE_H */
