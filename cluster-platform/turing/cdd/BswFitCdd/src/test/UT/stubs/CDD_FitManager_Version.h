
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef FITMANAGERCDD_VERSION_H
#define FITMANAGERCDD_VERSION_H

/*==================[inclusions]============================================*/

#include "CDD_FitManager_Cfg.h"

/*==================[macros]================================================*/

/*==================[Module ID]================================================*/
#if (defined FITMANAGERCDD_MODULE_ID) /* To prevent double declaration */
#error FITMANAGERCDD_MODULE_ID already defined
#endif /* if (defined FITMANAGERCDD_MODULE_ID) */

/** \brief AUTOSAR module identification. */
#define FITMANAGERCDD_MODULE_ID 3002U

#if (defined FITMANAGERCDD_INSTANCE_ID) /* to prevent double declaration */
#error FITMANAGERCDD_INSTANCE_ID already defined
#endif /* if (defined FITMANAGERCDD_INSTANCE_ID) */

/** \brief AUTOSAR module identification. */
#define FITMANAGERCDD_INSTANCE_ID 0u

/*------------------[AUTOSAR module version identification]------------------*/
#if (defined FITMANAGERCDD_SW_MAJOR_VERSION) /* To prevent double declaration */
#error FITMANAGERCDD_SW_MAJOR_VERSION already defined
#endif /* if (defined FITMANAGERCDD_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version. */
#define FITMANAGERCDD_SW_MAJOR_VERSION  1U

#if (defined FITMANAGERCDD_SW_MINOR_VERSION) /* To prevent double declaration */
#error FITMANAGERCDD_SW_MINOR_VERSION already defined
#endif /* if (defined FITMANAGERCDD_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version. */
#define FITMANAGERCDD_SW_MINOR_VERSION  0U

#endif //FITMANAGERCDD_VERSION_H

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_*/

/*==============================================================================================================================================
Date              	: 29-11-23
CDSID             	: rdarshan
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 30-01-24
CDSID             	: rdarshan
Traceability      	: PK3T229419-1468
Change Description	: FITMANAGERCDD_MODULE_ID updated from 3001 to 3002.
================================================================================================================================================*/
