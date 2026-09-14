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
 * @file        FltM_Ecc.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_ECC_C_
#define  FLTM_SOC_ECC_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Ecc.h"
#include "FltM_Soc_Cfg.h"
#include "MemLib.h"

#if(FLTM_ECC_ENABLE == STD_ON)

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define SDL_PULSAR_EVNT_BUS_ESM_CLR                       (0x440001Cu)
#define FLTM_ECC_INJECT_FLIP_BITMASK                      (0x101U)
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static boolean FltM_ECC_IsInjectParamValid(uint8_t aggregator, uint8_t ramid, \
                                      SDL_ECC_InjectErrorType errortype);
/*****************************************************************************
*                             Functions                                      *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_ECC_Init_All
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of ECC.
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
Std_ReturnType FltM_ECC_Init_All(void) 
{
    int32_t status;
    SDL_ECC_InitConfig_t SDL_ECC_InitTemp;
	Std_ReturnType retval = E_OK;

    /* Loop through all the configured aggregators and initialize themS*/
    for (uint32_t i = 0; i < NUM_ECC_AGGR_CONFIGS; i++) {
        const ECC_AggregatorConfigType *cfg = globalECCConfigs[i];
        SDL_ECC_InitTemp.numRams = cfg->numRams;
        SDL_ECC_InitTemp.pMemSubTypeList = cfg->pMemSubTypes;
        status = SDL_ECC_init(cfg->aggregatorInstance, &SDL_ECC_InitTemp);
        if (status != SDL_PASS)
        {
            retval = E_NOT_OK;
            FltM_Soc_Det_ReportError(FLTM_ECC_INITALL_API_ID, FLTM_ERR_ECC_INIT_FAIL);
            break;
        }
    }

    if (retval == E_OK)
    {
        /* TCM ECC init: attempt all banks; any failure -> E_NOT_OK */
        status = SDL_ECC_configECCRam(SDL_ECC_R5F_MEM_SUBTYPE_ATCM0_BANK0_VECTOR_ID);
        if (status != SDL_PASS) 
        { 
            retval = E_NOT_OK;
            FltM_Soc_Det_ReportError(FLTM_ECC_INITALL_API_ID, FLTM_ERR_ECC_INIT_FAIL);
        }

        status = SDL_ECC_configECCRam(SDL_ECC_R5F_MEM_SUBTYPE_B0TCM0_BANK0_VECTOR_ID);
        if (status != SDL_PASS) 
        { 
            retval = E_NOT_OK;
            FltM_Soc_Det_ReportError(FLTM_ECC_INITALL_API_ID, FLTM_ERR_ECC_INIT_FAIL);
        }

        status = SDL_ECC_configECCRam(SDL_ECC_R5F_MEM_SUBTYPE_B1TCM0_BANK0_VECTOR_ID);
        if (status != SDL_PASS) 
        { 
            retval = E_NOT_OK;
            FltM_Soc_Det_ReportError(FLTM_ECC_INITALL_API_ID, FLTM_ERR_ECC_INIT_FAIL);
        }
    }

	if(retval == E_OK)
	{
        /*Enabling the Event bus*/
        SDL_UTILS_enable_event_bus();
		
	}
	
	return(retval);
}

