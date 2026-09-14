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
// @File Name:       ComAbsCtrl.c
// @Description: 	 This component controls the ComAbs component with respect to
// @				 Application SRD Network / Multiplex - Generic SRD 0.3
//---------------------------------------------------------------------------------------------------------------------
#include "ComAbsCtrl_cfg.h"
//#include "ComAbsController_Cfg.h"
#include "ComAbsCtrlNwControllerApp.h"
#include "CmpLib.h"
#ifdef COMABSCTRL_38XD_PROGRAM_SPECIFIC_HS_INIT
#include "ComMExt.h"
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
#include "ComM_EcuMBswM.h"
#include "ComM.h"
#include "Com.h"
#endif
#ifdef COMABSCTRL_POWER_FROM_COM
#include "Com_Cfg.h"
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_PF2
#ifndef COMABSCTRL_POWER_FROM_COM_TT
#include "Fnos_ComAbs_Abstraction.h" 
#else
#include "Com_Cfg.h"
#ifndef COMABSCTRL_HEADER_NOTREQUIRED_FOR_P61QR
#include "Com_Types.h"
#endif
#endif
#endif
#include "ComAbsCtrl.h"
/* @brief  Instance of life-cycle state-machine */
CMPLIB_INSTANCE(ComAbsCtrl)

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
    static boolean ComAbsCtrl_Fault_Trigger = Flag_No_Fault;
    static boolean ComAbsCtrl_Run_Trigger = Flag_Not_Run;
    static boolean ComAbsCtrl_Run_Start_Trigger = Flag_Not_Run_Start;
#endif

#ifdef COMABSCTRL_MODEMGR_RESETREASON
tResetReason Rte_ModeMgr_ppSRModeResetReason_ResetReason;//MISRA- declared more than once and declared never defined
#else
//extern VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason;
#endif

#if (STUBS_FOR_EXTERNAL_APIS_IN_COMABS_CTRL  == 1)
void Rte_Read_rpSR_Power_Data_PwrMode(tPwrModeState * temp)
{
	
}
Std_ReturnType Rte_Receive_Power_Event_SR_PwrModeChange(tPwrModeTrans *data) 
{
	 return E_OK;
}

Std_ReturnType Rte_Read_rpSR_Power_Data_FaultCounterReset(tFaultCounterReset *data)
{
	 return E_OK;
}
#endif
#if 1

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static Std_ReturnType Rte_Receive_DiagnosticsEvent_SR_ClearDTCEvent (tClearDTC *data)
{
	 return E_OK;	 
}
#endif
#endif	

#ifdef COMABSCTRL_COMABSSAFE_EN
	#if ( MAX_ELEMENTS_IN_SAFE_RX_INIT1 > 0 )
	static const uint16 ComAbsSafe_Rx_Init1_Array_U16A[MAX_ELEMENTS_IN_SAFE_RX_INIT1]=
	{
			COMABS_SAFE_RX_INIT1_ARRAY
	};
	#endif
#endif
#ifdef COMABSCTRL_P61QR_INVALID_SIG_EN
static const tRxSignalId ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY]=
{
	COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_ARRAY
};
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static const uint16 ComAbsCtrl_Rx_Init2_Array_U16A[MAX_ELEMENTS_IN_RX_INIT2]=
{
		COMABS_CTRL_RX_INIT2_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Init3_Array_U16A[MAX_ELEMENTS_IN_RX_INIT3]=
{
		COMABS_CTRL_RX_INIT3_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Init4_Array_U16A[MAX_ELEMENTS_IN_RX_INIT4]=
{
		COMABS_CTRL_RX_INIT4_ARRAY
};
#endif


#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
#if  (MAX_ELEMENTS_IN_TX_INIT1_VALUE_ARRAY > 0)
	static const uint32 ComAbsCtrl_Tx_Init1_Val_U32A[MAX_ELEMENTS_IN_TX_INIT1_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT1_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT2_VALUE_ARRAY > 0)
	static const uint32 ComAbsCtrl_Tx_Init2_Val_U32A[MAX_ELEMENTS_IN_TX_INIT2_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT2_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_TX_INIT3_VALUE_ARRAY > 0)	
	static const uint32 ComAbsCtrl_Tx_Init3_Val_U32A[MAX_ELEMENTS_IN_TX_INIT3_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT3_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT4_VALUE_ARRAY > 0)
	static const uint32 ComAbsCtrl_Tx_Init4_Val_U32A[MAX_ELEMENTS_IN_TX_INIT4_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT4_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_RX_INIT1_VALUE_ARRAY > 0)
    static const uint32 ComAbsCtrl_Rx_Init1_Val_U32A[MAX_ELEMENTS_IN_RX_INIT1_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT1_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT2_VALUE_ARRAY > 0)	
	static const uint32 ComAbsCtrl_Rx_Init2_Val_U32A[MAX_ELEMENTS_IN_RX_INIT2_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT2_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT3_VALUE_ARRAY > 0)		
	static const uint32 ComAbsCtrl_Rx_Init3_Val_U32A[MAX_ELEMENTS_IN_RX_INIT3_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT3_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_RX_INIT4_VALUE_ARRAY > 0)
	static const uint32 ComAbsCtrl_Rx_Init4_Val_U32A[MAX_ELEMENTS_IN_RX_INIT4_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT4_VALUE_ARRAY
	};
#endif	
	
#else
#ifdef COMABSCTRL_SIG_PROCESSING_PF2
	static uint32 ComAbsCtrl_Rx_Init_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_VALUE_ARRAY
	};
#endif
#endif

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static const uint16 ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY]=
{
		COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START]=
{
		COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_OR_START_ARRAY
};


static const uint16 ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY]=
{
		COMABS_CTRL_RX_MISSING_RUN_DIAG_MODE_YES_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY]=
{
		COMABS_CTRL_RX_MISSING_RUN_DIAG_MODE_NO_ARRAY
};

#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY > 0)
static const uint16 ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY]=
{
		COMABS_CTRL_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY
};
#endif

#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
static const uint16 ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY]=
{
		COMABS_CTRL_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY
};
#endif

static const uint16 ComAbsCtrl_NVR_Init1_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT1_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT1_ARRAY
};

static const uint16 ComAbsCtrl_NVR_Init2_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT2_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT2_ARRAY
};

static const uint16 ComAbsCtrl_NVR_Init3_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT3_ARRAY
};

static const uint16 ComAbsCtrl_NVR_Init4_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT4_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT4_ARRAY
};
#endif

#ifdef COMABSCTRL_COMABSSAFE_EN
	#if (MAX_ELEMENTS_IN_SAFE_TX_INIT1_ARRAY > 0)
	static const uint16 ComAbsSafe_Tx_Init1_U16A[MAX_ELEMENTS_IN_SAFE_TX_INIT1_ARRAY]=
	{
		COMABS_SAFE_TX_INIT1_ARRAY
	};
	#endif
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static const uint16 ComAbsCtrl_Tx_Init2_U16A[MAX_ELEMENTS_IN_TX_INIT2_ARRAY]=
{
	COMABS_CTRL_TX_INIT2_ARRAY
};

static const uint16 ComAbsCtrl_Tx_Init3_U16A[MAX_ELEMENTS_IN_TX_INIT3_ARRAY]=
{
	COMABS_CTRL_TX_INIT3_ARRAY
};

static const uint16 ComAbsCtrl_Tx_Init4_U16A[MAX_ELEMENTS_IN_TX_INIT4_ARRAY]=
{
	COMABS_CTRL_TX_INIT4_ARRAY
};
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_PF2
static uint32 ComAbsCtrl_Tx_Init_value_U32A[MAX_ELEMENTS_IN_TX_INIT_VALUE_ARRAY]=
{
	COMABS_CTRL_TX_INIT_VALUE_ARRAY
};
#endif

#ifdef COMABSCTRL_38XD_PROGRAM_SPECIFIC_HS_INIT
// RX Init Array for VCAN
static const uint16 ComAbsCtrl_Rx_Init_BA_VCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_BA_VCAN]=
{
		COMABS_CTRL_RX_INIT_BA_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Init_B_VCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_B_VCAN]=
{
		COMABS_CTRL_RX_INIT_B_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_Rx_Init_IGR_VCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN]=
{
		COMABS_CTRL_RX_INIT_IGR_VCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_BSP_VCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN]=
{
		COMABS_CTRL_RX_INIT_BSP_VCAN_ARRAY
};
#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0)
		static const tRxSafeSignalId ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Array_U16A[SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN]=
		{
			SAFETY_COMABS_CTRL_RX_INIT_IGR_VCAN_ARRAY
		};
	#endif

	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
		static const tRxSafeSignalId ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Array_U16A[SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN]=
		{
			SAFETY_COMABS_CTRL_RX_INIT_BSP_VCAN_ARRAY
		};
	#endif
#endif

#if (MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN]=
{
		COMABS_CTRL_RX_INIT_ACCIGR_VCAN_ARRAY
};
#endif

// RX Init value Array for VCAN
#if  (MAX_ELEMENTS_IN_RX_INIT_BA_VCAN_VALUE_ARRAY > 0)
    static uint32 ComAbsCtrl_Rx_Init_BA_VCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_BA_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_BA_VCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_B_VCAN_VALUE_ARRAY > 0)	
	static uint32 ComAbsCtrl_Rx_Init_B_VCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_B_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_B_VCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN_VALUE_ARRAY > 0)		
	static uint32 ComAbsCtrl_Rx_Init_IGR_VCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_IGR_VCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Rx_Init_BSP_VCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_BSP_VCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_ACCIGR_VCAN_VALUE_ARRAY
	};
