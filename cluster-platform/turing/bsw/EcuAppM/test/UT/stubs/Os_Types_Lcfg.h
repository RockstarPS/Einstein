/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR Renault SLP6 (MSR_Renault_SLP6)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: S6J332EJB
 *    License Scope : The usage is restricted to CBD1700714_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_TYPES_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! OS-Application identifier. */
#define OsApplication OsApplication
#define SystemApplication_OsCore_Core0 SystemApplication_OsCore_Core0

/*! Trusted function identifier. */

/*! Non-Trusted function identifier. */

/*! Fast Trusted function identifier. */

/*! Task identifier. */
#define AppTask_10msLP AppTask_10msLP
#define IdleTask_OsCore_Core0 IdleTask_OsCore_Core0
#define OsTask_100ms OsTask_100ms
#define OsTask_10msCAN OsTask_10msCAN
#define OsTask_10msEcuM OsTask_10msEcuM
#define OsTask_10ms_Wdg OsTask_10ms_Wdg
#define OsTask_2ms OsTask_2ms
#define OsTask_30ms OsTask_30ms
#define OsTask_30msSnd OsTask_30msSnd
#define OsTask_4ms_Ipcl OsTask_4ms_Ipcl
#define OsTask_NvM_Stack OsTask_NvM_Stack
#define OsTask_RteEvent OsTask_RteEvent
#define OsTask_StackMesure OsTask_StackMesure
#define StartupTwo StartupTwo

/*! Category 2 ISR identifier. */
#define Bswc_App_Intrpt Bswc_App_Intrpt
#define CanIsr_0 CanIsr_0
#define CanIsr_5 CanIsr_5
#define OsIsr_60MHzFRT OsIsr_60MHzFRT
#define OsIsr_ADC_B0_ConversionDone OsIsr_ADC_B0_ConversionDone
#define OsIsr_ADC_B1_ConversionDone OsIsr_ADC_B1_ConversionDone
#define OsIsr_DMA_Ch0 OsIsr_DMA_Ch0
#define OsIsr_DMA_Ch12 OsIsr_DMA_Ch12
#define OsIsr_DMA_Ch13 OsIsr_DMA_Ch13
#define OsIsr_DMA_Ch14 OsIsr_DMA_Ch14
#define OsIsr_DMA_Ch15 OsIsr_DMA_Ch15
#define OsIsr_DMA_Error OsIsr_DMA_Error
#define OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error
#define OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error
#define OsIsr_ECC_SRAM_1_Bit_Error OsIsr_ECC_SRAM_1_Bit_Error
#define OsIsr_Ext_Int_0 OsIsr_Ext_Int_0
#define OsIsr_Ext_Int_6 OsIsr_Ext_Int_6
#define OsIsr_FAN_SPD OsIsr_FAN_SPD
#define OsIsr_MFS_Error_Ch9 OsIsr_MFS_Error_Ch9
#define OsIsr_MFS_Receive_Ch9 OsIsr_MFS_Receive_Ch9
#define OsIsr_MFS_Transmit_Ch9 OsIsr_MFS_Transmit_Ch9
#define OsIsr_RLT01_1us_1shot_delay OsIsr_RLT01_1us_1shot_delay
#define OsIsr_RTC OsIsr_RTC
#define OsIsr_SystemTimer OsIsr_SystemTimer
#define OsIsr_TmExt OsIsr_TmExt
#define OsIsr_Wdg_TO OsIsr_Wdg_TO
#define OsIsr_Wdg_Trg OsIsr_Wdg_Trg

