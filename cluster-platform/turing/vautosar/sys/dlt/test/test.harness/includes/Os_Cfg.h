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
#include "OsPrvTypes.h"

                                                                              
                                                                              
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
#define OsNumberOfApplications      2U
#define OsNumberOfTrustedFns        70U
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
#define OS_CFG_TRUSTED_CALL_ID_15     15
#define OS_CFG_TRUSTED_CALL_ID_16     16
#define OS_CFG_TRUSTED_CALL_ID_17     17
#define OS_CFG_TRUSTED_CALL_ID_18     18
#define OS_CFG_TRUSTED_CALL_ID_19     19
#define OS_CFG_TRUSTED_CALL_ID_20     20
#define OS_CFG_TRUSTED_CALL_ID_21     21
#define OS_CFG_TRUSTED_CALL_ID_22     22
#define OS_CFG_TRUSTED_CALL_ID_23     23
#define OS_CFG_TRUSTED_CALL_ID_24     24
#define OS_CFG_TRUSTED_CALL_ID_25     25
#define OS_CFG_TRUSTED_CALL_ID_26     26
#define OS_CFG_TRUSTED_CALL_ID_27     27
#define OS_CFG_TRUSTED_CALL_ID_28     28
#define OS_CFG_TRUSTED_CALL_ID_29     29
#define OS_CFG_TRUSTED_CALL_ID_30     30
#define OS_CFG_TRUSTED_CALL_ID_31     31
#define OS_CFG_TRUSTED_CALL_ID_32     32
#define OS_CFG_TRUSTED_CALL_ID_33     33
#define OS_CFG_TRUSTED_CALL_ID_34     34
#define OS_CFG_TRUSTED_CALL_ID_35     35
#define OS_CFG_TRUSTED_CALL_ID_36     36
#define OS_CFG_TRUSTED_CALL_ID_37     37
#define OS_CFG_TRUSTED_CALL_ID_38     38
#define OS_CFG_TRUSTED_CALL_ID_39     39
#define OS_CFG_TRUSTED_CALL_ID_40     40
#define OS_CFG_TRUSTED_CALL_ID_41     41
#define OS_CFG_TRUSTED_CALL_ID_42     42
#define OS_CFG_TRUSTED_CALL_ID_43     43
#define OS_CFG_TRUSTED_CALL_ID_44     44
#define OS_CFG_TRUSTED_CALL_ID_45     45
#define OS_CFG_TRUSTED_CALL_ID_46     46
#define OS_CFG_TRUSTED_CALL_ID_47     47
#define OS_CFG_TRUSTED_CALL_ID_48     48
#define OS_CFG_TRUSTED_CALL_ID_49     49
#define OS_CFG_TRUSTED_CALL_ID_50     50
#define OS_CFG_TRUSTED_CALL_ID_51     51
#define OS_CFG_TRUSTED_CALL_ID_52     52
#define OS_CFG_TRUSTED_CALL_ID_53     53
#define OS_CFG_TRUSTED_CALL_ID_54     54
#define OS_CFG_TRUSTED_CALL_ID_55     55
#define OS_CFG_TRUSTED_CALL_ID_56     56
#define OS_CFG_TRUSTED_CALL_ID_57     57
#define OS_CFG_TRUSTED_CALL_ID_58     58
#define OS_CFG_TRUSTED_CALL_ID_59     59
#define OS_CFG_TRUSTED_CALL_ID_60     60
#define OS_CFG_TRUSTED_CALL_ID_61     61
#define OS_CFG_TRUSTED_CALL_ID_62     62
#define OS_CFG_TRUSTED_CALL_ID_63     63
#define OS_CFG_TRUSTED_CALL_ID_64     64
#define OS_CFG_TRUSTED_CALL_ID_65     65
#define OS_CFG_TRUSTED_CALL_ID_66     66
#define OS_CFG_TRUSTED_CALL_ID_67     67
#define OS_CFG_TRUSTED_CALL_ID_68     68
#define OS_CFG_TRUSTED_CALL_ID_69     69
#define OsMaxAccessGroupIds         2U
#define OsNumberOfMPURegions_0      7
#define OsNumberOfMPURegions_1      7


/* CoreId Type */
#define OS_CFG_CORE_CORE_0        OsCoreAsr0
#define OsCoreAsr0             0UL
#define OS_CFG_CORE_COREINVALID               1UL


/* Application Type  */
#define OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM            0UL
#define OS_CFG_OSAPPLICATION_QM            1UL
#define OS_CFG_APPLICATION_INVALID      0xFFU


/* AccessRightsIdType */
#define OS_CFG_MPU_REGION_0      0UL
#define OS_CFG_MPU_REGION_1      1UL
#define OS_CFG_MPU_REGION_INVALID       0xFFFFFFFFU


#define OS_CFG_MPU_STACK_REGION_NUM     2


/* Num of applications in core */
#define OsNumberOfApplicationsCore0        2


/* OsApp count accessing given resource */
#define OsNumberOfApplicationsSchedRes0    2


#define OsNumberOfTasks              27U
#define OsNumberOfAlarms             64U
#define OsMaxPriorityLevel           27U
#define OsNumberOfAutoStartTasks     2
#define osMaxCounterId               2U
#define OsNumberOfIsr                10U
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
#define InitTask                  ((TaskType)0)
#define OsTask_IdleTask                  ((TaskType)1)
#define OsTask_BswCtrl_EventPeriodic                  ((TaskType)2)
#define OsTask_Bsw_EventPeriodic_0                  ((TaskType)3)
#define OsTask_Bsw_EventPeriodic_1                  ((TaskType)4)
#define OsTask_NvmSpeedup                  ((TaskType)5)
#define OsTask_SWCEventPeriodic_0                  ((TaskType)6)
#define OsTask_SWCEventPeriodic_1                  ((TaskType)7)
#define OsTask_SWCEventPeriodic_2                  ((TaskType)8)
#define OsTask_SWCEventPeriodic_3                  ((TaskType)9)
#define OsTask_SWCEventPeriodic_4                  ((TaskType)10)
#define OsTask_SWCEventPeriodic_5                  ((TaskType)11)
#define OsTask_SWCEventPeriodic_6                  ((TaskType)12)
#define OsTask_SWCEventPeriodic_7                  ((TaskType)13)
#define OsTask_SWCEventPeriodic_8                  ((TaskType)14)
#define OsTask_SWCEventPeriodic_10                  ((TaskType)15)
#define OsTask_SWCEventPeriodic_11                  ((TaskType)16)
#define OsTask_SWCEventPeriodic_12                  ((TaskType)17)
#define OsTask_SWCEventPeriodic_13                  ((TaskType)18)
#define OsTask_SafeSWCEventPeriodic_0                  ((TaskType)19)
#define OsTask_SafeBsw_0                  ((TaskType)20)
#define OsTask_SafeBsw_1                  ((TaskType)21)
#define OsTask_UclProxyEvent_0                  ((TaskType)22)
#define OsTask_UclProxyEvent_1                  ((TaskType)23)
#define OsTask_Cdd_EventPeriodic_0                  ((TaskType)24)
#define OsTask_Cdd_EventPeriodic_1                  ((TaskType)25)
#define OsTask_SWCEventPeriodic_9                  ((TaskType)26)


/* Object Names */
/* Task Object Names */
#define Object_InitTask            ((ObjectIdType)0)
#define Object_OsTask_IdleTask            ((ObjectIdType)1)
#define Object_OsTask_BswCtrl_EventPeriodic            ((ObjectIdType)2)
#define Object_OsTask_Bsw_EventPeriodic_0            ((ObjectIdType)3)
#define Object_OsTask_Bsw_EventPeriodic_1            ((ObjectIdType)4)
#define Object_OsTask_NvmSpeedup            ((ObjectIdType)5)
#define Object_OsTask_SWCEventPeriodic_0            ((ObjectIdType)6)
#define Object_OsTask_SWCEventPeriodic_1            ((ObjectIdType)7)
#define Object_OsTask_SWCEventPeriodic_2            ((ObjectIdType)8)
#define Object_OsTask_SWCEventPeriodic_3            ((ObjectIdType)9)
#define Object_OsTask_SWCEventPeriodic_4            ((ObjectIdType)10)
#define Object_OsTask_SWCEventPeriodic_5            ((ObjectIdType)11)
#define Object_OsTask_SWCEventPeriodic_6            ((ObjectIdType)12)
#define Object_OsTask_SWCEventPeriodic_7            ((ObjectIdType)13)
#define Object_OsTask_SWCEventPeriodic_8            ((ObjectIdType)14)
#define Object_OsTask_SWCEventPeriodic_10            ((ObjectIdType)15)
#define Object_OsTask_SWCEventPeriodic_11            ((ObjectIdType)16)
#define Object_OsTask_SWCEventPeriodic_12            ((ObjectIdType)17)
#define Object_OsTask_SWCEventPeriodic_13            ((ObjectIdType)18)
#define Object_OsTask_SafeSWCEventPeriodic_0            ((ObjectIdType)19)
#define Object_OsTask_SafeBsw_0            ((ObjectIdType)20)
#define Object_OsTask_SafeBsw_1            ((ObjectIdType)21)
#define Object_OsTask_UclProxyEvent_0            ((ObjectIdType)22)
#define Object_OsTask_UclProxyEvent_1            ((ObjectIdType)23)
#define Object_OsTask_Cdd_EventPeriodic_0            ((ObjectIdType)24)
#define Object_OsTask_Cdd_EventPeriodic_1            ((ObjectIdType)25)
#define Object_OsTask_SWCEventPeriodic_9            ((ObjectIdType)26)


/* Isr Object Names */
#define Object_SystemTimerISR            ((ObjectIdType)27)
#define Object_Can_ISR_B            ((ObjectIdType)28)
#define Object_ADC0_ISR            ((ObjectIdType)29)
#define Object_GPT_2            ((ObjectIdType)30)
#define Object_GPT_3            ((ObjectIdType)31)
#define Object_SPI0            ((ObjectIdType)32)
#define Object_SPI2            ((ObjectIdType)33)
#define Object_GPT_LPIT            ((ObjectIdType)34)
#define Object_GPT_4            ((ObjectIdType)35)
#define Object_GPIO0_INT            ((ObjectIdType)36)
#define Object_ObjectIdMax        ((ObjectIdType)37)


