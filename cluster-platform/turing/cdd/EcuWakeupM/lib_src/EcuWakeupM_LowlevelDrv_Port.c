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


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "EcuWakeupM_LowlevelDrv.h"

//=====================================================================================================================
//  PRE PROCEESSORS
//=====================================================================================================================



//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================


//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================
static CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t,ECUWAKEUPM_CONST) EcuWakeupM_PortDrvFuncTable =
{
	(EcuWakeupM_LowlevelDrvFct2_t)    Port_SetToDioMode,               	/* Change port mode to GPIO */
	(EcuWakeupM_LowlevelDrvFct2_t)    Port_SetToAlternateMode,          /* Change port mode to peripheral function  */
	(EcuWakeupM_PortFuncPtrType_t)    Port_SetPinMode			   		/* Set port pin mode */
};


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================


//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================


//======================================================================================================================
/** \brief EcuWakeupM_GetPortDrvFuncTable
 **
 ** This function returns pointer to  low level driver services.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC_P2CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetPortDrvFuncTable(void)
{
  return &EcuWakeupM_PortDrvFuncTable;
}


/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/






