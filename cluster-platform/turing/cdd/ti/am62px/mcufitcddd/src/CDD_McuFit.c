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
/*!*****************************************************************************
 *    @file Cdd_McuFit.c
 *    @defgroup Cdd_McuFit
 *    @ingroup Cdd_McuFit
 *    @brief
 ******************************************************************************/
#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef CDD_MCUFIT_C
#define CDD_MCUFIT_C

/*****************************************************************************
 * System Includes                                                            *
 *****************************************************************************/
#include "CDD_McuFit.h"
/*****************************************************************************
 * Project Includes                                                           *
 *****************************************************************************/

/*****************************************************************************
 * File Scope Prototypes                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Constants                                                                  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 *****************************************************************************/

/*****************************************************************************
 * Manifest Constants                                                         *
 *----------------------------------------------------------------------------*
 * Definition of Manifest constant shall be followed by a comment that        *
 * explains the purpose of the constant.                                      *
 *****************************************************************************/

/*****************************************************************************
 * Macro Definitions                                                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Globally  accessed Variable Declarations                                   *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/

/*****************************************************************************
 * Locally used Variable Declarations                                         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/

#ifdef cCDD_MCUFIT_ENABLE_MEMORYMAP
#define CDD_MCUFIT_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

static const SDL_POK_Inst pok_cores[MAX_POK_CORES][POK_CHCK_UV_OV] = 
{
   { SDL_POK_VDDS_DDRIO_ID,          SDL_POK_VDDS_DDRIO_ID },
   { SDL_POK_VDDR_CORE_ID,           SDL_POK_VDDR_CORE_ID },
   { SDL_POK_VMON_CAP_MCU_GENERAL_ID, SDL_POK_VMON_CAP_MCU_GENERAL_ID },
   { SDL_POK_VDDSHV_MAIN_1P8_ID,     SDL_POK_VDDSHV_MAIN_1P8_ID },
   { SDL_POK_VDDSHV_MAIN_3P3_ID,     SDL_POK_VDDSHV_MAIN_3P3_ID },
   { SDL_POR_VDD_MCU_UV_ID,          SDL_POK_VDD_MCU_OV_ID },
   { SDL_POR_VDDA_MCU_UV_ID,         SDL_POR_VDDA_MCU_OV_ID }
};

#ifdef cCDD_MCUFIT_ENABLE_MEMORYMAP
#define CDD_MCUFIT_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef cCDD_MCUFIT_ENABLE_MEMORYMAP
#define CDD_MCUFIT_START_SEC_CODE
#include "MemMap.h"
#endif

#if (FLTM_PPU_ENABLE == STD_ON)
void CDD_McuFit_InjectPPU_ReadBackFail(void)
{
    int32_t status = SystemP_SUCCESS;
    const struct tisci_msg_fwl_change_owner_info_req fwl_owner_req =
    {
        .fwl_id = Ppu_Config[0U].fwl_id,
        .region = Ppu_Config[0U].region_id,
        .owner_index = TISCI_HOST_ID_MCU_0_R5_0,
    };
    struct tisci_msg_fwl_change_owner_info_resp fwl_owner_resp = { 0U };
    status = (int32_t)Sciclient_firewallChangeOwnerInfo(&fwl_owner_req, &fwl_owner_resp, (uint32_t)SystemP_TIMEOUT);

	if(status == (int32_t)SystemP_SUCCESS)
	{
		const struct tisci_msg_fwl_set_firewall_region_req fwl_set_req =
		{
			.fwl_id = Ppu_Config[0U].fwl_id,
			.region = Ppu_Config[0U].region_id,
			.n_permission_regs = Ppu_Config[0U].n_permission_regs,
			.control = Ppu_Config[0U].control,
			.permissions[0U] = 0U, // FAULT
			.permissions[1U] = Ppu_Config[0U].permissions_1,
			.permissions[2U] = Ppu_Config[0U].permissions_2,
			.start_address  = Ppu_Config[0U].start_address,
			.end_address    = Ppu_Config[0U].end_address,
		};
		struct tisci_msg_fwl_set_firewall_region_resp fwl_set_resp = { 0U };

		status = (int32_t)Sciclient_firewallSetRegion(&fwl_set_req, &fwl_set_resp, (uint32_t)SystemP_TIMEOUT);

	}
	else
	{

	}
	
	(void)status;
}
#endif

/*!*****************************************************************************
 *   @brief      	To trigger start stop control functionality based on the
 *                  test id which needs to be executed
 *   @param[in]  	*Data - Data in which we receive FIT details.
 *   @return    	E_OK:
 *          		E_NOT_OK:
 *
 *          		2E 4F 09- 20 1 1 xx xx
 *          		Data[0]- 20 - module ID
 *          		Data[1]- 1  - fit test id
 *          		Data[2]- 1 - start/stop access
 *          		Data[3] -xx,
 *          		Data[4] -yy - fit data
 ******************************************************************************/

