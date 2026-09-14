//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon ComMExt Configurator 1.0
// Date:           Fri Nov 30 15:55:52 IST 2018
// User:           EASHOK
// Configuration:  SP2
// Comment:
//      ComMExt configuration
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef COMMEXT_CFG_H
#define COMMEXT_CFG_H

/**********************************************************************************************************************
*  Include Files                                                                                                      *
*********************************************************************************************************************/
#include "Std_Types.h"
//#include "Dio.h"
#include "Com.h"


/**********************************************************************************************************************
 * Is CAN supported
 *********************************************************************************************************************/
/*Configure whether CAN module supported */
#define COMMEXT_IS_CAN_SUPPORTED                          STD_ON

/**********************************************************************************************************************
 * COM TX and RX IPDU group references for CAN channels
 *********************************************************************************************************************/
/*!
*@brief Configure Receive PDU group of CAN channel 0
*/
#define COMMEXT_CAN_RX_IPDU_GROUP_CHANNEL_0               (COM_IPDU_GROUP_VCAN_RX)
#define COMMEXT_CAN_RX_IPDU_GROUP_CHANNEL_1               (COM_IPDU_GROUP_MCAN_RX)
/*!
*@brief Configure Transmit PDU group of CAN channel 0
*/
#define COMMEXT_CAN_TX_IPDU_GROUP_CHANNEL_0               (COM_IPDU_GROUP_VCAN_TX)
#define COMMEXT_CAN_TX_IPDU_GROUP_CHANNEL_1               (COM_IPDU_GROUP_MCAN_TX)
/*Configure Number of COM channels present including CAN, LIN, etc.,*/
#define COMMEXT_NUMBER_OF_COM_CHANNELS                    (COMMEXT_NUMBER_OF_CAN_CHANNELS)

#if (COMMEXT_IS_CAN_SUPPORTED == STD_ON)
/**********************************************************************************************************************
 * Number of CAN channels
 *********************************************************************************************************************/
/* Configure Number of CAN channels present. Maximum 3 channels supported */
#define COMMEXT_NUMBER_OF_CAN_CHANNELS                    1u

/* Configure Wake up validation support */
#define COMMEXT_CAN_WAKEUP_VALIDATION_SUPPORT             STD_OFF
#endif /* (COMMEXT_IS_CAN_SUPPORTED == STD_ON) */

/*Configure whether CAN NM module supported */
#define COMMEXT_IS_NM_SUPPORTED                           STD_OFF

/*External interrupt support for CAN channels*/
#define COMMEXT_EXT_INTR_SUPPORT                          STD_OFF

/*Configure Wake up validation support*/
#define COMMEXT_CAN_WAKEUP_VALIDATION_SUPPORT             STD_OFF

/*Configure IPDU group actviation at communication request support*/
#define COMMEXT_COM_IPDUGROUP_ACT_SUPPORT                 STD_ON

/*Configure Tramsit IPDU support*/
#define COMMEXT_COM_TX_IPDU_SUPPORT                       STD_ON

/*Configure Receive IPDU support*/
#define COMMEXT_COM_RX_IPDU_SUPPORT                       STD_ON

/*Configure Tansceiver support*/
#define COMMEXT_IS_TRCV_SUPPORTED                         STD_OFF

 /*Configure Nm Cdd support*/
#define COMMEXT_IS_NMCDD_SUPPORTED                        STD_OFF

 /*Configure ComMExt interfaces Test support*/
#define COMMEXT_TEST_FEATURE_SUPPORTED                    STD_OFF

/**********************************************************************************************************************
 * External interrupt function interfaces
 *********************************************************************************************************************/
#if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
/* Function to disable ICU channel interrupt \n
For functional safety SIP, call should be routed through Os Trusted Stub function for accessing from Non Trusted Application*/
#define ComMExt_IcuChannelInterruptDisable(Channel)       (void)McuExt_IcuChannelInterruptDisable(Channel)

/*Function to enable ICU channel interrupt \n
For functional safety SIP, call should be routed through Os Trusted Stub function for accessing from Non Trusted Application*/
#define ComMExt_IcuChannelInterruptEnable(Channel)        (void)McuExt_IcuChannelInterruptEnable(Channel)
#endif

/**********************************************************************************************************************
 * COM TX and RX IPDU group references for COM channels
 *********************************************************************************************************************/
#define COMMEXT_NUMBER_OF_IPDU_GROUPS                     (COM_SUPPORTED_IPDU_GROUPS)
#define COMMEXT_NUMBER_OF_TX_IPDU_GROUPS                  1U
#define COMMEXT_NUMBER_OF_RX_IPDU_GROUPS                  1U

/**********************************************************************************************************************
 * Program specific defines
 *********************************************************************************************************************/
/* Configure Channel number */
#define VCAN_CHANNEL 0

#define COMMEXT_CHANNEL_CAN1                    0U
#define COMMEXT_CHANNEL_CAN2_DIAG               1U

#define COMMEXT_NUM_OF_GATEWAY_MSG              0U

