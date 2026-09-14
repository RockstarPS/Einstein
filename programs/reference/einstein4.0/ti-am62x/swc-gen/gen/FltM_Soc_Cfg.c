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
 * @file        FltM_Cfg.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_CFG_C_
#define  FLTM_SOC_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "FltM_Soc_Cfg.h"
#include "FltM.h"
#include "Rte_Type.h"
#include "Rte_RstM_Type.h"
#include "Rte_CFltM_Type.h" // RTE types for integration
#include "Det.h"

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



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
void FltM_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc);
#if (FLTM_ECC_ENABLE == STD_ON)
static void FltM_ECC_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, const SDL_ECC_ErrorInfo_t *pEccErrorInfo);
#endif
#if (FLTM_DCC_ENABLE == STD_ON)
static void FltM_DCC_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, SDL_DCC_Inst dccInst);
#endif
#if (FLTM_POK_ENABLE == STD_ON)
static void FltM_POK_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, SDL_POK_Inst pokInst);
#endif

const FltM_ErrConfigType FltM_ErrConfig[FLTM_ESM_INSTANCE_MAX] =
{
  {
    SDL_ESM_INST_WKUP_ESM0,
    {
      .esmErrorConfig = {1u, 8u}, /* Self test error config */
      .enableBitmap = 
        {0x300C0037u, 0x5dc0003fu, 0x0047f3e7u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
      .priorityBitmap = 
        {0x300C0037u, 0x5dc0003fu, 0x0047f3e7u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
      .errorpinBitmap = 
        {0x300C0037u, 0x5dc0003fu, 0x0047f3e7u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
    },
    FltM_Soc_WkupCallBackFunc,
  },
  {
    SDL_ESM_INST_MAIN_ESM0,
    {
      .esmErrorConfig = {1u, 8u}, /* Self test error config */
      .enableBitmap = 
        {0x00000000u, 0x00000000u, 0x002082ffu, 0x003f0000u,
        0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
      .priorityBitmap = 
        {0x00000000u, 0x00000000u, 0x002082ffu, 0x003f0000u,
        0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
      .errorpinBitmap = 
        {0x00000000u, 0x00000000u, 0x002082ffu, 0x003f0000u,
        0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
        },
    },
    FltM_Soc_MainCallBackFunc
  }
};

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
void FltM_Soc_WkupCallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                           uint32_t grpChannel, uint32_t index, uint32_t intSrc, void *arg)
{
  (void)arg;
  uint16 flIndex = 0;
  FltM_ErrSourceType flErrSrc = FLTM_ERR_UNKNOWN; //FLTM_ERR_UNKNOWN;
#if (FLTM_ECC_ENABLE == STD_ON)
  SDL_ECC_ErrorInfo_t eccErrorInfo = {0};
  boolean eccErrorInfoValid = FALSE;
#endif
#if (FLTM_DCC_ENABLE == STD_ON)
  SDL_DCC_Inst dccInst = SDL_DCC_INVALID_INSTANCE;
#endif
#if (FLTM_POK_ENABLE == STD_ON)
  SDL_POK_Inst pokInst = FLTM_POK_INVALID_INSTANCE;
#endif

  if (esmInst == SDL_ESM_INST_WKUP_ESM0)
  {
    for (flIndex = 0; flIndex < FLTM_WKUP_ESM_INTERRUPT_MAX; flIndex++)
    {
      if (flIndex == intSrc)
      {
        flErrSrc = FltM_InterruptSourceMap_Table_WKUP[flIndex].FltM_ErrSource;
        break;  // Reduce path complexity (133723)
      }
    }
  }
#if (FLTM_ECC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_ECC_1BIT)
  {
    // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc,
                                &eccErrorInfo, &eccErrorInfoValid);
    
	// For 1 bit errors for MSRAM, report fault as FATAL due to errata in AM62Px
    if((intSrc == FLTM_MSRAM_256K0_1BIT) || (intSrc == FLTM_MSRAM_256K1_1BIT))
	{
	   FltM_ECC_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_ECC_ERROR, intSrc,
                               (eccErrorInfoValid == TRUE) ? &eccErrorInfo : NULL_PTR);
	}
	else
    {
      FltM_ECC_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_ECC_1BIT_ERROR, intSrc,
                           (eccErrorInfoValid == TRUE) ? &eccErrorInfo : NULL_PTR);
    }
  }
  else if(flErrSrc == FLTM_ERR_ECC_2BIT)
  {
	 // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc,
                                &eccErrorInfo, &eccErrorInfoValid);
	
	FltM_ECC_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_ECC_2BIT_ERROR, intSrc,
                            (eccErrorInfoValid == TRUE) ? &eccErrorInfo : NULL_PTR);
  }
  else
  {
    /* MISRA 15.7: else clause added */
  }
