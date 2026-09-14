/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  Os_Cfg.h
Module Short Name:  Os_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef OS_CFG_H
#define OS_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "OsMain.h"


                                                                              
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define OS_CFG_OS_STATUS               OS_STATUS_EXTENDED

#define MOS_VERSION_INFO_API           STD_ON

#define MOS_USE_SCHED_LOG              STD_OFF

#define OS_TESTING_LOCAL               STD_OFF



/******** OS Hook Routines are Enabled *************************************/
#define OS_CFG_SUPPORT_DBG_HOOKS
#define OS_ENABLE_OSAPI_ERR_HOOK

#define OS_API_ERROR_HOOK(x,y)          //pouplate user defined error hook here


/******** OS MemMap are Enabled *******************************/
#define OS_CFG_MEMMAP_ENABLED


/* OS SC3 Functionalities is STD_ON or STD_OFF */
#define OS_CFG_MEMORY_PROTECTION     STD_ON

#define OS_CFG_MPU_SWITCH_APP        STD_ON

#define OS_CFG_MPU_SWITCH_OBJ        STD_OFF


#define OsNumberOfCores             1U
#define OsNumberOfApplications      3U
#define OsNumberOfTrustedFns        15U
#define OS_CFG_TRUSTED_CALL_ID_0     0
#define OS_CFG_TRUSTED_CALL_ID_1     1
#define OS_CFG_TRUSTED_CALL_ID_2     2
#define OS_CFG_TRUSTED_CALL_ID_3     3
#define OS_CFG_TRUSTED_CALL_ID_4     4
#define OS_CFG_TRUSTED_CALL_ID_5     5
#define OS_CFG_TRUSTED_CALL_ID_6     6
#define OS_CFG_TRUSTED_CALL_ID_7     7
#define OS_CFG_TRUSTED_CALL_ID_8     8
#define OS_CFG_TRUSTED_CALL_ID_9     9
#define OS_CFG_TRUSTED_CALL_ID_10     10
#define OS_CFG_TRUSTED_CALL_ID_11     11
#define OS_CFG_TRUSTED_CALL_ID_12     12
#define OS_CFG_TRUSTED_CALL_ID_13     13
#define OS_CFG_TRUSTED_CALL_ID_14     14
#define OsMaxAccessGroupIds         3U
#define OsNumberOfMPURegions_0      7
#define OsNumberOfMPURegions_1      7
#define OsNumberOfMPURegions_2      7


/* CoreId Type */
#define OS_CFG_CORE_CORE_0        OsCoreAsr0
#define OsCoreAsr0             0UL
#define OS_CFG_CORE_COREINVALID               1UL


/* Application Type  */
#define OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM            0UL
#define OS_CFG_OSAPPLICATION_QM            1UL
#define OS_CFG_OSAPPLICATION_MCAN            2UL
#define OS_CFG_APPLICATION_INVALID      0xFFU


/* AccessRightsIdType */
#define OS_CFG_MPU_REGION_0      0UL
#define OS_CFG_MPU_REGION_1      1UL
#define OS_CFG_MPU_REGION_2      2UL
#define OS_CFG_MPU_REGION_INVALID       0xFFFFFFFFU


#define OS_CFG_MPU_STACK_REGION_NUM     2


/* Num of applications in core */
#define OsNumberOfApplicationsCore0        3


/* OsApp count accessing given resource */
#define OsNumberOfApplicationsSchedRes0    3


#define OsNumberOfTasks              18U
#define OsNumberOfAlarms             22U
#define OsMaxPriorityLevel           18U
#define OsNumberOfAutoStartTasks     2
#define osMaxCounterId               2U
#define OsNumberOfIsr                15U
#define OsMaxNumOfObjectId           (OsNumberOfTasks + OsNumberOfIsr)
#define OsNumberOfRes                1U


/* Resource IDs */


#define OsCounter_0                         ((CounterType) 0)
#define OsCounter_1                         ((CounterType) 1)


#define osdTimerReloadValue          
#define osdTimerChannel              
#define CC_TYPE                      ECC1
#define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )


/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define OsTask_BswCtrl_EventPeriodic                  ((TaskType)0)
#define OsTask_SNDCDD                  ((TaskType)1)
#define OsTask_COMABS                  ((TaskType)2)
#define OsTask_IOHWAB                  ((TaskType)3)
#define OsTask_CAN_1                  ((TaskType)4)
#define OsTask_CAN_2                  ((TaskType)5)
#define OsTask_CAN_3                  ((TaskType)6)
#define OsTask_CAN_4                  ((TaskType)7)
#define OsTask_UCL_main                  ((TaskType)8)
#define OsTask_UclEvt                  ((TaskType)9)
#define OsTask_COM                  ((TaskType)10)
#define OsTask_Diag                  ((TaskType)11)
#define OsTask_ECUM                  ((TaskType)12)
#define OsTask_NvmSpeedup                  ((TaskType)13)
#define OsTask_SND2ms                  ((TaskType)14)
#define OsTask_MODEMGR                  ((TaskType)15)
#define Init_Task                  ((TaskType)16)
#define OsTask_IdleTask                  ((TaskType)17)


