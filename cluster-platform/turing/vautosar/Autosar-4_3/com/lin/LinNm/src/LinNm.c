
 /*  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *   File Name     :   LinNm.c
 *    Component    :   LIN Network Management
 *       Module    :   LIN 
 *   Platforms     :   This layer is Micro and Hardware agnostic & hence it satisfies the below requirement it
 *                     [SWS_LinNm_00026] - The AUTOSAR LinNm state machine shall be processor independent, 
 *                                         which means shall  not rely on any processor specific hardware support 
 *                                         and thus shall be realizable on any processor architecture that is in 
 *                                         the scope of AUTOSAR.
 *  Description    :   Implementation of LIN Network Management function network request and release, passive start up,
 *                     get state and get version info 
 *                     Main function.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LinNm.h"                              
#include "LinNm_Par_Cfg.h"
#include "LinNm_Cbk.$h"
#if ( LINNM_NM_CBK_SUPPORT == STD_ON )
#include "Nm_Cbk.h"
#endif
#include "SchM_LinNm.$h"
#include "LinNm_MemMap.$h"
#if ( LINNM_COM_USER_DATA_SUPPORT == STD_ON )
#include "PduR_LinNm.$h"
#endif
#if ( LINNM_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"                                      /* Include Development Error Tracer */
#endif

/********************************************************************************************************************
*  VERSION CHECK                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((LINNM_SW_MAJOR_VERSION != LINNM_CFG_SW_MAJOR_VERSION) || \
    (LINNM_SW_MINOR_VERSION != LINNM_CFG_SW_MINOR_VERSION) || \
    (LINNM_SW_PATCH_VERSION != LINNM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((LINNM_AR_RELEASE_MAJOR_VERSION != LINNM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (LINNM_AR_RELEASE_MINOR_VERSION != LINNM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (LINNM_AR_RELEASE_REVISION_VERSION != LINNM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
/* LIN NM Network Instance ID */
#define LINNM_INSTANCE_ID               ((uint8)0x00)

#define LINNM_ZERO                      0x00U
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
/*@brief By this array variable, Store LINNM network state(unintialization, Network(Communication),and BUS sleep) 
  during Network Request and release process from upper layer  */
static Nm_StateType LinNm_NmState[LINNM_NUM_OF_CHANNELS];

/*@brief By this array variable, Store LINNM network Mode(Network(Communication),and BUS sleep ),
  during Network Request and release process from upper layer  */
static Nm_ModeType LinNm_NmMode[LINNM_NUM_OF_CHANNELS];

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LinNm_InitMemory()
 **********************************************************************************************************************/
/*  service name        :      LinNm_InitMemory.
 *  @brief              :      Initializes component variables in *_INIT_* sections at power up.
 *  service ID[hex]     :      None
 *  Sync/Async          :      None
 *  Reentrancy          :      None
 *  Parameters (in)     :      None
 *  Parameters (inout)  :      None
 *  Parameters (out)    :      None
 *  pre                 :      Module is uninitialized. Interrupts are disabled.       
 *  note                :      Use this function in case these variables are not initialized by the startup code.
 **********************************************************************************************************************/
void LinNm_InitMemory( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  /*This function local variable used as array index for access the LIN Nm network state buffer*/
  uint8 LINNM_Channel_Idx;

  /* Check function local variables less than the number of LIN network channels */
  for( LINNM_Channel_Idx = LINNM_ZERO; LINNM_Channel_Idx < LINNM_NUM_OF_CHANNELS; LINNM_Channel_Idx++ )
  {
   /* Set state to every LIN metwork channels as unintialization */
    LinNm_NmState[LINNM_Channel_Idx] = NM_STATE_UNINIT; 
  }
}

/***********************************************************************************************************************
 *  LinNm_Init()
 **********************************************************************************************************************/
/*  service name        :      LinNm_Init.
 *  @brief              :      Initializes all component variables and sets the component state to initialized.
 *                             By default the NM starts in the Bus-Sleep State & Bus-Sleep Mode. if parameter configptr
 *                             is invalid report to det with errorid.
 *  service ID[hex]     :      0x00
 *  Sync/Async          :      Synchronous
 *  Reentrancy          :      Non Reentrant
 *  Parameters (in)     :      ConfigPtr - Pointer to a selected configuration structure
 *  Parameters (inout)  :      None
 *  Parameters (out)    :      None
 *  return              :      None
 *  Description         :      Initialize the complete LinNm module.
 *  pre-condition       :      Interrupts are disabled,Module is uninitialized, and LinNm_InitMemory has been called.       
 *  note                :      By application (EcuM) and before of any NM service (except LinNm_InitMemory() ).
 **********************************************************************************************************************/

