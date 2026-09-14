/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file PduR.c
*    @ingroup PduR
*    @brief This file implements the AUTOSAR PduR module.The COM Module provides routing functionality.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Lcfg.h"
#include "PduR_Types.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#if !defined (PDUR_LOCAL) 
#define PDUR_LOCAL                               static
#endif

#if !defined (PDUR_LOCAL_INLINE)
#define PDUR_LOCAL_INLINE                        LOCAL_INLINE
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((PDUR_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
    (PDUR_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) || \
    (PDUR_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PDUR_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
/* Unsupported feature */
#if (PDUR_ZERO_COST_OPERATION  == STD_ON)
    #error " Zero cost operation is not supported in current version "
#endif
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service is used to notify the DET about the errors.
*   @param[in] ApiId API Id in which error occured
*   @param[in] ErrorId Id of the occured error
********************************************************************************************************************/
PDUR_LOCAL FUNC(void,PDUR_CODE) PduR_DetReportError(uint8 ApiId, uint8 ErrorId);
#endif
/*!******************************************************************************************************************
*   @brief     This service is used to handle the transmit request from upper layer to lower if layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration
*   @param[in] InfoPtr pointer to the received PduInfo 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpIfTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) InfoPtr
);
/*!******************************************************************************************************************
*   @brief     This service is used to handle the transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration
*   @param[in] InfoPtr pointer to the received PduInfo 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTpTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) InfoPtr
);
/*!******************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower interface layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpIfCancelTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr
);
/*!******************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTpCancelTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr
);
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
/*!******************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(boolean,PDUR_CODE) PduR_IsDestPduGroupEnabled(PduIdType PduId);
#endif
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define PDUR_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"

static PduR_StateType PduR_InitStatus = PDUR_UNINIT;

#define PDUR_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"

#define PDUR_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION			                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service initializes the PDU Router
*   @param[in]  ConfigPtr Pointer to post build configuration
*   @ServiceID  0xf0
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       To avoid problems calling the PDU Router module uninitialized it is important that the PDU Router 
*               module is initialized before interfaced modules.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType,AUTOMATIC,PDUR_APPL_CONST) ConfigPtr)
{
	uint8 ErrorId = PDUR_E_NO_ERROR;
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
	uint8 GroupIdx=0U;
#endif	
	if (PDUR_UNINIT != PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
	else
	{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
		/* Initialize the routing path group status to Init values */
		for (GroupIdx = 0; GroupIdx < PDUR_NUM_OF_ROUTING_PATH_GROUP; GroupIdx++)
		{
			PduR_RoutingPathGrpEnableSts[GroupIdx] = PduR_RpGroupInitStatus[GroupIdx];
		}
		#endif

		/* Set Init Status Variable */
		PduR_InitStatus = PDUR_ONLINE;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_INIT_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
	PDUR_DUMMY_STATEMENT(ConfigPtr);
}

#if (PDUR_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service Returns the version information of this module.
*   @param[out] versionInfo Pointer to where to store the version information of this module.
*   @ServiceID  0xf1
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,PDUR_APPL_DATA) versionInfo)

{
    /* Local Variables */
    uint8 ErrorId = PDUR_E_NO_ERROR;

    /* Check if Parameter VersionInfo is valid */
    if (NULL_PTR == versionInfo)
    {
        ErrorId = PDUR_E_PARAM_POINTER;
    }
    else
    {
        versionInfo->vendorID         = (uint16) PDUR_VENDOR_ID;
        versionInfo->moduleID         = (uint8)  PDUR_MODULE_ID;
        versionInfo->sw_major_version = (uint8)  PDUR_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)  PDUR_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)  PDUR_SW_PATCH_VERSION;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_GET_VERSION_INFO_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif

