//---------------------------------------------------------------------------------------------------------------------
// VISTEON CORPORATION CONFIDENTIAL
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File Name:       ComAbsCtrlNwControllerApp.c
//---------------------------------------------------------------------------------------------------------------------
#include "ComAbsCtrl_cfg.h"
#ifndef COMABSCTRL_NOT_REQUIRED_FOR_ACP
#ifndef COMABSCTRL_HEADER_NOTREQUIRED_FOR_P61QR
#include "ComAbsCtrl.h"
#endif
#endif
#include "ComAbsCtrlNwControllerApp.h"
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
#include "CanNm_Cfg.h"
#endif
#include "Rte_Type.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
// Fixed: Double parentheses ensure safe macro expansion (MISRA 20.7)
#define ICAN_BUS_ASLEEP                     ((uint8)0xEE)
#define ICAN_BUS_AWAKE                      ((uint8)0xAE)
#define ICAN_READY_TO_SLEEP                 ((uint8)0xAA)
#define ICAN_BUS_INIT                       ((uint8)0xBA)
#define ICAN_ALIVE_TIMER_COUNTER_VALUE      ((uint16)0x1F4)
#define ICAN_ALIVE_TIMER_COUNTER_INIT       ((uint16)0x00)

//=====================================================================================================================
//  Static Variables
//=====================================================================================================================
static uint8 ICAN_OperationalMode;

#ifdef EPRNDS_MODE_OUT_ENABLED
static Boolean ComAbsCtrl_prev_ePRNDS_status;
#endif

#ifdef PDS_INPUT_ENABLED
static Boolean ComAbsCtrl_prev_PDS_Switch_status;
uint8 ErrorType;
#endif

static uint16 ICAN_NwAliveTimerCounter;
static boolean ICAN_NwAwake_Flag; 
#ifdef COMABSCTRL_LOWQCURRENT_SUPPORT_ENABLE
static LowQCurrentSleepStatus ComAbsCtrl_LowQCurrent_PF; //DID Implementation for Low Q Current, Platform Variable
#endif
//=====================================================================================================================
//  Function Prototypes
//=====================================================================================================================
static void ComAbsCtrl_NwControllerApp_Network_KeyOff_Status(tPwrModeState ComAbsNW_IGN);
#ifndef COMABSCTRL_NOT_REQUIRED_FOR_ACP
static void ComAbsCtrl_NwControllerApp_Check_ICAN_WakeUP(void);
#endif
#ifdef COMABSCTRL_BUSSTATE_SILENT_ENABLE
void Comabsctrl_CAN_Busstate(uint8 CAN_OperationalMode)
{
    ICAN_OperationalMode = CAN_OperationalMode;
}
#endif

/*============================================================================
**
** Function Name:      void ComAbsCtrl_NwControllerApp_Init(void)
**
** Visibility:         This function is externally visible
**
** Description:
**
** Inputs/Outputs:     
**
** Critical Section:   No
**
** Created:
** SRD Ref 560106 I-CAN Sleep Status 
**
** Updated:
**
**==========================================================================*/
void ComAbsCtrl_NwControllerApp_Init(void)
{
    ICAN_OperationalMode = ICAN_BUS_INIT; 
    #ifdef EPRNDS_MODE_OUT_ENABLED
    ComAbsCtrl_prev_ePRNDS_status = FALSE;
    #endif
    #ifdef PDS_INPUT_ENABLED
    ComAbsCtrl_prev_PDS_Switch_status = FALSE;
    #endif
    ICAN_NwAwake_Flag = TRUE;
    ICAN_NwAliveTimerCounter = ICAN_ALIVE_TIMER_COUNTER_VALUE; 
}

/*============================================================================
**
** Function Name:      void ComAbsCtrl_NwControllerApp_Wakeup_Init(void)
**
** Visibility:         This function is externally visible
**
** Description:
**
** Inputs/Outputs:     
**
** Critical Section:   No
**
** Created:
** SRD Ref 560106 I-CAN Sleep Status 
**
** Updated:
**
**==========================================================================*/
void ComAbsCtrl_NwControllerApp_Wakeup_Init(void)
{
    ICAN_NwAwake_Flag = FALSE;
    ICAN_NwAliveTimerCounter = ICAN_ALIVE_TIMER_COUNTER_INIT;
}

