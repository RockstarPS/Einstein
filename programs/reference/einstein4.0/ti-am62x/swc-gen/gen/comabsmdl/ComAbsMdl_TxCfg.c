/********************************************************************************************************************
* C O P Y R I G H T                                                                                                 *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This Is an unpublished work Of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work And intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* Or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent Or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may Not copy it, use it, modify it, Or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComAbsMdl_TxCfg.c
*    @ingroup ComAbsMdl
*    @brief This file contains the configuration of the ComAbsMdl component.
*    @Note : Auto Generated code .Do Not hand modify this file
*    Auto generated code in VTAMILAR at 2024-11-20 16:37:10.938021
********************************************************************************************************************/
#include  "ComAbsMdl.h"

/********************************************************************************************************************
*  PUBLIC CONSTANT And VARIABLE DEFINITION                                                                           *
********************************************************************************************************************/
const ComAbsMdl_TxCanSetSignalFunctPtrType ComAbsMdl_TxCanSetSignalFunctPtrConfig[CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT]=
{
    &ComAbsMdl_TxCanSetSig_SecureTxByte0,  /* 0 - eSecureTxByte0Out */
    &ComAbsMdl_TxCanSetSig_SecureTxByte1,  /* 1 - eSecureTxByte1Out */
    &ComAbsMdl_TxCanSetSig_SecureTxByte2,  /* 2 - eSecureTxByte2Out */
    &ComAbsMdl_TxCanSetSig_SecureTxByte3,  /* 3 - eSecureTxByte3Out */
    &ComAbsMdl_TxCanSetSig_MAC_Tx,  /* 4 - eMAC_TxOut */
    &ComAbsMdl_TxCanSetSig_FV_Tx,  /* 5 - eFV_TxOut */
    &ComAbsMdl_TxCanSetSig_Odometer,  /* 7 - eOdometerOut */
    &ComAbsMdl_TxCanSetSig_VehicleSpeedIC,  /* 8 - eVehicleSpeedICOut */
    &ComAbsMdl_TxCanSetSig_Illumination_PWM,  /* 9 - eIllumination_PWMOut */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte0,  /* 10 - eDebug1_Byte0Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte1,  /* 11 - eDebug1_Byte1Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte2,  /* 12 - eDebug1_Byte2Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte3,  /* 13 - eDebug1_Byte3Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte4,  /* 14 - eDebug1_Byte4Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte5,  /* 15 - eDebug1_Byte5Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte6,  /* 16 - eDebug1_Byte6Out */
    &ComAbsMdl_TxCanSetSig_Debug1_Byte7,  /* 17 - eDebug1_Byte7Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte0,  /* 18 - eDebug2_Byte0Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte1,  /* 19 - eDebug2_Byte1Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte2,  /* 20 - eDebug2_Byte2Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte3,  /* 21 - eDebug2_Byte3Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte4,  /* 22 - eDebug2_Byte4Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte5,  /* 23 - eDebug2_Byte5Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte6,  /* 24 - eDebug2_Byte6Out */
    &ComAbsMdl_TxCanSetSig_Debug2_Byte7,  /* 25 - eDebug2_Byte7Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte0,  /* 26 - eDebug3_Byte0Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte1,  /* 27 - eDebug3_Byte1Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte2,  /* 28 - eDebug3_Byte2Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte3,  /* 29 - eDebug3_Byte3Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte4,  /* 30 - eDebug3_Byte4Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte5,  /* 31 - eDebug3_Byte5Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte6,  /* 32 - eDebug3_Byte6Out */
    &ComAbsMdl_TxCanSetSig_Debug3_Byte7,  /* 33 - eDebug3_Byte7Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte0,  /* 34 - eDebug4_Byte0Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte1,  /* 35 - eDebug4_Byte1Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte2,  /* 36 - eDebug4_Byte2Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte3,  /* 37 - eDebug4_Byte3Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte4,  /* 38 - eDebug4_Byte4Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte5,  /* 39 - eDebug4_Byte5Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte6,  /* 40 - eDebug4_Byte6Out */
    &ComAbsMdl_TxCanSetSig_Debug4_Byte7,  /* 41 - eDebug4_Byte7Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte0,  /* 42 - eDebug5_Byte0Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte1,  /* 43 - eDebug5_Byte1Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte2,  /* 44 - eDebug5_Byte2Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte3,  /* 45 - eDebug5_Byte3Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte4,  /* 46 - eDebug5_Byte4Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte5,  /* 47 - eDebug5_Byte5Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte6,  /* 48 - eDebug5_Byte6Out */
    &ComAbsMdl_TxCanSetSig_Debug5_Byte7  /* 49 - eDebug5_Byte7Out */
};