/********************************************************************************************************************
*   @brief      This service Returns the unique identifier of the post-build time configuration of the PDU Router
*   @return     PduR_PBConfigIdType Identifier of the post-build time configuration
*   @ServiceID  0xf2
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(PduR_PBConfigIdType,PDUR_CODE) PduR_GetConfigurationId(void)
{
	PduR_PBConfigIdType ConfigId=0U;
	uint8 ErrorId = PDUR_E_NO_ERROR;

	if (PDUR_ONLINE != PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
	else
	{
		ConfigId = (PduR_PBConfigIdType)PDUR_DEFAULT_CONFIGURATION_ID;
	}

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_GET_CONFIGURATION_ID_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    return ConfigId;
}

#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
/********************************************************************************************************************
*   @brief      This service Enables a routing path group.
*   @param[in]  id Identification of the routing path group. Routing path groups are defined in the PDU router
*               configuration.
*   @ServiceID  0xf3
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id)
{
    uint8 ErrorId = PDUR_E_NO_ERROR;

    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Id is valid */
    else if (PDUR_NUM_OF_ROUTING_PATH_GROUP <= id)
    {
        ErrorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
    }
#endif
    else
    {
        /* Enable Rpg status */
        PduR_RoutingPathGrpEnableSts[id] = TRUE;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if (PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_ENABLE_ROUTING_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service Disables a routing path group.
*   @param[in]  id Identification of the routing path group. Routing path groups are defined in the PDU router
*               configuration.
*   @param[in]  initialize true: initialize single buffers to the default value
*               false: retain current value of single buffers
*   @ServiceID  0xf4
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id,boolean initialize)
{
    uint8 ErrorId = PDUR_E_NO_ERROR;

    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Id is valid */
    else if (PDUR_NUM_OF_ROUTING_PATH_GROUP <= id)
    {
        ErrorId = PDUR_E_ROUTING_PATH_GROUP_ID_INVALID;
    }
#endif
    else
    {
        /* Disable Rpg status */
        PduR_RoutingPathGrpEnableSts[id] = FALSE;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if (PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_DISABLE_ROUTING_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    PDUR_DUMMY_STATEMENT(initialize);
}
#endif /* PDUR_ROUTING_PATH_GROUP == STD_ON */

/********************************************************************************************************************
*   @brief      This service Requests transmission of an I-PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted.
*   @param[in]  PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    /* Local Variables */
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = PDUR_E_NO_ERROR;
    P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check received Id is valid */
    else if (PDUR_NUM_OF_SRC_PDU <= TxPduId)
    {
        ErrorId = PDUR_E_PDU_ID_INVALID;
    }
    /* Check received PduInfoPtr is valid */
    else if (NULL_PTR == PduInfoPtr)
    {
        ErrorId = PDUR_E_PARAM_POINTER;
    }
#endif
    else
    {
    	/* Check for interface type - If layer or Tp layer */
    	/* Get Src Pdu Type */
    	pSourcePduCfg = &PduR_SourcePduCfg[TxPduId];
    	if (PDUR_PDU_TYPE_IF == pSourcePduCfg->PduType)
    	{
    		RetVal = PduR_UpIfTransmit(pSourcePduCfg,PduInfoPtr);
    	}
    	else
    	{
    		RetVal = PduR_UpTpTransmit(pSourcePduCfg,PduInfoPtr);
    	}
	}

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_UP_TRANSMIT_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication 
*               module.
*   @param[in]  TxPduId  Identification of the I-PDU to be cancelled.
*   @return     Std_ReturnType  status of the request
*               E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_UpCancelTransmit(PduIdType TxPduId)
{
    /* Local Variables */
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = PDUR_E_NO_ERROR;
    P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check received Id is valid */
    else if (PDUR_NUM_OF_SRC_PDU <= TxPduId)
    {
        ErrorId = PDUR_E_PDU_ID_INVALID;
    }
#endif
    else
    {
    	/* Check for interface type - If layer or Tp layer */
    	/* Get Src Pdu Type */
    	pSourcePduCfg = &PduR_SourcePduCfg[TxPduId];
    	if (PDUR_PDU_TYPE_IF == pSourcePduCfg->PduType)
    	{
    		RetVal = PduR_UpIfCancelTransmit(pSourcePduCfg);
    	}
    	else
    	{
    		RetVal = PduR_UpTpCancelTransmit(pSourcePduCfg);
    	}
	}

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_UP_CANCEL_TRANSMIT_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
*   @param[in]  id  Identifiaction of the I-PDU which the parameter change shall affect.
*   @param[in]  parameter The parameter that shall change
*   @param[in]  value  The new value of the parameter
*   @return     Std_ReturnType  status of the request
*               - E_OK : The parameter was changed successfully
*               - E_NOT_OK : The parameter change was rejected.
*   @ServiceID  0x4B
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_UpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    /* Local Variables */
	PduIdType PduId;
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = PDUR_E_NO_ERROR;
    P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
    P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
    P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check received Id is valid */
    else if (PDUR_NUM_OF_SRC_PDU <= id)
    {
        ErrorId = PDUR_E_PDU_ID_INVALID;
    }
#endif
    else
    {
    	/* Check for interface type - If layer or Tp layer */
    	/* Get Src Pdu Type */
    	pSourcePduCfg = &PduR_SourcePduCfg[id];
    	if (PDUR_PDU_TYPE_TP == pSourcePduCfg->PduType)
    	{
			for( PduId = pSourcePduCfg->DestStartPduId;
						 ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
			{
			#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
				if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
			#endif
				{
					pDestPduCfg = &PduR_DestPduCfg[PduId];
					/* get destination module */
					if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
					{
						pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
						/* get the Transmit interface from the dest module */
						if (NULL_PTR != pModuleConfig->LoTpChangeParameterFunctPtr)
						{
							/* Invoke destination transmit API */
							RetVal = pModuleConfig->LoTpChangeParameterFunctPtr(pDestPduCfg->ModuleDestPduId,
																				parameter, value);
						}
					}
				}
			}
    	}
	}

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_UP_CHANGE_PARAMETER_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
*               protocol module.
*   @param[in]  RxPduId  Identification of the PDU to be cancelled.
*   @return     Std_ReturnType  status of the request
*               - E_OK :  Cancellation was executed successfully by the destination module
*               - E_NOT_OK : Cancellation was rejected by the destination module
*   @ServiceID  0x4C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_UpCancelReceive(PduIdType RxPduId)
{
    /* Local Variables */
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = PDUR_E_NO_ERROR;
    P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
    P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
    P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
    PduIdType PduId;
    /* Check PduR Init Status */
    if (PDUR_UNINIT == PduR_InitStatus)
    {
        ErrorId = PDUR_E_UNINIT;
    }
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    /* Check received Id is valid */
    else if (PDUR_NUM_OF_SRC_PDU <= RxPduId)
    {
        ErrorId = PDUR_E_PDU_ID_INVALID;
    }
#endif
    else
    {
    	/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[RxPduId];
    	/* Check for interface type - If layer or Tp layer */
		if (PDUR_PDU_TYPE_TP == pSourcePduCfg->PduType)
		{
			for( PduId = pSourcePduCfg->DestStartPduId;
						 ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
			{
			#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
				if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
			#endif
				{
					pDestPduCfg = &PduR_DestPduCfg[PduId];
					/* get destination module */
					if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
					{
						pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
						/* get the Transmit interface from the dest module */
						if (NULL_PTR != pModuleConfig->LoTpCancelReceiveFunctPtr)
						{
							/* Invoke destination transmit API */
							RetVal = pModuleConfig->LoTpCancelReceiveFunctPtr(pDestPduCfg->ModuleDestPduId);
						}
					}
				}
			}
		}

	}

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
    if(PDUR_E_NO_ERROR != ErrorId)
    {
        PduR_DetReportError(PDUR_UP_CANCEL_RECEIVE_API, ErrorId);
    }
#else
    PDUR_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  RxPduId ID of the received PDU.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LoRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
	/* Local Variables */
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= RxPduId)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
	/* Check received PduInfoPtr is valid */
	else if (NULL_PTR == PduInfoPtr)
	{
		ErrorId = PDUR_E_PARAM_POINTER;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[RxPduId];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
					if (PUDR_PDU_DIRECTION_TRANSMIT == pDestPduCfg->PduDestDirection )
					{
						if (NULL_PTR != pModuleConfig->LoIfTransmitFunctPtr)
						{
							(void)pModuleConfig->LoIfTransmitFunctPtr(pDestPduCfg->ModuleDestPduId,PduInfoPtr);
						}
					}
					else
					{
						/* get the Transmit interface from the dest module */
						if (NULL_PTR != pModuleConfig->UpIfRxIndicationFunctPtr)
						{
							/* Invoke destination transmit API */
							pModuleConfig->UpIfRxIndicationFunctPtr(pDestPduCfg->ModuleDestPduId,PduInfoPtr);
						}
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}

	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_RX_INDICATION_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
}

/********************************************************************************************************************
*   @brief      The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*               transmit a PDU.
*   @param[in]  TxPduId ID of the PDU that has been transmitted.
*   @param[in]  result E_OK: The PDU was transmitted. E_NOT_OK: Transmission of the PDU failed.
*   @ServiceID  0x40
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LoTxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
	/* Local Variables */
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;

	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_DEST_PDU <= TxPduId)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
#endif
	else
	{
		pDestPduCfg = &PduR_DestPduCfg[TxPduId];
		/* get src pdu */
		if (PDUR_NUM_OF_SRC_PDU > pDestPduCfg->SrcPduId)
		{
			pSourcePduCfg = &PduR_SourcePduCfg[pDestPduCfg->SrcPduId];
			if (PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule)
			{
				pModuleConfig = &PduR_ModuleConfig[pSourcePduCfg->SrcModule];
				if (NULL_PTR != pModuleConfig->UpIfTxConfirmationFunctPtr)
				{
					pModuleConfig->UpIfTxConfirmationFunctPtr(pSourcePduCfg->ModuleSrcPduId,result);
				}
			}/*(PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule) */
		}/*(PDUR_NUM_OF_SRC_PDU > pDestPduCfg->SrcPduId)*/
	}

	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TX_CONFIRMATION_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
}

/********************************************************************************************************************
*   @brief      Within this API, the upper layer module (called module) shall check whether the available data fits 
*               into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
*               buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in 
*               PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*   @param[in]      TxPduId ID of the SDU that is requested to be transmitted.
*   @param[in,out]  PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied,  
*                   and the available buffer size in SduLengh. On return, the service will indicate the length of  
*                   the copied SDU data in SduLength.
*   @return         Std_ReturnType E_OK: SDU has been copied and SduLength indicates the number of copied bytes. 
*                   E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain a NULL
*                   pointer or point to invalid data.
*   @ServiceID      0x41
*   @Sync/Async     Synchronous 
*   @Reentrancy     Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_LoTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
)
{
	/* Local Variables */
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	Std_ReturnType RetVal = E_NOT_OK;

	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_DEST_PDU <= TxPduId)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
	/* Check received PduInfoPtr is valid */
	else if (NULL_PTR == PduInfoPtr)
	{
		ErrorId = PDUR_E_PARAM_POINTER;
	}
#endif
	else
	{
		pDestPduCfg = &PduR_DestPduCfg[TxPduId];
		/* get src pdu */
		if (PDUR_NUM_OF_SRC_PDU > pDestPduCfg->SrcPduId)
		{
			pSourcePduCfg = &PduR_SourcePduCfg[pDestPduCfg->SrcPduId];
			if (PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule)
			{
				pModuleConfig = &PduR_ModuleConfig[pSourcePduCfg->SrcModule];
				if (NULL_PTR != pModuleConfig->UpIfTriggerTransmitFunctPtr)
				{
					RetVal = pModuleConfig->UpIfTriggerTransmitFunctPtr(pSourcePduCfg->ModuleSrcPduId,PduInfoPtr);
				}
			}/*(PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule) */
		}/*(PDUR_NUM_OF_SRC_PDU > pDestPduCfg->SrcPduId)*/
	}

	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TRIGGER_TRANSMIT_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
	return RetVal;
}

/********************************************************************************************************************
*   @brief      This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
*               Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer 
*               is written to the position indicated by bufferSizePtr.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  info Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*               An SduLength of 0 can be used to query the current amount of available buffer in the upper layer 
*               module. In this case, the SduDataPtr may be a NULL_PTR.
*   @param[out] bufferSizePtr Available receive buffer after data has been copied.
*   @return     BufReq_ReturnType BUFREQ_OK: Data copied successfully 
*               BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*   @ServiceID  0x44
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id, 
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
)
{
	/* Local Variables */
	BufReq_ReturnType RetVal =  BUFREQ_E_NOT_OK;
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= id)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
	/* Check received PduInfoPtr is valid */
	else if (NULL_PTR == info)
	{
		ErrorId = PDUR_E_PARAM_POINTER;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[id];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];

					if (NULL_PTR != pModuleConfig->UpTpCopyRxDataFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->UpTpCopyRxDataFunctPtr(pDestPduCfg->ModuleDestPduId,info,
								                                       bufferSizePtr);
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}
	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TP_COPY_RX_DATA_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
	return RetVal;
}

