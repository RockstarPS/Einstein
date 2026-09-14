/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CFltMExt_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <CFltMExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CFLTMEXT_TYPE_H
# define _RTE_CFLTMEXT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#  endif

#  ifndef eCmpCmd_DeActivate
#   define eCmpCmd_DeActivate (3U)
#  endif

#  ifndef E_OS_ACCESS
#   define E_OS_ACCESS (65281U)
#  endif

#  ifndef E_OS_CALLLEVEL
#   define E_OS_CALLLEVEL (65282U)
#  endif

#  ifndef E_OS_ID
#   define E_OS_ID (65283U)
#  endif

#  ifndef E_OS_LIMIT
#   define E_OS_LIMIT (65284U)
#  endif

#  ifndef E_OS_NOFUNC
#   define E_OS_NOFUNC (65285U)
#  endif

#  ifndef E_OS_RESOURCE
#   define E_OS_RESOURCE (65286U)
#  endif

#  ifndef E_OS_STATE
#   define E_OS_STATE (65287U)
#  endif

#  ifndef E_OS_VALUE
#   define E_OS_VALUE (65288U)
#  endif

#  ifndef E_OS_SERVICEID
#   define E_OS_SERVICEID (65289U)
#  endif

#  ifndef E_OS_ILLEGAL_ADDRESS
#   define E_OS_ILLEGAL_ADDRESS (65290U)
#  endif

#  ifndef E_OS_MISSINGEND
#   define E_OS_MISSINGEND (65291U)
#  endif

#  ifndef E_OS_DISABLEDINT
#   define E_OS_DISABLEDINT (65292U)
#  endif

#  ifndef E_OS_STACKFAULT
#   define E_OS_STACKFAULT (65293U)
#  endif

#  ifndef E_OS_PROTECTION_MEMORY
#   define E_OS_PROTECTION_MEMORY (65294U)
#  endif

#  ifndef E_OS_PROTECTION_TIME
#   define E_OS_PROTECTION_TIME (65295U)
#  endif

#  ifndef E_OS_PROTECTION_ARRIVAL
#   define E_OS_PROTECTION_ARRIVAL (65296U)
#  endif

#  ifndef E_OS_PROTECTION_LOCKED
#   define E_OS_PROTECTION_LOCKED (65297U)
#  endif

#  ifndef E_OS_PROTECTION_EXCEPTION
#   define E_OS_PROTECTION_EXCEPTION (65298U)
#  endif

#  ifndef E_OS_INTERFERENCE_DEADLOCK
#   define E_OS_INTERFERENCE_DEADLOCK (65299U)
#  endif

#  ifndef E_OS_NESTING_DEADLOCK
#   define E_OS_NESTING_DEADLOCK (65300U)
#  endif

#  ifndef E_OS_SPINLOCK
#   define E_OS_SPINLOCK (65301U)
#  endif

#  ifndef E_OS_CORE
#   define E_OS_CORE (65302U)
#  endif

#  ifndef E_OS_PARAM_POINTER
#   define E_OS_PARAM_POINTER (65303U)
#  endif

#  ifndef E_OS_SHUTDOWN
#   define E_OS_SHUTDOWN (65304U)
#  endif

#  ifndef E_OS_SYS_API_ERROR
#   define E_OS_SYS_API_ERROR (65305U)
#  endif

#  ifndef E_OS_SYS_ASSERTION
#   define E_OS_SYS_ASSERTION (65520U)
#  endif

#  ifndef E_OS_SYS_DISABLED
#   define E_OS_SYS_DISABLED (65521U)
#  endif

#  ifndef E_OS_SYS_NO_BARRIER_PARTICIPANT
#   define E_OS_SYS_NO_BARRIER_PARTICIPANT (65522U)
#  endif

#  ifndef E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY
#   define E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (65523U)
#  endif

#  ifndef E_OS_SYS_NO_NTFSTACK
#   define E_OS_SYS_NO_NTFSTACK (65524U)
#  endif

#  ifndef E_OS_SYS_OVERFLOW
#   define E_OS_SYS_OVERFLOW (65525U)
#  endif

#  ifndef E_OS_SYS_KILL_KERNEL_OBJ
#   define E_OS_SYS_KILL_KERNEL_OBJ (65526U)
#  endif

#  ifndef E_OS_SYS_NO_RESTARTTASK
#   define E_OS_SYS_NO_RESTARTTASK (65527U)
#  endif