#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if  (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN_VALUE_ARRAY > 0)		
		static uint32 ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Val_U32A[SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN_VALUE_ARRAY]=
		{
			SAFETY_COMABS_CTRL_RX_INIT_IGR_VCAN_VALUE_ARRAY
		};
	#endif	
	#if  (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN_VALUE_ARRAY > 0)
		static uint32 ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Val_U32A[SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN_VALUE_ARRAY]=
		{
			SAFETY_COMABS_CTRL_RX_INIT_BSP_VCAN_VALUE_ARRAY
		};
	#endif
#endif

// TX Init Array for VCAN
static const uint16 ComAbsCtrl_Tx_Init_BA_VCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_BA_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_Tx_Init_B_VCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_B_VCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_B_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_Tx_Init_IGR_VCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_IGR_VCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_BSP_VCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_BSP_VCAN_ARRAY
};
#endif

#if (MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_ACCIGR_VCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_ACCIGR_VCAN_ARRAY
};
#endif

// TX Init value Array for VCAN
#if  (MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_BA_VCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_BA_VCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_B_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_B_VCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_B_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_B_VCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_VALUE_ARRAY > 0)	
	static uint32 ComAbsCtrl_Tx_Init_IGR_VCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_IGR_VCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_BSP_VCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_BSP_VCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_ACCIGR_VCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_ACCIGR_VCAN_VALUE_ARRAY
	};
#endif

// RX Init Array for MCAN
#if (MAX_ELEMENTS_IN_RX_INIT_BA_MCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_BA_MCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_BA_MCAN]=
{
		COMABS_CTRL_RX_INIT_BA_MCAN_ARRAY
};
#endif

#if(MAX_ELEMENTS_IN_RX_INIT_B_MCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_B_MCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_B_MCAN]=
{
		COMABS_CTRL_RX_INIT_B_MCAN_ARRAY
};
#endif

static const uint16 ComAbsCtrl_Rx_Init_IGR_MCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN]=
{
		COMABS_CTRL_RX_INIT_IGR_MCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_BSP_MCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN]=
{
		COMABS_CTRL_RX_INIT_BSP_MCAN_ARRAY
};
#endif

#if (MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)
static const uint16 ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN]=
{
		COMABS_CTRL_RX_INIT_ACCIGR_MCAN_ARRAY
};
#endif

// RX Init value Array for MCAN
#if  (MAX_ELEMENTS_IN_RX_INIT_BA_MCAN_VALUE_ARRAY > 0)
    static uint32 ComAbsCtrl_Rx_Init_BA_MCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_BA_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_BA_MCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_B_MCAN_VALUE_ARRAY > 0)	
	static uint32 ComAbsCtrl_Rx_Init_B_MCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_B_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_B_MCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN_VALUE_ARRAY > 0)		
	static uint32 ComAbsCtrl_Rx_Init_IGR_MCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_IGR_MCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Rx_Init_BSP_MCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_BSP_MCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_RX_INIT_ACCIGR_MCAN_VALUE_ARRAY
	};
#endif

// TX Init Array for MCAN
#if (MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_BA_MCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_BA_MCAN_ARRAY
};
#endif 

#if (MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_B_MCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_B_MCAN_ARRAY
};
#endif

static const uint16 ComAbsCtrl_Tx_Init_IGR_MCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_IGR_MCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_BSP_MCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_BSP_MCAN_ARRAY
};
#endif

#if (MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_Tx_Init_ACCIGR_MCAN_U16A[MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY]=
{
	COMABS_CTRL_TX_INIT_ACCIGR_MCAN_ARRAY
};
#endif

// TX Init value Array for MCAN
#if  (MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_BA_MCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_BA_MCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_B_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_B_MCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_B_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_B_MCAN_VALUE_ARRAY
	};
#endif
#if  (MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_VALUE_ARRAY > 0)	
	static uint32 ComAbsCtrl_Tx_Init_IGR_MCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_IGR_MCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_BSP_MCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_BSP_MCAN_VALUE_ARRAY
	};
#endif	
#if  (MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_VALUE_ARRAY > 0)
	static uint32 ComAbsCtrl_Tx_Init_ACCIGR_MCAN_Val_U32A[MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_VALUE_ARRAY]=
	{
		COMABS_CTRL_TX_INIT_ACCIGR_MCAN_VALUE_ARRAY
	};
#endif

// Never Received arrays - VCAN
static const uint16 ComAbsCtrl_NVR_Init_BA_VCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_VCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_BA_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_NVR_Init_B_VCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_VCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_B_VCAN_ARRAY
};

static const uint16 ComAbsCtrl_NVR_Init_IGR_VCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_BSP_VCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY
};
#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN 
	#if (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0)
	static const tRxSafeSignalId ComAbsCtrl_Safety_NVR_Init_IGR_VCAN_U16A[SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY]=
	{
		SAFETY_COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY
	};
	#endif

	#if (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
	static const tRxSafeSignalId ComAbsCtrl_Safety_NVR_Init_BSP_VCAN_U16A[SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY]=
	{
		SAFETY_COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY
	};
	#endif
#endif
#if (MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_ACCIGR_VCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY
};
#endif

// Never Received arrays - MCAN
#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_BA_MCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY
};
#endif

#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_B_MCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY
};
#endif

static const uint16 ComAbsCtrl_NVR_Init_IGR_MCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_MCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_IGR_MCAN_ARRAY
};

#if (MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_BSP_MCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY
};
#endif

#if (MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY > 0)
static const uint16 ComAbsCtrl_NVR_Init_ACCIGR_MCAN_U16A[MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY]=
{
		COMABS_CTRL_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY
};
#endif

// Invalid arrays - VCAN and MCAN
#if (MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN > 0)
static const uint16 ComAbsCtrl_Invalid_PWRMode_Run_U16A[MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN]=
{
	    COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_ARRAY
};
#endif

#if (MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START > 0)
static const uint16 ComAbsCtrl_Invalid_PWRMode_RunOrStart_U16A[MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START]=
{
	    COMABS_CTRL_RX_INVALID_PWR_MODE_RUN_OR_START_ARRAY
};
#endif

#endif

// ComAbsCtrl private methods for Life Cycle Management
///@brief   The ComAbsCtrl specific Init method
static Std_ReturnType CmpInit(void);
///@brief   The ComAbsCtrl specific DeInit method
static Std_ReturnType CmpDeInit(void);
///@brief   The ComAbsCtrl specific Active method
static Std_ReturnType CmpActive(void);
///@brief   The ComAbsCtrl specific Activation method
static Std_ReturnType CmpActivation(void);
///@brief   The ComAbsCtrl specific DeActivation method
static Std_ReturnType CmpDeActivation(void);

static void ComAbsCtrl_Input(void);
static void ComAbsCtrl_BuffInit( void );
#ifndef COMABSCTRL_DTC_NOT_IMPLEMENTED_V1
       void NetworkDTC_Active(void);
#endif 

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
    static void ComAbsCtrl_TxRxBuffInitWake( void );
    static void ComAbsCtrl_TxRxBuffInitOnCond3Transition(void );
    static void ComAbsCtrl_TxRxBuffInitOnCond4Transition(void );
    static void ComAbsCtrl_PwrModeUnstableResetTimers(void);
    static void ComAbsCtrl_CheckFaultCounterReset(void);
    static void ComAbsCtrl_CanNetModeTimerProcess( void );
    static void ComAbsCtrl_TransIntoIgnOff(void);

    static void ComAbsCtrl_TransIntoRun_DiagModeNo(void);
    static void ComAbsCtrl_TransOutofRun_DiagModeNo(void);
    static void ComAbsCtrl_TransIntoRunStart_DiagModeNo(void);
    static void ComAbsCtrl_TransIntoOffAcc_DiagModeNo(void);
#endif

#ifdef COMABSCTRL_38XD_PROGRAM_SPECIFIC_HS_INIT
	static void ComAbsCtrl_BuffInit( void );
	#if 0
	static void ComAbsCtrl_MissingProcessing_on_Activation(void);
	static void ComAbsCtrl_IgnMissingProcessing(void);
	#endif
	static void ComAbsCtrl_BuffInit_IGR_BSP(void);
	static void ComAbsCtrl_TxRxBuffInitWake( void );
    static void ComAbsCtrl_TxRxBuffInitOnCond3Transition(void );
	static void ComAbsCtrl_CANHWError_Handling(void);
	
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
//----------------------------------------------------------------------------------------------------------------------
// ComAbsCtrl Event management related definitions
///@brief   ComAbsCtrl specific Event handler function prototype.
typedef void (*tpf_ComAbsCtrl_EventHandler_PwrModeChange)(tpComAbsCtrl_Context pCommon,tPwrModeTrans Data);
typedef void (*tpf_ComAbsCtrl_EventHandler_ClearDTCEvent)(tpComAbsCtrl_Context pCommon,tClearDTC ClearDTCEvent);

