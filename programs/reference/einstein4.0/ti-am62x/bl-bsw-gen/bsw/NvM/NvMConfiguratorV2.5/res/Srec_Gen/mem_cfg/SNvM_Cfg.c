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

File Name        :  SNvM_Cfg.c
Module Short Name:  SNvM_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef SNVM_CFG_C
#define SNVM_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "SNvM_Cfg.h"
#define SNVM_CODE_SEC_START
#include "MemMap.h"

#define SNVM_DATA_SEC_START
#include "MemMap.h"

#define SNVM_CONST_SEC_START
#include "MemMap.h"
#include "Fls.h"
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "FeeExt.h"

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

const SNvM_BlockConfigType SNvM_BlockConfig[SNvM_ID_MAX]=
{
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018000,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        208    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018100,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        208    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018200,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        24    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018280,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        24    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018300,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018400,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018500,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018600,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018700,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018800,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00018900,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        20    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x00019800,    /*uint32 Base_Address*/
        0x31,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        6156    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B080,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        12    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B100,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B180,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B200,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B280,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B300,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B380,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B400,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        92    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B480,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B500,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B580,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        28    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B600,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B680,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B700,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        140    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B800,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        92    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B880,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        44    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B900,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        76    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001B980,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        92    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001BA00,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        76    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001BA80,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        188    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001BB80,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        76    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001BC00,    /*uint32 Base_Address*/
        0x01,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        76    /*uint16 Length; */
    },
    {    FLS_drive,    /*boolean Fls_EepDrv*/
        0x0001BC80,    /*uint32 Base_Address*/
        0x02,    /* uint8 Sector_Count */
        0x00000000,    /* uint32 Sector_Offset */
        212    /*uint16 Length; */
    },
};
const SNvM_Fls_Eep_fun_type SNvM_Fls_Eep_fun[No_Of_Drives]=
{
    {   NULL,    /*Std_ReturnType (*SNvM_Sector_Erase)(uint32,uint32)*/
        NULL,    /*MemIf_JobResultType (*SNvM_Status)(Void)*/
        NULL,    /*Std_ReturnType (*SNvM_Write)(uint32,uint8*,uint32)*/
        NULL    /*Std_ReturnType (*SNvM_Read)(uint32,uint8*,uint32)*/
    },
    {   FeeExt_Erase,    /*Std_ReturnType (*SNvM_Sector_Erase)(uint32,uint32)*/
        FeeExt_GetJobResult,    /*MemIf_JobResultType (*SNvM_Status)(Void)*/
        FeeExt_Write,    /*Std_ReturnType (*SNvM_Write)(uint32,uint8*,uint32)*/
        FeeExt_ReadImmediate    /*Std_ReturnType (*SNvM_Read)(uint32,uint8*,uint32)*/
    }
};

#define SNVM_CONST_SEC_END
#include "MemMap.h"

#define SNVM_DATA_SEC_END
#include "MemMap.h"

#define SNVM_CODE_SEC_END
#include "MemMap.h"


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:22 AM
****************************************************************/