#  ifndef E_OS_SYS_CALL_NOT_ALLOWED
#   define E_OS_SYS_CALL_NOT_ALLOWED (65528U)
#  endif

#  ifndef E_OS_SYS_FUNCTION_UNAVAILABLE
#   define E_OS_SYS_FUNCTION_UNAVAILABLE (65529U)
#  endif

#  ifndef E_OS_SYS_PROTECTION_SYSCALL
#   define E_OS_SYS_PROTECTION_SYSCALL (65530U)
#  endif

#  ifndef E_OS_SYS_PROTECTION_IRQ
#   define E_OS_SYS_PROTECTION_IRQ (65531U)
#  endif

#  ifndef E_OS_SYS_OVERLOAD
#   define E_OS_SYS_OVERLOAD (65532U)
#  endif

#  ifndef E_OS_SYS_CROSS_CORE_REQUESTED
#   define E_OS_SYS_CROSS_CORE_REQUESTED (65533U)
#  endif

#  ifndef E_ARM_NMI_EVENT
#   define E_ARM_NMI_EVENT (64001U)
#  endif

#  ifndef E_ARM_HARD_FAULT
#   define E_ARM_HARD_FAULT (64002U)
#  endif

#  ifndef E_ARM_MEMMANAGE_FAULT
#   define E_ARM_MEMMANAGE_FAULT (64003U)
#  endif

#  ifndef E_ARM_BUS_FAULT
#   define E_ARM_BUS_FAULT (64004U)
#  endif

#  ifndef E_ARM_USAGE_FAULT
#   define E_ARM_USAGE_FAULT (64005U)
#  endif

#  ifndef E_ARM_DEBUG_MONITOR
#   define E_ARM_DEBUG_MONITOR (64006U)
#  endif

#  ifndef E_ARM_PENDING_SV
#   define E_ARM_PENDING_SV (64007U)
#  endif

#  ifndef E_ARM_UNDEFINED_INSTRUCTION
#   define E_ARM_UNDEFINED_INSTRUCTION (64241U)
#  endif

#  ifndef E_ARM_Supervisor_Call
#   define E_ARM_Supervisor_Call (64242U)
#  endif

#  ifndef E_ARM_PREFETCH_ABORT
#   define E_ARM_PREFETCH_ABORT (64243U)
#  endif

#  ifndef E_ARM_DATA_ABORT
#   define E_ARM_DATA_ABORT (64244U)
#  endif

#  ifndef E_ARM_SUPERVISOR
#   define E_ARM_SUPERVISOR (64245U)
#  endif

#  ifndef E_ARM_UNDEFINED
#   define E_ARM_UNDEFINED (64246U)
#  endif

#  ifndef E_ARM_SVC
#   define E_ARM_SVC (64247U)
#  endif

#  ifndef E_ARM_PREFETCH_ABORT_R5
#   define E_ARM_PREFETCH_ABORT_R5 (64248U)
#  endif

#  ifndef E_ARM_PREFETCH_ABOR_R5
#   define E_ARM_PREFETCH_ABOR_R5 (64249U)
#  endif

#  ifndef NVM_E_HARDWARE
#   define NVM_E_HARDWARE (64257U)
#  endif

#  ifndef NVM_E_INTEGRITY_FAILED
#   define NVM_E_INTEGRITY_FAILED (64258U)
#  endif

#  ifndef E_NVM_REQ_FAILED
#   define E_NVM_REQ_FAILED (64259U)
#  endif

#  ifndef E_NVM_WRONG_BLOCK_ID
#   define E_NVM_WRONG_BLOCK_ID (64260U)
#  endif

#  ifndef E_NVM_VERIFY_FAILED
#   define E_NVM_VERIFY_FAILED (64261U)
#  endif

#  ifndef E_NVM_LOSS_OF_REDUNDANCY
#   define E_NVM_LOSS_OF_REDUNDANCY (64262U)
#  endif

#  ifndef E_NVM_WRITE_FAILED
#   define E_NVM_WRITE_FAILED (64263U)
#  endif

#  ifndef E_NVM_READ_FAILED
#   define E_NVM_READ_FAILED (64264U)
#  endif

#  ifndef RESET_UNDEFINED
#   define RESET_UNDEFINED (64512U)
#  endif

#  ifndef POWER_ON_RESET
#   define POWER_ON_RESET (64513U)
#  endif

#  ifndef MCU_PORz
#   define MCU_PORz (64514U)
#  endif

#  ifndef SW_MAIN_PORz
#   define SW_MAIN_PORz (64515U)
#  endif