void LinNm_Init( const LinNm_ConfigType* ConfigPtr )
{   /* ----- Local Variables ---------------------------------------------- */
  /*This function local variable used as array index for access the LIN Nm network state buffer*/
  uint8          LinNm_Channel_Idx;
   # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif
  /* checking configptr parameter is invalid or valid */
  if(ConfigPtr == NULL_PTR)
  {
    /*if selected configuration is null then assign initialization has been failed to erroId*/
    errorId= LINNM_E_INIT_FAILED;
  }
  /* [SWS_LinNm_00019] ⌈ff initialized, by default, the linNm module shall set the network state to nm_state_bus_sleep. */
  /* [SWS_LinNm_00020] ⌈if initialized, by default, the linNm module shall enter the bus-sleep mode. */
  else if( (ConfigPtr->LinNm_State != NM_STATE_BUS_SLEEP) && (ConfigPtr->LinNm_Mode != NM_MODE_BUS_SLEEP) )
  {
    /* if configptr parameter is not equal to sleep state and sleep mode then assign invalid parameter*/
    errorId= LINNM_E_INVALID_PARAMETER;
  }
  else{
   /* Check function local variables less than the number of LIN network channels */
  /*  Initialize state and mode of each channel to bus sleep  */
  for( LinNm_Channel_Idx = LINNM_ZERO; LinNm_Channel_Idx < LINNM_NUM_OF_CHANNELS; LinNm_Channel_Idx++ )
  {
    /* Set state to every LIN metwork channels as Bus Sleep */
    LinNm_NmState[LinNm_Channel_Idx] = ConfigPtr->LinNm_State;

   /* [SWS_LinNm_00018] ⌈If the initialization of the LinNm module (LinNm_Init)
   is successful, the LinNm module shall set the Network Management State to
   nm state bus sleep.*/

   /* Set Mode to every LIN metwork channels as Bus sleep */
    LinNm_NmMode [LinNm_Channel_Idx] = ConfigPtr->LinNm_Mode; 
     /*check whether linnm state change parameter is enabled or not*/
#if ( LINNM_STATE_CHANGE_IND_ENABLED == STD_ON )
    /* No callouts shall be made from the init function, since it is not known if the other module is initialized */
#endif
   }  
  }
  /* ----- Development Error Report --------------------------------------- */

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*Check whether if error is occured or not*/
  if (LINNM_E_NO_ERROR != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_INIT_ID, errorId);
  }
  else
  {
   /*Do nothing*/
  }
# endif 
}

#if ( LINNM_PASSIVE_MODE_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_PassiveStartUp()
 **********************************************************************************************************************/
/* Service name        :          LinNm_PassiveStartUp.
 * @brief              :          Request the network and change to Network mode. This service has no effect if the current state is not
 *                                equal to Bus Sleep Mode and returns E_NOT_OK.
 * Service ID[hex]     :          0x01
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Reentrant (but not for the same NM-Channel)
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK: No error
 *                                E_NOT_OK: Passive startup of network management has failed
 * Description         :          Passive startup of the AUTOSAR LIN NM.
 **********************************************************************************************************************/

 Std_ReturnType LinNm_PassiveStartUp( NetworkHandleType nmChannelHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  /*This local variables is used for store network request function return status*/
  Std_ReturnType             retVal= E_NOT_OK;

  /*This local variables used for access an array of LIN NM mode and State buffer*/
  NetworkHandleType         LinNm_ChannelTmp;
  /*This local variables carries the 0 and 1 value and it is provide access to  call nm call back function */
  uint8                     stateChanged;
  /*Check whether development error detection parameter is enabled or not*/
   # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID
    and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )

  /*  For validity of parameter nmChannelHandle, Check whether nmChannelHandle is greater than or equal to
      number of system LIN channels */
  if (LINNM_NUMBER_OF_SYS_CHANNELS  <= nmChannelHandle)
  {
    /*If LinNm Passive StartUp API service called with wrong channel number, assign invalid channel to error ID*/
     errorId = LINNM_E_INVALID_CHANNEL;
  }
  else
# endif  
  {

    /*For Ensures that the local variable "LinNm_ChannelTmp" is in range 0 to LinNm_NumberOfLinNmChannels - 1, 
      get element of array LinNm_SystemToLinNmChannel*/
    LinNm_ChannelTmp  = LinNm_SystemToNmChannelInd[nmChannelHandle];

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )

    /* To Ensure parameter nmChannelHandle references a LinNm channels, Check whether local variables "LinNm_ChannelTmp" 
    greater than or equal to number of  LIN ntwork channels*/
    if ((NetworkHandleType)LINNM_NUM_OF_CHANNELS  <= LinNm_ChannelTmp)
    {
      /*if LinNm Passive StartUp  API service called with wrong channel number, assign invalid channel to error ID*/
      errorId = LINNM_E_INVALID_CHANNEL;
    }
    /*  Check whether the LIN NM is initialized or not. */
    else if(NM_STATE_UNINIT  == LinNm_NmState[LinNm_ChannelTmp] )
    {
      /* if LinNm Passive StartUp  API service used without module initialization, assign unintitialization to error id*/
      errorId = LINNM_E_NO_INIT;
    }
    else
