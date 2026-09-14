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
**    File Name         :  OsHalMemProtection.c                                  **
**    Module Short Name :  mOs  HAL file for handling Os MPU                     **
**    Description       :  Internal File                                         **
**                                                                               **
**   Organization     :  Driver Information Software Section,                    **
**                       Visteon Software Operation                              **
**                       Visteon Corporation                                     **
**                                                                               **
**   --------------------------------------------------------------------------  **
**   Compiler Name    :  GHS                                                     **
**   Target Hardware  :  Platform Independent                                    **
**                                                                               **
**  ***************************************************************************  **
**-------------------------------------------------------------------------------*/

#ifndef OS_CPU_HAL_C
#define OS_CPU_HAL_C


/************************************* Includes **********************************/
#include "OsMain.h"
#include "OsPrivate.h"


#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*************************************** Macros **********************************/

/********************************** Internal Data **********************************/


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
void OsHal_Initialize (void)
{
    OS_ARCH_INITIALIZE();
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
/*To be implemented*/
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
/*To be implemented*/
}


static void OsCpuHal_DisableAllRegions (void)
{
    #if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
    osuint8 Ix;
    const osuint8 MaxRegions = (OS_INT_MPU_MPU_TYPE >> 8) & 0xFFUL;
    
    for(Ix = 0; Ix < (MaxRegions - 1); Ix++)
    {
        OS_INT_MPU_MPU_RNR = Ix;
        OS_INT_MPU_MPU_RASR = OS_INT_MPU_REGION_DISABLED_VALUE;
    }
    #endif
}
/**
 * @brief OsCpuHal_IsOsTrapRequired -  Function to check user mode enabled or not.
 *
 * @param
 *
 * @return osbool
 */

osbool OsCpuHal_IsOsTrapRequired(void)
{
   osbool Ret = FALSE;
   return Ret;     

}

/**
 * @brief OsCpuHal_IsOsPrivilegeMode -  Function to check user mode enabled or not.
 *
 * @param
 *
 * @return osbool
 */
 
osbool OsCpuHal_IsOsPrivilegeMode(void)
{
   osbool Ret = TRUE;
   return Ret; 
}

/**
 * @brief OsCpuHal_ExitPrivilegeMode -  Function to switch from Privilege mode to user mode.
 *
 * @param
 *
 * @return void
 */

void OsCpuHal_ExitPrivilegeMode(void)
{
    /*User mode is not supported in m0p. To be implemented once user mode is supported.*/        
} 

void HardFault_Handler(void)
{
     while(1);//Infinite loop is placed when hard fault occurs
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
    #if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
    osuint32 MpuCtrl = (OS_INT_MPU_MPU_CTRL | (OS_INT_MPU_MPU_CTRL_ENABLE | /*OS_INT_MPU_MPU_CTRL_PRIVDEFENA*/0));
    //Enable MPU
    OS_INT_MPU_MPU_CTRL = MpuCtrl;
    __asm("DSB");
    __asm("ISB");
    #endif
}



inline void OsCpuHal_DisableGlobalMPU(void)
{
    #if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
    osuint32 MpuCtrl = (OS_INT_MPU_MPU_CTRL & (~OS_INT_MPU_MPU_CTRL_ENABLE));
    __asm("DMB");                   //Make sure outstanding transfers are complete
   __asm("DSB");
    OS_INT_MPU_MPU_CTRL = MpuCtrl;  //Clear the enable bit
   __asm("ISB");
   #endif
}

inline void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig)
{
    OS_INT_MPU_MPU_RNR = pMpuConfig->RegnNumber;
    OS_INT_MPU_MPU_RASR = OS_INT_MPU_REGION_DISABLED_VALUE;
    OS_INT_MPU_MPU_RBAR = pMpuConfig->RegnBaseAddress;
    OS_INT_MPU_MPU_RASR = pMpuConfig->RegnAttribute | pMpuConfig->RegnSizeAndEnable;
}

/**
 * @brief OsHal_CpuTrap - Handles CPU traps.
 *
 * @param FnIndex The index of the trap function to call.
 * @param FnParam A reference to the trap function parameters.
 *
 * @return void
 */
FUNC(void, OS_CODE) OsHal_CpuTrap(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam)
{
    /* Trap implementation is not required since M0P supports only privilege mode */
}

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
**   ------------------------------------------------------------------------------ **
**   Date              : 06-02-2025                                                 **
**   CDSID             : nchellap                                                   **
**   JIRA Id           : PFM32897-377                                               **
**   Change Description: MPU changes updated with latest tag for cortexm0p          **
**----------------------------------------------------------------------------------**/
