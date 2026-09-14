/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
 *    @file FitManagerCdd_Types.h
 *    @ingroup FitManager
 *    @brief Data types definition for FitManagerCdd
 ********************************************************************************************************************/
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef __CDD_FITMANAGER_TYPES_H__
#define __CDD_FITMANAGER_TYPES_H__

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.
 *
 ******************************************************************************/

//----------------------------------------------------------------------------------------------------------------------
// Type definitions
//----------------------------------------------------------------------------------------------------------------------

/** \brief FIT Module ID type definition. */
typedef uint8 CDD_FitManager_ModuleIdType;
/** \brief Test command type definition. */
typedef uint8 CDD_FitManager_TestCommandType;
/** \brief Test ID type definition. */
typedef uint8 CDD_FitManager_TestIdType;
/** \brief Test data type definition . */
typedef uint8 CDD_FitManager_TestDataType;
/** \brief Number of Tests configured in a FIT Module. */
typedef uint8 CDD_FitManager_TestCountType;

/** \brief FIT Module handler type defnition. */
typedef P2FUNC(Std_ReturnType, CDD_FitManager_CODE, CDD_FitManager_ModuleHandlerType_t) (VAR(CDD_FitManager_TestCommandType, AUTOMATIC) Command,
							VAR(CDD_FitManager_TestIdType, AUTOMATIC) TestID, P2VAR(CDD_FitManager_TestDataType, AUTOMATIC, CDD_FITMANAGER_APPL_VAR) Data);
/** \brief FIT Module test handler type defnition. */
typedef P2FUNC(Std_ReturnType, CDD_FitManager_CODE, CDD_FitManager_TestHandlerType_t) (VAR(CDD_FitManager_TestCommandType, AUTOMATIC) Command,
							P2VAR(CDD_FitManager_TestDataType, AUTOMATIC, CDD_FITMANAGER_APPL_VAR) Data);

/** \brief FIT module test config type defnition. */
typedef struct CDD_FitManager_TestConfigType_s {
	CDD_FitManager_TestIdType        TestID;
	CDD_FitManager_TestHandlerType_t TestHandler;
} CDD_FitManager_TestConfigType_t;

/** \brief FIT module pointer to test config type defnition. */
typedef P2CONST(CDD_FitManager_TestConfigType_t, AUTOMATIC, CDD_FITMANAGER_APPL_CONST) CDD_FitManager_TestConfigTypePtr;


/** \brief FIT module config type definition . */
typedef struct CDD_FitManager_ModuleConfigType_s {
	CDD_FitManager_ModuleIdType     	FitModuleID;
	CDD_FitManager_ModuleHandlerType_t 	ModuleTestHandler;
	CDD_FitManager_TestCountType        TestCount;
	CDD_FitManager_TestConfigTypePtr    TestConfigDataPtr;
} CDD_FitManager_ModuleConfigType_t;

/** \brief FIT module pointer to Module config type defnition. */
typedef CDD_FitManager_ModuleConfigType_t  FitModuleConfigType;





#endif	/* __CDD_FITMANAGER_TYPES_H__ */
#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_*/

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================*/
/*---------------------------------------------------------------------------------------
Date              : 16/Nov/2023
By                : rdarshan
Traceability      : JIRA ID - PK3T229419-791
Change Description: Initial Version
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
 Date              : 9/Jan/2024
 By                : rdarshan
 Traceability      : JIRA ID - PK3T229419-1447
 Change Description: Updated fitmanagercdd files to match the configuration xml file.
-----------------------------------------------------------------------------------------*/


/* end of file =============================================================*/

