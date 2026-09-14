/**
*   @file    Mcl_Scfw_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl .
*   @details Header file containing Types used across multiple service APIs.
*
*   @addtogroup MCL_MODULE
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

#ifndef MCL_SCFW_TYPES_H
#define MCL_SCFW_TYPES_H
#ifdef __cplusplus
extern "C"{
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
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
* do-while-zero construct.
* This is used to abstract the export of configuration sets or for a function define.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include"Platform_Types.h"
#include"Mcal.h"
#include "rpc.h"
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCFW_TYPES_VENDOR_ID_H                    43
#define SCFW_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define SCFW_TYPES_AR_RELEASE_MINOR_VERSION_H     2
#define SCFW_TYPES_AR_RELEASE_REVISION_VERSION_H  2
#define SCFW_TYPES_SW_MAJOR_VERSION_H             4
#define SCFW_TYPES_SW_MINOR_VERSION_H             0
#define SCFW_TYPES_SW_PATCH_VERSION_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((SCFW_TYPES_AR_RELEASE_MAJOR_VERSION_H != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (SCFW_TYPES_AR_RELEASE_MINOR_VERSION_H != PLATFORM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcl_Scfw_Types.h and Platform_Types.h are different"
    #endif
    
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((SCFW_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SCFW_TYPES_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcl_Scfw_Types.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
 * @name Defines for chip IDs
 */
/** @{ */
#define CHIP_ID_QM      0x1U   /*!< i.MX8QM */
#define CHIP_ID_QX      0x2U   /*!< i.MX8QX*/
#define CHIP_ID_DXL     0xEU   /*!< i.MX8DXL */
/** @} */

/*!
 * @name Defines for common frequencies
 */
/** @{ */
#define SCFW_32KHZ            32768U   /*!< 32KHz */
#define SCFW_1MHZ           1000000U   /*!< 1MHz  */
#define SCFW_10MHZ         10000000U   /*!< 10MHz */
#define SCFW_16MHZ         16000000U   /*!< 16MHz */
#define SCFW_20MHZ         20000000U   /*!< 20MHz */
#define SCFW_25MHZ         25000000U   /*!< 25MHz */
#define SCFW_27MHZ         27000000U   /*!< 27MHz */
#define SCFW_40MHZ         40000000U   /*!< 40MHz */
#define SCFW_45MHZ         45000000U   /*!< 45MHz */
#define SCFW_50MHZ         50000000U   /*!< 50MHz */
#define SCFW_60MHZ         60000000U   /*!< 60MHz */
#define SCFW_66MHZ         66666666U   /*!< 66MHz */
#define SCFW_74MHZ         74250000U   /*!< 74.25MHz */
#define SCFW_80MHZ         80000000U   /*!< 80MHz */
#define SCFW_83MHZ         83333333U   /*!< 83MHz */
#define SCFW_84MHZ         84375000U   /*!< 84.37MHz */
#define SCFW_100MHZ       100000000U   /*!< 100MHz */
#define SCFW_114MHZ       114000000U   /*!< 114MHz */
#define SCFW_125MHZ       125000000U   /*!< 125MHz */
#define SCFW_128MHZ       128000000U   /*!< 128MHz */
#define SCFW_133MHZ       133333333U   /*!< 133MHz */
#define SCFW_135MHZ       135000000U   /*!< 135MHz */
#define SCFW_150MHZ       150000000U   /*!< 150MHz */
#define SCFW_160MHZ       160000000U   /*!< 160MHz */
#define SCFW_166MHZ       166666666U   /*!< 166MHz */
#define SCFW_175MHZ       175000000U   /*!< 175MHz */
#define SCFW_180MHZ       180000000U   /*!< 180MHz */
#define SCFW_200MHZ       200000000U   /*!< 200MHz */
#define SCFW_250MHZ       250000000U   /*!< 250MHz */
#define SCFW_266MHZ       266666666U   /*!< 266MHz */
#define SCFW_300MHZ       300000000U   /*!< 300MHz */
#define SCFW_312MHZ       312500000U   /*!< 312.5MHZ */
#define SCFW_320MHZ       320000000U   /*!< 320MHz */
#define SCFW_325MHZ       325000000U   /*!< 325MHz */
#define SCFW_333MHZ       333333333U   /*!< 333MHz */
#define SCFW_350MHZ       350000000U   /*!< 350MHz */
#define SCFW_368MHZ       368500000U   /*!< 368.5MHZ */
#define SCFW_372MHZ       372000000U   /*!< 372MHz */
#define SCFW_375MHZ       375000000U   /*!< 375MHz */
#define SCFW_400MHZ       400000000U   /*!< 400MHz */
#define SCFW_465MHZ       465000000U   /*!< 465MHz */
#define SCFW_500MHZ       500000000U   /*!< 500MHz */
#define SCFW_594MHZ       594000000U   /*!< 594MHz */
#define SCFW_625MHZ       625000000U   /*!< 625MHz */
#define SCFW_640MHZ       640000000U   /*!< 640MHz */
#define SCFW_648MHZ       648000000U   /*!< 648MHz */
#define SCFW_650MHZ       650000000U   /*!< 650MHz */
#define SCFW_667MHZ       666666667U   /*!< 667MHz */
#define SCFW_675MHZ       675000000U   /*!< 675MHz */
#define SCFW_700MHZ       700000000U   /*!< 700MHz */
#define SCFW_720MHZ       720000000U   /*!< 720MHz */
#define SCFW_750MHZ       750000000U   /*!< 750MHz */
#define SCFW_753MHZ       753000000U   /*!< 753MHz */
#define SCFW_793MHZ       793000000U   /*!< 793MHz */
#define SCFW_800MHZ       800000000U   /*!< 800MHz */
#define SCFW_850MHZ       850000000U   /*!< 850MHz */
#define SCFW_858MHZ       858000000U   /*!< 858MHz */
#define SCFW_900MHZ       900000000U   /*!< 900MHz */
#define SCFW_953MHZ       953000000U   /*!< 953MHz */
#define SCFW_963MHZ       963000000U   /*!< 963MHz */
#define SCFW_1000MHZ     1000000000U   /*!< 1GHz */
#define SCFW_1060MHZ     1060000000U   /*!< 1.06GHz */
#define SCFW_1068MHZ     1068000000U   /*!< 1.068GHz */
#define SCFW_1121MHZ     1121000000U   /*!< 1.121GHz */
#define SCFW_1173MHZ     1173000000U   /*!< 1.173GHz */
#define SCFW_1188MHZ     1188000000U   /*!< 1.188GHz */
#define SCFW_1260MHZ     1260000000U   /*!< 1.26GHz */
#define SCFW_1278MHZ     1278000000U   /*!< 1.278GHz */
#define SCFW_1280MHZ     1280000000U   /*!< 1.28GHz */
#define SCFW_1300MHZ     1300000000U   /*!< 1.3GHz */
#define SCFW_1313MHZ     1313000000U   /*!< 1.313GHz */
#define SCFW_1345MHZ     1345000000U   /*!< 1.345GHz */
#define SCFW_1400MHZ     1400000000U   /*!< 1.4GHz */
#define SCFW_1500MHZ     1500000000U   /*!< 1.5GHz */
#define SCFW_1600MHZ     1600000000U   /*!< 1.6GHz */
#define SCFW_1800MHZ     1800000000U   /*!< 1.8GHz */
#define SCFW_1860MHZ     1860000000U   /*!< 1.86GHz */
#define SCFW_2000MHZ     2000000000U   /*!< 2.0GHz */
#define SCFW_2112MHZ     2112000000U   /*!< 2.12GHz */
/** @} */

