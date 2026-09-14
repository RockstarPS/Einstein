//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
/******************************MISRA Warning Begin***********************************
  ** CID : 
  ** MISRA Title : 
  ** MISRA: 
  ** MISRA Message : 
  ** Rational: 
  ** Approved Status: NO
  ** Approved Date : 
  ** Approved By :
  ******************************MISRA Warning End************************************/

#include "LinTrcv.h"
#include "Dio.h"

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (LINTRCV_ICUCHANNELIDOFCHANNEL == STD_ON)
# include "Icu.h"
#endif

#if (LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL == STD_ON)
# include "EcuM_Cbk.h"
#endif

/********************************************************************************************************************
*  VERSION CHECK                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((LINTRCV_SW_MAJOR_VERSION != LINTRCV_CFG_SW_MAJOR_VERSION) || \
    (LINTRCV_SW_MINOR_VERSION != LINTRCV_CFG_SW_MINOR_VERSION) || \
    (LINTRCV_SW_PATCH_VERSION != LINTRCV_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((LINTRCV_AR_RELEASE_MAJOR_VERSION != LINTRCV_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (LINTRCV_AR_RELEASE_MINOR_VERSION != LINTRCV_CFG_AR_RELEASE_MINOR_VERSION) || \
    (LINTRCV_AR_RELEASE_REVISION_VERSION != LINTRCV_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

/* ===========================================================================
    M A C R O S
 =============================================================================*/

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
# define LinTrcv_Dev_InitValue                 ((uint8)0x00u)
# define LinTrcv_Dev_CheckValue                ((uint8)0xA5u)
uint8 LinTrcv_Dev_InitDetect;
#endif

#define LinTrcv_IsChannelUsedOfChannel(ch)          ((LinTrcv_GetChannelUsedOfPCConfig()[ch]) != FALSE)  
#define LinTrcv_GetInitStateOfChannel(ch)           (LinTrcv_GetInitStateConfigurationofPCConfig()[ch])
#define LinTrcv_GetDioPinEnOfDioChannel(ch)         (LinTrcv_GetDioConfigurationOfPCConfig()[(ch)].PinENOfDioConfiguration)
#define LinTrcv_GetDioPinRxOfDioChannel(ch)         (LinTrcv_GetDioConfigurationOfPCConfig()[(ch)].PinRXDOfDioConfiguration)
#define LinTrcv_GetDioPinTxOfDioChannel(ch)         (LinTrcv_GetDioConfigurationOfPCConfig()[(ch)].PinTXDOfDioConfiguration)
#define LinTrcv_IsIcuChannelIdUsedOfChannel(ch)     ((LinTrcv_GetICUChannelOfPCConfig()[ch].IcuChannelSetOfChannel) != FALSE)
#define LinTrcv_GetIcuChannelIdOfChannel(ch)        (LinTrcv_GetICUChannelOfPCConfig()[ch].IcuChannelOfChannel) 
#define LinTrcv_IsWakeupByBusUsedOfChannel(ch)      ((LinTrcv_GetIsWakeupByBusUsedOfPCConfig()[ch]) != FALSE)
#define LinTrcv_IsWakeupByPinUsedOfChannel(ch)      ((LinTrcv_GetIsWakeupByPinUsedOfPCConfig()[ch]) != FALSE)
#define LinTrcv_GetEcuMWakeupSourceIdOfChannel(ch)   (LinTrcv_GetEcuMWakeupSourceIdOfPCConfig()[ch])

#define LINTRCV_GNUM_0  0U
#define LINTRCV_GNUM_1  1U

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

static LinTrcv_Prob_Type LinTrcv_ChannelData[NO_OF_LIN_CHANNEL_USED];

static const uint8 LinTrcv_NrOfChannels = NO_OF_LIN_CHANNEL_USED;

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief      Init the transceiver with the Init state of the channel i.e Normal or Sleep
///
/// @return     None
///<br>
//---------------------------------------------------------------------------------------------------------------------

void LinTrcv_Init (LinTrcv_ConfigType *ConfigPtr)
{

    uint8 LinTrcvIndex;
    Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
    #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
    uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
    #endif

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
    /*  Check if the component is already initialized */
    if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_InitValue)
    {
      LinTrcv_ErrorId = LINTRCV_E_UNINIT;
    }
  # if (LINTRCV_USE_INIT_POINTER == STD_ON)
    /*  Check the validity of the pointer ConfigPtr */
    else if (ConfigPtr == NULL_PTR)
    {
      LinTrcv_ErrorId = LINTRCV_E_PARAM_POINTER;
    }
  # endif
    else