/*! Alarm identifier. */
#define Rte_Al_TE2_OsTask_100ms_0_1s Rte_Al_TE2_OsTask_100ms_0_1s
#define Rte_Al_TE2_OsTask_10msCAN_0_10ms Rte_Al_TE2_OsTask_10msCAN_0_10ms
#define Rte_Al_TE2_OsTask_10msCAN_0_20ms Rte_Al_TE2_OsTask_10msCAN_0_20ms
#define Rte_Al_TE2_OsTask_10msEcuM_0_10ms Rte_Al_TE2_OsTask_10msEcuM_0_10ms
#define Rte_Al_TE2_OsTask_10ms_Wdg_0_10ms Rte_Al_TE2_OsTask_10ms_Wdg_0_10ms
#define Rte_Al_TE2_OsTask_NvM_Stack_0_10ms Rte_Al_TE2_OsTask_NvM_Stack_0_10ms
#define Rte_Al_TE_AppTask_10msLP_0_10ms Rte_Al_TE_AppTask_10msLP_0_10ms
#define Rte_Al_TE_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp Rte_Al_TE_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp
#define Rte_Al_TE_IoCtrl_IoCtrl_StackMeasure Rte_Al_TE_IoCtrl_IoCtrl_StackMeasure
#define Rte_Al_TE_IoHwAb_IoHwAb_MainFunction Rte_Al_TE_IoHwAb_IoHwAb_MainFunction
#define Rte_Al_TE_IpclCdd_CIpclCdd_Impl_MainFunction Rte_Al_TE_IpclCdd_CIpclCdd_Impl_MainFunction
#define Rte_Al_TE_Ipcl_CIpclCdd_Impl_MainFunction Rte_Al_TE_Ipcl_CIpclCdd_Impl_MainFunction
#define Rte_Al_TE_OsTask_10msEcuM_0_10ms Rte_Al_TE_OsTask_10msEcuM_0_10ms
#define Rte_Al_TE_RtcCdd_CRtcCdd_Impl_MainFunction Rte_Al_TE_RtcCdd_CRtcCdd_Impl_MainFunction
#define Rte_Al_TE_SndCdd_CSndCdd_Impl_MainFunction Rte_Al_TE_SndCdd_CSndCdd_Impl_MainFunction
#define Rte_Al_TE_SndCdd_CSndCdd_ToneProcess Rte_Al_TE_SndCdd_CSndCdd_ToneProcess

/*! Counter identifier. */
#define SystemTimer SystemTimer

/*! ScheduleTable identifier. */
#define OsScheduleTable_60 OsScheduleTable_60

/*! Resource identifier. */
#define OsResource OsResource

/*! Spinlock identifier. */

/*! Peripheral identifier. */

/*! Trace thread identifier (Tasks and ISRs inclusive system objects). */
#define Os_TraceId_AppTask_10msLP Os_TraceId_AppTask_10msLP
#define Os_TraceId_IdleTask_OsCore_Core0 Os_TraceId_IdleTask_OsCore_Core0
#define Os_TraceId_OsTask_100ms Os_TraceId_OsTask_100ms
#define Os_TraceId_OsTask_10msCAN Os_TraceId_OsTask_10msCAN
#define Os_TraceId_OsTask_10msEcuM Os_TraceId_OsTask_10msEcuM
#define Os_TraceId_OsTask_10ms_Wdg Os_TraceId_OsTask_10ms_Wdg
#define Os_TraceId_OsTask_2ms Os_TraceId_OsTask_2ms
#define Os_TraceId_OsTask_30ms Os_TraceId_OsTask_30ms
#define Os_TraceId_OsTask_30msSnd Os_TraceId_OsTask_30msSnd
#define Os_TraceId_OsTask_4ms_Ipcl Os_TraceId_OsTask_4ms_Ipcl
#define Os_TraceId_OsTask_NvM_Stack Os_TraceId_OsTask_NvM_Stack
#define Os_TraceId_OsTask_RteEvent Os_TraceId_OsTask_RteEvent
#define Os_TraceId_OsTask_StackMesure Os_TraceId_OsTask_StackMesure
#define Os_TraceId_StartupTwo Os_TraceId_StartupTwo
#define Os_TraceId_Bswc_App_Intrpt Os_TraceId_Bswc_App_Intrpt
#define Os_TraceId_CanIsr_0 Os_TraceId_CanIsr_0
#define Os_TraceId_CanIsr_5 Os_TraceId_CanIsr_5
#define Os_TraceId_OsIsr_60MHzFRT Os_TraceId_OsIsr_60MHzFRT
#define Os_TraceId_OsIsr_ADC_B0_ConversionDone Os_TraceId_OsIsr_ADC_B0_ConversionDone
#define Os_TraceId_OsIsr_ADC_B1_ConversionDone Os_TraceId_OsIsr_ADC_B1_ConversionDone
#define Os_TraceId_OsIsr_DMA_Ch0 Os_TraceId_OsIsr_DMA_Ch0
#define Os_TraceId_OsIsr_DMA_Ch12 Os_TraceId_OsIsr_DMA_Ch12
#define Os_TraceId_OsIsr_DMA_Ch13 Os_TraceId_OsIsr_DMA_Ch13
#define Os_TraceId_OsIsr_DMA_Ch14 Os_TraceId_OsIsr_DMA_Ch14
#define Os_TraceId_OsIsr_DMA_Ch15 Os_TraceId_OsIsr_DMA_Ch15
#define Os_TraceId_OsIsr_DMA_Error Os_TraceId_OsIsr_DMA_Error
#define Os_TraceId_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error Os_TraceId_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error
#define Os_TraceId_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error Os_TraceId_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error
#define Os_TraceId_OsIsr_ECC_SRAM_1_Bit_Error Os_TraceId_OsIsr_ECC_SRAM_1_Bit_Error
#define Os_TraceId_OsIsr_Ext_Int_0 Os_TraceId_OsIsr_Ext_Int_0
#define Os_TraceId_OsIsr_Ext_Int_6 Os_TraceId_OsIsr_Ext_Int_6
#define Os_TraceId_OsIsr_FAN_SPD Os_TraceId_OsIsr_FAN_SPD
#define Os_TraceId_OsIsr_MFS_Error_Ch9 Os_TraceId_OsIsr_MFS_Error_Ch9
#define Os_TraceId_OsIsr_MFS_Receive_Ch9 Os_TraceId_OsIsr_MFS_Receive_Ch9
#define Os_TraceId_OsIsr_MFS_Transmit_Ch9 Os_TraceId_OsIsr_MFS_Transmit_Ch9
#define Os_TraceId_OsIsr_RLT01_1us_1shot_delay Os_TraceId_OsIsr_RLT01_1us_1shot_delay
#define Os_TraceId_OsIsr_RTC Os_TraceId_OsIsr_RTC
#define Os_TraceId_OsIsr_SystemTimer Os_TraceId_OsIsr_SystemTimer
#define Os_TraceId_OsIsr_TmExt Os_TraceId_OsIsr_TmExt
#define Os_TraceId_OsIsr_Wdg_TO Os_TraceId_OsIsr_Wdg_TO
#define Os_TraceId_OsIsr_Wdg_Trg Os_TraceId_OsIsr_Wdg_Trg