/*******************************************************************************************************************
*   @brief      Called after an I-PDU has been received via the TP API, the result indicates whether the transmission 
*               was successful or not.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  result Result of the reception.
*   @return     BufReq_ReturnType BUFREQ_OK: Data copied successfully 
*               BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*   @ServiceID  0x45
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result)
{
	/* Local Variables */
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= id)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[id];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];

					if (NULL_PTR != pModuleConfig->UpTpRxIndicationFunctPtr)
					{
						/* Invoke destination transmit API */
						pModuleConfig->UpTpRxIndicationFunctPtr(pDestPduCfg->ModuleDestPduId,result);
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}


	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TP_RX_INDICATION_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
}

/********************************************************************************************************************
*   @brief      This service is called at the start of receiving an N-SDU. The N-SDU might be fragmented into 
*               multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF). 
*               The service shall provide the currently available maximum buffer size when invoked with TpSduLength 
*               equal to 0.
*   @param[in]  id Identification of the I-PDU.
*   @param[in]  info Pointer to a PduInfoType structure containing the payload data (without protocol information) 
*               and payload length of the first frame or single frame of a transport protocol I-PDU reception, and 
*               the MetaData related to this PDU. If neither first/single frame data nor MetaData are available, 
*               this parameter is set to NULL_PTR.
*   @param[in]  TpSduLength Total length of the N-SDU to be received.
*   @param[out] bufferSizePtr Available receive buffer in the receiving module. This parameter will be used to 
*               compute the Block Size (BS) in the transport protocol module.
*   @return     BufReq_ReturnType 
*               BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available receive buffer; 
*               reception is continued. If no buffer of the requested size is available, 
*               a receive buffer size of 0 shall be indicated by bufferSizePtr. 
*               BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged. 
*               BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. bufferSizePtr 
*               remains unchanged.
*   @ServiceID  0x46
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
)
{
	/* Local Variables */
	BufReq_ReturnType RetVal =  BUFREQ_E_NOT_OK;
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= id)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
	/* Check received PduInfoPtr is valid */
	else if (NULL_PTR == info)
	{
		ErrorId = PDUR_E_PARAM_POINTER;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[id];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];

					if (NULL_PTR != pModuleConfig->UpTpStartOfReceptionFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->UpTpStartOfReceptionFunctPtr(pDestPduCfg->ModuleDestPduId,info,
								                                              TpSduLength, bufferSizePtr);
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}

	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TP_START_OF_RECEPTION_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
	return RetVal;
}

