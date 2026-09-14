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
 * @file        FltM_Cfg.h
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_CFG_H_
#define  FLTM_SOC_CFG_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc.h"
#include "FltM_Soc_Types.h"
#include "Det.h"


#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Define the periodicity counter for Each SM Readback features */
#define FLTM_DCC_READBACK_PERIODICITY                   80u  /* 80*10ms = 800ms*/
#define FLTM_ECC_READBACK_PERIODICITY                   50u  /* 50*10ms = 500ms*/
#define FLTM_PPU_READBACK_PERIODICITY                   80u  /* 50*10ms = 500ms*/

#define FLTM_HSM_RTI_INTERRUPT                          85u
#define FLTM_DM_RTI_INTERRUPT                           86u

#define FLTM_MSRAM_256K0_1BIT                           32u
#define FLTM_MSRAM_256K1_1BIT                           34u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct
{
    /* Module Instance Type */
    SDL_ESM_Inst Instance;
    /* Structure defines ESM Init configuration - taken from TI SDL */
    SDL_ESM_config SDL_ESMConfig;
    /* Callback function to handle the Error*/
    SDL_ESM_applicationCallback SDL_ESM_applicationCallbackFun;
}FltM_ErrConfigType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
extern const FltM_ErrConfigType FltM_ErrConfig[FLTM_ESM_INSTANCE_MAX];
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

extern void FltM_Soc_WkupCallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                                    uint32_t grpChannel, uint32_t index, uint32_t intSrc,void *arg);

extern void FltM_Soc_MainCallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                                    uint32_t grpChannel, uint32_t index, uint32_t intSrc,void *arg);
void FltM_FireWallExceptionCallBack(void);

extern void FltM_ReportError(uint8 DomainId, uint8 ErrorId, uint32 IntSrc);
extern void FltM_Soc_Det_ReportError(uint8 ApiId, uint8 ErrorId);

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

