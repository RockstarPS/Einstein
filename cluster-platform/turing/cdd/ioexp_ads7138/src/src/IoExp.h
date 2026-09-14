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
*  File Name         :  IoExp.h                                              *
*  Module Short Name :  IoExp_ads7138                                        *
*  VOBName           :                                                       *
*  Author            : gthanapp                                              *
*  Description       : External API interface for ExtIo Module               *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef IOEXP_H
#define IOEXP_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "IoExp_Types.h"
#include "IoExp_Cfg.h"
#include "Det.h"
#include "MemLib.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* HW CHANNEL ID */

#define IOEXP_PIN0                  0u
#define IOEXP_PIN1                  1u
#define IOEXP_PIN2                  2u
#define IOEXP_PIN3                  3u
#define IOEXP_PIN4                  4u
#define IOEXP_PIN5                  5u
#define IOEXP_PIN6                  6u
#define IOEXP_PIN7                  7u

#if (IOEXP_DEV_ERROR_DETECT == STD_ON)
/**
 *  \name IoExp Error Codes
 *
 *  @{
 */
#define IOEXP_MODULE_ID             100U
/** \brief IoExp Instance ID */
#define IOEXP_INSTANCE_ID            0U

#define IOEXP_E_UNINIT               0U
#define IOEXP_E_I2C_TRANSFER         1U
#define IOEXP_E_CHANNELID            2U

#define IOEXP_MAINFUNC_ID            0U
#define IOEXP_ENDNOTIFICATION_ID     1u
#define IOEXP_DIREAD_ID              2u
#define IOEXP_DOWRITE_ID             3u
#define IOEXP_AINREAD_ID             4u
#define IOEXP_CALLBACK_ID            5u
#define IOEXP_DEINIT_ID              6u
#define IOEXP_INIT_ID                7u
#define IOEXP_SETUPEB_ID             8u
#define IOEXP_ASYNCTRANSMIT_ID       9u
#define IOEXP_E_PINCONFIG            10u


#endif
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    DIGITAL_INPUT = 0,
    DIGITAL_OUTPUT,
    ANALOG_INPUT
}IoExp_PinType;


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/


/**************************************************************************
Function name   : IoExp_Init(uint8 ChannelId,uint16* AnalogDataBuffer)
Arguments       : None
Return type     : None
Description     : This function is used to Initialise the General config Registers
**************************************************************************/
extern void IoExp_Init(void);

/**************************************************************************
Function name   : IoExp_ReadChannel
Arguments       : ChannelId - ID of the channel 
Return type     : IoExp_LevelType
Description     : This function is used to Read the Pin Level of the channel
**************************************************************************/
extern IoExp_LevelType IoExp_ReadChannel(IoExp_ChannelType ChannelId);

/**************************************************************************
Function name   : IoExp_WriteChannel
Arguments       : ChannelId - ID of the channel 
                : Level - Value to be written
Return type     : Std_ReturnType
Description     : This function is used to Write the Pin Level of the DO Pins
**************************************************************************/
extern Std_ReturnType IoExp_WriteChannel(IoExp_ChannelType ChannelId, IoExp_LevelType Level);

/**************************************************************************
Function name   : IoExp_GetAdcResult
Arguments       : ChannelId - ID of the channel 
                : AnalogDataBuffer - Buffer in which Analog data need to be stored
Return type     : Std_ReturnType - E_OK, E_NOT_OK
Description     : This function is used to Read the ADC value of AI Pin
**************************************************************************/
extern Std_ReturnType IoExp_GetAdcResult(IoExp_ChannelType ChannelId,IoExp_AdcValueType* AnalogDataBuffer);

/**************************************************************************
Function name   : IoExp_GetAdcGroupResult
Arguments       : 
    Group             -  Specifies the ADC group to read the results from.
    AnalogDataBuffer  -  Pointer to the buffer where ADC results will be stored.
Return type     : Std_ReturnType - Returns E_OK if successful, otherwise E_NOT_OK.
Description     : This function retrieves the ADC conversion results of the specified
                  ADC group and stores them in the provided buffer. 
**************************************************************************/
extern Std_ReturnType IoExp_GetAdcGroupResult(uint8 Group,IoExp_AdcValueType* AnalogDataBuffer);

/*============================================================================
**
** Function Name    :   IoExp_Adc_SetupResultBuffer
**
** Visibility       :   Public
**
** Description      :   This function used in Setting up the result buffer for ADC
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**                      uint16* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK: ADC Result buffer is setup successfully.
**                     E_NOT_OK: ADC Result buffer is not setup successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/
extern Std_ReturnType IoExp_Adc_SetupResultBuffer(IoExp_ChannelType ChannelId, uint16* DataResultBufferPtr);

/*============================================================================
**
** Function Name    :   IoExp_Adc_StartGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in start the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
extern void IoExp_Adc_StartGroupConversion(IoExp_ChannelType ChannelId);

/*============================================================================
**
** Function Name    :   IoExp_Adc_StopGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in stop the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
extern void IoExp_Adc_StopGroupConversion(IoExp_ChannelType ChannelId);
/*============================================================================
**
** Function Name    :   IoExp_Adc_GetGroupStatus
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          : E_OK
**                    E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
extern Std_ReturnType IoExp_Adc_GetGroupStatus(IoExp_ChannelType ChannelId);

/*============================================================================
**
** Function Name    :   IoExp_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
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
extern void IoExp_Adc_EnableHardwareTrigger(IoExp_ChannelType ChannelId);

/*============================================================================
**
** Function Name    :   IoExp_Adc_DisableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
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
extern void IoExp_Adc_DisableHardwareTrigger(IoExp_ChannelType ChannelId);

/*============================================================================
**
** Function Name    :   IoExp_Adc_EnableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This enables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
extern void IoExp_Adc_EnableGroupNotification(IoExp_ChannelType ChannelId);

/*============================================================================
**
** Function Name    :   IoExp_Adc_DisableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
extern void IoExp_Adc_DisableGroupNotification(IoExp_ChannelType ChannelId);

/**************************************************************************
Function name   : IoExp_MainFunction
Arguments       : None
Return type     : None
Description     : This function is used to Initialise the General config Registers
**************************************************************************/
extern void IoExp_MainFunction(void);

/**************************************************************************
Function name   : IoExp_DeInit
Arguments       : None
Return type     : None
Description     : This function is used to DeInitialise the General config Registers
**************************************************************************/
extern void IoExp_DeInit(void);

#endif /* IOEXP_H */
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
/*Date              : 08-03-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Release                                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 12-12-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: IoExp changes to support IoHwAb Adc                   */
/*--------------------------------------------------------------------------*/