/* Object Names */
/* Task Object Names */
#define Object_OsTask_BswCtrl_EventPeriodic            ((ObjectIdType)0)
#define Object_OsTask_SNDCDD            ((ObjectIdType)1)
#define Object_OsTask_COMABS            ((ObjectIdType)2)
#define Object_OsTask_IOHWAB            ((ObjectIdType)3)
#define Object_OsTask_CAN_1            ((ObjectIdType)4)
#define Object_OsTask_CAN_2            ((ObjectIdType)5)
#define Object_OsTask_CAN_3            ((ObjectIdType)6)
#define Object_OsTask_CAN_4            ((ObjectIdType)7)
#define Object_OsTask_UCL_main            ((ObjectIdType)8)
#define Object_OsTask_UclEvt            ((ObjectIdType)9)
#define Object_OsTask_COM            ((ObjectIdType)10)
#define Object_OsTask_Diag            ((ObjectIdType)11)
#define Object_OsTask_ECUM            ((ObjectIdType)12)
#define Object_OsTask_NvmSpeedup            ((ObjectIdType)13)
#define Object_OsTask_SND2ms            ((ObjectIdType)14)
#define Object_OsTask_MODEMGR            ((ObjectIdType)15)
#define Object_Init_Task            ((ObjectIdType)16)
#define Object_OsTask_IdleTask            ((ObjectIdType)17)


/* Isr Object Names */
#define Object_SystemTimerISR            ((ObjectIdType)18)
#define Object_SPI0            ((ObjectIdType)19)
#define Object_Can_ISR_B            ((ObjectIdType)20)
#define Object_ADC0_ISR            ((ObjectIdType)21)
#define Object_GPT_2            ((ObjectIdType)22)
#define Object_GPT_3            ((ObjectIdType)23)
#define Object_GPT_LPIT            ((ObjectIdType)24)
#define Object_Can_ISR_A            ((ObjectIdType)25)
#define Object_ADMA_SAI0            ((ObjectIdType)26)
#define Object_LPI2C_6            ((ObjectIdType)27)
#define Object_PWM2            ((ObjectIdType)28)
#define Object_GPT_4            ((ObjectIdType)29)
#define Object_GPT_5            ((ObjectIdType)30)
#define Object_GPT6_INT            ((ObjectIdType)31)
#define Object_GPIO1_INT            ((ObjectIdType)32)
#define Object_ObjectIdMax        ((ObjectIdType)33)


/* Object Ids */
#define Os_Object_Id_0          Object_OsTask_BswCtrl_EventPeriodic
#define Os_Object_Id_1          Object_OsTask_SNDCDD
#define Os_Object_Id_2          Object_OsTask_COMABS
#define Os_Object_Id_3          Object_OsTask_IOHWAB
#define Os_Object_Id_4          Object_OsTask_CAN_1
#define Os_Object_Id_5          Object_OsTask_CAN_2
#define Os_Object_Id_6          Object_OsTask_CAN_3
#define Os_Object_Id_7          Object_OsTask_CAN_4
#define Os_Object_Id_8          Object_OsTask_UCL_main
#define Os_Object_Id_9          Object_OsTask_UclEvt
#define Os_Object_Id_10          Object_OsTask_COM
#define Os_Object_Id_11          Object_OsTask_Diag
#define Os_Object_Id_12          Object_OsTask_ECUM
#define Os_Object_Id_13          Object_OsTask_NvmSpeedup
#define Os_Object_Id_14          Object_OsTask_SND2ms
#define Os_Object_Id_15          Object_OsTask_MODEMGR
#define Os_Object_Id_16          Object_Init_Task
#define Os_Object_Id_17          Object_OsTask_IdleTask
#define Os_Object_Id_18          Object_SystemTimerISR
#define Os_Object_Id_19          Object_SPI0
#define Os_Object_Id_20          Object_Can_ISR_B
#define Os_Object_Id_21          Object_ADC0_ISR
#define Os_Object_Id_22          Object_GPT_2
#define Os_Object_Id_23          Object_GPT_3
#define Os_Object_Id_24          Object_GPT_LPIT
#define Os_Object_Id_25          Object_Can_ISR_A
#define Os_Object_Id_26          Object_ADMA_SAI0
#define Os_Object_Id_27          Object_LPI2C_6
#define Os_Object_Id_28          Object_PWM2
#define Os_Object_Id_29          Object_GPT_4
#define Os_Object_Id_30          Object_GPT_5
#define Os_Object_Id_31          Object_GPT6_INT
#define Os_Object_Id_32          Object_GPIO1_INT


/* Alarms */