# endif
    {
        /* assigning stateChanged value as zero */
      stateChanged = STATE_CHANGE_DISABLE;
      /*Check whether LIN network mode is bus sleep or not */
      if (NM_MODE_BUS_SLEEP  == LinNm_NmMode[LinNm_ChannelTmp])
      {
        /* If LIN network mode is Bus-Sleep, switch to communication Network mode */
        LinNm_NmMode[LinNm_ChannelTmp] = NM_MODE_NETWORK; 
        /*  Check whether LIN network state is Bus-Sleep or not */
        if (NM_STATE_BUS_SLEEP  == LinNm_NmState[LinNm_ChannelTmp]) 
        {
          /* If LIN network State is Bus-Sleep, switch to Network communication State */
          LinNm_NmState[LinNm_ChannelTmp] = NM_STATE_NORMAL_OPERATION; 
        }
        else
        {
          /* Do nothing */
        }
        /* assigning stateChanged value as state change enable  */
        stateChanged  = STATE_CHANGE_ENABLE;
      }
      else
      {
        /*if linnm mode is not in sleep mode and set return value as E_NOT_OK*/
        retVal = E_NOT_OK;
      }
        /*check whether stateChanged value is assigned as one*/
         if ( stateChanged == LINNM_NM_NOTIFICATION_IND )
         {
           /*check whether nm callback parameter is enabled or not*/
             #if ( LINNM_NM_CBK_SUPPORT == STD_ON )
             /*calling NM callback function for network mode change*/
              Nm_NetworkMode( nmChannelHandle );
              #endif
             /*check whetheR linnm remote sleep indication and linm passive mode parameter is enabled or not*/ 
#if ( (LINNM_REMOTE_SLEEP_INDICATION_ENABLED == STD_ON) && (LINNM_PASSIVE_MODE_ENABLED == STD_OFF) )
            /*calling NM callback function for nm remotesleep indication*/
              Nm_RemoteSleepIndication( nmChannelHandle );
#endif
            /*check whether linnm state change parameter is enabled or not*/ 
#if ( LINNM_STATE_CHANGE_IND_ENABLED == STD_ON )
            /*Calling NM callback function for nm state change notification*/
            Nm_StateChangeNotification( nmChannelHandle, NM_STATE_BUS_SLEEP, NM_STATE_NORMAL_OPERATION );
#endif
              /*Request for bus communication was accepted,and set return vaule as OK*/
              retVal = E_OK;
         }
         else
         {
          /* if state channge is not enabled return "E_NOT_OK"*/
		       retVal = E_NOT_OK;
         }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )

  /*Check whether if error is occured or not*/
  if (LINNM_E_NO_ERROR != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_PASSIVESTARTUP, errorId);
  }
  else
  {
   /*Do nothing*/
  }
# endif

/*Return bus communication request process status */
  return retVal;
} 
# endif


#if ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF )
/***********************************************************************************************************************
 *  LinNm_NetworkRequest()
 **********************************************************************************************************************/