/* Object Ids */
#define Os_Object_Id_0          Object_InitTask
#define Os_Object_Id_1          Object_OsTask_IdleTask
#define Os_Object_Id_2          Object_OsTask_BswCtrl_EventPeriodic
#define Os_Object_Id_3          Object_OsTask_Bsw_EventPeriodic_0
#define Os_Object_Id_4          Object_OsTask_Bsw_EventPeriodic_1
#define Os_Object_Id_5          Object_OsTask_NvmSpeedup
#define Os_Object_Id_6          Object_OsTask_SWCEventPeriodic_0
#define Os_Object_Id_7          Object_OsTask_SWCEventPeriodic_1
#define Os_Object_Id_8          Object_OsTask_SWCEventPeriodic_2
#define Os_Object_Id_9          Object_OsTask_SWCEventPeriodic_3
#define Os_Object_Id_10          Object_OsTask_SWCEventPeriodic_4
#define Os_Object_Id_11          Object_OsTask_SWCEventPeriodic_5
#define Os_Object_Id_12          Object_OsTask_SWCEventPeriodic_6
#define Os_Object_Id_13          Object_OsTask_SWCEventPeriodic_7
#define Os_Object_Id_14          Object_OsTask_SWCEventPeriodic_8
#define Os_Object_Id_15          Object_OsTask_SWCEventPeriodic_10
#define Os_Object_Id_16          Object_OsTask_SWCEventPeriodic_11
#define Os_Object_Id_17          Object_OsTask_SWCEventPeriodic_12
#define Os_Object_Id_18          Object_OsTask_SWCEventPeriodic_13
#define Os_Object_Id_19          Object_OsTask_SafeSWCEventPeriodic_0
#define Os_Object_Id_20          Object_OsTask_SafeBsw_0
#define Os_Object_Id_21          Object_OsTask_SafeBsw_1
#define Os_Object_Id_22          Object_OsTask_UclProxyEvent_0
#define Os_Object_Id_23          Object_OsTask_UclProxyEvent_1
#define Os_Object_Id_24          Object_OsTask_Cdd_EventPeriodic_0
#define Os_Object_Id_25          Object_OsTask_Cdd_EventPeriodic_1
#define Os_Object_Id_26          Object_OsTask_SWCEventPeriodic_9
#define Os_Object_Id_27          Object_SystemTimerISR
#define Os_Object_Id_28          Object_Can_ISR_B
#define Os_Object_Id_29          Object_ADC0_ISR
#define Os_Object_Id_30          Object_GPT_2
#define Os_Object_Id_31          Object_GPT_3
#define Os_Object_Id_32          Object_SPI0
#define Os_Object_Id_33          Object_SPI2
#define Os_Object_Id_34          Object_GPT_LPIT
#define Os_Object_Id_35          Object_GPT_4
#define Os_Object_Id_36          Object_GPIO0_INT


/* Alarms */

#define Rte_Al_TE2_OsTask_BswCtrl_EventPeriodic_0_10ms (0U)
#define Rte_Al_TE2_OsTask_Bsw_EventPeriodic_0_0_10ms (1U)
#define Rte_Al_TE2_OsTask_Bsw_EventPeriodic_0_2_10ms (2U)
#define Rte_Al_TE2_OsTask_Bsw_EventPeriodic_1_0_20ms (3U)
#define Rte_Al_TE_AASample1Mdl_AASample1Mdl_Impl_MainFunction (4U)
#define Rte_Al_TE_CAASampleMdl_CAASampleMdl_Impl_MainFunction (5U)
#define Rte_Al_TE_CComAbsMdl_CComAbsMdl_Impl_RxCanMdlMainFunction (6U)
#define Rte_Al_TE_CComAbsMdl_CComAbsMdl_Impl_TxCanMdlMainFunction (7U)
#define Rte_Al_TE_CSndCdd_CSndCdd_Impl_MainFunction (8U)
#define Rte_Al_TE_CanTp_CanTp_MainFunction (9U)
#define Rte_Al_TE_CddOsph_CddOsph_MainFunction (10U)
#define Rte_Al_TE_CddOsph_ParsedCdd_CmpMain (11U)
#define Rte_Al_TE_Chimes_Chimes_CmpMain (12U)
#define Rte_Al_TE_Com_Com_MainFunctionRx (13U)
#define Rte_Al_TE_Compass_Compass_CmpMain (14U)
#define Rte_Al_TE_Configuration_Configuration_CmpMain (15U)
#define Rte_Al_TE_ControlMirror_ControlMirror_CmpMain (16U)
#define Rte_Al_TE_Diagnostics_Diagnostics_CmpMain (17U)
#define Rte_Al_TE_DmnMgr_DmnMgr_CmpMain (18U)
#define Rte_Al_TE_Eprndl_Eprndl_CmpMain (19U)
#define Rte_Al_TE_Etm_Etm_CmpMain (20U)
#define Rte_Al_TE_Gauges_Gauges_CmpMain (21U)
#define Rte_Al_TE_HealthLog_HealthLog_HL_CmpMain (22U)
#define Rte_Al_TE_Illumination_Illumination_CmpMain (23U)
#define Rte_Al_TE_Infotainment_Infotainment_CmpMain (24U)
#define Rte_Al_TE_IoHwAb_IoHwAb_MainFunction (25U)
#define Rte_Al_TE_McuExt_McuExt_ClockMon_CyclicCheck (26U)
#define Rte_Al_TE_MemAbstractMdl_CMemAbstractMdl_Impl_MainFunction (27U)
#define Rte_Al_TE_MemAbstractStub_MemAbstractStub_ImplMainFunction (28U)
#define Rte_Al_TE_ModeMgr_ModeMgr_Mainfunction (29U)
#define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable (30U)
#define Rte_Al_TE_Oat_Oat_CmpMain (31U)
#define Rte_Al_TE_Odometer_Odometer_CmpMain (32U)
#define Rte_Al_TE_OsTask_BswCtrl_EventPeriodic_0_10ms (33U)
#define Rte_Al_TE_OsTask_Bsw_EventPeriodic_0_0_10ms (34U)
#define Rte_Al_TE_OsTask_Bsw_EventPeriodic_0_6_10ms (35U)
#define Rte_Al_TE_OsTask_Cdd_EventPeriodic_0_0_10ms (36U)
#define Rte_Al_TE_OsTask_Cdd_EventPeriodic_0_2_10ms (37U)
#define Rte_Al_TE_OsTask_SWCEventPeriodic_13_0_10ms (38U)
#define Rte_Al_TE_OsTask_SWCEventPeriodic_4_4_30ms (39U)
#define Rte_Al_TE_OsTask_SWCEventPeriodic_5_0_10ms (40U)
#define Rte_Al_TE_OsTask_SWCEventPeriodic_6_0_100ms (41U)
#define Rte_Al_TE_OsTask_SafeBsw_0_0_100ms (42U)
#define Rte_Al_TE_OsTask_SafeBsw_0_0_10ms (43U)
#define Rte_Al_TE_OsTask_SafeBsw_1_0_10ms (44U)
#define Rte_Al_TE_OsTask_SafeBsw_1_0_20ms (45U)
#define Rte_Al_TE_Personalization_Personalization_CmpMain (46U)
#define Rte_Al_TE_PowerCdd_PowerCdd_StateTransistionProcess (47U)
#define Rte_Al_TE_Power_Power_CmpMain (48U)
#define Rte_Al_TE_Rtt_Rtt_CmpMain (49U)
#define Rte_Al_TE_SDM_SDM_CmpMain (50U)
#define Rte_Al_TE_SWC_SWC_CmpMain (51U)
#define Rte_Al_TE_SndCtrl_SndCDD_CmpMain (52U)
#define Rte_Al_TE_SysTst_OsTask_SafeBsw_1_5ms_WdgCheckpoint (53U)
#define Rte_Al_TE_SysTst_OsTask_SafeSWCEventPeriodic_0_10ms_WdgCheckpoint (54U)
#define Rte_Al_TE_SysTst_OsTask_SafeSWCEventPeriodic_0_16ms_WdgCheckpoint (55U)
#define Rte_Al_TE_SysTst_OsTask_SafeSWCEventPeriodic_0_20ms_WdgCheckpoint (56U)
#define Rte_Al_TE_SysTst_OsTask_SafeSWCEventPeriodic_0_30ms_WdgCheckpoint (57U)
#define Rte_Al_TE_Telltale_Telltale_CmpMain (58U)
#define Rte_Al_TE_TripComputer_TripComputer_CmpMain (59U)
#define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (60U)
#define Rte_Al_TE_Warnings_Warnings_CmpMain (61U)
#define Rte_Al_TE_Welcome_Welcome_CmpMain (62U)
#define Rte_Al_TE_vSwUpdM_vSwUpdM_MainFunction (63U)


/* Events */

