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
*    @file CanIf_Cfg.h
*    @ingroup CanIf Configuration
*    @brief This is CanIf Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the CanIf module.
*    Auto generated code in SVENKA24 at 2025-04-10 20:04:57.421220
********************************************************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

#include "SchM_CanIf.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define CANIF_CFG_SW_MAJOR_VERSION                       0u
#define CANIF_CFG_SW_MINOR_VERSION                       0u
#define CANIF_CFG_SW_PATCH_VERSION                       2u
/* Autosar Release */
#define CANIF_CFG_AR_RELEASE_MAJOR_VERSION               4u
#define CANIF_CFG_AR_RELEASE_MINOR_VERSION               2u
#define CANIF_CFG_AR_RELEASE_REVISION_VERSION            1u
/*******************************************************************************************************************/ 
/*  Precompile Configuration                                                                                       */ 
/*******************************************************************************************************************/ 
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION                     STD_ON
#define CANIF_PUBLIC_TXCONFIRM_POLLING                           STD_OFF
#define CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API                 STD_OFF
#define CANIF_RXPDU_READ_NOTIFYSTATUS                            STD_OFF
#define CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API                 STD_OFF
#define CANIF_TXPDU_READ_NOTIFYSTATUS                            STD_OFF
#define CANIF_RX_PDU_RANGE_SUPPORT                               STD_ON
#define CANIF_PUBLIC_PN_FILTER_SUPPORT                           STD_OFF
#define CANIF_TRCV_HANDLING                                      STD_ON
#define CANIF_EXTENDEDID_SUPPORT                                 STD_ON
#define CANIF_PUBLIC_READRXPDU_DATA_API                          STD_OFF
#define CANIF_PRIVATE_DLC_CHECK                                  STD_OFF
#define CANIF_FIXED_BUFFER                                       STD_OFF
#define CANIF_SUPPORT_TTCAN                                      STD_OFF
#define CANIF_META_DATA_SUPPORT                                  STD_OFF
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT                     STD_OFF
#define CANIF_PUBLIC_ICOM_SUPPORT                                STD_OFF
#define CANIF_PUBLIC_DEV_ERROR_DETECT                            STD_ON
#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                        STD_OFF
#define CANIF_PUBLIC_PN_SUPPORT                                  STD_OFF
#define CANIF_PUBLIC_READ_RX_PDU_DATA_API                        STD_OFF
#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API               STD_OFF
#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API               STD_OFF
#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API                       STD_OFF
#define CANIF_PUBLIC_TX_BUFFERING                                STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT                  STD_OFF
#define CANIF_PUBLIC_VERSION_INFO_API                            STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM                    STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT                  STD_OFF
#define CANIF_SET_BAUD_RATE_API                                  STD_OFF
#define CANIF_TRIGGER_TRANSMIT_SUPPORT                           STD_OFF
#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT                          STD_OFF
#define CANIF_WAKEUP_SUPPORT                                     STD_ON
#define CANIF_CFG_RX_MAXVALIDRXDLC                               8U
#define CANIF_CFG_TX_MAXVALIDTXDLC                               8U
#define CANIF_CFG_MAX_WAKEUPSOURCES                              1U
#define CANIF_MAX_TX_QUEUE_SIZE                                  1U
#define CANIF_MAX_RX_BUFFER_SIZE                                 1U
#define CANIF_MAX_TX_BUFFER_SIZE                                 1U
#define CANIF_NUM_OF_TXBUFFER                                    1U
/*! @brief  Defines the software filter mechanism as Linear Filter method */  
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR       0U                    
/*! @brief  Defines the software filter mechanism as Binary Filter method */  
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY       1U                    
/*! @brief  Defines the software filter mechanism as Index Filter method */   
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX        2U                    
/*! @brief  Defines the software filter mechanism as Table Filter method */   
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE        3U                    
/*! @brief Selects the desired software filter mechanism for reception. */    
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE              CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR
/*! @brief Defines the type of the Can_HwHandleType as uint8. */
#define CANIF_PUBLIC_HANDLE_TYPE_UINT8                  0U
/*! @brief Defines the type of the Can_HwHandleType as uint16*/
#define CANIF_PUBLIC_HANDLE_TYPE_UINT16                 1U
/*! @brief Defines the type of the Can_HwHandleType.
    For CAN hardware units with more than 255 HW objects the extended range shall be used (UINT16). */
