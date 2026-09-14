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

File Name        :  MemIf_Lcfg.c
Module Short Name:  MemIf_Lcfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef MEMIF_LCFG_C
#define MEMIF_LCFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemIf_Cfg.h"
#include "MemIf.h"
#include "Ea.h"
#define MEMIF_CODE_SEC_START
 #include "MemMap.h"

#define MEMIF_DATA_SEC_START
 #include "MemMap.h"

#define MEMIF_CONST_SEC_START
 #include "MemMap.h"


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

const MemIf_FunctionPointerType MemIF_FunctionPointer[MEMIF_NUMBER_OF_DEVICES_SUPPORTED] = 
{
    {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    {
        Ea_SetMode,
        Ea_Read,
        Ea_Write,
        Ea_Cancel,
        Ea_GetStatus,
        Ea_GetJobResult,
        Ea_InvalidateBlock,
        Ea_GetVersionInfo,
        Ea_EraseImmediateBlock,
        NULL_PTR,
        NULL_PTR
    },
{
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    }
};

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



#define MEMIF_CONST_SEC_END
 #include "MemMap.h"

#define MEMIF_DATA_SEC_END
 #include "MemMap.h"

#define MEMIF_CODE_SEC_END
 #include "MemMap.h"


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 8/24/2024 5:22:32 PM
****************************************************************/