# define Rte_Ev_Cyclic2_OsTask_BswCtrl_EventPeriodic_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_0_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_0_2_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_1_0_20ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_BswCtrl_EventPeriodic_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_Bsw_EventPeriodic_0_0_10ms     ((EventMaskType)4ULL)
# define Rte_Ev_Cyclic_OsTask_Bsw_EventPeriodic_0_6_10ms     ((EventMaskType)8ULL)
# define Rte_Ev_Cyclic_OsTask_Cdd_EventPeriodic_0_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_Cdd_EventPeriodic_0_2_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_13_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_4_4_30ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_5_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_6_0_100ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SafeBsw_0_0_100ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SafeBsw_0_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_SafeBsw_1_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_SafeBsw_1_0_20ms     ((EventMaskType)2ULL)
# define Rte_Ev_OnRx_OsTask_UclProxyEvent_0_Telltale_pSR_RTT_Status_RTT_StatusData     ((EventMaskType)1ULL)
# define Rte_Ev_Run_AASample1Mdl_AASample1Mdl_Impl_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CAASampleMdl_CAASampleMdl_Impl_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_Impl_RxCanMdlMainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_Impl_TxCanMdlMainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACM_HDChanStatus     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_ARResponse_Rsp     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_CurrTUBand_St     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_CurrTUDRService2_St     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_CurrentPSName_St     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_CurrentPTYCode_St     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_CurrentStatFlags_St     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ACU_FunctionStatus_St     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AHU_Chime_Supported     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_APIM_ActiveTrackNum_St     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_APIM_TotalPlayTime_St     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AUDIO_MC_WORD_Tx     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ActChrgEndMin_No_Actl     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ActChrgStrtMin_No_Actl     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ActvFrontSteMsgTxt_D_Rq     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Adaptive_Hdlmp_Fault     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AhbStat_B_Dsply     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ApaSys_D_Stat     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AslIconDsply_D_Rq     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AutoHoldMde_D_Ind     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AutoHoldMsgTxt_D_Rq     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AutoTowActv_B_Stat     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AutoTowAllw_D_StatMnu     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AwdLckLamp_D_Rq     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AwdLckWhlFl_Pc_RqDsply     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_AwdRnge_D_Actl     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattChrgTrgtSoC_D_Rq     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattTracHazrd_D_Stat     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattTracSoc_Pc_Dsply     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattTracSrvcRqd_B_Rq     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattTracWarnLamp_B_Rq     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BattULoChrgHyb_D_Stat     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Batt_Crit_SoC_B     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BpedDrvAppl_D_Actl     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BrkMdeInhbt_B_RqDsply     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_BrkPadMsgTxt_D_Rq     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CONMP_MC_WORD_Tx     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CcOvrrdActv_B_Actl     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CcStat_D_Actl     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Ccd_B_Falt     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChargeNowDuration_St     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChimeBrk_B_Rq     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChkPlgtoStrt_D_Dsply     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgLocIdCurnt_D_Sav     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgNowCurnt_B_Dsply     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgPortDrOpen_B_Stat     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgStat_D2_Dsply     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgStat_D_Dsply     ((EventMaskType)562949953421312ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ChrgrSrvcRqd_B_Rq     ((EventMaskType)1125899906842624ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ClrExitAsstChime_D_Rq     ((EventMaskType)2251799813685248ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ClrExitAsstMsgTxt_D_Rq     ((EventMaskType)4503599627370496ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ClrExitAsst_D_Stat     ((EventMaskType)9007199254740992ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CstmDrvMde1_No_Confg1     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CtrStkFeat2NoActl     ((EventMaskType)18014398509481984ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_CtrStkFeatConfigActl     ((EventMaskType)36028797018963968ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DcChrgSrvcRqd_B_Rq     ((EventMaskType)72057594037927936ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DieslPrtcWarn_D_Rq     ((EventMaskType)144115188075855872ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DispGlblClkAdj_B_Rq     ((EventMaskType)288230376151711744ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Disp_VehUnitTempUsrSel     ((EventMaskType)576460752303423488ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrLatchFlMsgTxt_D_Rq     ((EventMaskType)1152921504606846976ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrLatchFrMsgTxt_D_Rq     ((EventMaskType)2305843009213693952ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrLatchRlMsgTxt_D_Rq     ((EventMaskType)4611686018427387904ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrLatchRrMsgTxt_D_Rq     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrPrsntDrv_D_Stat     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrTgateChime2_D_Rq     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrvBhavWarn_B_Rq     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrvDsplyPalette_D_Stat     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrvHazrd_D_St     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrvSlipCtlMdeMsg_D_Rq     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_DrvSlipCtlOffLamp_D_Rq     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ECG_MC_WORD_Tx     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ECMMILRequest     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EPAS_Failure     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EcoCochA_Pc_Dsply     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EdmCurrent_Fe_Dsply     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EffWhlLvl2_Pc_Dsply     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EmgcyCallFalt_B_Dsply     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngAirFiltMsgTxt_D_Rq     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngAout_N_Actl     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngAout_N_Dsply     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngClnt_Te_Actl     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngExhMdeQuiet_D2_Stat     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngMnfld_P_Actl     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngMsgTxt_D_Rq     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngOff_T_Actl     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngOilLvlWarn_D_Rq1     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EngTeColdPrtct_D_Stats     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EsaOn_B_Stat     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EstmChrgTimeHP_St     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_EstmChrgTimeLP_St     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FcwMsgTxt_D_Rq     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigBcmActl     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigCcmActl     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigDdmActl     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigDsmActl     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigFcimActl     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigHcmActl     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigHudActl     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigIpmaActl     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigSccmActl     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FeatConfigVdmActl     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FohEnbl_B_Rq     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FohStrtDateDay_No_Stat     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FpaChime_D_Rq     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FuelFlw_Vl_ActlFoh     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_FuelLvlWarn_D_ActlEng     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GPS_Compass_direction     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GboxOil_Te_Actl     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GearLvrPos_D_Actl     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GlblClkYr_No_Actl     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GrdAsstActv_B_Stat     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GsmGearMsgTxt_D_Rq     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_GsmSrvcRqd_B_Rq     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HMI_HMIMode_St     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HdcOn_B_Ind     ((EventMaskType)562949953421312ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HeadLghtHiOn_B_Stat     ((EventMaskType)1125899906842624ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HeadLghtHiOn_B_StatAhb     ((EventMaskType)2251799813685248ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HeadLghtHiOn_B_StatHcm     ((EventMaskType)4503599627370496ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HsaStat_D_Actl     ((EventMaskType)9007199254740992ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HtrnOvrTeLamp_B_Dsply     ((EventMaskType)18014398509481984ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HtrnSrvcRqd_B_Dsply     ((EventMaskType)36028797018963968ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HtrnWarnLamp_B_Dsply     ((EventMaskType)72057594037927936ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HudBrightMnuOn_B_Stat     ((EventMaskType)144115188075855872ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_HybMdeStat_D_Dsply     ((EventMaskType)288230376151711744ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ICI_BtnID_A     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_IaccVAdjLim_No_Actl     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Ignition_Status     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_IndvMdeSel_D_Stat     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_KeyAdmnTot_No_Cnt     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LBS2_ListServer     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LcwaMsgTxt_D_Stat     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LocationServices_1     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_LocationServices_3     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Lockmsgtxt_D_Rq     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_MC_RDISP_WORD_Rx     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_MK_AudioLimitConfig_Rq     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ManRgenSoot_Pc_RqDsply     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_MemDrvDeny_B_Stat     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Memory_Cmd     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Memory_Feedback_Rqst     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_NAV_MC_WORD_Tx     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Nav_DistancToDestVal_St     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ObjectEntrapped     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Outside_Air_Temp_Stat     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PHONE_MC_WORD_Tx     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PdstrnAlrt_B_Falt     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PoliceDmngLvl_D_Stat     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Power_Liftgate_Mode_Stt     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkAidAcsyFront_D_Stat     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkAid_D_Falt     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkBrkRedLamp_D_Rq     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkLckCtlAvail_T_Stat     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkLckCtlLatch_B_Rq     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkLckCtlMsgTxt_D_Rq     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PrkLckCtlTow_B_Enbl     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PtDrvMde_D_Stat     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PtLatchActv_B_RqBcm     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwPckTqRdyChime_B_Rq     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwPckTqRdy_B_Dsply     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwPckTq_D_Stat     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwStepMsgTxt_D_Rq     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwSysULoFalt_D_Stat     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwTgateLamp_B_Rq     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwTgateMsgTxt_B_Rq     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwTgateStepMsgTxt_B_Rq     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_PwWhlLvl_Pc_Dsply     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RILReq     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RearDiffLckLamp_D_Rq     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RearDiffLckLamp_D_Rq2     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RearDiffLckMsg2_D_Rq     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RearDiffSrvcRqd_B_Rq     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RecallEvent_No_Cnt     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_ResetTrip1_B_Rq     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RgenEvntLvl_Pc_Dsply     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RngPerChrgAvg_L_Dsply     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Row2DrvPrsnc_D_Actl     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_RunDryPrevent_B_Stat     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Running_Board_Stat     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SDARS_CurrentChanNum2_St     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SDARS_CurrentChanNum_St     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SDARS_MC_WORD_Tx     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SDARS_Receive_Err_St     ((EventMaskType)562949953421312ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SeatOccRearChime_B_Rq     ((EventMaskType)1125899906842624ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SeatSlprPosMsgTxt_B_Rq     ((EventMaskType)2251799813685248ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SelDrvMdeMsgTxt_D_Rq     ((EventMaskType)4503599627370496ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SelDrvMdePos01_D_Stat     ((EventMaskType)9007199254740992ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SetTimeFormat     ((EventMaskType)18014398509481984ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Shed_Level_Req     ((EventMaskType)36028797018963968ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SldrlChime_D_Rq     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SldrlMsgTxt_D2_Rq     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SldrlStat_B_Actl     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SldrrChime_D_Rq     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SldrrMsgTxt_D2_Rq     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SnowPlowMde_B_Enbl     ((EventMaskType)72057594037927936ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SodLeft_D_Stat     ((EventMaskType)144115188075855872ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SodRight_D_Stat     ((EventMaskType)288230376151711744ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_StePinComp_An_Est     ((EventMaskType)576460752303423488ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SteWhlCompAnEst_D_Qf     ((EventMaskType)1ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SteWhlComp_An_Est     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_SteWhlSwtchMenu_B_Stat     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_StopStrtMsgTxt_D_Rq     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_StopStrtVThres_D_Stat     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_StrtrMtrCtlMsgTxt_D_Rq     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Tire_Press_ILR_Data     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Tire_Press_LF_Data     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Tire_Press_System_Stat     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Tire_Temp_LF_Data     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrcmSrvcRqd_B_Rq     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrAidEnbl_D2_Stat     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrAidMsgTxt_D2_Rq     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrAnCalib_Pc_Actl     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrAnOffstDir_D_Calc     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrAnOffst_An_Calc     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrBrkActCnnct_B_Actl     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrBrkCtl2_B_Falt     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrLampCnnct_B_Actl     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrRvrseEnbl_D2_Stat     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrTireLf_T_Actl     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrTireSensLr_D_Stat     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrTireSensRr_D_Stat     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrlrTireThresh_D_Stat     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnGearMsgTxt2_D_Rq     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnGearMsgTxt_D_Rq     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnGearNtmAllow_B_Stat     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnIpcDsplyGear_D_Actl     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnManShif_D_IndDrv     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnMsgTxt2_D_Rq     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnMsgTxt_D_Rq     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TrnSrvcRqd_B_Rq     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TsrRegionTxt_D_Stat     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TsrVl2RstrcMsgTxt2_D_Rq     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_TurnLghtSwtch_D_Stat     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaLvlQlty_D_RqDsply     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaLvlTxtWarn_D_Rq     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaLvlTxt_D_RqDsply     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaLvl_Pc_Actl     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaMnAdd_L2_Actl     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaMxAdd_L2_Actl     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaQltyFlg_B_RqDsply     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaQltySysWarn_D_Rq     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_UreaQltySys_D_RqDsply     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VRM_BTEndTelService_Rsp     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VRM_BTSignalStrength_St     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VRM_CallDuration_St     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehElEffAvg_No_Dsply     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehElRnge_L_Dsply     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehOnSrc_D_Stat     ((EventMaskType)562949953421312ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehPtch_An_Dsply     ((EventMaskType)1125899906842624ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehRol_An_Dsply     ((EventMaskType)2251799813685248ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehStrtInhbt_D_Dsply     ((EventMaskType)4503599627370496ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehUreaRnge2_L_DsplyMx     ((EventMaskType)9007199254740992ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehUreaRnge3_L_DsplyMx     ((EventMaskType)18014398509481984ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehUreaWarn_V_DsplyMx     ((EventMaskType)36028797018963968ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_Veh_V_DsplyCcSet     ((EventMaskType)72057594037927936ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehicleGGCCData     ((EventMaskType)144115188075855872ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_WaterInFuel_B_Falt     ((EventMaskType)288230376151711744ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_AUDIO_MC_WORD_Rx     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_AccDeny_B_RqIpc     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_AvgFe_No_Dsply     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_CONMP_MC_WORD_Rx     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Chime_Directionality     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Chime_Directionality2     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_ConsAvgTrip_Fe_Dsply     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_ConsLongTerm_No_Dsply     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_DISPLAY_SPEED_OFFSET     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_DistTrip1_No_Dsply     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_DoNotDisturbOveride_St     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_ECG_MC_WORD_Rx     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_ElDistTrip1_No_Dsply     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_ElLongTerm_L_Dsply     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_FeatConfigIpc2Actl     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_FeatConfigIpcActl     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_FohStrtHr_T_Rq     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_FohT1Friday_T_Rq     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_HEC_AROperationType_Rq     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_HEC_BTEndTelService_Rq     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_HEC_SetCurrTUBand_Rq     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_InstFeMax_No_Dsply     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_InstFe_No_Dsply     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_IsaOffst_D_Rq     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_LBC1_ActiveListID     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_LangUpdate_Rsp     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_MC_RDISP_WORD_Tx     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_MK_CreateMyKey_Rsp     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_MK_DNDRestrictConf_St     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Mc_CancelCurrWaypt_Rq     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Mc_PerTUPresetArea_Rq     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Mc_VehLangUsrSel_St     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_MetricActv_B_Dsply     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_MsgCntrFeatNoRq     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_NAV_MC_WORD_Rx     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_PHONE_MC_WORD_Rx     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_RILStat     ((EventMaskType)64ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_SDARS_MC_WORD_Rx     ((EventMaskType)128ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_SelDrvMdeCnfm_D_Stat     ((EventMaskType)256ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_Sod_D_Rq     ((EventMaskType)512ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_TeltalWarnData_No_Actl     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_TimerTrip1_T_Dsply     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_TripSum_L_Dsply     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_TrlBrkInitOut_D_Rq     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataTx_TrlrTireThresh_D_RqDrv     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_CFotaCdd_OnDre_FOTAResponse     ((EventMaskType)4ULL)
# define Rte_Ev_Run_CMeetCdd_OnDre_DiagResponse     ((EventMaskType)8ULL)
# define Rte_Ev_Run_CSndCdd_CSndCdd_Impl_MainFunction     ((EventMaskType)16ULL)
# define Rte_Ev_Run_CanTp_CanTp_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CddOsph_CddOsph_MainFunction     ((EventMaskType)32ULL)
# define Rte_Ev_Run_CddOsph_ParsedCdd_CmpMain     ((EventMaskType)64ULL)
# define Rte_Ev_Run_Chimes_Chimes_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Com_Com_MainFunctionRx     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Compass_Compass_CmpMain     ((EventMaskType)1ULL)
# define Rte_Ev_Run_Configuration_Configuration_CmpMain     ((EventMaskType)1ULL)
# define Rte_Ev_Run_ControlMirror_ControlMirror_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_ControlMirror_ControlMirror_OnMcCmd_ControlPopup_Cmd     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Diagnostics_Diagnostics_CmpMain     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_Diagnostics_OnDre_DR_DiagResponse     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_CmpMain     ((EventMaskType)1ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime     ((EventMaskType)2ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData     ((EventMaskType)4ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo     ((EventMaskType)8ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError     ((EventMaskType)16ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat     ((EventMaskType)32ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake     ((EventMaskType)64ULL)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState     ((EventMaskType)128ULL)
# define Rte_Ev_Run_Eprndl_Eprndl_CmpMain     ((EventMaskType)256ULL)
# define Rte_Ev_Run_Etm_Etm_CmpMain     ((EventMaskType)576460752303423488ULL)
# define Rte_Ev_Run_Etm_Etm_OnMcCmd_ETM_Request     ((EventMaskType)1152921504606846976ULL)
# define Rte_Ev_Run_Gauges_Gauges_CmpMain     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_HealthLog_HealthLog_HL_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Illumination_Illumination_CmpMain     ((EventMaskType)512ULL)
# define Rte_Ev_Run_Infotainment_Infotainment_CmpMain     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_MainFunction     ((EventMaskType)4ULL)
# define Rte_Ev_Run_McuExt_McuExt_ClockMon_CyclicCheck     ((EventMaskType)1ULL)
# define Rte_Ev_Run_MemAbstractMdl_CMemAbstractMdl_Impl_MainFunction     ((EventMaskType)576460752303423488ULL)
# define Rte_Ev_Run_MemAbstractStub_MemAbstractStub_ImplMainFunction     ((EventMaskType)4ULL)
# define Rte_Ev_Run_ModeMgr_ModeMgr_Mainfunction     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_ModeMgr_ModeMgr_Uclerror_Runnable     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable     ((EventMaskType)4ULL)
# define Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable     ((EventMaskType)1ULL)
# define Rte_Ev_Run_Oat_Oat_CmpMain     ((EventMaskType)8ULL)
# define Rte_Ev_Run_Odometer_Odometer_CmpMain     ((EventMaskType)1ULL)
# define Rte_Ev_Run_Personalization_Personalization_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Personalization_Personalization_OnMcCmd_DAMenu_Cmd     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Personalization_Personalization_OnMcCmd_DAMyView_Cmd     ((EventMaskType)8ULL)
# define Rte_Ev_Run_Personalization_Personalization_OnMcCmd_PersSetting_Cmd     ((EventMaskType)2ULL)
# define Rte_Ev_Run_PowerCdd_PowerCdd_StateTransistionProcess     ((EventMaskType)128ULL)
# define Rte_Ev_Run_Power_Power_CmpMain     ((EventMaskType)1152921504606846976ULL)
# define Rte_Ev_Run_Rtt_Rtt_CmpMain     ((EventMaskType)4ULL)
# define Rte_Ev_Run_SDM_SDM_CmpMain     ((EventMaskType)1152921504606846976ULL)
# define Rte_Ev_Run_SWC_SWC_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_SndCtrl_SndCDD_CmpMain     ((EventMaskType)8ULL)
# define Rte_Ev_Run_SysTst_OsTask_SafeBsw_1_5ms_WdgCheckpoint     ((EventMaskType)8ULL)
# define Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_10ms_WdgCheckpoint     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_16ms_WdgCheckpoint     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_20ms_WdgCheckpoint     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_30ms_WdgCheckpoint     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_Telltale_Telltale_CmpMain     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_TripComputer_TripComputer_CmpMain     ((EventMaskType)4ULL)
# define Rte_Ev_Run_TripComputer_TripComputer_OnMcCmd_TCAccumulation_Reset_Cmd     ((EventMaskType)8ULL)
# define Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_AWDGaugeData     ((EventMaskType)1ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_AdjLimit     ((EventMaskType)2ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_AirFuelRatioState     ((EventMaskType)4ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_AutoStartStopState     ((EventMaskType)8ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_CompassInfo     ((EventMaskType)16ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ConfigRecord     ((EventMaskType)32ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ConfigRecordExt     ((EventMaskType)64ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ControlPopup     ((EventMaskType)128ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DASGenData     ((EventMaskType)256ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest     ((EventMaskType)512ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DieselAdBlueState     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DieselExhaustState     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DieselPRTCFilterState     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower     ((EventMaskType)16ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DistanceToEmpty     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DriverAssistData     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DriverAssistDisplay     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ETMData     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EVCoachState     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EcoAdvice     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EcoCoachDisplay     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EcoCoachTripState     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ElectricEfficiencyFunction     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ElectricRangeDisplay     ((EventMaskType)32ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EngineAirFilterState     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EngineInfo     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ExtETMStatus     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_FastGuageInfo     ((EventMaskType)64ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_FuelEconomy     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_GALCarPlayData     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_GeofencingWarningStatus     ((EventMaskType)128ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_GeofencingWarningText     ((EventMaskType)256ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HighVoltageBatteryBEVDisplay     ((EventMaskType)512ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HighVoltageBatteryDisplay     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IODGaugeData     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IODRBM     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IgnState     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_InfotainmentGenericData     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_LHIStatus     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_LaneKeepAssist     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ListTimeout     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_LocalHazardInformation     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_LogDataBasedOnLogEvent     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_MaintStatus     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_MediaStatus     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_MediaText     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_MediaTextExt     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_NaviData     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_NotReadyToDrive     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_NotifyLogDataReceiveStatus     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_OAT     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_Odometer     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_OffRoadState     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PersRecord1byte     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PersRecord4byte     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PersRecord8byte     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PhoneData     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PhoneGenericData     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerDisState     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerDistributionBEV     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PrefetchData     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PrefetchGenericData     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PrefetchStatus     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon     ((EventMaskType)562949953421312ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RadioData     ((EventMaskType)1125899906842624ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RangeDisplay     ((EventMaskType)2251799813685248ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RearBeltMonitor     ((EventMaskType)4503599627370496ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RequestLogData     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SDARSData     ((EventMaskType)9007199254740992ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SDM     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SDMExt     ((EventMaskType)18014398509481984ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SDMGenericData     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SPRStatus     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SSM     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SSMExt     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SSTM     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SSTMExt     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SWC     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SendLogConfigurationData     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SetupSpeed     ((EventMaskType)36028797018963968ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SlowGuageInfo     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateDataTransferReq     ((EventMaskType)72057594037927936ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateDownloadSwPartReq     ((EventMaskType)144115188075855872ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateEraseSwPartReq     ((EventMaskType)288230376151711744ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateMetaReadReq     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateMetaWriteReq     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SwUpdateUploadSwPartReq     ((EventMaskType)576460752303423488ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TireTempState     ((EventMaskType)1152921504606846976ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TrafficJamAssist     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TrafficSignRecognition     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TrailerInfo     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TrailerLighting     ((EventMaskType)4398046511104ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TrailerTPMSState     ((EventMaskType)8796093022208ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TripComputer     ((EventMaskType)17592186044416ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_VehicleFleetPhoneNumberSt     ((EventMaskType)35184372088832ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay     ((EventMaskType)70368744177664ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay     ((EventMaskType)140737488355328ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningsTPMSData     ((EventMaskType)2305843009213693952ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WelcomeFarewallData     ((EventMaskType)281474976710656ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WelcomeScreens     ((EventMaskType)4611686018427387904ULL)
# define Rte_Ev_Run_Warnings_Warnings_CmpMain     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Welcome_Welcome_CmpMain     ((EventMaskType)2305843009213693952ULL)
# define Rte_Ev_Run_vSwUpdM_vSwUpdM_MainFunction     ((EventMaskType)256ULL)