typedef void (* const * tppf_ComAbsCtrl_EventHandler_PwrModeChange)(tpComAbsCtrl_Context pCommon, tPwrModeTrans Data);
typedef void (* const * tppf_ComAbsCtrl_EventHandler_ClearDTCEvent)(tpComAbsCtrl_Context pCommon, tClearDTC ClearDTCEvent);
#endif
static uint8 ComAbsCtrl_IgnMode;
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static tFaultCounterReset ComAbsCtrl_FaultCounterReset = eFaultCounterResetNo;
static void HandleEvents(tpComAbsCtrl_Context pThis);
static void ComAbsCtrl_EventHandler_PwrModeChange(tpComAbsCtrl_Context pCommon, tPwrModeTrans Data);
static void ComAbsCtrl_EventHandler_ClearDTCEvent(tpComAbsCtrl_Context pCommon, tClearDTC ClearDTCEvent);
#endif
//----------------------------------------------------------------------------------------------------------------------
// Local macros

static void ComAbsCtrl_Input(void)
{
#ifdef COMABSCTRL_SIG_PROCESSING_PF2
	#ifndef COMABSCTRL_POWER_FROM_COM_TT
		ComAbsCtrl_PowerData_PowerMode(&ComAbsCtrl_IgnMode);
	#else
		#ifndef COMABSCTRL_POWERFROMIO
			extern FUNC(uint8, COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr);
			(void)Com_ReceiveSignal(ComConf_ComSignal_PowerModeStateStatus_oBCM_HUICTrailer_RC1_oIPC_7TFT_Digital_Common_5ea9aaa0_Rx, (&ComAbsCtrl_IgnMode));
		#else
		//Recieve IgnStatus from IO for Two Wheeler Programs
			(void)COMABSCTRL_IOHWAB_IGNMODE(eIO_Din_IGN_INT,&ComAbsCtrl_IgnMode,&ErrorStatus); 
		#endif
	#endif
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
#ifdef COMABSCTRL_POWER_FROM_COM
	extern FUNC(uint8, COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr);
	(void)Com_ReceiveSignal(ComConf_ComSignal_Ignition_Status_oBodyInfo_3_HS3_oHS3_CAN_46fae21b_Rx, (&ComAbsCtrl_IgnMode));
#else
	GET_IGN_MODE_STATE(&ComAbsCtrl_IgnMode);
#endif
 	 GET_FAULT_COUNTER_RESET(&ComAbsCtrl_FaultCounterReset);
#endif
    uint8 fl_get_error_status_u8;
    sint32 fl_Ign_IoHab_Status_S32 = 0;
    
    // Convert signal ID with explicit type safety; value known to fit in uint8
    const uint8 fl_SignalId_u8 = eIO_DIN_DI_IGN_MON;
    (void)IoHwAb_GetProcessedInput(fl_SignalId_u8, &fl_Ign_IoHab_Status_S32, &fl_get_error_status_u8);
    if(fl_Ign_IoHab_Status_S32 >= 0)
    {
        if(1 == fl_Ign_IoHab_Status_S32)
        {
            ComAbsCtrl_IgnMode = ePwrMode_Run;
        }
        else
        {
            ComAbsCtrl_IgnMode = ePwrMode_Off;
        }
    }
    else
    {
        /*do nothing*/
    }
}
//On ComActiivation
//all diag yes and no must be processed (missing and invalid)
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE

static void ComAbsCtrl_DiagModeProcessing_on_Activation(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;

	//MISSING_RUN_DIAG_YES_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}

	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}

	//MISSING_RUN_OR_START_DIAG_YES_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}

	//MISSING_RUN_OR_START_DIAG_NO_ARRAY
	#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
	/* missing counter restart processing for Run or Start array */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	#endif

	//INVALID_POWERMODE_RUN_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)TRUE);
	}

	//INVALID_POWERMODE_RUN_START_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)TRUE);
	}

	ComAbsCtrl_Fault_Trigger = Flag_No_Fault; 
	
}

// FaultResetCounter based Missing and Invalid Processing for applicable Signals
static void ComAbsCtrl_FaultCounterReset_Processing(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;

	if( eFaultCounterResetYes == ComAbsCtrl_FaultCounterReset)
	{
		if( ComAbsCtrl_Fault_Trigger != Flag_Fault)
		{
			//MISSING_RUN_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//MISSING_RUN_OR_START_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//INVALID_POWERMODE_RUN_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter];
				Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//INVALID_POWERMODE_RUN_START_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
				Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
			}

			ComAbsCtrl_Fault_Trigger = Flag_Fault;
            ComAbsCtrl_Run_Trigger = Flag_Not_Run;
            ComAbsCtrl_Run_Start_Trigger = Flag_Not_Run_Start;
		}
	}
	else
	{
		if( ComAbsCtrl_Fault_Trigger != Flag_No_Fault)
		{
			// missing_all_diag_mode_yes - False 
			// invalid_all_diag_mode_yes - False

			//MISSING_RUN_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//MISSING_RUN_OR_START_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//INVALID_POWERMODE_RUN_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter];
				Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//INVALID_POWERMODE_RUN_START_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
				Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
			}

			ComAbsCtrl_Fault_Trigger = Flag_No_Fault;
		}

		// For RUN PowerMode Diag 
		if(ePwrMode_Run == ComAbsCtrl_IgnMode)
		{
			if ( ComAbsCtrl_Run_Trigger == Flag_Not_Run)
			{
				//START_MISSING_RUN_DIAG_YES_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
					Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
				}
			
				//invalid_run_diag_mode_yes - True
				//INVALID_POWERMODE_RUN_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter];
					Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)TRUE);
				}

				ComAbsCtrl_Run_Trigger = Flag_Run;
			}
		}
		else
		{
			if(ComAbsCtrl_Run_Trigger == Flag_Run)
			{
				//STOP_MISSING_RUN_DIAG_YES_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
					Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
				}

				//invalid_run_diag_mode_yes - False
				//INVALID_POWERMODE_RUN_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter];
					Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
				}

				ComAbsCtrl_Run_Trigger = Flag_Not_Run;
			}
		}

		//For RUN or START PowerMode Diag
		if(( ePwrMode_Run == ComAbsCtrl_IgnMode)|| (ePwrMode_Start == ComAbsCtrl_IgnMode))
		{
			if(ComAbsCtrl_Run_Start_Trigger == Flag_Not_Run_Start )
			{
				//START_MISSING_RUN_START_DIAG_YES_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
					Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
				}

				//invalid_run_start_diag_mode_yes - True
				//INVALID_POWERMODE_RUN_START_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
					Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)TRUE);
				}

				ComAbsCtrl_Run_Start_Trigger = Flag_Run_Start;
			}
		}
		else
		{
			if(ComAbsCtrl_Run_Start_Trigger == Flag_Run_Start )
			{
				//STOP_MISSING_RUN_START_DIAG_YES_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
					Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
				}

				//invalid_run_start_diag_mode_yes - False
				//INVALID_POWERMODE_RUN_START_ARRAY
				for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
				{
					RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
					Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
				}

				ComAbsCtrl_Run_Start_Trigger = Flag_Not_Run_Start;
			}
		}
	}

}

// Transition into RUN
static void ComAbsCtrl_TransIntoRun_DiagModeNo(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	
	//missing_run_diag_mode_no - True
	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	
	//invalid_run_diag_mode_no - True	
}

//Transition out of RUN
static void ComAbsCtrl_TransOutofRun_DiagModeNo(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;

	//missing_run_diag_mode_no - false
	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
	}

	//invalid_run_diag_mode_no - false
}

//Transition into RUN 0r START
static void ComAbsCtrl_TransIntoRunStart_DiagModeNo(void)
{
	
	//missing_run_start_diag_mode_no - True
	//MISSING_RUN_OR_START_DIAG_NO_ARRAY
	#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	/* missing counter restart processing for Run or Start array */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	#endif
	
	//invalid_run_start_diag_mode_no - True	
}

//Transition into OFF 0r ACC
static void ComAbsCtrl_TransIntoOffAcc_DiagModeNo(void)
{
	
	//missing_run_start_diag_mode_no - False
	//MISSING_RUN_OR_START_DIAG_NO_ARRAY
	#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	/* missing counter restart processing for Run or Start array */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
	}
	#endif
	
	//invalid_run_start_diag_mode_no - False	
}

	//---------------------------------------------------------------------------------------------------------------------

	/// @brief    Network Parameter Initialization upon reset
	///
	/// @param    None
	///
	/// @return   void
	//---------------------------------------------------------------------------------------------------------------------
