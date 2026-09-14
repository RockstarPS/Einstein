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
 *          File:  Rte_Ctrl_WSS_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application types header file for SW-C <Ctrl_WSS>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRL_WSS_TYPE_H
# define _RTE_CTRL_WSS_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DBG_TRUE
#   define DBG_TRUE (0U)
#  endif

#  ifndef DBG_FALSE
#   define DBG_FALSE (1U)
#  endif

#  ifndef CLUSTER_INIT
#   define CLUSTER_INIT (0U)
#  endif

#  ifndef CLUSTER_RUN
#   define CLUSTER_RUN (1U)
#  endif

#  ifndef CLUSTER_RUN_READALL
#   define CLUSTER_RUN_READALL (2U)
#  endif

#  ifndef CLUSTER_INACTIVE
#   define CLUSTER_INACTIVE (0U)
#  endif

#  ifndef CLUSTER_ACTIVE
#   define CLUSTER_ACTIVE (1U)
#  endif

#  ifndef TFTDisplayOFF
#   define TFTDisplayOFF (0U)
#  endif

#  ifndef TFTDisplayON
#   define TFTDisplayON (1U)
#  endif

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

#  ifndef eHMI_NOT_READY
#   define eHMI_NOT_READY (0U)
#  endif

#  ifndef eHMI_READY
#   define eHMI_READY (1U)
#  endif

#  ifndef eODO_TYPE_OFF
#   define eODO_TYPE_OFF (0U)
#  endif

#  ifndef eODO_TYPE_BLANK
#   define eODO_TYPE_BLANK (1U)
#  endif

#  ifndef eODO_TYPE_ODO
#   define eODO_TYPE_ODO (2U)
#  endif

#  ifndef eODO_TYPE_TRIPA
#   define eODO_TYPE_TRIPA (3U)
#  endif

#  ifndef eODO_TYPE_TRIPB
#   define eODO_TYPE_TRIPB (4U)
#  endif

#  ifndef eODO_TYPE_OILMIL_DISTANCE
#   define eODO_TYPE_OILMIL_DISTANCE (5U)
#  endif

#  ifndef eODO_TYPE_FUEL_OW_ADV_NOTICE
#   define eODO_TYPE_FUEL_OW_ADV_NOTICE (6U)
#  endif

#  ifndef eODO_TYPE_FUEL_OVER_WRITE
#   define eODO_TYPE_FUEL_OVER_WRITE (7U)
#  endif

#  ifndef eODO_TYPE_POWER_STATUS_ACC
#   define eODO_TYPE_POWER_STATUS_ACC (8U)
#  endif

#  ifndef eODO_TYPE_POWER_STATUS_ON
#   define eODO_TYPE_POWER_STATUS_ON (9U)
#  endif

#  ifndef eODO_TYPE_OILMIL_DISTANCE_INT
#   define eODO_TYPE_OILMIL_DISTANCE_INT (10U)
#  endif

#  ifndef eSCREENMODE_OFF
#   define eSCREENMODE_OFF (0U)
#  endif

#  ifndef eSCREENMODE_BLANK
#   define eSCREENMODE_BLANK (1U)
#  endif

#  ifndef eSCREENMODE_NORMAL
#   define eSCREENMODE_NORMAL (2U)
#  endif

#  ifndef eSCREENMODE_DISPLAY_ADJ
#   define eSCREENMODE_DISPLAY_ADJ (3U)
#  endif

#  ifndef eSCREENMODE_WELCOME
#   define eSCREENMODE_WELCOME (4U)
#  endif

#  ifndef eSCREENMODE_IGNOFF_CHR
#   define eSCREENMODE_IGNOFF_CHR (5U)
#  endif

#  ifndef eSCREENMODE_OPENING
#   define eSCREENMODE_OPENING (6U)
#  endif

#  ifndef eSCREENMODE_ENDING
#   define eSCREENMODE_ENDING (7U)
#  endif

#  ifndef eSCREENMODE_ENDING_IGNOFF_CHR
#   define eSCREENMODE_ENDING_IGNOFF_CHR (8U)
#  endif

#  ifndef eSCREENMODE_RESERVED
#   define eSCREENMODE_RESERVED (9U)
#  endif

#  ifndef eWarningMask_Timerhandle
#   define eWarningMask_Timerhandle (0U)
#  endif

#  ifndef eOWC_Timerhandle
#   define eOWC_Timerhandle (1U)
#  endif

#  ifndef eNWD_Timerhandle
#   define eNWD_Timerhandle (2U)
#  endif

#  ifndef eWarningBulbCheckMask_Timerhandle
#   define eWarningBulbCheckMask_Timerhandle (3U)
#  endif

#  ifndef eInitWarning_TimerHandle
#   define eInitWarning_TimerHandle (4U)
#  endif

#  ifndef eInitChimeTimerHandle
#   define eInitChimeTimerHandle (5U)
#  endif

#  ifndef eProgrammingTimerHandle
#   define eProgrammingTimerHandle (6U)
#  endif

#  ifndef eStubCounter_TimerHanlde
#   define eStubCounter_TimerHanlde (7U)
#  endif

#  ifndef eModeMgrDisplayPowerDownUp
#   define eModeMgrDisplayPowerDownUp (8U)
#  endif

