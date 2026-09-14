/********************************************************************************************************************
|    File Name: PduR_Dcm.h
|
|  Description: Implementation of the AUTOSAR PduR DCM Interface
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
| 2020-03-19  00.00.03  MA     Can TP implementation Added
| 2020-01-30  00.00.02  MA     Review Comments fixed (Task 1394508)
| 2019-12-16  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef PDUR_DCM_H
#define PDUR_DCM_H

/*******************************************************************************************************************/
/*  PduR and Dcm Interface APIs                                                                                    */
/*******************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service Requests transmission of an I-PDU. 
*   @param[in]  id  Identification of the I-PDU. 
*   @param[in]  info   Length and pointer to the buffer of the I-PDU. 
*   @return     Std_ReturnType  status of the request
*               - E_OK :request is accepted by the destination module; transmission is continued. 
*               - E_NOT_OK :request is not accepted by the destination module; transmission is aborted.     
*   @ServiceID  0x99
*   @Sync/Async ASynchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
Std_ReturnType PduR_DcmTransmit(PduIdType Id, const PduInfoType* Info);
/*!******************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing transmission of an I-PDU in a lower layer 
*   communication interface or transport protocol module. 
*   @param[in]  id  Identification of the I-PDU to be cancelled. 
*   @return     Std_ReturnType  status of the request
*               - E_OK : Cancellation was executed successfully by the destination module 
*               - E_NOT_OK : Cancellation was rejected by the destination module  
*   @ServiceID  0x9A
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType PduR_DcmCancelTransmit(PduIdType Id);
/*!******************************************************************************************************************
*   @brief      This service Request to change a specific transport protocol parameter (e.g. block size).  
*   @param[in]  id  Identifiaction of the I-PDU which the parameter change shall affect. 
*   @param[in]  parameter The parameter that shall change
*   @param[in]  value  The new value of the parameter 
*   @return     Std_ReturnType  status of the request
*               - E_OK : The parameter was changed successfully
*               - E_NOT_OK : The parameter change was rejected. 
*   @ServiceID  0x9B
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType PduR_DcmChangeParameter(PduIdType Id, TPParameterType Parameter, uint16 Value);
/*!******************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport 
*   protocol module.
*   @param[in]  id  Identifiaction of the I-PDU which the parameter change shall affect. 
*   @param[in]  parameter The parameter that shall change
*   @param[in]  value  The new value of the parameter 
*   @return     Std_ReturnType  status of the request
*               - E_OK :  Cancellation was executed successfully by the destination module
*               - E_NOT_OK : Cancellation was rejected by the destination module
*   @ServiceID  0x9C
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType PduR_DcmCancelReceive(PduIdType Id);

#endif /* PDUR_DCM_H */