#endif
    {

        /* #25 Loop over all configured channels */
        for (LinTrcvIndex = 0x00u; LinTrcvIndex < LinTrcv_NrOfChannels; LinTrcvIndex++)
        {
            /*  If the channel is used */
            if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex))
            {
#if (LINTRCV_WAKEUPSUPPORT == STD_ON)
              /*  Enable Wakeup reporting for the channel, initialise WakeupReason value */
              LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupMode = LINTRCV_WUMODE_ENABLE; 
              LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason = LINTRCV_WU_ERROR; 
#endif
                switch(LinTrcv_GetInitStateOfChannel(LinTrcvIndex))
                {

                  case LINTRCV_OP_MODE_NORMAL: 
                    Dio_WriteChannel(LinTrcv_GetDioPinEnOfDioChannel(LinTrcvIndex), STD_HIGH);
                    LinTrcv_ReturnValTmp = E_OK;
                    
# if (LINTRCV_ICUCHANNELIDOFCHANNEL == STD_ON)
                        /*  Normal mode successfully set: If Icu is used, disable Icu notification */
                        if (LinTrcv_IsIcuChannelIdUsedOfChannel(LinTrcvIndex))
                        {
                          Icu_DisableNotification(LinTrcv_GetIcuChannelIdOfChannel(LinTrcvIndex));
                        }
# endif
# if (LINTRCV_WAKEUPSUPPORT == STD_ON)
              /*  Set the WakeupReason to RESET */
              LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason = LINTRCV_WU_RESET; 
# endif
                    

                  break;

                  case LINTRCV_OP_MODE_SLEEP:
                      Dio_WriteChannel(LinTrcv_GetDioPinEnOfDioChannel(LinTrcvIndex), STD_LOW);
                      LinTrcv_ReturnValTmp = E_OK;

                      
# if (LINTRCV_ICUCHANNELIDOFCHANNEL == STD_ON)
                        /*  Sleep mode successfully set: If Icu is used, enable Icu notification */
                        if (LinTrcv_IsIcuChannelIdUsedOfChannel(LinTrcvIndex))
                        {
                          Icu_EnableNotification(LinTrcv_GetIcuChannelIdOfChannel(LinTrcvIndex));
                        }
# endif
                      
                  break;
                  
                  default:
                    LinTrcv_ReturnValTmp = E_NOT_OK;
                  break;
                }

            }
            if (LinTrcv_ReturnValTmp == E_OK) 
            {
              /* #100 Change the internal state to the initial operation mode */
              LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_State = (LinTrcv_TrcvModeType)LinTrcv_GetInitStateOfChannel(LinTrcvIndex); 
            }
            else
            {
              /* Break the init loop in case of any E_NOT_OK return */
              break;
            }

        }

    }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_INIT, LinTrcv_ErrorId);
  }
#else
 
#endif

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if(LinTrcv_ReturnValTmp == E_OK)
  {
    /* Initialization went through, set flag */
    LinTrcv_Dev_InitDetect = LinTrcv_Dev_CheckValue;
  }
#endif

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief      Set the operation Mode of the transceiver 
/// @param      LinTrcvIndex: Channel number of the transceiver
/// @param      OpMode      : Operation Mode of the transceiver to be set 
/// @return     E_OK        : Operation Mode has been set 
///             E_NOT_OK    : Development error
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinTrcv_SetOpMode (uint8 LinTrcvIndex, LinTrcv_TrcvModeType OpMode)
{
  Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
  #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
  uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
  #endif

 #if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_CheckValue)
  {
    LinTrcv_ErrorId = LINTRCV_E_UNINIT;
  }
  /*  Check the validity of the parameter LinTrcvIndex */
  else if (LinTrcvIndex >= LinTrcv_NrOfChannels)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex) != TRUE)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else
