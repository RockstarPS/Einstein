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
#ifndef LINTRCVCDD_CFG_H
#define LINTRCVCDD_CFG_H

#include "Std_Types.h"

/*********************************************************************************************************************
*                                 #! LinTrcv SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the LinTrcv configuration software Major version */
#define LINTRCV_CFG_SW_MAJOR_VERSION                    	   1u
/*! @brief Defines the LinTrcv configuration software Minor version */
#define LINTRCV_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the LinTrcv configuration software Patch version */
#define LINTRCV_CFG_SW_PATCH_VERSION                          0u

/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by LinTrcv configuration  */
#define LINTRCV_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by LinTrcv configuration  */
#define LINTRCV_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by LinTrcv configuration  */
#define LINTRCV_CFG_AR_RELEASE_REVISION_VERSION               1u

/*=============================================================================
*   M A C R O   C O N F I G
**==========================================================================*/
#define LINTRCV_DEV_ERROR_DETECT                       STD_OFF
#define LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL            STD_OFF
#define LINTRCV_DEV_ERROR_REPORT                       STD_OFF
#define LINTRCV_ICUCHANNELIDOFCHANNEL                  STD_OFF
#define LINTRCV_USE_INIT_POINTER                       STD_OFF
#define LINTRCV_WAKEUPSUPPORT                          STD_OFF
#define LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL            STD_OFF
#define LINTRCV_WAKEUPBYBUSUSEDOFCHANNEL               STD_OFF
#define LINTRCV_WAKEUPBYPINUSEDOFCHANNEL               STD_OFF
#define NO_OF_LIN_CHANNEL_USED        1

#endif
/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/
