//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2016] Visteon Corporation
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
#ifndef __ECUWAKEUPM_LOWLEVELDRV_H__
#define __ECUWAKEUPM_LOWLEVELDRV_H__


//----------------------------------------------------------------------------------------------------------------------
// Included files
//----------------------------------------------------------------------------------------------------------------------
#include "EcuWakeupM_Types.h" 
#include "EcuWakeupM_LowlevelDrv_Icu.h"
#include "EcuWakeupM_LowlevelDrv_Gpt.h"
#include "EcuWakeupM_LowlevelDrv_Port.h"



//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------
	   
//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------

/** \brief EcuWakeupM_GetIcuDrvFuncTable
 **
 ** This function provides all the services of the ICU driver to EcuWakeupM.
 **
 ** \param[in] None.
 **
 ** \return   Reference to ICU services
 **
 ** */
extern FUNC_P2CONST(EcuWakeupM_LowlevelDrvFunc_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetIcuDrvFuncTable(void);

/** \brief EcuWakeupM_GetGptDrvFuncTable
 **
 ** This function provides all the services of the GPT driver to EcuWakeupM.
 **
 ** \param[in] None.
 **
 ** \return   Reference to GPT services
 **
 ** */

extern FUNC_P2CONST(EcuWakeupM_LowlevelDrvFunc_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetGptDrvFuncTable(void);


/** \brief EcuWakeupM_GetPortDrvFuncTable
 **
 ** This function provides all the services of the port driver to EcuWakeupM.
 **
 ** \param[in] None.
 **
 ** \return   Reference to GPT services
 **
 ** */

extern FUNC_P2CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetPortDrvFuncTable(void);



#endif  // __ECUWAKEUPM_LOWLEVELDRV_H__

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
