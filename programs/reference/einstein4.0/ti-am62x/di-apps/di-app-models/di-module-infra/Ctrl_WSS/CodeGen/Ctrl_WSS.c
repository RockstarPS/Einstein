/*---------------------------------------------------------------------------------------------------------------------
**
** VISTEON CORPORATION CONFIDENTIAL
** ________________________________
**
** [2015] Visteon Corporation
** All Rights Reserved.
**
** NOTICE: This is an unpublished work of authorship, which contains trade secrets.
** Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
** its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
** or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
** in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
** under all copyright laws to protect this work as a published work, when appropriate.
** Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
** without the written authorization of Visteon Corporation.
**
** ---------------------------------------------------------------------------------------------------------------------*/

#include "Rte_Ctrl_WSS.h"
#include "Ctrl_WSS.h"
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Rte_Ctrl_WSS_Type.h"
#include "string.h"
#include "CmpLib.h"

/* @brief  Instance of life-cycle state-machine */
CMPLIB_INSTANCE(trl_WSS)

/*=====================================================================================================================
**  CONSTANTS & TYPES
**=====================================================================================================================*/
#define Channel_0 ((uint8)0)
#define IGNON_VALUE ((uint8)1)
#define TIME_25min (uint32)1500000
#define cCTRLWSS_TASK_TIME_MS         	 (10)
#define cCTRLWSS_IC_SLEEP_WAIT_TIME        ((60*1000)/(cCTRLWSS_TASK_TIME_MS))    /* 60s counting every 10ms  */
#define cCTRLWSS_IC_IGNCAN_MAX_TIME        ((3*1000)/(cCTRLWSS_TASK_TIME_MS))    /* 3s counting every 10ms  */

#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif
/*=====================================================================================================================
**  FORWARD DECLARATIONS
**=====================================================================================================================*/

/* This variable will hold the 1 min timer for SleepCtrl */
static boolean l_swc_app_sleep_bool;
static uint8 l_Ctrl_Wss_Ign_Status_u8;
//static uint8 l_prev_AccStatus_u8;
static uint8 c_SWC_App_CtrlWss_sleep_status[eSWCApp_End];
static uint8 fl_loop_Idx;
static uint16 l_AppSleep60secCounter_u16;
static uint16 l_AppIgnCAN3secCounter_u16;
static boolean	l_Swc_Odo_Init_bool;


/*=====================================================================================================================
**  PRIVATE
**=====================================================================================================================*/
static void Ctrl_Wss_SWC_Ign_Buzzer_Acc_Ba_Igp_Networkmode_status(void);
static void Ctrl_Wss_SWC_Application_sleep_status(void);
static void Ctrl_WSS_SWCIgnForCANStatus(uint8 IgpStatus);
static void Ctrl_WSS_TFTDisplayOn_Status(void);
/*=====================================================================================================================
**  PRIVATE
**=====================================================================================================================*/

static uint8 Notify_Sleep_Status = NETWORK_NORMAL;