#define Rte_Al_TE2_OsTask_BswCtrl_EventPeriodic_0_10ms (0U)
#define Rte_Al_TE2_OsTask_COM_0_10ms (1U)
#define Rte_Al_TE2_OsTask_Diag_0_10ms (2U)
#define Rte_Al_TE2_OsTask_ECUM_0_10ms (3U)
#define Rte_Al_TE_CBacklightCdd_CBacklightCdd_Impl_MainFunction (4U)
#define Rte_Al_TE_CSndCdd_CSndCdd_Impl_MainFunction (5U)
#define Rte_Al_TE_CSndCdd_CSndCdd_SpkrDiag_MainFunction (6U)
#define Rte_Al_TE_CSndCdd_CSndCdd_ToneProcess (7U)
#define Rte_Al_TE_EcuMExt_EcuMExt_MainFunction (8U)
#define Rte_Al_TE_Eep24xx_Eep24xx_MainFunction (9U)
#define Rte_Al_TE_Eep_30_XXspi01_Eep_30_XXspi01_MainFunction (10U)
#define Rte_Al_TE_HealthLog_HealthLog_HL_CmpMain (11U)
#define Rte_Al_TE_IoHwAbExt_IoHwAbExt_MainFunction (12U)
#define Rte_Al_TE_IoHwAb_IoHwAb_MainFunction (13U)
#define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable (14U)
#define Rte_Al_TE_OsTask_BswCtrl_EventPeriodic_5_10ms (15U)
#define Rte_Al_TE_OsTask_COMABS_0_10ms (16U)
#define Rte_Al_TE_OsTask_MODEMGR_0_10ms (17U)
#define Rte_Al_TE_PowerCdd_PowerCdd_StateTransistionProcess (18U)
#define Rte_Al_TE_SndCtrl_SndCtrl_CmpMain (19U)
#define Rte_Al_TE_UclProxyCdd_UclProxyCdd_Impl_MainFunction (20U)
#define Rte_Al_TE_WdgM_WdgM_MainFunction (21U)


/* Events */

# define Rte_Ev_Cyclic2_OsTask_BswCtrl_EventPeriodic_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_ECUM_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_BswCtrl_EventPeriodic_5_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_MODEMGR_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CBacklightCdd_CBacklightCdd_Impl_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_A4WD_ERR     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ABS_W_LAMP     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ABS_W_LAMP_1     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AMP_Support_ElecSound     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AVM_BVM_Option     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AVM_View_Display     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AVN_Usm_CluFuelEconomySet     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AVN_Usm_CluThemeSta_New     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Advanced_TBT_Display     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BS2_SOC     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BVM_OnOffEquipstate     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_CluVoiceVolume     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_FCA_WarnTimeNvalueSet     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_HBANValueSet     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_HDALCFuncNValueSet     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_ISLAAutoNValueSet     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_NmodeFCAoff_NValueSet_N     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_PasSpkrLvNValueSet     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_AVN_SEA_NEWNValueSet     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Ctm_TrailerStopOpenSts     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_DATC_TempDisp_Sts     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Datc_TempDispUnit     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_EMS_SelfRgnRValueSet     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_AccINDforCLU     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_BCMWarning     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_ExtTailAct     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_IAUDigitalKey2Opt     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_IAUOption     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_IAU_Manufacturer     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_IAU_Year     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_IGNSw     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_MemoryP1Cmd     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_PDWDisplayFLH     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_PTGMRValue     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_PTGSpeedRValue     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_PwrAutoOffInfo     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_SMKDispWarn2     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_SeatBeltWngBuz     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Gway_WPCRValue     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_HDA_Opt_USM     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Hud_FontSizeStatus     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Hud_HeightStaus     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_IMT_EOL_state     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_LKA_LaneRecogState     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_Mdps_WLmp     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_PA_BeepAlarm     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_PA_HMI_Stat     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_PCA_RrEquipSta     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_PDW_AutoOn_USM     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_RCCA_WarnLh     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_RCCW_USM     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_SWL_Ind     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_TirePressure_Unit     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CF_VSM_Warn     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CH1_PhraseSpeed     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CR_Ems_BstPre     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CR_Fatc_OutTempSns     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_C_AV_Tail     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_C_RemoteWDWRValueSet     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_C_RrDefoggerCmdAVN     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_C_StopLampLhOpenSts     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EPB_I_LAMP     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FCA_WarningTargetDisplay     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FCO     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GLOW_STAT     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GPS_Year1     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HD_SPS_ChannelNo     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HUCurPosLat     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_AVM_Cal_Cmd     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_AliveStatus     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_DATC_DrTempSetC     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_DATC_DrTempUpDn     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_InitInfo     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_LanguageInfo     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_OpState_New     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_RVM_CameraOff     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_Type     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_VRActivity     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_VehiclePwr     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HU_VoiceGuidance     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ISLA_CondInfoDisp     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ISLA_NACntry1USMSta     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ISLA_OptUsmSta     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LKA_OnOffEquip2Sta     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LVR12_STS     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_L_MIL     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Lane_Info_Color     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_META_V2_3_MapProvider     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_MainMode_SCC     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_MsgGroupNum3     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_N     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_NV_DistToTurn_F1     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_NV_EstDist_F     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Navi_AirConditionWarning     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Navi_ISLA_NoPassingInfoDis     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Navi_ISLA_Popup     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Navi_WarnDist_OverDec     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_OFFROAD_ONOFF_MODE     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_POS_V2_3_Offset     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PROLONG_V2_3_Value     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PROSHORT_V2_3_Offset     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Remained_Distance     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SAS_Angle     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SCC_Char1Sta     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SCC_TrgtDstVal     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SCR_LEVEL_WARN_LAMP     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SCU_WarnMsg2     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SEG_V2_3_Offset     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SLD_VS     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TBT_Display_Type     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TPMS_W_LAMP     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TQ_STND     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TqDistRto_Frt     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VS_TCU     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_WHL_SPD_FL     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_eCall_SWL_Ind     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CSndCdd_CSndCdd_Impl_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CSndCdd_CSndCdd_SpkrDiag_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime     ((EventMaskType)1ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData     ((EventMaskType)2ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo     ((EventMaskType)4ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError     ((EventMaskType)8ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat     ((EventMaskType)16ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake     ((EventMaskType)32ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState     ((EventMaskType)64ULL)
# define Rte_Ev_Run_EcuMExt_EcuMExt_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Eep24xx_Eep24xx_MainFunction     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Eep_30_XXspi01_Eep_30_XXspi01_MainFunction     ((EventMaskType)8ULL)
# define Rte_Ev_Run_HealthLog_HealthLog_HL_CmpMain     ((EventMaskType)4ULL)
# define Rte_Ev_Run_IoHwAbExt_IoHwAbExt_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_ModeMgr_ModeMgr_Uclerror_Runnable     ((EventMaskType)128ULL)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable     ((EventMaskType)16ULL)
# define Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable     ((EventMaskType)1ULL)
# define Rte_Ev_Run_PowerCdd_PowerCdd_StateTransistionProcess     ((EventMaskType)8ULL)
# define Rte_Ev_Run_SndCtrl_SndCtrl_CmpMain     ((EventMaskType)4ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ConfigRecord     ((EventMaskType)256ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ConfigRecordExt     ((EventMaskType)512ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DisplayGetState     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IgnState     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerReportCompState     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqWakeLock     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_WdgM_WdgM_MainFunction     ((EventMaskType)4ULL)


