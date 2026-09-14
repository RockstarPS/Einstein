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
*   @file Eth_DrvInit.c
*   @ingroup Eth
*   @brief This file implements the api for testing the ethernet functionality
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "Eth.h"
#include "EthTest.h"
#include "BswM_EthSM.h"
#include "TcpIp.h"
#include "SoAd.h"
#include "SoAd_Cbk.h"
#include "DoIP.h"
#include "PduR_DoIP.h"
#include "DoIP_Cbk.h"
#include "DoIP_Externals.h"
#include "ComM.h"
#include "Eth_DrvInit.h"
#include <string.h>
#include "ComM_EcuMBswM.h"
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#ifdef AUTOSAR_ETH_ENABLE
/* App if pdu id */
#define APP_PDU_UdpServerPduRouteIf         0U
#define APP_PDU_UdpClientPduRouteIf         1U
#define APP_PDU_TcpServerPduRouteIf         2U
#define APP_PDU_TcpClientPduRouteIf         3U
#define APP_NUM_OF_IF_TX_PDU                4U
#define IF_TX_BUFFER_SIZE                   60u
#define APP_PDU_UdpServerPduRouteTp         0U
#define APP_PDU_UdpClientPduRouteTp         1U
#define APP_PDU_TcpServerPduRouteTp         2U
#define APP_PDU_TcpClientPduRouteTp         3U
#define APP_NUM_OF_TP_TX_PDU                4U
#define TP_TX_BUFFER_SIZE                   4096u
/* SoAd Socket route id */
#define APP_PDU_UdpServerSocketRouteIf      0U
#define APP_PDU_UdpClientSocketRouteIf      1U
#define APP_PDU_TcpServerSocketRouteIf      2U
#define APP_PDU_TcpClientSocketRouteIf      3U
#define APP_NUM_OF_IF_RX_PDU                4U
#define IF_RX_BUFFER_SIZE                   60u
#define APP_PDU_UdpServerSocketRouteTp      0U
#define APP_PDU_UdpClientSocketRouteTp      1U
#define APP_PDU_TcpServerSocketRouteTp      2U
#define APP_PDU_TcpClientSocketRouteTp      3U
#define APP_NUM_OF_TP_RX_PDU                4U
#define TP_RX_BUFFER_SIZE                   4096u
#define PDUR_STUB_EN
/** \brief MAC address length in bytes */
#define ETH_HW_ADDR_LEN                 (6U)

/** \brief Total bytes in header */
#define ETH_HDR_LEN                     (14U)

/** \brief Max octets in payload */
#define ETH_PAYLOAD_LEN                 (1500U)

/** \brief VLAN tag length in bytes */
#define ETH_VLAN_TAG_LEN                (4U)

#define ETH_DEFAULT_TX_PRIORITY         (0u)
/** \brief Experimental EtherType used in test packets */
#define ETHERTYPE_EXPERIMENTAL1         (0x88b5U)

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

typedef struct
{
    uint8 dstMac[ETH_HW_ADDR_LEN];
    uint8 srcMac[ETH_HW_ADDR_LEN];
    uint16 etherType;
} __attribute__((packed)) EthFrameHeader;

typedef struct
{
    EthFrameHeader hdr;
    uint8 payload[ETH_PAYLOAD_LEN + ETH_VLAN_TAG_LEN];
} __attribute__((packed)) EthFrame;
extern FUNC(void,SOAD_CODE) SoAd_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) SrcPtr , 
    PduLengthType Length
);
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static uint8 IfTxBuffer[APP_NUM_OF_IF_TX_PDU][IF_TX_BUFFER_SIZE];

static PduIdType IfTxToSoAdPduId[APP_NUM_OF_IF_TX_PDU]=
{
    SOAD_PDU_UdpServerPduRouteIf,
    SOAD_PDU_UdpClientPduRouteIf,
    SOAD_PDU_TcpServerPduRouteIf,
    SOAD_PDU_TcpClientPduRouteIf
};

static uint8 TpTxBuffer[APP_NUM_OF_TP_TX_PDU][TP_TX_BUFFER_SIZE];

static boolean TpTxBufferLock[APP_NUM_OF_TP_TX_PDU] = {FALSE};

static uint16 TpTxBufferRequestLength[APP_NUM_OF_TP_TX_PDU]={0};