/*---------------------------------------------------------------------------------------------------------------------
** @brief  Transitional initialization state
**
** @return E_OK:           Succeed
** <br>     E_NOT_READY:    In progress. Keeps the component in this state.
** <br>     E_NOT_OK:       Failed
**---------------------------------------------------------------------------------------------------------------------*/
static Std_ReturnType CmpInit( void )
{
	(void)Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(CLUSTER_INIT);
	l_Swc_Odo_Init_bool = FALSE;
	(void) Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(CLUSTER_INACTIVE);
    l_AppSleep60secCounter_u16 = (uint8)0;
	l_AppIgnCAN3secCounter_u16 = (uint8)0;
	l_swc_app_sleep_bool = FALSE;
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);/*25min*/
	(void)memset(&c_SWC_App_CtrlWss_sleep_status[0],eISleep_Active,eSWCApp_End);
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);
	/*Rte_Call_rp_Init_rp_Init_Mdl_GaBGM_Init();*/
	// Rte_Call_rp_Init_rp_Init_Mdl_Fuel_Init();
	// Rte_Call_rp_Init_rp_Init_AppSndCtrl_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_EWTemp_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_Rearfog_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_CSeat_Belt_Cfg_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_Variant_Config_Init();
	/*Rte_Call_rp_Init_rp_Init_Mdl_TurnSwCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_BodyLockCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_RemEngKeyCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_RemEngStartCtrlState_Init(); 
	Rte_Call_rp_Init_rp_Init_Mdl_FhlCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_BsmCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_RemoteHzdCtrlState_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_HzdSwCtrlState_Init();*/
	//Ctrl_Wss_SWC_Ign_Buzzer_Acc_Ba_Igp_Networkmode_status();
	//Rte_Call_rp_Init_rp_Init_Ctrl_Dim_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_Derate_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wChargeSys_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wHybirdSysBatLow_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wALMNM_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wHeadECU_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wHybird_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wRemChargeAmount_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wHybirdEV_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wHVAETrackBatIns_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_Dim_PWMOut_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wVehMovIGKey_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wHybirdMaiCer_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wRSR_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BHybridMalFun_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BLTA_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wACLoadLimit_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wParKSupBrake_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BAutoCruiseControl_Init();
	/*Rte_Call_rp_Init_rp_Init_Core_clag_tc_AFE_Init();
	Rte_Call_rp_Init_rp_Init_Core_clag_tc_IFE_Init();
	Rte_Call_rp_Init_rp_Init_Core_clag_tc_AVS_Init();*/
	// Rte_Call_rp_Init_rp_Init_Toyota_clag_tc_DTE_Init();
	// Rte_Call_rp_Init_rp_Init_Toyota_clag_tc_DT_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_TripDist_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_TripFuel_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_EVDriveTime_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_AFE_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_IFE_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_DTE_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_AVS_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_DriveTime_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_AFEView_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_IFEView_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_DTEView_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_AVSView_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_DriveTimeView_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BHighWaterTemp_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BHybridSysEV_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wMidEastKmph_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wECTInfo_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wPropServOpAdv_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wRoadSurfFreeze_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wCruiseCtrlSys_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wVehMovIGKey_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BATReverse_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BBrakeHoldStandBy_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BDoorAjar_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_vEnergyFlowWarn_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wIntSteerSwitch_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wHybSysAccHold_Init();	
	// Rte_Call_rp_Init_rp_Init_Mdl_vTpms_Init();	
	// Rte_Call_rp_Init_rp_Init_Mdl_v4WdAwd_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wShiftPosInd_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_vEcoDriveIndicator_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aLta_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aPda_Da_Init();
	//Rte_Call_rp_Init_rp_Init_Mdl_AdasMenu_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_vHybridSysMalFunc_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aAccTF_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wLDA_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wBodySysVoiceOp_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wLTA_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wLCA_Init();
	// //Rte_Call_rp_Init_rp_Init_Mdl_wDigitKeySys_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aTss_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aLca_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wDoorWarn_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aAccInterrupt_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_aClearanceSonar_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_DriveRecorder_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_vEcoJudge_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_sOilMilPowerTrain_Init();
    // Rte_Call_rp_Init_rp_Init_Mdl_wVoiceOpWarn_Init();
	// /*Rte_Call_rp_Init_rp_Init_Mdl_CTurn_Hazard_Init();*/
	// Rte_Call_rp_Init_rp_Init_Mdl_wWasherFluidLvl_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_RemoteWarning_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_wBrakeHoldStandby_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_BClearSonarSys_Init();
	// Rte_Call_rp_Init_rp_Init_Mdl_AnalogSpeed_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init();
	Rte_Call_rp_Init_rp_Init_View_Speed_Init();
	Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init();

	return E_OK;
}
/*---------------------------------------------------------------------------------------------------------------------
** @brief  Transitional de-initialization state
**
** @return E_OK:           Succeed
** <br>     E_NOT_READY:    In progress. Keeps the component in this state.
** <br>     E_NOT_OK:       Failed
**---------------------------------------------------------------------------------------------------------------------*/
static Std_ReturnType CmpDeInit( void )
{
    return E_OK;
}

/*---------------------------------------------------------------------------------------------------------------------
** @brief  Transitional activation state
**
** @return E_OK:           Succeed
** <br>     E_NOT_READY:    In progress. Keeps the component in this state.
** <br>     E_NOT_OK:       Failed
**---------------------------------------------------------------------------------------------------------------------*/
static Std_ReturnType CmpActivation( void )
{
	l_AppSleep60secCounter_u16 = (uint8)0;
	l_AppIgnCAN3secCounter_u16 = (uint8)0;
	l_swc_app_sleep_bool = FALSE;
	//Rte_Call_rp_Init_rp_Init_Mdl_Variant_Config_Init();
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);/*25min*/
	(void)memset(&c_SWC_App_CtrlWss_sleep_status[0],eISleep_Active,eSWCApp_End);
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);
    return E_OK;
}