#define CANIF_PUBLIC_HANDLE_TYPE_ENUM                   CANIF_PUBLIC_HANDLE_TYPE_UINT8
#define CANIF_NUM_OF_TX_DYNAMIC_PDU                     1U
#define CANIF_NUM_OF_MAILBOX                            52U
#define CANIF_NUM_OF_RX_NOTIFICATION_FUNCTION           3U
#define CANIF_NUM_OF_TX_CONFIRMATION_FUNCTION           3U
#define CANIF_NUM_OF_TX_TRIGGER_TRANSMIT                3U
#define CANIF_NUM_OF_CAN_CONTROLLERS                    2U
#define CANIF_NM_RX_PDUID                               2U
#define CANIF_NUM_OF_CAN_TRANSCEIVERS                   2U
#define CANIF_NUM_OF_CAN_DRIVERS                        1U
#define CANIF_NUM_OF_TRANSCEIVER_DRIVERS                2U
#define CANIF_NO_CAN_TRANSCEIVER_ID                     CANIF_NUM_OF_CAN_TRANSCEIVERS
#define CANIF_NO_CAN_CONTROLLER_ID                      CANIF_NUM_OF_CAN_CONTROLLERS


#define CanIf_EnterCriticalSection()                 SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0()
#define CanIf_ExitCriticalSection()                  SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0()

#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(param)				((void)(param))
#endif 


/*! @brief Defines the CanIf Transmit PDU IDs */
#define CANIF_PDU_CLU18                       0U
#define CANIF_PDU_CLU21                       1U
#define CANIF_PDU_CLU25                       2U
#define CANIF_PDU_CLU20                       3U
#define CANIF_PDU_CLU19                       4U
#define CANIF_PDU_CLU11                       5U
#define CANIF_PDU_CLU13                       6U
#define CANIF_PDU_CLU14                       7U
#define CANIF_PDU_CLU16                       8U
#define CANIF_PDU_CLU15                       9U
#define CANIF_PDU_CLU12                       10U
#define CANIF_PDU_CLU22                       11U
#define CANIF_PDU_CLU17                       12U
#define CANIF_PDU_DIAG_RSP                    13U
#define CANIF_PDU_CLU_HU_E_00                 14U
#define CANIF_PDU_CLU_HU_PE_00                15U
#define CANIF_PDU_CLU_HU_PE_03                16U
#define CANIF_PDU_CLU_AMP_PE_01               17U
#define CANIF_PDU_CLU_HU_PE_05                18U
#define CANIF_PDU_CLU_HU_PE_06                19U
#define CANIF_PDU_CLU_HU_PE_07                20U
#define CANIF_PDU_CLU_HU_PE_02                21U
#define CANIF_PDU_CLU_HU_PE_01                22U
#define CANIF_PDU_CLU_AMP_PE_02               23U
#define CANIF_PDU_NM_CLU                      24U
#define CANIF_PDU_TP_CLU_HFNO_HU              25U
#define CANIF_PDU_TP_CLU_NAVI_HU              26U
#define CANIF_PDU_TP_CLU_INTERNET_NEWS_HU     27U
#define CANIF_PDU_TP_CLU_USB_HU               28U
#define CANIF_PDU_TP_CLU_NATURE_HU            29U
#define CANIF_PDU_TP_CLU_XM_HU                30U
#define CANIF_PDU_TP_CLU_DAB_HU               31U
#define CANIF_PDU_TP_CLU_TBT_HU               32U
#define CANIF_PDU_TP_CLU_STREAMING_HU         33U
#define CANIF_PDU_TP_CLU_NAVI_LANE_HU         34U
#define CANIF_PDU_TP_CLU_FM_HU                35U
#define CANIF_PDU_TP_CLU_CARPLAY_HU           36U
#define CANIF_PDU_TP_CLU_ANDAUTO_HU           37U
#define CANIF_PDU_TP_CLU_BTSONG_HU            38U
#define CANIF_PDU_TP_CLU_HFNAME_HU            39U
#define CANIF_PDU_TP_CLU_ISDBT_HU             40U
#define CANIF_PDU_TP_CLU_WEATHER_HU           41U
#define CANIF_PDU_CLU_HU_P_06                 42U
#define CANIF_NUM_OF_TX_PDU                   43U


