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
* @file IoHwAb_DOut_Cfg.h
* @brief Configuration definitions for digital output
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_DOut_Cfg.h"
#include "Rte_IoHwAb.h"
#include "Stubs.h"

#if (IOHWAB_DOUT_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/**
* @brief Definition of configuration parameters for Digital outputs
*/
const IoHwAb_DOutCfgType IoHwAb_DOutCfg[IOHWAB_NUM_DOUT_OUTPUT] =
{
    {
        {
            /* Variant 1 */
            {
                MCU_GPIO0_B01_Ch22,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_LOW,                        /* Active level of the output pin*/
            }
        },
        eDO_3V3_DISP                         /* Digital output signal Id*/
    },
    {
        {
            /* Variant 1 */
            {
                MCU_GPIO0_B01_Ch23,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eIO_DOUT_DO_TFT_BL_EN                         /* Digital output signal Id*/
    },
    {
        {
            /* Variant 1 */
            {
                Main_GPIO1_Channel_5,          /* Mcal dio channel id*/
                STD_HIGH,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eIO_DOUT_DO_SOC_PWR_LATCH                         /* Digital output signal Id*/
    },
    {
        {
            /* Variant 1 */
            {
                MCU_GPIO0_B01_Ch7,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eIO_DOUT_DO_EN_5V                         /* Digital output signal Id*/
    },
    {
        {
            /* Variant 1 */
            {
                Main_GPIO0_Channel_71,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eIO_DOUT_DO_RTC_INTN                         /* Digital output signal Id*/
    },
    {
        {
            /* IOEXP_DIO_ADC_GPIO_08 */
            {
                IOEXP_DIO_ADC_GPIO_08,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_EXTERNAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eDO_DIO_ADC_GPIO_08                         /* Digital output signal Id*/
    },
    {
        {
            /* IOEXP_DIO_ADC_GPIO_09 */
            {
                IOEXP_DIO_ADC_GPIO_09,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_EXTERNAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eDO_DIO_ADC_GPIO_09                         /* Digital output signal Id*/
    },
    {
        {
            /* IOEXP_DIO_ADC_GPIO_10 */
            {
                IOEXP_DIO_ADC_GPIO_10,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_EXTERNAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eDO_DIO_ADC_GPIO_10                         /* Digital output signal Id*/
    },
    {
        {
            /* IOEXP_DIO_ADC_GPIO_11 */
            {
                IOEXP_DIO_ADC_GPIO_11,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_EXTERNAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
            }
        },
        eDO_DIO_ADC_GPIO_11                         /* Digital output signal Id*/
	},
	{
		{
			/* DO_MD_TOUCH_RST */
			{
				Main_GPIO0_Channel_41,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MD_TOUCH_RST                         /* Digital output signal Id*/
	},
	{
		{
			/* DO_VPP_EN */
			{
				Main_GPIO0_Channel_47,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_VPP_EN                         /* Digital output signal Id*/
	},
	{
		{
			/* DO_MD_GNSS_BOOT_EN */
			{
				Main_GPIO0_Channel_48,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MD_GNSS_BOOT_EN                         /* Digital output signal Id*/
	},
	{
		{
			/* DO_MD_GNSS_RESETP */
			{
				Main_GPIO0_Channel_50,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MD_GNSS_RESETP                        /* Digital output signal Id*/
	},
	{
		{
			/* DO_MD_GNSS_PWR_EN */
			{
				Main_GPIO0_Channel_51,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MD_GNSS_PWR_EN                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_BLU_OPAMP_PWR_EN */
			{
				Main_GPIO0_Channel_54,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_BLU_OPAMP_PWR_EN                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_BLU_DWALED_EN */
			{
				Main_GPIO0_Channel_60,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_BLU_DWALED_EN                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_TCON_BYPASS_MODE */
			{
				Main_GPIO0_Channel_61,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_TCON_BYPASS_MODE                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_TCON_BYPASS_SEL0 */
			{
				Main_GPIO0_Channel_62,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_TCON_BYPASS_SEL0                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_TCON_BYPASS_SEL1 */
			{
				Main_GPIO0_Channel_63,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_TCON_BYPASS_SEL1                       /* Digital output signal Id*/
	},
	{
		{
			/* DO_SOC_FPDLINK3_INTB# */
			{
				Main_GPIO0_Channel_68,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_LOW,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_SOC_FPDLINK3_INTB                      /* Digital output signal Id*/
	},
	{
		{
			/* DO_SOC_FPDLINK3_BISTEN */
			{
				Main_GPIO0_Channel_70,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_LOW,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_SOC_FPDLINK3_BISTEN                      /* Digital output signal Id*/
	},
	{
		{
			/* DO_EN_BUCK_FALD */
			{
				Main_GPIO1_Channel_0,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_EN_BUCK_FALD                     /* Digital output signal Id*/
	},
	{
		{
			/* DO_MCU_AMUX_S1 */
			{
				Main_GPIO1_Channel_12,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MCU_AMUX_S1                     /* Digital output signal Id*/
	},
	{
		{
			/* DO_MCU_AMUX_S0 */
			{
				Main_GPIO1_Channel_13,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MCU_AMUX_S0                     /* Digital output signal Id*/
	},
	{
		{
			/* DO_TCON_SPI0_CS0 */
			{
				Main_GPIO1_Channel_15,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_TCON_SPI0_CS0                     /* Digital output signal Id*/
	},
	{
		{
			/* DESER_SPI1_DO */
			{
				Main_GPIO1_Channel_42,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DESER_SPI1_DO                     /* Digital output signal Id*/
	},
	{
		{
			/* DO_SOC_TCON_GRBN */
			{
				Main_GPIO1_Channel_44,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_SOC_TCON_GRBN                     /* Digital output signal Id*/
	},
	{
		{
			/* DO_TFT_CSB */
			{
				Main_GPIO1_Channel_49,          /* Mcal dio channel id*/
				STD_LOW,                                        /* Init value of output signal*/
				IOHWAB_SOURCE_DOUT_MCAL,
				IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_TFT_CSB                     /* Digital output signal Id*/
	},
	{
		{
			/*DO_MCU_RESETSTAZ*/
			{
                MCU_GPIO0_B01_Ch21,          /* Mcal dio channel id*/
                STD_LOW,                                        /* Init value of output signal*/
                IOHWAB_SOURCE_DOUT_MCAL,                        /* Active level of the output pin*/
                IOHWAB_DOUT_ACTIVE_HIGH,                        /* Active level of the output pin*/
			}
		},
		eIO_DOUT_DO_MCU_RESETSTAZ
	}
};

void IoHwAb_Dio_WriteChannel(uint16 ChannelId, uint8 Level, IoHwAb_DOutSourceSignalType SourceSignalId)
{
    if(SourceSignalId == IOHWAB_SOURCE_DOUT_MCAL)
    {
        Dio_WriteChannel(ChannelId, Level);
    }
    else if(SourceSignalId == IOHWAB_SOURCE_DOUT_EXTERNAL)
    {
        IoExp_WriteChannel(ChannelId, Level);
    }
}

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/*****************************************************************************
*  Private Function Definitions                                              *                                                                                       *
******************************************************************************/
#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>
/**
* This method is used to get the current vehicle variant for digital outputs
* @param     DOutVariantId   - variable to get the varient number
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DOut_GetCurrentVariant(uint8* DOutVariantId)
{
 *DOutVariantId  = 0U;
 return E_OK;
}
/**
* This method is used to check any precondition before setting the digital outputs
* @param     void
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DOut_PreHook(void)
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

