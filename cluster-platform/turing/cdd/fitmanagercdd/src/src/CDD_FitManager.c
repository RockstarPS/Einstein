/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*!*****************************************************************************************************************
 *    @file Cdd_FitManager.c
 *    @defgroup FitManager
 *    @ingroup FitManager
 *    @defgroup Cdd_FitManager
 *    @ingroup Cdd_FitManager
 *    @brief This file implements and provides the external interfaces to be invoked by the user module for
 *    excuting the Fault Injection Testing.
 ********************************************************************************************************************/
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef CDD_FITMANAGER_C
#define CDD_FITMANAGER_C

/*****************************************************************************
 * System Includes                                                            *
 *****************************************************************************/
#include "CDD_FitManager.h"
#include "CDD_FitManager_Det.h"
#if defined(FITMGR_SYSTEM_STACK) && (FITMGR_SYSTEM_STACK == FITMGR_VAUTOSAR_STACK) /* VAUTOSAR_STACK */
#include "OsInternal.h"
#endif



/*****************************************************************************
 * Project Includes                                                           *
 *****************************************************************************/

/*****************************************************************************
 * File Scope Prototypes                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Constants                                                                  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 *****************************************************************************/

/*****************************************************************************
 * Manifest Constants                                                         *
 *----------------------------------------------------------------------------*
 * Definition of Manifest constant shall be followed by a comment that        *
 * explains the purpose of the constant.                                      *
 *****************************************************************************/

/*****************************************************************************
 * Macro Definitions                                                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Globally  accessed Variable Declarations                                   *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/

/*****************************************************************************
 * Locally used Variable Declarations                                         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/



#ifdef cCDD_FITMANAGER_ENABLE_MEMORYMAP
#define CDD_FITMANAGER_START_SEC_VAR
#include "MemMap.h"
#endif




#ifdef cCDD_FITMANAGER_ENABLE_MEMORYMAP
#define CDD_FITMANAGER_STOP_SEC_VAR
#include "MemMap.h"
#endif

#ifdef cCDD_FITMANAGER_ENABLE_MEMORYMAP
#define CDD_FITMANAGER_START_SEC_CODE
#include "MemMap.h"
#endif

#if defined(FITMGR_SYSTEM_STACK) && (FITMGR_SYSTEM_STACK == FITMGR_VECTOR_STACK) /* VAUTOSAR_STACK */
extern uint8 Os_Call_CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 Arg1, uint8 Arg2, uint8 Arg3, uint8* Arg4);
#endif

/*!*********************************************************************************************************************
 * @brief  Initialization of FitManagerCdd module. It will invoke the init of Fitmgr
 *
 * @return E_OK:           Succeed
 *         E_NOT_OK:       Failed
 ***********************************************************************************************************************/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_Init(void)
{

}

/*!*********************************************************************************************************************
 * @brief  DeInitialization of FitManagerCdd
 *
 * @return E_OK:           Succeed
 *         E_NOT_OK:       Failed
 ***********************************************************************************************************************/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_DeInit(void)
{

}

/*!*****************************************************************************************************************
 *   @brief      To perform the periodic operations of FitManagerCdd including abnormal voltage monitoring.
 ********************************************************************************************************************/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_MainFunction(void)
{


}

/*!*****************************************************************************************************************
 *   @brief      	To trigger the new state request which needs to be executed
 *   @param[in]  	newState -
 *   @return    	E_OK:           new  state request is accepted
 *          		E_NOT_OK:       new  state request is NOT accepted
 *
 *          		2E 4F 09 20 1 1 xx xx
 *          		20 - module ID
 *          		1  - fit test id
 *          		1 - start/stop access
 *          		xx, yy - fit data
 ********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_RouteFITDID(uint8 *Data, uint8 OpStatus, uint8 *pNrc)
{
	uint8 ReturnType = E_NOT_OK;

	if(Data != NULL_PTR)
	{
		ReturnType = CDD_FitManager_HandleFaultInjection(Data);
	}
	else
	{
		/* Report DET Error */
		CDD_FitManager_ReportError(CDD_FITMANAGER_API_NO_DATA, CDD_FITMANAGER_E_PARAM_DATA);
	}

	return ReturnType;

}