/********************************************************************************************************************
*   @brief      This service is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
*               function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this 
*               case the function restarts to copy the data beginning at the offset from the current position 
*               indicated by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated 
*               by availableDataPtr.
*   @param[in]  id Identification of the transmitted I-PDU.
*   @param[in]  info Provides the destination buffer (SduDataPtr) and the number of bytes to be copied (SduLength). 
*               If not enough transmit data is available, no data is copied by the upper layer module and 
*               BUFREQ_E_BUSY is returned. The lower layer module may retry the call. An SduLength of 0 can be used 
*               to indicate state changes in the retry parameter or to query the current amount of available data 
*               in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR.
*   @param[in]  retry This parameter is used to acknowledge transmitted data or to retransmit data after 
*               transmission problems. If the retry parameter is a NULL_PTR, it indicates that the transmit data can
*               be removed from the buffer immediately after it has been copied. Otherwise, the retry parameter must 
*               point to a valid RetryInfoType element. If TpDataState indicates TP_CONFPENDING, the previously copied 
*               data must remain in the TP buffer to be available for error recovery. TP_DATACONF indicates that all 
*               data that has been copied before this call is confirmed and can be removed from the TP buffer. 
*               Data copied by this API call is excluded and will be confirmed later. TP_DATARETRY indicates that this 
*               API call shall copy previously copied data in order to recover from an error. In this case TxTpDataCnt 
*               specifies the offset in bytes from the current data copy position.
*   @param[out] availableDataPtr Indicates the remaining number of bytes that are available in the upper layer
*               module's Tx buffer. availableDataPtr can be used by TP modules that support dynamic payload lengths 
*               (e.g. FrIsoTp) to determine the size of the following CFs.
*   @return     BufReq_ReturnType BUFREQ_OK: Data has been copied to the transmit buffer completely as requested. 
*               BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available.
*               The lower layer module may retry this call later on. No data has been copied. 
*               BUFREQ_E_NOT_OK: Data has not been copied. Request failed..
*   @ServiceID  0x43
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(RetryInfoType,AUTOMATIC,PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) availableDataPtr
)
{
	/* Local Variables */
	BufReq_ReturnType RetVal =  BUFREQ_E_NOT_OK;
	uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= id)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
	/* Check received PduInfoPtr is valid */
	else if (NULL_PTR == info)
	{
		ErrorId = PDUR_E_PARAM_POINTER;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[id];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get src module */
				if (PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule)
				{
					pModuleConfig = &PduR_ModuleConfig[pSourcePduCfg->SrcModule];

					if (NULL_PTR != pModuleConfig->UpTpCopyTxDataFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->UpTpCopyTxDataFunctPtr(pDestPduCfg->ModuleDestPduId,info,
																		retry,availableDataPtr);
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}

	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TP_COPY_TX_DATA_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
	    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service is called after the I-PDU has been transmitted on its network, the result indicates 
*               whether the transmission was successful or not.
*   @param[in]  id dentification of the transmitted I-PDU.
*   @param[in]  result Result of the transmission of the I-PDU.
*   @ServiceID  0x48
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
	/* Local Variables */uint8 ErrorId = PDUR_E_NO_ERROR;
	P2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) pSourcePduCfg;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	PduIdType PduId;
	/* Check PduR Init Status */
	if (PDUR_UNINIT == PduR_InitStatus)
	{
		ErrorId = PDUR_E_UNINIT;
	}
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	/* Check received Id is valid */
	else if (PDUR_NUM_OF_SRC_PDU <= id)
	{
		ErrorId = PDUR_E_PDU_ID_INVALID;
	}
#endif
	else
	{
		/* Check for interface type - If layer or Tp layer */
		/* Get Src Pdu Type */
		pSourcePduCfg = &PduR_SourcePduCfg[id];
		for( PduId = pSourcePduCfg->DestStartPduId;
            ((PduId <= pSourcePduCfg->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
		#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
		#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get source module */
				if (PDUR_NUM_OF_MODULE_ID > pSourcePduCfg->SrcModule)
				{
					pModuleConfig = &PduR_ModuleConfig[pSourcePduCfg->SrcModule];

					if (NULL_PTR != pModuleConfig->UpTpTxConfirmationFunctPtr)
					{
						/* Invoke destination transmit API */
						pModuleConfig->UpTpTxConfirmationFunctPtr(pDestPduCfg->ModuleDestPduId,result);
					}
				}/* PDUR_NUM_OF_MODULE_ID != pDestPduCfg->DestModuleId */
			} /* FALSE != PduR_IsDestPduGroupEnabled(PduId) */
		} /* dest loop */
	}



	#if (PDUR_DEV_ERROR_DETECT == STD_ON)
	if(PDUR_E_NO_ERROR != ErrorId)
	{
		PduR_DetReportError(PDUR_LO_TP_TX_CONFIRMATION_API, ErrorId);
	}
	#else
	PDUR_DUMMY_STATEMENT(ErrorId);
	#endif
}

/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION			                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief     This service is used to handle the transmit request from upper layer to lower if layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration
*   @param[in] InfoPtr pointer to the received PduInfo 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpIfTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) InfoPtr
)
{
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	Std_ReturnType RetVal = E_NOT_OK;
	PduIdType PduId;

	if (NULL_PTR != PduRSourcePduCfgPtr)
	{
		for( PduId = PduRSourcePduCfgPtr->DestStartPduId;
			 ((PduId <= PduRSourcePduCfgPtr->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
					/* get the Transmit interface from the dest module */
					if (NULL_PTR != pModuleConfig->LoIfTransmitFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->LoIfTransmitFunctPtr(pDestPduCfg->ModuleDestPduId ,InfoPtr);
					}
				}
			}
		}

	}
	return RetVal;
}