/* Schedule Tables */
#define MainScheduleTable_OsTask_NvM_Stack (0U)
/*****************************************************************************
*                           Auto Start Task Ids                              *
******************************************************************************/
#define OsTaskAutoStart_0                InitTask
#define OsTaskAutoStart_1                OsTask_IdleTask


/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task 0*********************/

#define osStartAddressTask_0                (osTaskFuncRefType)&InitTaskfunc
#define osStackStartAddressTask_0           (osStackPtrType)osdInitTask_TOP
#define osStackSizeTask_0                   sizeof(osTaskStackOsApplication0)
#define osPrioTask_0                        0
#define osMaxActivationCount_0              3
#define osRunningModeTask_0                 OS_Privilegemode
#define osCategoryTask_0                    TASK_NONPREEMPTIVE
#define osTypeTask_0                        TASK_BASIC


/********************* Task 1*********************/

#define osStartAddressTask_1                (osTaskFuncRefType)&OsTask_IdleTaskfunc
#define osStackStartAddressTask_1           (osStackPtrType)osdOsTask_IdleTask_TOP
#define osStackSizeTask_1                   sizeof(osTaskStackOsApplication1)
#define osPrioTask_1                        26
#define osMaxActivationCount_1              1
#define osRunningModeTask_1                 OS_Privilegemode
#define osCategoryTask_1                    TASK_PREEMPTIVE
#define osTypeTask_1                        TASK_EXTENDED


