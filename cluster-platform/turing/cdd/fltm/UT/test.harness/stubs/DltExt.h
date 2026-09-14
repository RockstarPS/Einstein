/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
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
*  File Name         :  DltExt.h                                            *
*  Module Short Name :  DltExt_H                                            *
*  Description       :                                                       *
*                                                                            *
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

#ifndef DLTEXT_H
#define DLTEXT_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "DltExt_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define DLT_E_ARM_NMI_EVENT                                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x01u)))
#define DLT_E_ARM_HARD_FAULT                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x02u)))
#define DLT_E_ARM_MEMMANAGE_FAULT                                  (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x03u)))           
#define DLT_E_ARM_BUS_FAULT                                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x04u)))
#define DLT_E_ARM_USAGE_FAULT                                      (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x05u)))
#define DLT_E_ARM_DEBUG_MONITOR                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x06u)))
#define DLT_E_ARM_PENDING_SV                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0x07u)))
#define DLT_E_ARM_UNDEFINED_INSTRUCTION                            (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0xF1u)))
#define DLT_E_ARM_SUPERVISOR_CALL                              	   (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0xF2u)))
#define DLT_E_ARM_PREFETCH_ABORT                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0xF3u)))  
#define DLT_E_ARM_DATA_ABORT                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_ARM_ERROR         ,(0xF4u))) 
#define DLT_NVM_E_HARDWARE                                         (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x01u)))
#define DLT_NVM_E_INTEGRITY_FAILED                                 (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x02u)))
#define DLT_E_NVM_REQ_FAILED                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x03u)))           
#define DLT_E_NVM_WRONG_BLOCK_ID                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x04u)))
#define DLT_E_NVM_VERIFY_FAILED                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x05u)))
#define DLT_E_NVM_LOSS_OF_REDUNDANCY                               (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x06u)))
#define DLT_E_NVM_WRITE_FAILED                                     (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x07u)))
#define DLT_E_NVM_READ_FAILED                                      (DLT_MAKE_FAULT_CODE(DLT_FAULT_NVM_ERROR         ,(0x08u)))
#define DLT_RESET_UNDEFINED                                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x00u)))
#define DLT_POWER_ON_RESET                                         (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x01u)))

#if(defined(DLTEXT_PLATFORM_IMX8) && (DLTEXT_PLATFORM_IMX8 == STD_ON))
    #define DLT_JTAG_RESET                                   	       (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x02u)))
    #define DLT_PARTITION_WDOG_RESET                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x03u)))           
    #define DLT_SCU_LOCKUP_RESET                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x04u)))
    #define DLT_SNVS_RESET                                             (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x05u)))
    #define DLT_TEMP_PANIC_RESET                               		   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x06u)))
    #define DLT_MSI_RESET                                     		   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x07u)))
    #define DLT_ECC_RESET                                     		   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x08u)))
    #define DLT_SCFW_WDOG_RESET                         			   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x0Au)))  
    #define DLT_SCU_ROM_WDOG_RESET                     	               (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x0Bu)))  
    #define DLT_SECO_RESET                         					   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x0Cu)))  
    #define DLT_SCFW_FAULT_RESET                                	   (DLT_MAKE_FAULT_CODE(DLT_FAULT_HW_RESET         ,(0x0Du)))
#elif(defined(DLTEXT_PLATFORM_TRAVEO2) && (DLTEXT_PLATFORM_TRAVEO2 == STD_ON))
    #define DLT_XRES_L                                                 (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x02u)))
    #define DLT_BOD                                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x03u)))
    #define DLT_OVD                                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x04u)))
    #define DLT_OCD                                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x05u)))
    #define DLT_HIB_WAKEUP                                             (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x06u)))
    #define DLT_CDBGRSTREQ                                             (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x07u)))
    #define DLT_FAULT                                                  (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x08u)))
    #define DLT_WDT                                                    (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x09u)))
    #define DLT_MCWDT                                                  (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x0Au)))
    #define DLT_CSV_HF                                                 (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x0Bu)))
    #define DLT_CSV_REF                                                (DLT_MAKE_FAULT_CODE(DLT_FAULT_TRAVEO_ERROR         ,(0x0Cu)))
