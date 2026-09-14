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
 *    @file ComAbsMdl_RxCfg.c
 *    @ingroup ComAbsMdl
 *    @brief This file contains the configuration of the ComAbsMdl component.
 *    Auto generated code in VTAMILAR at 2024-11-20 16:37:10.938021
 ********************************************************************************************************************/
#include "ComAbsMdl.h"
/********************************************************************************************************************
*  PUBLIC CONSTANT And VARIABLE DEFINITION                                                                          *
********************************************************************************************************************/

#define COMABSMDL_BACKUP_RAM_SEC_START
#include "MemMap.h"
uint8 ComAbsMdl_RxCanSignalNRStatus[COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES];
#define COMABSMDL_BACKUP_RAM_END
#include "MemMap.h"
uint8 ComAbsMdl_RxCanSignal_currentStatus[COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES];
uint8 ComAbsMdl_RxCanJustRcvdStatus[COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];
uint8 ComAbsMdl_RxCanSignalMissingStatus[COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES];



const ComAbsMdl_RxCanGetSignalFunctConfigType ComAbsMdl_RxCanGetSignalFunctConfig[COMABSMDL_RXCAN_NUM_OF_GET_SIG_FUNCT]=
{
    /* {ComAbsMdl_RxCanGetSignalFunctPtrType} */
    { &ComAbsMdl_RxCanGetDayNightMode },/* 0 =CONCATENATE("e",A2,"In") */
    { &ComAbsMdl_RxCanGetIllumination_level },/* 1 =CONCATENATE("e",A3,"In") */
    { &ComAbsMdl_RxCanGetAmbient_Light_level },/* 2 =CONCATENATE("e",A4,"In") */
    { &ComAbsMdl_RxCanGetPowerMode },/* 3 =CONCATENATE("e",A5,"In") */
    { &ComAbsMdl_RxCanGetTransportMode },/* 4 =CONCATENATE("e",A6,"In") */
    { &ComAbsMdl_RxCanGetGearMode },/* 5 =CONCATENATE("e",A7,"In") */
    { &ComAbsMdl_RxCanGetGearRecommendation },/* 6 =CONCATENATE("e",A8,"In") */
    { &ComAbsMdl_RxCanGetGear },/* 7 =CONCATENATE("e",A9,"In") */
    { &ComAbsMdl_RxCanGetWarning },/* 8 =CONCATENATE("e",A10,"In") */
    { &ComAbsMdl_RxCanGetGearStatus },/* 9 =CONCATENATE("e",A11,"In") */
    { &ComAbsMdl_RxCanGetEngineSpeed },/* 10 =CONCATENATE("e",A12,"In") */
    { &ComAbsMdl_RxCanGetTurn_Indicator_Control }  /* 11 eTurn_Indicator_ControlIn */
};

const ComAbsMdl_RxCanGetSignalU8ArrConfigType ComAbsMdl_RxCanGetSignalU8ArrConfig[COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG] =
    {
        /* { SignalU8ArrBufferLenIdx, ComAbsMdl_RxCanGetSignalU8ArrFunctPtrType }*/
        {0U, NULL_PTR}};