#endif
  {
    SchM_Enter_LINTRCV_EXCLUSIVE_AREA_0();

    switch(OpMode)
    {

      case LINTRCV_OP_MODE_NORMAL:
        Dio_WriteChannel(LinTrcv_GetDioPinEnOfDioChannel(LinTrcvIndex), STD_HIGH);
        LinTrcv_ReturnValTmp = E_OK;
        
# if (LINTRCV_ICUCHANNELIDOFCHANNEL == STD_ON)
          /*  Normal mode successfully set: If Icu is used, disable Icu notification */
          if (LinTrcv_IsIcuChannelIdUsedOfChannel(LinTrcvIndex))
          {
            Icu_DisableNotification(LinTrcv_GetIcuChannelIdOfChannel(LinTrcvIndex));
          }
# endif
        

        break;

      case LINTRCV_OP_MODE_SLEEP:
        Dio_WriteChannel(LinTrcv_GetDioPinEnOfDioChannel(LinTrcvIndex), STD_LOW);
        LinTrcv_ReturnValTmp = E_OK;

        
# if (LINTRCV_ICUCHANNELIDOFCHANNEL == STD_ON)
        /*  Sleep mode successfully set: If Icu is used, enable Icu notification */
        if (LinTrcv_IsIcuChannelIdUsedOfChannel(LinTrcvIndex))
        {
          Icu_EnableNotification(LinTrcv_GetIcuChannelIdOfChannel(LinTrcvIndex));
        }
# endif
        
        
        break;

        default:
#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
        LinTrcv_ErrorId = LINTRCV_E_PARAM_TRCV_OPMODE;
#endif
        break;
    }

    if(LinTrcv_ReturnValTmp == E_OK)
    {
      /*  Change the internal state to the requested operation mode */
      LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_State = OpMode; 
    }
    SchM_Exit_LINTRCV_EXCLUSIVE_AREA_0();
  }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_SETOPMODE, LinTrcv_ErrorId);
  }
#else
  
#endif

    /* #100 Exit critical area */


    return LinTrcv_ReturnValTmp;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief    Get the Operation Mode of the Transceiver 
/// @param    LinTrcvIndex: Channel Number of the Transceiver
/// @param    OpMode      : Pointer to the buffer to load the current operation mode of the transceiver
/// @return   E_OK        : Operation Mode copied successfully into the buffer
///           E_NOT_OK    : Development Error
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinTrcv_GetOpMode (uint8 LinTrcvIndex, LinTrcv_TrcvModeType *OpMode)
{
  Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
  #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
  uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
  #endif

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_CheckValue)
  {
    LinTrcv_ErrorId = LINTRCV_E_UNINIT;
  }
  /*  Check the validity of the parameter LinTrcvIndex */
  else if (LinTrcvIndex >= LinTrcv_NrOfChannels)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex) != TRUE)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  /*  Check the validity of the pointer OpMode */
  else if (OpMode == NULL_PTR)
  {
    LinTrcv_ErrorId = LINTRCV_E_PARAM_POINTER;
  }
  else
#endif
  {

    *OpMode = LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_State; 
    LinTrcv_ReturnValTmp = E_OK;
  }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_GETOPMODE, LinTrcv_ErrorId);
  }
#else
  
#endif

    return LinTrcv_ReturnValTmp;

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief    Check the Wakeup Reason of the Transceiver after sleep
/// @param    LinTrcvIndex  : Channel Id of the Transceiver
/// @return   E_OK          : Wakeup Reason found successful
///           E_NOT_OK      : If wakeup Mode is disabled and development error
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinTrcv_CheckWakeup (uint8 LinTrcvIndex)
{
  Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
  #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
  uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
  #endif

#if (LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL == STD_ON)
  uint8 LinTrcv_WakeupDetected = LINTRCV_GNUM_0;
#endif

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_CheckValue)
  {
    LinTrcv_ErrorId = LINTRCV_E_UNINIT;
  }
  /*  Check the validity of the parameter LinTrcvIndex */
  else if (LinTrcvIndex >= LinTrcv_NrOfChannels)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex) != TRUE)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else
