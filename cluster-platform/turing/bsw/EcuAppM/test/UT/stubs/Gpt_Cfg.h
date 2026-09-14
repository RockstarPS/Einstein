/**
*   @file    Gpt_Cfg.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*            configuration header file.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20201231
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2020 NXP
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

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, Braces not used for some macros
* Braces are not used for macros which expand to multiple statements separated by ";" character.
*
* @section GPT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Some global variables used by a single driver function shall be
* exported to user application.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref GPT_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Mcal.h"

#include "Reg_eSys_Ftm.h"
#include "Reg_eSys_LPit.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG                    43
/** @violates @ref GPT_CFG_H_REF_2  MISRA 2004 Required Rule 1.4 Identifier clash */
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @violates @ref GPT_CFG_H_REF_2  MISRA 2004 Required Rule 1.4 Identifier clash */
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     2
/** @violates @ref GPT_CFG_H_REF_2  MISRA 2004 Required Rule 1.4 Identifier clash */
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  2
#define GPT_SW_MAJOR_VERSION_CFG             4
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Mcal.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Cfg.h and Mcal.h are different"
    #endif
#endif



#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Gpt_Cfg.h and Reg_eSys_Ftm.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Reg_eSys_Ftm.h are different"
    #endif

    /* Check if Gpt_Cfg.h and Reg_eSys_LPit.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Reg_eSys_LPit.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Gpt Dev error detect switch
*
*/
#define GPT_DEV_ERROR_DETECT (STD_ON)

/**
* @brief Report Wakeup Source switch
*/
#define GPT_REPORT_WAKEUP_SOURCE (STD_ON)

/**
* @brief GPT_VERSION_INFO_API switch
*
*/
#define GPT_VERSION_INFO_API (STD_ON)

/**
* @brief GPT_DEINIT_API switch
*
*/
#define GPT_DEINIT_API (STD_ON)

/**
* @brief GPT_TIME_ELAPSED_API switch
*
*/
#define GPT_TIME_ELAPSED_API (STD_ON)

/**
* @brief GPT_TIME_REMAINING_API switch
*
*/
#define GPT_TIME_REMAINING_API (STD_ON)

/**
* @brief GPT_ENABLE_DISABLE_NOTIFICATION_API switch
*
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)

/**
* @brief GPT_WAKEUP_FUNCTIONALITY_API switch
*
*/
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_ON)

/**
* @brief GPT_PREDEFTIMER_FUNCTIONALITY_API switch
*
*/
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_OFF)

/**
* @brief Enable/disable support for changing timeout value during timer running
*
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE            (STD_OFF)

/**
* @brief Prescaler type. Indicates of whether the clock channel mode is "GPT_NORMAL" or "GPT_ALTERNATE".
*/
#define GPT_SET_CLOCK_MODE           (STD_OFF)

/**
* @brief Support Clock Source Selection for STM Timers
*/

/**
* @brief Enable/disable API for Chain Mode.
*/
#define GPT_CHAIN_MODE              (STD_OFF)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define GPT_USER_MODE_SOFT_LOCKING       (STD_OFF)

#define GPT_LPIT_ENABLE_EXT_TRIGGERS     (STD_OFF)


/**
* @brief  Post-build Support ON.
*/
#define GPT_PRECOMPILE_SUPPORT (STD_OFF)


#define GPT_GPT_2_ISR_USED
#define GPT_GPT_3_ISR_USED
#define GPT_GPT_4_ISR_USED
#define GPT_GPT_5_ISR_USED
#define GPT_GPT_6_ISR_USED

/**
* @brief These defines indicate that at least one chennel from each module is used in all configurations.
*
*/
#define GPT_FTM_USED (STD_OFF)

#define GPT_GPT_USED (STD_ON)

#define GPT_TPM_USED (STD_OFF)

#define GPT_LPIT_USED (STD_OFF)