/*!
 * @name Defines for 24M related frequencies
 */
/** @{ */
#define SCFW_8MHZ           8000000U   /*!< 8MHz */
#define SCFW_12MHZ         12000000U   /*!< 12MHz */
#define SCFW_19MHZ         19800000U   /*!< 19.8MHz */
#define SCFW_24MHZ         24000000U   /*!< 24MHz */
#define SCFW_48MHZ         48000000U   /*!< 48MHz */
#define SCFW_120MHZ       120000000U   /*!< 120MHz */
#define SCFW_132MHZ       132000000U   /*!< 132MHz */
#define SCFW_144MHZ       144000000U   /*!< 144MHz */
#define SCFW_192MHZ       192000000U   /*!< 192MHz */
#define SCFW_211MHZ       211200000U   /*!< 211.2MHz */
#define SCFW_228MHZ       228000000U   /*!< 233MHz */
#define SCFW_240MHZ       240000000U   /*!< 240MHz */
#define SCFW_264MHZ       264000000U   /*!< 264MHz */
#define SCFW_352MHZ       352000000U   /*!< 352MHz */
#define SCFW_360MHZ       360000000U   /*!< 360MHz */
#define SCFW_384MHZ       384000000U   /*!< 384MHz */
#define SCFW_396MHZ       396000000U   /*!< 396MHz */
#define SCFW_432MHZ       432000000U   /*!< 432MHz */
#define SCFW_456MHZ       456000000U   /*!< 466MHz */
#define SCFW_480MHZ       480000000U   /*!< 480MHz */
#define SCFW_600MHZ       600000000U   /*!< 600MHz */
#define SCFW_744MHZ       744000000U   /*!< 744MHz */
#define SCFW_792MHZ       792000000U   /*!< 792MHz */
#define SCFW_864MHZ       864000000U   /*!< 864MHz */
#define SCFW_912MHZ       912000000U   /*!< 912MHz */
#define SCFW_960MHZ       960000000U   /*!< 960MHz */
#define SCFW_1056MHZ     1056000000U   /*!< 1056MHz */
#define SCFW_1104MHZ     1104000000U   /*!< 1104MHz */
#define SCFW_1200MHZ     1200000000U   /*!< 1.2GHz */
#define SCFW_1464MHZ     1464000000U   /*!< 1.464GHz */
#define SCFW_2400MHZ     2400000000U   /*!< 2.4GHz */
/** @} */

/*!
 * @name Defines for A/V related frequencies
 */
/** @{ */
#define SCFW_62MHZ         62937500U   /*!< 62.9375MHz */
#define SCFW_755MHZ       755250000U   /*!< 755.25MHz */
/** @} */


/*!
 * @name Defines for Mcl_Scfw_BoolType
 */
/** @{ */
#define SCFW_FALSE        ((Mcl_Scfw_BoolType) 0U)    /*!< False */
#define SCFW_TRUE         ((Mcl_Scfw_BoolType) 1U)    /*!< True */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_ErrType
 */
/** @{ */
#define SCFW_ERR_NONE         0U      /*!< Success */
#define SCFW_ERR_VERSION      1U      /*!< Incompatible API version */
#define SCFW_ERR_CONFIG       2U      /*!< configuration error */
#define SCFW_ERR_PARM         3U      /*!< Bad parameter */
#define SCFW_ERR_NOACCESS     4U      /*!< Permission error (no access) */
#define SCFW_ERR_LOCKED       5U      /*!< Permission error (Locked) */
#define SCFW_ERR_UNAVAILABLE  6U      /*!< Unavailable (out of Resources) */
#define SCFW_ERR_NOTFOUND     7U      /*!< Not found */
#define SCFW_ERR_NOPOWER      8U      /*!< No power */
#define SCFW_ERR_IPC          9U      /*!< Generic IPC error */
#define SCFW_ERR_BUSY         10U     /*!< Resource is currently busy/active */
#define SCFW_ERR_FAIL         11U     /*!< General I/O failure */
#define SCFW_ERR_LAST         12U
/** @} */

/*!
 * @name Defines for Mcl_Scfw_RsrcType
 */
