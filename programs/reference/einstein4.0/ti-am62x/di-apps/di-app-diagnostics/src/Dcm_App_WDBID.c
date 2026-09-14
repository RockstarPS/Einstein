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
 * @file            Dcm_App_WDBID.c
 * @brief           Dcm_App_WDBID - Private module (part of Dcm_App)
 * @details         Implements Write Data By IDentifier - $2E service handlers
 * @author          jgopal1
 * Organization     Driver Information Software Section,
 *                  Visteon Corporation
 */
/******************************************************************************
 * Compiler Name    : GHS 2017.1.4
 * Target Processor : Traveo II
 *****************************************************************************/


/*****************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Project Includes                           *
 ******************************************************************************/

//#include "Rte_DcmApp.h"

#undef RTE_APPLICATION_HEADER_FILE // TBD: FIXME
#include "Rte_Type.h"
#include "Dcm_App_WDBID.h"
#include "Dcm_App_cfg.h"
#include "Dcm_Types.h"
#include "Dcm.h"
#include "Rte_DcmExt_Type.h"
#include "Rte_Dcm_Type.h"
#include "Dcm_App.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/


/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

#define DEFAULT_RESET           ( 0x02u)
#define SHORT_TERM_ADJUSTMENT   ( 0x05u)

static boolean l_WriteDID_Entry = FALSE;

/*****************************************************************************
 *                              File Scope Prototypes                         *
 ******************************************************************************/
static uint8 Dcm_App_WDBID_Response_Handling(uint8 jobsts, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrCode);

/*****************************************************************************
 *                               Functions                                     *
 ******************************************************************************/

/******************************************************************************
* Function Name     : Dcm_App_WDBID_Response_Handling(void)
* Description       :
* Invocation        : On DID Write service($2E)
* Parameters        : void
* Return Value      : uint8
* Critical Section  : None
******************************************************************************/
uint8 Dcm_App_WDBID_Response_Handling(uint8 jobsts, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrCode)
{
	uint8 fl_Ret_Type;
 
	if(DCM_E_WRITE_INPROGRESS == jobsts)
	{
		fl_Ret_Type = DCM_E_RESPONSE_PENDING;
	}
	else if(DCM_E_WRITE_FAIL == jobsts)
	{
		fl_Ret_Type = DCM_E_NOT_OK;
		*ErrCode =  (Dcm_NegativeResponseCodeType)DCM_E_GENERALPROGRAMMINGFAILURE;
		l_WriteDID_Entry = FALSE;
	}
	else
	{
		fl_Ret_Type = DCM_E_OK;
		l_WriteDID_Entry = FALSE;
	}
 
	return(fl_Ret_Type);
}

/*******************************************************************************
 * Function Name     : WDBID_WriteData_FD00
 * Description       : 
 * Invocation        : On DID Write service($2E)
 * Parameters        : UInt8 Data;
 * Parameters        : teDiagOpStatus OpStatus
 * Parameters        : UInt8 ErrorCode
 * Return Value      : uint8
 * Critical Section  : None
 ******************************************************************************/
uint8 WDBID_WriteData_FD00(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation)
{
	uint8 fl_ret_val_U8;
	uint8 fl_job_write_status_U8;

	fl_job_write_status_U8 = DCM_E_NOT_OK;
	fl_ret_val_U8 = DCM_E_NOT_OK;
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;

	
	if(FALSE == l_WriteDID_Entry)
	{
	    l_WriteDID_Entry = TRUE;	
						
		fl_ret_val_U8 = DCM_E_RESPONSE_PENDING;
	    *ErrorCode = DCM_E_OK;
	}
	else
	{
		// Rte interface to be added to get the job status
	    fl_ret_val_U8 = Dcm_App_WDBID_Response_Handling(fl_job_write_status_U8, ErrorCode);
	}
	return (fl_ret_val_U8);
}
/*******************************************************************************
 * Function Name     : WDBID_WriteData_FD07
 * Description       : 
 * Invocation        : On DID Write service($2E)
 * Parameters        : UInt8 Data;
 * Parameters        : teDiagOpStatus OpStatus
 * Parameters        : UInt8 ErrorCode
 * Return Value      : uint8
 * Critical Section  : None
 ******************************************************************************/
uint8 WDBID_WriteData_FD01(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation)
{
	uint8 fl_ret_val_U8;
	uint8 fl_job_write_status_U8;

	fl_job_write_status_U8 = DCM_E_NOT_OK;
	fl_ret_val_U8 = DCM_E_NOT_OK;
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;

	
	if(FALSE == l_WriteDID_Entry)
	{
	    l_WriteDID_Entry = TRUE;	
						
		fl_ret_val_U8 = DCM_E_RESPONSE_PENDING;
	    *ErrorCode = DCM_E_OK;
	}
	else
	{
		// Rte interface to be added to get the job status
	    fl_ret_val_U8 = Dcm_App_WDBID_Response_Handling(fl_job_write_status_U8, ErrorCode);
	}
	return (fl_ret_val_U8);
}

/*******************************************************************************
 * Function Name     : WDBID_IOCTL_FD31
 * Description       : DID is used do IO control
 * Invocation        : On DID Write service($2E)
 * Parameters        : UInt8 Data;
 * Parameters        : teDiagOpStatus OpStatus
 * Parameters        : UInt8 ErrorCode
 * Return Value      : uint8
 * Critical Section  : None
 ******************************************************************************/
uint8 WDBID_IOCTL_FD31(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation)
{
	uint8 fl_ret_val_U8 = DCM_E_NOT_OK;
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;

	switch(eOperation)
	{
	case DEFAULT_RESET:
	    fl_ret_val_U8 = DCM_E_OK;
	    *ErrorCode = DCM_E_OK;
		break;
		
	case SHORT_TERM_ADJUSTMENT:
	    fl_ret_val_U8 = DCM_E_OK;
	    *ErrorCode = DCM_E_OK;
		break;

	default:
		fl_ret_val_U8 = DCM_E_REQUESTOUTOFRANGE;
		break;
	}

	return (fl_ret_val_U8);
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
 
 