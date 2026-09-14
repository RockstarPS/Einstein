/**
*   @file           Reg_eSys_IrqSteer.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Mcl - IRQSTEER register and bitfield defines.
*   @details        IRQSTEER register and bitfield defines, used by driver that access the IRQSTEER resources.
*
*   @addtogroup     IRQSTEER_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20210812
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2021 NXP
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef REG_ESYS_IRQSTEER_H
#define REG_ESYS_IRQSTEER_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Reg_eSys_IrqSteer_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Reg_eSys_IrqSteer_H_REF_2
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Reg_eSys.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Reg_eSys_IrqSteer.h
*/
#define REG_ESYS_IRQSTEER_VENDOR_ID                    43
#define REG_ESYS_IRQSTEER_MODULE_ID                    255

/* @violates @ref Reg_eSys_IrqSteer_H_REF_1 Identifier clash. */
#define REG_ESYS_IRQSTEER_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Reg_eSys_IrqSteer_H_REF_1 Identifier clash. */
#define REG_ESYS_IRQSTEER_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Reg_eSys_IrqSteer_H_REF_1 Identifier clash. */
#define REG_ESYS_IRQSTEER_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_IRQSTEER_SW_MAJOR_VERSION             4
#define REG_ESYS_IRQSTEER_SW_MINOR_VERSION             0
#define REG_ESYS_IRQSTEER_SW_PATCH_VERSION             0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Reg_eSys_IrqSteer.h file and Reg_eSys.h are of the same Autosar version */
    #if ((REG_ESYS_IRQSTEER_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_IRQSTEER_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_IrqSteer.h and Reg_eSys.h are different"
    #endif
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*==================================================================================================
*                                GLOBAL DEFINES & DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief IRQ Steer Registers - Configuration registers.
*/
#define IRQSTEER_CHANCTL_ADDR32(u8ChannelIdx)                       (IRQSTEER_BASEADDR)

#ifdef DERIVATIVE_IMX8DXL_SUPPORT
#define IRQSTEER_CHANMASK_ADDR32(u8ChannelIdx)                      (IRQSTEER_BASEADDR + 0x4UL + ((11UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANSET_ADDR32(u8ChannelIdx)                       (IRQSTEER_BASEADDR + 0x34UL + ((11UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANSTATUS_ADDR32(u8ChannelIdx)                    (IRQSTEER_BASEADDR + 0x64UL + ((11UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANMINTDIS_ADDR32                                 (IRQSTEER_BASEADDR + 0x94UL)
#define IRQSTEER_CHANMSTRSTAT_ADDR32                                (IRQSTEER_BASEADDR + 0x98UL)
#else
#define IRQSTEER_CHANMASK_ADDR32(u8ChannelIdx)                      (IRQSTEER_BASEADDR + 0x4UL + ((15UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANSET_ADDR32(u8ChannelIdx)                       (IRQSTEER_BASEADDR + 0x44UL + ((15UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANSTATUS_ADDR32(u8ChannelIdx)                    (IRQSTEER_BASEADDR + 0x84UL + ((15UL - ((uint32)(u8ChannelIdx) >> 5UL)) << 2UL))
#define IRQSTEER_CHANMINTDIS_ADDR32                                 (IRQSTEER_BASEADDR + 0xC4UL)
#define IRQSTEER_CHANMSTRSTAT_ADDR32                                (IRQSTEER_BASEADDR + 0xC8UL)

