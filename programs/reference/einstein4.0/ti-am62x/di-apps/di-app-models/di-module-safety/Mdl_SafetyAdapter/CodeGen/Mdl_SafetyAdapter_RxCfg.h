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
*    @file Mdl_SafetyAdapter_RxCfg.h
*    @ingroup Mdl_SafetyAdapter
*    @brief This file contains the configuration of the Mdl_SafetyAdapter component.
*    Auto generated code in RPERIYAS at 2024-11-29 12:02:38.657263
********************************************************************************************************************/
#ifndef MDL_SAFETYADAPTER_RX_CFG_H_
#define MDL_SAFETYADAPTER_RX_CFG_H_

#include "Os_Lcfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Number of signal buffers */
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_BUFFERS                        37U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_BUFFERS                       1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_BUFFERS                       1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_BUFFERS                     1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS              1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_RETENTION_BUFFERS              1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_RETENTION_BUFFERS             1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_RETENTION_BUFFERS             1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS           1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS    1U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG                     1U

/* Number of signal status bytes*/ 

#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES                   5U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES              5U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES            5U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES                  1U

 /* Number of signal invalid */ 

#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS                   1U
#define MDL_SAFETYADAPTER_RXCAN_NO_INVALDID_SIGNAL                       MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS
/* Number of signal missing */
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_SIGNALS                   eEndOfRxSafeSignal
/* Main function runnable time */
#define MDL_SAFETYADAPTER_RXCAN_MAINFUNCTION_TIME_IN_MS                  10U
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_FUNCT                     37U
#define MDL_SAFETYADAPTER_RXCAN_NO_GET_SIG_FUNCT_IDX                     MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_FUNCT 
#define MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT               1U
#define MDL_SAFETYADAPTER_RXCAN_NO_GET_SIG_U8ARR_FUNCT_IDX               MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT 

#define MDL_SAFETYADAPTER_RXCAN_SIG_NR_ENABLE              0x01U
#define MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_ENABLE         0x02U
#define MDL_SAFETYADAPTER_RXCAN_SIG_INVALID_ENABLE         0x04U
#define MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_ENABLE       0x08U
#define MDL_SAFETYADAPTER_RXCAN_SIG_ISO_SUPPORTED          0x10U
#define MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_OW_SUPPORTED   0x20U      /*FaultHandling_Nissan_Toyota*/
#define MDL_SAFETYADAPTER_RXCAN_SIG_INVALID_OW_SUPPORTED   0x40U      /*FaultHandling_Nissan_Toyota*/

#define MDL_SAFETYADAPTER_SET_BIT(datau8,bitpos)     ((datau8) |= (uint8)(1u<<(bitpos))) 
#define MDL_SAFETYADAPTER_CLEAR_BIT(datau8,bitpos)   ((datau8) &= (uint8)(~(1U << (bitpos))))  
#define MDL_SAFETYADAPTER_IS_BIT_SET(datau8,bitpos)  ((( (datau8) & ((uint8)(1u<<(bitpos)))) != 0U) ? TRUE : FALSE) 

/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
typedef void(* Mdl_SafetyAdapter_RxCanGetSignalFunctPtrType)(uint8 *pSignalValue);
typedef void(* Mdl_SafetyAdapter_RxCanGetSignalU8ArrFunctPtrType)(uint8 *pSignalValue,uint32 *pSignalLength);
typedef boolean(*Mdl_SafetyAdapter_RxCanSignalInvalidCheckFuncPtrType)(void);

typedef uint8 Mdl_SafetyAdapter_RxCanSigMonitoringType;

typedef struct
{
    uint16   SignalLengthInByte;
    uint16   SignalBufferStartIdx;
    uint16   SignalInvalidIdx;
    uint16 	 SignalGetFunctIdx;
    Mdl_SafetyAdapter_RxCanSigMonitoringType RxSigMonitoringType;
    uint32  SignalMissingCounterValue;
    uint32  SignalMissingOWValue;
    uint32 SignalInvalidOWValue;
}Mdl_SafetyAdapter_RxCanSignalConfigType;

typedef struct
{
    Mdl_SafetyAdapter_RxCanGetSignalFunctPtrType    pGetSignalFunct;
}Mdl_SafetyAdapter_RxCanGetSignalFunctConfigType;

typedef struct
{
    uint16 SignalU8ArrBufferLenIdx;
    Mdl_SafetyAdapter_RxCanGetSignalU8ArrFunctPtrType    pGetSignalU8ArrFunct;
}Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfigType;

typedef struct
{
    uint32 SignalInvalidSigIdx;
    uint32 SignalInvalidCounterValue;
    Mdl_SafetyAdapter_RxCanSignalInvalidCheckFuncPtrType pSignalInvalidCheckFunc;
}Mdl_SafetyAdapter_RxCanSignalInvalidConfigType;

