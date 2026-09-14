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
*  File Name         :  Det_Cfg.c                                               *
*  Module Short Name :  DET_CFG_C                                               *
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
#ifndef DET_CFG_C
#define DET_CFG_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Det_Cfg.h"
#include "Os.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                              Function Definitions                          *
******************************************************************************/

/**
 * \brief API to report DET error to FltM fault handler.
 * 
 * Packs the error parameters into a log data array and calls OsTrustedCall_FltM_ReportFault.
 * 
 * \param ModuleId   The module ID reporting the error (uint16).
 * \param InstanceId The instance ID of the module (uint8).
 * \param ApiId      The API ID where the error occurred (uint8).
 * \param ErrorId    The specific error ID (uint8).
 */
void Det_ReportErrorToFltM(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    uint8 logData[5] = {0};
    /*Pack parameters into log data array */
    logData[0] = (ModuleId >> 8) & 0xFF;  // High byte of ModuleId
    logData[1] = ModuleId & 0xFF;         // Low byte of ModuleId
    logData[2] = InstanceId;
    logData[3] = ApiId;
    logData[4] = ErrorId;
    /* Route to FltM fault report */
    OsTrustedCall_FltM_ReportFault(DET_ERROR, FLTM_ACTIVE, &logData[0], 5);
}

#endif /* DET_CFG_C */
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