#  ifndef MCU_RESETz
#   define MCU_RESETz (64516U)
#  endif

#  ifndef SW_MCU_WARMRSTz
#   define SW_MCU_WARMRSTz (64517U)
#  endif

#  ifndef MAIN_RESETz_REQ
#   define MAIN_RESETz_REQ (64518U)
#  endif

#  ifndef SW_MAIN_WARMRSTz
#   define SW_MAIN_WARMRSTz (64519U)
#  endif

#  ifndef VTM_THERMAL_RESET
#   define VTM_THERMAL_RESET (64520U)
#  endif

#  ifndef ESM_ERRORz
#   define ESM_ERRORz (64521U)
#  endif

#  ifndef SMS_COLD_OUT_RST_n
#   define SMS_COLD_OUT_RST_n (64522U)
#  endif

#  ifndef SMS_WARM_OUT_RST_n
#   define SMS_WARM_OUT_RST_n (64523U)
#  endif

#  ifndef DM_WDT_RST_n
#   define DM_WDT_RST_n (64524U)
#  endif

#  ifndef DET_ERROR
#   define DET_ERROR (63745U)
#  endif

#  ifndef WDGM_ALIVE_FAIL
#   define WDGM_ALIVE_FAIL (63746U)
#  endif

#  ifndef FOTA_RESET
#   define FOTA_RESET (63747U)
#  endif

#  ifndef DIAG_RESET
#   define DIAG_RESET (63748U)
#  endif

#  ifndef RAM_TST_ERROR
#   define RAM_TST_ERROR (63749U)
#  endif

#  ifndef CAN_LOOP_TEST_ERROR
#   define CAN_LOOP_TEST_ERROR (63750U)
#  endif

#  ifndef FLS_TST_ERROR
#   define FLS_TST_ERROR (63751U)
#  endif

#  ifndef EARLY_WAKEUP
#   define EARLY_WAKEUP (63752U)
#  endif

#  ifndef CORE_SYS_TST_ERROR
#   define CORE_SYS_TST_ERROR (63753U)
#  endif

#  ifndef WAKEUP_SEQ_TIMELIMIT_FAULT
#   define WAKEUP_SEQ_TIMELIMIT_FAULT (63754U)
#  endif

#  ifndef TFT_RECOVERYTIMELIMIT_FAULT
#   define TFT_RECOVERYTIMELIMIT_FAULT (63755U)
#  endif

#  ifndef NVM_WRITE_FAIL
#   define NVM_WRITE_FAIL (63756U)
#  endif

#  ifndef ADC_TEST
#   define ADC_TEST (63757U)
#  endif

#  ifndef WDM_TIMER_FAIL
#   define WDM_TIMER_FAIL (63758U)
#  endif

#  ifndef CM_TEST_FAIL
#   define CM_TEST_FAIL (63759U)
#  endif

#  ifndef DMA_TEST_FAIL
#   define DMA_TEST_FAIL (63760U)
#  endif

#  ifndef PPU_TEST_FAIL
#   define PPU_TEST_FAIL (63761U)
#  endif

#  ifndef POWER_SUPPLY_FAULT
#   define POWER_SUPPLY_FAULT (63762U)
#  endif

#  ifndef ECC_FAULT
#   define ECC_FAULT (63763U)
#  endif

#  ifndef DCC_FAIL
#   define DCC_FAIL (63764U)
#  endif

#  ifndef OCOC_FAIL
#   define OCOC_FAIL (63765U)
#  endif

#  ifndef GIP_HEALTH_FAIL
#   define GIP_HEALTH_FAIL (63766U)
#  endif

#  ifndef HSM_WDG_FAIL
#   define HSM_WDG_FAIL (63767U)
#  endif

#  ifndef POK_FAULT
#   define POK_FAULT (63768U)
#  endif

#  ifndef DM_WDG_FAIL
#   define DM_WDG_FAIL (63769U)
#  endif

#  ifndef FIREWALL_ACCESS_FAIL
#   define FIREWALL_ACCESS_FAIL (63770U)
#  endif

#  ifndef FALSH_INTEGRITY_FAIL
#   define FALSH_INTEGRITY_FAIL (63771U)
#  endif

#  ifndef TOG_FAULT
#   define TOG_FAULT (63772U)
#  endif

#  ifndef VTM_FAULT
#   define VTM_FAULT (63773U)
#  endif

