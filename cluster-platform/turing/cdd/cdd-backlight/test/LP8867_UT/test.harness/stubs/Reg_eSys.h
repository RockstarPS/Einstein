/**
*   @file    Reg_eSys.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Base - BIP Memory and DMA mapping.
*   @details Memory mapping of the IP modules and DMA channels present on the IMX8
*            hardware platform.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IMX8
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : IMX8_MCAL_3_0_0_RTM_QLP1_ASR_REL_4_2_REV_0002_20200228
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2020 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef REG_ESYS_H
#define REG_ESYS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        Reg_eSys.h
* @brief Include platform types
* @violates @ref Reg_eSys_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/**
* @file        Reg_eSys.h
* @brief Include IP module versions
*/
#include "Soc_Ips.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_VENDOR_ID                    43
#define REG_ESYS_MODULE_ID                    0
#define REG_ESYS_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_AR_RELEASE_MINOR_VERSION     2
#define REG_ESYS_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_SW_MAJOR_VERSION             3
#define REG_ESYS_SW_MINOR_VERSION             0
#define REG_ESYS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Platform_Types.h header file have same versions */
#if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
//#error "AutoSar Version Numbers of Reg_eSys.h and Platform_Types.h are different"
#endif
#endif

/* Check if source file and Soc_Ips.h header file have same versions */
#if (REG_ESYS_VENDOR_ID != SOC_IPS_VENDOR_ID)
//#error "Reg_eSys.h and Soc_Ips.h have different vendor IDs"
#endif
#if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_REVISION_VERSION != SOC_IPS_AR_RELEASE_REVISION_VERSION))
//#error "AutoSar Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif
#if ((REG_ESYS_SW_MAJOR_VERSION != SOC_IPS_SW_MAJOR_VERSION) || \
     (REG_ESYS_SW_MINOR_VERSION != SOC_IPS_SW_MINOR_VERSION) || \
     (REG_ESYS_SW_PATCH_VERSION != SOC_IPS_SW_PATCH_VERSION))
//#error "Software Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Direct Memory Access Controller (ADC0)
* @details IMX8 System Memory Map
*/
#define ADC0_BASEADDR                           ((uint32)0x5A880000UL)

/**
* @brief Direct Memory Access Controller (ADC1)
* @details IMX8 System Memory Map
*/
#define ADC1_BASEADDR                           ((uint32)0x5A890000UL)

/**
* @brief Direct Memory Access Controller (DMA0)
* @details IMX8 System Memory Map
*/
#define DMA0_BASEADDR                           ((uint32)0x5A1F0000UL)

/**
* @brief Direct Memory Access Controller (DMA1)
* @details IMX8 System Memory Map
*/
#define DMA1_BASEADDR                           ((uint32)0x5A9F0000UL)

/**
* @brief Direct Memory Access Controller (DMA2)
* @details IMX8 System Memory Map
*/
#define DMA2_BASEADDR                           ((uint32)0x591F0000UL)

/**
* @brief Direct Memory Access Controller (DMA3)
* @details IMX8 System Memory Map
*/
#define DMA3_BASEADDR                           ((uint32)0x599F0000UL)

/**
* @brief Direct Memory Access Controller (DMA4 - Connectivity Memory)
* @details IMX8 System Memory Map
*/
#define DMA4_BASEADDR                           ((uint32)0x5B070000UL)

/**
* @brief Direct Memory Access Controller (IRQSTEER) for CM4_0
* @details IMX8 System Memory Map
*/
#define IRQSTEER_BASEADDR                       ((uint32)0x51070000UL)

/**
* @brief FlexTimer 2
* @details IMX8 System Memory Map
*/
#define FTM_1_BASEADDR                          ((uint32)0x5A8B0000UL)

/**
* @brief FlexTimer 1
* @details IMX8 System Memory Map
*/
#define FTM_0_BASEADDR                          ((uint32)0x5A8A0000UL)

/**
* @brief LowPowerTimer for Core M40
* @details IMX8 System Memory Map
*/
#define CM4_0_TPM_BASEADDR                          ((uint32)0x41200000UL)