static void ComAbsCtrl_BuffInit( void )
{
	/* All Init1 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;
	
	/* Reception buffer init */
    for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT1; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init1_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT2; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init2_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init2_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT3; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init3_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init3_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT4; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init4_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init4_Val_U32A[InitLoopCounter]) );
	}

	//Transmission buffer init 
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT1_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init1_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init1_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT2_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init2_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init2_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT3_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init3_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init3_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT4_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init4_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init4_Val_U32A[InitLoopCounter]) );
	}

	/* Never reced flag init */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT1_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init1_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT2_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init2_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init3_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT4_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init4_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(eDimLvlIn,(Boolean)TRUE);
	Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(eLitvalIn,(Boolean)TRUE);

}
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_PF2


	static void ComAbsCtrl_BuffInit( void )
	{
		/* All Init1 arrays are to be processed here */
		uint16 InitLoopCounter=0;
		tRxSignalId RxSigId;
		tTxSignalId TxSigId;
		/* Reception buffer init */
		for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_RX_INIT1); InitLoopCounter++)
		{
			RxSigId = (tRxSignalId)ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_Val_U32A[InitLoopCounter]) );
		}

		for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_RX_INIT1); InitLoopCounter++)
		{
			RxSigId = (tRxSignalId)ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);		
		}

		/* Transmission buffer init */
		for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_TX_INIT1_ARRAY); InitLoopCounter++)
		{
			TxSigId = (tTxSignalId)ComAbsCtrl_Tx_Init1_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_value_U32A[InitLoopCounter]) );
		}

	#ifdef COMABSCTRL_COMABSSAFE_EN

		#if ( MAX_ELEMENTS_IN_SAFE_RX_INIT1 > 0 )
		tRxSafeSignalId RxSafeSigId;

		/* Reception buffer init */
		for(InitLoopCounter = 0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_SAFE_RX_INIT1); InitLoopCounter++)
		{
			RxSafeSigId = (tRxSafeSignalId)ComAbsSafe_Rx_Init1_Array_U16A[InitLoopCounter];
			COMABSCTRL_COMABSSAFE_RxCan_SetSignalInitValue (RxSafeSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_Val_U32A[InitLoopCounter]) );
		}

		for(InitLoopCounter = 0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_SAFE_RX_INIT1); InitLoopCounter++)
		{
			RxSafeSigId = (tRxSafeSignalId)ComAbsSafe_Rx_Init1_Array_U16A[InitLoopCounter];
			COMABSCTRL_COMABSSAFE_RxCan_SignalNRProcessingControl(RxSafeSigId, (Boolean)TRUE);
		}
        #endif

		/* Transmission buffer init */
		#if ( MAX_ELEMENTS_IN_SAFE_TX_INIT1_ARRAY > 0)
		//tTxSafeSignalId TxSafeSigId;
		for(InitLoopCounter = 0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_SAFE_TX_INIT1_ARRAY); InitLoopCounter++)
		{
			TxSafeSigId = (tTxSafeSignalId)ComAbsSafe_Tx_Init1_U16A[InitLoopCounter];
			//COMABSCTRL_COMABSSAFE_TxCan_SetSignalValue(TxSafeSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_value_U32A[InitLoopCounter]) );
			(void)Rte_Call_rpCSTxCanSafe_TxCan_SetSignalValue(TxSafeSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_value_U32A[InitLoopCounter]) );
		}
		#endif

	#endif 

	}

	// Transition into RUN
static void ComAbsCtrl_StartMissingProcDuringRun(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	
	//missing_run_diag_mode_no - True
	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_RX_INIT1); InitLoopCounter++)
	{
		RxSigId = (tRxSignalId)ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	
	//invalid_run_diag_mode_no - True
#ifdef COMABSCTRL_COMABSSAFE_EN
    #if ( MAX_ELEMENTS_IN_SAFE_RX_INIT1 > 0 )
	tRxSafeSignalId RxSafeSigId;
	for(InitLoopCounter = 0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_SAFE_RX_INIT1); InitLoopCounter++)
	{
		RxSafeSigId = (tRxSafeSignalId)ComAbsSafe_Rx_Init1_Array_U16A[InitLoopCounter]; 
		COMABSCTRL_COMABSSAFE_RxCan_SignalMissingProcessingControl(RxSafeSigId,(Boolean)TRUE);
	}
	#endif
#endif	
}

static void ComAbsCtrl_StartNRProcDuringRun(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	
	//missing_run_diag_mode_no - True
	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_RX_INIT1); InitLoopCounter++)
	{
		RxSigId = (tRxSignalId)ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);	
	}
	
	//invalid_run_diag_mode_no - True
#ifdef COMABSCTRL_COMABSSAFE_EN
    #if ( MAX_ELEMENTS_IN_SAFE_RX_INIT1 > 0 )
	tRxSafeSignalId RxSafeSigId;
	for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_SAFE_RX_INIT1); InitLoopCounter++)
	{
		RxSafeSigId = (tRxSafeSignalId)ComAbsSafe_Rx_Init1_Array_U16A[InitLoopCounter]; 
		COMABSCTRL_COMABSSAFE_RxCan_SignalNRProcessingControl(RxSafeSigId, (Boolean)TRUE);
	}
	#endif
#endif
	
}

#ifdef COMABSCTRL_P61QR_INVALID_SIG_EN
static void ComAbsCtrl_StartInvaliSignalProcDuringRun(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;

	for(InitLoopCounter =0; InitLoopCounter<((uint16)MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_ARRAY); InitLoopCounter++)
	{
		RxSigId = (tRxSignalId)ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)TRUE);
	}
}
#endif
    #ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
		//Transition out of RUN
		static void ComAbsCtrl_StopMissingProcOtherThanRun(void)
		{
			uint16 InitLoopCounter=0;
			tRxSignalId RxSigId;

			//missing_run_diag_mode_no - false
			//MISSING_RUN_DIAG_NO_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT1; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Init1_Array_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
			}

			//invalid_run_diag_mode_no - false
		}
	#endif

#endif

//---------------------------------------------------------------------------------------------------------------------
// @brief:  	initialization state at battery connect
// @return: 	E_NOT_READY:    In progress. Keeps the component in this state.
//	   			E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit(void)
{
	ComAbsCtrl_NwControllerApp_Init();
	return E_OK;
}
//---------------------------------------------------------------------------------------------------------------------
// @brief:  	Transitional de-initialization state on battery off
// @return: 	E_NOT_READY:    In progress. Keeps the component in this state.
//				E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
//@ brief  	Transitional activation state upon wakeup
//@return: 	E_NOT_READY:    In progress. Keeps the component in this state.
//@		E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation(void)
{
    for (tRxSafeSignalId sig_id = 0U; sig_id < eEndOfSafeRxSignal; sig_id++)
    {
        OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl(sig_id, TRUE);
    }
    for (tRxSignalId sig_id = 0U; sig_id < eEndOfRxSignal; sig_id++)
    {
        CComAbsMdl_RxCan_SignalMissingProcessingControl(sig_id, TRUE);
        CComAbsMdl_RxCan_SignalNRProcessingControl(sig_id, TRUE);
    }
    return E_OK;
}
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
	//---------------------------------------------------------------------------------------------------------------------
	//	@brief:  		Network Parameter Initialization upon reset and wakeup
	//	@SRD reference:
	// 	@return :		None
	//
	// @SS NOTES: Called on Wakeup Init
	//---------------------------------------------------------------------------------------------------------------------
static void ComAbsCtrl_TxRxBuffInitWake( void )
{
	/* All Init2 and Init3 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;
	/* Reception buffer init */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT2; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init2_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init2_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT3; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init3_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init3_Val_U32A[InitLoopCounter]) );
	}

	/* Transmission buffer init */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT2_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init2_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init2_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT3_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init3_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init3_Val_U32A[InitLoopCounter]) );
	}

			
    /* Get buffered data for transmission */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT1_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init1_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(TxSigId);
	}
	
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT4_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init4_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(TxSigId);
	}


	/* Never reced flag init */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT2_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init2_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init3_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(eDimLvlIn,(Boolean)TRUE);
	Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(eLitvalIn,(Boolean)TRUE);
				
}
	//---------------------------------------------------------------------------------------------------------------------
	//  @Name:           ComAbsCtrl_TxRxBuffInitOnCond3Transition
	//	@brief:  		NR flag and Sig value would be initialize upon transition from  Off|Acc -> Run|Start
	//  @                Init Condition 3
	//	@SRD reference:	ID :
	// 	@return :		None
	//
	//
	//---------------------------------------------------------------------------
