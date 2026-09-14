/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
#ifndef DCM_C
#define DCM_C
/*****************************************************************************
 *  File Name         :  Dcm.C                                                *
 *  Module Short Name :  DiagMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

#include "Dcm.h"
#include "Dcm_Internal.h"
#include "Dcm_Dsd.h"
#include "Dcm_Dsp.h"
#include "Dcm_Cbk.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "MemLib.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define DCM_COMM_STATE_RX_DIS    0x0U
#define DCM_COMM_STATE_TX_DIS    0x0U
#define DCM_COMM_STATE_TX_EN     0x1U
#define DCM_COMM_STATE_RX_EN     0x2U

#define DCM_DIAG_REQUEST       0x01U
#define DCM_DIAG_TIMEOUT       0x02U
#define DcmDslAddBufferSize                     (uint8)3
/* Avoid warnings of unused API parameters */


#define DCM_0x01U               0x01U
#define DCM_0x02U               0x02U
#define DCM_0x03U               0x03U
#define DCM_SID_TESTER_PRESENT  0x3EU
#define DCM_0x40U               0x40U
#define DCM_SUPPRESS_RESP_MASK  0x80U
#define DCM_0xFFU               0xFFU
#define DCM_0x10U               0x10U
#define DCM_NRC_0x78            0x78U
#define DCM_NEGATIVE_RESP_SID   0x7FU
#define DCM_NRC_0x21            0x21U
#define DCM_0xFFFFU             0xFFFFU

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
static DcmDsl_BufferType RequestSnapshot[DcmDslBufferSize];
static Dcm_MsgLenType RequestLength;

typedef struct
{
    uint16 P2;
    uint16 P2Star;
    uint16 S3Server;
    uint16 TesterPresent;
    uint8 TimeOut;
} Dcm_TimerType;

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
#define DIAGMGR_CONST_SEC_START
#include "MemMap.h"
const Dcm_ConfigType *Dcm_ConfigPtr;
#define DIAGMGR_CONST_SEC_END
#include "MemMap.h"

#if(Dcm_KeepNonDefaultSessionActive == STD_ON)
static uint16 KeepS3Timer = TIMER_KeepNonDefaultSession;
#endif
/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
#define DIAGMGR_DATA_SEC_START
#include "MemMap.h"
DcmDsl_BufferType DcmDsl_Buffer[DcmDslBufferSize];
Dcm_InternalStatusType Dcm_InternalStatus;
Dcm_DslRequestResponseType Dcm_DslRequestResponse[DcmNumofClientSupported];
static Dcm_MsgItemType AddBuffer[DcmDslAddBufferSize];
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
static Dcm_MsgItemType BusyRespAddBuffer[DcmDslAddBufferSize];
#endif
static Dcm_TimerType Dcm_Timer;
#define DIAGMGR_DATA_SEC_END
#include "MemMap.h"

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

#define DIAGMGR_CODE_SEC_START
#include "MemMap.h"