/** @{ */
#define SCFW_R_AP_0                 0U
#define SCFW_R_AP_0_0               1U
#define SCFW_R_AP_0_1               2U
#define SCFW_R_AP_0_2               3U
#define SCFW_R_AP_0_3               4U
#define SCFW_R_AP_1                 5U
#define SCFW_R_AP_1_0               6U
#define SCFW_R_AP_1_1               7U
#define SCFW_R_AP_1_2               8U
#define SCFW_R_AP_1_3               9U
#define SCFW_R_CCI                  10U
#define SCFW_R_DB                   11U
#define SCFW_R_DRC_0                12U
#define SCFW_R_DRC_1                13U
#define SCFW_R_GIC_SMMU             14U
#define SCFW_R_IRQSTR_MCU_0         15U
#define SCFW_R_IRQSTR_MCU_1         16U
#define SCFW_R_SMMU_0               17U
#define SCFW_R_GIC_0                18U
#define SCFW_R_DC_0_BLIT0           19U
#define SCFW_R_DC_0_BLIT1           20U
#define SCFW_R_DC_0_BLIT2           21U
#define SCFW_R_DC_0_BLIT_OUT        22U
#define SCFW_R_PERF                 23U
#define SCFW_R_USB_1_PHY            24U
#define SCFW_R_DC_0_WARP            25U
#define SCFW_R_V2X_MU_0             26U
#define SCFW_R_V2X_MU_1             27U
#define SCFW_R_DC_0_VIDEO0          28U
#define SCFW_R_DC_0_VIDEO1          29U
#define SCFW_R_DC_0_FRAC0           30U
#define SCFW_R_V2X_MU_2             31U
#define SCFW_R_DC_0                 32U
#define SCFW_R_GPU_2_PID0           33U
#define SCFW_R_DC_0_PLL_0           34U
#define SCFW_R_DC_0_PLL_1           35U
#define SCFW_R_DC_1_BLIT0           36U
#define SCFW_R_DC_1_BLIT1           37U
#define SCFW_R_DC_1_BLIT2           38U
#define SCFW_R_DC_1_BLIT_OUT        39U
#define SCFW_R_V2X_MU_3             40U
#define SCFW_R_V2X_MU_4             41U
#define SCFW_R_DC_1_WARP            42U
#define SCFW_R_UNUSED1              43U
#define SCFW_R_SECVIO               44U
#define SCFW_R_DC_1_VIDEO0          45U
#define SCFW_R_DC_1_VIDEO1          46U
#define SCFW_R_DC_1_FRAC0           47U
#define SCFW_R_UNUSED13             48U
#define SCFW_R_DC_1                 49U
#define SCFW_R_UNUSED14             50U
#define SCFW_R_DC_1_PLL_0           51U
#define SCFW_R_DC_1_PLL_1           52U
#define SCFW_R_SPI_0                53U
#define SCFW_R_SPI_1                54U
#define SCFW_R_SPI_2                55U
#define SCFW_R_SPI_3                56U
#define SCFW_R_UART_0               57U
#define SCFW_R_UART_1               58U
#define SCFW_R_UART_2               59U
#define SCFW_R_UART_3               60U
#define SCFW_R_UART_4               61U
#define SCFW_R_EMVSIM_0             62U
#define SCFW_R_EMVSIM_1             63U
#define SCFW_R_DMA_0_CH0            64U
#define SCFW_R_DMA_0_CH1            65U
#define SCFW_R_DMA_0_CH2            66U
#define SCFW_R_DMA_0_CH3            67U
#define SCFW_R_DMA_0_CH4            68U
#define SCFW_R_DMA_0_CH5            69U
#define SCFW_R_DMA_0_CH6            70U
#define SCFW_R_DMA_0_CH7            71U
#define SCFW_R_DMA_0_CH8            72U
#define SCFW_R_DMA_0_CH9            73U
#define SCFW_R_DMA_0_CH10           74U
#define SCFW_R_DMA_0_CH11           75U
#define SCFW_R_DMA_0_CH12           76U
#define SCFW_R_DMA_0_CH13           77U
#define SCFW_R_DMA_0_CH14           78U
#define SCFW_R_DMA_0_CH15           79U
#define SCFW_R_DMA_0_CH16           80U
#define SCFW_R_DMA_0_CH17           81U
#define SCFW_R_DMA_0_CH18           82U
#define SCFW_R_DMA_0_CH19           83U
#define SCFW_R_DMA_0_CH20           84U
#define SCFW_R_DMA_0_CH21           85U
#define SCFW_R_DMA_0_CH22           86U
#define SCFW_R_DMA_0_CH23           87U
#define SCFW_R_DMA_0_CH24           88U
#define SCFW_R_DMA_0_CH25           89U
#define SCFW_R_DMA_0_CH26           90U
#define SCFW_R_DMA_0_CH27           91U
#define SCFW_R_DMA_0_CH28           92U
#define SCFW_R_DMA_0_CH29           93U
#define SCFW_R_DMA_0_CH30           94U
#define SCFW_R_DMA_0_CH31           95U
#define SCFW_R_I2C_0                96U
#define SCFW_R_I2C_1                97U
#define SCFW_R_I2C_2                98U
#define SCFW_R_I2C_3                99U
#define SCFW_R_I2C_4                100U
#define SCFW_R_ADC_0                101U
#define SCFW_R_ADC_1                102U
#define SCFW_R_FTM_0                103U
#define SCFW_R_FTM_1                104U
#define SCFW_R_CAN_0                105U
#define SCFW_R_CAN_1                106U
#define SCFW_R_CAN_2                107U
#define SCFW_R_DMA_1_CH0            108U
#define SCFW_R_DMA_1_CH1            109U
#define SCFW_R_DMA_1_CH2            110U
#define SCFW_R_DMA_1_CH3            111U
#define SCFW_R_DMA_1_CH4            112U
#define SCFW_R_DMA_1_CH5            113U
#define SCFW_R_DMA_1_CH6            114U
#define SCFW_R_DMA_1_CH7            115U
#define SCFW_R_DMA_1_CH8            116U
#define SCFW_R_DMA_1_CH9            117U
#define SCFW_R_DMA_1_CH10           118U
#define SCFW_R_DMA_1_CH11           119U
#define SCFW_R_DMA_1_CH12           120U
#define SCFW_R_DMA_1_CH13           121U
#define SCFW_R_DMA_1_CH14           122U
#define SCFW_R_DMA_1_CH15           123U
#define SCFW_R_DMA_1_CH16           124U
#define SCFW_R_DMA_1_CH17           125U
#define SCFW_R_DMA_1_CH18           126U
#define SCFW_R_DMA_1_CH19           127U
#define SCFW_R_DMA_1_CH20           128U
#define SCFW_R_DMA_1_CH21           129U
#define SCFW_R_DMA_1_CH22           130U
#define SCFW_R_DMA_1_CH23           131U
#define SCFW_R_DMA_1_CH24           132U
#define SCFW_R_DMA_1_CH25           133U
#define SCFW_R_DMA_1_CH26           134U
#define SCFW_R_DMA_1_CH27           135U
#define SCFW_R_DMA_1_CH28           136U
#define SCFW_R_DMA_1_CH29           137U
#define SCFW_R_DMA_1_CH30           138U
#define SCFW_R_DMA_1_CH31           139U
#define SCFW_R_V2X_PID0             140U
#define SCFW_R_V2X_PID1             141U
#define SCFW_R_V2X_PID2             142U
#define SCFW_R_V2X_PID3             143U
#define SCFW_R_GPU_0_PID0           144U
#define SCFW_R_GPU_0_PID1           145U
#define SCFW_R_GPU_0_PID2           146U
#define SCFW_R_GPU_0_PID3           147U
#define SCFW_R_GPU_1_PID0           148U
#define SCFW_R_GPU_1_PID1           149U
#define SCFW_R_GPU_1_PID2           150U
#define SCFW_R_GPU_1_PID3           151U
#define SCFW_R_PCIE_A               152U
#define SCFW_R_SERDES_0             153U
#define SCFW_R_MATCH_0              154U
#define SCFW_R_MATCH_1              155U
#define SCFW_R_MATCH_2              156U
#define SCFW_R_MATCH_3              157U
#define SCFW_R_MATCH_4              158U
#define SCFW_R_MATCH_5              159U
#define SCFW_R_MATCH_6              160U
#define SCFW_R_MATCH_7              161U
#define SCFW_R_MATCH_8              162U
#define SCFW_R_MATCH_9              163U
#define SCFW_R_MATCH_10             164U
#define SCFW_R_MATCH_11             165U
#define SCFW_R_MATCH_12             166U
#define SCFW_R_MATCH_13             167U
#define SCFW_R_MATCH_14             168U
#define SCFW_R_PCIE_B               169U
#define SCFW_R_SATA_0               170U
#define SCFW_R_SERDES_1             171U
#define SCFW_R_HSIO_GPIO            172U
#define SCFW_R_MATCH_15             173U
#define SCFW_R_MATCH_16             174U
#define SCFW_R_MATCH_17             175U
#define SCFW_R_MATCH_18             176U
#define SCFW_R_MATCH_19             177U
#define SCFW_R_MATCH_20             178U
#define SCFW_R_MATCH_21             179U
#define SCFW_R_MATCH_22             180U
#define SCFW_R_MATCH_23             181U
#define SCFW_R_MATCH_24             182U
#define SCFW_R_MATCH_25             183U
#define SCFW_R_MATCH_26             184U
#define SCFW_R_MATCH_27             185U
#define SCFW_R_MATCH_28             186U
#define SCFW_R_LCD_0                187U
#define SCFW_R_LCD_0_PWM_0          188U
#define SCFW_R_LCD_0_I2C_0          189U
#define SCFW_R_LCD_0_I2C_1          190U
#define SCFW_R_PWM_0                191U
#define SCFW_R_PWM_1                192U
#define SCFW_R_PWM_2                193U
#define SCFW_R_PWM_3                194U
#define SCFW_R_PWM_4                195U
#define SCFW_R_PWM_5                196U
#define SCFW_R_PWM_6                197U
#define SCFW_R_PWM_7                198U
#define SCFW_R_GPIO_0               199U
#define SCFW_R_GPIO_1               200U
#define SCFW_R_GPIO_2               201U
#define SCFW_R_GPIO_3               202U
#define SCFW_R_GPIO_4               203U
#define SCFW_R_GPIO_5               204U
#define SCFW_R_GPIO_6               205U
#define SCFW_R_GPIO_7               206U
#define SCFW_R_GPT_0                207U
#define SCFW_R_GPT_1                208U
#define SCFW_R_GPT_2                209U
#define SCFW_R_GPT_3                210U
#define SCFW_R_GPT_4                211U
#define SCFW_R_KPP                  212U
#define SCFW_R_MU_0A                213U
#define SCFW_R_MU_1A                214U
#define SCFW_R_MU_2A                215U
#define SCFW_R_MU_3A                216U
#define SCFW_R_MU_4A                217U
#define SCFW_R_MU_5A                218U
#define SCFW_R_MU_6A                219U
#define SCFW_R_MU_7A                220U
#define SCFW_R_MU_8A                221U
#define SCFW_R_MU_9A                222U
#define SCFW_R_MU_10A               223U
#define SCFW_R_MU_11A               224U
#define SCFW_R_MU_12A               225U
#define SCFW_R_MU_13A               226U
#define SCFW_R_MU_5B                227U
#define SCFW_R_MU_6B                228U
#define SCFW_R_MU_7B                229U
#define SCFW_R_MU_8B                230U
#define SCFW_R_MU_9B                231U
#define SCFW_R_MU_10B               232U
#define SCFW_R_MU_11B               233U
#define SCFW_R_MU_12B               234U
#define SCFW_R_MU_13B               235U
#define SCFW_R_ROM_0                236U
#define SCFW_R_FSPI_0               237U
#define SCFW_R_FSPI_1               238U
#define SCFW_R_IEE                  239U
#define SCFW_R_IEE_R0               240U
#define SCFW_R_IEE_R1               241U
#define SCFW_R_IEE_R2               242U
#define SCFW_R_IEE_R3               243U
#define SCFW_R_IEE_R4               244U
#define SCFW_R_IEE_R5               245U
#define SCFW_R_IEE_R6               246U
#define SCFW_R_IEE_R7               247U
#define SCFW_R_SDHC_0               248U
#define SCFW_R_SDHC_1               249U
#define SCFW_R_SDHC_2               250U
#define SCFW_R_ENET_0               251U
#define SCFW_R_ENET_1               252U
#define SCFW_R_MLB_0                253U
#define SCFW_R_DMA_2_CH0            254U
#define SCFW_R_DMA_2_CH1            255U
#define SCFW_R_DMA_2_CH2            256U
#define SCFW_R_DMA_2_CH3            257U
#define SCFW_R_DMA_2_CH4            258U
#define SCFW_R_USB_0                259U
#define SCFW_R_USB_1                260U
#define SCFW_R_USB_0_PHY            261U
#define SCFW_R_USB_2                262U
#define SCFW_R_USB_2_PHY            263U
#define SCFW_R_DTCP                 264U
#define SCFW_R_NAND                 265U
#define SCFW_R_LVDS_0               266U
#define SCFW_R_LVDS_0_PWM_0         267U
#define SCFW_R_LVDS_0_I2C_0         268U
#define SCFW_R_LVDS_0_I2C_1         269U
#define SCFW_R_LVDS_1               270U
#define SCFW_R_LVDS_1_PWM_0         271U
#define SCFW_R_LVDS_1_I2C_0         272U
#define SCFW_R_LVDS_1_I2C_1         273U
#define SCFW_R_LVDS_2               274U
#define SCFW_R_LVDS_2_PWM_0         275U
#define SCFW_R_LVDS_2_I2C_0         276U
#define SCFW_R_LVDS_2_I2C_1         277U
#define SCFW_R_MCU_0_PID0           278U
#define SCFW_R_MCU_0_PID1           279U
#define SCFW_R_MCU_0_PID2           280U
#define SCFW_R_MCU_0_PID3           281U
#define SCFW_R_MCU_0_PID4           282U
#define SCFW_R_MCU_0_RGPIO          283U
#define SCFW_R_MCU_0_SEMA42         284U
#define SCFW_R_MCU_0_TPM            285U
#define SCFW_R_MCU_0_PIT            286U
#define SCFW_R_MCU_0_UART           287U
#define SCFW_R_MCU_0_I2C            288U
#define SCFW_R_MCU_0_INTMUX         289U
#define SCFW_R_ENET_0_A0            290U
#define SCFW_R_ENET_0_A1            291U
#define SCFW_R_MCU_0_MU_0B          292U
#define SCFW_R_MCU_0_MU_0A0         293U
#define SCFW_R_MCU_0_MU_0A1         294U
#define SCFW_R_MCU_0_MU_0A2         295U
#define SCFW_R_MCU_0_MU_0A3         296U
#define SCFW_R_MCU_0_MU_1A          297U
#define SCFW_R_MCU_1_PID0           298U
#define SCFW_R_MCU_1_PID1           299U
#define SCFW_R_MCU_1_PID2           300U
#define SCFW_R_MCU_1_PID3           301U
#define SCFW_R_MCU_1_PID4           302U
#define SCFW_R_MCU_1_RGPIO          303U
#define SCFW_R_MCU_1_SEMA42         304U
#define SCFW_R_MCU_1_TPM            305U
#define SCFW_R_MCU_1_PIT            306U
#define SCFW_R_MCU_1_UART           307U
#define SCFW_R_MCU_1_I2C            308U
#define SCFW_R_MCU_1_INTMUX         309U
#define SCFW_R_UNUSED17             310U
#define SCFW_R_UNUSED18             311U
#define SCFW_R_MCU_1_MU_0B          312U
#define SCFW_R_MCU_1_MU_0A0         313U
#define SCFW_R_MCU_1_MU_0A1         314U
#define SCFW_R_MCU_1_MU_0A2         315U
#define SCFW_R_MCU_1_MU_0A3         316U
#define SCFW_R_MCU_1_MU_1A          317U
#define SCFW_R_SAI_0                318U
#define SCFW_R_SAI_1                319U
#define SCFW_R_SAI_2                320U
#define SCFW_R_IRQSTR_SCU2          321U
#define SCFW_R_IRQSTR_DSP           322U
#define SCFW_R_ELCDIF_PLL           323U
#define SCFW_R_OCRAM                324U
#define SCFW_R_AUDIO_PLL_0          325U
#define SCFW_R_PI_0                 326U
#define SCFW_R_PI_0_PWM_0           327U
#define SCFW_R_PI_0_PWM_1           328U
#define SCFW_R_PI_0_I2C_0           329U
#define SCFW_R_PI_0_PLL             330U
#define SCFW_R_PI_1                 331U
#define SCFW_R_PI_1_PWM_0           332U
#define SCFW_R_PI_1_PWM_1           333U
#define SCFW_R_PI_1_I2C_0           334U
#define SCFW_R_PI_1_PLL             335U
#define SCFW_R_SC_PID0              336U
#define SCFW_R_SC_PID1              337U
#define SCFW_R_SC_PID2              338U
#define SCFW_R_SC_PID3              339U
#define SCFW_R_SC_PID4              340U
#define SCFW_R_SC_SEMA42            341U
#define SCFW_R_SC_TPM               342U
#define SCFW_R_SC_PIT               343U
#define SCFW_R_SC_UART              344U
#define SCFW_R_SC_I2C               345U
#define SCFW_R_SC_MU_0B             346U
#define SCFW_R_SC_MU_0A0            347U
#define SCFW_R_SC_MU_0A1            348U
#define SCFW_R_SC_MU_0A2            349U
#define SCFW_R_SC_MU_0A3            350U
#define SCFW_R_SC_MU_1A             351U
#define SCFW_R_SYSCNT_RD            352U
#define SCFW_R_SYSCNT_CMP           353U
#define SCFW_R_DEBUG                354U
#define SCFW_R_SYSTEM               355U
#define SCFW_R_SNVS                 356U
#define SCFW_R_OTP                  357U
#define SCFW_R_VPU_PID0             358U
#define SCFW_R_VPU_PID1             359U
#define SCFW_R_VPU_PID2             360U
#define SCFW_R_VPU_PID3             361U
#define SCFW_R_VPU_PID4             362U
#define SCFW_R_VPU_PID5             363U
#define SCFW_R_VPU_PID6             364U
#define SCFW_R_VPU_PID7             365U
#define SCFW_R_ENET_0_A2            366U
#define SCFW_R_ENET_1_A0            367U
#define SCFW_R_ENET_1_A1            368U
#define SCFW_R_ENET_1_A2            369U
#define SCFW_R_ENET_1_A3            370U
#define SCFW_R_ENET_1_A4            371U
#define SCFW_R_DMA_4_CH0            372U
#define SCFW_R_DMA_4_CH1            373U
#define SCFW_R_DMA_4_CH2            374U
#define SCFW_R_DMA_4_CH3            375U
#define SCFW_R_DMA_4_CH4            376U
#define SCFW_R_ISI_CH0              377U
#define SCFW_R_ISI_CH1              378U
#define SCFW_R_ISI_CH2              379U
#define SCFW_R_ISI_CH3              380U
#define SCFW_R_ISI_CH4              381U
#define SCFW_R_ISI_CH5              382U
#define SCFW_R_ISI_CH6              383U
#define SCFW_R_ISI_CH7              384U
#define SCFW_R_MJPEG_DEC_S0         385U
#define SCFW_R_MJPEG_DEC_S1         386U
#define SCFW_R_MJPEG_DEC_S2         387U
#define SCFW_R_MJPEG_DEC_S3         388U
#define SCFW_R_MJPEG_ENC_S0         389U
#define SCFW_R_MJPEG_ENC_S1         390U
#define SCFW_R_MJPEG_ENC_S2         391U
#define SCFW_R_MJPEG_ENC_S3         392U
#define SCFW_R_MIPI_0               393U
#define SCFW_R_MIPI_0_PWM_0         394U
#define SCFW_R_MIPI_0_I2C_0         395U
#define SCFW_R_MIPI_0_I2C_1         396U
#define SCFW_R_MIPI_1               397U
#define SCFW_R_MIPI_1_PWM_0         398U
#define SCFW_R_MIPI_1_I2C_0         399U
#define SCFW_R_MIPI_1_I2C_1         400U
#define SCFW_R_CSI_0                401U
#define SCFW_R_CSI_0_PWM_0          402U
#define SCFW_R_CSI_0_I2C_0          403U
#define SCFW_R_CSI_1                404U
#define SCFW_R_CSI_1_PWM_0          405U
#define SCFW_R_CSI_1_I2C_0          406U
#define SCFW_R_HDMI                 407U
#define SCFW_R_HDMI_I2S             408U
#define SCFW_R_HDMI_I2C_0           409U
#define SCFW_R_HDMI_PLL_0           410U
#define SCFW_R_HDMI_RX              411U
#define SCFW_R_HDMI_RX_BYPASS       412U
#define SCFW_R_HDMI_RX_I2C_0        413U
#define SCFW_R_ASRC_0               414U
#define SCFW_R_ESAI_0               415U
#define SCFW_R_SPDIF_0              416U
#define SCFW_R_SPDIF_1              417U
#define SCFW_R_SAI_3                418U
#define SCFW_R_SAI_4                419U
#define SCFW_R_SAI_5                420U
#define SCFW_R_GPT_5                421U
#define SCFW_R_GPT_6                422U
#define SCFW_R_GPT_7                423U
#define SCFW_R_GPT_8                424U
#define SCFW_R_GPT_9                425U
#define SCFW_R_GPT_10               426U
#define SCFW_R_DMA_2_CH5            427U
#define SCFW_R_DMA_2_CH6            428U
#define SCFW_R_DMA_2_CH7            429U
#define SCFW_R_DMA_2_CH8            430U
#define SCFW_R_DMA_2_CH9            431U
#define SCFW_R_DMA_2_CH10           432U
#define SCFW_R_DMA_2_CH11           433U
#define SCFW_R_DMA_2_CH12           434U
#define SCFW_R_DMA_2_CH13           435U
#define SCFW_R_DMA_2_CH14           436U
#define SCFW_R_DMA_2_CH15           437U
#define SCFW_R_DMA_2_CH16           438U
#define SCFW_R_DMA_2_CH17           439U
#define SCFW_R_DMA_2_CH18           440U
#define SCFW_R_DMA_2_CH19           441U
#define SCFW_R_DMA_2_CH20           442U
#define SCFW_R_DMA_2_CH21           443U
#define SCFW_R_DMA_2_CH22           444U
#define SCFW_R_DMA_2_CH23           445U
#define SCFW_R_DMA_2_CH24           446U
#define SCFW_R_DMA_2_CH25           447U
#define SCFW_R_DMA_2_CH26           448U
#define SCFW_R_DMA_2_CH27           449U
#define SCFW_R_DMA_2_CH28           450U
#define SCFW_R_DMA_2_CH29           451U
#define SCFW_R_DMA_2_CH30           452U
#define SCFW_R_DMA_2_CH31           453U
#define SCFW_R_ASRC_1               454U
#define SCFW_R_ESAI_1               455U
#define SCFW_R_SAI_6                456U
#define SCFW_R_SAI_7                457U
#define SCFW_R_AMIX                 458U
#define SCFW_R_MQS_0                459U
#define SCFW_R_DMA_3_CH0            460U
#define SCFW_R_DMA_3_CH1            461U
#define SCFW_R_DMA_3_CH2            462U
#define SCFW_R_DMA_3_CH3            463U
#define SCFW_R_DMA_3_CH4            464U
#define SCFW_R_DMA_3_CH5            465U
#define SCFW_R_DMA_3_CH6            466U
#define SCFW_R_DMA_3_CH7            467U
#define SCFW_R_DMA_3_CH8            468U
#define SCFW_R_DMA_3_CH9            469U
#define SCFW_R_DMA_3_CH10           470U
#define SCFW_R_DMA_3_CH11           471U
#define SCFW_R_DMA_3_CH12           472U
#define SCFW_R_DMA_3_CH13           473U
#define SCFW_R_DMA_3_CH14           474U
#define SCFW_R_DMA_3_CH15           475U
#define SCFW_R_DMA_3_CH16           476U
#define SCFW_R_DMA_3_CH17           477U
#define SCFW_R_DMA_3_CH18           478U
#define SCFW_R_DMA_3_CH19           479U
#define SCFW_R_DMA_3_CH20           480U
#define SCFW_R_DMA_3_CH21           481U
#define SCFW_R_DMA_3_CH22           482U
#define SCFW_R_DMA_3_CH23           483U
#define SCFW_R_DMA_3_CH24           484U
#define SCFW_R_DMA_3_CH25           485U
#define SCFW_R_DMA_3_CH26           486U
#define SCFW_R_DMA_3_CH27           487U
#define SCFW_R_DMA_3_CH28           488U
#define SCFW_R_DMA_3_CH29           489U
#define SCFW_R_DMA_3_CH30           490U
#define SCFW_R_DMA_3_CH31           491U
#define SCFW_R_AUDIO_PLL_1          492U
#define SCFW_R_AUDIO_CLK_0          493U
#define SCFW_R_AUDIO_CLK_1          494U
#define SCFW_R_MCLK_OUT_0           495U
#define SCFW_R_MCLK_OUT_1           496U
#define SCFW_R_PMIC_0               497U
#define SCFW_R_PMIC_1               498U
#define SCFW_R_SECO                 499U
#define SCFW_R_CAAM_JR1             500U
#define SCFW_R_CAAM_JR2             501U
#define SCFW_R_CAAM_JR3             502U
#define SCFW_R_SECO_MU_2            503U
#define SCFW_R_SECO_MU_3            504U
#define SCFW_R_SECO_MU_4            505U
#define SCFW_R_HDMI_RX_PWM_0        506U
#define SCFW_R_AP_2                 507U
#define SCFW_R_AP_2_0               508U
#define SCFW_R_AP_2_1               509U
#define SCFW_R_AP_2_2               510U
#define SCFW_R_AP_2_3               511U
#define SCFW_R_DSP                  512U
#define SCFW_R_DSP_RAM              513U
#define SCFW_R_CAAM_JR1_OUT         514U
#define SCFW_R_CAAM_JR2_OUT         515U
#define SCFW_R_CAAM_JR3_OUT         516U
#define SCFW_R_VPU_DEC_0            517U
#define SCFW_R_VPU_ENC_0            518U
#define SCFW_R_CAAM_JR0             519U
#define SCFW_R_CAAM_JR0_OUT         520U
#define SCFW_R_PMIC_2               521U
#define SCFW_R_DBLOGIC              522U
#define SCFW_R_HDMI_PLL_1           523U
#define SCFW_R_BOARD_R0             524U
#define SCFW_R_BOARD_R1             525U
#define SCFW_R_BOARD_R2             526U
#define SCFW_R_BOARD_R3             527U
#define SCFW_R_BOARD_R4             528U
#define SCFW_R_BOARD_R5             529U
#define SCFW_R_BOARD_R6             530U
#define SCFW_R_BOARD_R7             531U
#define SCFW_R_MJPEG_DEC_MP         532U
#define SCFW_R_MJPEG_ENC_MP         533U
#define SCFW_R_VPU_TS_0             534U
#define SCFW_R_VPU_MU_0             535U
#define SCFW_R_VPU_MU_1             536U
#define SCFW_R_VPU_MU_2             537U
#define SCFW_R_VPU_MU_3             538U
#define SCFW_R_VPU_ENC_1            539U
#define SCFW_R_VPU                  540U
#define SCFW_R_DMA_5_CH0            541U
#define SCFW_R_DMA_5_CH1            542U
#define SCFW_R_DMA_5_CH2            543U
#define SCFW_R_DMA_5_CH3            544U
#define SCFW_R_ATTESTATION          545U
#define SCFW_R_LAST                 546U
#define SCFW_R_ALL                  ((Mcl_Scfw_RsrcType) UINT16_MAX)  /*!< All Resources */
/** @} */

