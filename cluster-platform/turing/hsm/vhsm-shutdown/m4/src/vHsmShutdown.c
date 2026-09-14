/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmDmnMgr.c
 *
 * \brief
 * Domain Manager Grace shutdown of HSM core Source file 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
#include "vHsmCryptoManager.h"
#include "string.h"
#include "trace.h"
#include "hwip.h"
#include "hosts.h"
#include "sec_proxy.h"
#include "dmsc_irq_map.h"
#include "vHsmIpc.h"

/**
 *********************************************************************************************
 ** \enum      DmnMgrState_ts
 **
 ** \brief     Internal state of the DmnMgr Writer.
 **
 *********************************************************************************************
 */
typedef enum
{
    e_DmnMgr_Uninit = 0,     /**< DmnMgr Uninit */
    e_DmnMgr_Idle = 1,       /**< DmnMgr Idle */
    e_DmnMgr_Req = 2,      /**< DmnMgr Req */
    e_DmnMgr_ReqPending = 3, /**< DmnMgr Req Pending */
    e_DmnMgr_Response = 4,  /**< DmnMgr Response */
}DmnMgrState_ts;


/*********************************************************************************************
 ** Static Varibles
 *********************************************************************************************/
static DmnMgrState_ts l_DmnMgr_Status = e_DmnMgr_Uninit;
static te_cryptojobresult vHsmDmnMgr_JobResult = CRYPTO_JOB_NOT_DONE;
static uint32 PendingFlag = 2u;
/*********************************************************************************************
 ** Public Functions
 *********************************************************************************************/


/**
 *********************************************************************************************
 ** \copydoc vHsmDmnMgr_Init
 *********************************************************************************************
 */
FUNC(void,DMN_CODE) vHsmDmnMgr_Init(void)
{
    if(l_DmnMgr_Status == e_DmnMgr_Uninit)
    {
        l_DmnMgr_Status = e_DmnMgr_Idle;
    }
}


/**
 *********************************************************************************************
 ** \copydoc vHsmDmnMgr_Shutdown
 *********************************************************************************************
 */
FUNC(Std_ReturnType,DMN_CODE) vHsmDmnMgr_Shutdown(void)
{
    Std_ReturnType l_RetVal_E = E_OK;
    if((l_DmnMgr_Status != e_DmnMgr_Idle))
    {
        l_RetVal_E = E_NOT_OK;
    }
    else
    {
        l_DmnMgr_Status = e_DmnMgr_Req;
        l_RetVal_E = E_OK;
        TRACE_info("\r\n HSM Shutdown");
    } 
    return l_RetVal_E;
}


/**
 *********************************************************************************************
 ** \copydoc vHsmDmnMgr_MainFunction
 *********************************************************************************************
 */
FUNC(void,DMN_CODE) vHsmDmnMgr_MainFunction(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    s32 interuptstate = 0;
    ts_vHsm_Commanddata l_commanddatasend = {0};
    switch (l_DmnMgr_Status)
    {
    case e_DmnMgr_Req:
        mask_interrupts();
        interuptstate = hwip_disable_interrupt(NVIC_IRQ(HSM_SEC_PROXY_RX_IRQ),NULL); //Disable the IPC interrupt to reject all incoming request
        unmask_interrupts();
        if(0u == interuptstate) 
        {
            vHsmDmnMgr_JobResult = CRYPTO_JOB_DONE;
        } 
        l_DmnMgr_Status = e_DmnMgr_Response;
        break;
    case e_DmnMgr_Response:
        l_commanddatasend.jobId_E = SID_3_DMNMGR_REQ_CB;
        l_commanddatasend.payLoadPtr_U8P = &vHsmDmnMgr_JobResult;
        l_commanddatasend.payLoadSize = (uint16)1;
        l_commanddatasend.priority_U8 = e_priorityunused;
        l_RetVal_E = vHsmCrypto_Command_SendData(l_commanddatasend);
        if(E_OK == l_RetVal_E)
        {
            /*IPC sent*/
        }
        else
        {
            /*IPC not sent*/
        }
        l_DmnMgr_Status = e_DmnMgr_ReqPending;
        break;
    case e_DmnMgr_ReqPending:
        if(PendingFlag == 0)
        {
            l_DmnMgr_Status = e_DmnMgr_Idle;
            vHsmIpc_DeInit(); /*deinit IPC*/
        }
        else
        {
            PendingFlag = PendingFlag-1;
        }
        break;
    default:
        break;
    }
}

/*EOF*/