#endif
  {
#if (LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL == STD_ON)
    /*  If the channel is in sleep mode */
    if (LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_State == LINTRCV_OP_MODE_SLEEP)
    {
      /*  Enter critical area */
    SchM_Enter_LINTRCV_EXCLUSIVE_AREA_0();

      /*  Check for wakeups */
# if (LINTRCV_WAKEUPBYBUSUSEDOFCHANNEL == STD_ON)
      if (LinTrcv_IsWakeupByBusUsedOfChannel(LinTrcvIndex))
      {
        if ((Dio_ReadChannel(LinTrcv_GetDioPinRxOfDioChannel(LinTrcvIndex)) == STD_LOW) && /* PRQA S 3415 */ /* MD_LINTRCV_3415 */
            (Dio_ReadChannel(LinTrcv_GetDioPinTxOfDioChannel(LinTrcvIndex)) == STD_HIGH))
        {
          /* Rx low / Tx high: Wakeup by pin */
          LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason = LINTRCV_WU_BY_BUS; 
          LinTrcv_WakeupDetected = LINTRCV_GNUM_1;
        }
      }
#endif
# if (LINTRCV_WAKEUPBYPINUSEDOFCHANNEL == STD_ON)
      if (LinTrcv_IsWakeupByPinUsedOfChannel(LinTrcvIndex))
      {
        if ((Dio_ReadChannel(LinTrcv_GetDioPinRxOfDioChannel(LinTrcvIndex)) == STD_LOW) && /* PRQA S 3415 */ /* MD_LINTRCV_3415 */
            (Dio_ReadChannel(LinTrcv_GetDioPinTxOfDioChannel(LinTrcvIndex)) == STD_LOW))
        {
          /* Rx/Tx low: Wakeup by pin */
          LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason = LINTRCV_WU_BY_PIN; 
          LinTrcv_WakeupDetected = LINTRCV_GNUM_1;
        }
      }
# endif
      /*  If the WakeupMode is enabled: Notify EcuM/LinIf about detected wakeups (LL part) */
      if ((LinTrcv_WakeupDetected == LINTRCV_GNUM_1) && (LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupMode == LINTRCV_WUMODE_ENABLE))
      {
        LinTrcv_ReturnValTmp = E_OK;
        EcuM_SetWakeupEvent(LinTrcv_GetEcuMWakeupSourceIdOfChannel(LinTrcvIndex));
//        removed commented code for LinIf_WakeupConfirmation
      }

      /*  Exit critical area */
      SchM_Exit_LINTRCV_EXCLUSIVE_AREA_0();
    }
# if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* Channel is not in sleep mode */
      LinTrcv_ErrorId = LINTRCV_E_TRCV_NOT_SLEEP;
    }
# endif
#else
  
#endif
  }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_CHECKWAKEUP, LinTrcv_ErrorId);
  }
#else
  
#endif

  return LinTrcv_ReturnValTmp;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief    Set the Wake Up Mode of the Transceiver and notify the wakeupMode 
/// @param    LinTrcvIndex  : Channel number of the transceiver
/// @param    TrcvWakeupMode: Type of Wakeup to be notified 
/// @return   E_OK, E_NOT_OK
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinTrcv_SetWakeupMode( uint8 LinTrcvIndex, LinTrcv_TrcvWakeupModeType TrcvWakeupMode)
{

  Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
  #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
  uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
  #endif
#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_CheckValue)
  {
    LinTrcv_ErrorId = LINTRCV_E_UNINIT;
  }
  /*  Check the validity of the parameter LinTrcvIndex */
  else if (LinTrcvIndex >= LinTrcv_NrOfChannels)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex) != TRUE)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else
