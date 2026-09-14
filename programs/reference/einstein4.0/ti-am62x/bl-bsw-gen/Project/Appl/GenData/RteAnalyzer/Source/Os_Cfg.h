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
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
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
# define OsTask_AppFun (0U)
# define OsTask_AudioFun (1U)
# define OsTask_CANFun (2U)
# define OsTask_CddFun (3U)
# define OsTask_Diagnostics (4U)
# define OsTask_EthFun (5U)
# define OsTask_FotaFun (6U)
# define OsTask_GaugeFun (7U)
# define OsTask_Graphics (8U)
# define OsTask_IndFun (9U)
# define OsTask_LinFun (10U)
# define OsTask_Mcal (11U)
# define OsTask_MemSer (12U)
# define OsTask_ModeMgt (13U)
# define OsTask_NvmSpeedup (14U)
# define OsTask_SafeFun (15U)
# define OsTask_TripFun (16U)
# define OsTask_WarnFun (17U)
# define OsTask_WdgMngt (18U)

/* Alarms */
# define Rte_Al_TE_Test_Comp_AppTaskStubRunnable (0U)
# define Rte_Al_TE_Test_Comp_AudioTaskStubRunnable (1U)
# define Rte_Al_TE_OsTask_CANFun_0_10ms (2U)
# define Rte_Al_TE_Test_Comp_CddTaskStubRunnable (3U)
# define Rte_Al_TE2_OsTask_Diagnostics_0_10ms (4U)
# define Rte_Al_TE_OsTask_EthFun_0_10ms (5U)
# define Rte_Al_TE_Test_Comp_FotaTaskStubRunnable (6U)
# define Rte_Al_TE_Test_Comp_GaugeTaskStubRunnable (7U)
# define Rte_Al_TE_Test_Comp_GraphicsTaskStubRunnable (8U)
# define Rte_Al_TE_Test_Comp_IndTaskStubRunnable (9U)
# define Rte_Al_TE_Test_Comp_LinTaskStubRunnable (10U)
# define Rte_Al_TE_OsTask_Mcal_0_10ms (11U)
# define Rte_Al_TE2_OsTask_MemSer_0_10ms (12U)
# define Rte_Al_TE_Ea_Ea_MainFunction (13U)
# define Rte_Al_TE_OsTask_MemSer_0_10ms (14U)
# define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (15U)
# define Rte_Al_TE_Test_Comp_IoExp_MainFunction (16U)
# define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable (17U)
# define Rte_Al_TE_Test_Comp_TxRxIpcMessage (18U)
# define Rte_Al_TE_Test_Comp_TripTaskStubRunnable (19U)
# define Rte_Al_TE_Test_Comp_WarnTaskStubRunnable (20U)
# define Rte_Al_TE_Test_Comp_WdgMgntTaskStubRunnable (21U)

/* Events */
# define Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms (0x04)
# define Rte_Ev_Cyclic_OsTask_MemSer_0_10ms (0x08)
# define Rte_Ev_Run_Ea_Ea_MainFunction (0x01)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable (0x02)
# define Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable (0x01)
# define Rte_Ev_Run_Test_Comp_GraphicsTaskStubRunnable (0x01)
# define Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (0x80)
# define Rte_Ev_Run_UclProxyCdd_OnDre_EnetRegReq (0x40)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData (0x20)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr (0x100)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IgnState (0x10)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange (0x200)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