#endif

#define DLT_DET_ERROR                                              (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET     ,(0x01u)))
#define DLT_WDGM_ALIVE_SUPERVISION_FAILURE                         (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET     ,(0x02u)))
#define DLT_FLS_TST_ERROR                                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET     ,(0x07u)))
#define DLT_EARLY_WAKEUP                                           (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET     ,(0x08u)))
#define DLT_E_OS_ACCESS                                            (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x01u)))
#define DLT_E_OS_CALLEVEL                                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x02u)))
#define DLT_E_OS_ID                                                (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x03u)))           
#define DLT_E_OS_LIMIT                                             (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x04u)))
#define DLT_E_OS_NOFUNC                                            (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x05u)))
#define DLT_E_OS_RESOURCE                                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x06u)))
#define DLT_E_OS_STATE                              			   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x07u)))
#define DLT_E_OS_VALUE                                  	       (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x08u)))
#define DLT_E_OS_SERVICEID                                     	   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x09u)))
#define DLT_E_OS_ILLEGAL_ADDRESS                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Au)))  
#define DLT_E_OS_MISSINGEND                                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Bu)))  
#define DLT_E_OS_DISABLEDINT                                       (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Cu)))  
#define DLT_E_OS_STACKFAULT                                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Du)))  
#define DLT_E_OS_PROTECTION_MEMORY                                 (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Eu)))
#define DLT_E_OS_PROTECTION_TIME                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x0Fu))) 
#define DLT_E_OS_PROTECTION_ARRIVAL                                (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x10u))) 
#define DLT_E_OS_PROTECTION_LOCKED                                 (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x11u)))
#define DLT_E_OS_PROTECTION_EXCEPTION                              (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x12u)))
#define DLT_E_OS_INTERFERENCE_DEADLOCK                             (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x13u)))
#define DLT_E_OS_NESTING_DEADLOCK                                  (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x14u)))
#define DLT_E_OS_SPINLOCK                                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x15u)))
#define DLT_E_OS_CORE                                              (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x16u)))
#define DLT_E_OS_PARAM_POINTER                                     (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x17u)))
#define DLT_E_OS_SHUTDOWN                                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0x18u)))
#define DLT_E_OS_SYS_API_ERROR                                     (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF0u)))
#define DLT_E_OS_SYS_ASSERTION                                     (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF1u)))
#define DLT_E_OS_SYS_DISABLED                                      (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF1u)))
#define DLT_E_OS_SYS_NO_BARRIER_PARTICIPANT                        (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF2u)))
#define DLT_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF3u)))
#define DLT_E_OS_SYS_NO_NTFSTACK                                   (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF4u)))
#define DLT_E_OS_SYS_OVERFLOW                                      (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF5u)))
#define DLT_E_OS_SYS_KILL_KERNEL_OBJ                               (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF6u)))
#define DLT_E_OS_SYS_NO_RESTARTTASK                                (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF7u)))
#define DLT_E_OS_SYS_CALL_NOT_ALLOWED                              (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF8u)))
#define DLT_E_OS_SYS_FUNCTION_UNAVAILABLE                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xF9u)))
#define DLT_E_OS_SYS_PROTECTION_SYSCALL                            (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xFAu)))
#define DLT_E_OS_SYS_PROTECTION_IRQ                                (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xFBu)))
#define DLT_E_OS_SYS_OVERLOAD                                      (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xFEu)))
#define DLT_E_OS_SYS_CROSS_CORE_REQUESTED                          (DLT_MAKE_FAULT_CODE(DLT_FAULT_OS_ERROR         ,(0xFFu)))

/*****************************************************************************
*                            Function Prototypes                             *
******************************************************************************/ 
/*============================================================================
**
** Function Name    :   DltExt_Init
**
** Visibility       :   Public
**
** Description      :
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
void DltExt_Init(void);

#endif /* DLTEXT_H */
