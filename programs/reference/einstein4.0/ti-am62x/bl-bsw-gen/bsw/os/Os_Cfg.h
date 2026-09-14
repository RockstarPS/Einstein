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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.303605200
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
	# define Rte_Ev_Cyclic2_OsTask_WdgMngt_0_500ms             ((EventMaskType)1uLL)
	# define Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms          ((EventMaskType)2uLL)
	# define Rte_Ev_Cyclic2_OsTask_Ucl_0_4ms                   ((EventMaskType)4uLL)
	# define Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms               ((EventMaskType)8uLL)

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