#  ifndef eModeMgrDisplayFaultAction
#   define eModeMgrDisplayFaultAction (9U)
#  endif

#  ifndef eModeMgrDomanResetAction
#   define eModeMgrDomanResetAction (10U)
#  endif

#  ifndef eModeMgrPowerFaultAction
#   define eModeMgrPowerFaultAction (11U)
#  endif

#  ifndef eEtm4SecTimer
#   define eEtm4SecTimer (12U)
#  endif

#  ifndef eEtm1200msecTimer
#   define eEtm1200msecTimer (13U)
#  endif

#  ifndef eEtm3SecTimer
#   define eEtm3SecTimer (14U)
#  endif

#  ifndef eCallbackTimerOdoMdl
#   define eCallbackTimerOdoMdl (15U)
#  endif

#  ifndef eThrottleTimerOdoMdl
#   define eThrottleTimerOdoMdl (16U)
#  endif

#  ifndef eChangeupCallbackTimerodoMdl
#   define eChangeupCallbackTimerodoMdl (17U)
#  endif

#  ifndef eTimerVehicleState
#   define eTimerVehicleState (18U)
#  endif

#  ifndef eTimerVariantConfig
#   define eTimerVariantConfig (19U)
#  endif

#  ifndef WARNING_DISPLAY_TIMER_ID
#   define WARNING_DISPLAY_TIMER_ID (20U)
#  endif

#  ifndef WARNING_HOLD_TIMER_ID
#   define WARNING_HOLD_TIMER_ID (21U)
#  endif

#  ifndef WARNING_CYCLE_TIMER_ID
#   define WARNING_CYCLE_TIMER_ID (22U)
#  endif

#  ifndef WARNING_DISPLAYHOLD_TIMER_ID
#   define WARNING_DISPLAYHOLD_TIMER_ID (23U)
#  endif

#  ifndef WARNING_ACK_TIMER_ID
#   define WARNING_ACK_TIMER_ID (24U)
#  endif

#  ifndef eTimerHandle_Sleep
#   define eTimerHandle_Sleep (25U)
#  endif

#  ifndef eInStartCount_TimerHandle
#   define eInStartCount_TimerHandle (26U)
#  endif

#  ifndef eVehicleModeCount_TimerHandle
#   define eVehicleModeCount_TimerHandle (27U)
#  endif

#  ifndef e10secTimer
#   define e10secTimer (28U)
#  endif

#  ifndef e3secTimer
#   define e3secTimer (29U)
#  endif

#  ifndef e30secTimer
#   define e30secTimer (30U)
#  endif

#  ifndef e2_6secTimer
#   define e2_6secTimer (31U)
#  endif

#  ifndef eDcmApp5secTimer
#   define eDcmApp5secTimer (32U)
#  endif

#  ifndef eDcmApp1secTimer
#   define eDcmApp1secTimer (33U)
#  endif

#  ifndef eLidopen_OFFTimer
#   define eLidopen_OFFTimer (34U)
#  endif

#  ifndef eLidopen_ONTimer
#   define eLidopen_ONTimer (35U)
#  endif

#  ifndef POPUP_DISPLAY_TIMER_ID
#   define POPUP_DISPLAY_TIMER_ID (36U)
#  endif

#  ifndef POPUP_GRP_TAB_TIMER_ID
#   define POPUP_GRP_TAB_TIMER_ID (37U)
#  endif

#  ifndef eDrvRec5_6Timer
#   define eDrvRec5_6Timer (38U)
#  endif

#  ifndef eDrvRec3_6Timer
#   define eDrvRec3_6Timer (39U)
#  endif

#  ifndef eIDS_1SecTimer
#   define eIDS_1SecTimer (40U)
#  endif

#  ifndef eIDS3_1SecTimer
#   define eIDS3_1SecTimer (41U)
#  endif

#  ifndef eIDS_3SecTimer
#   define eIDS_3SecTimer (42U)
#  endif

#  ifndef ePerDispSet100msTimer
#   define ePerDispSet100msTimer (43U)
#  endif

#  ifndef eDrvRec1_2secTimer
#   define eDrvRec1_2secTimer (44U)
#  endif

#  ifndef eDrvRec0_8secTimer
#   define eDrvRec0_8secTimer (45U)
#  endif

#  ifndef eHMI_Initial_Blank_timer_ID
#   define eHMI_Initial_Blank_timer_ID (46U)
#  endif

#  ifndef eHMI_Fade_in_delay_timer_ID
#   define eHMI_Fade_in_delay_timer_ID (47U)
#  endif

#  ifndef eKM6secTimer
#   define eKM6secTimer (48U)
#  endif

#  ifndef eKM5_8secTimer
#   define eKM5_8secTimer (49U)
#  endif

#  ifndef eKM0_6secTimer
#   define eKM0_6secTimer (50U)
#  endif

#  ifndef eKM0_2secTimer
#   define eKM0_2secTimer (51U)
#  endif

#  ifndef eIgnCANMode_3SecTimer
#   define eIgnCANMode_3SecTimer (52U)
#  endif

#  ifndef eDem2_6secTimer
#   define eDem2_6secTimer (53U)
#  endif

#  ifndef eDem5secTimer
#   define eDem5secTimer (54U)
#  endif

