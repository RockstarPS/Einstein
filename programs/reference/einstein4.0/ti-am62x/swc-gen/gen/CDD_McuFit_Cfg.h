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
** Name:           CDD_Mcufit_cfg.h
**
** Description:    This file configures the Mcufit cdd
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#ifndef CDD_MCUFIT_CFG_H
#define CDD_MCUFIT_CFG_H
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#include "Std_Types.h"
#include "CDD_FitManager_Cfg.h"
#include "CDD_McuFit_UserHandler.h"
#include "sdl_ecc.h"


#include "CDD_McuFit_Types.h"

#define	CDD_MCUFIT_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define	CDD_MCUFIT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CDD_MCUFIT_NUM_ECC_CFG                     9u

typedef struct
{
	uint32 ecc_addr;
	uint8  ecc_aggr;
	uint8 ecc_ramid;
	SDL_ECC_InjectErrorType ecc_errortype;
}CDD_McuFit_Ecc_Cfg_type;


extern const CDD_McuFit_Ecc_Cfg_type CDD_McuFit_Ecc_Cfg[CDD_MCUFIT_NUM_ECC_CFG];

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
Date              : 01/Dec/2023
By                : ksankara
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/
#endif
