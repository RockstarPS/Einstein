/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  Memif.h                                              *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Abstraction for EA/Fee                                *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef MEMIF_H
#define MEMIF_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemIf_Types.h"
#include "MemIf_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

extern void MemIf_SetMode(MemIf_ModeType Mode);

extern Std_ReturnType MemIf_Read(uint8 DeviceIndex,uint16 BlockNumber,uint16 BlockOffset,uint8* DataBufferPtr,uint16 Length);

extern Std_ReturnType MemIf_Write(uint8 DeviceIndex,uint16 BlockNumber,const uint8* DataBufferPtr);

extern void MemIf_Cancel(uint8 DeviceIndex);

extern MemIf_StatusType MemIf_GetStatus(uint8 DeviceIndex);

extern MemIf_JobResultType MemIf_GetJobResult(uint8 DeviceIndex);

extern Std_ReturnType MemIf_InvalidateBlock(uint8 DeviceIndex,uint16 BlockNumber);

extern void MemIf_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

extern Std_ReturnType MemIf_EraseImmediateBlock(uint8 DeviceIndex,uint16 BlockNumber);

extern void MemIf_SuspendInternalJob(void);

extern void MemIf_ResumeInternalJob(void);


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

#endif /* MEMIF_H */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