/*============================================================================
**
** Function Name:      void ComAbsCtrl_NwControllerApp_ProcessAliveTimer(void)
**
** Visibility:         This function is externally visible
**
** Description:
**
** Inputs/Outputs:     
**
** Critical Section:   No
**
** Created:
** SRD Ref 560106 I-CAN Sleep Status 
**
** Updated:
**
**==========================================================================*/
void ComAbsCtrl_NwControllerApp_ProcessAliveTimer(void)
{
	if(ICAN_NwAliveTimerCounter != 0x00U)
    {
        ICAN_NwAliveTimerCounter--;
		if(ICAN_NwAliveTimerCounter == 0x00U)
        {
            ICAN_NwAwake_Flag = FALSE;		
        }
    }		
}

/*============================================================================
**
** Function Name:      ComAbsCtrl_NwControllerApp_Network_KeyOff_Status
**
** Visibility:         This function is not externally visible
**
** Description:
**
** Inputs/Outputs:     
**
** Critical Section:   No
**
** Created:
** SRD Ref 560106 I-CAN Sleep Status 
**
** Updated:
**
**==========================================================================*/
static void ComAbsCtrl_NwControllerApp_Network_KeyOff_Status(tPwrModeState ComAbsNW_IGN)
{
	if(FALSE != ComAbsCtrl_NWSleep_Wakeup_Determination(ComAbsNW_IGN, ICAN_NwAwake_Flag))
    {
        /*
        ** HS CAN key off Process is complete, HSCAN Bus ON counter = 0 and
        ** HS CAN TxConf Counter = 0, shall HS CAN be put into sleep
        */
        #ifndef COMABSCTRL_COMEXT_APINOTAVAILABLE
        ComAbsCtrl_SetNetworkComMode(eReleaseCom);
        #endif
        ICAN_OperationalMode = ICAN_READY_TO_SLEEP;
    }
    else
    {
        /*
        ** Either HS CAN Key off condition is not satisfied or ignition is not
        ** in off/acc
        */
        #ifndef COMABSCTRL_COMEXT_APINOTAVAILABLE
        ComAbsCtrl_SetNetworkComMode(eRequestCom);
        #endif
        ICAN_OperationalMode = ICAN_BUS_AWAKE;
    }
}

