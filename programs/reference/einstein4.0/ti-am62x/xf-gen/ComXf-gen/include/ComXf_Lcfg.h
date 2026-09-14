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
*    @file ComXf_Lcfg.h
*    @ingroup ComXfConfiguration
*    @brief This is ComXf link time configuration header file. It contains definitions of link time
*    configuration parameters for the ComXf module.
********************************************************************************************************************/
#ifndef COMXF_LCFG_H
#define COMXF_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComXf_Cfg.h"
#define COMXF_SEC_CODE_START
#define COMXF_CORE_CONST_SEC_START
#define COMXF_CORE_DATA_SEC_START
#define COMXF_CORE_BSS_SEC_START
#include "MemMap.h"
/********************************************************************************************************************
* #! PUBLIC MACRO DEFINITIONS                                                                                       *
********************************************************************************************************************/

/********************************************************************************************************************
* #! PRIVATE TYPE DEFINITIONS                                                                                       *
********************************************************************************************************************/
/* this to be removed , this is an example type */
typedef struct
{
    uint8   Sig1;
    uint16  Sig2;
}Rte_SignalGroup1Type;

/*! @brief defines the type def for the idx of the ComXf_SignalConfig's signal */
typedef uint8 ComXf_SignalId;
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
/*! @brief This variable used to indicate the current ComXf initialization status */
extern ComXf_InitStatusType ComXf_InitStatus;
/********************************************************************************************************************
* #! ComXf const config  data                                                                                    *
********************************************************************************************************************/
/*! @brief This defines the signal configuration used by the ComXf */
extern const ComXf_SignalConfigType ComXf_SignalConfig[ComXf_Num_Of_Signals];
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief  This service initialize the ComXf local status
********************************************************************************************************************/
extern FUNC(void,COMXF_CODE) ComXf_LocalInit(void);
/* #! ComXf transformer for sender receiver interface */
/*!******************************************************************************************************************
*   @brief  This function transforms a Sender/Receiver communication using the serialization of COM Based Transformer.
*   It takes the data element as input and outputs a uint8 array containing the serialized data.
*   @param[out] buffer pointer to Buffer allocated by the RTE, where the transformed data has to be stored by the 
*   transformer
*   @param[out] bufferLength pointer to Used length of the buffer
*   @param[in]  dataElement Data element which shall be transformed
*   @return uint8 Returns the status of the transformer. 
*   0x00 (E_OK): Serialization successful
*   0x81 (E_SER_GENERIC_ERROR): A generic error occurred
********************************************************************************************************************/
// extern FUNC(uint8, COMXF_CODE) ComXf_Signal1SRInterface1
// ( 
//     P2VAR(uint8,AUTOMATIC,COMXF_APPL_VAR) buffer, 
//     P2VAR(uint32,AUTOMATIC,COMXF_APPL_VAR) bufferLength,
//     Rte_SignalGroup1Type dataElement
// );

// /* #! ComXf Inv transformer for sender receiver interface */
// /*!******************************************************************************************************************
// *   @brief  This function deserializes a Sender/Receiver communication using the deserialization of COM Based 
// *   Transformer. It takes the uint8 array containing the serialized data as input and outputs the original data 
// *   element which will be passed to the Rte.
// *   @param[in]  buffer Buffer allocated by the RTE, where the still serialized data are stored by the Rte
// *   @param[in]  bufferLength Used length of the buffer
// *   @param[out] dataElement pointer to Data element which is the result of the transformation and contains the 
// *   deserialized data element
// *   @return uint8 Returns the status of the inverse transformer. 
// *   0x00 (E_OK): Serialization successful
// *   0x01 (E_NO_DATA): No data available which can be deserialized
// *   0x81 (E_SER_GENERIC_ERROR): A generic error occurred
// ********************************************************************************************************************/
FUNC(uint8, COMXF_CODE) ComXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS
( 
    P2CONST(uint8,AUTOMATIC,COMXF_APPL_CONST) buffer, 
    uint32 bufferLength,
    P2VAR(SG_ABS,AUTOMATIC,COMXF_APPL_VAR) dataElement
);
FUNC(uint8, COMXF_CODE) ComXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS
(
    P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) buffer,
    P2VAR(uint16, AUTOMATIC, COMXF_APPL_VAR) bufferLength,
    P2CONST(SG_COM_HS, AUTOMATIC, COMXF_APPL_CONST) dataElement
);
#define COMXF_STOP_SEC_CODE
#include "MemMap.h"
#define E_SER_GENERIC_ERROR 0x81 
#define E_NO_DATA 0x01
#define COMXF_SEC_CODE_STOP
#define COMXF_CORE_CONST_SEC_END
#define COMXF_CORE_DATA_SEC_END
#define COMXF_CORE_BSS_SEC_END

#include "MemMap.h"
#endif /* COMXF_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