/* DiagMgr Timing Functions */
static void Dcm_TimerProcess(void);
static void Dcm_Transmit_Function(uint8 Client);
static void Dcm_OnTimeout(uint8 TmrId);
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
static void Dcm_CancelOngoingOperation(uint8 Client);
#endif
static void Dcm_ProcessDataIndication(uint8 Client, uint8 OpStatus);

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/* Callback Notifications */
/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_CopyRxData
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType* bufferSizePtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to provide the received data of an I-PDU segment (N-PDU)
 to the upper layer.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_CopyRxData(PduIdType DcmRxPduId, const PduInfoType *info, PduLengthType *bufferSizePtr)
{
    BufReq_ReturnType fl_RetVal = BUFREQ_E_NOT_OK;
    PduLengthType MemIter = DCM_ZERO;
    uint8 Client = DCM_ZERO;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        /*Check for Physical request*/
        if(Dcm_RxPduId[Client].PhyReqId == DcmRxPduId)
        {
          Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_ZERO;
          PduReqIdMatch = DCM_E_OK;
          break;
        }
        /*Check for Functional request*/
        else if(Dcm_RxPduId[Client].FuncReqId == DcmRxPduId)
        {
          Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_0x01U;
          PduReqIdMatch = DCM_E_OK;
          break;
        }
        else
        {
            /*DO NOTHING - MISRA FIX*/
        }
    }


    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        if(info->SduLength != DCM_ZERO)
        {
            /* To handle Concurrent tester present request */
            if((info->SduDataPtr[DCM_ZERO] == DCM_SID_TESTER_PRESENT) && (info->SduDataPtr[DCM_0x01U] == DCM_SUPPRESS_RESP_MASK)
                          &&(DCM_ZERO != Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType))
            {
                if((info->SduLength == DCM_0x02U) && (Dcm_InternalStatus.ConcurrentTesterPresent != DCM_FALSE))
                {
                    *bufferSizePtr = DCM_ZERO;
                    fl_RetVal = BUFREQ_OK;
                }
            }
            /* Buffer is free & No any client's request is in progress*/
            else if(Dcm_DslRequestResponse[Client].State == DCM_STATE_ONRX)
            {
                // copy requested data into buffer
                if(Dcm_DslRequestResponse[Client].Buff_Pos < Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen)
                {
                    for (MemIter = DCM_ZERO; MemIter < info->SduLength; MemIter++)
                    {
                        Dcm_DslRequestResponse[Client].pMsgContext.reqData[Dcm_DslRequestResponse[Client].Buff_Pos + MemIter] =
                            info->SduDataPtr[MemIter];
                    }
                    Dcm_DslRequestResponse[Client].Buff_Pos += MemIter;
                    *bufferSizePtr = (PduLengthType) (Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen - Dcm_DslRequestResponse[Client].Buff_Pos);
                    fl_RetVal = BUFREQ_OK;
                }
            }
            #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
            // When any clients request already in progress
            else if(Dcm_DslRequestResponse[Client].State == DCM_STATE_BUSY_REPEAT_REQUEST)
            {
                if(Dcm_DslRequestResponse[Client].Buff_Pos < Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen)
                {
                    //copying only the SID to send NRC21
                    Dcm_DslRequestResponse[Client].BusyRespAddBuf[DCM_0x01U] =
                        info->SduDataPtr[DCM_ZERO];
                    Dcm_DslRequestResponse[Client].Buff_Pos += info->SduLength;
                    *bufferSizePtr = (PduLengthType) (Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen - Dcm_DslRequestResponse[Client].Buff_Pos);
                    fl_RetVal = BUFREQ_OK;
                }
            }
            #endif
            else
            {
                /*do nothing*/
            }
        }
        else
        {
            /* Just inform available buffer size*/
            if((PduLengthType) Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen < Dcm_DslRequestResponse[Client].Buff_Pos)
            {
                fl_RetVal = BUFREQ_E_NOT_OK;
            }
            else
            {
                *bufferSizePtr = (PduLengthType) Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen - Dcm_DslRequestResponse[Client].Buff_Pos; /*CERT C 17223802*/
                fl_RetVal = BUFREQ_OK;
            }
        }
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_StartOfReception
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to indicate the start of new diag request.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(info);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_StartOfReception(PduIdType DcmRxPduId, const PduInfoType *info, PduLengthType TpSduLength,
                                       PduLengthType *bufferSizePtr)
{
    BufReq_ReturnType fl_RetVal = BUFREQ_E_NOT_OK;
    Dcm_PduIdChannelType const *ConnInfo;
    uint8 Client = DCM_ZERO;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        //Check for Physical request
        if(Dcm_RxPduId[Client].PhyReqId == DcmRxPduId)
        {
            Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_ZERO;
            ConnInfo = &Dcm_PduIdChannel[Dcm_RxPduId[Client].PduIdChannelRef];
            PduReqIdMatch = DCM_E_OK;
            break;
        }
        //Check for functional request
        else if(Dcm_RxPduId[Client].FuncReqId == DcmRxPduId)
        {
            Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_0x01U;
            ConnInfo = &Dcm_PduIdChannel[Dcm_RxPduId[Client].PduIdChannelRef];
            PduReqIdMatch = DCM_E_OK;
            break;
        }
        else
        {
            /*DO NOTHING - MISRA FIX*/
        }
    }
    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        if(FALSE != (Dcm_DslRequestResponse[Client].ComMMode & DCM_COMM_STATE_RX_EN))
        {
            // ComM_DCM_ActiveDiagnostic() is moved from Dcm_TpRxIndication() to here
            // this guarantee Com is ready to transmit FlowCtrl if needed
            Dcm_EnterCriticalSection();
            if((Dcm_InternalStatus.ComMState != Dcm_ComM_InActive) && (Dcm_InternalStatus.Session_Level == DCM_DEFAULT_SESSION))
            {
                ComM_DCM_ActiveDiagnostic(Dcm_ComMChannelId[ConnInfo->ComMChannelIdRef].ComMChannelId);
            }
            Dcm_ExitCriticalSection();
            /* To handle Concurrent tester present request */
            if((info->SduDataPtr[DCM_ZERO] == DCM_SID_TESTER_PRESENT) && (info->SduDataPtr[DCM_0x01U] == DCM_SUPPRESS_RESP_MASK) &&
                    (DCM_ZERO != Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType) && (TpSduLength == DCM_0x02U))
            {
                    *bufferSizePtr = DCM_0x03U;
                    // suppress false reaction on TP in middle of CF's
                    Dcm_InternalStatus.ConcurrentTesterPresent = DCM_TRUE;
                    if(Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqTypeStored < DCM_0x02U)
                    {
                        // suppress false reaction on TP in middle of CF's
                        Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType =
                            Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqTypeStored;
                    }
                    fl_RetVal = BUFREQ_OK;
            }
            else if(Dcm_DslRequestResponse[Client].State == DCM_STATE_READY)
            {
                if(TpSduLength <= DcmDslBufferSize)
                {
                    Dcm_DslRequestResponse[Client].Buff_Pos = DCM_ZERO;
                    Dcm_DslRequestResponse[Client].pMsgContext.rxPduId = DcmRxPduId;
                    Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.suppressPosResponse = DCM_ZERO;
                    Dcm_DslRequestResponse[Client].State = DCM_STATE_ONRX;
                    Dcm_DslRequestResponse[Client].pMsgContext.resDataLen = DCM_ZERO;
                    Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen = (Dcm_MsgLenType) TpSduLength;
                    Dcm_DslRequestResponse[Client].pMsgContext.DemClientId = ConnInfo->DcmDemClientRef;
                    *bufferSizePtr = (PduLengthType) DcmDslBufferSize;
                    Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqTypeStored =
                        Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType;
                     //if there is no any client's request is in progress
                    if(Dcm_InternalStatus.BuffInUse != DCM_TRUE)
                    {
                        Dcm_InternalStatus.OpStatus = DCM_INITIAL;
                        Dcm_InternalStatus.MainConnection = ConnInfo -> ConfRespId;
                        Dcm_InternalStatus.SubConnRef = Client;
                        Dcm_InternalStatus.MainConnRef = Client;
                        Dcm_StopTimer(DCM_TMR_ID_S3SERVER);
                        Dcm_InternalStatus.Priority = ConnInfo -> ClientPriority;
                        Dcm_DslRequestResponse[Client].pMsgContext.reqData = (Dcm_MsgType)&DcmDsl_Buffer[DCM_ZERO];
                        Dcm_DslRequestResponse[Client].pMsgContext.resData = (Dcm_MsgType)&DcmDsl_Buffer[DCM_ZERO];
                        Dcm_DslRequestResponse[Client].pMsgContext.DemClientId = ConnInfo->DcmDemClientRef;
                        Dcm_InternalStatus.BuffInUse = DCM_TRUE;
                        fl_RetVal = BUFREQ_OK;
                    }
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
                    //if one client's request is already in progress & another client requested
                    else
                    {
                        // if high priority client request is in progress & low priority client requested
                        if(Dcm_InternalStatus.Priority < ConnInfo -> ClientPriority)
                        {
                            Dcm_InternalStatus.SubConnection = ConnInfo -> ConfRespId;
                            Dcm_InternalStatus.SubConnRef = Client;
                            Dcm_InternalStatus.BusyRepeatRequest = DCM_TRUE;
                            Dcm_DslRequestResponse[Client].State = DCM_STATE_BUSY_REPEAT_REQUEST;
                            Dcm_DslRequestResponse[Client].Flag = DCM_FLAG_BUSY;
                            Dcm_DslRequestResponse[Client].pMsgContext.reqData = &Dcm_DslRequestResponse[Client].BusyRespAddBuf[DCM_0x01U];
                            Dcm_DslRequestResponse[Client].pMsgContext.resData = &Dcm_DslRequestResponse[Client].BusyRespAddBuf[DCM_0x01U];
                            Dcm_DslRequestResponse[Client].pMsgContext.DemClientId = ConnInfo->DcmDemClientRef;
                            fl_RetVal = BUFREQ_OK;
                        }
                        // if low priority client request is in progress & high priority client requested
                        else
                        {
                            // cancel low priority client request progress
                            (void)Dcm_CancelOngoingOperation(Client);
                            fl_RetVal = BUFREQ_OK;
                        }
                    }
#endif
                }
                else
                {
                    fl_RetVal = BUFREQ_E_OVFL;
                }
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : void Dcm_TpRxIndication
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : This function is called to indicate whether the transmission was successful or not.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dcm_TpRxIndication(PduIdType DcmRxPduId, Std_ReturnType result)
{
    #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
    Dcm_PduIdChannelType const *ConnInfo;
    PduInfoType info = { NULL, DCM_ZERO };
    Std_ReturnType stdReturn = DCM_E_NOT_OK;
    #endif
    uint8 Client;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        // check for Physical request
        if(Dcm_RxPduId[Client].PhyReqId == DcmRxPduId)
        {
          Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_ZERO;
          #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
          ConnInfo = &Dcm_PduIdChannel[Dcm_RxPduId[Client].PduIdChannelRef];
          #endif
          PduReqIdMatch = DCM_E_OK;
          break;
        }
        // check for functional request
        else if(Dcm_RxPduId[Client].FuncReqId == DcmRxPduId)
        {
          Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_0x01U;
          #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
          ConnInfo = &Dcm_PduIdChannel[Dcm_RxPduId[Client].PduIdChannelRef];
          #endif
          PduReqIdMatch = DCM_E_OK;
          break;
        }
        else
        {
            /*DO NOTHING - MISRA FIX*/
        }
    }

    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        if(result == E_OK)
        {
            if(Dcm_DslRequestResponse[Client].State == DCM_STATE_ONRX)
            {
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
                if(Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].Flag == DCM_FLAG_CANCEL)
                {
                    if(Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].State == DCM_STATE_ONTX_WAIT)
                    {
                        (void)PduR_DcmCancelTransmit(Dcm_PduIdChannel[Dcm_InternalStatus.SubConnRef].PhyRespId);
                    }
                    Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].State = DCM_STATE_READY;
                    Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].Flag = DCM_FLAG_IDLE;
                }
