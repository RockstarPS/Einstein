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
 *          File:  Os_Cfg.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define OsTask_BSW_COM_Periodic_2 (0U)
# define OsTask_BSW_EventPeriodic_0 (1U)
# define OsTask_BSW_Periodic_0 (2U)
# define OsTask_BSW_Periodic_1 (3U)
# define OsTask_CAN_Periodic_0 (4U)
# define OsTask_CDD_FitPeriodic_1 (5U)
# define OsTask_CDD_Periodic_0 (6U)
# define OsTask_COM_EventPeriodic_0 (7U)
# define OsTask_CanDataRx_0 (8U)
# define OsTask_LSH_16ms (9U)
# define OsTask_NvmSpeedup (10U)
# define OsTask_SafeBsw_0 (11U)

/* Alarms */
# define Rte_Al_TE_OsTask_BSW_COM_Periodic_2_6_10ms (0U)
# define Rte_Al_TE2_OsTask_BSW_EventPeriodic_0_0_10ms (1U)
# define Rte_Al_TE_CMeetCdd_CMeetCdd_Task (2U)
# define Rte_Al_TE_EcuMExt_EcuMExt_MainFunction (3U)
# define Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_100ms (4U)
# define Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_10ms (5U)
# define Rte_Al_TE2_OsTask_BSW_Periodic_0_1_10ms (6U)
# define Rte_Al_TE_OsTask_BSW_Periodic_1_3_10ms (7U)
# define Rte_Al_TE2_OsTask_CAN_Periodic_0_4_10ms (8U)
# define Rte_Al_TE_OsTask_CDD_FitPeriodic_1_0_20ms (9U)
# define Rte_Al_TE_OsTask_CDD_Periodic_0_5_10ms (10U)
# define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_10ms (11U)
# define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_20ms (12U)
# define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_5ms (13U)
# define Rte_Al_TE_OsTask_LSH_16ms_0_16ms (14U)
# define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable (15U)
# define Rte_Al_TE_OsTask_SafeBsw_0_10_10ms (16U)

/* Events */
# define Rte_Ev_Cyclic2_OsTask_BSW_EventPeriodic_0_0_10ms (0x04)
# define Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_10ms (0x01)
# define Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_20ms (0x04)
# define Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_5ms (0x02)
# define Rte_Ev_Cyclic_OsTask_BSW_COM_Periodic_2_6_10ms (0x01)
# define Rte_Ev_Cyclic_OsTask_BSW_EventPeriodic_0_0_100ms (0x40)
# define Rte_Ev_Cyclic_OsTask_BSW_EventPeriodic_0_0_10ms (0x01)
# define Rte_Ev_Cyclic_OsTask_CDD_FitPeriodic_1_0_20ms (0x01)
# define Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms (0x01)
# define Rte_Ev_Run_CComAbsMdl_CComAbsMdl_OnDataRx_VehicleStates (0x01)
# define Rte_Ev_Run_CMeetCdd_CMeetCdd_Task (0x08)
# define Rte_Ev_Run_EcuMExt_EcuMExt_MainFunction (0x20)
# define Rte_Ev_Run_GdtCdd_CGdtCdd_Impl_OnCommand (0x02)
# define Rte_Ev_Run_GdtCtrl_CGdtCtrl_Impl_OnCommand (0x08)
# define Rte_Ev_Run_GdtCtrl_GdtCtrl_RenderDone (0x04)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable (0x10)
# define Rte_Ev_WP_OsTask_BSW_COM_Periodic_2 (0x02)
# define Rte_Ev_WP_OsTask_BSW_EventPeriodic_0 (0x02)
# define Rte_Ev_WP_OsTask_CDD_FitPeriodic_1 (0x02)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
