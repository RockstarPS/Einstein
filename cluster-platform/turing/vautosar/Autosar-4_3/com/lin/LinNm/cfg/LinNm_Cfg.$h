#if !defined(LINNM_CFG_H)
#define LINNM_CFG_H


/* ===========================================================================
**
**  File Name:     LinNm_Cfg.h
**  Component:     LIN Network Management    
**  Module:        LIN 
**  Platforms :    This layer is Micro and Hardware agnostic & hence it satisfies the below requirement it
                   [SWS_LinNm_00026] The AUTOSAR LinNm state machine shall be processor independent, which means
                   shall  not rely on any processor specific hardware support and thus shall be realizable on any
                   processor architecture that is in the scope of AUTOSAR.
**  Description:   This file describe a features used in LIN NM Module.
**
**  =========================================================================*/
# include "ComStack_Types.h"  



/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the support of the Passive Mode of the LinNm.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_PASSIVE_MODE_ENABLED                                      STD_OFF

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the Node Detection feature.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_NODE_DETECTION_ENABLED                                    STD_OFF  

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the  User Data support.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_USER_DATA_ENABLED                                         STD_OFF   

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the transmission of the source node identifier
 in NM messages.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_NODE_ID_ENABLED                                           STD_OFF 


/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the Communication Control support.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_COM_CONTROL_ENABLED                                       STD_OFF  

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the Network Management state change notification.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_STATE_CHANGE_IND_ENABLED                                  STD_OFF

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) Remote Sleep Indication support.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */  
#define LINNM_REMOTE_SLEEP_INDICATION_ENABLED                           STD_OFF  


/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the bus synchronization support of the LinNm.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_BUS_SYNCHRONIZATION_ENABLED                               STD_OFF 


/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the coordinator synchronization support.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_COORDINATOR_SYNC_SUPPORT                                  STD_OFF 

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the development error detection  on or off.

    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_DEV_ERROR_DETECT                                          STD_ON  


/*@brief As per specification 4.2.2 document [SWS_LinNm_00140] The parameter linnm synchronizationpoint enabled shall be always in disable.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_SYNCHRONIZATIONPOINT_ENABLED                             STD_OFF  

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the version info API support.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_VERSION_INFO_API                                          STD_ON


/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the Network handle reference feature.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_COMM_NETWORK_HANDLE_REF                                   STD_OFF 


/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the development error notification on or off.
  
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_COM_USER_DATA_SUPPORT                                     STD_OFF

/*@brief this macro is used for STD_ON(enable)/STD_OFF(disbale) the header files for NM call back functions.

    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_NM_CBK_SUPPORT                                            STD_OFF


/*@brief this macro is used for ENABLE the header files for NM call back functions.

    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */

#define TX_CONFIRMATION_ENABLE                                            STD_OFF

/*********************************************************************************************************************
*                                 #! LinNm SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the LinNm configuration software Major version */
#define LINNM_CFG_SW_MAJOR_VERSION                    	   1u
/*! @brief Defines the LinNm configuration software Minor version */
#define LINNM_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the LinNm configuration software Patch version */
#define LINNM_CFG_SW_PATCH_VERSION                          0u

/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by LinNm configuration  */
#define LINNM_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by LinNm configuration  */
#define LINNM_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by LinNm configuration  */
#define LINNM_CFG_AR_RELEASE_REVISION_VERSION               1u

/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Mar/2020
By                : BPANDURA
Traceability      : RTC # 725516, 725520, 725525, 780723, 780719, 780721, 780734.
Change Description: Created "LINNM_NM_CBK_SUPPORT" conditional macro to support NM header files for NM callback functions.
                    Added "LINNM_COM_USER_DATA_SUPPORT".
----------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC # 1348466
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 26/July/2019
By                : MKANNAN2
Traceability      : RTC # 1351938
Change Description: Added Comment to All instruction.
----------------------------------------------------------------------------------------------------------------------*/


#endif