/* Service name        :          LinNm_NetworkRequest.
 * @brief              :          Request the network and change to Network mode. This service has no effect if the current state is not
 *                                equal to Bus Sleep Mode.
 * Service ID[hex]     :          0x02
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Reentrant (but not for the same NM-Channel)
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK: No error
 *                                E_NOT_OK: Requesting of network has failed.
 * Description         :          Request the network, since ECU needs to communicate on the bus.
 **********************************************************************************************************************/


 Std_ReturnType LinNm_NetworkRequest( NetworkHandleType nmChannelHandle )
{
  /* ----- Local Variables ---------------------------------------------- */

  /*This local variables is used for store network request function return status*/
  Std_ReturnType             retVal= E_NOT_OK;

  /*This local variables used for access an array of LIN NM mode and State buffer*/
  NetworkHandleType         LinNm_ChannelTmp;
  /*This local variables carries the 0 and 1 value and it is provide access to  call nm call back function */
  uint8                     stateChanged;
  /*Check whether development error detection parameter is enabled or not*/
   # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*  For validity of parameter nmChannelHandle, Check whether nmChannelHandle is greater than or equal to 
      number of sytem LIN channels */
  if (LINNM_NUMBER_OF_SYS_CHANNELS <= nmChannelHandle)
  {
    /*If LinNm_NetworkRequest API service called with wrong channel number, assign invalid channel to error ID*/
     errorId = LINNM_E_INVALID_CHANNEL;
  }
  else
# endif  
  {
    /*For Ensures that the local variable "LinNm_ChannelTmp" is in range 0 to LinNm_NumberOfLinNmChannels - 1, 
      get element of array LinNm_SystemToLinNmChannel*/
    LinNm_ChannelTmp  = LinNm_SystemToNmChannelInd[nmChannelHandle];

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )

    /* To Ensure parameter nmChannelHandle references a LinNm channels, Check whether local variables "LinNm_ChannelTmp" 
    greater than or equal to number of  LIN ntwork channels*/
    if ((NetworkHandleType)LINNM_NUM_OF_CHANNELS  <= LinNm_ChannelTmp)
    {
      /*if LinNm_NetworkRequest API service called with wrong channel number, assign invalid channel to error ID*/
      errorId = LINNM_E_INVALID_CHANNEL;
    }
    /*  Check whether the LIN NM is initialized or not. */
    else if(NM_STATE_UNINIT  ==  LinNm_NmState[LinNm_ChannelTmp])
    {
      /* if LinNm_NetworkRequest API service used without module initialization, assign unintitialization to error id*/
      errorId = LINNM_E_NO_INIT;
    }
    else
# endif
    {
      /* assigning stateChanged value as zero */
      stateChanged = STATE_CHANGE_DISABLE;
      /*Check whether LIN network mode is bus sleep or not */
      if (NM_MODE_BUS_SLEEP  == LinNm_NmMode[LinNm_ChannelTmp])
      {
        /* If LIN network mode is Bus-Sleep, switch to communication Network mode */
        LinNm_NmMode[LinNm_ChannelTmp] = NM_MODE_NETWORK; 
        
        /*  Check whether LIN network state is Bus-Sleep or not */
        if (NM_STATE_BUS_SLEEP  == LinNm_NmState[LinNm_ChannelTmp]) 
        {
          /* If LIN network State is Bus-Sleep, switch to Network communication State */
          LinNm_NmState[LinNm_ChannelTmp] = NM_STATE_NORMAL_OPERATION; 
        }
        else
        {
          /* Do nothing */
        }
        /* assigning stateChanged value as state change enable  */
        stateChanged  = STATE_CHANGE_ENABLE;
    
      }
      else
      {
        /*if linnm mode is not in sleep mode and set return value as E_NOT_OK*/
        retVal = E_NOT_OK;
      }
        /*check whether stateChanged value is assigned as one*/
         if ( stateChanged == LINNM_NM_NOTIFICATION_IND )
         {
           /*check whether nm callback parameter is enabled or not*/
             #if ( LINNM_NM_CBK_SUPPORT == STD_ON )
             /*calling NM callback function for network mode change*/
              Nm_NetworkMode( nmChannelHandle );
              #endif
             /*check whetheR linnm remote sleep indication and linm passive mode parameter is enabled or not*/ 
#if ( (LINNM_REMOTE_SLEEP_INDICATION_ENABLED == STD_ON) && (LINNM_PASSIVE_MODE_ENABLED == STD_OFF) )
            /*calling NM callback function for nm remotesleep indication*/
              Nm_RemoteSleepIndication( nmChannelHandle );
#endif
            /*check whether linnm state change parameter is enabled or not*/ 
#if ( LINNM_STATE_CHANGE_IND_ENABLED == STD_ON )
            /*Calling NM callback function for nm state change notification*/
            Nm_StateChangeNotification( nmChannelHandle, NM_STATE_BUS_SLEEP, NM_STATE_NORMAL_OPERATION );
#endif
              /*Request for bus communication was accepted,and set return vaule as OK*/
              retVal = E_OK;
         }
         else
         {
          /* if state channge is not enabled return "E_NOT_OK"*/
		          retVal = E_NOT_OK;
         }
    }
  }

  /* ----- Development Error Report --------------------------------------- */

  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*Check whether if error is occured or not*/
  if (LINNM_E_NO_ERROR != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_NETWORKREQUEST, errorId);
  }
  else
  {
   /*Do nothing*/
  }
# endif

/*Return Bus communication request process status*/
  return retVal;
} 


/***********************************************************************************************************************
 *  LinNm_NetworkRelease()
 **********************************************************************************************************************/
/* Service name        :          LinNm_NetworkRelease.
 * @brief              :          Release the network and change to Bus Sleep mode. This service has no effect if the current state is not
 *                                equal to Network Mode.
 * Service ID[hex]     :          0x03
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Reentrant (but not for the same NM-Channel)
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK: No error
 *                                E_NOT_OK: Releasing of network has failed.
 * Description         :          Release the network, since ECU doesn't have to communicate on the bus.
 **********************************************************************************************************************/