/*---------------------------------------------------------------------------------------------------------------------
** @brief  Transitional de-activation state
**
** @return E_OK:           Succeed
** <br>     E_NOT_READY:    In progress
** <br>     E_NOT_OK:       Failed
**---------------------------------------------------------------------------------------------------------------------*/
static Std_ReturnType CmpDeActivation( void )
{
	//reset();
    return E_OK;
}
/*---------------------------------------------------------------------------------------------------------------------
** @brief  Transitional CmpActive state
**
** @return E_OK:           Succeed
** <br>     E_NOT_READY:    In progress
** <br>     E_NOT_OK:       Failed
**---------------------------------------------------------------------------------------------------------------------*/
/*static Std_ReturnType CmpActive( void )
{
	Ctrl_WSS_Impl_MainFunction();
	  return E_OK;
}*/
/****************************************************************************
** Function Name     : void Ctrl_WSS_Impl_MainFunction(void)
**
** Description       : 	This function process the batt drain and app sleep status to set the sleep condition

**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static Std_ReturnType CmpActive( void )
{

	# define Rte_TypeDef_SMainHMIReadyStatus
	typedef struct
	{
  	  uint8 status;
	} SMainHMIReadyStatus;
	
	boolean fl_battdrain_status_bool;
	uint8 fl_timer_25min_started_bool;
	uint8 fl_timer_25min_elapsed_bool;
	uint8 fl_sleep_status;
	uint8 fl_network_mode_status_u8;
	Std_ReturnType fl_ret_u8;
	boolean fl_NvmReadStatus_bool = FALSE;
	boolean fl_Phase1ReadStatus_bool = FALSE;
	SMainHMIReadyStatus fl_SMainHMIReadyStatus_st = {0U};
	
	(void)Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(&fl_NvmReadStatus_bool);
	(void)Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(CLUSTER_RUN);
	(void)Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(&fl_Phase1ReadStatus_bool);
	//fl_Phase1ReadStatus_bool = TRUE;  //stub - to be removed
	
	if(fl_NvmReadStatus_bool != FALSE)
	{
		(void)Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(CLUSTER_RUN_READALL);
	}
	if(fl_Phase1ReadStatus_bool != FALSE)
	{
		if(l_Swc_Odo_Init_bool == FALSE)
		{
			//Rte_Call_rp_Init_rp_Init_OdoCtrl_Init();
			//Rte_Call_rp_Init_rp_Init_Mdl_Odo_Init();
		}
		l_Swc_Odo_Init_bool = TRUE;
		(void) Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(CLUSTER_ACTIVE);
	}
	Ctrl_Wss_SWC_Ign_Buzzer_Acc_Ba_Igp_Networkmode_status();
	Ctrl_WSS_TFTDisplayOn_Status();

	if(l_Ctrl_Wss_Ign_Status_u8 == IgnOff)
	{
		fl_battdrain_status_bool = FALSE;
		
		Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(eSleepMaxTimer, &fl_timer_25min_started_bool);
		Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(eSleepMaxTimer,TIME_25min, &fl_timer_25min_elapsed_bool);
		Rte_Call_rpComMExt_CAN_GetCurrentComMode(Channel_0, &fl_network_mode_status_u8);

		for(fl_loop_Idx = eSWCApp_SmartKey_Bzr;fl_loop_Idx <= eSWCApp_Tail_TT;fl_loop_Idx++)
		{
			fl_sleep_status = c_SWC_App_CtrlWss_sleep_status[fl_loop_Idx];

			if(fl_sleep_status == eSleep_Inactive)
			{
				fl_battdrain_status_bool = TRUE;
				break;
			}
		}
		if((fl_timer_25min_started_bool == FALSE) && (fl_network_mode_status_u8 == COMM_NO_COMMUNICATION))
		{
			Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);
			Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(eSleepMaxTimer);
		}
		else if(fl_network_mode_status_u8 != COMM_NO_COMMUNICATION)
		{
				Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);
			 
		}
		else
		{
				if(fl_timer_25min_elapsed_bool != FALSE)
				{
					if(FALSE == fl_battdrain_status_bool)
					{
						l_swc_app_sleep_bool = TRUE;	
                        Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);						
					}
					
				}
		}
		
		Ctrl_Wss_SWC_Application_sleep_status();			
	}
	else
	{

	}
	fl_ret_u8 = Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(&fl_SMainHMIReadyStatus_st);
	/*UCL return status check: To avoid the Lost or empty data reception*/
	if (fl_ret_u8 == E_OK)
	{
		Rte_Write_pp_HMIReady_HMI_ReadyStatus(fl_SMainHMIReadyStatus_st.status);
	}
	else
	{
		/*Do Nothing*/
	}
    
	/*stub - to be removed once HMI ready statys working properly - Defect Raised - PE4TI29141-9973*/
	Rte_Write_pp_HMIReady_HMI_ReadyStatus(1u);
	return E_OK;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}
