/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
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
 * @file        FltM_Soc.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_POK_C_
#define  FLTM_SOC_POK_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Pok.h"
#include "FltM_Soc_Types.h"
#include "FltM_Soc_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_POK_ENABLE == STD_ON)
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef FLTM_POK_TRIM_VALUE
#define FLTM_POK_TRIM_VALUE                                                (0u)
#endif
#ifndef FLTM_POK_TRIM_OV_VALUE
#define FLTM_POK_TRIM_OV_VALUE                                             (45u)
#endif
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static int32_t deactivate_trigger(const uint32_t *esm_err_sig ); 
static int32_t sdlGetInstance(SDL_POK_Inst *instance,const uint32_t *esm_err_sig);
static boolean FltM_POK_IsValidInstance(SDL_POK_Inst instance);
static boolean FltM_POK_IsValidPrgInstance(SDL_PRG_Inst instance);

/*****************************************************************************
*                             Functions                                      *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_POK_Init
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to during init
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void FltM_POK_Init(void)
{
    uint8 pok_idx;
    int32_t sdlRet = SDL_PASS;
    SDL_POK_config pokcfg;
    /* Loop through all configurations of POK */
    for (pok_idx = 0u; ((pok_idx < FLTM_NUM_POK_CFG) && (sdlRet == SDL_PASS)); pok_idx++)
    {
        pokcfg = FltM_POK_init_cfg[pok_idx].FltM_POK_cfg;
        sdlRet = FltM_POK_setConfig(FltM_POK_init_cfg[pok_idx].instance, &pokcfg);
    }

    /*
     * Preserve the original behavior of attempting to enable PP even if
     * a prior configuration step failed.
     */
    if (FltM_POK_IsValidPrgInstance((SDL_PRG_Inst)FLTM_POK_PP_ENABLE_PRG) == TRUE)
    {
        sdlRet = SDL_POK_enablePP((SDL_PRG_Inst)FLTM_POK_PP_ENABLE_PRG, true);
        if (sdlRet != SDL_PASS)
        {
            FltM_Soc_Det_ReportError(FLTM_POK_INIT_API, FLTM_ERR_OPERATION_FAILED);
        }
    }
    else
    {
        FltM_Soc_Det_ReportError(FLTM_POK_INIT_API, FLTM_ERR_INVALID_PARAM);
    }
}

/*============================================================================
**
** Function Name    :   FltM_POK_setConfig
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to trigger OV/UV error
**
** Invocation       :   Application
**
** Inputs           :   instance -  Instance of POK
**                  :   pPokCfg - Configuration of POK
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
int32_t FltM_POK_setConfig(SDL_POK_Inst instance, SDL_POK_config *pPokCfg)
{
    int32_t sdlRet = SDL_EFAIL;

    if (pPokCfg == NULL)
    {
        FltM_Soc_Det_ReportError(FLTM_POK_SETCONFIG_API, FLTM_ERR_NULL_POINTER);
    }
    else if (FltM_POK_IsValidInstance(instance) == FALSE)
    {
        FltM_Soc_Det_ReportError(FLTM_POK_SETCONFIG_API, FLTM_ERR_INVALID_PARAM);
    }
    else
    {
        sdlRet = SDL_POK_init(instance, pPokCfg);
        if (sdlRet != SDL_PASS)
        {
            FltM_Soc_Det_ReportError(FLTM_POK_SETCONFIG_API, FLTM_ERR_OPERATION_FAILED);
        }
    }
    return(sdlRet);
}

/*============================================================================
**
** Function Name    :   FltM_POK_IsValidInstance
**
** Visibility       :   Private
**
** Description      :   Checks whether the input POK instance is valid
**
**==========================================================================*/
static boolean FltM_POK_IsValidInstance(SDL_POK_Inst instance)
{
    boolean isValid = FALSE;

    if ((instance >= (SDL_POK_Inst)SDL_FIRST_POK_ID) &&
        (instance <= (SDL_POK_Inst)SDL_LAST_POK_ID))
    {
        isValid = TRUE;
    }
    return isValid;
}

/*============================================================================
**
** Function Name    :   FltM_POK_IsValidPrgInstance
**
** Visibility       :   Private
**
** Description      :   Checks whether the input PRG instance is valid
**
**==========================================================================*/
static boolean FltM_POK_IsValidPrgInstance(SDL_PRG_Inst instance)
{
    boolean isValid = FALSE;

    if ((instance >= (SDL_PRG_Inst)SDL_POK_PRG_FIRST_ID) &&
        (instance <= (SDL_PRG_Inst)SDL_POK_PRG_LAST_ID))
    {
        isValid = TRUE;
    }
    return isValid;
}