/**
* @brief LowPowerTimer for Core M41
* @details IMX8 System Memory Map
*/
#define CM4_1_TPM_BASEADDR                          ((uint32)0x41200000UL)

/**
* @brief Low Power Periodic Interrupt Timer for Core M41
* @details IMX8 System Memory Map
*/
#define CM4_0_LPIT_BASEADDR                      ((uint32)0x41210000UL)

/**
* @brief Low Power Periodic Interrupt Timer for Core M41
* @details IMX8 System Memory Map
*/
#define CM4_1_LPIT_BASEADDR                      ((uint32)0x41210000UL)

/**
* @brief FlexCan 3
* @details IMX8 System Memory Map

*/
#define FLEXCAN2_BASEADDR                       ((uint32)0x5A8F0000UL)

/**
* @brief FlexCan 2
* @details IMX8 System Memory Map
*/
#define FLEXCAN1_BASEADDR                       ((uint32)0x5A8E0000UL)

/**
* @brief FlexCan 1
* @details IMX8 System Memory Map
*/
#define FLEXCAN0_BASEADDR                       ((uint32)0x5A8D0000UL)

/**
* @brief FlexSpi 0
* @details IMX8 System Memory Map
*/
#define FLEXSPI_0_BASEADDR                      ((uint32)0x5D120000UL)

/**
* @brief FlexSpi 1
* @details IMX8 System Memory Map
*/
#define FLEXSPI_1_BASEADDR                      ((uint32)0x5D130000UL)

/**
* @brief SDMA ARM base address
* @details IMX8 System Memory Map
*/
#define SDMAARM_BASEADDR                        ((uint32)0x5A2A0000UL)

/**
@brief  Ethernet Controller 2 (ENET_2)
@details IMX8 System Memory Map
*/
#define ENET_1_BASEADDR                         ((uint32)0x5B050000UL)

/**
@brief  Ethernet Controller 1 (ENET_1)
@details IMX8 System Memory Map
*/
#define ENET_0_BASEADDR                         ((uint32)0x5B040000UL)

/**
* @brief QSPI1 Base Address
* @details IMX8 System Memory Map
*/
#define QSPI0_BASEADDR                          ((uint32)(0x5A270000UL))

/**
* @brief  LPSPI 3
* @details IMX8 System Memory Map
*/
#define LPSPI3_BASEADDR                         ((uint32)0x5A030000UL)

/**
* @brief  LPSPI 2
* @details IMX8 System Memory Map
*/
#define LPSPI2_BASEADDR                         ((uint32)0x5A020000UL)

/**
* @brief  LPSPI 1
* @details IMX8 System Memory Map
*/
#define LPSPI1_BASEADDR                         ((uint32)0x5A010000UL)

/**
* @brief  LPSPI 0
* @details IMX8 System Memory Map
*/
#define LPSPI0_BASEADDR                         ((uint32)0x5A000000UL)

/**
* @brief GPIO 0 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_0_BASEADDR                          ((uint32)0x5D080000UL)

/**
* @brief GPIO 1 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_1_BASEADDR                          ((uint32)0x5D090000UL)

/**
* @brief GPIO 2 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_2_BASEADDR                          ((uint32)0x5D0A0000UL)

/**
* @brief GPIO 3 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_3_BASEADDR                          ((uint32)0x5D0B0000UL)

/**
* @brief GPIO 4 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_4_BASEADDR                          ((uint32)0x5D0C0000UL)

/**
* @brief GPIO 5 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_5_BASEADDR                          ((uint32)0x5D0D0000UL)

/**
* @brief GPIO 6 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_6_BASEADDR                          ((uint32)0x5D0E0000UL)

/**
* @brief GPIO 7 direction register
* @details IMX8 System Memory Map
*/
#define GPIO_7_BASEADDR                          ((uint32)0x5D0F0000UL)