/****************************************************************************
** Function Name     : void Ctrl_Wss_SWC_Application_sleep_status(void)
**
** Description       : 	This function process the sleep status for the application module to trigger 60sec timer

**
** Invocation        : Ctrl_Wss.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static void Ctrl_Wss_SWC_Application_sleep_status( void )
{
	boolean fl_SWC_App_status_bool;
	uint8 fl_app_Idx;
	uint8 fl_network_mode_status_u8;
	fl_network_mode_status_u8 = COMM_NO_COMMUNICATION;
	uint8 fl_Nvm_rdySleep = E_NOT_OK;

	Rte_Call_rpComMExt_CAN_GetCurrentComMode(Channel_0, &fl_network_mode_status_u8);

	fl_SWC_App_status_bool = FALSE;
	c_SWC_App_CtrlWss_sleep_status[eSWCApp_NVM] = eISleep_Active;
	c_SWC_App_CtrlWss_sleep_status[eSWCApp_Illum] = eISleep_Active;

		for(fl_app_Idx = eSWCApp_Fuel;fl_app_Idx < eSWCApp_End;fl_app_Idx++)
		{
			if(c_SWC_App_CtrlWss_sleep_status[fl_app_Idx] == eSleep_Inactive)
			{
				fl_SWC_App_status_bool = TRUE;
				break;
			}
			else
			{
				
			}
		}
				 
		if(fl_SWC_App_status_bool == FALSE)
		{
			if(fl_network_mode_status_u8 == COMM_NO_COMMUNICATION)
			{
				if(l_AppSleep60secCounter_u16 < cCTRLWSS_IC_SLEEP_WAIT_TIME)
				{
					l_AppSleep60secCounter_u16++;
				}
				else
				{
					fl_Nvm_rdySleep = MemAbstractMdl_NvmWriteStatus();
					if(fl_Nvm_rdySleep == E_OK)
					{
						l_swc_app_sleep_bool = TRUE;
					}
					else{
						l_AppSleep60secCounter_u16 = 0;
					}
						
				}
			}
			else
			{
				l_AppSleep60secCounter_u16 = 0;
			}
		}
		else
		{
			l_AppSleep60secCounter_u16 = 0;
		}
		
}
/****************************************************************************
** Function Name     : void Ctrl_Wss_SWC_Ign_Buzzer_Acc_Ba_Igp_Networkmode_status(void)
**
** Description       : 	This function process the IGN,IGN buzzer, Acc, BA, IGP internal status

**
** Invocation        : Ctrl_Wss.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static void Ctrl_Wss_SWC_Ign_Buzzer_Acc_Ba_Igp_Networkmode_status(void)
{
	VehicleActiveModes fl_AppMode;
	//uint8 fl_Can_msg_Acc_value_u8;
	//uint8 fl_CanMsgAcc_Status_U8;
	//uint8 fl_Can_msg_Igp_value_u8;
	//uint8 fl_CanMsgIgp_Status_U8;
	//uint8 fl_Can_msg_Ba_value_u8;
	//uint8 fl_CanMsgBa_Status_U8;
	//uint8 fl_Can_msg_Baof_value_u8;
	//uint8 fl_CanMsgBaof_Status_U8;
	//uint8 fl_BaStatus_u8;
	//uint8 fl_BaofStatus_u8;
	//uint8 fl_AccStatus_u8;
	uint8 fl_IgpStatus_u8 = 0u;
	uint8 fl_get_error_status_u8;
	uint8 fl_network_mode_status_u8;
	SInt32 fl_Ign_IoHab_Status_S32 = E_NOT_OK;

	uint8 COM_Power_Mode_Value = 0u;
	uint8 COM_Power_Mode_Status= 0u;

	(void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(ePowerModeIn, &COM_Power_Mode_Value,&COM_Power_Mode_Status);

	if(COM_Power_Mode_Value == NETWORK_SLEEP)
	{
		
		Notify_Sleep_Status = NETWORK_SLEEP;

		Rte_Call_rpIoHwAb_Din_GetProcessedInput(((uint8)eIO_DIN_DI_IGN_MON), &fl_Ign_IoHab_Status_S32, &fl_get_error_status_u8);
	}
	else
	{
		Notify_Sleep_Status = NETWORK_NORMAL;
		Rte_Call_rpIoHwAb_Din_GetProcessedInput(((uint8)eIO_DIN_DI_IGN_MON), &fl_Ign_IoHab_Status_S32, &fl_get_error_status_u8);

	}

	// Rte_Call_rp_CS_CanAdapterRx_RxCanAdapter_GetSignalValueU8(eACC_PDCIn,&fl_Can_msg_Acc_value_u8, &fl_CanMsgAcc_Status_U8);
	// Rte_Call_rp_CS_CanAdapterRx_RxCanAdapter_GetSignalValueU8(eIGP_PDCIn,&fl_Can_msg_Igp_value_u8, &fl_CanMsgIgp_Status_U8);
	// Rte_Call_rp_CS_CanAdapterRx_RxCanAdapter_GetSignalValueU8(eBA_PDCIn,&fl_Can_msg_Ba_value_u8, &fl_CanMsgBa_Status_U8);
	// Rte_Call_rp_CS_CanAdapterRx_RxCanAdapter_GetSignalValueU8(eBAOF_PDCIn,&fl_Can_msg_Baof_value_u8, &fl_CanMsgBaof_Status_U8);
	(void)Rte_Call_rpComMExt_CAN_GetCurrentComMode(Channel_0, &fl_network_mode_status_u8);

	if(fl_network_mode_status_u8 == COMM_FULL_COMMUNICATION)
	{
		fl_AppMode = NETWORK_NORMAL;
	}
	else if(l_swc_app_sleep_bool != FALSE)
	{
		fl_AppMode = NETWORK_SLEEP;
	}
	else
	{
		fl_AppMode = NETWORK_STANDALONE;/* COMM_SILENT_COMMUNICATION or COMM_NO_COMMUNICATION*/
	}
	

	if(fl_Ign_IoHab_Status_S32 == IGNON_VALUE) /*Value 1 --> IGN ON, Value 0 is IGN OFF*/
	{
		l_Ctrl_Wss_Ign_Status_u8 = IgnOn;
	}
	else
	{
		l_Ctrl_Wss_Ign_Status_u8 = IgnOff;
	}

	// if (fl_AppMode != ((VehicleActiveModes)((uint8)NETWORK_NORMAL)))
	// {
	// 	//fl_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
	// 	fl_IgpStatus_u8 = ((uint8)IGPSTATUS_OFF);
	// 	//fl_BaStatus_u8 = ((uint8)BASTATUS_OFF);
	// }
	// else
	// {
		// if (fl_CanMsgAcc_Status_U8 == ((uint8)RTE_E_MAX_AGE_EXCEEDED))
		// {
		// 	if(l_Ctrl_Wss_Ign_Status_u8 != ((uint8)IgnOff))
		// 	{
		// 		//fl_AccStatus_u8 = l_prev_AccStatus_u8;
		// 	}
		// 	else
		// 	{
		// 		//fl_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
		// 	}
		// }
		// else if (fl_CanMsgAcc_Status_U8 == ((uint8)RTE_E_NEVER_RECEIVED))
		// {
		// 	//fl_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
		// 	l_prev_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
		// }
		// else if (fl_Can_msg_Acc_value_u8 == ((uint8)ACCSTATUS_ON_VAL))
		// {
		// 	//fl_AccStatus_u8 = ((uint8)ACCSTATUS_ON);
		// 	l_prev_AccStatus_u8 = ((uint8)ACCSTATUS_ON);
		// }
		// else
		// {
		// 	//fl_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
		// 	l_prev_AccStatus_u8 = ((uint8)ACCSTATUS_OFF);
		// }
		// if ((fl_CanMsgIgp_Status_U8 == ((uint8)RTE_E_MAX_AGE_EXCEEDED)) || (fl_CanMsgIgp_Status_U8 == ((uint8)RTE_E_NEVER_RECEIVED)))
		// {
		// 	fl_IgpStatus_u8 = ((uint8)IGPSTATUS_OFF);
		// }
		// else if (fl_Can_msg_Igp_value_u8 == ((uint8)IGPSTATUS_ON_VAL))
		// {
		// 	fl_IgpStatus_u8 = ((uint8)IGPSTATUS_ON);
		// }
		// else
		// {
		// 	fl_IgpStatus_u8 = ((uint8)IGPSTATUS_OFF);
		// }
		
		// if ((fl_CanMsgBaof_Status_U8 == ((uint8)RTE_E_MAX_AGE_EXCEEDED)) || (fl_CanMsgBaof_Status_U8 == ((uint8)RTE_E_NEVER_RECEIVED)))
		// {
		// 	//fl_BaofStatus_u8 = ((uint8)BAOFSTATUS_OFF);
		// }
		// else if (fl_Can_msg_Baof_value_u8 == ((uint8)BAOFSTATUS_ON_VAL))
		// {
		// 	//fl_BaofStatus_u8 = ((uint8)BAOFSTATUS_ON);
		// }
		// else
		// {
		// 	//fl_BaofStatus_u8 = ((uint8)BAOFSTATUS_OFF);
		// }
		
		// if ((fl_CanMsgBa_Status_U8 == ((uint8)RTE_E_MAX_AGE_EXCEEDED)) || (fl_CanMsgBa_Status_U8 == ((uint8)RTE_E_NEVER_RECEIVED)))
		// {
		// 	//fl_BaStatus_u8 = ((uint8)BASTATUS_OFF);
		// }
		// else if (fl_Can_msg_Ba_value_u8 == ((uint8)BASTATUS_ON_VAL))
		// {
		// 	//fl_BaStatus_u8 = ((uint8)BASTATUS_ON);
		// }
		// else
		// {
		// 	//fl_BaStatus_u8 = ((uint8)BASTATUS_OFF);
		// }
		Ctrl_WSS_SWCIgnForCANStatus(fl_IgpStatus_u8);

	(void) Rte_Write_ppIgnSubstate_IgnitionSubstate((IgntionSubstateType)l_Ctrl_Wss_Ign_Status_u8);
	(void) Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate((IgntionSubstateType)l_Ctrl_Wss_Ign_Status_u8);
	//(void) Rte_Write_ppBaModeState_WSSBaState((ModeStatus)fl_BaStatus_u8);
	//(void) Rte_Write_ppBaOfModeState_WSSBaOfState((ModeStatus)fl_BaofStatus_u8);
	(void) Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(fl_AppMode);
	//(void) Rte_Write_ppIgpModeState_WSSIGPState((ModeStatus)fl_IgpStatus_u8);
	//(void) Rte_Write_ppAccModeState_WSSAccState(fl_AccStatus_u8);
}

