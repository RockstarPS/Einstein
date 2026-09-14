/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2022. Visteon Corporation owns all rights to           *
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
/******************************************************************************/
/**
 * @file            Dcm_App.c
 * @brief           Dcm_App
 * @details         Implements Diagnostic services - application layer
 * @author          pthanda1
 * Organization     Driver Information Software Section,
 *                  Visteon Corporation
 */
/******************************************************************************/

/* Public headers */

//#include "Rte_DcmApp.h"
#include "Rte_Type.h"
#include "CmpLib.h"
#include "MemLib.h"

/* Private headers  */
#include "Dcm_App.h"
#include "Dcm_App_WDBID.h"
#include "Dcm_App_RDBID.h"

#define DCM_APP_READ_DID_COUNT          2U
#define DCM_APP_WRITE_DID_COUNT         2U


static void Dcm_App_Read_DID(UInt16 DID_Number_U16, teDiagOpStatus pStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData);
static uint8 CDcm_App_Write_DID(UInt16 DID_Number_U16, P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData, teDiagOpStatus pStatus, 
								P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pnrc,teDIDOperation eOperation);

typedef Std_ReturnType (*DID_Read_FncType)(teDiagOpStatus pStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR)pData);
typedef Std_ReturnType (*DID_Write_FncType)(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData, teDiagOpStatus pStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pnrc,teDIDOperation eOperation);

typedef struct  
{
	UInt16 l_DID_Num_U16;
	DID_Read_FncType Did_Read_Func_ptr;
}Diag_Read_DIDInfo_t;

typedef struct
{
	UInt16 l_DID_Num_U16;
	DID_Write_FncType Did_Write_Func_ptr;
}Diag_Write_DIDInfo_t;



static const Diag_Read_DIDInfo_t Dcm_App_Read_DID_Table[DCM_APP_READ_DID_COUNT]=
{
		{0xFD00, &RDBID_ReadData_FD00},
		{0xFD01, &RDBID_ReadData_FD01},
};

static const Diag_Write_DIDInfo_t Dcm_App_Write_DID_Table[DCM_APP_WRITE_DID_COUNT]=
{
		{0xFD00, &WDBID_WriteData_FD00},
		{0xFD01, &WDBID_WriteData_FD01},
};

CMPLIB_INSTANCE(DcmApp)

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
static void CDcm_App_Common_Init(void)
{
	
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
	return E_OK;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpDeActivation( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
	return E_OK;
}

/*************************************************************************//**
 * \brief          Dcm_App_Read_DID()
 *
 * \details        TBD.
 * \n              TBD.
 *
 * \param[in]      TBD.
 *
 * \retval         TBD:
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
static void Dcm_App_Read_DID(UInt16 DID_Number_U16, teDiagOpStatus pStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData)
{
	UInt16 DID_Item_U16;

	for (DID_Item_U16 = 0U; DID_Item_U16 < DCM_APP_READ_DID_COUNT; DID_Item_U16++)
	{
		if (Dcm_App_Read_DID_Table[DID_Item_U16].l_DID_Num_U16 == DID_Number_U16)
		{
			Dcm_App_Read_DID_Table[DID_Item_U16].Did_Read_Func_ptr(pStatus, pData);
		}
	}

	pStatus = E_OK;

}
/*************************************************************************//**
 * \brief          CDcm_App_Write_DID
 *
 * \details        Implements Diagnostics - write operation.
 * \n              Invoked within this module.
 *
 * \param[in]      TBD.
 *
 * \retval         TBD:
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
static uint8 CDcm_App_Write_DID(UInt16 DID_Number_U16, P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData, teDiagOpStatus pStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pnrc,teDIDOperation eOperation)
{
	UInt16 DID_Item_U16;
	UInt8 fl_Ret_Type_U8 = E_OK ;

	for (DID_Item_U16 = 0U; DID_Item_U16 < DCM_APP_WRITE_DID_COUNT; DID_Item_U16++)
	{
		if (Dcm_App_Write_DID_Table[DID_Item_U16].l_DID_Num_U16 == DID_Number_U16)
		{
			fl_Ret_Type_U8= Dcm_App_Write_DID_Table[DID_Item_U16].Did_Write_Func_ptr(pData, pStatus, pnrc, eOperation);
			if(fl_Ret_Type_U8 == E_OK)
			{
				//TBD: Rte_Send_ppDiagDIDWriteComplete_DaigDIDNumber(Dcm_App_Write_DID_Table[DID_Item_U16].DID_Update_Notify);
			}
			break;
		}
	}

	return(fl_Ret_Type_U8);
}
/*************************************************************************//**
 * \brief          CDcm_App_DID_DiagAction()
 *
 * \details        Implements Diagnostics - read/write operation.
 * \n              Invoked by DcmExt.
 *
 * \param[in]      TBD.
 *
 * \retval         TBD:
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
Std_ReturnType CDcmApp_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc, teDIDOperation eOperation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	UInt8 fl_Ret_Type_U8 = E_OK;
	if(eOperation == eRead)
	{
		/* Function routing to Read DID Table*/
		Dcm_App_Read_DID(DIDNum, OpStatus, Data);
	}
	else if((eOperation == eWrite ) || (eOperation == eSTA) ||(eOperation == eRTCtrlToEcu) ||
			(eOperation == eRTDef) || (eOperation == eRTFREEZ))
	{
		/* Function routing to Write DID Table*/
		fl_Ret_Type_U8 = CDcm_App_Write_DID(DIDNum, Data, OpStatus, pNrc,eOperation);
	}
	else
	{
		/* Do Nothing*/
	}
	return(fl_Ret_Type_U8);
}

/*============================================================================
** Function Name    :   Diag Entry status
**
** Visibility       :   Public
**
** Description      :   For checking entry conditions
**
** Invocation       :   DCM Ext
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**==========================================================================*/
Std_ReturnType CDcmApp_Diag_Entry_Status(UInt8 SID, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) RequestData, UInt16 RequestDataSize, UInt8 ReqType, UInt16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCMAPP_APPL_VAR) ErrorCode)
{
	/* Ignoring Unused Parameter */
  	APP_DCM_DEM_IGNORE_UNREF_PARAM(ReqType);
  	APP_DCM_DEM_IGNORE_UNREF_PARAM(SourceAddress);
	
	/* RTE interface should be added to get the voltage and IGN condition check */
	Std_ReturnType ReturnStates = E_OK;
	return  ReturnStates;
}

/*============================================================================
** Function Name    :   Get the current active session value
**
** Visibility       :   Public
**
** Description      :   For checking entry conditions
**
** Invocation       :   DCM Ext
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**==========================================================================*/
Std_ReturnType CDcmApp_Get_Current_Session(uint8 Current_Session)
{
	Std_ReturnType ReturnStates = E_OK;
	return  ReturnStates;
}
/*End of File*/					  
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/*---------------------------------------------------------------------------
Task ID           : PE4TI29141-2510 VIP:Diag Application Implementation
Date              : 05-Nov-2024
By                : pthanda1
Change Description: Initial version
-----------------------------------------------------------------------------*/



