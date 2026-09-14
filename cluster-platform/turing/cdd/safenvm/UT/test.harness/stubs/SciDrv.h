/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  SciDrv.h                                                *
*  Module Short Name :  SciDrv                                                *
*  Description       :  This file contains implementations of the SCI Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                             *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/


#ifndef SCIDRV_H
#define SCIDRV_H


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "SciDrv_Cfg.h"
#include "SciDrv_Types.h"


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
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   SciDrv_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   SSciDrvCfg *pConfig - Pointer to a configuration type.
**
** Outputs          :   E_OK: If success.
**                      E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_Init( const SSciDrvCfg *pConfig );

/*============================================================================
**
** Function Name    :   SciDrv_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function is called to initialise the Global
**                      and Static variables of this module to initial/ default values.
**
** Invocation       :   Application
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :
**
**==========================================================================*/
extern void SciDrv_DeInit( void );

/*============================================================================
**
** Function Name    :   SciDrv_SetupEB
**
** Visibility       :   Public
**
** Description      :   This function setsups the SciDrv External Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_SetupEB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length );

/*DMA mode is not supported as for now and WriteIB and ReadIB are supported only in DMA mode*/
#ifdef DMA_MODE_ENABLED
/*============================================================================
**
** Function Name    :   SciDrv_WriteIB
**
** Visibility       :   Public
**
** Description      :   This function writes to the SciDrv Internal Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/


extern Std_ReturnType SciDrv_WriteIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length );

/*============================================================================
**
** Function Name    :   SciDrv_ReadIB
**
** Visibility       :   Public
**
** Description      :   This function reads the SciDrv Internal Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_ReadIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint16 Length );
#endif

/*============================================================================
**
** Function Name    :   SciDrv_EnableChn
**
** Visibility       :   Public
**
** Description      :   This function Enables the Channel with SciDrv Configurations
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: The Hw Channel that needs to be enabled
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_EnableChn( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_AsyncTransmit
**
** Visibility       :   Public
**
** Description      :   This function triggers the asynchronous transmission.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If tx/ accepted.
**                     E_NOT_OK: If tx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_ASyncTransmit( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_ASyncReceive
**
** Visibility       :   Public
**
** Description      :   This function triggers the asynchronous Receiption.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_ASyncReceive( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_SetAsyncMode
**
** Visibility       :   Public
**
** Description      :   This function set the Asyncronous mode.
**                      The Asyncronpus modes are Interrupt and DMA.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The HW channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_SetAsyncMode( TSciDrvChn SciDrvHwChn, ESciDrvAsyncMode SciAsyncMode );

/*============================================================================
**
** Function Name    :   SciDrv_SyncTransmit
**
** Visibility       :   Public
**
** Description      :   This function triggers the synchronous transmission.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If tx/ accepted.
**                     E_NOT_OK: If tx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_SyncTransmit( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_SyncReceive
**
** Visibility       :   Public
**
** Description      :   This function triggers the synchronous Receiption.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_SyncReceive( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_SetSyncMode
**
** Visibility       :   Public
**
** Description      :   This function set the syncronous mode.
**                      The Asyncronpus modes is polled.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_SetSyncMode( TSciDrvChn SciDrvHwChn, ESciDrvSyncMode SciSyncMode );

/*============================================================================
**
** Function Name    :   SciDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :   This function set gives the Global Sci Driver.
**
** Invocation       :   Application.
**
** Inputs           :   
**
** Outputs          :  eSciDrvStatus_Uninit - The SCI Driver is not initialized or not usable
**                     eSciDrvStatus_Uninit - The SCI Driver is ready for use
**                     eSciDrvStatus_Last - Last Entry
**                    
**
** Critical Section :
**
**==========================================================================*/
extern ESciDrvStatus SciDrv_GetStatus( void );

/*============================================================================
**
** Function Name    :   SciDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :    This function gives the Channel status of
                        enabled Sci Driver Channel. 
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint32 *pLength: Received Bytes 
**
** Outputs          :  eSciDrvChnResult_Ok: The last transfer on the SCI Channel has been finished successfully
**                     eSciDrvChnResult_Busy: The SCI Driver is performing a transfer on the SCI Channel
**                     eSciDrvChnResult_Failed: The last transfer on the SCI Channel has failed
**                     eSciDrvChnResult_Cancelled: The last transfer on the SCI Channel has been cancelled by user  
**                     eSciDrvChnResult_Last: Last Entry
**
** Critical Section :
**
**==========================================================================*/
extern ESciDrvChnResult SciDrv_GetChnResult( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint32 *pLength );

/*============================================================================
**
** Function Name    :   SciDrv_DisableChn
**
** Visibility       :   Public
**
** Description      :   This function disables the Scidrv Channel.
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**
** Outputs          :   E_OK: Channel disabled.
**                      E_NOT_OK: Channel is not disabled.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_DisableChn( TSciDrvChn SciDrvHwChn );

/*============================================================================
**
** Function Name    :   SciDrv_Cancel
**
** Visibility       :   Public
**
** Description      :   This function cancels transmission or receiption which not triggered yet.
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**                      ESciDrvDirection Direction: Direction of the channel.
**
** Outputs          :   E_OK: Channel cancelled.
**                      E_NOT_OK: Channel is not cancelled.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType SciDrv_Cancel( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction );

/*============================================================================
**
** Function Name    :   SciDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending transmissions
**                      according to the priority.
**
** Invocation       :   Os Scheduling.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void SciDrv_MainFunction(void);

/*============================================================================
**
** Function Name    :   SciDrv_TxRxISRHandle
**
** Visibility       :   Public
**
** Description      :   This ISR is invoked whenever a transmission complete
**                      or reception is in progress.
**
** Invocation       :   Interrupt.
**
** Inputs           :   const TSciDrvChn SciDrvHwChn: Hw Channel ID
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void SciDrv_TxRxISRHandle( const TSciDrvChn SciDrvHwChn );

#endif /* SCIDRV_H_ */

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
/**-------------------------------------------------------------------------*/
/*Date              : 10-02-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*/
/*Date              : 26-02-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                       */
/*--------------------------------------------------------------------------*/