/********************* Task 2*********************/

#define osStartAddressTask_2                (osTaskFuncRefType)&OsTask_BswCtrl_EventPeriodicfunc
#define osStackStartAddressTask_2           (osStackPtrType)osdOsTask_BswCtrl_EventPeriodic_TOP
#define osStackSizeTask_2                   sizeof(osTaskStackOsApplication2)
#define osPrioTask_2                        1
#define osMaxActivationCount_2              1
#define osRunningModeTask_2                 OS_Privilegemode
#define osCategoryTask_2                    TASK_NONPREEMPTIVE
#define osTypeTask_2                        TASK_EXTENDED


/********************* Task 3*********************/

#define osStartAddressTask_3                (osTaskFuncRefType)&OsTask_Bsw_EventPeriodic_0func
#define osStackStartAddressTask_3           (osStackPtrType)osdOsTask_Bsw_EventPeriodic_0_TOP
#define osStackSizeTask_3                   sizeof(osTaskStackOsApplication3)
#define osPrioTask_3                        5
#define osMaxActivationCount_3              1
#define osRunningModeTask_3                 OS_Privilegemode
#define osCategoryTask_3                    TASK_NONPREEMPTIVE
#define osTypeTask_3                        TASK_EXTENDED


/********************* Task 4*********************/

#define osStartAddressTask_4                (osTaskFuncRefType)&OsTask_Bsw_EventPeriodic_1func
#define osStackStartAddressTask_4           (osStackPtrType)osdOsTask_Bsw_EventPeriodic_1_TOP
#define osStackSizeTask_4                   sizeof(osTaskStackOsApplication4)
#define osPrioTask_4                        6
#define osMaxActivationCount_4              1
#define osRunningModeTask_4                 OS_Privilegemode
#define osCategoryTask_4                    TASK_NONPREEMPTIVE
#define osTypeTask_4                        TASK_EXTENDED


/********************* Task 5*********************/

#define osStartAddressTask_5                (osTaskFuncRefType)&OsTask_NvmSpeedupfunc
#define osStackStartAddressTask_5           (osStackPtrType)osdOsTask_NvmSpeedup_TOP
#define osStackSizeTask_5                   sizeof(osTaskStackOsApplication5)
#define osPrioTask_5                        25
#define osMaxActivationCount_5              1
#define osRunningModeTask_5                 OS_Privilegemode
#define osCategoryTask_5                    TASK_NONPREEMPTIVE
#define osTypeTask_5                        TASK_EXTENDED


/********************* Task 6*********************/

#define osStartAddressTask_6                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_0func
#define osStackStartAddressTask_6           (osStackPtrType)osdOsTask_SWCEventPeriodic_0_TOP
#define osStackSizeTask_6                   sizeof(osTaskStackOsApplication6)
#define osPrioTask_6                        24
#define osMaxActivationCount_6              1
#define osRunningModeTask_6                 OS_Privilegemode
#define osCategoryTask_6                    TASK_NONPREEMPTIVE
#define osTypeTask_6                        TASK_EXTENDED


/********************* Task 7*********************/

#define osStartAddressTask_7                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_1func
#define osStackStartAddressTask_7           (osStackPtrType)osdOsTask_SWCEventPeriodic_1_TOP
#define osStackSizeTask_7                   sizeof(osTaskStackOsApplication7)
#define osPrioTask_7                        23
#define osMaxActivationCount_7              1
#define osRunningModeTask_7                 OS_Privilegemode
#define osCategoryTask_7                    TASK_NONPREEMPTIVE
#define osTypeTask_7                        TASK_EXTENDED


/********************* Task 8*********************/

#define osStartAddressTask_8                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_2func
#define osStackStartAddressTask_8           (osStackPtrType)osdOsTask_SWCEventPeriodic_2_TOP
#define osStackSizeTask_8                   sizeof(osTaskStackOsApplication8)
#define osPrioTask_8                        11
#define osMaxActivationCount_8              1
#define osRunningModeTask_8                 OS_Privilegemode
#define osCategoryTask_8                    TASK_NONPREEMPTIVE
#define osTypeTask_8                        TASK_EXTENDED


/********************* Task 9*********************/

#define osStartAddressTask_9                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_3func
#define osStackStartAddressTask_9           (osStackPtrType)osdOsTask_SWCEventPeriodic_3_TOP
#define osStackSizeTask_9                   sizeof(osTaskStackOsApplication9)
#define osPrioTask_9                        21
#define osMaxActivationCount_9              1
#define osRunningModeTask_9                 OS_Privilegemode
#define osCategoryTask_9                    TASK_NONPREEMPTIVE
#define osTypeTask_9                        TASK_EXTENDED


/********************* Task 10*********************/

#define osStartAddressTask_10                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_4func
#define osStackStartAddressTask_10           (osStackPtrType)osdOsTask_SWCEventPeriodic_4_TOP
#define osStackSizeTask_10                   sizeof(osTaskStackOsApplication10)
#define osPrioTask_10                        22
#define osMaxActivationCount_10              1
#define osRunningModeTask_10                 OS_Privilegemode
#define osCategoryTask_10                    TASK_NONPREEMPTIVE
#define osTypeTask_10                        TASK_EXTENDED


/********************* Task 11*********************/

#define osStartAddressTask_11                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_5func
#define osStackStartAddressTask_11           (osStackPtrType)osdOsTask_SWCEventPeriodic_5_TOP
#define osStackSizeTask_11                   sizeof(osTaskStackOsApplication11)
#define osPrioTask_11                        19
#define osMaxActivationCount_11              1
#define osRunningModeTask_11                 OS_Privilegemode
#define osCategoryTask_11                    TASK_NONPREEMPTIVE
#define osTypeTask_11                        TASK_EXTENDED


/********************* Task 12*********************/

#define osStartAddressTask_12                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_6func
#define osStackStartAddressTask_12           (osStackPtrType)osdOsTask_SWCEventPeriodic_6_TOP
#define osStackSizeTask_12                   sizeof(osTaskStackOsApplication12)
#define osPrioTask_12                        18
#define osMaxActivationCount_12              1
#define osRunningModeTask_12                 OS_Privilegemode
#define osCategoryTask_12                    TASK_NONPREEMPTIVE
#define osTypeTask_12                        TASK_EXTENDED


/********************* Task 13*********************/

#define osStartAddressTask_13                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_7func
#define osStackStartAddressTask_13           (osStackPtrType)osdOsTask_SWCEventPeriodic_7_TOP
#define osStackSizeTask_13                   sizeof(osTaskStackOsApplication13)
#define osPrioTask_13                        17
#define osMaxActivationCount_13              1
#define osRunningModeTask_13                 OS_Privilegemode
#define osCategoryTask_13                    TASK_NONPREEMPTIVE
#define osTypeTask_13                        TASK_EXTENDED


/********************* Task 14*********************/

#define osStartAddressTask_14                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_8func
#define osStackStartAddressTask_14           (osStackPtrType)osdOsTask_SWCEventPeriodic_8_TOP
#define osStackSizeTask_14                   sizeof(osTaskStackOsApplication14)
#define osPrioTask_14                        16
#define osMaxActivationCount_14              1
#define osRunningModeTask_14                 OS_Privilegemode
#define osCategoryTask_14                    TASK_NONPREEMPTIVE
#define osTypeTask_14                        TASK_EXTENDED


/********************* Task 15*********************/

