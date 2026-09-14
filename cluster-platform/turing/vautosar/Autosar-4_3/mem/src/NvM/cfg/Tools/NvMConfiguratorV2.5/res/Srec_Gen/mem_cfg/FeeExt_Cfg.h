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
#ifndef FEEEXT_CFG_H
#define FEEEXT_CFG_H
/*****************************************************************************
*  File Name         :  FeeExt_Cfg.h                                         *
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
#include "Os.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
typedef uint32 TickType;
extern void GetCounterValue (void);
/*Macro to get the Os counter value*/
#define FEE_EXT_GET_SYSTEM_TIMER(Value)                 (void)GetCounterValue()

/*Configurable Timeout value for Fls operations*/
#define FEE_EXT_TIMEOUT_VALUE                           (TickType)2500


#endif /*FEEEXT_CFG_H*/

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