/* Schedule Tables */
#define MainScheduleTable_OsTask_NvM_Stack (0U)
/*****************************************************************************
*                           Auto Start Task Ids                              *
******************************************************************************/
#define OsTaskAutoStart_0                Init_Task
#define OsTaskAutoStart_1                OsTask_IdleTask


/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task 0*********************/

#define osStartAddressTask_0                (osTaskFuncRefType)&OsTask_BswCtrl_EventPeriodicfunc
#define osStackStartAddressTask_0           (osStackPtrType)osdOsTask_BswCtrl_EventPeriodic_TOP
#define osStackSizeTask_0                   sizeof(osTaskStackOsApplication0)
#define osPrioTask_0                        2
#define osMaxActivationCount_0              1
#define osRunningModeTask_0                 
#define osCategoryTask_0                    TASK_NONPREEMPTIVE
#define osTypeTask_0                        TASK_EXTENDED


/********************* Task 1*********************/

#define osStartAddressTask_1                (osTaskFuncRefType)&OsTask_SNDCDDfunc
#define osStackStartAddressTask_1           (osStackPtrType)osdOsTask_SNDCDD_TOP
#define osStackSizeTask_1                   sizeof(osTaskStackOsApplication1)
#define osPrioTask_1                        3
#define osMaxActivationCount_1              1
#define osRunningModeTask_1                 
#define osCategoryTask_1                    TASK_NONPREEMPTIVE
#define osTypeTask_1                        TASK_EXTENDED


/********************* Task 2*********************/

#define osStartAddressTask_2                (osTaskFuncRefType)&OsTask_COMABSfunc
#define osStackStartAddressTask_2           (osStackPtrType)osdOsTask_COMABS_TOP
#define osStackSizeTask_2                   sizeof(osTaskStackOsApplication2)
#define osPrioTask_2                        8
#define osMaxActivationCount_2              1
#define osRunningModeTask_2                 
#define osCategoryTask_2                    TASK_NONPREEMPTIVE
#define osTypeTask_2                        TASK_BASIC


/********************* Task 3*********************/

#define osStartAddressTask_3                (osTaskFuncRefType)&OsTask_IOHWABfunc
#define osStackStartAddressTask_3           (osStackPtrType)osdOsTask_IOHWAB_TOP
#define osStackSizeTask_3                   sizeof(osTaskStackOsApplication3)
#define osPrioTask_3                        13
#define osMaxActivationCount_3              1
#define osRunningModeTask_3                 
#define osCategoryTask_3                    TASK_NONPREEMPTIVE
#define osTypeTask_3                        TASK_EXTENDED


/********************* Task 4*********************/

#define osStartAddressTask_4                (osTaskFuncRefType)&OsTask_CAN_1func
#define osStackStartAddressTask_4           (osStackPtrType)osdOsTask_CAN_1_TOP
#define osStackSizeTask_4                   sizeof(osTaskStackOsApplication4)
#define osPrioTask_4                        9
#define osMaxActivationCount_4              1
#define osRunningModeTask_4                 
#define osCategoryTask_4                    TASK_NONPREEMPTIVE
#define osTypeTask_4                        TASK_EXTENDED


/********************* Task 5*********************/

#define osStartAddressTask_5                (osTaskFuncRefType)&OsTask_CAN_2func
#define osStackStartAddressTask_5           (osStackPtrType)osdOsTask_CAN_2_TOP
#define osStackSizeTask_5                   sizeof(osTaskStackOsApplication5)
#define osPrioTask_5                        10
#define osMaxActivationCount_5              1
#define osRunningModeTask_5                 
#define osCategoryTask_5                    TASK_NONPREEMPTIVE
#define osTypeTask_5                        TASK_EXTENDED


/********************* Task 6*********************/

#define osStartAddressTask_6                (osTaskFuncRefType)&OsTask_CAN_3func
#define osStackStartAddressTask_6           (osStackPtrType)osdOsTask_CAN_3_TOP
#define osStackSizeTask_6                   sizeof(osTaskStackOsApplication6)
#define osPrioTask_6                        11
#define osMaxActivationCount_6              1
#define osRunningModeTask_6                 
#define osCategoryTask_6                    TASK_NONPREEMPTIVE
#define osTypeTask_6                        TASK_EXTENDED


