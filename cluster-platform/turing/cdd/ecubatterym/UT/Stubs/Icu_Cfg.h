/**
*   @file Icu_Cfg.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM GPT TPM
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20201231
*
*       Copyright 2006-2016 Freescale Semiconductor, Inc. 
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

#ifndef ICU_CFG_H
#define ICU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
* @section [global]
*          Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects
*          and functions shall not be reused. The driver needs to use defines starting with letter E
* @section Icu_Cfg_h_REF_2
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct.
*          This is used to abstract the export of configuration sets
* @section Icu_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
* @section Icu_Cfg_h_REF_4
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
*          are only accessed from within a single function.
*          These objects are used in various parts of the code
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Icu_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
//#include "Icu_EnvCfg.h"
/*
* @violates @ref Icu_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
//#include "Reg_eSys_Gpio.h"



/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_CFG                       43
/* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_AR_RELEASE_MAJOR_VERSION_CFG        4
/* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_AR_RELEASE_MINOR_VERSION_CFG        2
/* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_AR_RELEASE_REVISION_VERSION_CFG     2

#define ICU_SW_MAJOR_VERSION_CFG                4
#define ICU_SW_MINOR_VERSION_CFG                0
#define ICU_SW_PATCH_VERSION_CFG                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
// /* Check if source file and Icu_EnvCfg header file are of the same vendor */
// #if (ICU_VENDOR_ID_CFG != ICU_ENVCFG_VENDOR_ID)
//     #error "Icu_Cfg.h and Icu_EnvCfg.h have different vendor IDs"
// #endif
// /* Check if source file and Icu_EnvCfg header file are of the same AutoSar version */
// #if ((ICU_AR_RELEASE_MAJOR_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
//      (ICU_AR_RELEASE_MINOR_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
//      (ICU_AR_RELEASE_REVISION_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_REVISION_VERSION))
//     #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
// #endif
// /* Check if source file and Icu_EnvCfg header file are of the same Software version */
// #if ((ICU_SW_MAJOR_VERSION_CFG != ICU_ENVCFG_SW_MAJOR_VERSION) || \
//      (ICU_SW_MINOR_VERSION_CFG != ICU_ENVCFG_SW_MINOR_VERSION) || \
//      (ICU_SW_PATCH_VERSION_CFG != ICU_ENVCFG_SW_PATCH_VERSION))
// #error "Software Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
// #endif




// /* Check if Icu_Cfg.h and Reg_eSys_Gpio.h file are of the same Autosar version */
// #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
// #if ((ICU_AR_RELEASE_MAJOR_VERSION_CFG != REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG) || \
//      (ICU_AR_RELEASE_MINOR_VERSION_CFG != REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG))
//     #error "AutoSar Version Numbers of Icu_Cfg.h and Reg_eSys_Gpio.h are different"
// #endif
// #endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
*    @brief Implementation specific.
*     Each channel provides a DMA resolution of 16 bits.
*/
#define  ICU_DMA_SIZE           (DMA_SIZE_2BYTES)
/**
*    @brief Implementation specific.
*     DMA number of bytes transfer on a minor loop is 2 bytes - for 16 bits hw registers.
*/
#define  ICU_DMA_NUM_BYTES      (2U)
/**
*    @brief Implementation specific.
*     DMA offset is 16 bits hw registers.
*/
#define  ICU_DMA_OFFSET         (DMA_OFFSET_16_BITS)
/**
*   @brief   Get A number of Ftm hardware modules from resource file
*/
#define ICU_NUM_FTM_HW_MODULE_U8  ((uint8)1U)
/**
*   @brief   Get A number of Gpt hardware modules from resource file
*/
#define ICU_NUM_GPT_HW_MODULE_U8  ((uint8)2U)
/**
*   @brief   Get A number of Gpio hardware modules from resource file
*/
#define ICU_NUM_GPIO_HW_MODULE_U8  ((uint8)6U)
/**
*   @brief   Get A number of Tpm hardware modules from resource file
*/
#define ICU_NUM_TPM_HW_MODULE_U8  ((uint8)1U)

/**
@{
*   @brief Implementation specific.
*       Each channel provides a subset of the functionality available in the unified channel,
*      at a resolution of 16 bits.
*/
#define FTM_COUNTER_MASK          ((Icu_ValueType)0xFFFFU)
#define GPT_COUNTER_MASK          ((Icu_ValueType)0xFFFFFFFFU)
#define TPM_COUNTER_MASK          ((Icu_ValueType)0xFFFFFFFFU)

#define ICU_CAPTURE_REGISTER_MASK   (((Icu_ValueType)0xFFFFU))

