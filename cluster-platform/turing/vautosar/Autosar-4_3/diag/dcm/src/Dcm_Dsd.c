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
#ifndef DCM_DSD_C_
#define DCM_DSD_C_
/*****************************************************************************
 *  File Name         :  Dcm_Dsd.c                                            *
 *  Module Short Name :  DiagMgr                                              *
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

#include "Dcm_Dsd.h"
#include "Dcm.h"
#include "Dcm_Internal.h"
#include "ComM_Dcm.h"
#include "Dcm_Dsp.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

#define DCM_DSD_SID_HAS_SUBFN                0x01u
#define DCM_DSD_SID_FUNCTIONAL_ADDR_SUPPORT  0x02u
#define DSP_DIAG_CHK_LVL_SID                 0u

#define DCM_DSD_0x01U                        0x01u
#define DCM_DSD_0x02U                        0x02u
#define DCM_DSD_0x03U                        0x03u
#define DCM_DSD_SUPPRESS_RESP_MASK           0x80u
#define DCM_DSD_NEGATIVE_RESP_SID            0x7Fu
#define DCM_DSD_0x40U                        0x40u
/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                     *
 *****************************************************************************/
#define DIAGMGR_CODE_SEC_START
#include "MemMap.h"


/*****************************************************************************
 *                   Static Functions                                        *
 *****************************************************************************/
static void Dcm_ExternalSetNegResponse(Dcm_NegativeResponseCodeType ErrorCode);
static void Dcm_ExternalProcessingDone(void);

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
static Std_ReturnType Dsd_RequestIndication(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *nrc);
#endif

/**************************************************************************
 Function name   : void Dsd_Init
 Arguments       : void
 Return type     : void
 Description     : This function is called to provide the received data of an I-PDU segment (N-PDU)
 to the upper layer.
 **************************************************************************/

void Dsd_Init(void)
{

}

/**************************************************************************
 Function name   : void Dsd_Main
 Arguments       : void
 Return type     : void
 Description     : DSD Main Function.
 **************************************************************************/
void Dsd_Main(void)
{
}

/**************************************************************************
 Function name   : Dsd_DslDataIndication
 Arguments       : Dcm_MsgContextType *pMsgContext
 Return type     : Std_ReturnType
 Description     : DSD DataIndication Function.
 **************************************************************************/