/**
* @{
* @brief Local interrupt steer Registers - Configuration registers.
*/
#define LOCAL_IRQSTEER_CHANCTL_ADDR32(u32LocalIrqAddr)                       (u32LocalIrqAddr)
#define LOCAL_IRQSTEER_CHANMASK_ADDR32(u32LocalIrqAddr)                      ((u32LocalIrqAddr) + 0x4UL)
#define LOCAL_IRQSTEER_CHANSET_ADDR32(u32LocalIrqAddr)                       ((u32LocalIrqAddr) + 0x8UL)
#define LOCAL_IRQSTEER_CHANSTATUS_ADDR32(u32LocalIrqAddr)                    ((u32LocalIrqAddr) + 0xCUL)
#define LOCAL_IRQSTEER_CHANMINTDIS_ADDR32(u32LocalIrqAddr)                   ((u32LocalIrqAddr) + 0x10UL)
#define LOCAL_IRQSTEER_CHANMSTRSTAT_ADDR32(u32LocalIrqAddr)                  ((u32LocalIrqAddr) + 0x14UL)

/**
@{
* @brief LOCAL_IRQSTEER_CHANMSTRSTAT - Channel n Master Status Register.
*/
#define LOCAL_IRQSTEER_CHANMSTRSTAT_STATUS_MASK_U32                       ((uint32)(BIT0))

#endif /* DERIVATIVE_IMX8DXL_SUPPORT */

/** MASK and SHIFT values for each register field */
/**
@{
* @brief IRQSTEER_CHANCTL - Channel n Control Register.
*/
#define IRQSTEER_CHANCTL_CH0_MASK_U32                               ((uint32)(BIT0))
#define IRQSTEER_CHANCTL_CH1_MASK_U32                               ((uint32)(BIT1))
#define IRQSTEER_CHANCTL_CH2_MASK_U32                               ((uint32)(BIT2))
#define IRQSTEER_CHANCTL_CH3_MASK_U32                               ((uint32)(BIT3))
#define IRQSTEER_CHANCTL_CH4_MASK_U32                               ((uint32)(BIT4))

/**
@{
* @brief IRQSTEER_CHANMSTRSTAT - Channel n Master Status Register.
*/
#define IRQSTEER_CHANMINTDIS_DISABLE_MASK_U32                       ((uint32)(BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7))

