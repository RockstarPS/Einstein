
//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef ECUBATTERYM_VERSION_H
#define ECUBATTERYM_VERSION_H

/*==================[inclusions]============================================*/

#include "EcuBatteryM_Cfg.h"

/*==================[macros]================================================*/

/*==================[Module ID]================================================*/
#if (defined ECUBATTERYM_MODULE_ID) /* To prevent double declaration */
#error ECUBATTERYM_MODULE_ID already defined
#endif /* if (defined ECUBATTERYM_MODULE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUBATTERYM_MODULE_ID 3003U

#if (defined ECUBATTERYM_INSTANCE_ID) /* to prevent double declaration */
#error ECUBATTERYM_INSTANCE_ID already defined
#endif /* if (defined ECUBATTERYM_INSTANCE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUBATTERYM_INSTANCE_ID 0u

/*------------------[AUTOSAR module version identification]------------------*/
#if (defined ECUBATTERYM_SW_MAJOR_VERSION) /* To prevent double declaration */
#error ECUBATTERYM_SW_MAJOR_VERSION already defined
#endif /* if (defined ECUBATTERYM_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version. */
#define ECUBATTERYM_SW_MAJOR_VERSION 1U

#if (defined ECUBATTERYM_SW_MINOR_VERSION) /* To prevent double declaration */
#error ECUBATTERYM_SW_MINOR_VERSION already defined
#endif /* if (defined ECUBATTERYM_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version. */
#define ECUBATTERYM_SW_MINOR_VERSION 0U

#endif // ECUBATTERYM_VERSION_H

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: tgunasek
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
