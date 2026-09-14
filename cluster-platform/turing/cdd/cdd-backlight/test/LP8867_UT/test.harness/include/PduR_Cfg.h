/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file PduR_Cfg.h
*    @ingroup PduR Configuration
*    @brief This is PduR Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the PduR module.
*    Auto generated code in EASHOK at 2020-09-21 17:08:01.541789
********************************************************************************************************************/
#ifndef PDUR_CFG_H
#define PDUR_CFG_H
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define PDUR_CFG_SW_MAJOR_VERSION                               0u
#define PDUR_CFG_SW_MINOR_VERSION                               0u
#define PDUR_CFG_SW_PATCH_VERSION                               2u
/* Autosar Release */
#define PDUR_CFG_AR_RELEASE_MAJOR_VERSION                       4u
#define PDUR_CFG_AR_RELEASE_MINOR_VERSION                       2u
#define PDUR_CFG_AR_RELEASE_REVISION_VERSION                    1u
/*******************************************************************************************************************/
/*  Precompile Configuration                                                                                       */
/*******************************************************************************************************************/

#define PDUR_DEV_ERROR_DETECT                        STD_OFF
#define PDUR_VERSION_INFO_API                        STD_ON
#define PDUR_ZERO_COST_OPERATION                     STD_OFF
#define PDUR_META_DATA_SUPPORT                       STD_OFF
#define PDUR_GATEWAY_ROUTING                         STD_OFF
#define PDUR_TRIGGER_TRANSMIT                        STD_OFF
#define PDUR_ROUTING_PATH_GROUP                      STD_OFF
#define PUDR_TP_ROUTING_ENABLED                      STD_OFF
#define PDUR_TP_BUFFER_TABLE                         STD_OFF
#define PDUR_TX_BUFFER                               STD_OFF
#define PDUR_CANIF_MODULE_SUPPORT                    STD_ON
#define PDUR_COM_MODULE_SUPPORT                      STD_ON
#define PDUR_CANTP_MODULE_SUPPORT                    STD_ON
#define PDUR_DCM_MODULE_SUPPORT                      STD_ON
#define PDUR_NM_MODULE_SUPPORT                       STD_OFF
#define PDUR_LINIF_MODULE_SUPPORT                    STD_ON
#define PDUR_IPDUM_MODULE_SUPPORT                    STD_OFF
#define PDUR_CANNMFIATB_MODULE_SUPPORT               STD_OFF
#define PDUR_CANNM_MODULE_SUPPORT                    STD_OFF
#define PDUR_NUM_OF_ROUTING_PATH_GROUP               0U
/*! @brief Defines the global PDU ID.This should be used by the upper and lower when using PDUR APIs*/
#define PDUR_PDU_HSS2                                                          0U
#define PDUR_PDU_ESS                                                           1U
#define PDUR_PDU_ESL_WHEEL                                                     2U
#define PDUR_PDU_REQUEST_MET_FF                                                3U
#define PDUR_PDU_VSPNE                                                         4U
#define PDUR_PDU_AT                                                            5U
#define PDUR_PDU_ENGTEMP                                                       6U
#define PDUR_PDU_ILLUMI                                                        7U
#define PDUR_PDU_STEERING                                                      8U
#define PDUR_PDU_SRS                                                           9U
#define PDUR_PDU_REPLY_HFL_AUDIO                                               10U
#define PDUR_PDU_PARKSENS2_MET                                                 11U
#define PDUR_PDU_METER_DATA1                                                   12U
#define PDUR_PDU_REPLY_GUIDE_INFO_MET                                          13U
#define PDUR_PDU_REPLY_GUIDE_INFO_DIS                                          14U
#define PDUR_PDU_ODO_TRIP                                                      15U
#define PDUR_PDU_TRICOM1                                                       16U
#define PDUR_PDU_TRICOM2                                                       17U
#define PDUR_PDU_TRICOM3                                                       18U
#define PDUR_PDU_METER_EW4                                                     19U
#define PDUR_PDU_MAINTENANCE                                                   20U
#define PDUR_PDU_METDTC1                                                       21U
#define PDUR_PDU_TRICOM4                                                       22U
#define PDUR_PDU_MET_CUSTOM                                                    23U
#define PDUR_PDU_STEERING_ANGLE                                                24U
#define PDUR_PDU_STEERING2                                                     25U
#define PDUR_PDU_METER_NAVI_RMD                                                26U
#define PDUR_PDU_YAW_GW                                                        27U
#define PDUR_PDU_SEATBELT                                                      28U
#define PDUR_PDU_TRICOM5                                                       29U
#define PDUR_PDU_TRICOM6                                                       30U
#define PDUR_PDU_IND_NORMAL                                                    31U
#define PDUR_PDU_IND_FAIL1                                                     32U
#define PDUR_PDU_IND_FAIL2                                                     33U
#define PDUR_PDU_MID_DISPLAY                                                   34U
#define PDUR_PDU_IDS_COLOR_MODE                                                35U
#define PDUR_PDU_ST_SW_L_INT                                                   36U
#define PDUR_PDU_VEHICLE_REQ                                                   37U
#define PDUR_PDU_MET_TCU2                                                      38U
#define PDUR_PDU_SEATINFO                                                      39U
#define PDUR_PDU_HU_OPERATION_REQ                                              40U
#define PDUR_PDU_METER_GW_1                                                    41U
#define PDUR_PDU_METER_GW_2                                                    42U
#define PDUR_PDU_METER_GW_3                                                    43U
#define PDUR_PDU_METER_GW_4                                                    44U
#define PDUR_PDU_MET_TCU3                                                      45U
#define PDUR_PDU_MET_CUSTOM2                                                   46U
#define PDUR_PDU_CUSTOM_MET_RM                                                 47U
#define PDUR_PDU_CUSTOM_MET_BCM                                                48U
#define PDUR_PDU_CUSTOM_MET_PW                                                 49U
#define PDUR_PDU_CUSTOM_MET_PTG                                                50U
#define PDUR_PDU_CUSTOM_MET_NAV                                                51U
#define PDUR_PDU_CUSTOMCHECK_MET_NAV                                           52U
#define PDUR_PDU_DIAG_MET_RM                                                   53U
#define PDUR_PDU_DIAG_MET_BCM                                                  54U
#define PDUR_PDU_DIAG_MET_PW                                                   55U
#define PDUR_PDU_DIAG_MET_PTG                                                  56U
#define PDUR_PDU_DIAG_MET_ARM                                                  57U
#define PDUR_PDU_DIAG_MET_AC                                                   58U
#define PDUR_PDU_DIAG_MET_AHU                                                  59U
#define PDUR_PDU_DIAG_MET_NAV                                                  60U
#define PDUR_PDU_DIAG_MET_ALT                                                  61U
#define PDUR_PDU_DIAG_MET_RLS                                                  62U
#define PDUR_PDU_DIAG_MET_ALV                                                  63U
#define PDUR_PDU_DIAG_MET_ACL                                                  64U
#define PDUR_PDU_DIAG_MET_LFL                                                  65U
#define PDUR_PDU_DIAG_MET_LFR                                                  66U
#define PDUR_PDU_DIAG_MET_TEL                                                  67U
#define PDUR_PDU_DIAG_MET_BIM                                                  68U
#define PDUR_PDU_DIAG_MET_HCS                                                  69U
#define PDUR_PDU_DIAG_MET_BIS                                                  70U
#define PDUR_PDU_DIAG_MET_WLC                                                  71U
#define PDUR_PDU_DIAG_MET_BTU                                                  72U
#define PDUR_PDU_FAILCHECK_MET_BCM                                             73U
#define PDUR_PDU_FAILCHECK_MET_TEL                                             74U
#define PDUR_PDU_VINNO                                                         75U
#define PDUR_PDU_CHECK2_MET                                                    76U
#define PDUR_PDU_REPRO_MET                                                     77U
#define PDUR_PDU_METER_221                                                     78U
#define PDUR_PDU_METER_296                                                     79U
#define PDUR_PDU_METER_309                                                     80U
#define PDUR_PDU_METER_326                                                     81U
#define PDUR_PDU_METER_374                                                     82U
#define PDUR_PDU_METER_37B                                                     83U
#define PDUR_PDU_METER_396                                                     84U
#define PDUR_PDU_METER_3A1                                                     85U
#define PDUR_PDU_METER_405                                                     86U
#define PDUR_PDU_METER_42E                                                     87U
#define PDUR_PDU_METER_445                                                     88U
#define PDUR_PDU_METER_510                                                     89U
#define PDUR_PDU_METER_516                                                     90U
#define PDUR_PDU_TEST_739                                                      91U
#define PDUR_PDU_TEST_73C                                                      92U
#define PDUR_PDU_TEST_745                                                      93U
#define PDUR_PDU_METER_0CD9AA1B                                                94U
#define PDUR_PDU_METER_0F31AA57                                                95U
#define PDUR_PDU_RESPONSE_0X18DAF260                                           96U
#define PDUR_PDU_RESPONSE_0X18DAF360                                           97U
#define PDUR_PDU_METER_1A45AA51                                                98U
#define PDUR_PDU_REPLY_PHOTO_DATA                                              99U
#define PDUR_PDU_SIZE_DISP_PHOTO                                               100U
#define PDUR_PDU_METER_TO_HU_REQ                                               101U
#define PDUR_PDU_RM_RM                                                         102U
#define PDUR_PDU_HLSW_BCM                                                      103U
#define PDUR_PDU_WIPSW_BCM                                                     104U
#define PDUR_PDU_AUTOWIP_BCM                                                   105U
#define PDUR_PDU_KLDOORLOCK_BCM                                                106U
#define PDUR_PDU_PCUOUT_BCM                                                    107U
#define PDUR_PDU_PCUBUZZ_BCM                                                   108U
#define PDUR_PDU_AUTOLT_BCM                                                    109U
#define PDUR_PDU_AUTOLT_ALT                                                    110U
#define PDUR_PDU_YOPECU_BCM                                                    111U
#define PDUR_PDU_SMARTMIL_BCM                                                  112U
#define PDUR_PDU_BSI_CTM_STATUS                                                113U
#define PDUR_PDU_ACSTATE                                                       114U
#define PDUR_PDU_VK_INFO                                                       115U
#define PDUR_PDU_REQUEST_RM_FF                                                 116U
#define PDUR_PDU_REQUEST_BCM_FF                                                117U
#define PDUR_PDU_REQUEST_PTG_FF                                                118U
#define PDUR_PDU_REQUEST_AC_FF                                                 119U
#define PDUR_PDU_REQUEST_NAV_FF                                                120U
#define PDUR_PDU_REQUEST_ICU_FF                                                121U
#define PDUR_PDU_REQUEST_LFL_FF                                                122U
#define PDUR_PDU_REQUEST_LFR_FF                                                123U
#define PDUR_PDU_REQUEST_TEL_FF                                                124U
#define PDUR_PDU_MICU_BCM                                                      125U
#define PDUR_PDU_RELOCK                                                        126U
#define PDUR_PDU_ACBLOWER_BCM                                                  127U
#define PDUR_PDU_DOORSW_BCM                                                    128U
#define PDUR_PDU_DRLOCKSW_BCM                                                  129U
#define PDUR_PDU_DRLOCKSW_PW                                                   130U
#define PDUR_PDU_ASLOCKSW_PW                                                   131U
#define PDUR_PDU_FOB_ID_BCM                                                    132U
#define PDUR_PDU_ASDOORSW_BCM                                                  133U
#define PDUR_PDU_TRUNKSW_BCM                                                   134U
#define PDUR_PDU_PWSTATUS                                                      135U
#define PDUR_PDU_AC                                                            136U
#define PDUR_PDU_SMARTKEY_BCM                                                  137U
#define PDUR_PDU_IMMOBI_IMO                                                    138U
#define PDUR_PDU_BSI_SYSTEM_STATUS                                             139U
#define PDUR_PDU_HCS                                                           140U
#define PDUR_PDU_HCSSW                                                         141U
#define PDUR_PDU_HFL_STATE                                                     142U
#define PDUR_PDU_MPCTRL_DIALING                                                143U
#define PDUR_PDU_MPDATA_DIALING                                                144U
#define PDUR_PDU_MPCTRL_INCALL                                                 145U
#define PDUR_PDU_MPDATA_INCALL                                                 146U
#define PDUR_PDU_MPCTRL_CHNAME                                                 147U
#define PDUR_PDU_MPDATA_CHNAME                                                 148U
#define PDUR_PDU_ST_SW_FB                                                      149U
#define PDUR_PDU_DM_COOPERATE_INFO_12F91854                                    150U
#define PDUR_PDU_DM_COOPERATE_INFO_12F91855                                    151U
#define PDUR_PDU_DM_COOPERATE_CONT1_12F91B54                                   152U
#define PDUR_PDU_DM_COOPERATE_CONT1_12F91B55                                   153U
#define PDUR_PDU_GUIDE_DISP_DEMAND                                             154U
#define PDUR_PDU_MPCTRL_GUIDE                                                  155U
#define PDUR_PDU_MPDATA_GUIDE                                                  156U
#define PDUR_PDU_MPCTRL_CURRENT                                                157U
#define PDUR_PDU_MPDATA_CURRENT                                                158U
#define PDUR_PDU_IMID_CUSTOM_NAV                                               159U
#define PDUR_PDU_ACLOAD                                                        160U
#define PDUR_PDU_ECL_STATUS                                                    161U
#define PDUR_PDU_IMMOBI_GUIDE_REQ                                              162U
#define PDUR_PDU_IDAS_INFO_NAV                                                 163U
#define PDUR_PDU_ST_AUDIO_CURRENT                                              164U
#define PDUR_PDU_MPCTRL_DEVICENAME                                             165U
#define PDUR_PDU_MPDATA_DEVICENAME                                             166U
#define PDUR_PDU_MPCTRL_ARTISTNAME                                             167U
#define PDUR_PDU_MPDATA_ARTISTNAME                                             168U
#define PDUR_PDU_MPCTRL_FAVORITE_CONT                                          169U
#define PDUR_PDU_MPDATA_FAVORITE_CONT                                          170U
#define PDUR_PDU_MPCTRL_FAVORITES                                              171U
#define PDUR_PDU_MPDATA_FAVORITES                                              172U
#define PDUR_PDU_MPCTRL_HISTORY                                                173U
#define PDUR_PDU_MPDATA_HISTORY                                                174U
#define PDUR_PDU_MPCTRL_RECENT_CALLS                                           175U
#define PDUR_PDU_MPDATA_RECENT_CALLS                                           176U
#define PDUR_PDU_MPCTRL_TRACKNAME                                              177U
#define PDUR_PDU_MPDATA_TRACKNAME                                              178U
#define PDUR_PDU_DA_ILLUMI                                                     179U
#define PDUR_PDU_IMID_CUSTOM_NAV2                                              180U
#define PDUR_PDU_CUSTOM_RM_MET                                                 181U
#define PDUR_PDU_CUSTOM_BCM_MET                                                182U
#define PDUR_PDU_CUSTOM_PW_MET                                                 183U
#define PDUR_PDU_CUSTOM_PTG_MET                                                184U
#define PDUR_PDU_CUSTOM_ARM_MET                                                185U
#define PDUR_PDU_CUSTOM_AHU_MET                                                186U
#define PDUR_PDU_CUSTOM_NAV_METER                                              187U
#define PDUR_PDU_CUSTOMCHECK_RM_MET                                            188U
#define PDUR_PDU_CUSTOMCHECK_BCM_MET                                           189U
#define PDUR_PDU_CUSTOMCHECK_PW_MET                                            190U
#define PDUR_PDU_CUSTOMCHECK_PTG_MET                                           191U
#define PDUR_PDU_CUSTOMCHECK_ARM_MET                                           192U
#define PDUR_PDU_CUSTOMCHECK_ALT_MET                                           193U
#define PDUR_PDU_CUSTOMCHECK_BIM_MET                                           194U
#define PDUR_PDU_DIAG_PTG_ICU                                                  195U
#define PDUR_PDU_DIAG_RM_MET                                                   196U
#define PDUR_PDU_DIAG_BCM_MET                                                  197U
#define PDUR_PDU_DIAG_PW_MET                                                   198U
#define PDUR_PDU_DIAG_PTG_MET                                                  199U
#define PDUR_PDU_DIAG_ARM_MET                                                  200U
#define PDUR_PDU_DIAG_AC_MET                                                   201U
#define PDUR_PDU_DIAG_AHU_MET                                                  202U
#define PDUR_PDU_DIAG_NAV_MET                                                  203U
#define PDUR_PDU_DIAG_ALT_MET                                                  204U
#define PDUR_PDU_DIAG_RLS_MET                                                  205U
#define PDUR_PDU_DIAG_ALV_MET                                                  206U
#define PDUR_PDU_DIAG_LFL_MET                                                  207U
#define PDUR_PDU_DIAG_LFR_MET                                                  208U
#define PDUR_PDU_DIAG_TEL_MET                                                  209U
#define PDUR_PDU_DIAG_YES_MET                                                  210U
#define PDUR_PDU_DIAG_BIM_MET                                                  211U
#define PDUR_PDU_DIAG_HCS_MET                                                  212U
#define PDUR_PDU_DIAG_BIS_MET                                                  213U
#define PDUR_PDU_DIAG_WLC_MET                                                  214U
#define PDUR_PDU_DIAG_BTU_MET                                                  215U
#define PDUR_PDU_DIAG_TEL_LFL                                                  216U
#define PDUR_PDU_FAILCHECK_RM_MET                                              217U
#define PDUR_PDU_FAILCHECK_BCM_MET                                             218U
#define PDUR_PDU_FAILCHECK_PW_MET                                              219U
#define PDUR_PDU_FAILCHECK_PTG_MET                                             220U
#define PDUR_PDU_FAILCHECK_ARM_MET                                             221U
#define PDUR_PDU_FAILCHECK_AC_MET                                              222U
#define PDUR_PDU_FAILCHECK_AHU_MET                                             223U
#define PDUR_PDU_FAILCHECK_NAV_MET                                             224U
#define PDUR_PDU_FAILCHECK_ALT_MET                                             225U
#define PDUR_PDU_FAILCHECK_RLS_MET                                             226U
#define PDUR_PDU_FAILCHECK_ALV_MET                                             227U
#define PDUR_PDU_FAILCHECK_LFL_MET                                             228U
#define PDUR_PDU_FAILCHECK_LFR_MET                                             229U
#define PDUR_PDU_FAILCHECK_TEL_MET                                             230U
#define PDUR_PDU_FAILCHECK_BIM_MET                                             231U
#define PDUR_PDU_FAILCHECK_HCS_MET                                             232U
#define PDUR_PDU_FAILCHECK_BIS_MET                                             233U
#define PDUR_PDU_FAILCHECK_WLC_MET                                             234U
#define PDUR_PDU_FAILCHECK_BTU_MET                                             235U
#define PDUR_PDU_PTG                                                           236U
#define PDUR_PDU_GPSTIME_AHU                                                   237U
#define PDUR_PDU_GPSTIME                                                       238U
#define PDUR_PDU_REPRO_RM                                                      239U
#define PDUR_PDU_REPRO_BCM                                                     240U
#define PDUR_PDU_REPRO_IMG                                                     241U
#define PDUR_PDU_REPRO_APS                                                     242U
#define PDUR_PDU_SRS_039                                                       243U
#define PDUR_PDU_SRS_094                                                       244U
#define PDUR_PDU_EPS_14A                                                       245U
#define PDUR_PDU_EAT_158                                                       246U
#define PDUR_PDU_ENG_17C                                                       247U
#define PDUR_PDU_ESB_183                                                       248U
#define PDUR_PDU_ESB_184                                                       249U
#define PDUR_PDU_TM_1A3                                                        250U
#define PDUR_PDU_VSA_1A4                                                       251U
#define PDUR_PDU_EPS_1AB                                                       252U
#define PDUR_PDU_VSA_1B0                                                       253U
#define PDUR_PDU_EPB_1C2                                                       254U
#define PDUR_PDU_IDASC_1C8                                                     255U
#define PDUR_PDU_VSA_1D0                                                       256U
#define PDUR_PDU_ENG_1DC                                                       257U
#define PDUR_PDU_PARKSR_1E1                                                    258U
#define PDUR_PDU_ENG_1ED                                                       259U
#define PDUR_PDU_ESB_223                                                       260U
#define PDUR_PDU_IMG_22C                                                       261U
#define PDUR_PDU_BATT_22F                                                      262U
#define PDUR_PDU_APS_232                                                       263U
#define PDUR_PDU_VSA_255                                                       264U
#define PDUR_PDU_PARKSR_262                                                    265U
#define PDUR_PDU_SRS_305                                                       266U
#define PDUR_PDU_ACC_30C                                                       267U
#define PDUR_PDU_ACC_310                                                       268U
#define PDUR_PDU_VSA_31B                                                       269U
#define PDUR_PDU_ENG_320                                                       270U
#define PDUR_PDU_ENG_324                                                       271U
#define PDUR_PDU_ENG_328                                                       272U
#define PDUR_PDU_ENG_32F                                                       273U
#define PDUR_PDU_LKAS_33D                                                      274U
#define PDUR_PDU_CHG_33F                                                       275U
#define PDUR_PDU_BATT_340                                                      276U
#define PDUR_PDU_MG_341                                                        277U
#define PDUR_PDU_SBW_358                                                       278U
#define PDUR_PDU_FCM_35E                                                       279U
#define PDUR_PDU_MG_37F                                                        280U
#define PDUR_PDU_ENG_384                                                       281U
#define PDUR_PDU_ENG_388                                                       282U
#define PDUR_PDU_SRS_392                                                       283U
#define PDUR_PDU_MG_395                                                        284U
#define PDUR_PDU_ENG_3D7                                                       285U
#define PDUR_PDU_ENG_40C                                                       286U
#define PDUR_PDU_HVHTR_432                                                     287U
#define PDUR_PDU_ENG_454                                                       288U
#define PDUR_PDU_ENG_459                                                       289U
#define PDUR_PDU_AVAS_45A                                                      290U
#define PDUR_PDU_PCU_45B                                                       291U
#define PDUR_PDU_ENG_467                                                       292U
#define PDUR_PDU_BATT_468                                                      293U
#define PDUR_PDU_BATT_53D                                                      294U
#define PDUR_PDU_TEST_731                                                      295U
#define PDUR_PDU_ADAS_06CD5554                                                 296U
#define PDUR_PDU_AD_06CD5557                                                   297U
#define PDUR_PDU_ICM_0CD9AAC3                                                  298U
#define PDUR_PDU_ADAS_0F31AA54                                                 299U
#define PDUR_PDU_ICM_10E1AA0F                                                  300U
#define PDUR_PDU_REQUEST_0X18DA60F2                                            301U
#define PDUR_PDU_REQUEST_0X18DA60F3                                            302U
#define PDUR_PDU_REQUEST_0X18DBAFF1                                            303U
#define PDUR_PDU_REQUEST_0X18DBAFF2                                            304U
#define PDUR_PDU_REQUEST_0X18DBAFF3                                            305U
#define PDUR_PDU_REQUEST_0X18DBEFF1                                            306U
#define PDUR_PDU_REQUEST_0X18DBEFF2                                            307U
#define PDUR_PDU_REQUEST_0X18DBEFF3                                            308U
#define PDUR_PDU_MPCTRL_JACPHO                                                 309U
#define PDUR_PDU_MPDATA_JACPHO                                                 310U
#define PDUR_PDU_MPCTRL_STLOGO                                                 311U
#define PDUR_PDU_MPDATA_STLOGO                                                 312U
#define PDUR_PDU_MPCTRL_FACEPHO                                                313U
#define PDUR_PDU_MPDATA_FACEPHO                                                314U
#define PDUR_PDU_TP_DIAG_RESPONSE                                              315U
#define PDUR_PDU_TP_DIAG_REQUEST                                               316U
#define PDUR_PDU_METER_TX_37                                                   317U
#define PDUR_PDU_STRG_SW_INFO_25                                               318U
#define PDUR_NUM_OF_PDUS                                                       319U

#define LINIF_STRG_SW_INFO_25       1U
#define DCM_PDU_TP_DIAG_RESPONSE    0U
#define DCM_PDU_TP_DIAG_REQUEST     1U

#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v)
#endif

#endif /* PDUR_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


