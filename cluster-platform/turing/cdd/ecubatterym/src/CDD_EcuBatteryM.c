//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
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
#include "Rte_CCDD_EcuBatteryM.h"
#include "EcuBatteryM.h"
#include "CDD_EcuBatteryM.h"
#include "CmpLib.h"


/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(CDD_EcuBatteryM)

//======================================================================================================================
/** \brief CmpInit
 **
 ** This function initializes EcuBatteryM CDD.
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 ** */
//======================================================================================================================
static Std_ReturnType CmpInit( void )
{
	EcuBatteryM_Init();
    return E_OK;
}

//======================================================================================================================
/** \brief CmpDeInit
 **
 ** This function De-initializes EcuBatteryM CDD.
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 ** */
//======================================================================================================================
static Std_ReturnType CmpDeInit( void )
{
	EcuBatteryM_DeInit();
    return E_OK;
}

//======================================================================================================================
/** \brief CmpActivation
 **
 ** This function activates EcuBatteryM CDD.
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 ** */
//======================================================================================================================
static Std_ReturnType CmpActivation( void )
{
    return E_OK;
}


//======================================================================================================================
/** \brief CmpDeActivation
 **
 **
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 ** */
//======================================================================================================================
static Std_ReturnType CmpDeActivation( void )
{
	//reset();
    return E_OK;
}

//======================================================================================================================
/** \brief CmpActive
 **
 ** This function calls EcuBatteryM CDD main function periodically.
 **
 ** \param[in] None.
 **
 ** \return    Not used.
 **      	  
 ** */
//======================================================================================================================
static Std_ReturnType CmpActive( void )
{
	EcuBatteryM_MonitorChannels();
	return E_OK;
}


//======================================================================================================================
/** \brief CmpDiag
 **
 ** This function calls  after entering into Diagnostic state.
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 **      	  
 ** */
//======================================================================================================================
static Std_ReturnType CmpDiag( void )
{
    return E_OK;
}


//======================================================================================================================
/** \brief CmpDiag
 **
 ** Transitional state to clean up after diagnostic state. Component behaviour to be restored.
 **
 ** \param[in] None.
 **
 ** \return    E_OK:           Succeed.
 **			   E_NOT_READY:    In progress. Keeps the component in this state.
 **      	   E_NOT_OK:       Failed
 **      	  
 ** */
//======================================================================================================================
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: tgunasek
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