/**
 *   @brief Maximum number of ICU channels configured
 */
#define ICU_MAX_CHANNEL     ((Icu_ChannelType)1U)


/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled.
*        STD_OFF: Disabled.
*/
#define ICU_DEV_ERROR_DETECT            (STD_ON)

/**
*   @brief  Switch for enabling Wakeup source reporting.
*        STD_ON: Report Wakeup source.
*        STD_OFF: Do not report Wakeup source.
*
*/
#define ICU_REPORT_WAKEUP_SOURCE        (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Icu_GetVersionInfo() from the code.
*        STD_ON: Icu_GetVersionInfo() can be used.
*        STD_OFF: Icu_GetVersionInfo() can not be used.
*
*/
#define ICU_GET_VERSION_INFO_API        (STD_ON)

/**
*   @brief  Adds or removes the service Icu_DeInit() from the code.
*        STD_ON: Icu_DeInit() can be used. STD_OFF: Icu_DeInit() can not be used.
*   @implements ICU_DE_INIT_API_define
*/
#define ICU_DE_INIT_API                 (STD_ON)

/**
*   @brief  Adds or removes the service Icu_SetMode() from the code.
*        STD_ON: Icu_SetMode() can be used.
*        STD_OFF: Icu_SetMode() can not be used.
*   @implements ICU_SET_MODE_API_define
*/
#define ICU_SET_MODE_API                (STD_ON)

/**
*   @brief  Adds or removes the service Icu_DisableWakeup() from the code.
*        STD_ON: Icu_DisableWakeup() can be used.
*        STD_OFF: Icu_DisableWakeup() can not be used.
*   @implements ICU_DISABLE_WAKEUP_API_define
*/
#define ICU_DISABLE_WAKEUP_API          (STD_ON)

/**
*   @brief  Adds or removes the service Icu_EnableWakeup() from the code.
*        STD_ON: Icu_EnableWakeup() can be used.
*        STD_OFF: Icu_EnableWakeup() can not be used.
*   @implements ICU_ENABLE_WAKEUP_API_define
*/
#define ICU_ENABLE_WAKEUP_API           (STD_ON)

/**
*   @brief  Adds or removes all services related to the timestamping functionality as listed
*        below from the code: Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implements ICU_TIMESTAMP_API_define
*/
#define ICU_TIMESTAMP_API               (STD_ON)

/**
*   @brief  Adds or removes all services related to the edge counting functionality as listed below,
*           from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(),
*           Icu_GetEdgeNumbers().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implementsICU_EDGE_COUNT_API_define
*/
#define ICU_EDGE_COUNT_API              (STD_ON)

/**
*   @brief  Adds or removes the service Icu_GetTimeElapsed() from the code.
*        STD_ON: Icu_GetTimeElapsed() can be used.
*        STD_OFF: Icu_GetTimeElapsed() can not be used.
*   @implements ICU_GET_TIME_ELAPSED_API_define
*/
#define ICU_GET_TIME_ELAPSED_API        (STD_ON)

/**
*   @brief  Adds or removes the service Icu_GetDutyCycleValues() from the code.
*        STD_ON: Icu_GetDutyCycleValues() can be used.
*        STD_OFF: Icu_GetDutyCycleValues() can not be used.
*   @implements ICU_GET_DUTY_CYCLE_VALUES_API_define
*/
#define ICU_GET_DUTY_CYCLE_VALUES_API   (STD_ON)

/**
*   @brief  Adds or removes the service Icu_GetInputState() from the code.
*        STD_ON: Icu_GetInputState() can be used.
*        STD_OFF: Icu_GetInputState() can not be used.
*   @implements ICU_GET_INPUT_STATE_API_define
*/
#define ICU_GET_INPUT_STATE_API         (STD_ON)

/**
*   @brief  Adds or removes the services Icu_StartSignalMeasurement() and
*          Icu_StopSignalMeasurement() from the code.
*        STD_ON: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
*        STD_OFF: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
*   @implements ICU_SIGNAL_MEASUREMENT_API_define
*/
#define ICU_SIGNAL_MEASUREMENT_API      (STD_ON)

/**
*   @brief  Adds or removes the service Icu_CheckWakeup() from the code.
*        STD_ON: Icu_CheckWakeup() can be used.
*        STD_OFF: Icu_CheckWakeup() can not be used.
*   @implements ICU_WAKEUP_FUNCTIONALITY_API_define
*/
#define ICU_WAKEUP_FUNCTIONALITY_API      (STD_ON)

