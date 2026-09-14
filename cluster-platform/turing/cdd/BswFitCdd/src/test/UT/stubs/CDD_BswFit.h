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
 *    @file CDD_Bswfit.h
 *    @ingroup Bswfitcdd
 *    @brief Interfaces & Instants Declaration for CDD_Bswfit
 ********************************************************************************************************************/
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef CDD_BSWFIT_H
#define CDD_BSWFIT_H

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "Std_Types.h"
#include "CDD_BswFit_Cfg.h"
#include "CDD_FitManager_Cfg.h"
#include "CDD_BswFit_Types.h"
/*============================================================================
 ** T Y P E   D E F I N I T I O N S
 **==========================================================================*/


/*============================================================================
 ** E N T R Y   P O I N T S
 **==========================================================================*/
/*Definition for Vector Stack */
#define BSWFIT_VECTOR_STACK     1u
/*Definition for VAUTOSAR Stack */
#define BSWFIT_VAUTOSAR_STACK   2u 

/* NvM Fault injection states */
#define BSWFIT_NVM_IDLE_STATE                    (uint8)0x01
#define BSWFIT_NVM_NV_WRITE_STATE                (uint8)0x02
#define BSWFIT_NVM_NV_WRITE_WAIT_STATE           (uint8)0x03
#define BSWFIT_NVM_NV_REDUNTANT_WRITE_STATE      (uint8)0x04
#define BSWFIT_NVM_NV_REDUNTANT_WRITE_WAIT_STATE (uint8)0x05
#define BSWFIT_NVM_READ_BLOCK_STATE              (uint8)0x06
#define BSWFIT_NVM_READ_BLOCK_WAIT_STATE         (uint8)0x07

/* Function declarations */
void CCDD_BswFit_Impl_MainFunction(void);
void BswFitCdd_Init(void);
void BswFitCdd_DeInit(void);

#endif /* CDD_BSWFIT_H */

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_*/

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
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
**============================================================================
**============================================================================
Date              : 13/Dec/2023
By                : rswamyga
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/