#define osStartAddressTask_15                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_10func
#define osStackStartAddressTask_15           (osStackPtrType)osdOsTask_SWCEventPeriodic_10_TOP
#define osStackSizeTask_15                   sizeof(osTaskStackOsApplication15)
#define osPrioTask_15                        14
#define osMaxActivationCount_15              1
#define osRunningModeTask_15                 OS_Privilegemode
#define osCategoryTask_15                    TASK_NONPREEMPTIVE
#define osTypeTask_15                        TASK_EXTENDED


/********************* Task 16*********************/

#define osStartAddressTask_16                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_11func
#define osStackStartAddressTask_16           (osStackPtrType)osdOsTask_SWCEventPeriodic_11_TOP
#define osStackSizeTask_16                   sizeof(osTaskStackOsApplication16)
#define osPrioTask_16                        20
#define osMaxActivationCount_16              1
#define osRunningModeTask_16                 OS_Privilegemode
#define osCategoryTask_16                    TASK_NONPREEMPTIVE
#define osTypeTask_16                        TASK_EXTENDED


/********************* Task 17*********************/

#define osStartAddressTask_17                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_12func
#define osStackStartAddressTask_17           (osStackPtrType)osdOsTask_SWCEventPeriodic_12_TOP
#define osStackSizeTask_17                   sizeof(osTaskStackOsApplication17)
#define osPrioTask_17                        13
#define osMaxActivationCount_17              1
#define osRunningModeTask_17                 OS_Privilegemode
#define osCategoryTask_17                    TASK_NONPREEMPTIVE
#define osTypeTask_17                        TASK_EXTENDED


/********************* Task 18*********************/

#define osStartAddressTask_18                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_13func
#define osStackStartAddressTask_18           (osStackPtrType)osdOsTask_SWCEventPeriodic_13_TOP
#define osStackSizeTask_18                   sizeof(osTaskStackOsApplication18)
#define osPrioTask_18                        12
#define osMaxActivationCount_18              1
#define osRunningModeTask_18                 OS_Privilegemode
#define osCategoryTask_18                    TASK_NONPREEMPTIVE
#define osTypeTask_18                        TASK_EXTENDED


/********************* Task 19*********************/

#define osStartAddressTask_19                (osTaskFuncRefType)&OsTask_SafeSWCEventPeriodic_0func
#define osStackStartAddressTask_19           (osStackPtrType)osdOsTask_SafeSWCEventPeriodic_0_TOP
#define osStackSizeTask_19                   sizeof(osTaskStackOsApplication19)
#define osPrioTask_19                        4
#define osMaxActivationCount_19              1
#define osRunningModeTask_19                 OS_Privilegemode
#define osCategoryTask_19                    TASK_NONPREEMPTIVE
#define osTypeTask_19                        TASK_EXTENDED


/********************* Task 20*********************/

#define osStartAddressTask_20                (osTaskFuncRefType)&OsTask_SafeBsw_0func
#define osStackStartAddressTask_20           (osStackPtrType)osdOsTask_SafeBsw_0_TOP
#define osStackSizeTask_20                   sizeof(osTaskStackOsApplication20)
#define osPrioTask_20                        2
#define osMaxActivationCount_20              1
#define osRunningModeTask_20                 OS_Privilegemode
#define osCategoryTask_20                    TASK_NONPREEMPTIVE
#define osTypeTask_20                        TASK_EXTENDED


/********************* Task 21*********************/

#define osStartAddressTask_21                (osTaskFuncRefType)&OsTask_SafeBsw_1func
#define osStackStartAddressTask_21           (osStackPtrType)osdOsTask_SafeBsw_1_TOP
#define osStackSizeTask_21                   sizeof(osTaskStackOsApplication21)
#define osPrioTask_21                        3
#define osMaxActivationCount_21              1
#define osRunningModeTask_21                 OS_Privilegemode
#define osCategoryTask_21                    TASK_NONPREEMPTIVE
#define osTypeTask_21                        TASK_EXTENDED


/********************* Task 22*********************/

#define osStartAddressTask_22                (osTaskFuncRefType)&OsTask_UclProxyEvent_0func
#define osStackStartAddressTask_22           (osStackPtrType)osdOsTask_UclProxyEvent_0_TOP
#define osStackSizeTask_22                   sizeof(osTaskStackOsApplication22)
#define osPrioTask_22                        9
#define osMaxActivationCount_22              1
#define osRunningModeTask_22                 OS_Privilegemode
#define osCategoryTask_22                    TASK_NONPREEMPTIVE
#define osTypeTask_22                        TASK_EXTENDED


/********************* Task 23*********************/

#define osStartAddressTask_23                (osTaskFuncRefType)&OsTask_UclProxyEvent_1func
#define osStackStartAddressTask_23           (osStackPtrType)osdOsTask_UclProxyEvent_1_TOP
#define osStackSizeTask_23                   sizeof(osTaskStackOsApplication23)
#define osPrioTask_23                        8
#define osMaxActivationCount_23              1
#define osRunningModeTask_23                 OS_Privilegemode
#define osCategoryTask_23                    TASK_NONPREEMPTIVE
#define osTypeTask_23                        TASK_EXTENDED


/********************* Task 24*********************/

#define osStartAddressTask_24                (osTaskFuncRefType)&OsTask_Cdd_EventPeriodic_0func
#define osStackStartAddressTask_24           (osStackPtrType)osdOsTask_Cdd_EventPeriodic_0_TOP
#define osStackSizeTask_24                   sizeof(osTaskStackOsApplication24)
#define osPrioTask_24                        10
#define osMaxActivationCount_24              1
#define osRunningModeTask_24                 OS_Privilegemode
#define osCategoryTask_24                    TASK_NONPREEMPTIVE
#define osTypeTask_24                        TASK_EXTENDED


/********************* Task 25*********************/

#define osStartAddressTask_25                (osTaskFuncRefType)&OsTask_Cdd_EventPeriodic_1func
#define osStackStartAddressTask_25           (osStackPtrType)osdOsTask_Cdd_EventPeriodic_1_TOP
#define osStackSizeTask_25                   sizeof(osTaskStackOsApplication25)
#define osPrioTask_25                        7
#define osMaxActivationCount_25              1
#define osRunningModeTask_25                 OS_Privilegemode
#define osCategoryTask_25                    TASK_NONPREEMPTIVE
#define osTypeTask_25                        TASK_EXTENDED


/********************* Task 26*********************/