/*============================================================================
**
** Function Name    :   FltM_ECC_ReadBack
**
** Visibility       :   Public
**
** Description      :   The verify configuration function is invoked periodically
**                      to check the configurations of ECC
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
Std_ReturnType FltM_ECC_ReadBack(void)
 {
    SDL_ECC_InitConfig_t SDL_ECC_InitTemp;
    SDL_ecc_aggrRegs *eccAggrRegs;
    int32_t retVal_status = SDL_EFAIL;
    Std_ReturnType retVal;
    uint8_t ramIdType = 0;
    uint8_t injectOnlyFlag;
    const SDL_RAMIdEntry_t *ramTable;
    boolean stopReadBack = FALSE;
    retVal = E_NOT_OK;

    /* Loop through all the configured aggregators */
    for (uint32_t i = 0; ((i < NUM_ECC_AGGR_CONFIGS) &&
                          (stopReadBack == FALSE)); i++)
    {
        const ECC_AggregatorConfigType *cfg = globalECCConfigs[i];
        SDL_ECC_InitTemp.numRams = cfg->numRams;
        /* Get the base address of the aggregator */
        eccAggrRegs = SDL_ECC_aggrTransBaseAddressTable[cfg->aggregatorInstance];

        if (SDL_ECC_InitTemp.numRams > 0u)
        {
            retVal_status = SDL_PASS;
        }
        else
        {
        retVal_status = SDL_EFAIL;
            stopReadBack = TRUE;
        }
        /* Loop through all configured RAMs of the aggregator*/
        for(uint32_t ram_idx = 0; ((ram_idx < SDL_ECC_InitTemp.numRams) &&
                                   (retVal_status != SDL_EFAIL)); ram_idx++)
        {
            /* Get the ram type and inject only flag information */
            ramTable = SDL_ECC_aggrTable[cfg->aggregatorInstance].ramTable;
            ramIdType = ramTable[ram_idx].ramIdType;
            injectOnlyFlag = ramTable[ram_idx].aggregatorTypeInjectOnly;

            /* If it is inject only, only ECC generation is supported (TI ticket raised)*/
            if(injectOnlyFlag == 1u)
            {
                retVal_status = SDL_ecc_aggrVerifyConfigEccRam(eccAggrRegs,ram_idx,true,false,false);
            }
            /* If it is INTERCONNECT, only ECC check is supported (TI ticket raised)*/
            else if (ramIdType == SDL_ECC_RAM_ID_TYPE_INTERCONNECT)
            {
                retVal_status = SDL_ecc_aggrVerifyConfigEccRam(eccAggrRegs,ram_idx,false,true,false);
            }
            /* If it is Wrapper, ECC generation,ECC check and RME is supported */
            else
            {
                retVal_status = SDL_ecc_aggrVerifyConfigEccRam(eccAggrRegs,ram_idx,true,true,true);
            }
        }
        if(retVal_status == SDL_EFAIL)
        {
            stopReadBack = TRUE;
        }
    }
    /* All configurations are passed*/
    if(retVal_status == SDL_PASS)
    {
        retVal = E_OK;
    }
    return(retVal);
}

