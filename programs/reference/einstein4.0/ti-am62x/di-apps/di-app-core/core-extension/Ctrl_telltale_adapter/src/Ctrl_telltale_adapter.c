/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2017. Visteon Corporation owns all rights to this work and
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
**============================================================================
**
** Name:           Ctrl_telltale_adapter
**
** Description:    Reading of telltale status from the individual Telltale models.
**
** Organization:   Driver Information Software Section,
**           
**==========================================================================*/

/*----------------------------------------------------------------------------------------------------------------------
** Included files
**----------------------------------------------------------------------------------------------------------------------*/
#include "rtwtypes.h"
#include "Rte_CCtrl_Telltale.h"
#include "Std_Types.h"
#include "string.h"
#include "Ctrl_TT_Cfg.h"
//#include "Rte_IoHwAb.h"
//#include "IoHwAbExt_LEDDriver_Cfg.h"
//#include "IoHwAbExt_LEDDriver.h"
//#include "IoHwAb_Adc_Cfg.h"
//#include "Rte_TtView_Type.h"
//#include "Rte_TtView.h"


static uint8 tt_ip_array_adapter[TT_TOTAL_NUM_OF_TELLTALES];
//extern Std_ReturnType IoHwAbExt_LEDDriverSetPin(IoHwAbExt_LEDChannelType ChannelId, boolean OutputSignal, IoHwAbExt_ErrorType* ErrorStatus);
/*----------------------------------------------------------------------------------------------------------------------
** Constant data
**----------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------
** Exported type
**----------------------------------------------------------------------------------------------------------------------*/

//---------------------------------------------------------------------------------------------------------------------
/// @brief  This Runnable reads the telltale output from the respective telltale models and provides 
///			input to control telltale.
/// @return void
//---------------------------------------------------------------------------------------------------------------------