/********************* Task 7*********************/

#define osStartAddressTask_7                (osTaskFuncRefType)&OsTask_CAN_4func
#define osStackStartAddressTask_7           (osStackPtrType)osdOsTask_CAN_4_TOP
#define osStackSizeTask_7                   sizeof(osTaskStackOsApplication7)
#define osPrioTask_7                        12
#define osMaxActivationCount_7              1
#define osRunningModeTask_7                 
#define osCategoryTask_7                    TASK_NONPREEMPTIVE
#define osTypeTask_7                        TASK_EXTENDED


/********************* Task 8*********************/

#define osStartAddressTask_8                (osTaskFuncRefType)&OsTask_UCL_mainfunc
#define osStackStartAddressTask_8           (osStackPtrType)osdOsTask_UCL_main_TOP
#define osStackSizeTask_8                   sizeof(osTaskStackOsApplication8)
#define osPrioTask_8                        0
#define osMaxActivationCount_8              1
#define osRunningModeTask_8                 
#define osCategoryTask_8                    TASK_NONPREEMPTIVE
#define osTypeTask_8                        TASK_BASIC


/********************* Task 9*********************/

#define osStartAddressTask_9                (osTaskFuncRefType)&OsTask_UclEvtfunc
#define osStackStartAddressTask_9           (osStackPtrType)osdOsTask_UclEvt_TOP
#define osStackSizeTask_9                   sizeof(osTaskStackOsApplication9)
#define osPrioTask_9                        1
#define osMaxActivationCount_9              1
#define osRunningModeTask_9                 
#define osCategoryTask_9                    TASK_NONPREEMPTIVE
#define osTypeTask_9                        TASK_EXTENDED


/********************* Task 10*********************/

#define osStartAddressTask_10                (osTaskFuncRefType)&OsTask_COMfunc
#define osStackStartAddressTask_10           (osStackPtrType)osdOsTask_COM_TOP
#define osStackSizeTask_10                   sizeof(osTaskStackOsApplication10)
#define osPrioTask_10                        4
#define osMaxActivationCount_10              1
#define osRunningModeTask_10                 
#define osCategoryTask_10                    TASK_NONPREEMPTIVE
#define osTypeTask_10                        TASK_BASIC


/********************* Task 11*********************/

#define osStartAddressTask_11                (osTaskFuncRefType)&OsTask_Diagfunc
#define osStackStartAddressTask_11           (osStackPtrType)osdOsTask_Diag_TOP
#define osStackSizeTask_11                   sizeof(osTaskStackOsApplication11)
#define osPrioTask_11                        14
#define osMaxActivationCount_11              1
#define osRunningModeTask_11                 
#define osCategoryTask_11                    TASK_NONPREEMPTIVE
#define osTypeTask_11                        TASK_BASIC


/********************* Task 12*********************/

#define osStartAddressTask_12                (osTaskFuncRefType)&OsTask_ECUMfunc
#define osStackStartAddressTask_12           (osStackPtrType)osdOsTask_ECUM_TOP
#define osStackSizeTask_12                   sizeof(osTaskStackOsApplication12)
#define osPrioTask_12                        15
#define osMaxActivationCount_12              1
#define osRunningModeTask_12                 
#define osCategoryTask_12                    TASK_NONPREEMPTIVE
#define osTypeTask_12                        TASK_EXTENDED


/********************* Task 13*********************/

#define osStartAddressTask_13                (osTaskFuncRefType)&OsTask_NvmSpeedupfunc
#define osStackStartAddressTask_13           (osStackPtrType)osdOsTask_NvmSpeedup_TOP
#define osStackSizeTask_13                   sizeof(osTaskStackOsApplication13)
#define osPrioTask_13                        16
#define osMaxActivationCount_13              1
#define osRunningModeTask_13                 
#define osCategoryTask_13                    TASK_NONPREEMPTIVE
#define osTypeTask_13                        TASK_EXTENDED


/********************* Task 14*********************/

#define osStartAddressTask_14                (osTaskFuncRefType)&OsTask_SND2msfunc
#define osStackStartAddressTask_14           (osStackPtrType)osdOsTask_SND2ms_TOP
#define osStackSizeTask_14                   sizeof(osTaskStackOsApplication14)
#define osPrioTask_14                        5
#define osMaxActivationCount_14              1
#define osRunningModeTask_14                 
#define osCategoryTask_14                    TASK_NONPREEMPTIVE
#define osTypeTask_14                        TASK_BASIC


/********************* Task 15*********************/

#define osStartAddressTask_15                (osTaskFuncRefType)&OsTask_MODEMGRfunc
#define osStackStartAddressTask_15           (osStackPtrType)osdOsTask_MODEMGR_TOP
#define osStackSizeTask_15                   sizeof(osTaskStackOsApplication15)
#define osPrioTask_15                        6
#define osMaxActivationCount_15              1
#define osRunningModeTask_15                 
#define osCategoryTask_15                    TASK_NONPREEMPTIVE
#define osTypeTask_15                        TASK_EXTENDED


/********************* Task 16*********************/

#define osStartAddressTask_16                (osTaskFuncRefType)&Init_Taskfunc
#define osStackStartAddressTask_16           (osStackPtrType)osdInit_Task_TOP
#define osStackSizeTask_16                   sizeof(osTaskStackOsApplication16)
#define osPrioTask_16                        7
#define osMaxActivationCount_16              1
#define osRunningModeTask_16                 
#define osCategoryTask_16                    TASK_NONPREEMPTIVE
#define osTypeTask_16                        TASK_BASIC