#define osStartAddressTask_26                (osTaskFuncRefType)&OsTask_SWCEventPeriodic_9func
#define osStackStartAddressTask_26           (osStackPtrType)osdOsTask_SWCEventPeriodic_9_TOP
#define osStackSizeTask_26                   sizeof(osTaskStackOsApplication26)
#define osPrioTask_26                        15
#define osMaxActivationCount_26              1
#define osRunningModeTask_26                 OS_Privilegemode
#define osCategoryTask_26                    TASK_NONPREEMPTIVE
#define osTypeTask_26                        TASK_EXTENDED


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
#define osTaskIdOfAlarm_1                 OsTask_Bsw_EventPeriodic_0
#define osActionOfAlarm_1                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_1                Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_0_0_10ms
/********************** Alarm 2 ***********************/
#define osCbkOfAlarm_2                    NULL
#define osTaskIdOfAlarm_2                 OsTask_Bsw_EventPeriodic_0
#define osActionOfAlarm_2                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_2                Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_0_2_10ms
/********************** Alarm 3 ***********************/
#define osCbkOfAlarm_3                    NULL
#define osTaskIdOfAlarm_3                 OsTask_Bsw_EventPeriodic_1
#define osActionOfAlarm_3                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                Rte_Ev_Cyclic2_OsTask_Bsw_EventPeriodic_1_0_20ms
/********************** Alarm 4 ***********************/
#define osCbkOfAlarm_4                    NULL
#define osTaskIdOfAlarm_4                 OsTask_SWCEventPeriodic_0
#define osActionOfAlarm_4                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_4                Rte_Ev_Run_AASample1Mdl_AASample1Mdl_Impl_MainFunction
/********************** Alarm 5 ***********************/
#define osCbkOfAlarm_5                    NULL
#define osTaskIdOfAlarm_5                 OsTask_SWCEventPeriodic_1
#define osActionOfAlarm_5                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_5                Rte_Ev_Run_CAASampleMdl_CAASampleMdl_Impl_MainFunction
/********************** Alarm 6 ***********************/
#define osCbkOfAlarm_6                    NULL
#define osTaskIdOfAlarm_6                 OsTask_SWCEventPeriodic_11
#define osActionOfAlarm_6                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_6                Rte_Ev_Run_CComAbsMdl_CComAbsMdl_Impl_RxCanMdlMainFunction
/********************** Alarm 7 ***********************/
#define osCbkOfAlarm_7                    NULL
#define osTaskIdOfAlarm_7                 OsTask_SWCEventPeriodic_11
#define osActionOfAlarm_7                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_7                Rte_Ev_Run_CComAbsMdl_CComAbsMdl_Impl_TxCanMdlMainFunction
/********************** Alarm 8 ***********************/
#define osCbkOfAlarm_8                    NULL
#define osTaskIdOfAlarm_8                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_8                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_8                Rte_Ev_Run_CSndCdd_CSndCdd_Impl_MainFunction
/********************** Alarm 9 ***********************/
#define osCbkOfAlarm_9                    NULL
#define osTaskIdOfAlarm_9                 OsTask_Bsw_EventPeriodic_1
#define osActionOfAlarm_9                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_9                Rte_Ev_Run_CanTp_CanTp_MainFunction
/********************** Alarm 10 ***********************/
#define osCbkOfAlarm_10                    NULL
#define osTaskIdOfAlarm_10                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_10                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_10                Rte_Ev_Run_CddOsph_CddOsph_MainFunction
/********************** Alarm 11 ***********************/
#define osCbkOfAlarm_11                    NULL
#define osTaskIdOfAlarm_11                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_11                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_11                Rte_Ev_Run_CddOsph_ParsedCdd_CmpMain
/********************** Alarm 12 ***********************/
#define osCbkOfAlarm_12                    NULL
#define osTaskIdOfAlarm_12                 OsTask_SWCEventPeriodic_4
#define osActionOfAlarm_12                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_12                Rte_Ev_Run_Chimes_Chimes_CmpMain
/********************** Alarm 13 ***********************/
#define osCbkOfAlarm_13                    NULL
#define osTaskIdOfAlarm_13                 OsTask_Bsw_EventPeriodic_1
#define osActionOfAlarm_13                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_13                Rte_Ev_Run_Com_Com_MainFunctionRx
/********************** Alarm 14 ***********************/
#define osCbkOfAlarm_14                    NULL
#define osTaskIdOfAlarm_14                 OsTask_SWCEventPeriodic_3
#define osActionOfAlarm_14                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_14                Rte_Ev_Run_Compass_Compass_CmpMain
/********************** Alarm 15 ***********************/
#define osCbkOfAlarm_15                    NULL
#define osTaskIdOfAlarm_15                 OsTask_SWCEventPeriodic_2
#define osActionOfAlarm_15                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_15                Rte_Ev_Run_Configuration_Configuration_CmpMain
/********************** Alarm 16 ***********************/
#define osCbkOfAlarm_16                    NULL
#define osTaskIdOfAlarm_16                 OsTask_SWCEventPeriodic_3
#define osActionOfAlarm_16                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_16                Rte_Ev_Run_ControlMirror_ControlMirror_CmpMain
/********************** Alarm 17 ***********************/
#define osCbkOfAlarm_17                    NULL
#define osTaskIdOfAlarm_17                 OsTask_SWCEventPeriodic_6
#define osActionOfAlarm_17                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_17                Rte_Ev_Run_Diagnostics_Diagnostics_CmpMain
/********************** Alarm 18 ***********************/
#define osCbkOfAlarm_18                    NULL
#define osTaskIdOfAlarm_18                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_18                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_18                Rte_Ev_Run_DmnMgr_DmnMgr_CmpMain
/********************** Alarm 19 ***********************/
#define osCbkOfAlarm_19                    NULL
#define osTaskIdOfAlarm_19                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_19                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_19                Rte_Ev_Run_Eprndl_Eprndl_CmpMain
/********************** Alarm 20 ***********************/
#define osCbkOfAlarm_20                    NULL
#define osTaskIdOfAlarm_20                 OsTask_SWCEventPeriodic_8
#define osActionOfAlarm_20                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_20                Rte_Ev_Run_Etm_Etm_CmpMain
/********************** Alarm 21 ***********************/
#define osCbkOfAlarm_21                    NULL
#define osTaskIdOfAlarm_21                 OsTask_SWCEventPeriodic_9
#define osActionOfAlarm_21                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_21                Rte_Ev_Run_Gauges_Gauges_CmpMain
/********************** Alarm 22 ***********************/
#define osCbkOfAlarm_22                    NULL
#define osTaskIdOfAlarm_22                 OsTask_SWCEventPeriodic_2
#define osActionOfAlarm_22                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_22                Rte_Ev_Run_HealthLog_HealthLog_HL_CmpMain
/********************** Alarm 23 ***********************/
#define osCbkOfAlarm_23                    NULL
#define osTaskIdOfAlarm_23                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_23                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_23                Rte_Ev_Run_Illumination_Illumination_CmpMain
/********************** Alarm 24 ***********************/
#define osCbkOfAlarm_24                    NULL
#define osTaskIdOfAlarm_24                 OsTask_SWCEventPeriodic_9
#define osActionOfAlarm_24                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_24                Rte_Ev_Run_Infotainment_Infotainment_CmpMain
/********************** Alarm 25 ***********************/
#define osCbkOfAlarm_25                    NULL
#define osTaskIdOfAlarm_25                 OsTask_SafeBsw_1
#define osActionOfAlarm_25                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_25                Rte_Ev_Run_IoHwAb_IoHwAb_MainFunction
/********************** Alarm 26 ***********************/
#define osCbkOfAlarm_26                    NULL
#define osTaskIdOfAlarm_26                 OsTask_Cdd_EventPeriodic_1
#define osActionOfAlarm_26                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_26                Rte_Ev_Run_McuExt_McuExt_ClockMon_CyclicCheck
/********************** Alarm 27 ***********************/
#define osCbkOfAlarm_27                    NULL
#define osTaskIdOfAlarm_27                 OsTask_SWCEventPeriodic_13
#define osActionOfAlarm_27                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_27                Rte_Ev_Run_MemAbstractMdl_CMemAbstractMdl_Impl_MainFunction
/********************** Alarm 28 ***********************/
#define osCbkOfAlarm_28                    NULL
#define osTaskIdOfAlarm_28                 OsTask_SWCEventPeriodic_4
#define osActionOfAlarm_28                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_28                Rte_Ev_Run_MemAbstractStub_MemAbstractStub_ImplMainFunction
/********************** Alarm 29 ***********************/
#define osCbkOfAlarm_29                    NULL
#define osTaskIdOfAlarm_29                 OsTask_SWCEventPeriodic_7
#define osActionOfAlarm_29                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_29                Rte_Ev_Run_ModeMgr_ModeMgr_Mainfunction
/********************** Alarm 30 ***********************/
#define osCbkOfAlarm_30                    NULL
#define osTaskIdOfAlarm_30                 OsTask_NvmSpeedup
#define osActionOfAlarm_30                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_30                Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable
/********************** Alarm 31 ***********************/
#define osCbkOfAlarm_31                    NULL
#define osTaskIdOfAlarm_31                 OsTask_SWCEventPeriodic_4
#define osActionOfAlarm_31                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_31                Rte_Ev_Run_Oat_Oat_CmpMain
/********************** Alarm 32 ***********************/
#define osCbkOfAlarm_32                    NULL
#define osTaskIdOfAlarm_32                 OsTask_SWCEventPeriodic_10
#define osActionOfAlarm_32                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_32                Rte_Ev_Run_Odometer_Odometer_CmpMain
/********************** Alarm 33 ***********************/
#define osCbkOfAlarm_33                    NULL
#define osTaskIdOfAlarm_33                 OsTask_BswCtrl_EventPeriodic
#define osActionOfAlarm_33                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_33                Rte_Ev_Cyclic_OsTask_BswCtrl_EventPeriodic_0_10ms
/********************** Alarm 34 ***********************/
#define osCbkOfAlarm_34                    NULL
#define osTaskIdOfAlarm_34                 OsTask_Bsw_EventPeriodic_0
#define osActionOfAlarm_34                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_34                Rte_Ev_Cyclic_OsTask_Bsw_EventPeriodic_0_0_10ms
/********************** Alarm 35 ***********************/
#define osCbkOfAlarm_35                    NULL
#define osTaskIdOfAlarm_35                 OsTask_Bsw_EventPeriodic_0
#define osActionOfAlarm_35                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_35                Rte_Ev_Cyclic_OsTask_Bsw_EventPeriodic_0_6_10ms
/********************** Alarm 36 ***********************/
#define osCbkOfAlarm_36                    NULL
#define osTaskIdOfAlarm_36                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_36                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_36                Rte_Ev_Cyclic_OsTask_Cdd_EventPeriodic_0_0_10ms
/********************** Alarm 37 ***********************/
#define osCbkOfAlarm_37                    NULL
#define osTaskIdOfAlarm_37                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_37                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_37                Rte_Ev_Cyclic_OsTask_Cdd_EventPeriodic_0_2_10ms
/********************** Alarm 38 ***********************/
#define osCbkOfAlarm_38                    NULL
#define osTaskIdOfAlarm_38                 OsTask_SWCEventPeriodic_13
#define osActionOfAlarm_38                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_38                Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_13_0_10ms
/********************** Alarm 39 ***********************/
#define osCbkOfAlarm_39                    NULL
#define osTaskIdOfAlarm_39                 OsTask_SWCEventPeriodic_4
#define osActionOfAlarm_39                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_39                Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_4_4_30ms
/********************** Alarm 40 ***********************/
#define osCbkOfAlarm_40                    NULL
#define osTaskIdOfAlarm_40                 OsTask_SWCEventPeriodic_5
#define osActionOfAlarm_40                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_40                Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_5_0_10ms
/********************** Alarm 41 ***********************/
#define osCbkOfAlarm_41                    NULL
#define osTaskIdOfAlarm_41                 OsTask_SWCEventPeriodic_6
#define osActionOfAlarm_41                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_41                Rte_Ev_Cyclic_OsTask_SWCEventPeriodic_6_0_100ms
/********************** Alarm 42 ***********************/
#define osCbkOfAlarm_42                    NULL
#define osTaskIdOfAlarm_42                 OsTask_SafeBsw_0
#define osActionOfAlarm_42                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_42                Rte_Ev_Cyclic_OsTask_SafeBsw_0_0_100ms
/********************** Alarm 43 ***********************/
#define osCbkOfAlarm_43                    NULL
#define osTaskIdOfAlarm_43                 OsTask_SafeBsw_0
#define osActionOfAlarm_43                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_43                Rte_Ev_Cyclic_OsTask_SafeBsw_0_0_10ms
/********************** Alarm 44 ***********************/
#define osCbkOfAlarm_44                    NULL
#define osTaskIdOfAlarm_44                 OsTask_SafeBsw_1
#define osActionOfAlarm_44                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_44                Rte_Ev_Cyclic_OsTask_SafeBsw_1_0_10ms
/********************** Alarm 45 ***********************/
#define osCbkOfAlarm_45                    NULL
#define osTaskIdOfAlarm_45                 OsTask_SafeBsw_1
#define osActionOfAlarm_45                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_45                Rte_Ev_Cyclic_OsTask_SafeBsw_1_0_20ms
/********************** Alarm 46 ***********************/
#define osCbkOfAlarm_46                    NULL
#define osTaskIdOfAlarm_46                 OsTask_SWCEventPeriodic_0
#define osActionOfAlarm_46                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_46                Rte_Ev_Run_Personalization_Personalization_CmpMain
/********************** Alarm 47 ***********************/
#define osCbkOfAlarm_47                    NULL
#define osTaskIdOfAlarm_47                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_47                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_47                Rte_Ev_Run_PowerCdd_PowerCdd_StateTransistionProcess
/********************** Alarm 48 ***********************/
#define osCbkOfAlarm_48                    NULL
#define osTaskIdOfAlarm_48                 OsTask_SWCEventPeriodic_12
#define osActionOfAlarm_48                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_48                Rte_Ev_Run_Power_Power_CmpMain
/********************** Alarm 49 ***********************/
#define osCbkOfAlarm_49                    NULL
#define osTaskIdOfAlarm_49                 OsTask_SWCEventPeriodic_2
#define osActionOfAlarm_49                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_49                Rte_Ev_Run_Rtt_Rtt_CmpMain
/********************** Alarm 50 ***********************/
#define osCbkOfAlarm_50                    NULL
#define osTaskIdOfAlarm_50                 OsTask_SWCEventPeriodic_13
#define osActionOfAlarm_50                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_50                Rte_Ev_Run_SDM_SDM_CmpMain
/********************** Alarm 51 ***********************/
#define osCbkOfAlarm_51                    NULL
#define osTaskIdOfAlarm_51                 OsTask_UclProxyEvent_0
#define osActionOfAlarm_51                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_51                Rte_Ev_Run_SWC_SWC_CmpMain
/********************** Alarm 52 ***********************/
#define osCbkOfAlarm_52                    NULL
#define osTaskIdOfAlarm_52                 OsTask_SWCEventPeriodic_2
#define osActionOfAlarm_52                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_52                Rte_Ev_Run_SndCtrl_SndCDD_CmpMain
/********************** Alarm 53 ***********************/
#define osCbkOfAlarm_53                    NULL
#define osTaskIdOfAlarm_53                 OsTask_SafeBsw_1
#define osActionOfAlarm_53                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_53                Rte_Ev_Run_SysTst_OsTask_SafeBsw_1_5ms_WdgCheckpoint
/********************** Alarm 54 ***********************/
#define osCbkOfAlarm_54                    NULL
#define osTaskIdOfAlarm_54                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_54                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_54                Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_10ms_WdgCheckpoint
/********************** Alarm 55 ***********************/
#define osCbkOfAlarm_55                    NULL
#define osTaskIdOfAlarm_55                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_55                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_55                Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_16ms_WdgCheckpoint
/********************** Alarm 56 ***********************/
#define osCbkOfAlarm_56                    NULL
#define osTaskIdOfAlarm_56                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_56                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_56                Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_20ms_WdgCheckpoint
/********************** Alarm 57 ***********************/
#define osCbkOfAlarm_57                    NULL
#define osTaskIdOfAlarm_57                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_57                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_57                Rte_Ev_Run_SysTst_OsTask_SafeSWCEventPeriodic_0_30ms_WdgCheckpoint
/********************** Alarm 58 ***********************/
#define osCbkOfAlarm_58                    NULL
#define osTaskIdOfAlarm_58                 OsTask_SafeSWCEventPeriodic_0
#define osActionOfAlarm_58                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_58                Rte_Ev_Run_Telltale_Telltale_CmpMain
/********************** Alarm 59 ***********************/
#define osCbkOfAlarm_59                    NULL
#define osTaskIdOfAlarm_59                 OsTask_UclProxyEvent_0
#define osActionOfAlarm_59                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_59                Rte_Ev_Run_TripComputer_TripComputer_CmpMain
/********************** Alarm 60 ***********************/
#define osCbkOfAlarm_60                    NULL
#define osTaskIdOfAlarm_60                 OsTask_Cdd_EventPeriodic_1
#define osActionOfAlarm_60                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_60                Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction
/********************** Alarm 61 ***********************/
#define osCbkOfAlarm_61                    NULL
#define osTaskIdOfAlarm_61                 OsTask_SWCEventPeriodic_1
#define osActionOfAlarm_61                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_61                Rte_Ev_Run_Warnings_Warnings_CmpMain
/********************** Alarm 62 ***********************/
#define osCbkOfAlarm_62                    NULL
#define osTaskIdOfAlarm_62                 OsTask_SWCEventPeriodic_13
#define osActionOfAlarm_62                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_62                Rte_Ev_Run_Welcome_Welcome_CmpMain
/********************** Alarm 63 ***********************/
#define osCbkOfAlarm_63                    NULL
#define osTaskIdOfAlarm_63                 OsTask_Cdd_EventPeriodic_0
#define osActionOfAlarm_63                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_63                Rte_Ev_Run_vSwUpdM_vSwUpdM_MainFunction


