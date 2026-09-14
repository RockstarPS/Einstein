/********************************************************************************************************************
|   File Name   : Nm_Cfg.c
|
|   Description : This file provides the link time configuration parameters for the AUTOSAR NM module 
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2019-12-05  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
/* Includes */
#include "Nm_Cfg.h"
#include "ComM.h"
#include "CanNm.h"
//#include "CanNmFiatB.h"

/*! @brief It defines the mapping between the ComM channel and NM channel */
const NetworkHandleType Nm_ComMToNmChannelMapping[NM_COMM_NUMBER_OF_CHANNELS]=
{
    /* ComM channel Id */ 
    0U,                     /* ComMChannel0 */
    1U                      /* ComMChannel1 */
};

/*! @brief It defines the channel configuration of NM */
const Nm_ChannelConfigType Nm_ChannelConfig[NM_NUMBER_OF_CHANNELS]=
{
    /* {BusNmFunctConfigId , BusNmType, ComMChRef} */
    {
        0U,
        NM_BUSNM_GENERICNM,
		0U // ComMConf_ComMChannel_BHCAN
    },
    {
        1U,
        NM_BUSNM_CANNM,
		1U // ComMConf_ComMChannel_FDCAN1
    }
};

/*! @brief It defines the supported function by the bus specific NM */ 
const Nm_BusNmFunctConfigType Nm_BusNmFunctConfig[NM_NUM_OF_BUS_NM_SUPPORTED]=
{
    /* {BusNmPassiveStartUpFunctPtr, BusNmGetStateFunctPtr, BusNmNetworkRequestFunctPtr, BusNmNetworkReleaseFunctPtr, 
    BusNmDisableCommunicationFunctPtr, BusNmEnableCommunicationFunctPtr, Nm_BusNmSetUserDataFunctType, 
    Nm_BusNmGetUserDataFunctType, Nm_BusNmGetNodeIdentifierFunctType, Nm_BusNmGetLocalNodeIdentifierFunctType, 
    Nm_BusNmGetPduDataFunctType, Nm_BusNmPduRxIndicationCallOutFunctType, 
    Nm_BusNmCheckRemoteSleepIndicationFunctType } */
    {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    },
    {
        CanNm_PassiveStartUp,
        CanNm_GetState,
        CanNm_NetworkRequest,
        CanNm_NetworkRelease,
        CanNm_DisableCommunication,
        CanNm_EnableCommunication,
        NULL_PTR,
        CanNm_GetNodeIdentifier,
        CanNm_GetLocalNodeIdentifier,
        CanNm_GetPduData,
        CanNmCallOut_PduRxIndication,
        CanNm_CheckRemoteSleepIndication,
    }
};