#endif /* #if(FLTM_ECC_ENABLE == STD_ON) */

#if (FLTM_POK_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_POK)
  {
    // Handle POK error by clearning and getting the POK error source
    (void)FltM_POK_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc, &pokInst);

    FltM_POK_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_POK_ERROR, intSrc, pokInst);
  }
#endif /* #if(FLTM_POK_ENABLE == STD_ON) */

#if (FLTM_DCC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_DCC)
  {
    // Handle DCC error
    (void)FltM_Dcc_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc, &dccInst);

    FltM_DCC_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_DCC_ERROR, intSrc, dccInst);
  }
#endif
#if (FLTM_OCOCLKDET_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_PLLFRACF2)
  {
    FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_OCOCLKDET_ERROR, intSrc);
  }
#endif

  if((flErrSrc == FLTM_ERR_RTI) && (intSrc == FLTM_DM_RTI_INTERRUPT))
  {
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_DM_RTI_ERROR, intSrc);
  }
}

void FltM_Soc_MainCallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                           uint32_t grpChannel, uint32_t index, uint32_t intSrc, void *arg)
{
  (void)arg;
  uint32_t localIntSrc = intSrc;
  uint16 flIndex = 0;
  FltM_ErrSourceType flErrSrc = FLTM_ERR_UNKNOWN; //FLTM_ERR_UNKNOWN;
  SDL_ESM_IntType esmIntrPrivType;

  esmGroupIntrStatus_t localEsmGroupIntrStatus;
  uint32 esmInstBaseAddr;
  uint32 intSrcPls, intSrcLvl;
#if (FLTM_ECC_ENABLE == STD_ON)
  SDL_ECC_ErrorInfo_t eccErrorInfo = {0};
  boolean eccErrorInfoValid = FALSE;
#endif
#if (FLTM_DCC_ENABLE == STD_ON)
  SDL_DCC_Inst dccInst = SDL_DCC_INVALID_INSTANCE;
#endif
#if (FLTM_POK_ENABLE == STD_ON)
  SDL_POK_Inst pokInst = FLTM_POK_INVALID_INSTANCE;
#endif

  if (esmInst == SDL_ESM_INST_MAIN_ESM0)
  {
    if ((grpChannel == FLTM_MAIN_ESM_INT_GRP_IN_WKUP_MAP) && ((index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_0) || (index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_1) || (index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_2)))
    {
      /*Group Channel and index will be from Wakeup ESM interrupt Map. Since the Main ESM is reported to Wkup ESM, we need to check the interrupt source
      of the MAIN ESM */
      SDL_ESM_getBaseAddr(esmInst, &esmInstBaseAddr);

      if (esmIntrType == ESM_INTR_PRIORITY_LEVEL_HIGH)
      {
        esmIntrPrivType = SDL_ESM_INT_TYPE_HI;
      }
      else
      {
        esmIntrPrivType = SDL_ESM_INT_TYPE_LO;
      }

      // get the interrupt source id
      (void)SDL_ESM_getGroupIntrStatus((uint32_t)esmInstBaseAddr,
                                       (uint32_t)esmIntrPrivType,
                                       &localEsmGroupIntrStatus);
      intSrcPls = (uint32)localEsmGroupIntrStatus.highestPendPlsIntNum;
      intSrcLvl = (uint32)localEsmGroupIntrStatus.highestPendLvlIntNum;

      if ((intSrcPls != FLTM_NOT_VALID_EVENT) && (intSrcPls < (FLTM_BITS_PER_WORD * FLTM_ESM_MAX_EVENT_MAP_NUM_WORDS)))
      {
        // Process valid pulse interrupt source
        localIntSrc = intSrcPls;
      }
      else if ((intSrcLvl != FLTM_NOT_VALID_EVENT) && (intSrcLvl < (FLTM_BITS_PER_WORD * FLTM_ESM_MAX_EVENT_MAP_NUM_WORDS)))
      {
        // Process valid level interrupt source
        localIntSrc = intSrcLvl;
      }
      else
      {
        /*Do Nothing*/
      }
    }

    for (flIndex = 0; flIndex < FLTM_ESM_INTERRUPT_MAX; flIndex++)
    {
      if (flIndex == localIntSrc)
      {
        flErrSrc = FltM_InterruptSourceMap_Table_MAIN[flIndex].FltM_ErrSource;
        break;
      }
    }
  }

#if (FLTM_ECC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_ECC_1BIT)
  {
    // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, localIntSrc,
                                &eccErrorInfo, &eccErrorInfoValid);
    
    FltM_ECC_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_ECC_1BIT_ERROR, localIntSrc,
                         (eccErrorInfoValid == TRUE) ? &eccErrorInfo : NULL_PTR);
  }
  else if(flErrSrc == FLTM_ERR_ECC_2BIT)
  {
	 // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, localIntSrc,
                                &eccErrorInfo, &eccErrorInfoValid);
	
	FltM_ECC_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_ECC_2BIT_ERROR, localIntSrc,
                            (eccErrorInfoValid == TRUE) ? &eccErrorInfo : NULL_PTR);
  }
  else
  {
    /* MISRA 15.7 */
  }