/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/


#define osStackStartAddressIsr_0           (osStackPtrType)osdSystemTimerISR_TOP
#define osStackSizeIsr_0                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_1           (osStackPtrType)osdCan_ISR_B_TOP
#define osStackSizeIsr_1                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_2           (osStackPtrType)osdADC0_ISR_TOP
#define osStackSizeIsr_2                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_3           (osStackPtrType)osdGPT_2_TOP
#define osStackSizeIsr_3                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_4           (osStackPtrType)osdGPT_3_TOP
#define osStackSizeIsr_4                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_5           (osStackPtrType)osdSPI0_TOP
#define osStackSizeIsr_5                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_6           (osStackPtrType)osdSPI2_TOP
#define osStackSizeIsr_6                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_7           (osStackPtrType)osdGPT_LPIT_TOP
#define osStackSizeIsr_7                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_8           (osStackPtrType)osdGPT_4_TOP
#define osStackSizeIsr_8                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_9           (osStackPtrType)osdGPIO0_INT_TOP
#define osStackSizeIsr_9                   (osStackDataType)sizeof(osLevelStackCore0Level1)



/*****************************************************************************
*                               Isr Configs                                  *
******************************************************************************/
/********************** Isr 0***********************/
#define osIsrId_SystemTimerISR 0UL
#define osIsrPrioLevel_SystemTimerISR 128UL
#define osIsrServiceRoutine_SystemTimerISR osTimerInterruptfunc

/********************** Isr 1***********************/
#define osIsrId_Can_ISR_B 1UL
#define osIsrPrioLevel_Can_ISR_B 128UL
#define osIsrServiceRoutine_Can_ISR_B CanIsr_1func

/********************** Isr 2***********************/
#define osIsrId_ADC0_ISR 2UL
#define osIsrPrioLevel_ADC0_ISR 128UL
#define osIsrServiceRoutine_ADC0_ISR ADC_SARADC_ISR_UNIT0

/********************** Isr 3***********************/
#define osIsrId_GPT_2 3UL
#define osIsrPrioLevel_GPT_2 128UL
#define osIsrServiceRoutine_GPT_2 GPT_2_ISR

/********************** Isr 4***********************/
#define osIsrId_GPT_3 4UL
#define osIsrPrioLevel_GPT_3 128UL
#define osIsrServiceRoutine_GPT_3 GPT_3_ISR

/********************** Isr 5***********************/
#define osIsrId_SPI0 5UL
#define osIsrPrioLevel_SPI0 128UL
#define osIsrServiceRoutine_SPI0 Spi_LPspi_IsrTDF_LPSPI_0

/********************** Isr 6***********************/
#define osIsrId_SPI2 6UL
#define osIsrPrioLevel_SPI2 128UL
#define osIsrServiceRoutine_SPI2 Spi_LPspi_IsrTDF_LPSPI_2

/********************** Isr 7***********************/
#define osIsrId_GPT_LPIT 7UL
#define osIsrPrioLevel_GPT_LPIT 128UL
#define osIsrServiceRoutine_GPT_LPIT LPIT_0_ISRfunc

/********************** Isr 8***********************/
#define osIsrId_GPT_4 8UL
#define osIsrPrioLevel_GPT_4 128UL
#define osIsrServiceRoutine_GPT_4 GPT_4_ISR

/********************** Isr 9***********************/
#define osIsrId_GPIO0_INT 9UL
#define osIsrPrioLevel_GPIO0_INT 128UL
#define osIsrServiceRoutine_GPIO0_INT ICU_GPIO_0_ISR



/* Task function prototypes */

void InitTaskfunc(void);
void OsTask_IdleTaskfunc(void);
void OsTask_BswCtrl_EventPeriodicfunc(void);
void OsTask_Bsw_EventPeriodic_0func(void);
void OsTask_Bsw_EventPeriodic_1func(void);
void OsTask_NvmSpeedupfunc(void);
void OsTask_SWCEventPeriodic_0func(void);
void OsTask_SWCEventPeriodic_1func(void);
void OsTask_SWCEventPeriodic_2func(void);
void OsTask_SWCEventPeriodic_3func(void);
void OsTask_SWCEventPeriodic_4func(void);
void OsTask_SWCEventPeriodic_5func(void);
void OsTask_SWCEventPeriodic_6func(void);
void OsTask_SWCEventPeriodic_7func(void);
void OsTask_SWCEventPeriodic_8func(void);
void OsTask_SWCEventPeriodic_10func(void);
void OsTask_SWCEventPeriodic_11func(void);
void OsTask_SWCEventPeriodic_12func(void);
void OsTask_SWCEventPeriodic_13func(void);
void OsTask_SafeSWCEventPeriodic_0func(void);
void OsTask_SafeBsw_0func(void);
void OsTask_SafeBsw_1func(void);
void OsTask_UclProxyEvent_0func(void);
void OsTask_UclProxyEvent_1func(void);
void OsTask_Cdd_EventPeriodic_0func(void);
void OsTask_Cdd_EventPeriodic_1func(void);
void OsTask_SWCEventPeriodic_9func(void);
/* Alarm Callback function prototypes */

extern const OsAppConfigType OsAppConfig[OsNumberOfApplications];
extern const OsAppConfigRefType OsCore0ApplicationRef[OsNumberOfApplicationsCore0];
extern const OsCoreConfigType OsCoreConfig[OsNumberOfCores];
extern const OsObjConfigType  OsObjConfig[OsMaxNumOfObjectId];
extern const OsObjConfigRefType OsApplication_TrustedSystemObjConfigRef[];
extern const OsObjConfigRefType OsApplication_QMObjConfigRef[];
#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
extern const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns];
#endif
extern const OsMPUAccessGroupConfigType OsMPUAccessGroupConfig[OsMaxAccessGroupIds];
extern const OsMpuAccessGroupDiffType OsMpuAccessGroupDiff[OsMaxAccessGroupIds][OsMaxAccessGroupIds];
extern const OsIntMpuConfigType OsMpu_TrustedSystem[OsNumberOfMPURegions_0];

extern const OsIntMpuConfigType OsMpu_QMSystem[OsNumberOfMPURegions_0];

extern OsprioQueueType OsPriorityQueueDyn[OsMaxPriorityLevel];
extern const OsResConfigType OsResConfig[OsNumberOfRes];
extern const TaskPriorityType OsMaxPrioQueueCount[OsMaxPriorityLevel];

extern OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplicationsCore0];



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
Created Time: 12/6/2023 9:54:58 PM
****************************************************************/