static void ComAbsCtrl_TxRxBuffInitOnCond3Transition(void )
{
    /* All Init3 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT3; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init3_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init3_Val_U32A[InitLoopCounter]) );
	}
    
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init3_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

    for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT3_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init3_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init3_Val_U32A[InitLoopCounter]) );
	}
}

	//---------------------------------------------------------------------------------------------------------------------
	//  @Name:           ComAbsCtrl_TxRxBuffInitOnCond4Transition
	//	@brief:  		NR flag and Sig value would be initialize upon transition from  Off|Acc -> Run|Start
	//  @                Init Condition 4
	//	@SRD reference:	ID :
	// 	@return :		None
	//
	//
	//---------------------------------------------------------------------------
static void ComAbsCtrl_TxRxBuffInitOnCond4Transition(void )
{
	/* All Init4 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INIT4; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init4_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init4_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT4_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init4_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

    for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_TX_INIT4_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init4_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init4_Val_U32A[InitLoopCounter]) );
	}
}

/*  =========================================================================== */
/*                                                                              */
/*  @Name:           ComAbsCtrl_PwrModeUnstableResetTimers                  */
/*                                                                              */
/*  @Description:     Function to reset missing & invalid timers                 */
/*                   when diag vehicle mode is unstable                         */
/*  @Inputs:          NULL                                                       */
/*                                                                              */
/*  @Returns:         NULL                                                       */
/*                                                                              */
/*  ============================================================================*/

static void ComAbsCtrl_PwrModeUnstableResetTimers(void)
{
	//do nothing
}
#endif
/*  =========================================================================== */
/*                                                                              */
/* @ Name:            ComAbsCtrl_CheckFaultCounterReset                                */
/*                                                                              */
/* @ Description:     Check for Diag Vehicle mode Stable/ Unstable - If          */
/* @                  Unstable restart missing and invalid timers                */
/* @ Inputs:          NULL                                                       */
/*                                                                              */
/* @ Returns:         NULL                                                       */
/*                                                                              */
// ==============================================================================*/
#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
static void ComAbsCtrl_CheckFaultCounterReset(void)
{

    /*************************************************************************
      @* Check FaultCounterReset - indirectly indicates PwrMode status.
 	 @*     - Yes indicates PwrMode is "unstable" and that CAN network fault
      @*	      counters should be restarted
 	 @*	    - No indicates PwrMode is "stable" and CAN network fault time
	 @    *       counters don't need to be restarted
     @ *  If Unstable restart restart missing and invalid timers
      ************************************************************************/
    if (ComAbsCtrl_FaultCounterReset == eFaultCounterResetYes)
    {
    	ComAbsCtrl_PwrModeUnstableResetTimers();
    }
}
///@brief   ComAbsCtrl specific specific system handler methods
static tpf_ComAbsCtrl_EventHandler_PwrModeChange const sEventHandlers_PwrModeChangeL[]=
{
    &ComAbsCtrl_EventHandler_PwrModeChange,
    (tpf_ComAbsCtrl_EventHandler_PwrModeChange)NULL
};

static tpf_ComAbsCtrl_EventHandler_ClearDTCEvent const sEventHandlers_ClearDTCEventL[]=
{
    &ComAbsCtrl_EventHandler_ClearDTCEvent,
    (tpf_ComAbsCtrl_EventHandler_ClearDTCEvent)NULL
};

//----------------------------------------------------------------------------------------------------------------------
/// @brief    Provides a reference to the ComAbsCtrl specific Event handler methods table
///
/// @param    void
///
/// @return   tppf_ComAbsCtrl_EventHandler
//----------------------------------------------------------------------------------------------------------------------
tppf_ComAbsCtrl_EventHandler_PwrModeChange ComAbsCtrl_GetEventHandlers_PwrModeChange (void)
{
    // Return a reference to the Event handler methods table
    return &sEventHandlers_PwrModeChangeL[0];
}


//tppf_ComAbsCtrl_EventHandler_PwrModeChange ComAbsCtrl_GetEventHandlers_ClearDTCEvent (void)
tppf_ComAbsCtrl_EventHandler_ClearDTCEvent ComAbsCtrl_GetEventHandlers_ClearDTCEvent (void)
{
    // Return a reference to the Event handler methods table
    return &sEventHandlers_ClearDTCEventL[0];
}
#endif

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
//----------------------------------------------------------------------------------------------------------------------
/// @brief    Provides a reference to the ComAbsCtrl specific Event handler
///
/// @param    tpComAbsCtrl_Context pCommon, <uint8 Data>
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
static void ComAbsCtrl_EventHandler_PwrModeChange(tpComAbsCtrl_Context pCommon, tPwrModeTrans Data)
{

    /* A powermode transition from Run->Start, Start->Run, Off->Acc, or Acc->Off */
	   if(ePwrGroupNoEvent == Data.GroupTrans)
	   {
		   if(ePwrMode_Run == Data.ExitMode)
    	   {
		        /* Reset flags when transitioned Out of RUN */
				ComAbsCtrl_TransOutofRun_DiagModeNo();  //Transition out of run
    	   }
	       /* Transition from Start to Run */
	       if(ePwrMode_Run == Data.EntryMode)
    	   {
		        /* Reset flags when transitioned to RUN */
				ComAbsCtrl_TransIntoRun_DiagModeNo(); //Transition into run
    	   }
	            /* Transition from Run to Start */
	       else if(ePwrMode_Start == Data.EntryMode)
	       {
	            /* Reset missing and Invalid flags on transition to RUN|Start */
		   ComAbsCtrl_TransIntoRunStart_DiagModeNo(); //Transition into run_or_start
	       }
	        /* Transition into Ign Acc */
	       else if(ePwrMode_Acc == Data.EntryMode)
	       {
		        /* condition 4 initialization */
	    	   /*  ComAbsCtrl_TxRxBuffInitOnCond4Transition();  */
	       }
	        else
	        {
					//TODO: Nothing
	        }
	   }
	   /* A powermode transition from Off|Acc -> Run|Start */
	   else if(eOffAcc_to_RunStart == Data.GroupTrans)
	   {
	       /* Reset missing and Invalid flags on transition to RUN|Start */
		   ComAbsCtrl_TransIntoRunStart_DiagModeNo(); //Transition into run_or_start
		#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
	      /* Reset NR flags and Init signal value on transition to RUN|Start  - Cond 3*/
		   ComAbsCtrl_TxRxBuffInitOnCond3Transition();
	       ComAbsCtrl_TxRxBuffInitOnCond4Transition();
		#endif
	      /* Transition into Ign Run */
	      if(ePwrMode_Run == Data.EntryMode)
	      {
		    /* Reset flags when transitioned to RUN */
			ComAbsCtrl_TransIntoRun_DiagModeNo(); //Transition into run
	      }

	     /* if transitioned from Off -> Run|Start, but not from Acc ->Run|Start*/
	      if(ePwrMode_Acc != Data.ExitMode)
	      {
	    	 /* ComAbsCtrl_TxRxBuffInitOnCond4Transition(); SRD HS Init4 updated */
	      }
	   }
	   /* A powermode transition from Run|Start -> Off|Acc */
	   else  if(eRunStart_to_OffAcc == Data.GroupTrans)
	   {
		   ComAbsCtrl_TransIntoIgnOff();
		   ComAbsCtrl_TransIntoOffAcc_DiagModeNo(); //Transition into off_or_acc
		   if(ePwrMode_Run == Data.ExitMode)
    	   {
		        /* Reset flags when transitioned Out of RUN */
				ComAbsCtrl_TransOutofRun_DiagModeNo();  //Transition out of run
    	   }
	   }
	   else 
	   {
		  //do nothing
	   }
}
static void ComAbsCtrl_TransIntoIgnOff(void)
{
#if 0
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;


	   /* Condition xxx init NR and Init */
	 /* Never reced flag init */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT1_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init1_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)FALSE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT2_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init2_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)FALSE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT3_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init3_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)FALSE);
	}

	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT4_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init4_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)FALSE);
	}
	   	/* missing counter stop processing for Run array */
		for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
		}
		/* missing counter stop processing for Run array */
		for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
		}

		/* Invalid counter stop processing for Run or Start array */
		for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Invalid_Pwr_mode_RUN_Or_Start_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId,(Boolean)FALSE);
		}

		#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY > 0)
		/* missing counter stop processing for Run or Start array */
		for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
		}
		#endif
		#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY > 0)
		/* missing counter stop processing for Run or Start array */
		for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
			Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
		}
		#endif
#endif
}
#endif

#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH

/*============================================================================
**
** @Function Name:      void ComAbsCtrl_GetIgnStartState(void)
**
** @Visibility:         This function is externally visible
**
** @Description:		   Return a status of TRUE if Ignition state is START
**
** @Inputs/Outputs:
**
** @Critical Section:   No
**
** @Created:
**
** @Updated:
**
**==========================================================================*/
uint8 ComAbsCtrl_GetIgnStartState(void)
{
	uint8 retVal = FALSE;

 	if ( ePwrMode_Start ==  ComAbsCtrl_IgnMode)
	{
		retVal = TRUE;
	}
	return (retVal);

}


/*============================================================================
**
** @Function Name:      void ComAbsCtrl_GetIgnRunState(void)
**
** @Visibility:         This function is externally visible
**
** @Description:		   Return a status of TRUE if Ignition state is RUN
**
** @Inputs/Outputs:
**
** @Critical Section:   No
**
** @Created:
**
**@ Updated:
**
**==========================================================================*/
uint8 ComAbsCtrl_GetIgnRunState(void)
{
	uint8 retVal = FALSE;

 	if ( ePwrMode_Run ==  ComAbsCtrl_IgnMode)
	{
		retVal = TRUE;
	}
	return (retVal);
}

/*============================================================================
**
** @Function Name:      void ComAbsCtrl_GetIgnIgnState(void)
**
** @Visibility:         This function is externally visible
**
** @Description:		Return a status of TRUE if Ignition state is IGN
**
** @Inputs/Outputs:
**
** @Critical Section:   No
**
** @Created:
**
**@ Updated:
**
**==========================================================================*/
uint8 ComAbsCtrl_GetIgnIgnState(void)
{
	uint8 retVal = FALSE;

 	if (ePwrMode_Ignition ==  ComAbsCtrl_IgnMode)
	{
		retVal = TRUE;
	}
	return (retVal);
}
#endif

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
//----------------------------------------------------------------------------------------------------------------------
/// @brief    Calls (in sequence) the ComAbsCtrl specific asynchronous event handlers.
///
/// @param    tpComAbsCtrl_Context const pThis
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
static void HandleEvents(tpComAbsCtrl_Context pThis)
{

/*Ford_App.Autocode.Begin.HandleEvents*/
    // A reference to the event handler methods table
    tppf_ComAbsCtrl_EventHandler_PwrModeChange pHandleL = ComAbsCtrl_GetEventHandlers_PwrModeChange();
    // Rte call error code
    Std_ReturnType ErrorCodeL;

	tppf_ComAbsCtrl_EventHandler_ClearDTCEvent pHandleL1 = ComAbsCtrl_GetEventHandlers_ClearDTCEvent();
    tClearDTC Instance1L;

    // Handle event - <Power_Event::PwrModeChange>

        tPwrModeTrans InstanceL;
    ErrorCodeL = Rte_Receive_rpSRPowerEvent_PwrModeChange(&InstanceL);
    if((RTE_E_OK == ErrorCodeL) || (RTE_E_LOST_DATA == ErrorCodeL))
    {
        while(*pHandleL != NULL)
        {
            (**pHandleL)(pThis,InstanceL);
            pHandleL++;
        }
    }
    // Handle event - <DTC Event::Clear DTCs - Service $14>

    ErrorCodeL = Rte_Receive_DiagnosticsEvent_SR_ClearDTCEvent(&Instance1L);
    if((RTE_E_OK == ErrorCodeL) || (RTE_E_LOST_DATA == ErrorCodeL))
    {
        while(*pHandleL1 != NULL)
        {
            (**pHandleL1)(pThis,Instance1L);
            pHandleL1++;
        }
    }
/*Ford_App.Autocode.End.HandleEvents*/
}

