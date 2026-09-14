/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2025. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
File Name        :  CFastGaugeAdapter.c
Module Short Name:  Fast gauges Handling
Author           :  aelango6
Description      :  Packing the Speed and Tacho Inputs according to the UCL Fast Gauge format
Organization     :  Driver Information Software Section, Visteon Corporation
******************************************************************************/
/*includes*/

/*includes*/
#ifndef CFASTGAUGEADAPTER_COMMON_INCLUDES
# define CFASTGAUGEADAPTER_COMMON_INCLUDES                       
#include "Rte_Type.h"
#include "Rte_FastGaugeAdapter.h" /* CFASTGAUGEADAPTER_COMMON_INCLUDES_ */
#endif 
//=====================================================================================================================
//  FORWARD MACRO DEFINITION
//=====================================================================================================================
#define SPEED_GAUGE     1U
#define TACHO_GAUGE     2U
#define HVSYS_GAUGE     3U
#define NVM_MCUID0262   0U
#define NVM_MCUID0263   1U
#define BITSHIFT_16     16U
#define BITSHIFT_12     12U
#define BITSHIFT_4      4U
#define UPPER_U32       0xFFFF0000U
#define LOWER_U32       0x0000FFFFU
#define FIRST_NIBBLE    0x0000000FU
#define REDZONE_START   0x00000FF0U
#define cZERO           0U
#define cONE            1U
#define cTWO            2U
#define TACHO_MAX_BYTE  0x000FF000U
//=====================================================================================================================
//  GLOBAL DEFINITION
//=====================================================================================================================
static uint16 l_max_speed_value_u16[cTWO];
static uint8  l_mcuconst_init_u8;
/****************************************************************************
Function Name     	: CFastGaugeAdapter_Task

Description         : This function Main Task to Send Fast Gauge UCL info Message with 24ms Task Periodicity

Invocation          : called in Task.

Parameters          : None

Return Value        : None

Critical Section    : None

******************************************************************************/

FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Task(void) /* Sample time: [0.1s, 0.0s] */
{
	SFastGaugeInfo fl_fastgaugeinfo;
	uint16 fl_Digi_Speed_Val_u16;
	uint16 fl_Analog_Speed_Val_u16;
	uint16 fl_Digi_Sub_Speed_Val_u16;
	//uint16 fl_HVCROut_u16;
	uint16 fl_Analog_Tacho_u16;
	uint16 fl_Digi_Tacho_u16;
	uint8 fl_display_dist_unit_u8;
	uint8 fl_Needle_Tr_u8;
	uint8 fl_red_zone_start_u8;
	uint8 fl_Tacho_Max_u8;
	uint8 fl_PTSYS_u8;
	uint8 fl_HMI_Ready_status_u8;
	uint8 fl_cluster_mode;
	//uint16 fl_HVTH_Out_u16;
	boolean fl_Tacho_Unit_bool; 
	
	
	/*Inputs from other Models*/
	Rte_Read_rp_DispDistanceUnit_DisplayUnit(&fl_display_dist_unit_u8);
	Rte_Read_rp_Display_speed_Value_Digital_Speed_Value(&fl_Digi_Speed_Val_u16);
	Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal(&fl_Digi_Sub_Speed_Val_u16);
	Rte_Read_rp_DispSpeedA_DispSpeedVal(&fl_Analog_Speed_Val_u16);
	Rte_Read_rp_Analog_Tacho_Analog_Tacho(&fl_Analog_Tacho_u16);
	Rte_Read_rp_Digital_Tacho_Digital_Tacho(&fl_Digi_Tacho_u16);
	Rte_Read_rp_Needle_Transparent_Needle_TR(&fl_Needle_Tr_u8);
	Rte_Read_rp_TC_Unit_Digital_TachoUnit(&fl_Tacho_Unit_bool);
	Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM(&fl_red_zone_start_u8);
	Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX(&fl_Tacho_Max_u8);
	Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(&fl_HMI_Ready_status_u8);
	Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&fl_cluster_mode);
	//Rte_Read_rp_HVCR_Value_HVCRValue(&fl_HVCROut_u16);
	Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(&fl_PTSYS_u8);
	//Rte_Read_rp_HVTH_Value_HVTHValue(&fl_HVTH_Out_u16);

	/*Only one time MCU CONST Read after Cluster Active*/
	if((fl_cluster_mode != CLUSTER_INACTIVE) && (l_mcuconst_init_u8 == cZERO))
	{
		//Rte_Call_rp_CS_Fastgauge_MCUID_Value_CFastGaugeAdapterMCU_ID(&l_max_speed_value_u16[0]);

		l_mcuconst_init_u8 = cONE;
	}
	else
	{
		/* Do Nothing */
	}
	
	if ((fl_cluster_mode != CLUSTER_INACTIVE) && (fl_HMI_Ready_status_u8 != eHMI_NOT_READY)) //&& (l_mcuconst_init_u8 != cZERO))
	{
		/* UCL Speed Data (Id = 1) */
		fl_fastgaugeinfo.gaugeInfo[0].id          = SPEED_GAUGE;
		/* Analog pointer Speed input*/
		fl_fastgaugeinfo.gaugeInfo[0].position    = fl_Analog_Speed_Val_u16; 
		/* First 2 bytes - Digital speed data and Second 2 bytes Sub speed data*/
		
		// fl_fastgaugeinfo.gaugeInfo[0].digitalData = (UPPER_U32 & (fl_Digi_Sub_Speed_Val_u16 << BITSHIFT_16)) | (LOWER_U32 & fl_Digi_Speed_Val_u16);
        fl_fastgaugeinfo.gaugeInfo[0].digitalData = (uint32)fl_Digi_Speed_Val_u16;


		/*Display Distance Unit*/
		fl_fastgaugeinfo.gaugeInfo[0].unit	      = fl_display_dist_unit_u8;
		/* First 2 bytes - NVM_MCUID0263 and Second 2 bytes NVM_MCUID0262*/
		
		fl_fastgaugeinfo.gaugeInfo[0].dynData     = (UPPER_U32 & (l_max_speed_value_u16[NVM_MCUID0263] << BITSHIFT_16)) | (LOWER_U32 & l_max_speed_value_u16[NVM_MCUID0262]);
		
		/* UCL Tacho Data (Id = 2)*/
		fl_fastgaugeinfo.gaugeInfo[1].id          = TACHO_GAUGE;
		/* Analog Tacho input*/
		fl_fastgaugeinfo.gaugeInfo[1].position    = fl_Analog_Tacho_u16;
		/* Digital Tacho input*/
		fl_fastgaugeinfo.gaugeInfo[1].digitalData = fl_Digi_Tacho_u16;
		/* Tacho Unit*/
		fl_fastgaugeinfo.gaugeInfo[1].unit	      = fl_Tacho_Unit_bool;
		/* First nibble with Needle transparent data, Followed by next 1 byte indicates RedZone Start, and then 1 byte Tacho Max value */
		
		
		fl_fastgaugeinfo.gaugeInfo[1].dynData     = (((FIRST_NIBBLE) & fl_Needle_Tr_u8) | ((REDZONE_START) & ( fl_red_zone_start_u8 << BITSHIFT_4)) | ((TACHO_MAX_BYTE) & ( fl_Tacho_Max_u8 << BITSHIFT_12)));
		
		// /* UCL HVSYS Data (Id = 3)*/
		// fl_fastgaugeinfo.gaugeInfo[2].id          = HVSYS_GAUGE;
		// /* HVCR input*/
		// fl_fastgaugeinfo.gaugeInfo[2].position    = fl_HVCROut_u16;
		// /* ZERO input*/
		// fl_fastgaugeinfo.gaugeInfo[2].digitalData = (LOWER_U32 & fl_HVTH_Out_u16);
		// /* ZERO Unit*/
		// fl_fastgaugeinfo.gaugeInfo[2].unit	      = cZERO;
		// /* PTSYS_VALUE*/
		// fl_fastgaugeinfo.gaugeInfo[2].dynData     = fl_PTSYS_u8;

		/*UCL Output*/
		(void)Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData(&fl_fastgaugeinfo);
	}
	else
	{
		/*Do Nothing*/
	}	
}
/****************************************************************************
Function Name     	: CFastGaugeAdapter_Init

Description         : This function Init Task to Intialize the the variable/Outputs every sleep to wakeup and battery connect

Invocation          : called in Task.

Parameters          : None

Return Value        : None

Critical Section    : None

******************************************************************************/

FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Init(void)
{
  /* MCU Const read flag as zero*/
  l_mcuconst_init_u8 = cZERO;

}

/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*---------------------------------------------------------------------------
Release Label     : Initial Version
Date              : 03/07/2025
By                : aelango6
Change Description: Initial version.
-----------------------------------------------------------------------------*/

/*End of File*/