/********************* Task 17*********************/

#define osStartAddressTask_17                (osTaskFuncRefType)&OsTask_IdleTaskfunc
#define osStackStartAddressTask_17           (osStackPtrType)osdOsTask_IdleTask_TOP
#define osStackSizeTask_17                   sizeof(osTaskStackOsApplication17)
#define osPrioTask_17                        17
#define osMaxActivationCount_17              1
#define osRunningModeTask_17                 
#define osCategoryTask_17                    TASK_PREEMPTIVE
#define osTypeTask_17                        TASK_EXTENDED


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************** Alarm 0 ***********************/
#define osCbkOfAlarm_0                    NULL
#define osTaskIdOfAlarm_0                 OsTask_BswCtrl_EventPeriodic
#define osActionOfAlarm_0                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                Rte_Ev_Cyclic2_OsTask_BswCtrl_EventPeriodic_0_10ms
/********************** Alarm 1 ***********************/
#define osCbkOfAlarm_1                    NULL
#define osTaskIdOfAlarm_1                 OsTask_COM
#define osActionOfAlarm_1                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_1                0
/********************** Alarm 2 ***********************/
#define osCbkOfAlarm_2                    NULL
#define osTaskIdOfAlarm_2                 OsTask_Diag
#define osActionOfAlarm_2                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_2                0
/********************** Alarm 3 ***********************/
#define osCbkOfAlarm_3                    NULL
#define osTaskIdOfAlarm_3                 OsTask_ECUM
#define osActionOfAlarm_3                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                Rte_Ev_Cyclic2_OsTask_ECUM_0_10ms
/********************** Alarm 4 ***********************/
#define osCbkOfAlarm_4                    NULL
#define osTaskIdOfAlarm_4                 OsTask_MODEMGR
#define osActionOfAlarm_4                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_4                Rte_Ev_Run_CBacklightCdd_CBacklightCdd_Impl_MainFunction
/********************** Alarm 5 ***********************/
#define osCbkOfAlarm_5                    NULL
#define osTaskIdOfAlarm_5                 OsTask_SNDCDD
#define osActionOfAlarm_5                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_5                Rte_Ev_Run_CSndCdd_CSndCdd_Impl_MainFunction
/********************** Alarm 6 ***********************/
#define osCbkOfAlarm_6                    NULL
#define osTaskIdOfAlarm_6                 OsTask_SNDCDD
#define osActionOfAlarm_6                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_6                Rte_Ev_Run_CSndCdd_CSndCdd_SpkrDiag_MainFunction
/********************** Alarm 7 ***********************/
#define osCbkOfAlarm_7                    NULL
#define osTaskIdOfAlarm_7                 OsTask_SND2ms
#define osActionOfAlarm_7                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_7                0
/********************** Alarm 8 ***********************/
#define osCbkOfAlarm_8                    NULL
#define osTaskIdOfAlarm_8                 OsTask_ECUM
#define osActionOfAlarm_8                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_8                Rte_Ev_Run_EcuMExt_EcuMExt_MainFunction
/********************** Alarm 9 ***********************/
#define osCbkOfAlarm_9                    NULL
#define osTaskIdOfAlarm_9                 OsTask_BswCtrl_EventPeriodic
#define osActionOfAlarm_9                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_9                Rte_Ev_Run_Eep24xx_Eep24xx_MainFunction
/********************** Alarm 10 ***********************/
#define osCbkOfAlarm_10                    NULL
#define osTaskIdOfAlarm_10                 OsTask_BswCtrl_EventPeriodic
#define osActionOfAlarm_10                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_10                Rte_Ev_Run_Eep_30_XXspi01_Eep_30_XXspi01_MainFunction
/********************** Alarm 11 ***********************/
#define osCbkOfAlarm_11                    NULL
#define osTaskIdOfAlarm_11                 OsTask_MODEMGR
#define osActionOfAlarm_11                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_11                Rte_Ev_Run_HealthLog_HealthLog_HL_CmpMain
/********************** Alarm 12 ***********************/
#define osCbkOfAlarm_12                    NULL
#define osTaskIdOfAlarm_12                 OsTask_IOHWAB
#define osActionOfAlarm_12                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_12                Rte_Ev_Run_IoHwAbExt_IoHwAbExt_MainFunction
/********************** Alarm 13 ***********************/
#define osCbkOfAlarm_13                    NULL
#define osTaskIdOfAlarm_13                 OsTask_IOHWAB
#define osActionOfAlarm_13                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_13                Rte_Ev_Run_IoHwAb_IoHwAb_MainFunction
/********************** Alarm 14 ***********************/
#define osCbkOfAlarm_14                    NULL
#define osTaskIdOfAlarm_14                 OsTask_NvmSpeedup
#define osActionOfAlarm_14                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_14                Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable
/********************** Alarm 15 ***********************/
#define osCbkOfAlarm_15                    NULL
#define osTaskIdOfAlarm_15                 OsTask_BswCtrl_EventPeriodic
#define osActionOfAlarm_15                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_15                Rte_Ev_Cyclic_OsTask_BswCtrl_EventPeriodic_5_10ms
/********************** Alarm 16 ***********************/
#define osCbkOfAlarm_16                    NULL
#define osTaskIdOfAlarm_16                 OsTask_COMABS
#define osActionOfAlarm_16                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_16                0
/********************** Alarm 17 ***********************/
#define osCbkOfAlarm_17                    NULL
#define osTaskIdOfAlarm_17                 OsTask_MODEMGR
#define osActionOfAlarm_17                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_17                Rte_Ev_Cyclic_OsTask_MODEMGR_0_10ms
/********************** Alarm 18 ***********************/
#define osCbkOfAlarm_18                    NULL
#define osTaskIdOfAlarm_18                 OsTask_MODEMGR
#define osActionOfAlarm_18                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_18                Rte_Ev_Run_PowerCdd_PowerCdd_StateTransistionProcess
/********************** Alarm 19 ***********************/
#define osCbkOfAlarm_19                    NULL
#define osTaskIdOfAlarm_19                 OsTask_SNDCDD
#define osActionOfAlarm_19                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_19                Rte_Ev_Run_SndCtrl_SndCtrl_CmpMain
/********************** Alarm 20 ***********************/
#define osCbkOfAlarm_20                    NULL
#define osTaskIdOfAlarm_20                 OsTask_UCL_main
#define osActionOfAlarm_20                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_20                0
/********************** Alarm 21 ***********************/
#define osCbkOfAlarm_21                    NULL
#define osTaskIdOfAlarm_21                 OsTask_IOHWAB
#define osActionOfAlarm_21                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_21                Rte_Ev_Run_WdgM_WdgM_MainFunction