static void ComAbsCtrl_EventHandler_ClearDTCEvent(tpComAbsCtrl_Context pCommon, tClearDTC ClearDTCEvent)
{
#if 0
    uint16 BuffInitIndex;

	for(BuffInitIndex=0;BuffInitIndex < (uint16)EndOfRxSignalList;BuffInitIndex++)
	{
		CanMdl_ReloadMissingCounter(BuffInitIndex);
		CanMdl_ReloadInvalidCounter(BuffInitIndex);
		CanMdl_RxBuffer[BuffInitIndex].IsVSiglMissing = cNO_ITS_NOT;
		CanMdl_RxBuffer[BuffInitIndex].IsVSiglInvalid = cNO_ITS_NOT;
	}
	ClearDTCTimers();
#endif

}
//---------------------------------------------------------------------------------------------------------------------
// @brief:  			1.5 sec Timer Handling For Network Mode Processing
// @SRD reference:	ID :
// @return:			None
//---------------------------------------------------------------------------------------------------------------------
static void ComAbsCtrl_CanNetModeTimerProcess( void )
{
#if 0
 	ComM_ModeType GetComMode;


// 	ComMStatus = GET_CANNM_CURRENTMODE(&GetComMode);
 	GET_CANNM_CURRENTMODE(&GetComMode);
   //	if(E_OK == ComMStatus)
   //	{
 		if(COMM_FULL_COMMUNICATION == GetComMode)
 	 	{
 			/* validate the CAN network mode transition and does initialize Missing, Invalid and NR flag */
 			if(ComAbsCtrl_IsCanNMTransToNetWorkMode != cMODETRANSSUCCESS)
 			{
 				ComAbsCtrl_IsCanNMTransToNetWorkMode = cMODETRANSSUCCESS;
 			}

 			/* Start decrement 1.5seconds timer */
 			if(ComAbsCtrl_NetModeCnt > cCANNMSIGPROCWAITTIMER_EXPIRED)
 			{
 				ComAbsCtrl_NetModeCnt--;
 			}
 		}
 		else
 		{
 			ComAbsCtrl_NetModeCnt = cCANNM_SIGPROCWAITTIMER;
 			ComAbsCtrl_IsCanNMTransToNetWorkMode = cMODETRANSFAIL;
 		}
 	//}
#endif

}

#if 0
//---------------------------------------------------------------------------------------------------------------------
// brief:  			Validate the each signal missing status provided, if missing applicable
// SRD reference:	ID :
// return:			None
//---------------------------------------------------------------------------------------------------------------------
static Boolean ComAbsCtrl_GetProcesAllowedMode( uint16 AllowedModeIndex )
{
 	Boolean IsModeOkay;

 	if(cRxProcessBuf[AllowedModeIndex].IsAllowedMode != PROCESSINNETWORKMODE)
 	{
 		/* If allowed mode is RUN, then return "CanMdl_IsIgnTransToRun" status */
 		IsModeOkay = ComAbsCtrlIsIgnTransToRun;
 	}
 	else
 	{
 		/* If allowed mode is CAN NM, then return "CanMdl_IsCanNMTransToNetWorkMode" status */
 		IsModeOkay = ComAbsCtrlIsCanNMTransToNetWorkMode;
 	}

 	return(IsModeOkay);
}
#endif



/*============================================================================
**
** @Function Name:      void ComAbsCtrl_GetIgnStartState(void)
**
** @Visibility:         This function is externally visible
**
** @Description:		   Return a status of TRUE if Ignition state is START
**
** @Inputs/Outputs:
**
** @Critical Section:   No
**
** @Created:
**
** @Updated:
**
**==========================================================================*/
uint8 ComAbsCtrl_GetIgnStartState(void)
{
	uint8 retVal = FALSE;

 	if ( ePwrMode_Start ==  ComAbsCtrl_IgnMode)
	{
		retVal = TRUE;
	}
	return (retVal);

}


/*============================================================================
**
** @Function Name:      void ComAbsCtrl_GetIgnRunState(void)
**
** @Visibility:         This function is externally visible
**
** @Description:		   Return a status of TRUE if Ignition state is RUN
**
** @Inputs/Outputs:
**
** @Critical Section:   No
**
** @Created:
**
**@ Updated:
**
**==========================================================================*/
uint8 ComAbsCtrl_GetIgnRunState(void)
{
	uint8 retVal = FALSE;

 	if ( ePwrMode_Run ==  ComAbsCtrl_IgnMode)
	{
		retVal = TRUE;
	}
	return (retVal);
}
#if 0
//----------------------------------------------------------------------------------------------------------------------
/// @brief    The public ComAbsCtrl main method. It shall be periodically executed in a specific OS task context.
///
/// @param    void
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
void CComAbsCtrl_Impl_MainFunction(void)
{

    // Locals
    static tAppModeActionsList const sActionsListL = { CmpDeInit, CmpInit, CmpActivation, CmpDeActivation, CmpActive };
    tAppModeManagementContext sContextL;

    // Read the requested and actual modes
    Rte_Read_AppModeRequest_SR_RequestedMode(&sContextL.RequestedMode);
    Rte_Read_AppModeStatus_ComAbsCtrl_SR_ActualMode(&sContextL.ActualMode);

    // Execute the common application main method
    (void)AppModeLib_Main(&sContextL, &sActionsListL);

    // Publish the application mode status data - Right now Sleep inhibit conditions are set as Inactive
    Rte_Write_AppModeStatus_ComAbsCtrl_SR_InhibitLocalSleep(eInhibitLocalSleep_0_Inactive);
    Rte_Write_AppModeStatus_ComAbsCtrl_SR_ActualMode(sContextL.ActualMode);



}
#endif
#endif

//---------------------------------------------------------------------------------------------------------------------
// brief  State for normal operations
// return: 	E_NOT_READY:    In progress. Keeps the component in this state.
//			E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
	#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
        mLocalContext();
	#endif
	ComAbsCtrl_Input();
	ComAbsCtrl_NwControllerApp_Sleep_Wakeup_Process(ComAbsCtrl_IgnMode);

#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH
    NetworkDTC_Active();
	ComAbsCtrl_E2E_MainFunction();
#endif

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
	ComAbsCtrl_CanNetModeTimerProcess();
    HandleEvents(&sContextL);       // Handle the ComAbsCtrl specific required events
	#ifndef COMABSCTRL_DTC_NOT_IMPLEMENTED_V1
    NetworkDTC_Active();
	#endif
	ComAbsCtrl_CheckFaultCounterReset();
	ComAbsCtrl_FaultCounterReset_Processing();
#endif
#ifdef COMABSCTRL_SIG_PROCESSING_PF2
	ComAbsCtrl_StartMissingProcDuringRun();
#endif
#ifdef COMABSCTRL_P61QR_INVALID_SIG_EN
	ComAbsCtrl_StartInvaliSignalProcDuringRun();
#endif

#ifdef COMABSCTRL_TESTCODE_FOR_MISSING
ComAbsCtrl_TestCodeForMissing();
#endif
#ifdef COMABSCTRL_38XD_PROGRAM_SPECIFIC_HS_INIT
	ComAbsCtrl_BuffInit_IGR_BSP();
	#if 0
	ComAbsCtrl_IgnMissingProcessing();
	#endif
	ComAbsCtrl_CANHWError_Handling();
#endif
    return E_OK;
}

