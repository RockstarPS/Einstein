
/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 * File:         LinNm.h
 * Component:    LIN Network Management
 * Module:       LIN
 * Platforms :   This layer is Micro and Hardware agnostic & hence it satisfies the below requirement it
                 [SWS_LinNm_00026] The AUTOSAR LinNm state machine shall be processor independent, which means
                 shall  not rely on any processor specific hardware support and thus shall be realizable on any
                 processor architecture that is in the scope of AUTOSAR.
 * Description:  Header of LIN Network Management
 *********************************************************************************************************************/


#if !defined (LINNM_H)
# define LINNM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/                                                            

#include "LinNm_Cfg.h"
 /*check whether nm callback parameter is enabled or not*/
#if ( LINNM_NM_CBK_SUPPORT == STD_ON )
# include "NmStack_Types.h"
#endif
  
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Component version information (decimal version of ALM implementation package) */
# define LINNM_SW_MAJOR_VERSION                     (1u)
# define LINNM_SW_MINOR_VERSION                     (0u)
# define LINNM_SW_PATCH_VERSION                     (0u)

/* Vendor and module identification */
# define LINNM_VENDOR_ID                            (0u)
# define LINNM_MODULE_ID                            (0u)
/** @name Service id's */

/* Autosar Release */
/*! Defines the AUTOSAR LinNm Release major version */
#define LINNM_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR LinNm Release major version */
#define LINNM_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR LinNm Release patch version */
#define LINNM_AR_RELEASE_REVISION_VERSION             1U

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*@brief, This macro defines Error code for No error Occurrence 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
*/
# define LINNM_E_NO_ERROR                           0x00U 

/* @brief,This macro defines Error code for API service used without module initialization
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
 */
# define LINNM_E_NO_INIT                            0x01U 

/* @brief,This macro defines Error code for API service used with wrong channel handle
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
 */
# define LINNM_E_INVALID_CHANNEL                    0x02U 


/* @brief,This macro defines Error code for API service used with null pointer argument
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
 */
# define LINNM_E_PARAM_POINTER                      0x12U 


/* @brief,This macro defines Error code for initialization failed selected configuration set doesn't exist.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
*/

# define LINNM_E_INIT_FAILED                        0x13U 

/* @brief,This macro defines Error code for API service call with invalid Parameter
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
*/

# define LINNM_E_INVALID_PARAMETER                  0x14U 


/*@brief,This macro is used for state change notification*/
#define STATE_CHANGE_ENABLE      1u

/*@brief,This macro is used for state change notification*/
#define STATE_CHANGE_DISABLE     0u

/*@brief,This macro value should not be changed, statement to check mode and state are changed*/
#define LINNM_NM_NOTIFICATION_IND                                       STATE_CHANGE_ENABLE


/* ----- API service IDs ----- */
/* @brief,This macro defines service id of API - LinNm_Init() 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_INIT_ID                          0x00U 

/* @brief,This macro defines service id of API - LinNm_PassiveStartUp() 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_PASSIVESTARTUP                   0x01U 

/* @brief,This macro defines service id of API - LinNm_NetworkRequest()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_NETWORKREQUEST                   0x02U 

/* @brief,This macro defines service id of API - LinNm_NetworkRelease()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_NETWORKRELEASE                   0x03U 

/* @brief,This macro defines service id of API - LinNm_GetVersionInfo()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETVERSIONINFO                   0xF1U 

/* @brief,This macro defines service id of API - LinNm_RequestBusSynchronization()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_REQUESTBUSSYNCHRONIZATION        0xC0U

/* @brief,This macro defines service id of API - LinNm_CheckRemoteSleepIndication()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_CHECKREMOTESLEEPIND              0xD0U 

/* @brief,This macro defines service id of API - LinNm_SetSleepReadyBit()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_SETSLEEPREADYBIT                 0x10U 

/* @brief,This macro defines service id of API - LinNm_DisableCommunication()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_DISABLECOMMUNICATION             0x04U 

/* @brief,This macro defines service id of API -LinNm_EnableCommunication()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_ENABLECOMMUNICATION              0x05U 

/* @brief,This macro defines service id of API - LinNm_SetUserData()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_SETUSERDATA                      0x06U 

/* @brief,This macro defines service id of API - LinNm_GetUserData()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETUSERDATA                      0x07U 

/* @brief,This macro defines service id of API - LinNm_GetPduData()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETPDUDATA                       0x08U 

/* @brief,This macro defines service id of API - LinNm_RepeatMessageRequest()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_REPEATMESSAGEREQUEST             0x09U 

/* @brief,This macro defines service id of API - LinNm_GetNodeIdentifier()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETNODEIDENTIFIER                0x0AU 

/* @brief,This macro defines service id of API - LinNm_GetLocalNodeIdentifier()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETLOCALNODEIDENTIFIER           0x0BU 

/* @brief,This macro defines service id of API - LinNm_GetState()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_GETSTATE                         0x0EU 

/* @brief,This macro defines service id of API - LinNm_Transmit()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_TRANSMIT                         0x0FU 

/* @brief,This macro defines service id of API - LinNm_TxConfirmation()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_TXCONFIRMATION                   0x40U 

/* @brief,This macro defines service id of API - LinNm_MainFunction()
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable */ 
# define LINNM_SID_MainFunction                     0x11U 