static uint16 TpTxBufferCopiedLength[APP_NUM_OF_TP_TX_PDU]={0};

static PduIdType TpTxToSoAdPduId[APP_NUM_OF_TP_TX_PDU]=
{
    SOAD_PDU_UdpServerPduRouteTp,
    SOAD_PDU_UdpClientPduRouteTp,
    SOAD_PDU_TcpServerPduRouteTp,
    SOAD_PDU_TcpClientPduRouteTp
};



#if 0
static uint8 TpRxBuffer[APP_NUM_OF_TP_RX_PDU][TP_RX_BUFFER_SIZE];
static uint8 IfRxBuffer[APP_NUM_OF_IF_RX_PDU][IF_RX_BUFFER_SIZE];

static PduIdType IfRxToSoAdPduId[APP_NUM_OF_IF_RX_PDU]=
{
    SOAD_PDU_UdpServerSocketRouteIf,
    SOAD_PDU_UdpClientSocketRouteIf,
    SOAD_PDU_TcpServerSocketRouteIf,
    SOAD_PDU_TcpClientSocketRouteIf
};

static boolean TpRxBufferLock[APP_NUM_OF_TP_RX_PDU] = {FALSE};

static uint16 TpRxBufferRequestLength[APP_NUM_OF_TP_RX_PDU]={0};

static uint16 TpRxBufferCopiedLength[APP_NUM_OF_TP_RX_PDU]={0};

static PduIdType TpRxToSoAdPduId[APP_NUM_OF_TP_RX_PDU]=
{
    SOAD_PDU_UdpServerSocketRouteTp,
    SOAD_PDU_UdpClientSocketRouteTp,
    SOAD_PDU_TcpServerSocketRouteTp,
    SOAD_PDU_TcpClientSocketRouteTp
};
#endif
static volatile uint32 SoAd_TestCode=0;
static volatile uint32 DoIP_TestNum=0;
static volatile uint32 EthTest_Tx=2;
static volatile uint32 tx_cnt=0;
static uint8 BcastAddr[ETH_HW_ADDR_LEN] =
{
    0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU
};

/* Unicast MAC address */
static uint8 UcastAddr[ETH_HW_ADDR_LEN] =
{
    0xAAU, 0xBBU, 0xCCU, 0xDDU, 0xEEU, 0xFFU
};

