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
 *    @file BswfitCdd_Types.h
 *    @ingroup BswfitCDD
 *    @brief Data types definition for BswfitCDD
 ********************************************************************************************************************/

#ifndef CDD_BSWFIT_TYPES_H
#define CDD_BSWFIT_TYPES_H

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

/** \brief BSW FIT (Ea/Fee)Memory HW block number type defnition. */
typedef uint16 CDD_BswFit_MemoryHwBlockNumberType;

/** \brief BSW FIT (Ea/Fee)Memory HW Data type defnition. */
typedef uint8 CDD_BswFit_MemoryHwDataType;

/** \brief BSW FIT Module test handler type defnition. */
typedef P2FUNC(Std_ReturnType, CDD_BswFit_CODE, CDD_BswFit_MemoryHwWriteType_t) (VAR(CDD_BswFit_MemoryHwBlockNumberType, AUTOMATIC) BlockNumber, P2CONST(CDD_BswFit_MemoryHwDataType, AUTOMATIC, CDD_BswFit_APPL_VAR) DataBufferPtr);

/** \brief BSW FIT (Ea/Fee)Memory HW block status type defnition. */
typedef P2FUNC(uint8, CDD_BswFit_CODE, CDD_BswFit_MemoryHwStatusType_t)(void);

/** \brief (Ea/Fee)Memory Hardware module config type definition . */
typedef struct CDD_BswFit_MemoryConfigType_s {
	CDD_BswFit_MemoryHwWriteType_t 	MemoryHwWrite;
	CDD_BswFit_MemoryHwStatusType_t    MemoryHwStatus;
} CDD_BswFit_MemoryConfigType_t;

/** \brief Memory Hardware module pointer to Module config type defnition. */
typedef CDD_BswFit_MemoryConfigType_t  MemoryHwConfigType;


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
Date              : 13/Dec/2023
By                : rswamyga
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/


/* end of file =============================================================*/