/*@brief This data type used to define bus configurations of LIN Network management 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
*/
typedef struct {
    /*configuration structure declared for linnm state and mode*/
        Nm_StateType LinNm_State;
        Nm_ModeType LinNm_Mode;
}LinNm_ConfigType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

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
void LinNm_InitMemory( void );

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
void LinNm_Init( const LinNm_ConfigType* ConfigPtr );

# if ( LINNM_PASSIVE_MODE_ENABLED == STD_ON )
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
Std_ReturnType LinNm_PassiveStartUp( NetworkHandleType nmChannelHandle );
# endif

# if ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF )
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
 Std_ReturnType LinNm_NetworkRequest( NetworkHandleType nmChannelHandle );

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
Std_ReturnType LinNm_NetworkRelease(  NetworkHandleType nmChannelHandle );
# endif


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
void LinNm_GetVersionInfo( Std_VersionInfoType* versioninfo );


#if ( LINNM_PASSIVE_MODE_ENABLED == STD_OFF ) && ( LINNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON )
/***********************************************************************************************************************
 *  LinNm_RequestBusSynchronization()
 **********************************************************************************************************************/
/* Service name        :          LinNm_RequestBusSynchronization.
 * Description:        :          Empty function to be complaint with NM specifications. Request bus synchronization.
 * Service ID[hex]     :          0xc0
 * Sync/Async          :          Asynchronous
 * Reentrancy          :          Non Reentrant
 * Parameters (in)     :          nmChannelHandle - Identification of the NM-channel
 * Parameters (inout)  :          None
 * Parameters (out)    :          None
 * Return value        :          Std_ReturnType
 *                                E_OK : No error
 **********************************************************************************************************************/
Std_ReturnType LinNm_RequestBusSynchronization( NetworkHandleType nmChannelHandle);
#endif


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

Std_ReturnType LinNm_CheckRemoteSleepIndication( NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr );
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

Std_ReturnType LinNm_SetSleepReadyBit( NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit );
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

Std_ReturnType LinNm_DisableCommunication( NetworkHandleType networkHandle );

/***********************************************************************************************************************
 *  LinNm_EnableCommunication()
 **********************************************************************************************************************/
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

Std_ReturnType LinNm_EnableCommunication( NetworkHandleType networkHandle );
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

Std_ReturnType LinNm_SetUserData( NetworkHandleType networkHandle, const uint8* nmUserDataPtr );
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

Std_ReturnType LinNm_GetUserData( NetworkHandleType networkHandle, uint8* nmUserDataPtr );
#endif

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

Std_ReturnType LinNm_GetPduData( NetworkHandleType networkHandle, uint8* nmPduData );
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

Std_ReturnType LinNm_RepeatMessageRequest( NetworkHandleType networkHandle );
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

Std_ReturnType LinNm_GetNodeIdentifier( NetworkHandleType networkHandle, uint8* nmNodeIdPtr );

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

Std_ReturnType LinNm_GetLocalNodeIdentifier( NetworkHandleType networkHandle, uint8* nmNodeIdPtr );
#endif 

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
                                                   Nm_ModeType* nmModePtr );

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

Std_ReturnType LinNm_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr );
#endif


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
void LinNm_TxConfirmation(PduIdType TxPduId);




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
void LinNm_MainFunction( void );


#endif  /* LINNM_H */

/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Mar/2020
By                : BPANDURA
Traceability      : RTC # 725516, 725520, 725525, 780723, 780719, 780721, 780734.  
Change Description: Removed linNM_types.h header file.
                    Changed sid for lin sid transmit
                    Added nmstatetype and nmmodetype enum.\
                    Added linNm_ConfigType structure.
                    Added Conditional Macro for linNM API declaration
                    Added new comment structure for all api's as per LinNM specification document 4.2.2.
----------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Oct/2019
By                : MKANNAN2
Traceability      : RTC # 1375069  
Change Description: - Update @brief instead of /brief on comment block of function description.
                    - Configuration parameter added to function"LinNm_Init". 
                    - Updated a config description on comment block of function LIN_NM network release 
                      and request function.
                    - Conditional compilation added to function "LinNm_PassiveStartUp". 
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 5/Sep/2019
By                : MKANNAN2
Traceability      : RTC # 1365080  
Change Description: Update LINNM initialization function declaration, and Update LINNM main function service ID.
                    Removed function "LinNM_WakeUp_Confirmation" and LinNM_Sleep_Confirmation.
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC # 1348466
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
 *  END OF FILE: LinNm.h
 *********************************************************************************************************************/