Std_ReturnType LinNm_NetworkRelease(  NetworkHandleType nmChannelHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  /*This local variables is used for store network request function return status*/
  Std_ReturnType             retVal= E_NOT_OK;

  /*This local variables used for access an array of LIN NM mode and State buffer*/
  NetworkHandleType         LinNm_ChannelTmp;
   /*This local variables carries the 0 and 1 value and it is provide access to  call nm call back function */
  uint8                     stateChanged;
  
   # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID
    and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif

   /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*  For validity of parameter nmChannelHandle, Check whether nmChannelHandle is greater than or equal to 
      number of sytem LIN channels */
  if(LINNM_NUMBER_OF_SYS_CHANNELS  <= nmChannelHandle )
  {
    /*If LinNm Network Release API service called with wrong channel number, assign invalid channel to error ID*/
    errorId = LINNM_E_INVALID_CHANNEL;
  }
  else
  # endif
  {
    /*For Ensures that the local variable "LinNm_ChannelTmp" is in range 0 to LinNm_NumberOfLinNmChannels - 1, 
      get element of array LinNm_SystemToLinNmChannel*/
    LinNm_ChannelTmp  = LinNm_SystemToNmChannelInd[nmChannelHandle];

 /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )

    /* To Ensure parameter nmChannelHandle references a LinNm channels, Check whether local variables "LinNm_ChannelTmp" 
    greater than or equal to number of  LIN ntwork channels*/
    if ((NetworkHandleType)LINNM_NUM_OF_CHANNELS  <= LinNm_ChannelTmp)
    {
      /*if LinNm Network Release API service called with wrong channel number, assign invalid channel to error ID*/
       errorId = LINNM_E_INVALID_CHANNEL;
    }
    /*  Check whether the LIN NM is initialized or not. */
    else if(NM_STATE_UNINIT == LinNm_NmState[LinNm_ChannelTmp] )
    {
      /* if LinNm Network Release API service used without module initialization, assign unintitialization to error id*/
       errorId = LINNM_E_NO_INIT;
    }
    else
# endif
    {
       /* assigning stateChanged value as zero */
      stateChanged = STATE_CHANGE_DISABLE;
      /*Check whether LIN network mode is bus sleep or not */
      if (NM_MODE_BUS_SLEEP  == LinNm_NmMode[LinNm_ChannelTmp])
      {
        /* If LIN network mode is Bus-Sleep, switch to communication Network mode */
        LinNm_NmMode[LinNm_ChannelTmp] = NM_MODE_NETWORK; 
        
        /*  Check whether LIN network state is Bus-Sleep or not */
        if (NM_STATE_BUS_SLEEP  == LinNm_NmState[LinNm_ChannelTmp]) 
        {
          /* If LIN network State is Bus-Sleep, switch to Network communication State */
          LinNm_NmState[LinNm_ChannelTmp] = NM_STATE_NORMAL_OPERATION; 
        }
        else
        {
          /* Do nothing */
        }
        /* assigning stateChanged value as state change enable  */
        stateChanged  = STATE_CHANGE_ENABLE;
    
      }
      else
      {
        /*if linnm mode is not in sleep mode and set return value as E_NOT_OK*/
        retVal = E_NOT_OK;
      }
        /*check whether stateChanged value is assigned as one*/
         if ( stateChanged == LINNM_NM_NOTIFICATION_IND )
         {
                      /*check whether nm callback parameter is enabled or not*/ 
#if ( LINNM_NM_CBK_SUPPORT == STD_ON )
            /*calling NM callback function for sleep mode change*/
            Nm_BusSleepMode( nmChannelHandle );
# endif
            /*check whetheR linnm state change ind parameter is enabled or not*/       
# if ( LINNM_STATE_CHANGE_IND_ENABLED == STD_ON )
          /*calling NM call back for state change notification indication*/
             Nm_StateChangeNotification( nmChannelHandle, NM_STATE_NORMAL_OPERATION, NM_STATE_BUS_SLEEP );
# endif    
              /*Request for bus communication was accepted,and set return vaule as OK*/
              retVal = E_OK;
         }
         else
         {
          /* if state channge is not enabled return "E_NOT_OK"*/
		  retVal = E_NOT_OK;
         }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
   /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
 /*Check whether if error is occured or not*/
  if (LINNM_E_NO_ERROR  != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_NETWORKRELEASE, errorId);
  }
  else
  {
    /*Do nothing*/
  }
# endif

/*Return Bus communication release process status*/
  return retVal;
} 
#endif /* ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF ) */



# if ( LINNM_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  LinNm_GetVersionInfo()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetVersionInfo.
 * @brief              :          This service returns the version information of this module.
 * Service ID[hex]     :          0xf1
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant
 * Parameters (in)     :          None
 * Parameters (inout)  :          None
 * Parameters (out)    :          versioninfo - Pointer to where to store the version information of this module
 * Return value        :          None
 **********************************************************************************************************************/

void LinNm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  
 # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID
    and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif

  /* ----- Development Error Checks ------------------------------------- */
  /*Check whether development error detection parameter is enabled or not*/
# if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /* checking versioninfo parameter value is equal to null pointer */
  if (versioninfo == NULL_PTR)
  {
    /*if version info is equal to null pointer, assign errorid as linnm param pointer */
    errorId = LINNM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* version information for linNM vendor id*/
    versioninfo->vendorID = (uint16) LINNM_VENDOR_ID; /* SBSW_LINNM_VERSIONINFO_PTR */
    /* version information for linNM module id*/
    versioninfo->moduleID = (uint16) LINNM_MODULE_ID; /* SBSW_LINNM_VERSIONINFO_PTR */
     /* version information for linNM major version*/
    versioninfo->sw_major_version = (uint8)LINNM_SW_MAJOR_VERSION; /* SBSW_LINNM_VERSIONINFO_PTR */
    /* version information for linNM minor version*/
    versioninfo->sw_minor_version = (uint8)LINNM_SW_MINOR_VERSION; /* SBSW_LINNM_VERSIONINFO_PTR */
    /* version information for linNM patch version*/
    versioninfo->sw_patch_version = (uint8)LINNM_SW_PATCH_VERSION; /* SBSW_LINNM_VERSIONINFO_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
 /*Check whether development error detection parameter is enabled or not*/ 
#if ( LINNM_DEV_ERROR_DETECT == STD_ON )
 /*Check whether if error is occured or not*/
  if ( LINNM_E_NO_ERROR  != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_GETVERSIONINFO, errorId);
  }
  else
  {
    /*Do nothing*/
  }