/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/


#define osStackStartAddressIsr_0           (osStackPtrType)osdSystemTimerISR_TOP
#define osStackSizeIsr_0                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_1           (osStackPtrType)osdSPI0_TOP
#define osStackSizeIsr_1                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_2           (osStackPtrType)osdCan_ISR_B_TOP
#define osStackSizeIsr_2                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_3           (osStackPtrType)osdADC0_ISR_TOP
#define osStackSizeIsr_3                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_4           (osStackPtrType)osdGPT_2_TOP
#define osStackSizeIsr_4                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_5           (osStackPtrType)osdGPT_3_TOP
#define osStackSizeIsr_5                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_6           (osStackPtrType)osdGPT_LPIT_TOP
#define osStackSizeIsr_6                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_7           (osStackPtrType)osdCan_ISR_A_TOP
#define osStackSizeIsr_7                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_8           (osStackPtrType)osdADMA_SAI0_TOP
#define osStackSizeIsr_8                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_9           (osStackPtrType)osdLPI2C_6_TOP
#define osStackSizeIsr_9                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_10           (osStackPtrType)osdPWM2_TOP
#define osStackSizeIsr_10                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_11           (osStackPtrType)osdGPT_4_TOP
#define osStackSizeIsr_11                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_12           (osStackPtrType)osdGPT_5_TOP
#define osStackSizeIsr_12                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_13           (osStackPtrType)osdGPT6_INT_TOP
#define osStackSizeIsr_13                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_14           (osStackPtrType)osdGPIO1_INT_TOP
#define osStackSizeIsr_14                   (osStackDataType)sizeof(osLevelStackCore0Level1)



/*****************************************************************************
*                               Isr Configs                                  *
******************************************************************************/
/********************** Isr 0***********************/
#define osIsrId_SystemTimerISR 0UL
#define osIsrPrioLevel_SystemTimerISR 128UL
#define osIsrServiceRoutine_SystemTimerISR osTimerInterruptfunc

/********************** Isr 1***********************/
#define osIsrId_SPI0 1UL
#define osIsrPrioLevel_SPI0 128UL
#define osIsrServiceRoutine_SPI0 Spi_LPspi_IsrTDF_LPSPI_0

/********************** Isr 2***********************/
#define osIsrId_Can_ISR_B 2UL
#define osIsrPrioLevel_Can_ISR_B 128UL
#define osIsrServiceRoutine_Can_ISR_B Can_ISR_B

/********************** Isr 3***********************/
#define osIsrId_ADC0_ISR 3UL
#define osIsrPrioLevel_ADC0_ISR 128UL
#define osIsrServiceRoutine_ADC0_ISR ADC_SARADC_ISR_UNIT0

/********************** Isr 4***********************/
#define osIsrId_GPT_2 4UL
#define osIsrPrioLevel_GPT_2 128UL
#define osIsrServiceRoutine_GPT_2 GPT_2_ISR

/********************** Isr 5***********************/
#define osIsrId_GPT_3 5UL
#define osIsrPrioLevel_GPT_3 128UL
#define osIsrServiceRoutine_GPT_3 GPT_3_ISR

/********************** Isr 6***********************/
#define osIsrId_GPT_LPIT 6UL
#define osIsrPrioLevel_GPT_LPIT 128UL
#define osIsrServiceRoutine_GPT_LPIT LPIT_0_ISRfunc

/********************** Isr 7***********************/
#define osIsrId_Can_ISR_A 7UL
#define osIsrPrioLevel_Can_ISR_A 128UL
#define osIsrServiceRoutine_Can_ISR_A Can_ISR_A

/********************** Isr 8***********************/
#define osIsrId_ADMA_SAI0 8UL
#define osIsrPrioLevel_ADMA_SAI0 128UL
#define osIsrServiceRoutine_ADMA_SAI0 MCL_DMA0_CH_COMPLETE_ISR

