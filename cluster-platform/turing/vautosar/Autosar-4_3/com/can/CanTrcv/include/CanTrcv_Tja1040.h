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
/*!******************************************************************************************************************
*   @file CanTrcv_Tja1040.h
*   @ingroup CanTrcv
*   @brief This file provides the declaration of the CanTrcv Tja1040 API. This header file should be included by other  
*   modules that use the CanTrcv Tja1040 API.
********************************************************************************************************************/
#ifndef CANTRCV_TJA1040_H
#define CANTRCV_TJA1040_H

#include "CanTrcv_Tja1040_Cfg.h"

/*!******************************************************************************************************************
*   @brief This method initializes the Can Transceiver Tja1040 internal variables to default values.
********************************************************************************************************************/
void CanTrcv_Tja1040_InitMemory(void);

/*!******************************************************************************************************************
*   @brief This method initialize all the connected Tja1040 transceivers based on their initialization sequences.
********************************************************************************************************************/
void CanTrcv_Tja1040_Init(void);

/*!******************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  Channel  CAN transceiver Tja1040 channed Id to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request      
*               - E_OK: will be returned if the request for transceiver mode change has been accepted. 
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any 
*                 parameter is out of the allowed range.
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1040_SetOpMode(uint8 Channel, CanTrcv_TrcvModeType OpMode);

/*!******************************************************************************************************************
*   @brief      This method gets the opreation mode of the Transceiver.
*   @param[in]  Channel  CAN transceiver Tja1040 channel ID to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request      
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1443_GetOpMode(uint8 Channel, CanTrcv_TrcvModeType* OpMode);

/*!******************************************************************************************************************
*   @brief      This method gets the wakeup reasont of the Transceiver 
*   @param[in]  Channel  CAN transceiver Tja1040 channel ID to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request      
*                   - TRUE:  Wakeup occured
*                   - FALSE: Wakup not supported or not occured
********************************************************************************************************************/
boolean CanTrcv_Tja1040_GetBusWuReason(uint8 Channel, CanTrcv_TrcvWakeupReasonType *Reason);

#endif /* CANTRCV_TJA1040_H */
