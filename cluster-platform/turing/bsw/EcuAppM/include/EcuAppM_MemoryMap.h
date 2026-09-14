/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  EcuAppM_MemoryMap.h                                  *
*  Module Short Name :  EcuAppM_MemoryMap                                    *
*  Description       :  This file contains declations of the Autosar ECUAPP  *
*                       Manager Memory Map declarations                      *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Indpendent                                    *
*                                                                            *
******************************************************************************/
#ifndef __ECUAPPM_MEMORYMAP_H_
#define __ECUAPPM_MEMORYMAP_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                           Type Declarations                          		 *
******************************************************************************/

#ifdef EcuAppM_START_SEC_CODE
#undef EcuAppM_START_SEC_CODE
#define ECUAPPM_VAR
#include "MemMap.h"
#endif

#ifdef EcuAppM_START_SEC_CODE
#undef EcuAppM_START_SEC_CODE
#define ECUAPPM_CODE
#include "MemMap.h"
#endif

#ifdef EcuAppM_START_SEC_CODE
#undef EcuAppM_START_SEC_CODE
#define ECUAPPM_ERRORHANDLER_CODE
#include "MemMap.h"
#endif

#endif
/*****************************************************************************
	Date              	: 20-11-23
	CDSID             	: akappa
    Traceability      	:
    Change Description	: Initial Version.
******************************************************************************/
/* End Of File */
