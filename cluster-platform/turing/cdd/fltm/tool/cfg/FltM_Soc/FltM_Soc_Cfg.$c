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
void FltM_ReportError(uint8 DomainId, uint8 ErrorId);


const FltM_ErrConfigType FltM_ErrConfig[FLTM_ESM_INSTANCE_MAX] =
{
    {
        SDL_ESM_INST_WKUP_ESM0,
        {
            .esmErrorConfig = { 1u, 8u }, /* Self test error config */
            .enableBitmap = 
            {
                0x300c0037u, 0x5dc0003fu, 0x0007f3e7u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
            },
            .priorityBitmap = 
            {
                0x300c0037u, 0x5dc0003fu, 0x0007f3e7u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
            },
            .errorpinBitmap = 
            {
                0x300c0037u, 0x5dc0003fu, 0x0007f3e7u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
            },
        },
        FltM_Soc_WkupCallBackFunc,
    },
    {
        SDL_ESM_INST_MAIN_ESM0,
        {
            .esmErrorConfig = { 1u, 8u }, /* Self test error config */
            .enableBitmap = 
            {
                0x00000000u, 0x00000000u, 0x000082feu, 0x003f0000u,
                0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
            },
            .priorityBitmap = 
            {
                0x00000000u, 0x00000000u, 0x000082feu, 0x003f0000u,
                0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
            },
            .errorpinBitmap = 
            {
                0x00000000u, 0x00000000u, 0x000082feu, 0x003f0000u,
                0x00000080u, 0x00000000u, 0x80000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u
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
  uint16 flIndex = 0;
  uint16 flErrSrc;
  uint8 flLevel;

  if (esmInst == SDL_ESM_INST_WKUP_ESM0)
  {
    for (flIndex = 0; flIndex < FLTM_WKUP_ESM_INTERRUPT_MAX; flIndex++)
    {
      if (flIndex == intSrc)
      {
        flErrSrc = FltM_InterruptSourceMap_Table_WKUP[flIndex].FltM_ErrSource;
        flLevel = FltM_InterruptSourceMap_Table_WKUP[flIndex].FlTM_Level;
      }
    }
  }
#if (FLTM_ECC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_ECC)
  {
    // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    if ((esmIntrType == SDL_ESM_INT_TYPE_HI) || (flLevel == FLTM_SOC_UNCORRECTABLE))
    {
      FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_ECC_ERROR);
    }
  }
#endif /* #if(FLTM_ECC_ENABLE == STD_ON) */

#if (FLTM_POK_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_POK)
  {
    // Handle POK error by clearning and getting the POK error source
    (void)FltM_POK_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_POK_ERROR);
  }
#endif /* #if(FLTM_POK_ENABLE == STD_ON) */

#if (FLTM_DCC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_DCC)
  {
    // Handle DCC error
    (void)FltM_Dcc_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_DCC_ERROR);
  }
#endif
#if (FLTM_OCOCLKDET_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_PLLFRACF2)
  {
    FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_OCOCLKDET_ERROR);
  }
#endif
}

void FltM_Soc_MainCallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                           uint32_t grpChannel, uint32_t index, uint32_t intSrc, void *arg)
{
  uint16 flIndex = 0;
  uint16 flErrSrc;
  uint8 flLevel;
  uint8 esmIntrPrivType;

  esmGroupIntrStatus_t localEsmGroupIntrStatus;
  uint32 esmInstBaseAddr;
  uint32 intSrcPls, intSrcLvl;

  if (esmInst == SDL_ESM_INST_MAIN_ESM0)
  {
    if (grpChannel == FLTM_MAIN_ESM_INT_GRP_IN_WKUP_MAP && ((index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_0) || (index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_1) || (index == FLTM_WKUP_ESM0_ESM_LVL_EVENT_IN_2)))
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
      intSrcPls = localEsmGroupIntrStatus.highestPendPlsIntNum;
      intSrcLvl = localEsmGroupIntrStatus.highestPendLvlIntNum;

      if ((intSrcPls != FLTM_NOT_VALID_EVENT) && (intSrcPls < (FLTM_BITS_PER_WORD * FLTM_ESM_MAX_EVENT_MAP_NUM_WORDS)))
      {
        // Process valid pulse interrupt source
        intSrc = intSrcPls;
      }
      else if ((intSrcLvl != FLTM_NOT_VALID_EVENT) && (intSrcLvl < (FLTM_BITS_PER_WORD * FLTM_ESM_MAX_EVENT_MAP_NUM_WORDS)))
      {
        // Process valid level interrupt source
        intSrc = intSrcLvl;
      }
    }

    for (flIndex = 0; flIndex < FLTM_ESM_INTERRUPT_MAX; flIndex++)
    {
      if (flIndex == intSrc)
      {
        flErrSrc = FltM_InterruptSourceMap_Table_MAIN[flIndex].FltM_ErrSource;
        flLevel = FltM_InterruptSourceMap_Table_MAIN[flIndex].FlTM_Level;
      }
    }
  }

#if (FLTM_ECC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_ECC)
  {
    // Handle ECC error by clearning and getting the ECC error source
    (void)FltM_ECC_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    if ((esmIntrType == SDL_ESM_INT_TYPE_HI) || (flLevel == FLTM_SOC_UNCORRECTABLE))
    {
      FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_ECC_ERROR);
    }
  }
#endif /* #if(FLTM_ECC_ENABLE == STD_ON) */

#if (FLTM_POK_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_POK)
  {
    // Handle POK error by clearning and getting the POK error source
    (void)FltM_POK_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_POK_ERROR);
  }
#endif /* #if(FLTM_POK_ENABLE == STD_ON) */

#if (FLTM_DCC_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_DCC)
  {
    // Handle DCC error
    (void)FltM_Dcc_CallBackFunc(esmInst, esmIntrType, grpChannel, index, intSrc);

    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_DCC_ERROR);
  }
#endif
#if (FLTM_OCOCLKDET_ENABLE == STD_ON)
  if (flErrSrc == FLTM_ERR_GLUELOGIC)
  {
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_OCOCLKDET_ERROR);
  }
#endif
}

void FltM_FireWallExceptionCallBack()
{
    FltM_ReportError(FLTM_ERR_CBK_MAIN_DOMIAN, FLTM_PPU_ERROR);
}

void FltM_ReportError(uint8 DomainId, uint8 ErrorId)
{
  FltM_FaultIdType FltM_FaultId = 0U;
  uint8 logData;

  logData = DomainId;
  if(ErrorId == FLTM_ECC_ERROR)
  {
    FltM_FaultId = ECC_FAULT;
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
  else
  {
  }
   FltM_ReportFault(FltM_FaultId, FLTM_ACTIVE, &logData, 1);
}

void FltM_Soc_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
  (void)Det_ReportError(6700U,0x01, ApiId, ErrorId);
  //while(1);
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