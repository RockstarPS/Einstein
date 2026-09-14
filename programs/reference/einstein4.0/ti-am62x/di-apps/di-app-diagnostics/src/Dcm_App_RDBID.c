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
 * @file            Dcm_App_RDBID.c
 * @brief           Dcm_App_RDBID - Private module (part of Dcm_App)
 * @details         Implements Read Data By IDentifier - $22 service handlers
 * @author          pthanda1
 * Organization     Driver Information Software Section,
 *                  Visteon Corporation
 */
/******************************************************************************
 * Compiler Name    : GHS 2017.1.4
 * Target Processor : Traveo II
 *****************************************************************************/
//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

//#include "Rte_DcmApp.h"
#include "Rte_Type.h"
#include "Dcm_App_RDBID.h"
#include "Dcm_App_cfg.h"
#include "Dcm_App.h"
#include "Rte_Dcm_Type.h"
#include "Dcm.h"
#include "Dcm_Cfg.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

/*******************************************************************************
 * Function Name     : RDBID_ReadData_FD00
 * Description       : 
 * Invocation        : On DID Read service($22)
 * Parameter[in]     : teDiagOpStatus OpStatus
 * Parameter[in]     : uint8 Data
 * Return Value      : uint8
 * Critical Section  : None
 ******************************************************************************/
uint8 RDBID_ReadData_FD00(teDiagOpStatus OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data)
{
	Data[0] = 0x12u;
	Data[1] = 0x34u;
	return E_OK;
}

/*******************************************************************************
 * Function Name     : RDBID_ReadData_FD01
 * Description       : 
 * Invocation        : On DID Read service($22)
 * Parameter[in]     : teDiagOpStatus OpStatus
 * Parameter[in]     : uint8 Data
 * Return Value      : uint8
 * Critical Section  : None
 ******************************************************************************/
uint8 RDBID_ReadData_FD01(teDiagOpStatus OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data)
{
    Data[0] = 0x12u;
	Data[1] = 0x34u;
	Data[2] = 0x56u;
	Data[3] = 0x78u;
	return E_OK;
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
 