#  ifndef DM_SAFETY_CHECK_PWR_FAIL
#   define DM_SAFETY_CHECK_PWR_FAIL (63774U)
#  endif

#  ifndef DM_SAFETY_CHECK_RES_FAIL
#   define DM_SAFETY_CHECK_RES_FAIL (63775U)
#  endif

#  ifndef TIFS_SAFETY_CHECK_FWL_FAIL
#   define TIFS_SAFETY_CHECK_FWL_FAIL (63776U)
#  endif

#  ifndef SCI_CLIENT_PM_CLOCK_FAIL
#   define SCI_CLIENT_PM_CLOCK_FAIL (63777U)
#  endif

#  ifndef SCI_CLIENT_PM_RESET_FAIL
#   define SCI_CLIENT_PM_RESET_FAIL (63778U)
#  endif

#  ifndef SCI_CLIENT_PM_LPM_FAIL
#   define SCI_CLIENT_PM_LPM_FAIL (63779U)
#  endif

#  ifndef SCI_CLIENT_RM_IRQ_FAIL
#   define SCI_CLIENT_RM_IRQ_FAIL (63780U)
#  endif

#  ifndef SCI_CLIENT_RM_FWL_FAIL
#   define SCI_CLIENT_RM_FWL_FAIL (63781U)
#  endif

#  ifndef SCI_CLIENT_RM_UDMA_FAIL
#   define SCI_CLIENT_RM_UDMA_FAIL (63782U)
#  endif

#  ifndef SCI_CLIENT_RM_PSIL_FAIL
#   define SCI_CLIENT_RM_PSIL_FAIL (63783U)
#  endif

#  ifndef DM_BOOT_STAGE1_FAIL
#   define DM_BOOT_STAGE1_FAIL (63784U)
#  endif

#  ifndef DM_BOOT_STAGE2_FAIL
#   define DM_BOOT_STAGE2_FAIL (63785U)
#  endif

#  ifndef DM_DDR_FAIL
#   define DM_DDR_FAIL (63786U)
#  endif

#  ifndef DM_eMMC_FAIL
#   define DM_eMMC_FAIL (63787U)
#  endif

#  ifndef DM_QSPI_FAIL
#   define DM_QSPI_FAIL (63788U)
#  endif

#  ifndef DM_STACK_FAIL
#   define DM_STACK_FAIL (63789U)
#  endif

#  ifndef DM_OS_ERROR
#   define DM_OS_ERROR (63790U)
#  endif

#  ifndef DM_SCI_SERVER_FAIL
#   define DM_SCI_SERVER_FAIL (63791U)
#  endif

#  ifndef JTAG_PWD_FEED_FAIL
#   define JTAG_PWD_FEED_FAIL (63792U)
#  endif

#  ifndef BM_SB_FAIL
#   define BM_SB_FAIL (63793U)
#  endif

#  ifndef FBL_SB_FAIL
#   define FBL_SB_FAIL (63794U)
#  endif

#  ifndef APP_SB_FAIL
#   define APP_SB_FAIL (63795U)
#  endif

#  ifndef CRC_SB_FAIL
#   define CRC_SB_FAIL (63796U)
#  endif

#  ifndef HSM_OS_ERROR
#   define HSM_OS_ERROR (63797U)
#  endif

#  ifndef HSM_MAC_FAIL
#   define HSM_MAC_FAIL (63798U)
#  endif

#  ifndef HSM_CIPHER_FAIL
#   define HSM_CIPHER_FAIL (63799U)
#  endif

#  ifndef HSM_KEY_FAIL
#   define HSM_KEY_FAIL (63800U)
#  endif

#  ifndef HSM_SEED_FAIL
#   define HSM_SEED_FAIL (63801U)
#  endif

#  ifndef HSM_FWL_FAIL
#   define HSM_FWL_FAIL (63802U)
#  endif

#  ifndef EXT_WDG_RESET
#   define EXT_WDG_RESET (63784U)
#  endif

#  ifndef EXT_WDG_COMM_ERROR
#   define EXT_WDG_COMM_ERROR (63785U)
#  endif

#  ifndef FLTM_NONE
#   define FLTM_NONE (0U)
#  endif

#  ifndef FLTM_INACTIVE
#   define FLTM_INACTIVE (1U)
#  endif

#  ifndef FLTM_ACTIVE
#   define FLTM_ACTIVE (2U)
#  endif

#  ifndef FLTM_CHANGED
#   define FLTM_CHANGED (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CFLTMEXT_TYPE_H */
