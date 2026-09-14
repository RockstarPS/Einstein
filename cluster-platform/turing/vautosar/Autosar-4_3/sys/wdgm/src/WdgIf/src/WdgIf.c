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
*  File Name         :  WdgIf.h                                              *
*  Module Short Name :  WdgIf                                                *
*  VOBName           :                                                       *
*  Author            :                                                       *
*  Description       : Abstraction for WdgIf                                 *
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
#ifndef WDGIF_C
#define WDGIF_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "WdgIf.h"
#include "Det.h"

#define WDGIF_CODE_SEC_START
#include "MemMap.h"

#define WDGIF_DATA_SEC_START
#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
static FUNC(void, WDGIF_CODE_SEC_START) WdgIf_Det_ReportError(uint8 ApiId, uint8 ErrorId);
P2CONST(WdgIf_FunctionPointerType, AUTOMATIC, WDGIF_CODE_SEC_START) PWdgIfTrigger;
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
#if (WDGIF_VERSION_INFO_API == TRUE)
/*============================================================================
**
** Function Name    :   WdgIF_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Returns the version information 
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType * VersionInfo - Pointer to a VErsion Info type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGIF_CODE_SEC_START) WdgIf_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR != VersionInfo)
    {
        VersionInfo->vendorID         = (uint16)WDGIF_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)WDGIF_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)WDGIF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)WDGIF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)WDGIF_SW_PATCH_VERSION;
    }
	else 
	{
		WdgIf_Det_ReportError(WDGIF_VERSIONINFO_API,WDGIF_E_INV_POINTER);
	}
}
#endif

FUNC(void, WDGIF_CODE_SEC_START) WdgIf_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout)
{
    if(DeviceIndex < WDGIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        PWdgIfTrigger = &WdgIF_FunctionPointer[DeviceIndex];
        if(PWdgIfTrigger->SetTriggerPointer != NULL)
        {
            PWdgIfTrigger->SetTriggerPointer(Timeout);
        }
	}	
    else
    {
		WdgIf_Det_ReportError(WDGIF_SETTRIGGERCONDITION_API,WDGIF_E_PARAM_DEVICE);
    }
}


FUNC(Std_ReturnType, WDGIF_CODE_SEC_START) WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode)
{
	Std_ReturnType ModeStatus = E_NOT_OK;
    if(DeviceIndex < WDGIF_NUMBER_OF_DEVICES_SUPPORTED)
    {
        PWdgIfTrigger = &WdgIF_FunctionPointer[DeviceIndex];
        if(PWdgIfTrigger->SetModePointer != NULL)
        {
            ModeStatus = PWdgIfTrigger->SetModePointer(WdgMode);
        }
    }
    else
    {
		WdgIf_Det_ReportError(WDGIF_SETMODE_API,WDGIF_E_PARAM_DEVICE);    
    }
    return ModeStatus;   

}

static FUNC(void, WDGIF_CODE_SEC_START) WdgIf_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    #if (WDGIF_DEV_ERROR_DETECT == TRUE)
    (void)Det_ReportError(WDGIF_MODULE_ID,WDGIF_INSTANCE_ID,ApiId, ErrorId);
    #endif
}


#define WdgIf_DATA_SEC_END
#include "MemMap.h"

#define WdgIf_CODE_SEC_END
#include "MemMap.h"

#endif /* WdgIf_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/*---------------------------------------------------------------------------
Date               : 08-Aug-2021
CDSID              : praj1
Traceability       : RTC #1407725
Change Description : wdg two device set trigger update.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 27-May-2022
CDSID              : eganesan
Traceability       : RTC #1671485
Change Description : Bsw general requirement.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 06-Jun-2022
CDSID              : nchellap
Traceability       : RTC #1683740
Change Description : Added new line at end of file to fix compiler warning.
-----------------------------------------------------------------------------*/


