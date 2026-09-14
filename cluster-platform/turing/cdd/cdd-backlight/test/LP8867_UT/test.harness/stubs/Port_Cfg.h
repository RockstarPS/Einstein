/**
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 4.0.0
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : SCFW,GPIO
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/


#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_H_REF_1
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
*          accessed from within a single function.
*          These objects are used in various parts of the code.
*
* @section PORT_CFG_H_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
*
*/

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Port_SCFW_Types.h"
#include "Mcal.h"
#include "Reg_eSys_Mu.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_VENDOR_ID_CFG_H                       43
/**
* @violates @ref PORT_CFG_H_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
/**
* @violates @ref PORT_CFG_H_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        2
/**
* @violates @ref PORT_CFG_H_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     2
#define PORT_SW_MAJOR_VERSION_CFG_H                4
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                0

/*=================================================================================================
*                               FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.h and Port_SCFW_Types.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_SCFW_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_SCFW_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_SCFW_Types.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_SCFW_AR_RELEASE_MAJOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_SCFW_AR_RELEASE_MINOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_SCFW_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_SCFW_Types.h are different"
#endif
/* Check if Port_Cfg.h and Port_SCFW_Types.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_SCFW_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_SCFW_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_SCFW_SW_PATCH_VERSION_TYPES_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_SCFW_Types.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief       Ensure better readability of the configuration
* @note 
*
*/
#define SHL_PAD_U32(x)                  ((uint32)(((uint32)1) << (x)))

/**
* @brief GPIO setting not available
* @note The current platform does not implement pad selection for GPIO mode for current pin.
*
*/
#define PORT_NO_GPIO_U8                      ((uint8)0xFFU)

/**
* @brief Port Alternate 0 Mode
*/
#define PORT_ALT0_FUNC_MODE             ((Port_PinModeType)0)
/**
* @brief Port Alternate 1 Mode
*/
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/**
* @brief Port Alternate 2 Mode
*/
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/**
* @brief Port Alternate 3 Mode
*/
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/**
* @brief Port Alternate 4 Mode
*/
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/**
* @brief Port Alternate 5 Mode
*/
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)

#define PORT_ALT8_NO_MUX_MODE           ((Port_PinModeType)8)

/**
* @brief Macro to determinate GPIO mode
*/
#define PORT_GPIO_MODE                  (PORT_ALT4_FUNC_MODE)
#define PORT_IMX8X_USED
/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/

#define PORT_SET_PIN_DIRECTION_API      (STD_ON)


/**
* @brief  Switch to enable/disable the production error reporting.
*/
#define PORT_DISABLE_DEM_REPORT_ERROR_STATUS     (STD_ON)

/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/

#define PORT_SET_PIN_MODE_API           (STD_ON)


/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           (STD_ON)

/**
* @brief Use/remove Not Use Port Pin configuration feature from the compiled driver
*
* @implements   PORT_NOT_USE_PORT_PIN_CFG_define
*/
#define PORT_NOT_USE_PORT_PIN_CFG       (STD_OFF)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/

#define PortConfigSet_PortContainer_0_EN_5V_BOOST  0

#define PortConfigSet_PortContainer_0_MUX1_CTRL_A0  1

#define PortConfigSet_PortContainer_0_MUX1_CTRL_A1  2

#define PortConfigSet_PortContainer_0_MUX1_CTRL_A2  3

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_B34  4

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_K28  5

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_C33  6

#define PortConfigSet_PortContainer_0_BOOST_5V_PGOOD  7

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_J29  8

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_G31  9

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_D34  10

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_E35  11

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_H32  12

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_F34  13

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_G33  14

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_J31  15

#define PortConfigSet_PortContainer_0_EEPROM_SPI_CLK  16

#define PortConfigSet_PortContainer_0_MDO_TT_STOP  17

#define PortConfigSet_PortContainer_0_MDO_TT_PARKING_BRAKE  18

#define PortConfigSet_PortContainer_0_MDO_TT_AIRBAG  19

#define PortConfigSet_PortContainer_0_MDO_TT_LCA_TAKE_OVER  20

#define PortConfigSet_PortContainer_0_DI_FAN_SPD  21

#define PortConfigSet_PortContainer_0_MDO_TT_TURNRIGHT  22

#define PortConfigSet_PortContainer_0_AUDIO_OUT_I2S_TXD  23