/**
* @brief GPIO 8 (HSIO) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_8_BASEADDR                          ((uint32)0x5F170000UL)

/**
* @brief GPIO 9 (Display Interface 0 - Display Pixel Link 4 LVDS) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_9_BASEADDR                          ((uint32)0x56242000UL)

/**
* @brief GPIO 10 (Display Interface 0 - Display Pixel Link 8 MIPI/DSI) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_10_BASEADDR                          ((uint32)0x56222000UL)

/**
* @brief GPIO 11 (MIPI-CSI2 - HDMI IN) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_11_BASEADDR                          ((uint32)0x58262000UL)

/**
* @brief GPIO 12  Imaging (MIPI CSI #0) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_12_BASEADDR                          ((uint32)0x58222000UL)

/**
* @brief GPIO 13 (Display Pixel Link 0 HDMI) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_13_BASEADDR                          ((uint32)0x56262000UL)

/**
* @brief GPIO 14 (Display Interface 1 - Display Pixel Link 4 LVDS) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_14_BASEADDR                          ((uint32)0x57242000UL)

/**
* @brief GPIO 15 (Display Interface 1 - Display Pixel Link 8 MIPI DSI) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_15_BASEADDR                          ((uint32)0x57222000UL)

/**
* @brief GPIO 16 Imaging (MIPI CSI #1) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_16_BASEADDR                          ((uint32)0x58242000UL)

/**
* @brief GPIO 17 (Reserved) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_17_BASEADDR                          ((uint32)0xFFFF0000UL)

/**
* @brief GPIO 18 (Reserved) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_18_BASEADDR                          ((uint32)0xFFFF0000UL)

/**
* @brief GPIO 19 (Reserved) direction register
* @details IMX8 System Memory Map
*/
#define GPIO_19_BASEADDR                          ((uint32)0xFFFF0000UL)

/**
* @brief RGPIO0 for inner cortex M4
* @details IMX8 System Memory Map
*/
#define RGPIO_0_BASEADDR                         ((uint32)0x410F0000UL)

/**
* @brief RGPIO1 for outer cortex M4 from cortex M4_0 view
* @details IMX8 System Memory Map
*/
#define RGPIO_1_BASEADDR                         ((uint32)0x3B0F0000UL)

/**
* @brief GPT 0 base address
* @details IMX8 System Memory Map
*/
#define GPT0_BASEADDR                        ((uint32)(0x5D140000UL))

/**
* @brief GPT 1 base address
* @details IMX8 System Memory Map
*/
#define GPT1_BASEADDR                        ((uint32)(0x5D150000UL))

/**
* @brief GPT 2 base address
* @details IMX8 System Memory Map
*/
#define GPT2_BASEADDR                        ((uint32)(0x5D160000UL))

/**
* @brief GPT 3 base address
* @details IMX8 System Memory Map
*/
#define GPT3_BASEADDR                        ((uint32)(0x5D170000UL))

/**
* @brief GPT 4 base address
* @details IMX8 System Memory Map
*/
#define GPT4_BASEADDR                        ((uint32)(0x5D180000UL))

/**
* @brief GPT 5 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT5_BASEADDR                        ((uint32)(0x59100000UL))

/**
* @brief GPT 6 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT6_BASEADDR                        ((uint32)(0x590F0000UL))

/**
* @brief GPT 7 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT7_BASEADDR                        ((uint32)(0x590E0000UL))

/**
* @brief GPT 8 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT8_BASEADDR                        ((uint32)(0x590D0000UL))

/**
* @brief GPT 9 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT9_BASEADDR                        ((uint32)(0x590C0000UL))

/**
* @brief GPT 10 (Audio DMA) base address
* @details IMX8 System Memory Map
*/
#define GPT10_BASEADDR                        ((uint32)(0x590B0000UL))

/**
* @brief LPI2C_0 base address
* @details IMX8 System Memory Map
*/
#define LPI2C0_BASEADDR                     ((uint32)(0x5A800000UL))

/**
* @brief LPI2C_1 base address
* @details IMX8 System Memory Map
*/
#define LPI2C1_BASEADDR                     ((uint32)(0x5A810000UL))

/**
* @brief LPI2C_2 base address
* @details IMX8 System Memory Map
*/
#define LPI2C2_BASEADDR                     ((uint32)(0x5A820000UL))

