/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Resetsleepdiagcdd_cfg.c
**
** Description:    contains configurable functions to call RTE /API for each service
**                 
**
**===================================================================================================================*/

#ifndef RESETSLEEPDIAGCDD_CFG_C
#define RESETSLEEPDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mcu.h"
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Resetsleepdiagcdd_cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
/*
#ifdef WDRESET_VIP_GIP_SUPPORT
static Std_ReturnType WatchDogReset_ctrl_GIP(uint8* Data, uint8 *ErrorCode);

static GIPDataRquestState Resetsleepdiag_CurrentGIPState = eGIP_InitiateRequest;
#endif
*/
#ifdef RSTCNTRREADINGENABLE
static Std_ReturnType ResetSleepDiag_RstCntrReading_Read(uint8* Data);
static Std_ReturnType ResetSleepDiag_RstCntrReading_Write(uint8* Data);
#endif

#ifdef SLEEPMODEENABLE
static void ResetSleepDiag_SlpReq_Write(void);
#endif

#ifdef LOWQCURRENTENABLE
static Std_ReturnType ResetSleepDiag_SlpReq_SetLowQCurrent(uint8* Data);
#endif

#ifdef RESETSLEEPDIAG_ODOMETER_RESET
static uint8 ResetSleepDiag_Odo_Reset(uint8* Data);
static uint8 odoResetCount = 0U;
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef RSTCNTRREADINGENABLE
const ResetSleepDiag_ReadWrite_U8 RstCntrReadingConfig_U8=
{
    &ResetSleepDiag_RstCntrReading_Read,&ResetSleepDiag_RstCntrReading_Write,
};
#endif

#ifdef WDRESET_VIP_GIP_SUPPORT
const WatchDogReset_control WatchDogReset_control_Config=
{
    &WatchDogReset_ctrl_GIP,
};
#endif

#ifdef SLEEPMODEENABLE
const ResetSleepDiag_ReadWrite SlpReqConfig=
{
    &ResetSleepDiag_SlpReq_Write,
};
#endif

#ifdef LOWQCURRENTENABLE
const ResetSleepDiag_ReadWrite_U8 LowQCurrentConfig=
{
    NULL_PTR, &ResetSleepDiag_SlpReq_SetLowQCurrent,
};
#endif

#ifdef RESETSLEEPDIAG_ODOMETER_RESET
const ResetSleepDiag_Odo_Rst ResetSleepDiag_Odo_Reset_Config = 
{
    &ResetSleepDiag_Odo_Reset,
};
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef WDRESET_VIP_GIP_SUPPORT
static Std_ReturnType WatchDogReset_ctrl_GIP(uint8 *Data, uint8 *ErrorCode)
{
	
	Std_ReturnType ret = E_NOT_OK;
	MeetDiagReqType DiagReq; 
    
   DiagReq.ActionP   = DiagActionType_RoutineCtrl;
   DiagReq.ServiceId = cIOC_WatchdogRstControl;
   DiagReq.LengthP  = cIOC_WatchdogRstControl_DataLength+1;
   DiagReq.DataP[0] = MGRDIAGCDD_ROC_START_ACTION;
   DiagReq.DataP[1] = Data[0];
  
   switch(Resetsleepdiag_CurrentGIPState)
   {
       case eGIP_InitiateRequest:
          ret = Meet_Process_Gip_Diag_Request(Resetsleepdiag_CurrentGIPState, &DiagReq, ErrorCode);
          Resetsleepdiag_CurrentGIPState = eGIP_WaitForResponse;
          break;
       case eGIP_WaitForResponse:
          ret = Meet_Process_Gip_Diag_Request(Resetsleepdiag_CurrentGIPState, &DiagReq, ErrorCode);
          if(ret != DCM_E_PENDING)
          {
             Resetsleepdiag_CurrentGIPState = eGIP_InitiateRequest;
          }
         break;
       default:
    	 /*No action required*/
         break;
   }
    return ret;			
}

#endif