#endif /* #if(FLTM_ECC_ENABLE == STD_ON) */

#if (FLTM_POK_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_POK)
  {
    // Handle POK error by clearning and getting the POK error source
    (void)FltM_POK_CallBackFunc(esmInst, esmIntrType, grpChannel, index, localIntSrc, &pokInst);

    FltM_POK_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_POK_ERROR, localIntSrc, pokInst);
  }
#endif /* #if(FLTM_POK_ENABLE == STD_ON) */

#if (FLTM_DCC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_DCC)
  {
    // Handle DCC error
    (void)FltM_Dcc_CallBackFunc(esmInst, esmIntrType, grpChannel, index, localIntSrc, &dccInst);

    FltM_DCC_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_DCC_ERROR, localIntSrc, dccInst);
  }
#endif
#if (FLTM_OCOCLKDET_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_GLUELOGIC)
  {
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_OCOCLKDET_ERROR, localIntSrc);
  }
#endif

  if((flErrSrc == FLTM_ERR_RTI) && (localIntSrc == FLTM_HSM_RTI_INTERRUPT))
  {
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_HSM_RTI_ERROR, localIntSrc);
  }
}

void FltM_FireWallExceptionCallBack(void)
{
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_PPU_ERROR, 0xAAu);
}

void FltM_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc)
{
  FltM_FaultIdType FltM_FaultId = 0U;
  uint8 logData[5] = {0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};
  volatile uint32_t Hsm_Read_WdgFail_Reason;

  logData[0] = DomainId;
  logData[1] = (uint8)(IntSrc);

  if(ErrorId == FLTM_ECC_ERROR)
  {
    FltM_FaultId = ECC_FAULT;
  }
  else if(ErrorId == FLTM_ECC_1BIT_ERROR)
  {
    FltM_FaultId = ECC_1BIT_ERROR;
  }
  else if(ErrorId == FLTM_ECC_2BIT_ERROR)
  {
    FltM_FaultId = ECC_2BIT_ERROR;
  }
  else if(ErrorId == FLTM_POK_ERROR)
  {
    FltM_FaultId = POK_FAULT;
  }
  else if(ErrorId == FLTM_DCC_ERROR)
  {
    FltM_FaultId = DCC_FAIL;
  }
  else if(ErrorId == FLTM_OCOCLKDET_ERROR)
  {
    FltM_FaultId = OCOC_FAIL;
  }
  else if(ErrorId == FLTM_PPU_ERROR)
  {
    FltM_FaultId = TIFS_SAFETY_CHECK_FWL_FAIL;
  }
  #if (FLTM_FLSINTEGRITY_ENABLE == STD_ON)
  else if(ErrorId == FLTM_FLSINTEGRITY_ERROR)
  {
    FltM_FaultId = FALSH_INTEGRITY_FAIL;
  }
  #endif
  else if(ErrorId == FLTM_HSM_RTI_ERROR)
  {
    FltM_FaultId = HSM_WDG_FAIL;
    Hsm_Read_WdgFail_Reason = *(volatile uint32_t*)0x43c20004;
    logData[1] = FLTM_HSM_RTI_INTERRUPT;
    logData[2] = (uint8)((Hsm_Read_WdgFail_Reason >> 8U) & 0xFFU);
    logData[3] = (uint8)(Hsm_Read_WdgFail_Reason & 0xFFU);
  }
  else if (ErrorId == FLTM_DM_RTI_ERROR)
  {
    FltM_FaultId = DM_WDG_FAIL;
  }
  else if (ErrorId == FLTM_PERIODIC_READBACK_ERROR)
  {
    FltM_FaultId = PERIODIC_READBACK_FAIL;
  }
  else
  {
    /*Do Nothing*/
  }
  (void)FltM_ReportFault(FltM_FaultId, FLTM_ACTIVE, logData, 5u);
}
#if (FLTM_ECC_ENABLE == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_ECC_ReportError
**
** Visibility       :   Private
**
** Description      :   The function reports ECC related faults to the Fault
**                      Manager. It collects ECC error information, maps the
**                      received error ID to the corresponding Fault Manager
**                      fault ID, and logs the fault through
**                      FltM_ReportFault().
**
** Invocation       :   ECC error callback / ECC error handler
**
** Inputs           :   DomainId      - Fault reporting domain
**                      ErrorId       - ECC error identifier
**                      IntSrc        - ESM interrupt source
**                      pEccErrorInfo - Pointer to ECC error information
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_ECC_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, const SDL_ECC_ErrorInfo_t *pEccErrorInfo)
{
    FltM_FaultIdType FltM_FaultId = 0U;

    uint8 logData[5U] = { 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};

    logData[0] = DomainId;                            /*   Fault reporting domain */
    logData[1] = (uint8)IntSrc;                       /*   ESM interrupt source   */

    if (pEccErrorInfo != NULL_PTR)
    {
        logData[2] = (uint8)pEccErrorInfo->eccMemType; /*    ECC Aggregator Memory Type      */
        logData[3] = (uint8)pEccErrorInfo->memSubType; /*    ECC RAM/Memory Subtype (RAM ID) */
        logData[4] = (uint8)pEccErrorInfo->intrSrc;    /*    ECC Error Type (SEC/DED)        */
    }

    if(ErrorId == FLTM_ECC_ERROR)
    {
        FltM_FaultId = ECC_FAULT;
    }
    else if(ErrorId == FLTM_ECC_1BIT_ERROR)
    {
        FltM_FaultId = ECC_1BIT_ERROR;
    }
    else if(ErrorId == FLTM_ECC_2BIT_ERROR)
    {
        FltM_FaultId = ECC_2BIT_ERROR;
    }
    else
    {
        /* Do Nothing */
    }

    (void)FltM_ReportFault(FltM_FaultId, FLTM_ACTIVE, logData, 5U);
}
#endif /* #if (FLTM_ECC_ENABLE == STD_ON) */