#endif
}
#endif


#if ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF ) && ( LINNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON )

/***********************************************************************************************************************
 *  LinNm_RequestBusSynchronization()
 **********************************************************************************************************************/
/* Service name        :          LinNm_RequestBusSynchronization.
 * Description:        :          Empty function to be complaint with NM specifications. Request bus synchronization.
 * Service ID[hex]     :          0xc0`
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Non Reentrant
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_RequestBusSynchronization( NetworkHandleType nmChannelHandle)
{
  /*This local variables is used for store network request function return status*/
  Std_ReturnType             retVal= E_OK;

   /*Empty function to be complaint with NM specifications. Request bus synchronization.*/

return retVal;
}
#endif /* ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF ) && ( LINNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON ) */


#if ( LINNM_REMOTE_SLEEP_INDICATION_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_CheckRemoteSleepIndication()
 **********************************************************************************************************************/
/* Service name        :          LinNm_CheckRemoteSleepIndication.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0xd0
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant (but not for the same NM-channel)
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmRemoteSleepIndPtr - Pointer where check result of remote sleep indication 
 *                                shall be copied to
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_CheckRemoteSleepIndication( NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}
#endif


#if ( LINNM_COORDINATOR_SYNC_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  LinNm_SetSleepReadyBit()
 **********************************************************************************************************************/
/* Service name        :          LinNm_SetSleepReadyBit.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x10
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Non Reentrant
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (in)     :          nmSleepReadyBit - Value written to ReadySleep Bit in CBV
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_SetSleepReadyBit( NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}
#endif


#if ( LINNM_COM_CONTROL_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_DisableCommunication()
 **********************************************************************************************************************/
/* Service name        :          LinNm_DisableCommunication.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x04
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle  - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_DisableCommunication( NetworkHandleType networkHandle )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}


/***********************************************************************************************************************
 *  LinNm_EnableCommunication()
 **********************************************************************************************************************/
/* Service name        :          LinNm_EnableCommunication.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x05
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_EnableCommunication( NetworkHandleType networkHandle )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}
#endif


# if ( LINNM_USER_DATA_ENABLED == STD_ON )
# if ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF )
# if ( LINNM_COM_USER_DATA_SUPPORT == STD_OFF )

/***********************************************************************************************************************
 *  LinNm_SetUserData()
 **********************************************************************************************************************/
/* Service name        :          LinNm_SetUserData.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x06
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_SetUserData( NetworkHandleType networkHandle, const uint8* nmUserDataPtr )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;

}
#endif
#endif /* ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF ) */

/***********************************************************************************************************************
 *  LinNm_GetUserData()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetUserData.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x07
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmUserDataPtr - Pointer where user data out of the last successfully 
 *                                received NM message shall be copied to 
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_GetUserData( NetworkHandleType networkHandle, uint8* nmUserDataPtr )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}
#endif  /* ( LINNM_USER_DATA_ENABLED == STD_ON ) */

#if ( ( LINNM_NODE_ID_ENABLED == STD_ON ) || ( LINNM_USER_DATA_ENABLED == STD_ON ) )
/***********************************************************************************************************************
 *  LinNm_GetPduData()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetPduData.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x08
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmPduData - Pointer where NM PDU shall be copied to.
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_GetPduData( NetworkHandleType networkHandle, uint8* nmPduData )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;

}
#endif

#if ( LINNM_NODE_DETECTION_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_RepeatMessageRequest()
 **********************************************************************************************************************/
/* Service name        :          LinNm_RepeatMessageRequest.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x09
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_RepeatMessageRequest( NetworkHandleType networkHandle )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;

}
#endif

#if ( LINNM_NODE_ID_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_GetNodeIdentifier()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetNodeIdentifier.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x0a
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmNodeIdPtr  - Pointer where node identifier out of the last successfully 
 *                                received NM-message shall be copied to
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_GetNodeIdentifier( NetworkHandleType networkHandle, uint8* nmNodeIdPtr )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;

}

/***********************************************************************************************************************
 *  LinNm_GetLocalNodeIdentifier()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetLocalNodeIdentifier.
 * Description:        :          Empty function to be complaint with NM specifications.
 * Service ID[hex]     :          0x0b
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Parameters (in)     :          NetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmNodeIdPtr  - Pointer where node identifier of the local node shall be copied to
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_GetLocalNodeIdentifier( NetworkHandleType networkHandle, uint8* nmNodeIdPtr )
{
  Std_ReturnType             retVal= E_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;

}
#endif /* ( LINNM_NODE_ID_ENABLED  == STD_ON ) */