static EthFrame frame;
static uint8 UdpEchoBuffer[100];
static uint8 TcpEchoBuffer[100];
static uint8 DoTxUdpServerIf;
static uint8 DoTxTcpServerIf;
static uint16 UdpEchobufferLength;
static uint16 TcpEchobufferLength;
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
static void SendTxIfPduInfo(int IfIdx);
static void SendTxTpPduInfo(int TpIdx);
static void EthStub_MainFunc(void);
static void EthStub_DoIPFt(void);
static void EthStub_SoAdFt(void);
#endif
/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
void Eth_TestMain(void)
{
    #ifdef AUTOSAR_ETH_ENABLE
    Eth_FrameType frameType = frame.hdr.etherType;
    Eth_BufIdxType bufIdx;
    BufReq_ReturnType bufStatus;
    uint8 *bufPtr;
    Std_ReturnType retVal;
    uint16 len=500;
    PduInfoType IfPduInfo;

    Eth_DrvTrcvInit();
    switch(EthTest_Tx)
    {
        case 1: /* to transmit ethernet frame */
            memcpy(frame.hdr.dstMac, BcastAddr, ETH_MAC_ADDR_LEN);
            memcpy(frame.hdr.srcMac, UcastAddr, ETH_MAC_ADDR_LEN);
            frame.hdr.etherType = ETHERTYPE_EXPERIMENTAL1;
            memset(&frame.payload[0],0xaa,len);
            bufStatus = Eth_ProvideTxBuffer(0,ETH_DEFAULT_TX_PRIORITY, &bufIdx, &bufPtr,&len);
            if (BUFREQ_OK == bufStatus)
            {
                memcpy(bufPtr, frame.payload, len);
                retVal = Eth_Transmit(0,bufIdx,frameType,TRUE,len,frame.hdr.dstMac);
                if (retVal == E_OK)
                {
                    tx_cnt++;
                }
            }
            break;
        case 2:
            /* enable communication */
            ComM_CommunicationAllowed(0,TRUE);
            ComM_RequestComMode(0,COMM_FULL_COMMUNICATION);
            /* enable routing group */
            SoAd_OpenSoCon(SOAD_SOCON_UdpServerSocketConnection);   
            SoAd_EnableRouting(SOAD_RG_UdpServerRoutingGroup);
            SoAd_OpenSoCon(SOAD_SOCON_TcpServerSocketConnection);   
            SoAd_EnableRouting(SOAD_RG_TcpServerRoutingGroup);
            break;
        case 3:
            /* enable udp soad group */
            SoAd_OpenSoCon(SOAD_SOCON_UdpClientSocketConnection);
            SoAd_OpenSoCon(SOAD_SOCON_UdpServerSocketConnection);
            SoAd_EnableRouting(SOAD_RG_UdpServerRoutingGroup);
            SoAd_EnableRouting(SOAD_RG_UdpClientRoutingGroup);
            break;
        case 4:
            SoAd_OpenSoCon(SOAD_SOCON_TcpClientSocketConnection);
            SoAd_OpenSoCon(SOAD_SOCON_TcpServerSocketConnection);
            SoAd_EnableRouting(SOAD_RG_TcpServerRoutingGroup);
            SoAd_EnableRouting(SOAD_RG_TcpClientRoutingGroup);
            break;
        case 5:
            /* requet transmission of the frame for every 100ms */
            SendTxIfPduInfo(APP_PDU_UdpClientPduRouteIf);
            SendTxTpPduInfo(APP_PDU_UdpClientPduRouteTp);
            break;
        case 6:
            /* requet transmission of the frame for every 100ms */
            SendTxIfPduInfo(APP_PDU_UdpServerPduRouteIf);
            SendTxTpPduInfo(APP_PDU_UdpServerPduRouteTp);
            break;
        case 7:
            /* requet transmission of the frame for every 100ms */
            SendTxIfPduInfo(APP_PDU_TcpClientPduRouteIf);
            SendTxTpPduInfo(APP_PDU_TcpClientPduRouteTp);
            break;
        case 8:
            /* requet transmission of the frame for every 100ms */
            SendTxIfPduInfo(APP_PDU_TcpServerPduRouteIf);
            SendTxTpPduInfo(APP_PDU_TcpServerPduRouteTp);
            break;
        case 9:
            /* close socket udp */
            SoAd_CloseSoCon(SOAD_SOCON_UdpClientSocketConnection,FALSE);
            SoAd_CloseSoCon(SOAD_SOCON_UdpServerSocketConnection,FALSE);
            break;
        case 10:
            /* close socket udp */
            SoAd_CloseSoCon(SOAD_SOCON_TcpClientSocketConnection,FALSE);
            SoAd_CloseSoCon(SOAD_SOCON_TcpServerSocketConnection,FALSE);
            break;
        case 11:
            SendTxIfPduInfo(APP_PDU_TcpServerPduRouteIf);
            break;
        default:
            break;
    }
    /* reply from Udp server */
    if (DoTxUdpServerIf==1)
    {
        /* prepare Pdu info */
        IfPduInfo.SduDataPtr = &UdpEchoBuffer[0];
        IfPduInfo.SduLength = UdpEchobufferLength;
        /* request transmission */
        (void)SoAd_IfTransmit(SOAD_PDU_UdpServerPduRouteIf,&IfPduInfo);
        DoTxUdpServerIf = 0;
    }

    /* reply from tcp server */
    if (DoTxTcpServerIf==1)
    {
        /* prepare Pdu info */
        IfPduInfo.SduDataPtr = &TcpEchoBuffer[0];
        IfPduInfo.SduLength = TcpEchobufferLength;
        /* request transmission */
        (void)SoAd_IfTransmit(SOAD_PDU_TcpServerPduRouteIf,&IfPduInfo);
        DoTxTcpServerIf = 0;
    }
    EthTest_Tx = 0u;
    #endif
}
/* DOIP call back function */
Std_ReturnType DoIPApp_UserGetFurtherActionByte(DoIP_FurtherActionByteType * FurtherActionByte)
{
    return E_OK;
}

Std_ReturnType DoIPApp_UserGetGidCallback( uint8* GroupId )
{
    return E_OK;
}

Std_ReturnType DoIPApp_UserTriggerGidSyncCallback( void )
{
    return E_OK;
}

