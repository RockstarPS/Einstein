/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:23.772325200
********************************************************************************************************************/

	#ifndef OS_CFG_H
	#define OS_CFG_H
	
	/*****************************************************************************
	*                            Include files                                   *
	*****************************************************************************/


	/*****************************************************************************
	*                                 Macro Definitions                          *
	*----------------------------------------------------------------------------*
	* Definition of macro shall be followed by a comment that explains the       *
	* purpose of the macro.                                                      *
	*****************************************************************************/
	
	#define OS_CFG_OS_STATUS                                  OS_STATUS_EXTENDED
	
	#define MOS_VERSION_INFO_API                              STD_ON
	
	#define MOS_USE_SCHED_LOG                                 STD_OFF
	
	#define OS_TESTING_LOCAL                                  STD_OFF
	
	
	
	/******** OS Hook Routines are Enabled *************************************/
	#define OS_CFG_SUPPORT_DBG_HOOKS
	#define OS_ENABLE_OSAPI_ERR_HOOK
	#define OS_API_ERROR_HOOK(x,y)			//pouplate user defined error hook here
	
	
	
	/* OS SC3 Functionalities is STD_ON or STD_OFF */
	#define OS_CFG_MEMORY_PROTECTION                          STD_ON
	
	#define OS_CFG_MPU_SWITCH_APP                             STD_ON
	
	#define OS_CFG_MPU_SWITCH_OBJ                             STD_OFF
	
	#define OS_CFG_MPU_STACK_REGION_NUM                       12U
	

	#define CC_TYPE                                   ECC1
	#define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )
	
	
	/* Events */
	# define Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms               ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms          ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms               ((EventMaskType)2uLL)
	# define Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms              ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms              ((EventMaskType)64uLL)
	# define Rte_Ev_Cyclic_MemSer_10msLP_0_10ms                ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic_OsTask_CANFun_0_10ms                ((EventMaskType)2uLL)
	# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms          ((EventMaskType)2uLL)
	# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms           ((EventMaskType)4uLL)
	# define Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms           ((EventMaskType)8uLL)
	# define Rte_Ev_Cyclic_OsTask_DispFun_0_10ms               ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic_OsTask_DispFun_0_5ms                ((EventMaskType)4uLL)
	# define Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms              ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic_OsTask_MemSer_0_10ms                ((EventMaskType)4uLL)
	# define Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms               ((EventMaskType)2uLL)
	# define Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms               ((EventMaskType)1uLL)
	# define Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse          ((EventMaskType)1uLL)
	# define Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus          ((EventMaskType)2uLL)
	# define Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus          ((EventMaskType)4uLL)
	# define Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction       ((EventMaskType)8uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime          ((EventMaskType)16uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData ((EventMaskType)32uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo          ((EventMaskType)64uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError          ((EventMaskType)128uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat      ((EventMaskType)256uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake          ((EventMaskType)512uLL)
	# define Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState          ((EventMaskType)1024uLL)
	# define Rte_Ev_Run_Ea_Ea_MainFunction                     ((EventMaskType)8uLL)
	# define Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms          ((EventMaskType)32uLL)
	# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_EBW2          ((EventMaskType)2uLL)
	# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_PKBLP          ((EventMaskType)4uLL)
	# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_SCSBZR          ((EventMaskType)8uLL)
	# define Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_VSCOFF          ((EventMaskType)16uLL)
	# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable          ((EventMaskType)16uLL)
	# define Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable          ((EventMaskType)1uLL)
	# define Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination     ((EventMaskType)128uLL)
	# define Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task ((EventMaskType)2uLL)
	# define Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction          ((EventMaskType)2048uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse          ((EventMaskType)4294967296uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest          ((EventMaskType)8589934592uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest       ((EventMaskType)4096uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest    ((EventMaskType)8192uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest   ((EventMaskType)16384uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower      ((EventMaskType)32768uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status          ((EventMaskType)65536uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo        ((EventMaskType)131072uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData    ((EventMaskType)262144uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr     ((EventMaskType)524288uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData     ((EventMaskType)1048576uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange          ((EventMaskType)2097152uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon             ((EventMaskType)4194304uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Status           ((EventMaskType)8388608uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Toggle           ((EventMaskType)16777216uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus    ((EventMaskType)33554432uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo        ((EventMaskType)67108864uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status            ((EventMaskType)134217728uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq ((EventMaskType)268435456uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq          ((EventMaskType)536870912uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay       ((EventMaskType)1073741824uLL)
	# define Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay    ((EventMaskType)2147483648uLL)
	# define Rte_Ev_Run_DltExt_DltExt_OnDreDLTMessageReadAckData          ((EventMaskType)17179869184uLL)
	# define Gfx_Ev_RdrInit                                    ((EventMaskType)1uLL)
	# define Gfx_Ev_RdrInitDone                                ((EventMaskType)2uLL)
	# define Gfx_Ev_RdrDeinit                                  ((EventMaskType)4uLL)
	# define Gfx_Ev_RdrDeinitDone                              ((EventMaskType)8uLL)
	# define Gfx_Ev_RdrStart                                   ((EventMaskType)16uLL)
	# define Gfx_Ev_VSync                                      ((EventMaskType)32uLL)

	#define OS_CFG_SCHEDULE_TABLE                             STD_OFF

	#define OS_CFG_NUM_OF_APP_MODES                           1U
	
	#define OSDEFAULTAPPMODE                                  1U



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
	
	

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