FUNC(Std_ReturnType, CDD_McuFit_CODE) CDD_McuFit_FaultInjectionHandler(
                             uint8 StartStopData, uint8 TestListID, const uint8 *Data)
{

	static Std_ReturnType ReturnType = E_OK;
	static uint8 index = 0;
	static volatile uint8 Halt = FALSE;
	#if (FLTM_POK_ENABLE ==STD_ON)
	   static volatile uint8 ov_uv = 0;
	   SDL_POK_config pPokCfg;
	#endif
	#if (FLTM_DCC_ENABLE == STD_ON)
       uint32_t refclkFreq, monclkFreq;
	   uint32_t reg;
	#endif
	#if (FLTM_ECC_ENABLE == STD_ON)
	   int32_t ecc_ret;
	#endif

  #if (FLTM_FLSINTEGRITY_ENABLE == STD_ON)
    volatile uint16_t *chksum_ptr;
  #endif

	(void)index;

	switch(TestListID)
	{
		/* DID: 2E F7 81  00 81 01 00 00*/
		case CDD_FITMANAGER_CDD_MCUFIT_PMIC_WDG_TEST_ID:
		
		    ReturnType = E_OK;
		    while(Halt == FALSE)
			{

			}
		    break;

		/* DID: 2E F7 81  00 82 01 00 00*/
		case CDD_FITMANAGER_CDD_MCUFIT_CSV_PER_READBACK_TEST_ID:
		#if (FLTM_DCC_ENABLE == STD_ON)
			refclkFreq = Dcc_Config[0U].refclkFreq;
			monclkFreq = Dcc_Config[0U].monclkFreq;

			reg = *(volatile uint32_t *)(uintptr_t)DCC_DCCGCTRL_ADDR;
			reg &= (uint32_t)(~SINGLESHOT_MASK);           // Clear bits 11:8
			reg |= SINGLESHOT_VALUE;           // Set desired value
			*(volatile uint32_t *)(uintptr_t)DCC_DCCGCTRL_ADDR = reg;
			(void)refclkFreq;
			(void)monclkFreq;
			ReturnType = E_OK;
		#endif
		    break;

		/* DID: 2E F7 81  00 83 01 xx 00*/     // xx = configured DCC index 
		case CDD_FITMANAGER_CDD_MCUFIT_CSV_CLK_TEST_ID:
		#if (FLTM_DCC_ENABLE == STD_ON)
		    index = *(Data);
			if (FltM_Dcc_InjectFault(index) == (int32_t)SDL_PASS)
            {
                ReturnType = E_OK;
            }
            else
            {
                ReturnType = E_NOT_OK;
            }
		#endif
		    break;


		/* DID: 2E F7 81  00 84 01 xx 00*/    // xx  = 00 to 09
		case CDD_FITMANAGER_CDD_MCUFIT_ECC_TEST_ID:
		#if (FLTM_ECC_ENABLE == STD_ON)
			for(index=0U; index < CDD_MCUFIT_NUM_ECC_CFG; index++)
			{
				if(index== *(Data))
				{
					ecc_ret = FltM_runECC_InjectTest(CDD_McuFit_Ecc_Cfg[index].ecc_addr,
					                                 CDD_McuFit_Ecc_Cfg[index].ecc_aggr,
													 CDD_McuFit_Ecc_Cfg[index].ecc_ramid,
													 CDD_McuFit_Ecc_Cfg[index].ecc_errortype);
					if(ecc_ret == SDL_PASS)
					{
						ReturnType = E_OK;
					}
				}
			}
		#endif
			break;
		
		/* DID: 2E F7 81  00 85 01 00 00*/
		case CDD_FITMANAGER_CDD_MCUFIT_PPU_TEST_ID:
			/* PPU Test to be added to FIT using Ipc Messaging via DM */
			break;
		
		/* DID: 2E F7 81  00 86 01 00 00*/
		case CDD_FITMANAGER_CDD_MCUFIT_PPU_PER_READBACK_TEST_ID:
		#if (FLTM_PPU_ENABLE == STD_ON)
		    ReturnType = E_OK;
			CDD_McuFit_InjectPPU_ReadBackFail();
        #endif			
			break;
		
		/*  
			POK Test Method:
			--------------------------------------------------------------------
			Index 			: 	POK Instances					: Supported Test
			--------------------------------------------------------------------
			Instance 0 		- SDL_POK_VDDS_DDRIO_ID				-> Over Voltage / Under Voltage
			Instance 1 		- SDL_POK_VDDR_CORE_ID				-> Over Voltage / Under Voltage
			Instance 2 		- SDL_POK_VMON_CAP_MCU_GENERAL_ID	-> Over Voltage / Under Voltage
			Instance 3 		- SDL_POK_VDDSHV_MAIN_1P8_ID		-> Over Voltage / Under Voltage
			Instance 4 		- SDL_POK_VDDSHV_MAIN_3P3_ID		-> Over Voltage / Under Voltage
			Instance 5 		- SDL_POK_VDD_MCU			        -> Over Voltage / Under Voltage
			Instance 6 		- SDL_POR_VDDA_MCU			        -> Over Voltage / Under Voltage
			---------------------------------------------------------------------
			SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE   -  0
			SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE    -  1
			---------------------------------------------------------------------
		*/
		/*  DIDs for Testing over voltage
		    
			SDL_POK_VDDS_DDRIO_ID           - 2E F7 81  00 87 01 00 01
			SDL_POK_VDDR_CORE_ID            - 2E F7 81  00 87 01 01 01
			SDL_POK_VMON_CAP_MCU_GENERAL_ID - 2E F7 81  00 87 01 02 01
			SDL_POK_VDDSHV_MAIN_1P8_ID      - 2E F7 81  00 87 01 03 01
			SDL_POK_VDDSHV_MAIN_3P3_ID      - 2E F7 81  00 87 01 04 01
			SDL_POK_VDD_MCU_OV_ID           - 2E F7 81  00 87 01 05 01
			SDL_POR_VDDA_MCU_OV_ID          - 2E F7 81  00 87 01 06 01
		*/
		/*  DIDs for Testing under voltage
		    
			SDL_POK_VDDS_DDRIO_ID           - 2E F7 81  00 87 01 00 00
			SDL_POK_VDDR_CORE_ID            - 2E F7 81  00 87 01 01 00
			SDL_POK_VMON_CAP_MCU_GENERAL_ID - 2E F7 81  00 87 01 02 00
			SDL_POK_VDDSHV_MAIN_1P8_ID      - 2E F7 81  00 87 01 03 00
			SDL_POK_VDDSHV_MAIN_3P3_ID      - 2E F7 81  00 87 01 04 00
			SDL_POK_VDD_MCU_UV_ID           - 2E F7 81  00 87 01 05 00
			SDL_POR_VDDA_MCU_UV_ID          - 2E F7 81  00 87 01 06 00
		*/
		case CDD_FITMANAGER_CDD_MCUFIT_POK_TEST_ID:
		#if (FLTM_POK_ENABLE ==STD_ON)
		    index = *(Data);
			ov_uv = Data[1U];
			
		if ((MAX_POK_CORES <= index) || (POK_CHCK_UV_OV <= (SDL_pwrss_vd_mode)ov_uv))
		{
			ReturnType = E_NOT_OK;
		}
		else
		{
			SDL_POK_Inst selected_coreID = pok_cores[index][(SDL_pwrss_vd_mode)ov_uv];

			/* Common across both UV & OV cases for all rails*/
			pPokCfg.hystCtrl        = (SDL_pwrss_hysteresis)SDL_PWRSS_HYSTERESIS_NO_ACTION;
			pPokCfg.detectionCtrl   = (SDL_POK_detection)SDL_POK_DETECTION_NO_ACTION;
			pPokCfg.pokEnSelSrcCtrl = (SDL_POK_enSelSrc)SDL_POK_ENSEL_NO_ACTION;
			pPokCfg.hystCtrlOV      = (SDL_pwrss_hysteresis)SDL_PWRSS_HYSTERESIS_NO_ACTION;
			pPokCfg.deglitch        = (SDL_pwrss_deglitch)SDL_PWRSS_DEGLITCH_NO_ACTION;

			if (5u > index)
			{
				pPokCfg.voltDetMode = (SDL_pwrss_vd_mode)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE;
			}
			else
			{
				pPokCfg.voltDetMode = (SDL_pwrss_vd_mode)ov_uv;
			}

			if (SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE == (SDL_pwrss_vd_mode)ov_uv)
			{
				pPokCfg.trim   = (SDL_pwrss_trim)127U;
				pPokCfg.trimOV = (SDL_pwrss_trim)SDL_PWRSS_TRIM_NO_ACTION;
			}
			else if (SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE == (SDL_pwrss_vd_mode)ov_uv)
			{
				pPokCfg.trim   = (SDL_pwrss_trim)SDL_PWRSS_TRIM_NO_ACTION;
				pPokCfg.trimOV = (SDL_pwrss_trim)0U;
			}
			else
			{
				pPokCfg.trim   = (SDL_pwrss_trim)SDL_PWRSS_TRIM_NO_ACTION;
				pPokCfg.trimOV = (SDL_pwrss_trim)SDL_PWRSS_TRIM_NO_ACTION;
			}

			if (SDL_PASS == FltM_POK_setConfig(selected_coreID, &pPokCfg))
			{
				ReturnType = E_OK;
			}
			else
			{
				ReturnType = E_NOT_OK;
			}
		}
		#endif
			break;
    /* DID: 2E 4F 09 00 88 01 00 00*/
    /*
    * Flash Integrity Checksum Calculation Note:
    *
    * Full checksum verification takes approximately 60 seconds to complete.
    * After 60 seconds, the calculated checksum matches the golden value stored 
    * at DDR_CODE_APP_CHKSUM (0x82600000).
    * 
    * Therefore, for FIT fault injection testing, the golden checksum must be 
    * corrupted before 60 seconds after boot. Injecting fault after 60s 
    * will not trigger failure as calculation has already completed.
    */
    case CDD_FITMANAGER_CDD_MCUFIT_FLSINTEGRITY_TEST_ID:
    #if (FLTM_FLSINTEGRITY_ENABLE == STD_ON)
        chksum_ptr = (volatile uint16_t *)(uintptr_t)DDR_CODE_APP_CHKSUM_ADDRESS;
        *chksum_ptr = ~(*chksum_ptr);        // Corrupt the 16-bit checksum
		ReturnType = E_OK; 
    #endif
    break;

		default:
			ReturnType = E_NOT_OK;
			break;
	}

	return ReturnType;
}


#ifdef cCDD_MUCFIT_ENABLE_MEMORYMAP
#define CDD_MCUFIT_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif /*CDD_MCUFIT_C*/

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_ */

/*------------------------------------------------------------------------------
                               REVISION HISTORY
------------------------------------------------------------------------------*/
/*============================================================================
**
**============================================================================
**                  R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**============================================================================
Date              : 28/Jun/2025
By                : RRAJAGO2
Traceability      :
Change Description: Initial Version
**============================================================================
**==========================================================================*/


