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
#ifndef MEMIF_C
#define MEMIF_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemIf.h"


#define MEMIF_CODE_SEC_START
#include "MemMap.h"

#define MEMIF_DATA_SEC_START
#include "MemMap.h"

/* Used to prevent warnings about unused parameters */
#define MEMIF_UNUSED_PARAMETER(x) (void)(x)

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

void MemIf_SetMode(MemIf_ModeType Mode)
{
    MEMIF_UNUSED_PARAMETER(Mode);
}

Std_ReturnType MemIf_Read(uint8 DeviceIndex,uint16 BlockNumber,uint16 BlockOffset,uint8* DataBufferPtr,uint16 Length)
{
    Std_ReturnType ErrorStatus = E_NOT_OK;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].ReadBlockPointer != NULL)
        {
           ErrorStatus = MemIF_FunctionPointer[DeviceIndex].ReadBlockPointer(BlockNumber, BlockOffset, DataBufferPtr,Length);
        }
    }
    return ErrorStatus;
}

Std_ReturnType MemIf_Write(uint8 DeviceIndex,uint16 BlockNumber,const uint8* DataBufferPtr)
{
    Std_ReturnType ErrorStatus = E_NOT_OK;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].WriteBlockPointer != NULL)
        {
           ErrorStatus = MemIF_FunctionPointer[DeviceIndex].WriteBlockPointer(BlockNumber, DataBufferPtr);
        }
    }
    return ErrorStatus;
}

void MemIf_Cancel(uint8 DeviceIndex)
{
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].CancelPointer != NULL)
        {
           MemIF_FunctionPointer[DeviceIndex].CancelPointer();
        }
    }
}

MemIf_StatusType MemIf_GetStatus(uint8 DeviceIndex)
{
    MemIf_StatusType RetVal = MEMIF_IDLE;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].GetStatusPointer != NULL)
        {
           RetVal = MemIF_FunctionPointer[DeviceIndex].GetStatusPointer();
        }
    }
    return RetVal;
    
}

MemIf_JobResultType MemIf_GetJobResult(uint8 DeviceIndex)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].GetJobResultPointer != NULL)
        {
           RetVal = MemIF_FunctionPointer[DeviceIndex].GetJobResultPointer();
        }
    }
    return RetVal;
}

Std_ReturnType MemIf_InvalidateBlock(uint8 DeviceIndex,uint16 BlockNumber)
{
    Std_ReturnType ErrorStatus = E_NOT_OK;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].InvalidateBlockPointer != NULL)
        {
           ErrorStatus = MemIF_FunctionPointer[DeviceIndex].InvalidateBlockPointer(BlockNumber);
        }
    }
    return ErrorStatus;
}

void MemIf_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
	MEMIF_UNUSED_PARAMETER(VersionInfoPtr);
}

Std_ReturnType MemIf_EraseImmediateBlock(uint8 DeviceIndex,uint16 BlockNumber)
{
    Std_ReturnType ErrorStatus = E_NOT_OK;
    if(DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if(MemIF_FunctionPointer[DeviceIndex].EraseImmediateBlockPointer != NULL)
        {
           ErrorStatus = MemIF_FunctionPointer[DeviceIndex].EraseImmediateBlockPointer(BlockNumber);
        }
    }
    return ErrorStatus;
}

void MemIf_SuspendInternalJob(void)
{
    uint8 fl_DeviceIndex;
    for(fl_DeviceIndex = 0u; fl_DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED; fl_DeviceIndex++)
    {
        if(MemIF_FunctionPointer[fl_DeviceIndex].SuspendInternalJob != NULL)
        {
           MemIF_FunctionPointer[fl_DeviceIndex].SuspendInternalJob();
        }
    }
}

void MemIf_ResumeInternalJob(void)
{
    uint8 fl_DeviceIndex;
    for(fl_DeviceIndex = 0; fl_DeviceIndex < MEMIF_NUMBER_OF_DEVICES_SUPPORTED; fl_DeviceIndex++)
    {
        if(MemIF_FunctionPointer[fl_DeviceIndex].ResumeInternalJob != NULL)
        {
           MemIF_FunctionPointer[fl_DeviceIndex].ResumeInternalJob();
        }
    }
}
#define MEMIF_DATA_SEC_END
#include "MemMap.h"

#define MEMIF_CODE_SEC_END
#include "MemMap.h"

#endif /* MEMIF_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
