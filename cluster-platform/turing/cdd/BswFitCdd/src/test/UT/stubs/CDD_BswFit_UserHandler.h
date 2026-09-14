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
 *    @file CDD_BswFit_UserHandler.h
 *    @ingroup BswFitCdd
 *    @brief Data types definition for BswFitCdd
 ********************************************************************************************************************/
#ifndef CDD_BSWFIT_USERHANDLER_H
#define CDD_BSWFIT_USERHANDLER_H


/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.
 *
 ******************************************************************************/

/*****************************************************************************
 *                                 Enum Declarations                          *
 ******************************************************************************/


FUNC(Std_ReturnType, CDD_BswFit_CODE) CDD_BswFit_FaultInjectionHandler(uint8 StartStopData, uint8 TestListID, uint8 *Data);


#endif
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
Date              : 29/Dec/2023
By                : rdarshan
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/


/* end of file =============================================================*/