const ComAbsMdl_TxCanSetSignalU8ArrFunctPtrType ComAbsMdl_TxCanSetSignalU8ArrFunctPtrConfig[CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT]=
{
    NULL_PTR
};

const ComAbsMdl_TxCanSignalConfigType ComAbsMdl_TxCanSignalConfig[eEndOfTxSignal]=
{
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 0U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 0 SecureTxByte0 eSecureTxByte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 1U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 1 SecureTxByte1 eSecureTxByte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 2U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 2 SecureTxByte2 eSecureTxByte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 3U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 3 SecureTxByte3 eSecureTxByte3Out */
    { 4U      , COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS      , 4U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 4 MAC_Tx eMAC_TxOut */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 5U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 5 FV_Tx eFV_TxOut */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 6U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 6 Battery_Voltage eBattery_VoltageOut */
    { 4U      , COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS      , 7U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 7 Odometer eOdometerOut */
    { 2U      , COMABSMDL_TXCAN_NUM_OF_U16_BUFFERS      , 8U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 8 VehicleSpeedIC eVehicleSpeedICOut */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 9U      , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 9 Illumination_PWM eIllumination_PWMOut */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 10U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 10 Debug1_Byte0 eDebug1_Byte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 11U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 11 Debug1_Byte1 eDebug1_Byte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 12U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 12 Debug1_Byte2 eDebug1_Byte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 13U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 13 Debug1_Byte3 eDebug1_Byte3Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 14U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 14 Debug1_Byte4 eDebug1_Byte4Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 15U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 15 Debug1_Byte5 eDebug1_Byte5Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 16U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 16 Debug1_Byte6 eDebug1_Byte6Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 17U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 17 Debug1_Byte7 eDebug1_Byte7Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 18U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 18 Debug2_Byte0 eDebug2_Byte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 19U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 19 Debug2_Byte1 eDebug2_Byte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 20U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 20 Debug2_Byte2 eDebug2_Byte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 21U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 21 Debug2_Byte3 eDebug2_Byte3Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 22U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 22 Debug2_Byte4 eDebug2_Byte4Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 23U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 23 Debug2_Byte5 eDebug2_Byte5Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 24U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 24 Debug2_Byte6 eDebug2_Byte6Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 25U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 25 Debug2_Byte7 eDebug2_Byte7Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 26U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 26 Debug3_Byte0 eDebug3_Byte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 27U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 27 Debug3_Byte1 eDebug3_Byte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 28U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 28 Debug3_Byte2 eDebug3_Byte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 29U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 29 Debug3_Byte3 eDebug3_Byte3Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 30U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 30 Debug3_Byte4 eDebug3_Byte4Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 31U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 31 Debug3_Byte5 eDebug3_Byte5Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 32U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 32 Debug3_Byte6 eDebug3_Byte6Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 33U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 33 Debug3_Byte7 eDebug3_Byte7Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 34U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 34 Debug4_Byte0 eDebug4_Byte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 35U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 35 Debug4_Byte1 eDebug4_Byte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 36U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 36 Debug4_Byte2 eDebug4_Byte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 37U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 37 Debug4_Byte3 eDebug4_Byte3Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 38U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 38 Debug4_Byte4 eDebug4_Byte4Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 39U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 39 Debug4_Byte5 eDebug4_Byte5Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 40U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 40 Debug4_Byte6 eDebug4_Byte6Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 41U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 41 Debug4_Byte7 eDebug4_Byte7Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 42U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 42 Debug5_Byte0 eDebug5_Byte0Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 43U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 43 Debug5_Byte1 eDebug5_Byte1Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 44U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 44 Debug5_Byte2 eDebug5_Byte2Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 45U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 45 Debug5_Byte3 eDebug5_Byte3Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 46U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 46 Debug5_Byte4 eDebug5_Byte4Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 47U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 47 Debug5_Byte5 eDebug5_Byte5Out */
    { 1U      , COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS       , 48U     , ( COMABSMDL_TXCAN_CONFIRMATION_ENABLED )                                                                           }, /* 48 Debug5_Byte6 eDebug5_Byte6Out */
};
/********************************************************************************************************************
*  PUBLIC FUNCTION DEFINITION                                                                         	         	*
********************************************************************************************************************/

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal SecureTxByte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_SecureTxByte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eSecureTxByte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eSecureTxByte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eSecureTxByte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eSecureTxByte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eMAC_TxOut);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eFV_TxOut);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Odometer 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Odometer(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eOdometerOut);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal VehicleSpeedIC 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_VehicleSpeedIC(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eVehicleSpeedICOut);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Illumination_PWM 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Illumination_PWM(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eIllumination_PWMOut);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Debug1_Byte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Debug1_Byte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte4Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte5Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte6Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug1_Byte7Out);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Debug2_Byte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Debug2_Byte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte4Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte5Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte6Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug2_Byte7Out);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Debug3_Byte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Debug3_Byte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte4Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte5Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte6Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug3_Byte7Out);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Debug4_Byte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Debug4_Byte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte4Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte5Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte6Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug4_Byte7Out);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful transmission of the signal Debug5_Byte0 
********************************************************************************************************************/
void CComAbsMdl_OnDataTx_Debug5_Byte0(void)
{
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte0Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte1Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte2Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte3Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte4Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte5Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte6Out);
    ComAbsMdl_TxCan_SetCanSignalTxConfirmation(eDebug5_Byte7Out);
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal SecureTxByte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_SecureTxByte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxSecureTxByte0_SecureTxByte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal SecureTxByte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_SecureTxByte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxSecureTxByte1_SecureTxByte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal SecureTxByte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_SecureTxByte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxSecureTxByte2_SecureTxByte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal SecureTxByte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_SecureTxByte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxSecureTxByte3_SecureTxByte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal MAC_Tx to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_MAC_Tx(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint32   SignalValue = 0;
    SignalValue = *((uint32 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxMAC_Tx_MAC_Tx(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal FV_Tx to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_FV_Tx(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxFV_Tx_FV_Tx(SignalValue);
    return RetStatus;
}
/********************************************************************************************************************
*   @brief   This method Is used to send the signal Odometer to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Odometer(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint32   SignalValue = 0;
    SignalValue = *((uint32 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxOdometer_Odometer(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal VehicleSpeedIC to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_VehicleSpeedIC(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint16   SignalValue = 0;
    SignalValue = *((uint16 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Illumination_PWM to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Illumination_PWM(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxIllumination_PWM_Illumination_PWM(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte0_Debug1_Byte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte1_Debug1_Byte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte2_Debug1_Byte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte3_Debug1_Byte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte4 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte4(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte4_Debug1_Byte4(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte5 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte5(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte5_Debug1_Byte5(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte6 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte6(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte6_Debug1_Byte6(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug1_Byte7 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug1_Byte7(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug1_Byte7_Debug1_Byte7(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte0_Debug2_Byte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte1_Debug2_Byte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte2_Debug2_Byte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte3_Debug2_Byte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte4 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte4(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte4_Debug2_Byte4(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte5 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte5(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte5_Debug2_Byte5(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte6 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte6(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte6_Debug2_Byte6(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug2_Byte7 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug2_Byte7(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug2_Byte7_Debug2_Byte7(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte0_Debug3_Byte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte1_Debug3_Byte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte2_Debug3_Byte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte3_Debug3_Byte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte4 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte4(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte4_Debug3_Byte4(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte5 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte5(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte5_Debug3_Byte5(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte6 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte6(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte6_Debug3_Byte6(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug3_Byte7 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug3_Byte7(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug3_Byte7_Debug3_Byte7(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte0_Debug4_Byte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte1_Debug4_Byte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte2_Debug4_Byte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte3_Debug4_Byte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte4 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte4(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte4_Debug4_Byte4(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte5 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte5(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte5_Debug4_Byte5(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte6 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte6(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte6_Debug4_Byte6(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug4_Byte7 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug4_Byte7(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug4_Byte7_Debug4_Byte7(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte0 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte0(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte0_Debug5_Byte0(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte1 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte1(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte1_Debug5_Byte1(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte2 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte2(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte2_Debug5_Byte2(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte3 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte3(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte3_Debug5_Byte3(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte4 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte4(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte4_Debug5_Byte4(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte5 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte5(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte5_Debug5_Byte5(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte6 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte6(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte6_Debug5_Byte6(SignalValue);
    return RetStatus;
}

/********************************************************************************************************************
*   @brief   This method Is used to send the signal Debug5_Byte7 to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_TxCanSetSig_Debug5_Byte7(const uint8 * pSignalValue)
{
    Std_ReturnType RetStatus;
    uint8   SignalValue = 0;
    SignalValue = *((uint8 *)pSignalValue);
    RetStatus = Rte_Write_pp_SR_TxDebug5_Byte7_Debug5_Byte7(SignalValue);
    return RetStatus;
}

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


