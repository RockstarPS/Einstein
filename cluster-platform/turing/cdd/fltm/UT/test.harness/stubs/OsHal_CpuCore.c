/**
 * @file        OsHal_CpuCore.c
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
#define DATA_ABORT               0x1U
#define PREFETCH_ABORT           0x2U
#define UNDEFINED_INSTRUCTION    0x4U

/********************************** Internal Data **********************************/
static void OsHalPrv_EnableFaultregisters(void);
static void OsGetDataFaultRegisters(void);
static void OsGetPrefetchFaultRegisters(void);
ProtectionErrType ProtErrorInfo;
extern OsCtrlParamType OsCtrlParam;

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
    if((osGetCPSR()&(0x1FU))==0x10U)
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
   if((osGetCPSR()&(0x1FU))==0x10U)
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
    #if 0
    osuint8 Ix = 0;
    const osuint8 MaxRegions = (osMpuGetMpuTypeAsm() >> 8) & 0xFFUL;
    for(Ix = 0; Ix < (MaxRegions - 1U); Ix++)
    {
        Os_Hal_Compiler_CortexR5F_DisableMpuRegion(Ix, OS_INT_MPU_REGION_DISABLED_VALUE);
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
#if 0
    OsCpuHal_EnableGlobalMPU();
#endif
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
FUNC(void, OS_CODE) OsCpuHal_DisableMPU (void)
{
#if 0
    Os_Hal_Compiler_CortexR5F_DisableMpu();
    OsCpuHal_DisableAllRegions();
#endif
}

/**
 * @brief OsCpuHal_EnableGlobalMPU -  Function to enable global MPU.
 *
 * @param
 *
 * @return void
 */

FUNC(void, OS_CODE) OsCpuHal_EnableGlobalMPU(void)
{
    #if 0
    Os_Hal_Compiler_CortexR5F_EnableMpu();
    #endif
}

/**
 * @brief OsCpuHal_DisableGlobalMPU -  Function to disable global MPU.
 *
 * @param
 *
 * @return void
 */
FUNC(void, OS_CODE) OsCpuHal_DisableGlobalMPU(void)
{
    #if 0
    Os_Hal_Compiler_CortexR5F_DisableMpu();
   #endif
}

/**
 * @brief OsCpuHal_MpuInitRegion -  Function to initialize MPU region.
 *
 * @param pMpuConfig
 *
 * @return void
 */
FUNC(void, OS_CODE) OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig)
{
#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
    if(osMpuIsEnabledAsm() != 0U)
    {
        OsIntMpuConfigType mpuregion;
        mpuregion.RegnNumber = pMpuConfig->RegnNumber;
        osMpuRegionDisableAsm(mpuregion.RegnNumber, OS_INT_MPU_REGION_DISABLED_VALUE);
        mpuregion.RegnBaseAddress = pMpuConfig->RegnBaseAddress;
        mpuregion.RegnSizeAndEnable = pMpuConfig->RegnSizeAndEnable;
        mpuregion.RegnAttribute = pMpuConfig->RegnAttribute;
        osMpuSetRegionAsm(mpuregion.RegnNumber, mpuregion.RegnBaseAddress,mpuregion.RegnSizeAndEnable, mpuregion.RegnAttribute);
    }
#endif
}

/**
 * @brief Service OsGetDataFaultRegisters
 * @note  Function to get data fault related registers
 * @param void
 * @return void
 */