const ComAbsMdl_RxCanSignalConfigType ComAbsMdl_RxCanSignalConfig[eEndOfRxSignal] =
    {
        /* { SignalLengthInByte ,  SignalBufferStartIdx , SignalInvalidIdx , SignalGetFunctIdx ,
            RxSigMonitoringType , SignalMissingCounterValue } */
        {1U, 0U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 0U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 0 DayNightMode =CONCATENATE("e",A2,"In") */
        {1U, 1U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 1U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 1 Illumination_level =CONCATENATE("e",A3,"In") */
        {1U, 2U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 2U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 2 Ambient_Light_level =CONCATENATE("e",A4,"In") */
        {1U, 3U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 3U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 3 PowerMode =CONCATENATE("e",A5,"In") */
        {1U, 4U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 4U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 4 TransportMode =CONCATENATE("e",A6,"In") */
        {1U, 5U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 5U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 5 GearMode =CONCATENATE("e",A7,"In") */
        {1U, 6U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 6U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 6 GearRecommendation =CONCATENATE("e",A8,"In") */
        {1U, 7U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 7U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 7 Gear =CONCATENATE("e",A9,"In") */
        {1U, 8U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 8U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 8 Warning =CONCATENATE("e",A10,"In") */
        {1U, 9U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 9U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 9 GearStatus =CONCATENATE("e",A11,"In") */
        {2U, 0U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 10U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U}, /* 10 EngineSpeed =CONCATENATE("e",A12,"In") */
        {1U, 0U, COMABSMDL_RXCAN_NO_INVALDID_SIGNAL, 11U, (COMABSMDL_RXCAN_SIG_MISSING_ENABLE | COMABSMDL_RXCAN_SIG_NR_ENABLE), 200U} /* 11 Turn Indicator =CONCATENATE("e",A12,"In") */
};

const ComAbsMdl_RxCanSignalInvalidConfigType ComAbsMdl_RxCanSignalInvalidConfig[COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS] =
    {
        /* {  SignalInvalidSigIdx,  SignalInvalidCounterValue , pSignalInvalidCheckFunc } */
        {0U, 0U, NULL_PTR}};

/********************************************************************************************************************
 *  PUBLIC FUNCTION DEFINITION                                                                         	         	*
 ********************************************************************************************************************/
/* Signal get from Com buffer */

/********************************************************************************************************************
 *   @param[in] SignalValue pointer to signal data
 *   @brief   This method Is used to get the signal DayNightModeto Com
 ********************************************************************************************************************/
void ComAbsMdl_RxCanGetDayNightMode(uint8 *pSignalValue)
{
    (void)Rte_Read_rp_SR_RxDayNightMode_DayNightMode(pSignalValue);
}

/********************************************************************************************************************
 *   @brief   This method Is used to get the signal Illumination_levelto Com
 *   @param[in] SignalValue pointer to signal data
 ********************************************************************************************************************/
void ComAbsMdl_RxCanGetIllumination_level(uint8 *pSignalValue)
{
    (void)Rte_Read_rp_SR_RxIllumination_level_Illumination_level(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal Ambient_Light_levelto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetAmbient_Light_level(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal PowerModeto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetPowerMode(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxPowerMode_PowerMode(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TransportModeto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetTransportMode(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTransportMode_TransportMode(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal GearModeto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetGearMode(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxGearMode_GearMode(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal GearRecommendationto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetGearRecommendation(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxGearRecommendation_GearRecommendation(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal Gearto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetGear(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxGear_Gear(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal Warningto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetWarning(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxWarning_Warning(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal GearStatusto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetGearStatus(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxGearStatus_GearStatus(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal EngineSpeedto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetEngineSpeed(uint16 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxEngineSpeed_EngineSpeed(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal Turn_Indicator_Controlto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void ComAbsMdl_RxCanGetTurn_Indicator_Control(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal DayNightMode
 ********************************************************************************************************************/
void CComAbsMdl_OnDataRx_DayNightMode(void)
{
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[eDayNightModeIn >> 3U], (eDayNightModeIn & 0x7U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eDayNightModeIn>> 3U)], (uint8)(eDayNightModeIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eDayNightModeIn>> 3U)], (uint8)(eDayNightModeIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eDayNightModeIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eIllumination_levelIn>> 3U)], (uint8)(eIllumination_levelIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eIllumination_levelIn>> 3U)], (uint8)(eIllumination_levelIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eIllumination_levelIn>> 3U)], (uint8)(eIllumination_levelIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eIllumination_levelIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[eAmbient_Light_levelIn >> 3U], (eAmbient_Light_levelIn & 0x7U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eAmbient_Light_levelIn>> 3U)], (uint8)(eAmbient_Light_levelIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eAmbient_Light_levelIn>> 3U)], (uint8)(eAmbient_Light_levelIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eAmbient_Light_levelIn);
}

/********************************************************************************************************************
 *   @brief   This method is called from com on successful reception of the signal PowerMode
 ********************************************************************************************************************/
void CComAbsMdl_OnDataRx_PowerMode(void)
{
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)ePowerModeIn >> 3U)], (uint8)(ePowerModeIn & 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)ePowerModeIn >> 3U)], (uint8)(ePowerModeIn & 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)ePowerModeIn >> 3U)], (uint8)(ePowerModeIn & 0x07U));
    ComAbsMdl_ReloadMissingTimer(ePowerModeIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eTransportModeIn>> 3U)], (uint8)(eTransportModeIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eTransportModeIn>> 3U)], (uint8)(eTransportModeIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eTransportModeIn>> 3U)], (uint8)(eTransportModeIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eTransportModeIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eGearModeIn>> 3U)], (uint8)(eGearModeIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eGearModeIn>> 3U)], (uint8)(eGearModeIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eGearModeIn>> 3U)], (uint8)(eGearModeIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eGearModeIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eGearRecommendationIn>> 3U)], (uint8)(eGearRecommendationIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eGearRecommendationIn>> 3U)], (uint8)(eGearRecommendationIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eGearRecommendationIn>> 3U)], (uint8)(eGearRecommendationIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eGearRecommendationIn );
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eGearIn>> 3U)], (uint8)(eGearIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eGearIn>> 3U)], (uint8)(eGearIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eGearIn>> 3U)], (uint8)(eGearIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eGearIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eWarningIn>> 3U)], (uint8)(eWarningIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eWarningIn>> 3U)], (uint8)(eWarningIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eWarningIn>> 3U)], (uint8)(eWarningIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eWarningIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[eGearStatusIn >> 3U], (eGearStatusIn & 0x7U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eGearStatusIn>> 3U)], (uint8)(eGearStatusIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eGearStatusIn>> 3U)], (uint8)(eGearStatusIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eGearStatusIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eEngineSpeedIn>> 3U)], (uint8)(eEngineSpeedIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[eEngineSpeedIn >> 3U], (eEngineSpeedIn & 0x7U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eEngineSpeedIn>> 3U)], (uint8)(eEngineSpeedIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eEngineSpeedIn);
    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[(uint32)((uint32)eTurn_Indicator_ControlIn>> 3U)], (uint8)(eTurn_Indicator_ControlIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanJustRcvdStatus[(uint32)((uint32)eTurn_Indicator_ControlIn>> 3U)], (uint8)(eTurn_Indicator_ControlIn& 0x07U));
    COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignal_currentStatus[(uint32)((uint32)eTurn_Indicator_ControlIn>> 3U)], (uint8)(eTurn_Indicator_ControlIn& 0x07U));
    ComAbsMdl_ReloadMissingTimer(eTurn_Indicator_ControlIn);
}   

/********************************************************************************************************************
 *   @brief   This method Is used to get the RAW value of signal Outside_Air_Temp_Statto Com
 *   @param[in] void
 ********************************************************************************************************************/
// uint8 GetRawOutside_Air_Temp_Stat(void)
//{
//	uint8 Air_Temp_stat_Var = 0;
//	(void)Rte_Read_rp_SR_RxOutside_Air_Temp_Stat_Outside_Air_Temp_Stat(&Air_Temp_stat_Var);
//	return Air_Temp_stat_Var;
// }

/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
