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

static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_SetMode( VAR(EcuWakeupM_ModeType, AUTOMATIC) mode);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_EnableWakeup( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_DisableWakeup( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_EnableNotification( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_DisableNotification( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_CheckWakeup( VAR(EcuWakeupM_EcuMWakeupSourceType, AUTOMATIC) WakeupSource);
FUNC_P2CONST(EcuWakeupM_LowlevelDrvFunc_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetGptDrvFctTable(void);


//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


static CONST(EcuWakeupM_LowlevelDrvFuncTbl_t,ECUWAKEUPM_CONST) EcuWakeupM_GptLowlevelDrvFuncTable =
{
    (EcuWakeupM_LowlevelDrvFct_t)     &EcuWakeupM_Gpt_SetMode,  			          /*  Mode change API 			  	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    NULL_PTR,			  			       			  /*  Enable wakeup ISR API 	  	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    NULL_PTR,		                       			  /*  Disable wakeup ISR API 	  	*/
	(EcuWakeupM_LowlevelDrvFct3_t)    NULL_PTR,                  		   			  /*  Check edge detection status 	*/ 
	(EcuWakeupM_LowlevelDrvFct1_t)    &EcuWakeupM_Gpt_EnableWakeup,				   	  /*  Enable wakeup  API 		  	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &EcuWakeupM_Gpt_DisableWakeup,				  /*  Disable wakeup  API 		  	*/
	(EcuWakeupM_LowlevelDrvFct4_t)    &EcuWakeupM_Gpt_CheckWakeup,				  	  /*  Check wakeup status  	  		*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &EcuWakeupM_Gpt_EnableNotification,		      /*  Enable notification  API   	*/
	(EcuWakeupM_LowlevelDrvFct1_t)    &EcuWakeupM_Gpt_DisableNotification		      /*  Disable notification  API  	*/
};

static CONST(EcuWakeupM_LowlevelDrvFunc_t,ECUWAKEUPM_CONST) EcuWakeupM_GptDrvFuncTable =
{
    (EcuWakeupM_ModeType)			  		GPT_MODE_NORMAL,					     	/*  Normal Operating mode      	     */
	(EcuWakeupM_ModeType)			  		GPT_MODE_SLEEP,					         	/*  Sleep Operating mode		  	 */
	(EcuWakeupM_LowlevelDrvFuncTblType)		&EcuWakeupM_GptLowlevelDrvFuncTable			/*  Low level driver service table   */
};

//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================


//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================


//======================================================================================================================
/** \brief EcuWakeupM_GetGptDrvFctTable
 **
 ** This function returns pointer to  low level driver services.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC_P2CONST(EcuWakeupM_LowlevelDrvFunc_t, ECUWAKEUPM_APPL_CONST, ECUWAKEUPM_CODE) EcuWakeupM_GetGptDrvFctTable(void)
{
  return &EcuWakeupM_GptDrvFuncTable;
}


//======================================================================================================================
/** \brief EcuWakeupM_Gpt_SetMode
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_SetMode( VAR(EcuWakeupM_ModeType, AUTOMATIC) mode)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_SetMode(mode); 
#endif 
}

//======================================================================================================================
/** \brief EcuWakeupM_Gpt_EnableWakeup
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_EnableWakeup( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_EnableWakeup(channel); 
#endif 
}


//======================================================================================================================
/** \brief EcuWakeupM_Gpt_DisableWakeup
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_DisableWakeup( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_DisableWakeup(channel); 
#endif 
}

//======================================================================================================================
/** \brief EcuWakeupM_Gpt_EnableNotification
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_EnableNotification( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_EnableNotification(channel); 
#endif 
}


//======================================================================================================================
/** \brief EcuWakeupM_Gpt_DisableNotification
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_DisableNotification( VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_DisableNotification(channel); 
#endif 
}

//======================================================================================================================
/** \brief EcuWakeupM_Gpt_CheckWakeup
 **
 ** This function calls underlying GPT driver service.
 **
 ** \param[in] mode.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Gpt_CheckWakeup( VAR(EcuWakeupM_EcuMWakeupSourceType, AUTOMATIC) WakeupSource)
{

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
	Gpt_CheckWakeup(WakeupSource); 
#endif 
}





/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/






