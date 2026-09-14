/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2020. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           CDD_Bswfit_cfg.h
**
** Description:    This file configures the Bswfit cdd
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#ifndef CDD_BSWFIT_CFG_H
#define CDD_BSWFIT_CFG_H
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_
#include "Std_Types.h"
#include "CDD_FitManager_Cfg.h"
#include "CDD_BswFit_UserHandler.h"
#include "CDD_BswFit_Types.h"

//#include "Os_Types_Lcfg.h"
#include "Os_Cfg.h"


#define INTERNAL_FLASH  0x01
#define EXTERNAL_EEPROM 0x02

#pragma clang section data=".SafeDataSegmentStart"
uint8 Safe_asil_data = 0;
#pragma clang section data= ""

#define BSWFIT_MEMORY_HW  EXTERNAL_EEPROM

#if defined(BSWFIT_MEMORY_HW) && (BSWFIT_MEMORY_HW == INTERNAL_FLASH)
#include "Fee.h"
#elif defined(BSWFIT_MEMORY_HW) && (BSWFIT_MEMORY_HW == EXTERNAL_EEPROM)
#include "Ea.h"
#endif

#define	CDD_BSWFIT_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define BSWFIT_SYSTEM_STACK 2u

#define MPU_support 1U
uint16* mpu_fit[MPU_support] = {&Safe_asil_data};

#define CDD_BSWFIT_CFG_ASILALARM_MAX_COUNT    0x03u

CONST(AlarmType, OS_CONST) BswFitCdd_ASIL_AlarmRefs[CDD_BSWFIT_CFG_ASILALARM_MAX_COUNT] =
{
    Rte_Al_TE2_OsTask_SafeBsw_0_10ms,	
	Rte_Al_TE_OsTask_SafeBsw_0_10ms,
	Rte_Al_TE2_OsTask_Diagnostics_0_10ms
};


#define BSWFIT_OS_TASKID_COUNT                OsNumberOfTasks //13
#define BSWFIT_NVM_TOTAL_NUM_OF_NVRAM_BLOCKS  NVM_NUM_OF_BLOCKS+1 //64



extern CONST(MemoryHwConfigType, CDD_FITMANAGER_APPL_CONST)CDD_BswFit_MemoryHwConfigFunc[1];


CONST(MemoryHwConfigType, CDD_FITMANAGER_APPL_CONST)CDD_BswFit_MemoryHwConfigFunc[1] = {
#if defined(BSWFIT_MEMORY_HW) && (BSWFIT_MEMORY_HW == INTERNAL_FLASH)
	{      Fee_Write,	         Fee_GetStatus}
#elif defined(BSWFIT_MEMORY_HW) && (BSWFIT_MEMORY_HW == EXTERNAL_EEPROM)
	{      Ea_Write,	         Ea_GetStatus}
#endif
};

#define	CDD_BSWFIT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

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
Date              : 13/Dec/2023
By                : rswamyga
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/
#endif