/********************** Isr 9***********************/
#define osIsrId_LPI2C_6 9UL
#define osIsrPrioLevel_LPI2C_6 128UL
#define osIsrServiceRoutine_LPI2C_6 I2c_LPi2c_Isr_LPI2C_6

/********************** Isr 10***********************/
#define osIsrId_PWM2 10UL
#define osIsrPrioLevel_PWM2 128UL
#define osIsrServiceRoutine_PWM2 PWM_PWM_CH_2_ISR

/********************** Isr 11***********************/
#define osIsrId_GPT_4 11UL
#define osIsrPrioLevel_GPT_4 128UL
#define osIsrServiceRoutine_GPT_4 GPT_4_ISR

/********************** Isr 12***********************/
#define osIsrId_GPT_5 12UL
#define osIsrPrioLevel_GPT_5 128UL
#define osIsrServiceRoutine_GPT_5 GPT_5_ISR

/********************** Isr 13***********************/
#define osIsrId_GPT6_INT 13UL
#define osIsrPrioLevel_GPT6_INT 128UL
#define osIsrServiceRoutine_GPT6_INT GPT_6_ISR

/********************** Isr 14***********************/
#define osIsrId_GPIO1_INT 14UL
#define osIsrPrioLevel_GPIO1_INT 128UL
#define osIsrServiceRoutine_GPIO1_INT ICU_GPIO_1_ISR



/* Task function prototypes */

void OsTask_BswCtrl_EventPeriodicfunc(void);
void OsTask_SNDCDDfunc(void);
void OsTask_COMABSfunc(void);
void OsTask_IOHWABfunc(void);
void OsTask_CAN_1func(void);
void OsTask_CAN_2func(void);
void OsTask_CAN_3func(void);
void OsTask_CAN_4func(void);
void OsTask_UCL_mainfunc(void);
void OsTask_UclEvtfunc(void);
void OsTask_COMfunc(void);
void OsTask_Diagfunc(void);
void OsTask_ECUMfunc(void);
void OsTask_NvmSpeedupfunc(void);
void OsTask_SND2msfunc(void);
void OsTask_MODEMGRfunc(void);
void Init_Taskfunc(void);
void OsTask_IdleTaskfunc(void);
extern const OsAppConfigType OsAppConfig[OsNumberOfApplications];
extern const OsAppConfigRefType OsCore0ApplicationRef[OsNumberOfApplicationsCore0];
extern const OsCoreConfigType OsCoreConfig[OsNumberOfCores];
extern const OsObjConfigType  OsObjConfig[OsMaxNumOfObjectId];
extern const OsObjConfigRefType OsApplication_TrustedSystemObjConfigRef[];
extern const OsObjConfigRefType OsApplication_QMObjConfigRef[];
extern const OsObjConfigRefType OsApplication_MCANObjConfigRef[];
extern const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns];
extern const OsMPUAccessGroupConfigType OsMPUAccessGroupConfig[OsMaxAccessGroupIds];
extern const OsMpuAccessGroupDiffType OsMpuAccessGroupDiff[OsMaxAccessGroupIds][OsMaxAccessGroupIds];
extern const OsIntMpuConfigType OsMpu_TrustedSystem[OsNumberOfMPURegions_0];

extern const OsIntMpuConfigType OsMpu_QMSystem[OsNumberOfMPURegions_0];

extern const OsIntMpuConfigType OsMpu_MCANSystem[OsNumberOfMPURegions_0];

extern OsprioQueueType OsPriorityQueueDyn[OsMaxPriorityLevel];
extern const OsResConfigType OsResConfig[OsNumberOfRes];
extern const TaskPriorityType OsMaxPrioQueueCount[OsMaxPriorityLevel];

extern OsAppConfigRefType OsDynTrustedAppRef[OsNumberOfApplicationsCore0];



/************* OsMessage Configurations ******************************/
#define OsNumberOfTotalMessageQueues         0  /* 1,2,3,4,6 */
#define OsNumberOfRxMessages                 0  /* 0 to 6 */
#define OsNumberOfTxMessages                 0  /* 0,1,2,3,4 */
#define OsNumberOfMsgFlagNotifications       0 /* 0 */
#define OsNumberOfMsgCallbackNotifications   0 /* 2,5 */

#define OsComStartComExtension         1 /* 0 - Standard; 1 - Extended */

#if (OsNumberOfTxMessages>0)
#define osStartCOMExtension() E_OK

#if OsNumberOfMsgFlagNotifications
extern osuint8 osMsgFlags[OsNumberOfMsgFlagNotifications];
#endif
/* DataBuffer[Queue][DataLength] */
extern osuint8  OsMsgDataBuffer0[1][2];
extern osuint8  OsMsgDataBuffer1[2][2];
extern osuint8  OsMsgDataBuffer2[5][1];
extern osuint8  OsMsgDataBuffer3[5][1];
extern osuint8  OsMsgDataBuffer4[5][1];
extern osuint8  OsMsgDataBuffer5[1][2];
extern osuint8  OsMsgDataBuffer6[1][2];

extern osuint8 ReadFlag_Flag0(void);
extern void ClearFlag_Flag0(void);
#endif //OsNumberOfTxMessages

#endif    /* */
/* end of file */
/****************************************************************
Created Time: 7/12/2023 2:43:06 PM
****************************************************************/