/*============================================================================
**
** Function Name    :   FltM_ECC_CallBackFunc
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to find the ECC error details
**
** Invocation       :   Application
**
** Inputs           :   esmInst - Instance information
**                  :   esmIntrType - Interupt type
**                  :   grpChannel - Group information
**                  :   index - index information
**                  :   intSrc - interupt source
**
** Outputs          :   pEccErrorInfo      - ECC diagnostic information
**                      pEccErrorInfoValid - TRUE only when the diagnostic
**                                           information is available
**
** Critical Section :   No
**
**==========================================================================*/
int32_t FltM_ECC_CallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                              uint32_t grpChannel, uint32_t index, uint32_t intSrc,
                              SDL_ECC_ErrorInfo_t *pEccErrorInfo,
                              boolean *pEccErrorInfoValid)
{
    (void)esmIntrType;
    (void)grpChannel;
    (void)index;

    SDL_ECC_MemType eccmemtype;
    SDL_Ecc_AggrIntrSrc eccIntrSrc;
    int32_t retVal = SDL_PASS;
    int32_t esmInfoStatus = SDL_PASS;
    int32_t errInfoStatus = SDL_PASS;
    int32_t clearIntrStatus = SDL_PASS;
    int32_t ackIntrStatus = SDL_PASS;

    if (pEccErrorInfoValid != NULL_PTR)
    {
        *pEccErrorInfoValid = FALSE;
    }

    if ((pEccErrorInfo == NULL_PTR) || (pEccErrorInfoValid == NULL_PTR))
    {
        retVal = SDL_EFAIL;
        FltM_Soc_Det_ReportError(FLTM_ECC_CALLBACKFUNC_API_ID, FLTM_ERR_NULL_POINTER);
    }
    else if((intSrc == SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_COMMON0_ECC_DE_TO_ESM_0_0) ||
        (intSrc == SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_COMMON0_ECC_SE_TO_ESM_0_0))
    {
        uint32_t evntbus_esm_clr;

        /* To clear the ESM ECC events generated from R5FSS Core Memory,
        * read and write back the register SDL_PULSAR_EVNT_BUS_ESM_CLR */
        /* Read PULSAR event register. */
        evntbus_esm_clr = SDL_REG32_RD(SDL_PULSAR_EVNT_BUS_ESM_CLR);
        /* Write back the same data to clear the events */
        SDL_REG32_WR(SDL_PULSAR_EVNT_BUS_ESM_CLR, evntbus_esm_clr);
    }
    else
    {
        /* Get the interupt source and type */
        esmInfoStatus = SDL_ECC_getESMErrorInfo(esmInst, intSrc, &eccmemtype, &eccIntrSrc);
        if(esmInfoStatus != SDL_PASS)
        {
            retVal = esmInfoStatus;
            FltM_Soc_Det_ReportError(FLTM_ECC_CALLBACKFUNC_API_ID, FLTM_ERR_ECC_ESM_INFO_FAIL);
        }
        else
        {
          errInfoStatus = SDL_ECC_getErrorInfo(eccmemtype, eccIntrSrc, pEccErrorInfo);
          if(errInfoStatus != SDL_PASS)
          {
              retVal = errInfoStatus;
              FltM_Soc_Det_ReportError(FLTM_ECC_CALLBACKFUNC_API_ID, FLTM_ERR_ECC_ERR_INFO_FAIL);
          }
          else
          {
            *pEccErrorInfoValid = TRUE;

            /* clear the interupt*/
            if (pEccErrorInfo->injectBitErrCnt != 0u)
            {
                clearIntrStatus = SDL_ECC_clearNIntrPending(eccmemtype, pEccErrorInfo->memSubType, eccIntrSrc, SDL_ECC_AGGR_ERROR_SUBTYPE_INJECT, pEccErrorInfo->injectBitErrCnt);
            }
            else
            {
                clearIntrStatus = SDL_ECC_clearNIntrPending(eccmemtype, pEccErrorInfo->memSubType, eccIntrSrc, SDL_ECC_AGGR_ERROR_SUBTYPE_NORMAL, pEccErrorInfo->bitErrCnt);
            }
            if(clearIntrStatus != SDL_PASS)
            {
                retVal = clearIntrStatus;
                FltM_Soc_Det_ReportError(FLTM_ECC_CALLBACKFUNC_API_ID, FLTM_ERR_ECC_CLEAR_INTR_FAIL);
            }
            else
            {
                /* Acknowledge the interupt*/
                ackIntrStatus = SDL_ECC_ackIntr(eccmemtype, eccIntrSrc);
                if(ackIntrStatus != SDL_PASS)
                {
                    retVal = ackIntrStatus;
                    FltM_Soc_Det_ReportError(FLTM_ECC_CALLBACKFUNC_API_ID, FLTM_ERR_ECC_ACK_INTR_FAIL);
                }
            }
          }
        }
    }
    return(retVal);
}