#  ifndef e2FRheo5secTimer
#   define e2FRheo5secTimer (55U)
#  endif

#  ifndef e2FSTSW5secTimer
#   define e2FSTSW5secTimer (56U)
#  endif

#  ifndef eLSTM3_Timer
#   define eLSTM3_Timer (57U)
#  endif

#  ifndef eLSTM4_Timer
#   define eLSTM4_Timer (58U)
#  endif

#  ifndef eDem_AFS_5sec_Timer
#   define eDem_AFS_5sec_Timer (59U)
#  endif

#  ifndef WARNING_MSGTIMEOUT_1SEC_TIMER_ID
#   define WARNING_MSGTIMEOUT_1SEC_TIMER_ID (60U)
#  endif

#  ifndef eDCMApp_30Sec_Timer
#   define eDCMApp_30Sec_Timer (61U)
#  endif

#  ifndef WRN_ACK_REDISPLAY_TIMER_ID
#   define WRN_ACK_REDISPLAY_TIMER_ID (62U)
#  endif

#  ifndef eMenuScrollStart1sTimer
#   define eMenuScrollStart1sTimer (63U)
#  endif

#  ifndef eType4_6secTimer
#   define eType4_6secTimer (64U)
#  endif

#  ifndef eDcmApp_0_35secTimer
#   define eDcmApp_0_35secTimer (65U)
#  endif

#  ifndef eDcmApp_0_35_1secTimer
#   define eDcmApp_0_35_1secTimer (66U)
#  endif

#  ifndef eRemoteCarFindCtrlStateTimer
#   define eRemoteCarFindCtrlStateTimer (67U)
#  endif

#  ifndef eBrake_Red_100msecTimer
#   define eBrake_Red_100msecTimer (68U)
#  endif

#  ifndef eStreeingSw_ReleaseTimer
#   define eStreeingSw_ReleaseTimer (69U)
#  endif

#  ifndef POPUP_SETTING_TIMER_ID
#   define POPUP_SETTING_TIMER_ID (70U)
#  endif

#  ifndef eMenu100msTimer
#   define eMenu100msTimer (71U)
#  endif

#  ifndef eBuzzerMiddleEast_6secs
#   define eBuzzerMiddleEast_6secs (72U)
#  endif

#  ifndef eBuzzerMiddleEast_6secs_2
#   define eBuzzerMiddleEast_6secs_2 (73U)
#  endif

#  ifndef eMaxNumof16BitTimers
#   define eMaxNumof16BitTimers (74U)
#  endif

#  ifndef eSleepMaxTimer
#   define eSleepMaxTimer (75U)
#  endif

#  ifndef eRentACarTimer
#   define eRentACarTimer (76U)
#  endif

#  ifndef eDoorWarn_Timer
#   define eDoorWarn_Timer (77U)
#  endif

#  ifndef eTimerHandleGdtCdd
#   define eTimerHandleGdtCdd (78U)
#  endif

#  ifndef eSample32BitTimer
#   define eSample32BitTimer (79U)
#  endif

#  ifndef eTimerMax
#   define eTimerMax (80U)
#  endif

#  ifndef IgnOff
#   define IgnOff (0U)
#  endif

#  ifndef IgnOn
#   define IgnOn (1U)
#  endif

#  ifndef eIO_ADC_ADC_FUEL_5V_MON
#   define eIO_ADC_ADC_FUEL_5V_MON (16U)
#  endif

#  ifndef eIO_ADC_ADC_FUEL_MAIN
#   define eIO_ADC_ADC_FUEL_MAIN (17U)
#  endif

#  ifndef eIO_ADC_IGN_AD
#   define eIO_ADC_IGN_AD (2U)
#  endif

#  ifndef eIO_ADC_FUEL_SEND_SUB_MICRO_AD
#   define eIO_ADC_FUEL_SEND_SUB_MICRO_AD (3U)
#  endif

#  ifndef eIO_ADC_AI_BATTERY
#   define eIO_ADC_AI_BATTERY (4U)
#  endif

#  ifndef eIO_ADC_AI_LCD_NTC
#   define eIO_ADC_AI_LCD_NTC (5U)
#  endif

#  ifndef eIO_ADC_AI_TEMP_RTC
#   define eIO_ADC_AI_TEMP_RTC (6U)
#  endif

#  ifndef eIO_ADC_Flasher_Diag_sense_1
#   define eIO_ADC_Flasher_Diag_sense_1 (7U)
#  endif

#  ifndef eIO_ADC_STR_SW2_ADIN
#   define eIO_ADC_STR_SW2_ADIN (8U)
#  endif

#  ifndef eIO_ADC_STR_SW1_ADIN
#   define eIO_ADC_STR_SW1_ADIN (9U)
#  endif

#  ifndef eIO_ADC_RHEO_SW_IN_ADIN
#   define eIO_ADC_RHEO_SW_IN_ADIN (10U)
#  endif

#  ifndef eIO_ADC_ADC_RHEO_5V_MON_ADIN
#   define eIO_ADC_ADC_RHEO_5V_MON_ADIN (11U)
#  endif

#  ifndef eIO_ADC_Flasher_Diag_sense_2
#   define eIO_ADC_Flasher_Diag_sense_2 (12U)
#  endif