/*!
 * @name Compatibility defines for Mcl_Scfw_RsrcType
 */
/** @{ */
#define SCFW_R_A53                  SCFW_R_AP_0
#define SCFW_R_A53_0                SCFW_R_AP_0_0
#define SCFW_R_A53_1                SCFW_R_AP_0_1
#define SCFW_R_A53_2                SCFW_R_AP_0_2
#define SCFW_R_A53_3                SCFW_R_AP_0_3
#define SCFW_R_A72                  SCFW_R_AP_1
#define SCFW_R_A72_0                SCFW_R_AP_1_0
#define SCFW_R_A72_1                SCFW_R_AP_1_1
#define SCFW_R_A72_2                SCFW_R_AP_1_2
#define SCFW_R_A72_3                SCFW_R_AP_1_3
#define SCFW_R_A35                  SCFW_R_AP_2
#define SCFW_R_A35_0                SCFW_R_AP_2_0
#define SCFW_R_A35_1                SCFW_R_AP_2_1
#define SCFW_R_A35_2                SCFW_R_AP_2_2
#define SCFW_R_A35_3                SCFW_R_AP_2_3
#define SCFW_R_IRQSTR_M4_0          SCFW_R_IRQSTR_MCU_0
#define SCFW_R_IRQSTR_M4_1          SCFW_R_IRQSTR_MCU_1
#define SCFW_R_M4_0_PID0            SCFW_R_MCU_0_PID0
#define SCFW_R_M4_0_PID1            SCFW_R_MCU_0_PID1
#define SCFW_R_M4_0_PID2            SCFW_R_MCU_0_PID2
#define SCFW_R_M4_0_PID3            SCFW_R_MCU_0_PID3
#define SCFW_R_M4_0_PID4            SCFW_R_MCU_0_PID4
#define SCFW_R_M4_0_RGPIO           SCFW_R_MCU_0_RGPIO
#define SCFW_R_M4_0_SEMA42          SCFW_R_MCU_0_SEMA42
#define SCFW_R_M4_0_TPM             SCFW_R_MCU_0_TPM
#define SCFW_R_M4_0_PIT             SCFW_R_MCU_0_PIT
#define SCFW_R_M4_0_UART            SCFW_R_MCU_0_UART
#define SCFW_R_M4_0_I2C             SCFW_R_MCU_0_I2C
#define SCFW_R_M4_0_INTMUX          SCFW_R_MCU_0_INTMUX
#define SCFW_R_M4_0_MU_0B           SCFW_R_MCU_0_MU_0B
#define SCFW_R_M4_0_MU_0A0          SCFW_R_MCU_0_MU_0A0
#define SCFW_R_M4_0_MU_0A1          SCFW_R_MCU_0_MU_0A1
#define SCFW_R_M4_0_MU_0A2          SCFW_R_MCU_0_MU_0A2
#define SCFW_R_M4_0_MU_0A3          SCFW_R_MCU_0_MU_0A3
#define SCFW_R_M4_0_MU_1A           SCFW_R_MCU_0_MU_1A
#define SCFW_R_M4_1_PID0            SCFW_R_MCU_1_PID0
#define SCFW_R_M4_1_PID1            SCFW_R_MCU_1_PID1
#define SCFW_R_M4_1_PID2            SCFW_R_MCU_1_PID2
#define SCFW_R_M4_1_PID3            SCFW_R_MCU_1_PID3
#define SCFW_R_M4_1_PID4            SCFW_R_MCU_1_PID4
#define SCFW_R_M4_1_RGPIO           SCFW_R_MCU_1_RGPIO
#define SCFW_R_M4_1_SEMA42          SCFW_R_MCU_1_SEMA42
#define SCFW_R_M4_1_TPM             SCFW_R_MCU_1_TPM
#define SCFW_R_M4_1_PIT             SCFW_R_MCU_1_PIT
#define SCFW_R_M4_1_UART            SCFW_R_MCU_1_UART
#define SCFW_R_M4_1_I2C             SCFW_R_MCU_1_I2C
#define SCFW_R_M4_1_INTMUX          SCFW_R_MCU_1_INTMUX
#define SCFW_R_M4_1_MU_0B           SCFW_R_MCU_1_MU_0B
#define SCFW_R_M4_1_MU_0A0          SCFW_R_MCU_1_MU_0A0
#define SCFW_R_M4_1_MU_0A1          SCFW_R_MCU_1_MU_0A1
#define SCFW_R_M4_1_MU_0A2          SCFW_R_MCU_1_MU_0A2
#define SCFW_R_M4_1_MU_0A3          SCFW_R_MCU_1_MU_0A3
#define SCFW_R_M4_1_MU_1A           SCFW_R_MCU_1_MU_1A
#define SCFW_R_SMMU                 SCFW_R_SMMU_0
#define SCFW_R_GIC                  SCFW_R_GIC_0
/** @} */

