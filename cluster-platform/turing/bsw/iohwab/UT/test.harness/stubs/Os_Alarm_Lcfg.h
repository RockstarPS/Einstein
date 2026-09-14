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
 *              File: Os_Alarm_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_ALARM_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Alarm configuration data: Rte_Al_TE2_OsTask_100ms_0_1s */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_100ms_0_1s;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_10msCAN_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_10msCAN_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_10msCAN_0_20ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_10msCAN_0_20ms;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_10msEcuM_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_10msEcuM_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_10ms_Wdg_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_10ms_Wdg_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_NvM_Stack_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_NvM_Stack_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_AppTask_10msLP_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_AppTask_10msLP_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp;

/*! Alarm configuration data: Rte_Al_TE_IoCtrl_IoCtrl_StackMeasure */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IoCtrl_IoCtrl_StackMeasure;

/*! Alarm configuration data: Rte_Al_TE_IoHwAb_IoHwAb_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IoHwAb_IoHwAb_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_IpclCdd_CIpclCdd_Impl_MainFunction */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IpclCdd_CIpclCdd_Impl_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_Ipcl_CIpclCdd_Impl_MainFunction */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Ipcl_CIpclCdd_Impl_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_OsTask_10msEcuM_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_10msEcuM_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_RtcCdd_CRtcCdd_Impl_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_RtcCdd_CRtcCdd_Impl_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_SndCdd_CSndCdd_Impl_MainFunction */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SndCdd_CSndCdd_Impl_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_SndCdd_CSndCdd_ToneProcess */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SndCdd_CSndCdd_ToneProcess;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