#  ifndef eIO_ADC_AdcChannel_Vdb
#   define eIO_ADC_AdcChannel_Vdb (13U)
#  endif

#  ifndef eIO_ADC_AdcChannel_Vtemp
#   define eIO_ADC_AdcChannel_Vtemp (14U)
#  endif

#  ifndef eIO_ADC_MAX
#   define eIO_ADC_MAX (15U)
#  endif

#  ifndef eIO_ADC_AI_SAMPLE_1
#   define eIO_ADC_AI_SAMPLE_1 (0U)
#  endif

#  ifndef eIO_ADC_AI_SAMPLE_2
#   define eIO_ADC_AI_SAMPLE_2 (1U)
#  endif

#  ifndef eIO_DInGroupIdCount
#   define eIO_DInGroupIdCount (0)
#  endif

#  ifndef eIO_DIN_DI_AL_HAZARD
#   define eIO_DIN_DI_AL_HAZARD (0U)
#  endif

#  ifndef eIO_DIN_DI_AH_IGNITION
#   define eIO_DIN_DI_AH_IGNITION (1U)
#  endif

#  ifndef eIO_DIN_DI_SMPS_3V3_PG
#   define eIO_DIN_DI_SMPS_3V3_PG (2U)
#  endif

#  ifndef eIO_DIN_STOP_LAMP_MCU
#   define eIO_DIN_STOP_LAMP_MCU (3U)
#  endif

#  ifndef eIO_DIN_DI_AL_BRAKE_LEVEL
#   define eIO_DIN_DI_AL_BRAKE_LEVEL (4U)
#  endif

#  ifndef eIO_DIN_DI_AL_OIL_W
#   define eIO_DIN_DI_AL_OIL_W (5U)
#  endif

#  ifndef eIO_DIN_DI_AL_DRV_SEAT_BUCKLE
#   define eIO_DIN_DI_AL_DRV_SEAT_BUCKLE (6U)
#  endif

#  ifndef eIO_DIN_DI_AL_WASHER_LEVEL_SW
#   define eIO_DIN_DI_AL_WASHER_LEVEL_SW (7U)
#  endif

#  ifndef eIO_DIN_ODO_TripKnobInput
#   define eIO_DIN_ODO_TripKnobInput (8U)
#  endif

#  ifndef eIO_DIN_DI_AL_VACUUM
#   define eIO_DIN_DI_AL_VACUUM (9U)
#  endif

#  ifndef eIO_DIN_DI_LCD_BL_PWR_FAULT
#   define eIO_DIN_DI_LCD_BL_PWR_FAULT (10U)
#  endif

#  ifndef eIO_DIN_DI_AL_FUEL_LID_EFI_ECU
#   define eIO_DIN_DI_AL_FUEL_LID_EFI_ECU (11U)
#  endif

#  ifndef eIO_DIN_DI_TT_SHIFT_ERR
#   define eIO_DIN_DI_TT_SHIFT_ERR (12U)
#  endif

#  ifndef eIO_DIN_MAX
#   define eIO_DIN_MAX (13U)
#  endif

#  ifndef eIO_DIN_DI_PMIC_INTN
#   define eIO_DIN_DI_PMIC_INTN (14U)
#  endif

#  ifndef eIO_DIN_DI_MCU_PORZ
#   define eIO_DIN_DI_MCU_PORZ (15U)
#  endif

#  ifndef eIO_DIN_DI_SBATT2_ERR
#   define eIO_DIN_DI_SBATT2_ERR (16U)
#  endif

#  ifndef eIO_DIN_DI_FALD_PG
#   define eIO_DIN_DI_FALD_PG (17U)
#  endif

#  ifndef eIO_DIN_DI_MD_TOUCH_INTN
#   define eIO_DIN_DI_MD_TOUCH_INTN (18U)
#  endif

#  ifndef eIO_DIN_DI_BL_FAULT
#   define eIO_DIN_DI_BL_FAULT (19U)
#  endif

#  ifndef eIO_DIN_DI_SOC_FPDLINK3_LOCK
#   define eIO_DIN_DI_SOC_FPDLINK3_LOCK (20U)
#  endif

#  ifndef eIO_DIN_DI_SOC_FPDLINK3_PASS
#   define eIO_DIN_DI_SOC_FPDLINK3_PASS (21U)
#  endif

#  ifndef eIO_DIN_DI_ENET_MII_INT
#   define eIO_DIN_DI_ENET_MII_INT (22U)
#  endif

#  ifndef eIO_DIN_DI_IGN_MON
#   define eIO_DIN_DI_IGN_MON (23U)
#  endif

#  ifndef eIO_DIN_DI_CABLE_DETECT
#   define eIO_DIN_DI_CABLE_DETECT (24U)
#  endif

#  ifndef eIO_DIN_DI_TCON_IND_OUT
#   define eIO_DIN_DI_TCON_IND_OUT (25U)
#  endif

#  ifndef eIO_DIN_DI_SPI_CAN_TCON_SDI
#   define eIO_DIN_DI_SPI_CAN_TCON_SDI (26U)
#  endif

#  ifndef eIO_DIN_DI_MCU_FALD_CONN_CHK
#   define eIO_DIN_DI_MCU_FALD_CONN_CHK (27U)
#  endif