#define PortConfigSet_PortContainer_0_AUDIO_OUT_I2S_BCLK  24

#define PortConfigSet_PortContainer_0_AUDIO_OUT_SHUTDOWN  25

#define PortConfigSet_PortContainer_0_AUDIO_OUT_I2S_FS  26

#define PortConfigSet_PortContainer_0_MDO_SBR_LIGHT_OUTPUT  27

#define PortConfigSet_PortContainer_0_MDO_DAY_NIGHT_LIGHT_OUTPUT  28

#define PortConfigSet_PortContainer_0_EEPROM_SPI_CS  29

#define PortConfigSet_PortContainer_0_CANV_HS_STBY  30

#define PortConfigSet_PortContainer_0_AUDIO_I2C_CTRL_SCL  31

#define PortConfigSet_PortContainer_0_MDO_DIMMING_OUT  32

#define PortConfigSet_PortContainer_0_AUDIO_I2C_CTRL_SDA  33

#define PortConfigSet_PortContainer_0_MDO_CS_DIMMING_OUT  34

#define PortConfigSet_PortContainer_0_MDI_DIMMING_OUT  35

#define PortConfigSet_PortContainer_0_MAI_MUX_2  36

#define PortConfigSet_PortContainer_0_MAI_MUX_1  37

#define PortConfigSet_PortContainer_0_MAI_MUX_4  38

#define PortConfigSet_PortContainer_0_MAI_MUX_3  39

#define PortConfigSet_PortContainer_0_MAI_DIMMING_OUT_STATUS  40

#define PortConfigSet_PortContainer_0_MAI_BATT_SUPERV  41

#define PortConfigSet_PortContainer_0_CANV_HS_RX  42

#define PortConfigSet_PortContainer_0_CANV_HS_TX  43

#define PortConfigSet_PortContainer_0_PWM_OUT_MCU  44

#define PortConfigSet_PortContainer_0_CANM_HS_MODE_M  45

#define PortConfigSet_PortContainer_0_CANM_HS_RX_M  46

#define PortConfigSet_PortContainer_0_CANM_HS_TX_M  47

#define PortConfigSet_PortContainer_0_MDO_TT_SERVICE  48

#define PortConfigSet_PortContainer_0_MDO_TT_TURNLEFT  49

#define PortConfigSet_PortContainer_0_MDI_BKL_DRV_FAULT  50

#define PortConfigSet_PortContainer_0_MDO_BKL_DRV_EN  51

#define PortConfigSet_PortContainer_0_DO_EN_3V3_SW_TFT  52

#define PortConfigSet_PortContainer_0_MDO_SVBAT_EN  53

#define PortConfigSet_PortContainer_0_HW_VERSION_CHECK_2  54

#define PortConfigSet_PortContainer_0_HW_VERSION_CHECK_0  55

#define PortConfigSet_PortContainer_0_P_3V3_EE  56

#define PortConfigSet_PortContainer_0_HW_VERSION_CHECK_1  57

#define PortConfigSet_PortContainer_0_MDI_TACHOGRAPH  58

#define PortConfigSet_PortContainer_0_MDI_TRIP_RESET  59

#define PortConfigSet_PortContainer_0_MDO_FUEL_FORCE_OFF  60

#define PortConfigSet_PortContainer_0_MDI_DIMMING1  61

#define PortConfigSet_PortContainer_0_MDI_PARKING_BRAKE  62

#define PortConfigSet_PortContainer_0_MDO_OIL_EN  63

#define PortConfigSet_PortContainer_0_MDI_MINI_WASHER  64

#define PortConfigSet_PortContainer_0_MDI_OIL_PRESSURE  65

#define PortConfigSet_PortContainer_0_ENET_RESET  66

#define PortConfigSet_PortContainer_0_ENET_EN  67

#define PortConfigSet_PortContainer_0_NC_OTL_U13001_D28  68

#define PortConfigSet_PortContainer_0_NC_EN_5V_BOOST  69

#define PortConfigSet_PortContainer_0_EEPROM_SPI_MOSI  70

#define PortConfigSet_PortContainer_0_EEPROM_SPI_MISO  71

#define PortConfigSet_PortContainer_0_MDO_BKL_DRV_DIMMING  72

#define PortConfigSet_PortContainer_0_MDO_TFT_BL_PWR  73

#define PortConfigSet_PortContainer_0_DI_TFT_BRS  74

