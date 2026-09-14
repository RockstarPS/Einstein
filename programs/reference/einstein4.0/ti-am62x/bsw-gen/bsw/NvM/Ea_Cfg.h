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

File Name        :  Ea_Cfg.h
Module Short Name:  Ea_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef EA_CFG_H
#define EA_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Ea_Types.h"
#include "EepDrv.h"
#include "NvM_Types.h"
#include "NvM_Cbk.h"
#include "Os.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef EA_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif

#define EaDevErrorDetect

#define EaNvmJobEndNotification
#define EaNvmJobErrorNotification
#define EaPollingMode
#define EaVersionInfoApi
#define EaVirtualPageSize

#define EA_HEADER2_SIZE         1
#define EA_HEADER1_SIZE         1
#define EA_BLOCK_OVERHEAD      (EA_HEADER1_SIZE + EA_HEADER2_SIZE)

#define EA_NUM_BLOCKS          102

#define EA_NUMBER_OF_DEVICES_SUPPORTED          1


/*---------------  Call Backs  to NVM------------------------*/

#define Ea_CbkJobEndNotification()    NvM_JobEndNotification()
#define Ea_CbkJobErrorNotification()  NvM_JobErrorNotification()

/*---------------  EA Critical Sections Macro  ------------------------*/
#define EA_ENTER_CRITICAL_SECTION()   SuspendAllInterrupts()
#define EA_EXIT_CRITICAL_SECTION()    ResumeAllInterrupts()



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
uint16  BlockBaseAddress;
uint16  BlockSize;
uint8   NoOfInstances;
uint8   BlockFlags;
uint8   DeviceIndex;
}Ea_ConfigType;

typedef struct
{
    void (*SetModeEepPointer)(MemIf_ModeType);
    Std_ReturnType (*ReadEepPointer)(uint16,uint8*,uint16);
    Std_ReturnType (*WriteEepPointer)(uint16,const uint8*, uint16);
    Std_ReturnType (*CompareEepPointer)(uint16,const uint8*, uint16);
    Std_ReturnType (*EraseEepPointer)(uint16,uint16);
    void (*CancelEepPointer)(void);
    MemIf_StatusType (*GetEepStatusPointer)(void);
    MemIf_JobResultType (*GetEepJobResultPointer)(void);
}Ea_FunctionPointerType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
EXTERN const uint8 Ea_DatasetSelectionBits;

EXTERN const Ea_FunctionPointerType Ea_DeviceFunctionPointer[EA_NUMBER_OF_DEVICES_SUPPORTED];

EXTERN const Ea_ConfigType Ea_Config[EA_NUM_BLOCKS];
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
#undef EXTERN

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 10/30/2025 10:39:38 PM
****************************************************************/
