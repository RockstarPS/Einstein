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
*    @file DoIP_Externals.h
*    @ingroup DoIPConfiguration
*    @brief This is DoIP external header file. It contains definitions of external function prototype to be used by
*    the DoIP module.
********************************************************************************************************************/
#ifndef DOIP_EXTERNALS_H
#define DOIP_EXTERNALS_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP_Types.h"
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
* @brief This api is used to get the further action bytes from the app
* @param[in]  FurtherActionByte pointer to the further action buffer
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType DoIPApp_UserGetFurtherActionByte
(
    P2VAR(DoIP_FurtherActionByteType,AUTOMATIC,DOIP_APPL_DATA) FurtherActionByte
);
/*!******************************************************************************************************************
* @brief This api is used to get the group id from the app
* @param[in]  GroupId pointer to the Group Id buffer
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType DoIPApp_UserGetGidCallback(P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) GroupId);
/*!******************************************************************************************************************
* @brief This api is used to get the Vin from the app
* @param[in]  FurtherActionByte pointer to the Vin buffer
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType DoIPApp_UserGetVinCallback(P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) Vin);
/*!******************************************************************************************************************
* @brief This api is used to trigger the GID sync to the App
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted 
********************************************************************************************************************/
Std_ReturnType DoIPApp_UserTriggerGidSyncCallback( void );
/*!******************************************************************************************************************
* @brief This api is used to get the power state from the app
* @param[in]  PowerStateReady pointer to the power state buffer
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType DoIpApp_UserGetPowerModeCallback(P2VAR(DoIP_PowerStateType,AUTOMATIC,DOIP_APPL_DATA) PowerStateReady);
/*!******************************************************************************************************************
* @brief This api is used to get the payload data from the app
* @param[in] RxHeaderType the rx header type
* @param[in] RxPduInfo pointer to the rx pdu info
* @param[in] PayloadType the payload type
* @param[out] TxHeaderType the pointer to the tx header type
* @param[out] TxPduInfo the pointer to the tx pdu info
* @return  request status E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType DoIPApp_UserGetPayloadCallbackFn
(
    uint16 RxHeaderType,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) RxPduInfo,
    uint8 PayloadType,
    P2VAR(uint16,AUTOMATIC,DOIP_APPL_VAR) TxHeaderType,
    P2VAR(PduInfoType,AUTOMATIC,DOIP_APPL_VAR) TxPduInfo
);

#endif /* DOIP_EXTERNALS_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

