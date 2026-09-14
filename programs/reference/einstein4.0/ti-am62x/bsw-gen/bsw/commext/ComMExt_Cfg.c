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
// Configuration:  BEV
// Comment:
//      ComMExt configuration
//
//---------------------------------------------------------------------------------------------------------------------
#include "ComMExt.h"
#include "ComStack_Types.h"
#include "Com_Cfg.h"
void ComMExt_Local_MainFunction(void);
#if (COMMEXT_COM_RX_IPDU_SUPPORT == STD_ON)
/*  Store COM channels receive PDU group */
ComMExt_IpduGroupIdConfigType Com_RxIpduGroupIdConfig[COMMEXT_NUMBER_OF_RX_IPDU_GROUPS] =
{
    {TRUE,COM_IPDU_GROUP_PDUGROUP_CAN0_RX}
};
#endif

#if (COMMEXT_COM_TX_IPDU_SUPPORT == STD_ON)
/* Store COM channels transmit PDU group */
ComMExt_IpduGroupIdConfigType Com_TxIpduGroupIdConfig[COMMEXT_NUMBER_OF_TX_IPDU_GROUPS] =
{
    {TRUE,COM_IPDU_GROUP_PDUGROUP_CAN0_TX}
};
#endif

/* Store Channel Configuration values */
const ComMExt_ChannelConfigType ComMExt_ChannelConfig[COMMEXT_NUMBER_OF_COM_CHANNELS]=
{  
    {
        0u,
        0u,
        1u,
        1u
    }
};

/* Program specific variables declaration */
static boolean VCAN_StatusFlag = FALSE;   /* MD_MSR_15.7 */
//static boolean MCAN_StatusFlag = FALSE;

#if (COMMEXT_TEST_FEATURE_SUPPORTED == STD_ON)
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateRx(ComMExt_IpduGroupId GroupId);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlActivateRx(ComMExt_IpduGroupId GroupId);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateTx(ComMExt_IpduGroupId GroupId);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlActivateTx(ComMExt_IpduGroupId GroupId);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlSetDone(boolean PduInitRequest);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel);
extern Std_ReturnType ComMExt_GetBusOffStatus(uint8 Channel, boolean* BusOffStatus);
#endif
/*!***************************************************************************************************************
**
** @brief             ComMExt 10ms stub periodic function
**
** Function Name    : ComMExt_Local_MainFunction
**
** Visibility       : Public
**
** Invocation       : Called periodically from ComMExt_Impl_MainFunction on 10ms periodic event
**
** Critical Section : None
**
** @param[in]         None
**
** @param[out]        None
**
** @return            None
**
** @ingroup           ComMExt
**
*****************************************************************************************************************/