#  ifndef eIO_DIN_DI_LDO_1V2_FAULTN
#   define eIO_DIN_DI_LDO_1V2_FAULTN (28U)
#  endif

#  ifndef eIO_DIN_DI_TFT_ER_DET
#   define eIO_DIN_DI_TFT_ER_DET (29U)
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

#  ifndef IOHWAB_E_ADC_ERROR
#   define IOHWAB_E_ADC_ERROR (8U)
#  endif

#  ifndef IOHWAB_E_ADC_ID_INVALID
#   define IOHWAB_E_ADC_ID_INVALID (9U)
#  endif

#  ifndef IOHWAB_E_ERROR
#   define IOHWAB_E_ERROR (10U)
#  endif

#  ifndef IOHWAB_E_DOUT_ID_INVALID
#   define IOHWAB_E_DOUT_ID_INVALID (11U)
#  endif

#  ifndef IOHWAB_E_NO_ERROR
#   define IOHWAB_E_NO_ERROR (12U)
#  endif

#  ifndef IOHWAB_E_DIN_ID_INVALID
#   define IOHWAB_E_DIN_ID_INVALID (13U)
#  endif

#  ifndef STATUS_OFF
#   define STATUS_OFF (0U)
#  endif

#  ifndef STATUS_ON
#   define STATUS_ON (1U)
#  endif

#  ifndef SLEEEP_READY
#   define SLEEEP_READY (0U)
#  endif

#  ifndef SLEEP_NOT_READY
#   define SLEEP_NOT_READY (1U)
#  endif

#  ifndef NOT_IN_SYNCH
#   define NOT_IN_SYNCH (0U)
#  endif

#  ifndef FLASH_180DEG_PHASE_SYNCH
#   define FLASH_180DEG_PHASE_SYNCH (1U)
#  endif

#  ifndef FLASH_360DEG_PHASE_SYNCH
#   define FLASH_360DEG_PHASE_SYNCH (2U)
#  endif

#  ifndef FLASH_OFF_PERIOD_MASK
#   define FLASH_OFF_PERIOD_MASK (4U)
#  endif

#  ifndef TT_ABS_INDEX
#   define TT_ABS_INDEX (0U)
#  endif

#  ifndef TT_AIRBAG_INDEX
#   define TT_AIRBAG_INDEX (1U)
#  endif

#  ifndef TT_BRAKE_RED_INDEX
#   define TT_BRAKE_RED_INDEX (2U)
#  endif

#  ifndef TT_BRAKE_HOLD_INDEX
#   define TT_BRAKE_HOLD_INDEX (3U)
#  endif

#  ifndef TT_BRAKE_YELLOW_INDEX
#   define TT_BRAKE_YELLOW_INDEX (4U)
#  endif

#  ifndef TT_PARKING_BRAKE_INDEX
#   define TT_PARKING_BRAKE_INDEX (5U)
#  endif

#  ifndef TT_TRACTION_CTRL_INDEX
#   define TT_TRACTION_CTRL_INDEX (6U)
#  endif

#  ifndef TT_VCS_OFF_INDEX
#   define TT_VCS_OFF_INDEX (7U)
#  endif

#  ifndef TT_ABS_INDEX_US
#   define TT_ABS_INDEX_US (8U)
#  endif

#  ifndef TT_BRAKE_RED_INDEX_US
#   define TT_BRAKE_RED_INDEX_US (9U)
#  endif

#  ifndef TT_PARKING_BRAKE_INDEX_US
#   define TT_PARKING_BRAKE_INDEX_US (10U)
#  endif

#  ifndef TT_SAF_RES4_INDEX
#   define TT_SAF_RES4_INDEX (11U)
#  endif

#  ifndef TT_SAF_RES5_INDEX
#   define TT_SAF_RES5_INDEX (12U)
#  endif

#  ifndef TT_SAF_RES6_INDEX
#   define TT_SAF_RES6_INDEX (13U)
#  endif

#  ifndef TT_SAF_RES7_INDEX
#   define TT_SAF_RES7_INDEX (14U)
#  endif

#  ifndef TT_SAF_RES8_INDEX
#   define TT_SAF_RES8_INDEX (15U)
#  endif

#  ifndef TT_ADAS_INDEX
#   define TT_ADAS_INDEX (16U)
#  endif

#  ifndef TT_AUTO_HIGH_BEAM_INDEX
#   define TT_AUTO_HIGH_BEAM_INDEX (17U)
#  endif

#  ifndef TT_BRAKE_HOLD_STANDBY_INDEX
#   define TT_BRAKE_HOLD_STANDBY_INDEX (18U)
#  endif

#  ifndef TT_FUEL_INDEX
#   define TT_FUEL_INDEX (19U)
#  endif

#  ifndef TT_FFOG_INDEX
#   define TT_FFOG_INDEX (20U)
#  endif

#  ifndef TT_HEAD_INDEX
#   define TT_HEAD_INDEX (21U)
#  endif

#  ifndef TT_HIGH_BEAM_INDEX
#   define TT_HIGH_BEAM_INDEX (22U)
#  endif

#  ifndef TT_PCS_OFF_INDEX
#   define TT_PCS_OFF_INDEX (23U)
#  endif

#  ifndef TT_READY_INDEX
#   define TT_READY_INDEX (24U)
#  endif