/**
* @brief LPI2C_3 base address
* @details IMX8 System Memory Map
*/
#define LPI2C3_BASEADDR                     ((uint32)(0x5A830000UL))

/**
* @brief LPI2C_4 base address
* @details IMX8 System Memory Map
*/
#define LPI2C4_BASEADDR                     ((uint32)(0x5A840000UL))

/**
* @brief M4_0_LPI2C base address
* @details IMX8 System Memory Map
*/
#define M4_0_LPI2C_BASEADDR                     ((uint32)(0x41230000UL))

/**
* @brief M4_1_LPI2C base address
* @details IMX8 System Memory Map
*/
#define M4_1_LPI2C_BASEADDR                     ((uint32)(0x41230000UL))

/**
* @brief LPI2C_5 (MIPI DSI LVDS 1) base address
* @details IMX8 System Memory Map
*/
#define LPI2C5_BASEADDR                     ((uint32)(0x56246000UL))

/**
* @brief LPI2C_6 (MIPI DSI LVDS 0) base address
* @details IMX8 System Memory Map
*/
#define LPI2C6_BASEADDR                     ((uint32)(0x56226000UL))

/**
* @brief LPI2C_7 (Parallel Camera) base address
* @details IMX8 System Memory Map
*/
#define LPI2C7_BASEADDR                     ((uint32)(0x58266000UL))

/**
* @brief LPI2C_8 (Imaging) base address
* @details IMX8 System Memory Map
*/
#define LPI2C8_BASEADDR                     ((uint32)(0x58226000UL))

/**
* @brief LPI2C_9 (Display Pixel Link 0 HDMI) base address
* @details IMX8 System Memory Map
*/
#define LPI2C9_BASEADDR                     ((uint32)(0x56266000UL))

/**
* @brief LPI2C_10 (Display Pixel Link 4 LVDS) base address
* @details IMX8 System Memory Map
*/
#define LPI2C10_BASEADDR                     ((uint32)(0x56247000UL))

/**
* @brief LPI2C_11 (Display Pixel Link 4 LVDS) base address
* @details IMX8 System Memory Map
*/
#define LPI2C11_BASEADDR                     ((uint32)(0x57247000UL))

/**
* @brief LPI2C_12 (Display Pixel Link 4 LVDS) base address
* @details IMX8 System Memory Map
*/
#define LPI2C12_BASEADDR                     ((uint32)(0x57246000UL))

/**
* @brief LPI2C_13 (Display Pixel Link 8 MIPI DSI) base address
* @details IMX8 System Memory Map
*/
#define LPI2C13_BASEADDR                     ((uint32)(0x57227000UL))

/**
* @brief LPI2C_14 (Display Pixel Link 8 MIPI DSI) base address
* @details IMX8 System Memory Map
*/
#define LPI2C14_BASEADDR                     ((uint32)(0x57226000UL))

/**
* @brief LPI2C_15 (MIPI-CSI2 - Imaging (MIPI CSI1)) base address
* @details IMX8 System Memory Map
*/
#define LPI2C15_BASEADDR                     ((uint32)(0x58246000UL))

/**
* @brief QSPI base address
* @details IMX8 System Memory Map
*/
#define QSPI_BASEADDR                          ((uint32)(0x5A270000UL))

/**
* @brief PWM 0 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM0_BASEADDR                          ((uint32)(0x5D000000UL))

/**
* @brief PWM 1 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM1_BASEADDR                          ((uint32)(0x5D010000UL))

/**
* @brief PWM 2 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM2_BASEADDR                          ((uint32)(0x5D020000UL))

/**
* @brief PWM 3 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM3_BASEADDR                          ((uint32)(0x5D030000UL))

/**
* @brief PWM 4 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM4_BASEADDR                          ((uint32)(0x5D040000UL))

/**
* @brief PWM 5 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM5_BASEADDR                          ((uint32)(0x5D050000UL))

/**
* @brief PWM 6 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM6_BASEADDR                          ((uint32)(0x5D060000UL))

/**
* @brief PWM 7 Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM7_BASEADDR                          ((uint32)(0x5D070000UL))

/**
* @brief PWM 8 (Audio DMA) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM8_BASEADDR                          ((uint32)(0x5A190000UL))

/**
* @brief PWM 9 (MIPI DSI 0 ) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM9_BASEADDR                          ((uint32)(0x56244000UL))

/**
* @brief PWM 10 (MIPI DSI 1) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM10_BASEADDR                          ((uint32)(0x56224000UL))

/**
* @brief PWM 11 (MIPI DSI) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM11_BASEADDR                          ((uint32)(0x58264000UL))

/**
* @brief PWM 12 (MIPI DSI) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM12_BASEADDR                          ((uint32)(0x58224000UL))

/**
* @brief PWM 13 (Display Pixel Link 0) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM13_BASEADDR                          ((uint32)(0x56264000UL))

/**
* @brief PWM 14 (Display Pixel Link 4) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM14_BASEADDR                          ((uint32)(0x57244000UL))

/**
* @brief PWM 15 (Display Pixel Link 8) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM15_BASEADDR                          ((uint32)(0x57224000UL))

/**
* @brief PWM 16 (MIPI-CSI2 - Imaging (MIPI CSI1)) Control Register base address
* @details IMX8 System Memory Map
*/
#define PWM16_BASEADDR                          ((uint32)(0x58244000UL))

/**
* @brief LPUART 0 Control Register base address
* @details IMX8 System Memory Map
*/
#define LPUART0_BASEADDR                       ((uint32)0x5A060000UL)

/**
* @brief LPUART 1 Control Register base address
* @details IMX8 System Memory Map
*/
#define LPUART1_BASEADDR                       ((uint32)0x5A070000UL)

/**
* @brief LPUART 2 Control Register base address
* @details IMX8 System Memory Map
*/
#define LPUART2_BASEADDR                       ((uint32)0x5A080000UL)

/**
* @brief LPUART 3 Control Register base address
* @details IMX8 System Memory Map
*/
#define LPUART3_BASEADDR                       ((uint32)0x5A090000UL)

/**
* @brief LPUART 4 Control Register base address
* @details IMX8 System Memory Map
*/
#define LPUART4_BASEADDR                       ((uint32)0x5A0A0000UL)

/**
* @brief M4_0_LPUART Control Register base address
* @details IMX8 System Memory Map
*/
#define M4_0_LPUART_BASEADDR                       ((uint32)0x41220000UL)

/**
* @brief M4_1_LPUART Control Register base address
* @details IMX8 System Memory Map
*/
#define M4_1_LPUART_BASEADDR                       ((uint32)0x41220000UL)

/**
* @brief MU1_A_M4_0 Message Unit base address to communicate between M4 core and SCU core
* @details IMX8 System Memory Map
*/
#define MU1_A_M4_0_BASEADDR                        ((uint32)0x41480000UL)

/**
* @brief MU1_A_M4_0 Message Unit base address to communicate between M4 core and SCU core
* @details IMX8 System Memory Map
*/
#define MU1_A_M4_1_BASEADDR                        ((uint32)0x41480000UL)

/**
* @brief USDHC_0_BASEADDR base address
* @details IMX8 System Memory Map
*/
#define USDHC_0_BASEADDR                         ((uint32)0x5B010000UL)

/**
* @brief USDHC_1_BASEADDR base address
* @details IMX8 System Memory Map
*/
#define USDHC_1_BASEADDR                        ((uint32)0x5B020000UL)

/**
* @brief USDHC_2_BASEADDR base address
* @details IMX8 System Memory Map
*/
#define USDHC_2_BASEADDR                        ((uint32)0x5B030000UL)

/**
* @brief ASMC_BASEADDR base address
* @details IMX8 System Memory Map
*/
#define ASMC_BASEADDR                           ((uint32)0x41410000UL)

/**
* @brief WDOG_0_BASEADDR base address for SCU
* @details IMX8 System Memory Map
*/
#define WDOG_0_BASEADDR                           ((uint32)0x33420000UL)