#endif

                /* Check for the tester present physical  request*/
                if(Dcm_DslRequestResponse[Client].pMsgContext.reqData[DCM_ZERO] == DCM_SID_TESTER_PRESENT)
                {
                    #if(DCM_SVC_3E_SUPPORT_ENABLED == STD_ON)
                    Dcm_StartTimer (DCM_TMR_ID_3E);
                    /* Check for the suppression of Pos Response */
                    if((Dcm_DslRequestResponse[Client].pMsgContext.reqData[DCM_0x01U] == DCM_SUPPRESS_RESP_MASK)
                            && (Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen == DCM_0x02U))
                    {
                        /* Restart the session timeout timer for "tester present"*/
                        Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
                        /* No further processing needed for Suppress Positive Response bit set*/
                        Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
                        Dcm_InternalStatus.BuffInUse = DCM_FALSE;
                        Dcm_ComMInactiveIndication();
                    }
                    else
                    #endif
                    {
                        Dcm_StartTimer (DCM_TMR_ID_P2 | DCM_TMR_ID_P2STAR);
                        Dcm_DslRequestResponse[Client].State = DCM_STATE_RX_END;
                        Dcm_InternalStatus.RcrRp_Count = 0x0u;
                        Dcm_InternalStatus.FRcRp_Status = 0x0u;
                    }
                }
                else if(DCM_FALSE != Dcm_InternalStatus.ConcurrentTesterPresent)
                {
                    /* to address functional tester present */
                    /* Restart the session timeout timer for "tester present"*/
                    Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
                    Dcm_StartTimer (DCM_TMR_ID_3E);
                    Dcm_InternalStatus.ConcurrentTesterPresent = DCM_FALSE;
                }
                else
                {
                    Dcm_StartTimer (DCM_TMR_ID_P2 | DCM_TMR_ID_P2STAR);
                    Dcm_DslRequestResponse[Client].State = DCM_STATE_RX_END;
                    Dcm_InternalStatus.RcrRp_Count = 0x0u;
                    Dcm_InternalStatus.FRcRp_Status = 0x0u;
                }

                if(Dcm_DslRequestResponse[Client].State == DCM_STATE_RX_END)
                {
                    // Pre copy the SID for NRC 0x78 Response
                    Dcm_DslRequestResponse[Client].AddBuf[DCM_0x01U] = Dcm_DslRequestResponse[Client].pMsgContext.reqData[DCM_ZERO];
                }
            }
            else if(FALSE != Dcm_InternalStatus.ConcurrentTesterPresent)
            {
                /* to address functional tester present */
                /* Restart the session timeout timer for "tester present"*/
                Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
                Dcm_StartTimer (DCM_TMR_ID_3E);
                Dcm_InternalStatus.ConcurrentTesterPresent = DCM_FALSE;
            }
            else
            {
                /*Do Nothing*/
            }
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
            if(Dcm_DslRequestResponse[Client].State == DCM_STATE_BUSY_REPEAT_REQUEST)
            {
                // send NRC 0x21 for low priority client's request, if High priority client request is in progress & low priority client requested
                if(Dcm_InternalStatus.BusyRepeatRequest == DCM_TRUE)
                {
                  Dcm_DslRequestResponse[Client].BusyRespAddBuf[DCM_0x01U] = Dcm_DslRequestResponse[Client].pMsgContext.reqData[DCM_ZERO];
                  Dcm_DslRequestResponse[Client].BusyRespAddBuf[DCM_0x02U] = DCM_NRC_0x21;
                  info.SduDataPtr = Dcm_DslRequestResponse[Client].BusyRespAddBuf;
                  info.SduLength = DCM_0x03U;
                  stdReturn = PduR_DcmTransmit (ConnInfo->PhyRespId, &info);
                  if(stdReturn != E_OK)
                  {
                    Dcm_TpTxConfirmation (ConnInfo->ConfRespId, stdReturn);
                  }
                }

            }
#endif
        }
        else
        {
          Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
          Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
          Dcm_InternalStatus.BuffInUse = DCM_FALSE;
        }
    }

}

/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_CopyTxData
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to acquire the transmit data of an I-PDU segment.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
 ** DCM_IGNORE_UNREF_PARAM(retry);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3673
 ** MISRA Title : pointer
 ** MISRA Type:A pointer should point to a const-qualified type whenever possible - MISRA C:2012  Rule-8.13: (Advisory)
 ** MISRA Message :
 ** The object addressed by the pointer parameter 'retry' is not modified and so the
 ** pointer could be of type 'pointer to const'..
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_CopyTxData(PduIdType DcmTxPduId, const PduInfoType *info, RetryInfoType *retry,
                                 PduLengthType *availableDataPtr)
{
    PduLengthType memIter = DCM_ZERO;
    BufReq_ReturnType fl_RetVal = BUFREQ_E_NOT_OK;
    uint8 Client;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        if(Dcm_PduIdChannel[Client].ConfRespId == DcmTxPduId)
        {
            PduReqIdMatch = DCM_E_OK;
            break;
        }
    }
    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        if(Dcm_DslRequestResponse[Client].State == DCM_STATE_ONTX_WAIT)
        {
            fl_RetVal = BUFREQ_E_BUSY;
            if(info->SduLength == DCM_ZERO)
            {
                if(Dcm_DslRequestResponse[Client].pMsgContext.resDataLen < Dcm_DslRequestResponse[Client].Buff_Pos)
                {
                    /* do nothing */
                }
                else
                {
                    *availableDataPtr = (Dcm_DslRequestResponse[Client].pMsgContext.resDataLen - Dcm_DslRequestResponse[Client].Buff_Pos); /* CERT C 17225671 */
                }
            }

            if(Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE)
            {
                if(Dcm_DslRequestResponse[Client].Buff_Pos < Dcm_DslRequestResponse[Client].pMsgContext.resDataLen)
                {
                    if(info->SduLength <= (Dcm_DslRequestResponse[Client].pMsgContext.resDataLen - Dcm_DslRequestResponse[Client].Buff_Pos))
                    {
                        for (memIter = DCM_ZERO; memIter < info->SduLength; memIter++)
                        {
                            info->SduDataPtr[memIter] = Dcm_DslRequestResponse[Client].pMsgContext.resData[Dcm_DslRequestResponse[Client].Buff_Pos
                                                        + memIter];
                        }
                        Dcm_DslRequestResponse[Client].Buff_Pos += memIter;
                        *availableDataPtr = Dcm_DslRequestResponse[Client].pMsgContext.resDataLen - Dcm_DslRequestResponse[Client].Buff_Pos;
                        fl_RetVal = BUFREQ_OK;
                    }
                }
            }
            else
            {
                if(info->SduLength <= DCM_0x03U)
                {
                  if (info->SduDataPtr != NULL_PTR)
                  {
                    for (memIter = DCM_ZERO; memIter < info->SduLength; memIter++)
                    {
                      info->SduDataPtr[memIter] = Dcm_DslRequestResponse[Client].AddBuf[memIter];
                    }
                    *availableDataPtr = (PduLengthType) info->SduLength - memIter;
                  }
                  else
                  {
                    *availableDataPtr = DcmDslAddBufferSize;
                  }
                  fl_RetVal = BUFREQ_OK;
                }
            }
        }
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
        else if(Dcm_DslRequestResponse[Client].State == DCM_STATE_BUSY_REPEAT_REQUEST)
        {
            if((Dcm_DslRequestResponse[Client].Flag == DCM_FLAG_BUSY) && (Dcm_InternalStatus.BusyRepeatRequest == DCM_TRUE))
            {
                if(info->SduLength <= DCM_0x03U)
                {
                    for (memIter = DCM_ZERO; memIter < info->SduLength; memIter++)
                    {
                        info->SduDataPtr[memIter] = Dcm_DslRequestResponse[Client].BusyRespAddBuf[memIter];
                    }
                    *availableDataPtr = (PduLengthType) info->SduLength - memIter;
                    fl_RetVal = BUFREQ_OK;
                }
            }
        }
#endif
        else
        {
            /*Do Nothing*/
        }
    }
    return fl_RetVal;
}
/**************************************************************************
 Function name   : void Dcm_TpTxConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : The result indicates whether the diag response
 transmission was successful or not.
 **************************************************************************/

void Dcm_TpTxConfirmation(PduIdType DcmTxPduId, Std_ReturnType result)
{
    uint8 Client = DCM_ZERO;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        if(Dcm_PduIdChannel[Client].ConfRespId == DcmTxPduId)
        {
          PduReqIdMatch = DCM_E_OK;
          break;
        }
    }

    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        Dsd_DslConfirmation (DcmTxPduId, result);
        /*SFD*/
    #if(DcmDsdRequestManufacturerNotificationEnabled == STD_ON)
        Dsd_DslManufConfirmation(&Dcm_DslRequestResponse[Client].pMsgContext,result);
    #endif
        Dsp_DslConfirmation (DcmTxPduId, result);
        if(Dcm_InternalStatus.MainConnection == DcmTxPduId)
        {
        /* For an error confirmation re-transmission of response not require...
        * Hence Result parameter not checked */
        /* Indicate inactive diagnostics to ComM */
            if((Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE) || (Dcm_InternalStatus.OpStatus == DCM_E_CANCEL))
            {
                Dcm_InternalStatus.BuffInUse = DCM_FALSE;
                Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
                /* Indicate inactive diagnostics to ComM */
                Dcm_ComMInactiveIndication();
            }
            else
            {
                Dcm_DslRequestResponse[Client].State = DCM_SID_PROCESS;
            }
            /* Start S3Timer */
            if(Dcm_InternalStatus.Session_Level != DCM_DEFAULT_SESSION)
            {
                Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
            }
            else
            {
                Dcm_StopTimer(DCM_TMR_ID_S3SERVER);
            }
        }
        #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
        else
        {
            if(Dcm_DslRequestResponse[Client].State == DCM_STATE_BUSY_REPEAT_REQUEST)
            {
                Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
                Dcm_DslRequestResponse[Client].Flag = DCM_FLAG_IDLE;
                Dcm_InternalStatus.BusyRepeatRequest = DCM_FALSE;
                Dcm_InternalStatus.Priority = 0x0u;
            }
        }
        #endif
    }
}

