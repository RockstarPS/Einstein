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
#ifndef FEEEXT_H
#define FEEEXT_H
/*****************************************************************************
*  File Name         :  FeeExt.h                                             *
*  Module Short Name :  FeeExt                                               *
*  Description       :                                                       *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Traveo II                                              *
*                                                                            *
******************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "FeeExt_Cfg.h"


/**********************************************************************************************************************
 * FUNCTION DECLARATIONS
 *********************************************************************************************************************/
/**
 * This method is the init function of FeeExt module
 * @param     none
 * @return    void
 */
extern void FeeExt_Init(void);

/**
 * This method provides the Fls erase functionality through FeeExt module with timeout condition
 * @param     uint32 TargetAddress, uint32 Length
 * @return    Std_ReturnType
 */
extern Std_ReturnType FeeExt_Erase (uint32 TargetAddress, uint32 Length);

/**
 * This method provides the Fls write functionality through FeeExt module with timeout condition
 * @param     uint32 TargetAddress, uint8* SourceAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
extern Std_ReturnType FeeExt_Write (uint32 TargetAddress, uint8* SourceAddressPtr, uint32 Length);

/**
 * This method provides the Fls cancel functionality through FeeExt module
 * @param     none
 * @return    void
 */
extern void FeeExt_Cancel(void);

/**
 * This method provides the Fls Get Status functionality through FeeExt module and returns the status
 * @param     void
 * @return    MemIf_StatusType
 */
extern MemIf_StatusType FeeExt_GetStatus(void);

/**
 * This method provides the Fls Get Job Result status through FeeExt module
   Also checks for timeout elapsed and triggers FLs_Cancel
 * @param     void
 * @return    MemIf_JobResultType
 */
extern MemIf_JobResultType FeeExt_GetJobResult(void);

/**
 * This method provides the Fls read functionality through FeeExt module with timeout condition
 * @param     uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
extern Std_ReturnType FeeExt_Read (uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length);

/**
 * This method provides the Fls read immediate functionality through FeeExt module with timeout condition
 * @param     uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
extern Std_ReturnType FeeExt_ReadImmediate (uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length);

extern Std_ReturnType FeeExt_BlankCheck (uint32 TargetAddress, uint32 Length);
#endif /*FEEEXT_H*/

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 26-Jun-2022
CDSID              : nchellap
Traceability       :
Change Description : Initial version of FlsExt
-----------------------------------------------------------------------------*/


