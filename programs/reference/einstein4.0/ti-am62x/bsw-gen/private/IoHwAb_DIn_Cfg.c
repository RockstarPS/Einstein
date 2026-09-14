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
* @file IoHwAb_DIn_Cfg.c
* @brief Configuration data for digital inputs
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#include "IoHwAb_DIn_Cfg.h"
#include "Rte_IoHwAb.h"
#include "Stubs.h"

#if (IOHWAB_DIN_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/**
* @brief Definition of configuration parameters for Digital inputs
*/
const IoHwAb_DInCfgType IoHwAb_DInCfg[IOHWAB_NUM_DIN_INPUT] =
{
    {
        {
                /* Variant 1 */
            {
                Main_GPIO1_Channel_31,                      /* Mcal dio channel id*/
                IOHWAB_DIN_ACTIVE_LOW,                      /* Active level of the input pin*/
                IOHWAB_SOURCE_DIN_MCAL,
                0u,                                         /* Debounce Group Id*/
                0u,                                         /* Debounce channel Id*/
        },
        },
        eIO_DIN_DI_PMIC_INTN                                /* Digital Input signal Id*/
    },
	{
		{
			{
				Main_GPIO0_Channel_32,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_LOW,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				1u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_SBATT2_ERR 							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_40,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_LOW,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				2u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_FALD_PG 							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_42,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				3u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_MD_TOUCH_INTN 							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_53,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_LOW,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				4u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_BL_FAULT							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_66,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				5u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_SOC_FPDLINK3_LOCK							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_69,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_LOW,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				6u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_SOC_FPDLINK3_PASS							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_89,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_LOW,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				7u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_ENET_MII_INT							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO0_Channel_90,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				8u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_IGN_MON							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO1_Channel_1,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				9u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_CABLE_DETECT							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO1_Channel_11,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				10u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_TCON_IND_OUT							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO1_Channel_3,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				12u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_MCU_FALD_CONN_CHK							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO1_Channel_4,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				13u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_LDO_1V2_FAULTN							/* Digital Input signal Id*/
	},
	{
		{
			{
				Main_GPIO1_Channel_48,                      /* Mcal dio channel id*/
				IOHWAB_DIN_ACTIVE_HIGH,						/* Active level of the input pin*/
				IOHWAB_SOURCE_DIN_MCAL,
				0u,											/* Debounce Group Id*/
				14u,											/* Debounce channel Id*/
			},
		},
		eIO_DIN_DI_TFT_ER_DET							/* Digital Input signal Id*/
	}
};

uint8 IoHwAb_Dio_ReadChannel(Dio_ChannelType ChannelId, IohwAb_DInSourceSignalType SourceSignalId)
{
    uint8 pLevel = 0U;
    if(SourceSignalId == IOHWAB_SOURCE_DIN_MCAL)
    {
        pLevel = Dio_ReadChannel(ChannelId);
    }
    else if(SourceSignalId == IOHWAB_SOURCE_DIN_EXTERNAL)
    {
        pLevel = IoExp_ReadChannel(ChannelId);
    }
	else
	{
		/* Do Nothing */
	}
    return pLevel;
}

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/*****************************************************************************
*  Private Function Definitions                                              *                                                                                       *
******************************************************************************/
#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>
/**
* This method is used to get the current vehicle variant for digital inputs
* @param     DInVariantId   - variable to get the varient number
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DIn_GetCurrentVariant(uint8* DInVariantId)
{
     *DInVariantId  = 0U;
     return E_OK;
}

/**
* This method is used to check any precondition before reading the digital inputs
* @param     void
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DIn_PreHook(void)
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
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/