#  ifndef TT_RFOG_INDEX
#   define TT_RFOG_INDEX (25U)
#  endif

#  ifndef TT_SEAT_BELT_INDEX
#   define TT_SEAT_BELT_INDEX (26U)
#  endif

#  ifndef TT_TAIL_LIGHT_INDEX
#   define TT_TAIL_LIGHT_INDEX (27U)
#  endif

#  ifndef TT_TURN_HAZARD_RIGHT_INDEX
#   define TT_TURN_HAZARD_RIGHT_INDEX (28U)
#  endif

#  ifndef TT_TURN_HAZARD_LEFT_INDEX
#   define TT_TURN_HAZARD_LEFT_INDEX (29U)
#  endif

#  ifndef TT_EWT_INDEX
#   define TT_EWT_INDEX (30U)
#  endif

#  ifndef TT_AAHB_LO_GREEN
#   define TT_AAHB_LO_GREEN (31U)
#  endif

#  ifndef TT_AAHB_SHADED_GREEN
#   define TT_AAHB_SHADED_GREEN (32U)
#  endif

#  ifndef TT_AAHB_HI_GREEN
#   define TT_AAHB_HI_GREEN (33U)
#  endif

#  ifndef TT_AAHB_HI_WHITE
#   define TT_AAHB_HI_WHITE (34U)
#  endif

#  ifndef TT_ITS_INFRA
#   define TT_ITS_INFRA (35U)
#  endif

#  ifndef TT_ITS_VEHICLE
#   define TT_ITS_VEHICLE (36U)
#  endif

#  ifndef TT_ITS_COMBINATION
#   define TT_ITS_COMBINATION (37U)
#  endif

#  ifndef TT_SSS_GREEN
#   define TT_SSS_GREEN (38U)
#  endif

#  ifndef TT_SSS_AMBER
#   define TT_SSS_AMBER (39U)
#  endif

#  ifndef TT_LCA_LEFT_WHITE
#   define TT_LCA_LEFT_WHITE (40U)
#  endif

#  ifndef TT_LCA_LEFT_GRAY
#   define TT_LCA_LEFT_GRAY (41U)
#  endif

#  ifndef TT_LCA_LEFT_GREEN
#   define TT_LCA_LEFT_GREEN (42U)
#  endif

#  ifndef TT_LCA_RIGHT_WHITE
#   define TT_LCA_RIGHT_WHITE (43U)
#  endif

#  ifndef TT_LCA_RIGHT_GRAY
#   define TT_LCA_RIGHT_GRAY (44U)
#  endif

#  ifndef TT_LCA_RIGHT_GREEN
#   define TT_LCA_RIGHT_GREEN (45U)
#  endif

#  ifndef TT_LTA_GREEN
#   define TT_LTA_GREEN (46U)
#  endif

#  ifndef TT_LTA_WHITE
#   define TT_LTA_WHITE (47U)
#  endif

#  ifndef TT_LTA_AMBER
#   define TT_LTA_AMBER (48U)
#  endif

#  ifndef TT_CCT_GREEN
#   define TT_CCT_GREEN (49U)
#  endif

#  ifndef TT_CCT_WHITE
#   define TT_CCT_WHITE (50U)
#  endif

#  ifndef TT_CCT_AMBER
#   define TT_CCT_AMBER (51U)
#  endif

#  ifndef TT_RCCT_GREEN
#   define TT_RCCT_GREEN (52U)
#  endif

#  ifndef TT_RCCT_WHITE
#   define TT_RCCT_WHITE (53U)
#  endif

#  ifndef TT_RCCT_AMBER
#   define TT_RCCT_AMBER (54U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV4
#   define TT_ACCDT_WHITE_LV4 (55U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV3
#   define TT_ACCDT_WHITE_LV3 (56U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV2
#   define TT_ACCDT_WHITE_LV2 (57U)
#  endif

#  ifndef TT_ACCDT_WHITE_LV1
#   define TT_ACCDT_WHITE_LV1 (58U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV4
#   define TT_ACCDT_GREEN_LV4 (59U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV3
#   define TT_ACCDT_GREEN_LV3 (60U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV2
#   define TT_ACCDT_GREEN_LV2 (61U)
#  endif

#  ifndef TT_ACCDT_GREEN_LV1
#   define TT_ACCDT_GREEN_LV1 (62U)
#  endif

#  ifndef TT_SL_GREEN
#   define TT_SL_GREEN (63U)
#  endif

#  ifndef TT_SL_WHITE
#   define TT_SL_WHITE (64U)
#  endif

#  ifndef TT_SL_AMBER
#   define TT_SL_AMBER (65U)
#  endif

#  ifndef TT_AUTO_LSD_AMBER
#   define TT_AUTO_LSD_AMBER (66U)
#  endif

#  ifndef TT_DRIVEMODE_SPORT
#   define TT_DRIVEMODE_SPORT (67U)
#  endif

#  ifndef TT_DRIVEMODE_ECO
#   define TT_DRIVEMODE_ECO (68U)
#  endif

#  ifndef TT_DRIVEMODE_CUSTOM
#   define TT_DRIVEMODE_CUSTOM (69U)
#  endif