Std_ReturnType DoIPApp_UserGetVinCallback( uint8* Vin )
{
    return E_OK;
}

Std_ReturnType DoIpApp_UserGetPowerModeCallback(DoIP_PowerStateType * PowerStateReady)
{
    return E_OK;
}    

Std_ReturnType DoIPApp_UserGetPayloadCallbackFn
(
    uint16 RxHeaderType,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) RxPduInfo,
    uint8 PayloadType,
    P2VAR(uint16,AUTOMATIC,DOIP_APPL_VAR) TxHeaderType,
    P2VAR(PduInfoType,AUTOMATIC,DOIP_APPL_VAR) TxPduInfo
)
{
    return E_OK;
}

/* pdur doip callback function */
#ifdef PDUR_STUB_EN
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpStartOfReception
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    PduLengthType TpSduLength, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    return BUFREQ_OK;
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyRxData
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    
    return BUFREQ_OK;
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyTxData
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    
    return BUFREQ_OK;
}

void PduR_DoIPTpRxIndication(PduIdType RxPduId,Std_ReturnType Result)
{
    
}

void PduR_DoIPIfTxConfirmation(PduIdType TxPduId)
{
    
}

void PduR_DoIPTpTxConfirmation(PduIdType TxPduId,Std_ReturnType Result)
{
    
}
#endif

#ifdef ETH_DRV_STUB_EN
FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode(uint8 CtrlIdx, Eth_ModeType CtrlMode)
{
    return E_OK;
}

FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode(uint8 CtrlIdx, P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr)
{
    return E_OK;
}

FUNC(void, ETH_CODE) Eth_GetPhysAddr(uint8 CtrlIdx, P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr)
{
    
}

FUNC(void, ETH_CODE) Eth_SetPhysAddr(uint8 CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr)
{
    
}


FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter(uint8 CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr, Eth_FilterActionType Action)
{
    return E_OK;
}

FUNC(Std_ReturnType, ETH_CODE) Eth_GetCurrentTime(uint8 CtrlIdx, P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr)
{
    return E_OK;
}


FUNC(void, ETH_CODE) Eth_EnableEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx)
{
    
}

FUNC(void, ETH_CODE) Eth_GetEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx, P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr)
{
    
}

FUNC(void, ETH_CODE) Eth_GetIngressTimeStamp(uint8 CtrlIdx, P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) DataPtr, P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr)
{
    
}

FUNC(void, ETH_CODE) Eth_SetCorrectionTime(uint8 CtrlIdx, P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_DATA) timeOffsetPtr, P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_DATA) rateRatioPtr)
{

}
                      
FUNC(Std_ReturnType, ETH_CODE) Eth_SetGlobalTime(uint8 CtrlIdx, P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DAT) timeStampPtr)
{
    return E_OK;
}

FUNC(BufReq_ReturnType, ETH_CODE) Eth_ProvideTxBuffer(uint8 CtrlIdx, uint8 Priority,
                    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DAT) BufIdxPtr,
                    P2VAR(uint8, AUTOMATIC, ETH_APPL_DAT) *BufPtr,
                    P2VAR(uint16, AUTOMATIC, ETH_APPL_DAT) LenBytePtr)
{
    return BUFREQ_OK;
}

FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit(uint8 CtrlIdx,
             Eth_BufIdxType BufIdx,
             Eth_FrameType FrameType,
             boolean TxConfirmation,
             uint16 LenByte,
             P2CONST(uint8, AUTOMATIC, ETH_APPL_DAT) PhysAddrPtr)
{
    return E_OK;
}

#endif

/* app soad rx indication function */
FUNC(void, DOIP_CODE) App_SoAdIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr
)
{
    #ifdef AUTOSAR_ETH_ENABLE
    switch (RxPduId)
    {
    case 0 /* APP_PDU_UdpServerSocketRouteIf */:
        if (PduInfoPtr->SduLength < 100)
        {
            SoAd_UtilMemCopy(&UdpEchoBuffer[0],PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);
            UdpEchobufferLength = PduInfoPtr->SduLength;
            DoTxUdpServerIf=1;
        }
        break;
    case 2 /* APP_PDU_TcpServerSocketRouteIf */:
        if (PduInfoPtr->SduLength < 100)
        {
            SoAd_UtilMemCopy(&TcpEchoBuffer[0],PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);
            TcpEchobufferLength = PduInfoPtr->SduLength;
            DoTxTcpServerIf=1;
        }
    default:
        break;
    }
    #endif
}