void ComMExt_Local_MainFunction(void)
{
    // Invoke Runnables of modules which are not supported in DaVinci. Avoid manual update in Rte( DaVinci generated)
#if (COMMEXT_TEST_FEATURE_SUPPORTED == STD_ON)
    static uint8 action = 7u;
    static uint8 ch = 0u;
    //testing vautosar tx rx message
    static uint8 status;
    static boolean bo_status;
    static uint8 sigu8 = 0u;
    static uint8 sigu8_1 = 0u;
    static uint8 sigu8_2 = 0u;
    static uint8 sigu8_3 = 0u;
    static uint8 sigu8_4 = 0u;
    static uint8 sigu8_5 = 1u; //garumug1
    static uint8 sigu8_6 = 1u; //garumug1
    static uint8 sigu8_7 = 1u; //garumug1
    static uint16 sigu16 = 0u;
    static uint16 sigu16_1 = 0u;
    static uint32 sigu32 = 0u;
    static uint32 sigu32_1 = 0u;
    static uint32 sigu32_2 = 0x1234567;
    static uint8 sigu8_arr[8] = {0u};


    if(action==1u)
    {
        ComMExt_CAN_ActivateSilentCommunication(ch);
        action = 0u;
    }
    else if(action==2u)
    {
        ComMExt_CAN_DeActivateSilentCommunication(ch);
        action = 0u;
    }
    else if(action==3u)
    {
        // All CH TX and RX suspend
        ComMExt_CAN_CommControlDeActivateTx(0);
        ComMExt_CAN_CommControlDeActivateRx(1);
        ComMExt_CAN_CommControlSetDone(TRUE);
        action = 0u;
    }
    else if(action==4u)
    {
        // All TX suspend
        ComMExt_CAN_CommControlDeActivateTx(0);
        ComMExt_CAN_CommControlActivateRx(1);
        ComMExt_CAN_CommControlSetDone(TRUE);
        action = 0u;
    }
    else if(action==5u)
    {
        // All RX suspend
        ComMExt_CAN_CommControlActivateTx(0);
        ComMExt_CAN_CommControlDeActivateRx(1);
        ComMExt_CAN_CommControlSetDone(TRUE);
        action = 0u;
    }
    else if(action==6u)
    {
        // All TX and RX resume
        ComMExt_CAN_CommControlActivateTx(0);
        ComMExt_CAN_CommControlActivateRx(1);
        ComMExt_CAN_CommControlSetDone(TRUE);
        action = 0u;
    }
    else if(action==7u)
    {
        status = ComMExt_CAN_RequestCommunication(0);
        status = ComMExt_CAN_RequestCommunication(1);
        action = 0u;
    }
    else if(action==8u)
    {
        status = ComMExt_CAN_ReleaseCommunication(0);
        status = ComMExt_CAN_ReleaseCommunication(1);
    }
    else if(action==9u)
    {
        status = ComMExt_GetBusOffStatus(0,&bo_status);
    }
    else if(action==29u)
    {

        // status = Com_SendSignal(COM_SIGNAL_FTOOLS_METERTOCGW_2615079505_43BD, (&sigu8_arr[0]));
       /* status = Com_SendSignal(COM_SIGNAL_SIGMA_DTCMETER_2563508067_F434, (&sigu32));
        status = Com_SendSignal(COM_SIGNAL_SIGMA_METER_2563508067_49BE, (&sigu32));
        status = Com_SendSignal(COM_SIGNAL_AUTOLOCKACTIVATIONREQ_1491_E06E, (&sigu16_1));
        status = Com_SendSignal(COM_SIGNAL_INTERNALLIGHTINGINTENSITYREQUEST_1165_349A, (&sigu8)); Pdharane */


        /*
        RecieveSignal(Tx message signals)
        (1,27)ComConf_ComSignal_MemorizedDistanceTotalizer_0eaa6e21
        (2,17)ComConf_ComSignal_TripDistanceHEV_c90a0455 [meter_a8]
        (3,11)ComConf_ComSignal_DistanceToEmptyTank_aa04680a[Meter_A107]
        (4,10)ComConf_ComSignal_RawFuelGaugeResistance_5e4b4c19
        (5,7)ComConf_ComSignal_FuelLevelDisplayed_5e4b4c19
        (6,5)ComConf_ComSignal_HUD_NightLuminosityRequest_1661afe5
        SendSignal(Rx message signals)
        (1,28)ComConf_ComSignal_DistanceTotalizer_3a07d954
        (2,16)ComConf_ComSignal_VehicleSpeed_29cdb325 [VDC_A9(28A)]
        (3,12)ComConf_ComSignal_VehicleSpeedDisplayedinmph_2309048c[ECM_116(472)]
        (4,10)ComConf_ComSignal_SCR_DistanceAutonomyDisplay_36ac238f
        (5,7)ComConf_ComSignal_VCR_CompressionRatio_b49615a5
        (6,5)ComConf_ComSignal_TSR_OSP_TrafficSignZone3_3793bbe2
        */
        // (void)status;
    }
    else if(action==11u)
    {
       /* status = Com_ReceiveSignal(COM_SIGNAL_ADBCAUTIONDISPLAY_1130_B9B2, (&sigu8));
        status = Com_ReceiveSignal(COM_SIGNAL_APB_BRAKEPEDALREQUESTDISPLAY_964_C88C, (&sigu8_1));
        status = Com_ReceiveSignal(COM_SIGNAL_CLOCK_EBA_A2_939_37A1, (&sigu8_2));
        status = Com_ReceiveSignal(COM_SIGNAL_TSR_OSP_TRAFFICSIGNZONE3_1303_E787, (&sigu8_3));
        status = Com_ReceiveSignal(COM_SIGNAL_MINELECPOWERDISPLAY_1152_8B9F, (&sigu8_4)); pdharane*/
        // status = Com_ReceiveSignal(COM_SIGNAL_TORQUEDISTRIBUTIONRATIODISPLAY_969_2AAA, (&sigu16));
      /* status = Com_ReceiveSignal(COM_SIGNAL_VEHICLESPEEDDISPLAYEDINKMH_1052_C506, (&sigu16_1));
        status = Com_ReceiveSignal(COM_SIGNAL_DISTANCETOTALIZER_1080_DCFA, (&sigu32));
        status = Com_ReceiveSignal(COM_SIGNAL_SIGMA_DTCIDM_2563507968_EED3, (&sigu32_1));
        status = Com_ReceiveSignal(COM_SIGNAL_GAINECODISTANCEDISPLAY_1783_03C2, (&sigu32_2));pdharane */
    }
    else if(action == 12u)
    {
       /* Tx */
     //   status = Com_SendSignal(COM_SIGNAL_TSR_OSPACTIVATIONREQUEST_1516_E3D5, (&sigu8_6)); 0x5EC MD_MSR_3.1
       // status = Com_SendSignal(COM_SIGNAL_MEMORIZEDDISTANCETOTALIZER_879_ED48, (&sigu32_2));  0x36F MD_MSR_3.1
       // status = Com_SendSignal(COM_SIGNAL_AUTOFRONTWIPERACTIVATIONREQUEST_1491_C5FB, (&sigu8_5)); 0x5D3   MD_MSR_3.1
       // status = Com_SendSignal(COM_SIGNAL_BSWSON_ACTIVATIONREQUEST_1530_3097, (&sigu8_7));  0x5FA MD_MSR_3.1
       // status = Com_SendSignal(COM_SIGNAL_ADB_ACTIVATIONREQUEST_1720_9107, (&sigu8_7)); 0x6B8 MD_MSR_3.1
       // status = Com_SendSignal(COM_SIGNAL_PBDMAINSWITCHACTIVATIONREQUEST_1762_2EAA, (&sigu8_7));  0x6E2 MD_MSR_3.1
        
        // CanIf_Transmit(0,(const PduInfoType *)&mcanstubptr);
        // CanIf_Transmit(1,(const PduInfoType *)&mcanstubptr);
        // CanIf_Transmit(2,(const PduInfoType *)&mcanstubptr);
        // CanIf_Transmit(3,(const PduInfoType *)&mcanstubptr);
        // CanIf_Transmit(4,(const PduInfoType *)&mcanstubptr);
        action = 0;
    }
#endif
}

