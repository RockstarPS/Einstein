/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
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
/*!***************************************************************************
* @ingroup Input-Output Hardware Abstraction
* @file IoHwAb_Pwm_Cfg.c
* @brief Configuration definitions for PWM output
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#include "IoHwAb_Pwm_Cfg.h"
#include "Rte_IoHwAb.h"


#if (IOHWAB_PWM_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/

#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>
/*period*/
const IoHwAb_PwmCfgType IoHwAb_PwmCfg[IOHWAB_NUM_OF_PWM_OUTPUT]=
{
     /* ILLUM PWM*/
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_LEFT_R,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_LEFT_R,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_LEFT_G,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_LEFT_G,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_LEFT_B,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_LEFT_B,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_CWL_RED,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_CWL_RED,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_RESERVED,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_RESERVED,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_TURN_RIGHT,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_TURN_RIGHT,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_TURN_LEFT,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_TURN_LEFT,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_PREGLOW,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_TURN_PREGLOW,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_TT_TURN_OBD,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_TT_TURN_OBD,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_TT_CWL_YELLOW,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_TT_CWL_YELLOW,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_RIGHT_R,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_RIGHT_R,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_RIGHT_G,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_RIGHT_G,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_AMBIENT_RIGHT_B,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_AMBIENT_RIGHT_B,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_BG_WHITE,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_BG_WHITE,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_BG_RED,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_BG_RED,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_DO_PWM_SCALE,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_DO_PWM_SCALE,               /* PWM Output Signal Id*/
},
{
	{     /* Variant 1 */
			PwmConf_PwmChannel_PWM_LCD_BL_DIMMING,       /* Mcal PWM channel id*/
		 0,                                     /* DUTY Resolution Id in Filter Cfg for 0.01 Res */
		 1,                                     /* PEROD Reslution Id in Filter Cfg for 0.1 Res */
	},
	eIO_PWM_PWM_LCD_BL_DIMMING,               /* PWM Output Signal Id*/
},

};
#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>


/*****************************************************************************
*  Private Function Definitions                                              *                                                                                       *
******************************************************************************/

#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>
/**
* This method is used to get the current vehicle variant for Pwm outputs
* @param     PwmVariantId   - variable to get the variant number
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Pwm_GetCurrentVariant(uint8* PwmVariantId)
{
     *PwmVariantId  = 0U;
     return E_OK;
}
/**
* This method is used to check any precondition before setting the Pwm outputs
* @param     void
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Pwm_PreHook(void)
{
    return E_OK;
}
#define IoHwAb_STOP_SEC_CODE
#include <IoHwAb_MemMap.h>

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
Date              :7-Feb-2020
By                :PPARIMI1
Traceability      :758686: JLR RICM IoHwAb PWM changes				   
Change Description:Initial Version for IoHwAb PWM chnages
******************************************************************************/

