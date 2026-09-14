/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  Det_Cfg.h                                               *
*  Module Short Name :  DET_CFG_H                                               *
*  Description       :                                                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef DET_CFG_H
#define DET_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
// #include "Rte_CFltM_Type.h" // RTE type definitions 
#include "Std_Types.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define DET_VERSION_INFO_API  TRUE

#define DET_REPORT_ERROR_CALLOUT(a,b,c,d)           Det_ReportErrorToFltM(a,b,c,d)

/*****************************************************************************
*                     Function Prototypes                                    *
******************************************************************************/
void Det_ReportErrorToFltM(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);


/******************************************************************************
*                                 Type Declarations                           *
*******************************************************************************/

/**   \brief  type used in Det_PCConfig */
typedef struct sDet_PCConfigType
{
  uint8 Det_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Det_PCConfigType;


typedef Det_PCConfigType Det_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */


#endif /* DET_CFG_H */
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
Date               : 25-Mar-2024
CDSID              : eganesan
Traceability       : 
Change Description : Initial Framework version of Det
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


