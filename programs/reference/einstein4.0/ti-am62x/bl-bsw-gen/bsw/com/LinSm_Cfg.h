#if !defined(LINSM_CFG_H)
#define LINSM_CFG_H
/* ===========================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
**  This is an unpublished work of authorship, which contains trade secrets,
**  created in 2006.  Visteon Corporation owns all rights to this work and
**  intends to maintain it in confidence to preserve its trade secret status.
**  Visteon Corporation reserves the right, under the copyright laws of the
**  United States or those of any other country that may have jurisdiction, to
**  protect this work as an unpublished work, in the event of an inadvertent
**  or deliberate unauthorized publication.  Visteon Corporation also reserves
**  its rights under all copyright laws to protect this work as a published
**  work, when appropriate.  Those having access to this work may not copy it,
**  use it, modify it or disclose the information contained in it without the
**  written authorization of Visteon Corporation.
**
** =========================================================================*/

/* ===========================================================================
**
**  Name:           LinSm_Cfg.h
**  Component:      LINSM
**  Module:         LIN
**  Description:    LINSM parameter configuration file for global constants
**
**  =========================================================================*/
#include "Std_Types.h"
#include "LinSm_Types.h"


/**
  * @brief Select the Numer of LINSm Channels Supported.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 255
  * Applicablity: N/A
  */
#define LINSM_NUMBER_OF_CHANNELS                                    0x01u
/**
  * @brief Select the whether Development Error Report shall be 
  * enabled or disabled.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_ON,STD_OFF
  * Applicablity: N/A
  */
#define LINSM_DEV_ERROR_DETECT                                      STD_ON
/**
  * @brief Select the Schedule Table Count  
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 255
  * Applicablity: N/A
  */
#define LINSM_SCH_CNT                                               0x01u
/**
  * @brief Select the periodic processing time for LINSM Main Function   
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 255
  * Applicablity: N/A
  */
#define LINSM_MAIN_PROCESSING_PERIOD                                0x0Au
/**
  * @brief Select whether to use BSW interfaces   
  * unit : N/A
  * Resolution: N/A
  * Range: STD_OFF,STD_ON
  * Applicablity: N/A
  */
#define LINSM_USE_BSW_INTERFACES_CC                                 STD_OFF
/**
  * @brief Select whether to use COM interfaces   
  * unit : N/A
  * Resolution: N/A
  * Range: STD_OFF,STD_ON
  * Applicablity: N/A
  */
#define LINSM_USE_COM_INTERFACES_CC                                 STD_OFF


/**
  * @brief Select whether to use LinSM Version API   
  * unit : N/A
  * Resolution: N/A
  * Range: STD_OFF,STD_ON
  * Applicablity: N/A
  */
#define LINSM_VERSION_INFO_API                                      STD_ON


/**
  * @brief Set the maximum (LinSMModeRequestRepetitionMax) attempt repetition 
  * for Linif_wakeup call after timeout is expired.
  * 
  * [SWS_LinSM_00304] ⌈If request timout has occurred for LinIf_Wakeup and the maximum retries 
  * (LinSMModeRequestRepetitionMax) have not been reached, the LinIf_Wakeup request will be sent again.
  * unit : N/A
  * Resolution: N/A
  * Range: STD_OFF,STD_ON
  * Applicablity: N/A
  */
#define WAKEUP_ATTEMPT                                              0x01u

#define USE_COMM

/*********************************************************************************************************************
*                                 #! LinSM SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the LinSM configuration software Major version */
#define LINSM_CFG_SW_MAJOR_VERSION                    	   1u
/*! @brief Defines the LinSM configuration software Minor version */
#define LINSM_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the LinSM configuration software Patch version */
#define LINSM_CFG_SW_PATCH_VERSION                          0u

/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by LinSM configuration  */
#define LINSM_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by LinSM configuration  */
#define LINSM_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by LinSM configuration  */
#define LINSM_CFG_AR_RELEASE_REVISION_VERSION               1u

/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/APR/2020
By                : BPANDURA
Traceability      : RTC #724726 #835035 #835036 #835037 #724728
Change Description: Added WAKEUP_ATTEMPT for maximum repition attempt for wakeup.
                    Added LINSM_VERSION_INFO_API to enable the LinSM_GetVersionInfo function.

----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC #
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/


#endif