/**
* @{
* @brief Symbolic names of channels
*/

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_60MHzFRT  (0U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_M4WDOG  (1U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_ClockMonGpt5  (2U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_ClockMonGpt4  (3U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_AdcTimer  (4U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_ExtWdgTrigger  (5U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_DIMMINGOUT  (6U)
            

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_CANTP  (7U)
            

/*@}*/

/**
* @brief This define is a reserved logical channel name representing a not existing/configured
*        hardware channel.
*
*/
#define GPT_CHN_NOT_USED    (255U)




/**
* @brief The number of configured total GPT channels
*/
#define GPT_HW_CHANNEL_NUM   (8U)

/**
* @brief The number of Ftm HW modules
*/
#define GPT_FTM_MODULES_NUM_U8   ((uint8)2U)

/**
* @brief The number of Ftm HW channels
*/
#define GPT_FTM_MODULE_CHAN_NUM_U8      ((uint8)(GPT_FTM_MODULES_NUM_U8*8))

/**
* @brief The number of Gpt HW modules
*/
#define GPT_GPT_MODULES_NUM_U8      ((uint8)11U)

/**
* @brief The number of Gpt HW channels
*/
#define GPT_GPT_MODULE_CHAN_NUM_U8         ((uint8)(GPT_GPT_MODULES_NUM_U8*3))

/**
* @brief The number of Tpm HW modules
*/
#define GPT_TPM_MODULES_NUM_U8      ((uint8)1U)

/**
* @brief The number of Tpm HW channels
*/
#define GPT_TPM_MODULE_CHAN_NUM_U8         ((uint8)(GPT_TPM_MODULES_NUM_U8*6))

/**
* @brief The number of LPit HW modules
*/
#define GPT_LPIT_MODULES_NUM_U8      ((uint8)1U)

/**
* @brief The number of LPit HW channels
*/
#define GPT_LPIT_MODULE_CHAN_NUM_U8         ((uint8)(GPT_LPIT_MODULES_NUM_U8*4))

/**
* @brief The total number of indexes used by the hardware to logic channel map
*/
#define GPT_CHANNEL_IDX_NUM    (GPT_GPT_MODULE_CHAN_NUM_U8 + GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_TPM_MODULE_CHAN_NUM_U8 + GPT_LPIT_MODULE_CHAN_NUM_U8)

/**
@{
@brief ID for peripheral. This ID need to match the order in the hardware to logic channels mapping table
*      because it is used as a base index.
*/
#define GPT_FTM_MODULE                         0U                                                           /** @brief index where the GPT channels start*/
#define GPT_GPT_MODULE                         (GPT_FTM_MODULE_CHAN_NUM_U8)                                 /** @brief index where the FTM channels start*/
#define GPT_TPM_MODULE                         (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_GPT_MODULE_CHAN_NUM_U8)    /** @brief index where the TPM channels start*/
#define GPT_LPIT_MODULE                        (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_GPT_MODULE_CHAN_NUM_U8 + GPT_TPM_MODULE_CHAN_NUM_U8) /** @brief index where the LPIT channels start*/
/** @} */

/**
* @brief  Switch to enable/disable the production error reporting.
*/
#define GPT_DISABLE_DEM_REPORT_ERROR_STATUS           (STD_ON)

 /**
 * @brief      This is a timeout value which is used to wait till
 *                  - the software reset complete.
 */
 #define GPT_TIMEOUT_COUNTER                     ((uint32)0xFFFFUL)


#define GPT_HW_PREDEFTIMER_NUM                              (4U) /** @brief number for channels predef timer supported by the platform */
 /* GPT counter has 32 bits */
 #define GPT_CNT_MAX_VALUE        ((uint32)0xFFFFFFFFUL)

/**
*   @brief export configuration Gpt driver
*/



    
/**
 * @violates @ref GPT_CFG_H_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to...
 */
#define GPT_CONF_PB \
 extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_Config;

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief Predef Timer type. Indicates the type of predef timer.
* @implements   Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* GPT_CFG_H */

/** @} */