#endif
  {
#if (LINTRCV_WAKEUPSUPPORT == STD_ON)
      /*  Enter critical area */
      SchM_Enter_LINTRCV_EXCLUSIVE_AREA_0();

      /*  Set WakeupMode according to the parameter TrcvWakeupMode */
      switch(TrcvWakeupMode)
      {
        case LINTRCV_WUMODE_ENABLE:
          /*  For enable mode: enable WakeupReport and notify any stored Wakeup events */
          LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupMode = LINTRCV_WUMODE_ENABLE; 
# if (LINTRCV_ECUMWAKEUPSOURCEIDOFCHANNEL == STD_ON)
          switch (LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason)
          {
#  if (LINTRCV_WAKEUPBYBUSUSEDOFCHANNEL == STD_ON) 
            case LINTRCV_WU_BY_BUS:
#  endif
#  if (LINTRCV_WAKEUPBYPINUSEDOFCHANNEL == STD_ON) 
            case LINTRCV_WU_BY_PIN:
#  endif
              EcuM_SetWakeupEvent(LinTrcv_GetEcuMWakeupSourceIdOfChannel(LinTrcvIndex));
//              removed commented code for LinIf_WakeupConfirmation 
              break;

            default:
              break;
          }
# endif

          LinTrcv_ReturnValTmp = E_OK;
          break;

        case LINTRCV_WUMODE_DISABLE:
          /*  For disable mode: disable WakeupReport */
          LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupMode = LINTRCV_WUMODE_DISABLE; 
          LinTrcv_ReturnValTmp = E_OK;
          break;

        case LINTRCV_WUMODE_CLEAR:
          /*  For clear mode: set the WakeupReason to WU_ERROR only if WakeupReport is disabled */
          if (LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupMode == LINTRCV_WUMODE_DISABLE)
          {
            LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason = LINTRCV_WU_ERROR; 
            LinTrcv_ReturnValTmp = E_OK;
          }
          break;

        default: 
# if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
          LinTrcv_ErrorId = LINTRCV_E_PARAM_TRCV_WAKEUP_MODE;
# endif
          break;
      }

      /*  Exit critical area */
      SchM_Exit_LINTRCV_EXCLUSIVE_AREA_0();
#else
    
#endif
  }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_SETWAKEUPMODE, LinTrcv_ErrorId);
  }
#else
  
#endif

  return LinTrcv_ReturnValTmp;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief    Get the Bus Wakeup Reason of the transceiver
/// @param    LinTrcvIndex  : Channel number of the transceiver
/// @param    Reason        : WakeupReason is stored at pointer address 
/// @return   E_OK, E_NOT_OK
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinTrcv_GetBusWuReason(uint8 LinTrcvIndex,  LinTrcv_TrcvWakeupReasonType *Reason)
{
  Std_ReturnType LinTrcv_ReturnValTmp = E_NOT_OK;
  #if ((LINTRCV_DEV_ERROR_REPORT == STD_ON) || (LINTRCV_DEV_ERROR_DETECT == STD_ON))
  uint8 LinTrcv_ErrorId = LINTRCV_E_NO_ERROR;
  #endif

#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  if (LinTrcv_Dev_InitDetect != LinTrcv_Dev_CheckValue)
  {
    LinTrcv_ErrorId = LINTRCV_E_UNINIT;
  }
  /*  Check the validity of the parameter LinTrcvIndex */
  else if (LinTrcvIndex >= LinTrcv_NrOfChannels)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  else if (LinTrcv_IsChannelUsedOfChannel(LinTrcvIndex) != TRUE)
  {
    LinTrcv_ErrorId = LINTRCV_E_INVALID_LIN_NETWORK;
  }
  /*  Check the validity of the pointer Reason */
  else if (Reason == NULL_PTR)
  {
    LinTrcv_ErrorId = LINTRCV_E_PARAM_POINTER;
  }
  else
#endif
  {
#if (LINTRCV_WAKEUPSUPPORT == STD_ON)
    /*  Return the current WakeupReason */
    *Reason = LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason; 

    /*  If the stored WakeupReason is valid: Return E_OK */
    if (LinTrcv_ChannelData[LinTrcvIndex].LinTrcv_WakeupReason != LINTRCV_WU_ERROR)
    {
      LinTrcv_ReturnValTmp = E_OK;
    }
#else
    *Reason = LINTRCV_WU_NOT_SUPPORTED; 
    
#endif
  }

#if (LINTRCV_DEV_ERROR_REPORT == STD_ON)
  if (LinTrcv_ErrorId != LINTRCV_E_NO_ERROR)
  {
    (void)Det_ReportError(LINTRCV_MODULE_ID, 0, LINTRCV_SID_GETBUSWUREASON, LinTrcv_ErrorId);
  }
#else
  
#endif

  return LinTrcv_ReturnValTmp;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief    Init Memory Function
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinTrcv_InitMemory (void)
{

  /*  Set state to uninitialized */
#if (LINTRCV_DEV_ERROR_DETECT == STD_ON)
  LinTrcv_Dev_InitDetect = LinTrcv_Dev_InitValue;
#endif

}

/*============================================================================
**Date               : 24-Sep-2019
**CDSID              : ABAVALAT
**Traceability       : 1368881
**Change Description : Coverity fix.
**============================================================================*/
/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/