Std_ReturnType ComMExtCfg_GetBusOffStatus(uint8 ChannelId, boolean* BusOffStatus)
{
    uint8 RetStatus = E_OK;
    switch (ChannelId)
    {
        case COMM_CHANNEL_VCAN:
            *BusOffStatus = VCAN_StatusFlag;
            break;
        /*case COMM_CHANNEL_MCAN:
            *BusOffStatus = MCAN_StatusFlag;
            break;*/
        default:
            RetStatus = E_NOT_OK;
            break;
    }
    return RetStatus;
}

void ComMExtCfg_CanBusoffBegin(NetworkHandleType Network, uint8* pDelayCycle)
{
    switch (Network)
    {
        case COMM_CHANNEL_VCAN:
            VCAN_StatusFlag = TRUE;
            break;
        /*case COMM_CHANNEL_MCAN:
            MCAN_StatusFlag = TRUE;
            break;*/
        default:
            break;
    }
    *pDelayCycle = 0;
}

void ComMExtCfg_BusoffEnd(NetworkHandleType Network)
{
    switch (Network)
    {
        case COMM_CHANNEL_VCAN:
            VCAN_StatusFlag = FALSE;
            break;
        /*case COMM_CHANNEL_MCAN:
            BCAN_StatusFlag = FALSE;
            break;*/
        default:
            break;
    }
}