/*! Trace spinlock identifier (All spinlocks inclusive system objects). */

/*! Barrier identifiers. */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Application identifier. */
typedef enum
{
  OsApplication = 0, /* 0x00000001 */
  SystemApplication_OsCore_Core0 = 1, /* 0x00000002 */
  OS_APPID_COUNT = 2,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifier. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-Trusted function identifier. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast Trusted function identifier. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifier. */
typedef enum
{
  AppTask_10msLP = 0,
  IdleTask_OsCore_Core0 = 1,
  OsTask_100ms = 2,
  OsTask_10msCAN = 3,
  OsTask_10msEcuM = 4,
  OsTask_10ms_Wdg = 5,
  OsTask_2ms = 6,
  OsTask_30ms = 7,
  OsTask_30msSnd = 8,
  OsTask_4ms_Ipcl = 9,
  OsTask_NvM_Stack = 10,
  OsTask_RteEvent = 11,
  OsTask_StackMesure = 12,
  StartupTwo = 13,
  OS_TASKID_COUNT = 14,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifier. */
typedef enum
{
  Bswc_App_Intrpt = 0,
  CanIsr_0 = 1,
  CanIsr_5 = 2,
  OsIsr_60MHzFRT = 3,
  OsIsr_ADC_B0_ConversionDone = 4,
  OsIsr_ADC_B1_ConversionDone = 5,
  OsIsr_DMA_Ch0 = 6,
  OsIsr_DMA_Ch12 = 7,
  OsIsr_DMA_Ch13 = 8,
  OsIsr_DMA_Ch14 = 9,
  OsIsr_DMA_Ch15 = 10,
  OsIsr_DMA_Error = 11,
  OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error = 12,
  OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error = 13,
  OsIsr_ECC_SRAM_1_Bit_Error = 14,
  OsIsr_Ext_Int_0 = 15,
  OsIsr_Ext_Int_6 = 16,
  OsIsr_FAN_SPD = 17,
  OsIsr_MFS_Error_Ch9 = 18,
  OsIsr_MFS_Receive_Ch9 = 19,
  OsIsr_MFS_Transmit_Ch9 = 20,
  OsIsr_RLT01_1us_1shot_delay = 21,
  OsIsr_RTC = 22,
  OsIsr_SystemTimer = 23,
  OsIsr_TmExt = 24,
  OsIsr_Wdg_TO = 25,
  OsIsr_Wdg_Trg = 26,
  OS_ISRID_COUNT = 27,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifier. */
typedef enum
{
  Rte_Al_TE2_OsTask_100ms_0_1s = 0,
  Rte_Al_TE2_OsTask_10msCAN_0_10ms = 1,
  Rte_Al_TE2_OsTask_10msCAN_0_20ms = 2,
  Rte_Al_TE2_OsTask_10msEcuM_0_10ms = 3,
  Rte_Al_TE2_OsTask_10ms_Wdg_0_10ms = 4,
  Rte_Al_TE2_OsTask_NvM_Stack_0_10ms = 5,
  Rte_Al_TE_AppTask_10msLP_0_10ms = 6,
  Rte_Al_TE_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp = 7,
  Rte_Al_TE_IoCtrl_IoCtrl_StackMeasure = 8,
  Rte_Al_TE_IoHwAb_IoHwAb_MainFunction = 9,
  Rte_Al_TE_IpclCdd_CIpclCdd_Impl_MainFunction = 10,
  Rte_Al_TE_Ipcl_CIpclCdd_Impl_MainFunction = 11,
  Rte_Al_TE_OsTask_10msEcuM_0_10ms = 12,
  Rte_Al_TE_RtcCdd_CRtcCdd_Impl_MainFunction = 13,
  Rte_Al_TE_SndCdd_CSndCdd_Impl_MainFunction = 14,
  Rte_Al_TE_SndCdd_CSndCdd_ToneProcess = 15,
  OS_ALARMID_COUNT = 16
} AlarmType;

/*! Counter identifier. */
typedef enum
{
  SystemTimer = 0,
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifier. */
typedef enum
{
  OsScheduleTable_60 = 0,
  OS_SCHTID_COUNT = 1
} ScheduleTableType;

/*! Resource identifier. */
typedef enum
{
  OsResource = 0,
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifier. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifier. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Trace thread identifier (Tasks and ISRs inclusive system objects). */
typedef enum
{
  Os_TraceId_AppTask_10msLP = 0,
  Os_TraceId_IdleTask_OsCore_Core0 = 1,
  Os_TraceId_OsTask_100ms = 2,
  Os_TraceId_OsTask_10msCAN = 3,
  Os_TraceId_OsTask_10msEcuM = 4,
  Os_TraceId_OsTask_10ms_Wdg = 5,
  Os_TraceId_OsTask_2ms = 6,
  Os_TraceId_OsTask_30ms = 7,
  Os_TraceId_OsTask_30msSnd = 8,
  Os_TraceId_OsTask_4ms_Ipcl = 9,
  Os_TraceId_OsTask_NvM_Stack = 10,
  Os_TraceId_OsTask_RteEvent = 11,
  Os_TraceId_OsTask_StackMesure = 12,
  Os_TraceId_StartupTwo = 13,
  Os_TraceId_Bswc_App_Intrpt = 14,
  Os_TraceId_CanIsr_0 = 15,
  Os_TraceId_CanIsr_5 = 16,
  Os_TraceId_OsIsr_60MHzFRT = 17,
  Os_TraceId_OsIsr_ADC_B0_ConversionDone = 18,
  Os_TraceId_OsIsr_ADC_B1_ConversionDone = 19,
  Os_TraceId_OsIsr_DMA_Ch0 = 20,
  Os_TraceId_OsIsr_DMA_Ch12 = 21,
  Os_TraceId_OsIsr_DMA_Ch13 = 22,
  Os_TraceId_OsIsr_DMA_Ch14 = 23,
  Os_TraceId_OsIsr_DMA_Ch15 = 24,
  Os_TraceId_OsIsr_DMA_Error = 25,
  Os_TraceId_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error = 26,
  Os_TraceId_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error = 27,
  Os_TraceId_OsIsr_ECC_SRAM_1_Bit_Error = 28,
  Os_TraceId_OsIsr_Ext_Int_0 = 29,
  Os_TraceId_OsIsr_Ext_Int_6 = 30,
  Os_TraceId_OsIsr_FAN_SPD = 31,
  Os_TraceId_OsIsr_MFS_Error_Ch9 = 32,
  Os_TraceId_OsIsr_MFS_Receive_Ch9 = 33,
  Os_TraceId_OsIsr_MFS_Transmit_Ch9 = 34,
  Os_TraceId_OsIsr_RLT01_1us_1shot_delay = 35,
  Os_TraceId_OsIsr_RTC = 36,
  Os_TraceId_OsIsr_SystemTimer = 37,
  Os_TraceId_OsIsr_TmExt = 38,
  Os_TraceId_OsIsr_Wdg_TO = 39,
  Os_TraceId_OsIsr_Wdg_Trg = 40,
  OS_TRACE_THREADID_COUNT = 41,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifier (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
