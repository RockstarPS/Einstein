/**
 * @file        OsHalCpu.h
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
 * @details     <b>Internal header which has cpu specific definitions</b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */
 #ifndef OS_CPU_HAL_H
 #define OS_CPU_HAL_H
 
 #include "OsTypes.h"
 #define OsCpuHal_EnterPrivilegeMode()  __asm("svc #1")  
 /** The Fault configuration structure. */
 
 #define R0_Pos              (0u)    /**< Position of R0  content in fault structure */
 #define R1_Pos              (1u)    /**< Position of R1  content in fault structure */
 #define R2_Pos              (2u)    /**< Position of R2  content in fault structure */
 #define R3_Pos              (3u)    /**< Position of R3  content in fault structure */
 #define R12_Pos             (4u)    /**< Position of R12 content in fault structure */
 #define LR_Pos              (5u)    /**< Position of LR  content in fault structure */
 #define PC_Pos              (6u)    /**< Position of PC  content in fault structure */
 #define PSR_Pos             (7u)    /**< Position of PSR content in fault structure */
 
 # define OS_INT_INTC_CPUSS_CM7_SYSTEM_BASE            (0x4020A000uL)
 # define OS_INT_CPUSS_CM7_SYSTEM_INT_CTL(x)           (*(volatile uint32*) (OS_INT_INTC_CPUSS_CM7_SYSTEM_BASE + ((x) * 4UL))) /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 # define OS_INT_INTC_SYSTEM_INT_CL_ENABLED_BIT        (1uL << 31)
 
 #define OS_SYST_CSR                                    (*((volatile osuint32*)(0xE000E010U)))    
 #define OsDisableSystickInt()                          (OS_SYST_CSR&=~(1uL<<1)) /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 #define OsEnableSystickInt()                           (OS_SYST_CSR|=(1uL<<1)) /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 
 #define CM7_SCS_SHCSR       (*(volatile uint32*) (0xE000ED24uL))
 
 #define CM7_CFSR_REGISTER        (*(volatile uint32*) (0xE000ED28uL)) /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 #define IMPRECIS_ERROR 1024uL
 
 /*ProtectionHook error macros*/
 #define MMARVALID     (0x80U)
 #define MPU_FAULT     (0x3BU)
 #define USAGE_FAULT   (0x30F0000U)
 #define BUS_FAULT     (0x3F00U)
 #define BFARVALID     (0x8000U)
 
 typedef struct
 {
     osuint32 r0;               /**< R0 register content */
     osuint32 r1;               /**< R1 register content */
     osuint32 r2;               /**< R2 register content */
     osuint32 r3;               /**< R3 register content */
     osuint32 r12;              /**< R12 register content */
     osuint32 lr;               /**< LR register content */
     osuint32 pc;               /**< PC register content */
     osuint32 psr;              /**< PSR register content */
     osuint32 cfsr;             /**< CFSR register content */
     osbool   IsMMARValid;      /**< IS MMAR valid */
     osbool   IsBFARValid;      /**< IS BFAR valid */
     osuint32 MMARErrAddress;   /**< MMAR Error address */
     osuint32 BFARErrAddress;   /**< MMAR Error address */
 } ProtErrorInfoType;
 
 typedef struct
 {
       osuint32 RegnNumber;           /*  Region number (MPU_RNR). */
       osuint32 RegnBaseAddress;      /*  Region base address (MPU_RBAR). */
       osuint32 RegnSize;
       AccessType RegnAccess;
       osuint32 RegnAttribute;        /*  Region attributes */     
       osuint32 RegnSizeAndEnable;    /* 0 bit : Enable/Disable, [1:5] - Region size, [8:15] - Sub region Disable */     
 }OsIntMpuConfigType;
 
 
 extern void OsCpuHal_EnableMPU (void);
 extern osbool OsCpuHal_IsOsTrapRequired(void);
 extern void OsCpuHal_ExitPrivilegeMode(void); 
 extern osbool OsCpuHal_IsOsPrivilegeMode(void);
 
 extern void OsCpuHal_DisableMPU (void);
 extern void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig);
 extern void OsCpuHal_DisableGlobalMPU(void);
 extern void OsCpuHal_EnableGlobalMPU(void);
 extern void OsCpuHal_EnableAllStackAccess(void);
 extern void OsCpuHal_DisableAllStackAccess(void);
 extern osuint32 osGetPRIMASK(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 extern osuint32 osGetBASEPRI(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 
 extern void OsHal_Initialize (void);
 extern void OsHalPrv_EnableIrqSource (osuint32 IrqSrc);
 extern void OsHalPrv_DisableIrqSource (osuint32 IrqSrc);
 
 void OsFaultHandler(osuint32 const *faultStackAddr);
 void Os_ProcessingFault(void);
 
 extern void OsHal_CpuTrap(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam);
 
 osuint32 osMpuIsEnabledAsm(void);
 void osMpuEnableAsm(void);
 void osMpuRegionDisableAsm(osuint32 RegionId, osuint32 RegionDisableValue);
 void osMpuSetRegionAsm(osuint32 regionId, osuint32 regionBaseAddr, osuint32 sizeAndEnble, osuint32 regionAttrs);
 #define OsCpuHal_MpuSwitch(x)       OsCpuHal_MpuInitRegion(x)
 
 #define osIsGlobalIntEnabled()    ((osGetCPSR() & osdIntIrqBitCheck) == 0U) /*NCHELLAP : Modified for Global interrupt check*/
 
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
 **----------------------------------------------------------------------------------*/
 