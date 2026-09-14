/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CWarnMsg_Core_Observer.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CWarnMsg_Core_Observer
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CWarnMsg_Core_Observer>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CWarnMsg_Core_Observer.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CWarnMsg_Core_Observer.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CWarnMsg_Core_Observer_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * EChimeStatus: Integer in interval [0...65535]
 * Rte_DT_PayloadArr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Tpms_Arr_u8_5_0: Integer in interval [0...255]
 * Rte_DT_data_u32_5_0: Integer in interval [0...4294967295]
 * Rte_DT_data_u8_10_0: Integer in interval [0...255]
 * Rte_DT_data_u8_8_0: Integer in interval [0...255]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * EButtonId: Enumeration of integer in interval [0...8] with enumerators
 *   EButtonId_None (0U)
 *   EButtonId_Ok (1U)
 *   EButtonId_Up (2U)
 *   EButtonId_Down (3U)
 *   EButtonId_Back (4U)
 *   EButtonId_Menu (5U)
 *   EButtonId_Phone (6U)
 *   EButtonId_Hud (7U)
 *   EButtonId_Last (8U)
 * EButtonSts: Enumeration of integer in interval [0...5] with enumerators
 *   EButtonSts_Off (0U)
 *   EButtonSts_On (1U)
 *   EButtonSts_Short (2U)
 *   EButtonSts_Long (3U)
 *   EButtonSts_Repeat (4U)
 *   EButtonSts_Last (5U)
 * EChimeID: Enumeration of integer in interval [0...1] with enumerators
 *   NO_CHIME_ID (0U)
 *   MAX_CHIME_ID (1U)
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 *   eHMI_NOT_READY (0U)
 *   eHMI_READY (1U)
 * HMI_Screen_Mode: Enumeration of integer in interval [0...9] with enumerators
 *   eSCREENMODE_OFF (0U)
 *   eSCREENMODE_BLANK (1U)
 *   eSCREENMODE_NORMAL (2U)
 *   eSCREENMODE_DISPLAY_ADJ (3U)
 *   eSCREENMODE_WELCOME (4U)
 *   eSCREENMODE_IGNOFF_CHR (5U)
 *   eSCREENMODE_OPENING (6U)
 *   eSCREENMODE_ENDING (7U)
 *   eSCREENMODE_ENDING_IGNOFF_CHR (8U)
 *   eSCREENMODE_RESERVED (9U)
 * Hud_Wake_Type: Enumeration of integer in interval [0...1] with enumerators
 *   HUD_WK_LO (0U)
 *   HUD_WK_HI (1U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * Target_SW_Status: Enumeration of integer in interval [0...7] with enumerators
 *   NO_TARGET (0U)
 *   TG_LEFT (1U)
 *   TG_UP (2U)
 *   TG_DOWN (3U)
 *   TG_RIGHT (4U)
 *   TG_ENTER (5U)
 *   TG_BACK (6U)
 *   TG_MAX (7U)
 * WarningDisplayedStatus: Enumeration of integer in interval [0...32] with enumerators
 *   WRNG_NOTIFIED_NONE (0U)
 *   WRNG_NOTIFIED_ACKNOWLEDGED (1U)
 *   WRNG_NOTIFIED_TIMEOUT (2U)
 *   WRNG_NOTIFIED_HIDDEN (4U)
 *   WRNG_NOTIFIED_SHOW (8U)
 *   WRNG_NOTIFIED_ACTIVE (16U)
 *   WRNG_NOTIFIED_INACTIVE (32U)
 * WarningEvent: Enumeration of integer in interval [0...2] with enumerators
 *   UI_WARNING_EVENT_NONE (0U)
 *   UI_WARNING_EVENT_RETRIGGER (1U)
 *   UI_WARNING_EVENT_FORCED (2U)
 * WarningId: Enumeration of integer in interval [0...630] with enumerators
 *   WRN_NORM_BRLV_02 (0U)
 *   WRN_NORM_ECB_02 (1U)
 *   WRN_NORM_BRK_02 (2U)
 *   WRN_NORM_BRKHLD_10 (3U)
 *   WRN_NORM_BRKHLD_12 (4U)
 *   WRN_NORM_BRKHLD_16 (5U)
 *   WRN_NORM_ABS_02 (6U)
 *   WRN_NORM_AUTHIG_02 (7U)
 *   WRN_NORM_ADAHIG_02 (8U)
 *   WRN_NORM_BRKHLD_02 (9U)
 *   WRN_NORM_BRKHLD_03 (10U)
 *   WRN_NORM_BRKHLD_05 (11U)
 *   WRN_NORM_BRKHLD_06 (12U)
 *   WRN_NORM_BRKHLD_07 (13U)
 *   WRN_NORM_BRKHLD_08 (14U)
 *   WRN_NORM_BRKHLD_11 (15U)
 *   WRN_NORM_BRKHLD_13 (16U)
 *   WRN_NORM_BRKHLD_14 (17U)
 *   WRN_NORM_BRKHLD_15 (18U)
 *   WRN_NORM_BRKHLD_17 (19U)
 *   WRN_NORM_AIRBAG_03 (20U)
 *   WRN_NORM_AUTHIG_04 (21U)
 *   WRN_NORM_ADAHIG_04 (22U)
 *   WRN_NORM_ADASTT_05 (23U)
 *   WRN_NORM_ADASTT_07 (24U)
 *   WRN_NORM_ADASTT_09 (25U)
 *   WRN_NORM_ADASTT_10 (26U)
 *   WRN_NORM_ADASTT_11 (27U)
 *   WRN_NORM_TFUEL_01 (28U)
 *   WRN_NORM_PSC1_02 (29U)
 *   WRN_NORM_PSC1_04 (30U)
 *   WRN_NORM_PSC1_05 (31U)
 *   WRN_NORM_PSC1_06 (32U)
 *   WRN_NORM_PSC1_07 (33U)
 *   WRN_NORM_PSC1_08 (34U)
 *   WRN_NORM_PSC1_09 (35U)
 *   WRN_NORM_PSC1_10 (36U)
 *   WRN_NORM_PSC1_12 (37U)
 *   WRN_NORM_PSC1_13 (38U)
 *   WRN_NORM_EPB_03 (39U)
 *   WRN_NORM_EPB_04 (40U)
 *   WRN_NORM_EPB_05 (41U)
 *   WRN_NORM_EPB_08 (42U)
 *   WRN_NORM_EPB_10 (43U)
 *   WRN_NORM_EPB_11 (44U)
 *   WRN_NORM_EPB_12 (45U)
 *   WRN_NORM_EPB_13 (46U)
 *   WRN_NORM_EPB_14 (47U)
 *   WRN_NORM_EPB_15 (48U)
 *   WRN_NORM_EPB_16 (49U)
 *   WRN_NORM_EPB_17 (50U)
 *   WRN_NORM_EPB_18 (51U)
 *   WRN_NORM_TRCOFF_02 (52U)
 *   WRN_NORM_WASLEV_02 (53U)
 *   WRN_NORM_BVOOPE_02 (54U)
 *   WRN_NORM_THESEN_02 (55U)
 *   WRN_NORM_THESEN_03 (56U)
 *   WRN_CUSTMIZE_DIGKEY_04 (57U)
 *   WRN_CUSTMIZE_DIGKEY_05 (58U)
 *   WRN_CUSTMIZE_DIGKEY_06 (59U)
 *   WRN_CUSTMIZE_DIGKEY_07 (60U)
 *   WRN_NORM_MLGT_01 (61U)
 *   WRN_NORM_TPWSR_01 (62U)
 *   WRN_NORM_TPWSR_02 (63U)
 *   WRN_NORM_TPWSR_03 (64U)
 *   WRN_NORM_SMASTA_02 (65U)
 *   WRN_NORM_SMASTA_03 (66U)
 *   WRN_NORM_SMASTA_04 (67U)
 *   WRN_NORM_SMASTA_05 (68U)
 *   WRN_NORM_SMASTA_06 (69U)
 *   WRN_NORM_SMASTA_07 (70U)
 *   WRN_NORM_SMASTA_08 (71U)
 *   WRN_NORM_SMASTA_09 (72U)
 *   WRN_NORM_SMASTA_10 (73U)
 *   WRN_NORM_SMASTA_11 (74U)
 *   WRN_NORM_SMASTA_12 (75U)
 *   WRN_NORM_SMASTA_13 (76U)
 *   WRN_NORM_SMASTA_17 (77U)
 *   WRN_NORM_SMASTA_18 (78U)
 *   WRN_NORM_SMASTA_19 (79U)
 *   WRN_NORM_SMASTA_20 (80U)
 *   WRN_NORM_SMASTA_21 (81U)
 *   WRN_NORM_SMASTA_23 (82U)
 *   WRN_NORM_SMASTA_24 (83U)
 *   WRN_NORM_SMASTA_25 (84U)
 *   WRN_NORM_SMASTA_26 (85U)
 *   WRN_NORM_SMASTA_28 (86U)
 *   WRN_NORM_SMASTA_29 (87U)
 *   WRN_NORM_SMASTA_30 (88U)
 *   WRN_NORM_SMASTA_31 (89U)
 *   WRN_NORM_SMASTA_32 (90U)
 *   WRN_NORM_SMASTA_33 (91U)
 *   WRN_NORM_SMASTA_34 (92U)
 *   WRN_NORM_SMASTA_36 (93U)
 *   WRN_NORM_SMASTA_37 (94U)
 *   WRN_NORM_SMASTA_38 (95U)
 *   WRN_NORM_SMASTA_39 (96U)
 *   WRN_NORM_SMASTA_40 (97U)
 *   WRN_NORM_SMASTA_41 (98U)
 *   WRN_NORM_LEDHEA_01 (99U)
 *   WRN_NORM_HEALEV_02 (100U)
 *   WRN_NORM_HEALEV_03 (101U)
 *   WRN_NORM_GRISHU_02 (102U)
 *   WRN_NORM_AVAS_02 (103U)
 *   WRN_NORM_ALOA_03 (104U)
 *   WRN_NORM_PCS2_03 (105U)
 *   WRN_NORM_PCS2_11 (106U)
 *   WRN_NORM_TRWIP_01 (107U)
 *   WRN_NORM_RSEREM_02 (108U)
 *   WRN_NORM_RSEREM_03 (109U)
 *   WRN_NORM_RSEREM_04 (110U)
 *   WRN_NORM_RSEREM_05 (111U)
 *   WRN_NORM_4WDSYS_03 (112U)
 *   WRN_NORM_4WDSYS_04 (113U)
 *   WRN_NORM_4WDSYS_06 (114U)
 *   WRN_NORM_CVTOIL_02 (115U)
 *   WRN_NORM_CVTOIL_03 (116U)
 *   WRN_NORM_ATMAL_02 (117U)
 *   WRN_NORM_SFTPOS_02 (118U)
 *   WRN_NORM_SFTPOS_03 (119U)
 *   WRN_NORM_SFTPOS_04 (120U)
 *   WRN_NORM_MCBW_02 (121U)
 *   WRN_NORM_TPWS_01 (122U)
 *   WRN_NORM_TPWS_02 (123U)
 *   WRN_NORM_OILMIL_02 (124U)
 *   WRN_NORM_OILMIL_03 (125U)
 *   WRN_NORM_OILMIL_04 (126U)
 *   WRN_NORM_OILMIL_05 (127U)
 *   WRN_NORM_BRLV0_02 (128U)
 *   WRN_NORM_OILPRE_01 (129U)
 *   WRN_NORM_BRK0_02 (130U)
 *   WRN_NORM_BRK0_03 (131U)
 *   WRN_NORM_EPS_02 (132U)
 *   WRN_NORM_EPS_03 (133U)
 *   WRN_NORM_EPS_04 (134U)
 *   WRN_NORM_EPS_05 (135U)
 *   WRN_NORM_EPS_06 (136U)
 *   WRN_NORM_EPS_07 (137U)
 *   WRN_NORM_EPS_09 (138U)
 *   WRN_NORM_EPS_10 (139U)
 *   WRN_NORM_EPS_11 (140U)
 *   WRN_NORM_FUECAP_02 (141U)
 *   WRN_NORM_CHEENG_02 (142U)
 *   WRN_NORM_CHEENG_03 (143U)
 *   WRN_NORM_CHEENG_04 (144U)
 *   WRN_NORM_CHEENG_07 (145U)
 *   WRN_NORM_ROLAWA_01 (146U)
 *   WRN_NORM_ROLAWA_02 (147U)
 *   WRN_NORM_ROLAWA_03 (148U)
 *   WRN_NORM_GPF_05 (149U)
 *   WRN_NORM_GPF_06 (150U)
 *   WRN_NORM_GPF_07 (151U)
 *   WRN_NORM_GPF_08 (152U)
 *   WRN_NORM_GPF_09 (153U)
 *   WRN_NORM_GPF_10 (154U)
 *   WRN_NORM_GPF_11 (155U)
 *   WRN_NORM_OILLEV_02 (156U)
 *   WRN_NORM_COOTEM_03 (157U)
 *   WRN_NORM_ONACCN_03 (158U)
 *   WRN_NORM_BATLOW_02 (159U)
 *   WRN_NORM_CHAMAL_02 (160U)
 *   WRN_NORM_CHAMAL_03 (161U)
 *   WRN_NORM_POWMAN_02 (162U)
 *   WRN_NORM_SOCLOW_02 (163U)
 *   WRN_NORM_SOCLOW_03 (164U)
 *   WRN_NORM_BATINS_02 (165U)
 *   WRN_NORM_BATINS_03 (166U)
 *   WRN_NORM_BATINS_04 (167U)
 *   WRN_NORM_BATINS_05 (168U)
 *   WRN_NORM_ONACCP_02 (169U)
 *   WRN_NORM_ALMN_02 (170U)
 *   WRN_NORM_HEAECU_02 (171U)
 *   WRN_NORM_BOS_02 (172U)
 *   WRN_NORM_BOS_03 (173U)
 *   WRN_NORM_EVMOD_02 (174U)
 *   WRN_NORM_EVMOD_03 (175U)
 *   WRN_NORM_EVMOD_04 (176U)
 *   WRN_NORM_EVMOD_05 (177U)
 *   WRN_NORM_EVMOD_06 (178U)
 *   WRN_NORM_EVMOD_07 (179U)
 *   WRN_NORM_EVMOD_08 (180U)
 *   WRN_NORM_EVMOD_09 (181U)
 *   WRN_NORM_EVMOD_10 (182U)
 *   WRN_NORM_DSC_02 (183U)
 *   WRN_NORM_DSC_03 (184U)
 *   WRN_NORM_DSC_04 (185U)
 *   WRN_NORM_ROLAWA1_01 (186U)
 *   WRN_NORM_ROLAWA1_02 (187U)
 *   WRN_NORM_ROLAWA1_03 (188U)
 *   WRN_NORM_ROLAWA1_04 (189U)
 *   WRN_NORM_ROLAWA1_05 (190U)
 *   WRN_NORM_ROLAWA1_06 (191U)
 *   WRN_NORM_ROLAWA1_07 (192U)
 *   WRN_NORM_ROLAWA1_08 (193U)
 *   WRN_NORM_ROLAWA1_09 (194U)
 *   WRN_NORM_ROLAWA1_10 (195U)
 *   WRN_NORM_ROLAWA1_11 (196U)
 *   WRN_NORM_MAICER_09 (197U)
 *   WRN_NORM_MAICER_10 (198U)
 *   WRN_NORM_MAICER_11 (199U)
 *   WRN_NORM_MAICER_12 (200U)
 *   WRN_NORM_PKSB_09 (201U)
 *   WRN_NORM_PKSB_10 (202U)
 *   WRN_NORM_PKSB_11 (203U)
 *   WRN_NORM_PKSB_13 (204U)
 *   WRN_NORM_PKSB_14 (205U)
 *   WRN_NORM_ISA_02 (206U)
 *   WRN_NORM_ISA_04 (207U)
 *   WRN_NORM_TCBM_01 (208U)
 *   WRN_NORM_TCBM_02 (209U)
 *   WRN_NORM_ADAFRO_02 (210U)
 *   WRN_NORM_PDA_03 (211U)
 *   WRN_NORM_RTAN_03 (212U)
 *   WRN_NORM_SEA_02 (213U)
 *   WRN_NORM_T120_01 (214U)
 *   WRN_POWER_EIGCON_02 (215U)
 *   WRN_POWER_EIGCON_04 (216U)
 *   WRN_PROSRV_PROSRV_02 (217U)
 *   WRN_PROSRV_PROSRV_03 (218U)
 *   WRN_PROSRV_PROSRV_04 (219U)
 *   WRN_PROSRV_PROSRV_05 (220U)
 *   WRN_PROSRV_PROSRV_08 (221U)
 *   WRN_PROSRV_PROSRV_09 (222U)
 *   WRN_PROSRV_PROSRV_10 (223U)
 *   WRN_PROSRV_PROSRV_11 (224U)
 *   WRN_PROSRV_PROSRV_12 (225U)
 *   WRN_PROSRV_PROSRV_13 (226U)
 *   WRN_PROSRV_PROSRV_22 (227U)
 *   WRN_PROSRV_PROSRV_23 (228U)
 *   WRN_NORM_BATCOO_02 (229U)
 *   WRN_NORM_BATCOO_03 (230U)
 *   WRN_NORM_LDA_02 (231U)
 *   WRN_NORM_LDA_03 (232U)
 *   WRN_NORM_LDA_06 (233U)
 *   WRN_NORM_LDA_07 (234U)
 *   WRN_NORM_LTA_02 (235U)
 *   WRN_NORM_LTA_03 (236U)
 *   WRN_NORM_LTA_07 (237U)
 *   WRN_NORM_LCA_02 (238U)
 *   WRN_NORM_LCA_03 (239U)
 *   WRN_NORM_LCA_04 (240U)
 *   WRN_NORM_LCA_05 (241U)
 *   WRN_NORM_LCA_15 (242U)
 *   WRN_NORM_LCA_16 (243U)
 *   WRN_NORM_LCA_17 (244U)
 *   WRN_NORM_LCA_20 (245U)
 *   WRN_NORM_RSA_01 (246U)
 *   WRN_NORM_RSA_04 (247U)
 *   WRN_NORM_RSA_05 (248U)
 *   WRN_NORM_CHADYN_01 (249U)
 *   WRN_NORM_CHADYN_02 (250U)
 *   WRN_NORM_TOWWAR_02 (251U)
 *   WRN_NORM_TOWWAR_03 (252U)
 *   WRN_NORM_TOWWAR_05 (253U)
 *   WRN_NORM_DMC_02 (254U)
 *   WRN_NORM_DMC_03 (255U)
 *   WRN_NORM_DMC_05 (256U)
 *   WRN_NORM_DMC_06 (257U)
 *   WRN_NORM_DMC_12 (258U)
 *   WRN_NORM_DMC_13 (259U)
 *   WRN_NORM_DMC_14 (260U)
 *   WRN_NORM_DMC_15 (261U)
 *   WRN_NORM_DMC_17 (262U)
 *   WRN_NORM_DMC_18 (263U)
 *   WRN_NORM_ICYRA_01 (264U)
 *   WRN_NORM_SEA_NCYC_02 (265U)
 *   WRN_NORM_DRIPOW_02 (266U)
 *   WRN_NORM_DRIPOW_03 (267U)
 *   WRN_NORM_DRIPOW_04 (268U)
 *   WRN_NORM_CCS_02 (269U)
 *   WRN_NORM_CCS_03 (270U)
 *   WRN_NORM_ACC_02 (271U)
 *   WRN_NORM_ACC_03 (272U)
 *   WRN_NORM_ACC_04 (273U)
 *   WRN_NORM_ACC_05 (274U)
 *   WRN_NORM_ACC_06 (275U)
 *   WRN_NORM_ACC_07 (276U)
 *   WRN_NORM_ACC_08 (277U)
 *   WRN_NORM_ACC_09 (278U)
 *   WRN_NORM_ACC_10 (279U)
 *   WRN_NORM_ACC_11 (280U)
 *   WRN_NORM_ACC_12 (281U)
 *   WRN_NORM_ACC_18 (282U)
 *   WRN_NORM_ACC_19 (283U)
 *   WRN_NORM_ACC_21 (284U)
 *   WRN_NORM_DESA_02 (285U)
 *   WRN_NORM_DESA_03 (286U)
 *   WRN_NORM_DESA_04 (287U)
 *   WRN_NORM_DESA_05 (288U)
 *   WRN_NORM_DESA_06 (289U)
 *   WRN_NORM_DESA_07 (290U)
 *   WRN_NORM_DESA_08 (291U)
 *   WRN_NORM_PEXI_02 (292U)
 *   WRN_NORM_RESADJ_09 (293U)
 *   WRN_NORM_RESADJ_10 (294U)
 *   WRN_NORM_RESADJ_11 (295U)
 *   WRN_NORM_RESADJ_12 (296U)
 *   WRN_NORM_RESADJ_13 (297U)
 *   WRN_NORM_RESADJ_14 (298U)
 *   WRN_NORM_RESADJ_15 (299U)
 *   WRN_NORM_TSMODE_02 (300U)
 *   WRN_NORM_UNIOVE_02 (301U)
 *   WRN_NORM_UNIOVE_04 (302U)
 *   WARN_ADAS_SDG_01 (303U)
 *   WRN_ADAS_PDA_01 (304U)
 *   WRN_ADAS_PDA_02 (305U)
 *   WRN_NORM_TDOOR_01 (306U)
 *   WRN_NORM_TDOOR_02 (307U)
 *   WRN_NORM_TDOOR_03 (308U)
 *   WRN_NORM_ACCHOL_02 (309U)
 *   WRN_NORM_ACCHOL_03 (310U)
 *   WRN_NORM_ACCHOL_05 (311U)
 *   WRN_NORM_MAICER_09_RESADJ_09 (312U)
 *   WRN_NORM_MAICER_09_RESADJ_10 (313U)
 *   WRN_NORM_MAICER_09_RESADJ_11 (314U)
 *   WRN_NORM_MAICER_09_RESADJ_12 (315U)
 *   WRN_NORM_MAICER_09_RESADJ_13 (316U)
 *   WRN_NORM_MAICER_09_RESADJ_14 (317U)
 *   WRN_NORM_MAICER_09_RESADJ_15 (318U)
 *   WRN_NORM_MAICER_11_RESADJ_09 (319U)
 *   WRN_NORM_MAICER_11_RESADJ_10 (320U)
 *   WRN_NORM_MAICER_11_RESADJ_11 (321U)
 *   WRN_NORM_MAICER_11_RESADJ_12 (322U)
 *   WRN_NORM_MAICER_11_RESADJ_13 (323U)
 *   WRN_NORM_MAICER_11_RESADJ_14 (324U)
 *   WRN_NORM_MAICER_11_RESADJ_15 (325U)
 *   WRN_NORM_CVRS_04 (326U)
 *   WRN_NORM_CVRS_05 (327U)
 *   WRN_NORM_SMASTA_42 (328U)
 *   WRN_NORM_SMASTA_43 (329U)
 *   WRN_NORM_SMASTA_44 (330U)
 *   WRN_NORM_SMASTA_45 (331U)
 *   WRN_NORM_SMASTA_46 (332U)
 *   WRN_NORM_SMASTA_47 (333U)
 *   WRN_NORM_SMASTA_48 (334U)
 *   WRN_MFLID_MFLID_01 (335U)
 *   WRN_NORM_MFLID_02 (336U)
 *   WRN_NORM_MFLID_03 (337U)
 *   WRN_NORM_TMNT_15 (338U)
 *   WRN_NORM_TMNT_16 (339U)
 *   WRN_ADAS_LCA1 (340U)
 *   WRN_ADAS_LCA2 (341U)
 *   WRN_DOOR_UNLMOD_02 (342U)
 *   WARN_ADAS_PDA1 (343U)
 *   WRN_ADAS_URSM_01 (344U)
 *   WRN_ADAS_URSM_02 (345U)
 *   WRN_ADAS_URSM_03 (346U)
 *   WRN_ADAS_URSM_04 (347U)
 *   WRN_ADAS_URSM_05 (348U)
 *   WRN_ADAS_URSM_06 (349U)
 *   WRN_ADAS_URSM_07 (350U)
 *   WRN_NORM_SYSMAL_HVIND1 (351U)
 *   WRN_NORM_SYSMAL_HVIND2 (352U)
 *   WRN_NORM_SYSMAL_HVIND3 (353U)
 *   WRN_NORM_SYSMAL_HVIND4 (354U)
 *   WRN_NORM_SYSMAL_HVIND5 (355U)
 *   WRN_NORM_SYSMAL_HVIND6 (356U)
 *   WRN_NORM_SYSMAL_HVIND7 (357U)
 *   WRN_NORM_SYSMAL_HVIND8 (358U)
 *   WRN_NORM_SYSMAL_HVIND9 (359U)
 *   WRN_NORM_SYSMAL_HVIND10 (360U)
 *   WRN_NORM_SYSMAL_HVIND11 (361U)
 *   WRN_NORM_SYSMAL_HVIND12 (362U)
 *   WRN_NORM_SYSMAL_HVIND13 (363U)
 *   WRN_NORM_SYSMAL_HVIND14 (364U)
 *   WRN_NORM_SYSMAL_HVIND15 (365U)
 *   WRN_NORM_SYSMAL_HVIND16 (366U)
 *   WRN_NORM_SYSMAL_HVIND17 (367U)
 *   WRN_NORM_FHL_04 (368U)
 *   WRN_NORM_SMASTA_52 (369U)
 *   WRN_NORM_SMASTA_53 (370U)
 *   WRN_NORM_GPF_MEV01_02 (371U)
 *   WRN_NORM_GPF_MEV01_03 (372U)
 *   WRN_NORM_GPF_MEV01_04 (373U)
 *   WRN_NORM_GPF_MEV01_05 (374U)
 *   WRN_NORM_GPF_MEV01_06 (375U)
 *   WRN_NORM_GPF_MEV01_07 (376U)
 *   WRN_NORM_GPF_MEV01_08 (377U)
 *   WRN_NORM_VCOPE_02 (378U)
 *   WRN_NORM_VCOPE_03 (379U)
 *   WRN_ADAS_LCA_01 (380U)
 *   WRN_ADAS_LCA_03 (381U)
 *   WRN_ADAS_LCA_04 (382U)
 *   WRN_NORM_FCMDI_01 (383U)
 *   WRN_NORM_FCMDI_02 (384U)
 *   WRN_NORM_FCMDI_03 (385U)
 *   WRN_NORM_FCMDI_04 (386U)
 *   WRN_NORM_FCMDI_05 (387U)
 *   WRN_NORM_FCMDI_06 (388U)
 *   WRN_NORM_FCMDI_07 (389U)
 *   WRN_NORM_TSMODE_VM01_02 (390U)
 *   WRN_ADAS_ACC_01 (391U)
 *   WRN_ADAS_ACC_02 (392U)
 *   WRN_ADAS_ACC_03 (393U)
 *   WRN_ADAS_ACC_04 (394U)
 *   WRN_ADAS_ACC_05 (395U)
 *   WRN_ADAS_ACC_22 (396U)
 *   WRN_ADAS_ACC_23 (397U)
 *   WRN_ADAS_ACC_24 (398U)
 *   WRN_ADAS_ACC_25 (399U)
 *   WRN_ADAS_ACC_26 (400U)
 *   WRN_ADAS_ACC_27 (401U)
 *   WRN_ADAS_ACC_28 (402U)
 *   WRN_ADAS_ACC_29 (403U)
 *   WRN_ADAS_ACC_30 (404U)
 *   WRN_ADAS_ACC_31 (405U)
 *   WRN_ADAS_ACC_32 (406U)
 *   WRN_ADAS_ACC_33 (407U)
 *   WRN_ADAS_ACC_34 (408U)
 *   WRN_ADAS_ACC_35 (409U)
 *   WRN_ADAS_ACC_36 (410U)
 *   WRN_ADAS_ACC_37 (411U)
 *   WRN_ADAS_ACC_38 (412U)
 *   WRN_ADAS_ACC_39 (413U)
 *   WRN_ADAS_ACC_40 (414U)
 *   WRN_ADAS_ACC_41 (415U)
 *   WRN_ADAS_ACC_42 (416U)
 *   WRN_ADAS_ACC_43 (417U)
 *   WRN_ADAS_ACC_44 (418U)
 *   WRN_ADAS_ACC_45 (419U)
 *   WRN_ADAS_ACC_46 (420U)
 *   WRN_ADAS_ACC_47 (421U)
 *   WRN_ADAS_ACC_48 (422U)
 *   WRN_ADAS_ACC_49 (423U)
 *   WRN_ADAS_ACC_50 (424U)
 *   WRN_ADAS_ACC_51 (425U)
 *   WRN_ADAS_ACC_52 (426U)
 *   WRN_ADAS_ACC_53 (427U)
 *   WRN_ADAS_ACC_54 (428U)
 *   WRN_ADAS_ACC_55 (429U)
 *   WRN_ADAS_ACC_56 (430U)
 *   WRN_ADAS_ACC_57 (431U)
 *   WRN_NORM_ACC_VM01_GSY07_02 (432U)
 *   WRN_NORM_ACC_VM01_GSY07_03 (433U)
 *   WRN_NORM_ACC_VM01_GSY07_04 (434U)
 *   WRN_NORM_ACC_VM01_GSY07_05 (435U)
 *   WRN_NORM_ACC_VM01_GSY07_06 (436U)
 *   WRN_NORM_ACC_VM01_GSY07_07 (437U)
 *   WRN_NORM_ACC_VM01_GSY07_08 (438U)
 *   WRN_NORM_ACC_VM01_GSY07_09 (439U)
 *   WRN_NORM_ACC_VM01_EFE02_02 (440U)
 *   WRN_NORM_ACC_VM01_EFE02_03 (441U)
 *   WRN_NORM_ACC_VM01_EFE02_04 (442U)
 *   WRN_NORM_ACC_VM01_EFE02_05 (443U)
 *   WRN_NORM_ACC_VM01_EFE01_02 (444U)
 *   WRN_NORM_ACC_VM01_EFE01_03 (445U)
 *   WRN_NORM_ACC_VM01_EFE01_04 (446U)
 *   WRN_NORM_ACC_VM01_EFE01_05 (447U)
 *   WRN_NORM_ACC_VM01_GME12_02 (448U)
 *   WRN_NORM_ACC_VM01_GME12_03 (449U)
 *   WRN_NORM_ACC_VM01_GME12_04 (450U)
 *   WRN_NORM_ACC_VM01_GME12_05 (451U)
 *   WRN_NORM_ACC_VM01_GME12_06 (452U)
 *   WRN_NORM_ACC_VM01_GME12_07 (453U)
 *   WRN_NORM_ACC_VM01_GME12_08 (454U)
 *   WRN_NORM_ACC_VM01_GME12_09 (455U)
 *   WRN_NORM_FCTA_01 (456U)
 *   WARN_NORM_GRISHU_02 (457U)
 *   WRN_NORM_CHEENG_06 (458U)
 *   WRN_NORM_SFTPOSL_02 (459U)
 *   WRN_NORM_SFTPOSL_03 (460U)
 *   WRN_NORM_SFTPOSL_04 (461U)
 *   WRN_NORM_TPMS_02 (462U)
 *   WRN_NORM_TPMS_03 (463U)
 *   WRN_NORM_STOSTA_02 (464U)
 *   WRN_NORM_RSRDI_02 (465U)
 *   WRN_NORM_PSSDI_02 (466U)
 *   WRN_NORM_UNOVE_02 (467U)
 *   WRN_NORM_UNOVE_04 (468U)
 *   WRN_CUSTMIZE_PERSET_02 (469U)
 *   WRN_CUSTMIZE_PERSET_03 (470U)
 *   WRN_CUSTMIZE_PERSET_04 (471U)
 *   WRN_CUSTMIZE_PERSET_06 (472U)
 *   WRN_CUSTMIZE_PERSET_07 (473U)
 *   WRN_CUSTMIZE_PERSET_08 (474U)
 *   WRN_CUSTMIZE_PERSET_09 (475U)
 *   WRN_CUSTMIZE_PERSET_10 (476U)
 *   WRN_CUSTMIZE_PERSET_11 (477U)
 *   WRN_CUSTMIZE_PERSET_12 (478U)
 *   WRN_CUSTMIZE_PERSET_13 (479U)
 *   WRN_CUSTMIZE_PERSET_14 (480U)
 *   WRN_CUSTMIZE_PERSET_15 (481U)
 *   WRN_CUSTMIZE_PERSET_16 (482U)
 *   WRN_CUSTMIZE_PERSET_17 (483U)
 *   WRN_CUSTMIZE_PERSET_18 (484U)
 *   WRN_CUSTMIZE_PERSET_19 (485U)
 *   WRN_CUSTMIZE_PERSET_20 (486U)
 *   WRN_CUSTMIZE_PERSET_21 (487U)
 *   WRN_CUSTMIZE_PERSET_22 (488U)
 *   WRN_CUSTMIZE_PERSET_23 (489U)
 *   WRN_CUSTMIZE_PERSET_24 (490U)
 *   WRN_NORM_SEA_VM01_02 (491U)
 *   WRN_NORM_SEA_VM02_02 (492U)
 *   WRN_NORM_PSSDI_03 (493U)
 *   WRN_NORM_PSSDI_04 (494U)
 *   WRN_NORM_PSSDI_05 (495U)
 *   WRN_NORM_PSSDI_06 (496U)
 *   WRN_NORM_CLESON_02 (497U)
 *   WRN_CUTMIZE_DIGKEY_01 (498U)
 *   WRN_NORM_RSRDI_03 (499U)
 *   WRN_ADAS_LCA_02 (500U)
 *   WRN_NORM_TPMS_VM02_REQ02 (501U)
 *   WRN_NORM_TPMS_VM02_REQ03 (502U)
 *   WRN_NORM_TPMS_VM02_REQ04 (503U)
 *   WRN_NORM_TPMS_VM02_REQ05 (504U)
 *   WRN_NORM_TPMS_VM02_REQ06 (505U)
 *   WRN_NORM_TPMS_VM02_REQ07 (506U)
 *   WRN_NORM_TPMS_VM02_REQ08 (507U)
 *   WRN_NORM_TPMS_VM02_REQ09 (508U)
 *   WRN_NORM_TPMS_VM02_REQ10 (509U)
 *   WRN_NORM_TPMS_VM02_REQ11 (510U)
 *   WRN_NORM_TPMS_VM02_GWM08_REQ02 (511U)
 *   WRN_NORM_TPMS_VM02_GWM08_REQ01 (512U)
 *   WRN_NORM_PSSDI_07 (513U)
 *   WRN_NORM_EXWUOC_04 (514U)
 *   WRN_NORM_EXWUOC_06 (515U)
 *   WRN_NORM_EXWUOC_10 (516U)
 *   WRN_NORM_EXWUOC_16 (517U)
 *   WRN_NORM_EXWUOC_17 (518U)
 *   WRN_NORM_EXWUOC_18 (519U)
 *   WRN_NORM_PBD_02 (520U)
 *   WRN_NORM_FCTA_02 (521U)
 *   WRN_NORM_TMN_02 (522U)
 *   WRN_NORM_TMN_03 (523U)
 *   WRN_NORM_PEDPRO_03 (524U)
 *   WRN_NORM_PEDPRO_04 (525U)
 *   WRN_NORM_LEAUNF_02 (526U)
 *   WRN_NORM_LEAUNF_04 (527U)
 *   WRN_NORM_HCS_02 (528U)
 *   WRN_NORM_HCS_03 (529U)
 *   WRN_NORM_HCS_04 (530U)
 *   WRN_NORM_HCS_05 (531U)
 *   WRN_NORM_HCS_06 (532U)
 *   WRN_NORM_HCS_07 (533U)
 *   WRN_NORM_HCS_08 (534U)
 *   WRN_NORM_HCS_09 (535U)
 *   WRN_NORM_HCS_10 (536U)
 *   WRN_NORM_HCS_11 (537U)
 *   WRN_NORM_SCB_02 (538U)
 *   WRN_NORM_ITS_02 (539U)
 *   WRN_NORM_ITS_06 (540U)
 *   WRN_NORM_ITS_MEV01_02 (541U)
 *   WRN_NORM_ITS_MEV01_04 (542U)
 *   WRN_NORM_ITS_MEV01_05 (543U)
 *   WRN_NORM_ITS_MEV01_06 (544U)
 *   WRN_NORM_MAPACC_02 (545U)
 *   WRN_NORM_OAA_03 (546U)
 *   WRN_NORM_OAA_04 (547U)
 *   WRN_NORM_LCA_21 (548U)
 *   WRN_NORM_LCA_26 (549U)
 *   WRN_NORM_LCA_27 (550U)
 *   WRN_NORM_LCA_28 (551U)
 *   WRN_NORM_LCA_29 (552U)
 *   WRN_NORM_LCA_30 (553U)
 *   WRN_NORM_LCA_31 (554U)
 *   WRN_NORM_NLOCK_02 (555U)
 *   WRN_NORM_ATFWRN_02 (556U)
 *   WRN_NORM_LTA_04 (557U)
 *   WRN_NORM_LTA_05 (558U)
 *   WRN_NORM_LTA_06 (559U)
 *   WRN_NORM_LTA_08 (560U)
 *   WRN_NORM_LTA_09 (561U)
 *   WRN_NORM_LTA_10 (562U)
 *   WRN_NORM_LTA_11 (563U)
 *   WRN_NORM_LTA_12 (564U)
 *   WRN_NORM_PCL_02 (565U)
 *   WRN_ADAS_LCA_05 (566U)
 *   WRN_ADAS_LCA_06 (567U)
 *   WRN_ADAS_LCA_07 (568U)
 *   WRN_ADAS_LCA_08 (569U)
 *   WRN_ADAS_LCA_09 (570U)
 *   WRN_ADAS_LCA_10 (571U)
 *   WRN_ADAS_LCA_11 (572U)
 *   WRN_ADAS_LCA_12 (573U)
 *   WRN_NORM_LDA_04 (574U)
 *   WRN_NORM_LDA_05 (575U)
 *   WRN_ADAS_OAA_01 (576U)
 *   WRN_NORM_TPMS_VM02_GWM08_REQ06 (577U)
 *   WRN_NORM_TPMS_VM02_GWM08_REQ07 (578U)
 *   WRN_ADAS_ACC_G7 (579U)
 *   WRN_ADAS_ACC_G11_01 (580U)
 *   WRN_ADAS_ACC_G11_02 (581U)
 *   WRN_ADAS_ACC_G11_03 (582U)
 *   WRN_ADAS_ACC_G20 (583U)
 *   WRN_ADAS_ACC_G22 (584U)
 *   WRN_ADAS_ACC_G23 (585U)
 *   HUD_WRN_NORM_PCS1_05 (586U)
 *   HUD_WRN_NORM_PCS1_06 (587U)
 *   HUD_WRN_ADAS_ACC_G20 (588U)
 *   HUD_WRN_ADAS_ACC_G7 (589U)
 *   HUD_WRN_ADAS_ACC_G23 (590U)
 *   HUD_WRN_ADAS_ACC_G22 (591U)
 *   HUD_WRN_ADAS_LCA_02 (592U)
 *   HUD_WRN_NORM_DA_02 (593U)
 *   HUD_WRN_NORM_SCB_02 (594U)
 *   HUD_WRN_NORM_ITS_MEV01_04 (595U)
 *   HUD_WRN_NORM_ITS_MEV01_02 (596U)
 *   HUD_WRN_NORM_ITS_02 (597U)
 *   HUD_WRN_NORM_BOS_02 (598U)
 *   HUD_WRN_NORM_DSC_02 (599U)
 *   HUD_WRN_NORM_PMAR_03 (600U)
 *   HUD_WRN_ADAS_OAA_01 (601U)
 *   HUD_WRN_NORM_ACC_19 (602U)
 *   HUD_WRN_NORM_LCA_29 (603U)
 *   HUD_WRN_ADAS_LCA_05 (604U)
 *   HUD_WRN_ADAS_LCA_06 (605U)
 *   HUD_WRN_ADAS_LCA_07 (606U)
 *   HUD_WRN_ADAS_LCA_08 (607U)
 *   HUD_WRN_ADAS_LCA_09 (608U)
 *   HUD_WRN_ADAS_LCA_10 (609U)
 *   HUD_WRN_ADAS_LCA_11 (610U)
 *   HUD_WRN_ADAS_LCA_12 (611U)
 *   HUD_WRN_NORM_RTAN_02 (612U)
 *   HUD_WRN_NORM_LDA_02 (613U)
 *   HUD_WRN_ADAS_LCA_03 (614U)
 *   HUD_WRN_ADAS_LCA_04 (615U)
 *   HUD_WRN_NORM_ACC_21 (616U)
 *   HUD_WRN_ADAS_ACC_G11_01 (617U)
 *   HUD_WRN_ADAS_ACC_G11_02 (618U)
 *   HUD_WRN_ADAS_ACC_G11_03 (619U)
 *   HUD_WRN_NORM_DSC_04 (620U)
 *   WRN_NORM_GROUP1 (621U)
 *   WRN_NORM_GROUP2 (622U)
 *   WRN_NORM_GROUP3 (623U)
 *   WRN_NORM_GROUP4 (624U)
 *   WRN_NORM_GROUP5 (625U)
 *   WRN_NORM_GROUP6 (626U)
 *   WRN_NORM_GROUP7 (627U)
 *   WRN_NORM_GROUP8 (628U)
 *   WRN_NORM_GROUP9 (629U)
 *   TotalNumOfWarnings (630U)
 * WarningStatus: Enumeration of integer in interval [0...2] with enumerators
 *   UI_WARNING_STATUS_OFF (0U)
 *   UI_WARNING_STATUS_ON (1U)
 *   UI_WARNING_STATUS_UNKNOWN (2U)
 * tTxSigConfirmStatus: Enumeration of integer in interval [0...2] with enumerators
 *   eTxSigConfirmStatus_Cleared (0U)
 *   eTxSigConfirmStatus_Set (1U)
 *   eTxSigConfirmStatus_NotSupported (2U)
 * tTxSignalId: Enumeration of integer in interval [0...49] with enumerators
 *   eSecureTxByte0Out (0U)
 *   eSecureTxByte1Out (1U)
 *   eSecureTxByte2Out (2U)
 *   eSecureTxByte3Out (3U)
 *   eMAC_TxOut (4U)
 *   eFV_TxOut (5U)
 *   eOdometerOut (6U)
 *   eVehicleSpeedICOut (7U)
 *   eIllumination_PWMOut (8U)
 *   eDebug1_Byte0Out (9U)
 *   eDebug1_Byte1Out (10U)
 *   eDebug1_Byte2Out (11U)
 *   eDebug1_Byte3Out (12U)
 *   eDebug1_Byte4Out (13U)
 *   eDebug1_Byte5Out (14U)
 *   eDebug1_Byte6Out (15U)
 *   eDebug1_Byte7Out (16U)
 *   eDebug2_Byte0Out (17U)
 *   eDebug2_Byte1Out (18U)
 *   eDebug2_Byte2Out (19U)
 *   eDebug2_Byte3Out (20U)
 *   eDebug2_Byte4Out (21U)
 *   eDebug2_Byte5Out (22U)
 *   eDebug2_Byte6Out (23U)
 *   eDebug2_Byte7Out (24U)
 *   eDebug3_Byte0Out (25U)
 *   eDebug3_Byte1Out (26U)
 *   eDebug3_Byte2Out (27U)
 *   eDebug3_Byte3Out (28U)
 *   eDebug3_Byte4Out (29U)
 *   eDebug3_Byte5Out (30U)
 *   eDebug3_Byte6Out (31U)
 *   eDebug3_Byte7Out (32U)
 *   eDebug4_Byte0Out (33U)
 *   eDebug4_Byte1Out (34U)
 *   eDebug4_Byte2Out (35U)
 *   eDebug4_Byte3Out (36U)
 *   eDebug4_Byte4Out (37U)
 *   eDebug4_Byte5Out (38U)
 *   eDebug4_Byte6Out (39U)
 *   eDebug4_Byte7Out (40U)
 *   eDebug5_Byte0Out (41U)
 *   eDebug5_Byte1Out (42U)
 *   eDebug5_Byte2Out (43U)
 *   eDebug5_Byte3Out (44U)
 *   eDebug5_Byte4Out (45U)
 *   eDebug5_Byte5Out (46U)
 *   eDebug5_Byte6Out (47U)
 *   eDebug5_Byte7Out (48U)
 *   eEndOfTxSignal (49U)
 *
 * Array Types:
 * ============
 * PayloadArr_u8_8: Array with 8 element(s) of type Rte_DT_PayloadArr_u8_8_0
 * Tpms_Arr_u8_5: Array with 5 element(s) of type Rte_DT_Tpms_Arr_u8_5_0
 * data_u32_5: Array with 5 element(s) of type Rte_DT_data_u32_5_0
 * data_u8_10: Array with 10 element(s) of type Rte_DT_data_u8_10_0
 * data_u8_8: Array with 8 element(s) of type Rte_DT_data_u8_8_0
 *
 * Record Types:
 * =============
 * ExtWarningData: Record with elements
 *   ExtWarningCurrentStatus of type WarningStatus
 *   ExtWarningCurrentEvent of type WarningEvent
 *   ExtWarningCurrentPayload of type PayloadArr_u8_8
 * SHudWarningDisplay: Record with elements
 *   show of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_8
 * SHudWarningStatus: Record with elements
 *   visible of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_10
 * STpmsWarningData: Record with elements
 *   tpmsWarndata of type data_u32_5
 * SWarningDisplay: Record with elements
 *   show of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_8
 * SWarningStatus: Record with elements
 *   visible of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_10
 * WarningDataS: Record with elements
 *   WarningCurrentStatus of type WarningStatus
 *   WarningCurrentEvent of type WarningEvent
 *   WarningCurrentPayload of type UInt32
 *
 *********************************************************************************************************************/


#define CWarnMsg_Core_Observer_START_SEC_CODE
#include "CWarnMsg_Core_Observer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CWarnMsg_Core_Observer_GroupWrnAck
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GroupWrnAck> of PortPrototype <ppGroupWarningUpdate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CWarnMsg_Core_Observer_GroupWrnAck(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_GroupWrnAck_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_GroupWrnAck(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_GroupWrnAck
 *********************************************************************************************************************/

  CWarnMsg_Core_Observer_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CWarnMsg_Core_Observer_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 32ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
 *   Std_ReturnType Rte_Read_rpCS_GetChimeStatus_Chime_Status(EChimeStatus *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_FactoryMode_FactoryMode(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_FactoryModeSts_FactoryModeStatus(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(SHudWarningStatus *data)
 *   Std_ReturnType Rte_Read_rp_IllumStartSts_StarterStatus_Out(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TPMSPayload_Tpms_Payload(Rte_DT_Tpms_Arr_u8_5_0 *data)
 *     Argument data: Rte_DT_Tpms_Arr_u8_5_0* is of type Tpms_Arr_u8_5
 *   Std_ReturnType Rte_Read_rp_TargetSWStatus_TargetSw(Target_SW_Status *data)
 *   Std_ReturnType Rte_Read_rp_WarningStatus_WarningStatusData(SWarningStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(const SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(const STpmsWarningData *data)
 *   Std_ReturnType Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarnInt_WarningInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarningDisplay_WarningDisplayData(const SWarningDisplay *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WarningId CurrentWarning, ExtWarningData *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(WarningId CurrentWarning, WarningDataS *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(WarningId CurWarningId, const Rte_DT_PayloadArr_u8_8_0 *CurWarningDispPayload)
 *     Argument CurWarningDispPayload: Rte_DT_PayloadArr_u8_8_0* is of type PayloadArr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(WarningId Warning, UInt16 ButtonEvent, UInt8 CursorSt)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  EChimeID Read_rpCS_ChimeRequest_Chime_Request;
  EChimeStatus Read_rpCS_GetChimeStatus_Chime_Status;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  UInt8 Read_rp_FactoryMode_FactoryMode;
  UInt8 Read_rp_FactoryModeSts_FactoryModeStatus;
  HMIReadySts_Type Read_rp_HMIReadySts_HMI_ReadyStatus;
  HMI_Screen_Mode Read_rp_HMIScreenMode_HMIScreenMode_Status;
  Hud_Wake_Type Read_rp_HUDWakeupHwSts_WakeType_Hw;
  Hud_Wake_Type Read_rp_HUDWakeupSwSts_WakeType_Int;
  SHudWarningStatus Read_rp_HUDWarningStatus_HudWarningStatusData;
  UInt8 Read_rp_IllumStartSts_StarterStatus_Out;
  UInt8 Read_rp_NVM_HUD_CoordinateFlag_NvmData;
  Tpms_Arr_u8_5 Read_rp_TPMSPayload_Tpms_Payload;
  Target_SW_Status Read_rp_TargetSWStatus_TargetSw;
  SWarningStatus Read_rp_WarningStatus_WarningStatusData;

  SHudWarningDisplay Write_pp_HUDWarningDisplay_HudWarningDisplayData;
  STpmsWarningData Write_pp_TPMSWarnPayload_TpmsWarningDataData;
  SWarningDisplay Write_pp_WarningDisplay_WarningDisplayData;

  ExtWarningData Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  WarningDataS Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus = {
  0U, 0U, 0U
};
  tTxSigConfirmStatus Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  PayloadArr_u8_8 Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_ChimeRequest_Chime_Request(&Read_rpCS_ChimeRequest_Chime_Request);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_GetChimeStatus_Chime_Status(&Read_rpCS_GetChimeStatus_Chime_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryMode_FactoryMode(&Read_rp_FactoryMode_FactoryMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryModeSts_FactoryModeStatus(&Read_rp_FactoryModeSts_FactoryModeStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&Read_rp_HMIReadySts_HMI_ReadyStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&Read_rp_HMIScreenMode_HMIScreenMode_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(&Read_rp_HUDWakeupHwSts_WakeType_Hw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(&Read_rp_HUDWakeupSwSts_WakeType_Int);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(&Read_rp_HUDWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_IllumStartSts_StarterStatus_Out(&Read_rp_IllumStartSts_StarterStatus_Out);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(&Read_rp_NVM_HUD_CoordinateFlag_NvmData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TPMSPayload_Tpms_Payload(Read_rp_TPMSPayload_Tpms_Payload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TargetSWStatus_TargetSw(&Read_rp_TargetSWStatus_TargetSw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_WarningStatus_WarningStatusData(&Read_rp_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pp_HUDWarningDisplay_HudWarningDisplayData, 0, sizeof(Write_pp_HUDWarningDisplay_HudWarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(&Write_pp_HUDWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_TPMSWarnPayload_TpmsWarningDataData, 0, sizeof(Write_pp_TPMSWarnPayload_TpmsWarningDataData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(&Write_pp_TPMSWarnPayload_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(Rte_InitValue_pp_WarnHighInt_WarningHighInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnInt_WarningInterrupt_State(Rte_InitValue_pp_WarnInt_WarningInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_WarningDisplay_WarningDisplayData, 0, sizeof(Write_pp_WarningDisplay_WarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarningDisplay_WarningDisplayData(&Write_pp_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(0U, &Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(0U, &Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(0U, &Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(0U, Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CWarnMsg_Core_Observer_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CWarnMsg_Core_Observer_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Init> of PortPrototype <pp_Init>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CWarnMsg_Core_Observer_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CWarnMsg_Core_Observer_SW_NoOperationTimer
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SW_NoOperationTimer> of PortPrototype <ppSW_NoOperationTimer>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
 *   Std_ReturnType Rte_Read_rpCS_GetChimeStatus_Chime_Status(EChimeStatus *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_FactoryMode_FactoryMode(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_FactoryModeSts_FactoryModeStatus(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(SHudWarningStatus *data)
 *   Std_ReturnType Rte_Read_rp_IllumStartSts_StarterStatus_Out(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TPMSPayload_Tpms_Payload(Rte_DT_Tpms_Arr_u8_5_0 *data)
 *     Argument data: Rte_DT_Tpms_Arr_u8_5_0* is of type Tpms_Arr_u8_5
 *   Std_ReturnType Rte_Read_rp_TargetSWStatus_TargetSw(Target_SW_Status *data)
 *   Std_ReturnType Rte_Read_rp_WarningStatus_WarningStatusData(SWarningStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(const SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(const STpmsWarningData *data)
 *   Std_ReturnType Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarnInt_WarningInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarningDisplay_WarningDisplayData(const SWarningDisplay *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WarningId CurrentWarning, ExtWarningData *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(WarningId CurrentWarning, WarningDataS *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(WarningId CurWarningId, const Rte_DT_PayloadArr_u8_8_0 *CurWarningDispPayload)
 *     Argument CurWarningDispPayload: Rte_DT_PayloadArr_u8_8_0* is of type PayloadArr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(WarningId Warning, UInt16 ButtonEvent, UInt8 CursorSt)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CWarnMsg_Core_Observer_SW_NoOperationTimer(EButtonId pEvent, EButtonSts pEventType)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_SW_NoOperationTimer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_SW_NoOperationTimer(EButtonId pEvent, EButtonSts pEventType) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CWarnMsg_Core_Observer_SW_NoOperationTimer
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  EChimeID Read_rpCS_ChimeRequest_Chime_Request;
  EChimeStatus Read_rpCS_GetChimeStatus_Chime_Status;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  UInt8 Read_rp_FactoryMode_FactoryMode;
  UInt8 Read_rp_FactoryModeSts_FactoryModeStatus;
  HMIReadySts_Type Read_rp_HMIReadySts_HMI_ReadyStatus;
  HMI_Screen_Mode Read_rp_HMIScreenMode_HMIScreenMode_Status;
  Hud_Wake_Type Read_rp_HUDWakeupHwSts_WakeType_Hw;
  Hud_Wake_Type Read_rp_HUDWakeupSwSts_WakeType_Int;
  SHudWarningStatus Read_rp_HUDWarningStatus_HudWarningStatusData;
  UInt8 Read_rp_IllumStartSts_StarterStatus_Out;
  UInt8 Read_rp_NVM_HUD_CoordinateFlag_NvmData;
  Tpms_Arr_u8_5 Read_rp_TPMSPayload_Tpms_Payload;
  Target_SW_Status Read_rp_TargetSWStatus_TargetSw;
  SWarningStatus Read_rp_WarningStatus_WarningStatusData;

  SHudWarningDisplay Write_pp_HUDWarningDisplay_HudWarningDisplayData;
  STpmsWarningData Write_pp_TPMSWarnPayload_TpmsWarningDataData;
  SWarningDisplay Write_pp_WarningDisplay_WarningDisplayData;

  ExtWarningData Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  WarningDataS Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus = {
  0U, 0U, 0U
};
  tTxSigConfirmStatus Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  PayloadArr_u8_8 Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_ChimeRequest_Chime_Request(&Read_rpCS_ChimeRequest_Chime_Request);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_GetChimeStatus_Chime_Status(&Read_rpCS_GetChimeStatus_Chime_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryMode_FactoryMode(&Read_rp_FactoryMode_FactoryMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryModeSts_FactoryModeStatus(&Read_rp_FactoryModeSts_FactoryModeStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&Read_rp_HMIReadySts_HMI_ReadyStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&Read_rp_HMIScreenMode_HMIScreenMode_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(&Read_rp_HUDWakeupHwSts_WakeType_Hw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(&Read_rp_HUDWakeupSwSts_WakeType_Int);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(&Read_rp_HUDWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_IllumStartSts_StarterStatus_Out(&Read_rp_IllumStartSts_StarterStatus_Out);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(&Read_rp_NVM_HUD_CoordinateFlag_NvmData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TPMSPayload_Tpms_Payload(Read_rp_TPMSPayload_Tpms_Payload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TargetSWStatus_TargetSw(&Read_rp_TargetSWStatus_TargetSw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_WarningStatus_WarningStatusData(&Read_rp_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pp_HUDWarningDisplay_HudWarningDisplayData, 0, sizeof(Write_pp_HUDWarningDisplay_HudWarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(&Write_pp_HUDWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_TPMSWarnPayload_TpmsWarningDataData, 0, sizeof(Write_pp_TPMSWarnPayload_TpmsWarningDataData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(&Write_pp_TPMSWarnPayload_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(Rte_InitValue_pp_WarnHighInt_WarningHighInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnInt_WarningInterrupt_State(Rte_InitValue_pp_WarnInt_WarningInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_WarningDisplay_WarningDisplayData, 0, sizeof(Write_pp_WarningDisplay_WarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarningDisplay_WarningDisplayData(&Write_pp_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(0U, &Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(0U, &Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(0U, &Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(0U, Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_UCL_HudWarnStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HudWarningStatusData> of PortPrototype <rp_HUDWarningStatus>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
 *   Std_ReturnType Rte_Read_rpCS_GetChimeStatus_Chime_Status(EChimeStatus *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_FactoryMode_FactoryMode(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_FactoryModeSts_FactoryModeStatus(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(SHudWarningStatus *data)
 *   Std_ReturnType Rte_Read_rp_IllumStartSts_StarterStatus_Out(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TPMSPayload_Tpms_Payload(Rte_DT_Tpms_Arr_u8_5_0 *data)
 *     Argument data: Rte_DT_Tpms_Arr_u8_5_0* is of type Tpms_Arr_u8_5
 *   Std_ReturnType Rte_Read_rp_TargetSWStatus_TargetSw(Target_SW_Status *data)
 *   Std_ReturnType Rte_Read_rp_WarningStatus_WarningStatusData(SWarningStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(const SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(const STpmsWarningData *data)
 *   Std_ReturnType Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarnInt_WarningInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarningDisplay_WarningDisplayData(const SWarningDisplay *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WarningId CurrentWarning, ExtWarningData *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(WarningId CurrentWarning, WarningDataS *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(WarningId CurWarningId, const Rte_DT_PayloadArr_u8_8_0 *CurWarningDispPayload)
 *     Argument CurWarningDispPayload: Rte_DT_PayloadArr_u8_8_0* is of type PayloadArr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(WarningId Warning, UInt16 ButtonEvent, UInt8 CursorSt)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UCL_HudWarnStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) OnDre_UCL_HudWarnStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UCL_HudWarnStatus
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  EChimeID Read_rpCS_ChimeRequest_Chime_Request;
  EChimeStatus Read_rpCS_GetChimeStatus_Chime_Status;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  UInt8 Read_rp_FactoryMode_FactoryMode;
  UInt8 Read_rp_FactoryModeSts_FactoryModeStatus;
  HMIReadySts_Type Read_rp_HMIReadySts_HMI_ReadyStatus;
  HMI_Screen_Mode Read_rp_HMIScreenMode_HMIScreenMode_Status;
  Hud_Wake_Type Read_rp_HUDWakeupHwSts_WakeType_Hw;
  Hud_Wake_Type Read_rp_HUDWakeupSwSts_WakeType_Int;
  SHudWarningStatus Read_rp_HUDWarningStatus_HudWarningStatusData;
  UInt8 Read_rp_IllumStartSts_StarterStatus_Out;
  UInt8 Read_rp_NVM_HUD_CoordinateFlag_NvmData;
  Tpms_Arr_u8_5 Read_rp_TPMSPayload_Tpms_Payload;
  Target_SW_Status Read_rp_TargetSWStatus_TargetSw;
  SWarningStatus Read_rp_WarningStatus_WarningStatusData;

  SHudWarningDisplay Write_pp_HUDWarningDisplay_HudWarningDisplayData;
  STpmsWarningData Write_pp_TPMSWarnPayload_TpmsWarningDataData;
  SWarningDisplay Write_pp_WarningDisplay_WarningDisplayData;

  ExtWarningData Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  WarningDataS Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus = {
  0U, 0U, 0U
};
  tTxSigConfirmStatus Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  PayloadArr_u8_8 Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_ChimeRequest_Chime_Request(&Read_rpCS_ChimeRequest_Chime_Request);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_GetChimeStatus_Chime_Status(&Read_rpCS_GetChimeStatus_Chime_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryMode_FactoryMode(&Read_rp_FactoryMode_FactoryMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryModeSts_FactoryModeStatus(&Read_rp_FactoryModeSts_FactoryModeStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&Read_rp_HMIReadySts_HMI_ReadyStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&Read_rp_HMIScreenMode_HMIScreenMode_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(&Read_rp_HUDWakeupHwSts_WakeType_Hw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(&Read_rp_HUDWakeupSwSts_WakeType_Int);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(&Read_rp_HUDWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_IllumStartSts_StarterStatus_Out(&Read_rp_IllumStartSts_StarterStatus_Out);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(&Read_rp_NVM_HUD_CoordinateFlag_NvmData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TPMSPayload_Tpms_Payload(Read_rp_TPMSPayload_Tpms_Payload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TargetSWStatus_TargetSw(&Read_rp_TargetSWStatus_TargetSw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_WarningStatus_WarningStatusData(&Read_rp_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pp_HUDWarningDisplay_HudWarningDisplayData, 0, sizeof(Write_pp_HUDWarningDisplay_HudWarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(&Write_pp_HUDWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_TPMSWarnPayload_TpmsWarningDataData, 0, sizeof(Write_pp_TPMSWarnPayload_TpmsWarningDataData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(&Write_pp_TPMSWarnPayload_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(Rte_InitValue_pp_WarnHighInt_WarningHighInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnInt_WarningInterrupt_State(Rte_InitValue_pp_WarnInt_WarningInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_WarningDisplay_WarningDisplayData, 0, sizeof(Write_pp_WarningDisplay_WarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarningDisplay_WarningDisplayData(&Write_pp_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(0U, &Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(0U, &Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(0U, &Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(0U, Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_UCL_WarnStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <WarningStatusData> of PortPrototype <rp_WarningStatus>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
 *   Std_ReturnType Rte_Read_rpCS_GetChimeStatus_Chime_Status(EChimeStatus *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_FactoryMode_FactoryMode(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_FactoryModeSts_FactoryModeStatus(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(Hud_Wake_Type *data)
 *   Std_ReturnType Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(SHudWarningStatus *data)
 *   Std_ReturnType Rte_Read_rp_IllumStartSts_StarterStatus_Out(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TPMSPayload_Tpms_Payload(Rte_DT_Tpms_Arr_u8_5_0 *data)
 *     Argument data: Rte_DT_Tpms_Arr_u8_5_0* is of type Tpms_Arr_u8_5
 *   Std_ReturnType Rte_Read_rp_TargetSWStatus_TargetSw(Target_SW_Status *data)
 *   Std_ReturnType Rte_Read_rp_WarningStatus_WarningStatusData(SWarningStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(const SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(const STpmsWarningData *data)
 *   Std_ReturnType Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarnInt_WarningInterrupt_State(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_WarningDisplay_WarningDisplayData(const SWarningDisplay *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WarningId CurrentWarning, ExtWarningData *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(WarningId CurrentWarning, WarningDataS *CurrentWarningStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(WarningId CurWarningId, const Rte_DT_PayloadArr_u8_8_0 *CurWarningDispPayload)
 *     Argument CurWarningDispPayload: Rte_DT_PayloadArr_u8_8_0* is of type PayloadArr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(WarningId Warning, UInt16 ButtonEvent, UInt8 CursorSt)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UCL_WarnStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CWarnMsg_Core_Observer_CODE) OnDre_UCL_WarnStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UCL_WarnStatus
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  EChimeID Read_rpCS_ChimeRequest_Chime_Request;
  EChimeStatus Read_rpCS_GetChimeStatus_Chime_Status;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  UInt8 Read_rp_FactoryMode_FactoryMode;
  UInt8 Read_rp_FactoryModeSts_FactoryModeStatus;
  HMIReadySts_Type Read_rp_HMIReadySts_HMI_ReadyStatus;
  HMI_Screen_Mode Read_rp_HMIScreenMode_HMIScreenMode_Status;
  Hud_Wake_Type Read_rp_HUDWakeupHwSts_WakeType_Hw;
  Hud_Wake_Type Read_rp_HUDWakeupSwSts_WakeType_Int;
  SHudWarningStatus Read_rp_HUDWarningStatus_HudWarningStatusData;
  UInt8 Read_rp_IllumStartSts_StarterStatus_Out;
  UInt8 Read_rp_NVM_HUD_CoordinateFlag_NvmData;
  Tpms_Arr_u8_5 Read_rp_TPMSPayload_Tpms_Payload;
  Target_SW_Status Read_rp_TargetSWStatus_TargetSw;
  SWarningStatus Read_rp_WarningStatus_WarningStatusData;

  SHudWarningDisplay Write_pp_HUDWarningDisplay_HudWarningDisplayData;
  STpmsWarningData Write_pp_TPMSWarnPayload_TpmsWarningDataData;
  SWarningDisplay Write_pp_WarningDisplay_WarningDisplayData;

  ExtWarningData Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  WarningDataS Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus = {
  0U, 0U, 0U
};
  tTxSigConfirmStatus Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData = 0U;
  UInt8 Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData = 0U;
  PayloadArr_u8_8 Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_ChimeRequest_Chime_Request(&Read_rpCS_ChimeRequest_Chime_Request);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_GetChimeStatus_Chime_Status(&Read_rpCS_GetChimeStatus_Chime_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryMode_FactoryMode(&Read_rp_FactoryMode_FactoryMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryModeSts_FactoryModeStatus(&Read_rp_FactoryModeSts_FactoryModeStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&Read_rp_HMIReadySts_HMI_ReadyStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&Read_rp_HMIScreenMode_HMIScreenMode_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(&Read_rp_HUDWakeupHwSts_WakeType_Hw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(&Read_rp_HUDWakeupSwSts_WakeType_Int);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(&Read_rp_HUDWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_IllumStartSts_StarterStatus_Out(&Read_rp_IllumStartSts_StarterStatus_Out);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(&Read_rp_NVM_HUD_CoordinateFlag_NvmData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TPMSPayload_Tpms_Payload(Read_rp_TPMSPayload_Tpms_Payload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TargetSWStatus_TargetSw(&Read_rp_TargetSWStatus_TargetSw);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Read_rp_WarningStatus_WarningStatusData(&Read_rp_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pp_HUDWarningDisplay_HudWarningDisplayData, 0, sizeof(Write_pp_HUDWarningDisplay_HudWarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(&Write_pp_HUDWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_TPMSWarnPayload_TpmsWarningDataData, 0, sizeof(Write_pp_TPMSWarnPayload_TpmsWarningDataData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(&Write_pp_TPMSWarnPayload_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(Rte_InitValue_pp_WarnHighInt_WarningHighInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnInt_WarningInterrupt_State(Rte_InitValue_pp_WarnInt_WarningInterrupt_State);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_WarningDisplay_WarningDisplayData, 0, sizeof(Write_pp_WarningDisplay_WarningDisplayData));
  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarningDisplay_WarningDisplayData(&Write_pp_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(0U, &Call_rpActiveWarningStatus_GetActiveWarningStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(0U, &Call_rp_ActiveWarningSts_GetWarningActiveStatus_CurrentWarningStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(0U, &Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation_pStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValue_pTxSignalData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(0U, &Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr_pTxSignalData, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsTx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(0U, Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload_CurWarningDispPayload);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CWarnMsg_Core_Observer_Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CWarnMsg_Core_Observer_STOP_SEC_CODE
#include "CWarnMsg_Core_Observer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CWarnMsg_Core_Observer_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  EButtonId Test_EButtonId_V_1 = EButtonId_None;
  EButtonId Test_EButtonId_V_2 = EButtonId_Ok;
  EButtonId Test_EButtonId_V_3 = EButtonId_Up;
  EButtonId Test_EButtonId_V_4 = EButtonId_Down;
  EButtonId Test_EButtonId_V_5 = EButtonId_Back;
  EButtonId Test_EButtonId_V_6 = EButtonId_Menu;
  EButtonId Test_EButtonId_V_7 = EButtonId_Phone;
  EButtonId Test_EButtonId_V_8 = EButtonId_Hud;
  EButtonId Test_EButtonId_V_9 = EButtonId_Last;

  EButtonSts Test_EButtonSts_V_1 = EButtonSts_Off;
  EButtonSts Test_EButtonSts_V_2 = EButtonSts_On;
  EButtonSts Test_EButtonSts_V_3 = EButtonSts_Short;
  EButtonSts Test_EButtonSts_V_4 = EButtonSts_Long;
  EButtonSts Test_EButtonSts_V_5 = EButtonSts_Repeat;
  EButtonSts Test_EButtonSts_V_6 = EButtonSts_Last;

  EChimeID Test_EChimeID_V_1 = NO_CHIME_ID;
  EChimeID Test_EChimeID_V_2 = MAX_CHIME_ID;

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  HMI_Screen_Mode Test_HMI_Screen_Mode_V_1 = eSCREENMODE_OFF;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_2 = eSCREENMODE_BLANK;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_3 = eSCREENMODE_NORMAL;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_4 = eSCREENMODE_DISPLAY_ADJ;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_5 = eSCREENMODE_WELCOME;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_6 = eSCREENMODE_IGNOFF_CHR;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_7 = eSCREENMODE_OPENING;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_8 = eSCREENMODE_ENDING;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_9 = eSCREENMODE_ENDING_IGNOFF_CHR;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_10 = eSCREENMODE_RESERVED;

  Hud_Wake_Type Test_Hud_Wake_Type_V_1 = HUD_WK_LO;
  Hud_Wake_Type Test_Hud_Wake_Type_V_2 = HUD_WK_HI;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  Target_SW_Status Test_Target_SW_Status_V_1 = NO_TARGET;
  Target_SW_Status Test_Target_SW_Status_V_2 = TG_LEFT;
  Target_SW_Status Test_Target_SW_Status_V_3 = TG_UP;
  Target_SW_Status Test_Target_SW_Status_V_4 = TG_DOWN;
  Target_SW_Status Test_Target_SW_Status_V_5 = TG_RIGHT;
  Target_SW_Status Test_Target_SW_Status_V_6 = TG_ENTER;
  Target_SW_Status Test_Target_SW_Status_V_7 = TG_BACK;
  Target_SW_Status Test_Target_SW_Status_V_8 = TG_MAX;

  WarningDisplayedStatus Test_WarningDisplayedStatus_V_1 = WRNG_NOTIFIED_NONE;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_2 = WRNG_NOTIFIED_ACKNOWLEDGED;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_3 = WRNG_NOTIFIED_TIMEOUT;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_4 = WRNG_NOTIFIED_HIDDEN;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_5 = WRNG_NOTIFIED_SHOW;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_6 = WRNG_NOTIFIED_ACTIVE;
  WarningDisplayedStatus Test_WarningDisplayedStatus_V_7 = WRNG_NOTIFIED_INACTIVE;

  WarningEvent Test_WarningEvent_V_1 = UI_WARNING_EVENT_NONE;
  WarningEvent Test_WarningEvent_V_2 = UI_WARNING_EVENT_RETRIGGER;
  WarningEvent Test_WarningEvent_V_3 = UI_WARNING_EVENT_FORCED;

  WarningId Test_WarningId_V_1 = WRN_NORM_BRLV_02;
  WarningId Test_WarningId_V_2 = WRN_NORM_ECB_02;
  WarningId Test_WarningId_V_3 = WRN_NORM_BRK_02;
  WarningId Test_WarningId_V_4 = WRN_NORM_BRKHLD_10;
  WarningId Test_WarningId_V_5 = WRN_NORM_BRKHLD_12;
  WarningId Test_WarningId_V_6 = WRN_NORM_BRKHLD_16;
  WarningId Test_WarningId_V_7 = WRN_NORM_ABS_02;
  WarningId Test_WarningId_V_8 = WRN_NORM_AUTHIG_02;
  WarningId Test_WarningId_V_9 = WRN_NORM_ADAHIG_02;
  WarningId Test_WarningId_V_10 = WRN_NORM_BRKHLD_02;
  WarningId Test_WarningId_V_11 = WRN_NORM_BRKHLD_03;
  WarningId Test_WarningId_V_12 = WRN_NORM_BRKHLD_05;
  WarningId Test_WarningId_V_13 = WRN_NORM_BRKHLD_06;
  WarningId Test_WarningId_V_14 = WRN_NORM_BRKHLD_07;
  WarningId Test_WarningId_V_15 = WRN_NORM_BRKHLD_08;
  WarningId Test_WarningId_V_16 = WRN_NORM_BRKHLD_11;
  WarningId Test_WarningId_V_17 = WRN_NORM_BRKHLD_13;
  WarningId Test_WarningId_V_18 = WRN_NORM_BRKHLD_14;
  WarningId Test_WarningId_V_19 = WRN_NORM_BRKHLD_15;
  WarningId Test_WarningId_V_20 = WRN_NORM_BRKHLD_17;
  WarningId Test_WarningId_V_21 = WRN_NORM_AIRBAG_03;
  WarningId Test_WarningId_V_22 = WRN_NORM_AUTHIG_04;
  WarningId Test_WarningId_V_23 = WRN_NORM_ADAHIG_04;
  WarningId Test_WarningId_V_24 = WRN_NORM_ADASTT_05;
  WarningId Test_WarningId_V_25 = WRN_NORM_ADASTT_07;
  WarningId Test_WarningId_V_26 = WRN_NORM_ADASTT_09;
  WarningId Test_WarningId_V_27 = WRN_NORM_ADASTT_10;
  WarningId Test_WarningId_V_28 = WRN_NORM_ADASTT_11;
  WarningId Test_WarningId_V_29 = WRN_NORM_TFUEL_01;
  WarningId Test_WarningId_V_30 = WRN_NORM_PSC1_02;
  WarningId Test_WarningId_V_31 = WRN_NORM_PSC1_04;
  WarningId Test_WarningId_V_32 = WRN_NORM_PSC1_05;
  WarningId Test_WarningId_V_33 = WRN_NORM_PSC1_06;
  WarningId Test_WarningId_V_34 = WRN_NORM_PSC1_07;
  WarningId Test_WarningId_V_35 = WRN_NORM_PSC1_08;
  WarningId Test_WarningId_V_36 = WRN_NORM_PSC1_09;
  WarningId Test_WarningId_V_37 = WRN_NORM_PSC1_10;
  WarningId Test_WarningId_V_38 = WRN_NORM_PSC1_12;
  WarningId Test_WarningId_V_39 = WRN_NORM_PSC1_13;
  WarningId Test_WarningId_V_40 = WRN_NORM_EPB_03;
  WarningId Test_WarningId_V_41 = WRN_NORM_EPB_04;
  WarningId Test_WarningId_V_42 = WRN_NORM_EPB_05;
  WarningId Test_WarningId_V_43 = WRN_NORM_EPB_08;
  WarningId Test_WarningId_V_44 = WRN_NORM_EPB_10;
  WarningId Test_WarningId_V_45 = WRN_NORM_EPB_11;
  WarningId Test_WarningId_V_46 = WRN_NORM_EPB_12;
  WarningId Test_WarningId_V_47 = WRN_NORM_EPB_13;
  WarningId Test_WarningId_V_48 = WRN_NORM_EPB_14;
  WarningId Test_WarningId_V_49 = WRN_NORM_EPB_15;
  WarningId Test_WarningId_V_50 = WRN_NORM_EPB_16;
  WarningId Test_WarningId_V_51 = WRN_NORM_EPB_17;
  WarningId Test_WarningId_V_52 = WRN_NORM_EPB_18;
  WarningId Test_WarningId_V_53 = WRN_NORM_TRCOFF_02;
  WarningId Test_WarningId_V_54 = WRN_NORM_WASLEV_02;
  WarningId Test_WarningId_V_55 = WRN_NORM_BVOOPE_02;
  WarningId Test_WarningId_V_56 = WRN_NORM_THESEN_02;
  WarningId Test_WarningId_V_57 = WRN_NORM_THESEN_03;
  WarningId Test_WarningId_V_58 = WRN_CUSTMIZE_DIGKEY_04;
  WarningId Test_WarningId_V_59 = WRN_CUSTMIZE_DIGKEY_05;
  WarningId Test_WarningId_V_60 = WRN_CUSTMIZE_DIGKEY_06;
  WarningId Test_WarningId_V_61 = WRN_CUSTMIZE_DIGKEY_07;
  WarningId Test_WarningId_V_62 = WRN_NORM_MLGT_01;
  WarningId Test_WarningId_V_63 = WRN_NORM_TPWSR_01;
  WarningId Test_WarningId_V_64 = WRN_NORM_TPWSR_02;
  WarningId Test_WarningId_V_65 = WRN_NORM_TPWSR_03;
  WarningId Test_WarningId_V_66 = WRN_NORM_SMASTA_02;
  WarningId Test_WarningId_V_67 = WRN_NORM_SMASTA_03;
  WarningId Test_WarningId_V_68 = WRN_NORM_SMASTA_04;
  WarningId Test_WarningId_V_69 = WRN_NORM_SMASTA_05;
  WarningId Test_WarningId_V_70 = WRN_NORM_SMASTA_06;
  WarningId Test_WarningId_V_71 = WRN_NORM_SMASTA_07;
  WarningId Test_WarningId_V_72 = WRN_NORM_SMASTA_08;
  WarningId Test_WarningId_V_73 = WRN_NORM_SMASTA_09;
  WarningId Test_WarningId_V_74 = WRN_NORM_SMASTA_10;
  WarningId Test_WarningId_V_75 = WRN_NORM_SMASTA_11;
  WarningId Test_WarningId_V_76 = WRN_NORM_SMASTA_12;
  WarningId Test_WarningId_V_77 = WRN_NORM_SMASTA_13;
  WarningId Test_WarningId_V_78 = WRN_NORM_SMASTA_17;
  WarningId Test_WarningId_V_79 = WRN_NORM_SMASTA_18;
  WarningId Test_WarningId_V_80 = WRN_NORM_SMASTA_19;
  WarningId Test_WarningId_V_81 = WRN_NORM_SMASTA_20;
  WarningId Test_WarningId_V_82 = WRN_NORM_SMASTA_21;
  WarningId Test_WarningId_V_83 = WRN_NORM_SMASTA_23;
  WarningId Test_WarningId_V_84 = WRN_NORM_SMASTA_24;
  WarningId Test_WarningId_V_85 = WRN_NORM_SMASTA_25;
  WarningId Test_WarningId_V_86 = WRN_NORM_SMASTA_26;
  WarningId Test_WarningId_V_87 = WRN_NORM_SMASTA_28;
  WarningId Test_WarningId_V_88 = WRN_NORM_SMASTA_29;
  WarningId Test_WarningId_V_89 = WRN_NORM_SMASTA_30;
  WarningId Test_WarningId_V_90 = WRN_NORM_SMASTA_31;
  WarningId Test_WarningId_V_91 = WRN_NORM_SMASTA_32;
  WarningId Test_WarningId_V_92 = WRN_NORM_SMASTA_33;
  WarningId Test_WarningId_V_93 = WRN_NORM_SMASTA_34;
  WarningId Test_WarningId_V_94 = WRN_NORM_SMASTA_36;
  WarningId Test_WarningId_V_95 = WRN_NORM_SMASTA_37;
  WarningId Test_WarningId_V_96 = WRN_NORM_SMASTA_38;
  WarningId Test_WarningId_V_97 = WRN_NORM_SMASTA_39;
  WarningId Test_WarningId_V_98 = WRN_NORM_SMASTA_40;
  WarningId Test_WarningId_V_99 = WRN_NORM_SMASTA_41;
  WarningId Test_WarningId_V_100 = WRN_NORM_LEDHEA_01;
  WarningId Test_WarningId_V_101 = WRN_NORM_HEALEV_02;
  WarningId Test_WarningId_V_102 = WRN_NORM_HEALEV_03;
  WarningId Test_WarningId_V_103 = WRN_NORM_GRISHU_02;
  WarningId Test_WarningId_V_104 = WRN_NORM_AVAS_02;
  WarningId Test_WarningId_V_105 = WRN_NORM_ALOA_03;
  WarningId Test_WarningId_V_106 = WRN_NORM_PCS2_03;
  WarningId Test_WarningId_V_107 = WRN_NORM_PCS2_11;
  WarningId Test_WarningId_V_108 = WRN_NORM_TRWIP_01;
  WarningId Test_WarningId_V_109 = WRN_NORM_RSEREM_02;
  WarningId Test_WarningId_V_110 = WRN_NORM_RSEREM_03;
  WarningId Test_WarningId_V_111 = WRN_NORM_RSEREM_04;
  WarningId Test_WarningId_V_112 = WRN_NORM_RSEREM_05;
  WarningId Test_WarningId_V_113 = WRN_NORM_4WDSYS_03;
  WarningId Test_WarningId_V_114 = WRN_NORM_4WDSYS_04;
  WarningId Test_WarningId_V_115 = WRN_NORM_4WDSYS_06;
  WarningId Test_WarningId_V_116 = WRN_NORM_CVTOIL_02;
  WarningId Test_WarningId_V_117 = WRN_NORM_CVTOIL_03;
  WarningId Test_WarningId_V_118 = WRN_NORM_ATMAL_02;
  WarningId Test_WarningId_V_119 = WRN_NORM_SFTPOS_02;
  WarningId Test_WarningId_V_120 = WRN_NORM_SFTPOS_03;
  WarningId Test_WarningId_V_121 = WRN_NORM_SFTPOS_04;
  WarningId Test_WarningId_V_122 = WRN_NORM_MCBW_02;
  WarningId Test_WarningId_V_123 = WRN_NORM_TPWS_01;
  WarningId Test_WarningId_V_124 = WRN_NORM_TPWS_02;
  WarningId Test_WarningId_V_125 = WRN_NORM_OILMIL_02;
  WarningId Test_WarningId_V_126 = WRN_NORM_OILMIL_03;
  WarningId Test_WarningId_V_127 = WRN_NORM_OILMIL_04;
  WarningId Test_WarningId_V_128 = WRN_NORM_OILMIL_05;
  WarningId Test_WarningId_V_129 = WRN_NORM_BRLV0_02;
  WarningId Test_WarningId_V_130 = WRN_NORM_OILPRE_01;
  WarningId Test_WarningId_V_131 = WRN_NORM_BRK0_02;
  WarningId Test_WarningId_V_132 = WRN_NORM_BRK0_03;
  WarningId Test_WarningId_V_133 = WRN_NORM_EPS_02;
  WarningId Test_WarningId_V_134 = WRN_NORM_EPS_03;
  WarningId Test_WarningId_V_135 = WRN_NORM_EPS_04;
  WarningId Test_WarningId_V_136 = WRN_NORM_EPS_05;
  WarningId Test_WarningId_V_137 = WRN_NORM_EPS_06;
  WarningId Test_WarningId_V_138 = WRN_NORM_EPS_07;
  WarningId Test_WarningId_V_139 = WRN_NORM_EPS_09;
  WarningId Test_WarningId_V_140 = WRN_NORM_EPS_10;
  WarningId Test_WarningId_V_141 = WRN_NORM_EPS_11;
  WarningId Test_WarningId_V_142 = WRN_NORM_FUECAP_02;
  WarningId Test_WarningId_V_143 = WRN_NORM_CHEENG_02;
  WarningId Test_WarningId_V_144 = WRN_NORM_CHEENG_03;
  WarningId Test_WarningId_V_145 = WRN_NORM_CHEENG_04;
  WarningId Test_WarningId_V_146 = WRN_NORM_CHEENG_07;
  WarningId Test_WarningId_V_147 = WRN_NORM_ROLAWA_01;
  WarningId Test_WarningId_V_148 = WRN_NORM_ROLAWA_02;
  WarningId Test_WarningId_V_149 = WRN_NORM_ROLAWA_03;
  WarningId Test_WarningId_V_150 = WRN_NORM_GPF_05;
  WarningId Test_WarningId_V_151 = WRN_NORM_GPF_06;
  WarningId Test_WarningId_V_152 = WRN_NORM_GPF_07;
  WarningId Test_WarningId_V_153 = WRN_NORM_GPF_08;
  WarningId Test_WarningId_V_154 = WRN_NORM_GPF_09;
  WarningId Test_WarningId_V_155 = WRN_NORM_GPF_10;
  WarningId Test_WarningId_V_156 = WRN_NORM_GPF_11;
  WarningId Test_WarningId_V_157 = WRN_NORM_OILLEV_02;
  WarningId Test_WarningId_V_158 = WRN_NORM_COOTEM_03;
  WarningId Test_WarningId_V_159 = WRN_NORM_ONACCN_03;
  WarningId Test_WarningId_V_160 = WRN_NORM_BATLOW_02;
  WarningId Test_WarningId_V_161 = WRN_NORM_CHAMAL_02;
  WarningId Test_WarningId_V_162 = WRN_NORM_CHAMAL_03;
  WarningId Test_WarningId_V_163 = WRN_NORM_POWMAN_02;
  WarningId Test_WarningId_V_164 = WRN_NORM_SOCLOW_02;
  WarningId Test_WarningId_V_165 = WRN_NORM_SOCLOW_03;
  WarningId Test_WarningId_V_166 = WRN_NORM_BATINS_02;
  WarningId Test_WarningId_V_167 = WRN_NORM_BATINS_03;
  WarningId Test_WarningId_V_168 = WRN_NORM_BATINS_04;
  WarningId Test_WarningId_V_169 = WRN_NORM_BATINS_05;
  WarningId Test_WarningId_V_170 = WRN_NORM_ONACCP_02;
  WarningId Test_WarningId_V_171 = WRN_NORM_ALMN_02;
  WarningId Test_WarningId_V_172 = WRN_NORM_HEAECU_02;
  WarningId Test_WarningId_V_173 = WRN_NORM_BOS_02;
  WarningId Test_WarningId_V_174 = WRN_NORM_BOS_03;
  WarningId Test_WarningId_V_175 = WRN_NORM_EVMOD_02;
  WarningId Test_WarningId_V_176 = WRN_NORM_EVMOD_03;
  WarningId Test_WarningId_V_177 = WRN_NORM_EVMOD_04;
  WarningId Test_WarningId_V_178 = WRN_NORM_EVMOD_05;
  WarningId Test_WarningId_V_179 = WRN_NORM_EVMOD_06;
  WarningId Test_WarningId_V_180 = WRN_NORM_EVMOD_07;
  WarningId Test_WarningId_V_181 = WRN_NORM_EVMOD_08;
  WarningId Test_WarningId_V_182 = WRN_NORM_EVMOD_09;
  WarningId Test_WarningId_V_183 = WRN_NORM_EVMOD_10;
  WarningId Test_WarningId_V_184 = WRN_NORM_DSC_02;
  WarningId Test_WarningId_V_185 = WRN_NORM_DSC_03;
  WarningId Test_WarningId_V_186 = WRN_NORM_DSC_04;
  WarningId Test_WarningId_V_187 = WRN_NORM_ROLAWA1_01;
  WarningId Test_WarningId_V_188 = WRN_NORM_ROLAWA1_02;
  WarningId Test_WarningId_V_189 = WRN_NORM_ROLAWA1_03;
  WarningId Test_WarningId_V_190 = WRN_NORM_ROLAWA1_04;
  WarningId Test_WarningId_V_191 = WRN_NORM_ROLAWA1_05;
  WarningId Test_WarningId_V_192 = WRN_NORM_ROLAWA1_06;
  WarningId Test_WarningId_V_193 = WRN_NORM_ROLAWA1_07;
  WarningId Test_WarningId_V_194 = WRN_NORM_ROLAWA1_08;
  WarningId Test_WarningId_V_195 = WRN_NORM_ROLAWA1_09;
  WarningId Test_WarningId_V_196 = WRN_NORM_ROLAWA1_10;
  WarningId Test_WarningId_V_197 = WRN_NORM_ROLAWA1_11;
  WarningId Test_WarningId_V_198 = WRN_NORM_MAICER_09;
  WarningId Test_WarningId_V_199 = WRN_NORM_MAICER_10;
  WarningId Test_WarningId_V_200 = WRN_NORM_MAICER_11;
  WarningId Test_WarningId_V_201 = WRN_NORM_MAICER_12;
  WarningId Test_WarningId_V_202 = WRN_NORM_PKSB_09;
  WarningId Test_WarningId_V_203 = WRN_NORM_PKSB_10;
  WarningId Test_WarningId_V_204 = WRN_NORM_PKSB_11;
  WarningId Test_WarningId_V_205 = WRN_NORM_PKSB_13;
  WarningId Test_WarningId_V_206 = WRN_NORM_PKSB_14;
  WarningId Test_WarningId_V_207 = WRN_NORM_ISA_02;
  WarningId Test_WarningId_V_208 = WRN_NORM_ISA_04;
  WarningId Test_WarningId_V_209 = WRN_NORM_TCBM_01;
  WarningId Test_WarningId_V_210 = WRN_NORM_TCBM_02;
  WarningId Test_WarningId_V_211 = WRN_NORM_ADAFRO_02;
  WarningId Test_WarningId_V_212 = WRN_NORM_PDA_03;
  WarningId Test_WarningId_V_213 = WRN_NORM_RTAN_03;
  WarningId Test_WarningId_V_214 = WRN_NORM_SEA_02;
  WarningId Test_WarningId_V_215 = WRN_NORM_T120_01;
  WarningId Test_WarningId_V_216 = WRN_POWER_EIGCON_02;
  WarningId Test_WarningId_V_217 = WRN_POWER_EIGCON_04;
  WarningId Test_WarningId_V_218 = WRN_PROSRV_PROSRV_02;
  WarningId Test_WarningId_V_219 = WRN_PROSRV_PROSRV_03;
  WarningId Test_WarningId_V_220 = WRN_PROSRV_PROSRV_04;
  WarningId Test_WarningId_V_221 = WRN_PROSRV_PROSRV_05;
  WarningId Test_WarningId_V_222 = WRN_PROSRV_PROSRV_08;
  WarningId Test_WarningId_V_223 = WRN_PROSRV_PROSRV_09;
  WarningId Test_WarningId_V_224 = WRN_PROSRV_PROSRV_10;
  WarningId Test_WarningId_V_225 = WRN_PROSRV_PROSRV_11;
  WarningId Test_WarningId_V_226 = WRN_PROSRV_PROSRV_12;
  WarningId Test_WarningId_V_227 = WRN_PROSRV_PROSRV_13;
  WarningId Test_WarningId_V_228 = WRN_PROSRV_PROSRV_22;
  WarningId Test_WarningId_V_229 = WRN_PROSRV_PROSRV_23;
  WarningId Test_WarningId_V_230 = WRN_NORM_BATCOO_02;
  WarningId Test_WarningId_V_231 = WRN_NORM_BATCOO_03;
  WarningId Test_WarningId_V_232 = WRN_NORM_LDA_02;
  WarningId Test_WarningId_V_233 = WRN_NORM_LDA_03;
  WarningId Test_WarningId_V_234 = WRN_NORM_LDA_06;
  WarningId Test_WarningId_V_235 = WRN_NORM_LDA_07;
  WarningId Test_WarningId_V_236 = WRN_NORM_LTA_02;
  WarningId Test_WarningId_V_237 = WRN_NORM_LTA_03;
  WarningId Test_WarningId_V_238 = WRN_NORM_LTA_07;
  WarningId Test_WarningId_V_239 = WRN_NORM_LCA_02;
  WarningId Test_WarningId_V_240 = WRN_NORM_LCA_03;
  WarningId Test_WarningId_V_241 = WRN_NORM_LCA_04;
  WarningId Test_WarningId_V_242 = WRN_NORM_LCA_05;
  WarningId Test_WarningId_V_243 = WRN_NORM_LCA_15;
  WarningId Test_WarningId_V_244 = WRN_NORM_LCA_16;
  WarningId Test_WarningId_V_245 = WRN_NORM_LCA_17;
  WarningId Test_WarningId_V_246 = WRN_NORM_LCA_20;
  WarningId Test_WarningId_V_247 = WRN_NORM_RSA_01;
  WarningId Test_WarningId_V_248 = WRN_NORM_RSA_04;
  WarningId Test_WarningId_V_249 = WRN_NORM_RSA_05;
  WarningId Test_WarningId_V_250 = WRN_NORM_CHADYN_01;
  WarningId Test_WarningId_V_251 = WRN_NORM_CHADYN_02;
  WarningId Test_WarningId_V_252 = WRN_NORM_TOWWAR_02;
  WarningId Test_WarningId_V_253 = WRN_NORM_TOWWAR_03;
  WarningId Test_WarningId_V_254 = WRN_NORM_TOWWAR_05;
  WarningId Test_WarningId_V_255 = WRN_NORM_DMC_02;
  WarningId Test_WarningId_V_256 = WRN_NORM_DMC_03;
  WarningId Test_WarningId_V_257 = WRN_NORM_DMC_05;
  WarningId Test_WarningId_V_258 = WRN_NORM_DMC_06;
  WarningId Test_WarningId_V_259 = WRN_NORM_DMC_12;
  WarningId Test_WarningId_V_260 = WRN_NORM_DMC_13;
  WarningId Test_WarningId_V_261 = WRN_NORM_DMC_14;
  WarningId Test_WarningId_V_262 = WRN_NORM_DMC_15;
  WarningId Test_WarningId_V_263 = WRN_NORM_DMC_17;
  WarningId Test_WarningId_V_264 = WRN_NORM_DMC_18;
  WarningId Test_WarningId_V_265 = WRN_NORM_ICYRA_01;
  WarningId Test_WarningId_V_266 = WRN_NORM_SEA_NCYC_02;
  WarningId Test_WarningId_V_267 = WRN_NORM_DRIPOW_02;
  WarningId Test_WarningId_V_268 = WRN_NORM_DRIPOW_03;
  WarningId Test_WarningId_V_269 = WRN_NORM_DRIPOW_04;
  WarningId Test_WarningId_V_270 = WRN_NORM_CCS_02;
  WarningId Test_WarningId_V_271 = WRN_NORM_CCS_03;
  WarningId Test_WarningId_V_272 = WRN_NORM_ACC_02;
  WarningId Test_WarningId_V_273 = WRN_NORM_ACC_03;
  WarningId Test_WarningId_V_274 = WRN_NORM_ACC_04;
  WarningId Test_WarningId_V_275 = WRN_NORM_ACC_05;
  WarningId Test_WarningId_V_276 = WRN_NORM_ACC_06;
  WarningId Test_WarningId_V_277 = WRN_NORM_ACC_07;
  WarningId Test_WarningId_V_278 = WRN_NORM_ACC_08;
  WarningId Test_WarningId_V_279 = WRN_NORM_ACC_09;
  WarningId Test_WarningId_V_280 = WRN_NORM_ACC_10;
  WarningId Test_WarningId_V_281 = WRN_NORM_ACC_11;
  WarningId Test_WarningId_V_282 = WRN_NORM_ACC_12;
  WarningId Test_WarningId_V_283 = WRN_NORM_ACC_18;
  WarningId Test_WarningId_V_284 = WRN_NORM_ACC_19;
  WarningId Test_WarningId_V_285 = WRN_NORM_ACC_21;
  WarningId Test_WarningId_V_286 = WRN_NORM_DESA_02;
  WarningId Test_WarningId_V_287 = WRN_NORM_DESA_03;
  WarningId Test_WarningId_V_288 = WRN_NORM_DESA_04;
  WarningId Test_WarningId_V_289 = WRN_NORM_DESA_05;
  WarningId Test_WarningId_V_290 = WRN_NORM_DESA_06;
  WarningId Test_WarningId_V_291 = WRN_NORM_DESA_07;
  WarningId Test_WarningId_V_292 = WRN_NORM_DESA_08;
  WarningId Test_WarningId_V_293 = WRN_NORM_PEXI_02;
  WarningId Test_WarningId_V_294 = WRN_NORM_RESADJ_09;
  WarningId Test_WarningId_V_295 = WRN_NORM_RESADJ_10;
  WarningId Test_WarningId_V_296 = WRN_NORM_RESADJ_11;
  WarningId Test_WarningId_V_297 = WRN_NORM_RESADJ_12;
  WarningId Test_WarningId_V_298 = WRN_NORM_RESADJ_13;
  WarningId Test_WarningId_V_299 = WRN_NORM_RESADJ_14;
  WarningId Test_WarningId_V_300 = WRN_NORM_RESADJ_15;
  WarningId Test_WarningId_V_301 = WRN_NORM_TSMODE_02;
  WarningId Test_WarningId_V_302 = WRN_NORM_UNIOVE_02;
  WarningId Test_WarningId_V_303 = WRN_NORM_UNIOVE_04;
  WarningId Test_WarningId_V_304 = WARN_ADAS_SDG_01;
  WarningId Test_WarningId_V_305 = WRN_ADAS_PDA_01;
  WarningId Test_WarningId_V_306 = WRN_ADAS_PDA_02;
  WarningId Test_WarningId_V_307 = WRN_NORM_TDOOR_01;
  WarningId Test_WarningId_V_308 = WRN_NORM_TDOOR_02;
  WarningId Test_WarningId_V_309 = WRN_NORM_TDOOR_03;
  WarningId Test_WarningId_V_310 = WRN_NORM_ACCHOL_02;
  WarningId Test_WarningId_V_311 = WRN_NORM_ACCHOL_03;
  WarningId Test_WarningId_V_312 = WRN_NORM_ACCHOL_05;
  WarningId Test_WarningId_V_313 = WRN_NORM_MAICER_09_RESADJ_09;
  WarningId Test_WarningId_V_314 = WRN_NORM_MAICER_09_RESADJ_10;
  WarningId Test_WarningId_V_315 = WRN_NORM_MAICER_09_RESADJ_11;
  WarningId Test_WarningId_V_316 = WRN_NORM_MAICER_09_RESADJ_12;
  WarningId Test_WarningId_V_317 = WRN_NORM_MAICER_09_RESADJ_13;
  WarningId Test_WarningId_V_318 = WRN_NORM_MAICER_09_RESADJ_14;
  WarningId Test_WarningId_V_319 = WRN_NORM_MAICER_09_RESADJ_15;
  WarningId Test_WarningId_V_320 = WRN_NORM_MAICER_11_RESADJ_09;
  WarningId Test_WarningId_V_321 = WRN_NORM_MAICER_11_RESADJ_10;
  WarningId Test_WarningId_V_322 = WRN_NORM_MAICER_11_RESADJ_11;
  WarningId Test_WarningId_V_323 = WRN_NORM_MAICER_11_RESADJ_12;
  WarningId Test_WarningId_V_324 = WRN_NORM_MAICER_11_RESADJ_13;
  WarningId Test_WarningId_V_325 = WRN_NORM_MAICER_11_RESADJ_14;
  WarningId Test_WarningId_V_326 = WRN_NORM_MAICER_11_RESADJ_15;
  WarningId Test_WarningId_V_327 = WRN_NORM_CVRS_04;
  WarningId Test_WarningId_V_328 = WRN_NORM_CVRS_05;
  WarningId Test_WarningId_V_329 = WRN_NORM_SMASTA_42;
  WarningId Test_WarningId_V_330 = WRN_NORM_SMASTA_43;
  WarningId Test_WarningId_V_331 = WRN_NORM_SMASTA_44;
  WarningId Test_WarningId_V_332 = WRN_NORM_SMASTA_45;
  WarningId Test_WarningId_V_333 = WRN_NORM_SMASTA_46;
  WarningId Test_WarningId_V_334 = WRN_NORM_SMASTA_47;
  WarningId Test_WarningId_V_335 = WRN_NORM_SMASTA_48;
  WarningId Test_WarningId_V_336 = WRN_MFLID_MFLID_01;
  WarningId Test_WarningId_V_337 = WRN_NORM_MFLID_02;
  WarningId Test_WarningId_V_338 = WRN_NORM_MFLID_03;
  WarningId Test_WarningId_V_339 = WRN_NORM_TMNT_15;
  WarningId Test_WarningId_V_340 = WRN_NORM_TMNT_16;
  WarningId Test_WarningId_V_341 = WRN_ADAS_LCA1;
  WarningId Test_WarningId_V_342 = WRN_ADAS_LCA2;
  WarningId Test_WarningId_V_343 = WRN_DOOR_UNLMOD_02;
  WarningId Test_WarningId_V_344 = WARN_ADAS_PDA1;
  WarningId Test_WarningId_V_345 = WRN_ADAS_URSM_01;
  WarningId Test_WarningId_V_346 = WRN_ADAS_URSM_02;
  WarningId Test_WarningId_V_347 = WRN_ADAS_URSM_03;
  WarningId Test_WarningId_V_348 = WRN_ADAS_URSM_04;
  WarningId Test_WarningId_V_349 = WRN_ADAS_URSM_05;
  WarningId Test_WarningId_V_350 = WRN_ADAS_URSM_06;
  WarningId Test_WarningId_V_351 = WRN_ADAS_URSM_07;
  WarningId Test_WarningId_V_352 = WRN_NORM_SYSMAL_HVIND1;
  WarningId Test_WarningId_V_353 = WRN_NORM_SYSMAL_HVIND2;
  WarningId Test_WarningId_V_354 = WRN_NORM_SYSMAL_HVIND3;
  WarningId Test_WarningId_V_355 = WRN_NORM_SYSMAL_HVIND4;
  WarningId Test_WarningId_V_356 = WRN_NORM_SYSMAL_HVIND5;
  WarningId Test_WarningId_V_357 = WRN_NORM_SYSMAL_HVIND6;
  WarningId Test_WarningId_V_358 = WRN_NORM_SYSMAL_HVIND7;
  WarningId Test_WarningId_V_359 = WRN_NORM_SYSMAL_HVIND8;
  WarningId Test_WarningId_V_360 = WRN_NORM_SYSMAL_HVIND9;
  WarningId Test_WarningId_V_361 = WRN_NORM_SYSMAL_HVIND10;
  WarningId Test_WarningId_V_362 = WRN_NORM_SYSMAL_HVIND11;
  WarningId Test_WarningId_V_363 = WRN_NORM_SYSMAL_HVIND12;
  WarningId Test_WarningId_V_364 = WRN_NORM_SYSMAL_HVIND13;
  WarningId Test_WarningId_V_365 = WRN_NORM_SYSMAL_HVIND14;
  WarningId Test_WarningId_V_366 = WRN_NORM_SYSMAL_HVIND15;
  WarningId Test_WarningId_V_367 = WRN_NORM_SYSMAL_HVIND16;
  WarningId Test_WarningId_V_368 = WRN_NORM_SYSMAL_HVIND17;
  WarningId Test_WarningId_V_369 = WRN_NORM_FHL_04;
  WarningId Test_WarningId_V_370 = WRN_NORM_SMASTA_52;
  WarningId Test_WarningId_V_371 = WRN_NORM_SMASTA_53;
  WarningId Test_WarningId_V_372 = WRN_NORM_GPF_MEV01_02;
  WarningId Test_WarningId_V_373 = WRN_NORM_GPF_MEV01_03;
  WarningId Test_WarningId_V_374 = WRN_NORM_GPF_MEV01_04;
  WarningId Test_WarningId_V_375 = WRN_NORM_GPF_MEV01_05;
  WarningId Test_WarningId_V_376 = WRN_NORM_GPF_MEV01_06;
  WarningId Test_WarningId_V_377 = WRN_NORM_GPF_MEV01_07;
  WarningId Test_WarningId_V_378 = WRN_NORM_GPF_MEV01_08;
  WarningId Test_WarningId_V_379 = WRN_NORM_VCOPE_02;
  WarningId Test_WarningId_V_380 = WRN_NORM_VCOPE_03;
  WarningId Test_WarningId_V_381 = WRN_ADAS_LCA_01;
  WarningId Test_WarningId_V_382 = WRN_ADAS_LCA_03;
  WarningId Test_WarningId_V_383 = WRN_ADAS_LCA_04;
  WarningId Test_WarningId_V_384 = WRN_NORM_FCMDI_01;
  WarningId Test_WarningId_V_385 = WRN_NORM_FCMDI_02;
  WarningId Test_WarningId_V_386 = WRN_NORM_FCMDI_03;
  WarningId Test_WarningId_V_387 = WRN_NORM_FCMDI_04;
  WarningId Test_WarningId_V_388 = WRN_NORM_FCMDI_05;
  WarningId Test_WarningId_V_389 = WRN_NORM_FCMDI_06;
  WarningId Test_WarningId_V_390 = WRN_NORM_FCMDI_07;
  WarningId Test_WarningId_V_391 = WRN_NORM_TSMODE_VM01_02;
  WarningId Test_WarningId_V_392 = WRN_ADAS_ACC_01;
  WarningId Test_WarningId_V_393 = WRN_ADAS_ACC_02;
  WarningId Test_WarningId_V_394 = WRN_ADAS_ACC_03;
  WarningId Test_WarningId_V_395 = WRN_ADAS_ACC_04;
  WarningId Test_WarningId_V_396 = WRN_ADAS_ACC_05;
  WarningId Test_WarningId_V_397 = WRN_ADAS_ACC_22;
  WarningId Test_WarningId_V_398 = WRN_ADAS_ACC_23;
  WarningId Test_WarningId_V_399 = WRN_ADAS_ACC_24;
  WarningId Test_WarningId_V_400 = WRN_ADAS_ACC_25;
  WarningId Test_WarningId_V_401 = WRN_ADAS_ACC_26;
  WarningId Test_WarningId_V_402 = WRN_ADAS_ACC_27;
  WarningId Test_WarningId_V_403 = WRN_ADAS_ACC_28;
  WarningId Test_WarningId_V_404 = WRN_ADAS_ACC_29;
  WarningId Test_WarningId_V_405 = WRN_ADAS_ACC_30;
  WarningId Test_WarningId_V_406 = WRN_ADAS_ACC_31;
  WarningId Test_WarningId_V_407 = WRN_ADAS_ACC_32;
  WarningId Test_WarningId_V_408 = WRN_ADAS_ACC_33;
  WarningId Test_WarningId_V_409 = WRN_ADAS_ACC_34;
  WarningId Test_WarningId_V_410 = WRN_ADAS_ACC_35;
  WarningId Test_WarningId_V_411 = WRN_ADAS_ACC_36;
  WarningId Test_WarningId_V_412 = WRN_ADAS_ACC_37;
  WarningId Test_WarningId_V_413 = WRN_ADAS_ACC_38;
  WarningId Test_WarningId_V_414 = WRN_ADAS_ACC_39;
  WarningId Test_WarningId_V_415 = WRN_ADAS_ACC_40;
  WarningId Test_WarningId_V_416 = WRN_ADAS_ACC_41;
  WarningId Test_WarningId_V_417 = WRN_ADAS_ACC_42;
  WarningId Test_WarningId_V_418 = WRN_ADAS_ACC_43;
  WarningId Test_WarningId_V_419 = WRN_ADAS_ACC_44;
  WarningId Test_WarningId_V_420 = WRN_ADAS_ACC_45;
  WarningId Test_WarningId_V_421 = WRN_ADAS_ACC_46;
  WarningId Test_WarningId_V_422 = WRN_ADAS_ACC_47;
  WarningId Test_WarningId_V_423 = WRN_ADAS_ACC_48;
  WarningId Test_WarningId_V_424 = WRN_ADAS_ACC_49;
  WarningId Test_WarningId_V_425 = WRN_ADAS_ACC_50;
  WarningId Test_WarningId_V_426 = WRN_ADAS_ACC_51;
  WarningId Test_WarningId_V_427 = WRN_ADAS_ACC_52;
  WarningId Test_WarningId_V_428 = WRN_ADAS_ACC_53;
  WarningId Test_WarningId_V_429 = WRN_ADAS_ACC_54;
  WarningId Test_WarningId_V_430 = WRN_ADAS_ACC_55;
  WarningId Test_WarningId_V_431 = WRN_ADAS_ACC_56;
  WarningId Test_WarningId_V_432 = WRN_ADAS_ACC_57;
  WarningId Test_WarningId_V_433 = WRN_NORM_ACC_VM01_GSY07_02;
  WarningId Test_WarningId_V_434 = WRN_NORM_ACC_VM01_GSY07_03;
  WarningId Test_WarningId_V_435 = WRN_NORM_ACC_VM01_GSY07_04;
  WarningId Test_WarningId_V_436 = WRN_NORM_ACC_VM01_GSY07_05;
  WarningId Test_WarningId_V_437 = WRN_NORM_ACC_VM01_GSY07_06;
  WarningId Test_WarningId_V_438 = WRN_NORM_ACC_VM01_GSY07_07;
  WarningId Test_WarningId_V_439 = WRN_NORM_ACC_VM01_GSY07_08;
  WarningId Test_WarningId_V_440 = WRN_NORM_ACC_VM01_GSY07_09;
  WarningId Test_WarningId_V_441 = WRN_NORM_ACC_VM01_EFE02_02;
  WarningId Test_WarningId_V_442 = WRN_NORM_ACC_VM01_EFE02_03;
  WarningId Test_WarningId_V_443 = WRN_NORM_ACC_VM01_EFE02_04;
  WarningId Test_WarningId_V_444 = WRN_NORM_ACC_VM01_EFE02_05;
  WarningId Test_WarningId_V_445 = WRN_NORM_ACC_VM01_EFE01_02;
  WarningId Test_WarningId_V_446 = WRN_NORM_ACC_VM01_EFE01_03;
  WarningId Test_WarningId_V_447 = WRN_NORM_ACC_VM01_EFE01_04;
  WarningId Test_WarningId_V_448 = WRN_NORM_ACC_VM01_EFE01_05;
  WarningId Test_WarningId_V_449 = WRN_NORM_ACC_VM01_GME12_02;
  WarningId Test_WarningId_V_450 = WRN_NORM_ACC_VM01_GME12_03;
  WarningId Test_WarningId_V_451 = WRN_NORM_ACC_VM01_GME12_04;
  WarningId Test_WarningId_V_452 = WRN_NORM_ACC_VM01_GME12_05;
  WarningId Test_WarningId_V_453 = WRN_NORM_ACC_VM01_GME12_06;
  WarningId Test_WarningId_V_454 = WRN_NORM_ACC_VM01_GME12_07;
  WarningId Test_WarningId_V_455 = WRN_NORM_ACC_VM01_GME12_08;
  WarningId Test_WarningId_V_456 = WRN_NORM_ACC_VM01_GME12_09;
  WarningId Test_WarningId_V_457 = WRN_NORM_FCTA_01;
  WarningId Test_WarningId_V_458 = WARN_NORM_GRISHU_02;
  WarningId Test_WarningId_V_459 = WRN_NORM_CHEENG_06;
  WarningId Test_WarningId_V_460 = WRN_NORM_SFTPOSL_02;
  WarningId Test_WarningId_V_461 = WRN_NORM_SFTPOSL_03;
  WarningId Test_WarningId_V_462 = WRN_NORM_SFTPOSL_04;
  WarningId Test_WarningId_V_463 = WRN_NORM_TPMS_02;
  WarningId Test_WarningId_V_464 = WRN_NORM_TPMS_03;
  WarningId Test_WarningId_V_465 = WRN_NORM_STOSTA_02;
  WarningId Test_WarningId_V_466 = WRN_NORM_RSRDI_02;
  WarningId Test_WarningId_V_467 = WRN_NORM_PSSDI_02;
  WarningId Test_WarningId_V_468 = WRN_NORM_UNOVE_02;
  WarningId Test_WarningId_V_469 = WRN_NORM_UNOVE_04;
  WarningId Test_WarningId_V_470 = WRN_CUSTMIZE_PERSET_02;
  WarningId Test_WarningId_V_471 = WRN_CUSTMIZE_PERSET_03;
  WarningId Test_WarningId_V_472 = WRN_CUSTMIZE_PERSET_04;
  WarningId Test_WarningId_V_473 = WRN_CUSTMIZE_PERSET_06;
  WarningId Test_WarningId_V_474 = WRN_CUSTMIZE_PERSET_07;
  WarningId Test_WarningId_V_475 = WRN_CUSTMIZE_PERSET_08;
  WarningId Test_WarningId_V_476 = WRN_CUSTMIZE_PERSET_09;
  WarningId Test_WarningId_V_477 = WRN_CUSTMIZE_PERSET_10;
  WarningId Test_WarningId_V_478 = WRN_CUSTMIZE_PERSET_11;
  WarningId Test_WarningId_V_479 = WRN_CUSTMIZE_PERSET_12;
  WarningId Test_WarningId_V_480 = WRN_CUSTMIZE_PERSET_13;
  WarningId Test_WarningId_V_481 = WRN_CUSTMIZE_PERSET_14;
  WarningId Test_WarningId_V_482 = WRN_CUSTMIZE_PERSET_15;
  WarningId Test_WarningId_V_483 = WRN_CUSTMIZE_PERSET_16;
  WarningId Test_WarningId_V_484 = WRN_CUSTMIZE_PERSET_17;
  WarningId Test_WarningId_V_485 = WRN_CUSTMIZE_PERSET_18;
  WarningId Test_WarningId_V_486 = WRN_CUSTMIZE_PERSET_19;
  WarningId Test_WarningId_V_487 = WRN_CUSTMIZE_PERSET_20;
  WarningId Test_WarningId_V_488 = WRN_CUSTMIZE_PERSET_21;
  WarningId Test_WarningId_V_489 = WRN_CUSTMIZE_PERSET_22;
  WarningId Test_WarningId_V_490 = WRN_CUSTMIZE_PERSET_23;
  WarningId Test_WarningId_V_491 = WRN_CUSTMIZE_PERSET_24;
  WarningId Test_WarningId_V_492 = WRN_NORM_SEA_VM01_02;
  WarningId Test_WarningId_V_493 = WRN_NORM_SEA_VM02_02;
  WarningId Test_WarningId_V_494 = WRN_NORM_PSSDI_03;
  WarningId Test_WarningId_V_495 = WRN_NORM_PSSDI_04;
  WarningId Test_WarningId_V_496 = WRN_NORM_PSSDI_05;
  WarningId Test_WarningId_V_497 = WRN_NORM_PSSDI_06;
  WarningId Test_WarningId_V_498 = WRN_NORM_CLESON_02;
  WarningId Test_WarningId_V_499 = WRN_CUTMIZE_DIGKEY_01;
  WarningId Test_WarningId_V_500 = WRN_NORM_RSRDI_03;
  WarningId Test_WarningId_V_501 = WRN_ADAS_LCA_02;
  WarningId Test_WarningId_V_502 = WRN_NORM_TPMS_VM02_REQ02;
  WarningId Test_WarningId_V_503 = WRN_NORM_TPMS_VM02_REQ03;
  WarningId Test_WarningId_V_504 = WRN_NORM_TPMS_VM02_REQ04;
  WarningId Test_WarningId_V_505 = WRN_NORM_TPMS_VM02_REQ05;
  WarningId Test_WarningId_V_506 = WRN_NORM_TPMS_VM02_REQ06;
  WarningId Test_WarningId_V_507 = WRN_NORM_TPMS_VM02_REQ07;
  WarningId Test_WarningId_V_508 = WRN_NORM_TPMS_VM02_REQ08;
  WarningId Test_WarningId_V_509 = WRN_NORM_TPMS_VM02_REQ09;
  WarningId Test_WarningId_V_510 = WRN_NORM_TPMS_VM02_REQ10;
  WarningId Test_WarningId_V_511 = WRN_NORM_TPMS_VM02_REQ11;
  WarningId Test_WarningId_V_512 = WRN_NORM_TPMS_VM02_GWM08_REQ02;
  WarningId Test_WarningId_V_513 = WRN_NORM_TPMS_VM02_GWM08_REQ01;
  WarningId Test_WarningId_V_514 = WRN_NORM_PSSDI_07;
  WarningId Test_WarningId_V_515 = WRN_NORM_EXWUOC_04;
  WarningId Test_WarningId_V_516 = WRN_NORM_EXWUOC_06;
  WarningId Test_WarningId_V_517 = WRN_NORM_EXWUOC_10;
  WarningId Test_WarningId_V_518 = WRN_NORM_EXWUOC_16;
  WarningId Test_WarningId_V_519 = WRN_NORM_EXWUOC_17;
  WarningId Test_WarningId_V_520 = WRN_NORM_EXWUOC_18;
  WarningId Test_WarningId_V_521 = WRN_NORM_PBD_02;
  WarningId Test_WarningId_V_522 = WRN_NORM_FCTA_02;
  WarningId Test_WarningId_V_523 = WRN_NORM_TMN_02;
  WarningId Test_WarningId_V_524 = WRN_NORM_TMN_03;
  WarningId Test_WarningId_V_525 = WRN_NORM_PEDPRO_03;
  WarningId Test_WarningId_V_526 = WRN_NORM_PEDPRO_04;
  WarningId Test_WarningId_V_527 = WRN_NORM_LEAUNF_02;
  WarningId Test_WarningId_V_528 = WRN_NORM_LEAUNF_04;
  WarningId Test_WarningId_V_529 = WRN_NORM_HCS_02;
  WarningId Test_WarningId_V_530 = WRN_NORM_HCS_03;
  WarningId Test_WarningId_V_531 = WRN_NORM_HCS_04;
  WarningId Test_WarningId_V_532 = WRN_NORM_HCS_05;
  WarningId Test_WarningId_V_533 = WRN_NORM_HCS_06;
  WarningId Test_WarningId_V_534 = WRN_NORM_HCS_07;
  WarningId Test_WarningId_V_535 = WRN_NORM_HCS_08;
  WarningId Test_WarningId_V_536 = WRN_NORM_HCS_09;
  WarningId Test_WarningId_V_537 = WRN_NORM_HCS_10;
  WarningId Test_WarningId_V_538 = WRN_NORM_HCS_11;
  WarningId Test_WarningId_V_539 = WRN_NORM_SCB_02;
  WarningId Test_WarningId_V_540 = WRN_NORM_ITS_02;
  WarningId Test_WarningId_V_541 = WRN_NORM_ITS_06;
  WarningId Test_WarningId_V_542 = WRN_NORM_ITS_MEV01_02;
  WarningId Test_WarningId_V_543 = WRN_NORM_ITS_MEV01_04;
  WarningId Test_WarningId_V_544 = WRN_NORM_ITS_MEV01_05;
  WarningId Test_WarningId_V_545 = WRN_NORM_ITS_MEV01_06;
  WarningId Test_WarningId_V_546 = WRN_NORM_MAPACC_02;
  WarningId Test_WarningId_V_547 = WRN_NORM_OAA_03;
  WarningId Test_WarningId_V_548 = WRN_NORM_OAA_04;
  WarningId Test_WarningId_V_549 = WRN_NORM_LCA_21;
  WarningId Test_WarningId_V_550 = WRN_NORM_LCA_26;
  WarningId Test_WarningId_V_551 = WRN_NORM_LCA_27;
  WarningId Test_WarningId_V_552 = WRN_NORM_LCA_28;
  WarningId Test_WarningId_V_553 = WRN_NORM_LCA_29;
  WarningId Test_WarningId_V_554 = WRN_NORM_LCA_30;
  WarningId Test_WarningId_V_555 = WRN_NORM_LCA_31;
  WarningId Test_WarningId_V_556 = WRN_NORM_NLOCK_02;
  WarningId Test_WarningId_V_557 = WRN_NORM_ATFWRN_02;
  WarningId Test_WarningId_V_558 = WRN_NORM_LTA_04;
  WarningId Test_WarningId_V_559 = WRN_NORM_LTA_05;
  WarningId Test_WarningId_V_560 = WRN_NORM_LTA_06;
  WarningId Test_WarningId_V_561 = WRN_NORM_LTA_08;
  WarningId Test_WarningId_V_562 = WRN_NORM_LTA_09;
  WarningId Test_WarningId_V_563 = WRN_NORM_LTA_10;
  WarningId Test_WarningId_V_564 = WRN_NORM_LTA_11;
  WarningId Test_WarningId_V_565 = WRN_NORM_LTA_12;
  WarningId Test_WarningId_V_566 = WRN_NORM_PCL_02;
  WarningId Test_WarningId_V_567 = WRN_ADAS_LCA_05;
  WarningId Test_WarningId_V_568 = WRN_ADAS_LCA_06;
  WarningId Test_WarningId_V_569 = WRN_ADAS_LCA_07;
  WarningId Test_WarningId_V_570 = WRN_ADAS_LCA_08;
  WarningId Test_WarningId_V_571 = WRN_ADAS_LCA_09;
  WarningId Test_WarningId_V_572 = WRN_ADAS_LCA_10;
  WarningId Test_WarningId_V_573 = WRN_ADAS_LCA_11;
  WarningId Test_WarningId_V_574 = WRN_ADAS_LCA_12;
  WarningId Test_WarningId_V_575 = WRN_NORM_LDA_04;
  WarningId Test_WarningId_V_576 = WRN_NORM_LDA_05;
  WarningId Test_WarningId_V_577 = WRN_ADAS_OAA_01;
  WarningId Test_WarningId_V_578 = WRN_NORM_TPMS_VM02_GWM08_REQ06;
  WarningId Test_WarningId_V_579 = WRN_NORM_TPMS_VM02_GWM08_REQ07;
  WarningId Test_WarningId_V_580 = WRN_ADAS_ACC_G7;
  WarningId Test_WarningId_V_581 = WRN_ADAS_ACC_G11_01;
  WarningId Test_WarningId_V_582 = WRN_ADAS_ACC_G11_02;
  WarningId Test_WarningId_V_583 = WRN_ADAS_ACC_G11_03;
  WarningId Test_WarningId_V_584 = WRN_ADAS_ACC_G20;
  WarningId Test_WarningId_V_585 = WRN_ADAS_ACC_G22;
  WarningId Test_WarningId_V_586 = WRN_ADAS_ACC_G23;
  WarningId Test_WarningId_V_587 = HUD_WRN_NORM_PCS1_05;
  WarningId Test_WarningId_V_588 = HUD_WRN_NORM_PCS1_06;
  WarningId Test_WarningId_V_589 = HUD_WRN_ADAS_ACC_G20;
  WarningId Test_WarningId_V_590 = HUD_WRN_ADAS_ACC_G7;
  WarningId Test_WarningId_V_591 = HUD_WRN_ADAS_ACC_G23;
  WarningId Test_WarningId_V_592 = HUD_WRN_ADAS_ACC_G22;
  WarningId Test_WarningId_V_593 = HUD_WRN_ADAS_LCA_02;
  WarningId Test_WarningId_V_594 = HUD_WRN_NORM_DA_02;
  WarningId Test_WarningId_V_595 = HUD_WRN_NORM_SCB_02;
  WarningId Test_WarningId_V_596 = HUD_WRN_NORM_ITS_MEV01_04;
  WarningId Test_WarningId_V_597 = HUD_WRN_NORM_ITS_MEV01_02;
  WarningId Test_WarningId_V_598 = HUD_WRN_NORM_ITS_02;
  WarningId Test_WarningId_V_599 = HUD_WRN_NORM_BOS_02;
  WarningId Test_WarningId_V_600 = HUD_WRN_NORM_DSC_02;
  WarningId Test_WarningId_V_601 = HUD_WRN_NORM_PMAR_03;
  WarningId Test_WarningId_V_602 = HUD_WRN_ADAS_OAA_01;
  WarningId Test_WarningId_V_603 = HUD_WRN_NORM_ACC_19;
  WarningId Test_WarningId_V_604 = HUD_WRN_NORM_LCA_29;
  WarningId Test_WarningId_V_605 = HUD_WRN_ADAS_LCA_05;
  WarningId Test_WarningId_V_606 = HUD_WRN_ADAS_LCA_06;
  WarningId Test_WarningId_V_607 = HUD_WRN_ADAS_LCA_07;
  WarningId Test_WarningId_V_608 = HUD_WRN_ADAS_LCA_08;
  WarningId Test_WarningId_V_609 = HUD_WRN_ADAS_LCA_09;
  WarningId Test_WarningId_V_610 = HUD_WRN_ADAS_LCA_10;
  WarningId Test_WarningId_V_611 = HUD_WRN_ADAS_LCA_11;
  WarningId Test_WarningId_V_612 = HUD_WRN_ADAS_LCA_12;
  WarningId Test_WarningId_V_613 = HUD_WRN_NORM_RTAN_02;
  WarningId Test_WarningId_V_614 = HUD_WRN_NORM_LDA_02;
  WarningId Test_WarningId_V_615 = HUD_WRN_ADAS_LCA_03;
  WarningId Test_WarningId_V_616 = HUD_WRN_ADAS_LCA_04;
  WarningId Test_WarningId_V_617 = HUD_WRN_NORM_ACC_21;
  WarningId Test_WarningId_V_618 = HUD_WRN_ADAS_ACC_G11_01;
  WarningId Test_WarningId_V_619 = HUD_WRN_ADAS_ACC_G11_02;
  WarningId Test_WarningId_V_620 = HUD_WRN_ADAS_ACC_G11_03;
  WarningId Test_WarningId_V_621 = HUD_WRN_NORM_DSC_04;
  WarningId Test_WarningId_V_622 = WRN_NORM_GROUP1;
  WarningId Test_WarningId_V_623 = WRN_NORM_GROUP2;
  WarningId Test_WarningId_V_624 = WRN_NORM_GROUP3;
  WarningId Test_WarningId_V_625 = WRN_NORM_GROUP4;
  WarningId Test_WarningId_V_626 = WRN_NORM_GROUP5;
  WarningId Test_WarningId_V_627 = WRN_NORM_GROUP6;
  WarningId Test_WarningId_V_628 = WRN_NORM_GROUP7;
  WarningId Test_WarningId_V_629 = WRN_NORM_GROUP8;
  WarningId Test_WarningId_V_630 = WRN_NORM_GROUP9;
  WarningId Test_WarningId_V_631 = TotalNumOfWarnings;

  WarningStatus Test_WarningStatus_V_1 = UI_WARNING_STATUS_OFF;
  WarningStatus Test_WarningStatus_V_2 = UI_WARNING_STATUS_ON;
  WarningStatus Test_WarningStatus_V_3 = UI_WARNING_STATUS_UNKNOWN;

  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_1 = eTxSigConfirmStatus_Cleared;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_2 = eTxSigConfirmStatus_Set;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_3 = eTxSigConfirmStatus_NotSupported;

  tTxSignalId Test_tTxSignalId_V_1 = eSecureTxByte0Out;
  tTxSignalId Test_tTxSignalId_V_2 = eSecureTxByte1Out;
  tTxSignalId Test_tTxSignalId_V_3 = eSecureTxByte2Out;
  tTxSignalId Test_tTxSignalId_V_4 = eSecureTxByte3Out;
  tTxSignalId Test_tTxSignalId_V_5 = eMAC_TxOut;
  tTxSignalId Test_tTxSignalId_V_6 = eFV_TxOut;
  tTxSignalId Test_tTxSignalId_V_7 = eOdometerOut;
  tTxSignalId Test_tTxSignalId_V_8 = eVehicleSpeedICOut;
  tTxSignalId Test_tTxSignalId_V_9 = eIllumination_PWMOut;
  tTxSignalId Test_tTxSignalId_V_10 = eDebug1_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_11 = eDebug1_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_12 = eDebug1_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_13 = eDebug1_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_14 = eDebug1_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_15 = eDebug1_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_16 = eDebug1_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_17 = eDebug1_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_18 = eDebug2_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_19 = eDebug2_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_20 = eDebug2_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_21 = eDebug2_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_22 = eDebug2_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_23 = eDebug2_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_24 = eDebug2_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_25 = eDebug2_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_26 = eDebug3_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_27 = eDebug3_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_28 = eDebug3_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_29 = eDebug3_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_30 = eDebug3_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_31 = eDebug3_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_32 = eDebug3_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_33 = eDebug3_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_34 = eDebug4_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_35 = eDebug4_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_36 = eDebug4_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_37 = eDebug4_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_38 = eDebug4_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_39 = eDebug4_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_40 = eDebug4_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_41 = eDebug4_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_42 = eDebug5_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_43 = eDebug5_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_44 = eDebug5_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_45 = eDebug5_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_46 = eDebug5_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_47 = eDebug5_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_48 = eDebug5_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_49 = eDebug5_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_50 = eEndOfTxSignal;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