#define COMMEXT_BCM_NM_PDU_CAN_ID               ((uint16)0x500)
#define COMMEXT_IPC_DiagRequest_CAN2_DIAG_ID    ((uint16)0x700)
#define COMMEXT_DiagState1_CAN2_ID              ((uint16)0x7D0)
#define COMMEXT_DiagState3_CAN2_ID              ((uint16)0x7DF)

#define COMMEXT_EMS2_CAN2_GWAY_CAN_ID           ((uint16)0x280)
#define COMMEXT_EMS4_CAN2_GWAY_CAN_ID           ((uint16)0x284)
#define COMMEXT_SRS1_CAN2_GWAY_CAN_ID           ((uint16)0x103)


#if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
/*Function pointer of CAN channels dedicated external interrupt function*/
typedef void (*ComMExt_SetPinToExtInterruptFctType)(void); /* MISRA warning fix, CID 10448862 */

/* Function pointer of CAN channels interrupt function defined in EcuMExt */
typedef void (*ComMExt_SetIntrDetectedFctType)(void); /* MISRA warning fix, CID 10458339 */
#endif

/* Store CAN channels receive PDU group */
typedef struct
{
    boolean             CtrlOnRequest; /*Ipdu to be enabled in request full comm invocation*/
    Com_IpduGroupIdType IpduGroupId;
}ComMExt_IpduGroupIdConfigType;

/* Store Channel Configuration */
typedef struct
{

#if (COMMEXT_COM_TX_IPDU_SUPPORT == STD_ON)
    uint8                                           ComTxpduGroupStart;             //0u
    uint8                                           ComTxpduGroupEnd;               //0u
#endif
#if (COMMEXT_COM_RX_IPDU_SUPPORT == STD_ON)
    uint8                                           ComRxpduGroupStart;             //1u
    uint8                                           ComRxpduGroupEnd;               //1u
#endif
#if (COMMEXT_IS_NM_SUPPORTED == STD_ON)
    boolean                                         NmSupport;                      //TRUE or FALSE
#if (COMMEXT_IS_NMCDD_SUPPORTED == STD_ON)
    boolean                                         NmCddSupport;                   //TRUE or FALSE
#endif
#endif
#if (COMMEXT_IS_TRCV_SUPPORTED == STD_ON)
    boolean                                         TrcvSupport;                    //TRUE or FALSE
    uint16                                          DioTrcvStbPinRef;               //DIO_RX_CHANNEL_0 or 0xFFu
    uint16                                          DioTrcvEnPinRef;                //DIO_RX_CHANNEL_0 or 0xFFu
    boolean                                         TrcvNormalStbVal;               //STD_LOW or STD_HIGH
    boolean                                         TrcvNormalEnVal;                //STD_LOW or STD_HIGH
    boolean                                         TrcvStandbyStbVal;              //STD_LOW or STD_HIGH
    boolean                                         TrcvStandbyEnVal;               //STD_LOW or STD_HIGH
#endif
#if (COMMEXT_EXT_INTR_SUPPORT == STD_ON)
    uint16                                          DioRxPinRef;                    //DIO_RX_CHANNEL_0 or 0xFFu
    uint8                                           IcuChannelRef;                  //ICU_CHANNEL_0 or 0xFFu
    ComMExt_SetPinToExtInterruptFctType             ExtIntrFuncRef;                 //MCUEXT_CAN_SET_EINT_CHANNEL_0
    ComMExt_SetIntrDetectedFctType                  IntrDetectedFuncRef;            //EcuMExt_BCANRxIntDetected
#endif
#if (COMMEXT_CAN_WAKEUP_VALIDATION_SUPPORT == STD_ON)
    uint8                                           WakeUpChannel;                  //CAN_CHANNEL_NUMBER
    uint16                                          WakeUpValidationTime;           //100u
    uint8                                           WakeUpValidatedNotifyFunc;      //App_ValidateWakeUpEvent
#endif
}ComMExt_ChannelConfigType;

#if (COMMEXT_COM_RX_IPDU_SUPPORT == STD_ON)
/* Store CAN channels receive PDU group */
extern ComMExt_IpduGroupIdConfigType Com_RxIpduGroupIdConfig[COMMEXT_NUMBER_OF_RX_IPDU_GROUPS];
#endif
#if (COMMEXT_COM_TX_IPDU_SUPPORT == STD_ON)
/*Store CAN channels transmit PDU group */
extern ComMExt_IpduGroupIdConfigType Com_TxIpduGroupIdConfig[COMMEXT_NUMBER_OF_TX_IPDU_GROUPS];
#endif

/*Store Channel Configuration*/
extern const ComMExt_ChannelConfigType ComMExt_ChannelConfig[COMMEXT_NUMBER_OF_COM_CHANNELS];

/**********************************************************************************************************************
 * Program specific configurations and interfaces
 *********************************************************************************************************************/
/* Bus Off Status Configuration */
Std_ReturnType ComMExtCfg_GetBusOffStatus(uint8 ChannelId, boolean* BusOffStatus);
/*Bus off start function*/
extern void ComMExtCfg_CanBusoffBegin(NetworkHandleType Network, uint8* pDelayCycle);
/*Bus off stop function*/
extern void ComMExtCfg_BusoffEnd(NetworkHandleType Network);

#endif /*COMMEXT_CFG_H*/