/****************************************************************************
** Function Name     : Ctrl_WSS_CtrlWSS_NotifyNetworkSleep
** Description       : 	This function notify the power mode status to EcuAppM to turn off Ign
**
** Invocation        : EcuAppM
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
FUNC(Std_ReturnType, Ctrl_WSS_CODE) Ctrl_WSS_CtrlWSS_NotifyNetworkSleep(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) NotifyStatus)
{

	*NotifyStatus = Notify_Sleep_Status;

	return E_OK;

}


/****************************************************************************
** Function Name     : void CtrlWSS_ReadytoSleep(void)
**
** Description       : 	This function process the return the sleep ok or not to the modemanager
**
** Invocation        : 
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_ReadytoSleep(void)
{
	Std_ReturnType sleep_status;

	if(l_swc_app_sleep_bool != FALSE)
	{
		sleep_status = E_OK;
	}
	else
	{
		sleep_status = E_NOT_OK;
	}
	return sleep_status;
}
/****************************************************************************
** Function Name     : void Ctrl_WSS_SWCSleepStatus(void)
**
** Description       : 	This function collect the batt drain and application module sleep active or inactive

**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCSleepStatus(eAppMdl AppModule, eSleepSt SleepStatus)
{
	c_SWC_App_CtrlWss_sleep_status[AppModule] = SleepStatus;
}
/****************************************************************************
** Function Name     : void Ctrl_WSS_SWCIgnForCANStatus(void)
**
** Description       : 	This function collect is to Ign status is active for 3 sec

**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static void Ctrl_WSS_SWCIgnForCANStatus(uint8 IgpStatus)
{	
	if(IGPSTATUS_ON == IgpStatus)
	{
		if(l_AppIgnCAN3secCounter_u16 < cCTRLWSS_IC_IGNCAN_MAX_TIME)
		{
			l_AppIgnCAN3secCounter_u16++;
		}
		else
		{
			//Rte_Write_ppIgpCANModeState_WSSIGPState(IgpStatus);
		}
	}
	else
	{
		l_AppIgnCAN3secCounter_u16 = 0;
		//Rte_Write_ppIgpCANModeState_WSSIGPState(IgpStatus);
	}

}
/****************************************************************************
** Function Name     : void CtrlWSS_SWC_EarlyWakeUpHandle(void)
**
** Description       : This function handles the early wakeup for Applications
**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCEarlyWakeUpHandle(void)
{	
	l_AppSleep60secCounter_u16 = (uint8)0;
	l_AppIgnCAN3secCounter_u16 = (uint8)0;
	l_swc_app_sleep_bool = FALSE;
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);/*25min*/
	(void)memset(&c_SWC_App_CtrlWss_sleep_status[0],eISleep_Active,eSWCApp_End);
	Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(eSleepMaxTimer);

}

