/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_CDisplayCdd_Type.h
 *           Config:  Audi_Etron_TV2.dpa
 *      ECU-Project:  Audi_Etron_TV2
 *
 *        Generator:  MICROSAR RTE Generator Version 4.39.00
 *                    RTE Core Version 4.39.00
 *          License:  CBD2500735
 *
 *      Description:  Application types header file for SW-C <CDisplayCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDISPLAYCDD_TYPE_H
# define RTE_CDISPLAYCDD_TYPE_H

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
#  ifndef eDeviceNotReady
#   define eDeviceNotReady (0U)
#  endif

#  ifndef eDeviceInitialized
#   define eDeviceInitialized (1U)
#  endif

#  ifndef eDeviceReady
#   define eDeviceReady (2U)
#  endif

#  ifndef eDeviceBusy
#   define eDeviceBusy (3U)
#  endif

#  ifndef eDeviceFault
#   define eDeviceFault (4U)
#  endif

#  ifndef eDeviceMaxState
#   define eDeviceMaxState (5U)
#  endif
#  ifndef eDisplayNotReady
#   define eDisplayNotReady (0U)
#  endif

#  ifndef eDisplayReady
#   define eDisplayReady (1U)
#  endif

#  ifndef eDisplayBusy
#   define eDisplayBusy (2U)
#  endif

#  ifndef eDisplayFaultHandle
#   define eDisplayFaultHandle (3U)
#  endif

#  ifndef eDisplayMaxStatus
#   define eDisplayMaxStatus (4U)
#  endif
#  ifndef eDisplayIdle
#   define eDisplayIdle (0U)
#  endif

#  ifndef eDisplayPowerON
#   define eDisplayPowerON (1U)
#  endif

#  ifndef eDisplayNormal
#   define eDisplayNormal (2U)
#  endif

#  ifndef eDisplayPowerOFF
#   define eDisplayPowerOFF (3U)
#  endif

#  ifndef eDisplayFault_Handle
#   define eDisplayFault_Handle (4U)
#  endif

#  ifndef eDisplayMaxPowerState
#   define eDisplayMaxPowerState (5U)
#  endif
#  ifndef e_Display10Inch
#   define e_Display10Inch (0U)
#  endif

#  ifndef e_DisplayMaxDevice
#   define e_DisplayMaxDevice (1U)
#  endif
#  ifndef eDisplayCdd_GammaCorrection_None
#   define eDisplayCdd_GammaCorrection_None (0U)
#  endif

#  ifndef eDisplayCdd_GammaCorrection_OnGoing
#   define eDisplayCdd_GammaCorrection_OnGoing (1U)
#  endif

#  ifndef eDisplayCdd_GammaCorrection_Success
#   define eDisplayCdd_GammaCorrection_Success (2U)
#  endif

#  ifndef eDisplayCdd_GammaCorrection_Failure
#   define eDisplayCdd_GammaCorrection_Failure (3U)
#  endif
#  ifndef eIO_DOutGroupIdCount
#   define eIO_DOutGroupIdCount (0U)
#  endif
#  ifndef eIO_DOUT_DO_5VSW2_3V3_EN
#   define eIO_DOUT_DO_5VSW2_3V3_EN (0U)
#  endif

#  ifndef eIO_DOUT_PARK_BRAKE_TT_OUT
#   define eIO_DOUT_PARK_BRAKE_TT_OUT (1U)
#  endif

#  ifndef eIO_DOUT_DO_SYC1
#   define eIO_DOUT_DO_SYC1 (2U)
#  endif

#  ifndef eIO_DOUT_SEAT_BELT_TT_MCUOUT
#   define eIO_DOUT_SEAT_BELT_TT_MCUOUT (3U)
#  endif

#  ifndef eIO_DOUT_TURN_LEFT_TT_MCUOUT
#   define eIO_DOUT_TURN_LEFT_TT_MCUOUT (4U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_BL_PWR_EN
#   define eIO_DOUT_DO_LCD_BL_PWR_EN (5U)
#  endif