FUNC(void, DOIP_CODE) App_SoAdIfTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{

}

FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr 
)
{
    return BUFREQ_OK;
}

FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr
)
{
    
    return BUFREQ_OK;
}

FUNC(void, DOIP_CODE) App_SoAdTpRxIndication(PduIdType id, Std_ReturnType result)
{  

}


FUNC(void, DOIP_CODE) App_SoAdTpTxConfirmation(PduIdType id, Std_ReturnType result)
{

}


FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2CONST(RetryInfoType,AUTOMATIC,DOIP_APPL_CONST) retry,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) availableDataPtr
)
{
    return BUFREQ_OK;
}

FUNC(void, DOIP_CODE) App_LocalIpAddrAssignmentChg(SoAd_SoConIdType SoConId, TcpIp_IpAddrStateType State)
{

}

FUNC(void, DOIP_CODE) App_SoConModeChg(SoAd_SoConIdType SoConId, SoAd_SoConModeType Mode)
{

}

/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
#ifdef AUTOSAR_ETH_ENABLE
static void SendTxIfPduInfo(int IfIdx)
{
    PduInfoType IfPduInfo;
    /* prepare Pdu info */
    memset(&IfTxBuffer[IfIdx][0],0xAA,IF_TX_BUFFER_SIZE);
    IfPduInfo.SduDataPtr = &IfTxBuffer[IfIdx][0];
    IfPduInfo.SduLength = IF_TX_BUFFER_SIZE;
    /* request transmission */
    (void)SoAd_IfTransmit(IfTxToSoAdPduId[IfIdx],&IfPduInfo);
}

static void SendTxTpPduInfo(int TpIdx)
{   
    PduInfoType TpPduInfo;
    /* prepare Pdu info */
    memset(&TpTxBuffer[TpIdx][0],0xAA,TP_TX_BUFFER_SIZE);
    TpTxBufferCopiedLength[TpIdx] =0u;
    TpPduInfo.SduDataPtr = &TpTxBuffer[TpIdx][0];
    TpPduInfo.SduLength = TP_TX_BUFFER_SIZE;
    if (SoAd_TpTransmit(TpTxToSoAdPduId[TpIdx],&TpPduInfo) == E_OK)
    {
        TpTxBufferRequestLength[TpIdx] = TpPduInfo.SduLength;
        TpTxBufferLock[TpIdx] = TRUE;
    }
}

static void EthStub_MainFunc(void)
{
    EthStub_SoAdFt();
    EthStub_DoIPFt();
}

static void EthStub_DoIPFt(void)
{
    Std_VersionInfoType versioninfo;
    uint8 DoIp_Data[10];
    PduInfoType PduInfo;
    PduLengthType AvailableDataPtr=0u;
    static Std_ReturnType RetVal;
    static RetryInfoType RetryInfo={TP_DATACONF,8u};
    static BufReq_ReturnType BufRetVal;
    
    PduInfo.SduDataPtr = &DoIp_Data[0];
    PduInfo.SduLength = 8u;
    switch (DoIP_TestNum)
    {
        case 1u:
            DoIP_Init(NULL_PTR);
            break;
        case 2u:
            DoIP_GetVersionInfo(&versioninfo);
            break;
        case 3u:
            RetVal = DoIP_IfTransmit(0u,&PduInfo);
            break;
        case 4u:
            RetVal = DoIP_IfCancelTransmit(0U);
            break;
        case 5u:
            RetVal = DoIP_TpTransmit(0u,&PduInfo);
            break;
        case 6u:
            RetVal = DoIP_TpCancelTransmit(0U);
            break;
        case 7u:
            RetVal = DoIP_TpCancelReceive(0u);
            break;
        case 8u:
            BufRetVal = DoIP_SoAdTpCopyTxData(0u,&PduInfo,&RetryInfo,&AvailableDataPtr);
            break;
        case 9u:
            DoIP_SoAdTpTxConfirmation(0u,E_OK);
            break;
        case 10U:
            BufRetVal = DoIP_SoAdTpCopyRxData(0u,&PduInfo,&AvailableDataPtr);
            break;
        case 11u:
            BufRetVal = DoIP_SoAdTpStartOfReception(0U,&PduInfo,8u, &AvailableDataPtr);
            break;
        case 12U:
            DoIP_SoAdTpRxIndication(0u, E_OK);
            break;
        case 13u:
            DoIP_SoAdIfRxIndication(0U,&PduInfo);
            break;
        case 14u:
            DoIP_SoAdIfTxConfirmation(0u,E_OK);
            break;
        case 15u:
            DoIP_SoConModeChg(0u, SOAD_SOCON_ONLINE);
            break;
        case 16u:
            DoIP_LocalIpAddrAssignmentChg(0u,TCPIP_IPADDR_STATE_UNASSIGNED);
            break;
        case 17u:
            DoIP_ActivationLineSwitchActive();
            break;
        case 18u:
            DoIP_ActivationLineSwitchActive();
            break;
        default:
            break;
    }
    DOIP_DUMMY_STATEMENT(BufRetVal);
    DOIP_DUMMY_STATEMENT(RetVal);
}