/*!
 * Define for ATF/Linux. Not used by SCFW. Not a Valid parameter
 * for any SCFW API calls!
 */
#define SCFW_R_NONE                 0xFFF0U

/* NOTE - please add by replacing some of the UNUSED from above! */

/*!
 * Defines for Mcl_Scfw_CtrlType
 */
#define SCFW_C_TEMP                       0U
#define SCFW_C_TEMP_HI                    1U
#define SCFW_C_TEMP_LOW                   2U
#define SCFW_C_PXL_LINK_MST1_ADDR         3U
#define SCFW_C_PXL_LINK_MST2_ADDR         4U
#define SCFW_C_PXL_LINK_MST_ENB           5U
#define SCFW_C_PXL_LINK_MST1_ENB          6U
#define SCFW_C_PXL_LINK_MST2_ENB          7U
#define SCFW_C_PXL_LINK_SLV1_ADDR         8U
#define SCFW_C_PXL_LINK_SLV2_ADDR         9U
#define SCFW_C_PXL_LINK_MST_VLD           10U
#define SCFW_C_PXL_LINK_MST1_VLD          11U
#define SCFW_C_PXL_LINK_MST2_VLD          12U
#define SCFW_C_SINGLE_MODE                13U
#define SCFW_C_ID                         14U
#define SCFW_C_PXL_CLK_POLARITY           15U
#define SCFW_C_LINESTATE                  16U
#define SCFW_C_PCIE_G_RST                 17U
#define SCFW_C_PCIE_BUTTON_RST            18U
#define SCFW_C_PCIE_PERST                 19U
#define SCFW_C_PHY_RESET                  20U
#define SCFW_C_PXL_LINK_RATE_CORRECTION   21U
#define SCFW_C_PANIC                      22U
#define SCFW_C_PRIORITY_GROUP             23U
#define SCFW_C_TXCLK                      24U
#define SCFW_C_CLKDIV                     25U
#define SCFW_C_DISABLE_50                 26U
#define SCFW_C_DISABLE_125                27U
#define SCFW_C_SEL_125                    28U
#define SCFW_C_MODE                       29U
#define SCFW_C_SYNC_CTRL0                 30U
#define SCFW_C_KACHUNK_CNT                31U
#define SCFW_C_KACHUNK_SEL                32U
#define SCFW_C_SYNC_CTRL1                 33U
#define SCFW_C_DPI_RESET                  34U
#define SCFW_C_MIPI_RESET                 35U
#define SCFW_C_DUAL_MODE                  36U
#define SCFW_C_VOLTAGE                    37U
#define SCFW_C_PXL_LINK_SEL               38U
#define SCFW_C_OFS_SEL                    39U
#define SCFW_C_OFS_AUDIO                  40U
#define SCFW_C_OFS_PERIPH                 41U
#define SCFW_C_OFS_IRQ                    42U
#define SCFW_C_RST0                       43U
#define SCFW_C_RST1                       44U
#define SCFW_C_SEL0                       45U
#define SCFW_C_CALIB0                     46U
#define SCFW_C_CALIB1                     47U
#define SCFW_C_CALIB2                     48U
#define SCFW_C_IPG_DEBUG                  49U
#define SCFW_C_IPG_DOZE                   50U
#define SCFW_C_IPG_WAIT                   51U
#define SCFW_C_IPG_STOP                   52U
#define SCFW_C_IPG_STOP_MODE              53U
#define SCFW_C_IPG_STOP_ACK               54U
#define SCFW_C_SYNC_CTRL                  55U
#define SCFW_C_OFS_AUDIO_ALT              56U
#define SCFW_C_DSP_BYP                    57U
#define SCFW_C_CLK_GEN_EN	              58U
#define SCFW_C_INTF_SEL                   59U
#define SCFW_C_RXC_DLY                    60U
#define SCFW_C_TIMER_SEL                  61U
#define SCFW_C_MISC0                      62U
#define SCFW_C_MISC1                      63U
#define SCFW_C_MISC2                      64U
#define SCFW_C_MISC3                      65U
#define SCFW_C_LAST                       66U

