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
static CONST(EcuWakeupM_LowlevelDrvFuncTbl_t,ECUWAKEUPM_CONST) EcuWakeupM_IcuLowlevelDrvFuncTable =
{
    (EcuWakeupM_LowlevelDrvFct_t)     &Icu_SetMode,  			          /*  Mode change API 			 	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_EnableEdgeDetection,			  /*  Enable wakeup ISR API 	 	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_DisableEdgeDetection,		  /*  Disable wakeup ISR API 	 	*/
	(EcuWakeupM_LowlevelDrvFct3_t)    &Icu_GetInputState,                 /*  Check edge detection status	*/ 
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_EnableWakeup,				  /*  Enable wakeup  API 		 	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_DisableWakeup,				  /*  Disable wakeup  API 		 	*/
	(EcuWakeupM_LowlevelDrvFct4_t)    &Icu_CheckWakeup,				  	  /*  Check wakeup status  		 	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_EnableNotification,		      /*  Enable notification  API 	 	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &Icu_DisableNotification		      /*  Disable notification  API  	*/
};

static CONST(EcuWakeupM_LowlevelDrvFunc_t,ECUWAKEUPM_CONST) EcuWakeupM_IcuDrvFuncTable =
{
    (EcuWakeupM_ModeType)			  		ICU_MODE_NORMAL,					  		/*  Normal Operating mode      		*/
	(EcuWakeupM_ModeType)			  		ICU_MODE_SLEEP,					  			/*  Sleep Operating mode		 	*/
	(EcuWakeupM_LowlevelDrvFuncTblType)		&EcuWakeupM_IcuLowlevelDrvFuncTable			/*  Low level driver service table  */

};


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================


//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================


//======================================================================================================================
/** \brief EcuWakeupM_GetIcuDrvFctTable
 **
 ** This function returns pointer to  low level driver services.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC_P2CONST(EcuWakeupM_LowlevelDrvFunc_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetIcuDrvFuncTable(void)
{
  return &EcuWakeupM_IcuDrvFuncTable;
}


/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/






