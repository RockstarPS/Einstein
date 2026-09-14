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
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
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
# define OsTask_Diagnostics (3U)
# define OsTask_DispFun (4U)
# define OsTask_EthFun (5U)
# define OsTask_FotaFun (6U)
# define OsTask_GaugeFun (7U)
# define OsTask_IndFun (8U)
# define OsTask_IpcUclEv (9U)
# define OsTask_LSH_16ms (10U)
# define OsTask_LinFun (11U)
# define OsTask_Mcal (12U)
# define OsTask_MemSer (13U)
# define OsTask_ModeMgt (14U)
# define OsTask_NvmSpeedup (15U)
# define OsTask_SafeApp (16U)
# define OsTask_SafeBsw (17U)
# define OsTask_TripFun (18U)
# define OsTask_WarnFun (19U)
# define OsTask_WdgMngt (20U)

/* Alarms */
# define Rte_Al_TE_OsTask_AppFun_0_10ms (0U)
# define Rte_Al_TE_Test_Comp_AudioTaskStubRunnable (1U)
# define Rte_Al_TE2_OsTask_CANFun_0_10ms (2U)
# define Rte_Al_TE_OsTask_CANFun_0_10ms (3U)
# define Rte_Al_TE2_OsTask_Diagnostics_0_10ms (4U)
# define Rte_Al_TE_OsTask_Diagnostics_0_100ms (5U)
# define Rte_Al_TE_OsTask_Diagnostics_0_10ms (6U)
# define Rte_Al_TE_OsTask_Diagnostics_0_20ms (7U)
# define Rte_Al_TE_OsTask_DispFun_0_10ms (8U)
# define Rte_Al_TE_OsTask_DispFun_0_5ms (9U)
# define Rte_Al_TE_SlowGaugeAdapter_SlowGaugeAdapter_Task (10U)
# define Rte_Al_TE_OsTask_EthFun_0_10ms (11U)
# define Rte_Al_TE_Test_Comp_FotaTaskStubRunnable (12U)
# define Rte_Al_TE_OsTask_GaugeFun_0_20ms (13U)
# define Rte_Al_TE_OsTask_IndFun_0_30ms (14U)
# define Rte_Al_TE_DmnMgr_CDmnMgr_Impl_MainFunction (15U)
# define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (16U)
# define Rte_Al_TE_OsTask_LSH_16ms_0_16ms (17U)
# define Rte_Al_TE_Test_Comp_LinTaskStubRunnable (18U)
# define Rte_Al_TE_OsTask_Mcal_0_10ms (19U)
# define Rte_Al_TE2_OsTask_MemSer_0_10ms (20U)
# define Rte_Al_TE_Ea_Ea_MainFunction (21U)
# define Rte_Al_TE_OsTask_MemSer_0_10ms (22U)
# define Rte_Al_TE2_OsTask_ModeMgt_0_10ms (23U)
# define Rte_Al_TE_OsTask_ModeMgt_0_10ms (24U)
# define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable (25U)
# define Rte_Al_TE_OsTask_SafeApp_0_30ms (26U)
# define Rte_Al_TE2_OsTask_SafeBsw_0_10ms (27U)
# define Rte_Al_TE_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms (28U)
# define Rte_Al_TE_OsTask_SafeBsw_0_10ms (29U)
# define Rte_Al_TE_OsTask_TripFun_0_50ms (30U)
# define Rte_Al_TE_OsTask_WarnFun_0_32ms (31U)
# define Rte_Al_TE_OsTask_WdgMngt_0_10ms (32U)

/* Events */
# define Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms (0x02)
# define Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms (0x01)
# define Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms (0x04)
# define Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms (0x01)
# define Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms (0x08)
# define Rte_Ev_Cyclic_OsTask_CANFun_0_10ms (0x01)
# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms (0x08)
# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms (0x04)
# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms (0x02)
# define Rte_Ev_Cyclic_OsTask_DispFun_0_10ms (0x01)
# define Rte_Ev_Cyclic_OsTask_DispFun_0_5ms (0x02)
# define Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms (0x01)
# define Rte_Ev_Cyclic_OsTask_MemSer_0_10ms (0x02)
# define Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms (0x02)
# define Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms (0x02)
# define Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse (0x20)
# define Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus (0x80000)
# define Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus (0x40000000)
# define Rte_Ev_Run_DltExt_DltExt_OnDreDLTMessageReadAckData (0x1000000)
# define Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction (0x200)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime (0x100000000)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData (0x400)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo (0x10000000)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError (0x01)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat (0x400000)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake (0x4000)
# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState (0x02)
# define Rte_Ev_Run_Ea_Ea_MainFunction (0x08)
# define Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms (0x10)
# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_EBW2 (0x80)
# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_PKBLP (0x40)
# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_SCSBZR (0x04)
# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_VSCOFF (0x20)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable (0x01)
# define Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable (0x01)
# define Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination (0x01)
# define Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task (0x04)
# define Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (0x80000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse (0x40)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest (0x2000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest (0x08)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest (0x10)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest (0x2000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower (0x100)
# define Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status (0x800000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo (0x8000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData (0x20000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr (0x200000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData (0x10000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange (0x8000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon (0x800)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Status (0x80)
# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Toggle (0x200000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus (0x400000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo (0x04)
# define Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status (0x40000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq (0x1000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq (0x100000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay (0x4000000)
# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay (0x20000000)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