/********************************************************************************************************************
*  PUBLIC CONSTANT AND VARIABLE DECLARTAION                                                                         *
********************************************************************************************************************/
extern const Mdl_SafetyAdapter_RxCanGetSignalFunctConfigType Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_FUNCT];
extern const Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfigType Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG];
extern const Mdl_SafetyAdapter_RxCanSignalConfigType Mdl_SafetyAdapter_RxCanSignalConfig[eEndOfRxSafeSignal];
extern const Mdl_SafetyAdapter_RxCanSignalInvalidConfigType Mdl_SafetyAdapter_RxCanSignalInvalidConfig[MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS]; 
extern uint8 Mdl_SafetyAdapter_RxCanSignalNRStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES];
extern uint8 Mdl_SafetyAdapter_RxCanSignalMissingStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
extern uint8 Mdl_SafetyAdapter_RxCanJustRcvdStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPE                                                                         			    *
********************************************************************************************************************/


#ifdef MDL_SAFETYADAPTER_RXCAN_ISO_SIGNAL_SUPPORTED
/*!******************************************************************************************************************
*   @brief   Main function for the Mdl_SafetyAdapter_RxIso . Should be called in every
*   \MDL_SAFETYADAPTER_RXCAN_MAINFUNCTION_TIME_IN_MS. It process Iso signals
********************************************************************************************************************/

extern void Mdl_SafetyAdapter_RxIsoMainFunction(void);
#endif
/*!******************************************************************************************************************
*   On data rx function for the iso signals
********************************************************************************************************************/


/*!******************************************************************************************************************
*   Rx Get functions for the signals
********************************************************************************************************************/
extern void Mdl_SafetyAdapter_RxCanGetSCSBZR(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetSCSACCEL(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetPBKLAB(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetDBKLAB(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetAB(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_PKBLP(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_EPBWL(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_EPBMID(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_CPKB(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetVSCOFF(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetVSCEXIST(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetTRCOFF(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetSLP_WL(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetMCBW(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetECBEXIST(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetEBW_MID(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetBRK_MID(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetBHEXIST(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_EBW(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_DAINDP(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_DAINDC(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_DACIND(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BUZZER(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BRLV(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BRKW(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_ALSD(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_ABS(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetABS_MID(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetPWIINFO(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetTRCCONRR(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetTRCCONRL(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetTRCCONFR(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetTRCCONFL(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_EBW2(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BUZZE2(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BRLV2(uint8 * pSignalValue);
extern void Mdl_SafetyAdapter_RxCanGetB_BRKW2(uint8 * pSignalValue);

/* Signal Invalid check function */


/********************************************************************************************************************
*  Below are the set of signals that can be received via CMdl_SafetyAdapter_RxCan_GetSignalValue API               			    *
********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
   eSCSBZRIn      0     SCSBZR      ABG1S01
   eSCSACCELIn    1     SCSACCEL    ABG1S01
   ePBKLABIn      2     PBKLAB      ABG1S01
   eDBKLABIn      3     DBKLAB      ABG1S01
   eABIn          4     AB          ABG1S01
   eB_PKBLPIn     5     B_PKBLP     EPB1F01
   eB_EPBWLIn     6     B_EPBWL     EPB1F01
   eB_EPBMIDIn    7     B_EPBMID    EPB1F01
   eB_CPKBIn      8     B_CPKB      VSC1S95
   eVSCOFFIn      9     VSCOFF      VSC1S95
   eVSCEXISTIn    10    VSCEXIST    VSC1S95
   eTRCOFFIn      11    TRCOFF      VSC1S95
   eSLP_WLIn      12    SLP_WL      VSC1S95
   eMCBWIn        13    MCBW        VSC1S95
   eECBEXISTIn    14    ECBEXIST    VSC1S95
   eEBW_MIDIn     15    EBW_MID     VSC1S95
   eBRK_MIDIn     16    BRK_MID     VSC1S95
   eBHEXISTIn     17    BHEXIST     VSC1S95
   eB_EBWIn       18    B_EBW       VSC1S95
   eB_DAINDPIn    19    B_DAINDP    VSC1S95
   eB_DAINDCIn    20    B_DAINDC    VSC1S95
   eB_DACINDIn    21    B_DACIND    VSC1S95
   eB_BUZZERIn    22    B_BUZZER    VSC1S95
   eB_BRLVIn      23    B_BRLV      VSC1S95
   eB_BRKWIn      24    B_BRKW      VSC1S95
   eB_ALSDIn      25    B_ALSD      VSC1S95
   eB_ABSIn       26    B_ABS       VSC1S95
   eABS_MIDIn     27    ABS_MID     VSC1S95
   ePWIINFOIn     28    PWIINFO     VSC1S96
   eTRCCONRRIn    29    TRCCONRR    VSC1S96
   eTRCCONRLIn    30    TRCCONRL    VSC1S96
   eTRCCONFRIn    31    TRCCONFR    VSC1S96
   eTRCCONFLIn    32    TRCCONFL    VSC1S96
   eB_EBW2In      33    B_EBW2      VSC1S97
   eB_BUZZE2In    34    B_BUZZE2    VSC1S97
   eB_BRLV2In     35    B_BRLV2     VSC1S97
   eB_BRKW2In     36    B_BRKW2     VSC1S97
*/


/********************************************************************************************************************
*  Below are the set of signals that can be received via CMdl_SafetyAdapter_RxCan_GetSignalValueU8Arr API          			    *
********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
*/

#endif /* MDL_SAFETYADAPTER_RX_CFG_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