/****************************************************************************
** Function Name     : void Ctrl_WSS_TFTDisplayOnExceptTurn_Status(void)
**
** Description       : 	This function determine the TFTDisplayOnExceptTurn and TFTDisplayOn status

**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static void Ctrl_WSS_TFTDisplayOn_Status(void)
{
	uint8 fl_HMI_Screenmode_sts_u8 = STATUS_OFF; 
	uint8 fl_ShiftPositionDisplay_sts_u8 = STATUS_OFF; 
	TT_OP_Type TelltaleInputStatus; /* Telltale status array local variable */
	uint8 fl_TurnLstatus_sts_u8 = TT_TURN_OFF; 
	uint8 fl_TurnRstatus_sts_u8 = TT_TURN_OFF; 
	uint8 fl_HMI_ShiftIndStatus_u8 = STATUS_OFF;
	uint8 fl_HMI_OdoType_u8 = STATUS_OFF;
	boolean fl_Indicator_status = TT_TURN_OFF;
	//boolean fl_TFTDisplayOnExceptTurn_Status = STATUS_OFF;
	boolean fl_TFTDisplayOn_sts = STATUS_OFF;
	SMainHMIReadyStatus fl_SMainHMIReadyStatus_st = {0U};
	Std_ReturnType fl_ret_u8;
	
	Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&fl_HMI_Screenmode_sts_u8);
	Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(&fl_ShiftPositionDisplay_sts_u8);
  (void)Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(TelltaleInputStatus);
	Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(&fl_TurnLstatus_sts_u8);
	Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(&fl_TurnRstatus_sts_u8);
	
	/* TFTDisplayOn status determination */
	fl_ret_u8 = Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(&fl_SMainHMIReadyStatus_st);
	/*UCL return status check: To avoid the Lost or empty data reception*/
	if (fl_ret_u8 == E_OK)
	{
		fl_TFTDisplayOn_sts = fl_SMainHMIReadyStatus_st.status;
	}
	else
	{
		fl_TFTDisplayOn_sts = STATUS_OFF;
	}
	
		/*stub - to be removed once HMI ready statys working properly - Defect Raised - PE4TI29141-9973*/
	fl_TFTDisplayOn_sts = STATUS_ON;
	/* HMI Screenmode based update for HMI_OdoType_u8 and HMI_ShiftIndStatus_u8 */
	if(fl_HMI_Screenmode_sts_u8 == eSCREENMODE_BLANK)
	{
		/* BLANK Update HMI_OdoType_u8 and HMI_ShiftIndStatus_u8 */
		fl_HMI_OdoType_u8 = eODO_TYPE_BLANK;
		fl_HMI_ShiftIndStatus_u8 = eSCREENMODE_BLANK;
	}
	else 
	{
		
		if(fl_HMI_Screenmode_sts_u8 == eSCREENMODE_NORMAL)
		{
			/* ODO Update HMI_OdoType_u8*/
			fl_HMI_OdoType_u8 = eODO_TYPE_ODO;
		}
		else
		{
			fl_HMI_OdoType_u8 = eODO_TYPE_OFF;
		}
		/* HMI_ShiftIndStatus_u8 update based on ShiftPositionDisplay*/
		if(fl_HMI_Screenmode_sts_u8 == eSCREENMODE_OPENING)
		{
			fl_HMI_ShiftIndStatus_u8 = eSCREENMODE_BLANK;
		}
		else if(fl_ShiftPositionDisplay_sts_u8 == STATUS_ON)
		{
			fl_HMI_ShiftIndStatus_u8 = STATUS_ON;
		}
		else
		{
			fl_HMI_ShiftIndStatus_u8 = STATUS_OFF;
		}
			
	}
	/* Indicator Status determination At least one indicator is not OFF.*/
	if((TelltaleInputStatus[TT_FFOG_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_RFOG_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_HEAD_INDEX ]!= TT_TURN_OFF)|| (TelltaleInputStatus[ TT_READY_INDEX]!= TT_TURN_OFF) ||
	   (TelltaleInputStatus[TT_AIRBAG_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_HIGH_BEAM_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_ABS_INDEX]!= TT_TURN_OFF)|| (TelltaleInputStatus[TT_VCS_OFF_INDEX]!= TT_TURN_OFF) ||
	   (TelltaleInputStatus[TT_TAIL_LIGHT_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_PARKING_BRAKE_INDEX ]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_BRAKE_YELLOW_INDEX ]!= TT_TURN_OFF)|| (TelltaleInputStatus[TT_BRAKE_RED_INDEX ]!= TT_TURN_OFF) ||
	   (TelltaleInputStatus[TT_TRACTION_CTRL_INDEX]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_FUEL_INDEX ]!= TT_TURN_OFF) || (TelltaleInputStatus[TT_BRAKE_HOLD_INDEX]!= TT_TURN_OFF)|| (TelltaleInputStatus[TT_BRAKE_HOLD_STANDBY_INDEX]!= TT_TURN_OFF))
	{
		fl_Indicator_status = TT_TURN_ON;
	}
	else
	{
		fl_Indicator_status = TT_TURN_OFF;
	}
	 /* TFT Display On/Off Status Determination  */  
   if(((fl_HMI_Screenmode_sts_u8 !=  eSCREENMODE_BLANK) && (fl_HMI_Screenmode_sts_u8 !=  eSCREENMODE_OFF)) || (fl_HMI_ShiftIndStatus_u8 == STATUS_ON) ||
	   ((fl_HMI_OdoType_u8 !=  eODO_TYPE_BLANK) && (fl_HMI_OdoType_u8 !=  eODO_TYPE_OFF)) || (fl_Indicator_status == TT_TURN_ON))
   {
	   
	   //fl_TFTDisplayOnExceptTurn_Status = STATUS_ON;
	    c_SWC_App_CtrlWss_sleep_status[eTFTDisplayOnExceptTurn] = eSleep_Inactive;
   }
   else
   {
	   //fl_TFTDisplayOnExceptTurn_Status = STATUS_OFF;
	   c_SWC_App_CtrlWss_sleep_status[eTFTDisplayOnExceptTurn] = eISleep_Active;
   }
   