/*============================================================================
**
** Function Name:      ComAbsCtrl_NwControllerApp_Sleep_Wakeup_Process
**
** Visibility:         Externally visible
**
** Description:        Main state machine for sleep/wake transitions.
**
** Inputs/Outputs:     ComAbsNW_IGNstatus - current ignition state
**
** Critical Section:   No
**
** Created:
** SRD Ref 560106 I-CAN Sleep Status 
**
** Updated:
**
**==========================================================================*/
void ComAbsCtrl_NwControllerApp_Sleep_Wakeup_Process(tPwrModeState ComAbsNW_IGNstatus)
{		
    ComAbsCtrl_NwControllerApp_Network_KeyOff_Status(ComAbsNW_IGNstatus);
	if(ICAN_OperationalMode != ICAN_BUS_ASLEEP)
    {
		if(ICAN_OperationalMode == ICAN_READY_TO_SLEEP)
        {
            #ifndef COMABSCTRL_COMEXT_APINOTAVAILABLE
            #ifndef COMABSCTRL_NOT_REQUIRED_FOR_ACP
            ComM_ModeType GetComMode = 0U;
            (void)GET_CANNM_CURRENTMODE(&GetComMode);

			if(COMM_NO_COMMUNICATION == GetComMode)
            {
                #ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
				if(CanNm_GetNmState(0) == NM_STATE_BUS_SLEEP)
                #endif
                {
                    ICAN_OperationalMode = ICAN_BUS_ASLEEP;
                    #ifdef EPRNDS_MODE_OUT_ENABLED
                    EPRNDS_MODE_OUT_STATUS(&ComAbsCtrl_prev_ePRNDS_status);
                    #endif

                    #ifdef PDS_INPUT_ENABLED
                    (void)PDS_IN_STATUS(ePDSInStatus, &ComAbsCtrl_prev_PDS_Switch_status, &ErrorType);
                    #endif

                }
            }
            #endif
			#endif /*Do nothing*/
		   
        }
    }
	else
	{}
    #ifndef COMABSCTRL_NOT_REQUIRED_FOR_ACP
	if(ICAN_OperationalMode == ICAN_BUS_ASLEEP)
    {
        ComAbsCtrl_NwControllerApp_Check_ICAN_WakeUP();	
    }
	else
	{}
    #endif
}
#ifndef COMABSCTRL_NOT_REQUIRED_FOR_ACP
/*============================================================================
**
** Function Name:      void ComAbsCtrl_NwControllerApp_Check_ICAN_WakeUP(void)
**
** Visibility:         This function is not externally visible
**
** Description:
**
** Inputs/Outputs:     
**
** Critical Section:   No
**
** Created:
** SRD Ref 560107 	   I-CAN Wakeup Status 
**
** Updated:
**
**==========================================================================*/
static void ComAbsCtrl_NwControllerApp_Check_ICAN_WakeUP(void)
{
/*  BOOLEAN fl_pw_fepndl_eprndlmode_out_BOOL scope and extra vnim_nw_KSLocalWakeup();
    and fl_CAN_WakeupStatus_BOOL = FALSE; calls will be raplaced after R00 release*/

    Boolean fl_CAN_WakeupStatus_BOOL = FALSE;

  	/* function is called when the network goes to sleep  */

#ifdef PDS_INPUT_ENABLED
   /* power supplies should be turned on and should be stable. feprndl PDS In processing handles this*/
    static Boolean fl_PDS_Switch_Current_status_value = FALSE;

    (void)PDS_IN_STATUS(ePDSInStatus, &fl_PDS_Switch_Current_status_value, &ErrorType);

    if (ComAbsCtrl_prev_PDS_Switch_status != fl_PDS_Switch_Current_status_value)
    {
        fl_CAN_WakeupStatus_BOOL = TRUE;
    }
#endif

#ifdef EPRNDS_MODE_OUT_ENABLED
    Boolean fl_pw_fepndl_eprndlmode_out_BOOL = FALSE;
    EPRNDS_MODE_OUT_STATUS(&fl_pw_fepndl_eprndlmode_out_BOOL);

   	if(ComAbsCtrl_prev_ePRNDS_status != fl_pw_fepndl_eprndlmode_out_BOOL)
    {
        fl_CAN_WakeupStatus_BOOL = TRUE;
    }
#endif

#ifdef COMABSCTRL_LOWQCURRENT_SUPPORT_ENABLE
    ComAbsCtrl_LowQCurrent_PF = eLowQCmdOFF;
    (void)ComAbsCtrl_LowQCurrent_Sleep_Status(&ComAbsCtrl_LowQCurrent_PF);
#endif

#ifdef COMABSCTRL_CAN_BUS_TRAFFIC
    ComM_ModeType GetComMode = 0U;
    (void)GET_CANNM_CURRENTMODE(0U, &GetComMode);
    #ifdef COMABSCTRL_SIG_PROCESSING_PF2
	if(COMM_FULL_COMMUNICATION == GetComMode)
    #endif
    #ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
	if(CanNm_GetNmState(0) == NM_STATE_NORMAL_OPERATION)
    #endif
    {
        fl_CAN_WakeupStatus_BOOL = TRUE;
    }

#endif

    if (TRUE == fl_CAN_WakeupStatus_BOOL)
    {
#ifdef COMABSCTRL_LOWQCURRENT_SUPPORT_ENABLE
        if (eLowQCmdOFF == ComAbsCtrl_LowQCurrent_PF)
#endif
        {
            ICAN_NwAwake_Flag = TRUE;
            ICAN_NwAliveTimerCounter = ICAN_ALIVE_TIMER_COUNTER_VALUE;
            #ifndef COMABSCTRL_COMEXT_APINOTAVAILABLE
            ComAbsCtrl_SetNetworkComMode(eRequestCom);
            #endif
            ICAN_OperationalMode = ICAN_BUS_INIT;

        }
    }
}
#endif


/***********************************************************************************************/

