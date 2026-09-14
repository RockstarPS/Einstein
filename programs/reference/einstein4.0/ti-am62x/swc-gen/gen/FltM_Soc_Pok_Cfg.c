/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2025. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM_Soc_Pok_Cfg.c
 * @details     <b> Pok to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_POK_CFG_C_
#define  FLTM_SOC_POK_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Pok_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if (FLTM_POK_ENABLE == STD_ON)
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* Configuration structure for POK */
const FltM_POK_config FltM_POK_init_cfg[FLTM_NUM_POK_CFG] = 
{  
    /* OV and UV of VDDS_DDRIO - PP */
    {
        /* Pok_Instance */
        SDL_POK_VDDS_DDRIO_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            0x2B,
            /* Trim Value for OV */
            0x28,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    }, 
    /* OV and UV of VDDR_CORE - PP */
    {
        /* Pok_Instance */
        SDL_POK_VDDR_CORE_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE, 
            /* Trim Value for UV */
            0x18,
            /* Trim Value for OV */
            0x11,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },

    /* OV and UV of VMON_CAP_MCU - PP */
    {
        /* Pok_Instance */
        SDL_POK_VMON_CAP_MCU_GENERAL_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE, 
            /* Trim Value for UV */
            0x22, 
            /* Trim Value for OV */
            0x1F,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },

    /* OV and UV of VDDSHV_MAIN_1P8 - PP */
    {
        /* Pok_Instance */
        SDL_POK_VDDSHV_MAIN_1P8_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            0x29, 
            /* Trim Value for OV */
            0x27,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
    /* OV and UV of VDDSHV_MAIN_3P - PP */
    {
        /* Pok_Instance */
        SDL_POK_VDDSHV_MAIN_3P3_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            0x29, 
            /* Trim Value for OV */
             0x27,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
    /* OV for VDD_CORE */
    {
        /* Pok_Instance */
        SDL_POK_VDD_MCU_OV_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_HYSTERESIS_NO_ACTION,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            (uint8)SDL_PWRSS_TRIM_NO_ACTION, 
            /* Trim Value for OV */
            0x11,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
    /* UV for VDD_CORE */
    {
        /* Pok_Instance */
        SDL_POR_VDD_MCU_UV_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_HYSTERESIS_NO_ACTION,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            0x18, 
            /* Trim Value for OV */
            (uint8)SDL_PWRSS_TRIM_NO_ACTION,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
    /* OV for VDDA_MCU */
    {
        /* Pok_Instance */
        SDL_POR_VDDA_MCU_OV_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_HYSTERESIS_NO_ACTION,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            (uint8)SDL_PWRSS_TRIM_NO_ACTION,
            /* Trim Value for OV */
            0x27, 
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
    
    /* UV for VDDA_MCU */
    {
        /* Pok_Instance */      
        SDL_POR_VDDA_MCU_UV_ID,
        {
            /* hysteresis control - UV */
            (uint8)SDL_PWRSS_SET_HYSTERESIS_ENABLE,
            /* hysteresis control - OV */
            (uint8)SDL_PWRSS_HYSTERESIS_NO_ACTION,
            /* Voltage Detection Mode control */
            (uint8)SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            /* Trim Value for UV */
            0x29, 
            /* Trim Value for OV */
            (uint8)SDL_PWRSS_TRIM_NO_ACTION,
            /* POK Detection Enable */
            (uint8)SDL_POK_DETECTION_ENABLE,
            /* POK Enable Source control */
            (uint8)SDL_POK_ENSEL_NO_ACTION,
            /* Deglitch control */
            (uint8)SDL_PWRSS_DEGLITCH_20US
        }
    },
};


#endif /*#if (FLTM_POK_ENABLE == STD_ON)*/

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :12-Nov-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-10706
Change Description:POK configuration updated for specific voltage levels
-----------------------------------------------------------------------------*/