/**************************************************************************
 Function name   : void Dcm_TxConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : the result indicates whether the diag response
 transmission was successful or not.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(TxPduId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dcm_TxConfirmation(PduIdType TxPduId)
{

    uint8 Client = DCM_ZERO;
    uint8 PduReqIdMatch = DCM_E_NOT_OK;

    for (Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        if(Dcm_PduIdChannel[Client].ConfRespId == TxPduId)
        {
          PduReqIdMatch = DCM_E_OK;
          break;
        }
    }
    if(PduReqIdMatch != DCM_E_NOT_OK)
    {
        if(Dcm_InternalStatus.MainConnection == TxPduId)
        {
            /* Indicate inactive diagnostics to ComM */
            if((Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE) || (Dcm_InternalStatus.OpStatus == DCM_E_CANCEL))
            {
                Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
                Dcm_InternalStatus.BuffInUse = DCM_FALSE;
                /* Indicate inactive diagnostics to ComM */
                Dcm_ComMInactiveIndication();

            }
            else
            {
                Dcm_DslRequestResponse[Client].State = DCM_SID_PROCESS;
            }
        }
        #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
        else
        {
            if(Dcm_DslRequestResponse[Client].State == DCM_STATE_BUSY_REPEAT_REQUEST)
            {
                Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
                Dcm_DslRequestResponse[Client].Flag = DCM_FLAG_IDLE;
                Dcm_InternalStatus.BusyRepeatRequest = FALSE;
                Dcm_InternalStatus.Priority = 0x0u;
            }
        }
        #endif
    }
}
#if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
/**************************************************************************
 Function name   : void Dcm_CancelOngoingOperation
 Arguments       : uint8 Client
 Return type     : void
 Description     : This call informs the Dcm module to cancel the ongoing operation
 **************************************************************************/
static void Dcm_CancelOngoingOperation(uint8 Client)
{
    Dcm_InternalStatus.SubConnRef = Dcm_InternalStatus.MainConnRef;
    Dcm_InternalStatus.MainConnRef = Client;
    Dcm_InternalStatus.MainConnection = Dcm_PduIdChannel[Client].ConfRespId;
    Dcm_DslRequestResponse[Client].pMsgContext.DemClientId = Dcm_PduIdChannel[Client].DcmDemClientRef;
    Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].Flag = DCM_FLAG_CANCEL;
    Dcm_StopTimer(DCM_TMR_ID_S3SERVER);
    Dcm_StopTimer(DCM_TMR_ID_P2);
    Dcm_StopTimer(DCM_TMR_ID_P2STAR);

    Dcm_InternalStatus.OpStatus = DCM_INITIAL;
    Dcm_InternalStatus.ConcurrentTesterPresent = DCM_FALSE;
    Dcm_InternalStatus.Security_Level = DCM_SEC_LEV_LOCKED;
    Dcm_InternalStatus.Session_Level = DCM_DEFAULT_SESSION;
    Dcm_InternalStatus.Session_Index = 0x0u;

    Dcm_SessionChangeAction (DCM_INITIAL, DCM_DEFAULT_SESSION, DCM_DIAG_CANCEL);
}
#endif
/**************************************************************************
 Function name   : void Dcm_ComM_NoComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_NO_COMMUNICATION.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(NetworkId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dcm_ComM_NoComModeEntered(uint8 NetworkId)
{
    uint8 Client;
    for(Client = DCM_ZERO; Client < DcmNumofClientSupported ; Client ++)
    {
        if(Dcm_ComMChannelId[Dcm_PduIdChannel[Client].ComMChannelIdRef].ComMChannelId == NetworkId)
        {
            Dcm_EnterCriticalSection();
            Dcm_DslRequestResponse[Client].ComMMode = (DCM_COMM_STATE_RX_DIS | DCM_COMM_STATE_TX_DIS);
            Dcm_ExitCriticalSection();
        }
    }
}

/**************************************************************************
 Function name   : void Dcm_ComM_SilentComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_SILENT_COMMUNICATION..
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(NetworkId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dcm_ComM_SilentComModeEntered(uint8 NetworkId)
{
    uint8 Client;
    for(Client = DCM_ZERO; Client < DcmNumofClientSupported ; Client ++)
    {
        if(Dcm_ComMChannelId[Dcm_PduIdChannel[Client].ComMChannelIdRef].ComMChannelId == NetworkId)
        {
            Dcm_EnterCriticalSection();
            Dcm_DslRequestResponse[Client].ComMMode = (DCM_COMM_STATE_RX_EN | DCM_COMM_STATE_TX_DIS);
            Dcm_ExitCriticalSection();
        }
    }
}

/**************************************************************************
 Function name   : void Dcm_ComM_FullComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_FULL_COMMUNICATION.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(NetworkId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dcm_ComM_FullComModeEntered(uint8 NetworkId)
{
    uint8 Client;
    for(Client = DCM_ZERO; Client < DcmNumofClientSupported ; Client ++)
    {
        if(Dcm_ComMChannelId[Dcm_PduIdChannel[Client].ComMChannelIdRef].ComMChannelId == NetworkId)
        {
            Dcm_EnterCriticalSection();
            Dcm_DslRequestResponse[Client].ComMMode = (DCM_COMM_STATE_RX_EN | DCM_COMM_STATE_TX_EN);
            Dcm_ExitCriticalSection();
        }
    }
}

/*  Functions provided for other BSW components */
/**************************************************************************
 Function name   : void Dcm_Init
 Arguments       : const Dcm_ConfigType *ConfigPtr
 Return type     : void
 Description     : Service for basic initialization of DCM module.
 **************************************************************************/

void Dcm_Init(const Dcm_ConfigType *ConfigPtr)
{
    uint8 Client;
    Dcm_ConfigPtr = ConfigPtr;


    for(Client = DCM_ZERO; Client < DcmNumofClientSupported; Client++)
    {
        Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
        Dcm_DslRequestResponse[Client].Buff_Pos = (uint8) DCM_ZERO;
        Dcm_DslRequestResponse[Client].RxData = (DcmDsl_BufferType*)  &DcmDsl_Buffer[DCM_ZERO];
        Dcm_DslRequestResponse[Client].AddBuf = (Dcm_MsgItemType*) &AddBuffer[DCM_ZERO];
        #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
        Dcm_DslRequestResponse[Client].BusyRespAddBuf = (Dcm_MsgItemType*) &BusyRespAddBuffer[DCM_ZERO];
        #endif
        Dcm_DslRequestResponse[Client].pMsgContext.idContext = (Dcm_IdContextType) DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqType = DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.reqTypeStored = DCM_0x02U; /* not set */
        Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.suppressPosResponse = DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.reqData = (Dcm_MsgType) &DcmDsl_Buffer[DCM_ZERO];
        Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen = (Dcm_MsgLenType) DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.resData = (Dcm_MsgType) &DcmDsl_Buffer[DCM_ZERO];
        Dcm_DslRequestResponse[Client].pMsgContext.resDataLen = (Dcm_MsgLenType) DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.resMaxDataLen = (Dcm_MsgLenType) DcmDslBufferSize;
        Dcm_DslRequestResponse[Client].pMsgContext.rxPduId = (PduIdType) DCM_ZERO;
        Dcm_DslRequestResponse[Client].pMsgContext.DemClientId = DCM_ZERO;
        Dcm_DslRequestResponse[Client].ComMMode = DCM_NO_COM;
        Dcm_DslRequestResponse[Client].Flag = DCM_FLAG_IDLE;
    }

    AddBuffer[DCM_ZERO] = DCM_NEGATIVE_RESP_SID; /* Always used to send NRC */
    AddBuffer[DCM_0x02U] = DCM_NRC_0x78; /* Always used to send NRC - 0x78 */
    #if(DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
    BusyRespAddBuffer[DCM_ZERO] = DCM_NEGATIVE_RESP_SID; /* Always used to send NRC */
    BusyRespAddBuffer[DCM_0x02U] = DCM_NRC_0x21; /* Always used to send NRC - 0x21 */
    #endif
    Dcm_InternalStatus.ConcurrentTesterPresent = DCM_FALSE;
    Dcm_InternalStatus.ComMState = Dcm_ComM_Active;
    Dcm_InternalStatus.ConfirmationStatus = DCM_RES_NEG_OK;
    Dcm_InternalStatus.OpStatus = DCM_INITIAL;
    Dcm_InternalStatus.Security_Level = DCM_SEC_LEV_LOCKED;
    Dcm_InternalStatus.Session_Index = DCM_ZERO;
    Dcm_InternalStatus.RcrRp_Count = DCM_ZERO;
    Dcm_InternalStatus.FRcRp_Status = DCM_ZERO;
    Dcm_InternalStatus.Session_Level = DCM_DEFAULT_SESSION;
    Dcm_InternalStatus.BuffInUse = DCM_FALSE;
    Dcm_InternalStatus.Priority = DCM_ZERO;
    Dcm_InternalStatus.SubConnRef = DCM_ZERO;
    Dcm_InternalStatus.MainConnRef = DCM_ZERO;
    Dcm_InternalStatus.BusyRepeatRequest = DCM_FALSE;
    Dcm_InternalStatus.MainConnection = DCM_ZERO;
    Dcm_InternalStatus.SubConnection = DCM_ZERO;

    Dcm_Timer.P2 = DCM_ZERO;
    Dcm_Timer.P2Star = DCM_ZERO;
    Dcm_Timer.S3Server = DCM_ZERO;
    Dcm_Timer.TesterPresent = DCM_ZERO;
    Dcm_Timer.TimeOut = DCM_TMR_ID_P2 | DCM_TMR_ID_P2STAR | DCM_TMR_ID_S3SERVER | DCM_TMR_ID_3E;
    Dsd_Init();
    Dsp_Init();
}