#ifdef RSTCNTRREADINGENABLE
/*=====================================================================================================================
**
** Function Name    :  Set_Rst_Cnt 
**
** Visibility       :  Public 
**
** Description      :  reads the last reset reason during Initialisation and increments the corresponsing counter by 1
**                     (Implemented as per J59 Spec)
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  NA
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Set_Rst_Cnt(void)
{
	uint32 OtherResetCount = 0UL;
    boolean MfgModeActive=0U;  // coverity fix
	uint8 cnt;
	uint32 ResetRawReason;
    Mcu_ResetType RstReason;
    uint8 NvmData[RSTCNTRDATALEN]={0};
    MGRDIAG_GET_SESSION(&MfgModeActive);
    
    if(MfgModeActive == MEET_SESSION)
    {
		ResetRawReason = Mcu_GetResetRawValue();
        RstReason = Mcu_GetResetReason();
        (void)RstCntrReadingConfig_U8.ResetSleepDiag_Read(NvmData); /*Get the reset counters reading from NVM*/
		for(cnt=0u; cnt<32u; cnt++)
		{

			if( (((ResetRawReason >> RVD_Bit) & 0x01u) == 0x01u) &&
					 (cnt == RVD_Bit)
					)
			{
				OtherResetCount |= 1u << RVD_Reset_Bit;
			}
			else if( (((ResetRawReason >> INITX_Bit) & 0x01u) == 0x01u) &&
					 (cnt == INITX_Bit)
					)
			{
				OtherResetCount |= 1u << INITX_Reset_Bit;
			}
			else if( (((ResetRawReason >> IMR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == IMR_Bit)
					)
			{
				OtherResetCount |= 1u << IMR_Reset_Bit;
			}
			else if( (((ResetRawReason >> LVDL1R_Bit) & 0x01u) == 0x01u) &&
					 (cnt == LVDL1R_Bit)
					)
			{
				OtherResetCount |= 1u << LVDL1R_Reset_Bit;
			}
			else if( (((ResetRawReason >> LVDL2R_Bit) & 0x01u) == 0x01u) &&
					 (cnt == LVDL2R_Bit)
					)
			{
				OtherResetCount |= 1u << LVDL2R_Reset_Bit;
			}
			else if( (((ResetRawReason >> LVDH1R_Bit) & 0x01u) == 0x01u) &&
					 (cnt == LVDH1R_Bit)
					)
			{
				OtherResetCount |= 1u << LVDH1R_Reset_Bit;
			}
			else if( (((ResetRawReason >> LVDH2R_Bit) & 0x01u) == 0x01u) &&
					 (cnt == LVDH2R_Bit)
					)
			{
				OtherResetCount |= 1u << LVDH2R_Reset_Bit;
			}
			else if( (((ResetRawReason >> CKTOR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CKTOR_Bit)
					)
			{
				OtherResetCount |= 1u << CKTOR_Reset_Bit;
			}
			else if( (((ResetRawReason >> SRSTX_Bit) & 0x01u) == 0x01u) &&
					 (cnt == SRSTX_Bit)
					)
			{
				OtherResetCount |= 1u << SRSTX_Reset_Bit;
			}
			else if( (((ResetRawReason >> PRFERR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == PRFERR_Bit)
					)
			{
				OtherResetCount |= 1u << PRFERR_Reset_Bit;
			}
			else if( (((ResetRawReason >> SHRST_Bit) & 0x01u) == 0x01u) &&
					 (cnt == SHRST_Bit)
					)
			{
				OtherResetCount |= 1u << SHRST_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVSCRR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVSCRR_Bit)
					)
			{
				OtherResetCount |= 1u << CSVSCRR_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVFCRR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVFCRR_Bit)
					)
			{
				OtherResetCount |= 1u << CSVFCRR_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVMOR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVMOR_Bit)
					)
			{
				OtherResetCount |= 1u << CSVMOR_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVSOR_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVSOR_Bit)
					)
			{
				OtherResetCount |= 1u << CSVSOR_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVPR0_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVPR0_Bit)
					)
			{
				OtherResetCount |= 1u << CSVPR0_Reset_Bit;
			}
			else if( (((ResetRawReason >> CSVSR0_Bit) & 0x01u) == 0x01u) &&
					 (cnt == CSVSR0_Bit)
					)
			{
				OtherResetCount |= 1u << CSVSR0_Reset_Bit;
			}
			else
			{
				/*No action required*/
			}
		}
        switch(RstReason)
        {
			case MCU_RESET_UNDEFINED:
				OtherResetCount |= 1u << Reset_undef_bit;
				break;
			case MCU_PLL1_STOP_RESET:
				OtherResetCount |= 1u << CSVPR1_Reset_Bit;
				break;
			case MCU_PLL2_STOP_RESET:
				OtherResetCount |= 1u << CSVPR2_Reset_Bit;
				break;
			case MCU_PLL3_STOP_RESET:
				OtherResetCount |= 1u << CSVPR3_Reset_Bit;
				break;
			case MCU_SSCG1_STOP_RESET:
				OtherResetCount |= 1u << CSVSR1_Reset_Bit;
				break;
			case MCU_SSCG2_STOP_RESET:
				OtherResetCount |= 1u << CSVSR2_Reset_Bit;
				break;
			case MCU_SSCG3_STOP_RESET:
				OtherResetCount |= 1u << CSVSR3_Reset_Bit;
				break;
			case MCU_WAKEUP_RESET:
				OtherResetCount |= 1u << Wakeup_Reset_bit;
				break;

        case MCU_WATCHDOG_SW_RESET:	        /*SW WatchDog Reset Counter*/
            NvmData[DATA_BYTE_0] = NvmData[DATA_BYTE_0] +INC_BY_1;
            break;
            
        case MCU_WATCHDOG_RESET:	        /*HW WatchDog Reset Counter*/
            NvmData[DATA_BYTE_1] = NvmData[DATA_BYTE_1] +INC_BY_1;
            break;
            
        case MCU_SW_RESET:					/*SW Reset*/
        case MCU_SW_TRIGGER_HW_RESET:					
            NvmData[DATA_BYTE_2] = NvmData[DATA_BYTE_2] +INC_BY_1;
            break;
            
        case MCU_POWER_ON_RESET: 			/*HW Power on Reset*/
            NvmData[DATA_BYTE_3] = NvmData[DATA_BYTE_3] +INC_BY_1;
            break;
            
        case MCU_EXTERNAL_RESET:			/*RSTX , external pin reset*/
            NvmData[DATA_BYTE_4] = NvmData[DATA_BYTE_4] +INC_BY_1;	
            break;
        default:
			/*No action required in default case*/
            break;
        }
		
		NvmData[4] = (uint8)((OtherResetCount & 0xFF000000) >> 24);
		NvmData[5] = (uint8)((OtherResetCount & 0xFF0000) >> 16);
        NvmData[6] = (uint8)((OtherResetCount & 0xFF00) >> 8);
        NvmData[7] = (uint8)((OtherResetCount & 0xFF));
        (void)RstCntrReadingConfig_U8.ResetSleepiag_Write(NvmData);/*Set the reset counters reading in NVM*/
    }
    else
    {

    }
}

