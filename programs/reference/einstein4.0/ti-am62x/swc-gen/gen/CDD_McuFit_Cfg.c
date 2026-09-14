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
** Name:           CDD_McuFit_Cfg.c
**
** Description:    This file configures the MCU FIT related configuration details
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#ifndef CDD_MCUFIT_CFG_C
#define CDD_MCUFIT_CFG_C
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_
#include "CDD_McuFit_Cfg.h"

#define	CDD_MCUFIT_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

const CDD_McuFit_Ecc_Cfg_type CDD_McuFit_Ecc_Cfg[CDD_MCUFIT_NUM_ECC_CFG] =
{
	{
		0x79140000,         // ecc_addr
		8u,                 // ecc_aggr
		0u,                 // ecc_ramid
		SDL_INJECT_ECC_ERROR_FORCING_2BIT_ONCE,                 // ecc_errortype
	},
	{
		0x4E10000,          // ecc_addr
		21u,                // ecc_aggr
		0u,                 // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0x79100000,         // ecc_addr
		28u,                // ecc_aggr
		0u,                 // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0,                  // ecc_addr
		12u,                // ecc_aggr
		21u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		4,                  // ecc_addr
		12u,                // ecc_aggr
		22u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0x41010000,         // ecc_addr
		12u,                // ecc_aggr
		23u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0x41010004,         // ecc_addr
		12u,                // ecc_aggr
		24u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0x41010008,         // ecc_addr
		12u,                // ecc_aggr
		25u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
	{
		0x4101000C,         // ecc_addr
		12u,                // ecc_aggr
		26u,                // ecc_ramid
		SDL_INJECT_ECC_NO_ERROR,                 // ecc_errortype
	},
};

#define	CDD_MCUFIT_STOP_SEC_VAR_INIT_UNSPECIFIED
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
Date              : 01/Dec/2023
By                : ksankara
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/
#endif