/**************************************************************************
 Function name   : void Dcm_GetVersionInfo
 Arguments       : Std_VersionInfoType* versionInfo
 Return type     : void
 Description     : Returns the version information of this module.
 **************************************************************************/

void Dcm_GetVersionInfo(Std_VersionInfoType *versionInfo)
{
    if(versionInfo != NULL_PTR)
    {
        versionInfo->vendorID = DCM_VENDOR_ID;
        versionInfo->moduleID = DCM_MODULE_ID;
        versionInfo->sw_major_version = DCM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DCM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DCM_SW_PATCH_VERSION;
    }
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_DemTriggerOnDTCStatus
 Arguments       : uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
                   Dem_UdsStatusByteType DTCStatusNew
 Return type     : Std_ReturnType
 Description     : Triggers on changes of the UDS DTC status byte. Allows to trigger on ROE Event
 for subservice OnDTCStatusChanged.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DTC);
 ** DCM_IGNORE_UNREF_PARAM(DTCStatusOld);
 ** DCM_IGNORE_UNREF_PARAM(DTCStatusNew);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
Std_ReturnType Dcm_DemTriggerOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
        Dem_UdsStatusByteType DTCStatusNew)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;

    (void)Dcm_DspDemTriggerOnDTCStatus(DTC, DTCStatusOld, DTCStatusNew);

    return fl_RetVal;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetVin
 Arguments       : uint8* Data
 Return type     : Std_ReturnType
 Description     : Callbackfunction to get the VIN
 **************************************************************************/
Std_ReturnType Dcm_GetVin(uint8 *Data)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;
    /*QAC fix*/
    *Data = 0U;

    return fl_RetVal;
}

/**************************************************************************
 Function name   : void Dcm_ProcessDataIndication(void)
 Arguments       : none
 Return type     : void
 Description     :
 **************************************************************************/
static void Dcm_ProcessDataIndication(uint8 Client, uint8 OpStatus)
{
    Std_ReturnType DslDataIndicationStstus = DCM_E_NOT_OK;
    RequestLength = Dcm_DslRequestResponse[Client].pMsgContext.reqDataLen;
    DslDataIndicationStstus = Dsd_DslDataIndication (&Dcm_DslRequestResponse[Client].pMsgContext, OpStatus);

    switch (DslDataIndicationStstus)
    {
        case DCM_E_OK :
        case DCM_E_NOT_OK :
        case DCM_E_PROCESSING_DONE:
            Dcm_InternalStatus.OpStatus = DCM_E_PROCESSING_DONE;
            break;
        case DCM_E_REQUEST_NOT_ACCEPTED:
            Dcm_InternalStatus.OpStatus = DCM_E_CANCEL;
            Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
            break;
        case DCM_E_PENDING:
            MemLib_MemCpy (&RequestSnapshot[DCM_ZERO], &DcmDsl_Buffer[DCM_ZERO], DcmDslBufferSize);
            Dcm_InternalStatus.OpStatus = DCM_PENDING;
            /* In case of responsePending the DCM module shall clear the suppressPosRspMsgIndicationBit. */
            Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.suppressPosResponse = DCM_ZERO;
            break;
        case DCM_E_FORCE_RCRRP:
            MemLib_MemCpy (&RequestSnapshot[DCM_ZERO], &DcmDsl_Buffer[DCM_ZERO], DcmDslBufferSize);
            Dcm_DslRequestResponse[Client].pMsgContext.msgAddInfo.suppressPosResponse = DCM_ZERO;
            /* Transmit immediate RCRRP */
            if(Dcm_InternalStatus.FRcRp_Status == DCM_FALSE)
            {
                Dcm_DslRequestResponse[Client].AddBuf[DCM_0x02U] = DCM_NRC_0x78;
                Dcm_DslRequestResponse[Client].State = DCM_STATE_ONTX;
                Dcm_InternalStatus.OpStatus = DCM_E_FORCE_RCRRP;
                Dcm_InternalStatus.FRcRp_Status = DCM_TRUE;
                ++Dcm_InternalStatus.RcrRp_Count;
            }
            else
            {
                Dcm_InternalStatus.OpStatus = DCM_PENDING;
            }
            break;
        default:
            /*Do nothing - MISRA Fix snaray12*/
            Dcm_InternalStatus.OpStatus = DCM_E_CANCEL;
            Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
            break;
    }
}

/**************************************************************************
 Function name   : boolean Dcm_CheckTimerActive
 Arguments       : uint8 TmrId
 Return type     : boolean
 Description     : Used to check DCM timer is active, i.e. P2, P2*, S3Server
 **************************************************************************/
Dcm_BooleanType Dcm_CheckTimerActive( uint8 TmrId )
{
  Dcm_BooleanType Res = DCM_FALSE;

    if(DCM_FALSE != (DCM_TMR_ID_P2 & TmrId))
    {
        if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2))
        {
            Res = DCM_TRUE;
        }
    }
    else if(DCM_FALSE != (DCM_TMR_ID_P2STAR & TmrId))
    {
        if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2STAR))
        {
            Res = DCM_TRUE;
        }
    }
    else if(DCM_FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
    {
        if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_S3SERVER))
        {
            Res = DCM_TRUE;
        }
    }
    else if(DCM_FALSE != (DCM_TMR_ID_3E & TmrId))
    {
        if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_3E))
        {
            Res = DCM_TRUE;
        }
    }
    else
    {
        /* empty */
    }
    return Res;
}

/**************************************************************************
 Function name   : boolean Dcm_CheckTesterPresentActive
 Arguments       : uint8 TmrId
 Return type     : boolean
 Description     : Used to check TesterPresent message is active
 **************************************************************************/
Dcm_BooleanType Dcm_CheckTesterPresentActive(void)
{
    return Dcm_CheckTimerActive(DCM_TMR_ID_3E);
}


/*    Scheduled Functions */
/**************************************************************************
 Function name   : void Dcm_MainFunction
 Arguments       : void
 Return type     : void
 Description     : This service is used for processing the tasks of the main loop.
 **************************************************************************/