/*=====================================================================================================================
**
** Function Name    :  ResetSleepDiag_RstCntrReading_Read 
**
** Visibility       :  Private 
**
** Description      :  reads reset counter reading
**                     
** Invocation       :  MeetMgr.diagcdd , Function:Resetsleepdiag_ResetCounters_Read
**
** Inputs           :  Data[out]:reset counters reading
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType ResetSleepDiag_RstCntrReading_Read(uint8* Data)
{
    //return Rte_Call_rp_NVM_WATCHDOG_COUNTER_GetNv_NVM_WATCHDOG_COUNTER(Data);
	 return E_OK; /* to be replaced by RTE */
}
/*=====================================================================================================================
**
** Function Name    :  ResetSleepDiag_RstCntrReading_Write 
**
** Visibility       :  Private 
**
** Description      :  writes reset counter reading
**                     
** Invocation       :  MeetMgr.diagcdd , Function:Resetsleepdiag_ResetCounters_Write
**
** Inputs           :  Data[in]:reset counters reading
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType ResetSleepDiag_RstCntrReading_Write(uint8* Data)
{
    return Rte_Call_rp_NVM_WATCHDOG_COUNTER_SetNv_NVM_WATCHDOG_COUNTER(Data[0]);
}
/*=====================================================================================================================
**
** Function Name    :  ResetSleepDiagservice_Set_NVM_JobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to set NVM job status as 0 for the previous request
**
** Invocation       : 
**
** Inputs           :  data
**
** Outputs          :  
**
** Critical Section : No
**
**====================================================================================================================*/