static void EthStub_SoAdFt(void)
{
    Std_VersionInfoType versioninfo;
    SoAd_SoConIdType SoConId=0;
    SoAd_SoConModeType Mode;
    TcpIp_SockAddrType LocalIpAddr;
    TcpIp_SockAddrType DefaultRouter;
    uint8 PhyAddr[8];
    uint8 PhyAddrLen=0;
    uint32 MeasureData[8];
    PduInfoType PduInfo;
        
    switch (SoAd_TestCode)
    {
        case 1:
            SoAd_Init(NULL_PTR);
            break;
        case 2:
            SoAd_GetVersionInfo(&versioninfo);
            break;
        case 3:
            (void)SoAd_GetSoConId(SoConId,&SoConId);
            break;
        case 4:
            (void)SoAd_OpenSoCon(SoConId);
            break;
        case 5:
            (void)SoAd_CloseSoCon(SoConId,TRUE);
            break;
        case 6:
            (void)SoAd_GetSoConMode(SoConId,&Mode);
            break;
        case 7:
            (void)SoAd_RequestIpAddrAssignment(SoConId,TCPIP_IPADDR_ASSIGNMENT_STATIC,&LocalIpAddr,0u,&DefaultRouter);
            break;
        case 8:
            (void)SoAd_ReleaseIpAddrAssignment(SoConId);
            break;
        case 9:
            (void)SoAd_GetLocalAddr(SoConId,&LocalIpAddr,0u,&DefaultRouter);
            break;
        case 10:
            (void)SoAd_GetPhysAddr(SoConId,&PhyAddr[0]);
            break;
        case 11:
            (void)SoAd_GetRemoteAddr(SoConId,&LocalIpAddr);
            break;
        case 12:
            (void)SoAd_SetRemoteAddr(SoConId,&LocalIpAddr);
            break;
        case 13:
            (void)SoAd_SetUniqueRemoteAddr(SoConId,&LocalIpAddr,&SoConId);
            break;
        case 14:
            (void)SoAd_ReleaseRemoteAddr(SoConId);
            break;
        case 15:
            (void)SoAd_TpChangeParameter(0,TP_STMIN,0);
            break;
        case 16:
            (void)SoAd_ReadDhcpHostNameOption(SoConId,&PhyAddrLen,&PhyAddr[0]);
            break;
        case 17:
            (void)SoAd_WriteDhcpHostNameOption(SoConId,PhyAddrLen,&PhyAddr[0]);
            break;
        case 18:
            (void)SoAd_GetAndResetMeasurementData(0,TRUE,&MeasureData[0]);
            break;
        case 19:
            (void)SoAd_MainFunction();
            break;
        case 20:
            (void)SoAd_IfTransmit(0,&PduInfo);
            break;
        case 21:
            (void)SoAd_IfRoutingGroupTransmit(0);
            break;
        case 22:
            (void)SoAd_IfSpecificRoutingGroupTransmit(0,0);
            break;
        case 23:
            (void)SoAd_TpTransmit(0,&PduInfo);
            break;
        case 24:
            (void)SoAd_TpCancelTransmit(0);
            break;
        case 25:
            (void)SoAd_TpCancelReceive(0);
            break;
        default:
            break;
    }
}
#endif