/*!*****************************************************************************************************************
 *   @brief      	To trigger the new state request which needs to be executed
 *   @param[in]  	newState -
 *   @return    	E_OK:           new  state request is accepted
 *          		E_NOT_OK:       new  state request is NOT accepted
 *
 *          		2E 4F 09 20 1 1 xx xx
 *          		00 - module ID
 *          		88  - fit test id
 *          		1 - start/stop access
 *          		xx, yy - fit data
 ********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_HandleFaultInjection(uint8 *Data)
{
	uint8 ReturnType = E_NOT_OK;

	uint8 LoopCount;
	uint8 ModuleIndex= 0;
	uint8 StartStopData;

	uint8 TstIDLoop;
	uint8 TestIDData;
	uint8 TestListID;
	uint8 *FitData;
	uint8 FitTestID;

	uint8 FitManager_TestIdSize = 0;

	/* Extract the TestId from the data received from Diagnostics Tool , TestId data will be max of 0x7F - BIT0 to BIT7 bits  (0 to 127)*/
	FitTestID = Data[CDD_FITMANAGER_FIT_BUFFER_DATA1] & CDD_FITMANAGER_FIT_TESTID_MASK;

	for(LoopCount = CDD_FITMANAGER_FIT_BUFFER_DATA0; ModuleIndex < CDD_FITMANAGER_MAX_NUMBER_OF_MODULES; LoopCount++)
	{
		/*To select module ID */
		if(Data[CDD_FITMANAGER_FIT_BUFFER_DATA0] == CDD_FitManager_ModuleConfigData[LoopCount].FitModuleID)
		{

			FitManager_TestIdSize = CDD_FitManager_ModuleConfigData[LoopCount].TestCount;


			for(TstIDLoop = CDD_FITMANAGER_FIT_BUFFER_DATA0; TstIDLoop < FitManager_TestIdSize; TstIDLoop++)
			{

				/* To get the Test id array from FitTestList array */
				TestIDData = (CDD_FitManager_ModuleConfigData[LoopCount].TestConfigDataPtr[TstIDLoop].TestID);

				/* compare if the test id present from the list to Files invoke as trusted call / privilage mode set */

				if(FitTestID == TestIDData)
				{
					TestListID = TestIDData;
					StartStopData = Data[CDD_FITMANAGER_FIT_BUFFER_DATA2];
					FitData = &(Data[CDD_FITMANAGER_FIT_BUFFER_DATA3]);
					/* Check for Trusted or Non Trusted BIT , BIT7 from data received from Diagnostics Tool */
					if((Data[CDD_FITMANAGER_FIT_BUFFER_DATA1] & CDD_FITMANAGER_FIT_TRUST_CHECK_BIT) == CDD_FITMANAGER_FIT_TRUST_CHECK_BIT)
					{
						/* Trusted call invocation */
						#if defined(FITMGR_SYSTEM_STACK) && (FITMGR_SYSTEM_STACK == FITMGR_VECTOR_STACK)
						ReturnType = Os_Call_CDD_FitManager_SupervisorCallFaultInjectionHandler(LoopCount, StartStopData,TestListID,FitData);
						#else
						ReturnType = OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler(LoopCount, StartStopData,TestListID,FitData);
						#endif
					}
					else
					{
						/* Non Trusted call invocation */
						ReturnType = CDD_FitManager_NonSupervisorCallFaultInjectionHandler(LoopCount, StartStopData,TestListID,FitData);

					}
					break;
				}

			}
			break;
		}
		else
		{
			ModuleIndex++;
		}

	}

	return ReturnType;

}

/*!*****************************************************************************************************************
 *   @brief      	To trigger supervisor calls to inject fault.
 *   @param[in]  	newState -
 *   @return    	E_OK:           new  state request is accepted
 *          		E_NOT_OK:       new  state request is NOT accepted
 *

 ********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data)
{
	uint8 ReturnType = E_NOT_OK;

	ReturnType = CDD_FitManager_CallFaultInjectionHandler( LoopCount,  StartStopData,  TestListID,  Data);

	return ReturnType;
}

/*!*****************************************************************************************************************
 *   @brief      	To trigger non supervisor calls to inject fault.
 *   @param[in]  	newState -
 *   @return    	E_OK:           new  state request is accepted
 *          		E_NOT_OK:       new  state request is NOT accepted
 *

 ********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_NonSupervisorCallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data)
{

	uint8 ReturnType = E_NOT_OK;

	ReturnType = CDD_FitManager_CallFaultInjectionHandler( LoopCount,  StartStopData,  TestListID,  Data);

	return ReturnType;

}

/*!*****************************************************************************************************************
 *   @brief      	To trigger non supervisor calls to inject fault.
 *   @param[in]  	newState -
 *   @return    	E_OK:           new  state request is accepted
 *          		E_NOT_OK:       new  state request is NOT accepted
 *

 ********************************************************************************************************************/


FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_CallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data)
{

	uint8 ReturnType = E_NOT_OK;

	if(CDD_FitManager_ModuleConfigData[LoopCount].ModuleTestHandler != NULL_PTR)
	{

		ReturnType = CDD_FitManager_ModuleConfigData[LoopCount].ModuleTestHandler(StartStopData,TestListID,Data);

		/* below case is to invoke the specific test handler which is not present under  module handler */
		if(ReturnType == E_NOT_OK)
		{
			if (CDD_FitManager_ModuleConfigData[LoopCount].TestConfigDataPtr[TestListID].TestHandler != NULL_PTR)
			{
			ReturnType = CDD_FitManager_ModuleConfigData[LoopCount].TestConfigDataPtr[TestListID].TestHandler(StartStopData,Data);
			}
		}

	}
	else if (CDD_FitManager_ModuleConfigData[LoopCount].TestConfigDataPtr[TestListID].TestHandler != NULL_PTR)
	{
		ReturnType = CDD_FitManager_ModuleConfigData[LoopCount].TestConfigDataPtr[TestListID].TestHandler(StartStopData,Data);

	}
	else
	{
		/* Report DET error */
		CDD_FitManager_ReportError(CDD_FITMANAGER_API_NO_HANDLER, CDD_FITMANAGER_E_PARAM_HANDLER);
	}

	return ReturnType;

}



#ifdef cCDD_FITMANAGER_ENABLE_MEMORYMAP
#define CDD_FITMANAGER_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /*CDD_FITMANAGER_C*/

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_ */

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 16/November/2023
By                : rdarshan
Traceability      : JIRA ID - PK3T229419-791
Change Description: Initial Version
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 16/November/2023
By                : rdarshan
Traceability      : JIRA ID - PK3T229419-
Change Description: Clean up done for SW code format, unwanted functions, variables etc
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 8/Decmeber/2023
By                : rdarshan
Traceability      : JIRA ID - PK3T229419-1044
Change Description: Updated SW for mcufit for testing adc, wdg and clock monitoring.
**-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 12/Decmeber/2023
By                : rdarshan
Traceability      : JIRA ID - PK3T229419-1044
Change Description: Updated SW for done to address some clean up activity and sizeissue.
**-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
 Date              : 9/Jan/2024
 By                : rdarshan
 Traceability      : JIRA ID - PK3T229419-1447
 Change Description: Updated fitmanagercdd files to match the configuration xml file.
-----------------------------------------------------------------------------------------*/