#  ifndef TT_DRIVEMODE_RANGE
#   define TT_DRIVEMODE_RANGE (70U)
#  endif

#  ifndef TT_DRIVEMODE_REARCOMFORT
#   define TT_DRIVEMODE_REARCOMFORT (71U)
#  endif

#  ifndef TT_DRIVEMODE_SNOW
#   define TT_DRIVEMODE_SNOW (72U)
#  endif

#  ifndef TT_DRIVEMODE_TRACK
#   define TT_DRIVEMODE_TRACK (73U)
#  endif

#  ifndef TT_LDA_RED
#   define TT_LDA_RED (74U)
#  endif

#  ifndef TT_LDA_AMBER
#   define TT_LDA_AMBER (75U)
#  endif

#  ifndef TT_LDA_WHITE
#   define TT_LDA_WHITE (76U)
#  endif

#  ifndef TT_LDA_OFF_AMBER
#   define TT_LDA_OFF_AMBER (77U)
#  endif

#  ifndef TT_LDA_OFF_WHITE
#   define TT_LDA_OFF_WHITE (78U)
#  endif

#  ifndef TT_ECOLAMP
#   define TT_ECOLAMP (79U)
#  endif

#  ifndef TT_PS_GREEN
#   define TT_PS_GREEN (80U)
#  endif

#  ifndef TT_PKBOPER_TXT
#   define TT_PKBOPER_TXT (81U)
#  endif

#  ifndef TT_PKBOPER_IMG
#   define TT_PKBOPER_IMG (82U)
#  endif

#  ifndef TT_TPMS_INDEX
#   define TT_TPMS_INDEX (83U)
#  endif

#  ifndef TT_EBPWIND_RED_US
#   define TT_EBPWIND_RED_US (84U)
#  endif

#  ifndef TT_EBPWIND_RED
#   define TT_EBPWIND_RED (85U)
#  endif

#  ifndef TT_FMSR_AMBER
#   define TT_FMSR_AMBER (86U)
#  endif

#  ifndef TT_FMFR_AMBER
#   define TT_FMFR_AMBER (87U)
#  endif

#  ifndef TT_MULWL_GREEN
#   define TT_MULWL_GREEN (88U)
#  endif

#  ifndef TT_HCS_ACCESS_GREEN
#   define TT_HCS_ACCESS_GREEN (89U)
#  endif

#  ifndef TT_HCS_LIFT_GREEN
#   define TT_HCS_LIFT_GREEN (90U)
#  endif

#  ifndef TT_HCS_LIFT_AMBER
#   define TT_HCS_LIFT_AMBER (91U)
#  endif

#  ifndef TT_TOTAL_NUM_OF_TELLTALES
#   define TT_TOTAL_NUM_OF_TELLTALES (92U)
#  endif

#  ifndef TT_TURN_OFF
#   define TT_TURN_OFF (0U)
#  endif

#  ifndef TT_TURN_ON
#   define TT_TURN_ON (1U)
#  endif

#  ifndef TT_FLASH_QUARTER_HZ
#   define TT_FLASH_QUARTER_HZ (2U)
#  endif

#  ifndef TT_FLASH_HALF_HZ
#   define TT_FLASH_HALF_HZ (3U)
#  endif

#  ifndef TT_FLASH_CSNR_HALF_HZ
#   define TT_FLASH_CSNR_HALF_HZ (4U)
#  endif

#  ifndef TT_FLASH_0_83_HZ
#   define TT_FLASH_0_83_HZ (5U)
#  endif

#  ifndef TT_FLASH_1HZ
#   define TT_FLASH_1HZ (6U)
#  endif

#  ifndef TT_FLASH_1_33_HZ
#   define TT_FLASH_1_33_HZ (7U)
#  endif

#  ifndef TT_FLASH_1_66_HZ
#   define TT_FLASH_1_66_HZ (8U)
#  endif

#  ifndef TT_FLASH_2HZ
#   define TT_FLASH_2HZ (9U)
#  endif

#  ifndef TT_FLASH_2_5_HZ
#   define TT_FLASH_2_5_HZ (10U)
#  endif

#  ifndef TT_FLASH_2_66_HZ
#   define TT_FLASH_2_66_HZ (11U)
#  endif

#  ifndef TT_FLASH_TRNHZ_Normal
#   define TT_FLASH_TRNHZ_Normal (12U)
#  endif

#  ifndef TT_FLASH_TRNHZ_Fast
#   define TT_FLASH_TRNHZ_Fast (13U)
#  endif

#  ifndef TT_FLASH_TRNHZ_FHL
#   define TT_FLASH_TRNHZ_FHL (14U)
#  endif

#  ifndef TT_FLASH_3HZ
#   define TT_FLASH_3HZ (15U)
#  endif

#  ifndef TT_FLASH_4HZ
#   define TT_FLASH_4HZ (16U)
#  endif

#  ifndef TT_FLASH_5HZ
#   define TT_FLASH_5HZ (17U)
#  endif

#  ifndef TT_FLASH_SYNC_QUARTER_HZ
#   define TT_FLASH_SYNC_QUARTER_HZ (18U)
#  endif

#  ifndef TT_FLASH_SYNC_HALF_HZ
#   define TT_FLASH_SYNC_HALF_HZ (19U)
#  endif