#if (FLTM_DCC_ENABLE == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_DCC_ReportError
**
** Visibility       :   Private
**
** Description      :   The function reports DCC related faults to the Fault
**                      Manager. It captures the DCC instance information,
**                      maps the received error ID to the corresponding Fault
**                      Manager fault ID, and logs the fault through
**                      FltM_ReportFault().
**
** Invocation       :   DCC error callback / DCC error handler
**
** Inputs           :   DomainId - Fault reporting domain
**                      ErrorId  - DCC error identifier
**                      IntSrc   - ESM interrupt source
**                      dccInst  - DCC instance reporting the fault
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static void FltM_DCC_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, SDL_DCC_Inst dccInst)
{
    FltM_FaultIdType FltM_FaultId = 0U;

    uint8 logData[5U] = { 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};

    logData[0] = DomainId;                            /*   Fault reporting domain */
    logData[1] = (uint8)IntSrc;                       /*   ESM interrupt source   */
    if (dccInst != SDL_DCC_INVALID_INSTANCE)
    {
        logData[2] = (uint8)dccInst;                   /*   Fault DCC Instance     */
    }

    if(ErrorId == FLTM_DCC_ERROR)
    {
        FltM_FaultId = DCC_FAIL;
    }
    (void)FltM_ReportFault(FltM_FaultId, FLTM_ACTIVE, logData, 5U);
}
#endif /* #if (FLTM_DCC_ENABLE == STD_ON) */

#if (FLTM_POK_ENABLE == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_POK_ReportError
**
** Visibility       :   Private
**
** Description      :   The function reports POK related faults to the Fault
**                      Manager. It captures the POK instance information,
**                      maps the received error ID to the corresponding Fault
**                      Manager fault ID, and logs the fault through
**                      FltM_ReportFault().
**
** Invocation       :   POK error callback / POK error handler
**
** Inputs           :   DomainId - Fault reporting domain
**                      ErrorId  - POK error identifier
**                      IntSrc   - ESM interrupt source
**                      pokInst  - POK instance reporting the fault
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_POK_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc, SDL_POK_Inst pokInst)
{
  FltM_FaultIdType FltM_FaultId = 0U;

  uint8 logData[5U] = { 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};

  logData[0] = DomainId;                            /*   Fault reporting domain */
  logData[1] = (uint8)IntSrc;                       /*   ESM interrupt source   */
  if (pokInst != FLTM_POK_INVALID_INSTANCE)
  {
    logData[2] = (uint8)pokInst;                     /*   Fault POK Instance     */
  }

  if(ErrorId == FLTM_POK_ERROR)
  {
      FltM_FaultId = POK_FAULT;
  }
  (void)FltM_ReportFault(FltM_FaultId, FLTM_ACTIVE, logData, 5U);
}
#endif /* #if (FLTM_POK_ENABLE == STD_ON) */

void FltM_Soc_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
  (void)Det_ReportError(6700U, 0x01U, ApiId, ErrorId);
}

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
Date              :  
By                :  
Traceability      : 
Change Description: 
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/