FUNC(void, Ctrl_telltale_CODE) CCtrl_Telltale_Adapter_Task(void)
{		
	   
	    uint8 tt_Status;	
	    uint8 index;
		// Rte_Read_rpTelltlaeStatus_rp_Abs_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ABS_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_ADAS_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ADAS_INDEX]);
		Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AIRBAG_INDEX]);		
		// Rte_Read_rpTelltlaeStatus_rp_AHB_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AUTO_HIGH_BEAM_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_BRAKE_RED_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_BRAKE_RED_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Brake_Hold_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_BRAKE_HOLD_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Brake_Hold_Standby_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_BRAKE_HOLD_STANDBY_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Brake_Yellow_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_BRAKE_YELLOW_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Praking_brake_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_PARKING_BRAKE_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Fuel_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_FUEL_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_FrontFog_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_FFOG_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Hibeam_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_HIGH_BEAM_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Pcs_Off_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_PCS_OFF_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Ready_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_READY_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_RearFog_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_RFOG_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_HeadTailLight_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_TAIL_LIGHT_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_Traction_Control_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_TRACTION_CTRL_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_VSC_Off_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_VCS_OFF_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_EWT_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_EWT_INDEX]);
		Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_TURN_HAZARD_LEFT_INDEX]);
        Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_TURN_HAZARD_RIGHT_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_AutoLsdAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AUTO_LSD_AMBER]);
		// Rte_Read_rpTelltlaeStatus_rp_AAHB_Hi_Green_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AAHB_HI_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_AAHB_Hi_White_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AAHB_HI_WHITE]);
        // Rte_Read_rpTelltlaeStatus_rp_AAHB_Lo_Green_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AAHB_LO_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_AAHB_Shaded_Green_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_AAHB_SHADED_GREEN]);
		// Rte_Read_rpTelltlaeStatus_rp_Its_Combination_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ITS_COMBINATION]);
        // Rte_Read_rpTelltlaeStatus_rp_Its_Infra_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ITS_INFRA]);
        // Rte_Read_rpTelltlaeStatus_rp_Its_Vehicle_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ITS_VEHICLE]);
		// Rte_Read_rpTelltlaeStatus_rp_LcaLeftGray_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_LEFT_GRAY]);
        // Rte_Read_rpTelltlaeStatus_rp_LcaLeftGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_LEFT_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_LcaLeftWhiteTT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_LEFT_WHITE]);
        // Rte_Read_rpTelltlaeStatus_rp_LcaRightGray_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_RIGHT_GRAY]);
        // Rte_Read_rpTelltlaeStatus_rp_LcaRightGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_RIGHT_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_LcaRightWhiteTT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LCA_RIGHT_WHITE]);
		// Rte_Read_rpTelltlaeStatus_rp_SpeedLimiterWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_SL_WHITE]);
        // Rte_Read_rpTelltlaeStatus_rp_SpeedLimiterGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_SL_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_SpeedLimiterAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_SL_AMBER]);
		// Rte_Read_rpTelltlaeStatus_rp_AccDTGreenLV1_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_GREEN_LV1]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTGreenLV2_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_GREEN_LV2]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTGreenLV3_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_GREEN_LV3]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTGreenLV4_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_GREEN_LV4]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTWhiteLV1_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_WHITE_LV1]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTWhiteLV2_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_WHITE_LV2]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTWhiteLV3_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_WHITE_LV3]);
        // Rte_Read_rpTelltlaeStatus_rp_AccDTWhiteLV4_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ACCDT_WHITE_LV4]);
        // Rte_Read_rpTelltlaeStatus_rp_CctAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_CCT_AMBER]);
        // Rte_Read_rpTelltlaeStatus_rp_CctGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_CCT_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_CctWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_CCT_WHITE]);
        // Rte_Read_rpTelltlaeStatus_rp_RcctAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_RCCT_AMBER]);
        // Rte_Read_rpTelltlaeStatus_rp_RcctGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_RCCT_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_RcctWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_RCCT_WHITE]);
		// Rte_Read_rpTelltlaeStatus_rp_LtaAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LTA_AMBER]);
        // Rte_Read_rpTelltlaeStatus_rp_LtaGreen_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LTA_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_LtaWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LTA_WHITE]);
		// Rte_Read_rpTelltlaeStatus_rp_HeadTail_Light_USA_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_HEAD_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_PlusSurport_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_PS_GREEN]);
		// Rte_Read_rpTelltlaeStatus_rp_StrtStopSys_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_SSS_GREEN]);
		// Rte_Read_rpTelltlaeStatus_rp_StrtStopSysCancel_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_SSS_AMBER]);
		// Rte_Read_rpTelltlaeStatus_rp_LDAWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LDA_WHITE]);
		// Rte_Read_rpTelltlaeStatus_rp_LDARed_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LDA_RED]);
		// Rte_Read_rpTelltlaeStatus_rp_LDAAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LDA_AMBER]);
		// Rte_Read_rpTelltlaeStatus_rp_LDAOffWhite_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LDA_OFF_WHITE]);
		// Rte_Read_rpTelltlaeStatus_rp_LDAOffAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_LDA_OFF_AMBER]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModSport_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_SPORT]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModEco_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_ECO]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModCustom_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_CUSTOM]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModRange_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_RANGE]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModRearComfort_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_REARCOMFORT]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModSnow_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_SNOW]);
		// Rte_Read_rpTelltlaeStatus_rp_DrvModTrack_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_DRIVEMODE_TRACK]);
		// Rte_Read_rpTelltlaeStatus_rp_EcoDrive_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_ECOLAMP]);
        // Rte_Read_rpTelltlaeStatus_rp_PkbOper_Txt_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_PKBOPER_TXT]);
        // Rte_Read_rpTelltlaeStatus_rp_PkbOper_Img_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_PKBOPER_IMG]);
		// Rte_Read_rpTelltlaeStatus_rp_Tpms_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_TPMS_INDEX]);
		// Rte_Read_rpTelltlaeStatus_rp_ElecBrkPadWear_Txt_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_EBPWIND_RED_US]);
        // Rte_Read_rpTelltlaeStatus_rp_ElecBrkPadWear_Img_TT_Status_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_EBPWIND_RED]);
        // Rte_Read_rpTelltlaeStatus_rp_FMSideRadarAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_FMSR_AMBER]);
        // Rte_Read_rpTelltlaeStatus_rp_FMFwdRadarAmber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_FMFR_AMBER]);
        // Rte_Read_rpTelltlaeStatus_rp_MultiWeatherLight_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_MULWL_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_HICSAccess_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_HCS_ACCESS_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_HICSLift_Green_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_HCS_LIFT_GREEN]);
        // Rte_Read_rpTelltlaeStatus_rp_HICSLift_Amber_TT_Sts_CurrentTelltaleStatus(&tt_ip_array_adapter[TT_HCS_LIFT_AMBER]);



		for(index = 0; index < TT_TOTAL_NUM_OF_TELLTALES; index++)
		{ 
	      tt_Status = tt_ip_array_adapter[index];
          (void)CTRLTT_CTRLTTUPDATESTATUS(index, tt_Status);
		}

		
}
/*---------------------------------------------------------------------------
Date              : 13-June-2022
CDSID             : aahadhil    
Traceability      : 
Change Description: Airbag,ABS,Brake Hold,Ready TT,Rear Fog Added
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 21-June-2022
CDSID             : aahadhil    
Traceability      : 
Change Description: AHB Telltale Added
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 1-Sep-2022
CDSID             : aahadhil
Traceability      : 1757252: [toyota][38xd]-Turn Hzd Telltale Index Update
Change Description: Turn Hzd and TPMS Telltale Index Added 
-----------------------------------------------------------------------------*/
