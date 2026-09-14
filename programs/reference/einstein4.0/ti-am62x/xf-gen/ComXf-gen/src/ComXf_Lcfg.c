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
*    @file ComXf_Lcfg.c
*    @ingroup ComXfConfiguration
*    @brief This is ComXf Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the ComXf module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComXf.h"
#include "ComXf_Lcfg.h"
#include "ComXf_Int.h"
#include "Rte_Type.h"
#define COMXF_SEC_CODE_START
#define COMXF_CORE_CONST_SEC_START
#define COMXF_CORE_DATA_SEC_START
#define COMXF_CORE_BSS_SEC_START
#include "MemMap.h"
/********************************************************************************************************************
* #! PRIVATE MACRO DEFINITIONS                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
* #! PRIVATE TYPE DEFINITIONS                                                                                       *
********************************************************************************************************************/

/********************************************************************************************************************
* #! PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
* #! PRIVATE FUNCTION PROTOTYPES                                                                                    *
********************************************************************************************************************/

/********************************************************************************************************************
* #! PUBLIC VARIABLES                                                                                               *
********************************************************************************************************************/
/* @brief This variable used to indicate the current ComXf initialization status */
ComXf_InitStatusType ComXf_InitStatus = COMXF_STATUS_UNINIT;
/********************************************************************************************************************
* #! ComXf const config  data                                                                                    *
********************************************************************************************************************/
/* @brief This defines the signal configuration used by the ComXf 
SignalType              :   Defines the AUTOSAR type of the signal 
SignalEndiannessType    :   Defines the endianness of the signal's network representation
MsBitPosition           :   Defines the MS Bit position in the I-PDU data MsBytePosition
LsBitPosition           :   Defines the LS Bit position in the I-PDU data LsBytePosition
MsBytePosition          :   Defines the MS Byte position in the I-PDU data bytes
LsBytePosition          :   Defines the LS Byte position in the I-PDU data bytes
BitSize                 :   Defines the Size in bits, for integer signal types
ByteLength              :   Defines the Size in bytes
*/
const ComXf_SignalConfigType ComXf_SignalConfig[ComXf_Num_Of_Signals] =
    {
        {COMXF_SIGNALTYPE_UINT8, COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN, 1U, 0U, 1U, 1U, 2U, 1U},     /* Airbag_256 VehicleControl */
        {COMXF_SIGNALTYPE_UINT8, COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN, 3U, 0U, 5U, 5U, 4U, 1U},     /* Alive Counter signal update */
        {COMXF_SIGNALTYPE_UINT8, COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN, 7U, 0U, 6U, 6U, 8U, 1U},     /* CRC signal update*/
        {COMXF_SIGNALTYPE_UINT16, COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN, 7U, 0U, 3U, 4U, 16U, 2U}, /* VehicleSpeedABS_256 VehicleControl */
        {COMXF_SIGNALTYPE_UINT8, COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN, 7U, 0U, 0U, 0U, 8U, 1U},     /* Battery_Voltage signal update */

};
/********************************************************************************************************************
* #! ComXf Public API                                                                                            *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*   @brief  This function is used to initialize local status of ComXf
********************************************************************************************************************/
FUNC(void,COMXF_CODE) ComXf_LocalInit(void)
{

}

/* #! ComXf Inv transformer for sender receiver interface */
/*!******************************************************************************************************************
*   @brief  This function deserializes a Sender/Receiver communication using the deserialization of COM Based 
*   Transformer. It takes the uint8 array containing the serialized data as input and outputs the original data 
*   element which will be passed to the Rte.
********************************************************************************************************************/
FUNC(uint8, COMXF_CODE) ComXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS
( 
    P2CONST(uint8,AUTOMATIC,COMXF_APPL_CONST) buffer, 
    uint32 bufferLength,
    P2VAR(SG_ABS,AUTOMATIC,COMXF_APPL_VAR) dataElement
)
{
    uint8 RetVal = E_OK;
    uint8 ErrorId = COMXF_E_NO_ERROR;
    
    if (ComXf_InitStatus == COMXF_STATUS_UNINIT)
    {
        ErrorId = COMXF_E_UNINIT;
        RetVal = E_SER_GENERIC_ERROR;
    }
    else if ((buffer == NULL_PTR) && (bufferLength == 0U))
    {
        RetVal = E_NO_DATA;
    }
    else if ((buffer == NULL_PTR) || (bufferLength == 0U) || (dataElement == NULL_PTR))
    {   
        RetVal = E_SER_GENERIC_ERROR;
    }
    else
    {
        ComXf_ReadSignalFromBuffer(COMXf_SIGNAL_AIRBAG_ABS_258_CAN0_RX, &dataElement->Airbag,buffer,bufferLength,0U);
        ComXf_ReadSignalFromBuffer(COMXf_SIGNAL_ALIVE_101_CAN0_RX,&dataElement->Alive_101,buffer,bufferLength,0U);
        ComXf_ReadSignalFromBuffer(COMXf_SIGNAL_CRC_101_CAN0_RX,&dataElement->CRC_101,buffer,bufferLength,0U);
        ComXf_ReadSignalFromBuffer(COMXf_SIGNAL_VEHICLESPEEDABS_ABS_258_CAN0_RX,&dataElement->VehicleSpeedABS,buffer,bufferLength,0U);
    }
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
    if (COMXF_E_NO_ERROR != ErrorId)
    {
        ComXf_DetReportError(COMXF_TRANSFORMER_API, ErrorId);
    }
#else
    COMXF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
FUNC(uint8, COMXF_CODE) ComXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS
(
    P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer,
    P2VAR(uint16, AUTOMATIC, COMXF_APPL_VAR) bufferLength,
    P2CONST(SG_COM_HS, AUTOMATIC, COMXF_APPL_CONST) dataElement
)
{
    uint8 RetVal = E_OK;

    if (ComXf_InitStatus == COMXF_STATUS_UNINIT)
    {
        RetVal = E_SER_GENERIC_ERROR;
    }
    else if ((buffer == NULL_PTR) && (bufferLength == NULL_PTR))
    {
        RetVal = E_NO_DATA;
    }
    else if ((buffer == NULL_PTR) || (bufferLength == NULL_PTR) || (dataElement == NULL_PTR))
    {
        RetVal = E_SER_GENERIC_ERROR;
    }
    else
    {
        ComXf_WriteSignalToBuffer(COMXf_SIGNAL_COM_HS_BATTERY_VOLTAGE_CAN0_TX, &dataElement->Battery_Voltage, buffer, bufferLength, 0U);
    }

    return RetVal;
}
#define COMXF_SEC_CODE_STOP
#define COMXF_CORE_CONST_SEC_END
#define COMXF_CORE_DATA_SEC_END
#define COMXF_CORE_BSS_SEC_END

#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