//    /* TFTDisplayOn status determination */
//    if((fl_TFTDisplayOnExceptTurn_Status == STATUS_ON) || (fl_TurnLstatus_sts_u8 !=  TT_TURN_OFF) || (fl_TurnRstatus_sts_u8 !=  TT_TURN_OFF))
// 	{
// 		fl_TFTDisplayOn_sts = STATUS_ON;
// 	}
// 	else
// 	{
// 		fl_TFTDisplayOn_sts = STATUS_OFF;
// 	}
	/* sleepActive check based on TurnRightindicator list*/
	if((fl_TurnRstatus_sts_u8 !=  TT_TURN_OFF) && (fl_TurnRstatus_sts_u8 !=  TT_TURN_ON)) 
	{
		c_SWC_App_CtrlWss_sleep_status[eTurnR_Status] = eSleep_Inactive;
	}
	else
	{
		c_SWC_App_CtrlWss_sleep_status[eTurnR_Status] = eISleep_Active;
	}
	/* sleepActive check based on TurnLightindicator list*/
	if((fl_TurnLstatus_sts_u8 !=  TT_TURN_OFF) && (fl_TurnLstatus_sts_u8 !=  TT_TURN_ON))
	{
		c_SWC_App_CtrlWss_sleep_status[eTurnL_Status] = eSleep_Inactive;
	}
	else
	{
		c_SWC_App_CtrlWss_sleep_status[eTurnL_Status] = eISleep_Active;
	}
	Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(fl_TFTDisplayOn_sts);
}

/*---------------------------------------------------------------------------
Date              : 30-09-2025
CDSID             : aelango6
Traceability      : PE4TI29141-10412
Change Description: Ctrl-WSS - Initial version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 18-11-2025
CDSID             : aelango6
Traceability      : PE4TI29141-10857
Change Description: Notify sleep status to EcuAppM for CAN-H operation
-----------------------------------------------------------------------------*/