static void OsGetDataFaultRegisters(void)
{
    ProtErrorInfo.os_faultFrame.DFSR = osGetDFSR();
    /* Check whether MMFAR has valid contents or not */
    if (((ProtErrorInfo.os_faultFrame.DFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) && ((ProtErrorInfo.os_faultFrame.DFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
        ProtErrorInfo.os_faultFrame.MMARErrAddress = osGetDFAR(); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        ProtErrorInfo.os_faultFrame.IsMMARValid = TRUE;
    }
}

/**
 * @brief Service OsGetPrefetchFaultRegisters
 * @note  Function to get prefetch fault related registers
 * @param void
 * @return void
 */
static void OsGetPrefetchFaultRegisters(void)
{
    ProtErrorInfo.os_faultFrame.IFSR = osGetIFSR();
    /* Check whether MMFAR has valid contents or not */
    if (((ProtErrorInfo.os_faultFrame.IFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) && ((ProtErrorInfo.os_faultFrame.IFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
        ProtErrorInfo.os_faultFrame.MMARErrAddress = osGetIFAR(); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        ProtErrorInfo.os_faultFrame.IsMMARValid = TRUE;
    }
}

/**
 * @brief Service OsFaultHandler
 * @note  Function to handle exception faults
 * @param void
 * @return void
 */
void OsFaultHandler(void)
{
    ProtErrorInfo.os_faultFrame.IsMMARValid = FALSE;
    ProtErrorInfo.os_faultFrame.DFSR = 0U;
    ProtErrorInfo.os_faultFrame.IFSR = 0U;
    (void)osGetTaskID((TaskRefType)&(ProtErrorInfo.CallingTask));
    ProtErrorInfo.ErrorContext = Os_GetContext();
    /* Check if Data Abort Occured */
    if(ProtErrorInfo.os_faultFrame.FaultException == DATA_ABORT)
    {
        OsGetDataFaultRegisters();
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_MEMORY;
        OsErr_osProtectionHook(ProtErrorInfo);
    }
    /* Check if Prefetch Abort Occured */
    if(ProtErrorInfo.os_faultFrame.FaultException == PREFETCH_ABORT)
    {
        OsGetPrefetchFaultRegisters();
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_MEMORY;
        OsErr_osProtectionHook(ProtErrorInfo);
    }       
    if(ProtErrorInfo.os_faultFrame.FaultException == UNDEFINED_INSTRUCTION)
    {
        ProtErrorInfo.ProtectionError = E_OS_PROTECTION_EXCEPTION;
        OsErr_osProtectionHook(ProtErrorInfo);
    }
}

/**
 * @brief Service osPrefetchAbortHandler
 * @note  osPrefetchAbortHandler
 * @param void
 * @return void
 */
void osPrefetchAbortHandler (void)
{
    ProtErrorInfo.os_faultFrame.IsMMARValid = FALSE;
    ProtErrorInfo.os_faultFrame.DFSR = 0U;
    (void)osGetTaskID((TaskRefType)&(ProtErrorInfo.CallingTask));
    ProtErrorInfo.ErrorContext = Os_GetContext(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    ProtErrorInfo.os_faultFrame.IFSR = osGetIFSR();
    ProtErrorInfo.ProtectionError = E_OS_PROTECTION_MEMORY;
    /* Check whether MMFAR has valid contents or not */
    if (((ProtErrorInfo.os_faultFrame.IFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) && ((ProtErrorInfo.os_faultFrame.IFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
        ProtErrorInfo.os_faultFrame.MMARErrAddress = osGetIFAR(); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        ProtErrorInfo.os_faultFrame.IsMMARValid = TRUE;
    }
    OsErr_osProtectionHook(ProtErrorInfo);
}

/**
 * @brief Service osDataAbortExpHandler
 * @note  osDataAbortExpHandler
 * @param void
 * @return void
 */
void osDataAbortExpHandler (void)
{
    ProtErrorInfo.os_faultFrame.IsMMARValid = FALSE;
    ProtErrorInfo.os_faultFrame.IFSR = 0U;
    (void)osGetTaskID((TaskRefType)&(ProtErrorInfo.CallingTask));
    ProtErrorInfo.ErrorContext = Os_GetContext(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    ProtErrorInfo.os_faultFrame.DFSR = osGetDFSR();
    ProtErrorInfo.ProtectionError = E_OS_PROTECTION_MEMORY;
    /* Check whether MMFAR has valid contents or not */
    if (((ProtErrorInfo.os_faultFrame.DFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) && ((ProtErrorInfo.os_faultFrame.DFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
        ProtErrorInfo.os_faultFrame.MMARErrAddress = osGetDFAR(); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        ProtErrorInfo.os_faultFrame.IsMMARValid = TRUE;
    }
    OsErr_osProtectionHook(ProtErrorInfo);
}

/**
 * @brief Service osUndefinedInstructionException
 * @note  osUndefinedInstructionException
 * @param void
 * @return void
 */
void osUndefExceptionHandler (void)
{
    ProtErrorInfo.os_faultFrame.IsMMARValid = FALSE;
    ProtErrorInfo.os_faultFrame.IFSR = 0U;
    ProtErrorInfo.os_faultFrame.DFSR = 0U;
    (void)osGetTaskID((TaskRefType)&(ProtErrorInfo.CallingTask));
    ProtErrorInfo.ErrorContext = Os_GetContext(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    ProtErrorInfo.ProtectionError = E_OS_PROTECTION_EXCEPTION;
    OsErr_osProtectionHook(ProtErrorInfo);
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
    __asm__ volatile(  "stmfd      sp!,{r0-r10,lr} \n"   /* push to caller stack */
            "mov        r4, #1 \n"
            "svc #1 \n"
            "ldmfd      sp!,{r0-r10,lr} \n"
        );
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