static void ResetSleepDiagservice_Set_NVM_JobStatus(uint8 data)
{
   /*	jobresult_read[0] = data;
	jobres_read_idx = data;	  */
} 

/*=====================================================================================================================
**
** Function Name    :  ResetSleepDiagservice_Get_NVM_JobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to get NVM job status of current request 
**
** Invocation       : 
**
** Inputs           :  data
**
** Outputs          :  
**
** Critical Section : No
**
**====================================================================================================================*/

static void ResetSleepDiagservice_Get_NVM_JobStatus(uint8 *data)
{

	if(NumberOfBlkIds == jobres_read_idx)
	{
		uint8 jobresult = jobresult_read[0];
		//set to default value
		jobres_read_idx =0;
		NumberOfBlkIds =1;
		Triggered_BlkID1 = 0x00;
		Triggered_BlkID2 = 0x00;
		Triggered_BlkID3 = 0x00;

		*data = ~(jobresult);
	}
	else
	{
		*data = 0x02;	//2 means NVM_REQ_PENDING
	}

}

#endif

#ifdef SLEEPMODEENABLE
static void ResetSleepDiag_SlpReq_Write(void)
{
   // Rte_Write_ppMfgAppctrlSleepSts_MfgSleepSts(SLEEP_READY);
}
#endif

#ifdef LOWQCURRENTENABLE
/*=====================================================================================================================
** Function Name    :  ResetSleepDiag_SlpReq_SetLowQCurrent
**
** Visibility       :  Private
**
** Description      :  Short term adjustment on LowQCurrent
**
** Invocation       :  ResetSleepdiag_SetLowQCurrent
**
** Inputs           :  Data
**
** Outputs          :  Std_ReturnType
**
** Critical Section :  No
**====================================================================================================================*/
static Std_ReturnType ResetSleepDiag_SlpReq_SetLowQCurrent(uint8* Data)
{
	Std_ReturnType ret = E_NOT_OK;

	if(*Data == eLowQCmdON)
	{
		/*SLEEEP_READY (0U) - To put into sleep 0 has to be passed*/
		//ret = Rte_Write_CMeetCdd_pp_SR_MfgSleepSts_MfgSleepSts(eEOL_SleepReady);
	}
	else
	{
		/*No action required for other values only positive response*/
		ret = E_OK;
	}

    return ret;
}
#endif

#ifdef RESETSLEEPDIAG_ODOMETER_RESET
/*=====================================================================================================================
**
** Function Name    :  ResetSleepDiag_Odo_Reset
**
** Visibility       :  Private 
**
** Description      :  Used to reset the odometer 
**
** Invocation       : 
**
** Inputs           :  data
**
** Outputs          :  
**
** Critical Section : No
**
**====================================================================================================================*/
static uint8 ResetSleepDiag_Odo_Reset(uint8* Data)
{
	UNUSED(Data);
	Std_ReturnType ret = E_NOT_OK;

	//ret = Rte_Call_rp_CS_OdoReset_OdoReset();

	if(ret == (uint8)E_OK)
	{
		odoResetCount++;
	}

	return ret;
}
#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Irrelevant header files removed.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Configurations are updated to support SetLowQCurrent interface
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  29/07/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 969201
** Change Description:  Callback support added for NVM write.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1368189
** Change Description:  For Reset Control Service, other reset condition check added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  3/July/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1342897
** Change Description:  Gip watchdog reset is commented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/March/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1296902
** Change Description:  for watchdog reset vip-gip support is added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features,removed unused constants
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/05/2018  
** CDSID             : athiyag2
** Traceability      : RTC 1113499
** Change Description: Initial version - ResetSleepDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif
