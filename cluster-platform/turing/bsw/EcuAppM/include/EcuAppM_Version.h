/*************************************************************************************************************************
*                                                                            											 *
*              CONFIDENTIAL VISTEON CORPORATION                              											 *
*                                                                            											 *
* This is an unpublished work of authorship, which contains trade            											 *
* secrets, created in 2023. Visteon Corporation owns all rights to           											 *
* this work and intends to maintain it in confidence to preserve             											 *
* its trade secret status. Visteon Corporation reserves the right,           											 *
* under the copyright laws of the United States or those of any              											 *
* other country that may have jurisdiction, to protect this work             											 *
* as an unpublished work, in the event of an inadvertent or                  											 *
* deliberate unauthorized publication. Visteon Corporation also              											 *
* reserves its rights under all copyright laws to protect this               											 *
* work as a published work, when appropriate. Those having access            											 *
* to this work may not copy it, use it, modify it or disclose the            											 *
* information contained in it without the written authorization              											 *
* of Visteon Corporation.                                                    											 *
*                                                                            											 *
**************************************************************************************************************************/
#ifndef ECUAPPM_VERSION_H
#define ECUAPPM_VERSION_H

/**************************************************************************************************************************
*  											HEADER FILES INCLUSION												 		  *
***************************************************************************************************************************/

#include "EcuAppM_Cfg.h"

/**************************************************************************************************************************
*  											MACRO DEFINATIONS											 		  		  *
***************************************************************************************************************************/

#if (defined ECUAPPM_MODULE_ID)
#error ECUAPPM_MODULE_ID already defined
#endif /* if (defined ECUAPPM_MODULE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUAPPM_MODULE_ID 4000U

#if (defined ECUAPPM_INSTANCE_ID) /* to prevent double declaration */
#error ECUAPPM_INSTANCE_ID already defined
#endif /* if (defined ECUAPPM_INSTANCE_ID) */

/** \brief AUTOSAR module identification. */
#define ECUAPPM_INSTANCE_ID 0u

/**************************************************************************************************************************
*  											AUTOSAR module version identification										  *
***************************************************************************************************************************/
#if (defined ECUAPPM_SW_MAJOR_VERSION) /* To prevent double declaration */
#error ECUAPPM_SW_MAJOR_VERSION already defined
#endif /* if (defined ECUAPPM_SW_MAJOR_VERSION) */

/** \brief AUTOSAR module major version. */
#define ECUAPPM_SW_MAJOR_VERSION  1U

#if (defined ECUAPPM_SW_MINOR_VERSION) /* To prevent double declaration */
#error ECUAPPM_SW_MINOR_VERSION already defined
#endif /* if (defined ECUAPPM_SW_MINOR_VERSION) */

/** \brief AUTOSAR module minor version. */
#define ECUAPPM_SW_MINOR_VERSION  0U

#endif
/**************************************************************************************************************************
Date              : 22-11-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Version.
***************************************************************************************************************************/
/* End Of File */
