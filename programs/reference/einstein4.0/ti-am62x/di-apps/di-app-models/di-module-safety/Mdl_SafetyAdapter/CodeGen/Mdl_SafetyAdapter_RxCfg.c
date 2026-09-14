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
*    @file Mdl_SafetyAdapter_RxCfg.c
*    @ingroup Mdl_SafetyAdapter
*    @brief This file contains the configuration of the Mdl_SafetyAdapter component.
*    Auto generated code in RPERIYAS at 2024-12-10 11:04:19.624826
********************************************************************************************************************/
#include  "Mdl_SafetyAdapter.h"
/********************************************************************************************************************
*  PUBLIC CONSTANT And VARIABLE DEFINITION                                                                          *
********************************************************************************************************************/

#define MDL_SAFETYADAPTER_BACKUP_RAM_SEC_START
#include "MemMap.h"
uint8 Mdl_SafetyAdapter_RxCanSignalNRStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES];
#define MDL_SAFETYADAPTER_BACKUP_RAM_END
#include "MemMap.h"
uint8 Mdl_SafetyAdapter_RxCanSignal_currentStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES];
uint8 Mdl_SafetyAdapter_RxCanJustRcvdStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];
uint8 Mdl_SafetyAdapter_RxCanSignalMissingStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES];

const Mdl_SafetyAdapter_RxCanGetSignalFunctConfigType Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_FUNCT]=
{
    /* {Mdl_SafetyAdapter_RxCanGetSignalFunctPtrType} */
    { &Mdl_SafetyAdapter_RxCanGetSCSBZR },/* 0 eSCSBZRIn */
    { &Mdl_SafetyAdapter_RxCanGetSCSACCEL },/* 1 eSCSACCELIn */
    { &Mdl_SafetyAdapter_RxCanGetPBKLAB },/* 2 ePBKLABIn */
    { &Mdl_SafetyAdapter_RxCanGetDBKLAB },/* 3 eDBKLABIn */
    { &Mdl_SafetyAdapter_RxCanGetAB },/* 4 eABIn */
    { &Mdl_SafetyAdapter_RxCanGetB_PKBLP },/* 5 eB_PKBLPIn */
    { &Mdl_SafetyAdapter_RxCanGetB_EPBWL },/* 6 eB_EPBWLIn */
    { &Mdl_SafetyAdapter_RxCanGetB_EPBMID },/* 7 eB_EPBMIDIn */
    { &Mdl_SafetyAdapter_RxCanGetB_CPKB },/* 8 eB_CPKBIn */
    { &Mdl_SafetyAdapter_RxCanGetVSCOFF },/* 9 eVSCOFFIn */
    { &Mdl_SafetyAdapter_RxCanGetVSCEXIST },/* 10 eVSCEXISTIn */
    { &Mdl_SafetyAdapter_RxCanGetTRCOFF },/* 11 eTRCOFFIn */
    { &Mdl_SafetyAdapter_RxCanGetSLP_WL },/* 12 eSLP_WLIn */
    { &Mdl_SafetyAdapter_RxCanGetMCBW },/* 13 eMCBWIn */
    { &Mdl_SafetyAdapter_RxCanGetECBEXIST },/* 14 eECBEXISTIn */
    { &Mdl_SafetyAdapter_RxCanGetEBW_MID },/* 15 eEBW_MIDIn */
    { &Mdl_SafetyAdapter_RxCanGetBRK_MID },/* 16 eBRK_MIDIn */
    { &Mdl_SafetyAdapter_RxCanGetBHEXIST },/* 17 eBHEXISTIn */
    { &Mdl_SafetyAdapter_RxCanGetB_EBW },/* 18 eB_EBWIn */
    { &Mdl_SafetyAdapter_RxCanGetB_DAINDP },/* 19 eB_DAINDPIn */
    { &Mdl_SafetyAdapter_RxCanGetB_DAINDC },/* 20 eB_DAINDCIn */
    { &Mdl_SafetyAdapter_RxCanGetB_DACIND },/* 21 eB_DACINDIn */
    { &Mdl_SafetyAdapter_RxCanGetB_BUZZER },/* 22 eB_BUZZERIn */
    { &Mdl_SafetyAdapter_RxCanGetB_BRLV },/* 23 eB_BRLVIn */
    { &Mdl_SafetyAdapter_RxCanGetB_BRKW },/* 24 eB_BRKWIn */
    { &Mdl_SafetyAdapter_RxCanGetB_ALSD },/* 25 eB_ALSDIn */
    { &Mdl_SafetyAdapter_RxCanGetB_ABS },/* 26 eB_ABSIn */
    { &Mdl_SafetyAdapter_RxCanGetABS_MID },/* 27 eABS_MIDIn */
    { &Mdl_SafetyAdapter_RxCanGetPWIINFO },/* 28 ePWIINFOIn */
    { &Mdl_SafetyAdapter_RxCanGetTRCCONRR },/* 29 eTRCCONRRIn */
    { &Mdl_SafetyAdapter_RxCanGetTRCCONRL },/* 30 eTRCCONRLIn */
    { &Mdl_SafetyAdapter_RxCanGetTRCCONFR },/* 31 eTRCCONFRIn */
    { &Mdl_SafetyAdapter_RxCanGetTRCCONFL },/* 32 eTRCCONFLIn */
    { &Mdl_SafetyAdapter_RxCanGetB_EBW2 },/* 33 eB_EBW2In */
    { &Mdl_SafetyAdapter_RxCanGetB_BUZZE2 },/* 34 eB_BUZZE2In */
    { &Mdl_SafetyAdapter_RxCanGetB_BRLV2 },/* 35 eB_BRLV2In */
    { &Mdl_SafetyAdapter_RxCanGetB_BRKW2 }  /* 36 eB_BRKW2In */
};
  
const Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfigType Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG]=
{
    /* { SignalU8ArrBufferLenIdx, Mdl_SafetyAdapter_RxCanGetSignalU8ArrFunctPtrType }*/
    {0U, NULL_PTR }
};


const Mdl_SafetyAdapter_RxCanSignalConfigType Mdl_SafetyAdapter_RxCanSignalConfig[eEndOfRxSafeSignal]=
{
    /* { SignalLengthInByte ,  SignalBufferStartIdx , SignalInvalidIdx , SignalGetFunctIdx ,
        RxSigMonitoringType , SignalMissingCounterValue, SignalMissingOWValue, SignalInvalidOWValue } */
    { 1U,      0U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  0U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           500U,        3,  0}, /* 0 SCSBZR eSCSBZRIn */
    { 1U,      1U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  1U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           500U,        3,  0}, /* 1 SCSACCEL eSCSACCELIn */
    { 1U,      2U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  2U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           500U,        2,  0}, /* 2 PBKLAB ePBKLABIn */
    { 1U,      3U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  3U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           500U,        2,  0}, /* 3 DBKLAB eDBKLABIn */
    { 1U,      4U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  4U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           500U,        0,  0}, /* 4 AB eABIn */
    { 1U,      5U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  5U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        0,  0}, /* 5 B_PKBLP eB_PKBLPIn */
    { 1U,      6U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  6U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        1,  0}, /* 6 B_EPBWL eB_EPBWLIn */
    { 1U,      7U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  7U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        11,   0}, /* 7 B_EPBMID eB_EPBMIDIn */
    { 1U,      8U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  8U,       ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           360U,        0,  0}, /* 8 B_CPKB eB_CPKBIn */
    { 1U,      9U,      MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  9U,       (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 9 VSCOFF eVSCOFFIn */
    { 1U,      10U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  10U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 10 VSCEXIST eVSCEXISTIn */
    { 1U,      11U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  11U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 11 TRCOFF eTRCOFFIn */
    { 1U,      12U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  12U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        7,  0}, /* 12 SLP_WL eSLP_WLIn */
    { 1U,      13U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  13U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 13 MCBW eMCBWIn */
    { 1U,      14U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  14U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 14 ECBEXIST eECBEXISTIn */
    { 1U,      15U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  15U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        1,  0}, /* 15 EBW_MID eEBW_MIDIn */
    { 1U,      16U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  16U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 16 BRK_MID eBRK_MIDIn */
    { 1U,      17U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  17U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 17 BHEXIST eBHEXISTIn */
    { 1U,      18U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  18U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        6,  0}, /* 18 B_EBW eB_EBWIn */
    { 1U,      19U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  19U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           360U,        3,  0}, /* 19 B_DAINDP eB_DAINDPIn */
    { 1U,      20U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  20U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           360U,        0,  0}, /* 20 B_DAINDC eB_DAINDCIn */
    { 1U,      21U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  21U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           360U,        0,  0}, /* 21 B_DACIND eB_DACINDIn */
    { 1U,      22U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  22U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        0,  0}, /* 22 B_BUZZER eB_BUZZERIn */
    { 1U,      23U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  23U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 23 B_BRLV eB_BRLVIn */
    { 1U,      24U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  24U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        3,  0}, /* 24 B_BRKW eB_BRKWIn */
    { 1U,      25U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  25U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 25 B_ALSD eB_ALSDIn */
    { 1U,      26U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  26U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        7,  0}, /* 26 B_ABS eB_ABSIn */
    { 1U,      27U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  27U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 27 ABS_MID eABS_MIDIn */
    { 1U,      28U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  28U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 28 PWIINFO ePWIINFOIn */
    { 1U,      29U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  29U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 29 TRCCONRR eTRCCONRRIn */
    { 1U,      30U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  30U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 30 TRCCONRL eTRCCONRLIn */
    { 1U,      31U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  31U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 31 TRCCONFR eTRCCONFRIn */
    { 1U,      32U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  32U,      (  MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                                                            0U,      0,  0}, /* 32 TRCCONFL eTRCCONFLIn */
    { 1U,      33U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  33U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        6,  0}, /* 33 B_EBW2 eB_EBW2In */
    { 1U,      34U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  34U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        0,  0}, /* 34 B_BUZZE2 eB_BUZZE2In */
    { 1U,      35U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  35U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE ),                                                                                                                                                                                                                                                100U,        0,  0}, /* 35 B_BRLV2 eB_BRLV2In */
    { 1U,      36U,     MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL,  36U,      ( MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE | MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE  | MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED  ),                                                                                                                                                                                           100U,        3,  0} /* 36 B_BRKW2 eB_BRKW2In */
};

const Mdl_SafetyAdapter_RxCanSignalInvalidConfigType Mdl_SafetyAdapter_RxCanSignalInvalidConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS]=
{
        /* {  SignalInvalidSigIdx,  SignalInvalidCounterValue , pSignalInvalidCheckFunc } */
    { 0U,   0U,  NULL_PTR }
};

/********************************************************************************************************************
*  PUBLIC FUNCTION DEFINITION                                                                         	         	*
********************************************************************************************************************/
/* Signal get from Com buffer */

/********************************************************************************************************************
*   @brief   This method Is used to get the signal SCSBZRto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetSCSBZR(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxSCSBZR_SCSBZR(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal SCSACCELto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetSCSACCEL(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxSCSACCEL_SCSACCEL(pSignalValue);
}
/********************************************************************************************************************
*   @brief   This method Is used to get the signal PBKLABto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetPBKLAB(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxPBKLAB_PBKLAB(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal DBKLABto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetDBKLAB(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxDBKLAB_DBKLAB(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal ABto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetAB(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxAB_AB(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_PKBLPto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_PKBLP(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_PKBLP_B_PKBLP(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_EPBWLto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_EPBWL(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_EPBWL_B_EPBWL(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_EPBMIDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_EPBMID(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_EPBMID_B_EPBMID(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_CPKBto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_CPKB(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_CPKB_B_CPKB(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal VSCOFFto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetVSCOFF(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxVSCOFF_VSCOFF(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal VSCEXISTto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetVSCEXIST(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxVSCEXIST_VSCEXIST(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TRCOFFto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetTRCOFF(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTRCOFF_TRCOFF(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal SLP_WLto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetSLP_WL(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxSLP_WL_SLP_WL(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal MCBWto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetMCBW(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxMCBW_MCBW(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal ECBEXISTto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetECBEXIST(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxECBEXIST_ECBEXIST(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal EBW_MIDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetEBW_MID(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxEBW_MID_EBW_MID(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal BRK_MIDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetBRK_MID(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxBRK_MID_BRK_MID(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal BHEXISTto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetBHEXIST(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxBHEXIST_BHEXIST(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_EBWto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_EBW(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_EBW_B_EBW(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_DAINDPto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_DAINDP(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_DAINDP_B_DAINDP(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_DAINDCto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_DAINDC(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_DAINDC_B_DAINDC(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_DACINDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_DACIND(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_DACIND_B_DACIND(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BUZZERto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BUZZER(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BUZZER_B_BUZZER(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BRLVto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BRLV(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BRLV_B_BRLV(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BRKWto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BRKW(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BRKW_B_BRKW(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_ALSDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_ALSD(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_ALSD_B_ALSD(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_ABSto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_ABS(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_ABS_B_ABS(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal ABS_MIDto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetABS_MID(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxABS_MID_ABS_MID(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal PWIINFOto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetPWIINFO(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxPWIINFO_PWIINFO(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TRCCONRRto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetTRCCONRR(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTRCCONRR_TRCCONRR(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TRCCONRLto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetTRCCONRL(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTRCCONRL_TRCCONRL(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TRCCONFRto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetTRCCONFR(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTRCCONFR_TRCCONFR(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal TRCCONFLto Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetTRCCONFL(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxTRCCONFL_TRCCONFL(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_EBW2to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_EBW2(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_EBW2_B_EBW2(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BUZZE2to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BUZZE2(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BUZZE2_B_BUZZE2(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BRLV2to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BRLV2(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BRLV2_B_BRLV2(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method Is used to get the signal B_BRKW2to Com 
*   @param[in] SignalValue pointer to signal data
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanGetB_BRKW2(uint8 * pSignalValue)
{
    (void)Rte_Read_rp_SR_RxB_BRKW2_B_BRKW2(pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal SCSBZR
 ********************************************************************************************************************/
void Mdl_SafetyAdapter_OnDataRx_SCSBZR(void)
{
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eSCSBZRIn >> 3U], (eSCSBZRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eSCSBZRIn >> 3U], (eSCSBZRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eSCSBZRIn >> 3U], (eSCSBZRIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eSCSBZRIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eSCSACCELIn >> 3U], (eSCSACCELIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eSCSACCELIn >> 3U], (eSCSACCELIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eSCSACCELIn >> 3U], (eSCSACCELIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eSCSACCELIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[ePBKLABIn >> 3U], (ePBKLABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[ePBKLABIn >> 3U], (ePBKLABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[ePBKLABIn >> 3U], (ePBKLABIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(ePBKLABIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eDBKLABIn >> 3U], (eDBKLABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eDBKLABIn >> 3U], (eDBKLABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eDBKLABIn >> 3U], (eDBKLABIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eDBKLABIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eABIn >> 3U], (eABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eABIn >> 3U], (eABIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eABIn >> 3U], (eABIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eABIn);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal B_PKBLP
 ********************************************************************************************************************/
void Mdl_SafetyAdapter_OnDataRx_B_PKBLP(void)
{
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_PKBLPIn >> 3U], (eB_PKBLPIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_PKBLPIn >> 3U], (eB_PKBLPIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_PKBLPIn >> 3U], (eB_PKBLPIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_PKBLPIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_EPBWLIn >> 3U], (eB_EPBWLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_EPBWLIn >> 3U], (eB_EPBWLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_EPBWLIn >> 3U], (eB_EPBWLIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_EPBWLIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_EPBMIDIn >> 3U], (eB_EPBMIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_EPBMIDIn >> 3U], (eB_EPBMIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_EPBMIDIn >> 3U], (eB_EPBMIDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_EPBMIDIn);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal VSCOFF
 ********************************************************************************************************************/
void Mdl_SafetyAdapter_OnDataRx_VSCOFF(void)
{
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_CPKBIn >> 3U], (eB_CPKBIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_CPKBIn >> 3U], (eB_CPKBIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_CPKBIn >> 3U], (eB_CPKBIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_CPKBIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eVSCOFFIn >> 3U], (eVSCOFFIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eVSCOFFIn >> 3U], (eVSCOFFIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eVSCOFFIn >> 3U], (eVSCOFFIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eVSCOFFIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eVSCEXISTIn >> 3U], (eVSCEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eVSCEXISTIn >> 3U], (eVSCEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eVSCEXISTIn >> 3U], (eVSCEXISTIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eVSCEXISTIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eTRCOFFIn >> 3U], (eTRCOFFIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eTRCOFFIn >> 3U], (eTRCOFFIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eTRCOFFIn >> 3U], (eTRCOFFIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eTRCOFFIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eSLP_WLIn >> 3U], (eSLP_WLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eSLP_WLIn >> 3U], (eSLP_WLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eSLP_WLIn >> 3U], (eSLP_WLIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eSLP_WLIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eMCBWIn >> 3U], (eMCBWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eMCBWIn >> 3U], (eMCBWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eMCBWIn >> 3U], (eMCBWIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eMCBWIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eECBEXISTIn >> 3U], (eECBEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eECBEXISTIn >> 3U], (eECBEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eECBEXISTIn >> 3U], (eECBEXISTIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eECBEXISTIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eEBW_MIDIn >> 3U], (eEBW_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eEBW_MIDIn >> 3U], (eEBW_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eEBW_MIDIn >> 3U], (eEBW_MIDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eEBW_MIDIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eBRK_MIDIn >> 3U], (eBRK_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eBRK_MIDIn >> 3U], (eBRK_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eBRK_MIDIn >> 3U], (eBRK_MIDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eBRK_MIDIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eBHEXISTIn >> 3U], (eBHEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eBHEXISTIn >> 3U], (eBHEXISTIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eBHEXISTIn >> 3U], (eBHEXISTIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eBHEXISTIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_EBWIn >> 3U], (eB_EBWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_EBWIn >> 3U], (eB_EBWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_EBWIn >> 3U], (eB_EBWIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_EBWIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_DAINDPIn >> 3U], (eB_DAINDPIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_DAINDPIn >> 3U], (eB_DAINDPIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_DAINDPIn >> 3U], (eB_DAINDPIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_DAINDPIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_DAINDCIn >> 3U], (eB_DAINDCIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_DAINDCIn >> 3U], (eB_DAINDCIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_DAINDCIn >> 3U], (eB_DAINDCIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_DAINDCIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_DACINDIn >> 3U], (eB_DACINDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_DACINDIn >> 3U], (eB_DACINDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_DACINDIn >> 3U], (eB_DACINDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_DACINDIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BUZZERIn >> 3U], (eB_BUZZERIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BUZZERIn >> 3U], (eB_BUZZERIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BUZZERIn >> 3U], (eB_BUZZERIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BUZZERIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BRLVIn >> 3U], (eB_BRLVIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BRLVIn >> 3U], (eB_BRLVIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BRLVIn >> 3U], (eB_BRLVIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BRLVIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BRKWIn >> 3U], (eB_BRKWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BRKWIn >> 3U], (eB_BRKWIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BRKWIn >> 3U], (eB_BRKWIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BRKWIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_ALSDIn >> 3U], (eB_ALSDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_ALSDIn >> 3U], (eB_ALSDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_ALSDIn >> 3U], (eB_ALSDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_ALSDIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_ABSIn >> 3U], (eB_ABSIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_ABSIn >> 3U], (eB_ABSIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_ABSIn >> 3U], (eB_ABSIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_ABSIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eABS_MIDIn >> 3U], (eABS_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eABS_MIDIn >> 3U], (eABS_MIDIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eABS_MIDIn >> 3U], (eABS_MIDIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eABS_MIDIn);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal PWIINFO
 ********************************************************************************************************************/
void Mdl_SafetyAdapter_OnDataRx_PWIINFO(void)
{
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[ePWIINFOIn >> 3U], (ePWIINFOIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[ePWIINFOIn >> 3U], (ePWIINFOIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[ePWIINFOIn >> 3U], (ePWIINFOIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(ePWIINFOIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eTRCCONRRIn >> 3U], (eTRCCONRRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eTRCCONRRIn >> 3U], (eTRCCONRRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eTRCCONRRIn >> 3U], (eTRCCONRRIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eTRCCONRRIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eTRCCONRLIn >> 3U], (eTRCCONRLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eTRCCONRLIn >> 3U], (eTRCCONRLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eTRCCONRLIn >> 3U], (eTRCCONRLIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eTRCCONRLIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eTRCCONFRIn >> 3U], (eTRCCONFRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eTRCCONFRIn >> 3U], (eTRCCONFRIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eTRCCONFRIn >> 3U], (eTRCCONFRIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eTRCCONFRIn);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eTRCCONFLIn >> 3U], (eTRCCONFLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eTRCCONFLIn >> 3U], (eTRCCONFLIn & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eTRCCONFLIn >> 3U], (eTRCCONFLIn & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eTRCCONFLIn);
}

/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal B_EBW2
 ********************************************************************************************************************/
void Mdl_SafetyAdapter_OnDataRx_B_EBW2(void)
{
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_EBW2In >> 3U], (eB_EBW2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_EBW2In >> 3U], (eB_EBW2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_EBW2In >> 3U], (eB_EBW2In & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_EBW2In);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BUZZE2In >> 3U], (eB_BUZZE2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BUZZE2In >> 3U], (eB_BUZZE2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BUZZE2In >> 3U], (eB_BUZZE2In & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BUZZE2In);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BRLV2In >> 3U], (eB_BRLV2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BRLV2In >> 3U], (eB_BRLV2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BRLV2In >> 3U], (eB_BRLV2In & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BRLV2In);
    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[eB_BRKW2In >> 3U], (eB_BRKW2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[eB_BRKW2In >> 3U], (eB_BRKW2In & 0x7U));
    MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignal_currentStatus[eB_BRKW2In >> 3U], (eB_BRKW2In & 0x7U));
    Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(eB_BRKW2In);
}


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


