/**
 * @file        OsHalMemProtection.c
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @details     <b>Internal File</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_CPU_HAL_C
#define OS_CPU_HAL_C


/************************************* Includes **********************************/
#include "OsPrivate.h"
#include "OsMain.h"
#include "AssertLib.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*************************************** Macros **********************************/

/********************************** Internal Data **********************************/
static void OsHalPrv_EnableFaultregisters(void);
ProtectionErrType ProtErrorInfo;
extern OsCtrlParamType OsCtrlParam;
extern TickType osCounter[osMaxCounterId];

/********************************** Internal Functions *****************************/
/**
 * @brief OsHal_Initialize -  Function to initialize Architecture and Fault registers
 *
 * @param
 *
 * @return void
 */

void OsHal_Initialize (void)
{
    OS_ARCH_INITIALIZE(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    OsHalPrv_EnableFaultregisters();
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
    if((osGetCONTROL()&(1U))==1U)
    {
            Ret =TRUE;   
    }
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
     osExitPrivilegeModeAsm();        
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
   if((osGetCONTROL()&(1U))==1U)
   {
        Ret =FALSE;   
   }
   return Ret; 
}

/**
 * @brief OsCpuHal_DisableAllRegions -  Function to disable all regions.
 *
 * @param
 *
 * @return void
 */
 
static void OsCpuHal_DisableAllRegions (void)
{
    #if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
    osuint8 Ix = 0;
    const osuint8 MaxRegions = (OS_INT_MPU_MPU_TYPE >> 8) & 0xFFUL; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    
    for(Ix = 0; Ix < (MaxRegions - 1U); Ix++)
    {
        OS_INT_MPU_MPU_RNR = Ix;
        OS_INT_MPU_MPU_RASR = OS_INT_MPU_REGION_DISABLED_VALUE;
    }
    #endif
}
/********************************** Extended Functions *****************************/

/**
 * @brief OsCpuHal_EnableMPU -  Function to enable MPU.
 *
 * @ref   OsCpuHal_EnableGlobalMPU
 *
 * @param
 *
 * @return void
 */

void OsCpuHal_EnableMPU (void)
{
	OsCpuHal_EnableGlobalMPU();
}

/**
 * @brief OsCpuHal_DisableMPU -  Function to disable MPU.
 *
 * @ref   OsCpuHal_DisableGlobalMPU
 *
 * @param
 *
 * @return void
 */

void OsCpuHal_DisableMPU (void)
{
	OsCpuHal_DisableGlobalMPU();
    OsCpuHal_DisableAllRegions();
}

/**
 * @brief OsCpuHal_EnableGlobalMPU -  Function to enable global MPU.
 *
 * @param
 *
 * @return void
 */

inline void OsCpuHal_EnableGlobalMPU(void)
{
#if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
	osuint32 MpuCtrl = (OS_INT_MPU_MPU_CTRL | (OS_INT_MPU_MPU_CTRL_ENABLE | OS_INT_MPU_MPU_CTRL_PRIVDEFENA)); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    //Enable MPU
    OS_INT_MPU_MPU_CTRL = MpuCtrl;
    __asm("DSB"); /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    __asm("ISB"); /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#endif
}

/**
 * @brief OsCpuHal_DisableGlobalMPU -  Function to disable global MPU.
 *
 * @param
 *
 * @return void
 */

inline void OsCpuHal_DisableGlobalMPU(void)
{
#if (STD_OFF != OS_CFG_MEMORY_PROTECTION)
	osuint32 MpuCtrl = (OS_INT_MPU_MPU_CTRL & (~OS_INT_MPU_MPU_CTRL_ENABLE)); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    __asm("DMB");                   /*Make sure outstanding transfers are complete.*/

   __asm("DSB"); /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    OS_INT_MPU_MPU_CTRL = MpuCtrl;  //Clear the enable bit
   __asm("ISB"); /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#endif
}

/**
 * @brief OsCpuHal_MpuInitRegion -  Function to initialize MPU region.
 *
 * @param pMpuConfig
 *
 * @return void
 */

inline void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig)
{
    /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    OS_INT_MPU_MPU_RNR = pMpuConfig->RegnNumber;
    OS_INT_MPU_MPU_RASR = OS_INT_MPU_REGION_DISABLED_VALUE;
    OS_INT_MPU_MPU_RBAR = pMpuConfig->RegnBaseAddress;
    OS_INT_MPU_MPU_RASR = pMpuConfig->RegnAttribute | pMpuConfig->RegnSizeAndEnable;
}


/**
 * @brief Os_ProcessingFault -  Handles the protection errors reported from interrupt vector.
 *
 * @param
 *
 * @return void
 */