void CComAbsCtrl_CmpMain(void)
{
    ComAbsCtrl_NwControllerApp_ProcessAliveTimer();	
}
#ifndef COMABSCTRL_COMEXT_APINOTAVAILABLE
/* Request and Release CAN Network */
void ComAbsCtrl_SetNetworkComMode(tNetworkComMode Mode)
{
 	if (Mode != eReleaseCom)
 	{
       (void)Rte_Call_rpCSComMExt_CAN_RequestCommunication(0);
     }
 	else
 	{
	   (void)Rte_Call_rpCSComMExt_CAN_ReleaseCommunication(0);
 	}
}
#endif
/********************************************************************************************************************
*   @brief     Diagnostic state
*   @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
*   br>     E_NOT_READY:    Keeps the component in this state.
********************************************************************************************************************/
static Std_ReturnType CmpDiag( void )
{
     return E_OK;
}
/********************************************************************************************************************
*   @brief     Transitional state to clean up after diagnostic state. Component behavior to be restored.
*   @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
*   <br>     E_NOT_READY:    Keeps the component in this state.
********************************************************************************************************************/
static Std_ReturnType CmpDiagReturn( void )
{
     return E_OK;
}
/********************************************************************************************************************
*   @brief     Transitional de-activation  state
*   @return E_OK:           Succeed
*   <br>     E_NOT_READY:    In progress. Keeps the component in this state.
*   <br>     E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDeActivation( void )
{
     return  E_OK;
}
#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH

/********************************************************************************************************************
*   @brief    E2E fault check processing
*   @SRD reference:	ID :
*   <br>     FALSE: E2E Fault check not enabled
*   <br>     TRUE: E2E Fault check enabled
********************************************************************************************************************/
boolean ComAbsCtrl_E2E_FaultCheck_Enabled(void)
{
	static boolean E2E_Fault_Status = FALSE;
	static boolean E2E_previous_fault_status = FALSE;	
	boolean canmdl_lvsd0 =FALSE;
	boolean canmdl_hvsd0 =FALSE;

	GET_LVSD0(&canmdl_lvsd0);  
	GET_HVSD0(&canmdl_hvsd0); 

//VOPS Config- Not Applicable for HD
//HDA9928807-6017 : epowerMode condition not required for E2E_Fault_Status.
	//if((ePwrMode_Run == ComAbsCtrl_IgnMode)||(ePwrMode_Ignition == ComAbsCtrl_IgnMode))
	//{
		if(( canmdl_lvsd0 == FALSE)&&(canmdl_hvsd0 == FALSE))//Normal operating voltage
		{
			E2E_Fault_Status = TRUE;
		}
		else
		{
			E2E_Fault_Status= FALSE;
		}
	
	//}
	//else
	//{
	// 	E2E_Fault_Status= FALSE;	
	//}
	if ((E2E_previous_fault_status == FALSE) && (E2E_Fault_Status == TRUE))
	{
		CComAbsSafe_Init_B_WU_Diag_DisRx_E2Efaultno_to_yes();
	}
	else
	{
		//Do Nothing
	}

	E2E_previous_fault_status= E2E_Fault_Status;
	return E2E_Fault_Status;
}

/********************************************************************************************************************
*   @brief    To initialise ComAbs variables based on power transitions, E2E fault status
*   @SRD reference:	ID :
*   @return:			None   
********************************************************************************************************************/
static void ComAbsCtrl_Variables_Initialise(void)
{
	static uint8 ignon_counter =0;
	static uint8 ign_off_sleep_counter=0;
	if((ePwrMode_Off == ComAbsCtrl_IgnMode) || (ePwrMode_Sleep == ComAbsCtrl_IgnMode))
	{
		if(ign_off_sleep_counter == 0)
		{
			CComAbsSafe_Init_B_WU_Diag_DisRx_Pwrmodetransition_to_Off_Sleep();
			ign_off_sleep_counter++;
			ignon_counter =0;
		}
		else
		{
			//do nothing
		}
	}
	else if(ePwrMode_Ignition == ComAbsCtrl_IgnMode)
	{
		if (ignon_counter == 0)
		{
			CComAbsSafe_Init_B_WU_Diag_DisRx_Pwrmodetransition_to_Ign();
			ign_off_sleep_counter=0;
			ignon_counter++;
		}
		else
		{
			//do nothing
		}
	}
	else
	{
		ign_off_sleep_counter=0;
		ignon_counter=0;
	}

}
/********************************************************************************************************************
*   @brief    Main function call for E2E Processing
*   @SRD reference:	ID :
*   @return:			None   
********************************************************************************************************************/
static void ComAbsCtrl_E2E_MainFunction(void)
{
	ComAbsCtrl_Variables_Initialise();
	ComAbsCtrl_E2E_FaultCheck_Enabled();
}
#endif

#ifdef COMABSCTRL_38XD_PROGRAM_SPECIFIC_HS_INIT
	//---------------------------------------------------------------------------------------------------------------------

	/// @brief    Network Parameter Initialization upon reset
	///
	/// @param    None
	///
	/// @return   void
	//---------------------------------------------------------------------------------------------------------------------
static void ComAbsCtrl_BuffInit( void )
{
	/* All Init1 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if ((SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0) || \
	     (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0) || \
		 (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0) || \
		 (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0))
			tRxSafeSignalId Safety_RxSigId;
	#endif
#endif	
	/* Reception buffer init VCAN */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}

	#if(MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
		}
	#endif

	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
		}
	#endif
#endif
	
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	//Transmission buffer init VCAN
	#if(MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BA_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BA_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_B_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_B_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_B_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}

	#if(MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BSP_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
	/* Reception buffer init MCAN */
	#if (MAX_ELEMENTS_IN_RX_INIT_BA_MCAN > 0)
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
    
	#if (MAX_ELEMENTS_IN_RX_INIT_B_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}

	#if(MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	//Transmission buffer init MCAN
	#if(MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BA_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BA_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
    
	#if(MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_B_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_B_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
    
	#if(MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	#if(MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BSP_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BSP_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BSP_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	/* Never reced flag init - VCAN */
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BA_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_B_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
	#endif
	#if(SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
	#endif
#endif
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

    /* Never reced flag init - MCAN */
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BA_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

    #if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_B_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BSP_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	#if(MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN > 0)
	for(InitLoopCounter =0; InitLoopCounter < (uint16)MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Invalid_PWRMode_Run_U16A[InitLoopCounter];
        Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	#if(MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START > 0)
	for(InitLoopCounter =0; InitLoopCounter < (uint16)MAX_ELEMENTS_IN_RX_INVALID_PWR_MODE_RUN_OR_START; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Invalid_PWRMode_RunOrStart_U16A[InitLoopCounter];
        Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

}

#if 0
static void ComAbsCtrl_MissingProcessing_on_Activation(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;

	//MISSING_RUN_DIAG_YES_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}

	#if (MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY > 0)
	//MISSING_RUN_DIAG_NO_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_No_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	#endif

	//MISSING_RUN_OR_START_DIAG_YES_ARRAY
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}

	//MISSING_RUN_OR_START_DIAG_NO_ARRAY
	#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
	/* missing counter restart processing for Run or Start array */
	for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
		Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
	}
	#endif

}

// Missing processing for applicable Signals
static void ComAbsCtrl_IgnMissingProcessing(void)
{
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	static boolean ComAbsCtrl_PowerOnExec = FALSE;
	
	// For RUN or Start PowerMode Diag 
	if(ePwrMode_Run == ComAbsCtrl_IgnMode)
	{
		if ( ComAbsCtrl_Run_Trigger == Flag_Not_Run)
		{
			//START_MISSING_RUN_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
			}
			
			//START_MISSING_RUN_START_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
			}
			
			//MISSING_RUN_OR_START_DIAG_NO_ARRAY
			#if  (MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY > 0)
			/* missing counter restart processing for Run or Start array */
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_RX_MISSING_PWR_MODE_RUN_OR_START_DIAG_MODE_NO_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Or_Start_DM_No_U16A[InitLoopCounter];
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)TRUE);
				ComAbsCtrl_CanMdl_ReloadMissingTimer(RxSigId);
			}
			#endif

			ComAbsCtrl_Run_Trigger = Flag_Run;
		}
		
	}
	else
	{
		if(ComAbsCtrl_Run_Trigger == Flag_Run)
		{
			//STOP_MISSING_RUN_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
				ComAbsCtrl_CanMdl_ReloadMissingTimer(RxSigId);
			}

			ComAbsCtrl_Run_Trigger = Flag_Not_Run;
		}
		else if(FALSE == ComAbsCtrl_PowerOnExec)
		{
			//STOP_MISSING_RUN_DIAG_YES_ARRAY
			for(InitLoopCounter =0; InitLoopCounter<MAX_ELEMENTS_IN_MISSING_RUN_DIAG_MODE_YES_ARRAY; InitLoopCounter++)
			{
				RxSigId = ComAbsCtrl_Rx_Missing_Pwr_mode_RUN_Diag_Mode_Yes_U16A[InitLoopCounter]; 
				Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(RxSigId,(Boolean)FALSE);
				ComAbsCtrl_CanMdl_ReloadMissingTimer(RxSigId);
			}

			ComAbsCtrl_PowerOnExec = TRUE;
		}
		else
		{
			/* Do Nothing*/
		}
	}
}
#endif

static void ComAbsCtrl_BuffInit_IGR_BSP(void)
{
	static tPwrModeState ComAbsCtrl_IgnModePrevVal = ePwrMode_Off;
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	
	if((ePwrMode_Off == ComAbsCtrl_IgnModePrevVal) && (ePwrMode_Run == ComAbsCtrl_IgnMode))
	{
		ComAbsCtrl_TxRxBuffInitOnCond3Transition();
		//VCAN
		#if(MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
		}
		#endif

        #if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
		}
		#endif

	#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
		tRxSafeSignalId Safety_RxSigId;
		#if(SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
			for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
			{
				Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
				(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
			}
		#endif

        #if(SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
		#endif
	#endif

		//MCAN
		#if(MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_Rx_Init_BSP_MCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_MCAN_Val_U32A[InitLoopCounter]) );
		}
		#endif

		#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY; InitLoopCounter++)
		{
			RxSigId = ComAbsCtrl_NVR_Init_BSP_MCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
		}
		#endif

	}
	else if((ePwrMode_Run == ComAbsCtrl_IgnModePrevVal) && (ePwrMode_Off == ComAbsCtrl_IgnMode))
	{
		ComAbsCtrl_TxRxBuffInitOnCond3Transition();
	}
	else
	{
		/*Do Nothing*/
	}
	ComAbsCtrl_IgnModePrevVal = ComAbsCtrl_IgnMode;
}

void ComAbsCtrl_ComMExtBuffInit(void)
{
	ComAbsCtrl_BuffInit();
}

void ComAbsCtrl_ComMExtACCIGRInit(void)
{
	uint16 InitLoopCounter=0;
	tTxSignalId TxSigId;
	tRxSignalId RxSigId;
	
	//VCAN
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INITACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_InitACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	//MCAN
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

    #if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
}