#define PortConfigSet_PortContainer_0_DO_SPI_SCLK_TFT  75

#define PortConfigSet_PortContainer_0_DO_SPI_MOSI_TFT  76

#define PortConfigSet_PortContainer_0_DI_SPI_MISO_TFT  77

#define PortConfigSet_PortContainer_0_DO_SPI_SS0_TFT  78

#define PortConfigSet_PortContainer_0_ENET_INT  79

#define PortConfigSet_PortContainer_0_DO_OTG_PWR  80

#define PortConfigSet_PortContainer_0_MDI_TFT_LOOP2  81

#define PortConfigSet_PortContainer_0_MDI_TFT_LOOP1  82


/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)5)
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_32BLOCK_NO_U8           ((uint8)6)
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)174)

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)83)

/**
* @brief Port driver Pre-Compile configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT     (STD_ON)


/**
* @brief Define IPC channel for communicate with scfw
*/
#define PORT_IPC_CHANNEL_ID                     (MU1_A_M4_0)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
#if (PORT_NOT_USE_PORT_PIN_CFG == STD_ON)
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) paNotUsedPadArr;
    uint32 PadMode;
} Port_NotUsedCtrlPadConfigType;

typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;
    P2CONST(uint32, AUTOMATIC, PORT_APPL_CONST) paNotUsedPadArr;
    P2CONST(Port_SCFW_NotUsedPinConfigType, AUTOMATIC, PORT_APPL_CONSTW) PadMode;
} Port_NotUsedPadConfigType;

/**
* @brief   Structure needed by Port_ConfigType structure.
* @details The structure Port_UnUsedPinConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
*
*
* @api
*/
typedef struct
{
    CONST(Port_NotUsedCtrlPadConfigType, AUTOMATIC) UnUsedCompCtrlPadConfig;
    CONST(Port_NotUsedCtrlPadConfigType, AUTOMATIC) UnUsedCompCtlPswOverPadConfig;
    CONST(Port_NotUsedCtrlPadConfigType, AUTOMATIC) UnUsedCompSleepPadConfig;
    CONST(Port_NotUsedCtrlPadConfigType, AUTOMATIC) UnUsedCtrlPadConfig;
    CONST(Port_NotUsedCtrlPadConfigType, AUTOMATIC) UnUsedCalibrationPadConfig;
    CONST(Port_NotUsedPadConfigType,     AUTOMATIC) UnUsedPdrvPadConfig;
    CONST(Port_NotUsedPadConfigType,     AUTOMATIC) UnUsedDse2PadConfig;
    CONST(Port_NotUsedPadConfigType,     AUTOMATIC) UnUsedDse3PadConfig;
    CONST(Port_NotUsedPadConfigType,     AUTOMATIC) UnUsedHsicPadConfig;
} Port_UnUsedPinConfigType;
#endif /* PORT_NOT_USE_PORT_PIN_CFG */

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;                                                     /**< @brief Number of used pads (to be configured) */
    P2CONST(Port_SCFW_PinConfigType, AUTOMATIC, PORT_APPL_CONST) pUsedPadConfig;             /**< @brief Used pads data configuration */
    #if (PORT_NOT_USE_PORT_PIN_CFG == STD_ON)
    P2CONST(Port_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pNotUsedPadConfig;
    #endif /* PORT_NOT_USE_PORT_PIN_CFG */
    P2CONST(uint32, AUTOMATIC, PORT_APPL_CONST) u32PortaGpioMap;
} Port_ConfigType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Port_MemMap.h"


#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
/** @violates @ref PORT_CFG_H_REF_1 An object should be defined at block scope if its identifier only appears in a single function. */
extern CONST(Port_ConfigType, Port_CONST) Port_Config;
#endif

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Port_MemMap.h"
/**
* @violates @ref PORT_CFG_H_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_START_SEC_CONFIG_DATA_16

#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/** @violates @ref PORT_CFG_H_REF_1 An object should be defined at block scope if its identifier only appears in a single function. */
extern CONST(uint32, PORT_CONST) Port_au32PinDescription[5][6];
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/**
* @violates @ref PORT_CFG_H_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_STOP_SEC_CONFIG_DATA_16

#include "Port_MemMap.h"


#define PORT_START_SEC_CONST_UNSPECIFIED

#include "Port_MemMap.h"


#define PORT_STOP_SEC_CONST_UNSPECIFIED

#include "Port_MemMap.h"


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */
