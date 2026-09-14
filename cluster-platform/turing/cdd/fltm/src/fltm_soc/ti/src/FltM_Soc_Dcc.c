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
 * @file        FltM_Dcc.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_DCC_C_
#define  FLTM_SOC_DCC_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Cfg.h"
#include "FltM_Soc_Dcc.h"


#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_DCC_ENABLE == STD_ON)
/*****************************************************************************
*                                 Macro Definitions                          *
******************************************************************************/
#define LLD_MCU_CTRL_MMR           ((LLD_mcu_ctrl_mmr_cfg0Regs*)0x04500000U)

#define MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN              0x00000100U
#define MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN_PROXY        0x00000100U
#define MCU_PLL_BYP_ON_CLOCKLOSS_EN                  0x00010000U

/**< Maximum value that can be held in the COUNT0 register (ref clock) */
#define APP_DCC_SRC0_MAX_VAL            (0xFFFFFU)
/**< Maximum value that can be held in the VALID0 register (ref clock) */
#define APP_DCC_SRC0_VALID_MAX_VAL      (0x0FFFFU)
/**< Maximum value that can be held in the COUNT1 register (test clock) */
#define APP_DCC_SRC1_MAX_VAL            (0xFFFFFU)

#define FLTM_DCC_INVALID_INSTANCE       99U

#define FLTM_DCC_SYSCLK_125MHz          125000000U
#define FLTM_DCC_SYSCLK_100MHz          100000000U
#define FLTM_DCC_ARRAY_SIZE(array)      ((uint8)(sizeof(array) / sizeof((array)[0])))
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
/* Function to set the seed values */
static Std_ReturnType FltM_Dcc_SetSeedVals(uint32_t refClkFreq,
                                           uint32_t testClkFreq,
                                           uint32_t fsysclk,
                                           uint32_t driftPer,
                                           SDL_DCC_Config *configParams);
                                    

/* Function to find the triggered DCC instance from ESM call back */
static SDL_DCC_Inst FltM_Dcc_GetTriggeredDccInstance(SDL_ESM_Inst esmInst,
                                  uint32_t intSrc);
static boolean FltM_Dcc_IsValidInstance(SDL_DCC_Inst dccInstance);

                                  
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static const FltM_DCCIntSrcMapping FltM_DCC_wkupDccMap[] =
    {
        {36, SDL_DCC_INST_MCU_DCC1},
        {37, SDL_DCC_INST_MCU_DCC0}
    };
static const FltM_DCCIntSrcMapping FltM_DCC_mainDccMap[] =
    {
        {73, SDL_DCC_INST_DCC7},
        {79, SDL_DCC_INST_DCC6},
        {112, SDL_DCC_INST_DCC0},
        {113, SDL_DCC_INST_DCC1},
        {114, SDL_DCC_INST_DCC2},
        {115, SDL_DCC_INST_DCC3},
        {116, SDL_DCC_INST_DCC4},
        {117, SDL_DCC_INST_DCC5},
        {223, SDL_DCC_INST_DCC8}
    };

/*============================================================================
**
** Function Name    :   FltM_Dcc_IsValidInstance
**
** Visibility       :   Private
**
** Description      :   Validates the resolved DCC instance
**
**==========================================================================*/
static boolean FltM_Dcc_IsValidInstance(SDL_DCC_Inst dccInstance)
{
    boolean isValid = FALSE;

    if ((dccInstance >= SDL_DCC_INST_DCC0) &&
        (dccInstance < SDL_DCC_INVALID_INSTANCE))
    {
        isValid = TRUE;
    }
    return isValid;
}

/*****************************************************************************
*                             Functions                                      *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_Dcc_Init
**
** Visibility       :   public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   FltM_Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Dcc_Init(void)
{
    /* Declarations of variables */
    Std_ReturnType retVal = E_OK;
    int32_t  SdlretVal = SDL_EFAIL;
    uint32_t refclkFreq, monclkFreq, refClkRatioNum, testClkRatioNum, fsysclk;
    (void)refClkRatioNum;
    (void)testClkRatioNum;

    SDL_DCC_Config configParams;
    uint8 CurrDccInst = 0;

    /* Configure all DCC instances configured */
    for(CurrDccInst = 0; (CurrDccInst < DCC_INSTANCE_CONFIGURED); CurrDccInst++)
    {
        if(retVal == E_OK)
        {
            refclkFreq = Dcc_Config[CurrDccInst].refclkFreq;
            monclkFreq = Dcc_Config[CurrDccInst].monclkFreq;
            configParams.clk0Src = Dcc_Config[CurrDccInst].refclk;
            configParams.clk1Src = Dcc_Config[CurrDccInst].monclk;
            configParams.mode = Dcc_Config[CurrDccInst].mode;
            
            /* Ref  e2e  #1548824  : TI   suggestion on setting FSYSCLK  */
            if((Dcc_Config[CurrDccInst].dccInst == SDL_DCC_INST_MCU_DCC0) || 
                        (Dcc_Config[CurrDccInst].dccInst == SDL_DCC_INST_MCU_DCC1))
            {
                fsysclk = FLTM_DCC_SYSCLK_100MHz;
            }
            else
            {
                fsysclk = FLTM_DCC_SYSCLK_125MHz;
            }

            /* Get the seed values for given clock selections and allowed drift */
            retVal = FltM_Dcc_SetSeedVals(refclkFreq, monclkFreq, fsysclk,
                                Dcc_Config[CurrDccInst].DriftVal, &configParams);

            /* Configure the DCC */
            if(retVal == E_OK)
            {
                SdlretVal = SDL_DCC_configure(Dcc_Config[CurrDccInst].dccInst,
                                                                    &configParams);
            }
            else
            {
                /* None */
            }
            if (SDL_PASS == SdlretVal)
            {
                /* Verify the DCC configuration is valid */
                SdlretVal = SDL_DCC_verifyConfig(Dcc_Config[CurrDccInst].dccInst,
                                                                    &configParams);
            }
            else
            {
                SdlretVal = SDL_EFAIL;
            }
            if (SdlretVal == SDL_PASS)
            {
                /* Enable ERROR interrupt */
                (void)SDL_DCC_enableIntr(Dcc_Config[CurrDccInst].dccInst, SDL_DCC_INTERRUPT_ERR);

                if(Dcc_Config[CurrDccInst].mode != SDL_DCC_MODE_CONTINUOUS)
                {
                    (void)SDL_DCC_enableIntr(Dcc_Config[CurrDccInst].dccInst, SDL_DCC_INTERRUPT_DONE);
                }

                /* Enable Continuous DCC operation */
                (void)SDL_DCC_enable(Dcc_Config[CurrDccInst].dccInst);
            }
            else
            {
                SdlretVal = SDL_EFAIL;
            }
            if(SdlretVal != SDL_PASS)
            {
                retVal = E_NOT_OK;
            }
            else
            {
                /* Do Nothing */
            }
        }
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   FltM_DCC_ReadBack
**
** Visibility       :   Public
**
** Description      :   Periodic Readback for DCC.
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
Std_ReturnType FltM_DCC_ReadBack(void)
{
    uint8 index;
    SDL_DCC_Config configParams;
    int32_t  SdlretVal = SDL_EFAIL;
    Std_ReturnType retval = E_OK;
    uint32_t refclkFreq, monclkFreq, refClkRatioNum, testClkRatioNum, fsysclk;
    (void)refClkRatioNum;
    (void)testClkRatioNum;

    for(index = 0; (index < DCC_INSTANCE_CONFIGURED); index++)
    {
        if(retval == E_OK)
        {
            refclkFreq = Dcc_Config[index].refclkFreq;
            monclkFreq = Dcc_Config[index].monclkFreq;

            configParams.mode = Dcc_Config[index].mode;
            configParams.clk0Src = Dcc_Config[index].refclk;
            configParams.clk1Src = Dcc_Config[index].monclk;
            
            if((Dcc_Config[index].dccInst == SDL_DCC_INST_MCU_DCC0) || 
                        (Dcc_Config[index].dccInst == SDL_DCC_INST_MCU_DCC1))
            {
                fsysclk = FLTM_DCC_SYSCLK_100MHz;
            }
            else
            {
                fsysclk = FLTM_DCC_SYSCLK_125MHz;
            }

            /* Get the seed values for given clock selections and allowed drift */
            retval = FltM_Dcc_SetSeedVals(refclkFreq, monclkFreq, fsysclk,
                                        Dcc_Config[index].DriftVal, &configParams);

            if(retval == E_OK)
            {
                /* Verify the configuration of each configured DCC instance */
                SdlretVal = SDL_DCC_verifyConfig(Dcc_Config[index].dccInst,
                                                                    &configParams);
            }
            else
            {
                SdlretVal = SDL_EFAIL;
            }
            if(SdlretVal == SDL_PASS)
            {
                retval = E_OK;
            }
            else
            {
                retval = E_NOT_OK;
            }
        }
    }
    return(retval);
}

/*============================================================================
**
** Function Name    :   FltM_DCC_Disable
**
** Visibility       :   Public
**
** Description      :   The FltM_DCC_Disable function is called to disable DCC
**                      safety feature.
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
int32_t FltM_Dcc_Disable(void)
{
    uint8 index;
    int32_t retVal = SDL_EFAIL;
    for (index = 0; index < DCC_INSTANCE_CONFIGURED; index++)
    {
        retVal = SDL_DCC_disable(Dcc_Config[index].dccInst);
    }
    return retVal;
}

#if(DCC_FAULT_INJECT_TEST == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_Dcc_InjectFault
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to inject DCC Failure
**
** Invocation       :   Application
**
** Inputs           :   Index of Configuration structure
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Dcc_InjectFault(uint8 InjectIndex)
{
    /* Declarations of variables */
    Std_ReturnType retVal = E_OK;
    int32_t  SdlretVal = SDL_EFAIL;
    uint32_t refclkFreq, monclkFreq, refClkRatioNum, testClkRatioNum, fsysclk;
    (void)refClkRatioNum;
    (void)testClkRatioNum;

    SDL_DCC_Config configParams;
    
    (void)FltM_Dcc_Disable();

    if((InjectIndex != FLTM_DCC_INVALID_INSTANCE) && (InjectIndex < DCC_INSTANCE_CONFIGURED))
    {
        refclkFreq = Dcc_Config[InjectIndex].refclkFreq;
        monclkFreq = Dcc_Config[InjectIndex].monclkFreq;
        configParams.clk0Src = Dcc_Config[InjectIndex].refclk;
        configParams.clk1Src = Dcc_Config[InjectIndex].monclk;
        configParams.mode = Dcc_Config[InjectIndex].mode;
        
		/* Changing  the  clock manually  */
		monclkFreq *= 2u;
        /* Ref  e2e  #1548824  : TI   suggestion on setting FSYSCLK  */
        if((Dcc_Config[InjectIndex].dccInst == SDL_DCC_INST_MCU_DCC0) || 
                     (Dcc_Config[InjectIndex].dccInst == SDL_DCC_INST_MCU_DCC1))
        {
            fsysclk = FLTM_DCC_SYSCLK_100MHz;
        }
        else
        {
            fsysclk = FLTM_DCC_SYSCLK_125MHz;
        }

        /* Get the seed values for given clock selections and allowed drift */
        retVal = FltM_Dcc_SetSeedVals(refclkFreq, monclkFreq, fsysclk,
                               Dcc_Config[InjectIndex].DriftVal, &configParams);


        /* Configure the DCC */
        if(retVal == E_OK)
        {
            SdlretVal = SDL_DCC_configure(Dcc_Config[InjectIndex].dccInst,
                                                                 &configParams);
        }
        else
        {
            /* None */
        }
        if (SDL_PASS == SdlretVal)
        {
            /* Verify the DCC configuration is valid */
            SdlretVal = SDL_DCC_verifyConfig(Dcc_Config[InjectIndex].dccInst,
                                                                 &configParams);
        }
        else
        {
            SdlretVal = SDL_EFAIL;
        }
        if (SdlretVal == SDL_PASS)
        {
            /* Enable ERROR interrupt */
            (void)SDL_DCC_enableIntr(Dcc_Config[InjectIndex].dccInst, SDL_DCC_INTERRUPT_ERR);
            /* Enable Continuous DCC operation */
            (void)SDL_DCC_enable(Dcc_Config[InjectIndex].dccInst);
        }
        else
        {
            SdlretVal = SDL_EFAIL;
        }
        if(SdlretVal != SDL_PASS)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }
    return retVal;
}
#endif


/*============================================================================
**
** Function Name    :   FltM_Dcc_SetSeedVals
**
** Visibility       :   Private
**
** Description      :   The Init function is called to set the seed values
**                      based on the input frequencies.
**
** Invocation       :   DCC Init
**
** Inputs           :   clock freq, sysclk and dcc configs
**
** Outputs          :   seed values
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_Dcc_SetSeedVals(uint32_t refClkFreq,
                                           uint32_t testClkFreq,
                                           uint32_t fsysclk,
                                           uint32_t driftPer,
                                           SDL_DCC_Config *configParams)
{
    Std_ReturnType retVal = E_OK;
    uint64_t async_error;
    uint64_t dcc_error;
    uint64_t min_accuracy_scaled;
    uint64_t window;
    uint64_t freq_error_allowed;
    uint64_t total_error;
    uint32_t driftPer_local = driftPer;

        /* Input validation */
    if ((refClkFreq == 0u) || (testClkFreq == 0u) ||
        (driftPer == 0u) || (configParams == NULL))
    {
        retVal = E_NOT_OK;
        if (configParams == NULL)
        {
            FltM_Soc_Det_ReportError(FLTM_DCC_SETSEEDVALS_API, FLTM_ERR_NULL_POINTER);
        }
        else
        {
            FltM_Soc_Det_ReportError(FLTM_DCC_SETSEEDVALS_API, FLTM_ERR_INVALID_PARAM);
        }
    }
    else
    {
        if (testClkFreq > refClkFreq)
        {
            async_error = 2ULL + (2ULL * (fsysclk / refClkFreq));
        }
        else if (testClkFreq < refClkFreq)
        {
            async_error = (2ULL * (refClkFreq / testClkFreq)) +
                                                  (2ULL * (fsysclk / refClkFreq));
        }
        else
        {
            async_error = 2ULL + (2ULL * (fsysclk / refClkFreq));
        }
        
        /* Add fixed error margin to async error */
        dcc_error = async_error + 8ULL;
        
        /* Calculate minimum accuracy required, scaled to avoid floating point */
        min_accuracy_scaled = (100ULL * dcc_error * testClkFreq) / refClkFreq;
        uint64_t min_accuracy = min_accuracy_scaled / 1048575ULL;

        
        /* Ensure drift percentage is not below minimum accuracy */
        if (driftPer_local < min_accuracy)
        {
            driftPer_local = (uint32_t)min_accuracy;
        }

        /* Calculate window size and allowable frequency error */
        window = (dcc_error * 100ULL) / driftPer_local;
        freq_error_allowed = (window * driftPer_local) / 100ULL;
        total_error = dcc_error + freq_error_allowed;

        /* Check for overflow before assigning */
        if (((window - total_error) > DCC_UINT32_MAX) ||
            ((2ULL * total_error) > DCC_UINT32_MAX) ||
            ((((window * testClkFreq) / refClkFreq)) > DCC_UINT32_MAX))
        {
            retVal = E_NOT_OK;
            FltM_Soc_Det_ReportError(FLTM_DCC_SETSEEDVALS_API, FLTM_ERR_INVALID_PARAM);
        }
        else
        {
            /* Assign calculated seed values to configuration structure */
            configParams->clk0Seed = (uint32_t)(window - total_error);
            configParams->clk0ValidSeed = (uint32_t)(2ULL * total_error);
            configParams->clk1Seed = 
                                    (uint32_t)((window * testClkFreq) / refClkFreq);
        }
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   FltM_Dcc_GetTriggeredDccInstance
**
** Visibility       :   Private
**
** Description      :   This function returns the DCC instance from which the
**                      ESM interrupt is triggered.
**
** Invocation       :   DCC Init
**
** Inputs           :   clock freq, ratio and drift percentage
**
** Outputs          :   refClkRatioNum and testClkRatioNum
**
** Critical Section :   No
**
**==========================================================================*/
static SDL_DCC_Inst FltM_Dcc_GetTriggeredDccInstance(SDL_ESM_Inst esmInst, uint32_t intSrc)
{
    SDL_DCC_Inst TriggdInstance = SDL_DCC_INVALID_INSTANCE;
    const FltM_DCCIntSrcMapping *map = NULL;
    uint8 mapSize = 0;
    uint8 index = 0;
    /* Check for WKUP ESM */
    if (esmInst == SDL_ESM_INST_WKUP_ESM0)
    {
        map = FltM_DCC_wkupDccMap;
        mapSize = FLTM_DCC_ARRAY_SIZE(FltM_DCC_wkupDccMap);
    }
    /* Check for Main ESM */
    else if (esmInst == SDL_ESM_INST_MAIN_ESM0)
    {
        map = FltM_DCC_mainDccMap;
        mapSize = FLTM_DCC_ARRAY_SIZE(FltM_DCC_mainDccMap);
    }
    else
    {
        /*Do Nothing*/
    }
    /* Find the DCC Instance from the lookup table */
    for (index = 0; ((index < mapSize) && (TriggdInstance == SDL_DCC_INVALID_INSTANCE)); ++index)
    {
        if (map[index].intSrc == intSrc)
        {
            TriggdInstance = map[index].dccInst;
        }
    }
    return TriggdInstance;
}

/*============================================================================
**
** Function Name    :   FltM_Dcc_CallBackFunc
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to find the DCC error details
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
int32_t FltM_Dcc_CallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                          uint32_t grpChannel,  uint32_t index, uint32_t intSrc, SDL_DCC_Inst *dccInst)
{
    (void)grpChannel;
    (void)index;
    (void)esmIntrType;

    SDL_DCC_Inst CurDccInst = SDL_DCC_INVALID_INSTANCE;
    int32_t retVal = E_OK;

    /* Get the DCC instance from which error is triggered */
    CurDccInst = FltM_Dcc_GetTriggeredDccInstance(esmInst,intSrc);
    if (FltM_Dcc_IsValidInstance(CurDccInst) == TRUE)
    {
        if (dccInst != NULL_PTR)
        {
          *dccInst = CurDccInst;
        }
        /* Clear DCC event */
        retVal = SDL_DCC_clearIntr(CurDccInst, SDL_DCC_INTERRUPT_ERR);
    }
    else
    {
        retVal = SDL_EFAIL;
        FltM_Soc_Det_ReportError(FLTM_DCC_CALLBACK_API, FLTM_ERR_INVALID_PARAM);
    }

    return(retVal);

}

