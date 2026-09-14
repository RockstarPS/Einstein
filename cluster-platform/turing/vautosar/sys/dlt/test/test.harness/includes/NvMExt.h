/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  NvMExt.h
Module Short Name:  NvMExt
VOBName          :
Author           :
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_EXT_H
#define NVM_EXT_H

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
typedef enum
{
	NVMEXT_IDLE = 0,
	NVMEXT_PENDING,
	NVMEXT_SHUTDOWN_COMPLETED
}NvMExt_ShutdownType;

#define NVMEXT_NVM_FIRST_BLOCK              0x2

#define NVMEXT_NUM_OF_NVM_BLOCKS            NVM_NUM_OF_BLOCKS

#define NVMEXT_PET_WDG_TIMER_US                 100*(1000)  /*100ms*/
#define NVMEXT_WDG_RELOAD_TIME_MS               500*(1000)  /*500ms*/
#define NVMEXT_NVM_SPEEDUP_TIMEOUT_US            3*(1000) /*3ms*/

#  ifndef ECUMEXT_CANRXWAKEUP
#   define ECUMEXT_CANRXWAKEUP (1)
#  endif
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   NvMExt_Init
**
** Visibility       :   Public
**
** Description      :   Service for NvMExt initialization
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_Init(void);

/*============================================================================
**
** Function Name    :   NvMExt_ReadAll_Frm_Ecum
**
** Visibility       :   Public
**
** Description      :   To Request NvM Read All. This functionality abstracts the dependedncy
**                      to other modules to perform Speedup functionality
**
** Invocation       :   Function is called in application context after checking
**                      NvM will be ready to process read all requests
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

void NvMExt_ReadAll_Frm_Ecum(void);

/*============================================================================
**
** Function Name    :   NvMExt_ReadAll
**
** Visibility       :   Public
**
** Description      :   To Request NvM Read All. This functionality abstracts the dependedncy
**                      to other modules to perform Speedup functionality
**
** Invocation       :   Function is called in application context after checking
**                      NvM will be ready to process read all requests
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_ReadAll(void);

/*============================================================================
**
** Function Name    :   NvMExt_MainFunction
**
** Visibility       :   Public
**
** Description      :   MainFunction for this module
**
** Invocation       :   RTE containers
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_MainFunction(void);

/*============================================================================
**
** Function Name    :   NvMExt_RequestSpeedup
**
** Visibility       :   Public
**
** Description      :   To request NvMExt to initiate Speedup
**
** Invocation       :   BSW
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_RequestSpeedup(void);

/*============================================================================
**
** Function Name    :   NvMExt_ReleaseSpeedup
**
** Visibility       :   Public
**
** Description      :   To request NvMExt to release Speedup
**
** Invocation       :   BSW
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_ReleaseSpeedup(void);

/*============================================================================
**
** Function Name    :   NvMExt_RequestSleep
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_RequestSleep(void);

/*============================================================================
**
** Function Name    :   NvMExt_CancelSleep
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_CancelSleep(void);

/*============================================================================
**
** Function Name    :   NvMExt_ReadytoSleep
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   Sleep Ready state
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_ReadytoSleep(void);

/*============================================================================
**
** Function Name    :   NvMExt_IsPhase1ReadCompleted
**
** Visibility       :   Public
**
** Description      :   Function to check if the Phase1 reading is completed.
**
** Invocation       :   Called  from Application.
**
** Inputs           :   none
**
** Outputs          :   FALSE - Phase1 reading is not done or ongoing
**                      TRUE  - Phase1 reading is completed
**
** Critical Section :
**
**==========================================================================*/
extern boolean NvMExt_IsPhase1ReadCompleted( void );

Std_ReturnType NvMExt_Fls_Write (uint32 TargetAddress, uint8* SourceAddressPtr, uint32 Length);

Std_ReturnType NvMExt_Fls_Erase (uint32 TargetAddress, uint32 Length);

extern void NvMExt_StartRestoreBURAM(void);

Std_ReturnType NvMExt_GetBURAMReadStatus(void);

extern void NvMExt_CancelRestoreBURAM(void);

Std_ReturnType NvMExt_GetBlockRequestStatus(uint8* JobId, uint8* MultiIndex);
Std_ReturnType NvMExt_MultipleJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);
#endif    /* */
/* end of file */