void ComAbsCtrl_ComMExtACCIGR_Rx_Init(void)
{
	uint16 InitLoopCounter=0;
	tTxSignalId TxSigId;
	tRxSignalId RxSigId;
	
	//VCAN
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ValZero_s32) );
	}
	#endif

	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

    //MCAN
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
    #if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
}

static void ComAbsCtrl_TxRxBuffInitWake( void )
{
	/* All Init2 and Init3 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if ((SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0) || \
	     (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0) || \
	     (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0) || \
		 (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0))
		 	tRxSafeSignalId Safety_RxSigId;
	#endif
#endif

	/* Reception buffer init VCAN*/
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	
	#if(MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
		}
	#endif
	
	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
		}
	#endif
#endif
	
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	/* Transmission buffer init VCAN */
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_B_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_B_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_B_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	
	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	/* Reception buffer init MCAN*/
	#if(MAX_ELEMENTS_IN_RX_INIT_B_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	
	#if(MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	/* Transmission buffer init MCAN */
	#if(MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_B_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_B_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_B_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	
	#if(MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

    /* Never reced flag init -VCAN*/
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_B_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
	#if (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
	#endif
	
	#if(SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_BSP_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
	#endif
#endif
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	/* Never reced flag init -MCAN*/
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_B_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_B_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BSP_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BSP_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_ACCIGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_ACCIGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif
}
	//---------------------------------------------------------------------------------------------------------------------
	//  @Name:           ComAbsCtrl_TxRxBuffInitOnCond3Transition
	//	@brief:  		NR flag and Sig value would be initialize upon transition from  Off|Acc -> Run|Start
	//  @                Init Condition 3
	//	@SRD reference:	ID :
	// 	@return :		None
	//
	//
	//---------------------------------------------------------------------------
static void ComAbsCtrl_TxRxBuffInitOnCond3Transition(void )
{
    /* All Init3 arrays are to be processed here */
	uint16 InitLoopCounter=0;
	tRxSignalId RxSigId;
	tTxSignalId TxSigId;

    //VCAN
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
	}

#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
    tRxSafeSignalId Safety_RxSigId;
	#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
		}
	#endif

    #if (SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY > 0)
		for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_VCAN_ARRAY; InitLoopCounter++)
		{
			Safety_RxSigId = ComAbsCtrl_Safety_NVR_Init_IGR_VCAN_U16A[InitLoopCounter];
			(void)Rte_Call_rpCSRxCanSafe_RxCan_SignalNRProcessingControl(Safety_RxSigId, (Boolean)TRUE);
		}
	#endif
#endif

    //MCAN
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}

	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_IGR_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_IGR_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
	}
}

void ComAbsCtrl_ComMExtBAInit(void)
{
	uint16 InitLoopCounter=0;
	tTxSignalId TxSigId;
	tRxSignalId RxSigId;
	
	/* Reception buffer init VCAN*/
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_VCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_VCAN_Val_U32A[InitLoopCounter]) );
	}

	/* Never reced flag init VCAN*/
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_VCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BA_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}

#if ((MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_ARRAY > 0) && (MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_VALUE_ARRAY > 0))
	//Transmission buffer init VCAN
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BA_VCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BA_VCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BA_VCAN_Val_U32A[InitLoopCounter]) );
	}
#endif

	/* Reception buffer init MCAN*/
	#if (MAX_ELEMENTS_IN_RX_INIT_BA_MCAN > 0)
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_MCAN_Array_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_MCAN_Val_U32A[InitLoopCounter]) );
	}
	#endif

	/* Never reced flag init MCAN*/
	#if(MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY > 0)
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_NEVER_RECEIVED_RESET_INIT_BA_MCAN_ARRAY; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_NVR_Init_BA_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(RxSigId, (Boolean)TRUE);
	}
	#endif

#if ((MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY > 0) && (MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_VALUE_ARRAY > 0))
	//Transmission buffer init MCAN
	for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_TX_INIT_BA_MCAN_ARRAY; InitLoopCounter++)
	{
		TxSigId = ComAbsCtrl_Tx_Init_BA_MCAN_U16A[InitLoopCounter];
		(void)Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(TxSigId, ((uint8 *)&ComAbsCtrl_Tx_Init_BA_MCAN_Val_U32A[InitLoopCounter]) );
	}
#endif
}

/*!***************************************************************************************************************
**
** @brief  CAN Hardware Error handling. Reception buffer init for signals with Fail Safe value = NA.
**However error handling for Signals with Failsafe_value != NA are taken care in ComAbsMdl function CComAbsMdl_RxCan_GetSignalValue()
**
*****************************************************************************************************************/
static void ComAbsCtrl_CANHWError_Handling(void)
{
	boolean lVCAN_HWERRORStatus; 
	boolean lMCAN_HWERRORStatus;
	Std_ReturnType lMissing_OW_BIT_status;
	uint16 InitLoopCounter = (uint16)0;
	tRxSignalId RxSigId;

	ComAbsCtrl_ComMExt_GetVCANHWErrorSts(&lVCAN_HWERRORStatus);
	ComAbsCtrl_ComMExt_GetMCANHWErrorSts(&lMCAN_HWERRORStatus);
    
/*VCAN*/
	if(FALSE != lVCAN_HWERRORStatus)
	{
	/* Power domain BA_VCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_VCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_VCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
	    ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}

	/* Power domain B_VCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_VCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_VCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}

	/* Power domain IGR_VCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}

    #if(MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
	/* Power domain BSP_VCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}
	#endif
	
	#ifdef COMABSCTRL_38XD_SAFETYADAPTER_EN
		tRxSafeSignalId Safety_RxSigId;
		boolean lSafety_Missing_OW_BIT_status;
		#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN > 0)
			/* Power domain IGR_VCAN: */
			for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_IGR_VCAN; InitLoopCounter++)
			{
				Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Array_U16A[InitLoopCounter];
				lSafety_Missing_OW_BIT_status = ComAbsCtrl_Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus(Safety_RxSigId);	//Replace after RTE iteration

				if((boolean)E_OK != lSafety_Missing_OW_BIT_status)
				{
					(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_IGR_VCAN_Val_U32A[InitLoopCounter]) );
					lSafety_Missing_OW_BIT_status = (boolean)E_OK;
				}
				ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
			}
		#endif

		#if (SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN > 0)
			/* Power domain BSP_VCAN: */
			for(InitLoopCounter =0; InitLoopCounter<(uint16)SAFETY_MAX_ELEMENTS_IN_RX_INIT_BSP_VCAN; InitLoopCounter++)
			{
				Safety_RxSigId = ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Array_U16A[InitLoopCounter];
				lSafety_Missing_OW_BIT_status = ComAbsCtrl_Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus(Safety_RxSigId);	//Replace after RTE iteration

				if((boolean)E_OK != lSafety_Missing_OW_BIT_status)
				{
					(void)Rte_Call_rpCSRxCanSafe_RxCan_SetSignalInitValue(Safety_RxSigId, ((uint8 *)&ComAbsCtrl_Safety_Rx_Init_BSP_VCAN_Val_U32A[InitLoopCounter]) );
					lSafety_Missing_OW_BIT_status = (boolean)E_OK;
				}
				ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
			}
		#endif	
	#endif

	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN > 0)	
	/* Power domain ACCIGR_VCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_VCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_VCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}	
	#endif
	}

/*MCAN*/
    if(FALSE != lMCAN_HWERRORStatus)
	{
	/* Power domain BA_MCAN: */
	#if(MAX_ELEMENTS_IN_RX_INIT_BA_MCAN > 0)
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BA_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BA_MCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BA_MCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}
	#endif

	/* Power domain B_MCAN: */
	#if(MAX_ELEMENTS_IN_RX_INIT_B_MCAN > 0)
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_B_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_B_MCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_B_MCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}
    #endif

	/* Power domain IGR_MCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_IGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_IGR_MCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_IGR_MCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}

    #if(MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN > 0)
	/* Power domain BSP_MCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_BSP_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_BSP_MCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_BSP_MCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}
	#endif
	
	#if(MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN > 0)	
	/* Power domain ACCIGR_MCAN: */
    for(InitLoopCounter =0; InitLoopCounter<(uint16)MAX_ELEMENTS_IN_RX_INIT_ACCIGR_MCAN; InitLoopCounter++)
	{
		RxSigId = ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Array_U16A[InitLoopCounter];
        lMissing_OW_BIT_status = (uint8)ComAbsCtrl_ComAbsMdl_GetRXCAN_MissingOW_BITstatus(RxSigId);

		if((uint8)E_OK != lMissing_OW_BIT_status)
		{
            (void)Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(RxSigId, ((uint8 *)&ComAbsCtrl_Rx_Init_ACCIGR_MCAN_Val_U32A[InitLoopCounter]) );
			lMissing_OW_BIT_status = (uint8)E_OK;
		}
		ComAbsCtrl_ComAbsMdlSetMissingandNRStatus(RxSigId, (boolean)(TRUE));
	}	
	#endif
	}	

}
#endif

/*End of File*/ 
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :15/Aug/2020
By                :bjayara2
Traceability      : 1006237: Comabs - ComAbsCtrl Automation -
                   Python scripts for collecting all elements -Init1, Init2,
                    Init3, Init4,
                    pwr modes,init values for Tx and Rx signals
Change Description:Ford Bx755 Initial version
******************************************************************************/
