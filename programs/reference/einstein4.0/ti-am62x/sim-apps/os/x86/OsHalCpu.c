/*-------------------------------------------------------------------------------**
**  ***************************************************************************  **
**                                                                               **
**                CONFIDENTIAL VISTEON CORPORATION                               **
**                                                                               **
**   This is an unpublished work of authorship, which contains trade             **
**   secrets, created in 2013. Visteon Corporation owns all rights to            **
**   this work and intends to maintain it in confidence to preserve              **
**   its trade secret status. Visteon Corporation reserves the right,            **
**   under the copyright laws of the United States or those of any               **
**   other country that may have jurisdiction, to protect this work              **
**   as an unpublished work, in the event of an inadvertent or                   **
**   deliberate unauthorized publication. Visteon Corporation also               **
**   reserves its rights under all copyright laws to protect this                **
**   work as a published work, when appropriate. Those having access             **
**   to this work may not copy it, use it, modify it or disclose the             **
**   information contained in it without the written authorization               **
**   of Visteon Corporation.                                                     **
**                                                                               **
**  ***************************************************************************  **
**  ***************************************************************************  **
**    File Name         :  OsHalCpu                                 			 **
**    Module Short Name :  mOs  HAL file for handling Os MPU                     **
**    Description       :  Internal File                                         **
**                                                                               **
**   Organization     :  Driver Information Software Section,                    **
**                       Visteon Software Operation                              **
**                       Visteon Corporation                                     **
**                                                                               **
**   --------------------------------------------------------------------------  **
**   Compiler Name    :  GCC                                                     **
**   Target Hardware  :  X86 STUBS				                                 **
**                                                                               **
**  ***************************************************************************  **
**-------------------------------------------------------------------------------*/

#ifndef OS_CPU_HAL_C
#define OS_CPU_HAL_C


/************************************* Includes **********************************/
#include "OsMain.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*************************************** Macros **********************************/

/********************************** Internal Data **********************************/
static void OsHalPrv_EnableFaultregisters(void);

/********************************** Internal Functions *****************************/

/*============================================================================
**
** Function Name    :   OsHal_Initialize
**
** Visibility       :   Public
**
** Description      :   Function to initialize Architecture and Fault registers
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void WindowsInit(void);
void OsHal_Initialize (void)
{
   WindowsInit();
}


static void OsCpuHal_DisableAllRegions (void)
{
}
/********************************** Extended Functions *****************************/



void OsCpuHal_EnableMPU (void)
{
	OsCpuHal_EnableGlobalMPU();
}


void OsCpuHal_DisableMPU (void)
{
	OsCpuHal_DisableGlobalMPU();
    OsCpuHal_DisableAllRegions();
}

inline void OsCpuHal_EnableGlobalMPU(void)
{
}


inline void OsCpuHal_DisableGlobalMPU(void)
{
}

inline void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig)
{
}

void osMemProtectionFault (void)
{

}

void osStartArchTimer (void)
{}

/*============================================================================
**
** Function Name    :   HardFault_ErrorHandler
**
** Visibility       :   Public
**
** Description      :   Assembly code function to store debug info during protection errors
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void HardFault_ErrorHandler(void)
{
}

/*============================================================================
**
** Function Name    :   OsHalPrv_EnableIrqSource
**
** Visibility       :   Private
**
** Description      :   Function to Enable Irq Source
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void OsHalPrv_EnableIrqSource (osuint32 IrqSrc)
{

}

/*============================================================================
**
** Function Name    :   OsHal_EnableInterruptSource
**
** Visibility       :   Public
**
** Description      :   Function to Enable Irq Source
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending)
{
 
    return E_OK;
}

/*============================================================================
**
** Function Name    :   OsHalPrv_DisableIrqSource
**
** Visibility       :   Public
**
** Description      :   Function to Disable Irq Source
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void OsHalPrv_DisableIrqSource (osuint32 IrqSrc)
{

}

/*============================================================================
**
** Function Name    :   OsHal_DisableInterruptSource
**
** Visibility       :   Public
**
** Description      :   Function to Disable Irq Source
**
** Invocation       :   Task/ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
StatusType OsHal_DisableInterruptSource (ISRType ISRID)
{
    return E_OK;
}

static void OsHalPrv_EnableFaultregisters(void)
{
    
}

void OsCpuHal_ExitPrivilegeMode(void)
{
       
} 

osbool OsCpuHal_IsOsTrapRequired(void)
{
    osbool Ret = FALSE;
    return Ret; 
}

osbool OsCpuHal_IsOsPrivilegeMode(void)
{
   osbool Ret = TRUE;
   return Ret; 
}

FUNC(void, OS_CODE) OsHal_CpuTrap(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam)
{
}
void OsCpuHal_ExitTrusted(void)
{        
} 
FUNC(void, OS_CODE) OsCpuHal_EnableAllStackAccess(void){}
FUNC(void, OS_CODE) OsCpuHal_DisableAllStackAccess(void){}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**   ------------------------------------------------------------------------------ **
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS SC3 Support - Initial Version                           **
**----------------------------------------------------------------------------------**
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**/