/**
*   @brief  Adds or removes the services Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection()
*           from the code.
*        STD_ON: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can be used.
*        STD_OFF: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can not be used.
*
*   @implements  ICU_EDGE_DETECT_API_define
*/
#define ICU_EDGE_DETECT_API      (STD_ON)

/**
*   @brief  Implementation specific parameter
*        Adds or Removes the code related to overflow notification
*        STD_ON: Overflow notification function will be called if overflow occurs
*        STD_OFF: Overflow notification function will not be called though overflow occurs
*
*/
#define ICU_OVERFLOW_NOTIFICATION_API      (STD_OFF)

/**
*   @brief   Adds or removes the service Icu_GetInputLevel() from the code.
*         STD_ON:  Icu_GetInputLevel() can be used.
*         STD_OFF: Icu_GetInputLevel() can not be used.
*
*
*/
#define ICU_GET_INPUT_LEVEL_API             (STD_OFF)
/**@}*/

/**
*   @brief   Adds / removes the service Icu_GetPulseWidth() from the code.
*         STD_ON:  Icu_GetPulseWidth() can be used.
*         STD_OFF: Icu_GetPulseWidth() can not be used.
*/
#define ICU_GET_PULSE_WIDTH_API             (STD_OFF)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*           USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT,
*                                          user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define ICU_USER_MODE_SOFT_LOCKING       (STD_OFF)
/**@}*/

/**
*   @brief    Adds or removes the support  measurement with DMA
*         STD_ON:  DMA measurement can be used.
*         STD_OFF: DMA measurement can not be used.
*
*
*/


#define ICU_SIGNALMEASUREMENT_USES_DMA    (STD_OFF)

#define ICU_TIMESTAMP_USES_DMA            (STD_OFF)


/**
*   @brief   Adds / removes the service Icu_SetClockMode() from the code
*         At this point, this is disabled
*         STD_ON:  Icu_SetClockMode() can be used.
*         STD_OFF: Icu_SetClockMode() can not be used.
*
*/
#define ICU_DUAL_CLOCK_MODE_API        (STD_OFF)

/**
*   @brief   Adds / removes the service Icu_GetCaptureRegisterValue() from the code.
*         STD_ON:  Icu_GetCaptureRegisterValue() can be used.
*         STD_OFF: Icu_GetCaptureRegisterValue() can not be used.
*/
#define ICU_CAPTURERGISTER_API         (STD_OFF)

/**
*   @brief Selects or disables code in the HLD regarding setting channel level
*         prescalers
*         STD_ON:  There are channel prescalers on at least one IP
*         STD_OFF: There aren't channel prescalers on any IP
*
*/
#define ICU_USE_CHANNEL_PRESCALER    (STD_OFF)


/**
*   @brief No Mcl Dma Channel
*/
#define NoMclDmaChannel ((Mcl_ChannelType)0xFF)

 /**
*   @brief Icu Channel symbolic names
*   @details Get All Symbolic Names from configuration tool
*
*   @{
*/
#define NoIcuChannel  ((Icu_ChannelType)0xFF)

#define IcuChannel_VCAN_RX                     (IcuConf_IcuChannel_IcuChannel_VCAN_RX)
/* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define IcuConf_IcuChannel_IcuChannel_VCAN_RX  ((Icu_ChannelType)0U) 

/**
* @brief Signal measurement mode
* @details define SAIC mode if any channels not supporting IPWM or IPM mode is configured
* @{
*/

/* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define SIGNAL_MEASUREMENT_USES_SAIC_MODE            (STD_OFF)

/**@}*/

/**
*   @details Macros for Ftm used
*   @{
*/

/**@}*/

/**
*   @details Macros for Gpt used
*   @{
*/

/**@}*/

/**
*   @details Macros for Tpm used
*   @{
*/

/**@}*/

/**
*   @details Macros for Gpio used
*   @{
*/
#define ICU_GPIO_1_USED

/**
*   @brief ISR's configured for Icu channels
*   @details Macros for channels used in ISR
*   @{
*/
#define ICU_GPIO_1_ISR_USED 

/**
*   @brief export configuration icu driver
*/


/**
* @violates @ref Icu_Cfg_h_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to a braced initialiser
*/
#define ICU_CONF_PB \
 extern CONST(Icu_ConfigType, ICU_CONST) Icu_Config;



/**@}*/
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 Icu_TimerRegisterWidthType;

/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Description: Type, to abstract the return value of the service Icu_GetTimestampIndex().
*/
typedef uint32 Icu_HwSpecificIndexType;

/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Description: Type, to abstract the return value of the service Icu_GetEdgeNumbers().
*/
typedef uint32 Icu_HwSpecificEdgeNumberType;



/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /* ICU_CFG_H */
/**@}*/

