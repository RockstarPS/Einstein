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
 *    @file ComAbsMdl_RxCfg.h
 *    @ingroup ComAbsMdl
 *    @brief This file contains the configuration of the ComAbsMdl component.
 *    Auto generated code in ABASAVAR at 2025-06-25 16:07:17.614086
 ********************************************************************************************************************/
#ifndef COMABSMDL_RX_CFG_H_
#define COMABSMDL_RX_CFG_H_

/********************************************************************************************************************
 *  PUBLIC MACRO DEFINITIONS                                                                                         *
 ********************************************************************************************************************/
/********************************************************************************************************************
 *  PUBLIC MACRO DEFINITIONS                                                                                         *
 ********************************************************************************************************************/
/* Number of signal buffers */
#define COMABSMDL_RXCAN_NUM_OF_U8_BUFFERS                        11U
#define COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS                       1U
#define COMABSMDL_RXCAN_NUM_OF_U32_BUFFERS                       1U
#define COMABSMDL_RXCAN_NUM_OF_U8ARR_BUFFERS                     1U
#define COMABSMDL_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS              1U
#define COMABSMDL_RXCAN_NUM_OF_U8_RETENTION_BUFFERS              1U
#define COMABSMDL_RXCAN_NUM_OF_U16_RETENTION_BUFFERS             1U
#define COMABSMDL_RXCAN_NUM_OF_U32_RETENTION_BUFFERS             1U
#define COMABSMDL_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS           1U
#define COMABSMDL_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS    1U
#define COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG                     1U

/* Number of signal status bytes*/

#define COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES 2U
#define COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES 2U
#define COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES 2U
#define COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES 1U

/* Number of signal invalid */

#define COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS 1U
#define COMABSMDL_RXCAN_NO_INVALDID_SIGNAL COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS
/* Number of signal missing */
#define COMABSMDL_RXCAN_NUM_OF_MISSING_SIGNALS eEndOfRxSignal
/* Main function runnable time */
#define COMABSMDL_RXCAN_MAINFUNCTION_TIME_IN_MS 10U
#define COMABSMDL_RXCAN_NUM_OF_GET_SIG_FUNCT 12U
#define COMABSMDL_RXCAN_NO_GET_SIG_FUNCT_IDX COMABSMDL_RXCAN_NUM_OF_GET_SIG_FUNCT
#define COMABSMDL_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT 1U
#define COMABSMDL_RXCAN_NO_GET_SIG_U8ARR_FUNCT_IDX COMABSMDL_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT

#define COMABSMDL_RXCAN_SIG_NR_ENABLE 0x01U
#define COMABSMDL_RXCAN_SIG_MISSING_ENABLE 0x02U
#define COMABSMDL_RXCAN_SIG_INVALID_ENABLE 0x04U
#define COMABSMDL_RXCAN_SIG_RETENTION_ENABLE 0x08U
#define COMABSMDL_RXCAN_SIG_ISO_SUPPORTED 0x10U

#define COMABSMDL_SET_BIT(datau8, bitpos) ((datau8) |= (uint8)(1u << (bitpos)))
#define COMABSMDL_CLEAR_BIT(datau8, bitpos) ((datau8) &= (uint8)(~(1U << (bitpos))))
#define COMABSMDL_IS_BIT_SET(datau8, bitpos) ((((datau8) & ((uint8)(1u << (bitpos)))) != 0U) ? TRUE : FALSE)

/********************************************************************************************************************
 *  PUBLIC TYPE DEFINITIONS                                                                                         *
 ********************************************************************************************************************/
typedef void (*ComAbsMdl_RxCanGetSignalFunctPtrType)(uint8 *pSignalValue);
typedef void (*ComAbsMdl_RxCanGetSignalU8ArrFunctPtrType)(uint8 *pSignalValue, uint32 *pSignalLength);
typedef boolean (*ComAbsMdl_RxCanSignalInvalidCheckFuncPtrType)(void);

typedef uint8 ComAbsMdl_RxCanSigMonitoringType;

typedef struct
{
    uint16 SignalLengthInByte;
    uint16 SignalBufferStartIdx;
    uint16 SignalInvalidIdx;
    uint16 SignalGetFunctIdx;
    ComAbsMdl_RxCanSigMonitoringType RxSigMonitoringType;
    uint32 SignalMissingCounterValue;
} ComAbsMdl_RxCanSignalConfigType;

typedef struct
{
    ComAbsMdl_RxCanGetSignalFunctPtrType pGetSignalFunct;
} ComAbsMdl_RxCanGetSignalFunctConfigType;