/*============================================================================
**
** Function Name    :   FltM_OscClkLossDetection_Enable
**
** Visibility       :   Public
**
** Description      :   The Init function is called to enable HFOSC0 clock loss
**                      detection feature.
**
** Invocation       :   FltM Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void FltM_OscClkLossDetection_Enable(void)
{
    uint32 regVal;

    /* Set MCU_CTRL_MMR0_MCU_PLL_CLKSEL_PROXY.MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN_PROXY) */
    /* REQ PE4TI29141-774 */
    #if 0
      /* As per TI Feedback, PROXY setting is not required */
      regVal = LLD_REG32_RD(&LLD_MCU_CTRL_MMR->MCU_PLL_CLKSEL_PROXY);
      regVal |= MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN_PROXY;
      LLD_REG32_WR(&LLD_MCU_CTRL_MMR->MCU_PLL_CLKSEL_PROXY, regVal);
    #endif

    /* Configure PLL bypass mux to automatically switch the clock source to the
    reference clock when the PLL losses lock detected.*/
    /* REQ PE4TI29141-774 */

    /* Enable MCU_CTRL_MMR0_MCU_PLL_CLKSEL.MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN */
    regVal = LLD_REG32_RD(&LLD_MCU_CTRL_MMR->MCU_PLL_CLKSEL);
    regVal |= MCU_PLL_CLKSEL_CLKLOSS_SWTCH_EN;
    LLD_REG32_WR(&LLD_MCU_CTRL_MMR->MCU_PLL_CLKSEL, regVal);

    /* As per TI feedback in e2e #1500602, default value of BYP_ON_LOCKLOSS bit
       in PLL[0,1,2,5,7,8,12,15,17]_CTRL registers is set to 1 by default */
}

#endif /*#if(FLTM_DCC_ENABLE == STD_ON)*/

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
Date              :22-Apr-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-7898
Change Description:DCC Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :13-Aug-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-9628
Change Description:Clock Seedvalue calculation and update
-----------------------------------------------------------------------------*/