/********************************************************************************************************************
*   @brief     This service is used to handle the transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration
*   @param[in] InfoPtr pointer to the received PduInfo 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTpTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) InfoPtr
)
{
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	Std_ReturnType RetVal = E_NOT_OK;
	PduIdType PduId;

	if (NULL_PTR != PduRSourcePduCfgPtr)
	{
		for( PduId = PduRSourcePduCfgPtr->DestStartPduId;
			 ((PduId <= PduRSourcePduCfgPtr->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
					/* get the Transmit interface from the dest module */
					if (NULL_PTR != pModuleConfig->LoTpTransmitFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->LoTpTransmitFunctPtr(pDestPduCfg->ModuleDestPduId ,InfoPtr);
					}
				}
			}
		}

	}
	return RetVal;
}

/********************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower interface layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpIfCancelTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr
)
{
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	Std_ReturnType RetVal = E_NOT_OK;
	PduIdType PduId;

	if (NULL_PTR != PduRSourcePduCfgPtr)
	{
		for( PduId = PduRSourcePduCfgPtr->DestStartPduId;
			 ((PduId <= PduRSourcePduCfgPtr->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
					/* get the Transmit interface from the dest module */
					if (NULL_PTR != pModuleConfig->LoIfCancelTransmitFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->LoIfCancelTransmitFunctPtr(pDestPduCfg->ModuleDestPduId);
					}
				}
			}
		}

	}
	return RetVal;
}

