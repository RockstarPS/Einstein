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
*  File Name         :  SciDrv.c                                                *
*  Module Short Name :  SciDrv                                               *
*  Description       :  This file contains implementations of the SCI Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/



/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "SciDrv_Types.h"
#include "SciDrv.h"
#include <string.h>

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
*                                Private Variables                         *
******************************************************************************/

const SSciDrvCfg SciDrvCfg;
const SSciDrvCfg* pSciDrvCfg = &SciDrvCfg;


/*****************************************************************************
*                            Private Functions                                  *
******************************************************************************/

/*****************************************************************************
*                      Public Function Implementation                         *
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
** Invocation       :
**
** Inputs           :   SSciDrvCfg *pConfig - Pointer to a configuration type.
**
** Outputs          :   E_OK: If success.
**                      E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_Init( const SSciDrvCfg *pConfig )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function is called to initialise the Global
**                      and Static variables of this module to initial/ default values.
**
** Invocation       :
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :
**
**==========================================================================*/
void SciDrv_DeInit( void )
{
    
}

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
Std_ReturnType SciDrv_SetupEB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8 *pBuffer, uint32 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_WriteIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_ReadIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint16 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}
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
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel that needs to be enabled
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_EnableChn( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
	return flRetVal;
}

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
Std_ReturnType SciDrv_ASyncTransmit( TSciDrvChn SciDrvHwChn )
{
	Std_ReturnType flRetVal = E_NOT_OK;
	return flRetVal;
}

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
Std_ReturnType SciDrv_ASyncReceive(TSciDrvChn SciDrvHwChn)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SetAsyncMode( TSciDrvChn SciDrvHwChn, ESciDrvAsyncMode SciAsyncMode )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_SyncTransmit( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_SyncReceive( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_SetSyncMode( TSciDrvChn SciDrvHwChn, ESciDrvSyncMode SciSyncMode )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :   This function gives the Global Sci Driver. 
**
** Invocation       :   Application.
**
** Inputs           :   
**
** Outputs          :  eSciDrvStatus_Uninit - The SCI Driver is not initialized or not usable
**                     eSciDrvStatus_Ready - The SCI Driver is ready for use
**                     eSciDrvStatus_Last - Last Entry
**                    
**
** Critical Section :
**
**==========================================================================*/
ESciDrvStatus SciDrv_GetStatus( void )
{
    return eSciDrvStatus_Ready;
}

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
ESciDrvChnResult SciDrv_GetChnResult( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint32 *pLength )
{
    ESciDrvChnResult flResult = eSciDrvChnResult_Failed;
    return flResult;
}

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

Std_ReturnType SciDrv_DisableChn( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

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
Std_ReturnType SciDrv_Cancel( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending receive
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
void SciDrv_MainFunction(void)
{
    
}
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
void SciDrv_TxRxISRHandle( const TSciDrvChn SciDrvHwChn )
{
    
}


/*****************************************************************************
*                           Private Functions                                *
******************************************************************************/

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
/*Date              : 15-02-2024                                            */
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