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
 * @file        FltM.h
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_PPU_H_
#define  FLTM_SOC_PPU_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Ppu_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_PPU_ENABLE == STD_ON)

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Control Register setting for Background and Foreground Regions */
#define FLTM_FIREWALL_BGND               0x30AU
#define FLTM_FIREWALL_FGND               0xAU
#define PPU_SystemP_TIMEOUT   			 ((uint32_t)-2)

/*============================================================================
**
** Function Name    :   FltM_Ppu_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise firewall
**                      protection.
**
** Invocation       :   FltM_Soc_Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType FltM_Ppu_Init(void);


/*============================================================================
**
** Function Name    :   FltM_PPU_ReadBack
**
** Visibility       :   Public
**
** Description      :   Periodic Readback for PPU.
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
extern Std_ReturnType FltM_PPU_ReadBack(void);


/*============================================================================
**
** Function Name    :   FltM_FwlExceptionHandler
**
** Visibility       :   Public
**
** Description      :   Handles the firewall exception handler procedure
**
** Invocation       :   Interrupt Service
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void FltM_FwlExceptionHandler(void);

/*============================================================================
**
** Function Name    :   FltM_FireWallExceptionCallBack
**
** Visibility       :   Public
**
** Description      :   Handles the firewall exception callback
**
** Invocation       :   Interrupt Service
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_FireWallExceptionCallBack(void);

#endif /*#if(FLTM_PPU_ENABLE == STD_ON)*/

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
Date              :02-Jun-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-8501
Change Description:PPU Implementation
-----------------------------------------------------------------------------*/