/*============================================================================
**
** Function Name    :   FltM_runECC_InjectTest
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to trigger DED/SED
**
** Invocation       :   Application
**
** Inputs           :   addr - Address where the error needs to be injected
**                  :   aggregator - aggregator information
**                  :   ramid - RAM ID
**                  :   errortype - Type of Error
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
int32_t FltM_runECC_InjectTest(uint32_t addr,uint8_t aggregator, uint8_t ramid,SDL_ECC_InjectErrorType errortype)
{
    SDL_ErrType_t result;
    int32_t retVal = SDL_PASS;
    volatile uint32 ECC_InjectFaultLocationValue;
    if (FltM_ECC_IsInjectParamValid(aggregator, ramid, errortype) != TRUE)
    {
      retVal = SDL_EFAIL;
      FltM_Soc_Det_ReportError(FLTM_ECC_INJECTTEST_API_ID, FLTM_ERR_ECC_INVALID_PARAM);
    }
    else
    {
      SDL_ECC_InjectErrorConfig_t injectErrorConfig;
      MemLib_MemSet(&injectErrorConfig, 0, sizeof(injectErrorConfig));

      /* Note the address is relative to start of ram */
      injectErrorConfig.pErrMem = (uint32_t *)(addr);

      injectErrorConfig.flipBitMask = FLTM_ECC_INJECT_FLIP_BITMASK;

      result = SDL_ECC_injectError(aggregator, ramid,
                                  errortype,
                                  &injectErrorConfig);

      if (result != SDL_PASS )
      {
          retVal = SDL_EFAIL;
          FltM_Soc_Det_ReportError(FLTM_ECC_INJECTTEST_API_ID, FLTM_ERR_ECC_INJECT_FAIL);
      }
      else
      {
          ECC_InjectFaultLocationValue = *((volatile const uint32 *)injectErrorConfig.pErrMem);
          (void)ECC_InjectFaultLocationValue;
      }
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   FltM_ECC_IsInjectParamValid
**
** Visibility       :   Private
**
** Description      :    Validates the parameters supplied to
**                       FltM_runECC_InjectTest before any memory access is
**                       performed.
**
** Invocation       :   Internal
**
** Inputs           :   addr - Address where the error needs to be injected
**                  :   aggregator - aggregator information
**                  :   ramid - RAM ID
**                  :   errortype - Type of Error
**
** Outputs          :   None
**
** Return           :   TRUE if the parameters reference a currently
**                      configured aggregator/RAM and addr is non-NULL,
**                      FALSE otherwise.
**
** Critical Section :   No
**
**==========================================================================*/
static boolean FltM_ECC_IsInjectParamValid(uint8_t aggregator, uint8_t ramid, \
                                      SDL_ECC_InjectErrorType errortype)
{
    boolean isValid = FALSE;
    boolean isErrorTypeValid;

    switch (errortype)
    {
        case SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE:
        case SDL_INJECT_ECC_ERROR_FORCING_2BIT_ONCE:
        case SDL_INJECT_ECC_ERROR_FORCING_1BIT_N_ROW_ONCE:
        case SDL_INJECT_ECC_ERROR_FORCING_2BIT_N_ROW_ONCE:
        case SDL_INJECT_ECC_ERROR_FORCING_1BIT_REPEAT:
        case SDL_INJECT_ECC_ERROR_FORCING_2BIT_REPEAT:
        case SDL_INJECT_ECC_ERROR_FORCING_1BIT_N_ROW_REPEAT:
        case SDL_INJECT_ECC_ERROR_FORCING_2BIT_N_ROW_REPEAT:
            isErrorTypeValid = TRUE;
            break;
        case SDL_INJECT_ECC_NO_ERROR:
        default:
            isErrorTypeValid = FALSE;
            break;
    }

    if (isErrorTypeValid == TRUE)
    {
        for (uint32_t i = 0u; i < NUM_ECC_AGGR_CONFIGS; i++)
        {
            const ECC_AggregatorConfigType *cfg = globalECCConfigs[i];

            if ((cfg->aggregatorInstance == aggregator) &&
                (ramid < cfg->numRams))
            {
                isValid = TRUE;
                break;
            }
        }
    }

    return (isValid);
}

#endif /* #if(FLTM_ECC_ENABLE == STD_ON) */

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