#  ifndef TT_FLASH_SYNC_CSNR_HALF_HZ
#   define TT_FLASH_SYNC_CSNR_HALF_HZ (20U)
#  endif

#  ifndef TT_FLASH_SYNC_0_83_HZ
#   define TT_FLASH_SYNC_0_83_HZ (21U)
#  endif

#  ifndef TT_FLASH_SYNC_1HZ
#   define TT_FLASH_SYNC_1HZ (22U)
#  endif

#  ifndef TT_FLASH_SYNC_1_33_HZ
#   define TT_FLASH_SYNC_1_33_HZ (23U)
#  endif

#  ifndef TT_FLASH_SYNC_1_66_HZ
#   define TT_FLASH_SYNC_1_66_HZ (24U)
#  endif

#  ifndef TT_FLASH_SYNC_2HZ
#   define TT_FLASH_SYNC_2HZ (25U)
#  endif

#  ifndef TT_FLASH_SYNC_2_5_HZ
#   define TT_FLASH_SYNC_2_5_HZ (26U)
#  endif

#  ifndef TT_FLASH_SYNC_2_66_HZ
#   define TT_FLASH_SYNC_2_66_HZ (27U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_Normal
#   define TT_FLASH_TRNHZ_SYNC_Normal (28U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_Fast
#   define TT_FLASH_TRNHZ_SYNC_Fast (29U)
#  endif

#  ifndef TT_FLASH_TRNHZ_SYNC_FHL
#   define TT_FLASH_TRNHZ_SYNC_FHL (30U)
#  endif

#  ifndef TT_FLASH_SYNC_4HZ
#   define TT_FLASH_SYNC_4HZ (31U)
#  endif

#  ifndef TT_FLASH_SYNC_5HZ
#   define TT_FLASH_SYNC_5HZ (32U)
#  endif

#  ifndef TT_CONFIGURED_OFF
#   define TT_CONFIGURED_OFF (255U)
#  endif

#  ifndef TurnOff
#   define TurnOff (0U)
#  endif

#  ifndef TurnOn
#   define TurnOn (1U)
#  endif

#  ifndef TurnBlink
#   define TurnBlink (2U)
#  endif

#  ifndef NETWORK_SLEEP
#   define NETWORK_SLEEP (0U)
#  endif

#  ifndef NETWORK_NORMAL
#   define NETWORK_NORMAL (1U)
#  endif

#  ifndef NETWORK_STANDALONE
#   define NETWORK_STANDALONE (2U)
#  endif

#  ifndef eSWCApp_SmartKey_Bzr
#   define eSWCApp_SmartKey_Bzr (0U)
#  endif

#  ifndef eSWCApp_Warn_MFLID
#   define eSWCApp_Warn_MFLID (1U)
#  endif

#  ifndef eSWCApp_Head_TT
#   define eSWCApp_Head_TT (2U)
#  endif

#  ifndef eSWCApp_Tail_TT
#   define eSWCApp_Tail_TT (3U)
#  endif

#  ifndef eSWCApp_Fuel
#   define eSWCApp_Fuel (4U)
#  endif

#  ifndef eSWCApp_Illum
#   define eSWCApp_Illum (5U)
#  endif

#  ifndef eSWCApp_Buzzer
#   define eSWCApp_Buzzer (6U)
#  endif

#  ifndef eSWCApp_NVM
#   define eSWCApp_NVM (7U)
#  endif

#  ifndef eTFTDisplayOnExceptTurn
#   define eTFTDisplayOnExceptTurn (8U)
#  endif

#  ifndef eTurnL_Status
#   define eTurnL_Status (9U)
#  endif

#  ifndef eTurnR_Status
#   define eTurnR_Status (10U)
#  endif

#  ifndef eSWCApp_End
#   define eSWCApp_End (11U)
#  endif

#  ifndef eSleep_Inactive
#   define eSleep_Inactive (0U)
#  endif

#  ifndef eISleep_Active
#   define eISleep_Active (1U)
#  endif

#  ifndef eDayNightModeIn
#   define eDayNightModeIn (0U)
#  endif

#  ifndef eIllumination_levelIn
#   define eIllumination_levelIn (1U)
#  endif

#  ifndef eAmbient_Light_levelIn
#   define eAmbient_Light_levelIn (2U)
#  endif

#  ifndef ePowerModeIn
#   define ePowerModeIn (3U)
#  endif

#  ifndef eTransportModeIn
#   define eTransportModeIn (4U)
#  endif

#  ifndef eGearModeIn
#   define eGearModeIn (5U)
#  endif

#  ifndef eGearRecommendationIn
#   define eGearRecommendationIn (6U)
#  endif

#  ifndef eGearIn
#   define eGearIn (7U)
#  endif

#  ifndef eWarningIn
#   define eWarningIn (8U)
#  endif

#  ifndef eGearStatusIn
#   define eGearStatusIn (9U)
#  endif

#  ifndef eEngineSpeedIn
#   define eEngineSpeedIn (10U)
#  endif

#  ifndef eTurn_Indicator_ControlIn
#   define eTurn_Indicator_ControlIn (11U)
#  endif

#  ifndef eEndOfRxSignal
#   define eEndOfRxSignal (12U)
#  endif

#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif

#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRL_WSS_TYPE_H */