void Dcm_MainFunction(void)
{
    if (Dcm_InternalStatus.MainConnRef < DcmNumofClientSupported)
    {
        switch (Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State)
        {
            case DCM_STATE_ONRX:
                break;

            case DCM_STATE_RX_END:
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_SID_PROCESS;
                Dcm_ProcessDataIndication(Dcm_InternalStatus.MainConnRef, DCM_INITIAL);
                break;

            case DCM_STATE_ONTX:
                Dcm_Transmit_Function(Dcm_InternalStatus.MainConnRef);
                break;

            case DCM_SID_PROCESS:
                MemLib_MemCpy (&DcmDsl_Buffer[DCM_ZERO], &RequestSnapshot[DCM_ZERO], DcmDslBufferSize);
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqDataLen = RequestLength;
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData = &DcmDsl_Buffer[DCM_ZERO];
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData = &DcmDsl_Buffer[DCM_ZERO];
                Dcm_ProcessDataIndication(Dcm_InternalStatus.MainConnRef, DCM_PENDING);
                break;
            case DCM_STATE_ONTX_WAIT:
            case DCM_STATE_READY:
            case DCM_STATE_PREPTX_NRC:
            default:
                /*Do nothing - MISRA Warning Fix snaray12 */
                break;
        }
    }
    Dcm_TimerProcess();
    Dsd_Main();
    Dsp_Main();
}

/**************************************************************************
 Function name   : void Dcm_Transmit_Function
 Arguments       : void
 Return type     : void
 Description     : This function is used to handle transmit functionalities.
 **************************************************************************/

static void Dcm_Transmit_Function(uint8 Client)
{
    Std_ReturnType stdReturn = DCM_E_NOT_OK;
    PduIdType id = DCM_0xFFFFU;
    PduInfoType info = { NULL, DCM_ZERO };
    Dcm_DslRequestResponse[Client].Buff_Pos = 0x0;


    id = Dcm_PduIdChannel[Client].PhyRespId;

    if(DCM_FALSE != (Dcm_DslRequestResponse[Client].ComMMode & DCM_COMM_STATE_TX_EN))
    {
        if(Dcm_InternalStatus.OpStatus != DCM_E_PROCESSING_DONE)
        {
            /* Send Nrc: 0x78 - Response Pending */
            /* No need to touch resdata length on on response pending
             as it may updated by SWC's*/
            info.SduDataPtr = Dcm_DslRequestResponse[Client].AddBuf;
            info.SduLength = DCM_0x03U;
        }
        else
        {
             Dcm_DslRequestResponse[Client].pMsgContext.resDataLen +=
                 (Dcm_DslRequestResponse[Client].pMsgContext.resData - Dcm_DslRequestResponse[Client].pMsgContext.reqData);
             /* Revert back to starting address */
             Dcm_DslRequestResponse[Client].pMsgContext.resData = Dcm_DslRequestResponse[Client].pMsgContext.reqData;

             /* Check if the response length is higher than the available buffer size...
              * To report Nrc - 0x14  */
             if(Dcm_DslRequestResponse[Client].pMsgContext.resDataLen >= Dcm_DslRequestResponse[Client].pMsgContext.resMaxDataLen)
             {
                Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_0x01U] = Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_ZERO];
                if(Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_ZERO] > DCM_0x40U)
                {
                    Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_0x01U] = Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_ZERO] - DCM_0x40U;
                }
                Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_ZERO] = DCM_NEGATIVE_RESP_SID;
                Dcm_DslRequestResponse[Client].pMsgContext.resData[DCM_0x02U] = DCM_E_RESPONSETOOLONG;
                info.SduDataPtr = Dcm_DslRequestResponse[Client].pMsgContext.resData;
                info.SduLength = DCM_0x03U;
             }
             else
             {
                info.SduDataPtr = Dcm_DslRequestResponse[Client].pMsgContext.resData;
                info.SduLength = Dcm_DslRequestResponse[Client].pMsgContext.resDataLen;
             }
        }

        if(id != DCM_0xFFFFU)
        {
            Dcm_DslRequestResponse[Client].State = DCM_STATE_ONTX_WAIT;
            stdReturn = PduR_DcmTransmit (id, &info);
            if(stdReturn != E_OK)
            {
                id = Dcm_PduIdChannel[Client].ConfRespId;
                Dcm_TpTxConfirmation (id, stdReturn);
            }
        }
        else
        {
            Dcm_DslRequestResponse[Client].State = DCM_STATE_READY;
            Dcm_InternalStatus.BuffInUse = DCM_FALSE;
        }
    }
}

/**************************************************************************
 Function name   : void Dcm_TimeTask
 Arguments       : void
 Return type     : void
 Description     : This function is used to handle the DiagMgr timeout's
 **************************************************************************/

static void Dcm_TimerProcess(void)
{
    if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2))
    {
        if(DCM_0x01U < Dcm_Timer.P2)
        {
            --Dcm_Timer.P2;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_P2;
            Dcm_Timer.P2 = DCM_ZERO;
            Dcm_OnTimeout (DCM_TMR_ID_P2);
            /* Handle response pending */
        }
    }

    if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2STAR))
    {
        if(DCM_0x01U < Dcm_Timer.P2Star)
        {
            --Dcm_Timer.P2Star;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_P2STAR;
            Dcm_Timer.P2Star = DCM_ZERO;
            Dcm_OnTimeout (DCM_TMR_ID_P2STAR);
            /* Cancel the current request */
        }
    }

    if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_S3SERVER))
    {
        if(DCM_0x01U < Dcm_Timer.S3Server)
        {
            --Dcm_Timer.S3Server;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_S3SERVER;
            Dcm_Timer.S3Server = DCM_ZERO;
            Dcm_OnTimeout (DCM_TMR_ID_S3SERVER);
        }
    }

    if(DCM_ZERO == (Dcm_Timer.TimeOut & DCM_TMR_ID_3E))
    {
        if(DCM_0x01U < Dcm_Timer.TesterPresent)
        {
            --Dcm_Timer.TesterPresent;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_3E;
            Dcm_Timer.TesterPresent = DCM_ZERO;
            Dcm_OnTimeout (DCM_TMR_ID_3E);
        }
    }
}

/**************************************************************************
 Function name   : void Dcm_TimeTask
 Arguments       : void
 Return type     : void
 Description     : This function is used to handle the DiagMgr timeout's
 **************************************************************************/
static void Dcm_OnTimeout(uint8 TmrId)
{
    if(DCM_FALSE != (DCM_TMR_ID_P2 & TmrId))
    {
        if((Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State == DCM_SID_PROCESS) && (0x0u == Dcm_InternalStatus.RcrRp_Count))
        {
            ++Dcm_InternalStatus.RcrRp_Count;
            Dcm_StartTimer (DCM_TMR_ID_P2);
            /* Nrc */
            Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].AddBuf[DCM_0x02U] = DCM_NRC_0x78;
            Dcm_InternalStatus.OpStatus = DCM_PENDING;
            Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_ONTX;
        }
        else if(Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State == DCM_STATE_ONTX)
        {
            Dcm_StartTimer (DCM_TMR_ID_P2);
        }
        else
        {
            /*No action required - MISRA Fix snaray12*/
        }
    }
    if(DCM_FALSE != (DCM_TMR_ID_P2STAR & TmrId))
    {
        if(Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State == DCM_SID_PROCESS)
        {
            if(Dcm_InternalStatus.RcrRp_Count >= DcmDslDiagRespMaxNumRespPend)
            {
                Dcm_StopTimer (DCM_TMR_ID_P2);
                /* Nrc */
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].AddBuf[DCM_0x02U] = DCM_0x10U;
                Dcm_InternalStatus.OpStatus = DCM_E_CANCEL;
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_READY;
                ClearDcm_svc22Info();
                /* Transmit Negative resposne if ComM Tx Available */
                if(DCM_FALSE != (Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].ComMMode & DCM_COMM_STATE_TX_EN))
                {
                    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_ONTX;
                }
            }
            else
            {
                ++Dcm_InternalStatus.RcrRp_Count;
                Dcm_StartTimer (DCM_TMR_ID_P2STAR);
                /* Nrc */
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].AddBuf[DCM_0x02U] = DCM_NRC_0x78;
                Dcm_InternalStatus.OpStatus = DCM_PENDING;
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_ONTX;
            }
        }
        /*Added ComM state check to resolve the no response issue for the response sent during P2Star expiry*/
        else if((Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State == DCM_STATE_ONTX) &&
                        (Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].ComMMode == DCM_COMM_STATE_TX_DIS))
        {
            if((Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].State == DCM_STATE_ONTX) &&
                        (Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].ComMMode == DCM_COMM_STATE_TX_DIS))
            {
                Dcm_StopTimer (DCM_TMR_ID_P2);
                Dcm_InternalStatus.OpStatus = DCM_INITIAL;
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_READY;
                Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].State = DCM_STATE_READY;
                Dcm_ComMInactiveIndication();
            }
        }
        else
        {
            /*Do nothing*/
        }
    }

    if(DCM_FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
    {
        (void) Dcm_ResetToDefaultSession();
    }
}