#  ifndef eIO_DOUT_DO_3V3_DISP_SW_EN
#   define eIO_DOUT_DO_3V3_DISP_SW_EN (6U)
#  endif

#  ifndef eIO_DOUT_AMP_SHTD
#   define eIO_DOUT_AMP_SHTD (7U)
#  endif

#  ifndef eIO_DOUT_FUEL_RHEO_SUP_EN
#   define eIO_DOUT_FUEL_RHEO_SUP_EN (8U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_STBYB
#   define eIO_DOUT_DO_LCD_STBYB (9U)
#  endif

#  ifndef eIO_DOUT_SBATT2_EN
#   define eIO_DOUT_SBATT2_EN (10U)
#  endif

#  ifndef eIO_DOUT_BRAKE_TT_MCUOUT
#   define eIO_DOUT_BRAKE_TT_MCUOUT (11U)
#  endif

#  ifndef eIO_DOUT_AIRBAG_TT_MCUOUT
#   define eIO_DOUT_AIRBAG_TT_MCUOUT (12U)
#  endif

#  ifndef eIO_DOUT_TURN_RIGHT_TT_MCUOUT
#   define eIO_DOUT_TURN_RIGHT_TT_MCUOUT (13U)
#  endif

#  ifndef eIO_DOUT_DO_SMPS_5V_SW_EN
#   define eIO_DOUT_DO_SMPS_5V_SW_EN (14U)
#  endif

#  ifndef eIO_DOUT_PCS_OFF_TT_MCUOUT
#   define eIO_DOUT_PCS_OFF_TT_MCUOUT (15U)
#  endif

#  ifndef eIO_DOUT_ABS_TT_MCUOUT
#   define eIO_DOUT_ABS_TT_MCUOUT (16U)
#  endif

#  ifndef eIO_DOUT_SLIP_TT_MCUOUT
#   define eIO_DOUT_SLIP_TT_MCUOUT (17U)
#  endif

#  ifndef eIO_DOUT_VCS_OFF_TT_MCUOUT
#   define eIO_DOUT_VCS_OFF_TT_MCUOUT (18U)
#  endif

#  ifndef eIO_DOUT_ECB_EPB_TT_MCUOUT
#   define eIO_DOUT_ECB_EPB_TT_MCUOUT (19U)
#  endif

#  ifndef eIO_DOUT_Flasher_FL_RL_OUT
#   define eIO_DOUT_Flasher_FL_RL_OUT (20U)
#  endif

#  ifndef eIO_DOUT_Flasher_DEN1
#   define eIO_DOUT_Flasher_DEN1 (21U)
#  endif

#  ifndef eIO_DOUT_Flasher_DSEL1
#   define eIO_DOUT_Flasher_DSEL1 (22U)
#  endif

#  ifndef eIO_DOUT_Flasher_FR_RR_OUT
#   define eIO_DOUT_Flasher_FR_RR_OUT (23U)
#  endif

#  ifndef eIO_DOUT_DO_LCD_RST
#   define eIO_DOUT_DO_LCD_RST (24U)
#  endif

#  ifndef eIO_DOUT_DO_SMPS_1V2_EN
#   define eIO_DOUT_DO_SMPS_1V2_EN (25U)
#  endif

#  ifndef eIO_DO_MAX
#   define eIO_DO_MAX (26U)
#  endif
#  ifndef E_NO_ERROR
#   define E_NO_ERROR (2U)
#  endif

#  ifndef E_ERROR
#   define E_ERROR (3U)
#  endif

#  ifndef E_ADC_ERROR
#   define E_ADC_ERROR (4U)
#  endif

#  ifndef E_DOUT_ID_INVALID
#   define E_DOUT_ID_INVALID (5U)
#  endif

#  ifndef E_DIN_ID_INVALID
#   define E_DIN_ID_INVALID (6U)
#  endif

#  ifndef E_ADC_ID_INVALID
#   define E_ADC_ID_INVALID (7U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDISPLAYCDD_TYPE_H */