/**
@{
* @brief IRQSTEER_CHANMSTRSTAT - Channel n Master Status Register.
*/
#define IRQSTEER_CHANMSTRSTAT_STATUS_MASK_U32                       ((uint32)(BIT0))
#ifdef DERIVATIVE_IMX8DXL_SUPPORT
/** IRQ values for each peripherals */
    #define IRQSTEER_EDMA_2_IRQ                 (52U)
    #define IRQSTEER_EDMA_2_ERR_IRQ             (53U)

    #define IRQSTEER_EDMA_3_IRQ                 (54U)
    #define IRQSTEER_EDMA_3_ERR_IRQ             (55U)

    #define IRQSTEER_EDMA_0_IRQ                 (290U)
    #define IRQSTEER_EDMA_0_ERR_IRQ             (291U)

    #define IRQSTEER_GPT_0_IRQ                  (60U)
    #define IRQSTEER_GPT_1_IRQ                  (61U)
    #define IRQSTEER_GPT_2_IRQ                  (62U)
    #define IRQSTEER_GPT_3_IRQ                  (63U)
    #define IRQSTEER_GPT_4_IRQ                  (64U)

    #define IRQSTEER_GPT_7_IRQ                  (303U)
    #define IRQSTEER_GPT_8_IRQ                  (302U)
    #define IRQSTEER_GPT_9_IRQ                  (301U)
    #define IRQSTEER_GPT_10_IRQ                 (300U)

    #define IRQSTEER_FLEXSPI_0                  (66U)

    #define IRQSTEER_PWM_0_IRQ                  (68U)
    #define IRQSTEER_PWM_1_IRQ                  (69U)
    #define IRQSTEER_PWM_2_IRQ                  (70U)
    #define IRQSTEER_PWM_3_IRQ                  (71U)
    #define IRQSTEER_PWM_4_IRQ                  (72U)
    #define IRQSTEER_PWM_5_IRQ                  (73U)
    #define IRQSTEER_PWM_6_IRQ                  (74U)
    #define IRQSTEER_PWM_7_IRQ                  (75U)

    #define IRQSTEER_SPI_0_IRQ                  (150U)
    #define IRQSTEER_SPI_1_IRQ                  (151U)
    #define IRQSTEER_SPI_2_IRQ                  (152U)
    #define IRQSTEER_SPI_3_IRQ                  (153U)

    #define IRQSTEER_I2C_0_IRQ                  (154U)
    #define IRQSTEER_I2C_1_IRQ                  (155U)
    #define IRQSTEER_I2C_2_IRQ                  (156U)
    #define IRQSTEER_I2C_3_IRQ                  (157U)

    #define IRQSTEER_UART_0_IRQ                 (158U)
    #define IRQSTEER_UART_1_IRQ                 (159U)
    #define IRQSTEER_UART_2_IRQ                 (160U)
    #define IRQSTEER_UART_3_IRQ                 (161U)

    #define IRQSTEER_FLEXCAN_0_IRQ              (173U)
    #define IRQSTEER_FLEXCAN_1_IRQ              (174U)
    #define IRQSTEER_FLEXCAN_2_IRQ              (175U)

    #define IRQSTEER_FTM_0_IRQ                  (176U)
    #define IRQSTEER_FTM_1_IRQ                  (177U)

    #define IRQSTEER_ADC_0_IRQ                  (178U)

    #define IRQSTEER_GPIO_0_IRQ                 (110U)
    #define IRQSTEER_GPIO_1_IRQ                 (111U)
    #define IRQSTEER_GPIO_2_IRQ                 (112U)
    #define IRQSTEER_GPIO_3_IRQ                 (113U)
    #define IRQSTEER_GPIO_4_IRQ                 (114U)
    #define IRQSTEER_GPIO_5_IRQ                 (115U)
    #define IRQSTEER_GPIO_6_IRQ                 (116U)
    #define IRQSTEER_GPIO_7_IRQ                 (117U)

    #define IRQSTEER_ENET0_FRAME1_IRQ           (190U)
    #define IRQSTEER_ENET0_FRAME2_IRQ           (191U)
    #define IRQSTEER_ENET0_FRAME0_EVENT_IRQ     (192U)
    #define IRQSTEER_ENET0_TIMER_INT_IRQ        (193U)

    #define IRQSTEER_SECO_MU_2_IRQ              (350U)
    #define IRQSTEER_SECO_MU_3_IRQ              (351U)
    #define IRQSTEER_SECO_MU_4_IRQ              (352U)

    #define IRQSTEER_EQOS_DMA_CH0_INT_IRQ       (213U)
    #define IRQSTEER_EQOS_DMA_CH1_INT_IRQ       (214U)
    #define IRQSTEER_EQOS_DMA_CH2_INT_IRQ       (215U)
    #define IRQSTEER_EQOS_DMA_CH3_INT_IRQ       (216U)

#else /* DERIVATIVE_IMX8DXL_SUPPORT */

/** IRQ values for Display Pixel Link 8 MIPI/DSI in Display Interface 0 and 1 */
#define LIS_DISP_MIPI_DSI_IRQSTEER_LPI2C_0_IRQ                 (8U)
#define LIS_DISP_MIPI_DSI_IRQSTEER_LPI2C_1_IRQ                 (9U)
#define LIS_DISP_MIPI_DSI_IRQSTEER_PWM_IRQ                     (12U)

/** IRQ values for Display Pixel Link 4 LVDS in Display Interface 0 and 1 */
#define LIS_DISP_LVDS_IRQSTEER_LPI2C_0_IRQ                 (8U)
#define LIS_DISP_LVDS_IRQSTEER_LPI2C_1_IRQ                 (9U)
#define LIS_DISP_LVDS_IRQSTEER_PWM_IRQ                     (12U)

/** IRQ values for Display Pixel Link 0 HDMI in Display Interface 0 and HDMI IN in MIPI-CSI2 */
#define LIS_HDMI_IRQSTEER_LPI2C_IRQ                   (8U)
#define LIS_HDMI_IRQSTEER_PWM_IRQ                     (9U)

/** IRQ values for Imaging (MIPI CSI #1) and (MIPI CSI #0) in MIPI-CSI2 */
#define LIS_MIPI_CSI_IRQSTEER_LPI2C_IRQ                   (8U)
#define LIS_MIPI_CSI_IRQSTEER_PWM_IRQ                     (9U)

/** IRQ values for each sub system */
/* LVDS 0*/
#define IRQSTEER_LVDS_0_IRQ            (89U)

/*MIPI-CSI #0 */
#define IRQSTEER_MIPI_CSI_0_IRQ        (352U)

/* Display Interface 0 - Display Pixel Link 0 HDMI */
#define IRQSTEER_HDMI_RX_IRQ           (354U)

#ifdef DERIVATIVE_IMX8_SUPPORT
    /* LVDS 1*/
    #define IRQSTEER_LVDS_1_IRQ         (90U)
    /* MIPI DSI 1*/
    #define IRQSTEER_MIPI_DSI_1_IRQ        (92U)

    /* Display Interface 0 - Display Pixel Link 0 HDMI */
    #define IRQSTEER_HDMI_TX_IRQ                (93U)

    /*MIPI-CSI #1 */
    #define IRQSTEER_MIPI_CSI_1_IRQ             (353U)
#endif

/* MIPI DSI 0*/
#define IRQSTEER_MIPI_DSI_0_IRQ             (91U)
/** IRQ values for each peripherals */
#ifdef DERIVATIVE_IMX8_SUPPORT
#define IRQSTEER_EDMA_0_IRQ                 (98U)
#define IRQSTEER_EDMA_0_ERR_IRQ             (99U)

#define IRQSTEER_EDMA_1_IRQ                 (100U)
#define IRQSTEER_EDMA_1_ERR_IRQ             (101U)

#define IRQSTEER_EDMA_2_IRQ                 (400U)
#define IRQSTEER_EDMA_2_ERR_IRQ             (401U)

#define IRQSTEER_EDMA_3_IRQ                 (402U)
#define IRQSTEER_EDMA_3_ERR_IRQ             (403U)

#else
/* DERIVE_IMX8X_SUPPORT */
#define IRQSTEER_EDMA_2_IRQ                 (98U)
#define IRQSTEER_EDMA_2_ERR_IRQ             (99U)

#define IRQSTEER_EDMA_3_IRQ                 (100U)
#define IRQSTEER_EDMA_3_ERR_IRQ             (101U)

#define IRQSTEER_EDMA_0_IRQ                 (400U)
#define IRQSTEER_EDMA_0_ERR_IRQ             (401U)

#define IRQSTEER_EDMA_1_IRQ                 (402U)
#define IRQSTEER_EDMA_1_ERR_IRQ             (403U)
#endif
/* IRQSteer for DMA channels of Connectivity subsystem */
#define IRQSTEER_EDMA_4_IRQ                 (307U)
#define IRQSTEER_EDMA_4_ERR_IRQ             (308U)

#define IRQSTEER_GPT_0_IRQ                  (112U)
#define IRQSTEER_GPT_1_IRQ                  (113U)
#define IRQSTEER_GPT_2_IRQ                  (114U)
#define IRQSTEER_GPT_3_IRQ                  (115U)
#define IRQSTEER_GPT_4_IRQ                  (116U)
#define IRQSTEER_GPT_5_IRQ                  (428U)
#define IRQSTEER_GPT_6_IRQ                  (427U)
#define IRQSTEER_GPT_7_IRQ                  (426U)
#define IRQSTEER_GPT_8_IRQ                  (425U)
#define IRQSTEER_GPT_9_IRQ                  (424U)
#define IRQSTEER_GPT_10_IRQ                 (423U)