/********************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTpCancelTransmit
(
    CONSTP2CONST(PduR_SourcePduCfgType,AUTOMATIC,PDUR_APPL_CONST) PduRSourcePduCfgPtr
)
{
	P2CONST(PduR_ModuleConfigType,AUTOMATIC,PDUR_APPL_CONST) pModuleConfig;
	P2CONST(PduR_DestPduCfgType,AUTOMATIC,PDUR_APPL_CONST) pDestPduCfg;
	Std_ReturnType RetVal = E_NOT_OK;
	PduIdType PduId;

	if (NULL_PTR != PduRSourcePduCfgPtr)
	{
		for( PduId = PduRSourcePduCfgPtr->DestStartPduId;
			 ((PduId <= PduRSourcePduCfgPtr->DestEndPduId) && (PduId<PDUR_NUM_OF_DEST_PDU));PduId++)
		{
#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
			if(FALSE != PduR_IsDestPduGroupEnabled(PduId))
#endif
			{
				pDestPduCfg = &PduR_DestPduCfg[PduId];
				/* get destination module */
				if (PDUR_NUM_OF_MODULE_ID > pDestPduCfg->DestModuleId)
				{
					pModuleConfig = &PduR_ModuleConfig[pDestPduCfg->DestModuleId];
					/* get the Transmit interface from the dest module */
					if (NULL_PTR != pModuleConfig->LoTpCancelTransmitFunctPtr)
					{
						/* Invoke destination transmit API */
						RetVal = pModuleConfig->LoTpCancelTransmitFunctPtr(pDestPduCfg->ModuleDestPduId);
					}
				}
			}
		}

	}
	return RetVal;
}


#if (STD_ON == PDUR_ROUTING_PATH_GROUP)
/********************************************************************************************************************
*   @brief     This service is used to handle the cancel transmit request from upper layer to lower transport layer.
*   @param[in] PduRSourcePduCfgPtr pointer to the source pdu configuration 
*   @return    Std_ReturnType return status of the request
********************************************************************************************************************/
PDUR_LOCAL FUNC(boolean,PDUR_CODE) PduR_IsDestPduGroupEnabled(PduIdType PduId)
{
	return FALSE;
}
#endif


#if (PDUR_DEV_ERROR_DETECT == STD_ON)
/********************************************************************************************************************
*   @brief     This service is used to notify the DET about the errors.
*   @param[in] ApiId API Id in which error occured
*   @param[in] ErrorId Id of the occured error
********************************************************************************************************************/
PDUR_LOCAL FUNC(void,PDUR_CODE) PduR_DetReportError(uint8 ApiId, uint8 ErrorId)
{
    /* Development Error Report */
    (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, ApiId, ErrorId);
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    14-JUL-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - PduR AUTOSAR 4.3 version initial implementation
*******************************************************************************************************************/

