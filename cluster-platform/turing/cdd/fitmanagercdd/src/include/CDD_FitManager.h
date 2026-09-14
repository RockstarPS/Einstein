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
 *    @file CDD_FitManager.h
 *    @ingroup FitManager
 *    @brief Interfaces & Instants Declaration for CDD_FitManager
 ********************************************************************************************************************/
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef CDD_FITMANAGER_H
#define CDD_FITMANAGER_H

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "Std_Types.h"
#include "CDD_FitManager_Cfg.h"

/*Definition for Vector Stack */
#define   FITMGR_VECTOR_STACK     1u
/*Definition for VAUTOSAR Stack */
#define   FITMGR_VAUTOSAR_STACK   2u 
/*============================================================================
 ** T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S
 **==========================================================================*/

/*============================================================================
 **
 ** Function Name    : void CDD_FitManager_Init(void)
 **
 ** Visibility       : EcumExt
 **
 ** Description      : Initializes the variables of CDD_FitManger layer
 **
 ** Invocation       :
 **
 ** Parameters       : None
 **
 ** Return Value     : Std_ReturnType - E_NOT_OK  - Fail
 **										E_OK     - Success
 **
 ** Critical Section : None
 **
 ** Created          : rdarshan / 16-NOV-2023
 **
 ** Updated          : CDS ID / DATE
 **
 **==========================================================================*/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_Init(void);

/*============================================================================
 **
 ** Function Name    : Std_ReturnType CDD_FitManager_DeInit(void)
 **
 ** Visibility       : EcumExt
 **
 ** Description      : DeInitializes the variables of CDD_FitManager layer
 **
 ** Invocation       :
 **
 ** Parameters       : None
 **
 ** Return Value     : Std_ReturnType - E_NOT_OK  - Fail
 **										E_OK     - Success
 **
 ** Critical Section : None
 **
 ** Created          : rdarshan / 16-NOV-2023
 **
 ** Updated          : CDS ID / DATE
 **
 **==========================================================================*/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_DeInit(void);

/*============================================================================
 **
 ** Function Name    : void CDD_FitManager_MainFunction(void)
 **
 ** Visibility       : OS
 **
 ** Description      :
 **
 ** Invocation       : OS
 **
 ** Parameters       : None
 **
 ** Return Value     : Std_ReturnType - E_NOT_OK  - Fail
 **										E_OK     - Success
 **
 ** Critical Section : None
 **
 ** Created          : rdarshan / 16-NOV-2023
 **
 ** Updated          : CDS ID / DATE
 **
 **==========================================================================*/
FUNC(void, CDD_FitManager_CODE) CDD_FitManager_MainFunction(void);

/*============================================================================
 **
 ** Function Name    :  Std_ReturnType CDD_FitManager_HandleFaultInjection(uint8 *Data)
 **
 ** Visibility       :
 **
 **
 ** Description      :
 **
 ** Invocation       :
 **
 ** Parameters       : uint8 *Data
 **
 ** Return Value     : Std_ReturnType - E_NOT_OK  - Fail
 **										E_OK     - Success
 **
 ** Critical Section : None
 **
 ** Created          : rdarshan / 16-NOV-2023
 **
 ** Updated          : CDS ID / DATE
 **
 **==========================================================================*/
FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_HandleFaultInjection(uint8 *Data);

/*============================================================================
 **
 ** Function Name    : void CDD_FitManager_RouteFITDID(uint8 *Data, uint8 OpStatus, uint8 *pNrc)
 **
 ** Visibility       :
 **
 ** Description      : Execute the power state transition process
 **
 ** Invocation       :
 **
 ** Parameters       : uint8 *Data,
 **                    uint8 OpStatus,
 **                    uint8 *pNrc
 **
 ** Return Value     : Std_ReturnType - E_NOT_OK  - Fail
 **										E_OK     - Success
 **
 ** Critical Section : None
 **
 ** Created          : rdarshan / 16-NOV-2023
 **
 ** Updated          : CDS ID / DATE
 **
 **==========================================================================*/

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_RouteFITDID(uint8 *Data, uint8 OpStatus, uint8 *pNrc);

FUNC(Std_ReturnType, CDD_FitManager_CODE) CFitManager_FaultInjectionStartStopHandler(uint8 StartStopData, uint8 TestListID, uint8 *Data);

//FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data);

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_NonSupervisorCallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data);

FUNC(Std_ReturnType, CDD_FitManager_CODE) CDD_FitManager_CallFaultInjectionHandler(uint8 LoopCount, uint8 StartStopData, uint8 TestListID, uint8 *Data);

#endif /* CDD_FITMANAGER_H */

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_*/

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 16/Nov/2023
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
 Date              : 9/Jan/2024
 By                : rdarshan
 Traceability      : JIRA ID - PK3T229419-1447
 Change Description: Updated fitmanagercdd files to match the configuration xml file.
-----------------------------------------------------------------------------------------*/
