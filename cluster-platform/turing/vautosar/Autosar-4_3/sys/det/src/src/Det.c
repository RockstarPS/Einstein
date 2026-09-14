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
*  File Name         :  Det.c                                                *
*  Module Short Name :  Det                                                  *
*  Description       :  This file contains implementations of the Development*
*                       Error Trace                                          *
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
#ifndef DET_C
#define DET_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Det.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define DET_CODE_SEC_START
#include "MemMap.h"

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static uint8 Det_InitStatus = 0U;

/*============================================================================
**
** Function Name    :   Det_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global 
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   Det_ConfigType* ConfigPtr - Pointer to a configuration type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
/*MISRA 8.13 VIOLATION:pointer variable points to the non constant type but not modifying.It doesn't have any functional impact.This is the reason why the MISRA rule could not be followed in this special case. */
FUNC(void, DET_CODE_SEC_START) Det_Init(Det_ConfigType* ConfigPtr)
{
    (void)ConfigPtr;
    Det_InitStatus = DET_INIT;
}

/*============================================================================
**
** Function Name    :   Det_Start
**
** Visibility       :   Public
**
** Description      :   The Det_Start function is called to initialise the Global 
**                      and Static variables  of this module to initial/ default values.
**
** Invocation       :   
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, DET_CODE_SEC_START) Det_Start(void)
{

}

/*============================================================================
**
** Function Name    :   Det_InitMemory
**
** Visibility       :   Public
**
** Description      :   Service to initialize memory
**
** Invocation       :   
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, DET_CODE_SEC_START) Det_InitMemory(void)
{
    Det_InitStatus = DET_UNINIT;
}

/*============================================================================
**
** Function Name    :   Det_ReportError
**
** Visibility       :   Public
**
** Description      :   This function registers the Development Error reported.
**
** Invocation       :   Any configured module
**
** Inputs           :   ModuleId
**						InstanceId
**						ApiId
**						ErrorId
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    Std_ReturnType Ret = E_NOT_OK;
    if(DET_UNINIT != Det_InitStatus)
    {
        DET_REPORT_ERROR_CALLOUT(ModuleId, InstanceId, ApiId, ErrorId); /* MISRA RULE 4.9 VIOLATION:Function-like macros can take arguments, just like true functions. To define a macro that uses arguments.so,it is not a functional impact.This is the reason why the MISRA rule could not be followed in this special case */       
        Ret = E_OK;       
    }
    else
    {
        /* do nothing */
    }

    return Ret;
}

/*============================================================================
**
** Function Name    :   Det_ReportRuntimeError
**
** Visibility       :   Public
**
** Description      :   Registers configured runtime error
**
** Invocation       :   
**
** Inputs           :   ModuleId
**						InstanceId
**						ApiId
**						ErrorId
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    Std_ReturnType Ret = E_OK;
    
    return Ret;
}

/*============================================================================
**
** Function Name    :   Det_ReportTransientFault
**
** Visibility       :   Public
**
** Description      :   Service to report transient faults
**
** Invocation       :
**
** Inputs           :   ModuleId
**						InstanceId
**						ApiId
**						ErrorId
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
/*MISRA RULE 2.7 VIOLATION:function has external linkage but used in only one translation unit.It may be used by other files in future.It is not a functional impact.This is the reason why the MISRA rule could not be followed in this special case */
FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) /* MISRA RULE 8.7 VIOLATION:This is the reason why the MISRA rule could not be followed in this special case */
{
    Std_ReturnType Ret = E_OK;
            
    return (Ret);
}

/*============================================================================
**
** Function Name    :   Det_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Service to Get Det Version Info
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType
**						
**						
**						
**
** Outputs          :  void
**                     
**
** Critical Section :
**
**==========================================================================*/
#if (DET_VERSION_INFO_API == TRUE)
/*MISRA RULE 2.7 VIOLATION:function has external linkage but used in only one translation unit.It may be used by other files in future.It is not a functional impact.This is the reason why the MISRA rule could not be followed in this special case */
FUNC(void, DET_CODE_SEC_START) Det_GetVersionInfo (Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR != VersionInfo)
	{
        VersionInfo->vendorID         = DET_VENDOR_ID;
        VersionInfo->moduleID         = DET_MODULE_ID;
        VersionInfo->sw_major_version = DET_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = DET_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = DET_SW_PATCH_VERSION;
    }
    else
    {
        (void)Det_ReportError(DET_MODULE_ID,DET_INSTANCE_ID,DET_GETVERSIONINFO_API,DET_E_PARAM_POINTER);
    }
}
#endif

#define DET_CODE_SEC_STOP
#include "MemMap.h"

#endif
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
Date               : 22-Aug-2019
CDSID              : ssebast1
Traceability       : 
Change Description : Initial Framework version of Det
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 22-Aug-2022
CDSID              : psravani
Traceability       : 
Change Description : BSW General requirements update
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 14-Dec-2022
CDSID              : sjain10
Traceability       : 1790320: [Basic8_MP23] DiId_04d@4082- Identifikation nicht verfügbar
Change Description : Det_GetVersionInfo API update
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 25-Mar-2024
CDSID              : eganesan
Traceability       : DICVA-1945 : 4.3 Migration
Change Description : vAutosar 4.3 Migration
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/