Std_ReturnType Dsd_DslDataIndication(Dcm_MsgContextType *pMsgContext, uint8 Opstatus)
{
    uint8 flIter = 0u;
    uint8 flLength = 0u;
    uint8 flStateRef = 0u;
    Std_ReturnType retVal = DCM_E_NOT_OK;
#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
    Std_ReturnType retVal2 = DCM_E_OK;
    Dcm_NegativeResponseCodeType Nrc2 = DCM_E_POSITIVERESPONSE;
#endif
    Dcm_NegativeResponseCodeType Nrc = DCM_E_SERVICENOTSUPPORTED;

    if((NULL != pMsgContext) && (NULL != pMsgContext->reqData))
    {
        flLength = Dcm_DsdSidTabServiceId[0];
        if(flLength == DcmNumOfSIDSupported)
        {
            for(flIter = 0; flIter < flLength; flIter++)
            {
                if(pMsgContext->reqData[0] == Dcm_DsdSidTabServiceId[flIter + DCM_DSD_0x01U])
                {
                    if(   (0u != (Dcm_DsdSidTabServiceInfo[flIter].Props & DCM_DSD_SID_FUNCTIONAL_ADDR_SUPPORT))
                            || (0u == pMsgContext->msgAddInfo.reqType))
                    {
                        flStateRef = Dcm_DsdSidTabServiceInfo[flIter].State_Ref;
                        Nrc = Dcm_DspCheckSessionSecurity (flStateRef, DSP_DIAG_CHK_LVL_SID);
                        if(DCM_E_POSITIVERESPONSE == Nrc)
                        {
#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
                            Nrc2 = DCM_E_CONDITIONSNOTCORRECT;
							if(Opstatus == DCM_INITIAL)
                            {
                               retVal2 = Dsd_RequestIndication(pMsgContext, &Nrc2);
							}
                            if(retVal2 == DCM_E_OK)
    #endif
                            {
                            Nrc = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                                if(pMsgContext->reqDataLen >= Dcm_DsdSidTabServiceInfo[flIter].Length)
                                {
                                    if(DCM_FALSE != (Dcm_DsdSidTabServiceInfo[flIter].Props & DCM_DSD_SID_HAS_SUBFN))
                                    {
                                        if(DCM_FALSE != (pMsgContext->reqData[DCM_DSD_0x01U] & DCM_DSD_SUPPRESS_RESP_MASK))
                                        {
                                            pMsgContext->reqData[DCM_DSD_0x01U] &= DCM_DSD_NEGATIVE_RESP_SID;
                                            pMsgContext->msgAddInfo.suppressPosResponse = DCM_DSD_0x01U;
                                        }
                                    }
                                    Nrc = DCM_E_POSITIVERESPONSE;
                                    pMsgContext->reqData = (Dcm_MsgType) &pMsgContext->reqData[DCM_DSD_0x01U];
                                    if(0u != pMsgContext->reqDataLen)
                                    {
                                        pMsgContext->reqDataLen = pMsgContext->reqDataLen - DCM_DSD_0x01U;
                                    }
                                    pMsgContext->resDataLen = 0uL;
                                    retVal = Dcm_DsdSidTabServiceInfo[flIter].DcmDsdSidTabFnc(Dcm_InternalStatus.OpStatus, pMsgContext, &Nrc);
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
    if(retVal2 != DCM_E_OK)
    {
        retVal = retVal2;
        if(retVal2 == DCM_E_NOT_OK)
        {
            Dcm_ExternalSetNegResponse (Nrc2);
            Dcm_ExternalProcessingDone();
        }
        else if(retVal2 == DCM_E_PROCESSING_DONE)
        {
            Dcm_ExternalProcessingDone();
        }
        else
        {
            /*empty else to resolve 15.7 misra rule */
        }
    }
    else
#endif
    {
        if(retVal == DCM_E_NOT_OK)
        {
            Dcm_ExternalSetNegResponse (Nrc);
            Dcm_ExternalProcessingDone();
        }
        else if(retVal == DCM_E_OK)
        {
            Dcm_ExternalProcessingDone();
        }
        else
        {
            /*DO NOTHING - MISRA FIX*/
        }
    }
    return retVal;
}

/**************************************************************************
 Function name   : void Dsd_DspProcessingDone
 Arguments       : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType responseCode
 Return type     : void
 Description     : DSD - DSP processing is done.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(pMsgContext);
 ** DCM_IGNORE_UNREF_PARAM(responseCode);
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
 ** The object addressed by the pointer parameter 'pMsgContext' is not modified and so the
 ** pointer could be of type 'pointer to const'..
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dsd_DspProcessingDone(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType responseCode)
{
    /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(pMsgContext);
    DCM_IGNORE_UNREF_PARAM(responseCode);
    /*QAC fix*/
}

/**************************************************************************
 Function name   : void Dsd_DslConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : DCM Confirmation.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
 ** DCM_IGNORE_UNREF_PARAM(result);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
void Dsd_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result)
{
    /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
    DCM_IGNORE_UNREF_PARAM(result);
    /*QAC fix*/
}

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
/**************************************************************************
 Function name   : Dsd_RequestIndication
 Arguments       : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *nrc
 Return type     : Std_ReturnType
 Description     : DSD RequestIndication Function.
                   Function shall return only
                   DCM_E_OK, DCM_E_NOT_OK(with corresponded ErrorCode), DCM_E_REQUEST_NOT_ACCEPTED
 **************************************************************************/
static Std_ReturnType Dsd_RequestIndication(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *nrc)
{
    uint8 i = 0u;
    uint32 len = 0u;
    Std_ReturnType ret = DCM_E_NOT_OK;

    for(i = 0u; i < NO_OF_REQUEST_NOTIFICATION; i++)
    {
        len = pMsgContext->resMaxDataLen;
        ret = ServiceRequestIndicationTable[i].XXX_IndicationFunc(pMsgContext->reqData[0], &(pMsgContext->reqData[DCM_DSD_0x01U]), pMsgContext->reqDataLen,
                pMsgContext->msgAddInfo.reqType, pMsgContext->rxPduId, pMsgContext->resData, &len, nrc);
        pMsgContext->resDataLen = len;
        if((ret != DCM_E_OK) && (ret != DCM_E_PROCESSING_DONE))
        {
            break;
        }
    }
    return ret;
}

/**************************************************************************
 Function name   : void Dsd_DslManufConfirmation
 Arguments       : Dcm_MsgContextType* pMsgContext, Std_ReturnType result
 Return type     : void
 Description     : DCM Confirmation.
 **************************************************************************/
void Dsd_DslManufConfirmation(Dcm_MsgContextType *pMsgContext, Std_ReturnType result)
{
    uint8 flindex = 0u;
    for(flindex = 0u; flindex < NO_OF_CONFIRMATION_NOTIFICATION; flindex++)
    {
        (void)ServiceRequestConfirmationTable[flindex].XXX_ConfirmationFunc(pMsgContext->reqData[0], pMsgContext->msgAddInfo.reqType, pMsgContext->rxPduId, (Dcm_ConfirmationStatusType)result);
    }
}
#endif
/**************************************************************************
 Function name   : void Dcm_ExternalSetNegResponse
 Arguments       : Dcm_NegativeResponseCodeType ErrorCode
 Return type     : void
 Description     : Used by service interpreter outside of DCM to indicate that a the final response
 shall be a negative one.
 **************************************************************************/
static void Dcm_ExternalSetNegResponse(Dcm_NegativeResponseCodeType ErrorCode)
{
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData = (Dcm_MsgType) &DcmDsl_Buffer[0];
    /* Anyway response is pointing to same as request address */
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData = Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData;
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData[DCM_DSD_0x01U] = Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData[0];
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData[0] = DCM_DSD_NEGATIVE_RESP_SID;
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData[DCM_DSD_0x02U] = ErrorCode;
    /* The below assignment for getting length information in transmit function */
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData = &Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resData[DCM_DSD_0x03U];
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.resDataLen = 0x00u;
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_PREPTX_NRC;

    /* Suppression of Response should not proceed for Physical Address */
    Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.suppressPosResponse = 0u;

#if(DCM_FUNC_ADDR_SUPPRESS_NRC != FALSE)
    if(0u != Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.reqType)
    {
        switch(ErrorCode)
        {
            /* Suppress the below NRC's only for active Functional Addressing */
            case DCM_E_SERVICENOTSUPPORTED:
            case DCM_E_SUBFUNCTIONNOTSUPPORTED:
            case DCM_E_REQUESTOUTOFRANGE:
            case DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION:
            case DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION:
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.suppressPosResponse = DCM_DSD_0x01U;
                break;
    
            default:
                Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.suppressPosResponse = 0u;
                break;
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif
}

/**************************************************************************
 Function name   : void Dcm_ExternalProcessingDone
 Arguments       : void
 Return type     : void
 Description     : Used by service interpreter outside of DCM to indicate that a final response can be
 sent.
 **************************************************************************/
static void Dcm_ExternalProcessingDone(void)
{

    if(0u != Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.suppressPosResponse)
    {
        Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.msgAddInfo.suppressPosResponse = 0u;
        Dsp_DslConfirmation (Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.rxPduId, DCM_E_OK);
        Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_READY;
        Dcm_InternalStatus.BuffInUse = DCM_FALSE;
        if(Dcm_InternalStatus.Session_Level != DCM_DEFAULT_SESSION)
        {
            Dcm_StartTimer(DCM_TMR_ID_S3SERVER);
        }
        /* if response is suppressed in Default session, Dcm will call
         * ComM Dcm inactive diagnostics */
        else if(Dcm_InternalStatus.ComMState != Dcm_ComM_InActive)
        {
            Dcm_ComMInactiveIndication();
        }
        else
        {
            /*No action required - MISRA FIX snaray12*/
        }

    }
    else
    {
        if(Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State != DCM_STATE_PREPTX_NRC)
        {
            Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData = (Dcm_MsgType) &DcmDsl_Buffer[0];
            /* Add 0x40 with SID for positive response */
            Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].pMsgContext.reqData[0] += DCM_DSD_0x40U;
        }
        Dcm_InternalStatus.OpStatus = DCM_E_PROCESSING_DONE;
        Dcm_DslRequestResponse[Dcm_InternalStatus.MainConnRef].State = DCM_STATE_ONTX;
    }
}



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
/*Date              : 17-Jun-2016                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 859867                                           */
/*Change Description: Issue fix for service ID not supportted in Functional */
/*						Addressing                                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#  866349                                          */
/*Change Description: PR defect fixes for 866349							*/
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
/*Date              : 17-Jun-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1376136                                           */
/*Change Description: Implement RequestIndication()                         */
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