/*============================================================================
**
** Function Name    :   deactivate_trigger
**
** Visibility       :   Private
**
** Description      :   The function to be invoked to clear OV/UV interupt
**
** Invocation       :   FltM_POK_CallBackFunc
**
** Inputs           :   esm_err_sig -  ESM error signal
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static  int32_t deactivate_trigger(const uint32_t *esm_err_sig )
{
    SDL_POK_Inst               instance = FLTM_POK_INVALID_INSTANCE;
    SDL_POK_config             pPokCfg;
    SDL_pokVal_t               pPokVal;
    uint32_t                   pbaseAddress = 0u;
    SDL_mcuCtrlRegsBase_t    *pBaseAddr = (SDL_mcuCtrlRegsBase_t *)0;
    int32_t                    sdlRet = SDL_EFAIL;

    if (esm_err_sig == NULL)
    {
        FltM_Soc_Det_ReportError(FLTM_POK_DEACTIVATE_TRIGGER_API, FLTM_ERR_NULL_POINTER);
    }
    else if (SDL_POK_getBaseaddr(SDL_POK_MCU_CTRL_MMR0, &pbaseAddress) == FALSE)
    {
        FltM_Soc_Det_ReportError(FLTM_POK_DEACTIVATE_TRIGGER_API, FLTM_ERR_INVALID_ADDRESS_RANGE);
    }
    else
    {
        pBaseAddr = (SDL_mcuCtrlRegsBase_t *) pbaseAddress;
        sdlRet = sdlGetInstance(&instance, esm_err_sig);
        if (sdlRet == SDL_PASS)
        {
            /* Set to default values */
            pPokCfg.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION;
            pPokCfg.voltDetMode = SDL_PWRSS_GET_VOLTAGE_DET_MODE;
            pPokCfg.trim = SDL_PWRSS_TRIM_NO_ACTION;
            pPokCfg.detectionCtrl = SDL_POK_DETECTION_NO_ACTION;
            pPokCfg.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION;
            pPokCfg.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION;
            pPokCfg.trimOV = SDL_PWRSS_TRIM_NO_ACTION;
            pPokCfg.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION;

            sdlRet = SDL_pokGetControl(pBaseAddr, &pPokCfg, &pPokVal, instance);
            if (sdlRet == SDL_PASS)
            {
                /* Re-configure to "good" setting */
                if (pPokVal.voltDetMode == SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE)
                {
                    pPokCfg.trim = FLTM_POK_TRIM_VALUE;
                    pPokCfg.trimOV = SDL_PWRSS_TRIM_NO_ACTION;
                }
                else if (pPokVal.voltDetMode == SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE)
                {
                    pPokCfg.trimOV = FLTM_POK_TRIM_OV_VALUE;
                    pPokCfg.trim = SDL_PWRSS_TRIM_NO_ACTION;
                }
                else
                {
                    pPokCfg.trim = FLTM_POK_TRIM_VALUE;
                }

                pPokCfg.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION;
                pPokCfg.voltDetMode = pPokVal.voltDetMode;
                pPokCfg.detectionCtrl = SDL_POK_DETECTION_NO_ACTION;
                pPokCfg.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION;
                pPokCfg.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION;
                pPokCfg.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION;
                sdlRet = SDL_POK_init(instance,&pPokCfg);
                if (sdlRet != SDL_PASS)
                {
                    FltM_Soc_Det_ReportError(FLTM_POK_DEACTIVATE_TRIGGER_API, FLTM_ERR_OPERATION_FAILED);
                }
            }
            else
            {
                FltM_Soc_Det_ReportError(FLTM_POK_DEACTIVATE_TRIGGER_API, FLTM_ERR_OPERATION_FAILED);
            }
        }
    }

    return sdlRet;
}
/*============================================================================
**
** Function Name    :   sdlGetInstance
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to find the POK instance
**
** Invocation       :   deactivate_trigger
**
** Inputs           :   esm_err_sig -  ESM error signal
**
** Outputs          :   instance - Instance
**
** Critical Section :   No
**
**==========================================================================*/
static int32_t sdlGetInstance(SDL_POK_Inst *instance,const uint32_t *esm_err_sig)
{
    int32_t sdlRet = SDL_PASS;

    if (instance == NULL)
    {
        sdlRet = SDL_EFAIL;
        FltM_Soc_Det_ReportError(FLTM_POK_GETINSTANCE_API, FLTM_ERR_NULL_POINTER);
    }
    else if (esm_err_sig == NULL)
    {
        *instance = FLTM_POK_INVALID_INSTANCE;
        sdlRet = SDL_EFAIL;
        FltM_Soc_Det_ReportError(FLTM_POK_GETINSTANCE_API, FLTM_ERR_NULL_POINTER);
    }
    else
    {
        switch (*esm_err_sig)
        {
            case MCU_ESM_ERR_SIG_VDDA_PMIC_IN_UV:
                *instance = SDL_POK_VDDA_PMIC_IN_ID;
                break;
            case MCU_ESM_ERR_SIG_VDD_MCU_OV:
                 *instance = SDL_POK_VDD_MCU_OV_ID;
                 break;
            case MCU_ESM_ERR_SIG_VDDS_DDRIO_UV:
            case MCU_ESM_ERR_SIG_VDDS_DDRIO_OV:
                *instance    = SDL_POK_VDDS_DDRIO_ID;
                break;
            case MCU_ESM_ERR_SIG_VDDR_CORE_UV:
            case MCU_ESM_ERR_SIG_VDDR_CORE_OV:
                *instance    = SDL_POK_VDDR_CORE_ID;
                break;
            case MCU_ESM_ERR_SIG_VMON_CAP_MCU_GENERAL_UV:
            case MCU_ESM_ERR_SIG_VMON_CAP_MCU_GENERAL_OV:
                *instance = SDL_POK_VMON_CAP_MCU_GENERAL_ID;
                break;
            case MCU_ESM_ERR_SIG_VDDSHV_MAIN_1P8_UV:
            case MCU_ESM_ERR_SIG_VDDSHV_MAIN_1P8_OV:
                *instance = SDL_POK_VDDSHV_MAIN_1P8_ID;
                break;
            case MCU_ESM_ERR_SIG_VDDSHV_MAIN_3P3_UV:
            case MCU_ESM_ERR_SIG_VDDSHV_MAIN_3P3_OV:
                *instance = SDL_POK_VDDSHV_MAIN_3P3_ID;
                break;

            case MCU_ESM_ERR_SIG_VDDA_MCU_UV:
                 *instance = SDL_POR_VDDA_MCU_UV_ID;
                 break;
            case MCU_ESM_ERR_SIG_VDDA_MCU_OV:
                 *instance = SDL_POR_VDDA_MCU_OV_ID;
                 break;
            case MCU_ESM_ERR_SIG_VDD_MCU_UV:
                 *instance = SDL_POR_VDD_MCU_UV_ID;
                 break;
            default:
                *instance = FLTM_POK_INVALID_INSTANCE;
                sdlRet = SDL_EFAIL;
                FltM_Soc_Det_ReportError(FLTM_POK_GETINSTANCE_API, FLTM_ERR_INVALID_PARAM);
                break;
        }

        if ((sdlRet == SDL_PASS) && (FltM_POK_IsValidInstance(*instance) == FALSE))
        {
            *instance = FLTM_POK_INVALID_INSTANCE;
            sdlRet = SDL_EFAIL;
            FltM_Soc_Det_ReportError(FLTM_POK_GETINSTANCE_API, FLTM_ERR_INVALID_PARAM);
        }
    }
    return sdlRet;
}

