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

#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef __FITMANAGERCDD_DEFINES_H__
#define __FITMANAGERCDD_DEFINES_H__

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

/*==================[macros]================================================*/



#define CDD_FITMANAGER_FIT_BUFFER_DATA0 							((uint8)(0x00))
#define CDD_FITMANAGER_FIT_BUFFER_DATA1 							((uint8)(0x01))
#define CDD_FITMANAGER_FIT_BUFFER_DATA2 							((uint8)(0x02))
#define CDD_FITMANAGER_FIT_BUFFER_DATA3 							((uint8)(0x03))
#define CDD_FITMANAGER_FIT_BUFFER_DATA4 							((uint8)(0x04))

#define CDD_FITMANAGER_FIT_TRUST_CHECK_BIT 						((uint8)(0x80))

#define CDD_FITMANAGER_FIT_TESTID_MASK							((uint8)(0x7F))

/*------------------[DEM status codes] -------------------------------------*/
/** \brief Type for ICU DEM status */
/* Brief type for FITMANAGERCDD DEM pass status. */
#define FITMANAGERCDD_DEM_EVENT_STATUS_PASSED       ((uint8) 0x00U)
/* Brief type for FITMANAGERCDD DEM failed status. */
#define FITMANAGERCDD_DEM_EVENT_STATUS_FAILED       ((uint8) 0x01U)

/*------------------[Service identifiers]-----------------------------------*/

/** \brief Definition of the service identifier of FitManager_Datacheck. */
#define CDD_FITMANAGER_API_NO_DATA                   		((uint8) 0x00U)
#define CDD_FITMANAGER_API_NO_HANDLER                   		((uint8) 0x01U)

/*------------------[Development errors]------------------------------------*/
/** \brief API service called FitManager with null data  */
#define CDD_FITMANAGER_E_PARAM_DATA               					((uint8) 0x00U)
#define CDD_FITMANAGER_E_PARAM_HANDLER               					((uint8) 0x01U)

#endif //__FITMANAGERCDD_DEFINES_H__

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_ */

/*==============================================================================================================================================
Date              	: 29-11-23
CDSID             	: rdarshan
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*---------------------------------------------------------------------------------------
 Date              : 9/Jan/2024
 By                : rdarshan
 Traceability      : JIRA ID - PK3T229419-1447
 Change Description: Updated fitmanagercdd files to match the configuration xml file.
-----------------------------------------------------------------------------------------*/