/*!
 * Define for used to specify all Pads
 */
#define SCFW_P_ALL        ((Mcl_Scfw_PadType) UINT16_MAX)   /*!< All Pads */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
//typedef sc_rpc_msg_t Mcl_Scfw_RpcMsgType;
/*!
 * This Type is used to declare an ID for an IPC communication
 * channel. Its meaning is specific to the IPC implementation.
 */
typedef uint32 Mcl_Scfw_IpcIdType;

/*!
 * This Type is used to declare a handle for an IPC communication
 * channel. Its meaning is specific to the IPC implementation.
 */
typedef uint32 Mcl_Scfw_IpcType;

/*!
 * This Type is used to store a boolean.
 */
typedef uint8 Mcl_Scfw_BoolType;

/*!
 * This Type is used to store a system (full-size) address.
 */
typedef uint64 Mcl_Scfw_FaddrType;

/*!
 * This Type is used to indicate error response for most functions.
 */
typedef uint8 Mcl_Scfw_ErrType;

/*!
 * This Type is used to indicate a Resource. Resources include peripherals
 * and bus masters (but not memory regions). Note items from list should
 * never be changed or removed (only added to at the end of the list).
 */
typedef uint16 Mcl_Scfw_RsrcType;

/*!
 * This Type is used to indicate a control.
 */
typedef uint32 Mcl_Scfw_CtrlType;

/*!
 * This Type is used to indicate a Pad. Valid Values are SoC specific.
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
typedef uint16 Mcl_Scfw_PadType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
#endif /* MCL_SCFW_TYPES_H */
/** @} */