/*============================================================================
**
** Function Name    :   FltM_POK_CallBackFunc
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to trigger OV/UV error
**
** Invocation       :   Application
**
** Inputs           :   instance -  Instance of POK
**                  :   pPokCfg - Configuration of POK
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
int32_t FltM_POK_CallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,uint32_t grpChannel,
                            uint32_t index,uint32_t intSrc, SDL_POK_Inst *pokInst)
{
    int32_t retVal = SDL_PASS;
    int32_t deactivateRet = SDL_PASS;
    int32_t getInstanceRet = SDL_PASS;
    (void)index;
    (void)esmInst;
    (void)esmIntrType;
    (void)grpChannel;
    SDL_POK_Inst instance = FLTM_POK_INVALID_INSTANCE;

    getInstanceRet = sdlGetInstance(&instance, &intSrc);
    if (pokInst != NULL_PTR)
    {
      *pokInst = instance;
    }
    /* Disable the ESM Interrupt */
#if(FLTM_POK_TEST_ENABLE == STD_ON)
    deactivateRet = deactivate_trigger(&intSrc);
#endif /* #if(FLTM_POK_TEST_ENABLE == STD_ON) */
    retVal = SDL_ESM_clrNError(SDL_ESM_INST_WKUP_ESM0);
    if(retVal == SDL_PASS)
    {
        retVal = SDL_ESM_disableIntr((uint32_t)SDL_WKUP_ESM0_CFG_BASE,intSrc);
    }
    if ((retVal == SDL_PASS) && (deactivateRet != SDL_PASS))
    {
        retVal = deactivateRet;
    }
    if ((retVal == SDL_PASS) && (getInstanceRet != SDL_PASS))
    {
        retVal = getInstanceRet;
    }
    return retVal;
}

#endif /* #if(FLTM_POK_ENABLE == STD_ON) */

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
Date              :20-May-2025
By                :KPALANIV
Traceability      :PE4TI29141-8297
Change Description:POK Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/