void Os_ProcessingFault(void)
{
    ProtErrorInfo.os_faultFrame.IsMMARValid = FALSE;
    ProtErrorInfo.os_faultFrame.IsBFARValid = FALSE;

    /* MemManage Status Register, MMFSR */
    if((ProtErrorInfo.os_faultFrame.cfsr & MPU_FAULT) > 0U )
    {
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_MEMORY;

        /* Check whether MMFAR has valid contents or not */
        if ((ProtErrorInfo.os_faultFrame.cfsr & MMARVALID) > 0U)
        {
            ProtErrorInfo.os_faultFrame.MMARErrAddress = SCB->MMFAR; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            ProtErrorInfo.os_faultFrame.IsMMARValid = TRUE;
        }

        OsErr_osProtectionHook(ProtErrorInfo);
    }


    /* UsageFault Status Register, UFSR */
    if((ProtErrorInfo.os_faultFrame.cfsr & USAGE_FAULT) > 0U )
    {
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_EXCEPTION;
        OsErr_osProtectionHook(ProtErrorInfo);
    }


    /* BusFault Status Register, UFSR */
    if((ProtErrorInfo.os_faultFrame.cfsr & BUS_FAULT) > 0U )
    {
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_EXCEPTION;

        /* Check whether BFAR has valid contents or not */
        if ((ProtErrorInfo.os_faultFrame.cfsr & BFARVALID) > 0U)
        {
            ProtErrorInfo.os_faultFrame.BFARErrAddress = SCB->BFAR; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            ProtErrorInfo.os_faultFrame.IsBFARValid = TRUE;
        }

        OsErr_osProtectionHook(ProtErrorInfo);
    }
}

/**
 * @brief OsFaultHandler - Handles the protection errors reported from interrupt vector.
 *
 * @param faultStackAddr
 *
 * @return void
 */

void OsFaultHandler(osuint32 const *faultStackAddr)
{
    ProtErrorInfoType* ProtFaultFrame = &ProtErrorInfo.os_faultFrame;
    /* Stores the Configurable Fault Status Register state with the fault cause */
    ProtFaultFrame->cfsr = SCB->CFSR; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    /* Check if exception frame is valid and no error during exception entry of memfault or busfault */
    if(((ProtFaultFrame->cfsr & (1UL << 4U)) != 0U) || ((ProtFaultFrame->cfsr & (1UL << 12U)) != 0U))
    {
        /* Registers data are not valid */
        ProtFaultFrame->r0  = 0xDEADC0DEU;
        ProtFaultFrame->r1  = 0xDEADC0DEU;
        ProtFaultFrame->r2  = 0xDEADC0DEU;
        ProtFaultFrame->r3  = 0xDEADC0DEU;
        ProtFaultFrame->r12 = 0xDEADC0DEU;
        ProtFaultFrame->lr  = 0xDEADC0DEU;
        ProtFaultFrame->pc  = 0xDEADC0DEU;
        ProtFaultFrame->psr = 0xDEADC0DEU;
        ProtFaultFrame->IsExcFrameValid = FALSE;
    }
    else
    {
        /* Stores valid general registers */
        ProtFaultFrame->r0  = faultStackAddr[R0_Pos];
        ProtFaultFrame->r1  = faultStackAddr[R1_Pos];
        ProtFaultFrame->r2  = faultStackAddr[R2_Pos];
        ProtFaultFrame->r3  = faultStackAddr[R3_Pos];
        ProtFaultFrame->r12 = faultStackAddr[R12_Pos];
        ProtFaultFrame->lr  = faultStackAddr[LR_Pos];
        ProtFaultFrame->pc  = faultStackAddr[PC_Pos];
        ProtFaultFrame->psr = faultStackAddr[PSR_Pos];
        ProtFaultFrame->IsExcFrameValid = TRUE;
    }
    (void)osGetTaskID((TaskRefType)&(ProtErrorInfo.CallingTask));
    ProtErrorInfo.ErrorContext = Os_GetContext(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    Os_ProcessingFault();
    /* Enter Shutdown if the exception frame is not valid and user ignores error */
    if(ProtFaultFrame->IsExcFrameValid == FALSE)
    {
        osShutdownOS(ProtErrorInfo.ProtectionError);
    }
}
                                      
/**
 * @brief OsHalPrv_EnableIrqSource - Function to Enable Irq Source.
 *
 * @param IrqSrc
 *
 * @return void
 */

void OsHalPrv_EnableIrqSource (osuint32 IrqSrc)
{
    OS_INT_CPUSS_CM7_SYSTEM_INT_CTL(IrqSrc) |= OS_INT_INTC_SYSTEM_INT_CL_ENABLED_BIT;
}

/**
 * @brief OsHalPrv_DisableIrqSource - Function to Disable Irq Source.
 *
 * @param IrqSrc
 *
 * @return void
 */

void OsHalPrv_DisableIrqSource (osuint32 IrqSrc)
{
    OS_INT_CPUSS_CM7_SYSTEM_INT_CTL(IrqSrc) &= (~(OS_INT_INTC_SYSTEM_INT_CL_ENABLED_BIT));
}

/**
 * @brief OsHalPrv_EnableFaultregisters - Function to enable fault registers.
 *
 * @param
 *
 * @return void
 */

static void OsHalPrv_EnableFaultregisters(void)
{
    CM7_SCS_SHCSR |= BUS_MEM_USAGE_FAULT_ENABLE; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
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
    __asm(  "stmfd      sp!,{r0-r10,lr} \n"   /* push to caller stack */
            "svc #1 \n"
            "ldmfd      sp!,{r0-r10,lr} \n"
        );
}

/**
 * @brief OsCpuHal_ExitTrusted -  Function to exit privilege mode.
 *
 * @param
 *
 * @return void
 */

void OsCpuHal_ExitTrusted(void)
{
    osExitPrivilegeModeAsm();        
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
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**   ------------------------------------------------------------------------------ **
**   Date              : 27-June-2022                                               **
**   CDSID             : pmathew                                                    **
**   RTC Id            : 1586146                                                    **
**   Change Description: mOS updations for supporting user mode                     **
**----------------------------------------------------------------------------------**/

