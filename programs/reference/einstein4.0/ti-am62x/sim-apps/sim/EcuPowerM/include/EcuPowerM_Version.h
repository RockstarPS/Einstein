
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
#ifndef ECUPOWERM_VERSION_H
#define ECUPOWERM_VERSION_H

/*==================[inclusions]============================================*/

#include "EcuPowerM_Cfg.h"

/*==================[macros]================================================*/

/*==================[Module ID]================================================*/
#if (defined ECUPOWERM_MODULE_ID) /* To prevent double declaration */
#error ECUPOWERM_MODULE_ID already defined
#endif /* if (defined ECUPOWERM_MODULE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUPOWERM_MODULE_ID 3001U

#if (defined ECUPOWERM_INSTANCE_ID) /* to prevent double declaration */
#error ECUPOWERM_INSTANCE_ID already defined
#endif /* if (defined ECUPOWERM_INSTANCE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUPOWERM_INSTANCE_ID 0u

/*------------------[AUTOSAR module version identification]------------------*/
#if (defined ECUPOWERM_SW_MAJOR_VERSION) /* To prevent double declaration */
#error ECUPOWERM_SW_MAJOR_VERSION already defined
#endif /* if (defined ECUPOWERM_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version. */
#define ECUPOWERM_SW_MAJOR_VERSION  1U

#if (defined ECUPOWERM_SW_MINOR_VERSION) /* To prevent double declaration */
#error ECUPOWERM_SW_MINOR_VERSION already defined
#endif /* if (defined ECUPOWERM_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version. */
#define ECUPOWERM_SW_MINOR_VERSION  0U




#endif //ECUPOWERM_VERSION_H

/*==============================================================================================================================================
Date              	: 05-01-24
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
