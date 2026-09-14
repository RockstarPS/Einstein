/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  MemIf_Cfg.h
Module Short Name:  MemIf_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemIf_Types.h"


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define MEMIF_NUMBER_OF_DEVICES_SUPPORTED        3U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    void (*SetModePointer)(MemIf_ModeType);
    Std_ReturnType (*ReadBlockPointer)(uint16,uint16,uint8*,uint16);
    Std_ReturnType (*WriteBlockPointer)(uint16,const uint8*);
    void (*CancelPointer)(void);
    MemIf_StatusType (*GetStatusPointer)(void);
    MemIf_JobResultType (*GetJobResultPointer)(void);
    Std_ReturnType (*InvalidateBlockPointer)(uint16);
    void (*GetVersionInfoPointer)(Std_VersionInfoType*);
    Std_ReturnType (*EraseImmediateBlockPointer)(uint16);
    void (*SuspendInternalJob)(void);
    void (*ResumeInternalJob)(void);
}MemIf_FunctionPointerType;
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
extern const MemIf_FunctionPointerType MemIF_FunctionPointer[MEMIF_NUMBER_OF_DEVICES_SUPPORTED];

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:27 AM
****************************************************************/
