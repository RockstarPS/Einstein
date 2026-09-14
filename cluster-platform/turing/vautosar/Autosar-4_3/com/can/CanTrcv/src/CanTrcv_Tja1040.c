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
*    @file CanTrcv_Tja1040.c
*    @ingroup CanTrcv
*    @brief This file implements the AUTOSAR CanTrcv module.The CAN transceiver driver abstracts
*    the CAN transceiver hardware. It offers a hardware independent interface to the higher layers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_Tja1040.h"
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief This method initializes the Can Transceiver Tja1040 internal variables to default values.
********************************************************************************************************************/
void CanTrcv_Tja1040_InitMemory(void)
{

}


/********************************************************************************************************************
*   @brief This method initialize all the connected Tja1040 transceivers based on their initialization sequences.
********************************************************************************************************************/
void CanTrcv_Tja1040_Init(void)
{

}

/********************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  Channel  CAN transceiver Tja1040 channed Id to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request
*               - E_OK: will be returned if the request for transceiver mode change has been accepted.
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any
*                 parameter is out of the allowed range.
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1040_SetOpMode(uint8 Channel, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType Status = E_NOT_OK;
    CanTrcv_Tja1040_PinCfgType const *pTja1040_PinCfg;

    if (CANTRCV_TJA1040_NUM_OF_CHANNELS > Channel )
    {
        pTja1040_PinCfg = &CanTrcv_Tja1040_PinCfg[Channel];
        switch(OpMode)
        {
            case CANTRCV_TRCVMODE_NORMAL:
                Dio_WriteChannel(pTja1040_PinCfg->CanTrcv_Tja1040_StbPin,STD_LOW);
                Status = E_OK;
                break;
            case CANTRCV_TRCVMODE_STANDBY:
                Dio_WriteChannel(pTja1040_PinCfg->CanTrcv_Tja1040_StbPin,STD_HIGH);
                Status = E_OK;
                break;
            default:
                Status = E_NOT_OK;
                break;
        }
    }
    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the operation mode of the Transceiver.
*   @param[in]  Channel  CAN transceiver Tja1040 channel ID to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1443_GetOpMode(uint8 Channel, CanTrcv_TrcvModeType* OpMode)
{
    CanTrcv_Tja1040_PinCfgType const * pTja1040_PinCfg;
    Dio_LevelType StbPinLevel;
    Std_ReturnType Status = E_NOT_OK;

    if ((CANTRCV_TJA1040_NUM_OF_CHANNELS > Channel ) &&
        (NULL_PTR != OpMode))
    {
        pTja1040_PinCfg = &CanTrcv_Tja1040_PinCfg[Channel];
        StbPinLevel = Dio_ReadChannel(pTja1040_PinCfg->CanTrcv_Tja1040_StbPin);
        if (((uint8)STD_LOW) == StbPinLevel)
        {
            *OpMode = CANTRCV_TRCVMODE_NORMAL;
        }
        else
        {
            *OpMode = CANTRCV_TRCVMODE_STANDBY;
        }
        Status = E_OK;
    }

    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the wakeup reasont of the Transceiver
*   @param[in]  Channel  CAN transceiver Tja1040 channel ID to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request
*                   - TRUE:  Wakeup occured
*                   - FALSE: Wakup not supported or not occured
********************************************************************************************************************/
boolean CanTrcv_Tja1040_GetBusWuReason(uint8 Channel, CanTrcv_TrcvWakeupReasonType *Reason)
{
    boolean Status = FALSE;
#if(CANTRCV_TJA1040_WAKEUP_BY_BUS_USED == STD_ON)
    CanTrcv_Tja1040_PinCfgType const * pTja1040_PinCfg;
    Dio_LevelType StbPinLevel;
    Dio_LevelType RxPinLevel;

    if (CANTRCV_TJA1040_NUM_OF_CHANNELS > Channel)
    {
        pTja1040_PinCfg = &CanTrcv_Tja1040_PinCfg[Channel];
        StbPinLevel = Dio_ReadChannel(pTja1040_PinCfg->CanTrcv_Tja1040_StbPin);
        RxPinLevel = Dio_ReadChannel(pTja1040_PinCfg->CanTrcv_Tja1040_StbPin);
        if ((STD_HIGH == StbPinLevel) && (STD_LOW == RxPinLevel))
        {
            *Reason = CANTRCV_WU_BY_BUS;
            Status = TRUE;
        }
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(Channel);
    CANTRCV_IGNORE_UNUSED_PARAM(Reason);
#endif
    return Status;
}

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
*  @date    14-Apr-2021
*  @version 0.0.1
*  @author  pchinnat
*  @brief   Initial version implementation RTC#
*******************************************************************************************************************/