/***********************************************************************************************************************
 *  LinNm_GetState()
 **********************************************************************************************************************/
/* Service name        :          LinNm_GetState.
 * Description:        :          Returns the state of the network management.The function 
 *                                LinNm_GetState shall be called (e.g. LinNm_GetState function is called 
 *                                if channel is configured as LIN).
 * Service ID[hex]     :          0x0e
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant
 * Parameters (in)     :          nmNetworkHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          nmStatePtr  - Pointer where state of the network management shall be copied to
 * Parameters (out)    :          nmModePtr  -  Pointer to the location where the mode of the network management 
 *                                shall be copied to
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/

Std_ReturnType LinNm_GetState( NetworkHandleType nmNetworkHandle,
                                                   Nm_StateType* nmStatePtr,
                                                   Nm_ModeType* nmModePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  /*This local variables is used for store network request function return status*/
  Std_ReturnType             retVal= E_NOT_OK;

  /*This local variables used for access an array of LIN NM mode and State buffer*/
  NetworkHandleType         LinNm_ChannelTmp;
  /*Check whether development error detection parameter is enabled or not*/
   # if ( LINNM_DEV_ERROR_DETECT == STD_ON )
  /*This local variable is used for store error ID and Initialize local variable "errorId" as no error occured */
   uint8                     errorId= LINNM_E_NO_ERROR;
	#endif

/*Check whether development error detection parameter is enabled or not*/
#if ( LINNM_DEV_ERROR_DETECT == STD_ON )

  /*  For validity of parameter nmChannelHandle, Check whether nmChannelHandle is greater than or equal to 
      number of sytem LIN channels */
  if(LINNM_NUMBER_OF_SYS_CHANNELS  <= nmNetworkHandle )
  {
    /*If LinNm Get state API service called with wrong channel number, assign invalid channel to error ID*/
     errorId = LINNM_E_INVALID_CHANNEL;
  }
  /* To Ensure validity of parameters nmStatePtr and nmModePtr, check whether nmStatePtr and nmModePtr 
     equal to null pointer or not  */
  else if( (NULL_PTR == nmStatePtr) || ( NULL_PTR == nmModePtr) )
  {
    /*if Null pointer has been passed as an argument, assign error parameter to error ID*/
     errorId = LINNM_E_PARAM_POINTER;
  }
  else
#endif
  {
      /*For Ensures that the local variable "LinNm_ChannelTmp" is in range 0 to LinNm_NumberOfLinNmChannels - 1, 
      get element of array LinNm_SystemToLinNmChannel*/
    LinNm_ChannelTmp  = LinNm_SystemToNmChannelInd[nmNetworkHandle];

/*Check whether development error detection parameter is enabled or not*/
#if ( LINNM_DEV_ERROR_DETECT == STD_ON )

    /* To Ensure parameter nmChannelHandle references a LinNm channels, Check whether local variables "LinNm_ChannelTmp" 
    greater than or equal to number of LIN ntwork channels*/
    if ((NetworkHandleType)LINNM_NUM_OF_CHANNELS  <= LinNm_ChannelTmp )
    {
      /*if LinNm Get state API service called with wrong channel number, assign invalid channel to error ID*/
       errorId = LINNM_E_INVALID_CHANNEL;
    }
    /*  Check whether the LIN NM is initialized or not. */
    else if(NM_STATE_UNINIT == LinNm_NmState[LinNm_ChannelTmp] )
    {
       /* if LinNm Get state API service used without module initialization, assign unintitialization to error id*/
      errorId = LINNM_E_NO_INIT;
    }
    else
#endif
    {

      /*  Assign current channel network state into given pointer   */
      *nmStatePtr = LinNm_NmState[LinNm_ChannelTmp]; 

      /*  Assign current channel network mode into given pointer   */
      *nmModePtr  = LinNm_NmMode[LinNm_ChannelTmp];

      /*Request for get state process is done and Set return vaule as OK*/
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
 /*Check whether development error detection parameter is enabled or not*/ 
#if ( LINNM_DEV_ERROR_DETECT == STD_ON )
 /*Check whether if error is occured or not*/
  if ( LINNM_E_NO_ERROR  != errorId )
  {
    /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/
    (void)Det_ReportError( LINNM_MODULE_ID, LINNM_INSTANCE_ID, LINNM_SID_GETSTATE, errorId);
  }
  else
  {
    /*Do nothing*/
  }
#endif

/*Return get state process status*/
  return retVal;
}

#if ( LINNM_COM_USER_DATA_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  LinNm_Transmit()
 **********************************************************************************************************************/
/* Service name        :          LinNm_Transmit.
 * Description:        :          Empty function to be complaint with NM specifications. Always return E_NOT_OK
 * Service ID[hex]     :          0x0f
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Non Reentrant
 * Parameters (in)     :          LinTxPduId - Upper layer identification of the LIN frame to be transmitted 
 *                                (not the LIN protected ID). This parameter is used to determine the corresponding 
 *                                LIN protected ID (PID) and implicitly the LIN Driver instance as well as the 
 *                                corresponding LIN Controller device.
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          Std_ReturnType
 *                                E_NOT_OK: returns always
 **********************************************************************************************************************/

Std_ReturnType LinNm_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr )
{
  Std_ReturnType             retVal= E_NOT_OK;

  /*Empty function to be complaint with NM specifications*/
  
return retVal;
}
#endif