/*! @brief Defines the CanIf Receive PDU IDs */
#define CANIF_PDU_DATC13                         0U
#define CANIF_PDU_DATC11                         1U
#define CANIF_PDU_CGW5                           2U
#define CANIF_PDU_YRS12                          3U
#define CANIF_PDU_TCU_DCT13                      4U
#define CANIF_PDU_CGW_PC11                       5U
#define CANIF_PDU_EMS16                          6U
#define CANIF_PDU_SAS11_FS                       7U
#define CANIF_PDU_CGW_PC15                       8U
#define CANIF_PDU_EMS12                          9U
#define CANIF_PDU_LKA11_FS                       10U
#define CANIF_PDU_CGW_PC8                        11U
#define CANIF_PDU_ADAS_PRK_10_20MS               12U
#define CANIF_PDU_CGW_PC4                        13U
#define CANIF_PDU_CGW_PC5                        14U
#define CANIF_PDU_CGW_PC6                        15U
#define CANIF_PDU_MDPS11_FS                      16U
#define CANIF_PDU_WHL_SPD11                      17U
#define CANIF_PDU_SCC14                          18U
#define CANIF_PDU_ABS11                          19U
#define CANIF_PDU_FCA11_FS                       20U
#define CANIF_PDU_PA11_FS                        21U
#define CANIF_PDU_CGW12                          22U
#define CANIF_PDU_SVM_HU_PE_02                   23U
#define CANIF_PDU_CGW_USM1                       24U
#define CANIF_PDU_CGW_USM2                       25U
#define CANIF_PDU_CGW_USM3                       26U
#define CANIF_PDU_SCC11                          27U
#define CANIF_PDU_SCC12                          28U
#define CANIF_PDU_A4WD11                         29U
#define CANIF_PDU_LKA16                          30U
#define CANIF_PDU_PDW11                          31U
#define CANIF_PDU_EMS_CNG11                      32U
#define CANIF_PDU_CTM2                           33U
#define CANIF_PDU_CGW_PC14                       34U
#define CANIF_PDU_CGW_PC1                        35U
#define CANIF_PDU_ADAS_PRK_USM1                  36U
#define CANIF_PDU_CGW10                          37U
#define CANIF_PDU_ESP14                          38U
#define CANIF_PDU_P_STS                          39U
#define CANIF_PDU_CGW_IBS2                       40U
#define CANIF_PDU_FCA12                          41U
#define CANIF_PDU_HDA11_FS                       42U
#define CANIF_PDU_BCA11                          43U
#define CANIF_PDU_BCW12                          44U
#define CANIF_PDU_EPB11                          45U
#define CANIF_PDU_EMS19                          46U
#define CANIF_PDU_TPMS12                         47U
#define CANIF_PDU_CGW8                           48U
#define CANIF_PDU_AVM_CLU_PE_00                  49U
#define CANIF_PDU_CGW_PC12                       50U
#define CANIF_PDU_CGW7                           51U
#define CANIF_PDU_LKA13                          52U
#define CANIF_PDU_PA12                           53U
#define CANIF_PDU_ACU14                          54U
#define CANIF_PDU_TCS15                          55U
#define CANIF_PDU_SCC13                          56U
#define CANIF_PDU_CGW6                           57U
#define CANIF_PDU_CGW3                           58U
#define CANIF_PDU_CGW_USM6                       59U
#define CANIF_PDU_LKA12                          60U
#define CANIF_PDU_CGW_USM7                       61U
#define CANIF_PDU_CGW1                           62U
#define CANIF_PDU_CGW2                           63U
#define CANIF_PDU_CGW4                           64U
#define CANIF_PDU_AVM_HU_PE_00                   65U
#define CANIF_PDU_HUD11                          66U
#define CANIF_PDU_LKA17                          67U
#define CANIF_PDU_CGW_PC2                        68U
#define CANIF_PDU_CGW_PC3                        69U
#define CANIF_PDU_EVP11                          70U
#define CANIF_PDU_BCW11                          71U
#define CANIF_PDU_TPMS11                         72U
#define CANIF_PDU_CGW_USM4                       73U
#define CANIF_PDU_CGW11                          74U
#define CANIF_PDU_EMS21                          75U
#define CANIF_PDU_CGW_PC7                        76U
#define CANIF_PDU_SOUNDTEST                      77U
#define CANIF_PDU_DIAG_RQST                      78U
#define CANIF_PDU_FUN_DIAG_RQST                  79U
#define CANIF_PDU_HU_AVM_E_01                    80U
#define CANIF_PDU_HU_AVM_E_00                    81U
#define CANIF_PDU_HU_DATC_E_02                   82U
#define CANIF_PDU_HU_DATC_E_03                   83U
#define CANIF_PDU_HU_CNTL_E_01                   84U
#define CANIF_PDU_HU_RVM_E_00                    85U
#define CANIF_PDU_HU_USM_E_01                    86U
#define CANIF_PDU_HU_USM_E_02                    87U
#define CANIF_PDU_HU_USM_E_04                    88U
#define CANIF_PDU_HU_USM_E_05                    89U
#define CANIF_PDU_HU_USM_E_06                    90U
#define CANIF_PDU_HU_USM_E_07                    91U
#define CANIF_PDU_HU_USM_E_12                    92U
#define CANIF_PDU_HU_NAVI_V2_3_META_E            93U
#define CANIF_PDU_HU_NAVI_V2_3_SEG_E             94U
#define CANIF_PDU_HU_NAVI_V2_3_PROSHORT_E_00     95U
#define CANIF_PDU_HU_NAVI_V2_3_PROLONG_E         96U
#define CANIF_PDU_HU_USM_E_08                    97U
#define CANIF_PDU_HU_USM_E_09                    98U
#define CANIF_PDU_HU_NAVI_THEME_E_01             99U
#define CANIF_PDU_HU_TMU_E_02                    100U
#define CANIF_PDU_HU_MON_PE_01                   101U
#define CANIF_PDU_HU_CLU_PE_02                   102U
#define CANIF_PDU_HU_CLU_PE_10                   103U
#define CANIF_PDU_HU_CLU_PE_06                   104U
#define CANIF_PDU_HU_CLU_PE_07                   105U
#define CANIF_PDU_HU_CLOCK_PE_02                 106U
#define CANIF_PDU_DATC_PE_06                     107U
#define CANIF_PDU_ECALL_CLU_PE_01                108U
#define CANIF_PDU_GW_CARINFO_PE                  109U
#define CANIF_PDU_HU_CAR_PE_01                   110U
#define CANIF_PDU_HU_GW_PE_01                    111U
#define CANIF_PDU_GW_USM_PE_01                   112U
#define CANIF_PDU_GW_USM_PE_02                   113U
#define CANIF_PDU_AMP_HU_PE_01                   114U
#define CANIF_PDU_HU_CLU_PE_03                   115U
#define CANIF_PDU_HU_CLU_PE_04                   116U
#define CANIF_PDU_HU_CLU_PE_05                   117U
#define CANIF_PDU_HU_DATC_PE_00                  118U
#define CANIF_PDU_HU_NAVI_V2_3_POS_PE            119U
#define CANIF_PDU_HU_NAVI_PE_00                  120U
#define CANIF_PDU_HU_CLU_PE_11                   121U
#define CANIF_PDU_HU_CLU_PE_13                   122U
#define CANIF_PDU_HU_CLU_PE_14                   123U
#define CANIF_PDU_GW_DDM_PE                      124U
#define CANIF_PDU_HU_USM_E_10                    125U
#define CANIF_PDU_HU_USM_E_11                    126U
#define CANIF_PDU_HU_CLU_USM_E_01                127U
#define CANIF_PDU_HU_CLU_P_04                    128U
#define CANIF_PDU_HU_CLU_PE_15                   129U
#define CANIF_PDU_NM_H_U                         130U
#define CANIF_PDU_NM_AMP                         131U
#define CANIF_PDU_NM_TMU                         132U
#define CANIF_PDU_NM_EDT                         133U
#define CANIF_PDU_NM_CGW                         134U
#define CANIF_PDU_TP_HU_HFNO_CLU                 135U
#define CANIF_PDU_TP_HU_USB_CLU                  136U
#define CANIF_PDU_TP_HU_INTERNET_NEWS_CLU        137U
#define CANIF_PDU_TP_HU_NAVI_CLU                 138U
#define CANIF_PDU_TP_HU_NATURE_CLU               139U
#define CANIF_PDU_TP_HU_DAB_CLU                  140U
#define CANIF_PDU_TP_HU_TBT_CLU                  141U
#define CANIF_PDU_TP_HU_STREAMING_CLU            142U
#define CANIF_PDU_TP_HU_NAVI_LANE_CLU            143U
#define CANIF_PDU_TP_HU_FM_CLU                   144U
#define CANIF_PDU_TP_HU_CARPLAY_CLU              145U
#define CANIF_PDU_TP_HU_ANDAUTO_CLU              146U
#define CANIF_PDU_TP_HU_BTSONG_CLU               147U
#define CANIF_PDU_TP_HU_HFNAME_CLU               148U
#define CANIF_PDU_TP_HU_WEATHER_CLU              149U
#define CANIF_PDU_HU_AMP_P_01                    150U
#define CANIF_PDU_HU_CLU_P_03                    151U
#define CANIF_PDU_HU_NAVI_P_02                   152U
#define CANIF_PDU_AMP_HU_P_01                    153U
#define CANIF_NUM_OF_RX_PDU                      154U


#endif /* CANIF_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