/**
* @brief WDOG_1_BASEADDR base address for M4_0
* @details IMX8 System Memory Map
*/
#define WDOG_1_BASEADDR                           ((uint32)0x41420000UL)

/**
* @brief WDOG_2_BASEADDR base address for M4_1
* @details IMX8 System Memory Map
*/
#define WDOG_2_BASEADDR                           ((uint32)0x41420000UL)

/**
* @brief  LMEM
* @details IMX8 System Memory Map
*/
#define LMEM_BASEADDR                             ((uint32)0xE0082000U)

/**
* @brief ESAI_0_BASEADDR base address for M4_0
* @details IMX8 System Memory Map
*/
#define ESAI0_BASEADDR                           ((uint32)0x59010000UL)

/**
* @brief ESAI_1_BASEADDR base address for M4_0
* @details IMX8 System Memory Map
*/
#define ESAI1_BASEADDR                           ((uint32)0x59810000UL)

/**
* @brief LIS_DISP0_0_BASEADDR base address for MIPI DSI/LVDS_0 or Display Pixel Link 8 MIPI/DSI
* @details IMX8 System Memory Map
*/
#define LIS_DISP0_0_BASEADDR                           ((uint32)0x56220000UL)

/**
* @brief LIS_DISP0_1_BASEADDR base address for MIPI DSI/LVDS_1 or Display Pixel Link 4 LVDS
* @details IMX8 System Memory Map
*/
#define LIS_DISP0_1_BASEADDR                           ((uint32)0x56240000UL)

/**
* @brief LIS_DISP0_2_BASEADDR base address for Display Pixel Link 0 HDMI
* @details IMX8 System Memory Map
*/
#define LIS_DISP0_2_BASEADDR                           ((uint32)0x56260000UL)

/**
* @brief LIS_DISP1_0_BASEADDR base address for Display Pixel Link 8 MIPI DSI
* @details IMX8 System Memory Map
*/
#define LIS_DISP1_0_BASEADDR                           ((uint32)0x57220000UL)

/**
* @brief LIS_DISP1_1_BASEADDR base address for Display Pixel Link 4 LVDS
* @details IMX8 System Memory Map
*/
#define LIS_DISP1_1_BASEADDR                           ((uint32)0x57240000UL)

/**
* @brief LIS_MIPICSI_0_BASEADDR base address for Imaging (MIPI CSI #0)
* @details IMX8 System Memory Map
*/
#define LIS_MIPICSI_0_BASEADDR                         ((uint32)0x58220000UL)

/**
* @brief LIS_MIPICSI_1_BASEADDR base address for Imaging (MIPI CSI #1) 
* @details IMX8 System Memory Map
*/
#define LIS_MIPICSI_1_BASEADDR                         ((uint32)0x58240000UL)

/**
* @brief LIS_MIPICSI_2_BASEADDR base address for HDMI IN or Parallel Camera
* @details IMX8 System Memory Map
*/
#define LIS_MIPICSI_2_BASEADDR                         ((uint32)0x58260000UL)

/**
* @brief GPT channels per module for GPT driver
*/
#define GPT_GPT_CH_PER_MODULE                       (0x03U)

/**
* @brief GPT channels per module for ICU driver
*/
#define ICU_GPT_CH_PER_MODULE                       (0x02U)

/**
* @brief GPT channels per module for OCU driver
*/
#define OCU_GPT_CH_PER_MODULE                       (0x03U)

/**
* @brief FTM channels per module
*/
#define FTM_CH_PER_MODULE                       (0x08U)

/**
* @brief TPM channels per module
*/
#define TPM_CH_PER_MODULE                       (0x08U)

/**
* @brief Maximum number of GPIO PORT
*/
#define GPIO_NUM_MAXIMUM                        (0x14U)

/**
* @brief Maximum number of PWM
*/
#define PWM_NUM_INSTANCE                        (0x11U)

#define ESAI_NUM_INSTANCE                       (0x02U)

/**
* @details IMX8X derivative support
*/
#ifndef DERIVATIVE_IMX8X_SUPPORT
#define DERIVATIVE_IMX8X_SUPPORT
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef REG_ESYS_H*/

/** @} */
