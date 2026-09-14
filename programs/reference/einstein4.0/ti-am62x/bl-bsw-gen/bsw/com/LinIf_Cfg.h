/****************************************************************
*              CONFIDENTIAL VISTEON CORPORATION
*
* This is an unpublished work of authorship, which contains trade secrets,
* created in 2012. Visteon Corporation owns all rights to this work and
* intends to maintain it in confidence to preserve its trade secret status.
* Visteon Corporation reserves the right, under the copyright laws of the
* United States or those of any other country that may have  jurisdiction,
* to protect this work as an unpublished work, in the event of an
* inadvertent or deliberate unauthorized publication. Visteon Corporation
* also reserves its rights under all copyright laws to protect this work as
* a published work, when appropriate. Those having access to this work may
* not copy it, use it, modify it or disclose the information contained in
* it without the written authorization of Visteon Corporation
*
****************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H


#include "Lin_Cfg.h"

/*****************************************************************************
* File Name         :  LinIf_Cfg.h                                           *
* Module Short Name :  LinIf                                                 *
* Description       :  contains the generic feature enable/ disable          *
*                      macros of the  LinIf component                        *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/

/**
  * @brief  Select the development Error Detection.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define LINIF_DEV_ERROR_DETECT       STD_OFF

 /**
  * @brief  Select the Multiple driver support.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_MULTIPLE_DRIVER_SUPPORTED     STD_OFF  

 /**
  * @brief  Select the Transceiver driver support.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_TRANCEIVER_DRIVER_SUPPORTED     STD_ON  


 /**
  * @brief  Select the Multiple Transceiver driver support.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_MULTIPLETRANCEIVER_DRIVER_SUPPORTED     STD_OFF  


 /**
  * @brief  Select the Cancel transmit support.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIFCANCELTRANSMITSUPPORTED     STD_OFF  


 /**
  * @brief  Select the TP support.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_TP_SUPPORTED     STD_OFF    


 /**
  * @brief  Select the get version information api .
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_VERSION_INFO_API    STD_OFF 


 /**
  * @brief  Select the node configuration optional request support .
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define  LINIF_NODECFG_OPTIONAL_REQ_SUPPORT    STD_OFF  


/**
  * @brief  Select the number of Lin channels.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 255
  * Applicablity: N/A
  */
#define LINIF_NUMBER_OF_CHANNELS     0x01U
/**
  * @brief Select the Numer of Schedule Table count.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 255
  * Applicablity: N/A
  */
#define LINIF_SCH_CNT                0x02U


/**
  * @brief Select the Lin driver Channel Wakeup Support.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_LIN_CHANNEL_WAKEUP_SUPPORT    STD_OFF//Lin_LinChannel_0_PC.u8LinChannelWakeupSupport

/**
  * @brief Select the Lin Transceiver Channel Wakeup Support.
  * unit : N/A
  * Resolution: N/A
  * Range:  N/A
  * Applicablity: N/A
  */

#define LINIF_LINTRCV_WAKEUP_SUPPORT    LINTRCV_WAKEUPSUPPORT


 /**
  * @brief Select the Event triggered frame support.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_EVT_FRM_SUPPORTED  STD_ON

 /**
  * @brief Select the Sporadic frame support.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_SPORADIC_FRAME_SUPPORT  STD_ON

 /**
  * @brief Define the Null schedule index as zero.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_NULL_SCHEDULE_INDEX  0x00U

 /**
  * @brief Define the Application schedule index as zero.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_APP_SCHEDULE_INDEX  0x01U


 /**
  * @brief Define the Number of sporadic frame.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_NUMBER_OF_SPORADIC_FRAME    0x03U

/**
  * @brief Define the Collison schedule index.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LINIF_COLLISON_SCHEDULE_INDEX  0x02U

/**
  * @brief Define the Total number of unconditional frame.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define TOTAL_NO_OF_UNCONDITIONAL_FRAME  0x03U

/**
  * @brief Define the  txpdu ID of Lin IPC A.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LinIfConf_LinIfTxPdu_FT_LIN_IPC_A_c348e776    0x00U

/**
  * @brief Define the  txpdu ID of Lin IPC B.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LinIfConf_LinIfTxPdu_FT_LIN_IPC_B_c348e776    0x01U

/**
  * @brief Define the  txpdu ID of Lin IPC C.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LinIfConf_LinIfTxPdu_FT_LIN_IPC_C_c348e776	  0x02U

/**
  * @brief Define the  txpdu ID of Lin IPC D.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LinIfConf_LinIfTxPdu_FT_LIN_IPC_D_c348e776    0x03U

/*********************************************************************************************************************
*                                 #! LinIf SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the LinIf configuration software Major version */
#define LINIF_CFG_SW_MAJOR_VERSION                    	  1u
/*! @brief Defines the LinIf configuration software Minor version */
#define LINIF_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the LinIf configuration software Patch version */
#define LINIF_CFG_SW_PATCH_VERSION                          0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by LinIf configuration  */
#define LINIF_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by LinIf configuration  */
#define LINIF_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by LinIf configuration  */
#define LINIF_CFG_AR_RELEASE_REVISION_VERSION               1u

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================

**============================================================================
**Date               : 24-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update number of Sporadic frame, unconditional frame
                        and schedule table index, and support of frame types 
**============================================================================
**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update Lin General Configuration for User Configuration
                        Added a Lin Driver channel and Transceiver Wake up Support Configuration
**============================================================================
**============================================================================
**Date               : 04-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1352138  
**Change Description : 1. Added descriptions for Configuration tables.
**============================================================================
**============================================================================
**Date               : 26-July-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : Initial Version.
**============================================================================*/

#endif /* LINIF_CFG_H */