typedef struct
{
    uint16 SignalU8ArrBufferLenIdx;
    ComAbsMdl_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunct;
} ComAbsMdl_RxCanGetSignalU8ArrConfigType;

typedef struct
{
    uint32 SignalInvalidSigIdx;
    uint32 SignalInvalidCounterValue;
    ComAbsMdl_RxCanSignalInvalidCheckFuncPtrType pSignalInvalidCheckFunc;
} ComAbsMdl_RxCanSignalInvalidConfigType;

/********************************************************************************************************************
 *  PUBLIC CONSTANT AND VARIABLE DECLARTAION                                                                         *
 ********************************************************************************************************************/
extern const ComAbsMdl_RxCanGetSignalFunctConfigType ComAbsMdl_RxCanGetSignalFunctConfig[COMABSMDL_RXCAN_NUM_OF_GET_SIG_FUNCT];
extern const ComAbsMdl_RxCanGetSignalU8ArrConfigType ComAbsMdl_RxCanGetSignalU8ArrConfig[COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG];
extern const ComAbsMdl_RxCanSignalConfigType ComAbsMdl_RxCanSignalConfig[eEndOfRxSignal];
extern const ComAbsMdl_RxCanSignalInvalidConfigType ComAbsMdl_RxCanSignalInvalidConfig[COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS];
extern uint8 ComAbsMdl_RxCanSignalNRStatus[COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES];
extern uint8 ComAbsMdl_RxCanSignalMissingStatus[COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
extern uint8 ComAbsMdl_RxCanJustRcvdStatus[COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];

/********************************************************************************************************************
 *  PUBLIC FUNCTION PROTOTYPE                                                                         			    *
 ********************************************************************************************************************/

#ifdef COMABSMDL_RXCAN_ISO_SIGNAL_SUPPORTED
/*!******************************************************************************************************************
 *   @brief   Main function for the ComAbsMdl_RxIso . Should be called in every
 *   \COMABSMDL_RXCAN_MAINFUNCTION_TIME_IN_MS. It process Iso signals
 ********************************************************************************************************************/

extern void ComAbsMdl_RxIsoMainFunction(void);
#endif
/*!******************************************************************************************************************
 *   On data rx function for the iso signals
 ********************************************************************************************************************/

/*!******************************************************************************************************************
*   Rx Get functions for the signals
********************************************************************************************************************/
extern void ComAbsMdl_RxCanGetDayNightMode(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetIllumination_level(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetAmbient_Light_level(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetPowerMode(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetTransportMode(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetGearMode(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetGearRecommendation(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetGear(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetWarning(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetGearStatus(uint8 * pSignalValue);
extern void ComAbsMdl_RxCanGetEngineSpeed(uint16 * pSignalValue);
extern void ComAbsMdl_RxCanGetTurn_Indicator_Control(uint8 * pSignalValue);

/* Signal Invalid check function */
void CComAbsMdl_OnDataRx_DayNightMode(void);
void CComAbsMdl_OnDataRx_PowerMode(void);

/********************************************************************************************************************
 *  Below are the set of signals that can be received via CComAbsMdl_RxCan_GetSignalValue API               			    *
 ********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
   =CONCATENATE("e",A2,"In")     0     DayNightMode              Illum_control
   =CONCATENATE("e",A3,"In")     1     Illumination_level        Illum_control
   =CONCATENATE("e",A4,"In")     2     Ambient_Light_level       Illum_control
   =CONCATENATE("e",A5,"In")     3     PowerMode                 VehicleControl
   =CONCATENATE("e",A6,"In")     4     TransportMode             VehicleControl
   =CONCATENATE("e",A7,"In")     5     GearMode                  VehicleControl
   =CONCATENATE("e",A8,"In")     6     GearRecommendation        VehicleControl
   =CONCATENATE("e",A9,"In")     7     Gear                      VehicleControl
   =CONCATENATE("e",A10,"In")    8     Warning                   VehicleControl
   =CONCATENATE("e",A11,"In")    9     GearStatus                VehicleControl
   =CONCATENATE("e",A12,"In")    10    EngineSpeed               VehicleControl
   eTurn_Indicator_ControlIn     11    Turn_Indicator_Control    VehicleControl
*/

/********************************************************************************************************************
 *  Below are the set of signals that can be received via CComAbsMdl_RxCan_GetSignalValueU8Arr API          			    *
 ********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
 */

#endif /* COMABSMDL_RX_CFG_H_ */

/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