/**************************************************************************
 Function name   : void Dcm_StartTimer
 Arguments       : uint8
 Return type     : void
 Description     : This function is used to Start the timer's
 **************************************************************************/

void Dcm_StartTimer(uint8 TmrId)
{
    uint8 SessionIter = DCM_ZERO;

    for (SessionIter = DCM_ZERO; SessionIter < NO_OF_SUPPORTTED_SESSIONS; SessionIter++)
    {
        if(Dcm_DsdSessionInfo[SessionIter].Session_Value == Dcm_InternalStatus.Session_Level)
        {
            if(DCM_FALSE != (DCM_TMR_ID_P2 & TmrId))
            {
                Dcm_Timer.P2 = (Dcm_DsdSessionInfo[SessionIter].P2 - DcmTimStrP2ServerAdjust) / DCM_TASK_PERIODICITY;
                Dcm_Timer.TimeOut &= ~DCM_TMR_ID_P2;
            }

            if(DCM_FALSE != (DCM_TMR_ID_P2STAR & TmrId))
            {
                Dcm_Timer.P2Star = (Dcm_DsdSessionInfo[SessionIter].P2Star - DcmTimStrP2StarServerAdjust) / DCM_TASK_PERIODICITY;
                Dcm_Timer.TimeOut &= ~DCM_TMR_ID_P2STAR;
            }

            if(DCM_FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
            {
                Dcm_Timer.S3Server = DCM_S3_SERVER_TIME / DCM_TASK_PERIODICITY;
                Dcm_Timer.TimeOut &= ~DCM_TMR_ID_S3SERVER;
            }
            break;
        }
    }
    if(DCM_FALSE != (DCM_TMR_ID_3E & TmrId))
    {
        Dcm_Timer.TesterPresent = DCM_S3_SERVER_TIME / DCM_TASK_PERIODICITY;
        Dcm_Timer.TimeOut &= ~DCM_TMR_ID_3E;
    }
}

/**************************************************************************
 Function name   : void Dcm_StopTimer
 Arguments       : uint8
 Return type     : void
 Description     : This function is used to Start the timer's
 **************************************************************************/

void Dcm_StopTimer(uint8 TmrId)
{
    if(DCM_FALSE != (DCM_TMR_ID_P2 & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_P2;
    }
    if(DCM_FALSE != (DCM_TMR_ID_P2STAR & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_P2STAR;
    }
    if(DCM_FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_S3SERVER;
    }
    if(DCM_FALSE != (DCM_TMR_ID_3E & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_3E;
    }
}

/**************************************************************************
 Function name   : DslInternal_SetSesCtrlType
 Arguments       : Dcm_SesCtrlType SesCtrlType
 Return type     : void
 Description     : This function sets a new session control type value in the DCM module.
 **************************************************************************/
void DslInternal_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType)
{
    Dcm_OpStatusType flOpStatus = DCM_INITIAL;
    if(SesCtrlType < NO_OF_SUPPORTTED_SESSIONS)
    {
        Dcm_InternalStatus.Session_Index = SesCtrlType;
        Dcm_InternalStatus.Session_Level = Dcm_DsdSubService10[SesCtrlType].SubServiceId;
        Dcm_SessionChangeAction(flOpStatus, Dcm_InternalStatus.Session_Level, DCM_DIAG_REQUEST);
    }
}

/**************************************************************************
 Function name   : DslInternal_SetSecurityLevel
 Arguments       : Dcm_SecLevelType SecurityLevel)
 Return type     : void
 Description     : This function sets a new security level value in the DCM module.
 **************************************************************************/
void DslInternal_SetSecurityLevel(Dcm_SecLevelType SecurityLevel)
{
    Dcm_InternalStatus.Security_Level = SecurityLevel;
    Dcm_SecurityChangeAction(Dcm_InternalStatus.Security_Level, DCM_DIAG_REQUEST);
}

/* Functions provided to BSW modules and to SW-Cs */

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSecurityLevel
 Arguments       : Dcm_SecLevelType *secLevel
 Return type     : Std_ReturnType
 Description     : This function provides the active security level value.
 **************************************************************************/

Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType *secLevel)
{
    Std_ReturnType fl_RetVal = DCM_E_NOT_OK;
    if(NULL != secLevel)
    {
        *secLevel = Dcm_InternalStatus.Security_Level;
        fl_RetVal = DCM_E_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSesCtrlTypeIndex
 Arguments       : Dcm_SesCtrlType *sesCtrlTypeIndex
 Return type     : Std_ReturnType
 Description     : This function provides the active session control type value.
 **************************************************************************/
Std_ReturnType Dcm_GetSesCtrlTypeIndex(Dcm_SesCtrlType *sesCtrlTypeIndex)
{
    Std_ReturnType fl_RetVal = DCM_E_NOT_OK;
    if(NULL != sesCtrlTypeIndex)
    {
        *sesCtrlTypeIndex = Dcm_InternalStatus.Session_Index;
        fl_RetVal = DCM_E_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSesCtrlType
 Arguments       : Dcm_SesCtrlType *sesCtrlType
 Return type     : Std_ReturnType
 Description     : This function provides the active session control type value.
 **************************************************************************/
Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *sesCtrlType)
{
    Std_ReturnType fl_RetVal = DCM_E_NOT_OK;
    if(NULL != sesCtrlType)
    {
        *sesCtrlType = Dcm_InternalStatus.Session_Level;
        fl_RetVal = DCM_E_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetActiveProtocol
 Arguments       : Dcm_ProtocolType *activeProtocol
 Return type     : Std_ReturnType
 Description     : This function returns the active protocol name
 **************************************************************************/
Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType *activeProtocol)
{
    Std_ReturnType fl_RetVal = DCM_E_NOT_OK;
    /*QAC fix*/
    if(NULL != activeProtocol)
    {
        *activeProtocol = DCM_ZERO;
        fl_RetVal = DCM_E_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Dcm_ResetToDefaultSession
 Arguments       : void
 Return type     : Std_ReturnType
 Description     : The call to this function allows the application to reset the current session to
 Default session.
 **************************************************************************/
Std_ReturnType Dcm_ResetToDefaultSession(void)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;
    Dcm_OpStatusType flOpStatus = DCM_INITIAL;

    /* Should it be RESET to default ? */
    Dcm_InternalStatus.OpStatus = DCM_INITIAL;
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_READY;
    Dcm_InternalStatus.ConcurrentTesterPresent = DCM_FALSE;
    Dcm_InternalStatus.BuffInUse = DCM_FALSE;
    Dcm_InternalStatus.Security_Level = DCM_SEC_LEV_LOCKED;
    Dcm_InternalStatus.Session_Level = DCM_DEFAULT_SESSION;
    Dcm_InternalStatus.Session_Index = DCM_ZERO;
    Dcm_SessionChangeAction(flOpStatus, DCM_DEFAULT_SESSION, DCM_DIAG_TIMEOUT);
    Dcm_SecurityChangeAction (DCM_SEC_LEV_LOCKED, DCM_DIAG_TIMEOUT);
    Dcm_ComMInactiveIndication();
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Dcm_ComMInactiveIndication
 Arguments       : void
 Return type     : Std_ReturnType
 Description     : The call to this function allows the application to reset the current session to
 Default session.
 **************************************************************************/
void Dcm_ComMInactiveIndication(void)
{
    uint8 Client = DCM_ZERO;

    for(Client = DCM_ZERO; Client < DcmNumofClientSupported ; Client++)
    {
       if((Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State == DCM_STATE_READY) &&
                     (Dcm_DslRequestResponse[Dcm_InternalStatus.SubConnRef].State == DCM_STATE_READY))
       {
           if((Dcm_InternalStatus.ComMState != Dcm_ComM_InActive) && (Dcm_InternalStatus.Session_Level == DCM_DEFAULT_SESSION))
           {
              ComM_DCM_InactiveDiagnostic(Dcm_ComMChannelId[Client].ComMChannelId);
           }
       }
    }
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_TriggerOnEvent
 Arguments       : uint8 RoeEventId
 Return type     : Std_ReturnType
 Description     : The call to this function allows to trigger an event linked to a ResponseOnEvent
 request.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(RoeEventId);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
Std_ReturnType Dcm_TriggerOnEvent(uint8 RoeEventId)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;
    /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(RoeEventId);
    return fl_RetVal;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_SetActiveDiagnostic
 Arguments       : boolean avtive
 Return type     : Std_ReturnType
 Description     : Allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic()
                   function. Critical section needed as this API is reentrant.
 **************************************************************************/
Std_ReturnType Dcm_SetActiveDiagnostic(Dcm_BooleanType active)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;
    Dcm_EnterCriticalSection();
    Dcm_InternalStatus.ComMState = active;
    Dcm_ExitCriticalSection();
    return fl_RetVal;
}

/**************************************************************************
 Function name   : void Dcm_ResetP2StartServer
 Arguments       : void
 Return type     : void
 Description     :
 **************************************************************************/
void Dcm_ResetP2StartServer(void)
{
    Dcm_StartTimer (DCM_TMR_ID_P2STAR);
}

#if(Dcm_KeepNonDefaultSessionActive == STD_ON)
/**************************************************************************
 Function name   : void KeepSessionActive
 Arguments       : Dcm_SesCtrlType SessionId_Index,Dcm_SecLevelType SecurityLevel_Index
 Return type     : Std_ReturnType
 Description     : To keep non default session active and unlock the supported security.
                   If SecurityLevel = 0, it will not go for unlocking the security.
 **************************************************************************/
void KeepNonDefaultSessionActive(Dcm_SesCtrlType SessionId,Dcm_SecLevelType SecurityLevel)
{
    uint8 CurrentSession = DCM_ZERO;
    uint8 SessionId_Index, SecurityLevel_Index;
    uint8 index1,index2;
    Dcm_BooleanType flag= DCM_FALSE;

    for(index1=DCM_ZERO; index1< (NO_OF_SUPPORTTED_SESSIONS); index1++)
    {
        if(SessionId == Dcm_DsdSubService10[index1].SubServiceId)
        {
            SessionId_Index = index1;
            flag = DCM_TRUE;
            if(SecurityLevel != DCM_ZERO)
            {   
                flag= DCM_FALSE;
                for(index2=DCM_ZERO; index2<(uint8)(No_of_security_level*2); index2++)
                {
                    if(SecurityLevel == Dcm_DsdSubService27[index2].SubServiceId)
                    {
                        SecurityLevel_Index = index2;
                        flag = DCM_TRUE;
                        break;
                    }
                    else
                    {
                        /*do nothing*/
                    }
                }
            }
            break;
        }
        else
        {
            /*do nothing*/
        }
    }


    if((DCM_E_OK == Dcm_GetSesCtrlType(&CurrentSession)) && (flag == DCM_TRUE))
    {
        if(CurrentSession != SessionId)
        {
            DslInternal_SetSesCtrlType(SessionId_Index);
            if(SecurityLevel != DCM_ZERO)
            {
                DslInternal_SetSecurityLevel(SecurityLevel_Index);
            }
        }
        else
        {
            if(KeepS3Timer == DCM_ZERO)
            {
                /* Restart s3timer after 3seconds to keep session alive*/
                Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
                KeepS3Timer = TIMER_KeepNonDefaultSession;
            }
            else
            {
                KeepS3Timer--;
            }
        }
    }
}

#endif
/**************************************************************************
 Function name   : void Dcm_ResetS3Server
 Arguments       : void
 Return type     : void
 Description     :
 **************************************************************************/
void Dcm_ResetS3Server(void)
{
    Dcm_StartTimer (DCM_TMR_ID_S3SERVER);
}
#if 0

/* Callout Definitions */

/*!!!!!!!!!!!!!!!!!!!!!*/
/*  The content of most callouts is hand-written code, for some callouts the
 DCM configuration tool shall generate a default implementation that is manually
 edited by the integrator.

 These fucntions will be kept in Dcm_Callout.c file in future
 When real implementation begins*/

/**************************************************************************
 Function name   : Dcm_ReturnReadMemoryType Dcm_ReadMemory
 Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress,
                   uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Dcm_ReturnReadMemoryType
 Description     : The Dcm_ReadMemory callout is used to request memory data identified by the
 parameter memoryAddress and memorySize from the UDS request message.
 **************************************************************************/

Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,
                                        uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData,
                                        Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_READ_OK;
}

/**************************************************************************
 Function name   : Dcm_ReturnWriteMemoryType Dcm_WriteMemory
 Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress,
                   uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Dcm_ReturnWriteMemoryType
 Description     : The Dcm_WriteMemory callout is used to write memory data identified by the
 parameter memoryAddress and memorySize.
 **************************************************************************/

Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,
        uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_WRITE_OK;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_SetProgConditions
 Arguments       : Dcm_OpStatusType OpStatus, Dcm_ProgConditionsType * ProgConditions
 Return type     : Std_ReturnType
 Description     : The Dcm_SetProgConditions callout allows the integrator to store relevant
 information prior to jumping to bootloader.
 **************************************************************************/

Std_ReturnType Dcm_SetProgConditions(Dcm_OpStatusType OpStatus, Dcm_ProgConditionsType * ProgConditions)
{
    return DCM_E_OK;
}

/**************************************************************************
 Function name   : Dcm_EcuStartModeType Dcm_GetProgConditions
 Arguments       : Dcm_ProgConditionsType * ProgConditions
 Return type     : Dcm_EcuStartModeType
 Description     : The Dcm_GetProgConditions callout is called upon DCM initialization and allows to
 determine if a response ($50 or $51) has to be sent depending on request within
 the bootloader.
 **************************************************************************/
Dcm_EcuStartModeType Dcm_GetProgConditions(Dcm_ProgConditionsType * ProgConditions)
{
    return DCM_COLD_START;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_ProcessRequestTransferExit
 Arguments       : Dcm_OpStatusType OpStatus, uint8* RequestParameterRecord, uint32 RequestParameterRecordSize,
                   uint8* ResponseParameterRecord, uint32* ResponseParameterRecordSize, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Std_ReturnType
 Description     : DCM shall call this callout function to terminate a download or upload process.
 **************************************************************************/
Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus,
        uint8* RequestParameterRecord,  uint32  RequestParameterRecordSize,
        uint8* ResponseParameterRecord, uint32* ResponseParameterRecordSize,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_E_OK;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_ProcessRequestUpload
 Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
 uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Std_ReturnType
 Description     : DCM shall call this callout function to start an upload process. This service
 is needed for the implementation of UDS service RequestUpload.
 **************************************************************************/

Std_ReturnType Dcm_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
                                        uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_E_OK;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_ProcessRequestDownload
 Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength,
 Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Std_ReturnType
 Description     : DCM shall call this callout function to start an upload process. This service
 is needed for the implementation of UDS service RequestUpload.
 **************************************************************************/

Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
        uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_E_OK;
}

/**************************************************************************
 Function name   : Std_ReturnType Dcm_ProcessRequestFileTransfer
 Arguments       : Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength,
 uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength,
 uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Std_ReturnType
 Description     : DCM shall call this callout function to start a RequestFileTransferprocess. This
 service is needed for the implementation of UDS service RequestFileTransfer.
 **************************************************************************/

Std_ReturnType Dcm_ProcessRequestFileTransfer(Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength,
        uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength,
        uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_E_OK;
}

#endif

#define DIAGMGR_CODE_SEC_END
#include "MemMap.h"

#endif

/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : RTC# 567968                                           */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Dec-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc# 731986                                           */
/*Change Description: Concurrent tester present, functional request,        */
/*         Response pending transmission related issue's fix.               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 822374                                           */
/*Change Description: Coverity issue fixes                                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 05-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: MISRA warning fixes                                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: MISRA warning fixes                                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 27-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: PR defects fixed for MISRA                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 14-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 794563: Multi DID support for 0x22 service Multi      */
/*                    channel support                                       */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 31-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Dcm migration to Bookshelf - support (830050)         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Nov-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 1126336: [vAutosar] Dcm - Quality                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Jun-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1376136                                           */
/*Change Description: Implement RequestIndication()                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jul-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1408913                                           */
/*Change Description: Wrong NAK In case of Diagnostic Buffer overflow       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 06-Jul-2022                                           */
/*Version           :                                                       */
/*By                : dbalasub                                              */
/*Traceability      : Rtc#1706585                                           */
/*Change Description: Audit fix                                             */
/*--------------------------------------------------------------------------*/