#define IRQSTEER_ESAI_0_IRQ                 (420U)

#define IRQSTEER_FLEXSPI_0                  (124U)

#define IRQSTEER_PWM_0_IRQ                  (126U)
#define IRQSTEER_PWM_1_IRQ                  (127U)
#define IRQSTEER_PWM_2_IRQ                  (128U)
#define IRQSTEER_PWM_3_IRQ                  (129U)
#define IRQSTEER_PWM_4_IRQ                  (130U)
#define IRQSTEER_PWM_5_IRQ                  (131U)
#define IRQSTEER_PWM_6_IRQ                  (132U)
#define IRQSTEER_PWM_7_IRQ                  (133U)

#ifdef DERIVATIVE_IMX8X_SUPPORT
#define IRQSTEER_PWM_8_IRQ                  (95U)
#endif

#define IRQSTEER_SPI_0_IRQ                  (248U)
#define IRQSTEER_SPI_1_IRQ                  (249U)
#define IRQSTEER_SPI_2_IRQ                  (250U)
#define IRQSTEER_SPI_3_IRQ                  (251U)

#define IRQSTEER_I2C_0_IRQ                  (252U)
#define IRQSTEER_I2C_1_IRQ                  (253U)
#define IRQSTEER_I2C_2_IRQ                  (254U)
#define IRQSTEER_I2C_3_IRQ                  (255U)
#define IRQSTEER_I2C_4_IRQ                  (256U)

#define IRQSTEER_UART_0_IRQ                 (257U)
#define IRQSTEER_UART_1_IRQ                 (258U)
#define IRQSTEER_UART_2_IRQ                 (259U)
#define IRQSTEER_UART_3_IRQ                 (260U)
#define IRQSTEER_UART_4_IRQ                 (261U)

#define IRQSTEER_FLEXCAN_0_IRQ              (267U)
#define IRQSTEER_FLEXCAN_1_IRQ              (268U)
#define IRQSTEER_FLEXCAN_2_IRQ              (269U)

#define IRQSTEER_FTM_0_IRQ                  (270U)
#define IRQSTEER_FTM_1_IRQ                  (271U)

#define IRQSTEER_ADC_0_IRQ                  (272U)
#define IRQSTEER_ADC_1_IRQ                  (273U)

#define IRQSTEER_GPIO_0_IRQ                 (168U)
#define IRQSTEER_GPIO_1_IRQ                 (169U)
#define IRQSTEER_GPIO_2_IRQ                 (170U)
#define IRQSTEER_GPIO_3_IRQ                 (171U)
#define IRQSTEER_GPIO_4_IRQ                 (172U)
#define IRQSTEER_GPIO_5_IRQ                 (173U)
#define IRQSTEER_GPIO_6_IRQ                 (174U)
#define IRQSTEER_GPIO_7_IRQ                 (175U)

#define IRQSTEER_ENET0_FRAME1_IRQ           (288U)
#define IRQSTEER_ENET0_FRAME2_IRQ           (289U)
#define IRQSTEER_ENET0_FRAME0_EVENT_IRQ     (290U)
#define IRQSTEER_ENET0_TIMER_INT_IRQ        (291U)
#define IRQSTEER_ENET1_FRAME1_IRQ           (292U)
#define IRQSTEER_ENET1_FRAME2_IRQ           (293U)
#define IRQSTEER_ENET1_FRAME0_EVENT_IRQ     (294U)
#define IRQSTEER_ENET1_TIMER_INT_IRQ        (295U)

#define IRQSTEER_SECO_MU_2_IRQ              (480U)
#define IRQSTEER_SECO_MU_3_IRQ              (481U)
#define IRQSTEER_SECO_MU_4_IRQ              (482U)

#endif /* DERIVATIVE_IMX8DXL_SUPPORT */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif



#endif /* REG_ESYS_IRQSTEER_H */

/** @} */