#if ( TX_CONFIRMATION_ENABLE == STD_ON )
/***********************************************************************************************************************
 *  LinNm_TxConfirmation()
 **********************************************************************************************************************/
/* Service name        :          LinNm_TxConfirmation.
 * Description:        :          The lower layer communication interface module confirms the transmission of an I-PDU.
 * Service ID[hex]     :          0x40
 * Sync/Async          :          Synchronous
 * Reentrancy          :          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in)     :          TxPduId - ID of the I-PDU that has been transmitted.
 * Parameters (inout)  :          None
 * Parameters (out)    :          None 
 * Return value        :          None
 **********************************************************************************************************************/

void LinNm_TxConfirmation(PduIdType TxPduId)
{
  /*Empty Function*/
}
#endif

/***********************************************************************************************************************
 *  LinNm_MainFunction()
 **********************************************************************************************************************/
/* Service name        :        LinNm_MainFunction.
 * Description:        :        Main function of the LinNm which processes the algorithm described in document SWS LinNm.
 * Service ID[hex]     :        0x11
 * Sync/Async          :        None
 * Reentrancy          :        None
 * Parameters (in)     :        None
 * Parameters (inout)  :        None
 * Parameters (out)    :        None 
 * Return value        :        None
 **********************************************************************************************************************/

void LinNm_MainFunction( void )
{
  /*Empty Function*/
}


/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Mar/2020
By                : BPANDURA
Traceability      : RTC #  725516, 725520, 725525, 780723, 780719, 780721, 780734.
Change Description: Added version info Api for linNM and added vendorID, moduleID, sw_major_version, sw_minor_version, 
                    sw_patch_version
                    Added linNm_ConfigType structure for linNM state sleep and liNM sleep mode and added condition for
                    linNm_Init parameter to check invalid parameter and added condition while initalization by default
                    linNM state and mode selected as sleep state and mode.
                    Added E_NOT_OK in linNm_PassiveStartUp, if linNm_PassiveStartUp is called in network mode and return E_NOT_OK.
                    Added E_NOT_OK in linNm_NetworkRequest, if linNm_NetworkRequest is called in network mode and return E_NOT_OK.
                    Added E_NOT_OK innlinNm_NetworkRelease, if linNm_NetworkRelease is called in sleep mode and return E_NOT_OK
                    Added API as per specification document 4.2.2 linNm_RequestBusSynchronization, linNm_CheckRemoteSleepIndication
                    linNm_SetSleepReadyBit, linNm_DisableCommunication, linNm_EnableCommunication, linNm_SetUserData, linNm_GetUserData,
                    linNm_GetPduData, linNm_RepeatMessageRequest, linNm_GetNodeIdentifier, linNm_GetLocalNodeIdentifier, linNm_Transmit, 
                    linNm_TxConfirmation.
                    Added Condition Macros for all API.
                    Added header file as per LinNM specification document 4.2.2.
                    Added local variable stateChanged 
                    Added NM Call back functions to notify the state change to nm. 
                    Added new comment structure for all api's as per LinNM specification document 4.2.2.
                    Removed U unsigned in "LINNM_INSTANCE_ID".
----------------------------------------------------------------------------------------------------------------------*/




/*--------------------------------------------------------------------------------------------------------------------
Date              : 7/Oct/2019
By                : MKANNAN2
Traceability      : RTC # 1375069  
Change Description: Review comment fix - update @brief instead of /brief on comment block of function description.
                                       - Conditional compilation added to function "LinNm_PassiveStartUp".
                                       - Updated a config description on comment block of function LIN_NM network release 
                                         and request function.
                                       - Removed update of LINNM_BUSWAKEUP_NOTSUCCESS to LinNM_WakeUpNotify_Status on normal state 
                                         of function"LinNm_MainFunction" 
                                       - Removed update of LINNM_BUSSLEEP_NOTSUCCESS to LinNM_SleepNotify_Status on sleep state
                                         of function "LinNm_MainFunction".    
                                       - Configuration parameter added to function"LinNm_Init".  
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 6/Sep/2019
By                : ABAVALAT
Traceability      : RTC # 1352209  
Change Description: Changes done in LinNm_MainFunction for UnitTest Fix
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 5/Sep/2019
By                : MKANNAN2
Traceability      : RTC # 1365080  
Change Description: Added comment to all instruction, and update network request and release function.
                    Added LINNM Passive startup function. Moved constant variable from right to left in conditional statement.
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 11/August/2019
By                : MKANNAN2
Traceability      : RTC # 1368159  
Change Description: Remove compiler warning of LIN NM Module against DET configuration.
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC # 1345509  
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/

