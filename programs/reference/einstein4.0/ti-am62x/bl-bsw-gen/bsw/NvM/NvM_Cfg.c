/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  NvM_Cfg.c
Module Short Name:  NvM_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_CFG_C
#define NVM_CFG_C
#define RTE_MICROSAR_PIM_EXPORT

#include "Rte_Type.h"
#include "Rte_NvM.h"
#include "NvM_Cfg.h"
#include "SchM_NvM.h"
#include "EcuMExt.h"
#include "Dem.h"
#include "Dem_Cbk.h"
#include "NvMExt_PrivateCfg.h"


#define NVM_CODE_SEC_START
 #include "MemMap.h"

#define NVM_DATA_SEC_START
 #include "MemMap.h"

#define NVM_CONST_SEC_START
 #include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#ifdef __ghs__
#pragma alignvar (8)
#endif

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

extern void NvMExt_MultipleJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);
void NvM_MultiBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_MultipleJobEndNotification(ServiceId, JobResult);
}

void NvM_EnterCriticalSection(void)
{
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

void NvM_ExitCriticalSection(void)
{
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}


#define NVM_CONST_SEC_END
 #include "MemMap.h"

#define NVM_DATA_SEC_END
 #include "MemMap.h"

#define NVM_CODE_SEC_END
 #include "MemMap.h"

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 11-04-2024 19:36:22
****************************************************************/
